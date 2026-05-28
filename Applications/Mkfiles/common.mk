# makefile.
# =========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:   Edo. Franzi			2023-12-13
# Modifs:   Laurent von Allmen	2023-12-27
#
# Project:	uKOS-X
# Goal:     common makefile for the all the application.
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

SHELL			=  /bin/sh

PATH_UKOS_X_PACKAGE	?= $(abspath ../../../../..)

# Project paths

# - PATH_MKFILE	--> User makefile location	--> MyProjects/Project/Targets/makefile
# - PATH_MYPR	--> User project folder		--> MyProjects/

# Paths overloaded

# - PATH_UKOS	PATH_UKOS ?= $(PATH_UKOS_X_PACKAGE)
# - PATH_PORT	PATH_PORT ?= $(PATH_UKOS_X_PACKAGE)/Ports
# - PATH_BASE	PATH_BASE ?= $(PATH_UKOS_X_PACKAGE)/Ports/Targets/$(BOARD)/Base
# - PATH_VARI	PATH_VARI ?= $(PATH_UKOS_X_PACKAGE)/Ports/Targets/$(BOARD)/$(VARIANT)

PATH_MKFILE		=  $(shell pwd)
PATH_MYPR		=  $(abspath $(PATH_MKFILE)/..)
PATH_PORT		=  $(PATH_UKOS_X_PACKAGE)/Ports
PATH_RUNT		=  $(PATH_PORT)/EquatesModels/Generic/Runtime
PATH_APPS		=  $(PATH_UKOS_X_PACKAGE)/Applications

# The runtime components

RUNTIME_SRC		=  $(PATH_RUNT)/header.c
RUNTIME_SRC		+= $(PATH_RUNT)/crt0_App.c

# The project components

APPL_SRC		+= $(PATH_MYPR)
APPL_SRC		+= $(PATH_MYPR)/$(BOARD)
APPL_OBJ		=  $(PATH_MYPR)/$(BOARD)

include	$(PATH_APPS)/Mkfiles/application.mk
include	$(PATH_APPS)/Mkfiles/$(COMPILER_FAMILY)_application_$(CORE).mk
