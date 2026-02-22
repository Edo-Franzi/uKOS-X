/*
; RP2350_pll_sys.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_pll_sys equates.
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

// PLL_SYS address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	CS;
	volatile	uint32_t	PWR;
	volatile	uint32_t	FBDIV_INT;
	volatile	uint32_t	PRIM;
	volatile	uint32_t	INTR;
	volatile	uint32_t	INTE;
	volatile	uint32_t	INTF;
	volatile	uint32_t	INTS;
} PLL_SYS_TypeDef;

#ifdef __cplusplus
#define	PLL_SYS_NS	reinterpret_cast<PLL_SYS_TypeDef *>(0x40050000u)
#define	PLL_SYS_S	reinterpret_cast<PLL_SYS_TypeDef *>(0x40050000u)
#define	PLL_USB_NS	reinterpret_cast<PLL_SYS_TypeDef *>(0x40058000u)
#define	PLL_USB_S	reinterpret_cast<PLL_SYS_TypeDef *>(0x40058000u)
#else
#define	PLL_SYS_NS	((PLL_SYS_TypeDef *)0x40050000u)
#define	PLL_SYS_S	((PLL_SYS_TypeDef *)0x40050000u)
#define	PLL_USB_NS	((PLL_SYS_TypeDef *)0x40058000u)
#define	PLL_USB_S	((PLL_SYS_TypeDef *)0x40058000u)
#endif

// CS Configuration

#define	PLL_SYS_CS_REFDIV				(0x3Fu<<0)
#define	PLL_SYS_CS_REFDIV_0				(0x1u<<0)
#define	PLL_SYS_CS_BYPASS				(0x1u<<8)
#define	PLL_SYS_CS_LOCK_N				(0x1u<<30)
#define	PLL_SYS_CS_LOCK					(0x1u<<31)

// PWR Configuration

#define	PLL_SYS_PWR_PD					(0x1u<<0)
#define	PLL_SYS_PWR_DSMPD				(0x1u<<2)
#define	PLL_SYS_PWR_POSTDIVPD			(0x1u<<3)
#define	PLL_SYS_PWR_VCOPD				(0x1u<<5)

// FBDIV_INT Configuration

#define	PLL_SYS_FBDIV_INT_FBDIV_INT		(0xFFFu<<0)
#define	PLL_SYS_FBDIV_INT_FBDIV_INT_0	(0x1u<<0)

// PRIM Configuration

#define	PLL_SYS_PRIM_POSTDIV2			(0x7u<<12)
#define	PLL_SYS_PRIM_POSTDIV2_0			(0x1u<<12)
#define	PLL_SYS_PRIM_POSTDIV1			(0x7u<<16)
#define	PLL_SYS_PRIM_POSTDIV1_0			(0x1u<<16)

// INTR Configuration

#define	PLL_SYS_INTR_LOCK_N_STICKY		(0x1u<<0)

// INTE Configuration

#define	PLL_SYS_INTE_LOCK_N_STICKY		(0x1u<<0)

// INTF Configuration

#define	PLL_SYS_INTF_LOCK_N_STICKY		(0x1u<<0)

// INTS Configuration

#define	PLL_SYS_INTS_LOCK_N_STICKY		(0x1u<<0)
