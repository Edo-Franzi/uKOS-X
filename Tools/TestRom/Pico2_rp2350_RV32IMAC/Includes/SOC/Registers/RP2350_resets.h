/*
; RP2350_resets.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_resets equates.
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

#include	<stdint.h>

// RESETS address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	RESET;
	volatile	uint32_t	WDSEL;
	volatile	uint32_t	RESET_DONE;
} RESETS_TypeDef;

#ifdef __cplusplus
#define	RESETS_NS	reinterpret_cast<RESETS_TypeDef *>(0x40020000u)
#define	RESETS_S	reinterpret_cast<RESETS_TypeDef *>(0x40020000u)
#else
#define	RESETS_NS	((RESETS_TypeDef *)0x40020000u)
#define	RESETS_S	((RESETS_TypeDef *)0x40020000u)
#endif

// RESET Configuration

#define	RESETS_RESET_ADC				(0x1u<<0)
#define	RESETS_RESET_BUSCTRL			(0x1u<<1)
#define	RESETS_RESET_DMA				(0x1u<<2)
#define	RESETS_RESET_HSTX				(0x1u<<3)
#define	RESETS_RESET_I2C0				(0x1u<<4)
#define	RESETS_RESET_I2C1				(0x1u<<5)
#define	RESETS_RESET_IO_BANK0			(0x1u<<6)
#define	RESETS_RESET_IO_QSPI			(0x1u<<7)
#define	RESETS_RESET_JTAG				(0x1u<<8)
#define	RESETS_RESET_PADS_BANK0			(0x1u<<9)
#define	RESETS_RESET_PADS_QSPI			(0x1u<<10)
#define	RESETS_RESET_PIO0				(0x1u<<11)
#define	RESETS_RESET_PIO1				(0x1u<<12)
#define	RESETS_RESET_PIO2				(0x1u<<13)
#define	RESETS_RESET_PLL_SYS			(0x1u<<14)
#define	RESETS_RESET_PLL_USB			(0x1u<<15)
#define	RESETS_RESET_PWM				(0x1u<<16)
#define	RESETS_RESET_SHA256				(0x1u<<17)
#define	RESETS_RESET_SPI0				(0x1u<<18)
#define	RESETS_RESET_SPI1				(0x1u<<19)
#define	RESETS_RESET_SYSCFG				(0x1u<<20)
#define	RESETS_RESET_SYSINFO			(0x1u<<21)
#define	RESETS_RESET_TBMAN				(0x1u<<22)
#define	RESETS_RESET_TIMER0				(0x1u<<23)
#define	RESETS_RESET_TIMER1				(0x1u<<24)
#define	RESETS_RESET_TRNG				(0x1u<<25)
#define	RESETS_RESET_UART0				(0x1u<<26)
#define	RESETS_RESET_UART1				(0x1u<<27)
#define	RESETS_RESET_USBCTRL			(0x1u<<28)

// WDSEL Configuration

#define	RESETS_WDSEL_ADC				(0x1u<<0)
#define	RESETS_WDSEL_BUSCTRL			(0x1u<<1)
#define	RESETS_WDSEL_DMA				(0x1u<<2)
#define	RESETS_WDSEL_HSTX				(0x1u<<3)
#define	RESETS_WDSEL_I2C0				(0x1u<<4)
#define	RESETS_WDSEL_I2C1				(0x1u<<5)
#define	RESETS_WDSEL_IO_BANK0			(0x1u<<6)
#define	RESETS_WDSEL_IO_QSPI			(0x1u<<7)
#define	RESETS_WDSEL_JTAG				(0x1u<<8)
#define	RESETS_WDSEL_PADS_BANK0			(0x1u<<9)
#define	RESETS_WDSEL_PADS_QSPI			(0x1u<<10)
#define	RESETS_WDSEL_PIO0				(0x1u<<11)
#define	RESETS_WDSEL_PIO1				(0x1u<<12)
#define	RESETS_WDSEL_PIO2				(0x1u<<13)
#define	RESETS_WDSEL_PLL_SYS			(0x1u<<14)
#define	RESETS_WDSEL_PLL_USB			(0x1u<<15)
#define	RESETS_WDSEL_PWM				(0x1u<<16)
#define	RESETS_WDSEL_SHA256				(0x1u<<17)
#define	RESETS_WDSEL_SPI0				(0x1u<<18)
#define	RESETS_WDSEL_SPI1				(0x1u<<19)
#define	RESETS_WDSEL_SYSCFG				(0x1u<<20)
#define	RESETS_WDSEL_SYSINFO			(0x1u<<21)
#define	RESETS_WDSEL_TBMAN				(0x1u<<22)
#define	RESETS_WDSEL_TIMER0				(0x1u<<23)
#define	RESETS_WDSEL_TIMER1				(0x1u<<24)
#define	RESETS_WDSEL_TRNG				(0x1u<<25)
#define	RESETS_WDSEL_UART0				(0x1u<<26)
#define	RESETS_WDSEL_UART1				(0x1u<<27)
#define	RESETS_WDSEL_USBCTRL			(0x1u<<28)

// RESET_DONE Configuration

#define	RESETS_RESET_DONE_ADC			(0x1u<<0)
#define	RESETS_RESET_DONE_BUSCTRL		(0x1u<<1)
#define	RESETS_RESET_DONE_DMA			(0x1u<<2)
#define	RESETS_RESET_DONE_HSTX			(0x1u<<3)
#define	RESETS_RESET_DONE_I2C0			(0x1u<<4)
#define	RESETS_RESET_DONE_I2C1			(0x1u<<5)
#define	RESETS_RESET_DONE_IO_BANK0		(0x1u<<6)
#define	RESETS_RESET_DONE_IO_QSPI		(0x1u<<7)
#define	RESETS_RESET_DONE_JTAG			(0x1u<<8)
#define	RESETS_RESET_DONE_PADS_BANK0	(0x1u<<9)
#define	RESETS_RESET_DONE_PADS_QSPI		(0x1u<<10)
#define	RESETS_RESET_DONE_PIO0			(0x1u<<11)
#define	RESETS_RESET_DONE_PIO1			(0x1u<<12)
#define	RESETS_RESET_DONE_PIO2			(0x1u<<13)
#define	RESETS_RESET_DONE_PLL_SYS		(0x1u<<14)
#define	RESETS_RESET_DONE_PLL_USB		(0x1u<<15)
#define	RESETS_RESET_DONE_PWM			(0x1u<<16)
#define	RESETS_RESET_DONE_SHA256		(0x1u<<17)
#define	RESETS_RESET_DONE_SPI0			(0x1u<<18)
#define	RESETS_RESET_DONE_SPI1			(0x1u<<19)
#define	RESETS_RESET_DONE_SYSCFG		(0x1u<<20)
#define	RESETS_RESET_DONE_SYSINFO		(0x1u<<21)
#define	RESETS_RESET_DONE_TBMAN			(0x1u<<22)
#define	RESETS_RESET_DONE_TIMER0		(0x1u<<23)
#define	RESETS_RESET_DONE_TIMER1		(0x1u<<24)
#define	RESETS_RESET_DONE_TRNG			(0x1u<<25)
#define	RESETS_RESET_DONE_UART0			(0x1u<<26)
#define	RESETS_RESET_DONE_UART1			(0x1u<<27)
#define	RESETS_RESET_DONE_USBCTRL		(0x1u<<28)
