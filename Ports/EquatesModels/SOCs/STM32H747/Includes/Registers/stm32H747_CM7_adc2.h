/*
; stm32H747_CM7_adc2.
; ===================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM7_adc2 equates.
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

// ADC2 address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	ISR;
	volatile	uint32_t	IER;
	volatile	uint32_t	CR;
	volatile	uint32_t	CFGR;
	volatile	uint32_t	CFGR2;
	volatile	uint32_t	SMPR1;
	volatile	uint32_t	SMPR2;
	volatile	uint32_t	PCSEL;
	volatile	uint32_t	LTR1;
	volatile	uint32_t	LHTR1;
	volatile	uint32_t	RESERVED0[2];
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
	volatile	uint32_t	RESERVED3[4];
	volatile	uint32_t	JDR1;
	volatile	uint32_t	JDR2;
	volatile	uint32_t	JDR3;
	volatile	uint32_t	JDR4;
	volatile	uint32_t	RESERVED4[4];
	volatile	uint32_t	AWD2CR;
	volatile	uint32_t	AWD3CR;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	LTR2;
	volatile	uint32_t	HTR2;
	volatile	uint32_t	LTR3;
	volatile	uint32_t	HTR3;
	volatile	uint32_t	DIFSEL;
	volatile	uint32_t	CALFACT;
	volatile	uint32_t	CALFACT2;
} ADC2_TypeDef;

#if (defined(__cplusplus))
#define	ADC2	reinterpret_cast<ADC2_TypeDef *>(0x40022100u)

#else
#define	ADC2	((ADC2_TypeDef *)0x40022100u)
#endif

// ISR Configuration

#define	ADC2_ISR_ADRDY				(0x1u<<0)
#define	ADC2_ISR_EOSMP				(0x1u<<1)
#define	ADC2_ISR_EOC				(0x1u<<2)
#define	ADC2_ISR_EOS				(0x1u<<3)
#define	ADC2_ISR_OVR				(0x1u<<4)
#define	ADC2_ISR_JEOC				(0x1u<<5)
#define	ADC2_ISR_JEOS				(0x1u<<6)
#define	ADC2_ISR_AWD1				(0x1u<<7)
#define	ADC2_ISR_AWD2				(0x1u<<8)
#define	ADC2_ISR_AWD3				(0x1u<<9)
#define	ADC2_ISR_JQOVF				(0x1u<<10)

// IER Configuration

#define	ADC2_IER_ADRDYIE			(0x1u<<0)
#define	ADC2_IER_EOSMPIE			(0x1u<<1)
#define	ADC2_IER_EOCIE				(0x1u<<2)
#define	ADC2_IER_EOSIE				(0x1u<<3)
#define	ADC2_IER_OVRIE				(0x1u<<4)
#define	ADC2_IER_JEOCIE				(0x1u<<5)
#define	ADC2_IER_JEOSIE				(0x1u<<6)
#define	ADC2_IER_AWD1IE				(0x1u<<7)
#define	ADC2_IER_AWD2IE				(0x1u<<8)
#define	ADC2_IER_AWD3IE				(0x1u<<9)
#define	ADC2_IER_JQOVFIE			(0x1u<<10)

// CR Configuration

#define	ADC2_CR_ADEN				(0x1u<<0)
#define	ADC2_CR_ADDIS				(0x1u<<1)
#define	ADC2_CR_ADSTART				(0x1u<<2)
#define	ADC2_CR_JADSTART			(0x1u<<3)
#define	ADC2_CR_ADSTP				(0x1u<<4)
#define	ADC2_CR_JADSTP				(0x1u<<5)
#define	ADC2_CR_BOOST				(0x3u<<8)
#define	ADC2_CR_BOOST_0				(0x1u<<8)
#define	ADC2_CR_ADCALLIN			(0x1u<<16)
#define	ADC2_CR_LINCALRDYW1			(0x1u<<22)
#define	ADC2_CR_LINCALRDYW2			(0x1u<<23)
#define	ADC2_CR_LINCALRDYW3			(0x1u<<24)
#define	ADC2_CR_LINCALRDYW4			(0x1u<<25)
#define	ADC2_CR_LINCALRDYW5			(0x1u<<26)
#define	ADC2_CR_LINCALRDYW6			(0x1u<<27)
#define	ADC2_CR_ADVREGEN			(0x1u<<28)
#define	ADC2_CR_DEEPPWD				(0x1u<<29)
#define	ADC2_CR_ADCALDIF			(0x1u<<30)
#define	ADC2_CR_ADCAL				(0x1u<<31)

// CFGR Configuration

#define	ADC2_CFGR_DMNGT				(0x3u<<0)
#define	ADC2_CFGR_DMNGT_0			(0x1u<<0)
#define	ADC2_CFGR_RES				(0x7u<<2)
#define	ADC2_CFGR_RES_0				(0x1u<<2)
#define	ADC2_CFGR_EXTSEL			(0x1Fu<<5)
#define	ADC2_CFGR_EXTSEL_0			(0x1u<<5)
#define	ADC2_CFGR_EXTEN				(0x3u<<10)
#define	ADC2_CFGR_EXTEN_0			(0x1u<<10)
#define	ADC2_CFGR_OVRMOD			(0x1u<<12)
#define	ADC2_CFGR_CONT				(0x1u<<13)
#define	ADC2_CFGR_AUTDLY			(0x1u<<14)
#define	ADC2_CFGR_DISCEN			(0x1u<<16)
#define	ADC2_CFGR_DISCNUM			(0x7u<<17)
#define	ADC2_CFGR_DISCNUM_0			(0x1u<<17)
#define	ADC2_CFGR_JDISCEN			(0x1u<<20)
#define	ADC2_CFGR_JQM				(0x1u<<21)
#define	ADC2_CFGR_AWD1SGL			(0x1u<<22)
#define	ADC2_CFGR_AWD1EN			(0x1u<<23)
#define	ADC2_CFGR_JAWD1EN			(0x1u<<24)
#define	ADC2_CFGR_JAUTO				(0x1u<<25)
#define	ADC2_CFGR_AWDCH1CH			(0x1Fu<<26)
#define	ADC2_CFGR_AWDCH1CH_0		(0x1u<<26)
#define	ADC2_CFGR_JQDIS				(0x1u<<31)

// CFGR2 Configuration

#define	ADC2_CFGR2_LSHIFT			(0xFu<<28)
#define	ADC2_CFGR2_LSHIFT_0			(0x1u<<28)
#define	ADC2_CFGR2_OSR				(0x3FFu<<16)
#define	ADC2_CFGR2_OSR_0			(0x1u<<16)
#define	ADC2_CFGR2_RSHIFT4			(0x1u<<14)
#define	ADC2_CFGR2_RSHIFT3			(0x1u<<13)
#define	ADC2_CFGR2_RSHIFT2			(0x1u<<12)
#define	ADC2_CFGR2_RSHIFT1			(0x1u<<11)
#define	ADC2_CFGR2_ROVSM			(0x1u<<10)
#define	ADC2_CFGR2_TROVS			(0x1u<<9)
#define	ADC2_CFGR2_OVSS				(0xFu<<5)
#define	ADC2_CFGR2_OVSS_0			(0x1u<<5)
#define	ADC2_CFGR2_JOVSE			(0x1u<<1)
#define	ADC2_CFGR2_ROVSE			(0x1u<<0)

// SMPR1 Configuration

#define	ADC2_SMPR1_SMP1				(0x7u<<3)
#define	ADC2_SMPR1_SMP1_0			(0x1u<<3)
#define	ADC2_SMPR1_SMP2				(0x7u<<6)
#define	ADC2_SMPR1_SMP2_0			(0x1u<<6)
#define	ADC2_SMPR1_SMP3				(0x7u<<9)
#define	ADC2_SMPR1_SMP3_0			(0x1u<<9)
#define	ADC2_SMPR1_SMP4				(0x7u<<12)
#define	ADC2_SMPR1_SMP4_0			(0x1u<<12)
#define	ADC2_SMPR1_SMP5				(0x7u<<15)
#define	ADC2_SMPR1_SMP5_0			(0x1u<<15)
#define	ADC2_SMPR1_SMP6				(0x7u<<18)
#define	ADC2_SMPR1_SMP6_0			(0x1u<<18)
#define	ADC2_SMPR1_SMP7				(0x7u<<21)
#define	ADC2_SMPR1_SMP7_0			(0x1u<<21)
#define	ADC2_SMPR1_SMP8				(0x7u<<24)
#define	ADC2_SMPR1_SMP8_0			(0x1u<<24)
#define	ADC2_SMPR1_SMP9				(0x7u<<27)
#define	ADC2_SMPR1_SMP9_0			(0x1u<<27)

// SMPR2 Configuration

#define	ADC2_SMPR2_SMP10			(0x7u<<0)
#define	ADC2_SMPR2_SMP10_0			(0x1u<<0)
#define	ADC2_SMPR2_SMP11			(0x7u<<3)
#define	ADC2_SMPR2_SMP11_0			(0x1u<<3)
#define	ADC2_SMPR2_SMP12			(0x7u<<6)
#define	ADC2_SMPR2_SMP12_0			(0x1u<<6)
#define	ADC2_SMPR2_SMP13			(0x7u<<9)
#define	ADC2_SMPR2_SMP13_0			(0x1u<<9)
#define	ADC2_SMPR2_SMP14			(0x7u<<12)
#define	ADC2_SMPR2_SMP14_0			(0x1u<<12)
#define	ADC2_SMPR2_SMP15			(0x7u<<15)
#define	ADC2_SMPR2_SMP15_0			(0x1u<<15)
#define	ADC2_SMPR2_SMP16			(0x7u<<18)
#define	ADC2_SMPR2_SMP16_0			(0x1u<<18)
#define	ADC2_SMPR2_SMP17			(0x7u<<21)
#define	ADC2_SMPR2_SMP17_0			(0x1u<<21)
#define	ADC2_SMPR2_SMP18			(0x7u<<24)
#define	ADC2_SMPR2_SMP18_0			(0x1u<<24)
#define	ADC2_SMPR2_SMP19			(0x7u<<27)
#define	ADC2_SMPR2_SMP19_0			(0x1u<<27)

// PCSEL Configuration

#define	ADC2_PCSEL_PCSEL			(0xFFFFFu<<0)
#define	ADC2_PCSEL_PCSEL_0			(0x1u<<0)

// LTR1 Configuration

#define	ADC2_LTR1_LTR1				(0x3FFFFFFu<<0)
#define	ADC2_LTR1_LTR1_0			(0x1u<<0)

// LHTR1 Configuration

#define	ADC2_LHTR1_LHTR1			(0x3FFFFFFu<<0)
#define	ADC2_LHTR1_LHTR1_0			(0x1u<<0)

// SQR1 Configuration

#define	ADC2_SQR1_L3				(0xFu<<0)
#define	ADC2_SQR1_L3_0				(0x1u<<0)
#define	ADC2_SQR1_SQ1				(0x1Fu<<6)
#define	ADC2_SQR1_SQ1_0				(0x1u<<6)
#define	ADC2_SQR1_SQ2				(0x1Fu<<12)
#define	ADC2_SQR1_SQ2_0				(0x1u<<12)
#define	ADC2_SQR1_SQ3				(0x1Fu<<18)
#define	ADC2_SQR1_SQ3_0				(0x1u<<18)
#define	ADC2_SQR1_SQ4				(0x1Fu<<24)
#define	ADC2_SQR1_SQ4_0				(0x1u<<24)

// SQR2 Configuration

#define	ADC2_SQR2_SQ5				(0x1Fu<<0)
#define	ADC2_SQR2_SQ5_0				(0x1u<<0)
#define	ADC2_SQR2_SQ6				(0x1Fu<<6)
#define	ADC2_SQR2_SQ6_0				(0x1u<<6)
#define	ADC2_SQR2_SQ7				(0x1Fu<<12)
#define	ADC2_SQR2_SQ7_0				(0x1u<<12)
#define	ADC2_SQR2_SQ8				(0x1Fu<<18)
#define	ADC2_SQR2_SQ8_0				(0x1u<<18)
#define	ADC2_SQR2_SQ9				(0x1Fu<<24)
#define	ADC2_SQR2_SQ9_0				(0x1u<<24)

// SQR3 Configuration

#define	ADC2_SQR3_SQ10				(0x1Fu<<0)
#define	ADC2_SQR3_SQ10_0			(0x1u<<0)
#define	ADC2_SQR3_SQ11				(0x1Fu<<6)
#define	ADC2_SQR3_SQ11_0			(0x1u<<6)
#define	ADC2_SQR3_SQ12				(0x1Fu<<12)
#define	ADC2_SQR3_SQ12_0			(0x1u<<12)
#define	ADC2_SQR3_SQ13				(0x1Fu<<18)
#define	ADC2_SQR3_SQ13_0			(0x1u<<18)
#define	ADC2_SQR3_SQ14				(0x1Fu<<24)
#define	ADC2_SQR3_SQ14_0			(0x1u<<24)

// SQR4 Configuration

#define	ADC2_SQR4_SQ15				(0x1Fu<<0)
#define	ADC2_SQR4_SQ15_0			(0x1u<<0)
#define	ADC2_SQR4_SQ16				(0x1Fu<<6)
#define	ADC2_SQR4_SQ16_0			(0x1u<<6)

// DR Configuration

#define	ADC2_DR_RDATA				(0xFFFFu<<0)
#define	ADC2_DR_RDATA_0				(0x1u<<0)

// JSQR Configuration

#define	ADC2_JSQR_JL				(0x3u<<0)
#define	ADC2_JSQR_JL_0				(0x1u<<0)
#define	ADC2_JSQR_JEXTSEL			(0x1Fu<<2)
#define	ADC2_JSQR_JEXTSEL_0			(0x1u<<2)
#define	ADC2_JSQR_JEXTEN			(0x3u<<7)
#define	ADC2_JSQR_JEXTEN_0			(0x1u<<7)
#define	ADC2_JSQR_JSQ1				(0x1Fu<<9)
#define	ADC2_JSQR_JSQ1_0			(0x1u<<9)
#define	ADC2_JSQR_JSQ2				(0x1Fu<<15)
#define	ADC2_JSQR_JSQ2_0			(0x1u<<15)
#define	ADC2_JSQR_JSQ3				(0x1Fu<<21)
#define	ADC2_JSQR_JSQ3_0			(0x1u<<21)
#define	ADC2_JSQR_JSQ4				(0x1Fu<<27)
#define	ADC2_JSQR_JSQ4_0			(0x1u<<27)

// OFR1 Configuration

#define	ADC2_OFR1_OFFSET1			(0x3FFFFFFu<<0)
#define	ADC2_OFR1_OFFSET1_0			(0x1u<<0)
#define	ADC2_OFR1_OFFSET1_CH		(0x1Fu<<26)
#define	ADC2_OFR1_OFFSET1_CH_0		(0x1u<<26)
#define	ADC2_OFR1_SSATE				(0x1u<<31)

// OFR2 Configuration

#define	ADC2_OFR2_OFFSET1			(0x3FFFFFFu<<0)
#define	ADC2_OFR2_OFFSET1_0			(0x1u<<0)
#define	ADC2_OFR2_OFFSET1_CH		(0x1Fu<<26)
#define	ADC2_OFR2_OFFSET1_CH_0		(0x1u<<26)
#define	ADC2_OFR2_SSATE				(0x1u<<31)

// OFR3 Configuration

#define	ADC2_OFR3_OFFSET1			(0x3FFFFFFu<<0)
#define	ADC2_OFR3_OFFSET1_0			(0x1u<<0)
#define	ADC2_OFR3_OFFSET1_CH		(0x1Fu<<26)
#define	ADC2_OFR3_OFFSET1_CH_0		(0x1u<<26)
#define	ADC2_OFR3_SSATE				(0x1u<<31)

// OFR4 Configuration

#define	ADC2_OFR4_OFFSET1			(0x3FFFFFFu<<0)
#define	ADC2_OFR4_OFFSET1_0			(0x1u<<0)
#define	ADC2_OFR4_OFFSET1_CH		(0x1Fu<<26)
#define	ADC2_OFR4_OFFSET1_CH_0		(0x1u<<26)
#define	ADC2_OFR4_SSATE				(0x1u<<31)

// JDR1 Configuration

#define	ADC2_JDR1_JDATA1			(0xFFFFFFFFu<<0)
#define	ADC2_JDR1_JDATA1_0			(0x1u<<0)

// JDR2 Configuration

#define	ADC2_JDR2_JDATA2			(0xFFFFFFFFu<<0)
#define	ADC2_JDR2_JDATA2_0			(0x1u<<0)

// JDR3 Configuration

#define	ADC2_JDR3_JDATA3			(0xFFFFFFFFu<<0)
#define	ADC2_JDR3_JDATA3_0			(0x1u<<0)

// JDR4 Configuration

#define	ADC2_JDR4_JDATA4			(0xFFFFFFFFu<<0)
#define	ADC2_JDR4_JDATA4_0			(0x1u<<0)

// AWD2CR Configuration

#define	ADC2_AWD2CR_AWD2CH			(0xFFFFFu<<0)
#define	ADC2_AWD2CR_AWD2CH_0		(0x1u<<0)

// AWD3CR Configuration

#define	ADC2_AWD3CR_AWD3CH			(0xFFFFFu<<1)
#define	ADC2_AWD3CR_AWD3CH_0		(0x1u<<1)

// LTR2 Configuration

#define	ADC2_LTR2_LTR2				(0x3FFFFFFu<<0)
#define	ADC2_LTR2_LTR2_0			(0x1u<<0)

// HTR2 Configuration

#define	ADC2_HTR2_HTR2				(0x3FFFFFFu<<0)
#define	ADC2_HTR2_HTR2_0			(0x1u<<0)

// LTR3 Configuration

#define	ADC2_LTR3_LTR3				(0x3FFFFFFu<<0)
#define	ADC2_LTR3_LTR3_0			(0x1u<<0)

// HTR3 Configuration

#define	ADC2_HTR3_HTR3				(0x3FFFFFFu<<0)
#define	ADC2_HTR3_HTR3_0			(0x1u<<0)

// DIFSEL Configuration

#define	ADC2_DIFSEL_DIFSEL			(0xFFFFFu<<0)
#define	ADC2_DIFSEL_DIFSEL_0		(0x1u<<0)

// CALFACT Configuration

#define	ADC2_CALFACT_CALFACT_S		(0x7FFu<<0)
#define	ADC2_CALFACT_CALFACT_S_0	(0x1u<<0)
#define	ADC2_CALFACT_CALFACT_D		(0x7FFu<<16)
#define	ADC2_CALFACT_CALFACT_D_0	(0x1u<<16)

// CALFACT2 Configuration

#define	ADC2_CALFACT2_LINCALFACT	(0x3FFFFFFFu<<0)
#define	ADC2_CALFACT2_LINCALFACT_0	(0x1u<<0)
