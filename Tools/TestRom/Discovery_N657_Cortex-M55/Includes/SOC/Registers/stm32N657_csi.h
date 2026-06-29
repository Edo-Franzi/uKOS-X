/*
; stm32N657_csi.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_csi equates.
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

// CSI address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	PCR;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	VC0CFGR1;
	volatile	uint32_t	VC0CFGR2;
	volatile	uint32_t	VC0CFGR3;
	volatile	uint32_t	VC0CFGR4;
	volatile	uint32_t	VC1CFGR1;
	volatile	uint32_t	VC1CFGR2;
	volatile	uint32_t	VC1CFGR3;
	volatile	uint32_t	VC1CFGR4;
	volatile	uint32_t	VC2CFGR1;
	volatile	uint32_t	VC2CFGR2;
	volatile	uint32_t	VC2CFGR3;
	volatile	uint32_t	VC2CFGR4;
	volatile	uint32_t	VC3CFGR1;
	volatile	uint32_t	VC3CFGR2;
	volatile	uint32_t	VC3CFGR3;
	volatile	uint32_t	VC3CFGR4;
	volatile	uint32_t	LB0CFGR;
	volatile	uint32_t	LB1CFGR;
	volatile	uint32_t	LB2CFGR;
	volatile	uint32_t	LB3CFGR;
	volatile	uint32_t	TIM0CFGR;
	volatile	uint32_t	TIM1CFGR;
	volatile	uint32_t	TIM2CFGR;
	volatile	uint32_t	TIM3CFGR;
	volatile	uint32_t	LMCFGR;
	volatile	uint32_t	PRGITR;
	volatile	uint32_t	WDR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	IER0;
	volatile	uint32_t	IER1;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	SR0;
	volatile	uint32_t	SR1;
	volatile	uint32_t	RESERVED3[26];
	volatile	uint32_t	FCR0;
	volatile	uint32_t	FCR1;
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	SPDFR;
	volatile	uint32_t	ERR1;
	volatile	uint32_t	ERR2;
	volatile	uint32_t	RESERVED5[953];
	volatile	uint32_t	PRCR;
	volatile	uint32_t	PMCR;
	volatile	uint32_t	PFCR;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	PTCR0;
	volatile	uint32_t	PTCR1;
	volatile	uint32_t	PTSR;
} CSI_TypeDef;

#if (defined(__cplusplus))
#define	CSI_NS	reinterpret_cast<CSI_TypeDef *>(0x48006000u)
#define	CSI_S	reinterpret_cast<CSI_TypeDef *>(0x58006000u)

#else
#define	CSI_NS	((CSI_TypeDef *)0x48006000u)
#define	CSI_S	((CSI_TypeDef *)0x58006000u)
#endif

// CR Configuration

#define	CSI_CR_VC3STOP					(0x1u<<15)
#define	CSI_CR_VC3START					(0x1u<<14)
#define	CSI_CR_VC2STOP					(0x1u<<11)
#define	CSI_CR_VC2START					(0x1u<<10)
#define	CSI_CR_VC1STOP					(0x1u<<7)
#define	CSI_CR_VC1START					(0x1u<<6)
#define	CSI_CR_VC0STOP					(0x1u<<3)
#define	CSI_CR_VC0START					(0x1u<<2)
#define	CSI_CR_CSIEN					(0x1u<<0)

#define	CSI_CR_VC3STOP_B_0X0			(0x0u<<15)
#define	CSI_CR_VC3STOP_B_0X1			(0x1u<<15)
#define	CSI_CR_VC3START_B_0X0			(0x0u<<14)
#define	CSI_CR_VC3START_B_0X1			(0x1u<<14)
#define	CSI_CR_VC2STOP_B_0X0			(0x0u<<11)
#define	CSI_CR_VC2STOP_B_0X1			(0x1u<<11)
#define	CSI_CR_VC2START_B_0X0			(0x0u<<10)
#define	CSI_CR_VC2START_B_0X1			(0x1u<<10)
#define	CSI_CR_VC1STOP_B_0X0			(0x0u<<7)
#define	CSI_CR_VC1STOP_B_0X1			(0x1u<<7)
#define	CSI_CR_VC1START_B_0X0			(0x0u<<6)
#define	CSI_CR_VC1START_B_0X1			(0x1u<<6)
#define	CSI_CR_VC0STOP_B_0X0			(0x0u<<3)
#define	CSI_CR_VC0STOP_B_0X1			(0x1u<<3)
#define	CSI_CR_VC0START_B_0X0			(0x0u<<2)
#define	CSI_CR_VC0START_B_0X1			(0x1u<<2)
#define	CSI_CR_CSIEN_B_0X0				(0x0u<<0)
#define	CSI_CR_CSIEN_B_0X1				(0x1u<<0)

// PCR Configuration

#define	CSI_PCR_DL1EN					(0x1u<<3)
#define	CSI_PCR_DL0EN					(0x1u<<2)
#define	CSI_PCR_CLEN					(0x1u<<1)
#define	CSI_PCR_PWRDOWN					(0x1u<<0)

#define	CSI_PCR_DL1EN_B_0X0				(0x0u<<3)
#define	CSI_PCR_DL1EN_B_0X1				(0x1u<<3)
#define	CSI_PCR_DL0EN_B_0X0				(0x0u<<2)
#define	CSI_PCR_DL0EN_B_0X1				(0x1u<<2)
#define	CSI_PCR_CLEN_B_0X0				(0x0u<<1)
#define	CSI_PCR_CLEN_B_0X1				(0x1u<<1)
#define	CSI_PCR_PWRDOWN_B_0X0			(0x0u<<0)
#define	CSI_PCR_PWRDOWN_B_0X1			(0x1u<<0)

// VC0CFGR1 Configuration

#define	CSI_VC0CFGR1_DT0FT				(0x1Fu<<24)
#define	CSI_VC0CFGR1_DT0FT_0			(0x1u<<24)
#define	CSI_VC0CFGR1_DT0				(0x3Fu<<16)
#define	CSI_VC0CFGR1_DT0_0				(0x1u<<16)
#define	CSI_VC0CFGR1_CDTFT				(0x1Fu<<8)
#define	CSI_VC0CFGR1_CDTFT_0			(0x1u<<8)
#define	CSI_VC0CFGR1_DT6EN				(0x1u<<7)
#define	CSI_VC0CFGR1_DT5EN				(0x1u<<6)
#define	CSI_VC0CFGR1_DT4EN				(0x1u<<5)
#define	CSI_VC0CFGR1_DT3EN				(0x1u<<4)
#define	CSI_VC0CFGR1_DT2EN				(0x1u<<3)
#define	CSI_VC0CFGR1_DT1EN				(0x1u<<2)
#define	CSI_VC0CFGR1_DT0EN				(0x1u<<1)
#define	CSI_VC0CFGR1_ALLDT				(0x1u<<0)

#define	CSI_VC0CFGR1_DT0FT_BPP6			(0x0u<<24)
#define	CSI_VC0CFGR1_DT0FT_BPP7			(0x1u<<24)
#define	CSI_VC0CFGR1_DT0FT_BPP8			(0x2u<<24)
#define	CSI_VC0CFGR1_DT0FT_BPP10		(0x3u<<24)
#define	CSI_VC0CFGR1_DT0FT_BPP12		(0x4u<<24)
#define	CSI_VC0CFGR1_DT0FT_BPP14		(0x5u<<24)
#define	CSI_VC0CFGR1_DT0FT_BPP16		(0x6u<<24)
#define	CSI_VC0CFGR1_CDTFT_BPP6			(0x0u<<8)
#define	CSI_VC0CFGR1_CDTFT_BPP7			(0x1u<<8)
#define	CSI_VC0CFGR1_CDTFT_BPP8			(0x2u<<8)
#define	CSI_VC0CFGR1_CDTFT_BPP10		(0x3u<<8)
#define	CSI_VC0CFGR1_CDTFT_BPP12		(0x4u<<8)
#define	CSI_VC0CFGR1_CDTFT_BPP14		(0x5u<<8)
#define	CSI_VC0CFGR1_CDTFT_BPP16		(0x6u<<8)
#define	CSI_VC0CFGR1_DT6EN_B_0X0		(0x0u<<7)
#define	CSI_VC0CFGR1_DT6EN_B_0X1		(0x1u<<7)
#define	CSI_VC0CFGR1_DT5EN_B_0X0		(0x0u<<6)
#define	CSI_VC0CFGR1_DT5EN_B_0X1		(0x1u<<6)
#define	CSI_VC0CFGR1_DT4EN_B_0X0		(0x0u<<5)
#define	CSI_VC0CFGR1_DT4EN_B_0X1		(0x1u<<5)
#define	CSI_VC0CFGR1_DT3EN_B_0X0		(0x0u<<4)
#define	CSI_VC0CFGR1_DT3EN_B_0X1		(0x1u<<4)
#define	CSI_VC0CFGR1_DT2EN_B_0X0		(0x0u<<3)
#define	CSI_VC0CFGR1_DT2EN_B_0X1		(0x1u<<3)
#define	CSI_VC0CFGR1_DT1EN_B_0X0		(0x0u<<2)
#define	CSI_VC0CFGR1_DT1EN_B_0X1		(0x1u<<2)
#define	CSI_VC0CFGR1_DT0EN_B_0X0		(0x0u<<1)
#define	CSI_VC0CFGR1_DT0EN_B_0X1		(0x1u<<1)
#define	CSI_VC0CFGR1_ALLDT_B_0X0		(0x0u<<0)
#define	CSI_VC0CFGR1_ALLDT_B_0X1		(0x1u<<0)

// VC0CFGR2 Configuration

#define	CSI_VC0CFGR2_DT2FT				(0x1Fu<<24)
#define	CSI_VC0CFGR2_DT2FT_0			(0x1u<<24)
#define	CSI_VC0CFGR2_DT2				(0x3Fu<<16)
#define	CSI_VC0CFGR2_DT2_0				(0x1u<<16)
#define	CSI_VC0CFGR2_DT1FT				(0x1Fu<<8)
#define	CSI_VC0CFGR2_DT1FT_0			(0x1u<<8)
#define	CSI_VC0CFGR2_DT1				(0x3Fu<<0)
#define	CSI_VC0CFGR2_DT1_0				(0x1u<<0)

#define	CSI_VC0CFGR2_DT2FT_BPP6			(0x0u<<24)
#define	CSI_VC0CFGR2_DT2FT_BPP7			(0x1u<<24)
#define	CSI_VC0CFGR2_DT2FT_BPP8			(0x2u<<24)
#define	CSI_VC0CFGR2_DT2FT_BPP10		(0x3u<<24)
#define	CSI_VC0CFGR2_DT2FT_BPP12		(0x4u<<24)
#define	CSI_VC0CFGR2_DT2FT_BPP14		(0x5u<<24)
#define	CSI_VC0CFGR2_DT2FT_BPP16		(0x6u<<24)
#define	CSI_VC0CFGR2_DT1FT_BPP6			(0x0u<<8)
#define	CSI_VC0CFGR2_DT1FT_BPP7			(0x1u<<8)
#define	CSI_VC0CFGR2_DT1FT_BPP8			(0x2u<<8)
#define	CSI_VC0CFGR2_DT1FT_BPP10		(0x3u<<8)
#define	CSI_VC0CFGR2_DT1FT_BPP12		(0x4u<<8)
#define	CSI_VC0CFGR2_DT1FT_BPP14		(0x5u<<8)
#define	CSI_VC0CFGR2_DT1FT_BPP16		(0x6u<<8)

// VC0CFGR3 Configuration

#define	CSI_VC0CFGR3_DT4FT				(0x1Fu<<24)
#define	CSI_VC0CFGR3_DT4FT_0			(0x1u<<24)
#define	CSI_VC0CFGR3_DT4				(0x3Fu<<16)
#define	CSI_VC0CFGR3_DT4_0				(0x1u<<16)
#define	CSI_VC0CFGR3_DT3FT				(0x1Fu<<8)
#define	CSI_VC0CFGR3_DT3FT_0			(0x1u<<8)
#define	CSI_VC0CFGR3_DT3				(0x3Fu<<0)
#define	CSI_VC0CFGR3_DT3_0				(0x1u<<0)

#define	CSI_VC0CFGR3_DT4FT_BPP6			(0x0u<<24)
#define	CSI_VC0CFGR3_DT4FT_BPP7			(0x1u<<24)
#define	CSI_VC0CFGR3_DT4FT_BPP8			(0x2u<<24)
#define	CSI_VC0CFGR3_DT4FT_BPP10		(0x3u<<24)
#define	CSI_VC0CFGR3_DT4FT_BPP12		(0x4u<<24)
#define	CSI_VC0CFGR3_DT4FT_BPP14		(0x5u<<24)
#define	CSI_VC0CFGR3_DT4FT_BPP16		(0x6u<<24)
#define	CSI_VC0CFGR3_DT3FT_BPP6			(0x0u<<8)
#define	CSI_VC0CFGR3_DT3FT_BPP7			(0x1u<<8)
#define	CSI_VC0CFGR3_DT3FT_BPP8			(0x2u<<8)
#define	CSI_VC0CFGR3_DT3FT_BPP10		(0x3u<<8)
#define	CSI_VC0CFGR3_DT3FT_BPP12		(0x4u<<8)
#define	CSI_VC0CFGR3_DT3FT_BPP14		(0x5u<<8)
#define	CSI_VC0CFGR3_DT3FT_BPP16		(0x6u<<8)

// VC0CFGR4 Configuration

#define	CSI_VC0CFGR4_DT6FT				(0x1Fu<<24)
#define	CSI_VC0CFGR4_DT6FT_0			(0x1u<<24)
#define	CSI_VC0CFGR4_DT6				(0x3Fu<<16)
#define	CSI_VC0CFGR4_DT6_0				(0x1u<<16)
#define	CSI_VC0CFGR4_DT5FT				(0x1Fu<<8)
#define	CSI_VC0CFGR4_DT5FT_0			(0x1u<<8)
#define	CSI_VC0CFGR4_DT5				(0x3Fu<<0)
#define	CSI_VC0CFGR4_DT5_0				(0x1u<<0)

#define	CSI_VC0CFGR4_DT6FT_BPP6			(0x0u<<24)
#define	CSI_VC0CFGR4_DT6FT_BPP7			(0x1u<<24)
#define	CSI_VC0CFGR4_DT6FT_BPP8			(0x2u<<24)
#define	CSI_VC0CFGR4_DT6FT_BPP10		(0x3u<<24)
#define	CSI_VC0CFGR4_DT6FT_BPP12		(0x4u<<24)
#define	CSI_VC0CFGR4_DT6FT_BPP14		(0x5u<<24)
#define	CSI_VC0CFGR4_DT6FT_BPP16		(0x6u<<24)
#define	CSI_VC0CFGR4_DT5FT_BPP6			(0x0u<<8)
#define	CSI_VC0CFGR4_DT5FT_BPP7			(0x1u<<8)
#define	CSI_VC0CFGR4_DT5FT_BPP8			(0x2u<<8)
#define	CSI_VC0CFGR4_DT5FT_BPP10		(0x3u<<8)
#define	CSI_VC0CFGR4_DT5FT_BPP12		(0x4u<<8)
#define	CSI_VC0CFGR4_DT5FT_BPP14		(0x5u<<8)
#define	CSI_VC0CFGR4_DT5FT_BPP16		(0x6u<<8)

// VC1CFGR1 Configuration

#define	CSI_VC1CFGR1_DT0FT				(0x1Fu<<24)
#define	CSI_VC1CFGR1_DT0FT_0			(0x1u<<24)
#define	CSI_VC1CFGR1_DT0				(0x3Fu<<16)
#define	CSI_VC1CFGR1_DT0_0				(0x1u<<16)
#define	CSI_VC1CFGR1_CDTFT				(0x1Fu<<8)
#define	CSI_VC1CFGR1_CDTFT_0			(0x1u<<8)
#define	CSI_VC1CFGR1_DT6EN				(0x1u<<7)
#define	CSI_VC1CFGR1_DT5EN				(0x1u<<6)
#define	CSI_VC1CFGR1_DT4EN				(0x1u<<5)
#define	CSI_VC1CFGR1_DT3EN				(0x1u<<4)
#define	CSI_VC1CFGR1_DT2EN				(0x1u<<3)
#define	CSI_VC1CFGR1_DT1EN				(0x1u<<2)
#define	CSI_VC1CFGR1_DT0EN				(0x1u<<1)
#define	CSI_VC1CFGR1_ALLDT				(0x1u<<0)

#define	CSI_VC1CFGR1_DT0FT_BPP6			(0x0u<<24)
#define	CSI_VC1CFGR1_DT0FT_BPP7			(0x1u<<24)
#define	CSI_VC1CFGR1_DT0FT_BPP8			(0x2u<<24)
#define	CSI_VC1CFGR1_DT0FT_BPP10		(0x3u<<24)
#define	CSI_VC1CFGR1_DT0FT_BPP12		(0x4u<<24)
#define	CSI_VC1CFGR1_DT0FT_BPP14		(0x5u<<24)
#define	CSI_VC1CFGR1_DT0FT_BPP16		(0x6u<<24)
#define	CSI_VC1CFGR1_CDTFT_BPP6			(0x0u<<8)
#define	CSI_VC1CFGR1_CDTFT_BPP7			(0x1u<<8)
#define	CSI_VC1CFGR1_CDTFT_BPP8			(0x2u<<8)
#define	CSI_VC1CFGR1_CDTFT_BPP10		(0x3u<<8)
#define	CSI_VC1CFGR1_CDTFT_BPP12		(0x4u<<8)
#define	CSI_VC1CFGR1_CDTFT_BPP14		(0x5u<<8)
#define	CSI_VC1CFGR1_CDTFT_BPP16		(0x6u<<8)
#define	CSI_VC1CFGR1_DT6EN_B_0X0		(0x0u<<7)
#define	CSI_VC1CFGR1_DT6EN_B_0X1		(0x1u<<7)
#define	CSI_VC1CFGR1_DT5EN_B_0X0		(0x0u<<6)
#define	CSI_VC1CFGR1_DT5EN_B_0X1		(0x1u<<6)
#define	CSI_VC1CFGR1_DT4EN_B_0X0		(0x0u<<5)
#define	CSI_VC1CFGR1_DT4EN_B_0X1		(0x1u<<5)
#define	CSI_VC1CFGR1_DT3EN_B_0X0		(0x0u<<4)
#define	CSI_VC1CFGR1_DT3EN_B_0X1		(0x1u<<4)
#define	CSI_VC1CFGR1_DT2EN_B_0X0		(0x0u<<3)
#define	CSI_VC1CFGR1_DT2EN_B_0X1		(0x1u<<3)
#define	CSI_VC1CFGR1_DT1EN_B_0X0		(0x0u<<2)
#define	CSI_VC1CFGR1_DT1EN_B_0X1		(0x1u<<2)
#define	CSI_VC1CFGR1_DT0EN_B_0X0		(0x0u<<1)
#define	CSI_VC1CFGR1_DT0EN_B_0X1		(0x1u<<1)
#define	CSI_VC1CFGR1_ALLDT_B_0X0		(0x0u<<0)
#define	CSI_VC1CFGR1_ALLDT_B_0X1		(0x1u<<0)

// VC1CFGR2 Configuration

#define	CSI_VC1CFGR2_DT2FT				(0x1Fu<<24)
#define	CSI_VC1CFGR2_DT2FT_0			(0x1u<<24)
#define	CSI_VC1CFGR2_DT2				(0x3Fu<<16)
#define	CSI_VC1CFGR2_DT2_0				(0x1u<<16)
#define	CSI_VC1CFGR2_DT1FT				(0x1Fu<<8)
#define	CSI_VC1CFGR2_DT1FT_0			(0x1u<<8)
#define	CSI_VC1CFGR2_DT1				(0x3Fu<<0)
#define	CSI_VC1CFGR2_DT1_0				(0x1u<<0)

#define	CSI_VC1CFGR2_DT2FT_BPP6			(0x0u<<24)
#define	CSI_VC1CFGR2_DT2FT_BPP7			(0x1u<<24)
#define	CSI_VC1CFGR2_DT2FT_BPP8			(0x2u<<24)
#define	CSI_VC1CFGR2_DT2FT_BPP10		(0x3u<<24)
#define	CSI_VC1CFGR2_DT2FT_BPP12		(0x4u<<24)
#define	CSI_VC1CFGR2_DT2FT_BPP14		(0x5u<<24)
#define	CSI_VC1CFGR2_DT2FT_BPP16		(0x6u<<24)
#define	CSI_VC1CFGR2_DT1FT_BPP6			(0x0u<<8)
#define	CSI_VC1CFGR2_DT1FT_BPP7			(0x1u<<8)
#define	CSI_VC1CFGR2_DT1FT_BPP8			(0x2u<<8)
#define	CSI_VC1CFGR2_DT1FT_BPP10		(0x3u<<8)
#define	CSI_VC1CFGR2_DT1FT_BPP12		(0x4u<<8)
#define	CSI_VC1CFGR2_DT1FT_BPP14		(0x5u<<8)
#define	CSI_VC1CFGR2_DT1FT_BPP16		(0x6u<<8)

// VC1CFGR3 Configuration

#define	CSI_VC1CFGR3_DT4FT				(0x1Fu<<24)
#define	CSI_VC1CFGR3_DT4FT_0			(0x1u<<24)
#define	CSI_VC1CFGR3_DT4				(0x3Fu<<16)
#define	CSI_VC1CFGR3_DT4_0				(0x1u<<16)
#define	CSI_VC1CFGR3_DT3FT				(0x1Fu<<8)
#define	CSI_VC1CFGR3_DT3FT_0			(0x1u<<8)
#define	CSI_VC1CFGR3_DT3				(0x3Fu<<0)
#define	CSI_VC1CFGR3_DT3_0				(0x1u<<0)

#define	CSI_VC1CFGR3_DT4FT_BPP6			(0x0u<<24)
#define	CSI_VC1CFGR3_DT4FT_BPP7			(0x1u<<24)
#define	CSI_VC1CFGR3_DT4FT_BPP8			(0x2u<<24)
#define	CSI_VC1CFGR3_DT4FT_BPP10		(0x3u<<24)
#define	CSI_VC1CFGR3_DT4FT_BPP12		(0x4u<<24)
#define	CSI_VC1CFGR3_DT4FT_BPP14		(0x5u<<24)
#define	CSI_VC1CFGR3_DT4FT_BPP16		(0x6u<<24)
#define	CSI_VC1CFGR3_DT3FT_BPP6			(0x0u<<8)
#define	CSI_VC1CFGR3_DT3FT_BPP7			(0x1u<<8)
#define	CSI_VC1CFGR3_DT3FT_BPP8			(0x2u<<8)
#define	CSI_VC1CFGR3_DT3FT_BPP10		(0x3u<<8)
#define	CSI_VC1CFGR3_DT3FT_BPP12		(0x4u<<8)
#define	CSI_VC1CFGR3_DT3FT_BPP14		(0x5u<<8)
#define	CSI_VC1CFGR3_DT3FT_BPP16		(0x6u<<8)

// VC1CFGR4 Configuration

#define	CSI_VC1CFGR4_DT6FT				(0x1Fu<<24)
#define	CSI_VC1CFGR4_DT6FT_0			(0x1u<<24)
#define	CSI_VC1CFGR4_DT6				(0x3Fu<<16)
#define	CSI_VC1CFGR4_DT6_0				(0x1u<<16)
#define	CSI_VC1CFGR4_DT5FT				(0x1Fu<<8)
#define	CSI_VC1CFGR4_DT5FT_0			(0x1u<<8)
#define	CSI_VC1CFGR4_DT5				(0x3Fu<<0)
#define	CSI_VC1CFGR4_DT5_0				(0x1u<<0)

#define	CSI_VC1CFGR4_DT6FT_BPP6			(0x0u<<24)
#define	CSI_VC1CFGR4_DT6FT_BPP7			(0x1u<<24)
#define	CSI_VC1CFGR4_DT6FT_BPP8			(0x2u<<24)
#define	CSI_VC1CFGR4_DT6FT_BPP10		(0x3u<<24)
#define	CSI_VC1CFGR4_DT6FT_BPP12		(0x4u<<24)
#define	CSI_VC1CFGR4_DT6FT_BPP14		(0x5u<<24)
#define	CSI_VC1CFGR4_DT6FT_BPP16		(0x6u<<24)
#define	CSI_VC1CFGR4_DT5FT_BPP6			(0x0u<<8)
#define	CSI_VC1CFGR4_DT5FT_BPP7			(0x1u<<8)
#define	CSI_VC1CFGR4_DT5FT_BPP8			(0x2u<<8)
#define	CSI_VC1CFGR4_DT5FT_BPP10		(0x3u<<8)
#define	CSI_VC1CFGR4_DT5FT_BPP12		(0x4u<<8)
#define	CSI_VC1CFGR4_DT5FT_BPP14		(0x5u<<8)
#define	CSI_VC1CFGR4_DT5FT_BPP16		(0x6u<<8)

// VC2CFGR1 Configuration

#define	CSI_VC2CFGR1_DT0FT				(0x1Fu<<24)
#define	CSI_VC2CFGR1_DT0FT_0			(0x1u<<24)
#define	CSI_VC2CFGR1_DT0				(0x3Fu<<16)
#define	CSI_VC2CFGR1_DT0_0				(0x1u<<16)
#define	CSI_VC2CFGR1_CDTFT				(0x1Fu<<8)
#define	CSI_VC2CFGR1_CDTFT_0			(0x1u<<8)
#define	CSI_VC2CFGR1_DT6EN				(0x1u<<7)
#define	CSI_VC2CFGR1_DT5EN				(0x1u<<6)
#define	CSI_VC2CFGR1_DT4EN				(0x1u<<5)
#define	CSI_VC2CFGR1_DT3EN				(0x1u<<4)
#define	CSI_VC2CFGR1_DT2EN				(0x1u<<3)
#define	CSI_VC2CFGR1_DT1EN				(0x1u<<2)
#define	CSI_VC2CFGR1_DT0EN				(0x1u<<1)
#define	CSI_VC2CFGR1_ALLDT				(0x1u<<0)

#define	CSI_VC2CFGR1_DT0FT_BPP6			(0x0u<<24)
#define	CSI_VC2CFGR1_DT0FT_BPP7			(0x1u<<24)
#define	CSI_VC2CFGR1_DT0FT_BPP8			(0x2u<<24)
#define	CSI_VC2CFGR1_DT0FT_BPP10		(0x3u<<24)
#define	CSI_VC2CFGR1_DT0FT_BPP12		(0x4u<<24)
#define	CSI_VC2CFGR1_DT0FT_BPP14		(0x5u<<24)
#define	CSI_VC2CFGR1_DT0FT_BPP16		(0x6u<<24)
#define	CSI_VC2CFGR1_CDTFT_BPP6			(0x0u<<8)
#define	CSI_VC2CFGR1_CDTFT_BPP7			(0x1u<<8)
#define	CSI_VC2CFGR1_CDTFT_BPP8			(0x2u<<8)
#define	CSI_VC2CFGR1_CDTFT_BPP10		(0x3u<<8)
#define	CSI_VC2CFGR1_CDTFT_BPP12		(0x4u<<8)
#define	CSI_VC2CFGR1_CDTFT_BPP14		(0x5u<<8)
#define	CSI_VC2CFGR1_CDTFT_BPP16		(0x6u<<8)
#define	CSI_VC2CFGR1_DT6EN_B_0X0		(0x0u<<7)
#define	CSI_VC2CFGR1_DT6EN_B_0X1		(0x1u<<7)
#define	CSI_VC2CFGR1_DT5EN_B_0X0		(0x0u<<6)
#define	CSI_VC2CFGR1_DT5EN_B_0X1		(0x1u<<6)
#define	CSI_VC2CFGR1_DT4EN_B_0X0		(0x0u<<5)
#define	CSI_VC2CFGR1_DT4EN_B_0X1		(0x1u<<5)
#define	CSI_VC2CFGR1_DT3EN_B_0X0		(0x0u<<4)
#define	CSI_VC2CFGR1_DT3EN_B_0X1		(0x1u<<4)
#define	CSI_VC2CFGR1_DT2EN_B_0X0		(0x0u<<3)
#define	CSI_VC2CFGR1_DT2EN_B_0X1		(0x1u<<3)
#define	CSI_VC2CFGR1_DT1EN_B_0X0		(0x0u<<2)
#define	CSI_VC2CFGR1_DT1EN_B_0X1		(0x1u<<2)
#define	CSI_VC2CFGR1_DT0EN_B_0X0		(0x0u<<1)
#define	CSI_VC2CFGR1_DT0EN_B_0X1		(0x1u<<1)
#define	CSI_VC2CFGR1_ALLDT_B_0X0		(0x0u<<0)
#define	CSI_VC2CFGR1_ALLDT_B_0X1		(0x1u<<0)

// VC2CFGR2 Configuration

#define	CSI_VC2CFGR2_DT2FT				(0x1Fu<<24)
#define	CSI_VC2CFGR2_DT2FT_0			(0x1u<<24)
#define	CSI_VC2CFGR2_DT2				(0x3Fu<<16)
#define	CSI_VC2CFGR2_DT2_0				(0x1u<<16)
#define	CSI_VC2CFGR2_DT1FT				(0x1Fu<<8)
#define	CSI_VC2CFGR2_DT1FT_0			(0x1u<<8)
#define	CSI_VC2CFGR2_DT1				(0x3Fu<<0)
#define	CSI_VC2CFGR2_DT1_0				(0x1u<<0)

#define	CSI_VC2CFGR2_DT2FT_BPP6			(0x0u<<24)
#define	CSI_VC2CFGR2_DT2FT_BPP7			(0x1u<<24)
#define	CSI_VC2CFGR2_DT2FT_BPP8			(0x2u<<24)
#define	CSI_VC2CFGR2_DT2FT_BPP10		(0x3u<<24)
#define	CSI_VC2CFGR2_DT2FT_BPP12		(0x4u<<24)
#define	CSI_VC2CFGR2_DT2FT_BPP14		(0x5u<<24)
#define	CSI_VC2CFGR2_DT2FT_BPP16		(0x6u<<24)
#define	CSI_VC2CFGR2_DT1FT_BPP6			(0x0u<<8)
#define	CSI_VC2CFGR2_DT1FT_BPP7			(0x1u<<8)
#define	CSI_VC2CFGR2_DT1FT_BPP8			(0x2u<<8)
#define	CSI_VC2CFGR2_DT1FT_BPP10		(0x3u<<8)
#define	CSI_VC2CFGR2_DT1FT_BPP12		(0x4u<<8)
#define	CSI_VC2CFGR2_DT1FT_BPP14		(0x5u<<8)
#define	CSI_VC2CFGR2_DT1FT_BPP16		(0x6u<<8)

// VC2CFGR3 Configuration

#define	CSI_VC2CFGR3_DT4FT				(0x1Fu<<24)
#define	CSI_VC2CFGR3_DT4FT_0			(0x1u<<24)
#define	CSI_VC2CFGR3_DT4				(0x3Fu<<16)
#define	CSI_VC2CFGR3_DT4_0				(0x1u<<16)
#define	CSI_VC2CFGR3_DT3FT				(0x1Fu<<8)
#define	CSI_VC2CFGR3_DT3FT_0			(0x1u<<8)
#define	CSI_VC2CFGR3_DT3				(0x3Fu<<0)
#define	CSI_VC2CFGR3_DT3_0				(0x1u<<0)

#define	CSI_VC2CFGR3_DT4FT_BPP6			(0x0u<<24)
#define	CSI_VC2CFGR3_DT4FT_BPP7			(0x1u<<24)
#define	CSI_VC2CFGR3_DT4FT_BPP8			(0x2u<<24)
#define	CSI_VC2CFGR3_DT4FT_BPP10		(0x3u<<24)
#define	CSI_VC2CFGR3_DT4FT_BPP12		(0x4u<<24)
#define	CSI_VC2CFGR3_DT4FT_BPP14		(0x5u<<24)
#define	CSI_VC2CFGR3_DT4FT_BPP16		(0x6u<<24)
#define	CSI_VC2CFGR3_DT3FT_BPP6			(0x0u<<8)
#define	CSI_VC2CFGR3_DT3FT_BPP7			(0x1u<<8)
#define	CSI_VC2CFGR3_DT3FT_BPP8			(0x2u<<8)
#define	CSI_VC2CFGR3_DT3FT_BPP10		(0x3u<<8)
#define	CSI_VC2CFGR3_DT3FT_BPP12		(0x4u<<8)
#define	CSI_VC2CFGR3_DT3FT_BPP14		(0x5u<<8)
#define	CSI_VC2CFGR3_DT3FT_BPP16		(0x6u<<8)

// VC2CFGR4 Configuration

#define	CSI_VC2CFGR4_DT6FT				(0x1Fu<<24)
#define	CSI_VC2CFGR4_DT6FT_0			(0x1u<<24)
#define	CSI_VC2CFGR4_DT6				(0x3Fu<<16)
#define	CSI_VC2CFGR4_DT6_0				(0x1u<<16)
#define	CSI_VC2CFGR4_DT5FT				(0x1Fu<<8)
#define	CSI_VC2CFGR4_DT5FT_0			(0x1u<<8)
#define	CSI_VC2CFGR4_DT5				(0x3Fu<<0)
#define	CSI_VC2CFGR4_DT5_0				(0x1u<<0)

#define	CSI_VC2CFGR4_DT6FT_BPP6			(0x0u<<24)
#define	CSI_VC2CFGR4_DT6FT_BPP7			(0x1u<<24)
#define	CSI_VC2CFGR4_DT6FT_BPP8			(0x2u<<24)
#define	CSI_VC2CFGR4_DT6FT_BPP10		(0x3u<<24)
#define	CSI_VC2CFGR4_DT6FT_BPP12		(0x4u<<24)
#define	CSI_VC2CFGR4_DT6FT_BPP14		(0x5u<<24)
#define	CSI_VC2CFGR4_DT6FT_BPP16		(0x6u<<24)
#define	CSI_VC2CFGR4_DT5FT_BPP6			(0x0u<<8)
#define	CSI_VC2CFGR4_DT5FT_BPP7			(0x1u<<8)
#define	CSI_VC2CFGR4_DT5FT_BPP8			(0x2u<<8)
#define	CSI_VC2CFGR4_DT5FT_BPP10		(0x3u<<8)
#define	CSI_VC2CFGR4_DT5FT_BPP12		(0x4u<<8)
#define	CSI_VC2CFGR4_DT5FT_BPP14		(0x5u<<8)
#define	CSI_VC2CFGR4_DT5FT_BPP16		(0x6u<<8)

// VC3CFGR1 Configuration

#define	CSI_VC3CFGR1_DT0FT				(0x1Fu<<24)
#define	CSI_VC3CFGR1_DT0FT_0			(0x1u<<24)
#define	CSI_VC3CFGR1_DT0				(0x3Fu<<16)
#define	CSI_VC3CFGR1_DT0_0				(0x1u<<16)
#define	CSI_VC3CFGR1_CDTFT				(0x1Fu<<8)
#define	CSI_VC3CFGR1_CDTFT_0			(0x1u<<8)
#define	CSI_VC3CFGR1_DT6EN				(0x1u<<7)
#define	CSI_VC3CFGR1_DT5EN				(0x1u<<6)
#define	CSI_VC3CFGR1_DT4EN				(0x1u<<5)
#define	CSI_VC3CFGR1_DT3EN				(0x1u<<4)
#define	CSI_VC3CFGR1_DT2EN				(0x1u<<3)
#define	CSI_VC3CFGR1_DT1EN				(0x1u<<2)
#define	CSI_VC3CFGR1_DT0EN				(0x1u<<1)
#define	CSI_VC3CFGR1_ALLDT				(0x1u<<0)

#define	CSI_VC3CFGR1_DT0FT_BPP6			(0x0u<<24)
#define	CSI_VC3CFGR1_DT0FT_BPP7			(0x1u<<24)
#define	CSI_VC3CFGR1_DT0FT_BPP8			(0x2u<<24)
#define	CSI_VC3CFGR1_DT0FT_BPP10		(0x3u<<24)
#define	CSI_VC3CFGR1_DT0FT_BPP12		(0x4u<<24)
#define	CSI_VC3CFGR1_DT0FT_BPP14		(0x5u<<24)
#define	CSI_VC3CFGR1_DT0FT_BPP16		(0x6u<<24)
#define	CSI_VC3CFGR1_CDTFT_BPP6			(0x0u<<8)
#define	CSI_VC3CFGR1_CDTFT_BPP7			(0x1u<<8)
#define	CSI_VC3CFGR1_CDTFT_BPP8			(0x2u<<8)
#define	CSI_VC3CFGR1_CDTFT_BPP10		(0x3u<<8)
#define	CSI_VC3CFGR1_CDTFT_BPP12		(0x4u<<8)
#define	CSI_VC3CFGR1_CDTFT_BPP14		(0x5u<<8)
#define	CSI_VC3CFGR1_CDTFT_BPP16		(0x6u<<8)
#define	CSI_VC3CFGR1_DT6EN_B_0X0		(0x0u<<7)
#define	CSI_VC3CFGR1_DT6EN_B_0X1		(0x1u<<7)
#define	CSI_VC3CFGR1_DT5EN_B_0X0		(0x0u<<6)
#define	CSI_VC3CFGR1_DT5EN_B_0X1		(0x1u<<6)
#define	CSI_VC3CFGR1_DT4EN_B_0X0		(0x0u<<5)
#define	CSI_VC3CFGR1_DT4EN_B_0X1		(0x1u<<5)
#define	CSI_VC3CFGR1_DT3EN_B_0X0		(0x0u<<4)
#define	CSI_VC3CFGR1_DT3EN_B_0X1		(0x1u<<4)
#define	CSI_VC3CFGR1_DT2EN_B_0X0		(0x0u<<3)
#define	CSI_VC3CFGR1_DT2EN_B_0X1		(0x1u<<3)
#define	CSI_VC3CFGR1_DT1EN_B_0X0		(0x0u<<2)
#define	CSI_VC3CFGR1_DT1EN_B_0X1		(0x1u<<2)
#define	CSI_VC3CFGR1_DT0EN_B_0X0		(0x0u<<1)
#define	CSI_VC3CFGR1_DT0EN_B_0X1		(0x1u<<1)
#define	CSI_VC3CFGR1_ALLDT_B_0X0		(0x0u<<0)
#define	CSI_VC3CFGR1_ALLDT_B_0X1		(0x1u<<0)

// VC3CFGR2 Configuration

#define	CSI_VC3CFGR2_DT2FT				(0x1Fu<<24)
#define	CSI_VC3CFGR2_DT2FT_0			(0x1u<<24)
#define	CSI_VC3CFGR2_DT2				(0x3Fu<<16)
#define	CSI_VC3CFGR2_DT2_0				(0x1u<<16)
#define	CSI_VC3CFGR2_DT1FT				(0x1Fu<<8)
#define	CSI_VC3CFGR2_DT1FT_0			(0x1u<<8)
#define	CSI_VC3CFGR2_DT1				(0x3Fu<<0)
#define	CSI_VC3CFGR2_DT1_0				(0x1u<<0)

#define	CSI_VC3CFGR2_DT2FT_BPP6			(0x0u<<24)
#define	CSI_VC3CFGR2_DT2FT_BPP7			(0x1u<<24)
#define	CSI_VC3CFGR2_DT2FT_BPP8			(0x2u<<24)
#define	CSI_VC3CFGR2_DT2FT_BPP10		(0x3u<<24)
#define	CSI_VC3CFGR2_DT2FT_BPP12		(0x4u<<24)
#define	CSI_VC3CFGR2_DT2FT_BPP14		(0x5u<<24)
#define	CSI_VC3CFGR2_DT2FT_BPP16		(0x6u<<24)
#define	CSI_VC3CFGR2_DT1FT_BPP6			(0x0u<<8)
#define	CSI_VC3CFGR2_DT1FT_BPP7			(0x1u<<8)
#define	CSI_VC3CFGR2_DT1FT_BPP8			(0x2u<<8)
#define	CSI_VC3CFGR2_DT1FT_BPP10		(0x3u<<8)
#define	CSI_VC3CFGR2_DT1FT_BPP12		(0x4u<<8)
#define	CSI_VC3CFGR2_DT1FT_BPP14		(0x5u<<8)
#define	CSI_VC3CFGR2_DT1FT_BPP16		(0x6u<<8)

// VC3CFGR3 Configuration

#define	CSI_VC3CFGR3_DT4FT				(0x1Fu<<24)
#define	CSI_VC3CFGR3_DT4FT_0			(0x1u<<24)
#define	CSI_VC3CFGR3_DT4				(0x3Fu<<16)
#define	CSI_VC3CFGR3_DT4_0				(0x1u<<16)
#define	CSI_VC3CFGR3_DT3FT				(0x1Fu<<8)
#define	CSI_VC3CFGR3_DT3FT_0			(0x1u<<8)
#define	CSI_VC3CFGR3_DT3				(0x3Fu<<0)
#define	CSI_VC3CFGR3_DT3_0				(0x1u<<0)

#define	CSI_VC3CFGR3_DT4FT_BPP6			(0x0u<<24)
#define	CSI_VC3CFGR3_DT4FT_BPP7			(0x1u<<24)
#define	CSI_VC3CFGR3_DT4FT_BPP8			(0x2u<<24)
#define	CSI_VC3CFGR3_DT4FT_BPP10		(0x3u<<24)
#define	CSI_VC3CFGR3_DT4FT_BPP12		(0x4u<<24)
#define	CSI_VC3CFGR3_DT4FT_BPP14		(0x5u<<24)
#define	CSI_VC3CFGR3_DT4FT_BPP16		(0x6u<<24)
#define	CSI_VC3CFGR3_DT3FT_BPP6			(0x0u<<8)
#define	CSI_VC3CFGR3_DT3FT_BPP7			(0x1u<<8)
#define	CSI_VC3CFGR3_DT3FT_BPP8			(0x2u<<8)
#define	CSI_VC3CFGR3_DT3FT_BPP10		(0x3u<<8)
#define	CSI_VC3CFGR3_DT3FT_BPP12		(0x4u<<8)
#define	CSI_VC3CFGR3_DT3FT_BPP14		(0x5u<<8)
#define	CSI_VC3CFGR3_DT3FT_BPP16		(0x6u<<8)

// VC3CFGR4 Configuration

#define	CSI_VC3CFGR4_DT6FT				(0x1Fu<<24)
#define	CSI_VC3CFGR4_DT6FT_0			(0x1u<<24)
#define	CSI_VC3CFGR4_DT6				(0x3Fu<<16)
#define	CSI_VC3CFGR4_DT6_0				(0x1u<<16)
#define	CSI_VC3CFGR4_DT5FT				(0x1Fu<<8)
#define	CSI_VC3CFGR4_DT5FT_0			(0x1u<<8)
#define	CSI_VC3CFGR4_DT5				(0x3Fu<<0)
#define	CSI_VC3CFGR4_DT5_0				(0x1u<<0)

#define	CSI_VC3CFGR4_DT6FT_BPP6			(0x0u<<24)
#define	CSI_VC3CFGR4_DT6FT_BPP7			(0x1u<<24)
#define	CSI_VC3CFGR4_DT6FT_BPP8			(0x2u<<24)
#define	CSI_VC3CFGR4_DT6FT_BPP10		(0x3u<<24)
#define	CSI_VC3CFGR4_DT6FT_BPP12		(0x4u<<24)
#define	CSI_VC3CFGR4_DT6FT_BPP14		(0x5u<<24)
#define	CSI_VC3CFGR4_DT6FT_BPP16		(0x6u<<24)
#define	CSI_VC3CFGR4_DT5FT_BPP6			(0x0u<<8)
#define	CSI_VC3CFGR4_DT5FT_BPP7			(0x1u<<8)
#define	CSI_VC3CFGR4_DT5FT_BPP8			(0x2u<<8)
#define	CSI_VC3CFGR4_DT5FT_BPP10		(0x3u<<8)
#define	CSI_VC3CFGR4_DT5FT_BPP12		(0x4u<<8)
#define	CSI_VC3CFGR4_DT5FT_BPP14		(0x5u<<8)
#define	CSI_VC3CFGR4_DT5FT_BPP16		(0x6u<<8)

// LB0CFGR Configuration

#define	CSI_LB0CFGR_LINECNT				(0xFFFFu<<16)
#define	CSI_LB0CFGR_LINECNT_0			(0x1u<<16)
#define	CSI_LB0CFGR_BYTECNT				(0xFFFFu<<0)
#define	CSI_LB0CFGR_BYTECNT_0			(0x1u<<0)

// LB1CFGR Configuration

#define	CSI_LB1CFGR_LINECNT				(0xFFFFu<<16)
#define	CSI_LB1CFGR_LINECNT_0			(0x1u<<16)
#define	CSI_LB1CFGR_BYTECNT				(0xFFFFu<<0)
#define	CSI_LB1CFGR_BYTECNT_0			(0x1u<<0)

// LB2CFGR Configuration

#define	CSI_LB2CFGR_LINECNT				(0xFFFFu<<16)
#define	CSI_LB2CFGR_LINECNT_0			(0x1u<<16)
#define	CSI_LB2CFGR_BYTECNT				(0xFFFFu<<0)
#define	CSI_LB2CFGR_BYTECNT_0			(0x1u<<0)

// LB3CFGR Configuration

#define	CSI_LB3CFGR_LINECNT				(0xFFFFu<<16)
#define	CSI_LB3CFGR_LINECNT_0			(0x1u<<16)
#define	CSI_LB3CFGR_BYTECNT				(0xFFFFu<<0)
#define	CSI_LB3CFGR_BYTECNT_0			(0x1u<<0)

// TIM0CFGR Configuration

#define	CSI_TIM0CFGR_COUNT				(0x1FFFFFFu<<0)
#define	CSI_TIM0CFGR_COUNT_0			(0x1u<<0)

// TIM1CFGR Configuration

#define	CSI_TIM1CFGR_COUNT				(0x1FFFFFFu<<0)
#define	CSI_TIM1CFGR_COUNT_0			(0x1u<<0)

// TIM2CFGR Configuration

#define	CSI_TIM2CFGR_COUNT				(0x1FFFFFFu<<0)
#define	CSI_TIM2CFGR_COUNT_0			(0x1u<<0)

// TIM3CFGR Configuration

#define	CSI_TIM3CFGR_COUNT				(0x1FFFFFFu<<0)
#define	CSI_TIM3CFGR_COUNT_0			(0x1u<<0)

// LMCFGR Configuration

#define	CSI_LMCFGR_DL1MAP				(0x7u<<20)
#define	CSI_LMCFGR_DL1MAP_0				(0x1u<<20)
#define	CSI_LMCFGR_DL0MAP				(0x7u<<16)
#define	CSI_LMCFGR_DL0MAP_0				(0x1u<<16)
#define	CSI_LMCFGR_LANENB				(0x7u<<8)
#define	CSI_LMCFGR_LANENB_0				(0x1u<<8)

#define	CSI_LMCFGR_DL1MAP_B_0X1			(0x1u<<20)
#define	CSI_LMCFGR_DL1MAP_B_0X2			(0x2u<<20)
#define	CSI_LMCFGR_DL0MAP_B_0X1			(0x1u<<16)
#define	CSI_LMCFGR_DL0MAP_B_0X2			(0x2u<<16)
#define	CSI_LMCFGR_LANENB_B_0X1			(0x1u<<8)
#define	CSI_LMCFGR_LANENB_B_0X2			(0x2u<<8)

// PRGITR Configuration

#define	CSI_PRGITR_TIM3EN				(0x1u<<31)
#define	CSI_PRGITR_TIM3EOF				(0x1u<<30)
#define	CSI_PRGITR_TIM3VC				(0x3u<<28)
#define	CSI_PRGITR_TIM3VC_0				(0x1u<<28)
#define	CSI_PRGITR_TIM2EN				(0x1u<<27)
#define	CSI_PRGITR_TIM2EOF				(0x1u<<26)
#define	CSI_PRGITR_TIM2VC				(0x3u<<24)
#define	CSI_PRGITR_TIM2VC_0				(0x1u<<24)
#define	CSI_PRGITR_TIM1EN				(0x1u<<23)
#define	CSI_PRGITR_TIM1EOF				(0x1u<<22)
#define	CSI_PRGITR_TIM1VC				(0x3u<<20)
#define	CSI_PRGITR_TIM1VC_0				(0x1u<<20)
#define	CSI_PRGITR_TIM0EN				(0x1u<<19)
#define	CSI_PRGITR_TIM0EOF				(0x1u<<18)
#define	CSI_PRGITR_TIM0VC				(0x3u<<16)
#define	CSI_PRGITR_TIM0VC_0				(0x1u<<16)
#define	CSI_PRGITR_LB3EN				(0x1u<<15)
#define	CSI_PRGITR_LB3VC				(0x3u<<12)
#define	CSI_PRGITR_LB3VC_0				(0x1u<<12)
#define	CSI_PRGITR_LB2EN				(0x1u<<11)
#define	CSI_PRGITR_LB2VC				(0x3u<<8)
#define	CSI_PRGITR_LB2VC_0				(0x1u<<8)
#define	CSI_PRGITR_LB1EN				(0x1u<<7)
#define	CSI_PRGITR_LB1VC				(0x3u<<4)
#define	CSI_PRGITR_LB1VC_0				(0x1u<<4)
#define	CSI_PRGITR_LB0EN				(0x1u<<3)
#define	CSI_PRGITR_LB0VC				(0x3u<<0)
#define	CSI_PRGITR_LB0VC_0				(0x1u<<0)

#define	CSI_PRGITR_TIM3EN_B_0X0			(0x0u<<31)
#define	CSI_PRGITR_TIM3EN_B_0X1			(0x1u<<31)
#define	CSI_PRGITR_TIM3EOF_B_0X0		(0x0u<<30)
#define	CSI_PRGITR_TIM3EOF_B_0X1		(0x1u<<30)
#define	CSI_PRGITR_TIM3VC_B_0X0			(0x0u<<28)
#define	CSI_PRGITR_TIM3VC_B_0X1			(0x1u<<28)
#define	CSI_PRGITR_TIM3VC_B_0X2			(0x2u<<28)
#define	CSI_PRGITR_TIM3VC_B_0X3			(0x3u<<28)
#define	CSI_PRGITR_TIM2EN_B_0X0			(0x0u<<27)
#define	CSI_PRGITR_TIM2EN_B_0X1			(0x1u<<27)
#define	CSI_PRGITR_TIM2EOF_B_0X0		(0x0u<<26)
#define	CSI_PRGITR_TIM2EOF_B_0X1		(0x1u<<26)
#define	CSI_PRGITR_TIM2VC_B_0X0			(0x0u<<24)
#define	CSI_PRGITR_TIM2VC_B_0X1			(0x1u<<24)
#define	CSI_PRGITR_TIM2VC_B_0X2			(0x2u<<24)
#define	CSI_PRGITR_TIM2VC_B_0X3			(0x3u<<24)
#define	CSI_PRGITR_TIM1EN_B_0X0			(0x0u<<23)
#define	CSI_PRGITR_TIM1EN_B_0X1			(0x1u<<23)
#define	CSI_PRGITR_TIM1EOF_B_0X0		(0x0u<<22)
#define	CSI_PRGITR_TIM1EOF_B_0X1		(0x1u<<22)
#define	CSI_PRGITR_TIM1VC_B_0X0			(0x0u<<20)
#define	CSI_PRGITR_TIM1VC_B_0X1			(0x1u<<20)
#define	CSI_PRGITR_TIM1VC_B_0X2			(0x2u<<20)
#define	CSI_PRGITR_TIM1VC_B_0X3			(0x3u<<20)
#define	CSI_PRGITR_TIM0EN_B_0X0			(0x0u<<19)
#define	CSI_PRGITR_TIM0EN_B_0X1			(0x1u<<19)
#define	CSI_PRGITR_TIM0EOF_B_0X0		(0x0u<<18)
#define	CSI_PRGITR_TIM0EOF_B_0X1		(0x1u<<18)
#define	CSI_PRGITR_TIM0VC_B_0X0			(0x0u<<16)
#define	CSI_PRGITR_TIM0VC_B_0X1			(0x1u<<16)
#define	CSI_PRGITR_TIM0VC_B_0X2			(0x2u<<16)
#define	CSI_PRGITR_TIM0VC_B_0X3			(0x3u<<16)
#define	CSI_PRGITR_LB3EN_B_0X0			(0x0u<<15)
#define	CSI_PRGITR_LB3EN_B_0X1			(0x1u<<15)
#define	CSI_PRGITR_LB3VC_B_0X0			(0x0u<<12)
#define	CSI_PRGITR_LB3VC_B_0X1			(0x1u<<12)
#define	CSI_PRGITR_LB3VC_B_0X2			(0x2u<<12)
#define	CSI_PRGITR_LB3VC_B_0X3			(0x3u<<12)
#define	CSI_PRGITR_LB2EN_B_0X0			(0x0u<<11)
#define	CSI_PRGITR_LB2EN_B_0X1			(0x1u<<11)
#define	CSI_PRGITR_LB2VC_B_0X0			(0x0u<<8)
#define	CSI_PRGITR_LB2VC_B_0X1			(0x1u<<8)
#define	CSI_PRGITR_LB2VC_B_0X2			(0x2u<<8)
#define	CSI_PRGITR_LB2VC_B_0X3			(0x3u<<8)
#define	CSI_PRGITR_LB1EN_B_0X0			(0x0u<<7)
#define	CSI_PRGITR_LB1EN_B_0X1			(0x1u<<7)
#define	CSI_PRGITR_LB1VC_B_0X0			(0x0u<<4)
#define	CSI_PRGITR_LB1VC_B_0X1			(0x1u<<4)
#define	CSI_PRGITR_LB1VC_B_0X2			(0x2u<<4)
#define	CSI_PRGITR_LB1VC_B_0X3			(0x3u<<4)
#define	CSI_PRGITR_LB0EN_B_0X0			(0x0u<<3)
#define	CSI_PRGITR_LB0EN_B_0X1			(0x1u<<3)
#define	CSI_PRGITR_LB0VC_B_0X0			(0x0u<<0)
#define	CSI_PRGITR_LB0VC_B_0X1			(0x1u<<0)
#define	CSI_PRGITR_LB0VC_B_0X2			(0x2u<<0)
#define	CSI_PRGITR_LB0VC_B_0X3			(0x3u<<0)

// WDR Configuration

#define	CSI_WDR_CNT						(0xFFFFFFFFu<<0)
#define	CSI_WDR_CNT_0					(0x1u<<0)

// IER0 Configuration

#define	CSI_IER0_SYNCERRIE				(0x1u<<30)
#define	CSI_IER0_WDERRIE				(0x1u<<29)
#define	CSI_IER0_SPKTERRIE				(0x1u<<28)
#define	CSI_IER0_IDERRIE				(0x1u<<27)
#define	CSI_IER0_CECCERRIE				(0x1u<<26)
#define	CSI_IER0_ECCERRIE				(0x1u<<25)
#define	CSI_IER0_CRCERRIE				(0x1u<<24)
#define	CSI_IER0_CCFIFOFIE				(0x1u<<21)
#define	CSI_IER0_SPKTIE					(0x1u<<16)
#define	CSI_IER0_EOF3IE					(0x1u<<15)
#define	CSI_IER0_EOF2IE					(0x1u<<14)
#define	CSI_IER0_EOF1IE					(0x1u<<13)
#define	CSI_IER0_EOF0IE					(0x1u<<12)
#define	CSI_IER0_SOF3IE					(0x1u<<11)
#define	CSI_IER0_SOF2IE					(0x1u<<10)
#define	CSI_IER0_SOF1IE					(0x1u<<9)
#define	CSI_IER0_SOF0IE					(0x1u<<8)
#define	CSI_IER0_TIM3IE					(0x1u<<7)
#define	CSI_IER0_TIM2IE					(0x1u<<6)
#define	CSI_IER0_TIM1IE					(0x1u<<5)
#define	CSI_IER0_TIM0IE					(0x1u<<4)
#define	CSI_IER0_LB3IE					(0x1u<<3)
#define	CSI_IER0_LB2IE					(0x1u<<2)
#define	CSI_IER0_LB1IE					(0x1u<<1)
#define	CSI_IER0_LB0IE					(0x1u<<0)

#define	CSI_IER0_SYNCERRIE_B_0X0		(0x0u<<30)
#define	CSI_IER0_SYNCERRIE_B_0X1		(0x1u<<30)
#define	CSI_IER0_WDERRIE_B_0X0			(0x0u<<29)
#define	CSI_IER0_WDERRIE_B_0X1			(0x1u<<29)
#define	CSI_IER0_SPKTERRIE_B_0X0		(0x0u<<28)
#define	CSI_IER0_SPKTERRIE_B_0X1		(0x1u<<28)
#define	CSI_IER0_IDERRIE_B_0X0			(0x0u<<27)
#define	CSI_IER0_IDERRIE_B_0X1			(0x1u<<27)
#define	CSI_IER0_CECCERRIE_B_0X0		(0x0u<<26)
#define	CSI_IER0_CECCERRIE_B_0X1		(0x1u<<26)
#define	CSI_IER0_ECCERRIE_B_0X0			(0x0u<<25)
#define	CSI_IER0_ECCERRIE_B_0X1			(0x1u<<25)
#define	CSI_IER0_CRCERRIE_B_0X0			(0x0u<<24)
#define	CSI_IER0_CRCERRIE_B_0X1			(0x1u<<24)
#define	CSI_IER0_CCFIFOFIE_B_0X0		(0x0u<<21)
#define	CSI_IER0_CCFIFOFIE_B_0X1		(0x1u<<21)
#define	CSI_IER0_SPKTIE_B_0X0			(0x0u<<16)
#define	CSI_IER0_SPKTIE_B_0X1			(0x1u<<16)
#define	CSI_IER0_EOF3IE_B_0X0			(0x0u<<15)
#define	CSI_IER0_EOF3IE_B_0X1			(0x1u<<15)
#define	CSI_IER0_EOF2IE_B_0X0			(0x0u<<14)
#define	CSI_IER0_EOF2IE_B_0X1			(0x1u<<14)
#define	CSI_IER0_EOF1IE_B_0X0			(0x0u<<13)
#define	CSI_IER0_EOF1IE_B_0X1			(0x1u<<13)
#define	CSI_IER0_EOF0IE_B_0X0			(0x0u<<12)
#define	CSI_IER0_EOF0IE_B_0X1			(0x1u<<12)
#define	CSI_IER0_SOF3IE_B_0X0			(0x0u<<11)
#define	CSI_IER0_SOF3IE_B_0X1			(0x1u<<11)
#define	CSI_IER0_SOF2IE_B_0X0			(0x0u<<10)
#define	CSI_IER0_SOF2IE_B_0X1			(0x1u<<10)
#define	CSI_IER0_SOF1IE_B_0X0			(0x0u<<9)
#define	CSI_IER0_SOF1IE_B_0X1			(0x1u<<9)
#define	CSI_IER0_SOF0IE_B_0X0			(0x0u<<8)
#define	CSI_IER0_SOF0IE_B_0X1			(0x1u<<8)
#define	CSI_IER0_TIM3IE_B_0X0			(0x0u<<7)
#define	CSI_IER0_TIM3IE_B_0X1			(0x1u<<7)
#define	CSI_IER0_TIM2IE_B_0X0			(0x0u<<6)
#define	CSI_IER0_TIM2IE_B_0X1			(0x1u<<6)
#define	CSI_IER0_TIM1IE_B_0X0			(0x0u<<5)
#define	CSI_IER0_TIM1IE_B_0X1			(0x1u<<5)
#define	CSI_IER0_TIM0IE_B_0X0			(0x0u<<4)
#define	CSI_IER0_TIM0IE_B_0X1			(0x1u<<4)

// IER1 Configuration

#define	CSI_IER1_ECTRLDL1IE				(0x1u<<12)
#define	CSI_IER1_ESYNCESCDL1IE			(0x1u<<11)
#define	CSI_IER1_EESCDL1IE				(0x1u<<10)
#define	CSI_IER1_ESOTSYNCDL1IE			(0x1u<<9)
#define	CSI_IER1_ESOTDL1IE				(0x1u<<8)
#define	CSI_IER1_ECTRLDL0IE				(0x1u<<4)
#define	CSI_IER1_ESYNCESCDL0IE			(0x1u<<3)
#define	CSI_IER1_EESCDL0IE				(0x1u<<2)
#define	CSI_IER1_ESOTSYNCDL0IE			(0x1u<<1)
#define	CSI_IER1_ESOTDL0IE				(0x1u<<0)

#define	CSI_IER1_ECTRLDL1IE_B_0X0		(0x0u<<12)
#define	CSI_IER1_ECTRLDL1IE_B_0X1		(0x1u<<12)
#define	CSI_IER1_ESYNCESCDL1IE_B_0X0	(0x0u<<11)
#define	CSI_IER1_ESYNCESCDL1IE_B_0X1	(0x1u<<11)
#define	CSI_IER1_EESCDL1IE_B_0X0		(0x0u<<10)
#define	CSI_IER1_EESCDL1IE_B_0X1		(0x1u<<10)
#define	CSI_IER1_ESOTSYNCDL1IE_B_0X0	(0x0u<<9)
#define	CSI_IER1_ESOTSYNCDL1IE_B_0X1	(0x1u<<9)
#define	CSI_IER1_ESOTDL1IE_B_0X0		(0x0u<<8)
#define	CSI_IER1_ESOTDL1IE_B_0X1		(0x1u<<8)
#define	CSI_IER1_ECTRLDL0IE_B_0X0		(0x0u<<4)
#define	CSI_IER1_ECTRLDL0IE_B_0X1		(0x1u<<4)
#define	CSI_IER1_ESYNCESCDL0IE_B_0X0	(0x0u<<3)
#define	CSI_IER1_ESYNCESCDL0IE_B_0X1	(0x1u<<3)
#define	CSI_IER1_EESCDL0IE_B_0X0		(0x0u<<2)
#define	CSI_IER1_EESCDL0IE_B_0X1		(0x1u<<2)
#define	CSI_IER1_ESOTSYNCDL0IE_B_0X0	(0x0u<<1)
#define	CSI_IER1_ESOTSYNCDL0IE_B_0X1	(0x1u<<1)
#define	CSI_IER1_ESOTDL0IE_B_0X0		(0x0u<<0)
#define	CSI_IER1_ESOTDL0IE_B_0X1		(0x1u<<0)

// SR0 Configuration

#define	CSI_SR0_SYNCERRF				(0x1u<<30)
#define	CSI_SR0_WDERRF					(0x1u<<29)
#define	CSI_SR0_SPKTERRF				(0x1u<<28)
#define	CSI_SR0_IDERRF					(0x1u<<27)
#define	CSI_SR0_CECCERRF				(0x1u<<26)
#define	CSI_SR0_ECCERRF					(0x1u<<25)
#define	CSI_SR0_CRCERRF					(0x1u<<24)
#define	CSI_SR0_CCFIFOFF				(0x1u<<21)
#define	CSI_SR0_VC3STATEF				(0x1u<<20)
#define	CSI_SR0_VC2STATEF				(0x1u<<19)
#define	CSI_SR0_VC1STATEF				(0x1u<<18)
#define	CSI_SR0_VC0STATEF				(0x1u<<17)
#define	CSI_SR0_SPKTF					(0x1u<<16)
#define	CSI_SR0_EOF3F					(0x1u<<15)
#define	CSI_SR0_EOF2F					(0x1u<<14)
#define	CSI_SR0_EOF1F					(0x1u<<13)
#define	CSI_SR0_EOF0F					(0x1u<<12)
#define	CSI_SR0_SOF3F					(0x1u<<11)
#define	CSI_SR0_SOF2F					(0x1u<<10)
#define	CSI_SR0_SOF1F					(0x1u<<9)
#define	CSI_SR0_SOF0F					(0x1u<<8)
#define	CSI_SR0_TIM3F					(0x1u<<7)
#define	CSI_SR0_TIM2F					(0x1u<<6)
#define	CSI_SR0_TIM1F					(0x1u<<5)
#define	CSI_SR0_TIM0F					(0x1u<<4)
#define	CSI_SR0_LB3F					(0x1u<<3)
#define	CSI_SR0_LB2F					(0x1u<<2)
#define	CSI_SR0_LB1F					(0x1u<<1)
#define	CSI_SR0_LB0F					(0x1u<<0)

#define	CSI_SR0_VC3STATEF_B_0X0			(0x0u<<20)
#define	CSI_SR0_VC3STATEF_B_0X1			(0x1u<<20)
#define	CSI_SR0_VC2STATEF_B_0X0			(0x0u<<19)
#define	CSI_SR0_VC2STATEF_B_0X1			(0x1u<<19)
#define	CSI_SR0_VC1STATEF_B_0X0			(0x0u<<18)
#define	CSI_SR0_VC1STATEF_B_0X1			(0x1u<<18)
#define	CSI_SR0_VC0STATEF_B_0X0			(0x0u<<17)
#define	CSI_SR0_VC0STATEF_B_0X1			(0x1u<<17)

// SR1 Configuration

#define	CSI_SR1_ACTCLF					(0x1u<<31)
#define	CSI_SR1_ULPNCLF					(0x1u<<30)
#define	CSI_SR1_ULPNACTF				(0x1u<<29)
#define	CSI_SR1_STOPCLF					(0x1u<<28)
#define	CSI_SR1_ULPNDL1F				(0x1u<<26)
#define	CSI_SR1_STOPDL1F				(0x1u<<25)
#define	CSI_SR1_SKCALDL1F				(0x1u<<24)
#define	CSI_SR1_SYNCDL1F				(0x1u<<23)
#define	CSI_SR1_ACTDL1F					(0x1u<<22)
#define	CSI_SR1_ULPNDL0F				(0x1u<<20)
#define	CSI_SR1_STOPDL0F				(0x1u<<19)
#define	CSI_SR1_SKCALDL0F				(0x1u<<18)
#define	CSI_SR1_SYNCDL0F				(0x1u<<17)
#define	CSI_SR1_ACTDL0F					(0x1u<<16)
#define	CSI_SR1_ECTRLDL1F				(0x1u<<12)
#define	CSI_SR1_ESYNCESCDL1F			(0x1u<<11)
#define	CSI_SR1_EESCDL1F				(0x1u<<10)
#define	CSI_SR1_ESOTSYNCDL1F			(0x1u<<9)
#define	CSI_SR1_ESOTDL1F				(0x1u<<8)
#define	CSI_SR1_ECTRLDL0F				(0x1u<<4)
#define	CSI_SR1_ESYNCESCDL0F			(0x1u<<3)
#define	CSI_SR1_EESCDL0F				(0x1u<<2)
#define	CSI_SR1_ESOTSYNCDL0F			(0x1u<<1)
#define	CSI_SR1_ESOTDL0F				(0x1u<<0)

// FCR0 Configuration

#define	CSI_FCR0_CSYNCERRF				(0x1u<<30)
#define	CSI_FCR0_CWDERRF				(0x1u<<29)
#define	CSI_FCR0_CSPKTERRF				(0x1u<<28)
#define	CSI_FCR0_CIDERRF				(0x1u<<27)
#define	CSI_FCR0_CCECCERRF				(0x1u<<26)
#define	CSI_FCR0_CECCERRF				(0x1u<<25)
#define	CSI_FCR0_CCRCERRF				(0x1u<<24)
#define	CSI_FCR0_CCCFIFOFF				(0x1u<<21)
#define	CSI_FCR0_CSPKTF					(0x1u<<16)
#define	CSI_FCR0_CEOF3F					(0x1u<<15)
#define	CSI_FCR0_CEOF2F					(0x1u<<14)
#define	CSI_FCR0_CEOF1F					(0x1u<<13)
#define	CSI_FCR0_CEOF0F					(0x1u<<12)
#define	CSI_FCR0_CSOF3F					(0x1u<<11)
#define	CSI_FCR0_CSOF2F					(0x1u<<10)
#define	CSI_FCR0_CSOF1F					(0x1u<<9)
#define	CSI_FCR0_CSOF0F					(0x1u<<8)
#define	CSI_FCR0_CTIM3F					(0x1u<<7)
#define	CSI_FCR0_CTIM2F					(0x1u<<6)
#define	CSI_FCR0_CTIM1F					(0x1u<<5)
#define	CSI_FCR0_CTIM0F					(0x1u<<4)
#define	CSI_FCR0_CLB3F					(0x1u<<3)
#define	CSI_FCR0_CLB2F					(0x1u<<2)
#define	CSI_FCR0_CLB1F					(0x1u<<1)
#define	CSI_FCR0_CLB0F					(0x1u<<0)

// FCR1 Configuration

#define	CSI_FCR1_CECTRLDL1F				(0x1u<<12)
#define	CSI_FCR1_CESYNCESCDL1F			(0x1u<<11)
#define	CSI_FCR1_CEESCDL1F				(0x1u<<10)
#define	CSI_FCR1_CESOTSYNCDL1F			(0x1u<<9)
#define	CSI_FCR1_CESOTDL1F				(0x1u<<8)
#define	CSI_FCR1_CECTRLDL0F				(0x1u<<4)
#define	CSI_FCR1_CESYNCESCDL0F			(0x1u<<3)
#define	CSI_FCR1_CEESCDL0F				(0x1u<<2)
#define	CSI_FCR1_CESOTSYNCDL0F			(0x1u<<1)
#define	CSI_FCR1_CESOTDL0F				(0x1u<<0)

// SPDFR Configuration

#define	CSI_SPDFR_VCHANNEL				(0x3u<<22)
#define	CSI_SPDFR_VCHANNEL_0			(0x1u<<22)
#define	CSI_SPDFR_DATATYPE				(0x3Fu<<16)
#define	CSI_SPDFR_DATATYPE_0			(0x1u<<16)
#define	CSI_SPDFR_DATAFIELD				(0xFFFFu<<0)
#define	CSI_SPDFR_DATAFIELD_0			(0x1u<<0)

// ERR1 Configuration

#define	CSI_ERR1_IDVCERR				(0x3u<<22)
#define	CSI_ERR1_IDVCERR_0				(0x1u<<22)
#define	CSI_ERR1_IDDTERR				(0x3Fu<<16)
#define	CSI_ERR1_IDDTERR_0				(0x1u<<16)
#define	CSI_ERR1_CECCVCERR				(0x3u<<14)
#define	CSI_ERR1_CECCVCERR_0			(0x1u<<14)
#define	CSI_ERR1_CECCDTERR				(0x3Fu<<8)
#define	CSI_ERR1_CECCDTERR_0			(0x1u<<8)
#define	CSI_ERR1_CRCVCERR				(0x3u<<6)
#define	CSI_ERR1_CRCVCERR_0				(0x1u<<6)
#define	CSI_ERR1_CRCDTERR				(0x3Fu<<0)
#define	CSI_ERR1_CRCDTERR_0				(0x1u<<0)

// ERR2 Configuration

#define	CSI_ERR2_SYNCVCERR				(0x3u<<18)
#define	CSI_ERR2_SYNCVCERR_0			(0x1u<<18)
#define	CSI_ERR2_WDVCERR				(0x3u<<16)
#define	CSI_ERR2_WDVCERR_0				(0x1u<<16)
#define	CSI_ERR2_SPKTVCERR				(0x3u<<6)
#define	CSI_ERR2_SPKTVCERR_0			(0x1u<<6)
#define	CSI_ERR2_SPKTDTERR				(0x3Fu<<0)
#define	CSI_ERR2_SPKTDTERR_0			(0x1u<<0)

// PRCR Configuration

#define	CSI_PRCR_PEN					(0x1u<<1)

#define	CSI_PRCR_PEN_B_0X0				(0x0u<<1)
#define	CSI_PRCR_PEN_B_0X1				(0x1u<<1)

// PMCR Configuration

#define	CSI_PMCR_TUEXDL0				(0x1u<<16)
#define	CSI_PMCR_TUESDL0				(0x1u<<12)
#define	CSI_PMCR_RTDL0					(0x1u<<8)
#define	CSI_PMCR_DTDL					(0x1u<<4)
#define	CSI_PMCR_FTXSMDL0				(0x1u<<2)
#define	CSI_PMCR_FRXMDL1				(0x1u<<1)
#define	CSI_PMCR_FRXMDL0				(0x1u<<0)

#define	CSI_PMCR_RTDL0_B_0X0			(0x0u<<8)
#define	CSI_PMCR_RTDL0_B_0X1			(0x1u<<8)
#define	CSI_PMCR_DTDL_B_0X0				(0x0u<<4)
#define	CSI_PMCR_DTDL_B_0X1				(0x1u<<4)
#define	CSI_PMCR_FTXSMDL0_B_0X0			(0x0u<<2)
#define	CSI_PMCR_FTXSMDL0_B_0X1			(0x1u<<2)
#define	CSI_PMCR_FRXMDL1_B_0X0			(0x0u<<1)
#define	CSI_PMCR_FRXMDL1_B_0X1			(0x1u<<1)
#define	CSI_PMCR_FRXMDL0_B_0X0			(0x0u<<0)
#define	CSI_PMCR_FRXMDL0_B_0X1			(0x1u<<0)

// PFCR Configuration

#define	CSI_PFCR_DLD					(0x1u<<16)
#define	CSI_PFCR_HSFR					(0x7Fu<<8)
#define	CSI_PFCR_HSFR_0					(0x1u<<8)
#define	CSI_PFCR_CCFR					(0x3Fu<<0)
#define	CSI_PFCR_CCFR_0					(0x1u<<0)

#define	CSI_PFCR_DLD_B_0X0				(0x0u<<16)
#define	CSI_PFCR_DLD_B_0X1				(0x1u<<16)

// PTCR0 Configuration

#define	CSI_PTCR0_TRSEN					(0x1u<<1)
#define	CSI_PTCR0_TCKEN					(0x1u<<0)

// PTCR1 Configuration

#define	CSI_PTCR1_TWM					(0x1u<<16)
#define	CSI_PTCR1_TDI					(0xFFu<<0)
#define	CSI_PTCR1_TDI_0					(0x1u<<0)

#define	CSI_PTCR1_TWM_B_0X0				(0x0u<<16)
#define	CSI_PTCR1_TWM_B_0X1				(0x1u<<16)

// PTSR Configuration

#define	CSI_PTSR_TDO					(0xFFu<<0)
#define	CSI_PTSR_TDO_0					(0x1u<<0)
