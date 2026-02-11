/*
; mpu.
; ====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		MPU equates.
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

// MPU address definitions
// -----------------------

typedef struct {
	volatile	const	uint32_t	TYPE;
	volatile			uint32_t	CTRL;
	volatile			uint32_t	RNR;
	volatile			uint32_t	RBAR;
	volatile			uint32_t	RLAR;
	volatile			uint32_t	RBAR_A1;
	volatile			uint32_t	RLAR_A1;
	volatile			uint32_t	RBAR_A2;
	volatile			uint32_t	RLAR_A2;
	volatile			uint32_t	RBAR_A3;
	volatile			uint32_t	RLAR_A3;
	volatile			uint32_t	RESERVED0;
	volatile			uint32_t	MAIR0;
	volatile			uint32_t	MAIR1;
} MPU_TypeDef;

#if (defined(__cplusplus))
#define	MPU_S	reinterpret_cast<MPU_TypeDef *>(0xE000ED90u)
#define	MPU_NS	reinterpret_cast<MPU_TypeDef *>(0xE002ED90u)

#else
#define	MPU_S	((MPU_TypeDef *)0xE000ED90u)
#define	MPU_NS	((MPU_TypeDef *)0xE002ED90u)
#endif
