#!/usr/bin/env zsh

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Cleaning all the uKOS downloadable applications.
#
#			usage:
#			./clean.sh
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

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

# Parse apps.yaml file using yq
parse_apps_yaml() {
	local yaml_file="${PATH_PRG}/apps.yaml"

	# Parse YAML: iterate through families, projects, and targets
	yq eval 'to_entries[] | .key as $family | .value | to_entries[] | .key as $project | .value[] | "\($family)/\($project)/\(.)"' "${yaml_file}"
}

readonly LOG_FILE='compilation.log'

printf '%bCleaning all the downloadable applications ...%b\n' "${BOLD}" "${NC}"
while IFS= read -r CURRENT_TARGET
do
	printf '.'
	cd "${PATH_PRG}/${CURRENT_TARGET}"
	make --silent clean_all
	rm -f "${LOG_FILE}"
	rm -fr build
done < <(parse_apps_yaml)
printf '\n%bTerminated!%b\n' "${BOLD}" "${NC}"
