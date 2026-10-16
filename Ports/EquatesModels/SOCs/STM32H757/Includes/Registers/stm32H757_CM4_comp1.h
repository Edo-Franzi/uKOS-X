/*
; stm32H757_CM4_comp1.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H757_CM4_comp1 equates.
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

// COMP1 address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	SR;
	volatile	uint32_t	ICFR;
	volatile	uint32_t	OR;
	volatile	uint32_t	CFGR1;
	volatile	uint32_t	CFGR2;
} COMP1_TypeDef;

#if (defined(__cplusplus))
#define	COMP1	reinterpret_cast<COMP1_TypeDef *>(0x58003800u)

#else
#define	COMP1	((COMP1_TypeDef *)0x58003800u)
#endif

// SR Configuration

#define	COMP1_SR_C2IF			(0x1u<<17)
#define	COMP1_SR_C1IF			(0x1u<<16)
#define	COMP1_SR_C2VAL			(0x1u<<1)
#define	COMP1_SR_C1VAL			(0x1u<<0)

// ICFR Configuration

#define	COMP1_ICFR_CC2IF		(0x1u<<17)
#define	COMP1_ICFR_CC1IF		(0x1u<<16)

// OR Configuration

#define	COMP1_OR_OR				(0x1FFFFFu<<11)
#define	COMP1_OR_OR_0			(0x1u<<11)
#define	COMP1_OR_AFOP			(0x7FFu<<0)
#define	COMP1_OR_AFOP_0			(0x1u<<0)

// CFGR1 Configuration

#define	COMP1_CFGR1_LOCK		(0x1u<<31)
#define	COMP1_CFGR1_BLANKING	(0xFu<<24)
#define	COMP1_CFGR1_BLANKING_0	(0x1u<<24)
#define	COMP1_CFGR1_INPSEL		(0x1u<<20)
#define	COMP1_CFGR1_INMSEL		(0x7u<<16)
#define	COMP1_CFGR1_INMSEL_0	(0x1u<<16)
#define	COMP1_CFGR1_PWRMODE		(0x3u<<12)
#define	COMP1_CFGR1_PWRMODE_0	(0x1u<<12)
#define	COMP1_CFGR1_HYST		(0x3u<<8)
#define	COMP1_CFGR1_HYST_0		(0x1u<<8)
#define	COMP1_CFGR1_ITEN		(0x1u<<6)
#define	COMP1_CFGR1_POLARITY	(0x1u<<3)
#define	COMP1_CFGR1_SCALEN		(0x1u<<2)
#define	COMP1_CFGR1_BRGEN		(0x1u<<1)
#define	COMP1_CFGR1_EN			(0x1u<<0)

// CFGR2 Configuration

#define	COMP1_CFGR2_LOCK		(0x1u<<31)
#define	COMP1_CFGR2_BLANKING	(0xFu<<24)
#define	COMP1_CFGR2_BLANKING_0	(0x1u<<24)
#define	COMP1_CFGR2_INPSEL		(0x1u<<20)
#define	COMP1_CFGR2_INMSEL		(0x7u<<16)
#define	COMP1_CFGR2_INMSEL_0	(0x1u<<16)
#define	COMP1_CFGR2_PWRMODE		(0x3u<<12)
#define	COMP1_CFGR2_PWRMODE_0	(0x1u<<12)
#define	COMP1_CFGR2_HYST		(0x3u<<8)
#define	COMP1_CFGR2_HYST_0		(0x1u<<8)
#define	COMP1_CFGR2_ITEN		(0x1u<<6)
#define	COMP1_CFGR2_WINMODE		(0x1u<<4)
#define	COMP1_CFGR2_POLARITY	(0x1u<<3)
#define	COMP1_CFGR2_SCALEN		(0x1u<<2)
#define	COMP1_CFGR2_BRGEN		(0x1u<<1)
#define	COMP1_CFGR2_EN			(0x1u<<0)
