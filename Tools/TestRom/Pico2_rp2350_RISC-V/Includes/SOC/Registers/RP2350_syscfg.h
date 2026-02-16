/*
; RP2350_syscfg.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_syscfg equates.
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

// SYSCFG address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	PROC_CONFIG;
	volatile	uint32_t	PROC_IN_SYNC_BYPASS;
	volatile	uint32_t	PROC_IN_SYNC_BYPASS_HI;
	volatile	uint32_t	DBGFORCE;
	volatile	uint32_t	MEMPOWERDOWN;
	volatile	uint32_t	AUXCTRL;
} SYSCFG_TypeDef;

#ifdef __cplusplus
#define	SYSCFG_NS	reinterpret_cast<SYSCFG_TypeDef *>(0x40008000u)
#define	SYSCFG_S	reinterpret_cast<SYSCFG_TypeDef *>(0x40008000u)
#else
#define	SYSCFG_NS	((SYSCFG_TypeDef *)0x40008000u)
#define	SYSCFG_S	((SYSCFG_TypeDef *)0x40008000u)
#endif

// PROC_CONFIG Configuration

#define	SYSCFG_PROC_CONFIG_PROC0_HALTED			(0x1u<<0)
#define	SYSCFG_PROC_CONFIG_PROC1_HALTED			(0x1u<<1)

// PROC_IN_SYNC_BYPASS Configuration

#define	SYSCFG_PROC_IN_SYNC_BYPASS_GPIO			(0xFFFFFFFFu<<0)
#define	SYSCFG_PROC_IN_SYNC_BYPASS_GPIO_0		(0x1u<<0)

// PROC_IN_SYNC_BYPASS_HI Configuration

#define	SYSCFG_PROC_IN_SYNC_BYPASS_HI_GPIO		(0xFFFFu<<0)
#define	SYSCFG_PROC_IN_SYNC_BYPASS_HI_GPIO_0	(0x1u<<0)
#define	SYSCFG_PROC_IN_SYNC_BYPASS_HI_USB_DP	(0x1u<<24)
#define	SYSCFG_PROC_IN_SYNC_BYPASS_HI_USB_DM	(0x1u<<25)
#define	SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_SCK	(0x1u<<26)
#define	SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_CSN	(0x1u<<27)
#define	SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_SD	(0xFu<<28)
#define	SYSCFG_PROC_IN_SYNC_BYPASS_HI_QSPI_SD_0	(0x1u<<28)

// DBGFORCE Configuration

#define	SYSCFG_DBGFORCE_SWDO					(0x1u<<0)
#define	SYSCFG_DBGFORCE_SWDI					(0x1u<<1)
#define	SYSCFG_DBGFORCE_SWCLK					(0x1u<<2)
#define	SYSCFG_DBGFORCE_ATTACH					(0x1u<<3)

// MEMPOWERDOWN Configuration

#define	SYSCFG_MEMPOWERDOWN_SRAM0				(0x1u<<0)
#define	SYSCFG_MEMPOWERDOWN_SRAM1				(0x1u<<1)
#define	SYSCFG_MEMPOWERDOWN_SRAM2				(0x1u<<2)
#define	SYSCFG_MEMPOWERDOWN_SRAM3				(0x1u<<3)
#define	SYSCFG_MEMPOWERDOWN_SRAM4				(0x1u<<4)
#define	SYSCFG_MEMPOWERDOWN_SRAM5				(0x1u<<5)
#define	SYSCFG_MEMPOWERDOWN_SRAM6				(0x1u<<6)
#define	SYSCFG_MEMPOWERDOWN_SRAM7				(0x1u<<7)
#define	SYSCFG_MEMPOWERDOWN_SRAM8				(0x1u<<8)
#define	SYSCFG_MEMPOWERDOWN_SRAM9				(0x1u<<9)
#define	SYSCFG_MEMPOWERDOWN_USB					(0x1u<<10)
#define	SYSCFG_MEMPOWERDOWN_ROM					(0x1u<<11)
#define	SYSCFG_MEMPOWERDOWN_BOOTRAM				(0x1u<<12)

// AUXCTRL Configuration

#define	SYSCFG_AUXCTRL_AUXCTRL					(0xFFu<<0)
#define	SYSCFG_AUXCTRL_AUXCTRL_0				(0x1u<<0)
