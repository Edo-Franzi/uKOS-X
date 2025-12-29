# CMakeLists.
# ===========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		CMake file to set up the building for uKOS-X system.
#
#   (c) 2025-20xx, Laurent von Allmen
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

cmake_minimum_required(VERSION 3.26)

# Applications CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../../Mkfiles/cmake")

include(set-project-paths)

include(${PATH_UKOS}/Ports/Mkfiles/cmake/select-riscv-toolchain.cmake)

project(
	rpn
	VERSION 1.0
	LANGUAGES C
)

set(PATH_DECNUMBER ${PATH_UKOS}/Third_Parties/decnumber)

# Microcontroller description (mandatory variables)
set(SOC K210)
set(CORE RV64IMAFDC)

# Target
set(BOARD MAiXDUiNO_K210)
set(VARIANT Variant_Test)

# Extra compilation options
add_compile_options(
	-g3 # include extra information for debugger
	-Os # optimisation
)

if(CMAKE_C_COMPILER_ID MATCHES "Clang")
    set(CFLAGS_APPEND -Wno-c++-keyword)
endif()

set(PATH_INCLUDES
	${PATH_DECNUMBER}/decnumber-current/include
	${PATH_DECNUMBER}/decnumber-current/include/libdecnumber
)
find_library(MYLIB decnumber ${PATH_DECNUMBER}/Library/${CORE})

include(common)
