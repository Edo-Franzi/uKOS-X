/*
; GD32VF103_timer2.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_timer2 equates.
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

// TIMER2 address definitions
// --------------------------

typedef struct {
	volatile	uint16_t	CTL0;
	volatile	uint16_t	RESERVED0;
	volatile	uint16_t	CTL1;
	volatile	uint16_t	RESERVED1;
	volatile	uint16_t	SMCFG;
	volatile	uint16_t	RESERVED2;
	volatile	uint16_t	DMAINTEN;
	volatile	uint16_t	RESERVED3;
	volatile	uint16_t	INTF;
	volatile	uint16_t	RESERVED4;
	volatile	uint16_t	SWEVG;
	volatile	uint16_t	RESERVED5;
	volatile	uint16_t	CHCTL0;
	volatile	uint16_t	RESERVED6;
	volatile	uint16_t	CHCTL1;
	volatile	uint16_t	RESERVED7;
	volatile	uint16_t	CHCTL2;
	volatile	uint16_t	RESERVED8;
	volatile	uint16_t	CNT;
	volatile	uint16_t	RESERVED9;
	volatile	uint16_t	PSC;
	volatile	uint16_t	RESERVED10;
	volatile	uint16_t	CAR;
	volatile	uint16_t	RESERVED11[3];
	volatile	uint32_t	CH0CV;
	volatile	uint32_t	CH1CV;
	volatile	uint32_t	CH2CV;
	volatile	uint32_t	CH3CV;
	volatile	uint32_t	RESERVED12;
	volatile	uint16_t	DMACFG;
	volatile	uint16_t	RESERVED13;
	volatile	uint32_t	DMATB;
} TIMER2_TypeDef;

#if (defined(__cplusplus))
#define	TIMER2	reinterpret_cast<TIMER2_TypeDef *>(0x40000400u)

#else
#define	TIMER2	((TIMER2_TypeDef *)0x40000400u)
#endif

// CTL0 Configuration

#define	TIMER2_CTL0_CEN				(0x1u<<0)
#define	TIMER2_CTL0_UPDIS			(0x1u<<1)
#define	TIMER2_CTL0_UPS				(0x1u<<2)
#define	TIMER2_CTL0_SPM				(0x1u<<3)
#define	TIMER2_CTL0_DIR				(0x1u<<4)
#define	TIMER2_CTL0_CAM				(0x3u<<5)
#define	TIMER2_CTL0_CAM_0			(0x1u<<5)
#define	TIMER2_CTL0_ARSE			(0x1u<<7)
#define	TIMER2_CTL0_CKDIV			(0x3u<<8)
#define	TIMER2_CTL0_CKDIV_0			(0x1u<<8)

// CTL1 Configuration

#define	TIMER2_CTL1_DMAS			(0x1u<<3)
#define	TIMER2_CTL1_MMC				(0x7u<<4)
#define	TIMER2_CTL1_MMC_0			(0x1u<<4)
#define	TIMER2_CTL1_TI0S			(0x1u<<7)

// SMCFG Configuration

#define	TIMER2_SMCFG_SMC			(0x7u<<0)
#define	TIMER2_SMCFG_SMC_0			(0x1u<<0)
#define	TIMER2_SMCFG_TRGS			(0x7u<<4)
#define	TIMER2_SMCFG_TRGS_0			(0x1u<<4)
#define	TIMER2_SMCFG_MSM			(0x1u<<7)
#define	TIMER2_SMCFG_ETFC			(0xFu<<8)
#define	TIMER2_SMCFG_ETFC_0			(0x1u<<8)
#define	TIMER2_SMCFG_ETPSC			(0x3u<<12)
#define	TIMER2_SMCFG_ETPSC_0		(0x1u<<12)
#define	TIMER2_SMCFG_SMC1			(0x1u<<14)
#define	TIMER2_SMCFG_ETP			(0x1u<<15)

// DMAINTEN Configuration

#define	TIMER2_DMAINTEN_UPIE		(0x1u<<0)
#define	TIMER2_DMAINTEN_CH0IE		(0x1u<<1)
#define	TIMER2_DMAINTEN_CH1IE		(0x1u<<2)
#define	TIMER2_DMAINTEN_CH2IE		(0x1u<<3)
#define	TIMER2_DMAINTEN_CH3IE		(0x1u<<4)
#define	TIMER2_DMAINTEN_TRGIE		(0x1u<<6)
#define	TIMER2_DMAINTEN_UPDEN		(0x1u<<8)
#define	TIMER2_DMAINTEN_CH0DEN		(0x1u<<9)
#define	TIMER2_DMAINTEN_CH1DEN		(0x1u<<10)
#define	TIMER2_DMAINTEN_CH2DEN		(0x1u<<11)
#define	TIMER2_DMAINTEN_CH3DEN		(0x1u<<12)
#define	TIMER2_DMAINTEN_TRGDEN		(0x1u<<14)

// INTF Configuration

#define	TIMER2_INTF_UPIF			(0x1u<<0)
#define	TIMER2_INTF_CH0IF			(0x1u<<1)
#define	TIMER2_INTF_CH1IF			(0x1u<<2)
#define	TIMER2_INTF_CH2IF			(0x1u<<3)
#define	TIMER2_INTF_CH3IF			(0x1u<<4)
#define	TIMER2_INTF_TRGIF			(0x1u<<6)
#define	TIMER2_INTF_CH0OF			(0x1u<<9)
#define	TIMER2_INTF_CH1OF			(0x1u<<10)
#define	TIMER2_INTF_CH2OF			(0x1u<<11)
#define	TIMER2_INTF_CH3OF			(0x1u<<12)

// SWEVG Configuration

#define	TIMER2_SWEVG_UPG			(0x1u<<0)
#define	TIMER2_SWEVG_CH0G			(0x1u<<1)
#define	TIMER2_SWEVG_CH1G			(0x1u<<2)
#define	TIMER2_SWEVG_CH2G			(0x1u<<3)
#define	TIMER2_SWEVG_CH3G			(0x1u<<4)
#define	TIMER2_SWEVG_TRGG			(0x1u<<6)

// CHCTL0 Configuration

#define	TIMER2_CHCTL0_CH0MS			(0x3u<<0)
#define	TIMER2_CHCTL0_CH0MS_0		(0x1u<<0)
#define	TIMER2_CHCTL0_CH0COMFEN		(0x1u<<2)
#define	TIMER2_CHCTL0_CH0COMSEN		(0x1u<<3)
#define	TIMER2_CHCTL0_CH0COMCTL		(0x7u<<4)
#define	TIMER2_CHCTL0_CH0COMCTL_0	(0x1u<<4)
#define	TIMER2_CHCTL0_CH0COMCEN		(0x1u<<7)
#define	TIMER2_CHCTL0_CH1MS			(0x3u<<8)
#define	TIMER2_CHCTL0_CH1MS_0		(0x1u<<8)
#define	TIMER2_CHCTL0_CH1COMFEN		(0x1u<<10)
#define	TIMER2_CHCTL0_CH1COMSEN		(0x1u<<11)
#define	TIMER2_CHCTL0_CH1COMCTL		(0x7u<<12)
#define	TIMER2_CHCTL0_CH1COMCTL_0	(0x1u<<12)
#define	TIMER2_CHCTL0_CH1COMCEN		(0x1u<<15)

// CHCTL1 Configuration

#define	TIMER2_CHCTL1_CH2MS			(0x3u<<0)
#define	TIMER2_CHCTL1_CH2MS_0		(0x1u<<0)
#define	TIMER2_CHCTL1_CH2COMFEN		(0x1u<<2)
#define	TIMER2_CHCTL1_CH2COMSEN		(0x1u<<3)
#define	TIMER2_CHCTL1_CH2COMCTL		(0x7u<<4)
#define	TIMER2_CHCTL1_CH2COMCTL_0	(0x1u<<4)
#define	TIMER2_CHCTL1_CH2COMCEN		(0x1u<<7)
#define	TIMER2_CHCTL1_CH3MS			(0x3u<<8)
#define	TIMER2_CHCTL1_CH3MS_0		(0x1u<<8)
#define	TIMER2_CHCTL1_CH3COMFEN		(0x1u<<10)
#define	TIMER2_CHCTL1_CH3COMSEN		(0x1u<<11)
#define	TIMER2_CHCTL1_CH3COMCTL		(0x7u<<12)
#define	TIMER2_CHCTL1_CH3COMCTL_0	(0x1u<<12)
#define	TIMER2_CHCTL1_CH3COMCEN		(0x1u<<15)

// CHCTL2 Configuration

#define	TIMER2_CHCTL2_CH0EN			(0x1u<<0)
#define	TIMER2_CHCTL2_CH0P			(0x1u<<1)
#define	TIMER2_CHCTL2_CH1EN			(0x1u<<4)
#define	TIMER2_CHCTL2_CH1P			(0x1u<<5)
#define	TIMER2_CHCTL2_CH2EN			(0x1u<<8)
#define	TIMER2_CHCTL2_CH2P			(0x1u<<9)
#define	TIMER2_CHCTL2_CH3EN			(0x1u<<12)
#define	TIMER2_CHCTL2_CH3P			(0x1u<<13)

// CNT Configuration

#define	TIMER2_CNT_CNT				(0xFFFFu<<0)
#define	TIMER2_CNT_CNT_0			(0x1u<<0)

// PSC Configuration

#define	TIMER2_PSC_PSC				(0xFFFFu<<0)
#define	TIMER2_PSC_PSC_0			(0x1u<<0)

// CAR Configuration

#define	TIMER2_CAR_CARL				(0xFFFFu<<0)
#define	TIMER2_CAR_CARL_0			(0x1u<<0)

// CH0CV Configuration

#define	TIMER2_CH0CV_CH0VAL			(0xFFFFu<<0)
#define	TIMER2_CH0CV_CH0VAL_0		(0x1u<<0)

// CH1CV Configuration

#define	TIMER2_CH1CV_CH1VAL			(0xFFFFu<<0)
#define	TIMER2_CH1CV_CH1VAL_0		(0x1u<<0)

// CH2CV Configuration

#define	TIMER2_CH2CV_CH2VAL			(0xFFFFu<<0)
#define	TIMER2_CH2CV_CH2VAL_0		(0x1u<<0)

// CH3CV Configuration

#define	TIMER2_CH3CV_CH3VAL			(0xFFFFu<<0)
#define	TIMER2_CH3CV_CH3VAL_0		(0x1u<<0)

// DMACFG Configuration

#define	TIMER2_DMACFG_DMATA			(0x1Fu<<0)
#define	TIMER2_DMACFG_DMATA_0		(0x1u<<0)
#define	TIMER2_DMACFG_DMATC			(0x1Fu<<8)
#define	TIMER2_DMACFG_DMATC_0		(0x1u<<8)

// DMATB Configuration

#define	TIMER2_DMATB_DMATB			(0xFFFFu<<0)
#define	TIMER2_DMATB_DMATB_0		(0x1u<<0)
