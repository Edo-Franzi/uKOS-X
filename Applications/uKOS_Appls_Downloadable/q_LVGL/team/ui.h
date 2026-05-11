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
;			Simple UI for the team demo.
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

#define	KLCD_BUF_LINES		10u																	// Limited buffer (10 * KLCD_WIDTH * 2) to force partial rendering
#define	KLCD_WIDTH			320u																// LCD width
#define	KLCD_HEIGHT			240u																// LCD height

// Bars

#define KBAR_MAX_VALUE		2000u																// Max value
#define KBAR_MIN_VALUE		0u																	// Min value
#define	KBAR_POS_Y			15u																	// Y = 15 for all the bars
#define	KBAR_POS_X_1		140u																// X = 140 for all the bars 1
#define	KBAR_POS_X_2		170u																// X = 170 for all the bars 2
#define	KBAR_POS_X_3		200u																// X = 200 for all the bars 3
#define	KBAR_GAP_Y			6u																	// Bar gap
#define	KBAR_LABEL_WIDTH	80u																	// Bar label max width
#define	KBAR_HEIGHT			20u																	// Bar height
#define	KBAR_WIDTH			(KLCD_WIDTH - (2 * KBAR_POS_Y) - KBAR_LABEL_WIDTH - KBAR_GAP_Y)		// Bar width
