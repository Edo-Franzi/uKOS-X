#!/usr/bin/env zsh

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Edo. Franzi			The 2025-01-01
# Modifs:   Laurent von Allmen	The 2025-01-01
#
# Project:	uKOS-X
# Goal:		Build all the projects.
#
#			usage: sourced by build.sh
#           cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets
#			./_build_cmake.sh [-L] [-U] [-Y] [-v|-w]
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

# Determine script directory (works if executed via ./script.sh or zsh script.sh)

readonly PATH_PRG="${0:a:h}"

# set up options

GENERATEUR="Unix Makefiles"

# Colours for messages

readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
readonly BOLD='\033[1m'
readonly FAINT='\033[2m'
readonly ITALIC='\033[3m'
readonly NC='\033[0m' # No Color

# Defaults

COMPILER_TOOL="gcc"
VERBOSITY=""
CANARY_MODE="ON"
USER_MODE="ON"

usage() {
	cat <<'EOF'
Usage: ./_build_cmake.sh [-L] [-U] [-Y] [-v|-w]

Options:
  -L  Use LLVM/clang compiler
  -U  Privileged mode only
  -Y  Disable canary stack protection
  -v  Verbose: display warnings and errors
  -w  Keep error and warning messages in log file
  -h  Show this help message
EOF
}

readonly OPTSTRING=":LUYvwh"

while getopts "${OPTSTRING}" option; do
	case "${option}" in
		h)
			usage
			exit 0
			;;
		L)
			COMPILER_TOOL="LLVM clang"
			;;
		U)
			USER_MODE="OFF"
			;;
		Y)
			CANARY_MODE="OFF"
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

get_cmake_preset() {
	local compiler="$1"
	local user_mode="$2"
	local canary_mode="$3"
	local preset="${compiler}"

	if [ "$user_mode" = "OFF" ]; then
		preset="${preset}-nouser"
		if [ "$canary_mode" = "OFF" ]; then
			preset="${preset}-nocanary"
		fi
	else
		# user_mode = ON
		if [ "$canary_mode" = "OFF" ]; then
			preset="${preset}-nocanary"
		fi
		# When user_mode=ON and canary_mode=ON, preset stays as just "${compiler}"
	fi

	echo "$preset"
}

case ${COMPILER_TOOL} in
	"gcc")
		if [[ -z "${PATH_GCC_ARM}" ]]; then
			if ! command -v arm-none-eabi-gcc >/dev/null 2>&1; then
				printf "Variable PATH_GCC_ARM is not set! arm targets will not build!\n" >&2
			fi
		fi
		if [[ -z "${PATH_GCC_RVXX}" ]]; then
			if ! command -v riscv64-unknown-elf-gcc >/dev/null 2>&1; then
				printf "Variable PATH_GCC_RVXX is not set! RISC-V targets will not build!\n" >&2
			fi
		fi
		gcc_arm_version=$(${PATH_GCC_ARM}/bin/arm-none-eabi-gcc --version | awk 'NR==1{print $3; exit}')
		gcc_rvxx_version=$(${PATH_GCC_RVXX}/bin/riscv64-unknown-elf-gcc --version | awk 'NR==1{print $3; exit}')
		COMPILER_VERSIONS="arm:${gcc_arm_version} - riscv:${gcc_rvxx_version}"
		CMAKE_PRESET=$(get_cmake_preset "gcc" "${USER_MODE}" "${CANARY_MODE}")
		;;
	"LLVM clang")
		if [[ -z "${PATH_LLVM_ARM}" ]]; then
			printf "Variable PATH_LLVM_ARM is not set! arm targets will not build!\n" >&2
		fi
		if [[ -z "${PATH_LLVM_RVXX}" ]]; then
			printf "Variable PATH_LLVM_RVXX is not set! RISC-V targets will not build!\n" >&2
		fi
		llvm_arm_version=$(${PATH_LLVM_ARM}/bin/clang --version | awk 'NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}')
		llvm_rvxx_version=$(${PATH_LLVM_RVXX}/bin/clang --version | awk 'NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}')
		COMPILER_VERSIONS="arm:${llvm_arm_version} - riscv:${llvm_rvxx_version}"
		CMAKE_PRESET=$(get_cmake_preset "llvm" "${USER_MODE}" "${CANARY_MODE}")
		;;
esac

cmake_version=$(cmake --version | awk 'NR==1{print $3; exit}')
printf "%bUsing cmake (%s) and %s (%s)%b\n" "${YELLOW}" "${cmake_version}" "$COMPILER_TOOL" "${COMPILER_VERSIONS}" "${NC}"

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
readonly LOG_FILE="build/compilation.log"

printf "%bBuilding all the systems with --preset %s%b (USER_MODE=%s CANARY=%s)\n" "${BOLD}" "${CMAKE_PRESET}" "${NC}" "${USER_MODE}" "${CANARY_MODE})"
# Parse YAML and iterate through all build targets
while IFS=$'\t' read -r family variant_name; do
	CURRENT_VARIANT="${family}/Variant_${variant_name}"
	printf "%-40s " "${CURRENT_VARIANT}"
	cd "${PATH_PRG}/${CURRENT_VARIANT}"

# Normal output on the stdout, error/warnings on comp.log
# If comp.log empty		-> "PASS"
# If comp.log not empty -> "WARNING"
# If make error			-> "FAIL"

	was_error=0
	rm -fr build
	cmake -G "${GENERATEUR}" --preset "${CMAKE_PRESET}" >/dev/null && \
	cmake --build build --parallel >/dev/null 2>"${LOG_FILE}" || was_error=1
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
