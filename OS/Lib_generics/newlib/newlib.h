/*
; newlib.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		newLib interface for gcc C compiler (reentrant version).
;
;			See: https://linux.die.net/man/
;
;			Fully or partially supported functions to support
;
;			Open - close - read - write newlib functions
;			_open_r
;			_close_r
;			_write_r
;			_read_r
;
;			Generic newlib functions
;			_times_r
;			_wait_r
;			__errno
;			_fork_r
;			_stat_r
;			_fstat_r
;			_link_r
;			_unlink_r
;			_lseek_r
;			_getpid_r
;			_kill_r
;
;			Allocator newlib functions
;			_sbrk_r
;			__wrap__malloc_r
;			__wrap__free_r
;			__wrap__realloc_r
;			__wrap__calloc_r
;
;			Suported devices controlled by the open - close - read - write newlib functions
;			urt0
;			urt1
;			urt2
;			urt3
;			urt4
;			cdc0
;			cdc1
;			wfi0
;
;			syst
;			def0
;			stdin
;			stdout
;			stderr
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

#include	<sys/time.h>

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \defgroup newlib Newlib
 *
 * \brief Newlib
 *
 * Newlib management
 *
 * @{
 */

typedef	struct	_reent	reent_t;

// Integer equivalence of stdin, stdout, stderr

#define	KSTDIN		STDIN_FILENO
#define	KSTDOUT		STDOUT_FILENO
#define	KSTDERR		STDERR_FILENO

// This value has to be re-defined accordingly to the
// µKernel specification. For an unclear reason, the newlib
// define:
// #define _CLOCKS_PER_SEC_ 100
// in a machine/time.h

#define CLOCKS_PER_SEC_CHECK(x) ((x) == 1000000u)
static_assert(CLOCKS_PER_SEC_CHECK(_CLOCKS_PER_SEC_), "_CLOCKS_PER_SEC_ must be 1000000");

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
