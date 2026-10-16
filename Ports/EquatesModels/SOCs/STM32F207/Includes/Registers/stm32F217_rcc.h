/*
; stm32F217_rcc.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_rcc equates.
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
	volatile	uint32_t	PLLCFGR;
	volatile	uint32_t	CFGR;
	volatile	uint32_t	CIR;
	volatile	uint32_t	AHB1RSTR;
	volatile	uint32_t	AHB2RSTR;
	volatile	uint32_t	AHB3RSTR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	APB1RSTR;
	volatile	uint32_t	APB2RSTR;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	AHB1ENR;
	volatile	uint32_t	AHB2ENR;
	volatile	uint32_t	AHB3ENR;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	APB1ENR;
	volatile	uint32_t	APB2ENR;
	volatile	uint32_t	RESERVED3[2];
	volatile	uint32_t	AHB1LPENR;
	volatile	uint32_t	AHB2LPENR;
	volatile	uint32_t	AHB3LPENR;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	APB1LPENR;
	volatile	uint32_t	APB2LPENR;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	BDCR;
	volatile	uint32_t	CSR;
	volatile	uint32_t	RESERVED6[2];
	volatile	uint32_t	SSCGR;
	volatile	uint32_t	PLLI2SCFGR;
} RCC_TypeDef;

#if (defined(__cplusplus))
#define	RCC	reinterpret_cast<RCC_TypeDef *>(0x40023800u)

#else
#define	RCC	((RCC_TypeDef *)0x40023800u)
#endif

// CR Configuration

#define	RCC_CR_HSION				(0x1u<<0)
#define	RCC_CR_HSIRDY				(0x1u<<1)
#define	RCC_CR_HSITRIM				(0x1Fu<<3)
#define	RCC_CR_HSITRIM_0			(0x1u<<3)
#define	RCC_CR_HSICAL				(0xFFu<<8)
#define	RCC_CR_HSICAL_0				(0x1u<<8)
#define	RCC_CR_HSEON				(0x1u<<16)
#define	RCC_CR_HSERDY				(0x1u<<17)
#define	RCC_CR_HSEBYP				(0x1u<<18)
#define	RCC_CR_CSSON				(0x1u<<19)
#define	RCC_CR_PLLON				(0x1u<<24)
#define	RCC_CR_PLLRDY				(0x1u<<25)
#define	RCC_CR_PLLI2SON				(0x1u<<26)
#define	RCC_CR_PLLI2SRDY			(0x1u<<27)

// PLLCFGR Configuration

#define	RCC_PLLCFGR_PLLM0			(0x1u<<0)
#define	RCC_PLLCFGR_PLLM1			(0x1u<<1)
#define	RCC_PLLCFGR_PLLM2			(0x1u<<2)
#define	RCC_PLLCFGR_PLLM3			(0x1u<<3)
#define	RCC_PLLCFGR_PLLM4			(0x1u<<4)
#define	RCC_PLLCFGR_PLLM5			(0x1u<<5)
#define	RCC_PLLCFGR_PLLN0			(0x1u<<6)
#define	RCC_PLLCFGR_PLLN1			(0x1u<<7)
#define	RCC_PLLCFGR_PLLN2			(0x1u<<8)
#define	RCC_PLLCFGR_PLLN3			(0x1u<<9)
#define	RCC_PLLCFGR_PLLN4			(0x1u<<10)
#define	RCC_PLLCFGR_PLLN5			(0x1u<<11)
#define	RCC_PLLCFGR_PLLN6			(0x1u<<12)
#define	RCC_PLLCFGR_PLLN7			(0x1u<<13)
#define	RCC_PLLCFGR_PLLN8			(0x1u<<14)
#define	RCC_PLLCFGR_PLLP0			(0x1u<<16)
#define	RCC_PLLCFGR_PLLP1			(0x1u<<17)
#define	RCC_PLLCFGR_PLLSRC			(0x1u<<22)
#define	RCC_PLLCFGR_PLLQ0			(0x1u<<24)
#define	RCC_PLLCFGR_PLLQ1			(0x1u<<25)
#define	RCC_PLLCFGR_PLLQ2			(0x1u<<26)
#define	RCC_PLLCFGR_PLLQ3			(0x1u<<27)

// CFGR Configuration

#define	RCC_CFGR_SW0				(0x1u<<0)
#define	RCC_CFGR_SW1				(0x1u<<1)
#define	RCC_CFGR_SWS0				(0x1u<<2)
#define	RCC_CFGR_SWS1				(0x1u<<3)
#define	RCC_CFGR_HPRE0				(0x1u<<4)
#define	RCC_CFGR_HPRE1				(0x1u<<5)
#define	RCC_CFGR_HPRE2				(0x1u<<6)
#define	RCC_CFGR_HPRE3				(0x1u<<7)
#define	RCC_CFGR_PPRE10				(0x1u<<10)
#define	RCC_CFGR_PPRE11				(0x1u<<11)
#define	RCC_CFGR_PPRE12				(0x1u<<12)
#define	RCC_CFGR_PPRE20				(0x1u<<13)
#define	RCC_CFGR_PPRE21				(0x1u<<14)
#define	RCC_CFGR_PPRE22				(0x1u<<15)
#define	RCC_CFGR_RTCPRE0			(0x1u<<16)
#define	RCC_CFGR_RTCPRE1			(0x1u<<17)
#define	RCC_CFGR_RTCPRE2			(0x1u<<18)
#define	RCC_CFGR_RTCPRE3			(0x1u<<19)
#define	RCC_CFGR_RTCPRE4			(0x1u<<20)
#define	RCC_CFGR_MCO10				(0x1u<<21)
#define	RCC_CFGR_MCO11				(0x1u<<22)
#define	RCC_CFGR_I2SSRC				(0x1u<<23)
#define	RCC_CFGR_MCO1PRE0			(0x1u<<24)
#define	RCC_CFGR_MCO1PRE1			(0x1u<<25)
#define	RCC_CFGR_MCO1PRE2			(0x1u<<26)
#define	RCC_CFGR_MCO2PRE0			(0x1u<<27)
#define	RCC_CFGR_MCO2PRE1			(0x1u<<28)
#define	RCC_CFGR_MCO2PRE2			(0x1u<<29)
#define	RCC_CFGR_MCO20				(0x1u<<30)
#define	RCC_CFGR_MCO21				(0x1u<<31)

// CIR Configuration

#define	RCC_CIR_LSIRDYF				(0x1u<<0)
#define	RCC_CIR_LSERDYF				(0x1u<<1)
#define	RCC_CIR_HSIRDYF				(0x1u<<2)
#define	RCC_CIR_HSERDYF				(0x1u<<3)
#define	RCC_CIR_PLLRDYF				(0x1u<<4)
#define	RCC_CIR_PLLI2SRDYF			(0x1u<<5)
#define	RCC_CIR_CSSF				(0x1u<<7)
#define	RCC_CIR_LSIRDYIE			(0x1u<<8)
#define	RCC_CIR_LSERDYIE			(0x1u<<9)
#define	RCC_CIR_HSIRDYIE			(0x1u<<10)
#define	RCC_CIR_HSERDYIE			(0x1u<<11)
#define	RCC_CIR_PLLRDYIE			(0x1u<<12)
#define	RCC_CIR_PLLI2SRDYIE			(0x1u<<13)
#define	RCC_CIR_LSIRDYC				(0x1u<<16)
#define	RCC_CIR_LSERDYC				(0x1u<<17)
#define	RCC_CIR_HSIRDYC				(0x1u<<18)
#define	RCC_CIR_HSERDYC				(0x1u<<19)
#define	RCC_CIR_PLLRDYC				(0x1u<<20)
#define	RCC_CIR_PLLI2SRDYC			(0x1u<<21)
#define	RCC_CIR_CSSC				(0x1u<<23)

// AHB1RSTR Configuration

#define	RCC_AHB1RSTR_GPIOARST		(0x1u<<0)
#define	RCC_AHB1RSTR_GPIOBRST		(0x1u<<1)
#define	RCC_AHB1RSTR_GPIOCRST		(0x1u<<2)
#define	RCC_AHB1RSTR_GPIODRST		(0x1u<<3)
#define	RCC_AHB1RSTR_GPIOERST		(0x1u<<4)
#define	RCC_AHB1RSTR_GPIOFRST		(0x1u<<5)
#define	RCC_AHB1RSTR_GPIOGRST		(0x1u<<6)
#define	RCC_AHB1RSTR_GPIOHRST		(0x1u<<7)
#define	RCC_AHB1RSTR_GPIOIRST		(0x1u<<8)
#define	RCC_AHB1RSTR_CRCRST			(0x1u<<12)
#define	RCC_AHB1RSTR_DMA1RST		(0x1u<<21)
#define	RCC_AHB1RSTR_DMA2RST		(0x1u<<22)
#define	RCC_AHB1RSTR_ETHMACRST		(0x1u<<25)
#define	RCC_AHB1RSTR_OTGHSRST		(0x1u<<29)

// AHB2RSTR Configuration

#define	RCC_AHB2RSTR_DCMIRST		(0x1u<<0)
#define	RCC_AHB2RSTR_CRYPRST		(0x1u<<4)
#define	RCC_AHB2RSTR_HSAHRST		(0x1u<<5)
#define	RCC_AHB2RSTR_RNGRST			(0x1u<<6)
#define	RCC_AHB2RSTR_OTGFSRST		(0x1u<<7)

// AHB3RSTR Configuration

#define	RCC_AHB3RSTR_FSMCRST		(0x1u<<0)

// APB1RSTR Configuration

#define	RCC_APB1RSTR_TIM2RST		(0x1u<<0)
#define	RCC_APB1RSTR_TIM3RST		(0x1u<<1)
#define	RCC_APB1RSTR_TIM4RST		(0x1u<<2)
#define	RCC_APB1RSTR_TIM5RST		(0x1u<<3)
#define	RCC_APB1RSTR_TIM6RST		(0x1u<<4)
#define	RCC_APB1RSTR_TIM7RST		(0x1u<<5)
#define	RCC_APB1RSTR_TIM12RST		(0x1u<<6)
#define	RCC_APB1RSTR_TIM13RST		(0x1u<<7)
#define	RCC_APB1RSTR_TIM14RST		(0x1u<<8)
#define	RCC_APB1RSTR_WWDGRST		(0x1u<<11)
#define	RCC_APB1RSTR_SPI2RST		(0x1u<<14)
#define	RCC_APB1RSTR_SPI3RST		(0x1u<<15)
#define	RCC_APB1RSTR_UART2RST		(0x1u<<17)
#define	RCC_APB1RSTR_UART3RST		(0x1u<<18)
#define	RCC_APB1RSTR_UART4RST		(0x1u<<19)
#define	RCC_APB1RSTR_UART5RST		(0x1u<<20)
#define	RCC_APB1RSTR_I2C1RST		(0x1u<<21)
#define	RCC_APB1RSTR_I2C2RST		(0x1u<<22)
#define	RCC_APB1RSTR_I2C3RST		(0x1u<<23)
#define	RCC_APB1RSTR_CAN1RST		(0x1u<<25)
#define	RCC_APB1RSTR_CAN2RST		(0x1u<<26)
#define	RCC_APB1RSTR_PWRRST			(0x1u<<28)
#define	RCC_APB1RSTR_DACRST			(0x1u<<29)

// APB2RSTR Configuration

#define	RCC_APB2RSTR_TIM1RST		(0x1u<<0)
#define	RCC_APB2RSTR_TIM8RST		(0x1u<<1)
#define	RCC_APB2RSTR_USART1RST		(0x1u<<4)
#define	RCC_APB2RSTR_USART6RST		(0x1u<<5)
#define	RCC_APB2RSTR_ADCRST			(0x1u<<8)
#define	RCC_APB2RSTR_SDIORST		(0x1u<<11)
#define	RCC_APB2RSTR_SPI1RST		(0x1u<<12)
#define	RCC_APB2RSTR_SYSCFGRST		(0x1u<<14)
#define	RCC_APB2RSTR_TIM9RST		(0x1u<<16)
#define	RCC_APB2RSTR_TIM10RST		(0x1u<<17)
#define	RCC_APB2RSTR_TIM11RST		(0x1u<<18)

// AHB1ENR Configuration

#define	RCC_AHB1ENR_GPIOAEN			(0x1u<<0)
#define	RCC_AHB1ENR_GPIOBEN			(0x1u<<1)
#define	RCC_AHB1ENR_GPIOCEN			(0x1u<<2)
#define	RCC_AHB1ENR_GPIODEN			(0x1u<<3)
#define	RCC_AHB1ENR_GPIOEEN			(0x1u<<4)
#define	RCC_AHB1ENR_GPIOFEN			(0x1u<<5)
#define	RCC_AHB1ENR_GPIOGEN			(0x1u<<6)
#define	RCC_AHB1ENR_GPIOHEN			(0x1u<<7)
#define	RCC_AHB1ENR_GPIOIEN			(0x1u<<8)
#define	RCC_AHB1ENR_CRCEN			(0x1u<<12)
#define	RCC_AHB1ENR_BKPSRAMEN		(0x1u<<18)
#define	RCC_AHB1ENR_DMA1EN			(0x1u<<21)
#define	RCC_AHB1ENR_DMA2EN			(0x1u<<22)
#define	RCC_AHB1ENR_ETHMACEN		(0x1u<<25)
#define	RCC_AHB1ENR_ETHMACTXEN		(0x1u<<26)
#define	RCC_AHB1ENR_ETHMACRXEN		(0x1u<<27)
#define	RCC_AHB1ENR_ETHMACPTPEN		(0x1u<<28)
#define	RCC_AHB1ENR_OTGHSEN			(0x1u<<29)
#define	RCC_AHB1ENR_OTGHSULPIEN		(0x1u<<30)

// AHB2ENR Configuration

#define	RCC_AHB2ENR_DCMIEN			(0x1u<<0)
#define	RCC_AHB2ENR_CRYPEN			(0x1u<<4)
#define	RCC_AHB2ENR_HASHEN			(0x1u<<5)
#define	RCC_AHB2ENR_RNGEN			(0x1u<<6)
#define	RCC_AHB2ENR_OTGFSEN			(0x1u<<7)

// AHB3ENR Configuration

#define	RCC_AHB3ENR_FSMCEN			(0x1u<<0)

// APB1ENR Configuration

#define	RCC_APB1ENR_TIM2EN			(0x1u<<0)
#define	RCC_APB1ENR_TIM3EN			(0x1u<<1)
#define	RCC_APB1ENR_TIM4EN			(0x1u<<2)
#define	RCC_APB1ENR_TIM5EN			(0x1u<<3)
#define	RCC_APB1ENR_TIM6EN			(0x1u<<4)
#define	RCC_APB1ENR_TIM7EN			(0x1u<<5)
#define	RCC_APB1ENR_TIM12EN			(0x1u<<6)
#define	RCC_APB1ENR_TIM13EN			(0x1u<<7)
#define	RCC_APB1ENR_TIM14EN			(0x1u<<8)
#define	RCC_APB1ENR_WWDGEN			(0x1u<<11)
#define	RCC_APB1ENR_SPI2EN			(0x1u<<14)
#define	RCC_APB1ENR_SPI3EN			(0x1u<<15)
#define	RCC_APB1ENR_USART2EN		(0x1u<<17)
#define	RCC_APB1ENR_USART3EN		(0x1u<<18)
#define	RCC_APB1ENR_UART4EN			(0x1u<<19)
#define	RCC_APB1ENR_UART5EN			(0x1u<<20)
#define	RCC_APB1ENR_I2C1EN			(0x1u<<21)
#define	RCC_APB1ENR_I2C2EN			(0x1u<<22)
#define	RCC_APB1ENR_I2C3EN			(0x1u<<23)
#define	RCC_APB1ENR_CAN1EN			(0x1u<<25)
#define	RCC_APB1ENR_CAN2EN			(0x1u<<26)
#define	RCC_APB1ENR_PWREN			(0x1u<<28)
#define	RCC_APB1ENR_DACEN			(0x1u<<29)

// APB2ENR Configuration

#define	RCC_APB2ENR_TIM1EN			(0x1u<<0)
#define	RCC_APB2ENR_TIM8EN			(0x1u<<1)
#define	RCC_APB2ENR_USART1EN		(0x1u<<4)
#define	RCC_APB2ENR_USART6EN		(0x1u<<5)
#define	RCC_APB2ENR_ADC1EN			(0x1u<<8)
#define	RCC_APB2ENR_ADC2EN			(0x1u<<9)
#define	RCC_APB2ENR_ADC3EN			(0x1u<<10)
#define	RCC_APB2ENR_SDIOEN			(0x1u<<11)
#define	RCC_APB2ENR_SPI1EN			(0x1u<<12)
#define	RCC_APB2ENR_SYSCFGEN		(0x1u<<14)
#define	RCC_APB2ENR_TIM9EN			(0x1u<<16)
#define	RCC_APB2ENR_TIM10EN			(0x1u<<17)
#define	RCC_APB2ENR_TIM11EN			(0x1u<<18)

// AHB1LPENR Configuration

#define	RCC_AHB1LPENR_GPIOALPEN		(0x1u<<0)
#define	RCC_AHB1LPENR_GPIOBLPEN		(0x1u<<1)
#define	RCC_AHB1LPENR_GPIOCLPEN		(0x1u<<2)
#define	RCC_AHB1LPENR_GPIODLPEN		(0x1u<<3)
#define	RCC_AHB1LPENR_GPIOELPEN		(0x1u<<4)
#define	RCC_AHB1LPENR_GPIOFLPEN		(0x1u<<5)
#define	RCC_AHB1LPENR_GPIOGLPEN		(0x1u<<6)
#define	RCC_AHB1LPENR_GPIOHLPEN		(0x1u<<7)
#define	RCC_AHB1LPENR_GPIOILPEN		(0x1u<<8)
#define	RCC_AHB1LPENR_CRCLPEN		(0x1u<<12)
#define	RCC_AHB1LPENR_FLITFLPEN		(0x1u<<15)
#define	RCC_AHB1LPENR_SRAM1LPEN		(0x1u<<16)
#define	RCC_AHB1LPENR_SRAM2LPEN		(0x1u<<17)
#define	RCC_AHB1LPENR_BKPSRAMLPEN	(0x1u<<18)
#define	RCC_AHB1LPENR_DMA1LPEN		(0x1u<<21)
#define	RCC_AHB1LPENR_DMA2LPEN		(0x1u<<22)
#define	RCC_AHB1LPENR_ETHMACLPEN	(0x1u<<25)
#define	RCC_AHB1LPENR_ETHMACTXLPEN	(0x1u<<26)
#define	RCC_AHB1LPENR_ETHMACRXLPEN	(0x1u<<27)
#define	RCC_AHB1LPENR_ETHMACPTPLPEN	(0x1u<<28)
#define	RCC_AHB1LPENR_OTGHSLPEN		(0x1u<<29)
#define	RCC_AHB1LPENR_OTGHSULPILPEN	(0x1u<<30)

// AHB2LPENR Configuration

#define	RCC_AHB2LPENR_DCMILPEN		(0x1u<<0)
#define	RCC_AHB2LPENR_CRYPLPEN		(0x1u<<4)
#define	RCC_AHB2LPENR_HASHLPEN		(0x1u<<5)
#define	RCC_AHB2LPENR_RNGLPEN		(0x1u<<6)
#define	RCC_AHB2LPENR_OTGFSLPEN		(0x1u<<7)

// AHB3LPENR Configuration

#define	RCC_AHB3LPENR_FSMCLPEN		(0x1u<<0)

// APB1LPENR Configuration

#define	RCC_APB1LPENR_TIM2LPEN		(0x1u<<0)
#define	RCC_APB1LPENR_TIM3LPEN		(0x1u<<1)
#define	RCC_APB1LPENR_TIM4LPEN		(0x1u<<2)
#define	RCC_APB1LPENR_TIM5LPEN		(0x1u<<3)
#define	RCC_APB1LPENR_TIM6LPEN		(0x1u<<4)
#define	RCC_APB1LPENR_TIM7LPEN		(0x1u<<5)
#define	RCC_APB1LPENR_TIM12LPEN		(0x1u<<6)
#define	RCC_APB1LPENR_TIM13LPEN		(0x1u<<7)
#define	RCC_APB1LPENR_TIM14LPEN		(0x1u<<8)
#define	RCC_APB1LPENR_WWDGLPEN		(0x1u<<11)
#define	RCC_APB1LPENR_SPI2LPEN		(0x1u<<14)
#define	RCC_APB1LPENR_SPI3LPEN		(0x1u<<15)
#define	RCC_APB1LPENR_USART2LPEN	(0x1u<<17)
#define	RCC_APB1LPENR_USART3LPEN	(0x1u<<18)
#define	RCC_APB1LPENR_UART4LPEN		(0x1u<<19)
#define	RCC_APB1LPENR_UART5LPEN		(0x1u<<20)
#define	RCC_APB1LPENR_I2C1LPEN		(0x1u<<21)
#define	RCC_APB1LPENR_I2C2LPEN		(0x1u<<22)
#define	RCC_APB1LPENR_I2C3LPEN		(0x1u<<23)
#define	RCC_APB1LPENR_CAN1LPEN		(0x1u<<25)
#define	RCC_APB1LPENR_CAN2LPEN		(0x1u<<26)
#define	RCC_APB1LPENR_PWRLPEN		(0x1u<<28)
#define	RCC_APB1LPENR_DACLPEN		(0x1u<<29)

// APB2LPENR Configuration

#define	RCC_APB2LPENR_TIM1LPEN		(0x1u<<0)
#define	RCC_APB2LPENR_TIM8LPEN		(0x1u<<1)
#define	RCC_APB2LPENR_USART1LPEN	(0x1u<<4)
#define	RCC_APB2LPENR_USART6LPEN	(0x1u<<5)
#define	RCC_APB2LPENR_ADC1LPEN		(0x1u<<8)
#define	RCC_APB2LPENR_ADC2LPEN		(0x1u<<9)
#define	RCC_APB2LPENR_ADC3LPEN		(0x1u<<10)
#define	RCC_APB2LPENR_SDIOLPEN		(0x1u<<11)
#define	RCC_APB2LPENR_SPI1LPEN		(0x1u<<12)
#define	RCC_APB2LPENR_SYSCFGLPEN	(0x1u<<14)
#define	RCC_APB2LPENR_TIM9LPEN		(0x1u<<16)
#define	RCC_APB2LPENR_TIM10LPEN		(0x1u<<17)
#define	RCC_APB2LPENR_TIM11LPEN		(0x1u<<18)

// BDCR Configuration

#define	RCC_BDCR_LSEON				(0x1u<<0)
#define	RCC_BDCR_LSERDY				(0x1u<<1)
#define	RCC_BDCR_LSEBYP				(0x1u<<2)
#define	RCC_BDCR_RTCSEL0			(0x1u<<8)
#define	RCC_BDCR_RTCSEL1			(0x1u<<9)
#define	RCC_BDCR_RTCEN				(0x1u<<15)
#define	RCC_BDCR_BDRST				(0x1u<<16)

// CSR Configuration

#define	RCC_CSR_LSION				(0x1u<<0)
#define	RCC_CSR_LSIRDY				(0x1u<<1)
#define	RCC_CSR_RMVF				(0x1u<<24)
#define	RCC_CSR_BORRSTF				(0x1u<<25)
#define	RCC_CSR_PADRSTF				(0x1u<<26)
#define	RCC_CSR_PORRSTF				(0x1u<<27)
#define	RCC_CSR_SFTRSTF				(0x1u<<28)
#define	RCC_CSR_WDGRSTF				(0x1u<<29)
#define	RCC_CSR_WWDGRSTF			(0x1u<<30)
#define	RCC_CSR_LPWRRSTF			(0x1u<<31)

// SSCGR Configuration

#define	RCC_SSCGR_MODPER			(0x1FFFu<<0)
#define	RCC_SSCGR_MODPER_0			(0x1u<<0)
#define	RCC_SSCGR_INCSTEP			(0x7FFFu<<13)
#define	RCC_SSCGR_INCSTEP_0			(0x1u<<13)
#define	RCC_SSCGR_SPREADSEL			(0x1u<<30)
#define	RCC_SSCGR_SSCGEN			(0x1u<<31)

// PLLI2SCFGR Configuration

#define	RCC_PLLI2SCFGR_PLLI2SR2		(0x1u<<30)
#define	RCC_PLLI2SCFGR_PLLI2SR1		(0x1u<<29)
#define	RCC_PLLI2SCFGR_PLLI2SR0		(0x1u<<28)
#define	RCC_PLLI2SCFGR_PLLI2SN8		(0x1u<<14)
#define	RCC_PLLI2SCFGR_PLLI2SN7		(0x1u<<13)
#define	RCC_PLLI2SCFGR_PLLI2SN6		(0x1u<<12)
#define	RCC_PLLI2SCFGR_PLLI2SN5		(0x1u<<11)
#define	RCC_PLLI2SCFGR_PLLI2SN4		(0x1u<<10)
#define	RCC_PLLI2SCFGR_PLLI2SN3		(0x1u<<9)
#define	RCC_PLLI2SCFGR_PLLI2SN2		(0x1u<<8)
#define	RCC_PLLI2SCFGR_PLLI2SN1		(0x1u<<7)
#define	RCC_PLLI2SCFGR_PLLI2SN0		(0x1u<<6)
