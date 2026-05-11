/*
; K210_timer.
; ===========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		K210_timer equates.
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

// TIMER devices number
// --------------------

typedef	enum	_timer_deivce_number {
	TIMER_DEVICE_0,									//
	TIMER_DEVICE_1,									//
	TIMER_DEVICE_2,									//
	TIMER_DEVICE_MAX								//
} timer_device_number_t;

// TIMER channel number
// --------------------

typedef	enum	_timer_channel_number {
	TIMER_CHANNEL_0,								//
	TIMER_CHANNEL_1,								//
	TIMER_CHANNEL_2,								//
	TIMER_CHANNEL_3,								//
	TIMER_CHANNEL_MAX								//
} timer_channel_number_t;

// TIMER Control Register
// ----------------------

#define	TIMER_CR_ENABLE				0x00000001u		//
#define	TIMER_CR_MODE_MASK			0x00000002u		//
#define	TIMER_CR_FREE_MODE			0x00000000u		//
#define	TIMER_CR_USER_MODE			0x00000002u		//
#define	TIMER_CR_INTERRUPT_MASK		0x00000004u		//
#define	TIMER_CR_PWM_ENABLE			0x00000008u		//

// The TIMER address map
// ---------------------

typedef	struct	[[gnu::packed, gnu::aligned(4)]] _timer_channel {

	volatile	uint32_t		load_count;			// TIMER_N Load Count Register              (0x00+(N-1)*0x14)
	volatile	uint32_t		current_value;		// TIMER_N Current Value Register           (0x04+(N-1)*0x14)
	volatile	uint32_t		control;			// TIMER_N Control Register                 (0x08+(N-1)*0x14)
	volatile	uint32_t		eoi;				// TIMER_N Interrupt Clear Register         (0x0c+(N-1)*0x14)
	volatile	uint32_t		intr_stat;			// TIMER_N Interrupt Status Register        (0x10+(N-1)*0x14)
} timer_channel_t;

typedef	struct	[[gnu::packed, gnu::aligned(4)]] _kendryte_timer {
	volatile	timer_channel_t	channel[4];			// TIMER_N Register                         (0x00-0x4c)
	volatile	uint32_t		resv1[20];			// reserverd                                (0x50-0x9c)
	volatile	uint32_t		intr_stat;			// TIMER Interrupt Status Register          (0xa0)
	volatile	uint32_t		eoi;				// TIMER Interrupt Clear Register           (0xa4)
	volatile	uint32_t		raw_intr_stat;		// TIMER Raw Interrupt Status Register      (0xa8)
	volatile	uint32_t		comp_version;		// TIMER Component Version Register         (0xac)
	volatile	uint32_t		load_count2[4];		// TIMER_N Load Count2 Register             (0xb0-0xbc)
} kendryte_timer_t;

#define	timer0	((volatile	kendryte_timer_t *)0x502D0000u)
#define	timer1	((volatile	kendryte_timer_t *)0x502E0000u)
#define	timer2	((volatile	kendryte_timer_t *)0x502F0000u)
