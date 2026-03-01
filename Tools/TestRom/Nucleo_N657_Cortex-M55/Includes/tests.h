/*
; tests.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test ROM routine collection.
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

#include	"types.h"
#include	"cmns.h"
#include	"debug.h"
#include	"core_reg.h"
#include	"soc_reg.h"
#include	"board.h"
#include	"clockTree.h"
#include	"macros.h"
#include	"macros_soc.h"
#include	"macros_core.h"
#include	"core.h"

#ifndef USING_CMAKE
#undef	TEST_00_S			// Test of the clocks via MCO1-2
#undef	TEST_01_S			// Test blink the RED, GREEN & BLUE Leds
#undef	TEST_02_S			// Test sending data via the cnms manager
#undef	TEST_03_S			// Test reading & sending data via the cnms manager
#undef	TEST_04_S			// Test of the USART1 Rx interruption
#undef	TEST_05_S			// Test of the USART1 Tx interruption
#define	TEST_06_S			// Test of a SVC call
#undef	TEST_07_S			// Test of a preliminary pico kernel (with messages swi)
#undef	TEST_08_S			// Test of the TIM2 interruption
#undef	TEST_09_S			// Test of the TIM3 interruption
#undef	TEST_10_S			// Test of the TIM4 interruption
#undef	TEST_11_S			// Test of the TIM5 interruption
#undef	TEST_12_S			// Test of some RAM limits
#undef	TEST_13_S			// Test of the MVE/Helium dot product benchmark
#endif

#define	NO_KERNEL_S			// No kernels (naked function entries)
