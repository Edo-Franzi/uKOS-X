#!/usr/bin/env zsh

# build.
# ======

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Build the TinyUSB package
#
#   (c) 2025-20xx, Edo. Franzi
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

# Colours for messages

readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
readonly BOLD='\033[1m'
readonly FAINT='\033[2m'
readonly ITALIC='\033[3m'
readonly NC='\033[0m' # No Color

readonly splash="
╔════════════════════════════════════════════════════════════╗
║               TinyUSB Package Build System                 ║
║      Fetching upstream + Building all architectures        ║
╚════════════════════════════════════════════════════════════╝
"
printf '%b%s%b' "${GREEN}" "$splash" "${NC}"

# Packages
# --------

readonly package=0.20.0
readonly hash=77fcf62

export PATH="${PATH_GCC_ARM}/bin":"${PATH}"
printf '%b%s%b\n' "${YELLOW}" "$(arm-none-eabi-gcc --version)" "${NC}"

# Clone the right package

printf '\n%bDownload the TinyUSB package ...%b\n\n' "${BOLD}" "${NC}"

cd "${PATH_UKOS_X_PACKAGE}"/Third_Parties/TinyUSB
rm -rf "${PATH_UKOS_X_PACKAGE}"/Third_Parties/TinyUSB/TinyUSB-"${package}"
git clone https://github.com/hathach/tinyusb TinyUSB-"${package}"
cd TinyUSB-"${package}"
git submodule update --init lib
git checkout "${hash}"

# Update path links

cd ..
rm -f TinyUSB-current
ln -s TinyUSB-"${package}" TinyUSB-current

# Clone the pico-sdk package

printf '\n%bDownload the pico-sdk package ...%b\n\n' "${BOLD}" "${NC}"

cd TinyUSB-"${package}"/lib
git clone https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init --recursive

cd ../../..

# Parse core.yaml file using yq
parse_core_yaml() {
	local yaml_file="core.yaml"

	# Parse YAML: iterate through families, SOCs, and profiles
	# Output format: family \t dependency \t soc \t profile
	yq eval 'to_entries[] | .key as $family | .value[] | .dependency as $dep | .soc as $soc | .profiles[] | "\($family)\t\($dep)\t\($soc)\t\(.)"' "${yaml_file}"
}

printf '\n%bBuilding all the TinyUSB libraries ...%b\n' "${BOLD}" "${NC}"

# Track the current SOC to avoid running get-deps multiple times for the same SOC
prev_soc=""

# Parse YAML and iterate through all build targets
while IFS=$'\t' read -r family dependency soc profile; do

	# Load the dependencies (run get-deps only once per SOC)
	if [[ "${soc}" != "${prev_soc}" ]]; then
		if [[ "${dependency}" != "null" ]]; then
			cd "${PATH_UKOS_X_PACKAGE}"/Third_Parties/TinyUSB/TinyUSB-current/examples/device/cdc_dual_ports
			make BOARD="${dependency}" get-deps
		fi
		prev_soc="${soc}"
	fi

	# Build a specific profile library
	printf '\n%bBuild for the soc %s profile %s ...%b\n' "${BOLD}" "${soc}" "${profile}" "${NC}"

	cd "${PATH_UKOS_X_PACKAGE}"/Third_Parties/TinyUSB
	CURRENT_PROFILE=Library/Family/"${family}"/"${soc}"/"${profile}"

	cd "${CURRENT_PROFILE}"
	echo "Start of building: $(date)" > libTinyUSB_temp.log
	make -j all
	echo "End of building: $(date)" >> libTinyUSB_temp.log
	mv libTinyUSB_temp.log libTinyUSB_ready.txt
done < <(parse_core_yaml)

printf '\n🎉 %bBuild Complete%b\n\n' "${GREEN}" "${NC}"
