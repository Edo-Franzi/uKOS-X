#!/usr/bin/env zsh

# ukos_srecord.
# =============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating the srecord tool.
#
#			In the file CMakeLists.txt we have to comment the following lines
#
#			FHS compliant paths for Linux installation
#			if(NOT WIN32 AND CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
#			#  set(CMAKE_INSTALL_PREFIX "/opt/${PROJECT_NAME}")
#			#  set(CMAKE_INSTALL_PREFIX "/usr")
#			endif()
#
#
#			Usage:
#			./ukos_srecord.sh
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

readonly PACKS="${PATH_TOOLS_GCC}"/Packages/srecord-"${SRECORD_VER}"
readonly BUILD="${PATH_TOOLS_GCC}"/builds/srecord-"${SRECORD_VER}"
readonly CROSS="${PATH_TOOLS_GCC}"/cross/srecord-"${SRECORD_VER}"

readonly LOG_FILE="${BUILD}"/srecord_temp.txt

# Downloading sources
# -------------------

if [[ ! -d "${PACKS}" ]]; then
	echo "Cloning srecord-${SRECORD_VER}"
	git clone https://github.com/sierrafoxtrot/srecord.git "${PACKS}"
else
	echo "Fetching srecord-${SRECORD_VER}"
	git -C "${PACKS}" fetch --quiet
fi
git -C "${PACKS}" checkout "v${SRECORD_VER}"

# Building the tool
# -----------------

rm -rf "${BUILD}"
rm -rf "${CROSS}"
mkdir -p "${BUILD}"

echo "Start of build: $(date)" > "${LOG_FILE}"

mkdir "${CROSS}"
mkdir "${CROSS}"/bin

cd "${BUILD}"
cmake -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX="${CROSS}" "${PACKS}"	|| { echo "Error configuring srecord";		 exit 1; }
cmake --build . --target srec_cat srec_cmp srec_info					|| { echo "Error building srecord binaries"; exit 1; }
install -m 755 "srec_cat/srec_cat"	 "${CROSS}/bin/"					|| { echo "Error installing srec_cat";		 exit 1; }
install -m 755 "srec_cmp/srec_cmp"	 "${CROSS}/bin/"					|| { echo "Error installing srec_cmp";		 exit 1; }
install -m 755 "srec_info/srec_info" "${CROSS}/bin/"					|| { echo "Error installing srec_info";		 exit 1; }

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/srecord_ready.txt
