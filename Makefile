# Copyright 2015 Matthias Puech.
#
# Author: Matthias Puech (matthias.puech@gmail.com)
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# 
# See http://creativecommons.org/licenses/MIT/ for more information.
#
# -----------------------------------------------------------------------------
#
# Makefile driver.

# System specifications
F_CRYSTAL      = 8000000L
F_CPU          = 72000000L
SYSCLOCK       = SYSCLK_FREQ_72MHz
FAMILY         = f10x
DENSITY        = md
MEMORY_MODE    = flash
# USB            = enabled
SAMPLE_RATE    = 16384

APPLICATION    = TRUE

# Preferred upload command
UPLOAD_COMMAND  = upload_combo_jtag

# Packages to build
TARGET         = batumi
BOOTLOADER     = batumi_bootloader
PACKAGES       = . drivers stmlib/utils stmlib/system
RESOURCES      = resources
ORIGINAL_BIN  = $(RESOURCES)/original_firmware.bin

include stmlib/makefile.inc

CCFLAGS := $(CCFLAGS) -DPOT_REVERSED -DZOOM_IS_LEVELATTEN -DLONG_PRESS_TO_CHANGE_MODE -DDISABLE_ZOOM_VALUE_RESET

flasher: bin
	cd flasher; pyinstaller -y "XAOC Firmware Update Tool.spec"

# Rule for uploading the original firmware
upload_original_serial:
	python2.7 $(STM32LOADER_PATH)stm32loader.py \
		-p $(PGM_SERIAL_PORT) \
		-b $(PGM_SERIAL_BAUD_RATE) \
		-e $(PGM_SERIAL_VERIFY) \
		-a $(BASE_ADDRESS) \
		-w $(ORIGINAL_BIN)

upload_original_jtag:
	openocd \
	-f $(OPENOCD_SCRIPTS_PATH)interface.cfg \
	-f $(OPENOCD_SCRIPTS_PATH)stm32$(FAMILY).cfg \
	-f $(OPENOCD_SCRIPTS_PATH)prelude_$(FAMILY).cfg \
	-f $(OPENOCD_SCRIPTS_PATH)erase_$(FAMILY).cfg \
	-c "flash write_bank 0 $(ORIGINAL_BIN) 0x0" \
	-c "verify_image $(ORIGINAL_BIN)" \
	-f $(OPENOCD_SCRIPTS_PATH)postlude.cfg
