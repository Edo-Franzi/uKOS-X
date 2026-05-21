# tinyusb.
# ========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2026-04-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		TinyUSB integration for CMake builds
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

# Function to derive SoC properties from SoC name
#
# This function automatically determines the PROVIDER and FAMILY from a SoC name.
# These properties map to the TinyUSB library directory structure:
#   Library/Family/${FAMILY}/${SOC}/${PROFILE}
#
# Arguments:
#	SOC_NAME - Name of the SoC (e.g., STM32L4R5, STM32H743, nRF5340)
#
# Sets in parent scope:
#	PROVIDER - Hardware provider (e.g., "st", "nordic")
#	FAMILY	 - Processor family (e.g., "l4", "h7", "nrf")
function(derive_soc_properties SOC_NAME)
	# STMicroelectronics processors
	# Pattern: STM32[FGHLUWP][0-9]...
	if(SOC_NAME MATCHES "^STM32([FGHLNUVWP][0-9])")
		set(PROVIDER "st" PARENT_SCOPE)
		# Extract family letter and first digit (e.g., "L4" -> "l4")
		string(TOLOWER "${CMAKE_MATCH_1}" FAMILY_LOWER)
		set(FAMILY "${FAMILY_LOWER}" PARENT_SCOPE)
		message(STATUS "Derived properties for ${SOC_NAME}: PROVIDER=st, FAMILY=${FAMILY_LOWER}")
		return()
	endif()

	# Nordic Semiconductor processors
	# Pattern: nRF[0-9]...
	if(SOC_NAME MATCHES "^nRF([0-9]+)")
		set(PROVIDER "nordic" PARENT_SCOPE)
		set(FAMILY "nrf" PARENT_SCOPE)
		message(STATUS "Derived properties for ${SOC_NAME}: PROVIDER=nordic, FAMILY=nrf")
		return()
	endif()

	# Raspberry Pi
	# Pattern: rp[0-9]...
	# rp2350 has both ARM Cortex-M33 and Hazard3 RV32IMAC variants; the SOC
	# name alone is ambiguous. Disambiguate via the CORE variable that the
	# variant CMakeLists.txt sets before calling add_TinyUSB().
	if(SOC_NAME MATCHES "^rp([0-9]+)")
		set(PROVIDER "raspberrypi" PARENT_SCOPE)
		if(DEFINED CORE AND CORE STREQUAL "RV32IMAC")
			set(FAMILY "pico2riscv" PARENT_SCOPE)
			message(STATUS "Derived properties for ${SOC_NAME}: PROVIDER=raspberrypi, FAMILY=pico2riscv")
		else()
			set(FAMILY "pico2m33" PARENT_SCOPE)
			message(STATUS "Derived properties for ${SOC_NAME}: PROVIDER=raspberrypi, FAMILY=pico2")
		endif()
		return()
	endif()

	# If no match found, issue a warning
	message(WARNING "Could not derive PROVIDER and FAMILY from SOC name: ${SOC_NAME}")
	message(WARNING "Please set PROVIDER and FAMILY manually, or extend derive_soc_properties()")
endfunction()

# Function to integrate TinyUSB library into the build
#
# This function derives the FAMILY from the SOC name, configures and locates
# the TinyUSB package, and creates an imported target for linking.
#
# Arguments (keyword-based):
#	SPEED	- USB speed variant: FS (Full Speed) or HS (High Speed)
#	PROFILE	- USB device profile (e.g., cdc_cdc, cdc_msc, cdc_video)
#
# Requires:
#	SOC		 - Must be defined before calling (e.g., STM32H743)
#	PATH_UKOS - Must be defined before calling
#
# Sets in parent scope:
#	TINYUSB		 - The imported target to link against (e.g., TinyUSB::FS)
#	PATH_TINYUSB - Path to the TinyUSB third-party directory
#
# Usage example:
#	add_TinyUSB(SPEED FS  PROFILE cdc_cdc)
#	# Now ${TINYUSB} can be used in target_link_libraries()
function(add_TinyUSB)
	cmake_parse_arguments(TUSB "" "SPEED;PROFILE" "" ${ARGN})

	# Validate mandatory arguments
	if(NOT DEFINED TUSB_SPEED)
		message(FATAL_ERROR "add_TinyUSB: SPEED is mandatory (FS or HS)")
	endif()
	if(NOT DEFINED TUSB_PROFILE)
		message(FATAL_ERROR "add_TinyUSB: PROFILE is mandatory (e.g., cdc_cdc, cdc_msc, cdc_video)")
	endif()

	# Validate SPEED value
	if(NOT TUSB_SPEED STREQUAL "FS" AND NOT TUSB_SPEED STREQUAL "HS")
		message(FATAL_ERROR "add_TinyUSB: SPEED must be FS or HS, got '${TUSB_SPEED}'")
	endif()

	# Validate that SOC is available
	if(NOT DEFINED SOC)
		message(FATAL_ERROR "add_TinyUSB: SOC must be defined before calling add_TinyUSB()")
	endif()

	# Derive FAMILY from SOC
	derive_soc_properties(${SOC})

	set(PATH_TINYUSB ${PATH_UKOS}/Third_Parties/TinyUSB)
	set(PATH_TINYUSB ${PATH_TINYUSB} PARENT_SCOPE)

	find_package(TinyUSB REQUIRED
		PATHS ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${TUSB_PROFILE}
		NO_DEFAULT_PATH
	)

	set(TINYUSB TinyUSB::${TUSB_SPEED} PARENT_SCOPE)
endfunction()
