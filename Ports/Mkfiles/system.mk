# system.
# =======

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for uKOS-X systems (generic part).
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

ifeq ($(CONFIG_VERBOSE_S),y)
VERBOSE				= 1
endif

ifeq ($(CONFIG_NOCANARY_S),y)
NOCANARY			= 1
endif

ifeq ($(CONFIG_NOCLEAN_S),y)
NOCLEAN				= 1
endif

ifeq ($(CONFIG_NOLISTING_S),y)
NOLISTING			= 1
endif

HIDE				= @
ifneq ($(VERBOSE),)
HIDE				=
LDFLAGS				+= -v
endif

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

TARGET				?= FLASH
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
PATH_INCLUDES		+= -I$(PATH_SOC)/Runtime
PATH_INCLUDES		+= -I$(PATH_CORE)/Runtime
PATH_INCLUDES		+= -I$(PATH_CORE)/Models
PATH_INCLUDES		+= -I$(PATH_PORT)/EquatesModels/Generic/Runtime
PATH_INCLUDES		+= -I$(PATH_UKOS)/Third_Parties

CFLAGS				+= $(CFLAGS_APPEND)

# The included app makefile

ifneq ($(WITHAPP),)
	include	app_$(WITHAPP).mk
endif

all :
ifeq ($(NOCLEAN),)
	$(MAKE)	clr_all
endif
	$(MAKE)	version
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
	$(MAKE)	version
	$(MAKE)	build
	$(MAKE)	utils
	$(MAKE)	utilStack
	$(MAKE)	size
ifeq ($(NOCLEAN),)
	$(MAKE)	clr
endif

clean :
	$(MAKE)	clr

clean_all :
	$(MAKE)	clr_all

# Clean rules
# -----------

clr :
	rm -rf *.a *.d *.o *.lst *.dis version.h *.su *.nosig.* *.sig kernel_config.h ozone_config.jdebug.user $(CLEAN)

clr_src:
	rm -f *.a *.d *.o version.h *.su *.nosig.* *.sig kernel_config.h ozone_config.jdebug.user conf_system

clr_all :
	rm -rf *.a *.d *.o *.lst *.dis *.map *.elf *.bin *.sig *.s3 *.hex version.h *.su *.nosig.* *.stack *.ck *.sig kernel_config.h ozone_config.jdebug.user $(CLEAN) *.cnf

$(TARGET).cnf:
	$(HIDE)echo "$(CONF_SYSTEM)" > $@

# Build the version rules
# -----------------------

version :
	$(HIDE)echo "#define VERSIONING_TOOL \"No versioning system\"  "				>  version.h
	$(HIDE)echo "#define SW_VERSION \" \"  "										>> version.h
	$(HIDE)echo "#define VERSIONING_TOOL \"git:\"  "								>  version.h
	$(HIDE)echo "#define SW_VERSION \"`git describe --always --dirty --match=`\"  "	>> version.h

# Build the .o & .a rules
# -----------------------

build : makefile $(TARGET).elf

WHOLE_ARCHIVE_START	?= -Wl,-whole-archive
WHOLE_ARCHIVE_END	?= -Wl,-no-whole-archive

$(TARGET).nosig.elf : $(LINKS_LD) $(patsubst %.c, %.o, $(notdir $(UKOS_FIRST_P))) $(UKOS_COMPONENTS) $(LIBS_FILES)
	@echo "Linking $@"
	$(HIDE)$(CXX) $(LDFLAGS)																\
	$(patsubst %.c, %.o, $(notdir $(UKOS_FIRST_P)))											\
	$(WHOLE_ARCHIVE_START) $(UKOS_COMPONENTS) $(WHOLE_ARCHIVE_END) $(LIBS)					\
	-lm -o $@

$(TARGET).elf : $(LINKS_LD) $(patsubst %.c, %.o, $(notdir $(UKOS_FIRST_P))) $(UKOS_COMPONENTS) $(LIBS_FILES) $(TARGET).sig $(TARGET).sig.o
	@echo "Linking $@"
	$(HIDE)$(CXX) $(LDFLAGS)																\
	$(patsubst %.c, %.o, $(notdir $(UKOS_FIRST_P)))											\
	$(WHOLE_ARCHIVE_START) $(UKOS_COMPONENTS) $(TARGET).sig.o $(WHOLE_ARCHIVE_END) $(LIBS)	\
	-lm -o $@

SRC_DIRS :=	$(dir $(FIRST_P))	$(dir $(FIRST_HIDE_P))		\
			$(dir $(RTCB_P))	$(dir $(RTCB_HIDE_P))		\
			$(dir $(KERN_P))	$(dir $(KERN_HIDE_P))		\
			$(dir $(KERN_U))	$(dir $(KERN_HIDE_U))		\
			$(dir $(LIBX_P))	$(dir $(LIBX_HIDE_P))		\
			$(dir $(LIBX_U))	$(dir $(LIBX_HIDE_U))		\
			$(dir $(SHAR_P))	$(dir $(SHAR_HIDE_P))		\
			$(dir $(PROC_P))	$(dir $(PROC_HIDE_P))		\
			$(dir $(PROC_U))	$(dir $(PROC_HIDE_U))		\
			$(dir $(CLI_U))		$(dir $(CLI_HIDE_U))

vpath %.S	$(dir $(FIRST_P))	$(dir $(FIRST_HIDE_P))
vpath %.c   $(SRC_DIRS)
vpath %.cpp $(SRC_DIRS)

%.o : %.S $(TARGET).cnf
	@echo "Compiling $(notdir $<)"
	$(HIDE)$(CC) @$(TARGET).cnf -c -o $@ $(CFLAGS) $<

%.o : %.c $(TARGET).cnf
	@echo "Compiling $(notdir $<)"
	$(HIDE)$(CC) @$(TARGET).cnf -c -o $@ $(CFLAGS) $<

%.o : %.cpp $(TARGET).cnf
	@echo "Compiling $(notdir $<)"
	$(HIDE)$(CXX) @$(TARGET).cnf -c -o $@ $(CXXFLAGS) $<

%.nosig.bin : %.nosig.elf
	$(HIDE)$(OBJCOPY) -O binary --strip-all --remove-section=.signature $< $@

%.bin : %.elf
	$(OBJCOPY) -O binary --strip-all $< $@

%.ck : %.nosig.bin
	@echo Generating the signature file for the applications
	$(HIDE)thesha=`shasum --algorithm 256 $< | cut -c 1-64`; echo "STRG_LOC_CONST(aSignature[]) = \"$${thesha}\";" > $@

%.sig : %.nosig.bin
	@echo Generating the signature
	$(HIDE)thesha=`shasum --algorithm 256 $< | cut -c 1-64`; echo "const char aFLASH_signature[] __attribute__((section(\".signature\"))) = \"$${thesha}\";" > $@

%.sig.o : %.sig
	$(HIDE)$(CC) -c $(CFLAGS) -o $@ -x c $<

librtcb_p.a : \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(RTCB_P)))) \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(RTCB_HIDE_P))))
	$(HIDE)$(AR) rcs $@ $^

libkern_p.a : \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(KERN_P)))) \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(KERN_HIDE_P))))
	$(HIDE)$(AR) rcs $@ $^

libkern_u.a : \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(KERN_U)))) \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(KERN_HIDE_U))))
	$(HIDE)$(AR) rcs $@ $^

liblibx_p.a : \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(LIBX_P)))) \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(LIBX_HIDE_P))))
	$(HIDE)$(AR) rcs $@ $^

liblibx_u.a : \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(LIBX_U)))) \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(LIBX_HIDE_U))))
	$(HIDE)$(AR) rcs $@ $^

libshar_p.a : \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(SHAR_P)))) \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(SHAR_HIDE_P))))
	$(HIDE)$(AR) rcs $@ $^

libproc_p.a : \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(PROC_P)))) \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(PROC_HIDE_P))))
	$(HIDE)$(AR) rcs $@ $^

libproc_u.a : \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(PROC_U)))) \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(PROC_HIDE_U))))
	$(HIDE)$(AR) rcs $@ $^

libtool_u.a : \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(CLI_U)))) \
	$(patsubst %.cpp, %.o, $(patsubst %.c, %.o, $(notdir $(CLI_HIDE_U))))
	$(HIDE)$(AR) rcs $@ $^

# Build the TinyUSB, MicroPython & FatFs library rules
# ----------------------------------------------------

ifneq ($(TINYUSB),)
$(TINYUSB).a :
	cp -f $(PATH_LIB_TINYUSB)/$(TINYUSB).a $(TINYUSB).a
endif

ifneq ($(MICROPYTHON),)
$(MICROPYTHON).a :
	cp -f $(PATH_LIB_MICROPYTHON)/$(MICROPYTHON).a $(MICROPYTHON).a
endif

ifneq ($(FATFS),)
$(FATFS).a :
	cp -f $(PATH_LIB_FATFS)/$(FATFS).a $(FATFS).a
endif

ifneq ($(LVGL),)
$(LVGL).a :
	cp -f $(PATH_LIB_LVGL)/$(LVGL).a $(LVGL).a
endif

ifneq ($(TFLITE),)
$(TFLITE).a :
	cp -f $(PATH_LIB_TFLITE)/$(TFLITE).a $(TFLITE).a
endif

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

help : help_core
	@echo "NOCLEAN=1              Keep the object files."
	@echo "NOLISTING=1            Do not generate the .dis & .lst."
	@echo "VERBOSE=1              Display the compiler command line."
	@echo "TARGET=name            Name is the final result name (i.e. name.bin, name.s3, name.elf, etc)."
	@echo "NOCANARY=1             Suppress detection if a buffer overflow in stack"
	@echo "WITHAPP=xyz            Integrate the user application xyz into the system"

ifeq ($(NOCLEAN),)
burn :
	$(PATH_SOC)/Burn/$(BURN).sh
else
burn : $(TARGET).elf $(TARGET).hex
	$(PATH_SOC)/Burn/$(BURN).sh
endif

CTAGS			?= ctags
TAG_FILE		=  $(PATH_UKOS_X_PACKAGE)/tags
TAG_SRC			=  $(PATH_UKOS_X_PACKAGE)/Includes
TAG_SRC			+= $(PATH_UKOS_X_PACKAGE)/Lib_*
TAG_SRC			+= $(PATH_UKOS_X_PACKAGE)/Ports/EquatesModels/Cores/$(CORE)
TAG_SRC			+= $(PATH_UKOS_X_PACKAGE)/Ports/EquatesModels/SOCs/$(SOC)
TAG_SRC			+= $(PATH_UKOS_X_PACKAGE)/Ports/EquatesModels/Generic
TAG_SRC			+= $(PATH_UKOS_X_PACKAGE)/Ports/EquatesModels/Devices
TAG_SRC			+= $(PATH_UKOS_X_PACKAGE)/Boots
TAG_SRC			+= $(PATH_BASE) $(PATH_VARI)
CTAGS_OPTIONS	:= --excmd=number --tag-relative=always --fields=+a+m+n+S
CTAGS_OPTIONS	+= --map-C=+.cm --map-C=+.h --languages=C

tags:
	rm -f $(TAG_FILE)
	@$(CTAGS) $(CTAGS_OPTIONS) -R -f $(TAG_FILE) $(TAG_SRC)

.PHONY : stack clean clean_all clr clr_all version build size help
