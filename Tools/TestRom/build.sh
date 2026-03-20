#!/usr/bin/env zsh

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Building all the uKOS TestRom.
#
#			usage:
#			./build.sh
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

set -euo pipefail
setopt KSH_ARRAYS  # Use 0-indexed arrays like bash

if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
	echo "Variable PATH_UKOS_X_PACKAGE is not set!"
	exit 1
fi

if [[ -z "${PATH_TOOLS_UNIX:-}" ]]; then
	echo "Variable PATH_TOOLS_UNIX is not set!"
	exit 1
fi

if [[ -z "${PATH_GCC_ARM:-}" ]]; then
	echo "Variable PATH_GCC_ARM is not set! arm targets will not build!"
	sleep 4
fi

if [[ -z "${PATH_GCC_RVXX:-}" ]]; then
	echo "Variable PATH_GCC_RVXX is not set! RISC-V targets will not build!"
	sleep 4
fi

PATH_PRG="${PATH_UKOS_X_PACKAGE}/Tools/TestRom"

THE_OPTION=""
if [ $# = 1 ]; then
	THE_OPTION="${1}"; shift
fi

process_option() {
	case "${THE_OPTION}" in
		"-v")
			cat comp.log
			rm -f comp.log
			;;
		"-w")
			;;
		*)
			rm -f comp.log
			;;
	esac
}

# Parse apps.yaml file using yq
parse_apps_yaml() {
	local yaml_file="${PATH_PRG}/apps.yaml"

	# Parse YAML: iterate through targets
	yq eval '.targets[]' "${yaml_file}"
}

build_failure=""
build_success=""

print -P "%BBuilding all ...%b"

# Parse YAML and iterate through all targets
while read -r CURRENT_TARGET; do
	printf '%-40s' "${CURRENT_TARGET}"

	cd "${PATH_PRG}/${CURRENT_TARGET}"
	make --silent clean_all

	if make -j >/dev/null 2>comp.log; then
		build_success="${build_success}\n${CURRENT_TARGET}"
		if [[ ! -s "comp.log" ]]; then
			print -P "%F{green} PASS%f"
			rm -f comp.log
		else
			print -P "%F{yellow} WARNING%f"
			process_option
		fi
	else
		build_failure="${build_failure}\n${CURRENT_TARGET}"
		print -P "%F{red} FAIL%f"
		process_option
	fi
	make --silent clean
done < <(parse_apps_yaml)

# Display the target list that have failed

if [[ -n "$build_failure" ]]; then
	print -P "\nFailed build:%F{red}$build_failure%f"
fi
print -P "%BTerminated!%b"
