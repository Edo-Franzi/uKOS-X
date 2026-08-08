# makefile.
# =========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for the "gan" application.
#			This application compile the sources located in the uKOS_Demos folder
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

PROJECT			=  gan

# All the sources are in the uKOS_Demos folder

PATH_DEMO		=  $(PATH_UKOS_X_PACKAGE)/Applications/uKOS_Demos/$(PROJECT)

APPL_SRC		+= $(PATH_DEMO)
APPL_SRC		+= $(PATH_DEMO)/$(BOARD)
APPL_SRC		+= $(PATH_DEMO)/Classifier
APPL_SRC		+= $(PATH_DEMO)/Graphics
APPL_SRC		+= $(PATH_DEMO)/Graphics/Widgets/$(BOARD)/background

DISPLAY			?= RK050HR18_5_Inches
PATH_LVGL		=  $(PATH_UKOS)/Third_Parties/LVGL

# Target & Infrastructure

PREFIX			?= arm-none-eabi-
COMPILER_FAMILY	?= gcc

BOARD			=  Discovery_N657
VARIANT			=  Variant_Test
SOC				=  STM32N657
CORE			=  CORTEX_M55
OPTIMISATION	=  -Os
NN_DEFINES		=  -DUSE_NN_HARDWARE

CFLAGS			+= $(NN_DEFINES)
CFLAGS			+= -I$(PATH_LVGL)/LVGL-current
CFLAGS			+= -I$(PATH_LVGL)/Library/$(DISPLAY)
CFLAGS			+= -I$(PATH_LVGL)/Library/$(DISPLAY)/$(CORE)
CFLAGS			+= -isystem $(PATH_LVGL)/LVGL-current
CFLAGS			+= -DUSE_NN_HARDWARE

CXXFLAGS		+= $(NN_DEFINES)
CXXFLAGS		+= -I$(PATH_LVGL)/LVGL-current
CXXFLAGS		+= -I$(PATH_LVGL)/Library/$(DISPLAY)
CXXFLAGS		+= -I$(PATH_LVGL)/Library/$(DISPLAY)/$(CORE)
CXXFLAGS		+= -DTF_LITE_STATIC_MEMORY=1

MYLIB			=    $(PATH_UKOS)/Third_Parties/Tflite-micro/Library/$(CORE)/libTFLite.a
MYLIB			+=	 $(PATH_UKOS)/Third_Parties/STM32/STM32N6/Library/AI/$(PROJECT)/libNN_Hardware.a
PATH_INCLUDES	+= -I$(PATH_UKOS)/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic
PATH_INCLUDES	+= -I$(PATH_UKOS)/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic/third_party/flatbuffers/include
PATH_INCLUDES	+= -I$(PATH_UKOS)/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic/third_party/gemmlowp
PATH_INCLUDES	+= -I$(PATH_UKOS)/Third_Parties/STM32/STM32N6/Library/AI/$(PROJECT)

PATH_INCLUDES	+= -I$(PATH_DEMO)/Classifier
PATH_INCLUDES	+= -I$(PATH_DEMO)/Graphics
PATH_INCLUDES	+= -I$(PATH_DEMO)/Graphics/Widgets

include ../../../../Mkfiles/common.mk
