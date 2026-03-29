# system.
# =======

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		CMake for uKOS-X systems (generic part).
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

# Versioning Detection
if(NOT DEFINED VERSIONING)
	find_package(Git QUIET)
	if(GIT_FOUND)
		execute_process(
			COMMAND ${GIT_EXECUTABLE} rev-parse --git-dir
			OUTPUT_VARIABLE GIT_DIR
			OUTPUT_STRIP_TRAILING_WHITESPACE
			ERROR_QUIET
		)
		if(GIT_DIR)
			set(VERSIONING "git")
		else()
			set(VERSIONING "none")
		endif()
	else()
		set(VERSIONING "none")
	endif()
else()
	string(TOLOWER "${VERSIONING}" VERSIONING)
endif()

# Target Names
set(LOCAL_TARGET "FLASH" CACHE STRING "Name of the elf file.")
set(TARGET_ELF ${LOCAL_TARGET}.elf)
set(TARGET_NOSIG_ELF ${LOCAL_TARGET}.nosig.elf)

# Compiler Flags - Modern Interface Library Approach
add_library(system_compiler_flags INTERFACE)
target_link_libraries(system_compiler_flags INTERFACE core_compiler_flags)

# Standards
if(NOT DEFINED CSTANDARD)
	set(CSTANDARD "c23")
endif()
if(NOT DEFINED CXXSTANDARD)
	set(CXXSTANDARD "c++23")
endif()

# Compile definitions
target_compile_definitions(system_compiler_flags INTERFACE
	UKOS_S
	${SOC}_S
	${CORE}_S
	ROMABLE_S
	"$<$<BOOL:${KERNEL_OPT}>:${KERNEL_OPT}_S>"
	_POSIX_C_SOURCE=200809L
)

# Common flags from *_system_CORTEX_M3.mk, *_system_CORTEX_M4.mk,
# *_system_CORTEX_M7.mk, *_system_RV32IMAC.mk and *_system_RV64IMAFDC.mk
# Compile options
target_compile_options(system_compiler_flags BEFORE INTERFACE
	# Standards
	$<$<COMPILE_LANGUAGE:C>:-std=${CSTANDARD}>
	$<$<COMPILE_LANGUAGE:CXX>:-std=${CXXSTANDARD}>
	# Security
	$<$<BOOL:${CANARY}>:-fstack-protector-strong>
	# Basic behaviour
	-fshort-enums
	-fstack-usage
	$<$<AND:$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},ARM>,$<C_COMPILER_ID:GNU>>:-mpoke-function-name>
	# Warnings
	-Wall -Wextra -Wpedantic
	# Exceptions
	-Wno-main
	# Additional checks
	-Wconversion
	-Wshadow
	-Wunreachable-code
	# Recommended for CERT C
	-Wswitch-default
	-Wcast-align
	-Wcast-qual
	# C specific flags
	-Wstrict-prototypes
	-Wc++-compat
	# Additional flags
	${CFLAGS_APPEND}
)

# Include directories - NOW TARGET-SPECIFIC
target_include_directories(system_compiler_flags INTERFACE
	${PATH_INCLUDES}
	${PATH_UKOS}
	${PATH_UKOS}/OS
	${PATH_UKOS}/OS/Boots
	${PATH_UKOS}/OS/Includes
	${PATH_UKOS}/OS/Lib_serials
	${PATH_UKOS}/OS/Lib_generics
	${PATH_UKOS}/OS/Lib_kernels
	${PATH_UKOS}/OS/Lib_peripherals
	${PATH_UKOS}/OS/Lib_neurals
	${PATH_UKOS}/OS/Lib_storages
	${PATH_UKOS}/OS/Lib_cryptographics
	${PATH_UKOS}/OS/Processes
	${PATH_UKOS}/OS/Daemons
	${PATH_UKOS}/OS/CLI
	${PATH_VARI}/Shared
	${PATH_VARI}/Runtime
	${PATH_BASE}/Runtime
	${PATH_VARI}/Includes/System
	${PATH_BASE}/Includes/System
	${PATH_VARI}/Includes/Board
	${PATH_BASE}/Includes/Board
	${PATH_UKOS}/Ports/EquatesModels/Devices
	${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Models
	${PATH_UKOS}/Ports/EquatesModels/Generic/Models
	${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Includes
	${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Includes
	${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Runtime
	${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Runtime
	${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Models
	${PATH_UKOS}/Ports/EquatesModels/Generic/Runtime
	${CMAKE_CURRENT_BINARY_DIR}
	${PATH_UKOS}/Third_Parties
	${EXTRA_INCLUDE_DIRECTORIES}
)

# Link options
target_link_options(system_compiler_flags INTERFACE
	-Wall
	$<$<BOOL:${VERBOSE_LINK}>:-v>
)

# Generate version.h at each build as this file contains the git SHA of the
# code used to build the project
# Version Header Generation
if(VERSIONING STREQUAL "git")
	execute_process(
		COMMAND ${GIT_EXECUTABLE} -C "${PATH_UKOS}" describe --always --dirty --match=
		OUTPUT_VARIABLE SW_VERSION_VAR
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)
	# Trick to have version.h updated when git status changed
	execute_process(
		COMMAND ${GIT_EXECUTABLE} -C "${PATH_UKOS}" rev-parse --git-dir
		OUTPUT_VARIABLE PROJECT_SOURCE_GIT
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)
	string(REGEX REPLACE "\\.git.*" ".git" PROJECT_SOURCE_GIT "${PROJECT_SOURCE_GIT}")
	set_property(GLOBAL APPEND
		PROPERTY CMAKE_CONFIGURE_DEPENDS
		"${PROJECT_SOURCE_GIT}/index"
	)
elseif(VERSIONING STREQUAL "svn")
	execute_process(
		COMMAND svnversion
		OUTPUT_VARIABLE SW_VERSION_VAR
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)
else()
	set(SW_VERSION_VAR "Unsupported versioning system")
endif()
configure_file(
	"${PATH_UKOS}/OS/Includes/version.h.in"
	"${CMAKE_CURRENT_BINARY_DIR}/version.h"
)

# Executable Targets

# The really first pcs of code
# Put first.o in an object library
add_library(first_object OBJECT "${FIRST_P}")
target_link_libraries(first_object PUBLIC system_compiler_flags)

# Main executables
add_executable(${TARGET_NOSIG_ELF})
add_executable(${TARGET_ELF})

# Link libraries (without signature)
target_link_libraries(${TARGET_NOSIG_ELF} PRIVATE
	system_compiler_flags
	first_object
	"-Wl,-whole-archive" ${UKOS_COMPONENTS} "-Wl,-no-whole-archive"
	"-lm"
)

# Link libraries for final ELF (with signature inside whole-archive)
target_link_libraries(${TARGET_ELF} PRIVATE
	system_compiler_flags
	first_object
	"-Wl,-whole-archive" ${UKOS_COMPONENTS} sig_object "-Wl,-no-whole-archive"
	"-lm"
)

# Linker Script Selection
if(NOT DEFINED LINKS_LD)
	if(NOT DEFINED PATH_MAPP)
		set(PATH_MAPP "${PATH_BASE}/Runtime")
	endif()
	if(PREFIX STREQUAL "llvm-")
		set(LINKS_LD "${PATH_MAPP}/link${MODE}.ld")
	else()
		set(LINKS_LD "${PATH_MAPP}/link${MODE}.ld")
	endif()
endif()

# Common link options
set(TARGET_COMMON_LINK_OPTIONS
	$<$<BOOL:${CANARY}>:-Wl,--wrap=__stack_chk_fail>
	-Wl,--wrap=_malloc_r
	-Wl,--wrap=_free_r
	-Wl,--wrap=_realloc_r
	-Wl,--wrap=_calloc_r
	-L${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Runtime
	-L${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Runtime
	-T${LINKS_LD}
	$<$<C_COMPILER_ID:GNU>:-nostartfiles>
	$<$<AND:$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,20>,$<C_COMPILER_ID:Clang>>:-nostartfiles>
)
target_link_options(${TARGET_NOSIG_ELF} PRIVATE ${TARGET_COMMON_LINK_OPTIONS})
target_link_options(${TARGET_ELF} PRIVATE
	${TARGET_COMMON_LINK_OPTIONS}
	$<$<C_COMPILER_ID:GNU>:-Wl,--no-print-map-discarded>
	-Wl,-Map=${LOCAL_TARGET}.map,--cref,--print-memory-usage
)

# Generate signature at each build
add_custom_command(
	TARGET ${TARGET_NOSIG_ELF}
	POST_BUILD
	COMMAND ${CMAKE_OBJCOPY} -O binary --strip-all --remove-section=.signature
		${TARGET_NOSIG_ELF} NOSIG.bin
	BYPRODUCTS NOSIG.bin
	VERBATIM
)
# Generate signature using portable CMake script (cross-platform)
add_custom_command(
	OUTPUT ${LOCAL_TARGET}.sig.c ${LOCAL_TARGET}.ck
	COMMAND ${CMAKE_COMMAND}
		-DINPUT_FILE=${CMAKE_CURRENT_BINARY_DIR}/NOSIG.bin
		-DOUTPUT_SIG_C=${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.sig.c
		-DOUTPUT_CK=${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.ck
		-P ${CMAKE_CURRENT_LIST_DIR}/generate_signature.cmake
	DEPENDS ${TARGET_NOSIG_ELF} NOSIG.bin
	COMMENT "Generating signature C source file (SHA-256)"
	VERBATIM
)

add_library(sig_object OBJECT ${LOCAL_TARGET}.sig.c)
target_link_libraries(sig_object PRIVATE system_compiler_flags)

# Add map file, and ck file in the list of files removed by make clean
# Clean files
set_property(TARGET ${TARGET_ELF} APPEND
	PROPERTY ADDITIONAL_CLEAN_FILES
		${LOCAL_TARGET}.map
		${LOCAL_TARGET}.ck
)

# Post-Build Actions
# ==================
#
# Hybrid Approach: Development Workflow + Modern CMake Install
#
# This section implements a hybrid approach that serves two purposes:
#
# 1. DEVELOPMENT WORKFLOW (automatic, via POST_BUILD):
#	 - Artifacts are automatically copied to ARTEFACTS_DIR after each build
#	 - Default location: ${CMAKE_SOURCE_DIR}/System (configurable via cache)
#	 - This preserves the existing workflow where burn scripts expect files in System/
#	 - Uses copy_if_different for efficiency (only copies when files change)
#
# 2. DEPLOYMENT/PACKAGING (explicit, via cmake --install):
#	 - Modern install() rules enable flexible deployment scenarios
#	 - Supports CMAKE_INSTALL_PREFIX for custom installation locations
#	 - Component-based installation (runtime, firmware, development)
#	 - Usage: cmake --install build --prefix /path/to/install
#
# This design ensures backwards compatibility whilst adding modern CMake capabilities.

# Artifact output directory configuration
set(ARTEFACTS_DIR "$ENV{PWD}/System" CACHE PATH "Directory for build artifacts")

# Print executable size
add_custom_command(
	TARGET ${TARGET_ELF}
	POST_BUILD
	COMMAND ${CMAKE_STRIP} --strip-debug ${TARGET_ELF} -o stripped${TARGET_ELF}
	COMMAND ${CMAKE_SIZE} -A --radix=16 stripped${TARGET_ELF} | grep -F -v -e .debug -e .ARM.attributes -e .comment
	COMMAND ${CMAKE_COMMAND} -E remove stripped${TARGET_ELF}
	VERBATIM
)

# Generate output formats and copy to artifact directory
# Development workflow: automatic copy to ARTEFACTS_DIR for immediate use
add_custom_command(
	TARGET ${TARGET_ELF}
	POST_BUILD
	COMMENT "Generating output formats and copying to ${ARTEFACTS_DIR}"

	# Generate output formats
	COMMAND ${CMAKE_OBJCOPY} -O ihex --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.hex
	COMMAND ${CMAKE_OBJCOPY} -O binary --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.bin
	COMMAND ${CMAKE_OBJCOPY} -O srec --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.s3

	# Ensure artifact directory exists
	COMMAND ${CMAKE_COMMAND} -E make_directory ${ARTEFACTS_DIR}

	# Copy artifacts (only when changed)
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${TARGET_ELF} ${ARTEFACTS_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${LOCAL_TARGET}.map ${ARTEFACTS_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${LOCAL_TARGET}.ck ${ARTEFACTS_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${LOCAL_TARGET}.hex ${ARTEFACTS_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${LOCAL_TARGET}.bin ${ARTEFACTS_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${LOCAL_TARGET}.s3 ${ARTEFACTS_DIR}

	BYPRODUCTS
		${ARTEFACTS_DIR}/${LOCAL_TARGET}.hex
		${ARTEFACTS_DIR}/${LOCAL_TARGET}.bin
		${ARTEFACTS_DIR}/${LOCAL_TARGET}.s3
		${ARTEFACTS_DIR}/${TARGET_ELF}
		${ARTEFACTS_DIR}/${LOCAL_TARGET}.map
		${ARTEFACTS_DIR}/${LOCAL_TARGET}.ck
	VERBATIM
)

# Installation rules (modern CMake approach)
# Usage: cmake --install build --prefix /path/to/install
# This enables packaging and deployment scenarios beyond the development workflow
#
# For embedded systems, we use a simplified structure:
#	firmware/		 - All firmware files (.elf, .hex, .bin, .s3)
#	<prefix>/		 - Development files (.map, .ck, .cnf)

# Install firmware files (including ELF)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/${TARGET_ELF}
	${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.hex
	${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.bin
	${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.s3
	DESTINATION firmware
	COMPONENT firmware
)

# Install development files (map, checksum, and configuration)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.map
	${CMAKE_CURRENT_BINARY_DIR}/${LOCAL_TARGET}.ck
	${ARTEFACTS_DIR}/${LOCAL_TARGET}.cnf
	DESTINATION .
	COMPONENT development
)

# Listing files
if(WITH_LISTING)
	# Automatically create listing files
	add_custom_command(
		TARGET ${TARGET_ELF}
		POST_BUILD
		COMMAND ${GENERATE_LST} ${TARGET_ELF} > ${ARTEFACTS_DIR}/${LOCAL_TARGET}.lst
		COMMAND ${GENERATE_DIS} ${TARGET_ELF} > ${ARTEFACTS_DIR}/${LOCAL_TARGET}.dis
		BYPRODUCTS
			${ARTEFACTS_DIR}/${LOCAL_TARGET}.lst
			${ARTEFACTS_DIR}/${LOCAL_TARGET}.dis
		VERBATIM
	)
endif()

add_custom_target(listing
	DEPENDS ${TARGET_ELF}
	COMMAND ${GENERATE_LST} ${TARGET_ELF} > ${ARTEFACTS_DIR}/${LOCAL_TARGET}.lst
	COMMAND ${GENERATE_DIS} ${TARGET_ELF} > ${ARTEFACTS_DIR}/${LOCAL_TARGET}.dis
	BYPRODUCTS
		${ARTEFACTS_DIR}/${LOCAL_TARGET}.lst
		${ARTEFACTS_DIR}/${LOCAL_TARGET}.dis
	VERBATIM
)

# Utility Targets

# Program the SOC with binary
add_custom_target(burn
	DEPENDS ${TARGET_ELF}
	COMMAND ${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Burn/${BURN}.sh
	VERBATIM
)

# CTags generation
if(NOT DEFINED ENV{CTAGS})
	set(PROJ_CTAGS ctags)
else()
	set(PROJ_CTAGS $ENV{CTAGS})
endif()
set(TAG_FILE "${PATH_UKOS}/tags")
file(GLOB TAG_SRC "${PATH_UKOS}/Lib_*")
list(APPEND TAG_SRC
	"${PATH_UKOS}/OS/Includes"
	"${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}"
	"${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}"
	"${PATH_BASE}"
	"${PATH_VARI}"
)
set(CTAGS_OPTIONS "--excmd=number --tag-relative=always --fields=+a+m+n+S --map-C=+.cm --map-C=+.h --languages=C")
add_custom_target(tags
	COMMAND ${CMAKE_COMMAND} -E remove -f ${TAG_FILE}
	COMMAND ${PROJ_CTAGS} ${CTAGS_OPTIONS} -R -f ${TAG_FILE} ${TAG_SRC}
	VERBATIM
)
