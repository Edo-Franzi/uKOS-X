# proj_config.
# ============

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Configuring options to build kernel and os
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
# This function automatically determines the PROVIDER and FAMILY from a SoC name,
# eliminating redundant information in project CMakeLists.txt files.
#
# Arguments:
#	SOC_NAME - Name of the SoC (e.g., STM32L4R5, STM32H743, nRF5340)
#
# Sets in parent scope:
#	PROVIDER - Hardware provider (e.g., "st", "nordic")
#	FAMILY	 - Processor family (e.g., "l4", "h7", "nrf")
#
# Usage example:
#	set(SOC STM32L4R5)
#	derive_soc_properties(${SOC})
#	# Now PROVIDER="st" and FAMILY="l4" are available
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
	if(SOC_NAME MATCHES "^rp([0-9]+)")
		set(PROVIDER "raspberrypi" PARENT_SCOPE)
		set(FAMILY "pico2" PARENT_SCOPE)
		message(STATUS "Derived properties for ${SOC_NAME}: PROVIDER=raspberrypi, FAMILY=pico2")
		return()
	endif()

	# If no match found, issue a warning
	message(WARNING "Could not derive PROVIDER and FAMILY from SOC name: ${SOC_NAME}")
	message(WARNING "Please set PROVIDER and FAMILY manually, or extend derive_soc_properties()")
endfunction()

set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_ASM_OUTPUT_EXTENSION_REPLACE 1)

option(VERBOSE_LINK "Use -v option with lld" OFF)

option(WITH_LISTING "Control generation of dis and lst files" OFF)

option(CANARY "Canary stack protection" ON)

# Set default mode to privileged

option(USER_MODE "User mode activated" ON)

add_library(core_compiler_flags INTERFACE)
if(${USER_MODE} AND (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "ARM"))
	set(MODE _pu)
	target_compile_definitions(core_compiler_flags INTERFACE PRIVILEGED_USER_S)
else()
	# RISC-V does not support privileged/user spaces
	set(MODE _p)
endif()

set(TARGET_TRIPLE_MIDDLE unknown-none)

# Core configuration database
# This table-driven approach makes it easy to add new cores
# Format: CORE -> (llvm_target, mcpu, mfloat_abi, mfpu, extra_flags, has_cache, march)

function(configure_arm_core)
	add_link_options($<$<C_COMPILER_ID:GNU>:-Wl,--no-warn-rwx-segment>)
	target_compile_options(core_compiler_flags INTERFACE -mthumb -Wformat-security)
	target_compile_definitions(core_compiler_flags INTERFACE _MACHTIME_H_ _CLOCKS_PER_SEC_=1000000)

	# ARM Cortex-M core configurations
	if(${CORE} STREQUAL "CORTEX_M3")
		set(LLVM_TARGET "thumbv7m-${TARGET_TRIPLE_MIDDLE}-eabi")
		set(MCPU "cortex-m3")
		set(MFLOAT_ABI "soft")
		set(EXTRA_COMPILE_FLAGS "$<$<C_COMPILER_ID:Clang>:-mfpu=none>")
	elseif(${CORE} STREQUAL "CORTEX_M4")
		set(LLVM_TARGET "thumbv7em-${TARGET_TRIPLE_MIDDLE}-eabihf")
		set(MCPU "cortex-m4")
		set(MFLOAT_ABI "hard")
		set(MFPU "fpv4-sp-d16")
	elseif(${CORE} STREQUAL "CORTEX_M7")
		set(LLVM_TARGET "thumbv7em-${TARGET_TRIPLE_MIDDLE}-eabihf")
		set(MCPU "cortex-m7")
		set(MFLOAT_ABI "hard")
		set(MFPU "fpv5-sp-d16")

	elseif(${CORE} STREQUAL "CORTEX_M33")
		# M33 uses CPU_SPEC variable, handle separately
		if(NOT DEFINED CPU_SPEC)
			set(LLVM_TARGET "thumbv8m.main-${TARGET_TRIPLE_MIDDLE}-eabihf")
			set(CPU_SPEC "-mcpu=cortex-m33;-mfloat-abi=hard;-mfpu=fpv5-sp-d16")
		else()
			set(LLVM_TARGET "thumbv8m.main-${TARGET_TRIPLE_MIDDLE}-eabi")
		endif()
		target_compile_options(core_compiler_flags INTERFACE ${CPU_SPEC})
		add_link_options(${CPU_SPEC})
		return()
	elseif(${CORE} STREQUAL "CORTEX_M55")
		set(LLVM_TARGET "thumbv8.1m.main-${TARGET_TRIPLE_MIDDLE}-eabihf")
		set(MCPU "cortex-m55")
		set(MFLOAT_ABI "hard")
		set(MFPU "fpv5-sp-d16")
	elseif(${CORE} STREQUAL "CORTEX_M85")
		set(LLVM_TARGET "thumbv8.1m.main-${TARGET_TRIPLE_MIDDLE}-eabihf")
		set(MCPU "cortex-m85")
		set(MFLOAT_ABI "hard")
		set(MFPU "fpv5-sp-d16")
	elseif(${CORE} STREQUAL "CORTEX_A7")
		if(${COMPILER_FAMILY} STREQUAL "llvm")
			message(WARNING "LLVM target not defined for CORTEX_A7")
		endif()
		set(MCPU "cortex-a7")
		set(MARCH "armv7ve")
		# A7 uses different flags, handle separately
		target_compile_options(core_compiler_flags INTERFACE -mcpu=${MCPU} -march=${MARCH})
		add_link_options(-mcpu=${MCPU} -march=${MARCH})
		return()
	else()
		message(FATAL_ERROR "Unsupported ARM core: ${CORE}")
	endif()

	# Apply LLVM target if using LLVM
	if(${COMPILER_FAMILY} STREQUAL "llvm" AND DEFINED LLVM_TARGET)
		set(CMAKE_C_COMPILER_TARGET ${LLVM_TARGET} PARENT_SCOPE)
	endif()

	# Build compile flags
	set(COMPILE_FLAGS "-mcpu=${MCPU}")
	if(DEFINED MFLOAT_ABI)
		list(APPEND COMPILE_FLAGS "-mfloat-abi=${MFLOAT_ABI}")
	endif()
	if(DEFINED MFPU)
		list(APPEND COMPILE_FLAGS "-mfpu=${MFPU}")
	endif()
	if(DEFINED EXTRA_COMPILE_FLAGS)
		list(APPEND COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})
	endif()

	# Apply compile and link flags
	target_compile_options(core_compiler_flags INTERFACE ${COMPILE_FLAGS})
	add_link_options(${COMPILE_FLAGS})

endfunction()

function(configure_riscv_core)
	add_link_options($<$<C_COMPILER_ID:GNU>:-Wl,--no-warn-rwx-segment>)

	# RISC-V core configurations
	if(${CORE} STREQUAL "RV32IMAC")
		set(LLVM_TARGET "riscv32-unknown-elf")
		set(MARCH_GNU "rv32imac_zicsr_zifencei")
		set(MARCH_LLVM "rv32imac")
		set(MABI "ilp32")
		set(EXTRA_FLAGS "-gdwarf-4")
	elseif(${CORE} STREQUAL "RV64IMAFDC")
		set(LLVM_TARGET "riscv64-unknown-elf")
		set(MARCH_GNU "rv64imafdc_zicsr_zifencei")
		set(MARCH_LLVM "rv64imafdc")
		set(MABI "lp64d")
		set(MCMODEL "medany")
		set(EXTRA_FLAGS
			"-gdwarf-4"
			"-ffast-math"
			"-fno-math-errno"
			"-fno-zero-initialized-in-bss"
			"-ffunction-sections"
			"-fdata-sections"
			"-Wno-format"
			"-Wno-format-security"
		)
		set(EXTRA_FLAGS_GNU "-fstrict-volatile-bitfields")
	else()
		message(FATAL_ERROR "Unsupported RISC-V core: ${CORE}")
	endif()

	# Apply LLVM target if using LLVM
	if(${COMPILER_FAMILY} STREQUAL "llvm" AND DEFINED LLVM_TARGET)
		set(CMAKE_C_COMPILER_TARGET ${LLVM_TARGET} PARENT_SCOPE)
		set(CMAKE_ASM_COMPILER_TARGET ${LLVM_TARGET} PARENT_SCOPE)
	endif()

	# Build compile flags
	set(COMPILE_FLAGS
		"$<$<C_COMPILER_ID:GNU>:-march=${MARCH_GNU}>"
		"$<$<C_COMPILER_ID:Clang>:-march=${MARCH_LLVM}>"
		"-mabi=${MABI}"
	)
	if(DEFINED MCMODEL)
		list(APPEND COMPILE_FLAGS "-mcmodel=${MCMODEL}")
	endif()
	if(DEFINED EXTRA_FLAGS)
		list(APPEND COMPILE_FLAGS ${EXTRA_FLAGS})
	endif()
	if(DEFINED EXTRA_FLAGS_GNU)
		list(APPEND COMPILE_FLAGS "$<$<C_COMPILER_ID:GNU>:${EXTRA_FLAGS_GNU}>")
	endif()

	# Build link flags
	set(LINK_FLAGS
		"$<$<C_COMPILER_ID:GNU>:-march=${MARCH_GNU}>"
		"$<$<C_COMPILER_ID:Clang>:-march=${MARCH_LLVM}>"
		"-mabi=${MABI}"
	)
	if(DEFINED MCMODEL)
		list(APPEND LINK_FLAGS "-mcmodel=${MCMODEL}")
	endif()

	# Apply flags
	target_compile_options(core_compiler_flags INTERFACE ${COMPILE_FLAGS})
	add_link_options(${LINK_FLAGS})
endfunction()

# Apply processor-specific configuration
if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "ARM")
	configure_arm_core()
elseif(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "RISCV")
	configure_riscv_core()
else()
	message(FATAL_ERROR "Unsupported processor: ${CMAKE_SYSTEM_PROCESSOR}")
endif()

# Artifact directory configuration (shared with system.cmake)
# This must match the default in system.cmake
if(NOT DEFINED ARTEFACTS_DIR)
	set(ARTEFACTS_DIR "$ENV{PWD}/System" CACHE PATH "Directory for build artifacts")
endif()

file(REMOVE "${ARTEFACTS_DIR}/FLASH.cnf")
# Mark the file for deletion during clean
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_CLEAN_FILES "${ARTEFACTS_DIR}/FLASH.cnf")
# Macro to add a file with an associated define option
macro(add_source_with_define the_list source_file definition)
	list(APPEND ${the_list} ${source_file})
	add_compile_definitions(${definition})
	file(APPEND "${ARTEFACTS_DIR}/FLASH.cnf" "-D${definition} ")
endmacro()
