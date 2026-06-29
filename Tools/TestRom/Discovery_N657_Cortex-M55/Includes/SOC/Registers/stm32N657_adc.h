/*
; stm32N657_adc.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_adc equates.
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
	volatile	uint32_t	OFCFGR1;
	volatile	uint32_t	OFCFGR2;
	volatile	uint32_t	OFCFGR3;
	volatile	uint32_t	OFCFGR4;
	volatile	uint32_t	OFR1;
	volatile	uint32_t	OFR2;
	volatile	uint32_t	OFR3;
	volatile	uint32_t	OFR4;
	volatile	uint32_t	GCOMP;
	volatile	uint32_t	RESERVED2[3];
	volatile	uint32_t	JDR1;
	volatile	uint32_t	JDR2;
	volatile	uint32_t	JDR3;
	volatile	uint32_t	JDR4;
	volatile	uint32_t	RESERVED3[4];
	volatile	uint32_t	AWD2CR;
	volatile	uint32_t	AWD3CR;
	volatile	uint32_t	AWD1LTR;
	volatile	uint32_t	AWD1HTR;
	volatile	uint32_t	AWD2LTR;
	volatile	uint32_t	AWD2HTR;
	volatile	uint32_t	AWD3LTR;
	volatile	uint32_t	AWD3HTR;
	volatile	uint32_t	DIFSEL;
	volatile	uint32_t	CALFACT;
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	OR;
} ADC_TypeDef;

#if (defined(__cplusplus))
#define	ADC1_NS	reinterpret_cast<ADC_TypeDef *>(0x40022000u)
#define	ADC1_S	reinterpret_cast<ADC_TypeDef *>(0x50022000u)
#define	ADC2_NS	reinterpret_cast<ADC_TypeDef *>(0x40022100u)
#define	ADC2_S	reinterpret_cast<ADC_TypeDef *>(0x50022100u)

#else
#define	ADC1_NS	((ADC_TypeDef *)0x40022000u)
#define	ADC1_S	((ADC_TypeDef *)0x50022000u)
#define	ADC2_NS	((ADC_TypeDef *)0x40022100u)
#define	ADC2_S	((ADC_TypeDef *)0x50022100u)
#endif

// ISR Configuration

#define	ADC_ISR_JQOVF					(0x1u<<10)
#define	ADC_ISR_AWD3					(0x1u<<9)
#define	ADC_ISR_AWD2					(0x1u<<8)
#define	ADC_ISR_AWD1					(0x1u<<7)
#define	ADC_ISR_JEOS					(0x1u<<6)
#define	ADC_ISR_JEOC					(0x1u<<5)
#define	ADC_ISR_OVR						(0x1u<<4)
#define	ADC_ISR_EOS						(0x1u<<3)
#define	ADC_ISR_EOC						(0x1u<<2)
#define	ADC_ISR_EOSMP					(0x1u<<1)
#define	ADC_ISR_ADRDY					(0x1u<<0)

#define	ADC_ISR_JQOVF_B_0X0				(0x0u<<10)
#define	ADC_ISR_JQOVF_B_0X1				(0x1u<<10)
#define	ADC_ISR_AWD3_B_0X0				(0x0u<<9)
#define	ADC_ISR_AWD3_B_0X1				(0x1u<<9)
#define	ADC_ISR_AWD2_B_0X0				(0x0u<<8)
#define	ADC_ISR_AWD2_B_0X1				(0x1u<<8)
#define	ADC_ISR_AWD1_B_0X0				(0x0u<<7)
#define	ADC_ISR_AWD1_B_0X1				(0x1u<<7)
#define	ADC_ISR_JEOS_B_0X0				(0x0u<<6)
#define	ADC_ISR_JEOS_B_0X1				(0x1u<<6)
#define	ADC_ISR_JEOC_B_0X0				(0x0u<<5)
#define	ADC_ISR_JEOC_B_0X1				(0x1u<<5)
#define	ADC_ISR_OVR_B_0X0				(0x0u<<4)
#define	ADC_ISR_OVR_B_0X1				(0x1u<<4)
#define	ADC_ISR_EOS_B_0X0				(0x0u<<3)
#define	ADC_ISR_EOS_B_0X1				(0x1u<<3)
#define	ADC_ISR_EOC_B_0X0				(0x0u<<2)
#define	ADC_ISR_EOC_B_0X1				(0x1u<<2)
#define	ADC_ISR_EOSMP_B_0X0				(0x0u<<1)
#define	ADC_ISR_EOSMP_B_0X1				(0x1u<<1)
#define	ADC_ISR_ADRDY_B_0X0				(0x0u<<0)
#define	ADC_ISR_ADRDY_B_0X1				(0x1u<<0)

// IER Configuration

#define	ADC_IER_JQOVFIE					(0x1u<<10)
#define	ADC_IER_AWD3IE					(0x1u<<9)
#define	ADC_IER_AWD2IE					(0x1u<<8)
#define	ADC_IER_AWD1IE					(0x1u<<7)
#define	ADC_IER_JEOSIE					(0x1u<<6)
#define	ADC_IER_JEOCIE					(0x1u<<5)
#define	ADC_IER_OVRIE					(0x1u<<4)
#define	ADC_IER_EOSIE					(0x1u<<3)
#define	ADC_IER_EOCIE					(0x1u<<2)
#define	ADC_IER_EOSMPIE					(0x1u<<1)
#define	ADC_IER_ADRDYIE					(0x1u<<0)

#define	ADC_IER_JQOVFIE_B_0X0			(0x0u<<10)
#define	ADC_IER_JQOVFIE_B_0X1			(0x1u<<10)
#define	ADC_IER_AWD3IE_B_0X0			(0x0u<<9)
#define	ADC_IER_AWD3IE_B_0X1			(0x1u<<9)
#define	ADC_IER_AWD2IE_B_0X0			(0x0u<<8)
#define	ADC_IER_AWD2IE_B_0X1			(0x1u<<8)
#define	ADC_IER_AWD1IE_B_0X0			(0x0u<<7)
#define	ADC_IER_AWD1IE_B_0X1			(0x1u<<7)
#define	ADC_IER_JEOSIE_B_0X0			(0x0u<<6)
#define	ADC_IER_JEOSIE_B_0X1			(0x1u<<6)
#define	ADC_IER_JEOCIE_B_0X0			(0x0u<<5)
#define	ADC_IER_JEOCIE_B_0X1			(0x1u<<5)
#define	ADC_IER_OVRIE_B_0X0				(0x0u<<4)
#define	ADC_IER_OVRIE_B_0X1				(0x1u<<4)
#define	ADC_IER_EOSIE_B_0X0				(0x0u<<3)
#define	ADC_IER_EOSIE_B_0X1				(0x1u<<3)
#define	ADC_IER_EOCIE_B_0X0				(0x0u<<2)
#define	ADC_IER_EOCIE_B_0X1				(0x1u<<2)
#define	ADC_IER_EOSMPIE_B_0X0			(0x0u<<1)
#define	ADC_IER_EOSMPIE_B_0X1			(0x1u<<1)
#define	ADC_IER_ADRDYIE_B_0X0			(0x0u<<0)
#define	ADC_IER_ADRDYIE_B_0X1			(0x1u<<0)

// CR Configuration

#define	ADC_CR_ADCAL					(0x1u<<31)
#define	ADC_CR_ADCALDIF					(0x1u<<30)
#define	ADC_CR_DEEPPWD					(0x1u<<29)
#define	ADC_CR_JADSTP					(0x1u<<5)
#define	ADC_CR_ADSTP					(0x1u<<4)
#define	ADC_CR_JADSTART					(0x1u<<3)
#define	ADC_CR_ADSTART					(0x1u<<2)
#define	ADC_CR_ADDIS					(0x1u<<1)
#define	ADC_CR_ADEN						(0x1u<<0)

#define	ADC_CR_ADCAL_B_0X0				(0x0u<<31)
#define	ADC_CR_ADCAL_B_0X1				(0x1u<<31)
#define	ADC_CR_ADCALDIF_B_0X0			(0x0u<<30)
#define	ADC_CR_ADCALDIF_B_0X1			(0x1u<<30)
#define	ADC_CR_DEEPPWD_B_0X0			(0x0u<<29)
#define	ADC_CR_DEEPPWD_B_0X1			(0x1u<<29)
#define	ADC_CR_JADSTP_B_0X0				(0x0u<<5)
#define	ADC_CR_JADSTP_B_0X1				(0x1u<<5)
#define	ADC_CR_ADSTP_B_0X0				(0x0u<<4)
#define	ADC_CR_ADSTP_B_0X1				(0x1u<<4)
#define	ADC_CR_JADSTART_B_0X0			(0x0u<<3)
#define	ADC_CR_JADSTART_B_0X1			(0x1u<<3)
#define	ADC_CR_ADSTART_B_0X0			(0x0u<<2)
#define	ADC_CR_ADSTART_B_0X1			(0x1u<<2)
#define	ADC_CR_ADDIS_B_0X0				(0x0u<<1)
#define	ADC_CR_ADDIS_B_0X1				(0x1u<<1)
#define	ADC_CR_ADEN_B_0X0				(0x0u<<0)
#define	ADC_CR_ADEN_B_0X1				(0x1u<<0)

// CFGR1 Configuration

#define	ADC_CFGR1_JQDIS					(0x1u<<31)
#define	ADC_CFGR1_AWD1CH				(0x1Fu<<26)
#define	ADC_CFGR1_AWD1CH_0				(0x1u<<26)
#define	ADC_CFGR1_JAUTO					(0x1u<<25)
#define	ADC_CFGR1_JAWD1EN				(0x1u<<24)
#define	ADC_CFGR1_AWD1EN				(0x1u<<23)
#define	ADC_CFGR1_AWD1SGL				(0x1u<<22)
#define	ADC_CFGR1_JQM					(0x1u<<21)
#define	ADC_CFGR1_JDISCEN				(0x1u<<20)
#define	ADC_CFGR1_DISCNUM				(0x7u<<17)
#define	ADC_CFGR1_DISCNUM_0				(0x1u<<17)
#define	ADC_CFGR1_DISCEN				(0x1u<<16)
#define	ADC_CFGR1_AUTDLY				(0x1u<<14)
#define	ADC_CFGR1_CONT					(0x1u<<13)
#define	ADC_CFGR1_OVRMOD				(0x1u<<12)
#define	ADC_CFGR1_EXTEN					(0x3u<<10)
#define	ADC_CFGR1_EXTEN_0				(0x1u<<10)
#define	ADC_CFGR1_EXTSEL				(0x1Fu<<5)
#define	ADC_CFGR1_EXTSEL_0				(0x1u<<5)
#define	ADC_CFGR1_RES					(0x3u<<2)
#define	ADC_CFGR1_RES_0					(0x1u<<2)
#define	ADC_CFGR1_DMNGT					(0x3u<<0)
#define	ADC_CFGR1_DMNGT_0				(0x1u<<0)

#define	ADC_CFGR1_JQDIS_B_0X0			(0x0u<<31)
#define	ADC_CFGR1_JQDIS_B_0X1			(0x1u<<31)
#define	ADC_CFGR1_AWD1CH_B_0X0			(0x0u<<26)
#define	ADC_CFGR1_AWD1CH_B_0X1			(0x1u<<26)
#define	ADC_CFGR1_AWD1CH_B_0X13			(0x13u<<26)
#define	ADC_CFGR1_JAUTO_B_0X0			(0x0u<<25)
#define	ADC_CFGR1_JAUTO_B_0X1			(0x1u<<25)
#define	ADC_CFGR1_JAWD1EN_B_0X0			(0x0u<<24)
#define	ADC_CFGR1_JAWD1EN_B_0X1			(0x1u<<24)
#define	ADC_CFGR1_AWD1EN_B_0X0			(0x0u<<23)
#define	ADC_CFGR1_AWD1EN_B_0X1			(0x1u<<23)
#define	ADC_CFGR1_AWD1SGL_B_0X0			(0x0u<<22)
#define	ADC_CFGR1_AWD1SGL_B_0X1			(0x1u<<22)
#define	ADC_CFGR1_JQM_B_0X0				(0x0u<<21)
#define	ADC_CFGR1_JQM_B_0X1				(0x1u<<21)
#define	ADC_CFGR1_JDISCEN_B_0X0			(0x0u<<20)
#define	ADC_CFGR1_JDISCEN_B_0X1			(0x1u<<20)
#define	ADC_CFGR1_DISCNUM_B_0X0			(0x0u<<17)
#define	ADC_CFGR1_DISCNUM_B_0X1			(0x1u<<17)
#define	ADC_CFGR1_DISCNUM_B_0X7			(0x7u<<17)
#define	ADC_CFGR1_DISCEN_B_0X0			(0x0u<<16)
#define	ADC_CFGR1_DISCEN_B_0X1			(0x1u<<16)
#define	ADC_CFGR1_AUTDLY_B_0X0			(0x0u<<14)
#define	ADC_CFGR1_AUTDLY_B_0X1			(0x1u<<14)
#define	ADC_CFGR1_CONT_B_0X0			(0x0u<<13)
#define	ADC_CFGR1_CONT_B_0X1			(0x1u<<13)
#define	ADC_CFGR1_OVRMOD_B_0X0			(0x0u<<12)
#define	ADC_CFGR1_OVRMOD_B_0X1			(0x1u<<12)
#define	ADC_CFGR1_EXTEN_B_0X0			(0x0u<<10)
#define	ADC_CFGR1_EXTEN_B_0X1			(0x1u<<10)
#define	ADC_CFGR1_EXTEN_B_0X2			(0x2u<<10)
#define	ADC_CFGR1_EXTEN_B_0X3			(0x3u<<10)
#define	ADC_CFGR1_EXTSEL_B_0X0			(0x0u<<5)
#define	ADC_CFGR1_EXTSEL_B_0X1			(0x1u<<5)
#define	ADC_CFGR1_EXTSEL_B_0X2			(0x2u<<5)
#define	ADC_CFGR1_EXTSEL_B_0X3			(0x3u<<5)
#define	ADC_CFGR1_EXTSEL_B_0X4			(0x4u<<5)
#define	ADC_CFGR1_EXTSEL_B_0X5			(0x5u<<5)
#define	ADC_CFGR1_EXTSEL_B_0X6			(0x6u<<5)
#define	ADC_CFGR1_EXTSEL_B_0X7			(0x7u<<5)
#define	ADC_CFGR1_EXTSEL_B_0X1F			(0x1Fu<<5)
#define	ADC_CFGR1_RES_B_0X0				(0x0u<<2)
#define	ADC_CFGR1_RES_B_0X1				(0x1u<<2)
#define	ADC_CFGR1_RES_B_0X2				(0x2u<<2)
#define	ADC_CFGR1_RES_B_0X3				(0x3u<<2)
#define	ADC_CFGR1_DMNGT_B_0X0			(0x0u<<0)
#define	ADC_CFGR1_DMNGT_B_0X1			(0x1u<<0)
#define	ADC_CFGR1_DMNGT_B_0X2			(0x2u<<0)
#define	ADC_CFGR1_DMNGT_B_0X3			(0x3u<<0)

// CFGR2 Configuration

#define	ADC_CFGR2_LSHIFT				(0xFu<<28)
#define	ADC_CFGR2_LSHIFT_0				(0x1u<<28)
#define	ADC_CFGR2_OSR					(0x3FFu<<16)
#define	ADC_CFGR2_OSR_0					(0x1u<<16)
#define	ADC_CFGR2_SMPTRIG				(0x1u<<15)
#define	ADC_CFGR2_SWTRIG				(0x1u<<14)
#define	ADC_CFGR2_BULB					(0x1u<<13)
#define	ADC_CFGR2_ROVSM					(0x1u<<10)
#define	ADC_CFGR2_TROVS					(0x1u<<9)
#define	ADC_CFGR2_OVSS					(0xFu<<5)
#define	ADC_CFGR2_OVSS_0				(0x1u<<5)
#define	ADC_CFGR2_JOVSE					(0x1u<<1)
#define	ADC_CFGR2_ROVSE					(0x1u<<0)

#define	ADC_CFGR2_LSHIFT_B_0X0			(0x0u<<28)
#define	ADC_CFGR2_LSHIFT_B_0X1			(0x1u<<28)
#define	ADC_CFGR2_LSHIFT_B_0X2			(0x2u<<28)
#define	ADC_CFGR2_LSHIFT_B_0X3			(0x3u<<28)
#define	ADC_CFGR2_LSHIFT_B_0X4			(0x4u<<28)
#define	ADC_CFGR2_LSHIFT_B_0X5			(0x5u<<28)
#define	ADC_CFGR2_LSHIFT_B_0X6			(0x6u<<28)
#define	ADC_CFGR2_LSHIFT_B_0X7			(0x7u<<28)
#define	ADC_CFGR2_LSHIFT_B_0X8			(0x8u<<28)
#define	ADC_CFGR2_LSHIFT_B_0X9			(0x9u<<28)
#define	ADC_CFGR2_LSHIFT_B_0XA			(0xAu<<28)
#define	ADC_CFGR2_LSHIFT_B_0XB			(0xBu<<28)
#define	ADC_CFGR2_LSHIFT_B_0XC			(0xCu<<28)
#define	ADC_CFGR2_LSHIFT_B_0XD			(0xDu<<28)
#define	ADC_CFGR2_LSHIFT_B_0XE			(0xEu<<28)
#define	ADC_CFGR2_LSHIFT_B_0XF			(0xFu<<28)
#define	ADC_CFGR2_OSR_B_0X0				(0x0u<<16)
#define	ADC_CFGR2_OSR_B_0X1				(0x1u<<16)
#define	ADC_CFGR2_SMPTRIG_B_0X0			(0x0u<<15)
#define	ADC_CFGR2_SMPTRIG_B_0X1			(0x1u<<15)
#define	ADC_CFGR2_SWTRIG_B_0X0			(0x0u<<14)
#define	ADC_CFGR2_SWTRIG_B_0X1			(0x1u<<14)
#define	ADC_CFGR2_BULB_B_0X0			(0x0u<<13)
#define	ADC_CFGR2_BULB_B_0X1			(0x1u<<13)
#define	ADC_CFGR2_ROVSM_B_0X0			(0x0u<<10)
#define	ADC_CFGR2_ROVSM_B_0X1			(0x1u<<10)
#define	ADC_CFGR2_TROVS_B_0X0			(0x0u<<9)
#define	ADC_CFGR2_TROVS_B_0X1			(0x1u<<9)
#define	ADC_CFGR2_OVSS_B_0X0			(0x0u<<5)
#define	ADC_CFGR2_OVSS_B_0X1			(0x1u<<5)
#define	ADC_CFGR2_OVSS_B_0X2			(0x2u<<5)
#define	ADC_CFGR2_OVSS_B_0X3			(0x3u<<5)
#define	ADC_CFGR2_OVSS_B_0X4			(0x4u<<5)
#define	ADC_CFGR2_OVSS_B_0X5			(0x5u<<5)
#define	ADC_CFGR2_OVSS_B_0X6			(0x6u<<5)
#define	ADC_CFGR2_OVSS_B_0X7			(0x7u<<5)
#define	ADC_CFGR2_OVSS_B_0X8			(0x8u<<5)
#define	ADC_CFGR2_OVSS_B_0X9			(0x9u<<5)
#define	ADC_CFGR2_OVSS_B_0XA			(0xAu<<5)
#define	ADC_CFGR2_JOVSE_B_0X0			(0x0u<<1)
#define	ADC_CFGR2_JOVSE_B_0X1			(0x1u<<1)
#define	ADC_CFGR2_ROVSE_B_0X0			(0x0u<<0)
#define	ADC_CFGR2_ROVSE_B_0X1			(0x1u<<0)

// SMPR1 Configuration

#define	ADC_SMPR1_SMP9					(0x7u<<27)
#define	ADC_SMPR1_SMP9_0				(0x1u<<27)
#define	ADC_SMPR1_SMP8					(0x7u<<24)
#define	ADC_SMPR1_SMP8_0				(0x1u<<24)
#define	ADC_SMPR1_SMP7					(0x7u<<21)
#define	ADC_SMPR1_SMP7_0				(0x1u<<21)
#define	ADC_SMPR1_SMP6					(0x7u<<18)
#define	ADC_SMPR1_SMP6_0				(0x1u<<18)
#define	ADC_SMPR1_SMP5					(0x7u<<15)
#define	ADC_SMPR1_SMP5_0				(0x1u<<15)
#define	ADC_SMPR1_SMP4					(0x7u<<12)
#define	ADC_SMPR1_SMP4_0				(0x1u<<12)
#define	ADC_SMPR1_SMP3					(0x7u<<9)
#define	ADC_SMPR1_SMP3_0				(0x1u<<9)
#define	ADC_SMPR1_SMP2					(0x7u<<6)
#define	ADC_SMPR1_SMP2_0				(0x1u<<6)
#define	ADC_SMPR1_SMP1					(0x7u<<3)
#define	ADC_SMPR1_SMP1_0				(0x1u<<3)
#define	ADC_SMPR1_SMP0					(0x7u<<0)
#define	ADC_SMPR1_SMP0_0				(0x1u<<0)

#define	ADC_SMPR1_SMP9_B_0X0			(0x0u<<27)
#define	ADC_SMPR1_SMP9_B_0X1			(0x1u<<27)
#define	ADC_SMPR1_SMP9_B_0X2			(0x2u<<27)
#define	ADC_SMPR1_SMP9_B_0X3			(0x3u<<27)
#define	ADC_SMPR1_SMP9_B_0X4			(0x4u<<27)
#define	ADC_SMPR1_SMP9_B_0X5			(0x5u<<27)
#define	ADC_SMPR1_SMP9_B_0X6			(0x6u<<27)
#define	ADC_SMPR1_SMP9_B_0X7			(0x7u<<27)
#define	ADC_SMPR1_SMP8_B_0X0			(0x0u<<24)
#define	ADC_SMPR1_SMP8_B_0X1			(0x1u<<24)
#define	ADC_SMPR1_SMP8_B_0X2			(0x2u<<24)
#define	ADC_SMPR1_SMP8_B_0X3			(0x3u<<24)
#define	ADC_SMPR1_SMP8_B_0X4			(0x4u<<24)
#define	ADC_SMPR1_SMP8_B_0X5			(0x5u<<24)
#define	ADC_SMPR1_SMP8_B_0X6			(0x6u<<24)
#define	ADC_SMPR1_SMP8_B_0X7			(0x7u<<24)
#define	ADC_SMPR1_SMP7_B_0X0			(0x0u<<21)
#define	ADC_SMPR1_SMP7_B_0X1			(0x1u<<21)
#define	ADC_SMPR1_SMP7_B_0X2			(0x2u<<21)
#define	ADC_SMPR1_SMP7_B_0X3			(0x3u<<21)
#define	ADC_SMPR1_SMP7_B_0X4			(0x4u<<21)
#define	ADC_SMPR1_SMP7_B_0X5			(0x5u<<21)
#define	ADC_SMPR1_SMP7_B_0X6			(0x6u<<21)
#define	ADC_SMPR1_SMP7_B_0X7			(0x7u<<21)
#define	ADC_SMPR1_SMP6_B_0X0			(0x0u<<18)
#define	ADC_SMPR1_SMP6_B_0X1			(0x1u<<18)
#define	ADC_SMPR1_SMP6_B_0X2			(0x2u<<18)
#define	ADC_SMPR1_SMP6_B_0X3			(0x3u<<18)
#define	ADC_SMPR1_SMP6_B_0X4			(0x4u<<18)
#define	ADC_SMPR1_SMP6_B_0X5			(0x5u<<18)
#define	ADC_SMPR1_SMP6_B_0X6			(0x6u<<18)
#define	ADC_SMPR1_SMP6_B_0X7			(0x7u<<18)
#define	ADC_SMPR1_SMP5_B_0X0			(0x0u<<15)
#define	ADC_SMPR1_SMP5_B_0X1			(0x1u<<15)
#define	ADC_SMPR1_SMP5_B_0X2			(0x2u<<15)
#define	ADC_SMPR1_SMP5_B_0X3			(0x3u<<15)
#define	ADC_SMPR1_SMP5_B_0X4			(0x4u<<15)
#define	ADC_SMPR1_SMP5_B_0X5			(0x5u<<15)
#define	ADC_SMPR1_SMP5_B_0X6			(0x6u<<15)
#define	ADC_SMPR1_SMP5_B_0X7			(0x7u<<15)
#define	ADC_SMPR1_SMP4_B_0X0			(0x0u<<12)
#define	ADC_SMPR1_SMP4_B_0X1			(0x1u<<12)
#define	ADC_SMPR1_SMP4_B_0X2			(0x2u<<12)
#define	ADC_SMPR1_SMP4_B_0X3			(0x3u<<12)
#define	ADC_SMPR1_SMP4_B_0X4			(0x4u<<12)
#define	ADC_SMPR1_SMP4_B_0X5			(0x5u<<12)
#define	ADC_SMPR1_SMP4_B_0X6			(0x6u<<12)
#define	ADC_SMPR1_SMP4_B_0X7			(0x7u<<12)
#define	ADC_SMPR1_SMP3_B_0X0			(0x0u<<9)
#define	ADC_SMPR1_SMP3_B_0X1			(0x1u<<9)
#define	ADC_SMPR1_SMP3_B_0X2			(0x2u<<9)
#define	ADC_SMPR1_SMP3_B_0X3			(0x3u<<9)
#define	ADC_SMPR1_SMP3_B_0X4			(0x4u<<9)
#define	ADC_SMPR1_SMP3_B_0X5			(0x5u<<9)
#define	ADC_SMPR1_SMP3_B_0X6			(0x6u<<9)
#define	ADC_SMPR1_SMP3_B_0X7			(0x7u<<9)
#define	ADC_SMPR1_SMP2_B_0X0			(0x0u<<6)
#define	ADC_SMPR1_SMP2_B_0X1			(0x1u<<6)
#define	ADC_SMPR1_SMP2_B_0X2			(0x2u<<6)
#define	ADC_SMPR1_SMP2_B_0X3			(0x3u<<6)
#define	ADC_SMPR1_SMP2_B_0X4			(0x4u<<6)
#define	ADC_SMPR1_SMP2_B_0X5			(0x5u<<6)
#define	ADC_SMPR1_SMP2_B_0X6			(0x6u<<6)
#define	ADC_SMPR1_SMP2_B_0X7			(0x7u<<6)
#define	ADC_SMPR1_SMP1_B_0X0			(0x0u<<3)
#define	ADC_SMPR1_SMP1_B_0X1			(0x1u<<3)
#define	ADC_SMPR1_SMP1_B_0X2			(0x2u<<3)
#define	ADC_SMPR1_SMP1_B_0X3			(0x3u<<3)
#define	ADC_SMPR1_SMP1_B_0X4			(0x4u<<3)
#define	ADC_SMPR1_SMP1_B_0X5			(0x5u<<3)
#define	ADC_SMPR1_SMP1_B_0X6			(0x6u<<3)
#define	ADC_SMPR1_SMP1_B_0X7			(0x7u<<3)
#define	ADC_SMPR1_SMP0_B_0X0			(0x0u<<0)
#define	ADC_SMPR1_SMP0_B_0X1			(0x1u<<0)
#define	ADC_SMPR1_SMP0_B_0X2			(0x2u<<0)
#define	ADC_SMPR1_SMP0_B_0X3			(0x3u<<0)
#define	ADC_SMPR1_SMP0_B_0X4			(0x4u<<0)
#define	ADC_SMPR1_SMP0_B_0X5			(0x5u<<0)
#define	ADC_SMPR1_SMP0_B_0X6			(0x6u<<0)
#define	ADC_SMPR1_SMP0_B_0X7			(0x7u<<0)

// SMPR2 Configuration

#define	ADC_SMPR2_SMP19					(0x7u<<27)
#define	ADC_SMPR2_SMP19_0				(0x1u<<27)
#define	ADC_SMPR2_SMP18					(0x7u<<24)
#define	ADC_SMPR2_SMP18_0				(0x1u<<24)
#define	ADC_SMPR2_SMP17					(0x7u<<21)
#define	ADC_SMPR2_SMP17_0				(0x1u<<21)
#define	ADC_SMPR2_SMP16					(0x7u<<18)
#define	ADC_SMPR2_SMP16_0				(0x1u<<18)
#define	ADC_SMPR2_SMP15					(0x7u<<15)
#define	ADC_SMPR2_SMP15_0				(0x1u<<15)
#define	ADC_SMPR2_SMP14					(0x7u<<12)
#define	ADC_SMPR2_SMP14_0				(0x1u<<12)
#define	ADC_SMPR2_SMP13					(0x7u<<9)
#define	ADC_SMPR2_SMP13_0				(0x1u<<9)
#define	ADC_SMPR2_SMP12					(0x7u<<6)
#define	ADC_SMPR2_SMP12_0				(0x1u<<6)
#define	ADC_SMPR2_SMP11					(0x7u<<3)
#define	ADC_SMPR2_SMP11_0				(0x1u<<3)
#define	ADC_SMPR2_SMP10					(0x7u<<0)
#define	ADC_SMPR2_SMP10_0				(0x1u<<0)

#define	ADC_SMPR2_SMP19_B_0X0			(0x0u<<27)
#define	ADC_SMPR2_SMP19_B_0X1			(0x1u<<27)
#define	ADC_SMPR2_SMP19_B_0X2			(0x2u<<27)
#define	ADC_SMPR2_SMP19_B_0X3			(0x3u<<27)
#define	ADC_SMPR2_SMP19_B_0X4			(0x4u<<27)
#define	ADC_SMPR2_SMP19_B_0X5			(0x5u<<27)
#define	ADC_SMPR2_SMP19_B_0X6			(0x6u<<27)
#define	ADC_SMPR2_SMP19_B_0X7			(0x7u<<27)
#define	ADC_SMPR2_SMP18_B_0X0			(0x0u<<24)
#define	ADC_SMPR2_SMP18_B_0X1			(0x1u<<24)
#define	ADC_SMPR2_SMP18_B_0X2			(0x2u<<24)
#define	ADC_SMPR2_SMP18_B_0X3			(0x3u<<24)
#define	ADC_SMPR2_SMP18_B_0X4			(0x4u<<24)
#define	ADC_SMPR2_SMP18_B_0X5			(0x5u<<24)
#define	ADC_SMPR2_SMP18_B_0X6			(0x6u<<24)
#define	ADC_SMPR2_SMP18_B_0X7			(0x7u<<24)
#define	ADC_SMPR2_SMP17_B_0X0			(0x0u<<21)
#define	ADC_SMPR2_SMP17_B_0X1			(0x1u<<21)
#define	ADC_SMPR2_SMP17_B_0X2			(0x2u<<21)
#define	ADC_SMPR2_SMP17_B_0X3			(0x3u<<21)
#define	ADC_SMPR2_SMP17_B_0X4			(0x4u<<21)
#define	ADC_SMPR2_SMP17_B_0X5			(0x5u<<21)
#define	ADC_SMPR2_SMP17_B_0X6			(0x6u<<21)
#define	ADC_SMPR2_SMP17_B_0X7			(0x7u<<21)
#define	ADC_SMPR2_SMP16_B_0X0			(0x0u<<18)
#define	ADC_SMPR2_SMP16_B_0X1			(0x1u<<18)
#define	ADC_SMPR2_SMP16_B_0X2			(0x2u<<18)
#define	ADC_SMPR2_SMP16_B_0X3			(0x3u<<18)
#define	ADC_SMPR2_SMP16_B_0X4			(0x4u<<18)
#define	ADC_SMPR2_SMP16_B_0X5			(0x5u<<18)
#define	ADC_SMPR2_SMP16_B_0X6			(0x6u<<18)
#define	ADC_SMPR2_SMP16_B_0X7			(0x7u<<18)
#define	ADC_SMPR2_SMP15_B_0X0			(0x0u<<15)
#define	ADC_SMPR2_SMP15_B_0X1			(0x1u<<15)
#define	ADC_SMPR2_SMP15_B_0X2			(0x2u<<15)
#define	ADC_SMPR2_SMP15_B_0X3			(0x3u<<15)
#define	ADC_SMPR2_SMP15_B_0X4			(0x4u<<15)
#define	ADC_SMPR2_SMP15_B_0X5			(0x5u<<15)
#define	ADC_SMPR2_SMP15_B_0X6			(0x6u<<15)
#define	ADC_SMPR2_SMP15_B_0X7			(0x7u<<15)
#define	ADC_SMPR2_SMP14_B_0X0			(0x0u<<12)
#define	ADC_SMPR2_SMP14_B_0X1			(0x1u<<12)
#define	ADC_SMPR2_SMP14_B_0X2			(0x2u<<12)
#define	ADC_SMPR2_SMP14_B_0X3			(0x3u<<12)
#define	ADC_SMPR2_SMP14_B_0X4			(0x4u<<12)
#define	ADC_SMPR2_SMP14_B_0X5			(0x5u<<12)
#define	ADC_SMPR2_SMP14_B_0X6			(0x6u<<12)
#define	ADC_SMPR2_SMP14_B_0X7			(0x7u<<12)
#define	ADC_SMPR2_SMP13_B_0X0			(0x0u<<9)
#define	ADC_SMPR2_SMP13_B_0X1			(0x1u<<9)
#define	ADC_SMPR2_SMP13_B_0X2			(0x2u<<9)
#define	ADC_SMPR2_SMP13_B_0X3			(0x3u<<9)
#define	ADC_SMPR2_SMP13_B_0X4			(0x4u<<9)
#define	ADC_SMPR2_SMP13_B_0X5			(0x5u<<9)
#define	ADC_SMPR2_SMP13_B_0X6			(0x6u<<9)
#define	ADC_SMPR2_SMP13_B_0X7			(0x7u<<9)
#define	ADC_SMPR2_SMP12_B_0X0			(0x0u<<6)
#define	ADC_SMPR2_SMP12_B_0X1			(0x1u<<6)
#define	ADC_SMPR2_SMP12_B_0X2			(0x2u<<6)
#define	ADC_SMPR2_SMP12_B_0X3			(0x3u<<6)
#define	ADC_SMPR2_SMP12_B_0X4			(0x4u<<6)
#define	ADC_SMPR2_SMP12_B_0X5			(0x5u<<6)
#define	ADC_SMPR2_SMP12_B_0X6			(0x6u<<6)
#define	ADC_SMPR2_SMP12_B_0X7			(0x7u<<6)
#define	ADC_SMPR2_SMP11_B_0X0			(0x0u<<3)
#define	ADC_SMPR2_SMP11_B_0X1			(0x1u<<3)
#define	ADC_SMPR2_SMP11_B_0X2			(0x2u<<3)
#define	ADC_SMPR2_SMP11_B_0X3			(0x3u<<3)
#define	ADC_SMPR2_SMP11_B_0X4			(0x4u<<3)
#define	ADC_SMPR2_SMP11_B_0X5			(0x5u<<3)
#define	ADC_SMPR2_SMP11_B_0X6			(0x6u<<3)
#define	ADC_SMPR2_SMP11_B_0X7			(0x7u<<3)
#define	ADC_SMPR2_SMP10_B_0X0			(0x0u<<0)
#define	ADC_SMPR2_SMP10_B_0X1			(0x1u<<0)
#define	ADC_SMPR2_SMP10_B_0X2			(0x2u<<0)
#define	ADC_SMPR2_SMP10_B_0X3			(0x3u<<0)
#define	ADC_SMPR2_SMP10_B_0X4			(0x4u<<0)
#define	ADC_SMPR2_SMP10_B_0X5			(0x5u<<0)
#define	ADC_SMPR2_SMP10_B_0X6			(0x6u<<0)
#define	ADC_SMPR2_SMP10_B_0X7			(0x7u<<0)

// PCSEL Configuration

#define	ADC_PCSEL_PCSEL					(0xFFFFFu<<0)
#define	ADC_PCSEL_PCSEL_0				(0x1u<<0)

#define	ADC_PCSEL_PCSEL_B_0X0			(0x0u<<0)
#define	ADC_PCSEL_PCSEL_B_0X1			(0x1u<<0)

// SQR1 Configuration

#define	ADC_SQR1_SQ4					(0x1Fu<<24)
#define	ADC_SQR1_SQ4_0					(0x1u<<24)
#define	ADC_SQR1_SQ3					(0x1Fu<<18)
#define	ADC_SQR1_SQ3_0					(0x1u<<18)
#define	ADC_SQR1_SQ2					(0x1Fu<<12)
#define	ADC_SQR1_SQ2_0					(0x1u<<12)
#define	ADC_SQR1_SQ1					(0x1Fu<<6)
#define	ADC_SQR1_SQ1_0					(0x1u<<6)
#define	ADC_SQR1_L						(0xFu<<0)
#define	ADC_SQR1_L_0					(0x1u<<0)

#define	ADC_SQR1_L_B_0X0				(0x0u<<0)
#define	ADC_SQR1_L_B_0X1				(0x1u<<0)
#define	ADC_SQR1_L_B_0XF				(0xFu<<0)

// SQR2 Configuration

#define	ADC_SQR2_SQ9					(0x1Fu<<24)
#define	ADC_SQR2_SQ9_0					(0x1u<<24)
#define	ADC_SQR2_SQ8					(0x1Fu<<18)
#define	ADC_SQR2_SQ8_0					(0x1u<<18)
#define	ADC_SQR2_SQ7					(0x1Fu<<12)
#define	ADC_SQR2_SQ7_0					(0x1u<<12)
#define	ADC_SQR2_SQ6					(0x1Fu<<6)
#define	ADC_SQR2_SQ6_0					(0x1u<<6)
#define	ADC_SQR2_SQ5					(0x1Fu<<0)
#define	ADC_SQR2_SQ5_0					(0x1u<<0)

// SQR3 Configuration

#define	ADC_SQR3_SQ14					(0x1Fu<<24)
#define	ADC_SQR3_SQ14_0					(0x1u<<24)
#define	ADC_SQR3_SQ13					(0x1Fu<<18)
#define	ADC_SQR3_SQ13_0					(0x1u<<18)
#define	ADC_SQR3_SQ12					(0x1Fu<<12)
#define	ADC_SQR3_SQ12_0					(0x1u<<12)
#define	ADC_SQR3_SQ11					(0x1Fu<<6)
#define	ADC_SQR3_SQ11_0					(0x1u<<6)
#define	ADC_SQR3_SQ10					(0x1Fu<<0)
#define	ADC_SQR3_SQ10_0					(0x1u<<0)

// SQR4 Configuration

#define	ADC_SQR4_SQ16					(0x1Fu<<6)
#define	ADC_SQR4_SQ16_0					(0x1u<<6)
#define	ADC_SQR4_SQ15					(0x1Fu<<0)
#define	ADC_SQR4_SQ15_0					(0x1u<<0)

// DR Configuration

#define	ADC_DR_RDATA					(0xFFFFFFFFu<<0)
#define	ADC_DR_RDATA_0					(0x1u<<0)

// JSQR Configuration

#define	ADC_JSQR_JSQ4					(0x1Fu<<27)
#define	ADC_JSQR_JSQ4_0					(0x1u<<27)
#define	ADC_JSQR_JSQ3					(0x1Fu<<21)
#define	ADC_JSQR_JSQ3_0					(0x1u<<21)
#define	ADC_JSQR_JSQ2					(0x1Fu<<15)
#define	ADC_JSQR_JSQ2_0					(0x1u<<15)
#define	ADC_JSQR_JSQ1					(0x1Fu<<9)
#define	ADC_JSQR_JSQ1_0					(0x1u<<9)
#define	ADC_JSQR_JEXTEN					(0x3u<<7)
#define	ADC_JSQR_JEXTEN_0				(0x1u<<7)
#define	ADC_JSQR_JEXTSEL				(0x1Fu<<2)
#define	ADC_JSQR_JEXTSEL_0				(0x1u<<2)
#define	ADC_JSQR_JL						(0x3u<<0)
#define	ADC_JSQR_JL_0					(0x1u<<0)

#define	ADC_JSQR_JEXTEN_B_0X0			(0x0u<<7)
#define	ADC_JSQR_JEXTEN_B_0X1			(0x1u<<7)
#define	ADC_JSQR_JEXTEN_B_0X2			(0x2u<<7)
#define	ADC_JSQR_JEXTEN_B_0X3			(0x3u<<7)
#define	ADC_JSQR_JEXTSEL_B_0X0			(0x0u<<2)
#define	ADC_JSQR_JEXTSEL_B_0X1			(0x1u<<2)
#define	ADC_JSQR_JEXTSEL_B_0X2			(0x2u<<2)
#define	ADC_JSQR_JEXTSEL_B_0X3			(0x3u<<2)
#define	ADC_JSQR_JEXTSEL_B_0X4			(0x4u<<2)
#define	ADC_JSQR_JEXTSEL_B_0X5			(0x5u<<2)
#define	ADC_JSQR_JEXTSEL_B_0X6			(0x6u<<2)
#define	ADC_JSQR_JEXTSEL_B_0X7			(0x7u<<2)
#define	ADC_JSQR_JEXTSEL_B_0X1F			(0x1Fu<<2)
#define	ADC_JSQR_JL_B_0X0				(0x0u<<0)
#define	ADC_JSQR_JL_B_0X1				(0x1u<<0)
#define	ADC_JSQR_JL_B_0X2				(0x2u<<0)
#define	ADC_JSQR_JL_B_0X3				(0x3u<<0)

// OFCFGR1 Configuration

#define	ADC_OFCFGR1_OFFSET_CH			(0x1Fu<<27)
#define	ADC_OFCFGR1_OFFSET_CH_0			(0x1u<<27)
#define	ADC_OFCFGR1_SSAT				(0x1u<<26)
#define	ADC_OFCFGR1_USAT				(0x1u<<25)
#define	ADC_OFCFGR1_POSOFF				(0x1u<<24)

#define	ADC_OFCFGR1_SSAT_B_0X0			(0x0u<<26)
#define	ADC_OFCFGR1_SSAT_B_0X1			(0x1u<<26)
#define	ADC_OFCFGR1_USAT_B_0X0			(0x0u<<25)
#define	ADC_OFCFGR1_USAT_B_0X1			(0x1u<<25)
#define	ADC_OFCFGR1_POSOFF_B_0X0		(0x0u<<24)
#define	ADC_OFCFGR1_POSOFF_B_0X1		(0x1u<<24)

// OFCFGR2 Configuration

#define	ADC_OFCFGR2_OFFSET_CH			(0x1Fu<<27)
#define	ADC_OFCFGR2_OFFSET_CH_0			(0x1u<<27)
#define	ADC_OFCFGR2_SSAT				(0x1u<<26)
#define	ADC_OFCFGR2_USAT				(0x1u<<25)
#define	ADC_OFCFGR2_POSOFF				(0x1u<<24)

#define	ADC_OFCFGR2_SSAT_B_0X0			(0x0u<<26)
#define	ADC_OFCFGR2_SSAT_B_0X1			(0x1u<<26)
#define	ADC_OFCFGR2_USAT_B_0X0			(0x0u<<25)
#define	ADC_OFCFGR2_USAT_B_0X1			(0x1u<<25)
#define	ADC_OFCFGR2_POSOFF_B_0X0		(0x0u<<24)
#define	ADC_OFCFGR2_POSOFF_B_0X1		(0x1u<<24)

// OFCFGR3 Configuration

#define	ADC_OFCFGR3_OFFSET_CH			(0x1Fu<<27)
#define	ADC_OFCFGR3_OFFSET_CH_0			(0x1u<<27)
#define	ADC_OFCFGR3_SSAT				(0x1u<<26)
#define	ADC_OFCFGR3_USAT				(0x1u<<25)
#define	ADC_OFCFGR3_POSOFF				(0x1u<<24)

#define	ADC_OFCFGR3_SSAT_B_0X0			(0x0u<<26)
#define	ADC_OFCFGR3_SSAT_B_0X1			(0x1u<<26)
#define	ADC_OFCFGR3_USAT_B_0X0			(0x0u<<25)
#define	ADC_OFCFGR3_USAT_B_0X1			(0x1u<<25)
#define	ADC_OFCFGR3_POSOFF_B_0X0		(0x0u<<24)
#define	ADC_OFCFGR3_POSOFF_B_0X1		(0x1u<<24)

// OFCFGR4 Configuration

#define	ADC_OFCFGR4_OFFSET_CH			(0x1Fu<<27)
#define	ADC_OFCFGR4_OFFSET_CH_0			(0x1u<<27)
#define	ADC_OFCFGR4_SSAT				(0x1u<<26)
#define	ADC_OFCFGR4_USAT				(0x1u<<25)
#define	ADC_OFCFGR4_POSOFF				(0x1u<<24)

#define	ADC_OFCFGR4_SSAT_B_0X0			(0x0u<<26)
#define	ADC_OFCFGR4_SSAT_B_0X1			(0x1u<<26)
#define	ADC_OFCFGR4_USAT_B_0X0			(0x0u<<25)
#define	ADC_OFCFGR4_USAT_B_0X1			(0x1u<<25)
#define	ADC_OFCFGR4_POSOFF_B_0X0		(0x0u<<24)
#define	ADC_OFCFGR4_POSOFF_B_0X1		(0x1u<<24)

// OFR1 Configuration

#define	ADC_OFR1_OFFSET					(0x3FFFFFu<<0)
#define	ADC_OFR1_OFFSET_0				(0x1u<<0)

// OFR2 Configuration

#define	ADC_OFR2_OFFSET					(0x3FFFFFu<<0)
#define	ADC_OFR2_OFFSET_0				(0x1u<<0)

// OFR3 Configuration

#define	ADC_OFR3_OFFSET					(0x3FFFFFu<<0)
#define	ADC_OFR3_OFFSET_0				(0x1u<<0)

// OFR4 Configuration

#define	ADC_OFR4_OFFSET					(0x3FFFFFu<<0)
#define	ADC_OFR4_OFFSET_0				(0x1u<<0)

// GCOMP Configuration

#define	ADC_GCOMP_GCOMP					(0x1u<<31)
#define	ADC_GCOMP_GCOMPCOEFF			(0x3FFFu<<0)
#define	ADC_GCOMP_GCOMPCOEFF_0			(0x1u<<0)

#define	ADC_GCOMP_GCOMP_B_0X0			(0x0u<<31)
#define	ADC_GCOMP_GCOMP_B_0X1			(0x1u<<31)
#define	ADC_GCOMP_GCOMPCOEFF_B_0X800	(0x800u<<0)
#define	ADC_GCOMP_GCOMPCOEFF_B_0X1000	(0x1000u<<0)
#define	ADC_GCOMP_GCOMPCOEFF_B_0X2000	(0x2000u<<0)
#define	ADC_GCOMP_GCOMPCOEFF_B_0X3000	(0x3000u<<0)

// JDR1 Configuration

#define	ADC_JDR1_JDATA					(0xFFFFFFFFu<<0)
#define	ADC_JDR1_JDATA_0				(0x1u<<0)

// JDR2 Configuration

#define	ADC_JDR2_JDATA					(0xFFFFFFFFu<<0)
#define	ADC_JDR2_JDATA_0				(0x1u<<0)

// JDR3 Configuration

#define	ADC_JDR3_JDATA					(0xFFFFFFFFu<<0)
#define	ADC_JDR3_JDATA_0				(0x1u<<0)

// JDR4 Configuration

#define	ADC_JDR4_JDATA					(0xFFFFFFFFu<<0)
#define	ADC_JDR4_JDATA_0				(0x1u<<0)

// AWD2CR Configuration

#define	ADC_AWD2CR_AWD2CH				(0xFFFFFu<<0)
#define	ADC_AWD2CR_AWD2CH_0				(0x1u<<0)

// AWD3CR Configuration

#define	ADC_AWD3CR_AWD3CH				(0xFFFFFu<<0)
#define	ADC_AWD3CR_AWD3CH_0				(0x1u<<0)

// AWD1LTR Configuration

#define	ADC_AWD1LTR_LTR					(0x7FFFFFu<<0)
#define	ADC_AWD1LTR_LTR_0				(0x1u<<0)

// AWD1HTR Configuration

#define	ADC_AWD1HTR_AWDFILT				(0x7u<<29)
#define	ADC_AWD1HTR_AWDFILT_0			(0x1u<<29)
#define	ADC_AWD1HTR_HTR					(0x7FFFFFu<<0)
#define	ADC_AWD1HTR_HTR_0				(0x1u<<0)

#define	ADC_AWD1HTR_AWDFILT_B_0X0		(0x0u<<29)
#define	ADC_AWD1HTR_AWDFILT_B_0X1		(0x1u<<29)
#define	ADC_AWD1HTR_AWDFILT_B_0X7		(0x7u<<29)

// AWD2LTR Configuration

#define	ADC_AWD2LTR_LTR					(0x7FFFFFu<<0)
#define	ADC_AWD2LTR_LTR_0				(0x1u<<0)

// AWD2HTR Configuration

#define	ADC_AWD2HTR_HTR					(0x7FFFFFu<<0)
#define	ADC_AWD2HTR_HTR_0				(0x1u<<0)

// AWD3LTR Configuration

#define	ADC_AWD3LTR_LTR					(0x7FFFFFu<<0)
#define	ADC_AWD3LTR_LTR_0				(0x1u<<0)

// AWD3HTR Configuration

#define	ADC_AWD3HTR_HTR					(0x7FFFFFu<<0)
#define	ADC_AWD3HTR_HTR_0				(0x1u<<0)

// DIFSEL Configuration

#define	ADC_DIFSEL_DIFSEL				(0xFFFFFu<<0)
#define	ADC_DIFSEL_DIFSEL_0				(0x1u<<0)

// CALFACT Configuration

#define	ADC_CALFACT_CALADDOS			(0x1u<<31)
#define	ADC_CALFACT_CALFACT_D			(0x1FFu<<16)
#define	ADC_CALFACT_CALFACT_D_0			(0x1u<<16)
#define	ADC_CALFACT_CALFACT_S			(0x1FFu<<0)
#define	ADC_CALFACT_CALFACT_S_0			(0x1u<<0)

#define	ADC_CALFACT_CALADDOS_B_0X0		(0x0u<<31)
#define	ADC_CALFACT_CALADDOS_B_0X1		(0x1u<<31)

// OR Configuration

#define	ADC_OR_VDDCOREEN				(0x1u<<2)
#define	ADC_OR_SELBG					(0x1u<<1)
#define	ADC_OR_SELREF					(0x1u<<0)

#define	ADC_OR_VDDCOREEN_B_0X0			(0x0u<<2)
#define	ADC_OR_VDDCOREEN_B_0X1			(0x1u<<2)
#define	ADC_OR_SELBG_B_0X0				(0x0u<<1)
#define	ADC_OR_SELBG_B_0X1				(0x1u<<1)
#define	ADC_OR_SELREF_B_0X0				(0x0u<<0)
#define	ADC_OR_SELREF_B_0X1				(0x1u<<0)
