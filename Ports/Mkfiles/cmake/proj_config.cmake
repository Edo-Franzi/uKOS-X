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

# TinyUSB integration (derive_soc_properties, add_TinyUSB)
include(tinyusb)

# TensorFlow Lite Micro integration (add_Tflite)
include(tflite)

set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_ASM_OUTPUT_EXTENSION_REPLACE 1)

option(VERBOSE_LINK "Use -v option with lld" OFF)

option(WITH_LISTING "Control generation of dis and lst files" OFF)

option(CANARY "Canary stack protection" ON)

# Set default mode to privileged
option(USER_MODE "User mode activated" ON)

add_library(core_compiler_flags INTERFACE)

# RISC-V "user_mode" capability pre-scan.
# The privilege-split gate below runs before configure_riscv_core(), so the
# capability has to be detected from CPU_FEATURES here. Only cores/ports that
# implement M+U mode + PMP (e.g. rp2350 Hazard3) declare it; others stay privileged.
set(RISCV_FEATURE_UMODE OFF)
if((CMAKE_SYSTEM_PROCESSOR STREQUAL "RISCV") AND DEFINED CPU_FEATURES AND ("user_mode" IN_LIST CPU_FEATURES))
	set(RISCV_FEATURE_UMODE ON)
endif()

if(${USER_MODE} AND ((${CMAKE_SYSTEM_PROCESSOR} STREQUAL "ARM") OR RISCV_FEATURE_UMODE))
	set(MODE _pu)
	target_compile_definitions(core_compiler_flags INTERFACE PRIVILEGED_USER_S)
else()
	set(MODE _p)
endif()

set(TARGET_TRIPLE_MIDDLE unknown-none)

# ==============================================================================
# CPU FEATURES SYSTEM
# ==============================================================================
#
# The CPU_FEATURES variable allows specifying optional CPU capabilities that
# modify compiler flags and code generation. Feature names are case-sensitive.
#
# USAGE:
#	In your target's CMakeLists.txt, BEFORE include(proj_config):
#
#	set(CPU_FEATURES "feature1;feature2;...")
#	include(proj_config)
#
# VALID FEATURES BY CORE:
#
#	CORTEX_M3:
#	  (No configurable features)
#
#	CORTEX_M4:
#	  nofp			  - Disable the FPU (-mcpu=cortex-m4+nofp, soft-float ABI)
#
#	CORTEX_M7:
#	  Double		  - Double-precision FPU (-mfpu=fpv5-d16 instead of fpv5-sp-d16)
#	  nofp			  - Disable the FPU (-mcpu=cortex-m7+nofp, soft-float ABI);
#						takes precedence over Double
#
#	CORTEX_M33:
#	  nodsp			  - Disable the DSP instructions (+nodsp)
#	  nofp			  - Disable the FPU (+nofp, soft-float ABI)
#
#	CORTEX_M55:
#	  Helium		  - Arm Helium M-Profile Vector Extension (+mve.fp: integer and
#						single-precision floating-point vector processing)
#	  Double		  - Double-precision FPU (+fp.dp), combines with Helium
#	  nofp			  - Disable the FPU (+nofp, soft-float ABI)
#						Precedence: Helium > Double > nofp
#						Default (no feature): scalar single-precision FPU (+fp)
#
#	CORTEX_M85:
#	  Helium, Double, nofp - As for CORTEX_M55
#	  PACBTI		  - Pointer Authentication and Branch Target Identification
#						(+pacbti, -mbranch-protection=standard); ignored with nofp
#
#	CORTEX_A7:
#	  (No configurable features)
#
#	RV32IMAC (ilp32), RV32IMAFDC (ilp32d), RV32EMAC (ilp32e),
#	RV64IMAFC (lp64f), RV64IMAFDC (lp64d):
#	  <z...>		  - Any RISC-V Z-extension (zicsr, zifencei, zba, zbb, zbs, zbkb,
#						zca, zcb, zcmp, ...), appended to -march in the listed order for
#						both GCC and Clang. Requesting any Zc* code-size extension drops
#						the monolithic "c" from the base ISA (Zca/Zcb/Zcmp supersede C -
#						list "zca" to keep compression).
#	  user_mode		  - Capability (not an ISA extension): enable the privileged/user
#						split (M+U mode + PMP). Requires core + port support.
#
# VALIDATION:
#	Unknown feature names are a fatal error on every core (names are
#	case-sensitive). Conflicting ARM features are resolved by precedence
#	(see above), not by errors.
#
# EXAMPLES:
#
#	# Cortex-M55 with Helium/MVE and double-precision FPU (STM32N657)
#	set(SOC STM32N657)
#	set(CORE CORTEX_M55)
#	set(CPU_FEATURES "Helium;Double")
#	include(proj_config)
#
#   # Cortex-M85 with Helium/MVE and PACBTI (illustrative: no M85 port in this fork yet)
#   set(SOC <your_M85_SoC>)
#	set(CORE CORTEX_M85)
#	set(CPU_FEATURES "Helium;PACBTI")
#	include(proj_config)
#
#	# Cortex-M33 without FPU or DSP (nRF5340 network core)
#	set(SOC nRF5340)
#	set(CORE CORTEX_M33)
#	set(CPU_FEATURES "nodsp;nofp")
#	include(proj_config)
#
#	# RISC-V with ISA extensions and the privileged/user split (RP2350)
#	set(CORE RV32IMAC)
#	set(CPU_FEATURES "zicsr;zifencei;zba;zbb;zbs;zbkb;user_mode")
#	include(proj_config)
#
#	# Cortex-M55 with scalar FPU only (default behaviour)
#	set(SOC STM32N657)
#	set(CORE CORTEX_M55)
#	# No CPU_FEATURES needed - scalar FPU is the default
#	include(proj_config)
#
# MIGRATION FROM THE LEGACY VARIABLES:
#
#	Old: set(NOFPU ON)
#	New: Remove the line entirely (scalar FPU is the default)
#		 OR set(CPU_FEATURES "nofp") to disable the FPU completely
#
#	Old: set(CPU_SPEC "-mcpu=cortex-m33+nodsp+nofp")
#	New: set(CPU_FEATURES "nodsp;nofp")
#
#	Specifying CPU_FEATURES together with NOFPU or CPU_SPEC is a fatal error.
#
# FEATURE EFFECTS:
#
#	Features automatically:
#	- Modify the compiler flags (-mcpu/-march, -mfpu, -mfloat-abi, ...)
#	- Apply the same flags to the linker
#	- Select the matching LLVM target triple
#	- On RISC-V, "user_mode" enables the privileged/user build (MODE _pu)
#
# ==============================================================================

function(configure_arm_core)
	# Check for conflicts between old and new feature systems
	if(DEFINED CPU_FEATURES AND (DEFINED NOFPU OR DEFINED CPU_SPEC))
		message(FATAL_ERROR
			"Cannot specify both CPU_FEATURES and legacy options (NOFPU/CPU_SPEC).\n"
			"Please use only CPU_FEATURES for feature configuration.")
	endif()

	# Valid feature names per core (case-sensitive). An unknown name is a hard
	# error to catch typos early, as for RISC-V; cores without features reject
	# any name.
	set(CORTEX_M3_VALID_FEATURES "")
	set(CORTEX_M4_VALID_FEATURES "nofp")
	set(CORTEX_M7_VALID_FEATURES "Double;nofp")
	set(CORTEX_M33_VALID_FEATURES "nodsp;nofp")
	set(CORTEX_M55_VALID_FEATURES "Helium;Double;nofp")
	set(CORTEX_M85_VALID_FEATURES "Helium;Double;nofp;PACBTI")
	set(CORTEX_A7_VALID_FEATURES "")
	if(DEFINED CPU_FEATURES AND DEFINED ${CORE}_VALID_FEATURES)
		string(JOIN ", " _valid_list ${${CORE}_VALID_FEATURES})
		if(_valid_list STREQUAL "")
			set(_valid_list "(none)")
		endif()
		foreach(feature IN LISTS CPU_FEATURES)
			if(NOT feature IN_LIST ${CORE}_VALID_FEATURES)
				message(FATAL_ERROR
					"Unknown ARM CPU feature: '${feature}' (CORE=${CORE})\n"
					"Valid features for ${CORE}: ${_valid_list}")
			endif()
		endforeach()
	endif()

	add_link_options($<$<C_COMPILER_ID:GNU>:-Wl,--no-warn-rwx-segment>)
	target_compile_options(core_compiler_flags INTERFACE -mthumb -Wformat-security
		$<$<C_COMPILER_ID:Clang>:-ffunction-sections>
		$<$<C_COMPILER_ID:Clang>:-fdata-sections>
	)
	target_compile_definitions(core_compiler_flags INTERFACE _MACHTIME_H_ _CLOCKS_PER_SEC_=1000000)

	# ARM Cortex-M core configurations
	# Cores other than M55/M85 use -mcpu= with feature extensions (not -march=):
	# -mcpu= implies -march= and additionally enables CPU-specific scheduling.
	# M55/M85 use -march= only (see below).
	if(${CORE} STREQUAL "CORTEX_M3")
		set(LLVM_TARGET "thumbv7m-${TARGET_TRIPLE_MIDDLE}-eabi")
		set(MCPU "cortex-m3")
		set(MFLOAT_ABI "soft")

	elseif(${CORE} STREQUAL "CORTEX_M4")
		set(LLVM_TARGET "thumbv7em-${TARGET_TRIPLE_MIDDLE}-eabi")
		set(MCPU "cortex-m4")
		if(DEFINED CPU_FEATURES AND NOT "${CPU_FEATURES}" STREQUAL "")
			# CORTEX_M4 features:
			#	nofp	- Disable the FPU (+nofp, soft-float ABI)
			foreach(feature IN LISTS CPU_FEATURES)
				if(${feature} STREQUAL "nofp")
					set(MCPU "${MCPU}+nofp")
					set(MFLOAT_ABI "soft")
				endif()
			endforeach()
		endif()
		if(NOT DEFINED MFLOAT_ABI)
			# Default: hard float SP
			set(LLVM_TARGET "${LLVM_TARGET}hf")
			set(MFLOAT_ABI "hard")
			set(MFPU "fpv4-sp-d16")		 # GCC only via filter further down
		endif()

	elseif(${CORE} STREQUAL "CORTEX_M7")
		set(LLVM_TARGET "thumbv7em-${TARGET_TRIPLE_MIDDLE}-eabi")
		set(MCPU "cortex-m7")
		# Check for feature-based configuration
		if(DEFINED CPU_FEATURES AND NOT "${CPU_FEATURES}" STREQUAL "")
			# CORTEX_M7 features:
			#	Double	- Double-precision FPU (-mfpu=fpv5-d16)
			#	nofp	- Disable the FPU (+nofp, soft-float ABI); takes precedence over Double
			foreach(feature IN LISTS CPU_FEATURES)
				if(${feature} STREQUAL "Double")
					set(has_dp TRUE)
				elseif(${feature} STREQUAL "nofp")
					set(has_nofp TRUE)
				endif()
			endforeach()
			if(has_nofp)
				set(MCPU "${MCPU}+nofp")
				set(MFLOAT_ABI "soft")
			elseif(has_dp)
				set(LLVM_TARGET "${LLVM_TARGET}hf")
				set(MFLOAT_ABI "hard")
				set(MFPU "fpv5-d16")
			else()
				# Single-precision FPU (default when features are set but not Double/nofp)
				set(LLVM_TARGET "${LLVM_TARGET}hf")
				set(MFLOAT_ABI "hard")
				set(MFPU "fpv5-sp-d16")
			endif()
		else()
			# Hard float ABI with single-precision FPU (default)
			set(LLVM_TARGET "${LLVM_TARGET}hf")
			set(MFLOAT_ABI "hard")
			set(MFPU "fpv5-sp-d16")
		endif()

	elseif(${CORE} STREQUAL "CORTEX_M33")
		set(LLVM_TARGET "thumbv8m.main-${TARGET_TRIPLE_MIDDLE}-eabihf")
		set(MCPU "cortex-m33")
		set(MFLOAT_ABI "hard")
		set(MFPU "fpv5-sp-d16")
		# Check for feature-based configuration
		if(DEFINED CPU_FEATURES AND NOT "${CPU_FEATURES}" STREQUAL "")
			# CORTEX_M33 features:
			#	nodsp	- Disable the DSP instructions (+nodsp)
			#	nofp	- Disable the FPU (+nofp, soft-float ABI)
			foreach(feature IN LISTS CPU_FEATURES)
				if(${feature} STREQUAL "nodsp")
					set(MCPU "${MCPU}+nodsp")
				elseif(${feature} STREQUAL "nofp")
					set(MCPU "${MCPU}+nofp")
					set(MFLOAT_ABI "soft")
					unset(MFPU)
				endif()
			endforeach()
		endif()

	elseif(${CORE} STREQUAL "CORTEX_M55")
		set(LLVM_TARGET "thumbv8.1m.main-${TARGET_TRIPLE_MIDDLE}-eabihf")
		# M55/M85 use -march= only (no -mcpu=) because GCC and Clang have
		# incompatible -mcpu= feature syntax (GCC subtractive, Clang additive).
		set(MARCH "armv8.1-m.main")
		set(MFLOAT_ABI "hard")
		# Check for feature-based configuration
		if(DEFINED CPU_FEATURES AND NOT "${CPU_FEATURES}" STREQUAL "")
			# CORTEX_M55 features:
			#	Helium	- Arm Helium M-Profile Vector Extension (+mve.fp)
			#	Double	- Double-precision FPU (+fp.dp)
			#	nofp	- Disable the FPU (+nofp, soft-float ABI)
			#	Precedence: Helium > Double > nofp
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
		if(has_mve)
			# Helium/MVE mode
			unset(MFPU)	 # MVE doesn't use -mfpu
			set(MARCH "${MARCH}+mve.fp")
			if(has_dp)
				set(MARCH "${MARCH}+fp.dp")
			endif()
		elseif(has_dp)
			set(MARCH "${MARCH}+fp.dp")
		elseif(has_nofp)
			set(LLVM_TARGET "thumbv8.1m.main-${TARGET_TRIPLE_MIDDLE}-eabi")
			set(MARCH "${MARCH}+nofp")
			set(MFLOAT_ABI "soft")
			unset(MFPU)
		else()
			# Default: scalar single-precision FPU. -march=armv8.1-m.main alone has
			# no FPU and GCC rejects it together with -mfloat-abi=hard.
			set(MARCH "${MARCH}+fp")
		endif()

	elseif(${CORE} STREQUAL "CORTEX_M85")
		set(LLVM_TARGET "thumbv8.1m.main-${TARGET_TRIPLE_MIDDLE}-eabihf")
		# Same -march= approach as M55 (see comment above)
		set(MARCH "armv8.1-m.main")
		set(MFLOAT_ABI "hard")
		# Check for feature-based configuration
		if(DEFINED CPU_FEATURES AND NOT "${CPU_FEATURES}" STREQUAL "")
			# CORTEX_M85 features:
			#	Helium	- Arm Helium M-Profile Vector Extension (+mve.fp)
			#	PACBTI	- Pointer Authentication, Branch Target Identification (+pacbti)
			#	Double	- Double-precision FPU (+fp.dp)
			#	nofp	- Disable the FPU (+nofp, soft-float ABI)
			#	Precedence: Helium > Double > nofp; PACBTI ignored with nofp
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
		if(has_mve)
			# Helium/MVE mode
			unset(MFPU)	 # MVE doesn't use -mfpu
			set(MARCH "${MARCH}+mve.fp")
			if(has_dp)
				set(MARCH "${MARCH}+fp.dp")
			endif()
		elseif(has_dp)
			set(MARCH "${MARCH}+fp.dp")
		elseif(has_nofp)
			set(LLVM_TARGET "thumbv8.1m.main-${TARGET_TRIPLE_MIDDLE}-eabi")
			set(MARCH "${MARCH}+nofp")
			set(MFLOAT_ABI "soft")
			unset(MFPU)
		else()
			# Default: scalar single-precision FPU. -march=armv8.1-m.main alone has
			# no FPU and GCC rejects it together with -mfloat-abi=hard.
			set(MARCH "${MARCH}+fp")
		endif()
		# PACBTI is orthogonal to other features: appended last
		# Incompatible with nofp as it requires the FPU for PAC keys
		if(has_pacbti AND NOT has_nofp)
			set(MARCH "${MARCH}+pacbti")
			set(EXTRA_COMPILE_FLAGS "-mbranch-protection=standard")
		endif()

	elseif(${CORE} STREQUAL "CORTEX_A7")
		if(${COMPILER_FAMILY} STREQUAL "llvm")
			message(WARNING "LLVM target not defined for CORTEX_A7")
		endif()
		set(MCPU "cortex-a7")
		# A7 uses different flags, handle separately
		target_compile_options(core_compiler_flags INTERFACE -mcpu=${MCPU})
		add_link_options(-mcpu=${MCPU})
		return()
	else()
		message(FATAL_ERROR "Unsupported ARM core: ${CORE}")
	endif()

	# Apply LLVM target if using LLVM
	if(CMAKE_C_COMPILER_ID STREQUAL "Clang" AND DEFINED LLVM_TARGET)
		set(CMAKE_C_COMPILER_TARGET ${LLVM_TARGET} PARENT_SCOPE)
		set(CMAKE_CXX_COMPILER_TARGET ${LLVM_TARGET} PARENT_SCOPE)
	endif()

	# Build compile flags — -mcpu= for scheduling, -march= only for M55/M85
	# (where GCC and Clang have incompatible -mcpu= feature syntax)
	set(COMPILE_FLAGS "")
	if(DEFINED MCPU)
		list(APPEND COMPILE_FLAGS "-mcpu=${MCPU}")
	endif()
	if(DEFINED MARCH)
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

endfunction()

function(configure_riscv_core)
	add_link_options($<$<C_COMPILER_ID:GNU>:-Wl,--no-warn-rwx-segment>)
	# Same clock-tick contract as the ARM cores: _CLOCKS_PER_SEC_ is the 1-us
	# resolution of the kernel counter, and _MACHTIME_H_ keeps newlib's
	# machine/time.h from defining it (it agrees on RISC-V, but the value must
	# not depend on which C library is in use -- LLVM libc ships no machine/).
	target_compile_definitions(core_compiler_flags INTERFACE _MACHTIME_H_ _CLOCKS_PER_SEC_=1000000)
	target_compile_options(core_compiler_flags INTERFACE
		$<$<C_COMPILER_ID:Clang>:-ffunction-sections>
		$<$<C_COMPILER_ID:Clang>:-fdata-sections>
	)

	# RISC-V core configurations.
	# The base ISA is fixed per core; optional ISA extensions (zicsr, zifencei and any
	# further z*) and capabilities (user_mode) are declared by the target via CPU_FEATURES
	# and parsed below into the -march suffix. ABI / code model / extra flags stay per core.
	if(${CORE} STREQUAL "RV32IMAC")
		set(LLVM_TARGET "riscv32-unknown-elf")
		set(MARCH_BASE "rv32imac")
		set(MABI "ilp32")
		set(EXTRA_FLAGS "-gdwarf-4")
	elseif(${CORE} STREQUAL "RV32IMAFDC")
		set(LLVM_TARGET "riscv32-unknown-elf")
		set(MARCH_BASE "rv32imafdc")
		set(MABI "ilp32d")
		set(EXTRA_FLAGS "-gdwarf-4")
	elseif(${CORE} STREQUAL "RV32EMAC")
		set(LLVM_TARGET "riscv32-unknown-elf")
		set(MARCH_BASE "rv32emac")
		set(MABI "ilp32e")
		set(EXTRA_FLAGS "-gdwarf-4")
	elseif(${CORE} STREQUAL "RV64IMAFC")
		set(LLVM_TARGET "riscv64-unknown-elf")
		set(MARCH_BASE "rv64imafc")
		set(MABI "lp64f")
		set(MCMODEL "medany")
		set(EXTRA_FLAGS "-gdwarf-4")
	elseif(${CORE} STREQUAL "RV64IMAFDC")
		set(LLVM_TARGET "riscv64-unknown-elf")
		set(MARCH_BASE "rv64imafdc")
		set(MABI "lp64d")
		set(MCMODEL "medany")
		set(EXTRA_FLAGS
			"-gdwarf-4"
			"-ffast-math"
			"-fno-math-errno"
			"-fno-zero-initialized-in-bss"
			"-Wno-format"
			"-Wno-format-security"
		)
		# GCC only, and only for this core: gcc_system_RV64IMAFDC.mk adds the section
		# flags that no other GCC configuration uses. Clang gets them above, for every
		# RISC-V core, which is what the llvm_system_RV*.mk files do.
		set(EXTRA_FLAGS_GNU
			"-fstrict-volatile-bitfields"
			"-ffunction-sections"
			"-fdata-sections"
		)
	else()
		message(FATAL_ERROR "Unsupported RISC-V core: ${CORE}")
	endif()

	# Parse CPU_FEATURES into the -march extension suffix (applied to BOTH GCC and Clang,
	# so the two toolchains stay in sync). A z* token becomes an ISA extension; "user_mode"
	# is a capability consumed by the privilege gate (see RISCV_FEATURE_UMODE) and does not
	# affect -march; anything else is a hard error to catch typos early.
	#
	# The granular code-size extensions (Zca/Zcb/Zcmp/...) supersede the monolithic "C":
	# if any Zc* is requested, drop the trailing "c" from the base ISA and let the target
	# provide compression explicitly via "zca". This matches the RP2350 datasheet's
	# rv32ima_..._zca_zcb_zcmp recommendation and avoids older assemblers rejecting c + zcmp.
	set(_march_ext "")
	set(_has_zc FALSE)
	if(DEFINED CPU_FEATURES AND NOT "${CPU_FEATURES}" STREQUAL "")
		foreach(feature IN LISTS CPU_FEATURES)
			if(feature MATCHES "^z[0-9a-z]+$")
				string(APPEND _march_ext "_${feature}")
				if(feature MATCHES "^zc")
					set(_has_zc TRUE)
				endif()
			elseif(feature STREQUAL "user_mode")
				# capability only — no effect on -march
			else()
				message(FATAL_ERROR "Unknown RISC-V CPU feature: '${feature}' (CORE=${CORE})")
			endif()
		endforeach()
	endif()
	if(_has_zc)
		string(REGEX REPLACE "c$" "" MARCH_BASE "${MARCH_BASE}")
	endif()
	set(MARCH_GNU  "${MARCH_BASE}${_march_ext}")
	set(MARCH_LLVM "${MARCH_BASE}${_march_ext}")

	# Apply LLVM target if using LLVM
	if(${COMPILER_FAMILY} STREQUAL "llvm" AND DEFINED LLVM_TARGET)
		set(CMAKE_C_COMPILER_TARGET ${LLVM_TARGET} PARENT_SCOPE)
		set(CMAKE_CXX_COMPILER_TARGET ${LLVM_TARGET} PARENT_SCOPE)
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

	# Privileged/user split (_pu): privileged and user small-data sit farther apart than
	# the ±2 KiB gp window, so gp-relative access to the other domain would silently hit
	# the wrong address. Disable small-data entirely (globals addressed absolutely); the
	# KERN_NEW_FRAME "la gp,__global_pointer$" reload stays harmless. Accepted by GCC and Clang.
	if(MODE STREQUAL "_pu")
		list(APPEND COMPILE_FLAGS "-msmall-data-limit=0")
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
macro(add_source_with_define the_lib source_file)
	target_sources(${the_lib} PRIVATE ${source_file})
	# Handle all definitions passed as remaining arguments
	foreach(definition ${ARGN})
		add_compile_definitions(${definition})
		file(APPEND "${ARTEFACTS_DIR}/FLASH.cnf" "-D${definition} ")
	endforeach()
endmacro()

# Macro to add the C library manager source selected by C_LIBRARY.
# Centralises the newlib/picolibc/llvmlibc source-file switch that would
# otherwise be copy-pasted into every target's CMakeLists.txt.
macro(add_clib_manager_source the_lib)
	if(C_LIBRARY STREQUAL "picolibc")
		add_source_with_define(${the_lib} ${PATH_OSYS}/Lib_generics/picolibc/picolibc.c CONFIG_MAN_PICOLIBC_S)
	elseif(C_LIBRARY STREQUAL "llvmlibc")
		add_source_with_define(${the_lib} ${PATH_OSYS}/Lib_generics/llvmlibc/llvmlibc.c CONFIG_MAN_LLVMLIBC_S)
	else()
		add_source_with_define(${the_lib} ${PATH_OSYS}/Lib_generics/newlib/newlib.c CONFIG_MAN_NEWLIB_S)
	endif()
endmacro()

# MicroPython Engine integration (MicroPython manager)
macro(add_MicroPython)
	add_compile_definitions(CONFIG_MAN_MICROPYTHON_S)
	find_library(MICROPYTHON MicroPython ${PATH_UKOS}/Third_Parties/MicroPython/Library/${CORE})
	file(APPEND "${ARTEFACTS_DIR}/FLASH.cnf" "-DCONFIG_MAN_MICROPYTHON_S ")
	list(APPEND UKOS_COMPONENTS ${MICROPYTHON})
endmacro()

# FATFS (File system) integration
# Usage example:
#	add_FatFs(STORAGE flash)
macro(add_FatFs)
	cmake_parse_arguments(FATFS "" "STORAGE" "" ${ARGN})

	# Validate mandatory arguments
	if(NOT DEFINED FATFS_STORAGE)
		message(FATAL_ERROR "add_FatFS: STORAGE is mandatory (flash, or sdcard, or sdcard_flash)")
	endif()

	# Validate STORAGE value
	if(NOT FATFS_STORAGE STREQUAL "flash" AND NOT FATFS_STORAGE STREQUAL "sdcard" AND NOT FATFS_STORAGE STREQUAL "sdcard_flash")
		message(FATAL_ERROR "add_FatFs: STORAGE must be flash, or sdcard, or sdcard_flash, got '${FATFS_STORAGE}'")
	endif()

	add_compile_definitions(CONFIG_MAN_FATFS_S)
	find_library(FATFS FatFs ${PATH_UKOS}/Third_Parties/FatFs/Library/${CORE}/${FATFS_STORAGE})
	file(APPEND "${ARTEFACTS_DIR}/FLASH.cnf" "-DCONFIG_MAN_FATFS_S ")
	list(APPEND UKOS_COMPONENTS ${FATFS})
endmacro()

# Graphic library integration (LVGL)
macro(add_LVGL)
	cmake_parse_arguments(LVGL "" "DISPLAY" "" ${ARGN})

	# Validate mandatory arguments
	if(NOT DEFINED LVGL_DISPLAY)
		message(FATAL_ERROR "add_LVGL: DISPLAY is mandatory")
	endif()

	add_compile_definitions(SYSTEM_LVGL_S)
	find_library(LVGL LVGL ${PATH_UKOS}/Third_Parties/LVGL/Library/${LVGL_DISPLAY}/${CORE})
	file(APPEND "${ARTEFACTS_DIR}/FLASH.cnf" "-DSYSTEM_LVGL_S ")
	list(APPEND UKOS_COMPONENTS ${LVGL})
endmacro()
