/*
; clockTree.
; ==========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

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
// Fcpu:			600-MHz		sysa_ck (ic1)
// Fnpu:			600-MHz		sysc_ck (ic6)
// Faxi:			150-MHz		sysb_ck (ic2)
// FaxiRAMNPU:		300-MHz		sysd_ck (1c11)
//
// !!! Some silicon limitations. PBx HAS to be = AHB
//
// Faxi, 150-MHz, FBusMax
// - Timer group 1, 150-MHz
// - Timer group 2, 150-MHz
// - sys_bus2_ck (pclkx), 150-MHz, Faxi / 1
//		- APB1,2,4,5, 150-MHz, sys_bus2_ck / 1
//
// Simple peripherals
// Fadc12, 		pclk5 150-MHz
// Fi2cx, 		pclk5 150-MHz (x=1, 2, 3 ,4)
// Fi3cx, 		pclk5 150-MHz (x=1, 2)
// Fsaix, 		pclk2 150-MHz (x=1, 2)
// Fspix, 		pclk4 150-MHz (x=1, 2, 3, 4, 5, 6)
// Flptimx,		pclk4 150-MHz (x=1, 2, 3, 4, 5)
// Fusartx,		pclk1 150-MHz (x=1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
// Flpusartx,	pclk4 150-MHz (x=1, 2)
// Flpuartx,	pclk4 150-MHz (x=1)

#define KCRYSTAL			64000000u									// Quartz crystal resonator
#define KFREQUENCY_PLL1		608000000u									// PLL 1 CPU frequency of 608-MHz
#define KFREQUENCY_PLL2		608000000u									// PLL 2 NPU frequency of 608-MHz
#define KFREQUENCY_PLL3		150000000u									// PLL 3 AXI frequency of 150-MHz
#define KFREQUENCY_PLL4		150000000u									// PLL 4 PER frequency of 300-MHz

// !! Errata & silicon limitations

#define KTIMPRE				0u											// Div 1 (2^0)
#define KHPRE				0u											// Div 1 (2^0)
#define KPPRE1				0u											// Div 1 (2^0)
#define KPPRE2				0u											// Div 1 (2^0)
#define KPPRE4				0u											// Div 1 (2^0)
#define KPPRE5				0u											// Div 1 (2^0)

#define KFREQUENCY_CPU		KFREQUENCY_PLL1								// CPU bus frequency of 608-MHz
#define KFREQUENCY_NPU		KFREQUENCY_PLL2								// NPU bus frequency of 608-MHz
#define KFREQUENCY_AXI		KFREQUENCY_PLL4								// AXI bus frequency of 150-MHz
#define KFREQUENCY_TIM		(KFREQUENCY_AXI / (1u<<KTIMPRE))			// TIM bus frequency of 150-MHz
#define KFREQUENCY_HCL		(KFREQUENCY_AXI / (1u<<KHPRE))				// HCL bus frequency of 150-MHz
#define KFREQUENCY_APB1		(KFREQUENCY_HCL / (1u<<KPPRE1))				// APB1 bus frequency of 150-MHz
#define KFREQUENCY_APB2		(KFREQUENCY_HCL / (1u<<KPPRE2))				// APB2 bus frequency of 150-MHz
#define KFREQUENCY_APB4		(KFREQUENCY_HCL / (1u<<KPPRE4))				// APB4 bus frequency of 150-MHz
#define KFREQUENCY_APB5		(KFREQUENCY_HCL / (1u<<KPPRE5))				// APB5 bus frequency of 150-MHz
#define KFREQUENCY_1GHz		1000000000u									// Frequency of 1-GHz
#define KFREQUENCY_1MHz		1000000u									// Frequency of 1-MHz
#define KFREQUENCY_1KHz		1000u										// Frequency of 1-KHz
#define KFREQUENCY_CORE		KFREQUENCY_CPU								// CORE frequency
