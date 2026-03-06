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
#			Ubuntu 24.04 LTS	yes
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

readonly PACKS="${PATH_TOOLS_GCC}"/Packages/graphviz-"${GRAPHVIZ_VER}"
readonly BUILD="${PATH_TOOLS_GCC}"/builds/graphviz-"${GRAPHVIZ_VER}"
readonly CROSS="${PATH_TOOLS_GCC}"/cross/graphviz-"${GRAPHVIZ_VER}"

readonly LOG_FILE="${BUILD}"/graphviz_temp.txt

# Downloading sources
# -------------------

if [[ ! -d "${PACKS}" ]]; then
	echo Cloning graphviz-${GRAPHVIZ_VER}
	git clone https://gitlab.com/graphviz/graphviz.git "${PACKS}"
else
	echo Fetching graphviz-${GRAPHVIZ_VER}
	git -C "${PACKS}" fetch --quiet
fi
git -C "${PACKS}" checkout ${GRAPHVIZ_VER}

chmod +x "${PACKS}/lib/common/"*.py

# Building the tool
# -----------------

rm -rf "${BUILD}"
rm -rf "${CROSS}"
mkdir -p "${BUILD}"

echo "Start of build: $(date)" > "${LOG_FILE}"

export prefix="${CROSS}"
export executables="${prefix}"/bin

PATH="${executables}":"${PATH}"

cd "${PACKS}"
./autogen.sh
cd "${BUILD}"
"${PACKS}"/configure --prefix="${prefix}" \
	--disable-debug \
	--disable-dependency-tracking \
	--disable-php \
	--disable-swig \
	--disable-tcl \
	--with-quartz \
	--without-gdk \
	--without-gtk \
	--without-poppler \
	--without-qt \
	--without-x \
	--with-freetype2 \
	--with-gdk-pixbuf \
	--with-gts						|| { echo "Error configuring Graphviz"; exit 1; }
make CPPFLAGS=-I/opt/X11/include	|| { echo "Error building Graphviz";	exit 1; }
make install						|| { echo "Error installing Graphviz";	exit 1; }
make clean							|| { echo "Error cleaning Graphviz";	exit 1; }

# Update path links

cd "${PATH_TOOLS_GCC}"/cross
rm -f graphviz-current
ln -s graphviz-"${GRAPHVIZ_VER}" graphviz-current

echo "End of build:	  $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${BUILD}"/graphviz_ready.txt
