#!/usr/bin/env zsh

# build.
# ======

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Generate the code from the TF model to the NPU
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

if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
	echo "Variable PATH_UKOS_X_PACKAGE is not set!"
	exit 1
fi

SCRIPT_DIR="${0:A:h}"

readonly NETWORK="gan"
readonly MODEL="NN_model"
readonly DST_WEIGHTS="NN_weight"
readonly SRC_WEIGHTS="stedgeai-output/network_atonbuf.xSPI2"

readonly TFLITE_PYENV="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv/Tflite_Pyenv"
readonly PROFILE="${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Library/AI/${NETWORK}/mapping/mapping.json"
readonly MPOOL="${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Library/AI/${NETWORK}/mapping/mapping.mpool"
readonly OUTPUT="${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Library/AI/${NETWORK}/stedgeai-output"
readonly STM32_NEURAL_ART="${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/STEdgeAI/4.0/Utilities/macarm"

if [[ -d "${TFLITE_PYENV}" ]]; then
	source "${TFLITE_PYENV}/bin/activate"
fi

if [[ ! -f "${MODEL}.xxd" ]]; then
	echo "Model not found: ${MODEL}.xxd"
	exit 1
fi

if [[ ! -f "${PROFILE}" ]]; then
	echo "Neural-ART profile not found: ${PROFILE}"
	exit 1
fi

if [[ ! -f "${MPOOL}" ]]; then
	echo "Neural-ART memory pool not found: ${MPOOL}"
	exit 1
fi

rm -rf "${OUTPUT}"
mkdir -p "${OUTPUT}"

xxd -r "${MODEL}.xxd" > "${MODEL}.tflite"
${STM32_NEURAL_ART}/stedgeai generate --model "${MODEL}.tflite" --target stm32n6 --st-neural-art "default@${PROFILE}" --output "${OUTPUT}"

make

# Copy the weight set

cp "${SRC_WEIGHTS}.raw" "${DST_WEIGHTS}.bin"

rm -rf st_ai_ws
rm -rf stedgeai-output
rm -rf "${MODEL}.tflite"

