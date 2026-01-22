#!/usr/bin/env zsh

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Building all the uKOS downloadable applications using make and gcc.
#
#			usage:
#			cd ${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Appls_Downloadable
#			./_build_gcc.sh [-U] [-Y] [-v|-w]
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

# Determine script directory (works if executed via ./script.sh or bash script.sh)

readonly PATH_PRG="${0:a:h}"

if [[ -z "${PATH_GCC_ARM:-}" ]]; then
	printf 'Variable PATH_GCC_ARM is not set! ARM targets will not build!\n' >&2
fi

if [[ -z "${PATH_GCC_RVXX:-}" ]]; then
	printf 'Variable PATH_GCC_RVXX is not set! RISC-V targets will not build!\n' >&2
fi

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

gcc_arm_version=$("${PATH_GCC_ARM}/bin/arm-none-eabi-gcc" --version | awk 'NR==1{print $3; exit}')
gcc_rvxx_version=$("${PATH_GCC_RVXX}/bin/riscv64-unknown-elf-gcc" --version | awk 'NR==1{print $3; exit}')
COMPILER_VERSIONS="arm:${gcc_arm_version} - riscv:${gcc_rvxx_version}"
make_version=$(make --version | head -1 | awk '{print $3}')
printf '%bUsing make (%s) and gcc (%s)%b\n' "${YELLOW}" "${make_version}" "${COMPILER_VERSIONS}" "${NC}"

# Defaults

CANARY_MODE=''
USER_MODE=''
VERBOSITY=''

usage() {
	cat <<'EOF'
Usage: ./_build_gcc.sh [-U] [-Y] [-v|-w]

Options:
  -U  Privileged mode only
  -Y  Disable canary stack protection
  -v  Verbose: display warnings and errors
  -w  Keep error and warning messages in log file
  -h  Show this help message
EOF
}

readonly OPTSTRING=':UYvwh'

while getopts "${OPTSTRING}" option; do
	case "${option}" in
		h)
			usage
			exit 0
			;;
		U)
			USER_MODE='USER_MODE=0'
			;;
		Y)
			CANARY_MODE='CANARY=0'
			;;
		v)
			VERBOSITY='-v'
			;;
		w)
			# -v (verbose) takes precedence over -w (write log)
			if [[ "${VERBOSITY}" != '-v' ]]
			then
				VERBOSITY='-w'
			fi
			;;
		?)
			printf 'Invalid option: -%s\n' "${OPTARG}" >&2
			exit 1
			;;
	esac
done

process_option() {
	case "${VERBOSITY}" in
		'-v')
			cat "${1}"
			rm -f "${1}"
			;;
		'-w')
			;;
		*)
			rm -f "${1}"
			;;
	esac
}

# Parse apps.yaml file using yq
parse_apps_yaml() {
	local yaml_file="${PATH_PRG}/apps.yaml"

	# Parse YAML: iterate through families, projects, and targets
	yq eval 'to_entries[] | .key as $family | .value | to_entries[] | .key as $project | .value[] | "\($family)/\($project)/\(.)"' "${yaml_file}"
}

build_failure=''
build_warning=''
build_success=''
readonly LOG_FILE='compilation.log'

printf "%bBuilding all the downloadable applications with 'make %s %s'%b\n" "${BOLD}" "${USER_MODE}" "${CANARY_MODE}" "${NC}"
while IFS= read -r CURRENT_TARGET
do
	printf '%s ' "${CURRENT_TARGET}"
	cd "${PATH_PRG}/${CURRENT_TARGET}"
	make clean_all >/dev/null;

# Normal output on the stdout, error/warnings on comp.log
# If comp.log empty		-> "PASS"
# If comp.log not empty -> "WARNING"
# If make error			-> "FAIL"

	if make -j ${CANARY_MODE} ${USER_MODE} >/dev/null 2>"${LOG_FILE}"; then
		if [[ ! -s "comp.log" ]]; then
			build_success+=$'\n'"${CURRENT_TARGET}"
			printf '%bPASS%b\n' "${GREEN}" "${NC}"
			rm -f "${LOG_FILE}"
		else
			build_warning+=$'\n'"${CURRENT_TARGET}"
			printf '%bWARNING%b\n' "${YELLOW}" "${NC}"
			process_option "${LOG_FILE}"
		fi
	else
		build_failure+=$'\n'"${CURRENT_TARGET}"
		printf '%bFAIL%b\n' "${RED}" "${NC}"
		process_option "${LOG_FILE}"
	fi
done < <(parse_apps_yaml)

# Display the target list that with warnings

if [[ -n "${build_warning}" ]]; then
	printf '%bBuild with warning:%b%s\n' "${YELLOW}" "${NC}" "${build_warning}"
fi

# Display the target list that have failed

if [[ -n "${build_failure}" ]]; then
	printf '%bFailed builds:%b%s\n' "${RED}" "${NC}" "${build_failure}"
fi
printf '%bTerminated!%b\n' "${BOLD}" "${NC}"
