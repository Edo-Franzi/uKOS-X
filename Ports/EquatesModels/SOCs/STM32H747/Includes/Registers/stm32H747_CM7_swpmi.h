/*
; stm32H747_CM7_swpmi.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM7_swpmi equates.
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

// SWPMI address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	BRR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	IER;
	volatile	uint32_t	RFL;
	volatile	uint32_t	TDR;
	volatile	uint32_t	RDR;
	volatile	uint32_t	OR;
} SWPMI_TypeDef;

#if (defined(__cplusplus))
#define	SWPMI	reinterpret_cast<SWPMI_TypeDef *>(0x40008800u)

#else
#define	SWPMI	((SWPMI_TypeDef *)0x40008800u)
#endif

// CR Configuration

#define	SWPMI_CR_SWPTEN		(0x1u<<11)
#define	SWPMI_CR_DEACT		(0x1u<<10)
#define	SWPMI_CR_SWPACT		(0x1u<<5)
#define	SWPMI_CR_LPBK		(0x1u<<4)
#define	SWPMI_CR_TXMODE		(0x1u<<3)
#define	SWPMI_CR_RXMODE		(0x1u<<2)
#define	SWPMI_CR_TXDMA		(0x1u<<1)
#define	SWPMI_CR_RXDMA		(0x1u<<0)

// BRR Configuration

#define	SWPMI_BRR_BR		(0xFFu<<0)
#define	SWPMI_BRR_BR_0		(0x1u<<0)

// ISR Configuration

#define	SWPMI_ISR_RDYF		(0x1u<<11)
#define	SWPMI_ISR_DEACTF	(0x1u<<10)
#define	SWPMI_ISR_SUSP		(0x1u<<9)
#define	SWPMI_ISR_SRF		(0x1u<<8)
#define	SWPMI_ISR_TCF		(0x1u<<7)
#define	SWPMI_ISR_TXE		(0x1u<<6)
#define	SWPMI_ISR_RXNE		(0x1u<<5)
#define	SWPMI_ISR_TXUNRF	(0x1u<<4)
#define	SWPMI_ISR_RXOVRF	(0x1u<<3)
#define	SWPMI_ISR_RXBERF	(0x1u<<2)
#define	SWPMI_ISR_TXBEF		(0x1u<<1)
#define	SWPMI_ISR_RXBFF		(0x1u<<0)

// ICR Configuration

#define	SWPMI_ICR_CRDYF		(0x1u<<11)
#define	SWPMI_ICR_CSRF		(0x1u<<8)
#define	SWPMI_ICR_CTCF		(0x1u<<7)
#define	SWPMI_ICR_CTXUNRF	(0x1u<<4)
#define	SWPMI_ICR_CRXOVRF	(0x1u<<3)
#define	SWPMI_ICR_CRXBERF	(0x1u<<2)
#define	SWPMI_ICR_CTXBEF	(0x1u<<1)
#define	SWPMI_ICR_CRXBFF	(0x1u<<0)

// IER Configuration

#define	SWPMI_IER_RDYIE		(0x1u<<11)
#define	SWPMI_IER_SRIE		(0x1u<<8)
#define	SWPMI_IER_TCIE		(0x1u<<7)
#define	SWPMI_IER_TIE		(0x1u<<6)
#define	SWPMI_IER_RIE		(0x1u<<5)
#define	SWPMI_IER_TXUNRIE	(0x1u<<4)
#define	SWPMI_IER_RXOVRIE	(0x1u<<3)
#define	SWPMI_IER_RXBERIE	(0x1u<<2)
#define	SWPMI_IER_TXBEIE	(0x1u<<1)
#define	SWPMI_IER_RXBFIE	(0x1u<<0)

// RFL Configuration

#define	SWPMI_RFL_RFL		(0x1Fu<<0)
#define	SWPMI_RFL_RFL_0		(0x1u<<0)

// TDR Configuration

#define	SWPMI_TDR_TD		(0xFFFFFFFFu<<0)
#define	SWPMI_TDR_TD_0		(0x1u<<0)

// RDR Configuration

#define	SWPMI_RDR_RD		(0xFFFFFFFFu<<0)
#define	SWPMI_RDR_RD_0		(0x1u<<0)

// OR Configuration

#define	SWPMI_OR_SWP_CLASS	(0x1u<<1)
#define	SWPMI_OR_SWP_TBYP	(0x1u<<0)
