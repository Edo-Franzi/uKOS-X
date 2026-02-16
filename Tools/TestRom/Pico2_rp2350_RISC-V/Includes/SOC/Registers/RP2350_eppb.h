/*
; RP2350_eppb.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_eppb equates.
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

// EPPB address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	NMI_MASK0;
	volatile	uint32_t	NMI_MASK1;
	volatile	uint32_t	SLEEPCTRL;
} EPPB_TypeDef;

#ifdef __cplusplus
#define	EPPB_NS	reinterpret_cast<EPPB_TypeDef *>(0xE0080000u)
#define	EPPB_S	reinterpret_cast<EPPB_TypeDef *>(0xE0080000u)
#else
#define	EPPB_NS	((EPPB_TypeDef *)0xE0080000u)
#define	EPPB_S	((EPPB_TypeDef *)0xE0080000u)
#endif

// NMI_MASK0 Configuration

#define	EPPB_NMI_MASK0_NMI_MASK0	(0xFFFFFFFFu<<0)
#define	EPPB_NMI_MASK0_NMI_MASK0_0	(0x1u<<0)

// NMI_MASK1 Configuration

#define	EPPB_NMI_MASK1_NMI_MASK1	(0xFFFFFu<<0)
#define	EPPB_NMI_MASK1_NMI_MASK1_0	(0x1u<<0)

// SLEEPCTRL Configuration

#define	EPPB_SLEEPCTRL_LIGHT_SLEEP	(0x1u<<0)
#define	EPPB_SLEEPCTRL_WICENREQ		(0x1u<<1)
#define	EPPB_SLEEPCTRL_WICENACK		(0x1u<<2)
