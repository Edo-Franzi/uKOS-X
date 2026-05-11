/*
; ui.
; ===

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			Simple UI for the basic demo.
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

// Display size

#define	KLCD_BUF_LINES		10u											// Limited buffer (10 * KLCD_WIDTH * 2) to force partial rendering
#define	KLCD_WIDTH			320u										// LCD width
#define	KLCD_HEIGHT			240u										// LCD height

// Used colors

#define	KMASK_24_BITS		0x00FFFFFFu									// Mask
#define	KRED				0x00FF0000u									// Red
#define	KGREEN				0x0000FF00u									// Green
#define	KBLUE				0x000000FFu									// Blue

// Text position (relative to the middle of the display 0, 0)

#define	KTEXT_POS_X			0u											// X = 0 for all the textes
#define	KTEXT_POS_Y_1		20u											// Y = 20 for all the text 1
#define	KTEXT_POS_Y_2		50u											// Y = 50 for all the text 2
#define	KTEXT_POS_Y_3		70u											// Y = 70 for all the text 2

// Arc diameter & positions

#define	KARC_DIAMETER		80u											// Arc diameter
#define	KARC_MARGIN			20u											// Arc margin
#define	KARC_POS_X			(KLCD_WIDTH - KARC_DIAMETER - KARC_MARGIN)	// X Arc
#define	KARC_POS_Y			KARC_MARGIN									// Y Arc

// Square dimension & positions

#define	KSQUARES_NB_MAX		20u											// 20 square
#define	KSQUARE_SIZE		30u											// Square size
