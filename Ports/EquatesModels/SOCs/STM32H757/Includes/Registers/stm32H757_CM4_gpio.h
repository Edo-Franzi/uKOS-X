/*
; stm32H757_CM4_gpio.
; ===================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H757_CM4_gpio equates.
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

// GPIO address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	MODER;
	volatile	uint32_t	OTYPER;
	volatile	uint32_t	OSPEEDR;
	volatile	uint32_t	PUPDR;
	volatile	uint32_t	IDR;
	volatile	uint32_t	ODR;
	volatile	uint32_t	BSRR;
	volatile	uint32_t	LCKR;
	volatile	uint32_t	AFRL;
	volatile	uint32_t	AFRH;
} GPIO_TypeDef;

#if (defined(__cplusplus))
#define	GPIOA	reinterpret_cast<GPIO_TypeDef *>(0x58020000u)
#define	GPIOB	reinterpret_cast<GPIO_TypeDef *>(0x58020400u)
#define	GPIOC	reinterpret_cast<GPIO_TypeDef *>(0x58020800u)
#define	GPIOD	reinterpret_cast<GPIO_TypeDef *>(0x58020C00u)
#define	GPIOE	reinterpret_cast<GPIO_TypeDef *>(0x58021000u)
#define	GPIOF	reinterpret_cast<GPIO_TypeDef *>(0x58021400u)
#define	GPIOG	reinterpret_cast<GPIO_TypeDef *>(0x58021800u)
#define	GPIOH	reinterpret_cast<GPIO_TypeDef *>(0x58021C00u)
#define	GPIOI	reinterpret_cast<GPIO_TypeDef *>(0x58022000u)
#define	GPIOJ	reinterpret_cast<GPIO_TypeDef *>(0x58022400u)
#define	GPIOK	reinterpret_cast<GPIO_TypeDef *>(0x58022800u)

#else
#define	GPIOA	((GPIO_TypeDef *)0x58020000u)
#define	GPIOB	((GPIO_TypeDef *)0x58020400u)
#define	GPIOC	((GPIO_TypeDef *)0x58020800u)
#define	GPIOD	((GPIO_TypeDef *)0x58020C00u)
#define	GPIOE	((GPIO_TypeDef *)0x58021000u)
#define	GPIOF	((GPIO_TypeDef *)0x58021400u)
#define	GPIOG	((GPIO_TypeDef *)0x58021800u)
#define	GPIOH	((GPIO_TypeDef *)0x58021C00u)
#define	GPIOI	((GPIO_TypeDef *)0x58022000u)
#define	GPIOJ	((GPIO_TypeDef *)0x58022400u)
#define	GPIOK	((GPIO_TypeDef *)0x58022800u)
#endif

// MODER Configuration

#define	GPIO_MODER_MODE15		(0x3u<<30)
#define	GPIO_MODER_MODE15_0		(0x1u<<30)
#define	GPIO_MODER_MODE14		(0x3u<<28)
#define	GPIO_MODER_MODE14_0		(0x1u<<28)
#define	GPIO_MODER_MODE13		(0x3u<<26)
#define	GPIO_MODER_MODE13_0		(0x1u<<26)
#define	GPIO_MODER_MODE12		(0x3u<<24)
#define	GPIO_MODER_MODE12_0		(0x1u<<24)
#define	GPIO_MODER_MODE11		(0x3u<<22)
#define	GPIO_MODER_MODE11_0		(0x1u<<22)
#define	GPIO_MODER_MODE10		(0x3u<<20)
#define	GPIO_MODER_MODE10_0		(0x1u<<20)
#define	GPIO_MODER_MODE9		(0x3u<<18)
#define	GPIO_MODER_MODE9_0		(0x1u<<18)
#define	GPIO_MODER_MODE8		(0x3u<<16)
#define	GPIO_MODER_MODE8_0		(0x1u<<16)
#define	GPIO_MODER_MODE7		(0x3u<<14)
#define	GPIO_MODER_MODE7_0		(0x1u<<14)
#define	GPIO_MODER_MODE6		(0x3u<<12)
#define	GPIO_MODER_MODE6_0		(0x1u<<12)
#define	GPIO_MODER_MODE5		(0x3u<<10)
#define	GPIO_MODER_MODE5_0		(0x1u<<10)
#define	GPIO_MODER_MODE4		(0x3u<<8)
#define	GPIO_MODER_MODE4_0		(0x1u<<8)
#define	GPIO_MODER_MODE3		(0x3u<<6)
#define	GPIO_MODER_MODE3_0		(0x1u<<6)
#define	GPIO_MODER_MODE2		(0x3u<<4)
#define	GPIO_MODER_MODE2_0		(0x1u<<4)
#define	GPIO_MODER_MODE1		(0x3u<<2)
#define	GPIO_MODER_MODE1_0		(0x1u<<2)
#define	GPIO_MODER_MODE0		(0x3u<<0)
#define	GPIO_MODER_MODE0_0		(0x1u<<0)

// OTYPER Configuration

#define	GPIO_OTYPER_OT15		(0x1u<<15)
#define	GPIO_OTYPER_OT14		(0x1u<<14)
#define	GPIO_OTYPER_OT13		(0x1u<<13)
#define	GPIO_OTYPER_OT12		(0x1u<<12)
#define	GPIO_OTYPER_OT11		(0x1u<<11)
#define	GPIO_OTYPER_OT10		(0x1u<<10)
#define	GPIO_OTYPER_OT9			(0x1u<<9)
#define	GPIO_OTYPER_OT8			(0x1u<<8)
#define	GPIO_OTYPER_OT7			(0x1u<<7)
#define	GPIO_OTYPER_OT6			(0x1u<<6)
#define	GPIO_OTYPER_OT5			(0x1u<<5)
#define	GPIO_OTYPER_OT4			(0x1u<<4)
#define	GPIO_OTYPER_OT3			(0x1u<<3)
#define	GPIO_OTYPER_OT2			(0x1u<<2)
#define	GPIO_OTYPER_OT1			(0x1u<<1)
#define	GPIO_OTYPER_OT0			(0x1u<<0)

// OSPEEDR Configuration

#define	GPIO_OSPEEDR_OSPEED15	(0x3u<<30)
#define	GPIO_OSPEEDR_OSPEED15_0	(0x1u<<30)
#define	GPIO_OSPEEDR_OSPEED14	(0x3u<<28)
#define	GPIO_OSPEEDR_OSPEED14_0	(0x1u<<28)
#define	GPIO_OSPEEDR_OSPEED13	(0x3u<<26)
#define	GPIO_OSPEEDR_OSPEED13_0	(0x1u<<26)
#define	GPIO_OSPEEDR_OSPEED12	(0x3u<<24)
#define	GPIO_OSPEEDR_OSPEED12_0	(0x1u<<24)
#define	GPIO_OSPEEDR_OSPEED11	(0x3u<<22)
#define	GPIO_OSPEEDR_OSPEED11_0	(0x1u<<22)
#define	GPIO_OSPEEDR_OSPEED10	(0x3u<<20)
#define	GPIO_OSPEEDR_OSPEED10_0	(0x1u<<20)
#define	GPIO_OSPEEDR_OSPEED9	(0x3u<<18)
#define	GPIO_OSPEEDR_OSPEED9_0	(0x1u<<18)
#define	GPIO_OSPEEDR_OSPEED8	(0x3u<<16)
#define	GPIO_OSPEEDR_OSPEED8_0	(0x1u<<16)
#define	GPIO_OSPEEDR_OSPEED7	(0x3u<<14)
#define	GPIO_OSPEEDR_OSPEED7_0	(0x1u<<14)
#define	GPIO_OSPEEDR_OSPEED6	(0x3u<<12)
#define	GPIO_OSPEEDR_OSPEED6_0	(0x1u<<12)
#define	GPIO_OSPEEDR_OSPEED5	(0x3u<<10)
#define	GPIO_OSPEEDR_OSPEED5_0	(0x1u<<10)
#define	GPIO_OSPEEDR_OSPEED4	(0x3u<<8)
#define	GPIO_OSPEEDR_OSPEED4_0	(0x1u<<8)
#define	GPIO_OSPEEDR_OSPEED3	(0x3u<<6)
#define	GPIO_OSPEEDR_OSPEED3_0	(0x1u<<6)
#define	GPIO_OSPEEDR_OSPEED2	(0x3u<<4)
#define	GPIO_OSPEEDR_OSPEED2_0	(0x1u<<4)
#define	GPIO_OSPEEDR_OSPEED1	(0x3u<<2)
#define	GPIO_OSPEEDR_OSPEED1_0	(0x1u<<2)
#define	GPIO_OSPEEDR_OSPEED0	(0x3u<<0)
#define	GPIO_OSPEEDR_OSPEED0_0	(0x1u<<0)

// PUPDR Configuration

#define	GPIO_PUPDR_PUPD15		(0x3u<<30)
#define	GPIO_PUPDR_PUPD15_0		(0x1u<<30)
#define	GPIO_PUPDR_PUPD14		(0x3u<<28)
#define	GPIO_PUPDR_PUPD14_0		(0x1u<<28)
#define	GPIO_PUPDR_PUPD13		(0x3u<<26)
#define	GPIO_PUPDR_PUPD13_0		(0x1u<<26)
#define	GPIO_PUPDR_PUPD12		(0x3u<<24)
#define	GPIO_PUPDR_PUPD12_0		(0x1u<<24)
#define	GPIO_PUPDR_PUPD11		(0x3u<<22)
#define	GPIO_PUPDR_PUPD11_0		(0x1u<<22)
#define	GPIO_PUPDR_PUPD10		(0x3u<<20)
#define	GPIO_PUPDR_PUPD10_0		(0x1u<<20)
#define	GPIO_PUPDR_PUPD9		(0x3u<<18)
#define	GPIO_PUPDR_PUPD9_0		(0x1u<<18)
#define	GPIO_PUPDR_PUPD8		(0x3u<<16)
#define	GPIO_PUPDR_PUPD8_0		(0x1u<<16)
#define	GPIO_PUPDR_PUPD7		(0x3u<<14)
#define	GPIO_PUPDR_PUPD7_0		(0x1u<<14)
#define	GPIO_PUPDR_PUPD6		(0x3u<<12)
#define	GPIO_PUPDR_PUPD6_0		(0x1u<<12)
#define	GPIO_PUPDR_PUPD5		(0x3u<<10)
#define	GPIO_PUPDR_PUPD5_0		(0x1u<<10)
#define	GPIO_PUPDR_PUPD4		(0x3u<<8)
#define	GPIO_PUPDR_PUPD4_0		(0x1u<<8)
#define	GPIO_PUPDR_PUPD3		(0x3u<<6)
#define	GPIO_PUPDR_PUPD3_0		(0x1u<<6)
#define	GPIO_PUPDR_PUPD2		(0x3u<<4)
#define	GPIO_PUPDR_PUPD2_0		(0x1u<<4)
#define	GPIO_PUPDR_PUPD1		(0x3u<<2)
#define	GPIO_PUPDR_PUPD1_0		(0x1u<<2)
#define	GPIO_PUPDR_PUPD0		(0x3u<<0)
#define	GPIO_PUPDR_PUPD0_0		(0x1u<<0)

// IDR Configuration

#define	GPIO_IDR_ID15			(0x1u<<15)
#define	GPIO_IDR_ID14			(0x1u<<14)
#define	GPIO_IDR_ID13			(0x1u<<13)
#define	GPIO_IDR_ID12			(0x1u<<12)
#define	GPIO_IDR_ID11			(0x1u<<11)
#define	GPIO_IDR_ID10			(0x1u<<10)
#define	GPIO_IDR_ID9			(0x1u<<9)
#define	GPIO_IDR_ID8			(0x1u<<8)
#define	GPIO_IDR_ID7			(0x1u<<7)
#define	GPIO_IDR_ID6			(0x1u<<6)
#define	GPIO_IDR_ID5			(0x1u<<5)
#define	GPIO_IDR_ID4			(0x1u<<4)
#define	GPIO_IDR_ID3			(0x1u<<3)
#define	GPIO_IDR_ID2			(0x1u<<2)
#define	GPIO_IDR_ID1			(0x1u<<1)
#define	GPIO_IDR_ID0			(0x1u<<0)

// ODR Configuration

#define	GPIO_ODR_OD15			(0x1u<<15)
#define	GPIO_ODR_OD14			(0x1u<<14)
#define	GPIO_ODR_OD13			(0x1u<<13)
#define	GPIO_ODR_OD12			(0x1u<<12)
#define	GPIO_ODR_OD11			(0x1u<<11)
#define	GPIO_ODR_OD10			(0x1u<<10)
#define	GPIO_ODR_OD9			(0x1u<<9)
#define	GPIO_ODR_OD8			(0x1u<<8)
#define	GPIO_ODR_OD7			(0x1u<<7)
#define	GPIO_ODR_OD6			(0x1u<<6)
#define	GPIO_ODR_OD5			(0x1u<<5)
#define	GPIO_ODR_OD4			(0x1u<<4)
#define	GPIO_ODR_OD3			(0x1u<<3)
#define	GPIO_ODR_OD2			(0x1u<<2)
#define	GPIO_ODR_OD1			(0x1u<<1)
#define	GPIO_ODR_OD0			(0x1u<<0)

// BSRR Configuration

#define	GPIO_BSRR_BR15			(0x1u<<31)
#define	GPIO_BSRR_BR14			(0x1u<<30)
#define	GPIO_BSRR_BR13			(0x1u<<29)
#define	GPIO_BSRR_BR12			(0x1u<<28)
#define	GPIO_BSRR_BR11			(0x1u<<27)
#define	GPIO_BSRR_BR10			(0x1u<<26)
#define	GPIO_BSRR_BR9			(0x1u<<25)
#define	GPIO_BSRR_BR8			(0x1u<<24)
#define	GPIO_BSRR_BR7			(0x1u<<23)
#define	GPIO_BSRR_BR6			(0x1u<<22)
#define	GPIO_BSRR_BR5			(0x1u<<21)
#define	GPIO_BSRR_BR4			(0x1u<<20)
#define	GPIO_BSRR_BR3			(0x1u<<19)
#define	GPIO_BSRR_BR2			(0x1u<<18)
#define	GPIO_BSRR_BR1			(0x1u<<17)
#define	GPIO_BSRR_BR0			(0x1u<<16)
#define	GPIO_BSRR_BS15			(0x1u<<15)
#define	GPIO_BSRR_BS14			(0x1u<<14)
#define	GPIO_BSRR_BS13			(0x1u<<13)
#define	GPIO_BSRR_BS12			(0x1u<<12)
#define	GPIO_BSRR_BS11			(0x1u<<11)
#define	GPIO_BSRR_BS10			(0x1u<<10)
#define	GPIO_BSRR_BS9			(0x1u<<9)
#define	GPIO_BSRR_BS8			(0x1u<<8)
#define	GPIO_BSRR_BS7			(0x1u<<7)
#define	GPIO_BSRR_BS6			(0x1u<<6)
#define	GPIO_BSRR_BS5			(0x1u<<5)
#define	GPIO_BSRR_BS4			(0x1u<<4)
#define	GPIO_BSRR_BS3			(0x1u<<3)
#define	GPIO_BSRR_BS2			(0x1u<<2)
#define	GPIO_BSRR_BS1			(0x1u<<1)
#define	GPIO_BSRR_BS0			(0x1u<<0)

// LCKR Configuration

#define	GPIO_LCKR_LCKK			(0x1u<<16)
#define	GPIO_LCKR_LCK15			(0x1u<<15)
#define	GPIO_LCKR_LCK14			(0x1u<<14)
#define	GPIO_LCKR_LCK13			(0x1u<<13)
#define	GPIO_LCKR_LCK12			(0x1u<<12)
#define	GPIO_LCKR_LCK11			(0x1u<<11)
#define	GPIO_LCKR_LCK10			(0x1u<<10)
#define	GPIO_LCKR_LCK9			(0x1u<<9)
#define	GPIO_LCKR_LCK8			(0x1u<<8)
#define	GPIO_LCKR_LCK7			(0x1u<<7)
#define	GPIO_LCKR_LCK6			(0x1u<<6)
#define	GPIO_LCKR_LCK5			(0x1u<<5)
#define	GPIO_LCKR_LCK4			(0x1u<<4)
#define	GPIO_LCKR_LCK3			(0x1u<<3)
#define	GPIO_LCKR_LCK2			(0x1u<<2)
#define	GPIO_LCKR_LCK1			(0x1u<<1)
#define	GPIO_LCKR_LCK0			(0x1u<<0)

// AFRL Configuration

#define	GPIO_AFRL_AFSEL7		(0xFu<<28)
#define	GPIO_AFRL_AFSEL7_0		(0x1u<<28)
#define	GPIO_AFRL_AFSEL6		(0xFu<<24)
#define	GPIO_AFRL_AFSEL6_0		(0x1u<<24)
#define	GPIO_AFRL_AFSEL5		(0xFu<<20)
#define	GPIO_AFRL_AFSEL5_0		(0x1u<<20)
#define	GPIO_AFRL_AFSEL4		(0xFu<<16)
#define	GPIO_AFRL_AFSEL4_0		(0x1u<<16)
#define	GPIO_AFRL_AFSEL3		(0xFu<<12)
#define	GPIO_AFRL_AFSEL3_0		(0x1u<<12)
#define	GPIO_AFRL_AFSEL2		(0xFu<<8)
#define	GPIO_AFRL_AFSEL2_0		(0x1u<<8)
#define	GPIO_AFRL_AFSEL1		(0xFu<<4)
#define	GPIO_AFRL_AFSEL1_0		(0x1u<<4)
#define	GPIO_AFRL_AFSEL0		(0xFu<<0)
#define	GPIO_AFRL_AFSEL0_0		(0x1u<<0)

// AFRH Configuration

#define	GPIO_AFRH_AFSEL15		(0xFu<<28)
#define	GPIO_AFRH_AFSEL15_0		(0x1u<<28)
#define	GPIO_AFRH_AFSEL14		(0xFu<<24)
#define	GPIO_AFRH_AFSEL14_0		(0x1u<<24)
#define	GPIO_AFRH_AFSEL13		(0xFu<<20)
#define	GPIO_AFRH_AFSEL13_0		(0x1u<<20)
#define	GPIO_AFRH_AFSEL12		(0xFu<<16)
#define	GPIO_AFRH_AFSEL12_0		(0x1u<<16)
#define	GPIO_AFRH_AFSEL11		(0xFu<<12)
#define	GPIO_AFRH_AFSEL11_0		(0x1u<<12)
#define	GPIO_AFRH_AFSEL10		(0xFu<<8)
#define	GPIO_AFRH_AFSEL10_0		(0x1u<<8)
#define	GPIO_AFRH_AFSEL9		(0xFu<<4)
#define	GPIO_AFRH_AFSEL9_0		(0x1u<<4)
#define	GPIO_AFRH_AFSEL8		(0xFu<<0)
#define	GPIO_AFRH_AFSEL8_0		(0x1u<<0)
