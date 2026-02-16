/*
; RP2350_watchdog.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_watchdog equates.
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

// WATCHDOG address definitions
// ----------------------------

typedef struct {
	volatile	uint32_t	CTRL;
	volatile	uint32_t	LOAD;
	volatile	uint32_t	REASON;
	volatile	uint32_t	SCRATCH0;
	volatile	uint32_t	SCRATCH1;
	volatile	uint32_t	SCRATCH2;
	volatile	uint32_t	SCRATCH3;
	volatile	uint32_t	SCRATCH4;
	volatile	uint32_t	SCRATCH5;
	volatile	uint32_t	SCRATCH6;
	volatile	uint32_t	SCRATCH7;
} WATCHDOG_TypeDef;

#ifdef __cplusplus
#define	WATCHDOG_NS	reinterpret_cast<WATCHDOG_TypeDef *>(0x400D8000u)
#define	WATCHDOG_S	reinterpret_cast<WATCHDOG_TypeDef *>(0x400D8000u)
#else
#define	WATCHDOG_NS	((WATCHDOG_TypeDef *)0x400D8000u)
#define	WATCHDOG_S	((WATCHDOG_TypeDef *)0x400D8000u)
#endif

// CTRL Configuration

#define	WATCHDOG_CTRL_TIME				(0xFFFFFFu<<0)
#define	WATCHDOG_CTRL_TIME_0			(0x1u<<0)
#define	WATCHDOG_CTRL_PAUSE_JTAG		(0x1u<<24)
#define	WATCHDOG_CTRL_PAUSE_DBG0		(0x1u<<25)
#define	WATCHDOG_CTRL_PAUSE_DBG1		(0x1u<<26)
#define	WATCHDOG_CTRL_ENABLE			(0x1u<<30)
#define	WATCHDOG_CTRL_TRIGGER			(0x1u<<31)

// LOAD Configuration

#define	WATCHDOG_LOAD_LOAD				(0xFFFFFFu<<0)
#define	WATCHDOG_LOAD_LOAD_0			(0x1u<<0)

// REASON Configuration

#define	WATCHDOG_REASON_TIMER			(0x1u<<0)
#define	WATCHDOG_REASON_FORCE			(0x1u<<1)

// SCRATCH0 Configuration

#define	WATCHDOG_SCRATCH0_SCRATCH0		(0xFFFFFFFFu<<0)
#define	WATCHDOG_SCRATCH0_SCRATCH0_0	(0x1u<<0)

// SCRATCH1 Configuration

#define	WATCHDOG_SCRATCH1_SCRATCH1		(0xFFFFFFFFu<<0)
#define	WATCHDOG_SCRATCH1_SCRATCH1_0	(0x1u<<0)

// SCRATCH2 Configuration

#define	WATCHDOG_SCRATCH2_SCRATCH2		(0xFFFFFFFFu<<0)
#define	WATCHDOG_SCRATCH2_SCRATCH2_0	(0x1u<<0)

// SCRATCH3 Configuration

#define	WATCHDOG_SCRATCH3_SCRATCH3		(0xFFFFFFFFu<<0)
#define	WATCHDOG_SCRATCH3_SCRATCH3_0	(0x1u<<0)

// SCRATCH4 Configuration

#define	WATCHDOG_SCRATCH4_SCRATCH4		(0xFFFFFFFFu<<0)
#define	WATCHDOG_SCRATCH4_SCRATCH4_0	(0x1u<<0)

// SCRATCH5 Configuration

#define	WATCHDOG_SCRATCH5_SCRATCH5		(0xFFFFFFFFu<<0)
#define	WATCHDOG_SCRATCH5_SCRATCH5_0	(0x1u<<0)

// SCRATCH6 Configuration

#define	WATCHDOG_SCRATCH6_SCRATCH6		(0xFFFFFFFFu<<0)
#define	WATCHDOG_SCRATCH6_SCRATCH6_0	(0x1u<<0)

// SCRATCH7 Configuration

#define	WATCHDOG_SCRATCH7_SCRATCH7		(0xFFFFFFFFu<<0)
#define	WATCHDOG_SCRATCH7_SCRATCH7_0	(0x1u<<0)
