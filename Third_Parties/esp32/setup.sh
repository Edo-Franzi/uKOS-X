#!/bin/zsh

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2026-04-26
# Modifs:
#
# Project:	uKOS-X
# Goal:		Setup the esp32 environment.
#
#			usage:
#			source setup.sh
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

# Set the esp32 tool paths

IDF_PATH="${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/esp-idf-current"
IDF_TOOLS_PATH="${IDF_PATH}/espressif-tools"
IDF_PYTHON_ENV_PATH="${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/Construction/Pyenv/esp32_Pyenv"

export IDF_PATH
export IDF_TOOLS_PATH
export IDF_PYTHON_ENV_PATH

source "${IDF_PYTHON_ENV_PATH}/bin/activate"
PYTHON="${IDF_PYTHON_ENV_PATH}/bin/python"
export PYTHON

eval "$("${PYTHON}" "${IDF_PATH}/tools/idf_tools.py" export --format shell)"
export PATH="${IDF_PATH}/tools:${PATH}"

echo "Set the esp32 environment path for the project: ${PROJECT}"
