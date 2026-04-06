#!/usr/bin/env zsh

# build.
# ======

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Build the MicroPython package and the libMicroPython.a (including the uKOS interface)
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
║            Micropython Package Build System                ║
║      Fetching upstream + Building all architectures        ║
╚════════════════════════════════════════════════════════════╝
'
printf '%b%s%b' "${GREEN}" "${splash}" "${NC}"

# Packages
# --------

readonly package=1.28.0

# Clone the right package

printf '\n%bDownload the MicroPython package ...%b\n\n' "${BOLD}" "${NC}"

cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/MicroPython"
rm -rf "${PATH_UKOS_X_PACKAGE}/Third_Parties/MicroPython/MicroPython-${package}"
git clone https://github.com/micropython/micropython.git "MicroPython-${package}" -b "v${package}"

# Update path links

rm -f MicroPython-current
ln -s "MicroPython-${package}" MicroPython-current

# Building for CORTEX_M4, _M7, _M33, _M55, _M85

export PATH_MICROPYTHON_LIBRARY="${PATH_UKOS_X_PACKAGE}/Third_Parties/MicroPython/Library"

build_core() {
	cd "${PATH_MICROPYTHON_LIBRARY}/${1}"
	echo "Start of building: $(date)" > libMicroPython_temp.log
	make -j all
	echo "End of building: $(date)" >> libMicroPython_temp.log
	mv libMicroPython_temp.log libMicroPython_ready.txt
}

printf '\n%bBuilding for cortex M4! ...%b\n' "${BOLD}" "${NC}"
build_core CORTEX_M4

printf '\n%bBuilding for cortex M7! ...%b\n' "${BOLD}" "${NC}"
build_core CORTEX_M7

printf '\n%bBuilding for cortex M33! ...%b\n' "${BOLD}" "${NC}"
build_core CORTEX_M33

printf '\n%bBuilding for cortex M55! ...%b\n' "${BOLD}" "${NC}"
build_core CORTEX_M55

printf '\n%bBuilding for cortex M85! ...%b\n' "${BOLD}" "${NC}"
build_core CORTEX_M85

printf '\n🎉 %bBuild Complete%b\n\n' "${GREEN}" "${NC}"
