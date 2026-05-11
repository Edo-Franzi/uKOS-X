#!/usr/bin/env zsh

# ukos_dfu-util.
# ==============

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating the dfu-util (i.e. for the RISC-V gd32 cpu).
#
#			Usage:
#			./ukos_dfu-util.sh
#
#			git clone --recurse-submodules git://git.code.sf.net/p/dfu-util/dfu-util dfu-util-${DFUUTIL_VER}
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

readonly PACKS="${PATH_TOOLS_GCC}"/Packages/dfu-util-"${DFUUTIL_VER}"
readonly BUILD="${PATH_TOOLS_GCC}"/builds/dfu-util-"${DFUUTIL_VER}"
readonly CROSS="${PATH_TOOLS_GCC}"/cross/dfu-util-"${DFUUTIL_VER}"

readonly LOG_FILE="${BUILD}"/dfu-util_temp.txt
readonly prefix="${CROSS}"
readonly executables="${prefix}"/bin
readonly DIRLOCAL="${PATH_TOOLS_ROOT}"/local

# Downloading sources
# -------------------

if [[ ! -d "${PACKS}" ]]; then
	echo "Cloning dfu-util-${DFUUTIL_VER}"
	git clone --recurse-submodules git://git.code.sf.net/p/dfu-util/dfu-util "${PACKS}"
else
	echo "Fetching dfu-util-${DFUUTIL_VER}"
	git -C "${PACKS}" fetch --quiet
fi
git -C "${PACKS}" checkout master

# Building the tool
# -----------------

rm -rf "${BUILD}"
rm -rf "${CROSS}"
mkdir -p "${BUILD}"

PATH="${executables}":"${PATH}"

echo "Start of build: $(date)" > "${LOG_FILE}"

cd "${PACKS}"
./autogen.sh

cd "${BUILD}"
env USB_CFLAGS=-I"${DIRLOCAL}"/include/libusb-1.0 \
	USB_LIBS=-L"${DIRLOCAL}/lib -lusb-1.0" \
	"${PACKS}"/configure --prefix="${prefix}" || { echo "Error configuring DFUUTIL"; exit 1; }
make										  || { echo "Error building DFUUTIL";	 exit 1; }
make install								  || { echo "Error installing DFUUTIL";	 exit 1; }
make clean									  || { echo "Error cleaning DFUUTIL";	 exit 1; }

# Update path links

cd "${PATH_TOOLS_GCC}"/cross
rm -f dfu-util-current
ln -s dfu-util-"${DFUUTIL_VER}" dfu-util-current

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/dfu-util_ready.txt

