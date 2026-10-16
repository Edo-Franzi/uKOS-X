/*
; stm32U5Gx_adc4.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_adc4 equates.
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

// ADC4 address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	ISR;
	volatile	uint32_t	IER;
	volatile	uint32_t	CR;
	volatile	uint32_t	CFGR1;
	volatile	uint32_t	CFGR2;
	volatile	uint32_t	SMPR;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	AWD1TR;
	volatile	uint32_t	AWD2TR;
		union {
	volatile	uint32_t	CHSELRMOD0;
	volatile	uint32_t	CHSELRMOD1;
		};
	volatile	uint32_t	AWD3TR;
	volatile	uint32_t	RESERVED1[4];
	volatile	uint32_t	DR;
	volatile	uint32_t	PWR;
	volatile	uint32_t	RESERVED2[22];
	volatile	uint32_t	AWD2CR;
	volatile	uint32_t	AWD3CR;
	volatile	uint32_t	RESERVED3[3];
	volatile	uint32_t	CALFACT;
	volatile	uint32_t	RESERVED4[6];
	volatile	uint32_t	OR;
	volatile	uint32_t	RESERVED5[141];
	volatile	uint32_t	CCR;
} ADC4_TypeDef;

#if (defined(__cplusplus))
#define	ADC4_NS	reinterpret_cast<ADC4_TypeDef *>(0x46021000u)
#define	ADC4_S	reinterpret_cast<ADC4_TypeDef *>(0x56021000u)

#else
#define	ADC4_NS	((ADC4_TypeDef *)0x46021000u)
#define	ADC4_S	((ADC4_TypeDef *)0x56021000u)
#endif

// ISR Configuration

#define	ADC4_ISR_ADRDY			(0x1u<<0)
#define	ADC4_ISR_EOSMP			(0x1u<<1)
#define	ADC4_ISR_EOC			(0x1u<<2)
#define	ADC4_ISR_EOS			(0x1u<<3)
#define	ADC4_ISR_OVR			(0x1u<<4)
#define	ADC4_ISR_AWD1			(0x1u<<7)
#define	ADC4_ISR_AWD2			(0x1u<<8)
#define	ADC4_ISR_AWD3			(0x1u<<9)
#define	ADC4_ISR_EOCAL			(0x1u<<11)
#define	ADC4_ISR_LDORDY			(0x1u<<12)

// IER Configuration

#define	ADC4_IER_ADRDYIE		(0x1u<<0)
#define	ADC4_IER_EOSMPIE		(0x1u<<1)
#define	ADC4_IER_EOCIE			(0x1u<<2)
#define	ADC4_IER_EOSIE			(0x1u<<3)
#define	ADC4_IER_OVRIE			(0x1u<<4)
#define	ADC4_IER_AWD1IE			(0x1u<<7)
#define	ADC4_IER_AWD2IE			(0x1u<<8)
#define	ADC4_IER_AWD3IE			(0x1u<<9)
#define	ADC4_IER_EOCALIE		(0x1u<<11)
#define	ADC4_IER_LDORDYIE		(0x1u<<12)

// CR Configuration

#define	ADC4_CR_ADEN			(0x1u<<0)
#define	ADC4_CR_ADDIS			(0x1u<<1)
#define	ADC4_CR_ADSTART			(0x1u<<2)
#define	ADC4_CR_ADSTP			(0x1u<<4)
#define	ADC4_CR_ADVREGEN		(0x1u<<28)
#define	ADC4_CR_ADCAL			(0x1u<<31)

// CFGR1 Configuration

#define	ADC4_CFGR1_DMAEN		(0x1u<<0)
#define	ADC4_CFGR1_DMACFG		(0x1u<<1)
#define	ADC4_CFGR1_RES			(0x3u<<2)
#define	ADC4_CFGR1_RES_0		(0x1u<<2)
#define	ADC4_CFGR1_SCANDIR		(0x1u<<4)
#define	ADC4_CFGR1_ALIGN		(0x1u<<5)
#define	ADC4_CFGR1_EXTSEL		(0x7u<<6)
#define	ADC4_CFGR1_EXTSEL_0		(0x1u<<6)
#define	ADC4_CFGR1_EXTEN		(0x3u<<10)
#define	ADC4_CFGR1_EXTEN_0		(0x1u<<10)
#define	ADC4_CFGR1_OVRMOD		(0x1u<<12)
#define	ADC4_CFGR1_CONT			(0x1u<<13)
#define	ADC4_CFGR1_WAIT			(0x1u<<14)
#define	ADC4_CFGR1_DISCEN		(0x1u<<16)
#define	ADC4_CFGR1_CHSELRMOD	(0x1u<<21)
#define	ADC4_CFGR1_AWD1SGL		(0x1u<<22)
#define	ADC4_CFGR1_AWD1EN		(0x1u<<23)
#define	ADC4_CFGR1_AWD1CH		(0x1Fu<<26)
#define	ADC4_CFGR1_AWD1CH_0		(0x1u<<26)

// CFGR2 Configuration

#define	ADC4_CFGR2_OVSE			(0x1u<<0)
#define	ADC4_CFGR2_OVSR			(0x7u<<2)
#define	ADC4_CFGR2_OVSR_0		(0x1u<<2)
#define	ADC4_CFGR2_OVSS			(0xFu<<5)
#define	ADC4_CFGR2_OVSS_0		(0x1u<<5)
#define	ADC4_CFGR2_TOVS			(0x1u<<9)
#define	ADC4_CFGR2_LFTRIG		(0x1u<<29)

// SMPR Configuration

#define	ADC4_SMPR_SMP1			(0x7u<<0)
#define	ADC4_SMPR_SMP1_0		(0x1u<<0)
#define	ADC4_SMPR_SMP2			(0x7u<<4)
#define	ADC4_SMPR_SMP2_0		(0x1u<<4)
#define	ADC4_SMPR_SMPSEL0		(0x1u<<8)
#define	ADC4_SMPR_SMPSEL1		(0x1u<<9)
#define	ADC4_SMPR_SMPSEL2		(0x1u<<10)
#define	ADC4_SMPR_SMPSEL3		(0x1u<<11)
#define	ADC4_SMPR_SMPSEL4		(0x1u<<12)
#define	ADC4_SMPR_SMPSEL5		(0x1u<<13)
#define	ADC4_SMPR_SMPSEL6		(0x1u<<14)
#define	ADC4_SMPR_SMPSEL7		(0x1u<<15)
#define	ADC4_SMPR_SMPSEL8		(0x1u<<16)
#define	ADC4_SMPR_SMPSEL9		(0x1u<<17)
#define	ADC4_SMPR_SMPSEL10		(0x1u<<18)
#define	ADC4_SMPR_SMPSEL11		(0x1u<<19)
#define	ADC4_SMPR_SMPSEL12		(0x1u<<20)
#define	ADC4_SMPR_SMPSEL13		(0x1u<<21)
#define	ADC4_SMPR_SMPSEL14		(0x1u<<22)
#define	ADC4_SMPR_SMPSEL15		(0x1u<<23)
#define	ADC4_SMPR_SMPSEL16		(0x1u<<24)
#define	ADC4_SMPR_SMPSEL17		(0x1u<<25)
#define	ADC4_SMPR_SMPSEL18		(0x1u<<26)
#define	ADC4_SMPR_SMPSEL19		(0x1u<<27)
#define	ADC4_SMPR_SMPSEL20		(0x1u<<28)
#define	ADC4_SMPR_SMPSEL21		(0x1u<<29)
#define	ADC4_SMPR_SMPSEL22		(0x1u<<30)
#define	ADC4_SMPR_SMPSEL23		(0x1u<<31)

// AWD1TR Configuration

#define	ADC4_AWD1TR_LT1			(0xFFFu<<0)
#define	ADC4_AWD1TR_LT1_0		(0x1u<<0)
#define	ADC4_AWD1TR_HT1			(0xFFFu<<16)
#define	ADC4_AWD1TR_HT1_0		(0x1u<<16)

// AWD2TR Configuration

#define	ADC4_AWD2TR_LT2			(0xFFFu<<0)
#define	ADC4_AWD2TR_LT2_0		(0x1u<<0)
#define	ADC4_AWD2TR_HT2			(0xFFFu<<16)
#define	ADC4_AWD2TR_HT2_0		(0x1u<<16)

// CHSELRMOD0 Configuration

#define	ADC4_CHSELRMOD0_CHSEL	(0xFFFFFFu<<0)
#define	ADC4_CHSELRMOD0_CHSEL_0	(0x1u<<0)

// CHSELRMOD1 Configuration

#define	ADC4_CHSELRMOD1_SQ1		(0xFu<<0)
#define	ADC4_CHSELRMOD1_SQ1_0	(0x1u<<0)
#define	ADC4_CHSELRMOD1_SQ2		(0xFu<<4)
#define	ADC4_CHSELRMOD1_SQ2_0	(0x1u<<4)
#define	ADC4_CHSELRMOD1_SQ3		(0xFu<<8)
#define	ADC4_CHSELRMOD1_SQ3_0	(0x1u<<8)
#define	ADC4_CHSELRMOD1_SQ4		(0xFu<<12)
#define	ADC4_CHSELRMOD1_SQ4_0	(0x1u<<12)
#define	ADC4_CHSELRMOD1_SQ5		(0xFu<<16)
#define	ADC4_CHSELRMOD1_SQ5_0	(0x1u<<16)
#define	ADC4_CHSELRMOD1_SQ6		(0xFu<<20)
#define	ADC4_CHSELRMOD1_SQ6_0	(0x1u<<20)
#define	ADC4_CHSELRMOD1_SQ7		(0xFu<<24)
#define	ADC4_CHSELRMOD1_SQ7_0	(0x1u<<24)
#define	ADC4_CHSELRMOD1_SQ8		(0xFu<<28)
#define	ADC4_CHSELRMOD1_SQ8_0	(0x1u<<28)

// AWD3TR Configuration

#define	ADC4_AWD3TR_LT3			(0xFFFu<<0)
#define	ADC4_AWD3TR_LT3_0		(0x1u<<0)
#define	ADC4_AWD3TR_HT3			(0xFFFu<<16)
#define	ADC4_AWD3TR_HT3_0		(0x1u<<16)

// DR Configuration

#define	ADC4_DR_DATA			(0xFFFFu<<0)
#define	ADC4_DR_DATA_0			(0x1u<<0)

// PWR Configuration

#define	ADC4_PWR_AUTOFF			(0x1u<<0)
#define	ADC4_PWR_DPD			(0x1u<<1)
#define	ADC4_PWR_VREFPROT		(0x1u<<2)
#define	ADC4_PWR_VREFSECSMP		(0x1u<<3)

// AWD2CR Configuration

#define	ADC4_AWD2CR_AWD2CH0		(0x1u<<0)
#define	ADC4_AWD2CR_AWD2CH1		(0x1u<<1)
#define	ADC4_AWD2CR_AWD2CH2		(0x1u<<2)
#define	ADC4_AWD2CR_AWD2CH3		(0x1u<<3)
#define	ADC4_AWD2CR_AWD2CH4		(0x1u<<4)
#define	ADC4_AWD2CR_AWD2CH5		(0x1u<<5)
#define	ADC4_AWD2CR_AWD2CH6		(0x1u<<6)
#define	ADC4_AWD2CR_AWD2CH7		(0x1u<<7)
#define	ADC4_AWD2CR_AWD2CH8		(0x1u<<8)
#define	ADC4_AWD2CR_AWD2CH9		(0x1u<<9)
#define	ADC4_AWD2CR_AWD2CH10	(0x1u<<10)
#define	ADC4_AWD2CR_AWD2CH11	(0x1u<<11)
#define	ADC4_AWD2CR_AWD2CH12	(0x1u<<12)
#define	ADC4_AWD2CR_AWD2CH13	(0x1u<<13)
#define	ADC4_AWD2CR_AWD2CH14	(0x1u<<14)
#define	ADC4_AWD2CR_AWD2CH15	(0x1u<<15)
#define	ADC4_AWD2CR_AWD2CH16	(0x1u<<16)
#define	ADC4_AWD2CR_AWD2CH17	(0x1u<<17)
#define	ADC4_AWD2CR_AWD2CH18	(0x1u<<18)
#define	ADC4_AWD2CR_AWD2CH19	(0x1u<<19)
#define	ADC4_AWD2CR_AWD2CH20	(0x1u<<20)
#define	ADC4_AWD2CR_AWD2CH21	(0x1u<<21)
#define	ADC4_AWD2CR_AWD2CH22	(0x1u<<22)
#define	ADC4_AWD2CR_AWD2CH23	(0x1u<<23)

// AWD3CR Configuration

#define	ADC4_AWD3CR_AWD3CH0		(0x1u<<0)
#define	ADC4_AWD3CR_AWD3CH1		(0x1u<<1)
#define	ADC4_AWD3CR_AWD3CH2		(0x1u<<2)
#define	ADC4_AWD3CR_AWD3CH3		(0x1u<<3)
#define	ADC4_AWD3CR_AWD3CH4		(0x1u<<4)
#define	ADC4_AWD3CR_AWD3CH5		(0x1u<<5)
#define	ADC4_AWD3CR_AWD3CH6		(0x1u<<6)
#define	ADC4_AWD3CR_AWD3CH7		(0x1u<<7)
#define	ADC4_AWD3CR_AWD3CH8		(0x1u<<8)
#define	ADC4_AWD3CR_AWD3CH9		(0x1u<<9)
#define	ADC4_AWD3CR_AWD3CH10	(0x1u<<10)
#define	ADC4_AWD3CR_AWD3CH11	(0x1u<<11)
#define	ADC4_AWD3CR_AWD3CH12	(0x1u<<12)
#define	ADC4_AWD3CR_AWD3CH13	(0x1u<<13)
#define	ADC4_AWD3CR_AWD3CH14	(0x1u<<14)
#define	ADC4_AWD3CR_AWD3CH15	(0x1u<<15)
#define	ADC4_AWD3CR_AWD3CH16	(0x1u<<16)
#define	ADC4_AWD3CR_AWD3CH17	(0x1u<<17)
#define	ADC4_AWD3CR_AWD3CH18	(0x1u<<18)
#define	ADC4_AWD3CR_AWD3CH19	(0x1u<<19)
#define	ADC4_AWD3CR_AWD3CH20	(0x1u<<20)
#define	ADC4_AWD3CR_AWD3CH21	(0x1u<<21)
#define	ADC4_AWD3CR_AWD3CH22	(0x1u<<22)
#define	ADC4_AWD3CR_AWD3CH23	(0x1u<<23)

// CALFACT Configuration

#define	ADC4_CALFACT_CALFACT	(0x7Fu<<0)
#define	ADC4_CALFACT_CALFACT_0	(0x1u<<0)

// OR Configuration

#define	ADC4_OR_CHN21SEL		(0x1u<<0)

// CCR Configuration

#define	ADC4_CCR_PRESC			(0xFu<<18)
#define	ADC4_CCR_PRESC_0		(0x1u<<18)
#define	ADC4_CCR_VREFEN			(0x1u<<22)
#define	ADC4_CCR_TSEN			(0x1u<<23)
#define	ADC4_CCR_VBATEN			(0x1u<<24)
