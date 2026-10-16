/*
; stm32L4R5_octospim.
; ===================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_octospim equates.
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

// OCTOSPIM address definitions
// ----------------------------

typedef struct {
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	P1CR;
	volatile	uint32_t	P2CR;
} OCTOSPIM_TypeDef;

#if (defined(__cplusplus))
#define	OCTOSPIM	reinterpret_cast<OCTOSPIM_TypeDef *>(0x50061C00u)

#else
#define	OCTOSPIM	((OCTOSPIM_TypeDef *)0x50061C00u)
#endif

// P1CR Configuration

#define	OCTOSPIM_P1CR_IOHSRC	(0x3u<<25)
#define	OCTOSPIM_P1CR_IOHSRC_0	(0x1u<<25)
#define	OCTOSPIM_P1CR_IOHEN		(0x1u<<24)
#define	OCTOSPIM_P1CR_IOLSRC	(0x3u<<17)
#define	OCTOSPIM_P1CR_IOLSRC_0	(0x1u<<17)
#define	OCTOSPIM_P1CR_IOLEN		(0x1u<<16)
#define	OCTOSPIM_P1CR_NCSSRC	(0x1u<<9)
#define	OCTOSPIM_P1CR_NCSEN		(0x1u<<8)
#define	OCTOSPIM_P1CR_DQSSRC	(0x1u<<5)
#define	OCTOSPIM_P1CR_DQSEN		(0x1u<<4)
#define	OCTOSPIM_P1CR_CLKSRC	(0x1u<<1)
#define	OCTOSPIM_P1CR_CLKEN		(0x1u<<0)

// P2CR Configuration

#define	OCTOSPIM_P2CR_IOHSRC	(0x3u<<25)
#define	OCTOSPIM_P2CR_IOHSRC_0	(0x1u<<25)
#define	OCTOSPIM_P2CR_IOHEN		(0x1u<<24)
#define	OCTOSPIM_P2CR_IOLSRC	(0x3u<<17)
#define	OCTOSPIM_P2CR_IOLSRC_0	(0x1u<<17)
#define	OCTOSPIM_P2CR_IOLEN		(0x1u<<16)
#define	OCTOSPIM_P2CR_NCSSRC	(0x1u<<9)
#define	OCTOSPIM_P2CR_NCSEN		(0x1u<<8)
#define	OCTOSPIM_P2CR_DQSSRC	(0x1u<<5)
#define	OCTOSPIM_P2CR_DQSEN		(0x1u<<4)
#define	OCTOSPIM_P2CR_CLKSRC	(0x1u<<1)
#define	OCTOSPIM_P2CR_CLKEN		(0x1u<<0)
