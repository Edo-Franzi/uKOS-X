#!/usr/bin/env zsh

# ukos_D2XX.
# ==========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for installing the ftdi D2XX driver.
#
#			Usage:
#			./ukos_D2XX.sh
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

readonly PACKS="${PATH_TOOLS_GCC}"/Packages/D2XX
readonly BUILD="${PATH_TOOLS_GCC}"/builds/D2XX

readonly LOG_FILE="${BUILD}"/ftdi_temp.txt
readonly DIRLOCAL="${PATH_TOOLS_ROOT}"/local

# Downloading sources
# -------------------

cd "${PATH_TOOLS_ROOT}"/Packages/,Sources

echo "Downloading FTDI D2xx"
case "$(uname)" in
	"Darwin")
		if [[ ! -f "D2XX${D2XX_OSX_VER}.zip" ]]; then
			echo "Downloading FTDI D2xx"
			rm -fr ../D2XX
			move_to_archive 'D2XX*'
			curl -OL https://ftdichip.com/wp-content/uploads/2024/04/D2XX"${D2XX_OSX_VER}".dmg
			hdiutil attach "D2XX${D2XX_OSX_VER}.dmg"
			cp -r /Volumes/dmg/release ../D2XX
			umount /Volumes/dmg
			rm "D2XX${D2XX_OSX_VER}.dmg"
		fi
		;;
	*)
		echo "Downloading FTDI D2xx"
		rm -fr ../D2XX
		move_to_archive 'D2XX*'
		wget "https://ftdichip.com/wp-content/uploads/2025/11/libftd2xx-linux-arm-v8-${D2XX_LINUX_VER}.tgz"
		tar xf "libftd2xx-linux-arm-v8-${D2XX_LINUX_VER}.tgz"
		mv linux-arm-v8 ../D2XX
		;;
esac

# Install the FTDI D2XX driver
# ----------------------------

rm -rf "${BUILD}"
mkdir -p "${BUILD}"

echo "Start of build: $(date)" > "${LOG_FILE}"

cd "${PACKS}"
case "$(uname)" in
	"Darwin")
		mkdir -p "${DIRLOCAL}"/lib "${DIRLOCAL}"/include
		cp build/libftd2xx."${D2XX_OSX_VER}".dylib "${DIRLOCAL}"/lib/
		ln -sf "${DIRLOCAL}"/lib/libftd2xx."${D2XX_OSX_VER}".dylib "${DIRLOCAL}"/lib/libftd2xx.dylib
		cp ftd2xx.h "${DIRLOCAL}"/include/
		cp WinTypes.h "${DIRLOCAL}"/include/
		;;
	"Linux")
		mkdir -p "${DIRLOCAL}"/lib "${DIRLOCAL}"/include
		cp libftd2xx.so."${D2XX_LINUX_VER}" "${DIRLOCAL}"/lib/
		ln -sf "${DIRLOCAL}"/lib/libftd2xx.so."${D2XX_LINUX_VER}" "${DIRLOCAL}"/lib/libftd2xx.so
		cp ftd2xx.h "${DIRLOCAL}"/include/
		cp WinTypes.h "${DIRLOCAL}"/include/
		;;
esac

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/ftdi_ready.txt
