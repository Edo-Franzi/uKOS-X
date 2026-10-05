# check-picolib-default.
# ======================

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2026-05-01
# Modifs:
#
# Project:	uKOS-X
#
# Verify that a compiler selected for C_LIBRARY=picolibc really has picolibc as
# its default C library.
#
# The build passes no -specs=picolibc.specs: on a picolibc-native GCC the specs
# file breaks every C++ translation unit by hoisting the C include directory
# above the C++ ones, which strands libstdc++'s #include_next. See "picolibc
# with GCC - the toolchain must be picolibc-native" (§2.2) in
# Documentation/USER_GUIDES/C-library-selection.md.
#
# The consequence is that a toolchain reaching picolibc only through that specs
# file is no longer usable. Without this check it would fail silently rather
# than loudly: the compiler would resolve <stdlib.h> and -lc to newlib while the
# build defines CONFIG_MAN_PICOLIBC_S, producing an image whose C library does
# not match its registered C library manager.
#
# The probe is a header check, so it needs no -mcpu/-march: every multilib of a
# given toolchain shares one include directory.
#
#   (c) 2026, Laurent von Allmen
#   ----------------------------
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

function(check_picolibc_is_default compiler)
	set(probe "${CMAKE_CURRENT_BINARY_DIR}/picolibc_probe.c")
	file(WRITE "${probe}"
		"#include <stdlib.h>\n"
		"#ifndef __PICOLIBC__\n"
		"#error the default C library of this toolchain is not picolibc\n"
		"#endif\n"
	)

	execute_process(
		COMMAND ${compiler} -fsyntax-only ${probe}
		RESULT_VARIABLE probe_result
		OUTPUT_QUIET
		ERROR_QUIET
	)
	file(REMOVE "${probe}")

	if(NOT probe_result EQUAL 0)
		message(FATAL_ERROR
			"C_LIBRARY=picolibc, but the default C library of\n"
			"	 ${compiler}\n"
			"is not picolibc (<stdlib.h> does not define __PICOLIBC__).\n"
			"\n"
			"The build passes no -specs=picolibc.specs, so a toolchain that carries "
			"picolibc as an overlay on newlib cannot be used: it would silently "
			"compile and link against newlib while the image declares the picolibc "
			"manager. Point the corresponding PATH_*_*P variable at a toolchain "
			"built with picolibc as its main C library. See "
			"Documentation/USER_GUIDES/C-library-selection.md."
		)
	endif()
endfunction()
