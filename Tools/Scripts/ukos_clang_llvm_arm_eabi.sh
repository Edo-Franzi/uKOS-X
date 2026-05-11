#!/usr/bin/env zsh

# ukos_clang_llvm_arm_eabi.
# =========================

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-22
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating LLVM clang cross compilers
#			for Unix like machines
#
#			Github project LLVM-embedded-toolchain-for-Arm
#			Supported architectures
#				Armv6-M
#				Armv7-M
#				Armv7E-M
#				Armv8-M Mainline
#				Armv8.1-M Mainline
#				Armv4T (experimental)
#				Armv5TE (experimental)
#				Armv6 (experimental, using the Armv5TE library variant)
#				AArch64 armv8.0 (experimental)
#
#			Usage:
#			./ukos_clang_llvm_arm_eabi.sh
#
#			OS:
#			OSX 26.xx			yes
#			Ubuntu 26.04 LTS	yes
#
#	(c) 2025-2026, Laurent von Allmen
#	---------------------------------
#											   __ ______  _____
#	Edo. Franzi							__	__/ //_/ __ \/ ___/
#	5-Route de Cheseaux				   / / / / ,< / / / /\__ \
#	CH 1400 Cheseaux-Noréaz			  / /_/ / /| / /_/ /___/ /
#									  \__,_/_/ |_\____//____/
#	edo.franzi@ukos.ch
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
# For Ubuntu, the native compiler is gcc, but clang need clang

case "$(uname)" in
	"Darwin")
		echo "Target OSX clang"
		CC=clang
		CXX=clang++
		nb_parallel_jobs=$(($(sysctl -n hw.ncpu) + 1))
		;;
	"Linux")
		echo "Target Linux"
		CC=clang
		CXX=clang++
		nb_parallel_jobs=$(nproc)
		;;
esac

export CC=clang
export CXX=clang++

readonly CC
readonly CXX
readonly nb_parallel_jobs

# Environment
# -----------

readonly PACKS_LLVM="${PATH_TOOLS_ROOT}"/Packages/llvm-"${LLVM_ARM_VER}"/arm
readonly SRC_ATFE="${PACKS_LLVM}"/arm-software/embedded
readonly BUILD="${PATH_TOOLS_ROOT}"/builds/llvm-arm
readonly CROSS="${PATH_TOOLS_ROOT}"/cross/LLVM-ET-Arm-"${LLVM_ARM_VER}"N-Darwin-"$(uname -m)"
readonly LOG_FILE="${BUILD}"/clang_llvm_arm_temp.txt

# Downloading sources
# -------------------

cd "${PATH_TOOLS_ROOT}"/Packages

if [[ ! -d llvm-"${LLVM_ARM_VER}"/arm ]]; then
	echo "Downloading LLVM-${LLVM_ARM_VER} embedded for Arm"
	LLVM_ARM_MAJOR="${LLVM_ARM_VER%%.*}"
	git clone --branch release/arm-software/${LLVM_ARM_MAJOR}.x https://github.com/arm/arm-toolchain.git "llvm-${LLVM_ARM_VER}/arm"
	git -C llvm-"${LLVM_ARM_VER}"/arm checkout ${LLVM_ARM_COMMIT}
fi

if [[ -d "${PATH_SCRIPTS}"/Patches/llvm-arm/"${LLVM_ARM_VER}" ]]; then
	pushd "${PACKS_LLVM}" >/dev/null
	for i in "${PATH_SCRIPTS}"/Patches/llvm-arm/"${LLVM_ARM_VER}"/*
	do
		if [[ -f "$i" ]]; then
			git apply --quiet "$i"
		fi
	done
	popd >/dev/null
fi

# Building the toolchain
# ----------------------

rm -rf "${BUILD}"
mkdir -p "${BUILD}"
echo "Start of build: $(date)" > "${LOG_FILE}"
rm -rf "${CROSS}"

echo "$(date) Start of CMake configuration" >> "${LOG_FILE}"
cmake -S "${SRC_ATFE}" -B "${BUILD}" -GNinja \
	-DFETCHCONTENT_QUIET=OFF \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_INSTALL_PREFIX="${CROSS}" \
	-DLLVM_TOOLCHAIN_C_LIBRARY=newlib
echo "$(date) End of CMake configuration" >> "${LOG_FILE}"

echo "$(date) Start of build LLVM" >> "${LOG_FILE}"
ninja -C "${BUILD}" -j ${nb_parallel_jobs} llvm-toolchain 2>/dev/null
ninja -C "${BUILD}" install-llvm-toolchain 2>/dev/null
echo "$(date) End of build LLVM" >> "${LOG_FILE}"

# Remove debug info from libraries

find "${CROSS}"/lib/clang-runtimes/arm-none-eabi -name "lib*.a" -exec "${CROSS}"/bin/llvm-strip --strip-unneeded "{}" +

git -C "${PACKS_LLVM}" reset --hard

# Update path links

current_dir="${PATH_TOOLS_ROOT}"/cross/llvm-current
if [[ ! -d "${current_dir}" ]]; then
	mkdir "${current_dir}"
fi
cd "${current_dir}"
rm -f arm
ln -s ../LLVM-ET-Arm-"${LLVM_ARM_VER}"N-Darwin-$(uname -m) arm

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${CROSS}"/clang_llvm_arm_ready"$(date -I)".txt
rm -fr "${BUILD}"
