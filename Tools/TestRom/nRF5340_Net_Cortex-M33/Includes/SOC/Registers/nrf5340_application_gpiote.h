/*
; nrf5340_application_gpiote.
; ===========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_gpiote equates.
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

// GPIOTE address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	TASKS_OUT[8];
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	TASKS_SET[8];
	volatile	uint32_t	RESERVED1[4];
	volatile	uint32_t	TASKS_CLR[8];
	volatile	uint32_t	SUBSCRIBE_OUT[8];
	volatile	uint32_t	RESERVED2[4];
	volatile	uint32_t	SUBSCRIBE_SET[8];
	volatile	uint32_t	RESERVED3[4];
	volatile	uint32_t	SUBSCRIBE_CLR[8];
	volatile	uint32_t	EVENTS_IN[8];
	volatile	uint32_t	RESERVED4[23];
	volatile	uint32_t	EVENTS_PORT;
	volatile	uint32_t	PUBLISH_IN[8];
	volatile	uint32_t	RESERVED5[23];
	volatile	uint32_t	PUBLISH_PORT;
	volatile	uint32_t	RESERVED6[65];
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED7[126];
	volatile	uint32_t	LATENCY;
	volatile	uint32_t	RESERVED8[2];
	volatile	uint32_t	CONFIG[8];
} GPIOTE_TypeDef;

#if (defined(__cplusplus))
#define	GPIOTE0_S	reinterpret_cast<GPIOTE_TypeDef *>(0x5000D000u)
#define	GPIOTE1_NS	reinterpret_cast<GPIOTE_TypeDef *>(0x4002F000u)

#else
#define	GPIOTE0_S	((GPIOTE_TypeDef *)0x5000D000u)
#define	GPIOTE1_NS	((GPIOTE_TypeDef *)0x4002F000u)
#endif

// TASKS_OUT Configuration

#define	GPIOTE_TASKS_OUT_TASKS_OUT					(0x1u<<0)
#define	GPIOTE_TASKS_OUT_TASKS_OUT_TRIGGER			(0x1u<<0)

// TASKS_SET Configuration

#define	GPIOTE_TASKS_SET_TASKS_SET					(0x1u<<0)
#define	GPIOTE_TASKS_SET_TASKS_SET_TRIGGER			(0x1u<<0)

// TASKS_CLR Configuration

#define	GPIOTE_TASKS_CLR_TASKS_CLR					(0x1u<<0)
#define	GPIOTE_TASKS_CLR_TASKS_CLR_TRIGGER			(0x1u<<0)

// SUBSCRIBE_OUT Configuration

#define	GPIOTE_SUBSCRIBE_OUT_EN						(0x1u<<31)
#define	GPIOTE_SUBSCRIBE_OUT_CHIDX					(0xFFu<<0)
#define	GPIOTE_SUBSCRIBE_OUT_CHIDX_0				(0x1u<<0)
#define	GPIOTE_SUBSCRIBE_OUT_EN_DISABLED			(0x0u<<31)
#define	GPIOTE_SUBSCRIBE_OUT_EN_ENABLED				(0x1u<<31)

// SUBSCRIBE_SET Configuration

#define	GPIOTE_SUBSCRIBE_SET_EN						(0x1u<<31)
#define	GPIOTE_SUBSCRIBE_SET_CHIDX					(0xFFu<<0)
#define	GPIOTE_SUBSCRIBE_SET_CHIDX_0				(0x1u<<0)
#define	GPIOTE_SUBSCRIBE_SET_EN_DISABLED			(0x0u<<31)
#define	GPIOTE_SUBSCRIBE_SET_EN_ENABLED				(0x1u<<31)

// SUBSCRIBE_CLR Configuration

#define	GPIOTE_SUBSCRIBE_CLR_EN						(0x1u<<31)
#define	GPIOTE_SUBSCRIBE_CLR_CHIDX					(0xFFu<<0)
#define	GPIOTE_SUBSCRIBE_CLR_CHIDX_0				(0x1u<<0)
#define	GPIOTE_SUBSCRIBE_CLR_EN_DISABLED			(0x0u<<31)
#define	GPIOTE_SUBSCRIBE_CLR_EN_ENABLED				(0x1u<<31)

// EVENTS_IN Configuration

#define	GPIOTE_EVENTS_IN_EVENTS_IN					(0x1u<<0)
#define	GPIOTE_EVENTS_IN_EVENTS_IN_NOTGENERATED		(0x0u<<0)
#define	GPIOTE_EVENTS_IN_EVENTS_IN_GENERATED		(0x1u<<0)

// EVENTS_PORT Configuration

#define	GPIOTE_EVENTS_PORT_EVENTS_PORT				(0x1u<<0)
#define	GPIOTE_EVENTS_PORT_EVENTS_PORT_NOTGENERATED	(0x0u<<0)
#define	GPIOTE_EVENTS_PORT_EVENTS_PORT_GENERATED	(0x1u<<0)

// PUBLISH_IN Configuration

#define	GPIOTE_PUBLISH_IN_EN						(0x1u<<31)
#define	GPIOTE_PUBLISH_IN_CHIDX						(0xFFu<<0)
#define	GPIOTE_PUBLISH_IN_CHIDX_0					(0x1u<<0)
#define	GPIOTE_PUBLISH_IN_EN_DISABLED				(0x0u<<31)
#define	GPIOTE_PUBLISH_IN_EN_ENABLED				(0x1u<<31)

// PUBLISH_PORT Configuration

#define	GPIOTE_PUBLISH_PORT_EN						(0x1u<<31)
#define	GPIOTE_PUBLISH_PORT_CHIDX					(0xFFu<<0)
#define	GPIOTE_PUBLISH_PORT_CHIDX_0					(0x1u<<0)
#define	GPIOTE_PUBLISH_PORT_EN_DISABLED				(0x0u<<31)
#define	GPIOTE_PUBLISH_PORT_EN_ENABLED				(0x1u<<31)

// INTENSET Configuration

#define	GPIOTE_INTENSET_PORT						(0x1u<<31)
#define	GPIOTE_INTENSET_IN7							(0x1u<<7)
#define	GPIOTE_INTENSET_IN6							(0x1u<<6)
#define	GPIOTE_INTENSET_IN5							(0x1u<<5)
#define	GPIOTE_INTENSET_IN4							(0x1u<<4)
#define	GPIOTE_INTENSET_IN3							(0x1u<<3)
#define	GPIOTE_INTENSET_IN2							(0x1u<<2)
#define	GPIOTE_INTENSET_IN1							(0x1u<<1)
#define	GPIOTE_INTENSET_IN0							(0x1u<<0)
#define	GPIOTE_INTENSET_PORT_DISABLED				(0x0u<<31)
#define	GPIOTE_INTENSET_PORT_ENABLED				(0x1u<<31)
#define	GPIOTE_INTENSET_PORT_SET					(0x1u<<31)
#define	GPIOTE_INTENSET_IN7_DISABLED				(0x0u<<7)
#define	GPIOTE_INTENSET_IN7_ENABLED					(0x1u<<7)
#define	GPIOTE_INTENSET_IN7_SET						(0x1u<<7)
#define	GPIOTE_INTENSET_IN6_DISABLED				(0x0u<<6)
#define	GPIOTE_INTENSET_IN6_ENABLED					(0x1u<<6)
#define	GPIOTE_INTENSET_IN6_SET						(0x1u<<6)
#define	GPIOTE_INTENSET_IN5_DISABLED				(0x0u<<5)
#define	GPIOTE_INTENSET_IN5_ENABLED					(0x1u<<5)
#define	GPIOTE_INTENSET_IN5_SET						(0x1u<<5)
#define	GPIOTE_INTENSET_IN4_DISABLED				(0x0u<<4)
#define	GPIOTE_INTENSET_IN4_ENABLED					(0x1u<<4)
#define	GPIOTE_INTENSET_IN4_SET						(0x1u<<4)
#define	GPIOTE_INTENSET_IN3_DISABLED				(0x0u<<3)
#define	GPIOTE_INTENSET_IN3_ENABLED					(0x1u<<3)
#define	GPIOTE_INTENSET_IN3_SET						(0x1u<<3)
#define	GPIOTE_INTENSET_IN2_DISABLED				(0x0u<<2)
#define	GPIOTE_INTENSET_IN2_ENABLED					(0x1u<<2)
#define	GPIOTE_INTENSET_IN2_SET						(0x1u<<2)
#define	GPIOTE_INTENSET_IN1_DISABLED				(0x0u<<1)
#define	GPIOTE_INTENSET_IN1_ENABLED					(0x1u<<1)
#define	GPIOTE_INTENSET_IN1_SET						(0x1u<<1)
#define	GPIOTE_INTENSET_IN0_DISABLED				(0x0u<<0)
#define	GPIOTE_INTENSET_IN0_ENABLED					(0x1u<<0)
#define	GPIOTE_INTENSET_IN0_SET						(0x1u<<0)

// INTENCLR Configuration

#define	GPIOTE_INTENCLR_PORT						(0x1u<<31)
#define	GPIOTE_INTENCLR_IN7							(0x1u<<7)
#define	GPIOTE_INTENCLR_IN6							(0x1u<<6)
#define	GPIOTE_INTENCLR_IN5							(0x1u<<5)
#define	GPIOTE_INTENCLR_IN4							(0x1u<<4)
#define	GPIOTE_INTENCLR_IN3							(0x1u<<3)
#define	GPIOTE_INTENCLR_IN2							(0x1u<<2)
#define	GPIOTE_INTENCLR_IN1							(0x1u<<1)
#define	GPIOTE_INTENCLR_IN0							(0x1u<<0)
#define	GPIOTE_INTENCLR_PORT_DISABLED				(0x0u<<31)
#define	GPIOTE_INTENCLR_PORT_ENABLED				(0x1u<<31)
#define	GPIOTE_INTENCLR_PORT_CLEAR					(0x1u<<31)
#define	GPIOTE_INTENCLR_IN7_DISABLED				(0x0u<<7)
#define	GPIOTE_INTENCLR_IN7_ENABLED					(0x1u<<7)
#define	GPIOTE_INTENCLR_IN7_CLEAR					(0x1u<<7)
#define	GPIOTE_INTENCLR_IN6_DISABLED				(0x0u<<6)
#define	GPIOTE_INTENCLR_IN6_ENABLED					(0x1u<<6)
#define	GPIOTE_INTENCLR_IN6_CLEAR					(0x1u<<6)
#define	GPIOTE_INTENCLR_IN5_DISABLED				(0x0u<<5)
#define	GPIOTE_INTENCLR_IN5_ENABLED					(0x1u<<5)
#define	GPIOTE_INTENCLR_IN5_CLEAR					(0x1u<<5)
#define	GPIOTE_INTENCLR_IN4_DISABLED				(0x0u<<4)
#define	GPIOTE_INTENCLR_IN4_ENABLED					(0x1u<<4)
#define	GPIOTE_INTENCLR_IN4_CLEAR					(0x1u<<4)
#define	GPIOTE_INTENCLR_IN3_DISABLED				(0x0u<<3)
#define	GPIOTE_INTENCLR_IN3_ENABLED					(0x1u<<3)
#define	GPIOTE_INTENCLR_IN3_CLEAR					(0x1u<<3)
#define	GPIOTE_INTENCLR_IN2_DISABLED				(0x0u<<2)
#define	GPIOTE_INTENCLR_IN2_ENABLED					(0x1u<<2)
#define	GPIOTE_INTENCLR_IN2_CLEAR					(0x1u<<2)
#define	GPIOTE_INTENCLR_IN1_DISABLED				(0x0u<<1)
#define	GPIOTE_INTENCLR_IN1_ENABLED					(0x1u<<1)
#define	GPIOTE_INTENCLR_IN1_CLEAR					(0x1u<<1)
#define	GPIOTE_INTENCLR_IN0_DISABLED				(0x0u<<0)
#define	GPIOTE_INTENCLR_IN0_ENABLED					(0x1u<<0)
#define	GPIOTE_INTENCLR_IN0_CLEAR					(0x1u<<0)

// LATENCY Configuration

#define	GPIOTE_LATENCY_LATENCY						(0x1u<<0)
#define	GPIOTE_LATENCY_LATENCY_LOWPOWER				(0x0u<<0)
#define	GPIOTE_LATENCY_LATENCY_LOWLATENCY			(0x1u<<0)

// CONFIG Configuration

#define	GPIOTE_CONFIG_OUTINIT						(0x1u<<20)
#define	GPIOTE_CONFIG_POLARITY						(0x3u<<16)
#define	GPIOTE_CONFIG_POLARITY_0					(0x1u<<16)
#define	GPIOTE_CONFIG_PORT							(0x1u<<13)
#define	GPIOTE_CONFIG_PSEL							(0x1Fu<<8)
#define	GPIOTE_CONFIG_PSEL_0						(0x1u<<8)
#define	GPIOTE_CONFIG_MODE							(0x3u<<0)
#define	GPIOTE_CONFIG_MODE_0						(0x1u<<0)
#define	GPIOTE_CONFIG_OUTINIT_LOW					(0x0u<<20)
#define	GPIOTE_CONFIG_OUTINIT_HIGH					(0x1u<<20)
#define	GPIOTE_CONFIG_POLARITY_NONE					(0x0u<<16)
#define	GPIOTE_CONFIG_POLARITY_LOTOHI				(0x1u<<16)
#define	GPIOTE_CONFIG_POLARITY_HITOLO				(0x2u<<16)
#define	GPIOTE_CONFIG_POLARITY_TOGGLE				(0x3u<<16)
#define	GPIOTE_CONFIG_MODE_DISABLED					(0x0u<<0)
#define	GPIOTE_CONFIG_MODE_EVENT					(0x1u<<0)
#define	GPIOTE_CONFIG_MODE_TASK						(0x3u<<0)
