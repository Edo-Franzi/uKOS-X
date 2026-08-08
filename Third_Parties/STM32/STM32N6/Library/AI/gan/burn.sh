#!/usr/bin/env zsh

# burn.
# =====

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		script for burning a demo into the arm flash via the stm32programmer.
#			This is for discovery boards.
#
#			- Usage:
#			  ./burn.sh
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

readonly WEIGHTS="NN_weight"

if [[ ! -f "${WEIGHTS}.bin" ]]; then
	print -u2 "Error: weights file not found: ${WEIGHTS}.raw"
	exit 1
fi

STM32_PROGRAMMER_CLI="${STM32_PROGRAMMER_CLI:-/Applications/STMicroelectronics/STM32Cube/STM32CubeProgrammer/STM32CubeProgrammer.app/Contents/Resources/bin/STM32_Programmer_CLI}"
if [[ ! -x "${STM32_PROGRAMMER_CLI}" ]]; then
	print -u2 "Error: STM32_Programmer_CLI not found."
	print -u2 "Install STM32CubeProgrammer, or set STM32_PROGRAMMER_CLI to its full path:"
	print -u2 "  export STM32_PROGRAMMER_CLI=/path/to/STM32_Programmer_CLI"
	exit 1
fi

STM32_PROGRAMMER_BIN=${STM32_PROGRAMMER_CLI:h}

"${STM32_PROGRAMMER_CLI}" -c port=SWD mode=HOTPLUG ap=1 -el "${STM32_PROGRAMMER_BIN}/ExternalLoader/MX66UW1G45G_STM32N6570-DK.stldr" -d "${WEIGHTS}.bin" 0x71000000 -v
