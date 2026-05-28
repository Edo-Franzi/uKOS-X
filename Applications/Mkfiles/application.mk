# application.
# ============

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for uKOS-X applications (generic part).
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

# Hide the compiler command line if VERBOSE=... is not specified.

HIDE				= @
ifneq ($(VERBOSE),)
HIDE				=
LDFLAGS				+= -v
endif

# CANARY is by default active.

ifdef NOCANARY
CANARY				= 0
else
CANARY				?= 1
endif

ifneq ($(CANARY),0)
CFLAGS				+= -fstack-protector-strong
LDFLAGS				+= -Wl,--wrap=__stack_chk_fail
endif

ifneq ($(CSTANDARD),)
CFLAGS				+= $(CSTANDARD)
else
CFLAGS				+= -std=c23
endif
ifneq ($(CXXSTANDARD),)
CXXFLAGS			+= $(CXXSTANDARD)
else
CXXFLAGS			+= -std=c++23
endif

CFLAGS				+= -D_POSIX_C_SOURCE=200809L
CXXFLAGS			+= -D_POSIX_C_SOURCE=200809L

LDFLAGS				+= -Wl,--wrap=_malloc_r
LDFLAGS				+= -Wl,--wrap=_free_r
LDFLAGS				+= -Wl,--wrap=_realloc_r
LDFLAGS				+= -Wl,--wrap=_calloc_r

PYTHON				?= python
CC					=  $(PATH_COMPILER)/bin/$(PREFIX)gcc
AR					=  $(PATH_COMPILER)/bin/$(PREFIX)ar
CXX					=  $(PATH_COMPILER)/bin/$(PREFIX)g++
AS					=  $(PATH_COMPILER)/bin/$(PREFIX)as
OBJCOPY				=  $(PATH_COMPILER)/bin/$(PREFIX)objcopy
OBJDUMP				=  $(PATH_COMPILER)/bin/$(PREFIX)objdump
SIZE				=  $(PATH_COMPILER)/bin/$(PREFIX)size

TARGET				?= $(PROJECT)
PATH_UKOS			?= $(PATH_UKOS_X_PACKAGE)
PATH_PORT			?= $(PATH_UKOS_X_PACKAGE)/Ports
PATH_BASE			?= $(PATH_UKOS_X_PACKAGE)/Ports/Targets/$(BOARD)/Base
PATH_VARI			?= $(PATH_UKOS_X_PACKAGE)/Ports/Targets/$(BOARD)/$(VARIANT)
PATH_MAPP			?= $(PATH_BASE)/Runtime
PATH_CORE			?= $(PATH_PORT)/EquatesModels/Cores/$(CORE)
PATH_SOC			?= $(PATH_PORT)/EquatesModels/SOCs/$(SOC)

PATH_INCLUDES		+= -I$(PATH_UKOS)
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Boots
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Includes
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Lib_serials
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Lib_generics
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Lib_kernels
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Lib_peripherals
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Lib_neurals
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Lib_storages
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Lib_cryptographics
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Processes
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Daemons
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/CLI
PATH_INCLUDES		+= -I$(PATH_VARI)/Shared
PATH_INCLUDES		+= -I$(PATH_VARI)/System
PATH_INCLUDES		+= -I$(PATH_VARI)/Runtime
PATH_INCLUDES		+= -I$(PATH_BASE)/Runtime
PATH_INCLUDES		+= -I$(PATH_VARI)/Includes/System
PATH_INCLUDES		+= -I$(PATH_BASE)/Includes/System
PATH_INCLUDES		+= -I$(PATH_VARI)/Includes/Board
PATH_INCLUDES		+= -I$(PATH_BASE)/Includes/Board
PATH_INCLUDES		+= -I$(PATH_PORT)/EquatesModels/Devices
PATH_INCLUDES		+= -I$(PATH_SOC)/Models
PATH_INCLUDES		+= -I$(PATH_PORT)/EquatesModels/Generic/Models
PATH_INCLUDES		+= -I$(PATH_CORE)/Includes
PATH_INCLUDES		+= -I$(PATH_SOC)/Includes
PATH_INCLUDES		+= -I$(PATH_CORE)/Runtime
PATH_INCLUDES		+= -I$(PATH_CORE)/Models
PATH_INCLUDES		+= -I$(PATH_SOC)/Runtime
PATH_INCLUDES		+= -I$(PATH_PORT)/EquatesModels/Generic/Runtime
PATH_INCLUDES		+= -I$(PATH_UKOS)/Third_Parties

all :
ifeq ($(NOCLEAN),)
	$(MAKE)	clr_all
endif
	$(MAKE)	build
	$(MAKE)	utils
	$(MAKE)	size
ifeq ($(NOCLEAN),)
ifeq ($(NOLISTING),)
	$(MAKE)	clr_src
else
	$(MAKE)	clr
endif
endif

stack :
ifeq ($(NOCLEAN),)
	$(MAKE)	clr_all
endif
	$(MAKE)	build
	$(MAKE)	utils
	$(MAKE)	utilStack
	$(MAKE)	size
ifeq ($(NOCLEAN),)
	$(MAKE) clr
endif

clean :
	$(MAKE)	clr

clean_all :
	$(MAKE)	clr_all

# Clean rules
# -----------

clr :
	rm -rf *.d *.o *.lst *.dis *.su $(CLEAN) ozone_config.jdebug.user

clr_src:
	rm -f *.d *.o *.su ozone_config.jdebug.user

clr_all :
	rm -rf *.d *.o *.lst *.dis *.map *.elf *.bin *.s3 *.hex *.su *.nosig.* *.stack $(CLEAN) ozone_config.jdebug.user

# Build the .o & .a rules
# -----------------------

build : makefile $(TARGET).elf

RUNTIME_OBJ			=  $(patsubst %.c, %.o, $(notdir $(RUNTIME_SRC)))
APPL_C_SRC			=  $(foreach dir, $(APPL_SRC), $(wildcard $(dir)/*.c))
APPL_C_OBJ			=  $(patsubst %.c, %.o, $(notdir $(APPL_C_SRC)))
APPL_CPP_SRC		=  $(foreach dir, $(APPL_SRC), $(wildcard $(dir)/*.cpp))
APPL_CPP_OBJ		=  $(patsubst %.cpp, %.o, $(notdir $(APPL_CPP_SRC)))

$(TARGET).elf : $(LINKS_LD) $(RUNTIME_OBJ) $(APPL_C_OBJ) $(APPL_CPP_OBJ) $(LIBS_FILES)
	@echo "Linking $@"
	$(HIDE)$(CXX) $(LDFLAGS)							\
	$(RUNTIME_OBJ)										\
	$(APPL_C_OBJ)										\
 	$(APPL_CPP_OBJ)										\
	$(MYLIB)											\
	-Wl,--just-symbols=$(PATH_VARI)/System/FLASH.elf 	\
	$(GPPLDOPTION) -lm -o $@

vpath %.c	$(dir $(RUNTIME_SRC)) $(dir $(APPL_C_SRC))
vpath %.cpp	$(dir $(APPL_CPP_SRC))

%.o : %.c
	@echo "Compiling $(notdir $<) $(APPL_SRC) "
	$(HIDE)$(CC) @$(PATH_VARI)/System/FLASH.cnf -c -o $@ $(CFLAGS) $<

%.o : %.cpp
	echo "Compiling $(notdir $<)"
	$(HIDE)$(CXX) @$(PATH_VARI)/System/FLASH.cnf -c -o $@ $(CXXFLAGS) $<

%.bin : %.elf
	$(OBJCOPY) -O binary --strip-all $< $@

# Build the additional useful file rules
# --------------------------------------

%.lst : %.elf
	$(OBJDUMP) $(SWTCH_OBJDUMP) $< > $@

%.dis : %.elf
	$(OBJDUMP) -S $< > $@

%.hex : %.elf
	$(OBJCOPY) -O ihex --strip-all $< $@

ifneq ($(PREFIX),llvm-)
%.s3 : %.elf
	$(OBJCOPY) -O srec --srec-forceS3 --strip-all $< $@
else
%.s3 : %.elf
	$(OBJCOPY) -O srec --strip-all $< $@
endif

%.stack : $(wildcard *.su)
	cat $^ | awk '{ $$3=""; printf("%s\t [Bytes] ---> %s\n",$$2, $$1); }' | sort -gr -o $@

ELFSIZE = $(SIZE) -A --radix=16 $(TARGET).elf

size : $(TARGET).elf
	@echo
	@echo "Size of the generated program"
	@cp $(TARGET).elf $(TARGET).elf.backup
	@$(PATH_COMPILER)/bin/$(PREFIX)strip --strip-debug $(TARGET).elf
	@$(ELFSIZE) | grep -F -v -e .debug -e .ARM.attributes -e .comment
	@rm $(TARGET).elf
	@mv $(TARGET).elf.backup $(TARGET).elf
	@echo
	$(HIDE)cat *.su | awk '{ $$3=""; printf("%s\t [Bytes] ---> %s\n",$$2, $$1); }' | sort -gro $(TARGET).stack

help : help_core
	@echo "NOCLEAN=1              Keep the object files."
	@echo "NOLISTING=1            Do not generate the .dis & .lst."
	@echo "VERBOSE=1              Display the compiler command line."
	@echo "TARGET=name            Name is the final result name (i.e. name.bin, name.s3, name.elf, etc)."
	@echo "NOCANARY=1             Suppress detection if a buffer overflow in stack"

.PHONY : stack clean clean_all clr clr_all build size help
