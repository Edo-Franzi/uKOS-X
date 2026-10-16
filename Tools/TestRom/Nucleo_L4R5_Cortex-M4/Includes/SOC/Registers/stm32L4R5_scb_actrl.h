/*
; stm32L4R5_scb_actrl.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_scb_actrl equates.
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

// SCB_ACTRL address definitions
// -----------------------------

typedef struct {
	volatile	uint32_t	ACTRL;
} SCB_ACTRL_TypeDef;

#if (defined(__cplusplus))
#define	SCB_ACTRL	reinterpret_cast<SCB_ACTRL_TypeDef *>(0xE000E008u)

#else
#define	SCB_ACTRL	((SCB_ACTRL_TypeDef *)0xE000E008u)
#endif

// ACTRL Configuration

#define	SCB_ACTRL_ACTRL_DISOOFP		(0x1u<<9)
#define	SCB_ACTRL_ACTRL_DISFPCA		(0x1u<<8)
#define	SCB_ACTRL_ACTRL_DISFOLD		(0x1u<<2)
#define	SCB_ACTRL_ACTRL_DISDEFWBUF	(0x1u<<1)
#define	SCB_ACTRL_ACTRL_DISMCYCINT	(0x1u<<0)
