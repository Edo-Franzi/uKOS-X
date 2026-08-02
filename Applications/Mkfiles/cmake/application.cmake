# application.
# ============

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:   Laurent von Allmen  The 2025-01-01
# Modifs:
#
# Project:  uKOS-X
# Goal:     CMake for uKOS-X applications (generic part).
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

# Target Names
set(LOCAL_TARGET ${CMAKE_PROJECT_NAME})
set(TARGET_ELF ${LOCAL_TARGET}.elf)

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
)

# C library specific compile definitions
if(C_LIBRARY STREQUAL "picolibc")
	target_compile_definitions(system_compiler_flags INTERFACE
		CONFIG_MAN_PICOLIBC_S
		_GNU_SOURCE
		_REENT_GLOBAL_ERRNO
	)
	message(STATUS "C library compile definitions: CONFIG_MAN_PICOLIBC_S, _GNU_SOURCE, _REENT_GLOBAL_ERRNO")
elseif(C_LIBRARY STREQUAL "llvmlibc")
    target_compile_definitions(system_compiler_flags INTERFACE
        CONFIG_MAN_LLVMLIBC_S
    )
    # LLVM libc has no FILE*-based dprintf; force-include the declaration shim
    # so app code that only includes <stdio.h> still sees a prototype.
    target_compile_options(system_compiler_flags INTERFACE
        "$<$<COMPILE_LANGUAGE:C,CXX>:-include;${PATH_UKOS}/OS/Lib_generics/llvmlibc/llvmlibc_shim.h>"
    )
    # Overlay installs need --config=llvmlibc.cfg to select LLVM libc; a
    # dedicated LLVM-libc toolchain build does not. Set LLVMLIBC_CONFIG to enable.
    if(LLVMLIBC_CONFIG)
        target_compile_options(system_compiler_flags INTERFACE --config=${LLVMLIBC_CONFIG})
        target_link_options(system_compiler_flags INTERFACE --config=${LLVMLIBC_CONFIG})
    endif()
    message(STATUS "C library compile definitions: CONFIG_MAN_LLVMLIBC_S (dprintf shim force-included)")
else()
	# newlib (default)
	target_compile_definitions(system_compiler_flags INTERFACE
		CONFIG_MAN_NEWLIB_S
		__DYNAMIC_REENT__
		_POSIX_C_SOURCE=200809L
	)
	message(STATUS "C library compile definitions: CONFIG_MAN_NEWLIB_S, __DYNAMIC_REENT__, _POSIX_C_SOURCE=200809L")
endif()

# C library specific specs for GCC (compiler and linker)
# Note: Clang/LLVM uses picolibc by default, no specs needed
if(COMPILER_FAMILY STREQUAL "gcc")
	if(C_LIBRARY STREQUAL "picolibc")
		# GCC with picolibc: Use specs for both compilation and linking
		# The picolibc.specs file provides:
		# - Include paths to picolibc headers
		# - Library paths to picolibc libraries
		# - Automatic --gc-sections for linker (reduces binary size)
		# - Default picolibc.ld linker script (overridden by our -T flag)
		# Note: Our custom linker scripts override picolibc's default via -T flag
		target_compile_options(system_compiler_flags INTERFACE
			-specs=picolibc.specs
		)
		target_link_options(system_compiler_flags INTERFACE
			-specs=picolibc.specs
		)
		message(STATUS "C library specs (GCC): -specs=picolibc.specs for compilation and linking")
	else()
		# GCC with newlib (default)
		# Note: -specs=nano.specs is typically added in target-specific CMakeLists.txt
		message(STATUS "C library specs (GCC): newlib (no additional specs at application level)")
	endif()
endif()

# Common flags from *_application_CORTEX_M3.mk, *_application_CORTEX_M4.mk, *_application_CORTEX_M7.mk,
# *_application_CORTEX_M33.mk, *_application_RV32IMAC.mk and *_application_RV64IMAFDC.mk

# Read the system configuration flags from the file
file(STRINGS ${SYSTEM_CNF_PATH} SYSTEM_CNF_RAW)
separate_arguments(SYSTEM_CNF_FLAGS UNIX_COMMAND "${SYSTEM_CNF_RAW}")
list(TRANSFORM SYSTEM_CNF_FLAGS REPLACE "^-D" "")
target_compile_definitions(system_compiler_flags INTERFACE ${SYSTEM_CNF_FLAGS})

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
	$<$<COMPILE_LANGUAGE:C>:-Wstrict-prototypes>
	$<$<COMPILE_LANGUAGE:C>:-Wc++-compat>
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
	${SYSTEM_INCLUDE_DIR}
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
	${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Runtime
	${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Models
	${PATH_UKOS}/Ports/EquatesModels/SOCs/${SOC}/Runtime
	${PATH_UKOS}/Ports/EquatesModels/Generic/Runtime
	${PATH_UKOS}/Third_Parties
)

# Link options
target_link_options(system_compiler_flags INTERFACE
	-Wall
	$<$<BOOL:${VERBOSE_LINK}>:-v>
)

# Executable Target
add_executable(${TARGET_ELF} ${RUNTIME} ${OBJ})
target_link_libraries(${TARGET_ELF} PUBLIC system_compiler_flags)

# Generated TFLite models (mlp_model.xxd --> mlp_model.c_inc)
# Scan the application folder and the folders of all application sources
# for committed model hex dumps
include(${PATH_UKOS}/Ports/Mkfiles/cmake/tflite-model.cmake)

set(MODEL_SCAN_DIRS ${PATH_MYPR})
foreach(SRC IN LISTS OBJ)
	cmake_path(GET SRC PARENT_PATH SRC_DIR)
	list(APPEND MODEL_SCAN_DIRS ${SRC_DIR})
endforeach()
list(REMOVE_DUPLICATES MODEL_SCAN_DIRS)

set(MODEL_XXD_FILES "")
foreach(SCAN_DIR IN LISTS MODEL_SCAN_DIRS)
	file(GLOB DIR_XXD "${SCAN_DIR}/_Training/*.xxd" "${SCAN_DIR}/_Models/*.xxd")
	list(APPEND MODEL_XXD_FILES ${DIR_XXD})
endforeach()
list(REMOVE_DUPLICATES MODEL_XXD_FILES)

ukos_add_tflite_models(${TARGET_ELF} ${MODEL_XXD_FILES})

# Add map file in the list of files removed by make clean
set_property(TARGET ${TARGET_ELF} APPEND
	PROPERTY ADDITIONAL_CLEAN_FILES ${LOCAL_TARGET}.map
)

# Common link libraries
set(TARGET_COMMON_LIBS
	"-lm"
)
target_link_libraries(${TARGET_ELF} PRIVATE ${TARGET_COMMON_LIBS})

# Linker Script Selection
if(NOT DEFINED LINKS_LD)
	if(NOT DEFINED PATH_MAPP)
		set(PATH_MAPP ${PATH_BASE}/Runtime)
	endif()
	set(LINKS_LD ${PATH_MAPP}/link_App.ld)
endif()

# Link options
set(TARGET_COMMON_LINK_OPTIONS
	$<$<C_COMPILER_ID:Clang>:-Wl,--gc-sections>
	-Wall
	-L${PATH_UKOS}/Ports/EquatesModels/Cores/${CORE}/Runtime
	-T${LINKS_LD}
	$<$<C_COMPILER_ID:GNU>:-nostartfiles>
	$<$<AND:$<VERSION_GREATER_EQUAL:$<C_COMPILER_VERSION>,20>,$<C_COMPILER_ID:Clang>>:-nostartfiles>
)

# C library specific memory allocator wrapping
if(C_LIBRARY STREQUAL "picolibc")
	# Picolibc uses standard function names (no _r suffix)
	list(APPEND TARGET_COMMON_LINK_OPTIONS
		-Wl,--wrap=malloc
		-Wl,--wrap=free
		-Wl,--wrap=realloc
		-Wl,--wrap=calloc
	)
	message(STATUS "C library malloc wrapping: --wrap=malloc, --wrap=free, --wrap=realloc, --wrap=calloc")
elseif(C_LIBRARY STREQUAL "llvmlibc")
    # LLVM libc uses standard function names (no _r suffix), like picolibc
    list(APPEND TARGET_COMMON_LINK_OPTIONS
        -Wl,--wrap=malloc
        -Wl,--wrap=free
        -Wl,--wrap=realloc
        -Wl,--wrap=calloc
    )
    message(STATUS "C library malloc wrapping: --wrap=malloc, --wrap=free, --wrap=realloc, --wrap=calloc")
else()
	# Newlib uses reentrant function names (_r suffix)
	list(APPEND TARGET_COMMON_LINK_OPTIONS
		-Wl,--wrap=_malloc_r
		-Wl,--wrap=_free_r
		-Wl,--wrap=_realloc_r
		-Wl,--wrap=_calloc_r
	)
	message(STATUS "C library malloc wrapping: --wrap=_malloc_r, --wrap=_free_r, --wrap=_realloc_r, --wrap=_calloc_r")
endif()

target_link_options(${TARGET_ELF} PRIVATE
	${TARGET_COMMON_LINK_OPTIONS}
	$<$<COMPILE_LANGUAGE:CXX>:-lc>
	$<$<COMPILE_LANGUAGE:CXX>:-lstdc++>
	-Wl,--just-symbols=${SYSTEM_ELF_PATH}
	-Wl,-Map=${LOCAL_TARGET}.map,--cref,--print-memory-usage
)
target_link_libraries(${TARGET_ELF} PRIVATE ${MYLIB})

# Post-Build Actions

# Print executable size
add_custom_command(
	TARGET ${TARGET_ELF}
	POST_BUILD
	COMMAND ${CMAKE_STRIP} --strip-debug ${TARGET_ELF} -o stripped${TARGET_ELF}
	COMMAND ${CMAKE_SIZE} -A --radix=16 stripped${TARGET_ELF} | grep -F -v -e .debug -e .ARM.attributes -e .comment
	COMMAND ${CMAKE_COMMAND} -E remove stripped${TARGET_ELF}
	VERBATIM
)

# Generate output formats hex, bin and srec
add_custom_command(
	TARGET ${TARGET_ELF}
	POST_BUILD
	COMMAND ${CMAKE_OBJCOPY} -O ihex --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.hex
	COMMAND ${CMAKE_OBJCOPY} -O binary --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.bin
	COMMAND ${CMAKE_OBJCOPY} -O srec --strip-all ${TARGET_ELF} ${LOCAL_TARGET}.s3
	COMMAND ${CMAKE_COMMAND} -E copy ${TARGET_ELF} ${CMAKE_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy ${LOCAL_TARGET}.map ${CMAKE_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy ${LOCAL_TARGET}.hex ${CMAKE_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy ${LOCAL_TARGET}.bin ${CMAKE_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy ${LOCAL_TARGET}.s3 ${CMAKE_SOURCE_DIR}
	BYPRODUCTS
		${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.hex
		${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.bin
		${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.s3
		${CMAKE_SOURCE_DIR}/${TARGET_ELF}
		${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.map
	VERBATIM
)

# Listing files
if(WITH_LISTING)
	# Automatically create listing files
	add_custom_command(
		TARGET ${TARGET_ELF}
		POST_BUILD
		COMMAND ${GENERATE_LST} ${TARGET_ELF} > ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.lst
		COMMAND ${GENERATE_DIS} ${TARGET_ELF} > ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.dis
		BYPRODUCTS
			${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.lst
			${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.dis
		VERBATIM
	)
endif()

add_custom_target(listing
	DEPENDS ${TARGET_ELF}
	COMMAND ${GENERATE_LST} ${TARGET_ELF} > ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.lst
	COMMAND ${GENERATE_DIS} ${TARGET_ELF} > ${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.dis
	BYPRODUCTS
		${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.lst
		${CMAKE_SOURCE_DIR}/${LOCAL_TARGET}.dis
	VERBATIM
)
