/*
; RP2350_hstx_fifo.
; =================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_hstx_fifo equates.
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

// HSTX_FIFO address definitions
// -----------------------------

typedef struct {
	volatile	uint32_t	STAT;
	volatile	uint32_t	FIFO;
} HSTX_FIFO_TypeDef;

#ifdef __cplusplus
#define	HSTX_FIFO_NS	reinterpret_cast<HSTX_FIFO_TypeDef *>(0x50600000u)
#define	HSTX_FIFO_S		reinterpret_cast<HSTX_FIFO_TypeDef *>(0x50600000u)
#else
#define	HSTX_FIFO_NS	((HSTX_FIFO_TypeDef *)0x50600000u)
#define	HSTX_FIFO_S		((HSTX_FIFO_TypeDef *)0x50600000u)
#endif

// STAT Configuration

#define	HSTX_FIFO_STAT_LEVEL	(0xFFu<<0)
#define	HSTX_FIFO_STAT_LEVEL_0	(0x1u<<0)
#define	HSTX_FIFO_STAT_FULL		(0x1u<<8)
#define	HSTX_FIFO_STAT_EMPTY	(0x1u<<9)
#define	HSTX_FIFO_STAT_WOF		(0x1u<<10)

// FIFO Configuration

#define	HSTX_FIFO_FIFO_FIFO		(0xFFFFFFFFu<<0)
#define	HSTX_FIFO_FIFO_FIFO_0	(0x1u<<0)
