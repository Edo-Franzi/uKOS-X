# llvm-arm.
# =========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Toolchain file for configuring Cmake to build cross-compiling
#			projects based on CORTEM M core using clang(LLVM).
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

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR ARM)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(PATH_TOOLCHAIN_PREFIX ${PATH_LLVM_ARM}/bin/llvm-)

# Validate that all required toolchain utilities exist
foreach(tool IN ITEMS clang clang++ ld.lld)
	set(tool_path "${PATH_LLVM_ARM}/bin/${tool}")
	if(NOT EXISTS "${tool_path}")
		message(FATAL_ERROR "Toolchain utility not found: ${tool_path}\n"
							"Please verify PATH_LLVM_ARM is set correctly: ${PATH_LLVM_ARM}")
	endif()
endforeach()

foreach(tool IN ITEMS ar objcopy objdump ranlib strip size)
	set(tool_path "${PATH_TOOLCHAIN_PREFIX}${tool}")
	if(NOT EXISTS "${tool_path}")
		message(FATAL_ERROR "Toolchain utility not found: ${tool_path}\n"
							"Please verify PATH_LLVM_ARM is set correctly: ${PATH_LLVM_ARM}")
	endif()
endforeach()

set(CMAKE_C_COMPILER ${PATH_LLVM_ARM}/bin/clang)
set(CMAKE_CXX_COMPILER ${PATH_LLVM_ARM}/bin/clang++)
set(CMAKE_AR "${PATH_TOOLCHAIN_PREFIX}ar")
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_LINKER "${PATH_LLVM_ARM}/bin/ld.lld")
set(CMAKE_OBJCOPY "${PATH_TOOLCHAIN_PREFIX}objcopy")
set(CMAKE_OBJDUMP "${PATH_TOOLCHAIN_PREFIX}objdump")
set(CMAKE_RANLIB "${PATH_TOOLCHAIN_PREFIX}ranlib")
set(CMAKE_STRIP "${PATH_TOOLCHAIN_PREFIX}strip")
set(CMAKE_SIZE "${PATH_TOOLCHAIN_PREFIX}size")
set(SCAN_BUILD "${PATH_LLVM_ARM}/bin/scan-build")

set(GENERATE_LST ${PATH_TOOLCHAIN_PREFIX}objdump -f -p -D -d -h -t -s)
set(GENERATE_DIS ${PATH_TOOLCHAIN_PREFIX}objdump -S)

# Common flags for arm bare-metal

set(CMAKE_CXX_FLAGS_INIT "-fno-rtti -fno-exceptions")
