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

#define	LED_BLUE_ON			(REG(GPIOG)->ODR &= (uint32_t)~(1<<BLED_0))		//
#define	LED_BLUE_OFF		(REG(GPIOG)->ODR |=  		   (1<<BLED_0))		//
#define	LED_BLUE_TOGGLE		(REG(GPIOG)->ODR ^=			   (1<<BLED_0))		//
#define	LED_RED_ON			(REG(GPIOG)->ODR &= (uint32_t)~(1<<BLED_1))		//
#define	LED_RED_OFF			(REG(GPIOG)->ODR |=  		   (1<<BLED_1))		//
#define	LED_RED_TOGGLE		(REG(GPIOG)->ODR ^=			   (1<<BLED_1))		//
#define	LED_GREEN_ON		(REG(GPIOG)->ODR &= (uint32_t)~(1<<BLED_2))		//
#define	LED_GREEN_OFF		(REG(GPIOG)->ODR |=			   (1<<BLED_2))		//
#define	LED_GREEN_TOGGLE	(REG(GPIOG)->ODR ^=			   (1<<BLED_2))		// Led macros

#define	ANALYSER_ON			(REG(GPIOG)->ODR &= (uint32_t)~(1<<BANALYSER))	//
#define	ANALYSER_OFF		(REG(GPIOG)->ODR |=  		   (1<<BANALYSER))	//
#define	ANALYSER_TOGGLE		(REG(GPIOG)->ODR ^=			   (1<<BANALYSER))	// Analyser macros

#define KNB_LED				3u												// Number of LEDs

// PORTs

#define	BLED_0				8u												// PORT G 8, LED
#define	BLED_1				10u												// PORT G 10, LED
#define	BLED_2				0u												// PORT G 0, LED
#define	BANALYSER			1u												// PORT G 1, Analyser
#define	BSW_0				13u												// PORT C 13, SW1
