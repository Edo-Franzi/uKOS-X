/*
; stm32U5Gx_dma2d.
; ================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_dma2d equates.
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

// DMA2D address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	ISR;
	volatile	uint32_t	IFCR;
	volatile	uint32_t	FGMAR;
	volatile	uint32_t	FGOR;
	volatile	uint32_t	BGMAR;
	volatile	uint32_t	BGOR;
	volatile	uint32_t	FGPFCCR;
	volatile	uint32_t	FGCOLR;
	volatile	uint32_t	BGPFCCR;
	volatile	uint32_t	BGCOLR;
	volatile	uint32_t	FGCMAR;
	volatile	uint32_t	BGCMAR;
	volatile	uint32_t	OPFCCR;
	volatile	uint32_t	OCOLR;
	volatile	uint32_t	OMAR;
	volatile	uint32_t	OOR;
	volatile	uint32_t	NLR;
	volatile	uint32_t	LWR;
	volatile	uint32_t	AMTCR;
	volatile	uint32_t	RESERVED0[236];
	volatile	uint32_t	FGCLUT;
	volatile	uint32_t	RESERVED1[255];
	volatile	uint32_t	BGCLUT;
} DMA2D_TypeDef;

#if (defined(__cplusplus))
#define	DMA2D_NS	reinterpret_cast<DMA2D_TypeDef *>(0x4002B000u)
#define	DMA2D_S		reinterpret_cast<DMA2D_TypeDef *>(0x5002B000u)

#else
#define	DMA2D_NS	((DMA2D_TypeDef *)0x4002B000u)
#define	DMA2D_S		((DMA2D_TypeDef *)0x5002B000u)
#endif

// CR Configuration

#define	DMA2D_CR_START			(0x1u<<0)
#define	DMA2D_CR_SUSP			(0x1u<<1)
#define	DMA2D_CR_ABORT			(0x1u<<2)
#define	DMA2D_CR_LOM			(0x1u<<6)
#define	DMA2D_CR_TEIE			(0x1u<<8)
#define	DMA2D_CR_TCIE			(0x1u<<9)
#define	DMA2D_CR_TWIE			(0x1u<<10)
#define	DMA2D_CR_CAEIE			(0x1u<<11)
#define	DMA2D_CR_CTCIE			(0x1u<<12)
#define	DMA2D_CR_CEIE			(0x1u<<13)
#define	DMA2D_CR_MODE			(0x7u<<16)
#define	DMA2D_CR_MODE_0			(0x1u<<16)

// ISR Configuration

#define	DMA2D_ISR_TEIF			(0x1u<<0)
#define	DMA2D_ISR_TCIF			(0x1u<<1)
#define	DMA2D_ISR_TWIF			(0x1u<<2)
#define	DMA2D_ISR_CAEIF			(0x1u<<3)
#define	DMA2D_ISR_CTCIF			(0x1u<<4)
#define	DMA2D_ISR_CEIF			(0x1u<<5)

// IFCR Configuration

#define	DMA2D_IFCR_CTEIF		(0x1u<<0)
#define	DMA2D_IFCR_CTCIF		(0x1u<<1)
#define	DMA2D_IFCR_CTWIF		(0x1u<<2)
#define	DMA2D_IFCR_CAECIF		(0x1u<<3)
#define	DMA2D_IFCR_CCTCIF		(0x1u<<4)
#define	DMA2D_IFCR_CCEIF		(0x1u<<5)

// FGMAR Configuration

#define	DMA2D_FGMAR_MA			(0xFFFFFFFFu<<0)
#define	DMA2D_FGMAR_MA_0		(0x1u<<0)

// FGOR Configuration

#define	DMA2D_FGOR_LO			(0xFFFFu<<0)
#define	DMA2D_FGOR_LO_0			(0x1u<<0)

// BGMAR Configuration

#define	DMA2D_BGMAR_MA			(0xFFFFFFFFu<<0)
#define	DMA2D_BGMAR_MA_0		(0x1u<<0)

// BGOR Configuration

#define	DMA2D_BGOR_LO			(0xFFFFu<<0)
#define	DMA2D_BGOR_LO_0			(0x1u<<0)

// FGPFCCR Configuration

#define	DMA2D_FGPFCCR_CM		(0xFu<<0)
#define	DMA2D_FGPFCCR_CM_0		(0x1u<<0)
#define	DMA2D_FGPFCCR_CCM		(0x1u<<4)
#define	DMA2D_FGPFCCR_START		(0x1u<<5)
#define	DMA2D_FGPFCCR_CS		(0xFFu<<8)
#define	DMA2D_FGPFCCR_CS_0		(0x1u<<8)
#define	DMA2D_FGPFCCR_AM		(0x3u<<16)
#define	DMA2D_FGPFCCR_AM_0		(0x1u<<16)
#define	DMA2D_FGPFCCR_AI		(0x1u<<20)
#define	DMA2D_FGPFCCR_RBS		(0x1u<<21)
#define	DMA2D_FGPFCCR_ALPHA		(0xFFu<<24)
#define	DMA2D_FGPFCCR_ALPHA_0	(0x1u<<24)

// FGCOLR Configuration

#define	DMA2D_FGCOLR_BLUE		(0xFFu<<0)
#define	DMA2D_FGCOLR_BLUE_0		(0x1u<<0)
#define	DMA2D_FGCOLR_GREEN		(0xFFu<<8)
#define	DMA2D_FGCOLR_GREEN_0	(0x1u<<8)
#define	DMA2D_FGCOLR_RED		(0xFFu<<16)
#define	DMA2D_FGCOLR_RED_0		(0x1u<<16)

// BGPFCCR Configuration

#define	DMA2D_BGPFCCR_CM		(0xFu<<0)
#define	DMA2D_BGPFCCR_CM_0		(0x1u<<0)
#define	DMA2D_BGPFCCR_CCM		(0x1u<<4)
#define	DMA2D_BGPFCCR_START		(0x1u<<5)
#define	DMA2D_BGPFCCR_CS		(0xFFu<<8)
#define	DMA2D_BGPFCCR_CS_0		(0x1u<<8)
#define	DMA2D_BGPFCCR_AM		(0x3u<<16)
#define	DMA2D_BGPFCCR_AM_0		(0x1u<<16)
#define	DMA2D_BGPFCCR_AI		(0x1u<<20)
#define	DMA2D_BGPFCCR_RBS		(0x1u<<21)
#define	DMA2D_BGPFCCR_ALPHA		(0xFFu<<24)
#define	DMA2D_BGPFCCR_ALPHA_0	(0x1u<<24)

// BGCOLR Configuration

#define	DMA2D_BGCOLR_BLUE		(0xFFu<<0)
#define	DMA2D_BGCOLR_BLUE_0		(0x1u<<0)
#define	DMA2D_BGCOLR_GREEN		(0xFFu<<8)
#define	DMA2D_BGCOLR_GREEN_0	(0x1u<<8)
#define	DMA2D_BGCOLR_RED		(0xFFu<<16)
#define	DMA2D_BGCOLR_RED_0		(0x1u<<16)

// FGCMAR Configuration

#define	DMA2D_FGCMAR_MA			(0xFFFFFFFFu<<0)
#define	DMA2D_FGCMAR_MA_0		(0x1u<<0)

// BGCMAR Configuration

#define	DMA2D_BGCMAR_MA			(0xFFFFFFFFu<<0)
#define	DMA2D_BGCMAR_MA_0		(0x1u<<0)

// OPFCCR Configuration

#define	DMA2D_OPFCCR_CM			(0x7u<<0)
#define	DMA2D_OPFCCR_CM_0		(0x1u<<0)
#define	DMA2D_OPFCCR_SB			(0x1u<<9)
#define	DMA2D_OPFCCR_AI			(0x1u<<20)
#define	DMA2D_OPFCCR_RBS		(0x1u<<21)

// OCOLR Configuration

#define	DMA2D_OCOLR_BLUE		(0xFFu<<0)
#define	DMA2D_OCOLR_BLUE_0		(0x1u<<0)
#define	DMA2D_OCOLR_GREEN		(0xFFu<<8)
#define	DMA2D_OCOLR_GREEN_0		(0x1u<<8)
#define	DMA2D_OCOLR_RED			(0xFFu<<16)
#define	DMA2D_OCOLR_RED_0		(0x1u<<16)
#define	DMA2D_OCOLR_APLHA		(0xFFu<<24)
#define	DMA2D_OCOLR_APLHA_0		(0x1u<<24)

// OMAR Configuration

#define	DMA2D_OMAR_MA			(0xFFFFFFFFu<<0)
#define	DMA2D_OMAR_MA_0			(0x1u<<0)

// OOR Configuration

#define	DMA2D_OOR_LO			(0xFFFFu<<0)
#define	DMA2D_OOR_LO_0			(0x1u<<0)

// NLR Configuration

#define	DMA2D_NLR_NL			(0xFFFFu<<0)
#define	DMA2D_NLR_NL_0			(0x1u<<0)
#define	DMA2D_NLR_PL			(0x3FFFu<<16)
#define	DMA2D_NLR_PL_0			(0x1u<<16)

// LWR Configuration

#define	DMA2D_LWR_LW			(0xFFFFu<<0)
#define	DMA2D_LWR_LW_0			(0x1u<<0)

// AMTCR Configuration

#define	DMA2D_AMTCR_EN			(0x1u<<0)
#define	DMA2D_AMTCR_DT			(0xFFu<<8)
#define	DMA2D_AMTCR_DT_0		(0x1u<<8)

// FGCLUT Configuration

#define	DMA2D_FGCLUT_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT_BLUE_0		(0x1u<<0)
#define	DMA2D_FGCLUT_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT_GREEN_0	(0x1u<<8)
#define	DMA2D_FGCLUT_RED		(0xFFu<<16)
#define	DMA2D_FGCLUT_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT_APLHA		(0xFFu<<24)
#define	DMA2D_FGCLUT_APLHA_0	(0x1u<<24)

// BGCLUT Configuration

#define	DMA2D_BGCLUT_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT_BLUE_0		(0x1u<<0)
#define	DMA2D_BGCLUT_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT_GREEN_0	(0x1u<<8)
#define	DMA2D_BGCLUT_RED		(0xFFu<<16)
#define	DMA2D_BGCLUT_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT_APLHA		(0xFFu<<24)
#define	DMA2D_BGCLUT_APLHA_0	(0x1u<<24)
