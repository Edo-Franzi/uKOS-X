#!/usr/bin/env zsh

# _gnu_gcc_pass1_build.
# =====================

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Build gcc (pass 1)
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

readonly build_machine="${BUILD}/${MACHINE}"
readonly log_file="${build_machine}/gnu_gcc_pass1_temp.txt"

echo "Start gcc pass 1: $(date)" > "${log_file}"

mkdir -p "${build_machine}/gcc-${GCC_VER}"
cd "${build_machine}/gcc-${GCC_VER}"

case "$(uname)" in
	"Darwin")
		CFLAGS="-O2 -fbracket-depth=1024 -pipe"
		CXXFLAGS="-O2 -fbracket-depth=1024 -pipe"
		"${PACKS_GCC}/configure" \
			--target="${TARGET}" \
			--prefix="${prefix}" \
			--with-native-system-header-dir="${CROSS}/${MACHINE}/${TARGET}/include" \
			--with-sysroot \
			--with-headers="${PACKS_NBL}/newlib/libc/include" \
			--with-system-zlib \
			--disable-werror \
			--disable-libgloss \
			--disable-libssp \
			${=GCC1_CONFIG}													|| { echo "Error configuring gcc pass 1";	exit 1; }
		make CXXFLAGS="-fbracket-depth=1024" all-gcc -j "${PARALLEL_JOBS}"	|| { echo "Error building gcc pass 1";		exit 1; }
		make install-gcc													|| { echo "Error installing gcc pass 1";	exit 1; }
		;;
	"Linux")
		"${PACKS_GCC}/configure" \
			--target="${TARGET}" \
			--prefix="${prefix}" \
			--with-native-system-header-dir="${CROSS}/${MACHINE}/${TARGET}/include" \
			--with-sysroot= \
			--with-system-zlib \
			--disable-werror \
			--disable-libgloss \
			--disable-libssp \
			${=GCC1_CONFIG}													|| { echo "Error configuring gcc pass 1";	exit 1; }
		make all-gcc -j "${PARALLEL_JOBS}"									|| { echo "Error building gcc pass 1";		exit 1; }
		make install-gcc													|| { echo "Error installing gcc pass 1";	exit 1; }
		;;
esac

echo "End gcc pass 1:   $(date)" >> "${log_file}"
mv "${log_file}" "${build_machine}/gnu_gcc_pass1_ready.txt"
