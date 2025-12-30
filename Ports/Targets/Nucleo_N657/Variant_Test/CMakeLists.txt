# CMakeLists.
# ===========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		CMake file to set up the building for uKOS-X system.
#
#   (c) 2025-20xx, Laurent von Allmen
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

# uKOS-X CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../Mkfiles/cmake")

# Project path configuration
# - PATH_UKOS	--> Main uKOS-X folder
# - PATH_VARI	--> Projects Root Variant folder
# - PATH_BASE	--> Projects Root Base folder
# - PATH_PORT	--> PATH_UKOS/Ports
include(set-project-paths)

include(select-arm-toolchain)

project(
	Nucleo_N657_Variant_Test
	VERSION 1.0
	LANGUAGES C
)

# Microcontroller description (mandatory variables)
set(SOC STM32N657)
set(CORE CORTEX_M55)

# Customisation of firmware copyright text
add_compile_definitions(
	"uKOS_NAME="
	"uKOS_OWNER=(c) LvA"
	"SECURE_S"
	"__DYNAMIC_REENT__"
)

# Flash programming script selection
set(BURN secure)

# Apply project settings
include(proj_config)

# Extra compilation options
add_compile_options(
	-g3 # include extra information for debugger
	-Os # optimisation
)

# Sources
# -------

# First piece of code (privileged)
set(FIRST_P
	${PATH_PORT}/EquatesModels/SOCs/${SOC}/Runtime/first.c
)

# Runtime & common components (privileged) -> librtcb_p.a
list(APPEND RTCB_P
	${PATH_UKOS}/OS/Boots/boot/boot.c
	${PATH_PORT}/EquatesModels/Generic/Runtime/crt0.c
	${PATH_PORT}/EquatesModels/Cores/${CORE}/Runtime/syscallDispatcher.c
	${PATH_BASE}/Runtime/cmns.c
	${PATH_BASE}/Runtime/exce.c
	${PATH_VARI}/Runtime/init.c
)
add_library(rtcb_p ${RTCB_P})
target_link_libraries(rtcb_p PUBLIC system_compiler_flags)

# uKernel components (privileged) -> libkern_p.a
list(APPEND KERN_P
	${PATH_UKOS}/OS/Lib_kernels/kern/debug.c
	${PATH_UKOS}/OS/Lib_kernels/kern/identifier.c
	${PATH_UKOS}/OS/Lib_kernels/kern/kern.c
	${PATH_UKOS}/OS/Lib_kernels/kern/lists.c
	${PATH_UKOS}/OS/Lib_kernels/kern/mailboxes.c
	${PATH_UKOS}/OS/Lib_kernels/kern/mutexes.c
	${PATH_UKOS}/OS/Lib_kernels/kern/pools.c
	${PATH_UKOS}/OS/Lib_kernels/kern/preciseSignals.c
	${PATH_UKOS}/OS/Lib_kernels/kern/processes.c
	${PATH_UKOS}/OS/Lib_kernels/kern/scheduler.c
	${PATH_UKOS}/OS/Lib_kernels/kern/semaphores.c
	${PATH_UKOS}/OS/Lib_kernels/kern/signals.c
	${PATH_UKOS}/OS/Lib_kernels/kern/softwareTimers.c
	${PATH_UKOS}/OS/Lib_kernels/kern/statistics.c
	${PATH_UKOS}/OS/Lib_kernels/kern/temporal.c
	${PATH_BASE}/Lib_kernels/kern/stub_kern_kernel.c
)
add_library(kern_p ${KERN_P})
target_link_libraries(kern_p PUBLIC system_compiler_flags)

# uKernel components (user) -> libkern_u.a
list(APPEND KERN_U
	${PATH_UKOS}/OS/Lib_kernels/kern/privileges.c
	${PATH_UKOS}/OS/Lib_kernels/kern/xLibrary.c
)
add_library(kern_u ${KERN_U})
target_link_libraries(kern_u PUBLIC system_compiler_flags)

# Lib_xxxx components (privileged) -> liblibx_p.a
# (grouped by manager)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_cryptographics/random/random.c CONFIG_MAN_RANDOM_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_generics/calendar/calendar.c CONFIG_MAN_CALENDAR_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_generics/machine/machine.c CONFIG_MAN_MACHINE_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_generics/memo/memo.c CONFIG_MAN_MEMO_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_generics/record/record.c CONFIG_MAN_RECORD_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_generics/system/system.c CONFIG_MAN_SYSTEM_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/i2c/i2c.c CONFIG_MAN_I2C_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/i2c0/i2c0.c CONFIG_MAN_I2C0_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/i2c1/i2c1.c CONFIG_MAN_I2C1_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/led/led.c CONFIG_MAN_LED_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/spi/spi.c CONFIG_MAN_SPI_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/spi0/spi0.c CONFIG_MAN_SPI0_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/switch/switch.c CONFIG_MAN_SWITCH_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/watchdog/watchdog.c CONFIG_MAN_WATCHDOG_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_serials/cdc0/cdc0.c CONFIG_MAN_CDC0_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_serials/serial/serial.c CONFIG_MAN_SERIAL_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_serials/urt0/urt0.c CONFIG_MAN_URT0_S)
list(APPEND LIBX_P
	${PATH_BASE}/Lib_cryptographics/random/stub_random.c
	${PATH_BASE}/Lib_generics/machine/stub_machine.c
	${PATH_BASE}/Lib_peripherals/i2c0/stub_i2c0_si2c2.c
	${PATH_BASE}/Lib_peripherals/i2c1/stub_i2c1_si2c1.c
	${PATH_BASE}/Lib_peripherals/led/stub_led.c
	${PATH_BASE}/Lib_peripherals/spi0/stub_spi0_sspi4.c
	${PATH_BASE}/Lib_peripherals/switch/stub_switch.c
	${PATH_BASE}/Lib_peripherals/watchdog/stub_watchdog.c
	${PATH_BASE}/Lib_serials/urt0/stub_urt0_usart1.c
)
add_library(libx_p ${LIBX_P})
target_link_libraries(libx_p PUBLIC system_compiler_flags)

# Lib_xxxx components (user) -> liblibx_u.a
add_source_with_define(LIBX_U ${PATH_UKOS}/OS/Lib_generics/newlib/newlib.c CONFIG_MAN_NEWLIB_S)
add_source_with_define(LIBX_U ${PATH_UKOS}/OS/Lib_generics/text/text.c CONFIG_MAN_TEXT_S)
add_source_with_define(LIBX_U ${PATH_UKOS}/OS/Lib_neurals/mlpn/mlpn.c CONFIG_MAN_MLPN_S)
add_library(libx_u ${LIBX_U})
target_link_libraries(libx_u PUBLIC system_compiler_flags)

# Process components (privileged) -> libproc_p.a
list(APPEND PROC_P
	${PATH_UKOS}/OS/Daemons/idle/idle.c
	${PATH_UKOS}/OS/Daemons/stack/stack.c
	${PATH_UKOS}/OS/Daemons/stimer/stimer.c
)
add_library(proc_p ${PROC_P})
target_link_libraries(proc_p PUBLIC system_compiler_flags)

# Process components (user) -> libproc_u.a
list(APPEND PROC_U
	${PATH_UKOS}/OS/Processes/alive/alive.c
	${PATH_UKOS}/OS/Processes/launcher/launcher.c
	${PATH_UKOS}/OS/Processes/startUp/startUp.c
	${PATH_UKOS}/OS/Processes/TinyUSB/TinyUSB.c
	${PATH_BASE}/Processes/alive/stub_alive.c
	${PATH_VARI}/Processes/startUp/stub_startUp.c
	${PATH_VARI}/Processes/TinyUSB/stub_TinyUSB.c
)
add_library(proc_u ${PROC_U})
target_link_libraries(proc_u PUBLIC system_compiler_flags)

# CLI components (user) -> libtool_u.a
list(APPEND CLI_U
	${PATH_UKOS}/OS/CLI/bangla/BaNgLa.c
	${PATH_UKOS}/OS/CLI/bench/bench.c
	${PATH_UKOS}/OS/CLI/bench/bench_00.c
	${PATH_UKOS}/OS/CLI/bench/bench_01.c
	${PATH_UKOS}/OS/CLI/bench/bench_02.c
	${PATH_UKOS}/OS/CLI/bench/bench_03.c
	${PATH_UKOS}/OS/CLI/bench/bench_04.c
	${PATH_UKOS}/OS/CLI/bench/bench_05.c
	${PATH_UKOS}/OS/CLI/console/console.c
	${PATH_UKOS}/OS/CLI/cycle/cycle.c
	${PATH_UKOS}/OS/CLI/date/date.c
	${PATH_UKOS}/OS/CLI/dump/dump.c
	${PATH_UKOS}/OS/CLI/dumplog/dumplog.c
	${PATH_UKOS}/OS/CLI/dumptrace/dumptrace.c
	${PATH_UKOS}/OS/CLI/echo/echo.c
	${PATH_UKOS}/OS/CLI/fill/fill.c
	${PATH_UKOS}/OS/CLI/gdb/gdb.c
	${PATH_UKOS}/OS/CLI/hexloader/hexloader.c
	${PATH_UKOS}/OS/CLI/kill/kill.c
	${PATH_UKOS}/OS/CLI/list/list.c
	${PATH_UKOS}/OS/CLI/man/man.c
	${PATH_UKOS}/OS/CLI/memory/memory.c
	${PATH_UKOS}/OS/CLI/microPython/microPython.c
	${PATH_UKOS}/OS/CLI/mutex/mutex.c
	${PATH_UKOS}/OS/CLI/object/object.c
	${PATH_UKOS}/OS/CLI/process/process.c
	${PATH_UKOS}/OS/CLI/restart/restart.c
	${PATH_UKOS}/OS/CLI/rnd/rnd.c
	${PATH_UKOS}/OS/CLI/run/run.c
	${PATH_UKOS}/OS/CLI/semaphore/semaphore.c
	${PATH_UKOS}/OS/CLI/sloader/sloader.c
	${PATH_UKOS}/OS/CLI/szkern/szkern.c
	${PATH_UKOS}/OS/CLI/uKOS/uKOS.c
	${PATH_UKOS}/OS/CLI/viewer/viewer_uvc0_simule.c
	${PATH_UKOS}/OS/CLI/viewer/viewer.c
	${PATH_UKOS}/OS/CLI/wki2c/wki2c.c
	${PATH_UKOS}/OS/CLI/wkserial/wkserial.c
	${PATH_UKOS}/OS/CLI/wkspi/wkspi.c
)
add_library(tool_u ${CLI_U})
target_link_libraries(tool_u PUBLIC system_compiler_flags)

# MicroPython Engine integration (MicroPython manager)
add_compile_definitions(CONFIG_MAN_MICROPYTHON_S)
find_library(MICROPYTHON MicroPython ${PATH_UKOS}/Third_Parties/MicroPython/Library/${CORE})
file(APPEND "System/FLASH.cnf" "-DCONFIG_MAN_MICROPYTHON_S ")

# TinyUSB integration
set(PROVIDER st)
set(FAMILY n6)
set(SPEED HS)
set(PROFILE cdc_video)

set(PATH_TINYUSB ${PATH_UKOS}/Third_Parties/TinyUSB)
list(APPEND PATH_INCLUDES
	${PATH_TINYUSB}/uKOS_Interface/Includes/mcu/${PROVIDER}
	${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE}
	${PATH_TINYUSB}/uKOS_Interface/OSAL
	${PATH_TINYUSB}/TinyUSB-current/src
)
add_compile_definitions(SYSTEM_TINYUSB_${SPEED}_S)
find_library(TINYUSB TinyUSB_${SPEED} ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE})

# All library components
set(UKOS_COMPONENTS rtcb_p kern_p kern_u libx_p libx_u proc_p proc_u tool_u ${MICROPYTHON} ${TINYUSB})

# System configuration flags

# Statistics support
add_compile_definitions(KKERN_WITH_STATISTICS_S=true)

# Stack integrity monitoring
add_compile_definitions(
	KDAEMONS_ALERT_STACK_INT_S=false
	KDAEMONS_TIME_STACK_INT=10000
	KDAEMONS_WITH_STACK_INT_S=false
)

# Apply system configuration
include(system)
