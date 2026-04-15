#!/usr/bin/env zsh

# ukos_picotool.
# ==============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating the picotool for Pico2 cpu.
#
#			Usage:
#			./ukos_picotool.sh
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

readonly PACKS_PICO_SDK="${PATH_TOOLS_GCC}"/Packages/pico-sdk-"${PICO_SDK_VER}"
readonly PACKS="${PATH_TOOLS_GCC}"/Packages/picotool-"${PICOTOOL_VER}"
readonly BUILD="${PATH_TOOLS_GCC}"/builds/picotool-"${PICOTOOL_VER}"
readonly CROSS="${PATH_TOOLS_GCC}"/cross/picotool-"${PICOTOOL_VER}"

readonly LOG_FILE="${BUILD}"/picotool_temp.txt
readonly prefix="${CROSS}"
readonly executables="${prefix}"/bin

export	DIRLOCAL="${PATH_TOOLS_ROOT}"/local
export	PKG_CONFIG_PATH="${DIRLOCAL}/lib/pkgconfig${PKG_CONFIG_PATH:+:${PKG_CONFIG_PATH}}"
export	CMAKE_PREFIX_PATH="${DIRLOCAL}${CMAKE_PREFIX_PATH:+:${CMAKE_PREFIX_PATH}}"

# Downloading sources
# -------------------

if [[ ! -d "${PACKS}" ]]; then
	echo "Cloning picotool"
	git clone --recurse-submodules --branch ${PICOTOOL_VER} https://github.com/raspberrypi/picotool.git "${PACKS}"
else
	echo "Fetching picotool"
	git -C "${PACKS}" fetch --quiet
fi
git -C "${PACKS}" checkout master

if [[ ! -d "${PACKS_PICO_SDK}" ]]; then
	echo "Cloning pico_sdk"
	git clone --recurse-submodules --branch ${PICO_SDK_VER} https://github.com/raspberrypi/pico-sdk.git "${PACKS_PICO_SDK}"
else
	echo "Fetching pico_sdk"
	git -C "${PACKS_PICO_SDK}" fetch --quiet
fi
git -C "${PACKS_PICO_SDK}" checkout master

# Building the tool
# -----------------

rm -rf "${BUILD}"
rm -rf "${CROSS}"
mkdir -p "${BUILD}"

echo "Start of build: $(date)" > "${LOG_FILE}"

cd "${BUILD}"
cmake -G "Unix Makefiles" \
	-S "${PACKS}" \
	-B "${BUILD}" \
	-DCMAKE_INSTALL_PREFIX="${CROSS}" \
	-DPICO_SDK_PATH="${PACKS_PICO_SDK}" \
	-DPICOTOOL_NO_LIBUSB=0 \
	-DCMAKE_OSX_ARCHITECTURES=arm64 \
	-DCMAKE_IGNORE_PATH="/usr/local"

cmake --build "${BUILD}" --parallel
cmake --install "${BUILD}" --prefix "${CROSS}"

# Update path links

cd "${PATH_TOOLS_GCC}"/cross
rm -f picotool-current
ln -s picotool-"${PICOTOOL_VER}" picotool-current

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/picotool_ready.txt
