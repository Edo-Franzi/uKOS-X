/*
; stm32U5Gx_lptim1.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_lptim1 equates.
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

// LPTIM1 address definitions
// --------------------------

typedef struct {
		union {
	volatile	uint32_t	ISR_OUTPUT;
	volatile	uint32_t	ISR_INPUT;
		};
		union {
	volatile	uint32_t	ICR_OUTPUT;
	volatile	uint32_t	ICR_INPUT;
		};
		union {
	volatile	uint32_t	DIER_OUTPUT;
	volatile	uint32_t	DIER_INPUT;
		};
	volatile	uint32_t	CFGR;
	volatile	uint32_t	CR;
	volatile	uint32_t	CCR1;
	volatile	uint32_t	ARR;
	volatile	uint32_t	CNT;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	CFGR2;
	volatile	uint32_t	RCR;
	volatile	uint32_t	CCMR1;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	CCR2;
} LPTIM1_TypeDef;

#if (defined(__cplusplus))
#define	LPTIM1_NS	reinterpret_cast<LPTIM1_TypeDef *>(0x46004400u)
#define	LPTIM1_S	reinterpret_cast<LPTIM1_TypeDef *>(0x56004400u)

#else
#define	LPTIM1_NS	((LPTIM1_TypeDef *)0x46004400u)
#define	LPTIM1_S	((LPTIM1_TypeDef *)0x56004400u)
#endif

// ISR_OUTPUT Configuration

#define	LPTIM1_ISR_OUTPUT_CC1IF			(0x1u<<0)
#define	LPTIM1_ISR_OUTPUT_ARRM			(0x1u<<1)
#define	LPTIM1_ISR_OUTPUT_EXTTRIG		(0x1u<<2)
#define	LPTIM1_ISR_OUTPUT_CMP1OK		(0x1u<<3)
#define	LPTIM1_ISR_OUTPUT_ARROK			(0x1u<<4)
#define	LPTIM1_ISR_OUTPUT_UP			(0x1u<<5)
#define	LPTIM1_ISR_OUTPUT_DOWN			(0x1u<<6)
#define	LPTIM1_ISR_OUTPUT_UE			(0x1u<<7)
#define	LPTIM1_ISR_OUTPUT_REPOK			(0x1u<<8)
#define	LPTIM1_ISR_OUTPUT_CC2IF			(0x1u<<9)
#define	LPTIM1_ISR_OUTPUT_CMP2OK		(0x1u<<19)
#define	LPTIM1_ISR_OUTPUT_DIEROK		(0x1u<<24)

// ISR_INPUT Configuration

#define	LPTIM1_ISR_INPUT_CC1IF			(0x1u<<0)
#define	LPTIM1_ISR_INPUT_ARRM			(0x1u<<1)
#define	LPTIM1_ISR_INPUT_EXTTRIG		(0x1u<<2)
#define	LPTIM1_ISR_INPUT_ARROK			(0x1u<<4)
#define	LPTIM1_ISR_INPUT_UP				(0x1u<<5)
#define	LPTIM1_ISR_INPUT_DOWN			(0x1u<<6)
#define	LPTIM1_ISR_INPUT_UE				(0x1u<<7)
#define	LPTIM1_ISR_INPUT_REPOK			(0x1u<<8)
#define	LPTIM1_ISR_INPUT_CC2IF			(0x1u<<9)
#define	LPTIM1_ISR_INPUT_CC1OF			(0x1u<<12)
#define	LPTIM1_ISR_INPUT_CC2OF			(0x1u<<13)
#define	LPTIM1_ISR_INPUT_DIEROK			(0x1u<<24)

// ICR_OUTPUT Configuration

#define	LPTIM1_ICR_OUTPUT_CC1IF			(0x1u<<0)
#define	LPTIM1_ICR_OUTPUT_ARRMCF		(0x1u<<1)
#define	LPTIM1_ICR_OUTPUT_EXTTRIGCF		(0x1u<<2)
#define	LPTIM1_ICR_OUTPUT_CMP1OKCF		(0x1u<<3)
#define	LPTIM1_ICR_OUTPUT_ARROKCF		(0x1u<<4)
#define	LPTIM1_ICR_OUTPUT_UPCF			(0x1u<<5)
#define	LPTIM1_ICR_OUTPUT_DOWNCF		(0x1u<<6)
#define	LPTIM1_ICR_OUTPUT_UECF			(0x1u<<7)
#define	LPTIM1_ICR_OUTPUT_REPOKCF		(0x1u<<8)
#define	LPTIM1_ICR_OUTPUT_CC2CF			(0x1u<<9)
#define	LPTIM1_ICR_OUTPUT_CMP2OKCF		(0x1u<<19)
#define	LPTIM1_ICR_OUTPUT_DIEROKCF		(0x1u<<24)

// ICR_INPUT Configuration

#define	LPTIM1_ICR_INPUT_CC1IF			(0x1u<<0)
#define	LPTIM1_ICR_INPUT_ARRMCF			(0x1u<<1)
#define	LPTIM1_ICR_INPUT_EXTTRIGCF		(0x1u<<2)
#define	LPTIM1_ICR_INPUT_ARROKCF		(0x1u<<4)
#define	LPTIM1_ICR_INPUT_UPCF			(0x1u<<5)
#define	LPTIM1_ICR_INPUT_DOWNCF			(0x1u<<6)
#define	LPTIM1_ICR_INPUT_UECF			(0x1u<<7)
#define	LPTIM1_ICR_INPUT_REPOKCF		(0x1u<<8)
#define	LPTIM1_ICR_INPUT_CC2CF			(0x1u<<9)
#define	LPTIM1_ICR_INPUT_CC1OCF			(0x1u<<12)
#define	LPTIM1_ICR_INPUT_CC2OCF			(0x1u<<13)
#define	LPTIM1_ICR_INPUT_DIEROKCF		(0x1u<<24)

// DIER_OUTPUT Configuration

#define	LPTIM1_DIER_OUTPUT_CC1IF		(0x1u<<0)
#define	LPTIM1_DIER_OUTPUT_ARRMIE		(0x1u<<1)
#define	LPTIM1_DIER_OUTPUT_EXTTRIGIE	(0x1u<<2)
#define	LPTIM1_DIER_OUTPUT_CMP1OKIE		(0x1u<<3)
#define	LPTIM1_DIER_OUTPUT_ARROKIE		(0x1u<<4)
#define	LPTIM1_DIER_OUTPUT_UPIE			(0x1u<<5)
#define	LPTIM1_DIER_OUTPUT_DOWNIE		(0x1u<<6)
#define	LPTIM1_DIER_OUTPUT_UEIE			(0x1u<<7)
#define	LPTIM1_DIER_OUTPUT_REPOKIE		(0x1u<<8)
#define	LPTIM1_DIER_OUTPUT_CC2IE		(0x1u<<9)
#define	LPTIM1_DIER_OUTPUT_CMP2OKIE		(0x1u<<19)
#define	LPTIM1_DIER_OUTPUT_UEDE			(0x1u<<23)

// DIER_INPUT Configuration

#define	LPTIM1_DIER_INPUT_CC1IF			(0x1u<<0)
#define	LPTIM1_DIER_INPUT_ARRMIE		(0x1u<<1)
#define	LPTIM1_DIER_INPUT_EXTTRIGIE		(0x1u<<2)
#define	LPTIM1_DIER_INPUT_ARROKIE		(0x1u<<4)
#define	LPTIM1_DIER_INPUT_UPIE			(0x1u<<5)
#define	LPTIM1_DIER_INPUT_DOWNIE		(0x1u<<6)
#define	LPTIM1_DIER_INPUT_UEIE			(0x1u<<7)
#define	LPTIM1_DIER_INPUT_REPOKIE		(0x1u<<8)
#define	LPTIM1_DIER_INPUT_CC2IE			(0x1u<<9)
#define	LPTIM1_DIER_INPUT_CC1OIE		(0x1u<<12)
#define	LPTIM1_DIER_INPUT_CC2OIE		(0x1u<<13)
#define	LPTIM1_DIER_INPUT_CC1DE			(0x1u<<16)
#define	LPTIM1_DIER_INPUT_CC2DE			(0x1u<<25)

// CFGR Configuration

#define	LPTIM1_CFGR_CKSEL				(0x1u<<0)
#define	LPTIM1_CFGR_CKPOL				(0x3u<<1)
#define	LPTIM1_CFGR_CKPOL_0				(0x1u<<1)
#define	LPTIM1_CFGR_CKFLT				(0x3u<<3)
#define	LPTIM1_CFGR_CKFLT_0				(0x1u<<3)
#define	LPTIM1_CFGR_TRGFLT				(0x3u<<6)
#define	LPTIM1_CFGR_TRGFLT_0			(0x1u<<6)
#define	LPTIM1_CFGR_PRESC				(0x7u<<9)
#define	LPTIM1_CFGR_PRESC_0				(0x1u<<9)
#define	LPTIM1_CFGR_TRIGSEL				(0x7u<<13)
#define	LPTIM1_CFGR_TRIGSEL_0			(0x1u<<13)
#define	LPTIM1_CFGR_TRIGEN				(0x3u<<17)
#define	LPTIM1_CFGR_TRIGEN_0			(0x1u<<17)
#define	LPTIM1_CFGR_TIMOUT				(0x1u<<19)
#define	LPTIM1_CFGR_WAVE				(0x1u<<20)
#define	LPTIM1_CFGR_WAVPOL				(0x1u<<21)
#define	LPTIM1_CFGR_PRELOAD				(0x1u<<22)
#define	LPTIM1_CFGR_COUNTMODE			(0x1u<<23)
#define	LPTIM1_CFGR_ENC					(0x1u<<24)

// CR Configuration

#define	LPTIM1_CR_ENABLE				(0x1u<<0)
#define	LPTIM1_CR_SNGSTRT				(0x1u<<1)
#define	LPTIM1_CR_CNTSTRT				(0x1u<<2)
#define	LPTIM1_CR_COUNTRST				(0x1u<<3)
#define	LPTIM1_CR_RSTARE				(0x1u<<4)

// CCR1 Configuration

#define	LPTIM1_CCR1_CCR1				(0xFFFFu<<0)
#define	LPTIM1_CCR1_CCR1_0				(0x1u<<0)

// ARR Configuration

#define	LPTIM1_ARR_ARR					(0xFFFFu<<0)
#define	LPTIM1_ARR_ARR_0				(0x1u<<0)

// CNT Configuration

#define	LPTIM1_CNT_CNT					(0xFFFFu<<0)
#define	LPTIM1_CNT_CNT_0				(0x1u<<0)

// CFGR2 Configuration

#define	LPTIM1_CFGR2_IN1SEL				(0x3u<<0)
#define	LPTIM1_CFGR2_IN1SEL_0			(0x1u<<0)
#define	LPTIM1_CFGR2_IN2SEL				(0x3u<<4)
#define	LPTIM1_CFGR2_IN2SEL_0			(0x1u<<4)
#define	LPTIM1_CFGR2_IC1SEL				(0x3u<<16)
#define	LPTIM1_CFGR2_IC1SEL_0			(0x1u<<16)
#define	LPTIM1_CFGR2_IC2SEL				(0x3u<<20)
#define	LPTIM1_CFGR2_IC2SEL_0			(0x1u<<20)

// RCR Configuration

#define	LPTIM1_RCR_REP					(0xFFu<<0)
#define	LPTIM1_RCR_REP_0				(0x1u<<0)

// CCMR1 Configuration

#define	LPTIM1_CCMR1_IC2F				(0x3u<<28)
#define	LPTIM1_CCMR1_IC2F_0				(0x1u<<28)
#define	LPTIM1_CCMR1_IC2PSC				(0x3u<<24)
#define	LPTIM1_CCMR1_IC2PSC_0			(0x1u<<24)
#define	LPTIM1_CCMR1_CC2P				(0x3u<<18)
#define	LPTIM1_CCMR1_CC2P_0				(0x1u<<18)
#define	LPTIM1_CCMR1_CC2E				(0x1u<<17)
#define	LPTIM1_CCMR1_CC2SEL				(0x1u<<16)
#define	LPTIM1_CCMR1_IC1F				(0x3u<<12)
#define	LPTIM1_CCMR1_IC1F_0				(0x1u<<12)
#define	LPTIM1_CCMR1_IC1PSC				(0x3u<<8)
#define	LPTIM1_CCMR1_IC1PSC_0			(0x1u<<8)
#define	LPTIM1_CCMR1_CC1P				(0x3u<<2)
#define	LPTIM1_CCMR1_CC1P_0				(0x1u<<2)
#define	LPTIM1_CCMR1_CC1E				(0x1u<<1)
#define	LPTIM1_CCMR1_CC1SEL				(0x1u<<0)

// CCR2 Configuration

#define	LPTIM1_CCR2_CCR2				(0xFFFFu<<0)
#define	LPTIM1_CCR2_CCR2_0				(0x1u<<0)
