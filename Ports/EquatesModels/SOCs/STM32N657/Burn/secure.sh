#!/usr/bin/env zsh

# burn.
# =====

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		script for burning the arm flash via the stm32programmer.
#			script mainly generated with chatgpt
#
#			- Usage:
#			  ./secure.sh
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

SCRIPT_PATH="${0:A:h}"

BOOT="FSBL"
APPL="FLASH"

if [ -f "${SCRIPT_PATH}/fsbl/build/release/fsbl.bin" ]; then
	cp -f "${SCRIPT_PATH}/fsbl/build/release/fsbl.bin" "${SCRIPT_PATH}/fsbl.noSignature"
	cp -f "${SCRIPT_PATH}/fsbl.noSignature" "${BOOT}.bin"

elif [ -f "${SCRIPT_PATH}/fsbl.noSignature" ]; then
	cp -f "${SCRIPT_PATH}/fsbl.noSignature" "${BOOT}.bin"

else
	echo "You need to build the fsbl.bin"
	exit 1
fi

STM32_PROGRAMMER_BIN="${STM32_PROGRAMMER_BIN:-/Applications/STMicroelectronics/STM32Cube/STM32CubeProgrammer/STM32CubeProgrammer.app/Contents/Resources/bin}"
STM32_PROGRAMMER_CLI="${STM32_PROGRAMMER_BIN}/STM32_Programmer_CLI"
STM32_PROGRAMMER_SIG="${STM32_PROGRAMMER_BIN}/STM32_SigningTool_CLI"

"${STM32_PROGRAMMER_SIG}" -s -bin "${BOOT}.bin" -nk -of 0x80000000 -t fsbl -o "${BOOT}-trusted.bin" -hv 2.3 -dump "${BOOT}-trusted.bin" -align
"${STM32_PROGRAMMER_SIG}" -s -bin "${APPL}.bin" -nk -of 0x80000000 -t fsbl -o "${APPL}-trusted.bin" -hv 2.3 -dump "${APPL}-trusted.bin" -align

chmod +w "${BOOT}-trusted.bin" "${APPL}-trusted.bin"

"${STM32_PROGRAMMER_CLI}" -c port=SWD mode=HOTPLUG ap=1 -el "${STM32_PROGRAMMER_BIN}/ExternalLoader/MX25UM51245G_STM32N6570-NUCLEO.stldr" -d "${BOOT}-trusted.bin" 0x70000000
"${STM32_PROGRAMMER_CLI}" -c port=SWD mode=HOTPLUG ap=1 -el "${STM32_PROGRAMMER_BIN}/ExternalLoader/MX25UM51245G_STM32N6570-NUCLEO.stldr" -d "${APPL}-trusted.bin" 0x70100000
