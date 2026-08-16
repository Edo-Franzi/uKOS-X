cmake_minimum_required(VERSION 3.31)

# Get project paths
cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH PATH_TEST_ROM)
cmake_path(GET PATH_TEST_ROM PARENT_PATH PATH_TOOLS)
cmake_path(GET PATH_TOOLS PARENT_PATH PATH_UKOS)

# Set toolchain
include(${PATH_UKOS}/Ports/Mkfiles/cmake/select-riscv-toolchain.cmake)

project(
    K210_TestRom
    VERSION 0.1
    LANGUAGES C ASM
)

if(${COMPILER_FAMILY} STREQUAL "llvm")
    set(CMAKE_C_COMPILER_TARGET riscv64-unknown-elf)
    set(CMAKE_ASM_COMPILER_TARGET riscv64-unknown-elf)
endif()

set(TARGET_NAME testROM)

# Define the list of valid values for test number
set(VALID_TEST_NUMBERS 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20)

# Set the default value
set(TEST_NUMBER "00" CACHE STRING "Number of test to run.")

# Set the property for GUI tools
set_property(CACHE TEST_NUMBER PROPERTY STRINGS ${VALID_TEST_NUMBERS})

# Validate the value of TEST_NUMBER
if(NOT TEST_NUMBER IN_LIST VALID_TEST_NUMBERS)
    message(FATAL_ERROR "Invalid value for TEST_NUMBER: ${TEST_NUMBER}. Valid values are: ${VALID_TEST_NUMBERS}.")
endif()

include_directories(
    ${PATH_TEST_ROM}/_Common/Includes
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/Includes
    ${CMAKE_SOURCE_DIR}/Includes/Core
    ${CMAKE_SOURCE_DIR}/Includes/SOC
)

add_compile_definitions(
    USING_CMAKE
    TEST_${TEST_NUMBER}_S
)

add_compile_options(
    $<$<C_COMPILER_ID:GNU>:-march=rv64imafdc_zicsr_zifencei>
    $<$<C_COMPILER_ID:Clang>:-march=rv64imafdc>
    -mcmodel=medany
    -mabi=lp64d
    -g
    -Os
    -Wall
    $<$<C_COMPILER_ID:GNU>:-fstrict-volatile-bitfields>
    -fno-zero-initialized-in-bss
    -ffast-math
    -fno-math-errno
    $<$<C_COMPILER_ID:GNU>:-fsingle-precision-constant>
    -ffunction-sections
    -fdata-sections
    $<$<C_COMPILER_ID:GNU>:-Wlogical-op>
)

if(NOT ${PREFIX} STREQUAL "llvm-")
    set(LINKS_LD Runtime/link_p.ld)
else()
    set(LINKS_LD Runtime/link_p.lld)
endif()

add_link_options(
    $<$<C_COMPILER_ID:GNU>:-march=rv64imafdc_zicsr_zifencei>
    $<$<C_COMPILER_ID:Clang>:-march=rv64imafdc>
    -mcmodel=medany
    -mabi=lp64d
    -Wall
    -nostartfiles
    -L${CMAKE_SOURCE_DIR}
    -T${LINKS_LD}
    -Wl,-Map=${TARGET_NAME}.map,--cref,--print-memory-usage
    $<$<C_COMPILER_ID:GNU>:-Wl,--no-warn-rwx-segment>
)

# Create the executable
add_executable(${TARGET_NAME}.elf
    Runtime/vectors.S
    first.c
    init.c
    exce.c
    cmns.c
    tests.c
    ${PATH_TEST_ROM}/_Common/Runtime/crt0_r.c
    ${PATH_TEST_ROM}/_Common/Runtime/debug.c
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
	COMMAND ${CMAKE_SOURCE_DIR}/kflash_maixduino.sh ${TARGET_NAME}
	VERBATIM
)

# Define the custom command to generate the .lst and .dis files
add_custom_command(
    OUTPUT ${TARGET_NAME}.lst ${TARGET_NAME}.dis
    COMMAND ${GENERATE_LST} ${TARGET_NAME}.elf > ${TARGET_NAME}.lst
    COMMAND ${GENERATE_DIS} ${TARGET_NAME}.elf > ${TARGET_NAME}.dis
    DEPENDS ${TARGET_NAME}.elf
    VERBATIM
)

# Add a custom target that depends on the outputs of the custom command
add_custom_target(display
    DEPENDS ${TARGET_NAME}.lst ${TARGET_NAME}.dis
)

# Add a custom target that erases the outputs
add_custom_target(clr_all
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMAND ${CMAKE_COMMAND} -E remove -f ${TARGET_NAME}.map
)
