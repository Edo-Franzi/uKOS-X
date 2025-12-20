# makefile.
# =========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for building the uKOS-X system.
#
#   (c) 2025-20xx, Edo. Franzi
#   --------------------------
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

SHELL			= /bin/sh

PATH_UKOS_X_PACKAGE	?= $(abspath ../../../../..)
PATH_UKOS			?= $(PATH_UKOS_X_PACKAGE)

# With the the time zone set for the Switzerland
# CET+1		!!! For CET+1, the string has to be CET-1
# CEST		Support the Summer day
# M3.5.0/2	Start summer day in March (3), 5th occurance (5) of Sunday (0) @ 2am (/2)
# M10.5.0/2	End summer day in October (10), 5th occurance (5) of Sunday (0) @ 2am (/2)
#
TZ_UTC_SHIFT	?= "CET-1"
FLAGS_USER		+= -DTZ_UTC_SHIFT=\"$(TZ_UTC_SHIFT)\"

TZ_DST_SPEC		?= "CEST,M3.5.0/2,M10.5.0/2"
FLAGS_USER		+= -DTZ_DST_SPEC=\"$(TZ_DST_SPEC)\"

# Project paths

# - PATH_MKFILE	--> System makefile location	--> OS_Kernel-X/Ports/Targets/$(BOARD)/$(V)/makefile
# - PATH_COMX	--> Commun folders				--> OS_Kernel-X/Ports/Targets/$(BOARD)/Base_CMx

# Paths overloaded

# - PATH_UKOS	PATH_UKOS ?= $(PATH_UKOS_X_PACKAGE)
# - PATH_PORT	PATH_PORT ?= $(PATH_UKOS_X_PACKAGE)/Ports
# - PATH_BASE	PATH_BASE ?= $(PATH_UKOS_X_PACKAGE)/Ports/Targets/$(BOARD)/Base
# - PATH_VARI	PATH_VARI ?= $(PATH_UKOS_X_PACKAGE)/Ports/Targets/$(BOARD)/$(V)
# - PATH_MAPP	PATH_MAPP ?= $(PATH_BASE)/Runtime

PATH_MKFILE				:= $(abspath $(lastword $(MAKEFILE_LIST)))
PATH_PORT				=  $(PATH_UKOS)/Ports

PATH_LIB_MICROPYTHON	=  $(PATH_UKOS)/Third_Parties/MicroPython/Library/$(CORE)
MICROPYTHON				=  libMicroPython

PATH_LIB_TINYUSB		=  $(PATH_UKOS)/Third_Parties/TinyUSB/Library/Family/$(FAMILY)/$(SOC)/$(PROFILE)
TINYUSB					=  libTinyUSB_$(SPEED)
PROVIDER				=  raspberrypi
FAMILY					=  pico2
SPEED					=  FS
PROFILE					=  cdc_cdc

PATH_INCLUDES			+= -I$(PATH_UKOS)/Third_Parties/TinyUSB/uKOS_Interface/Includes/mcu/$(PROVIDER)
PATH_INCLUDES			+= -I$(PATH_UKOS)/Third_Parties/TinyUSB/Library/Family/$(FAMILY)/$(SOC)/$(PROFILE)
PATH_INCLUDES			+= -I$(PATH_UKOS)/Third_Parties/TinyUSB/uKOS_Interface/OSAL
PATH_INCLUDES			+= -I$(PATH_UKOS)/Third_Parties/TinyUSB/TinyUSB-current/src

# Target & Infrastructure

# - VERSIONING	--> SVN
# - VERSIONING	--> GIT
# - VERSIONING	--> NONE

PREFIX			?=  arm-none-eabi-
COMPILER_FAMILY	?=  gcc

BOARD			=  Pico2_rp2350
V				=  Variant_Test
SOC				=  rp2350
CORE			=  CORTEX_M33
OPTIMISATION	=  -Os
VERSIONING		=  GIT
FLAGS_USER		+= -DuKOS_NAME=''
FLAGS_USER		+= -DuKOS_OWNER='(c) Edo. Franzi'
FLAGS_UKOS		+= -DSECURE_S
FLAGS_UKOS		+= -D__DYNAMIC_REENT__

BURN			?= picotool

# The really first pcs of code (privileged)

FIRST_P			=
FIRST_P			+=												$(PATH_PORT)/EquatesModels/SOCs/$(SOC)/Runtime/first.c
FIRST_P			+=												$(PATH_PORT)/EquatesModels/SOCs/$(SOC)/Runtime/picobin.c

# The runtime & commun components (privileged)

RTCB_P			=
RTCB_P			+=												$(PATH_PORT)/EquatesModels/Generic/Runtime/crt0.c
RTCB_P			+=												$(PATH_PORT)/EquatesModels/Cores/$(CORE)/Runtime/syscallDispatcher.c
RTCB_P			+=												$(PATH_VARI)/Runtime/init.c
RTCB_P			+=												$(PATH_BASE)/Runtime/exce.c
RTCB_P			+=												$(PATH_BASE)/Runtime/cmns.c
RTCB_P			+= $(PATH_UKOS)/OS/Boots/boot/boot.c

# The uKernel components (privileged)

KERN_P			=
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/kern.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/identifier.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/lists.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/processes.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/mutexes.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/pools.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/preciseSignals.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/scheduler.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/semaphores.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/signals.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/statistics.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/softwareTimers.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/debug.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/temporal.c
KERN_P			+= $(PATH_UKOS)/OS/Lib_kernels/kern/mailboxes.c
KERN_P			+=												$(PATH_BASE)/Lib_kernels/kern/stub_kern_kernel.c

# The uKernel components (user)

KERN_U			=
KERN_U			+= $(PATH_UKOS)/OS/Lib_kernels/kern/privileges.c
KERN_U			+= $(PATH_UKOS)/OS/Lib_kernels/kern/xLibrary.c

# The Lib_xxxx components (privileged)

LIBX_P			=

# With the LED manager
CONF_SYSTEM		+= -DCONFIG_MAN_LED_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_peripherals/led/led.c
# With the SWITCH manager
CONF_SYSTEM		+= -DCONFIG_MAN_SWITCH_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_peripherals/switch/switch.c
# With the ASMP manager
CONF_SYSTEM		+= -DCONFIG_MAN_ASMP_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_generics/asmp/asmp.c
# With the RECORD manager
CONF_SYSTEM		+= -DCONFIG_MAN_RECORD_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_generics/record/record.c
# With the MEMO manager
CONF_SYSTEM		+= -DCONFIG_MAN_MEMO_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_generics/memo/memo.c
# With the SYSTEM manager
CONF_SYSTEM		+= -DCONFIG_MAN_SYSTEM_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_generics/system/system.c
# With the MACHINE manager
CONF_SYSTEM		+= -DCONFIG_MAN_MACHINE_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_generics/machine/machine.c
# With the CALENDAR manager
CONF_SYSTEM		+= -DCONFIG_MAN_CALENDAR_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_generics/calendar/calendar.c
# With the SERIAL communication manager
CONF_SYSTEM		+= -DCONFIG_MAN_SERIAL_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_serials/serial/serial.c
# With the URT0 communication manager
CONF_SYSTEM		+= -DCONFIG_MAN_URT0_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_serials/urt0/urt0.c
# With the CDC0 communication manager
CONF_SYSTEM		+= -DCONFIG_MAN_CDC0_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_serials/cdc0/cdc0.c
# With the CDC1 communication manager
CONF_SYSTEM		+= -DCONFIG_MAN_CDC1_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_serials/cdc1/cdc1.c
# With the RANDOM manager
CONF_SYSTEM		+= -DCONFIG_MAN_RANDOM_S
LIBX_P			+= $(PATH_UKOS)/OS/Lib_cryptographics/random/random.c
LIBX_P			+= 												$(PATH_BASE)/Lib_peripherals/switch/stub_switch.c
LIBX_P			+= 												$(PATH_BASE)/Lib_peripherals/led/stub_led.c
LIBX_P			+= 												$(PATH_BASE)/Lib_generics/asmp/stub_asmp_dbell.c
LIBX_P			+= 												$(PATH_BASE)/Lib_generics/machine/stub_machine.c
LIBX_P			+= 												$(PATH_BASE)/Lib_serials/urt0/stub_urt0_uart.c
LIBX_P			+= 												$(PATH_BASE)/Lib_cryptographics/random/stub_random.c

# The Lib_xxxx components (user)

LIBX_U			=

# With the TEXT manager
CONF_SYSTEM		+= -DCONFIG_MAN_TEXT_S
LIBX_U			+= $(PATH_UKOS)/OS/Lib_generics/text/text.c
# With the NEWLIB manager
CONF_SYSTEM		+= -DCONFIG_MAN_NEWLIB_S
LIBX_U			+= $(PATH_UKOS)/OS/Lib_generics/newlib/newlib.c
# With the MLPN manager
CONF_SYSTEM		+= -DCONFIG_MAN_MLPN_S
LIBX_U			+= $(PATH_UKOS)/OS/Lib_neurals/mlpn/mlpn.c

# The shared components (privileged)

SHAR_P			=

# The process components (privileged)

PROC_P			=
PROC_P			+= $(PATH_UKOS)/OS/Daemons/idle/idle.c
PROC_P			+= $(PATH_UKOS)/OS/Daemons/stimer/stimer.c
PROC_P			+= $(PATH_UKOS)/OS/Daemons/stack/stack.c
PROC_P			+= $(PATH_UKOS)/OS/Daemons/mcore/mcore.c

# The process components (user)

PROC_U			=
PROC_U			+= $(PATH_UKOS)/OS/Processes/launcher/launcher.c
PROC_U			+= $(PATH_UKOS)/OS/Processes/alive/alive.c
PROC_U			+= $(PATH_UKOS)/OS/Processes/TinyUSB/TinyUSB.c
PROC_U			+= $(PATH_UKOS)/OS/Processes/startUp/startUp.c
PROC_U			+=  											$(PATH_BASE)/Processes/alive/stub_alive.c
PROC_U			+= 												$(PATH_VARI)/Processes/startUp/stub_startUp.c
PROC_U			+= 												$(PATH_VARI)/Processes/TinyUSB/stub_TinyUSB.c

# The CLI components (user)

CLI_U			=
CLI_U			+= $(PATH_UKOS)/OS/CLI/bangla/BaNgLa.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/console/console.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/cycle/cycle.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/dump/dump.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/dumplog/dumplog.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/dumptrace/dumptrace.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/echo/echo.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/fill/fill.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/gdb/gdb.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/hexloader/hexloader.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/kill/kill.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/list/list.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/man/man.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/memory/memory.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/microPython/microPython.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/mutex/mutex.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/object/object.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/process/process.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/restart/restart.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/rnd/rnd.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/run/run.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/semaphore/semaphore.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/sloader/sloader.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/szkern/szkern.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/uKOS/uKOS.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/wkserial/wkserial.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/test_mcore/test_mcore.c
CLI_U			+= $(PATH_UKOS)/OS/CLI/test_malloc/test_malloc.c

# All the uKOS-X library components

UKOS_FIRST_P	=  first.c picobin.c
UKOS_COMPONENTS	=  librtcb_p.a libkern_p.a libkern_u.a liblibx_p.a liblibx_u.a libshar_p.a libproc_p.a libproc_u.a libtool_u.a

# With the MicroPython manager (MicroPython Engine)
CONF_SYSTEM		+= -DCONFIG_MAN_MICROPYTHON_S
UKOS_COMPONENTS	+= $(MICROPYTHON).a

# With the TinyUSB library
CONF_SYSTEM		+= -DSYSTEM_TINYUSB_$(SPEED)_S
UKOS_COMPONENTS	+= $(TINYUSB).a

# The included makefiles

include	$(PATH_PORT)/Mkfiles/system.mk
include	$(PATH_PORT)/Mkfiles/$(COMPILER_FAMILY)_system_$(CORE).mk
-include $(wildcard *.d)

# With cdc0 on core 0 & urt0 on core 1
CONF_SYSTEM		+= -DCONFIG_DIFFERENT_SERIAL_PER_CORE_S=false

# With the statistic
CONF_SYSTEM		+= -DKKERN_WITH_STATISTICS_S=true

# With the stack integrity
CONF_SYSTEM		+= -DKDAEMONS_WITH_STACK_INT_S=true
CONF_SYSTEM		+= -DKDAEMONS_ALERT_STACK_INT_S=false
CONF_SYSTEM		+= -DKDAEMONS_TIME_STACK_INT=10000

# Number of precise signals
CONF_SYSTEM		+= -DKKERN_NB_PRECISE_SIGNALS=0
