# makefile.
# =========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:	Edo. Franzi		The 2025-01-01	install replaces cp -f
#
# Project:	uKOS-X
# Goal:		makefile for the "bin2s" application.
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

ifndef PATH_UKOS_X_PACKAGE
    $(error PATH_UKOS_X_PACKAGE is not defined)
endif
ifndef PATH_TOOLS_UNIX
    $(error PATH_TOOLS_UNIX is not defined)
endif

PATH_XTOOLS	  = $(PATH_TOOLS_UNIX)
PATH_INCLUDES = -I$(PATH_UKOS_X_PACKAGE)/OS/Includes

all :
	make TARGET=bin2s clr_all
	make TARGET=bin2s build
	make TARGET=bin2s copy
	make TARGET=bin2s clr

clean :
	make TARGET=bin2s clr

clean_all :
	make TARGET=bin2s clr_all

# Clean

clr :
	rm -f $(TARGET)

clr_all :
	rm -f $(TARGET)

# Copy the tools @ the right place

copy :
	install $(TARGET) $(PATH_XTOOLS)/$(TARGET)

# Build

build : $(TARGET)

$(TARGET) : $(TARGET).c
	gcc -pedantic -std=c23 -o $(TARGET) $(TARGET).c $(PATH_INCLUDES)
