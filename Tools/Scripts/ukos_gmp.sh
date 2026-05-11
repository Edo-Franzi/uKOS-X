#!/usr/bin/env zsh

# ukos_gmp.
# =========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for building the math gmp librarie
#			for building the versions of gdb greater than 11.x.x.
#
#			Usage:
#			./ukos_gmp.sh
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

readonly PACKS="${PATH_TOOLS_GCC}"/Packages/gmp-"${GMP_VER}"
readonly BUILD="${PATH_TOOLS_GCC}"/builds/gmp-"${GMP_VER}"
readonly CROSS="${PATH_TOOLS_GCC}"/cross/gmp-"${GMP_VER}"

readonly LOG_FILE="${BUILD}"/gmp_temp.txt
readonly DIRLOCAL="${PATH_TOOLS_ROOT}"/local

# Downloading sources
# -------------------

cd "${PATH_TOOLS_ROOT}"/Packages/,Sources

if [[ ! -f "gmp-${GMP_VER}.tar.lz" ]]; then
	echo "Downloading gmp-${GMP_VER}"
	move_to_archive 'gmp-*'
	"${WGET[@]}" https://ftp.gnu.org/gnu/gmp/gmp-"${GMP_VER}".tar.lz
fi

cd ..
echo "Extracting gmp sources"
tar --lzip -xf ,Sources/gmp-"${GMP_VER}".tar.lz

# Building the library
# --------------------

rm -rf "${BUILD}"
mkdir -p "${BUILD}"

echo "Start of build: $(date)" > "${LOG_FILE}"

cd "${PACKS}"
autoreconf -i -s

cd "${BUILD}"
"${PACKS}"/configure --prefix=${DIRLOCAL} --enable-cxx --with-pic CC="gcc" CFLAGS="-O2 -std=gnu99" CXX="g++" CXXFLAGS="-O2 -std=gnu++11" \
				|| { echo "Error configuring GMP"; exit 1; }
make			|| { echo "Error building GMP";	   exit 1; }
make check		|| { echo "Error checking GMP";	   exit 1; }
make install	|| { echo "Error installing GMP";  exit 1; }
make clean		|| { echo "Error cleaning GMP";	   exit 1; }

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/gmp_ready.txt
