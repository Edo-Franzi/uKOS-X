# gcc_application_CORTEX_M7.
# ==========================

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for uKOS-X applications (cortex-m7 specific).
#
#   (c) 2025-2026, Edo. Franzi
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

ifndef PATH_GCC_ARM
$(error PATH_GCC_ARM is not defined)
endif

# Compiler flags

PATH_COMPILER	=  $(PATH_GCC_ARM)

FLAGS_UKOS		=  -DUKOS_S -D$(BOARD)_S -D$(SOC)_S -D$(CORE)_S
ifneq ($(USER_MODE),0)
FLAGS_UKOS		+= -DPRIVILEGED_USER_S
endif

SWTCH_OBJDUMP	= -d -S -h -t

GPPCOMPILER		=  $(PATH_COMPILER)/bin/$(PREFIX)g++
GPPLDOPTION		=  -lc -lstdc++

FLAGS_FP		?= -mfloat-abi=hard -mfpu=fpv5-sp-d16
CPU_SPEC		?= -mcpu=cortex-m7 -mthumb

C_CXX_FLAGS		+= $(CPU_SPEC) $(FLAGS_FP)
C_CXX_FLAGS		+= -g3 $(OPTIMISATION)
C_CXX_FLAGS		+= $(FLAGS_UKOS) $(FLAGS_USER)
C_CXX_FLAGS		+= $(PATH_INCLUDES)
C_CXX_FLAGS		+= -MMD

# Basic behaviour for the build
# -----------------------------

C_CXX_FLAGS		+= -fshort-enums
C_CXX_FLAGS		+= -fstack-usage
C_CXX_FLAGS		+= -mpoke-function-name

# Warnings for the build
# ----------------------

C_CXX_FLAGS		+= -Wall -Wextra -Wpedantic

# Exceptions

C_CXX_FLAGS		+= -Wno-main

# Additional checks

C_CXX_FLAGS		+= -Wconversion
C_CXX_FLAGS		+= -Wshadow
C_CXX_FLAGS		+= -Wunreachable-code

# Recommended for CERT C

C_CXX_FLAGS		+= -Wswitch-default
C_CXX_FLAGS		+= -Wcast-align
C_CXX_FLAGS		+= -Wcast-qual
C_CXX_FLAGS		+= -Wformat-security

# For newlib

C_CXX_FLAGS		+= -D_MACHTIME_H_
C_CXX_FLAGS		+= -D_CLOCKS_PER_SEC_=1000000

# C specific flags

CFLAGS			+= $(C_CXX_FLAGS)
CFLAGS			+= -Wstrict-prototypes
CFLAGS			+= -Wc++-compat

# CXX specific flags

CXXFLAGS		+= -fno-rtti
CXXFLAGS		+= -fno-exceptions
CXXFLAGS		+= $(C_CXX_FLAGS)

LINKS_LD		?= $(PATH_MAPP)/link_App.ld

LDFLAGS			+= -L$(PATH_CORE)/Runtime
LDFLAGS			+= $(CPU_SPEC) $(FLAGS_FP)
LDFLAGS			+= -Wall -nostartfiles
LDFLAGS			+= -T$(LINKS_LD)
LDFLAGS			+= -Wl,-Map=$(TARGET).map,--cref,--print-memory-usage -Wl,--no-warn-rwx-segment

# Generate some useful & necessary files

ifeq ($(NOLISTING),)
utils : $(TARGET).lst $(TARGET).dis $(TARGET).bin $(TARGET).hex $(TARGET).s3
else
utils : $(TARGET).bin $(TARGET).hex $(TARGET).s3
endif

utilStack : $(TARGET).stack

ifneq ($(SHOW_INCLUDE_TREE),)
C_CXX_FLAGS		+= -H
endif

help_core :
	@echo "NOLISTING=1            Disable assembly listing generation."
	@echo "SHOW_INCLUDE_TREE=1    Show the compiler header include tree."

.PHONY: utils utilStack help_core
