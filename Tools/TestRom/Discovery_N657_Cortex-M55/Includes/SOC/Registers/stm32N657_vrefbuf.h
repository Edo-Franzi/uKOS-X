/*
; stm32N657_vrefbuf.
; ==================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_vrefbuf equates.
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

// VREFBUF address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	CSR;
	volatile	uint32_t	CCR;
} VREFBUF_TypeDef;

#if (defined(__cplusplus))
#define	VREFBUF_NS	reinterpret_cast<VREFBUF_TypeDef *>(0x46003C00u)
#define	VREFBUF_S	reinterpret_cast<VREFBUF_TypeDef *>(0x56003C00u)

#else
#define	VREFBUF_NS	((VREFBUF_TypeDef *)0x46003C00u)
#define	VREFBUF_S	((VREFBUF_TypeDef *)0x56003C00u)
#endif

// CSR Configuration

#define	VREFBUF_CSR_VRS			(0x7u<<4)
#define	VREFBUF_CSR_VRS_0		(0x1u<<4)
#define	VREFBUF_CSR_VRR			(0x1u<<3)
#define	VREFBUF_CSR_HIZ			(0x1u<<1)
#define	VREFBUF_CSR_ENVR		(0x1u<<0)

#define	VREFBUF_CSR_VRR_B_0X0	(0x0u<<3)
#define	VREFBUF_CSR_VRR_B_0X1	(0x1u<<3)
#define	VREFBUF_CSR_HIZ_B_0X0	(0x0u<<1)
#define	VREFBUF_CSR_HIZ_B_0X1	(0x1u<<1)
#define	VREFBUF_CSR_ENVR_B_0X0	(0x0u<<0)
#define	VREFBUF_CSR_ENVR_B_0X1	(0x1u<<0)

// CCR Configuration

#define	VREFBUF_CCR_TRIM		(0x3Fu<<0)
#define	VREFBUF_CCR_TRIM_0		(0x1u<<0)
