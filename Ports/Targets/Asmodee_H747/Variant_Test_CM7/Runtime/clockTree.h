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

// SPI 1,2,3								ck = PLL1 Q
// SPI 4,5									ck = rcc_pclk2 -> APB2
// SPI 6									ck = rcc_pclk4 -> APB4
// QUAD SPI									ck = rcc_hclk3 -> AHB3
// I2C 1,2,3								ck = rcc_pclk1 -> APB1
// I2C 4									ck = rcc_pclk4 -> APB4
// LPUSART 1								ck = rcc_pclk4 -> APB4
// USART 1,6								ck = rcc_pclk2 -> APB2
// USART 2,3,4,5,7,8						ck = rcc_pclk1 -> APB1
// FMC										ck = rcc_hclk3 -> AHB3
// ADC 1,2,3								ck = PLL2 P
// RNG										ck = PLL1 Q
// USB										ck = PLL3 Q
// LPTIM 1									ck = rcc_pclk1 -> APB1
// LPTIM 2,3,4,5							ck = rcc_pclk4 -> APB4
// TIM 1,2,3,4,5,6,7,8,12,13,14,15,16,17	ck = ??? -> A??

#define KCRYSTAL			16000000u									// Quartz crystal resonator
#define KFREQUENCY_PLL1P	480000000u									// PLL 1 P bus frequency of 480-MHz
#define KFREQUENCY_PLL1Q	240000000u									// PLL 1 Q bus frequency of 240-MHz
#define KFREQUENCY_PLL1R	120000000u									// PLL 1 R bus frequency of 120-MHz
#define KFREQUENCY_PLL2P	100000000u									// PLL 2 P bus frequency of 100-MHz
#define KFREQUENCY_PLL2Q	50000000u									// PLL 2 Q bus frequency of 50-MHz
#define KFREQUENCY_PLL2R	25000000u									// PLL 2 R bus frequency of 25-MHz
#define KFREQUENCY_PLL3P	120000000u									// PLL 3 P bus frequency of 120-MHz
#define KFREQUENCY_PLL3Q	48000000u									// PLL 3 Q bus frequency of 48-MHz
#define KFREQUENCY_PLL3R	120000000u									// PLL 3 R bus frequency of 120-MHz

#define KD1CPRE				1u											// Div 1
#define KHPRE				2u											// Div 2
#define KD1PPRE				1u											// Div 1
#define KD2PPRE1			4u											// Div 4
#define KD2PPRE2			4u											// Div 4
#define KD3PPRE				2u											// Div 2
#define KTIMPRE				2u											// Div 2

#define KFREQUENCY_AHB		(KFREQUENCY_PLL1P / KD1CPRE)				// AHB bus frequency of 480-MHz
#define KFREQUENCY_APB		(KFREQUENCY_AHB / KHPRE)					// APB bus frequency of 240-MHz

#define KFREQUENCY_AXI		KFREQUENCY_APB								// AXI bus frequency of 240-MHz
#define KFREQUENCY_AHB1		KFREQUENCY_APB								// AHB1 bus frequency of 240-MHz
#define KFREQUENCY_AHB2		KFREQUENCY_APB								// AHB2 bus frequency of 240-MHz
#define KFREQUENCY_AHB3		KFREQUENCY_APB								// AHB3 bus frequency of 240-MHz
#define KFREQUENCY_AHB4		KFREQUENCY_APB								// AHB4 bus frequency of 240-MHz
#define KFREQUENCY_APB1		(KFREQUENCY_APB / KD2PPRE1)					// APB1 bus frequency of 60-MHz
#define KFREQUENCY_APB2		(KFREQUENCY_APB / KD2PPRE2)					// APB2 bus frequency of 60-MHz
#define KFREQUENCY_APB3		(KFREQUENCY_APB / KD1PPRE)					// APB3 bus frequency of 120-MHz
#define KFREQUENCY_APB4		(KFREQUENCY_APB / KD3PPRE)					// APB4 bus frequency of 120-MHz
#define KFREQUENCY_TIM		(KFREQUENCY_APB / KTIMPRE)					// Timer clock 120-MHz
#define KFREQUENCY_1GHz		1000000000u									// Frequency of 1-GHz
#define KFREQUENCY_1MHz		1000000u									// Frequency of 1-MHz
#define KFREQUENCY_1KHz		1000u										// Frequency of 1-KHz
#define KFREQUENCY_CORE		KFREQUENCY_AHB								// CORE frequency
