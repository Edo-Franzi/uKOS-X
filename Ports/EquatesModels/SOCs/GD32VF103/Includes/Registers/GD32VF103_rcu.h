/*
; GD32VF103_rcu.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_rcu equates.
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

// RCU address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CTL;
	volatile	uint32_t	CFG0;
	volatile	uint32_t	INT;
	volatile	uint32_t	APB2RST;
	volatile	uint32_t	APB1RST;
	volatile	uint32_t	AHBEN;
	volatile	uint32_t	APB2EN;
	volatile	uint32_t	APB1EN;
	volatile	uint32_t	BDCTL;
	volatile	uint32_t	RSTSCK;
	volatile	uint32_t	AHBRST;
	volatile	uint32_t	CFG1;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	DSV;
} RCU_TypeDef;

#if (defined(__cplusplus))
#define	RCU	reinterpret_cast<RCU_TypeDef *>(0x40021000u)

#else
#define	RCU	((RCU_TypeDef *)0x40021000u)
#endif

// CTL Configuration

#define	RCU_CTL_PLL2STB			(0x1u<<29)
#define	RCU_CTL_PLL2EN			(0x1u<<28)
#define	RCU_CTL_PLL1STB			(0x1u<<27)
#define	RCU_CTL_PLL1EN			(0x1u<<26)
#define	RCU_CTL_PLLSTB			(0x1u<<25)
#define	RCU_CTL_PLLEN			(0x1u<<24)
#define	RCU_CTL_CKMEN			(0x1u<<19)
#define	RCU_CTL_HXTALBPS		(0x1u<<18)
#define	RCU_CTL_HXTALSTB		(0x1u<<17)
#define	RCU_CTL_HXTALEN			(0x1u<<16)
#define	RCU_CTL_IRC8MCALIB		(0xFFu<<8)
#define	RCU_CTL_IRC8MCALIB_0	(0x1u<<8)
#define	RCU_CTL_IRC8MADJ		(0x1Fu<<3)
#define	RCU_CTL_IRC8MADJ_0		(0x1u<<3)
#define	RCU_CTL_IRC8MSTB		(0x1u<<1)
#define	RCU_CTL_IRC8MEN			(0x1u<<0)

// CFG0 Configuration

#define	RCU_CFG0_PLLMF_4		(0x1u<<29)
#define	RCU_CFG0_ADCPSC_2		(0x1u<<28)
#define	RCU_CFG0_CKOUT0SEL		(0xFu<<24)
#define	RCU_CFG0_CKOUT0SEL_0	(0x1u<<24)
#define	RCU_CFG0_USBFSPSC		(0x3u<<22)
#define	RCU_CFG0_USBFSPSC_0		(0x1u<<22)
#define	RCU_CFG0_PLLMF_3_0		(0xFu<<18)
#define	RCU_CFG0_PLLMF_3_0_0	(0x1u<<18)
#define	RCU_CFG0_PREDV0_LSB		(0x1u<<17)
#define	RCU_CFG0_PLLSEL			(0x1u<<16)
#define	RCU_CFG0_ADCPSC_1_0		(0x3u<<14)
#define	RCU_CFG0_ADCPSC_1_0_0	(0x1u<<14)
#define	RCU_CFG0_APB2PSC		(0x7u<<11)
#define	RCU_CFG0_APB2PSC_0		(0x1u<<11)
#define	RCU_CFG0_APB1PSC		(0x7u<<8)
#define	RCU_CFG0_APB1PSC_0		(0x1u<<8)
#define	RCU_CFG0_AHBPSC			(0xFu<<4)
#define	RCU_CFG0_AHBPSC_0		(0x1u<<4)
#define	RCU_CFG0_SCSS			(0x3u<<2)
#define	RCU_CFG0_SCSS_0			(0x1u<<2)
#define	RCU_CFG0_SCS			(0x3u<<0)
#define	RCU_CFG0_SCS_0			(0x1u<<0)

// INT Configuration

#define	RCU_INT_CKMIC			(0x1u<<23)
#define	RCU_INT_PLL2STBIC		(0x1u<<22)
#define	RCU_INT_PLL1STBIC		(0x1u<<21)
#define	RCU_INT_PLLSTBIC		(0x1u<<20)
#define	RCU_INT_HXTALSTBIC		(0x1u<<19)
#define	RCU_INT_IRC8MSTBIC		(0x1u<<18)
#define	RCU_INT_LXTALSTBIC		(0x1u<<17)
#define	RCU_INT_IRC40KSTBIC		(0x1u<<16)
#define	RCU_INT_PLL2STBIE		(0x1u<<14)
#define	RCU_INT_PLL1STBIE		(0x1u<<13)
#define	RCU_INT_PLLSTBIE		(0x1u<<12)
#define	RCU_INT_HXTALSTBIE		(0x1u<<11)
#define	RCU_INT_IRC8MSTBIE		(0x1u<<10)
#define	RCU_INT_LXTALSTBIE		(0x1u<<9)
#define	RCU_INT_IRC40KSTBIE		(0x1u<<8)
#define	RCU_INT_CKMIF			(0x1u<<7)
#define	RCU_INT_PLL2STBIF		(0x1u<<6)
#define	RCU_INT_PLL1STBIF		(0x1u<<5)
#define	RCU_INT_PLLSTBIF		(0x1u<<4)
#define	RCU_INT_HXTALSTBIF		(0x1u<<3)
#define	RCU_INT_IRC8MSTBIF		(0x1u<<2)
#define	RCU_INT_LXTALSTBIF		(0x1u<<1)
#define	RCU_INT_IRC40KSTBIF		(0x1u<<0)

// APB2RST Configuration

#define	RCU_APB2RST_USART0RST	(0x1u<<14)
#define	RCU_APB2RST_SPI0RST		(0x1u<<12)
#define	RCU_APB2RST_TIMER0RST	(0x1u<<11)
#define	RCU_APB2RST_ADC1RST		(0x1u<<10)
#define	RCU_APB2RST_ADC0RST		(0x1u<<9)
#define	RCU_APB2RST_PERST		(0x1u<<6)
#define	RCU_APB2RST_PDRST		(0x1u<<5)
#define	RCU_APB2RST_PCRST		(0x1u<<4)
#define	RCU_APB2RST_PBRST		(0x1u<<3)
#define	RCU_APB2RST_PARST		(0x1u<<2)
#define	RCU_APB2RST_AFRST		(0x1u<<0)

// APB1RST Configuration

#define	RCU_APB1RST_DACRST		(0x1u<<29)
#define	RCU_APB1RST_PMURST		(0x1u<<28)
#define	RCU_APB1RST_BKPIRST		(0x1u<<27)
#define	RCU_APB1RST_CAN1RST		(0x1u<<26)
#define	RCU_APB1RST_CAN0RST		(0x1u<<25)
#define	RCU_APB1RST_I2C1RST		(0x1u<<22)
#define	RCU_APB1RST_I2C0RST		(0x1u<<21)
#define	RCU_APB1RST_UART4RST	(0x1u<<20)
#define	RCU_APB1RST_UART3RST	(0x1u<<19)
#define	RCU_APB1RST_USART2RST	(0x1u<<18)
#define	RCU_APB1RST_USART1RST	(0x1u<<17)
#define	RCU_APB1RST_SPI2RST		(0x1u<<15)
#define	RCU_APB1RST_SPI1RST		(0x1u<<14)
#define	RCU_APB1RST_WWDGTRST	(0x1u<<11)
#define	RCU_APB1RST_TIMER6RST	(0x1u<<5)
#define	RCU_APB1RST_TIMER5RST	(0x1u<<4)
#define	RCU_APB1RST_TIMER4RST	(0x1u<<3)
#define	RCU_APB1RST_TIMER3RST	(0x1u<<2)
#define	RCU_APB1RST_TIMER2RST	(0x1u<<1)
#define	RCU_APB1RST_TIMER1RST	(0x1u<<0)

// AHBEN Configuration

#define	RCU_AHBEN_USBFSEN		(0x1u<<12)
#define	RCU_AHBEN_EXMCEN		(0x1u<<8)
#define	RCU_AHBEN_CRCEN			(0x1u<<6)
#define	RCU_AHBEN_FMCSPEN		(0x1u<<4)
#define	RCU_AHBEN_SRAMSPEN		(0x1u<<2)
#define	RCU_AHBEN_DMA1EN		(0x1u<<1)
#define	RCU_AHBEN_DMA0EN		(0x1u<<0)

// APB2EN Configuration

#define	RCU_APB2EN_USART0EN		(0x1u<<14)
#define	RCU_APB2EN_SPI0EN		(0x1u<<12)
#define	RCU_APB2EN_TIMER0EN		(0x1u<<11)
#define	RCU_APB2EN_ADC1EN		(0x1u<<10)
#define	RCU_APB2EN_ADC0EN		(0x1u<<9)
#define	RCU_APB2EN_PEEN			(0x1u<<6)
#define	RCU_APB2EN_PDEN			(0x1u<<5)
#define	RCU_APB2EN_PCEN			(0x1u<<4)
#define	RCU_APB2EN_PBEN			(0x1u<<3)
#define	RCU_APB2EN_PAEN			(0x1u<<2)
#define	RCU_APB2EN_AFEN			(0x1u<<0)

// APB1EN Configuration

#define	RCU_APB1EN_DACEN		(0x1u<<29)
#define	RCU_APB1EN_PMUEN		(0x1u<<28)
#define	RCU_APB1EN_BKPIEN		(0x1u<<27)
#define	RCU_APB1EN_CAN1EN		(0x1u<<26)
#define	RCU_APB1EN_CAN0EN		(0x1u<<25)
#define	RCU_APB1EN_I2C1EN		(0x1u<<22)
#define	RCU_APB1EN_I2C0EN		(0x1u<<21)
#define	RCU_APB1EN_UART4EN		(0x1u<<20)
#define	RCU_APB1EN_UART3EN		(0x1u<<19)
#define	RCU_APB1EN_USART2EN		(0x1u<<18)
#define	RCU_APB1EN_USART1EN		(0x1u<<17)
#define	RCU_APB1EN_SPI2EN		(0x1u<<15)
#define	RCU_APB1EN_SPI1EN		(0x1u<<14)
#define	RCU_APB1EN_WWDGTEN		(0x1u<<11)
#define	RCU_APB1EN_TIMER6EN		(0x1u<<5)
#define	RCU_APB1EN_TIMER5EN		(0x1u<<4)
#define	RCU_APB1EN_TIMER4EN		(0x1u<<3)
#define	RCU_APB1EN_TIMER3EN		(0x1u<<2)
#define	RCU_APB1EN_TIMER2EN		(0x1u<<1)
#define	RCU_APB1EN_TIMER1EN		(0x1u<<0)

// BDCTL Configuration

#define	RCU_BDCTL_BKPRST		(0x1u<<16)
#define	RCU_BDCTL_RTCEN			(0x1u<<15)
#define	RCU_BDCTL_RTCSRC		(0x3u<<8)
#define	RCU_BDCTL_RTCSRC_0		(0x1u<<8)
#define	RCU_BDCTL_LXTALBPS		(0x1u<<2)
#define	RCU_BDCTL_LXTALSTB		(0x1u<<1)
#define	RCU_BDCTL_LXTALEN		(0x1u<<0)

// RSTSCK Configuration

#define	RCU_RSTSCK_LPRSTF		(0x1u<<31)
#define	RCU_RSTSCK_WWDGTRSTF	(0x1u<<30)
#define	RCU_RSTSCK_FWDGTRSTF	(0x1u<<29)
#define	RCU_RSTSCK_SWRSTF		(0x1u<<28)
#define	RCU_RSTSCK_PORRSTF		(0x1u<<27)
#define	RCU_RSTSCK_EPRSTF		(0x1u<<26)
#define	RCU_RSTSCK_RSTFC		(0x1u<<24)
#define	RCU_RSTSCK_IRC40KSTB	(0x1u<<1)
#define	RCU_RSTSCK_IRC40KEN		(0x1u<<0)

// AHBRST Configuration

#define	RCU_AHBRST_USBFSRST		(0x1u<<12)

// CFG1 Configuration

#define	RCU_CFG1_I2S2SEL		(0x1u<<18)
#define	RCU_CFG1_I2S1SEL		(0x1u<<17)
#define	RCU_CFG1_PREDV0SEL		(0x1u<<16)
#define	RCU_CFG1_PLL2MF			(0xFu<<12)
#define	RCU_CFG1_PLL2MF_0		(0x1u<<12)
#define	RCU_CFG1_PLL1MF			(0xFu<<8)
#define	RCU_CFG1_PLL1MF_0		(0x1u<<8)
#define	RCU_CFG1_PREDV1			(0xFu<<4)
#define	RCU_CFG1_PREDV1_0		(0x1u<<4)
#define	RCU_CFG1_PREDV0			(0xFu<<0)
#define	RCU_CFG1_PREDV0_0		(0x1u<<0)

// DSV Configuration

#define	RCU_DSV_DSLPVS			(0x3u<<0)
#define	RCU_DSV_DSLPVS_0		(0x1u<<0)
