/*
; stm32N657_lptim.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_lptim equates.
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
	volatile	uint32_t	DIER;
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
} LPTIM_TypeDef;

#if (defined(__cplusplus))
#define	LPTIM1_NS	reinterpret_cast<LPTIM_TypeDef *>(0x40002400u)
#define	LPTIM1_S	reinterpret_cast<LPTIM_TypeDef *>(0x50002400u)
#define	LPTIM2_NS	reinterpret_cast<LPTIM_TypeDef *>(0x46002400u)
#define	LPTIM2_S	reinterpret_cast<LPTIM_TypeDef *>(0x56002400u)
#define	LPTIM3_NS	reinterpret_cast<LPTIM_TypeDef *>(0x46002800u)
#define	LPTIM3_S	reinterpret_cast<LPTIM_TypeDef *>(0x56002800u)
#define	LPTIM4_NS	reinterpret_cast<LPTIM_TypeDef *>(0x46002C00u)
#define	LPTIM4_S	reinterpret_cast<LPTIM_TypeDef *>(0x56002C00u)
#define	LPTIM5_NS	reinterpret_cast<LPTIM_TypeDef *>(0x46003000u)
#define	LPTIM5_S	reinterpret_cast<LPTIM_TypeDef *>(0x56003000u)

#else
#define	LPTIM1_NS	((LPTIM_TypeDef *)0x40002400u)
#define	LPTIM1_S	((LPTIM_TypeDef *)0x50002400u)
#define	LPTIM2_NS	((LPTIM_TypeDef *)0x46002400u)
#define	LPTIM2_S	((LPTIM_TypeDef *)0x56002400u)
#define	LPTIM3_NS	((LPTIM_TypeDef *)0x46002800u)
#define	LPTIM3_S	((LPTIM_TypeDef *)0x56002800u)
#define	LPTIM4_NS	((LPTIM_TypeDef *)0x46002C00u)
#define	LPTIM4_S	((LPTIM_TypeDef *)0x56002C00u)
#define	LPTIM5_NS	((LPTIM_TypeDef *)0x46003000u)
#define	LPTIM5_S	((LPTIM_TypeDef *)0x56003000u)
#endif

// ISR Configuration

#define	LPTIM_ISR_DIEROK						(0x1u<<24)
#define	LPTIM_ISR_CMP2OK						(0x1u<<19)
#define	LPTIM_ISR_CC2IF							(0x1u<<9)
#define	LPTIM_ISR_REPOK							(0x1u<<8)
#define	LPTIM_ISR_UE							(0x1u<<7)
#define	LPTIM_ISR_DOWN							(0x1u<<6)
#define	LPTIM_ISR_UP							(0x1u<<5)
#define	LPTIM_ISR_ARROK							(0x1u<<4)
#define	LPTIM_ISR_CMP1OK						(0x1u<<3)
#define	LPTIM_ISR_EXTTRIG						(0x1u<<2)
#define	LPTIM_ISR_ARRM							(0x1u<<1)
#define	LPTIM_ISR_CC1IF							(0x1u<<0)

#define	LPTIM_ISR_CC2IF_B_0X0					(0x0u<<9)
#define	LPTIM_ISR_CC2IF_B_0X1					(0x1u<<9)
#define	LPTIM_ISR_CC1IF_B_0X0					(0x0u<<0)
#define	LPTIM_ISR_CC1IF_B_0X1					(0x1u<<0)

// ICR Configuration

#define	LPTIM_ICR_DIEROKCF						(0x1u<<24)
#define	LPTIM_ICR_CMP2OKCF						(0x1u<<19)
#define	LPTIM_ICR_CC2CF							(0x1u<<9)
#define	LPTIM_ICR_REPOKCF						(0x1u<<8)
#define	LPTIM_ICR_UECF							(0x1u<<7)
#define	LPTIM_ICR_DOWNCF						(0x1u<<6)
#define	LPTIM_ICR_UPCF							(0x1u<<5)
#define	LPTIM_ICR_ARROKCF						(0x1u<<4)
#define	LPTIM_ICR_CMP1OKCF						(0x1u<<3)
#define	LPTIM_ICR_EXTTRIGCF						(0x1u<<2)
#define	LPTIM_ICR_ARRMCF						(0x1u<<1)
#define	LPTIM_ICR_CC1CF							(0x1u<<0)

// DIER Configuration

#define	LPTIM_DIER_UEDE							(0x1u<<23)
#define	LPTIM_DIER_CMP2OKIE						(0x1u<<19)
#define	LPTIM_DIER_CC2IE						(0x1u<<9)
#define	LPTIM_DIER_REPOKIE						(0x1u<<8)
#define	LPTIM_DIER_UEIE							(0x1u<<7)
#define	LPTIM_DIER_DOWNIE						(0x1u<<6)
#define	LPTIM_DIER_UPIE							(0x1u<<5)
#define	LPTIM_DIER_ARROKIE						(0x1u<<4)
#define	LPTIM_DIER_CMP1OKIE						(0x1u<<3)
#define	LPTIM_DIER_EXTTRIGIE					(0x1u<<2)
#define	LPTIM_DIER_ARRMIE						(0x1u<<1)
#define	LPTIM_DIER_CC1IE						(0x1u<<0)

#define	LPTIM_DIER_UEDE_B_0X0					(0x0u<<23)
#define	LPTIM_DIER_UEDE_B_0X1					(0x1u<<23)
#define	LPTIM_DIER_CMP2OKIE_B_0X0				(0x0u<<19)
#define	LPTIM_DIER_CMP2OKIE_B_0X1				(0x1u<<19)
#define	LPTIM_DIER_CC2IE_B_0X0					(0x0u<<9)
#define	LPTIM_DIER_CC2IE_B_0X1					(0x1u<<9)
#define	LPTIM_DIER_REPOKIE_B_0X0				(0x0u<<8)
#define	LPTIM_DIER_REPOKIE_B_0X1				(0x1u<<8)
#define	LPTIM_DIER_UEIE_B_0X0					(0x0u<<7)
#define	LPTIM_DIER_UEIE_B_0X1					(0x1u<<7)
#define	LPTIM_DIER_DOWNIE_B_0X0					(0x0u<<6)
#define	LPTIM_DIER_DOWNIE_B_0X1					(0x1u<<6)
#define	LPTIM_DIER_UPIE_B_0X0					(0x0u<<5)
#define	LPTIM_DIER_UPIE_B_0X1					(0x1u<<5)
#define	LPTIM_DIER_ARROKIE_B_0X0				(0x0u<<4)
#define	LPTIM_DIER_ARROKIE_B_0X1				(0x1u<<4)
#define	LPTIM_DIER_CMP1OKIE_B_0X0				(0x0u<<3)
#define	LPTIM_DIER_CMP1OKIE_B_0X1				(0x1u<<3)
#define	LPTIM_DIER_EXTTRIGIE_B_0X0				(0x0u<<2)
#define	LPTIM_DIER_EXTTRIGIE_B_0X1				(0x1u<<2)
#define	LPTIM_DIER_ARRMIE_B_0X0					(0x0u<<1)
#define	LPTIM_DIER_ARRMIE_B_0X1					(0x1u<<1)
#define	LPTIM_DIER_CC1IE_B_0X0					(0x0u<<0)
#define	LPTIM_DIER_CC1IE_B_0X1					(0x1u<<0)

// CFGR Configuration

#define	LPTIM_CFGR_ENC							(0x1u<<24)
#define	LPTIM_CFGR_COUNTMODE					(0x1u<<23)
#define	LPTIM_CFGR_PRELOAD						(0x1u<<22)
#define	LPTIM_CFGR_WAVPOL						(0x1u<<21)
#define	LPTIM_CFGR_WAVE							(0x1u<<20)
#define	LPTIM_CFGR_TIMOUT						(0x1u<<19)
#define	LPTIM_CFGR_TRIGEN						(0x3u<<17)
#define	LPTIM_CFGR_TRIGEN_0						(0x1u<<17)
#define	LPTIM_CFGR_TRIGSEL						(0x7u<<13)
#define	LPTIM_CFGR_TRIGSEL_0					(0x1u<<13)
#define	LPTIM_CFGR_PRESC						(0x7u<<9)
#define	LPTIM_CFGR_PRESC_0						(0x1u<<9)
#define	LPTIM_CFGR_TRGFLT						(0x3u<<6)
#define	LPTIM_CFGR_TRGFLT_0						(0x1u<<6)
#define	LPTIM_CFGR_CKFLT						(0x3u<<3)
#define	LPTIM_CFGR_CKFLT_0						(0x1u<<3)
#define	LPTIM_CFGR_CKPOL						(0x3u<<1)
#define	LPTIM_CFGR_CKPOL_0						(0x1u<<1)
#define	LPTIM_CFGR_CKSEL						(0x1u<<0)

#define	LPTIM_CFGR_ENC_B_0X0					(0x0u<<24)
#define	LPTIM_CFGR_ENC_B_0X1					(0x1u<<24)
#define	LPTIM_CFGR_COUNTMODE_B_0X0				(0x0u<<23)
#define	LPTIM_CFGR_COUNTMODE_B_0X1				(0x1u<<23)
#define	LPTIM_CFGR_PRELOAD_B_0X0				(0x0u<<22)
#define	LPTIM_CFGR_PRELOAD_B_0X1				(0x1u<<22)
#define	LPTIM_CFGR_WAVPOL_B_0X0					(0x0u<<21)
#define	LPTIM_CFGR_WAVPOL_B_0X1					(0x1u<<21)
#define	LPTIM_CFGR_WAVE_B_0X0					(0x0u<<20)
#define	LPTIM_CFGR_WAVE_B_0X1					(0x1u<<20)
#define	LPTIM_CFGR_TIMOUT_B_0X0					(0x0u<<19)
#define	LPTIM_CFGR_TIMOUT_B_0X1					(0x1u<<19)
#define	LPTIM_CFGR_TRIGEN_B_0X0					(0x0u<<17)
#define	LPTIM_CFGR_TRIGEN_B_0X1					(0x1u<<17)
#define	LPTIM_CFGR_TRIGEN_B_0X2					(0x2u<<17)
#define	LPTIM_CFGR_TRIGEN_B_0X3					(0x3u<<17)
#define	LPTIM_CFGR_TRIGSEL_B_0X0				(0x0u<<13)
#define	LPTIM_CFGR_TRIGSEL_B_0X1				(0x1u<<13)
#define	LPTIM_CFGR_TRIGSEL_B_0X2				(0x2u<<13)
#define	LPTIM_CFGR_TRIGSEL_B_0X3				(0x3u<<13)
#define	LPTIM_CFGR_TRIGSEL_B_0X4				(0x4u<<13)
#define	LPTIM_CFGR_TRIGSEL_B_0X5				(0x5u<<13)
#define	LPTIM_CFGR_TRIGSEL_B_0X6				(0x6u<<13)
#define	LPTIM_CFGR_TRIGSEL_B_0X7				(0x7u<<13)
#define	LPTIM_CFGR_PRESC_B_0X0					(0x0u<<9)
#define	LPTIM_CFGR_PRESC_B_0X1					(0x1u<<9)
#define	LPTIM_CFGR_PRESC_B_0X2					(0x2u<<9)
#define	LPTIM_CFGR_PRESC_B_0X3					(0x3u<<9)
#define	LPTIM_CFGR_PRESC_B_0X4					(0x4u<<9)
#define	LPTIM_CFGR_PRESC_B_0X5					(0x5u<<9)
#define	LPTIM_CFGR_PRESC_B_0X6					(0x6u<<9)
#define	LPTIM_CFGR_PRESC_B_0X7					(0x7u<<9)
#define	LPTIM_CFGR_TRGFLT_B_0X0					(0x0u<<6)
#define	LPTIM_CFGR_TRGFLT_B_0X1					(0x1u<<6)
#define	LPTIM_CFGR_TRGFLT_B_0X2					(0x2u<<6)
#define	LPTIM_CFGR_TRGFLT_B_0X3					(0x3u<<6)
#define	LPTIM_CFGR_CKFLT_B_0X0					(0x0u<<3)
#define	LPTIM_CFGR_CKFLT_B_0X1					(0x1u<<3)
#define	LPTIM_CFGR_CKFLT_B_0X2					(0x2u<<3)
#define	LPTIM_CFGR_CKFLT_B_0X3					(0x3u<<3)
#define	LPTIM_CFGR_CKPOL_B_0X0					(0x0u<<1)
#define	LPTIM_CFGR_CKPOL_B_0X1					(0x1u<<1)
#define	LPTIM_CFGR_CKPOL_B_0X2					(0x2u<<1)
#define	LPTIM_CFGR_CKPOL_B_0X3					(0x3u<<1)
#define	LPTIM_CFGR_CKSEL_B_0X0					(0x0u<<0)
#define	LPTIM_CFGR_CKSEL_B_0X1					(0x1u<<0)

// CR Configuration

#define	LPTIM_CR_RSTARE							(0x1u<<4)
#define	LPTIM_CR_COUNTRST						(0x1u<<3)
#define	LPTIM_CR_CNTSTRT						(0x1u<<2)
#define	LPTIM_CR_SNGSTRT						(0x1u<<1)
#define	LPTIM_CR_ENABLE							(0x1u<<0)

#define	LPTIM_CR_ENABLE_B_0X0					(0x0u<<0)
#define	LPTIM_CR_ENABLE_B_0X1					(0x1u<<0)

// CCR1 Configuration

#define	LPTIM_CCR1_CCR1							(0xFFFFu<<0)
#define	LPTIM_CCR1_CCR1_0						(0x1u<<0)

// ARR Configuration

#define	LPTIM_ARR_ARR							(0xFFFFu<<0)
#define	LPTIM_ARR_ARR_0							(0x1u<<0)

// CNT Configuration

#define	LPTIM_CNT_CNT							(0xFFFFu<<0)
#define	LPTIM_CNT_CNT_0							(0x1u<<0)

// CFGR2 Configuration

#define	LPTIM_CFGR2_IC2SEL						(0x3u<<20)
#define	LPTIM_CFGR2_IC2SEL_0					(0x1u<<20)
#define	LPTIM_CFGR2_IC1SEL						(0x3u<<16)
#define	LPTIM_CFGR2_IC1SEL_0					(0x1u<<16)
#define	LPTIM_CFGR2_IN2SEL						(0x3u<<4)
#define	LPTIM_CFGR2_IN2SEL_0					(0x1u<<4)
#define	LPTIM_CFGR2_IN1SEL						(0x3u<<0)
#define	LPTIM_CFGR2_IN1SEL_0					(0x1u<<0)

#define	LPTIM_CFGR2_IC2SEL_B_0X0				(0x0u<<20)
#define	LPTIM_CFGR2_IC2SEL_B_0X1				(0x1u<<20)
#define	LPTIM_CFGR2_IC2SEL_B_0X2				(0x2u<<20)
#define	LPTIM_CFGR2_IC2SEL_B_0X3				(0x3u<<20)
#define	LPTIM_CFGR2_IC1SEL_B_0X0				(0x0u<<16)
#define	LPTIM_CFGR2_IC1SEL_B_0X1				(0x1u<<16)
#define	LPTIM_CFGR2_IC1SEL_B_0X2				(0x2u<<16)
#define	LPTIM_CFGR2_IC1SEL_B_0X3				(0x3u<<16)
#define	LPTIM_CFGR2_IN2SEL_B_0X0				(0x0u<<4)
#define	LPTIM_CFGR2_IN2SEL_B_0X1				(0x1u<<4)
#define	LPTIM_CFGR2_IN2SEL_B_0X2				(0x2u<<4)
#define	LPTIM_CFGR2_IN2SEL_B_0X3				(0x3u<<4)
#define	LPTIM_CFGR2_IN1SEL_B_0X0				(0x0u<<0)
#define	LPTIM_CFGR2_IN1SEL_B_0X1				(0x1u<<0)
#define	LPTIM_CFGR2_IN1SEL_B_0X2				(0x2u<<0)
#define	LPTIM_CFGR2_IN1SEL_B_0X3				(0x3u<<0)

// RCR Configuration

#define	LPTIM_RCR_REP							(0xFFu<<0)
#define	LPTIM_RCR_REP_0							(0x1u<<0)

// CCMR1 Configuration

#define	LPTIM_CCMR1_IC2F						(0x3u<<28)
#define	LPTIM_CCMR1_IC2F_0						(0x1u<<28)
#define	LPTIM_CCMR1_IC2PSC						(0x3u<<24)
#define	LPTIM_CCMR1_IC2PSC_0					(0x1u<<24)
#define	LPTIM_CCMR1_CC2P						(0x3u<<18)
#define	LPTIM_CCMR1_CC2P_0						(0x1u<<18)
#define	LPTIM_CCMR1_CC2E						(0x1u<<17)
#define	LPTIM_CCMR1_CC2SEL						(0x1u<<16)
#define	LPTIM_CCMR1_IC1F						(0x3u<<12)
#define	LPTIM_CCMR1_IC1F_0						(0x1u<<12)
#define	LPTIM_CCMR1_IC1PSC						(0x3u<<8)
#define	LPTIM_CCMR1_IC1PSC_0					(0x1u<<8)
#define	LPTIM_CCMR1_CC1P						(0x3u<<2)
#define	LPTIM_CCMR1_CC1P_0						(0x1u<<2)
#define	LPTIM_CCMR1_CC1E						(0x1u<<1)
#define	LPTIM_CCMR1_CC1SEL						(0x1u<<0)

#define	LPTIM_CCMR1_IC2F_B_0X0					(0x0u<<28)
#define	LPTIM_CCMR1_IC2F_B_0X1					(0x1u<<28)
#define	LPTIM_CCMR1_IC2F_B_0X2					(0x2u<<28)
#define	LPTIM_CCMR1_IC2F_B_0X3					(0x3u<<28)
#define	LPTIM_CCMR1_IC2PSC_B_0X0				(0x0u<<24)
#define	LPTIM_CCMR1_IC2PSC_B_0X1				(0x1u<<24)
#define	LPTIM_CCMR1_IC2PSC_B_0X2				(0x2u<<24)
#define	LPTIM_CCMR1_IC2PSC_B_0X3				(0x3u<<24)
#define	LPTIM_CCMR1_CC2P_B_0X0_CC2_AS_OUTPUT	(0x0u<<18)
#define	LPTIM_CCMR1_CC2P_B_0X1_CC2_AS_OUTPUT	(0x1u<<18)
#define	LPTIM_CCMR1_CC2P_B_0X3_CC2_AS_INPUT		(0x3u<<18)
#define	LPTIM_CCMR1_CC2E_B_0X0_CC2_AS_OUTPUT	(0x0u<<17)
#define	LPTIM_CCMR1_CC2E_B_0X1_CC2_AS_OUTPUT	(0x1u<<17)
#define	LPTIM_CCMR1_CC2SEL_B_0X0				(0x0u<<16)
#define	LPTIM_CCMR1_CC2SEL_B_0X1				(0x1u<<16)
#define	LPTIM_CCMR1_IC1F_B_0X0					(0x0u<<12)
#define	LPTIM_CCMR1_IC1F_B_0X1					(0x1u<<12)
#define	LPTIM_CCMR1_IC1F_B_0X2					(0x2u<<12)
#define	LPTIM_CCMR1_IC1F_B_0X3					(0x3u<<12)
#define	LPTIM_CCMR1_IC1PSC_B_0X0				(0x0u<<8)
#define	LPTIM_CCMR1_IC1PSC_B_0X1				(0x1u<<8)
#define	LPTIM_CCMR1_IC1PSC_B_0X2				(0x2u<<8)
#define	LPTIM_CCMR1_IC1PSC_B_0X3				(0x3u<<8)
#define	LPTIM_CCMR1_CC1P_B_0X0_CC1_AS_OUTPUT	(0x0u<<2)
#define	LPTIM_CCMR1_CC1P_B_0X1_CC1_AS_OUTPUT	(0x1u<<2)
#define	LPTIM_CCMR1_CC1P_B_0X3_CC1_AS_INPUT		(0x3u<<2)
#define	LPTIM_CCMR1_CC1E_B_0X0_CC1_AS_OUTPUT	(0x0u<<1)
#define	LPTIM_CCMR1_CC1E_B_0X1_CC1_AS_OUTPUT	(0x1u<<1)
#define	LPTIM_CCMR1_CC1SEL_B_0X0				(0x0u<<0)
#define	LPTIM_CCMR1_CC1SEL_B_0X1				(0x1u<<0)

// CCR2 Configuration

#define	LPTIM_CCR2_CCR2							(0xFFFFu<<0)
#define	LPTIM_CCR2_CCR2_0						(0x1u<<0)
