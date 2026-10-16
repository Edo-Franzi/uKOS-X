/*
; GD32VF103_afio.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_afio equates.
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

// AFIO address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	EC;
	volatile	uint32_t	PCF0;
	volatile	uint32_t	EXTISS0;
	volatile	uint32_t	EXTISS1;
	volatile	uint32_t	EXTISS2;
	volatile	uint32_t	EXTISS3;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	PCF1;
} AFIO_TypeDef;

#if (defined(__cplusplus))
#define	AFIO	reinterpret_cast<AFIO_TypeDef *>(0x40010000u)

#else
#define	AFIO	((AFIO_TypeDef *)0x40010000u)
#endif

// EC Configuration

#define	AFIO_EC_PIN					(0xFu<<0)
#define	AFIO_EC_PIN_0				(0x1u<<0)
#define	AFIO_EC_PORT				(0x7u<<4)
#define	AFIO_EC_PORT_0				(0x1u<<4)
#define	AFIO_EC_EOE					(0x1u<<7)

// PCF0 Configuration

#define	AFIO_PCF0_SPI0_REMAP		(0x1u<<0)
#define	AFIO_PCF0_I2C0_REMAP		(0x1u<<1)
#define	AFIO_PCF0_USART0_REMAP		(0x1u<<2)
#define	AFIO_PCF0_USART1_REMAP		(0x1u<<3)
#define	AFIO_PCF0_USART2_REMAP		(0x3u<<4)
#define	AFIO_PCF0_USART2_REMAP_0	(0x1u<<4)
#define	AFIO_PCF0_TIMER0_REMAP		(0x3u<<6)
#define	AFIO_PCF0_TIMER0_REMAP_0	(0x1u<<6)
#define	AFIO_PCF0_TIMER1_REMAP		(0x3u<<8)
#define	AFIO_PCF0_TIMER1_REMAP_0	(0x1u<<8)
#define	AFIO_PCF0_TIMER2_REMAP		(0x3u<<10)
#define	AFIO_PCF0_TIMER2_REMAP_0	(0x1u<<10)
#define	AFIO_PCF0_TIMER3_REMAP		(0x1u<<12)
#define	AFIO_PCF0_CAN0_REMAP		(0x3u<<13)
#define	AFIO_PCF0_CAN0_REMAP_0		(0x1u<<13)
#define	AFIO_PCF0_PD01_REMAP		(0x1u<<15)
#define	AFIO_PCF0_TIMER4CH3_IREMAP	(0x1u<<16)
#define	AFIO_PCF0_CAN1_REMAP		(0x1u<<22)
#define	AFIO_PCF0_SWJ_CFG			(0x7u<<24)
#define	AFIO_PCF0_SWJ_CFG_0			(0x1u<<24)
#define	AFIO_PCF0_SPI2_REMAP		(0x1u<<28)
#define	AFIO_PCF0_TIMER1ITI1_REMAP	(0x1u<<29)

// EXTISS0 Configuration

#define	AFIO_EXTISS0_EXTI0_SS		(0xFu<<0)
#define	AFIO_EXTISS0_EXTI0_SS_0		(0x1u<<0)
#define	AFIO_EXTISS0_EXTI1_SS		(0xFu<<4)
#define	AFIO_EXTISS0_EXTI1_SS_0		(0x1u<<4)
#define	AFIO_EXTISS0_EXTI2_SS		(0xFu<<8)
#define	AFIO_EXTISS0_EXTI2_SS_0		(0x1u<<8)
#define	AFIO_EXTISS0_EXTI3_SS		(0xFu<<12)
#define	AFIO_EXTISS0_EXTI3_SS_0		(0x1u<<12)

// EXTISS1 Configuration

#define	AFIO_EXTISS1_EXTI4_SS		(0xFu<<0)
#define	AFIO_EXTISS1_EXTI4_SS_0		(0x1u<<0)
#define	AFIO_EXTISS1_EXTI5_SS		(0xFu<<4)
#define	AFIO_EXTISS1_EXTI5_SS_0		(0x1u<<4)
#define	AFIO_EXTISS1_EXTI6_SS		(0xFu<<8)
#define	AFIO_EXTISS1_EXTI6_SS_0		(0x1u<<8)
#define	AFIO_EXTISS1_EXTI7_SS		(0xFu<<12)
#define	AFIO_EXTISS1_EXTI7_SS_0		(0x1u<<12)

// EXTISS2 Configuration

#define	AFIO_EXTISS2_EXTI8_SS		(0xFu<<0)
#define	AFIO_EXTISS2_EXTI8_SS_0		(0x1u<<0)
#define	AFIO_EXTISS2_EXTI9_SS		(0xFu<<4)
#define	AFIO_EXTISS2_EXTI9_SS_0		(0x1u<<4)
#define	AFIO_EXTISS2_EXTI10_SS		(0xFu<<8)
#define	AFIO_EXTISS2_EXTI10_SS_0	(0x1u<<8)
#define	AFIO_EXTISS2_EXTI11_SS		(0xFu<<12)
#define	AFIO_EXTISS2_EXTI11_SS_0	(0x1u<<12)

// EXTISS3 Configuration

#define	AFIO_EXTISS3_EXTI12_SS		(0xFu<<0)
#define	AFIO_EXTISS3_EXTI12_SS_0	(0x1u<<0)
#define	AFIO_EXTISS3_EXTI13_SS		(0xFu<<4)
#define	AFIO_EXTISS3_EXTI13_SS_0	(0x1u<<4)
#define	AFIO_EXTISS3_EXTI14_SS		(0xFu<<8)
#define	AFIO_EXTISS3_EXTI14_SS_0	(0x1u<<8)
#define	AFIO_EXTISS3_EXTI15_SS		(0xFu<<12)
#define	AFIO_EXTISS3_EXTI15_SS_0	(0x1u<<12)

// PCF1 Configuration

#define	AFIO_PCF1_EXMC_NADV			(0x1u<<10)
