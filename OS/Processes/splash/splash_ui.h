/*
; splash_ui.
; ==========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-10-08
; Modifs:
;
; Project:	uKOS-X
; Goal:		Drawing of the boot banner of the splash process.
;
;   (c) 2026, Laurent von Allmen
;   ----------------------------
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

#pragma once

#include	"splash.h"

// Logo
// The logo of ip.h is an ASCII art made of '_' and '/', each one drawn
// as a line inside a cell. Further than KLOGO_NB_COLUMNS, its rows hold
// the tag line, which is a text

#define KMARGIN					20u													// Left and right margins
#define KLOGO_NB_COLUMNS		68u													// Columns of the ASCII art
#define KLOGO_CELL_WIDTH		((KLCD_WIDTH - (2u * KMARGIN)) / KLOGO_NB_COLUMNS)	// Cell width
#define KLOGO_CELL_HEIGHT		(2u * KLOGO_CELL_WIDTH)								// Cell height
#define KLOGO_LINE_WIDTH		2u													// Line width
#define KLOGO_NB_TAG_LINES		2u													// Max. number of tag lines

// Positions

#define KTITLE_POS_Y			12													// Y of the title
#define KLOGO_GAP_Y				10													// Gap between the title and the logo
#define KTAG_GAP_Y				4													// Tag line shift under the logo
#define KINFO_GAP_Y				14													// Gap between the logo and the information

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	void	splash_ui_draw(void);

#if (defined(__cplusplus))
}
#endif
