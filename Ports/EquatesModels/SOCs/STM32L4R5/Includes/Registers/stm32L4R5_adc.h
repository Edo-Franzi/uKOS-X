/*
; stm32L4R5_adc.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_adc equates.
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

// ADC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	ISR;
	volatile	uint32_t	IER;
	volatile	uint32_t	CR;
	volatile	uint32_t	CFGR;
	volatile	uint32_t	CFGR2;
	volatile	uint32_t	SMPR1;
	volatile	uint32_t	SMPR2;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	TR1;
	volatile	uint32_t	TR2;
	volatile	uint32_t	TR3;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	SQR1;
	volatile	uint32_t	SQR2;
	volatile	uint32_t	SQR3;
	volatile	uint32_t	SQR4;
	volatile	uint32_t	DR;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	JSQR;
	volatile	uint32_t	RESERVED3[4];
	volatile	uint32_t	OFR1;
	volatile	uint32_t	OFR2;
	volatile	uint32_t	OFR3;
	volatile	uint32_t	OFR4;
	volatile	uint32_t	RESERVED4[4];
	volatile	uint32_t	JDR1;
	volatile	uint32_t	JDR2;
	volatile	uint32_t	JDR3;
	volatile	uint32_t	JDR4;
	volatile	uint32_t	RESERVED5[4];
	volatile	uint32_t	AWD2CR;
	volatile	uint32_t	AWD3CR;
	volatile	uint32_t	RESERVED6[2];
	volatile	uint32_t	DIFSEL;
	volatile	uint32_t	CALFACT;
} ADC_TypeDef;

#if (defined(__cplusplus))
#define	ADC	reinterpret_cast<ADC_TypeDef *>(0x50040000u)

#else
#define	ADC	((ADC_TypeDef *)0x50040000u)
#endif

// ISR Configuration

#define	ADC_ISR_ADRDY				(0x1u<<0)
#define	ADC_ISR_EOSMP				(0x1u<<1)
#define	ADC_ISR_EOC					(0x1u<<2)
#define	ADC_ISR_EOS					(0x1u<<3)
#define	ADC_ISR_OVR					(0x1u<<4)
#define	ADC_ISR_JEOC				(0x1u<<5)
#define	ADC_ISR_JEOS				(0x1u<<6)
#define	ADC_ISR_AWD1				(0x1u<<7)
#define	ADC_ISR_AWD2				(0x1u<<8)
#define	ADC_ISR_AWD3				(0x1u<<9)
#define	ADC_ISR_JQOVF				(0x1u<<10)

// IER Configuration

#define	ADC_IER_ADRDYIE				(0x1u<<0)
#define	ADC_IER_EOSMPIE				(0x1u<<1)
#define	ADC_IER_EOCIE				(0x1u<<2)
#define	ADC_IER_EOSIE				(0x1u<<3)
#define	ADC_IER_OVRIE				(0x1u<<4)
#define	ADC_IER_JEOCIE				(0x1u<<5)
#define	ADC_IER_JEOSIE				(0x1u<<6)
#define	ADC_IER_AWD1IE				(0x1u<<7)
#define	ADC_IER_AWD2IE				(0x1u<<8)
#define	ADC_IER_AWD3IE				(0x1u<<9)
#define	ADC_IER_JQOVFIE				(0x1u<<10)

// CR Configuration

#define	ADC_CR_ADEN					(0x1u<<0)
#define	ADC_CR_ADDIS				(0x1u<<1)
#define	ADC_CR_ADSTART				(0x1u<<2)
#define	ADC_CR_JADSTART				(0x1u<<3)
#define	ADC_CR_ADSTP				(0x1u<<4)
#define	ADC_CR_JADSTP				(0x1u<<5)
#define	ADC_CR_ADVREGEN				(0x1u<<28)
#define	ADC_CR_DEEPPWD				(0x1u<<29)
#define	ADC_CR_ADCALDIF				(0x1u<<30)
#define	ADC_CR_ADCAL				(0x1u<<31)

// CFGR Configuration

#define	ADC_CFGR_JQDIS				(0x1u<<31)
#define	ADC_CFGR_DMAEN				(0x1u<<0)
#define	ADC_CFGR_DMACFG				(0x1u<<1)
#define	ADC_CFGR_RES				(0x3u<<3)
#define	ADC_CFGR_RES_0				(0x1u<<3)
#define	ADC_CFGR_ALIGN				(0x1u<<5)
#define	ADC_CFGR_EXTSEL				(0xFu<<6)
#define	ADC_CFGR_EXTSEL_0			(0x1u<<6)
#define	ADC_CFGR_EXTEN				(0x3u<<10)
#define	ADC_CFGR_EXTEN_0			(0x1u<<10)
#define	ADC_CFGR_OVRMOD				(0x1u<<12)
#define	ADC_CFGR_CONT				(0x1u<<13)
#define	ADC_CFGR_AUTDLY				(0x1u<<14)
#define	ADC_CFGR_DISCEN				(0x1u<<16)
#define	ADC_CFGR_DISCNUM			(0x7u<<17)
#define	ADC_CFGR_DISCNUM_0			(0x1u<<17)
#define	ADC_CFGR_JDISCEN			(0x1u<<20)
#define	ADC_CFGR_JQM				(0x1u<<21)
#define	ADC_CFGR_AWD1SGL			(0x1u<<22)
#define	ADC_CFGR_AWD1EN				(0x1u<<23)
#define	ADC_CFGR_JAWD1EN			(0x1u<<24)
#define	ADC_CFGR_JAUTO				(0x1u<<25)
#define	ADC_CFGR_AWDCH1CH			(0x1Fu<<26)
#define	ADC_CFGR_AWDCH1CH_0			(0x1u<<26)

// CFGR2 Configuration

#define	ADC_CFGR2_ROVSE				(0x1u<<0)
#define	ADC_CFGR2_JOVSE				(0x1u<<1)
#define	ADC_CFGR2_OVSR				(0x7u<<2)
#define	ADC_CFGR2_OVSR_0			(0x1u<<2)
#define	ADC_CFGR2_OVSS				(0xFu<<5)
#define	ADC_CFGR2_OVSS_0			(0x1u<<5)
#define	ADC_CFGR2_TROVS				(0x1u<<9)
#define	ADC_CFGR2_ROVSM				(0x1u<<10)

// SMPR1 Configuration

#define	ADC_SMPR1_SMP0				(0x7u<<0)
#define	ADC_SMPR1_SMP0_0			(0x1u<<0)
#define	ADC_SMPR1_SMPPLUS			(0x1u<<31)
#define	ADC_SMPR1_SMP1				(0x7u<<3)
#define	ADC_SMPR1_SMP1_0			(0x1u<<3)
#define	ADC_SMPR1_SMP2				(0x7u<<6)
#define	ADC_SMPR1_SMP2_0			(0x1u<<6)
#define	ADC_SMPR1_SMP3				(0x7u<<9)
#define	ADC_SMPR1_SMP3_0			(0x1u<<9)
#define	ADC_SMPR1_SMP4				(0x7u<<12)
#define	ADC_SMPR1_SMP4_0			(0x1u<<12)
#define	ADC_SMPR1_SMP5				(0x7u<<15)
#define	ADC_SMPR1_SMP5_0			(0x1u<<15)
#define	ADC_SMPR1_SMP6				(0x7u<<18)
#define	ADC_SMPR1_SMP6_0			(0x1u<<18)
#define	ADC_SMPR1_SMP7				(0x7u<<21)
#define	ADC_SMPR1_SMP7_0			(0x1u<<21)
#define	ADC_SMPR1_SMP8				(0x7u<<24)
#define	ADC_SMPR1_SMP8_0			(0x1u<<24)
#define	ADC_SMPR1_SMP9				(0x7u<<27)
#define	ADC_SMPR1_SMP9_0			(0x1u<<27)

// SMPR2 Configuration

#define	ADC_SMPR2_SMP10				(0x7u<<0)
#define	ADC_SMPR2_SMP10_0			(0x1u<<0)
#define	ADC_SMPR2_SMP11				(0x7u<<3)
#define	ADC_SMPR2_SMP11_0			(0x1u<<3)
#define	ADC_SMPR2_SMP12				(0x7u<<6)
#define	ADC_SMPR2_SMP12_0			(0x1u<<6)
#define	ADC_SMPR2_SMP13				(0x7u<<9)
#define	ADC_SMPR2_SMP13_0			(0x1u<<9)
#define	ADC_SMPR2_SMP14				(0x7u<<12)
#define	ADC_SMPR2_SMP14_0			(0x1u<<12)
#define	ADC_SMPR2_SMP15				(0x7u<<15)
#define	ADC_SMPR2_SMP15_0			(0x1u<<15)
#define	ADC_SMPR2_SMP16				(0x7u<<18)
#define	ADC_SMPR2_SMP16_0			(0x1u<<18)
#define	ADC_SMPR2_SMP17				(0x7u<<21)
#define	ADC_SMPR2_SMP17_0			(0x1u<<21)
#define	ADC_SMPR2_SMP18				(0x7u<<24)
#define	ADC_SMPR2_SMP18_0			(0x1u<<24)

// TR1 Configuration

#define	ADC_TR1_LT1					(0xFFFu<<0)
#define	ADC_TR1_LT1_0				(0x1u<<0)
#define	ADC_TR1_HT1					(0xFFFu<<16)
#define	ADC_TR1_HT1_0				(0x1u<<16)

// TR2 Configuration

#define	ADC_TR2_LT2					(0xFFu<<0)
#define	ADC_TR2_LT2_0				(0x1u<<0)
#define	ADC_TR2_HT2					(0xFFu<<16)
#define	ADC_TR2_HT2_0				(0x1u<<16)

// TR3 Configuration

#define	ADC_TR3_LT3					(0xFFu<<0)
#define	ADC_TR3_LT3_0				(0x1u<<0)
#define	ADC_TR3_HT3					(0xFFu<<16)
#define	ADC_TR3_HT3_0				(0x1u<<16)

// SQR1 Configuration

#define	ADC_SQR1_L					(0xFu<<0)
#define	ADC_SQR1_L_0				(0x1u<<0)
#define	ADC_SQR1_SQ1				(0x1Fu<<6)
#define	ADC_SQR1_SQ1_0				(0x1u<<6)
#define	ADC_SQR1_SQ2				(0x1Fu<<12)
#define	ADC_SQR1_SQ2_0				(0x1u<<12)
#define	ADC_SQR1_SQ3				(0x1Fu<<18)
#define	ADC_SQR1_SQ3_0				(0x1u<<18)
#define	ADC_SQR1_SQ4				(0x1Fu<<24)
#define	ADC_SQR1_SQ4_0				(0x1u<<24)

// SQR2 Configuration

#define	ADC_SQR2_SQ5				(0x1Fu<<0)
#define	ADC_SQR2_SQ5_0				(0x1u<<0)
#define	ADC_SQR2_SQ6				(0x1Fu<<6)
#define	ADC_SQR2_SQ6_0				(0x1u<<6)
#define	ADC_SQR2_SQ7				(0x1Fu<<12)
#define	ADC_SQR2_SQ7_0				(0x1u<<12)
#define	ADC_SQR2_SQ8				(0x1Fu<<18)
#define	ADC_SQR2_SQ8_0				(0x1u<<18)
#define	ADC_SQR2_SQ9				(0x1Fu<<24)
#define	ADC_SQR2_SQ9_0				(0x1u<<24)

// SQR3 Configuration

#define	ADC_SQR3_SQ10				(0x1Fu<<0)
#define	ADC_SQR3_SQ10_0				(0x1u<<0)
#define	ADC_SQR3_SQ11				(0x1Fu<<6)
#define	ADC_SQR3_SQ11_0				(0x1u<<6)
#define	ADC_SQR3_SQ12				(0x1Fu<<12)
#define	ADC_SQR3_SQ12_0				(0x1u<<12)
#define	ADC_SQR3_SQ13				(0x1Fu<<18)
#define	ADC_SQR3_SQ13_0				(0x1u<<18)
#define	ADC_SQR3_SQ14				(0x1Fu<<24)
#define	ADC_SQR3_SQ14_0				(0x1u<<24)

// SQR4 Configuration

#define	ADC_SQR4_SQ15				(0x1Fu<<0)
#define	ADC_SQR4_SQ15_0				(0x1u<<0)
#define	ADC_SQR4_SQ16				(0x1Fu<<6)
#define	ADC_SQR4_SQ16_0				(0x1u<<6)

// DR Configuration

#define	ADC_DR_RDATA				(0xFFFFu<<0)
#define	ADC_DR_RDATA_0				(0x1u<<0)

// JSQR Configuration

#define	ADC_JSQR_JL					(0x3u<<0)
#define	ADC_JSQR_JL_0				(0x1u<<0)
#define	ADC_JSQR_JEXTSEL			(0xFu<<2)
#define	ADC_JSQR_JEXTSEL_0			(0x1u<<2)
#define	ADC_JSQR_JEXTEN				(0x3u<<6)
#define	ADC_JSQR_JEXTEN_0			(0x1u<<6)
#define	ADC_JSQR_JSQ1				(0x1Fu<<8)
#define	ADC_JSQR_JSQ1_0				(0x1u<<8)
#define	ADC_JSQR_JSQ2				(0x1Fu<<14)
#define	ADC_JSQR_JSQ2_0				(0x1u<<14)
#define	ADC_JSQR_JSQ3				(0x1Fu<<20)
#define	ADC_JSQR_JSQ3_0				(0x1u<<20)
#define	ADC_JSQR_JSQ4				(0x1Fu<<26)
#define	ADC_JSQR_JSQ4_0				(0x1u<<26)

// OFR1 Configuration

#define	ADC_OFR1_OFFSET1			(0xFFFu<<0)
#define	ADC_OFR1_OFFSET1_0			(0x1u<<0)
#define	ADC_OFR1_OFFSET1_CH			(0x1Fu<<26)
#define	ADC_OFR1_OFFSET1_CH_0		(0x1u<<26)
#define	ADC_OFR1_OFFSET1_EN			(0x1u<<31)

// OFR2 Configuration

#define	ADC_OFR2_OFFSET2			(0xFFFu<<0)
#define	ADC_OFR2_OFFSET2_0			(0x1u<<0)
#define	ADC_OFR2_OFFSET2_CH			(0x1Fu<<26)
#define	ADC_OFR2_OFFSET2_CH_0		(0x1u<<26)
#define	ADC_OFR2_OFFSET2_EN			(0x1u<<31)

// OFR3 Configuration

#define	ADC_OFR3_OFFSET3			(0xFFFu<<0)
#define	ADC_OFR3_OFFSET3_0			(0x1u<<0)
#define	ADC_OFR3_OFFSET3_CH			(0x1Fu<<26)
#define	ADC_OFR3_OFFSET3_CH_0		(0x1u<<26)
#define	ADC_OFR3_OFFSET3_EN			(0x1u<<31)

// OFR4 Configuration

#define	ADC_OFR4_OFFSET4			(0xFFFu<<0)
#define	ADC_OFR4_OFFSET4_0			(0x1u<<0)
#define	ADC_OFR4_OFFSET4_CH			(0x1Fu<<26)
#define	ADC_OFR4_OFFSET4_CH_0		(0x1u<<26)
#define	ADC_OFR4_OFFSET4_EN			(0x1u<<31)

// JDR1 Configuration

#define	ADC_JDR1_JDATA1				(0xFFFFu<<0)
#define	ADC_JDR1_JDATA1_0			(0x1u<<0)

// JDR2 Configuration

#define	ADC_JDR2_JDATA2				(0xFFFFu<<0)
#define	ADC_JDR2_JDATA2_0			(0x1u<<0)

// JDR3 Configuration

#define	ADC_JDR3_JDATA3				(0xFFFFu<<0)
#define	ADC_JDR3_JDATA3_0			(0x1u<<0)

// JDR4 Configuration

#define	ADC_JDR4_JDATA4				(0xFFFFu<<0)
#define	ADC_JDR4_JDATA4_0			(0x1u<<0)

// AWD2CR Configuration

#define	ADC_AWD2CR_AWD2CH			(0x3FFFFu<<0)
#define	ADC_AWD2CR_AWD2CH_0			(0x1u<<0)

// AWD3CR Configuration

#define	ADC_AWD3CR_AWD3CH			(0x3FFFFu<<0)
#define	ADC_AWD3CR_AWD3CH_0			(0x1u<<0)

// DIFSEL Configuration

#define	ADC_DIFSEL_DIFSEL_16_18		(0x7u<<16)
#define	ADC_DIFSEL_DIFSEL_16_18_0	(0x1u<<16)
#define	ADC_DIFSEL_DIFSEL_1_15		(0x7FFFu<<1)
#define	ADC_DIFSEL_DIFSEL_1_15_0	(0x1u<<1)

// CALFACT Configuration

#define	ADC_CALFACT_CALFACT_S		(0x7Fu<<0)
#define	ADC_CALFACT_CALFACT_S_0		(0x1u<<0)
#define	ADC_CALFACT_CALFACT_D		(0x7Fu<<16)
#define	ADC_CALFACT_CALFACT_D_0		(0x1u<<16)
