# makefile.
# =========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi 	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for building the testROM
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

SHELL			= /bin/sh

ifndef PATH_GCC_RVXX
$(error PATH_GCC_RVXX is not defined)
endif

PATH_TEST_ROM	?= $(abspath ../)
PATH_COMPILER	?= $(PATH_GCC_RVXX)
PREFIX			?= riscv64-unknown-elf-
COMPILER_FAMILY	?= gcc

TARGET			=  testROM
BOARD			=  Longan_Nano_F103_RV32IMAC

PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/_Commun
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/_Commun/Includes
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/_Commun/Runtime
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/$(BOARD)
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/$(BOARD)/Includes
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/$(BOARD)/Includes/SOC
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/$(BOARD)/Includes/Core
PATH_INCLUDES	+= -I$(PATH_TEST_ROM)/$(BOARD)/Runtime

OBJ				=  Runtime/vectors.o first.o init.o cmns.o tests.o
OBJ				+= ../_Commun/Runtime/crt0.o ../_Commun/Runtime/debug.o ../_Commun/Runtime/syscall.o

# Target & Infrastructure

CC				=  $(PATH_COMPILER)/bin/$(PREFIX)gcc
AS				=  $(PATH_COMPILER)/bin/$(PREFIX)as
OBJCOPY			=  $(PATH_COMPILER)/bin/$(PREFIX)objcopy
OBJDUMP			=  $(PATH_COMPILER)/bin/$(PREFIX)objdump

ASFLAGS			+= -g

TARGET_MACH		=  -march=rv32imac_zicsr_zifencei -mabi=ilp32 -gdwarf-4
TARGET_ARCH		=  -march=rv32imac_zicsr_zifencei -mabi=ilp32 -gdwarf-4

CFLAGS			+= -Wall -c -g -Os -Wlogical-op
CFLAGS			+= -MMD
CFLAGS			+= $(PATH_INCLUDES)

LINKS_LD		=  Runtime/link_p.ld

# For binutils >= 2.39, --no-warn-rwx-segment

BINUTILMAJORVERSION	:= $(shell expr `$(PATH_COMPILER)/bin/$(PREFIX)ld --version | sed -En "s/(.*) ([0-9]+)\.([0-9]+)(.*)/\2/p" `)
BINUTILMINORVERSION	:= $(shell expr `$(PATH_COMPILER)/bin/$(PREFIX)ld --version | sed -En "s/(.*) ([0-9]+)\.([0-9]+)(.*)/\3/p" `)

ifeq ($(BINUTILMAJORVERSION), 2)
ifeq ($(shell expr $(BINUTILMINORVERSION) \>= 39), 1)
LDFLAGS			+= -Wl,--no-warn-rwx-segment
endif
endif

LDFLAGS			+= -march=rv32imac -mabi=ilp32
LDFLAGS			+= -Wall -nostartfiles
LDFLAGS			+= -T$(LINKS_LD)
LDFLAGS			+= -Wl,-Map=$(TARGET).map,--cref,--print-memory-usage

SWTCH_OBJDUMP	=  -f -p -g -D -d -h -t -s

all :
	$(MAKE) clr_all
	$(MAKE) build
	$(MAKE) clr

dfu :
	$(MAKE) clr_all
	$(MAKE) build
	$(MAKE) clr
	$(MAKE) burn_dfu

src :
	$(MAKE) clr_all
	$(MAKE) build
	$(MAKE) display
	$(MAKE) clr

clean :
	$(MAKE) clr

clean_all :
	$(MAKE) clr_all

# Clean

clr :
	rm -f *.o *.d ../_Commun/Runtime/*.o ../_Commun/Runtime/*.d

clr_all :
	rm -f *.hex *.bin *.elf *.o *.d *.map *.dis *.lst ../_Commun/Runtime/*.o ../_Commun/Runtime/*.d

# Build

build : $(TARGET).bin $(TARGET).hex

display : $(TARGET).bin $(TARGET).dis $(TARGET).lst

# Burn

burn_jlink : $(TARGET).hex
	echo device GD32VF103CBT6 >jlink.cmd
	echo if jtag >>jlink.cmd
	echo speed 4000 >>jlink.cmd
	echo JTAGConf -1,-1 >>jlink.cmd
	echo power on >>jlink.cmd
	echo connect >>jlink.cmd
	echo loadfile $(TARGET).hex >>jlink.cmd
	echo r >>jlink.cmd
#	#echo SetPC 0x08000000 >>jlink.cmd
	echo r >>jlink.cmd
	echo g >>jlink.cmd
#	echo q >>jlink.cmd
	JLinkExe jlink.cmd

burn_dfu: $(TARGET).bin
	dfu-util -d 28e9:0189 --alt 0 --dfuse-address 0x08000000 --download $(TARGET).bin --reset

$(TARGET).bin : $(TARGET).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) -O binary $< $@

#$(TARGET).elf : $(OBJ)
#	$(LINK.o) -o $@ $^

$(TARGET).elf : $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^ -lm

$(TARGET).dis : $(TARGET).elf
	$(OBJDUMP) -S $< > $@

$(TARGET).lst : $(TARGET).elf
	$(OBJDUMP) $(SWTCH_OBJDUMP) $< > $@

$(TARGET).hex : $(TARGET).elf
	$(OBJCOPY) -O ihex --strip-all $< $@

.PHONY : all dfu src clean clean_all clr clr_all build display burn_dfu
