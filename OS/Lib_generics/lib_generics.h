/*
; lib_generics.
; =============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		lib_generics system call interface module.
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

/*!
 * \defgroup Lib_generics Library for generic manager
 *
 * \brief Generic manager system calls
 *
 * The Lib_generics library offers a set of managers that illustrate how a
 * system may combine order and efficiency. Each manager contributes a unique
 * service, yet all together they form a coherent foundation.
 *
 * The asmp manager demonstrates multi-processor control. It divides work
 * among processors, ensuring that heavy tasks may be shared and completed with
 * speed and balance.
 *
 * The calendar manager focuses on time. It parses dates, handles calendars,
 * and measures intervals, allowing events to be scheduled and coordinated.
 *
 * The machine manager provides access to low-level resources. It observes
 * the hardware closely and offers precise control where performance matters.
 *
 * The memo manager governs memory. By allocating and freeing space, it
 * preserves safety, prevents leaks, and ensures resources are well used.
 *
 * The newlib manager supports the familiar functions of the C library. It
 * guarantees that formatted output and essential utilities remain reliable.
 *
 * The system manager explores the environment. It searches modules, adapts
 * to settings, and lets the programme integrate with its wider context.
 *
 * The text manager treats ASCII lines with care. It splits commands into
 * arguments, so that human input may be transformed into clear instruction.
 *
 * Together these managers show that discipline and design can live side by side.
 * Lib_generics is both a toolbox for developers and a lesson in clarity.
 *
 * @{
 */

// IWYU pragma: begin_exports

#if (defined(CONFIG_MAN_TEXT_S))
#include	"text/text.h"
#endif
#if (defined(CONFIG_MAN_MEMO_S))
#include	"memo/memo.h"
#endif
#if (defined(CONFIG_MAN_ASMP_S))
#include	"asmp/asmp.h"
#endif
#if (defined(CONFIG_MAN_SYSTEM_S))
#include	"system/system.h"
#endif
#if (defined(CONFIG_MAN_MACHINE_S))
#include	"machine/machine.h"
#endif
#if (defined(CONFIG_MAN_CALENDAR_S))
#include	"calendar/calendar.h"
#endif

// dprintf and record_trace
// These functions are always defined.

#include	"record/record.h"
#include	"newlib/newlib.h"

// IWYU pragma: end_exports

/**!@}*/
