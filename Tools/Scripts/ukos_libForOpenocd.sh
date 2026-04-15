#!/usr/bin/env zsh

# ukos_libForOpenocd
# ==================

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating all the libs necessary
#			for building openocd.
#			- libftdi
#			- libusb
#			- libconfuse
#			- libjaylink
#
#			Usage:
#			./ukos_libForOpenocd.sh
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

readonly PACKS_LIBUSB="${PATH_TOOLS_GCC}"/Packages/libusb-"${LIBUSB_VER}"
readonly BUILD_LIBUSB="${PATH_TOOLS_GCC}"/builds/libusb-"${LIBUSB_VER}"

readonly PACKS_LIBCONFUSE="${PATH_TOOLS_GCC}"/Packages/confuse-"${LIBCONFUSE_VER}"
readonly BUILD_LIBCONFUSE="${PATH_TOOLS_GCC}"/builds/libconfuse-"${LIBCONFUSE_VER}"

readonly PACKS_LIBJAYLINK="${PATH_TOOLS_GCC}"/Packages/libjaylink-"${LIBJAYLINK_VER}"
readonly BUILD_LIBJAYLINK="${PATH_TOOLS_GCC}"/builds/libjaylink-"${LIBJAYLINK_VER}"

readonly PACKS_LIBFTDI="${PATH_TOOLS_GCC}"/Packages/libftdi1-"${LIBFTDI_VER}"
readonly BUILD_LIBFTDI="${PATH_TOOLS_GCC}"/builds/libftdi1-"${LIBFTDI_VER}"

readonly LOG_FILE_LIBUSB="${BUILD_LIBUSB}"/libusb_temp.txt
readonly LOG_FILE_LIBCONFUSE="${BUILD_LIBCONFUSE}"/libconfuse_temp.txt
readonly LOG_FILE_LIBJAYLINK="${BUILD_LIBJAYLINK}"/libjaylink_temp.txt
readonly LOG_FILE_LIBFTDI="${BUILD_LIBFTDI}"/libftdi1_temp.txt
readonly DIRLOCAL="${PATH_TOOLS_ROOT}"/local

# Downloading sources
# -------------------

cd "${PATH_TOOLS_ROOT}"/Packages/,Sources

if [[ ! -f "libusb-${LIBUSB_VER}.tar.bz2" ]]; then
	echo "Downloading libusb"
	move_to_archive 'libusb-*'
	"${WGET[@]}" https://github.com/libusb/libusb/releases/download/v"${LIBUSB_VER}"/libusb-"${LIBUSB_VER}".tar.bz2
fi

if [[ ! -f "confuse-${LIBCONFUSE_VER}.tar.gz" ]]; then
	echo "Downloading confuse"
	move_to_archive 'confuse-*'
	"${WGET[@]}" https://github.com/martinh/libconfuse/releases/download/v"${LIBCONFUSE_VER}"/confuse-"${LIBCONFUSE_VER}".tar.gz
fi

if [[ ! -f "libftdi1-${LIBFTDI_VER}.tar.bz2" ]]; then
	echo "Downloading libftdi"
	move_to_archive 'ibftdi1-*'
	"${WGET[@]}" https://www.intra2net.com/en/developer/libftdi/download/libftdi1-"${LIBFTDI_VER}".tar.bz2
fi

cd ..
echo "Extracting libusb sources"
tar xjf ,Sources/libusb-"${LIBUSB_VER}".tar.bz2

echo "Extracting confuse sources"
tar xzf ,Sources/confuse-"${LIBCONFUSE_VER}".tar.gz

echo "Extracting libftdi1 sources"
tar xjf ,Sources/libftdi1-"${LIBFTDI_VER}".tar.bz2

if [[ ! -d "${PACKS_LIBJAYLINK}" ]]; then
	echo "Cloning libjaylink-${LIBJAYLINK_VER}"
	git clone --recurse-submodules --branch ${LIBJAYLINK_VER} https://gitlab.zapb.de/libjaylink/libjaylink.git "${PACKS_LIBJAYLINK}"
else
	echo "Fetching libjaylink-${LIBJAYLINK_VER}"
	git -C "${PACKS_LIBJAYLINK}" fetch --quiet
fi
git -C "${PACKS_LIBJAYLINK}" checkout ${LIBJAYLINK_VER}

# Building the libusb
# -------------------

rm -rf "${BUILD_LIBUSB}"
mkdir -p "${BUILD_LIBUSB}"

echo "Start of build: $(date)" > "${LOG_FILE_LIBUSB}"

cd "${BUILD_LIBUSB}"
"${PACKS_LIBUSB}"/configure --prefix="${DIRLOCAL}"

make
make install
make clean

echo "End of build:	  $(date)" >> "${LOG_FILE_LIBUSB}"
mv "${LOG_FILE_LIBUSB}" "${BUILD_LIBUSB}"/libusb_ready.txt

# Building the libconfuse
# -----------------------

rm -rf "${BUILD_LIBCONFUSE}"
mkdir -p "${BUILD_LIBCONFUSE}"

echo "Start of build: $(date)" > "${LOG_FILE_LIBCONFUSE}"

cd "${BUILD_LIBCONFUSE}"
"${PACKS_LIBCONFUSE}"/configure --prefix="${DIRLOCAL}"

make
make install
make clean

echo "End of build:	  $(date)" >> "${LOG_FILE_LIBCONFUSE}"
mv "${LOG_FILE_LIBCONFUSE}" "${BUILD_LIBCONFUSE}"/libconfuse_ready.txt

# Building the libjaylink
# -----------------------

if [[ "$(uname)" == "Linux" ]]; then
	export ACLOCAL_PATH=/usr/share/aclocal
fi

rm -rf "${BUILD_LIBJAYLINK}"
mkdir -p "${BUILD_LIBJAYLINK}"

echo "Start of build: $(date)" > "${LOG_FILE_LIBJAYLINK}"

cd "${PACKS_LIBJAYLINK}"
./autogen.sh

cd "${BUILD_LIBJAYLINK}"
"${PACKS_LIBJAYLINK}"/configure --prefix="${DIRLOCAL}"

make
make install
make clean

echo "End of build:	  $(date)" >> "${LOG_FILE_LIBJAYLINK}"
mv "${LOG_FILE_LIBJAYLINK}" "${BUILD_LIBJAYLINK}"/libjaylink_ready.txt

# Building the libftdi
# --------------------

rm -rf "${BUILD_LIBFTDI}"
mkdir -p "${BUILD_LIBFTDI}"

echo "Start of build: $(date)" > "${LOG_FILE_LIBFTDI}"

cd "${BUILD_LIBFTDI}"
case "$(uname)" in
	"Darwin")
		cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DDOCUMENTATION=off -DCMAKE_INSTALL_PREFIX="${DIRLOCAL}" \
		-DLIBUSB_INCLUDE_DIR="${DIRLOCAL}"/include/libusb-1.0 -DLIBUSB_LIBRARIES="${DIRLOCAL}"/lib/libusb-1.0.dylib "${PACKS_LIBFTDI}" \
		-DCONFUSE_LIBRARY="${DIRLOCAL}"/lib/libconfuse.dylib -DCONFUSE_INCLUDE_DIR="${DIRLOCAL}"/include
		;;
	"Linux")
		cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DDOCUMENTATION=off -DCMAKE_INSTALL_PREFIX="${DIRLOCAL}" \
		-DLIBUSB_INCLUDE_DIR="${DIRLOCAL}"/include/libusb-1.0 -DLIBUSB_LIBRARIES="${DIRLOCAL}"/lib/libusb-1.0.so "${PACKS_LIBFTDI}" \
		-DCONFUSE_LIBRARY="${DIRLOCAL}"/lib/libconfuse.so -DCONFUSE_INCLUDE_DIR="${DIRLOCAL}"/include
		;;
esac

make
make install
make clean

case "$(uname)" in
	"Darwin")
		install_name_tool -change libftdi1.2.dylib "${DIRLOCAL}"/lib/libftdi1.2.dylib "${DIRLOCAL}"/bin/ftdi_eeprom
		;;
	"Linux")
		;;
esac

echo "End of build:   $(date)" >> "${LOG_FILE_LIBFTDI}"
mv "${LOG_FILE_LIBFTDI}" "${BUILD_LIBFTDI}"/libftdi1_ready.txt
