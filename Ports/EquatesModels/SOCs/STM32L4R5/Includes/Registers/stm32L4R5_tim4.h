/*
; stm32L4R5_tim4.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_tim4 equates.
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

// TIM4 address definitions
// ------------------------

typedef struct {
	volatile	uint16_t	CR1;
	volatile	uint16_t	RESERVED0;
	volatile	uint16_t	CR2;
	volatile	uint16_t	RESERVED1;
	volatile	uint32_t	SMCR;
	volatile	uint16_t	DIER;
	volatile	uint16_t	RESERVED2;
	volatile	uint16_t	SR;
	volatile	uint16_t	RESERVED3;
	volatile	uint16_t	EGR;
	volatile	uint16_t	RESERVED4;
		union {
	volatile	uint32_t	CCMR1;
	volatile	uint32_t	CCMR1_ALTERNATE;
		};
		union {
	volatile	uint32_t	CCMR2;
	volatile	uint32_t	CCMR2_ALTERNATE;
		};
	volatile	uint16_t	CCER;
	volatile	uint16_t	RESERVED5;
		union {
	volatile	uint32_t	CNT;
	volatile	uint32_t	CNT_ALTERNATE;
		};
	volatile	uint16_t	PSC;
	volatile	uint16_t	RESERVED6;
	volatile	uint32_t	ARR;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	CCR1;
	volatile	uint32_t	CCR2;
	volatile	uint32_t	CCR3;
	volatile	uint32_t	CCR4;
	volatile	uint32_t	RESERVED8;
	volatile	uint16_t	DCR;
	volatile	uint16_t	RESERVED9;
	volatile	uint16_t	DMAR;
	volatile	uint16_t	RESERVED10[9];
	volatile	uint32_t	AF1;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	TISEL;
} TIM4_TypeDef;

#if (defined(__cplusplus))
#define	TIM4	reinterpret_cast<TIM4_TypeDef *>(0x40000800u)

#else
#define	TIM4	((TIM4_TypeDef *)0x40000800u)
#endif

// CR1 Configuration

#define	TIM4_CR1_UIFREMAP					(0x1u<<11)
#define	TIM4_CR1_CKD						(0x3u<<8)
#define	TIM4_CR1_CKD_0						(0x1u<<8)
#define	TIM4_CR1_ARPE						(0x1u<<7)
#define	TIM4_CR1_CMS						(0x3u<<5)
#define	TIM4_CR1_CMS_0						(0x1u<<5)
#define	TIM4_CR1_DIR						(0x1u<<4)
#define	TIM4_CR1_OPM						(0x1u<<3)
#define	TIM4_CR1_URS						(0x1u<<2)
#define	TIM4_CR1_UDIS						(0x1u<<1)
#define	TIM4_CR1_CEN						(0x1u<<0)
#define	TIM4_CR1_UIFREMAP_B_0X0				(0x0u<<11)
#define	TIM4_CR1_UIFREMAP_B_0X1				(0x1u<<11)
#define	TIM4_CR1_CKD_B_0X0					(0x0u<<8)
#define	TIM4_CR1_CKD_B_0X1					(0x1u<<8)
#define	TIM4_CR1_CKD_B_0X2					(0x2u<<8)
#define	TIM4_CR1_ARPE_B_0X0					(0x0u<<7)
#define	TIM4_CR1_ARPE_B_0X1					(0x1u<<7)
#define	TIM4_CR1_CMS_B_0X0					(0x0u<<5)
#define	TIM4_CR1_CMS_B_0X1					(0x1u<<5)
#define	TIM4_CR1_CMS_B_0X2					(0x2u<<5)
#define	TIM4_CR1_CMS_B_0X3					(0x3u<<5)
#define	TIM4_CR1_DIR_B_0X0					(0x0u<<4)
#define	TIM4_CR1_DIR_B_0X1					(0x1u<<4)
#define	TIM4_CR1_OPM_B_0X0					(0x0u<<3)
#define	TIM4_CR1_OPM_B_0X1					(0x1u<<3)
#define	TIM4_CR1_URS_B_0X0					(0x0u<<2)
#define	TIM4_CR1_URS_B_0X1					(0x1u<<2)
#define	TIM4_CR1_UDIS_B_0X0					(0x0u<<1)
#define	TIM4_CR1_UDIS_B_0X1					(0x1u<<1)
#define	TIM4_CR1_CEN_B_0X0					(0x0u<<0)
#define	TIM4_CR1_CEN_B_0X1					(0x1u<<0)

// CR2 Configuration

#define	TIM4_CR2_TI1S						(0x1u<<7)
#define	TIM4_CR2_MMS						(0x7u<<4)
#define	TIM4_CR2_MMS_0						(0x1u<<4)
#define	TIM4_CR2_CCDS						(0x1u<<3)
#define	TIM4_CR2_TI1S_B_0X0					(0x0u<<7)
#define	TIM4_CR2_TI1S_B_0X1					(0x1u<<7)
#define	TIM4_CR2_MMS_B_0X0					(0x0u<<4)
#define	TIM4_CR2_MMS_B_0X1					(0x1u<<4)
#define	TIM4_CR2_MMS_B_0X2					(0x2u<<4)
#define	TIM4_CR2_MMS_B_0X3					(0x3u<<4)
#define	TIM4_CR2_MMS_B_0X4					(0x4u<<4)
#define	TIM4_CR2_MMS_B_0X5					(0x5u<<4)
#define	TIM4_CR2_MMS_B_0X6					(0x6u<<4)
#define	TIM4_CR2_MMS_B_0X7					(0x7u<<4)
#define	TIM4_CR2_CCDS_B_0X0					(0x0u<<3)
#define	TIM4_CR2_CCDS_B_0X1					(0x1u<<3)

// SMCR Configuration

#define	TIM4_SMCR_TS_1						(0x3u<<20)
#define	TIM4_SMCR_TS_1_0					(0x1u<<20)
#define	TIM4_SMCR_SMS_1						(0x1u<<16)
#define	TIM4_SMCR_ETP						(0x1u<<15)
#define	TIM4_SMCR_ECE						(0x1u<<14)
#define	TIM4_SMCR_ETPS						(0x3u<<12)
#define	TIM4_SMCR_ETPS_0					(0x1u<<12)
#define	TIM4_SMCR_ETF						(0xFu<<8)
#define	TIM4_SMCR_ETF_0						(0x1u<<8)
#define	TIM4_SMCR_MSM						(0x1u<<7)
#define	TIM4_SMCR_TS						(0x7u<<4)
#define	TIM4_SMCR_TS_0						(0x1u<<4)
#define	TIM4_SMCR_SMS						(0x7u<<0)
#define	TIM4_SMCR_SMS_0						(0x1u<<0)
#define	TIM4_SMCR_ETP_B_0X0					(0x0u<<15)
#define	TIM4_SMCR_ETP_B_0X1					(0x1u<<15)
#define	TIM4_SMCR_ECE_B_0X0					(0x0u<<14)
#define	TIM4_SMCR_ECE_B_0X1					(0x1u<<14)
#define	TIM4_SMCR_ETPS_B_0X0				(0x0u<<12)
#define	TIM4_SMCR_ETPS_B_0X1				(0x1u<<12)
#define	TIM4_SMCR_ETPS_B_0X2				(0x2u<<12)
#define	TIM4_SMCR_ETPS_B_0X3				(0x3u<<12)
#define	TIM4_SMCR_ETF_B_0X0					(0x0u<<8)
#define	TIM4_SMCR_ETF_B_0X1					(0x1u<<8)
#define	TIM4_SMCR_ETF_B_0X2					(0x2u<<8)
#define	TIM4_SMCR_ETF_B_0X3					(0x3u<<8)
#define	TIM4_SMCR_ETF_B_0X4					(0x4u<<8)
#define	TIM4_SMCR_ETF_B_0X5					(0x5u<<8)
#define	TIM4_SMCR_ETF_B_0X6					(0x6u<<8)
#define	TIM4_SMCR_ETF_B_0X7					(0x7u<<8)
#define	TIM4_SMCR_ETF_B_0X8					(0x8u<<8)
#define	TIM4_SMCR_ETF_B_0X9					(0x9u<<8)
#define	TIM4_SMCR_ETF_B_0XA					(0xAu<<8)
#define	TIM4_SMCR_ETF_B_0XB					(0xBu<<8)
#define	TIM4_SMCR_ETF_B_0XC					(0xCu<<8)
#define	TIM4_SMCR_ETF_B_0XD					(0xDu<<8)
#define	TIM4_SMCR_ETF_B_0XE					(0xEu<<8)
#define	TIM4_SMCR_ETF_B_0XF					(0xFu<<8)
#define	TIM4_SMCR_MSM_B_0X0					(0x0u<<7)
#define	TIM4_SMCR_MSM_B_0X1					(0x1u<<7)
#define	TIM4_SMCR_TS_B_0X0					(0x0u<<4)
#define	TIM4_SMCR_TS_B_0X1					(0x1u<<4)
#define	TIM4_SMCR_TS_B_0X2					(0x2u<<4)
#define	TIM4_SMCR_TS_B_0X3					(0x3u<<4)
#define	TIM4_SMCR_TS_B_0X4					(0x4u<<4)
#define	TIM4_SMCR_TS_B_0X5					(0x5u<<4)
#define	TIM4_SMCR_TS_B_0X6					(0x6u<<4)
#define	TIM4_SMCR_TS_B_0X7					(0x7u<<4)
#define	TIM4_SMCR_SMS_B_0X0					(0x0u<<0)
#define	TIM4_SMCR_SMS_B_0X1					(0x1u<<0)
#define	TIM4_SMCR_SMS_B_0X2					(0x2u<<0)
#define	TIM4_SMCR_SMS_B_0X3					(0x3u<<0)
#define	TIM4_SMCR_SMS_B_0X4					(0x4u<<0)
#define	TIM4_SMCR_SMS_B_0X5					(0x5u<<0)
#define	TIM4_SMCR_SMS_B_0X6					(0x6u<<0)
#define	TIM4_SMCR_SMS_B_0X7					(0x7u<<0)

// DIER Configuration

#define	TIM4_DIER_TDE						(0x1u<<14)
#define	TIM4_DIER_CC4DE						(0x1u<<12)
#define	TIM4_DIER_CC3DE						(0x1u<<11)
#define	TIM4_DIER_CC2DE						(0x1u<<10)
#define	TIM4_DIER_CC1DE						(0x1u<<9)
#define	TIM4_DIER_UDE						(0x1u<<8)
#define	TIM4_DIER_TIE						(0x1u<<6)
#define	TIM4_DIER_CC4IE						(0x1u<<4)
#define	TIM4_DIER_CC3IE						(0x1u<<3)
#define	TIM4_DIER_CC2IE						(0x1u<<2)
#define	TIM4_DIER_CC1IE						(0x1u<<1)
#define	TIM4_DIER_UIE						(0x1u<<0)
#define	TIM4_DIER_TDE_B_0X0					(0x0u<<14)
#define	TIM4_DIER_TDE_B_0X1					(0x1u<<14)
#define	TIM4_DIER_CC4DE_B_0X0				(0x0u<<12)
#define	TIM4_DIER_CC4DE_B_0X1				(0x1u<<12)
#define	TIM4_DIER_CC3DE_B_0X0				(0x0u<<11)
#define	TIM4_DIER_CC3DE_B_0X1				(0x1u<<11)
#define	TIM4_DIER_CC2DE_B_0X0				(0x0u<<10)
#define	TIM4_DIER_CC2DE_B_0X1				(0x1u<<10)
#define	TIM4_DIER_CC1DE_B_0X0				(0x0u<<9)
#define	TIM4_DIER_CC1DE_B_0X1				(0x1u<<9)
#define	TIM4_DIER_UDE_B_0X0					(0x0u<<8)
#define	TIM4_DIER_UDE_B_0X1					(0x1u<<8)
#define	TIM4_DIER_TIE_B_0X0					(0x0u<<6)
#define	TIM4_DIER_TIE_B_0X1					(0x1u<<6)
#define	TIM4_DIER_CC4IE_B_0X0				(0x0u<<4)
#define	TIM4_DIER_CC4IE_B_0X1				(0x1u<<4)
#define	TIM4_DIER_CC3IE_B_0X0				(0x0u<<3)
#define	TIM4_DIER_CC3IE_B_0X1				(0x1u<<3)
#define	TIM4_DIER_CC2IE_B_0X0				(0x0u<<2)
#define	TIM4_DIER_CC2IE_B_0X1				(0x1u<<2)
#define	TIM4_DIER_CC1IE_B_0X0				(0x0u<<1)
#define	TIM4_DIER_CC1IE_B_0X1				(0x1u<<1)
#define	TIM4_DIER_UIE_B_0X0					(0x0u<<0)
#define	TIM4_DIER_UIE_B_0X1					(0x1u<<0)

// SR Configuration

#define	TIM4_SR_CC4OF						(0x1u<<12)
#define	TIM4_SR_CC3OF						(0x1u<<11)
#define	TIM4_SR_CC2OF						(0x1u<<10)
#define	TIM4_SR_CC1OF						(0x1u<<9)
#define	TIM4_SR_TIF							(0x1u<<6)
#define	TIM4_SR_CC4IF						(0x1u<<4)
#define	TIM4_SR_CC3IF						(0x1u<<3)
#define	TIM4_SR_CC2IF						(0x1u<<2)
#define	TIM4_SR_CC1IF						(0x1u<<1)
#define	TIM4_SR_UIF							(0x1u<<0)
#define	TIM4_SR_CC1OF_B_0X0					(0x0u<<9)
#define	TIM4_SR_CC1OF_B_0X1					(0x1u<<9)
#define	TIM4_SR_TIF_B_0X0					(0x0u<<6)
#define	TIM4_SR_TIF_B_0X1					(0x1u<<6)
#define	TIM4_SR_CC1IF_B_0X0					(0x0u<<1)
#define	TIM4_SR_CC1IF_B_0X1					(0x1u<<1)
#define	TIM4_SR_UIF_B_0X0					(0x0u<<0)
#define	TIM4_SR_UIF_B_0X1					(0x1u<<0)

// EGR Configuration

#define	TIM4_EGR_TG							(0x1u<<6)
#define	TIM4_EGR_CC4G						(0x1u<<4)
#define	TIM4_EGR_CC3G						(0x1u<<3)
#define	TIM4_EGR_CC2G						(0x1u<<2)
#define	TIM4_EGR_CC1G						(0x1u<<1)
#define	TIM4_EGR_UG							(0x1u<<0)
#define	TIM4_EGR_TG_B_0X0					(0x0u<<6)
#define	TIM4_EGR_TG_B_0X1					(0x1u<<6)
#define	TIM4_EGR_CC1G_B_0X0					(0x0u<<1)
#define	TIM4_EGR_CC1G_B_0X1					(0x1u<<1)
#define	TIM4_EGR_UG_B_0X0					(0x0u<<0)
#define	TIM4_EGR_UG_B_0X1					(0x1u<<0)

// CCMR1 Configuration

#define	TIM4_CCMR1_IC2F						(0xFu<<12)
#define	TIM4_CCMR1_IC2F_0					(0x1u<<12)
#define	TIM4_CCMR1_IC2PSC					(0x3u<<10)
#define	TIM4_CCMR1_IC2PSC_0					(0x1u<<10)
#define	TIM4_CCMR1_CC2S						(0x3u<<8)
#define	TIM4_CCMR1_CC2S_0					(0x1u<<8)
#define	TIM4_CCMR1_IC1F						(0xFu<<4)
#define	TIM4_CCMR1_IC1F_0					(0x1u<<4)
#define	TIM4_CCMR1_IC1PSC					(0x3u<<2)
#define	TIM4_CCMR1_IC1PSC_0					(0x1u<<2)
#define	TIM4_CCMR1_CC1S						(0x3u<<0)
#define	TIM4_CCMR1_CC1S_0					(0x1u<<0)
#define	TIM4_CCMR1_CC2S_B_0X0				(0x0u<<8)
#define	TIM4_CCMR1_CC2S_B_0X1				(0x1u<<8)
#define	TIM4_CCMR1_CC2S_B_0X2				(0x2u<<8)
#define	TIM4_CCMR1_CC2S_B_0X3				(0x3u<<8)
#define	TIM4_CCMR1_IC1F_B_0X0				(0x0u<<4)
#define	TIM4_CCMR1_IC1F_B_0X1				(0x1u<<4)
#define	TIM4_CCMR1_IC1F_B_0X2				(0x2u<<4)
#define	TIM4_CCMR1_IC1F_B_0X3				(0x3u<<4)
#define	TIM4_CCMR1_IC1F_B_0X4				(0x4u<<4)
#define	TIM4_CCMR1_IC1F_B_0X5				(0x5u<<4)
#define	TIM4_CCMR1_IC1F_B_0X6				(0x6u<<4)
#define	TIM4_CCMR1_IC1F_B_0X7				(0x7u<<4)
#define	TIM4_CCMR1_IC1F_B_0X8				(0x8u<<4)
#define	TIM4_CCMR1_IC1F_B_0X9				(0x9u<<4)
#define	TIM4_CCMR1_IC1F_B_0XA				(0xAu<<4)
#define	TIM4_CCMR1_IC1F_B_0XB				(0xBu<<4)
#define	TIM4_CCMR1_IC1F_B_0XC				(0xCu<<4)
#define	TIM4_CCMR1_IC1F_B_0XD				(0xDu<<4)
#define	TIM4_CCMR1_IC1F_B_0XE				(0xEu<<4)
#define	TIM4_CCMR1_IC1F_B_0XF				(0xFu<<4)
#define	TIM4_CCMR1_IC1PSC_B_0X0				(0x0u<<2)
#define	TIM4_CCMR1_IC1PSC_B_0X1				(0x1u<<2)
#define	TIM4_CCMR1_IC1PSC_B_0X2				(0x2u<<2)
#define	TIM4_CCMR1_IC1PSC_B_0X3				(0x3u<<2)
#define	TIM4_CCMR1_CC1S_B_0X0				(0x0u<<0)
#define	TIM4_CCMR1_CC1S_B_0X1				(0x1u<<0)
#define	TIM4_CCMR1_CC1S_B_0X2				(0x2u<<0)
#define	TIM4_CCMR1_CC1S_B_0X3				(0x3u<<0)

// CCMR1_ALTERNATE Configuration

#define	TIM4_CCMR1_ALTERNATE_OC2M_1			(0x1u<<24)
#define	TIM4_CCMR1_ALTERNATE_OC1M_1			(0x1u<<16)
#define	TIM4_CCMR1_ALTERNATE_OC2CE			(0x1u<<15)
#define	TIM4_CCMR1_ALTERNATE_OC2M			(0x7u<<12)
#define	TIM4_CCMR1_ALTERNATE_OC2M_0			(0x1u<<12)
#define	TIM4_CCMR1_ALTERNATE_OC2PE			(0x1u<<11)
#define	TIM4_CCMR1_ALTERNATE_OC2FE			(0x1u<<10)
#define	TIM4_CCMR1_ALTERNATE_CC2S			(0x3u<<8)
#define	TIM4_CCMR1_ALTERNATE_CC2S_0			(0x1u<<8)
#define	TIM4_CCMR1_ALTERNATE_OC1CE			(0x1u<<7)
#define	TIM4_CCMR1_ALTERNATE_OC1M			(0x7u<<4)
#define	TIM4_CCMR1_ALTERNATE_OC1M_0			(0x1u<<4)
#define	TIM4_CCMR1_ALTERNATE_OC1PE			(0x1u<<3)
#define	TIM4_CCMR1_ALTERNATE_OC1FE			(0x1u<<2)
#define	TIM4_CCMR1_ALTERNATE_CC1S			(0x3u<<0)
#define	TIM4_CCMR1_ALTERNATE_CC1S_0			(0x1u<<0)
#define	TIM4_CCMR1_ALTERNATE_CC2S_B_0X0		(0x0u<<8)
#define	TIM4_CCMR1_ALTERNATE_CC2S_B_0X1		(0x1u<<8)
#define	TIM4_CCMR1_ALTERNATE_CC2S_B_0X2		(0x2u<<8)
#define	TIM4_CCMR1_ALTERNATE_CC2S_B_0X3		(0x3u<<8)
#define	TIM4_CCMR1_ALTERNATE_OC1CE_B_0X0	(0x0u<<7)
#define	TIM4_CCMR1_ALTERNATE_OC1CE_B_0X1	(0x1u<<7)
#define	TIM4_CCMR1_ALTERNATE_OC1M_B_0X0		(0x0u<<4)
#define	TIM4_CCMR1_ALTERNATE_OC1M_B_0X1		(0x1u<<4)
#define	TIM4_CCMR1_ALTERNATE_OC1M_B_0X2		(0x2u<<4)
#define	TIM4_CCMR1_ALTERNATE_OC1M_B_0X3		(0x3u<<4)
#define	TIM4_CCMR1_ALTERNATE_OC1M_B_0X4		(0x4u<<4)
#define	TIM4_CCMR1_ALTERNATE_OC1M_B_0X5		(0x5u<<4)
#define	TIM4_CCMR1_ALTERNATE_OC1M_B_0X6		(0x6u<<4)
#define	TIM4_CCMR1_ALTERNATE_OC1M_B_0X7		(0x7u<<4)
#define	TIM4_CCMR1_ALTERNATE_OC1PE_B_0X0	(0x0u<<3)
#define	TIM4_CCMR1_ALTERNATE_OC1PE_B_0X1	(0x1u<<3)
#define	TIM4_CCMR1_ALTERNATE_OC1FE_B_0X0	(0x0u<<2)
#define	TIM4_CCMR1_ALTERNATE_OC1FE_B_0X1	(0x1u<<2)
#define	TIM4_CCMR1_ALTERNATE_CC1S_B_0X0		(0x0u<<0)
#define	TIM4_CCMR1_ALTERNATE_CC1S_B_0X1		(0x1u<<0)
#define	TIM4_CCMR1_ALTERNATE_CC1S_B_0X2		(0x2u<<0)
#define	TIM4_CCMR1_ALTERNATE_CC1S_B_0X3		(0x3u<<0)

// CCMR2 Configuration

#define	TIM4_CCMR2_IC4F						(0xFu<<12)
#define	TIM4_CCMR2_IC4F_0					(0x1u<<12)
#define	TIM4_CCMR2_IC4PSC					(0x3u<<10)
#define	TIM4_CCMR2_IC4PSC_0					(0x1u<<10)
#define	TIM4_CCMR2_CC4S						(0x3u<<8)
#define	TIM4_CCMR2_CC4S_0					(0x1u<<8)
#define	TIM4_CCMR2_IC3F						(0xFu<<4)
#define	TIM4_CCMR2_IC3F_0					(0x1u<<4)
#define	TIM4_CCMR2_IC3PSC					(0x3u<<2)
#define	TIM4_CCMR2_IC3PSC_0					(0x1u<<2)
#define	TIM4_CCMR2_CC3S						(0x3u<<0)
#define	TIM4_CCMR2_CC3S_0					(0x1u<<0)
#define	TIM4_CCMR2_CC4S_B_0X0				(0x0u<<8)
#define	TIM4_CCMR2_CC4S_B_0X1				(0x1u<<8)
#define	TIM4_CCMR2_CC4S_B_0X2				(0x2u<<8)
#define	TIM4_CCMR2_CC4S_B_0X3				(0x3u<<8)
#define	TIM4_CCMR2_CC3S_B_0X0				(0x0u<<0)
#define	TIM4_CCMR2_CC3S_B_0X1				(0x1u<<0)
#define	TIM4_CCMR2_CC3S_B_0X2				(0x2u<<0)
#define	TIM4_CCMR2_CC3S_B_0X3				(0x3u<<0)

// CCMR2_ALTERNATE Configuration

#define	TIM4_CCMR2_ALTERNATE_OC4M_1			(0x1u<<24)
#define	TIM4_CCMR2_ALTERNATE_OC3M_1			(0x1u<<16)
#define	TIM4_CCMR2_ALTERNATE_OC4CE			(0x1u<<15)
#define	TIM4_CCMR2_ALTERNATE_OC4M			(0x7u<<12)
#define	TIM4_CCMR2_ALTERNATE_OC4M_0			(0x1u<<12)
#define	TIM4_CCMR2_ALTERNATE_OC4PE			(0x1u<<11)
#define	TIM4_CCMR2_ALTERNATE_OC4FE			(0x1u<<10)
#define	TIM4_CCMR2_ALTERNATE_CC4S			(0x3u<<8)
#define	TIM4_CCMR2_ALTERNATE_CC4S_0			(0x1u<<8)
#define	TIM4_CCMR2_ALTERNATE_OC3CE			(0x1u<<7)
#define	TIM4_CCMR2_ALTERNATE_OC3M			(0x7u<<4)
#define	TIM4_CCMR2_ALTERNATE_OC3M_0			(0x1u<<4)
#define	TIM4_CCMR2_ALTERNATE_OC3PE			(0x1u<<3)
#define	TIM4_CCMR2_ALTERNATE_OC3FE			(0x1u<<2)
#define	TIM4_CCMR2_ALTERNATE_CC3S			(0x3u<<0)
#define	TIM4_CCMR2_ALTERNATE_CC3S_0			(0x1u<<0)
#define	TIM4_CCMR2_ALTERNATE_CC4S_B_0X0		(0x0u<<8)
#define	TIM4_CCMR2_ALTERNATE_CC4S_B_0X1		(0x1u<<8)
#define	TIM4_CCMR2_ALTERNATE_CC4S_B_0X2		(0x2u<<8)
#define	TIM4_CCMR2_ALTERNATE_CC4S_B_0X3		(0x3u<<8)
#define	TIM4_CCMR2_ALTERNATE_CC3S_B_0X0		(0x0u<<0)
#define	TIM4_CCMR2_ALTERNATE_CC3S_B_0X1		(0x1u<<0)
#define	TIM4_CCMR2_ALTERNATE_CC3S_B_0X2		(0x2u<<0)
#define	TIM4_CCMR2_ALTERNATE_CC3S_B_0X3		(0x3u<<0)

// CCER Configuration

#define	TIM4_CCER_CC4NP						(0x1u<<15)
#define	TIM4_CCER_CC4P						(0x1u<<13)
#define	TIM4_CCER_CC4E						(0x1u<<12)
#define	TIM4_CCER_CC3NP						(0x1u<<11)
#define	TIM4_CCER_CC3P						(0x1u<<9)
#define	TIM4_CCER_CC3E						(0x1u<<8)
#define	TIM4_CCER_CC2NP						(0x1u<<7)
#define	TIM4_CCER_CC2P						(0x1u<<5)
#define	TIM4_CCER_CC2E						(0x1u<<4)
#define	TIM4_CCER_CC1NP						(0x1u<<3)
#define	TIM4_CCER_CC1P						(0x1u<<1)
#define	TIM4_CCER_CC1E						(0x1u<<0)
#define	TIM4_CCER_CC1P_B_0X0				(0x0u<<1)
#define	TIM4_CCER_CC1P_B_0X1				(0x1u<<1)
#define	TIM4_CCER_CC1E_B_0X0				(0x0u<<0)
#define	TIM4_CCER_CC1E_B_0X1				(0x1u<<0)

// CNT Configuration

#define	TIM4_CNT_CNT						(0xFFFFFFFFu<<0)
#define	TIM4_CNT_CNT_0						(0x1u<<0)

// CNT_ALTERNATE Configuration

#define	TIM4_CNT_ALTERNATE_UIFCPY			(0x1u<<31)
#define	TIM4_CNT_ALTERNATE_CNT				(0x7FFFFFFFu<<0)
#define	TIM4_CNT_ALTERNATE_CNT_0			(0x1u<<0)

// PSC Configuration

#define	TIM4_PSC_PSC						(0xFFFFu<<0)
#define	TIM4_PSC_PSC_0						(0x1u<<0)

// ARR Configuration

#define	TIM4_ARR_ARR						(0xFFFFFFFFu<<0)
#define	TIM4_ARR_ARR_0						(0x1u<<0)

// CCR1 Configuration

#define	TIM4_CCR1_CCR1						(0xFFFFFFFFu<<0)
#define	TIM4_CCR1_CCR1_0					(0x1u<<0)

// CCR2 Configuration

#define	TIM4_CCR2_CCR2						(0xFFFFFFFFu<<0)
#define	TIM4_CCR2_CCR2_0					(0x1u<<0)

// CCR3 Configuration

#define	TIM4_CCR3_CCR3						(0xFFFFFFFFu<<0)
#define	TIM4_CCR3_CCR3_0					(0x1u<<0)

// CCR4 Configuration

#define	TIM4_CCR4_CCR4						(0xFFFFFFFFu<<0)
#define	TIM4_CCR4_CCR4_0					(0x1u<<0)

// DCR Configuration

#define	TIM4_DCR_DBL						(0x1Fu<<8)
#define	TIM4_DCR_DBL_0						(0x1u<<8)
#define	TIM4_DCR_DBA						(0x1Fu<<0)
#define	TIM4_DCR_DBA_0						(0x1u<<0)
#define	TIM4_DCR_DBL_B_0X0					(0x0u<<8)
#define	TIM4_DCR_DBL_B_0X1					(0x1u<<8)
#define	TIM4_DCR_DBL_B_0X2					(0x2u<<8)
#define	TIM4_DCR_DBL_B_0X11					(0x11u<<8)
#define	TIM4_DCR_DBA_B_0X0					(0x0u<<0)
#define	TIM4_DCR_DBA_B_0X1					(0x1u<<0)
#define	TIM4_DCR_DBA_B_0X2					(0x2u<<0)

// DMAR Configuration

#define	TIM4_DMAR_DMAB						(0xFFFFu<<0)
#define	TIM4_DMAR_DMAB_0					(0x1u<<0)

// AF1 Configuration

#define	TIM4_AF1_ETRSEL						(0xFu<<14)
#define	TIM4_AF1_ETRSEL_0					(0x1u<<14)
#define	TIM4_AF1_ETRSEL_B_0X0				(0x0u<<14)
#define	TIM4_AF1_ETRSEL_B_0X1				(0x1u<<14)
#define	TIM4_AF1_ETRSEL_B_0X2				(0x2u<<14)
#define	TIM4_AF1_ETRSEL_B_0X3				(0x3u<<14)
#define	TIM4_AF1_ETRSEL_B_0X4				(0x4u<<14)
#define	TIM4_AF1_ETRSEL_B_0X5				(0x5u<<14)

// TISEL Configuration

#define	TIM4_TISEL_TI4SEL					(0xFu<<24)
#define	TIM4_TISEL_TI4SEL_0					(0x1u<<24)
#define	TIM4_TISEL_TI3SEL					(0xFu<<16)
#define	TIM4_TISEL_TI3SEL_0					(0x1u<<16)
#define	TIM4_TISEL_TI2SEL					(0xFu<<8)
#define	TIM4_TISEL_TI2SEL_0					(0x1u<<8)
#define	TIM4_TISEL_TI1SEL					(0xFu<<0)
#define	TIM4_TISEL_TI1SEL_0					(0x1u<<0)
#define	TIM4_TISEL_TI4SEL_B_0X0				(0x0u<<24)
#define	TIM4_TISEL_TI4SEL_B_0X1				(0x1u<<24)
#define	TIM4_TISEL_TI4SEL_B_0X2				(0x2u<<24)
#define	TIM4_TISEL_TI4SEL_B_0X3				(0x3u<<24)
#define	TIM4_TISEL_TI3SEL_B_0X0				(0x0u<<16)
#define	TIM4_TISEL_TI2SEL_B_0X0				(0x0u<<8)
#define	TIM4_TISEL_TI1SEL_B_0X0				(0x0u<<0)
