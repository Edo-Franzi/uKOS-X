# CMakeLists.
# ===========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2026-02-13
# Modifs:
#
# Project:	uKOS-X
# Goal:		CMake file to set up the building for uKOS-X the testROM.
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

cmake_minimum_required(VERSION 3.31)

# Get project paths
get_filename_component(PATH_UKOS "${CMAKE_CURRENT_LIST_DIR}/../../.." ABSOLUTE)
get_filename_component(PATH_TEST_ROM "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

# Set toolchain
include(${PATH_UKOS}/Ports/Mkfiles/cmake/select-riscv-toolchain.cmake)

project(
	RP2350_RISCV-TestRom
	VERSION 1.0
	LANGUAGES C ASM
)

set(TARGET_NAME testROM)

# Define the list of valid values for test number
set(VALID_TEST_NUMBERS 00 01 02 03 04 05 06 07 08 09 10 11)

# Set the default value
set(TEST_NUMBER "00" CACHE STRING "Number of test to run.")

# Set the property for GUI tools
set_property(CACHE TEST_NUMBER PROPERTY STRINGS ${VALID_TEST_NUMBERS})

# Validate the value of TEST_NUMBER
if(NOT TEST_NUMBER IN_LIST VALID_TEST_NUMBERS)
    message(FATAL_ERROR "Invalid value for TEST_NUMBER: ${TEST_NUMBER}. Valid values are: ${VALID_TEST_NUMBERS}.")
endif()
set(test_source "tests_${TEST_NUMBER}.c")
message(STATUS "Configured to use test file ${test_source}" )

# Define the list of supported boards
list(APPEND VALID_BOARDS
    Pico2
    Pico2W
)
# Set the default value
set(BOARD "Pico2" CACHE STRING "Target board.")
# Set the property for GUI tools
set_property(CACHE BOARD PROPERTY STRINGS ${VALID_BOARDS})
# Validate the value of BOARD
if(NOT BOARD IN_LIST VALID_BOARDS)
    message(FATAL_ERROR "Invalid value for BOARD: ${BOARD}. Valid values are: ${VALID_BOARDS}.")
endif()

set(CPU_SPECS -march=rv32imac_zicsr_zifencei)
list(APPEND FLAGS_FP
    -mabi=ilp32
)

include_directories(
    ${PATH_TEST_ROM}/_Common/Includes
    ${PATH_TEST_ROM}/_Common/Runtime
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/Includes
    ${CMAKE_SOURCE_DIR}/Includes/Core
    ${CMAKE_SOURCE_DIR}/Includes/SOC
)

# Create the executable
add_executable(${TARGET_NAME}.elf
    first_rv.c
    picobin.c
    init.c
    cmns.c
    ${test_source}
    tests.c
    ../_Common/Runtime/crt0.c
)

# Forward selected test
set_source_files_properties(tests.c
    PROPERTIES
        COMPILE_DEFINITIONS "TEST_${TEST_NUMBER}_S"
)

target_compile_definitions(${TARGET_NAME}.elf PRIVATE
    USING_CMAKE
    CACHE_D_S
    SECURE_S
    BOARD_${BOARD}
)

target_compile_options(${TARGET_NAME}.elf PRIVATE
    ${CPU_SPECS}
    ${FLAGS_FP}
    -g -Os
    -Wall
    -Wlogical-op
)

if(NOT ${PREFIX} STREQUAL "llvm-")
    set(LINKS_LD Runtime/link_p.ld)
else()
    set(LINKS_LD Runtime/link_p.lld)
endif()

target_link_options(${TARGET_NAME}.elf PRIVATE
    ${CPU_SPECS}
    ${FLAGS_FP}
    -Wall
    -nostartfiles
    -L${CMAKE_SOURCE_DIR}
    -T${LINKS_LD}
    -Wl,-Map=${TARGET_NAME}.map,--cref,--print-memory-usage
    $<$<C_COMPILER_ID:GNU>:-Wl,--no-warn-rwx-segment>
    -lm
)

# Add map file, and ck file in the list of files removed by make clean
# Clean files
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
