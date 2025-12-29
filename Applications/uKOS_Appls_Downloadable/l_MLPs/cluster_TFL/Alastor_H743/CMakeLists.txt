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

include(${PATH_UKOS}/Ports/Mkfiles/cmake/select-arm-toolchain.cmake)

project(
	cluster_TFL
	VERSION 1.0
	LANGUAGES CXX C
)

# Microcontroller description (mandatory variables)
set(SOC STM32H743)
set(CORE CORTEX_M7)

# Target
set(BOARD Alastor_H743)
set(VARIANT Variant_Test)

# Extra compilation options
add_compile_options(-g3 # includes extra information for debugger
	$<$<COMPILE_LANGUAGE:CXX>:-std=c++23>
	$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
	$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
	$<$<COMPILE_LANGUAGE:C>:-std=c23> # STANDARD
	-Os # optimisation
)
add_compile_definitions(
    $<$<COMPILE_LANGUAGE:CXX>:TF_LITE_STATIC_MEMORY=1>
    $<$<COMPILE_LANGUAGE:CXX>:CORTEX>
)

set(PATH_INCLUDES
	${PATH_UKOS}/Third_Parties/Tflite-micro/uKOS_Interface/CORTEX_M_generic
	${PATH_UKOS}/Third_Parties/Tflite-micro/uKOS_Interface/CORTEX_M_generic/third_party/flatbuffers/include
	${PATH_UKOS}/Third_Parties/Tflite-micro/uKOS_Interface/CORTEX_M_generic/third_party/gemmlowp
)
find_library(MYLIB TFLite ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/${CORE})

include(common)
