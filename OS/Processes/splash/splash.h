/*
; splash.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-10-08
; Modifs:
;
; Project:	uKOS-X
; Goal:		Splash process; draw the boot banner on the LCD display, then terminate.
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

#include	<stdint.h>
#include	"ulvgl.h"

// Display size

#define KLCD_BUF_LINES			10u											// Lines of the draw buffer (partial rendering)
#define KLCD_NB_BYTES_PIXEL		4u											// XRGB8888
#define KLCD_WIDTH				800u										// LCD width
#define KLCD_HEIGHT				480u										// LCD height

// Used colors
//								  RRGGBB
#define KBACKGROUND				0x00000000u									// Black
#define KFOREGROUND				0x00E0E0E0u									// Light grey

#if (defined(__cplusplus))
extern	"C" {
#endif

// Provided by the board stub
// stub_splash_on needs the privileged mode and has to be called by a process

extern	void	stub_splash_on(uint32_t rgb8888);
extern	void	stub_splash_flush_cb(lv_display_t *lv_display, const lv_area_t *area, uint8_t *pixelMapping);

#if (defined(__cplusplus))
}
#endif
