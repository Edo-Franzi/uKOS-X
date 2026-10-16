/*
; stm32F217_gpio.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_gpio equates.
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
#define	GPIOI	reinterpret_cast<GPIO_TypeDef *>(0x40022000u)
#define	GPIOH	reinterpret_cast<GPIO_TypeDef *>(0x40021C00u)
#define	GPIOG	reinterpret_cast<GPIO_TypeDef *>(0x40021800u)
#define	GPIOF	reinterpret_cast<GPIO_TypeDef *>(0x40021400u)
#define	GPIOE	reinterpret_cast<GPIO_TypeDef *>(0x40021000u)
#define	GPIOD	reinterpret_cast<GPIO_TypeDef *>(0x40020C00u)
#define	GPIOC	reinterpret_cast<GPIO_TypeDef *>(0x40020800u)
#define	GPIOB	reinterpret_cast<GPIO_TypeDef *>(0x40020400u)
#define	GPIOA	reinterpret_cast<GPIO_TypeDef *>(0x40020000u)

#else
#define	GPIOI	((GPIO_TypeDef *)0x40022000u)
#define	GPIOH	((GPIO_TypeDef *)0x40021C00u)
#define	GPIOG	((GPIO_TypeDef *)0x40021800u)
#define	GPIOF	((GPIO_TypeDef *)0x40021400u)
#define	GPIOE	((GPIO_TypeDef *)0x40021000u)
#define	GPIOD	((GPIO_TypeDef *)0x40020C00u)
#define	GPIOC	((GPIO_TypeDef *)0x40020800u)
#define	GPIOB	((GPIO_TypeDef *)0x40020400u)
#define	GPIOA	((GPIO_TypeDef *)0x40020000u)
#endif

// MODER Configuration

#define	GPIO_MODER_MODER0			(0x3u<<0)
#define	GPIO_MODER_MODER0_0			(0x1u<<0)
#define	GPIO_MODER_MODER1			(0x3u<<2)
#define	GPIO_MODER_MODER1_0			(0x1u<<2)
#define	GPIO_MODER_MODER2			(0x3u<<4)
#define	GPIO_MODER_MODER2_0			(0x1u<<4)
#define	GPIO_MODER_MODER3			(0x3u<<6)
#define	GPIO_MODER_MODER3_0			(0x1u<<6)
#define	GPIO_MODER_MODER4			(0x3u<<8)
#define	GPIO_MODER_MODER4_0			(0x1u<<8)
#define	GPIO_MODER_MODER5			(0x3u<<10)
#define	GPIO_MODER_MODER5_0			(0x1u<<10)
#define	GPIO_MODER_MODER6			(0x3u<<12)
#define	GPIO_MODER_MODER6_0			(0x1u<<12)
#define	GPIO_MODER_MODER7			(0x3u<<14)
#define	GPIO_MODER_MODER7_0			(0x1u<<14)
#define	GPIO_MODER_MODER8			(0x3u<<16)
#define	GPIO_MODER_MODER8_0			(0x1u<<16)
#define	GPIO_MODER_MODER9			(0x3u<<18)
#define	GPIO_MODER_MODER9_0			(0x1u<<18)
#define	GPIO_MODER_MODER10			(0x3u<<20)
#define	GPIO_MODER_MODER10_0		(0x1u<<20)
#define	GPIO_MODER_MODER11			(0x3u<<22)
#define	GPIO_MODER_MODER11_0		(0x1u<<22)
#define	GPIO_MODER_MODER12			(0x3u<<24)
#define	GPIO_MODER_MODER12_0		(0x1u<<24)
#define	GPIO_MODER_MODER13			(0x3u<<26)
#define	GPIO_MODER_MODER13_0		(0x1u<<26)
#define	GPIO_MODER_MODER14			(0x3u<<28)
#define	GPIO_MODER_MODER14_0		(0x1u<<28)
#define	GPIO_MODER_MODER15			(0x3u<<30)
#define	GPIO_MODER_MODER15_0		(0x1u<<30)

// OTYPER Configuration

#define	GPIO_OTYPER_OT0				(0x1u<<0)
#define	GPIO_OTYPER_OT1				(0x1u<<1)
#define	GPIO_OTYPER_OT2				(0x1u<<2)
#define	GPIO_OTYPER_OT3				(0x1u<<3)
#define	GPIO_OTYPER_OT4				(0x1u<<4)
#define	GPIO_OTYPER_OT5				(0x1u<<5)
#define	GPIO_OTYPER_OT6				(0x1u<<6)
#define	GPIO_OTYPER_OT7				(0x1u<<7)
#define	GPIO_OTYPER_OT8				(0x1u<<8)
#define	GPIO_OTYPER_OT9				(0x1u<<9)
#define	GPIO_OTYPER_OT10			(0x1u<<10)
#define	GPIO_OTYPER_OT11			(0x1u<<11)
#define	GPIO_OTYPER_OT12			(0x1u<<12)
#define	GPIO_OTYPER_OT13			(0x1u<<13)
#define	GPIO_OTYPER_OT14			(0x1u<<14)
#define	GPIO_OTYPER_OT15			(0x1u<<15)

// OSPEEDR Configuration

#define	GPIO_OSPEEDR_OSPEEDR0		(0x3u<<0)
#define	GPIO_OSPEEDR_OSPEEDR0_0		(0x1u<<0)
#define	GPIO_OSPEEDR_OSPEEDR1		(0x3u<<2)
#define	GPIO_OSPEEDR_OSPEEDR1_0		(0x1u<<2)
#define	GPIO_OSPEEDR_OSPEEDR2		(0x3u<<4)
#define	GPIO_OSPEEDR_OSPEEDR2_0		(0x1u<<4)
#define	GPIO_OSPEEDR_OSPEEDR3		(0x3u<<6)
#define	GPIO_OSPEEDR_OSPEEDR3_0		(0x1u<<6)
#define	GPIO_OSPEEDR_OSPEEDR4		(0x3u<<8)
#define	GPIO_OSPEEDR_OSPEEDR4_0		(0x1u<<8)
#define	GPIO_OSPEEDR_OSPEEDR5		(0x3u<<10)
#define	GPIO_OSPEEDR_OSPEEDR5_0		(0x1u<<10)
#define	GPIO_OSPEEDR_OSPEEDR6		(0x3u<<12)
#define	GPIO_OSPEEDR_OSPEEDR6_0		(0x1u<<12)
#define	GPIO_OSPEEDR_OSPEEDR7		(0x3u<<14)
#define	GPIO_OSPEEDR_OSPEEDR7_0		(0x1u<<14)
#define	GPIO_OSPEEDR_OSPEEDR8		(0x3u<<16)
#define	GPIO_OSPEEDR_OSPEEDR8_0		(0x1u<<16)
#define	GPIO_OSPEEDR_OSPEEDR9		(0x3u<<18)
#define	GPIO_OSPEEDR_OSPEEDR9_0		(0x1u<<18)
#define	GPIO_OSPEEDR_OSPEEDR10		(0x3u<<20)
#define	GPIO_OSPEEDR_OSPEEDR10_0	(0x1u<<20)
#define	GPIO_OSPEEDR_OSPEEDR11		(0x3u<<22)
#define	GPIO_OSPEEDR_OSPEEDR11_0	(0x1u<<22)
#define	GPIO_OSPEEDR_OSPEEDR12		(0x3u<<24)
#define	GPIO_OSPEEDR_OSPEEDR12_0	(0x1u<<24)
#define	GPIO_OSPEEDR_OSPEEDR13		(0x3u<<26)
#define	GPIO_OSPEEDR_OSPEEDR13_0	(0x1u<<26)
#define	GPIO_OSPEEDR_OSPEEDR14		(0x3u<<28)
#define	GPIO_OSPEEDR_OSPEEDR14_0	(0x1u<<28)
#define	GPIO_OSPEEDR_OSPEEDR15		(0x3u<<30)
#define	GPIO_OSPEEDR_OSPEEDR15_0	(0x1u<<30)

// PUPDR Configuration

#define	GPIO_PUPDR_PUPDR0			(0x3u<<0)
#define	GPIO_PUPDR_PUPDR0_0			(0x1u<<0)
#define	GPIO_PUPDR_PUPDR1			(0x3u<<2)
#define	GPIO_PUPDR_PUPDR1_0			(0x1u<<2)
#define	GPIO_PUPDR_PUPDR2			(0x3u<<4)
#define	GPIO_PUPDR_PUPDR2_0			(0x1u<<4)
#define	GPIO_PUPDR_PUPDR3			(0x3u<<6)
#define	GPIO_PUPDR_PUPDR3_0			(0x1u<<6)
#define	GPIO_PUPDR_PUPDR4			(0x3u<<8)
#define	GPIO_PUPDR_PUPDR4_0			(0x1u<<8)
#define	GPIO_PUPDR_PUPDR5			(0x3u<<10)
#define	GPIO_PUPDR_PUPDR5_0			(0x1u<<10)
#define	GPIO_PUPDR_PUPDR6			(0x3u<<12)
#define	GPIO_PUPDR_PUPDR6_0			(0x1u<<12)
#define	GPIO_PUPDR_PUPDR7			(0x3u<<14)
#define	GPIO_PUPDR_PUPDR7_0			(0x1u<<14)
#define	GPIO_PUPDR_PUPDR8			(0x3u<<16)
#define	GPIO_PUPDR_PUPDR8_0			(0x1u<<16)
#define	GPIO_PUPDR_PUPDR9			(0x3u<<18)
#define	GPIO_PUPDR_PUPDR9_0			(0x1u<<18)
#define	GPIO_PUPDR_PUPDR10			(0x3u<<20)
#define	GPIO_PUPDR_PUPDR10_0		(0x1u<<20)
#define	GPIO_PUPDR_PUPDR11			(0x3u<<22)
#define	GPIO_PUPDR_PUPDR11_0		(0x1u<<22)
#define	GPIO_PUPDR_PUPDR12			(0x3u<<24)
#define	GPIO_PUPDR_PUPDR12_0		(0x1u<<24)
#define	GPIO_PUPDR_PUPDR13			(0x3u<<26)
#define	GPIO_PUPDR_PUPDR13_0		(0x1u<<26)
#define	GPIO_PUPDR_PUPDR14			(0x3u<<28)
#define	GPIO_PUPDR_PUPDR14_0		(0x1u<<28)
#define	GPIO_PUPDR_PUPDR15			(0x3u<<30)
#define	GPIO_PUPDR_PUPDR15_0		(0x1u<<30)

// IDR Configuration

#define	GPIO_IDR_IDR0				(0x1u<<0)
#define	GPIO_IDR_IDR1				(0x1u<<1)
#define	GPIO_IDR_IDR2				(0x1u<<2)
#define	GPIO_IDR_IDR3				(0x1u<<3)
#define	GPIO_IDR_IDR4				(0x1u<<4)
#define	GPIO_IDR_IDR5				(0x1u<<5)
#define	GPIO_IDR_IDR6				(0x1u<<6)
#define	GPIO_IDR_IDR7				(0x1u<<7)
#define	GPIO_IDR_IDR8				(0x1u<<8)
#define	GPIO_IDR_IDR9				(0x1u<<9)
#define	GPIO_IDR_IDR10				(0x1u<<10)
#define	GPIO_IDR_IDR11				(0x1u<<11)
#define	GPIO_IDR_IDR12				(0x1u<<12)
#define	GPIO_IDR_IDR13				(0x1u<<13)
#define	GPIO_IDR_IDR14				(0x1u<<14)
#define	GPIO_IDR_IDR15				(0x1u<<15)

// ODR Configuration

#define	GPIO_ODR_ODR0				(0x1u<<0)
#define	GPIO_ODR_ODR1				(0x1u<<1)
#define	GPIO_ODR_ODR2				(0x1u<<2)
#define	GPIO_ODR_ODR3				(0x1u<<3)
#define	GPIO_ODR_ODR4				(0x1u<<4)
#define	GPIO_ODR_ODR5				(0x1u<<5)
#define	GPIO_ODR_ODR6				(0x1u<<6)
#define	GPIO_ODR_ODR7				(0x1u<<7)
#define	GPIO_ODR_ODR8				(0x1u<<8)
#define	GPIO_ODR_ODR9				(0x1u<<9)
#define	GPIO_ODR_ODR10				(0x1u<<10)
#define	GPIO_ODR_ODR11				(0x1u<<11)
#define	GPIO_ODR_ODR12				(0x1u<<12)
#define	GPIO_ODR_ODR13				(0x1u<<13)
#define	GPIO_ODR_ODR14				(0x1u<<14)
#define	GPIO_ODR_ODR15				(0x1u<<15)

// BSRR Configuration

#define	GPIO_BSRR_BS0				(0x1u<<0)
#define	GPIO_BSRR_BS1				(0x1u<<1)
#define	GPIO_BSRR_BS2				(0x1u<<2)
#define	GPIO_BSRR_BS3				(0x1u<<3)
#define	GPIO_BSRR_BS4				(0x1u<<4)
#define	GPIO_BSRR_BS5				(0x1u<<5)
#define	GPIO_BSRR_BS6				(0x1u<<6)
#define	GPIO_BSRR_BS7				(0x1u<<7)
#define	GPIO_BSRR_BS8				(0x1u<<8)
#define	GPIO_BSRR_BS9				(0x1u<<9)
#define	GPIO_BSRR_BS10				(0x1u<<10)
#define	GPIO_BSRR_BS11				(0x1u<<11)
#define	GPIO_BSRR_BS12				(0x1u<<12)
#define	GPIO_BSRR_BS13				(0x1u<<13)
#define	GPIO_BSRR_BS14				(0x1u<<14)
#define	GPIO_BSRR_BS15				(0x1u<<15)
#define	GPIO_BSRR_BR0				(0x1u<<16)
#define	GPIO_BSRR_BR1				(0x1u<<17)
#define	GPIO_BSRR_BR2				(0x1u<<18)
#define	GPIO_BSRR_BR3				(0x1u<<19)
#define	GPIO_BSRR_BR4				(0x1u<<20)
#define	GPIO_BSRR_BR5				(0x1u<<21)
#define	GPIO_BSRR_BR6				(0x1u<<22)
#define	GPIO_BSRR_BR7				(0x1u<<23)
#define	GPIO_BSRR_BR8				(0x1u<<24)
#define	GPIO_BSRR_BR9				(0x1u<<25)
#define	GPIO_BSRR_BR10				(0x1u<<26)
#define	GPIO_BSRR_BR11				(0x1u<<27)
#define	GPIO_BSRR_BR12				(0x1u<<28)
#define	GPIO_BSRR_BR13				(0x1u<<29)
#define	GPIO_BSRR_BR14				(0x1u<<30)
#define	GPIO_BSRR_BR15				(0x1u<<31)

// LCKR Configuration

#define	GPIO_LCKR_LCK0				(0x1u<<0)
#define	GPIO_LCKR_LCK1				(0x1u<<1)
#define	GPIO_LCKR_LCK2				(0x1u<<2)
#define	GPIO_LCKR_LCK3				(0x1u<<3)
#define	GPIO_LCKR_LCK4				(0x1u<<4)
#define	GPIO_LCKR_LCK5				(0x1u<<5)
#define	GPIO_LCKR_LCK6				(0x1u<<6)
#define	GPIO_LCKR_LCK7				(0x1u<<7)
#define	GPIO_LCKR_LCK8				(0x1u<<8)
#define	GPIO_LCKR_LCK9				(0x1u<<9)
#define	GPIO_LCKR_LCK10				(0x1u<<10)
#define	GPIO_LCKR_LCK11				(0x1u<<11)
#define	GPIO_LCKR_LCK12				(0x1u<<12)
#define	GPIO_LCKR_LCK13				(0x1u<<13)
#define	GPIO_LCKR_LCK14				(0x1u<<14)
#define	GPIO_LCKR_LCK15				(0x1u<<15)
#define	GPIO_LCKR_LCKK				(0x1u<<16)

// AFRL Configuration

#define	GPIO_AFRL_AFRL0				(0xFu<<0)
#define	GPIO_AFRL_AFRL0_0			(0x1u<<0)
#define	GPIO_AFRL_AFRL1				(0xFu<<4)
#define	GPIO_AFRL_AFRL1_0			(0x1u<<4)
#define	GPIO_AFRL_AFRL2				(0xFu<<8)
#define	GPIO_AFRL_AFRL2_0			(0x1u<<8)
#define	GPIO_AFRL_AFRL3				(0xFu<<12)
#define	GPIO_AFRL_AFRL3_0			(0x1u<<12)
#define	GPIO_AFRL_AFRL4				(0xFu<<16)
#define	GPIO_AFRL_AFRL4_0			(0x1u<<16)
#define	GPIO_AFRL_AFRL5				(0xFu<<20)
#define	GPIO_AFRL_AFRL5_0			(0x1u<<20)
#define	GPIO_AFRL_AFRL6				(0xFu<<24)
#define	GPIO_AFRL_AFRL6_0			(0x1u<<24)
#define	GPIO_AFRL_AFRL7				(0xFu<<28)
#define	GPIO_AFRL_AFRL7_0			(0x1u<<28)

// AFRH Configuration

#define	GPIO_AFRH_AFRH8				(0xFu<<0)
#define	GPIO_AFRH_AFRH8_0			(0x1u<<0)
#define	GPIO_AFRH_AFRH9				(0xFu<<4)
#define	GPIO_AFRH_AFRH9_0			(0x1u<<4)
#define	GPIO_AFRH_AFRH10			(0xFu<<8)
#define	GPIO_AFRH_AFRH10_0			(0x1u<<8)
#define	GPIO_AFRH_AFRH11			(0xFu<<12)
#define	GPIO_AFRH_AFRH11_0			(0x1u<<12)
#define	GPIO_AFRH_AFRH12			(0xFu<<16)
#define	GPIO_AFRH_AFRH12_0			(0x1u<<16)
#define	GPIO_AFRH_AFRH13			(0xFu<<20)
#define	GPIO_AFRH_AFRH13_0			(0x1u<<20)
#define	GPIO_AFRH_AFRH14			(0xFu<<24)
#define	GPIO_AFRH_AFRH14_0			(0x1u<<24)
#define	GPIO_AFRH_AFRH15			(0xFu<<28)
#define	GPIO_AFRH_AFRH15_0			(0x1u<<28)
