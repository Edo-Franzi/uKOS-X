# llvm_system_RV64IMAFDC.
# =======================

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for uKOS-X systems (RV64IMAFDC specific).
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

ifndef PATH_LLVM_RVXX
$(error PATH_LLVM_RVXX is not defined)
endif

# Compiler flags

PATH_COMPILER	=  $(PATH_LLVM_RVXX)

CLANGVERS := $(shell $(PATH_COMPILER)/bin/clang -dumpversion | cut -f1 -d.)
CLANGVERS_GT_19 := $(shell [ $(CLANGVERS) -gt 19 ] && echo true)

CLANG_CFG		=  --target=riscv64-unknown-elf
CC				=  $(PATH_COMPILER)/bin/clang
CFLAGS			+= $(CLANG_CFG)
LDFLAGS			+= $(CLANG_CFG)

FLAGS_UKOS		+= -DUKOS_S -D$(BOARD)_S -D$(SOC)_S -D$(CORE)_S -DROMABLE_S
ifneq ($(KERNEL_OPT),)
FLAGS_UKOS		+= -D$(KERNEL_OPT)_S
endif

# This architecture does not support privileged/user spaces
# Even with USER_MODE=1 we remain in the privileged mode

MODE			=  _p

SWTCH_OBJDUMP	=  -f -p -D -d -h -t -s

FLAGS_FP		?= -mabi=lp64d
CPU_SPEC		?= -march=rv64imafdc -mcmodel=medany

C_CXX_FLAGS		+= $(CPU_SPEC) $(FLAGS_FP)
C_CXX_FLAGS		+= -g3 $(OPTIMISATION)
C_CXX_FLAGS		+= $(FLAGS_UKOS) $(FLAGS_USER)
C_CXX_FLAGS		+= $(PATH_INCLUDES)
C_CXX_FLAGS		+= -MMD

# Basic behaviour for the build
# -----------------------------

C_CXX_FLAGS		+= -fshort-enums
C_CXX_FLAGS		+= -fstack-usage
#C_CXX_FLAGS	+= -fstrict-volatile-bitfields		#NOTE: option unknown by clang
C_CXX_FLAGS		+= -ffast-math
C_CXX_FLAGS		+= -fno-math-errno
C_CXX_FLAGS		+= -fno-zero-initialized-in-bss
C_CXX_FLAGS		+= -ffunction-sections
C_CXX_FLAGS		+= -fdata-sections
C_CXX_FLAGS		+= -gdwarf-4

# Warnings for the build
# ----------------------

C_CXX_FLAGS		+= -Wall -Wextra -Wpedantic

# Exceptions

C_CXX_FLAGS		+= -Wno-main
C_CXX_FLAGS		+= -Wno-format
C_CXX_FLAGS		+= -Wno-format-security

# Additional checks

C_CXX_FLAGS		+= -Wconversion
C_CXX_FLAGS		+= -Wshadow
C_CXX_FLAGS		+= -Wunreachable-code

# Recommended for CERT C

C_CXX_FLAGS		+= -Wswitch-default
C_CXX_FLAGS		+= -Wcast-align
C_CXX_FLAGS		+= -Wcast-qual

# C specific flags

ASFLAGS			+= -g

CFLAGS			+= $(C_CXX_FLAGS)
CFLAGS			+= -Wstrict-prototypes
CFLAGS			+= -Wc++-compat

# CXX specific flags

CXXFLAGS		+= -fno-rtti
CXXFLAGS		+= -fno-exceptions
CXXFLAGS		+= $(C_CXX_FLAGS)

LINKS_LD		?= $(PATH_MAPP)/link${MODE}.lld

LDFLAGS			+= -L$(PATH_SOC)/Runtime
LDFLAGS			+= -L$(PATH_CORE)/Runtime
LDFLAGS			+= $(CPU_SPEC) $(FLAGS_FP)
LDFLAGS			+= -Wall
ifeq ($(CLANGVERS_GT_19),true)
LDFLAGS			+= -nostartfiles
endif
LDFLAGS			+= -T$(LINKS_LD)
LDFLAGS			+= -Wl,-Map=$(TARGET).map,--cref,--print-memory-usage

# Generate some useful & necessary files

ifeq ($(NOLISTING),)
utils : $(TARGET).lst $(TARGET).dis $(TARGET).bin $(TARGET).hex $(TARGET).ck $(TARGET).s3
else
utils : $(TARGET).bin $(TARGET).hex $(TARGET).ck $(TARGET).s3
endif

utilStack : $(TARGET).stack

ifneq ($(SHOW_INCLUDE_TREE),)
C_CXX_FLAGS		+= -H
endif

help_core :
	@echo "NOLISTING=1            Disable assembly listing generation."
	@echo "SHOW_INCLUDE_TREE=1    Show the compiler header include tree."

.PHONY: utils utilStack help_core
