/*
; stm32U5Gx_gtzc1_tzsc.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_gtzc1_tzsc equates.
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

// GTZC1_TZSC address definitions
// ------------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	RESERVED0[3];
	volatile	uint32_t	SECCFGR1;
	volatile	uint32_t	SECCFGR2;
	volatile	uint32_t	SECCFGR3;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	PRIVCFGR1;
	volatile	uint32_t	PRIVCFGR2;
	volatile	uint32_t	PRIVCFGR3;
	volatile	uint32_t	RESERVED2[5];
	volatile	uint32_t	MPCWM1ACFGR;
	volatile	uint32_t	MPCWM1AR;
	volatile	uint32_t	MPCWM1BCFGR;
	volatile	uint32_t	MPCWM1BR;
	volatile	uint32_t	MPCWM2ACFGR;
	volatile	uint32_t	MPCWM2AR;
	volatile	uint32_t	MPCWM2BCFGR;
	volatile	uint32_t	MPCWM2BR;
	volatile	uint32_t	MPCWM3ACFGR;
	volatile	uint32_t	MPCWM3AR;
	volatile	uint32_t	RESERVED3[2];
	volatile	uint32_t	MPCWM4ACFGR;
	volatile	uint32_t	MPCWM4AR;
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	MPCWM5ACFGR;
	volatile	uint32_t	MPCWM5AR;
	volatile	uint32_t	MPCWM5BCFGR;
	volatile	uint32_t	MPCWM5BR;
	volatile	uint32_t	MPCWM6ACFGR;
	volatile	uint32_t	MPCWM6AR;
	volatile	uint32_t	MPCWM6BCFGR;
	volatile	uint32_t	MPCWM6BR;
} GTZC1_TZSC_TypeDef;

#if (defined(__cplusplus))
#define	GTZC1_TZSC_NS	reinterpret_cast<GTZC1_TZSC_TypeDef *>(0x40032400u)
#define	GTZC1_TZSC_S	reinterpret_cast<GTZC1_TZSC_TypeDef *>(0x50032400u)

#else
#define	GTZC1_TZSC_NS	((GTZC1_TZSC_TypeDef *)0x40032400u)
#define	GTZC1_TZSC_S	((GTZC1_TZSC_TypeDef *)0x50032400u)
#endif

// CR Configuration

#define	GTZC1_TZSC_CR_LCK						(0x1u<<0)

// SECCFGR1 Configuration

#define	GTZC1_TZSC_SECCFGR1_I2C6SEC				(0x1u<<23)
#define	GTZC1_TZSC_SECCFGR1_I2C5SEC				(0x1u<<22)
#define	GTZC1_TZSC_SECCFGR1_USART6SEC			(0x1u<<21)
#define	GTZC1_TZSC_SECCFGR1_UCPD1SEC			(0x1u<<19)
#define	GTZC1_TZSC_SECCFGR1_FDCAN1SEC			(0x1u<<18)
#define	GTZC1_TZSC_SECCFGR1_LPTIM2SEC			(0x1u<<17)
#define	GTZC1_TZSC_SECCFGR1_I2C4SEC				(0x1u<<16)
#define	GTZC1_TZSC_SECCFGR1_CRSSEC				(0x1u<<15)
#define	GTZC1_TZSC_SECCFGR1_I2C2SEC				(0x1u<<14)
#define	GTZC1_TZSC_SECCFGR1_I2C1SEC				(0x1u<<13)
#define	GTZC1_TZSC_SECCFGR1_UART5SEC			(0x1u<<12)
#define	GTZC1_TZSC_SECCFGR1_UART4SEC			(0x1u<<11)
#define	GTZC1_TZSC_SECCFGR1_USART3SEC			(0x1u<<10)
#define	GTZC1_TZSC_SECCFGR1_USART2SEC			(0x1u<<9)
#define	GTZC1_TZSC_SECCFGR1_SPI2SEC				(0x1u<<8)
#define	GTZC1_TZSC_SECCFGR1_IWDGSEC				(0x1u<<7)
#define	GTZC1_TZSC_SECCFGR1_WWDGSEC				(0x1u<<6)
#define	GTZC1_TZSC_SECCFGR1_TIM7SEC				(0x1u<<5)
#define	GTZC1_TZSC_SECCFGR1_TIM6SEC				(0x1u<<4)
#define	GTZC1_TZSC_SECCFGR1_TIM5SEC				(0x1u<<3)
#define	GTZC1_TZSC_SECCFGR1_TIM4SEC				(0x1u<<2)
#define	GTZC1_TZSC_SECCFGR1_TIM3SEC				(0x1u<<1)
#define	GTZC1_TZSC_SECCFGR1_TIM2SEC				(0x1u<<0)

// SECCFGR2 Configuration

#define	GTZC1_TZSC_SECCFGR2_DSISEC				(0x1u<<10)
#define	GTZC1_TZSC_SECCFGR2_LTDCSEC				(0x1u<<9)
#define	GTZC1_TZSC_SECCFGR2_SAI2SEC				(0x1u<<8)
#define	GTZC1_TZSC_SECCFGR2_SAI1SEC				(0x1u<<7)
#define	GTZC1_TZSC_SECCFGR2_TIM17SEC			(0x1u<<6)
#define	GTZC1_TZSC_SECCFGR2_TIM16SEC			(0x1u<<5)
#define	GTZC1_TZSC_SECCFGR2_TIM15SEC			(0x1u<<4)
#define	GTZC1_TZSC_SECCFGR2_USART1SEC			(0x1u<<3)
#define	GTZC1_TZSC_SECCFGR2_TIM8SEC				(0x1u<<2)
#define	GTZC1_TZSC_SECCFGR2_SPI1SEC				(0x1u<<1)
#define	GTZC1_TZSC_SECCFGR2_TIM1SEC				(0x1u<<0)

// SECCFGR3 Configuration

#define	GTZC1_TZSC_SECCFGR3_DCACHE2_REGSEC		(0x1u<<27)
#define	GTZC1_TZSC_SECCFGR3_HSPI1_REGSEC		(0x1u<<26)
#define	GTZC1_TZSC_SECCFGR3_GFXMMU_REGSEC		(0x1u<<25)
#define	GTZC1_TZSC_SECCFGR3_GFXMMUSEC			(0x1u<<24)
#define	GTZC1_TZSC_SECCFGR3_GPU2DSEC			(0x1u<<23)
#define	GTZC1_TZSC_SECCFGR3_RAMCFGSEC			(0x1u<<22)
#define	GTZC1_TZSC_SECCFGR3_OCTOSPI2_REGSEC		(0x1u<<21)
#define	GTZC1_TZSC_SECCFGR3_OCTOSPI1_REGSEC		(0x1u<<20)
#define	GTZC1_TZSC_SECCFGR3_FSMC_REGSEC			(0x1u<<19)
#define	GTZC1_TZSC_SECCFGR3_SDMMC2SEC			(0x1u<<18)
#define	GTZC1_TZSC_SECCFGR3_SDMMC1SEC			(0x1u<<17)
#define	GTZC1_TZSC_SECCFGR3_OCTOSPIMSEC			(0x1u<<16)
#define	GTZC1_TZSC_SECCFGR3_SAESSEC				(0x1u<<15)
#define	GTZC1_TZSC_SECCFGR3_PKASEC				(0x1u<<14)
#define	GTZC1_TZSC_SECCFGR3_RNGSEC				(0x1u<<13)
#define	GTZC1_TZSC_SECCFGR3_HASHSEC				(0x1u<<12)
#define	GTZC1_TZSC_SECCFGR3_AESSEC				(0x1u<<11)
#define	GTZC1_TZSC_SECCFGR3_OTGFSSEC			(0x1u<<10)
#define	GTZC1_TZSC_SECCFGR3_DCMISEC				(0x1u<<9)
#define	GTZC1_TZSC_SECCFGR3_ADC1SEC				(0x1u<<8)
#define	GTZC1_TZSC_SECCFGR3_DCACHE1_REGSEC		(0x1u<<7)
#define	GTZC1_TZSC_SECCFGR3_ICACHE_REGSEC		(0x1u<<6)
#define	GTZC1_TZSC_SECCFGR3_DMA2DSEC			(0x1u<<5)
#define	GTZC1_TZSC_SECCFGR3_TSCSEC				(0x1u<<4)
#define	GTZC1_TZSC_SECCFGR3_CRCSEC				(0x1u<<3)
#define	GTZC1_TZSC_SECCFGR3_FMACSEC				(0x1u<<2)
#define	GTZC1_TZSC_SECCFGR3_CORDICSEC			(0x1u<<1)
#define	GTZC1_TZSC_SECCFGR3_MDF1SEC				(0x1u<<0)

// PRIVCFGR1 Configuration

#define	GTZC1_TZSC_PRIVCFGR1_I2C6PRIV			(0x1u<<23)
#define	GTZC1_TZSC_PRIVCFGR1_I2C5PRIV			(0x1u<<22)
#define	GTZC1_TZSC_PRIVCFGR1_USART6PRIV			(0x1u<<21)
#define	GTZC1_TZSC_PRIVCFGR1_UCPD1PRIV			(0x1u<<19)
#define	GTZC1_TZSC_PRIVCFGR1_FDCAN1PRIV			(0x1u<<18)
#define	GTZC1_TZSC_PRIVCFGR1_LPTIM2PRIV			(0x1u<<17)
#define	GTZC1_TZSC_PRIVCFGR1_I2C4PRIV			(0x1u<<16)
#define	GTZC1_TZSC_PRIVCFGR1_CRSPRIV			(0x1u<<15)
#define	GTZC1_TZSC_PRIVCFGR1_I2C2PRIV			(0x1u<<14)
#define	GTZC1_TZSC_PRIVCFGR1_I2C1PRIV			(0x1u<<13)
#define	GTZC1_TZSC_PRIVCFGR1_UART5PRIV			(0x1u<<12)
#define	GTZC1_TZSC_PRIVCFGR1_UART4PRIV			(0x1u<<11)
#define	GTZC1_TZSC_PRIVCFGR1_USART3PRIV			(0x1u<<10)
#define	GTZC1_TZSC_PRIVCFGR1_USART2PRIV			(0x1u<<9)
#define	GTZC1_TZSC_PRIVCFGR1_SPI2PRIV			(0x1u<<8)
#define	GTZC1_TZSC_PRIVCFGR1_IWDGPRIV			(0x1u<<7)
#define	GTZC1_TZSC_PRIVCFGR1_WWDGPRIV			(0x1u<<6)
#define	GTZC1_TZSC_PRIVCFGR1_TIM7PRIV			(0x1u<<5)
#define	GTZC1_TZSC_PRIVCFGR1_TIM6PRIV			(0x1u<<4)
#define	GTZC1_TZSC_PRIVCFGR1_TIM5PRIV			(0x1u<<3)
#define	GTZC1_TZSC_PRIVCFGR1_TIM4PRIV			(0x1u<<2)
#define	GTZC1_TZSC_PRIVCFGR1_TIM3PRIV			(0x1u<<1)
#define	GTZC1_TZSC_PRIVCFGR1_TIM2PRIV			(0x1u<<0)

// PRIVCFGR2 Configuration

#define	GTZC1_TZSC_PRIVCFGR2_DSIPRIV			(0x1u<<10)
#define	GTZC1_TZSC_PRIVCFGR2_LTDCPRIV			(0x1u<<9)
#define	GTZC1_TZSC_PRIVCFGR2_SAI2PRIV			(0x1u<<8)
#define	GTZC1_TZSC_PRIVCFGR2_SAI1PRIV			(0x1u<<7)
#define	GTZC1_TZSC_PRIVCFGR2_TIM17PRIV			(0x1u<<6)
#define	GTZC1_TZSC_PRIVCFGR2_TIM16PRIV			(0x1u<<5)
#define	GTZC1_TZSC_PRIVCFGR2_TIM15PRIV			(0x1u<<4)
#define	GTZC1_TZSC_PRIVCFGR2_USART1PRIV			(0x1u<<3)
#define	GTZC1_TZSC_PRIVCFGR2_TIM8PRIV			(0x1u<<2)
#define	GTZC1_TZSC_PRIVCFGR2_SPI1PRIV			(0x1u<<1)
#define	GTZC1_TZSC_PRIVCFGR2_TIM1PRIV			(0x1u<<0)

// PRIVCFGR3 Configuration

#define	GTZC1_TZSC_PRIVCFGR3_DCACHE2_REGPRIV	(0x1u<<27)
#define	GTZC1_TZSC_PRIVCFGR3_HSPI1_REGPRIV		(0x1u<<26)
#define	GTZC1_TZSC_PRIVCFGR3_GFXMMU_REGPRIV		(0x1u<<25)
#define	GTZC1_TZSC_PRIVCFGR3_GFXMMUPRIV			(0x1u<<24)
#define	GTZC1_TZSC_PRIVCFGR3_GPU2DPRIV			(0x1u<<23)
#define	GTZC1_TZSC_PRIVCFGR3_RAMCFGPRIV			(0x1u<<22)
#define	GTZC1_TZSC_PRIVCFGR3_OCTOSPI2_REGPRIV	(0x1u<<21)
#define	GTZC1_TZSC_PRIVCFGR3_OCTOSPI1_REGPRIV	(0x1u<<20)
#define	GTZC1_TZSC_PRIVCFGR3_FSMC_REGPRIV		(0x1u<<19)
#define	GTZC1_TZSC_PRIVCFGR3_SDMMC2PRIV			(0x1u<<18)
#define	GTZC1_TZSC_PRIVCFGR3_SDMMC1PRIV			(0x1u<<17)
#define	GTZC1_TZSC_PRIVCFGR3_OCTOSPIMPRIV		(0x1u<<16)
#define	GTZC1_TZSC_PRIVCFGR3_SAESPRIV			(0x1u<<15)
#define	GTZC1_TZSC_PRIVCFGR3_PKAPRIV			(0x1u<<14)
#define	GTZC1_TZSC_PRIVCFGR3_RNGPRIV			(0x1u<<13)
#define	GTZC1_TZSC_PRIVCFGR3_HASHPRIV			(0x1u<<12)
#define	GTZC1_TZSC_PRIVCFGR3_AESPRIV			(0x1u<<11)
#define	GTZC1_TZSC_PRIVCFGR3_OTGFSPRIV			(0x1u<<10)
#define	GTZC1_TZSC_PRIVCFGR3_DCMIPRIV			(0x1u<<9)
#define	GTZC1_TZSC_PRIVCFGR3_ADC1PRIV			(0x1u<<8)
#define	GTZC1_TZSC_PRIVCFGR3_DCACHE1_REGPRIV	(0x1u<<7)
#define	GTZC1_TZSC_PRIVCFGR3_ICACHE_REGPRIV		(0x1u<<6)
#define	GTZC1_TZSC_PRIVCFGR3_DMA2DPRIV			(0x1u<<5)
#define	GTZC1_TZSC_PRIVCFGR3_TSCPRIV			(0x1u<<4)
#define	GTZC1_TZSC_PRIVCFGR3_CRCPRIV			(0x1u<<3)
#define	GTZC1_TZSC_PRIVCFGR3_FMACPRIV			(0x1u<<2)
#define	GTZC1_TZSC_PRIVCFGR3_CORDICPRIV			(0x1u<<1)
#define	GTZC1_TZSC_PRIVCFGR3_MDF1PRIV			(0x1u<<0)

// MPCWM1ACFGR Configuration

#define	GTZC1_TZSC_MPCWM1ACFGR_PRIV				(0x1u<<9)
#define	GTZC1_TZSC_MPCWM1ACFGR_SEC				(0x1u<<8)
#define	GTZC1_TZSC_MPCWM1ACFGR_SRLOCK			(0x1u<<1)
#define	GTZC1_TZSC_MPCWM1ACFGR_SREN				(0x1u<<0)

// MPCWM1AR Configuration

#define	GTZC1_TZSC_MPCWM1AR_SUBA_LENGTH			(0xFFFu<<16)
#define	GTZC1_TZSC_MPCWM1AR_SUBA_LENGTH_0		(0x1u<<16)
#define	GTZC1_TZSC_MPCWM1AR_SUBA_START			(0x7FFu<<0)
#define	GTZC1_TZSC_MPCWM1AR_SUBA_START_0		(0x1u<<0)

// MPCWM1BCFGR Configuration

#define	GTZC1_TZSC_MPCWM1BCFGR_PRIV				(0x1u<<9)
#define	GTZC1_TZSC_MPCWM1BCFGR_SEC				(0x1u<<8)
#define	GTZC1_TZSC_MPCWM1BCFGR_SRLOCK			(0x1u<<1)
#define	GTZC1_TZSC_MPCWM1BCFGR_SREN				(0x1u<<0)

// MPCWM1BR Configuration

#define	GTZC1_TZSC_MPCWM1BR_SUBB_LENGTH			(0xFFFu<<16)
#define	GTZC1_TZSC_MPCWM1BR_SUBB_LENGTH_0		(0x1u<<16)
#define	GTZC1_TZSC_MPCWM1BR_SUBB_START			(0x7FFu<<0)
#define	GTZC1_TZSC_MPCWM1BR_SUBB_START_0		(0x1u<<0)

// MPCWM2ACFGR Configuration

#define	GTZC1_TZSC_MPCWM2ACFGR_PRIV				(0x1u<<9)
#define	GTZC1_TZSC_MPCWM2ACFGR_SEC				(0x1u<<8)
#define	GTZC1_TZSC_MPCWM2ACFGR_SRLOCK			(0x1u<<1)
#define	GTZC1_TZSC_MPCWM2ACFGR_SREN				(0x1u<<0)

// MPCWM2AR Configuration

#define	GTZC1_TZSC_MPCWM2AR_SUBA_LENGTH			(0xFFFu<<16)
#define	GTZC1_TZSC_MPCWM2AR_SUBA_LENGTH_0		(0x1u<<16)
#define	GTZC1_TZSC_MPCWM2AR_SUBA_START			(0x7FFu<<0)
#define	GTZC1_TZSC_MPCWM2AR_SUBA_START_0		(0x1u<<0)

// MPCWM2BCFGR Configuration

#define	GTZC1_TZSC_MPCWM2BCFGR_PRIV				(0x1u<<9)
#define	GTZC1_TZSC_MPCWM2BCFGR_SEC				(0x1u<<8)
#define	GTZC1_TZSC_MPCWM2BCFGR_SRLOCK			(0x1u<<1)
#define	GTZC1_TZSC_MPCWM2BCFGR_SREN				(0x1u<<0)

// MPCWM2BR Configuration

#define	GTZC1_TZSC_MPCWM2BR_SUBB_LENGTH			(0xFFFu<<16)
#define	GTZC1_TZSC_MPCWM2BR_SUBB_LENGTH_0		(0x1u<<16)
#define	GTZC1_TZSC_MPCWM2BR_SUBB_START			(0x7FFu<<0)
#define	GTZC1_TZSC_MPCWM2BR_SUBB_START_0		(0x1u<<0)

// MPCWM3ACFGR Configuration

#define	GTZC1_TZSC_MPCWM3ACFGR_PRIV				(0x1u<<9)
#define	GTZC1_TZSC_MPCWM3ACFGR_SEC				(0x1u<<8)
#define	GTZC1_TZSC_MPCWM3ACFGR_SRLOCK			(0x1u<<1)
#define	GTZC1_TZSC_MPCWM3ACFGR_SREN				(0x1u<<0)

// MPCWM3AR Configuration

#define	GTZC1_TZSC_MPCWM3AR_SUBA_LENGTH			(0xFFFu<<16)
#define	GTZC1_TZSC_MPCWM3AR_SUBA_LENGTH_0		(0x1u<<16)
#define	GTZC1_TZSC_MPCWM3AR_SUBA_START			(0x7FFu<<0)
#define	GTZC1_TZSC_MPCWM3AR_SUBA_START_0		(0x1u<<0)

// MPCWM4ACFGR Configuration

#define	GTZC1_TZSC_MPCWM4ACFGR_PRIV				(0x1u<<9)
#define	GTZC1_TZSC_MPCWM4ACFGR_SEC				(0x1u<<8)
#define	GTZC1_TZSC_MPCWM4ACFGR_SRLOCK			(0x1u<<1)
#define	GTZC1_TZSC_MPCWM4ACFGR_SREN				(0x1u<<0)

// MPCWM4AR Configuration

#define	GTZC1_TZSC_MPCWM4AR_SUBA_LENGTH			(0xFFFu<<16)
#define	GTZC1_TZSC_MPCWM4AR_SUBA_LENGTH_0		(0x1u<<16)
#define	GTZC1_TZSC_MPCWM4AR_SUBA_START			(0x7FFu<<0)
#define	GTZC1_TZSC_MPCWM4AR_SUBA_START_0		(0x1u<<0)

// MPCWM5ACFGR Configuration

#define	GTZC1_TZSC_MPCWM5ACFGR_PRIV				(0x1u<<9)
#define	GTZC1_TZSC_MPCWM5ACFGR_SEC				(0x1u<<8)
#define	GTZC1_TZSC_MPCWM5ACFGR_SRLOCK			(0x1u<<1)
#define	GTZC1_TZSC_MPCWM5ACFGR_SREN				(0x1u<<0)

// MPCWM5AR Configuration

#define	GTZC1_TZSC_MPCWM5AR_SUBA_LENGTH			(0xFFFu<<16)
#define	GTZC1_TZSC_MPCWM5AR_SUBA_LENGTH_0		(0x1u<<16)
#define	GTZC1_TZSC_MPCWM5AR_SUBA_START			(0x7FFu<<0)
#define	GTZC1_TZSC_MPCWM5AR_SUBA_START_0		(0x1u<<0)

// MPCWM5BCFGR Configuration

#define	GTZC1_TZSC_MPCWM5BCFGR_PRIV				(0x1u<<9)
#define	GTZC1_TZSC_MPCWM5BCFGR_SEC				(0x1u<<8)
#define	GTZC1_TZSC_MPCWM5BCFGR_SRLOCK			(0x1u<<1)
#define	GTZC1_TZSC_MPCWM5BCFGR_SREN				(0x1u<<0)

// MPCWM5BR Configuration

#define	GTZC1_TZSC_MPCWM5BR_SUBB_LENGTH			(0xFFFu<<16)
#define	GTZC1_TZSC_MPCWM5BR_SUBB_LENGTH_0		(0x1u<<16)
#define	GTZC1_TZSC_MPCWM5BR_SUBB_START			(0x7FFu<<0)
#define	GTZC1_TZSC_MPCWM5BR_SUBB_START_0		(0x1u<<0)

// MPCWM6ACFGR Configuration

#define	GTZC1_TZSC_MPCWM6ACFGR_PRIV				(0x1u<<9)
#define	GTZC1_TZSC_MPCWM6ACFGR_SEC				(0x1u<<8)
#define	GTZC1_TZSC_MPCWM6ACFGR_SRLOCK			(0x1u<<1)
#define	GTZC1_TZSC_MPCWM6ACFGR_SREN				(0x1u<<0)

// MPCWM6AR Configuration

#define	GTZC1_TZSC_MPCWM6AR_SUBA_LENGTH			(0xFFFu<<16)
#define	GTZC1_TZSC_MPCWM6AR_SUBA_LENGTH_0		(0x1u<<16)
#define	GTZC1_TZSC_MPCWM6AR_SUBA_START			(0x7FFu<<0)
#define	GTZC1_TZSC_MPCWM6AR_SUBA_START_0		(0x1u<<0)

// MPCWM6BCFGR Configuration

#define	GTZC1_TZSC_MPCWM6BCFGR_PRIV				(0x1u<<9)
#define	GTZC1_TZSC_MPCWM6BCFGR_SEC				(0x1u<<8)
#define	GTZC1_TZSC_MPCWM6BCFGR_SRLOCK			(0x1u<<1)
#define	GTZC1_TZSC_MPCWM6BCFGR_SREN				(0x1u<<0)

// MPCWM6BR Configuration

#define	GTZC1_TZSC_MPCWM6BR_SUBB_LENGTH			(0xFFFu<<16)
#define	GTZC1_TZSC_MPCWM6BR_SUBB_LENGTH_0		(0x1u<<16)
#define	GTZC1_TZSC_MPCWM6BR_SUBB_START			(0x7FFu<<0)
#define	GTZC1_TZSC_MPCWM6BR_SUBB_START_0		(0x1u<<0)
