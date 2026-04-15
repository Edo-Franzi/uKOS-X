#!/usr/bin/env zsh

# ukos_doxygen.
# =============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating the doxygen documenting tool.
#
#			Usage:
#			./ukos_doxygen.sh
#
#			OS:
#			OSX 26.xx			yes
#			Ubuntu 26.04 LTS	yes
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

# Source the configuration file from the same directory
source "$(dirname "$0")"/config_install.sh

set -euo pipefail

# Environment
# -----------

readonly PACKS="${PATH_TOOLS_GCC}"/Packages/doxygen-"${DOXYGEN_VER}"
readonly BUILD="${PATH_TOOLS_GCC}"/builds/doxygen-"${DOXYGEN_VER}"
readonly CROSS="${PATH_TOOLS_GCC}"/cross/doxygen-"${DOXYGEN_VER}"

readonly LOG_FILE="${BUILD}"/doxygen_temp.txt

# Downloading sources
# -------------------

cd "${PATH_TOOLS_ROOT}"/Packages/,Sources

if [[ ! -f "doxygen-${DOXYGEN_VER}.tar.gz" ]]; then
	echo "Downloading doxygen"
	move_to_archive "doxygen-*"
	"${WGET[@]}" https://www.doxygen.nl/files/doxygen-"${DOXYGEN_VER}".src.tar.gz
fi

cd ..
echo "Extracting doxygen sources"
tar xzf ,Sources/doxygen-"${DOXYGEN_VER}".src.tar.gz

# Building the tool
# -----------------

rm -rf "${BUILD}"
rm -rf "${CROSS}"
mkdir -p "${BUILD}"

echo "Start of build: $(date)" > "${LOG_FILE}"

mkdir "${CROSS}"
mkdir "${CROSS}"/bin

cd "${BUILD}"
cmake -G "Unix Makefiles" "${PACKS}"
cmake "-DCMAKE_INSTALL_PREFIX=${CROSS}" "${PACKS}"
make
make install

# Update path links

cd "${PATH_TOOLS_GCC}"/cross
rm -f doxygen-current
ln -s doxygen-"${DOXYGEN_VER}" doxygen-current

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/doxygen_ready.txt
