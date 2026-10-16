/*
; stm32U5Gx_tim17.
; ================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_tim17 equates.
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

// TIM17 address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	CR1;
	volatile	uint32_t	CR2;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	DIER;
	volatile	uint32_t	SR;
	volatile	uint32_t	EGR;
	volatile	uint32_t	CCMR1;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	CCER;
	volatile	uint32_t	CNT;
	volatile	uint32_t	PSC;
	volatile	uint32_t	ARR;
	volatile	uint32_t	RCR;
	volatile	uint32_t	CCR1;
	volatile	uint32_t	RESERVED2[3];
	volatile	uint32_t	BDTR;
	volatile	uint32_t	RESERVED3[2];
	volatile	uint32_t	OR1;
	volatile	uint32_t	DTR2;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	TISEL;
	volatile	uint32_t	AF1;
	volatile	uint32_t	AF2;
	volatile	uint32_t	RESERVED5[221];
	volatile	uint32_t	DCR;
	volatile	uint32_t	DMAR;
} TIM17_TypeDef;

#if (defined(__cplusplus))
#define	TIM17_NS	reinterpret_cast<TIM17_TypeDef *>(0x40014800u)
#define	TIM17_S		reinterpret_cast<TIM17_TypeDef *>(0x50014800u)

#else
#define	TIM17_NS	((TIM17_TypeDef *)0x40014800u)
#define	TIM17_S		((TIM17_TypeDef *)0x50014800u)
#endif

// CR1 Configuration

#define	TIM17_CR1_CEN			(0x1u<<0)
#define	TIM17_CR1_UDIS			(0x1u<<1)
#define	TIM17_CR1_URS			(0x1u<<2)
#define	TIM17_CR1_OPM			(0x1u<<3)
#define	TIM17_CR1_ARPE			(0x1u<<7)
#define	TIM17_CR1_CKD			(0x3u<<8)
#define	TIM17_CR1_CKD_0			(0x1u<<8)
#define	TIM17_CR1_UIFREMAP		(0x1u<<11)

// CR2 Configuration

#define	TIM17_CR2_CCPC			(0x1u<<0)
#define	TIM17_CR2_CCUS			(0x1u<<2)
#define	TIM17_CR2_CCDS			(0x1u<<3)
#define	TIM17_CR2_OIS1			(0x1u<<8)
#define	TIM17_CR2_OIS1N			(0x1u<<9)

// DIER Configuration

#define	TIM17_DIER_UIE			(0x1u<<0)
#define	TIM17_DIER_CC1IE		(0x1u<<1)
#define	TIM17_DIER_COMIE		(0x1u<<5)
#define	TIM17_DIER_BIE			(0x1u<<7)
#define	TIM17_DIER_UDE			(0x1u<<8)
#define	TIM17_DIER_CC1DE		(0x1u<<9)
#define	TIM17_DIER_COMDE		(0x1u<<13)

// SR Configuration

#define	TIM17_SR_UIF			(0x1u<<0)
#define	TIM17_SR_CC1IF			(0x1u<<1)
#define	TIM17_SR_COMIF			(0x1u<<5)
#define	TIM17_SR_BIF			(0x1u<<7)
#define	TIM17_SR_CC1OF			(0x1u<<9)

// EGR Configuration

#define	TIM17_EGR_UG			(0x1u<<0)
#define	TIM17_EGR_CC1G			(0x1u<<1)
#define	TIM17_EGR_COMG			(0x1u<<5)
#define	TIM17_EGR_BG			(0x1u<<7)

// CCMR1 Configuration

#define	TIM17_CCMR1_CC1S		(0x3u<<0)
#define	TIM17_CCMR1_CC1S_0		(0x1u<<0)
#define	TIM17_CCMR1_OC1FE		(0x1u<<2)
#define	TIM17_CCMR1_OC1PE		(0x1u<<3)
#define	TIM17_CCMR1_OC1M		(0x7u<<4)
#define	TIM17_CCMR1_OC1M_0		(0x1u<<4)
#define	TIM17_CCMR1_OC1CE		(0x1u<<7)
#define	TIM17_CCMR1_OC1M_2		(0x1u<<16)

// CCER Configuration

#define	TIM17_CCER_CC1E			(0x1u<<0)
#define	TIM17_CCER_CC1P			(0x1u<<1)
#define	TIM17_CCER_CC1NE		(0x1u<<2)
#define	TIM17_CCER_CC1NP		(0x1u<<3)

// CNT Configuration

#define	TIM17_CNT_CNT			(0xFFFFu<<0)
#define	TIM17_CNT_CNT_0			(0x1u<<0)
#define	TIM17_CNT_UIFCPY		(0x1u<<31)

// PSC Configuration

#define	TIM17_PSC_PSC			(0xFFFFu<<0)
#define	TIM17_PSC_PSC_0			(0x1u<<0)

// ARR Configuration

#define	TIM17_ARR_ARR			(0xFFFFFu<<0)
#define	TIM17_ARR_ARR_0			(0x1u<<0)

// RCR Configuration

#define	TIM17_RCR_REP			(0xFFu<<0)
#define	TIM17_RCR_REP_0			(0x1u<<0)

// CCR1 Configuration

#define	TIM17_CCR1_CCR1			(0xFFFFFu<<0)
#define	TIM17_CCR1_CCR1_0		(0x1u<<0)

// BDTR Configuration

#define	TIM17_BDTR_DTG			(0xFFu<<0)
#define	TIM17_BDTR_DTG_0		(0x1u<<0)
#define	TIM17_BDTR_LOCK			(0x3u<<8)
#define	TIM17_BDTR_LOCK_0		(0x1u<<8)
#define	TIM17_BDTR_OSSI			(0x1u<<10)
#define	TIM17_BDTR_OSSR			(0x1u<<11)
#define	TIM17_BDTR_BKE			(0x1u<<12)
#define	TIM17_BDTR_BKP			(0x1u<<13)
#define	TIM17_BDTR_AOE			(0x1u<<14)
#define	TIM17_BDTR_MOE			(0x1u<<15)
#define	TIM17_BDTR_BKDSRM		(0x1u<<26)
#define	TIM17_BDTR_BKBID		(0x1u<<28)

// OR1 Configuration

#define	TIM17_OR1_HSE32EN		(0x1u<<0)

// DTR2 Configuration

#define	TIM17_DTR2_DTGF			(0xFFu<<0)
#define	TIM17_DTR2_DTGF_0		(0x1u<<0)
#define	TIM17_DTR2_DTAE			(0x1u<<16)
#define	TIM17_DTR2_DTPE			(0x1u<<17)

// TISEL Configuration

#define	TIM17_TISEL_TI1SEL		(0xFu<<0)
#define	TIM17_TISEL_TI1SEL_0	(0x1u<<0)

// AF1 Configuration

#define	TIM17_AF1_BKINE			(0x1u<<0)
#define	TIM17_AF1_BKCMP1E		(0x1u<<1)
#define	TIM17_AF1_BKCMP2E		(0x1u<<2)
#define	TIM17_AF1_BKCMP3E		(0x1u<<3)
#define	TIM17_AF1_BKCMP4E		(0x1u<<4)
#define	TIM17_AF1_BKCMP5E		(0x1u<<5)
#define	TIM17_AF1_BKCMP6E		(0x1u<<6)
#define	TIM17_AF1_BKCMP7E		(0x1u<<7)
#define	TIM17_AF1_BKINP			(0x1u<<9)
#define	TIM17_AF1_BKCMP1P		(0x1u<<10)
#define	TIM17_AF1_BKCMP2P		(0x1u<<11)
#define	TIM17_AF1_BKCMP3P		(0x1u<<12)
#define	TIM17_AF1_BKCMP4P		(0x1u<<13)

// AF2 Configuration

#define	TIM17_AF2_OCRSEL		(0x7u<<16)
#define	TIM17_AF2_OCRSEL_0		(0x1u<<16)

// DCR Configuration

#define	TIM17_DCR_DBA			(0x1Fu<<0)
#define	TIM17_DCR_DBA_0			(0x1u<<0)
#define	TIM17_DCR_DBL			(0x1Fu<<8)
#define	TIM17_DCR_DBL_0			(0x1u<<8)
#define	TIM17_DCR_DBSS			(0xFu<<16)
#define	TIM17_DCR_DBSS_0		(0x1u<<16)

// DMAR Configuration

#define	TIM17_DMAR_DMAB			(0xFFFFFFFFu<<0)
#define	TIM17_DMAR_DMAB_0		(0x1u<<0)
