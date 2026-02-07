/*
; types.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Basic predefined types (normally machine independent).
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

#include	<stdint.h>
#include	<stdbool.h>
#include	<stddef.h>

// uKOS-X program returns / exits
//
// return (code)
//         code = EXIT_OS_SUCCESS				--->		Success, kill the console process. Only the running processes
//         code = EXIT_OS_SUCCESS_CLI			--->		Success; return to the OS (console) with the running processes
//         code = EXIT_OS_FAILURE				--->		Failure; return to the OS (console) with an error message
//         code = EXIT_OS_FAILURE_CRT0			--->		Failure; return to the OS (console). Reload the latest OS
//         code = EXIT_OS_PANIC					--->		Failure; panic. System is stopped
//         code = default						--->		Failure; panic. System is stopped
//
// exit (code)
//         code = EXIT_OS_SUCCESS				--->		Success, commit a suicide
//         code = EXIT_OS_FAILURE				--->		Failure; commit a suicide
//         code = EXIT_OS_PANIC					--->		Failure; panic. System is stopped
//         code = EXIT_OS_PANIC_MALLOC_BROKEN	--->		Failure; panic. System is stopped
//         code = EXIT_OS_PANIC_STACK_UNDERFLOW	--->		Failure; panic. System is stopped
//         code = EXIT_OS_PANIC_NO_SYSCALL		--->		Failure; panic. System is stopped
//         code = EXIT_OS_PANIC_ELEVATION		--->		Failure; panic. System is stopped
//         code = default						--->		Failure; panic. System is stopped

enum : int32_t {
		EXIT_OS_SUCCESS = 0,
		EXIT_OS_SUCCESS_CLI,
		EXIT_OS_FAILURE,
		EXIT_OS_FAILURE_CRT0,
		EXIT_OS_PANIC,
		EXIT_OS_PANIC_MALLOC_BROKEN,
		EXIT_OS_PANIC_STACK_UNDERFLOW,
		EXIT_OS_PANIC_NO_SYSCALL,
		EXIT_OS_PANIC_ELEVATION
};

// uKOS-X misc

#if (!defined(tm_t))
typedef	struct	tm			tm_t;
#endif

#if (!defined(timeval_t))
typedef	struct timeval		timeval_t;
#endif

#if (!defined(reserveMode_t))
typedef	enum {
			KMODE_READ = 0u,
			KMODE_WRITE,
			KMODE_READ_WRITE,
} reserveMode_t;

#define	KMODE_ALL	KMODE_READ_WRITE
#endif

// Types defined by gcc (version > than 4.8)

#if (!defined(char_t))
typedef	char				char_t;
#endif

#if (!defined(float32_t))
typedef float				float32_t;
#endif

#if (!defined(float64_t))
typedef double				float64_t;
#endif
