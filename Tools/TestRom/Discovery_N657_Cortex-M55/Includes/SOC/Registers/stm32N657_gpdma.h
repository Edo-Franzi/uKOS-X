/*
; stm32N657_gpdma.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_gpdma equates.
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

// GPDMA address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	SECCFGR;
	volatile	uint32_t	PRIVCFGR;
	volatile	uint32_t	RCFGLOCKR;
	volatile	uint32_t	MISR;
	volatile	uint32_t	SMISR;
	volatile	uint32_t	RESERVED0[15];
	volatile	uint32_t	C0LBAR;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	C0FCR;
	volatile	uint32_t	C0SR;
	volatile	uint32_t	C0CR;
	volatile	uint32_t	RESERVED2[10];
	volatile	uint32_t	C0TR1;
	volatile	uint32_t	C0TR2;
	volatile	uint32_t	C0BR1;
	volatile	uint32_t	C0SAR;
	volatile	uint32_t	C0DAR;
	volatile	uint32_t	RESERVED3[10];
	volatile	uint32_t	C0LLR;
	volatile	uint32_t	C1LBAR;
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	C1FCR;
	volatile	uint32_t	C1SR;
	volatile	uint32_t	C1CR;
	volatile	uint32_t	RESERVED5[10];
	volatile	uint32_t	C1TR1;
	volatile	uint32_t	C1TR2;
	volatile	uint32_t	C1BR1;
	volatile	uint32_t	C1SAR;
	volatile	uint32_t	C1DAR;
	volatile	uint32_t	RESERVED6[10];
	volatile	uint32_t	C1LLR;
	volatile	uint32_t	C2LBAR;
	volatile	uint32_t	RESERVED7[2];
	volatile	uint32_t	C2FCR;
	volatile	uint32_t	C2SR;
	volatile	uint32_t	C2CR;
	volatile	uint32_t	RESERVED8[10];
	volatile	uint32_t	C2TR1;
	volatile	uint32_t	C2TR2;
	volatile	uint32_t	C2BR1;
	volatile	uint32_t	C2SAR;
	volatile	uint32_t	C2DAR;
	volatile	uint32_t	RESERVED9[10];
	volatile	uint32_t	C2LLR;
	volatile	uint32_t	C3LBAR;
	volatile	uint32_t	RESERVED10[2];
	volatile	uint32_t	C3FCR;
	volatile	uint32_t	C3SR;
	volatile	uint32_t	C3CR;
	volatile	uint32_t	RESERVED11[10];
	volatile	uint32_t	C3TR1;
	volatile	uint32_t	C3TR2;
	volatile	uint32_t	C3BR1;
	volatile	uint32_t	C3SAR;
	volatile	uint32_t	C3DAR;
	volatile	uint32_t	RESERVED12[10];
	volatile	uint32_t	C3LLR;
	volatile	uint32_t	C4LBAR;
	volatile	uint32_t	RESERVED13[2];
	volatile	uint32_t	C4FCR;
	volatile	uint32_t	C4SR;
	volatile	uint32_t	C4CR;
	volatile	uint32_t	RESERVED14[10];
	volatile	uint32_t	C4TR1;
	volatile	uint32_t	C4TR2;
	volatile	uint32_t	C4BR1;
	volatile	uint32_t	C4SAR;
	volatile	uint32_t	C4DAR;
	volatile	uint32_t	RESERVED15[10];
	volatile	uint32_t	C4LLR;
	volatile	uint32_t	C5LBAR;
	volatile	uint32_t	RESERVED16[2];
	volatile	uint32_t	C5FCR;
	volatile	uint32_t	C5SR;
	volatile	uint32_t	C5CR;
	volatile	uint32_t	RESERVED17[10];
	volatile	uint32_t	C5TR1;
	volatile	uint32_t	C5TR2;
	volatile	uint32_t	C5BR1;
	volatile	uint32_t	C5SAR;
	volatile	uint32_t	C5DAR;
	volatile	uint32_t	RESERVED18[10];
	volatile	uint32_t	C5LLR;
	volatile	uint32_t	C6LBAR;
	volatile	uint32_t	RESERVED19[2];
	volatile	uint32_t	C6FCR;
	volatile	uint32_t	C6SR;
	volatile	uint32_t	C6CR;
	volatile	uint32_t	RESERVED20[10];
	volatile	uint32_t	C6TR1;
	volatile	uint32_t	C6TR2;
	volatile	uint32_t	C6BR1;
	volatile	uint32_t	C6SAR;
	volatile	uint32_t	C6DAR;
	volatile	uint32_t	RESERVED21[10];
	volatile	uint32_t	C6LLR;
	volatile	uint32_t	C7LBAR;
	volatile	uint32_t	RESERVED22[2];
	volatile	uint32_t	C7FCR;
	volatile	uint32_t	C7SR;
	volatile	uint32_t	C7CR;
	volatile	uint32_t	RESERVED23[10];
	volatile	uint32_t	C7TR1;
	volatile	uint32_t	C7TR2;
	volatile	uint32_t	C7BR1;
	volatile	uint32_t	C7SAR;
	volatile	uint32_t	C7DAR;
	volatile	uint32_t	RESERVED24[10];
	volatile	uint32_t	C7LLR;
	volatile	uint32_t	C8LBAR;
	volatile	uint32_t	RESERVED25[2];
	volatile	uint32_t	C8FCR;
	volatile	uint32_t	C8SR;
	volatile	uint32_t	C8CR;
	volatile	uint32_t	RESERVED26[10];
	volatile	uint32_t	C8TR1;
	volatile	uint32_t	C8TR2;
	volatile	uint32_t	C8BR1;
	volatile	uint32_t	C8SAR;
	volatile	uint32_t	C8DAR;
	volatile	uint32_t	RESERVED27[10];
	volatile	uint32_t	C8LLR;
	volatile	uint32_t	C9LBAR;
	volatile	uint32_t	RESERVED28[2];
	volatile	uint32_t	C9FCR;
	volatile	uint32_t	C9SR;
	volatile	uint32_t	C9CR;
	volatile	uint32_t	RESERVED29[10];
	volatile	uint32_t	C9TR1;
	volatile	uint32_t	C9TR2;
	volatile	uint32_t	C9BR1;
	volatile	uint32_t	C9SAR;
	volatile	uint32_t	C9DAR;
	volatile	uint32_t	RESERVED30[10];
	volatile	uint32_t	C9LLR;
	volatile	uint32_t	C10LBAR;
	volatile	uint32_t	RESERVED31[2];
	volatile	uint32_t	C10FCR;
	volatile	uint32_t	C10SR;
	volatile	uint32_t	C10CR;
	volatile	uint32_t	RESERVED32[10];
	volatile	uint32_t	C10TR1;
	volatile	uint32_t	C10TR2;
	volatile	uint32_t	C10BR1;
	volatile	uint32_t	C10SAR;
	volatile	uint32_t	C10DAR;
	volatile	uint32_t	RESERVED33[10];
	volatile	uint32_t	C10LLR;
	volatile	uint32_t	C11LBAR;
	volatile	uint32_t	RESERVED34[2];
	volatile	uint32_t	C11FCR;
	volatile	uint32_t	C11SR;
	volatile	uint32_t	C11CR;
	volatile	uint32_t	RESERVED35[10];
	volatile	uint32_t	C11TR1;
	volatile	uint32_t	C11TR2;
	volatile	uint32_t	C11BR1;
	volatile	uint32_t	C11SAR;
	volatile	uint32_t	C11DAR;
	volatile	uint32_t	RESERVED36[10];
	volatile	uint32_t	C11LLR;
	volatile	uint32_t	C12LBAR;
	volatile	uint32_t	RESERVED37[2];
	volatile	uint32_t	C12FCR;
	volatile	uint32_t	C12SR;
	volatile	uint32_t	C12CR;
	volatile	uint32_t	RESERVED38[10];
	volatile	uint32_t	C12TR1;
	volatile	uint32_t	C12TR2;
	volatile	uint32_t	C12BR1;
	volatile	uint32_t	C12SAR;
	volatile	uint32_t	C12DAR;
	volatile	uint32_t	C12TR3;
	volatile	uint32_t	C12BR2;
	volatile	uint32_t	RESERVED39[8];
	volatile	uint32_t	C12LLR;
	volatile	uint32_t	C13LBAR;
	volatile	uint32_t	RESERVED40[2];
	volatile	uint32_t	C13FCR;
	volatile	uint32_t	C13SR;
	volatile	uint32_t	C13CR;
	volatile	uint32_t	RESERVED41[10];
	volatile	uint32_t	C13TR1;
	volatile	uint32_t	C13TR2;
	volatile	uint32_t	C13BR1;
	volatile	uint32_t	C13SAR;
	volatile	uint32_t	C13DAR;
	volatile	uint32_t	C13TR3;
	volatile	uint32_t	C13BR2;
	volatile	uint32_t	RESERVED42[8];
	volatile	uint32_t	C13LLR;
	volatile	uint32_t	C14LBAR;
	volatile	uint32_t	RESERVED43[2];
	volatile	uint32_t	C14FCR;
	volatile	uint32_t	C14SR;
	volatile	uint32_t	C14CR;
	volatile	uint32_t	RESERVED44[10];
	volatile	uint32_t	C14TR1;
	volatile	uint32_t	C14TR2;
	volatile	uint32_t	C14BR1;
	volatile	uint32_t	C14SAR;
	volatile	uint32_t	C14DAR;
	volatile	uint32_t	C14TR3;
	volatile	uint32_t	C14BR2;
	volatile	uint32_t	RESERVED45[8];
	volatile	uint32_t	C14LLR;
	volatile	uint32_t	C15LBAR;
	volatile	uint32_t	RESERVED46[2];
	volatile	uint32_t	C15FCR;
	volatile	uint32_t	C15SR;
	volatile	uint32_t	C15CR;
	volatile	uint32_t	RESERVED47[10];
	volatile	uint32_t	C15TR1;
	volatile	uint32_t	C15TR2;
	volatile	uint32_t	C15BR1;
	volatile	uint32_t	C15SAR;
	volatile	uint32_t	C15DAR;
	volatile	uint32_t	C15TR3;
	volatile	uint32_t	C15BR2;
	volatile	uint32_t	RESERVED48[8];
	volatile	uint32_t	C15LLR;
} GPDMA_TypeDef;

#if (defined(__cplusplus))
#define	GPDMA_NS	reinterpret_cast<GPDMA_TypeDef *>(0x40021000u)
#define	GPDMA_S		reinterpret_cast<GPDMA_TypeDef *>(0x50021000u)

#else
#define	GPDMA_NS	((GPDMA_TypeDef *)0x40021000u)
#define	GPDMA_S		((GPDMA_TypeDef *)0x50021000u)
#endif

// SECCFGR Configuration

#define	GPDMA_SECCFGR_SEC15				(0x1u<<15)
#define	GPDMA_SECCFGR_SEC14				(0x1u<<14)
#define	GPDMA_SECCFGR_SEC13				(0x1u<<13)
#define	GPDMA_SECCFGR_SEC12				(0x1u<<12)
#define	GPDMA_SECCFGR_SEC11				(0x1u<<11)
#define	GPDMA_SECCFGR_SEC10				(0x1u<<10)
#define	GPDMA_SECCFGR_SEC9				(0x1u<<9)
#define	GPDMA_SECCFGR_SEC8				(0x1u<<8)
#define	GPDMA_SECCFGR_SEC7				(0x1u<<7)
#define	GPDMA_SECCFGR_SEC6				(0x1u<<6)
#define	GPDMA_SECCFGR_SEC5				(0x1u<<5)
#define	GPDMA_SECCFGR_SEC4				(0x1u<<4)
#define	GPDMA_SECCFGR_SEC3				(0x1u<<3)
#define	GPDMA_SECCFGR_SEC2				(0x1u<<2)
#define	GPDMA_SECCFGR_SEC1				(0x1u<<1)
#define	GPDMA_SECCFGR_SEC0				(0x1u<<0)

#define	GPDMA_SECCFGR_SEC15_B_0X0		(0x0u<<15)
#define	GPDMA_SECCFGR_SEC15_B_0X1		(0x1u<<15)
#define	GPDMA_SECCFGR_SEC14_B_0X0		(0x0u<<14)
#define	GPDMA_SECCFGR_SEC14_B_0X1		(0x1u<<14)
#define	GPDMA_SECCFGR_SEC13_B_0X0		(0x0u<<13)
#define	GPDMA_SECCFGR_SEC13_B_0X1		(0x1u<<13)
#define	GPDMA_SECCFGR_SEC12_B_0X0		(0x0u<<12)
#define	GPDMA_SECCFGR_SEC12_B_0X1		(0x1u<<12)
#define	GPDMA_SECCFGR_SEC11_B_0X0		(0x0u<<11)
#define	GPDMA_SECCFGR_SEC11_B_0X1		(0x1u<<11)
#define	GPDMA_SECCFGR_SEC10_B_0X0		(0x0u<<10)
#define	GPDMA_SECCFGR_SEC10_B_0X1		(0x1u<<10)
#define	GPDMA_SECCFGR_SEC9_B_0X0		(0x0u<<9)
#define	GPDMA_SECCFGR_SEC9_B_0X1		(0x1u<<9)
#define	GPDMA_SECCFGR_SEC8_B_0X0		(0x0u<<8)
#define	GPDMA_SECCFGR_SEC8_B_0X1		(0x1u<<8)
#define	GPDMA_SECCFGR_SEC7_B_0X0		(0x0u<<7)
#define	GPDMA_SECCFGR_SEC7_B_0X1		(0x1u<<7)
#define	GPDMA_SECCFGR_SEC6_B_0X0		(0x0u<<6)
#define	GPDMA_SECCFGR_SEC6_B_0X1		(0x1u<<6)
#define	GPDMA_SECCFGR_SEC5_B_0X0		(0x0u<<5)
#define	GPDMA_SECCFGR_SEC5_B_0X1		(0x1u<<5)
#define	GPDMA_SECCFGR_SEC4_B_0X0		(0x0u<<4)
#define	GPDMA_SECCFGR_SEC4_B_0X1		(0x1u<<4)
#define	GPDMA_SECCFGR_SEC3_B_0X0		(0x0u<<3)
#define	GPDMA_SECCFGR_SEC3_B_0X1		(0x1u<<3)
#define	GPDMA_SECCFGR_SEC2_B_0X0		(0x0u<<2)
#define	GPDMA_SECCFGR_SEC2_B_0X1		(0x1u<<2)
#define	GPDMA_SECCFGR_SEC1_B_0X0		(0x0u<<1)
#define	GPDMA_SECCFGR_SEC1_B_0X1		(0x1u<<1)
#define	GPDMA_SECCFGR_SEC0_B_0X0		(0x0u<<0)
#define	GPDMA_SECCFGR_SEC0_B_0X1		(0x1u<<0)

// PRIVCFGR Configuration

#define	GPDMA_PRIVCFGR_PRIV15			(0x1u<<15)
#define	GPDMA_PRIVCFGR_PRIV14			(0x1u<<14)
#define	GPDMA_PRIVCFGR_PRIV13			(0x1u<<13)
#define	GPDMA_PRIVCFGR_PRIV12			(0x1u<<12)
#define	GPDMA_PRIVCFGR_PRIV11			(0x1u<<11)
#define	GPDMA_PRIVCFGR_PRIV10			(0x1u<<10)
#define	GPDMA_PRIVCFGR_PRIV9			(0x1u<<9)
#define	GPDMA_PRIVCFGR_PRIV8			(0x1u<<8)
#define	GPDMA_PRIVCFGR_PRIV7			(0x1u<<7)
#define	GPDMA_PRIVCFGR_PRIV6			(0x1u<<6)
#define	GPDMA_PRIVCFGR_PRIV5			(0x1u<<5)
#define	GPDMA_PRIVCFGR_PRIV4			(0x1u<<4)
#define	GPDMA_PRIVCFGR_PRIV3			(0x1u<<3)
#define	GPDMA_PRIVCFGR_PRIV2			(0x1u<<2)
#define	GPDMA_PRIVCFGR_PRIV1			(0x1u<<1)
#define	GPDMA_PRIVCFGR_PRIV0			(0x1u<<0)

#define	GPDMA_PRIVCFGR_PRIV15_B_0X0		(0x0u<<15)
#define	GPDMA_PRIVCFGR_PRIV15_B_0X1		(0x1u<<15)
#define	GPDMA_PRIVCFGR_PRIV14_B_0X0		(0x0u<<14)
#define	GPDMA_PRIVCFGR_PRIV14_B_0X1		(0x1u<<14)
#define	GPDMA_PRIVCFGR_PRIV13_B_0X0		(0x0u<<13)
#define	GPDMA_PRIVCFGR_PRIV13_B_0X1		(0x1u<<13)
#define	GPDMA_PRIVCFGR_PRIV12_B_0X0		(0x0u<<12)
#define	GPDMA_PRIVCFGR_PRIV12_B_0X1		(0x1u<<12)
#define	GPDMA_PRIVCFGR_PRIV11_B_0X0		(0x0u<<11)
#define	GPDMA_PRIVCFGR_PRIV11_B_0X1		(0x1u<<11)
#define	GPDMA_PRIVCFGR_PRIV10_B_0X0		(0x0u<<10)
#define	GPDMA_PRIVCFGR_PRIV10_B_0X1		(0x1u<<10)
#define	GPDMA_PRIVCFGR_PRIV9_B_0X0		(0x0u<<9)
#define	GPDMA_PRIVCFGR_PRIV9_B_0X1		(0x1u<<9)
#define	GPDMA_PRIVCFGR_PRIV8_B_0X0		(0x0u<<8)
#define	GPDMA_PRIVCFGR_PRIV8_B_0X1		(0x1u<<8)
#define	GPDMA_PRIVCFGR_PRIV7_B_0X0		(0x0u<<7)
#define	GPDMA_PRIVCFGR_PRIV7_B_0X1		(0x1u<<7)
#define	GPDMA_PRIVCFGR_PRIV6_B_0X0		(0x0u<<6)
#define	GPDMA_PRIVCFGR_PRIV6_B_0X1		(0x1u<<6)
#define	GPDMA_PRIVCFGR_PRIV5_B_0X0		(0x0u<<5)
#define	GPDMA_PRIVCFGR_PRIV5_B_0X1		(0x1u<<5)
#define	GPDMA_PRIVCFGR_PRIV4_B_0X0		(0x0u<<4)
#define	GPDMA_PRIVCFGR_PRIV4_B_0X1		(0x1u<<4)
#define	GPDMA_PRIVCFGR_PRIV3_B_0X0		(0x0u<<3)
#define	GPDMA_PRIVCFGR_PRIV3_B_0X1		(0x1u<<3)
#define	GPDMA_PRIVCFGR_PRIV2_B_0X0		(0x0u<<2)
#define	GPDMA_PRIVCFGR_PRIV2_B_0X1		(0x1u<<2)
#define	GPDMA_PRIVCFGR_PRIV1_B_0X0		(0x0u<<1)
#define	GPDMA_PRIVCFGR_PRIV1_B_0X1		(0x1u<<1)
#define	GPDMA_PRIVCFGR_PRIV0_B_0X0		(0x0u<<0)
#define	GPDMA_PRIVCFGR_PRIV0_B_0X1		(0x1u<<0)

// RCFGLOCKR Configuration

#define	GPDMA_RCFGLOCKR_LOCK15			(0x1u<<15)
#define	GPDMA_RCFGLOCKR_LOCK14			(0x1u<<14)
#define	GPDMA_RCFGLOCKR_LOCK13			(0x1u<<13)
#define	GPDMA_RCFGLOCKR_LOCK12			(0x1u<<12)
#define	GPDMA_RCFGLOCKR_LOCK11			(0x1u<<11)
#define	GPDMA_RCFGLOCKR_LOCK10			(0x1u<<10)
#define	GPDMA_RCFGLOCKR_LOCK9			(0x1u<<9)
#define	GPDMA_RCFGLOCKR_LOCK8			(0x1u<<8)
#define	GPDMA_RCFGLOCKR_LOCK7			(0x1u<<7)
#define	GPDMA_RCFGLOCKR_LOCK6			(0x1u<<6)
#define	GPDMA_RCFGLOCKR_LOCK5			(0x1u<<5)
#define	GPDMA_RCFGLOCKR_LOCK4			(0x1u<<4)
#define	GPDMA_RCFGLOCKR_LOCK3			(0x1u<<3)
#define	GPDMA_RCFGLOCKR_LOCK2			(0x1u<<2)
#define	GPDMA_RCFGLOCKR_LOCK1			(0x1u<<1)
#define	GPDMA_RCFGLOCKR_LOCK0			(0x1u<<0)

#define	GPDMA_RCFGLOCKR_LOCK15_B_0X0	(0x0u<<15)
#define	GPDMA_RCFGLOCKR_LOCK15_B_0X1	(0x1u<<15)
#define	GPDMA_RCFGLOCKR_LOCK14_B_0X0	(0x0u<<14)
#define	GPDMA_RCFGLOCKR_LOCK14_B_0X1	(0x1u<<14)
#define	GPDMA_RCFGLOCKR_LOCK13_B_0X0	(0x0u<<13)
#define	GPDMA_RCFGLOCKR_LOCK13_B_0X1	(0x1u<<13)
#define	GPDMA_RCFGLOCKR_LOCK12_B_0X0	(0x0u<<12)
#define	GPDMA_RCFGLOCKR_LOCK12_B_0X1	(0x1u<<12)
#define	GPDMA_RCFGLOCKR_LOCK11_B_0X0	(0x0u<<11)
#define	GPDMA_RCFGLOCKR_LOCK11_B_0X1	(0x1u<<11)
#define	GPDMA_RCFGLOCKR_LOCK10_B_0X0	(0x0u<<10)
#define	GPDMA_RCFGLOCKR_LOCK10_B_0X1	(0x1u<<10)
#define	GPDMA_RCFGLOCKR_LOCK9_B_0X0		(0x0u<<9)
#define	GPDMA_RCFGLOCKR_LOCK9_B_0X1		(0x1u<<9)
#define	GPDMA_RCFGLOCKR_LOCK8_B_0X0		(0x0u<<8)
#define	GPDMA_RCFGLOCKR_LOCK8_B_0X1		(0x1u<<8)
#define	GPDMA_RCFGLOCKR_LOCK7_B_0X0		(0x0u<<7)
#define	GPDMA_RCFGLOCKR_LOCK7_B_0X1		(0x1u<<7)
#define	GPDMA_RCFGLOCKR_LOCK6_B_0X0		(0x0u<<6)
#define	GPDMA_RCFGLOCKR_LOCK6_B_0X1		(0x1u<<6)
#define	GPDMA_RCFGLOCKR_LOCK5_B_0X0		(0x0u<<5)
#define	GPDMA_RCFGLOCKR_LOCK5_B_0X1		(0x1u<<5)
#define	GPDMA_RCFGLOCKR_LOCK4_B_0X0		(0x0u<<4)
#define	GPDMA_RCFGLOCKR_LOCK4_B_0X1		(0x1u<<4)
#define	GPDMA_RCFGLOCKR_LOCK3_B_0X0		(0x0u<<3)
#define	GPDMA_RCFGLOCKR_LOCK3_B_0X1		(0x1u<<3)
#define	GPDMA_RCFGLOCKR_LOCK2_B_0X0		(0x0u<<2)
#define	GPDMA_RCFGLOCKR_LOCK2_B_0X1		(0x1u<<2)
#define	GPDMA_RCFGLOCKR_LOCK1_B_0X0		(0x0u<<1)
#define	GPDMA_RCFGLOCKR_LOCK1_B_0X1		(0x1u<<1)
#define	GPDMA_RCFGLOCKR_LOCK0_B_0X0		(0x0u<<0)
#define	GPDMA_RCFGLOCKR_LOCK0_B_0X1		(0x1u<<0)

// MISR Configuration

#define	GPDMA_MISR_MIS15				(0x1u<<15)
#define	GPDMA_MISR_MIS14				(0x1u<<14)
#define	GPDMA_MISR_MIS13				(0x1u<<13)
#define	GPDMA_MISR_MIS12				(0x1u<<12)
#define	GPDMA_MISR_MIS11				(0x1u<<11)
#define	GPDMA_MISR_MIS10				(0x1u<<10)
#define	GPDMA_MISR_MIS9					(0x1u<<9)
#define	GPDMA_MISR_MIS8					(0x1u<<8)
#define	GPDMA_MISR_MIS7					(0x1u<<7)
#define	GPDMA_MISR_MIS6					(0x1u<<6)
#define	GPDMA_MISR_MIS5					(0x1u<<5)
#define	GPDMA_MISR_MIS4					(0x1u<<4)
#define	GPDMA_MISR_MIS3					(0x1u<<3)
#define	GPDMA_MISR_MIS2					(0x1u<<2)
#define	GPDMA_MISR_MIS1					(0x1u<<1)
#define	GPDMA_MISR_MIS0					(0x1u<<0)

#define	GPDMA_MISR_MIS15_B_0X0			(0x0u<<15)
#define	GPDMA_MISR_MIS15_B_0X1			(0x1u<<15)
#define	GPDMA_MISR_MIS14_B_0X0			(0x0u<<14)
#define	GPDMA_MISR_MIS14_B_0X1			(0x1u<<14)
#define	GPDMA_MISR_MIS13_B_0X0			(0x0u<<13)
#define	GPDMA_MISR_MIS13_B_0X1			(0x1u<<13)
#define	GPDMA_MISR_MIS12_B_0X0			(0x0u<<12)
#define	GPDMA_MISR_MIS12_B_0X1			(0x1u<<12)
#define	GPDMA_MISR_MIS11_B_0X0			(0x0u<<11)
#define	GPDMA_MISR_MIS11_B_0X1			(0x1u<<11)
#define	GPDMA_MISR_MIS10_B_0X0			(0x0u<<10)
#define	GPDMA_MISR_MIS10_B_0X1			(0x1u<<10)
#define	GPDMA_MISR_MIS9_B_0X0			(0x0u<<9)
#define	GPDMA_MISR_MIS9_B_0X1			(0x1u<<9)
#define	GPDMA_MISR_MIS8_B_0X0			(0x0u<<8)
#define	GPDMA_MISR_MIS8_B_0X1			(0x1u<<8)
#define	GPDMA_MISR_MIS7_B_0X0			(0x0u<<7)
#define	GPDMA_MISR_MIS7_B_0X1			(0x1u<<7)
#define	GPDMA_MISR_MIS6_B_0X0			(0x0u<<6)
#define	GPDMA_MISR_MIS6_B_0X1			(0x1u<<6)
#define	GPDMA_MISR_MIS5_B_0X0			(0x0u<<5)
#define	GPDMA_MISR_MIS5_B_0X1			(0x1u<<5)
#define	GPDMA_MISR_MIS4_B_0X0			(0x0u<<4)
#define	GPDMA_MISR_MIS4_B_0X1			(0x1u<<4)
#define	GPDMA_MISR_MIS3_B_0X0			(0x0u<<3)
#define	GPDMA_MISR_MIS3_B_0X1			(0x1u<<3)
#define	GPDMA_MISR_MIS2_B_0X0			(0x0u<<2)
#define	GPDMA_MISR_MIS2_B_0X1			(0x1u<<2)
#define	GPDMA_MISR_MIS1_B_0X0			(0x0u<<1)
#define	GPDMA_MISR_MIS1_B_0X1			(0x1u<<1)
#define	GPDMA_MISR_MIS0_B_0X0			(0x0u<<0)
#define	GPDMA_MISR_MIS0_B_0X1			(0x1u<<0)

// SMISR Configuration

#define	GPDMA_SMISR_MIS15				(0x1u<<15)
#define	GPDMA_SMISR_MIS14				(0x1u<<14)
#define	GPDMA_SMISR_MIS13				(0x1u<<13)
#define	GPDMA_SMISR_MIS12				(0x1u<<12)
#define	GPDMA_SMISR_MIS11				(0x1u<<11)
#define	GPDMA_SMISR_MIS10				(0x1u<<10)
#define	GPDMA_SMISR_MIS9				(0x1u<<9)
#define	GPDMA_SMISR_MIS8				(0x1u<<8)
#define	GPDMA_SMISR_MIS7				(0x1u<<7)
#define	GPDMA_SMISR_MIS6				(0x1u<<6)
#define	GPDMA_SMISR_MIS5				(0x1u<<5)
#define	GPDMA_SMISR_MIS4				(0x1u<<4)
#define	GPDMA_SMISR_MIS3				(0x1u<<3)
#define	GPDMA_SMISR_MIS2				(0x1u<<2)
#define	GPDMA_SMISR_MIS1				(0x1u<<1)
#define	GPDMA_SMISR_MIS0				(0x1u<<0)

#define	GPDMA_SMISR_MIS15_B_0X0			(0x0u<<15)
#define	GPDMA_SMISR_MIS15_B_0X1			(0x1u<<15)
#define	GPDMA_SMISR_MIS14_B_0X0			(0x0u<<14)
#define	GPDMA_SMISR_MIS14_B_0X1			(0x1u<<14)
#define	GPDMA_SMISR_MIS13_B_0X0			(0x0u<<13)
#define	GPDMA_SMISR_MIS13_B_0X1			(0x1u<<13)
#define	GPDMA_SMISR_MIS12_B_0X0			(0x0u<<12)
#define	GPDMA_SMISR_MIS12_B_0X1			(0x1u<<12)
#define	GPDMA_SMISR_MIS11_B_0X0			(0x0u<<11)
#define	GPDMA_SMISR_MIS11_B_0X1			(0x1u<<11)
#define	GPDMA_SMISR_MIS10_B_0X0			(0x0u<<10)
#define	GPDMA_SMISR_MIS10_B_0X1			(0x1u<<10)
#define	GPDMA_SMISR_MIS9_B_0X0			(0x0u<<9)
#define	GPDMA_SMISR_MIS9_B_0X1			(0x1u<<9)
#define	GPDMA_SMISR_MIS8_B_0X0			(0x0u<<8)
#define	GPDMA_SMISR_MIS8_B_0X1			(0x1u<<8)
#define	GPDMA_SMISR_MIS7_B_0X0			(0x0u<<7)
#define	GPDMA_SMISR_MIS7_B_0X1			(0x1u<<7)
#define	GPDMA_SMISR_MIS6_B_0X0			(0x0u<<6)
#define	GPDMA_SMISR_MIS6_B_0X1			(0x1u<<6)
#define	GPDMA_SMISR_MIS5_B_0X0			(0x0u<<5)
#define	GPDMA_SMISR_MIS5_B_0X1			(0x1u<<5)
#define	GPDMA_SMISR_MIS4_B_0X0			(0x0u<<4)
#define	GPDMA_SMISR_MIS4_B_0X1			(0x1u<<4)
#define	GPDMA_SMISR_MIS3_B_0X0			(0x0u<<3)
#define	GPDMA_SMISR_MIS3_B_0X1			(0x1u<<3)
#define	GPDMA_SMISR_MIS2_B_0X0			(0x0u<<2)
#define	GPDMA_SMISR_MIS2_B_0X1			(0x1u<<2)
#define	GPDMA_SMISR_MIS1_B_0X0			(0x0u<<1)
#define	GPDMA_SMISR_MIS1_B_0X1			(0x1u<<1)
#define	GPDMA_SMISR_MIS0_B_0X0			(0x0u<<0)
#define	GPDMA_SMISR_MIS0_B_0X1			(0x1u<<0)

// C0LBAR Configuration

#define	GPDMA_C0LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C0LBAR_LBA_0				(0x1u<<16)

// C0FCR Configuration

#define	GPDMA_C0FCR_TOF					(0x1u<<14)
#define	GPDMA_C0FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C0FCR_USEF				(0x1u<<12)
#define	GPDMA_C0FCR_ULEF				(0x1u<<11)
#define	GPDMA_C0FCR_DTEF				(0x1u<<10)
#define	GPDMA_C0FCR_HTF					(0x1u<<9)
#define	GPDMA_C0FCR_TCF					(0x1u<<8)

#define	GPDMA_C0FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C0FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C0FCR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C0FCR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C0FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C0FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C0FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C0FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C0FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C0FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C0FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C0FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C0FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C0FCR_TCF_B_0X1			(0x1u<<8)

// C0SR Configuration

#define	GPDMA_C0SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C0SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C0SR_TOF					(0x1u<<14)
#define	GPDMA_C0SR_SUSPF				(0x1u<<13)
#define	GPDMA_C0SR_USEF					(0x1u<<12)
#define	GPDMA_C0SR_ULEF					(0x1u<<11)
#define	GPDMA_C0SR_DTEF					(0x1u<<10)
#define	GPDMA_C0SR_HTF					(0x1u<<9)
#define	GPDMA_C0SR_TCF					(0x1u<<8)
#define	GPDMA_C0SR_IDLEF				(0x1u<<0)

#define	GPDMA_C0SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C0SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C0SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C0SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C0SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C0SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C0SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C0SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C0SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C0SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C0SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C0SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C0SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C0SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C0SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C0SR_IDLEF_B_0X1			(0x1u<<0)

// C0CR Configuration

#define	GPDMA_C0CR_PRIO					(0x3u<<22)
#define	GPDMA_C0CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C0CR_LAP					(0x1u<<17)
#define	GPDMA_C0CR_LSM					(0x1u<<16)
#define	GPDMA_C0CR_TOIE					(0x1u<<14)
#define	GPDMA_C0CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C0CR_USEIE				(0x1u<<12)
#define	GPDMA_C0CR_ULEIE				(0x1u<<11)
#define	GPDMA_C0CR_DTEIE				(0x1u<<10)
#define	GPDMA_C0CR_HTIE					(0x1u<<9)
#define	GPDMA_C0CR_TCIE					(0x1u<<8)
#define	GPDMA_C0CR_SUSP					(0x1u<<2)
#define	GPDMA_C0CR_RESET				(0x1u<<1)
#define	GPDMA_C0CR_EN					(0x1u<<0)

#define	GPDMA_C0CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C0CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C0CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C0CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C0CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C0CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C0CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C0CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C0CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C0CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C0CR_SUSPIE_B_0X0			(0x0u<<13)
#define	GPDMA_C0CR_SUSPIE_B_0X1			(0x1u<<13)
#define	GPDMA_C0CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C0CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C0CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C0CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C0CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C0CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C0CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C0CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C0CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C0CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C0CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C0CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C0CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C0CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C0CR_EN_B_0X0				(0x0u<<0)
#define	GPDMA_C0CR_EN_B_0X1				(0x1u<<0)

// C0TR1 Configuration

#define	GPDMA_C0TR1_DSEC				(0x1u<<31)
#define	GPDMA_C0TR1_DAP					(0x1u<<30)
#define	GPDMA_C0TR1_DHX					(0x1u<<27)
#define	GPDMA_C0TR1_DBX					(0x1u<<26)
#define	GPDMA_C0TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C0TR1_DBL_1_0				(0x1u<<20)
#define	GPDMA_C0TR1_DINC				(0x1u<<19)
#define	GPDMA_C0TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C0TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C0TR1_SSEC				(0x1u<<15)
#define	GPDMA_C0TR1_SAP					(0x1u<<14)
#define	GPDMA_C0TR1_SBX					(0x1u<<13)
#define	GPDMA_C0TR1_PAM					(0x3u<<11)
#define	GPDMA_C0TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C0TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C0TR1_SBL_1_0				(0x1u<<4)
#define	GPDMA_C0TR1_SINC				(0x1u<<3)
#define	GPDMA_C0TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C0TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C0TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C0TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C0TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C0TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C0TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C0TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C0TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C0TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C0TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C0TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C0TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C0TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C0TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C0TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C0TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C0TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C0TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C0TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C0TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C0TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C0TR1_PAM_B_0X0_PAM_1		(0x0u<<11)
#define	GPDMA_C0TR1_PAM_B_0X1_PAM_1		(0x1u<<11)
#define	GPDMA_C0TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C0TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C0TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C0TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C0TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C0TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C0TR2 Configuration

#define	GPDMA_C0TR2_TCEM				(0x3u<<30)
#define	GPDMA_C0TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C0TR2_TRIGPOL				(0x3u<<24)
#define	GPDMA_C0TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C0TR2_TRIGSEL				(0x7Fu<<16)
#define	GPDMA_C0TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C0TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C0TR2_TRIGM_0				(0x1u<<14)
#define	GPDMA_C0TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C0TR2_BREQ				(0x1u<<11)
#define	GPDMA_C0TR2_DREQ				(0x1u<<10)
#define	GPDMA_C0TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C0TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C0TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C0TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C0TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C0TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C0TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C0TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C0TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C0TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C0TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C0TR2_TRIGM_B_0X0			(0x0u<<14)
#define	GPDMA_C0TR2_TRIGM_B_0X1			(0x1u<<14)
#define	GPDMA_C0TR2_TRIGM_B_0X2			(0x2u<<14)
#define	GPDMA_C0TR2_TRIGM_B_0X3			(0x3u<<14)
#define	GPDMA_C0TR2_PFREQ_B_0X0			(0x0u<<12)
#define	GPDMA_C0TR2_PFREQ_B_0X1			(0x1u<<12)
#define	GPDMA_C0TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C0TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C0TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C0TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C0TR2_SWREQ_B_0X0			(0x0u<<9)
#define	GPDMA_C0TR2_SWREQ_B_0X1			(0x1u<<9)

// C0BR1 Configuration

#define	GPDMA_C0BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C0BR1_BNDT_0				(0x1u<<0)

// C0SAR Configuration

#define	GPDMA_C0SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C0SAR_SA_0				(0x1u<<0)

// C0DAR Configuration

#define	GPDMA_C0DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C0DAR_DA_0				(0x1u<<0)

// C0LLR Configuration

#define	GPDMA_C0LLR_UT1					(0x1u<<31)
#define	GPDMA_C0LLR_UT2					(0x1u<<30)
#define	GPDMA_C0LLR_UB1					(0x1u<<29)
#define	GPDMA_C0LLR_USA					(0x1u<<28)
#define	GPDMA_C0LLR_UDA					(0x1u<<27)
#define	GPDMA_C0LLR_ULL					(0x1u<<16)
#define	GPDMA_C0LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C0LLR_LA_0				(0x1u<<2)

#define	GPDMA_C0LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C0LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C0LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C0LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C0LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C0LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C0LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C0LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C0LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C0LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C0LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C0LLR_ULL_B_0X1			(0x1u<<16)

// C1LBAR Configuration

#define	GPDMA_C1LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C1LBAR_LBA_0				(0x1u<<16)

// C1FCR Configuration

#define	GPDMA_C1FCR_TOF					(0x1u<<14)
#define	GPDMA_C1FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C1FCR_USEF				(0x1u<<12)
#define	GPDMA_C1FCR_ULEF				(0x1u<<11)
#define	GPDMA_C1FCR_DTEF				(0x1u<<10)
#define	GPDMA_C1FCR_HTF					(0x1u<<9)
#define	GPDMA_C1FCR_TCF					(0x1u<<8)

#define	GPDMA_C1FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C1FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C1FCR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C1FCR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C1FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C1FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C1FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C1FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C1FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C1FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C1FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C1FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C1FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C1FCR_TCF_B_0X1			(0x1u<<8)

// C1SR Configuration

#define	GPDMA_C1SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C1SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C1SR_TOF					(0x1u<<14)
#define	GPDMA_C1SR_SUSPF				(0x1u<<13)
#define	GPDMA_C1SR_USEF					(0x1u<<12)
#define	GPDMA_C1SR_ULEF					(0x1u<<11)
#define	GPDMA_C1SR_DTEF					(0x1u<<10)
#define	GPDMA_C1SR_HTF					(0x1u<<9)
#define	GPDMA_C1SR_TCF					(0x1u<<8)
#define	GPDMA_C1SR_IDLEF				(0x1u<<0)

#define	GPDMA_C1SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C1SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C1SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C1SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C1SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C1SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C1SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C1SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C1SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C1SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C1SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C1SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C1SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C1SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C1SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C1SR_IDLEF_B_0X1			(0x1u<<0)

// C1CR Configuration

#define	GPDMA_C1CR_PRIO					(0x3u<<22)
#define	GPDMA_C1CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C1CR_LAP					(0x1u<<17)
#define	GPDMA_C1CR_LSM					(0x1u<<16)
#define	GPDMA_C1CR_TOIE					(0x1u<<14)
#define	GPDMA_C1CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C1CR_USEIE				(0x1u<<12)
#define	GPDMA_C1CR_ULEIE				(0x1u<<11)
#define	GPDMA_C1CR_DTEIE				(0x1u<<10)
#define	GPDMA_C1CR_HTIE					(0x1u<<9)
#define	GPDMA_C1CR_TCIE					(0x1u<<8)
#define	GPDMA_C1CR_SUSP					(0x1u<<2)
#define	GPDMA_C1CR_RESET				(0x1u<<1)
#define	GPDMA_C1CR_EN					(0x1u<<0)

#define	GPDMA_C1CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C1CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C1CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C1CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C1CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C1CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C1CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C1CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C1CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C1CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C1CR_SUSPIE_B_0X0			(0x0u<<13)
#define	GPDMA_C1CR_SUSPIE_B_0X1			(0x1u<<13)
#define	GPDMA_C1CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C1CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C1CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C1CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C1CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C1CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C1CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C1CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C1CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C1CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C1CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C1CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C1CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C1CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C1CR_EN_B_0X0				(0x0u<<0)
#define	GPDMA_C1CR_EN_B_0X1				(0x1u<<0)

// C1TR1 Configuration

#define	GPDMA_C1TR1_DSEC				(0x1u<<31)
#define	GPDMA_C1TR1_DAP					(0x1u<<30)
#define	GPDMA_C1TR1_DHX					(0x1u<<27)
#define	GPDMA_C1TR1_DBX					(0x1u<<26)
#define	GPDMA_C1TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C1TR1_DBL_1_0				(0x1u<<20)
#define	GPDMA_C1TR1_DINC				(0x1u<<19)
#define	GPDMA_C1TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C1TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C1TR1_SSEC				(0x1u<<15)
#define	GPDMA_C1TR1_SAP					(0x1u<<14)
#define	GPDMA_C1TR1_SBX					(0x1u<<13)
#define	GPDMA_C1TR1_PAM					(0x3u<<11)
#define	GPDMA_C1TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C1TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C1TR1_SBL_1_0				(0x1u<<4)
#define	GPDMA_C1TR1_SINC				(0x1u<<3)
#define	GPDMA_C1TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C1TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C1TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C1TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C1TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C1TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C1TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C1TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C1TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C1TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C1TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C1TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C1TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C1TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C1TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C1TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C1TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C1TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C1TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C1TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C1TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C1TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C1TR1_PAM_B_0X0_PAM_1		(0x0u<<11)
#define	GPDMA_C1TR1_PAM_B_0X1_PAM_1		(0x1u<<11)
#define	GPDMA_C1TR1_PAM_B_0X2_PAM_1		(0x2u<<11)
#define	GPDMA_C1TR1_PAM_B_0X3_PAM_1		(0x3u<<11)
#define	GPDMA_C1TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C1TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C1TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C1TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C1TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C1TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C1TR2 Configuration

#define	GPDMA_C1TR2_TCEM				(0x3u<<30)
#define	GPDMA_C1TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C1TR2_TRIGPOL				(0x3u<<24)
#define	GPDMA_C1TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C1TR2_TRIGSEL				(0x7Fu<<16)
#define	GPDMA_C1TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C1TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C1TR2_TRIGM_0				(0x1u<<14)
#define	GPDMA_C1TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C1TR2_BREQ				(0x1u<<11)
#define	GPDMA_C1TR2_DREQ				(0x1u<<10)
#define	GPDMA_C1TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C1TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C1TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C1TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C1TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C1TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C1TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C1TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C1TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C1TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C1TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C1TR2_TRIGM_B_0X0			(0x0u<<14)
#define	GPDMA_C1TR2_TRIGM_B_0X1			(0x1u<<14)
#define	GPDMA_C1TR2_TRIGM_B_0X2			(0x2u<<14)
#define	GPDMA_C1TR2_TRIGM_B_0X3			(0x3u<<14)
#define	GPDMA_C1TR2_PFREQ_B_0X0			(0x0u<<12)
#define	GPDMA_C1TR2_PFREQ_B_0X1			(0x1u<<12)
#define	GPDMA_C1TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C1TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C1TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C1TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C1TR2_SWREQ_B_0X0			(0x0u<<9)
#define	GPDMA_C1TR2_SWREQ_B_0X1			(0x1u<<9)

// C1BR1 Configuration

#define	GPDMA_C1BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C1BR1_BNDT_0				(0x1u<<0)

// C1SAR Configuration

#define	GPDMA_C1SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C1SAR_SA_0				(0x1u<<0)

// C1DAR Configuration

#define	GPDMA_C1DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C1DAR_DA_0				(0x1u<<0)

// C1LLR Configuration

#define	GPDMA_C1LLR_UT1					(0x1u<<31)
#define	GPDMA_C1LLR_UT2					(0x1u<<30)
#define	GPDMA_C1LLR_UB1					(0x1u<<29)
#define	GPDMA_C1LLR_USA					(0x1u<<28)
#define	GPDMA_C1LLR_UDA					(0x1u<<27)
#define	GPDMA_C1LLR_ULL					(0x1u<<16)
#define	GPDMA_C1LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C1LLR_LA_0				(0x1u<<2)

#define	GPDMA_C1LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C1LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C1LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C1LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C1LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C1LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C1LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C1LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C1LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C1LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C1LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C1LLR_ULL_B_0X1			(0x1u<<16)

// C2LBAR Configuration

#define	GPDMA_C2LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C2LBAR_LBA_0				(0x1u<<16)

// C2FCR Configuration

#define	GPDMA_C2FCR_TOF					(0x1u<<14)
#define	GPDMA_C2FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C2FCR_USEF				(0x1u<<12)
#define	GPDMA_C2FCR_ULEF				(0x1u<<11)
#define	GPDMA_C2FCR_DTEF				(0x1u<<10)
#define	GPDMA_C2FCR_HTF					(0x1u<<9)
#define	GPDMA_C2FCR_TCF					(0x1u<<8)

#define	GPDMA_C2FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C2FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C2FCR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C2FCR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C2FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C2FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C2FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C2FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C2FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C2FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C2FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C2FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C2FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C2FCR_TCF_B_0X1			(0x1u<<8)

// C2SR Configuration

#define	GPDMA_C2SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C2SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C2SR_TOF					(0x1u<<14)
#define	GPDMA_C2SR_SUSPF				(0x1u<<13)
#define	GPDMA_C2SR_USEF					(0x1u<<12)
#define	GPDMA_C2SR_ULEF					(0x1u<<11)
#define	GPDMA_C2SR_DTEF					(0x1u<<10)
#define	GPDMA_C2SR_HTF					(0x1u<<9)
#define	GPDMA_C2SR_TCF					(0x1u<<8)
#define	GPDMA_C2SR_IDLEF				(0x1u<<0)

#define	GPDMA_C2SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C2SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C2SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C2SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C2SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C2SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C2SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C2SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C2SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C2SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C2SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C2SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C2SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C2SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C2SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C2SR_IDLEF_B_0X1			(0x1u<<0)

// C2CR Configuration

#define	GPDMA_C2CR_PRIO					(0x3u<<22)
#define	GPDMA_C2CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C2CR_LAP					(0x1u<<17)
#define	GPDMA_C2CR_LSM					(0x1u<<16)
#define	GPDMA_C2CR_TOIE					(0x1u<<14)
#define	GPDMA_C2CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C2CR_USEIE				(0x1u<<12)
#define	GPDMA_C2CR_ULEIE				(0x1u<<11)
#define	GPDMA_C2CR_DTEIE				(0x1u<<10)
#define	GPDMA_C2CR_HTIE					(0x1u<<9)
#define	GPDMA_C2CR_TCIE					(0x1u<<8)
#define	GPDMA_C2CR_SUSP					(0x1u<<2)
#define	GPDMA_C2CR_RESET				(0x1u<<1)
#define	GPDMA_C2CR_EN					(0x1u<<0)

#define	GPDMA_C2CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C2CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C2CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C2CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C2CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C2CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C2CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C2CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C2CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C2CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C2CR_SUSPIE_B_0X0			(0x0u<<13)
#define	GPDMA_C2CR_SUSPIE_B_0X1			(0x1u<<13)
#define	GPDMA_C2CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C2CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C2CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C2CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C2CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C2CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C2CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C2CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C2CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C2CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C2CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C2CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C2CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C2CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C2CR_EN_B_0X0				(0x0u<<0)
#define	GPDMA_C2CR_EN_B_0X1				(0x1u<<0)

// C2TR1 Configuration

#define	GPDMA_C2TR1_DSEC				(0x1u<<31)
#define	GPDMA_C2TR1_DAP					(0x1u<<30)
#define	GPDMA_C2TR1_DHX					(0x1u<<27)
#define	GPDMA_C2TR1_DBX					(0x1u<<26)
#define	GPDMA_C2TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C2TR1_DBL_1_0				(0x1u<<20)
#define	GPDMA_C2TR1_DINC				(0x1u<<19)
#define	GPDMA_C2TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C2TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C2TR1_SSEC				(0x1u<<15)
#define	GPDMA_C2TR1_SAP					(0x1u<<14)
#define	GPDMA_C2TR1_SBX					(0x1u<<13)
#define	GPDMA_C2TR1_PAM					(0x3u<<11)
#define	GPDMA_C2TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C2TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C2TR1_SBL_1_0				(0x1u<<4)
#define	GPDMA_C2TR1_SINC				(0x1u<<3)
#define	GPDMA_C2TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C2TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C2TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C2TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C2TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C2TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C2TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C2TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C2TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C2TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C2TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C2TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C2TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C2TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C2TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C2TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C2TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C2TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C2TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C2TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C2TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C2TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C2TR1_PAM_B_0X0_PAM_1		(0x0u<<11)
#define	GPDMA_C2TR1_PAM_B_0X1_PAM_1		(0x1u<<11)
#define	GPDMA_C2TR1_PAM_B_0X2_PAM_1		(0x2u<<11)
#define	GPDMA_C2TR1_PAM_B_0X3_PAM_1		(0x3u<<11)
#define	GPDMA_C2TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C2TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C2TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C2TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C2TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C2TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C2TR2 Configuration

#define	GPDMA_C2TR2_TCEM				(0x3u<<30)
#define	GPDMA_C2TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C2TR2_TRIGPOL				(0x3u<<24)
#define	GPDMA_C2TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C2TR2_TRIGSEL				(0x7Fu<<16)
#define	GPDMA_C2TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C2TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C2TR2_TRIGM_0				(0x1u<<14)
#define	GPDMA_C2TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C2TR2_BREQ				(0x1u<<11)
#define	GPDMA_C2TR2_DREQ				(0x1u<<10)
#define	GPDMA_C2TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C2TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C2TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C2TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C2TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C2TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C2TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C2TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C2TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C2TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C2TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C2TR2_TRIGM_B_0X0			(0x0u<<14)
#define	GPDMA_C2TR2_TRIGM_B_0X1			(0x1u<<14)
#define	GPDMA_C2TR2_TRIGM_B_0X2			(0x2u<<14)
#define	GPDMA_C2TR2_TRIGM_B_0X3			(0x3u<<14)
#define	GPDMA_C2TR2_PFREQ_B_0X0			(0x0u<<12)
#define	GPDMA_C2TR2_PFREQ_B_0X1			(0x1u<<12)
#define	GPDMA_C2TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C2TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C2TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C2TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C2TR2_SWREQ_B_0X0			(0x0u<<9)
#define	GPDMA_C2TR2_SWREQ_B_0X1			(0x1u<<9)

// C2BR1 Configuration

#define	GPDMA_C2BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C2BR1_BNDT_0				(0x1u<<0)

// C2SAR Configuration

#define	GPDMA_C2SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C2SAR_SA_0				(0x1u<<0)

// C2DAR Configuration

#define	GPDMA_C2DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C2DAR_DA_0				(0x1u<<0)

// C2LLR Configuration

#define	GPDMA_C2LLR_UT1					(0x1u<<31)
#define	GPDMA_C2LLR_UT2					(0x1u<<30)
#define	GPDMA_C2LLR_UB1					(0x1u<<29)
#define	GPDMA_C2LLR_USA					(0x1u<<28)
#define	GPDMA_C2LLR_UDA					(0x1u<<27)
#define	GPDMA_C2LLR_ULL					(0x1u<<16)
#define	GPDMA_C2LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C2LLR_LA_0				(0x1u<<2)

#define	GPDMA_C2LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C2LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C2LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C2LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C2LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C2LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C2LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C2LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C2LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C2LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C2LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C2LLR_ULL_B_0X1			(0x1u<<16)

// C3LBAR Configuration

#define	GPDMA_C3LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C3LBAR_LBA_0				(0x1u<<16)

// C3FCR Configuration

#define	GPDMA_C3FCR_TOF					(0x1u<<14)
#define	GPDMA_C3FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C3FCR_USEF				(0x1u<<12)
#define	GPDMA_C3FCR_ULEF				(0x1u<<11)
#define	GPDMA_C3FCR_DTEF				(0x1u<<10)
#define	GPDMA_C3FCR_HTF					(0x1u<<9)
#define	GPDMA_C3FCR_TCF					(0x1u<<8)

#define	GPDMA_C3FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C3FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C3FCR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C3FCR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C3FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C3FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C3FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C3FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C3FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C3FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C3FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C3FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C3FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C3FCR_TCF_B_0X1			(0x1u<<8)

// C3SR Configuration

#define	GPDMA_C3SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C3SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C3SR_TOF					(0x1u<<14)
#define	GPDMA_C3SR_SUSPF				(0x1u<<13)
#define	GPDMA_C3SR_USEF					(0x1u<<12)
#define	GPDMA_C3SR_ULEF					(0x1u<<11)
#define	GPDMA_C3SR_DTEF					(0x1u<<10)
#define	GPDMA_C3SR_HTF					(0x1u<<9)
#define	GPDMA_C3SR_TCF					(0x1u<<8)
#define	GPDMA_C3SR_IDLEF				(0x1u<<0)

#define	GPDMA_C3SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C3SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C3SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C3SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C3SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C3SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C3SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C3SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C3SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C3SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C3SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C3SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C3SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C3SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C3SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C3SR_IDLEF_B_0X1			(0x1u<<0)

// C3CR Configuration

#define	GPDMA_C3CR_PRIO					(0x3u<<22)
#define	GPDMA_C3CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C3CR_LAP					(0x1u<<17)
#define	GPDMA_C3CR_LSM					(0x1u<<16)
#define	GPDMA_C3CR_TOIE					(0x1u<<14)
#define	GPDMA_C3CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C3CR_USEIE				(0x1u<<12)
#define	GPDMA_C3CR_ULEIE				(0x1u<<11)
#define	GPDMA_C3CR_DTEIE				(0x1u<<10)
#define	GPDMA_C3CR_HTIE					(0x1u<<9)
#define	GPDMA_C3CR_TCIE					(0x1u<<8)
#define	GPDMA_C3CR_SUSP					(0x1u<<2)
#define	GPDMA_C3CR_RESET				(0x1u<<1)
#define	GPDMA_C3CR_EN					(0x1u<<0)

#define	GPDMA_C3CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C3CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C3CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C3CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C3CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C3CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C3CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C3CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C3CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C3CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C3CR_SUSPIE_B_0X0			(0x0u<<13)
#define	GPDMA_C3CR_SUSPIE_B_0X1			(0x1u<<13)
#define	GPDMA_C3CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C3CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C3CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C3CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C3CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C3CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C3CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C3CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C3CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C3CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C3CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C3CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C3CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C3CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C3CR_EN_B_0X0				(0x0u<<0)
#define	GPDMA_C3CR_EN_B_0X1				(0x1u<<0)

// C3TR1 Configuration

#define	GPDMA_C3TR1_DSEC				(0x1u<<31)
#define	GPDMA_C3TR1_DAP					(0x1u<<30)
#define	GPDMA_C3TR1_DHX					(0x1u<<27)
#define	GPDMA_C3TR1_DBX					(0x1u<<26)
#define	GPDMA_C3TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C3TR1_DBL_1_0				(0x1u<<20)
#define	GPDMA_C3TR1_DINC				(0x1u<<19)
#define	GPDMA_C3TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C3TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C3TR1_SSEC				(0x1u<<15)
#define	GPDMA_C3TR1_SAP					(0x1u<<14)
#define	GPDMA_C3TR1_SBX					(0x1u<<13)
#define	GPDMA_C3TR1_PAM					(0x3u<<11)
#define	GPDMA_C3TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C3TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C3TR1_SBL_1_0				(0x1u<<4)
#define	GPDMA_C3TR1_SINC				(0x1u<<3)
#define	GPDMA_C3TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C3TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C3TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C3TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C3TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C3TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C3TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C3TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C3TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C3TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C3TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C3TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C3TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C3TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C3TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C3TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C3TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C3TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C3TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C3TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C3TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C3TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C3TR1_PAM_B_0X0_PAM_1		(0x0u<<11)
#define	GPDMA_C3TR1_PAM_B_0X1_PAM_1		(0x1u<<11)
#define	GPDMA_C3TR1_PAM_B_0X2_PAM_1		(0x2u<<11)
#define	GPDMA_C3TR1_PAM_B_0X3_PAM_1		(0x3u<<11)
#define	GPDMA_C3TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C3TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C3TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C3TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C3TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C3TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C3TR2 Configuration

#define	GPDMA_C3TR2_TCEM				(0x3u<<30)
#define	GPDMA_C3TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C3TR2_TRIGPOL				(0x3u<<24)
#define	GPDMA_C3TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C3TR2_TRIGSEL				(0x7Fu<<16)
#define	GPDMA_C3TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C3TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C3TR2_TRIGM_0				(0x1u<<14)
#define	GPDMA_C3TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C3TR2_BREQ				(0x1u<<11)
#define	GPDMA_C3TR2_DREQ				(0x1u<<10)
#define	GPDMA_C3TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C3TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C3TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C3TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C3TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C3TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C3TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C3TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C3TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C3TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C3TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C3TR2_TRIGM_B_0X0			(0x0u<<14)
#define	GPDMA_C3TR2_TRIGM_B_0X1			(0x1u<<14)
#define	GPDMA_C3TR2_TRIGM_B_0X2			(0x2u<<14)
#define	GPDMA_C3TR2_TRIGM_B_0X3			(0x3u<<14)
#define	GPDMA_C3TR2_PFREQ_B_0X0			(0x0u<<12)
#define	GPDMA_C3TR2_PFREQ_B_0X1			(0x1u<<12)
#define	GPDMA_C3TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C3TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C3TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C3TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C3TR2_SWREQ_B_0X0			(0x0u<<9)
#define	GPDMA_C3TR2_SWREQ_B_0X1			(0x1u<<9)

// C3BR1 Configuration

#define	GPDMA_C3BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C3BR1_BNDT_0				(0x1u<<0)

// C3SAR Configuration

#define	GPDMA_C3SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C3SAR_SA_0				(0x1u<<0)

// C3DAR Configuration

#define	GPDMA_C3DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C3DAR_DA_0				(0x1u<<0)

// C3LLR Configuration

#define	GPDMA_C3LLR_UT1					(0x1u<<31)
#define	GPDMA_C3LLR_UT2					(0x1u<<30)
#define	GPDMA_C3LLR_UB1					(0x1u<<29)
#define	GPDMA_C3LLR_USA					(0x1u<<28)
#define	GPDMA_C3LLR_UDA					(0x1u<<27)
#define	GPDMA_C3LLR_ULL					(0x1u<<16)
#define	GPDMA_C3LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C3LLR_LA_0				(0x1u<<2)

#define	GPDMA_C3LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C3LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C3LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C3LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C3LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C3LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C3LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C3LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C3LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C3LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C3LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C3LLR_ULL_B_0X1			(0x1u<<16)

// C4LBAR Configuration

#define	GPDMA_C4LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C4LBAR_LBA_0				(0x1u<<16)

// C4FCR Configuration

#define	GPDMA_C4FCR_TOF					(0x1u<<14)
#define	GPDMA_C4FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C4FCR_USEF				(0x1u<<12)
#define	GPDMA_C4FCR_ULEF				(0x1u<<11)
#define	GPDMA_C4FCR_DTEF				(0x1u<<10)
#define	GPDMA_C4FCR_HTF					(0x1u<<9)
#define	GPDMA_C4FCR_TCF					(0x1u<<8)

#define	GPDMA_C4FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C4FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C4FCR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C4FCR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C4FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C4FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C4FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C4FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C4FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C4FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C4FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C4FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C4FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C4FCR_TCF_B_0X1			(0x1u<<8)

// C4SR Configuration

#define	GPDMA_C4SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C4SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C4SR_TOF					(0x1u<<14)
#define	GPDMA_C4SR_SUSPF				(0x1u<<13)
#define	GPDMA_C4SR_USEF					(0x1u<<12)
#define	GPDMA_C4SR_ULEF					(0x1u<<11)
#define	GPDMA_C4SR_DTEF					(0x1u<<10)
#define	GPDMA_C4SR_HTF					(0x1u<<9)
#define	GPDMA_C4SR_TCF					(0x1u<<8)
#define	GPDMA_C4SR_IDLEF				(0x1u<<0)

#define	GPDMA_C4SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C4SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C4SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C4SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C4SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C4SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C4SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C4SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C4SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C4SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C4SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C4SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C4SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C4SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C4SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C4SR_IDLEF_B_0X1			(0x1u<<0)

// C4CR Configuration

#define	GPDMA_C4CR_PRIO					(0x3u<<22)
#define	GPDMA_C4CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C4CR_LAP					(0x1u<<17)
#define	GPDMA_C4CR_LSM					(0x1u<<16)
#define	GPDMA_C4CR_TOIE					(0x1u<<14)
#define	GPDMA_C4CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C4CR_USEIE				(0x1u<<12)
#define	GPDMA_C4CR_ULEIE				(0x1u<<11)
#define	GPDMA_C4CR_DTEIE				(0x1u<<10)
#define	GPDMA_C4CR_HTIE					(0x1u<<9)
#define	GPDMA_C4CR_TCIE					(0x1u<<8)
#define	GPDMA_C4CR_SUSP					(0x1u<<2)
#define	GPDMA_C4CR_RESET				(0x1u<<1)
#define	GPDMA_C4CR_EN					(0x1u<<0)

#define	GPDMA_C4CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C4CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C4CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C4CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C4CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C4CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C4CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C4CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C4CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C4CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C4CR_SUSPIE_B_0X0			(0x0u<<13)
#define	GPDMA_C4CR_SUSPIE_B_0X1			(0x1u<<13)
#define	GPDMA_C4CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C4CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C4CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C4CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C4CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C4CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C4CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C4CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C4CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C4CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C4CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C4CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C4CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C4CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C4CR_EN_B_0X0				(0x0u<<0)
#define	GPDMA_C4CR_EN_B_0X1				(0x1u<<0)

// C4TR1 Configuration

#define	GPDMA_C4TR1_DSEC				(0x1u<<31)
#define	GPDMA_C4TR1_DAP					(0x1u<<30)
#define	GPDMA_C4TR1_DHX					(0x1u<<27)
#define	GPDMA_C4TR1_DBX					(0x1u<<26)
#define	GPDMA_C4TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C4TR1_DBL_1_0				(0x1u<<20)
#define	GPDMA_C4TR1_DINC				(0x1u<<19)
#define	GPDMA_C4TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C4TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C4TR1_SSEC				(0x1u<<15)
#define	GPDMA_C4TR1_SAP					(0x1u<<14)
#define	GPDMA_C4TR1_SBX					(0x1u<<13)
#define	GPDMA_C4TR1_PAM					(0x3u<<11)
#define	GPDMA_C4TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C4TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C4TR1_SBL_1_0				(0x1u<<4)
#define	GPDMA_C4TR1_SINC				(0x1u<<3)
#define	GPDMA_C4TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C4TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C4TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C4TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C4TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C4TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C4TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C4TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C4TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C4TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C4TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C4TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C4TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C4TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C4TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C4TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C4TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C4TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C4TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C4TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C4TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C4TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C4TR1_PAM_B_0X0_PAM_1		(0x0u<<11)
#define	GPDMA_C4TR1_PAM_B_0X1_PAM_1		(0x1u<<11)
#define	GPDMA_C4TR1_PAM_B_0X2_PAM_1		(0x2u<<11)
#define	GPDMA_C4TR1_PAM_B_0X3_PAM_1		(0x3u<<11)
#define	GPDMA_C4TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C4TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C4TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C4TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C4TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C4TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C4TR2 Configuration

#define	GPDMA_C4TR2_TCEM				(0x3u<<30)
#define	GPDMA_C4TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C4TR2_TRIGPOL				(0x3u<<24)
#define	GPDMA_C4TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C4TR2_TRIGSEL				(0x7Fu<<16)
#define	GPDMA_C4TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C4TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C4TR2_TRIGM_0				(0x1u<<14)
#define	GPDMA_C4TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C4TR2_BREQ				(0x1u<<11)
#define	GPDMA_C4TR2_DREQ				(0x1u<<10)
#define	GPDMA_C4TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C4TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C4TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C4TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C4TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C4TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C4TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C4TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C4TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C4TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C4TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C4TR2_TRIGM_B_0X0			(0x0u<<14)
#define	GPDMA_C4TR2_TRIGM_B_0X1			(0x1u<<14)
#define	GPDMA_C4TR2_TRIGM_B_0X2			(0x2u<<14)
#define	GPDMA_C4TR2_TRIGM_B_0X3			(0x3u<<14)
#define	GPDMA_C4TR2_PFREQ_B_0X0			(0x0u<<12)
#define	GPDMA_C4TR2_PFREQ_B_0X1			(0x1u<<12)
#define	GPDMA_C4TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C4TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C4TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C4TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C4TR2_SWREQ_B_0X0			(0x0u<<9)
#define	GPDMA_C4TR2_SWREQ_B_0X1			(0x1u<<9)

// C4BR1 Configuration

#define	GPDMA_C4BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C4BR1_BNDT_0				(0x1u<<0)

// C4SAR Configuration

#define	GPDMA_C4SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C4SAR_SA_0				(0x1u<<0)

// C4DAR Configuration

#define	GPDMA_C4DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C4DAR_DA_0				(0x1u<<0)

// C4LLR Configuration

#define	GPDMA_C4LLR_UT1					(0x1u<<31)
#define	GPDMA_C4LLR_UT2					(0x1u<<30)
#define	GPDMA_C4LLR_UB1					(0x1u<<29)
#define	GPDMA_C4LLR_USA					(0x1u<<28)
#define	GPDMA_C4LLR_UDA					(0x1u<<27)
#define	GPDMA_C4LLR_ULL					(0x1u<<16)
#define	GPDMA_C4LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C4LLR_LA_0				(0x1u<<2)

#define	GPDMA_C4LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C4LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C4LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C4LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C4LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C4LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C4LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C4LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C4LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C4LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C4LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C4LLR_ULL_B_0X1			(0x1u<<16)

// C5LBAR Configuration

#define	GPDMA_C5LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C5LBAR_LBA_0				(0x1u<<16)

// C5FCR Configuration

#define	GPDMA_C5FCR_TOF					(0x1u<<14)
#define	GPDMA_C5FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C5FCR_USEF				(0x1u<<12)
#define	GPDMA_C5FCR_ULEF				(0x1u<<11)
#define	GPDMA_C5FCR_DTEF				(0x1u<<10)
#define	GPDMA_C5FCR_HTF					(0x1u<<9)
#define	GPDMA_C5FCR_TCF					(0x1u<<8)

#define	GPDMA_C5FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C5FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C5FCR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C5FCR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C5FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C5FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C5FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C5FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C5FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C5FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C5FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C5FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C5FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C5FCR_TCF_B_0X1			(0x1u<<8)

// C5SR Configuration

#define	GPDMA_C5SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C5SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C5SR_TOF					(0x1u<<14)
#define	GPDMA_C5SR_SUSPF				(0x1u<<13)
#define	GPDMA_C5SR_USEF					(0x1u<<12)
#define	GPDMA_C5SR_ULEF					(0x1u<<11)
#define	GPDMA_C5SR_DTEF					(0x1u<<10)
#define	GPDMA_C5SR_HTF					(0x1u<<9)
#define	GPDMA_C5SR_TCF					(0x1u<<8)
#define	GPDMA_C5SR_IDLEF				(0x1u<<0)

#define	GPDMA_C5SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C5SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C5SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C5SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C5SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C5SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C5SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C5SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C5SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C5SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C5SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C5SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C5SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C5SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C5SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C5SR_IDLEF_B_0X1			(0x1u<<0)

// C5CR Configuration

#define	GPDMA_C5CR_PRIO					(0x3u<<22)
#define	GPDMA_C5CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C5CR_LAP					(0x1u<<17)
#define	GPDMA_C5CR_LSM					(0x1u<<16)
#define	GPDMA_C5CR_TOIE					(0x1u<<14)
#define	GPDMA_C5CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C5CR_USEIE				(0x1u<<12)
#define	GPDMA_C5CR_ULEIE				(0x1u<<11)
#define	GPDMA_C5CR_DTEIE				(0x1u<<10)
#define	GPDMA_C5CR_HTIE					(0x1u<<9)
#define	GPDMA_C5CR_TCIE					(0x1u<<8)
#define	GPDMA_C5CR_SUSP					(0x1u<<2)
#define	GPDMA_C5CR_RESET				(0x1u<<1)
#define	GPDMA_C5CR_EN					(0x1u<<0)

#define	GPDMA_C5CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C5CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C5CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C5CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C5CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C5CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C5CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C5CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C5CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C5CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C5CR_SUSPIE_B_0X0			(0x0u<<13)
#define	GPDMA_C5CR_SUSPIE_B_0X1			(0x1u<<13)
#define	GPDMA_C5CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C5CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C5CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C5CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C5CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C5CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C5CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C5CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C5CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C5CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C5CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C5CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C5CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C5CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C5CR_EN_B_0X0				(0x0u<<0)
#define	GPDMA_C5CR_EN_B_0X1				(0x1u<<0)

// C5TR1 Configuration

#define	GPDMA_C5TR1_DSEC				(0x1u<<31)
#define	GPDMA_C5TR1_DAP					(0x1u<<30)
#define	GPDMA_C5TR1_DHX					(0x1u<<27)
#define	GPDMA_C5TR1_DBX					(0x1u<<26)
#define	GPDMA_C5TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C5TR1_DBL_1_0				(0x1u<<20)
#define	GPDMA_C5TR1_DINC				(0x1u<<19)
#define	GPDMA_C5TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C5TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C5TR1_SSEC				(0x1u<<15)
#define	GPDMA_C5TR1_SAP					(0x1u<<14)
#define	GPDMA_C5TR1_SBX					(0x1u<<13)
#define	GPDMA_C5TR1_PAM					(0x3u<<11)
#define	GPDMA_C5TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C5TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C5TR1_SBL_1_0				(0x1u<<4)
#define	GPDMA_C5TR1_SINC				(0x1u<<3)
#define	GPDMA_C5TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C5TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C5TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C5TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C5TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C5TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C5TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C5TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C5TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C5TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C5TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C5TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C5TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C5TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C5TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C5TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C5TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C5TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C5TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C5TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C5TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C5TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C5TR1_PAM_B_0X0_PAM_1		(0x0u<<11)
#define	GPDMA_C5TR1_PAM_B_0X1_PAM_1		(0x1u<<11)
#define	GPDMA_C5TR1_PAM_B_0X2_PAM_1		(0x2u<<11)
#define	GPDMA_C5TR1_PAM_B_0X3_PAM_1		(0x3u<<11)
#define	GPDMA_C5TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C5TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C5TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C5TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C5TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C5TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C5TR2 Configuration

#define	GPDMA_C5TR2_TCEM				(0x3u<<30)
#define	GPDMA_C5TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C5TR2_TRIGPOL				(0x3u<<24)
#define	GPDMA_C5TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C5TR2_TRIGSEL				(0x7Fu<<16)
#define	GPDMA_C5TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C5TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C5TR2_TRIGM_0				(0x1u<<14)
#define	GPDMA_C5TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C5TR2_BREQ				(0x1u<<11)
#define	GPDMA_C5TR2_DREQ				(0x1u<<10)
#define	GPDMA_C5TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C5TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C5TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C5TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C5TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C5TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C5TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C5TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C5TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C5TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C5TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C5TR2_TRIGM_B_0X0			(0x0u<<14)
#define	GPDMA_C5TR2_TRIGM_B_0X1			(0x1u<<14)
#define	GPDMA_C5TR2_TRIGM_B_0X2			(0x2u<<14)
#define	GPDMA_C5TR2_TRIGM_B_0X3			(0x3u<<14)
#define	GPDMA_C5TR2_PFREQ_B_0X0			(0x0u<<12)
#define	GPDMA_C5TR2_PFREQ_B_0X1			(0x1u<<12)
#define	GPDMA_C5TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C5TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C5TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C5TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C5TR2_SWREQ_B_0X0			(0x0u<<9)
#define	GPDMA_C5TR2_SWREQ_B_0X1			(0x1u<<9)

// C5BR1 Configuration

#define	GPDMA_C5BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C5BR1_BNDT_0				(0x1u<<0)

// C5SAR Configuration

#define	GPDMA_C5SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C5SAR_SA_0				(0x1u<<0)

// C5DAR Configuration

#define	GPDMA_C5DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C5DAR_DA_0				(0x1u<<0)

// C5LLR Configuration

#define	GPDMA_C5LLR_UT1					(0x1u<<31)
#define	GPDMA_C5LLR_UT2					(0x1u<<30)
#define	GPDMA_C5LLR_UB1					(0x1u<<29)
#define	GPDMA_C5LLR_USA					(0x1u<<28)
#define	GPDMA_C5LLR_UDA					(0x1u<<27)
#define	GPDMA_C5LLR_ULL					(0x1u<<16)
#define	GPDMA_C5LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C5LLR_LA_0				(0x1u<<2)

#define	GPDMA_C5LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C5LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C5LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C5LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C5LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C5LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C5LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C5LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C5LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C5LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C5LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C5LLR_ULL_B_0X1			(0x1u<<16)

// C6LBAR Configuration

#define	GPDMA_C6LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C6LBAR_LBA_0				(0x1u<<16)

// C6FCR Configuration

#define	GPDMA_C6FCR_TOF					(0x1u<<14)
#define	GPDMA_C6FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C6FCR_USEF				(0x1u<<12)
#define	GPDMA_C6FCR_ULEF				(0x1u<<11)
#define	GPDMA_C6FCR_DTEF				(0x1u<<10)
#define	GPDMA_C6FCR_HTF					(0x1u<<9)
#define	GPDMA_C6FCR_TCF					(0x1u<<8)

#define	GPDMA_C6FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C6FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C6FCR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C6FCR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C6FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C6FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C6FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C6FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C6FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C6FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C6FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C6FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C6FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C6FCR_TCF_B_0X1			(0x1u<<8)

// C6SR Configuration

#define	GPDMA_C6SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C6SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C6SR_TOF					(0x1u<<14)
#define	GPDMA_C6SR_SUSPF				(0x1u<<13)
#define	GPDMA_C6SR_USEF					(0x1u<<12)
#define	GPDMA_C6SR_ULEF					(0x1u<<11)
#define	GPDMA_C6SR_DTEF					(0x1u<<10)
#define	GPDMA_C6SR_HTF					(0x1u<<9)
#define	GPDMA_C6SR_TCF					(0x1u<<8)
#define	GPDMA_C6SR_IDLEF				(0x1u<<0)

#define	GPDMA_C6SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C6SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C6SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C6SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C6SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C6SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C6SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C6SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C6SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C6SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C6SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C6SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C6SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C6SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C6SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C6SR_IDLEF_B_0X1			(0x1u<<0)

// C6CR Configuration

#define	GPDMA_C6CR_PRIO					(0x3u<<22)
#define	GPDMA_C6CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C6CR_LAP					(0x1u<<17)
#define	GPDMA_C6CR_LSM					(0x1u<<16)
#define	GPDMA_C6CR_TOIE					(0x1u<<14)
#define	GPDMA_C6CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C6CR_USEIE				(0x1u<<12)
#define	GPDMA_C6CR_ULEIE				(0x1u<<11)
#define	GPDMA_C6CR_DTEIE				(0x1u<<10)
#define	GPDMA_C6CR_HTIE					(0x1u<<9)
#define	GPDMA_C6CR_TCIE					(0x1u<<8)
#define	GPDMA_C6CR_SUSP					(0x1u<<2)
#define	GPDMA_C6CR_RESET				(0x1u<<1)
#define	GPDMA_C6CR_EN					(0x1u<<0)

#define	GPDMA_C6CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C6CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C6CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C6CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C6CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C6CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C6CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C6CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C6CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C6CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C6CR_SUSPIE_B_0X0			(0x0u<<13)
#define	GPDMA_C6CR_SUSPIE_B_0X1			(0x1u<<13)
#define	GPDMA_C6CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C6CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C6CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C6CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C6CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C6CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C6CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C6CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C6CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C6CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C6CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C6CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C6CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C6CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C6CR_EN_B_0X0				(0x0u<<0)
#define	GPDMA_C6CR_EN_B_0X1				(0x1u<<0)

// C6TR1 Configuration

#define	GPDMA_C6TR1_DSEC				(0x1u<<31)
#define	GPDMA_C6TR1_DAP					(0x1u<<30)
#define	GPDMA_C6TR1_DHX					(0x1u<<27)
#define	GPDMA_C6TR1_DBX					(0x1u<<26)
#define	GPDMA_C6TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C6TR1_DBL_1_0				(0x1u<<20)
#define	GPDMA_C6TR1_DINC				(0x1u<<19)
#define	GPDMA_C6TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C6TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C6TR1_SSEC				(0x1u<<15)
#define	GPDMA_C6TR1_SAP					(0x1u<<14)
#define	GPDMA_C6TR1_SBX					(0x1u<<13)
#define	GPDMA_C6TR1_PAM					(0x3u<<11)
#define	GPDMA_C6TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C6TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C6TR1_SBL_1_0				(0x1u<<4)
#define	GPDMA_C6TR1_SINC				(0x1u<<3)
#define	GPDMA_C6TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C6TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C6TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C6TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C6TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C6TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C6TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C6TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C6TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C6TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C6TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C6TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C6TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C6TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C6TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C6TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C6TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C6TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C6TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C6TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C6TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C6TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C6TR1_PAM_B_0X0_PAM_1		(0x0u<<11)
#define	GPDMA_C6TR1_PAM_B_0X1_PAM_1		(0x1u<<11)
#define	GPDMA_C6TR1_PAM_B_0X2_PAM_1		(0x2u<<11)
#define	GPDMA_C6TR1_PAM_B_0X3_PAM_1		(0x3u<<11)
#define	GPDMA_C6TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C6TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C6TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C6TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C6TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C6TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C6TR2 Configuration

#define	GPDMA_C6TR2_TCEM				(0x3u<<30)
#define	GPDMA_C6TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C6TR2_TRIGPOL				(0x3u<<24)
#define	GPDMA_C6TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C6TR2_TRIGSEL				(0x7Fu<<16)
#define	GPDMA_C6TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C6TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C6TR2_TRIGM_0				(0x1u<<14)
#define	GPDMA_C6TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C6TR2_BREQ				(0x1u<<11)
#define	GPDMA_C6TR2_DREQ				(0x1u<<10)
#define	GPDMA_C6TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C6TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C6TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C6TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C6TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C6TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C6TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C6TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C6TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C6TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C6TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C6TR2_TRIGM_B_0X0			(0x0u<<14)
#define	GPDMA_C6TR2_TRIGM_B_0X1			(0x1u<<14)
#define	GPDMA_C6TR2_TRIGM_B_0X2			(0x2u<<14)
#define	GPDMA_C6TR2_TRIGM_B_0X3			(0x3u<<14)
#define	GPDMA_C6TR2_PFREQ_B_0X0			(0x0u<<12)
#define	GPDMA_C6TR2_PFREQ_B_0X1			(0x1u<<12)
#define	GPDMA_C6TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C6TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C6TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C6TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C6TR2_SWREQ_B_0X0			(0x0u<<9)
#define	GPDMA_C6TR2_SWREQ_B_0X1			(0x1u<<9)

// C6BR1 Configuration

#define	GPDMA_C6BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C6BR1_BNDT_0				(0x1u<<0)

// C6SAR Configuration

#define	GPDMA_C6SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C6SAR_SA_0				(0x1u<<0)

// C6DAR Configuration

#define	GPDMA_C6DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C6DAR_DA_0				(0x1u<<0)

// C6LLR Configuration

#define	GPDMA_C6LLR_UT1					(0x1u<<31)
#define	GPDMA_C6LLR_UT2					(0x1u<<30)
#define	GPDMA_C6LLR_UB1					(0x1u<<29)
#define	GPDMA_C6LLR_USA					(0x1u<<28)
#define	GPDMA_C6LLR_UDA					(0x1u<<27)
#define	GPDMA_C6LLR_ULL					(0x1u<<16)
#define	GPDMA_C6LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C6LLR_LA_0				(0x1u<<2)

#define	GPDMA_C6LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C6LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C6LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C6LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C6LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C6LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C6LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C6LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C6LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C6LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C6LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C6LLR_ULL_B_0X1			(0x1u<<16)

// C7LBAR Configuration

#define	GPDMA_C7LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C7LBAR_LBA_0				(0x1u<<16)

// C7FCR Configuration

#define	GPDMA_C7FCR_TOF					(0x1u<<14)
#define	GPDMA_C7FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C7FCR_USEF				(0x1u<<12)
#define	GPDMA_C7FCR_ULEF				(0x1u<<11)
#define	GPDMA_C7FCR_DTEF				(0x1u<<10)
#define	GPDMA_C7FCR_HTF					(0x1u<<9)
#define	GPDMA_C7FCR_TCF					(0x1u<<8)

#define	GPDMA_C7FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C7FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C7FCR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C7FCR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C7FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C7FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C7FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C7FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C7FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C7FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C7FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C7FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C7FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C7FCR_TCF_B_0X1			(0x1u<<8)

// C7SR Configuration

#define	GPDMA_C7SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C7SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C7SR_TOF					(0x1u<<14)
#define	GPDMA_C7SR_SUSPF				(0x1u<<13)
#define	GPDMA_C7SR_USEF					(0x1u<<12)
#define	GPDMA_C7SR_ULEF					(0x1u<<11)
#define	GPDMA_C7SR_DTEF					(0x1u<<10)
#define	GPDMA_C7SR_HTF					(0x1u<<9)
#define	GPDMA_C7SR_TCF					(0x1u<<8)
#define	GPDMA_C7SR_IDLEF				(0x1u<<0)

#define	GPDMA_C7SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C7SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C7SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C7SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C7SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C7SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C7SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C7SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C7SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C7SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C7SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C7SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C7SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C7SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C7SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C7SR_IDLEF_B_0X1			(0x1u<<0)

// C7CR Configuration

#define	GPDMA_C7CR_PRIO					(0x3u<<22)
#define	GPDMA_C7CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C7CR_LAP					(0x1u<<17)
#define	GPDMA_C7CR_LSM					(0x1u<<16)
#define	GPDMA_C7CR_TOIE					(0x1u<<14)
#define	GPDMA_C7CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C7CR_USEIE				(0x1u<<12)
#define	GPDMA_C7CR_ULEIE				(0x1u<<11)
#define	GPDMA_C7CR_DTEIE				(0x1u<<10)
#define	GPDMA_C7CR_HTIE					(0x1u<<9)
#define	GPDMA_C7CR_TCIE					(0x1u<<8)
#define	GPDMA_C7CR_SUSP					(0x1u<<2)
#define	GPDMA_C7CR_RESET				(0x1u<<1)
#define	GPDMA_C7CR_EN					(0x1u<<0)

#define	GPDMA_C7CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C7CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C7CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C7CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C7CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C7CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C7CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C7CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C7CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C7CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C7CR_SUSPIE_B_0X0			(0x0u<<13)
#define	GPDMA_C7CR_SUSPIE_B_0X1			(0x1u<<13)
#define	GPDMA_C7CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C7CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C7CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C7CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C7CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C7CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C7CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C7CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C7CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C7CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C7CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C7CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C7CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C7CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C7CR_EN_B_0X0				(0x0u<<0)
#define	GPDMA_C7CR_EN_B_0X1				(0x1u<<0)

// C7TR1 Configuration

#define	GPDMA_C7TR1_DSEC				(0x1u<<31)
#define	GPDMA_C7TR1_DAP					(0x1u<<30)
#define	GPDMA_C7TR1_DHX					(0x1u<<27)
#define	GPDMA_C7TR1_DBX					(0x1u<<26)
#define	GPDMA_C7TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C7TR1_DBL_1_0				(0x1u<<20)
#define	GPDMA_C7TR1_DINC				(0x1u<<19)
#define	GPDMA_C7TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C7TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C7TR1_SSEC				(0x1u<<15)
#define	GPDMA_C7TR1_SAP					(0x1u<<14)
#define	GPDMA_C7TR1_SBX					(0x1u<<13)
#define	GPDMA_C7TR1_PAM					(0x3u<<11)
#define	GPDMA_C7TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C7TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C7TR1_SBL_1_0				(0x1u<<4)
#define	GPDMA_C7TR1_SINC				(0x1u<<3)
#define	GPDMA_C7TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C7TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C7TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C7TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C7TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C7TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C7TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C7TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C7TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C7TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C7TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C7TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C7TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C7TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C7TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C7TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C7TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C7TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C7TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C7TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C7TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C7TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C7TR1_PAM_B_0X0_PAM_1		(0x0u<<11)
#define	GPDMA_C7TR1_PAM_B_0X1_PAM_1		(0x1u<<11)
#define	GPDMA_C7TR1_PAM_B_0X2_PAM_1		(0x2u<<11)
#define	GPDMA_C7TR1_PAM_B_0X3_PAM_1		(0x3u<<11)
#define	GPDMA_C7TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C7TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C7TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C7TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C7TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C7TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C7TR2 Configuration

#define	GPDMA_C7TR2_TCEM				(0x3u<<30)
#define	GPDMA_C7TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C7TR2_TRIGPOL				(0x3u<<24)
#define	GPDMA_C7TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C7TR2_TRIGSEL				(0x7Fu<<16)
#define	GPDMA_C7TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C7TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C7TR2_TRIGM_0				(0x1u<<14)
#define	GPDMA_C7TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C7TR2_BREQ				(0x1u<<11)
#define	GPDMA_C7TR2_DREQ				(0x1u<<10)
#define	GPDMA_C7TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C7TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C7TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C7TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C7TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C7TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C7TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C7TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C7TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C7TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C7TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C7TR2_TRIGM_B_0X0			(0x0u<<14)
#define	GPDMA_C7TR2_TRIGM_B_0X1			(0x1u<<14)
#define	GPDMA_C7TR2_TRIGM_B_0X2			(0x2u<<14)
#define	GPDMA_C7TR2_TRIGM_B_0X3			(0x3u<<14)
#define	GPDMA_C7TR2_PFREQ_B_0X0			(0x0u<<12)
#define	GPDMA_C7TR2_PFREQ_B_0X1			(0x1u<<12)
#define	GPDMA_C7TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C7TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C7TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C7TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C7TR2_SWREQ_B_0X0			(0x0u<<9)
#define	GPDMA_C7TR2_SWREQ_B_0X1			(0x1u<<9)

// C7BR1 Configuration

#define	GPDMA_C7BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C7BR1_BNDT_0				(0x1u<<0)

// C7SAR Configuration

#define	GPDMA_C7SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C7SAR_SA_0				(0x1u<<0)

// C7DAR Configuration

#define	GPDMA_C7DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C7DAR_DA_0				(0x1u<<0)

// C7LLR Configuration

#define	GPDMA_C7LLR_UT1					(0x1u<<31)
#define	GPDMA_C7LLR_UT2					(0x1u<<30)
#define	GPDMA_C7LLR_UB1					(0x1u<<29)
#define	GPDMA_C7LLR_USA					(0x1u<<28)
#define	GPDMA_C7LLR_UDA					(0x1u<<27)
#define	GPDMA_C7LLR_ULL					(0x1u<<16)
#define	GPDMA_C7LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C7LLR_LA_0				(0x1u<<2)

#define	GPDMA_C7LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C7LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C7LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C7LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C7LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C7LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C7LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C7LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C7LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C7LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C7LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C7LLR_ULL_B_0X1			(0x1u<<16)

// C8LBAR Configuration

#define	GPDMA_C8LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C8LBAR_LBA_0				(0x1u<<16)

// C8FCR Configuration

#define	GPDMA_C8FCR_TOF					(0x1u<<14)
#define	GPDMA_C8FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C8FCR_USEF				(0x1u<<12)
#define	GPDMA_C8FCR_ULEF				(0x1u<<11)
#define	GPDMA_C8FCR_DTEF				(0x1u<<10)
#define	GPDMA_C8FCR_HTF					(0x1u<<9)
#define	GPDMA_C8FCR_TCF					(0x1u<<8)

#define	GPDMA_C8FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C8FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C8FCR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C8FCR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C8FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C8FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C8FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C8FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C8FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C8FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C8FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C8FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C8FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C8FCR_TCF_B_0X1			(0x1u<<8)

// C8SR Configuration

#define	GPDMA_C8SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C8SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C8SR_TOF					(0x1u<<14)
#define	GPDMA_C8SR_SUSPF				(0x1u<<13)
#define	GPDMA_C8SR_USEF					(0x1u<<12)
#define	GPDMA_C8SR_ULEF					(0x1u<<11)
#define	GPDMA_C8SR_DTEF					(0x1u<<10)
#define	GPDMA_C8SR_HTF					(0x1u<<9)
#define	GPDMA_C8SR_TCF					(0x1u<<8)
#define	GPDMA_C8SR_IDLEF				(0x1u<<0)

#define	GPDMA_C8SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C8SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C8SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C8SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C8SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C8SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C8SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C8SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C8SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C8SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C8SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C8SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C8SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C8SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C8SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C8SR_IDLEF_B_0X1			(0x1u<<0)

// C8CR Configuration

#define	GPDMA_C8CR_PRIO					(0x3u<<22)
#define	GPDMA_C8CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C8CR_LAP					(0x1u<<17)
#define	GPDMA_C8CR_LSM					(0x1u<<16)
#define	GPDMA_C8CR_TOIE					(0x1u<<14)
#define	GPDMA_C8CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C8CR_USEIE				(0x1u<<12)
#define	GPDMA_C8CR_ULEIE				(0x1u<<11)
#define	GPDMA_C8CR_DTEIE				(0x1u<<10)
#define	GPDMA_C8CR_HTIE					(0x1u<<9)
#define	GPDMA_C8CR_TCIE					(0x1u<<8)
#define	GPDMA_C8CR_SUSP					(0x1u<<2)
#define	GPDMA_C8CR_RESET				(0x1u<<1)
#define	GPDMA_C8CR_EN					(0x1u<<0)

#define	GPDMA_C8CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C8CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C8CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C8CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C8CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C8CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C8CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C8CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C8CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C8CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C8CR_SUSPIE_B_0X0			(0x0u<<13)
#define	GPDMA_C8CR_SUSPIE_B_0X1			(0x1u<<13)
#define	GPDMA_C8CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C8CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C8CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C8CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C8CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C8CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C8CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C8CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C8CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C8CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C8CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C8CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C8CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C8CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C8CR_EN_B_0X0				(0x0u<<0)
#define	GPDMA_C8CR_EN_B_0X1				(0x1u<<0)

// C8TR1 Configuration

#define	GPDMA_C8TR1_DSEC				(0x1u<<31)
#define	GPDMA_C8TR1_DAP					(0x1u<<30)
#define	GPDMA_C8TR1_DHX					(0x1u<<27)
#define	GPDMA_C8TR1_DBX					(0x1u<<26)
#define	GPDMA_C8TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C8TR1_DBL_1_0				(0x1u<<20)
#define	GPDMA_C8TR1_DINC				(0x1u<<19)
#define	GPDMA_C8TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C8TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C8TR1_SSEC				(0x1u<<15)
#define	GPDMA_C8TR1_SAP					(0x1u<<14)
#define	GPDMA_C8TR1_SBX					(0x1u<<13)
#define	GPDMA_C8TR1_PAM					(0x3u<<11)
#define	GPDMA_C8TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C8TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C8TR1_SBL_1_0				(0x1u<<4)
#define	GPDMA_C8TR1_SINC				(0x1u<<3)
#define	GPDMA_C8TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C8TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C8TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C8TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C8TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C8TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C8TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C8TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C8TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C8TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C8TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C8TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C8TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C8TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C8TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C8TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C8TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C8TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C8TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C8TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C8TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C8TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C8TR1_PAM_B_0X0_PAM_1		(0x0u<<11)
#define	GPDMA_C8TR1_PAM_B_0X1_PAM_1		(0x1u<<11)
#define	GPDMA_C8TR1_PAM_B_0X2_PAM_1		(0x2u<<11)
#define	GPDMA_C8TR1_PAM_B_0X3_PAM_1		(0x3u<<11)
#define	GPDMA_C8TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C8TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C8TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C8TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C8TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C8TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C8TR2 Configuration

#define	GPDMA_C8TR2_TCEM				(0x3u<<30)
#define	GPDMA_C8TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C8TR2_TRIGPOL				(0x3u<<24)
#define	GPDMA_C8TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C8TR2_TRIGSEL				(0x7Fu<<16)
#define	GPDMA_C8TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C8TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C8TR2_TRIGM_0				(0x1u<<14)
#define	GPDMA_C8TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C8TR2_BREQ				(0x1u<<11)
#define	GPDMA_C8TR2_DREQ				(0x1u<<10)
#define	GPDMA_C8TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C8TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C8TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C8TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C8TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C8TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C8TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C8TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C8TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C8TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C8TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C8TR2_TRIGM_B_0X0			(0x0u<<14)
#define	GPDMA_C8TR2_TRIGM_B_0X1			(0x1u<<14)
#define	GPDMA_C8TR2_TRIGM_B_0X2			(0x2u<<14)
#define	GPDMA_C8TR2_TRIGM_B_0X3			(0x3u<<14)
#define	GPDMA_C8TR2_PFREQ_B_0X0			(0x0u<<12)
#define	GPDMA_C8TR2_PFREQ_B_0X1			(0x1u<<12)
#define	GPDMA_C8TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C8TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C8TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C8TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C8TR2_SWREQ_B_0X0			(0x0u<<9)
#define	GPDMA_C8TR2_SWREQ_B_0X1			(0x1u<<9)

// C8BR1 Configuration

#define	GPDMA_C8BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C8BR1_BNDT_0				(0x1u<<0)

// C8SAR Configuration

#define	GPDMA_C8SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C8SAR_SA_0				(0x1u<<0)

// C8DAR Configuration

#define	GPDMA_C8DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C8DAR_DA_0				(0x1u<<0)

// C8LLR Configuration

#define	GPDMA_C8LLR_UT1					(0x1u<<31)
#define	GPDMA_C8LLR_UT2					(0x1u<<30)
#define	GPDMA_C8LLR_UB1					(0x1u<<29)
#define	GPDMA_C8LLR_USA					(0x1u<<28)
#define	GPDMA_C8LLR_UDA					(0x1u<<27)
#define	GPDMA_C8LLR_ULL					(0x1u<<16)
#define	GPDMA_C8LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C8LLR_LA_0				(0x1u<<2)

#define	GPDMA_C8LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C8LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C8LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C8LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C8LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C8LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C8LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C8LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C8LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C8LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C8LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C8LLR_ULL_B_0X1			(0x1u<<16)

// C9LBAR Configuration

#define	GPDMA_C9LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C9LBAR_LBA_0				(0x1u<<16)

// C9FCR Configuration

#define	GPDMA_C9FCR_TOF					(0x1u<<14)
#define	GPDMA_C9FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C9FCR_USEF				(0x1u<<12)
#define	GPDMA_C9FCR_ULEF				(0x1u<<11)
#define	GPDMA_C9FCR_DTEF				(0x1u<<10)
#define	GPDMA_C9FCR_HTF					(0x1u<<9)
#define	GPDMA_C9FCR_TCF					(0x1u<<8)

#define	GPDMA_C9FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C9FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C9FCR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C9FCR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C9FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C9FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C9FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C9FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C9FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C9FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C9FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C9FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C9FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C9FCR_TCF_B_0X1			(0x1u<<8)

// C9SR Configuration

#define	GPDMA_C9SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C9SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C9SR_TOF					(0x1u<<14)
#define	GPDMA_C9SR_SUSPF				(0x1u<<13)
#define	GPDMA_C9SR_USEF					(0x1u<<12)
#define	GPDMA_C9SR_ULEF					(0x1u<<11)
#define	GPDMA_C9SR_DTEF					(0x1u<<10)
#define	GPDMA_C9SR_HTF					(0x1u<<9)
#define	GPDMA_C9SR_TCF					(0x1u<<8)
#define	GPDMA_C9SR_IDLEF				(0x1u<<0)

#define	GPDMA_C9SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C9SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C9SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C9SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C9SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C9SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C9SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C9SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C9SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C9SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C9SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C9SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C9SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C9SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C9SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C9SR_IDLEF_B_0X1			(0x1u<<0)

// C9CR Configuration

#define	GPDMA_C9CR_PRIO					(0x3u<<22)
#define	GPDMA_C9CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C9CR_LAP					(0x1u<<17)
#define	GPDMA_C9CR_LSM					(0x1u<<16)
#define	GPDMA_C9CR_TOIE					(0x1u<<14)
#define	GPDMA_C9CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C9CR_USEIE				(0x1u<<12)
#define	GPDMA_C9CR_ULEIE				(0x1u<<11)
#define	GPDMA_C9CR_DTEIE				(0x1u<<10)
#define	GPDMA_C9CR_HTIE					(0x1u<<9)
#define	GPDMA_C9CR_TCIE					(0x1u<<8)
#define	GPDMA_C9CR_SUSP					(0x1u<<2)
#define	GPDMA_C9CR_RESET				(0x1u<<1)
#define	GPDMA_C9CR_EN					(0x1u<<0)

#define	GPDMA_C9CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C9CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C9CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C9CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C9CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C9CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C9CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C9CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C9CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C9CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C9CR_SUSPIE_B_0X0			(0x0u<<13)
#define	GPDMA_C9CR_SUSPIE_B_0X1			(0x1u<<13)
#define	GPDMA_C9CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C9CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C9CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C9CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C9CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C9CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C9CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C9CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C9CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C9CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C9CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C9CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C9CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C9CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C9CR_EN_B_0X0				(0x0u<<0)
#define	GPDMA_C9CR_EN_B_0X1				(0x1u<<0)

// C9TR1 Configuration

#define	GPDMA_C9TR1_DSEC				(0x1u<<31)
#define	GPDMA_C9TR1_DAP					(0x1u<<30)
#define	GPDMA_C9TR1_DHX					(0x1u<<27)
#define	GPDMA_C9TR1_DBX					(0x1u<<26)
#define	GPDMA_C9TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C9TR1_DBL_1_0				(0x1u<<20)
#define	GPDMA_C9TR1_DINC				(0x1u<<19)
#define	GPDMA_C9TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C9TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C9TR1_SSEC				(0x1u<<15)
#define	GPDMA_C9TR1_SAP					(0x1u<<14)
#define	GPDMA_C9TR1_SBX					(0x1u<<13)
#define	GPDMA_C9TR1_PAM					(0x3u<<11)
#define	GPDMA_C9TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C9TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C9TR1_SBL_1_0				(0x1u<<4)
#define	GPDMA_C9TR1_SINC				(0x1u<<3)
#define	GPDMA_C9TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C9TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C9TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C9TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C9TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C9TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C9TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C9TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C9TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C9TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C9TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C9TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C9TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C9TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C9TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C9TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C9TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C9TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C9TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C9TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C9TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C9TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C9TR1_PAM_B_0X0_PAM_1		(0x0u<<11)
#define	GPDMA_C9TR1_PAM_B_0X1_PAM_1		(0x1u<<11)
#define	GPDMA_C9TR1_PAM_B_0X2_PAM_1		(0x2u<<11)
#define	GPDMA_C9TR1_PAM_B_0X3_PAM_1		(0x3u<<11)
#define	GPDMA_C9TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C9TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C9TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C9TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C9TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C9TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C9TR2 Configuration

#define	GPDMA_C9TR2_TCEM				(0x3u<<30)
#define	GPDMA_C9TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C9TR2_TRIGPOL				(0x3u<<24)
#define	GPDMA_C9TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C9TR2_TRIGSEL				(0x7Fu<<16)
#define	GPDMA_C9TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C9TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C9TR2_TRIGM_0				(0x1u<<14)
#define	GPDMA_C9TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C9TR2_BREQ				(0x1u<<11)
#define	GPDMA_C9TR2_DREQ				(0x1u<<10)
#define	GPDMA_C9TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C9TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C9TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C9TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C9TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C9TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C9TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C9TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C9TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C9TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C9TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C9TR2_TRIGM_B_0X0			(0x0u<<14)
#define	GPDMA_C9TR2_TRIGM_B_0X1			(0x1u<<14)
#define	GPDMA_C9TR2_TRIGM_B_0X2			(0x2u<<14)
#define	GPDMA_C9TR2_TRIGM_B_0X3			(0x3u<<14)
#define	GPDMA_C9TR2_PFREQ_B_0X0			(0x0u<<12)
#define	GPDMA_C9TR2_PFREQ_B_0X1			(0x1u<<12)
#define	GPDMA_C9TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C9TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C9TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C9TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C9TR2_SWREQ_B_0X0			(0x0u<<9)
#define	GPDMA_C9TR2_SWREQ_B_0X1			(0x1u<<9)

// C9BR1 Configuration

#define	GPDMA_C9BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C9BR1_BNDT_0				(0x1u<<0)

// C9SAR Configuration

#define	GPDMA_C9SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C9SAR_SA_0				(0x1u<<0)

// C9DAR Configuration

#define	GPDMA_C9DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C9DAR_DA_0				(0x1u<<0)

// C9LLR Configuration

#define	GPDMA_C9LLR_UT1					(0x1u<<31)
#define	GPDMA_C9LLR_UT2					(0x1u<<30)
#define	GPDMA_C9LLR_UB1					(0x1u<<29)
#define	GPDMA_C9LLR_USA					(0x1u<<28)
#define	GPDMA_C9LLR_UDA					(0x1u<<27)
#define	GPDMA_C9LLR_ULL					(0x1u<<16)
#define	GPDMA_C9LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C9LLR_LA_0				(0x1u<<2)

#define	GPDMA_C9LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C9LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C9LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C9LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C9LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C9LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C9LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C9LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C9LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C9LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C9LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C9LLR_ULL_B_0X1			(0x1u<<16)

// C10LBAR Configuration

#define	GPDMA_C10LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C10LBAR_LBA_0				(0x1u<<16)

// C10FCR Configuration

#define	GPDMA_C10FCR_TOF				(0x1u<<14)
#define	GPDMA_C10FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C10FCR_USEF				(0x1u<<12)
#define	GPDMA_C10FCR_ULEF				(0x1u<<11)
#define	GPDMA_C10FCR_DTEF				(0x1u<<10)
#define	GPDMA_C10FCR_HTF				(0x1u<<9)
#define	GPDMA_C10FCR_TCF				(0x1u<<8)

#define	GPDMA_C10FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C10FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C10FCR_SUSPF_B_0X0		(0x0u<<13)
#define	GPDMA_C10FCR_SUSPF_B_0X1		(0x1u<<13)
#define	GPDMA_C10FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C10FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C10FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C10FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C10FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C10FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C10FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C10FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C10FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C10FCR_TCF_B_0X1			(0x1u<<8)

// C10SR Configuration

#define	GPDMA_C10SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C10SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C10SR_TOF					(0x1u<<14)
#define	GPDMA_C10SR_SUSPF				(0x1u<<13)
#define	GPDMA_C10SR_USEF				(0x1u<<12)
#define	GPDMA_C10SR_ULEF				(0x1u<<11)
#define	GPDMA_C10SR_DTEF				(0x1u<<10)
#define	GPDMA_C10SR_HTF					(0x1u<<9)
#define	GPDMA_C10SR_TCF					(0x1u<<8)
#define	GPDMA_C10SR_IDLEF				(0x1u<<0)

#define	GPDMA_C10SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C10SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C10SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C10SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C10SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C10SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C10SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C10SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C10SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C10SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C10SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C10SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C10SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C10SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C10SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C10SR_IDLEF_B_0X1			(0x1u<<0)

// C10CR Configuration

#define	GPDMA_C10CR_PRIO				(0x3u<<22)
#define	GPDMA_C10CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C10CR_LAP					(0x1u<<17)
#define	GPDMA_C10CR_LSM					(0x1u<<16)
#define	GPDMA_C10CR_TOIE				(0x1u<<14)
#define	GPDMA_C10CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C10CR_USEIE				(0x1u<<12)
#define	GPDMA_C10CR_ULEIE				(0x1u<<11)
#define	GPDMA_C10CR_DTEIE				(0x1u<<10)
#define	GPDMA_C10CR_HTIE				(0x1u<<9)
#define	GPDMA_C10CR_TCIE				(0x1u<<8)
#define	GPDMA_C10CR_SUSP				(0x1u<<2)
#define	GPDMA_C10CR_RESET				(0x1u<<1)
#define	GPDMA_C10CR_EN					(0x1u<<0)

#define	GPDMA_C10CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C10CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C10CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C10CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C10CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C10CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C10CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C10CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C10CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C10CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C10CR_SUSPIE_B_0X0		(0x0u<<13)
#define	GPDMA_C10CR_SUSPIE_B_0X1		(0x1u<<13)
#define	GPDMA_C10CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C10CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C10CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C10CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C10CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C10CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C10CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C10CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C10CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C10CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C10CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C10CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C10CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C10CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C10CR_EN_B_0X0			(0x0u<<0)
#define	GPDMA_C10CR_EN_B_0X1			(0x1u<<0)

// C10TR1 Configuration

#define	GPDMA_C10TR1_DSEC				(0x1u<<31)
#define	GPDMA_C10TR1_DAP				(0x1u<<30)
#define	GPDMA_C10TR1_DHX				(0x1u<<27)
#define	GPDMA_C10TR1_DBX				(0x1u<<26)
#define	GPDMA_C10TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C10TR1_DBL_1_0			(0x1u<<20)
#define	GPDMA_C10TR1_DINC				(0x1u<<19)
#define	GPDMA_C10TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C10TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C10TR1_SSEC				(0x1u<<15)
#define	GPDMA_C10TR1_SAP				(0x1u<<14)
#define	GPDMA_C10TR1_SBX				(0x1u<<13)
#define	GPDMA_C10TR1_PAM				(0x3u<<11)
#define	GPDMA_C10TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C10TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C10TR1_SBL_1_0			(0x1u<<4)
#define	GPDMA_C10TR1_SINC				(0x1u<<3)
#define	GPDMA_C10TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C10TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C10TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C10TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C10TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C10TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C10TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C10TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C10TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C10TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C10TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C10TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C10TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C10TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C10TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C10TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C10TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C10TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C10TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C10TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C10TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C10TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C10TR1_PAM_B_0X0_PAM_1	(0x0u<<11)
#define	GPDMA_C10TR1_PAM_B_0X1_PAM_1	(0x1u<<11)
#define	GPDMA_C10TR1_PAM_B_0X2_PAM_1	(0x2u<<11)
#define	GPDMA_C10TR1_PAM_B_0X3_PAM_1	(0x3u<<11)
#define	GPDMA_C10TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C10TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C10TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C10TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C10TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C10TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C10TR2 Configuration

#define	GPDMA_C10TR2_TCEM				(0x3u<<30)
#define	GPDMA_C10TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C10TR2_TRIGPOL			(0x3u<<24)
#define	GPDMA_C10TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C10TR2_TRIGSEL			(0x7Fu<<16)
#define	GPDMA_C10TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C10TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C10TR2_TRIGM_0			(0x1u<<14)
#define	GPDMA_C10TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C10TR2_BREQ				(0x1u<<11)
#define	GPDMA_C10TR2_DREQ				(0x1u<<10)
#define	GPDMA_C10TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C10TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C10TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C10TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C10TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C10TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C10TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C10TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C10TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C10TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C10TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C10TR2_TRIGM_B_0X0		(0x0u<<14)
#define	GPDMA_C10TR2_TRIGM_B_0X1		(0x1u<<14)
#define	GPDMA_C10TR2_TRIGM_B_0X2		(0x2u<<14)
#define	GPDMA_C10TR2_TRIGM_B_0X3		(0x3u<<14)
#define	GPDMA_C10TR2_PFREQ_B_0X0		(0x0u<<12)
#define	GPDMA_C10TR2_PFREQ_B_0X1		(0x1u<<12)
#define	GPDMA_C10TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C10TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C10TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C10TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C10TR2_SWREQ_B_0X0		(0x0u<<9)
#define	GPDMA_C10TR2_SWREQ_B_0X1		(0x1u<<9)

// C10BR1 Configuration

#define	GPDMA_C10BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C10BR1_BNDT_0				(0x1u<<0)

// C10SAR Configuration

#define	GPDMA_C10SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C10SAR_SA_0				(0x1u<<0)

// C10DAR Configuration

#define	GPDMA_C10DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C10DAR_DA_0				(0x1u<<0)

// C10LLR Configuration

#define	GPDMA_C10LLR_UT1				(0x1u<<31)
#define	GPDMA_C10LLR_UT2				(0x1u<<30)
#define	GPDMA_C10LLR_UB1				(0x1u<<29)
#define	GPDMA_C10LLR_USA				(0x1u<<28)
#define	GPDMA_C10LLR_UDA				(0x1u<<27)
#define	GPDMA_C10LLR_ULL				(0x1u<<16)
#define	GPDMA_C10LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C10LLR_LA_0				(0x1u<<2)

#define	GPDMA_C10LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C10LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C10LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C10LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C10LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C10LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C10LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C10LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C10LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C10LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C10LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C10LLR_ULL_B_0X1			(0x1u<<16)

// C11LBAR Configuration

#define	GPDMA_C11LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C11LBAR_LBA_0				(0x1u<<16)

// C11FCR Configuration

#define	GPDMA_C11FCR_TOF				(0x1u<<14)
#define	GPDMA_C11FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C11FCR_USEF				(0x1u<<12)
#define	GPDMA_C11FCR_ULEF				(0x1u<<11)
#define	GPDMA_C11FCR_DTEF				(0x1u<<10)
#define	GPDMA_C11FCR_HTF				(0x1u<<9)
#define	GPDMA_C11FCR_TCF				(0x1u<<8)

#define	GPDMA_C11FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C11FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C11FCR_SUSPF_B_0X0		(0x0u<<13)
#define	GPDMA_C11FCR_SUSPF_B_0X1		(0x1u<<13)
#define	GPDMA_C11FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C11FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C11FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C11FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C11FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C11FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C11FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C11FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C11FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C11FCR_TCF_B_0X1			(0x1u<<8)

// C11SR Configuration

#define	GPDMA_C11SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C11SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C11SR_TOF					(0x1u<<14)
#define	GPDMA_C11SR_SUSPF				(0x1u<<13)
#define	GPDMA_C11SR_USEF				(0x1u<<12)
#define	GPDMA_C11SR_ULEF				(0x1u<<11)
#define	GPDMA_C11SR_DTEF				(0x1u<<10)
#define	GPDMA_C11SR_HTF					(0x1u<<9)
#define	GPDMA_C11SR_TCF					(0x1u<<8)
#define	GPDMA_C11SR_IDLEF				(0x1u<<0)

#define	GPDMA_C11SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C11SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C11SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C11SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C11SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C11SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C11SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C11SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C11SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C11SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C11SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C11SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C11SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C11SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C11SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C11SR_IDLEF_B_0X1			(0x1u<<0)

// C11CR Configuration

#define	GPDMA_C11CR_PRIO				(0x3u<<22)
#define	GPDMA_C11CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C11CR_LAP					(0x1u<<17)
#define	GPDMA_C11CR_LSM					(0x1u<<16)
#define	GPDMA_C11CR_TOIE				(0x1u<<14)
#define	GPDMA_C11CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C11CR_USEIE				(0x1u<<12)
#define	GPDMA_C11CR_ULEIE				(0x1u<<11)
#define	GPDMA_C11CR_DTEIE				(0x1u<<10)
#define	GPDMA_C11CR_HTIE				(0x1u<<9)
#define	GPDMA_C11CR_TCIE				(0x1u<<8)
#define	GPDMA_C11CR_SUSP				(0x1u<<2)
#define	GPDMA_C11CR_RESET				(0x1u<<1)
#define	GPDMA_C11CR_EN					(0x1u<<0)

#define	GPDMA_C11CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C11CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C11CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C11CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C11CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C11CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C11CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C11CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C11CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C11CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C11CR_SUSPIE_B_0X0		(0x0u<<13)
#define	GPDMA_C11CR_SUSPIE_B_0X1		(0x1u<<13)
#define	GPDMA_C11CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C11CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C11CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C11CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C11CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C11CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C11CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C11CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C11CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C11CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C11CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C11CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C11CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C11CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C11CR_EN_B_0X0			(0x0u<<0)
#define	GPDMA_C11CR_EN_B_0X1			(0x1u<<0)

// C11TR1 Configuration

#define	GPDMA_C11TR1_DSEC				(0x1u<<31)
#define	GPDMA_C11TR1_DAP				(0x1u<<30)
#define	GPDMA_C11TR1_DHX				(0x1u<<27)
#define	GPDMA_C11TR1_DBX				(0x1u<<26)
#define	GPDMA_C11TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C11TR1_DBL_1_0			(0x1u<<20)
#define	GPDMA_C11TR1_DINC				(0x1u<<19)
#define	GPDMA_C11TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C11TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C11TR1_SSEC				(0x1u<<15)
#define	GPDMA_C11TR1_SAP				(0x1u<<14)
#define	GPDMA_C11TR1_SBX				(0x1u<<13)
#define	GPDMA_C11TR1_PAM				(0x3u<<11)
#define	GPDMA_C11TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C11TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C11TR1_SBL_1_0			(0x1u<<4)
#define	GPDMA_C11TR1_SINC				(0x1u<<3)
#define	GPDMA_C11TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C11TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C11TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C11TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C11TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C11TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C11TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C11TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C11TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C11TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C11TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C11TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C11TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C11TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C11TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C11TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C11TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C11TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C11TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C11TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C11TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C11TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C11TR1_PAM_B_0X0_PAM_1	(0x0u<<11)
#define	GPDMA_C11TR1_PAM_B_0X1_PAM_1	(0x1u<<11)
#define	GPDMA_C11TR1_PAM_B_0X2_PAM_1	(0x2u<<11)
#define	GPDMA_C11TR1_PAM_B_0X3_PAM_1	(0x3u<<11)
#define	GPDMA_C11TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C11TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C11TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C11TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C11TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C11TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C11TR2 Configuration

#define	GPDMA_C11TR2_TCEM				(0x3u<<30)
#define	GPDMA_C11TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C11TR2_TRIGPOL			(0x3u<<24)
#define	GPDMA_C11TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C11TR2_TRIGSEL			(0x7Fu<<16)
#define	GPDMA_C11TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C11TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C11TR2_TRIGM_0			(0x1u<<14)
#define	GPDMA_C11TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C11TR2_BREQ				(0x1u<<11)
#define	GPDMA_C11TR2_DREQ				(0x1u<<10)
#define	GPDMA_C11TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C11TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C11TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C11TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C11TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C11TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C11TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C11TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C11TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C11TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C11TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C11TR2_TRIGM_B_0X0		(0x0u<<14)
#define	GPDMA_C11TR2_TRIGM_B_0X1		(0x1u<<14)
#define	GPDMA_C11TR2_TRIGM_B_0X2		(0x2u<<14)
#define	GPDMA_C11TR2_TRIGM_B_0X3		(0x3u<<14)
#define	GPDMA_C11TR2_PFREQ_B_0X0		(0x0u<<12)
#define	GPDMA_C11TR2_PFREQ_B_0X1		(0x1u<<12)
#define	GPDMA_C11TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C11TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C11TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C11TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C11TR2_SWREQ_B_0X0		(0x0u<<9)
#define	GPDMA_C11TR2_SWREQ_B_0X1		(0x1u<<9)

// C11BR1 Configuration

#define	GPDMA_C11BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C11BR1_BNDT_0				(0x1u<<0)

// C11SAR Configuration

#define	GPDMA_C11SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C11SAR_SA_0				(0x1u<<0)

// C11DAR Configuration

#define	GPDMA_C11DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C11DAR_DA_0				(0x1u<<0)

// C11LLR Configuration

#define	GPDMA_C11LLR_UT1				(0x1u<<31)
#define	GPDMA_C11LLR_UT2				(0x1u<<30)
#define	GPDMA_C11LLR_UB1				(0x1u<<29)
#define	GPDMA_C11LLR_USA				(0x1u<<28)
#define	GPDMA_C11LLR_UDA				(0x1u<<27)
#define	GPDMA_C11LLR_ULL				(0x1u<<16)
#define	GPDMA_C11LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C11LLR_LA_0				(0x1u<<2)

#define	GPDMA_C11LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C11LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C11LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C11LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C11LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C11LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C11LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C11LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C11LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C11LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C11LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C11LLR_ULL_B_0X1			(0x1u<<16)

// C12LBAR Configuration

#define	GPDMA_C12LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C12LBAR_LBA_0				(0x1u<<16)

// C12FCR Configuration

#define	GPDMA_C12FCR_TOF				(0x1u<<14)
#define	GPDMA_C12FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C12FCR_USEF				(0x1u<<12)
#define	GPDMA_C12FCR_ULEF				(0x1u<<11)
#define	GPDMA_C12FCR_DTEF				(0x1u<<10)
#define	GPDMA_C12FCR_HTF				(0x1u<<9)
#define	GPDMA_C12FCR_TCF				(0x1u<<8)

#define	GPDMA_C12FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C12FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C12FCR_SUSPF_B_0X0		(0x0u<<13)
#define	GPDMA_C12FCR_SUSPF_B_0X1		(0x1u<<13)
#define	GPDMA_C12FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C12FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C12FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C12FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C12FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C12FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C12FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C12FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C12FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C12FCR_TCF_B_0X1			(0x1u<<8)

// C12SR Configuration

#define	GPDMA_C12SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C12SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C12SR_TOF					(0x1u<<14)
#define	GPDMA_C12SR_SUSPF				(0x1u<<13)
#define	GPDMA_C12SR_USEF				(0x1u<<12)
#define	GPDMA_C12SR_ULEF				(0x1u<<11)
#define	GPDMA_C12SR_DTEF				(0x1u<<10)
#define	GPDMA_C12SR_HTF					(0x1u<<9)
#define	GPDMA_C12SR_TCF					(0x1u<<8)
#define	GPDMA_C12SR_IDLEF				(0x1u<<0)

#define	GPDMA_C12SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C12SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C12SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C12SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C12SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C12SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C12SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C12SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C12SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C12SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C12SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C12SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C12SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C12SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C12SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C12SR_IDLEF_B_0X1			(0x1u<<0)

// C12CR Configuration

#define	GPDMA_C12CR_PRIO				(0x3u<<22)
#define	GPDMA_C12CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C12CR_LAP					(0x1u<<17)
#define	GPDMA_C12CR_LSM					(0x1u<<16)
#define	GPDMA_C12CR_TOIE				(0x1u<<14)
#define	GPDMA_C12CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C12CR_USEIE				(0x1u<<12)
#define	GPDMA_C12CR_ULEIE				(0x1u<<11)
#define	GPDMA_C12CR_DTEIE				(0x1u<<10)
#define	GPDMA_C12CR_HTIE				(0x1u<<9)
#define	GPDMA_C12CR_TCIE				(0x1u<<8)
#define	GPDMA_C12CR_SUSP				(0x1u<<2)
#define	GPDMA_C12CR_RESET				(0x1u<<1)
#define	GPDMA_C12CR_EN					(0x1u<<0)

#define	GPDMA_C12CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C12CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C12CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C12CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C12CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C12CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C12CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C12CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C12CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C12CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C12CR_SUSPIE_B_0X0		(0x0u<<13)
#define	GPDMA_C12CR_SUSPIE_B_0X1		(0x1u<<13)
#define	GPDMA_C12CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C12CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C12CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C12CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C12CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C12CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C12CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C12CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C12CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C12CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C12CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C12CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C12CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C12CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C12CR_EN_B_0X0			(0x0u<<0)
#define	GPDMA_C12CR_EN_B_0X1			(0x1u<<0)

// C12TR1 Configuration

#define	GPDMA_C12TR1_DSEC				(0x1u<<31)
#define	GPDMA_C12TR1_DAP				(0x1u<<30)
#define	GPDMA_C12TR1_DHX				(0x1u<<27)
#define	GPDMA_C12TR1_DBX				(0x1u<<26)
#define	GPDMA_C12TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C12TR1_DBL_1_0			(0x1u<<20)
#define	GPDMA_C12TR1_DINC				(0x1u<<19)
#define	GPDMA_C12TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C12TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C12TR1_SSEC				(0x1u<<15)
#define	GPDMA_C12TR1_SAP				(0x1u<<14)
#define	GPDMA_C12TR1_SBX				(0x1u<<13)
#define	GPDMA_C12TR1_PAM				(0x3u<<11)
#define	GPDMA_C12TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C12TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C12TR1_SBL_1_0			(0x1u<<4)
#define	GPDMA_C12TR1_SINC				(0x1u<<3)
#define	GPDMA_C12TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C12TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C12TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C12TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C12TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C12TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C12TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C12TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C12TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C12TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C12TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C12TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C12TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C12TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C12TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C12TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C12TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C12TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C12TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C12TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C12TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C12TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C12TR1_PAM_B_0X0_PAM_1	(0x0u<<11)
#define	GPDMA_C12TR1_PAM_B_0X1_PAM_1	(0x1u<<11)
#define	GPDMA_C12TR1_PAM_B_0X2_PAM_1	(0x2u<<11)
#define	GPDMA_C12TR1_PAM_B_0X3_PAM_1	(0x3u<<11)
#define	GPDMA_C12TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C12TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C12TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C12TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C12TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C12TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C12TR2 Configuration

#define	GPDMA_C12TR2_TCEM				(0x3u<<30)
#define	GPDMA_C12TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C12TR2_TRIGPOL			(0x3u<<24)
#define	GPDMA_C12TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C12TR2_TRIGSEL			(0x7Fu<<16)
#define	GPDMA_C12TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C12TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C12TR2_TRIGM_0			(0x1u<<14)
#define	GPDMA_C12TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C12TR2_BREQ				(0x1u<<11)
#define	GPDMA_C12TR2_DREQ				(0x1u<<10)
#define	GPDMA_C12TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C12TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C12TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C12TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C12TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C12TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C12TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C12TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C12TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C12TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C12TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C12TR2_TRIGM_B_0X0		(0x0u<<14)
#define	GPDMA_C12TR2_TRIGM_B_0X1		(0x1u<<14)
#define	GPDMA_C12TR2_TRIGM_B_0X2		(0x2u<<14)
#define	GPDMA_C12TR2_TRIGM_B_0X3		(0x3u<<14)
#define	GPDMA_C12TR2_PFREQ_B_0X0		(0x0u<<12)
#define	GPDMA_C12TR2_PFREQ_B_0X1		(0x1u<<12)
#define	GPDMA_C12TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C12TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C12TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C12TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C12TR2_SWREQ_B_0X0		(0x0u<<9)
#define	GPDMA_C12TR2_SWREQ_B_0X1		(0x1u<<9)

// C12BR1 Configuration

#define	GPDMA_C12BR1_BRDDEC				(0x1u<<31)
#define	GPDMA_C12BR1_BRSDEC				(0x1u<<30)
#define	GPDMA_C12BR1_DDEC				(0x1u<<29)
#define	GPDMA_C12BR1_SDEC				(0x1u<<28)
#define	GPDMA_C12BR1_BRC				(0x7FFu<<16)
#define	GPDMA_C12BR1_BRC_0				(0x1u<<16)
#define	GPDMA_C12BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C12BR1_BNDT_0				(0x1u<<0)

#define	GPDMA_C12BR1_BRDDEC_B_0X0		(0x0u<<31)
#define	GPDMA_C12BR1_BRDDEC_B_0X1		(0x1u<<31)
#define	GPDMA_C12BR1_BRSDEC_B_0X0		(0x0u<<30)
#define	GPDMA_C12BR1_BRSDEC_B_0X1		(0x1u<<30)
#define	GPDMA_C12BR1_DDEC_B_0X0			(0x0u<<29)
#define	GPDMA_C12BR1_DDEC_B_0X1			(0x1u<<29)
#define	GPDMA_C12BR1_SDEC_B_0X0			(0x0u<<28)
#define	GPDMA_C12BR1_SDEC_B_0X1			(0x1u<<28)

// C12SAR Configuration

#define	GPDMA_C12SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C12SAR_SA_0				(0x1u<<0)

// C12DAR Configuration

#define	GPDMA_C12DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C12DAR_DA_0				(0x1u<<0)

// C12TR3 Configuration

#define	GPDMA_C12TR3_DAO				(0x1FFFu<<16)
#define	GPDMA_C12TR3_DAO_0				(0x1u<<16)
#define	GPDMA_C12TR3_SAO				(0x1FFFu<<0)
#define	GPDMA_C12TR3_SAO_0				(0x1u<<0)

// C12BR2 Configuration

#define	GPDMA_C12BR2_BRDAO				(0xFFFFu<<16)
#define	GPDMA_C12BR2_BRDAO_0			(0x1u<<16)
#define	GPDMA_C12BR2_BRSAO				(0xFFFFu<<0)
#define	GPDMA_C12BR2_BRSAO_0			(0x1u<<0)

// C12LLR Configuration

#define	GPDMA_C12LLR_UT1				(0x1u<<31)
#define	GPDMA_C12LLR_UT2				(0x1u<<30)
#define	GPDMA_C12LLR_UB1				(0x1u<<29)
#define	GPDMA_C12LLR_USA				(0x1u<<28)
#define	GPDMA_C12LLR_UDA				(0x1u<<27)
#define	GPDMA_C12LLR_UT3				(0x1u<<26)
#define	GPDMA_C12LLR_UB2				(0x1u<<25)
#define	GPDMA_C12LLR_ULL				(0x1u<<16)
#define	GPDMA_C12LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C12LLR_LA_0				(0x1u<<2)

#define	GPDMA_C12LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C12LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C12LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C12LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C12LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C12LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C12LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C12LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C12LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C12LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C12LLR_UT3_B_0X0			(0x0u<<26)
#define	GPDMA_C12LLR_UT3_B_0X1			(0x1u<<26)
#define	GPDMA_C12LLR_UB2_B_0X0			(0x0u<<25)
#define	GPDMA_C12LLR_UB2_B_0X1			(0x1u<<25)
#define	GPDMA_C12LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C12LLR_ULL_B_0X1			(0x1u<<16)

// C13LBAR Configuration

#define	GPDMA_C13LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C13LBAR_LBA_0				(0x1u<<16)

// C13FCR Configuration

#define	GPDMA_C13FCR_TOF				(0x1u<<14)
#define	GPDMA_C13FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C13FCR_USEF				(0x1u<<12)
#define	GPDMA_C13FCR_ULEF				(0x1u<<11)
#define	GPDMA_C13FCR_DTEF				(0x1u<<10)
#define	GPDMA_C13FCR_HTF				(0x1u<<9)
#define	GPDMA_C13FCR_TCF				(0x1u<<8)

#define	GPDMA_C13FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C13FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C13FCR_SUSPF_B_0X0		(0x0u<<13)
#define	GPDMA_C13FCR_SUSPF_B_0X1		(0x1u<<13)
#define	GPDMA_C13FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C13FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C13FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C13FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C13FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C13FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C13FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C13FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C13FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C13FCR_TCF_B_0X1			(0x1u<<8)

// C13SR Configuration

#define	GPDMA_C13SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C13SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C13SR_TOF					(0x1u<<14)
#define	GPDMA_C13SR_SUSPF				(0x1u<<13)
#define	GPDMA_C13SR_USEF				(0x1u<<12)
#define	GPDMA_C13SR_ULEF				(0x1u<<11)
#define	GPDMA_C13SR_DTEF				(0x1u<<10)
#define	GPDMA_C13SR_HTF					(0x1u<<9)
#define	GPDMA_C13SR_TCF					(0x1u<<8)
#define	GPDMA_C13SR_IDLEF				(0x1u<<0)

#define	GPDMA_C13SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C13SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C13SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C13SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C13SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C13SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C13SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C13SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C13SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C13SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C13SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C13SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C13SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C13SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C13SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C13SR_IDLEF_B_0X1			(0x1u<<0)

// C13CR Configuration

#define	GPDMA_C13CR_PRIO				(0x3u<<22)
#define	GPDMA_C13CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C13CR_LAP					(0x1u<<17)
#define	GPDMA_C13CR_LSM					(0x1u<<16)
#define	GPDMA_C13CR_TOIE				(0x1u<<14)
#define	GPDMA_C13CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C13CR_USEIE				(0x1u<<12)
#define	GPDMA_C13CR_ULEIE				(0x1u<<11)
#define	GPDMA_C13CR_DTEIE				(0x1u<<10)
#define	GPDMA_C13CR_HTIE				(0x1u<<9)
#define	GPDMA_C13CR_TCIE				(0x1u<<8)
#define	GPDMA_C13CR_SUSP				(0x1u<<2)
#define	GPDMA_C13CR_RESET				(0x1u<<1)
#define	GPDMA_C13CR_EN					(0x1u<<0)

#define	GPDMA_C13CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C13CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C13CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C13CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C13CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C13CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C13CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C13CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C13CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C13CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C13CR_SUSPIE_B_0X0		(0x0u<<13)
#define	GPDMA_C13CR_SUSPIE_B_0X1		(0x1u<<13)
#define	GPDMA_C13CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C13CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C13CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C13CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C13CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C13CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C13CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C13CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C13CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C13CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C13CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C13CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C13CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C13CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C13CR_EN_B_0X0			(0x0u<<0)
#define	GPDMA_C13CR_EN_B_0X1			(0x1u<<0)

// C13TR1 Configuration

#define	GPDMA_C13TR1_DSEC				(0x1u<<31)
#define	GPDMA_C13TR1_DAP				(0x1u<<30)
#define	GPDMA_C13TR1_DHX				(0x1u<<27)
#define	GPDMA_C13TR1_DBX				(0x1u<<26)
#define	GPDMA_C13TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C13TR1_DBL_1_0			(0x1u<<20)
#define	GPDMA_C13TR1_DINC				(0x1u<<19)
#define	GPDMA_C13TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C13TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C13TR1_SSEC				(0x1u<<15)
#define	GPDMA_C13TR1_SAP				(0x1u<<14)
#define	GPDMA_C13TR1_SBX				(0x1u<<13)
#define	GPDMA_C13TR1_PAM				(0x3u<<11)
#define	GPDMA_C13TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C13TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C13TR1_SBL_1_0			(0x1u<<4)
#define	GPDMA_C13TR1_SINC				(0x1u<<3)
#define	GPDMA_C13TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C13TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C13TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C13TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C13TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C13TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C13TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C13TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C13TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C13TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C13TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C13TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C13TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C13TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C13TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C13TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C13TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C13TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C13TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C13TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C13TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C13TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C13TR1_PAM_B_0X0_PAM_1	(0x0u<<11)
#define	GPDMA_C13TR1_PAM_B_0X1_PAM_1	(0x1u<<11)
#define	GPDMA_C13TR1_PAM_B_0X2_PAM_1	(0x2u<<11)
#define	GPDMA_C13TR1_PAM_B_0X3_PAM_1	(0x3u<<11)
#define	GPDMA_C13TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C13TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C13TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C13TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C13TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C13TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C13TR2 Configuration

#define	GPDMA_C13TR2_TCEM				(0x3u<<30)
#define	GPDMA_C13TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C13TR2_TRIGPOL			(0x3u<<24)
#define	GPDMA_C13TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C13TR2_TRIGSEL			(0x7Fu<<16)
#define	GPDMA_C13TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C13TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C13TR2_TRIGM_0			(0x1u<<14)
#define	GPDMA_C13TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C13TR2_BREQ				(0x1u<<11)
#define	GPDMA_C13TR2_DREQ				(0x1u<<10)
#define	GPDMA_C13TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C13TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C13TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C13TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C13TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C13TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C13TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C13TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C13TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C13TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C13TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C13TR2_TRIGM_B_0X0		(0x0u<<14)
#define	GPDMA_C13TR2_TRIGM_B_0X1		(0x1u<<14)
#define	GPDMA_C13TR2_TRIGM_B_0X2		(0x2u<<14)
#define	GPDMA_C13TR2_TRIGM_B_0X3		(0x3u<<14)
#define	GPDMA_C13TR2_PFREQ_B_0X0		(0x0u<<12)
#define	GPDMA_C13TR2_PFREQ_B_0X1		(0x1u<<12)
#define	GPDMA_C13TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C13TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C13TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C13TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C13TR2_SWREQ_B_0X0		(0x0u<<9)
#define	GPDMA_C13TR2_SWREQ_B_0X1		(0x1u<<9)

// C13BR1 Configuration

#define	GPDMA_C13BR1_BRDDEC				(0x1u<<31)
#define	GPDMA_C13BR1_BRSDEC				(0x1u<<30)
#define	GPDMA_C13BR1_DDEC				(0x1u<<29)
#define	GPDMA_C13BR1_SDEC				(0x1u<<28)
#define	GPDMA_C13BR1_BRC				(0x7FFu<<16)
#define	GPDMA_C13BR1_BRC_0				(0x1u<<16)
#define	GPDMA_C13BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C13BR1_BNDT_0				(0x1u<<0)

#define	GPDMA_C13BR1_BRDDEC_B_0X0		(0x0u<<31)
#define	GPDMA_C13BR1_BRDDEC_B_0X1		(0x1u<<31)
#define	GPDMA_C13BR1_BRSDEC_B_0X0		(0x0u<<30)
#define	GPDMA_C13BR1_BRSDEC_B_0X1		(0x1u<<30)
#define	GPDMA_C13BR1_DDEC_B_0X0			(0x0u<<29)
#define	GPDMA_C13BR1_DDEC_B_0X1			(0x1u<<29)
#define	GPDMA_C13BR1_SDEC_B_0X0			(0x0u<<28)
#define	GPDMA_C13BR1_SDEC_B_0X1			(0x1u<<28)

// C13SAR Configuration

#define	GPDMA_C13SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C13SAR_SA_0				(0x1u<<0)

// C13DAR Configuration

#define	GPDMA_C13DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C13DAR_DA_0				(0x1u<<0)

// C13TR3 Configuration

#define	GPDMA_C13TR3_DAO				(0x1FFFu<<16)
#define	GPDMA_C13TR3_DAO_0				(0x1u<<16)
#define	GPDMA_C13TR3_SAO				(0x1FFFu<<0)
#define	GPDMA_C13TR3_SAO_0				(0x1u<<0)

// C13BR2 Configuration

#define	GPDMA_C13BR2_BRDAO				(0xFFFFu<<16)
#define	GPDMA_C13BR2_BRDAO_0			(0x1u<<16)
#define	GPDMA_C13BR2_BRSAO				(0xFFFFu<<0)
#define	GPDMA_C13BR2_BRSAO_0			(0x1u<<0)

// C13LLR Configuration

#define	GPDMA_C13LLR_UT1				(0x1u<<31)
#define	GPDMA_C13LLR_UT2				(0x1u<<30)
#define	GPDMA_C13LLR_UB1				(0x1u<<29)
#define	GPDMA_C13LLR_USA				(0x1u<<28)
#define	GPDMA_C13LLR_UDA				(0x1u<<27)
#define	GPDMA_C13LLR_UT3				(0x1u<<26)
#define	GPDMA_C13LLR_UB2				(0x1u<<25)
#define	GPDMA_C13LLR_ULL				(0x1u<<16)
#define	GPDMA_C13LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C13LLR_LA_0				(0x1u<<2)

#define	GPDMA_C13LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C13LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C13LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C13LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C13LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C13LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C13LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C13LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C13LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C13LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C13LLR_UT3_B_0X0			(0x0u<<26)
#define	GPDMA_C13LLR_UT3_B_0X1			(0x1u<<26)
#define	GPDMA_C13LLR_UB2_B_0X0			(0x0u<<25)
#define	GPDMA_C13LLR_UB2_B_0X1			(0x1u<<25)
#define	GPDMA_C13LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C13LLR_ULL_B_0X1			(0x1u<<16)

// C14LBAR Configuration

#define	GPDMA_C14LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C14LBAR_LBA_0				(0x1u<<16)

// C14FCR Configuration

#define	GPDMA_C14FCR_TOF				(0x1u<<14)
#define	GPDMA_C14FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C14FCR_USEF				(0x1u<<12)
#define	GPDMA_C14FCR_ULEF				(0x1u<<11)
#define	GPDMA_C14FCR_DTEF				(0x1u<<10)
#define	GPDMA_C14FCR_HTF				(0x1u<<9)
#define	GPDMA_C14FCR_TCF				(0x1u<<8)

#define	GPDMA_C14FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C14FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C14FCR_SUSPF_B_0X0		(0x0u<<13)
#define	GPDMA_C14FCR_SUSPF_B_0X1		(0x1u<<13)
#define	GPDMA_C14FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C14FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C14FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C14FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C14FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C14FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C14FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C14FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C14FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C14FCR_TCF_B_0X1			(0x1u<<8)

// C14SR Configuration

#define	GPDMA_C14SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C14SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C14SR_TOF					(0x1u<<14)
#define	GPDMA_C14SR_SUSPF				(0x1u<<13)
#define	GPDMA_C14SR_USEF				(0x1u<<12)
#define	GPDMA_C14SR_ULEF				(0x1u<<11)
#define	GPDMA_C14SR_DTEF				(0x1u<<10)
#define	GPDMA_C14SR_HTF					(0x1u<<9)
#define	GPDMA_C14SR_TCF					(0x1u<<8)
#define	GPDMA_C14SR_IDLEF				(0x1u<<0)

#define	GPDMA_C14SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C14SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C14SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C14SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C14SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C14SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C14SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C14SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C14SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C14SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C14SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C14SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C14SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C14SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C14SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C14SR_IDLEF_B_0X1			(0x1u<<0)

// C14CR Configuration

#define	GPDMA_C14CR_PRIO				(0x3u<<22)
#define	GPDMA_C14CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C14CR_LAP					(0x1u<<17)
#define	GPDMA_C14CR_LSM					(0x1u<<16)
#define	GPDMA_C14CR_TOIE				(0x1u<<14)
#define	GPDMA_C14CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C14CR_USEIE				(0x1u<<12)
#define	GPDMA_C14CR_ULEIE				(0x1u<<11)
#define	GPDMA_C14CR_DTEIE				(0x1u<<10)
#define	GPDMA_C14CR_HTIE				(0x1u<<9)
#define	GPDMA_C14CR_TCIE				(0x1u<<8)
#define	GPDMA_C14CR_SUSP				(0x1u<<2)
#define	GPDMA_C14CR_RESET				(0x1u<<1)
#define	GPDMA_C14CR_EN					(0x1u<<0)

#define	GPDMA_C14CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C14CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C14CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C14CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C14CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C14CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C14CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C14CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C14CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C14CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C14CR_SUSPIE_B_0X0		(0x0u<<13)
#define	GPDMA_C14CR_SUSPIE_B_0X1		(0x1u<<13)
#define	GPDMA_C14CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C14CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C14CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C14CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C14CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C14CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C14CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C14CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C14CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C14CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C14CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C14CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C14CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C14CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C14CR_EN_B_0X0			(0x0u<<0)
#define	GPDMA_C14CR_EN_B_0X1			(0x1u<<0)

// C14TR1 Configuration

#define	GPDMA_C14TR1_DSEC				(0x1u<<31)
#define	GPDMA_C14TR1_DAP				(0x1u<<30)
#define	GPDMA_C14TR1_DHX				(0x1u<<27)
#define	GPDMA_C14TR1_DBX				(0x1u<<26)
#define	GPDMA_C14TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C14TR1_DBL_1_0			(0x1u<<20)
#define	GPDMA_C14TR1_DINC				(0x1u<<19)
#define	GPDMA_C14TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C14TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C14TR1_SSEC				(0x1u<<15)
#define	GPDMA_C14TR1_SAP				(0x1u<<14)
#define	GPDMA_C14TR1_SBX				(0x1u<<13)
#define	GPDMA_C14TR1_PAM				(0x3u<<11)
#define	GPDMA_C14TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C14TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C14TR1_SBL_1_0			(0x1u<<4)
#define	GPDMA_C14TR1_SINC				(0x1u<<3)
#define	GPDMA_C14TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C14TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C14TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C14TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C14TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C14TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C14TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C14TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C14TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C14TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C14TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C14TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C14TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C14TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C14TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C14TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C14TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C14TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C14TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C14TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C14TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C14TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C14TR1_PAM_B_0X0_PAM_1	(0x0u<<11)
#define	GPDMA_C14TR1_PAM_B_0X1_PAM_1	(0x1u<<11)
#define	GPDMA_C14TR1_PAM_B_0X2_PAM_1	(0x2u<<11)
#define	GPDMA_C14TR1_PAM_B_0X3_PAM_1	(0x3u<<11)
#define	GPDMA_C14TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C14TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C14TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C14TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C14TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C14TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C14TR2 Configuration

#define	GPDMA_C14TR2_TCEM				(0x3u<<30)
#define	GPDMA_C14TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C14TR2_TRIGPOL			(0x3u<<24)
#define	GPDMA_C14TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C14TR2_TRIGSEL			(0x7Fu<<16)
#define	GPDMA_C14TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C14TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C14TR2_TRIGM_0			(0x1u<<14)
#define	GPDMA_C14TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C14TR2_BREQ				(0x1u<<11)
#define	GPDMA_C14TR2_DREQ				(0x1u<<10)
#define	GPDMA_C14TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C14TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C14TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C14TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C14TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C14TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C14TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C14TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C14TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C14TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C14TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C14TR2_TRIGM_B_0X0		(0x0u<<14)
#define	GPDMA_C14TR2_TRIGM_B_0X1		(0x1u<<14)
#define	GPDMA_C14TR2_TRIGM_B_0X2		(0x2u<<14)
#define	GPDMA_C14TR2_TRIGM_B_0X3		(0x3u<<14)
#define	GPDMA_C14TR2_PFREQ_B_0X0		(0x0u<<12)
#define	GPDMA_C14TR2_PFREQ_B_0X1		(0x1u<<12)
#define	GPDMA_C14TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C14TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C14TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C14TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C14TR2_SWREQ_B_0X0		(0x0u<<9)
#define	GPDMA_C14TR2_SWREQ_B_0X1		(0x1u<<9)

// C14BR1 Configuration

#define	GPDMA_C14BR1_BRDDEC				(0x1u<<31)
#define	GPDMA_C14BR1_BRSDEC				(0x1u<<30)
#define	GPDMA_C14BR1_DDEC				(0x1u<<29)
#define	GPDMA_C14BR1_SDEC				(0x1u<<28)
#define	GPDMA_C14BR1_BRC				(0x7FFu<<16)
#define	GPDMA_C14BR1_BRC_0				(0x1u<<16)
#define	GPDMA_C14BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C14BR1_BNDT_0				(0x1u<<0)

#define	GPDMA_C14BR1_BRDDEC_B_0X0		(0x0u<<31)
#define	GPDMA_C14BR1_BRDDEC_B_0X1		(0x1u<<31)
#define	GPDMA_C14BR1_BRSDEC_B_0X0		(0x0u<<30)
#define	GPDMA_C14BR1_BRSDEC_B_0X1		(0x1u<<30)
#define	GPDMA_C14BR1_DDEC_B_0X0			(0x0u<<29)
#define	GPDMA_C14BR1_DDEC_B_0X1			(0x1u<<29)
#define	GPDMA_C14BR1_SDEC_B_0X0			(0x0u<<28)
#define	GPDMA_C14BR1_SDEC_B_0X1			(0x1u<<28)

// C14SAR Configuration

#define	GPDMA_C14SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C14SAR_SA_0				(0x1u<<0)

// C14DAR Configuration

#define	GPDMA_C14DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C14DAR_DA_0				(0x1u<<0)

// C14TR3 Configuration

#define	GPDMA_C14TR3_DAO				(0x1FFFu<<16)
#define	GPDMA_C14TR3_DAO_0				(0x1u<<16)
#define	GPDMA_C14TR3_SAO				(0x1FFFu<<0)
#define	GPDMA_C14TR3_SAO_0				(0x1u<<0)

// C14BR2 Configuration

#define	GPDMA_C14BR2_BRDAO				(0xFFFFu<<16)
#define	GPDMA_C14BR2_BRDAO_0			(0x1u<<16)
#define	GPDMA_C14BR2_BRSAO				(0xFFFFu<<0)
#define	GPDMA_C14BR2_BRSAO_0			(0x1u<<0)

// C14LLR Configuration

#define	GPDMA_C14LLR_UT1				(0x1u<<31)
#define	GPDMA_C14LLR_UT2				(0x1u<<30)
#define	GPDMA_C14LLR_UB1				(0x1u<<29)
#define	GPDMA_C14LLR_USA				(0x1u<<28)
#define	GPDMA_C14LLR_UDA				(0x1u<<27)
#define	GPDMA_C14LLR_UT3				(0x1u<<26)
#define	GPDMA_C14LLR_UB2				(0x1u<<25)
#define	GPDMA_C14LLR_ULL				(0x1u<<16)
#define	GPDMA_C14LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C14LLR_LA_0				(0x1u<<2)

#define	GPDMA_C14LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C14LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C14LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C14LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C14LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C14LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C14LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C14LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C14LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C14LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C14LLR_UT3_B_0X0			(0x0u<<26)
#define	GPDMA_C14LLR_UT3_B_0X1			(0x1u<<26)
#define	GPDMA_C14LLR_UB2_B_0X0			(0x0u<<25)
#define	GPDMA_C14LLR_UB2_B_0X1			(0x1u<<25)
#define	GPDMA_C14LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C14LLR_ULL_B_0X1			(0x1u<<16)

// C15LBAR Configuration

#define	GPDMA_C15LBAR_LBA				(0xFFFFu<<16)
#define	GPDMA_C15LBAR_LBA_0				(0x1u<<16)

// C15FCR Configuration

#define	GPDMA_C15FCR_TOF				(0x1u<<14)
#define	GPDMA_C15FCR_SUSPF				(0x1u<<13)
#define	GPDMA_C15FCR_USEF				(0x1u<<12)
#define	GPDMA_C15FCR_ULEF				(0x1u<<11)
#define	GPDMA_C15FCR_DTEF				(0x1u<<10)
#define	GPDMA_C15FCR_HTF				(0x1u<<9)
#define	GPDMA_C15FCR_TCF				(0x1u<<8)

#define	GPDMA_C15FCR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C15FCR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C15FCR_SUSPF_B_0X0		(0x0u<<13)
#define	GPDMA_C15FCR_SUSPF_B_0X1		(0x1u<<13)
#define	GPDMA_C15FCR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C15FCR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C15FCR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C15FCR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C15FCR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C15FCR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C15FCR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C15FCR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C15FCR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C15FCR_TCF_B_0X1			(0x1u<<8)

// C15SR Configuration

#define	GPDMA_C15SR_FIFOL				(0xFFu<<16)
#define	GPDMA_C15SR_FIFOL_0				(0x1u<<16)
#define	GPDMA_C15SR_TOF					(0x1u<<14)
#define	GPDMA_C15SR_SUSPF				(0x1u<<13)
#define	GPDMA_C15SR_USEF				(0x1u<<12)
#define	GPDMA_C15SR_ULEF				(0x1u<<11)
#define	GPDMA_C15SR_DTEF				(0x1u<<10)
#define	GPDMA_C15SR_HTF					(0x1u<<9)
#define	GPDMA_C15SR_TCF					(0x1u<<8)
#define	GPDMA_C15SR_IDLEF				(0x1u<<0)

#define	GPDMA_C15SR_TOF_B_0X0			(0x0u<<14)
#define	GPDMA_C15SR_TOF_B_0X1			(0x1u<<14)
#define	GPDMA_C15SR_SUSPF_B_0X0			(0x0u<<13)
#define	GPDMA_C15SR_SUSPF_B_0X1			(0x1u<<13)
#define	GPDMA_C15SR_USEF_B_0X0			(0x0u<<12)
#define	GPDMA_C15SR_USEF_B_0X1			(0x1u<<12)
#define	GPDMA_C15SR_ULEF_B_0X0			(0x0u<<11)
#define	GPDMA_C15SR_ULEF_B_0X1			(0x1u<<11)
#define	GPDMA_C15SR_DTEF_B_0X0			(0x0u<<10)
#define	GPDMA_C15SR_DTEF_B_0X1			(0x1u<<10)
#define	GPDMA_C15SR_HTF_B_0X0			(0x0u<<9)
#define	GPDMA_C15SR_HTF_B_0X1			(0x1u<<9)
#define	GPDMA_C15SR_TCF_B_0X0			(0x0u<<8)
#define	GPDMA_C15SR_TCF_B_0X1			(0x1u<<8)
#define	GPDMA_C15SR_IDLEF_B_0X0			(0x0u<<0)
#define	GPDMA_C15SR_IDLEF_B_0X1			(0x1u<<0)

// C15CR Configuration

#define	GPDMA_C15CR_PRIO				(0x3u<<22)
#define	GPDMA_C15CR_PRIO_0				(0x1u<<22)
#define	GPDMA_C15CR_LAP					(0x1u<<17)
#define	GPDMA_C15CR_LSM					(0x1u<<16)
#define	GPDMA_C15CR_TOIE				(0x1u<<14)
#define	GPDMA_C15CR_SUSPIE				(0x1u<<13)
#define	GPDMA_C15CR_USEIE				(0x1u<<12)
#define	GPDMA_C15CR_ULEIE				(0x1u<<11)
#define	GPDMA_C15CR_DTEIE				(0x1u<<10)
#define	GPDMA_C15CR_HTIE				(0x1u<<9)
#define	GPDMA_C15CR_TCIE				(0x1u<<8)
#define	GPDMA_C15CR_SUSP				(0x1u<<2)
#define	GPDMA_C15CR_RESET				(0x1u<<1)
#define	GPDMA_C15CR_EN					(0x1u<<0)

#define	GPDMA_C15CR_PRIO_B_0X0			(0x0u<<22)
#define	GPDMA_C15CR_PRIO_B_0X1			(0x1u<<22)
#define	GPDMA_C15CR_PRIO_B_0X2			(0x2u<<22)
#define	GPDMA_C15CR_PRIO_B_0X3			(0x3u<<22)
#define	GPDMA_C15CR_LAP_B_0X0			(0x0u<<17)
#define	GPDMA_C15CR_LAP_B_0X1			(0x1u<<17)
#define	GPDMA_C15CR_LSM_B_0X0			(0x0u<<16)
#define	GPDMA_C15CR_LSM_B_0X1			(0x1u<<16)
#define	GPDMA_C15CR_TOIE_B_0X0			(0x0u<<14)
#define	GPDMA_C15CR_TOIE_B_0X1			(0x1u<<14)
#define	GPDMA_C15CR_SUSPIE_B_0X0		(0x0u<<13)
#define	GPDMA_C15CR_SUSPIE_B_0X1		(0x1u<<13)
#define	GPDMA_C15CR_USEIE_B_0X0			(0x0u<<12)
#define	GPDMA_C15CR_USEIE_B_0X1			(0x1u<<12)
#define	GPDMA_C15CR_ULEIE_B_0X0			(0x0u<<11)
#define	GPDMA_C15CR_ULEIE_B_0X1			(0x1u<<11)
#define	GPDMA_C15CR_DTEIE_B_0X0			(0x0u<<10)
#define	GPDMA_C15CR_DTEIE_B_0X1			(0x1u<<10)
#define	GPDMA_C15CR_HTIE_B_0X0			(0x0u<<9)
#define	GPDMA_C15CR_HTIE_B_0X1			(0x1u<<9)
#define	GPDMA_C15CR_TCIE_B_0X0			(0x0u<<8)
#define	GPDMA_C15CR_TCIE_B_0X1			(0x1u<<8)
#define	GPDMA_C15CR_SUSP_B_0X0			(0x0u<<2)
#define	GPDMA_C15CR_SUSP_B_0X1			(0x1u<<2)
#define	GPDMA_C15CR_RESET_B_0X0			(0x0u<<1)
#define	GPDMA_C15CR_RESET_B_0X1			(0x1u<<1)
#define	GPDMA_C15CR_EN_B_0X0			(0x0u<<0)
#define	GPDMA_C15CR_EN_B_0X1			(0x1u<<0)

// C15TR1 Configuration

#define	GPDMA_C15TR1_DSEC				(0x1u<<31)
#define	GPDMA_C15TR1_DAP				(0x1u<<30)
#define	GPDMA_C15TR1_DHX				(0x1u<<27)
#define	GPDMA_C15TR1_DBX				(0x1u<<26)
#define	GPDMA_C15TR1_DBL_1				(0x3Fu<<20)
#define	GPDMA_C15TR1_DBL_1_0			(0x1u<<20)
#define	GPDMA_C15TR1_DINC				(0x1u<<19)
#define	GPDMA_C15TR1_DDW_LOG2			(0x3u<<16)
#define	GPDMA_C15TR1_DDW_LOG2_0			(0x1u<<16)
#define	GPDMA_C15TR1_SSEC				(0x1u<<15)
#define	GPDMA_C15TR1_SAP				(0x1u<<14)
#define	GPDMA_C15TR1_SBX				(0x1u<<13)
#define	GPDMA_C15TR1_PAM				(0x3u<<11)
#define	GPDMA_C15TR1_PAM_0				(0x1u<<11)
#define	GPDMA_C15TR1_SBL_1				(0x3Fu<<4)
#define	GPDMA_C15TR1_SBL_1_0			(0x1u<<4)
#define	GPDMA_C15TR1_SINC				(0x1u<<3)
#define	GPDMA_C15TR1_SDW_LOG2			(0x3u<<0)
#define	GPDMA_C15TR1_SDW_LOG2_0			(0x1u<<0)

#define	GPDMA_C15TR1_DSEC_B_0X0			(0x0u<<31)
#define	GPDMA_C15TR1_DSEC_B_0X1			(0x1u<<31)
#define	GPDMA_C15TR1_DAP_B_0X0			(0x0u<<30)
#define	GPDMA_C15TR1_DAP_B_0X1			(0x1u<<30)
#define	GPDMA_C15TR1_DHX_B_0X0			(0x0u<<27)
#define	GPDMA_C15TR1_DHX_B_0X1			(0x1u<<27)
#define	GPDMA_C15TR1_DBX_B_0X0			(0x0u<<26)
#define	GPDMA_C15TR1_DBX_B_0X1			(0x1u<<26)
#define	GPDMA_C15TR1_DINC_B_0X0			(0x0u<<19)
#define	GPDMA_C15TR1_DINC_B_0X1			(0x1u<<19)
#define	GPDMA_C15TR1_DDW_LOG2_B_0X0		(0x0u<<16)
#define	GPDMA_C15TR1_DDW_LOG2_B_0X1		(0x1u<<16)
#define	GPDMA_C15TR1_DDW_LOG2_B_0X2		(0x2u<<16)
#define	GPDMA_C15TR1_DDW_LOG2_B_0X3		(0x3u<<16)
#define	GPDMA_C15TR1_SSEC_B_0X0			(0x0u<<15)
#define	GPDMA_C15TR1_SSEC_B_0X1			(0x1u<<15)
#define	GPDMA_C15TR1_SAP_B_0X0			(0x0u<<14)
#define	GPDMA_C15TR1_SAP_B_0X1			(0x1u<<14)
#define	GPDMA_C15TR1_SBX_B_0X0			(0x0u<<13)
#define	GPDMA_C15TR1_SBX_B_0X1			(0x1u<<13)
#define	GPDMA_C15TR1_PAM_B_0X0_PAM_1	(0x0u<<11)
#define	GPDMA_C15TR1_PAM_B_0X1_PAM_1	(0x1u<<11)
#define	GPDMA_C15TR1_PAM_B_0X2_PAM_1	(0x2u<<11)
#define	GPDMA_C15TR1_PAM_B_0X3_PAM_1	(0x3u<<11)
#define	GPDMA_C15TR1_SINC_B_0X0			(0x0u<<3)
#define	GPDMA_C15TR1_SINC_B_0X1			(0x1u<<3)
#define	GPDMA_C15TR1_SDW_LOG2_B_0X0		(0x0u<<0)
#define	GPDMA_C15TR1_SDW_LOG2_B_0X1		(0x1u<<0)
#define	GPDMA_C15TR1_SDW_LOG2_B_0X2		(0x2u<<0)
#define	GPDMA_C15TR1_SDW_LOG2_B_0X3		(0x3u<<0)

// C15TR2 Configuration

#define	GPDMA_C15TR2_TCEM				(0x3u<<30)
#define	GPDMA_C15TR2_TCEM_0				(0x1u<<30)
#define	GPDMA_C15TR2_TRIGPOL			(0x3u<<24)
#define	GPDMA_C15TR2_TRIGPOL_0			(0x1u<<24)
#define	GPDMA_C15TR2_TRIGSEL			(0x7Fu<<16)
#define	GPDMA_C15TR2_TRIGSEL_0			(0x1u<<16)
#define	GPDMA_C15TR2_TRIGM				(0x3u<<14)
#define	GPDMA_C15TR2_TRIGM_0			(0x1u<<14)
#define	GPDMA_C15TR2_PFREQ				(0x1u<<12)
#define	GPDMA_C15TR2_BREQ				(0x1u<<11)
#define	GPDMA_C15TR2_DREQ				(0x1u<<10)
#define	GPDMA_C15TR2_SWREQ				(0x1u<<9)
#define	GPDMA_C15TR2_REQSEL				(0xFFu<<0)
#define	GPDMA_C15TR2_REQSEL_0			(0x1u<<0)

#define	GPDMA_C15TR2_TCEM_B_0X0			(0x0u<<30)
#define	GPDMA_C15TR2_TCEM_B_0X1			(0x1u<<30)
#define	GPDMA_C15TR2_TCEM_B_0X2			(0x2u<<30)
#define	GPDMA_C15TR2_TCEM_B_0X3			(0x3u<<30)
#define	GPDMA_C15TR2_TRIGPOL_B_0X0		(0x0u<<24)
#define	GPDMA_C15TR2_TRIGPOL_B_0X1		(0x1u<<24)
#define	GPDMA_C15TR2_TRIGPOL_B_0X2		(0x2u<<24)
#define	GPDMA_C15TR2_TRIGPOL_B_0X3		(0x3u<<24)
#define	GPDMA_C15TR2_TRIGM_B_0X0		(0x0u<<14)
#define	GPDMA_C15TR2_TRIGM_B_0X1		(0x1u<<14)
#define	GPDMA_C15TR2_TRIGM_B_0X2		(0x2u<<14)
#define	GPDMA_C15TR2_TRIGM_B_0X3		(0x3u<<14)
#define	GPDMA_C15TR2_PFREQ_B_0X0		(0x0u<<12)
#define	GPDMA_C15TR2_PFREQ_B_0X1		(0x1u<<12)
#define	GPDMA_C15TR2_BREQ_B_0X0			(0x0u<<11)
#define	GPDMA_C15TR2_BREQ_B_0X1			(0x1u<<11)
#define	GPDMA_C15TR2_DREQ_B_0X0			(0x0u<<10)
#define	GPDMA_C15TR2_DREQ_B_0X1			(0x1u<<10)
#define	GPDMA_C15TR2_SWREQ_B_0X0		(0x0u<<9)
#define	GPDMA_C15TR2_SWREQ_B_0X1		(0x1u<<9)

// C15BR1 Configuration

#define	GPDMA_C15BR1_BRDDEC				(0x1u<<31)
#define	GPDMA_C15BR1_BRSDEC				(0x1u<<30)
#define	GPDMA_C15BR1_DDEC				(0x1u<<29)
#define	GPDMA_C15BR1_SDEC				(0x1u<<28)
#define	GPDMA_C15BR1_BRC				(0x7FFu<<16)
#define	GPDMA_C15BR1_BRC_0				(0x1u<<16)
#define	GPDMA_C15BR1_BNDT				(0xFFFFu<<0)
#define	GPDMA_C15BR1_BNDT_0				(0x1u<<0)

#define	GPDMA_C15BR1_BRDDEC_B_0X0		(0x0u<<31)
#define	GPDMA_C15BR1_BRDDEC_B_0X1		(0x1u<<31)
#define	GPDMA_C15BR1_BRSDEC_B_0X0		(0x0u<<30)
#define	GPDMA_C15BR1_BRSDEC_B_0X1		(0x1u<<30)
#define	GPDMA_C15BR1_DDEC_B_0X0			(0x0u<<29)
#define	GPDMA_C15BR1_DDEC_B_0X1			(0x1u<<29)
#define	GPDMA_C15BR1_SDEC_B_0X0			(0x0u<<28)
#define	GPDMA_C15BR1_SDEC_B_0X1			(0x1u<<28)

// C15SAR Configuration

#define	GPDMA_C15SAR_SA					(0xFFFFFFFFu<<0)
#define	GPDMA_C15SAR_SA_0				(0x1u<<0)

// C15DAR Configuration

#define	GPDMA_C15DAR_DA					(0xFFFFFFFFu<<0)
#define	GPDMA_C15DAR_DA_0				(0x1u<<0)

// C15TR3 Configuration

#define	GPDMA_C15TR3_DAO				(0x1FFFu<<16)
#define	GPDMA_C15TR3_DAO_0				(0x1u<<16)
#define	GPDMA_C15TR3_SAO				(0x1FFFu<<0)
#define	GPDMA_C15TR3_SAO_0				(0x1u<<0)

// C15BR2 Configuration

#define	GPDMA_C15BR2_BRDAO				(0xFFFFu<<16)
#define	GPDMA_C15BR2_BRDAO_0			(0x1u<<16)
#define	GPDMA_C15BR2_BRSAO				(0xFFFFu<<0)
#define	GPDMA_C15BR2_BRSAO_0			(0x1u<<0)

// C15LLR Configuration

#define	GPDMA_C15LLR_UT1				(0x1u<<31)
#define	GPDMA_C15LLR_UT2				(0x1u<<30)
#define	GPDMA_C15LLR_UB1				(0x1u<<29)
#define	GPDMA_C15LLR_USA				(0x1u<<28)
#define	GPDMA_C15LLR_UDA				(0x1u<<27)
#define	GPDMA_C15LLR_UT3				(0x1u<<26)
#define	GPDMA_C15LLR_UB2				(0x1u<<25)
#define	GPDMA_C15LLR_ULL				(0x1u<<16)
#define	GPDMA_C15LLR_LA					(0x3FFFu<<2)
#define	GPDMA_C15LLR_LA_0				(0x1u<<2)

#define	GPDMA_C15LLR_UT1_B_0X0			(0x0u<<31)
#define	GPDMA_C15LLR_UT1_B_0X1			(0x1u<<31)
#define	GPDMA_C15LLR_UT2_B_0X0			(0x0u<<30)
#define	GPDMA_C15LLR_UT2_B_0X1			(0x1u<<30)
#define	GPDMA_C15LLR_UB1_B_0X0			(0x0u<<29)
#define	GPDMA_C15LLR_UB1_B_0X1			(0x1u<<29)
#define	GPDMA_C15LLR_USA_B_0X0			(0x0u<<28)
#define	GPDMA_C15LLR_USA_B_0X1			(0x1u<<28)
#define	GPDMA_C15LLR_UDA_B_0X0			(0x0u<<27)
#define	GPDMA_C15LLR_UDA_B_0X1			(0x1u<<27)
#define	GPDMA_C15LLR_UT3_B_0X0			(0x0u<<26)
#define	GPDMA_C15LLR_UT3_B_0X1			(0x1u<<26)
#define	GPDMA_C15LLR_UB2_B_0X0			(0x0u<<25)
#define	GPDMA_C15LLR_UB2_B_0X1			(0x1u<<25)
#define	GPDMA_C15LLR_ULL_B_0X0			(0x0u<<16)
#define	GPDMA_C15LLR_ULL_B_0X1			(0x1u<<16)
