/*
; debug.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Some consts that could be necessary for debugging tool
;			susch as Segger Ozone.
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

// Debug kernel
// ------------

#if (!defined(DEBUG_KERN_TRACE))
#define	DEBUG_KERN_TRACE(text);
#endif

// uKOS-X architecture constants
// ------------------------------

// Used architecture
// uKOS_ARCHITECTURE is specially designed for third parties debug
// tools such as Segger Ozone plugin
//
// cortex -M3, -M4, -M7, -M33 -m55 -m85 = 0
// risc-v (RV32) RV32IMAC				= 1
// risc-v (RV64) RV64IMAFDC				= 2

#if (defined(CORTEX_M3_S) || defined(CORTEX_M4_S) || defined(CORTEX_M7_S) || defined(CORTEX_M33_S) || defined(CORTEX_M55_S) || defined(CORTEX_M85_S))
#define	uKOS_ARCHITECTURE	0u

#elif (defined(RV32IMAC_S))
#define	uKOS_ARCHITECTURE	1u

#elif (defined(RV64IMAFDC_S))
#define	uKOS_ARCHITECTURE	2u

#else
#error	"*** Architecture not defined"
#endif
