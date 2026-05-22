# common.
# =======

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		CMake common file for the all the application.
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

# Apply project settings
include(${CMAKE_CURRENT_LIST_DIR}/proj_config.cmake)

# Project path configuration
# - PATH_UKOS	--> Main uKOS-X folder					--> kernel_os
# - PATH_BASE	--> MyProjects Root Base folders		--> MyProjects/Ports/Targets/xyz/Base
# - PATH_VARI	--> MyProjects Root Variant_xx folders	--> MyProjects/Ports/Targets/xyz/Variant_xx

cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH PATH_MYPR)
if(NOT DEFINED BOARD)
	message( FATAL_ERROR "Variable BOARD is not defined." )
endif()
if(DEFINED BASE)
	set(PATH_BASE ${PATH_UKOS}/Ports/Targets/${BOARD}/${BASE})
else()
	set(PATH_BASE ${PATH_UKOS}/Ports/Targets/${BOARD}/Base)
endif()
if(NOT DEFINED VARIANT)
	message( FATAL_ERROR "Variable VARIANT is not defined." )
endif()
set(PATH_VARI ${PATH_UKOS}/Ports/Targets/${BOARD}/${VARIANT})

# System files location configuration
# ------------------------------------
# Applications require FLASH.cnf, FLASH.ck, and FLASH.elf from the system build.
# Two modes are supported:
#	1. Source tree mode (default): Files are located in ${PATH_VARI}/System/
#	2. Installed system mode: Files are located in a directory specified by SYSTEM_INSTALL_DIR
#
# To use an installed system, pass -DSYSTEM_INSTALL_DIR=/path/to/install when configuring:
#	cmake -S . -B build -DSYSTEM_INSTALL_DIR=/path/to/l4r5

if(DEFINED SYSTEM_INSTALL_DIR)
	# Normalize to absolute path (required for compiler @file syntax)
	# Relative paths are resolved from the shell's current working directory ($ENV{PWD})
	# This allows paths like: -DSYSTEM_INSTALL_DIR=l4r5 (relative to where cmake was invoked)
	if(NOT IS_ABSOLUTE "${SYSTEM_INSTALL_DIR}")
		cmake_path(ABSOLUTE_PATH SYSTEM_INSTALL_DIR BASE_DIRECTORY "$ENV{PWD}" NORMALIZE OUTPUT_VARIABLE SYSTEM_INSTALL_DIR_ABS)
	else()
		set(SYSTEM_INSTALL_DIR_ABS "${SYSTEM_INSTALL_DIR}")
	endif()

	# Validate that the install directory exists
	if(NOT EXISTS "${SYSTEM_INSTALL_DIR_ABS}")
		message(FATAL_ERROR
			"SYSTEM_INSTALL_DIR is set to '${SYSTEM_INSTALL_DIR}' "
			"(resolved to '${SYSTEM_INSTALL_DIR_ABS}') but this directory does not exist.\n"
			"Please ensure you have installed the system using: cmake --install build --prefix <path>")
	endif()

	# Define required system files (using absolute path)
	set(REQUIRED_SYSTEM_FILES
		"${SYSTEM_INSTALL_DIR_ABS}/FLASH.cnf"
		"${SYSTEM_INSTALL_DIR_ABS}/FLASH.ck"
		"${SYSTEM_INSTALL_DIR_ABS}/firmware/FLASH.elf"
	)

	# Validate that all required files exist
	set(MISSING_FILES "")
	foreach(file ${REQUIRED_SYSTEM_FILES})
		if(NOT EXISTS "${file}")
			list(APPEND MISSING_FILES "	 - ${file}")
		endif()
	endforeach()

	if(MISSING_FILES)
		message(FATAL_ERROR
			"SYSTEM_INSTALL_DIR is set to '${SYSTEM_INSTALL_DIR}' "
			"(resolved to '${SYSTEM_INSTALL_DIR_ABS}') but the following required files are missing:\n"
			"${MISSING_FILES}\n"
			"Please ensure you have installed the system using: cmake --install build --prefix <path>")
	endif()

	# Use installed system paths (absolute)
	set(SYSTEM_CNF_PATH "${SYSTEM_INSTALL_DIR_ABS}/FLASH.cnf")
	set(SYSTEM_CK_PATH "${SYSTEM_INSTALL_DIR_ABS}/FLASH.ck")
	set(SYSTEM_ELF_PATH "${SYSTEM_INSTALL_DIR_ABS}/firmware/FLASH.elf")
	set(SYSTEM_INCLUDE_DIR "${SYSTEM_INSTALL_DIR_ABS}")

	message(STATUS "Using installed system from: ${SYSTEM_INSTALL_DIR_ABS}")
else()
	# Default: use source tree paths
	set(SYSTEM_CNF_PATH "${PATH_VARI}/System/FLASH.cnf")
	set(SYSTEM_CK_PATH "${PATH_VARI}/System/FLASH.ck")
	set(SYSTEM_ELF_PATH "${PATH_VARI}/System/FLASH.elf")
	set(SYSTEM_INCLUDE_DIR "${PATH_VARI}/System")
endif()

# Sources
# -------

# Runtime components
set(RUNTIME
	${PATH_UKOS}/Ports/EquatesModels/Generic/Runtime/header.c
	${PATH_UKOS}/Ports/EquatesModels/Generic/Runtime/crt0_App.c
)

# Project components
# Get the application name from the directory name
cmake_path(GET APP_DIR STEM APP_NAME)
if(EXISTS "${PATH_MYPR}/${APP_NAME}.c")
	set(OBJ
		${PATH_MYPR}/${APP_NAME}.c ${OBJ}
	)
elseif(EXISTS "${PATH_MYPR}/${APP_NAME}.cpp")
	set(OBJ
		${PATH_MYPR}/${APP_NAME}.cpp ${OBJ}
	)
endif()

# Apply application configuration
include(application)
