/*
; nrf5340_network_rng.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_rng equates.
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

// RNG address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	TASKS_START;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	RESERVED0[30];
	volatile	uint32_t	SUBSCRIBE_START;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	RESERVED1[30];
	volatile	uint32_t	EVENTS_VALRDY;
	volatile	uint32_t	RESERVED2[31];
	volatile	uint32_t	PUBLISH_VALRDY;
	volatile	uint32_t	RESERVED3[31];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED4[64];
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED5[126];
	volatile	uint32_t	CONFIG;
	volatile	uint32_t	VALUE;
} RNG_TypeDef;

#if (defined(__cplusplus))
#define	RNG_NS	reinterpret_cast<RNG_TypeDef *>(0x41009000u)

#else
#define	RNG_NS	((RNG_TypeDef *)0x41009000u)
#endif

// TASKS_START Configuration

#define	RNG_TASKS_START_TASKS_START						(0x1u<<0)
#define	RNG_TASKS_START_TASKS_START_TRIGGER				(0x1u<<0)

// TASKS_STOP Configuration

#define	RNG_TASKS_STOP_TASKS_STOP						(0x1u<<0)
#define	RNG_TASKS_STOP_TASKS_STOP_TRIGGER				(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	RNG_SUBSCRIBE_START_EN							(0x1u<<31)
#define	RNG_SUBSCRIBE_START_CHIDX						(0xFFu<<0)
#define	RNG_SUBSCRIBE_START_CHIDX_0						(0x1u<<0)
#define	RNG_SUBSCRIBE_START_EN_DISABLED					(0x0u<<31)
#define	RNG_SUBSCRIBE_START_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	RNG_SUBSCRIBE_STOP_EN							(0x1u<<31)
#define	RNG_SUBSCRIBE_STOP_CHIDX						(0xFFu<<0)
#define	RNG_SUBSCRIBE_STOP_CHIDX_0						(0x1u<<0)
#define	RNG_SUBSCRIBE_STOP_EN_DISABLED					(0x0u<<31)
#define	RNG_SUBSCRIBE_STOP_EN_ENABLED					(0x1u<<31)

// EVENTS_VALRDY Configuration

#define	RNG_EVENTS_VALRDY_EVENTS_VALRDY					(0x1u<<0)
#define	RNG_EVENTS_VALRDY_EVENTS_VALRDY_NOTGENERATED	(0x0u<<0)
#define	RNG_EVENTS_VALRDY_EVENTS_VALRDY_GENERATED		(0x1u<<0)

// PUBLISH_VALRDY Configuration

#define	RNG_PUBLISH_VALRDY_EN							(0x1u<<31)
#define	RNG_PUBLISH_VALRDY_CHIDX						(0xFFu<<0)
#define	RNG_PUBLISH_VALRDY_CHIDX_0						(0x1u<<0)
#define	RNG_PUBLISH_VALRDY_EN_DISABLED					(0x0u<<31)
#define	RNG_PUBLISH_VALRDY_EN_ENABLED					(0x1u<<31)

// SHORTS Configuration

#define	RNG_SHORTS_VALRDY_STOP							(0x1u<<0)
#define	RNG_SHORTS_VALRDY_STOP_DISABLED					(0x0u<<0)
#define	RNG_SHORTS_VALRDY_STOP_ENABLED					(0x1u<<0)

// INTENSET Configuration

#define	RNG_INTENSET_VALRDY								(0x1u<<0)
#define	RNG_INTENSET_VALRDY_DISABLED					(0x0u<<0)
#define	RNG_INTENSET_VALRDY_ENABLED						(0x1u<<0)
#define	RNG_INTENSET_VALRDY_SET							(0x1u<<0)

// INTENCLR Configuration

#define	RNG_INTENCLR_VALRDY								(0x1u<<0)
#define	RNG_INTENCLR_VALRDY_DISABLED					(0x0u<<0)
#define	RNG_INTENCLR_VALRDY_ENABLED						(0x1u<<0)
#define	RNG_INTENCLR_VALRDY_CLEAR						(0x1u<<0)

// CONFIG Configuration

#define	RNG_CONFIG_DERCEN								(0x1u<<0)
#define	RNG_CONFIG_DERCEN_DISABLED						(0x0u<<0)
#define	RNG_CONFIG_DERCEN_ENABLED						(0x1u<<0)

// VALUE Configuration

#define	RNG_VALUE_VALUE									(0xFFu<<0)
#define	RNG_VALUE_VALUE_0								(0x1u<<0)
