# CMakeLists.
# ===========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Builds directly STM32N657 FSBL from STM32CubeN6 sources
#			without copying files.
#			Standalone CMake project (Load-and-Run, NUCLEO-N657X0-Q)
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

# ---- Toolchain (must be set before project()) ------------------------------
set(CMAKE_TOOLCHAIN_FILE
    "${CMAKE_CURRENT_LIST_DIR}/cmake/arm-none-eabi-gcc.cmake"
    CACHE FILEPATH "Toolchain file"
)

# ---- Project ---------------------------------------------------------------
project(stm32n657_fsbl
    VERSION   0.1.0
    LANGUAGES C ASM
)

set(CMAKE_C_STANDARD          11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS        ON)          # ST headers use GNU extensions
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- STM32CubeN6 path ------------------------------------------------------
# Configure where to find STM32CubeN6 sources.
#
# Three ways to specify the location (in order of priority):
#   1. CMake command line:  -DCUBE_ROOT=/path/to/STM32CubeN6
#   2. Environment variable: export STM32CUBEN6_ROOT=/path/to/STM32CubeN6
#   3. Default: ${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeN6 (inside project)
#
# This allows teams to:
#   - Use a shared STM32CubeN6 installation
#   - Clone STM32CubeN6 anywhere on their system
#   - Use the default location inside the project directory

# Priority 1: Check if CUBE_ROOT was set via command line (-DCUBE_ROOT=...)
# Priority 2: Check environment variable
# Priority 3: Use default location inside project

if(NOT DEFINED CUBE_ROOT OR CUBE_ROOT STREQUAL "")
    # Not set via command line, check environment variable
    if(DEFINED ENV{STM32CUBEN6_ROOT})
        set(CUBE_ROOT "$ENV{STM32CUBEN6_ROOT}" CACHE PATH
            "Path to STM32CubeN6 repository (from environment variable)"
        )
        message(STATUS "Using STM32CubeN6 from environment: ${CUBE_ROOT}")
    else()
        # Use default location inside project
        set(CUBE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/STM32CubeN6" CACHE PATH
            "Path to STM32CubeN6 repository (override with -DCUBE_ROOT=...)"
        )
    endif()
else()
    # CUBE_ROOT was set via command line, ensure it's in cache
    set(CUBE_ROOT "${CUBE_ROOT}" CACHE PATH
        "Path to STM32CubeN6 repository (set via command line)" FORCE
    )
    message(STATUS "Using STM32CubeN6 from command line: ${CUBE_ROOT}")
endif()

# Verify STM32CubeN6 exists at the specified location
if(NOT EXISTS "${CUBE_ROOT}")
    message(FATAL_ERROR
        "STM32CubeN6 not found at: ${CUBE_ROOT}\n"
        "\n"
        "Please provide STM32CubeN6 location using one of these methods:\n"
        "\n"
        "  1. Clone inside project (default):\n"
        "     git clone --recursive --depth 1 \\\n"
        "         https://github.com/STMicroelectronics/STM32CubeN6.git\n"
        "\n"
        "  2. Use a different location via CMake:\n"
        "     cmake -DCUBE_ROOT=/path/to/STM32CubeN6 ...\n"
        "\n"
        "  3. Set environment variable:\n"
        "     export STM32CUBEN6_ROOT=/path/to/STM32CubeN6\n"
        "     cmake ...\n"
    )
endif()

# Verify CMSIS submodules are initialized
if(NOT EXISTS "${CUBE_ROOT}/Drivers/CMSIS/Core/Include/core_cm55.h")
    message(FATAL_ERROR
        "CMSIS submodules not initialized in STM32CubeN6.\n"
        "Run: cd ${CUBE_ROOT} && git submodule update --init --recursive"
    )
endif()

message(STATUS "Using STM32CubeN6 at: ${CUBE_ROOT}")

# ---- Global compile definitions --------------------------------------------
add_compile_definitions(
    STM32N657xx
    USE_HAL_DRIVER
    CPU_IN_SECURE_STATE
)

# =============================================================================
# Sources
# =============================================================================

# ---- FSBL application sources (project-specific) ---------------------------
set(FSBL_SOURCES
    fsbl/src/main.c
    fsbl/src/extmem.c
    fsbl/src/stm32n6xx_hal_msp.c
    fsbl/src/stm32n6xx_it.c
    fsbl/src/system_stm32n6xx_fsbl.c
)

# ---- HAL driver sources (from STM32CubeN6) ---------------------------------
# Minimal set required for FSBL LRUN mode.
# Add or remove drivers as needed by your configuration.
set(HAL_SOURCES
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal.c
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_bsec.c
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_cortex.c
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_dma.c
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_dma_ex.c
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_exti.c
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_gpio.c
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_pwr.c
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_pwr_ex.c
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_rcc.c
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_rcc_ex.c
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_xspi.c
)

# ---- ExtMem Manager middleware (from STM32CubeN6) --------------------------
# LRUN boot logic and NOR SFDP driver
file(GLOB EXTMEM_NOR_SFDP_SOURCES
    ${CUBE_ROOT}/Middlewares/ST/STM32_ExtMem_Manager/nor_sfdp/*.c
)
file(GLOB EXTMEM_SAL_SOURCES
    ${CUBE_ROOT}/Middlewares/ST/STM32_ExtMem_Manager/sal/*.c
)
set(EXTMEM_SOURCES
    ${CUBE_ROOT}/Middlewares/ST/STM32_ExtMem_Manager/stm32_extmem.c
    ${CUBE_ROOT}/Middlewares/ST/STM32_ExtMem_Manager/boot/stm32_boot_lrun.c
    ${EXTMEM_NOR_SFDP_SOURCES}
    ${EXTMEM_SAL_SOURCES}
)

# ---- BSP (optional — from STM32CubeN6) -------------------------------------
# Board Support Package for NUCLEO-N657X0-Q
file(GLOB BSP_SOURCES
    ${CUBE_ROOT}/Drivers/BSP/STM32N657X0-Nucleo/*.c
    ${CUBE_ROOT}/Drivers/BSP/NUCLEO-N657X0-Q/*.c
    ${CUBE_ROOT}/Drivers/BSP/STM32N6570-Nucleo/*.c
)

# ---- Startup (project-specific, device-specific) ----------------------------
set(STARTUP_SOURCE startup/startup_stm32n657xx.s)

# =============================================================================
# Executable target
# =============================================================================

add_executable(fsbl
    ${FSBL_SOURCES}
    ${HAL_SOURCES}
    ${EXTMEM_SOURCES}
    ${BSP_SOURCES}
    ${STARTUP_SOURCE}
)

# ---- Include paths ----------------------------------------------------------
target_include_directories(fsbl PRIVATE
    # FSBL application headers (project-specific)
    fsbl/inc

    # CMSIS Core (core_cm55.h, etc.) from STM32CubeN6
    ${CUBE_ROOT}/Drivers/CMSIS/Core/Include

    # CMSIS Device (stm32n657xx.h, system_stm32n6xx.h) from STM32CubeN6
    ${CUBE_ROOT}/Drivers/CMSIS/Device/ST/STM32N6xx/Include

    # HAL driver headers from STM32CubeN6
    ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Inc

    # BSP from STM32CubeN6 (try multiple possible paths)
    ${CUBE_ROOT}/Drivers/BSP/STM32N657X0-Nucleo
    ${CUBE_ROOT}/Drivers/BSP/NUCLEO-N657X0-Q
    ${CUBE_ROOT}/Drivers/BSP/STM32N6570-Nucleo

    # ExtMem Manager from STM32CubeN6
    ${CUBE_ROOT}/Middlewares/ST/STM32_ExtMem_Manager
    ${CUBE_ROOT}/Middlewares/ST/STM32_ExtMem_Manager/boot
    ${CUBE_ROOT}/Middlewares/ST/STM32_ExtMem_Manager/nor_sfdp
    ${CUBE_ROOT}/Middlewares/ST/STM32_ExtMem_Manager/sal
)

# ---- Compiler flags ---------------------------------------------------------
target_compile_options(fsbl PRIVATE
    -Wall
    -Wextra
    -Wno-unused-parameter
    -fdata-sections
    -ffunction-sections
    -fno-common

    # Debug
    $<$<CONFIG:Debug>:-Og -g3 -gdwarf-4>

    # Release
    $<$<CONFIG:Release>:-Os>
    $<$<CONFIG:RelWithDebInfo>:-Os -g3 -gdwarf-4>
)

# ---- Linker -----------------------------------------------------------------
set(LINKER_SCRIPT
    "${CMAKE_CURRENT_LIST_DIR}/linker/STM32N657XX_AXISRAM2_fsbl.ld"
)

target_link_options(fsbl PRIVATE
    -T${LINKER_SCRIPT}
    -Wl,--gc-sections
    -Wl,--print-memory-usage
    -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/fsbl.map
)

# Force re-link when the linker script changes
set_target_properties(fsbl PROPERTIES
    LINK_DEPENDS "${LINKER_SCRIPT}"
    SUFFIX       ".elf"
)

# =============================================================================
# Post-build: generate .bin / .hex, print size
# =============================================================================

set(BIN_FILE ${CMAKE_CURRENT_BINARY_DIR}/fsbl.bin)
set(HEX_FILE ${CMAKE_CURRENT_BINARY_DIR}/fsbl.hex)

add_custom_command(TARGET fsbl POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:fsbl> ${BIN_FILE}
    COMMAND ${CMAKE_OBJCOPY} -O ihex   $<TARGET_FILE:fsbl> ${HEX_FILE}
    COMMAND ${CMAKE_SIZE}    --format=berkeley $<TARGET_FILE:fsbl>
    COMMENT ">> Generating fsbl.bin and fsbl.hex"
    VERBATIM
)

# =============================================================================
# Optional: FSBL signing (requires STM32_SigningTool_CLI in PATH)
# =============================================================================
option(SIGN_FSBL "Sign the FSBL binary with STM32_SigningTool_CLI" OFF)

if(SIGN_FSBL)
    find_program(SIGNING_TOOL STM32_SigningTool_CLI)
    if(NOT SIGNING_TOOL)
        message(WARNING "STM32_SigningTool_CLI not found — FSBL will not be signed")
    else()
        set(TRUSTED_BIN ${CMAKE_CURRENT_BINARY_DIR}/fsbl-trusted.bin)
        add_custom_command(TARGET fsbl POST_BUILD
            COMMAND ${SIGNING_TOOL}
                -bin ${BIN_FILE}
                -nk
                -of 0x80000000
                -t fsbl
                -o ${TRUSTED_BIN}
                -hv 2.3
            COMMENT ">> Signing FSBL → fsbl-trusted.bin"
            VERBATIM
        )
    endif()
endif()

# =============================================================================
# Custom target: flash (convenience)
# =============================================================================
find_program(PROGRAMMER STM32_Programmer_CLI)

if(PROGRAMMER)
    # Adjust the external loader path for your installation
    set(EXT_LOADER "" CACHE FILEPATH
        "Path to .stldr external loader for NUCLEO-N657X0-Q (MX25UM51245G)"
    )

    add_custom_target(flash
        COMMAND ${PROGRAMMER}
            -c port=SWD mode=HOTPLUG
            $<$<BOOL:${EXT_LOADER}>:-el$<SEMICOLON>${EXT_LOADER}>
            -hardRst
            -w ${CMAKE_CURRENT_BINARY_DIR}/fsbl-trusted.bin 0x70000000
        DEPENDS fsbl
        COMMENT ">> Flashing fsbl-trusted.bin to external flash @ 0x70000000"
        VERBATIM
    )
endif()
