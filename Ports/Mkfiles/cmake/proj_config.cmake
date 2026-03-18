# proj_config.
# ============

# SPDX-License-Identifier: MIT

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
	if(SOC_NAME MATCHES "^STM32([FGHLNUWP][0-9])")
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

# ==============================================================================
# CPU FEATURES SYSTEM
# ==============================================================================
#
# The CPU_FEATURES variable allows specifying optional CPU capabilities that
# modify compiler flags and code generation.
#
# USAGE:
#	In your target's CMakeLists.txt, BEFORE include(proj_config):
#
#	set(CPU_FEATURES "feature1;feature2;...")
#	include(proj_config)
#
# VALID FEATURES BY CORE:
#
#	CORTEX_M33:
#	  nodsp			  - Disable DSP instructions
#	  nofp			  - Disable floating point unit
#
#	CORTEX_M55:
#	  mve			  - Enable Arm Helium M-Profile Vector Extension
#						(integer and floating-point vector processing)
#	  mve.fp		  - Enable Helium with explicit FP support
#	  nofp			  - Disable floating point unit
#
# EXAMPLES:
#
#	# Cortex-M55 with Helium/MVE enabled for neural networks
#	set(SOC STM32N657)
#	set(CORE CORTEX_M55)
#	set(CPU_FEATURES "mve")
#	include(proj_config)
#
#	# Cortex-M33 without FPU or DSP (minimal configuration)
#	set(SOC nRF5340)
#	set(CORE CORTEX_M33)
#	set(CPU_FEATURES "nodsp;nofp")
#	include(proj_config)
#
#	# Cortex-M55 with scalar FPU only (default behaviour)
#	set(SOC STM32N657)
#	set(CORE CORTEX_M55)
#	# No CPU_FEATURES needed - scalar FPU is default
#	include(proj_config)
#
# MIGRATION FROM OLD SYSTEM:
#
#	Old: set(NOFPU ON)
#	New: Remove line entirely (scalar FPU is now the default)
#		 OR set(CPU_FEATURES "nofp") to disable FPU completely
#
#	Old: set(CPU_SPEC "-mcpu=cortex-m33+nodsp+nofp")
#	New: set(CPU_FEATURES "nodsp;nofp")
#
# FEATURE EFFECTS:
#
#	Features automatically:
#	- Modify compiler flags (-march, -mcpu, -mfpu, etc.)
#	- Add compile definitions (e.g., MLPN_HAVE_HELIUM_FP_S)
#	- Adjust linker flags
#	- Set appropriate LLVM target triple
#
# ==============================================================================

function(configure_arm_core)
	# Check for conflicts between old and new feature systems
	if(DEFINED CPU_FEATURES AND (DEFINED NOFPU OR DEFINED CPU_SPEC))
		message(FATAL_ERROR
			"Cannot specify both CPU_FEATURES and legacy options (NOFPU/CPU_SPEC).\n"
			"Please use only CPU_FEATURES for feature configuration.")
	endif()

	add_link_options($<$<C_COMPILER_ID:GNU>:-Wl,--no-warn-rwx-segment>)
	target_compile_options(core_compiler_flags INTERFACE -mthumb -Wformat-security)
	target_compile_definitions(core_compiler_flags INTERFACE _MACHTIME_H_ _CLOCKS_PER_SEC_=1000000)

	# ARM Cortex-M core configurations
	if(${CORE} STREQUAL "CORTEX_M3")
		set(LLVM_TARGET "thumbv7m-${TARGET_TRIPLE_MIDDLE}-eabi")
		set(MCPU "cortex-m3")
		set(MARCH "armv7-m")
		set(MFLOAT_ABI "soft")
		set(EXTRA_COMPILE_FLAGS "$<$<C_COMPILER_ID:Clang>:-mfpu=none>")

	elseif(${CORE} STREQUAL "CORTEX_M4")
		set(LLVM_TARGET "thumbv7em-${TARGET_TRIPLE_MIDDLE}-eabihf")
		set(MCPU "cortex-m4")
		set(MARCH "armv7e-m")
		set(MFLOAT_ABI "hard")
		set(MFPU "fpv4-sp-d16")

	elseif(${CORE} STREQUAL "CORTEX_M7")
		set(LLVM_TARGET "thumbv7em-${TARGET_TRIPLE_MIDDLE}-eabihf")
		set(MCPU "cortex-m7")
		set(MARCH "armv7e-m")
		set(MFLOAT_ABI "hard")
		set(MFPU "fpv5-sp-d16")
		set(HAS_CACHE TRUE)

	elseif(${CORE} STREQUAL "CORTEX_M33")
		set(LLVM_TARGET "thumbv8m.main-${TARGET_TRIPLE_MIDDLE}-eabi")
		set(MCPU "cortex-m33")
		set(MARCH "armv8-m.main")
		# Check for feature-based configuration
		if(DEFINED CPU_FEATURES AND NOT "${CPU_FEATURES}" STREQUAL "")
			# CORTEX_M33_VALID_FEATURES
			#	"nodsp|Disable DSP instructions|||+nodsp"
			#	"nofp|Disable floating point unit|||+nofp"
			foreach(feature IN LISTS CPU_FEATURES)
				if(${feature} STREQUAL "nodsp")
					set(MCPU "${MCPU}+nodsp")
					set(MARCH "${MARCH}+nodsp")
				elseif(${feature} STREQUAL "nofp")
					set(MCPU "${MCPU}+nofp")
					set(MARCH "${MARCH}+nofp")
					# Soft float ABI when FP disabled
					set(MFLOAT_ABI "soft")
					unset(MFPU)
				endif()
			endforeach()
		else()
			# Hard float ABI (default)
			set(LLVM_TARGET "${LLVM_TARGET}hf")
			set(MFLOAT_ABI "hard")
			set(MFPU "fpv5-sp-d16")
		endif()
		set(HAS_CACHE TRUE)

	elseif(${CORE} STREQUAL "CORTEX_M55")
		set(LLVM_TARGET "thumbv8.1m.main-${TARGET_TRIPLE_MIDDLE}-eabihf")
		set(MARCH "armv8.1-m.main")
		set(MFLOAT_ABI "hard")
		# Check for feature-based configuration
		if(DEFINED CPU_FEATURES AND NOT "${CPU_FEATURES}" STREQUAL "")
			# CORTEX_M55_VALID_FEATURES
			#	"Helium|Helium M-Profile Vector Extension||MLPN_HAVE_HELIUM_FP_S|+mve"
			#	"Double|Double precision FP support||MLPN_HAVE_HELIUM_FP_S|+mve.fp"
			#	"nofp|Disable floating point unit|||+nofp"
			foreach(feature IN LISTS CPU_FEATURES)
				if(${feature} STREQUAL "Helium")
					set(has_mve TRUE)
				elseif(${feature} STREQUAL "Double")
					set(has_dp TRUE)
				elseif(${feature} STREQUAL "nofp")
					set(has_nofp TRUE)
				endif()
			endforeach()
		endif()
		# Check if MVE/Helium is requested
		if(has_mve)
			# Helium/MVE mode
			unset(MFPU)	 # MVE doesn't use -mfpu
			# Build -march with MVE extensions
			# GCC uses armv8.1-m.main, LLVM uses thumbv8.1m.main
			if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
				set(MARCH "armv8.1-m.main")
			endif()
            set(MARCH "${MARCH}+mve.fp")
            if(has_dp)
                set(MARCH "${MARCH}+fp.dp")
            endif()
		elseif(has_dp)
            set(MARCH "${MARCH}+fp.dp")
		elseif(has_nofp)
			# No floating point
			set(LLVM_TARGET "${MARCH}-${TARGET_TRIPLE_MIDDLE}-eabi")
			set(MFLOAT_ABI "soft")
			unset(MFPU)
		endif()
		set(HAS_CACHE TRUE)

	elseif(${CORE} STREQUAL "CORTEX_M85")
        set(LLVM_TARGET "thumbv8.1m.main-${TARGET_TRIPLE_MIDDLE}-eabihf")
        set(MARCH "armv8.1-m.main")
        set(MFLOAT_ABI "hard")
        # Check for feature-based configuration
        if(DEFINED CPU_FEATURES AND NOT "${CPU_FEATURES}" STREQUAL "")
            # CORTEX_M85_VALID_FEATURES
            #   "Helium|Helium M-Profile Vector Extension||MLPN_HAVE_HELIUM_FP_S|+mve"
            #   "PACBTI|Pointer Authentication, Branch Target Identification|||+pacbti"
            #   "Double|Double precision FP support||MLPN_HAVE_HELIUM_FP_S|+mve.fp"
            #   "nofp|Disable floating point unit|||+nofp"
            foreach(feature IN LISTS CPU_FEATURES)
                if(${feature} STREQUAL "Helium")
                    set(has_mve TRUE)
                elseif(${feature} STREQUAL "PACBTI")
                    set(has_pacbti TRUE)
                elseif(${feature} STREQUAL "Double")
                    set(has_dp TRUE)
                elseif(${feature} STREQUAL "nofp")
                    set(has_nofp TRUE)
                endif()
            endforeach()
        endif()
        # Check if MVE/Helium is requested
        if(has_mve)
            # Helium/MVE mode
            unset(MFPU)  # MVE doesn't use -mfpu
            # Build -march with MVE extensions
            # GCC uses armv8.1-m.main, LLVM uses thumbv8.1m.main
            if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
                set(MARCH "armv8.1-m.main")
            endif()
            set(MARCH "${MARCH}+mve.fp")
            if(has_dp)
                set(MARCH "${MARCH}+fp.dp")
            endif()
        elseif(has_dp)
            set(MARCH "${MARCH}+fp.dp")
        elseif(has_nofp)
            # No floating point
            set(LLVM_TARGET "${MARCH}-${TARGET_TRIPLE_MIDDLE}-eabi")
            set(MFLOAT_ABI "soft")
            unset(MFPU)
        endif()
        # PACBTI est orthogonal aux autres features : on l'ajoute en dernier
        # Il est incompatible avec nofp car il nécessite la FPU pour PAC keys
        if(has_pacbti AND NOT has_nofp)
            set(MARCH "${MARCH}+pacbti")
            set(EXTRA_COMPILE_FLAGS "-mbranch-protection=standard")
        endif()
		set(HAS_CACHE TRUE)

	elseif(${CORE} STREQUAL "CORTEX_A7")
		if(${COMPILER_FAMILY} STREQUAL "llvm")
			message(WARNING "LLVM target not defined for CORTEX_A7")
		endif()
		set(MCPU "cortex-a7")
		set(MARCH "armv7ve")
		set(HAS_CACHE TRUE)
		# A7 uses different flags, handle separately
		target_compile_options(core_compiler_flags INTERFACE -mcpu=${MCPU} -march=${MARCH})
		target_compile_definitions(core_compiler_flags INTERFACE CACHE_S)
		add_link_options(-mcpu=${MCPU} -march=${MARCH})
		return()
	else()
		message(FATAL_ERROR "Unsupported ARM core: ${CORE}")
	endif()

	# Apply LLVM target if using LLVM
	if(CMAKE_C_COMPILER_ID STREQUAL "Clang" AND DEFINED LLVM_TARGET)
		set(CMAKE_C_COMPILER_TARGET ${LLVM_TARGET} PARENT_SCOPE)
	endif()

	# Build compile flags
	set(COMPILE_FLAGS "")
	if(DEFINED MCPU)
		list(APPEND COMPILE_FLAGS "-mcpu=${MCPU}")
	endif()
	if(DEFINED MARCH AND (CMAKE_C_COMPILER_ID STREQUAL "Clang" OR ${CORE} STREQUAL "CORTEX_M55" OR ${CORE} STREQUAL "CORTEX_M85"))
		list(APPEND COMPILE_FLAGS "-march=${MARCH}")
	endif()
	if(DEFINED MFLOAT_ABI)
		list(APPEND COMPILE_FLAGS "-mfloat-abi=${MFLOAT_ABI}")
	endif()
	if(NOT DEFINED NOFPU AND DEFINED MFPU)
		list(APPEND COMPILE_FLAGS "-mfpu=${MFPU}")
	endif()
	if(DEFINED EXTRA_COMPILE_FLAGS)
		list(APPEND COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})
	endif()

	# Apply compile and link flags
	target_compile_options(core_compiler_flags INTERFACE ${COMPILE_FLAGS})
	add_link_options(${COMPILE_FLAGS})

	# Add cache definition if core has cache
	if(HAS_CACHE)
		target_compile_definitions(core_compiler_flags INTERFACE CACHE_S)
	endif()
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
macro(add_source_with_define the_list source_file)
	list(APPEND ${the_list} ${source_file})
	# Handle all definitions passed as remaining arguments
	foreach(definition ${ARGN})
		add_compile_definitions(${definition})
		file(APPEND "${ARTEFACTS_DIR}/FLASH.cnf" "-D${definition} ")
	endforeach()
endmacro()
