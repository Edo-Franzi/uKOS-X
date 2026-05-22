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
# Goal:		script for burning the arm flash via the stm32programmer.
#			script mainly generated with chatgpt
#
#			- Usage:
#			./burn.sh
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

set -e

# Colours for messages

readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
readonly BOLD='\033[1m'
readonly FAINT='\033[2m'
readonly ITALIC='\033[3m'
readonly NC='\033[0m' # No Color

HEX=testROM.hex

# Detection of the STM32_Programmer_CLI on different OS

detect_cli() {

	# Already on the path?
	if command -v STM32_Programmer_CLI >/dev/null 2>&1; then
		echo "STM32_Programmer_CLI"
		return
	fi

	# macOS (Spotlight via mdfind)
	if [[ "$OSTYPE" == "darwin"* ]]; then
		if [[ -z "$STM32_PROGRAMMER_CLI" ]]; then
			STM32_PROGRAMMER_CLI="/Applications/STMicroelectronics/STM32Cube/STM32CubeProgrammer/STM32CubeProgrammer.app/Contents/Resources/bin/STM32_Programmer_CLI"
		fi

		# Verify if executable
		if [[ -x "$STM32_PROGRAMMER_CLI" ]]; then
			echo "$STM32_PROGRAMMER_CLI"
			return 0
		fi
	fi

	# Linux : search in /opt ou /usr/local
	if [[ -d /opt/st ]]; then
		find /opt/st -name STM32_Programmer_CLI 2>/dev/null | head -n 1
		return
	fi

	# Windows (Git Bash / WSL) : exemple of path
	if [[ -d "/c/Program Files/STMicroelectronics" ]]; then
		find "/c/Program Files/STMicroelectronics" -name STM32_Programmer_CLI.exe 2>/dev/null | head -n 1
		return
	fi
}

# Locate the STM32_Programmer_CLI
# Extract the serial number of the ST link
# Burn the testROM.hex

CLI="$(detect_cli)"

if [[ -z "$CLI" ]]; then
	echo -e "${RED}STM32_Programmer_CLI not found${NC}"
	exit 1
fi

if [[ ! -f "$HEX" ]]; then
	echo -e "${RED}File not found : $HEX${NC}"
	exit 1
fi

SN=$("$CLI" -l | grep "ST-LINK SN" | head -n1 | awk -F':' '{gsub(/ /, "", $2); print $2}')

if [[ -z "$SN" ]]; then
	echo -e "${RED}ST-Link not detected.${NC}"
	exit 1
fi

echo -e "${GREEN}ST-Link detected : $SN${NC}"
echo -e "${GREEN}Flashing of the $HEX ...${NC}"

"$CLI" -c port=SWD sn="$SN" -e all -w "$HEX" -v -rst
