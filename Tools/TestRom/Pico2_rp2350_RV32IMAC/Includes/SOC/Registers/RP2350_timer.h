/*
; RP2350_timer.
; =============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_timer equates.
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

// TIMER address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	TIMEHW;
	volatile	uint32_t	TIMELW;
	volatile	uint32_t	TIMEHR;
	volatile	uint32_t	TIMELR;
	volatile	uint32_t	ALARM0;
	volatile	uint32_t	ALARM1;
	volatile	uint32_t	ALARM2;
	volatile	uint32_t	ALARM3;
	volatile	uint32_t	ARMED;
	volatile	uint32_t	TIMERAWH;
	volatile	uint32_t	TIMERAWL;
	volatile	uint32_t	DBGPAUSE;
	volatile	uint32_t	PAUSE;
	volatile	uint32_t	LOCKED;
	volatile	uint32_t	SOURCE;
	volatile	uint32_t	INTR;
	volatile	uint32_t	INTE;
	volatile	uint32_t	INTF;
	volatile	uint32_t	INTS;
} TIMER_TypeDef;

#ifdef __cplusplus
#define	TIMER0_NS	reinterpret_cast<TIMER_TypeDef *>(0x400B0000u)
#define	TIMER0_S	reinterpret_cast<TIMER_TypeDef *>(0x400B0000u)
#define	TIMER1_NS	reinterpret_cast<TIMER_TypeDef *>(0x400B8000u)
#define	TIMER1_S	reinterpret_cast<TIMER_TypeDef *>(0x400B8000u)
#else
#define	TIMER0_NS	((TIMER_TypeDef *)0x400B0000u)
#define	TIMER0_S	((TIMER_TypeDef *)0x400B0000u)
#define	TIMER1_NS	((TIMER_TypeDef *)0x400B8000u)
#define	TIMER1_S	((TIMER_TypeDef *)0x400B8000u)
#endif

// TIMEHW Configuration

#define	TIMER_TIMEHW_TIMEHW				(0xFFFFFFFFu<<0)
#define	TIMER_TIMEHW_TIMEHW_0			(0x1u<<0)

// TIMELW Configuration

#define	TIMER_TIMELW_TIMELW				(0xFFFFFFFFu<<0)
#define	TIMER_TIMELW_TIMELW_0			(0x1u<<0)

// TIMEHR Configuration

#define	TIMER_TIMEHR_TIMEHR				(0xFFFFFFFFu<<0)
#define	TIMER_TIMEHR_TIMEHR_0			(0x1u<<0)

// TIMELR Configuration

#define	TIMER_TIMELR_TIMELR				(0xFFFFFFFFu<<0)
#define	TIMER_TIMELR_TIMELR_0			(0x1u<<0)

// ALARM0 Configuration

#define	TIMER_ALARM0_ALARM0				(0xFFFFFFFFu<<0)
#define	TIMER_ALARM0_ALARM0_0			(0x1u<<0)

// ALARM1 Configuration

#define	TIMER_ALARM1_ALARM1				(0xFFFFFFFFu<<0)
#define	TIMER_ALARM1_ALARM1_0			(0x1u<<0)

// ALARM2 Configuration

#define	TIMER_ALARM2_ALARM2				(0xFFFFFFFFu<<0)
#define	TIMER_ALARM2_ALARM2_0			(0x1u<<0)

// ALARM3 Configuration

#define	TIMER_ALARM3_ALARM3				(0xFFFFFFFFu<<0)
#define	TIMER_ALARM3_ALARM3_0			(0x1u<<0)

// ARMED Configuration

#define	TIMER_ARMED_ARMED				(0xFu<<0)
#define	TIMER_ARMED_ARMED_0				(0x1u<<0)

// TIMERAWH Configuration

#define	TIMER_TIMERAWH_TIMERAWH			(0xFFFFFFFFu<<0)
#define	TIMER_TIMERAWH_TIMERAWH_0		(0x1u<<0)

// TIMERAWL Configuration

#define	TIMER_TIMERAWL_TIMERAWL			(0xFFFFFFFFu<<0)
#define	TIMER_TIMERAWL_TIMERAWL_0		(0x1u<<0)

// DBGPAUSE Configuration

#define	TIMER_DBGPAUSE_DBG0				(0x1u<<1)
#define	TIMER_DBGPAUSE_DBG1				(0x1u<<2)

// PAUSE Configuration

#define	TIMER_PAUSE_PAUSE				(0x1u<<0)

// LOCKED Configuration

#define	TIMER_LOCKED_LOCKED				(0x1u<<0)

// SOURCE Configuration

#define	TIMER_SOURCE_CLK_SYS			(0x1u<<0)
#define	TIMER_SOURCE_CLK_SYS_TICK		(0x0u<<0)
#define	TIMER_SOURCE_CLK_SYS_CLK_SYS	(0x1u<<0)

// INTR Configuration

#define	TIMER_INTR_ALARM_0				(0x1u<<0)
#define	TIMER_INTR_ALARM_1				(0x1u<<1)
#define	TIMER_INTR_ALARM_2				(0x1u<<2)
#define	TIMER_INTR_ALARM_3				(0x1u<<3)

// INTE Configuration

#define	TIMER_INTE_ALARM_0				(0x1u<<0)
#define	TIMER_INTE_ALARM_1				(0x1u<<1)
#define	TIMER_INTE_ALARM_2				(0x1u<<2)
#define	TIMER_INTE_ALARM_3				(0x1u<<3)

// INTF Configuration

#define	TIMER_INTF_ALARM_0				(0x1u<<0)
#define	TIMER_INTF_ALARM_1				(0x1u<<1)
#define	TIMER_INTF_ALARM_2				(0x1u<<2)
#define	TIMER_INTF_ALARM_3				(0x1u<<3)

// INTS Configuration

#define	TIMER_INTS_ALARM_0				(0x1u<<0)
#define	TIMER_INTS_ALARM_1				(0x1u<<1)
#define	TIMER_INTS_ALARM_2				(0x1u<<2)
#define	TIMER_INTS_ALARM_3				(0x1u<<3)
