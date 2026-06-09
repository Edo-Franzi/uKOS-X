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

include(select-riscv-toolchain)

project(
	MAiXDUiNO_K210_Variant_Test
	VERSION 1.0
	LANGUAGES C ASM
)

# Microcontroller description (mandatory variables)
set(SOC K210)
set(CORE RV64IMAFDC)

# Apply project settings
include(proj_config)

# Customisation of firmware copyright text
add_compile_definitions(
	"uKOS_NAME="
	"uKOS_OWNER=(c) LvA"
)

# Flash programming script selection
set(BURN kflash_maixduino)

# Extra compilation options
add_compile_options(
	-g3 # include extra information for debugger
	-Os # optimisation
)

# Graphical display
set(DISPLAY TFT_2_4_Inches)

# Sources
# -------

# First piece of code (privileged)
set(FIRST_P
	${PATH_PORT}/EquatesModels/SOCs/${SOC}/Runtime/first.c
	${PATH_PORT}/EquatesModels/SOCs/${SOC}/Runtime/vectors.S
)

# Runtime & common components (privileged) -> librtcb_p.a
add_library(rtcb_p)
target_sources(rtcb_p PRIVATE
	${PATH_OSYS}/Boots/boot/boot.c
	${PATH_PORT}/EquatesModels/Generic/Runtime/crt0_r_mc.c
	${PATH_BASE}/Runtime/cmns.c
	${PATH_BASE}/Runtime/exce.c
	${PATH_VARI}/Runtime/init.c
)
target_link_libraries(rtcb_p PUBLIC system_compiler_flags)

# uKernel components (privileged) -> libkern_p.a
add_library(kern_p)
target_sources(kern_p PRIVATE
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
target_link_libraries(kern_p PUBLIC system_compiler_flags)

# uKernel components (user) -> libkern_u.a
add_library(kern_u)
target_sources(kern_u PRIVATE
	${PATH_OSYS}/Lib_kernels/kern/privileges.c
	${PATH_OSYS}/Lib_kernels/kern/xLibrary.c
)
target_link_libraries(kern_u PUBLIC system_compiler_flags)

# Lib_xxxx components (privileged) -> liblibx_p.a
add_library(libx_p)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_cryptographics/random/random.c CONFIG_MAN_RANDOM_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_generics/asmp/asmp.c CONFIG_MAN_ASMP_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_generics/calendar/calendar.c CONFIG_MAN_CALENDAR_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_generics/machine/machine.c CONFIG_MAN_MACHINE_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_generics/memo/memo.c CONFIG_MAN_MEMO_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_generics/record/record.c CONFIG_MAN_RECORD_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_generics/system/system.c CONFIG_MAN_SYSTEM_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_peripherals/led/led.c CONFIG_MAN_LED_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_peripherals/switch/switch.c CONFIG_MAN_SWITCH_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_serials/serial/serial.c CONFIG_MAN_SERIAL_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_serials/urt0/urt0.c CONFIG_MAN_URT0_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_serials/urt1/urt1.c CONFIG_MAN_URT1_S)
add_source_with_define(libx_p ${PATH_OSYS}/Lib_serials/wfi0/wfi0.c CONFIG_MAN_WFI0_S)
target_sources(libx_p PRIVATE
	${PATH_BASE}/Lib_cryptographics/random/stub_random.c
	${PATH_BASE}/Lib_generics/asmp/stub_asmp_msip.c
	${PATH_BASE}/Lib_generics/machine/stub_machine.c
	${PATH_BASE}/Lib_peripherals/imgk/imgk.c
	${PATH_BASE}/Lib_peripherals/lcd0/lcd0.c
	${PATH_BASE}/Lib_peripherals/led/stub_led.c
	${PATH_BASE}/Lib_peripherals/oct0/oct0.c
	${PATH_BASE}/Lib_peripherals/switch/stub_switch.c
	${PATH_BASE}/Lib_peripherals/tft0/tft0.c
	${PATH_BASE}/Lib_serials/urt0/stub_urt0_uart.c
	${PATH_BASE}/Lib_serials/urt1/stub_urt1_uart.c
	${PATH_BASE}/Lib_serials/wfi0/stub_wfi0_urt1.c
)
target_link_libraries(libx_p PUBLIC system_compiler_flags)

# Lib_xxxx components (user) -> liblibx_u.a
add_library(libx_u)
add_source_with_define(libx_u ${PATH_OSYS}/Lib_generics/newlib/newlib.c CONFIG_MAN_NEWLIB_S)
add_source_with_define(libx_u ${PATH_OSYS}/Lib_generics/text/text.c CONFIG_MAN_TEXT_S)
add_source_with_define(libx_u ${PATH_OSYS}/Lib_neurals/mlpn/mlpn.c CONFIG_MAN_MLPN_S)
target_link_libraries(libx_u PUBLIC system_compiler_flags)

# Process components (privileged) -> libproc_p.a
add_library(proc_p)
target_sources(proc_p PRIVATE
	${PATH_OSYS}/Daemons/idle/idle.c
	${PATH_OSYS}/Daemons/mcore/mcore.c
	${PATH_OSYS}/Daemons/stack/stack.c
	${PATH_OSYS}/Daemons/stimer/stimer.c
)
target_link_libraries(proc_p PUBLIC system_compiler_flags)

# Process components (user) -> libproc_u.a
add_library(proc_u)
target_sources(proc_u PRIVATE
	${PATH_OSYS}/Processes/alive/alive.c
	${PATH_OSYS}/Processes/launcher/launcher.c
	${PATH_OSYS}/Processes/startUp/startUp.c
	${PATH_BASE}/Processes/alive/stub_alive.c
	${PATH_VARI}/Processes/startUp/stub_startUp.c
)
target_link_libraries(proc_u PUBLIC system_compiler_flags)

# CLI components (user) -> libtool_u.a
add_library(tool_u)
target_sources(tool_u PRIVATE
	${PATH_OSYS}/CLI/bangla/BaNgLa.c
	${PATH_OSYS}/CLI/bench/bench.c
	${PATH_OSYS}/CLI/bench/bench_00.c
	${PATH_OSYS}/CLI/bench/bench_01.c
	${PATH_OSYS}/CLI/bench/bench_02.c
	${PATH_OSYS}/CLI/bench/bench_03.c
	${PATH_OSYS}/CLI/bench/bench_04.c
	${PATH_OSYS}/CLI/bench/bench_05.c
	${PATH_OSYS}/CLI/console/console.c
	${PATH_OSYS}/CLI/cycle/cycle.c
	${PATH_OSYS}/CLI/date/date.c
	${PATH_OSYS}/CLI/dump/dump.c
	${PATH_OSYS}/CLI/dumplog/dumplog.c
	${PATH_OSYS}/CLI/dumpshared/dumpshared.c
	${PATH_OSYS}/CLI/dumptrace/dumptrace.c
	${PATH_OSYS}/CLI/echo/echo.c
	${PATH_BASE}/CLI/esp32/esp32.c
	${PATH_OSYS}/CLI/fill/fill.c
	${PATH_OSYS}/CLI/gdb/gdb.c
	${PATH_OSYS}/CLI/hexloader/hexloader.c
	${PATH_OSYS}/CLI/kill/kill.c
	${PATH_OSYS}/CLI/list/list.c
	${PATH_OSYS}/CLI/man/man.c
	${PATH_OSYS}/CLI/memck/memck.c
	${PATH_OSYS}/CLI/memory/memory.c
	${PATH_OSYS}/CLI/microPython/microPython.c
	${PATH_OSYS}/CLI/mutex/mutex.c
	${PATH_OSYS}/CLI/object/object.c
	${PATH_OSYS}/CLI/process/process.c
	${PATH_OSYS}/CLI/rnd/rnd.c
	${PATH_OSYS}/CLI/run/run.c
	${PATH_OSYS}/CLI/semaphore/semaphore.c
	${PATH_OSYS}/CLI/sloader/sloader.c
	${PATH_OSYS}/CLI/test_malloc/test_malloc.c
	${PATH_OSYS}/CLI/test_mcore/test_mcore.c
	${PATH_OSYS}/CLI/uKOS/uKOS.c
	${PATH_BASE}/CLI/test_img/test_img.c
	${PATH_BASE}/CLI/test_ipi/test_ipi.c
	${PATH_BASE}/CLI/test_lcd/test_lcd.c
)
target_link_libraries(tool_u PUBLIC system_compiler_flags)

# All library components
set(UKOS_COMPONENTS rtcb_p kern_p kern_u libx_p libx_u proc_p proc_u tool_u)

# Optional manager
add_LVGL()

# Optional manager
add_MicroPython()

# System configuration flags

# Statistics support
add_compile_definitions(KKERN_WITH_STATISTICS_S=true)

# Baudrate
add_compile_definitions(KCOMM_DEFAULT_BAUDRATE=115200)

# SPI MMX support
add_compile_definitions(KGLOBAL_WITH_MMX1_S=false)

# Stack integrity monitoring
add_compile_definitions(
	KDAEMONS_ALERT_STACK_INT_S=false
	KDAEMONS_TIME_STACK_INT=10000
	KDAEMONS_WITH_STACK_INT_S=true
)

# Apply system configuration
include(system)
