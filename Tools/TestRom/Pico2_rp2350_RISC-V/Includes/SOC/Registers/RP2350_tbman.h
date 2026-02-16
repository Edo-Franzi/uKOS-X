/*
; RP2350_tbman.
; =============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_tbman equates.
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

// TBMAN address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	PLATFORM;
} TBMAN_TypeDef;

#ifdef __cplusplus
#define	TBMAN_NS	reinterpret_cast<TBMAN_TypeDef *>(0x40160000u)
#define	TBMAN_S		reinterpret_cast<TBMAN_TypeDef *>(0x40160000u)
#else
#define	TBMAN_NS	((TBMAN_TypeDef *)0x40160000u)
#define	TBMAN_S		((TBMAN_TypeDef *)0x40160000u)
#endif

// PLATFORM Configuration

#define	TBMAN_PLATFORM_ASIC		(0x1u<<0)
#define	TBMAN_PLATFORM_FPGA		(0x1u<<1)
#define	TBMAN_PLATFORM_HDLSIM	(0x1u<<2)
