# CMakeLists.
# ===========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		CMake file to set up the building for uKOS-X system.
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

# uKOS-X CMake module setup
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../../../Mkfiles/cmake")

# Project path configuration
# - PATH_UKOS	--> Main uKOS-X folder
# - PATH_OSYS	--> Main OS folder
# - PATH_VARI	--> Projects Root Variant folder
# - PATH_BASE	--> Projects Root Base folder
# - PATH_PORT	--> PATH_UKOS/Ports
include(set-project-paths)

include(select-arm-toolchain)

project(
	DevKit_nRF5340_Variant_Test_App
	VERSION 1.0
	LANGUAGES C
)

# Microcontroller description (mandatory variables)
set(SOC nRF5340)
set(CORE CORTEX_M33)

# Apply project settings
include(proj_config)

# Customisation of firmware copyright text
add_compile_definitions(
	"uKOS_NAME="
	"uKOS_OWNER=(c) LvA"
	"CPU_APPLICATION_S"
	"SECURE_S"
)

# Flash programming script selection
set(BURN jlinkexe)

# Extra compilation options
add_compile_options(
	-g3 # include extra information for debugger
	-Os # optimisation
)

# TinyUSB integration (must be before library definitions)
add_TinyUSB(
	SPEED FS
	PROFILE cdc_cdc
)

# Sources
# -------

# First piece of code (privileged)
set(FIRST_P
	${PATH_PORT}/EquatesModels/SOCs/${SOC}/Runtime/first.c
)

# Runtime & common components (privileged) -> librtcb_p.a
list(APPEND RTCB_P
	${PATH_OSYS}/Boots/boot/boot.c
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
	${PATH_OSYS}/Lib_kernels/kern/debug.c
	${PATH_OSYS}/Lib_kernels/kern/identifier.c
	${PATH_OSYS}/Lib_kernels/kern/kern.c
	${PATH_OSYS}/Lib_kernels/kern/lists.c
	${PATH_OSYS}/Lib_kernels/kern/mailboxes.c
	${PATH_OSYS}/Lib_kernels/kern/mutexes.c
	${PATH_OSYS}/Lib_kernels/kern/pools.c
	${PATH_OSYS}/Lib_kernels/kern/preciseSignals.c
	${PATH_OSYS}/Lib_kernels/kern/processes.c
	${PATH_OSYS}/Lib_kernels/kern/scheduler.c
	${PATH_OSYS}/Lib_kernels/kern/semaphores.c
	${PATH_OSYS}/Lib_kernels/kern/signals.c
	${PATH_OSYS}/Lib_kernels/kern/softwareTimers.c
	${PATH_OSYS}/Lib_kernels/kern/statistics.c
	${PATH_OSYS}/Lib_kernels/kern/temporal.c
	${PATH_BASE}/Lib_kernels/kern/stub_kern_kernel.c
)
add_library(kern_p ${KERN_P})
target_link_libraries(kern_p PUBLIC system_compiler_flags)

# uKernel components (user) -> libkern_u.a
list(APPEND KERN_U
	${PATH_OSYS}/Lib_kernels/kern/privileges.c
	${PATH_OSYS}/Lib_kernels/kern/xLibrary.c
)
add_library(kern_u ${KERN_U})
target_link_libraries(kern_u PUBLIC system_compiler_flags)

# Lib_xxxx components (privileged) -> liblibx_p.a
# (grouped by manager)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_cryptographics/random/random.c CONFIG_MAN_RANDOM_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_generics/asmp/asmp.c CONFIG_MAN_ASMP_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_generics/calendar/calendar.c CONFIG_MAN_CALENDAR_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_generics/machine/machine.c CONFIG_MAN_MACHINE_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_generics/memo/memo.c CONFIG_MAN_MEMO_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_generics/record/record.c CONFIG_MAN_RECORD_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_generics/system/system.c CONFIG_MAN_SYSTEM_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_peripherals/led/led.c CONFIG_MAN_LED_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_peripherals/switch/switch.c CONFIG_MAN_SWITCH_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_serials/cdc0/cdc0.c CONFIG_MAN_CDC0_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_serials/cdc1/cdc1.c CONFIG_MAN_CDC1_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_serials/serial/serial.c CONFIG_MAN_SERIAL_S)
add_source_with_define(LIBX_P ${PATH_OSYS}/Lib_serials/urt0/urt0.c CONFIG_MAN_URT0_S)
list(APPEND LIBX_P
	${PATH_BASE}/Lib_cryptographics/random/stub_random.c
	${PATH_BASE}/Lib_generics/machine/stub_machine.c
	${PATH_BASE}/Lib_peripherals/led/stub_led.c
	${PATH_BASE}/Lib_peripherals/switch/stub_switch.c
	${PATH_BASE}/Lib_serials/urt0/stub_urt0_uarte1.c
	${PATH_COMX}/Lib_generics/asmp/stub_asmp_ipc.c
)
add_library(libx_p ${LIBX_P})
target_link_libraries(libx_p PUBLIC system_compiler_flags ${TINYUSB})

# Lib_xxxx components (user) -> liblibx_u.a
add_source_with_define(LIBX_U ${PATH_OSYS}/Lib_generics/newlib/newlib.c CONFIG_MAN_NEWLIB_S)
add_source_with_define(LIBX_U ${PATH_OSYS}/Lib_generics/text/text.c CONFIG_MAN_TEXT_S)
add_source_with_define(LIBX_U ${PATH_OSYS}/Lib_neurals/mlpn/mlpn.c CONFIG_MAN_MLPN_S)
add_library(libx_u ${LIBX_U})
target_link_libraries(libx_u PUBLIC system_compiler_flags)

# Process components (privileged) -> libproc_p.a
list(APPEND PROC_P
	${PATH_OSYS}/Daemons/idle/idle.c
	${PATH_OSYS}/Daemons/mcore/mcore.c
	${PATH_OSYS}/Daemons/stack/stack.c
	${PATH_OSYS}/Daemons/stimer/stimer.c
)
add_library(proc_p ${PROC_P})
target_link_libraries(proc_p PUBLIC system_compiler_flags)

# Process components (user) -> libproc_u.a
list(APPEND PROC_U
	${PATH_OSYS}/Processes/alive/alive.c
	${PATH_OSYS}/Processes/launcher/launcher.c
	${PATH_OSYS}/Processes/startUp/startUp.c
	${PATH_OSYS}/Processes/TinyUSB/TinyUSB.c
	${PATH_BASE}/Processes/alive/stub_alive.c
	${PATH_VARI}/Processes/startUp/stub_startUp.c
	${PATH_BASE}/Processes/TinyUSB/stub_TinyUSB.c
)
add_library(proc_u ${PROC_U})
target_link_libraries(proc_u PUBLIC system_compiler_flags ${TINYUSB})

# CLI components (user) -> libtool_u.a
list(APPEND CLI_U
	${PATH_OSYS}/CLI/bangla/BaNgLa.c
	${PATH_OSYS}/CLI/console/console.c
	${PATH_OSYS}/CLI/cycle/cycle.c
	${PATH_OSYS}/CLI/date/date.c
	${PATH_OSYS}/CLI/dump/dump.c
	${PATH_OSYS}/CLI/dumplog/dumplog.c
	${PATH_OSYS}/CLI/dumptrace/dumptrace.c
	${PATH_OSYS}/CLI/echo/echo.c
	${PATH_OSYS}/CLI/fill/fill.c
	${PATH_OSYS}/CLI/hexloader/hexloader.c
	${PATH_OSYS}/CLI/kill/kill.c
	${PATH_OSYS}/CLI/list/list.c
	${PATH_OSYS}/CLI/man/man.c
	${PATH_OSYS}/CLI/memory/memory.c
	${PATH_OSYS}/CLI/microPython/microPython.c
	${PATH_OSYS}/CLI/mutex/mutex.c
	${PATH_OSYS}/CLI/object/object.c
	${PATH_OSYS}/CLI/process/process.c
	${PATH_OSYS}/CLI/restart/restart.c
	${PATH_OSYS}/CLI/rnd/rnd.c
	${PATH_OSYS}/CLI/run/run.c
	${PATH_OSYS}/CLI/semaphore/semaphore.c
	${PATH_OSYS}/CLI/sloader/sloader.c
	${PATH_OSYS}/CLI/szkern/szkern.c
	${PATH_OSYS}/CLI/test_mcore/test_mcore.c
	${PATH_OSYS}/CLI/uKOS/uKOS.c
	${PATH_OSYS}/CLI/wkserial/wkserial.c
)
add_library(tool_u ${CLI_U})
target_link_libraries(tool_u PUBLIC system_compiler_flags)

# All library components
set(UKOS_COMPONENTS rtcb_p kern_p kern_u libx_p libx_u proc_p proc_u tool_u ${TINYUSB})

# Optional manager
add_MicroPython()

# System configuration flags

# Statistics support
add_compile_definitions(KKERN_WITH_STATISTICS_S=true)

# Hardware check of the stack
add_compile_definitions(STUB_KERN_CHECK_XSP_LIMIT_S)

# Stack integrity monitoring
add_compile_definitions(
	KDAEMONS_ALERT_STACK_INT_S=false
	KDAEMONS_TIME_STACK_INT=10000
	KDAEMONS_WITH_STACK_INT_S=true
)

# Apply system configuration
include(system)
