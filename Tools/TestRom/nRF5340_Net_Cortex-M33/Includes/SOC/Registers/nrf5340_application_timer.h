/*
; nrf5340_application_timer.
; ==========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_timer equates.
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

// TIMER address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	TASKS_START;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	TASKS_COUNT;
	volatile	uint32_t	TASKS_CLEAR;
	volatile	uint32_t	TASKS_SHUTDOWN;
	volatile	uint32_t	RESERVED0[11];
	volatile	uint32_t	TASKS_CAPTURE[6];
	volatile	uint32_t	RESERVED1[10];
	volatile	uint32_t	SUBSCRIBE_START;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	SUBSCRIBE_COUNT;
	volatile	uint32_t	SUBSCRIBE_CLEAR;
	volatile	uint32_t	SUBSCRIBE_SHUTDOWN;
	volatile	uint32_t	RESERVED2[11];
	volatile	uint32_t	SUBSCRIBE_CAPTURE[6];
	volatile	uint32_t	RESERVED3[26];
	volatile	uint32_t	EVENTS_COMPARE[6];
	volatile	uint32_t	RESERVED4[26];
	volatile	uint32_t	PUBLISH_COMPARE[6];
	volatile	uint32_t	RESERVED5[10];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED6[63];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED7[126];
	volatile	uint32_t	MODE;
	volatile	uint32_t	BITMODE;
	volatile	uint32_t	RESERVED8;
	volatile	uint32_t	PRESCALER;
	volatile	uint32_t	RESERVED9[11];
	volatile	uint32_t	CC[6];
	volatile	uint32_t	RESERVED10[10];
	volatile	uint32_t	ONESHOTEN[6];
} TIMER_TypeDef;

#if (defined(__cplusplus))
#define	TIMER0_NS	reinterpret_cast<TIMER_TypeDef *>(0x4000F000u)
#define	TIMER0_S	reinterpret_cast<TIMER_TypeDef *>(0x5000F000u)
#define	TIMER1_NS	reinterpret_cast<TIMER_TypeDef *>(0x40010000u)
#define	TIMER1_S	reinterpret_cast<TIMER_TypeDef *>(0x50010000u)
#define	TIMER2_NS	reinterpret_cast<TIMER_TypeDef *>(0x40011000u)
#define	TIMER2_S	reinterpret_cast<TIMER_TypeDef *>(0x50011000u)

#else
#define	TIMER0_NS	((TIMER_TypeDef *)0x4000F000u)
#define	TIMER0_S	((TIMER_TypeDef *)0x5000F000u)
#define	TIMER1_NS	((TIMER_TypeDef *)0x40010000u)
#define	TIMER1_S	((TIMER_TypeDef *)0x50010000u)
#define	TIMER2_NS	((TIMER_TypeDef *)0x40011000u)
#define	TIMER2_S	((TIMER_TypeDef *)0x50011000u)
#endif

// TASKS_START Configuration

#define	TIMER_TASKS_START_TASKS_START						(0x1u<<0)
#define	TIMER_TASKS_START_TASKS_START_TRIGGER				(0x1u<<0)

// TASKS_STOP Configuration

#define	TIMER_TASKS_STOP_TASKS_STOP							(0x1u<<0)
#define	TIMER_TASKS_STOP_TASKS_STOP_TRIGGER					(0x1u<<0)

// TASKS_COUNT Configuration

#define	TIMER_TASKS_COUNT_TASKS_COUNT						(0x1u<<0)
#define	TIMER_TASKS_COUNT_TASKS_COUNT_TRIGGER				(0x1u<<0)

// TASKS_CLEAR Configuration

#define	TIMER_TASKS_CLEAR_TASKS_CLEAR						(0x1u<<0)
#define	TIMER_TASKS_CLEAR_TASKS_CLEAR_TRIGGER				(0x1u<<0)

// TASKS_SHUTDOWN Configuration

#define	TIMER_TASKS_SHUTDOWN_TASKS_SHUTDOWN					(0x1u<<0)
#define	TIMER_TASKS_SHUTDOWN_TASKS_SHUTDOWN_TRIGGER			(0x1u<<0)

// TASKS_CAPTURE Configuration

#define	TIMER_TASKS_CAPTURE_TASKS_CAPTURE					(0x1u<<0)
#define	TIMER_TASKS_CAPTURE_TASKS_CAPTURE_TRIGGER			(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	TIMER_SUBSCRIBE_START_EN							(0x1u<<31)
#define	TIMER_SUBSCRIBE_START_CHIDX							(0xFFu<<0)
#define	TIMER_SUBSCRIBE_START_CHIDX_0						(0x1u<<0)
#define	TIMER_SUBSCRIBE_START_EN_DISABLED					(0x0u<<31)
#define	TIMER_SUBSCRIBE_START_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	TIMER_SUBSCRIBE_STOP_EN								(0x1u<<31)
#define	TIMER_SUBSCRIBE_STOP_CHIDX							(0xFFu<<0)
#define	TIMER_SUBSCRIBE_STOP_CHIDX_0						(0x1u<<0)
#define	TIMER_SUBSCRIBE_STOP_EN_DISABLED					(0x0u<<31)
#define	TIMER_SUBSCRIBE_STOP_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_COUNT Configuration

#define	TIMER_SUBSCRIBE_COUNT_EN							(0x1u<<31)
#define	TIMER_SUBSCRIBE_COUNT_CHIDX							(0xFFu<<0)
#define	TIMER_SUBSCRIBE_COUNT_CHIDX_0						(0x1u<<0)
#define	TIMER_SUBSCRIBE_COUNT_EN_DISABLED					(0x0u<<31)
#define	TIMER_SUBSCRIBE_COUNT_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_CLEAR Configuration

#define	TIMER_SUBSCRIBE_CLEAR_EN							(0x1u<<31)
#define	TIMER_SUBSCRIBE_CLEAR_CHIDX							(0xFFu<<0)
#define	TIMER_SUBSCRIBE_CLEAR_CHIDX_0						(0x1u<<0)
#define	TIMER_SUBSCRIBE_CLEAR_EN_DISABLED					(0x0u<<31)
#define	TIMER_SUBSCRIBE_CLEAR_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_SHUTDOWN Configuration

#define	TIMER_SUBSCRIBE_SHUTDOWN_EN							(0x1u<<31)
#define	TIMER_SUBSCRIBE_SHUTDOWN_CHIDX						(0xFFu<<0)
#define	TIMER_SUBSCRIBE_SHUTDOWN_CHIDX_0					(0x1u<<0)
#define	TIMER_SUBSCRIBE_SHUTDOWN_EN_DISABLED				(0x0u<<31)
#define	TIMER_SUBSCRIBE_SHUTDOWN_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_CAPTURE Configuration

#define	TIMER_SUBSCRIBE_CAPTURE_EN							(0x1u<<31)
#define	TIMER_SUBSCRIBE_CAPTURE_CHIDX						(0xFFu<<0)
#define	TIMER_SUBSCRIBE_CAPTURE_CHIDX_0						(0x1u<<0)
#define	TIMER_SUBSCRIBE_CAPTURE_EN_DISABLED					(0x0u<<31)
#define	TIMER_SUBSCRIBE_CAPTURE_EN_ENABLED					(0x1u<<31)

// EVENTS_COMPARE Configuration

#define	TIMER_EVENTS_COMPARE_EVENTS_COMPARE					(0x1u<<0)
#define	TIMER_EVENTS_COMPARE_EVENTS_COMPARE_NOTGENERATED	(0x0u<<0)
#define	TIMER_EVENTS_COMPARE_EVENTS_COMPARE_GENERATED		(0x1u<<0)

// PUBLISH_COMPARE Configuration

#define	TIMER_PUBLISH_COMPARE_EN							(0x1u<<31)
#define	TIMER_PUBLISH_COMPARE_CHIDX							(0xFFu<<0)
#define	TIMER_PUBLISH_COMPARE_CHIDX_0						(0x1u<<0)
#define	TIMER_PUBLISH_COMPARE_EN_DISABLED					(0x0u<<31)
#define	TIMER_PUBLISH_COMPARE_EN_ENABLED					(0x1u<<31)

// SHORTS Configuration

#define	TIMER_SHORTS_COMPARE5_STOP							(0x1u<<21)
#define	TIMER_SHORTS_COMPARE4_STOP							(0x1u<<20)
#define	TIMER_SHORTS_COMPARE3_STOP							(0x1u<<19)
#define	TIMER_SHORTS_COMPARE2_STOP							(0x1u<<18)
#define	TIMER_SHORTS_COMPARE1_STOP							(0x1u<<17)
#define	TIMER_SHORTS_COMPARE0_STOP							(0x1u<<16)
#define	TIMER_SHORTS_COMPARE5_CLEAR							(0x1u<<5)
#define	TIMER_SHORTS_COMPARE4_CLEAR							(0x1u<<4)
#define	TIMER_SHORTS_COMPARE3_CLEAR							(0x1u<<3)
#define	TIMER_SHORTS_COMPARE2_CLEAR							(0x1u<<2)
#define	TIMER_SHORTS_COMPARE1_CLEAR							(0x1u<<1)
#define	TIMER_SHORTS_COMPARE0_CLEAR							(0x1u<<0)
#define	TIMER_SHORTS_COMPARE5_STOP_DISABLED					(0x0u<<21)
#define	TIMER_SHORTS_COMPARE5_STOP_ENABLED					(0x1u<<21)
#define	TIMER_SHORTS_COMPARE4_STOP_DISABLED					(0x0u<<20)
#define	TIMER_SHORTS_COMPARE4_STOP_ENABLED					(0x1u<<20)
#define	TIMER_SHORTS_COMPARE3_STOP_DISABLED					(0x0u<<19)
#define	TIMER_SHORTS_COMPARE3_STOP_ENABLED					(0x1u<<19)
#define	TIMER_SHORTS_COMPARE2_STOP_DISABLED					(0x0u<<18)
#define	TIMER_SHORTS_COMPARE2_STOP_ENABLED					(0x1u<<18)
#define	TIMER_SHORTS_COMPARE1_STOP_DISABLED					(0x0u<<17)
#define	TIMER_SHORTS_COMPARE1_STOP_ENABLED					(0x1u<<17)
#define	TIMER_SHORTS_COMPARE0_STOP_DISABLED					(0x0u<<16)
#define	TIMER_SHORTS_COMPARE0_STOP_ENABLED					(0x1u<<16)
#define	TIMER_SHORTS_COMPARE5_CLEAR_DISABLED				(0x0u<<5)
#define	TIMER_SHORTS_COMPARE5_CLEAR_ENABLED					(0x1u<<5)
#define	TIMER_SHORTS_COMPARE4_CLEAR_DISABLED				(0x0u<<4)
#define	TIMER_SHORTS_COMPARE4_CLEAR_ENABLED					(0x1u<<4)
#define	TIMER_SHORTS_COMPARE3_CLEAR_DISABLED				(0x0u<<3)
#define	TIMER_SHORTS_COMPARE3_CLEAR_ENABLED					(0x1u<<3)
#define	TIMER_SHORTS_COMPARE2_CLEAR_DISABLED				(0x0u<<2)
#define	TIMER_SHORTS_COMPARE2_CLEAR_ENABLED					(0x1u<<2)
#define	TIMER_SHORTS_COMPARE1_CLEAR_DISABLED				(0x0u<<1)
#define	TIMER_SHORTS_COMPARE1_CLEAR_ENABLED					(0x1u<<1)
#define	TIMER_SHORTS_COMPARE0_CLEAR_DISABLED				(0x0u<<0)
#define	TIMER_SHORTS_COMPARE0_CLEAR_ENABLED					(0x1u<<0)

// INTEN Configuration

#define	TIMER_INTEN_COMPARE5								(0x1u<<21)
#define	TIMER_INTEN_COMPARE4								(0x1u<<20)
#define	TIMER_INTEN_COMPARE3								(0x1u<<19)
#define	TIMER_INTEN_COMPARE2								(0x1u<<18)
#define	TIMER_INTEN_COMPARE1								(0x1u<<17)
#define	TIMER_INTEN_COMPARE0								(0x1u<<16)
#define	TIMER_INTEN_COMPARE5_DISABLED						(0x0u<<21)
#define	TIMER_INTEN_COMPARE5_ENABLED						(0x1u<<21)
#define	TIMER_INTEN_COMPARE4_DISABLED						(0x0u<<20)
#define	TIMER_INTEN_COMPARE4_ENABLED						(0x1u<<20)
#define	TIMER_INTEN_COMPARE3_DISABLED						(0x0u<<19)
#define	TIMER_INTEN_COMPARE3_ENABLED						(0x1u<<19)
#define	TIMER_INTEN_COMPARE2_DISABLED						(0x0u<<18)
#define	TIMER_INTEN_COMPARE2_ENABLED						(0x1u<<18)
#define	TIMER_INTEN_COMPARE1_DISABLED						(0x0u<<17)
#define	TIMER_INTEN_COMPARE1_ENABLED						(0x1u<<17)
#define	TIMER_INTEN_COMPARE0_DISABLED						(0x0u<<16)
#define	TIMER_INTEN_COMPARE0_ENABLED						(0x1u<<16)

// INTENSET Configuration

#define	TIMER_INTENSET_COMPARE5								(0x1u<<21)
#define	TIMER_INTENSET_COMPARE4								(0x1u<<20)
#define	TIMER_INTENSET_COMPARE3								(0x1u<<19)
#define	TIMER_INTENSET_COMPARE2								(0x1u<<18)
#define	TIMER_INTENSET_COMPARE1								(0x1u<<17)
#define	TIMER_INTENSET_COMPARE0								(0x1u<<16)
#define	TIMER_INTENSET_COMPARE5_DISABLED					(0x0u<<21)
#define	TIMER_INTENSET_COMPARE5_ENABLED						(0x1u<<21)
#define	TIMER_INTENSET_COMPARE5_SET							(0x1u<<21)
#define	TIMER_INTENSET_COMPARE4_DISABLED					(0x0u<<20)
#define	TIMER_INTENSET_COMPARE4_ENABLED						(0x1u<<20)
#define	TIMER_INTENSET_COMPARE4_SET							(0x1u<<20)
#define	TIMER_INTENSET_COMPARE3_DISABLED					(0x0u<<19)
#define	TIMER_INTENSET_COMPARE3_ENABLED						(0x1u<<19)
#define	TIMER_INTENSET_COMPARE3_SET							(0x1u<<19)
#define	TIMER_INTENSET_COMPARE2_DISABLED					(0x0u<<18)
#define	TIMER_INTENSET_COMPARE2_ENABLED						(0x1u<<18)
#define	TIMER_INTENSET_COMPARE2_SET							(0x1u<<18)
#define	TIMER_INTENSET_COMPARE1_DISABLED					(0x0u<<17)
#define	TIMER_INTENSET_COMPARE1_ENABLED						(0x1u<<17)
#define	TIMER_INTENSET_COMPARE1_SET							(0x1u<<17)
#define	TIMER_INTENSET_COMPARE0_DISABLED					(0x0u<<16)
#define	TIMER_INTENSET_COMPARE0_ENABLED						(0x1u<<16)
#define	TIMER_INTENSET_COMPARE0_SET							(0x1u<<16)

// INTENCLR Configuration

#define	TIMER_INTENCLR_COMPARE5								(0x1u<<21)
#define	TIMER_INTENCLR_COMPARE4								(0x1u<<20)
#define	TIMER_INTENCLR_COMPARE3								(0x1u<<19)
#define	TIMER_INTENCLR_COMPARE2								(0x1u<<18)
#define	TIMER_INTENCLR_COMPARE1								(0x1u<<17)
#define	TIMER_INTENCLR_COMPARE0								(0x1u<<16)
#define	TIMER_INTENCLR_COMPARE5_DISABLED					(0x0u<<21)
#define	TIMER_INTENCLR_COMPARE5_ENABLED						(0x1u<<21)
#define	TIMER_INTENCLR_COMPARE5_CLEAR						(0x1u<<21)
#define	TIMER_INTENCLR_COMPARE4_DISABLED					(0x0u<<20)
#define	TIMER_INTENCLR_COMPARE4_ENABLED						(0x1u<<20)
#define	TIMER_INTENCLR_COMPARE4_CLEAR						(0x1u<<20)
#define	TIMER_INTENCLR_COMPARE3_DISABLED					(0x0u<<19)
#define	TIMER_INTENCLR_COMPARE3_ENABLED						(0x1u<<19)
#define	TIMER_INTENCLR_COMPARE3_CLEAR						(0x1u<<19)
#define	TIMER_INTENCLR_COMPARE2_DISABLED					(0x0u<<18)
#define	TIMER_INTENCLR_COMPARE2_ENABLED						(0x1u<<18)
#define	TIMER_INTENCLR_COMPARE2_CLEAR						(0x1u<<18)
#define	TIMER_INTENCLR_COMPARE1_DISABLED					(0x0u<<17)
#define	TIMER_INTENCLR_COMPARE1_ENABLED						(0x1u<<17)
#define	TIMER_INTENCLR_COMPARE1_CLEAR						(0x1u<<17)
#define	TIMER_INTENCLR_COMPARE0_DISABLED					(0x0u<<16)
#define	TIMER_INTENCLR_COMPARE0_ENABLED						(0x1u<<16)
#define	TIMER_INTENCLR_COMPARE0_CLEAR						(0x1u<<16)

// MODE Configuration

#define	TIMER_MODE_MODE										(0x3u<<0)
#define	TIMER_MODE_MODE_0									(0x1u<<0)
#define	TIMER_MODE_MODE_TIMER								(0x0u<<0)
#define	TIMER_MODE_MODE_COUNTER								(0x1u<<0)
#define	TIMER_MODE_MODE_LOWPOWERCOUNTER						(0x2u<<0)

// BITMODE Configuration

#define	TIMER_BITMODE_BITMODE								(0x3u<<0)
#define	TIMER_BITMODE_BITMODE_0								(0x1u<<0)
#define	TIMER_BITMODE_BITMODE_16BIT							(0x0u<<0)
#define	TIMER_BITMODE_BITMODE_08BIT							(0x1u<<0)
#define	TIMER_BITMODE_BITMODE_24BIT							(0x2u<<0)
#define	TIMER_BITMODE_BITMODE_32BIT							(0x3u<<0)

// PRESCALER Configuration

#define	TIMER_PRESCALER_PRESCALER							(0xFu<<0)
#define	TIMER_PRESCALER_PRESCALER_0							(0x1u<<0)

// CC Configuration

#define	TIMER_CC_CC											(0xFFFFFFFFu<<0)
#define	TIMER_CC_CC_0										(0x1u<<0)

// ONESHOTEN Configuration

#define	TIMER_ONESHOTEN_ONESHOTEN							(0x1u<<0)
#define	TIMER_ONESHOTEN_ONESHOTEN_DISABLE					(0x0u<<0)
#define	TIMER_ONESHOTEN_ONESHOTEN_ENABLE					(0x1u<<0)
