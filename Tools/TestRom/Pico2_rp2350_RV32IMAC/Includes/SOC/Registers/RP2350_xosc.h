/*
; RP2350_xosc.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_xosc equates.
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

// XOSC address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CTRL;
	volatile	uint32_t	STATUS;
	volatile	uint32_t	DORMANT;
	volatile	uint32_t	STARTUP;
	volatile	uint32_t	COUNT;
} XOSC_TypeDef;

#ifdef __cplusplus
#define	XOSC_NS	reinterpret_cast<XOSC_TypeDef *>(0x40048000u)
#define	XOSC_S	reinterpret_cast<XOSC_TypeDef *>(0x40048000u)
#else
#define	XOSC_NS	((XOSC_TypeDef *)0x40048000u)
#define	XOSC_S	((XOSC_TypeDef *)0x40048000u)
#endif

// CTRL Configuration

#define	XOSC_CTRL_FREQ_RANGE				(0xFFFu<<0)
#define	XOSC_CTRL_FREQ_RANGE_0				(0x1u<<0)
#define	XOSC_CTRL_ENABLE					(0xFFFu<<12)
#define	XOSC_CTRL_ENABLE_0					(0x1u<<12)
#define	XOSC_CTRL_FREQ_RANGE_1_15MHZ		(0xAA0u<<0)
#define	XOSC_CTRL_FREQ_RANGE_10_30MHZ		(0xAA1u<<0)
#define	XOSC_CTRL_FREQ_RANGE_25_60MHZ		(0xAA2u<<0)
#define	XOSC_CTRL_FREQ_RANGE_40_100MHZ		(0xAA3u<<0)
#define	XOSC_CTRL_ENABLE_DISABLE			(0xD1Eu<<12)
#define	XOSC_CTRL_ENABLE_ENABLE				(0xFABu<<12)

// STATUS Configuration

#define	XOSC_STATUS_FREQ_RANGE				(0x3u<<0)
#define	XOSC_STATUS_FREQ_RANGE_0			(0x1u<<0)
#define	XOSC_STATUS_ENABLED					(0x1u<<12)
#define	XOSC_STATUS_BADWRITE				(0x1u<<24)
#define	XOSC_STATUS_STABLE					(0x1u<<31)
#define	XOSC_STATUS_FREQ_RANGE_1_15MHZ		(0x0u<<0)
#define	XOSC_STATUS_FREQ_RANGE_10_30MHZ		(0x1u<<0)
#define	XOSC_STATUS_FREQ_RANGE_25_60MHZ		(0x2u<<0)
#define	XOSC_STATUS_FREQ_RANGE_40_100MHZ	(0x3u<<0)

// DORMANT Configuration

#define	XOSC_DORMANT_DORMANT				(0xFFFFFFFFu<<0)
#define	XOSC_DORMANT_DORMANT_0				(0x1u<<0)
#define	XOSC_DORMANT_DORMANT_DORMANT		(0x636F6D61u<<0)
#define	XOSC_DORMANT_DORMANT_WAKE			(0x77616B65u<<0)

// STARTUP Configuration

#define	XOSC_STARTUP_DELAY					(0x3FFFu<<0)
#define	XOSC_STARTUP_DELAY_0				(0x1u<<0)
#define	XOSC_STARTUP_X4						(0x1u<<20)

// COUNT Configuration

#define	XOSC_COUNT_COUNT					(0xFFFFu<<0)
#define	XOSC_COUNT_COUNT_0					(0x1u<<0)
