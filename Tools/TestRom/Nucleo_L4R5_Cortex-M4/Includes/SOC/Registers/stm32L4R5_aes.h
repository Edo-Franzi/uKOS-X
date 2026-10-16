/*
; stm32L4R5_aes.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_aes equates.
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

// AES address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	DINR;
	volatile	uint32_t	DOUTR;
	volatile	uint32_t	KEYR0;
	volatile	uint32_t	KEYR1;
	volatile	uint32_t	KEYR2;
	volatile	uint32_t	KEYR3;
	volatile	uint32_t	IVR0;
	volatile	uint32_t	IVR1;
	volatile	uint32_t	IVR2;
	volatile	uint32_t	IVR3;
} AES_TypeDef;

#if (defined(__cplusplus))
#define	AES	reinterpret_cast<AES_TypeDef *>(0x50060000u)

#else
#define	AES	((AES_TypeDef *)0x50060000u)
#endif

// CR Configuration

#define	AES_CR_EN				(0x1u<<0)
#define	AES_CR_DATATYPE			(0x3u<<1)
#define	AES_CR_DATATYPE_0		(0x1u<<1)
#define	AES_CR_MODE				(0x3u<<3)
#define	AES_CR_MODE_0			(0x1u<<3)
#define	AES_CR_CHMOD			(0x3u<<5)
#define	AES_CR_CHMOD_0			(0x1u<<5)
#define	AES_CR_CCFC				(0x1u<<7)
#define	AES_CR_ERRC				(0x1u<<8)
#define	AES_CR_CCFIE			(0x1u<<9)
#define	AES_CR_ERRIE			(0x1u<<10)
#define	AES_CR_DMAINEN			(0x1u<<11)
#define	AES_CR_DMAOUTEN			(0x1u<<12)

// SR Configuration

#define	AES_SR_CCF				(0x1u<<0)
#define	AES_SR_RDERR			(0x1u<<1)
#define	AES_SR_WRERR			(0x1u<<2)

// DINR Configuration

#define	AES_DINR_AES_DINR		(0xFFFFFFFFu<<0)
#define	AES_DINR_AES_DINR_0		(0x1u<<0)

// DOUTR Configuration

#define	AES_DOUTR_AES_DOUTR		(0xFFFFFFFFu<<0)
#define	AES_DOUTR_AES_DOUTR_0	(0x1u<<0)

// KEYR0 Configuration

#define	AES_KEYR0_AES_KEYR0		(0xFFFFFFFFu<<0)
#define	AES_KEYR0_AES_KEYR0_0	(0x1u<<0)

// KEYR1 Configuration

#define	AES_KEYR1_AES_KEYR1		(0xFFFFFFFFu<<0)
#define	AES_KEYR1_AES_KEYR1_0	(0x1u<<0)

// KEYR2 Configuration

#define	AES_KEYR2_AES_KEYR2		(0xFFFFFFFFu<<0)
#define	AES_KEYR2_AES_KEYR2_0	(0x1u<<0)

// KEYR3 Configuration

#define	AES_KEYR3_AES_KEYR3		(0xFFFFFFFFu<<0)
#define	AES_KEYR3_AES_KEYR3_0	(0x1u<<0)

// IVR0 Configuration

#define	AES_IVR0_AES_IVR0		(0xFFFFFFFFu<<0)
#define	AES_IVR0_AES_IVR0_0		(0x1u<<0)

// IVR1 Configuration

#define	AES_IVR1_AES_IVR1		(0xFFFFFFFFu<<0)
#define	AES_IVR1_AES_IVR1_0		(0x1u<<0)

// IVR2 Configuration

#define	AES_IVR2_AES_IVR2		(0xFFFFFFFFu<<0)
#define	AES_IVR2_AES_IVR2_0		(0x1u<<0)

// IVR3 Configuration

#define	AES_IVR3_AES_IVR3		(0xFFFFFFFFu<<0)
#define	AES_IVR3_AES_IVR3_0		(0x1u<<0)
