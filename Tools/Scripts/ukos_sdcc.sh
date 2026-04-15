#!/usr/bin/env zsh

# ukos_sdcc.
# ==========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating the sdcc cross compiler
#			for Unix like machines (small 8-bit cpus).
#
#			Usage:
#			./ukos_sdcc.sh
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

readonly PACKS="${PATH_TOOLS_GCC}"/Packages/sdcc-"${SDCC_VER}"
readonly BUILD="${PATH_TOOLS_GCC}"/builds/sdcc-"${SDCC_VER}"
readonly CROSS="${PATH_TOOLS_GCC}"/cross/sdcc-"${SDCC_VER}"

readonly LOG_FILE="${BUILD}"/sdcc_temp.txt
readonly LIB_BOOST="${PATH_TOOLS_GCC}"/cross/boost-current
readonly GPUTIL="${PATH_TOOLS_GCC}"/cross/gputils-current
readonly prefix="${CROSS}"
readonly executables="${prefix}"/bin
readonly CPPFLAGS=-I"${LIB_BOOST}"/include
readonly LDFLAGS="-L${LIB_BOOST}/lib"

export	CPPFLAGS
export	LDFLAGS

# Downloading sources
# -------------------

cd "${PATH_TOOLS_ROOT}"/Packages/,Sources

if [[ ! -f "sdcc-${SDCC_VER}.tar.gz" ]]; then
	echo "Downloading sdcc"
	move_to_archive 'sdcc-*'
	"${WGET[@]}" https://sourceforge.net/projects/sdcc/files/sdcc/"${SDCC_VER}"/sdcc-src-"${SDCC_VER}".tar.bz2
fi

cd ..
echo "Extracting sdcc sources"
tar xjf ,Sources/sdcc-src-"${SDCC_VER}".tar.bz2

# Building the toolchain
# ----------------------

rm -rf "${BUILD}"
rm -rf "${CROSS}"
mkdir -p "${BUILD}"

PATH="${BUILD}/bin:${executables}:${PATH}"
PATH="${PATH}:${GPUTIL}/bin"

echo "Start of build: $(date)" > "${LOG_FILE}"

cd "${BUILD}"
"${PACKS}"/configure --prefix="${prefix}" --disable-werror --disable-ucsim \
				|| { echo "Error configuring sdcc"; exit 1; }
make			|| { echo "Error building sdcc";	exit 1; }
make install	|| { echo "Error installing sdcc";	exit 1; }
make clean		|| { echo "Error cleaning sdcc";	exit 1; }

# Update path links

cd "${PATH_TOOLS_GCC}"/cross
rm -f sdcc-current
ln -s sdcc-"${SDCC_VER}" sdcc-current

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/sdcc_ready.txt
