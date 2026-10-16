/*
; stm32U5Gx_gtzc1_tzic.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_gtzc1_tzic equates.
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

// GTZC1_TZIC address definitions
// ------------------------------

typedef struct {
	volatile	uint32_t	IER1;
	volatile	uint32_t	IER2;
	volatile	uint32_t	IER3;
	volatile	uint32_t	IER4;
	volatile	uint32_t	SR1;
	volatile	uint32_t	SR2;
	volatile	uint32_t	SR3;
	volatile	uint32_t	SR4;
	volatile	uint32_t	FCR1;
	volatile	uint32_t	FCR2;
	volatile	uint32_t	FCR3;
	volatile	uint32_t	FCR4;
} GTZC1_TZIC_TypeDef;

#if (defined(__cplusplus))
#define	GTZC1_TZIC_NS	reinterpret_cast<GTZC1_TZIC_TypeDef *>(0x40032800u)
#define	GTZC1_TZIC_S	reinterpret_cast<GTZC1_TZIC_TypeDef *>(0x50032800u)

#else
#define	GTZC1_TZIC_NS	((GTZC1_TZIC_TypeDef *)0x40032800u)
#define	GTZC1_TZIC_S	((GTZC1_TZIC_TypeDef *)0x50032800u)
#endif

// IER1 Configuration

#define	GTZC1_TZIC_IER1_I2C6IE			(0x1u<<23)
#define	GTZC1_TZIC_IER1_I2C5IE			(0x1u<<22)
#define	GTZC1_TZIC_IER1_USART6IE		(0x1u<<21)
#define	GTZC1_TZIC_IER1_UCPD1IE			(0x1u<<19)
#define	GTZC1_TZIC_IER1_FDCAN1IE		(0x1u<<18)
#define	GTZC1_TZIC_IER1_LPTIM2IE		(0x1u<<17)
#define	GTZC1_TZIC_IER1_I2C4IE			(0x1u<<16)
#define	GTZC1_TZIC_IER1_CRSIE			(0x1u<<15)
#define	GTZC1_TZIC_IER1_I2C2IE			(0x1u<<14)
#define	GTZC1_TZIC_IER1_I2C1IE			(0x1u<<13)
#define	GTZC1_TZIC_IER1_UART5IE			(0x1u<<12)
#define	GTZC1_TZIC_IER1_USART4IE		(0x1u<<11)
#define	GTZC1_TZIC_IER1_USART3IE		(0x1u<<10)
#define	GTZC1_TZIC_IER1_USART2IE		(0x1u<<9)
#define	GTZC1_TZIC_IER1_SPI2IE			(0x1u<<8)
#define	GTZC1_TZIC_IER1_IWDGIE			(0x1u<<7)
#define	GTZC1_TZIC_IER1_WWDGIE			(0x1u<<6)
#define	GTZC1_TZIC_IER1_TIM7IE			(0x1u<<5)
#define	GTZC1_TZIC_IER1_TIM6IE			(0x1u<<4)
#define	GTZC1_TZIC_IER1_TIM5IE			(0x1u<<3)
#define	GTZC1_TZIC_IER1_TIM4IE			(0x1u<<2)
#define	GTZC1_TZIC_IER1_TIM3IE			(0x1u<<1)
#define	GTZC1_TZIC_IER1_TIM2IE			(0x1u<<0)

// IER2 Configuration

#define	GTZC1_TZIC_IER2_DSIIE			(0x1u<<10)
#define	GTZC1_TZIC_IER2_LTDCIE			(0x1u<<9)
#define	GTZC1_TZIC_IER2_SAI2IE			(0x1u<<8)
#define	GTZC1_TZIC_IER2_SAI1IE			(0x1u<<7)
#define	GTZC1_TZIC_IER2_TIM17IE			(0x1u<<6)
#define	GTZC1_TZIC_IER2_TIM16IE			(0x1u<<5)
#define	GTZC1_TZIC_IER2_TIM15IE			(0x1u<<4)
#define	GTZC1_TZIC_IER2_USART1IE		(0x1u<<3)
#define	GTZC1_TZIC_IER2_TIM8IE			(0x1u<<2)
#define	GTZC1_TZIC_IER2_SPI1IE			(0x1u<<1)
#define	GTZC1_TZIC_IER2_TIM1IE			(0x1u<<0)

// IER3 Configuration

#define	GTZC1_TZIC_IER3_DCACHE2_REGIE	(0x1u<<27)
#define	GTZC1_TZIC_IER3_HSPI1_REGIE		(0x1u<<26)
#define	GTZC1_TZIC_IER3_GFXMMU_REGIE	(0x1u<<25)
#define	GTZC1_TZIC_IER3_GFXMMUIE		(0x1u<<24)
#define	GTZC1_TZIC_IER3_GPU2DIE			(0x1u<<23)
#define	GTZC1_TZIC_IER3_RAMCFGIE		(0x1u<<22)
#define	GTZC1_TZIC_IER3_OCTOSPI2_REGIE	(0x1u<<21)
#define	GTZC1_TZIC_IER3_OCTOSPI1_REGIE	(0x1u<<20)
#define	GTZC1_TZIC_IER3_FSMC_REGIE		(0x1u<<19)
#define	GTZC1_TZIC_IER3_SDMMC2IE		(0x1u<<18)
#define	GTZC1_TZIC_IER3_SDMMC1IE		(0x1u<<17)
#define	GTZC1_TZIC_IER3_OCTOSPIMIE		(0x1u<<16)
#define	GTZC1_TZIC_IER3_SAESIE			(0x1u<<15)
#define	GTZC1_TZIC_IER3_PKAIE			(0x1u<<14)
#define	GTZC1_TZIC_IER3_RNGIE			(0x1u<<13)
#define	GTZC1_TZIC_IER3_HASHIE			(0x1u<<12)
#define	GTZC1_TZIC_IER3_AESIE			(0x1u<<11)
#define	GTZC1_TZIC_IER3_OTGIE			(0x1u<<10)
#define	GTZC1_TZIC_IER3_DCMIIE			(0x1u<<9)
#define	GTZC1_TZIC_IER3_ADC1I2E			(0x1u<<8)
#define	GTZC1_TZIC_IER3_DCACHE1_REGIE	(0x1u<<7)
#define	GTZC1_TZIC_IER3_ICACHE_REGIE	(0x1u<<6)
#define	GTZC1_TZIC_IER3_DMA2DIE			(0x1u<<5)
#define	GTZC1_TZIC_IER3_TSCIE			(0x1u<<4)
#define	GTZC1_TZIC_IER3_CRCIE			(0x1u<<3)
#define	GTZC1_TZIC_IER3_FMACIE			(0x1u<<2)
#define	GTZC1_TZIC_IER3_CORDICIE		(0x1u<<1)
#define	GTZC1_TZIC_IER3_MDF1IE			(0x1u<<0)

// IER4 Configuration

#define	GTZC1_TZIC_IER4_MPCBB5_REGIE	(0x1u<<31)
#define	GTZC1_TZIC_IER4_SRAM5IE			(0x1u<<30)
#define	GTZC1_TZIC_IER4_MPCBB3_REGIE	(0x1u<<29)
#define	GTZC1_TZIC_IER4_SRAM3IE			(0x1u<<28)
#define	GTZC1_TZIC_IER4_MPCBB2_REGIE	(0x1u<<27)
#define	GTZC1_TZIC_IER4_SRAM2IE			(0x1u<<26)
#define	GTZC1_TZIC_IER4_MPCBB1_REGIE	(0x1u<<25)
#define	GTZC1_TZIC_IER4_SRAM1IE			(0x1u<<24)
#define	GTZC1_TZIC_IER4_HSPI1_MEMIE		(0x1u<<20)
#define	GTZC1_TZIC_IER4_OCTOSPI2_MEMIE	(0x1u<<19)
#define	GTZC1_TZIC_IER4_BKPSRAMIE		(0x1u<<18)
#define	GTZC1_TZIC_IER4_FSMC_MEMIE		(0x1u<<17)
#define	GTZC1_TZIC_IER4_OCTOSPI1_MEMIE	(0x1u<<16)
#define	GTZC1_TZIC_IER4_TZIC1IE			(0x1u<<15)
#define	GTZC1_TZIC_IER4_TZSC1IE			(0x1u<<14)
#define	GTZC1_TZIC_IER4_OTFDEC2IE		(0x1u<<4)
#define	GTZC1_TZIC_IER4_OTFDEC1IE		(0x1u<<3)
#define	GTZC1_TZIC_IER4_FLASHIE			(0x1u<<2)
#define	GTZC1_TZIC_IER4_FLASH_REGIE		(0x1u<<1)
#define	GTZC1_TZIC_IER4_GPDMA1IE		(0x1u<<0)

// SR1 Configuration

#define	GTZC1_TZIC_SR1_I2C6F			(0x1u<<23)
#define	GTZC1_TZIC_SR1_I2C5F			(0x1u<<22)
#define	GTZC1_TZIC_SR1_USART6F			(0x1u<<21)
#define	GTZC1_TZIC_SR1_UCPD1F			(0x1u<<19)
#define	GTZC1_TZIC_SR1_FDCAN1F			(0x1u<<18)
#define	GTZC1_TZIC_SR1_LPTIM2F			(0x1u<<17)
#define	GTZC1_TZIC_SR1_I2C4F			(0x1u<<16)
#define	GTZC1_TZIC_SR1_CRSF				(0x1u<<15)
#define	GTZC1_TZIC_SR1_I2C2F			(0x1u<<14)
#define	GTZC1_TZIC_SR1_I2C1F			(0x1u<<13)
#define	GTZC1_TZIC_SR1_UART5F			(0x1u<<12)
#define	GTZC1_TZIC_SR1_UART4F			(0x1u<<11)
#define	GTZC1_TZIC_SR1_USART3F			(0x1u<<10)
#define	GTZC1_TZIC_SR1_USART2F			(0x1u<<9)
#define	GTZC1_TZIC_SR1_SPI2F			(0x1u<<8)
#define	GTZC1_TZIC_SR1_IWDGF			(0x1u<<7)
#define	GTZC1_TZIC_SR1_WWDGF			(0x1u<<6)
#define	GTZC1_TZIC_SR1_TIM7F			(0x1u<<5)
#define	GTZC1_TZIC_SR1_TIM6F			(0x1u<<4)
#define	GTZC1_TZIC_SR1_TIM5F			(0x1u<<3)
#define	GTZC1_TZIC_SR1_TIM4F			(0x1u<<2)
#define	GTZC1_TZIC_SR1_TIM3F			(0x1u<<1)
#define	GTZC1_TZIC_SR1_TIM2F			(0x1u<<0)

// SR2 Configuration

#define	GTZC1_TZIC_SR2_DSIF				(0x1u<<10)
#define	GTZC1_TZIC_SR2_LTDCF			(0x1u<<9)
#define	GTZC1_TZIC_SR2_SAI2F			(0x1u<<8)
#define	GTZC1_TZIC_SR2_SAI1F			(0x1u<<7)
#define	GTZC1_TZIC_SR2_TIM17F			(0x1u<<6)
#define	GTZC1_TZIC_SR2_TIM16F			(0x1u<<5)
#define	GTZC1_TZIC_SR2_TIM15F			(0x1u<<4)
#define	GTZC1_TZIC_SR2_USART1F			(0x1u<<3)
#define	GTZC1_TZIC_SR2_TIM8F			(0x1u<<2)
#define	GTZC1_TZIC_SR2_SPI1F			(0x1u<<1)
#define	GTZC1_TZIC_SR2_TIM1F			(0x1u<<0)

// SR3 Configuration

#define	GTZC1_TZIC_SR3_DCACHE2_REGF		(0x1u<<27)
#define	GTZC1_TZIC_SR3_HSPI1_REGF		(0x1u<<26)
#define	GTZC1_TZIC_SR3_GFXMMU_REGF		(0x1u<<25)
#define	GTZC1_TZIC_SR3_GFXMMUF			(0x1u<<24)
#define	GTZC1_TZIC_SR3_GPU2DF			(0x1u<<23)
#define	GTZC1_TZIC_SR3_RAMCFGF			(0x1u<<22)
#define	GTZC1_TZIC_SR3_OCTOSPI2_REGF	(0x1u<<21)
#define	GTZC1_TZIC_SR3_OCTOSPI1_REGF	(0x1u<<20)
#define	GTZC1_TZIC_SR3_FSMC_REGF		(0x1u<<19)
#define	GTZC1_TZIC_SR3_SDMMC2F			(0x1u<<18)
#define	GTZC1_TZIC_SR3_SDMMC1F			(0x1u<<17)
#define	GTZC1_TZIC_SR3_OCTOSPIMF		(0x1u<<16)
#define	GTZC1_TZIC_SR3_SAESF			(0x1u<<15)
#define	GTZC1_TZIC_SR3_PKAF				(0x1u<<14)
#define	GTZC1_TZIC_SR3_RNGF				(0x1u<<13)
#define	GTZC1_TZIC_SR3_HASHF			(0x1u<<12)
#define	GTZC1_TZIC_SR3_AESF				(0x1u<<11)
#define	GTZC1_TZIC_SR3_OTGF				(0x1u<<10)
#define	GTZC1_TZIC_SR3_DCMIF			(0x1u<<9)
#define	GTZC1_TZIC_SR3_ADC12F			(0x1u<<8)
#define	GTZC1_TZIC_SR3_DCACHE1_REGF		(0x1u<<7)
#define	GTZC1_TZIC_SR3_ICACHE_REGF		(0x1u<<6)
#define	GTZC1_TZIC_SR3_DMA2DF			(0x1u<<5)
#define	GTZC1_TZIC_SR3_TSCF				(0x1u<<4)
#define	GTZC1_TZIC_SR3_CRCF				(0x1u<<3)
#define	GTZC1_TZIC_SR3_FMACF			(0x1u<<2)
#define	GTZC1_TZIC_SR3_CORDICF			(0x1u<<1)
#define	GTZC1_TZIC_SR3_MDF1F			(0x1u<<0)

// SR4 Configuration

#define	GTZC1_TZIC_SR4_MPCBB5_REGF		(0x1u<<31)
#define	GTZC1_TZIC_SR4_SRAM5F			(0x1u<<30)
#define	GTZC1_TZIC_SR4_MPCBB3_REGF		(0x1u<<29)
#define	GTZC1_TZIC_SR4_SRAM3F			(0x1u<<28)
#define	GTZC1_TZIC_SR4_MPCBB2_REGF		(0x1u<<27)
#define	GTZC1_TZIC_SR4_SRAM2F			(0x1u<<26)
#define	GTZC1_TZIC_SR4_MPCBB1_REGF		(0x1u<<25)
#define	GTZC1_TZIC_SR4_SRAM1F			(0x1u<<24)
#define	GTZC1_TZIC_SR4_HSPI1_MEMF		(0x1u<<20)
#define	GTZC1_TZIC_SR4_OCTOSPI2_MEMF	(0x1u<<19)
#define	GTZC1_TZIC_SR4_BKPSRAMF			(0x1u<<18)
#define	GTZC1_TZIC_SR4_FSMC_MEMF		(0x1u<<17)
#define	GTZC1_TZIC_SR4_OCTOSPI1_MEMF	(0x1u<<16)
#define	GTZC1_TZIC_SR4_TZIC1F			(0x1u<<15)
#define	GTZC1_TZIC_SR4_TZSC1F			(0x1u<<14)
#define	GTZC1_TZIC_SR4_OTFDEC2F			(0x1u<<4)
#define	GTZC1_TZIC_SR4_OTFDEC1F			(0x1u<<3)
#define	GTZC1_TZIC_SR4_FLASHF			(0x1u<<2)
#define	GTZC1_TZIC_SR4_FLASH_REGF		(0x1u<<1)
#define	GTZC1_TZIC_SR4_GPDMA1F			(0x1u<<0)

// FCR1 Configuration

#define	GTZC1_TZIC_FCR1_CI2C6F			(0x1u<<23)
#define	GTZC1_TZIC_FCR1_CI2C5F			(0x1u<<22)
#define	GTZC1_TZIC_FCR1_CUSART6F		(0x1u<<21)
#define	GTZC1_TZIC_FCR1_CUCPD1F			(0x1u<<19)
#define	GTZC1_TZIC_FCR1_CFDCAN1F		(0x1u<<18)
#define	GTZC1_TZIC_FCR1_CLPTIM2F		(0x1u<<17)
#define	GTZC1_TZIC_FCR1_CI2C4F			(0x1u<<16)
#define	GTZC1_TZIC_FCR1_CCRSF			(0x1u<<15)
#define	GTZC1_TZIC_FCR1_CI2C2F			(0x1u<<14)
#define	GTZC1_TZIC_FCR1_CI2C1F			(0x1u<<13)
#define	GTZC1_TZIC_FCR1_CUART5F			(0x1u<<12)
#define	GTZC1_TZIC_FCR1_CUART4F			(0x1u<<11)
#define	GTZC1_TZIC_FCR1_CUSART3F		(0x1u<<10)
#define	GTZC1_TZIC_FCR1_CUSART2F		(0x1u<<9)
#define	GTZC1_TZIC_FCR1_CSPI2F			(0x1u<<8)
#define	GTZC1_TZIC_FCR1_CIWDGF			(0x1u<<7)
#define	GTZC1_TZIC_FCR1_CWWDGF			(0x1u<<6)
#define	GTZC1_TZIC_FCR1_CTIM7F			(0x1u<<5)
#define	GTZC1_TZIC_FCR1_CTIM6F			(0x1u<<4)
#define	GTZC1_TZIC_FCR1_CTIM5F			(0x1u<<3)
#define	GTZC1_TZIC_FCR1_CTIM4F			(0x1u<<2)
#define	GTZC1_TZIC_FCR1_CTIM3F			(0x1u<<1)
#define	GTZC1_TZIC_FCR1_CTIM2F			(0x1u<<0)

// FCR2 Configuration

#define	GTZC1_TZIC_FCR2_CDSIF			(0x1u<<10)
#define	GTZC1_TZIC_FCR2_CLTDCF			(0x1u<<9)
#define	GTZC1_TZIC_FCR2_CSAI2F			(0x1u<<8)
#define	GTZC1_TZIC_FCR2_CSAI1F			(0x1u<<7)
#define	GTZC1_TZIC_FCR2_CTIM17F			(0x1u<<6)
#define	GTZC1_TZIC_FCR2_CTIM16F			(0x1u<<5)
#define	GTZC1_TZIC_FCR2_CTIM15F			(0x1u<<4)
#define	GTZC1_TZIC_FCR2_CUSART1F		(0x1u<<3)
#define	GTZC1_TZIC_FCR2_CTIM8F			(0x1u<<2)
#define	GTZC1_TZIC_FCR2_CSPI1F			(0x1u<<1)
#define	GTZC1_TZIC_FCR2_CTIM1F			(0x1u<<0)

// FCR3 Configuration

#define	GTZC1_TZIC_FCR3_CDCACHE2_REGF	(0x1u<<27)
#define	GTZC1_TZIC_FCR3_CHSPI1_REGF		(0x1u<<26)
#define	GTZC1_TZIC_FCR3_CGFXMMU_REGF	(0x1u<<25)
#define	GTZC1_TZIC_FCR3_CGFXMMUF		(0x1u<<24)
#define	GTZC1_TZIC_FCR3_CGPU2DF			(0x1u<<23)
#define	GTZC1_TZIC_FCR3_CRAMCFGF		(0x1u<<22)
#define	GTZC1_TZIC_FCR3_COCTOSPI2_REGF	(0x1u<<21)
#define	GTZC1_TZIC_FCR3_COCTOSPI1_REGF	(0x1u<<20)
#define	GTZC1_TZIC_FCR3_CFSMC_REGF		(0x1u<<19)
#define	GTZC1_TZIC_FCR3_CSDMMC2F		(0x1u<<18)
#define	GTZC1_TZIC_FCR3_CSDMMC1F		(0x1u<<17)
#define	GTZC1_TZIC_FCR3_COCTOSPIMF		(0x1u<<16)
#define	GTZC1_TZIC_FCR3_CSAESF			(0x1u<<15)
#define	GTZC1_TZIC_FCR3_CPKAF			(0x1u<<14)
#define	GTZC1_TZIC_FCR3_CRNGF			(0x1u<<13)
#define	GTZC1_TZIC_FCR3_CHASHF			(0x1u<<12)
#define	GTZC1_TZIC_FCR3_CAESF			(0x1u<<11)
#define	GTZC1_TZIC_FCR3_COTGF			(0x1u<<10)
#define	GTZC1_TZIC_FCR3_CDCMIF			(0x1u<<9)
#define	GTZC1_TZIC_FCR3_CADC12F			(0x1u<<8)
#define	GTZC1_TZIC_FCR3_CDCACHE1_REGF	(0x1u<<7)
#define	GTZC1_TZIC_FCR3_CICACHE_REGF	(0x1u<<6)
#define	GTZC1_TZIC_FCR3_CDMA2DF			(0x1u<<5)
#define	GTZC1_TZIC_FCR3_CTSCF			(0x1u<<4)
#define	GTZC1_TZIC_FCR3_CCRCF			(0x1u<<3)
#define	GTZC1_TZIC_FCR3_CFMACF			(0x1u<<2)
#define	GTZC1_TZIC_FCR3_CCORDICF		(0x1u<<1)
#define	GTZC1_TZIC_FCR3_CMDF1F			(0x1u<<0)

// FCR4 Configuration

#define	GTZC1_TZIC_FCR4_CMPCBB5_REGF	(0x1u<<31)
#define	GTZC1_TZIC_FCR4_CSRAM5F			(0x1u<<30)
#define	GTZC1_TZIC_FCR4_CMPCBB3_REGF	(0x1u<<29)
#define	GTZC1_TZIC_FCR4_CSRAM3F			(0x1u<<28)
#define	GTZC1_TZIC_FCR4_CMPCBB2_REGF	(0x1u<<27)
#define	GTZC1_TZIC_FCR4_CSRAM2F			(0x1u<<26)
#define	GTZC1_TZIC_FCR4_CMPCBB1_REGF	(0x1u<<25)
#define	GTZC1_TZIC_FCR4_CSRAM1F			(0x1u<<24)
#define	GTZC1_TZIC_FCR4_CHSPI1_MEMF		(0x1u<<20)
#define	GTZC1_TZIC_FCR4_COCTOSPI2_MEMF	(0x1u<<19)
#define	GTZC1_TZIC_FCR4_CBKPSRAMF		(0x1u<<18)
#define	GTZC1_TZIC_FCR4_CFSMC_MEMF		(0x1u<<17)
#define	GTZC1_TZIC_FCR4_COCTOSPI1_MEMF	(0x1u<<16)
#define	GTZC1_TZIC_FCR4_CTZIC1F			(0x1u<<15)
#define	GTZC1_TZIC_FCR4_CTZSC1F			(0x1u<<14)
#define	GTZC1_TZIC_FCR4_COTFDEC2F		(0x1u<<4)
#define	GTZC1_TZIC_FCR4_COTFDEC1F		(0x1u<<3)
#define	GTZC1_TZIC_FCR4_CFLASHF			(0x1u<<2)
#define	GTZC1_TZIC_FCR4_CFLASH_REGF		(0x1u<<1)
#define	GTZC1_TZIC_FCR4_CGPDMA1F		(0x1u<<0)
