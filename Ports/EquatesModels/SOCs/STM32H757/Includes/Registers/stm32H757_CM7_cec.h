/*
; stm32H757_CM7_cec.
; ==================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H757_CM7_cec equates.
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

// CEC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	CFGR;
	volatile	uint32_t	TXDR;
	volatile	uint32_t	RXDR;
	volatile	uint32_t	ISR;
	volatile	uint32_t	IER;
} CEC_TypeDef;

#if (defined(__cplusplus))
#define	CEC	reinterpret_cast<CEC_TypeDef *>(0x40006C00u)

#else
#define	CEC	((CEC_TypeDef *)0x40006C00u)
#endif

// CR Configuration

#define	CEC_CR_TXEOM		(0x1u<<2)
#define	CEC_CR_TXSOM		(0x1u<<1)
#define	CEC_CR_CECEN		(0x1u<<0)

// CFGR Configuration

#define	CEC_CFGR_LSTN		(0x1u<<31)
#define	CEC_CFGR_OAR		(0x7FFFu<<16)
#define	CEC_CFGR_OAR_0		(0x1u<<16)
#define	CEC_CFGR_SFTOPT		(0x1u<<8)
#define	CEC_CFGR_BRDNOGEN	(0x1u<<7)
#define	CEC_CFGR_LBPEGEN	(0x1u<<6)
#define	CEC_CFGR_BREGEN		(0x1u<<5)
#define	CEC_CFGR_BRESTP		(0x1u<<4)
#define	CEC_CFGR_RXTOL		(0x1u<<3)
#define	CEC_CFGR_SFT		(0x7u<<0)
#define	CEC_CFGR_SFT_0		(0x1u<<0)

// TXDR Configuration

#define	CEC_TXDR_TXD		(0xFFu<<0)
#define	CEC_TXDR_TXD_0		(0x1u<<0)

// RXDR Configuration

#define	CEC_RXDR_RXD		(0xFFu<<0)
#define	CEC_RXDR_RXD_0		(0x1u<<0)

// ISR Configuration

#define	CEC_ISR_TXACKE		(0x1u<<12)
#define	CEC_ISR_TXERR		(0x1u<<11)
#define	CEC_ISR_TXUDR		(0x1u<<10)
#define	CEC_ISR_TXEND		(0x1u<<9)
#define	CEC_ISR_TXBR		(0x1u<<8)
#define	CEC_ISR_ARBLST		(0x1u<<7)
#define	CEC_ISR_RXACKE		(0x1u<<6)
#define	CEC_ISR_LBPE		(0x1u<<5)
#define	CEC_ISR_SBPE		(0x1u<<4)
#define	CEC_ISR_BRE			(0x1u<<3)
#define	CEC_ISR_RXOVR		(0x1u<<2)
#define	CEC_ISR_RXEND		(0x1u<<1)
#define	CEC_ISR_RXBR		(0x1u<<0)

// IER Configuration

#define	CEC_IER_TXACKIE		(0x1u<<12)
#define	CEC_IER_TXERRIE		(0x1u<<11)
#define	CEC_IER_TXUDRIE		(0x1u<<10)
#define	CEC_IER_TXENDIE		(0x1u<<9)
#define	CEC_IER_TXBRIE		(0x1u<<8)
#define	CEC_IER_ARBLSTIE	(0x1u<<7)
#define	CEC_IER_RXACKIE		(0x1u<<6)
#define	CEC_IER_LBPEIE		(0x1u<<5)
#define	CEC_IER_SBPEIE		(0x1u<<4)
#define	CEC_IER_BREIE		(0x1u<<3)
#define	CEC_IER_RXOVRIE		(0x1u<<2)
#define	CEC_IER_RXENDIE		(0x1u<<1)
#define	CEC_IER_RXBRIE		(0x1u<<0)
