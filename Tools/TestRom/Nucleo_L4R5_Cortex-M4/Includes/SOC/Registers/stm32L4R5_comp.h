/*
; stm32L4R5_comp.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_comp equates.
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

// COMP address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	COMP1_CSR;
	volatile	uint32_t	COMP2_CSR;
} COMP_TypeDef;

#if (defined(__cplusplus))
#define	COMP	reinterpret_cast<COMP_TypeDef *>(0x40010200u)

#else
#define	COMP	((COMP_TypeDef *)0x40010200u)
#endif

// COMP1_CSR Configuration

#define	COMP_COMP1_CSR_COMP1_LOCK		(0x1u<<31)
#define	COMP_COMP1_CSR_COMP1_VALUE		(0x1u<<30)
#define	COMP_COMP1_CSR_COMP1_SCALEN		(0x1u<<23)
#define	COMP_COMP1_CSR_COMP1_BRGEN		(0x1u<<22)
#define	COMP_COMP1_CSR_COMP1_BLANKING	(0x7u<<18)
#define	COMP_COMP1_CSR_COMP1_BLANKING_0	(0x1u<<18)
#define	COMP_COMP1_CSR_COMP1_HYST		(0x3u<<16)
#define	COMP_COMP1_CSR_COMP1_HYST_0		(0x1u<<16)
#define	COMP_COMP1_CSR_COMP1_POLARITY	(0x1u<<15)
#define	COMP_COMP1_CSR_COMP1_INPSEL		(0x1u<<7)
#define	COMP_COMP1_CSR_COMP1_INMSEL		(0x7u<<4)
#define	COMP_COMP1_CSR_COMP1_INMSEL_0	(0x1u<<4)
#define	COMP_COMP1_CSR_COMP1_PWRMODE	(0x3u<<2)
#define	COMP_COMP1_CSR_COMP1_PWRMODE_0	(0x1u<<2)
#define	COMP_COMP1_CSR_COMP1_EN			(0x1u<<0)

// COMP2_CSR Configuration

#define	COMP_COMP2_CSR_COMP2_LOCK		(0x1u<<31)
#define	COMP_COMP2_CSR_COMP2_VALUE		(0x1u<<30)
#define	COMP_COMP2_CSR_COMP2_SCALEN		(0x1u<<23)
#define	COMP_COMP2_CSR_COMP2_BRGEN		(0x1u<<22)
#define	COMP_COMP2_CSR_COMP2_BLANKING	(0x7u<<18)
#define	COMP_COMP2_CSR_COMP2_BLANKING_0	(0x1u<<18)
#define	COMP_COMP2_CSR_COMP2_HYST		(0x3u<<16)
#define	COMP_COMP2_CSR_COMP2_HYST_0		(0x1u<<16)
#define	COMP_COMP2_CSR_COMP2_POLARITY	(0x1u<<15)
#define	COMP_COMP2_CSR_COMP2_WINMODE	(0x1u<<9)
#define	COMP_COMP2_CSR_COMP2_INPSEL		(0x1u<<7)
#define	COMP_COMP2_CSR_COMP2_INMSEL		(0x7u<<4)
#define	COMP_COMP2_CSR_COMP2_INMSEL_0	(0x1u<<4)
#define	COMP_COMP2_CSR_COMP2_PWRMODE	(0x3u<<2)
#define	COMP_COMP2_CSR_COMP2_PWRMODE_0	(0x1u<<2)
#define	COMP_COMP2_CSR_COMP2_EN			(0x1u<<0)
