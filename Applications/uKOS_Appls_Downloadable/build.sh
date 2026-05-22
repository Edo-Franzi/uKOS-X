#!/usr/bin/env zsh

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Build all the downloadable applications (generic).
#
#			usage:
#			cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets
#			./build.sh [-C] [-L] [-U] [-Y] [-v|-w]
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

set -euo pipefail

declare -a cli_args=()
llvm_option=''
build_with_cmake=0

usage() {
	cat <<'EOF'
Usage: ./build.sh [-C] [-L] [-v|-w] [-U] [-Y]

Options:
  -C  Use CMake instead of make
  -L  Use LLVM/clang compiler
  -U  Privileged mode only
  -Y  Disable canary stack protection
  -v  Verbose: display warnings and errors
  -w  Keep error and warning messages in log file
  -h  Show this help message
EOF
}

readonly OPTSTRING=':LCUYvwh'

while getopts "${OPTSTRING}" option; do
	case "${option}" in
		h)
			usage
			exit 0
			;;
		C)
			build_with_cmake=1
			;;
		L)
			llvm_option='-L'
			;;
		U|Y|v|w)
			cli_args+=("-${option}")
			;;
		?)
			printf 'Invalid option: -%s\n' "${OPTARG}" >&2
			exit 1
			;;
	esac
done

if [[ "${build_with_cmake}" == 0 ]]; then
	if [[ "${llvm_option}" == '-L' ]]; then
		./_build_llvm.sh "${cli_args[@]:-}"
	else
		./_build_gcc.sh "${cli_args[@]:-}"
	fi
else
	./_build_cmake.sh "${llvm_option}" "${cli_args[@]:-}"
fi
