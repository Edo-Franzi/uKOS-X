# lvgl.
# =====

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for uKOS-X systems (lvgl part).
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

ifndef PATH_UKOS
$(error PATH_UKOS is not defined)
endif
ifndef PATH_LVGL
$(error PATH_LVGL is not defined)
endif

LIB_SYS_DIR			=  $(PATH_LVGL)/Construction/System
LIB_SRC_DIR			= $(PATH_LVGL)/LVGL-current/src

PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Includes
PATH_INCLUDES		+= -I$(PATH_LVGL)/Library/$(CORE)/$(DISPLAY)
PATH_INCLUDES		+= -I$(LIB_SRC_DIR)

SRC					=  $(LIB_SYS_DIR)/headerLVGL.c
SRC					+= $(shell find $(LIB_SRC_DIR) -name '*.c')

OBJ					=  $(patsubst %.c,%.o,$(SRC))

CFLAGS				+= -DLV_CONF_INCLUDE_SIMPLE
CFLAGS				+= $(OPTIMISATION)
CFLAGS				+= $(CPU_SPEC) $(FLAGS_FP)
CFLAGS				+= $(STANDARD)
CFLAGS				+= $(FLAGS_UKOS)
CFLAGS				+= -MMD
CFLAGS				+= $(PATH_INCLUDES)

CFLAGS				+= -Wall
CFLAGS				+= -Wno-pedantic
CFLAGS				+= -Wlogical-op
CFLAGS				+= -fsingle-precision-constant
CFLAGS				+= -Wno-error=undef
CFLAGS				+= -Wno-error=unused-parameter
CFLAGS				+= -Wno-error=cast-align
CFLAGS				+= -Wno-error=cast-qual
CFLAGS				+= -Wno-error=redundant-decls
CFLAGS				+= -Wno-error=strict-prototypes
CFLAGS				+= -Wno-missing-braces
CFLAGS				+= -Wno-misleading-indentation

ifneq ($(PREFIX),llvm-)
ifneq (,$(filter $(CORE),CORTEX_M3 CORTEX_M4 CORTEX_M7 CORTEX_M33 CORTEX_M55))
CFLAGS += -mpoke-function-name
endif
endif

all :
	@$(MAKE)	clr_all
	$(MAKE)		build
	$(MAKE)		archive
	$(MAKE)		remove
	@$(MAKE)	clr

# Clean

LIB_CLEAN_DIRS := . $(LIB_SYS_DIR) $(LIB_SRC_DIR)

clr_all :
	@rm -f $(shell find $(LIB_CLEAN_DIRS) -type f -name '*.a')		\
		   $(shell find $(LIB_CLEAN_DIRS) -type f -name '*.d')		\
		   $(shell find $(LIB_CLEAN_DIRS) -type f -name '*.o')		\
		   $(shell find $(LIB_CLEAN_DIRS) -type f -name '*.o.*')

clr :
	@rm -f $(shell find $(LIB_CLEAN_DIRS) -type f -name '*.d')		\
		   $(shell find $(LIB_CLEAN_DIRS) -type f -name '*.o')		\
		   $(shell find $(LIB_CLEAN_DIRS) -type f -name '*.o.*')

# Archive

archive :
	$(AR) rcs $(LVGL) $(OBJ)
	$(RANLIB) $(LVGL)

# Build & remove

build : $(OBJ)

%.o: %.c
	@echo "Compiling $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

remove :
	$(ST) --strip-unneeded $(LVGL)
