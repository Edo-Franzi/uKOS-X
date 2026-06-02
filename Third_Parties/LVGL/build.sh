#!/usr/bin/env zsh

# build.
# ======

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Build the LVGL package
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

if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
	echo 'Variable PATH_UKOS_X_PACKAGE is not set!'
	exit 1
fi

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

readonly splash='
╔════════════════════════════════════════════════════════════╗
║               Lvgl Package Build System                    ║
║      Fetching upstream + Building all architectures        ║
╚════════════════════════════════════════════════════════════╝
'
printf '%b%s%b' "${GREEN}" "${splash}" "${NC}"

# Packages
# --------

readonly package=9.5.0

# Clone the right package

printf '\n%bDownload the LVGL package ...%b\n\n' "${BOLD}" "${NC}"

cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/LVGL"
rm -rf "${PATH_UKOS_X_PACKAGE}/Third_Parties/LVGL/LVGL-${package}"
git clone https://github.com/lvgl/lvgl.git "LVGL-${package}" -b "v${package}"

# Update path links

rm -f LVGL-current
ln -s "LVGL-${package}" LVGL-current

build_core() {
	cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/LVGL/Library/${1}/${2}"
	echo "Start of building: $(date)" > libLVGL_temp.log
	make -j all
	echo "End of building: $(date)" >> libLVGL_temp.log
	mv libLVGL_temp.log libLVGL_ready.txt
}

printf '\n%bBuilding for WKS43WV067_5_Inches! ...%b\n' "${BOLD}" "${NC}"
build_core WKS43WV067_5_Inches CORTEX_M7

printf '\n%bBuilding for WaveShare_2_Inches! ...%b\n' "${BOLD}" "${NC}"
build_core WaveShare_2_Inches CORTEX_M55

printf '\n%bBuilding for RK050HR18_5_Inches! ...%b\n' "${BOLD}" "${NC}"
build_core RK050HR18_5_Inches CORTEX_M85

printf '\n%bBuilding for TFT_2_4_Inches! ...%b\n' "${BOLD}" "${NC}"
build_core TFT_2_4_Inches RV64IMAFDC

printf '\n🎉 %bBuild Complete%b\n\n' "${GREEN}" "${NC}"
