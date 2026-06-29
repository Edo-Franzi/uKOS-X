/*
; board.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Board mapping.
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

// GPIO settings
// -------------

#define	LED_GREEN_ON		(REG(GPIOO)->ODR |=  		   (1<<BLED_1))		//
#define	LED_GREEN_OFF		(REG(GPIOO)->ODR &= (uint32_t)~(1<<BLED_1))		//
#define	LED_GREEN_TOGGLE	(REG(GPIOO)->ODR ^=			   (1<<BLED_1))		//
#define	LED_RED_ON			(REG(GPIOG)->ODR &= (uint32_t)~(1<<BLED_2))		//
#define	LED_RED_OFF			(REG(GPIOG)->ODR |=  		   (1<<BLED_2))		//
#define	LED_RED_TOGGLE		(REG(GPIOG)->ODR ^=			   (1<<BLED_2))		//

#define KNB_LED				3u												// Number of LEDs

// PORTs

#define	BLED_0				15u												// PORT E 15, LED
#define	BLED_1				1u												// PORT O 1, LED
#define	BLED_2				10u												// PORT G 10, LED
#define	BSW_0				13u												// PORT C 13, SW1
#define	BLCD_NRST			1u												// PORT E 1, LCD reset
#define	BLCD_POWER			3u												// PORT Q 3, LCD power
#define	BBL_CTRL			6u												// PORT Q 6, LCD backlignt
