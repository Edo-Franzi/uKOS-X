/*
; stm32H747_CM4_tim15.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM4_tim15 equates.
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

// TIM15 address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	CR1;
	volatile	uint32_t	CR2;
	volatile	uint32_t	SMCR;
	volatile	uint32_t	DIER;
	volatile	uint32_t	SR;
	volatile	uint32_t	EGR;
	volatile	uint32_t	CCMR1;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	CCER;
	volatile	uint32_t	CNT;
	volatile	uint32_t	PSC;
	volatile	uint32_t	ARR;
	volatile	uint32_t	RCR;
	volatile	uint32_t	CCR1;
	volatile	uint32_t	CCR2;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	BDTR;
	volatile	uint32_t	DCR;
	volatile	uint32_t	DMAR;
	volatile	uint32_t	RESERVED2[4];
	volatile	uint32_t	AF1;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	TISEL;
} TIM15_TypeDef;

#if (defined(__cplusplus))
#define	TIM15	reinterpret_cast<TIM15_TypeDef *>(0x40014000u)

#else
#define	TIM15	((TIM15_TypeDef *)0x40014000u)
#endif

// CR1 Configuration

#define	TIM15_CR1_UIFREMAP		(0x1u<<11)
#define	TIM15_CR1_CKD			(0x3u<<8)
#define	TIM15_CR1_CKD_0			(0x1u<<8)
#define	TIM15_CR1_ARPE			(0x1u<<7)
#define	TIM15_CR1_OPM			(0x1u<<3)
#define	TIM15_CR1_URS			(0x1u<<2)
#define	TIM15_CR1_UDIS			(0x1u<<1)
#define	TIM15_CR1_CEN			(0x1u<<0)

// CR2 Configuration

#define	TIM15_CR2_OIS2			(0x1u<<10)
#define	TIM15_CR2_OIS1N			(0x1u<<9)
#define	TIM15_CR2_OIS1			(0x1u<<8)
#define	TIM15_CR2_TI1S			(0x1u<<7)
#define	TIM15_CR2_MMS			(0x7u<<4)
#define	TIM15_CR2_MMS_0			(0x1u<<4)
#define	TIM15_CR2_CCDS			(0x1u<<3)
#define	TIM15_CR2_CCUS			(0x1u<<2)
#define	TIM15_CR2_CCPC			(0x1u<<0)

// SMCR Configuration

#define	TIM15_SMCR_TS_4_3		(0x3u<<20)
#define	TIM15_SMCR_TS_4_3_0		(0x1u<<20)
#define	TIM15_SMCR_SMS_3		(0x1u<<16)
#define	TIM15_SMCR_MSM			(0x1u<<7)
#define	TIM15_SMCR_TS_2_0		(0x7u<<4)
#define	TIM15_SMCR_TS_2_0_0		(0x1u<<4)
#define	TIM15_SMCR_SMS			(0x7u<<0)
#define	TIM15_SMCR_SMS_0		(0x1u<<0)

// DIER Configuration

#define	TIM15_DIER_TDE			(0x1u<<14)
#define	TIM15_DIER_COMDE		(0x1u<<13)
#define	TIM15_DIER_CC2DE		(0x1u<<10)
#define	TIM15_DIER_CC1DE		(0x1u<<9)
#define	TIM15_DIER_UDE			(0x1u<<8)
#define	TIM15_DIER_BIE			(0x1u<<7)
#define	TIM15_DIER_TIE			(0x1u<<6)
#define	TIM15_DIER_COMIE		(0x1u<<5)
#define	TIM15_DIER_CC2IE		(0x1u<<2)
#define	TIM15_DIER_CC1IE		(0x1u<<1)
#define	TIM15_DIER_UIE			(0x1u<<0)

// SR Configuration

#define	TIM15_SR_UIF			(0x1u<<0)
#define	TIM15_SR_CC1IF			(0x1u<<1)
#define	TIM15_SR_CC2IF			(0x1u<<2)
#define	TIM15_SR_COMIF			(0x1u<<5)
#define	TIM15_SR_TIF			(0x1u<<6)
#define	TIM15_SR_BIF			(0x1u<<7)
#define	TIM15_SR_CC1OF			(0x1u<<9)
#define	TIM15_SR_CC2OF			(0x1u<<10)

// EGR Configuration

#define	TIM15_EGR_UG			(0x1u<<0)
#define	TIM15_EGR_CC1G			(0x1u<<1)
#define	TIM15_EGR_CC2G			(0x1u<<2)
#define	TIM15_EGR_COMG			(0x1u<<5)
#define	TIM15_EGR_TG			(0x1u<<6)
#define	TIM15_EGR_BG			(0x1u<<7)

// CCMR1 Configuration

#define	TIM15_CCMR1_OC2M_3		(0x1u<<24)
#define	TIM15_CCMR1_OC1M_3		(0x1u<<16)
#define	TIM15_CCMR1_OC2M		(0x7u<<12)
#define	TIM15_CCMR1_OC2M_0		(0x1u<<12)
#define	TIM15_CCMR1_OC2PE		(0x1u<<11)
#define	TIM15_CCMR1_OC2FE		(0x1u<<10)
#define	TIM15_CCMR1_CC2S		(0x3u<<8)
#define	TIM15_CCMR1_CC2S_0		(0x1u<<8)
#define	TIM15_CCMR1_OC1M		(0x7u<<4)
#define	TIM15_CCMR1_OC1M_0		(0x1u<<4)
#define	TIM15_CCMR1_OC1PE		(0x1u<<3)
#define	TIM15_CCMR1_OC1FE		(0x1u<<2)
#define	TIM15_CCMR1_CC1S		(0x3u<<0)
#define	TIM15_CCMR1_CC1S_0		(0x1u<<0)

// CCER Configuration

#define	TIM15_CCER_CC1E			(0x1u<<0)
#define	TIM15_CCER_CC1P			(0x1u<<1)
#define	TIM15_CCER_CC1NE		(0x1u<<2)
#define	TIM15_CCER_CC1NP		(0x1u<<3)
#define	TIM15_CCER_CC2E			(0x1u<<4)
#define	TIM15_CCER_CC2P			(0x1u<<5)
#define	TIM15_CCER_CC2NP		(0x1u<<7)

// CNT Configuration

#define	TIM15_CNT_UIFCPY		(0x1u<<31)
#define	TIM15_CNT_CNT			(0xFFFFu<<0)
#define	TIM15_CNT_CNT_0			(0x1u<<0)

// PSC Configuration

#define	TIM15_PSC_PSC			(0xFFFFu<<0)
#define	TIM15_PSC_PSC_0			(0x1u<<0)

// ARR Configuration

#define	TIM15_ARR_ARR			(0xFFFFu<<0)
#define	TIM15_ARR_ARR_0			(0x1u<<0)

// RCR Configuration

#define	TIM15_RCR_REP			(0xFFu<<0)
#define	TIM15_RCR_REP_0			(0x1u<<0)

// CCR1 Configuration

#define	TIM15_CCR1_CCR1			(0xFFFFu<<0)
#define	TIM15_CCR1_CCR1_0		(0x1u<<0)

// CCR2 Configuration

#define	TIM15_CCR2_CCR2			(0xFFFFu<<0)
#define	TIM15_CCR2_CCR2_0		(0x1u<<0)

// BDTR Configuration

#define	TIM15_BDTR_BKF			(0xFu<<16)
#define	TIM15_BDTR_BKF_0		(0x1u<<16)
#define	TIM15_BDTR_DTG			(0xFFu<<0)
#define	TIM15_BDTR_DTG_0		(0x1u<<0)
#define	TIM15_BDTR_LOCK			(0x3u<<8)
#define	TIM15_BDTR_LOCK_0		(0x1u<<8)
#define	TIM15_BDTR_OSSI			(0x1u<<10)
#define	TIM15_BDTR_OSSR			(0x1u<<11)
#define	TIM15_BDTR_BKE			(0x1u<<12)
#define	TIM15_BDTR_BKP			(0x1u<<13)
#define	TIM15_BDTR_AOE			(0x1u<<14)
#define	TIM15_BDTR_MOE			(0x1u<<15)

// DCR Configuration

#define	TIM15_DCR_DBA			(0x1Fu<<0)
#define	TIM15_DCR_DBA_0			(0x1u<<0)
#define	TIM15_DCR_DBL			(0x1Fu<<8)
#define	TIM15_DCR_DBL_0			(0x1u<<8)

// DMAR Configuration

#define	TIM15_DMAR_DMAB			(0xFFFFu<<0)
#define	TIM15_DMAR_DMAB_0		(0x1u<<0)

// AF1 Configuration

#define	TIM15_AF1_BKCMP2P		(0x1u<<11)
#define	TIM15_AF1_BKCMP1P		(0x1u<<10)
#define	TIM15_AF1_BKINP			(0x1u<<9)
#define	TIM15_AF1_BKDF1BK0E		(0x1u<<8)
#define	TIM15_AF1_BKCMP2E		(0x1u<<2)
#define	TIM15_AF1_BKCMP1E		(0x1u<<1)
#define	TIM15_AF1_BKINE			(0x1u<<0)

// TISEL Configuration

#define	TIM15_TISEL_TI2SEL		(0xFu<<8)
#define	TIM15_TISEL_TI2SEL_0	(0x1u<<8)
#define	TIM15_TISEL_TI1SEL		(0xFu<<0)
#define	TIM15_TISEL_TI1SEL_0	(0x1u<<0)
