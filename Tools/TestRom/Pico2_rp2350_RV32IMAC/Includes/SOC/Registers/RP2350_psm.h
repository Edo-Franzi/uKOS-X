/*
; RP2350_psm.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_psm equates.
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

// PSM address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	FRCE_ON;
	volatile	uint32_t	FRCE_OFF;
	volatile	uint32_t	WDSEL;
	volatile	uint32_t	DONE;
} PSM_TypeDef;

#ifdef __cplusplus
#define	PSM_NS	reinterpret_cast<PSM_TypeDef *>(0x40018000u)
#define	PSM_S	reinterpret_cast<PSM_TypeDef *>(0x40018000u)
#else
#define	PSM_NS	((PSM_TypeDef *)0x40018000u)
#define	PSM_S	((PSM_TypeDef *)0x40018000u)
#endif

// FRCE_ON Configuration

#define	PSM_FRCE_ON_PROC_COLD	(0x1u<<0)
#define	PSM_FRCE_ON_OTP			(0x1u<<1)
#define	PSM_FRCE_ON_ROSC		(0x1u<<2)
#define	PSM_FRCE_ON_XOSC		(0x1u<<3)
#define	PSM_FRCE_ON_RESETS		(0x1u<<4)
#define	PSM_FRCE_ON_CLOCKS		(0x1u<<5)
#define	PSM_FRCE_ON_PSM_READY	(0x1u<<6)
#define	PSM_FRCE_ON_BUSFABRIC	(0x1u<<7)
#define	PSM_FRCE_ON_ROM			(0x1u<<8)
#define	PSM_FRCE_ON_BOOTRAM		(0x1u<<9)
#define	PSM_FRCE_ON_SRAM0		(0x1u<<10)
#define	PSM_FRCE_ON_SRAM1		(0x1u<<11)
#define	PSM_FRCE_ON_SRAM2		(0x1u<<12)
#define	PSM_FRCE_ON_SRAM3		(0x1u<<13)
#define	PSM_FRCE_ON_SRAM4		(0x1u<<14)
#define	PSM_FRCE_ON_SRAM5		(0x1u<<15)
#define	PSM_FRCE_ON_SRAM6		(0x1u<<16)
#define	PSM_FRCE_ON_SRAM7		(0x1u<<17)
#define	PSM_FRCE_ON_SRAM8		(0x1u<<18)
#define	PSM_FRCE_ON_SRAM9		(0x1u<<19)
#define	PSM_FRCE_ON_XIP			(0x1u<<20)
#define	PSM_FRCE_ON_SIO			(0x1u<<21)
#define	PSM_FRCE_ON_ACCESSCTRL	(0x1u<<22)
#define	PSM_FRCE_ON_PROC0		(0x1u<<23)
#define	PSM_FRCE_ON_PROC1		(0x1u<<24)

// FRCE_OFF Configuration

#define	PSM_FRCE_OFF_PROC_COLD	(0x1u<<0)
#define	PSM_FRCE_OFF_OTP		(0x1u<<1)
#define	PSM_FRCE_OFF_ROSC		(0x1u<<2)
#define	PSM_FRCE_OFF_XOSC		(0x1u<<3)
#define	PSM_FRCE_OFF_RESETS		(0x1u<<4)
#define	PSM_FRCE_OFF_CLOCKS		(0x1u<<5)
#define	PSM_FRCE_OFF_PSM_READY	(0x1u<<6)
#define	PSM_FRCE_OFF_BUSFABRIC	(0x1u<<7)
#define	PSM_FRCE_OFF_ROM		(0x1u<<8)
#define	PSM_FRCE_OFF_BOOTRAM	(0x1u<<9)
#define	PSM_FRCE_OFF_SRAM0		(0x1u<<10)
#define	PSM_FRCE_OFF_SRAM1		(0x1u<<11)
#define	PSM_FRCE_OFF_SRAM2		(0x1u<<12)
#define	PSM_FRCE_OFF_SRAM3		(0x1u<<13)
#define	PSM_FRCE_OFF_SRAM4		(0x1u<<14)
#define	PSM_FRCE_OFF_SRAM5		(0x1u<<15)
#define	PSM_FRCE_OFF_SRAM6		(0x1u<<16)
#define	PSM_FRCE_OFF_SRAM7		(0x1u<<17)
#define	PSM_FRCE_OFF_SRAM8		(0x1u<<18)
#define	PSM_FRCE_OFF_SRAM9		(0x1u<<19)
#define	PSM_FRCE_OFF_XIP		(0x1u<<20)
#define	PSM_FRCE_OFF_SIO		(0x1u<<21)
#define	PSM_FRCE_OFF_ACCESSCTRL	(0x1u<<22)
#define	PSM_FRCE_OFF_PROC0		(0x1u<<23)
#define	PSM_FRCE_OFF_PROC1		(0x1u<<24)

// WDSEL Configuration

#define	PSM_WDSEL_PROC_COLD		(0x1u<<0)
#define	PSM_WDSEL_OTP			(0x1u<<1)
#define	PSM_WDSEL_ROSC			(0x1u<<2)
#define	PSM_WDSEL_XOSC			(0x1u<<3)
#define	PSM_WDSEL_RESETS		(0x1u<<4)
#define	PSM_WDSEL_CLOCKS		(0x1u<<5)
#define	PSM_WDSEL_PSM_READY		(0x1u<<6)
#define	PSM_WDSEL_BUSFABRIC		(0x1u<<7)
#define	PSM_WDSEL_ROM			(0x1u<<8)
#define	PSM_WDSEL_BOOTRAM		(0x1u<<9)
#define	PSM_WDSEL_SRAM0			(0x1u<<10)
#define	PSM_WDSEL_SRAM1			(0x1u<<11)
#define	PSM_WDSEL_SRAM2			(0x1u<<12)
#define	PSM_WDSEL_SRAM3			(0x1u<<13)
#define	PSM_WDSEL_SRAM4			(0x1u<<14)
#define	PSM_WDSEL_SRAM5			(0x1u<<15)
#define	PSM_WDSEL_SRAM6			(0x1u<<16)
#define	PSM_WDSEL_SRAM7			(0x1u<<17)
#define	PSM_WDSEL_SRAM8			(0x1u<<18)
#define	PSM_WDSEL_SRAM9			(0x1u<<19)
#define	PSM_WDSEL_XIP			(0x1u<<20)
#define	PSM_WDSEL_SIO			(0x1u<<21)
#define	PSM_WDSEL_ACCESSCTRL	(0x1u<<22)
#define	PSM_WDSEL_PROC0			(0x1u<<23)
#define	PSM_WDSEL_PROC1			(0x1u<<24)

// DONE Configuration

#define	PSM_DONE_PROC_COLD		(0x1u<<0)
#define	PSM_DONE_OTP			(0x1u<<1)
#define	PSM_DONE_ROSC			(0x1u<<2)
#define	PSM_DONE_XOSC			(0x1u<<3)
#define	PSM_DONE_RESETS			(0x1u<<4)
#define	PSM_DONE_CLOCKS			(0x1u<<5)
#define	PSM_DONE_PSM_READY		(0x1u<<6)
#define	PSM_DONE_BUSFABRIC		(0x1u<<7)
#define	PSM_DONE_ROM			(0x1u<<8)
#define	PSM_DONE_BOOTRAM		(0x1u<<9)
#define	PSM_DONE_SRAM0			(0x1u<<10)
#define	PSM_DONE_SRAM1			(0x1u<<11)
#define	PSM_DONE_SRAM2			(0x1u<<12)
#define	PSM_DONE_SRAM3			(0x1u<<13)
#define	PSM_DONE_SRAM4			(0x1u<<14)
#define	PSM_DONE_SRAM5			(0x1u<<15)
#define	PSM_DONE_SRAM6			(0x1u<<16)
#define	PSM_DONE_SRAM7			(0x1u<<17)
#define	PSM_DONE_SRAM8			(0x1u<<18)
#define	PSM_DONE_SRAM9			(0x1u<<19)
#define	PSM_DONE_XIP			(0x1u<<20)
#define	PSM_DONE_SIO			(0x1u<<21)
#define	PSM_DONE_ACCESSCTRL		(0x1u<<22)
#define	PSM_DONE_PROC0			(0x1u<<23)
#define	PSM_DONE_PROC1			(0x1u<<24)
