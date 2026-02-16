/*
; RP2350_sha256.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_sha256 equates.
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

#include	<stdint.h>

// SHA256 address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	CSR;
	volatile	uint32_t	WDATA;
	volatile	uint32_t	SUM0;
	volatile	uint32_t	SUM1;
	volatile	uint32_t	SUM2;
	volatile	uint32_t	SUM3;
	volatile	uint32_t	SUM4;
	volatile	uint32_t	SUM5;
	volatile	uint32_t	SUM6;
	volatile	uint32_t	SUM7;
} SHA256_TypeDef;

#ifdef __cplusplus
#define	SHA256_NS	reinterpret_cast<SHA256_TypeDef *>(0x400F8000u)
#define	SHA256_S	reinterpret_cast<SHA256_TypeDef *>(0x400F8000u)
#else
#define	SHA256_NS	((SHA256_TypeDef *)0x400F8000u)
#define	SHA256_S	((SHA256_TypeDef *)0x400F8000u)
#endif

// CSR Configuration

#define	SHA256_CSR_START				(0x1u<<0)
#define	SHA256_CSR_WDATA_RDY			(0x1u<<1)
#define	SHA256_CSR_SUM_VLD				(0x1u<<2)
#define	SHA256_CSR_ERR_WDATA_NOT_RDY	(0x1u<<4)
#define	SHA256_CSR_DMA_SIZE				(0x3u<<8)
#define	SHA256_CSR_DMA_SIZE_0			(0x1u<<8)
#define	SHA256_CSR_BSWAP				(0x1u<<12)
#define	SHA256_CSR_DMA_SIZE_8BIT		(0x0u<<8)
#define	SHA256_CSR_DMA_SIZE_16BIT		(0x1u<<8)
#define	SHA256_CSR_DMA_SIZE_32BIT		(0x2u<<8)

// WDATA Configuration

#define	SHA256_WDATA_WDATA				(0xFFFFFFFFu<<0)
#define	SHA256_WDATA_WDATA_0			(0x1u<<0)

// SUM0 Configuration

#define	SHA256_SUM0_SUM0				(0xFFFFFFFFu<<0)
#define	SHA256_SUM0_SUM0_0				(0x1u<<0)

// SUM1 Configuration

#define	SHA256_SUM1_SUM1				(0xFFFFFFFFu<<0)
#define	SHA256_SUM1_SUM1_0				(0x1u<<0)

// SUM2 Configuration

#define	SHA256_SUM2_SUM2				(0xFFFFFFFFu<<0)
#define	SHA256_SUM2_SUM2_0				(0x1u<<0)

// SUM3 Configuration

#define	SHA256_SUM3_SUM3				(0xFFFFFFFFu<<0)
#define	SHA256_SUM3_SUM3_0				(0x1u<<0)

// SUM4 Configuration

#define	SHA256_SUM4_SUM4				(0xFFFFFFFFu<<0)
#define	SHA256_SUM4_SUM4_0				(0x1u<<0)

// SUM5 Configuration

#define	SHA256_SUM5_SUM5				(0xFFFFFFFFu<<0)
#define	SHA256_SUM5_SUM5_0				(0x1u<<0)

// SUM6 Configuration

#define	SHA256_SUM6_SUM6				(0xFFFFFFFFu<<0)
#define	SHA256_SUM6_SUM6_0				(0x1u<<0)

// SUM7 Configuration

#define	SHA256_SUM7_SUM7				(0xFFFFFFFFu<<0)
#define	SHA256_SUM7_SUM7_0				(0x1u<<0)
