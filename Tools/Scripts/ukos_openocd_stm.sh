#!/usr/bin/env zsh

# ukos_openocd_stm.
# =================

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating the openocd support via
#			an FTDI chip and via the STLinkV2.
#			git clone --recurse-submodules https://github.com/STMicroelectronics/OpenOCD.git openocd-0.12.0-stm
#			git submodule init
#			git submodule update
#
#			With macport it is mandatory to install the package hidapi
#			before the construction of openocd.
#
#			Usage:
#			./ukos_openocd_stm.sh
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

# Choice of the native compiler
# -----------------------------

# For OSX, the native compiler is LLVM
# For Ubuntu, the native compiler is gcc

case "$(uname)" in
	"Darwin")
		echo "Target OSX clang"
		export CC=clang
		export CXX=clang++
		;;
	"Linux")
		echo "Target Linux"
		;;
esac

# Target
# ------

export MACHINE=stm

# Environment
# -----------

readonly PATCH="${PATH_SCRIPTS}"/Patches
readonly PACKS="${PATH_TOOLS_GCC}"/Packages/openocd-"${OPENOCD_VER}"-"${MACHINE}"
readonly BUILD="${PATH_TOOLS_GCC}"/builds/openocd-"${OPENOCD_VER}"
readonly CROSS="${PATH_TOOLS_GCC}"/cross/openocd-"${OPENOCD_VER}"

readonly LOG_FILE="${BUILD}"/"${MACHINE}"/openocd_temp.txt
readonly prefix="${CROSS}"/"${MACHINE}"
readonly DIRLOCAL="${PATH_TOOLS_ROOT}"/local

# Downloading sources
# -------------------

cd "${PATH_TOOLS_ROOT}"/Packages
if [[ ! -d openocd-"${OPENOCD_VER}"-stm ]]; then
	echo "Cloning openocd-${OPENOCD_VER} for stm"
	git clone --recurse-submodules https://github.com/STMicroelectronics/OpenOCD openocd-"${OPENOCD_VER}"-stm
fi

# Configurations
# --------------

export OPENOCD_CONFIG=(
	--disable-option-checking
	--disable-werror
	--enable-stlink
	--enable-jlink
	--enable-cmsis-dap
	--enable-remote-bitbang
	--enable-dummy
	--enable-ftdi
)

# Building the tool
# -----------------

rm -rf "${BUILD}"/"${MACHINE}"
rm -rf "${CROSS}"/"${MACHINE}"
mkdir -p "${BUILD}"/"${MACHINE}"

echo "Start of build: $(date)" > "${LOG_FILE}"

cd "${PACKS}"
./bootstrap

cd "${BUILD}"/"${MACHINE}"
case "$(uname)" in
	"Darwin")
		export PKG_CONFIG_PATH="${DIRLOCAL}"/lib/pkgconfig
		export CFLAGS="-I${DIRLOCAL}/include/libusb-1.0"
		"${PACKS}"/configure \
			"${OPENOCD_CONFIG[@]}" \
			CC=clang \
			--program-suffix=-${MACHINE} \
			--prefix="${prefix}" --with-sysroot="${DIRLOCAL}" \
			--libdir="${DIRLOCAL}"/lib		|| { echo "Error configuring openocd"; exit 1; }
		make "LDFLAGS = -L${DIRLOCAL}/lib"	|| { echo "Error building openocd";	   exit 1; }
		;;
	"Linux")
		export LDFLAGS="-pthread"
		"${PACKS}"/configure \
			"${OPENOCD_CONFIG[@]}" \
			CC=cc \
			--program-suffix=-${MACHINE} \
			--libdir=/usr/lib/x86_64-linux-gnu \
			--prefix="${prefix}" \
			--with-ftd2xx-lib=static \
			--with-ftd2xx-linux-tardir="${PATH_TOOLS_GCC}"/Packages/libftd2xx-"${D2XX_LINUX_VER}" \
											|| { echo "Error configuring openocd"; exit 1; }
		make								|| { echo "Error building openocd";	   exit 1; }
		sudo cp "${PACKS}"/contrib/60-openocd.rules /etc/udev/rules.d/
		;;
esac

make install || { echo "Error installing openocd"; exit 1; }
make clean	 || { echo "Error cleaning openocd";   exit 1; }

case "$(uname)" in
	"Darwin")
		install_name_tool -add_rpath "${DIRLOCAL}"/lib "${CROSS}"/"${MACHINE}"/bin/openocd-"${MACHINE}"
		;;
	"Linux")
		;;
esac

# Update path links

if [[ ! -d "${PATH_TOOLS_GCC}"/cross/openocd-current ]]; then
	mkdir "${PATH_TOOLS_GCC}"/cross/openocd-current
fi
cd "${PATH_TOOLS_GCC}"/cross/openocd-current
rm -f "${MACHINE}"
ln -s ../openocd-"${OPENOCD_VER}"/"${MACHINE}" "${MACHINE}"

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/"${MACHINE}"/openocd_ready.txt
