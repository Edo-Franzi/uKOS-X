#!/usr/bin/env zsh

# build.
# ======

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2026-04-26
# Modifs:
#
# Project:	uKOS-X
# Goal:		Build the esp-idf & AT firmware package
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

readonly PYTHON=python3

if ! command -v "${PYTHON}" >/dev/null 2>&1; then
	echo "Python not found: ${PYTHON}"
	exit 1
fi

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
║        esp-idf & AT firmware Package Build System          ║
║      Fetching upstream + Building all architectures        ║
╚════════════════════════════════════════════════════════════╝
'
printf '%b%s%b' "${GREEN}" "${splash}" "${NC}"

# Packages
# --------

readonly package="6.0.1"
readonly idf_tag="v${package}"
readonly URL="https://dl.espressif.com/esp-at/firmwares/esp32/ESP32-WROOM-32/ESP32-WROOM-32-AT-V4.1.1.0.zip"
readonly ARCHIVE="ESP32-WROOM-32-AT-V4.1.1.0"

IDF_PATH="${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/esp-idf-current"
IDF_TOOLS_PATH="${IDF_PATH}/espressif-tools"
IDF_PYTHON_ENV_PATH="${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/Construction/Pyenv/esp32_Pyenv"

export IDF_PATH
export IDF_TOOLS_PATH
export IDF_PYTHON_ENV_PATH

# Clone the right packages

printf '\n%bDownload the esp-idf package ...%b\n\n' "${BOLD}" "${NC}"

cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32"
rm -rf "esp-idf-${package}"
git clone https://github.com/espressif/esp-idf.git "esp-idf-${package}"
cd "esp-idf-${package}"
git checkout "${idf_tag}"
git submodule update --init --recursive

# Update path links

cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32"
rm -f esp-idf-current
ln -s "esp-idf-${package}" esp-idf-current

# Ignore tools in git

touch "${IDF_PATH}/.git/info/exclude"
grep -qxF "espressif-tools/" "${IDF_PATH}/.git/info/exclude" || echo "espressif-tools/" >> "${IDF_PATH}/.git/info/exclude"

# Install ESP-IDF tools

printf '\n%bInstall ESP-IDF tools...%b\n\n' "${BOLD}" "${NC}"

mkdir -p "${IDF_TOOLS_PATH}"
mkdir -p "$(dirname "${IDF_PYTHON_ENV_PATH}")"
"${PYTHON}" "${IDF_PATH}/tools/idf_tools.py" install --targets=esp32,esp32s3
rm -rf "${IDF_PYTHON_ENV_PATH}"
mkdir -p "${IDF_PYTHON_ENV_PATH}"
"${PYTHON}" "${IDF_PATH}/tools/idf_tools.py" install-python-env

# Download AT firmware

printf '\n%bDownload the AT firmware package ...%b\n\n' "${BOLD}" "${NC}"

cd esp-idf-current
mkdir -p AT_firmware

rm -f "$ARCHIVE.zip"
rm -rf "$ARCHIVE"
wget -O "$ARCHIVE.zip" "$URL"
unzip "$ARCHIVE.zip"

cd "$ARCHIVE"
rm -rf "../AT_firmware/${ARCHIVE}"
mv "$ARCHIVE" ../AT_firmware
cd "${IDF_PATH}"
rm "$ARCHIVE.zip"
rm -rf "$ARCHIVE"

printf '\n🎉 %bBuild Complete%b\n\n' "${GREEN}" "${NC}"
