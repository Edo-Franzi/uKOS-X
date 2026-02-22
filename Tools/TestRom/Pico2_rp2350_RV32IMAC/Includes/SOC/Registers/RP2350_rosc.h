/*
; RP2350_rosc.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_rosc equates.
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

// ROSC address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CTRL;
	volatile	uint32_t	FREQA;
	volatile	uint32_t	FREQB;
	volatile	uint32_t	RANDOM;
	volatile	uint32_t	DORMANT;
	volatile	uint32_t	DIV;
	volatile	uint32_t	PHASE;
	volatile	uint32_t	STATUS;
	volatile	uint32_t	RANDOMBIT;
	volatile	uint32_t	COUNT;
} ROSC_TypeDef;

#ifdef __cplusplus
#define	ROSC_NS	reinterpret_cast<ROSC_TypeDef *>(0x400E8000u)
#define	ROSC_S	reinterpret_cast<ROSC_TypeDef *>(0x400E8000u)
#else
#define	ROSC_NS	((ROSC_TypeDef *)0x400E8000u)
#define	ROSC_S	((ROSC_TypeDef *)0x400E8000u)
#endif

// CTRL Configuration

#define	ROSC_CTRL_FREQ_RANGE			(0xFFFu<<0)
#define	ROSC_CTRL_FREQ_RANGE_0			(0x1u<<0)
#define	ROSC_CTRL_ENABLE				(0xFFFu<<12)
#define	ROSC_CTRL_ENABLE_0				(0x1u<<12)
#define	ROSC_CTRL_FREQ_RANGE_LOW		(0xFA4u<<0)
#define	ROSC_CTRL_FREQ_RANGE_MEDIUM		(0xFA5u<<0)
#define	ROSC_CTRL_FREQ_RANGE_HIGH		(0xFA7u<<0)
#define	ROSC_CTRL_FREQ_RANGE_TOOHIGH	(0xFA6u<<0)
#define	ROSC_CTRL_ENABLE_DISABLE		(0xD1Eu<<12)
#define	ROSC_CTRL_ENABLE_ENABLE			(0xFABu<<12)

// FREQA Configuration

#define	ROSC_FREQA_DS0					(0x7u<<0)
#define	ROSC_FREQA_DS0_0				(0x1u<<0)
#define	ROSC_FREQA_DS0_RANDOM			(0x1u<<3)
#define	ROSC_FREQA_DS1					(0x7u<<4)
#define	ROSC_FREQA_DS1_0				(0x1u<<4)
#define	ROSC_FREQA_DS1_RANDOM			(0x1u<<7)
#define	ROSC_FREQA_DS2					(0x7u<<8)
#define	ROSC_FREQA_DS2_0				(0x1u<<8)
#define	ROSC_FREQA_DS3					(0x7u<<12)
#define	ROSC_FREQA_DS3_0				(0x1u<<12)
#define	ROSC_FREQA_PASSWD				(0xFFFFu<<16)
#define	ROSC_FREQA_PASSWD_0				(0x1u<<16)
#define	ROSC_FREQA_PASSWD_PASS			(0x9696u<<16)

// FREQB Configuration

#define	ROSC_FREQB_DS4					(0x7u<<0)
#define	ROSC_FREQB_DS4_0				(0x1u<<0)
#define	ROSC_FREQB_DS5					(0x7u<<4)
#define	ROSC_FREQB_DS5_0				(0x1u<<4)
#define	ROSC_FREQB_DS6					(0x7u<<8)
#define	ROSC_FREQB_DS6_0				(0x1u<<8)
#define	ROSC_FREQB_DS7					(0x7u<<12)
#define	ROSC_FREQB_DS7_0				(0x1u<<12)
#define	ROSC_FREQB_PASSWD				(0xFFFFu<<16)
#define	ROSC_FREQB_PASSWD_0				(0x1u<<16)
#define	ROSC_FREQB_PASSWD_PASS			(0x9696u<<16)

// RANDOM Configuration

#define	ROSC_RANDOM_SEED				(0xFFFFFFFFu<<0)
#define	ROSC_RANDOM_SEED_0				(0x1u<<0)

// DORMANT Configuration

#define	ROSC_DORMANT_DORMANT			(0xFFFFFFFFu<<0)
#define	ROSC_DORMANT_DORMANT_0			(0x1u<<0)
#define	ROSC_DORMANT_DORMANT_DORMANT	(0x636F6D61u<<0)
#define	ROSC_DORMANT_DORMANT_WAKE		(0x77616B65u<<0)

// DIV Configuration

#define	ROSC_DIV_DIV					(0xFFFFu<<0)
#define	ROSC_DIV_DIV_0					(0x1u<<0)
#define	ROSC_DIV_DIV_PASS				(0xAA00u<<0)

// PHASE Configuration

#define	ROSC_PHASE_SHIFT				(0x3u<<0)
#define	ROSC_PHASE_SHIFT_0				(0x1u<<0)
#define	ROSC_PHASE_FLIP					(0x1u<<2)
#define	ROSC_PHASE_ENABLE				(0x1u<<3)
#define	ROSC_PHASE_PASSWD				(0xFFu<<4)
#define	ROSC_PHASE_PASSWD_0				(0x1u<<4)

// STATUS Configuration

#define	ROSC_STATUS_ENABLED				(0x1u<<12)
#define	ROSC_STATUS_DIV_RUNNING			(0x1u<<16)
#define	ROSC_STATUS_BADWRITE			(0x1u<<24)
#define	ROSC_STATUS_STABLE				(0x1u<<31)

// RANDOMBIT Configuration

#define	ROSC_RANDOMBIT_RANDOMBIT		(0x1u<<0)

// COUNT Configuration

#define	ROSC_COUNT_COUNT				(0xFFFFu<<0)
#define	ROSC_COUNT_COUNT_0				(0x1u<<0)
