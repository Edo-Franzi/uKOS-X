# CMakeLists.
# ===========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-07-31
# Modifs:
#
# Project:	uKOS-X
# Goal:		Cmake file for building the testROM.
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

cmake_minimum_required(VERSION 3.26)

# Add uKOS-X CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../Ports/Mkfiles/cmake")

# Get project paths
include(set-project-paths)
cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH PATH_TEST_ROM)

# Set toolchain
include(select-arm-toolchain)

project(
	Nucleo_N657_Cortex-M55_testROM
	VERSION 1.0
	LANGUAGES C
)

set(TARGET_NAME testROM)

# Define the list of valid values for test number
set(VALID_TEST_NUMBERS 00 01 02 03 04 05 06 07 08 09 10 11 12)

# Set the default value
set(TEST_NUMBER "01" CACHE STRING "Number of test to run.")

# Set the property for GUI tools
set_property(CACHE TEST_NUMBER PROPERTY STRINGS ${VALID_TEST_NUMBERS})

# Validate the value of TEST_NUMBER
if(NOT TEST_NUMBER IN_LIST VALID_TEST_NUMBERS)
    message(FATAL_ERROR "Invalid value for TEST_NUMBER: ${TEST_NUMBER}. Valid values are: ${VALID_TEST_NUMBERS}.")
endif()
message(STATUS "Configured to use test number ${TEST_NUMBER}" )

set(FLAGS_FP -mfloat-abi=hard -mfpu=fpv5-sp-d16)
set(CPU_SPEC -mcpu=cortex-m55 -mthumb)

list(APPEND PATH_INCLUDES
	${PATH_TEST_ROM}/_Commun
	${PATH_TEST_ROM}/_Commun/Includes
	${PATH_TEST_ROM}/_Commun/Runtime
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/Includes
	${CMAKE_SOURCE_DIR}/Includes/SOC
	${CMAKE_SOURCE_DIR}/Includes/Core
	${CMAKE_SOURCE_DIR}/Runtime
)
include_directories(${PATH_INCLUDES})

# Sources
add_executable(${TARGET_NAME}.elf
    first.c
    init.c
    cmns.c
    tests.c
    ${PATH_TEST_ROM}/_Commun/Runtime/crt0_b.c
    ${PATH_TEST_ROM}/_Commun/Runtime/debug.c
)

# Forward selected test
set_source_files_properties(tests.c
    PROPERTIES
        COMPILE_DEFINITIONS "USING_CMAKE;TEST_${TEST_NUMBER}_S"
)

target_compile_definitions(${TARGET_NAME}.elf PRIVATE
    CACHE_S
    SECURE_S
)

target_compile_options(${TARGET_NAME}.elf PRIVATE
    ${CPU_SPEC}
    ${FLAGS_FP}
    -g -Os
    -Wall
    $<$<C_COMPILER_ID:GNU>:-Wlogical-op>
    $<$<C_COMPILER_ID:Clang>:-falign-loops=16>
)

if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
    set(LINKS_LD Runtime/link_p.lld)
else()
    set(LINKS_LD Runtime/link_p.ld)
endif()

target_link_options(${TARGET_NAME}.elf PRIVATE
    ${CPU_SPEC}
    ${FLAGS_FP}
    -Wall
    -nostartfiles
    -L${CMAKE_SOURCE_DIR}
    -T${LINKS_LD}
    -Wl,-Map=${TARGET_NAME}.map,--cref,--print-memory-usage
    $<$<C_COMPILER_ID:GNU>:-Wl,--no-warn-rwx-segment>
)
target_link_libraries(${TARGET_NAME}.elf PRIVATE m)

# Add map file in the list of files removed by make clean
set_property(TARGET ${TARGET_NAME}.elf APPEND
	PROPERTY ADDITIONAL_CLEAN_FILES
		${TARGET_NAME}.map
)

# Create hex and bin files (utils)
add_custom_command(TARGET ${TARGET_NAME}.elf
	POST_BUILD
	COMMAND ${CMAKE_OBJCOPY} -O ihex --strip-all ${TARGET_NAME}.elf ${TARGET_NAME}.hex
	COMMAND ${CMAKE_OBJCOPY} -O binary --strip-all ${TARGET_NAME}.elf ${TARGET_NAME}.bin
	VERBATIM
	BYPRODUCTS ${TARGET_NAME}.hex ${TARGET_NAME}.bin
)

# Program the SOC with binary
add_custom_target(burn
	DEPENDS ${TARGET_NAME}.elf
	COMMAND ${CMAKE_SOURCE_DIR}/burn.sh
	VERBATIM
)
