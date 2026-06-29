/*
; stm32N657_tim8.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_tim8 equates.
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

// TIM8 address definitions
// ------------------------

typedef struct {
	volatile	uint16_t	CR1;
	volatile	uint16_t	RESERVED0;
	volatile	uint32_t	CR2;
	volatile	uint32_t	SMCR;
	volatile	uint32_t	DIER;
	volatile	uint32_t	SR;
	volatile	uint16_t	EGR;
	volatile	uint16_t	RESERVED1;
	volatile	uint32_t	CCMR1;
	volatile	uint32_t	CCMR2;
	volatile	uint32_t	CCER;
	volatile	uint32_t	CNT;
	volatile	uint16_t	PSC;
	volatile	uint16_t	RESERVED2;
	volatile	uint32_t	ARR;
	volatile	uint16_t	RCR;
	volatile	uint16_t	RESERVED3;
	volatile	uint32_t	CCR1;
	volatile	uint32_t	CCR2;
	volatile	uint32_t	CCR3;
	volatile	uint32_t	CCR4;
	volatile	uint32_t	BDTR;
	volatile	uint32_t	CCR5;
	volatile	uint32_t	CCR6;
	volatile	uint32_t	CCMR3;
	volatile	uint32_t	DTR2;
	volatile	uint32_t	ECR;
	volatile	uint32_t	TISEL;
	volatile	uint32_t	AF1;
	volatile	uint32_t	AF2;
	volatile	uint32_t	RESERVED4[221];
	volatile	uint32_t	DCR;
	volatile	uint32_t	DMAR;
} TIM8_TypeDef;

#if (defined(__cplusplus))
#define	TIM8_S	reinterpret_cast<TIM8_TypeDef *>(0x52000400u)

#else
#define	TIM8_S	((TIM8_TypeDef *)0x52000400u)
#endif

// CR1 Configuration

#define	TIM8_CR1_DITHEN				(0x1u<<12)
#define	TIM8_CR1_UIFREMAP			(0x1u<<11)
#define	TIM8_CR1_CKD				(0x3u<<8)
#define	TIM8_CR1_CKD_0				(0x1u<<8)
#define	TIM8_CR1_ARPE				(0x1u<<7)
#define	TIM8_CR1_CMS				(0x3u<<5)
#define	TIM8_CR1_CMS_0				(0x1u<<5)
#define	TIM8_CR1_DIR				(0x1u<<4)
#define	TIM8_CR1_OPM				(0x1u<<3)
#define	TIM8_CR1_URS				(0x1u<<2)
#define	TIM8_CR1_UDIS				(0x1u<<1)
#define	TIM8_CR1_CEN				(0x1u<<0)

#define	TIM8_CR1_DITHEN_B_0X0		(0x0u<<12)
#define	TIM8_CR1_DITHEN_B_0X1		(0x1u<<12)
#define	TIM8_CR1_UIFREMAP_B_0X0		(0x0u<<11)
#define	TIM8_CR1_UIFREMAP_B_0X1		(0x1u<<11)
#define	TIM8_CR1_CKD_B_0X0			(0x0u<<8)
#define	TIM8_CR1_CKD_B_0X1			(0x1u<<8)
#define	TIM8_CR1_CKD_B_0X2			(0x2u<<8)
#define	TIM8_CR1_ARPE_B_0X0			(0x0u<<7)
#define	TIM8_CR1_ARPE_B_0X1			(0x1u<<7)
#define	TIM8_CR1_CMS_B_0X0			(0x0u<<5)
#define	TIM8_CR1_CMS_B_0X1			(0x1u<<5)
#define	TIM8_CR1_CMS_B_0X2			(0x2u<<5)
#define	TIM8_CR1_CMS_B_0X3			(0x3u<<5)
#define	TIM8_CR1_DIR_B_0X0			(0x0u<<4)
#define	TIM8_CR1_DIR_B_0X1			(0x1u<<4)
#define	TIM8_CR1_OPM_B_0X0			(0x0u<<3)
#define	TIM8_CR1_OPM_B_0X1			(0x1u<<3)
#define	TIM8_CR1_URS_B_0X0			(0x0u<<2)
#define	TIM8_CR1_URS_B_0X1			(0x1u<<2)
#define	TIM8_CR1_UDIS_B_0X0			(0x0u<<1)
#define	TIM8_CR1_UDIS_B_0X1			(0x1u<<1)
#define	TIM8_CR1_CEN_B_0X0			(0x0u<<0)
#define	TIM8_CR1_CEN_B_0X1			(0x1u<<0)

// CR2 Configuration

#define	TIM8_CR2_ADSYNC				(0x1u<<28)
#define	TIM8_CR2_MMS_1				(0x1u<<25)
#define	TIM8_CR2_MMS2				(0xFu<<20)
#define	TIM8_CR2_MMS2_0				(0x1u<<20)
#define	TIM8_CR2_OIS6				(0x1u<<18)
#define	TIM8_CR2_OIS5				(0x1u<<16)
#define	TIM8_CR2_OIS4N				(0x1u<<15)
#define	TIM8_CR2_OIS4				(0x1u<<14)
#define	TIM8_CR2_OIS3N				(0x1u<<13)
#define	TIM8_CR2_OIS3				(0x1u<<12)
#define	TIM8_CR2_OIS2N				(0x1u<<11)
#define	TIM8_CR2_OIS2				(0x1u<<10)
#define	TIM8_CR2_OIS1N				(0x1u<<9)
#define	TIM8_CR2_OIS1				(0x1u<<8)
#define	TIM8_CR2_TI1S				(0x1u<<7)
#define	TIM8_CR2_MMS				(0x7u<<4)
#define	TIM8_CR2_MMS_0				(0x1u<<4)
#define	TIM8_CR2_CCDS				(0x1u<<3)
#define	TIM8_CR2_CCUS				(0x1u<<2)
#define	TIM8_CR2_CCPC				(0x1u<<0)

#define	TIM8_CR2_ADSYNC_B_0X0		(0x0u<<28)
#define	TIM8_CR2_ADSYNC_B_0X1		(0x1u<<28)
#define	TIM8_CR2_MMS2_B_0X0			(0x0u<<20)
#define	TIM8_CR2_MMS2_B_0X1			(0x1u<<20)
#define	TIM8_CR2_MMS2_B_0X2			(0x2u<<20)
#define	TIM8_CR2_MMS2_B_0X3			(0x3u<<20)
#define	TIM8_CR2_MMS2_B_0X4			(0x4u<<20)
#define	TIM8_CR2_MMS2_B_0X5			(0x5u<<20)
#define	TIM8_CR2_MMS2_B_0X6			(0x6u<<20)
#define	TIM8_CR2_MMS2_B_0X7			(0x7u<<20)
#define	TIM8_CR2_MMS2_B_0X8			(0x8u<<20)
#define	TIM8_CR2_MMS2_B_0X9			(0x9u<<20)
#define	TIM8_CR2_MMS2_B_0XA			(0xAu<<20)
#define	TIM8_CR2_MMS2_B_0XB			(0xBu<<20)
#define	TIM8_CR2_MMS2_B_0XC			(0xCu<<20)
#define	TIM8_CR2_MMS2_B_0XD			(0xDu<<20)
#define	TIM8_CR2_MMS2_B_0XE			(0xEu<<20)
#define	TIM8_CR2_MMS2_B_0XF			(0xFu<<20)
#define	TIM8_CR2_OIS1N_B_0X0		(0x0u<<9)
#define	TIM8_CR2_OIS1N_B_0X1		(0x1u<<9)
#define	TIM8_CR2_OIS1_B_0X0			(0x0u<<8)
#define	TIM8_CR2_OIS1_B_0X1			(0x1u<<8)
#define	TIM8_CR2_TI1S_B_0X0			(0x0u<<7)
#define	TIM8_CR2_TI1S_B_0X1			(0x1u<<7)
#define	TIM8_CR2_MMS_B_0X0			(0x0u<<4)
#define	TIM8_CR2_MMS_B_0X1			(0x1u<<4)
#define	TIM8_CR2_MMS_B_0X2			(0x2u<<4)
#define	TIM8_CR2_MMS_B_0X3			(0x3u<<4)
#define	TIM8_CR2_MMS_B_0X4			(0x4u<<4)
#define	TIM8_CR2_MMS_B_0X5			(0x5u<<4)
#define	TIM8_CR2_MMS_B_0X6			(0x6u<<4)
#define	TIM8_CR2_MMS_B_0X7			(0x7u<<4)
#define	TIM8_CR2_CCDS_B_0X0			(0x0u<<3)
#define	TIM8_CR2_CCDS_B_0X1			(0x1u<<3)
#define	TIM8_CR2_CCUS_B_0X0			(0x0u<<2)
#define	TIM8_CR2_CCUS_B_0X1			(0x1u<<2)
#define	TIM8_CR2_CCPC_B_0X0			(0x0u<<0)
#define	TIM8_CR2_CCPC_B_0X1			(0x1u<<0)

// SMCR Configuration

#define	TIM8_SMCR_SMSPS				(0x1u<<25)
#define	TIM8_SMCR_SMSPE				(0x1u<<24)
#define	TIM8_SMCR_TS_1				(0x3u<<20)
#define	TIM8_SMCR_TS_1_0			(0x1u<<20)
#define	TIM8_SMCR_SMS_1				(0x1u<<16)
#define	TIM8_SMCR_ETP				(0x1u<<15)
#define	TIM8_SMCR_ECE				(0x1u<<14)
#define	TIM8_SMCR_ETPS				(0x3u<<12)
#define	TIM8_SMCR_ETPS_0			(0x1u<<12)
#define	TIM8_SMCR_ETF				(0xFu<<8)
#define	TIM8_SMCR_ETF_0				(0x1u<<8)
#define	TIM8_SMCR_MSM				(0x1u<<7)
#define	TIM8_SMCR_TS				(0x7u<<4)
#define	TIM8_SMCR_TS_0				(0x1u<<4)
#define	TIM8_SMCR_SMS				(0x7u<<0)
#define	TIM8_SMCR_SMS_0				(0x1u<<0)

#define	TIM8_SMCR_SMSPS_B_0X0		(0x0u<<25)
#define	TIM8_SMCR_SMSPS_B_0X1		(0x1u<<25)
#define	TIM8_SMCR_SMSPE_B_0X0		(0x0u<<24)
#define	TIM8_SMCR_SMSPE_B_0X1		(0x1u<<24)
#define	TIM8_SMCR_ETP_B_0X0			(0x0u<<15)
#define	TIM8_SMCR_ETP_B_0X1			(0x1u<<15)
#define	TIM8_SMCR_ECE_B_0X0			(0x0u<<14)
#define	TIM8_SMCR_ECE_B_0X1			(0x1u<<14)
#define	TIM8_SMCR_ETPS_B_0X0		(0x0u<<12)
#define	TIM8_SMCR_ETPS_B_0X1		(0x1u<<12)
#define	TIM8_SMCR_ETPS_B_0X2		(0x2u<<12)
#define	TIM8_SMCR_ETPS_B_0X3		(0x3u<<12)
#define	TIM8_SMCR_ETF_B_0X0			(0x0u<<8)
#define	TIM8_SMCR_ETF_B_0X1			(0x1u<<8)
#define	TIM8_SMCR_ETF_B_0X2			(0x2u<<8)
#define	TIM8_SMCR_ETF_B_0X3			(0x3u<<8)
#define	TIM8_SMCR_ETF_B_0X4			(0x4u<<8)
#define	TIM8_SMCR_ETF_B_0X5			(0x5u<<8)
#define	TIM8_SMCR_ETF_B_0X6			(0x6u<<8)
#define	TIM8_SMCR_ETF_B_0X7			(0x7u<<8)
#define	TIM8_SMCR_ETF_B_0X8			(0x8u<<8)
#define	TIM8_SMCR_ETF_B_0X9			(0x9u<<8)
#define	TIM8_SMCR_ETF_B_0XA			(0xAu<<8)
#define	TIM8_SMCR_ETF_B_0XB			(0xBu<<8)
#define	TIM8_SMCR_ETF_B_0XC			(0xCu<<8)
#define	TIM8_SMCR_ETF_B_0XD			(0xDu<<8)
#define	TIM8_SMCR_ETF_B_0XE			(0xEu<<8)
#define	TIM8_SMCR_ETF_B_0XF			(0xFu<<8)
#define	TIM8_SMCR_MSM_B_0X0			(0x0u<<7)
#define	TIM8_SMCR_MSM_B_0X1			(0x1u<<7)
#define	TIM8_SMCR_TS_B_0X0			(0x0u<<4)
#define	TIM8_SMCR_TS_B_0X1			(0x1u<<4)
#define	TIM8_SMCR_TS_B_0X2			(0x2u<<4)
#define	TIM8_SMCR_TS_B_0X3			(0x3u<<4)
#define	TIM8_SMCR_TS_B_0X4			(0x4u<<4)
#define	TIM8_SMCR_TS_B_0X5			(0x5u<<4)
#define	TIM8_SMCR_TS_B_0X6			(0x6u<<4)
#define	TIM8_SMCR_TS_B_0X7			(0x7u<<4)
#define	TIM8_SMCR_SMS_B_0X0			(0x0u<<0)
#define	TIM8_SMCR_SMS_B_0X1			(0x1u<<0)
#define	TIM8_SMCR_SMS_B_0X2			(0x2u<<0)
#define	TIM8_SMCR_SMS_B_0X3			(0x3u<<0)
#define	TIM8_SMCR_SMS_B_0X4			(0x4u<<0)
#define	TIM8_SMCR_SMS_B_0X5			(0x5u<<0)
#define	TIM8_SMCR_SMS_B_0X6			(0x6u<<0)
#define	TIM8_SMCR_SMS_B_0X7			(0x7u<<0)

// DIER Configuration

#define	TIM8_DIER_TERRIE			(0x1u<<23)
#define	TIM8_DIER_IERRIE			(0x1u<<22)
#define	TIM8_DIER_DIRIE				(0x1u<<21)
#define	TIM8_DIER_IDXIE				(0x1u<<20)
#define	TIM8_DIER_TDE				(0x1u<<14)
#define	TIM8_DIER_COMDE				(0x1u<<13)
#define	TIM8_DIER_CC4DE				(0x1u<<12)
#define	TIM8_DIER_CC3DE				(0x1u<<11)
#define	TIM8_DIER_CC2DE				(0x1u<<10)
#define	TIM8_DIER_CC1DE				(0x1u<<9)
#define	TIM8_DIER_UDE				(0x1u<<8)
#define	TIM8_DIER_BIE				(0x1u<<7)
#define	TIM8_DIER_TIE				(0x1u<<6)
#define	TIM8_DIER_COMIE				(0x1u<<5)
#define	TIM8_DIER_CC4IE				(0x1u<<4)
#define	TIM8_DIER_CC3IE				(0x1u<<3)
#define	TIM8_DIER_CC2IE				(0x1u<<2)
#define	TIM8_DIER_CC1IE				(0x1u<<1)
#define	TIM8_DIER_UIE				(0x1u<<0)

#define	TIM8_DIER_TERRIE_B_0X0		(0x0u<<23)
#define	TIM8_DIER_TERRIE_B_0X1		(0x1u<<23)
#define	TIM8_DIER_IERRIE_B_0X0		(0x0u<<22)
#define	TIM8_DIER_IERRIE_B_0X1		(0x1u<<22)
#define	TIM8_DIER_DIRIE_B_0X0		(0x0u<<21)
#define	TIM8_DIER_DIRIE_B_0X1		(0x1u<<21)
#define	TIM8_DIER_IDXIE_B_0X0		(0x0u<<20)
#define	TIM8_DIER_IDXIE_B_0X1		(0x1u<<20)
#define	TIM8_DIER_TDE_B_0X0			(0x0u<<14)
#define	TIM8_DIER_TDE_B_0X1			(0x1u<<14)
#define	TIM8_DIER_COMDE_B_0X0		(0x0u<<13)
#define	TIM8_DIER_COMDE_B_0X1		(0x1u<<13)
#define	TIM8_DIER_CC4DE_B_0X0		(0x0u<<12)
#define	TIM8_DIER_CC4DE_B_0X1		(0x1u<<12)
#define	TIM8_DIER_CC3DE_B_0X0		(0x0u<<11)
#define	TIM8_DIER_CC3DE_B_0X1		(0x1u<<11)
#define	TIM8_DIER_CC2DE_B_0X0		(0x0u<<10)
#define	TIM8_DIER_CC2DE_B_0X1		(0x1u<<10)
#define	TIM8_DIER_CC1DE_B_0X0		(0x0u<<9)
#define	TIM8_DIER_CC1DE_B_0X1		(0x1u<<9)
#define	TIM8_DIER_UDE_B_0X0			(0x0u<<8)
#define	TIM8_DIER_UDE_B_0X1			(0x1u<<8)
#define	TIM8_DIER_BIE_B_0X0			(0x0u<<7)
#define	TIM8_DIER_BIE_B_0X1			(0x1u<<7)
#define	TIM8_DIER_TIE_B_0X0			(0x0u<<6)
#define	TIM8_DIER_TIE_B_0X1			(0x1u<<6)
#define	TIM8_DIER_COMIE_B_0X0		(0x0u<<5)
#define	TIM8_DIER_COMIE_B_0X1		(0x1u<<5)
#define	TIM8_DIER_CC4IE_B_0X0		(0x0u<<4)
#define	TIM8_DIER_CC4IE_B_0X1		(0x1u<<4)
#define	TIM8_DIER_CC3IE_B_0X0		(0x0u<<3)
#define	TIM8_DIER_CC3IE_B_0X1		(0x1u<<3)
#define	TIM8_DIER_CC2IE_B_0X0		(0x0u<<2)
#define	TIM8_DIER_CC2IE_B_0X1		(0x1u<<2)
#define	TIM8_DIER_CC1IE_B_0X0		(0x0u<<1)
#define	TIM8_DIER_CC1IE_B_0X1		(0x1u<<1)
#define	TIM8_DIER_UIE_B_0X0			(0x0u<<0)
#define	TIM8_DIER_UIE_B_0X1			(0x1u<<0)

// SR Configuration

#define	TIM8_SR_TERRF				(0x1u<<23)
#define	TIM8_SR_IERRF				(0x1u<<22)
#define	TIM8_SR_DIRF				(0x1u<<21)
#define	TIM8_SR_IDXF				(0x1u<<20)
#define	TIM8_SR_CC6IF				(0x1u<<17)
#define	TIM8_SR_CC5IF				(0x1u<<16)
#define	TIM8_SR_SBIF				(0x1u<<13)
#define	TIM8_SR_CC4OF				(0x1u<<12)
#define	TIM8_SR_CC3OF				(0x1u<<11)
#define	TIM8_SR_CC2OF				(0x1u<<10)
#define	TIM8_SR_CC1OF				(0x1u<<9)
#define	TIM8_SR_B2IF				(0x1u<<8)
#define	TIM8_SR_BIF					(0x1u<<7)
#define	TIM8_SR_TIF					(0x1u<<6)
#define	TIM8_SR_COMIF				(0x1u<<5)
#define	TIM8_SR_CC4IF				(0x1u<<4)
#define	TIM8_SR_CC3IF				(0x1u<<3)
#define	TIM8_SR_CC2IF				(0x1u<<2)
#define	TIM8_SR_CC1IF				(0x1u<<1)
#define	TIM8_SR_UIF					(0x1u<<0)

#define	TIM8_SR_TERRF_B_0X0			(0x0u<<23)
#define	TIM8_SR_TERRF_B_0X1			(0x1u<<23)
#define	TIM8_SR_IERRF_B_0X0			(0x0u<<22)
#define	TIM8_SR_IERRF_B_0X1			(0x1u<<22)
#define	TIM8_SR_DIRF_B_0X0			(0x0u<<21)
#define	TIM8_SR_DIRF_B_0X1			(0x1u<<21)
#define	TIM8_SR_IDXF_B_0X0			(0x0u<<20)
#define	TIM8_SR_IDXF_B_0X1			(0x1u<<20)
#define	TIM8_SR_SBIF_B_0X0			(0x0u<<13)
#define	TIM8_SR_SBIF_B_0X1			(0x1u<<13)
#define	TIM8_SR_CC1OF_B_0X0			(0x0u<<9)
#define	TIM8_SR_CC1OF_B_0X1			(0x1u<<9)
#define	TIM8_SR_B2IF_B_0X0			(0x0u<<8)
#define	TIM8_SR_B2IF_B_0X1			(0x1u<<8)
#define	TIM8_SR_BIF_B_0X0			(0x0u<<7)
#define	TIM8_SR_BIF_B_0X1			(0x1u<<7)
#define	TIM8_SR_TIF_B_0X0			(0x0u<<6)
#define	TIM8_SR_TIF_B_0X1			(0x1u<<6)
#define	TIM8_SR_COMIF_B_0X0			(0x0u<<5)
#define	TIM8_SR_COMIF_B_0X1			(0x1u<<5)
#define	TIM8_SR_CC1IF_B_0X0			(0x0u<<1)
#define	TIM8_SR_CC1IF_B_0X1			(0x1u<<1)
#define	TIM8_SR_UIF_B_0X0			(0x0u<<0)
#define	TIM8_SR_UIF_B_0X1			(0x1u<<0)

// EGR Configuration

#define	TIM8_EGR_B2G				(0x1u<<8)
#define	TIM8_EGR_BG					(0x1u<<7)
#define	TIM8_EGR_TG					(0x1u<<6)
#define	TIM8_EGR_COMG				(0x1u<<5)
#define	TIM8_EGR_CC4G				(0x1u<<4)
#define	TIM8_EGR_CC3G				(0x1u<<3)
#define	TIM8_EGR_CC2G				(0x1u<<2)
#define	TIM8_EGR_CC1G				(0x1u<<1)
#define	TIM8_EGR_UG					(0x1u<<0)

#define	TIM8_EGR_B2G_B_0X0			(0x0u<<8)
#define	TIM8_EGR_B2G_B_0X1			(0x1u<<8)
#define	TIM8_EGR_BG_B_0X0			(0x0u<<7)
#define	TIM8_EGR_BG_B_0X1			(0x1u<<7)
#define	TIM8_EGR_TG_B_0X0			(0x0u<<6)
#define	TIM8_EGR_TG_B_0X1			(0x1u<<6)
#define	TIM8_EGR_COMG_B_0X0			(0x0u<<5)
#define	TIM8_EGR_COMG_B_0X1			(0x1u<<5)
#define	TIM8_EGR_CC1G_B_0X0			(0x0u<<1)
#define	TIM8_EGR_CC1G_B_0X1			(0x1u<<1)
#define	TIM8_EGR_UG_B_0X0			(0x0u<<0)
#define	TIM8_EGR_UG_B_0X1			(0x1u<<0)

// CCMR1 Configuration

#define	TIM8_CCMR1_IC2F				(0xFu<<12)
#define	TIM8_CCMR1_IC2F_0			(0x1u<<12)
#define	TIM8_CCMR1_IC2PSC			(0x3u<<10)
#define	TIM8_CCMR1_IC2PSC_0			(0x1u<<10)
#define	TIM8_CCMR1_CC2S				(0x3u<<8)
#define	TIM8_CCMR1_CC2S_0			(0x1u<<8)
#define	TIM8_CCMR1_IC1F				(0xFu<<4)
#define	TIM8_CCMR1_IC1F_0			(0x1u<<4)
#define	TIM8_CCMR1_IC1PSC			(0x3u<<2)
#define	TIM8_CCMR1_IC1PSC_0			(0x1u<<2)
#define	TIM8_CCMR1_CC1S				(0x3u<<0)
#define	TIM8_CCMR1_CC1S_0			(0x1u<<0)

#define	TIM8_CCMR1_CC2S_B_0X0		(0x0u<<8)
#define	TIM8_CCMR1_CC2S_B_0X1		(0x1u<<8)
#define	TIM8_CCMR1_CC2S_B_0X2		(0x2u<<8)
#define	TIM8_CCMR1_CC2S_B_0X3		(0x3u<<8)
#define	TIM8_CCMR1_IC1F_B_0X0		(0x0u<<4)
#define	TIM8_CCMR1_IC1F_B_0X1		(0x1u<<4)
#define	TIM8_CCMR1_IC1F_B_0X2		(0x2u<<4)
#define	TIM8_CCMR1_IC1F_B_0X3		(0x3u<<4)
#define	TIM8_CCMR1_IC1F_B_0X4		(0x4u<<4)
#define	TIM8_CCMR1_IC1F_B_0X5		(0x5u<<4)
#define	TIM8_CCMR1_IC1F_B_0X6		(0x6u<<4)
#define	TIM8_CCMR1_IC1F_B_0X7		(0x7u<<4)
#define	TIM8_CCMR1_IC1F_B_0X8		(0x8u<<4)
#define	TIM8_CCMR1_IC1F_B_0X9		(0x9u<<4)
#define	TIM8_CCMR1_IC1F_B_0XA		(0xAu<<4)
#define	TIM8_CCMR1_IC1F_B_0XB		(0xBu<<4)
#define	TIM8_CCMR1_IC1F_B_0XC		(0xCu<<4)
#define	TIM8_CCMR1_IC1F_B_0XD		(0xDu<<4)
#define	TIM8_CCMR1_IC1F_B_0XE		(0xEu<<4)
#define	TIM8_CCMR1_IC1F_B_0XF		(0xFu<<4)
#define	TIM8_CCMR1_IC1PSC_B_0X0		(0x0u<<2)
#define	TIM8_CCMR1_IC1PSC_B_0X1		(0x1u<<2)
#define	TIM8_CCMR1_IC1PSC_B_0X2		(0x2u<<2)
#define	TIM8_CCMR1_IC1PSC_B_0X3		(0x3u<<2)
#define	TIM8_CCMR1_CC1S_B_0X0		(0x0u<<0)
#define	TIM8_CCMR1_CC1S_B_0X1		(0x1u<<0)
#define	TIM8_CCMR1_CC1S_B_0X2		(0x2u<<0)
#define	TIM8_CCMR1_CC1S_B_0X3		(0x3u<<0)

// CCMR2 Configuration

#define	TIM8_CCMR2_IC4F				(0xFu<<12)
#define	TIM8_CCMR2_IC4F_0			(0x1u<<12)
#define	TIM8_CCMR2_IC4PSC			(0x3u<<10)
#define	TIM8_CCMR2_IC4PSC_0			(0x1u<<10)
#define	TIM8_CCMR2_CC4S				(0x3u<<8)
#define	TIM8_CCMR2_CC4S_0			(0x1u<<8)
#define	TIM8_CCMR2_IC3F				(0xFu<<4)
#define	TIM8_CCMR2_IC3F_0			(0x1u<<4)
#define	TIM8_CCMR2_IC3PSC			(0x3u<<2)
#define	TIM8_CCMR2_IC3PSC_0			(0x1u<<2)
#define	TIM8_CCMR2_CC3S				(0x3u<<0)
#define	TIM8_CCMR2_CC3S_0			(0x1u<<0)

#define	TIM8_CCMR2_CC4S_B_0X0		(0x0u<<8)
#define	TIM8_CCMR2_CC4S_B_0X1		(0x1u<<8)
#define	TIM8_CCMR2_CC4S_B_0X2		(0x2u<<8)
#define	TIM8_CCMR2_CC4S_B_0X3		(0x3u<<8)
#define	TIM8_CCMR2_CC3S_B_0X0		(0x0u<<0)
#define	TIM8_CCMR2_CC3S_B_0X1		(0x1u<<0)
#define	TIM8_CCMR2_CC3S_B_0X2		(0x2u<<0)
#define	TIM8_CCMR2_CC3S_B_0X3		(0x3u<<0)

// CCER Configuration

#define	TIM8_CCER_CC6P				(0x1u<<21)
#define	TIM8_CCER_CC6E				(0x1u<<20)
#define	TIM8_CCER_CC5P				(0x1u<<17)
#define	TIM8_CCER_CC5E				(0x1u<<16)
#define	TIM8_CCER_CC4NP				(0x1u<<15)
#define	TIM8_CCER_CC4NE				(0x1u<<14)
#define	TIM8_CCER_CC4P				(0x1u<<13)
#define	TIM8_CCER_CC4E				(0x1u<<12)
#define	TIM8_CCER_CC3NP				(0x1u<<11)
#define	TIM8_CCER_CC3NE				(0x1u<<10)
#define	TIM8_CCER_CC3P				(0x1u<<9)
#define	TIM8_CCER_CC3E				(0x1u<<8)
#define	TIM8_CCER_CC2NP				(0x1u<<7)
#define	TIM8_CCER_CC2NE				(0x1u<<6)
#define	TIM8_CCER_CC2P				(0x1u<<5)
#define	TIM8_CCER_CC2E				(0x1u<<4)
#define	TIM8_CCER_CC1NP				(0x1u<<3)
#define	TIM8_CCER_CC1NE				(0x1u<<2)
#define	TIM8_CCER_CC1P				(0x1u<<1)
#define	TIM8_CCER_CC1E				(0x1u<<0)

#define	TIM8_CCER_CC1NP_B_0X0		(0x0u<<3)
#define	TIM8_CCER_CC1NP_B_0X1		(0x1u<<3)
#define	TIM8_CCER_CC1NE_B_0X0		(0x0u<<2)
#define	TIM8_CCER_CC1NE_B_0X1		(0x1u<<2)
#define	TIM8_CCER_CC1P_B_0X0		(0x0u<<1)
#define	TIM8_CCER_CC1P_B_0X1		(0x1u<<1)
#define	TIM8_CCER_CC1E_B_0X0		(0x0u<<0)
#define	TIM8_CCER_CC1E_B_0X1		(0x1u<<0)

// CNT Configuration

#define	TIM8_CNT_UIFCPY				(0x1u<<31)
#define	TIM8_CNT_CNT				(0xFFFFu<<0)
#define	TIM8_CNT_CNT_0				(0x1u<<0)

// PSC Configuration

#define	TIM8_PSC_PSC				(0xFFFFu<<0)
#define	TIM8_PSC_PSC_0				(0x1u<<0)

// ARR Configuration

#define	TIM8_ARR_ARR				(0xFFFFFu<<0)
#define	TIM8_ARR_ARR_0				(0x1u<<0)

// RCR Configuration

#define	TIM8_RCR_REP				(0xFFFFu<<0)
#define	TIM8_RCR_REP_0				(0x1u<<0)

// CCR1 Configuration

#define	TIM8_CCR1_CCR1				(0xFFFFFu<<0)
#define	TIM8_CCR1_CCR1_0			(0x1u<<0)

// CCR2 Configuration

#define	TIM8_CCR2_CCR2				(0xFFFFFu<<0)
#define	TIM8_CCR2_CCR2_0			(0x1u<<0)

// CCR3 Configuration

#define	TIM8_CCR3_CCR3				(0xFFFFFu<<0)
#define	TIM8_CCR3_CCR3_0			(0x1u<<0)

// CCR4 Configuration

#define	TIM8_CCR4_CCR4				(0xFFFFFu<<0)
#define	TIM8_CCR4_CCR4_0			(0x1u<<0)

// BDTR Configuration

#define	TIM8_BDTR_BK2BID			(0x1u<<29)
#define	TIM8_BDTR_BKBID				(0x1u<<28)
#define	TIM8_BDTR_BK2DSRM			(0x1u<<27)
#define	TIM8_BDTR_BKDSRM			(0x1u<<26)
#define	TIM8_BDTR_BK2P				(0x1u<<25)
#define	TIM8_BDTR_BK2E				(0x1u<<24)
#define	TIM8_BDTR_BK2F				(0xFu<<20)
#define	TIM8_BDTR_BK2F_0			(0x1u<<20)
#define	TIM8_BDTR_BKF				(0xFu<<16)
#define	TIM8_BDTR_BKF_0				(0x1u<<16)
#define	TIM8_BDTR_MOE				(0x1u<<15)
#define	TIM8_BDTR_AOE				(0x1u<<14)
#define	TIM8_BDTR_BKP				(0x1u<<13)
#define	TIM8_BDTR_BKE				(0x1u<<12)
#define	TIM8_BDTR_OSSR				(0x1u<<11)
#define	TIM8_BDTR_OSSI				(0x1u<<10)
#define	TIM8_BDTR_LOCK				(0x3u<<8)
#define	TIM8_BDTR_LOCK_0			(0x1u<<8)
#define	TIM8_BDTR_DTG				(0xFFu<<0)
#define	TIM8_BDTR_DTG_0				(0x1u<<0)

#define	TIM8_BDTR_BKBID_B_0X0		(0x0u<<28)
#define	TIM8_BDTR_BKBID_B_0X1		(0x1u<<28)
#define	TIM8_BDTR_BKDSRM_B_0X0		(0x0u<<26)
#define	TIM8_BDTR_BKDSRM_B_0X1		(0x1u<<26)
#define	TIM8_BDTR_BK2P_B_0X0		(0x0u<<25)
#define	TIM8_BDTR_BK2P_B_0X1		(0x1u<<25)
#define	TIM8_BDTR_BK2E_B_0X0		(0x0u<<24)
#define	TIM8_BDTR_BK2E_B_0X1		(0x1u<<24)
#define	TIM8_BDTR_BK2F_B_0X0		(0x0u<<20)
#define	TIM8_BDTR_BK2F_B_0X1		(0x1u<<20)
#define	TIM8_BDTR_BK2F_B_0X2		(0x2u<<20)
#define	TIM8_BDTR_BK2F_B_0X3		(0x3u<<20)
#define	TIM8_BDTR_BK2F_B_0X4		(0x4u<<20)
#define	TIM8_BDTR_BK2F_B_0X5		(0x5u<<20)
#define	TIM8_BDTR_BK2F_B_0X6		(0x6u<<20)
#define	TIM8_BDTR_BK2F_B_0X7		(0x7u<<20)
#define	TIM8_BDTR_BK2F_B_0X8		(0x8u<<20)
#define	TIM8_BDTR_BK2F_B_0X9		(0x9u<<20)
#define	TIM8_BDTR_BK2F_B_0XA		(0xAu<<20)
#define	TIM8_BDTR_BK2F_B_0XB		(0xBu<<20)
#define	TIM8_BDTR_BK2F_B_0XC		(0xCu<<20)
#define	TIM8_BDTR_BK2F_B_0XD		(0xDu<<20)
#define	TIM8_BDTR_BK2F_B_0XE		(0xEu<<20)
#define	TIM8_BDTR_BK2F_B_0XF		(0xFu<<20)
#define	TIM8_BDTR_BKF_B_0X0			(0x0u<<16)
#define	TIM8_BDTR_BKF_B_0X1			(0x1u<<16)
#define	TIM8_BDTR_BKF_B_0X2			(0x2u<<16)
#define	TIM8_BDTR_BKF_B_0X3			(0x3u<<16)
#define	TIM8_BDTR_BKF_B_0X4			(0x4u<<16)
#define	TIM8_BDTR_BKF_B_0X5			(0x5u<<16)
#define	TIM8_BDTR_BKF_B_0X6			(0x6u<<16)
#define	TIM8_BDTR_BKF_B_0X7			(0x7u<<16)
#define	TIM8_BDTR_BKF_B_0X8			(0x8u<<16)
#define	TIM8_BDTR_BKF_B_0X9			(0x9u<<16)
#define	TIM8_BDTR_BKF_B_0XA			(0xAu<<16)
#define	TIM8_BDTR_BKF_B_0XB			(0xBu<<16)
#define	TIM8_BDTR_BKF_B_0XC			(0xCu<<16)
#define	TIM8_BDTR_BKF_B_0XD			(0xDu<<16)
#define	TIM8_BDTR_BKF_B_0XE			(0xEu<<16)
#define	TIM8_BDTR_BKF_B_0XF			(0xFu<<16)
#define	TIM8_BDTR_MOE_B_0X0			(0x0u<<15)
#define	TIM8_BDTR_MOE_B_0X1			(0x1u<<15)
#define	TIM8_BDTR_AOE_B_0X0			(0x0u<<14)
#define	TIM8_BDTR_AOE_B_0X1			(0x1u<<14)
#define	TIM8_BDTR_BKP_B_0X0			(0x0u<<13)
#define	TIM8_BDTR_BKP_B_0X1			(0x1u<<13)
#define	TIM8_BDTR_BKE_B_0X0			(0x0u<<12)
#define	TIM8_BDTR_BKE_B_0X1			(0x1u<<12)
#define	TIM8_BDTR_OSSR_B_0X0		(0x0u<<11)
#define	TIM8_BDTR_OSSR_B_0X1		(0x1u<<11)
#define	TIM8_BDTR_OSSI_B_0X0		(0x0u<<10)
#define	TIM8_BDTR_OSSI_B_0X1		(0x1u<<10)
#define	TIM8_BDTR_LOCK_B_0X0		(0x0u<<8)
#define	TIM8_BDTR_LOCK_B_0X1		(0x1u<<8)
#define	TIM8_BDTR_LOCK_B_0X2		(0x2u<<8)
#define	TIM8_BDTR_LOCK_B_0X3		(0x3u<<8)

// CCR5 Configuration

#define	TIM8_CCR5_GC5C3				(0x1u<<31)
#define	TIM8_CCR5_GC5C2				(0x1u<<30)
#define	TIM8_CCR5_GC5C1				(0x1u<<29)
#define	TIM8_CCR5_CCR5				(0xFFFFFu<<0)
#define	TIM8_CCR5_CCR5_0			(0x1u<<0)

#define	TIM8_CCR5_GC5C3_B_0X0		(0x0u<<31)
#define	TIM8_CCR5_GC5C3_B_0X1		(0x1u<<31)
#define	TIM8_CCR5_GC5C2_B_0X0		(0x0u<<30)
#define	TIM8_CCR5_GC5C2_B_0X1		(0x1u<<30)
#define	TIM8_CCR5_GC5C1_B_0X0		(0x0u<<29)
#define	TIM8_CCR5_GC5C1_B_0X1		(0x1u<<29)

// CCR6 Configuration

#define	TIM8_CCR6_CCR6				(0xFFFFFu<<0)
#define	TIM8_CCR6_CCR6_0			(0x1u<<0)

// CCMR3 Configuration

#define	TIM8_CCMR3_OC6M_1			(0x1u<<24)
#define	TIM8_CCMR3_OC5M_1			(0x1u<<16)
#define	TIM8_CCMR3_OC6CE			(0x1u<<15)
#define	TIM8_CCMR3_OC6M				(0x7u<<12)
#define	TIM8_CCMR3_OC6M_0			(0x1u<<12)
#define	TIM8_CCMR3_OC6PE			(0x1u<<11)
#define	TIM8_CCMR3_OC6FE			(0x1u<<10)
#define	TIM8_CCMR3_OC5CE			(0x1u<<7)
#define	TIM8_CCMR3_OC5M				(0x7u<<4)
#define	TIM8_CCMR3_OC5M_0			(0x1u<<4)
#define	TIM8_CCMR3_OC5PE			(0x1u<<3)
#define	TIM8_CCMR3_OC5FE			(0x1u<<2)

// DTR2 Configuration

#define	TIM8_DTR2_DTPE				(0x1u<<17)
#define	TIM8_DTR2_DTAE				(0x1u<<16)
#define	TIM8_DTR2_DTGF				(0xFFu<<0)
#define	TIM8_DTR2_DTGF_0			(0x1u<<0)

#define	TIM8_DTR2_DTPE_B_0X0		(0x0u<<17)
#define	TIM8_DTR2_DTPE_B_0X1		(0x1u<<17)
#define	TIM8_DTR2_DTAE_B_0X0		(0x0u<<16)
#define	TIM8_DTR2_DTAE_B_0X1		(0x1u<<16)

// ECR Configuration

#define	TIM8_ECR_PWPRSC				(0x7u<<24)
#define	TIM8_ECR_PWPRSC_0			(0x1u<<24)
#define	TIM8_ECR_PW					(0xFFu<<16)
#define	TIM8_ECR_PW_0				(0x1u<<16)
#define	TIM8_ECR_IPOS				(0x3u<<6)
#define	TIM8_ECR_IPOS_0				(0x1u<<6)
#define	TIM8_ECR_FIDX				(0x1u<<5)
#define	TIM8_ECR_IBLK				(0x3u<<3)
#define	TIM8_ECR_IBLK_0				(0x1u<<3)
#define	TIM8_ECR_IDIR				(0x3u<<1)
#define	TIM8_ECR_IDIR_0				(0x1u<<1)
#define	TIM8_ECR_IE					(0x1u<<0)

#define	TIM8_ECR_IPOS_B_0X0			(0x0u<<6)
#define	TIM8_ECR_IPOS_B_0X1			(0x1u<<6)
#define	TIM8_ECR_IPOS_B_0X2			(0x2u<<6)
#define	TIM8_ECR_IPOS_B_0X3			(0x3u<<6)
#define	TIM8_ECR_FIDX_B_0X0			(0x0u<<5)
#define	TIM8_ECR_FIDX_B_0X1			(0x1u<<5)
#define	TIM8_ECR_IBLK_B_0X0			(0x0u<<3)
#define	TIM8_ECR_IBLK_B_0X1			(0x1u<<3)
#define	TIM8_ECR_IBLK_B_0X2			(0x2u<<3)
#define	TIM8_ECR_IDIR_B_0X0			(0x0u<<1)
#define	TIM8_ECR_IDIR_B_0X1			(0x1u<<1)
#define	TIM8_ECR_IDIR_B_0X2			(0x2u<<1)
#define	TIM8_ECR_IE_B_0X0			(0x0u<<0)
#define	TIM8_ECR_IE_B_0X1			(0x1u<<0)

// TISEL Configuration

#define	TIM8_TISEL_TI4SEL			(0xFu<<24)
#define	TIM8_TISEL_TI4SEL_0			(0x1u<<24)
#define	TIM8_TISEL_TI3SEL			(0xFu<<16)
#define	TIM8_TISEL_TI3SEL_0			(0x1u<<16)
#define	TIM8_TISEL_TI2SEL			(0xFu<<8)
#define	TIM8_TISEL_TI2SEL_0			(0x1u<<8)
#define	TIM8_TISEL_TI1SEL			(0xFu<<0)
#define	TIM8_TISEL_TI1SEL_0			(0x1u<<0)

#define	TIM8_TISEL_TI4SEL_B_0X0		(0x0u<<24)
#define	TIM8_TISEL_TI4SEL_B_0X1		(0x1u<<24)
#define	TIM8_TISEL_TI4SEL_B_0XF		(0xFu<<24)
#define	TIM8_TISEL_TI3SEL_B_0X0		(0x0u<<16)
#define	TIM8_TISEL_TI3SEL_B_0X1		(0x1u<<16)
#define	TIM8_TISEL_TI3SEL_B_0XF		(0xFu<<16)
#define	TIM8_TISEL_TI2SEL_B_0X0		(0x0u<<8)
#define	TIM8_TISEL_TI2SEL_B_0X1		(0x1u<<8)
#define	TIM8_TISEL_TI2SEL_B_0XF		(0xFu<<8)
#define	TIM8_TISEL_TI1SEL_B_0X0		(0x0u<<0)
#define	TIM8_TISEL_TI1SEL_B_0X1		(0x1u<<0)
#define	TIM8_TISEL_TI1SEL_B_0XF		(0xFu<<0)

// AF1 Configuration

#define	TIM8_AF1_ETRSEL				(0xFu<<14)
#define	TIM8_AF1_ETRSEL_0			(0x1u<<14)
#define	TIM8_AF1_BKCMP4P			(0x1u<<13)
#define	TIM8_AF1_BKCMP3P			(0x1u<<12)
#define	TIM8_AF1_BKCMP2P			(0x1u<<11)
#define	TIM8_AF1_BKCMP1P			(0x1u<<10)
#define	TIM8_AF1_BKINP				(0x1u<<9)
#define	TIM8_AF1_BKCMP8E			(0x1u<<8)
#define	TIM8_AF1_BKCMP7E			(0x1u<<7)
#define	TIM8_AF1_BKCMP6E			(0x1u<<6)
#define	TIM8_AF1_BKCMP5E			(0x1u<<5)
#define	TIM8_AF1_BKCMP4E			(0x1u<<4)
#define	TIM8_AF1_BKCMP3E			(0x1u<<3)
#define	TIM8_AF1_BKCMP2E			(0x1u<<2)
#define	TIM8_AF1_BKCMP1E			(0x1u<<1)
#define	TIM8_AF1_BKINE				(0x1u<<0)

#define	TIM8_AF1_ETRSEL_B_0X0		(0x0u<<14)
#define	TIM8_AF1_ETRSEL_B_0X1		(0x1u<<14)
#define	TIM8_AF1_ETRSEL_B_0XF		(0xFu<<14)
#define	TIM8_AF1_BKCMP4P_B_0X0		(0x0u<<13)
#define	TIM8_AF1_BKCMP4P_B_0X1		(0x1u<<13)
#define	TIM8_AF1_BKCMP3P_B_0X0		(0x0u<<12)
#define	TIM8_AF1_BKCMP3P_B_0X1		(0x1u<<12)
#define	TIM8_AF1_BKCMP2P_B_0X0		(0x0u<<11)
#define	TIM8_AF1_BKCMP2P_B_0X1		(0x1u<<11)
#define	TIM8_AF1_BKCMP1P_B_0X0		(0x0u<<10)
#define	TIM8_AF1_BKCMP1P_B_0X1		(0x1u<<10)
#define	TIM8_AF1_BKINP_B_0X0		(0x0u<<9)
#define	TIM8_AF1_BKINP_B_0X1		(0x1u<<9)
#define	TIM8_AF1_BKCMP8E_B_0X0		(0x0u<<8)
#define	TIM8_AF1_BKCMP8E_B_0X1		(0x1u<<8)
#define	TIM8_AF1_BKCMP7E_B_0X0		(0x0u<<7)
#define	TIM8_AF1_BKCMP7E_B_0X1		(0x1u<<7)
#define	TIM8_AF1_BKCMP6E_B_0X0		(0x0u<<6)
#define	TIM8_AF1_BKCMP6E_B_0X1		(0x1u<<6)
#define	TIM8_AF1_BKCMP5E_B_0X0		(0x0u<<5)
#define	TIM8_AF1_BKCMP5E_B_0X1		(0x1u<<5)
#define	TIM8_AF1_BKCMP4E_B_0X0		(0x0u<<4)
#define	TIM8_AF1_BKCMP4E_B_0X1		(0x1u<<4)
#define	TIM8_AF1_BKCMP3E_B_0X0		(0x0u<<3)
#define	TIM8_AF1_BKCMP3E_B_0X1		(0x1u<<3)
#define	TIM8_AF1_BKCMP2E_B_0X0		(0x0u<<2)
#define	TIM8_AF1_BKCMP2E_B_0X1		(0x1u<<2)
#define	TIM8_AF1_BKCMP1E_B_0X0		(0x0u<<1)
#define	TIM8_AF1_BKCMP1E_B_0X1		(0x1u<<1)
#define	TIM8_AF1_BKINE_B_0X0		(0x0u<<0)
#define	TIM8_AF1_BKINE_B_0X1		(0x1u<<0)

// AF2 Configuration

#define	TIM8_AF2_OCRSEL				(0x7u<<16)
#define	TIM8_AF2_OCRSEL_0			(0x1u<<16)
#define	TIM8_AF2_BK2CMP4P			(0x1u<<13)
#define	TIM8_AF2_BK2CMP3P			(0x1u<<12)
#define	TIM8_AF2_BK2CMP2P			(0x1u<<11)
#define	TIM8_AF2_BK2CMP1P			(0x1u<<10)
#define	TIM8_AF2_BK2INP				(0x1u<<9)
#define	TIM8_AF2_BK2CMP8E			(0x1u<<8)
#define	TIM8_AF2_BK2CMP7E			(0x1u<<7)
#define	TIM8_AF2_BK2CMP6E			(0x1u<<6)
#define	TIM8_AF2_BK2CMP5E			(0x1u<<5)
#define	TIM8_AF2_BK2CMP4E			(0x1u<<4)
#define	TIM8_AF2_BK2CMP3E			(0x1u<<3)
#define	TIM8_AF2_BK2CMP2E			(0x1u<<2)
#define	TIM8_AF2_BK2CMP1E			(0x1u<<1)
#define	TIM8_AF2_BK2INE				(0x1u<<0)

#define	TIM8_AF2_OCRSEL_B_0X0		(0x0u<<16)
#define	TIM8_AF2_OCRSEL_B_0X1		(0x1u<<16)
#define	TIM8_AF2_OCRSEL_B_0X7		(0x7u<<16)
#define	TIM8_AF2_BK2CMP4P_B_0X0		(0x0u<<13)
#define	TIM8_AF2_BK2CMP4P_B_0X1		(0x1u<<13)
#define	TIM8_AF2_BK2CMP3P_B_0X0		(0x0u<<12)
#define	TIM8_AF2_BK2CMP3P_B_0X1		(0x1u<<12)
#define	TIM8_AF2_BK2CMP2P_B_0X0		(0x0u<<11)
#define	TIM8_AF2_BK2CMP2P_B_0X1		(0x1u<<11)
#define	TIM8_AF2_BK2CMP1P_B_0X0		(0x0u<<10)
#define	TIM8_AF2_BK2CMP1P_B_0X1		(0x1u<<10)
#define	TIM8_AF2_BK2INP_B_0X0		(0x0u<<9)
#define	TIM8_AF2_BK2INP_B_0X1		(0x1u<<9)
#define	TIM8_AF2_BK2CMP8E_B_0X0		(0x0u<<8)
#define	TIM8_AF2_BK2CMP8E_B_0X1		(0x1u<<8)
#define	TIM8_AF2_BK2CMP7E_B_0X0		(0x0u<<7)
#define	TIM8_AF2_BK2CMP7E_B_0X1		(0x1u<<7)
#define	TIM8_AF2_BK2CMP6E_B_0X0		(0x0u<<6)
#define	TIM8_AF2_BK2CMP6E_B_0X1		(0x1u<<6)
#define	TIM8_AF2_BK2CMP5E_B_0X0		(0x0u<<5)
#define	TIM8_AF2_BK2CMP5E_B_0X1		(0x1u<<5)
#define	TIM8_AF2_BK2CMP4E_B_0X0		(0x0u<<4)
#define	TIM8_AF2_BK2CMP4E_B_0X1		(0x1u<<4)
#define	TIM8_AF2_BK2CMP3E_B_0X0		(0x0u<<3)
#define	TIM8_AF2_BK2CMP3E_B_0X1		(0x1u<<3)
#define	TIM8_AF2_BK2CMP2E_B_0X0		(0x0u<<2)
#define	TIM8_AF2_BK2CMP2E_B_0X1		(0x1u<<2)
#define	TIM8_AF2_BK2CMP1E_B_0X0		(0x0u<<1)
#define	TIM8_AF2_BK2CMP1E_B_0X1		(0x1u<<1)
#define	TIM8_AF2_BK2INE_B_0X0		(0x0u<<0)
#define	TIM8_AF2_BK2INE_B_0X1		(0x1u<<0)

// DCR Configuration

#define	TIM8_DCR_DBSS				(0xFu<<16)
#define	TIM8_DCR_DBSS_0				(0x1u<<16)
#define	TIM8_DCR_DBL				(0x1Fu<<8)
#define	TIM8_DCR_DBL_0				(0x1u<<8)
#define	TIM8_DCR_DBA				(0x1Fu<<0)
#define	TIM8_DCR_DBA_0				(0x1u<<0)

#define	TIM8_DCR_DBSS_B_0X1			(0x1u<<16)
#define	TIM8_DCR_DBSS_B_0X2			(0x2u<<16)
#define	TIM8_DCR_DBSS_B_0X3			(0x3u<<16)
#define	TIM8_DCR_DBSS_B_0X4			(0x4u<<16)
#define	TIM8_DCR_DBSS_B_0X5			(0x5u<<16)
#define	TIM8_DCR_DBSS_B_0X6			(0x6u<<16)
#define	TIM8_DCR_DBSS_B_0X7			(0x7u<<16)
#define	TIM8_DCR_DBL_B_0X0			(0x0u<<8)
#define	TIM8_DCR_DBL_B_0X1			(0x1u<<8)
#define	TIM8_DCR_DBL_B_0X2			(0x2u<<8)
#define	TIM8_DCR_DBL_B_0X1A			(0x1Au<<8)
#define	TIM8_DCR_DBA_B_0X0			(0x0u<<0)
#define	TIM8_DCR_DBA_B_0X1			(0x1u<<0)
#define	TIM8_DCR_DBA_B_0X2			(0x2u<<0)

// DMAR Configuration

#define	TIM8_DMAR_DMAB				(0xFFFFFFFFu<<0)
#define	TIM8_DMAR_DMAB_0			(0x1u<<0)
