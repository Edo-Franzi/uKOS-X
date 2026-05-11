#!/usr/bin/env zsh

# ukos_imagemagick.
# =================

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating the ImageMagick graphic tool.
#			git clone https://github.com/ImageMagick/ImageMagick.git ImageMagick
#			git submodule init
#			git submodule update
#
#			Usage:
#			./ukos_imagemagick.sh
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

readonly PACKS="${PATH_TOOLS_GCC}"/Packages/ImageMagick-"${IMAGEMAGICK_VER}"
readonly BUILD="${PATH_TOOLS_GCC}"/builds/ImageMagick-"${IMAGEMAGICK_VER}"
readonly CROSS="${PATH_TOOLS_GCC}"/cross/ImageMagick-"${IMAGEMAGICK_VER}"

readonly LOG_FILE="${BUILD}"/ImageMagick_temp.txt

# Downloading sources
# -------------------

if [[ ! -d "${PACKS}" ]]; then
	echo "Cloning ImageMagick-${IMAGEMAGICK_VER}"
	git clone https://github.com/ImageMagick/ImageMagick.git "${PACKS}"
else
	echo "Fetching ImageMagick-${IMAGEMAGICK_VER}"
	git -C "${PACKS}" fetch --quiet
fi
git -C "${PACKS}" checkout ${IMAGEMAGICK_VER}

# Building the tool
# -----------------

rm -rf "${BUILD}"
rm -rf "${CROSS}"
mkdir -p "${BUILD}"

echo "Start of build: $(date)" > "${LOG_FILE}"

export prefix="${CROSS}"
export executables="${prefix}"/bin

PATH="${executables}":"${PATH}"

cd "${BUILD}"
"${PACKS}"/configure --prefix="${prefix}" --with-modules \
				|| { echo "Error configuring ImageMagick"; exit 1; }
make			|| { echo "Error building ImageMagick";	   exit 1; }
make install	|| { echo "Error installing ImageMagick";  exit 1; }
make clean		|| { echo "Error cleaning ImageMagick";	   exit 1; }

# Update path links

cd "${PATH_TOOLS_GCC}"/cross
rm -f ImageMagick-current
ln -s ImageMagick-"${IMAGEMAGICK_VER}" ImageMagick-current

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/ImageMagick_ready.txt
