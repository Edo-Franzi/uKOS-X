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
# Description:
#   Technical tool to ensure build parity between the legacy 'make' system
#   and the new 'CMake' infrastructure. It compiles the same variant
#   with both systems and performs a binary comparison (cmp) of
#   object files (.o), archives (.a), and the final ELF.
#
# Usage:
#   cd Ports/Targets/<Target>/<Variant>
#   $PATH_UKOS_X_PACKAGE/Tools/Developer/cmake-reproducibility-system.sh [-c] [-h]
#
#   The GCC preset is used by default; -c selects the LLVM one.
#
# Pre-requisites (Manual checks in CMakeLists.txt vs Makefile):
#   - Identical values for: uKOS_NAME, uKOS_OWNER.
#   - Identical source file ordering (crucial for archive parity).
#   - Remove any empty 'libshar' references in Makefile if they differ.
#
# Technical Notes:
#   - Creates 'artefacts_make' and 'artefacts_cmake' directories for diffing,
#     kept on failure so the differing files can be inspected.
#   - Binaries are normalised with strip/ranlib before comparison. The tools are
#     selected from the CORE declared in System/makefile: GCC uses the per-target
#     triple (arm-none-eabi- or riscv64-unknown-elf-) under PATH_GCC_ARM or
#     PATH_GCC_RVXX, LLVM uses llvm-* under PATH_LLVM_ARM or PATH_LLVM_RVXX.
#   - When only the ELF differs, the loadable image is extracted from both with
#     objcopy and compared, which tells a real divergence from ELF metadata noise.
#   - The firmware embeds a build time and a 'git describe' string. If the make
#     and CMake halves of a run straddle a second boundary the images differ once
#     at that offset; re-run before concluding.
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

TRAPZERR() {
	print -u2 -- "Build failed at ${funcfiletrace[1]:t} (exit $?)"
	exit 1
}

usage() {
	cat <<'EOF'
Usage: cd Ports/Targets/<Target>/<Variant> && cmake-reproducibility-system.sh [-g] [-h]

Builds the variant with make and with CMake, then compares the object files,
the archives and the ELF byte for byte.

Options:
  -g  Use the GCC toolchain (default: LLVM/clang)
  -h  Show this help message
EOF
}

# Process command line options
use_preset="gcc"
while getopts ":ch" option; do
	case "${option}" in
		c) use_preset="llvm" ;;
		h) usage; exit 0 ;;
		?) printf "Invalid option: -%s\n" "${OPTARG}" >&2; usage >&2; exit 1 ;;
	esac
done
shift $((OPTIND - 1))

if [[ ! -f System/makefile ]]
then
	print -u2 -- "Error: no System/makefile here. Run from Ports/Targets/<Target>/<Variant>."
	exit 1
fi

# Resolve the target architecture from the variant makefile.
# CORE is read rather than PREFIX: the Pico2 makefile declares PREFIX twice inside
# an ifeq, RISC-V branch first, so the first PREFIX match names the wrong toolchain.
# CORE appears once and carries the default the build actually uses. Testing the RV
# prefix rather than an enumeration follows proj_config.cmake, which accepts more
# RISC-V core names than the Mkfiles provide.
typeset core
core=$(sed -n 's/^CORE[[:space:]]*[:?]\{0,1\}=[[:space:]]*\([^[:space:]]*\).*/\1/p' System/makefile | head -1)

case $core in
	(RV*)		readonly ARCH="riscv" ;;
	(CORTEX*)	readonly ARCH="arm" ;;
	(*)			print -u2 -- "Error: cannot tell the architecture from CORE='${core}' in System/makefile."
				exit 1 ;;
esac

# Select the binutils matching both the architecture and the compiler family.
# Names follow Ports/cmake/select-{arm,riscv}-toolchain.cmake, which is the authority:
# GCC uses a per-target triple, LLVM uses llvm-* under either root.
if [[ $use_preset == "gcc" ]]
then
	if [[ $ARCH == "riscv" ]]
	then
		: ${PATH_GCC_RVXX:?Environment variable PATH_GCC_RVXX must be defined for a RISC-V target.}
		readonly TOOL_ROOT="$PATH_GCC_RVXX" TOOL_PREFIX="riscv64-unknown-elf-"
	else
		: ${PATH_GCC_ARM:?Environment variable PATH_GCC_ARM must be defined for an ARM target.}
		readonly TOOL_ROOT="$PATH_GCC_ARM" TOOL_PREFIX="arm-none-eabi-"
	fi
else
	if [[ $ARCH == "riscv" ]]
	then
		: ${PATH_LLVM_RVXX:?Environment variable PATH_LLVM_RVXX must be defined for a RISC-V target.}
		readonly TOOL_ROOT="$PATH_LLVM_RVXX"
	else
		: ${PATH_LLVM_ARM:?Environment variable PATH_LLVM_ARM must be defined for an ARM target.}
		readonly TOOL_ROOT="$PATH_LLVM_ARM"
	fi
	readonly TOOL_PREFIX="llvm-"
fi

readonly STRIP="${TOOL_ROOT}/bin/${TOOL_PREFIX}strip"
readonly RANLIB="${TOOL_ROOT}/bin/${TOOL_PREFIX}ranlib"
readonly READELF="${TOOL_ROOT}/bin/${TOOL_PREFIX}readelf"
readonly OBJCOPY="${TOOL_ROOT}/bin/${TOOL_PREFIX}objcopy"

for tool in "$STRIP" "$RANLIB" "$READELF" "$OBJCOPY"
do
	if [[ ! -x $tool ]]
	then
		print -u2 -- "Error: ${tool} not found or not executable (CORE=${core}, ${use_preset} toolchain)."
		exit 1
	fi
done

printf 'Target %s (%s), %s toolchain\n' "$core" "$ARCH" "$use_preset"

export SOURCE_DATE_EPOCH=1785062700

rm -rf artefacts_make artefacts_cmake
mkdir artefacts_make artefacts_cmake

printf '=== Building with Make ===\n'
cd System
make clean_all > /dev/null 2>&1
# Do no use make -j so that verbose output is linear
make_opts=(VERBOSE=1 NOLISTING=true NOCLEAN=1)
if [[ $use_preset != "gcc" ]]
then
	make_opts+=(PREFIX=llvm- COMPILER_FAMILY=llvm)
fi
make "${make_opts[@]}" > ../artefacts_make/verbose_log.txt 2>&1
$STRIP --strip-unneeded *.o
$STRIP --strip-unneeded lib*.a
# Normalisation timpestamp (set to 0)
$RANLIB -D lib*_[pu].a
$STRIP --strip-unneeded FLASH.elf
mv *.o ../artefacts_make
mv lib*_[pu].a ../artefacts_make
mv FLASH.elf FLASH.cnf ../artefacts_make
make clean_all > /dev/null 2>&1
cd ..

printf '=== Building with CMake ===\n'
rm -rf build
cmake --preset $use_preset -G "Unix Makefiles" -DVERBOSE_LINK=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON > /dev/null 2>&1
cp System/FLASH.cnf artefacts_cmake/
# Do no use cmake --parallel so that verbose output is linear
cmake --build build --verbose > artefacts_cmake/verbose_log.txt 2>&1
cp build/**/*.o(.) artefacts_cmake/			# Use Zsh recursive globbing instead of find
$STRIP --strip-unneeded artefacts_cmake/*.o
$STRIP --strip-unneeded build/lib*.a
# Normalisation timpestamp (set to 0)
$RANLIB -D build/lib*.a
cp build/lib*.a artefacts_cmake/
$STRIP --strip-unneeded build/FLASH.elf
cp build/FLASH.elf artefacts_cmake/
rm -r build

printf '=== Results ===\n'
integer differences=0

# Helper function for comparison to reduce repetition
check_diff() {
	local f1=$1 f2=$2
	if ! cmp -s "$f1" "$f2"; then
		print -l "${f1:t} is different"
		(( ++differences ))
	fi
}

for file_path in artefacts_make/*.o
do
	check_diff "$file_path" "artefacts_cmake/${file_path:t}"
done
for file_path in artefacts_make/lib*.a
do
	check_diff "$file_path" "artefacts_cmake/${file_path:t}"
done
if ! cmp -s "artefacts_make/FLASH.elf" "artefacts_cmake/FLASH.elf"; then
	printf "Flash.elf is different\n"
	(( ++differences ))

	printf '\n--- ELF difference analysis ---\n'

	# 1. What actually reaches the device. Everything else is metadata.
	integer image_identical=0
	$OBJCOPY -O binary "artefacts_make/FLASH.elf"  "artefacts_make/FLASH.image"
	$OBJCOPY -O binary "artefacts_cmake/FLASH.elf" "artefacts_cmake/FLASH.image"
	if cmp -s "artefacts_make/FLASH.image" "artefacts_cmake/FLASH.image"; then
		image_identical=1
		printf 'Loadable image (objcopy -O binary): IDENTICAL\n'
	else
		printf 'Loadable image (objcopy -O binary): DIFFERENT\n'
		cmp "artefacts_make/FLASH.image" "artefacts_cmake/FLASH.image" 2>&1 | sed 's/^/	 /' || true
	fi

	# 2. Section headers. The same set in a different order is emission noise.
	$READELF -S -W "artefacts_make/FLASH.elf"  | sed -n 's/^ *\[ *[0-9]\{1,\}\] \([^ ]*\).*/\1/p' > "artefacts_make/sections.txt"  || true
	$READELF -S -W "artefacts_cmake/FLASH.elf" | sed -n 's/^ *\[ *[0-9]\{1,\}\] \([^ ]*\).*/\1/p' > "artefacts_cmake/sections.txt" || true
	if cmp -s "artefacts_make/sections.txt" "artefacts_cmake/sections.txt"; then
		printf 'Section headers: identical\n'
	elif cmp -s =(sort "artefacts_make/sections.txt") =(sort "artefacts_cmake/sections.txt"); then
		printf 'Section headers: same set, different order\n'
		diff "artefacts_make/sections.txt" "artefacts_cmake/sections.txt" | sed -n 's/^[<>] \{0,1\}\(.*\)/	\1/p' | sort -u || true
	else
		printf 'Section headers: different set\n'
		diff "artefacts_make/sections.txt" "artefacts_cmake/sections.txt" | sed 's/^/  /' || true
	fi

	# 3. Architecture attributes: .ARM.attributes or .riscv.attributes.
	attr_make=$( $READELF -A "artefacts_make/FLASH.elf" 2>/dev/null || true )
	attr_cmake=$( $READELF -A "artefacts_cmake/FLASH.elf" 2>/dev/null || true )
	if [[ "$attr_make" == "$attr_cmake" ]]; then
		printf 'Architecture attributes: identical\n'
	else
		printf 'Architecture attributes: different\n'
		diff -u =(printf "%s" "$attr_make") =(printf "%s" "$attr_cmake") | sed 's/^/  /' || true
	fi

	if (( image_identical )); then
		printf '=> metadata only; nothing that reaches the device differs\n'
	fi
	printf -- '-------------------------------\n\n'
fi

if (( differences == 0 )); then
	printf 'Builds are identical.\n'
	rm -rf artefacts_make artefacts_cmake
	exit 0
fi

printf '%d difference(s) found; artefacts_make/ and artefacts_cmake/ kept for inspection.\n' $differences
exit 1
