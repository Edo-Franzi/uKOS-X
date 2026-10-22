/*
; clockTree.
; ==========
;
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
;
;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Clock tree definitions.
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

// Main system clocks
// ------------------

#define KFREQUENCY_PLL		108000000u									// PLL frequency of 108-MHz
#define KFREQUENCY_AHB		108000000u									// AHB bus frequency of 108-MHz
#define KFREQUENCY_APB1		54000000u									// APB1 bus frequency of 54-MHz
#define KFREQUENCY_APB2		54000000u									// APB2 bus frequency of 54-MHz
#define KFREQUENCY_TIM		108000000u									// Timer clock 108-MHz (APB2 x 2)
#define KFREQUENCY_UART		54000000u									// Uart clock 54-MHz
#define KFREQUENCY_1GHz		1000000000u									// Frequency of 1-GHz
#define KFREQUENCY_1MHz		1000000u									// Frequency of 1-MHz
#define KFREQUENCY_1KHz		1000u										// Frequency of 1-KHz
#define KFREQUENCY_CORE		KFREQUENCY_AHB								// CORE frequency

// PLL settings
// ------------

#define	KPLL_CK_IN			4000000u									// f(ck in), PLLSEL = IRC8M / 2 (4-MHz)
#define	KPLL_FOUT_MAX		108000000u									// CK_PLL max, 108-MHz
#define	KPLL_PLLMF(mf)		(((mf) >= 17u) ? ((mf) - 1u) : (((mf) == 16u) ? 14u : ((mf) - 2u)))	// PLLMF[4:0] encoding of x mf

// Compile-time checks of the PLL configuration (GD32VF103 user manual)
// PLLMF = 01101 is x 6.5, so x 15 is not available

#define	KPLL_STATIC_CHECKS(mf)																											\
	static_assert(((mf) >= 2u) && ((mf) <= 32u) && ((mf) != 15u), "PLL: PLLMF shall be in 2..14 or 16..32");							\
	static_assert((KPLL_CK_IN * (mf)) <= KPLL_FOUT_MAX, "PLL: CK_PLL out of range");													\
	static_assert((KPLL_CK_IN * (mf)) == KFREQUENCY_PLL, "PLL: configuration does not match KFREQUENCY_PLL")

// Main PLL

#define	KCFG_PLLMF			27u											// CK_PLL = 4-MHz x 27 = 108-MHz
#define	KCFG_USBFSPSC		3u											// CK_USBFS = CK_PLL / 2 (0: /1.5, 1: /1, 2: /2.5, 3: /2)
