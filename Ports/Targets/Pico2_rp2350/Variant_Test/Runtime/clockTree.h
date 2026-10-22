/*
; clockTree.
; ==========
;
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
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

#define KCRYSTAL			12000000u									// Quartz crystal resonator
#define KFREQUENCY_PLLSYS	150000000u									// PLL SYS frequency of 150-MHz
#define KFREQUENCY_PLLUSB	48000000u									// PLL USB frequency of 48-MHz
#define KFREQUENCY_AHB		150000000u									// AHB bus frequency of 150-MHz
#define KFREQUENCY_TIM		1000000u									// Timers frequency of 1-MHz
#define KFREQUENCY_1GHz		1000000000u									// Frequency of 1-GHz
#define KFREQUENCY_1MHz		1000000u									// Frequency of 1-MHz
#define KFREQUENCY_1KHz		1000u										// Frequency of 1-KHz
#define KFREQUENCY_CORE		KFREQUENCY_AHB								// CORE frequency

// PLL settings
// ------------

#define	KPLL_CK_IN			KCRYSTAL									// f(ck in), XOSC (12-MHz)
#define	KPLL_FREF_MIN		5000000u									// f(ref) min, 5-MHz
#define	KPLL_FVCO_MIN		750000000u									// FVCO min, 750-MHz
#define	KPLL_FVCO_MAX		1600000000u									// FVCO max, 1600-MHz
#define	KPLL_FREF(r)		(KPLL_CK_IN / (r))							// f(ref) = f(ck in) / REFDIV
#define	KPLL_FVCO(r, fb)	(((uint64_t)KPLL_CK_IN * (fb)) / (r))		// f(vco) = f(ck in) * (FBDIV / REFDIV)

// Compile-time checks of a PLL configuration (RP2350 datasheet)

#define	KPLL_STATIC_CHECKS(x, r, fb, pd1, pd2)																							\
	static_assert(((r) >= 1u) && ((r) <= 63u), "PLL_" #x ": REFDIV shall be in 1..63");													\
	static_assert(((fb) >= 16u) && ((fb) <= 320u), "PLL_" #x ": FBDIV shall be in 16..320");											\
	static_assert(((pd1) >= 1u) && ((pd1) <= 7u), "PLL_" #x ": POSTDIV1 shall be in 1..7");												\
	static_assert(((pd2) >= 1u) && ((pd2) <= 7u), "PLL_" #x ": POSTDIV2 shall be in 1..7");												\
	static_assert(KPLL_FREF(r) >= KPLL_FREF_MIN, "PLL_" #x ": f(ref) out of range");													\
	static_assert((KPLL_FVCO(r, fb) / ((pd1) * (pd2))) == KFREQUENCY_PLL##x, "PLL_" #x ": configuration does not match KFREQUENCY_PLL" #x)

#define	KPLL_STATIC_CHECK_FVCO(x, r, fb)																								\
	static_assert((KPLL_FVCO(r, fb) >= KPLL_FVCO_MIN) && (KPLL_FVCO(r, fb) <= KPLL_FVCO_MAX), "PLL_" #x ": FVCO out of range")

// PLL SYS

#define	KCFG_PLLSYS_REFDIV	1u											// REFDIV = 1, f(ref) = 12-MHz
#define	KCFG_PLLSYS_FBDIV	125u										// FBDIV = 125, f(vco) = 1500-MHz
#define	KCFG_PLLSYS_POSTDIV1	5u										// VCO / 5
#define	KCFG_PLLSYS_POSTDIV2	2u										// VCO / (5 * 2), 150-MHz

// PLL USB

#define	KCFG_PLLUSB_REFDIV	1u											// REFDIV = 1, f(ref) = 12-MHz
#define	KCFG_PLLUSB_FBDIV	40u											// FBDIV = 40, f(vco) = 480-MHz
#define	KCFG_PLLUSB_POSTDIV1	5u										// VCO / 5
#define	KCFG_PLLUSB_POSTDIV2	2u										// VCO / (5 * 2), 48-MHz
