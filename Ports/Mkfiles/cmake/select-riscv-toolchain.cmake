# select-riscv-toolchain.
# =======================

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-07-13
# Modifs:
#
# Project:	uKOS-X
# Goal:		Selecting toolchain to build kernel and os
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

# Get the parent directory of the current file
cmake_path(GET CMAKE_CURRENT_LIST_FILE PARENT_PATH mkfiles_cmake_path)

option(USE_LLVM "Selection of toolchain" OFF)
if(${USE_LLVM})
	set(COMPILER_FAMILY llvm)
	set(PREFIX llvm-)

	if(DEFINED ENV{PATH_LLVM_RVXX})
		set(PATH_LLVM_RVXX $ENV{PATH_LLVM_RVXX})
	else()
		find_program(CLANG_COMPILER
			NAMES clang
			DOC "Clang compiler"
		)
		if(NOT CLANG_COMPILER)
			message(FATAL_ERROR "Environment variable PATH_LLVM_RVXX is not defined")
		endif()
		# Check for support for RISCV
		execute_process(
			COMMAND ${CLANG_COMPILER} --print-target-triple
			OUTPUT_VARIABLE CLANG_TARGETS
			OUTPUT_STRIP_TRAILING_WHITESPACE
			RESULT_VARIABLE CLANG_CHECK_RESULT
		)
		if(NOT CLANG_CHECK_RESULT EQUAL 0)
			message(FATAL_ERROR "Failed to check Clang targets")
		endif()
		if(NOT CLANG_TARGETS MATCHES "riscv")
			message(FATAL_ERROR "Clang found but does not support RISCV targets")
		endif()
		get_filename_component(CLANG_BIN_DIR ${CLANG_COMPILER} DIRECTORY)
		cmake_path(GET CLANG_BIN_DIR PARENT_PATH PATH_LLVM_RVXX)
	endif()

	include(${mkfiles_cmake_path}/llvm-riscv.cmake)
else()
	set(COMPILER_FAMILY gcc)
	set(PREFIX riscv64-unknown-elf-)

	if(DEFINED ENV{PATH_GCC_RVXX})
		set(PATH_GCC_RVXX $ENV{PATH_GCC_RVXX})
	else()
		# Search GCC for RISC-V in PATH
		find_program(RISC_GCC_COMPILER
			NAMES ${PREFIX}gcc
			DOC "RISC-V GCC Compiler"
		)
		if(NOT RISC_GCC_COMPILER)
			message(FATAL_ERROR "Environment variable PATH_GCC_RVXX is not defined")
		else()
			get_filename_component(RISC_GCC_BIN_DIR ${RISC_GCC_COMPILER} DIRECTORY)
			cmake_path(GET RISC_GCC_BIN_DIR PARENT_PATH PATH_GCC_RVXX)
		endif()
	endif()

	include(${mkfiles_cmake_path}/gcc-riscv.cmake)
endif()

unset(mkfiles_cmake_path)
