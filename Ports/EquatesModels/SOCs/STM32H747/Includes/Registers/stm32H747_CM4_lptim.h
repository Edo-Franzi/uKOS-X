/*
; stm32H747_CM4_lptim.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM4_lptim equates.
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

// LPTIM address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	IER;
	volatile	uint32_t	CFGR;
	volatile	uint32_t	CR;
	volatile	uint32_t	CMP;
	volatile	uint32_t	ARR;
	volatile	uint32_t	CNT;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	CFGR2;
} LPTIM_TypeDef;

#if (defined(__cplusplus))
#define	LPTIM1	reinterpret_cast<LPTIM_TypeDef *>(0x40002400u)
#define	LPTIM2	reinterpret_cast<LPTIM_TypeDef *>(0x58002400u)
#define	LPTIM3	reinterpret_cast<LPTIM_TypeDef *>(0x58002800u)
#define	LPTIM4	reinterpret_cast<LPTIM_TypeDef *>(0x58002C00u)
#define	LPTIM5	reinterpret_cast<LPTIM_TypeDef *>(0x58003000u)

#else
#define	LPTIM1	((LPTIM_TypeDef *)0x40002400u)
#define	LPTIM2	((LPTIM_TypeDef *)0x58002400u)
#define	LPTIM3	((LPTIM_TypeDef *)0x58002800u)
#define	LPTIM4	((LPTIM_TypeDef *)0x58002C00u)
#define	LPTIM5	((LPTIM_TypeDef *)0x58003000u)
#endif

// ISR Configuration

#define	LPTIM_ISR_CMPM			(0x1u<<0)
#define	LPTIM_ISR_ARRM			(0x1u<<1)
#define	LPTIM_ISR_EXTTRIG		(0x1u<<2)
#define	LPTIM_ISR_CMPOK			(0x1u<<3)
#define	LPTIM_ISR_ARROK			(0x1u<<4)
#define	LPTIM_ISR_UP			(0x1u<<5)
#define	LPTIM_ISR_DOWN			(0x1u<<6)

// ICR Configuration

#define	LPTIM_ICR_CMPMCF		(0x1u<<0)
#define	LPTIM_ICR_ARRMCF		(0x1u<<1)
#define	LPTIM_ICR_EXTTRIGCF		(0x1u<<2)
#define	LPTIM_ICR_CMPOKCF		(0x1u<<3)
#define	LPTIM_ICR_ARROKCF		(0x1u<<4)
#define	LPTIM_ICR_UPCF			(0x1u<<5)
#define	LPTIM_ICR_DOWNCF		(0x1u<<6)

// IER Configuration

#define	LPTIM_IER_CMPMIE		(0x1u<<0)
#define	LPTIM_IER_ARRMIE		(0x1u<<1)
#define	LPTIM_IER_EXTTRIGIE		(0x1u<<2)
#define	LPTIM_IER_CMPOKIE		(0x1u<<3)
#define	LPTIM_IER_ARROKIE		(0x1u<<4)
#define	LPTIM_IER_UPIE			(0x1u<<5)
#define	LPTIM_IER_DOWNIE		(0x1u<<6)

// CFGR Configuration

#define	LPTIM_CFGR_CKSEL		(0x1u<<0)
#define	LPTIM_CFGR_CKPOL		(0x3u<<1)
#define	LPTIM_CFGR_CKPOL_0		(0x1u<<1)
#define	LPTIM_CFGR_CKFLT		(0x3u<<3)
#define	LPTIM_CFGR_CKFLT_0		(0x1u<<3)
#define	LPTIM_CFGR_TRGFLT		(0x3u<<6)
#define	LPTIM_CFGR_TRGFLT_0		(0x1u<<6)
#define	LPTIM_CFGR_PRESC		(0x7u<<9)
#define	LPTIM_CFGR_PRESC_0		(0x1u<<9)
#define	LPTIM_CFGR_TRIGSEL		(0x7u<<13)
#define	LPTIM_CFGR_TRIGSEL_0	(0x1u<<13)
#define	LPTIM_CFGR_TRIGEN		(0x3u<<17)
#define	LPTIM_CFGR_TRIGEN_0		(0x1u<<17)
#define	LPTIM_CFGR_TIMOUT		(0x1u<<19)
#define	LPTIM_CFGR_WAVE			(0x1u<<20)
#define	LPTIM_CFGR_WAVPOL		(0x1u<<21)
#define	LPTIM_CFGR_PRELOAD		(0x1u<<22)
#define	LPTIM_CFGR_COUNTMODE	(0x1u<<23)
#define	LPTIM_CFGR_ENC			(0x1u<<24)

// CR Configuration

#define	LPTIM_CR_RSTARE			(0x1u<<4)
#define	LPTIM_CR_COUNTRST		(0x1u<<3)
#define	LPTIM_CR_CNTSTRT		(0x1u<<2)
#define	LPTIM_CR_SNGSTRT		(0x1u<<1)
#define	LPTIM_CR_ENABLE			(0x1u<<0)

// CMP Configuration

#define	LPTIM_CMP_CMP			(0xFFFFu<<0)
#define	LPTIM_CMP_CMP_0			(0x1u<<0)

// ARR Configuration

#define	LPTIM_ARR_ARR			(0xFFFFu<<0)
#define	LPTIM_ARR_ARR_0			(0x1u<<0)

// CNT Configuration

#define	LPTIM_CNT_CNT			(0xFFFFu<<0)
#define	LPTIM_CNT_CNT_0			(0x1u<<0)

// CFGR2 Configuration

#define	LPTIM_CFGR2_IN2SEL		(0x3u<<4)
#define	LPTIM_CFGR2_IN2SEL_0	(0x1u<<4)
#define	LPTIM_CFGR2_IN1SEL		(0x3u<<0)
#define	LPTIM_CFGR2_IN1SEL_0	(0x1u<<0)
