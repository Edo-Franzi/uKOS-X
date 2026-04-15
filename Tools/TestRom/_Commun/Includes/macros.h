/*
; macros.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Important generic macros.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#pragma	once

// System & compiler
// -----------------

#define	QUOTE(name)				#name
#define	STR(macro)				QUOTE(macro)

#if (defined(__clang__))
#define uKOS_COMPILER			"clang " STR(__clang_major__) "." STR(__clang_minor__) "." STR(__clang_patchlevel__)
#define uKOS_COMPILER_VERSION	((__clang_major__ * 10000) + (__clang_minor__ * 100) + (__clang_patchlevel__))

#else
#define uKOS_COMPILER			"gcc-" STR(__GNUC__) "." STR(__GNUC_MINOR__) "." STR(__GNUC_PATCHLEVEL__)
#define uKOS_COMPILER_VERSION	((__GNUC__ * 10000) + (__GNUC_MINOR__ * 100) + (__GNUC_PATCHLEVEL__))
#endif

#define	uKOS_KBOARD				KBOARD

// Variable alignement macros for C99 & C11
// ----------------------------------------

#if (defined(__STDC_VERSION__)) && (__STDC_VERSION__ < 201112L)
#define	VAR_DECLARED_ALIGN(varDeclared, boundary)											\
								varDeclared __attribute__ ((aligned (boundary)))

#else
#include	<stdalign.h>
#define	VAR_DECLARED_ALIGN(varDeclared, boundary)											\
								alignas (boundary) varDeclared
#endif

// Device reserve/release macros
// -----------------------------

#define	RESERVE(device, mode)	device##_reserve(mode, KWAIT_INFINITY)
#define	RELEASE(device, mode)	device##_release(mode)

#define	RESERVE_SERIAL(serialManager, mode)													\
								serial_reserve(serialManager, mode, KWAIT_INFINITY)
#define	RELEASE_SERIAL(serialManager, mode)													\
								serial_release(serialManager, mode)

// Some useful macros
// ------------------

#define	GET_PTR_32(ptr)			((uint32_t)*((ptr) + 0)<<24) +								\
								((uint32_t)*((ptr) + 1)<<16) +								\
								((uint32_t)*((ptr) + 2)<<8)  +								\
								((uint32_t)*((ptr) + 3))

#define	UNUSED(x)				(void)(x)

// uKernel macros
// --------------

#if (KKERN_WITH_STATISTICS_S == true)
#define	TIC_EXCEPTION_TIME		uint64_t	tic, tac;										\
								kern_readTickCount(&tic);

#define	TAC_EXCEPTION_TIME(core)															\
								extern	volatile uint32_t vKern_TimeException[KNB_CORES];	\
								kern_readTickCount(&tac);									\
								vKern_TimeException[core] += (uint32_t)(tac - tic)

#else
#define	TIC_EXCEPTION_TIME
#define	TAC_EXCEPTION_TIME(core)
#endif

// Call suffix for Applications (downloadable) or Tools (romable application)
// --------------------------------------------------------------------------

// If application (downloadable):
// int	main(int argc, const char *argv[]);
//
// If tool (romable application):
// static	int32_t	prgm(uint32_t argc, const char_t *argv[]);

#if defined(ROMABLE_S)
#if defined(__cplusplus)
#define	CPP_INTERNAL_SCOPE_BEGIN	namespace {
#define	CPP_INTERNAL_SCOPE_END		}
#define	MAIN_ENTRY(argc, argv)			int32_t	prgm(uint32_t argc, const char_t *argv)

#else
#define MAIN_ENTRY(argc, argv)	static	int32_t	prgm(uint32_t argc, const char_t *argv)
#endif

#else
#define	CPP_INTERNAL_SCOPE_BEGIN
#define	CPP_INTERNAL_SCOPE_END
#define	MAIN_ENTRY(argc, argv)	int main(int argc, const char *argv)
#endif
