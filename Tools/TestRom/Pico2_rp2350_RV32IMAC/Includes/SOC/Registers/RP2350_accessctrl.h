/*
; RP2350_accessctrl.
; ==================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_accessctrl equates.
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

// ACCESSCTRL address definitions
// ------------------------------

typedef struct {
	volatile	uint32_t	LOCK;
	volatile	uint32_t	FORCE_CORE_NS;
	volatile	uint32_t	CFGRESET;
	volatile	uint32_t	GPIO_NSMASK0;
	volatile	uint32_t	GPIO_NSMASK1;
	volatile	uint32_t	ROM;
	volatile	uint32_t	XIP_MAIN;
	volatile	uint32_t	SRAM0;
	volatile	uint32_t	SRAM1;
	volatile	uint32_t	SRAM2;
	volatile	uint32_t	SRAM3;
	volatile	uint32_t	SRAM4;
	volatile	uint32_t	SRAM5;
	volatile	uint32_t	SRAM6;
	volatile	uint32_t	SRAM7;
	volatile	uint32_t	SRAM8;
	volatile	uint32_t	SRAM9;
	volatile	uint32_t	DMA;
	volatile	uint32_t	USBCTRL;
	volatile	uint32_t	PIO0;
	volatile	uint32_t	PIO1;
	volatile	uint32_t	PIO2;
	volatile	uint32_t	CORESIGHT_TRACE;
	volatile	uint32_t	CORESIGHT_PERIPH;
	volatile	uint32_t	SYSINFO;
	volatile	uint32_t	RESETS;
	volatile	uint32_t	IO_BANK0;
	volatile	uint32_t	IO_BANK1;
	volatile	uint32_t	PADS_BANK0;
	volatile	uint32_t	PADS_QSPI;
	volatile	uint32_t	BUSCTRL;
	volatile	uint32_t	ADC0;
	volatile	uint32_t	HSTX;
	volatile	uint32_t	I2C0;
	volatile	uint32_t	I2C1;
	volatile	uint32_t	PWM;
	volatile	uint32_t	SPI0;
	volatile	uint32_t	SPI1;
	volatile	uint32_t	TIMER0;
	volatile	uint32_t	TIMER1;
	volatile	uint32_t	UART0;
	volatile	uint32_t	UART1;
	volatile	uint32_t	OTP;
	volatile	uint32_t	TBMAN;
	volatile	uint32_t	POWMAN;
	volatile	uint32_t	TRNG;
	volatile	uint32_t	SHA256;
	volatile	uint32_t	SYSCFG;
	volatile	uint32_t	CLOCKS;
	volatile	uint32_t	XOSC;
	volatile	uint32_t	ROSC;
	volatile	uint32_t	PLL_SYS;
	volatile	uint32_t	PLL_USB;
	volatile	uint32_t	TICKS;
	volatile	uint32_t	WATCHDOG;
	volatile	uint32_t	RSM;
	volatile	uint32_t	XIP_CTRL;
	volatile	uint32_t	XIP_QMI;
	volatile	uint32_t	XIP_AUX;
} ACCESSCTRL_TypeDef;

#ifdef __cplusplus
#define	ACCESSCTRL_NS	reinterpret_cast<ACCESSCTRL_TypeDef *>(0x40060000u)
#define	ACCESSCTRL_S	reinterpret_cast<ACCESSCTRL_TypeDef *>(0x40060000u)
#else
#define	ACCESSCTRL_NS	((ACCESSCTRL_TypeDef *)0x40060000u)
#define	ACCESSCTRL_S	((ACCESSCTRL_TypeDef *)0x40060000u)
#endif

// LOCK Configuration

#define	ACCESSCTRL_LOCK_CORE0					(0x1u<<0)
#define	ACCESSCTRL_LOCK_CORE1					(0x1u<<1)
#define	ACCESSCTRL_LOCK_DMA						(0x1u<<2)
#define	ACCESSCTRL_LOCK_DEBUG					(0x1u<<3)

// FORCE_CORE_NS Configuration

#define	ACCESSCTRL_FORCE_CORE_NS_CORE1			(0x1u<<1)

// CFGRESET Configuration

#define	ACCESSCTRL_CFGRESET_CFGRESET			(0x1u<<0)

// GPIO_NSMASK0 Configuration

#define	ACCESSCTRL_GPIO_NSMASK0_GPIO_NSMASK0	(0xFFFFFFFFu<<0)
#define	ACCESSCTRL_GPIO_NSMASK0_GPIO_NSMASK0_0	(0x1u<<0)

// GPIO_NSMASK1 Configuration

#define	ACCESSCTRL_GPIO_NSMASK1_GPIO			(0xFFFFu<<0)
#define	ACCESSCTRL_GPIO_NSMASK1_GPIO_0			(0x1u<<0)
#define	ACCESSCTRL_GPIO_NSMASK1_USB_DP			(0x1u<<24)
#define	ACCESSCTRL_GPIO_NSMASK1_USB_DM			(0x1u<<25)
#define	ACCESSCTRL_GPIO_NSMASK1_QSPI_SCK		(0x1u<<26)
#define	ACCESSCTRL_GPIO_NSMASK1_QSPI_CSN		(0x1u<<27)
#define	ACCESSCTRL_GPIO_NSMASK1_QSPI_SD			(0xFu<<28)
#define	ACCESSCTRL_GPIO_NSMASK1_QSPI_SD_0		(0x1u<<28)

// ROM Configuration

#define	ACCESSCTRL_ROM_NSU						(0x1u<<0)
#define	ACCESSCTRL_ROM_NSP						(0x1u<<1)
#define	ACCESSCTRL_ROM_SU						(0x1u<<2)
#define	ACCESSCTRL_ROM_SP						(0x1u<<3)
#define	ACCESSCTRL_ROM_CORE0					(0x1u<<4)
#define	ACCESSCTRL_ROM_CORE1					(0x1u<<5)
#define	ACCESSCTRL_ROM_DMA						(0x1u<<6)
#define	ACCESSCTRL_ROM_DBG						(0x1u<<7)

// XIP_MAIN Configuration

#define	ACCESSCTRL_XIP_MAIN_NSU					(0x1u<<0)
#define	ACCESSCTRL_XIP_MAIN_NSP					(0x1u<<1)
#define	ACCESSCTRL_XIP_MAIN_SU					(0x1u<<2)
#define	ACCESSCTRL_XIP_MAIN_SP					(0x1u<<3)
#define	ACCESSCTRL_XIP_MAIN_CORE0				(0x1u<<4)
#define	ACCESSCTRL_XIP_MAIN_CORE1				(0x1u<<5)
#define	ACCESSCTRL_XIP_MAIN_DMA					(0x1u<<6)
#define	ACCESSCTRL_XIP_MAIN_DBG					(0x1u<<7)

// SRAM0 Configuration

#define	ACCESSCTRL_SRAM0_NSU					(0x1u<<0)
#define	ACCESSCTRL_SRAM0_NSP					(0x1u<<1)
#define	ACCESSCTRL_SRAM0_SU						(0x1u<<2)
#define	ACCESSCTRL_SRAM0_SP						(0x1u<<3)
#define	ACCESSCTRL_SRAM0_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SRAM0_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SRAM0_DMA					(0x1u<<6)
#define	ACCESSCTRL_SRAM0_DBG					(0x1u<<7)

// SRAM1 Configuration

#define	ACCESSCTRL_SRAM1_NSU					(0x1u<<0)
#define	ACCESSCTRL_SRAM1_NSP					(0x1u<<1)
#define	ACCESSCTRL_SRAM1_SU						(0x1u<<2)
#define	ACCESSCTRL_SRAM1_SP						(0x1u<<3)
#define	ACCESSCTRL_SRAM1_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SRAM1_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SRAM1_DMA					(0x1u<<6)
#define	ACCESSCTRL_SRAM1_DBG					(0x1u<<7)

// SRAM2 Configuration

#define	ACCESSCTRL_SRAM2_NSU					(0x1u<<0)
#define	ACCESSCTRL_SRAM2_NSP					(0x1u<<1)
#define	ACCESSCTRL_SRAM2_SU						(0x1u<<2)
#define	ACCESSCTRL_SRAM2_SP						(0x1u<<3)
#define	ACCESSCTRL_SRAM2_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SRAM2_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SRAM2_DMA					(0x1u<<6)
#define	ACCESSCTRL_SRAM2_DBG					(0x1u<<7)

// SRAM3 Configuration

#define	ACCESSCTRL_SRAM3_NSU					(0x1u<<0)
#define	ACCESSCTRL_SRAM3_NSP					(0x1u<<1)
#define	ACCESSCTRL_SRAM3_SU						(0x1u<<2)
#define	ACCESSCTRL_SRAM3_SP						(0x1u<<3)
#define	ACCESSCTRL_SRAM3_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SRAM3_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SRAM3_DMA					(0x1u<<6)
#define	ACCESSCTRL_SRAM3_DBG					(0x1u<<7)

// SRAM4 Configuration

#define	ACCESSCTRL_SRAM4_NSU					(0x1u<<0)
#define	ACCESSCTRL_SRAM4_NSP					(0x1u<<1)
#define	ACCESSCTRL_SRAM4_SU						(0x1u<<2)
#define	ACCESSCTRL_SRAM4_SP						(0x1u<<3)
#define	ACCESSCTRL_SRAM4_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SRAM4_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SRAM4_DMA					(0x1u<<6)
#define	ACCESSCTRL_SRAM4_DBG					(0x1u<<7)

// SRAM5 Configuration

#define	ACCESSCTRL_SRAM5_NSU					(0x1u<<0)
#define	ACCESSCTRL_SRAM5_NSP					(0x1u<<1)
#define	ACCESSCTRL_SRAM5_SU						(0x1u<<2)
#define	ACCESSCTRL_SRAM5_SP						(0x1u<<3)
#define	ACCESSCTRL_SRAM5_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SRAM5_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SRAM5_DMA					(0x1u<<6)
#define	ACCESSCTRL_SRAM5_DBG					(0x1u<<7)

// SRAM6 Configuration

#define	ACCESSCTRL_SRAM6_NSU					(0x1u<<0)
#define	ACCESSCTRL_SRAM6_NSP					(0x1u<<1)
#define	ACCESSCTRL_SRAM6_SU						(0x1u<<2)
#define	ACCESSCTRL_SRAM6_SP						(0x1u<<3)
#define	ACCESSCTRL_SRAM6_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SRAM6_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SRAM6_DMA					(0x1u<<6)
#define	ACCESSCTRL_SRAM6_DBG					(0x1u<<7)

// SRAM7 Configuration

#define	ACCESSCTRL_SRAM7_NSU					(0x1u<<0)
#define	ACCESSCTRL_SRAM7_NSP					(0x1u<<1)
#define	ACCESSCTRL_SRAM7_SU						(0x1u<<2)
#define	ACCESSCTRL_SRAM7_SP						(0x1u<<3)
#define	ACCESSCTRL_SRAM7_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SRAM7_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SRAM7_DMA					(0x1u<<6)
#define	ACCESSCTRL_SRAM7_DBG					(0x1u<<7)

// SRAM8 Configuration

#define	ACCESSCTRL_SRAM8_NSU					(0x1u<<0)
#define	ACCESSCTRL_SRAM8_NSP					(0x1u<<1)
#define	ACCESSCTRL_SRAM8_SU						(0x1u<<2)
#define	ACCESSCTRL_SRAM8_SP						(0x1u<<3)
#define	ACCESSCTRL_SRAM8_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SRAM8_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SRAM8_DMA					(0x1u<<6)
#define	ACCESSCTRL_SRAM8_DBG					(0x1u<<7)

// SRAM9 Configuration

#define	ACCESSCTRL_SRAM9_NSU					(0x1u<<0)
#define	ACCESSCTRL_SRAM9_NSP					(0x1u<<1)
#define	ACCESSCTRL_SRAM9_SU						(0x1u<<2)
#define	ACCESSCTRL_SRAM9_SP						(0x1u<<3)
#define	ACCESSCTRL_SRAM9_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SRAM9_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SRAM9_DMA					(0x1u<<6)
#define	ACCESSCTRL_SRAM9_DBG					(0x1u<<7)

// DMA Configuration

#define	ACCESSCTRL_DMA_NSU						(0x1u<<0)
#define	ACCESSCTRL_DMA_NSP						(0x1u<<1)
#define	ACCESSCTRL_DMA_SU						(0x1u<<2)
#define	ACCESSCTRL_DMA_SP						(0x1u<<3)
#define	ACCESSCTRL_DMA_CORE0					(0x1u<<4)
#define	ACCESSCTRL_DMA_CORE1					(0x1u<<5)
#define	ACCESSCTRL_DMA_DMA						(0x1u<<6)
#define	ACCESSCTRL_DMA_DBG						(0x1u<<7)

// USBCTRL Configuration

#define	ACCESSCTRL_USBCTRL_NSU					(0x1u<<0)
#define	ACCESSCTRL_USBCTRL_NSP					(0x1u<<1)
#define	ACCESSCTRL_USBCTRL_SU					(0x1u<<2)
#define	ACCESSCTRL_USBCTRL_SP					(0x1u<<3)
#define	ACCESSCTRL_USBCTRL_CORE0				(0x1u<<4)
#define	ACCESSCTRL_USBCTRL_CORE1				(0x1u<<5)
#define	ACCESSCTRL_USBCTRL_DMA					(0x1u<<6)
#define	ACCESSCTRL_USBCTRL_DBG					(0x1u<<7)

// PIO0 Configuration

#define	ACCESSCTRL_PIO0_NSU						(0x1u<<0)
#define	ACCESSCTRL_PIO0_NSP						(0x1u<<1)
#define	ACCESSCTRL_PIO0_SU						(0x1u<<2)
#define	ACCESSCTRL_PIO0_SP						(0x1u<<3)
#define	ACCESSCTRL_PIO0_CORE0					(0x1u<<4)
#define	ACCESSCTRL_PIO0_CORE1					(0x1u<<5)
#define	ACCESSCTRL_PIO0_DMA						(0x1u<<6)
#define	ACCESSCTRL_PIO0_DBG						(0x1u<<7)

// PIO1 Configuration

#define	ACCESSCTRL_PIO1_NSU						(0x1u<<0)
#define	ACCESSCTRL_PIO1_NSP						(0x1u<<1)
#define	ACCESSCTRL_PIO1_SU						(0x1u<<2)
#define	ACCESSCTRL_PIO1_SP						(0x1u<<3)
#define	ACCESSCTRL_PIO1_CORE0					(0x1u<<4)
#define	ACCESSCTRL_PIO1_CORE1					(0x1u<<5)
#define	ACCESSCTRL_PIO1_DMA						(0x1u<<6)
#define	ACCESSCTRL_PIO1_DBG						(0x1u<<7)

// PIO2 Configuration

#define	ACCESSCTRL_PIO2_NSU						(0x1u<<0)
#define	ACCESSCTRL_PIO2_NSP						(0x1u<<1)
#define	ACCESSCTRL_PIO2_SU						(0x1u<<2)
#define	ACCESSCTRL_PIO2_SP						(0x1u<<3)
#define	ACCESSCTRL_PIO2_CORE0					(0x1u<<4)
#define	ACCESSCTRL_PIO2_CORE1					(0x1u<<5)
#define	ACCESSCTRL_PIO2_DMA						(0x1u<<6)
#define	ACCESSCTRL_PIO2_DBG						(0x1u<<7)

// CORESIGHT_TRACE Configuration

#define	ACCESSCTRL_CORESIGHT_TRACE_NSU			(0x1u<<0)
#define	ACCESSCTRL_CORESIGHT_TRACE_NSP			(0x1u<<1)
#define	ACCESSCTRL_CORESIGHT_TRACE_SU			(0x1u<<2)
#define	ACCESSCTRL_CORESIGHT_TRACE_SP			(0x1u<<3)
#define	ACCESSCTRL_CORESIGHT_TRACE_CORE0		(0x1u<<4)
#define	ACCESSCTRL_CORESIGHT_TRACE_CORE1		(0x1u<<5)
#define	ACCESSCTRL_CORESIGHT_TRACE_DMA			(0x1u<<6)
#define	ACCESSCTRL_CORESIGHT_TRACE_DBG			(0x1u<<7)

// CORESIGHT_PERIPH Configuration

#define	ACCESSCTRL_CORESIGHT_PERIPH_NSU			(0x1u<<0)
#define	ACCESSCTRL_CORESIGHT_PERIPH_NSP			(0x1u<<1)
#define	ACCESSCTRL_CORESIGHT_PERIPH_SU			(0x1u<<2)
#define	ACCESSCTRL_CORESIGHT_PERIPH_SP			(0x1u<<3)
#define	ACCESSCTRL_CORESIGHT_PERIPH_CORE0		(0x1u<<4)
#define	ACCESSCTRL_CORESIGHT_PERIPH_CORE1		(0x1u<<5)
#define	ACCESSCTRL_CORESIGHT_PERIPH_DMA			(0x1u<<6)
#define	ACCESSCTRL_CORESIGHT_PERIPH_DBG			(0x1u<<7)

// SYSINFO Configuration

#define	ACCESSCTRL_SYSINFO_NSU					(0x1u<<0)
#define	ACCESSCTRL_SYSINFO_NSP					(0x1u<<1)
#define	ACCESSCTRL_SYSINFO_SU					(0x1u<<2)
#define	ACCESSCTRL_SYSINFO_SP					(0x1u<<3)
#define	ACCESSCTRL_SYSINFO_CORE0				(0x1u<<4)
#define	ACCESSCTRL_SYSINFO_CORE1				(0x1u<<5)
#define	ACCESSCTRL_SYSINFO_DMA					(0x1u<<6)
#define	ACCESSCTRL_SYSINFO_DBG					(0x1u<<7)

// RESETS Configuration

#define	ACCESSCTRL_RESETS_NSU					(0x1u<<0)
#define	ACCESSCTRL_RESETS_NSP					(0x1u<<1)
#define	ACCESSCTRL_RESETS_SU					(0x1u<<2)
#define	ACCESSCTRL_RESETS_SP					(0x1u<<3)
#define	ACCESSCTRL_RESETS_CORE0					(0x1u<<4)
#define	ACCESSCTRL_RESETS_CORE1					(0x1u<<5)
#define	ACCESSCTRL_RESETS_DMA					(0x1u<<6)
#define	ACCESSCTRL_RESETS_DBG					(0x1u<<7)

// IO_BANK0 Configuration

#define	ACCESSCTRL_IO_BANK0_NSU					(0x1u<<0)
#define	ACCESSCTRL_IO_BANK0_NSP					(0x1u<<1)
#define	ACCESSCTRL_IO_BANK0_SU					(0x1u<<2)
#define	ACCESSCTRL_IO_BANK0_SP					(0x1u<<3)
#define	ACCESSCTRL_IO_BANK0_CORE0				(0x1u<<4)
#define	ACCESSCTRL_IO_BANK0_CORE1				(0x1u<<5)
#define	ACCESSCTRL_IO_BANK0_DMA					(0x1u<<6)
#define	ACCESSCTRL_IO_BANK0_DBG					(0x1u<<7)

// IO_BANK1 Configuration

#define	ACCESSCTRL_IO_BANK1_NSU					(0x1u<<0)
#define	ACCESSCTRL_IO_BANK1_NSP					(0x1u<<1)
#define	ACCESSCTRL_IO_BANK1_SU					(0x1u<<2)
#define	ACCESSCTRL_IO_BANK1_SP					(0x1u<<3)
#define	ACCESSCTRL_IO_BANK1_CORE0				(0x1u<<4)
#define	ACCESSCTRL_IO_BANK1_CORE1				(0x1u<<5)
#define	ACCESSCTRL_IO_BANK1_DMA					(0x1u<<6)
#define	ACCESSCTRL_IO_BANK1_DBG					(0x1u<<7)

// PADS_BANK0 Configuration

#define	ACCESSCTRL_PADS_BANK0_NSU				(0x1u<<0)
#define	ACCESSCTRL_PADS_BANK0_NSP				(0x1u<<1)
#define	ACCESSCTRL_PADS_BANK0_SU				(0x1u<<2)
#define	ACCESSCTRL_PADS_BANK0_SP				(0x1u<<3)
#define	ACCESSCTRL_PADS_BANK0_CORE0				(0x1u<<4)
#define	ACCESSCTRL_PADS_BANK0_CORE1				(0x1u<<5)
#define	ACCESSCTRL_PADS_BANK0_DMA				(0x1u<<6)
#define	ACCESSCTRL_PADS_BANK0_DBG				(0x1u<<7)

// PADS_QSPI Configuration

#define	ACCESSCTRL_PADS_QSPI_NSU				(0x1u<<0)
#define	ACCESSCTRL_PADS_QSPI_NSP				(0x1u<<1)
#define	ACCESSCTRL_PADS_QSPI_SU					(0x1u<<2)
#define	ACCESSCTRL_PADS_QSPI_SP					(0x1u<<3)
#define	ACCESSCTRL_PADS_QSPI_CORE0				(0x1u<<4)
#define	ACCESSCTRL_PADS_QSPI_CORE1				(0x1u<<5)
#define	ACCESSCTRL_PADS_QSPI_DMA				(0x1u<<6)
#define	ACCESSCTRL_PADS_QSPI_DBG				(0x1u<<7)

// BUSCTRL Configuration

#define	ACCESSCTRL_BUSCTRL_NSU					(0x1u<<0)
#define	ACCESSCTRL_BUSCTRL_NSP					(0x1u<<1)
#define	ACCESSCTRL_BUSCTRL_SU					(0x1u<<2)
#define	ACCESSCTRL_BUSCTRL_SP					(0x1u<<3)
#define	ACCESSCTRL_BUSCTRL_CORE0				(0x1u<<4)
#define	ACCESSCTRL_BUSCTRL_CORE1				(0x1u<<5)
#define	ACCESSCTRL_BUSCTRL_DMA					(0x1u<<6)
#define	ACCESSCTRL_BUSCTRL_DBG					(0x1u<<7)

// ADC0 Configuration

#define	ACCESSCTRL_ADC0_NSU						(0x1u<<0)
#define	ACCESSCTRL_ADC0_NSP						(0x1u<<1)
#define	ACCESSCTRL_ADC0_SU						(0x1u<<2)
#define	ACCESSCTRL_ADC0_SP						(0x1u<<3)
#define	ACCESSCTRL_ADC0_CORE0					(0x1u<<4)
#define	ACCESSCTRL_ADC0_CORE1					(0x1u<<5)
#define	ACCESSCTRL_ADC0_DMA						(0x1u<<6)
#define	ACCESSCTRL_ADC0_DBG						(0x1u<<7)

// HSTX Configuration

#define	ACCESSCTRL_HSTX_NSU						(0x1u<<0)
#define	ACCESSCTRL_HSTX_NSP						(0x1u<<1)
#define	ACCESSCTRL_HSTX_SU						(0x1u<<2)
#define	ACCESSCTRL_HSTX_SP						(0x1u<<3)
#define	ACCESSCTRL_HSTX_CORE0					(0x1u<<4)
#define	ACCESSCTRL_HSTX_CORE1					(0x1u<<5)
#define	ACCESSCTRL_HSTX_DMA						(0x1u<<6)
#define	ACCESSCTRL_HSTX_DBG						(0x1u<<7)

// I2C0 Configuration

#define	ACCESSCTRL_I2C0_NSU						(0x1u<<0)
#define	ACCESSCTRL_I2C0_NSP						(0x1u<<1)
#define	ACCESSCTRL_I2C0_SU						(0x1u<<2)
#define	ACCESSCTRL_I2C0_SP						(0x1u<<3)
#define	ACCESSCTRL_I2C0_CORE0					(0x1u<<4)
#define	ACCESSCTRL_I2C0_CORE1					(0x1u<<5)
#define	ACCESSCTRL_I2C0_DMA						(0x1u<<6)
#define	ACCESSCTRL_I2C0_DBG						(0x1u<<7)

// I2C1 Configuration

#define	ACCESSCTRL_I2C1_NSU						(0x1u<<0)
#define	ACCESSCTRL_I2C1_NSP						(0x1u<<1)
#define	ACCESSCTRL_I2C1_SU						(0x1u<<2)
#define	ACCESSCTRL_I2C1_SP						(0x1u<<3)
#define	ACCESSCTRL_I2C1_CORE0					(0x1u<<4)
#define	ACCESSCTRL_I2C1_CORE1					(0x1u<<5)
#define	ACCESSCTRL_I2C1_DMA						(0x1u<<6)
#define	ACCESSCTRL_I2C1_DBG						(0x1u<<7)

// PWM Configuration

#define	ACCESSCTRL_PWM_NSU						(0x1u<<0)
#define	ACCESSCTRL_PWM_NSP						(0x1u<<1)
#define	ACCESSCTRL_PWM_SU						(0x1u<<2)
#define	ACCESSCTRL_PWM_SP						(0x1u<<3)
#define	ACCESSCTRL_PWM_CORE0					(0x1u<<4)
#define	ACCESSCTRL_PWM_CORE1					(0x1u<<5)
#define	ACCESSCTRL_PWM_DMA						(0x1u<<6)
#define	ACCESSCTRL_PWM_DBG						(0x1u<<7)

// SPI0 Configuration

#define	ACCESSCTRL_SPI0_NSU						(0x1u<<0)
#define	ACCESSCTRL_SPI0_NSP						(0x1u<<1)
#define	ACCESSCTRL_SPI0_SU						(0x1u<<2)
#define	ACCESSCTRL_SPI0_SP						(0x1u<<3)
#define	ACCESSCTRL_SPI0_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SPI0_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SPI0_DMA						(0x1u<<6)
#define	ACCESSCTRL_SPI0_DBG						(0x1u<<7)

// SPI1 Configuration

#define	ACCESSCTRL_SPI1_NSU						(0x1u<<0)
#define	ACCESSCTRL_SPI1_NSP						(0x1u<<1)
#define	ACCESSCTRL_SPI1_SU						(0x1u<<2)
#define	ACCESSCTRL_SPI1_SP						(0x1u<<3)
#define	ACCESSCTRL_SPI1_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SPI1_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SPI1_DMA						(0x1u<<6)
#define	ACCESSCTRL_SPI1_DBG						(0x1u<<7)

// TIMER0 Configuration

#define	ACCESSCTRL_TIMER0_NSU					(0x1u<<0)
#define	ACCESSCTRL_TIMER0_NSP					(0x1u<<1)
#define	ACCESSCTRL_TIMER0_SU					(0x1u<<2)
#define	ACCESSCTRL_TIMER0_SP					(0x1u<<3)
#define	ACCESSCTRL_TIMER0_CORE0					(0x1u<<4)
#define	ACCESSCTRL_TIMER0_CORE1					(0x1u<<5)
#define	ACCESSCTRL_TIMER0_DMA					(0x1u<<6)
#define	ACCESSCTRL_TIMER0_DBG					(0x1u<<7)

// TIMER1 Configuration

#define	ACCESSCTRL_TIMER1_NSU					(0x1u<<0)
#define	ACCESSCTRL_TIMER1_NSP					(0x1u<<1)
#define	ACCESSCTRL_TIMER1_SU					(0x1u<<2)
#define	ACCESSCTRL_TIMER1_SP					(0x1u<<3)
#define	ACCESSCTRL_TIMER1_CORE0					(0x1u<<4)
#define	ACCESSCTRL_TIMER1_CORE1					(0x1u<<5)
#define	ACCESSCTRL_TIMER1_DMA					(0x1u<<6)
#define	ACCESSCTRL_TIMER1_DBG					(0x1u<<7)

// UART0 Configuration

#define	ACCESSCTRL_UART0_NSU					(0x1u<<0)
#define	ACCESSCTRL_UART0_NSP					(0x1u<<1)
#define	ACCESSCTRL_UART0_SU						(0x1u<<2)
#define	ACCESSCTRL_UART0_SP						(0x1u<<3)
#define	ACCESSCTRL_UART0_CORE0					(0x1u<<4)
#define	ACCESSCTRL_UART0_CORE1					(0x1u<<5)
#define	ACCESSCTRL_UART0_DMA					(0x1u<<6)
#define	ACCESSCTRL_UART0_DBG					(0x1u<<7)

// UART1 Configuration

#define	ACCESSCTRL_UART1_NSU					(0x1u<<0)
#define	ACCESSCTRL_UART1_NSP					(0x1u<<1)
#define	ACCESSCTRL_UART1_SU						(0x1u<<2)
#define	ACCESSCTRL_UART1_SP						(0x1u<<3)
#define	ACCESSCTRL_UART1_CORE0					(0x1u<<4)
#define	ACCESSCTRL_UART1_CORE1					(0x1u<<5)
#define	ACCESSCTRL_UART1_DMA					(0x1u<<6)
#define	ACCESSCTRL_UART1_DBG					(0x1u<<7)

// OTP Configuration

#define	ACCESSCTRL_OTP_NSU						(0x1u<<0)
#define	ACCESSCTRL_OTP_NSP						(0x1u<<1)
#define	ACCESSCTRL_OTP_SU						(0x1u<<2)
#define	ACCESSCTRL_OTP_SP						(0x1u<<3)
#define	ACCESSCTRL_OTP_CORE0					(0x1u<<4)
#define	ACCESSCTRL_OTP_CORE1					(0x1u<<5)
#define	ACCESSCTRL_OTP_DMA						(0x1u<<6)
#define	ACCESSCTRL_OTP_DBG						(0x1u<<7)

// TBMAN Configuration

#define	ACCESSCTRL_TBMAN_NSU					(0x1u<<0)
#define	ACCESSCTRL_TBMAN_NSP					(0x1u<<1)
#define	ACCESSCTRL_TBMAN_SU						(0x1u<<2)
#define	ACCESSCTRL_TBMAN_SP						(0x1u<<3)
#define	ACCESSCTRL_TBMAN_CORE0					(0x1u<<4)
#define	ACCESSCTRL_TBMAN_CORE1					(0x1u<<5)
#define	ACCESSCTRL_TBMAN_DMA					(0x1u<<6)
#define	ACCESSCTRL_TBMAN_DBG					(0x1u<<7)

// POWMAN Configuration

#define	ACCESSCTRL_POWMAN_NSU					(0x1u<<0)
#define	ACCESSCTRL_POWMAN_NSP					(0x1u<<1)
#define	ACCESSCTRL_POWMAN_SU					(0x1u<<2)
#define	ACCESSCTRL_POWMAN_SP					(0x1u<<3)
#define	ACCESSCTRL_POWMAN_CORE0					(0x1u<<4)
#define	ACCESSCTRL_POWMAN_CORE1					(0x1u<<5)
#define	ACCESSCTRL_POWMAN_DMA					(0x1u<<6)
#define	ACCESSCTRL_POWMAN_DBG					(0x1u<<7)

// TRNG Configuration

#define	ACCESSCTRL_TRNG_NSU						(0x1u<<0)
#define	ACCESSCTRL_TRNG_NSP						(0x1u<<1)
#define	ACCESSCTRL_TRNG_SU						(0x1u<<2)
#define	ACCESSCTRL_TRNG_SP						(0x1u<<3)
#define	ACCESSCTRL_TRNG_CORE0					(0x1u<<4)
#define	ACCESSCTRL_TRNG_CORE1					(0x1u<<5)
#define	ACCESSCTRL_TRNG_DMA						(0x1u<<6)
#define	ACCESSCTRL_TRNG_DBG						(0x1u<<7)

// SHA256 Configuration

#define	ACCESSCTRL_SHA256_NSU					(0x1u<<0)
#define	ACCESSCTRL_SHA256_NSP					(0x1u<<1)
#define	ACCESSCTRL_SHA256_SU					(0x1u<<2)
#define	ACCESSCTRL_SHA256_SP					(0x1u<<3)
#define	ACCESSCTRL_SHA256_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SHA256_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SHA256_DMA					(0x1u<<6)
#define	ACCESSCTRL_SHA256_DBG					(0x1u<<7)

// SYSCFG Configuration

#define	ACCESSCTRL_SYSCFG_NSU					(0x1u<<0)
#define	ACCESSCTRL_SYSCFG_NSP					(0x1u<<1)
#define	ACCESSCTRL_SYSCFG_SU					(0x1u<<2)
#define	ACCESSCTRL_SYSCFG_SP					(0x1u<<3)
#define	ACCESSCTRL_SYSCFG_CORE0					(0x1u<<4)
#define	ACCESSCTRL_SYSCFG_CORE1					(0x1u<<5)
#define	ACCESSCTRL_SYSCFG_DMA					(0x1u<<6)
#define	ACCESSCTRL_SYSCFG_DBG					(0x1u<<7)

// CLOCKS Configuration

#define	ACCESSCTRL_CLOCKS_NSU					(0x1u<<0)
#define	ACCESSCTRL_CLOCKS_NSP					(0x1u<<1)
#define	ACCESSCTRL_CLOCKS_SU					(0x1u<<2)
#define	ACCESSCTRL_CLOCKS_SP					(0x1u<<3)
#define	ACCESSCTRL_CLOCKS_CORE0					(0x1u<<4)
#define	ACCESSCTRL_CLOCKS_CORE1					(0x1u<<5)
#define	ACCESSCTRL_CLOCKS_DMA					(0x1u<<6)
#define	ACCESSCTRL_CLOCKS_DBG					(0x1u<<7)

// XOSC Configuration

#define	ACCESSCTRL_XOSC_NSU						(0x1u<<0)
#define	ACCESSCTRL_XOSC_NSP						(0x1u<<1)
#define	ACCESSCTRL_XOSC_SU						(0x1u<<2)
#define	ACCESSCTRL_XOSC_SP						(0x1u<<3)
#define	ACCESSCTRL_XOSC_CORE0					(0x1u<<4)
#define	ACCESSCTRL_XOSC_CORE1					(0x1u<<5)
#define	ACCESSCTRL_XOSC_DMA						(0x1u<<6)
#define	ACCESSCTRL_XOSC_DBG						(0x1u<<7)

// ROSC Configuration

#define	ACCESSCTRL_ROSC_NSU						(0x1u<<0)
#define	ACCESSCTRL_ROSC_NSP						(0x1u<<1)
#define	ACCESSCTRL_ROSC_SU						(0x1u<<2)
#define	ACCESSCTRL_ROSC_SP						(0x1u<<3)
#define	ACCESSCTRL_ROSC_CORE0					(0x1u<<4)
#define	ACCESSCTRL_ROSC_CORE1					(0x1u<<5)
#define	ACCESSCTRL_ROSC_DMA						(0x1u<<6)
#define	ACCESSCTRL_ROSC_DBG						(0x1u<<7)

// PLL_SYS Configuration

#define	ACCESSCTRL_PLL_SYS_NSU					(0x1u<<0)
#define	ACCESSCTRL_PLL_SYS_NSP					(0x1u<<1)
#define	ACCESSCTRL_PLL_SYS_SU					(0x1u<<2)
#define	ACCESSCTRL_PLL_SYS_SP					(0x1u<<3)
#define	ACCESSCTRL_PLL_SYS_CORE0				(0x1u<<4)
#define	ACCESSCTRL_PLL_SYS_CORE1				(0x1u<<5)
#define	ACCESSCTRL_PLL_SYS_DMA					(0x1u<<6)
#define	ACCESSCTRL_PLL_SYS_DBG					(0x1u<<7)

// PLL_USB Configuration

#define	ACCESSCTRL_PLL_USB_NSU					(0x1u<<0)
#define	ACCESSCTRL_PLL_USB_NSP					(0x1u<<1)
#define	ACCESSCTRL_PLL_USB_SU					(0x1u<<2)
#define	ACCESSCTRL_PLL_USB_SP					(0x1u<<3)
#define	ACCESSCTRL_PLL_USB_CORE0				(0x1u<<4)
#define	ACCESSCTRL_PLL_USB_CORE1				(0x1u<<5)
#define	ACCESSCTRL_PLL_USB_DMA					(0x1u<<6)
#define	ACCESSCTRL_PLL_USB_DBG					(0x1u<<7)

// TICKS Configuration

#define	ACCESSCTRL_TICKS_NSU					(0x1u<<0)
#define	ACCESSCTRL_TICKS_NSP					(0x1u<<1)
#define	ACCESSCTRL_TICKS_SU						(0x1u<<2)
#define	ACCESSCTRL_TICKS_SP						(0x1u<<3)
#define	ACCESSCTRL_TICKS_CORE0					(0x1u<<4)
#define	ACCESSCTRL_TICKS_CORE1					(0x1u<<5)
#define	ACCESSCTRL_TICKS_DMA					(0x1u<<6)
#define	ACCESSCTRL_TICKS_DBG					(0x1u<<7)

// WATCHDOG Configuration

#define	ACCESSCTRL_WATCHDOG_NSU					(0x1u<<0)
#define	ACCESSCTRL_WATCHDOG_NSP					(0x1u<<1)
#define	ACCESSCTRL_WATCHDOG_SU					(0x1u<<2)
#define	ACCESSCTRL_WATCHDOG_SP					(0x1u<<3)
#define	ACCESSCTRL_WATCHDOG_CORE0				(0x1u<<4)
#define	ACCESSCTRL_WATCHDOG_CORE1				(0x1u<<5)
#define	ACCESSCTRL_WATCHDOG_DMA					(0x1u<<6)
#define	ACCESSCTRL_WATCHDOG_DBG					(0x1u<<7)

// RSM Configuration

#define	ACCESSCTRL_RSM_NSU						(0x1u<<0)
#define	ACCESSCTRL_RSM_NSP						(0x1u<<1)
#define	ACCESSCTRL_RSM_SU						(0x1u<<2)
#define	ACCESSCTRL_RSM_SP						(0x1u<<3)
#define	ACCESSCTRL_RSM_CORE0					(0x1u<<4)
#define	ACCESSCTRL_RSM_CORE1					(0x1u<<5)
#define	ACCESSCTRL_RSM_DMA						(0x1u<<6)
#define	ACCESSCTRL_RSM_DBG						(0x1u<<7)

// XIP_CTRL Configuration

#define	ACCESSCTRL_XIP_CTRL_NSU					(0x1u<<0)
#define	ACCESSCTRL_XIP_CTRL_NSP					(0x1u<<1)
#define	ACCESSCTRL_XIP_CTRL_SU					(0x1u<<2)
#define	ACCESSCTRL_XIP_CTRL_SP					(0x1u<<3)
#define	ACCESSCTRL_XIP_CTRL_CORE0				(0x1u<<4)
#define	ACCESSCTRL_XIP_CTRL_CORE1				(0x1u<<5)
#define	ACCESSCTRL_XIP_CTRL_DMA					(0x1u<<6)
#define	ACCESSCTRL_XIP_CTRL_DBG					(0x1u<<7)

// XIP_QMI Configuration

#define	ACCESSCTRL_XIP_QMI_NSU					(0x1u<<0)
#define	ACCESSCTRL_XIP_QMI_NSP					(0x1u<<1)
#define	ACCESSCTRL_XIP_QMI_SU					(0x1u<<2)
#define	ACCESSCTRL_XIP_QMI_SP					(0x1u<<3)
#define	ACCESSCTRL_XIP_QMI_CORE0				(0x1u<<4)
#define	ACCESSCTRL_XIP_QMI_CORE1				(0x1u<<5)
#define	ACCESSCTRL_XIP_QMI_DMA					(0x1u<<6)
#define	ACCESSCTRL_XIP_QMI_DBG					(0x1u<<7)

// XIP_AUX Configuration

#define	ACCESSCTRL_XIP_AUX_NSU					(0x1u<<0)
#define	ACCESSCTRL_XIP_AUX_NSP					(0x1u<<1)
#define	ACCESSCTRL_XIP_AUX_SU					(0x1u<<2)
#define	ACCESSCTRL_XIP_AUX_SP					(0x1u<<3)
#define	ACCESSCTRL_XIP_AUX_CORE0				(0x1u<<4)
#define	ACCESSCTRL_XIP_AUX_CORE1				(0x1u<<5)
#define	ACCESSCTRL_XIP_AUX_DMA					(0x1u<<6)
#define	ACCESSCTRL_XIP_AUX_DBG					(0x1u<<7)
