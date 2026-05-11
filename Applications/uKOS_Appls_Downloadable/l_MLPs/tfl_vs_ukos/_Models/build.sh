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
# Goal:		Create the mlpn model
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

TFLITE_PYENV="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv/Tflite_Pyenv"
MLPN_CONVERTER="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Tools/tflite_structure"

if [[ -d "${TFLITE_PYENV:-}" ]]; then
    source "${TFLITE_PYENV}/bin/activate"
fi

MODEL_FILE="mlp_model.tflite"

xxd -i "${MODEL_FILE}" > mlp_model.c_inc

# Now generate the uKOS-X mlpn model

python3 "${MLPN_CONVERTER}/tflite_structure.py" "${MODEL_FILE}" -o structure.c


