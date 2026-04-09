# tflite.
# =======

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2026-04-08
# Modifs:
#
# Project:	uKOS-X
# Goal:		TensorFlow Lite Micro integration for CMake builds
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

# Macro to integrate the TensorFlow Lite Micro library into the build
#
# This macro locates the prebuilt libTFLite.a for the current CORE,
# adds the public TFLite-micro include directories, defines the
# SYSTEM_TFLITE_S compile definition, and appends the imported library
# to UKOS_COMPONENTS so it is picked up by the link step in system.cmake.
#
# Requires (must be set before calling):
#	CORE		- Processor core (e.g. CORTEX_M85, CORTEX_M7, RV64IMAFDC)
#	PATH_UKOS	- Path to the uKOS-X repository root
#	ARTEFACTS_DIR	- Set by proj_config (used to record build flags)
#
# Updates in caller scope (macro):
#	PATH_INCLUDES	- Appended with the TFLite-micro public headers
#	UKOS_COMPONENTS	- Appended with the TFLite imported library
#
# Usage example:
#	add_Tflite()
macro(add_Tflite)
	# Locate the prebuilt static library for this CORE
	find_library(TFLITE TFLite
		PATHS ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/${CORE}
		NO_DEFAULT_PATH
	)
	if(NOT TFLITE)
		message(FATAL_ERROR
			"add_Tflite: libTFLite.a not found for CORE=${CORE} in "
			"${PATH_UKOS}/Third_Parties/Tflite-micro/Library/${CORE}")
	endif()

	# Public include paths for users of the library
	set(_TFLITE_ROOT
		${PATH_UKOS}/Third_Parties/Tflite-micro/uKOS_Interface/CORTEX_M_generic
	)
	list(APPEND PATH_INCLUDES
		${_TFLITE_ROOT}
		${_TFLITE_ROOT}/third_party/flatbuffers/include
		${_TFLITE_ROOT}/third_party/gemmlowp
	)

	# System wide compile definition (mirrors SYSTEM_LVGL_S convention)
	add_compile_definitions(SYSTEM_TFLITE_S)
	file(APPEND "${ARTEFACTS_DIR}/FLASH.cnf" "-DSYSTEM_TFLITE_S ")

	# Append to the link list consumed by system.cmake
	list(APPEND UKOS_COMPONENTS ${TFLITE})
endmacro()
