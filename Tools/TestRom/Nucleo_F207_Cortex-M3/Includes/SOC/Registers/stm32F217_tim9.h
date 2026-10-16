/*
; stm32F217_tim9.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_tim9 equates.
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

// TIM9 address definitions
// ------------------------

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
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	CCR1;
	volatile	uint32_t	CCR2;
} TIM9_TypeDef;

#if (defined(__cplusplus))
#define	TIM9	reinterpret_cast<TIM9_TypeDef *>(0x40014000u)

#else
#define	TIM9	((TIM9_TypeDef *)0x40014000u)
#endif

// CR1 Configuration

#define	TIM9_CR1_CEN		(0x1u<<0)
#define	TIM9_CR1_UDIS		(0x1u<<1)
#define	TIM9_CR1_URS		(0x1u<<2)
#define	TIM9_CR1_OPM		(0x1u<<3)
#define	TIM9_CR1_ARPE		(0x1u<<7)
#define	TIM9_CR1_CKD		(0x3u<<8)
#define	TIM9_CR1_CKD_0		(0x1u<<8)

// CR2 Configuration

#define	TIM9_CR2_MMS		(0x7u<<4)
#define	TIM9_CR2_MMS_0		(0x1u<<4)

// SMCR Configuration

#define	TIM9_SMCR_SMS		(0x7u<<0)
#define	TIM9_SMCR_SMS_0		(0x1u<<0)
#define	TIM9_SMCR_TS		(0x7u<<4)
#define	TIM9_SMCR_TS_0		(0x1u<<4)
#define	TIM9_SMCR_MSM		(0x1u<<7)

// DIER Configuration

#define	TIM9_DIER_UIE		(0x1u<<0)
#define	TIM9_DIER_CC1IE		(0x1u<<1)
#define	TIM9_DIER_CC2IE		(0x1u<<2)
#define	TIM9_DIER_TIE		(0x1u<<6)

// SR Configuration

#define	TIM9_SR_UIF			(0x1u<<0)
#define	TIM9_SR_CC1IF		(0x1u<<1)
#define	TIM9_SR_CC2IF		(0x1u<<2)
#define	TIM9_SR_TIF			(0x1u<<6)
#define	TIM9_SR_CC1OF		(0x1u<<9)
#define	TIM9_SR_CC2OF		(0x1u<<10)

// EGR Configuration

#define	TIM9_EGR_UG			(0x1u<<0)
#define	TIM9_EGR_CC1G		(0x1u<<1)
#define	TIM9_EGR_CC2G		(0x1u<<2)
#define	TIM9_EGR_TG			(0x1u<<6)

// CCMR1 Configuration

#define	TIM9_CCMR1_CC1S		(0x3u<<0)
#define	TIM9_CCMR1_CC1S_0	(0x1u<<0)
#define	TIM9_CCMR1_OC1FE	(0x1u<<2)
#define	TIM9_CCMR1_OC1PE	(0x1u<<3)
#define	TIM9_CCMR1_OC1M		(0x7u<<4)
#define	TIM9_CCMR1_OC1M_0	(0x1u<<4)
#define	TIM9_CCMR1_CC2S		(0x3u<<8)
#define	TIM9_CCMR1_CC2S_0	(0x1u<<8)
#define	TIM9_CCMR1_OC2FE	(0x1u<<10)
#define	TIM9_CCMR1_OC2PE	(0x1u<<11)
#define	TIM9_CCMR1_OC2M		(0x7u<<12)
#define	TIM9_CCMR1_OC2M_0	(0x1u<<12)

// CCER Configuration

#define	TIM9_CCER_CC1E		(0x1u<<0)
#define	TIM9_CCER_CC1P		(0x1u<<1)
#define	TIM9_CCER_CC1NP		(0x1u<<3)
#define	TIM9_CCER_CC2E		(0x1u<<4)
#define	TIM9_CCER_CC2P		(0x1u<<5)
#define	TIM9_CCER_CC2NP		(0x1u<<7)

// CNT Configuration

#define	TIM9_CNT_CNT		(0xFFFFu<<0)
#define	TIM9_CNT_CNT_0		(0x1u<<0)

// PSC Configuration

#define	TIM9_PSC_PSC		(0xFFFFu<<0)
#define	TIM9_PSC_PSC_0		(0x1u<<0)

// ARR Configuration

#define	TIM9_ARR_ARR		(0xFFFFu<<0)
#define	TIM9_ARR_ARR_0		(0x1u<<0)

// CCR1 Configuration

#define	TIM9_CCR1_CCR1		(0xFFFFu<<0)
#define	TIM9_CCR1_CCR1_0	(0x1u<<0)

// CCR2 Configuration

#define	TIM9_CCR2_CCR2		(0xFFFFu<<0)
#define	TIM9_CCR2_CCR2_0	(0x1u<<0)
