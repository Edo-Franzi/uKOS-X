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

#define KCRYSTAL			26000000u									// Quartz crystal resonator
#define KFREQUENCY_PLL0		806000000u									// PLL 0 frequency of 806-MHz
#define KFREQUENCY_PLL1		159714285u									// PLL 1 frequency of 159.7-MHz
#define KFREQUENCY_PLL2		45066666u									// PLL 2 frequency of 45.07-MHz
#define KFREQUENCY_AHB		403000000u									// AHB bus frequency of 403-MHz
#define KFREQUENCY_APB0		201500000u									// APB1 bus frequency of 201-MHz
#define KFREQUENCY_APB1		201500000u									// APB1 bus frequency of 201-MHz
#define KFREQUENCY_APB2		201500000u									// APB2 bus frequency of 201-MHz
#define KFREQUENCY_TIM		403000000u									// Timer clock 403-MHz
#define KFREQUENCY_UART		201500000u									// Uart clock 201-MHz
#define KFREQUENCY_SPI0		403000000u									// Spi0 clock 403-MHz
#define KFREQUENCY_SPI1		403000000u									// Spi1 clock 403-MHz
#define KFREQUENCY_SPI2		403000000u									// Spi2 clock 403-MHz
#define KFREQUENCY_SPI3		100750000u									// Spi3 clock 100-MHz
#define KFREQUENCY_1GHz		1000000000u									// Frequency of 1-GHz
#define KFREQUENCY_1MHz		1000000u									// Frequency of 1-MHz
#define KFREQUENCY_1KHz		1000u										// Frequency of 1-KHz
#define KFREQUENCY_CORE		KFREQUENCY_AHB								// CORE frequency

// PLL settings
// ------------

#define	KPLL_CK_IN			KCRYSTAL									// f(ck in), IN0 (26-MHz)
#define	KPLL_FREF_MIN		13671900u									// f(ref) min, ~13.67-MHz
#define	KPLL_FVCO_MIN		350000000u									// FVCO min, 350-MHz
#define	KPLL_FVCO_MAX		1750000000u									// FVCO max, 1750-MHz
#define	KPLL_FREF(r)		(KPLL_CK_IN / (r))							// f(ref) = f(ck in) / R
#define	KPLL_FVCO(r, f)		(((uint64_t)KPLL_CK_IN * (f)) / (r))		// f(vco) = f(ck in) * (F / R)

// Compile-time checks of a PLL configuration (limits from the Kendryte SDK, sysctl.c)
// Register fields hold the value - 1 (clkr = R - 1, clkf = F - 1, clkod = OD - 1, bwadj = F - 1)

#define	KPLL_STATIC_CHECKS(x, r, f, od)																									\
	static_assert(((r) >= 1u) && ((r) <= 16u), "PLL" #x ": R shall be in 1..16");														\
	static_assert(((f) >= 1u) && ((f) <= 64u), "PLL" #x ": F shall be in 1..64");														\
	static_assert(((od) >= 1u) && ((od) <= 16u), "PLL" #x ": OD shall be in 1..16");													\
	static_assert(KPLL_FREF(r) >= KPLL_FREF_MIN, "PLL" #x ": f(ref) out of range");														\
	static_assert((KPLL_FVCO(r, f) >= KPLL_FVCO_MIN) && (KPLL_FVCO(r, f) <= KPLL_FVCO_MAX), "PLL" #x ": FVCO out of range");			\
	static_assert((KPLL_FVCO(r, f) / (od)) == KFREQUENCY_PLL##x, "PLL" #x ": configuration does not match KFREQUENCY_PLL" #x)

// PLL 0

#define	KCFG_PLL0DIVR		1u											// R = 1, f(ref) = 26-MHz
#define	KCFG_PLL0DIVF		62u											// F = 62, f(vco) = 1612-MHz
#define	KCFG_PLL0DIVOD		2u											// VCO / 2, 806-MHz

// PLL 1

#define	KCFG_PLL1DIVR		1u											// R = 1, f(ref) = 26-MHz
#define	KCFG_PLL1DIVF		43u											// F = 43, f(vco) = 1118-MHz
#define	KCFG_PLL1DIVOD		7u											// VCO / 7, 159.7-MHz

// PLL 2

#define	KCFG_PLL2DIVR		1u											// R = 1, f(ref) = 26-MHz
#define	KCFG_PLL2DIVF		26u											// F = 26, f(vco) = 676-MHz
#define	KCFG_PLL2DIVOD		15u											// VCO / 15, 45.07-MHz
