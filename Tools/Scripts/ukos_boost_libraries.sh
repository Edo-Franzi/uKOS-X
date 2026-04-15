#!/usr/bin/env zsh

# ukos_boost_libraries
# ====================

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating the Boost libraries necessary
#			for building the versions of sdcc.
#
#			Usage:
#			./ukos_boost_libraries.sh
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

readonly PACKS="${PATH_TOOLS_ROOT}"/Packages/boost-"${BOOST_VER}"
readonly BUILD="${PATH_TOOLS_ROOT}"/builds/boost-"${BOOST_VER}"
readonly CROSS="${PATH_TOOLS_GCC}"/cross/boost-"${BOOST_VER}"

readonly LOG_FILE="${BUILD}"/boost_temp.txt
readonly prefix="${CROSS}"
readonly executables="${prefix}"/bin

PATH="${executables}":"${PATH}"

# Downloading sources
# -------------------

if [[ ! -d "${PACKS}" ]]; then
	echo "Cloning boost-${BOOST_VER}"
	git clone --recursive https://github.com/boostorg/boost.git "${PACKS}"
else
	echo "Fetching boost-${BOOST_VER}"
	git -C "${PACKS}" fetch --quiet
fi
git -C "${PACKS}" checkout boost-"${BOOST_VER}"

# Building the library
# --------------------

rm -rf "${BUILD}"
rm -rf "${CROSS}"
mkdir -p "${BUILD}"

echo "Start of build: $(date)" > "${LOG_FILE}"

cd "${PACKS}"
./bootstrap.sh --prefix="${prefix}"
./b2 install

# Update path links

cd "${PATH_TOOLS_ROOT}"/cross
rm -f boost-current
ln -s boost-"${BOOST_VER}" boost-current

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/boost_ready.txt
