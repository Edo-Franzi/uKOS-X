#!/usr/bin/env zsh

# build.
# ======

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Build the Tflite-micro package
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
	echo 'Variable PATH_UKOS_X_PACKAGE is not set!'
	exit 1
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

readonly splash='
╔════════════════════════════════════════════════════════════╗
║           TFlite-micro Package Build System                ║
║      Fetching upstream + Building all architectures        ║
╚════════════════════════════════════════════════════════════╝
'
printf '%b%s%b' "${GREEN}" "${splash}" "${NC}"

if [[ -d 'Tflite-env/bin' ]]; then
	source 'Tflite-env/bin/activate'
fi

# Packages
# --------

readonly hash=070751f

printf '\n%bDownload the Tflite-micro package ...%b\n\n' "${BOLD}" "${NC}"

# Clone the right package
cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro"
rm -rf "${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Tflite-micro"
git clone https://github.com/tensorflow/tflite-micro Tflite-micro
cd Tflite-micro
git checkout "${hash}"

# Update path links
cd ..
rm -f Tflite-micro-current
ln -s Tflite-micro Tflite-micro-current

# Parse core.yaml file using yq
parse_core_yaml() {
	local yaml_file='../core.yaml'

	# Parse YAML: iterate through models and their cores
	yq eval 'to_entries[] | .key as $model | .value[] | "\($model)\t\(.core)\t\(.target_arch)\t\(.fpu)"' "${yaml_file}"
}

# Generate the `.h` interface files for all the cortex-M (generic, -m3, m4, -m7, -m33, -m55 -m85)
# Generate the `.h` interface files for all the risc-v (generic, rv64imafdc)
cd ./Tflite-micro-current/

python3 tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py \
	--makefile_options='TARGET=cortex_m_generic OPTIMIZED_KERNEL_DIR=cmsis_nn TARGET_ARCH=project_generation' \
	../uKOS_Interface/CORTEX_M_generic

python3 tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py \
	--makefile_options='TARGET=riscv32_generic TARGET_ARCH=project_generation' \
	../uKOS_Interface/RISCV64_generic

printf '\n%bBuilding all the Tflite-micro libraries ...%b\n' "${BOLD}" "${NC}"

# Parse YAML and iterate through all build targets
while IFS=$'\t' read -r model core target_arch fpu
do

	# Build a specific core library
	printf '\n%bBuild for the core %s ...%b\n' "${BOLD}" "${core}" "${NC}"

	if [[ ${model} == cortex_m_generic ]]; then
		make -f tensorflow/lite/micro/tools/make/Makefile \
			TARGET=cortex_m_generic TARGET_ARCH="${target_arch}" \
			OPTIMIZED_KERNEL_DIR=cmsis_nn microlite -j8 FLOAT="${fpu}" BUILD_TYPE=debug
		mkdir -p "../Library/${core}"
		cp "./gen/cortex_m_generic_${target_arch}_debug_cmsis_nn_gcc/lib/libtensorflow-microlite.a" \
			"../Library/${core}/libTFLite.a"
	fi

	if [[ ${model} == riscv32_generic ]]; then
		make -f tensorflow/lite/micro/tools/make/Makefile \
			TARGET=riscv32_generic TARGET_ARCH="${target_arch}" \
			RISCV_ARCH=rv64imafdc \
			RISCV_ABI=lp64d \
			DISABLE_PRINTF=true \
			microlite -j8 FLOAT="${fpu}" BUILD_TYPE=debug \
			CFLAGS_EXTRA='-march=rv64imafdc -mabi=lp64d' \
			CXXFLAGS_EXTRA='-march=rv64imafdc -mabi=lp64d' \
			LDFLAGS_EXTRA='-march=rv64imafdc -mabi=lp64d'
		mkdir -p "../Library/${core}"
		cp "./gen/riscv32_generic_${target_arch}_debug_gcc/lib/libtensorflow-microlite.a" \
			"../Library/${core}/libTFLite.a"
	fi
done < <(parse_core_yaml)

printf '\n🎉 %bBuild Complete%b\n\n' "${GREEN}" "${NC}"
