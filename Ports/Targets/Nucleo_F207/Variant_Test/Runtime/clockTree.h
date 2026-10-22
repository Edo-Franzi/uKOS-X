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

#define KCRYSTAL			16000000u									// Quartz crystal resonator
#define KFREQUENCY_PLLP		120000000u									// PLL P bus frequency of 120-MHz
#define KFREQUENCY_PLLQ		48000000u									// PLL Q bus frequency of 48-MHz
#define KFREQUENCY_AHB		120000000u									// AHB bus frequency of 120-MHz
#define KFREQUENCY_APB2		60000000u									// APB2 periph bus frequency of 60-MHz
#define KFREQUENCY_APB1		30000000u									// APB1 periph bus frequency of 30-MHz
#define KFREQUENCY_1GHz		1000000000u									// Frequency of 1-GHz
#define KFREQUENCY_1MHz		1000000u									// Frequency of 1-MHz
#define KFREQUENCY_1KHz		1000u										// Frequency of 1-KHz
#define KFREQUENCY_CORE		KFREQUENCY_AHB								// CORE frequency

// PLL settings
// ------------

#define	KPLL_CK_IN			16000000u									// f(ck in), PLLSRC = HSI (16-MHz)
#define	KPLL_FVCO_MIN		192000000u									// FVCO min, 192-MHz
#define	KPLL_FVCO_MAX		432000000u									// FVCO max, 432-MHz
#define	KPLL_FVCO(m, n)		(((uint64_t)KPLL_CK_IN * (n)) / (m))		// f(vco) = f(ck in) * (N / M)

// Compile-time checks of the main PLL configuration (RM0033)

#define	KPLL_STATIC_CHECKS(m, n, p, q)																									\
	static_assert(((m) >= 2u) && ((m) <= 63u), "PLL: PLLM shall be in 2..63");															\
	static_assert(((n) >= 2u) && ((n) <= 432u), "PLL: PLLN shall be in 2..432");														\
	static_assert(((p) == 2u) || ((p) == 4u) || ((p) == 6u) || ((p) == 8u), "PLL: PLLP shall be 2, 4, 6 or 8");							\
	static_assert(((q) >= 2u) && ((q) <= 15u), "PLL: PLLQ shall be in 2..15");															\
	static_assert((KPLL_FVCO(m, n) >= KPLL_FVCO_MIN) && (KPLL_FVCO(m, n) <= KPLL_FVCO_MAX), "PLL: FVCO out of range");					\
	static_assert((KPLL_FVCO(m, n) / (p)) == KFREQUENCY_PLLP, "PLL: configuration does not match KFREQUENCY_PLLP");						\
	static_assert((KPLL_FVCO(m, n) / (q)) == KFREQUENCY_PLLQ, "PLL: configuration does not match KFREQUENCY_PLLQ")

// Main PLL

#define	KCFG_PLLDIVM		4u											// M = 4, f(ref) = 4-MHz
#define	KCFG_PLLDIVN		60u											// N = 60, f(vco) = 240-MHz
#define	KCFG_PLLDIVP		2u											// VCO / 2, 120-MHz
#define	KCFG_PLLDIVQ		5u											// VCO / 5, 48-MHz
