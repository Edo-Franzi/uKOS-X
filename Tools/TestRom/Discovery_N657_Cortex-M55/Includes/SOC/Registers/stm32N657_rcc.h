/*
; stm32N657_rcc.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_rcc equates.
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

// RCC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	STOPCR;
	volatile	uint32_t	RESERVED0[5];
	volatile	uint32_t	CFGR1;
	volatile	uint32_t	CFGR2;
	volatile	uint32_t	CKPROTR;
	volatile	uint32_t	BDCR;
	volatile	uint32_t	HWRSR;
	volatile	uint32_t	RSR;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	LSECFGR;
	volatile	uint32_t	MSICFGR;
	volatile	uint32_t	HSICFGR;
	volatile	uint32_t	HSIMCR;
	volatile	uint32_t	HSIMSR;
	volatile	uint32_t	HSECFGR;
	volatile	uint32_t	RESERVED2[10];
	volatile	uint32_t	PLL1CFGR1;
	volatile	uint32_t	PLL1CFGR2;
	volatile	uint32_t	PLL1CFGR3;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	PLL2CFGR1;
	volatile	uint32_t	PLL2CFGR2;
	volatile	uint32_t	PLL2CFGR3;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	PLL3CFGR1;
	volatile	uint32_t	PLL3CFGR2;
	volatile	uint32_t	PLL3CFGR3;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	PLL4CFGR1;
	volatile	uint32_t	PLL4CFGR2;
	volatile	uint32_t	PLL4CFGR3;
	volatile	uint32_t	RESERVED6[2];
	volatile	uint32_t	IC1CFGR;
	volatile	uint32_t	IC2CFGR;
	volatile	uint32_t	IC3CFGR;
	volatile	uint32_t	IC4CFGR;
	volatile	uint32_t	IC5CFGR;
	volatile	uint32_t	IC6CFGR;
	volatile	uint32_t	IC7CFGR;
	volatile	uint32_t	IC8CFGR;
	volatile	uint32_t	IC9CFGR;
	volatile	uint32_t	IC10CFGR;
	volatile	uint32_t	IC11CFGR;
	volatile	uint32_t	IC12CFGR;
	volatile	uint32_t	IC13CFGR;
	volatile	uint32_t	IC14CFGR;
	volatile	uint32_t	IC15CFGR;
	volatile	uint32_t	IC16CFGR;
	volatile	uint32_t	IC17CFGR;
	volatile	uint32_t	IC18CFGR;
	volatile	uint32_t	IC19CFGR;
	volatile	uint32_t	IC20CFGR;
	volatile	uint32_t	RESERVED7[4];
	volatile	uint32_t	CIER;
	volatile	uint32_t	CIFR;
	volatile	uint32_t	CICR;
	volatile	uint32_t	RESERVED8[5];
	volatile	uint32_t	CCIPR1;
	volatile	uint32_t	CCIPR2;
	volatile	uint32_t	CCIPR3;
	volatile	uint32_t	CCIPR4;
	volatile	uint32_t	CCIPR5;
	volatile	uint32_t	CCIPR6;
	volatile	uint32_t	CCIPR7;
	volatile	uint32_t	CCIPR8;
	volatile	uint32_t	CCIPR9;
	volatile	uint32_t	RESERVED9[2];
	volatile	uint32_t	CCIPR12;
	volatile	uint32_t	CCIPR13;
	volatile	uint32_t	CCIPR14;
	volatile	uint32_t	RESERVED10[34];
	volatile	uint32_t	BUSRSTR;
	volatile	uint32_t	MISCRSTR;
	volatile	uint32_t	MEMRSTR;
	volatile	uint32_t	AHB1RSTR;
	volatile	uint32_t	AHB2RSTR;
	volatile	uint32_t	AHB3RSTR;
	volatile	uint32_t	AHB4RSTR;
	volatile	uint32_t	AHB5RSTR;
	volatile	uint32_t	APB1LRSTR;
	volatile	uint32_t	APB1HRSTR;
	volatile	uint32_t	APB2RSTR;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	APB4LRSTR;
	volatile	uint32_t	APB4HRSTR;
	volatile	uint32_t	APB5RSTR;
	volatile	uint32_t	DIVENR;
	volatile	uint32_t	BUSENR;
	volatile	uint32_t	MISCENR;
	volatile	uint32_t	MEMENR;
	volatile	uint32_t	AHB1ENR;
	volatile	uint32_t	AHB2ENR;
	volatile	uint32_t	AHB3ENR;
	volatile	uint32_t	AHB4ENR;
	volatile	uint32_t	AHB5ENR;
	volatile	uint32_t	APB1LENR;
	volatile	uint32_t	APB1HENR;
	volatile	uint32_t	APB2ENR;
	volatile	uint32_t	APB3ENR;
	volatile	uint32_t	APB4LENR;
	volatile	uint32_t	APB4HENR;
	volatile	uint32_t	APB5ENR;
	volatile	uint32_t	DIVLPENR;
	volatile	uint32_t	BUSLPENR;
	volatile	uint32_t	MISCLPENR;
	volatile	uint32_t	MEMLPENR;
	volatile	uint32_t	AHB1LPENR;
	volatile	uint32_t	AHB2LPENR;
	volatile	uint32_t	AHB3LPENR;
	volatile	uint32_t	AHB4LPENR;
	volatile	uint32_t	AHB5LPENR;
	volatile	uint32_t	APB1LLPENR;
	volatile	uint32_t	APB1HLPENR;
	volatile	uint32_t	APB2LPENR;
	volatile	uint32_t	APB3LPENR;
	volatile	uint32_t	APB4LLPENR;
	volatile	uint32_t	APB4HLPENR;
	volatile	uint32_t	APB5LPENR;
	volatile	uint32_t	RESERVED12[99];
	volatile	uint32_t	RDCR;
	volatile	uint32_t	RESERVED13[204];
	volatile	uint32_t	SECCFGR0;
	volatile	uint32_t	PRIVCFGR0;
	volatile	uint32_t	LOCKCFGR0;
	volatile	uint32_t	PUBCFGR0;
	volatile	uint32_t	SECCFGR1;
	volatile	uint32_t	PRIVCFGR1;
	volatile	uint32_t	LOCKCFGR1;
	volatile	uint32_t	PUBCFGR1;
	volatile	uint32_t	SECCFGR2;
	volatile	uint32_t	PRIVCFGR2;
	volatile	uint32_t	LOCKCFGR2;
	volatile	uint32_t	PUBCFGR2;
	volatile	uint32_t	SECCFGR3;
	volatile	uint32_t	PRIVCFGR3;
	volatile	uint32_t	LOCKCFGR3;
	volatile	uint32_t	PUBCFGR3;
	volatile	uint32_t	SECCFGR4;
	volatile	uint32_t	PRIVCFGR4;
	volatile	uint32_t	LOCKCFGR4;
	volatile	uint32_t	PUBCFGR4;
	volatile	uint32_t	PUBCFGR5;
	volatile	uint32_t	RESERVED14[11];
	volatile	uint32_t	CSR;
	volatile	uint32_t	RESERVED15;
	volatile	uint32_t	STOPCSR;
	volatile	uint32_t	RESERVED16[126];
	volatile	uint32_t	BUSRSTSR;
	volatile	uint32_t	MISCRSTSR;
	volatile	uint32_t	MEMRSTSR;
	volatile	uint32_t	AHB1RSTSR;
	volatile	uint32_t	AHB2RSTSR;
	volatile	uint32_t	AHB3RSTSR;
	volatile	uint32_t	AHB4RSTSR;
	volatile	uint32_t	AHB5RSTSR;
	volatile	uint32_t	APB1LRSTSR;
	volatile	uint32_t	APB1HRSTSR;
	volatile	uint32_t	APB2RSTSR;
	volatile	uint32_t	RESERVED17;
	volatile	uint32_t	APB4LRSTSR;
	volatile	uint32_t	APB4HRSTSR;
	volatile	uint32_t	APB5RSTSR;
	volatile	uint32_t	DIVENSR;
	volatile	uint32_t	BUSENSR;
	volatile	uint32_t	MISCENSR;
	volatile	uint32_t	MEMENSR;
	volatile	uint32_t	AHB1ENSR;
	volatile	uint32_t	AHB2ENSR;
	volatile	uint32_t	AHB3ENSR;
	volatile	uint32_t	AHB4ENSR;
	volatile	uint32_t	AHB5ENSR;
	volatile	uint32_t	APB1LENSR;
	volatile	uint32_t	APB1HENSR;
	volatile	uint32_t	APB2ENSR;
	volatile	uint32_t	APB3ENSR;
	volatile	uint32_t	APB4LENSR;
	volatile	uint32_t	APB4HENSR;
	volatile	uint32_t	APB5ENSR;
	volatile	uint32_t	DIVLPENSR;
	volatile	uint32_t	BUSLPENSR;
	volatile	uint32_t	MISCLPENSR;
	volatile	uint32_t	MEMLPENSR;
	volatile	uint32_t	AHB1LPENSR;
	volatile	uint32_t	AHB2LPENSR;
	volatile	uint32_t	AHB3LPENSR;
	volatile	uint32_t	AHB4LPENSR;
	volatile	uint32_t	AHB5LPENSR;
	volatile	uint32_t	APB1LLPENSR;
	volatile	uint32_t	APB1HLPENSR;
	volatile	uint32_t	APB2LPENSR;
	volatile	uint32_t	APB3LPENSR;
	volatile	uint32_t	APB4LLPENSR;
	volatile	uint32_t	APB4HLPENSR;
	volatile	uint32_t	APB5LPENSR;
	volatile	uint32_t	RESERVED18[305];
	volatile	uint32_t	PRIVCFGSR0;
	volatile	uint32_t	RESERVED19;
	volatile	uint32_t	PUBCFGSR0;
	volatile	uint32_t	RESERVED20;
	volatile	uint32_t	PRIVCFGSR1;
	volatile	uint32_t	RESERVED21;
	volatile	uint32_t	PUBCFGSR1;
	volatile	uint32_t	RESERVED22;
	volatile	uint32_t	PRIVCFGSR2;
	volatile	uint32_t	RESERVED23;
	volatile	uint32_t	PUBCFGSR2;
	volatile	uint32_t	SECCFGSR3;
	volatile	uint32_t	PRIVCFGSR3;
	volatile	uint32_t	LOCKCFGSR3;
	volatile	uint32_t	PUBCFGSR3;
	volatile	uint32_t	RESERVED24;
	volatile	uint32_t	PRIVCFGSR4;
	volatile	uint32_t	RESERVED25;
	volatile	uint32_t	PUBCFGSR4;
	volatile	uint32_t	PUBCFGSR5;
	volatile	uint32_t	RESERVED26[11];
	volatile	uint32_t	CCR;
	volatile	uint32_t	RESERVED27;
	volatile	uint32_t	STOPCCR;
	volatile	uint32_t	RESERVED28[126];
	volatile	uint32_t	BUSRSTCR;
	volatile	uint32_t	MISCRSTCR;
	volatile	uint32_t	MEMRSTCR;
	volatile	uint32_t	AHB1RSTCR;
	volatile	uint32_t	AHB2RSTCR;
	volatile	uint32_t	AHB3RSTCR;
	volatile	uint32_t	AHB4RSTCR;
	volatile	uint32_t	AHB5RSTCR;
	volatile	uint32_t	APB1LRSTCR;
	volatile	uint32_t	APB1HRSTCR;
	volatile	uint32_t	APB2RSTCR;
	volatile	uint32_t	RESERVED29;
	volatile	uint32_t	APB4LRSTCR;
	volatile	uint32_t	APB4HRSTCR;
	volatile	uint32_t	APB5RSTCR;
	volatile	uint32_t	DIVENCR;
	volatile	uint32_t	BUSENCR;
	volatile	uint32_t	MISCENCR;
	volatile	uint32_t	MEMENCR;
	volatile	uint32_t	AHB1ENCR;
	volatile	uint32_t	AHB2ENCR;
	volatile	uint32_t	AHB3ENCR;
	volatile	uint32_t	AHB4ENCR;
	volatile	uint32_t	AHB5ENCR;
	volatile	uint32_t	APB1LENCR;
	volatile	uint32_t	APB1HENCR;
	volatile	uint32_t	APB2ENCR;
	volatile	uint32_t	APB3ENCR;
	volatile	uint32_t	APB4LENCR;
	volatile	uint32_t	APB4HENCR;
	volatile	uint32_t	APB5ENCR;
	volatile	uint32_t	DIVLPENCR;
	volatile	uint32_t	BUSLPENCR;
	volatile	uint32_t	MISCLPENCR;
	volatile	uint32_t	MEMLPENCR;
	volatile	uint32_t	AHB1LPENCR;
	volatile	uint32_t	AHB2LPENCR;
	volatile	uint32_t	AHB3LPENCR;
	volatile	uint32_t	AHB4LPENCR;
	volatile	uint32_t	AHB5LPENCR;
	volatile	uint32_t	APB1LLPENCR;
	volatile	uint32_t	APB1HLPENCR;
	volatile	uint32_t	APB2LPENCR;
	volatile	uint32_t	APB3LPENCR;
	volatile	uint32_t	APB4LLPENCR;
	volatile	uint32_t	APB4HLPENCR;
	volatile	uint32_t	APB5LPENCR;
	volatile	uint32_t	RESERVED30[305];
	volatile	uint32_t	PRIVCFGCR0;
	volatile	uint32_t	RESERVED31;
	volatile	uint32_t	PUBCFGCR0;
	volatile	uint32_t	RESERVED32;
	volatile	uint32_t	PRIVCFGCR1;
	volatile	uint32_t	RESERVED33;
	volatile	uint32_t	PUBCFGCR1;
	volatile	uint32_t	RESERVED34;
	volatile	uint32_t	PRIVCFGCR2;
	volatile	uint32_t	RESERVED35;
	volatile	uint32_t	PUBCFGCR2;
	volatile	uint32_t	RESERVED36;
	volatile	uint32_t	PRIVCFGCR3;
	volatile	uint32_t	RESERVED37;
	volatile	uint32_t	PUBCFGCR3;
	volatile	uint32_t	RESERVED38;
	volatile	uint32_t	PRIVCFGCR4;
	volatile	uint32_t	RESERVED39;
	volatile	uint32_t	PUBCFGCR4;
	volatile	uint32_t	PUBCFGCR5;
} RCC_TypeDef;

#if (defined(__cplusplus))
#define	RCC_NS	reinterpret_cast<RCC_TypeDef *>(0x46028000u)
#define	RCC_S	reinterpret_cast<RCC_TypeDef *>(0x56028000u)

#else
#define	RCC_NS	((RCC_TypeDef *)0x46028000u)
#define	RCC_S	((RCC_TypeDef *)0x56028000u)
#endif

// CR Configuration

#define	RCC_CR_PLL4ON							(0x1u<<11)
#define	RCC_CR_PLL3ON							(0x1u<<10)
#define	RCC_CR_PLL2ON							(0x1u<<9)
#define	RCC_CR_PLL1ON							(0x1u<<8)
#define	RCC_CR_HSEON							(0x1u<<4)
#define	RCC_CR_HSION							(0x1u<<3)
#define	RCC_CR_MSION							(0x1u<<2)
#define	RCC_CR_LSEON							(0x1u<<1)
#define	RCC_CR_LSION							(0x1u<<0)

#define	RCC_CR_PLL4ON_B_0X0						(0x0u<<11)
#define	RCC_CR_PLL4ON_B_0X1						(0x1u<<11)
#define	RCC_CR_PLL3ON_B_0X0						(0x0u<<10)
#define	RCC_CR_PLL3ON_B_0X1						(0x1u<<10)
#define	RCC_CR_PLL2ON_B_0X0						(0x0u<<9)
#define	RCC_CR_PLL2ON_B_0X1						(0x1u<<9)
#define	RCC_CR_PLL1ON_B_0X0						(0x0u<<8)
#define	RCC_CR_PLL1ON_B_0X1						(0x1u<<8)
#define	RCC_CR_HSEON_B_0X0						(0x0u<<4)
#define	RCC_CR_HSEON_B_0X1						(0x1u<<4)
#define	RCC_CR_HSION_B_0X0						(0x0u<<3)
#define	RCC_CR_HSION_B_0X1						(0x1u<<3)
#define	RCC_CR_MSION_B_0X0						(0x0u<<2)
#define	RCC_CR_MSION_B_0X1						(0x1u<<2)
#define	RCC_CR_LSEON_B_0X0						(0x0u<<1)
#define	RCC_CR_LSEON_B_0X1						(0x1u<<1)
#define	RCC_CR_LSION_B_0X0						(0x0u<<0)
#define	RCC_CR_LSION_B_0X1						(0x1u<<0)

// SR Configuration

#define	RCC_SR_PLL4RDY							(0x1u<<11)
#define	RCC_SR_PLL3RDY							(0x1u<<10)
#define	RCC_SR_PLL2RDY							(0x1u<<9)
#define	RCC_SR_PLL1RDY							(0x1u<<8)
#define	RCC_SR_HSERDY							(0x1u<<4)
#define	RCC_SR_HSIRDY							(0x1u<<3)
#define	RCC_SR_MSIRDY							(0x1u<<2)
#define	RCC_SR_LSERDY							(0x1u<<1)
#define	RCC_SR_LSIRDY							(0x1u<<0)

#define	RCC_SR_PLL4RDY_B_0X0					(0x0u<<11)
#define	RCC_SR_PLL4RDY_B_0X1					(0x1u<<11)
#define	RCC_SR_PLL3RDY_B_0X0					(0x0u<<10)
#define	RCC_SR_PLL3RDY_B_0X1					(0x1u<<10)
#define	RCC_SR_PLL2RDY_B_0X0					(0x0u<<9)
#define	RCC_SR_PLL2RDY_B_0X1					(0x1u<<9)
#define	RCC_SR_PLL1RDY_B_0X0					(0x0u<<8)
#define	RCC_SR_PLL1RDY_B_0X1					(0x1u<<8)
#define	RCC_SR_HSERDY_B_0X0						(0x0u<<4)
#define	RCC_SR_HSERDY_B_0X1						(0x1u<<4)
#define	RCC_SR_HSIRDY_B_0X0						(0x0u<<3)
#define	RCC_SR_HSIRDY_B_0X1						(0x1u<<3)
#define	RCC_SR_MSIRDY_B_0X0						(0x0u<<2)
#define	RCC_SR_MSIRDY_B_0X1						(0x1u<<2)
#define	RCC_SR_LSERDY_B_0X0						(0x0u<<1)
#define	RCC_SR_LSERDY_B_0X1						(0x1u<<1)
#define	RCC_SR_LSIRDY_B_0X0						(0x0u<<0)
#define	RCC_SR_LSIRDY_B_0X1						(0x1u<<0)

// STOPCR Configuration

#define	RCC_STOPCR_HSISTOPEN					(0x1u<<3)
#define	RCC_STOPCR_MSISTOPEN					(0x1u<<2)
#define	RCC_STOPCR_LSESTOPEN					(0x1u<<1)
#define	RCC_STOPCR_LSISTOPEN					(0x1u<<0)

#define	RCC_STOPCR_HSISTOPEN_B_0X0				(0x0u<<3)
#define	RCC_STOPCR_HSISTOPEN_B_0X1				(0x1u<<3)
#define	RCC_STOPCR_MSISTOPEN_B_0X0				(0x0u<<2)
#define	RCC_STOPCR_MSISTOPEN_B_0X1				(0x1u<<2)
#define	RCC_STOPCR_LSESTOPEN_B_0X0				(0x0u<<1)
#define	RCC_STOPCR_LSESTOPEN_B_0X1				(0x1u<<1)
#define	RCC_STOPCR_LSISTOPEN_B_0X0				(0x0u<<0)
#define	RCC_STOPCR_LSISTOPEN_B_0X1				(0x1u<<0)

// CFGR1 Configuration

#define	RCC_CFGR1_SYSSWS						(0x3u<<28)
#define	RCC_CFGR1_SYSSWS_0						(0x1u<<28)
#define	RCC_CFGR1_SYSSW							(0x3u<<24)
#define	RCC_CFGR1_SYSSW_0						(0x1u<<24)
#define	RCC_CFGR1_CPUSWS						(0x3u<<20)
#define	RCC_CFGR1_CPUSWS_0						(0x1u<<20)
#define	RCC_CFGR1_CPUSW							(0x3u<<16)
#define	RCC_CFGR1_CPUSW_0						(0x1u<<16)
#define	RCC_CFGR1_STOPWUCK						(0x1u<<0)

#define	RCC_CFGR1_SYSSWS_B_0X0					(0x0u<<28)
#define	RCC_CFGR1_SYSSWS_B_0X1					(0x1u<<28)
#define	RCC_CFGR1_SYSSWS_B_0X2					(0x2u<<28)
#define	RCC_CFGR1_SYSSWS_B_0X3					(0x3u<<28)
#define	RCC_CFGR1_SYSSW_B_0X0					(0x0u<<24)
#define	RCC_CFGR1_SYSSW_B_0X1					(0x1u<<24)
#define	RCC_CFGR1_SYSSW_B_0X2					(0x2u<<24)
#define	RCC_CFGR1_SYSSW_B_0X3					(0x3u<<24)
#define	RCC_CFGR1_CPUSWS_B_0X0					(0x0u<<20)
#define	RCC_CFGR1_CPUSWS_B_0X1					(0x1u<<20)
#define	RCC_CFGR1_CPUSWS_B_0X2					(0x2u<<20)
#define	RCC_CFGR1_CPUSWS_B_0X3					(0x3u<<20)
#define	RCC_CFGR1_CPUSW_B_0X0					(0x0u<<16)
#define	RCC_CFGR1_CPUSW_B_0X1					(0x1u<<16)
#define	RCC_CFGR1_CPUSW_B_0X2					(0x2u<<16)
#define	RCC_CFGR1_CPUSW_B_0X3					(0x3u<<16)
#define	RCC_CFGR1_STOPWUCK_B_0X0				(0x0u<<0)
#define	RCC_CFGR1_STOPWUCK_B_0X1				(0x1u<<0)

// CFGR2 Configuration

#define	RCC_CFGR2_TIMPRE						(0x3u<<24)
#define	RCC_CFGR2_TIMPRE_0						(0x1u<<24)
#define	RCC_CFGR2_HPRE							(0x7u<<20)
#define	RCC_CFGR2_HPRE_0						(0x1u<<20)
#define	RCC_CFGR2_PPRE5							(0x7u<<16)
#define	RCC_CFGR2_PPRE5_0						(0x1u<<16)
#define	RCC_CFGR2_PPRE4							(0x7u<<12)
#define	RCC_CFGR2_PPRE4_0						(0x1u<<12)
#define	RCC_CFGR2_PPRE2							(0x7u<<4)
#define	RCC_CFGR2_PPRE2_0						(0x1u<<4)
#define	RCC_CFGR2_PPRE1							(0x7u<<0)
#define	RCC_CFGR2_PPRE1_0						(0x1u<<0)

#define	RCC_CFGR2_TIMPRE_B_0X0					(0x0u<<24)
#define	RCC_CFGR2_TIMPRE_B_0X1					(0x1u<<24)
#define	RCC_CFGR2_TIMPRE_B_0X2					(0x2u<<24)
#define	RCC_CFGR2_HPRE_B_0X0					(0x0u<<20)
#define	RCC_CFGR2_HPRE_B_0X1					(0x1u<<20)
#define	RCC_CFGR2_HPRE_B_0X2					(0x2u<<20)
#define	RCC_CFGR2_HPRE_B_0X3					(0x3u<<20)
#define	RCC_CFGR2_HPRE_B_0X4					(0x4u<<20)
#define	RCC_CFGR2_HPRE_B_0X5					(0x5u<<20)
#define	RCC_CFGR2_HPRE_B_0X6					(0x6u<<20)
#define	RCC_CFGR2_HPRE_B_0X7					(0x7u<<20)
#define	RCC_CFGR2_PPRE5_B_0X0					(0x0u<<16)
#define	RCC_CFGR2_PPRE5_B_0X1					(0x1u<<16)
#define	RCC_CFGR2_PPRE5_B_0X2					(0x2u<<16)
#define	RCC_CFGR2_PPRE5_B_0X3					(0x3u<<16)
#define	RCC_CFGR2_PPRE5_B_0X4					(0x4u<<16)
#define	RCC_CFGR2_PPRE5_B_0X5					(0x5u<<16)
#define	RCC_CFGR2_PPRE5_B_0X6					(0x6u<<16)
#define	RCC_CFGR2_PPRE5_B_0X7					(0x7u<<16)
#define	RCC_CFGR2_PPRE4_B_0X0					(0x0u<<12)
#define	RCC_CFGR2_PPRE4_B_0X1					(0x1u<<12)
#define	RCC_CFGR2_PPRE4_B_0X2					(0x2u<<12)
#define	RCC_CFGR2_PPRE4_B_0X3					(0x3u<<12)
#define	RCC_CFGR2_PPRE4_B_0X4					(0x4u<<12)
#define	RCC_CFGR2_PPRE4_B_0X5					(0x5u<<12)
#define	RCC_CFGR2_PPRE4_B_0X6					(0x6u<<12)
#define	RCC_CFGR2_PPRE4_B_0X7					(0x7u<<12)
#define	RCC_CFGR2_PPRE2_B_0X0					(0x0u<<4)
#define	RCC_CFGR2_PPRE2_B_0X1					(0x1u<<4)
#define	RCC_CFGR2_PPRE2_B_0X2					(0x2u<<4)
#define	RCC_CFGR2_PPRE2_B_0X3					(0x3u<<4)
#define	RCC_CFGR2_PPRE2_B_0X4					(0x4u<<4)
#define	RCC_CFGR2_PPRE2_B_0X5					(0x5u<<4)
#define	RCC_CFGR2_PPRE2_B_0X6					(0x6u<<4)
#define	RCC_CFGR2_PPRE2_B_0X7					(0x7u<<4)
#define	RCC_CFGR2_PPRE1_B_0X0					(0x0u<<0)
#define	RCC_CFGR2_PPRE1_B_0X1					(0x1u<<0)
#define	RCC_CFGR2_PPRE1_B_0X2					(0x2u<<0)
#define	RCC_CFGR2_PPRE1_B_0X3					(0x3u<<0)
#define	RCC_CFGR2_PPRE1_B_0X4					(0x4u<<0)
#define	RCC_CFGR2_PPRE1_B_0X5					(0x5u<<0)
#define	RCC_CFGR2_PPRE1_B_0X6					(0x6u<<0)
#define	RCC_CFGR2_PPRE1_B_0X7					(0x7u<<0)

// CKPROTR Configuration

#define	RCC_CKPROTR_FMCSELS						(0x3u<<28)
#define	RCC_CKPROTR_FMCSELS_0					(0x1u<<28)
#define	RCC_CKPROTR_XSPI1SELS					(0x3u<<24)
#define	RCC_CKPROTR_XSPI1SELS_0					(0x1u<<24)
#define	RCC_CKPROTR_XSPI2SELS					(0x3u<<20)
#define	RCC_CKPROTR_XSPI2SELS_0					(0x1u<<20)
#define	RCC_CKPROTR_XSPI3SELS					(0x3u<<16)
#define	RCC_CKPROTR_XSPI3SELS_0					(0x1u<<16)

#define	RCC_CKPROTR_FMCSELS_B_0X0				(0x0u<<28)
#define	RCC_CKPROTR_FMCSELS_B_0X1				(0x1u<<28)
#define	RCC_CKPROTR_FMCSELS_B_0X2				(0x2u<<28)
#define	RCC_CKPROTR_FMCSELS_B_0X3				(0x3u<<28)
#define	RCC_CKPROTR_XSPI1SELS_B_0X0				(0x0u<<24)
#define	RCC_CKPROTR_XSPI1SELS_B_0X1				(0x1u<<24)
#define	RCC_CKPROTR_XSPI1SELS_B_0X2				(0x2u<<24)
#define	RCC_CKPROTR_XSPI1SELS_B_0X3				(0x3u<<24)
#define	RCC_CKPROTR_XSPI2SELS_B_0X0				(0x0u<<20)
#define	RCC_CKPROTR_XSPI2SELS_B_0X1				(0x1u<<20)
#define	RCC_CKPROTR_XSPI2SELS_B_0X2				(0x2u<<20)
#define	RCC_CKPROTR_XSPI2SELS_B_0X3				(0x3u<<20)
#define	RCC_CKPROTR_XSPI3SELS_B_0X0				(0x0u<<16)
#define	RCC_CKPROTR_XSPI3SELS_B_0X1				(0x1u<<16)
#define	RCC_CKPROTR_XSPI3SELS_B_0X2				(0x2u<<16)
#define	RCC_CKPROTR_XSPI3SELS_B_0X3				(0x3u<<16)

// BDCR Configuration

#define	RCC_BDCR_VSWRST							(0x1u<<31)

#define	RCC_BDCR_VSWRST_B_0X0					(0x0u<<31)
#define	RCC_BDCR_VSWRST_B_0X1					(0x1u<<31)

// HWRSR Configuration

#define	RCC_HWRSR_LPWRRSTF						(0x1u<<30)
#define	RCC_HWRSR_WWDGRSTF						(0x1u<<28)
#define	RCC_HWRSR_IWDGRSTF						(0x1u<<26)
#define	RCC_HWRSR_SFTRSTF						(0x1u<<24)
#define	RCC_HWRSR_PORRSTF						(0x1u<<23)
#define	RCC_HWRSR_PINRSTF						(0x1u<<22)
#define	RCC_HWRSR_BORRSTF						(0x1u<<21)
#define	RCC_HWRSR_LCKRSTF						(0x1u<<17)
#define	RCC_HWRSR_RMVF							(0x1u<<16)

#define	RCC_HWRSR_LPWRRSTF_B_0X0				(0x0u<<30)
#define	RCC_HWRSR_LPWRRSTF_B_0X1				(0x1u<<30)
#define	RCC_HWRSR_WWDGRSTF_B_0X0				(0x0u<<28)
#define	RCC_HWRSR_WWDGRSTF_B_0X1				(0x1u<<28)
#define	RCC_HWRSR_IWDGRSTF_B_0X0				(0x0u<<26)
#define	RCC_HWRSR_IWDGRSTF_B_0X1				(0x1u<<26)
#define	RCC_HWRSR_SFTRSTF_B_0X0					(0x0u<<24)
#define	RCC_HWRSR_SFTRSTF_B_0X1					(0x1u<<24)
#define	RCC_HWRSR_PORRSTF_B_0X0					(0x0u<<23)
#define	RCC_HWRSR_PORRSTF_B_0X1					(0x1u<<23)
#define	RCC_HWRSR_PINRSTF_B_0X0					(0x0u<<22)
#define	RCC_HWRSR_PINRSTF_B_0X1					(0x1u<<22)
#define	RCC_HWRSR_BORRSTF_B_0X0					(0x0u<<21)
#define	RCC_HWRSR_BORRSTF_B_0X1					(0x1u<<21)
#define	RCC_HWRSR_LCKRSTF_B_0X0					(0x0u<<17)
#define	RCC_HWRSR_LCKRSTF_B_0X1					(0x1u<<17)
#define	RCC_HWRSR_RMVF_B_0X0					(0x0u<<16)
#define	RCC_HWRSR_RMVF_B_0X1					(0x1u<<16)

// RSR Configuration

#define	RCC_RSR_LPWRRSTF						(0x1u<<30)
#define	RCC_RSR_WWDGRSTF						(0x1u<<28)
#define	RCC_RSR_IWDGRSTF						(0x1u<<26)
#define	RCC_RSR_SFTRSTF							(0x1u<<24)
#define	RCC_RSR_PORRSTF							(0x1u<<23)
#define	RCC_RSR_PINRSTF							(0x1u<<22)
#define	RCC_RSR_BORRSTF							(0x1u<<21)
#define	RCC_RSR_LCKRSTF							(0x1u<<17)
#define	RCC_RSR_RMVF							(0x1u<<16)

#define	RCC_RSR_LPWRRSTF_B_0X0					(0x0u<<30)
#define	RCC_RSR_LPWRRSTF_B_0X1					(0x1u<<30)
#define	RCC_RSR_WWDGRSTF_B_0X0					(0x0u<<28)
#define	RCC_RSR_WWDGRSTF_B_0X1					(0x1u<<28)
#define	RCC_RSR_IWDGRSTF_B_0X0					(0x0u<<26)
#define	RCC_RSR_IWDGRSTF_B_0X1					(0x1u<<26)
#define	RCC_RSR_SFTRSTF_B_0X0					(0x0u<<24)
#define	RCC_RSR_SFTRSTF_B_0X1					(0x1u<<24)
#define	RCC_RSR_PORRSTF_B_0X0					(0x0u<<23)
#define	RCC_RSR_PORRSTF_B_0X1					(0x1u<<23)
#define	RCC_RSR_PINRSTF_B_0X0					(0x0u<<22)
#define	RCC_RSR_PINRSTF_B_0X1					(0x1u<<22)
#define	RCC_RSR_BORRSTF_B_0X0					(0x0u<<21)
#define	RCC_RSR_BORRSTF_B_0X1					(0x1u<<21)
#define	RCC_RSR_LCKRSTF_B_0X0					(0x0u<<17)
#define	RCC_RSR_LCKRSTF_B_0X1					(0x1u<<17)
#define	RCC_RSR_RMVF_B_0X0						(0x0u<<16)
#define	RCC_RSR_RMVF_B_0X1						(0x1u<<16)

// LSECFGR Configuration

#define	RCC_LSECFGR_LSEDRV						(0x3u<<18)
#define	RCC_LSECFGR_LSEDRV_0					(0x1u<<18)
#define	RCC_LSECFGR_LSEGFON						(0x1u<<17)
#define	RCC_LSECFGR_LSEEXT						(0x1u<<16)
#define	RCC_LSECFGR_LSEBYP						(0x1u<<15)
#define	RCC_LSECFGR_LSECSSD						(0x1u<<9)
#define	RCC_LSECFGR_LSECSSRA					(0x1u<<8)
#define	RCC_LSECFGR_LSECSSON					(0x1u<<7)

#define	RCC_LSECFGR_LSEDRV_B_0X0				(0x0u<<18)
#define	RCC_LSECFGR_LSEDRV_B_0X1				(0x1u<<18)
#define	RCC_LSECFGR_LSEDRV_B_0X2				(0x2u<<18)
#define	RCC_LSECFGR_LSEDRV_B_0X3				(0x3u<<18)
#define	RCC_LSECFGR_LSEGFON_B_0X0				(0x0u<<17)
#define	RCC_LSECFGR_LSEGFON_B_0X1				(0x1u<<17)
#define	RCC_LSECFGR_LSEEXT_B_0X0				(0x0u<<16)
#define	RCC_LSECFGR_LSEEXT_B_0X1				(0x1u<<16)
#define	RCC_LSECFGR_LSEBYP_B_0X0				(0x0u<<15)
#define	RCC_LSECFGR_LSEBYP_B_0X1				(0x1u<<15)
#define	RCC_LSECFGR_LSECSSD_B_0X0				(0x0u<<9)
#define	RCC_LSECFGR_LSECSSD_B_0X1				(0x1u<<9)
#define	RCC_LSECFGR_LSECSSRA_B_0X0				(0x0u<<8)
#define	RCC_LSECFGR_LSECSSRA_B_0X1				(0x1u<<8)
#define	RCC_LSECFGR_LSECSSON_B_0X0				(0x0u<<7)
#define	RCC_LSECFGR_LSECSSON_B_0X1				(0x1u<<7)

// MSICFGR Configuration

#define	RCC_MSICFGR_MSICAL						(0xFFu<<23)
#define	RCC_MSICFGR_MSICAL_0					(0x1u<<23)
#define	RCC_MSICFGR_MSITRIM						(0x1Fu<<16)
#define	RCC_MSICFGR_MSITRIM_0					(0x1u<<16)
#define	RCC_MSICFGR_MSIFREQSEL					(0x1u<<9)

#define	RCC_MSICFGR_MSIFREQSEL_B_0X0			(0x0u<<9)
#define	RCC_MSICFGR_MSIFREQSEL_B_0X1			(0x1u<<9)

// HSICFGR Configuration

#define	RCC_HSICFGR_HSICAL						(0x1FFu<<23)
#define	RCC_HSICFGR_HSICAL_0					(0x1u<<23)
#define	RCC_HSICFGR_HSITRIM						(0x7Fu<<16)
#define	RCC_HSICFGR_HSITRIM_0					(0x1u<<16)
#define	RCC_HSICFGR_HSIDIV						(0x3u<<7)
#define	RCC_HSICFGR_HSIDIV_0					(0x1u<<7)

#define	RCC_HSICFGR_HSITRIM_B_0X40				(0x40u<<16)
#define	RCC_HSICFGR_HSITRIM_B_0X41				(0x41u<<16)
#define	RCC_HSICFGR_HSITRIM_B_0X0				(0x0u<<16)
#define	RCC_HSICFGR_HSITRIM_B_0X3E				(0x3Eu<<16)
#define	RCC_HSICFGR_HSITRIM_B_0X3F				(0x3Fu<<16)
#define	RCC_HSICFGR_HSIDIV_B_0X0				(0x0u<<7)
#define	RCC_HSICFGR_HSIDIV_B_0X1				(0x1u<<7)

// HSIMCR Configuration

#define	RCC_HSIMCR_HSIMONEN						(0x1u<<31)
#define	RCC_HSIMCR_HSIDEV						(0x3Fu<<16)
#define	RCC_HSIMCR_HSIDEV_0						(0x1u<<16)
#define	RCC_HSIMCR_HSIREF						(0x7FFu<<0)
#define	RCC_HSIMCR_HSIREF_0						(0x1u<<0)

#define	RCC_HSIMCR_HSIMONEN_B_0X0				(0x0u<<31)
#define	RCC_HSIMCR_HSIMONEN_B_0X1				(0x1u<<31)

// HSIMSR Configuration

#define	RCC_HSIMSR_HSIVAL						(0x7FFu<<0)
#define	RCC_HSIMSR_HSIVAL_0						(0x1u<<0)

// HSECFGR Configuration

#define	RCC_HSECFGR_HSEDRV						(0x3u<<18)
#define	RCC_HSECFGR_HSEDRV_0					(0x1u<<18)
#define	RCC_HSECFGR_HSEGFON						(0x1u<<17)
#define	RCC_HSECFGR_HSEEXT						(0x1u<<16)
#define	RCC_HSECFGR_HSEBYP						(0x1u<<15)
#define	RCC_HSECFGR_HSECSSBPRE					(0xFu<<11)
#define	RCC_HSECFGR_HSECSSBPRE_0				(0x1u<<11)
#define	RCC_HSECFGR_HSECSSBYP					(0x1u<<10)
#define	RCC_HSECFGR_HSECSSD						(0x1u<<9)
#define	RCC_HSECFGR_HSECSSRA					(0x1u<<8)
#define	RCC_HSECFGR_HSECSSON					(0x1u<<7)
#define	RCC_HSECFGR_HSEDIV2BYP					(0x1u<<6)

#define	RCC_HSECFGR_HSEDRV_B_0X0				(0x0u<<18)
#define	RCC_HSECFGR_HSEDRV_B_0X1				(0x1u<<18)
#define	RCC_HSECFGR_HSEDRV_B_0X2				(0x2u<<18)
#define	RCC_HSECFGR_HSEDRV_B_0X3				(0x3u<<18)
#define	RCC_HSECFGR_HSEGFON_B_0X0				(0x0u<<17)
#define	RCC_HSECFGR_HSEGFON_B_0X1				(0x1u<<17)
#define	RCC_HSECFGR_HSEEXT_B_0X0				(0x0u<<16)
#define	RCC_HSECFGR_HSEEXT_B_0X1				(0x1u<<16)
#define	RCC_HSECFGR_HSEBYP_B_0X0				(0x0u<<15)
#define	RCC_HSECFGR_HSEBYP_B_0X1				(0x1u<<15)
#define	RCC_HSECFGR_HSECSSBPRE_B_0X0			(0x0u<<11)
#define	RCC_HSECFGR_HSECSSBPRE_B_0X1			(0x1u<<11)
#define	RCC_HSECFGR_HSECSSBPRE_B_0X2			(0x2u<<11)
#define	RCC_HSECFGR_HSECSSBPRE_B_0X3			(0x3u<<11)
#define	RCC_HSECFGR_HSECSSBPRE_B_0XF			(0xFu<<11)
#define	RCC_HSECFGR_HSECSSBYP_B_0X0				(0x0u<<10)
#define	RCC_HSECFGR_HSECSSBYP_B_0X1				(0x1u<<10)
#define	RCC_HSECFGR_HSECSSD_B_0X0				(0x0u<<9)
#define	RCC_HSECFGR_HSECSSD_B_0X1				(0x1u<<9)
#define	RCC_HSECFGR_HSECSSRA_B_0X0				(0x0u<<8)
#define	RCC_HSECFGR_HSECSSRA_B_0X1				(0x1u<<8)
#define	RCC_HSECFGR_HSECSSON_B_0X0				(0x0u<<7)
#define	RCC_HSECFGR_HSECSSON_B_0X1				(0x1u<<7)
#define	RCC_HSECFGR_HSEDIV2BYP_B_0X0			(0x0u<<6)
#define	RCC_HSECFGR_HSEDIV2BYP_B_0X1			(0x1u<<6)

// PLL1CFGR1 Configuration

#define	RCC_PLL1CFGR1_PLL1SEL					(0x7u<<28)
#define	RCC_PLL1CFGR1_PLL1SEL_0					(0x1u<<28)
#define	RCC_PLL1CFGR1_PLL1BYP					(0x1u<<27)
#define	RCC_PLL1CFGR1_PLL1DIVM					(0x3Fu<<20)
#define	RCC_PLL1CFGR1_PLL1DIVM_0				(0x1u<<20)
#define	RCC_PLL1CFGR1_PLL1DIVN					(0xFFFu<<8)
#define	RCC_PLL1CFGR1_PLL1DIVN_0				(0x1u<<8)

#define	RCC_PLL1CFGR1_PLL1SEL_B_0X0				(0x0u<<28)
#define	RCC_PLL1CFGR1_PLL1SEL_B_0X1				(0x1u<<28)
#define	RCC_PLL1CFGR1_PLL1SEL_B_0X2				(0x2u<<28)
#define	RCC_PLL1CFGR1_PLL1SEL_B_0X3				(0x3u<<28)
#define	RCC_PLL1CFGR1_PLL1BYP_B_0X0				(0x0u<<27)
#define	RCC_PLL1CFGR1_PLL1BYP_B_0X1				(0x1u<<27)
#define	RCC_PLL1CFGR1_PLL1DIVM_B_0X0			(0x0u<<20)
#define	RCC_PLL1CFGR1_PLL1DIVM_B_0X1			(0x1u<<20)
#define	RCC_PLL1CFGR1_PLL1DIVM_B_0X2			(0x2u<<20)
#define	RCC_PLL1CFGR1_PLL1DIVM_B_0X3F			(0x3Fu<<20)

// PLL1CFGR2 Configuration

#define	RCC_PLL1CFGR2_PLL1DIVNFRAC				(0xFFFFFFu<<0)
#define	RCC_PLL1CFGR2_PLL1DIVNFRAC_0			(0x1u<<0)

// PLL1CFGR3 Configuration

#define	RCC_PLL1CFGR3_PLL1PDIVEN				(0x1u<<30)
#define	RCC_PLL1CFGR3_PLL1PDIV1					(0x7u<<27)
#define	RCC_PLL1CFGR3_PLL1PDIV1_0				(0x1u<<27)
#define	RCC_PLL1CFGR3_PLL1PDIV2					(0x7u<<24)
#define	RCC_PLL1CFGR3_PLL1PDIV2_0				(0x1u<<24)
#define	RCC_PLL1CFGR3_PLL1MODSPR				(0x1Fu<<16)
#define	RCC_PLL1CFGR3_PLL1MODSPR_0				(0x1u<<16)
#define	RCC_PLL1CFGR3_PLL1MODDIV				(0xFu<<8)
#define	RCC_PLL1CFGR3_PLL1MODDIV_0				(0x1u<<8)
#define	RCC_PLL1CFGR3_PLL1MODSPRDW				(0x1u<<4)
#define	RCC_PLL1CFGR3_PLL1MODDSEN				(0x1u<<3)
#define	RCC_PLL1CFGR3_PLL1MODSSDIS				(0x1u<<2)
#define	RCC_PLL1CFGR3_PLL1DACEN					(0x1u<<1)
#define	RCC_PLL1CFGR3_PLL1MODSSRST				(0x1u<<0)

#define	RCC_PLL1CFGR3_PLL1PDIVEN_B_0X0			(0x0u<<30)
#define	RCC_PLL1CFGR3_PLL1PDIVEN_B_0X1			(0x1u<<30)
#define	RCC_PLL1CFGR3_PLL1PDIV1_B_0X0			(0x0u<<27)
#define	RCC_PLL1CFGR3_PLL1PDIV1_B_0X1			(0x1u<<27)
#define	RCC_PLL1CFGR3_PLL1PDIV1_B_0X7			(0x7u<<27)
#define	RCC_PLL1CFGR3_PLL1PDIV2_B_0X0			(0x0u<<24)
#define	RCC_PLL1CFGR3_PLL1PDIV2_B_0X1			(0x1u<<24)
#define	RCC_PLL1CFGR3_PLL1PDIV2_B_0X7			(0x7u<<24)
#define	RCC_PLL1CFGR3_PLL1MODSPRDW_B_0X0		(0x0u<<4)
#define	RCC_PLL1CFGR3_PLL1MODSPRDW_B_0X1		(0x1u<<4)
#define	RCC_PLL1CFGR3_PLL1MODDSEN_B_0X0			(0x0u<<3)
#define	RCC_PLL1CFGR3_PLL1MODDSEN_B_0X1			(0x1u<<3)
#define	RCC_PLL1CFGR3_PLL1MODSSDIS_B_0X0		(0x0u<<2)
#define	RCC_PLL1CFGR3_PLL1MODSSDIS_B_0X1		(0x1u<<2)
#define	RCC_PLL1CFGR3_PLL1DACEN_B_0X0			(0x0u<<1)
#define	RCC_PLL1CFGR3_PLL1DACEN_B_0X1			(0x1u<<1)
#define	RCC_PLL1CFGR3_PLL1MODSSRST_B_0X0		(0x0u<<0)
#define	RCC_PLL1CFGR3_PLL1MODSSRST_B_0X1		(0x1u<<0)

// PLL2CFGR1 Configuration

#define	RCC_PLL2CFGR1_PLL2SEL					(0x7u<<28)
#define	RCC_PLL2CFGR1_PLL2SEL_0					(0x1u<<28)
#define	RCC_PLL2CFGR1_PLL2BYP					(0x1u<<27)
#define	RCC_PLL2CFGR1_PLL2DIVM					(0x3Fu<<20)
#define	RCC_PLL2CFGR1_PLL2DIVM_0				(0x1u<<20)
#define	RCC_PLL2CFGR1_PLL2DIVN					(0xFFFu<<8)
#define	RCC_PLL2CFGR1_PLL2DIVN_0				(0x1u<<8)

#define	RCC_PLL2CFGR1_PLL2SEL_B_0X0				(0x0u<<28)
#define	RCC_PLL2CFGR1_PLL2SEL_B_0X1				(0x1u<<28)
#define	RCC_PLL2CFGR1_PLL2SEL_B_0X2				(0x2u<<28)
#define	RCC_PLL2CFGR1_PLL2SEL_B_0X3				(0x3u<<28)
#define	RCC_PLL2CFGR1_PLL2BYP_B_0X0				(0x0u<<27)
#define	RCC_PLL2CFGR1_PLL2BYP_B_0X1				(0x1u<<27)
#define	RCC_PLL2CFGR1_PLL2DIVM_B_0X0			(0x0u<<20)
#define	RCC_PLL2CFGR1_PLL2DIVM_B_0X1			(0x1u<<20)
#define	RCC_PLL2CFGR1_PLL2DIVM_B_0X2			(0x2u<<20)
#define	RCC_PLL2CFGR1_PLL2DIVM_B_0X3F			(0x3Fu<<20)

// PLL2CFGR2 Configuration

#define	RCC_PLL2CFGR2_PLL2DIVNFRAC				(0xFFFFFFu<<0)
#define	RCC_PLL2CFGR2_PLL2DIVNFRAC_0			(0x1u<<0)

// PLL2CFGR3 Configuration

#define	RCC_PLL2CFGR3_PLL2PDIVEN				(0x1u<<30)
#define	RCC_PLL2CFGR3_PLL2PDIV1					(0x7u<<27)
#define	RCC_PLL2CFGR3_PLL2PDIV1_0				(0x1u<<27)
#define	RCC_PLL2CFGR3_PLL2PDIV2					(0x7u<<24)
#define	RCC_PLL2CFGR3_PLL2PDIV2_0				(0x1u<<24)
#define	RCC_PLL2CFGR3_PLL2MODSPR				(0x1Fu<<16)
#define	RCC_PLL2CFGR3_PLL2MODSPR_0				(0x1u<<16)
#define	RCC_PLL2CFGR3_PLL2MODDIV				(0xFu<<8)
#define	RCC_PLL2CFGR3_PLL2MODDIV_0				(0x1u<<8)
#define	RCC_PLL2CFGR3_PLL2MODSPRDW				(0x1u<<4)
#define	RCC_PLL2CFGR3_PLL2MODDSEN				(0x1u<<3)
#define	RCC_PLL2CFGR3_PLL2MODSSDIS				(0x1u<<2)
#define	RCC_PLL2CFGR3_PLL2DACEN					(0x1u<<1)
#define	RCC_PLL2CFGR3_PLL2MODSSRST				(0x1u<<0)

#define	RCC_PLL2CFGR3_PLL2PDIVEN_B_0X0			(0x0u<<30)
#define	RCC_PLL2CFGR3_PLL2PDIVEN_B_0X1			(0x1u<<30)
#define	RCC_PLL2CFGR3_PLL2PDIV1_B_0X0			(0x0u<<27)
#define	RCC_PLL2CFGR3_PLL2PDIV1_B_0X1			(0x1u<<27)
#define	RCC_PLL2CFGR3_PLL2PDIV1_B_0X7			(0x7u<<27)
#define	RCC_PLL2CFGR3_PLL2PDIV2_B_0X0			(0x0u<<24)
#define	RCC_PLL2CFGR3_PLL2PDIV2_B_0X1			(0x1u<<24)
#define	RCC_PLL2CFGR3_PLL2PDIV2_B_0X7			(0x7u<<24)
#define	RCC_PLL2CFGR3_PLL2MODSPRDW_B_0X0		(0x0u<<4)
#define	RCC_PLL2CFGR3_PLL2MODSPRDW_B_0X1		(0x1u<<4)
#define	RCC_PLL2CFGR3_PLL2MODDSEN_B_0X0			(0x0u<<3)
#define	RCC_PLL2CFGR3_PLL2MODDSEN_B_0X1			(0x1u<<3)
#define	RCC_PLL2CFGR3_PLL2MODSSDIS_B_0X0		(0x0u<<2)
#define	RCC_PLL2CFGR3_PLL2MODSSDIS_B_0X1		(0x1u<<2)
#define	RCC_PLL2CFGR3_PLL2DACEN_B_0X0			(0x0u<<1)
#define	RCC_PLL2CFGR3_PLL2DACEN_B_0X1			(0x1u<<1)
#define	RCC_PLL2CFGR3_PLL2MODSSRST_B_0X0		(0x0u<<0)
#define	RCC_PLL2CFGR3_PLL2MODSSRST_B_0X1		(0x1u<<0)

// PLL3CFGR1 Configuration

#define	RCC_PLL3CFGR1_PLL3SEL					(0x7u<<28)
#define	RCC_PLL3CFGR1_PLL3SEL_0					(0x1u<<28)
#define	RCC_PLL3CFGR1_PLL3BYP					(0x1u<<27)
#define	RCC_PLL3CFGR1_PLL3DIVM					(0x3Fu<<20)
#define	RCC_PLL3CFGR1_PLL3DIVM_0				(0x1u<<20)
#define	RCC_PLL3CFGR1_PLL3DIVN					(0xFFFu<<8)
#define	RCC_PLL3CFGR1_PLL3DIVN_0				(0x1u<<8)

#define	RCC_PLL3CFGR1_PLL3SEL_B_0X0				(0x0u<<28)
#define	RCC_PLL3CFGR1_PLL3SEL_B_0X1				(0x1u<<28)
#define	RCC_PLL3CFGR1_PLL3SEL_B_0X2				(0x2u<<28)
#define	RCC_PLL3CFGR1_PLL3SEL_B_0X3				(0x3u<<28)
#define	RCC_PLL3CFGR1_PLL3BYP_B_0X0				(0x0u<<27)
#define	RCC_PLL3CFGR1_PLL3BYP_B_0X1				(0x1u<<27)
#define	RCC_PLL3CFGR1_PLL3DIVM_B_0X0			(0x0u<<20)
#define	RCC_PLL3CFGR1_PLL3DIVM_B_0X1			(0x1u<<20)
#define	RCC_PLL3CFGR1_PLL3DIVM_B_0X2			(0x2u<<20)
#define	RCC_PLL3CFGR1_PLL3DIVM_B_0X3F			(0x3Fu<<20)

// PLL3CFGR2 Configuration

#define	RCC_PLL3CFGR2_PLL3DIVNFRAC				(0xFFFFFFu<<0)
#define	RCC_PLL3CFGR2_PLL3DIVNFRAC_0			(0x1u<<0)

// PLL3CFGR3 Configuration

#define	RCC_PLL3CFGR3_PLL3PDIVEN				(0x1u<<30)
#define	RCC_PLL3CFGR3_PLL3PDIV1					(0x7u<<27)
#define	RCC_PLL3CFGR3_PLL3PDIV1_0				(0x1u<<27)
#define	RCC_PLL3CFGR3_PLL3PDIV2					(0x7u<<24)
#define	RCC_PLL3CFGR3_PLL3PDIV2_0				(0x1u<<24)
#define	RCC_PLL3CFGR3_PLL3MODSPR				(0x1Fu<<16)
#define	RCC_PLL3CFGR3_PLL3MODSPR_0				(0x1u<<16)
#define	RCC_PLL3CFGR3_PLL3MODDIV				(0xFu<<8)
#define	RCC_PLL3CFGR3_PLL3MODDIV_0				(0x1u<<8)
#define	RCC_PLL3CFGR3_PLL3MODSPRDW				(0x1u<<4)
#define	RCC_PLL3CFGR3_PLL3MODDSEN				(0x1u<<3)
#define	RCC_PLL3CFGR3_PLL3MODSSDIS				(0x1u<<2)
#define	RCC_PLL3CFGR3_PLL3DACEN					(0x1u<<1)
#define	RCC_PLL3CFGR3_PLL3MODSSRST				(0x1u<<0)

#define	RCC_PLL3CFGR3_PLL3PDIVEN_B_0X0			(0x0u<<30)
#define	RCC_PLL3CFGR3_PLL3PDIVEN_B_0X1			(0x1u<<30)
#define	RCC_PLL3CFGR3_PLL3PDIV1_B_0X0			(0x0u<<27)
#define	RCC_PLL3CFGR3_PLL3PDIV1_B_0X1			(0x1u<<27)
#define	RCC_PLL3CFGR3_PLL3PDIV1_B_0X7			(0x7u<<27)
#define	RCC_PLL3CFGR3_PLL3PDIV2_B_0X0			(0x0u<<24)
#define	RCC_PLL3CFGR3_PLL3PDIV2_B_0X1			(0x1u<<24)
#define	RCC_PLL3CFGR3_PLL3PDIV2_B_0X7			(0x7u<<24)
#define	RCC_PLL3CFGR3_PLL3MODSPRDW_B_0X0		(0x0u<<4)
#define	RCC_PLL3CFGR3_PLL3MODSPRDW_B_0X1		(0x1u<<4)
#define	RCC_PLL3CFGR3_PLL3MODDSEN_B_0X0			(0x0u<<3)
#define	RCC_PLL3CFGR3_PLL3MODDSEN_B_0X1			(0x1u<<3)
#define	RCC_PLL3CFGR3_PLL3MODSSDIS_B_0X0		(0x0u<<2)
#define	RCC_PLL3CFGR3_PLL3MODSSDIS_B_0X1		(0x1u<<2)
#define	RCC_PLL3CFGR3_PLL3DACEN_B_0X0			(0x0u<<1)
#define	RCC_PLL3CFGR3_PLL3DACEN_B_0X1			(0x1u<<1)
#define	RCC_PLL3CFGR3_PLL3MODSSRST_B_0X0		(0x0u<<0)
#define	RCC_PLL3CFGR3_PLL3MODSSRST_B_0X1		(0x1u<<0)

// PLL4CFGR1 Configuration

#define	RCC_PLL4CFGR1_PLL4SEL					(0x7u<<28)
#define	RCC_PLL4CFGR1_PLL4SEL_0					(0x1u<<28)
#define	RCC_PLL4CFGR1_PLL4BYP					(0x1u<<27)
#define	RCC_PLL4CFGR1_PLL4DIVM					(0x3Fu<<20)
#define	RCC_PLL4CFGR1_PLL4DIVM_0				(0x1u<<20)
#define	RCC_PLL4CFGR1_PLL4DIVN					(0xFFFu<<8)
#define	RCC_PLL4CFGR1_PLL4DIVN_0				(0x1u<<8)

#define	RCC_PLL4CFGR1_PLL4SEL_B_0X0				(0x0u<<28)
#define	RCC_PLL4CFGR1_PLL4SEL_B_0X1				(0x1u<<28)
#define	RCC_PLL4CFGR1_PLL4SEL_B_0X2				(0x2u<<28)
#define	RCC_PLL4CFGR1_PLL4SEL_B_0X3				(0x3u<<28)
#define	RCC_PLL4CFGR1_PLL4BYP_B_0X0				(0x0u<<27)
#define	RCC_PLL4CFGR1_PLL4BYP_B_0X1				(0x1u<<27)
#define	RCC_PLL4CFGR1_PLL4DIVM_B_0X0			(0x0u<<20)
#define	RCC_PLL4CFGR1_PLL4DIVM_B_0X1			(0x1u<<20)
#define	RCC_PLL4CFGR1_PLL4DIVM_B_0X2			(0x2u<<20)
#define	RCC_PLL4CFGR1_PLL4DIVM_B_0X3F			(0x3Fu<<20)

// PLL4CFGR2 Configuration

#define	RCC_PLL4CFGR2_PLL4DIVNFRAC				(0xFFFFFFu<<0)
#define	RCC_PLL4CFGR2_PLL4DIVNFRAC_0			(0x1u<<0)

// PLL4CFGR3 Configuration

#define	RCC_PLL4CFGR3_PLL4PDIVEN				(0x1u<<30)
#define	RCC_PLL4CFGR3_PLL4PDIV1					(0x7u<<27)
#define	RCC_PLL4CFGR3_PLL4PDIV1_0				(0x1u<<27)
#define	RCC_PLL4CFGR3_PLL4PDIV2					(0x7u<<24)
#define	RCC_PLL4CFGR3_PLL4PDIV2_0				(0x1u<<24)
#define	RCC_PLL4CFGR3_PLL4MODSPR				(0x1Fu<<16)
#define	RCC_PLL4CFGR3_PLL4MODSPR_0				(0x1u<<16)
#define	RCC_PLL4CFGR3_PLL4MODDIV				(0xFu<<8)
#define	RCC_PLL4CFGR3_PLL4MODDIV_0				(0x1u<<8)
#define	RCC_PLL4CFGR3_PLL4MODSPRDW				(0x1u<<4)
#define	RCC_PLL4CFGR3_PLL4MODDSEN				(0x1u<<3)
#define	RCC_PLL4CFGR3_PLL4MODSSDIS				(0x1u<<2)
#define	RCC_PLL4CFGR3_PLL4DACEN					(0x1u<<1)
#define	RCC_PLL4CFGR3_PLL4MODSSRST				(0x1u<<0)

#define	RCC_PLL4CFGR3_PLL4PDIVEN_B_0X0			(0x0u<<30)
#define	RCC_PLL4CFGR3_PLL4PDIVEN_B_0X1			(0x1u<<30)
#define	RCC_PLL4CFGR3_PLL4PDIV1_B_0X0			(0x0u<<27)
#define	RCC_PLL4CFGR3_PLL4PDIV1_B_0X1			(0x1u<<27)
#define	RCC_PLL4CFGR3_PLL4PDIV1_B_0X7			(0x7u<<27)
#define	RCC_PLL4CFGR3_PLL4PDIV2_B_0X0			(0x0u<<24)
#define	RCC_PLL4CFGR3_PLL4PDIV2_B_0X1			(0x1u<<24)
#define	RCC_PLL4CFGR3_PLL4PDIV2_B_0X7			(0x7u<<24)
#define	RCC_PLL4CFGR3_PLL4MODSPRDW_B_0X0		(0x0u<<4)
#define	RCC_PLL4CFGR3_PLL4MODSPRDW_B_0X1		(0x1u<<4)
#define	RCC_PLL4CFGR3_PLL4MODDSEN_B_0X0			(0x0u<<3)
#define	RCC_PLL4CFGR3_PLL4MODDSEN_B_0X1			(0x1u<<3)
#define	RCC_PLL4CFGR3_PLL4MODSSDIS_B_0X0		(0x0u<<2)
#define	RCC_PLL4CFGR3_PLL4MODSSDIS_B_0X1		(0x1u<<2)
#define	RCC_PLL4CFGR3_PLL4DACEN_B_0X0			(0x0u<<1)
#define	RCC_PLL4CFGR3_PLL4DACEN_B_0X1			(0x1u<<1)
#define	RCC_PLL4CFGR3_PLL4MODSSRST_B_0X0		(0x0u<<0)
#define	RCC_PLL4CFGR3_PLL4MODSSRST_B_0X1		(0x1u<<0)

// IC1CFGR Configuration

#define	RCC_IC1CFGR_IC1SEL						(0x3u<<28)
#define	RCC_IC1CFGR_IC1SEL_0					(0x1u<<28)
#define	RCC_IC1CFGR_IC1INT						(0xFFu<<16)
#define	RCC_IC1CFGR_IC1INT_0					(0x1u<<16)

#define	RCC_IC1CFGR_IC1SEL_B_0X0				(0x0u<<28)
#define	RCC_IC1CFGR_IC1SEL_B_0X1				(0x1u<<28)
#define	RCC_IC1CFGR_IC1SEL_B_0X2				(0x2u<<28)
#define	RCC_IC1CFGR_IC1SEL_B_0X3				(0x3u<<28)
#define	RCC_IC1CFGR_IC1INT_B_0X0				(0x0u<<16)
#define	RCC_IC1CFGR_IC1INT_B_0X1				(0x1u<<16)
#define	RCC_IC1CFGR_IC1INT_B_0X2				(0x2u<<16)
#define	RCC_IC1CFGR_IC1INT_B_0X3				(0x3u<<16)
#define	RCC_IC1CFGR_IC1INT_B_0XFF				(0xFFu<<16)

// IC2CFGR Configuration

#define	RCC_IC2CFGR_IC2SEL						(0x3u<<28)
#define	RCC_IC2CFGR_IC2SEL_0					(0x1u<<28)
#define	RCC_IC2CFGR_IC2INT						(0xFFu<<16)
#define	RCC_IC2CFGR_IC2INT_0					(0x1u<<16)

#define	RCC_IC2CFGR_IC2SEL_B_0X0				(0x0u<<28)
#define	RCC_IC2CFGR_IC2SEL_B_0X1				(0x1u<<28)
#define	RCC_IC2CFGR_IC2SEL_B_0X2				(0x2u<<28)
#define	RCC_IC2CFGR_IC2SEL_B_0X3				(0x3u<<28)
#define	RCC_IC2CFGR_IC2INT_B_0X0				(0x0u<<16)
#define	RCC_IC2CFGR_IC2INT_B_0X1				(0x1u<<16)
#define	RCC_IC2CFGR_IC2INT_B_0X2				(0x2u<<16)
#define	RCC_IC2CFGR_IC2INT_B_0X3				(0x3u<<16)
#define	RCC_IC2CFGR_IC2INT_B_0XFF				(0xFFu<<16)

// IC3CFGR Configuration

#define	RCC_IC3CFGR_IC3SEL						(0x3u<<28)
#define	RCC_IC3CFGR_IC3SEL_0					(0x1u<<28)
#define	RCC_IC3CFGR_IC3INT						(0xFFu<<16)
#define	RCC_IC3CFGR_IC3INT_0					(0x1u<<16)

#define	RCC_IC3CFGR_IC3SEL_B_0X0				(0x0u<<28)
#define	RCC_IC3CFGR_IC3SEL_B_0X1				(0x1u<<28)
#define	RCC_IC3CFGR_IC3SEL_B_0X2				(0x2u<<28)
#define	RCC_IC3CFGR_IC3SEL_B_0X3				(0x3u<<28)
#define	RCC_IC3CFGR_IC3INT_B_0X0				(0x0u<<16)
#define	RCC_IC3CFGR_IC3INT_B_0X1				(0x1u<<16)
#define	RCC_IC3CFGR_IC3INT_B_0X2				(0x2u<<16)
#define	RCC_IC3CFGR_IC3INT_B_0X3				(0x3u<<16)
#define	RCC_IC3CFGR_IC3INT_B_0XFF				(0xFFu<<16)

// IC4CFGR Configuration

#define	RCC_IC4CFGR_IC4SEL						(0x3u<<28)
#define	RCC_IC4CFGR_IC4SEL_0					(0x1u<<28)
#define	RCC_IC4CFGR_IC4INT						(0xFFu<<16)
#define	RCC_IC4CFGR_IC4INT_0					(0x1u<<16)

#define	RCC_IC4CFGR_IC4SEL_B_0X0				(0x0u<<28)
#define	RCC_IC4CFGR_IC4SEL_B_0X1				(0x1u<<28)
#define	RCC_IC4CFGR_IC4SEL_B_0X2				(0x2u<<28)
#define	RCC_IC4CFGR_IC4SEL_B_0X3				(0x3u<<28)
#define	RCC_IC4CFGR_IC4INT_B_0X0				(0x0u<<16)
#define	RCC_IC4CFGR_IC4INT_B_0X1				(0x1u<<16)
#define	RCC_IC4CFGR_IC4INT_B_0X2				(0x2u<<16)
#define	RCC_IC4CFGR_IC4INT_B_0X3				(0x3u<<16)
#define	RCC_IC4CFGR_IC4INT_B_0XFF				(0xFFu<<16)

// IC5CFGR Configuration

#define	RCC_IC5CFGR_IC5SEL						(0x3u<<28)
#define	RCC_IC5CFGR_IC5SEL_0					(0x1u<<28)
#define	RCC_IC5CFGR_IC5INT						(0xFFu<<16)
#define	RCC_IC5CFGR_IC5INT_0					(0x1u<<16)

#define	RCC_IC5CFGR_IC5SEL_B_0X0				(0x0u<<28)
#define	RCC_IC5CFGR_IC5SEL_B_0X1				(0x1u<<28)
#define	RCC_IC5CFGR_IC5SEL_B_0X2				(0x2u<<28)
#define	RCC_IC5CFGR_IC5SEL_B_0X3				(0x3u<<28)
#define	RCC_IC5CFGR_IC5INT_B_0X0				(0x0u<<16)
#define	RCC_IC5CFGR_IC5INT_B_0X1				(0x1u<<16)
#define	RCC_IC5CFGR_IC5INT_B_0X2				(0x2u<<16)
#define	RCC_IC5CFGR_IC5INT_B_0X3				(0x3u<<16)
#define	RCC_IC5CFGR_IC5INT_B_0XFF				(0xFFu<<16)

// IC6CFGR Configuration

#define	RCC_IC6CFGR_IC6SEL						(0x3u<<28)
#define	RCC_IC6CFGR_IC6SEL_0					(0x1u<<28)
#define	RCC_IC6CFGR_IC6INT						(0xFFu<<16)
#define	RCC_IC6CFGR_IC6INT_0					(0x1u<<16)

#define	RCC_IC6CFGR_IC6SEL_B_0X0				(0x0u<<28)
#define	RCC_IC6CFGR_IC6SEL_B_0X1				(0x1u<<28)
#define	RCC_IC6CFGR_IC6SEL_B_0X2				(0x2u<<28)
#define	RCC_IC6CFGR_IC6SEL_B_0X3				(0x3u<<28)
#define	RCC_IC6CFGR_IC6INT_B_0X0				(0x0u<<16)
#define	RCC_IC6CFGR_IC6INT_B_0X1				(0x1u<<16)
#define	RCC_IC6CFGR_IC6INT_B_0X2				(0x2u<<16)
#define	RCC_IC6CFGR_IC6INT_B_0X3				(0x3u<<16)
#define	RCC_IC6CFGR_IC6INT_B_0XFF				(0xFFu<<16)

// IC7CFGR Configuration

#define	RCC_IC7CFGR_IC7SEL						(0x3u<<28)
#define	RCC_IC7CFGR_IC7SEL_0					(0x1u<<28)
#define	RCC_IC7CFGR_IC7INT						(0xFFu<<16)
#define	RCC_IC7CFGR_IC7INT_0					(0x1u<<16)

#define	RCC_IC7CFGR_IC7SEL_B_0X0				(0x0u<<28)
#define	RCC_IC7CFGR_IC7SEL_B_0X1				(0x1u<<28)
#define	RCC_IC7CFGR_IC7SEL_B_0X2				(0x2u<<28)
#define	RCC_IC7CFGR_IC7SEL_B_0X3				(0x3u<<28)
#define	RCC_IC7CFGR_IC7INT_B_0X0				(0x0u<<16)
#define	RCC_IC7CFGR_IC7INT_B_0X1				(0x1u<<16)
#define	RCC_IC7CFGR_IC7INT_B_0X2				(0x2u<<16)
#define	RCC_IC7CFGR_IC7INT_B_0X3				(0x3u<<16)
#define	RCC_IC7CFGR_IC7INT_B_0XFF				(0xFFu<<16)

// IC8CFGR Configuration

#define	RCC_IC8CFGR_IC8SEL						(0x3u<<28)
#define	RCC_IC8CFGR_IC8SEL_0					(0x1u<<28)
#define	RCC_IC8CFGR_IC8INT						(0xFFu<<16)
#define	RCC_IC8CFGR_IC8INT_0					(0x1u<<16)

#define	RCC_IC8CFGR_IC8SEL_B_0X0				(0x0u<<28)
#define	RCC_IC8CFGR_IC8SEL_B_0X1				(0x1u<<28)
#define	RCC_IC8CFGR_IC8SEL_B_0X2				(0x2u<<28)
#define	RCC_IC8CFGR_IC8SEL_B_0X3				(0x3u<<28)
#define	RCC_IC8CFGR_IC8INT_B_0X0				(0x0u<<16)
#define	RCC_IC8CFGR_IC8INT_B_0X1				(0x1u<<16)
#define	RCC_IC8CFGR_IC8INT_B_0X2				(0x2u<<16)
#define	RCC_IC8CFGR_IC8INT_B_0X3				(0x3u<<16)
#define	RCC_IC8CFGR_IC8INT_B_0XFF				(0xFFu<<16)

// IC9CFGR Configuration

#define	RCC_IC9CFGR_IC9SEL						(0x3u<<28)
#define	RCC_IC9CFGR_IC9SEL_0					(0x1u<<28)
#define	RCC_IC9CFGR_IC9INT						(0xFFu<<16)
#define	RCC_IC9CFGR_IC9INT_0					(0x1u<<16)

#define	RCC_IC9CFGR_IC9SEL_B_0X0				(0x0u<<28)
#define	RCC_IC9CFGR_IC9SEL_B_0X1				(0x1u<<28)
#define	RCC_IC9CFGR_IC9SEL_B_0X2				(0x2u<<28)
#define	RCC_IC9CFGR_IC9SEL_B_0X3				(0x3u<<28)
#define	RCC_IC9CFGR_IC9INT_B_0X0				(0x0u<<16)
#define	RCC_IC9CFGR_IC9INT_B_0X1				(0x1u<<16)
#define	RCC_IC9CFGR_IC9INT_B_0X2				(0x2u<<16)
#define	RCC_IC9CFGR_IC9INT_B_0X3				(0x3u<<16)
#define	RCC_IC9CFGR_IC9INT_B_0XFF				(0xFFu<<16)

// IC10CFGR Configuration

#define	RCC_IC10CFGR_IC10SEL					(0x3u<<28)
#define	RCC_IC10CFGR_IC10SEL_0					(0x1u<<28)
#define	RCC_IC10CFGR_IC10INT					(0xFFu<<16)
#define	RCC_IC10CFGR_IC10INT_0					(0x1u<<16)

#define	RCC_IC10CFGR_IC10SEL_B_0X0				(0x0u<<28)
#define	RCC_IC10CFGR_IC10SEL_B_0X1				(0x1u<<28)
#define	RCC_IC10CFGR_IC10SEL_B_0X2				(0x2u<<28)
#define	RCC_IC10CFGR_IC10SEL_B_0X3				(0x3u<<28)
#define	RCC_IC10CFGR_IC10INT_B_0X0				(0x0u<<16)
#define	RCC_IC10CFGR_IC10INT_B_0X1				(0x1u<<16)
#define	RCC_IC10CFGR_IC10INT_B_0X2				(0x2u<<16)
#define	RCC_IC10CFGR_IC10INT_B_0X3				(0x3u<<16)
#define	RCC_IC10CFGR_IC10INT_B_0XFF				(0xFFu<<16)

// IC11CFGR Configuration

#define	RCC_IC11CFGR_IC11SEL					(0x3u<<28)
#define	RCC_IC11CFGR_IC11SEL_0					(0x1u<<28)
#define	RCC_IC11CFGR_IC11INT					(0xFFu<<16)
#define	RCC_IC11CFGR_IC11INT_0					(0x1u<<16)

#define	RCC_IC11CFGR_IC11SEL_B_0X0				(0x0u<<28)
#define	RCC_IC11CFGR_IC11SEL_B_0X1				(0x1u<<28)
#define	RCC_IC11CFGR_IC11SEL_B_0X2				(0x2u<<28)
#define	RCC_IC11CFGR_IC11SEL_B_0X3				(0x3u<<28)
#define	RCC_IC11CFGR_IC11INT_B_0X0				(0x0u<<16)
#define	RCC_IC11CFGR_IC11INT_B_0X1				(0x1u<<16)
#define	RCC_IC11CFGR_IC11INT_B_0X2				(0x2u<<16)
#define	RCC_IC11CFGR_IC11INT_B_0X3				(0x3u<<16)
#define	RCC_IC11CFGR_IC11INT_B_0XFF				(0xFFu<<16)

// IC12CFGR Configuration

#define	RCC_IC12CFGR_IC12SEL					(0x3u<<28)
#define	RCC_IC12CFGR_IC12SEL_0					(0x1u<<28)
#define	RCC_IC12CFGR_IC12INT					(0xFFu<<16)
#define	RCC_IC12CFGR_IC12INT_0					(0x1u<<16)

#define	RCC_IC12CFGR_IC12SEL_B_0X0				(0x0u<<28)
#define	RCC_IC12CFGR_IC12SEL_B_0X1				(0x1u<<28)
#define	RCC_IC12CFGR_IC12SEL_B_0X2				(0x2u<<28)
#define	RCC_IC12CFGR_IC12SEL_B_0X3				(0x3u<<28)
#define	RCC_IC12CFGR_IC12INT_B_0X0				(0x0u<<16)
#define	RCC_IC12CFGR_IC12INT_B_0X1				(0x1u<<16)
#define	RCC_IC12CFGR_IC12INT_B_0X2				(0x2u<<16)
#define	RCC_IC12CFGR_IC12INT_B_0X3				(0x3u<<16)
#define	RCC_IC12CFGR_IC12INT_B_0XFF				(0xFFu<<16)

// IC13CFGR Configuration

#define	RCC_IC13CFGR_IC13SEL					(0x3u<<28)
#define	RCC_IC13CFGR_IC13SEL_0					(0x1u<<28)
#define	RCC_IC13CFGR_IC13INT					(0xFFu<<16)
#define	RCC_IC13CFGR_IC13INT_0					(0x1u<<16)

#define	RCC_IC13CFGR_IC13SEL_B_0X0				(0x0u<<28)
#define	RCC_IC13CFGR_IC13SEL_B_0X1				(0x1u<<28)
#define	RCC_IC13CFGR_IC13SEL_B_0X2				(0x2u<<28)
#define	RCC_IC13CFGR_IC13SEL_B_0X3				(0x3u<<28)
#define	RCC_IC13CFGR_IC13INT_B_0X0				(0x0u<<16)
#define	RCC_IC13CFGR_IC13INT_B_0X1				(0x1u<<16)
#define	RCC_IC13CFGR_IC13INT_B_0X2				(0x2u<<16)
#define	RCC_IC13CFGR_IC13INT_B_0X3				(0x3u<<16)
#define	RCC_IC13CFGR_IC13INT_B_0XFF				(0xFFu<<16)

// IC14CFGR Configuration

#define	RCC_IC14CFGR_IC14SEL					(0x3u<<28)
#define	RCC_IC14CFGR_IC14SEL_0					(0x1u<<28)
#define	RCC_IC14CFGR_IC14INT					(0xFFu<<16)
#define	RCC_IC14CFGR_IC14INT_0					(0x1u<<16)

#define	RCC_IC14CFGR_IC14SEL_B_0X0				(0x0u<<28)
#define	RCC_IC14CFGR_IC14SEL_B_0X1				(0x1u<<28)
#define	RCC_IC14CFGR_IC14SEL_B_0X2				(0x2u<<28)
#define	RCC_IC14CFGR_IC14SEL_B_0X3				(0x3u<<28)
#define	RCC_IC14CFGR_IC14INT_B_0X0				(0x0u<<16)
#define	RCC_IC14CFGR_IC14INT_B_0X1				(0x1u<<16)
#define	RCC_IC14CFGR_IC14INT_B_0X2				(0x2u<<16)
#define	RCC_IC14CFGR_IC14INT_B_0X3				(0x3u<<16)
#define	RCC_IC14CFGR_IC14INT_B_0XFF				(0xFFu<<16)

// IC15CFGR Configuration

#define	RCC_IC15CFGR_IC15SEL					(0x3u<<28)
#define	RCC_IC15CFGR_IC15SEL_0					(0x1u<<28)
#define	RCC_IC15CFGR_IC15INT					(0xFFu<<16)
#define	RCC_IC15CFGR_IC15INT_0					(0x1u<<16)

#define	RCC_IC15CFGR_IC15SEL_B_0X0				(0x0u<<28)
#define	RCC_IC15CFGR_IC15SEL_B_0X1				(0x1u<<28)
#define	RCC_IC15CFGR_IC15SEL_B_0X2				(0x2u<<28)
#define	RCC_IC15CFGR_IC15SEL_B_0X3				(0x3u<<28)
#define	RCC_IC15CFGR_IC15INT_B_0X0				(0x0u<<16)
#define	RCC_IC15CFGR_IC15INT_B_0X1				(0x1u<<16)
#define	RCC_IC15CFGR_IC15INT_B_0X2				(0x2u<<16)
#define	RCC_IC15CFGR_IC15INT_B_0X3				(0x3u<<16)
#define	RCC_IC15CFGR_IC15INT_B_0XFF				(0xFFu<<16)

// IC16CFGR Configuration

#define	RCC_IC16CFGR_IC16SEL					(0x3u<<28)
#define	RCC_IC16CFGR_IC16SEL_0					(0x1u<<28)
#define	RCC_IC16CFGR_IC16INT					(0xFFu<<16)
#define	RCC_IC16CFGR_IC16INT_0					(0x1u<<16)

#define	RCC_IC16CFGR_IC16SEL_B_0X0				(0x0u<<28)
#define	RCC_IC16CFGR_IC16SEL_B_0X1				(0x1u<<28)
#define	RCC_IC16CFGR_IC16SEL_B_0X2				(0x2u<<28)
#define	RCC_IC16CFGR_IC16SEL_B_0X3				(0x3u<<28)
#define	RCC_IC16CFGR_IC16INT_B_0X1				(0x1u<<16)
#define	RCC_IC16CFGR_IC16INT_B_0X2				(0x2u<<16)
#define	RCC_IC16CFGR_IC16INT_B_0X3				(0x3u<<16)
#define	RCC_IC16CFGR_IC16INT_B_0XFF				(0xFFu<<16)

// IC17CFGR Configuration

#define	RCC_IC17CFGR_IC17SEL					(0x3u<<28)
#define	RCC_IC17CFGR_IC17SEL_0					(0x1u<<28)
#define	RCC_IC17CFGR_IC17INT					(0xFFu<<16)
#define	RCC_IC17CFGR_IC17INT_0					(0x1u<<16)

#define	RCC_IC17CFGR_IC17SEL_B_0X0				(0x0u<<28)
#define	RCC_IC17CFGR_IC17SEL_B_0X1				(0x1u<<28)
#define	RCC_IC17CFGR_IC17SEL_B_0X2				(0x2u<<28)
#define	RCC_IC17CFGR_IC17SEL_B_0X3				(0x3u<<28)
#define	RCC_IC17CFGR_IC17INT_B_0X0				(0x0u<<16)
#define	RCC_IC17CFGR_IC17INT_B_0X1				(0x1u<<16)
#define	RCC_IC17CFGR_IC17INT_B_0X2				(0x2u<<16)
#define	RCC_IC17CFGR_IC17INT_B_0X3				(0x3u<<16)
#define	RCC_IC17CFGR_IC17INT_B_0XFF				(0xFFu<<16)

// IC18CFGR Configuration

#define	RCC_IC18CFGR_IC18SEL					(0x3u<<28)
#define	RCC_IC18CFGR_IC18SEL_0					(0x1u<<28)
#define	RCC_IC18CFGR_IC18INT					(0xFFu<<16)
#define	RCC_IC18CFGR_IC18INT_0					(0x1u<<16)

#define	RCC_IC18CFGR_IC18SEL_B_0X0				(0x0u<<28)
#define	RCC_IC18CFGR_IC18SEL_B_0X1				(0x1u<<28)
#define	RCC_IC18CFGR_IC18SEL_B_0X2				(0x2u<<28)
#define	RCC_IC18CFGR_IC18SEL_B_0X3				(0x3u<<28)
#define	RCC_IC18CFGR_IC18INT_B_0X0				(0x0u<<16)
#define	RCC_IC18CFGR_IC18INT_B_0X1				(0x1u<<16)
#define	RCC_IC18CFGR_IC18INT_B_0X2				(0x2u<<16)
#define	RCC_IC18CFGR_IC18INT_B_0X3				(0x3u<<16)
#define	RCC_IC18CFGR_IC18INT_B_0XFF				(0xFFu<<16)

// IC19CFGR Configuration

#define	RCC_IC19CFGR_IC19SEL					(0x3u<<28)
#define	RCC_IC19CFGR_IC19SEL_0					(0x1u<<28)
#define	RCC_IC19CFGR_IC19INT					(0xFFu<<16)
#define	RCC_IC19CFGR_IC19INT_0					(0x1u<<16)

#define	RCC_IC19CFGR_IC19SEL_B_0X0				(0x0u<<28)
#define	RCC_IC19CFGR_IC19SEL_B_0X1				(0x1u<<28)
#define	RCC_IC19CFGR_IC19SEL_B_0X2				(0x2u<<28)
#define	RCC_IC19CFGR_IC19SEL_B_0X3				(0x3u<<28)
#define	RCC_IC19CFGR_IC19INT_B_0X0				(0x0u<<16)
#define	RCC_IC19CFGR_IC19INT_B_0X1				(0x1u<<16)
#define	RCC_IC19CFGR_IC19INT_B_0X2				(0x2u<<16)
#define	RCC_IC19CFGR_IC19INT_B_0X3				(0x3u<<16)
#define	RCC_IC19CFGR_IC19INT_B_0XFF				(0xFFu<<16)

// IC20CFGR Configuration

#define	RCC_IC20CFGR_IC20SEL					(0x3u<<28)
#define	RCC_IC20CFGR_IC20SEL_0					(0x1u<<28)
#define	RCC_IC20CFGR_IC20INT					(0xFFu<<16)
#define	RCC_IC20CFGR_IC20INT_0					(0x1u<<16)

#define	RCC_IC20CFGR_IC20SEL_B_0X0				(0x0u<<28)
#define	RCC_IC20CFGR_IC20SEL_B_0X1				(0x1u<<28)
#define	RCC_IC20CFGR_IC20SEL_B_0X2				(0x2u<<28)
#define	RCC_IC20CFGR_IC20SEL_B_0X3				(0x3u<<28)
#define	RCC_IC20CFGR_IC20INT_B_0X0				(0x0u<<16)
#define	RCC_IC20CFGR_IC20INT_B_0X1				(0x1u<<16)
#define	RCC_IC20CFGR_IC20INT_B_0X2				(0x2u<<16)
#define	RCC_IC20CFGR_IC20INT_B_0X3				(0x3u<<16)
#define	RCC_IC20CFGR_IC20INT_B_0XFF				(0xFFu<<16)

// CIER Configuration

#define	RCC_CIER_WKUPIE							(0x1u<<24)
#define	RCC_CIER_HSECSSIE						(0x1u<<17)
#define	RCC_CIER_LSECSSIE						(0x1u<<16)
#define	RCC_CIER_PLL4RDYIE						(0x1u<<11)
#define	RCC_CIER_PLL3RDYIE						(0x1u<<10)
#define	RCC_CIER_PLL2RDYIE						(0x1u<<9)
#define	RCC_CIER_PLL1RDYIE						(0x1u<<8)
#define	RCC_CIER_HSERDYIE						(0x1u<<4)
#define	RCC_CIER_HSIRDYIE						(0x1u<<3)
#define	RCC_CIER_MSIRDYIE						(0x1u<<2)
#define	RCC_CIER_LSERDYIE						(0x1u<<1)
#define	RCC_CIER_LSIRDYIE						(0x1u<<0)

#define	RCC_CIER_WKUPIE_B_0X0					(0x0u<<24)
#define	RCC_CIER_WKUPIE_B_0X1					(0x1u<<24)
#define	RCC_CIER_HSECSSIE_B_0X0					(0x0u<<17)
#define	RCC_CIER_HSECSSIE_B_0X1					(0x1u<<17)
#define	RCC_CIER_LSECSSIE_B_0X0					(0x0u<<16)
#define	RCC_CIER_LSECSSIE_B_0X1					(0x1u<<16)
#define	RCC_CIER_PLL4RDYIE_B_0X0				(0x0u<<11)
#define	RCC_CIER_PLL4RDYIE_B_0X1				(0x1u<<11)
#define	RCC_CIER_PLL3RDYIE_B_0X0				(0x0u<<10)
#define	RCC_CIER_PLL3RDYIE_B_0X1				(0x1u<<10)
#define	RCC_CIER_PLL2RDYIE_B_0X0				(0x0u<<9)
#define	RCC_CIER_PLL2RDYIE_B_0X1				(0x1u<<9)
#define	RCC_CIER_PLL1RDYIE_B_0X0				(0x0u<<8)
#define	RCC_CIER_PLL1RDYIE_B_0X1				(0x1u<<8)
#define	RCC_CIER_HSERDYIE_B_0X0					(0x0u<<4)
#define	RCC_CIER_HSERDYIE_B_0X1					(0x1u<<4)
#define	RCC_CIER_HSIRDYIE_B_0X0					(0x0u<<3)
#define	RCC_CIER_HSIRDYIE_B_0X1					(0x1u<<3)
#define	RCC_CIER_MSIRDYIE_B_0X0					(0x0u<<2)
#define	RCC_CIER_MSIRDYIE_B_0X1					(0x1u<<2)
#define	RCC_CIER_LSERDYIE_B_0X0					(0x0u<<1)
#define	RCC_CIER_LSERDYIE_B_0X1					(0x1u<<1)
#define	RCC_CIER_LSIRDYIE_B_0X0					(0x0u<<0)
#define	RCC_CIER_LSIRDYIE_B_0X1					(0x1u<<0)

// CIFR Configuration

#define	RCC_CIFR_WKUPF							(0x1u<<24)
#define	RCC_CIFR_HSECSSF						(0x1u<<17)
#define	RCC_CIFR_LSECSSF						(0x1u<<16)
#define	RCC_CIFR_PLL4RDYF						(0x1u<<11)
#define	RCC_CIFR_PLL3RDYF						(0x1u<<10)
#define	RCC_CIFR_PLL2RDYF						(0x1u<<9)
#define	RCC_CIFR_PLL1RDYF						(0x1u<<8)
#define	RCC_CIFR_HSERDYF						(0x1u<<4)
#define	RCC_CIFR_HSIRDYF						(0x1u<<3)
#define	RCC_CIFR_MSIRDYF						(0x1u<<2)
#define	RCC_CIFR_LSERDYF						(0x1u<<1)
#define	RCC_CIFR_LSIRDYF						(0x1u<<0)

#define	RCC_CIFR_WKUPF_B_0X0					(0x0u<<24)
#define	RCC_CIFR_WKUPF_B_0X1					(0x1u<<24)
#define	RCC_CIFR_HSECSSF_B_0X0					(0x0u<<17)
#define	RCC_CIFR_HSECSSF_B_0X1					(0x1u<<17)
#define	RCC_CIFR_LSECSSF_B_0X0					(0x0u<<16)
#define	RCC_CIFR_LSECSSF_B_0X1					(0x1u<<16)
#define	RCC_CIFR_PLL4RDYF_B_0X0					(0x0u<<11)
#define	RCC_CIFR_PLL4RDYF_B_0X1					(0x1u<<11)
#define	RCC_CIFR_PLL3RDYF_B_0X0					(0x0u<<10)
#define	RCC_CIFR_PLL3RDYF_B_0X1					(0x1u<<10)
#define	RCC_CIFR_PLL2RDYF_B_0X0					(0x0u<<9)
#define	RCC_CIFR_PLL2RDYF_B_0X1					(0x1u<<9)
#define	RCC_CIFR_PLL1RDYF_B_0X0					(0x0u<<8)
#define	RCC_CIFR_PLL1RDYF_B_0X1					(0x1u<<8)
#define	RCC_CIFR_HSERDYF_B_0X0					(0x0u<<4)
#define	RCC_CIFR_HSERDYF_B_0X1					(0x1u<<4)
#define	RCC_CIFR_HSIRDYF_B_0X0					(0x0u<<3)
#define	RCC_CIFR_HSIRDYF_B_0X1					(0x1u<<3)
#define	RCC_CIFR_MSIRDYF_B_0X0					(0x0u<<2)
#define	RCC_CIFR_MSIRDYF_B_0X1					(0x1u<<2)
#define	RCC_CIFR_LSERDYF_B_0X0					(0x0u<<1)
#define	RCC_CIFR_LSERDYF_B_0X1					(0x1u<<1)
#define	RCC_CIFR_LSIRDYF_B_0X0					(0x0u<<0)
#define	RCC_CIFR_LSIRDYF_B_0X1					(0x1u<<0)

// CICR Configuration

#define	RCC_CICR_WKUPFC							(0x1u<<24)
#define	RCC_CICR_HSECSSC						(0x1u<<17)
#define	RCC_CICR_LSECSSC						(0x1u<<16)
#define	RCC_CICR_PLL4RDYC						(0x1u<<11)
#define	RCC_CICR_PLL3RDYC						(0x1u<<10)
#define	RCC_CICR_PLL2RDYC						(0x1u<<9)
#define	RCC_CICR_PLL1RDYC						(0x1u<<8)
#define	RCC_CICR_HSERDYC						(0x1u<<4)
#define	RCC_CICR_HSIRDYC						(0x1u<<3)
#define	RCC_CICR_MSIRDYC						(0x1u<<2)
#define	RCC_CICR_LSERDYC						(0x1u<<1)
#define	RCC_CICR_LSIRDYC						(0x1u<<0)

#define	RCC_CICR_WKUPFC_B_0X0					(0x0u<<24)
#define	RCC_CICR_WKUPFC_B_0X1					(0x1u<<24)
#define	RCC_CICR_HSECSSC_B_0X0					(0x0u<<17)
#define	RCC_CICR_HSECSSC_B_0X1					(0x1u<<17)
#define	RCC_CICR_LSECSSC_B_0X0					(0x0u<<16)
#define	RCC_CICR_LSECSSC_B_0X1					(0x1u<<16)
#define	RCC_CICR_PLL4RDYC_B_0X0					(0x0u<<11)
#define	RCC_CICR_PLL4RDYC_B_0X1					(0x1u<<11)
#define	RCC_CICR_PLL3RDYC_B_0X0					(0x0u<<10)
#define	RCC_CICR_PLL3RDYC_B_0X1					(0x1u<<10)
#define	RCC_CICR_PLL2RDYC_B_0X0					(0x0u<<9)
#define	RCC_CICR_PLL2RDYC_B_0X1					(0x1u<<9)
#define	RCC_CICR_PLL1RDYC_B_0X0					(0x0u<<8)
#define	RCC_CICR_PLL1RDYC_B_0X1					(0x1u<<8)
#define	RCC_CICR_HSERDYC_B_0X0					(0x0u<<4)
#define	RCC_CICR_HSERDYC_B_0X1					(0x1u<<4)
#define	RCC_CICR_HSIRDYC_B_0X0					(0x0u<<3)
#define	RCC_CICR_HSIRDYC_B_0X1					(0x1u<<3)
#define	RCC_CICR_MSIRDYC_B_0X0					(0x0u<<2)
#define	RCC_CICR_MSIRDYC_B_0X1					(0x1u<<2)
#define	RCC_CICR_LSERDYC_B_0X0					(0x0u<<1)
#define	RCC_CICR_LSERDYC_B_0X1					(0x1u<<1)
#define	RCC_CICR_LSIRDYC_B_0X0					(0x0u<<0)
#define	RCC_CICR_LSIRDYC_B_0X1					(0x1u<<0)

// CCIPR1 Configuration

#define	RCC_CCIPR1_DCMIPPSEL					(0x3u<<20)
#define	RCC_CCIPR1_DCMIPPSEL_0					(0x1u<<20)
#define	RCC_CCIPR1_ADCPRE						(0xFFu<<8)
#define	RCC_CCIPR1_ADCPRE_0						(0x1u<<8)
#define	RCC_CCIPR1_ADC12SEL						(0x7u<<4)
#define	RCC_CCIPR1_ADC12SEL_0					(0x1u<<4)
#define	RCC_CCIPR1_ADF1SEL						(0x7u<<0)
#define	RCC_CCIPR1_ADF1SEL_0					(0x1u<<0)

#define	RCC_CCIPR1_DCMIPPSEL_B_0X0				(0x0u<<20)
#define	RCC_CCIPR1_DCMIPPSEL_B_0X1				(0x1u<<20)
#define	RCC_CCIPR1_DCMIPPSEL_B_0X2				(0x2u<<20)
#define	RCC_CCIPR1_DCMIPPSEL_B_0X3				(0x3u<<20)
#define	RCC_CCIPR1_ADCPRE_B_0X0					(0x0u<<8)
#define	RCC_CCIPR1_ADCPRE_B_0X1					(0x1u<<8)
#define	RCC_CCIPR1_ADCPRE_B_0X2					(0x2u<<8)
#define	RCC_CCIPR1_ADCPRE_B_0X3					(0x3u<<8)
#define	RCC_CCIPR1_ADC12SEL_B_0X0				(0x0u<<4)
#define	RCC_CCIPR1_ADC12SEL_B_0X1				(0x1u<<4)
#define	RCC_CCIPR1_ADC12SEL_B_0X2				(0x2u<<4)
#define	RCC_CCIPR1_ADC12SEL_B_0X3				(0x3u<<4)
#define	RCC_CCIPR1_ADC12SEL_B_0X4				(0x4u<<4)
#define	RCC_CCIPR1_ADC12SEL_B_0X5				(0x5u<<4)
#define	RCC_CCIPR1_ADC12SEL_B_0X6				(0x6u<<4)
#define	RCC_CCIPR1_ADC12SEL_B_0X7				(0x7u<<4)
#define	RCC_CCIPR1_ADF1SEL_B_0X0				(0x0u<<0)
#define	RCC_CCIPR1_ADF1SEL_B_0X1				(0x1u<<0)
#define	RCC_CCIPR1_ADF1SEL_B_0X2				(0x2u<<0)
#define	RCC_CCIPR1_ADF1SEL_B_0X3				(0x3u<<0)
#define	RCC_CCIPR1_ADF1SEL_B_0X4				(0x4u<<0)
#define	RCC_CCIPR1_ADF1SEL_B_0X5				(0x5u<<0)
#define	RCC_CCIPR1_ADF1SEL_B_0X6				(0x6u<<0)
#define	RCC_CCIPR1_ADF1SEL_B_0X7				(0x7u<<0)

// CCIPR2 Configuration

#define	RCC_CCIPR2_ETH1GTXCLKSEL				(0x1u<<24)
#define	RCC_CCIPR2_ETH1REFCLKSEL				(0x1u<<20)
#define	RCC_CCIPR2_ETH1SEL						(0x7u<<16)
#define	RCC_CCIPR2_ETH1SEL_0					(0x1u<<16)
#define	RCC_CCIPR2_ETH1CLKSEL					(0x3u<<12)
#define	RCC_CCIPR2_ETH1CLKSEL_0					(0x1u<<12)
#define	RCC_CCIPR2_ETH1PWRDOWNACK				(0x1u<<8)
#define	RCC_CCIPR2_ETH1PTPDIV					(0xFu<<4)
#define	RCC_CCIPR2_ETH1PTPDIV_0					(0x1u<<4)
#define	RCC_CCIPR2_ETH1PTPSEL					(0x3u<<0)
#define	RCC_CCIPR2_ETH1PTPSEL_0					(0x1u<<0)

#define	RCC_CCIPR2_ETH1GTXCLKSEL_B_0X0			(0x0u<<24)
#define	RCC_CCIPR2_ETH1GTXCLKSEL_B_0X1			(0x1u<<24)
#define	RCC_CCIPR2_ETH1CLKSEL_B_0X0				(0x0u<<12)
#define	RCC_CCIPR2_ETH1CLKSEL_B_0X1				(0x1u<<12)
#define	RCC_CCIPR2_ETH1CLKSEL_B_0X2				(0x2u<<12)
#define	RCC_CCIPR2_ETH1CLKSEL_B_0X3				(0x3u<<12)
#define	RCC_CCIPR2_ETH1PWRDOWNACK_B_0X0			(0x0u<<8)
#define	RCC_CCIPR2_ETH1PWRDOWNACK_B_0X1			(0x1u<<8)
#define	RCC_CCIPR2_ETH1PTPDIV_B_0X0				(0x0u<<4)
#define	RCC_CCIPR2_ETH1PTPDIV_B_0X1				(0x1u<<4)
#define	RCC_CCIPR2_ETH1PTPDIV_B_0X2				(0x2u<<4)
#define	RCC_CCIPR2_ETH1PTPDIV_B_0X3				(0x3u<<4)
#define	RCC_CCIPR2_ETH1PTPDIV_B_0XF				(0xFu<<4)
#define	RCC_CCIPR2_ETH1PTPSEL_B_0X0				(0x0u<<0)
#define	RCC_CCIPR2_ETH1PTPSEL_B_0X1				(0x1u<<0)
#define	RCC_CCIPR2_ETH1PTPSEL_B_0X2				(0x2u<<0)
#define	RCC_CCIPR2_ETH1PTPSEL_B_0X3				(0x3u<<0)

// CCIPR3 Configuration

#define	RCC_CCIPR3_DFTSEL						(0x1u<<8)
#define	RCC_CCIPR3_FMCSEL						(0x3u<<4)
#define	RCC_CCIPR3_FMCSEL_0						(0x1u<<4)
#define	RCC_CCIPR3_FDCANSEL						(0x3u<<0)
#define	RCC_CCIPR3_FDCANSEL_0					(0x1u<<0)

#define	RCC_CCIPR3_DFTSEL_B_0X0					(0x0u<<8)
#define	RCC_CCIPR3_DFTSEL_B_0X1					(0x1u<<8)
#define	RCC_CCIPR3_FMCSEL_B_0X0					(0x0u<<4)
#define	RCC_CCIPR3_FMCSEL_B_0X1					(0x1u<<4)
#define	RCC_CCIPR3_FMCSEL_B_0X2					(0x2u<<4)
#define	RCC_CCIPR3_FMCSEL_B_0X3					(0x3u<<4)
#define	RCC_CCIPR3_FDCANSEL_B_0X0				(0x0u<<0)
#define	RCC_CCIPR3_FDCANSEL_B_0X1				(0x1u<<0)
#define	RCC_CCIPR3_FDCANSEL_B_0X2				(0x2u<<0)
#define	RCC_CCIPR3_FDCANSEL_B_0X3				(0x3u<<0)

// CCIPR4 Configuration

#define	RCC_CCIPR4_LTDCSEL						(0x3u<<24)
#define	RCC_CCIPR4_LTDCSEL_0					(0x1u<<24)
#define	RCC_CCIPR4_I3C2SEL						(0x7u<<20)
#define	RCC_CCIPR4_I3C2SEL_0					(0x1u<<20)
#define	RCC_CCIPR4_I3C1SEL						(0x7u<<16)
#define	RCC_CCIPR4_I3C1SEL_0					(0x1u<<16)
#define	RCC_CCIPR4_I2C4SEL						(0x7u<<12)
#define	RCC_CCIPR4_I2C4SEL_0					(0x1u<<12)
#define	RCC_CCIPR4_I2C3SEL						(0x7u<<8)
#define	RCC_CCIPR4_I2C3SEL_0					(0x1u<<8)
#define	RCC_CCIPR4_I2C2SEL						(0x7u<<4)
#define	RCC_CCIPR4_I2C2SEL_0					(0x1u<<4)
#define	RCC_CCIPR4_I2C1SEL						(0x7u<<0)
#define	RCC_CCIPR4_I2C1SEL_0					(0x1u<<0)

#define	RCC_CCIPR4_LTDCSEL_B_0X0				(0x0u<<24)
#define	RCC_CCIPR4_LTDCSEL_B_0X1				(0x1u<<24)
#define	RCC_CCIPR4_LTDCSEL_B_0X2				(0x2u<<24)
#define	RCC_CCIPR4_LTDCSEL_B_0X3				(0x3u<<24)
#define	RCC_CCIPR4_I3C2SEL_B_0X0				(0x0u<<20)
#define	RCC_CCIPR4_I3C2SEL_B_0X1				(0x1u<<20)
#define	RCC_CCIPR4_I3C2SEL_B_0X2				(0x2u<<20)
#define	RCC_CCIPR4_I3C2SEL_B_0X3				(0x3u<<20)
#define	RCC_CCIPR4_I3C2SEL_B_0X4				(0x4u<<20)
#define	RCC_CCIPR4_I3C2SEL_B_0X5				(0x5u<<20)
#define	RCC_CCIPR4_I3C1SEL_B_0X0				(0x0u<<16)
#define	RCC_CCIPR4_I3C1SEL_B_0X1				(0x1u<<16)
#define	RCC_CCIPR4_I3C1SEL_B_0X2				(0x2u<<16)
#define	RCC_CCIPR4_I3C1SEL_B_0X3				(0x3u<<16)
#define	RCC_CCIPR4_I3C1SEL_B_0X4				(0x4u<<16)
#define	RCC_CCIPR4_I3C1SEL_B_0X5				(0x5u<<16)
#define	RCC_CCIPR4_I2C4SEL_B_0X0				(0x0u<<12)
#define	RCC_CCIPR4_I2C4SEL_B_0X1				(0x1u<<12)
#define	RCC_CCIPR4_I2C4SEL_B_0X2				(0x2u<<12)
#define	RCC_CCIPR4_I2C4SEL_B_0X3				(0x3u<<12)
#define	RCC_CCIPR4_I2C4SEL_B_0X4				(0x4u<<12)
#define	RCC_CCIPR4_I2C4SEL_B_0X5				(0x5u<<12)
#define	RCC_CCIPR4_I2C3SEL_B_0X0				(0x0u<<8)
#define	RCC_CCIPR4_I2C3SEL_B_0X1				(0x1u<<8)
#define	RCC_CCIPR4_I2C3SEL_B_0X2				(0x2u<<8)
#define	RCC_CCIPR4_I2C3SEL_B_0X3				(0x3u<<8)
#define	RCC_CCIPR4_I2C3SEL_B_0X4				(0x4u<<8)
#define	RCC_CCIPR4_I2C3SEL_B_0X5				(0x5u<<8)
#define	RCC_CCIPR4_I2C2SEL_B_0X0				(0x0u<<4)
#define	RCC_CCIPR4_I2C2SEL_B_0X1				(0x1u<<4)
#define	RCC_CCIPR4_I2C2SEL_B_0X2				(0x2u<<4)
#define	RCC_CCIPR4_I2C2SEL_B_0X3				(0x3u<<4)
#define	RCC_CCIPR4_I2C2SEL_B_0X4				(0x4u<<4)
#define	RCC_CCIPR4_I2C2SEL_B_0X5				(0x5u<<4)
#define	RCC_CCIPR4_I2C1SEL_B_0X0				(0x0u<<0)
#define	RCC_CCIPR4_I2C1SEL_B_0X1				(0x1u<<0)
#define	RCC_CCIPR4_I2C1SEL_B_0X2				(0x2u<<0)
#define	RCC_CCIPR4_I2C1SEL_B_0X3				(0x3u<<0)
#define	RCC_CCIPR4_I2C1SEL_B_0X4				(0x4u<<0)
#define	RCC_CCIPR4_I2C1SEL_B_0X5				(0x5u<<0)

// CCIPR5 Configuration

#define	RCC_CCIPR5_MDF1SEL						(0x7u<<16)
#define	RCC_CCIPR5_MDF1SEL_0					(0x1u<<16)
#define	RCC_CCIPR5_MCO2PRE						(0xFu<<12)
#define	RCC_CCIPR5_MCO2PRE_0					(0x1u<<12)
#define	RCC_CCIPR5_MCO2SEL						(0x7u<<8)
#define	RCC_CCIPR5_MCO2SEL_0					(0x1u<<8)
#define	RCC_CCIPR5_MCO1PRE						(0xFu<<4)
#define	RCC_CCIPR5_MCO1PRE_0					(0x1u<<4)
#define	RCC_CCIPR5_MCO1SEL						(0x7u<<0)
#define	RCC_CCIPR5_MCO1SEL_0					(0x1u<<0)

#define	RCC_CCIPR5_MDF1SEL_B_0X0				(0x0u<<16)
#define	RCC_CCIPR5_MDF1SEL_B_0X1				(0x1u<<16)
#define	RCC_CCIPR5_MDF1SEL_B_0X2				(0x2u<<16)
#define	RCC_CCIPR5_MDF1SEL_B_0X3				(0x3u<<16)
#define	RCC_CCIPR5_MDF1SEL_B_0X4				(0x4u<<16)
#define	RCC_CCIPR5_MDF1SEL_B_0X5				(0x5u<<16)
#define	RCC_CCIPR5_MDF1SEL_B_0X6				(0x6u<<16)
#define	RCC_CCIPR5_MDF1SEL_B_0X7				(0x7u<<16)
#define	RCC_CCIPR5_MCO2PRE_B_0X0				(0x0u<<12)
#define	RCC_CCIPR5_MCO2PRE_B_0X1				(0x1u<<12)
#define	RCC_CCIPR5_MCO2PRE_B_0X2				(0x2u<<12)
#define	RCC_CCIPR5_MCO2PRE_B_0X3				(0x3u<<12)
#define	RCC_CCIPR5_MCO2PRE_B_0XF				(0xFu<<12)
#define	RCC_CCIPR5_MCO2SEL_B_0X0				(0x0u<<8)
#define	RCC_CCIPR5_MCO2SEL_B_0X1				(0x1u<<8)
#define	RCC_CCIPR5_MCO2SEL_B_0X2				(0x2u<<8)
#define	RCC_CCIPR5_MCO2SEL_B_0X3				(0x3u<<8)
#define	RCC_CCIPR5_MCO2SEL_B_0X4				(0x4u<<8)
#define	RCC_CCIPR5_MCO2SEL_B_0X5				(0x5u<<8)
#define	RCC_CCIPR5_MCO2SEL_B_0X6				(0x6u<<8)
#define	RCC_CCIPR5_MCO2SEL_B_0X7				(0x7u<<8)
#define	RCC_CCIPR5_MCO1PRE_B_0X0				(0x0u<<4)
#define	RCC_CCIPR5_MCO1PRE_B_0X1				(0x1u<<4)
#define	RCC_CCIPR5_MCO1PRE_B_0X2				(0x2u<<4)
#define	RCC_CCIPR5_MCO1PRE_B_0X3				(0x3u<<4)
#define	RCC_CCIPR5_MCO1PRE_B_0XF				(0xFu<<4)
#define	RCC_CCIPR5_MCO1SEL_B_0X0				(0x0u<<0)
#define	RCC_CCIPR5_MCO1SEL_B_0X1				(0x1u<<0)
#define	RCC_CCIPR5_MCO1SEL_B_0X2				(0x2u<<0)
#define	RCC_CCIPR5_MCO1SEL_B_0X3				(0x3u<<0)
#define	RCC_CCIPR5_MCO1SEL_B_0X4				(0x4u<<0)
#define	RCC_CCIPR5_MCO1SEL_B_0X5				(0x5u<<0)
#define	RCC_CCIPR5_MCO1SEL_B_0X6				(0x6u<<0)
#define	RCC_CCIPR5_MCO1SEL_B_0X7				(0x7u<<0)

// CCIPR6 Configuration

#define	RCC_CCIPR6_OTGPHY2CKREFSEL				(0x1u<<24)
#define	RCC_CCIPR6_OTGPHY2SEL					(0x3u<<20)
#define	RCC_CCIPR6_OTGPHY2SEL_0					(0x1u<<20)
#define	RCC_CCIPR6_OTGPHY1CKREFSEL				(0x1u<<16)
#define	RCC_CCIPR6_OTGPHY1SEL					(0x3u<<12)
#define	RCC_CCIPR6_OTGPHY1SEL_0					(0x1u<<12)
#define	RCC_CCIPR6_XSPI3SEL						(0x3u<<8)
#define	RCC_CCIPR6_XSPI3SEL_0					(0x1u<<8)
#define	RCC_CCIPR6_XSPI2SEL						(0x3u<<4)
#define	RCC_CCIPR6_XSPI2SEL_0					(0x1u<<4)
#define	RCC_CCIPR6_XSPI1SEL						(0x3u<<0)
#define	RCC_CCIPR6_XSPI1SEL_0					(0x1u<<0)

#define	RCC_CCIPR6_OTGPHY2SEL_B_0X0				(0x0u<<20)
#define	RCC_CCIPR6_OTGPHY2SEL_B_0X1				(0x1u<<20)
#define	RCC_CCIPR6_OTGPHY2SEL_B_0X2				(0x2u<<20)
#define	RCC_CCIPR6_OTGPHY2SEL_B_0X3				(0x3u<<20)
#define	RCC_CCIPR6_OTGPHY1SEL_B_0X0				(0x0u<<12)
#define	RCC_CCIPR6_OTGPHY1SEL_B_0X1				(0x1u<<12)
#define	RCC_CCIPR6_OTGPHY1SEL_B_0X2				(0x2u<<12)
#define	RCC_CCIPR6_OTGPHY1SEL_B_0X3				(0x3u<<12)
#define	RCC_CCIPR6_XSPI3SEL_B_0X0				(0x0u<<8)
#define	RCC_CCIPR6_XSPI3SEL_B_0X1				(0x1u<<8)
#define	RCC_CCIPR6_XSPI3SEL_B_0X2				(0x2u<<8)
#define	RCC_CCIPR6_XSPI3SEL_B_0X3				(0x3u<<8)
#define	RCC_CCIPR6_XSPI2SEL_B_0X0				(0x0u<<4)
#define	RCC_CCIPR6_XSPI2SEL_B_0X1				(0x1u<<4)
#define	RCC_CCIPR6_XSPI2SEL_B_0X2				(0x2u<<4)
#define	RCC_CCIPR6_XSPI2SEL_B_0X3				(0x3u<<4)
#define	RCC_CCIPR6_XSPI1SEL_B_0X0				(0x0u<<0)
#define	RCC_CCIPR6_XSPI1SEL_B_0X1				(0x1u<<0)
#define	RCC_CCIPR6_XSPI1SEL_B_0X2				(0x2u<<0)
#define	RCC_CCIPR6_XSPI1SEL_B_0X3				(0x3u<<0)

// CCIPR7 Configuration

#define	RCC_CCIPR7_SAI2SEL						(0x7u<<24)
#define	RCC_CCIPR7_SAI2SEL_0					(0x1u<<24)
#define	RCC_CCIPR7_SAI1SEL						(0x7u<<20)
#define	RCC_CCIPR7_SAI1SEL_0					(0x1u<<20)
#define	RCC_CCIPR7_RTCPRE						(0x3Fu<<12)
#define	RCC_CCIPR7_RTCPRE_0						(0x1u<<12)
#define	RCC_CCIPR7_RTCSEL						(0x3u<<8)
#define	RCC_CCIPR7_RTCSEL_0						(0x1u<<8)
#define	RCC_CCIPR7_PSSISEL						(0x3u<<4)
#define	RCC_CCIPR7_PSSISEL_0					(0x1u<<4)
#define	RCC_CCIPR7_PERSEL						(0x7u<<0)
#define	RCC_CCIPR7_PERSEL_0						(0x1u<<0)

#define	RCC_CCIPR7_SAI2SEL_B_0X0				(0x0u<<24)
#define	RCC_CCIPR7_SAI2SEL_B_0X1				(0x1u<<24)
#define	RCC_CCIPR7_SAI2SEL_B_0X2				(0x2u<<24)
#define	RCC_CCIPR7_SAI2SEL_B_0X3				(0x3u<<24)
#define	RCC_CCIPR7_SAI2SEL_B_0X4				(0x4u<<24)
#define	RCC_CCIPR7_SAI2SEL_B_0X5				(0x5u<<24)
#define	RCC_CCIPR7_SAI2SEL_B_0X6				(0x6u<<24)
#define	RCC_CCIPR7_SAI2SEL_B_0X7				(0x7u<<24)
#define	RCC_CCIPR7_SAI1SEL_B_0X0				(0x0u<<20)
#define	RCC_CCIPR7_SAI1SEL_B_0X1				(0x1u<<20)
#define	RCC_CCIPR7_SAI1SEL_B_0X2				(0x2u<<20)
#define	RCC_CCIPR7_SAI1SEL_B_0X3				(0x3u<<20)
#define	RCC_CCIPR7_SAI1SEL_B_0X4				(0x4u<<20)
#define	RCC_CCIPR7_SAI1SEL_B_0X5				(0x5u<<20)
#define	RCC_CCIPR7_SAI1SEL_B_0X6				(0x6u<<20)
#define	RCC_CCIPR7_SAI1SEL_B_0X7				(0x7u<<20)
#define	RCC_CCIPR7_RTCPRE_B_0X0					(0x0u<<12)
#define	RCC_CCIPR7_RTCPRE_B_0X1					(0x1u<<12)
#define	RCC_CCIPR7_RTCPRE_B_0X2					(0x2u<<12)
#define	RCC_CCIPR7_RTCPRE_B_0X3					(0x3u<<12)
#define	RCC_CCIPR7_RTCPRE_B_0X3F				(0x3Fu<<12)
#define	RCC_CCIPR7_RTCSEL_B_0X1					(0x1u<<8)
#define	RCC_CCIPR7_RTCSEL_B_0X2					(0x2u<<8)
#define	RCC_CCIPR7_RTCSEL_B_0X3					(0x3u<<8)
#define	RCC_CCIPR7_PSSISEL_B_0X0				(0x0u<<4)
#define	RCC_CCIPR7_PSSISEL_B_0X1				(0x1u<<4)
#define	RCC_CCIPR7_PSSISEL_B_0X2				(0x2u<<4)
#define	RCC_CCIPR7_PSSISEL_B_0X3				(0x3u<<4)
#define	RCC_CCIPR7_PERSEL_B_0X0					(0x0u<<0)
#define	RCC_CCIPR7_PERSEL_B_0X1					(0x1u<<0)
#define	RCC_CCIPR7_PERSEL_B_0X2					(0x2u<<0)
#define	RCC_CCIPR7_PERSEL_B_0X3					(0x3u<<0)
#define	RCC_CCIPR7_PERSEL_B_0X4					(0x4u<<0)
#define	RCC_CCIPR7_PERSEL_B_0X5					(0x5u<<0)
#define	RCC_CCIPR7_PERSEL_B_0X6					(0x6u<<0)
#define	RCC_CCIPR7_PERSEL_B_0X7					(0x7u<<0)

// CCIPR8 Configuration

#define	RCC_CCIPR8_SDMMC2SEL					(0x3u<<4)
#define	RCC_CCIPR8_SDMMC2SEL_0					(0x1u<<4)
#define	RCC_CCIPR8_SDMMC1SEL					(0x3u<<0)
#define	RCC_CCIPR8_SDMMC1SEL_0					(0x1u<<0)

#define	RCC_CCIPR8_SDMMC2SEL_B_0X0				(0x0u<<4)
#define	RCC_CCIPR8_SDMMC2SEL_B_0X1				(0x1u<<4)
#define	RCC_CCIPR8_SDMMC2SEL_B_0X2				(0x2u<<4)
#define	RCC_CCIPR8_SDMMC2SEL_B_0X3				(0x3u<<4)
#define	RCC_CCIPR8_SDMMC1SEL_B_0X0				(0x0u<<0)
#define	RCC_CCIPR8_SDMMC1SEL_B_0X1				(0x1u<<0)
#define	RCC_CCIPR8_SDMMC1SEL_B_0X2				(0x2u<<0)
#define	RCC_CCIPR8_SDMMC1SEL_B_0X3				(0x3u<<0)

// CCIPR9 Configuration

#define	RCC_CCIPR9_SPI6SEL						(0x7u<<24)
#define	RCC_CCIPR9_SPI6SEL_0					(0x1u<<24)
#define	RCC_CCIPR9_SPI5SEL						(0x7u<<20)
#define	RCC_CCIPR9_SPI5SEL_0					(0x1u<<20)
#define	RCC_CCIPR9_SPI4SEL						(0x7u<<16)
#define	RCC_CCIPR9_SPI4SEL_0					(0x1u<<16)
#define	RCC_CCIPR9_SPI3SEL						(0x7u<<12)
#define	RCC_CCIPR9_SPI3SEL_0					(0x1u<<12)
#define	RCC_CCIPR9_SPI2SEL						(0x7u<<8)
#define	RCC_CCIPR9_SPI2SEL_0					(0x1u<<8)
#define	RCC_CCIPR9_SPI1SEL						(0x7u<<4)
#define	RCC_CCIPR9_SPI1SEL_0					(0x1u<<4)
#define	RCC_CCIPR9_SPDIFRX1SEL					(0x7u<<0)
#define	RCC_CCIPR9_SPDIFRX1SEL_0				(0x1u<<0)

#define	RCC_CCIPR9_SPI6SEL_B_0X0				(0x0u<<24)
#define	RCC_CCIPR9_SPI6SEL_B_0X1				(0x1u<<24)
#define	RCC_CCIPR9_SPI6SEL_B_0X2				(0x2u<<24)
#define	RCC_CCIPR9_SPI6SEL_B_0X3				(0x3u<<24)
#define	RCC_CCIPR9_SPI6SEL_B_0X4				(0x4u<<24)
#define	RCC_CCIPR9_SPI6SEL_B_0X5				(0x5u<<24)
#define	RCC_CCIPR9_SPI6SEL_B_0X6				(0x6u<<24)
#define	RCC_CCIPR9_SPI5SEL_B_0X0				(0x0u<<20)
#define	RCC_CCIPR9_SPI5SEL_B_0X1				(0x1u<<20)
#define	RCC_CCIPR9_SPI5SEL_B_0X2				(0x2u<<20)
#define	RCC_CCIPR9_SPI5SEL_B_0X3				(0x3u<<20)
#define	RCC_CCIPR9_SPI5SEL_B_0X4				(0x4u<<20)
#define	RCC_CCIPR9_SPI5SEL_B_0X5				(0x5u<<20)
#define	RCC_CCIPR9_SPI5SEL_B_0X6				(0x6u<<20)
#define	RCC_CCIPR9_SPI4SEL_B_0X0				(0x0u<<16)
#define	RCC_CCIPR9_SPI4SEL_B_0X1				(0x1u<<16)
#define	RCC_CCIPR9_SPI4SEL_B_0X2				(0x2u<<16)
#define	RCC_CCIPR9_SPI4SEL_B_0X3				(0x3u<<16)
#define	RCC_CCIPR9_SPI4SEL_B_0X4				(0x4u<<16)
#define	RCC_CCIPR9_SPI4SEL_B_0X5				(0x5u<<16)
#define	RCC_CCIPR9_SPI4SEL_B_0X6				(0x6u<<16)
#define	RCC_CCIPR9_SPI3SEL_B_0X0				(0x0u<<12)
#define	RCC_CCIPR9_SPI3SEL_B_0X1				(0x1u<<12)
#define	RCC_CCIPR9_SPI3SEL_B_0X2				(0x2u<<12)
#define	RCC_CCIPR9_SPI3SEL_B_0X3				(0x3u<<12)
#define	RCC_CCIPR9_SPI3SEL_B_0X4				(0x4u<<12)
#define	RCC_CCIPR9_SPI3SEL_B_0X5				(0x5u<<12)
#define	RCC_CCIPR9_SPI3SEL_B_0X6				(0x6u<<12)
#define	RCC_CCIPR9_SPI2SEL_B_0X0				(0x0u<<8)
#define	RCC_CCIPR9_SPI2SEL_B_0X1				(0x1u<<8)
#define	RCC_CCIPR9_SPI2SEL_B_0X2				(0x2u<<8)
#define	RCC_CCIPR9_SPI2SEL_B_0X3				(0x3u<<8)
#define	RCC_CCIPR9_SPI2SEL_B_0X4				(0x4u<<8)
#define	RCC_CCIPR9_SPI2SEL_B_0X5				(0x5u<<8)
#define	RCC_CCIPR9_SPI2SEL_B_0X6				(0x6u<<8)
#define	RCC_CCIPR9_SPI1SEL_B_0X0				(0x0u<<4)
#define	RCC_CCIPR9_SPI1SEL_B_0X1				(0x1u<<4)
#define	RCC_CCIPR9_SPI1SEL_B_0X2				(0x2u<<4)
#define	RCC_CCIPR9_SPI1SEL_B_0X3				(0x3u<<4)
#define	RCC_CCIPR9_SPI1SEL_B_0X4				(0x4u<<4)
#define	RCC_CCIPR9_SPI1SEL_B_0X5				(0x5u<<4)
#define	RCC_CCIPR9_SPI1SEL_B_0X6				(0x6u<<4)
#define	RCC_CCIPR9_SPDIFRX1SEL_B_0X0			(0x0u<<0)
#define	RCC_CCIPR9_SPDIFRX1SEL_B_0X1			(0x1u<<0)
#define	RCC_CCIPR9_SPDIFRX1SEL_B_0X2			(0x2u<<0)
#define	RCC_CCIPR9_SPDIFRX1SEL_B_0X3			(0x3u<<0)
#define	RCC_CCIPR9_SPDIFRX1SEL_B_0X4			(0x4u<<0)
#define	RCC_CCIPR9_SPDIFRX1SEL_B_0X5			(0x5u<<0)
#define	RCC_CCIPR9_SPDIFRX1SEL_B_0X6			(0x6u<<0)

// CCIPR12 Configuration

#define	RCC_CCIPR12_LPTIM5SEL					(0x7u<<24)
#define	RCC_CCIPR12_LPTIM5SEL_0					(0x1u<<24)
#define	RCC_CCIPR12_LPTIM4SEL					(0x7u<<20)
#define	RCC_CCIPR12_LPTIM4SEL_0					(0x1u<<20)
#define	RCC_CCIPR12_LPTIM3SEL					(0x7u<<16)
#define	RCC_CCIPR12_LPTIM3SEL_0					(0x1u<<16)
#define	RCC_CCIPR12_LPTIM2SEL					(0x7u<<12)
#define	RCC_CCIPR12_LPTIM2SEL_0					(0x1u<<12)
#define	RCC_CCIPR12_LPTIM1SEL					(0x7u<<8)
#define	RCC_CCIPR12_LPTIM1SEL_0					(0x1u<<8)

#define	RCC_CCIPR12_LPTIM5SEL_B_0X0				(0x0u<<24)
#define	RCC_CCIPR12_LPTIM5SEL_B_0X1				(0x1u<<24)
#define	RCC_CCIPR12_LPTIM5SEL_B_0X2				(0x2u<<24)
#define	RCC_CCIPR12_LPTIM5SEL_B_0X3				(0x3u<<24)
#define	RCC_CCIPR12_LPTIM5SEL_B_0X4				(0x4u<<24)
#define	RCC_CCIPR12_LPTIM5SEL_B_0X5				(0x5u<<24)
#define	RCC_CCIPR12_LPTIM4SEL_B_0X0				(0x0u<<20)
#define	RCC_CCIPR12_LPTIM4SEL_B_0X1				(0x1u<<20)
#define	RCC_CCIPR12_LPTIM4SEL_B_0X2				(0x2u<<20)
#define	RCC_CCIPR12_LPTIM4SEL_B_0X3				(0x3u<<20)
#define	RCC_CCIPR12_LPTIM4SEL_B_0X4				(0x4u<<20)
#define	RCC_CCIPR12_LPTIM4SEL_B_0X5				(0x5u<<20)
#define	RCC_CCIPR12_LPTIM3SEL_B_0X0				(0x0u<<16)
#define	RCC_CCIPR12_LPTIM3SEL_B_0X1				(0x1u<<16)
#define	RCC_CCIPR12_LPTIM3SEL_B_0X2				(0x2u<<16)
#define	RCC_CCIPR12_LPTIM3SEL_B_0X3				(0x3u<<16)
#define	RCC_CCIPR12_LPTIM3SEL_B_0X4				(0x4u<<16)
#define	RCC_CCIPR12_LPTIM3SEL_B_0X5				(0x5u<<16)
#define	RCC_CCIPR12_LPTIM2SEL_B_0X0				(0x0u<<12)
#define	RCC_CCIPR12_LPTIM2SEL_B_0X1				(0x1u<<12)
#define	RCC_CCIPR12_LPTIM2SEL_B_0X2				(0x2u<<12)
#define	RCC_CCIPR12_LPTIM2SEL_B_0X3				(0x3u<<12)
#define	RCC_CCIPR12_LPTIM2SEL_B_0X4				(0x4u<<12)
#define	RCC_CCIPR12_LPTIM2SEL_B_0X5				(0x5u<<12)
#define	RCC_CCIPR12_LPTIM1SEL_B_0X0				(0x0u<<8)
#define	RCC_CCIPR12_LPTIM1SEL_B_0X1				(0x1u<<8)
#define	RCC_CCIPR12_LPTIM1SEL_B_0X2				(0x2u<<8)
#define	RCC_CCIPR12_LPTIM1SEL_B_0X3				(0x3u<<8)
#define	RCC_CCIPR12_LPTIM1SEL_B_0X4				(0x4u<<8)
#define	RCC_CCIPR12_LPTIM1SEL_B_0X5				(0x5u<<8)

// CCIPR13 Configuration

#define	RCC_CCIPR13_UART8SEL					(0x7u<<28)
#define	RCC_CCIPR13_UART8SEL_0					(0x1u<<28)
#define	RCC_CCIPR13_UART7SEL					(0x7u<<24)
#define	RCC_CCIPR13_UART7SEL_0					(0x1u<<24)
#define	RCC_CCIPR13_USART6SEL					(0x7u<<20)
#define	RCC_CCIPR13_USART6SEL_0					(0x1u<<20)
#define	RCC_CCIPR13_UART5SEL					(0x7u<<16)
#define	RCC_CCIPR13_UART5SEL_0					(0x1u<<16)
#define	RCC_CCIPR13_UART4SEL					(0x7u<<12)
#define	RCC_CCIPR13_UART4SEL_0					(0x1u<<12)
#define	RCC_CCIPR13_USART3SEL					(0x7u<<8)
#define	RCC_CCIPR13_USART3SEL_0					(0x1u<<8)
#define	RCC_CCIPR13_USART2SEL					(0x7u<<4)
#define	RCC_CCIPR13_USART2SEL_0					(0x1u<<4)
#define	RCC_CCIPR13_USART1SEL					(0x7u<<0)
#define	RCC_CCIPR13_USART1SEL_0					(0x1u<<0)

#define	RCC_CCIPR13_UART8SEL_B_0X0				(0x0u<<28)
#define	RCC_CCIPR13_UART8SEL_B_0X1				(0x1u<<28)
#define	RCC_CCIPR13_UART8SEL_B_0X2				(0x2u<<28)
#define	RCC_CCIPR13_UART8SEL_B_0X3				(0x3u<<28)
#define	RCC_CCIPR13_UART8SEL_B_0X4				(0x4u<<28)
#define	RCC_CCIPR13_UART8SEL_B_0X5				(0x5u<<28)
#define	RCC_CCIPR13_UART8SEL_B_0X6				(0x6u<<28)
#define	RCC_CCIPR13_UART7SEL_B_0X0				(0x0u<<24)
#define	RCC_CCIPR13_UART7SEL_B_0X1				(0x1u<<24)
#define	RCC_CCIPR13_UART7SEL_B_0X2				(0x2u<<24)
#define	RCC_CCIPR13_UART7SEL_B_0X3				(0x3u<<24)
#define	RCC_CCIPR13_UART7SEL_B_0X4				(0x4u<<24)
#define	RCC_CCIPR13_UART7SEL_B_0X5				(0x5u<<24)
#define	RCC_CCIPR13_UART7SEL_B_0X6				(0x6u<<24)
#define	RCC_CCIPR13_USART6SEL_B_0X0				(0x0u<<20)
#define	RCC_CCIPR13_USART6SEL_B_0X1				(0x1u<<20)
#define	RCC_CCIPR13_USART6SEL_B_0X2				(0x2u<<20)
#define	RCC_CCIPR13_USART6SEL_B_0X3				(0x3u<<20)
#define	RCC_CCIPR13_USART6SEL_B_0X4				(0x4u<<20)
#define	RCC_CCIPR13_USART6SEL_B_0X5				(0x5u<<20)
#define	RCC_CCIPR13_USART6SEL_B_0X6				(0x6u<<20)
#define	RCC_CCIPR13_UART5SEL_B_0X0				(0x0u<<16)
#define	RCC_CCIPR13_UART5SEL_B_0X1				(0x1u<<16)
#define	RCC_CCIPR13_UART5SEL_B_0X2				(0x2u<<16)
#define	RCC_CCIPR13_UART5SEL_B_0X3				(0x3u<<16)
#define	RCC_CCIPR13_UART5SEL_B_0X4				(0x4u<<16)
#define	RCC_CCIPR13_UART5SEL_B_0X5				(0x5u<<16)
#define	RCC_CCIPR13_UART5SEL_B_0X6				(0x6u<<16)
#define	RCC_CCIPR13_UART4SEL_B_0X0				(0x0u<<12)
#define	RCC_CCIPR13_UART4SEL_B_0X1				(0x1u<<12)
#define	RCC_CCIPR13_UART4SEL_B_0X2				(0x2u<<12)
#define	RCC_CCIPR13_UART4SEL_B_0X3				(0x3u<<12)
#define	RCC_CCIPR13_UART4SEL_B_0X4				(0x4u<<12)
#define	RCC_CCIPR13_UART4SEL_B_0X5				(0x5u<<12)
#define	RCC_CCIPR13_UART4SEL_B_0X6				(0x6u<<12)
#define	RCC_CCIPR13_USART3SEL_B_0X0				(0x0u<<8)
#define	RCC_CCIPR13_USART3SEL_B_0X1				(0x1u<<8)
#define	RCC_CCIPR13_USART3SEL_B_0X2				(0x2u<<8)
#define	RCC_CCIPR13_USART3SEL_B_0X3				(0x3u<<8)
#define	RCC_CCIPR13_USART3SEL_B_0X4				(0x4u<<8)
#define	RCC_CCIPR13_USART3SEL_B_0X5				(0x5u<<8)
#define	RCC_CCIPR13_USART3SEL_B_0X6				(0x6u<<8)
#define	RCC_CCIPR13_USART2SEL_B_0X0				(0x0u<<4)
#define	RCC_CCIPR13_USART2SEL_B_0X1				(0x1u<<4)
#define	RCC_CCIPR13_USART2SEL_B_0X2				(0x2u<<4)
#define	RCC_CCIPR13_USART2SEL_B_0X3				(0x3u<<4)
#define	RCC_CCIPR13_USART2SEL_B_0X4				(0x4u<<4)
#define	RCC_CCIPR13_USART2SEL_B_0X5				(0x5u<<4)
#define	RCC_CCIPR13_USART2SEL_B_0X6				(0x6u<<4)
#define	RCC_CCIPR13_USART1SEL_B_0X0				(0x0u<<0)
#define	RCC_CCIPR13_USART1SEL_B_0X1				(0x1u<<0)
#define	RCC_CCIPR13_USART1SEL_B_0X2				(0x2u<<0)
#define	RCC_CCIPR13_USART1SEL_B_0X3				(0x3u<<0)
#define	RCC_CCIPR13_USART1SEL_B_0X4				(0x4u<<0)
#define	RCC_CCIPR13_USART1SEL_B_0X5				(0x5u<<0)
#define	RCC_CCIPR13_USART1SEL_B_0X6				(0x6u<<0)

// CCIPR14 Configuration

#define	RCC_CCIPR14_LPUART1SEL					(0x7u<<8)
#define	RCC_CCIPR14_LPUART1SEL_0				(0x1u<<8)
#define	RCC_CCIPR14_USART10SEL					(0x7u<<4)
#define	RCC_CCIPR14_USART10SEL_0				(0x1u<<4)
#define	RCC_CCIPR14_UART9SEL					(0x7u<<0)
#define	RCC_CCIPR14_UART9SEL_0					(0x1u<<0)

#define	RCC_CCIPR14_LPUART1SEL_B_0X0			(0x0u<<8)
#define	RCC_CCIPR14_LPUART1SEL_B_0X1			(0x1u<<8)
#define	RCC_CCIPR14_LPUART1SEL_B_0X2			(0x2u<<8)
#define	RCC_CCIPR14_LPUART1SEL_B_0X3			(0x3u<<8)
#define	RCC_CCIPR14_LPUART1SEL_B_0X4			(0x4u<<8)
#define	RCC_CCIPR14_LPUART1SEL_B_0X5			(0x5u<<8)
#define	RCC_CCIPR14_LPUART1SEL_B_0X6			(0x6u<<8)
#define	RCC_CCIPR14_USART10SEL_B_0X0			(0x0u<<4)
#define	RCC_CCIPR14_USART10SEL_B_0X1			(0x1u<<4)
#define	RCC_CCIPR14_USART10SEL_B_0X2			(0x2u<<4)
#define	RCC_CCIPR14_USART10SEL_B_0X3			(0x3u<<4)
#define	RCC_CCIPR14_USART10SEL_B_0X4			(0x4u<<4)
#define	RCC_CCIPR14_USART10SEL_B_0X5			(0x5u<<4)
#define	RCC_CCIPR14_USART10SEL_B_0X6			(0x6u<<4)
#define	RCC_CCIPR14_UART9SEL_B_0X0				(0x0u<<0)
#define	RCC_CCIPR14_UART9SEL_B_0X1				(0x1u<<0)
#define	RCC_CCIPR14_UART9SEL_B_0X2				(0x2u<<0)
#define	RCC_CCIPR14_UART9SEL_B_0X3				(0x3u<<0)
#define	RCC_CCIPR14_UART9SEL_B_0X4				(0x4u<<0)
#define	RCC_CCIPR14_UART9SEL_B_0X5				(0x5u<<0)
#define	RCC_CCIPR14_UART9SEL_B_0X6				(0x6u<<0)

// BUSRSTR Configuration

#define	RCC_BUSRSTR_NOCRST						(0x1u<<13)
#define	RCC_BUSRSTR_APB5RST						(0x1u<<12)
#define	RCC_BUSRSTR_APB4RST						(0x1u<<11)
#define	RCC_BUSRSTR_APB3RST						(0x1u<<10)
#define	RCC_BUSRSTR_APB2RST						(0x1u<<9)
#define	RCC_BUSRSTR_APB1RST						(0x1u<<8)
#define	RCC_BUSRSTR_AHB5RST						(0x1u<<7)
#define	RCC_BUSRSTR_AHB4RST						(0x1u<<6)
#define	RCC_BUSRSTR_AHB3RST						(0x1u<<5)
#define	RCC_BUSRSTR_AHB2RST						(0x1u<<4)
#define	RCC_BUSRSTR_AHB1RST						(0x1u<<3)
#define	RCC_BUSRSTR_AHBMRST						(0x1u<<2)
#define	RCC_BUSRSTR_ACLKNRST					(0x1u<<0)

#define	RCC_BUSRSTR_NOCRST_B_0X0				(0x0u<<13)
#define	RCC_BUSRSTR_NOCRST_B_0X1				(0x1u<<13)
#define	RCC_BUSRSTR_APB5RST_B_0X0				(0x0u<<12)
#define	RCC_BUSRSTR_APB5RST_B_0X1				(0x1u<<12)
#define	RCC_BUSRSTR_APB4RST_B_0X0				(0x0u<<11)
#define	RCC_BUSRSTR_APB4RST_B_0X1				(0x1u<<11)
#define	RCC_BUSRSTR_APB3RST_B_0X0				(0x0u<<10)
#define	RCC_BUSRSTR_APB3RST_B_0X1				(0x1u<<10)
#define	RCC_BUSRSTR_APB2RST_B_0X0				(0x0u<<9)
#define	RCC_BUSRSTR_APB2RST_B_0X1				(0x1u<<9)
#define	RCC_BUSRSTR_APB1RST_B_0X0				(0x0u<<8)
#define	RCC_BUSRSTR_APB1RST_B_0X1				(0x1u<<8)
#define	RCC_BUSRSTR_AHB5RST_B_0X0				(0x0u<<7)
#define	RCC_BUSRSTR_AHB5RST_B_0X1				(0x1u<<7)
#define	RCC_BUSRSTR_AHB4RST_B_0X0				(0x0u<<6)
#define	RCC_BUSRSTR_AHB4RST_B_0X1				(0x1u<<6)
#define	RCC_BUSRSTR_AHB3RST_B_0X0				(0x0u<<5)
#define	RCC_BUSRSTR_AHB3RST_B_0X1				(0x1u<<5)
#define	RCC_BUSRSTR_AHB2RST_B_0X0				(0x0u<<4)
#define	RCC_BUSRSTR_AHB2RST_B_0X1				(0x1u<<4)
#define	RCC_BUSRSTR_AHB1RST_B_0X0				(0x0u<<3)
#define	RCC_BUSRSTR_AHB1RST_B_0X1				(0x1u<<3)
#define	RCC_BUSRSTR_AHBMRST_B_0X0				(0x0u<<2)
#define	RCC_BUSRSTR_AHBMRST_B_0X1				(0x1u<<2)
#define	RCC_BUSRSTR_ACLKNRST_B_0X0				(0x0u<<0)
#define	RCC_BUSRSTR_ACLKNRST_B_0X1				(0x1u<<0)

// MISCRSTR Configuration

#define	RCC_MISCRSTR_SDMMC2DLLRST				(0x1u<<8)
#define	RCC_MISCRSTR_SDMMC1DLLRST				(0x1u<<7)
#define	RCC_MISCRSTR_XSPIPHY2RST				(0x1u<<5)
#define	RCC_MISCRSTR_XSPIPHY1RST				(0x1u<<4)
#define	RCC_MISCRSTR_DBGRST						(0x1u<<0)

#define	RCC_MISCRSTR_SDMMC2DLLRST_B_0X0			(0x0u<<8)
#define	RCC_MISCRSTR_SDMMC2DLLRST_B_0X1			(0x1u<<8)
#define	RCC_MISCRSTR_SDMMC1DLLRST_B_0X0			(0x0u<<7)
#define	RCC_MISCRSTR_SDMMC1DLLRST_B_0X1			(0x1u<<7)
#define	RCC_MISCRSTR_XSPIPHY2RST_B_0X0			(0x0u<<5)
#define	RCC_MISCRSTR_XSPIPHY2RST_B_0X1			(0x1u<<5)
#define	RCC_MISCRSTR_XSPIPHY1RST_B_0X0			(0x0u<<4)
#define	RCC_MISCRSTR_XSPIPHY1RST_B_0X1			(0x1u<<4)
#define	RCC_MISCRSTR_DBGRST_B_0X0				(0x0u<<0)
#define	RCC_MISCRSTR_DBGRST_B_0X1				(0x1u<<0)

// MEMRSTR Configuration

#define	RCC_MEMRSTR_BOOTROMRST					(0x1u<<12)
#define	RCC_MEMRSTR_VENCRAMRST					(0x1u<<11)
#define	RCC_MEMRSTR_NPUCACHERAMRST				(0x1u<<10)
#define	RCC_MEMRSTR_FLEXRAMRST					(0x1u<<9)
#define	RCC_MEMRSTR_AXISRAM2RST					(0x1u<<8)
#define	RCC_MEMRSTR_AXISRAM1RST					(0x1u<<7)
#define	RCC_MEMRSTR_AHBSRAM2RST					(0x1u<<5)
#define	RCC_MEMRSTR_AHBSRAM1RST					(0x1u<<4)
#define	RCC_MEMRSTR_AXISRAM6RST					(0x1u<<3)
#define	RCC_MEMRSTR_AXISRAM5RST					(0x1u<<2)
#define	RCC_MEMRSTR_AXISRAM4RST					(0x1u<<1)
#define	RCC_MEMRSTR_AXISRAM3RST					(0x1u<<0)

#define	RCC_MEMRSTR_BOOTROMRST_B_0X0			(0x0u<<12)
#define	RCC_MEMRSTR_BOOTROMRST_B_0X1			(0x1u<<12)
#define	RCC_MEMRSTR_VENCRAMRST_B_0X0			(0x0u<<11)
#define	RCC_MEMRSTR_VENCRAMRST_B_0X1			(0x1u<<11)
#define	RCC_MEMRSTR_NPUCACHERAMRST_B_0X0		(0x0u<<10)
#define	RCC_MEMRSTR_NPUCACHERAMRST_B_0X1		(0x1u<<10)
#define	RCC_MEMRSTR_FLEXRAMRST_B_0X0			(0x0u<<9)
#define	RCC_MEMRSTR_FLEXRAMRST_B_0X1			(0x1u<<9)
#define	RCC_MEMRSTR_AXISRAM2RST_B_0X0			(0x0u<<8)
#define	RCC_MEMRSTR_AXISRAM2RST_B_0X1			(0x1u<<8)
#define	RCC_MEMRSTR_AXISRAM1RST_B_0X0			(0x0u<<7)
#define	RCC_MEMRSTR_AXISRAM1RST_B_0X1			(0x1u<<7)
#define	RCC_MEMRSTR_AHBSRAM2RST_B_0X0			(0x0u<<5)
#define	RCC_MEMRSTR_AHBSRAM2RST_B_0X1			(0x1u<<5)
#define	RCC_MEMRSTR_AHBSRAM1RST_B_0X0			(0x0u<<4)
#define	RCC_MEMRSTR_AHBSRAM1RST_B_0X1			(0x1u<<4)
#define	RCC_MEMRSTR_AXISRAM6RST_B_0X0			(0x0u<<3)
#define	RCC_MEMRSTR_AXISRAM6RST_B_0X1			(0x1u<<3)
#define	RCC_MEMRSTR_AXISRAM5RST_B_0X0			(0x0u<<2)
#define	RCC_MEMRSTR_AXISRAM5RST_B_0X1			(0x1u<<2)
#define	RCC_MEMRSTR_AXISRAM4RST_B_0X0			(0x0u<<1)
#define	RCC_MEMRSTR_AXISRAM4RST_B_0X1			(0x1u<<1)
#define	RCC_MEMRSTR_AXISRAM3RST_B_0X0			(0x0u<<0)
#define	RCC_MEMRSTR_AXISRAM3RST_B_0X1			(0x1u<<0)

// AHB1RSTR Configuration

#define	RCC_AHB1RSTR_ADC12RST					(0x1u<<5)
#define	RCC_AHB1RSTR_GPDMA1RST					(0x1u<<4)

#define	RCC_AHB1RSTR_ADC12RST_B_0X0				(0x0u<<5)
#define	RCC_AHB1RSTR_ADC12RST_B_0X1				(0x1u<<5)
#define	RCC_AHB1RSTR_GPDMA1RST_B_0X0			(0x0u<<4)
#define	RCC_AHB1RSTR_GPDMA1RST_B_0X1			(0x1u<<4)

// AHB2RSTR Configuration

#define	RCC_AHB2RSTR_ADF1RST					(0x1u<<17)
#define	RCC_AHB2RSTR_MDF1RST					(0x1u<<16)
#define	RCC_AHB2RSTR_RAMCFGRST					(0x1u<<12)

#define	RCC_AHB2RSTR_ADF1RST_B_0X0				(0x0u<<17)
#define	RCC_AHB2RSTR_ADF1RST_B_0X1				(0x1u<<17)
#define	RCC_AHB2RSTR_MDF1RST_B_0X0				(0x0u<<16)
#define	RCC_AHB2RSTR_MDF1RST_B_0X1				(0x1u<<16)
#define	RCC_AHB2RSTR_RAMCFGRST_B_0X0			(0x0u<<12)
#define	RCC_AHB2RSTR_RAMCFGRST_B_0X1			(0x1u<<12)

// AHB3RSTR Configuration

#define	RCC_AHB3RSTR_IACRST						(0x1u<<10)
#define	RCC_AHB3RSTR_PKARST						(0x1u<<8)
#define	RCC_AHB3RSTR_SAESRST					(0x1u<<4)
#define	RCC_AHB3RSTR_CRYPRST					(0x1u<<2)
#define	RCC_AHB3RSTR_HASHRST					(0x1u<<1)
#define	RCC_AHB3RSTR_RNGRST						(0x1u<<0)

#define	RCC_AHB3RSTR_IACRST_B_0X0				(0x0u<<10)
#define	RCC_AHB3RSTR_IACRST_B_0X1				(0x1u<<10)
#define	RCC_AHB3RSTR_PKARST_B_0X0				(0x0u<<8)
#define	RCC_AHB3RSTR_PKARST_B_0X1				(0x1u<<8)
#define	RCC_AHB3RSTR_SAESRST_B_0X0				(0x0u<<4)
#define	RCC_AHB3RSTR_SAESRST_B_0X1				(0x1u<<4)
#define	RCC_AHB3RSTR_CRYPRST_B_0X0				(0x0u<<2)
#define	RCC_AHB3RSTR_CRYPRST_B_0X1				(0x1u<<2)
#define	RCC_AHB3RSTR_HASHRST_B_0X0				(0x0u<<1)
#define	RCC_AHB3RSTR_HASHRST_B_0X1				(0x1u<<1)
#define	RCC_AHB3RSTR_RNGRST_B_0X0				(0x0u<<0)
#define	RCC_AHB3RSTR_RNGRST_B_0X1				(0x1u<<0)

// AHB4RSTR Configuration

#define	RCC_AHB4RSTR_CRCRST						(0x1u<<19)
#define	RCC_AHB4RSTR_PWRRST						(0x1u<<18)
#define	RCC_AHB4RSTR_GPIOQRST					(0x1u<<16)
#define	RCC_AHB4RSTR_GPIOPRST					(0x1u<<15)
#define	RCC_AHB4RSTR_GPIOORST					(0x1u<<14)
#define	RCC_AHB4RSTR_GPIONRST					(0x1u<<13)
#define	RCC_AHB4RSTR_GPIOHRST					(0x1u<<7)
#define	RCC_AHB4RSTR_GPIOGRST					(0x1u<<6)
#define	RCC_AHB4RSTR_GPIOFRST					(0x1u<<5)
#define	RCC_AHB4RSTR_GPIOERST					(0x1u<<4)
#define	RCC_AHB4RSTR_GPIODRST					(0x1u<<3)
#define	RCC_AHB4RSTR_GPIOCRST					(0x1u<<2)
#define	RCC_AHB4RSTR_GPIOBRST					(0x1u<<1)
#define	RCC_AHB4RSTR_GPIOARST					(0x1u<<0)

#define	RCC_AHB4RSTR_CRCRST_B_0X0				(0x0u<<19)
#define	RCC_AHB4RSTR_CRCRST_B_0X1				(0x1u<<19)
#define	RCC_AHB4RSTR_PWRRST_B_0X0				(0x0u<<18)
#define	RCC_AHB4RSTR_PWRRST_B_0X1				(0x1u<<18)
#define	RCC_AHB4RSTR_GPIOQRST_B_0X0				(0x0u<<16)
#define	RCC_AHB4RSTR_GPIOQRST_B_0X1				(0x1u<<16)
#define	RCC_AHB4RSTR_GPIOPRST_B_0X0				(0x0u<<15)
#define	RCC_AHB4RSTR_GPIOPRST_B_0X1				(0x1u<<15)
#define	RCC_AHB4RSTR_GPIOORST_B_0X0				(0x0u<<14)
#define	RCC_AHB4RSTR_GPIOORST_B_0X1				(0x1u<<14)
#define	RCC_AHB4RSTR_GPIONRST_B_0X0				(0x0u<<13)
#define	RCC_AHB4RSTR_GPIONRST_B_0X1				(0x1u<<13)
#define	RCC_AHB4RSTR_GPIOHRST_B_0X0				(0x0u<<7)
#define	RCC_AHB4RSTR_GPIOHRST_B_0X1				(0x1u<<7)
#define	RCC_AHB4RSTR_GPIOGRST_B_0X0				(0x0u<<6)
#define	RCC_AHB4RSTR_GPIOGRST_B_0X1				(0x1u<<6)
#define	RCC_AHB4RSTR_GPIOFRST_B_0X0				(0x0u<<5)
#define	RCC_AHB4RSTR_GPIOFRST_B_0X1				(0x1u<<5)
#define	RCC_AHB4RSTR_GPIOERST_B_0X0				(0x0u<<4)
#define	RCC_AHB4RSTR_GPIOERST_B_0X1				(0x1u<<4)
#define	RCC_AHB4RSTR_GPIODRST_B_0X0				(0x0u<<3)
#define	RCC_AHB4RSTR_GPIODRST_B_0X1				(0x1u<<3)
#define	RCC_AHB4RSTR_GPIOCRST_B_0X0				(0x0u<<2)
#define	RCC_AHB4RSTR_GPIOCRST_B_0X1				(0x1u<<2)
#define	RCC_AHB4RSTR_GPIOBRST_B_0X0				(0x0u<<1)
#define	RCC_AHB4RSTR_GPIOBRST_B_0X1				(0x1u<<1)
#define	RCC_AHB4RSTR_GPIOARST_B_0X0				(0x0u<<0)
#define	RCC_AHB4RSTR_GPIOARST_B_0X1				(0x1u<<0)

// AHB5RSTR Configuration

#define	RCC_AHB5RSTR_NPURST						(0x1u<<31)
#define	RCC_AHB5RSTR_NPUCACHERST				(0x1u<<30)
#define	RCC_AHB5RSTR_OTG2RST					(0x1u<<29)
#define	RCC_AHB5RSTR_OTGPHY2RST					(0x1u<<28)
#define	RCC_AHB5RSTR_OTGPHY1RST					(0x1u<<27)
#define	RCC_AHB5RSTR_OTG1RST					(0x1u<<26)
#define	RCC_AHB5RSTR_ETH1RST					(0x1u<<25)
#define	RCC_AHB5RSTR_SYSCFGOTGHSPHY2RST			(0x1u<<24)
#define	RCC_AHB5RSTR_SYSCFGOTGHSPHY1RST			(0x1u<<23)
#define	RCC_AHB5RSTR_GPURST						(0x1u<<20)
#define	RCC_AHB5RSTR_GFXMMURST					(0x1u<<19)
#define	RCC_AHB5RSTR_MCE4RST					(0x1u<<18)
#define	RCC_AHB5RSTR_XSPI3RST					(0x1u<<17)
#define	RCC_AHB5RSTR_XSPIMRST					(0x1u<<13)
#define	RCC_AHB5RSTR_XSPI2RST					(0x1u<<12)
#define	RCC_AHB5RSTR_SDMMC1RST					(0x1u<<8)
#define	RCC_AHB5RSTR_SDMMC2RST					(0x1u<<7)
#define	RCC_AHB5RSTR_PSSIRST					(0x1u<<6)
#define	RCC_AHB5RSTR_XSPI1RST					(0x1u<<5)
#define	RCC_AHB5RSTR_FMCRST						(0x1u<<4)
#define	RCC_AHB5RSTR_JPEGRST					(0x1u<<3)
#define	RCC_AHB5RSTR_DMA2DRST					(0x1u<<1)
#define	RCC_AHB5RSTR_HPDMA1RST					(0x1u<<0)

#define	RCC_AHB5RSTR_NPURST_B_0X0				(0x0u<<31)
#define	RCC_AHB5RSTR_NPURST_B_0X1				(0x1u<<31)
#define	RCC_AHB5RSTR_NPUCACHERST_B_0X0			(0x0u<<30)
#define	RCC_AHB5RSTR_NPUCACHERST_B_0X1			(0x1u<<30)
#define	RCC_AHB5RSTR_OTG2RST_B_0X0				(0x0u<<29)
#define	RCC_AHB5RSTR_OTG2RST_B_0X1				(0x1u<<29)
#define	RCC_AHB5RSTR_OTGPHY2RST_B_0X0			(0x0u<<28)
#define	RCC_AHB5RSTR_OTGPHY2RST_B_0X1			(0x1u<<28)
#define	RCC_AHB5RSTR_OTGPHY1RST_B_0X0			(0x0u<<27)
#define	RCC_AHB5RSTR_OTGPHY1RST_B_0X1			(0x1u<<27)
#define	RCC_AHB5RSTR_OTG1RST_B_0X0				(0x0u<<26)
#define	RCC_AHB5RSTR_OTG1RST_B_0X1				(0x1u<<26)
#define	RCC_AHB5RSTR_ETH1RST_B_0X0				(0x0u<<25)
#define	RCC_AHB5RSTR_ETH1RST_B_0X1				(0x1u<<25)
#define	RCC_AHB5RSTR_SYSCFGOTGHSPHY2RST_B_0X0	(0x0u<<24)
#define	RCC_AHB5RSTR_SYSCFGOTGHSPHY2RST_B_0X1	(0x1u<<24)
#define	RCC_AHB5RSTR_SYSCFGOTGHSPHY1RST_B_0X0	(0x0u<<23)
#define	RCC_AHB5RSTR_SYSCFGOTGHSPHY1RST_B_0X1	(0x1u<<23)
#define	RCC_AHB5RSTR_GPURST_B_0X0				(0x0u<<20)
#define	RCC_AHB5RSTR_GPURST_B_0X1				(0x1u<<20)
#define	RCC_AHB5RSTR_GFXMMURST_B_0X0			(0x0u<<19)
#define	RCC_AHB5RSTR_GFXMMURST_B_0X1			(0x1u<<19)
#define	RCC_AHB5RSTR_MCE4RST_B_0X0				(0x0u<<18)
#define	RCC_AHB5RSTR_MCE4RST_B_0X1				(0x1u<<18)
#define	RCC_AHB5RSTR_XSPI3RST_B_0X0				(0x0u<<17)
#define	RCC_AHB5RSTR_XSPI3RST_B_0X1				(0x1u<<17)
#define	RCC_AHB5RSTR_XSPIMRST_B_0X0				(0x0u<<13)
#define	RCC_AHB5RSTR_XSPIMRST_B_0X1				(0x1u<<13)
#define	RCC_AHB5RSTR_XSPI2RST_B_0X0				(0x0u<<12)
#define	RCC_AHB5RSTR_XSPI2RST_B_0X1				(0x1u<<12)
#define	RCC_AHB5RSTR_SDMMC1RST_B_0X0			(0x0u<<8)
#define	RCC_AHB5RSTR_SDMMC1RST_B_0X1			(0x1u<<8)
#define	RCC_AHB5RSTR_SDMMC2RST_B_0X0			(0x0u<<7)
#define	RCC_AHB5RSTR_SDMMC2RST_B_0X1			(0x1u<<7)
#define	RCC_AHB5RSTR_PSSIRST_B_0X0				(0x0u<<6)
#define	RCC_AHB5RSTR_PSSIRST_B_0X1				(0x1u<<6)
#define	RCC_AHB5RSTR_XSPI1RST_B_0X0				(0x0u<<5)
#define	RCC_AHB5RSTR_XSPI1RST_B_0X1				(0x1u<<5)
#define	RCC_AHB5RSTR_FMCRST_B_0X0				(0x0u<<4)
#define	RCC_AHB5RSTR_FMCRST_B_0X1				(0x1u<<4)
#define	RCC_AHB5RSTR_JPEGRST_B_0X0				(0x0u<<3)
#define	RCC_AHB5RSTR_JPEGRST_B_0X1				(0x1u<<3)
#define	RCC_AHB5RSTR_DMA2DRST_B_0X0				(0x0u<<1)
#define	RCC_AHB5RSTR_DMA2DRST_B_0X1				(0x1u<<1)
#define	RCC_AHB5RSTR_HPDMA1RST_B_0X0			(0x0u<<0)
#define	RCC_AHB5RSTR_HPDMA1RST_B_0X1			(0x1u<<0)

// APB1LRSTR Configuration

#define	RCC_APB1LRSTR_UART8RST					(0x1u<<31)
#define	RCC_APB1LRSTR_UART7RST					(0x1u<<30)
#define	RCC_APB1LRSTR_I3C2RST					(0x1u<<25)
#define	RCC_APB1LRSTR_I3C1RST					(0x1u<<24)
#define	RCC_APB1LRSTR_I2C3RST					(0x1u<<23)
#define	RCC_APB1LRSTR_I2C2RST					(0x1u<<22)
#define	RCC_APB1LRSTR_I2C1RST					(0x1u<<21)
#define	RCC_APB1LRSTR_UART5RST					(0x1u<<20)
#define	RCC_APB1LRSTR_UART4RST					(0x1u<<19)
#define	RCC_APB1LRSTR_USART3RST					(0x1u<<18)
#define	RCC_APB1LRSTR_USART2RST					(0x1u<<17)
#define	RCC_APB1LRSTR_SPDIFRX1RST				(0x1u<<16)
#define	RCC_APB1LRSTR_SPI3RST					(0x1u<<15)
#define	RCC_APB1LRSTR_SPI2RST					(0x1u<<14)
#define	RCC_APB1LRSTR_TIM11RST					(0x1u<<13)
#define	RCC_APB1LRSTR_TIM10RST					(0x1u<<12)
#define	RCC_APB1LRSTR_WWDGRST					(0x1u<<11)
#define	RCC_APB1LRSTR_LPTIM1RST					(0x1u<<9)
#define	RCC_APB1LRSTR_TIM14RST					(0x1u<<8)
#define	RCC_APB1LRSTR_TIM13RST					(0x1u<<7)
#define	RCC_APB1LRSTR_TIM12RST					(0x1u<<6)
#define	RCC_APB1LRSTR_TIM7RST					(0x1u<<5)
#define	RCC_APB1LRSTR_TIM6RST					(0x1u<<4)
#define	RCC_APB1LRSTR_TIM5RST					(0x1u<<3)
#define	RCC_APB1LRSTR_TIM4RST					(0x1u<<2)
#define	RCC_APB1LRSTR_TIM3RST					(0x1u<<1)
#define	RCC_APB1LRSTR_TIM2RST					(0x1u<<0)

#define	RCC_APB1LRSTR_UART8RST_B_0X0			(0x0u<<31)
#define	RCC_APB1LRSTR_UART8RST_B_0X1			(0x1u<<31)
#define	RCC_APB1LRSTR_UART7RST_B_0X0			(0x0u<<30)
#define	RCC_APB1LRSTR_UART7RST_B_0X1			(0x1u<<30)
#define	RCC_APB1LRSTR_I3C2RST_B_0X0				(0x0u<<25)
#define	RCC_APB1LRSTR_I3C2RST_B_0X1				(0x1u<<25)
#define	RCC_APB1LRSTR_I3C1RST_B_0X0				(0x0u<<24)
#define	RCC_APB1LRSTR_I3C1RST_B_0X1				(0x1u<<24)
#define	RCC_APB1LRSTR_I2C3RST_B_0X0				(0x0u<<23)
#define	RCC_APB1LRSTR_I2C3RST_B_0X1				(0x1u<<23)
#define	RCC_APB1LRSTR_I2C2RST_B_0X0				(0x0u<<22)
#define	RCC_APB1LRSTR_I2C2RST_B_0X1				(0x1u<<22)
#define	RCC_APB1LRSTR_I2C1RST_B_0X0				(0x0u<<21)
#define	RCC_APB1LRSTR_I2C1RST_B_0X1				(0x1u<<21)
#define	RCC_APB1LRSTR_UART5RST_B_0X0			(0x0u<<20)
#define	RCC_APB1LRSTR_UART5RST_B_0X1			(0x1u<<20)
#define	RCC_APB1LRSTR_UART4RST_B_0X0			(0x0u<<19)
#define	RCC_APB1LRSTR_UART4RST_B_0X1			(0x1u<<19)
#define	RCC_APB1LRSTR_USART3RST_B_0X0			(0x0u<<18)
#define	RCC_APB1LRSTR_USART3RST_B_0X1			(0x1u<<18)
#define	RCC_APB1LRSTR_USART2RST_B_0X0			(0x0u<<17)
#define	RCC_APB1LRSTR_USART2RST_B_0X1			(0x1u<<17)
#define	RCC_APB1LRSTR_SPDIFRX1RST_B_0X0			(0x0u<<16)
#define	RCC_APB1LRSTR_SPDIFRX1RST_B_0X1			(0x1u<<16)
#define	RCC_APB1LRSTR_SPI3RST_B_0X0				(0x0u<<15)
#define	RCC_APB1LRSTR_SPI3RST_B_0X1				(0x1u<<15)
#define	RCC_APB1LRSTR_SPI2RST_B_0X0				(0x0u<<14)
#define	RCC_APB1LRSTR_SPI2RST_B_0X1				(0x1u<<14)
#define	RCC_APB1LRSTR_TIM11RST_B_0X0			(0x0u<<13)
#define	RCC_APB1LRSTR_TIM11RST_B_0X1			(0x1u<<13)
#define	RCC_APB1LRSTR_TIM10RST_B_0X0			(0x0u<<12)
#define	RCC_APB1LRSTR_TIM10RST_B_0X1			(0x1u<<12)
#define	RCC_APB1LRSTR_WWDGRST_B_0X0				(0x0u<<11)
#define	RCC_APB1LRSTR_WWDGRST_B_0X1				(0x1u<<11)
#define	RCC_APB1LRSTR_LPTIM1RST_B_0X0			(0x0u<<9)
#define	RCC_APB1LRSTR_LPTIM1RST_B_0X1			(0x1u<<9)
#define	RCC_APB1LRSTR_TIM14RST_B_0X0			(0x0u<<8)
#define	RCC_APB1LRSTR_TIM14RST_B_0X1			(0x1u<<8)
#define	RCC_APB1LRSTR_TIM13RST_B_0X0			(0x0u<<7)
#define	RCC_APB1LRSTR_TIM13RST_B_0X1			(0x1u<<7)
#define	RCC_APB1LRSTR_TIM12RST_B_0X0			(0x0u<<6)
#define	RCC_APB1LRSTR_TIM12RST_B_0X1			(0x1u<<6)
#define	RCC_APB1LRSTR_TIM7RST_B_0X0				(0x0u<<5)
#define	RCC_APB1LRSTR_TIM7RST_B_0X1				(0x1u<<5)
#define	RCC_APB1LRSTR_TIM6RST_B_0X0				(0x0u<<4)
#define	RCC_APB1LRSTR_TIM6RST_B_0X1				(0x1u<<4)
#define	RCC_APB1LRSTR_TIM5RST_B_0X0				(0x0u<<3)
#define	RCC_APB1LRSTR_TIM5RST_B_0X1				(0x1u<<3)
#define	RCC_APB1LRSTR_TIM4RST_B_0X0				(0x0u<<2)
#define	RCC_APB1LRSTR_TIM4RST_B_0X1				(0x1u<<2)
#define	RCC_APB1LRSTR_TIM3RST_B_0X0				(0x0u<<1)
#define	RCC_APB1LRSTR_TIM3RST_B_0X1				(0x1u<<1)
#define	RCC_APB1LRSTR_TIM2RST_B_0X0				(0x0u<<0)
#define	RCC_APB1LRSTR_TIM2RST_B_0X1				(0x1u<<0)

// APB1HRSTR Configuration

#define	RCC_APB1HRSTR_UCPD1RST					(0x1u<<18)
#define	RCC_APB1HRSTR_FDCANRST					(0x1u<<8)
#define	RCC_APB1HRSTR_MDIOSRST					(0x1u<<5)

#define	RCC_APB1HRSTR_UCPD1RST_B_0X0			(0x0u<<18)
#define	RCC_APB1HRSTR_UCPD1RST_B_0X1			(0x1u<<18)
#define	RCC_APB1HRSTR_FDCANRST_B_0X0			(0x0u<<8)
#define	RCC_APB1HRSTR_FDCANRST_B_0X1			(0x1u<<8)
#define	RCC_APB1HRSTR_MDIOSRST_B_0X0			(0x0u<<5)
#define	RCC_APB1HRSTR_MDIOSRST_B_0X1			(0x1u<<5)

// APB2RSTR Configuration

#define	RCC_APB2RSTR_SAI2RST					(0x1u<<22)
#define	RCC_APB2RSTR_SAI1RST					(0x1u<<21)
#define	RCC_APB2RSTR_SPI5RST					(0x1u<<20)
#define	RCC_APB2RSTR_TIM9RST					(0x1u<<19)
#define	RCC_APB2RSTR_TIM17RST					(0x1u<<18)
#define	RCC_APB2RSTR_TIM16RST					(0x1u<<17)
#define	RCC_APB2RSTR_TIM15RST					(0x1u<<16)
#define	RCC_APB2RSTR_TIM18RST					(0x1u<<15)
#define	RCC_APB2RSTR_SPI4RST					(0x1u<<13)
#define	RCC_APB2RSTR_SPI1RST					(0x1u<<12)
#define	RCC_APB2RSTR_USART10RST					(0x1u<<7)
#define	RCC_APB2RSTR_UART9RST					(0x1u<<6)
#define	RCC_APB2RSTR_USART6RST					(0x1u<<5)
#define	RCC_APB2RSTR_USART1RST					(0x1u<<4)
#define	RCC_APB2RSTR_TIM8RST					(0x1u<<1)
#define	RCC_APB2RSTR_TIM1RST					(0x1u<<0)

#define	RCC_APB2RSTR_SAI2RST_B_0X0				(0x0u<<22)
#define	RCC_APB2RSTR_SAI2RST_B_0X1				(0x1u<<22)
#define	RCC_APB2RSTR_SAI1RST_B_0X0				(0x0u<<21)
#define	RCC_APB2RSTR_SAI1RST_B_0X1				(0x1u<<21)
#define	RCC_APB2RSTR_SPI5RST_B_0X0				(0x0u<<20)
#define	RCC_APB2RSTR_SPI5RST_B_0X1				(0x1u<<20)
#define	RCC_APB2RSTR_TIM9RST_B_0X0				(0x0u<<19)
#define	RCC_APB2RSTR_TIM9RST_B_0X1				(0x1u<<19)
#define	RCC_APB2RSTR_TIM17RST_B_0X0				(0x0u<<18)
#define	RCC_APB2RSTR_TIM17RST_B_0X1				(0x1u<<18)
#define	RCC_APB2RSTR_TIM16RST_B_0X0				(0x0u<<17)
#define	RCC_APB2RSTR_TIM16RST_B_0X1				(0x1u<<17)
#define	RCC_APB2RSTR_TIM15RST_B_0X0				(0x0u<<16)
#define	RCC_APB2RSTR_TIM15RST_B_0X1				(0x1u<<16)
#define	RCC_APB2RSTR_TIM18RST_B_0X0				(0x0u<<15)
#define	RCC_APB2RSTR_TIM18RST_B_0X1				(0x1u<<15)
#define	RCC_APB2RSTR_SPI4RST_B_0X0				(0x0u<<13)
#define	RCC_APB2RSTR_SPI4RST_B_0X1				(0x1u<<13)
#define	RCC_APB2RSTR_SPI1RST_B_0X0				(0x0u<<12)
#define	RCC_APB2RSTR_SPI1RST_B_0X1				(0x1u<<12)
#define	RCC_APB2RSTR_USART10RST_B_0X0			(0x0u<<7)
#define	RCC_APB2RSTR_USART10RST_B_0X1			(0x1u<<7)
#define	RCC_APB2RSTR_UART9RST_B_0X0				(0x0u<<6)
#define	RCC_APB2RSTR_UART9RST_B_0X1				(0x1u<<6)
#define	RCC_APB2RSTR_USART6RST_B_0X0			(0x0u<<5)
#define	RCC_APB2RSTR_USART6RST_B_0X1			(0x1u<<5)
#define	RCC_APB2RSTR_USART1RST_B_0X0			(0x0u<<4)
#define	RCC_APB2RSTR_USART1RST_B_0X1			(0x1u<<4)
#define	RCC_APB2RSTR_TIM8RST_B_0X0				(0x0u<<1)
#define	RCC_APB2RSTR_TIM8RST_B_0X1				(0x1u<<1)
#define	RCC_APB2RSTR_TIM1RST_B_0X0				(0x0u<<0)
#define	RCC_APB2RSTR_TIM1RST_B_0X1				(0x1u<<0)

// APB4LRSTR Configuration

#define	RCC_APB4LRSTR_SERFRST					(0x1u<<31)
#define	RCC_APB4LRSTR_R2GNPURST					(0x1u<<23)
#define	RCC_APB4LRSTR_R2GRETRST					(0x1u<<22)
#define	RCC_APB4LRSTR_RTCRST					(0x1u<<16)
#define	RCC_APB4LRSTR_VREFBUFRST				(0x1u<<15)
#define	RCC_APB4LRSTR_LPTIM5RST					(0x1u<<12)
#define	RCC_APB4LRSTR_LPTIM4RST					(0x1u<<11)
#define	RCC_APB4LRSTR_LPTIM3RST					(0x1u<<10)
#define	RCC_APB4LRSTR_LPTIM2RST					(0x1u<<9)
#define	RCC_APB4LRSTR_I2C4RST					(0x1u<<7)
#define	RCC_APB4LRSTR_SPI6RST					(0x1u<<5)
#define	RCC_APB4LRSTR_LPUART1RST				(0x1u<<3)
#define	RCC_APB4LRSTR_HDPRST					(0x1u<<2)

#define	RCC_APB4LRSTR_SERFRST_B_0X0				(0x0u<<31)
#define	RCC_APB4LRSTR_SERFRST_B_0X1				(0x1u<<31)
#define	RCC_APB4LRSTR_R2GNPURST_B_0X0			(0x0u<<23)
#define	RCC_APB4LRSTR_R2GNPURST_B_0X1			(0x1u<<23)
#define	RCC_APB4LRSTR_R2GRETRST_B_0X0			(0x0u<<22)
#define	RCC_APB4LRSTR_R2GRETRST_B_0X1			(0x1u<<22)
#define	RCC_APB4LRSTR_RTCRST_B_0X0				(0x0u<<16)
#define	RCC_APB4LRSTR_RTCRST_B_0X1				(0x1u<<16)
#define	RCC_APB4LRSTR_VREFBUFRST_B_0X0			(0x0u<<15)
#define	RCC_APB4LRSTR_VREFBUFRST_B_0X1			(0x1u<<15)
#define	RCC_APB4LRSTR_LPTIM5RST_B_0X0			(0x0u<<12)
#define	RCC_APB4LRSTR_LPTIM5RST_B_0X1			(0x1u<<12)
#define	RCC_APB4LRSTR_LPTIM4RST_B_0X0			(0x0u<<11)
#define	RCC_APB4LRSTR_LPTIM4RST_B_0X1			(0x1u<<11)
#define	RCC_APB4LRSTR_LPTIM3RST_B_0X0			(0x0u<<10)
#define	RCC_APB4LRSTR_LPTIM3RST_B_0X1			(0x1u<<10)
#define	RCC_APB4LRSTR_LPTIM2RST_B_0X0			(0x0u<<9)
#define	RCC_APB4LRSTR_LPTIM2RST_B_0X1			(0x1u<<9)
#define	RCC_APB4LRSTR_I2C4RST_B_0X0				(0x0u<<7)
#define	RCC_APB4LRSTR_I2C4RST_B_0X1				(0x1u<<7)
#define	RCC_APB4LRSTR_SPI6RST_B_0X0				(0x0u<<5)
#define	RCC_APB4LRSTR_SPI6RST_B_0X1				(0x1u<<5)
#define	RCC_APB4LRSTR_LPUART1RST_B_0X0			(0x0u<<3)
#define	RCC_APB4LRSTR_LPUART1RST_B_0X1			(0x1u<<3)
#define	RCC_APB4LRSTR_HDPRST_B_0X0				(0x0u<<2)
#define	RCC_APB4LRSTR_HDPRST_B_0X1				(0x1u<<2)

// APB4HRSTR Configuration

#define	RCC_APB4HRSTR_BUSPERFMRST				(0x1u<<4)
#define	RCC_APB4HRSTR_DTSRST					(0x1u<<2)
#define	RCC_APB4HRSTR_SYSCFGRST					(0x1u<<0)

#define	RCC_APB4HRSTR_BUSPERFMRST_B_0X0			(0x0u<<4)
#define	RCC_APB4HRSTR_BUSPERFMRST_B_0X1			(0x1u<<4)
#define	RCC_APB4HRSTR_DTSRST_B_0X0				(0x0u<<2)
#define	RCC_APB4HRSTR_DTSRST_B_0X1				(0x1u<<2)
#define	RCC_APB4HRSTR_SYSCFGRST_B_0X0			(0x0u<<0)
#define	RCC_APB4HRSTR_SYSCFGRST_B_0X1			(0x1u<<0)

// APB5RSTR Configuration

#define	RCC_APB5RSTR_CSIRST						(0x1u<<6)
#define	RCC_APB5RSTR_VENCRST					(0x1u<<5)
#define	RCC_APB5RSTR_GFXTIMRST					(0x1u<<4)
#define	RCC_APB5RSTR_DCMIPPRST					(0x1u<<2)
#define	RCC_APB5RSTR_LTDCRST					(0x1u<<1)

#define	RCC_APB5RSTR_CSIRST_B_0X0				(0x0u<<6)
#define	RCC_APB5RSTR_CSIRST_B_0X1				(0x1u<<6)
#define	RCC_APB5RSTR_VENCRST_B_0X0				(0x0u<<5)
#define	RCC_APB5RSTR_VENCRST_B_0X1				(0x1u<<5)
#define	RCC_APB5RSTR_GFXTIMRST_B_0X0			(0x0u<<4)
#define	RCC_APB5RSTR_GFXTIMRST_B_0X1			(0x1u<<4)
#define	RCC_APB5RSTR_DCMIPPRST_B_0X0			(0x0u<<2)
#define	RCC_APB5RSTR_DCMIPPRST_B_0X1			(0x1u<<2)
#define	RCC_APB5RSTR_LTDCRST_B_0X0				(0x0u<<1)
#define	RCC_APB5RSTR_LTDCRST_B_0X1				(0x1u<<1)

// DIVENR Configuration

#define	RCC_DIVENR_IC20EN						(0x1u<<19)
#define	RCC_DIVENR_IC19EN						(0x1u<<18)
#define	RCC_DIVENR_IC18EN						(0x1u<<17)
#define	RCC_DIVENR_IC17EN						(0x1u<<16)
#define	RCC_DIVENR_IC16EN						(0x1u<<15)
#define	RCC_DIVENR_IC15EN						(0x1u<<14)
#define	RCC_DIVENR_IC14EN						(0x1u<<13)
#define	RCC_DIVENR_IC13EN						(0x1u<<12)
#define	RCC_DIVENR_IC12EN						(0x1u<<11)
#define	RCC_DIVENR_IC11EN						(0x1u<<10)
#define	RCC_DIVENR_IC10EN						(0x1u<<9)
#define	RCC_DIVENR_IC9EN						(0x1u<<8)
#define	RCC_DIVENR_IC8EN						(0x1u<<7)
#define	RCC_DIVENR_IC7EN						(0x1u<<6)
#define	RCC_DIVENR_IC6EN						(0x1u<<5)
#define	RCC_DIVENR_IC5EN						(0x1u<<4)
#define	RCC_DIVENR_IC4EN						(0x1u<<3)
#define	RCC_DIVENR_IC3EN						(0x1u<<2)
#define	RCC_DIVENR_IC2EN						(0x1u<<1)
#define	RCC_DIVENR_IC1EN						(0x1u<<0)

#define	RCC_DIVENR_IC20EN_B_0X0					(0x0u<<19)
#define	RCC_DIVENR_IC20EN_B_0X1					(0x1u<<19)
#define	RCC_DIVENR_IC19EN_B_0X0					(0x0u<<18)
#define	RCC_DIVENR_IC19EN_B_0X1					(0x1u<<18)
#define	RCC_DIVENR_IC18EN_B_0X0					(0x0u<<17)
#define	RCC_DIVENR_IC18EN_B_0X1					(0x1u<<17)
#define	RCC_DIVENR_IC17EN_B_0X0					(0x0u<<16)
#define	RCC_DIVENR_IC17EN_B_0X1					(0x1u<<16)
#define	RCC_DIVENR_IC16EN_B_0X0					(0x0u<<15)
#define	RCC_DIVENR_IC16EN_B_0X1					(0x1u<<15)
#define	RCC_DIVENR_IC15EN_B_0X0					(0x0u<<14)
#define	RCC_DIVENR_IC15EN_B_0X1					(0x1u<<14)
#define	RCC_DIVENR_IC14EN_B_0X0					(0x0u<<13)
#define	RCC_DIVENR_IC14EN_B_0X1					(0x1u<<13)
#define	RCC_DIVENR_IC13EN_B_0X0					(0x0u<<12)
#define	RCC_DIVENR_IC13EN_B_0X1					(0x1u<<12)
#define	RCC_DIVENR_IC12EN_B_0X0					(0x0u<<11)
#define	RCC_DIVENR_IC12EN_B_0X1					(0x1u<<11)
#define	RCC_DIVENR_IC11EN_B_0X0					(0x0u<<10)
#define	RCC_DIVENR_IC11EN_B_0X1					(0x1u<<10)
#define	RCC_DIVENR_IC10EN_B_0X0					(0x0u<<9)
#define	RCC_DIVENR_IC10EN_B_0X1					(0x1u<<9)
#define	RCC_DIVENR_IC9EN_B_0X0					(0x0u<<8)
#define	RCC_DIVENR_IC9EN_B_0X1					(0x1u<<8)
#define	RCC_DIVENR_IC8EN_B_0X0					(0x0u<<7)
#define	RCC_DIVENR_IC8EN_B_0X1					(0x1u<<7)
#define	RCC_DIVENR_IC7EN_B_0X0					(0x0u<<6)
#define	RCC_DIVENR_IC7EN_B_0X1					(0x1u<<6)
#define	RCC_DIVENR_IC6EN_B_0X0					(0x0u<<5)
#define	RCC_DIVENR_IC6EN_B_0X1					(0x1u<<5)
#define	RCC_DIVENR_IC5EN_B_0X0					(0x0u<<4)
#define	RCC_DIVENR_IC5EN_B_0X1					(0x1u<<4)
#define	RCC_DIVENR_IC4EN_B_0X0					(0x0u<<3)
#define	RCC_DIVENR_IC4EN_B_0X1					(0x1u<<3)
#define	RCC_DIVENR_IC3EN_B_0X0					(0x0u<<2)
#define	RCC_DIVENR_IC3EN_B_0X1					(0x1u<<2)
#define	RCC_DIVENR_IC2EN_B_0X0					(0x0u<<1)
#define	RCC_DIVENR_IC2EN_B_0X1					(0x1u<<1)
#define	RCC_DIVENR_IC1EN_B_0X0					(0x0u<<0)
#define	RCC_DIVENR_IC1EN_B_0X1					(0x1u<<0)

// BUSENR Configuration

#define	RCC_BUSENR_APB5EN						(0x1u<<12)
#define	RCC_BUSENR_APB4EN						(0x1u<<11)
#define	RCC_BUSENR_APB3EN						(0x1u<<10)
#define	RCC_BUSENR_APB2EN						(0x1u<<9)
#define	RCC_BUSENR_APB1EN						(0x1u<<8)
#define	RCC_BUSENR_AHB5EN						(0x1u<<7)
#define	RCC_BUSENR_AHB4EN						(0x1u<<6)
#define	RCC_BUSENR_AHB3EN						(0x1u<<5)
#define	RCC_BUSENR_AHB2EN						(0x1u<<4)
#define	RCC_BUSENR_AHB1EN						(0x1u<<3)
#define	RCC_BUSENR_AHBMEN						(0x1u<<2)
#define	RCC_BUSENR_ACLKNCEN						(0x1u<<1)
#define	RCC_BUSENR_ACLKNEN						(0x1u<<0)

#define	RCC_BUSENR_APB5EN_B_0X0					(0x0u<<12)
#define	RCC_BUSENR_APB5EN_B_0X1					(0x1u<<12)
#define	RCC_BUSENR_APB4EN_B_0X0					(0x0u<<11)
#define	RCC_BUSENR_APB4EN_B_0X1					(0x1u<<11)
#define	RCC_BUSENR_APB3EN_B_0X0					(0x0u<<10)
#define	RCC_BUSENR_APB3EN_B_0X1					(0x1u<<10)
#define	RCC_BUSENR_APB2EN_B_0X0					(0x0u<<9)
#define	RCC_BUSENR_APB2EN_B_0X1					(0x1u<<9)
#define	RCC_BUSENR_APB1EN_B_0X0					(0x0u<<8)
#define	RCC_BUSENR_APB1EN_B_0X1					(0x1u<<8)
#define	RCC_BUSENR_AHB5EN_B_0X0					(0x0u<<7)
#define	RCC_BUSENR_AHB5EN_B_0X1					(0x1u<<7)
#define	RCC_BUSENR_AHB4EN_B_0X0					(0x0u<<6)
#define	RCC_BUSENR_AHB4EN_B_0X1					(0x1u<<6)
#define	RCC_BUSENR_AHB3EN_B_0X0					(0x0u<<5)
#define	RCC_BUSENR_AHB3EN_B_0X1					(0x1u<<5)
#define	RCC_BUSENR_AHB2EN_B_0X0					(0x0u<<4)
#define	RCC_BUSENR_AHB2EN_B_0X1					(0x1u<<4)
#define	RCC_BUSENR_AHB1EN_B_0X0					(0x0u<<3)
#define	RCC_BUSENR_AHB1EN_B_0X1					(0x1u<<3)
#define	RCC_BUSENR_AHBMEN_B_0X0					(0x0u<<2)
#define	RCC_BUSENR_AHBMEN_B_0X1					(0x1u<<2)
#define	RCC_BUSENR_ACLKNCEN_B_0X0				(0x0u<<1)
#define	RCC_BUSENR_ACLKNCEN_B_0X1				(0x1u<<1)
#define	RCC_BUSENR_ACLKNEN_B_0X0				(0x0u<<0)
#define	RCC_BUSENR_ACLKNEN_B_0X1				(0x1u<<0)

// MISCENR Configuration

#define	RCC_MISCENR_PEREN						(0x1u<<6)
#define	RCC_MISCENR_XSPIPHYCOMPEN				(0x1u<<3)
#define	RCC_MISCENR_MCO2EN						(0x1u<<2)
#define	RCC_MISCENR_MCO1EN						(0x1u<<1)
#define	RCC_MISCENR_DBGEN						(0x1u<<0)

#define	RCC_MISCENR_PEREN_B_0X0					(0x0u<<6)
#define	RCC_MISCENR_PEREN_B_0X1					(0x1u<<6)
#define	RCC_MISCENR_XSPIPHYCOMPEN_B_0X0			(0x0u<<3)
#define	RCC_MISCENR_XSPIPHYCOMPEN_B_0X1			(0x1u<<3)
#define	RCC_MISCENR_MCO2EN_B_0X0				(0x0u<<2)
#define	RCC_MISCENR_MCO2EN_B_0X1				(0x1u<<2)
#define	RCC_MISCENR_MCO1EN_B_0X0				(0x0u<<1)
#define	RCC_MISCENR_MCO1EN_B_0X1				(0x1u<<1)
#define	RCC_MISCENR_DBGEN_B_0X0					(0x0u<<0)
#define	RCC_MISCENR_DBGEN_B_0X1					(0x1u<<0)

// MEMENR Configuration

#define	RCC_MEMENR_BOOTROMEN					(0x1u<<12)
#define	RCC_MEMENR_VENCRAMEN					(0x1u<<11)
#define	RCC_MEMENR_NPUCACHERAMEN				(0x1u<<10)
#define	RCC_MEMENR_FLEXRAMEN					(0x1u<<9)
#define	RCC_MEMENR_AXISRAM2EN					(0x1u<<8)
#define	RCC_MEMENR_AXISRAM1EN					(0x1u<<7)
#define	RCC_MEMENR_BKPSRAMEN					(0x1u<<6)
#define	RCC_MEMENR_AHBSRAM2EN					(0x1u<<5)
#define	RCC_MEMENR_AHBSRAM1EN					(0x1u<<4)
#define	RCC_MEMENR_AXISRAM6EN					(0x1u<<3)
#define	RCC_MEMENR_AXISRAM5EN					(0x1u<<2)
#define	RCC_MEMENR_AXISRAM4EN					(0x1u<<1)
#define	RCC_MEMENR_AXISRAM3EN					(0x1u<<0)

#define	RCC_MEMENR_BOOTROMEN_B_0X0				(0x0u<<12)
#define	RCC_MEMENR_BOOTROMEN_B_0X1				(0x1u<<12)
#define	RCC_MEMENR_VENCRAMEN_B_0X0				(0x0u<<11)
#define	RCC_MEMENR_VENCRAMEN_B_0X1				(0x1u<<11)
#define	RCC_MEMENR_NPUCACHERAMEN_B_0X0			(0x0u<<10)
#define	RCC_MEMENR_NPUCACHERAMEN_B_0X1			(0x1u<<10)
#define	RCC_MEMENR_FLEXRAMEN_B_0X0				(0x0u<<9)
#define	RCC_MEMENR_FLEXRAMEN_B_0X1				(0x1u<<9)
#define	RCC_MEMENR_AXISRAM2EN_B_0X0				(0x0u<<8)
#define	RCC_MEMENR_AXISRAM2EN_B_0X1				(0x1u<<8)
#define	RCC_MEMENR_AXISRAM1EN_B_0X0				(0x0u<<7)
#define	RCC_MEMENR_AXISRAM1EN_B_0X1				(0x1u<<7)
#define	RCC_MEMENR_BKPSRAMEN_B_0X0				(0x0u<<6)
#define	RCC_MEMENR_BKPSRAMEN_B_0X1				(0x1u<<6)
#define	RCC_MEMENR_AHBSRAM2EN_B_0X0				(0x0u<<5)
#define	RCC_MEMENR_AHBSRAM2EN_B_0X1				(0x1u<<5)
#define	RCC_MEMENR_AHBSRAM1EN_B_0X0				(0x0u<<4)
#define	RCC_MEMENR_AHBSRAM1EN_B_0X1				(0x1u<<4)
#define	RCC_MEMENR_AXISRAM6EN_B_0X0				(0x0u<<3)
#define	RCC_MEMENR_AXISRAM6EN_B_0X1				(0x1u<<3)
#define	RCC_MEMENR_AXISRAM5EN_B_0X0				(0x0u<<2)
#define	RCC_MEMENR_AXISRAM5EN_B_0X1				(0x1u<<2)
#define	RCC_MEMENR_AXISRAM4EN_B_0X0				(0x0u<<1)
#define	RCC_MEMENR_AXISRAM4EN_B_0X1				(0x1u<<1)
#define	RCC_MEMENR_AXISRAM3EN_B_0X0				(0x0u<<0)
#define	RCC_MEMENR_AXISRAM3EN_B_0X1				(0x1u<<0)

// AHB1ENR Configuration

#define	RCC_AHB1ENR_ADC12EN						(0x1u<<5)
#define	RCC_AHB1ENR_GPDMA1EN					(0x1u<<4)

#define	RCC_AHB1ENR_ADC12EN_B_0X0				(0x0u<<5)
#define	RCC_AHB1ENR_ADC12EN_B_0X1				(0x1u<<5)
#define	RCC_AHB1ENR_GPDMA1EN_B_0X0				(0x0u<<4)
#define	RCC_AHB1ENR_GPDMA1EN_B_0X1				(0x1u<<4)

// AHB2ENR Configuration

#define	RCC_AHB2ENR_ADF1EN						(0x1u<<17)
#define	RCC_AHB2ENR_MDF1EN						(0x1u<<16)
#define	RCC_AHB2ENR_RAMCFGEN					(0x1u<<12)

#define	RCC_AHB2ENR_ADF1EN_B_0X0				(0x0u<<17)
#define	RCC_AHB2ENR_ADF1EN_B_0X1				(0x1u<<17)
#define	RCC_AHB2ENR_MDF1EN_B_0X0				(0x0u<<16)
#define	RCC_AHB2ENR_MDF1EN_B_0X1				(0x1u<<16)
#define	RCC_AHB2ENR_RAMCFGEN_B_0X0				(0x0u<<12)
#define	RCC_AHB2ENR_RAMCFGEN_B_0X1				(0x1u<<12)

// AHB3ENR Configuration

#define	RCC_AHB3ENR_RISAFEN						(0x1u<<14)
#define	RCC_AHB3ENR_IACEN						(0x1u<<10)
#define	RCC_AHB3ENR_RIFSCEN						(0x1u<<9)
#define	RCC_AHB3ENR_PKAEN						(0x1u<<8)
#define	RCC_AHB3ENR_SAESEN						(0x1u<<4)
#define	RCC_AHB3ENR_CRYPEN						(0x1u<<2)
#define	RCC_AHB3ENR_HASHEN						(0x1u<<1)
#define	RCC_AHB3ENR_RNGEN						(0x1u<<0)

#define	RCC_AHB3ENR_RISAFEN_B_0X0				(0x0u<<14)
#define	RCC_AHB3ENR_RISAFEN_B_0X1				(0x1u<<14)
#define	RCC_AHB3ENR_IACEN_B_0X0					(0x0u<<10)
#define	RCC_AHB3ENR_IACEN_B_0X1					(0x1u<<10)
#define	RCC_AHB3ENR_RIFSCEN_B_0X0				(0x0u<<9)
#define	RCC_AHB3ENR_RIFSCEN_B_0X1				(0x1u<<9)
#define	RCC_AHB3ENR_PKAEN_B_0X0					(0x0u<<8)
#define	RCC_AHB3ENR_PKAEN_B_0X1					(0x1u<<8)
#define	RCC_AHB3ENR_SAESEN_B_0X0				(0x0u<<4)
#define	RCC_AHB3ENR_SAESEN_B_0X1				(0x1u<<4)
#define	RCC_AHB3ENR_CRYPEN_B_0X0				(0x0u<<2)
#define	RCC_AHB3ENR_CRYPEN_B_0X1				(0x1u<<2)
#define	RCC_AHB3ENR_HASHEN_B_0X0				(0x0u<<1)
#define	RCC_AHB3ENR_HASHEN_B_0X1				(0x1u<<1)
#define	RCC_AHB3ENR_RNGEN_B_0X0					(0x0u<<0)
#define	RCC_AHB3ENR_RNGEN_B_0X1					(0x1u<<0)

// AHB4ENR Configuration

#define	RCC_AHB4ENR_CRCEN						(0x1u<<19)
#define	RCC_AHB4ENR_PWREN						(0x1u<<18)
#define	RCC_AHB4ENR_GPIOQEN						(0x1u<<16)
#define	RCC_AHB4ENR_GPIOPEN						(0x1u<<15)
#define	RCC_AHB4ENR_GPIOOEN						(0x1u<<14)
#define	RCC_AHB4ENR_GPIONEN						(0x1u<<13)
#define	RCC_AHB4ENR_GPIOHEN						(0x1u<<7)
#define	RCC_AHB4ENR_GPIOGEN						(0x1u<<6)
#define	RCC_AHB4ENR_GPIOFEN						(0x1u<<5)
#define	RCC_AHB4ENR_GPIOEEN						(0x1u<<4)
#define	RCC_AHB4ENR_GPIODEN						(0x1u<<3)
#define	RCC_AHB4ENR_GPIOCEN						(0x1u<<2)
#define	RCC_AHB4ENR_GPIOBEN						(0x1u<<1)
#define	RCC_AHB4ENR_GPIOAEN						(0x1u<<0)

#define	RCC_AHB4ENR_CRCEN_B_0X0					(0x0u<<19)
#define	RCC_AHB4ENR_CRCEN_B_0X1					(0x1u<<19)
#define	RCC_AHB4ENR_PWREN_B_0X0					(0x0u<<18)
#define	RCC_AHB4ENR_PWREN_B_0X1					(0x1u<<18)
#define	RCC_AHB4ENR_GPIOQEN_B_0X0				(0x0u<<16)
#define	RCC_AHB4ENR_GPIOQEN_B_0X1				(0x1u<<16)
#define	RCC_AHB4ENR_GPIOPEN_B_0X0				(0x0u<<15)
#define	RCC_AHB4ENR_GPIOPEN_B_0X1				(0x1u<<15)
#define	RCC_AHB4ENR_GPIOOEN_B_0X0				(0x0u<<14)
#define	RCC_AHB4ENR_GPIOOEN_B_0X1				(0x1u<<14)
#define	RCC_AHB4ENR_GPIONEN_B_0X0				(0x0u<<13)
#define	RCC_AHB4ENR_GPIONEN_B_0X1				(0x1u<<13)
#define	RCC_AHB4ENR_GPIOHEN_B_0X0				(0x0u<<7)
#define	RCC_AHB4ENR_GPIOHEN_B_0X1				(0x1u<<7)
#define	RCC_AHB4ENR_GPIOGEN_B_0X0				(0x0u<<6)
#define	RCC_AHB4ENR_GPIOGEN_B_0X1				(0x1u<<6)
#define	RCC_AHB4ENR_GPIOFEN_B_0X0				(0x0u<<5)
#define	RCC_AHB4ENR_GPIOFEN_B_0X1				(0x1u<<5)
#define	RCC_AHB4ENR_GPIOEEN_B_0X0				(0x0u<<4)
#define	RCC_AHB4ENR_GPIOEEN_B_0X1				(0x1u<<4)
#define	RCC_AHB4ENR_GPIODEN_B_0X0				(0x0u<<3)
#define	RCC_AHB4ENR_GPIODEN_B_0X1				(0x1u<<3)
#define	RCC_AHB4ENR_GPIOCEN_B_0X0				(0x0u<<2)
#define	RCC_AHB4ENR_GPIOCEN_B_0X1				(0x1u<<2)
#define	RCC_AHB4ENR_GPIOBEN_B_0X0				(0x0u<<1)
#define	RCC_AHB4ENR_GPIOBEN_B_0X1				(0x1u<<1)
#define	RCC_AHB4ENR_GPIOAEN_B_0X0				(0x0u<<0)
#define	RCC_AHB4ENR_GPIOAEN_B_0X1				(0x1u<<0)

// AHB5ENR Configuration

#define	RCC_AHB5ENR_NPUEN						(0x1u<<31)
#define	RCC_AHB5ENR_NPUCACHEEN					(0x1u<<30)
#define	RCC_AHB5ENR_OTG2EN						(0x1u<<29)
#define	RCC_AHB5ENR_OTGPHY2EN					(0x1u<<28)
#define	RCC_AHB5ENR_OTGPHY1EN					(0x1u<<27)
#define	RCC_AHB5ENR_OTG1EN						(0x1u<<26)
#define	RCC_AHB5ENR_ETH1EN						(0x1u<<25)
#define	RCC_AHB5ENR_ETH1RXEN					(0x1u<<24)
#define	RCC_AHB5ENR_ETH1TXEN					(0x1u<<23)
#define	RCC_AHB5ENR_ETH1MACEN					(0x1u<<22)
#define	RCC_AHB5ENR_GPUEN						(0x1u<<20)
#define	RCC_AHB5ENR_GFXMMUEN					(0x1u<<19)
#define	RCC_AHB5ENR_MCE4EN						(0x1u<<18)
#define	RCC_AHB5ENR_XSPI3EN						(0x1u<<17)
#define	RCC_AHB5ENR_MCE3EN						(0x1u<<16)
#define	RCC_AHB5ENR_MCE2EN						(0x1u<<15)
#define	RCC_AHB5ENR_MCE1EN						(0x1u<<14)
#define	RCC_AHB5ENR_XSPIMEN						(0x1u<<13)
#define	RCC_AHB5ENR_XSPI2EN						(0x1u<<12)
#define	RCC_AHB5ENR_SDMMC1EN					(0x1u<<8)
#define	RCC_AHB5ENR_SDMMC2EN					(0x1u<<7)
#define	RCC_AHB5ENR_PSSIEN						(0x1u<<6)
#define	RCC_AHB5ENR_XSPI1EN						(0x1u<<5)
#define	RCC_AHB5ENR_FMCEN						(0x1u<<4)
#define	RCC_AHB5ENR_JPEGEN						(0x1u<<3)
#define	RCC_AHB5ENR_DMA2DEN						(0x1u<<1)
#define	RCC_AHB5ENR_HPDMA1EN					(0x1u<<0)

#define	RCC_AHB5ENR_NPUEN_B_0X0					(0x0u<<31)
#define	RCC_AHB5ENR_NPUEN_B_0X1					(0x1u<<31)
#define	RCC_AHB5ENR_NPUCACHEEN_B_0X0			(0x0u<<30)
#define	RCC_AHB5ENR_NPUCACHEEN_B_0X1			(0x1u<<30)
#define	RCC_AHB5ENR_OTG2EN_B_0X0				(0x0u<<29)
#define	RCC_AHB5ENR_OTG2EN_B_0X1				(0x1u<<29)
#define	RCC_AHB5ENR_OTGPHY2EN_B_0X0				(0x0u<<28)
#define	RCC_AHB5ENR_OTGPHY2EN_B_0X1				(0x1u<<28)
#define	RCC_AHB5ENR_OTGPHY1EN_B_0X0				(0x0u<<27)
#define	RCC_AHB5ENR_OTGPHY1EN_B_0X1				(0x1u<<27)
#define	RCC_AHB5ENR_OTG1EN_B_0X0				(0x0u<<26)
#define	RCC_AHB5ENR_OTG1EN_B_0X1				(0x1u<<26)
#define	RCC_AHB5ENR_ETH1EN_B_0X0				(0x0u<<25)
#define	RCC_AHB5ENR_ETH1EN_B_0X1				(0x1u<<25)
#define	RCC_AHB5ENR_ETH1RXEN_B_0X0				(0x0u<<24)
#define	RCC_AHB5ENR_ETH1RXEN_B_0X1				(0x1u<<24)
#define	RCC_AHB5ENR_ETH1TXEN_B_0X0				(0x0u<<23)
#define	RCC_AHB5ENR_ETH1TXEN_B_0X1				(0x1u<<23)
#define	RCC_AHB5ENR_ETH1MACEN_B_0X0				(0x0u<<22)
#define	RCC_AHB5ENR_ETH1MACEN_B_0X1				(0x1u<<22)
#define	RCC_AHB5ENR_GPUEN_B_0X0					(0x0u<<20)
#define	RCC_AHB5ENR_GPUEN_B_0X1					(0x1u<<20)
#define	RCC_AHB5ENR_GFXMMUEN_B_0X0				(0x0u<<19)
#define	RCC_AHB5ENR_GFXMMUEN_B_0X1				(0x1u<<19)
#define	RCC_AHB5ENR_MCE4EN_B_0X0				(0x0u<<18)
#define	RCC_AHB5ENR_MCE4EN_B_0X1				(0x1u<<18)
#define	RCC_AHB5ENR_XSPI3EN_B_0X0				(0x0u<<17)
#define	RCC_AHB5ENR_XSPI3EN_B_0X1				(0x1u<<17)
#define	RCC_AHB5ENR_MCE3EN_B_0X0				(0x0u<<16)
#define	RCC_AHB5ENR_MCE3EN_B_0X1				(0x1u<<16)
#define	RCC_AHB5ENR_MCE2EN_B_0X0				(0x0u<<15)
#define	RCC_AHB5ENR_MCE2EN_B_0X1				(0x1u<<15)
#define	RCC_AHB5ENR_MCE1EN_B_0X0				(0x0u<<14)
#define	RCC_AHB5ENR_MCE1EN_B_0X1				(0x1u<<14)
#define	RCC_AHB5ENR_XSPIMEN_B_0X0				(0x0u<<13)
#define	RCC_AHB5ENR_XSPIMEN_B_0X1				(0x1u<<13)
#define	RCC_AHB5ENR_XSPI2EN_B_0X0				(0x0u<<12)
#define	RCC_AHB5ENR_XSPI2EN_B_0X1				(0x1u<<12)
#define	RCC_AHB5ENR_SDMMC1EN_B_0X0				(0x0u<<8)
#define	RCC_AHB5ENR_SDMMC1EN_B_0X1				(0x1u<<8)
#define	RCC_AHB5ENR_SDMMC2EN_B_0X0				(0x0u<<7)
#define	RCC_AHB5ENR_SDMMC2EN_B_0X1				(0x1u<<7)
#define	RCC_AHB5ENR_PSSIEN_B_0X0				(0x0u<<6)
#define	RCC_AHB5ENR_PSSIEN_B_0X1				(0x1u<<6)
#define	RCC_AHB5ENR_XSPI1EN_B_0X0				(0x0u<<5)
#define	RCC_AHB5ENR_XSPI1EN_B_0X1				(0x1u<<5)
#define	RCC_AHB5ENR_FMCEN_B_0X0					(0x0u<<4)
#define	RCC_AHB5ENR_FMCEN_B_0X1					(0x1u<<4)
#define	RCC_AHB5ENR_JPEGEN_B_0X0				(0x0u<<3)
#define	RCC_AHB5ENR_JPEGEN_B_0X1				(0x1u<<3)
#define	RCC_AHB5ENR_DMA2DEN_B_0X0				(0x0u<<1)
#define	RCC_AHB5ENR_DMA2DEN_B_0X1				(0x1u<<1)
#define	RCC_AHB5ENR_HPDMA1EN_B_0X0				(0x0u<<0)
#define	RCC_AHB5ENR_HPDMA1EN_B_0X1				(0x1u<<0)

// APB1LENR Configuration

#define	RCC_APB1LENR_UART8EN					(0x1u<<31)
#define	RCC_APB1LENR_UART7EN					(0x1u<<30)
#define	RCC_APB1LENR_I3C2EN						(0x1u<<25)
#define	RCC_APB1LENR_I3C1EN						(0x1u<<24)
#define	RCC_APB1LENR_I2C3EN						(0x1u<<23)
#define	RCC_APB1LENR_I2C2EN						(0x1u<<22)
#define	RCC_APB1LENR_I2C1EN						(0x1u<<21)
#define	RCC_APB1LENR_UART5EN					(0x1u<<20)
#define	RCC_APB1LENR_UART4EN					(0x1u<<19)
#define	RCC_APB1LENR_USART3EN					(0x1u<<18)
#define	RCC_APB1LENR_USART2EN					(0x1u<<17)
#define	RCC_APB1LENR_SPDIFRX1EN					(0x1u<<16)
#define	RCC_APB1LENR_SPI3EN						(0x1u<<15)
#define	RCC_APB1LENR_SPI2EN						(0x1u<<14)
#define	RCC_APB1LENR_TIM11EN					(0x1u<<13)
#define	RCC_APB1LENR_TIM10EN					(0x1u<<12)
#define	RCC_APB1LENR_WWDGEN						(0x1u<<11)
#define	RCC_APB1LENR_LPTIM1EN					(0x1u<<9)
#define	RCC_APB1LENR_TIM14EN					(0x1u<<8)
#define	RCC_APB1LENR_TIM13EN					(0x1u<<7)
#define	RCC_APB1LENR_TIM12EN					(0x1u<<6)
#define	RCC_APB1LENR_TIM7EN						(0x1u<<5)
#define	RCC_APB1LENR_TIM6EN						(0x1u<<4)
#define	RCC_APB1LENR_TIM5EN						(0x1u<<3)
#define	RCC_APB1LENR_TIM4EN						(0x1u<<2)
#define	RCC_APB1LENR_TIM3EN						(0x1u<<1)
#define	RCC_APB1LENR_TIM2EN						(0x1u<<0)

#define	RCC_APB1LENR_UART8EN_B_0X0				(0x0u<<31)
#define	RCC_APB1LENR_UART8EN_B_0X1				(0x1u<<31)
#define	RCC_APB1LENR_UART7EN_B_0X0				(0x0u<<30)
#define	RCC_APB1LENR_UART7EN_B_0X1				(0x1u<<30)
#define	RCC_APB1LENR_I3C2EN_B_0X0				(0x0u<<25)
#define	RCC_APB1LENR_I3C2EN_B_0X1				(0x1u<<25)
#define	RCC_APB1LENR_I3C1EN_B_0X0				(0x0u<<24)
#define	RCC_APB1LENR_I3C1EN_B_0X1				(0x1u<<24)
#define	RCC_APB1LENR_I2C3EN_B_0X0				(0x0u<<23)
#define	RCC_APB1LENR_I2C3EN_B_0X1				(0x1u<<23)
#define	RCC_APB1LENR_I2C2EN_B_0X0				(0x0u<<22)
#define	RCC_APB1LENR_I2C2EN_B_0X1				(0x1u<<22)
#define	RCC_APB1LENR_I2C1EN_B_0X0				(0x0u<<21)
#define	RCC_APB1LENR_I2C1EN_B_0X1				(0x1u<<21)
#define	RCC_APB1LENR_UART5EN_B_0X0				(0x0u<<20)
#define	RCC_APB1LENR_UART5EN_B_0X1				(0x1u<<20)
#define	RCC_APB1LENR_UART4EN_B_0X0				(0x0u<<19)
#define	RCC_APB1LENR_UART4EN_B_0X1				(0x1u<<19)
#define	RCC_APB1LENR_USART3EN_B_0X0				(0x0u<<18)
#define	RCC_APB1LENR_USART3EN_B_0X1				(0x1u<<18)
#define	RCC_APB1LENR_USART2EN_B_0X0				(0x0u<<17)
#define	RCC_APB1LENR_USART2EN_B_0X1				(0x1u<<17)
#define	RCC_APB1LENR_SPDIFRX1EN_B_0X0			(0x0u<<16)
#define	RCC_APB1LENR_SPDIFRX1EN_B_0X1			(0x1u<<16)
#define	RCC_APB1LENR_SPI3EN_B_0X0				(0x0u<<15)
#define	RCC_APB1LENR_SPI3EN_B_0X1				(0x1u<<15)
#define	RCC_APB1LENR_SPI2EN_B_0X0				(0x0u<<14)
#define	RCC_APB1LENR_SPI2EN_B_0X1				(0x1u<<14)
#define	RCC_APB1LENR_TIM11EN_B_0X0				(0x0u<<13)
#define	RCC_APB1LENR_TIM11EN_B_0X1				(0x1u<<13)
#define	RCC_APB1LENR_TIM10EN_B_0X0				(0x0u<<12)
#define	RCC_APB1LENR_TIM10EN_B_0X1				(0x1u<<12)
#define	RCC_APB1LENR_WWDGEN_B_0X0				(0x0u<<11)
#define	RCC_APB1LENR_WWDGEN_B_0X1				(0x1u<<11)
#define	RCC_APB1LENR_LPTIM1EN_B_0X0				(0x0u<<9)
#define	RCC_APB1LENR_LPTIM1EN_B_0X1				(0x1u<<9)
#define	RCC_APB1LENR_TIM14EN_B_0X0				(0x0u<<8)
#define	RCC_APB1LENR_TIM14EN_B_0X1				(0x1u<<8)
#define	RCC_APB1LENR_TIM13EN_B_0X0				(0x0u<<7)
#define	RCC_APB1LENR_TIM13EN_B_0X1				(0x1u<<7)
#define	RCC_APB1LENR_TIM12EN_B_0X0				(0x0u<<6)
#define	RCC_APB1LENR_TIM12EN_B_0X1				(0x1u<<6)
#define	RCC_APB1LENR_TIM7EN_B_0X0				(0x0u<<5)
#define	RCC_APB1LENR_TIM7EN_B_0X1				(0x1u<<5)
#define	RCC_APB1LENR_TIM6EN_B_0X0				(0x0u<<4)
#define	RCC_APB1LENR_TIM6EN_B_0X1				(0x1u<<4)
#define	RCC_APB1LENR_TIM5EN_B_0X0				(0x0u<<3)
#define	RCC_APB1LENR_TIM5EN_B_0X1				(0x1u<<3)
#define	RCC_APB1LENR_TIM4EN_B_0X0				(0x0u<<2)
#define	RCC_APB1LENR_TIM4EN_B_0X1				(0x1u<<2)
#define	RCC_APB1LENR_TIM3EN_B_0X0				(0x0u<<1)
#define	RCC_APB1LENR_TIM3EN_B_0X1				(0x1u<<1)
#define	RCC_APB1LENR_TIM2EN_B_0X0				(0x0u<<0)
#define	RCC_APB1LENR_TIM2EN_B_0X1				(0x1u<<0)

// APB1HENR Configuration

#define	RCC_APB1HENR_UCPD1EN					(0x1u<<18)
#define	RCC_APB1HENR_FDCANEN					(0x1u<<8)
#define	RCC_APB1HENR_MDIOSEN					(0x1u<<5)

#define	RCC_APB1HENR_UCPD1EN_B_0X0				(0x0u<<18)
#define	RCC_APB1HENR_UCPD1EN_B_0X1				(0x1u<<18)
#define	RCC_APB1HENR_FDCANEN_B_0X0				(0x0u<<8)
#define	RCC_APB1HENR_FDCANEN_B_0X1				(0x1u<<8)
#define	RCC_APB1HENR_MDIOSEN_B_0X0				(0x0u<<5)
#define	RCC_APB1HENR_MDIOSEN_B_0X1				(0x1u<<5)

// APB2ENR Configuration

#define	RCC_APB2ENR_SAI2EN						(0x1u<<22)
#define	RCC_APB2ENR_SAI1EN						(0x1u<<21)
#define	RCC_APB2ENR_SPI5EN						(0x1u<<20)
#define	RCC_APB2ENR_TIM9EN						(0x1u<<19)
#define	RCC_APB2ENR_TIM17EN						(0x1u<<18)
#define	RCC_APB2ENR_TIM16EN						(0x1u<<17)
#define	RCC_APB2ENR_TIM15EN						(0x1u<<16)
#define	RCC_APB2ENR_TIM18EN						(0x1u<<15)
#define	RCC_APB2ENR_SPI4EN						(0x1u<<13)
#define	RCC_APB2ENR_SPI1EN						(0x1u<<12)
#define	RCC_APB2ENR_USART10EN					(0x1u<<7)
#define	RCC_APB2ENR_UART9EN						(0x1u<<6)
#define	RCC_APB2ENR_USART6EN					(0x1u<<5)
#define	RCC_APB2ENR_USART1EN					(0x1u<<4)
#define	RCC_APB2ENR_TIM8EN						(0x1u<<1)
#define	RCC_APB2ENR_TIM1EN						(0x1u<<0)

#define	RCC_APB2ENR_SAI2EN_B_0X0				(0x0u<<22)
#define	RCC_APB2ENR_SAI2EN_B_0X1				(0x1u<<22)
#define	RCC_APB2ENR_SAI1EN_B_0X0				(0x0u<<21)
#define	RCC_APB2ENR_SAI1EN_B_0X1				(0x1u<<21)
#define	RCC_APB2ENR_SPI5EN_B_0X0				(0x0u<<20)
#define	RCC_APB2ENR_SPI5EN_B_0X1				(0x1u<<20)
#define	RCC_APB2ENR_TIM9EN_B_0X0				(0x0u<<19)
#define	RCC_APB2ENR_TIM9EN_B_0X1				(0x1u<<19)
#define	RCC_APB2ENR_TIM17EN_B_0X0				(0x0u<<18)
#define	RCC_APB2ENR_TIM17EN_B_0X1				(0x1u<<18)
#define	RCC_APB2ENR_TIM16EN_B_0X0				(0x0u<<17)
#define	RCC_APB2ENR_TIM16EN_B_0X1				(0x1u<<17)
#define	RCC_APB2ENR_TIM15EN_B_0X0				(0x0u<<16)
#define	RCC_APB2ENR_TIM15EN_B_0X1				(0x1u<<16)
#define	RCC_APB2ENR_TIM18EN_B_0X0				(0x0u<<15)
#define	RCC_APB2ENR_TIM18EN_B_0X1				(0x1u<<15)
#define	RCC_APB2ENR_SPI4EN_B_0X0				(0x0u<<13)
#define	RCC_APB2ENR_SPI4EN_B_0X1				(0x1u<<13)
#define	RCC_APB2ENR_SPI1EN_B_0X0				(0x0u<<12)
#define	RCC_APB2ENR_SPI1EN_B_0X1				(0x1u<<12)
#define	RCC_APB2ENR_USART10EN_B_0X0				(0x0u<<7)
#define	RCC_APB2ENR_USART10EN_B_0X1				(0x1u<<7)
#define	RCC_APB2ENR_UART9EN_B_0X0				(0x0u<<6)
#define	RCC_APB2ENR_UART9EN_B_0X1				(0x1u<<6)
#define	RCC_APB2ENR_USART6EN_B_0X0				(0x0u<<5)
#define	RCC_APB2ENR_USART6EN_B_0X1				(0x1u<<5)
#define	RCC_APB2ENR_USART1EN_B_0X0				(0x0u<<4)
#define	RCC_APB2ENR_USART1EN_B_0X1				(0x1u<<4)
#define	RCC_APB2ENR_TIM8EN_B_0X0				(0x0u<<1)
#define	RCC_APB2ENR_TIM8EN_B_0X1				(0x1u<<1)
#define	RCC_APB2ENR_TIM1EN_B_0X0				(0x0u<<0)
#define	RCC_APB2ENR_TIM1EN_B_0X1				(0x1u<<0)

// APB3ENR Configuration

#define	RCC_APB3ENR_DFTEN						(0x1u<<2)

#define	RCC_APB3ENR_DFTEN_B_0X0					(0x0u<<2)
#define	RCC_APB3ENR_DFTEN_B_0X1					(0x1u<<2)

// APB4LENR Configuration

#define	RCC_APB4LENR_SERFEN						(0x1u<<31)
#define	RCC_APB4LENR_R2GNPUEN					(0x1u<<23)
#define	RCC_APB4LENR_R2GRETEN					(0x1u<<22)
#define	RCC_APB4LENR_RTCAPBEN					(0x1u<<17)
#define	RCC_APB4LENR_RTCEN						(0x1u<<16)
#define	RCC_APB4LENR_VREFBUFEN					(0x1u<<15)
#define	RCC_APB4LENR_LPTIM5EN					(0x1u<<12)
#define	RCC_APB4LENR_LPTIM4EN					(0x1u<<11)
#define	RCC_APB4LENR_LPTIM3EN					(0x1u<<10)
#define	RCC_APB4LENR_LPTIM2EN					(0x1u<<9)
#define	RCC_APB4LENR_I2C4EN						(0x1u<<7)
#define	RCC_APB4LENR_SPI6EN						(0x1u<<5)
#define	RCC_APB4LENR_LPUART1EN					(0x1u<<3)
#define	RCC_APB4LENR_HDPEN						(0x1u<<2)

#define	RCC_APB4LENR_SERFEN_B_0X0				(0x0u<<31)
#define	RCC_APB4LENR_SERFEN_B_0X1				(0x1u<<31)
#define	RCC_APB4LENR_R2GNPUEN_B_0X0				(0x0u<<23)
#define	RCC_APB4LENR_R2GNPUEN_B_0X1				(0x1u<<23)
#define	RCC_APB4LENR_R2GRETEN_B_0X0				(0x0u<<22)
#define	RCC_APB4LENR_R2GRETEN_B_0X1				(0x1u<<22)
#define	RCC_APB4LENR_RTCAPBEN_B_0X0				(0x0u<<17)
#define	RCC_APB4LENR_RTCAPBEN_B_0X1				(0x1u<<17)
#define	RCC_APB4LENR_RTCEN_B_0X0				(0x0u<<16)
#define	RCC_APB4LENR_RTCEN_B_0X1				(0x1u<<16)
#define	RCC_APB4LENR_VREFBUFEN_B_0X0			(0x0u<<15)
#define	RCC_APB4LENR_VREFBUFEN_B_0X1			(0x1u<<15)
#define	RCC_APB4LENR_LPTIM5EN_B_0X0				(0x0u<<12)
#define	RCC_APB4LENR_LPTIM5EN_B_0X1				(0x1u<<12)
#define	RCC_APB4LENR_LPTIM4EN_B_0X0				(0x0u<<11)
#define	RCC_APB4LENR_LPTIM4EN_B_0X1				(0x1u<<11)
#define	RCC_APB4LENR_LPTIM3EN_B_0X0				(0x0u<<10)
#define	RCC_APB4LENR_LPTIM3EN_B_0X1				(0x1u<<10)
#define	RCC_APB4LENR_LPTIM2EN_B_0X0				(0x0u<<9)
#define	RCC_APB4LENR_LPTIM2EN_B_0X1				(0x1u<<9)
#define	RCC_APB4LENR_I2C4EN_B_0X0				(0x0u<<7)
#define	RCC_APB4LENR_I2C4EN_B_0X1				(0x1u<<7)
#define	RCC_APB4LENR_SPI6EN_B_0X0				(0x0u<<5)
#define	RCC_APB4LENR_SPI6EN_B_0X1				(0x1u<<5)
#define	RCC_APB4LENR_LPUART1EN_B_0X0			(0x0u<<3)
#define	RCC_APB4LENR_LPUART1EN_B_0X1			(0x1u<<3)
#define	RCC_APB4LENR_HDPEN_B_0X0				(0x0u<<2)
#define	RCC_APB4LENR_HDPEN_B_0X1				(0x1u<<2)

// APB4HENR Configuration

#define	RCC_APB4HENR_BUSPERFMEN					(0x1u<<4)
#define	RCC_APB4HENR_DTSEN						(0x1u<<2)
#define	RCC_APB4HENR_BSECEN						(0x1u<<1)
#define	RCC_APB4HENR_SYSCFGEN					(0x1u<<0)

#define	RCC_APB4HENR_BUSPERFMEN_B_0X0			(0x0u<<4)
#define	RCC_APB4HENR_BUSPERFMEN_B_0X1			(0x1u<<4)
#define	RCC_APB4HENR_DTSEN_B_0X0				(0x0u<<2)
#define	RCC_APB4HENR_DTSEN_B_0X1				(0x1u<<2)
#define	RCC_APB4HENR_BSECEN_B_0X0				(0x0u<<1)
#define	RCC_APB4HENR_BSECEN_B_0X1				(0x1u<<1)
#define	RCC_APB4HENR_SYSCFGEN_B_0X0				(0x0u<<0)
#define	RCC_APB4HENR_SYSCFGEN_B_0X1				(0x1u<<0)

// APB5ENR Configuration

#define	RCC_APB5ENR_CSIEN						(0x1u<<6)
#define	RCC_APB5ENR_VENCEN						(0x1u<<5)
#define	RCC_APB5ENR_GFXTIMEN					(0x1u<<4)
#define	RCC_APB5ENR_DCMIPPEN					(0x1u<<2)
#define	RCC_APB5ENR_LTDCEN						(0x1u<<1)

#define	RCC_APB5ENR_CSIEN_B_0X0					(0x0u<<6)
#define	RCC_APB5ENR_CSIEN_B_0X1					(0x1u<<6)
#define	RCC_APB5ENR_VENCEN_B_0X0				(0x0u<<5)
#define	RCC_APB5ENR_VENCEN_B_0X1				(0x1u<<5)
#define	RCC_APB5ENR_GFXTIMEN_B_0X0				(0x0u<<4)
#define	RCC_APB5ENR_GFXTIMEN_B_0X1				(0x1u<<4)
#define	RCC_APB5ENR_DCMIPPEN_B_0X0				(0x0u<<2)
#define	RCC_APB5ENR_DCMIPPEN_B_0X1				(0x1u<<2)
#define	RCC_APB5ENR_LTDCEN_B_0X0				(0x0u<<1)
#define	RCC_APB5ENR_LTDCEN_B_0X1				(0x1u<<1)

// DIVLPENR Configuration

#define	RCC_DIVLPENR_IC20LPEN					(0x1u<<19)
#define	RCC_DIVLPENR_IC19LPEN					(0x1u<<18)
#define	RCC_DIVLPENR_IC18LPEN					(0x1u<<17)
#define	RCC_DIVLPENR_IC17LPEN					(0x1u<<16)
#define	RCC_DIVLPENR_IC16LPEN					(0x1u<<15)
#define	RCC_DIVLPENR_IC15LPEN					(0x1u<<14)
#define	RCC_DIVLPENR_IC14LPEN					(0x1u<<13)
#define	RCC_DIVLPENR_IC13LPEN					(0x1u<<12)
#define	RCC_DIVLPENR_IC12LPEN					(0x1u<<11)
#define	RCC_DIVLPENR_IC11LPEN					(0x1u<<10)
#define	RCC_DIVLPENR_IC10LPEN					(0x1u<<9)
#define	RCC_DIVLPENR_IC9LPEN					(0x1u<<8)
#define	RCC_DIVLPENR_IC8LPEN					(0x1u<<7)
#define	RCC_DIVLPENR_IC7LPEN					(0x1u<<6)
#define	RCC_DIVLPENR_IC6LPEN					(0x1u<<5)
#define	RCC_DIVLPENR_IC5LPEN					(0x1u<<4)
#define	RCC_DIVLPENR_IC4LPEN					(0x1u<<3)
#define	RCC_DIVLPENR_IC3LPEN					(0x1u<<2)
#define	RCC_DIVLPENR_IC2LPEN					(0x1u<<1)
#define	RCC_DIVLPENR_IC1LPEN					(0x1u<<0)

#define	RCC_DIVLPENR_IC20LPEN_B_0X0				(0x0u<<19)
#define	RCC_DIVLPENR_IC20LPEN_B_0X1				(0x1u<<19)
#define	RCC_DIVLPENR_IC19LPEN_B_0X0				(0x0u<<18)
#define	RCC_DIVLPENR_IC19LPEN_B_0X1				(0x1u<<18)
#define	RCC_DIVLPENR_IC18LPEN_B_0X0				(0x0u<<17)
#define	RCC_DIVLPENR_IC18LPEN_B_0X1				(0x1u<<17)
#define	RCC_DIVLPENR_IC17LPEN_B_0X0				(0x0u<<16)
#define	RCC_DIVLPENR_IC17LPEN_B_0X1				(0x1u<<16)
#define	RCC_DIVLPENR_IC16LPEN_B_0X0				(0x0u<<15)
#define	RCC_DIVLPENR_IC16LPEN_B_0X1				(0x1u<<15)
#define	RCC_DIVLPENR_IC15LPEN_B_0X0				(0x0u<<14)
#define	RCC_DIVLPENR_IC15LPEN_B_0X1				(0x1u<<14)
#define	RCC_DIVLPENR_IC14LPEN_B_0X0				(0x0u<<13)
#define	RCC_DIVLPENR_IC14LPEN_B_0X1				(0x1u<<13)
#define	RCC_DIVLPENR_IC13LPEN_B_0X0				(0x0u<<12)
#define	RCC_DIVLPENR_IC13LPEN_B_0X1				(0x1u<<12)
#define	RCC_DIVLPENR_IC12LPEN_B_0X0				(0x0u<<11)
#define	RCC_DIVLPENR_IC12LPEN_B_0X1				(0x1u<<11)
#define	RCC_DIVLPENR_IC11LPEN_B_0X0				(0x0u<<10)
#define	RCC_DIVLPENR_IC11LPEN_B_0X1				(0x1u<<10)
#define	RCC_DIVLPENR_IC10LPEN_B_0X0				(0x0u<<9)
#define	RCC_DIVLPENR_IC10LPEN_B_0X1				(0x1u<<9)
#define	RCC_DIVLPENR_IC9LPEN_B_0X0				(0x0u<<8)
#define	RCC_DIVLPENR_IC9LPEN_B_0X1				(0x1u<<8)
#define	RCC_DIVLPENR_IC8LPEN_B_0X0				(0x0u<<7)
#define	RCC_DIVLPENR_IC8LPEN_B_0X1				(0x1u<<7)
#define	RCC_DIVLPENR_IC7LPEN_B_0X0				(0x0u<<6)
#define	RCC_DIVLPENR_IC7LPEN_B_0X1				(0x1u<<6)
#define	RCC_DIVLPENR_IC6LPEN_B_0X0				(0x0u<<5)
#define	RCC_DIVLPENR_IC6LPEN_B_0X1				(0x1u<<5)
#define	RCC_DIVLPENR_IC5LPEN_B_0X0				(0x0u<<4)
#define	RCC_DIVLPENR_IC5LPEN_B_0X1				(0x1u<<4)
#define	RCC_DIVLPENR_IC4LPEN_B_0X0				(0x0u<<3)
#define	RCC_DIVLPENR_IC4LPEN_B_0X1				(0x1u<<3)
#define	RCC_DIVLPENR_IC3LPEN_B_0X0				(0x0u<<2)
#define	RCC_DIVLPENR_IC3LPEN_B_0X1				(0x1u<<2)
#define	RCC_DIVLPENR_IC2LPEN_B_0X0				(0x0u<<1)
#define	RCC_DIVLPENR_IC2LPEN_B_0X1				(0x1u<<1)
#define	RCC_DIVLPENR_IC1LPEN_B_0X0				(0x0u<<0)
#define	RCC_DIVLPENR_IC1LPEN_B_0X1				(0x1u<<0)

// BUSLPENR Configuration

#define	RCC_BUSLPENR_APB5LPEN					(0x1u<<12)
#define	RCC_BUSLPENR_APB4LPEN					(0x1u<<11)
#define	RCC_BUSLPENR_APB3LPEN					(0x1u<<10)
#define	RCC_BUSLPENR_APB2LPEN					(0x1u<<9)
#define	RCC_BUSLPENR_APB1LPEN					(0x1u<<8)
#define	RCC_BUSLPENR_AHB5LPEN					(0x1u<<7)
#define	RCC_BUSLPENR_AHB4LPEN					(0x1u<<6)
#define	RCC_BUSLPENR_AHB3LPEN					(0x1u<<5)
#define	RCC_BUSLPENR_AHB2LPEN					(0x1u<<4)
#define	RCC_BUSLPENR_AHB1LPEN					(0x1u<<3)
#define	RCC_BUSLPENR_AHBMLPEN					(0x1u<<2)
#define	RCC_BUSLPENR_ACLKNCLPEN					(0x1u<<1)
#define	RCC_BUSLPENR_ACLKNLPEN					(0x1u<<0)

#define	RCC_BUSLPENR_APB5LPEN_B_0X0				(0x0u<<12)
#define	RCC_BUSLPENR_APB5LPEN_B_0X1				(0x1u<<12)
#define	RCC_BUSLPENR_APB4LPEN_B_0X0				(0x0u<<11)
#define	RCC_BUSLPENR_APB4LPEN_B_0X1				(0x1u<<11)
#define	RCC_BUSLPENR_APB3LPEN_B_0X0				(0x0u<<10)
#define	RCC_BUSLPENR_APB3LPEN_B_0X1				(0x1u<<10)
#define	RCC_BUSLPENR_APB2LPEN_B_0X0				(0x0u<<9)
#define	RCC_BUSLPENR_APB2LPEN_B_0X1				(0x1u<<9)
#define	RCC_BUSLPENR_APB1LPEN_B_0X0				(0x0u<<8)
#define	RCC_BUSLPENR_APB1LPEN_B_0X1				(0x1u<<8)
#define	RCC_BUSLPENR_AHB5LPEN_B_0X0				(0x0u<<7)
#define	RCC_BUSLPENR_AHB5LPEN_B_0X1				(0x1u<<7)
#define	RCC_BUSLPENR_AHB4LPEN_B_0X0				(0x0u<<6)
#define	RCC_BUSLPENR_AHB4LPEN_B_0X1				(0x1u<<6)
#define	RCC_BUSLPENR_AHB3LPEN_B_0X0				(0x0u<<5)
#define	RCC_BUSLPENR_AHB3LPEN_B_0X1				(0x1u<<5)
#define	RCC_BUSLPENR_AHB2LPEN_B_0X0				(0x0u<<4)
#define	RCC_BUSLPENR_AHB2LPEN_B_0X1				(0x1u<<4)
#define	RCC_BUSLPENR_AHB1LPEN_B_0X0				(0x0u<<3)
#define	RCC_BUSLPENR_AHB1LPEN_B_0X1				(0x1u<<3)
#define	RCC_BUSLPENR_AHBMLPEN_B_0X0				(0x0u<<2)
#define	RCC_BUSLPENR_AHBMLPEN_B_0X1				(0x1u<<2)
#define	RCC_BUSLPENR_ACLKNCLPEN_B_0X0			(0x0u<<1)
#define	RCC_BUSLPENR_ACLKNCLPEN_B_0X1			(0x1u<<1)
#define	RCC_BUSLPENR_ACLKNLPEN_B_0X0			(0x0u<<0)
#define	RCC_BUSLPENR_ACLKNLPEN_B_0X1			(0x1u<<0)

// MISCLPENR Configuration

#define	RCC_MISCLPENR_PERLPEN					(0x1u<<6)
#define	RCC_MISCLPENR_XSPIPHYCOMPLPEN			(0x1u<<3)
#define	RCC_MISCLPENR_DBGLPEN					(0x1u<<0)

#define	RCC_MISCLPENR_PERLPEN_B_0X0				(0x0u<<6)
#define	RCC_MISCLPENR_PERLPEN_B_0X1				(0x1u<<6)
#define	RCC_MISCLPENR_XSPIPHYCOMPLPEN_B_0X0		(0x0u<<3)
#define	RCC_MISCLPENR_XSPIPHYCOMPLPEN_B_0X1		(0x1u<<3)
#define	RCC_MISCLPENR_DBGLPEN_B_0X0				(0x0u<<0)
#define	RCC_MISCLPENR_DBGLPEN_B_0X1				(0x1u<<0)

// MEMLPENR Configuration

#define	RCC_MEMLPENR_BOOTROMLPEN				(0x1u<<12)
#define	RCC_MEMLPENR_VENCRAMLPEN				(0x1u<<11)
#define	RCC_MEMLPENR_NPUCACHERAMLPEN			(0x1u<<10)
#define	RCC_MEMLPENR_FLEXRAMLPEN				(0x1u<<9)
#define	RCC_MEMLPENR_AXISRAM2LPEN				(0x1u<<8)
#define	RCC_MEMLPENR_AXISRAM1LPEN				(0x1u<<7)
#define	RCC_MEMLPENR_BKPSRAMLPEN				(0x1u<<6)
#define	RCC_MEMLPENR_AHBSRAM2LPEN				(0x1u<<5)
#define	RCC_MEMLPENR_AHBSRAM1LPEN				(0x1u<<4)
#define	RCC_MEMLPENR_AXISRAM6LPEN				(0x1u<<3)
#define	RCC_MEMLPENR_AXISRAM5LPEN				(0x1u<<2)
#define	RCC_MEMLPENR_AXISRAM4LPEN				(0x1u<<1)
#define	RCC_MEMLPENR_AXISRAM3LPEN				(0x1u<<0)

#define	RCC_MEMLPENR_BOOTROMLPEN_B_0X0			(0x0u<<12)
#define	RCC_MEMLPENR_BOOTROMLPEN_B_0X1			(0x1u<<12)
#define	RCC_MEMLPENR_VENCRAMLPEN_B_0X0			(0x0u<<11)
#define	RCC_MEMLPENR_VENCRAMLPEN_B_0X1			(0x1u<<11)
#define	RCC_MEMLPENR_NPUCACHERAMLPEN_B_0X0		(0x0u<<10)
#define	RCC_MEMLPENR_NPUCACHERAMLPEN_B_0X1		(0x1u<<10)
#define	RCC_MEMLPENR_FLEXRAMLPEN_B_0X0			(0x0u<<9)
#define	RCC_MEMLPENR_FLEXRAMLPEN_B_0X1			(0x1u<<9)
#define	RCC_MEMLPENR_AXISRAM2LPEN_B_0X0			(0x0u<<8)
#define	RCC_MEMLPENR_AXISRAM2LPEN_B_0X1			(0x1u<<8)
#define	RCC_MEMLPENR_AXISRAM1LPEN_B_0X0			(0x0u<<7)
#define	RCC_MEMLPENR_AXISRAM1LPEN_B_0X1			(0x1u<<7)
#define	RCC_MEMLPENR_BKPSRAMLPEN_B_0X0			(0x0u<<6)
#define	RCC_MEMLPENR_BKPSRAMLPEN_B_0X1			(0x1u<<6)
#define	RCC_MEMLPENR_AHBSRAM2LPEN_B_0X0			(0x0u<<5)
#define	RCC_MEMLPENR_AHBSRAM2LPEN_B_0X1			(0x1u<<5)
#define	RCC_MEMLPENR_AHBSRAM1LPEN_B_0X0			(0x0u<<4)
#define	RCC_MEMLPENR_AHBSRAM1LPEN_B_0X1			(0x1u<<4)
#define	RCC_MEMLPENR_AXISRAM6LPEN_B_0X0			(0x0u<<3)
#define	RCC_MEMLPENR_AXISRAM6LPEN_B_0X1			(0x1u<<3)
#define	RCC_MEMLPENR_AXISRAM5LPEN_B_0X0			(0x0u<<2)
#define	RCC_MEMLPENR_AXISRAM5LPEN_B_0X1			(0x1u<<2)
#define	RCC_MEMLPENR_AXISRAM4LPEN_B_0X0			(0x0u<<1)
#define	RCC_MEMLPENR_AXISRAM4LPEN_B_0X1			(0x1u<<1)
#define	RCC_MEMLPENR_AXISRAM3LPEN_B_0X0			(0x0u<<0)
#define	RCC_MEMLPENR_AXISRAM3LPEN_B_0X1			(0x1u<<0)

// AHB1LPENR Configuration

#define	RCC_AHB1LPENR_ADC12LPEN					(0x1u<<5)
#define	RCC_AHB1LPENR_GPDMA1LPEN				(0x1u<<4)

#define	RCC_AHB1LPENR_ADC12LPEN_B_0X0			(0x0u<<5)
#define	RCC_AHB1LPENR_ADC12LPEN_B_0X1			(0x1u<<5)
#define	RCC_AHB1LPENR_GPDMA1LPEN_B_0X0			(0x0u<<4)
#define	RCC_AHB1LPENR_GPDMA1LPEN_B_0X1			(0x1u<<4)

// AHB2LPENR Configuration

#define	RCC_AHB2LPENR_ADF1LPEN					(0x1u<<17)
#define	RCC_AHB2LPENR_MDF1LPEN					(0x1u<<16)
#define	RCC_AHB2LPENR_RAMCFGLPEN				(0x1u<<12)

#define	RCC_AHB2LPENR_ADF1LPEN_B_0X0			(0x0u<<17)
#define	RCC_AHB2LPENR_ADF1LPEN_B_0X1			(0x1u<<17)
#define	RCC_AHB2LPENR_MDF1LPEN_B_0X0			(0x0u<<16)
#define	RCC_AHB2LPENR_MDF1LPEN_B_0X1			(0x1u<<16)
#define	RCC_AHB2LPENR_RAMCFGLPEN_B_0X0			(0x0u<<12)
#define	RCC_AHB2LPENR_RAMCFGLPEN_B_0X1			(0x1u<<12)

// AHB3LPENR Configuration

#define	RCC_AHB3LPENR_RISAFLPEN					(0x1u<<14)
#define	RCC_AHB3LPENR_IACLPEN					(0x1u<<10)
#define	RCC_AHB3LPENR_RIFSCLPEN					(0x1u<<9)
#define	RCC_AHB3LPENR_PKALPEN					(0x1u<<8)
#define	RCC_AHB3LPENR_SAESLPEN					(0x1u<<4)
#define	RCC_AHB3LPENR_CRYPLPEN					(0x1u<<2)
#define	RCC_AHB3LPENR_HASHLPEN					(0x1u<<1)
#define	RCC_AHB3LPENR_RNGLPEN					(0x1u<<0)

#define	RCC_AHB3LPENR_RISAFLPEN_B_0X0			(0x0u<<14)
#define	RCC_AHB3LPENR_RISAFLPEN_B_0X1			(0x1u<<14)
#define	RCC_AHB3LPENR_IACLPEN_B_0X0				(0x0u<<10)
#define	RCC_AHB3LPENR_IACLPEN_B_0X1				(0x1u<<10)
#define	RCC_AHB3LPENR_RIFSCLPEN_B_0X0			(0x0u<<9)
#define	RCC_AHB3LPENR_RIFSCLPEN_B_0X1			(0x1u<<9)
#define	RCC_AHB3LPENR_PKALPEN_B_0X0				(0x0u<<8)
#define	RCC_AHB3LPENR_PKALPEN_B_0X1				(0x1u<<8)
#define	RCC_AHB3LPENR_SAESLPEN_B_0X0			(0x0u<<4)
#define	RCC_AHB3LPENR_SAESLPEN_B_0X1			(0x1u<<4)
#define	RCC_AHB3LPENR_CRYPLPEN_B_0X0			(0x0u<<2)
#define	RCC_AHB3LPENR_CRYPLPEN_B_0X1			(0x1u<<2)
#define	RCC_AHB3LPENR_HASHLPEN_B_0X0			(0x0u<<1)
#define	RCC_AHB3LPENR_HASHLPEN_B_0X1			(0x1u<<1)
#define	RCC_AHB3LPENR_RNGLPEN_B_0X0				(0x0u<<0)
#define	RCC_AHB3LPENR_RNGLPEN_B_0X1				(0x1u<<0)

// AHB4LPENR Configuration

#define	RCC_AHB4LPENR_CRCLPEN					(0x1u<<19)
#define	RCC_AHB4LPENR_PWRLPEN					(0x1u<<18)
#define	RCC_AHB4LPENR_GPIOQLPEN					(0x1u<<16)
#define	RCC_AHB4LPENR_GPIOPLPEN					(0x1u<<15)
#define	RCC_AHB4LPENR_GPIOOLPEN					(0x1u<<14)
#define	RCC_AHB4LPENR_GPIONLPEN					(0x1u<<13)
#define	RCC_AHB4LPENR_GPIOHLPEN					(0x1u<<7)
#define	RCC_AHB4LPENR_GPIOGLPEN					(0x1u<<6)
#define	RCC_AHB4LPENR_GPIOFLPEN					(0x1u<<5)
#define	RCC_AHB4LPENR_GPIOELPEN					(0x1u<<4)
#define	RCC_AHB4LPENR_GPIODLPEN					(0x1u<<3)
#define	RCC_AHB4LPENR_GPIOCLPEN					(0x1u<<2)
#define	RCC_AHB4LPENR_GPIOBLPEN					(0x1u<<1)
#define	RCC_AHB4LPENR_GPIOALPEN					(0x1u<<0)

#define	RCC_AHB4LPENR_CRCLPEN_B_0X0				(0x0u<<19)
#define	RCC_AHB4LPENR_CRCLPEN_B_0X1				(0x1u<<19)
#define	RCC_AHB4LPENR_PWRLPEN_B_0X0				(0x0u<<18)
#define	RCC_AHB4LPENR_PWRLPEN_B_0X1				(0x1u<<18)
#define	RCC_AHB4LPENR_GPIOQLPEN_B_0X0			(0x0u<<16)
#define	RCC_AHB4LPENR_GPIOQLPEN_B_0X1			(0x1u<<16)
#define	RCC_AHB4LPENR_GPIOPLPEN_B_0X0			(0x0u<<15)
#define	RCC_AHB4LPENR_GPIOPLPEN_B_0X1			(0x1u<<15)
#define	RCC_AHB4LPENR_GPIOOLPEN_B_0X0			(0x0u<<14)
#define	RCC_AHB4LPENR_GPIOOLPEN_B_0X1			(0x1u<<14)
#define	RCC_AHB4LPENR_GPIONLPEN_B_0X0			(0x0u<<13)
#define	RCC_AHB4LPENR_GPIONLPEN_B_0X1			(0x1u<<13)
#define	RCC_AHB4LPENR_GPIOHLPEN_B_0X0			(0x0u<<7)
#define	RCC_AHB4LPENR_GPIOHLPEN_B_0X1			(0x1u<<7)
#define	RCC_AHB4LPENR_GPIOGLPEN_B_0X0			(0x0u<<6)
#define	RCC_AHB4LPENR_GPIOGLPEN_B_0X1			(0x1u<<6)
#define	RCC_AHB4LPENR_GPIOFLPEN_B_0X0			(0x0u<<5)
#define	RCC_AHB4LPENR_GPIOFLPEN_B_0X1			(0x1u<<5)
#define	RCC_AHB4LPENR_GPIOELPEN_B_0X0			(0x0u<<4)
#define	RCC_AHB4LPENR_GPIOELPEN_B_0X1			(0x1u<<4)
#define	RCC_AHB4LPENR_GPIODLPEN_B_0X0			(0x0u<<3)
#define	RCC_AHB4LPENR_GPIODLPEN_B_0X1			(0x1u<<3)
#define	RCC_AHB4LPENR_GPIOCLPEN_B_0X0			(0x0u<<2)
#define	RCC_AHB4LPENR_GPIOCLPEN_B_0X1			(0x1u<<2)
#define	RCC_AHB4LPENR_GPIOBLPEN_B_0X0			(0x0u<<1)
#define	RCC_AHB4LPENR_GPIOBLPEN_B_0X1			(0x1u<<1)
#define	RCC_AHB4LPENR_GPIOALPEN_B_0X0			(0x0u<<0)
#define	RCC_AHB4LPENR_GPIOALPEN_B_0X1			(0x1u<<0)

// AHB5LPENR Configuration

#define	RCC_AHB5LPENR_NPULPEN					(0x1u<<31)
#define	RCC_AHB5LPENR_NPUCACHELPEN				(0x1u<<30)
#define	RCC_AHB5LPENR_OTG2LPEN					(0x1u<<29)
#define	RCC_AHB5LPENR_OTGPHY2LPEN				(0x1u<<28)
#define	RCC_AHB5LPENR_OTGPHY1LPEN				(0x1u<<27)
#define	RCC_AHB5LPENR_OTG1LPEN					(0x1u<<26)
#define	RCC_AHB5LPENR_ETH1LPEN					(0x1u<<25)
#define	RCC_AHB5LPENR_ETH1RXLPEN				(0x1u<<24)
#define	RCC_AHB5LPENR_ETH1TXLPEN				(0x1u<<23)
#define	RCC_AHB5LPENR_ETH1MACLPEN				(0x1u<<22)
#define	RCC_AHB5LPENR_GPULPEN					(0x1u<<20)
#define	RCC_AHB5LPENR_GFXMMULPEN				(0x1u<<19)
#define	RCC_AHB5LPENR_MCE4LPEN					(0x1u<<18)
#define	RCC_AHB5LPENR_XSPI3LPEN					(0x1u<<17)
#define	RCC_AHB5LPENR_MCE3LPEN					(0x1u<<16)
#define	RCC_AHB5LPENR_MCE2LPEN					(0x1u<<15)
#define	RCC_AHB5LPENR_MCE1LPEN					(0x1u<<14)
#define	RCC_AHB5LPENR_XSPIMLPEN					(0x1u<<13)
#define	RCC_AHB5LPENR_XSPI2LPEN					(0x1u<<12)
#define	RCC_AHB5LPENR_SDMMC1LPEN				(0x1u<<8)
#define	RCC_AHB5LPENR_SDMMC2LPEN				(0x1u<<7)
#define	RCC_AHB5LPENR_PSSILPEN					(0x1u<<6)
#define	RCC_AHB5LPENR_XSPI1LPEN					(0x1u<<5)
#define	RCC_AHB5LPENR_FMCLPEN					(0x1u<<4)
#define	RCC_AHB5LPENR_JPEGLPEN					(0x1u<<3)
#define	RCC_AHB5LPENR_DMA2DLPEN					(0x1u<<1)
#define	RCC_AHB5LPENR_HPDMA1LPEN				(0x1u<<0)

#define	RCC_AHB5LPENR_NPULPEN_B_0X0				(0x0u<<31)
#define	RCC_AHB5LPENR_NPULPEN_B_0X1				(0x1u<<31)
#define	RCC_AHB5LPENR_NPUCACHELPEN_B_0X0		(0x0u<<30)
#define	RCC_AHB5LPENR_NPUCACHELPEN_B_0X1		(0x1u<<30)
#define	RCC_AHB5LPENR_OTG2LPEN_B_0X0			(0x0u<<29)
#define	RCC_AHB5LPENR_OTG2LPEN_B_0X1			(0x1u<<29)
#define	RCC_AHB5LPENR_OTGPHY2LPEN_B_0X0			(0x0u<<28)
#define	RCC_AHB5LPENR_OTGPHY2LPEN_B_0X1			(0x1u<<28)
#define	RCC_AHB5LPENR_OTGPHY1LPEN_B_0X0			(0x0u<<27)
#define	RCC_AHB5LPENR_OTGPHY1LPEN_B_0X1			(0x1u<<27)
#define	RCC_AHB5LPENR_OTG1LPEN_B_0X0			(0x0u<<26)
#define	RCC_AHB5LPENR_OTG1LPEN_B_0X1			(0x1u<<26)
#define	RCC_AHB5LPENR_ETH1LPEN_B_0X0			(0x0u<<25)
#define	RCC_AHB5LPENR_ETH1LPEN_B_0X1			(0x1u<<25)
#define	RCC_AHB5LPENR_ETH1RXLPEN_B_0X0			(0x0u<<24)
#define	RCC_AHB5LPENR_ETH1RXLPEN_B_0X1			(0x1u<<24)
#define	RCC_AHB5LPENR_ETH1TXLPEN_B_0X0			(0x0u<<23)
#define	RCC_AHB5LPENR_ETH1TXLPEN_B_0X1			(0x1u<<23)
#define	RCC_AHB5LPENR_ETH1MACLPEN_B_0X0			(0x0u<<22)
#define	RCC_AHB5LPENR_ETH1MACLPEN_B_0X1			(0x1u<<22)
#define	RCC_AHB5LPENR_GPULPEN_B_0X0				(0x0u<<20)
#define	RCC_AHB5LPENR_GPULPEN_B_0X1				(0x1u<<20)
#define	RCC_AHB5LPENR_GFXMMULPEN_B_0X0			(0x0u<<19)
#define	RCC_AHB5LPENR_GFXMMULPEN_B_0X1			(0x1u<<19)
#define	RCC_AHB5LPENR_MCE4LPEN_B_0X0			(0x0u<<18)
#define	RCC_AHB5LPENR_MCE4LPEN_B_0X1			(0x1u<<18)
#define	RCC_AHB5LPENR_XSPI3LPEN_B_0X0			(0x0u<<17)
#define	RCC_AHB5LPENR_XSPI3LPEN_B_0X1			(0x1u<<17)
#define	RCC_AHB5LPENR_MCE3LPEN_B_0X0			(0x0u<<16)
#define	RCC_AHB5LPENR_MCE3LPEN_B_0X1			(0x1u<<16)
#define	RCC_AHB5LPENR_MCE2LPEN_B_0X0			(0x0u<<15)
#define	RCC_AHB5LPENR_MCE2LPEN_B_0X1			(0x1u<<15)
#define	RCC_AHB5LPENR_MCE1LPEN_B_0X0			(0x0u<<14)
#define	RCC_AHB5LPENR_MCE1LPEN_B_0X1			(0x1u<<14)
#define	RCC_AHB5LPENR_XSPIMLPEN_B_0X0			(0x0u<<13)
#define	RCC_AHB5LPENR_XSPIMLPEN_B_0X1			(0x1u<<13)
#define	RCC_AHB5LPENR_XSPI2LPEN_B_0X0			(0x0u<<12)
#define	RCC_AHB5LPENR_XSPI2LPEN_B_0X1			(0x1u<<12)
#define	RCC_AHB5LPENR_SDMMC1LPEN_B_0X0			(0x0u<<8)
#define	RCC_AHB5LPENR_SDMMC1LPEN_B_0X1			(0x1u<<8)
#define	RCC_AHB5LPENR_SDMMC2LPEN_B_0X0			(0x0u<<7)
#define	RCC_AHB5LPENR_SDMMC2LPEN_B_0X1			(0x1u<<7)
#define	RCC_AHB5LPENR_PSSILPEN_B_0X0			(0x0u<<6)
#define	RCC_AHB5LPENR_PSSILPEN_B_0X1			(0x1u<<6)
#define	RCC_AHB5LPENR_XSPI1LPEN_B_0X0			(0x0u<<5)
#define	RCC_AHB5LPENR_XSPI1LPEN_B_0X1			(0x1u<<5)
#define	RCC_AHB5LPENR_FMCLPEN_B_0X0				(0x0u<<4)
#define	RCC_AHB5LPENR_FMCLPEN_B_0X1				(0x1u<<4)
#define	RCC_AHB5LPENR_JPEGLPEN_B_0X0			(0x0u<<3)
#define	RCC_AHB5LPENR_JPEGLPEN_B_0X1			(0x1u<<3)
#define	RCC_AHB5LPENR_DMA2DLPEN_B_0X0			(0x0u<<1)
#define	RCC_AHB5LPENR_DMA2DLPEN_B_0X1			(0x1u<<1)
#define	RCC_AHB5LPENR_HPDMA1LPEN_B_0X0			(0x0u<<0)
#define	RCC_AHB5LPENR_HPDMA1LPEN_B_0X1			(0x1u<<0)

// APB1LLPENR Configuration

#define	RCC_APB1LLPENR_UART8LPEN				(0x1u<<31)
#define	RCC_APB1LLPENR_UART7LPEN				(0x1u<<30)
#define	RCC_APB1LLPENR_I3C2LPEN					(0x1u<<25)
#define	RCC_APB1LLPENR_I3C1LPEN					(0x1u<<24)
#define	RCC_APB1LLPENR_I2C3LPEN					(0x1u<<23)
#define	RCC_APB1LLPENR_I2C2LPEN					(0x1u<<22)
#define	RCC_APB1LLPENR_I2C1LPEN					(0x1u<<21)
#define	RCC_APB1LLPENR_UART5LPEN				(0x1u<<20)
#define	RCC_APB1LLPENR_UART4LPEN				(0x1u<<19)
#define	RCC_APB1LLPENR_USART3LPEN				(0x1u<<18)
#define	RCC_APB1LLPENR_USART2LPEN				(0x1u<<17)
#define	RCC_APB1LLPENR_SPDIFRX1LPEN				(0x1u<<16)
#define	RCC_APB1LLPENR_SPI3LPEN					(0x1u<<15)
#define	RCC_APB1LLPENR_SPI2LPEN					(0x1u<<14)
#define	RCC_APB1LLPENR_TIM11LPEN				(0x1u<<13)
#define	RCC_APB1LLPENR_TIM10LPEN				(0x1u<<12)
#define	RCC_APB1LLPENR_WWDGLPEN					(0x1u<<11)
#define	RCC_APB1LLPENR_LPTIM1LPEN				(0x1u<<9)
#define	RCC_APB1LLPENR_TIM14LPEN				(0x1u<<8)
#define	RCC_APB1LLPENR_TIM13LPEN				(0x1u<<7)
#define	RCC_APB1LLPENR_TIM12LPEN				(0x1u<<6)
#define	RCC_APB1LLPENR_TIM7LPEN					(0x1u<<5)
#define	RCC_APB1LLPENR_TIM6LPEN					(0x1u<<4)
#define	RCC_APB1LLPENR_TIM5LPEN					(0x1u<<3)
#define	RCC_APB1LLPENR_TIM4LPEN					(0x1u<<2)
#define	RCC_APB1LLPENR_TIM3LPEN					(0x1u<<1)
#define	RCC_APB1LLPENR_TIM2LPEN					(0x1u<<0)

#define	RCC_APB1LLPENR_UART8LPEN_B_0X0			(0x0u<<31)
#define	RCC_APB1LLPENR_UART8LPEN_B_0X1			(0x1u<<31)
#define	RCC_APB1LLPENR_UART7LPEN_B_0X0			(0x0u<<30)
#define	RCC_APB1LLPENR_UART7LPEN_B_0X1			(0x1u<<30)
#define	RCC_APB1LLPENR_I3C2LPEN_B_0X0			(0x0u<<25)
#define	RCC_APB1LLPENR_I3C2LPEN_B_0X1			(0x1u<<25)
#define	RCC_APB1LLPENR_I3C1LPEN_B_0X0			(0x0u<<24)
#define	RCC_APB1LLPENR_I3C1LPEN_B_0X1			(0x1u<<24)
#define	RCC_APB1LLPENR_I2C3LPEN_B_0X0			(0x0u<<23)
#define	RCC_APB1LLPENR_I2C3LPEN_B_0X1			(0x1u<<23)
#define	RCC_APB1LLPENR_I2C2LPEN_B_0X0			(0x0u<<22)
#define	RCC_APB1LLPENR_I2C2LPEN_B_0X1			(0x1u<<22)
#define	RCC_APB1LLPENR_I2C1LPEN_B_0X0			(0x0u<<21)
#define	RCC_APB1LLPENR_I2C1LPEN_B_0X1			(0x1u<<21)
#define	RCC_APB1LLPENR_UART5LPEN_B_0X0			(0x0u<<20)
#define	RCC_APB1LLPENR_UART5LPEN_B_0X1			(0x1u<<20)
#define	RCC_APB1LLPENR_UART4LPEN_B_0X0			(0x0u<<19)
#define	RCC_APB1LLPENR_UART4LPEN_B_0X1			(0x1u<<19)
#define	RCC_APB1LLPENR_USART3LPEN_B_0X0			(0x0u<<18)
#define	RCC_APB1LLPENR_USART3LPEN_B_0X1			(0x1u<<18)
#define	RCC_APB1LLPENR_USART2LPEN_B_0X0			(0x0u<<17)
#define	RCC_APB1LLPENR_USART2LPEN_B_0X1			(0x1u<<17)
#define	RCC_APB1LLPENR_SPDIFRX1LPEN_B_0X0		(0x0u<<16)
#define	RCC_APB1LLPENR_SPDIFRX1LPEN_B_0X1		(0x1u<<16)
#define	RCC_APB1LLPENR_SPI3LPEN_B_0X0			(0x0u<<15)
#define	RCC_APB1LLPENR_SPI3LPEN_B_0X1			(0x1u<<15)
#define	RCC_APB1LLPENR_SPI2LPEN_B_0X0			(0x0u<<14)
#define	RCC_APB1LLPENR_SPI2LPEN_B_0X1			(0x1u<<14)
#define	RCC_APB1LLPENR_TIM11LPEN_B_0X0			(0x0u<<13)
#define	RCC_APB1LLPENR_TIM11LPEN_B_0X1			(0x1u<<13)
#define	RCC_APB1LLPENR_TIM10LPEN_B_0X0			(0x0u<<12)
#define	RCC_APB1LLPENR_TIM10LPEN_B_0X1			(0x1u<<12)
#define	RCC_APB1LLPENR_WWDGLPEN_B_0X0			(0x0u<<11)
#define	RCC_APB1LLPENR_WWDGLPEN_B_0X1			(0x1u<<11)
#define	RCC_APB1LLPENR_LPTIM1LPEN_B_0X0			(0x0u<<9)
#define	RCC_APB1LLPENR_LPTIM1LPEN_B_0X1			(0x1u<<9)
#define	RCC_APB1LLPENR_TIM14LPEN_B_0X0			(0x0u<<8)
#define	RCC_APB1LLPENR_TIM14LPEN_B_0X1			(0x1u<<8)
#define	RCC_APB1LLPENR_TIM13LPEN_B_0X0			(0x0u<<7)
#define	RCC_APB1LLPENR_TIM13LPEN_B_0X1			(0x1u<<7)
#define	RCC_APB1LLPENR_TIM12LPEN_B_0X0			(0x0u<<6)
#define	RCC_APB1LLPENR_TIM12LPEN_B_0X1			(0x1u<<6)
#define	RCC_APB1LLPENR_TIM7LPEN_B_0X0			(0x0u<<5)
#define	RCC_APB1LLPENR_TIM7LPEN_B_0X1			(0x1u<<5)
#define	RCC_APB1LLPENR_TIM6LPEN_B_0X0			(0x0u<<4)
#define	RCC_APB1LLPENR_TIM6LPEN_B_0X1			(0x1u<<4)
#define	RCC_APB1LLPENR_TIM5LPEN_B_0X0			(0x0u<<3)
#define	RCC_APB1LLPENR_TIM5LPEN_B_0X1			(0x1u<<3)
#define	RCC_APB1LLPENR_TIM4LPEN_B_0X0			(0x0u<<2)
#define	RCC_APB1LLPENR_TIM4LPEN_B_0X1			(0x1u<<2)
#define	RCC_APB1LLPENR_TIM3LPEN_B_0X0			(0x0u<<1)
#define	RCC_APB1LLPENR_TIM3LPEN_B_0X1			(0x1u<<1)
#define	RCC_APB1LLPENR_TIM2LPEN_B_0X0			(0x0u<<0)
#define	RCC_APB1LLPENR_TIM2LPEN_B_0X1			(0x1u<<0)

// APB1HLPENR Configuration

#define	RCC_APB1HLPENR_UCPD1LPEN				(0x1u<<18)
#define	RCC_APB1HLPENR_FDCANLPEN				(0x1u<<8)
#define	RCC_APB1HLPENR_MDIOSLPEN				(0x1u<<5)

#define	RCC_APB1HLPENR_UCPD1LPEN_B_0X0			(0x0u<<18)
#define	RCC_APB1HLPENR_UCPD1LPEN_B_0X1			(0x1u<<18)
#define	RCC_APB1HLPENR_FDCANLPEN_B_0X0			(0x0u<<8)
#define	RCC_APB1HLPENR_FDCANLPEN_B_0X1			(0x1u<<8)
#define	RCC_APB1HLPENR_MDIOSLPEN_B_0X0			(0x0u<<5)
#define	RCC_APB1HLPENR_MDIOSLPEN_B_0X1			(0x1u<<5)

// APB2LPENR Configuration

#define	RCC_APB2LPENR_SAI2LPEN					(0x1u<<22)
#define	RCC_APB2LPENR_SAI1LPEN					(0x1u<<21)
#define	RCC_APB2LPENR_SPI5LPEN					(0x1u<<20)
#define	RCC_APB2LPENR_TIM9LPEN					(0x1u<<19)
#define	RCC_APB2LPENR_TIM17LPEN					(0x1u<<18)
#define	RCC_APB2LPENR_TIM16LPEN					(0x1u<<17)
#define	RCC_APB2LPENR_TIM15LPEN					(0x1u<<16)
#define	RCC_APB2LPENR_TIM18LPEN					(0x1u<<15)
#define	RCC_APB2LPENR_SPI4LPEN					(0x1u<<13)
#define	RCC_APB2LPENR_SPI1LPEN					(0x1u<<12)
#define	RCC_APB2LPENR_USART10LPEN				(0x1u<<7)
#define	RCC_APB2LPENR_UART9LPEN					(0x1u<<6)
#define	RCC_APB2LPENR_USART6LPEN				(0x1u<<5)
#define	RCC_APB2LPENR_USART1LPEN				(0x1u<<4)
#define	RCC_APB2LPENR_TIM8LPEN					(0x1u<<1)
#define	RCC_APB2LPENR_TIM1LPEN					(0x1u<<0)

#define	RCC_APB2LPENR_SAI2LPEN_B_0X0			(0x0u<<22)
#define	RCC_APB2LPENR_SAI2LPEN_B_0X1			(0x1u<<22)
#define	RCC_APB2LPENR_SAI1LPEN_B_0X0			(0x0u<<21)
#define	RCC_APB2LPENR_SAI1LPEN_B_0X1			(0x1u<<21)
#define	RCC_APB2LPENR_SPI5LPEN_B_0X0			(0x0u<<20)
#define	RCC_APB2LPENR_SPI5LPEN_B_0X1			(0x1u<<20)
#define	RCC_APB2LPENR_TIM9LPEN_B_0X0			(0x0u<<19)
#define	RCC_APB2LPENR_TIM9LPEN_B_0X1			(0x1u<<19)
#define	RCC_APB2LPENR_TIM17LPEN_B_0X0			(0x0u<<18)
#define	RCC_APB2LPENR_TIM17LPEN_B_0X1			(0x1u<<18)
#define	RCC_APB2LPENR_TIM16LPEN_B_0X0			(0x0u<<17)
#define	RCC_APB2LPENR_TIM16LPEN_B_0X1			(0x1u<<17)
#define	RCC_APB2LPENR_TIM15LPEN_B_0X0			(0x0u<<16)
#define	RCC_APB2LPENR_TIM15LPEN_B_0X1			(0x1u<<16)
#define	RCC_APB2LPENR_TIM18LPEN_B_0X0			(0x0u<<15)
#define	RCC_APB2LPENR_TIM18LPEN_B_0X1			(0x1u<<15)
#define	RCC_APB2LPENR_SPI4LPEN_B_0X0			(0x0u<<13)
#define	RCC_APB2LPENR_SPI4LPEN_B_0X1			(0x1u<<13)
#define	RCC_APB2LPENR_SPI1LPEN_B_0X0			(0x0u<<12)
#define	RCC_APB2LPENR_SPI1LPEN_B_0X1			(0x1u<<12)
#define	RCC_APB2LPENR_USART10LPEN_B_0X0			(0x0u<<7)
#define	RCC_APB2LPENR_USART10LPEN_B_0X1			(0x1u<<7)
#define	RCC_APB2LPENR_UART9LPEN_B_0X0			(0x0u<<6)
#define	RCC_APB2LPENR_UART9LPEN_B_0X1			(0x1u<<6)
#define	RCC_APB2LPENR_USART6LPEN_B_0X0			(0x0u<<5)
#define	RCC_APB2LPENR_USART6LPEN_B_0X1			(0x1u<<5)
#define	RCC_APB2LPENR_USART1LPEN_B_0X0			(0x0u<<4)
#define	RCC_APB2LPENR_USART1LPEN_B_0X1			(0x1u<<4)
#define	RCC_APB2LPENR_TIM8LPEN_B_0X0			(0x0u<<1)
#define	RCC_APB2LPENR_TIM8LPEN_B_0X1			(0x1u<<1)
#define	RCC_APB2LPENR_TIM1LPEN_B_0X0			(0x0u<<0)
#define	RCC_APB2LPENR_TIM1LPEN_B_0X1			(0x1u<<0)

// APB3LPENR Configuration

#define	RCC_APB3LPENR_DFTLPEN					(0x1u<<2)

#define	RCC_APB3LPENR_DFTLPEN_B_0X0				(0x0u<<2)
#define	RCC_APB3LPENR_DFTLPEN_B_0X1				(0x1u<<2)

// APB4LLPENR Configuration

#define	RCC_APB4LLPENR_SERFLPEN					(0x1u<<31)
#define	RCC_APB4LLPENR_R2GNPULPEN				(0x1u<<23)
#define	RCC_APB4LLPENR_R2GRETLPEN				(0x1u<<22)
#define	RCC_APB4LLPENR_RTCAPBLPEN				(0x1u<<17)
#define	RCC_APB4LLPENR_RTCLPEN					(0x1u<<16)
#define	RCC_APB4LLPENR_VREFBUFLPEN				(0x1u<<15)
#define	RCC_APB4LLPENR_LPTIM5LPEN				(0x1u<<12)
#define	RCC_APB4LLPENR_LPTIM4LPEN				(0x1u<<11)
#define	RCC_APB4LLPENR_LPTIM3LPEN				(0x1u<<10)
#define	RCC_APB4LLPENR_LPTIM2LPEN				(0x1u<<9)
#define	RCC_APB4LLPENR_I2C4LPEN					(0x1u<<7)
#define	RCC_APB4LLPENR_SPI6LPEN					(0x1u<<5)
#define	RCC_APB4LLPENR_LPUART1LPEN				(0x1u<<3)
#define	RCC_APB4LLPENR_HDPLPEN					(0x1u<<2)

#define	RCC_APB4LLPENR_SERFLPEN_B_0X0			(0x0u<<31)
#define	RCC_APB4LLPENR_SERFLPEN_B_0X1			(0x1u<<31)
#define	RCC_APB4LLPENR_R2GNPULPEN_B_0X0			(0x0u<<23)
#define	RCC_APB4LLPENR_R2GNPULPEN_B_0X1			(0x1u<<23)
#define	RCC_APB4LLPENR_R2GRETLPEN_B_0X0			(0x0u<<22)
#define	RCC_APB4LLPENR_R2GRETLPEN_B_0X1			(0x1u<<22)
#define	RCC_APB4LLPENR_RTCAPBLPEN_B_0X0			(0x0u<<17)
#define	RCC_APB4LLPENR_RTCAPBLPEN_B_0X1			(0x1u<<17)
#define	RCC_APB4LLPENR_RTCLPEN_B_0X0			(0x0u<<16)
#define	RCC_APB4LLPENR_RTCLPEN_B_0X1			(0x1u<<16)
#define	RCC_APB4LLPENR_VREFBUFLPEN_B_0X0		(0x0u<<15)
#define	RCC_APB4LLPENR_VREFBUFLPEN_B_0X1		(0x1u<<15)
#define	RCC_APB4LLPENR_LPTIM5LPEN_B_0X0			(0x0u<<12)
#define	RCC_APB4LLPENR_LPTIM5LPEN_B_0X1			(0x1u<<12)
#define	RCC_APB4LLPENR_LPTIM4LPEN_B_0X0			(0x0u<<11)
#define	RCC_APB4LLPENR_LPTIM4LPEN_B_0X1			(0x1u<<11)
#define	RCC_APB4LLPENR_LPTIM3LPEN_B_0X0			(0x0u<<10)
#define	RCC_APB4LLPENR_LPTIM3LPEN_B_0X1			(0x1u<<10)
#define	RCC_APB4LLPENR_LPTIM2LPEN_B_0X0			(0x0u<<9)
#define	RCC_APB4LLPENR_LPTIM2LPEN_B_0X1			(0x1u<<9)
#define	RCC_APB4LLPENR_I2C4LPEN_B_0X0			(0x0u<<7)
#define	RCC_APB4LLPENR_I2C4LPEN_B_0X1			(0x1u<<7)
#define	RCC_APB4LLPENR_SPI6LPEN_B_0X0			(0x0u<<5)
#define	RCC_APB4LLPENR_SPI6LPEN_B_0X1			(0x1u<<5)
#define	RCC_APB4LLPENR_LPUART1LPEN_B_0X0		(0x0u<<3)
#define	RCC_APB4LLPENR_LPUART1LPEN_B_0X1		(0x1u<<3)
#define	RCC_APB4LLPENR_HDPLPEN_B_0X0			(0x0u<<2)
#define	RCC_APB4LLPENR_HDPLPEN_B_0X1			(0x1u<<2)

// APB4HLPENR Configuration

#define	RCC_APB4HLPENR_BUSPERFMLPEN				(0x1u<<4)
#define	RCC_APB4HLPENR_DTSLPEN					(0x1u<<2)
#define	RCC_APB4HLPENR_BSECLPEN					(0x1u<<1)
#define	RCC_APB4HLPENR_SYSCFGLPEN				(0x1u<<0)

#define	RCC_APB4HLPENR_BUSPERFMLPEN_B_0X0		(0x0u<<4)
#define	RCC_APB4HLPENR_BUSPERFMLPEN_B_0X1		(0x1u<<4)
#define	RCC_APB4HLPENR_DTSLPEN_B_0X0			(0x0u<<2)
#define	RCC_APB4HLPENR_DTSLPEN_B_0X1			(0x1u<<2)
#define	RCC_APB4HLPENR_BSECLPEN_B_0X0			(0x0u<<1)
#define	RCC_APB4HLPENR_BSECLPEN_B_0X1			(0x1u<<1)
#define	RCC_APB4HLPENR_SYSCFGLPEN_B_0X0			(0x0u<<0)
#define	RCC_APB4HLPENR_SYSCFGLPEN_B_0X1			(0x1u<<0)

// APB5LPENR Configuration

#define	RCC_APB5LPENR_CSILPEN					(0x1u<<6)
#define	RCC_APB5LPENR_VENCLPEN					(0x1u<<5)
#define	RCC_APB5LPENR_GFXTIMLPEN				(0x1u<<4)
#define	RCC_APB5LPENR_DCMIPPLPEN				(0x1u<<2)
#define	RCC_APB5LPENR_LTDCLPEN					(0x1u<<1)

#define	RCC_APB5LPENR_CSILPEN_B_0X0				(0x0u<<6)
#define	RCC_APB5LPENR_CSILPEN_B_0X1				(0x1u<<6)
#define	RCC_APB5LPENR_VENCLPEN_B_0X0			(0x0u<<5)
#define	RCC_APB5LPENR_VENCLPEN_B_0X1			(0x1u<<5)
#define	RCC_APB5LPENR_GFXTIMLPEN_B_0X0			(0x0u<<4)
#define	RCC_APB5LPENR_GFXTIMLPEN_B_0X1			(0x1u<<4)
#define	RCC_APB5LPENR_DCMIPPLPEN_B_0X0			(0x0u<<2)
#define	RCC_APB5LPENR_DCMIPPLPEN_B_0X1			(0x1u<<2)
#define	RCC_APB5LPENR_LTDCLPEN_B_0X0			(0x0u<<1)
#define	RCC_APB5LPENR_LTDCLPEN_B_0X1			(0x1u<<1)

// RDCR Configuration

#define	RCC_RDCR_EADLY							(0xFu<<24)
#define	RCC_RDCR_EADLY_0						(0x1u<<24)
#define	RCC_RDCR_MRD							(0x1Fu<<16)
#define	RCC_RDCR_MRD_0							(0x1u<<16)

#define	RCC_RDCR_EADLY_B_0X0					(0x0u<<24)
#define	RCC_RDCR_EADLY_B_0X1					(0x1u<<24)
#define	RCC_RDCR_EADLY_B_0X2					(0x2u<<24)
#define	RCC_RDCR_MRD_B_0X0						(0x0u<<16)
#define	RCC_RDCR_MRD_B_0X1						(0x1u<<16)
#define	RCC_RDCR_MRD_B_0X2						(0x2u<<16)
#define	RCC_RDCR_MRD_B_0X3						(0x3u<<16)
#define	RCC_RDCR_MRD_B_0X4						(0x4u<<16)
#define	RCC_RDCR_MRD_B_0X5						(0x5u<<16)
#define	RCC_RDCR_MRD_B_0X6						(0x6u<<16)
#define	RCC_RDCR_MRD_B_0X7						(0x7u<<16)
#define	RCC_RDCR_MRD_B_0X8						(0x8u<<16)
#define	RCC_RDCR_MRD_B_0X9						(0x9u<<16)
#define	RCC_RDCR_MRD_B_0XA						(0xAu<<16)
#define	RCC_RDCR_MRD_B_0XB						(0xBu<<16)
#define	RCC_RDCR_MRD_B_0XC						(0xCu<<16)
#define	RCC_RDCR_MRD_B_0XD						(0xDu<<16)
#define	RCC_RDCR_MRD_B_0XE						(0xEu<<16)
#define	RCC_RDCR_MRD_B_0XF						(0xFu<<16)

// SECCFGR0 Configuration

#define	RCC_SECCFGR0_HSESEC						(0x1u<<4)
#define	RCC_SECCFGR0_HSISEC						(0x1u<<3)
#define	RCC_SECCFGR0_MSISEC						(0x1u<<2)
#define	RCC_SECCFGR0_LSESEC						(0x1u<<1)
#define	RCC_SECCFGR0_LSISEC						(0x1u<<0)

#define	RCC_SECCFGR0_HSESEC_B_0X0				(0x0u<<4)
#define	RCC_SECCFGR0_HSESEC_B_0X1				(0x1u<<4)
#define	RCC_SECCFGR0_HSISEC_B_0X0				(0x0u<<3)
#define	RCC_SECCFGR0_HSISEC_B_0X1				(0x1u<<3)
#define	RCC_SECCFGR0_MSISEC_B_0X0				(0x0u<<2)
#define	RCC_SECCFGR0_MSISEC_B_0X1				(0x1u<<2)
#define	RCC_SECCFGR0_LSESEC_B_0X0				(0x0u<<1)
#define	RCC_SECCFGR0_LSESEC_B_0X1				(0x1u<<1)
#define	RCC_SECCFGR0_LSISEC_B_0X0				(0x0u<<0)
#define	RCC_SECCFGR0_LSISEC_B_0X1				(0x1u<<0)

// PRIVCFGR0 Configuration

#define	RCC_PRIVCFGR0_HSEPV						(0x1u<<4)
#define	RCC_PRIVCFGR0_HSIPV						(0x1u<<3)
#define	RCC_PRIVCFGR0_MSIPV						(0x1u<<2)
#define	RCC_PRIVCFGR0_LSEPV						(0x1u<<1)
#define	RCC_PRIVCFGR0_LSIPV						(0x1u<<0)

#define	RCC_PRIVCFGR0_HSEPV_B_0X0				(0x0u<<4)
#define	RCC_PRIVCFGR0_HSEPV_B_0X1				(0x1u<<4)
#define	RCC_PRIVCFGR0_HSIPV_B_0X0				(0x0u<<3)
#define	RCC_PRIVCFGR0_HSIPV_B_0X1				(0x1u<<3)
#define	RCC_PRIVCFGR0_MSIPV_B_0X0				(0x0u<<2)
#define	RCC_PRIVCFGR0_MSIPV_B_0X1				(0x1u<<2)
#define	RCC_PRIVCFGR0_LSEPV_B_0X0				(0x0u<<1)
#define	RCC_PRIVCFGR0_LSEPV_B_0X1				(0x1u<<1)
#define	RCC_PRIVCFGR0_LSIPV_B_0X0				(0x0u<<0)
#define	RCC_PRIVCFGR0_LSIPV_B_0X1				(0x1u<<0)

// LOCKCFGR0 Configuration

#define	RCC_LOCKCFGR0_HSELOCK					(0x1u<<4)
#define	RCC_LOCKCFGR0_HSILOCK					(0x1u<<3)
#define	RCC_LOCKCFGR0_MSILOCK					(0x1u<<2)
#define	RCC_LOCKCFGR0_LSELOCK					(0x1u<<1)
#define	RCC_LOCKCFGR0_LSILOCK					(0x1u<<0)

#define	RCC_LOCKCFGR0_HSELOCK_B_0X0				(0x0u<<4)
#define	RCC_LOCKCFGR0_HSELOCK_B_0X1				(0x1u<<4)
#define	RCC_LOCKCFGR0_HSILOCK_B_0X0				(0x0u<<3)
#define	RCC_LOCKCFGR0_HSILOCK_B_0X1				(0x1u<<3)
#define	RCC_LOCKCFGR0_MSILOCK_B_0X0				(0x0u<<2)
#define	RCC_LOCKCFGR0_MSILOCK_B_0X1				(0x1u<<2)
#define	RCC_LOCKCFGR0_LSELOCK_B_0X0				(0x0u<<1)
#define	RCC_LOCKCFGR0_LSELOCK_B_0X1				(0x1u<<1)
#define	RCC_LOCKCFGR0_LSILOCK_B_0X0				(0x0u<<0)
#define	RCC_LOCKCFGR0_LSILOCK_B_0X1				(0x1u<<0)

// PUBCFGR0 Configuration

#define	RCC_PUBCFGR0_HSEPUB						(0x1u<<4)
#define	RCC_PUBCFGR0_HSIPUB						(0x1u<<3)
#define	RCC_PUBCFGR0_MSIPUB						(0x1u<<2)
#define	RCC_PUBCFGR0_LSEPUB						(0x1u<<1)
#define	RCC_PUBCFGR0_LSIPUB						(0x1u<<0)

#define	RCC_PUBCFGR0_HSEPUB_B_0X0				(0x0u<<4)
#define	RCC_PUBCFGR0_HSEPUB_B_0X1				(0x1u<<4)
#define	RCC_PUBCFGR0_HSIPUB_B_0X0				(0x0u<<3)
#define	RCC_PUBCFGR0_HSIPUB_B_0X1				(0x1u<<3)
#define	RCC_PUBCFGR0_MSIPUB_B_0X0				(0x0u<<2)
#define	RCC_PUBCFGR0_MSIPUB_B_0X1				(0x1u<<2)
#define	RCC_PUBCFGR0_LSEPUB_B_0X0				(0x0u<<1)
#define	RCC_PUBCFGR0_LSEPUB_B_0X1				(0x1u<<1)
#define	RCC_PUBCFGR0_LSIPUB_B_0X0				(0x0u<<0)
#define	RCC_PUBCFGR0_LSIPUB_B_0X1				(0x1u<<0)

// SECCFGR1 Configuration

#define	RCC_SECCFGR1_PLL4SEC					(0x1u<<3)
#define	RCC_SECCFGR1_PLL3SEC					(0x1u<<2)
#define	RCC_SECCFGR1_PLL2SEC					(0x1u<<1)
#define	RCC_SECCFGR1_PLL1SEC					(0x1u<<0)

#define	RCC_SECCFGR1_PLL4SEC_B_0X0				(0x0u<<3)
#define	RCC_SECCFGR1_PLL4SEC_B_0X1				(0x1u<<3)
#define	RCC_SECCFGR1_PLL3SEC_B_0X0				(0x0u<<2)
#define	RCC_SECCFGR1_PLL3SEC_B_0X1				(0x1u<<2)
#define	RCC_SECCFGR1_PLL2SEC_B_0X0				(0x0u<<1)
#define	RCC_SECCFGR1_PLL2SEC_B_0X1				(0x1u<<1)
#define	RCC_SECCFGR1_PLL1SEC_B_0X0				(0x0u<<0)
#define	RCC_SECCFGR1_PLL1SEC_B_0X1				(0x1u<<0)

// PRIVCFGR1 Configuration

#define	RCC_PRIVCFGR1_PLL4PV					(0x1u<<3)
#define	RCC_PRIVCFGR1_PLL3PV					(0x1u<<2)
#define	RCC_PRIVCFGR1_PLL2PV					(0x1u<<1)
#define	RCC_PRIVCFGR1_PLL1PV					(0x1u<<0)

#define	RCC_PRIVCFGR1_PLL4PV_B_0X0				(0x0u<<3)
#define	RCC_PRIVCFGR1_PLL4PV_B_0X1				(0x1u<<3)
#define	RCC_PRIVCFGR1_PLL3PV_B_0X0				(0x0u<<2)
#define	RCC_PRIVCFGR1_PLL3PV_B_0X1				(0x1u<<2)
#define	RCC_PRIVCFGR1_PLL2PV_B_0X0				(0x0u<<1)
#define	RCC_PRIVCFGR1_PLL2PV_B_0X1				(0x1u<<1)
#define	RCC_PRIVCFGR1_PLL1PV_B_0X0				(0x0u<<0)
#define	RCC_PRIVCFGR1_PLL1PV_B_0X1				(0x1u<<0)

// LOCKCFGR1 Configuration

#define	RCC_LOCKCFGR1_PLL4LOCK					(0x1u<<3)
#define	RCC_LOCKCFGR1_PLL3LOCK					(0x1u<<2)
#define	RCC_LOCKCFGR1_PLL2LOCK					(0x1u<<1)
#define	RCC_LOCKCFGR1_PLL1LOCK					(0x1u<<0)

#define	RCC_LOCKCFGR1_PLL4LOCK_B_0X0			(0x0u<<3)
#define	RCC_LOCKCFGR1_PLL4LOCK_B_0X1			(0x1u<<3)
#define	RCC_LOCKCFGR1_PLL3LOCK_B_0X0			(0x0u<<2)
#define	RCC_LOCKCFGR1_PLL3LOCK_B_0X1			(0x1u<<2)
#define	RCC_LOCKCFGR1_PLL2LOCK_B_0X0			(0x0u<<1)
#define	RCC_LOCKCFGR1_PLL2LOCK_B_0X1			(0x1u<<1)
#define	RCC_LOCKCFGR1_PLL1LOCK_B_0X0			(0x0u<<0)
#define	RCC_LOCKCFGR1_PLL1LOCK_B_0X1			(0x1u<<0)

// PUBCFGR1 Configuration

#define	RCC_PUBCFGR1_PLL4PUB					(0x1u<<3)
#define	RCC_PUBCFGR1_PLL3PUB					(0x1u<<2)
#define	RCC_PUBCFGR1_PLL2PUB					(0x1u<<1)
#define	RCC_PUBCFGR1_PLL1PUB					(0x1u<<0)

#define	RCC_PUBCFGR1_PLL4PUB_B_0X0				(0x0u<<3)
#define	RCC_PUBCFGR1_PLL4PUB_B_0X1				(0x1u<<3)
#define	RCC_PUBCFGR1_PLL3PUB_B_0X0				(0x0u<<2)
#define	RCC_PUBCFGR1_PLL3PUB_B_0X1				(0x1u<<2)
#define	RCC_PUBCFGR1_PLL2PUB_B_0X0				(0x0u<<1)
#define	RCC_PUBCFGR1_PLL2PUB_B_0X1				(0x1u<<1)
#define	RCC_PUBCFGR1_PLL1PUB_B_0X0				(0x0u<<0)
#define	RCC_PUBCFGR1_PLL1PUB_B_0X1				(0x1u<<0)

// SECCFGR2 Configuration

#define	RCC_SECCFGR2_IC20SEC					(0x1u<<19)
#define	RCC_SECCFGR2_IC19SEC					(0x1u<<18)
#define	RCC_SECCFGR2_IC18SEC					(0x1u<<17)
#define	RCC_SECCFGR2_IC17SEC					(0x1u<<16)
#define	RCC_SECCFGR2_IC16SEC					(0x1u<<15)
#define	RCC_SECCFGR2_IC15SEC					(0x1u<<14)
#define	RCC_SECCFGR2_IC14SEC					(0x1u<<13)
#define	RCC_SECCFGR2_IC13SEC					(0x1u<<12)
#define	RCC_SECCFGR2_IC12SEC					(0x1u<<11)
#define	RCC_SECCFGR2_IC11SEC					(0x1u<<10)
#define	RCC_SECCFGR2_IC10SEC					(0x1u<<9)
#define	RCC_SECCFGR2_IC9SEC						(0x1u<<8)
#define	RCC_SECCFGR2_IC8SEC						(0x1u<<7)
#define	RCC_SECCFGR2_IC7SEC						(0x1u<<6)
#define	RCC_SECCFGR2_IC6SEC						(0x1u<<5)
#define	RCC_SECCFGR2_IC5SEC						(0x1u<<4)
#define	RCC_SECCFGR2_IC4SEC						(0x1u<<3)
#define	RCC_SECCFGR2_IC3SEC						(0x1u<<2)
#define	RCC_SECCFGR2_IC2SEC						(0x1u<<1)
#define	RCC_SECCFGR2_IC1SEC						(0x1u<<0)

#define	RCC_SECCFGR2_IC20SEC_B_0X0				(0x0u<<19)
#define	RCC_SECCFGR2_IC20SEC_B_0X1				(0x1u<<19)
#define	RCC_SECCFGR2_IC19SEC_B_0X0				(0x0u<<18)
#define	RCC_SECCFGR2_IC19SEC_B_0X1				(0x1u<<18)
#define	RCC_SECCFGR2_IC18SEC_B_0X0				(0x0u<<17)
#define	RCC_SECCFGR2_IC18SEC_B_0X1				(0x1u<<17)
#define	RCC_SECCFGR2_IC17SEC_B_0X0				(0x0u<<16)
#define	RCC_SECCFGR2_IC17SEC_B_0X1				(0x1u<<16)
#define	RCC_SECCFGR2_IC16SEC_B_0X0				(0x0u<<15)
#define	RCC_SECCFGR2_IC16SEC_B_0X1				(0x1u<<15)
#define	RCC_SECCFGR2_IC15SEC_B_0X0				(0x0u<<14)
#define	RCC_SECCFGR2_IC15SEC_B_0X1				(0x1u<<14)
#define	RCC_SECCFGR2_IC14SEC_B_0X0				(0x0u<<13)
#define	RCC_SECCFGR2_IC14SEC_B_0X1				(0x1u<<13)
#define	RCC_SECCFGR2_IC13SEC_B_0X0				(0x0u<<12)
#define	RCC_SECCFGR2_IC13SEC_B_0X1				(0x1u<<12)
#define	RCC_SECCFGR2_IC12SEC_B_0X0				(0x0u<<11)
#define	RCC_SECCFGR2_IC12SEC_B_0X1				(0x1u<<11)
#define	RCC_SECCFGR2_IC11SEC_B_0X0				(0x0u<<10)
#define	RCC_SECCFGR2_IC11SEC_B_0X1				(0x1u<<10)
#define	RCC_SECCFGR2_IC10SEC_B_0X0				(0x0u<<9)
#define	RCC_SECCFGR2_IC10SEC_B_0X1				(0x1u<<9)
#define	RCC_SECCFGR2_IC9SEC_B_0X0				(0x0u<<8)
#define	RCC_SECCFGR2_IC9SEC_B_0X1				(0x1u<<8)
#define	RCC_SECCFGR2_IC8SEC_B_0X0				(0x0u<<7)
#define	RCC_SECCFGR2_IC8SEC_B_0X1				(0x1u<<7)
#define	RCC_SECCFGR2_IC7SEC_B_0X0				(0x0u<<6)
#define	RCC_SECCFGR2_IC7SEC_B_0X1				(0x1u<<6)
#define	RCC_SECCFGR2_IC6SEC_B_0X0				(0x0u<<5)
#define	RCC_SECCFGR2_IC6SEC_B_0X1				(0x1u<<5)
#define	RCC_SECCFGR2_IC5SEC_B_0X0				(0x0u<<4)
#define	RCC_SECCFGR2_IC5SEC_B_0X1				(0x1u<<4)
#define	RCC_SECCFGR2_IC4SEC_B_0X0				(0x0u<<3)
#define	RCC_SECCFGR2_IC4SEC_B_0X1				(0x1u<<3)
#define	RCC_SECCFGR2_IC3SEC_B_0X0				(0x0u<<2)
#define	RCC_SECCFGR2_IC3SEC_B_0X1				(0x1u<<2)
#define	RCC_SECCFGR2_IC2SEC_B_0X0				(0x0u<<1)
#define	RCC_SECCFGR2_IC2SEC_B_0X1				(0x1u<<1)
#define	RCC_SECCFGR2_IC1SEC_B_0X0				(0x0u<<0)
#define	RCC_SECCFGR2_IC1SEC_B_0X1				(0x1u<<0)

// PRIVCFGR2 Configuration

#define	RCC_PRIVCFGR2_IC20PV					(0x1u<<19)
#define	RCC_PRIVCFGR2_IC19PV					(0x1u<<18)
#define	RCC_PRIVCFGR2_IC18PV					(0x1u<<17)
#define	RCC_PRIVCFGR2_IC17PV					(0x1u<<16)
#define	RCC_PRIVCFGR2_IC16PV					(0x1u<<15)
#define	RCC_PRIVCFGR2_IC15PV					(0x1u<<14)
#define	RCC_PRIVCFGR2_IC14PV					(0x1u<<13)
#define	RCC_PRIVCFGR2_IC13PV					(0x1u<<12)
#define	RCC_PRIVCFGR2_IC12PV					(0x1u<<11)
#define	RCC_PRIVCFGR2_IC11PV					(0x1u<<10)
#define	RCC_PRIVCFGR2_IC10PV					(0x1u<<9)
#define	RCC_PRIVCFGR2_IC9PV						(0x1u<<8)
#define	RCC_PRIVCFGR2_IC8PV						(0x1u<<7)
#define	RCC_PRIVCFGR2_IC7PV						(0x1u<<6)
#define	RCC_PRIVCFGR2_IC6PV						(0x1u<<5)
#define	RCC_PRIVCFGR2_IC5PV						(0x1u<<4)
#define	RCC_PRIVCFGR2_IC4PV						(0x1u<<3)
#define	RCC_PRIVCFGR2_IC3PV						(0x1u<<2)
#define	RCC_PRIVCFGR2_IC2PV						(0x1u<<1)
#define	RCC_PRIVCFGR2_IC1PV						(0x1u<<0)

#define	RCC_PRIVCFGR2_IC20PV_B_0X0				(0x0u<<19)
#define	RCC_PRIVCFGR2_IC20PV_B_0X1				(0x1u<<19)
#define	RCC_PRIVCFGR2_IC19PV_B_0X0				(0x0u<<18)
#define	RCC_PRIVCFGR2_IC19PV_B_0X1				(0x1u<<18)
#define	RCC_PRIVCFGR2_IC18PV_B_0X0				(0x0u<<17)
#define	RCC_PRIVCFGR2_IC18PV_B_0X1				(0x1u<<17)
#define	RCC_PRIVCFGR2_IC17PV_B_0X0				(0x0u<<16)
#define	RCC_PRIVCFGR2_IC17PV_B_0X1				(0x1u<<16)
#define	RCC_PRIVCFGR2_IC16PV_B_0X0				(0x0u<<15)
#define	RCC_PRIVCFGR2_IC16PV_B_0X1				(0x1u<<15)
#define	RCC_PRIVCFGR2_IC15PV_B_0X0				(0x0u<<14)
#define	RCC_PRIVCFGR2_IC15PV_B_0X1				(0x1u<<14)
#define	RCC_PRIVCFGR2_IC14PV_B_0X0				(0x0u<<13)
#define	RCC_PRIVCFGR2_IC14PV_B_0X1				(0x1u<<13)
#define	RCC_PRIVCFGR2_IC13PV_B_0X0				(0x0u<<12)
#define	RCC_PRIVCFGR2_IC13PV_B_0X1				(0x1u<<12)
#define	RCC_PRIVCFGR2_IC12PV_B_0X0				(0x0u<<11)
#define	RCC_PRIVCFGR2_IC12PV_B_0X1				(0x1u<<11)
#define	RCC_PRIVCFGR2_IC11PV_B_0X0				(0x0u<<10)
#define	RCC_PRIVCFGR2_IC11PV_B_0X1				(0x1u<<10)
#define	RCC_PRIVCFGR2_IC10PV_B_0X0				(0x0u<<9)
#define	RCC_PRIVCFGR2_IC10PV_B_0X1				(0x1u<<9)
#define	RCC_PRIVCFGR2_IC9PV_B_0X0				(0x0u<<8)
#define	RCC_PRIVCFGR2_IC9PV_B_0X1				(0x1u<<8)
#define	RCC_PRIVCFGR2_IC8PV_B_0X0				(0x0u<<7)
#define	RCC_PRIVCFGR2_IC8PV_B_0X1				(0x1u<<7)
#define	RCC_PRIVCFGR2_IC7PV_B_0X0				(0x0u<<6)
#define	RCC_PRIVCFGR2_IC7PV_B_0X1				(0x1u<<6)
#define	RCC_PRIVCFGR2_IC6PV_B_0X0				(0x0u<<5)
#define	RCC_PRIVCFGR2_IC6PV_B_0X1				(0x1u<<5)
#define	RCC_PRIVCFGR2_IC5PV_B_0X0				(0x0u<<4)
#define	RCC_PRIVCFGR2_IC5PV_B_0X1				(0x1u<<4)
#define	RCC_PRIVCFGR2_IC4PV_B_0X0				(0x0u<<3)
#define	RCC_PRIVCFGR2_IC4PV_B_0X1				(0x1u<<3)
#define	RCC_PRIVCFGR2_IC3PV_B_0X0				(0x0u<<2)
#define	RCC_PRIVCFGR2_IC3PV_B_0X1				(0x1u<<2)
#define	RCC_PRIVCFGR2_IC2PV_B_0X0				(0x0u<<1)
#define	RCC_PRIVCFGR2_IC2PV_B_0X1				(0x1u<<1)
#define	RCC_PRIVCFGR2_IC1PV_B_0X0				(0x0u<<0)
#define	RCC_PRIVCFGR2_IC1PV_B_0X1				(0x1u<<0)

// LOCKCFGR2 Configuration

#define	RCC_LOCKCFGR2_IC20LOCK					(0x1u<<19)
#define	RCC_LOCKCFGR2_IC19LOCK					(0x1u<<18)
#define	RCC_LOCKCFGR2_IC18LOCK					(0x1u<<17)
#define	RCC_LOCKCFGR2_IC17LOCK					(0x1u<<16)
#define	RCC_LOCKCFGR2_IC16LOCK					(0x1u<<15)
#define	RCC_LOCKCFGR2_IC15LOCK					(0x1u<<14)
#define	RCC_LOCKCFGR2_IC14LOCK					(0x1u<<13)
#define	RCC_LOCKCFGR2_IC13LOCK					(0x1u<<12)
#define	RCC_LOCKCFGR2_IC12LOCK					(0x1u<<11)
#define	RCC_LOCKCFGR2_IC11LOCK					(0x1u<<10)
#define	RCC_LOCKCFGR2_IC10LOCK					(0x1u<<9)
#define	RCC_LOCKCFGR2_IC9LOCK					(0x1u<<8)
#define	RCC_LOCKCFGR2_IC8LOCK					(0x1u<<7)
#define	RCC_LOCKCFGR2_IC7LOCK					(0x1u<<6)
#define	RCC_LOCKCFGR2_IC6LOCK					(0x1u<<5)
#define	RCC_LOCKCFGR2_IC5LOCK					(0x1u<<4)
#define	RCC_LOCKCFGR2_IC4LOCK					(0x1u<<3)
#define	RCC_LOCKCFGR2_IC3LOCK					(0x1u<<2)
#define	RCC_LOCKCFGR2_IC2LOCK					(0x1u<<1)
#define	RCC_LOCKCFGR2_IC1LOCK					(0x1u<<0)

#define	RCC_LOCKCFGR2_IC20LOCK_B_0X0			(0x0u<<19)
#define	RCC_LOCKCFGR2_IC20LOCK_B_0X1			(0x1u<<19)
#define	RCC_LOCKCFGR2_IC19LOCK_B_0X0			(0x0u<<18)
#define	RCC_LOCKCFGR2_IC19LOCK_B_0X1			(0x1u<<18)
#define	RCC_LOCKCFGR2_IC18LOCK_B_0X0			(0x0u<<17)
#define	RCC_LOCKCFGR2_IC18LOCK_B_0X1			(0x1u<<17)
#define	RCC_LOCKCFGR2_IC17LOCK_B_0X0			(0x0u<<16)
#define	RCC_LOCKCFGR2_IC17LOCK_B_0X1			(0x1u<<16)
#define	RCC_LOCKCFGR2_IC16LOCK_B_0X0			(0x0u<<15)
#define	RCC_LOCKCFGR2_IC16LOCK_B_0X1			(0x1u<<15)
#define	RCC_LOCKCFGR2_IC15LOCK_B_0X0			(0x0u<<14)
#define	RCC_LOCKCFGR2_IC15LOCK_B_0X1			(0x1u<<14)
#define	RCC_LOCKCFGR2_IC14LOCK_B_0X0			(0x0u<<13)
#define	RCC_LOCKCFGR2_IC14LOCK_B_0X1			(0x1u<<13)
#define	RCC_LOCKCFGR2_IC13LOCK_B_0X0			(0x0u<<12)
#define	RCC_LOCKCFGR2_IC13LOCK_B_0X1			(0x1u<<12)
#define	RCC_LOCKCFGR2_IC12LOCK_B_0X0			(0x0u<<11)
#define	RCC_LOCKCFGR2_IC12LOCK_B_0X1			(0x1u<<11)
#define	RCC_LOCKCFGR2_IC11LOCK_B_0X0			(0x0u<<10)
#define	RCC_LOCKCFGR2_IC11LOCK_B_0X1			(0x1u<<10)
#define	RCC_LOCKCFGR2_IC10LOCK_B_0X0			(0x0u<<9)
#define	RCC_LOCKCFGR2_IC10LOCK_B_0X1			(0x1u<<9)
#define	RCC_LOCKCFGR2_IC9LOCK_B_0X0				(0x0u<<8)
#define	RCC_LOCKCFGR2_IC9LOCK_B_0X1				(0x1u<<8)
#define	RCC_LOCKCFGR2_IC8LOCK_B_0X0				(0x0u<<7)
#define	RCC_LOCKCFGR2_IC8LOCK_B_0X1				(0x1u<<7)
#define	RCC_LOCKCFGR2_IC7LOCK_B_0X0				(0x0u<<6)
#define	RCC_LOCKCFGR2_IC7LOCK_B_0X1				(0x1u<<6)
#define	RCC_LOCKCFGR2_IC6LOCK_B_0X0				(0x0u<<5)
#define	RCC_LOCKCFGR2_IC6LOCK_B_0X1				(0x1u<<5)
#define	RCC_LOCKCFGR2_IC5LOCK_B_0X0				(0x0u<<4)
#define	RCC_LOCKCFGR2_IC5LOCK_B_0X1				(0x1u<<4)
#define	RCC_LOCKCFGR2_IC4LOCK_B_0X0				(0x0u<<3)
#define	RCC_LOCKCFGR2_IC4LOCK_B_0X1				(0x1u<<3)
#define	RCC_LOCKCFGR2_IC3LOCK_B_0X0				(0x0u<<2)
#define	RCC_LOCKCFGR2_IC3LOCK_B_0X1				(0x1u<<2)
#define	RCC_LOCKCFGR2_IC2LOCK_B_0X0				(0x0u<<1)
#define	RCC_LOCKCFGR2_IC2LOCK_B_0X1				(0x1u<<1)
#define	RCC_LOCKCFGR2_IC1LOCK_B_0X0				(0x0u<<0)
#define	RCC_LOCKCFGR2_IC1LOCK_B_0X1				(0x1u<<0)

// PUBCFGR2 Configuration

#define	RCC_PUBCFGR2_IC20PUB					(0x1u<<19)
#define	RCC_PUBCFGR2_IC19PUB					(0x1u<<18)
#define	RCC_PUBCFGR2_IC18PUB					(0x1u<<17)
#define	RCC_PUBCFGR2_IC17PUB					(0x1u<<16)
#define	RCC_PUBCFGR2_IC16PUB					(0x1u<<15)
#define	RCC_PUBCFGR2_IC15PUB					(0x1u<<14)
#define	RCC_PUBCFGR2_IC14PUB					(0x1u<<13)
#define	RCC_PUBCFGR2_IC13PUB					(0x1u<<12)
#define	RCC_PUBCFGR2_IC12PUB					(0x1u<<11)
#define	RCC_PUBCFGR2_IC11PUB					(0x1u<<10)
#define	RCC_PUBCFGR2_IC10PUB					(0x1u<<9)
#define	RCC_PUBCFGR2_IC9PUB						(0x1u<<8)
#define	RCC_PUBCFGR2_IC8PUB						(0x1u<<7)
#define	RCC_PUBCFGR2_IC7PUB						(0x1u<<6)
#define	RCC_PUBCFGR2_IC6PUB						(0x1u<<5)
#define	RCC_PUBCFGR2_IC5PUB						(0x1u<<4)
#define	RCC_PUBCFGR2_IC4PUB						(0x1u<<3)
#define	RCC_PUBCFGR2_IC3PUB						(0x1u<<2)
#define	RCC_PUBCFGR2_IC2PUB						(0x1u<<1)
#define	RCC_PUBCFGR2_IC1PUB						(0x1u<<0)

#define	RCC_PUBCFGR2_IC20PUB_B_0X0				(0x0u<<19)
#define	RCC_PUBCFGR2_IC20PUB_B_0X1				(0x1u<<19)
#define	RCC_PUBCFGR2_IC19PUB_B_0X0				(0x0u<<18)
#define	RCC_PUBCFGR2_IC19PUB_B_0X1				(0x1u<<18)
#define	RCC_PUBCFGR2_IC18PUB_B_0X0				(0x0u<<17)
#define	RCC_PUBCFGR2_IC18PUB_B_0X1				(0x1u<<17)
#define	RCC_PUBCFGR2_IC17PUB_B_0X0				(0x0u<<16)
#define	RCC_PUBCFGR2_IC17PUB_B_0X1				(0x1u<<16)
#define	RCC_PUBCFGR2_IC16PUB_B_0X0				(0x0u<<15)
#define	RCC_PUBCFGR2_IC16PUB_B_0X1				(0x1u<<15)
#define	RCC_PUBCFGR2_IC15PUB_B_0X0				(0x0u<<14)
#define	RCC_PUBCFGR2_IC15PUB_B_0X1				(0x1u<<14)
#define	RCC_PUBCFGR2_IC14PUB_B_0X0				(0x0u<<13)
#define	RCC_PUBCFGR2_IC14PUB_B_0X1				(0x1u<<13)
#define	RCC_PUBCFGR2_IC13PUB_B_0X0				(0x0u<<12)
#define	RCC_PUBCFGR2_IC13PUB_B_0X1				(0x1u<<12)
#define	RCC_PUBCFGR2_IC12PUB_B_0X0				(0x0u<<11)
#define	RCC_PUBCFGR2_IC12PUB_B_0X1				(0x1u<<11)
#define	RCC_PUBCFGR2_IC11PUB_B_0X0				(0x0u<<10)
#define	RCC_PUBCFGR2_IC11PUB_B_0X1				(0x1u<<10)
#define	RCC_PUBCFGR2_IC10PUB_B_0X0				(0x0u<<9)
#define	RCC_PUBCFGR2_IC10PUB_B_0X1				(0x1u<<9)
#define	RCC_PUBCFGR2_IC9PUB_B_0X0				(0x0u<<8)
#define	RCC_PUBCFGR2_IC9PUB_B_0X1				(0x1u<<8)
#define	RCC_PUBCFGR2_IC8PUB_B_0X0				(0x0u<<7)
#define	RCC_PUBCFGR2_IC8PUB_B_0X1				(0x1u<<7)
#define	RCC_PUBCFGR2_IC7PUB_B_0X0				(0x0u<<6)
#define	RCC_PUBCFGR2_IC7PUB_B_0X1				(0x1u<<6)
#define	RCC_PUBCFGR2_IC6PUB_B_0X0				(0x0u<<5)
#define	RCC_PUBCFGR2_IC6PUB_B_0X1				(0x1u<<5)
#define	RCC_PUBCFGR2_IC5PUB_B_0X0				(0x0u<<4)
#define	RCC_PUBCFGR2_IC5PUB_B_0X1				(0x1u<<4)
#define	RCC_PUBCFGR2_IC4PUB_B_0X0				(0x0u<<3)
#define	RCC_PUBCFGR2_IC4PUB_B_0X1				(0x1u<<3)
#define	RCC_PUBCFGR2_IC3PUB_B_0X0				(0x0u<<2)
#define	RCC_PUBCFGR2_IC3PUB_B_0X1				(0x1u<<2)
#define	RCC_PUBCFGR2_IC2PUB_B_0X0				(0x0u<<1)
#define	RCC_PUBCFGR2_IC2PUB_B_0X1				(0x1u<<1)
#define	RCC_PUBCFGR2_IC1PUB_B_0X0				(0x0u<<0)
#define	RCC_PUBCFGR2_IC1PUB_B_0X1				(0x1u<<0)

// SECCFGR3 Configuration

#define	RCC_SECCFGR3_DFTSEC						(0x1u<<6)
#define	RCC_SECCFGR3_RSTSEC						(0x1u<<5)
#define	RCC_SECCFGR3_INTSEC						(0x1u<<4)
#define	RCC_SECCFGR3_PERSEC						(0x1u<<3)
#define	RCC_SECCFGR3_BUSSEC						(0x1u<<2)
#define	RCC_SECCFGR3_SYSSEC						(0x1u<<1)
#define	RCC_SECCFGR3_MODSEC						(0x1u<<0)

#define	RCC_SECCFGR3_DFTSEC_B_0X0				(0x0u<<6)
#define	RCC_SECCFGR3_DFTSEC_B_0X1				(0x1u<<6)
#define	RCC_SECCFGR3_RSTSEC_B_0X0				(0x0u<<5)
#define	RCC_SECCFGR3_RSTSEC_B_0X1				(0x1u<<5)
#define	RCC_SECCFGR3_INTSEC_B_0X0				(0x0u<<4)
#define	RCC_SECCFGR3_INTSEC_B_0X1				(0x1u<<4)
#define	RCC_SECCFGR3_PERSEC_B_0X0				(0x0u<<3)
#define	RCC_SECCFGR3_PERSEC_B_0X1				(0x1u<<3)
#define	RCC_SECCFGR3_BUSSEC_B_0X0				(0x0u<<2)
#define	RCC_SECCFGR3_BUSSEC_B_0X1				(0x1u<<2)
#define	RCC_SECCFGR3_SYSSEC_B_0X0				(0x0u<<1)
#define	RCC_SECCFGR3_SYSSEC_B_0X1				(0x1u<<1)
#define	RCC_SECCFGR3_MODSEC_B_0X0				(0x0u<<0)
#define	RCC_SECCFGR3_MODSEC_B_0X1				(0x1u<<0)

// PRIVCFGR3 Configuration

#define	RCC_PRIVCFGR3_DFTPV						(0x1u<<6)
#define	RCC_PRIVCFGR3_RSTPV						(0x1u<<5)
#define	RCC_PRIVCFGR3_INTPV						(0x1u<<4)
#define	RCC_PRIVCFGR3_PERPV						(0x1u<<3)
#define	RCC_PRIVCFGR3_BUSPV						(0x1u<<2)
#define	RCC_PRIVCFGR3_SYSPV						(0x1u<<1)
#define	RCC_PRIVCFGR3_MODPV						(0x1u<<0)

#define	RCC_PRIVCFGR3_DFTPV_B_0X0				(0x0u<<6)
#define	RCC_PRIVCFGR3_DFTPV_B_0X1				(0x1u<<6)
#define	RCC_PRIVCFGR3_RSTPV_B_0X0				(0x0u<<5)
#define	RCC_PRIVCFGR3_RSTPV_B_0X1				(0x1u<<5)
#define	RCC_PRIVCFGR3_INTPV_B_0X0				(0x0u<<4)
#define	RCC_PRIVCFGR3_INTPV_B_0X1				(0x1u<<4)
#define	RCC_PRIVCFGR3_PERPV_B_0X0				(0x0u<<3)
#define	RCC_PRIVCFGR3_PERPV_B_0X1				(0x1u<<3)
#define	RCC_PRIVCFGR3_BUSPV_B_0X0				(0x0u<<2)
#define	RCC_PRIVCFGR3_BUSPV_B_0X1				(0x1u<<2)
#define	RCC_PRIVCFGR3_SYSPV_B_0X0				(0x0u<<1)
#define	RCC_PRIVCFGR3_SYSPV_B_0X1				(0x1u<<1)
#define	RCC_PRIVCFGR3_MODPV_B_0X0				(0x0u<<0)
#define	RCC_PRIVCFGR3_MODPV_B_0X1				(0x1u<<0)

// LOCKCFGR3 Configuration

#define	RCC_LOCKCFGR3_DFTLOCK					(0x1u<<6)
#define	RCC_LOCKCFGR3_RSTLOCK					(0x1u<<5)
#define	RCC_LOCKCFGR3_INTLOCK					(0x1u<<4)
#define	RCC_LOCKCFGR3_PERLOCK					(0x1u<<3)
#define	RCC_LOCKCFGR3_BUSLOCK					(0x1u<<2)
#define	RCC_LOCKCFGR3_SYSLOCK					(0x1u<<1)
#define	RCC_LOCKCFGR3_MODLOCK					(0x1u<<0)

#define	RCC_LOCKCFGR3_DFTLOCK_B_0X0				(0x0u<<6)
#define	RCC_LOCKCFGR3_DFTLOCK_B_0X1				(0x1u<<6)
#define	RCC_LOCKCFGR3_RSTLOCK_B_0X0				(0x0u<<5)
#define	RCC_LOCKCFGR3_RSTLOCK_B_0X1				(0x1u<<5)
#define	RCC_LOCKCFGR3_INTLOCK_B_0X0				(0x0u<<4)
#define	RCC_LOCKCFGR3_INTLOCK_B_0X1				(0x1u<<4)
#define	RCC_LOCKCFGR3_PERLOCK_B_0X0				(0x0u<<3)
#define	RCC_LOCKCFGR3_PERLOCK_B_0X1				(0x1u<<3)
#define	RCC_LOCKCFGR3_BUSLOCK_B_0X0				(0x0u<<2)
#define	RCC_LOCKCFGR3_BUSLOCK_B_0X1				(0x1u<<2)
#define	RCC_LOCKCFGR3_SYSLOCK_B_0X0				(0x0u<<1)
#define	RCC_LOCKCFGR3_SYSLOCK_B_0X1				(0x1u<<1)
#define	RCC_LOCKCFGR3_MODLOCK_B_0X0				(0x0u<<0)
#define	RCC_LOCKCFGR3_MODLOCK_B_0X1				(0x1u<<0)

// PUBCFGR3 Configuration

#define	RCC_PUBCFGR3_DFTPUB						(0x1u<<6)
#define	RCC_PUBCFGR3_RSTPUB						(0x1u<<5)
#define	RCC_PUBCFGR3_INTPUB						(0x1u<<4)
#define	RCC_PUBCFGR3_PERPUB						(0x1u<<3)
#define	RCC_PUBCFGR3_BUSPUB						(0x1u<<2)
#define	RCC_PUBCFGR3_SYSPUB						(0x1u<<1)
#define	RCC_PUBCFGR3_MODPUB						(0x1u<<0)

#define	RCC_PUBCFGR3_DFTPUB_B_0X0				(0x0u<<6)
#define	RCC_PUBCFGR3_DFTPUB_B_0X1				(0x1u<<6)
#define	RCC_PUBCFGR3_RSTPUB_B_0X0				(0x0u<<5)
#define	RCC_PUBCFGR3_RSTPUB_B_0X1				(0x1u<<5)
#define	RCC_PUBCFGR3_INTPUB_B_0X0				(0x0u<<4)
#define	RCC_PUBCFGR3_INTPUB_B_0X1				(0x1u<<4)
#define	RCC_PUBCFGR3_PERPUB_B_0X0				(0x0u<<3)
#define	RCC_PUBCFGR3_PERPUB_B_0X1				(0x1u<<3)
#define	RCC_PUBCFGR3_BUSPUB_B_0X0				(0x0u<<2)
#define	RCC_PUBCFGR3_BUSPUB_B_0X1				(0x1u<<2)
#define	RCC_PUBCFGR3_SYSPUB_B_0X0				(0x0u<<1)
#define	RCC_PUBCFGR3_SYSPUB_B_0X1				(0x1u<<1)
#define	RCC_PUBCFGR3_MODPUB_B_0X0				(0x0u<<0)
#define	RCC_PUBCFGR3_MODPUB_B_0X1				(0x1u<<0)

// SECCFGR4 Configuration

#define	RCC_SECCFGR4_NOCSEC						(0x1u<<13)
#define	RCC_SECCFGR4_APB5SEC					(0x1u<<12)
#define	RCC_SECCFGR4_APB4SEC					(0x1u<<11)
#define	RCC_SECCFGR4_APB3SEC					(0x1u<<10)
#define	RCC_SECCFGR4_APB2SEC					(0x1u<<9)
#define	RCC_SECCFGR4_APB1SEC					(0x1u<<8)
#define	RCC_SECCFGR4_AHB5SEC					(0x1u<<7)
#define	RCC_SECCFGR4_AHB4SEC					(0x1u<<6)
#define	RCC_SECCFGR4_AHB3SEC					(0x1u<<5)
#define	RCC_SECCFGR4_AHB2SEC					(0x1u<<4)
#define	RCC_SECCFGR4_AHB1SEC					(0x1u<<3)
#define	RCC_SECCFGR4_AHBMSEC					(0x1u<<2)
#define	RCC_SECCFGR4_ACLKNCSEC					(0x1u<<1)
#define	RCC_SECCFGR4_ACLKNSEC					(0x1u<<0)

#define	RCC_SECCFGR4_NOCSEC_B_0X0				(0x0u<<13)
#define	RCC_SECCFGR4_NOCSEC_B_0X1				(0x1u<<13)
#define	RCC_SECCFGR4_APB5SEC_B_0X0				(0x0u<<12)
#define	RCC_SECCFGR4_APB5SEC_B_0X1				(0x1u<<12)
#define	RCC_SECCFGR4_APB4SEC_B_0X0				(0x0u<<11)
#define	RCC_SECCFGR4_APB4SEC_B_0X1				(0x1u<<11)
#define	RCC_SECCFGR4_APB3SEC_B_0X0				(0x0u<<10)
#define	RCC_SECCFGR4_APB3SEC_B_0X1				(0x1u<<10)
#define	RCC_SECCFGR4_APB2SEC_B_0X0				(0x0u<<9)
#define	RCC_SECCFGR4_APB2SEC_B_0X1				(0x1u<<9)
#define	RCC_SECCFGR4_APB1SEC_B_0X0				(0x0u<<8)
#define	RCC_SECCFGR4_APB1SEC_B_0X1				(0x1u<<8)
#define	RCC_SECCFGR4_AHB5SEC_B_0X0				(0x0u<<7)
#define	RCC_SECCFGR4_AHB5SEC_B_0X1				(0x1u<<7)
#define	RCC_SECCFGR4_AHB4SEC_B_0X0				(0x0u<<6)
#define	RCC_SECCFGR4_AHB4SEC_B_0X1				(0x1u<<6)
#define	RCC_SECCFGR4_AHB3SEC_B_0X0				(0x0u<<5)
#define	RCC_SECCFGR4_AHB3SEC_B_0X1				(0x1u<<5)
#define	RCC_SECCFGR4_AHB2SEC_B_0X0				(0x0u<<4)
#define	RCC_SECCFGR4_AHB2SEC_B_0X1				(0x1u<<4)
#define	RCC_SECCFGR4_AHB1SEC_B_0X0				(0x0u<<3)
#define	RCC_SECCFGR4_AHB1SEC_B_0X1				(0x1u<<3)
#define	RCC_SECCFGR4_AHBMSEC_B_0X0				(0x0u<<2)
#define	RCC_SECCFGR4_AHBMSEC_B_0X1				(0x1u<<2)
#define	RCC_SECCFGR4_ACLKNCSEC_B_0X0			(0x0u<<1)
#define	RCC_SECCFGR4_ACLKNCSEC_B_0X1			(0x1u<<1)
#define	RCC_SECCFGR4_ACLKNSEC_B_0X0				(0x0u<<0)
#define	RCC_SECCFGR4_ACLKNSEC_B_0X1				(0x1u<<0)

// PRIVCFGR4 Configuration

#define	RCC_PRIVCFGR4_NOCPV						(0x1u<<13)
#define	RCC_PRIVCFGR4_APB5PV					(0x1u<<12)
#define	RCC_PRIVCFGR4_APB4PV					(0x1u<<11)
#define	RCC_PRIVCFGR4_APB3PV					(0x1u<<10)
#define	RCC_PRIVCFGR4_APB2PV					(0x1u<<9)
#define	RCC_PRIVCFGR4_APB1PV					(0x1u<<8)
#define	RCC_PRIVCFGR4_AHB5PV					(0x1u<<7)
#define	RCC_PRIVCFGR4_AHB4PV					(0x1u<<6)
#define	RCC_PRIVCFGR4_AHB3PV					(0x1u<<5)
#define	RCC_PRIVCFGR4_AHB2PV					(0x1u<<4)
#define	RCC_PRIVCFGR4_AHB1PV					(0x1u<<3)
#define	RCC_PRIVCFGR4_AHBMPV					(0x1u<<2)
#define	RCC_PRIVCFGR4_ACLKNCPV					(0x1u<<1)
#define	RCC_PRIVCFGR4_ACLKNPV					(0x1u<<0)

#define	RCC_PRIVCFGR4_NOCPV_B_0X0				(0x0u<<13)
#define	RCC_PRIVCFGR4_NOCPV_B_0X1				(0x1u<<13)
#define	RCC_PRIVCFGR4_APB5PV_B_0X0				(0x0u<<12)
#define	RCC_PRIVCFGR4_APB5PV_B_0X1				(0x1u<<12)
#define	RCC_PRIVCFGR4_APB4PV_B_0X0				(0x0u<<11)
#define	RCC_PRIVCFGR4_APB4PV_B_0X1				(0x1u<<11)
#define	RCC_PRIVCFGR4_APB3PV_B_0X0				(0x0u<<10)
#define	RCC_PRIVCFGR4_APB3PV_B_0X1				(0x1u<<10)
#define	RCC_PRIVCFGR4_APB2PV_B_0X0				(0x0u<<9)
#define	RCC_PRIVCFGR4_APB2PV_B_0X1				(0x1u<<9)
#define	RCC_PRIVCFGR4_APB1PV_B_0X0				(0x0u<<8)
#define	RCC_PRIVCFGR4_APB1PV_B_0X1				(0x1u<<8)
#define	RCC_PRIVCFGR4_AHB5PV_B_0X0				(0x0u<<7)
#define	RCC_PRIVCFGR4_AHB5PV_B_0X1				(0x1u<<7)
#define	RCC_PRIVCFGR4_AHB4PV_B_0X0				(0x0u<<6)
#define	RCC_PRIVCFGR4_AHB4PV_B_0X1				(0x1u<<6)
#define	RCC_PRIVCFGR4_AHB3PV_B_0X0				(0x0u<<5)
#define	RCC_PRIVCFGR4_AHB3PV_B_0X1				(0x1u<<5)
#define	RCC_PRIVCFGR4_AHB2PV_B_0X0				(0x0u<<4)
#define	RCC_PRIVCFGR4_AHB2PV_B_0X1				(0x1u<<4)
#define	RCC_PRIVCFGR4_AHB1PV_B_0X0				(0x0u<<3)
#define	RCC_PRIVCFGR4_AHB1PV_B_0X1				(0x1u<<3)
#define	RCC_PRIVCFGR4_AHBMPV_B_0X0				(0x0u<<2)
#define	RCC_PRIVCFGR4_AHBMPV_B_0X1				(0x1u<<2)
#define	RCC_PRIVCFGR4_ACLKNCPV_B_0X0			(0x0u<<1)
#define	RCC_PRIVCFGR4_ACLKNCPV_B_0X1			(0x1u<<1)
#define	RCC_PRIVCFGR4_ACLKNPV_B_0X0				(0x0u<<0)
#define	RCC_PRIVCFGR4_ACLKNPV_B_0X1				(0x1u<<0)

// LOCKCFGR4 Configuration

#define	RCC_LOCKCFGR4_NOCLOCK					(0x1u<<13)
#define	RCC_LOCKCFGR4_APB5LOCK					(0x1u<<12)
#define	RCC_LOCKCFGR4_APB4LOCK					(0x1u<<11)
#define	RCC_LOCKCFGR4_APB3LOCK					(0x1u<<10)
#define	RCC_LOCKCFGR4_APB2LOCK					(0x1u<<9)
#define	RCC_LOCKCFGR4_APB1LOCK					(0x1u<<8)
#define	RCC_LOCKCFGR4_AHB5LOCK					(0x1u<<7)
#define	RCC_LOCKCFGR4_AHB4LOCK					(0x1u<<6)
#define	RCC_LOCKCFGR4_AHB3LOCK					(0x1u<<5)
#define	RCC_LOCKCFGR4_AHB2LOCK					(0x1u<<4)
#define	RCC_LOCKCFGR4_AHB1LOCK					(0x1u<<3)
#define	RCC_LOCKCFGR4_AHBMLOCK					(0x1u<<2)
#define	RCC_LOCKCFGR4_ACLKNCLOCK				(0x1u<<1)
#define	RCC_LOCKCFGR4_ACLKNLOCK					(0x1u<<0)

#define	RCC_LOCKCFGR4_NOCLOCK_B_0X0				(0x0u<<13)
#define	RCC_LOCKCFGR4_NOCLOCK_B_0X1				(0x1u<<13)
#define	RCC_LOCKCFGR4_APB5LOCK_B_0X0			(0x0u<<12)
#define	RCC_LOCKCFGR4_APB5LOCK_B_0X1			(0x1u<<12)
#define	RCC_LOCKCFGR4_APB4LOCK_B_0X0			(0x0u<<11)
#define	RCC_LOCKCFGR4_APB4LOCK_B_0X1			(0x1u<<11)
#define	RCC_LOCKCFGR4_APB3LOCK_B_0X0			(0x0u<<10)
#define	RCC_LOCKCFGR4_APB3LOCK_B_0X1			(0x1u<<10)
#define	RCC_LOCKCFGR4_APB2LOCK_B_0X0			(0x0u<<9)
#define	RCC_LOCKCFGR4_APB2LOCK_B_0X1			(0x1u<<9)
#define	RCC_LOCKCFGR4_APB1LOCK_B_0X0			(0x0u<<8)
#define	RCC_LOCKCFGR4_APB1LOCK_B_0X1			(0x1u<<8)
#define	RCC_LOCKCFGR4_AHB5LOCK_B_0X0			(0x0u<<7)
#define	RCC_LOCKCFGR4_AHB5LOCK_B_0X1			(0x1u<<7)
#define	RCC_LOCKCFGR4_AHB4LOCK_B_0X0			(0x0u<<6)
#define	RCC_LOCKCFGR4_AHB4LOCK_B_0X1			(0x1u<<6)
#define	RCC_LOCKCFGR4_AHB3LOCK_B_0X0			(0x0u<<5)
#define	RCC_LOCKCFGR4_AHB3LOCK_B_0X1			(0x1u<<5)
#define	RCC_LOCKCFGR4_AHB2LOCK_B_0X0			(0x0u<<4)
#define	RCC_LOCKCFGR4_AHB2LOCK_B_0X1			(0x1u<<4)
#define	RCC_LOCKCFGR4_AHB1LOCK_B_0X0			(0x0u<<3)
#define	RCC_LOCKCFGR4_AHB1LOCK_B_0X1			(0x1u<<3)
#define	RCC_LOCKCFGR4_AHBMLOCK_B_0X0			(0x0u<<2)
#define	RCC_LOCKCFGR4_AHBMLOCK_B_0X1			(0x1u<<2)
#define	RCC_LOCKCFGR4_ACLKNCLOCK_B_0X0			(0x0u<<1)
#define	RCC_LOCKCFGR4_ACLKNCLOCK_B_0X1			(0x1u<<1)
#define	RCC_LOCKCFGR4_ACLKNLOCK_B_0X0			(0x0u<<0)
#define	RCC_LOCKCFGR4_ACLKNLOCK_B_0X1			(0x1u<<0)

// PUBCFGR4 Configuration

#define	RCC_PUBCFGR4_NOCPUB						(0x1u<<13)
#define	RCC_PUBCFGR4_APB5PUB					(0x1u<<12)
#define	RCC_PUBCFGR4_APB4PUB					(0x1u<<11)
#define	RCC_PUBCFGR4_APB3PUB					(0x1u<<10)
#define	RCC_PUBCFGR4_APB2PUB					(0x1u<<9)
#define	RCC_PUBCFGR4_APB1PUB					(0x1u<<8)
#define	RCC_PUBCFGR4_AHB5PUB					(0x1u<<7)
#define	RCC_PUBCFGR4_AHB4PUB					(0x1u<<6)
#define	RCC_PUBCFGR4_AHB3PUB					(0x1u<<5)
#define	RCC_PUBCFGR4_AHB2PUB					(0x1u<<4)
#define	RCC_PUBCFGR4_AHB1PUB					(0x1u<<3)
#define	RCC_PUBCFGR4_AHBMPUB					(0x1u<<2)
#define	RCC_PUBCFGR4_ACLKNCPUB					(0x1u<<1)
#define	RCC_PUBCFGR4_ACLKNPUB					(0x1u<<0)

#define	RCC_PUBCFGR4_NOCPUB_B_0X0				(0x0u<<13)
#define	RCC_PUBCFGR4_NOCPUB_B_0X1				(0x1u<<13)
#define	RCC_PUBCFGR4_APB5PUB_B_0X0				(0x0u<<12)
#define	RCC_PUBCFGR4_APB5PUB_B_0X1				(0x1u<<12)
#define	RCC_PUBCFGR4_APB4PUB_B_0X0				(0x0u<<11)
#define	RCC_PUBCFGR4_APB4PUB_B_0X1				(0x1u<<11)
#define	RCC_PUBCFGR4_APB3PUB_B_0X0				(0x0u<<10)
#define	RCC_PUBCFGR4_APB3PUB_B_0X1				(0x1u<<10)
#define	RCC_PUBCFGR4_APB2PUB_B_0X0				(0x0u<<9)
#define	RCC_PUBCFGR4_APB2PUB_B_0X1				(0x1u<<9)
#define	RCC_PUBCFGR4_APB1PUB_B_0X0				(0x0u<<8)
#define	RCC_PUBCFGR4_APB1PUB_B_0X1				(0x1u<<8)
#define	RCC_PUBCFGR4_AHB5PUB_B_0X0				(0x0u<<7)
#define	RCC_PUBCFGR4_AHB5PUB_B_0X1				(0x1u<<7)
#define	RCC_PUBCFGR4_AHB4PUB_B_0X0				(0x0u<<6)
#define	RCC_PUBCFGR4_AHB4PUB_B_0X1				(0x1u<<6)
#define	RCC_PUBCFGR4_AHB3PUB_B_0X0				(0x0u<<5)
#define	RCC_PUBCFGR4_AHB3PUB_B_0X1				(0x1u<<5)
#define	RCC_PUBCFGR4_AHB2PUB_B_0X0				(0x0u<<4)
#define	RCC_PUBCFGR4_AHB2PUB_B_0X1				(0x1u<<4)
#define	RCC_PUBCFGR4_AHB1PUB_B_0X0				(0x0u<<3)
#define	RCC_PUBCFGR4_AHB1PUB_B_0X1				(0x1u<<3)
#define	RCC_PUBCFGR4_AHBMPUB_B_0X0				(0x0u<<2)
#define	RCC_PUBCFGR4_AHBMPUB_B_0X1				(0x1u<<2)
#define	RCC_PUBCFGR4_ACLKNCPUB_B_0X0			(0x0u<<1)
#define	RCC_PUBCFGR4_ACLKNCPUB_B_0X1			(0x1u<<1)
#define	RCC_PUBCFGR4_ACLKNPUB_B_0X0				(0x0u<<0)
#define	RCC_PUBCFGR4_ACLKNPUB_B_0X1				(0x1u<<0)

// PUBCFGR5 Configuration

#define	RCC_PUBCFGR5_VENCRAMPUB					(0x1u<<11)
#define	RCC_PUBCFGR5_NPUCACHERAMPUB				(0x1u<<10)
#define	RCC_PUBCFGR5_FLEXRAMPUB					(0x1u<<9)
#define	RCC_PUBCFGR5_AXISRAM2PUB				(0x1u<<8)
#define	RCC_PUBCFGR5_AXISRAM1PUB				(0x1u<<7)
#define	RCC_PUBCFGR5_BKPSRAMPUB					(0x1u<<6)
#define	RCC_PUBCFGR5_AHBSRAM2PUB				(0x1u<<5)
#define	RCC_PUBCFGR5_AHBSRAM1PUB				(0x1u<<4)
#define	RCC_PUBCFGR5_AXISRAM6PUB				(0x1u<<3)
#define	RCC_PUBCFGR5_AXISRAM5PUB				(0x1u<<2)
#define	RCC_PUBCFGR5_AXISRAM4PUB				(0x1u<<1)
#define	RCC_PUBCFGR5_AXISRAM3PUB				(0x1u<<0)

#define	RCC_PUBCFGR5_VENCRAMPUB_B_0X0			(0x0u<<11)
#define	RCC_PUBCFGR5_VENCRAMPUB_B_0X1			(0x1u<<11)
#define	RCC_PUBCFGR5_NPUCACHERAMPUB_B_0X0		(0x0u<<10)
#define	RCC_PUBCFGR5_NPUCACHERAMPUB_B_0X1		(0x1u<<10)
#define	RCC_PUBCFGR5_FLEXRAMPUB_B_0X0			(0x0u<<9)
#define	RCC_PUBCFGR5_FLEXRAMPUB_B_0X1			(0x1u<<9)
#define	RCC_PUBCFGR5_AXISRAM2PUB_B_0X0			(0x0u<<8)
#define	RCC_PUBCFGR5_AXISRAM2PUB_B_0X1			(0x1u<<8)
#define	RCC_PUBCFGR5_AXISRAM1PUB_B_0X0			(0x0u<<7)
#define	RCC_PUBCFGR5_AXISRAM1PUB_B_0X1			(0x1u<<7)
#define	RCC_PUBCFGR5_BKPSRAMPUB_B_0X0			(0x0u<<6)
#define	RCC_PUBCFGR5_BKPSRAMPUB_B_0X1			(0x1u<<6)
#define	RCC_PUBCFGR5_AHBSRAM2PUB_B_0X0			(0x0u<<5)
#define	RCC_PUBCFGR5_AHBSRAM2PUB_B_0X1			(0x1u<<5)
#define	RCC_PUBCFGR5_AHBSRAM1PUB_B_0X0			(0x0u<<4)
#define	RCC_PUBCFGR5_AHBSRAM1PUB_B_0X1			(0x1u<<4)
#define	RCC_PUBCFGR5_AXISRAM6PUB_B_0X0			(0x0u<<3)
#define	RCC_PUBCFGR5_AXISRAM6PUB_B_0X1			(0x1u<<3)
#define	RCC_PUBCFGR5_AXISRAM5PUB_B_0X0			(0x0u<<2)
#define	RCC_PUBCFGR5_AXISRAM5PUB_B_0X1			(0x1u<<2)
#define	RCC_PUBCFGR5_AXISRAM4PUB_B_0X0			(0x0u<<1)
#define	RCC_PUBCFGR5_AXISRAM4PUB_B_0X1			(0x1u<<1)
#define	RCC_PUBCFGR5_AXISRAM3PUB_B_0X0			(0x0u<<0)
#define	RCC_PUBCFGR5_AXISRAM3PUB_B_0X1			(0x1u<<0)

// CSR Configuration

#define	RCC_CSR_PLL4ONS							(0x1u<<11)
#define	RCC_CSR_PLL3ONS							(0x1u<<10)
#define	RCC_CSR_PLL2ONS							(0x1u<<9)
#define	RCC_CSR_PLL1ONS							(0x1u<<8)
#define	RCC_CSR_HSEONS							(0x1u<<4)
#define	RCC_CSR_HSIONS							(0x1u<<3)
#define	RCC_CSR_MSIONS							(0x1u<<2)
#define	RCC_CSR_LSEONS							(0x1u<<1)
#define	RCC_CSR_LSIONS							(0x1u<<0)

// STOPCSR Configuration

#define	RCC_STOPCSR_HSISTOPENS					(0x1u<<1)
#define	RCC_STOPCSR_MSISTOPENS					(0x1u<<0)

// BUSRSTSR Configuration

#define	RCC_BUSRSTSR_NOCRSTS					(0x1u<<13)
#define	RCC_BUSRSTSR_APB5RSTS					(0x1u<<12)
#define	RCC_BUSRSTSR_APB4RSTS					(0x1u<<11)
#define	RCC_BUSRSTSR_APB3RSTS					(0x1u<<10)
#define	RCC_BUSRSTSR_APB2RSTS					(0x1u<<9)
#define	RCC_BUSRSTSR_APB1RSTS					(0x1u<<8)
#define	RCC_BUSRSTSR_AHB5RSTS					(0x1u<<7)
#define	RCC_BUSRSTSR_AHB4RSTS					(0x1u<<6)
#define	RCC_BUSRSTSR_AHB3RSTS					(0x1u<<5)
#define	RCC_BUSRSTSR_AHB2RSTS					(0x1u<<4)
#define	RCC_BUSRSTSR_AHB1RSTS					(0x1u<<3)
#define	RCC_BUSRSTSR_AHBMRSTS					(0x1u<<2)
#define	RCC_BUSRSTSR_ACLKNRSTS					(0x1u<<0)

// MISCRSTSR Configuration

#define	RCC_MISCRSTSR_SDMMC2DLLRSTS				(0x1u<<8)
#define	RCC_MISCRSTSR_SDMMC1DLLRSTS				(0x1u<<7)
#define	RCC_MISCRSTSR_XSPIPHY2RSTS				(0x1u<<5)
#define	RCC_MISCRSTSR_XSPIPHY1RSTS				(0x1u<<4)
#define	RCC_MISCRSTSR_DBGRSTS					(0x1u<<0)

// MEMRSTSR Configuration

#define	RCC_MEMRSTSR_BOOTROMRSTS				(0x1u<<12)
#define	RCC_MEMRSTSR_VENCRAMRSTS				(0x1u<<11)
#define	RCC_MEMRSTSR_NPUCACHERAMRSTS			(0x1u<<10)
#define	RCC_MEMRSTSR_FLEXRAMRSTS				(0x1u<<9)
#define	RCC_MEMRSTSR_AXISRAM2RSTS				(0x1u<<8)
#define	RCC_MEMRSTSR_AXISRAM1RSTS				(0x1u<<7)
#define	RCC_MEMRSTSR_AHBSRAM2RSTS				(0x1u<<5)
#define	RCC_MEMRSTSR_AHBSRAM1RSTS				(0x1u<<4)
#define	RCC_MEMRSTSR_AXISRAM6RSTS				(0x1u<<3)
#define	RCC_MEMRSTSR_AXISRAM5RSTS				(0x1u<<2)
#define	RCC_MEMRSTSR_AXISRAM4RSTS				(0x1u<<1)
#define	RCC_MEMRSTSR_AXISRAM3RSTS				(0x1u<<0)

// AHB1RSTSR Configuration

#define	RCC_AHB1RSTSR_ADC12RSTS					(0x1u<<5)
#define	RCC_AHB1RSTSR_GPDMA1RSTS				(0x1u<<4)

// AHB2RSTSR Configuration

#define	RCC_AHB2RSTSR_ADF1RSTS					(0x1u<<17)
#define	RCC_AHB2RSTSR_MDF1RSTS					(0x1u<<16)
#define	RCC_AHB2RSTSR_RAMCFGRSTS				(0x1u<<12)

// AHB3RSTSR Configuration

#define	RCC_AHB3RSTSR_IACRSTS					(0x1u<<10)
#define	RCC_AHB3RSTSR_PKARSTS					(0x1u<<8)
#define	RCC_AHB3RSTSR_SAESRSTS					(0x1u<<4)
#define	RCC_AHB3RSTSR_CRYPRSTS					(0x1u<<2)
#define	RCC_AHB3RSTSR_HASHRSTS					(0x1u<<1)
#define	RCC_AHB3RSTSR_RNGRSTS					(0x1u<<0)

// AHB4RSTSR Configuration

#define	RCC_AHB4RSTSR_CRCRSTS					(0x1u<<19)
#define	RCC_AHB4RSTSR_PWRRSTS					(0x1u<<18)
#define	RCC_AHB4RSTSR_GPIOQRSTS					(0x1u<<16)
#define	RCC_AHB4RSTSR_GPIOPRSTS					(0x1u<<15)
#define	RCC_AHB4RSTSR_GPIOORSTS					(0x1u<<14)
#define	RCC_AHB4RSTSR_GPIONRSTS					(0x1u<<13)
#define	RCC_AHB4RSTSR_GPIOHRSTS					(0x1u<<7)
#define	RCC_AHB4RSTSR_GPIOGRSTS					(0x1u<<6)
#define	RCC_AHB4RSTSR_GPIOFRSTS					(0x1u<<5)
#define	RCC_AHB4RSTSR_GPIOERSTS					(0x1u<<4)
#define	RCC_AHB4RSTSR_GPIODRSTS					(0x1u<<3)
#define	RCC_AHB4RSTSR_GPIOCRSTS					(0x1u<<2)
#define	RCC_AHB4RSTSR_GPIOBRSTS					(0x1u<<1)
#define	RCC_AHB4RSTSR_GPIOARSTS					(0x1u<<0)

// AHB5RSTSR Configuration

#define	RCC_AHB5RSTSR_NPURSTS					(0x1u<<31)
#define	RCC_AHB5RSTSR_NPUCACHERSTS				(0x1u<<30)
#define	RCC_AHB5RSTSR_OTG2RSTS					(0x1u<<29)
#define	RCC_AHB5RSTSR_OTGPHY2RSTS				(0x1u<<28)
#define	RCC_AHB5RSTSR_OTGPHY1RSTS				(0x1u<<27)
#define	RCC_AHB5RSTSR_OTG1RSTS					(0x1u<<26)
#define	RCC_AHB5RSTSR_ETH1RSTS					(0x1u<<25)
#define	RCC_AHB5RSTSR_SYSCFGOTGHSPHY2RSTS		(0x1u<<24)
#define	RCC_AHB5RSTSR_SYSCFGOTGHSPHY1RSTS		(0x1u<<23)
#define	RCC_AHB5RSTSR_GPURSTS					(0x1u<<20)
#define	RCC_AHB5RSTSR_GFXMMURSTS				(0x1u<<19)
#define	RCC_AHB5RSTSR_MCE4RSTS					(0x1u<<18)
#define	RCC_AHB5RSTSR_XSPI3RSTS					(0x1u<<17)
#define	RCC_AHB5RSTSR_XSPIMRSTS					(0x1u<<13)
#define	RCC_AHB5RSTSR_XSPI2RSTS					(0x1u<<12)
#define	RCC_AHB5RSTSR_SDMMC1RSTS				(0x1u<<8)
#define	RCC_AHB5RSTSR_SDMMC2RSTS				(0x1u<<7)
#define	RCC_AHB5RSTSR_PSSIRSTS					(0x1u<<6)
#define	RCC_AHB5RSTSR_XSPI1RSTS					(0x1u<<5)
#define	RCC_AHB5RSTSR_FMCRSTS					(0x1u<<4)
#define	RCC_AHB5RSTSR_JPEGRSTS					(0x1u<<3)
#define	RCC_AHB5RSTSR_DMA2DRSTS					(0x1u<<1)
#define	RCC_AHB5RSTSR_HPDMA1RSTS				(0x1u<<0)

// APB1LRSTSR Configuration

#define	RCC_APB1LRSTSR_UART8RSTS				(0x1u<<31)
#define	RCC_APB1LRSTSR_UART7RSTS				(0x1u<<30)
#define	RCC_APB1LRSTSR_I3C2RSTS					(0x1u<<25)
#define	RCC_APB1LRSTSR_I3C1RSTS					(0x1u<<24)
#define	RCC_APB1LRSTSR_I2C3RSTS					(0x1u<<23)
#define	RCC_APB1LRSTSR_I2C2RSTS					(0x1u<<22)
#define	RCC_APB1LRSTSR_I2C1RSTS					(0x1u<<21)
#define	RCC_APB1LRSTSR_UART5RSTS				(0x1u<<20)
#define	RCC_APB1LRSTSR_UART4RSTS				(0x1u<<19)
#define	RCC_APB1LRSTSR_USART3RSTS				(0x1u<<18)
#define	RCC_APB1LRSTSR_USART2RSTS				(0x1u<<17)
#define	RCC_APB1LRSTSR_SPDIFRX1RSTS				(0x1u<<16)
#define	RCC_APB1LRSTSR_SPI3RSTS					(0x1u<<15)
#define	RCC_APB1LRSTSR_SPI2RSTS					(0x1u<<14)
#define	RCC_APB1LRSTSR_TIM11RSTS				(0x1u<<13)
#define	RCC_APB1LRSTSR_TIM10RSTS				(0x1u<<12)
#define	RCC_APB1LRSTSR_WWDGRSTS					(0x1u<<11)
#define	RCC_APB1LRSTSR_LPTIM1RSTS				(0x1u<<9)
#define	RCC_APB1LRSTSR_TIM14RSTS				(0x1u<<8)
#define	RCC_APB1LRSTSR_TIM13RSTS				(0x1u<<7)
#define	RCC_APB1LRSTSR_TIM12RSTS				(0x1u<<6)
#define	RCC_APB1LRSTSR_TIM7RSTS					(0x1u<<5)
#define	RCC_APB1LRSTSR_TIM6RSTS					(0x1u<<4)
#define	RCC_APB1LRSTSR_TIM5RSTS					(0x1u<<3)
#define	RCC_APB1LRSTSR_TIM4RSTS					(0x1u<<2)
#define	RCC_APB1LRSTSR_TIM3RSTS					(0x1u<<1)
#define	RCC_APB1LRSTSR_TIM2RSTS					(0x1u<<0)

// APB1HRSTSR Configuration

#define	RCC_APB1HRSTSR_UCPD1RSTS				(0x1u<<18)
#define	RCC_APB1HRSTSR_FDCANRSTS				(0x1u<<8)
#define	RCC_APB1HRSTSR_MDIOSRSTS				(0x1u<<5)

// APB2RSTSR Configuration

#define	RCC_APB2RSTSR_SAI2RSTS					(0x1u<<22)
#define	RCC_APB2RSTSR_SAI1RSTS					(0x1u<<21)
#define	RCC_APB2RSTSR_SPI5RSTS					(0x1u<<20)
#define	RCC_APB2RSTSR_TIM9RSTS					(0x1u<<19)
#define	RCC_APB2RSTSR_TIM17RSTS					(0x1u<<18)
#define	RCC_APB2RSTSR_TIM16RSTS					(0x1u<<17)
#define	RCC_APB2RSTSR_TIM15RSTS					(0x1u<<16)
#define	RCC_APB2RSTSR_TIM18RSTS					(0x1u<<15)
#define	RCC_APB2RSTSR_SPI4RSTS					(0x1u<<13)
#define	RCC_APB2RSTSR_SPI1RSTS					(0x1u<<12)
#define	RCC_APB2RSTSR_USART10RSTS				(0x1u<<7)
#define	RCC_APB2RSTSR_UART9RSTS					(0x1u<<6)
#define	RCC_APB2RSTSR_USART6RSTS				(0x1u<<5)
#define	RCC_APB2RSTSR_USART1RSTS				(0x1u<<4)
#define	RCC_APB2RSTSR_TIM8RSTS					(0x1u<<1)
#define	RCC_APB2RSTSR_TIM1RSTS					(0x1u<<0)

// APB4LRSTSR Configuration

#define	RCC_APB4LRSTSR_SERFRSTS					(0x1u<<31)
#define	RCC_APB4LRSTSR_R2GNPURSTS				(0x1u<<23)
#define	RCC_APB4LRSTSR_R2GRETRSTS				(0x1u<<22)
#define	RCC_APB4LRSTSR_RTCRSTS					(0x1u<<16)
#define	RCC_APB4LRSTSR_VREFBUFRSTS				(0x1u<<15)
#define	RCC_APB4LRSTSR_LPTIM5RSTS				(0x1u<<12)
#define	RCC_APB4LRSTSR_LPTIM4RSTS				(0x1u<<11)
#define	RCC_APB4LRSTSR_LPTIM3RSTS				(0x1u<<10)
#define	RCC_APB4LRSTSR_LPTIM2RSTS				(0x1u<<9)
#define	RCC_APB4LRSTSR_I2C4RSTS					(0x1u<<7)
#define	RCC_APB4LRSTSR_SPI6RSTS					(0x1u<<5)
#define	RCC_APB4LRSTSR_LPUART1RSTS				(0x1u<<3)
#define	RCC_APB4LRSTSR_HDPRSTS					(0x1u<<2)

// APB4HRSTSR Configuration

#define	RCC_APB4HRSTSR_BUSPERFMRSTS				(0x1u<<4)
#define	RCC_APB4HRSTSR_DTSRSTS					(0x1u<<2)
#define	RCC_APB4HRSTSR_SYSCFGRSTS				(0x1u<<0)

// APB5RSTSR Configuration

#define	RCC_APB5RSTSR_CSIRSTS					(0x1u<<6)
#define	RCC_APB5RSTSR_VENCRSTS					(0x1u<<5)
#define	RCC_APB5RSTSR_GFXTIMRSTS				(0x1u<<4)
#define	RCC_APB5RSTSR_DCMIPPRSTS				(0x1u<<2)
#define	RCC_APB5RSTSR_LTDCRSTS					(0x1u<<1)

// DIVENSR Configuration

#define	RCC_DIVENSR_IC20ENS						(0x1u<<19)
#define	RCC_DIVENSR_IC19ENS						(0x1u<<18)
#define	RCC_DIVENSR_IC18ENS						(0x1u<<17)
#define	RCC_DIVENSR_IC17ENS						(0x1u<<16)
#define	RCC_DIVENSR_IC16ENS						(0x1u<<15)
#define	RCC_DIVENSR_IC15ENS						(0x1u<<14)
#define	RCC_DIVENSR_IC14ENS						(0x1u<<13)
#define	RCC_DIVENSR_IC13ENS						(0x1u<<12)
#define	RCC_DIVENSR_IC12ENS						(0x1u<<11)
#define	RCC_DIVENSR_IC11ENS						(0x1u<<10)
#define	RCC_DIVENSR_IC10ENS						(0x1u<<9)
#define	RCC_DIVENSR_IC9ENS						(0x1u<<8)
#define	RCC_DIVENSR_IC8ENS						(0x1u<<7)
#define	RCC_DIVENSR_IC7ENS						(0x1u<<6)
#define	RCC_DIVENSR_IC6ENS						(0x1u<<5)
#define	RCC_DIVENSR_IC5ENS						(0x1u<<4)
#define	RCC_DIVENSR_IC4ENS						(0x1u<<3)
#define	RCC_DIVENSR_IC3ENS						(0x1u<<2)
#define	RCC_DIVENSR_IC2ENS						(0x1u<<1)
#define	RCC_DIVENSR_IC1ENS						(0x1u<<0)

// BUSENSR Configuration

#define	RCC_BUSENSR_APB5ENS						(0x1u<<12)
#define	RCC_BUSENSR_APB4ENS						(0x1u<<11)
#define	RCC_BUSENSR_APB3ENS						(0x1u<<10)
#define	RCC_BUSENSR_APB2ENS						(0x1u<<9)
#define	RCC_BUSENSR_APB1ENS						(0x1u<<8)
#define	RCC_BUSENSR_AHB5ENS						(0x1u<<7)
#define	RCC_BUSENSR_AHB4ENS						(0x1u<<6)
#define	RCC_BUSENSR_AHB3ENS						(0x1u<<5)
#define	RCC_BUSENSR_AHB2ENS						(0x1u<<4)
#define	RCC_BUSENSR_AHB1ENS						(0x1u<<3)
#define	RCC_BUSENSR_AHBMENS						(0x1u<<2)
#define	RCC_BUSENSR_ACLKNCENS					(0x1u<<1)
#define	RCC_BUSENSR_ACLKNENS					(0x1u<<0)

// MISCENSR Configuration

#define	RCC_MISCENSR_PERENS						(0x1u<<6)
#define	RCC_MISCENSR_XSPIPHYCOMPENS				(0x1u<<3)
#define	RCC_MISCENSR_MCO2ENS					(0x1u<<2)
#define	RCC_MISCENSR_MCO1ENS					(0x1u<<1)
#define	RCC_MISCENSR_DBGENS						(0x1u<<0)

// MEMENSR Configuration

#define	RCC_MEMENSR_BOOTROMENS					(0x1u<<12)
#define	RCC_MEMENSR_VENCRAMENS					(0x1u<<11)
#define	RCC_MEMENSR_NPUCACHERAMENS				(0x1u<<10)
#define	RCC_MEMENSR_FLEXRAMENS					(0x1u<<9)
#define	RCC_MEMENSR_AXISRAM2ENS					(0x1u<<8)
#define	RCC_MEMENSR_AXISRAM1ENS					(0x1u<<7)
#define	RCC_MEMENSR_BKPSRAMENS					(0x1u<<6)
#define	RCC_MEMENSR_AHBSRAM2ENS					(0x1u<<5)
#define	RCC_MEMENSR_AHBSRAM1ENS					(0x1u<<4)
#define	RCC_MEMENSR_AXISRAM6ENS					(0x1u<<3)
#define	RCC_MEMENSR_AXISRAM5ENS					(0x1u<<2)
#define	RCC_MEMENSR_AXISRAM4ENS					(0x1u<<1)
#define	RCC_MEMENSR_AXISRAM3ENS					(0x1u<<0)

// AHB1ENSR Configuration

#define	RCC_AHB1ENSR_ADC12ENS					(0x1u<<5)
#define	RCC_AHB1ENSR_GPDMA1ENS					(0x1u<<4)

// AHB2ENSR Configuration

#define	RCC_AHB2ENSR_ADF1ENS					(0x1u<<17)
#define	RCC_AHB2ENSR_MDF1ENS					(0x1u<<16)
#define	RCC_AHB2ENSR_RAMCFGENS					(0x1u<<12)

// AHB3ENSR Configuration

#define	RCC_AHB3ENSR_RISAFENS					(0x1u<<14)
#define	RCC_AHB3ENSR_IACENS						(0x1u<<10)
#define	RCC_AHB3ENSR_RIFSCENS					(0x1u<<9)
#define	RCC_AHB3ENSR_PKAENS						(0x1u<<8)
#define	RCC_AHB3ENSR_SAESENS					(0x1u<<4)
#define	RCC_AHB3ENSR_CRYPENS					(0x1u<<2)
#define	RCC_AHB3ENSR_HASHENS					(0x1u<<1)
#define	RCC_AHB3ENSR_RNGENS						(0x1u<<0)

// AHB4ENSR Configuration

#define	RCC_AHB4ENSR_CRCENS						(0x1u<<19)
#define	RCC_AHB4ENSR_PWRENS						(0x1u<<18)
#define	RCC_AHB4ENSR_GPIOQENS					(0x1u<<16)
#define	RCC_AHB4ENSR_GPIOPENS					(0x1u<<15)
#define	RCC_AHB4ENSR_GPIOOENS					(0x1u<<14)
#define	RCC_AHB4ENSR_GPIONENS					(0x1u<<13)
#define	RCC_AHB4ENSR_GPIOHENS					(0x1u<<7)
#define	RCC_AHB4ENSR_GPIOGENS					(0x1u<<6)
#define	RCC_AHB4ENSR_GPIOFENS					(0x1u<<5)
#define	RCC_AHB4ENSR_GPIOEENS					(0x1u<<4)
#define	RCC_AHB4ENSR_GPIODENS					(0x1u<<3)
#define	RCC_AHB4ENSR_GPIOCENS					(0x1u<<2)
#define	RCC_AHB4ENSR_GPIOBENS					(0x1u<<1)
#define	RCC_AHB4ENSR_GPIOAENS					(0x1u<<0)

// AHB5ENSR Configuration

#define	RCC_AHB5ENSR_NPUENS						(0x1u<<31)
#define	RCC_AHB5ENSR_NPUCACHEENS				(0x1u<<30)
#define	RCC_AHB5ENSR_OTG2ENS					(0x1u<<29)
#define	RCC_AHB5ENSR_OTGPHY2ENS					(0x1u<<28)
#define	RCC_AHB5ENSR_OTGPHY1ENS					(0x1u<<27)
#define	RCC_AHB5ENSR_OTG1ENS					(0x1u<<26)
#define	RCC_AHB5ENSR_ETH1ENS					(0x1u<<25)
#define	RCC_AHB5ENSR_ETH1RXENS					(0x1u<<24)
#define	RCC_AHB5ENSR_ETH1TXENS					(0x1u<<23)
#define	RCC_AHB5ENSR_ETH1MACENS					(0x1u<<22)
#define	RCC_AHB5ENSR_GPUENS						(0x1u<<20)
#define	RCC_AHB5ENSR_GFXMMUENS					(0x1u<<19)
#define	RCC_AHB5ENSR_MCE4ENS					(0x1u<<18)
#define	RCC_AHB5ENSR_XSPI3ENS					(0x1u<<17)
#define	RCC_AHB5ENSR_MCE3ENS					(0x1u<<16)
#define	RCC_AHB5ENSR_MCE2ENS					(0x1u<<15)
#define	RCC_AHB5ENSR_MCE1ENS					(0x1u<<14)
#define	RCC_AHB5ENSR_XSPIMENS					(0x1u<<13)
#define	RCC_AHB5ENSR_XSPI2ENS					(0x1u<<12)
#define	RCC_AHB5ENSR_SDMMC1ENS					(0x1u<<8)
#define	RCC_AHB5ENSR_SDMMC2ENS					(0x1u<<7)
#define	RCC_AHB5ENSR_PSSIENS					(0x1u<<6)
#define	RCC_AHB5ENSR_XSPI1ENS					(0x1u<<5)
#define	RCC_AHB5ENSR_FMCENS						(0x1u<<4)
#define	RCC_AHB5ENSR_JPEGENS					(0x1u<<3)
#define	RCC_AHB5ENSR_DMA2DENS					(0x1u<<1)
#define	RCC_AHB5ENSR_HPDMA1ENS					(0x1u<<0)

// APB1LENSR Configuration

#define	RCC_APB1LENSR_UART8ENS					(0x1u<<31)
#define	RCC_APB1LENSR_UART7ENS					(0x1u<<30)
#define	RCC_APB1LENSR_I3C2ENS					(0x1u<<25)
#define	RCC_APB1LENSR_I3C1ENS					(0x1u<<24)
#define	RCC_APB1LENSR_I2C3ENS					(0x1u<<23)
#define	RCC_APB1LENSR_I2C2ENS					(0x1u<<22)
#define	RCC_APB1LENSR_I2C1ENS					(0x1u<<21)
#define	RCC_APB1LENSR_UART5ENS					(0x1u<<20)
#define	RCC_APB1LENSR_UART4ENS					(0x1u<<19)
#define	RCC_APB1LENSR_USART3ENS					(0x1u<<18)
#define	RCC_APB1LENSR_USART2ENS					(0x1u<<17)
#define	RCC_APB1LENSR_SPDIFRX1ENS				(0x1u<<16)
#define	RCC_APB1LENSR_SPI3ENS					(0x1u<<15)
#define	RCC_APB1LENSR_SPI2ENS					(0x1u<<14)
#define	RCC_APB1LENSR_TIM11ENS					(0x1u<<13)
#define	RCC_APB1LENSR_TIM10ENS					(0x1u<<12)
#define	RCC_APB1LENSR_WWDGENS					(0x1u<<11)
#define	RCC_APB1LENSR_LPTIM1ENS					(0x1u<<9)
#define	RCC_APB1LENSR_TIM14ENS					(0x1u<<8)
#define	RCC_APB1LENSR_TIM13ENS					(0x1u<<7)
#define	RCC_APB1LENSR_TIM12ENS					(0x1u<<6)
#define	RCC_APB1LENSR_TIM7ENS					(0x1u<<5)
#define	RCC_APB1LENSR_TIM6ENS					(0x1u<<4)
#define	RCC_APB1LENSR_TIM5ENS					(0x1u<<3)
#define	RCC_APB1LENSR_TIM4ENS					(0x1u<<2)
#define	RCC_APB1LENSR_TIM3ENS					(0x1u<<1)
#define	RCC_APB1LENSR_TIM2ENS					(0x1u<<0)

// APB1HENSR Configuration

#define	RCC_APB1HENSR_UCPD1ENS					(0x1u<<18)
#define	RCC_APB1HENSR_FDCANENS					(0x1u<<8)
#define	RCC_APB1HENSR_MDIOSENS					(0x1u<<5)

// APB2ENSR Configuration

#define	RCC_APB2ENSR_SAI2ENS					(0x1u<<22)
#define	RCC_APB2ENSR_SAI1ENS					(0x1u<<21)
#define	RCC_APB2ENSR_SPI5ENS					(0x1u<<20)
#define	RCC_APB2ENSR_TIM9ENS					(0x1u<<19)
#define	RCC_APB2ENSR_TIM17ENS					(0x1u<<18)
#define	RCC_APB2ENSR_TIM16ENS					(0x1u<<17)
#define	RCC_APB2ENSR_TIM15ENS					(0x1u<<16)
#define	RCC_APB2ENSR_TIM18ENS					(0x1u<<15)
#define	RCC_APB2ENSR_SPI4ENS					(0x1u<<13)
#define	RCC_APB2ENSR_SPI1ENS					(0x1u<<12)
#define	RCC_APB2ENSR_USART10ENS					(0x1u<<7)
#define	RCC_APB2ENSR_UART9ENS					(0x1u<<6)
#define	RCC_APB2ENSR_USART6ENS					(0x1u<<5)
#define	RCC_APB2ENSR_USART1ENS					(0x1u<<4)
#define	RCC_APB2ENSR_TIM8ENS					(0x1u<<1)
#define	RCC_APB2ENSR_TIM1ENS					(0x1u<<0)

// APB3ENSR Configuration

#define	RCC_APB3ENSR_DFTENS						(0x1u<<2)

// APB4LENSR Configuration

#define	RCC_APB4LENSR_SERFENS					(0x1u<<31)
#define	RCC_APB4LENSR_R2GNPUENS					(0x1u<<23)
#define	RCC_APB4LENSR_R2GRETENS					(0x1u<<22)
#define	RCC_APB4LENSR_RTCAPBENS					(0x1u<<17)
#define	RCC_APB4LENSR_RTCENS					(0x1u<<16)
#define	RCC_APB4LENSR_VREFBUFENS				(0x1u<<15)
#define	RCC_APB4LENSR_LPTIM5ENS					(0x1u<<12)
#define	RCC_APB4LENSR_LPTIM4ENS					(0x1u<<11)
#define	RCC_APB4LENSR_LPTIM3ENS					(0x1u<<10)
#define	RCC_APB4LENSR_LPTIM2ENS					(0x1u<<9)
#define	RCC_APB4LENSR_I2C4ENS					(0x1u<<7)
#define	RCC_APB4LENSR_SPI6ENS					(0x1u<<5)
#define	RCC_APB4LENSR_LPUART1ENS				(0x1u<<3)
#define	RCC_APB4LENSR_HDPENS					(0x1u<<2)

// APB4HENSR Configuration

#define	RCC_APB4HENSR_BUSPERFMENS				(0x1u<<4)
#define	RCC_APB4HENSR_DTSENS					(0x1u<<2)
#define	RCC_APB4HENSR_BSECENS					(0x1u<<1)
#define	RCC_APB4HENSR_SYSCFGENS					(0x1u<<0)

// APB5ENSR Configuration

#define	RCC_APB5ENSR_CSIENS						(0x1u<<6)
#define	RCC_APB5ENSR_VENCENS					(0x1u<<5)
#define	RCC_APB5ENSR_GFXTIMENS					(0x1u<<4)
#define	RCC_APB5ENSR_DCMIPPENS					(0x1u<<2)
#define	RCC_APB5ENSR_LTDCENS					(0x1u<<1)

// DIVLPENSR Configuration

#define	RCC_DIVLPENSR_IC20LPENS					(0x1u<<19)
#define	RCC_DIVLPENSR_IC19LPENS					(0x1u<<18)
#define	RCC_DIVLPENSR_IC18LPENS					(0x1u<<17)
#define	RCC_DIVLPENSR_IC17LPENS					(0x1u<<16)
#define	RCC_DIVLPENSR_IC16LPENS					(0x1u<<15)
#define	RCC_DIVLPENSR_IC15LPENS					(0x1u<<14)
#define	RCC_DIVLPENSR_IC14LPENS					(0x1u<<13)
#define	RCC_DIVLPENSR_IC13LPENS					(0x1u<<12)
#define	RCC_DIVLPENSR_IC12LPENS					(0x1u<<11)
#define	RCC_DIVLPENSR_IC11LPENS					(0x1u<<10)
#define	RCC_DIVLPENSR_IC10LPENS					(0x1u<<9)
#define	RCC_DIVLPENSR_IC9LPENS					(0x1u<<8)
#define	RCC_DIVLPENSR_IC8LPENS					(0x1u<<7)
#define	RCC_DIVLPENSR_IC7LPENS					(0x1u<<6)
#define	RCC_DIVLPENSR_IC6LPENS					(0x1u<<5)
#define	RCC_DIVLPENSR_IC5LPENS					(0x1u<<4)
#define	RCC_DIVLPENSR_IC4LPENS					(0x1u<<3)
#define	RCC_DIVLPENSR_IC3LPENS					(0x1u<<2)
#define	RCC_DIVLPENSR_IC2LPENS					(0x1u<<1)
#define	RCC_DIVLPENSR_IC1LPENS					(0x1u<<0)

// BUSLPENSR Configuration

#define	RCC_BUSLPENSR_APB5LPENS					(0x1u<<12)
#define	RCC_BUSLPENSR_APB4LPENS					(0x1u<<11)
#define	RCC_BUSLPENSR_APB3LPENS					(0x1u<<10)
#define	RCC_BUSLPENSR_APB2LPENS					(0x1u<<9)
#define	RCC_BUSLPENSR_APB1LPENS					(0x1u<<8)
#define	RCC_BUSLPENSR_AHB5LPENS					(0x1u<<7)
#define	RCC_BUSLPENSR_AHB4LPENS					(0x1u<<6)
#define	RCC_BUSLPENSR_AHB3LPENS					(0x1u<<5)
#define	RCC_BUSLPENSR_AHB2LPENS					(0x1u<<4)
#define	RCC_BUSLPENSR_AHB1LPENS					(0x1u<<3)
#define	RCC_BUSLPENSR_AHBMLPENS					(0x1u<<2)
#define	RCC_BUSLPENSR_ACLKNCLPENS				(0x1u<<1)
#define	RCC_BUSLPENSR_ACLKNLPENS				(0x1u<<0)

// MISCLPENSR Configuration

#define	RCC_MISCLPENSR_PERLPENS					(0x1u<<6)
#define	RCC_MISCLPENSR_XSPIPHYCOMPLPENS			(0x1u<<3)
#define	RCC_MISCLPENSR_DBGLPENS					(0x1u<<0)

// MEMLPENSR Configuration

#define	RCC_MEMLPENSR_BOOTROMLPENS				(0x1u<<12)
#define	RCC_MEMLPENSR_VENCRAMLPENS				(0x1u<<11)
#define	RCC_MEMLPENSR_NPUCACHERAMLPENS			(0x1u<<10)
#define	RCC_MEMLPENSR_FLEXRAMLPENS				(0x1u<<9)
#define	RCC_MEMLPENSR_AXISRAM2LPENS				(0x1u<<8)
#define	RCC_MEMLPENSR_AXISRAM1LPENS				(0x1u<<7)
#define	RCC_MEMLPENSR_BKPSRAMLPENS				(0x1u<<6)
#define	RCC_MEMLPENSR_AHBSRAM2LPENS				(0x1u<<5)
#define	RCC_MEMLPENSR_AHBSRAM1LPENS				(0x1u<<4)
#define	RCC_MEMLPENSR_AXISRAM6LPENS				(0x1u<<3)
#define	RCC_MEMLPENSR_AXISRAM5LPENS				(0x1u<<2)
#define	RCC_MEMLPENSR_AXISRAM4LPENS				(0x1u<<1)
#define	RCC_MEMLPENSR_AXISRAM3LPENS				(0x1u<<0)

// AHB1LPENSR Configuration

#define	RCC_AHB1LPENSR_ADC12LPENS				(0x1u<<5)
#define	RCC_AHB1LPENSR_GPDMA1LPENS				(0x1u<<4)

// AHB2LPENSR Configuration

#define	RCC_AHB2LPENSR_ADF1LPENS				(0x1u<<17)
#define	RCC_AHB2LPENSR_MDF1LPENS				(0x1u<<16)
#define	RCC_AHB2LPENSR_RAMCFGLPENS				(0x1u<<12)

// AHB3LPENSR Configuration

#define	RCC_AHB3LPENSR_RISAFLPENS				(0x1u<<14)
#define	RCC_AHB3LPENSR_IACLPENS					(0x1u<<10)
#define	RCC_AHB3LPENSR_RIFSCLPENS				(0x1u<<9)
#define	RCC_AHB3LPENSR_PKALPENS					(0x1u<<8)
#define	RCC_AHB3LPENSR_SAESLPENS				(0x1u<<4)
#define	RCC_AHB3LPENSR_CRYPLPENS				(0x1u<<2)
#define	RCC_AHB3LPENSR_HASHLPENS				(0x1u<<1)
#define	RCC_AHB3LPENSR_RNGLPENS					(0x1u<<0)

// AHB4LPENSR Configuration

#define	RCC_AHB4LPENSR_CRCLPENS					(0x1u<<19)
#define	RCC_AHB4LPENSR_PWRLPENS					(0x1u<<18)
#define	RCC_AHB4LPENSR_GPIOQLPENS				(0x1u<<16)
#define	RCC_AHB4LPENSR_GPIOPLPENS				(0x1u<<15)
#define	RCC_AHB4LPENSR_GPIOOLPENS				(0x1u<<14)
#define	RCC_AHB4LPENSR_GPIONLPENS				(0x1u<<13)
#define	RCC_AHB4LPENSR_GPIOHLPENS				(0x1u<<7)
#define	RCC_AHB4LPENSR_GPIOGLPENS				(0x1u<<6)
#define	RCC_AHB4LPENSR_GPIOFLPENS				(0x1u<<5)
#define	RCC_AHB4LPENSR_GPIOELPENS				(0x1u<<4)
#define	RCC_AHB4LPENSR_GPIODLPENS				(0x1u<<3)
#define	RCC_AHB4LPENSR_GPIOCLPENS				(0x1u<<2)
#define	RCC_AHB4LPENSR_GPIOBLPENS				(0x1u<<1)
#define	RCC_AHB4LPENSR_GPIOALPENS				(0x1u<<0)

// AHB5LPENSR Configuration

#define	RCC_AHB5LPENSR_NPULPENS					(0x1u<<31)
#define	RCC_AHB5LPENSR_NPUCACHELPENS			(0x1u<<30)
#define	RCC_AHB5LPENSR_OTG2LPENS				(0x1u<<29)
#define	RCC_AHB5LPENSR_OTGPHY2LPENS				(0x1u<<28)
#define	RCC_AHB5LPENSR_OTGPHY1LPENS				(0x1u<<27)
#define	RCC_AHB5LPENSR_OTG1LPENS				(0x1u<<26)
#define	RCC_AHB5LPENSR_ETH1LPENS				(0x1u<<25)
#define	RCC_AHB5LPENSR_ETH1RXLPENS				(0x1u<<24)
#define	RCC_AHB5LPENSR_ETH1TXLPENS				(0x1u<<23)
#define	RCC_AHB5LPENSR_ETH1MACLPENS				(0x1u<<22)
#define	RCC_AHB5LPENSR_GPULPENS					(0x1u<<20)
#define	RCC_AHB5LPENSR_GFXMMULPENS				(0x1u<<19)
#define	RCC_AHB5LPENSR_MCE4LPENS				(0x1u<<18)
#define	RCC_AHB5LPENSR_XSPI3LPENS				(0x1u<<17)
#define	RCC_AHB5LPENSR_MCE3LPENS				(0x1u<<16)
#define	RCC_AHB5LPENSR_MCE2LPENS				(0x1u<<15)
#define	RCC_AHB5LPENSR_MCE1LPENS				(0x1u<<14)
#define	RCC_AHB5LPENSR_XSPIMLPENS				(0x1u<<13)
#define	RCC_AHB5LPENSR_XSPI2LPENS				(0x1u<<12)
#define	RCC_AHB5LPENSR_SDMMC1LPENS				(0x1u<<8)
#define	RCC_AHB5LPENSR_SDMMC2LPENS				(0x1u<<7)
#define	RCC_AHB5LPENSR_PSSILPENS				(0x1u<<6)
#define	RCC_AHB5LPENSR_XSPI1LPENS				(0x1u<<5)
#define	RCC_AHB5LPENSR_FMCLPENS					(0x1u<<4)
#define	RCC_AHB5LPENSR_JPEGLPENS				(0x1u<<3)
#define	RCC_AHB5LPENSR_DMA2DLPENS				(0x1u<<1)
#define	RCC_AHB5LPENSR_HPDMA1LPENS				(0x1u<<0)

// APB1LLPENSR Configuration

#define	RCC_APB1LLPENSR_UART8LPENS				(0x1u<<31)
#define	RCC_APB1LLPENSR_UART7LPENS				(0x1u<<30)
#define	RCC_APB1LLPENSR_I3C2LPENS				(0x1u<<25)
#define	RCC_APB1LLPENSR_I3C1LPENS				(0x1u<<24)
#define	RCC_APB1LLPENSR_I2C3LPENS				(0x1u<<23)
#define	RCC_APB1LLPENSR_I2C2LPENS				(0x1u<<22)
#define	RCC_APB1LLPENSR_I2C1LPENS				(0x1u<<21)
#define	RCC_APB1LLPENSR_UART5LPENS				(0x1u<<20)
#define	RCC_APB1LLPENSR_UART4LPENS				(0x1u<<19)
#define	RCC_APB1LLPENSR_USART3LPENS				(0x1u<<18)
#define	RCC_APB1LLPENSR_USART2LPENS				(0x1u<<17)
#define	RCC_APB1LLPENSR_SPDIFRX1LPENS			(0x1u<<16)
#define	RCC_APB1LLPENSR_SPI3LPENS				(0x1u<<15)
#define	RCC_APB1LLPENSR_SPI2LPENS				(0x1u<<14)
#define	RCC_APB1LLPENSR_TIM11LPENS				(0x1u<<13)
#define	RCC_APB1LLPENSR_TIM10LPENS				(0x1u<<12)
#define	RCC_APB1LLPENSR_WWDGLPENS				(0x1u<<11)
#define	RCC_APB1LLPENSR_LPTIM1LPENS				(0x1u<<9)
#define	RCC_APB1LLPENSR_TIM14LPENS				(0x1u<<8)
#define	RCC_APB1LLPENSR_TIM13LPENS				(0x1u<<7)
#define	RCC_APB1LLPENSR_TIM12LPENS				(0x1u<<6)
#define	RCC_APB1LLPENSR_TIM7LPENS				(0x1u<<5)
#define	RCC_APB1LLPENSR_TIM6LPENS				(0x1u<<4)
#define	RCC_APB1LLPENSR_TIM5LPENS				(0x1u<<3)
#define	RCC_APB1LLPENSR_TIM4LPENS				(0x1u<<2)
#define	RCC_APB1LLPENSR_TIM3LPENS				(0x1u<<1)
#define	RCC_APB1LLPENSR_TIM2LPENS				(0x1u<<0)

// APB1HLPENSR Configuration

#define	RCC_APB1HLPENSR_UCPD1LPENS				(0x1u<<18)
#define	RCC_APB1HLPENSR_FDCANLPENS				(0x1u<<8)
#define	RCC_APB1HLPENSR_MDIOSLPENS				(0x1u<<5)

// APB2LPENSR Configuration

#define	RCC_APB2LPENSR_SAI2LPENS				(0x1u<<22)
#define	RCC_APB2LPENSR_SAI1LPENS				(0x1u<<21)
#define	RCC_APB2LPENSR_SPI5LPENS				(0x1u<<20)
#define	RCC_APB2LPENSR_TIM9LPENS				(0x1u<<19)
#define	RCC_APB2LPENSR_TIM17LPENS				(0x1u<<18)
#define	RCC_APB2LPENSR_TIM16LPENS				(0x1u<<17)
#define	RCC_APB2LPENSR_TIM15LPENS				(0x1u<<16)
#define	RCC_APB2LPENSR_TIM18LPENS				(0x1u<<15)
#define	RCC_APB2LPENSR_SPI4LPENS				(0x1u<<13)
#define	RCC_APB2LPENSR_SPI1LPENS				(0x1u<<12)
#define	RCC_APB2LPENSR_USART10LPENS				(0x1u<<7)
#define	RCC_APB2LPENSR_UART9LPENS				(0x1u<<6)
#define	RCC_APB2LPENSR_USART6LPENS				(0x1u<<5)
#define	RCC_APB2LPENSR_USART1LPENS				(0x1u<<4)
#define	RCC_APB2LPENSR_TIM8LPENS				(0x1u<<1)
#define	RCC_APB2LPENSR_TIM1LPENS				(0x1u<<0)

// APB3LPENSR Configuration

#define	RCC_APB3LPENSR_DFTLPENS					(0x1u<<2)

// APB4LLPENSR Configuration

#define	RCC_APB4LLPENSR_SERFLPENS				(0x1u<<31)
#define	RCC_APB4LLPENSR_R2GNPULPENS				(0x1u<<23)
#define	RCC_APB4LLPENSR_R2GRETLPENS				(0x1u<<22)
#define	RCC_APB4LLPENSR_RTCAPBLPENS				(0x1u<<17)
#define	RCC_APB4LLPENSR_RTCLPENS				(0x1u<<16)
#define	RCC_APB4LLPENSR_VREFBUFLPENS			(0x1u<<15)
#define	RCC_APB4LLPENSR_LPTIM5LPENS				(0x1u<<12)
#define	RCC_APB4LLPENSR_LPTIM4LPENS				(0x1u<<11)
#define	RCC_APB4LLPENSR_LPTIM3LPENS				(0x1u<<10)
#define	RCC_APB4LLPENSR_LPTIM2LPENS				(0x1u<<9)
#define	RCC_APB4LLPENSR_I2C4LPENS				(0x1u<<7)
#define	RCC_APB4LLPENSR_SPI6LPENS				(0x1u<<5)
#define	RCC_APB4LLPENSR_LPUART1LPENS			(0x1u<<3)
#define	RCC_APB4LLPENSR_HDPLPENS				(0x1u<<2)

// APB4HLPENSR Configuration

#define	RCC_APB4HLPENSR_BUSPERFMLPENS			(0x1u<<4)
#define	RCC_APB4HLPENSR_DTSLPENS				(0x1u<<2)
#define	RCC_APB4HLPENSR_BSECLPENS				(0x1u<<1)
#define	RCC_APB4HLPENSR_SYSCFGLPENS				(0x1u<<0)

// APB5LPENSR Configuration

#define	RCC_APB5LPENSR_CSILPENS					(0x1u<<6)
#define	RCC_APB5LPENSR_VENCLPENS				(0x1u<<5)
#define	RCC_APB5LPENSR_GFXTIMLPENS				(0x1u<<4)
#define	RCC_APB5LPENSR_DCMIPPLPENS				(0x1u<<2)
#define	RCC_APB5LPENSR_LTDCLPENS				(0x1u<<1)

// PRIVCFGSR0 Configuration

#define	RCC_PRIVCFGSR0_HSEPVS					(0x1u<<4)
#define	RCC_PRIVCFGSR0_HSIPVS					(0x1u<<3)
#define	RCC_PRIVCFGSR0_MSIPVS					(0x1u<<2)
#define	RCC_PRIVCFGSR0_LSEPVS					(0x1u<<1)
#define	RCC_PRIVCFGSR0_LSIPVS					(0x1u<<0)

// PUBCFGSR0 Configuration

#define	RCC_PUBCFGSR0_HSEPUBS					(0x1u<<4)
#define	RCC_PUBCFGSR0_HSIPUBS					(0x1u<<3)
#define	RCC_PUBCFGSR0_MSIPUBS					(0x1u<<2)
#define	RCC_PUBCFGSR0_LSEPUBS					(0x1u<<1)
#define	RCC_PUBCFGSR0_LSIPUBS					(0x1u<<0)

// PRIVCFGSR1 Configuration

#define	RCC_PRIVCFGSR1_PLL4PVS					(0x1u<<3)
#define	RCC_PRIVCFGSR1_PLL3PVS					(0x1u<<2)
#define	RCC_PRIVCFGSR1_PLL2PVS					(0x1u<<1)
#define	RCC_PRIVCFGSR1_PLL1PVS					(0x1u<<0)

// PUBCFGSR1 Configuration

#define	RCC_PUBCFGSR1_PLL4PUBS					(0x1u<<3)
#define	RCC_PUBCFGSR1_PLL3PUBS					(0x1u<<2)
#define	RCC_PUBCFGSR1_PLL2PUBS					(0x1u<<1)
#define	RCC_PUBCFGSR1_PLL1PUBS					(0x1u<<0)

// PRIVCFGSR2 Configuration

#define	RCC_PRIVCFGSR2_IC20PVS					(0x1u<<19)
#define	RCC_PRIVCFGSR2_IC19PVS					(0x1u<<18)
#define	RCC_PRIVCFGSR2_IC18PVS					(0x1u<<17)
#define	RCC_PRIVCFGSR2_IC17PVS					(0x1u<<16)
#define	RCC_PRIVCFGSR2_IC16PVS					(0x1u<<15)
#define	RCC_PRIVCFGSR2_IC15PVS					(0x1u<<14)
#define	RCC_PRIVCFGSR2_IC14PVS					(0x1u<<13)
#define	RCC_PRIVCFGSR2_IC13PVS					(0x1u<<12)
#define	RCC_PRIVCFGSR2_IC12PVS					(0x1u<<11)
#define	RCC_PRIVCFGSR2_IC11PVS					(0x1u<<10)
#define	RCC_PRIVCFGSR2_IC10PVS					(0x1u<<9)
#define	RCC_PRIVCFGSR2_IC9PVS					(0x1u<<8)
#define	RCC_PRIVCFGSR2_IC8PVS					(0x1u<<7)
#define	RCC_PRIVCFGSR2_IC7PVS					(0x1u<<6)
#define	RCC_PRIVCFGSR2_IC6PVS					(0x1u<<5)
#define	RCC_PRIVCFGSR2_IC5PVS					(0x1u<<4)
#define	RCC_PRIVCFGSR2_IC4PVS					(0x1u<<3)
#define	RCC_PRIVCFGSR2_IC3PVS					(0x1u<<2)
#define	RCC_PRIVCFGSR2_IC2PVS					(0x1u<<1)
#define	RCC_PRIVCFGSR2_IC1PVS					(0x1u<<0)

// PUBCFGSR2 Configuration

#define	RCC_PUBCFGSR2_IC20PUBS					(0x1u<<19)
#define	RCC_PUBCFGSR2_IC19PUBS					(0x1u<<18)
#define	RCC_PUBCFGSR2_IC18PUBS					(0x1u<<17)
#define	RCC_PUBCFGSR2_IC17PUBS					(0x1u<<16)
#define	RCC_PUBCFGSR2_IC16PUBS					(0x1u<<15)
#define	RCC_PUBCFGSR2_IC15PUBS					(0x1u<<14)
#define	RCC_PUBCFGSR2_IC14PUBS					(0x1u<<13)
#define	RCC_PUBCFGSR2_IC13PUBS					(0x1u<<12)
#define	RCC_PUBCFGSR2_IC12PUBS					(0x1u<<11)
#define	RCC_PUBCFGSR2_IC11PUBS					(0x1u<<10)
#define	RCC_PUBCFGSR2_IC10PUBS					(0x1u<<9)
#define	RCC_PUBCFGSR2_IC9PUBS					(0x1u<<8)
#define	RCC_PUBCFGSR2_IC8PUBS					(0x1u<<7)
#define	RCC_PUBCFGSR2_IC7PUBS					(0x1u<<6)
#define	RCC_PUBCFGSR2_IC6PUBS					(0x1u<<5)
#define	RCC_PUBCFGSR2_IC5PUBS					(0x1u<<4)
#define	RCC_PUBCFGSR2_IC4PUBS					(0x1u<<3)
#define	RCC_PUBCFGSR2_IC3PUBS					(0x1u<<2)
#define	RCC_PUBCFGSR2_IC2PUBS					(0x1u<<1)
#define	RCC_PUBCFGSR2_IC1PUBS					(0x1u<<0)

// SECCFGSR3 Configuration

#define	RCC_SECCFGSR3_DFTSECS					(0x1u<<6)
#define	RCC_SECCFGSR3_RSTSECS					(0x1u<<5)
#define	RCC_SECCFGSR3_INTSECS					(0x1u<<4)
#define	RCC_SECCFGSR3_PERSECS					(0x1u<<3)
#define	RCC_SECCFGSR3_BUSSECS					(0x1u<<2)
#define	RCC_SECCFGSR3_SYSSECS					(0x1u<<1)
#define	RCC_SECCFGSR3_MODSECS					(0x1u<<0)

// PRIVCFGSR3 Configuration

#define	RCC_PRIVCFGSR3_DFTPVS					(0x1u<<6)
#define	RCC_PRIVCFGSR3_RSTPVS					(0x1u<<5)
#define	RCC_PRIVCFGSR3_INTPVS					(0x1u<<4)
#define	RCC_PRIVCFGSR3_PERPVS					(0x1u<<3)
#define	RCC_PRIVCFGSR3_BUSPVS					(0x1u<<2)
#define	RCC_PRIVCFGSR3_SYSPVS					(0x1u<<1)
#define	RCC_PRIVCFGSR3_MODPVS					(0x1u<<0)

// LOCKCFGSR3 Configuration

#define	RCC_LOCKCFGSR3_DFTLOCKS					(0x1u<<6)
#define	RCC_LOCKCFGSR3_RSTLOCKS					(0x1u<<5)
#define	RCC_LOCKCFGSR3_INTLOCKS					(0x1u<<4)
#define	RCC_LOCKCFGSR3_PERLOCKS					(0x1u<<3)
#define	RCC_LOCKCFGSR3_BUSLOCKS					(0x1u<<2)
#define	RCC_LOCKCFGSR3_SYSLOCKS					(0x1u<<1)
#define	RCC_LOCKCFGSR3_MODLOCKS					(0x1u<<0)

// PUBCFGSR3 Configuration

#define	RCC_PUBCFGSR3_DFTPUBS					(0x1u<<6)
#define	RCC_PUBCFGSR3_RSTPUBS					(0x1u<<5)
#define	RCC_PUBCFGSR3_INTPUBS					(0x1u<<4)
#define	RCC_PUBCFGSR3_PERPUBS					(0x1u<<3)
#define	RCC_PUBCFGSR3_BUSPUBS					(0x1u<<2)
#define	RCC_PUBCFGSR3_SYSPUBS					(0x1u<<1)
#define	RCC_PUBCFGSR3_MODPUBS					(0x1u<<0)

// PRIVCFGSR4 Configuration

#define	RCC_PRIVCFGSR4_NOCPVS					(0x1u<<13)
#define	RCC_PRIVCFGSR4_APB5PVS					(0x1u<<12)
#define	RCC_PRIVCFGSR4_APB4PVS					(0x1u<<11)
#define	RCC_PRIVCFGSR4_APB3PVS					(0x1u<<10)
#define	RCC_PRIVCFGSR4_APB2PVS					(0x1u<<9)
#define	RCC_PRIVCFGSR4_APB1PVS					(0x1u<<8)
#define	RCC_PRIVCFGSR4_AHB5PVS					(0x1u<<7)
#define	RCC_PRIVCFGSR4_AHB4PVS					(0x1u<<6)
#define	RCC_PRIVCFGSR4_AHB3PVS					(0x1u<<5)
#define	RCC_PRIVCFGSR4_AHB2PVS					(0x1u<<4)
#define	RCC_PRIVCFGSR4_AHB1PVS					(0x1u<<3)
#define	RCC_PRIVCFGSR4_AHBMPVS					(0x1u<<2)
#define	RCC_PRIVCFGSR4_ACLKNCPVS				(0x1u<<1)
#define	RCC_PRIVCFGSR4_ACLKNPVS					(0x1u<<0)

// PUBCFGSR4 Configuration

#define	RCC_PUBCFGSR4_NOCPUBS					(0x1u<<13)
#define	RCC_PUBCFGSR4_APB5PUBS					(0x1u<<12)
#define	RCC_PUBCFGSR4_APB4PUBS					(0x1u<<11)
#define	RCC_PUBCFGSR4_APB3PUBS					(0x1u<<10)
#define	RCC_PUBCFGSR4_APB2PUBS					(0x1u<<9)
#define	RCC_PUBCFGSR4_APB1PUBS					(0x1u<<8)
#define	RCC_PUBCFGSR4_AHB5PUBS					(0x1u<<7)
#define	RCC_PUBCFGSR4_AHB4PUBS					(0x1u<<6)
#define	RCC_PUBCFGSR4_AHB3PUBS					(0x1u<<5)
#define	RCC_PUBCFGSR4_AHB2PUBS					(0x1u<<4)
#define	RCC_PUBCFGSR4_AHB1PUBS					(0x1u<<3)
#define	RCC_PUBCFGSR4_AHBMPUBS					(0x1u<<2)
#define	RCC_PUBCFGSR4_ACLKNCPUBS				(0x1u<<1)
#define	RCC_PUBCFGSR4_ACLKNPUBS					(0x1u<<0)

// PUBCFGSR5 Configuration

#define	RCC_PUBCFGSR5_VENCRAMPUBS				(0x1u<<11)
#define	RCC_PUBCFGSR5_NPUCACHERAMPUBS			(0x1u<<10)
#define	RCC_PUBCFGSR5_FLEXRAMPUBS				(0x1u<<9)
#define	RCC_PUBCFGSR5_AXISRAM2PUBS				(0x1u<<8)
#define	RCC_PUBCFGSR5_AXISRAM1PUBS				(0x1u<<7)
#define	RCC_PUBCFGSR5_BKPSRAMPUBS				(0x1u<<6)
#define	RCC_PUBCFGSR5_AHBSRAM2PUBS				(0x1u<<5)
#define	RCC_PUBCFGSR5_AHBSRAM1PUBS				(0x1u<<4)
#define	RCC_PUBCFGSR5_AXISRAM6PUBS				(0x1u<<3)
#define	RCC_PUBCFGSR5_AXISRAM5PUBS				(0x1u<<2)
#define	RCC_PUBCFGSR5_AXISRAM4PUBS				(0x1u<<1)
#define	RCC_PUBCFGSR5_AXISRAM3PUBS				(0x1u<<0)

// CCR Configuration

#define	RCC_CCR_PLL4ONC							(0x1u<<11)
#define	RCC_CCR_PLL3ONC							(0x1u<<10)
#define	RCC_CCR_PLL2ONC							(0x1u<<9)
#define	RCC_CCR_PLL1ONC							(0x1u<<8)
#define	RCC_CCR_HSEONC							(0x1u<<4)
#define	RCC_CCR_HSIONC							(0x1u<<3)
#define	RCC_CCR_MSIONC							(0x1u<<2)
#define	RCC_CCR_LSEONC							(0x1u<<1)
#define	RCC_CCR_LSIONC							(0x1u<<0)

// STOPCCR Configuration

#define	RCC_STOPCCR_HSISTOPENC					(0x1u<<3)
#define	RCC_STOPCCR_MSISTOPENC					(0x1u<<2)
#define	RCC_STOPCCR_LSESTOPENC					(0x1u<<1)
#define	RCC_STOPCCR_LSISTOPENC					(0x1u<<0)

// BUSRSTCR Configuration

#define	RCC_BUSRSTCR_NOCRSTC					(0x1u<<13)
#define	RCC_BUSRSTCR_APB5RSTC					(0x1u<<12)
#define	RCC_BUSRSTCR_APB4RSTC					(0x1u<<11)
#define	RCC_BUSRSTCR_APB3RSTC					(0x1u<<10)
#define	RCC_BUSRSTCR_APB2RSTC					(0x1u<<9)
#define	RCC_BUSRSTCR_APB1RSTC					(0x1u<<8)
#define	RCC_BUSRSTCR_AHB5RSTC					(0x1u<<7)
#define	RCC_BUSRSTCR_AHB4RSTC					(0x1u<<6)
#define	RCC_BUSRSTCR_AHB3RSTC					(0x1u<<5)
#define	RCC_BUSRSTCR_AHB2RSTC					(0x1u<<4)
#define	RCC_BUSRSTCR_AHB1RSTC					(0x1u<<3)
#define	RCC_BUSRSTCR_AHBMRSTC					(0x1u<<2)
#define	RCC_BUSRSTCR_ACLKNRSTC					(0x1u<<0)

// MISCRSTCR Configuration

#define	RCC_MISCRSTCR_SDMMC2DLLRSTC				(0x1u<<8)
#define	RCC_MISCRSTCR_SDMMC1DLLRSTC				(0x1u<<7)
#define	RCC_MISCRSTCR_XSPIPHY2RSTC				(0x1u<<5)
#define	RCC_MISCRSTCR_XSPIPHY1RSTC				(0x1u<<4)
#define	RCC_MISCRSTCR_DBGRSTC					(0x1u<<0)

// MEMRSTCR Configuration

#define	RCC_MEMRSTCR_BOOTROMRSTC				(0x1u<<12)
#define	RCC_MEMRSTCR_VENCRAMRSTC				(0x1u<<11)
#define	RCC_MEMRSTCR_NPUCACHERAMRSTC			(0x1u<<10)
#define	RCC_MEMRSTCR_FLEXRAMRSTC				(0x1u<<9)
#define	RCC_MEMRSTCR_AXISRAM2RSTC				(0x1u<<8)
#define	RCC_MEMRSTCR_AXISRAM1RSTC				(0x1u<<7)
#define	RCC_MEMRSTCR_AHBSRAM2RSTC				(0x1u<<5)
#define	RCC_MEMRSTCR_AHBSRAM1RSTC				(0x1u<<4)
#define	RCC_MEMRSTCR_AXISRAM6RSTC				(0x1u<<3)
#define	RCC_MEMRSTCR_AXISRAM5RSTC				(0x1u<<2)
#define	RCC_MEMRSTCR_AXISRAM4RSTC				(0x1u<<1)
#define	RCC_MEMRSTCR_AXISRAM3RSTC				(0x1u<<0)

// AHB1RSTCR Configuration

#define	RCC_AHB1RSTCR_ADC12RSTC					(0x1u<<5)
#define	RCC_AHB1RSTCR_GPDMA1RSTC				(0x1u<<4)

// AHB2RSTCR Configuration

#define	RCC_AHB2RSTCR_ADF1RSTC					(0x1u<<17)
#define	RCC_AHB2RSTCR_MDF1RSTC					(0x1u<<16)
#define	RCC_AHB2RSTCR_RAMCFGRSTC				(0x1u<<12)

// AHB3RSTCR Configuration

#define	RCC_AHB3RSTCR_IACRSTC					(0x1u<<10)
#define	RCC_AHB3RSTCR_PKARSTC					(0x1u<<8)
#define	RCC_AHB3RSTCR_SAESRSTC					(0x1u<<4)
#define	RCC_AHB3RSTCR_CRYPRSTC					(0x1u<<2)
#define	RCC_AHB3RSTCR_HASHRSTC					(0x1u<<1)
#define	RCC_AHB3RSTCR_RNGRSTC					(0x1u<<0)

// AHB4RSTCR Configuration

#define	RCC_AHB4RSTCR_CRCRSTC					(0x1u<<19)
#define	RCC_AHB4RSTCR_PWRRSTC					(0x1u<<18)
#define	RCC_AHB4RSTCR_GPIOQRSTC					(0x1u<<16)
#define	RCC_AHB4RSTCR_GPIOPRSTC					(0x1u<<15)
#define	RCC_AHB4RSTCR_GPIOORSTC					(0x1u<<14)
#define	RCC_AHB4RSTCR_GPIONRSTC					(0x1u<<13)
#define	RCC_AHB4RSTCR_GPIOHRSTC					(0x1u<<7)
#define	RCC_AHB4RSTCR_GPIOGRSTC					(0x1u<<6)
#define	RCC_AHB4RSTCR_GPIOFRSTC					(0x1u<<5)
#define	RCC_AHB4RSTCR_GPIOERSTC					(0x1u<<4)
#define	RCC_AHB4RSTCR_GPIODRSTC					(0x1u<<3)
#define	RCC_AHB4RSTCR_GPIOCRSTC					(0x1u<<2)
#define	RCC_AHB4RSTCR_GPIOBRSTC					(0x1u<<1)
#define	RCC_AHB4RSTCR_GPIOARSTC					(0x1u<<0)

// AHB5RSTCR Configuration

#define	RCC_AHB5RSTCR_NPURSTC					(0x1u<<31)
#define	RCC_AHB5RSTCR_NPUCACHERSTC				(0x1u<<30)
#define	RCC_AHB5RSTCR_OTG2RSTC					(0x1u<<29)
#define	RCC_AHB5RSTCR_OTGPHY2RSTC				(0x1u<<28)
#define	RCC_AHB5RSTCR_OTGPHY1RSTC				(0x1u<<27)
#define	RCC_AHB5RSTCR_OTG1RSTC					(0x1u<<26)
#define	RCC_AHB5RSTCR_ETH1RSTC					(0x1u<<25)
#define	RCC_AHB5RSTCR_SYSCFGOTGHSPHY2RSTC		(0x1u<<24)
#define	RCC_AHB5RSTCR_SYSCFGOTGHSPHY1RSTC		(0x1u<<23)
#define	RCC_AHB5RSTCR_GPURSTC					(0x1u<<20)
#define	RCC_AHB5RSTCR_GFXMMURSTC				(0x1u<<19)
#define	RCC_AHB5RSTCR_MCE4RSTC					(0x1u<<18)
#define	RCC_AHB5RSTCR_XSPI3RSTC					(0x1u<<17)
#define	RCC_AHB5RSTCR_XSPIMRSTC					(0x1u<<13)
#define	RCC_AHB5RSTCR_XSPI2RSTC					(0x1u<<12)
#define	RCC_AHB5RSTCR_SDMMC1RSTC				(0x1u<<8)
#define	RCC_AHB5RSTCR_SDMMC2RSTC				(0x1u<<7)
#define	RCC_AHB5RSTCR_PSSIRSTC					(0x1u<<6)
#define	RCC_AHB5RSTCR_XSPI1RSTC					(0x1u<<5)
#define	RCC_AHB5RSTCR_FMCRSTC					(0x1u<<4)
#define	RCC_AHB5RSTCR_JPEGRSTC					(0x1u<<3)
#define	RCC_AHB5RSTCR_DMA2DRSTC					(0x1u<<1)
#define	RCC_AHB5RSTCR_HPDMA1RSTC				(0x1u<<0)

// APB1LRSTCR Configuration

#define	RCC_APB1LRSTCR_UART8RSTC				(0x1u<<31)
#define	RCC_APB1LRSTCR_UART7RSTC				(0x1u<<30)
#define	RCC_APB1LRSTCR_I3C2RSTC					(0x1u<<25)
#define	RCC_APB1LRSTCR_I3C1RSTC					(0x1u<<24)
#define	RCC_APB1LRSTCR_I2C3RSTC					(0x1u<<23)
#define	RCC_APB1LRSTCR_I2C2RSTC					(0x1u<<22)
#define	RCC_APB1LRSTCR_I2C1RSTC					(0x1u<<21)
#define	RCC_APB1LRSTCR_UART5RSTC				(0x1u<<20)
#define	RCC_APB1LRSTCR_UART4RSTC				(0x1u<<19)
#define	RCC_APB1LRSTCR_USART3RSTC				(0x1u<<18)
#define	RCC_APB1LRSTCR_USART2RSTC				(0x1u<<17)
#define	RCC_APB1LRSTCR_SPDIFRX1RSTC				(0x1u<<16)
#define	RCC_APB1LRSTCR_SPI3RSTC					(0x1u<<15)
#define	RCC_APB1LRSTCR_SPI2RSTC					(0x1u<<14)
#define	RCC_APB1LRSTCR_TIM11RSTC				(0x1u<<13)
#define	RCC_APB1LRSTCR_TIM10RSTC				(0x1u<<12)
#define	RCC_APB1LRSTCR_WWDGRSTC					(0x1u<<11)
#define	RCC_APB1LRSTCR_LPTIM1RSTC				(0x1u<<9)
#define	RCC_APB1LRSTCR_TIM14RSTC				(0x1u<<8)
#define	RCC_APB1LRSTCR_TIM13RSTC				(0x1u<<7)
#define	RCC_APB1LRSTCR_TIM12RSTC				(0x1u<<6)
#define	RCC_APB1LRSTCR_TIM7RSTC					(0x1u<<5)
#define	RCC_APB1LRSTCR_TIM6RSTC					(0x1u<<4)
#define	RCC_APB1LRSTCR_TIM5RSTC					(0x1u<<3)
#define	RCC_APB1LRSTCR_TIM4RSTC					(0x1u<<2)
#define	RCC_APB1LRSTCR_TIM3RSTC					(0x1u<<1)
#define	RCC_APB1LRSTCR_TIM2RSTC					(0x1u<<0)

// APB1HRSTCR Configuration

#define	RCC_APB1HRSTCR_UCPD1RSTC				(0x1u<<18)
#define	RCC_APB1HRSTCR_FDCANRSTC				(0x1u<<8)
#define	RCC_APB1HRSTCR_MDIOSRSTC				(0x1u<<5)

// APB2RSTCR Configuration

#define	RCC_APB2RSTCR_SAI2RSTC					(0x1u<<22)
#define	RCC_APB2RSTCR_SAI1RSTC					(0x1u<<21)
#define	RCC_APB2RSTCR_SPI5RSTC					(0x1u<<20)
#define	RCC_APB2RSTCR_TIM9RSTC					(0x1u<<19)
#define	RCC_APB2RSTCR_TIM17RSTC					(0x1u<<18)
#define	RCC_APB2RSTCR_TIM16RSTC					(0x1u<<17)
#define	RCC_APB2RSTCR_TIM15RSTC					(0x1u<<16)
#define	RCC_APB2RSTCR_TIM18RSTC					(0x1u<<15)
#define	RCC_APB2RSTCR_SPI4RSTC					(0x1u<<13)
#define	RCC_APB2RSTCR_SPI1RSTC					(0x1u<<12)
#define	RCC_APB2RSTCR_USART10RSTC				(0x1u<<7)
#define	RCC_APB2RSTCR_UART9RSTC					(0x1u<<6)
#define	RCC_APB2RSTCR_USART6RSTC				(0x1u<<5)
#define	RCC_APB2RSTCR_USART1RSTC				(0x1u<<4)
#define	RCC_APB2RSTCR_TIM8RSTC					(0x1u<<1)
#define	RCC_APB2RSTCR_TIM1RSTC					(0x1u<<0)

// APB4LRSTCR Configuration

#define	RCC_APB4LRSTCR_SERFRSTC					(0x1u<<31)
#define	RCC_APB4LRSTCR_R2GNPURSTC				(0x1u<<23)
#define	RCC_APB4LRSTCR_R2GRETRSTC				(0x1u<<22)
#define	RCC_APB4LRSTCR_RTCRSTC					(0x1u<<16)
#define	RCC_APB4LRSTCR_VREFBUFRSTC				(0x1u<<15)
#define	RCC_APB4LRSTCR_LPTIM5RSTC				(0x1u<<12)
#define	RCC_APB4LRSTCR_LPTIM4RSTC				(0x1u<<11)
#define	RCC_APB4LRSTCR_LPTIM3RSTC				(0x1u<<10)
#define	RCC_APB4LRSTCR_LPTIM2RSTC				(0x1u<<9)
#define	RCC_APB4LRSTCR_I2C4RSTC					(0x1u<<7)
#define	RCC_APB4LRSTCR_SPI6RSTC					(0x1u<<5)
#define	RCC_APB4LRSTCR_LPUART1RSTC				(0x1u<<3)
#define	RCC_APB4LRSTCR_HDPRSTC					(0x1u<<2)

// APB4HRSTCR Configuration

#define	RCC_APB4HRSTCR_BUSPERFMRSTC				(0x1u<<4)
#define	RCC_APB4HRSTCR_DTSRSTC					(0x1u<<2)
#define	RCC_APB4HRSTCR_SYSCFGRSTC				(0x1u<<0)

// APB5RSTCR Configuration

#define	RCC_APB5RSTCR_CSIRSTC					(0x1u<<6)
#define	RCC_APB5RSTCR_VENCRSTC					(0x1u<<5)
#define	RCC_APB5RSTCR_GFXTIMRSTC				(0x1u<<4)
#define	RCC_APB5RSTCR_DCMIPPRSTC				(0x1u<<2)
#define	RCC_APB5RSTCR_LTDCRSTC					(0x1u<<1)

// DIVENCR Configuration

#define	RCC_DIVENCR_IC20ENC						(0x1u<<19)
#define	RCC_DIVENCR_IC19ENC						(0x1u<<18)
#define	RCC_DIVENCR_IC18ENC						(0x1u<<17)
#define	RCC_DIVENCR_IC17ENC						(0x1u<<16)
#define	RCC_DIVENCR_IC16ENC						(0x1u<<15)
#define	RCC_DIVENCR_IC15ENC						(0x1u<<14)
#define	RCC_DIVENCR_IC14ENC						(0x1u<<13)
#define	RCC_DIVENCR_IC13ENC						(0x1u<<12)
#define	RCC_DIVENCR_IC12ENC						(0x1u<<11)
#define	RCC_DIVENCR_IC11ENC						(0x1u<<10)
#define	RCC_DIVENCR_IC10ENC						(0x1u<<9)
#define	RCC_DIVENCR_IC9ENC						(0x1u<<8)
#define	RCC_DIVENCR_IC8ENC						(0x1u<<7)
#define	RCC_DIVENCR_IC7ENC						(0x1u<<6)
#define	RCC_DIVENCR_IC6ENC						(0x1u<<5)
#define	RCC_DIVENCR_IC5ENC						(0x1u<<4)
#define	RCC_DIVENCR_IC4ENC						(0x1u<<3)
#define	RCC_DIVENCR_IC3ENC						(0x1u<<2)
#define	RCC_DIVENCR_IC2ENC						(0x1u<<1)
#define	RCC_DIVENCR_IC1ENC						(0x1u<<0)

// BUSENCR Configuration

#define	RCC_BUSENCR_APB5ENC						(0x1u<<12)
#define	RCC_BUSENCR_APB4ENC						(0x1u<<11)
#define	RCC_BUSENCR_APB3ENC						(0x1u<<10)
#define	RCC_BUSENCR_APB2ENC						(0x1u<<9)
#define	RCC_BUSENCR_APB1ENC						(0x1u<<8)
#define	RCC_BUSENCR_AHB5ENC						(0x1u<<7)
#define	RCC_BUSENCR_AHB4ENC						(0x1u<<6)
#define	RCC_BUSENCR_AHB3ENC						(0x1u<<5)
#define	RCC_BUSENCR_AHB2ENC						(0x1u<<4)
#define	RCC_BUSENCR_AHB1ENC						(0x1u<<3)
#define	RCC_BUSENCR_AHBMENC						(0x1u<<2)
#define	RCC_BUSENCR_ACLKNCENC					(0x1u<<1)
#define	RCC_BUSENCR_ACLKNENC					(0x1u<<0)

// MISCENCR Configuration

#define	RCC_MISCENCR_PERENC						(0x1u<<6)
#define	RCC_MISCENCR_XSPIPHYCOMPENC				(0x1u<<3)
#define	RCC_MISCENCR_MCO2ENC					(0x1u<<2)
#define	RCC_MISCENCR_MCO1ENC					(0x1u<<1)
#define	RCC_MISCENCR_DBGENC						(0x1u<<0)

// MEMENCR Configuration

#define	RCC_MEMENCR_BOOTROMENC					(0x1u<<12)
#define	RCC_MEMENCR_VENCRAMENC					(0x1u<<11)
#define	RCC_MEMENCR_NPUCACHERAMENC				(0x1u<<10)
#define	RCC_MEMENCR_FLEXRAMENC					(0x1u<<9)
#define	RCC_MEMENCR_AXISRAM2ENC					(0x1u<<8)
#define	RCC_MEMENCR_AXISRAM1ENC					(0x1u<<7)
#define	RCC_MEMENCR_BKPSRAMENC					(0x1u<<6)
#define	RCC_MEMENCR_AHBSRAM2ENC					(0x1u<<5)
#define	RCC_MEMENCR_AHBSRAM1ENC					(0x1u<<4)
#define	RCC_MEMENCR_AXISRAM6ENC					(0x1u<<3)
#define	RCC_MEMENCR_AXISRAM5ENC					(0x1u<<2)
#define	RCC_MEMENCR_AXISRAM4ENC					(0x1u<<1)
#define	RCC_MEMENCR_AXISRAM3ENC					(0x1u<<0)

// AHB1ENCR Configuration

#define	RCC_AHB1ENCR_ADC12ENC					(0x1u<<5)
#define	RCC_AHB1ENCR_GPDMA1ENC					(0x1u<<4)

// AHB2ENCR Configuration

#define	RCC_AHB2ENCR_ADF1ENC					(0x1u<<17)
#define	RCC_AHB2ENCR_MDF1ENC					(0x1u<<16)
#define	RCC_AHB2ENCR_RAMCFGENC					(0x1u<<12)

// AHB3ENCR Configuration

#define	RCC_AHB3ENCR_RISAFENC					(0x1u<<14)
#define	RCC_AHB3ENCR_IACENC						(0x1u<<10)
#define	RCC_AHB3ENCR_RIFSCENC					(0x1u<<9)
#define	RCC_AHB3ENCR_PKAENC						(0x1u<<8)
#define	RCC_AHB3ENCR_SAESENC					(0x1u<<4)
#define	RCC_AHB3ENCR_CRYPENC					(0x1u<<2)
#define	RCC_AHB3ENCR_HASHENC					(0x1u<<1)
#define	RCC_AHB3ENCR_RNGENC						(0x1u<<0)

// AHB4ENCR Configuration

#define	RCC_AHB4ENCR_CRCENC						(0x1u<<19)
#define	RCC_AHB4ENCR_PWRENC						(0x1u<<18)
#define	RCC_AHB4ENCR_GPIOQENC					(0x1u<<16)
#define	RCC_AHB4ENCR_GPIOPENC					(0x1u<<15)
#define	RCC_AHB4ENCR_GPIOOENC					(0x1u<<14)
#define	RCC_AHB4ENCR_GPIONENC					(0x1u<<13)
#define	RCC_AHB4ENCR_GPIOHENC					(0x1u<<7)
#define	RCC_AHB4ENCR_GPIOGENC					(0x1u<<6)
#define	RCC_AHB4ENCR_GPIOFENC					(0x1u<<5)
#define	RCC_AHB4ENCR_GPIOEENC					(0x1u<<4)
#define	RCC_AHB4ENCR_GPIODENC					(0x1u<<3)
#define	RCC_AHB4ENCR_GPIOCENC					(0x1u<<2)
#define	RCC_AHB4ENCR_GPIOBENC					(0x1u<<1)
#define	RCC_AHB4ENCR_GPIOAENC					(0x1u<<0)

// AHB5ENCR Configuration

#define	RCC_AHB5ENCR_NPUENC						(0x1u<<31)
#define	RCC_AHB5ENCR_NPUCACHEENC				(0x1u<<30)
#define	RCC_AHB5ENCR_OTG2ENC					(0x1u<<29)
#define	RCC_AHB5ENCR_OTGPHY2ENC					(0x1u<<28)
#define	RCC_AHB5ENCR_OTGPHY1ENC					(0x1u<<27)
#define	RCC_AHB5ENCR_OTG1ENC					(0x1u<<26)
#define	RCC_AHB5ENCR_ETH1ENC					(0x1u<<25)
#define	RCC_AHB5ENCR_ETH1RXENC					(0x1u<<24)
#define	RCC_AHB5ENCR_ETH1TXENC					(0x1u<<23)
#define	RCC_AHB5ENCR_ETH1MACENC					(0x1u<<22)
#define	RCC_AHB5ENCR_GPUENC						(0x1u<<20)
#define	RCC_AHB5ENCR_GFXMMUENC					(0x1u<<19)
#define	RCC_AHB5ENCR_MCE4ENC					(0x1u<<18)
#define	RCC_AHB5ENCR_XSPI3ENC					(0x1u<<17)
#define	RCC_AHB5ENCR_MCE3ENC					(0x1u<<16)
#define	RCC_AHB5ENCR_MCE2ENC					(0x1u<<15)
#define	RCC_AHB5ENCR_MCE1ENC					(0x1u<<14)
#define	RCC_AHB5ENCR_XSPIMENC					(0x1u<<13)
#define	RCC_AHB5ENCR_XSPI2ENC					(0x1u<<12)
#define	RCC_AHB5ENCR_SDMMC1ENC					(0x1u<<8)
#define	RCC_AHB5ENCR_SDMMC2ENC					(0x1u<<7)
#define	RCC_AHB5ENCR_PSSIENC					(0x1u<<6)
#define	RCC_AHB5ENCR_XSPI1ENC					(0x1u<<5)
#define	RCC_AHB5ENCR_FMCENC						(0x1u<<4)
#define	RCC_AHB5ENCR_JPEGENC					(0x1u<<3)
#define	RCC_AHB5ENCR_DMA2DENC					(0x1u<<1)
#define	RCC_AHB5ENCR_HPDMA1ENC					(0x1u<<0)

// APB1LENCR Configuration

#define	RCC_APB1LENCR_UART8ENC					(0x1u<<31)
#define	RCC_APB1LENCR_UART7ENC					(0x1u<<30)
#define	RCC_APB1LENCR_I3C2ENC					(0x1u<<25)
#define	RCC_APB1LENCR_I3C1ENC					(0x1u<<24)
#define	RCC_APB1LENCR_I2C3ENC					(0x1u<<23)
#define	RCC_APB1LENCR_I2C2ENC					(0x1u<<22)
#define	RCC_APB1LENCR_I2C1ENC					(0x1u<<21)
#define	RCC_APB1LENCR_UART5ENC					(0x1u<<20)
#define	RCC_APB1LENCR_UART4ENC					(0x1u<<19)
#define	RCC_APB1LENCR_USART3ENC					(0x1u<<18)
#define	RCC_APB1LENCR_USART2ENC					(0x1u<<17)
#define	RCC_APB1LENCR_SPDIFRX1ENC				(0x1u<<16)
#define	RCC_APB1LENCR_SPI3ENC					(0x1u<<15)
#define	RCC_APB1LENCR_SPI2ENC					(0x1u<<14)
#define	RCC_APB1LENCR_TIM11ENC					(0x1u<<13)
#define	RCC_APB1LENCR_TIM10ENC					(0x1u<<12)
#define	RCC_APB1LENCR_LPTIM1ENC					(0x1u<<9)
#define	RCC_APB1LENCR_TIM14ENC					(0x1u<<8)
#define	RCC_APB1LENCR_TIM13ENC					(0x1u<<7)
#define	RCC_APB1LENCR_TIM12ENC					(0x1u<<6)
#define	RCC_APB1LENCR_TIM7ENC					(0x1u<<5)
#define	RCC_APB1LENCR_TIM6ENC					(0x1u<<4)
#define	RCC_APB1LENCR_TIM5ENC					(0x1u<<3)
#define	RCC_APB1LENCR_TIM4ENC					(0x1u<<2)
#define	RCC_APB1LENCR_TIM3ENC					(0x1u<<1)
#define	RCC_APB1LENCR_TIM2ENC					(0x1u<<0)

// APB1HENCR Configuration

#define	RCC_APB1HENCR_UCPD1ENC					(0x1u<<18)
#define	RCC_APB1HENCR_FDCANENC					(0x1u<<8)
#define	RCC_APB1HENCR_MDIOSENC					(0x1u<<5)

// APB2ENCR Configuration

#define	RCC_APB2ENCR_SAI2ENC					(0x1u<<22)
#define	RCC_APB2ENCR_SAI1ENC					(0x1u<<21)
#define	RCC_APB2ENCR_SPI5ENC					(0x1u<<20)
#define	RCC_APB2ENCR_TIM9ENC					(0x1u<<19)
#define	RCC_APB2ENCR_TIM17ENC					(0x1u<<18)
#define	RCC_APB2ENCR_TIM16ENC					(0x1u<<17)
#define	RCC_APB2ENCR_TIM15ENC					(0x1u<<16)
#define	RCC_APB2ENCR_TIM18ENC					(0x1u<<15)
#define	RCC_APB2ENCR_SPI4ENC					(0x1u<<13)
#define	RCC_APB2ENCR_SPI1ENC					(0x1u<<12)
#define	RCC_APB2ENCR_USART10ENC					(0x1u<<7)
#define	RCC_APB2ENCR_UART9ENC					(0x1u<<6)
#define	RCC_APB2ENCR_USART6ENC					(0x1u<<5)
#define	RCC_APB2ENCR_USART1ENC					(0x1u<<4)
#define	RCC_APB2ENCR_TIM8ENC					(0x1u<<1)
#define	RCC_APB2ENCR_TIM1ENC					(0x1u<<0)

// APB3ENCR Configuration

#define	RCC_APB3ENCR_DFTENC						(0x1u<<2)

// APB4LENCR Configuration

#define	RCC_APB4LENCR_SERFENC					(0x1u<<31)
#define	RCC_APB4LENCR_R2GNPUENC					(0x1u<<23)
#define	RCC_APB4LENCR_R2GRETENC					(0x1u<<22)
#define	RCC_APB4LENCR_RTCAPBENC					(0x1u<<17)
#define	RCC_APB4LENCR_RTCENC					(0x1u<<16)
#define	RCC_APB4LENCR_VREFBUFENC				(0x1u<<15)
#define	RCC_APB4LENCR_LPTIM5ENC					(0x1u<<12)
#define	RCC_APB4LENCR_LPTIM4ENC					(0x1u<<11)
#define	RCC_APB4LENCR_LPTIM3ENC					(0x1u<<10)
#define	RCC_APB4LENCR_LPTIM2ENC					(0x1u<<9)
#define	RCC_APB4LENCR_I2C4ENC					(0x1u<<7)
#define	RCC_APB4LENCR_SPI6ENC					(0x1u<<5)
#define	RCC_APB4LENCR_LPUART1ENC				(0x1u<<3)
#define	RCC_APB4LENCR_HDPENC					(0x1u<<2)

// APB4HENCR Configuration

#define	RCC_APB4HENCR_BUSPERFMENC				(0x1u<<4)
#define	RCC_APB4HENCR_DTSENC					(0x1u<<2)
#define	RCC_APB4HENCR_BSECENC					(0x1u<<1)
#define	RCC_APB4HENCR_SYSCFGENC					(0x1u<<0)

// APB5ENCR Configuration

#define	RCC_APB5ENCR_CSIENC						(0x1u<<6)
#define	RCC_APB5ENCR_VENCENC					(0x1u<<5)
#define	RCC_APB5ENCR_GFXTIMENC					(0x1u<<4)
#define	RCC_APB5ENCR_DCMIPPENC					(0x1u<<2)
#define	RCC_APB5ENCR_LTDCENC					(0x1u<<1)

// DIVLPENCR Configuration

#define	RCC_DIVLPENCR_IC20LPENC					(0x1u<<19)
#define	RCC_DIVLPENCR_IC19LPENC					(0x1u<<18)
#define	RCC_DIVLPENCR_IC18LPENC					(0x1u<<17)
#define	RCC_DIVLPENCR_IC17LPENC					(0x1u<<16)
#define	RCC_DIVLPENCR_IC16LPENC					(0x1u<<15)
#define	RCC_DIVLPENCR_IC15LPENC					(0x1u<<14)
#define	RCC_DIVLPENCR_IC14LPENC					(0x1u<<13)
#define	RCC_DIVLPENCR_IC13LPENC					(0x1u<<12)
#define	RCC_DIVLPENCR_IC12LPENC					(0x1u<<11)
#define	RCC_DIVLPENCR_IC11LPENC					(0x1u<<10)
#define	RCC_DIVLPENCR_IC10LPENC					(0x1u<<9)
#define	RCC_DIVLPENCR_IC9LPENC					(0x1u<<8)
#define	RCC_DIVLPENCR_IC8LPENC					(0x1u<<7)
#define	RCC_DIVLPENCR_IC7LPENC					(0x1u<<6)
#define	RCC_DIVLPENCR_IC6LPENC					(0x1u<<5)
#define	RCC_DIVLPENCR_IC5LPENC					(0x1u<<4)
#define	RCC_DIVLPENCR_IC4LPENC					(0x1u<<3)
#define	RCC_DIVLPENCR_IC3LPENC					(0x1u<<2)
#define	RCC_DIVLPENCR_IC2LPENC					(0x1u<<1)
#define	RCC_DIVLPENCR_IC1LPENC					(0x1u<<0)

// BUSLPENCR Configuration

#define	RCC_BUSLPENCR_APB5LPENC					(0x1u<<12)
#define	RCC_BUSLPENCR_APB4LPENC					(0x1u<<11)
#define	RCC_BUSLPENCR_APB3LPENC					(0x1u<<10)
#define	RCC_BUSLPENCR_APB2LPENC					(0x1u<<9)
#define	RCC_BUSLPENCR_APB1LPENC					(0x1u<<8)
#define	RCC_BUSLPENCR_AHB5LPENC					(0x1u<<7)
#define	RCC_BUSLPENCR_AHB4LPENC					(0x1u<<6)
#define	RCC_BUSLPENCR_AHB3LPENC					(0x1u<<5)
#define	RCC_BUSLPENCR_AHB2LPENC					(0x1u<<4)
#define	RCC_BUSLPENCR_AHB1LPENC					(0x1u<<3)
#define	RCC_BUSLPENCR_AHBMLPENC					(0x1u<<2)
#define	RCC_BUSLPENCR_ACLKNCLPENC				(0x1u<<1)
#define	RCC_BUSLPENCR_ACLKNLPENC				(0x1u<<0)

// MISCLPENCR Configuration

#define	RCC_MISCLPENCR_PERLPENC					(0x1u<<6)
#define	RCC_MISCLPENCR_XSPIPHYCOMPLPENC			(0x1u<<3)
#define	RCC_MISCLPENCR_DBGLPENC					(0x1u<<0)

// MEMLPENCR Configuration

#define	RCC_MEMLPENCR_BOOTROMLPENC				(0x1u<<12)
#define	RCC_MEMLPENCR_VENCRAMLPENC				(0x1u<<11)
#define	RCC_MEMLPENCR_NPUCACHERAMLPENC			(0x1u<<10)
#define	RCC_MEMLPENCR_FLEXRAMLPENC				(0x1u<<9)
#define	RCC_MEMLPENCR_AXISRAM2LPENC				(0x1u<<8)
#define	RCC_MEMLPENCR_AXISRAM1LPENC				(0x1u<<7)
#define	RCC_MEMLPENCR_BKPSRAMLPENC				(0x1u<<6)
#define	RCC_MEMLPENCR_AHBSRAM2LPENC				(0x1u<<5)
#define	RCC_MEMLPENCR_AHBSRAM1LPENC				(0x1u<<4)
#define	RCC_MEMLPENCR_AXISRAM6LPENC				(0x1u<<3)
#define	RCC_MEMLPENCR_AXISRAM5LPENC				(0x1u<<2)
#define	RCC_MEMLPENCR_AXISRAM4LPENC				(0x1u<<1)
#define	RCC_MEMLPENCR_AXISRAM3LPENC				(0x1u<<0)

// AHB1LPENCR Configuration

#define	RCC_AHB1LPENCR_ADC12LPENC				(0x1u<<5)
#define	RCC_AHB1LPENCR_GPDMA1LPENC				(0x1u<<4)

// AHB2LPENCR Configuration

#define	RCC_AHB2LPENCR_ADF1LPENC				(0x1u<<17)
#define	RCC_AHB2LPENCR_MDF1LPENC				(0x1u<<16)
#define	RCC_AHB2LPENCR_RAMCFGLPENC				(0x1u<<12)

// AHB3LPENCR Configuration

#define	RCC_AHB3LPENCR_RISAFLPENC				(0x1u<<14)
#define	RCC_AHB3LPENCR_IACLPENC					(0x1u<<10)
#define	RCC_AHB3LPENCR_RIFSCLPENC				(0x1u<<9)
#define	RCC_AHB3LPENCR_PKALPENC					(0x1u<<8)
#define	RCC_AHB3LPENCR_SAESLPENC				(0x1u<<4)
#define	RCC_AHB3LPENCR_CRYPLPENC				(0x1u<<2)
#define	RCC_AHB3LPENCR_HASHLPENC				(0x1u<<1)
#define	RCC_AHB3LPENCR_RNGLPENC					(0x1u<<0)

// AHB4LPENCR Configuration

#define	RCC_AHB4LPENCR_CRCLPENC					(0x1u<<19)
#define	RCC_AHB4LPENCR_PWRLPENC					(0x1u<<18)
#define	RCC_AHB4LPENCR_GPIOQLPENC				(0x1u<<16)
#define	RCC_AHB4LPENCR_GPIOPLPENC				(0x1u<<15)
#define	RCC_AHB4LPENCR_GPIOOLPENC				(0x1u<<14)
#define	RCC_AHB4LPENCR_GPIONLPENC				(0x1u<<13)
#define	RCC_AHB4LPENCR_GPIOHLPENC				(0x1u<<7)
#define	RCC_AHB4LPENCR_GPIOGLPENC				(0x1u<<6)
#define	RCC_AHB4LPENCR_GPIOFLPENC				(0x1u<<5)
#define	RCC_AHB4LPENCR_GPIOELPENC				(0x1u<<4)
#define	RCC_AHB4LPENCR_GPIODLPENC				(0x1u<<3)
#define	RCC_AHB4LPENCR_GPIOCLPENC				(0x1u<<2)
#define	RCC_AHB4LPENCR_GPIOBLPENC				(0x1u<<1)
#define	RCC_AHB4LPENCR_GPIOALPENC				(0x1u<<0)

// AHB5LPENCR Configuration

#define	RCC_AHB5LPENCR_NPULPENC					(0x1u<<31)
#define	RCC_AHB5LPENCR_NPUCACHELPENC			(0x1u<<30)
#define	RCC_AHB5LPENCR_OTG2LPENC				(0x1u<<29)
#define	RCC_AHB5LPENCR_OTGPHY2LPENC				(0x1u<<28)
#define	RCC_AHB5LPENCR_OTGPHY1LPENC				(0x1u<<27)
#define	RCC_AHB5LPENCR_OTG1LPENC				(0x1u<<26)
#define	RCC_AHB5LPENCR_ETH1LPENC				(0x1u<<25)
#define	RCC_AHB5LPENCR_ETH1RXLPENC				(0x1u<<24)
#define	RCC_AHB5LPENCR_ETH1TXLPENC				(0x1u<<23)
#define	RCC_AHB5LPENCR_ETH1MACLPENC				(0x1u<<22)
#define	RCC_AHB5LPENCR_GPULPENC					(0x1u<<20)
#define	RCC_AHB5LPENCR_GFXMMULPENC				(0x1u<<19)
#define	RCC_AHB5LPENCR_MCE4LPENC				(0x1u<<18)
#define	RCC_AHB5LPENCR_XSPI3LPENC				(0x1u<<17)
#define	RCC_AHB5LPENCR_MCE3LPENC				(0x1u<<16)
#define	RCC_AHB5LPENCR_MCE2LPENC				(0x1u<<15)
#define	RCC_AHB5LPENCR_MCE1LPENC				(0x1u<<14)
#define	RCC_AHB5LPENCR_XSPIMLPENC				(0x1u<<13)
#define	RCC_AHB5LPENCR_XSPI2LPENC				(0x1u<<12)
#define	RCC_AHB5LPENCR_SDMMC1LPENC				(0x1u<<8)
#define	RCC_AHB5LPENCR_SDMMC2LPENC				(0x1u<<7)
#define	RCC_AHB5LPENCR_PSSILPENC				(0x1u<<6)
#define	RCC_AHB5LPENCR_XSPI1LPENC				(0x1u<<5)
#define	RCC_AHB5LPENCR_FMCLPENC					(0x1u<<4)
#define	RCC_AHB5LPENCR_JPEGLPENC				(0x1u<<3)
#define	RCC_AHB5LPENCR_DMA2DLPENC				(0x1u<<1)
#define	RCC_AHB5LPENCR_HPDMA1LPENC				(0x1u<<0)

// APB1LLPENCR Configuration

#define	RCC_APB1LLPENCR_UART8LPENC				(0x1u<<31)
#define	RCC_APB1LLPENCR_UART7LPENC				(0x1u<<30)
#define	RCC_APB1LLPENCR_I3C2LPENC				(0x1u<<25)
#define	RCC_APB1LLPENCR_I3C1LPENC				(0x1u<<24)
#define	RCC_APB1LLPENCR_I2C3LPENC				(0x1u<<23)
#define	RCC_APB1LLPENCR_I2C2LPENC				(0x1u<<22)
#define	RCC_APB1LLPENCR_I2C1LPENC				(0x1u<<21)
#define	RCC_APB1LLPENCR_UART5LPENC				(0x1u<<20)
#define	RCC_APB1LLPENCR_UART4LPENC				(0x1u<<19)
#define	RCC_APB1LLPENCR_USART3LPENC				(0x1u<<18)
#define	RCC_APB1LLPENCR_USART2LPENC				(0x1u<<17)
#define	RCC_APB1LLPENCR_SPDIFRX1LPENC			(0x1u<<16)
#define	RCC_APB1LLPENCR_SPI3LPENC				(0x1u<<15)
#define	RCC_APB1LLPENCR_SPI2LPENC				(0x1u<<14)
#define	RCC_APB1LLPENCR_TIM11LPENC				(0x1u<<13)
#define	RCC_APB1LLPENCR_TIM10LPENC				(0x1u<<12)
#define	RCC_APB1LLPENCR_WWDGLPENC				(0x1u<<11)
#define	RCC_APB1LLPENCR_LPTIM1LPENC				(0x1u<<9)
#define	RCC_APB1LLPENCR_TIM14LPENC				(0x1u<<8)
#define	RCC_APB1LLPENCR_TIM13LPENC				(0x1u<<7)
#define	RCC_APB1LLPENCR_TIM12LPENC				(0x1u<<6)
#define	RCC_APB1LLPENCR_TIM7LPENC				(0x1u<<5)
#define	RCC_APB1LLPENCR_TIM6LPENC				(0x1u<<4)
#define	RCC_APB1LLPENCR_TIM5LPENC				(0x1u<<3)
#define	RCC_APB1LLPENCR_TIM4LPENC				(0x1u<<2)
#define	RCC_APB1LLPENCR_TIM3LPENC				(0x1u<<1)
#define	RCC_APB1LLPENCR_TIM2LPENC				(0x1u<<0)

// APB1HLPENCR Configuration

#define	RCC_APB1HLPENCR_UCPD1LPENC				(0x1u<<18)
#define	RCC_APB1HLPENCR_FDCANLPENC				(0x1u<<8)
#define	RCC_APB1HLPENCR_MDIOSLPENC				(0x1u<<5)

// APB2LPENCR Configuration

#define	RCC_APB2LPENCR_SAI2LPENC				(0x1u<<22)
#define	RCC_APB2LPENCR_SAI1LPENC				(0x1u<<21)
#define	RCC_APB2LPENCR_SPI5LPENC				(0x1u<<20)
#define	RCC_APB2LPENCR_TIM9LPENC				(0x1u<<19)
#define	RCC_APB2LPENCR_TIM17LPENC				(0x1u<<18)
#define	RCC_APB2LPENCR_TIM16LPENC				(0x1u<<17)
#define	RCC_APB2LPENCR_TIM15LPENC				(0x1u<<16)
#define	RCC_APB2LPENCR_TIM18LPENC				(0x1u<<15)
#define	RCC_APB2LPENCR_SPI4LPENC				(0x1u<<13)
#define	RCC_APB2LPENCR_SPI1LPENC				(0x1u<<12)
#define	RCC_APB2LPENCR_USART10LPENC				(0x1u<<7)
#define	RCC_APB2LPENCR_UART9LPENC				(0x1u<<6)
#define	RCC_APB2LPENCR_USART6LPENC				(0x1u<<5)
#define	RCC_APB2LPENCR_USART1LPENC				(0x1u<<4)
#define	RCC_APB2LPENCR_TIM8LPENC				(0x1u<<1)
#define	RCC_APB2LPENCR_TIM1LPENC				(0x1u<<0)

// APB3LPENCR Configuration

#define	RCC_APB3LPENCR_DFTLPENC					(0x1u<<2)

// APB4LLPENCR Configuration

#define	RCC_APB4LLPENCR_SERFLPENC				(0x1u<<31)
#define	RCC_APB4LLPENCR_R2GNPULPENC				(0x1u<<23)
#define	RCC_APB4LLPENCR_R2GRETLPENC				(0x1u<<22)
#define	RCC_APB4LLPENCR_RTCAPBLPENC				(0x1u<<17)
#define	RCC_APB4LLPENCR_RTCLPENC				(0x1u<<16)
#define	RCC_APB4LLPENCR_VREFBUFLPENC			(0x1u<<15)
#define	RCC_APB4LLPENCR_LPTIM5LPENC				(0x1u<<12)
#define	RCC_APB4LLPENCR_LPTIM4LPENC				(0x1u<<11)
#define	RCC_APB4LLPENCR_LPTIM3LPENC				(0x1u<<10)
#define	RCC_APB4LLPENCR_LPTIM2LPENC				(0x1u<<9)
#define	RCC_APB4LLPENCR_I2C4LPENC				(0x1u<<7)
#define	RCC_APB4LLPENCR_SPI6LPENC				(0x1u<<5)
#define	RCC_APB4LLPENCR_LPUART1LPENC			(0x1u<<3)
#define	RCC_APB4LLPENCR_HDPLPENC				(0x1u<<2)

// APB4HLPENCR Configuration

#define	RCC_APB4HLPENCR_BUSPERFMLPENC			(0x1u<<4)
#define	RCC_APB4HLPENCR_DTSLPENC				(0x1u<<2)
#define	RCC_APB4HLPENCR_BSECLPENC				(0x1u<<1)
#define	RCC_APB4HLPENCR_SYSCFGLPENC				(0x1u<<0)

// APB5LPENCR Configuration

#define	RCC_APB5LPENCR_CSILPENC					(0x1u<<6)
#define	RCC_APB5LPENCR_VENCLPENC				(0x1u<<5)
#define	RCC_APB5LPENCR_GFXTIMLPENC				(0x1u<<4)
#define	RCC_APB5LPENCR_DCMIPPLPENC				(0x1u<<2)
#define	RCC_APB5LPENCR_LTDCLPENC				(0x1u<<1)

// PRIVCFGCR0 Configuration

#define	RCC_PRIVCFGCR0_HSEPVC					(0x1u<<4)
#define	RCC_PRIVCFGCR0_HSIPVC					(0x1u<<3)
#define	RCC_PRIVCFGCR0_MSIPVC					(0x1u<<2)
#define	RCC_PRIVCFGCR0_LSEPVC					(0x1u<<1)
#define	RCC_PRIVCFGCR0_LSIPVC					(0x1u<<0)

// PUBCFGCR0 Configuration

#define	RCC_PUBCFGCR0_HSEPUBC					(0x1u<<4)
#define	RCC_PUBCFGCR0_HSIPUBC					(0x1u<<3)
#define	RCC_PUBCFGCR0_MSIPUBC					(0x1u<<2)
#define	RCC_PUBCFGCR0_LSEPUBC					(0x1u<<1)
#define	RCC_PUBCFGCR0_LSIPUBC					(0x1u<<0)

// PRIVCFGCR1 Configuration

#define	RCC_PRIVCFGCR1_PLL4PVC					(0x1u<<3)
#define	RCC_PRIVCFGCR1_PLL3PVC					(0x1u<<2)
#define	RCC_PRIVCFGCR1_PLL2PVC					(0x1u<<1)
#define	RCC_PRIVCFGCR1_PLL1PVC					(0x1u<<0)

// PUBCFGCR1 Configuration

#define	RCC_PUBCFGCR1_PLL4PUBC					(0x1u<<3)
#define	RCC_PUBCFGCR1_PLL3PUBC					(0x1u<<2)
#define	RCC_PUBCFGCR1_PLL2PUBC					(0x1u<<1)
#define	RCC_PUBCFGCR1_PLL1PUBC					(0x1u<<0)

// PRIVCFGCR2 Configuration

#define	RCC_PRIVCFGCR2_IC20PVC					(0x1u<<19)
#define	RCC_PRIVCFGCR2_IC19PVC					(0x1u<<18)
#define	RCC_PRIVCFGCR2_IC18PVC					(0x1u<<17)
#define	RCC_PRIVCFGCR2_IC17PVC					(0x1u<<16)
#define	RCC_PRIVCFGCR2_IC16PVC					(0x1u<<15)
#define	RCC_PRIVCFGCR2_IC15PVC					(0x1u<<14)
#define	RCC_PRIVCFGCR2_IC14PVC					(0x1u<<13)
#define	RCC_PRIVCFGCR2_IC13PVC					(0x1u<<12)
#define	RCC_PRIVCFGCR2_IC12PVC					(0x1u<<11)
#define	RCC_PRIVCFGCR2_IC11PVC					(0x1u<<10)
#define	RCC_PRIVCFGCR2_IC10PVC					(0x1u<<9)
#define	RCC_PRIVCFGCR2_IC9PVC					(0x1u<<8)
#define	RCC_PRIVCFGCR2_IC8PVC					(0x1u<<7)
#define	RCC_PRIVCFGCR2_IC7PVC					(0x1u<<6)
#define	RCC_PRIVCFGCR2_IC6PVC					(0x1u<<5)
#define	RCC_PRIVCFGCR2_IC5PVC					(0x1u<<4)
#define	RCC_PRIVCFGCR2_IC4PVC					(0x1u<<3)
#define	RCC_PRIVCFGCR2_IC3PVC					(0x1u<<2)
#define	RCC_PRIVCFGCR2_IC2PVC					(0x1u<<1)
#define	RCC_PRIVCFGCR2_IC1PVC					(0x1u<<0)

// PUBCFGCR2 Configuration

#define	RCC_PUBCFGCR2_IC20PUBC					(0x1u<<19)
#define	RCC_PUBCFGCR2_IC19PUBC					(0x1u<<18)
#define	RCC_PUBCFGCR2_IC18PUBC					(0x1u<<17)
#define	RCC_PUBCFGCR2_IC17PUBC					(0x1u<<16)
#define	RCC_PUBCFGCR2_IC16PUBC					(0x1u<<15)
#define	RCC_PUBCFGCR2_IC15PUBC					(0x1u<<14)
#define	RCC_PUBCFGCR2_IC14PUBC					(0x1u<<13)
#define	RCC_PUBCFGCR2_IC13PUBC					(0x1u<<12)
#define	RCC_PUBCFGCR2_IC12PUBC					(0x1u<<11)
#define	RCC_PUBCFGCR2_IC11PUBC					(0x1u<<10)
#define	RCC_PUBCFGCR2_IC10PUBC					(0x1u<<9)
#define	RCC_PUBCFGCR2_IC9PUBC					(0x1u<<8)
#define	RCC_PUBCFGCR2_IC8PUBC					(0x1u<<7)
#define	RCC_PUBCFGCR2_IC7PUBC					(0x1u<<6)
#define	RCC_PUBCFGCR2_IC6PUBC					(0x1u<<5)
#define	RCC_PUBCFGCR2_IC5PUBC					(0x1u<<4)
#define	RCC_PUBCFGCR2_IC4PUBC					(0x1u<<3)
#define	RCC_PUBCFGCR2_IC3PUBC					(0x1u<<2)
#define	RCC_PUBCFGCR2_IC2PUBC					(0x1u<<1)
#define	RCC_PUBCFGCR2_IC1PUBC					(0x1u<<0)

// PRIVCFGCR3 Configuration

#define	RCC_PRIVCFGCR3_DFTPVC					(0x1u<<6)
#define	RCC_PRIVCFGCR3_RSTPVC					(0x1u<<5)
#define	RCC_PRIVCFGCR3_INTPVC					(0x1u<<4)
#define	RCC_PRIVCFGCR3_PERPVC					(0x1u<<3)
#define	RCC_PRIVCFGCR3_BUSPVC					(0x1u<<2)
#define	RCC_PRIVCFGCR3_SYSPVC					(0x1u<<1)
#define	RCC_PRIVCFGCR3_MODPVC					(0x1u<<0)

// PUBCFGCR3 Configuration

#define	RCC_PUBCFGCR3_DFTPUBC					(0x1u<<6)
#define	RCC_PUBCFGCR3_RSTPUBC					(0x1u<<5)
#define	RCC_PUBCFGCR3_INTPUBC					(0x1u<<4)
#define	RCC_PUBCFGCR3_PERPUBC					(0x1u<<3)
#define	RCC_PUBCFGCR3_BUSPUBC					(0x1u<<2)
#define	RCC_PUBCFGCR3_SYSPUBC					(0x1u<<1)
#define	RCC_PUBCFGCR3_MODPUBC					(0x1u<<0)

// PRIVCFGCR4 Configuration

#define	RCC_PRIVCFGCR4_NOCPVC					(0x1u<<13)
#define	RCC_PRIVCFGCR4_APB5PVC					(0x1u<<12)
#define	RCC_PRIVCFGCR4_APB4PVC					(0x1u<<11)
#define	RCC_PRIVCFGCR4_APB3PVC					(0x1u<<10)
#define	RCC_PRIVCFGCR4_APB2PVC					(0x1u<<9)
#define	RCC_PRIVCFGCR4_APB1PVC					(0x1u<<8)
#define	RCC_PRIVCFGCR4_AHB5PVC					(0x1u<<7)
#define	RCC_PRIVCFGCR4_AHB4PVC					(0x1u<<6)
#define	RCC_PRIVCFGCR4_AHB3PVC					(0x1u<<5)
#define	RCC_PRIVCFGCR4_AHB2PVC					(0x1u<<4)
#define	RCC_PRIVCFGCR4_AHB1PVC					(0x1u<<3)
#define	RCC_PRIVCFGCR4_AHBMPVC					(0x1u<<2)
#define	RCC_PRIVCFGCR4_ACLKNCPVC				(0x1u<<1)
#define	RCC_PRIVCFGCR4_ACLKNPVC					(0x1u<<0)

// PUBCFGCR4 Configuration

#define	RCC_PUBCFGCR4_NOCPUBC					(0x1u<<13)
#define	RCC_PUBCFGCR4_APB5PUBC					(0x1u<<12)
#define	RCC_PUBCFGCR4_APB4PUBC					(0x1u<<11)
#define	RCC_PUBCFGCR4_APB3PUBC					(0x1u<<10)
#define	RCC_PUBCFGCR4_APB2PUBC					(0x1u<<9)
#define	RCC_PUBCFGCR4_APB1PUBC					(0x1u<<8)
#define	RCC_PUBCFGCR4_AHB5PUBC					(0x1u<<7)
#define	RCC_PUBCFGCR4_AHB4PUBC					(0x1u<<6)
#define	RCC_PUBCFGCR4_AHB3PUBC					(0x1u<<5)
#define	RCC_PUBCFGCR4_AHB2PUBC					(0x1u<<4)
#define	RCC_PUBCFGCR4_AHB1PUBC					(0x1u<<3)
#define	RCC_PUBCFGCR4_AHBMPUBC					(0x1u<<2)
#define	RCC_PUBCFGCR4_ACLKNCPUBC				(0x1u<<1)
#define	RCC_PUBCFGCR4_ACLKNPUBC					(0x1u<<0)

// PUBCFGCR5 Configuration

#define	RCC_PUBCFGCR5_VENCRAMPUBC				(0x1u<<11)
#define	RCC_PUBCFGCR5_CACHEAXIRAMPUBC			(0x1u<<10)
#define	RCC_PUBCFGCR5_FLEXRAMPUBC				(0x1u<<9)
#define	RCC_PUBCFGCR5_AXISRAM2PUBC				(0x1u<<8)
#define	RCC_PUBCFGCR5_AXISRAM1PUBC				(0x1u<<7)
#define	RCC_PUBCFGCR5_BKPSRAMPUBC				(0x1u<<6)
#define	RCC_PUBCFGCR5_AHBSRAM2PUBC				(0x1u<<5)
#define	RCC_PUBCFGCR5_AHBSRAM1PUBC				(0x1u<<4)
#define	RCC_PUBCFGCR5_AXISRAM6PUBC				(0x1u<<3)
#define	RCC_PUBCFGCR5_AXISRAM5PUBC				(0x1u<<2)
#define	RCC_PUBCFGCR5_AXISRAM4PUBC				(0x1u<<1)
#define	RCC_PUBCFGCR5_AXISRAM3PUBC				(0x1u<<0)
