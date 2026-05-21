# set-project-paths.
# ==================

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-07-13
# Modifs:
#
# Project:	uKOS-X
# Goal:		Define directory paths required to build the system
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

# Project paths

# - PATH_UKOS	--> Main uKOS-X folder
# - PATH_VARI	--> folder holding CMakeLists.txt
# - PATH_BASE	--> Projects Root Base folder
# - PATH_OSYS	--> Projects Root OS folder

# Setup path to project root directory
get_filename_component(PATH_PORT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
get_filename_component(PATH_UKOS "${PATH_PORT}/.." ABSOLUTE)
cmake_path(GET CMAKE_SOURCE_DIR PARENT_PATH TARGET_DIR)
set(PATH_VARI ${CMAKE_SOURCE_DIR})
set(PATH_OSYS ${PATH_UKOS}/OS)

# Assumptions
# For multi-processor board, each processor is labelled with '_procID'
# and have its dedicated folders Base_procID and Variant_Test_procID
# A folder Base_Common can be used for shared code

get_filename_component(DIR_NAME "${CMAKE_SOURCE_DIR}" NAME)
if(DIR_NAME MATCHES "^Variant_Test_(.+)$")
	set(VARIANT_SUFFIX "_${CMAKE_MATCH_1}")
	set(PATH_BASE ${TARGET_DIR}/Base${VARIANT_SUFFIX})
	set(PATH_COMX ${TARGET_DIR}/Base_Common)
else()
	set(PATH_BASE ${TARGET_DIR}/Base)
endif()
