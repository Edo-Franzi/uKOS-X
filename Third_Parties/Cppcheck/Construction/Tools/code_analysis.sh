#!/usr/bin/env zsh

# code_analysis.
# ==============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-10-02
# Modifs:
#
# Project:	uKOS-X
# Goal:		Helper tool for Cppcheck static code analysis.
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

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB

# Determine script directory (works if executed via ./script.sh or zsh script.sh)

readonly PATH_PRG=${0:a:h}

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

declare -a premium_options

while getopts ":chP" option; do
	case ${option} in
		h)
			echo 'USAGE: code_analysis.sh [-c]'
			echo
			echo 'OPTIONS:'
			echo '    -c: clear previous results'
			echo '    -P: Cppcheck Premium'
			exit 0
			;;
		c)
			rm -fr Static_Analysis
			;;
		P)
			premium_options=(
				--premium=cert-cpp-2016
				--premium=misra-c-2023
				--premium=safety-off
			)
			;;
		?)
			echo "Invalid option: -${OPTARG}"
			exit 1
			;;
	esac
done

# check that Cppcheck's applications are available

if ! ( command -v cppcheck &> /dev/null || command -v cppcheck-htmlreport &> /dev/null )
then
	printf '%bCppcheck is not in your path%b\n' "${RED}" "${NC}"
	exit 1
fi

printf '%bBuilding list of files to check%b\n' "${YELLOW}" "${NC}"
mkdir -p Static_Analysis
cd Static_Analysis
cmake -S .. -B build --preset llvm -DCMAKE_EXPORT_COMPILE_COMMANDS=ON &> /dev/null

printf '%bRunning Cppcheck%b\n' "${YELLOW}" "${NC}"
mkdir -p Cppcheck-build

# Possible checks
# --premium=cert-cpp-2016
# --premium=bughunting
# --premium=misra-c-2025

cppcheck \
	-D__GNUC__ \
	-UEXCLUDE_CPPCHECK \
	--max-configs=1 \
	--suppressions-list="${PATH_UKOS_X_PACKAGE}/Third_Parties/Cppcheck/Construction/Rules/uKOS_misra_rules.suppress" -rp="${PATH_UKOS_X_PACKAGE}/Third_Parties/Cppcheck/Construction/Rules" \
	--suppress=asctimeCalled \
	--suppress=missingIncludeSystem \
	--suppress=variableScope \
	--suppress=unknownMacro \
	--suppress=unknownSymbol \
	--suppress=unusedFunction \
	--suppress=knownConditionTrueFalse \
	--suppress=badBitmaskCheck \
	--suppress=duplicateBreak \
	--suppress=premium-misra-config \
	--suppress=unmatchedSuppression \
	--suppress='*:*/Third_Parties/TinyUSB/*' \
	--suppress='*:*/Third_Parties/MicroPython/*' \
	--suppress='*:*/Third_Parties/FatFs/*' \
	--suppress='*:*/Third_Parties/LVGL/*' \
	--suppress='*:*/Third_Parties/Tflite-micro/*' \
	"${premium_options[@]}" \
	-I"${PATH_UKOS_X_PACKAGE}"/OS/Includes \
	--enable=all --inconclusive \
	--enable=style \
	--project=build/compile_commands.json \
	-iFLASH.sig.c \
	--cppcheck-build-dir=Cppcheck-build \
	--inline-suppr \
	--check-level=exhaustive \
	--quiet \
	--xml \
	--output-file=ukos-analysis.xml

if [[ -d "${PATH_PRG}/Construction/Pyenv/Cppcheck_Pyenv" ]]
then
	source "${PATH_PRG}/Construction/Pyenv/Cppcheck_Pyenv/bin/activate"
fi
cppcheck-htmlreport --file=ukos-analysis.xml --report-dir=html &> /dev/null
if [[ -d "${PATH_PRG}/Construction/Pyenv/Cppcheck_Pyenv" ]]
then
	deactivate
fi

if [ -f html/index.html ]
then
	case "$(uname)" in
		'Darwin')
			open html/index.html
			;;
		'Linux')
			printf '%bopen Static_Analysis/html/index.html in your browswer.%b\n' "${BOLD}" "${NC}"
			;;
	esac
else
	printf '%bNo error reported.%b\n' "${GREEN}" "${NC}"
fi
