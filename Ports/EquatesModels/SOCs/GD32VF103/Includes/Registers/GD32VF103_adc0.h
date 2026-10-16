/*
; GD32VF103_adc0.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_adc0 equates.
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

// ADC0 address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	STAT;
	volatile	uint32_t	CTL0;
	volatile	uint32_t	CTL1;
	volatile	uint32_t	SAMPT0;
	volatile	uint32_t	SAMPT1;
	volatile	uint32_t	IOFF0;
	volatile	uint32_t	IOFF1;
	volatile	uint32_t	IOFF2;
	volatile	uint32_t	IOFF3;
	volatile	uint32_t	WDHT;
	volatile	uint32_t	WDLT;
	volatile	uint32_t	RSQ0;
	volatile	uint32_t	RSQ1;
	volatile	uint32_t	RSQ2;
	volatile	uint32_t	ISQ;
	volatile	uint32_t	IDATA0;
	volatile	uint32_t	IDATA1;
	volatile	uint32_t	IDATA2;
	volatile	uint32_t	IDATA3;
	volatile	uint32_t	RDATA;
	volatile	uint32_t	RESERVED0[12];
	volatile	uint32_t	OVSAMPCTL;
} ADC0_TypeDef;

#if (defined(__cplusplus))
#define	ADC0	reinterpret_cast<ADC0_TypeDef *>(0x40012400u)

#else
#define	ADC0	((ADC0_TypeDef *)0x40012400u)
#endif

// STAT Configuration

#define	ADC0_STAT_WDE			(0x1u<<0)
#define	ADC0_STAT_EOC			(0x1u<<1)
#define	ADC0_STAT_EOIC			(0x1u<<2)
#define	ADC0_STAT_STIC			(0x1u<<3)
#define	ADC0_STAT_STRC			(0x1u<<4)

// CTL0 Configuration

#define	ADC0_CTL0_WDCHSEL		(0x1Fu<<0)
#define	ADC0_CTL0_WDCHSEL_0		(0x1u<<0)
#define	ADC0_CTL0_EOCIE			(0x1u<<5)
#define	ADC0_CTL0_WDEIE			(0x1u<<6)
#define	ADC0_CTL0_EOICIE		(0x1u<<7)
#define	ADC0_CTL0_SM			(0x1u<<8)
#define	ADC0_CTL0_WDSC			(0x1u<<9)
#define	ADC0_CTL0_ICA			(0x1u<<10)
#define	ADC0_CTL0_DISRC			(0x1u<<11)
#define	ADC0_CTL0_DISIC			(0x1u<<12)
#define	ADC0_CTL0_DISNUM		(0x7u<<13)
#define	ADC0_CTL0_DISNUM_0		(0x1u<<13)
#define	ADC0_CTL0_SYNCM			(0xFu<<16)
#define	ADC0_CTL0_SYNCM_0		(0x1u<<16)
#define	ADC0_CTL0_IWDEN			(0x1u<<22)
#define	ADC0_CTL0_RWDEN			(0x1u<<23)

// CTL1 Configuration

#define	ADC0_CTL1_ADCON			(0x1u<<0)
#define	ADC0_CTL1_CTN			(0x1u<<1)
#define	ADC0_CTL1_CLB			(0x1u<<2)
#define	ADC0_CTL1_RSTCLB		(0x1u<<3)
#define	ADC0_CTL1_DMA			(0x1u<<8)
#define	ADC0_CTL1_DAL			(0x1u<<11)
#define	ADC0_CTL1_ETSIC			(0x7u<<12)
#define	ADC0_CTL1_ETSIC_0		(0x1u<<12)
#define	ADC0_CTL1_ETEIC			(0x1u<<15)
#define	ADC0_CTL1_ETSRC			(0x7u<<17)
#define	ADC0_CTL1_ETSRC_0		(0x1u<<17)
#define	ADC0_CTL1_ETERC			(0x1u<<20)
#define	ADC0_CTL1_SWICST		(0x1u<<21)
#define	ADC0_CTL1_SWRCST		(0x1u<<22)
#define	ADC0_CTL1_TSVREN		(0x1u<<23)

// SAMPT0 Configuration

#define	ADC0_SAMPT0_SPT17		(0x7u<<21)
#define	ADC0_SAMPT0_SPT17_0		(0x1u<<21)
#define	ADC0_SAMPT0_SPT16		(0x7u<<18)
#define	ADC0_SAMPT0_SPT16_0		(0x1u<<18)
#define	ADC0_SAMPT0_SPT15		(0x7u<<15)
#define	ADC0_SAMPT0_SPT15_0		(0x1u<<15)
#define	ADC0_SAMPT0_SPT14		(0x7u<<12)
#define	ADC0_SAMPT0_SPT14_0		(0x1u<<12)
#define	ADC0_SAMPT0_SPT13		(0x7u<<9)
#define	ADC0_SAMPT0_SPT13_0		(0x1u<<9)
#define	ADC0_SAMPT0_SPT12		(0x7u<<6)
#define	ADC0_SAMPT0_SPT12_0		(0x1u<<6)
#define	ADC0_SAMPT0_SPT11		(0x7u<<3)
#define	ADC0_SAMPT0_SPT11_0		(0x1u<<3)
#define	ADC0_SAMPT0_SPT10		(0x7u<<0)
#define	ADC0_SAMPT0_SPT10_0		(0x1u<<0)

// SAMPT1 Configuration

#define	ADC0_SAMPT1_SPT9		(0x7u<<27)
#define	ADC0_SAMPT1_SPT9_0		(0x1u<<27)
#define	ADC0_SAMPT1_SPT8		(0x7u<<24)
#define	ADC0_SAMPT1_SPT8_0		(0x1u<<24)
#define	ADC0_SAMPT1_SPT7		(0x7u<<21)
#define	ADC0_SAMPT1_SPT7_0		(0x1u<<21)
#define	ADC0_SAMPT1_SPT6		(0x7u<<18)
#define	ADC0_SAMPT1_SPT6_0		(0x1u<<18)
#define	ADC0_SAMPT1_SPT5		(0x7u<<15)
#define	ADC0_SAMPT1_SPT5_0		(0x1u<<15)
#define	ADC0_SAMPT1_SPT4		(0x7u<<12)
#define	ADC0_SAMPT1_SPT4_0		(0x1u<<12)
#define	ADC0_SAMPT1_SPT3		(0x7u<<9)
#define	ADC0_SAMPT1_SPT3_0		(0x1u<<9)
#define	ADC0_SAMPT1_SPT2		(0x7u<<6)
#define	ADC0_SAMPT1_SPT2_0		(0x1u<<6)
#define	ADC0_SAMPT1_SPT1		(0x7u<<3)
#define	ADC0_SAMPT1_SPT1_0		(0x1u<<3)
#define	ADC0_SAMPT1_SPT0		(0x7u<<0)
#define	ADC0_SAMPT1_SPT0_0		(0x1u<<0)

// IOFF0 Configuration

#define	ADC0_IOFF0_IOFF			(0xFFFu<<0)
#define	ADC0_IOFF0_IOFF_0		(0x1u<<0)

// IOFF1 Configuration

#define	ADC0_IOFF1_IOFF			(0xFFFu<<0)
#define	ADC0_IOFF1_IOFF_0		(0x1u<<0)

// IOFF2 Configuration

#define	ADC0_IOFF2_IOFF			(0xFFFu<<0)
#define	ADC0_IOFF2_IOFF_0		(0x1u<<0)

// IOFF3 Configuration

#define	ADC0_IOFF3_IOFF			(0xFFFu<<0)
#define	ADC0_IOFF3_IOFF_0		(0x1u<<0)

// WDHT Configuration

#define	ADC0_WDHT_WDHT			(0xFFFu<<0)
#define	ADC0_WDHT_WDHT_0		(0x1u<<0)

// WDLT Configuration

#define	ADC0_WDLT_WDLT			(0xFFFu<<0)
#define	ADC0_WDLT_WDLT_0		(0x1u<<0)

// RSQ0 Configuration

#define	ADC0_RSQ0_RSQ12			(0x1Fu<<0)
#define	ADC0_RSQ0_RSQ12_0		(0x1u<<0)
#define	ADC0_RSQ0_RSQ13			(0x1Fu<<5)
#define	ADC0_RSQ0_RSQ13_0		(0x1u<<5)
#define	ADC0_RSQ0_RSQ14			(0x1Fu<<10)
#define	ADC0_RSQ0_RSQ14_0		(0x1u<<10)
#define	ADC0_RSQ0_RSQ15			(0x1Fu<<15)
#define	ADC0_RSQ0_RSQ15_0		(0x1u<<15)
#define	ADC0_RSQ0_RL			(0xFu<<20)
#define	ADC0_RSQ0_RL_0			(0x1u<<20)

// RSQ1 Configuration

#define	ADC0_RSQ1_RSQ6			(0x1Fu<<0)
#define	ADC0_RSQ1_RSQ6_0		(0x1u<<0)
#define	ADC0_RSQ1_RSQ7			(0x1Fu<<5)
#define	ADC0_RSQ1_RSQ7_0		(0x1u<<5)
#define	ADC0_RSQ1_RSQ8			(0x1Fu<<10)
#define	ADC0_RSQ1_RSQ8_0		(0x1u<<10)
#define	ADC0_RSQ1_RSQ9			(0x1Fu<<15)
#define	ADC0_RSQ1_RSQ9_0		(0x1u<<15)
#define	ADC0_RSQ1_RSQ10			(0x1Fu<<20)
#define	ADC0_RSQ1_RSQ10_0		(0x1u<<20)
#define	ADC0_RSQ1_RSQ11			(0x1Fu<<25)
#define	ADC0_RSQ1_RSQ11_0		(0x1u<<25)

// RSQ2 Configuration

#define	ADC0_RSQ2_RSQ0			(0x1Fu<<0)
#define	ADC0_RSQ2_RSQ0_0		(0x1u<<0)
#define	ADC0_RSQ2_RSQ1			(0x1Fu<<5)
#define	ADC0_RSQ2_RSQ1_0		(0x1u<<5)
#define	ADC0_RSQ2_RSQ2			(0x1Fu<<10)
#define	ADC0_RSQ2_RSQ2_0		(0x1u<<10)
#define	ADC0_RSQ2_RSQ3			(0x1Fu<<15)
#define	ADC0_RSQ2_RSQ3_0		(0x1u<<15)
#define	ADC0_RSQ2_RSQ4			(0x1Fu<<20)
#define	ADC0_RSQ2_RSQ4_0		(0x1u<<20)
#define	ADC0_RSQ2_RSQ5			(0x1Fu<<25)
#define	ADC0_RSQ2_RSQ5_0		(0x1u<<25)

// ISQ Configuration

#define	ADC0_ISQ_ISQ0			(0x1Fu<<0)
#define	ADC0_ISQ_ISQ0_0			(0x1u<<0)
#define	ADC0_ISQ_ISQ1			(0x1Fu<<5)
#define	ADC0_ISQ_ISQ1_0			(0x1u<<5)
#define	ADC0_ISQ_ISQ2			(0x1Fu<<10)
#define	ADC0_ISQ_ISQ2_0			(0x1u<<10)
#define	ADC0_ISQ_ISQ3			(0x1Fu<<15)
#define	ADC0_ISQ_ISQ3_0			(0x1u<<15)
#define	ADC0_ISQ_IL				(0x3u<<20)
#define	ADC0_ISQ_IL_0			(0x1u<<20)

// IDATA0 Configuration

#define	ADC0_IDATA0_IDATAN		(0xFFFFu<<0)
#define	ADC0_IDATA0_IDATAN_0	(0x1u<<0)

// IDATA1 Configuration

#define	ADC0_IDATA1_IDATAN		(0xFFFFu<<0)
#define	ADC0_IDATA1_IDATAN_0	(0x1u<<0)

// IDATA2 Configuration

#define	ADC0_IDATA2_IDATAN		(0xFFFFu<<0)
#define	ADC0_IDATA2_IDATAN_0	(0x1u<<0)

// IDATA3 Configuration

#define	ADC0_IDATA3_IDATAN		(0xFFFFu<<0)
#define	ADC0_IDATA3_IDATAN_0	(0x1u<<0)

// RDATA Configuration

#define	ADC0_RDATA_RDATA		(0xFFFFu<<0)
#define	ADC0_RDATA_RDATA_0		(0x1u<<0)
#define	ADC0_RDATA_ADC1RDTR		(0xFFFFu<<16)
#define	ADC0_RDATA_ADC1RDTR_0	(0x1u<<16)

// OVSAMPCTL Configuration

#define	ADC0_OVSAMPCTL_OVSEN	(0x1u<<0)
#define	ADC0_OVSAMPCTL_OVSR		(0x7u<<2)
#define	ADC0_OVSAMPCTL_OVSR_0	(0x1u<<2)
#define	ADC0_OVSAMPCTL_OVSS		(0xFu<<5)
#define	ADC0_OVSAMPCTL_OVSS_0	(0x1u<<5)
#define	ADC0_OVSAMPCTL_TOVS		(0x1u<<9)
#define	ADC0_OVSAMPCTL_DRES		(0x3u<<12)
#define	ADC0_OVSAMPCTL_DRES_0	(0x1u<<12)
