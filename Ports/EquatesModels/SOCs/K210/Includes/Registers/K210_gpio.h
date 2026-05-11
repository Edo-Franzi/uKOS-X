/*
; K210_gpio.
; ==========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		K210_gpio equates.
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

// GPIO address definitions
// ------------------------

#define	GPIO_MAX_PINNO		8

// Structure for accessing GPIO registers by individual bit
// --------------------------------------------------------

typedef	struct	[[gnu::packed, gnu::aligned(4)]] _gpio_bits {
	uint32_t	b0  : 1;							//
	uint32_t	b1  : 1;							//
	uint32_t	b2  : 1;							//
	uint32_t	b3  : 1;							//
	uint32_t	b4  : 1;							//
	uint32_t	b5  : 1;							//
	uint32_t	b6  : 1;							//
	uint32_t	b7  : 1;							//
	uint32_t	b8  : 1;							//
	uint32_t	b9  : 1;							//
	uint32_t	b10 : 1;							//
	uint32_t	b11 : 1;							//
	uint32_t	b12 : 1;							//
	uint32_t	b13 : 1;							//
	uint32_t	b14 : 1;							//
	uint32_t	b15 : 1;							//
	uint32_t	b16 : 1;							//
	uint32_t	b17 : 1;							//
	uint32_t	b18 : 1;							//
	uint32_t	b19 : 1;							//
	uint32_t	b20 : 1;							//
	uint32_t	b21 : 1;							//
	uint32_t	b22 : 1;							//
	uint32_t	b23 : 1;							//
	uint32_t	b24 : 1;							//
	uint32_t	b25 : 1;							//
	uint32_t	b26 : 1;							//
	uint32_t	b27 : 1;							//
	uint32_t	b28 : 1;							//
	uint32_t	b29 : 1;							//
	uint32_t	b30 : 1;							//
	uint32_t	b31 : 1;							//
} gpio_bits_t;

// Structure of templates for accessing GPIO registers
// ---------------------------------------------------

typedef	union	[[gnu::packed, gnu::aligned(4)]] _gpio_access_tp {
	uint32_t		u32[1];							// 32x1 bit mode
	uint16_t		u16[2];							// 16x2 bit mode
	uint8_t			u8[4];							// 8x4 bit mode
	gpio_bits_t		bits;							// 1x32 bit mode
} gpio_access_tp_t;

// The GPIO address map
// --------------------

typedef	struct	[[gnu::packed, gnu::aligned(4)]] _gpio {
	gpio_access_tp_t	data_output;				// Offset 0x00: Data (output) registers
	gpio_access_tp_t	direction;					// Offset 0x04: Data direction registers
	gpio_access_tp_t	source;						// Offset 0x08: Data source registers
	uint32_t			unused_0[9];				// Offset 0x10 - 0x2f: Unused registers, 9x4 bytes
	gpio_access_tp_t	interrupt_enable;			// Offset 0x30: Interrupt enable/disable registers
	gpio_access_tp_t	interrupt_mask;				// Offset 0x34: Interrupt mask registers
	gpio_access_tp_t	interrupt_level;			// Offset 0x38: Interrupt level registers
	gpio_access_tp_t	interrupt_polarity;			// Offset 0x3c: Interrupt polarity registers
	gpio_access_tp_t	interrupt_status;			// Offset 0x40: Interrupt status registers
	gpio_access_tp_t	interrupt_status_raw;		// Offset 0x44: Raw interrupt status registers
	gpio_access_tp_t	interrupt_debounce;			// Offset 0x48: Interrupt debounce registers
	gpio_access_tp_t	interrupt_clear;			// Offset 0x4c: Registers for clearing interrupts
	gpio_access_tp_t	data_input;					// Offset 0x50: External port (data input) registers
	uint32_t			unused_1[3];				// Offset 0x54 - 0x5f: Unused registers, 3x4 bytes
	gpio_access_tp_t	sync_level;					// Offset 0x60: Sync level registers
	gpio_access_tp_t	id_code;					// Offset 0x64: ID code
	gpio_access_tp_t	interrupt_bothedge;			// Offset 0x68: Interrupt both edge type
} gpio_t;

#define	gpio	((volatile	gpio_t *)0x50200000u)
