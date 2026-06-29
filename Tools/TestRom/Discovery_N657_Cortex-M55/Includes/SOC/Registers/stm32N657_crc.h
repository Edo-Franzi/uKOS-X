/*
; stm32N657_crc.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_crc equates.
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

// CRC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	DR;
	volatile	uint32_t	IDR;
	volatile	uint32_t	CR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	INIT;
	volatile	uint32_t	POL;
} CRC_TypeDef;

#if (defined(__cplusplus))
#define	CRC_NS	reinterpret_cast<CRC_TypeDef *>(0x46024C00u)
#define	CRC_S	reinterpret_cast<CRC_TypeDef *>(0x56024C00u)

#else
#define	CRC_NS	((CRC_TypeDef *)0x46024C00u)
#define	CRC_S	((CRC_TypeDef *)0x56024C00u)
#endif

// DR Configuration

#define	CRC_DR_DR				(0xFFFFFFFFu<<0)
#define	CRC_DR_DR_0				(0x1u<<0)

// IDR Configuration

#define	CRC_IDR_IDR				(0xFFFFFFFFu<<0)
#define	CRC_IDR_IDR_0			(0x1u<<0)

// CR Configuration

#define	CRC_CR_RTYPE_OUT		(0x1u<<10)
#define	CRC_CR_RTYPE_IN			(0x1u<<9)
#define	CRC_CR_REV_OUT			(0x3u<<7)
#define	CRC_CR_REV_OUT_0		(0x1u<<7)
#define	CRC_CR_REV_IN			(0x3u<<5)
#define	CRC_CR_REV_IN_0			(0x1u<<5)
#define	CRC_CR_POLYSIZE			(0x3u<<3)
#define	CRC_CR_POLYSIZE_0		(0x1u<<3)
#define	CRC_CR_RESET			(0x1u<<0)

#define	CRC_CR_RTYPE_OUT_B_0X0	(0x0u<<10)
#define	CRC_CR_RTYPE_OUT_B_0X1	(0x1u<<10)
#define	CRC_CR_RTYPE_IN_B_0X0	(0x0u<<9)
#define	CRC_CR_RTYPE_IN_B_0X1	(0x1u<<9)
#define	CRC_CR_REV_OUT_B_0X0	(0x0u<<7)
#define	CRC_CR_REV_OUT_B_0X1	(0x1u<<7)
#define	CRC_CR_REV_OUT_B_0X2	(0x2u<<7)
#define	CRC_CR_REV_OUT_B_0X3	(0x3u<<7)
#define	CRC_CR_REV_IN_B_0X0		(0x0u<<5)
#define	CRC_CR_REV_IN_B_0X1		(0x1u<<5)
#define	CRC_CR_REV_IN_B_0X2		(0x2u<<5)
#define	CRC_CR_REV_IN_B_0X3		(0x3u<<5)
#define	CRC_CR_POLYSIZE_B_0X0	(0x0u<<3)
#define	CRC_CR_POLYSIZE_B_0X1	(0x1u<<3)
#define	CRC_CR_POLYSIZE_B_0X2	(0x2u<<3)
#define	CRC_CR_POLYSIZE_B_0X3	(0x3u<<3)

// INIT Configuration

#define	CRC_INIT_CRC_INIT		(0xFFFFFFFFu<<0)
#define	CRC_INIT_CRC_INIT_0		(0x1u<<0)

// POL Configuration

#define	CRC_POL_POL				(0xFFFFFFFFu<<0)
#define	CRC_POL_POL_0			(0x1u<<0)
