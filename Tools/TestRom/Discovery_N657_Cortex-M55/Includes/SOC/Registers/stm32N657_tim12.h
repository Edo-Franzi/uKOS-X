/*
; stm32N657_tim12.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_tim12 equates.
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

// TIM12 address definitions
// -------------------------

typedef struct {
	volatile	uint16_t	CR1;
	volatile	uint16_t	RESERVED0;
	volatile	uint32_t	CR2;
	volatile	uint32_t	SMCR;
	volatile	uint16_t	DIER;
	volatile	uint16_t	RESERVED1;
	volatile	uint16_t	SR;
	volatile	uint16_t	RESERVED2;
	volatile	uint16_t	EGR;
	volatile	uint16_t	RESERVED3;
	volatile	uint32_t	CCMR1;
	volatile	uint32_t	RESERVED4;
	volatile	uint16_t	CCER;
	volatile	uint16_t	RESERVED5;
	volatile	uint32_t	CNT;
	volatile	uint16_t	PSC;
	volatile	uint16_t	RESERVED6;
	volatile	uint32_t	ARR;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	CCR1;
	volatile	uint32_t	CCR2;
	volatile	uint32_t	RESERVED8[8];
	volatile	uint16_t	TISEL;
} TIM12_TypeDef;

#if (defined(__cplusplus))
#define	TIM12_NS	reinterpret_cast<TIM12_TypeDef *>(0x40001800u)
#define	TIM12_S		reinterpret_cast<TIM12_TypeDef *>(0x50001800u)

#else
#define	TIM12_NS	((TIM12_TypeDef *)0x40001800u)
#define	TIM12_S		((TIM12_TypeDef *)0x50001800u)
#endif

// CR1 Configuration

#define	TIM12_CR1_DITHEN			(0x1u<<12)
#define	TIM12_CR1_UIFREMAP			(0x1u<<11)
#define	TIM12_CR1_CKD				(0x3u<<8)
#define	TIM12_CR1_CKD_0				(0x1u<<8)
#define	TIM12_CR1_ARPE				(0x1u<<7)
#define	TIM12_CR1_OPM				(0x1u<<3)
#define	TIM12_CR1_URS				(0x1u<<2)
#define	TIM12_CR1_UDIS				(0x1u<<1)
#define	TIM12_CR1_CEN				(0x1u<<0)

#define	TIM12_CR1_DITHEN_B_0X0		(0x0u<<12)
#define	TIM12_CR1_DITHEN_B_0X1		(0x1u<<12)
#define	TIM12_CR1_UIFREMAP_B_0X0	(0x0u<<11)
#define	TIM12_CR1_UIFREMAP_B_0X1	(0x1u<<11)
#define	TIM12_CR1_CKD_B_0X0			(0x0u<<8)
#define	TIM12_CR1_CKD_B_0X1			(0x1u<<8)
#define	TIM12_CR1_CKD_B_0X2			(0x2u<<8)
#define	TIM12_CR1_ARPE_B_0X0		(0x0u<<7)
#define	TIM12_CR1_ARPE_B_0X1		(0x1u<<7)
#define	TIM12_CR1_OPM_B_0X0			(0x0u<<3)
#define	TIM12_CR1_OPM_B_0X1			(0x1u<<3)
#define	TIM12_CR1_URS_B_0X0			(0x0u<<2)
#define	TIM12_CR1_URS_B_0X1			(0x1u<<2)
#define	TIM12_CR1_UDIS_B_0X0		(0x0u<<1)
#define	TIM12_CR1_UDIS_B_0X1		(0x1u<<1)
#define	TIM12_CR1_CEN_B_0X0			(0x0u<<0)
#define	TIM12_CR1_CEN_B_0X1			(0x1u<<0)

// CR2 Configuration

#define	TIM12_CR2_ADSYNC			(0x1u<<28)
#define	TIM12_CR2_TI1S				(0x1u<<7)
#define	TIM12_CR2_MMS				(0x7u<<4)
#define	TIM12_CR2_MMS_0				(0x1u<<4)

#define	TIM12_CR2_ADSYNC_B_0X0		(0x0u<<28)
#define	TIM12_CR2_ADSYNC_B_0X1		(0x1u<<28)
#define	TIM12_CR2_TI1S_B_0X0		(0x0u<<7)
#define	TIM12_CR2_TI1S_B_0X1		(0x1u<<7)
#define	TIM12_CR2_MMS_B_0X0			(0x0u<<4)
#define	TIM12_CR2_MMS_B_0X1			(0x1u<<4)
#define	TIM12_CR2_MMS_B_0X2			(0x2u<<4)
#define	TIM12_CR2_MMS_B_0X3			(0x3u<<4)
#define	TIM12_CR2_MMS_B_0X4			(0x4u<<4)
#define	TIM12_CR2_MMS_B_0X5			(0x5u<<4)

// SMCR Configuration

#define	TIM12_SMCR_TS_1				(0x3u<<20)
#define	TIM12_SMCR_TS_1_0			(0x1u<<20)
#define	TIM12_SMCR_SMS_1			(0x1u<<16)
#define	TIM12_SMCR_MSM				(0x1u<<7)
#define	TIM12_SMCR_TS				(0x7u<<4)
#define	TIM12_SMCR_TS_0				(0x1u<<4)
#define	TIM12_SMCR_SMS				(0x7u<<0)
#define	TIM12_SMCR_SMS_0			(0x1u<<0)

#define	TIM12_SMCR_MSM_B_0X0		(0x0u<<7)
#define	TIM12_SMCR_MSM_B_0X1		(0x1u<<7)
#define	TIM12_SMCR_TS_B_0X0			(0x0u<<4)
#define	TIM12_SMCR_TS_B_0X1			(0x1u<<4)
#define	TIM12_SMCR_TS_B_0X2			(0x2u<<4)
#define	TIM12_SMCR_TS_B_0X3			(0x3u<<4)
#define	TIM12_SMCR_TS_B_0X4			(0x4u<<4)
#define	TIM12_SMCR_TS_B_0X5			(0x5u<<4)
#define	TIM12_SMCR_TS_B_0X6			(0x6u<<4)
#define	TIM12_SMCR_SMS_B_0X0		(0x0u<<0)
#define	TIM12_SMCR_SMS_B_0X4		(0x4u<<0)
#define	TIM12_SMCR_SMS_B_0X5		(0x5u<<0)
#define	TIM12_SMCR_SMS_B_0X6		(0x6u<<0)
#define	TIM12_SMCR_SMS_B_0X7		(0x7u<<0)

// DIER Configuration

#define	TIM12_DIER_TIE				(0x1u<<6)
#define	TIM12_DIER_CC2IE			(0x1u<<2)
#define	TIM12_DIER_CC1IE			(0x1u<<1)
#define	TIM12_DIER_UIE				(0x1u<<0)

#define	TIM12_DIER_TIE_B_0X0		(0x0u<<6)
#define	TIM12_DIER_TIE_B_0X1		(0x1u<<6)
#define	TIM12_DIER_CC2IE_B_0X0		(0x0u<<2)
#define	TIM12_DIER_CC2IE_B_0X1		(0x1u<<2)
#define	TIM12_DIER_CC1IE_B_0X0		(0x0u<<1)
#define	TIM12_DIER_CC1IE_B_0X1		(0x1u<<1)
#define	TIM12_DIER_UIE_B_0X0		(0x0u<<0)
#define	TIM12_DIER_UIE_B_0X1		(0x1u<<0)

// SR Configuration

#define	TIM12_SR_CC2OF				(0x1u<<10)
#define	TIM12_SR_CC1OF				(0x1u<<9)
#define	TIM12_SR_TIF				(0x1u<<6)
#define	TIM12_SR_CC2IF				(0x1u<<2)
#define	TIM12_SR_CC1IF				(0x1u<<1)
#define	TIM12_SR_UIF				(0x1u<<0)

#define	TIM12_SR_CC1OF_B_0X0		(0x0u<<9)
#define	TIM12_SR_CC1OF_B_0X1		(0x1u<<9)
#define	TIM12_SR_TIF_B_0X0			(0x0u<<6)
#define	TIM12_SR_TIF_B_0X1			(0x1u<<6)
#define	TIM12_SR_CC1IF_B_0X0		(0x0u<<1)
#define	TIM12_SR_CC1IF_B_0X1		(0x1u<<1)
#define	TIM12_SR_UIF_B_0X0			(0x0u<<0)
#define	TIM12_SR_UIF_B_0X1			(0x1u<<0)

// EGR Configuration

#define	TIM12_EGR_TG				(0x1u<<6)
#define	TIM12_EGR_CC2G				(0x1u<<2)
#define	TIM12_EGR_CC1G				(0x1u<<1)
#define	TIM12_EGR_UG				(0x1u<<0)

#define	TIM12_EGR_TG_B_0X0			(0x0u<<6)
#define	TIM12_EGR_TG_B_0X1			(0x1u<<6)
#define	TIM12_EGR_CC1G_B_0X0		(0x0u<<1)
#define	TIM12_EGR_CC1G_B_0X1		(0x1u<<1)
#define	TIM12_EGR_UG_B_0X0			(0x0u<<0)
#define	TIM12_EGR_UG_B_0X1			(0x1u<<0)

// CCMR1 Configuration

#define	TIM12_CCMR1_IC2F			(0xFu<<12)
#define	TIM12_CCMR1_IC2F_0			(0x1u<<12)
#define	TIM12_CCMR1_IC2PSC			(0x3u<<10)
#define	TIM12_CCMR1_IC2PSC_0		(0x1u<<10)
#define	TIM12_CCMR1_CC2S			(0x3u<<8)
#define	TIM12_CCMR1_CC2S_0			(0x1u<<8)
#define	TIM12_CCMR1_IC1F			(0xFu<<4)
#define	TIM12_CCMR1_IC1F_0			(0x1u<<4)
#define	TIM12_CCMR1_IC1PSC			(0x3u<<2)
#define	TIM12_CCMR1_IC1PSC_0		(0x1u<<2)
#define	TIM12_CCMR1_CC1S			(0x3u<<0)
#define	TIM12_CCMR1_CC1S_0			(0x1u<<0)

#define	TIM12_CCMR1_CC2S_B_0X0		(0x0u<<8)
#define	TIM12_CCMR1_CC2S_B_0X1		(0x1u<<8)
#define	TIM12_CCMR1_CC2S_B_0X2		(0x2u<<8)
#define	TIM12_CCMR1_CC2S_B_0X3		(0x3u<<8)
#define	TIM12_CCMR1_IC1F_B_0X0		(0x0u<<4)
#define	TIM12_CCMR1_IC1F_B_0X1		(0x1u<<4)
#define	TIM12_CCMR1_IC1F_B_0X2		(0x2u<<4)
#define	TIM12_CCMR1_IC1F_B_0X3		(0x3u<<4)
#define	TIM12_CCMR1_IC1F_B_0X4		(0x4u<<4)
#define	TIM12_CCMR1_IC1F_B_0X5		(0x5u<<4)
#define	TIM12_CCMR1_IC1F_B_0X6		(0x6u<<4)
#define	TIM12_CCMR1_IC1F_B_0X7		(0x7u<<4)
#define	TIM12_CCMR1_IC1F_B_0X8		(0x8u<<4)
#define	TIM12_CCMR1_IC1F_B_0X9		(0x9u<<4)
#define	TIM12_CCMR1_IC1F_B_0XA		(0xAu<<4)
#define	TIM12_CCMR1_IC1F_B_0XB		(0xBu<<4)
#define	TIM12_CCMR1_IC1F_B_0XC		(0xCu<<4)
#define	TIM12_CCMR1_IC1F_B_0XD		(0xDu<<4)
#define	TIM12_CCMR1_IC1F_B_0XE		(0xEu<<4)
#define	TIM12_CCMR1_IC1F_B_0XF		(0xFu<<4)
#define	TIM12_CCMR1_IC1PSC_B_0X0	(0x0u<<2)
#define	TIM12_CCMR1_IC1PSC_B_0X1	(0x1u<<2)
#define	TIM12_CCMR1_IC1PSC_B_0X2	(0x2u<<2)
#define	TIM12_CCMR1_IC1PSC_B_0X3	(0x3u<<2)
#define	TIM12_CCMR1_CC1S_B_0X0		(0x0u<<0)
#define	TIM12_CCMR1_CC1S_B_0X1		(0x1u<<0)
#define	TIM12_CCMR1_CC1S_B_0X2		(0x2u<<0)
#define	TIM12_CCMR1_CC1S_B_0X3		(0x3u<<0)

// CCER Configuration

#define	TIM12_CCER_CC2NP			(0x1u<<7)
#define	TIM12_CCER_CC2P				(0x1u<<5)
#define	TIM12_CCER_CC2E				(0x1u<<4)
#define	TIM12_CCER_CC1NP			(0x1u<<3)
#define	TIM12_CCER_CC1P				(0x1u<<1)
#define	TIM12_CCER_CC1E				(0x1u<<0)

#define	TIM12_CCER_CC1P_B_0X0		(0x0u<<1)
#define	TIM12_CCER_CC1P_B_0X1		(0x1u<<1)
#define	TIM12_CCER_CC1E_B_0X0		(0x0u<<0)
#define	TIM12_CCER_CC1E_B_0X1		(0x1u<<0)

// CNT Configuration

#define	TIM12_CNT_UIFCPY			(0x1u<<31)
#define	TIM12_CNT_CNT				(0xFFFFu<<0)
#define	TIM12_CNT_CNT_0				(0x1u<<0)

// PSC Configuration

#define	TIM12_PSC_PSC				(0xFFFFu<<0)
#define	TIM12_PSC_PSC_0				(0x1u<<0)

// ARR Configuration

#define	TIM12_ARR_ARR				(0xFFFFFu<<0)
#define	TIM12_ARR_ARR_0				(0x1u<<0)

// CCR1 Configuration

#define	TIM12_CCR1_CCR1				(0xFFFFFu<<0)
#define	TIM12_CCR1_CCR1_0			(0x1u<<0)

// CCR2 Configuration

#define	TIM12_CCR2_CCR2				(0xFFFFFu<<0)
#define	TIM12_CCR2_CCR2_0			(0x1u<<0)

// TISEL Configuration

#define	TIM12_TISEL_TI2SEL			(0xFu<<8)
#define	TIM12_TISEL_TI2SEL_0		(0x1u<<8)
#define	TIM12_TISEL_TI1SEL			(0xFu<<0)
#define	TIM12_TISEL_TI1SEL_0		(0x1u<<0)

#define	TIM12_TISEL_TI2SEL_B_0X0	(0x0u<<8)
#define	TIM12_TISEL_TI2SEL_B_0X1	(0x1u<<8)
#define	TIM12_TISEL_TI2SEL_B_0X4	(0x4u<<8)
#define	TIM12_TISEL_TI1SEL_B_0X0	(0x0u<<0)
#define	TIM12_TISEL_TI1SEL_B_0X1	(0x1u<<0)
#define	TIM12_TISEL_TI1SEL_B_0XF	(0xFu<<0)
