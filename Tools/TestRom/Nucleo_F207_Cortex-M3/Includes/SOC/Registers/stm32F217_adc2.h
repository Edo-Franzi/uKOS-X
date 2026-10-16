/*
; stm32F217_adc2.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_adc2 equates.
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
	volatile	uint32_t	SR;
	volatile	uint32_t	CR1;
	volatile	uint32_t	CR2;
	volatile	uint32_t	SMPR1;
	volatile	uint32_t	SMPR2;
	volatile	uint32_t	JOFR1;
	volatile	uint32_t	JOFR2;
	volatile	uint32_t	JOFR3;
	volatile	uint32_t	JOFR4;
	volatile	uint32_t	HTR;
	volatile	uint32_t	LTR;
	volatile	uint32_t	SQR1;
	volatile	uint32_t	SQR2;
	volatile	uint32_t	SQR3;
	volatile	uint32_t	JSQR;
	volatile	uint32_t	JDR1;
	volatile	uint32_t	JDR2;
	volatile	uint32_t	JDR3;
	volatile	uint32_t	JDR4;
	volatile	uint32_t	DR;
} ADC2_TypeDef;

#if (defined(__cplusplus))
#define	ADC2	reinterpret_cast<ADC2_TypeDef *>(0x40012100u)

#else
#define	ADC2	((ADC2_TypeDef *)0x40012100u)
#endif

// SR Configuration

#define	ADC2_SR_AWD				(0x1u<<0)
#define	ADC2_SR_EOC				(0x1u<<1)
#define	ADC2_SR_JEOC			(0x1u<<2)
#define	ADC2_SR_JSTRT			(0x1u<<3)
#define	ADC2_SR_STRT			(0x1u<<4)
#define	ADC2_SR_OVR				(0x1u<<5)

// CR1 Configuration

#define	ADC2_CR1_AWDCH			(0x1Fu<<0)
#define	ADC2_CR1_AWDCH_0		(0x1u<<0)
#define	ADC2_CR1_EOCIE			(0x1u<<5)
#define	ADC2_CR1_AWDIE			(0x1u<<6)
#define	ADC2_CR1_JEOCIE			(0x1u<<7)
#define	ADC2_CR1_SCAN			(0x1u<<8)
#define	ADC2_CR1_AWDSGL			(0x1u<<9)
#define	ADC2_CR1_JAUTO			(0x1u<<10)
#define	ADC2_CR1_DISCEN			(0x1u<<11)
#define	ADC2_CR1_JDISCEN		(0x1u<<12)
#define	ADC2_CR1_DISCNUM		(0x7u<<13)
#define	ADC2_CR1_DISCNUM_0		(0x1u<<13)
#define	ADC2_CR1_JAWDEN			(0x1u<<22)
#define	ADC2_CR1_AWDEN			(0x1u<<23)
#define	ADC2_CR1_RES			(0x3u<<24)
#define	ADC2_CR1_RES_0			(0x1u<<24)
#define	ADC2_CR1_OVRIE			(0x1u<<26)

// CR2 Configuration

#define	ADC2_CR2_ADON			(0x1u<<0)
#define	ADC2_CR2_CONT			(0x1u<<1)
#define	ADC2_CR2_DMA			(0x1u<<8)
#define	ADC2_CR2_DDS			(0x1u<<9)
#define	ADC2_CR2_EOCS			(0x1u<<10)
#define	ADC2_CR2_ALIGN			(0x1u<<11)
#define	ADC2_CR2_JEXTSEL		(0xFu<<16)
#define	ADC2_CR2_JEXTSEL_0		(0x1u<<16)
#define	ADC2_CR2_JEXTEN			(0x3u<<20)
#define	ADC2_CR2_JEXTEN_0		(0x1u<<20)
#define	ADC2_CR2_JSWSTART		(0x1u<<22)
#define	ADC2_CR2_EXTSEL			(0xFu<<24)
#define	ADC2_CR2_EXTSEL_0		(0x1u<<24)
#define	ADC2_CR2_EXTEN			(0x3u<<28)
#define	ADC2_CR2_EXTEN_0		(0x1u<<28)
#define	ADC2_CR2_SWSTART		(0x1u<<30)

// SMPR1 Configuration

#define	ADC2_SMPR1_SMP18		(0x7u<<24)
#define	ADC2_SMPR1_SMP18_0		(0x1u<<24)
#define	ADC2_SMPR1_SMP17		(0x7u<<21)
#define	ADC2_SMPR1_SMP17_0		(0x1u<<21)
#define	ADC2_SMPR1_SMP16		(0x7u<<18)
#define	ADC2_SMPR1_SMP16_0		(0x1u<<18)
#define	ADC2_SMPR1_SMP15		(0x7u<<15)
#define	ADC2_SMPR1_SMP15_0		(0x1u<<15)
#define	ADC2_SMPR1_SMP14		(0x7u<<12)
#define	ADC2_SMPR1_SMP14_0		(0x1u<<12)
#define	ADC2_SMPR1_SMP13		(0x7u<<9)
#define	ADC2_SMPR1_SMP13_0		(0x1u<<9)
#define	ADC2_SMPR1_SMP12		(0x7u<<6)
#define	ADC2_SMPR1_SMP12_0		(0x1u<<6)
#define	ADC2_SMPR1_SMP11		(0x7u<<3)
#define	ADC2_SMPR1_SMP11_0		(0x1u<<3)
#define	ADC2_SMPR1_SMP10		(0x7u<<0)
#define	ADC2_SMPR1_SMP10_0		(0x1u<<0)

// SMPR2 Configuration

#define	ADC2_SMPR2_SMP9			(0x7u<<27)
#define	ADC2_SMPR2_SMP9_0		(0x1u<<27)
#define	ADC2_SMPR2_SMP8			(0x7u<<24)
#define	ADC2_SMPR2_SMP8_0		(0x1u<<24)
#define	ADC2_SMPR2_SMP7			(0x7u<<21)
#define	ADC2_SMPR2_SMP7_0		(0x1u<<21)
#define	ADC2_SMPR2_SMP6			(0x7u<<18)
#define	ADC2_SMPR2_SMP6_0		(0x1u<<18)
#define	ADC2_SMPR2_SMP5			(0x7u<<15)
#define	ADC2_SMPR2_SMP5_0		(0x1u<<15)
#define	ADC2_SMPR2_SMP4			(0x7u<<12)
#define	ADC2_SMPR2_SMP4_0		(0x1u<<12)
#define	ADC2_SMPR2_SMP3			(0x7u<<9)
#define	ADC2_SMPR2_SMP3_0		(0x1u<<9)
#define	ADC2_SMPR2_SMP2			(0x7u<<6)
#define	ADC2_SMPR2_SMP2_0		(0x1u<<6)
#define	ADC2_SMPR2_SMP1			(0x7u<<3)
#define	ADC2_SMPR2_SMP1_0		(0x1u<<3)
#define	ADC2_SMPR2_SMP0			(0x7u<<0)
#define	ADC2_SMPR2_SMP0_0		(0x1u<<0)

// JOFR1 Configuration

#define	ADC2_JOFR1_JOFFSET1		(0xFFFu<<0)
#define	ADC2_JOFR1_JOFFSET1_0	(0x1u<<0)

// JOFR2 Configuration

#define	ADC2_JOFR2_JOFFSET2		(0xFFFu<<0)
#define	ADC2_JOFR2_JOFFSET2_0	(0x1u<<0)

// JOFR3 Configuration

#define	ADC2_JOFR3_JOFFSET3		(0xFFFu<<0)
#define	ADC2_JOFR3_JOFFSET3_0	(0x1u<<0)

// JOFR4 Configuration

#define	ADC2_JOFR4_JOFFSET4		(0xFFFu<<0)
#define	ADC2_JOFR4_JOFFSET4_0	(0x1u<<0)

// HTR Configuration

#define	ADC2_HTR_HT				(0xFFFu<<0)
#define	ADC2_HTR_HT_0			(0x1u<<0)

// LTR Configuration

#define	ADC2_LTR_LT				(0xFFFu<<0)
#define	ADC2_LTR_LT_0			(0x1u<<0)

// SQR1 Configuration

#define	ADC2_SQR1_SQ13			(0x1Fu<<0)
#define	ADC2_SQR1_SQ13_0		(0x1u<<0)
#define	ADC2_SQR1_SQ14			(0x1Fu<<5)
#define	ADC2_SQR1_SQ14_0		(0x1u<<5)
#define	ADC2_SQR1_SQ15			(0x1Fu<<10)
#define	ADC2_SQR1_SQ15_0		(0x1u<<10)
#define	ADC2_SQR1_SQ16			(0x1Fu<<15)
#define	ADC2_SQR1_SQ16_0		(0x1u<<15)
#define	ADC2_SQR1_L				(0xFu<<20)
#define	ADC2_SQR1_L_0			(0x1u<<20)

// SQR2 Configuration

#define	ADC2_SQR2_SQ7			(0x1Fu<<0)
#define	ADC2_SQR2_SQ7_0			(0x1u<<0)
#define	ADC2_SQR2_SQ8			(0x1Fu<<5)
#define	ADC2_SQR2_SQ8_0			(0x1u<<5)
#define	ADC2_SQR2_SQ9			(0x1Fu<<10)
#define	ADC2_SQR2_SQ9_0			(0x1u<<10)
#define	ADC2_SQR2_SQ10			(0x1Fu<<15)
#define	ADC2_SQR2_SQ10_0		(0x1u<<15)
#define	ADC2_SQR2_SQ11			(0x1Fu<<20)
#define	ADC2_SQR2_SQ11_0		(0x1u<<20)
#define	ADC2_SQR2_SQ12			(0x1Fu<<25)
#define	ADC2_SQR2_SQ12_0		(0x1u<<25)

// SQR3 Configuration

#define	ADC2_SQR3_SQ1			(0x1Fu<<0)
#define	ADC2_SQR3_SQ1_0			(0x1u<<0)
#define	ADC2_SQR3_SQ2			(0x1Fu<<5)
#define	ADC2_SQR3_SQ2_0			(0x1u<<5)
#define	ADC2_SQR3_SQ3			(0x1Fu<<10)
#define	ADC2_SQR3_SQ3_0			(0x1u<<10)
#define	ADC2_SQR3_SQ4			(0x1Fu<<15)
#define	ADC2_SQR3_SQ4_0			(0x1u<<15)
#define	ADC2_SQR3_SQ5			(0x1Fu<<20)
#define	ADC2_SQR3_SQ5_0			(0x1u<<20)
#define	ADC2_SQR3_SQ6			(0x1Fu<<25)
#define	ADC2_SQR3_SQ6_0			(0x1u<<25)

// JSQR Configuration

#define	ADC2_JSQR_JSQ1			(0x1Fu<<0)
#define	ADC2_JSQR_JSQ1_0		(0x1u<<0)
#define	ADC2_JSQR_JSQ2			(0x1Fu<<5)
#define	ADC2_JSQR_JSQ2_0		(0x1u<<5)
#define	ADC2_JSQR_JSQ3			(0x1Fu<<10)
#define	ADC2_JSQR_JSQ3_0		(0x1u<<10)
#define	ADC2_JSQR_JSQ4			(0x1Fu<<15)
#define	ADC2_JSQR_JSQ4_0		(0x1u<<15)
#define	ADC2_JSQR_JL			(0x3u<<20)
#define	ADC2_JSQR_JL_0			(0x1u<<20)

// JDR1 Configuration

#define	ADC2_JDR1_JDATA			(0xFFFFu<<0)
#define	ADC2_JDR1_JDATA_0		(0x1u<<0)

// JDR2 Configuration

#define	ADC2_JDR2_JDATA			(0xFFFFu<<0)
#define	ADC2_JDR2_JDATA_0		(0x1u<<0)

// JDR3 Configuration

#define	ADC2_JDR3_JDATA			(0xFFFFu<<0)
#define	ADC2_JDR3_JDATA_0		(0x1u<<0)

// JDR4 Configuration

#define	ADC2_JDR4_JDATA			(0xFFFFu<<0)
#define	ADC2_JDR4_JDATA_0		(0x1u<<0)

// DR Configuration

#define	ADC2_DR_DATA			(0xFFFFu<<0)
#define	ADC2_DR_DATA_0			(0x1u<<0)
