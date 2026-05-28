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

#define KNB_LED				(8u + 3u)							// Number of LEDs

// PORTs

#define	BLED_0				9u									// PORT I 9, LED
#define	BLED_1				10u									// PORT I 10, LED
#define	BLED_2				13u									// PORT I 13, LED
#define	BLED_3				14u									// PORT I 14, LED
#define	BLED_4				15u									// PORT I 15, LED
#define	BLED_5				13u									// PORT H 13, LED
#define	BLED_6				6u									// PORT D 6, LED
#define	BLED_7				2u									// PORT E 2, LED
#define	BLED_RED			5u									// PORT K 5, LED Red
#define	BLED_GREEN			6u									// PORT K 6, LED Green
#define	BLED_BLUE			7u									// PORT K 7, LED Blue

#define	BPUSH_0				0u									// PORT A 0, PUSH0

#define	BSW_0				8u									// PORT B 8, SW0
#define	BSW_1				14u									// PORT B 14, SW1
#define	BSW_2				15u									// PORT B 15, SW2
#define	BSW_3				2u									// PORT B 2, SW3

#define	BLOGIC_0			15u									// PORT I 15, LOGIC0
#define	BLOGIC_1			13u									// PORT H 13, LOGIC1
