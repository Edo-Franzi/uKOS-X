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

#define	LED_SYSTEM_ON		(REG(SIO)->GPIO_OUT_SET = (1<<BLED_s))		//
#define	LED_SYSTEM_OFF		(REG(SIO)->GPIO_OUT_CLR = (1<<BLED_s))		//
#define	LED_SYSTEM_TOGGLE	(REG(SIO)->GPIO_OUT_XOR = (1<<BLED_s))		// Led macros

#define	LED_YELLOW_ON		(REG(SIO)->GPIO_OUT_SET = (1<<BLED_0))		//
#define	LED_YELLOW_OFF		(REG(SIO)->GPIO_OUT_CLR = (1<<BLED_0))		//
#define	LED_YELLOW_TOGGLE	(REG(SIO)->GPIO_OUT_XOR = (1<<BLED_0))		// Led macros

#define	LED_GREEN_ON		(REG(SIO)->GPIO_OUT_SET = (1<<BLED_1))		//
#define	LED_GREEN_OFF		(REG(SIO)->GPIO_OUT_CLR = (1<<BLED_1))		//
#define	LED_GREEN_TOGGLE	(REG(SIO)->GPIO_OUT_XOR = (1<<BLED_1))		// Led macros

#define	LED_RED_ON			(REG(SIO)->GPIO_OUT_SET = (1<<BLED_2))		//
#define	LED_RED_OFF			(REG(SIO)->GPIO_OUT_CLR = (1<<BLED_2))		//
#define	LED_RED_TOGGLE		(REG(SIO)->GPIO_OUT_XOR = (1<<BLED_2))		// Led macros

#define KNB_LED				4u											// Number of LEDs

// PORTs

#define	BLED_s				25u											// GPIO25, LED system
#define	BLED_0				11u											// GPIO11, LED yellow
#define	BLED_1				12u											// GPIO12, LED green
#define	BLED_2				13u											// GPIO13, LED red
