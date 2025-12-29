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

SRC_LIBM		+= $(addprefix lib/libm/, \
					atanhf.c \
					acoshf.c \
					asinfacosf.c \
					asinhf.c \
					atan2f.c \
					atanf.c \
					ef_rem_pio2.c \
					ef_sqrt.c \
					erf_lgamma.c \
					fmodf.c \
					kf_cos.c \
					kf_rem_pio2.c \
					kf_sin.c \
					kf_tan.c \
					log1pf.c \
					math.c \
					nearbyintf.c \
					roundf.c \
					sf_cos.c \
					sf_erf.c \
					sf_frexp.c \
					sf_ldexp.c \
					sf_modf.c \
					sf_sin.c \
					sf_tan.c \
					wf_lgamma.c \
					wf_tgamma.c \
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

# Settings for cortex M55 cores
# -----------------------------

CORE			= CORTEX_M55
FLAGS_UKOS		= -DTHIRD_PARTY_S -DCORTEX_M55_S

CFLAGS_CORTEX	+= -mthumb -mtune=cortex-m55 -mcpu=cortex-m55 -mfpu=fpv5-sp-d16 -mfloat-abi=hard
ifneq ($(PREFIX),llvm-)
CFLAGS_CORTEX 	+= -fsingle-precision-constant
else
CFLAGS_CORTEX 	+= --target=thumbv8.1m.main-none-unknown-eabihf -cl-single-precision-constant
endif
CFLAGS_CORTEX	+= -Wdouble-promotion -fshort-enums
CFLAGS_CORTEX	+= $(FLAGS_UKOS)

CFLAGS			+= $(INC) -Wall -Wno-pedantic -std=c23 -nostdlib $(CFLAGS_CORTEX) $(COPT) -Os -DNDEBUG
ifneq ($(PREFIX),llvm-)
CFLAGS			+= -Wno-dangling-pointer
endif

include ../Mkfiles/MicroPython.mk
include $(TOP)/py/mkrules.mk
