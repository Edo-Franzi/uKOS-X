# makefile.
# =========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen 	The 2026-02-16
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for building the testROM
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

SHELL			= /bin/sh

ifeq ($(VERBOSE),1)
    Q :=
else
    Q := @
endif
MAKEFLAGS		+= --no-print-directory

ifndef PATH_GCC_RVXX
$(error PATH_GCC_RVXX is not defined)
endif

PATH_TEST_ROM	?= $(abspath ../)
PATH_COMPILER	?= $(PATH_GCC_RVXX)
PREFIX			?= riscv64-unknown-elf-
COMPILER_FAMILY	?= gcc

TARGET			=  testROM
BOARD			=  Pico2_rp2350_RV32IMAC
TEST_NUMBER		?= 00

PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/_Commun
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/_Commun/Includes
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/_Commun/Runtime
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/$(BOARD)
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/$(BOARD)/Includes
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/$(BOARD)/Includes/SOC
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/$(BOARD)/Includes/Core
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/$(BOARD)/Runtime

OBJ				=  first_rv.o picobin.o init.o cmns.o tests.o
OBJ				+= ../_Commun/Runtime/crt0.o

# Target & Infrastructure

CC				=  $(PATH_COMPILER)/bin/$(PREFIX)gcc
AS				=  $(PATH_COMPILER)/bin/$(PREFIX)as
OBJCOPY			=  $(PATH_COMPILER)/bin/$(PREFIX)objcopy
OBJDUMP			=  $(PATH_COMPILER)/bin/$(PREFIX)objdump

FLAGS_FP		?= -mabi=ilp32
CPU_SPEC		?= -march=rv32imac_zicsr_zifencei

CFLAGS			+= $(CPU_SPEC) $(FLAGS_FP)
CFLAGS			+= -c -g -Os
CFLAGS			+= $(PATH_INCLUDES)
CFLAGS			+= -MMD
CFLAGS			+= -DCACHE_D_S -DSECURE_S
CFLAGS			+= -DBOARD_Pico2=true
CFLAGS			+= -DBOARD_Pico2W=false
CFLAGS			+= -DTEST_$(TEST_NUMBER)_S

CFLAGS			+= -Wall
CFLAGS			+= -Wlogical-op

LINKS_LD		=  Runtime/link_p.ld

LDFLAGS			+= $(CPU_SPEC) $(FLAGS_FP)
LDFLAGS			+= -Wall -nostartfiles
LDFLAGS			+= -T$(LINKS_LD)
LDFLAGS			+= -Wl,-Map=$(TARGET).map,--cref,--print-memory-usage -Wl,--no-warn-rwx-segment

SWTCH_OBJDUMP	=  -f -p -g -D -d -h -t -s

all :
	$(Q)$(MAKE) clr_all
	$(Q)$(MAKE) build
	$(Q)$(MAKE) clr

src :
	$(Q)$(MAKE) clr_all
	$(Q)$(MAKE) build
	$(Q)$(MAKE) display
	$(Q)$(MAKE) clr

burn :
	$(Q)$(MAKE) program

clean :
	$(Q)$(MAKE) clr

clean_all :
	$(Q)$(MAKE) clr_all

# Clean

clr :
	$(Q)rm -f *.o *.d ../_Commun/Runtime/*.o ../_Commun/Runtime/*.d

clr_all :
	$(Q)rm -f *.hex *.bin *.elf *.o *.d *.map *.dis *.lst ../_Commun/Runtime/*.o ../_Commun/Runtime/*.d

# Build

build : $(TARGET).bin $(TARGET).hex $(TARGET).dis

display : $(TARGET).bin $(TARGET).dis $(TARGET).lst

%.o : %.c
	@echo "  CC      $<"
	$(Q)$(CC) $(CFLAGS) -o $@ $<

$(TARGET).bin : $(TARGET).elf
	@echo "  OBJCOPY $@"
	$(Q)$(OBJCOPY) $(OBJCOPYFLAGS) -O binary $< $@

$(TARGET).elf : $(OBJ)
	@echo "  LD      $@"
	$(Q)$(LINK.o) -o $@ $^ -lm

$(TARGET).dis : $(TARGET).elf
	@echo "  OBJDUMP $@"
	$(Q)$(OBJDUMP) -S $< > $@

$(TARGET).lst : $(TARGET).elf
	@echo "  OBJDUMP $@"
	$(Q)$(OBJDUMP) $(SWTCH_OBJDUMP) $< > $@

$(TARGET).hex : $(TARGET).elf
	@echo "  OBJCOPY $@"
	$(Q)$(OBJCOPY) -O ihex --strip-all $< $@

.PHONY : all src clean clean_all clr clr_all build display
