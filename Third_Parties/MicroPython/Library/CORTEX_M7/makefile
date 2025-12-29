# makefile.
# =========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for building the MicroPython library.
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

include ../../MicroPython-current/py/mkenv.mk

PREFIX			?= arm-none-eabi-

# Select the compiler

ifneq ($(PREFIX),llvm-)
PATH_COMPILER	= $(PATH_GCC_ARM)/bin/$(PREFIX)
else
PATH_COMPILER	= $(PATH_LLVM_ARM)/bin/$(PREFIX)
endif

CROSS_COMPILE	:= $(PATH_COMPILER)

PATH_UKOS		=  $(PATH_UKOS_X_PACKAGE)

INC				+= -I.
INC				+= -I$(TOP)
INC				+= -I$(BUILD)
INC				+= -I$(PATH_UKOS)
INC				+= -I$(PATH_UKOS)/OS
INC				+= -I$(PATH_UKOS)/OS/Includes
INC				+= -I$(PATH_UKOS)/OS/Lib_generics
INC				+= -I$(PATH_UKOS)/OS/Lib_peripherals
INC				+= -I$(PATH_UKOS)/OS/Lib_serials
INC				+= -I$(PATH_UKOS)/OS/Lib_kernels
INC				+= -I$(PATH_UKOS)/Ports/EquatesModels/Generic/Runtime

# Libs & files necessary for building MicroPython.a
#
# !!The paths have to be relative to MicroPyton_current
# !!Mandatory: Place the object list before "include $(TOP)/py/py.mk"

SRC_C			+= $(addprefix uKOS_System/, \
					help.c \
					headerMicroPython.c \
					microPython.c \
				)

SRC_MODULE		+= $(addprefix uKOS_Interface/, \
					led/led.c \
					switch/switch.c \
					serial/serial.c \
					example/example.c \
)

SRC_LIBM		+= $(addprefix lib/libm_dbl/, \
					__cos.c \
					__expo2.c \
					__fpclassify.c \
					__rem_pio2_large.c \
					__rem_pio2.c \
					__signbit.c \
					__sin.c \
					__tan.c \
					acos.c \
					acosh.c \
					asin.c \
					asinh.c \
					atan.c \
					atan2.c \
					atanh.c \
					ceil.c \
					copysign.c \
					cos.c \
					cosh.c \
					erf.c \
					exp.c \
					expm1.c \
					floor.c \
					fmod.c \
					frexp.c \
					ldexp.c \
					lgamma.c \
					log.c \
					log1p.c \
					log10.c \
					modf.c \
					nearbyint.c \
					pow.c \
					rint.c \
					round.c \
					scalbn.c \
					sin.c \
					sinh.c \
					sqrt.c \
					tan.c \
					tanh.c \
					tgamma.c \
					trunc.c \
				)

# Important: for the QSTR components it is mandatory the full path

SRC_QSTR		+= $(addprefix shared/runtime/, \
					stdout_helpers.c \
					pyexec.c \
				)

SRC_QSTR		+= $(addprefix shared/readline/, \
					readline.c \
				)

SRC_QSTR		+= $(addprefix ../, $(SRC_MODULE))

include $(TOP)/py/py.mk

OBJ				=  $(PY_O)
OBJ				+= $(addprefix $(BUILD)/, $(SRC_QSTR:.c=.o))
OBJ				+= $(addprefix $(BUILD)/, $(SRC_LIBM:.c=.o))
OBJ				+= $(addprefix $(BUILD)/, $(SRC_C:.c=.o))
OBJ				+= $(addprefix $(BUILD)/, $(SRC_MODULE:.c=.o))

OBJ				:= $(patsubst $(BUILD)/../%, $(BUILD)/%, $(OBJ))
OBJ				:= $(sort $(OBJ))

# Settings for cortex M7 cores
# ----------------------------

CORE			= CORTEX_M7
FLAGS_UKOS		= -DTHIRD_PARTY_S -DCORTEX_M7_S

CFLAGS_CORTEX	+= -mthumb -mtune=cortex-m7 -mcpu=cortex-m7 -mfpu=fpv5-sp-d16 -mfloat-abi=hard
ifeq ($(PREFIX),llvm-)
CFLAGS_CORTEX 	+= --target=thumbv7em-none-unknown-eabihf -cl-single-precision-constant
endif
CFLAGS_CORTEX	+= -fshort-enums
CFLAGS_CORTEX	+= $(FLAGS_UKOS)

CFLAGS			+= $(INC) -Wall -Wno-pedantic -std=c23 -nostdlib $(CFLAGS_CORTEX) $(COPT) -Os -DNDEBUG
ifneq ($(PREFIX),llvm-)
CFLAGS			+= -Wno-dangling-pointer
endif

CFLAGS			+= $(INC) -Wall -Wno-pedantic -std=c23 -nostdlib $(CFLAGS_CORTEX) $(COPT) -Os -DNDEBUG
ifneq ($(PREFIX),llvm-)
CFLAGS			+= -Wno-dangling-pointer
endif

include ../Mkfiles/MicroPython.mk
include $(TOP)/py/mkrules.mk
