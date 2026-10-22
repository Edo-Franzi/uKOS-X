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

// Constraints:
//
// Fcpu:			800-MHz		sysa_ck (ic1)
// Fnpu:			800-MHz		sysc_ck (ic6)
// Faxi:			400-MHz		sysb_ck (ic2)
// FaxiRAMNPU:		400-MHz		sysd_ck (1c11)
//
// !!! Some silicon limitations. PBx HAS to be = AHB
//
// Faxi, 400-MHz, FBusMax
// - Timer group 1, 100-MHz
// - Timer group 2, 100-MHz
// - sys_bus2_ck (pclkx), 100-MHz, Faxi / 4
//		- APB1,2,4,5, 100-MHz, sys_bus2_ck / 1
//
// Simple peripherals
// Fadc12, 		pclk5 100-MHz
// Fi2cx, 		pclk5 100-MHz (x=1, 2, 3 ,4)
// Fi3cx, 		pclk5 100-MHz (x=1, 2)
// Fsaix, 		pclk2 100-MHz (x=1, 2)
// Fspix, 		pclk4 100-MHz (x=1, 2, 3, 4, 5, 6)
// Flptimx,		pclk4 100-MHz (x=1, 2, 3, 4, 5)
// Fusartx,		pclk1 100-MHz (x=1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
// Flpusartx,	pclk4 100-MHz (x=1, 2)
// Flpuartx,	pclk4 100-MHz (x=1)

#define KCRYSTAL			64000000u									// Quartz crystal resonator
#define KFREQUENCY_PLL1		800000000u									// PLL 1 CPU frequency of 800-MHz
#define KFREQUENCY_PLL2		800000000u									// PLL 2 NPU frequency of 800-MHz
#define KFREQUENCY_PLL3		400000000u									// PLL 3 AXI frequency of 400-MHz
#define KFREQUENCY_PLL4		400000000u									// PLL 4 PER frequency of 400-MHz

#define KTIMPRE				2u											// Div 4 (2^2)
#define KHPRE				2u											// Div 4 (2^2)
#define KPPRE1				0u											// Div 1 (2^0)
#define KPPRE2				0u											// Div 1 (2^0)
#define KPPRE4				0u											// Div 1 (2^0)
#define KPPRE5				0u											// Div 1 (2^0)

#define KFREQUENCY_CPU		KFREQUENCY_PLL1								// CPU bus frequency of 800-MHz
#define KFREQUENCY_NPU		KFREQUENCY_PLL2								// NPU bus frequency of 800-MHz
#define KFREQUENCY_AXI		KFREQUENCY_PLL3								// AXI bus frequency of 400-MHz
#define KFREQUENCY_TIM		(KFREQUENCY_AXI / (1u<<KTIMPRE))			// TIM bus frequency of 100-MHz
#define KFREQUENCY_HCL		(KFREQUENCY_AXI / (1u<<KHPRE))				// HCL bus frequency of 100-MHz
#define KFREQUENCY_APB1		(KFREQUENCY_HCL / (1u<<KPPRE1))				// APB1 bus frequency of 100-MHz
#define KFREQUENCY_APB2		(KFREQUENCY_HCL / (1u<<KPPRE2))				// APB2 bus frequency of 100-MHz
#define KFREQUENCY_APB4		(KFREQUENCY_HCL / (1u<<KPPRE4))				// APB4 bus frequency of 100-MHz
#define KFREQUENCY_APB5		(KFREQUENCY_HCL / (1u<<KPPRE5))				// APB5 bus frequency of 100-MHz
#define KFREQUENCY_1GHz		1000000000u									// Frequency of 1-GHz
#define KFREQUENCY_1MHz		1000000u									// Frequency of 1-MHz
#define KFREQUENCY_1KHz		1000u										// Frequency of 1-KHz
#define KFREQUENCY_CORE		KFREQUENCY_CPU								// CORE frequency

// PLL settings
// ------------

#define	KPLL_FVCO_MIN		800000000u									// FVCO min, 800-MHz
#define	KPLL_FVCO_MAX		3200000000u									// FVCO max, 3200-MHz
#define	KPLL_FVCO(m, n)		(((uint64_t)KCRYSTAL * (n)) / (m))			// f(vco) = f(ck in) * (N / M), PLLxSEL = HSI

// Compile-time checks of a PLL configuration (RM0486, integer mode)

#define	KPLL_STATIC_CHECKS(x, m, n, pdiv1, pdiv2, freq)																				\
	static_assert(((m) >= 1u) && ((m) <= 63u), "PLL" #x ": DIVM shall be in 1..63");												\
	static_assert(((n) >= 16u) && ((n) <= 640u), "PLL" #x ": DIVN shall be in 16..640");											\
	static_assert(((pdiv1) >= 1u) && ((pdiv1) <= 7u), "PLL" #x ": PDIV1 shall be in 1..7");											\
	static_assert(((pdiv2) >= 1u) && ((pdiv2) <= 7u), "PLL" #x ": PDIV2 shall be in 1..7");											\
	static_assert((KPLL_FVCO(m, n) >= KPLL_FVCO_MIN) && (KPLL_FVCO(m, n) <= KPLL_FVCO_MAX), "PLL" #x ": FVCO out of range");		\
	static_assert((KPLL_FVCO(m, n) / ((pdiv1) * (pdiv2))) == (freq), "PLL" #x ": configuration does not match KFREQUENCY_PLL" #x)

// PLL 1

#define	KCFG_PLL1DIVM	5u												// M = 5
#define	KCFG_PLL1DIVN	125u											// N = 125
#define	KCFG_PLL1PDIV1	2u												// VCO / 2
#define	KCFG_PLL1PDIV2	1u												//

// PLL 2

#define	KCFG_PLL2DIVM	5u												// M = 5
#define	KCFG_PLL2DIVN	125u											// N = 125
#define	KCFG_PLL2PDIV1	2u												// VCO / 2
#define	KCFG_PLL2PDIV2	1u												//

// PLL 3

#define	KCFG_PLL3DIVM	5u												// M = 5
#define	KCFG_PLL3DIVN	125u											// N = 125
#define	KCFG_PLL3PDIV1	4u												// VCO / 4
#define	KCFG_PLL3PDIV2	1u												//

// PLL 4

#define	KCFG_PLL4DIVM	5u												// M = 5
#define	KCFG_PLL4DIVN	125u											// N = 125
#define	KCFG_PLL4PDIV1	4u												// VCO / 4
#define	KCFG_PLL4PDIV2	1u												//

// IC source selection
// -------------------

// ICx source selection (RM0486, RCC_ICxCFGR.ICxSEL)

#define	KICSEL_PLL1_CK		0u											// pll1_ck
#define	KICSEL_PLL2_CK		1u											// pll2_ck
#define	KICSEL_PLL3_CK		2u											// pll3_ck
#define	KICSEL_PLL4_CK		3u											// pll4_ck

// IC1

#define	KCFG_IC1SEL			KICSEL_PLL1_CK								// PLL1
#define	KCFG_IC1INT_DIV		1u											// IC1 = PLL1 / 1, ~800-MHz

// IC2

#define	KCFG_IC2SEL			KICSEL_PLL1_CK								// PLL1
#define	KCFG_IC2INT_DIV		2u											// IC2 = PLL1 / 2, ~400-MHz

// IC4

#define	KCFG_IC4SEL			KICSEL_PLL4_CK								// PLL4
#define	KCFG_IC4INT_DIV		2u											// IC4 = PLL4 / 2, ~200-MHz

// IC9

#define	KCFG_IC9SEL			KICSEL_PLL3_CK								// PLL3
#define	KCFG_IC9INT_DIV		4u											// IC9 = PLL3 / 4, ~100-MHz

// IC11

#define	KCFG_IC11SEL		KICSEL_PLL3_CK								// PLL3
#define	KCFG_IC11INT_DIV	1u											// IC11 = PLL3 / 1, ~400-MHz

// IC15

#define	KCFG_IC15SEL		KICSEL_PLL1_CK								// PLL1
#define	KCFG_IC15INT_DIV	2u											// IC15 = PLL1 / 2, ~400-MHz

// IC20

#define	KCFG_IC20SEL		KICSEL_PLL3_CK								// PLL3
#define	KCFG_IC20INT_DIV	10u											// IC20 = PLL3 / 10, ~40-MHz

