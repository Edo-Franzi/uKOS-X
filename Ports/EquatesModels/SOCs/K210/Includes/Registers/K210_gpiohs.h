/*
; K210_gpiohs.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		K210_gpiohs equates.
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

// GPIOHS address definitions
// --------------------------

#define	GPIOHS_MAX_PINNO	32u

// Register address offsets
// ------------------------

#define	GPIOHS_INPUT_VAL	0x00u					//
#define	GPIOHS_INPUT_EN		0x04u					//
#define	GPIOHS_OUTPUT_EN	0x08u					//
#define	GPIOHS_OUTPUT_VA	0x0Cu					//
#define	GPIOHS_PULLUP_EN	0x10u					//
#define	GPIOHS_DRIVE		0x14u					//
#define	GPIOHS_RISE_IE		0x18u					//
#define	GPIOHS_RISE_IP		0x1Cu					//
#define	GPIOHS_FALL_IE		0x20u					//
#define	GPIOHS_FALL_IP		0x24u					//
#define	GPIOHS_HIGH_IE		0x28u					//
#define	GPIOHS_HIGH_IP		0x2Cu					//
#define	GPIOHS_LOW_IE		0x30u					//
#define	GPIOHS_LOW_IP		0x34u					//
#define	GPIOHS_IOF_EN		0x38u					//
#define	GPIOHS_IOF_SEL		0x3Cu					//
#define	GPIOHS_OUTPUT_XOR	0x40u					//

// GPIO bits raw object
// --------------------

typedef	struct	[[gnu::packed, gnu::aligned(4)]] _gpiohs_raw {
	uint32_t	input_val;							// Address offset 0x00
	uint32_t	input_en;							// Address offset 0x04
	uint32_t	output_en;							// Address offset 0x08
	uint32_t	output_val;							// Address offset 0x0c
	uint32_t	pullup_en;							// Address offset 0x10
	uint32_t	drive;								// Address offset 0x14
	uint32_t	rise_ie;							// Address offset 0x18
	uint32_t	rise_ip;							// Address offset 0x1c
	uint32_t	fall_ie;							// Address offset 0x20
	uint32_t	fall_ip;							// Address offset 0x24
	uint32_t	high_ie;							// Address offset 0x28
	uint32_t	high_ip;							// Address offset 0x2c
	uint32_t	low_ie;								// Address offset 0x30
	uint32_t	low_ip;								// Address offset 0x34
	uint32_t	iof_en;								// Address offset 0x38
	uint32_t	iof_sel;							// Address offset 0x3c
	uint32_t	output_xor;							// Address offset 0x40
} gpiohs_raw_t;

// Structure for accessing GPIOHS registers by individual bit
// ----------------------------------------------------------

typedef	struct	[[gnu::packed, gnu::aligned(4)]] _gpiohs_bits {
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
} gpiohs_bits_t;

// Structure of templates for accessing GPIOHS registers
// -----------------------------------------------------

typedef	union	[[gnu::packed, gnu::aligned(4)]] _gpiohs_u32 {
	uint32_t		u32[1];							// 32x1 bit mode
	uint16_t		u16[2];							// 16x2 bit mode
	uint8_t			u8[4];							// 8x4 bit mode
	gpiohs_bits_t	bits;							// 1x32 bit mode
} gpiohs_u32_t;

// The GPIOHS address map
// ----------------------

typedef	struct	[[gnu::packed, gnu::aligned(4)]] _gpiohs {
	gpiohs_u32_t	input_val;						// Address offset 0x00, Input Values
	gpiohs_u32_t	input_en;						// Address offset 0x04, Input enable
	gpiohs_u32_t	output_en;						// Address offset 0x08, Output enable
	gpiohs_u32_t	output_val;						// Address offset 0x0c, Onput Values
	gpiohs_u32_t	pullup_en;						// Address offset 0x10, Internal Pull-Ups enable
	gpiohs_u32_t	drive;							// Address offset 0x14, Drive Strength
	gpiohs_u32_t	rise_ie;						// Address offset 0x18, Rise interrupt enable
	gpiohs_u32_t	rise_ip;						// Address offset 0x1c, Rise interrupt pending
	gpiohs_u32_t	fall_ie;						// Address offset 0x20, Fall interrupt enable
	gpiohs_u32_t	fall_ip;						// Address offset 0x24, Fall interrupt pending
	gpiohs_u32_t	high_ie;						// Address offset 0x28, High interrupt enable
	gpiohs_u32_t	high_ip;						// Address offset 0x2c, High interrupt pending
	gpiohs_u32_t	low_ie;							// Address offset 0x30, Low interrupt enable
	gpiohs_u32_t	low_ip;							// Address offset 0x34, Low interrupt pending
	gpiohs_u32_t	iof_en;							// Address offset 0x38, HW I/O Function enable
	gpiohs_u32_t	iof_sel;						// Address offset 0x3c, HW I/O Function select
	gpiohs_u32_t	output_xor;						// Address offset 0x40, Output XOR (invert)
} gpiohs_t;

#define	gpiohs	((volatile	gpiohs_t *)0x38001000u)
