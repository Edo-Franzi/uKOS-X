#!/usr/bin/env zsh

# ukos_clang_llvm_riscv_elf.
# ==========================

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Laurent von Allmen  The  2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating LLVM clang cross compilers
#			for Unix like machines
#
#			Usage:
#			./ukos_clang_llvm_riscv_elf.sh
#
#			OS:
#			OSX 26.xx			yes
#			Ubuntu 26.04 LTS	yes
#
#   (c) 2025-2026, Laurent von Allmen
#   ---------------------------------
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

export CC=clang
export CXX=clang++

readonly PACKS_LLVM="${PATH_TOOLS_ROOT}"/Packages/llvm-"${LLVM_RVXX_VER}"/riscv

# Environment
# -----------

# Allow environment to control parallelism

if [[ "x${PARALLEL_JOBS:-}" == "x" ]]; then
	PARALLEL_JOBS=6
fi

readonly BUILD="${PATH_TOOLS_ROOT}"/builds/llvm-"${LLVM_RVXX_VER}"/riscv
readonly CROSS="${PATH_TOOLS_ROOT}"/cross/llvm-"${LLVM_RVXX_VER}"/riscv
readonly LOG_FILE="${BUILD}"/clang_llvm_riscv_temp.txt

# Downloading sources
# -------------------

cd "${PATH_TOOLS_ROOT}"/Packages

if [[ ! -d llvm-"${LLVM_RVXX_VER}"/riscv ]]; then
	echo "Downloading LLVM-${LLVM_RVXX_VER} for RISC-V"
	git clone https://github.com/Laur59/RTfE.git "llvm-${LLVM_RVXX_VER}/riscv"
	git -C llvm-"${LLVM_RVXX_VER}"/riscv checkout ${LLVM_RVXX_COMMIT}
fi

# Building the toolchain
# ----------------------

rm -rf "${BUILD}"
mkdir -p "${BUILD}"
rm -rf "${CROSS}"
mkdir -p "${CROSS}"

echo "Start of build: $(date)" > "${LOG_FILE}"

cmake -S "${PACKS_LLVM}"/riscv-software/embedded -B "${BUILD}" -GNinja \
	-DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_INSTALL_PREFIX="${CROSS}" -Wno-dev
cmake --build "${BUILD}" --parallel ${PARALLEL_JOBS} --target llvm-toolchain 2>/dev/null
ninja -C "${BUILD}" install-llvm-toolchain

# Remove debug info from libraries
echo "$(date)	Start stripping libraries" >> "${LOG_FILE}"
find "${CROSS}"/lib/clang-runtimes/ -name "lib*.a" -exec "${CROSS}"/bin/llvm-strip --strip-unneeded "{}" +
echo "$(date)	End stripping libraries" >> "${LOG_FILE}"

# Update path links

current_dir="${PATH_TOOLS_ROOT}"/cross/llvm-current
if [[ ! -d "${current_dir}" ]]; then
	mkdir "${current_dir}"
fi
cd "${current_dir}"
rm -f riscv
ln -s ../llvm-"${LLVM_RVXX_VER}"/riscv riscv

echo "End of build:	  $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${CROSS}"/clang_llvm_riscv_ready"$(date -I)".txt
rm -fr "${BUILD}"
