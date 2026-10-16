/*
; nrf5340_network_uicr.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_uicr equates.
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

// UICR address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	APPROTECT;
	volatile	uint32_t	ERASEPROTECT;
	volatile	uint32_t	RESERVED0[126];
	volatile	uint32_t	NRFFW[32];
	volatile	uint32_t	RESERVED1[32];
	volatile	uint32_t	CUSTOMER[32];
} UICR_TypeDef;

#if (defined(__cplusplus))
#define	UICR_NS	reinterpret_cast<UICR_TypeDef *>(0x01FF8000u)

#else
#define	UICR_NS	((UICR_TypeDef *)0x01FF8000u)
#endif

// APPROTECT Configuration

#define	UICR_APPROTECT_PALL						(0xFFFFFFFFu<<0)
#define	UICR_APPROTECT_PALL_0					(0x1u<<0)
#define	UICR_APPROTECT_PALL_UNPROTECTED			(0x50FA50FAu<<0)
#define	UICR_APPROTECT_PALL_PROTECTED			(0x0u<<0)

// ERASEPROTECT Configuration

#define	UICR_ERASEPROTECT_PALL					(0xFFFFFFFFu<<0)
#define	UICR_ERASEPROTECT_PALL_0				(0x1u<<0)
#define	UICR_ERASEPROTECT_PALL_UNPROTECTED		(0xFFFFFFFFu<<0)
#define	UICR_ERASEPROTECT_PALL_PROTECTED		(0x0u<<0)

// NRFFW Configuration

#define	UICR_NRFFW_NRFFW						(0xFFFFFFFFu<<0)
#define	UICR_NRFFW_NRFFW_0						(0x1u<<0)

// CUSTOMER Configuration

#define	UICR_CUSTOMER_CUSTOMER					(0xFFFFFFFFu<<0)
#define	UICR_CUSTOMER_CUSTOMER_0				(0x1u<<0)
