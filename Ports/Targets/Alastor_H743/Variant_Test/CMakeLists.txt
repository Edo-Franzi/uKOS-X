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
	Alastor_H743_Variant_Test
	VERSION 1.0
	LANGUAGES C
)

# Microcontroller description (mandatory variables)
set(SOC STM32H743)
set(CORE CORTEX_M7)

# Customisation of firmware copyright text
add_compile_definitions(
	"uKOS_NAME="
	"uKOS_OWNER=(c) LvA"
)

# Flash programming script selection
set(BURN jtag_FT4232_b)

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
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/battery/battery.c CONFIG_MAN_BATTERY_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/i2c/i2c.c CONFIG_MAN_I2C_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/i2c0/i2c0.c CONFIG_MAN_I2C0_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/i2c1/i2c1.c CONFIG_MAN_I2C1_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/imager/imager.c CONFIG_MAN_IMAGER_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/imu/imu.c CONFIG_MAN_IMU_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/led/led.c CONFIG_MAN_LED_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/spi/spi.c CONFIG_MAN_SPI_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/spi0/spi0.c CONFIG_MAN_SPI0_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/spi1/spi1.c CONFIG_MAN_SPI1_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/switch/switch.c CONFIG_MAN_SWITCH_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/temperature/temperature.c CONFIG_MAN_TEMPERATURE_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_peripherals/watchdog/watchdog.c CONFIG_MAN_WATCHDOG_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_serials/serial/serial.c CONFIG_MAN_SERIAL_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_serials/urt0/urt0.c CONFIG_MAN_URT0_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_serials/urt1/urt1.c CONFIG_MAN_URT1_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_serials/urt2/urt2.c CONFIG_MAN_URT2_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_serials/urt3/urt3.c CONFIG_MAN_URT3_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_serials/wfi0/wfi0.c CONFIG_MAN_WFI0_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_storages/storage/storage.c CONFIG_MAN_STORAGE_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_storages/sdcard/sdcard.c CONFIG_MAN_SDCARD_S)
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_storages/serialFlash/serialFlash.c CONFIG_MAN_SERIAL_FLASH_S)
list(APPEND LIBX_P
	${PATH_BASE}/Lib_cryptographics/random/stub_random.c
	${PATH_BASE}/Lib_generics/machine/stub_machine.c
	${PATH_BASE}/Lib_peripherals/battery/stub_battery_bq27510g3.c
	${PATH_BASE}/Lib_peripherals/i2c0/stub_i2c0_si2c2.c
	${PATH_BASE}/Lib_peripherals/i2c1/stub_i2c1_si2c1.c
	${PATH_BASE}/Lib_peripherals/led/stub_led.c
	${PATH_BASE}/Lib_peripherals/spi0/stub_spi0_sspi2.c
	${PATH_BASE}/Lib_peripherals/spi1/stub_spi1_sspi4.c
	${PATH_BASE}/Lib_peripherals/switch/stub_switch.c
	${PATH_BASE}/Lib_peripherals/watchdog/stub_watchdog.c
	${PATH_VARI}/Lib_peripherals/imager/stub_imager_mt9v03x.c
	${PATH_VARI}/Lib_peripherals/imu/stub_imu_lsm9ds1.c
	${PATH_VARI}/Lib_peripherals/temperature/stub_temperature_lsm9ds1.c
	${PATH_BASE}/Lib_serials/urt0/stub_urt0_usart2.c
	${PATH_BASE}/Lib_serials/urt1/stub_urt1_usart3.c
	${PATH_BASE}/Lib_serials/urt2/stub_urt2_usart1.c
	${PATH_BASE}/Lib_serials/urt3/stub_urt3_uart4.c
	${PATH_BASE}/Lib_serials/wfi0/stub_wfi0_usart1_esp32_wifi_AP.c
	${PATH_BASE}/Lib_storages/sdcard/stub_sdcard.c
	${PATH_BASE}/Lib_storages/serialFlash/stub_serialFlash.c
)
add_library(libx_p ${LIBX_P})
target_link_libraries(libx_p PUBLIC system_compiler_flags)

# Lib_xxxx components (user) -> liblibx_u.a
add_source_with_define(LIBX_U ${PATH_UKOS}/OS/Lib_generics/newlib/newlib.c CONFIG_MAN_NEWLIB_S)
add_source_with_define(LIBX_U ${PATH_UKOS}/OS/Lib_generics/text/text.c CONFIG_MAN_TEXT_S)
add_source_with_define(LIBX_U ${PATH_UKOS}/OS/Lib_neurals/mlpn/mlpn.c CONFIG_MAN_MLPN_S)
add_library(libx_u ${LIBX_U})
target_link_libraries(libx_u PUBLIC system_compiler_flags)

# Shared components (privileged) -> libshar_p.a
list(APPEND SHAR_P
	${PATH_VARI}/Shared/shared_spi0/shared_spi0.c
)
add_library(shar_p ${SHAR_P})
target_link_libraries(shar_p PUBLIC system_compiler_flags)

# Process components (privileged) -> libproc_p.a
list(APPEND PROC_P
	${PATH_UKOS}/OS/Daemons/idle/idle.c
	${PATH_UKOS}/OS/Daemons/rtc/rtc.c
	${PATH_UKOS}/OS/Daemons/stack/stack.c
	${PATH_UKOS}/OS/Daemons/stimer/stimer.c
)
add_library(proc_p ${PROC_P})
target_link_libraries(proc_p PUBLIC system_compiler_flags)

# Process components (user) -> libproc_u.a
list(APPEND PROC_U
	${PATH_UKOS}/OS/Processes/alive/alive.c
	${PATH_UKOS}/OS/Processes/getTemp/getTemp.c
	${PATH_UKOS}/OS/Processes/launcher/launcher.c
	${PATH_UKOS}/OS/Processes/startUp/startUp.c
	${PATH_BASE}/Processes/alive/stub_alive.c
	${PATH_VARI}/Processes/startUp/stub_startUp.c
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
	${PATH_UKOS}/OS/CLI/esp32/esp32.c
	${PATH_UKOS}/OS/CLI/fill/fill.c
	${PATH_UKOS}/OS/CLI/gdb/gdb.c
	${PATH_UKOS}/OS/CLI/hexloader/hexloader.c
	${PATH_UKOS}/OS/CLI/kill/kill.c
	${PATH_UKOS}/OS/CLI/list/list.c
	${PATH_UKOS}/OS/CLI/man/man.c
	${PATH_UKOS}/OS/CLI/memck/memck.c
	${PATH_UKOS}/OS/CLI/memory/memory.c
	${PATH_UKOS}/OS/CLI/microPython/microPython.c
	${PATH_UKOS}/OS/CLI/mutex/mutex.c
	${PATH_UKOS}/OS/CLI/object/object.c
	${PATH_UKOS}/OS/CLI/power/power.c
	${PATH_UKOS}/OS/CLI/process/process.c
	${PATH_UKOS}/OS/CLI/restart/restart.c
	${PATH_UKOS}/OS/CLI/rnd/rnd.c
	${PATH_UKOS}/OS/CLI/run/run.c
	${PATH_UKOS}/OS/CLI/semaphore/semaphore.c
	${PATH_UKOS}/OS/CLI/sloader/sloader.c
	${PATH_UKOS}/OS/CLI/szkern/szkern.c
	${PATH_UKOS}/OS/CLI/test_malloc/test_malloc.c
	${PATH_UKOS}/OS/CLI/test_ram/test_ram.c
	${PATH_UKOS}/OS/CLI/test_sdcard/test_sdcard.c
	${PATH_UKOS}/OS/CLI/uKOS/uKOS.c
	${PATH_UKOS}/OS/CLI/wki2c/wki2c.c
	${PATH_UKOS}/OS/CLI/wkserial/wkserial.c
	${PATH_UKOS}/OS/CLI/wkspi/wkspi.c
	${PATH_UKOS}/OS/CLI/X/X.c
)
add_library(tool_u ${CLI_U})
target_link_libraries(tool_u PUBLIC system_compiler_flags)

# MicroPython Engine integration (MicroPython manager)
add_compile_definitions(CONFIG_MAN_MICROPYTHON_S)
find_library(MICROPYTHON MicroPython ${PATH_UKOS}/Third_Parties/MicroPython/Library/${CORE})
file(APPEND "System/FLASH.cnf" "-DCONFIG_MAN_MICROPYTHON_S ")

# FATFS (File system) integration
add_compile_definitions(CONFIG_MAN_FATFS_S)
find_library(FATFS FatFs ${PATH_UKOS}/Third_Parties/FatFs/Library/${CORE})
file(APPEND "System/FLASH.cnf" "-DCONFIG_MAN_FATFS_S ")

# All library components
set(UKOS_COMPONENTS rtcb_p kern_p kern_u libx_p libx_u shar_p proc_p proc_u tool_u ${MICROPYTHON} ${FATFS})

# System configuration flags

# Statistics support
add_compile_definitions(KKERN_WITH_STATISTICS_S=true)

# Record Log & trace
add_compile_definitions(
	KRECORD_SZ_LOG_BUF=100
	KRECORD_SZ_TRACE_FIFO=100
)

# SPI MMX support
add_compile_definitions(KGLOBAL_WITH_MMX1_S=false)

# Stack integrity monitoring
add_compile_definitions(
	KDAEMONS_ALERT_STACK_INT_S=false
	KDAEMONS_TIME_STACK_INT=10000
	KDAEMONS_WITH_STACK_INT_S=true
)

# Hardware RTC support
add_compile_definitions(KCALENDAR_WITH_HW_RTC_S=true)

# Apply system configuration
include(system)
