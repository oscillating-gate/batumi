// Copyright 2015 Matthias Puech
//
// Author: Matthias Puech (matthias.puech@gmail.com)
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
// Processor. Orchestrates the four LFOs.

#include "drivers/adc.h"
#include "drivers/dac.h"

#include "processor.h"
#include "ui.h"
#include "resources.h"
#include "stmlib/utils/dsp.h"

namespace batumi {

using namespace stmlib;

const int16_t kUnsyncPotThreshold = INT16_MAX / 20;
const int16_t kResetThresholdLow = 10000;
const int16_t kResetThresholdHigh = 20000;

void Processor::Init(Ui *ui, Adc *adc, Dac *dac) {
  ui_ = ui;
  adc_ = adc;
  dac_ = dac;
  previous_feat_mode_ = FEAT_MODE_LAST;
  // no need to Init the LFOs, it'll be done in Process on first run
  for (uint8_t i=0; i<kNumChannels; i++) {
    reset_trigger_armed_[i]= false;
    last_reset_[i] = 0;
  }
  waveform_offset_ = 0;
}

inline int16_t AdcValuesToPitch(uint16_t coarse, int16_t fine, int16_t cv) {
  coarse = Interpolate88(lut_scale_freq, coarse) - 32768;
  fine = (1 * kOctave * static_cast<int32_t>(fine)) >> 16;
  cv = cv * 5 * kOctave >> 15;
  return coarse + fine + cv;
}

inline uint8_t AdcValuesToDivider(uint16_t pot, int16_t fine, int16_t cv) {
  int32_t ctrl = pot + cv;
  CONSTRAIN(ctrl, 0, UINT16_MAX);
  fine = (5 * static_cast<int32_t>(fine + INT16_MAX / 5)) >> 16;
  int8_t div = lut_scale_divide[ctrl >> 8];
  div -= fine;
  CONSTRAIN(div, 1, 64);
  return div;
}

inline uint16_t AdcValuesToPhase(uint16_t pot, int16_t fine, int16_t cv) {
  int32_t ctrl = pot + cv + fine / 8;
  // no need to clip the result, wrapping around is ok
  return Interpolate88(lut_scale_phase, ctrl);
}

inline uint16_t AdcValuesToLevel(uint16_t pot, int16_t fine, int16_t cv) {
  int32_t ctrl = pot + cv + fine / 8 - UINT16_MAX/16;
  CONSTRAIN(ctrl, 0, UINT16_MAX);
  return Interpolate88(lut_scale_phase, ctrl);
}

void Processor::SetFrequency(int8_t lfo_no) {
  // sync or reset
  if (reset_triggered_[lfo_no]) {
    if (ui_->sync_mode()) {
      lfo_[lfo_no].set_period(last_reset_[lfo_no]);
      lfo_[lfo_no].align();
      synced_[lfo_no] = true;
    } else {
      lfo_[lfo_no].Reset(reset_subsample_[lfo_no]);
    }
    reset_trigger_armed_[lfo_no] = false;
    last_reset_[lfo_no] = 0;
  } else {
    last_reset_[lfo_no]++;
  }

#ifdef ZOOM_IS_ATTEN
  int16_t cv = (filtered_cv_[lfo_no] * ui_->atten(lfo_no)) >> 16;
  int16_t pitch = AdcValuesToPitch(ui_->coarse(lfo_no), 0, cv);
#else
  int16_t pitch = AdcValuesToPitch(ui_->coarse(lfo_no),
				   ui_->fine(lfo_no),
				   filtered_cv_[lfo_no]);
#endif

  // set pitch
  if (!synced_[lfo_no] ||
      (abs(pitch - last_pitch_[lfo_no]) > kUnsyncPotThreshold)) {
    lfo_[lfo_no].set_pitch(pitch);
    last_pitch_[lfo_no] = pitch;
    synced_[lfo_no] = false;
  }
}

void Processor::Process() {

  // do not run during the splash animation
  if (ui_->mode() == UI_MODE_SPLASH)
    return;

  // reset the LFOs if mode changed
  if (ui_->feat_mode() != previous_feat_mode_) {
    for (int i=0; i<kNumChannels; i++)
      lfo_[i].Init();
    previous_feat_mode_ = ui_->feat_mode();
    waveform_offset_ = 0;
  }

  for (int i=0; i<kNumChannels; i++) {
    // filter CV
    filtered_cv_[i] += (adc_->cv(i) - filtered_cv_[i]) >> 6;

    // detect triggers on the reset input
    int16_t reset = adc_->reset(i);

    if (reset < kResetThresholdLow)
      reset_trigger_armed_[i] = true;

    if (reset > kResetThresholdHigh &&
	reset_trigger_armed_[i]) {
      reset_triggered_[i] = true;
      int32_t dist_to_trig = kResetThresholdHigh - previous_reset_[i];
      int32_t dist_to_next = reset - previous_reset_[i];
      reset_subsample_[i] = dist_to_trig * 32L / dist_to_next;
    } else {
      reset_triggered_[i] = false;
    }

    previous_reset_[i] = reset;
  }

  switch (ui_->feat_mode()) {
  case FEAT_MODE_FREE:
  {
    for (uint8_t i=0; i<kNumChannels; i++) {
      SetFrequency(i);
    }
  }
  break;

  case FEAT_MODE_QUAD:
  {
    SetFrequency(0);
    // reset 2 holds the LFOs
    lfo_[0].set_hold(reset_triggered_[1]);
    // reset 3 changes direction
    lfo_[0].set_direction(!reset_triggered_[2]);
    // reset 4 changes waveform
    if (reset_triggered_[3]) {
      waveform_offset_++;
      reset_trigger_armed_[3] = false;
    }

    for (int i=1; i<kNumChannels; i++) {
      lfo_[i].link_to(&lfo_[0]);
#ifdef ZOOM_IS_ATTEN
      int16_t cv = (filtered_cv_[i] * ui_->atten(i)) >> 16;
      lfo_[i].set_level(AdcValuesToLevel(ui_->coarse(i), 0, cv));
#else
      lfo_[i].set_level(AdcValuesToLevel(ui_->coarse(i),
					 ui_->fine(i),
					 filtered_cv_[i]));
#endif
      lfo_[i].set_initial_phase((kNumChannels - i) * (UINT16_MAX >> 2));
    }
  }
  break;

  case FEAT_MODE_PHASE:
  {
    SetFrequency(0);
    // reset 2 holds the LFOs
    lfo_[0].set_hold(reset_triggered_[1]);
    // reset 3 changes direction
    lfo_[0].set_direction(!reset_triggered_[2]);
    // reset 4 changes waveform
    if (reset_triggered_[3]) {
      waveform_offset_++;
      reset_trigger_armed_[3] = false;
    }
    for (int i=1; i<kNumChannels; i++) {
      lfo_[i].link_to(&lfo_[0]);
#ifdef ZOOM_IS_ATTEN
      int16_t cv = (filtered_cv_[i] * ui_->atten(i)) >> 16;
      lfo_[i].set_initial_phase(AdcValuesToPhase(ui_->coarse(i), 0, cv));
#else
      lfo_[i].set_initial_phase(AdcValuesToPhase(ui_->coarse(i),
						 ui_->fine(i),
						 filtered_cv_[i]));
#endif
    }
  }
  break;

  case FEAT_MODE_DIVIDE:
  {
    SetFrequency(0);
    // reset 2 holds the LFOs
    lfo_[0].set_hold(reset_triggered_[1]);
    // reset 3 changes direction
    lfo_[0].set_direction(!reset_triggered_[2]);
    // reset 4 changes waveform
    if (reset_triggered_[3]) {
      waveform_offset_++;
      reset_trigger_armed_[3] = false;
    }
    for (int i=1; i<kNumChannels; i++) {
      lfo_[i].link_to(&lfo_[0]);
#ifdef ZOOM_IS_ATTEN
      int16_t cv = (filtered_cv_[i] * ui_->atten(i)) >> 16;
      lfo_[i].set_divider(AdcValuesToDivider(ui_->coarse(i), 0, cv));
#else
      lfo_[i].set_divider(AdcValuesToDivider(ui_->coarse(i),
      					     ui_->fine(i),
      					     filtered_cv_[i]));
#endif
      // when 1st channel resets, all other channels reset
      if (!ui_->sync_mode() && reset_triggered_[0]) {
	lfo_[i].Reset(reset_subsample_[0]);
      }
    }
  }
  break;

  case FEAT_MODE_LAST: break;	// to please the compiler
  }

  // send to DAC and step
  for (int i=0; i<kNumChannels; i++) {
    lfo_[i].Step();
    int s = ((ui_->shape() + waveform_offset_) % 4) + 1;
    LfoShape shape = static_cast<LfoShape>(s);
    dac_->set_sine(i, lfo_[i].ComputeSampleShape(SHAPE_SINE));
    dac_->set_asgn(i, lfo_[i].ComputeSampleShape(shape));
  }
}
}
