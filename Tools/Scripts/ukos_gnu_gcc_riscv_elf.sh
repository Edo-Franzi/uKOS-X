#!/usr/bin/env zsh

# ukos_gnu_gcc_riscv_elf.
# =======================

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating generic gcc cross compilers
#			for Unix like machines (for the uKOS-X project)
#
#			RISC-V family (for RV32 & RV64-bits)
#
#			Usage:
#			./ukos_gnu_gcc_riscv_elf.sh
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
source "$(dirname "$0")/config_install.sh"

set -euo pipefail

# Choice of the native compiler
# -----------------------------

# For OSX, the native compiler is LLVM
# For Ubuntu, the native compiler is gcc

case "$(uname)" in
	"Darwin")
		echo "Target OSX clang"
		export CC="clang"
		export CXX="clang++"
		export PARALLEL_JOBS="$(( $(sysctl -n hw.ncpu) - 1 ))"
		;;
	"Linux")
		echo "Target Linux"
		export PARALLEL_JOBS="4"
		;;
esac

# Target
# ------

export TARGET="riscv64-unknown-elf"
export MACHINE="riscv"
export GCC_VER="${GCC_RVXX_VER}"

# Environment
# -----------

export PACKS_GCC="${PATH_TOOLS_GCC}/Packages/gcc-${GCC_VER}"
export PACKS_BIN="${PATH_TOOLS_GCC}/Packages/binutils-${BIN_VER}"
export PACKS_NBL="${PATH_TOOLS_GCC}/Packages/newlib-${NLB_RVXX_VER}"
export PACKS_GDB="${PATH_TOOLS_GCC}/Packages/gdb-${GDB_VER}"

export PATCH="${PATH_SCRIPTS}/Patches"
export BUILD="${PATH_TOOLS_GCC}/builds/gcc-${GCC_VER}"
export CROSS="${PATH_TOOLS_GCC}/cross/gcc-${GCC_VER}"

export prefix="${CROSS}/${MACHINE}"
export executables="${prefix}/bin"

build_machine="${BUILD}/${MACHINE}"
readonly LOG_FILE="${build_machine}/gnu_gcc_riscv_temp.txt"

export PATH="${executables}:${PATH}"

# Downloading sources
# -------------------

cd "${PATH_TOOLS_ROOT}/Packages/,Sources"

if [[ ! -f "binutils-${BIN_VER}.tar.bz2" ]]; then
	echo "Downloading binutils-${BIN_VER}"
	move_to_archive "binutils-*"
	"${WGET[@]}" "http://gnu.mirror.constant.com/binutils/binutils-${BIN_VER}.tar.bz2"
fi

if [[ ! -f "gdb-${GDB_VER}.tar.gz" ]]; then
	echo "Downloading gdb-${GDB_VER}"
	move_to_archive "gdb-*"
	"${WGET[@]}" "ftp://ftp.gnu.org/pub/gnu/gdb/gdb-${GDB_VER}.tar.gz"
fi

cd ..
echo "Extracting binutils sources"
tar xjf ",Sources/binutils-${BIN_VER}.tar.bz2"

echo "Extracting gdb sources"
tar xzf ",Sources/gdb-${GDB_VER}.tar.gz"

if [[ ! -d "gcc-${GCC_VER}" ]]; then
	echo "Downloading gcc-${GCC_VER}"
	git clone "git://gcc.gnu.org/git/gcc.git" "gcc-${GCC_VER}"
	git -C "gcc-${GCC_VER}" fetch --tags
	git -C "gcc-${GCC_VER}" checkout "tags/releases/gcc-${GCC_VER}"
	cd "gcc-${GCC_VER}"
	./contrib/download_prerequisites
	setopt NULL_GLOB
	for file in "${PATH_SCRIPTS}/Patches/gcc/${GCC_VER}"/*; do
		[[ -f "$file" ]] && patch -p1 -t < "$file"
	done
	unsetopt NULL_GLOB
	cd ..
fi

if [[ ! -d "newlib-${NLB_RVXX_VER}" ]]; then
	echo "Downloading newlib-${NLB_RVXX_VER}"
	git clone "https://sourceware.org/git/newlib-cygwin.git" "newlib-${NLB_RVXX_VER}"
	git -C "newlib-${NLB_RVXX_VER}" fetch --tags
	git -C "newlib-${NLB_RVXX_VER}" checkout "tags/newlib-${NLB_RVXX_VER}"
fi

# Configurations
# --------------

export BIN_CONFIG=""
GCC1_CONFIG=" \
	--disable-shared \
	--disable-nls \
	--disable-threads \
	--disable-tls \
	--enable-checking=release \
	--enable-languages=c \
	--without-cloog \
	--without-isl \
	--with-newlib \
	--without-headers \
	--with-gnu-as \
	--with-gnu-ld"
export GCC1_CONFIG
GCC2_CONFIG=" \
	--disable-shared \
	--disable-nls \
	--disable-threads \
	--disable-tls \
	--enable-checking=release \
	--enable-languages=c,c++ \
	--without-isl \
	--with-newlib \
	--with-headers=yes \
	--with-gnu-as \
	--with-gnu-ld"
export GCC2_CONFIG
export NLB_CONFIG=" \
	--enable-newlib-io-long-long \
	--enable-newlib-io-float"
export GDB_CONFIG=""

# Building the toolchain
# ----------------------

rm -rf "${build_machine}"
rm -rf "${CROSS}/${MACHINE}"
mkdir -p "${build_machine}"

echo "Start of build: $(date)" > "${LOG_FILE}"

cd "${PACKS_GCC}"

"${PATH_SCRIPTS}/_gnu_gcc_riscv_patch.sh"
if [[ ! -f "${build_machine}/gnu_gcc_riscv_patch_ready.txt" ]]; then
	echo "Failed to pass patches"
	exit 1
fi
cat "${build_machine}/gnu_gcc_riscv_patch_ready.txt" >> "${LOG_FILE}"

"${PATH_SCRIPTS}/_gnu_binutils_build.sh"
if [[ ! -f "${build_machine}/gnu_binutils_ready.txt" ]]; then
	echo "Failed to build binutils"
	exit 1
fi
cat "${build_machine}/gnu_binutils_ready.txt" >> "${LOG_FILE}"

"${PATH_SCRIPTS}/_gnu_gcc_pass1_build.sh"
if [[ ! -f "${build_machine}/gnu_gcc_pass1_ready.txt" ]]; then
	echo "Failed to complete pass 1 for gcc"
	exit 1
fi
cat "${build_machine}/gnu_gcc_pass1_ready.txt" >> "${LOG_FILE}"

"${PATH_SCRIPTS}/_newlib_riscv_build.sh"
if [[ ! -f "${build_machine}/newlib_ready.txt" ]]; then
	echo "Failed to build newlib"
	exit 1
fi
cat "${build_machine}/newlib_ready.txt" >> "${LOG_FILE}"

"${PATH_SCRIPTS}/_gnu_gcc_pass2_build.sh"
if [[ ! -f "${build_machine}/gnu_gcc_pass2_ready.txt" ]]; then
	echo "Failed to complete pass 2 for gcc"
	exit 1
fi
cat "${build_machine}/gnu_gcc_pass2_ready.txt" >> "${LOG_FILE}"

"${PATH_SCRIPTS}/_gnu_gdb_build.sh"
if [[ ! -f "${build_machine}/gnu_gdb_ready.txt" ]]; then
	echo "Failed to build gdb"
	exit 1
fi
cat "${build_machine}/gnu_gdb_ready.txt" >> "${LOG_FILE}"

# Strip the binaries

find "${CROSS}/${MACHINE}/riscv64-unknown-elf" -name "lib*.a" \
	-exec "${CROSS}/${MACHINE}/bin/riscv64-unknown-elf-strip" --strip-unneeded {} \;

# Update path links

current_dir="${PATH_TOOLS_ROOT}/cross/gcc-current"
if [[ ! -d "${current_dir}" ]]; then
	mkdir "${current_dir}"
fi
cd "${current_dir}"
rm -f "${MACHINE}"
ln -s "../gcc-${GCC_VER}/${MACHINE}" "${MACHINE}"

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${build_machine}/gnu_gcc_riscv_ready.txt"
