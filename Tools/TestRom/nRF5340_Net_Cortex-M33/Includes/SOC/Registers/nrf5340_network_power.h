/*
; nrf5340_network_power.
; ======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_power equates.
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

// POWER address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[30];
	volatile	uint32_t	TASKS_CONSTLAT;
	volatile	uint32_t	TASKS_LOWPWR;
	volatile	uint32_t	RESERVED1[30];
	volatile	uint32_t	SUBSCRIBE_CONSTLAT;
	volatile	uint32_t	SUBSCRIBE_LOWPWR;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	EVENTS_POFWARN;
	volatile	uint32_t	RESERVED3[2];
	volatile	uint32_t	EVENTS_SLEEPENTER;
	volatile	uint32_t	EVENTS_SLEEPEXIT;
	volatile	uint32_t	RESERVED4[27];
	volatile	uint32_t	PUBLISH_POFWARN;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	PUBLISH_SLEEPENTER;
	volatile	uint32_t	PUBLISH_SLEEPEXIT;
	volatile	uint32_t	RESERVED6[89];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED7[132];
	volatile	uint32_t	GPREGRET[2];
} POWER_TypeDef;

#if (defined(__cplusplus))
#define	POWER_NS	reinterpret_cast<POWER_TypeDef *>(0x41005000u)

#else
#define	POWER_NS	((POWER_TypeDef *)0x41005000u)
#endif

// TASKS_CONSTLAT Configuration

#define	POWER_TASKS_CONSTLAT_TASKS_CONSTLAT						(0x1u<<0)
#define	POWER_TASKS_CONSTLAT_TASKS_CONSTLAT_TRIGGER				(0x1u<<0)

// TASKS_LOWPWR Configuration

#define	POWER_TASKS_LOWPWR_TASKS_LOWPWR							(0x1u<<0)
#define	POWER_TASKS_LOWPWR_TASKS_LOWPWR_TRIGGER					(0x1u<<0)

// SUBSCRIBE_CONSTLAT Configuration

#define	POWER_SUBSCRIBE_CONSTLAT_EN								(0x1u<<31)
#define	POWER_SUBSCRIBE_CONSTLAT_CHIDX							(0xFFu<<0)
#define	POWER_SUBSCRIBE_CONSTLAT_CHIDX_0						(0x1u<<0)
#define	POWER_SUBSCRIBE_CONSTLAT_EN_DISABLED					(0x0u<<31)
#define	POWER_SUBSCRIBE_CONSTLAT_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_LOWPWR Configuration

#define	POWER_SUBSCRIBE_LOWPWR_EN								(0x1u<<31)
#define	POWER_SUBSCRIBE_LOWPWR_CHIDX							(0xFFu<<0)
#define	POWER_SUBSCRIBE_LOWPWR_CHIDX_0							(0x1u<<0)
#define	POWER_SUBSCRIBE_LOWPWR_EN_DISABLED						(0x0u<<31)
#define	POWER_SUBSCRIBE_LOWPWR_EN_ENABLED						(0x1u<<31)

// EVENTS_POFWARN Configuration

#define	POWER_EVENTS_POFWARN_EVENTS_POFWARN						(0x1u<<0)
#define	POWER_EVENTS_POFWARN_EVENTS_POFWARN_NOTGENERATED		(0x0u<<0)
#define	POWER_EVENTS_POFWARN_EVENTS_POFWARN_GENERATED			(0x1u<<0)

// EVENTS_SLEEPENTER Configuration

#define	POWER_EVENTS_SLEEPENTER_EVENTS_SLEEPENTER				(0x1u<<0)
#define	POWER_EVENTS_SLEEPENTER_EVENTS_SLEEPENTER_NOTGENERATED	(0x0u<<0)
#define	POWER_EVENTS_SLEEPENTER_EVENTS_SLEEPENTER_GENERATED		(0x1u<<0)

// EVENTS_SLEEPEXIT Configuration

#define	POWER_EVENTS_SLEEPEXIT_EVENTS_SLEEPEXIT					(0x1u<<0)
#define	POWER_EVENTS_SLEEPEXIT_EVENTS_SLEEPEXIT_NOTGENERATED	(0x0u<<0)
#define	POWER_EVENTS_SLEEPEXIT_EVENTS_SLEEPEXIT_GENERATED		(0x1u<<0)

// PUBLISH_POFWARN Configuration

#define	POWER_PUBLISH_POFWARN_EN								(0x1u<<31)
#define	POWER_PUBLISH_POFWARN_CHIDX								(0xFFu<<0)
#define	POWER_PUBLISH_POFWARN_CHIDX_0							(0x1u<<0)
#define	POWER_PUBLISH_POFWARN_EN_DISABLED						(0x0u<<31)
#define	POWER_PUBLISH_POFWARN_EN_ENABLED						(0x1u<<31)

// PUBLISH_SLEEPENTER Configuration

#define	POWER_PUBLISH_SLEEPENTER_EN								(0x1u<<31)
#define	POWER_PUBLISH_SLEEPENTER_CHIDX							(0xFFu<<0)
#define	POWER_PUBLISH_SLEEPENTER_CHIDX_0						(0x1u<<0)
#define	POWER_PUBLISH_SLEEPENTER_EN_DISABLED					(0x0u<<31)
#define	POWER_PUBLISH_SLEEPENTER_EN_ENABLED						(0x1u<<31)

// PUBLISH_SLEEPEXIT Configuration

#define	POWER_PUBLISH_SLEEPEXIT_EN								(0x1u<<31)
#define	POWER_PUBLISH_SLEEPEXIT_CHIDX							(0xFFu<<0)
#define	POWER_PUBLISH_SLEEPEXIT_CHIDX_0							(0x1u<<0)
#define	POWER_PUBLISH_SLEEPEXIT_EN_DISABLED						(0x0u<<31)
#define	POWER_PUBLISH_SLEEPEXIT_EN_ENABLED						(0x1u<<31)

// INTEN Configuration

#define	POWER_INTEN_SLEEPEXIT									(0x1u<<6)
#define	POWER_INTEN_SLEEPENTER									(0x1u<<5)
#define	POWER_INTEN_POFWARN										(0x1u<<2)
#define	POWER_INTEN_SLEEPEXIT_DISABLED							(0x0u<<6)
#define	POWER_INTEN_SLEEPEXIT_ENABLED							(0x1u<<6)
#define	POWER_INTEN_SLEEPENTER_DISABLED							(0x0u<<5)
#define	POWER_INTEN_SLEEPENTER_ENABLED							(0x1u<<5)
#define	POWER_INTEN_POFWARN_DISABLED							(0x0u<<2)
#define	POWER_INTEN_POFWARN_ENABLED								(0x1u<<2)

// INTENSET Configuration

#define	POWER_INTENSET_SLEEPEXIT								(0x1u<<6)
#define	POWER_INTENSET_SLEEPENTER								(0x1u<<5)
#define	POWER_INTENSET_POFWARN									(0x1u<<2)
#define	POWER_INTENSET_SLEEPEXIT_DISABLED						(0x0u<<6)
#define	POWER_INTENSET_SLEEPEXIT_ENABLED						(0x1u<<6)
#define	POWER_INTENSET_SLEEPEXIT_SET							(0x1u<<6)
#define	POWER_INTENSET_SLEEPENTER_DISABLED						(0x0u<<5)
#define	POWER_INTENSET_SLEEPENTER_ENABLED						(0x1u<<5)
#define	POWER_INTENSET_SLEEPENTER_SET							(0x1u<<5)
#define	POWER_INTENSET_POFWARN_DISABLED							(0x0u<<2)
#define	POWER_INTENSET_POFWARN_ENABLED							(0x1u<<2)
#define	POWER_INTENSET_POFWARN_SET								(0x1u<<2)

// INTENCLR Configuration

#define	POWER_INTENCLR_SLEEPEXIT								(0x1u<<6)
#define	POWER_INTENCLR_SLEEPENTER								(0x1u<<5)
#define	POWER_INTENCLR_POFWARN									(0x1u<<2)
#define	POWER_INTENCLR_SLEEPEXIT_DISABLED						(0x0u<<6)
#define	POWER_INTENCLR_SLEEPEXIT_ENABLED						(0x1u<<6)
#define	POWER_INTENCLR_SLEEPEXIT_CLEAR							(0x1u<<6)
#define	POWER_INTENCLR_SLEEPENTER_DISABLED						(0x0u<<5)
#define	POWER_INTENCLR_SLEEPENTER_ENABLED						(0x1u<<5)
#define	POWER_INTENCLR_SLEEPENTER_CLEAR							(0x1u<<5)
#define	POWER_INTENCLR_POFWARN_DISABLED							(0x0u<<2)
#define	POWER_INTENCLR_POFWARN_ENABLED							(0x1u<<2)
#define	POWER_INTENCLR_POFWARN_CLEAR							(0x1u<<2)

// GPREGRET Configuration

#define	POWER_GPREGRET_GPREGRET									(0xFFu<<0)
#define	POWER_GPREGRET_GPREGRET_0								(0x1u<<0)
