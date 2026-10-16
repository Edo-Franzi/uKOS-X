/*
; stm32U5Gx_tsc.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_tsc equates.
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

// TSC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	IER;
	volatile	uint32_t	ICR;
	volatile	uint32_t	ISR;
	volatile	uint32_t	IOHCR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	IOASCR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	IOSCR;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	IOCCR;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	IOGCSR;
	volatile	uint32_t	IOG1CR;
	volatile	uint32_t	IOG2CR;
	volatile	uint32_t	IOG3CR;
	volatile	uint32_t	IOG4CR;
	volatile	uint32_t	IOG5CR;
	volatile	uint32_t	IOG6CR;
	volatile	uint32_t	IOG7CR;
	volatile	uint32_t	IOG8CR;
} TSC_TypeDef;

#if (defined(__cplusplus))
#define	TSC_NS	reinterpret_cast<TSC_TypeDef *>(0x40024000u)
#define	TSC_S	reinterpret_cast<TSC_TypeDef *>(0x50024000u)

#else
#define	TSC_NS	((TSC_TypeDef *)0x40024000u)
#define	TSC_S	((TSC_TypeDef *)0x50024000u)
#endif

// CR Configuration

#define	TSC_CR_TSCE			(0x1u<<0)
#define	TSC_CR_START		(0x1u<<1)
#define	TSC_CR_AM			(0x1u<<2)
#define	TSC_CR_SYNCPOL		(0x1u<<3)
#define	TSC_CR_IODEF		(0x1u<<4)
#define	TSC_CR_MCV			(0x7u<<5)
#define	TSC_CR_MCV_0		(0x1u<<5)
#define	TSC_CR_PGPSC		(0x7u<<12)
#define	TSC_CR_PGPSC_0		(0x1u<<12)
#define	TSC_CR_SSPSC		(0x1u<<15)
#define	TSC_CR_SSE			(0x1u<<16)
#define	TSC_CR_SSD			(0x7Fu<<17)
#define	TSC_CR_SSD_0		(0x1u<<17)
#define	TSC_CR_CTPL			(0xFu<<24)
#define	TSC_CR_CTPL_0		(0x1u<<24)
#define	TSC_CR_CTPH			(0xFu<<28)
#define	TSC_CR_CTPH_0		(0x1u<<28)

// IER Configuration

#define	TSC_IER_EOAIE		(0x1u<<0)
#define	TSC_IER_MCEIE		(0x1u<<1)

// ICR Configuration

#define	TSC_ICR_EOAIC		(0x1u<<0)
#define	TSC_ICR_MCEIC		(0x1u<<1)

// ISR Configuration

#define	TSC_ISR_EOAF		(0x1u<<0)
#define	TSC_ISR_MCEF		(0x1u<<1)

// IOHCR Configuration

#define	TSC_IOHCR_G1_IO1	(0x1u<<0)
#define	TSC_IOHCR_G1_IO2	(0x1u<<1)
#define	TSC_IOHCR_G1_IO3	(0x1u<<2)
#define	TSC_IOHCR_G1_IO4	(0x1u<<3)
#define	TSC_IOHCR_G2_IO1	(0x1u<<4)
#define	TSC_IOHCR_G2_IO2	(0x1u<<5)
#define	TSC_IOHCR_G2_IO3	(0x1u<<6)
#define	TSC_IOHCR_G2_IO4	(0x1u<<7)
#define	TSC_IOHCR_G3_IO1	(0x1u<<8)
#define	TSC_IOHCR_G3_IO2	(0x1u<<9)
#define	TSC_IOHCR_G3_IO3	(0x1u<<10)
#define	TSC_IOHCR_G3_IO4	(0x1u<<11)
#define	TSC_IOHCR_G4_IO1	(0x1u<<12)
#define	TSC_IOHCR_G4_IO2	(0x1u<<13)
#define	TSC_IOHCR_G4_IO3	(0x1u<<14)
#define	TSC_IOHCR_G4_IO4	(0x1u<<15)
#define	TSC_IOHCR_G5_IO1	(0x1u<<16)
#define	TSC_IOHCR_G5_IO2	(0x1u<<17)
#define	TSC_IOHCR_G5_IO3	(0x1u<<18)
#define	TSC_IOHCR_G5_IO4	(0x1u<<19)
#define	TSC_IOHCR_G6_IO1	(0x1u<<20)
#define	TSC_IOHCR_G6_IO2	(0x1u<<21)
#define	TSC_IOHCR_G6_IO3	(0x1u<<22)
#define	TSC_IOHCR_G6_IO4	(0x1u<<23)
#define	TSC_IOHCR_G7_IO1	(0x1u<<24)
#define	TSC_IOHCR_G7_IO2	(0x1u<<25)
#define	TSC_IOHCR_G7_IO3	(0x1u<<26)
#define	TSC_IOHCR_G7_IO4	(0x1u<<27)
#define	TSC_IOHCR_G8_IO1	(0x1u<<28)
#define	TSC_IOHCR_G8_IO2	(0x1u<<29)
#define	TSC_IOHCR_G8_IO3	(0x1u<<30)
#define	TSC_IOHCR_G8_IO4	(0x1u<<31)

// IOASCR Configuration

#define	TSC_IOASCR_G1_IO1	(0x1u<<0)
#define	TSC_IOASCR_G1_IO2	(0x1u<<1)
#define	TSC_IOASCR_G1_IO3	(0x1u<<2)
#define	TSC_IOASCR_G1_IO4	(0x1u<<3)
#define	TSC_IOASCR_G2_IO1	(0x1u<<4)
#define	TSC_IOASCR_G2_IO2	(0x1u<<5)
#define	TSC_IOASCR_G2_IO3	(0x1u<<6)
#define	TSC_IOASCR_G2_IO4	(0x1u<<7)
#define	TSC_IOASCR_G3_IO1	(0x1u<<8)
#define	TSC_IOASCR_G3_IO2	(0x1u<<9)
#define	TSC_IOASCR_G3_IO3	(0x1u<<10)
#define	TSC_IOASCR_G3_IO4	(0x1u<<11)
#define	TSC_IOASCR_G4_IO1	(0x1u<<12)
#define	TSC_IOASCR_G4_IO2	(0x1u<<13)
#define	TSC_IOASCR_G4_IO3	(0x1u<<14)
#define	TSC_IOASCR_G4_IO4	(0x1u<<15)
#define	TSC_IOASCR_G5_IO1	(0x1u<<16)
#define	TSC_IOASCR_G5_IO2	(0x1u<<17)
#define	TSC_IOASCR_G5_IO3	(0x1u<<18)
#define	TSC_IOASCR_G5_IO4	(0x1u<<19)
#define	TSC_IOASCR_G6_IO1	(0x1u<<20)
#define	TSC_IOASCR_G6_IO2	(0x1u<<21)
#define	TSC_IOASCR_G6_IO3	(0x1u<<22)
#define	TSC_IOASCR_G6_IO4	(0x1u<<23)
#define	TSC_IOASCR_G7_IO1	(0x1u<<24)
#define	TSC_IOASCR_G7_IO2	(0x1u<<25)
#define	TSC_IOASCR_G7_IO3	(0x1u<<26)
#define	TSC_IOASCR_G7_IO4	(0x1u<<27)
#define	TSC_IOASCR_G8_IO1	(0x1u<<28)
#define	TSC_IOASCR_G8_IO2	(0x1u<<29)
#define	TSC_IOASCR_G8_IO3	(0x1u<<30)
#define	TSC_IOASCR_G8_IO4	(0x1u<<31)

// IOSCR Configuration

#define	TSC_IOSCR_G1_IO1	(0x1u<<0)
#define	TSC_IOSCR_G1_IO2	(0x1u<<1)
#define	TSC_IOSCR_G1_IO3	(0x1u<<2)
#define	TSC_IOSCR_G1_IO4	(0x1u<<3)
#define	TSC_IOSCR_G2_IO1	(0x1u<<4)
#define	TSC_IOSCR_G2_IO2	(0x1u<<5)
#define	TSC_IOSCR_G2_IO3	(0x1u<<6)
#define	TSC_IOSCR_G2_IO4	(0x1u<<7)
#define	TSC_IOSCR_G3_IO1	(0x1u<<8)
#define	TSC_IOSCR_G3_IO2	(0x1u<<9)
#define	TSC_IOSCR_G3_IO3	(0x1u<<10)
#define	TSC_IOSCR_G3_IO4	(0x1u<<11)
#define	TSC_IOSCR_G4_IO1	(0x1u<<12)
#define	TSC_IOSCR_G4_IO2	(0x1u<<13)
#define	TSC_IOSCR_G4_IO3	(0x1u<<14)
#define	TSC_IOSCR_G4_IO4	(0x1u<<15)
#define	TSC_IOSCR_G5_IO1	(0x1u<<16)
#define	TSC_IOSCR_G5_IO2	(0x1u<<17)
#define	TSC_IOSCR_G5_IO3	(0x1u<<18)
#define	TSC_IOSCR_G5_IO4	(0x1u<<19)
#define	TSC_IOSCR_G6_IO1	(0x1u<<20)
#define	TSC_IOSCR_G6_IO2	(0x1u<<21)
#define	TSC_IOSCR_G6_IO3	(0x1u<<22)
#define	TSC_IOSCR_G6_IO4	(0x1u<<23)
#define	TSC_IOSCR_G7_IO1	(0x1u<<24)
#define	TSC_IOSCR_G7_IO2	(0x1u<<25)
#define	TSC_IOSCR_G7_IO3	(0x1u<<26)
#define	TSC_IOSCR_G7_IO4	(0x1u<<27)
#define	TSC_IOSCR_G8_IO1	(0x1u<<28)
#define	TSC_IOSCR_G8_IO2	(0x1u<<29)
#define	TSC_IOSCR_G8_IO3	(0x1u<<30)
#define	TSC_IOSCR_G8_IO4	(0x1u<<31)

// IOCCR Configuration

#define	TSC_IOCCR_G1_IO1	(0x1u<<0)
#define	TSC_IOCCR_G1_IO2	(0x1u<<1)
#define	TSC_IOCCR_G1_IO3	(0x1u<<2)
#define	TSC_IOCCR_G1_IO4	(0x1u<<3)
#define	TSC_IOCCR_G2_IO1	(0x1u<<4)
#define	TSC_IOCCR_G2_IO2	(0x1u<<5)
#define	TSC_IOCCR_G2_IO3	(0x1u<<6)
#define	TSC_IOCCR_G2_IO4	(0x1u<<7)
#define	TSC_IOCCR_G3_IO1	(0x1u<<8)
#define	TSC_IOCCR_G3_IO2	(0x1u<<9)
#define	TSC_IOCCR_G3_IO3	(0x1u<<10)
#define	TSC_IOCCR_G3_IO4	(0x1u<<11)
#define	TSC_IOCCR_G4_IO1	(0x1u<<12)
#define	TSC_IOCCR_G4_IO2	(0x1u<<13)
#define	TSC_IOCCR_G4_IO3	(0x1u<<14)
#define	TSC_IOCCR_G4_IO4	(0x1u<<15)
#define	TSC_IOCCR_G5_IO1	(0x1u<<16)
#define	TSC_IOCCR_G5_IO2	(0x1u<<17)
#define	TSC_IOCCR_G5_IO3	(0x1u<<18)
#define	TSC_IOCCR_G5_IO4	(0x1u<<19)
#define	TSC_IOCCR_G6_IO1	(0x1u<<20)
#define	TSC_IOCCR_G6_IO2	(0x1u<<21)
#define	TSC_IOCCR_G6_IO3	(0x1u<<22)
#define	TSC_IOCCR_G6_IO4	(0x1u<<23)
#define	TSC_IOCCR_G7_IO1	(0x1u<<24)
#define	TSC_IOCCR_G7_IO2	(0x1u<<25)
#define	TSC_IOCCR_G7_IO3	(0x1u<<26)
#define	TSC_IOCCR_G7_IO4	(0x1u<<27)
#define	TSC_IOCCR_G8_IO1	(0x1u<<28)
#define	TSC_IOCCR_G8_IO2	(0x1u<<29)
#define	TSC_IOCCR_G8_IO3	(0x1u<<30)
#define	TSC_IOCCR_G8_IO4	(0x1u<<31)

// IOGCSR Configuration

#define	TSC_IOGCSR_G1E		(0x1u<<0)
#define	TSC_IOGCSR_G2E		(0x1u<<1)
#define	TSC_IOGCSR_G3E		(0x1u<<2)
#define	TSC_IOGCSR_G4E		(0x1u<<3)
#define	TSC_IOGCSR_G5E		(0x1u<<4)
#define	TSC_IOGCSR_G6E		(0x1u<<5)
#define	TSC_IOGCSR_G7E		(0x1u<<6)
#define	TSC_IOGCSR_G8E		(0x1u<<7)
#define	TSC_IOGCSR_G1S		(0x1u<<16)
#define	TSC_IOGCSR_G2S		(0x1u<<17)
#define	TSC_IOGCSR_G3S		(0x1u<<18)
#define	TSC_IOGCSR_G4S		(0x1u<<19)
#define	TSC_IOGCSR_G5S		(0x1u<<20)
#define	TSC_IOGCSR_G6S		(0x1u<<21)
#define	TSC_IOGCSR_G7S		(0x1u<<22)
#define	TSC_IOGCSR_G8S		(0x1u<<23)

// IOG1CR Configuration

#define	TSC_IOG1CR_CNT		(0x3FFFu<<0)
#define	TSC_IOG1CR_CNT_0	(0x1u<<0)

// IOG2CR Configuration

#define	TSC_IOG2CR_CNT		(0x3FFFu<<0)
#define	TSC_IOG2CR_CNT_0	(0x1u<<0)

// IOG3CR Configuration

#define	TSC_IOG3CR_CNT		(0x3FFFu<<0)
#define	TSC_IOG3CR_CNT_0	(0x1u<<0)

// IOG4CR Configuration

#define	TSC_IOG4CR_CNT		(0x3FFFu<<0)
#define	TSC_IOG4CR_CNT_0	(0x1u<<0)

// IOG5CR Configuration

#define	TSC_IOG5CR_CNT		(0x3FFFu<<0)
#define	TSC_IOG5CR_CNT_0	(0x1u<<0)

// IOG6CR Configuration

#define	TSC_IOG6CR_CNT		(0x3FFFu<<0)
#define	TSC_IOG6CR_CNT_0	(0x1u<<0)

// IOG7CR Configuration

#define	TSC_IOG7CR_CNT		(0x3FFFu<<0)
#define	TSC_IOG7CR_CNT_0	(0x1u<<0)

// IOG8CR Configuration

#define	TSC_IOG8CR_CNT		(0x3FFFu<<0)
#define	TSC_IOG8CR_CNT_0	(0x1u<<0)
