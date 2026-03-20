#!/usr/bin/env zsh

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Edo. Franzi			The 2025-01-01
# Modifs:   Laurent von Allmen	The 2025-01-01
#
# Project:	uKOS-X
# Goal:		Build all the projects using make and clang.
#
#			usage:
#           cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets
#			./_build_llvm.sh [-U] [-Y] [-v|-w]
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

# Determine script directory (works if executed via ./script.sh or bash script.sh)

readonly PATH_PRG="${0:a:h}"

if [[ -z "${PATH_LLVM_ARM}" ]]; then
	printf "Variable PATH_LLVM_ARM is not set! ARM targets will not build!\n" >&2
fi

if [[ -z "${PATH_LLVM_RVXX}" ]]; then
	printf "Variable PATH_LLVM_RVXX is not set! RISC-V targets will not build!\n" >&2
fi

# Colours for messages

readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
readonly BOLD='\033[1m'
readonly FAINT='\033[2m'
readonly ITALIC='\033[3m'
readonly NC='\033[0m' # No Color

llvm_arm_version=$(${PATH_LLVM_ARM}/bin/clang --version | awk 'NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}')
llvm_rvxx_version=$(${PATH_LLVM_RVXX}/bin/clang --version | awk 'NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}')
COMPILER_VERSIONS="arm:${llvm_arm_version} - riscv:${llvm_rvxx_version}"
make_version=$(make --version | head -1 | awk '{print $3}')
printf "%bUsing make (%s) and LLVM clang (%s)%b\n" "${YELLOW}" "${make_version}" "${COMPILER_VERSIONS}" "${NC}"

# Defaults

CANARY_MODE=""
USER_MODE=""
VERBOSITY=""

usage() {
	cat <<'EOF'
Usage: ./_build_llvm.sh [-U] [-Y] [-v|-w]

Options:
  -U  Privileged mode only
  -Y  Disable canary stack protection
  -v  Verbose: display warnings and errors
  -w  Keep error and warning messages in log file
  -h  Show this help message
EOF
}

readonly OPTSTRING=":UYvwh"

while getopts "${OPTSTRING}" option; do
	case "${option}" in
		h)
			usage
			exit 0
			;;
		U)
			USER_MODE="USER_MODE=0"
			;;
		Y)
			CANARY_MODE="CANARY=0"
			;;
		v)
			VERBOSITY="-v"
			;;
		w)
			# -v (verbose) takes precedence over -w (write log)
			if [[ "${VERBOSITY}" != "-v" ]]
			then
				VERBOSITY="-w"
			fi
			;;
		?)
			printf "Invalid option: -%s\n" "${OPTARG}" >&2
			exit 1
			;;
	esac
done

process_option()
{
	case "${VERBOSITY}" in
		"-v")
			cat ${1}
			rm -f ${1}
			;;
		"-w")
			;;
		*)
			rm -f ${1}
			;;
	esac
}

# Parse variants.yaml file using yq
parse_variants_yaml() {
	local yaml_file="${PATH_PRG}/variants.yaml"

	if ! [[ -f "${yaml_file}" ]]; then
		printf "%bError: YAML file not found: %s%b\n" "${RED}" "${yaml_file}" "${NC}" >&2
		exit 1
	fi

	if ! command -v yq >/dev/null 2>&1; then
		printf "%bError: yq is not installed%b\n" "${RED}" "${NC}" >&2
		exit 1
	fi

	# Parse YAML: iterate through families and their variants
	yq eval 'to_entries[] | .key as $family | .value[] | "\($family)\t\(.name)"' "${yaml_file}"
}

build_failure=""
build_success=""
readonly LOG_FILE="compilation.log"
PREFIX_VAR=(PREFIX=llvm- COMPILER_FAMILY=llvm)

printf "%bBuilding all the systems with '%s make %s %s'%b\n" "${BOLD}" "${PREFIX_VAR[*]}" "${USER_MODE}" "${CANARY_MODE}" "${NC}"
# Parse YAML and iterate through all build targets
while IFS=$'\t' read -r family variant_name; do
	CURRENT_VARIANT="${family}/Variant_${variant_name}"
	printf "%-40s " "${CURRENT_VARIANT}"
	cd "${PATH_PRG}"/"${CURRENT_VARIANT}"/System

# Normal output on the stdout, error/warnings on comp.log
# If comp.log empty		-> "PASS"
# If comp.log not empty -> "WARNING"
# If make error			-> "FAIL"

	was_error=0
	make -j "${PREFIX_VAR[@]}" "${USER_MODE}" "${CANARY_MODE}" >/dev/null 2>"${LOG_FILE}" || was_error=1
	if (( was_error == 0 )); then
		build_success+=$'\n'"${CURRENT_VARIANT}"
		# Check if the file is empty
		if [ ! -s "${LOG_FILE}" ]; then
			printf "%bPASS%b\n" "${GREEN}" "${NC}"
			rm -f "${LOG_FILE}"
		else
			printf "%bWARNING%b\n" "${YELLOW}" "${NC}"
			process_option "${LOG_FILE}"
		fi
	else
		build_failure+=$'\n'"${CURRENT_VARIANT}"
		printf "%bFAIL%b\n" "${RED}" "${NC}"
		process_option "${LOG_FILE}"
	fi
done < <(parse_variants_yaml)

# Display the target list that have failed

if [[ -n "${build_failure}" ]]; then
	printf "%bFailed builds:%b%s\n" "${RED}" "${NC}" "${build_failure}"
fi
printf "%bTerminated!%b\n" "${BOLD}" "${NC}"
