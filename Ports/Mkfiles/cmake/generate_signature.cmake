# generate_signature.
# ===================

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-10-24
# Modifs:
#
# Project:	uKOS-X
# Goal:		Cross-platform signature generation script for uKOS-X.
#
#			This script generates a SHA-256 signature from a binary file
#			and creates C source files containing the signature as a.
#			compile-time constant
#
#			Required input variables (pass via -D on command line):
#				INPUT_FILE   - Path to input binary file (e.g., NOSIG.bin)
#				OUTPUT_SIG_C - Path to output C source file (e.g., FLASH.sig.c)
#				OUTPUT_CK    - Path to output checksum file (e.g., FLASH.ck)
#
#			Example usage:
#				cmake -DINPUT_FILE=NOSIG.bin \
# 					-DOUTPUT_SIG_C=FLASH.sig.c \
# 					-DOUTPUT_CK=FLASH.ck \
# 					-P generate_signature.cmake
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

# Validate required variables
if(NOT DEFINED INPUT_FILE)
	message(FATAL_ERROR "INPUT_FILE variable is required")
endif()

if(NOT DEFINED OUTPUT_SIG_C)
	message(FATAL_ERROR "OUTPUT_SIG_C variable is required")
endif()

if(NOT DEFINED OUTPUT_CK)
	message(FATAL_ERROR "OUTPUT_CK variable is required")
endif()

# Check if input file exists
if(NOT EXISTS "${INPUT_FILE}")
	message(FATAL_ERROR "Input file does not exist: ${INPUT_FILE}")
endif()

# Compute SHA-256 hash using CMake's built-in function (cross-platform)
file(SHA256 "${INPUT_FILE}" FILE_HASH)

# SHA-256 produces exactly 64 hex characters, but extract first 64 to be explicit
string(SUBSTRING "${FILE_HASH}" 0 64 HASH_64)

# Convert to lowercase (shasum default behaviour)
string(TOLOWER "${HASH_64}" HASH_64)

# Generate .sig.c file with signature embedded in .signature section
# This mimics the original shell command output format
file(WRITE "${OUTPUT_SIG_C}"
"const char aFLASH_signature[] __attribute__((section(\".signature\"))) = \"${HASH_64}\";
")

# Generate .ck file with signature in STRG_LOC_CONST format
file(WRITE "${OUTPUT_CK}"
"STRG_LOC_CONST(aSignature[]) = \"${HASH_64}\";
")
