/*
; RP2350_bootram.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_bootram equates.
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

// BOOTRAM address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[512];
	volatile	uint32_t	WRITE_ONCE0;
	volatile	uint32_t	WRITE_ONCE1;
	volatile	uint32_t	BOOTLOCK_STAT;
	volatile	uint32_t	BOOTLOCK0;
	volatile	uint32_t	BOOTLOCK1;
	volatile	uint32_t	BOOTLOCK2;
	volatile	uint32_t	BOOTLOCK3;
	volatile	uint32_t	BOOTLOCK4;
	volatile	uint32_t	BOOTLOCK5;
	volatile	uint32_t	BOOTLOCK6;
	volatile	uint32_t	BOOTLOCK7;
} BOOTRAM_TypeDef;

#ifdef __cplusplus
#define	BOOTRAM_NS	reinterpret_cast<BOOTRAM_TypeDef *>(0x400E0000u)
#define	BOOTRAM_S	reinterpret_cast<BOOTRAM_TypeDef *>(0x400E0000u)
#else
#define	BOOTRAM_NS	((BOOTRAM_TypeDef *)0x400E0000u)
#define	BOOTRAM_S	((BOOTRAM_TypeDef *)0x400E0000u)
#endif

// WRITE_ONCE0 Configuration

#define	BOOTRAM_WRITE_ONCE0_WRITE_ONCE0			(0xFFFFFFFFu<<0)
#define	BOOTRAM_WRITE_ONCE0_WRITE_ONCE0_0		(0x1u<<0)

// WRITE_ONCE1 Configuration

#define	BOOTRAM_WRITE_ONCE1_WRITE_ONCE1			(0xFFFFFFFFu<<0)
#define	BOOTRAM_WRITE_ONCE1_WRITE_ONCE1_0		(0x1u<<0)

// BOOTLOCK_STAT Configuration

#define	BOOTRAM_BOOTLOCK_STAT_BOOTLOCK_STAT		(0xFFu<<0)
#define	BOOTRAM_BOOTLOCK_STAT_BOOTLOCK_STAT_0	(0x1u<<0)

// BOOTLOCK0 Configuration

#define	BOOTRAM_BOOTLOCK0_BOOTLOCK0				(0xFFFFFFFFu<<0)
#define	BOOTRAM_BOOTLOCK0_BOOTLOCK0_0			(0x1u<<0)

// BOOTLOCK1 Configuration

#define	BOOTRAM_BOOTLOCK1_BOOTLOCK1				(0xFFFFFFFFu<<0)
#define	BOOTRAM_BOOTLOCK1_BOOTLOCK1_0			(0x1u<<0)

// BOOTLOCK2 Configuration

#define	BOOTRAM_BOOTLOCK2_BOOTLOCK2				(0xFFFFFFFFu<<0)
#define	BOOTRAM_BOOTLOCK2_BOOTLOCK2_0			(0x1u<<0)

// BOOTLOCK3 Configuration

#define	BOOTRAM_BOOTLOCK3_BOOTLOCK3				(0xFFFFFFFFu<<0)
#define	BOOTRAM_BOOTLOCK3_BOOTLOCK3_0			(0x1u<<0)

// BOOTLOCK4 Configuration

#define	BOOTRAM_BOOTLOCK4_BOOTLOCK4				(0xFFFFFFFFu<<0)
#define	BOOTRAM_BOOTLOCK4_BOOTLOCK4_0			(0x1u<<0)

// BOOTLOCK5 Configuration

#define	BOOTRAM_BOOTLOCK5_BOOTLOCK5				(0xFFFFFFFFu<<0)
#define	BOOTRAM_BOOTLOCK5_BOOTLOCK5_0			(0x1u<<0)

// BOOTLOCK6 Configuration

#define	BOOTRAM_BOOTLOCK6_BOOTLOCK6				(0xFFFFFFFFu<<0)
#define	BOOTRAM_BOOTLOCK6_BOOTLOCK6_0			(0x1u<<0)

// BOOTLOCK7 Configuration

#define	BOOTRAM_BOOTLOCK7_BOOTLOCK7				(0xFFFFFFFFu<<0)
#define	BOOTRAM_BOOTLOCK7_BOOTLOCK7_0			(0x1u<<0)
