#!/usr/bin/env zsh

# ukos_mpfr.
# ==========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for building the math mpfr librarie
#			for building the versions of gdb greater than 11.x.x.
#
#			Usage:
#			./ukos_mpfr.sh
#
#			mpfr need gmp; so, first install gmp
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

readonly PACKS="${PATH_TOOLS_GCC}"/Packages/mpfr-"${MPFR_VER}"
readonly BUILD="${PATH_TOOLS_GCC}"/builds/mpfr-"${MPFR_VER}"
readonly CROSS="${PATH_TOOLS_GCC}"/cross/mpfr-"${MPFR_VER}"

readonly LOG_FILE="${BUILD}"/mpfr_temp.txt
readonly DIRLOCAL="${PATH_TOOLS_ROOT}"/local

# Downloading sources
# -------------------

cd "${PATH_TOOLS_ROOT}"/Packages/,Sources

if [[ ! -f "mpfr-${MPFR_VER}.tar.bz2" ]]; then
	echo "Downloading mpfr-${MPFR_VER}"
	move_to_archive 'mpfr-*'
	"${WGET[@]}" https://www.mpfr.org/mpfr-current/mpfr-"${MPFR_VER}".tar.bz2
fi

cd ..
echo "Extracting mpfr sources"
tar xjf ,Sources/mpfr-"${MPFR_VER}".tar.bz2

# Building the library
# --------------------

rm -rf "${BUILD}"
mkdir -p "${BUILD}"

echo "Start of build: $(date)" > "${LOG_FILE}"

cd "${BUILD}"
env CPPFLAGS=-I"${DIRLOCAL}"/include \
	LDFLAGS=-L"${DIRLOCAL}"/lib \
	PKG_CONFIG_PATH="${DIRLOCAL}"/lib/pkgconfig \
	"${PACKS}"/configure --prefix="${DIRLOCAL}"	|| { echo "Error configuring MPFR"; exit 1; }
make											|| { echo "Error building MPFR";	exit 1; }
make install									|| { echo "Error installing MPFR";  exit 1; }
make clean										|| { echo "Error cleaning MPFR";	exit 1; }

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/mpfr_ready.txt
