#!/usr/bin/env zsh

# ukos_graphviz.
# ==============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain for generating the doxygen documenting tool.
#
#			Usage:
#			./ukos_graphviz.sh
#
#			OS:
#			OSX 26.xx			yes
#			Ubuntu 26.04 LTS	yes
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

# Source the configuration file from the same directory
source "$(dirname "$0")"/config_install.sh

set -euo pipefail

# Environment
# -----------

readonly PACKS="${PATH_TOOLS_GCC}/Packages/graphviz-${GRAPHVIZ_VER}"
readonly BUILD="${PATH_TOOLS_GCC}/builds/graphviz-${GRAPHVIZ_VER}"
readonly CROSS="${PATH_TOOLS_GCC}/cross/graphviz-${GRAPHVIZ_VER}"

readonly LOG_FILE="${BUILD}/graphviz_temp.txt"

# OS detection
# ------------

readonly OS_NAME="$(uname -s)"

IS_MAC=0
IS_LINUX=0
IS_UBUNTU=0
IS_UBUNTU_2604=0

case "${OS_NAME}" in
	Darwin)
		IS_MAC=1
		;;
		Linux)
		IS_LINUX=1
		if [[ -r /etc/os-release ]]; then
			. /etc/os-release
			if [[ "${ID:-}" == "ubuntu" ]]; then
				IS_UBUNTU=1
			fi
			if [[ "${ID:-}" == "ubuntu" && "${VERSION_ID:-}" == "26.04" ]]; then
				IS_UBUNTU_2604=1
			fi
		fi
		;;
	*)
		echo "Unsupported host OS: ${OS_NAME}"
		exit 1
		;;
esac

# Optional informational warning
if [[ ${IS_LINUX} -eq 1 && ${IS_UBUNTU_2604} -ne 1 ]]; then
	echo "Warning: this Linux host is not detected as Ubuntu 26.04."
	echo "Detected: ID=${ID:-unknown}, VERSION_ID=${VERSION_ID:-unknown}"
	echo "The build may still work, but this script is tuned for Ubuntu 26.04."
fi

# Prerequisites checks
# --------------------

require_cmd() {
	command -v "$1" >/dev/null 2>&1 || {
		echo "Missing required command: $1"
		exit 1
	}
}

require_cmd git
require_cmd make
require_cmd python3

if [[ ${IS_MAC} -eq 1 ]]; then
	require_cmd pkg-config
	require_cmd autoconf
	require_cmd automake
	require_cmd libtool
elif [[ ${IS_LINUX} -eq 1 ]]; then
	require_cmd pkg-config
	require_cmd autoconf
	require_cmd automake
	require_cmd libtoolize
fi

# Best-effort dependency hints
if [[ ${IS_LINUX} -eq 1 ]]; then
	for pc in freetype2 gdk-pixbuf-2.0 gts; do
		if ! pkg-config --exists "${pc}"; then
			echo "Missing pkg-config dependency: ${pc}"
			echo "On Ubuntu 26.04, install the required -dev packages before building."
			exit 1
		fi
	done
fi

# Downloading sources
# -------------------

if [[ ! -d "${PACKS}" ]]; then
	echo "Cloning graphviz-${GRAPHVIZ_VER}"
	git clone https://gitlab.com/graphviz/graphviz.git "${PACKS}"
else
	echo "Fetching graphviz-${GRAPHVIZ_VER}"
	git -C "${PACKS}" fetch --quiet
fi

git -C "${PACKS}" checkout "${GRAPHVIZ_VER}"

chmod +x "${PACKS}/lib/common/"*.py

# Building the tool
# -----------------

rm -rf "${BUILD}"
rm -rf "${CROSS}"
mkdir -p "${BUILD}"

echo "Start of build: $(date)" > "${LOG_FILE}"

export prefix="${CROSS}"
export executables="${prefix}/bin"
PATH="${executables}:${PATH}"

# Common configure flags
typeset -a CONFIG_FLAGS
CONFIG_FLAGS=(
	--prefix="${prefix}"
	--disable-debug
	--disable-dependency-tracking
	--disable-php
	--disable-swig
	--disable-tcl
	--without-gtk
	--without-poppler
	--without-qt
	--with-freetype2
	--with-gdk-pixbuf
	--with-gts
)

# OS-specific configure flags
typeset -a MAKE_FLAGS
MAKE_FLAGS=()

if [[ ${IS_MAC} -eq 1 ]]; then
	CONFIG_FLAGS+=(
		--with-quartz
		--without-gdk
		--without-x
	)
	MAKE_FLAGS+=(
		CPPFLAGS=-I/opt/X11/include
	)
elif [[ ${IS_LINUX} -eq 1 ]]; then
	CONFIG_FLAGS+=(
		--without-x
	)
fi

cd "${PACKS}"
./autogen.sh

cd "${BUILD}"
"${PACKS}"/configure "${CONFIG_FLAGS[@]}"	|| { echo "Error configuring Graphviz"; exit 1; }
make PS2PDF=true "${MAKE_FLAGS[@]}"			|| { echo "Error building Graphviz";	exit 1; }
make PS2PDF=true pdf_DATA= install			|| { echo "Error installing Graphviz";	exit 1; }
make clean									|| { echo "Error cleaning Graphviz";	exit 1; }

# Update path links

cd "${PATH_TOOLS_GCC}/cross"
rm -f graphviz-current
ln -s "graphviz-${GRAPHVIZ_VER}" graphviz-current

echo "End of build:   $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}/graphviz_ready.txt"
