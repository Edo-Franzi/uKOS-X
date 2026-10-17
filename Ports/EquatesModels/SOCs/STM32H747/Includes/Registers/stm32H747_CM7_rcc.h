/*
; stm32H747_CM7_rcc.
; ==================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM7_rcc equates.
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
	volatile	uint32_t	HSICFGR;
	volatile	uint32_t	CRRCR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	CFGR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	D1CFGR;
	volatile	uint32_t	D2CFGR;
	volatile	uint32_t	D3CFGR;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	PLLCKSELR;
	volatile	uint32_t	PLLCFGR;
	volatile	uint32_t	PLL1DIVR;
	volatile	uint32_t	PLL1FRACR;
	volatile	uint32_t	PLL2DIVR;
	volatile	uint32_t	PLL2FRACR;
	volatile	uint32_t	PLL3DIVR;
	volatile	uint32_t	PLL3FRACR;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	D1CCIPR;
	volatile	uint32_t	D2CCIP1R;
	volatile	uint32_t	D2CCIP2R;
	volatile	uint32_t	D3CCIPR;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	CIER;
	volatile	uint32_t	CIFR;
	volatile	uint32_t	CICR;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	BDCR;
	volatile	uint32_t	CSR;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	AHB3RSTR;
	volatile	uint32_t	AHB1RSTR;
	volatile	uint32_t	AHB2RSTR;
	volatile	uint32_t	AHB4RSTR;
	volatile	uint32_t	APB3RSTR;
	volatile	uint32_t	APB1LRSTR;
	volatile	uint32_t	APB1HRSTR;
	volatile	uint32_t	APB2RSTR;
	volatile	uint32_t	APB4RSTR;
	volatile	uint32_t	GCR;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	D3AMR;
	volatile	uint32_t	RESERVED8[9];
	volatile	uint32_t	RSR;
	volatile	uint32_t	AHB3ENR;
	volatile	uint32_t	AHB1ENR;
	volatile	uint32_t	AHB2ENR;
	volatile	uint32_t	AHB4ENR;
	volatile	uint32_t	APB3ENR;
	volatile	uint32_t	APB1LENR;
	volatile	uint32_t	APB1HENR;
	volatile	uint32_t	APB2ENR;
	volatile	uint32_t	APB4ENR;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	AHB3LPENR;
	volatile	uint32_t	AHB1LPENR;
	volatile	uint32_t	AHB2LPENR;
	volatile	uint32_t	AHB4LPENR;
	volatile	uint32_t	APB3LPENR;
	volatile	uint32_t	APB1LLPENR;
	volatile	uint32_t	APB1HLPENR;
	volatile	uint32_t	APB2LPENR;
	volatile	uint32_t	APB4LPENR;
	volatile	uint32_t	RESERVED10[4];
	volatile	uint32_t	C1_RSR;
	volatile	uint32_t	C1_AHB3ENR;
	volatile	uint32_t	C1_AHB1ENR;
	volatile	uint32_t	C1_AHB2ENR;
	volatile	uint32_t	C1_AHB4ENR;
	volatile	uint32_t	C1_APB3ENR;
	volatile	uint32_t	C1_APB1LENR;
	volatile	uint32_t	C1_APB1HENR;
	volatile	uint32_t	C1_APB2ENR;
	volatile	uint32_t	C1_APB4ENR;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	C1_AHB3LPENR;
	volatile	uint32_t	C1_AHB1LPENR;
	volatile	uint32_t	C1_AHB2LPENR;
	volatile	uint32_t	C1_AHB4LPENR;
	volatile	uint32_t	C1_APB3LPENR;
	volatile	uint32_t	C1_APB1LLPENR;
	volatile	uint32_t	C1_APB1HLPENR;
	volatile	uint32_t	C1_APB2LPENR;
	volatile	uint32_t	C1_APB4LPENR;
} RCC_TypeDef;

#if (defined(__cplusplus))
#define	RCC	reinterpret_cast<RCC_TypeDef *>(0x58024400u)

#else
#define	RCC	((RCC_TypeDef *)0x58024400u)
#endif

// CR Configuration

#define	RCC_CR_PLL3RDY						(0x1u<<29)
#define	RCC_CR_PLL3ON						(0x1u<<28)
#define	RCC_CR_PLL2RDY						(0x1u<<27)
#define	RCC_CR_PLL2ON						(0x1u<<26)
#define	RCC_CR_PLL1RDY						(0x1u<<25)
#define	RCC_CR_PLL1ON						(0x1u<<24)
#define	RCC_CR_HSECSSON						(0x1u<<19)
#define	RCC_CR_HSEBYP						(0x1u<<18)
#define	RCC_CR_HSERDY						(0x1u<<17)
#define	RCC_CR_HSEON						(0x1u<<16)
#define	RCC_CR_D2CKRDY						(0x1u<<15)
#define	RCC_CR_D1CKRDY						(0x1u<<14)
#define	RCC_CR_RC48RDY						(0x1u<<13)
#define	RCC_CR_RC48ON						(0x1u<<12)
#define	RCC_CR_CSIKERON						(0x1u<<9)
#define	RCC_CR_CSIRDY						(0x1u<<8)
#define	RCC_CR_CSION						(0x1u<<7)
#define	RCC_CR_HSIDIVF						(0x1u<<5)
#define	RCC_CR_HSIDIV						(0x3u<<3)
#define	RCC_CR_HSIDIV_0						(0x1u<<3)
#define	RCC_CR_HSIRDY						(0x1u<<2)
#define	RCC_CR_HSIKERON						(0x1u<<1)
#define	RCC_CR_HSION						(0x1u<<0)

// HSICFGR Configuration

#define	RCC_HSICFGR_HSITRIM					(0x7Fu<<24)
#define	RCC_HSICFGR_HSITRIM_0				(0x1u<<24)
#define	RCC_HSICFGR_HSICAL					(0xFFFu<<0)
#define	RCC_HSICFGR_HSICAL_0				(0x1u<<0)

// CRRCR Configuration

#define	RCC_CRRCR_RC48CAL					(0x3FFu<<0)
#define	RCC_CRRCR_RC48CAL_0					(0x1u<<0)

// CFGR Configuration

#define	RCC_CFGR_MCO2SEL					(0x7u<<29)
#define	RCC_CFGR_MCO2SEL_0					(0x1u<<29)
#define	RCC_CFGR_MCO2PRE					(0xFu<<25)
#define	RCC_CFGR_MCO2PRE_0					(0x1u<<25)
#define	RCC_CFGR_MCO1SEL					(0x7u<<22)
#define	RCC_CFGR_MCO1SEL_0					(0x1u<<22)
#define	RCC_CFGR_MCO1PRE					(0xFu<<18)
#define	RCC_CFGR_MCO1PRE_0					(0x1u<<18)
#define	RCC_CFGR_TIMPRE						(0x1u<<15)
#define	RCC_CFGR_HRTIMSEL					(0x1u<<14)
#define	RCC_CFGR_RTCPRE						(0x3Fu<<8)
#define	RCC_CFGR_RTCPRE_0					(0x1u<<8)
#define	RCC_CFGR_STOPKERWUCK				(0x1u<<7)
#define	RCC_CFGR_STOPWUCK					(0x1u<<6)
#define	RCC_CFGR_SWS						(0x7u<<3)
#define	RCC_CFGR_SWS_0						(0x1u<<3)
#define	RCC_CFGR_SW							(0x7u<<0)
#define	RCC_CFGR_SW_0						(0x1u<<0)

// D1CFGR Configuration

#define	RCC_D1CFGR_D1CPRE					(0xFu<<8)
#define	RCC_D1CFGR_D1CPRE_0					(0x1u<<8)
#define	RCC_D1CFGR_D1PPRE					(0x7u<<4)
#define	RCC_D1CFGR_D1PPRE_0					(0x1u<<4)
#define	RCC_D1CFGR_HPRE						(0xFu<<0)
#define	RCC_D1CFGR_HPRE_0					(0x1u<<0)

// D2CFGR Configuration

#define	RCC_D2CFGR_D2PPRE2					(0x7u<<8)
#define	RCC_D2CFGR_D2PPRE2_0				(0x1u<<8)
#define	RCC_D2CFGR_D2PPRE1					(0x7u<<4)
#define	RCC_D2CFGR_D2PPRE1_0				(0x1u<<4)

// D3CFGR Configuration

#define	RCC_D3CFGR_D3PPRE					(0x7u<<4)
#define	RCC_D3CFGR_D3PPRE_0					(0x1u<<4)

// PLLCKSELR Configuration

#define	RCC_PLLCKSELR_DIVM3					(0x3Fu<<20)
#define	RCC_PLLCKSELR_DIVM3_0				(0x1u<<20)
#define	RCC_PLLCKSELR_DIVM2					(0x3Fu<<12)
#define	RCC_PLLCKSELR_DIVM2_0				(0x1u<<12)
#define	RCC_PLLCKSELR_DIVM1					(0x3Fu<<4)
#define	RCC_PLLCKSELR_DIVM1_0				(0x1u<<4)
#define	RCC_PLLCKSELR_PLLSRC				(0x3u<<0)
#define	RCC_PLLCKSELR_PLLSRC_0				(0x1u<<0)

// PLLCFGR Configuration

#define	RCC_PLLCFGR_DIVR3EN					(0x1u<<24)
#define	RCC_PLLCFGR_DIVQ3EN					(0x1u<<23)
#define	RCC_PLLCFGR_DIVP3EN					(0x1u<<22)
#define	RCC_PLLCFGR_DIVR2EN					(0x1u<<21)
#define	RCC_PLLCFGR_DIVQ2EN					(0x1u<<20)
#define	RCC_PLLCFGR_DIVP2EN					(0x1u<<19)
#define	RCC_PLLCFGR_DIVR1EN					(0x1u<<18)
#define	RCC_PLLCFGR_DIVQ1EN					(0x1u<<17)
#define	RCC_PLLCFGR_DIVP1EN					(0x1u<<16)
#define	RCC_PLLCFGR_PLL3RGE					(0x3u<<10)
#define	RCC_PLLCFGR_PLL3RGE_0				(0x1u<<10)
#define	RCC_PLLCFGR_PLL3VCOSEL				(0x1u<<9)
#define	RCC_PLLCFGR_PLL3FRACEN				(0x1u<<8)
#define	RCC_PLLCFGR_PLL2RGE					(0x3u<<6)
#define	RCC_PLLCFGR_PLL2RGE_0				(0x1u<<6)
#define	RCC_PLLCFGR_PLL2VCOSEL				(0x1u<<5)
#define	RCC_PLLCFGR_PLL2FRACEN				(0x1u<<4)
#define	RCC_PLLCFGR_PLL1RGE					(0x3u<<2)
#define	RCC_PLLCFGR_PLL1RGE_0				(0x1u<<2)
#define	RCC_PLLCFGR_PLL1VCOSEL				(0x1u<<1)
#define	RCC_PLLCFGR_PLL1FRACEN				(0x1u<<0)

// PLL1DIVR Configuration

#define	RCC_PLL1DIVR_DIVR1					(0x7Fu<<24)
#define	RCC_PLL1DIVR_DIVR1_0				(0x1u<<24)
#define	RCC_PLL1DIVR_DIVQ1					(0x7Fu<<16)
#define	RCC_PLL1DIVR_DIVQ1_0				(0x1u<<16)
#define	RCC_PLL1DIVR_DIVP1					(0x7Fu<<9)
#define	RCC_PLL1DIVR_DIVP1_0				(0x1u<<9)
#define	RCC_PLL1DIVR_DIVN1					(0x1FFu<<0)
#define	RCC_PLL1DIVR_DIVN1_0				(0x1u<<0)

// PLL1FRACR Configuration

#define	RCC_PLL1FRACR_FRACN1				(0x1FFFu<<3)
#define	RCC_PLL1FRACR_FRACN1_0				(0x1u<<3)

// PLL2DIVR Configuration

#define	RCC_PLL2DIVR_DIVR2					(0x7Fu<<24)
#define	RCC_PLL2DIVR_DIVR2_0				(0x1u<<24)
#define	RCC_PLL2DIVR_DIVQ2					(0x7Fu<<16)
#define	RCC_PLL2DIVR_DIVQ2_0				(0x1u<<16)
#define	RCC_PLL2DIVR_DIVP2					(0x7Fu<<9)
#define	RCC_PLL2DIVR_DIVP2_0				(0x1u<<9)
#define	RCC_PLL2DIVR_DIVN2					(0x1FFu<<0)
#define	RCC_PLL2DIVR_DIVN2_0				(0x1u<<0)

// PLL2FRACR Configuration

#define	RCC_PLL2FRACR_FRACN2				(0x1FFFu<<3)
#define	RCC_PLL2FRACR_FRACN2_0				(0x1u<<3)

// PLL3DIVR Configuration

#define	RCC_PLL3DIVR_DIVR3					(0x7Fu<<24)
#define	RCC_PLL3DIVR_DIVR3_0				(0x1u<<24)
#define	RCC_PLL3DIVR_DIVQ3					(0x7Fu<<16)
#define	RCC_PLL3DIVR_DIVQ3_0				(0x1u<<16)
#define	RCC_PLL3DIVR_DIVP3					(0x7Fu<<9)
#define	RCC_PLL3DIVR_DIVP3_0				(0x1u<<9)
#define	RCC_PLL3DIVR_DIVN3					(0x1FFu<<0)
#define	RCC_PLL3DIVR_DIVN3_0				(0x1u<<0)

// PLL3FRACR Configuration

#define	RCC_PLL3FRACR_FRACN3				(0x1FFFu<<3)
#define	RCC_PLL3FRACR_FRACN3_0				(0x1u<<3)

// D1CCIPR Configuration

#define	RCC_D1CCIPR_CKPERSEL				(0x3u<<28)
#define	RCC_D1CCIPR_CKPERSEL_0				(0x1u<<28)
#define	RCC_D1CCIPR_SDMMCSEL				(0x1u<<16)
#define	RCC_D1CCIPR_DSISEL					(0x1u<<8)
#define	RCC_D1CCIPR_QSPISEL					(0x3u<<4)
#define	RCC_D1CCIPR_QSPISEL_0				(0x1u<<4)
#define	RCC_D1CCIPR_FMCSEL					(0x3u<<0)
#define	RCC_D1CCIPR_FMCSEL_0				(0x1u<<0)

// D2CCIP1R Configuration

#define	RCC_D2CCIP1R_SWPSEL					(0x1u<<31)
#define	RCC_D2CCIP1R_FDCANSEL				(0x3u<<28)
#define	RCC_D2CCIP1R_FDCANSEL_0				(0x1u<<28)
#define	RCC_D2CCIP1R_DFSDM1SEL				(0x1u<<24)
#define	RCC_D2CCIP1R_SPDIFSEL				(0x3u<<20)
#define	RCC_D2CCIP1R_SPDIFSEL_0				(0x1u<<20)
#define	RCC_D2CCIP1R_SPI45SEL				(0x7u<<16)
#define	RCC_D2CCIP1R_SPI45SEL_0				(0x1u<<16)
#define	RCC_D2CCIP1R_SPI123SEL				(0x7u<<12)
#define	RCC_D2CCIP1R_SPI123SEL_0			(0x1u<<12)
#define	RCC_D2CCIP1R_SAI23SEL				(0x7u<<6)
#define	RCC_D2CCIP1R_SAI23SEL_0				(0x1u<<6)
#define	RCC_D2CCIP1R_SAI1SEL				(0x7u<<0)
#define	RCC_D2CCIP1R_SAI1SEL_0				(0x1u<<0)

// D2CCIP2R Configuration

#define	RCC_D2CCIP2R_LPTIM1SEL				(0x7u<<28)
#define	RCC_D2CCIP2R_LPTIM1SEL_0			(0x1u<<28)
#define	RCC_D2CCIP2R_CECSEL					(0x3u<<22)
#define	RCC_D2CCIP2R_CECSEL_0				(0x1u<<22)
#define	RCC_D2CCIP2R_USBSEL					(0x3u<<20)
#define	RCC_D2CCIP2R_USBSEL_0				(0x1u<<20)
#define	RCC_D2CCIP2R_I2C123SEL				(0x3u<<12)
#define	RCC_D2CCIP2R_I2C123SEL_0			(0x1u<<12)
#define	RCC_D2CCIP2R_RNGSEL					(0x3u<<8)
#define	RCC_D2CCIP2R_RNGSEL_0				(0x1u<<8)
#define	RCC_D2CCIP2R_USART16SEL				(0x7u<<3)
#define	RCC_D2CCIP2R_USART16SEL_0			(0x1u<<3)
#define	RCC_D2CCIP2R_USART234578SEL			(0x7u<<0)
#define	RCC_D2CCIP2R_USART234578SEL_0		(0x1u<<0)

// D3CCIPR Configuration

#define	RCC_D3CCIPR_SPI6SEL					(0x7u<<28)
#define	RCC_D3CCIPR_SPI6SEL_0				(0x1u<<28)
#define	RCC_D3CCIPR_SAI4BSEL				(0x7u<<24)
#define	RCC_D3CCIPR_SAI4BSEL_0				(0x1u<<24)
#define	RCC_D3CCIPR_SAI4ASEL				(0x7u<<21)
#define	RCC_D3CCIPR_SAI4ASEL_0				(0x1u<<21)
#define	RCC_D3CCIPR_ADCSEL					(0x3u<<16)
#define	RCC_D3CCIPR_ADCSEL_0				(0x1u<<16)
#define	RCC_D3CCIPR_LPTIM345SEL				(0x7u<<13)
#define	RCC_D3CCIPR_LPTIM345SEL_0			(0x1u<<13)
#define	RCC_D3CCIPR_LPTIM2SEL				(0x7u<<10)
#define	RCC_D3CCIPR_LPTIM2SEL_0				(0x1u<<10)
#define	RCC_D3CCIPR_I2C4SEL					(0x3u<<8)
#define	RCC_D3CCIPR_I2C4SEL_0				(0x1u<<8)
#define	RCC_D3CCIPR_LPUART1SEL				(0x7u<<0)
#define	RCC_D3CCIPR_LPUART1SEL_0			(0x1u<<0)

// CIER Configuration

#define	RCC_CIER_LSECSSIE					(0x1u<<9)
#define	RCC_CIER_PLL3RDYIE					(0x1u<<8)
#define	RCC_CIER_PLL2RDYIE					(0x1u<<7)
#define	RCC_CIER_PLL1RDYIE					(0x1u<<6)
#define	RCC_CIER_RC48RDYIE					(0x1u<<5)
#define	RCC_CIER_CSIRDYIE					(0x1u<<4)
#define	RCC_CIER_HSERDYIE					(0x1u<<3)
#define	RCC_CIER_HSIRDYIE					(0x1u<<2)
#define	RCC_CIER_LSERDYIE					(0x1u<<1)
#define	RCC_CIER_LSIRDYIE					(0x1u<<0)

// CIFR Configuration

#define	RCC_CIFR_HSECSSF					(0x1u<<10)
#define	RCC_CIFR_LSECSSF					(0x1u<<9)
#define	RCC_CIFR_PLL3RDYF					(0x1u<<8)
#define	RCC_CIFR_PLL2RDYF					(0x1u<<7)
#define	RCC_CIFR_PLL1RDYF					(0x1u<<6)
#define	RCC_CIFR_RC48RDYF					(0x1u<<5)
#define	RCC_CIFR_CSIRDY						(0x1u<<4)
#define	RCC_CIFR_HSERDYF					(0x1u<<3)
#define	RCC_CIFR_HSIRDYF					(0x1u<<2)
#define	RCC_CIFR_LSERDYF					(0x1u<<1)
#define	RCC_CIFR_LSIRDYF					(0x1u<<0)

// CICR Configuration

#define	RCC_CICR_HSECSSC					(0x1u<<10)
#define	RCC_CICR_LSECSSC					(0x1u<<9)
#define	RCC_CICR_PLL3RDYC					(0x1u<<8)
#define	RCC_CICR_PLL2RDYC					(0x1u<<7)
#define	RCC_CICR_PLL1RDYC					(0x1u<<6)
#define	RCC_CICR_RC48RDYC					(0x1u<<5)
#define	RCC_CICR_HSE_READY_INTERRUPT_CLEAR	(0x1u<<4)
#define	RCC_CICR_HSERDYC					(0x1u<<3)
#define	RCC_CICR_HSIRDYC					(0x1u<<2)
#define	RCC_CICR_LSERDYC					(0x1u<<1)
#define	RCC_CICR_LSIRDYC					(0x1u<<0)

// BDCR Configuration

#define	RCC_BDCR_VSWRST						(0x1u<<16)
#define	RCC_BDCR_RTCEN						(0x1u<<15)
#define	RCC_BDCR_RTCSRC						(0x3u<<8)
#define	RCC_BDCR_RTCSRC_0					(0x1u<<8)
#define	RCC_BDCR_LSECSSD					(0x1u<<6)
#define	RCC_BDCR_LSECSSON					(0x1u<<5)
#define	RCC_BDCR_LSEDRV						(0x3u<<3)
#define	RCC_BDCR_LSEDRV_0					(0x1u<<3)
#define	RCC_BDCR_LSEBYP						(0x1u<<2)
#define	RCC_BDCR_LSERDY						(0x1u<<1)
#define	RCC_BDCR_LSEON						(0x1u<<0)

// CSR Configuration

#define	RCC_CSR_LSIRDY						(0x1u<<1)
#define	RCC_CSR_LSION						(0x1u<<0)

// AHB3RSTR Configuration

#define	RCC_AHB3RSTR_CPURST					(0x1u<<31)
#define	RCC_AHB3RSTR_SDMMC1RST				(0x1u<<16)
#define	RCC_AHB3RSTR_QSPIRST				(0x1u<<14)
#define	RCC_AHB3RSTR_FMCRST					(0x1u<<12)
#define	RCC_AHB3RSTR_JPGDECRST				(0x1u<<5)
#define	RCC_AHB3RSTR_DMA2DRST				(0x1u<<4)
#define	RCC_AHB3RSTR_MDMARST				(0x1u<<0)

// AHB1RSTR Configuration

#define	RCC_AHB1RSTR_USB2OTGRST				(0x1u<<27)
#define	RCC_AHB1RSTR_USB1OTGRST				(0x1u<<25)
#define	RCC_AHB1RSTR_ETH1MACRST				(0x1u<<15)
#define	RCC_AHB1RSTR_ADC12RST				(0x1u<<5)
#define	RCC_AHB1RSTR_DMA2RST				(0x1u<<1)
#define	RCC_AHB1RSTR_DMA1RST				(0x1u<<0)

// AHB2RSTR Configuration

#define	RCC_AHB2RSTR_SDMMC2RST				(0x1u<<9)
#define	RCC_AHB2RSTR_RNGRST					(0x1u<<6)
#define	RCC_AHB2RSTR_HASHRST				(0x1u<<5)
#define	RCC_AHB2RSTR_CRYPTRST				(0x1u<<4)
#define	RCC_AHB2RSTR_CAMITFRST				(0x1u<<0)

// AHB4RSTR Configuration

#define	RCC_AHB4RSTR_HSEMRST				(0x1u<<25)
#define	RCC_AHB4RSTR_ADC3RST				(0x1u<<24)
#define	RCC_AHB4RSTR_BDMARST				(0x1u<<21)
#define	RCC_AHB4RSTR_CRCRST					(0x1u<<19)
#define	RCC_AHB4RSTR_GPIOKRST				(0x1u<<10)
#define	RCC_AHB4RSTR_GPIOJRST				(0x1u<<9)
#define	RCC_AHB4RSTR_GPIOIRST				(0x1u<<8)
#define	RCC_AHB4RSTR_GPIOHRST				(0x1u<<7)
#define	RCC_AHB4RSTR_GPIOGRST				(0x1u<<6)
#define	RCC_AHB4RSTR_GPIOFRST				(0x1u<<5)
#define	RCC_AHB4RSTR_GPIOERST				(0x1u<<4)
#define	RCC_AHB4RSTR_GPIODRST				(0x1u<<3)
#define	RCC_AHB4RSTR_GPIOCRST				(0x1u<<2)
#define	RCC_AHB4RSTR_GPIOBRST				(0x1u<<1)
#define	RCC_AHB4RSTR_GPIOARST				(0x1u<<0)

// APB3RSTR Configuration

#define	RCC_APB3RSTR_LTDCRST				(0x1u<<3)

// APB1LRSTR Configuration

#define	RCC_APB1LRSTR_USART8RST				(0x1u<<31)
#define	RCC_APB1LRSTR_USART7RST				(0x1u<<30)
#define	RCC_APB1LRSTR_DAC12RST				(0x1u<<29)
#define	RCC_APB1LRSTR_HDMICECRST			(0x1u<<27)
#define	RCC_APB1LRSTR_I2C3RST				(0x1u<<23)
#define	RCC_APB1LRSTR_I2C2RST				(0x1u<<22)
#define	RCC_APB1LRSTR_I2C1RST				(0x1u<<21)
#define	RCC_APB1LRSTR_UART5RST				(0x1u<<20)
#define	RCC_APB1LRSTR_UART4RST				(0x1u<<19)
#define	RCC_APB1LRSTR_USART3RST				(0x1u<<18)
#define	RCC_APB1LRSTR_USART2RST				(0x1u<<17)
#define	RCC_APB1LRSTR_SPDIFRXRST			(0x1u<<16)
#define	RCC_APB1LRSTR_SPI3RST				(0x1u<<15)
#define	RCC_APB1LRSTR_SPI2RST				(0x1u<<14)
#define	RCC_APB1LRSTR_LPTIM1RST				(0x1u<<9)
#define	RCC_APB1LRSTR_TIM14RST				(0x1u<<8)
#define	RCC_APB1LRSTR_TIM13RST				(0x1u<<7)
#define	RCC_APB1LRSTR_TIM12RST				(0x1u<<6)
#define	RCC_APB1LRSTR_TIM7RST				(0x1u<<5)
#define	RCC_APB1LRSTR_TIM6RST				(0x1u<<4)
#define	RCC_APB1LRSTR_TIM5RST				(0x1u<<3)
#define	RCC_APB1LRSTR_TIM4RST				(0x1u<<2)
#define	RCC_APB1LRSTR_TIM3RST				(0x1u<<1)
#define	RCC_APB1LRSTR_TIM2RST				(0x1u<<0)

// APB1HRSTR Configuration

#define	RCC_APB1HRSTR_FDCANRST				(0x1u<<8)
#define	RCC_APB1HRSTR_MDIOSRST				(0x1u<<5)
#define	RCC_APB1HRSTR_OPAMPRST				(0x1u<<4)
#define	RCC_APB1HRSTR_SWPRST				(0x1u<<2)
#define	RCC_APB1HRSTR_CRSRST				(0x1u<<1)

// APB2RSTR Configuration

#define	RCC_APB2RSTR_HRTIMRST				(0x1u<<29)
#define	RCC_APB2RSTR_DFSDM1RST				(0x1u<<28)
#define	RCC_APB2RSTR_SAI3RST				(0x1u<<24)
#define	RCC_APB2RSTR_SAI2RST				(0x1u<<23)
#define	RCC_APB2RSTR_SAI1RST				(0x1u<<22)
#define	RCC_APB2RSTR_SPI5RST				(0x1u<<20)
#define	RCC_APB2RSTR_TIM17RST				(0x1u<<18)
#define	RCC_APB2RSTR_TIM16RST				(0x1u<<17)
#define	RCC_APB2RSTR_TIM15RST				(0x1u<<16)
#define	RCC_APB2RSTR_SPI4RST				(0x1u<<13)
#define	RCC_APB2RSTR_SPI1RST				(0x1u<<12)
#define	RCC_APB2RSTR_USART6RST				(0x1u<<5)
#define	RCC_APB2RSTR_USART1RST				(0x1u<<4)
#define	RCC_APB2RSTR_TIM8RST				(0x1u<<1)
#define	RCC_APB2RSTR_TIM1RST				(0x1u<<0)

// APB4RSTR Configuration

#define	RCC_APB4RSTR_SAI4RST				(0x1u<<21)
#define	RCC_APB4RSTR_VREFRST				(0x1u<<15)
#define	RCC_APB4RSTR_COMP12RST				(0x1u<<14)
#define	RCC_APB4RSTR_LPTIM5RST				(0x1u<<12)
#define	RCC_APB4RSTR_LPTIM4RST				(0x1u<<11)
#define	RCC_APB4RSTR_LPTIM3RST				(0x1u<<10)
#define	RCC_APB4RSTR_LPTIM2RST				(0x1u<<9)
#define	RCC_APB4RSTR_I2C4RST				(0x1u<<7)
#define	RCC_APB4RSTR_SPI6RST				(0x1u<<5)
#define	RCC_APB4RSTR_LPUART1RST				(0x1u<<3)
#define	RCC_APB4RSTR_SYSCFGRST				(0x1u<<1)

// GCR Configuration

#define	RCC_GCR_WW1RSC						(0x1u<<0)

// D3AMR Configuration

#define	RCC_D3AMR_SRAM4AMEN					(0x1u<<29)
#define	RCC_D3AMR_BKPSRAMAMEN				(0x1u<<28)
#define	RCC_D3AMR_ADC3AMEN					(0x1u<<24)
#define	RCC_D3AMR_SAI4AMEN					(0x1u<<21)
#define	RCC_D3AMR_CRCAMEN					(0x1u<<19)
#define	RCC_D3AMR_RTCAMEN					(0x1u<<16)
#define	RCC_D3AMR_VREFAMEN					(0x1u<<15)
#define	RCC_D3AMR_COMP12AMEN				(0x1u<<14)
#define	RCC_D3AMR_LPTIM5AMEN				(0x1u<<12)
#define	RCC_D3AMR_LPTIM4AMEN				(0x1u<<11)
#define	RCC_D3AMR_LPTIM3AMEN				(0x1u<<10)
#define	RCC_D3AMR_LPTIM2AMEN				(0x1u<<9)
#define	RCC_D3AMR_I2C4AMEN					(0x1u<<7)
#define	RCC_D3AMR_SPI6AMEN					(0x1u<<5)
#define	RCC_D3AMR_LPUART1AMEN				(0x1u<<3)
#define	RCC_D3AMR_BDMAAMEN					(0x1u<<0)

// RSR Configuration

#define	RCC_RSR_LPWRRSTF					(0x1u<<30)
#define	RCC_RSR_WWDG1RSTF					(0x1u<<28)
#define	RCC_RSR_IWDG1RSTF					(0x1u<<26)
#define	RCC_RSR_SFTRSTF						(0x1u<<24)
#define	RCC_RSR_PORRSTF						(0x1u<<23)
#define	RCC_RSR_PINRSTF						(0x1u<<22)
#define	RCC_RSR_BORRSTF						(0x1u<<21)
#define	RCC_RSR_D2RSTF						(0x1u<<20)
#define	RCC_RSR_D1RSTF						(0x1u<<19)
#define	RCC_RSR_CPURSTF						(0x1u<<17)
#define	RCC_RSR_RMVF						(0x1u<<16)

// AHB3ENR Configuration

#define	RCC_AHB3ENR_AXISRAMEN				(0x1u<<31)
#define	RCC_AHB3ENR_ITCM1EN					(0x1u<<30)
#define	RCC_AHB3ENR_DTCM2EN					(0x1u<<29)
#define	RCC_AHB3ENR_DTCM1EN					(0x1u<<28)
#define	RCC_AHB3ENR_SDMMC1EN				(0x1u<<16)
#define	RCC_AHB3ENR_QSPIEN					(0x1u<<14)
#define	RCC_AHB3ENR_FMCEN					(0x1u<<12)
#define	RCC_AHB3ENR_FLITFEN					(0x1u<<8)
#define	RCC_AHB3ENR_JPGDECEN				(0x1u<<5)
#define	RCC_AHB3ENR_DMA2DEN					(0x1u<<4)
#define	RCC_AHB3ENR_MDMAEN					(0x1u<<0)

// AHB1ENR Configuration

#define	RCC_AHB1ENR_USB2OTGHSULPIEN			(0x1u<<28)
#define	RCC_AHB1ENR_USB2OTGHSEN				(0x1u<<27)
#define	RCC_AHB1ENR_USB1OTGHSULPIEN			(0x1u<<26)
#define	RCC_AHB1ENR_USB1OTGHSEN				(0x1u<<25)
#define	RCC_AHB1ENR_ETH1RXEN				(0x1u<<17)
#define	RCC_AHB1ENR_ETH1TXEN				(0x1u<<16)
#define	RCC_AHB1ENR_ETH1MACEN				(0x1u<<15)
#define	RCC_AHB1ENR_ARTEN					(0x1u<<14)
#define	RCC_AHB1ENR_ADC12EN					(0x1u<<5)
#define	RCC_AHB1ENR_DMA2EN					(0x1u<<1)
#define	RCC_AHB1ENR_DMA1EN					(0x1u<<0)

// AHB2ENR Configuration

#define	RCC_AHB2ENR_SRAM3EN					(0x1u<<31)
#define	RCC_AHB2ENR_SRAM2EN					(0x1u<<30)
#define	RCC_AHB2ENR_SRAM1EN					(0x1u<<29)
#define	RCC_AHB2ENR_SDMMC2EN				(0x1u<<9)
#define	RCC_AHB2ENR_RNGEN					(0x1u<<6)
#define	RCC_AHB2ENR_HASHEN					(0x1u<<5)
#define	RCC_AHB2ENR_CRYPTEN					(0x1u<<4)
#define	RCC_AHB2ENR_DCMIEN					(0x1u<<0)

// AHB4ENR Configuration

#define	RCC_AHB4ENR_BKPRAMEN				(0x1u<<28)
#define	RCC_AHB4ENR_HSEMEN					(0x1u<<25)
#define	RCC_AHB4ENR_ADC3EN					(0x1u<<24)
#define	RCC_AHB4ENR_BDMAEN					(0x1u<<21)
#define	RCC_AHB4ENR_CRCEN					(0x1u<<19)
#define	RCC_AHB4ENR_GPIOKEN					(0x1u<<10)
#define	RCC_AHB4ENR_GPIOJEN					(0x1u<<9)
#define	RCC_AHB4ENR_GPIOIEN					(0x1u<<8)
#define	RCC_AHB4ENR_GPIOHEN					(0x1u<<7)
#define	RCC_AHB4ENR_GPIOGEN					(0x1u<<6)
#define	RCC_AHB4ENR_GPIOFEN					(0x1u<<5)
#define	RCC_AHB4ENR_GPIOEEN					(0x1u<<4)
#define	RCC_AHB4ENR_GPIODEN					(0x1u<<3)
#define	RCC_AHB4ENR_GPIOCEN					(0x1u<<2)
#define	RCC_AHB4ENR_GPIOBEN					(0x1u<<1)
#define	RCC_AHB4ENR_GPIOAEN					(0x1u<<0)

// APB3ENR Configuration

#define	RCC_APB3ENR_WWDG1EN					(0x1u<<6)
#define	RCC_APB3ENR_LTDCEN					(0x1u<<3)

// APB1LENR Configuration

#define	RCC_APB1LENR_USART8EN				(0x1u<<31)
#define	RCC_APB1LENR_USART7EN				(0x1u<<30)
#define	RCC_APB1LENR_DAC12EN				(0x1u<<29)
#define	RCC_APB1LENR_HDMICECEN				(0x1u<<27)
#define	RCC_APB1LENR_I2C3EN					(0x1u<<23)
#define	RCC_APB1LENR_I2C2EN					(0x1u<<22)
#define	RCC_APB1LENR_I2C1EN					(0x1u<<21)
#define	RCC_APB1LENR_UART5EN				(0x1u<<20)
#define	RCC_APB1LENR_UART4EN				(0x1u<<19)
#define	RCC_APB1LENR_USART3EN				(0x1u<<18)
#define	RCC_APB1LENR_USART2EN				(0x1u<<17)
#define	RCC_APB1LENR_SPDIFRXEN				(0x1u<<16)
#define	RCC_APB1LENR_SPI3EN					(0x1u<<15)
#define	RCC_APB1LENR_SPI2EN					(0x1u<<14)
#define	RCC_APB1LENR_LPTIM1EN				(0x1u<<9)
#define	RCC_APB1LENR_TIM14EN				(0x1u<<8)
#define	RCC_APB1LENR_TIM13EN				(0x1u<<7)
#define	RCC_APB1LENR_TIM12EN				(0x1u<<6)
#define	RCC_APB1LENR_TIM7EN					(0x1u<<5)
#define	RCC_APB1LENR_TIM6EN					(0x1u<<4)
#define	RCC_APB1LENR_TIM5EN					(0x1u<<3)
#define	RCC_APB1LENR_TIM4EN					(0x1u<<2)
#define	RCC_APB1LENR_TIM3EN					(0x1u<<1)
#define	RCC_APB1LENR_TIM2EN					(0x1u<<0)

// APB1HENR Configuration

#define	RCC_APB1HENR_FDCANEN				(0x1u<<8)
#define	RCC_APB1HENR_MDIOSEN				(0x1u<<5)
#define	RCC_APB1HENR_OPAMPEN				(0x1u<<4)
#define	RCC_APB1HENR_SWPEN					(0x1u<<2)
#define	RCC_APB1HENR_CRSEN					(0x1u<<1)

// APB2ENR Configuration

#define	RCC_APB2ENR_HRTIMEN					(0x1u<<29)
#define	RCC_APB2ENR_DFSDM1EN				(0x1u<<28)
#define	RCC_APB2ENR_SAI3EN					(0x1u<<24)
#define	RCC_APB2ENR_SAI2EN					(0x1u<<23)
#define	RCC_APB2ENR_SAI1EN					(0x1u<<22)
#define	RCC_APB2ENR_SPI5EN					(0x1u<<20)
#define	RCC_APB2ENR_TIM17EN					(0x1u<<18)
#define	RCC_APB2ENR_TIM15EN					(0x1u<<16)
#define	RCC_APB2ENR_TIM16EN					(0x1u<<17)
#define	RCC_APB2ENR_SPI4EN					(0x1u<<13)
#define	RCC_APB2ENR_SPI1EN					(0x1u<<12)
#define	RCC_APB2ENR_USART6EN				(0x1u<<5)
#define	RCC_APB2ENR_USART1EN				(0x1u<<4)
#define	RCC_APB2ENR_TIM8EN					(0x1u<<1)
#define	RCC_APB2ENR_TIM1EN					(0x1u<<0)

// APB4ENR Configuration

#define	RCC_APB4ENR_SAI4EN					(0x1u<<21)
#define	RCC_APB4ENR_RTCAPBEN				(0x1u<<16)
#define	RCC_APB4ENR_VREFEN					(0x1u<<15)
#define	RCC_APB4ENR_COMP12EN				(0x1u<<14)
#define	RCC_APB4ENR_LPTIM5EN				(0x1u<<12)
#define	RCC_APB4ENR_LPTIM4EN				(0x1u<<11)
#define	RCC_APB4ENR_LPTIM3EN				(0x1u<<10)
#define	RCC_APB4ENR_LPTIM2EN				(0x1u<<9)
#define	RCC_APB4ENR_I2C4EN					(0x1u<<7)
#define	RCC_APB4ENR_SPI6EN					(0x1u<<5)
#define	RCC_APB4ENR_LPUART1EN				(0x1u<<3)
#define	RCC_APB4ENR_SYSCFGEN				(0x1u<<1)

// AHB3LPENR Configuration

#define	RCC_AHB3LPENR_AXISRAMLPEN			(0x1u<<31)
#define	RCC_AHB3LPENR_ITCMLPEN				(0x1u<<30)
#define	RCC_AHB3LPENR_DTCM2LPEN				(0x1u<<29)
#define	RCC_AHB3LPENR_D1DTCM1LPEN			(0x1u<<28)
#define	RCC_AHB3LPENR_SDMMC1LPEN			(0x1u<<16)
#define	RCC_AHB3LPENR_QSPILPEN				(0x1u<<14)
#define	RCC_AHB3LPENR_FMCLPEN				(0x1u<<12)
#define	RCC_AHB3LPENR_FLITFLPEN				(0x1u<<8)
#define	RCC_AHB3LPENR_JPGDECLPEN			(0x1u<<5)
#define	RCC_AHB3LPENR_DMA2DLPEN				(0x1u<<4)
#define	RCC_AHB3LPENR_MDMALPEN				(0x1u<<0)

// AHB1LPENR Configuration

#define	RCC_AHB1LPENR_USB2ULPILPEN			(0x1u<<28)
#define	RCC_AHB1LPENR_USB2OTGLPEN			(0x1u<<27)
#define	RCC_AHB1LPENR_USB1ULPILPEN			(0x1u<<26)
#define	RCC_AHB1LPENR_USB1OTGLPEN			(0x1u<<25)
#define	RCC_AHB1LPENR_ETH1RXLPEN			(0x1u<<17)
#define	RCC_AHB1LPENR_ETH1TXLPEN			(0x1u<<16)
#define	RCC_AHB1LPENR_ETH1MACLPEN			(0x1u<<15)
#define	RCC_AHB1LPENR_ADC12LPEN				(0x1u<<5)
#define	RCC_AHB1LPENR_DMA2LPEN				(0x1u<<1)
#define	RCC_AHB1LPENR_DMA1LPEN				(0x1u<<0)

// AHB2LPENR Configuration

#define	RCC_AHB2LPENR_SRAM3LPEN				(0x1u<<31)
#define	RCC_AHB2LPENR_SRAM2LPEN				(0x1u<<30)
#define	RCC_AHB2LPENR_SRAM1LPEN				(0x1u<<29)
#define	RCC_AHB2LPENR_RNGLPEN				(0x1u<<6)
#define	RCC_AHB2LPENR_SDMMC2LPEN			(0x1u<<9)
#define	RCC_AHB2LPENR_HASHLPEN				(0x1u<<5)
#define	RCC_AHB2LPENR_CRYPTLPEN				(0x1u<<4)
#define	RCC_AHB2LPENR_CAMITFLPEN			(0x1u<<0)

// AHB4LPENR Configuration

#define	RCC_AHB4LPENR_SRAM4LPEN				(0x1u<<29)
#define	RCC_AHB4LPENR_BKPRAMLPEN			(0x1u<<28)
#define	RCC_AHB4LPENR_ADC3LPEN				(0x1u<<24)
#define	RCC_AHB4LPENR_BDMALPEN				(0x1u<<21)
#define	RCC_AHB4LPENR_CRCLPEN				(0x1u<<19)
#define	RCC_AHB4LPENR_GPIOKLPEN				(0x1u<<10)
#define	RCC_AHB4LPENR_GPIOJLPEN				(0x1u<<9)
#define	RCC_AHB4LPENR_GPIOILPEN				(0x1u<<8)
#define	RCC_AHB4LPENR_GPIOHLPEN				(0x1u<<7)
#define	RCC_AHB4LPENR_GPIOGLPEN				(0x1u<<6)
#define	RCC_AHB4LPENR_GPIOFLPEN				(0x1u<<5)
#define	RCC_AHB4LPENR_GPIOELPEN				(0x1u<<4)
#define	RCC_AHB4LPENR_GPIODLPEN				(0x1u<<3)
#define	RCC_AHB4LPENR_GPIOCLPEN				(0x1u<<2)
#define	RCC_AHB4LPENR_GPIOBLPEN				(0x1u<<1)
#define	RCC_AHB4LPENR_GPIOALPEN				(0x1u<<0)

// APB3LPENR Configuration

#define	RCC_APB3LPENR_WWDG1LPEN				(0x1u<<6)
#define	RCC_APB3LPENR_LTDCLPEN				(0x1u<<3)

// APB1LLPENR Configuration

#define	RCC_APB1LLPENR_USART8LPEN			(0x1u<<31)
#define	RCC_APB1LLPENR_USART7LPEN			(0x1u<<30)
#define	RCC_APB1LLPENR_DAC12LPEN			(0x1u<<29)
#define	RCC_APB1LLPENR_HDMICECLPEN			(0x1u<<27)
#define	RCC_APB1LLPENR_I2C3LPEN				(0x1u<<23)
#define	RCC_APB1LLPENR_I2C2LPEN				(0x1u<<22)
#define	RCC_APB1LLPENR_I2C1LPEN				(0x1u<<21)
#define	RCC_APB1LLPENR_UART5LPEN			(0x1u<<20)
#define	RCC_APB1LLPENR_UART4LPEN			(0x1u<<19)
#define	RCC_APB1LLPENR_USART3LPEN			(0x1u<<18)
#define	RCC_APB1LLPENR_USART2LPEN			(0x1u<<17)
#define	RCC_APB1LLPENR_SPDIFRXLPEN			(0x1u<<16)
#define	RCC_APB1LLPENR_SPI3LPEN				(0x1u<<15)
#define	RCC_APB1LLPENR_SPI2LPEN				(0x1u<<14)
#define	RCC_APB1LLPENR_LPTIM1LPEN			(0x1u<<9)
#define	RCC_APB1LLPENR_TIM14LPEN			(0x1u<<8)
#define	RCC_APB1LLPENR_TIM13LPEN			(0x1u<<7)
#define	RCC_APB1LLPENR_TIM12LPEN			(0x1u<<6)
#define	RCC_APB1LLPENR_TIM7LPEN				(0x1u<<5)
#define	RCC_APB1LLPENR_TIM6LPEN				(0x1u<<4)
#define	RCC_APB1LLPENR_TIM5LPEN				(0x1u<<3)
#define	RCC_APB1LLPENR_TIM4LPEN				(0x1u<<2)
#define	RCC_APB1LLPENR_TIM3LPEN				(0x1u<<1)
#define	RCC_APB1LLPENR_TIM2LPEN				(0x1u<<0)

// APB1HLPENR Configuration

#define	RCC_APB1HLPENR_FDCANLPEN			(0x1u<<8)
#define	RCC_APB1HLPENR_MDIOSLPEN			(0x1u<<5)
#define	RCC_APB1HLPENR_OPAMPLPEN			(0x1u<<4)
#define	RCC_APB1HLPENR_SWPLPEN				(0x1u<<2)
#define	RCC_APB1HLPENR_CRSLPEN				(0x1u<<1)

// APB2LPENR Configuration

#define	RCC_APB2LPENR_HRTIMLPEN				(0x1u<<29)
#define	RCC_APB2LPENR_DFSDM1LPEN			(0x1u<<28)
#define	RCC_APB2LPENR_SAI3LPEN				(0x1u<<24)
#define	RCC_APB2LPENR_SAI2LPEN				(0x1u<<23)
#define	RCC_APB2LPENR_SAI1LPEN				(0x1u<<22)
#define	RCC_APB2LPENR_SPI5LPEN				(0x1u<<20)
#define	RCC_APB2LPENR_TIM17LPEN				(0x1u<<18)
#define	RCC_APB2LPENR_TIM16LPEN				(0x1u<<17)
#define	RCC_APB2LPENR_TIM15LPEN				(0x1u<<16)
#define	RCC_APB2LPENR_SPI4LPEN				(0x1u<<13)
#define	RCC_APB2LPENR_SPI1LPEN				(0x1u<<12)
#define	RCC_APB2LPENR_USART6LPEN			(0x1u<<5)
#define	RCC_APB2LPENR_USART1LPEN			(0x1u<<4)
#define	RCC_APB2LPENR_TIM8LPEN				(0x1u<<1)
#define	RCC_APB2LPENR_TIM1LPEN				(0x1u<<0)

// APB4LPENR Configuration

#define	RCC_APB4LPENR_SAI4LPEN				(0x1u<<21)
#define	RCC_APB4LPENR_RTCAPBLPEN			(0x1u<<16)
#define	RCC_APB4LPENR_VREFLPEN				(0x1u<<15)
#define	RCC_APB4LPENR_COMP12LPEN			(0x1u<<14)
#define	RCC_APB4LPENR_LPTIM5LPEN			(0x1u<<12)
#define	RCC_APB4LPENR_LPTIM4LPEN			(0x1u<<11)
#define	RCC_APB4LPENR_LPTIM3LPEN			(0x1u<<10)
#define	RCC_APB4LPENR_LPTIM2LPEN			(0x1u<<9)
#define	RCC_APB4LPENR_I2C4LPEN				(0x1u<<7)
#define	RCC_APB4LPENR_SPI6LPEN				(0x1u<<5)
#define	RCC_APB4LPENR_LPUART1LPEN			(0x1u<<3)
#define	RCC_APB4LPENR_SYSCFGLPEN			(0x1u<<1)

// C1_RSR Configuration

#define	RCC_C1_RSR_LPWRRSTF					(0x1u<<30)
#define	RCC_C1_RSR_WWDG1RSTF				(0x1u<<28)
#define	RCC_C1_RSR_IWDG1RSTF				(0x1u<<26)
#define	RCC_C1_RSR_SFTRSTF					(0x1u<<24)
#define	RCC_C1_RSR_PORRSTF					(0x1u<<23)
#define	RCC_C1_RSR_PINRSTF					(0x1u<<22)
#define	RCC_C1_RSR_BORRSTF					(0x1u<<21)
#define	RCC_C1_RSR_D2RSTF					(0x1u<<20)
#define	RCC_C1_RSR_D1RSTF					(0x1u<<19)
#define	RCC_C1_RSR_CPURSTF					(0x1u<<17)
#define	RCC_C1_RSR_RMVF						(0x1u<<16)

// C1_AHB3ENR Configuration

#define	RCC_C1_AHB3ENR_AXISRAMEN			(0x1u<<31)
#define	RCC_C1_AHB3ENR_ITCM1EN				(0x1u<<30)
#define	RCC_C1_AHB3ENR_DTCM2EN				(0x1u<<29)
#define	RCC_C1_AHB3ENR_DTCM1EN				(0x1u<<28)
#define	RCC_C1_AHB3ENR_SDMMC1EN				(0x1u<<16)
#define	RCC_C1_AHB3ENR_QSPIEN				(0x1u<<14)
#define	RCC_C1_AHB3ENR_FMCEN				(0x1u<<12)
#define	RCC_C1_AHB3ENR_JPGDECEN				(0x1u<<5)
#define	RCC_C1_AHB3ENR_DMA2DEN				(0x1u<<4)
#define	RCC_C1_AHB3ENR_MDMAEN				(0x1u<<0)

// C1_AHB1ENR Configuration

#define	RCC_C1_AHB1ENR_USB2OTGHSULPIEN		(0x1u<<28)
#define	RCC_C1_AHB1ENR_USB2OTGHSEN			(0x1u<<27)
#define	RCC_C1_AHB1ENR_USB1OTGHSULPIEN		(0x1u<<26)
#define	RCC_C1_AHB1ENR_USB1OTGHSEN			(0x1u<<25)
#define	RCC_C1_AHB1ENR_ETH1RXEN				(0x1u<<17)
#define	RCC_C1_AHB1ENR_ETH1TXEN				(0x1u<<16)
#define	RCC_C1_AHB1ENR_ETH1MACEN			(0x1u<<15)
#define	RCC_C1_AHB1ENR_ARTEN				(0x1u<<14)
#define	RCC_C1_AHB1ENR_ADC12EN				(0x1u<<5)
#define	RCC_C1_AHB1ENR_DMA2EN				(0x1u<<1)
#define	RCC_C1_AHB1ENR_DMA1EN				(0x1u<<0)

// C1_AHB2ENR Configuration

#define	RCC_C1_AHB2ENR_SRAM3EN				(0x1u<<31)
#define	RCC_C1_AHB2ENR_SRAM2EN				(0x1u<<30)
#define	RCC_C1_AHB2ENR_SRAM1EN				(0x1u<<29)
#define	RCC_C1_AHB2ENR_SDMMC2EN				(0x1u<<9)
#define	RCC_C1_AHB2ENR_RNGEN				(0x1u<<6)
#define	RCC_C1_AHB2ENR_HASHEN				(0x1u<<5)
#define	RCC_C1_AHB2ENR_CRYPTEN				(0x1u<<4)
#define	RCC_C1_AHB2ENR_DCMIEN				(0x1u<<0)

// C1_AHB4ENR Configuration

#define	RCC_C1_AHB4ENR_BKPRAMEN				(0x1u<<28)
#define	RCC_C1_AHB4ENR_HSEMEN				(0x1u<<25)
#define	RCC_C1_AHB4ENR_ADC3EN				(0x1u<<24)
#define	RCC_C1_AHB4ENR_BDMAEN				(0x1u<<21)
#define	RCC_C1_AHB4ENR_CRCEN				(0x1u<<19)
#define	RCC_C1_AHB4ENR_GPIOKEN				(0x1u<<10)
#define	RCC_C1_AHB4ENR_GPIOJEN				(0x1u<<9)
#define	RCC_C1_AHB4ENR_GPIOIEN				(0x1u<<8)
#define	RCC_C1_AHB4ENR_GPIOHEN				(0x1u<<7)
#define	RCC_C1_AHB4ENR_GPIOGEN				(0x1u<<6)
#define	RCC_C1_AHB4ENR_GPIOFEN				(0x1u<<5)
#define	RCC_C1_AHB4ENR_GPIOEEN				(0x1u<<4)
#define	RCC_C1_AHB4ENR_GPIODEN				(0x1u<<3)
#define	RCC_C1_AHB4ENR_GPIOCEN				(0x1u<<2)
#define	RCC_C1_AHB4ENR_GPIOBEN				(0x1u<<1)
#define	RCC_C1_AHB4ENR_GPIOAEN				(0x1u<<0)

// C1_APB3ENR Configuration

#define	RCC_C1_APB3ENR_WWDG1EN				(0x1u<<6)
#define	RCC_C1_APB3ENR_LTDCEN				(0x1u<<3)

// C1_APB1LENR Configuration

#define	RCC_C1_APB1LENR_USART8EN			(0x1u<<31)
#define	RCC_C1_APB1LENR_USART7EN			(0x1u<<30)
#define	RCC_C1_APB1LENR_DAC12EN				(0x1u<<29)
#define	RCC_C1_APB1LENR_HDMICECEN			(0x1u<<27)
#define	RCC_C1_APB1LENR_I2C3EN				(0x1u<<23)
#define	RCC_C1_APB1LENR_I2C2EN				(0x1u<<22)
#define	RCC_C1_APB1LENR_I2C1EN				(0x1u<<21)
#define	RCC_C1_APB1LENR_UART5EN				(0x1u<<20)
#define	RCC_C1_APB1LENR_UART4EN				(0x1u<<19)
#define	RCC_C1_APB1LENR_USART3EN			(0x1u<<18)
#define	RCC_C1_APB1LENR_USART2EN			(0x1u<<17)
#define	RCC_C1_APB1LENR_SPDIFRXEN			(0x1u<<16)
#define	RCC_C1_APB1LENR_SPI3EN				(0x1u<<15)
#define	RCC_C1_APB1LENR_SPI2EN				(0x1u<<14)
#define	RCC_C1_APB1LENR_LPTIM1EN			(0x1u<<9)
#define	RCC_C1_APB1LENR_TIM14EN				(0x1u<<8)
#define	RCC_C1_APB1LENR_TIM13EN				(0x1u<<7)
#define	RCC_C1_APB1LENR_TIM12EN				(0x1u<<6)
#define	RCC_C1_APB1LENR_TIM7EN				(0x1u<<5)
#define	RCC_C1_APB1LENR_TIM6EN				(0x1u<<4)
#define	RCC_C1_APB1LENR_TIM5EN				(0x1u<<3)
#define	RCC_C1_APB1LENR_TIM4EN				(0x1u<<2)
#define	RCC_C1_APB1LENR_TIM3EN				(0x1u<<1)
#define	RCC_C1_APB1LENR_TIM2EN				(0x1u<<0)

// C1_APB1HENR Configuration

#define	RCC_C1_APB1HENR_FDCANEN				(0x1u<<8)
#define	RCC_C1_APB1HENR_MDIOSEN				(0x1u<<5)
#define	RCC_C1_APB1HENR_OPAMPEN				(0x1u<<4)
#define	RCC_C1_APB1HENR_SWPEN				(0x1u<<2)
#define	RCC_C1_APB1HENR_CRSEN				(0x1u<<1)

// C1_APB2ENR Configuration

#define	RCC_C1_APB2ENR_HRTIMEN				(0x1u<<29)
#define	RCC_C1_APB2ENR_DFSDM1EN				(0x1u<<28)
#define	RCC_C1_APB2ENR_SAI3EN				(0x1u<<24)
#define	RCC_C1_APB2ENR_SAI2EN				(0x1u<<23)
#define	RCC_C1_APB2ENR_SAI1EN				(0x1u<<22)
#define	RCC_C1_APB2ENR_SPI5EN				(0x1u<<20)
#define	RCC_C1_APB2ENR_TIM17EN				(0x1u<<18)
#define	RCC_C1_APB2ENR_TIM15EN				(0x1u<<16)
#define	RCC_C1_APB2ENR_TIM16EN				(0x1u<<17)
#define	RCC_C1_APB2ENR_SPI4EN				(0x1u<<13)
#define	RCC_C1_APB2ENR_SPI1EN				(0x1u<<12)
#define	RCC_C1_APB2ENR_USART6EN				(0x1u<<5)
#define	RCC_C1_APB2ENR_USART1EN				(0x1u<<4)
#define	RCC_C1_APB2ENR_TIM8EN				(0x1u<<1)
#define	RCC_C1_APB2ENR_TIM1EN				(0x1u<<0)

// C1_APB4ENR Configuration

#define	RCC_C1_APB4ENR_SAI4EN				(0x1u<<21)
#define	RCC_C1_APB4ENR_RTCAPBEN				(0x1u<<16)
#define	RCC_C1_APB4ENR_VREFEN				(0x1u<<15)
#define	RCC_C1_APB4ENR_COMP12EN				(0x1u<<14)
#define	RCC_C1_APB4ENR_LPTIM5EN				(0x1u<<12)
#define	RCC_C1_APB4ENR_LPTIM4EN				(0x1u<<11)
#define	RCC_C1_APB4ENR_LPTIM3EN				(0x1u<<10)
#define	RCC_C1_APB4ENR_LPTIM2EN				(0x1u<<9)
#define	RCC_C1_APB4ENR_I2C4EN				(0x1u<<7)
#define	RCC_C1_APB4ENR_SPI6EN				(0x1u<<5)
#define	RCC_C1_APB4ENR_LPUART1EN			(0x1u<<3)
#define	RCC_C1_APB4ENR_SYSCFGEN				(0x1u<<1)

// C1_AHB3LPENR Configuration

#define	RCC_C1_AHB3LPENR_AXISRAMLPEN		(0x1u<<31)
#define	RCC_C1_AHB3LPENR_ITCMLPEN			(0x1u<<30)
#define	RCC_C1_AHB3LPENR_DTCM2LPEN			(0x1u<<29)
#define	RCC_C1_AHB3LPENR_D1DTCM1LPEN		(0x1u<<28)
#define	RCC_C1_AHB3LPENR_SDMMC1LPEN			(0x1u<<16)
#define	RCC_C1_AHB3LPENR_QSPILPEN			(0x1u<<14)
#define	RCC_C1_AHB3LPENR_FMCLPEN			(0x1u<<12)
#define	RCC_C1_AHB3LPENR_FLITFLPEN			(0x1u<<8)
#define	RCC_C1_AHB3LPENR_JPGDECLPEN			(0x1u<<5)
#define	RCC_C1_AHB3LPENR_DMA2DLPEN			(0x1u<<4)
#define	RCC_C1_AHB3LPENR_MDMALPEN			(0x1u<<0)

// C1_AHB1LPENR Configuration

#define	RCC_C1_AHB1LPENR_USB2ULPILPEN		(0x1u<<28)
#define	RCC_C1_AHB1LPENR_USB2OTGLPEN		(0x1u<<27)
#define	RCC_C1_AHB1LPENR_USB1ULPILPEN		(0x1u<<26)
#define	RCC_C1_AHB1LPENR_USB1OTGLPEN		(0x1u<<25)
#define	RCC_C1_AHB1LPENR_ETH1RXLPEN			(0x1u<<17)
#define	RCC_C1_AHB1LPENR_ETH1TXLPEN			(0x1u<<16)
#define	RCC_C1_AHB1LPENR_ETH1MACLPEN		(0x1u<<15)
#define	RCC_C1_AHB1LPENR_ADC12LPEN			(0x1u<<5)
#define	RCC_C1_AHB1LPENR_DMA2LPEN			(0x1u<<1)
#define	RCC_C1_AHB1LPENR_DMA1LPEN			(0x1u<<0)

// C1_AHB2LPENR Configuration

#define	RCC_C1_AHB2LPENR_SRAM3LPEN			(0x1u<<31)
#define	RCC_C1_AHB2LPENR_SRAM2LPEN			(0x1u<<30)
#define	RCC_C1_AHB2LPENR_SRAM1LPEN			(0x1u<<29)
#define	RCC_C1_AHB2LPENR_RNGLPEN			(0x1u<<6)
#define	RCC_C1_AHB2LPENR_SDMMC2LPEN			(0x1u<<9)
#define	RCC_C1_AHB2LPENR_HASHLPEN			(0x1u<<5)
#define	RCC_C1_AHB2LPENR_CRYPTLPEN			(0x1u<<4)
#define	RCC_C1_AHB2LPENR_CAMITFLPEN			(0x1u<<0)

// C1_AHB4LPENR Configuration

#define	RCC_C1_AHB4LPENR_SRAM4LPEN			(0x1u<<29)
#define	RCC_C1_AHB4LPENR_BKPRAMLPEN			(0x1u<<28)
#define	RCC_C1_AHB4LPENR_ADC3LPEN			(0x1u<<24)
#define	RCC_C1_AHB4LPENR_BDMALPEN			(0x1u<<21)
#define	RCC_C1_AHB4LPENR_CRCLPEN			(0x1u<<19)
#define	RCC_C1_AHB4LPENR_GPIOKLPEN			(0x1u<<10)
#define	RCC_C1_AHB4LPENR_GPIOJLPEN			(0x1u<<9)
#define	RCC_C1_AHB4LPENR_GPIOILPEN			(0x1u<<8)
#define	RCC_C1_AHB4LPENR_GPIOHLPEN			(0x1u<<7)
#define	RCC_C1_AHB4LPENR_GPIOGLPEN			(0x1u<<6)
#define	RCC_C1_AHB4LPENR_GPIOFLPEN			(0x1u<<5)
#define	RCC_C1_AHB4LPENR_GPIOELPEN			(0x1u<<4)
#define	RCC_C1_AHB4LPENR_GPIODLPEN			(0x1u<<3)
#define	RCC_C1_AHB4LPENR_GPIOCLPEN			(0x1u<<2)
#define	RCC_C1_AHB4LPENR_GPIOBLPEN			(0x1u<<1)
#define	RCC_C1_AHB4LPENR_GPIOALPEN			(0x1u<<0)

// C1_APB3LPENR Configuration

#define	RCC_C1_APB3LPENR_WWDG1LPEN			(0x1u<<6)
#define	RCC_C1_APB3LPENR_LTDCLPEN			(0x1u<<3)

// C1_APB1LLPENR Configuration

#define	RCC_C1_APB1LLPENR_USART8LPEN		(0x1u<<31)
#define	RCC_C1_APB1LLPENR_USART7LPEN		(0x1u<<30)
#define	RCC_C1_APB1LLPENR_DAC12LPEN			(0x1u<<29)
#define	RCC_C1_APB1LLPENR_HDMICECLPEN		(0x1u<<27)
#define	RCC_C1_APB1LLPENR_I2C3LPEN			(0x1u<<23)
#define	RCC_C1_APB1LLPENR_I2C2LPEN			(0x1u<<22)
#define	RCC_C1_APB1LLPENR_I2C1LPEN			(0x1u<<21)
#define	RCC_C1_APB1LLPENR_UART5LPEN			(0x1u<<20)
#define	RCC_C1_APB1LLPENR_UART4LPEN			(0x1u<<19)
#define	RCC_C1_APB1LLPENR_USART3LPEN		(0x1u<<18)
#define	RCC_C1_APB1LLPENR_USART2LPEN		(0x1u<<17)
#define	RCC_C1_APB1LLPENR_SPDIFRXLPEN		(0x1u<<16)
#define	RCC_C1_APB1LLPENR_SPI3LPEN			(0x1u<<15)
#define	RCC_C1_APB1LLPENR_SPI2LPEN			(0x1u<<14)
#define	RCC_C1_APB1LLPENR_LPTIM1LPEN		(0x1u<<9)
#define	RCC_C1_APB1LLPENR_TIM14LPEN			(0x1u<<8)
#define	RCC_C1_APB1LLPENR_TIM13LPEN			(0x1u<<7)
#define	RCC_C1_APB1LLPENR_TIM12LPEN			(0x1u<<6)
#define	RCC_C1_APB1LLPENR_TIM7LPEN			(0x1u<<5)
#define	RCC_C1_APB1LLPENR_TIM6LPEN			(0x1u<<4)
#define	RCC_C1_APB1LLPENR_TIM5LPEN			(0x1u<<3)
#define	RCC_C1_APB1LLPENR_TIM4LPEN			(0x1u<<2)
#define	RCC_C1_APB1LLPENR_TIM3LPEN			(0x1u<<1)
#define	RCC_C1_APB1LLPENR_TIM2LPEN			(0x1u<<0)

// C1_APB1HLPENR Configuration

#define	RCC_C1_APB1HLPENR_FDCANLPEN			(0x1u<<8)
#define	RCC_C1_APB1HLPENR_MDIOSLPEN			(0x1u<<5)
#define	RCC_C1_APB1HLPENR_OPAMPLPEN			(0x1u<<4)
#define	RCC_C1_APB1HLPENR_SWPLPEN			(0x1u<<2)
#define	RCC_C1_APB1HLPENR_CRSLPEN			(0x1u<<1)

// C1_APB2LPENR Configuration

#define	RCC_C1_APB2LPENR_HRTIMLPEN			(0x1u<<29)
#define	RCC_C1_APB2LPENR_DFSDM1LPEN			(0x1u<<28)
#define	RCC_C1_APB2LPENR_SAI3LPEN			(0x1u<<24)
#define	RCC_C1_APB2LPENR_SAI2LPEN			(0x1u<<23)
#define	RCC_C1_APB2LPENR_SAI1LPEN			(0x1u<<22)
#define	RCC_C1_APB2LPENR_SPI5LPEN			(0x1u<<20)
#define	RCC_C1_APB2LPENR_TIM17LPEN			(0x1u<<18)
#define	RCC_C1_APB2LPENR_TIM16LPEN			(0x1u<<17)
#define	RCC_C1_APB2LPENR_TIM15LPEN			(0x1u<<16)
#define	RCC_C1_APB2LPENR_SPI4LPEN			(0x1u<<13)
#define	RCC_C1_APB2LPENR_SPI1LPEN			(0x1u<<12)
#define	RCC_C1_APB2LPENR_USART6LPEN			(0x1u<<5)
#define	RCC_C1_APB2LPENR_USART1LPEN			(0x1u<<4)
#define	RCC_C1_APB2LPENR_TIM8LPEN			(0x1u<<1)
#define	RCC_C1_APB2LPENR_TIM1LPEN			(0x1u<<0)

// C1_APB4LPENR Configuration

#define	RCC_C1_APB4LPENR_SAI4LPEN			(0x1u<<21)
#define	RCC_C1_APB4LPENR_RTCAPBLPEN			(0x1u<<16)
#define	RCC_C1_APB4LPENR_VREFLPEN			(0x1u<<15)
#define	RCC_C1_APB4LPENR_COMP12LPEN			(0x1u<<14)
#define	RCC_C1_APB4LPENR_LPTIM5LPEN			(0x1u<<12)
#define	RCC_C1_APB4LPENR_LPTIM4LPEN			(0x1u<<11)
#define	RCC_C1_APB4LPENR_LPTIM3LPEN			(0x1u<<10)
#define	RCC_C1_APB4LPENR_LPTIM2LPEN			(0x1u<<9)
#define	RCC_C1_APB4LPENR_I2C4LPEN			(0x1u<<7)
#define	RCC_C1_APB4LPENR_SPI6LPEN			(0x1u<<5)
#define	RCC_C1_APB4LPENR_LPUART1LPEN		(0x1u<<3)
#define	RCC_C1_APB4LPENR_SYSCFGLPEN			(0x1u<<1)
