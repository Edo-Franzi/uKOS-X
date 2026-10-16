/*
; stm32U5Gx_pka.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_pka equates.
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

// PKA address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	CLRFR;
} PKA_TypeDef;

#if (defined(__cplusplus))
#define	PKA_NS	reinterpret_cast<PKA_TypeDef *>(0x420C2000u)
#define	PKA_S	reinterpret_cast<PKA_TypeDef *>(0x520C2000u)

#else
#define	PKA_NS	((PKA_TypeDef *)0x420C2000u)
#define	PKA_S	((PKA_TypeDef *)0x520C2000u)
#endif

// CR Configuration

#define	PKA_CR_EN			(0x1u<<0)
#define	PKA_CR_START		(0x1u<<1)
#define	PKA_CR_MODE			(0x3Fu<<8)
#define	PKA_CR_MODE_0		(0x1u<<8)
#define	PKA_CR_PROCENDIE	(0x1u<<17)
#define	PKA_CR_RAMERRIE		(0x1u<<19)
#define	PKA_CR_ADDRERRIE	(0x1u<<20)
#define	PKA_CR_OPERRIE		(0x1u<<21)

// SR Configuration

#define	PKA_SR_OPERRF		(0x1u<<21)
#define	PKA_SR_ADDRERRF		(0x1u<<20)
#define	PKA_SR_RAMERRF		(0x1u<<19)
#define	PKA_SR_PROCENDF		(0x1u<<17)
#define	PKA_SR_BUSY			(0x1u<<16)
#define	PKA_SR_INITOK		(0x1u<<0)

// CLRFR Configuration

#define	PKA_CLRFR_OPERRFC	(0x1u<<21)
#define	PKA_CLRFR_ADDRERRFC	(0x1u<<20)
#define	PKA_CLRFR_RAMERRFC	(0x1u<<19)
#define	PKA_CLRFR_PROCENDFC	(0x1u<<17)
