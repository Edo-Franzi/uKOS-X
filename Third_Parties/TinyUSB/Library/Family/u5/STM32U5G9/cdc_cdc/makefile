# makefile.
# =========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for uKOS-X for building the libTinyUSB.a module.
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

SHELL			=  /bin/sh

ifndef PATH_UKOS_X_PACKAGE
    $(error PATH_UKOS_X_PACKAGE is not defined)
endif
ifndef PATH_GCC_ARM
    $(error PATH_GCC_ARM is not defined)
endif

ifeq ($(origin CC), default)
CC					=  $(PATH_COMPILER)/bin/$(PREFIX)gcc
AR					=  $(PATH_COMPILER)/bin/$(PREFIX)ar
ST					=  $(PATH_COMPILER)/bin/$(PREFIX)strip
endif

# Project paths

# - PATH_UKOS		--> Main uKOS-X folder			--> OS_Kernel-X
# - PATH_PORT		--> Main uKOS-X port folders	--> OS_Kernel-X/Ports
# - PATH_TINYUSB	--> TinyUSB package

PATH_UKOS			=  $(PATH_UKOS_X_PACKAGE)
PATH_TINYUSB		=  $(PATH_UKOS)/Third_Parties/TinyUSB

# Target & Infrastructure

PROVIDER			=  st
FAMILY				=  u5
CORE				=  CORTEX_M33
SOC					=  STM32U5G9
TINYUSB_FS			=  libTinyUSB_FS.a
TINYUSB_HS			=  libTinyUSB_HS.a
PROFILE				=  cdc_cdc

STANDARD			=  -std=c23
OPTIMISATION		=  -Os

PREFIX				?= arm-none-eabi-
PATH_COMPILER		=  $(PATH_GCC_ARM)
FLAGS_FP			=  -mfloat-abi=hard -mfpu=fpv5-sp-d16
CPU_SPEC			=  -mcpu=cortex-m33
FLAGS_UKOS			=  -DTHIRD_PARTY_S -D$(SOC)_S -DLITTLE_ENDIAN_S -DSECURE_S

# The included makefiles

include	$(PATH_TINYUSB)/Library/Family/Mkfiles/TinyUSB.mk
-include $(wildcard *.d)
.PHONY : all clr_all clr build archive
