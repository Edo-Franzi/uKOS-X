#!/usr/bin/env zsh

# _newlib_riscv_build.
# ====================

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Build the newlib (specific RVXX)
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
readonly log_file="${build_machine}/newlib_temp.txt"

echo "Start building newlib: $(date)" > "${log_file}"

mkdir -p "${build_machine}/newlib-${NLB_RVXX_VER}"
cd "${build_machine}/newlib-${NLB_RVXX_VER}"

"${PACKS_NBL}/configure" \
	--target="${TARGET}" \
	--prefix="${prefix}" \
	--enable-multilib \
	--disable-werror \
	--disable-nls \
	--disable-libssp \
	${=NLB_CONFIG}			|| { echo "Error configuring newlib";	exit 1; }
make -j "${PARALLEL_JOBS}"	|| { echo "Error building newlib";		exit 1; }
make install				|| { echo "Error installing newlib";	exit 1; }
make clean					|| { echo "Error cleaning newlib";		exit 1; }

echo "End building newlib:   $(date)" >> "${log_file}"
mv "${log_file}" "${build_machine}/newlib_ready.txt"
