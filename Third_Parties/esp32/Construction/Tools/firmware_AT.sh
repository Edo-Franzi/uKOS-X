#!/usr/bin/env zsh

# firmware_AT.
# ============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Burn the flash of the esp32 device
#
#			Usage:
#			Connect and boot uKOS
#			From the console type:
#				esp32 -reset
#				esp32 -boot
#
#			source export.sh
#			./firmware_AT.sh {-erase | -burn}
#
#			After the burning, change the baudrate to 921600-b/s
#				esp32 -reset
#				esp32 -connect 115200
#			Verify that everithing is OK
#				AT should return
#				AT
#			Set the name of the network
#				AT+CWSAP="uKOS-X_wifi","",1,0,4,0
#			Verify the current baudrate
#				AT+UART_DEF? should return
#				+UART_DEF:115200,8,1,0,1
#			Set the new baudrate
#				AT+UART_DEF=921600,8,1,0,1
#
#			usage with a wifi console
#			console wfi0
#				nc 192.168.4.1 9999 (on the computer)
#
#   (c) 2025-2026, Edo. Franzi
#   --------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Description: Lightweight, real-time multitasking operating
#   system for embedded microcontroller and DSP-based systems.
#
#   Permission is hereby granted, free of charge, to any person
#   obtaining a copy of this software and associated documentation
#   files (the "Software"), to deal in the Software without restriction,
#   including without limitation the rights to use, copy, modify,
#   merge, publish, distribute, sublicense, and/or sell copies of the
#   Software, and to permit persons to whom the Software is furnished
#   to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be
#   included in all copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
#   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
#   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.
#
#------------------------------------------------------------------------

set -euo pipefail

if [[ -z "${IDF_PATH:-}" ]]; then
	echo 'Variable IDF_PATH is not set!'
	exit 1
fi

if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
	echo 'Variable PATH_UKOS_X_PACKAGE is not set!'
	exit 1
fi

# Packages
# --------

export CHIP=esp32
export SERIAL=/dev/cu.usbserial-uKOS_1
export BAUDRATE=115200
export FIRMWARE=V4.1.1.0
export COMMAND="${1:-}"

cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/esp-idf-current/AT_firmware/ESP32-WROOM-32-AT-${FIRMWARE}"
echo 'Start of burning:' > esp32_temp.txt
date >> esp32_temp.txt

# To fully erase/burn the flash

if [[ "${COMMAND}" = '-erase' ]]; then
	python -m esptool \
		--chip "${CHIP}" \
		--port "${SERIAL}" \
		--baud "${BAUDRATE}" \
		--before 'default_reset' \
		--after 'hard_reset' \
		erase_flash

elif [[ "${COMMAND}" = '-burn' ]]; then
	python -m esptool \
		--chip "${CHIP}" \
		--port "${SERIAL}" \
		--baud "${BAUDRATE}" \
		--before 'default_reset' \
		--after 'hard_reset' \
		write_flash -z --flash_mode dio --flash_freq 40m --flash_size 4MB \
			0x1000 bootloader/bootloader.bin \
			0x100000 esp-at.bin \
			0x8000 partition_table/partition-table.bin \
			0x10000 ota_data_initial.bin \
			0x20000 at_customize.bin \
			0x21000 customized_partitions/mfg_nvs.bin

else
	echo 'Usage: ./firmware_AT.sh {-erase | -burn}'
	exit 1
fi

echo 'End of burning:' >> esp32_temp.txt
date >> esp32_temp.txt
mv esp32_temp.txt esp32_ready.txt
