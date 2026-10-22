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
#define KFREQUENCY_PLL1P	160000000u									// PLL 1 P bus frequency of 160-MHz
#define KFREQUENCY_PLL1Q	160000000u									// PLL 1 Q bus frequency of 160-MHz
#define KFREQUENCY_PLL1R	160000000u									// PLL 1 R bus frequency of 160-MHz
#define KFREQUENCY_PLL3P	20833333u									// PLL 3 P bus frequency of 20.83-MHz
#define KFREQUENCY_PLL3Q	250000000u									// PLL 3 Q bus frequency of 250-MHz
#define KFREQUENCY_PLL3R	20833333u									// PLL 3 R bus frequency of 20.83-MHz
#define KFREQUENCY_AHB		160000000u									// AHB bus frequency of 160-MHz
#define KFREQUENCY_APB3		80000000u									// APB3 periph bus frequency of 80-MHz
#define KFREQUENCY_APB2		80000000u									// APB2 periph bus frequency of 80-MHz
#define KFREQUENCY_APB1		80000000u									// APB1 periph bus frequency of 80-MHz
#define KFREQUENCY_1GHz		1000000000u									// Frequency of 1-GHz
#define KFREQUENCY_1MHz		1000000u									// Frequency of 1-MHz
#define KFREQUENCY_1KHz		1000u										// Frequency of 1-KHz
#define KFREQUENCY_CORE		KFREQUENCY_AHB								// CORE frequency

// PLL settings
// ------------

#define	KPLL_CK_IN			16000000u									// f(ck in), PLLxSRC = HSI16 (16-MHz)
#define	KPLL_FVCO_MIN		128000000u									// FVCO min, 128-MHz
#define	KPLL_FVCO_MAX		544000000u									// FVCO max, 544-MHz
#define	KPLL_FREF(m)		(KPLL_CK_IN / (m))							// f(ref) = f(ck in) / M
#define	KPLL_FREF_MIN(rge)	(((rge) == 0u) ? 4000000u : 8000000u)		// f(ref) min for PLLxRGE (0: 4-MHz, 3: 8-MHz)
#define	KPLL_FREF_MAX(rge)	(((rge) == 0u) ? 8000000u : 16000000u)		// f(ref) max for PLLxRGE (0: 8-MHz, 3: 16-MHz)
#define	KPLL_FVCO(m, n)		(((uint64_t)KPLL_CK_IN * (n)) / (m))		// f(vco) = f(ck in) * (N / M)

// Compile-time checks of a PLL configuration (RM0456, integer mode)

#define	KPLL_STATIC_CHECKS(x, m, rge, n, p, q, r)																						\
	static_assert(((m) >= 1u) && ((m) <= 16u), "PLL" #x ": DIVM shall be in 1..16");													\
	static_assert(((rge) == 0u) || ((rge) == 3u), "PLL" #x ": RGE shall be 0 or 3");													\
	static_assert(((n) >= 4u) && ((n) <= 512u), "PLL" #x ": DIVN shall be in 4..512");													\
	static_assert(((p) >= 1u) && ((p) <= 128u), "PLL" #x ": DIVP shall be in 1..128");													\
	static_assert(((q) >= 1u) && ((q) <= 128u), "PLL" #x ": DIVQ shall be in 1..128");													\
	static_assert(((r) >= 1u) && ((r) <= 128u), "PLL" #x ": DIVR shall be in 1..128");													\
	static_assert((KPLL_FREF(m) >= KPLL_FREF_MIN(rge)) && (KPLL_FREF(m) <= KPLL_FREF_MAX(rge)), "PLL" #x ": f(ref) out of the PLLxRGE range");	\
	static_assert((KPLL_FVCO(m, n) >= KPLL_FVCO_MIN) && (KPLL_FVCO(m, n) <= KPLL_FVCO_MAX), "PLL" #x ": FVCO out of range");			\
	static_assert((KPLL_FVCO(m, n) / (p)) == KFREQUENCY_PLL##x##P, "PLL" #x ": configuration does not match KFREQUENCY_PLL" #x "P");	\
	static_assert((KPLL_FVCO(m, n) / (q)) == KFREQUENCY_PLL##x##Q, "PLL" #x ": configuration does not match KFREQUENCY_PLL" #x "Q");	\
	static_assert((KPLL_FVCO(m, n) / (r)) == KFREQUENCY_PLL##x##R, "PLL" #x ": configuration does not match KFREQUENCY_PLL" #x "R")

// PLL 1

#define	KCFG_PLL1DIVM		1u											// M = 1, f(ref) = 16-MHz
#define	KCFG_PLL1RGE		3u											// f(ref) in 8-MHz..16-MHz
#define	KCFG_PLL1DIVN		20u											// N = 20, f(vco) = 320-MHz
#define	KCFG_PLL1DIVP		2u											// VCO / 2, 160-MHz
#define	KCFG_PLL1DIVQ		2u											// VCO / 2, 160-MHz
#define	KCFG_PLL1DIVR		2u											// VCO / 2, 160-MHz

// PLL 3

#define	KCFG_PLL3DIVM		4u											// M = 4, f(ref) = 4-MHz
#define	KCFG_PLL3RGE		0u											// f(ref) in 4-MHz..8-MHz
#define	KCFG_PLL3DIVN		125u										// N = 125, f(vco) = 500-MHz
#define	KCFG_PLL3DIVP		24u											// VCO / 24, 20.83-MHz
#define	KCFG_PLL3DIVQ		2u											// VCO / 2, 250-MHz
#define	KCFG_PLL3DIVR		24u											// VCO / 24, 20.83-MHz
