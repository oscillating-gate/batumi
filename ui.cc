// Copyright 2015 Matthias Puech.
// Copyright 2013 Olivier Gillet.
//
// Original author: Olivier Gillet (ol.gillet@gmail.com)
// Modified by: Matthias Puech (matthias.puech@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 
// See http://creativecommons.org/licenses/MIT/ for more information.
//
// -----------------------------------------------------------------------------
//
// User interface.

#include "ui.h"
#include "stmlib/system/storage.h"

#include <algorithm>

namespace batumi {

using namespace std;
using namespace stmlib;

const int32_t kLongPressDuration = 500;
const int32_t kVeryLongPressDuration = 2000;
const int32_t kPotMoveThreshold = 1 << (16 - 10);  // 10 bits
const uint16_t kCatchupThreshold = 1 << 10;

stmlib::Storage<0x8020000, 4> storage;

void Ui::Init(Adc *adc) {
  mode_ = UI_MODE_SPLASH;
  adc_ = adc;
  leds_.Init();
  switches_.Init(adc_);
  animation_counter_ = 0;

  if (!storage.ParsimoniousLoad(&feat_mode_, SETTINGS_SIZE, &version_token_)) {
    feat_mode_ = FEAT_MODE_FREE;
#ifdef ZOOM_IS_ATTEN
    for (int i=0; i<4; i++)
      pot_atten_value_[i] = UINT16_MAX;
#else
    for (int i=0; i<4; i++)
      pot_fine_value_[i] = 1 << 15;
#endif
  }

  // synchronize pots at startup
  for (uint8_t i=0; i<4; i++) {
#ifdef POT_REVERSED
    uint16_t adc_value = 0xffff - adc_->pot(i);
#else
    uint16_t adc_value = adc_->pot(i);
#endif
    pot_value_[i] = pot_filtered_value_[i] = pot_coarse_value_[i] = adc_value;
    catchup_state_[i] = false;
  }
}

void Ui::Poll() {
  switches_.Debounce();

  // we begin the iteration after the internal switches (or jumpers),
  // which are polled manually
  for (uint8_t i = SWITCH_SELECT; i < kNumSwitches; ++i) {
    if (switches_.just_pressed(i)) {
      queue_.AddEvent(CONTROL_SWITCH, i, 0);
      press_time_[i] = system_clock.milliseconds();
      detect_very_long_press_[i] = false;
    }
    if (switches_.pressed(i) && press_time_[i]) {
      int32_t pressed_time = system_clock.milliseconds() - press_time_[i];

      if (!detect_very_long_press_[i]) {
        if (pressed_time > kLongPressDuration) {
          queue_.AddEvent(CONTROL_SWITCH, i, pressed_time);
          detect_very_long_press_[i] = true;
        }
      } else {
        if (pressed_time > kVeryLongPressDuration) {
          queue_.AddEvent(CONTROL_SWITCH, i, pressed_time);
          detect_very_long_press_[i] = false;
          press_time_[i] = 0;
        }
      }
    }
    
    if (switches_.released(i) &&
        press_time_[i] != 0 &&
        !detect_very_long_press_[i]) {
      queue_.AddEvent(
          CONTROL_SWITCH,
          i,
          system_clock.milliseconds() - press_time_[i] + 1);
      press_time_[i] = 0;
      detect_very_long_press_[i] = false;
    }
  }

  // filter the pot values and emit events when changed
  for (uint8_t i = 0; i < 4; ++i) {
#ifdef POT_REVERSED
    uint16_t adc_value = 0xffff - adc_->pot(i);
#else
    uint16_t adc_value = adc_->pot(i);
#endif
    int32_t value = (31 * pot_filtered_value_[i] + adc_value) >> 5;
    pot_filtered_value_[i] = value;
    int32_t current_value = static_cast<int32_t>(pot_value_[i]);
    if (value >= current_value + kPotMoveThreshold || value <= current_value - kPotMoveThreshold) {
      queue_.AddEvent(CONTROL_POT, i, value);
      pot_value_[i] = value;
    }
  }

  // paint the interface
  switch (mode_) {
  case UI_MODE_SPLASH:
    if (animation_counter_ % 64 == 0) {
      for (int i=0; i<kNumLeds; i++)
	leds_.set(i, ((animation_counter_ / 64) % 4) == i);
      if (animation_counter_ / 64 > 3)
	mode_ = UI_MODE_NORMAL;
    }
    animation_counter_++;
    break;

  case UI_MODE_ZOOM:
    animation_counter_++;
    for (uint8_t i=0; i<kNumLeds; i++)
      leds_.set(i, false);
    leds_.set(feat_mode_, animation_counter_ & 128);
    break;

  case UI_MODE_NORMAL:
    animation_counter_++;
    bool flash = (animation_counter_ & 64) &&
      (animation_counter_ & 32) &&
      (animation_counter_ & 16);
    for (uint8_t i=0; i<kNumLeds; i++) {
      if (catchup_state_[i])
	leds_.set(i, i==feat_mode_ ? !flash : flash);
      else
	leds_.set(i, i == feat_mode_);
    }
    break;
  }

  leds_.Write();
}

void Ui::FlushEvents() {
  queue_.Flush();
}

void Ui::OnSwitchPressed(const Event& e) {
}

void Ui::OnSwitchReleased(const Event& e) {
  switch (e.control_id) {
  case SWITCH_SYNC:
  case SWITCH_WAV1:
  case SWITCH_WAV2:
    break;
  case SWITCH_SELECT:
    if (e.data > kVeryLongPressDuration) {
    } else if (e.data > kLongPressDuration) {
#ifdef LONG_PRESS_TO_CHANGE_MODE
      ChangeFeatureMode();
#else
      ToggleZoomMode();
#endif
    } else {
      switch (mode_) {
      case UI_MODE_SPLASH:
        break;
      case UI_MODE_ZOOM:
        // detect if pots have moved during zoom
        for (int i = 0; i < 4; i++)
          if (abs(pot_value_[i] - pot_coarse_value_[i]) > kCatchupThreshold) {
            catchup_state_[i] = true;
          }
        mode_ = UI_MODE_NORMAL;
        storage.ParsimoniousSave(&feat_mode_, SETTINGS_SIZE, &version_token_);
        break;

      case UI_MODE_NORMAL:
#ifdef LONG_PRESS_TO_CHANGE_MODE
        ToggleZoomMode();
#else
        ChangeFeatureMode();
#endif
        break;
      }
    }
    break;
  }
}

void Ui::OnPotChanged(const Event& e) {
  switch (mode_) {
  case UI_MODE_SPLASH:
    break;
  case UI_MODE_ZOOM:
#ifdef ZOOM_IS_ATTEN
    pot_atten_value_[e.control_id] = e.data;
#else
    pot_fine_value_[e.control_id] = e.data;
#endif
    break;
  case UI_MODE_NORMAL:
    if (!catchup_state_[e.control_id]) {
      pot_coarse_value_[e.control_id] = e.data;
    } else if (abs(e.data - pot_coarse_value_[e.control_id]) < kCatchupThreshold) {
      pot_coarse_value_[e.control_id] = e.data;
      catchup_state_[e.control_id] = false;
    }
    break;
  }
}

void Ui::ToggleZoomMode()
{
  if (mode_ == UI_MODE_NORMAL)
    mode_ = UI_MODE_ZOOM;
  else if (mode_ == UI_MODE_ZOOM)
    mode_ = UI_MODE_NORMAL;
}

void Ui::ChangeFeatureMode()
{
  feat_mode_ = static_cast<FeatureMode>((feat_mode_ + 1) % FEAT_MODE_LAST);
  // reset pots fine value
#ifdef ZOOM_IS_ATTEN
  for (int i = 0; i < 4; i++)
    pot_atten_value_[i] = UINT16_MAX;
#else
  for (int i = 0; i < 4; i++)
    pot_fine_value_[i] = 1 << 15;
#endif
  storage.ParsimoniousSave(&feat_mode_, SETTINGS_SIZE, &version_token_);
}

void Ui::DoEvents() {
  while (queue_.available()) {
    Event e = queue_.PullEvent();
    if (e.control_type == CONTROL_SWITCH) {
      if (e.data == 0) {
        OnSwitchPressed(e);
      } else {
        OnSwitchReleased(e);
      }
    } else if (e.control_type == CONTROL_POT) {
      OnPotChanged(e);
    }
  }
  if (queue_.idle_time() > 500) {
    queue_.Touch();
  }
}

}  // namespace batumi
