/*
; stm32N657_tim16.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_tim16 equates.
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

// TIM16 address definitions
// -------------------------

typedef struct {
	volatile	uint16_t	CR1;
	volatile	uint16_t	RESERVED0;
	volatile	uint16_t	CR2;
	volatile	uint16_t	RESERVED1[3];
	volatile	uint16_t	DIER;
	volatile	uint16_t	RESERVED2;
	volatile	uint16_t	SR;
	volatile	uint16_t	RESERVED3;
	volatile	uint16_t	EGR;
	volatile	uint16_t	RESERVED4;
	volatile	uint32_t	CCMR1;
	volatile	uint32_t	RESERVED5;
	volatile	uint16_t	CCER;
	volatile	uint16_t	RESERVED6;
	volatile	uint32_t	CNT;
	volatile	uint16_t	PSC;
	volatile	uint16_t	RESERVED7;
	volatile	uint32_t	ARR;
	volatile	uint16_t	RCR;
	volatile	uint16_t	RESERVED8;
	volatile	uint32_t	CCR1;
	volatile	uint32_t	RESERVED9[3];
	volatile	uint32_t	BDTR;
	volatile	uint32_t	RESERVED10[3];
	volatile	uint32_t	DTR2;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	TISEL;
	volatile	uint32_t	AF1;
	volatile	uint32_t	AF2;
	volatile	uint32_t	RESERVED12[221];
	volatile	uint32_t	DCR;
	volatile	uint32_t	DMAR;
} TIM16_TypeDef;

#if (defined(__cplusplus))
#define	TIM16_S	reinterpret_cast<TIM16_TypeDef *>(0x52004400u)

#else
#define	TIM16_S	((TIM16_TypeDef *)0x52004400u)
#endif

// CR1 Configuration

#define	TIM16_CR1_DITHEN			(0x1u<<12)
#define	TIM16_CR1_UIFREMAP			(0x1u<<11)
#define	TIM16_CR1_CKD				(0x3u<<8)
#define	TIM16_CR1_CKD_0				(0x1u<<8)
#define	TIM16_CR1_ARPE				(0x1u<<7)
#define	TIM16_CR1_OPM				(0x1u<<3)
#define	TIM16_CR1_URS				(0x1u<<2)
#define	TIM16_CR1_UDIS				(0x1u<<1)
#define	TIM16_CR1_CEN				(0x1u<<0)

#define	TIM16_CR1_DITHEN_B_0X0		(0x0u<<12)
#define	TIM16_CR1_DITHEN_B_0X1		(0x1u<<12)
#define	TIM16_CR1_UIFREMAP_B_0X0	(0x0u<<11)
#define	TIM16_CR1_UIFREMAP_B_0X1	(0x1u<<11)
#define	TIM16_CR1_CKD_B_0X0			(0x0u<<8)
#define	TIM16_CR1_CKD_B_0X1			(0x1u<<8)
#define	TIM16_CR1_CKD_B_0X2			(0x2u<<8)
#define	TIM16_CR1_ARPE_B_0X0		(0x0u<<7)
#define	TIM16_CR1_ARPE_B_0X1		(0x1u<<7)
#define	TIM16_CR1_OPM_B_0X0			(0x0u<<3)
#define	TIM16_CR1_OPM_B_0X1			(0x1u<<3)
#define	TIM16_CR1_URS_B_0X0			(0x0u<<2)
#define	TIM16_CR1_URS_B_0X1			(0x1u<<2)
#define	TIM16_CR1_UDIS_B_0X0		(0x0u<<1)
#define	TIM16_CR1_UDIS_B_0X1		(0x1u<<1)
#define	TIM16_CR1_CEN_B_0X0			(0x0u<<0)
#define	TIM16_CR1_CEN_B_0X1			(0x1u<<0)

// CR2 Configuration

#define	TIM16_CR2_OIS1N				(0x1u<<9)
#define	TIM16_CR2_OIS1				(0x1u<<8)
#define	TIM16_CR2_CCDS				(0x1u<<3)
#define	TIM16_CR2_CCUS				(0x1u<<2)
#define	TIM16_CR2_CCPC				(0x1u<<0)

#define	TIM16_CR2_OIS1N_B_0X0		(0x0u<<9)
#define	TIM16_CR2_OIS1N_B_0X1		(0x1u<<9)
#define	TIM16_CR2_OIS1_B_0X0		(0x0u<<8)
#define	TIM16_CR2_OIS1_B_0X1		(0x1u<<8)
#define	TIM16_CR2_CCDS_B_0X0		(0x0u<<3)
#define	TIM16_CR2_CCDS_B_0X1		(0x1u<<3)
#define	TIM16_CR2_CCUS_B_0X0		(0x0u<<2)
#define	TIM16_CR2_CCUS_B_0X1		(0x1u<<2)
#define	TIM16_CR2_CCPC_B_0X0		(0x0u<<0)
#define	TIM16_CR2_CCPC_B_0X1		(0x1u<<0)

// DIER Configuration

#define	TIM16_DIER_CC1DE			(0x1u<<9)
#define	TIM16_DIER_UDE				(0x1u<<8)
#define	TIM16_DIER_BIE				(0x1u<<7)
#define	TIM16_DIER_COMIE			(0x1u<<5)
#define	TIM16_DIER_CC1IE			(0x1u<<1)
#define	TIM16_DIER_UIE				(0x1u<<0)

#define	TIM16_DIER_CC1DE_B_0X0		(0x0u<<9)
#define	TIM16_DIER_CC1DE_B_0X1		(0x1u<<9)
#define	TIM16_DIER_UDE_B_0X0		(0x0u<<8)
#define	TIM16_DIER_UDE_B_0X1		(0x1u<<8)
#define	TIM16_DIER_BIE_B_0X0		(0x0u<<7)
#define	TIM16_DIER_BIE_B_0X1		(0x1u<<7)
#define	TIM16_DIER_COMIE_B_0X0		(0x0u<<5)
#define	TIM16_DIER_COMIE_B_0X1		(0x1u<<5)
#define	TIM16_DIER_CC1IE_B_0X0		(0x0u<<1)
#define	TIM16_DIER_CC1IE_B_0X1		(0x1u<<1)
#define	TIM16_DIER_UIE_B_0X0		(0x0u<<0)
#define	TIM16_DIER_UIE_B_0X1		(0x1u<<0)

// SR Configuration

#define	TIM16_SR_CC1OF				(0x1u<<9)
#define	TIM16_SR_BIF				(0x1u<<7)
#define	TIM16_SR_COMIF				(0x1u<<5)
#define	TIM16_SR_CC1IF				(0x1u<<1)
#define	TIM16_SR_UIF				(0x1u<<0)

#define	TIM16_SR_CC1OF_B_0X0		(0x0u<<9)
#define	TIM16_SR_CC1OF_B_0X1		(0x1u<<9)
#define	TIM16_SR_BIF_B_0X0			(0x0u<<7)
#define	TIM16_SR_BIF_B_0X1			(0x1u<<7)
#define	TIM16_SR_COMIF_B_0X0		(0x0u<<5)
#define	TIM16_SR_COMIF_B_0X1		(0x1u<<5)
#define	TIM16_SR_CC1IF_B_0X0		(0x0u<<1)
#define	TIM16_SR_CC1IF_B_0X1		(0x1u<<1)
#define	TIM16_SR_UIF_B_0X0			(0x0u<<0)
#define	TIM16_SR_UIF_B_0X1			(0x1u<<0)

// EGR Configuration

#define	TIM16_EGR_BG				(0x1u<<7)
#define	TIM16_EGR_COMG				(0x1u<<5)
#define	TIM16_EGR_CC1G				(0x1u<<1)
#define	TIM16_EGR_UG				(0x1u<<0)

#define	TIM16_EGR_BG_B_0X0			(0x0u<<7)
#define	TIM16_EGR_BG_B_0X1			(0x1u<<7)
#define	TIM16_EGR_COMG_B_0X0		(0x0u<<5)
#define	TIM16_EGR_COMG_B_0X1		(0x1u<<5)
#define	TIM16_EGR_CC1G_B_0X0		(0x0u<<1)
#define	TIM16_EGR_CC1G_B_0X1		(0x1u<<1)
#define	TIM16_EGR_UG_B_0X0			(0x0u<<0)
#define	TIM16_EGR_UG_B_0X1			(0x1u<<0)

// CCMR1 Configuration

#define	TIM16_CCMR1_IC1F			(0xFu<<4)
#define	TIM16_CCMR1_IC1F_0			(0x1u<<4)
#define	TIM16_CCMR1_IC1PSC			(0x3u<<2)
#define	TIM16_CCMR1_IC1PSC_0		(0x1u<<2)
#define	TIM16_CCMR1_CC1S			(0x3u<<0)
#define	TIM16_CCMR1_CC1S_0			(0x1u<<0)

#define	TIM16_CCMR1_IC1F_B_0X0		(0x0u<<4)
#define	TIM16_CCMR1_IC1F_B_0X1		(0x1u<<4)
#define	TIM16_CCMR1_IC1F_B_0X2		(0x2u<<4)
#define	TIM16_CCMR1_IC1F_B_0X3		(0x3u<<4)
#define	TIM16_CCMR1_IC1F_B_0X4		(0x4u<<4)
#define	TIM16_CCMR1_IC1F_B_0X5		(0x5u<<4)
#define	TIM16_CCMR1_IC1F_B_0X6		(0x6u<<4)
#define	TIM16_CCMR1_IC1F_B_0X7		(0x7u<<4)
#define	TIM16_CCMR1_IC1F_B_0X8		(0x8u<<4)
#define	TIM16_CCMR1_IC1F_B_0X9		(0x9u<<4)
#define	TIM16_CCMR1_IC1F_B_0XA		(0xAu<<4)
#define	TIM16_CCMR1_IC1F_B_0XB		(0xBu<<4)
#define	TIM16_CCMR1_IC1F_B_0XC		(0xCu<<4)
#define	TIM16_CCMR1_IC1F_B_0XD		(0xDu<<4)
#define	TIM16_CCMR1_IC1F_B_0XE		(0xEu<<4)
#define	TIM16_CCMR1_IC1F_B_0XF		(0xFu<<4)
#define	TIM16_CCMR1_IC1PSC_B_0X0	(0x0u<<2)
#define	TIM16_CCMR1_IC1PSC_B_0X1	(0x1u<<2)
#define	TIM16_CCMR1_IC1PSC_B_0X2	(0x2u<<2)
#define	TIM16_CCMR1_IC1PSC_B_0X3	(0x3u<<2)
#define	TIM16_CCMR1_CC1S_B_0X0		(0x0u<<0)
#define	TIM16_CCMR1_CC1S_B_0X1		(0x1u<<0)

// CCER Configuration

#define	TIM16_CCER_CC1NP			(0x1u<<3)
#define	TIM16_CCER_CC1NE			(0x1u<<2)
#define	TIM16_CCER_CC1P				(0x1u<<1)
#define	TIM16_CCER_CC1E				(0x1u<<0)

#define	TIM16_CCER_CC1NP_B_0X0		(0x0u<<3)
#define	TIM16_CCER_CC1NP_B_0X1		(0x1u<<3)
#define	TIM16_CCER_CC1NE_B_0X0		(0x0u<<2)
#define	TIM16_CCER_CC1NE_B_0X1		(0x1u<<2)
#define	TIM16_CCER_CC1P_B_0X0		(0x0u<<1)
#define	TIM16_CCER_CC1P_B_0X1		(0x1u<<1)
#define	TIM16_CCER_CC1E_B_0X0		(0x0u<<0)
#define	TIM16_CCER_CC1E_B_0X1		(0x1u<<0)

// CNT Configuration

#define	TIM16_CNT_UIFCPY			(0x1u<<31)
#define	TIM16_CNT_CNT				(0xFFFFu<<0)
#define	TIM16_CNT_CNT_0				(0x1u<<0)

// PSC Configuration

#define	TIM16_PSC_PSC				(0xFFFFu<<0)
#define	TIM16_PSC_PSC_0				(0x1u<<0)

// ARR Configuration

#define	TIM16_ARR_ARR				(0xFFFFFu<<0)
#define	TIM16_ARR_ARR_0				(0x1u<<0)

// RCR Configuration

#define	TIM16_RCR_REP				(0xFFu<<0)
#define	TIM16_RCR_REP_0				(0x1u<<0)

// CCR1 Configuration

#define	TIM16_CCR1_CCR1				(0xFFFFFu<<0)
#define	TIM16_CCR1_CCR1_0			(0x1u<<0)

// BDTR Configuration

#define	TIM16_BDTR_BKBID			(0x1u<<28)
#define	TIM16_BDTR_BKDSRM			(0x1u<<26)
#define	TIM16_BDTR_BKF				(0xFu<<16)
#define	TIM16_BDTR_BKF_0			(0x1u<<16)
#define	TIM16_BDTR_MOE				(0x1u<<15)
#define	TIM16_BDTR_AOE				(0x1u<<14)
#define	TIM16_BDTR_BKP				(0x1u<<13)
#define	TIM16_BDTR_BKE				(0x1u<<12)
#define	TIM16_BDTR_OSSR				(0x1u<<11)
#define	TIM16_BDTR_OSSI				(0x1u<<10)
#define	TIM16_BDTR_LOCK				(0x3u<<8)
#define	TIM16_BDTR_LOCK_0			(0x1u<<8)
#define	TIM16_BDTR_DTG				(0xFFu<<0)
#define	TIM16_BDTR_DTG_0			(0x1u<<0)

#define	TIM16_BDTR_BKBID_B_0X0		(0x0u<<28)
#define	TIM16_BDTR_BKBID_B_0X1		(0x1u<<28)
#define	TIM16_BDTR_BKDSRM_B_0X0		(0x0u<<26)
#define	TIM16_BDTR_BKDSRM_B_0X1		(0x1u<<26)
#define	TIM16_BDTR_BKF_B_0X0		(0x0u<<16)
#define	TIM16_BDTR_BKF_B_0X1		(0x1u<<16)
#define	TIM16_BDTR_BKF_B_0X2		(0x2u<<16)
#define	TIM16_BDTR_BKF_B_0X3		(0x3u<<16)
#define	TIM16_BDTR_BKF_B_0X4		(0x4u<<16)
#define	TIM16_BDTR_BKF_B_0X5		(0x5u<<16)
#define	TIM16_BDTR_BKF_B_0X6		(0x6u<<16)
#define	TIM16_BDTR_BKF_B_0X7		(0x7u<<16)
#define	TIM16_BDTR_BKF_B_0X8		(0x8u<<16)
#define	TIM16_BDTR_BKF_B_0X9		(0x9u<<16)
#define	TIM16_BDTR_BKF_B_0XA		(0xAu<<16)
#define	TIM16_BDTR_BKF_B_0XB		(0xBu<<16)
#define	TIM16_BDTR_BKF_B_0XC		(0xCu<<16)
#define	TIM16_BDTR_BKF_B_0XD		(0xDu<<16)
#define	TIM16_BDTR_BKF_B_0XE		(0xEu<<16)
#define	TIM16_BDTR_BKF_B_0XF		(0xFu<<16)
#define	TIM16_BDTR_MOE_B_0X0		(0x0u<<15)
#define	TIM16_BDTR_MOE_B_0X1		(0x1u<<15)
#define	TIM16_BDTR_AOE_B_0X0		(0x0u<<14)
#define	TIM16_BDTR_AOE_B_0X1		(0x1u<<14)
#define	TIM16_BDTR_BKP_B_0X0		(0x0u<<13)
#define	TIM16_BDTR_BKP_B_0X1		(0x1u<<13)
#define	TIM16_BDTR_BKE_B_0X0		(0x0u<<12)
#define	TIM16_BDTR_OSSR_B_0X0		(0x0u<<11)
#define	TIM16_BDTR_OSSR_B_0X1		(0x1u<<11)
#define	TIM16_BDTR_OSSI_B_0X0		(0x0u<<10)
#define	TIM16_BDTR_OSSI_B_0X1		(0x1u<<10)
#define	TIM16_BDTR_LOCK_B_0X0		(0x0u<<8)
#define	TIM16_BDTR_LOCK_B_0X1		(0x1u<<8)
#define	TIM16_BDTR_LOCK_B_0X2		(0x2u<<8)
#define	TIM16_BDTR_LOCK_B_0X3		(0x3u<<8)

// DTR2 Configuration

#define	TIM16_DTR2_DTPE				(0x1u<<17)
#define	TIM16_DTR2_DTAE				(0x1u<<16)
#define	TIM16_DTR2_DTGF				(0xFFu<<0)
#define	TIM16_DTR2_DTGF_0			(0x1u<<0)

#define	TIM16_DTR2_DTPE_B_0X0		(0x0u<<17)
#define	TIM16_DTR2_DTPE_B_0X1		(0x1u<<17)
#define	TIM16_DTR2_DTAE_B_0X0		(0x0u<<16)
#define	TIM16_DTR2_DTAE_B_0X1		(0x1u<<16)

// TISEL Configuration

#define	TIM16_TISEL_TI1SEL			(0xFu<<0)
#define	TIM16_TISEL_TI1SEL_0		(0x1u<<0)

#define	TIM16_TISEL_TI1SEL_B_0X0	(0x0u<<0)
#define	TIM16_TISEL_TI1SEL_B_0X1	(0x1u<<0)
#define	TIM16_TISEL_TI1SEL_B_0XF	(0xFu<<0)

// AF1 Configuration

#define	TIM16_AF1_BKCMP4P			(0x1u<<13)
#define	TIM16_AF1_BKCMP3P			(0x1u<<12)
#define	TIM16_AF1_BKCMP2P			(0x1u<<11)
#define	TIM16_AF1_BKCMP1P			(0x1u<<10)
#define	TIM16_AF1_BKINP				(0x1u<<9)
#define	TIM16_AF1_BKCMP8E			(0x1u<<8)
#define	TIM16_AF1_BKCMP7E			(0x1u<<7)
#define	TIM16_AF1_BKCMP6E			(0x1u<<6)
#define	TIM16_AF1_BKCMP5E			(0x1u<<5)
#define	TIM16_AF1_BKCMP4E			(0x1u<<4)
#define	TIM16_AF1_BKCMP3E			(0x1u<<3)
#define	TIM16_AF1_BKCMP2E			(0x1u<<2)
#define	TIM16_AF1_BKCMP1E			(0x1u<<1)
#define	TIM16_AF1_BKINE				(0x1u<<0)

#define	TIM16_AF1_BKCMP4P_B_0X0		(0x0u<<13)
#define	TIM16_AF1_BKCMP4P_B_0X1		(0x1u<<13)
#define	TIM16_AF1_BKCMP3P_B_0X0		(0x0u<<12)
#define	TIM16_AF1_BKCMP3P_B_0X1		(0x1u<<12)
#define	TIM16_AF1_BKCMP2P_B_0X0		(0x0u<<11)
#define	TIM16_AF1_BKCMP2P_B_0X1		(0x1u<<11)
#define	TIM16_AF1_BKCMP1P_B_0X0		(0x0u<<10)
#define	TIM16_AF1_BKCMP1P_B_0X1		(0x1u<<10)
#define	TIM16_AF1_BKINP_B_0X0		(0x0u<<9)
#define	TIM16_AF1_BKINP_B_0X1		(0x1u<<9)
#define	TIM16_AF1_BKCMP8E_B_0X0		(0x0u<<8)
#define	TIM16_AF1_BKCMP8E_B_0X1		(0x1u<<8)
#define	TIM16_AF1_BKCMP7E_B_0X0		(0x0u<<7)
#define	TIM16_AF1_BKCMP7E_B_0X1		(0x1u<<7)
#define	TIM16_AF1_BKCMP6E_B_0X0		(0x0u<<6)
#define	TIM16_AF1_BKCMP6E_B_0X1		(0x1u<<6)
#define	TIM16_AF1_BKCMP5E_B_0X0		(0x0u<<5)
#define	TIM16_AF1_BKCMP5E_B_0X1		(0x1u<<5)
#define	TIM16_AF1_BKCMP4E_B_0X0		(0x0u<<4)
#define	TIM16_AF1_BKCMP4E_B_0X1		(0x1u<<4)
#define	TIM16_AF1_BKCMP3E_B_0X0		(0x0u<<3)
#define	TIM16_AF1_BKCMP3E_B_0X1		(0x1u<<3)
#define	TIM16_AF1_BKCMP2E_B_0X0		(0x0u<<2)
#define	TIM16_AF1_BKCMP2E_B_0X1		(0x1u<<2)
#define	TIM16_AF1_BKCMP1E_B_0X0		(0x0u<<1)
#define	TIM16_AF1_BKCMP1E_B_0X1		(0x1u<<1)
#define	TIM16_AF1_BKINE_B_0X0		(0x0u<<0)
#define	TIM16_AF1_BKINE_B_0X1		(0x1u<<0)

// AF2 Configuration

#define	TIM16_AF2_OCRSEL			(0x7u<<16)
#define	TIM16_AF2_OCRSEL_0			(0x1u<<16)

#define	TIM16_AF2_OCRSEL_B_0X0		(0x0u<<16)
#define	TIM16_AF2_OCRSEL_B_0X1		(0x1u<<16)
#define	TIM16_AF2_OCRSEL_B_0X2		(0x2u<<16)
#define	TIM16_AF2_OCRSEL_B_0X3		(0x3u<<16)
#define	TIM16_AF2_OCRSEL_B_0X4		(0x4u<<16)
#define	TIM16_AF2_OCRSEL_B_0X5		(0x5u<<16)
#define	TIM16_AF2_OCRSEL_B_0X6		(0x6u<<16)
#define	TIM16_AF2_OCRSEL_B_0X7		(0x7u<<16)

// DCR Configuration

#define	TIM16_DCR_DBSS				(0xFu<<16)
#define	TIM16_DCR_DBSS_0			(0x1u<<16)
#define	TIM16_DCR_DBL				(0x1Fu<<8)
#define	TIM16_DCR_DBL_0				(0x1u<<8)
#define	TIM16_DCR_DBA				(0x1Fu<<0)
#define	TIM16_DCR_DBA_0				(0x1u<<0)

#define	TIM16_DCR_DBSS_B_0X1		(0x1u<<16)
#define	TIM16_DCR_DBSS_B_0X2		(0x2u<<16)
#define	TIM16_DCR_DBL_B_0X0			(0x0u<<8)
#define	TIM16_DCR_DBL_B_0X1			(0x1u<<8)
#define	TIM16_DCR_DBL_B_0X2			(0x2u<<8)
#define	TIM16_DCR_DBL_B_0X11		(0x11u<<8)
#define	TIM16_DCR_DBA_B_0X0			(0x0u<<0)
#define	TIM16_DCR_DBA_B_0X1			(0x1u<<0)
#define	TIM16_DCR_DBA_B_0X2			(0x2u<<0)

// DMAR Configuration

#define	TIM16_DMAR_DMAB				(0xFFFFFFFFu<<0)
#define	TIM16_DMAR_DMAB_0			(0x1u<<0)
