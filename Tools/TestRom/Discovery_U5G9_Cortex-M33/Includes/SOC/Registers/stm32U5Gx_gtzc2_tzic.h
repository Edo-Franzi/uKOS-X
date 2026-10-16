/*
; stm32U5Gx_gtzc2_tzic.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_gtzc2_tzic equates.
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

// GTZC2_TZIC address definitions
// ------------------------------

typedef struct {
	volatile	uint32_t	IER1;
	volatile	uint32_t	IER2;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	SR1;
	volatile	uint32_t	SR2;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	FCR1;
	volatile	uint32_t	FCR2;
} GTZC2_TZIC_TypeDef;

#if (defined(__cplusplus))
#define	GTZC2_TZIC_NS	reinterpret_cast<GTZC2_TZIC_TypeDef *>(0x46023400u)
#define	GTZC2_TZIC_S	reinterpret_cast<GTZC2_TZIC_TypeDef *>(0x56023400u)

#else
#define	GTZC2_TZIC_NS	((GTZC2_TZIC_TypeDef *)0x46023400u)
#define	GTZC2_TZIC_S	((GTZC2_TZIC_TypeDef *)0x56023400u)
#endif

// IER1 Configuration

#define	GTZC2_TZIC_IER1_ADF1IE			(0x1u<<12)
#define	GTZC2_TZIC_IER1_DAC1IE			(0x1u<<11)
#define	GTZC2_TZIC_IER1_VREFBUFIE		(0x1u<<9)
#define	GTZC2_TZIC_IER1_ADC2IE			(0x1u<<8)
#define	GTZC2_TZIC_IER1_COMPIE			(0x1u<<7)
#define	GTZC2_TZIC_IER1_OPAMPIE			(0x1u<<6)
#define	GTZC2_TZIC_IER1_LPTIM4IE		(0x1u<<5)
#define	GTZC2_TZIC_IER1_LPTIM3IE		(0x1u<<4)
#define	GTZC2_TZIC_IER1_LPTIM1IE		(0x1u<<3)
#define	GTZC2_TZIC_IER1_I2C3IE			(0x1u<<2)
#define	GTZC2_TZIC_IER1_LPUART1IE		(0x1u<<1)
#define	GTZC2_TZIC_IER1_SPI3IE			(0x1u<<0)

// IER2 Configuration

#define	GTZC2_TZIC_IER2_MPCBB4_REGIE	(0x1u<<25)
#define	GTZC2_TZIC_IER2_SRAM4IE			(0x1u<<24)
#define	GTZC2_TZIC_IER2_TZIC2IE			(0x1u<<15)
#define	GTZC2_TZIC_IER2_TZSC2IE			(0x1u<<14)
#define	GTZC2_TZIC_IER2_EXTIIE			(0x1u<<6)
#define	GTZC2_TZIC_IER2_LPDMA1IE		(0x1u<<5)
#define	GTZC2_TZIC_IER2_RCCIE			(0x1u<<4)
#define	GTZC2_TZIC_IER2_PWRIE			(0x1u<<3)
#define	GTZC2_TZIC_IER2_TAMPIE			(0x1u<<2)
#define	GTZC2_TZIC_IER2_RTCIE			(0x1u<<1)
#define	GTZC2_TZIC_IER2_SYSCFGIE		(0x1u<<0)

// SR1 Configuration

#define	GTZC2_TZIC_SR1_ADF1F			(0x1u<<12)
#define	GTZC2_TZIC_SR1_DAC1F			(0x1u<<11)
#define	GTZC2_TZIC_SR1_VREFBUFF			(0x1u<<9)
#define	GTZC2_TZIC_SR1_ADC2F			(0x1u<<8)
#define	GTZC2_TZIC_SR1_COMPF			(0x1u<<7)
#define	GTZC2_TZIC_SR1_OPAMPF			(0x1u<<6)
#define	GTZC2_TZIC_SR1_LPTIM4F			(0x1u<<5)
#define	GTZC2_TZIC_SR1_LPTIM3F			(0x1u<<4)
#define	GTZC2_TZIC_SR1_LPTIM1F			(0x1u<<3)
#define	GTZC2_TZIC_SR1_I2C3F			(0x1u<<2)
#define	GTZC2_TZIC_SR1_LPUART1F			(0x1u<<1)
#define	GTZC2_TZIC_SR1_SPI3F			(0x1u<<0)

// SR2 Configuration

#define	GTZC2_TZIC_SR2_MPCBB4_REGF		(0x1u<<25)
#define	GTZC2_TZIC_SR2_SRAM4F			(0x1u<<24)
#define	GTZC2_TZIC_SR2_TZIC2F			(0x1u<<15)
#define	GTZC2_TZIC_SR2_TZSC2F			(0x1u<<14)
#define	GTZC2_TZIC_SR2_EXTIF			(0x1u<<6)
#define	GTZC2_TZIC_SR2_LPDMA1F			(0x1u<<5)
#define	GTZC2_TZIC_SR2_RCCF				(0x1u<<4)
#define	GTZC2_TZIC_SR2_PWRF				(0x1u<<3)
#define	GTZC2_TZIC_SR2_TAMPF			(0x1u<<2)
#define	GTZC2_TZIC_SR2_RTCF				(0x1u<<1)
#define	GTZC2_TZIC_SR2_SYSCFGF			(0x1u<<0)

// FCR1 Configuration

#define	GTZC2_TZIC_FCR1_CADF1F			(0x1u<<12)
#define	GTZC2_TZIC_FCR1_CDAC1F			(0x1u<<11)
#define	GTZC2_TZIC_FCR1_CVREFBUFF		(0x1u<<9)
#define	GTZC2_TZIC_FCR1_CADC2F			(0x1u<<8)
#define	GTZC2_TZIC_FCR1_CCOMPF			(0x1u<<7)
#define	GTZC2_TZIC_FCR1_COPAMPF			(0x1u<<6)
#define	GTZC2_TZIC_FCR1_CLPTIM4F		(0x1u<<5)
#define	GTZC2_TZIC_FCR1_CLPTIM3F		(0x1u<<4)
#define	GTZC2_TZIC_FCR1_CLPTIM1F		(0x1u<<3)
#define	GTZC2_TZIC_FCR1_CI2C3F			(0x1u<<2)
#define	GTZC2_TZIC_FCR1_CLPUART1F		(0x1u<<1)
#define	GTZC2_TZIC_FCR1_CSPI3F			(0x1u<<0)

// FCR2 Configuration

#define	GTZC2_TZIC_FCR2_CMPCBB4_REGF	(0x1u<<25)
#define	GTZC2_TZIC_FCR2_CSRAM4F			(0x1u<<24)
#define	GTZC2_TZIC_FCR2_CTZIC2F			(0x1u<<15)
#define	GTZC2_TZIC_FCR2_CTZSC2F			(0x1u<<14)
#define	GTZC2_TZIC_FCR2_CEXTIF			(0x1u<<6)
#define	GTZC2_TZIC_FCR2_CLPDMA1F		(0x1u<<5)
#define	GTZC2_TZIC_FCR2_CRCCF			(0x1u<<4)
#define	GTZC2_TZIC_FCR2_CPWRF			(0x1u<<3)
#define	GTZC2_TZIC_FCR2_CTAMPF			(0x1u<<2)
#define	GTZC2_TZIC_FCR2_CRTCF			(0x1u<<1)
#define	GTZC2_TZIC_FCR2_CSYSCFGF		(0x1u<<0)
