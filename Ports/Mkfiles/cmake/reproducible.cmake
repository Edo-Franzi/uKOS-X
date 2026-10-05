# reproducible.
# =============

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2026-06-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Make a build tree produce the same bytes when it is built
#			again from the same commit.
#
# Build description:
#   Two things diverge between two builds of identical sources, and both are
#   handled here:
#
#     - ar records every member's mtime, uid and gid, so an archive differs even
#       when each object in it is byte-identical. The deterministic 'D' modifier
#       zeroes the three fields; it is accepted by GNU ar and by llvm-ar, and
#       both ranlibs take '-D'.
#
#     - __DATE__ and __TIME__ read the wall clock. Nearly every module in the
#       system ends its help string with "Module built on " __DATE__ " " __TIME__,
#       so one object per module changes on every build. GCC and Clang compute
#       both macros from SOURCE_DATE_EPOCH when it is present in the compiler's
#       environment, which is what the compiler launcher supplies. No source
#       change is needed and the console keeps showing a date.
#
#   The epoch is the commit date of HEAD, so it does follow the source: moving
#   the checkout to another commit changes it, and the configure step re-runs
#   because it depends on the git HEAD and index files. An epoch already exported
#   in the environment wins, as the reproducible-builds specification requires.
#   A checkout that is not a git working tree gets no epoch and keeps wall-clock
#   dates rather than a misleading fixed one.
#
#   A dirty working tree deliberately keeps the epoch of the last commit: the
#   date reports which commit was built, not when the compiler ran. version.h
#   carries the '-dirty' marker for the rest.
#
# Usage:
#   include(reproducible)         # or include(<path>/Ports/cmake/reproducible.cmake)
#   ukos_reproducible_build()     # after the toolchain is chosen, before any target
#
# Requires:
#   PATH_UKOS - root of the uKOS-X checkout
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

include_guard(GLOBAL)

macro(ukos_reproducible_build)

	# Deterministic archives. The variables are consumed when a target is
	# generated, so they only have to be set before the add_library() calls.
	foreach(_ukos_repro_lang C CXX ASM)
		set(CMAKE_${_ukos_repro_lang}_ARCHIVE_CREATE "<CMAKE_AR> qcD <TARGET> <LINK_FLAGS> <OBJECTS>")
		set(CMAKE_${_ukos_repro_lang}_ARCHIVE_APPEND "<CMAKE_AR> qD <TARGET> <LINK_FLAGS> <OBJECTS>")
		set(CMAKE_${_ukos_repro_lang}_ARCHIVE_FINISH "<CMAKE_RANLIB> -D <TARGET>")
	endforeach()
	unset(_ukos_repro_lang)

	# Where the epoch comes from
	set(_ukos_repro_epoch "")
	if(DEFINED ENV{SOURCE_DATE_EPOCH})
		set(_ukos_repro_epoch "$ENV{SOURCE_DATE_EPOCH}")
		set(_ukos_repro_origin "environment")
	else()
		find_package(Git QUIET)
		if(GIT_FOUND)
			execute_process(
				COMMAND ${GIT_EXECUTABLE} -C "${PATH_UKOS}" log -1 --format=%ct
				OUTPUT_VARIABLE _ukos_repro_epoch
				OUTPUT_STRIP_TRAILING_WHITESPACE
				ERROR_QUIET
				RESULT_VARIABLE _ukos_repro_rc
			)
			if(NOT _ukos_repro_rc EQUAL 0)
				set(_ukos_repro_epoch "")
			endif()
		endif()
		set(_ukos_repro_origin "HEAD commit date")
	endif()

	if(_ukos_repro_epoch)
		find_program(UKOS_ENV_EXECUTABLE env)
		if(UKOS_ENV_EXECUTABLE)
			set(CMAKE_C_COMPILER_LAUNCHER
				"${UKOS_ENV_EXECUTABLE}" "SOURCE_DATE_EPOCH=${_ukos_repro_epoch}")
			set(CMAKE_CXX_COMPILER_LAUNCHER
				"${UKOS_ENV_EXECUTABLE}" "SOURCE_DATE_EPOCH=${_ukos_repro_epoch}")
			message(STATUS
				"Reproducible build: SOURCE_DATE_EPOCH=${_ukos_repro_epoch} (${_ukos_repro_origin})")
		else()
			message(WARNING
				"Reproducible build: 'env' not found, so SOURCE_DATE_EPOCH cannot be "
				"passed to the compiler; __DATE__ and __TIME__ keep the wall clock.")
		endif()

		# Re-run the configure step when the checkout moves, so the epoch follows
		# the source instead of freezing at the value of the first configure.
		# CMAKE_CONFIGURE_DEPENDS is a DIRECTORY property; set on any other scope
		# it is silently ignored.
		if(GIT_FOUND)
			execute_process(
				COMMAND ${GIT_EXECUTABLE} -C "${PATH_UKOS}" rev-parse --absolute-git-dir
				OUTPUT_VARIABLE _ukos_repro_gitdir
				OUTPUT_STRIP_TRAILING_WHITESPACE
				ERROR_QUIET
			)
			foreach(_ukos_repro_watch HEAD index)
				if(EXISTS "${_ukos_repro_gitdir}/${_ukos_repro_watch}")
					set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
						"${_ukos_repro_gitdir}/${_ukos_repro_watch}")
				endif()
			endforeach()
			unset(_ukos_repro_watch)
			unset(_ukos_repro_gitdir)
		endif()
	else()
		message(STATUS
			"Reproducible build: no SOURCE_DATE_EPOCH available, "
			"__DATE__ and __TIME__ keep the wall clock")
	endif()

	unset(_ukos_repro_epoch)
	unset(_ukos_repro_origin)
	unset(_ukos_repro_rc)

endmacro()
