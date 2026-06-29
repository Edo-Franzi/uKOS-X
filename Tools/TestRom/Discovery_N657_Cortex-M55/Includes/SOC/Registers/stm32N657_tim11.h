/*
; stm32N657_tim11.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_tim11 equates.
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

// TIM11 address definitions
// -------------------------

typedef struct {
	volatile	uint16_t	CR1;
	volatile	uint16_t	RESERVED0[5];
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
	volatile	uint32_t	RESERVED8[9];
	volatile	uint16_t	TISEL;
} TIM11_TypeDef;

#if (defined(__cplusplus))
#define	TIM11_NS	reinterpret_cast<TIM11_TypeDef *>(0x40003400u)
#define	TIM11_S		reinterpret_cast<TIM11_TypeDef *>(0x50003400u)

#else
#define	TIM11_NS	((TIM11_TypeDef *)0x40003400u)
#define	TIM11_S		((TIM11_TypeDef *)0x50003400u)
#endif

// CR1 Configuration

#define	TIM11_CR1_DITHEN			(0x1u<<12)
#define	TIM11_CR1_UIFREMAP			(0x1u<<11)
#define	TIM11_CR1_CKD				(0x3u<<8)
#define	TIM11_CR1_CKD_0				(0x1u<<8)
#define	TIM11_CR1_ARPE				(0x1u<<7)
#define	TIM11_CR1_OPM				(0x1u<<3)
#define	TIM11_CR1_URS				(0x1u<<2)
#define	TIM11_CR1_UDIS				(0x1u<<1)
#define	TIM11_CR1_CEN				(0x1u<<0)

#define	TIM11_CR1_DITHEN_B_0X0		(0x0u<<12)
#define	TIM11_CR1_DITHEN_B_0X1		(0x1u<<12)
#define	TIM11_CR1_UIFREMAP_B_0X0	(0x0u<<11)
#define	TIM11_CR1_UIFREMAP_B_0X1	(0x1u<<11)
#define	TIM11_CR1_CKD_B_0X0			(0x0u<<8)
#define	TIM11_CR1_CKD_B_0X1			(0x1u<<8)
#define	TIM11_CR1_CKD_B_0X2			(0x2u<<8)
#define	TIM11_CR1_ARPE_B_0X0		(0x0u<<7)
#define	TIM11_CR1_ARPE_B_0X1		(0x1u<<7)
#define	TIM11_CR1_OPM_B_0X0			(0x0u<<3)
#define	TIM11_CR1_OPM_B_0X1			(0x1u<<3)
#define	TIM11_CR1_URS_B_0X0			(0x0u<<2)
#define	TIM11_CR1_URS_B_0X1			(0x1u<<2)
#define	TIM11_CR1_UDIS_B_0X0		(0x0u<<1)
#define	TIM11_CR1_UDIS_B_0X1		(0x1u<<1)
#define	TIM11_CR1_CEN_B_0X0			(0x0u<<0)
#define	TIM11_CR1_CEN_B_0X1			(0x1u<<0)

// DIER Configuration

#define	TIM11_DIER_CC1IE			(0x1u<<1)
#define	TIM11_DIER_UIE				(0x1u<<0)

#define	TIM11_DIER_CC1IE_B_0X0		(0x0u<<1)
#define	TIM11_DIER_CC1IE_B_0X1		(0x1u<<1)
#define	TIM11_DIER_UIE_B_0X0		(0x0u<<0)
#define	TIM11_DIER_UIE_B_0X1		(0x1u<<0)

// SR Configuration

#define	TIM11_SR_CC1OF				(0x1u<<9)
#define	TIM11_SR_CC1IF				(0x1u<<1)
#define	TIM11_SR_UIF				(0x1u<<0)

#define	TIM11_SR_CC1OF_B_0X0		(0x0u<<9)
#define	TIM11_SR_CC1OF_B_0X1		(0x1u<<9)
#define	TIM11_SR_CC1IF_B_0X0		(0x0u<<1)
#define	TIM11_SR_CC1IF_B_0X1		(0x1u<<1)
#define	TIM11_SR_UIF_B_0X0			(0x0u<<0)
#define	TIM11_SR_UIF_B_0X1			(0x1u<<0)

// EGR Configuration

#define	TIM11_EGR_CC1G				(0x1u<<1)
#define	TIM11_EGR_UG				(0x1u<<0)

#define	TIM11_EGR_CC1G_B_0X0		(0x0u<<1)
#define	TIM11_EGR_CC1G_B_0X1		(0x1u<<1)
#define	TIM11_EGR_UG_B_0X0			(0x0u<<0)
#define	TIM11_EGR_UG_B_0X1			(0x1u<<0)

// CCMR1 Configuration

#define	TIM11_CCMR1_IC1F			(0xFu<<4)
#define	TIM11_CCMR1_IC1F_0			(0x1u<<4)
#define	TIM11_CCMR1_IC1PSC			(0x3u<<2)
#define	TIM11_CCMR1_IC1PSC_0		(0x1u<<2)
#define	TIM11_CCMR1_CC1S			(0x3u<<0)
#define	TIM11_CCMR1_CC1S_0			(0x1u<<0)

#define	TIM11_CCMR1_IC1F_B_0X0		(0x0u<<4)
#define	TIM11_CCMR1_IC1F_B_0X1		(0x1u<<4)
#define	TIM11_CCMR1_IC1F_B_0X2		(0x2u<<4)
#define	TIM11_CCMR1_IC1F_B_0X3		(0x3u<<4)
#define	TIM11_CCMR1_IC1F_B_0X4		(0x4u<<4)
#define	TIM11_CCMR1_IC1F_B_0X5		(0x5u<<4)
#define	TIM11_CCMR1_IC1F_B_0X6		(0x6u<<4)
#define	TIM11_CCMR1_IC1F_B_0X7		(0x7u<<4)
#define	TIM11_CCMR1_IC1F_B_0X8		(0x8u<<4)
#define	TIM11_CCMR1_IC1F_B_0X9		(0x9u<<4)
#define	TIM11_CCMR1_IC1F_B_0XA		(0xAu<<4)
#define	TIM11_CCMR1_IC1F_B_0XB		(0xBu<<4)
#define	TIM11_CCMR1_IC1F_B_0XC		(0xCu<<4)
#define	TIM11_CCMR1_IC1F_B_0XD		(0xDu<<4)
#define	TIM11_CCMR1_IC1F_B_0XE		(0xEu<<4)
#define	TIM11_CCMR1_IC1F_B_0XF		(0xFu<<4)
#define	TIM11_CCMR1_IC1PSC_B_0X0	(0x0u<<2)
#define	TIM11_CCMR1_IC1PSC_B_0X1	(0x1u<<2)
#define	TIM11_CCMR1_IC1PSC_B_0X2	(0x2u<<2)
#define	TIM11_CCMR1_IC1PSC_B_0X3	(0x3u<<2)
#define	TIM11_CCMR1_CC1S_B_0X0		(0x0u<<0)
#define	TIM11_CCMR1_CC1S_B_0X1		(0x1u<<0)

// CCER Configuration

#define	TIM11_CCER_CC1NP			(0x1u<<3)
#define	TIM11_CCER_CC1P				(0x1u<<1)
#define	TIM11_CCER_CC1E				(0x1u<<0)

#define	TIM11_CCER_CC1P_B_0X0		(0x0u<<1)
#define	TIM11_CCER_CC1P_B_0X1		(0x1u<<1)
#define	TIM11_CCER_CC1E_B_0X0		(0x0u<<0)
#define	TIM11_CCER_CC1E_B_0X1		(0x1u<<0)

// CNT Configuration

#define	TIM11_CNT_UIFCPY			(0x1u<<31)
#define	TIM11_CNT_CNT				(0xFFFFu<<0)
#define	TIM11_CNT_CNT_0				(0x1u<<0)

// PSC Configuration

#define	TIM11_PSC_PSC				(0xFFFFu<<0)
#define	TIM11_PSC_PSC_0				(0x1u<<0)

// ARR Configuration

#define	TIM11_ARR_ARR				(0xFFFFFu<<0)
#define	TIM11_ARR_ARR_0				(0x1u<<0)

// CCR1 Configuration

#define	TIM11_CCR1_CCR1				(0xFFFFFu<<0)
#define	TIM11_CCR1_CCR1_0			(0x1u<<0)

// TISEL Configuration

#define	TIM11_TISEL_TI1SEL			(0xFu<<0)
#define	TIM11_TISEL_TI1SEL_0		(0x1u<<0)

#define	TIM11_TISEL_TI1SEL_B_0X0	(0x0u<<0)
#define	TIM11_TISEL_TI1SEL_B_0X1	(0x1u<<0)
#define	TIM11_TISEL_TI1SEL_B_0XF	(0xFu<<0)
