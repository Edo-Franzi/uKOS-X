/*
; stm32U5Gx_adc1.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_adc1 equates.
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

// ADC1 address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	ISR;
	volatile	uint32_t	IER;
	volatile	uint32_t	CR;
	volatile	uint32_t	CFGR1;
	volatile	uint32_t	CFGR2;
	volatile	uint32_t	SMPR1;
	volatile	uint32_t	SMPR2;
	volatile	uint32_t	PCSEL;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	SQR1;
	volatile	uint32_t	SQR2;
	volatile	uint32_t	SQR3;
	volatile	uint32_t	SQR4;
	volatile	uint32_t	DR;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	JSQR;
	volatile	uint32_t	RESERVED2[4];
	volatile	uint32_t	OFR1;
	volatile	uint32_t	OFR2;
	volatile	uint32_t	OFR3;
	volatile	uint32_t	OFR4;
	volatile	uint32_t	GCOMP;
	volatile	uint32_t	RESERVED3[3];
	volatile	uint32_t	JDR1;
	volatile	uint32_t	JDR2;
	volatile	uint32_t	JDR3;
	volatile	uint32_t	JDR4;
	volatile	uint32_t	RESERVED4[4];
	volatile	uint32_t	AWD2CR;
	volatile	uint32_t	AWD3CR;
	volatile	uint32_t	LTR1;
	volatile	uint32_t	HTR1;
	volatile	uint32_t	LTR2;
	volatile	uint32_t	HTR2;
	volatile	uint32_t	LTR3;
	volatile	uint32_t	HTR3;
	volatile	uint32_t	DIFSEL;
	volatile	uint32_t	CALFACT;
	volatile	uint32_t	CALFACT2;
} ADC1_TypeDef;

#if (defined(__cplusplus))
#define	ADC1_NS	reinterpret_cast<ADC1_TypeDef *>(0x42028000u)
#define	ADC1_S	reinterpret_cast<ADC1_TypeDef *>(0x52028000u)

#else
#define	ADC1_NS	((ADC1_TypeDef *)0x42028000u)
#define	ADC1_S	((ADC1_TypeDef *)0x52028000u)
#endif

// ISR Configuration

#define	ADC1_ISR_ADRDY				(0x1u<<0)
#define	ADC1_ISR_EOSMP				(0x1u<<1)
#define	ADC1_ISR_EOC				(0x1u<<2)
#define	ADC1_ISR_EOS				(0x1u<<3)
#define	ADC1_ISR_OVR				(0x1u<<4)
#define	ADC1_ISR_JEOC				(0x1u<<5)
#define	ADC1_ISR_JEOS				(0x1u<<6)
#define	ADC1_ISR_AWD1				(0x1u<<7)
#define	ADC1_ISR_AWD2				(0x1u<<8)
#define	ADC1_ISR_AWD3				(0x1u<<9)
#define	ADC1_ISR_LDORDY				(0x1u<<12)

// IER Configuration

#define	ADC1_IER_ADRDYIE			(0x1u<<0)
#define	ADC1_IER_EOSMPIE			(0x1u<<1)
#define	ADC1_IER_EOCIE				(0x1u<<2)
#define	ADC1_IER_EOSIE				(0x1u<<3)
#define	ADC1_IER_OVRIE				(0x1u<<4)
#define	ADC1_IER_JEOCIE				(0x1u<<5)
#define	ADC1_IER_JEOSIE				(0x1u<<6)
#define	ADC1_IER_AWD1IE				(0x1u<<7)
#define	ADC1_IER_AWD2IE				(0x1u<<8)
#define	ADC1_IER_AWD3IE				(0x1u<<9)

// CR Configuration

#define	ADC1_CR_ADEN				(0x1u<<0)
#define	ADC1_CR_ADDIS				(0x1u<<1)
#define	ADC1_CR_ADSTART				(0x1u<<2)
#define	ADC1_CR_JADSTART			(0x1u<<3)
#define	ADC1_CR_ADSTP				(0x1u<<4)
#define	ADC1_CR_JADSTP				(0x1u<<5)
#define	ADC1_CR_ADCALLIN			(0x1u<<16)
#define	ADC1_CR_CALINDEX			(0xFu<<24)
#define	ADC1_CR_CALINDEX_0			(0x1u<<24)
#define	ADC1_CR_ADVREGEN			(0x1u<<28)
#define	ADC1_CR_DEEPPWD				(0x1u<<29)
#define	ADC1_CR_ADCAL				(0x1u<<31)

// CFGR1 Configuration

#define	ADC1_CFGR1_DMNGT			(0x3u<<0)
#define	ADC1_CFGR1_DMNGT_0			(0x1u<<0)
#define	ADC1_CFGR1_RES				(0x3u<<2)
#define	ADC1_CFGR1_RES_0			(0x1u<<2)
#define	ADC1_CFGR1_EXTSEL			(0x1Fu<<5)
#define	ADC1_CFGR1_EXTSEL_0			(0x1u<<5)
#define	ADC1_CFGR1_EXTEN			(0x3u<<10)
#define	ADC1_CFGR1_EXTEN_0			(0x1u<<10)
#define	ADC1_CFGR1_OVRMOD			(0x1u<<12)
#define	ADC1_CFGR1_CONT				(0x1u<<13)
#define	ADC1_CFGR1_AUTDLY			(0x1u<<14)
#define	ADC1_CFGR1_DISCEN			(0x1u<<16)
#define	ADC1_CFGR1_DISCNUM			(0x7u<<17)
#define	ADC1_CFGR1_DISCNUM_0		(0x1u<<17)
#define	ADC1_CFGR1_JDISCEN			(0x1u<<20)
#define	ADC1_CFGR1_AWD1SGL			(0x1u<<22)
#define	ADC1_CFGR1_AWD1EN			(0x1u<<23)
#define	ADC1_CFGR1_JAWD1EN			(0x1u<<24)
#define	ADC1_CFGR1_JAUTO			(0x1u<<25)
#define	ADC1_CFGR1_AWD1CH			(0x1Fu<<26)
#define	ADC1_CFGR1_AWD1CH_0			(0x1u<<26)

// CFGR2 Configuration

#define	ADC1_CFGR2_ROVSE			(0x1u<<0)
#define	ADC1_CFGR2_JOVSE			(0x1u<<1)
#define	ADC1_CFGR2_OVSS				(0xFu<<5)
#define	ADC1_CFGR2_OVSS_0			(0x1u<<5)
#define	ADC1_CFGR2_TROVS			(0x1u<<9)
#define	ADC1_CFGR2_ROVSM			(0x1u<<10)
#define	ADC1_CFGR2_BULB				(0x1u<<13)
#define	ADC1_CFGR2_SWTRIG			(0x1u<<14)
#define	ADC1_CFGR2_SMPTRIG			(0x1u<<15)
#define	ADC1_CFGR2_OSR				(0x3FFu<<16)
#define	ADC1_CFGR2_OSR_0			(0x1u<<16)
#define	ADC1_CFGR2_LFTRIG			(0x1u<<27)
#define	ADC1_CFGR2_LSHIFT			(0xFu<<28)
#define	ADC1_CFGR2_LSHIFT_0			(0x1u<<28)

// SMPR1 Configuration

#define	ADC1_SMPR1_SMP0				(0x7u<<0)
#define	ADC1_SMPR1_SMP0_0			(0x1u<<0)
#define	ADC1_SMPR1_SMP1				(0x7u<<3)
#define	ADC1_SMPR1_SMP1_0			(0x1u<<3)
#define	ADC1_SMPR1_SMP2				(0x7u<<6)
#define	ADC1_SMPR1_SMP2_0			(0x1u<<6)
#define	ADC1_SMPR1_SMP3				(0x7u<<9)
#define	ADC1_SMPR1_SMP3_0			(0x1u<<9)
#define	ADC1_SMPR1_SMP4				(0x7u<<12)
#define	ADC1_SMPR1_SMP4_0			(0x1u<<12)
#define	ADC1_SMPR1_SMP5				(0x7u<<15)
#define	ADC1_SMPR1_SMP5_0			(0x1u<<15)
#define	ADC1_SMPR1_SMP6				(0x7u<<18)
#define	ADC1_SMPR1_SMP6_0			(0x1u<<18)
#define	ADC1_SMPR1_SMP7				(0x7u<<21)
#define	ADC1_SMPR1_SMP7_0			(0x1u<<21)
#define	ADC1_SMPR1_SMP8				(0x7u<<24)
#define	ADC1_SMPR1_SMP8_0			(0x1u<<24)
#define	ADC1_SMPR1_SMP9				(0x7u<<27)
#define	ADC1_SMPR1_SMP9_0			(0x1u<<27)

// SMPR2 Configuration

#define	ADC1_SMPR2_SMP10			(0x7u<<0)
#define	ADC1_SMPR2_SMP10_0			(0x1u<<0)
#define	ADC1_SMPR2_SMP11			(0x7u<<3)
#define	ADC1_SMPR2_SMP11_0			(0x1u<<3)
#define	ADC1_SMPR2_SMP12			(0x7u<<6)
#define	ADC1_SMPR2_SMP12_0			(0x1u<<6)
#define	ADC1_SMPR2_SMP13			(0x7u<<9)
#define	ADC1_SMPR2_SMP13_0			(0x1u<<9)
#define	ADC1_SMPR2_SMP14			(0x7u<<12)
#define	ADC1_SMPR2_SMP14_0			(0x1u<<12)
#define	ADC1_SMPR2_SMP15			(0x7u<<15)
#define	ADC1_SMPR2_SMP15_0			(0x1u<<15)
#define	ADC1_SMPR2_SMP16			(0x7u<<18)
#define	ADC1_SMPR2_SMP16_0			(0x1u<<18)
#define	ADC1_SMPR2_SMP17			(0x7u<<21)
#define	ADC1_SMPR2_SMP17_0			(0x1u<<21)
#define	ADC1_SMPR2_SMP18			(0x7u<<24)
#define	ADC1_SMPR2_SMP18_0			(0x1u<<24)
#define	ADC1_SMPR2_SMP19			(0x7u<<27)
#define	ADC1_SMPR2_SMP19_0			(0x1u<<27)

// PCSEL Configuration

#define	ADC1_PCSEL_PCSEL0			(0x1u<<0)
#define	ADC1_PCSEL_PCSEL1			(0x1u<<1)
#define	ADC1_PCSEL_PCSEL2			(0x1u<<2)
#define	ADC1_PCSEL_PCSEL3			(0x1u<<3)
#define	ADC1_PCSEL_PCSEL4			(0x1u<<4)
#define	ADC1_PCSEL_PCSEL5			(0x1u<<5)
#define	ADC1_PCSEL_PCSEL6			(0x1u<<6)
#define	ADC1_PCSEL_PCSEL7			(0x1u<<7)
#define	ADC1_PCSEL_PCSEL8			(0x1u<<8)
#define	ADC1_PCSEL_PCSEL9			(0x1u<<9)
#define	ADC1_PCSEL_PCSEL10			(0x1u<<10)
#define	ADC1_PCSEL_PCSEL11			(0x1u<<11)
#define	ADC1_PCSEL_PCSEL12			(0x1u<<12)
#define	ADC1_PCSEL_PCSEL13			(0x1u<<13)
#define	ADC1_PCSEL_PCSEL14			(0x1u<<14)
#define	ADC1_PCSEL_PCSEL15			(0x1u<<15)
#define	ADC1_PCSEL_PCSEL16			(0x1u<<16)
#define	ADC1_PCSEL_PCSEL17			(0x1u<<17)
#define	ADC1_PCSEL_PCSEL18			(0x1u<<18)
#define	ADC1_PCSEL_PCSEL19			(0x1u<<19)

// SQR1 Configuration

#define	ADC1_SQR1_L					(0xFu<<0)
#define	ADC1_SQR1_L_0				(0x1u<<0)
#define	ADC1_SQR1_SQ1				(0x1Fu<<6)
#define	ADC1_SQR1_SQ1_0				(0x1u<<6)
#define	ADC1_SQR1_SQ2				(0x1Fu<<12)
#define	ADC1_SQR1_SQ2_0				(0x1u<<12)
#define	ADC1_SQR1_SQ3				(0x1Fu<<18)
#define	ADC1_SQR1_SQ3_0				(0x1u<<18)
#define	ADC1_SQR1_SQ4				(0x1Fu<<24)
#define	ADC1_SQR1_SQ4_0				(0x1u<<24)

// SQR2 Configuration

#define	ADC1_SQR2_SQ5				(0x1Fu<<0)
#define	ADC1_SQR2_SQ5_0				(0x1u<<0)
#define	ADC1_SQR2_SQ6				(0x1Fu<<6)
#define	ADC1_SQR2_SQ6_0				(0x1u<<6)
#define	ADC1_SQR2_SQ7				(0x1Fu<<12)
#define	ADC1_SQR2_SQ7_0				(0x1u<<12)
#define	ADC1_SQR2_SQ8				(0x1Fu<<18)
#define	ADC1_SQR2_SQ8_0				(0x1u<<18)
#define	ADC1_SQR2_SQ9				(0x1Fu<<24)
#define	ADC1_SQR2_SQ9_0				(0x1u<<24)

// SQR3 Configuration

#define	ADC1_SQR3_SQ10				(0x1Fu<<0)
#define	ADC1_SQR3_SQ10_0			(0x1u<<0)
#define	ADC1_SQR3_SQ11				(0x1Fu<<6)
#define	ADC1_SQR3_SQ11_0			(0x1u<<6)
#define	ADC1_SQR3_SQ12				(0x1Fu<<12)
#define	ADC1_SQR3_SQ12_0			(0x1u<<12)
#define	ADC1_SQR3_SQ13				(0x1Fu<<18)
#define	ADC1_SQR3_SQ13_0			(0x1u<<18)
#define	ADC1_SQR3_SQ14				(0x1Fu<<24)
#define	ADC1_SQR3_SQ14_0			(0x1u<<24)

// SQR4 Configuration

#define	ADC1_SQR4_SQ15				(0x1Fu<<0)
#define	ADC1_SQR4_SQ15_0			(0x1u<<0)
#define	ADC1_SQR4_SQ16				(0x1Fu<<6)
#define	ADC1_SQR4_SQ16_0			(0x1u<<6)

// DR Configuration

#define	ADC1_DR_RDATA				(0xFFFFFFFFu<<0)
#define	ADC1_DR_RDATA_0				(0x1u<<0)

// JSQR Configuration

#define	ADC1_JSQR_JL				(0x3u<<0)
#define	ADC1_JSQR_JL_0				(0x1u<<0)
#define	ADC1_JSQR_JEXTSEL			(0x1Fu<<2)
#define	ADC1_JSQR_JEXTSEL_0			(0x1u<<2)
#define	ADC1_JSQR_JEXTEN			(0x3u<<7)
#define	ADC1_JSQR_JEXTEN_0			(0x1u<<7)
#define	ADC1_JSQR_JSQ1				(0x1Fu<<9)
#define	ADC1_JSQR_JSQ1_0			(0x1u<<9)
#define	ADC1_JSQR_JSQ2				(0x1Fu<<15)
#define	ADC1_JSQR_JSQ2_0			(0x1u<<15)
#define	ADC1_JSQR_JSQ3				(0x1Fu<<21)
#define	ADC1_JSQR_JSQ3_0			(0x1u<<21)
#define	ADC1_JSQR_JSQ4				(0x1Fu<<27)
#define	ADC1_JSQR_JSQ4_0			(0x1u<<27)

// OFR1 Configuration

#define	ADC1_OFR1_OFFSET			(0xFFFFFFu<<0)
#define	ADC1_OFR1_OFFSET_0			(0x1u<<0)
#define	ADC1_OFR1_POSOFF			(0x1u<<24)
#define	ADC1_OFR1_USAT				(0x1u<<25)
#define	ADC1_OFR1_SSAT				(0x1u<<26)
#define	ADC1_OFR1_OFFSET_CH			(0x1Fu<<27)
#define	ADC1_OFR1_OFFSET_CH_0		(0x1u<<27)

// OFR2 Configuration

#define	ADC1_OFR2_OFFSET			(0xFFFFFFu<<0)
#define	ADC1_OFR2_OFFSET_0			(0x1u<<0)
#define	ADC1_OFR2_POSOFF			(0x1u<<24)
#define	ADC1_OFR2_USAT				(0x1u<<25)
#define	ADC1_OFR2_SSAT				(0x1u<<26)
#define	ADC1_OFR2_OFFSET_CH			(0x1Fu<<27)
#define	ADC1_OFR2_OFFSET_CH_0		(0x1u<<27)

// OFR3 Configuration

#define	ADC1_OFR3_OFFSET			(0xFFFFFFu<<0)
#define	ADC1_OFR3_OFFSET_0			(0x1u<<0)
#define	ADC1_OFR3_POSOFF			(0x1u<<24)
#define	ADC1_OFR3_USAT				(0x1u<<25)
#define	ADC1_OFR3_SSAT				(0x1u<<26)
#define	ADC1_OFR3_OFFSET_CH			(0x1Fu<<27)
#define	ADC1_OFR3_OFFSET_CH_0		(0x1u<<27)

// OFR4 Configuration

#define	ADC1_OFR4_OFFSET			(0xFFFFFFu<<0)
#define	ADC1_OFR4_OFFSET_0			(0x1u<<0)
#define	ADC1_OFR4_POSOFF			(0x1u<<24)
#define	ADC1_OFR4_USAT				(0x1u<<25)
#define	ADC1_OFR4_SSAT				(0x1u<<26)
#define	ADC1_OFR4_OFFSET_CH			(0x1Fu<<27)
#define	ADC1_OFR4_OFFSET_CH_0		(0x1u<<27)

// GCOMP Configuration

#define	ADC1_GCOMP_GCOMPCOEFF		(0x3FFFu<<0)
#define	ADC1_GCOMP_GCOMPCOEFF_0		(0x1u<<0)
#define	ADC1_GCOMP_GCOMP			(0x1u<<31)

// JDR1 Configuration

#define	ADC1_JDR1_JDATA				(0xFFFFFFFFu<<0)
#define	ADC1_JDR1_JDATA_0			(0x1u<<0)

// JDR2 Configuration

#define	ADC1_JDR2_JDATA				(0xFFFFFFFFu<<0)
#define	ADC1_JDR2_JDATA_0			(0x1u<<0)

// JDR3 Configuration

#define	ADC1_JDR3_JDATA				(0xFFFFFFFFu<<0)
#define	ADC1_JDR3_JDATA_0			(0x1u<<0)

// JDR4 Configuration

#define	ADC1_JDR4_JDATA				(0xFFFFFFFFu<<0)
#define	ADC1_JDR4_JDATA_0			(0x1u<<0)

// AWD2CR Configuration

#define	ADC1_AWD2CR_AWD2CH			(0xFFFFFu<<0)
#define	ADC1_AWD2CR_AWD2CH_0		(0x1u<<0)

// AWD3CR Configuration

#define	ADC1_AWD3CR_AWD3CH			(0xFFFFFu<<0)
#define	ADC1_AWD3CR_AWD3CH_0		(0x1u<<0)

// LTR1 Configuration

#define	ADC1_LTR1_LTR1				(0x1FFFFFFu<<0)
#define	ADC1_LTR1_LTR1_0			(0x1u<<0)

// HTR1 Configuration

#define	ADC1_HTR1_HTR1				(0x1FFFFFFu<<0)
#define	ADC1_HTR1_HTR1_0			(0x1u<<0)
#define	ADC1_HTR1_AWDFILT1			(0x7u<<29)
#define	ADC1_HTR1_AWDFILT1_0		(0x1u<<29)

// LTR2 Configuration

#define	ADC1_LTR2_LTR2				(0x1FFFFFFu<<0)
#define	ADC1_LTR2_LTR2_0			(0x1u<<0)

// HTR2 Configuration

#define	ADC1_HTR2_HTR2				(0x1FFFFFFu<<0)
#define	ADC1_HTR2_HTR2_0			(0x1u<<0)

// LTR3 Configuration

#define	ADC1_LTR3_LTR3				(0x1FFFFFFu<<0)
#define	ADC1_LTR3_LTR3_0			(0x1u<<0)

// HTR3 Configuration

#define	ADC1_HTR3_HTR3				(0x1FFFFFFu<<0)
#define	ADC1_HTR3_HTR3_0			(0x1u<<0)

// DIFSEL Configuration

#define	ADC1_DIFSEL_DIFSEL			(0xFFFFFu<<0)
#define	ADC1_DIFSEL_DIFSEL_0		(0x1u<<0)

// CALFACT Configuration

#define	ADC1_CALFACT_I_APB_ADDR		(0xFFu<<0)
#define	ADC1_CALFACT_I_APB_ADDR_0	(0x1u<<0)
#define	ADC1_CALFACT_I_APB_DATA		(0xFFu<<8)
#define	ADC1_CALFACT_I_APB_DATA_0	(0x1u<<8)
#define	ADC1_CALFACT_VALIDITY		(0x1u<<16)
#define	ADC1_CALFACT_LATCH_COEF		(0x1u<<24)
#define	ADC1_CALFACT_CAPTURE_COEF	(0x1u<<25)

// CALFACT2 Configuration

#define	ADC1_CALFACT2_CALFACT		(0xFFFFFFFFu<<0)
#define	ADC1_CALFACT2_CALFACT_0		(0x1u<<0)
