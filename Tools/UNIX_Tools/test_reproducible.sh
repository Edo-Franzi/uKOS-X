#!/usr/bin/env zsh

# test_reproducible.
# ==================

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-12-19
# Modifs:
#
# Project:	uKOS-X
# Goal:		Compare binaries generated with CMake with those from make
#
#			Usage:
#				alias reproducibility='$PATH_UKOS_X_PACKAGE/Tools/UNIX_Tools/test_reproducible.sh'
#				cd variant
#				reproducibility
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

# Test script to verify reproducible builds
# Check that
# - uKOS_NAME
# - uKOS_OWNER
# - TZ_UTC_SHIFT
# - TZ_DST_SPEC
# have identical value.
# Remove empty libshar in makefile
# Be sure that order of sources for each library is the same
# The script should end with
# === Building with Make ===
# === Building with CMake ===
# === Results ===

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB

# Determine script directory (works if executed via ./script.sh or zsh script.sh)
readonly PATH_PRG="${0:a:h}"

export SOURCE_DATE_EPOCH=1785062700

rm -rf artefacts_make artefacts_cmake
mkdir artefacts_make artefacts_cmake

echo "=== Building with Make ==="
cd System
make clean_all > /dev/null 2>&1
# make -j 8 NOCLEAN=1 > /dev/null 2>&1
make VERBOSE=1 NOCLEAN=1 > ../artefacts_make/verbose_log.txt 2>&1
$PATH_GCC_ARM/bin/arm-none-eabi-strip --strip-unneeded *.o
$PATH_GCC_ARM/bin/arm-none-eabi-strip --strip-unneeded lib*.a
# Normalisation timpestamp (set to 0)
$PATH_GCC_ARM/bin/arm-none-eabi-ranlib -D lib*_[pu].a
$PATH_GCC_ARM/bin/arm-none-eabi-strip --strip-unneeded FLASH.elf
mv *.o ../artefacts_make
mv lib*_[pu].a ../artefacts_make
mv FLASH.elf ../artefacts_make
make clean_all > /dev/null 2>&1
cd ..

echo "=== Building with CMake ==="
rm -rf build
cmake --preset gcc -G "Unix Makefiles" > /dev/null 2>&1
# cmake --build build --parallel > /dev/null 2>&1
cmake --build build --verbose > artefacts_cmake/verbose_log.txt 2>&1
find build -type f -name "*.o" -exec cp {} artefacts_cmake \;
$PATH_GCC_ARM/bin/arm-none-eabi-strip --strip-unneeded artefacts_cmake/*.o
$PATH_GCC_ARM/bin/arm-none-eabi-strip --strip-unneeded build/lib*.a
# Normalisation timpestamp (set to 0)
$PATH_GCC_ARM/bin/arm-none-eabi-ranlib -D build/lib*.a
cp build/lib*.a artefacts_cmake/
$PATH_GCC_ARM/bin/arm-none-eabi-strip --strip-unneeded build/FLASH.elf
cp build/FLASH.elf artefacts_cmake/

echo "=== Results ==="
for file_path in artefacts_make/*.o
do
		file_name=${file_path:t}
		if ! cmp -s "$file_path" "artefacts_cmake/$file_name"; then
			print "$file_name is different"
		fi
done
for file_path in artefacts_make/lib*.a
do
		file_name=${file_path:t}
		if ! cmp -s "$file_path" "artefacts_cmake/$file_name"; then
			print "$file_name is different"
		fi
done
if ! cmp -s "artefacts_make/FLASH.elf" "artefacts_cmake/FLASH.elf"; then
	print "Flash.elf is different"
fi
