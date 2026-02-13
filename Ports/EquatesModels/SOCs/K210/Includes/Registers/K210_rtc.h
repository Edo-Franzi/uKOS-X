/*
; K210_rtc.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Laurent von Allmen		The 2026-02-13
; Author:	Claude Code (Anthropic)	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		K210_rtc equates.
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

// RTC register table
// ------------------

//  | Offset    | Name           | Description                         |
//  |-----------|----------------|-------------------------------------|
//  | 0x00      | date           | Timer date information              |
//  | 0x04      | time           | Timer time information              |
//  | 0x08      | alarm_date     | Alarm date information              |
//  | 0x0c      | alarm_time     | Alarm time information              |
//  | 0x10      | initial_count  | Timer counter initial value         |
//  | 0x14      | current_count  | Timer counter current value         |
//  | 0x18      | interrupt_ctrl | RTC interrupt settings              |
//  | 0x1c      | register_ctrl  | RTC register settings               |
//  | 0x20      | reserved0      | Reserved                            |
//  | 0x24      | reserved1      | Reserved                            |
//  | 0x28      | extended       | Timer extended information          |

// Timer date information
// ----------------------

typedef	struct	_rtc_date {
	uint32_t	week     : 3;						// Week. Range [0,6]
	uint32_t	reserved : 5;						// Reserved
	uint32_t	day      : 5;						// Day. Range [1,31]
	uint32_t	reserved0: 3;						// Reserved
	uint32_t	month    : 4;						// Month. Range [1,12]
	uint32_t	reserved1: 4;						// Reserved
	uint32_t	year     : 8;						// Year. Range [0,99]
} __attribute__ ((packed, aligned (4))) rtc_date_t;

// Timer time information
// ----------------------

typedef	struct	_rtc_time {
	uint32_t	reserved : 10;						// Reserved
	uint32_t	second   : 6;						// Second. Range [0,59]
	uint32_t	minute   : 6;						// Minute. Range [0,59]
	uint32_t	reserved0: 2;						// Reserved
	uint32_t	hour     : 5;						// Hour. Range [0,23]
	uint32_t	reserved1: 3;						// Reserved
} __attribute__ ((packed, aligned (4))) rtc_time_t;

// Timer counter initial value
// ---------------------------

typedef	struct	_rtc_initial_count {
	uint32_t	count    : 32;						// RTC counter initial value
} __attribute__ ((packed, aligned (4))) rtc_initial_count_t;

// Timer counter current value
// ---------------------------

typedef	struct	_rtc_current_count {
	uint32_t	count    : 32;						// RTC counter current value
} __attribute__ ((packed, aligned (4))) rtc_current_count_t;

// RTC interrupt settings
// ----------------------

typedef	struct	_rtc_interrupt_ctrl {
	uint32_t	tick_enable        : 1;				// Tick interrupt enable
	uint32_t	alarm_enable       : 1;				// Alarm interrupt enable
	uint32_t	tick_int_mode      : 2;				// Tick interrupt mode
	uint32_t	reserved           : 20;			// Reserved
	uint32_t	alarm_compare_mask : 8;				// Alarm compare mask for interrupt
} __attribute__ ((packed, aligned (4))) rtc_interrupt_ctrl_t;

// RTC register settings
// ---------------------

typedef	struct	_rtc_register_ctrl {
	uint32_t	read_enable            : 1;			// RTC timer read enable
	uint32_t	write_enable           : 1;			// RTC timer write enable
	uint32_t	reserved               : 11;		// Reserved
	uint32_t	timer_mask             : 8;			// RTC timer mask
	uint32_t	alarm_mask             : 8;			// RTC alarm mask
	uint32_t	initial_count_mask     : 1;			// RTC counter initial count value mask
	uint32_t	interrupt_register_mask: 1;			// RTC interrupt register mask
	uint32_t	reserved0              : 1;			// Reserved
} __attribute__ ((packed, aligned (4))) rtc_register_ctrl_t;

// Timer extended information
// --------------------------

typedef	struct	_rtc_extended {
	uint32_t	century       : 5;					// Century. Range [0,31]
	uint32_t	leap_year     : 1;					// Is leap year. 1 is leap year, 0 is not
	uint32_t	reserved      : 26;					// Reserved
} __attribute__ ((packed, aligned (4))) rtc_extended_t;

// RTC object
// ----------

typedef	struct	_rtc {
	rtc_date_t			date;					// No. 0 (0x00): Timer date information
	rtc_time_t			time;					// No. 1 (0x04): Timer time information
	rtc_date_t			alarm_date;				// No. 2 (0x08): Alarm date information
	rtc_time_t			alarm_time;				// No. 3 (0x0c): Alarm time information
	rtc_initial_count_t	initial_count;			// No. 4 (0x10): Timer counter initial value
	rtc_current_count_t	current_count;			// No. 5 (0x14): Timer counter current value
	rtc_interrupt_ctrl_t interrupt_ctrl;		// No. 6 (0x18): RTC interrupt settings
	rtc_register_ctrl_t	register_ctrl;			// No. 7 (0x1c): RTC register settings
	uint32_t			reserved0;				// No. 8 (0x20): Reserved
	uint32_t			reserved1;				// No. 9 (0x24): Reserved
	rtc_extended_t		extended;				// No. 10 (0x28): Timer extended information
} __attribute__ ((packed, aligned (4))) rtc_t;

#define	rtc		((volatile rtc_t *)0x50460000u)
