/*
; stm32H743_bdma.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_bdma equates.
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

// BDMA address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	ISR;
	volatile	uint32_t	IFCR;
	volatile	uint32_t	CCR0;
	volatile	uint32_t	CNDTR0;
	volatile	uint32_t	CPAR0;
	volatile	uint32_t	CM0AR0;
	volatile	uint32_t	CM1AR0;
	volatile	uint32_t	CCR1;
	volatile	uint32_t	CNDTR1;
	volatile	uint32_t	CPAR1;
	volatile	uint32_t	CM0AR1;
	volatile	uint32_t	CM1AR1;
	volatile	uint32_t	CCR2;
	volatile	uint32_t	CNDTR2;
	volatile	uint32_t	CPAR2;
	volatile	uint32_t	CM0AR2;
	volatile	uint32_t	CM1AR2;
	volatile	uint32_t	CCR3;
	volatile	uint32_t	CNDTR3;
	volatile	uint32_t	CPAR3;
	volatile	uint32_t	CM0AR3;
	volatile	uint32_t	CM1AR3;
	volatile	uint32_t	CCR4;
	volatile	uint32_t	CNDTR4;
	volatile	uint32_t	CPAR4;
	volatile	uint32_t	CM0AR4;
	volatile	uint32_t	CM1AR4;
	volatile	uint32_t	CCR5;
	volatile	uint32_t	CNDTR5;
	volatile	uint32_t	CPAR5;
	volatile	uint32_t	CM0AR5;
	volatile	uint32_t	CM1AR5;
	volatile	uint32_t	CCR6;
	volatile	uint32_t	CNDTR6;
	volatile	uint32_t	CPAR6;
	volatile	uint32_t	CM0AR6;
	volatile	uint32_t	CM1AR6;
	volatile	uint32_t	CCR7;
	volatile	uint32_t	CNDTR7;
	volatile	uint32_t	CPAR7;
	volatile	uint32_t	CM0AR7;
	volatile	uint32_t	CM1AR7;
} BDMA_TypeDef;

#if (defined(__cplusplus))
#define	BDMA	reinterpret_cast<BDMA_TypeDef *>(0x58025400u)

#else
#define	BDMA	((BDMA_TypeDef *)0x58025400u)
#endif

// ISR Configuration

#define	BDMA_ISR_TEIF7			(0x1u<<31)
#define	BDMA_ISR_HTIF7			(0x1u<<30)
#define	BDMA_ISR_TCIF7			(0x1u<<29)
#define	BDMA_ISR_GIF7			(0x1u<<28)
#define	BDMA_ISR_TEIF6			(0x1u<<27)
#define	BDMA_ISR_HTIF6			(0x1u<<26)
#define	BDMA_ISR_TCIF6			(0x1u<<25)
#define	BDMA_ISR_GIF6			(0x1u<<24)
#define	BDMA_ISR_TEIF5			(0x1u<<23)
#define	BDMA_ISR_HTIF5			(0x1u<<22)
#define	BDMA_ISR_TCIF5			(0x1u<<21)
#define	BDMA_ISR_GIF5			(0x1u<<20)
#define	BDMA_ISR_TEIF4			(0x1u<<19)
#define	BDMA_ISR_HTIF4			(0x1u<<18)
#define	BDMA_ISR_TCIF4			(0x1u<<17)
#define	BDMA_ISR_GIF4			(0x1u<<16)
#define	BDMA_ISR_TEIF3			(0x1u<<15)
#define	BDMA_ISR_HTIF3			(0x1u<<14)
#define	BDMA_ISR_TCIF3			(0x1u<<13)
#define	BDMA_ISR_GIF3			(0x1u<<12)
#define	BDMA_ISR_TEIF2			(0x1u<<11)
#define	BDMA_ISR_HTIF2			(0x1u<<10)
#define	BDMA_ISR_TCIF2			(0x1u<<9)
#define	BDMA_ISR_GIF2			(0x1u<<8)
#define	BDMA_ISR_TEIF1			(0x1u<<7)
#define	BDMA_ISR_HTIF1			(0x1u<<6)
#define	BDMA_ISR_TCIF1			(0x1u<<5)
#define	BDMA_ISR_GIF1			(0x1u<<4)
#define	BDMA_ISR_TEIF0			(0x1u<<3)
#define	BDMA_ISR_HTIF0			(0x1u<<2)
#define	BDMA_ISR_TCIF0			(0x1u<<1)
#define	BDMA_ISR_GIF0			(0x1u<<0)
#define	BDMA_ISR_TEIF7_B_0X0	(0x0u<<31)
#define	BDMA_ISR_TEIF7_B_0X1	(0x1u<<31)
#define	BDMA_ISR_HTIF7_B_0X0	(0x0u<<30)
#define	BDMA_ISR_HTIF7_B_0X1	(0x1u<<30)
#define	BDMA_ISR_TCIF7_B_0X0	(0x0u<<29)
#define	BDMA_ISR_TCIF7_B_0X1	(0x1u<<29)
#define	BDMA_ISR_GIF7_B_0X0		(0x0u<<28)
#define	BDMA_ISR_GIF7_B_0X1		(0x1u<<28)
#define	BDMA_ISR_TEIF6_B_0X0	(0x0u<<27)
#define	BDMA_ISR_TEIF6_B_0X1	(0x1u<<27)
#define	BDMA_ISR_HTIF6_B_0X0	(0x0u<<26)
#define	BDMA_ISR_HTIF6_B_0X1	(0x1u<<26)
#define	BDMA_ISR_TCIF6_B_0X0	(0x0u<<25)
#define	BDMA_ISR_TCIF6_B_0X1	(0x1u<<25)
#define	BDMA_ISR_GIF6_B_0X0		(0x0u<<24)
#define	BDMA_ISR_GIF6_B_0X1		(0x1u<<24)
#define	BDMA_ISR_TEIF5_B_0X0	(0x0u<<23)
#define	BDMA_ISR_TEIF5_B_0X1	(0x1u<<23)
#define	BDMA_ISR_HTIF5_B_0X0	(0x0u<<22)
#define	BDMA_ISR_HTIF5_B_0X1	(0x1u<<22)
#define	BDMA_ISR_TCIF5_B_0X0	(0x0u<<21)
#define	BDMA_ISR_TCIF5_B_0X1	(0x1u<<21)
#define	BDMA_ISR_GIF5_B_0X0		(0x0u<<20)
#define	BDMA_ISR_GIF5_B_0X1		(0x1u<<20)
#define	BDMA_ISR_TEIF4_B_0X0	(0x0u<<19)
#define	BDMA_ISR_TEIF4_B_0X1	(0x1u<<19)
#define	BDMA_ISR_HTIF4_B_0X0	(0x0u<<18)
#define	BDMA_ISR_HTIF4_B_0X1	(0x1u<<18)
#define	BDMA_ISR_TCIF4_B_0X0	(0x0u<<17)
#define	BDMA_ISR_TCIF4_B_0X1	(0x1u<<17)
#define	BDMA_ISR_GIF4_B_0X0		(0x0u<<16)
#define	BDMA_ISR_GIF4_B_0X1		(0x1u<<16)
#define	BDMA_ISR_TEIF3_B_0X0	(0x0u<<15)
#define	BDMA_ISR_TEIF3_B_0X1	(0x1u<<15)
#define	BDMA_ISR_HTIF3_B_0X0	(0x0u<<14)
#define	BDMA_ISR_HTIF3_B_0X1	(0x1u<<14)
#define	BDMA_ISR_TCIF3_B_0X0	(0x0u<<13)
#define	BDMA_ISR_TCIF3_B_0X1	(0x1u<<13)
#define	BDMA_ISR_GIF3_B_0X0		(0x0u<<12)
#define	BDMA_ISR_GIF3_B_0X1		(0x1u<<12)
#define	BDMA_ISR_TEIF2_B_0X0	(0x0u<<11)
#define	BDMA_ISR_TEIF2_B_0X1	(0x1u<<11)
#define	BDMA_ISR_HTIF2_B_0X0	(0x0u<<10)
#define	BDMA_ISR_HTIF2_B_0X1	(0x1u<<10)
#define	BDMA_ISR_TCIF2_B_0X0	(0x0u<<9)
#define	BDMA_ISR_TCIF2_B_0X1	(0x1u<<9)
#define	BDMA_ISR_GIF2_B_0X0		(0x0u<<8)
#define	BDMA_ISR_GIF2_B_0X1		(0x1u<<8)
#define	BDMA_ISR_TEIF1_B_0X0	(0x0u<<7)
#define	BDMA_ISR_TEIF1_B_0X1	(0x1u<<7)
#define	BDMA_ISR_HTIF1_B_0X0	(0x0u<<6)
#define	BDMA_ISR_HTIF1_B_0X1	(0x1u<<6)
#define	BDMA_ISR_TCIF1_B_0X0	(0x0u<<5)
#define	BDMA_ISR_TCIF1_B_0X1	(0x1u<<5)
#define	BDMA_ISR_GIF1_B_0X0		(0x0u<<4)
#define	BDMA_ISR_GIF1_B_0X1		(0x1u<<4)
#define	BDMA_ISR_TEIF0_B_0X0	(0x0u<<3)
#define	BDMA_ISR_TEIF0_B_0X1	(0x1u<<3)
#define	BDMA_ISR_HTIF0_B_0X0	(0x0u<<2)
#define	BDMA_ISR_HTIF0_B_0X1	(0x1u<<2)
#define	BDMA_ISR_TCIF0_B_0X0	(0x0u<<1)
#define	BDMA_ISR_TCIF0_B_0X1	(0x1u<<1)
#define	BDMA_ISR_GIF0_B_0X0		(0x0u<<0)
#define	BDMA_ISR_GIF0_B_0X1		(0x1u<<0)

// IFCR Configuration

#define	BDMA_IFCR_CTEIF7		(0x1u<<31)
#define	BDMA_IFCR_CHTIF7		(0x1u<<30)
#define	BDMA_IFCR_CTCIF7		(0x1u<<29)
#define	BDMA_IFCR_CGIF7			(0x1u<<28)
#define	BDMA_IFCR_CTEIF6		(0x1u<<27)
#define	BDMA_IFCR_CHTIF6		(0x1u<<26)
#define	BDMA_IFCR_CTCIF6		(0x1u<<25)
#define	BDMA_IFCR_CGIF6			(0x1u<<24)
#define	BDMA_IFCR_CTEIF5		(0x1u<<23)
#define	BDMA_IFCR_CHTIF5		(0x1u<<22)
#define	BDMA_IFCR_CTCIF5		(0x1u<<21)
#define	BDMA_IFCR_CGIF5			(0x1u<<20)
#define	BDMA_IFCR_CTEIF4		(0x1u<<19)
#define	BDMA_IFCR_CHTIF4		(0x1u<<18)
#define	BDMA_IFCR_CTCIF4		(0x1u<<17)
#define	BDMA_IFCR_CGIF4			(0x1u<<16)
#define	BDMA_IFCR_CTEIF3		(0x1u<<15)
#define	BDMA_IFCR_CHTIF3		(0x1u<<14)
#define	BDMA_IFCR_CTCIF3		(0x1u<<13)
#define	BDMA_IFCR_CGIF3			(0x1u<<12)
#define	BDMA_IFCR_CTEIF2		(0x1u<<11)
#define	BDMA_IFCR_CHTIF2		(0x1u<<10)
#define	BDMA_IFCR_CTCIF2		(0x1u<<9)
#define	BDMA_IFCR_CGIF2			(0x1u<<8)
#define	BDMA_IFCR_CTEIF1		(0x1u<<7)
#define	BDMA_IFCR_CHTIF1		(0x1u<<6)
#define	BDMA_IFCR_CTCIF1		(0x1u<<5)
#define	BDMA_IFCR_CGIF1			(0x1u<<4)
#define	BDMA_IFCR_CTEIF0		(0x1u<<3)
#define	BDMA_IFCR_CHTIF0		(0x1u<<2)
#define	BDMA_IFCR_CTCIF0		(0x1u<<1)
#define	BDMA_IFCR_CGIF0			(0x1u<<0)

// CCR0 Configuration

#define	BDMA_CCR0_CT			(0x1u<<16)
#define	BDMA_CCR0_DBM			(0x1u<<15)
#define	BDMA_CCR0_MEM2MEM		(0x1u<<14)
#define	BDMA_CCR0_PL			(0x3u<<12)
#define	BDMA_CCR0_PL_0			(0x1u<<12)
#define	BDMA_CCR0_MSIZE			(0x3u<<10)
#define	BDMA_CCR0_MSIZE_0		(0x1u<<10)
#define	BDMA_CCR0_PSIZE			(0x3u<<8)
#define	BDMA_CCR0_PSIZE_0		(0x1u<<8)
#define	BDMA_CCR0_MINC			(0x1u<<7)
#define	BDMA_CCR0_PINC			(0x1u<<6)
#define	BDMA_CCR0_CIRC			(0x1u<<5)
#define	BDMA_CCR0_DIR			(0x1u<<4)
#define	BDMA_CCR0_TEIE			(0x1u<<3)
#define	BDMA_CCR0_HTIE			(0x1u<<2)
#define	BDMA_CCR0_TCIE			(0x1u<<1)
#define	BDMA_CCR0_EN			(0x1u<<0)
#define	BDMA_CCR0_CT_B_0X0		(0x0u<<16)
#define	BDMA_CCR0_CT_B_0X1		(0x1u<<16)
#define	BDMA_CCR0_DBM_B_0X0		(0x0u<<15)
#define	BDMA_CCR0_DBM_B_0X1		(0x1u<<15)
#define	BDMA_CCR0_MEM2MEM_B_0X0	(0x0u<<14)
#define	BDMA_CCR0_MEM2MEM_B_0X1	(0x1u<<14)
#define	BDMA_CCR0_PL_B_0X0		(0x0u<<12)
#define	BDMA_CCR0_PL_B_0X1		(0x1u<<12)
#define	BDMA_CCR0_PL_B_0X2		(0x2u<<12)
#define	BDMA_CCR0_PL_B_0X3		(0x3u<<12)
#define	BDMA_CCR0_MSIZE_B_0X0	(0x0u<<10)
#define	BDMA_CCR0_MSIZE_B_0X1	(0x1u<<10)
#define	BDMA_CCR0_MSIZE_B_0X2	(0x2u<<10)
#define	BDMA_CCR0_PSIZE_B_0X0	(0x0u<<8)
#define	BDMA_CCR0_PSIZE_B_0X1	(0x1u<<8)
#define	BDMA_CCR0_PSIZE_B_0X2	(0x2u<<8)
#define	BDMA_CCR0_MINC_B_0X0	(0x0u<<7)
#define	BDMA_CCR0_MINC_B_0X1	(0x1u<<7)
#define	BDMA_CCR0_PINC_B_0X0	(0x0u<<6)
#define	BDMA_CCR0_PINC_B_0X1	(0x1u<<6)
#define	BDMA_CCR0_CIRC_B_0X0	(0x0u<<5)
#define	BDMA_CCR0_CIRC_B_0X1	(0x1u<<5)
#define	BDMA_CCR0_DIR_B_0X0		(0x0u<<4)
#define	BDMA_CCR0_DIR_B_0X1		(0x1u<<4)
#define	BDMA_CCR0_TEIE_B_0X0	(0x0u<<3)
#define	BDMA_CCR0_TEIE_B_0X1	(0x1u<<3)
#define	BDMA_CCR0_HTIE_B_0X0	(0x0u<<2)
#define	BDMA_CCR0_HTIE_B_0X1	(0x1u<<2)
#define	BDMA_CCR0_TCIE_B_0X0	(0x0u<<1)
#define	BDMA_CCR0_TCIE_B_0X1	(0x1u<<1)
#define	BDMA_CCR0_EN_B_0X0		(0x0u<<0)
#define	BDMA_CCR0_EN_B_0X1		(0x1u<<0)

// CNDTR0 Configuration

#define	BDMA_CNDTR0_NDT			(0xFFFFu<<0)
#define	BDMA_CNDTR0_NDT_0		(0x1u<<0)

// CPAR0 Configuration

#define	BDMA_CPAR0_PA			(0xFFFFFFFFu<<0)
#define	BDMA_CPAR0_PA_0			(0x1u<<0)

// CM0AR0 Configuration

#define	BDMA_CM0AR0_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM0AR0_MA_0		(0x1u<<0)

// CM1AR0 Configuration

#define	BDMA_CM1AR0_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM1AR0_MA_0		(0x1u<<0)

// CCR1 Configuration

#define	BDMA_CCR1_CT			(0x1u<<16)
#define	BDMA_CCR1_DBM			(0x1u<<15)
#define	BDMA_CCR1_MEM2MEM		(0x1u<<14)
#define	BDMA_CCR1_PL			(0x3u<<12)
#define	BDMA_CCR1_PL_0			(0x1u<<12)
#define	BDMA_CCR1_MSIZE			(0x3u<<10)
#define	BDMA_CCR1_MSIZE_0		(0x1u<<10)
#define	BDMA_CCR1_PSIZE			(0x3u<<8)
#define	BDMA_CCR1_PSIZE_0		(0x1u<<8)
#define	BDMA_CCR1_MINC			(0x1u<<7)
#define	BDMA_CCR1_PINC			(0x1u<<6)
#define	BDMA_CCR1_CIRC			(0x1u<<5)
#define	BDMA_CCR1_DIR			(0x1u<<4)
#define	BDMA_CCR1_TEIE			(0x1u<<3)
#define	BDMA_CCR1_HTIE			(0x1u<<2)
#define	BDMA_CCR1_TCIE			(0x1u<<1)
#define	BDMA_CCR1_EN			(0x1u<<0)
#define	BDMA_CCR1_CT_B_0X0		(0x0u<<16)
#define	BDMA_CCR1_CT_B_0X1		(0x1u<<16)
#define	BDMA_CCR1_DBM_B_0X0		(0x0u<<15)
#define	BDMA_CCR1_DBM_B_0X1		(0x1u<<15)
#define	BDMA_CCR1_MEM2MEM_B_0X0	(0x0u<<14)
#define	BDMA_CCR1_MEM2MEM_B_0X1	(0x1u<<14)
#define	BDMA_CCR1_PL_B_0X0		(0x0u<<12)
#define	BDMA_CCR1_PL_B_0X1		(0x1u<<12)
#define	BDMA_CCR1_PL_B_0X2		(0x2u<<12)
#define	BDMA_CCR1_PL_B_0X3		(0x3u<<12)
#define	BDMA_CCR1_MSIZE_B_0X0	(0x0u<<10)
#define	BDMA_CCR1_MSIZE_B_0X1	(0x1u<<10)
#define	BDMA_CCR1_MSIZE_B_0X2	(0x2u<<10)
#define	BDMA_CCR1_PSIZE_B_0X0	(0x0u<<8)
#define	BDMA_CCR1_PSIZE_B_0X1	(0x1u<<8)
#define	BDMA_CCR1_PSIZE_B_0X2	(0x2u<<8)
#define	BDMA_CCR1_MINC_B_0X0	(0x0u<<7)
#define	BDMA_CCR1_MINC_B_0X1	(0x1u<<7)
#define	BDMA_CCR1_PINC_B_0X0	(0x0u<<6)
#define	BDMA_CCR1_PINC_B_0X1	(0x1u<<6)
#define	BDMA_CCR1_CIRC_B_0X0	(0x0u<<5)
#define	BDMA_CCR1_CIRC_B_0X1	(0x1u<<5)
#define	BDMA_CCR1_DIR_B_0X0		(0x0u<<4)
#define	BDMA_CCR1_DIR_B_0X1		(0x1u<<4)
#define	BDMA_CCR1_TEIE_B_0X0	(0x0u<<3)
#define	BDMA_CCR1_TEIE_B_0X1	(0x1u<<3)
#define	BDMA_CCR1_HTIE_B_0X0	(0x0u<<2)
#define	BDMA_CCR1_HTIE_B_0X1	(0x1u<<2)
#define	BDMA_CCR1_TCIE_B_0X0	(0x0u<<1)
#define	BDMA_CCR1_TCIE_B_0X1	(0x1u<<1)
#define	BDMA_CCR1_EN_B_0X0		(0x0u<<0)
#define	BDMA_CCR1_EN_B_0X1		(0x1u<<0)

// CNDTR1 Configuration

#define	BDMA_CNDTR1_NDT			(0xFFFFu<<0)
#define	BDMA_CNDTR1_NDT_0		(0x1u<<0)

// CPAR1 Configuration

#define	BDMA_CPAR1_PA			(0xFFFFFFFFu<<0)
#define	BDMA_CPAR1_PA_0			(0x1u<<0)

// CM0AR1 Configuration

#define	BDMA_CM0AR1_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM0AR1_MA_0		(0x1u<<0)

// CM1AR1 Configuration

#define	BDMA_CM1AR1_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM1AR1_MA_0		(0x1u<<0)

// CCR2 Configuration

#define	BDMA_CCR2_CT			(0x1u<<16)
#define	BDMA_CCR2_DBM			(0x1u<<15)
#define	BDMA_CCR2_MEM2MEM		(0x1u<<14)
#define	BDMA_CCR2_PL			(0x3u<<12)
#define	BDMA_CCR2_PL_0			(0x1u<<12)
#define	BDMA_CCR2_MSIZE			(0x3u<<10)
#define	BDMA_CCR2_MSIZE_0		(0x1u<<10)
#define	BDMA_CCR2_PSIZE			(0x3u<<8)
#define	BDMA_CCR2_PSIZE_0		(0x1u<<8)
#define	BDMA_CCR2_MINC			(0x1u<<7)
#define	BDMA_CCR2_PINC			(0x1u<<6)
#define	BDMA_CCR2_CIRC			(0x1u<<5)
#define	BDMA_CCR2_DIR			(0x1u<<4)
#define	BDMA_CCR2_TEIE			(0x1u<<3)
#define	BDMA_CCR2_HTIE			(0x1u<<2)
#define	BDMA_CCR2_TCIE			(0x1u<<1)
#define	BDMA_CCR2_EN			(0x1u<<0)
#define	BDMA_CCR2_CT_B_0X0		(0x0u<<16)
#define	BDMA_CCR2_CT_B_0X1		(0x1u<<16)
#define	BDMA_CCR2_DBM_B_0X0		(0x0u<<15)
#define	BDMA_CCR2_DBM_B_0X1		(0x1u<<15)
#define	BDMA_CCR2_MEM2MEM_B_0X0	(0x0u<<14)
#define	BDMA_CCR2_MEM2MEM_B_0X1	(0x1u<<14)
#define	BDMA_CCR2_PL_B_0X0		(0x0u<<12)
#define	BDMA_CCR2_PL_B_0X1		(0x1u<<12)
#define	BDMA_CCR2_PL_B_0X2		(0x2u<<12)
#define	BDMA_CCR2_PL_B_0X3		(0x3u<<12)
#define	BDMA_CCR2_MSIZE_B_0X0	(0x0u<<10)
#define	BDMA_CCR2_MSIZE_B_0X1	(0x1u<<10)
#define	BDMA_CCR2_MSIZE_B_0X2	(0x2u<<10)
#define	BDMA_CCR2_PSIZE_B_0X0	(0x0u<<8)
#define	BDMA_CCR2_PSIZE_B_0X1	(0x1u<<8)
#define	BDMA_CCR2_PSIZE_B_0X2	(0x2u<<8)
#define	BDMA_CCR2_MINC_B_0X0	(0x0u<<7)
#define	BDMA_CCR2_MINC_B_0X1	(0x1u<<7)
#define	BDMA_CCR2_PINC_B_0X0	(0x0u<<6)
#define	BDMA_CCR2_PINC_B_0X1	(0x1u<<6)
#define	BDMA_CCR2_CIRC_B_0X0	(0x0u<<5)
#define	BDMA_CCR2_CIRC_B_0X1	(0x1u<<5)
#define	BDMA_CCR2_DIR_B_0X0		(0x0u<<4)
#define	BDMA_CCR2_DIR_B_0X1		(0x1u<<4)
#define	BDMA_CCR2_TEIE_B_0X0	(0x0u<<3)
#define	BDMA_CCR2_TEIE_B_0X1	(0x1u<<3)
#define	BDMA_CCR2_HTIE_B_0X0	(0x0u<<2)
#define	BDMA_CCR2_HTIE_B_0X1	(0x1u<<2)
#define	BDMA_CCR2_TCIE_B_0X0	(0x0u<<1)
#define	BDMA_CCR2_TCIE_B_0X1	(0x1u<<1)
#define	BDMA_CCR2_EN_B_0X0		(0x0u<<0)
#define	BDMA_CCR2_EN_B_0X1		(0x1u<<0)

// CNDTR2 Configuration

#define	BDMA_CNDTR2_NDT			(0xFFFFu<<0)
#define	BDMA_CNDTR2_NDT_0		(0x1u<<0)

// CPAR2 Configuration

#define	BDMA_CPAR2_PA			(0xFFFFFFFFu<<0)
#define	BDMA_CPAR2_PA_0			(0x1u<<0)

// CM0AR2 Configuration

#define	BDMA_CM0AR2_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM0AR2_MA_0		(0x1u<<0)

// CM1AR2 Configuration

#define	BDMA_CM1AR2_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM1AR2_MA_0		(0x1u<<0)

// CCR3 Configuration

#define	BDMA_CCR3_CT			(0x1u<<16)
#define	BDMA_CCR3_DBM			(0x1u<<15)
#define	BDMA_CCR3_MEM2MEM		(0x1u<<14)
#define	BDMA_CCR3_PL			(0x3u<<12)
#define	BDMA_CCR3_PL_0			(0x1u<<12)
#define	BDMA_CCR3_MSIZE			(0x3u<<10)
#define	BDMA_CCR3_MSIZE_0		(0x1u<<10)
#define	BDMA_CCR3_PSIZE			(0x3u<<8)
#define	BDMA_CCR3_PSIZE_0		(0x1u<<8)
#define	BDMA_CCR3_MINC			(0x1u<<7)
#define	BDMA_CCR3_PINC			(0x1u<<6)
#define	BDMA_CCR3_CIRC			(0x1u<<5)
#define	BDMA_CCR3_DIR			(0x1u<<4)
#define	BDMA_CCR3_TEIE			(0x1u<<3)
#define	BDMA_CCR3_HTIE			(0x1u<<2)
#define	BDMA_CCR3_TCIE			(0x1u<<1)
#define	BDMA_CCR3_EN			(0x1u<<0)
#define	BDMA_CCR3_CT_B_0X0		(0x0u<<16)
#define	BDMA_CCR3_CT_B_0X1		(0x1u<<16)
#define	BDMA_CCR3_DBM_B_0X0		(0x0u<<15)
#define	BDMA_CCR3_DBM_B_0X1		(0x1u<<15)
#define	BDMA_CCR3_MEM2MEM_B_0X0	(0x0u<<14)
#define	BDMA_CCR3_MEM2MEM_B_0X1	(0x1u<<14)
#define	BDMA_CCR3_PL_B_0X0		(0x0u<<12)
#define	BDMA_CCR3_PL_B_0X1		(0x1u<<12)
#define	BDMA_CCR3_PL_B_0X2		(0x2u<<12)
#define	BDMA_CCR3_PL_B_0X3		(0x3u<<12)
#define	BDMA_CCR3_MSIZE_B_0X0	(0x0u<<10)
#define	BDMA_CCR3_MSIZE_B_0X1	(0x1u<<10)
#define	BDMA_CCR3_MSIZE_B_0X2	(0x2u<<10)
#define	BDMA_CCR3_PSIZE_B_0X0	(0x0u<<8)
#define	BDMA_CCR3_PSIZE_B_0X1	(0x1u<<8)
#define	BDMA_CCR3_PSIZE_B_0X2	(0x2u<<8)
#define	BDMA_CCR3_MINC_B_0X0	(0x0u<<7)
#define	BDMA_CCR3_MINC_B_0X1	(0x1u<<7)
#define	BDMA_CCR3_PINC_B_0X0	(0x0u<<6)
#define	BDMA_CCR3_PINC_B_0X1	(0x1u<<6)
#define	BDMA_CCR3_CIRC_B_0X0	(0x0u<<5)
#define	BDMA_CCR3_CIRC_B_0X1	(0x1u<<5)
#define	BDMA_CCR3_DIR_B_0X0		(0x0u<<4)
#define	BDMA_CCR3_DIR_B_0X1		(0x1u<<4)
#define	BDMA_CCR3_TEIE_B_0X0	(0x0u<<3)
#define	BDMA_CCR3_TEIE_B_0X1	(0x1u<<3)
#define	BDMA_CCR3_HTIE_B_0X0	(0x0u<<2)
#define	BDMA_CCR3_HTIE_B_0X1	(0x1u<<2)
#define	BDMA_CCR3_TCIE_B_0X0	(0x0u<<1)
#define	BDMA_CCR3_TCIE_B_0X1	(0x1u<<1)
#define	BDMA_CCR3_EN_B_0X0		(0x0u<<0)
#define	BDMA_CCR3_EN_B_0X1		(0x1u<<0)

// CNDTR3 Configuration

#define	BDMA_CNDTR3_NDT			(0xFFFFu<<0)
#define	BDMA_CNDTR3_NDT_0		(0x1u<<0)

// CPAR3 Configuration

#define	BDMA_CPAR3_PA			(0xFFFFFFFFu<<0)
#define	BDMA_CPAR3_PA_0			(0x1u<<0)

// CM0AR3 Configuration

#define	BDMA_CM0AR3_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM0AR3_MA_0		(0x1u<<0)

// CM1AR3 Configuration

#define	BDMA_CM1AR3_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM1AR3_MA_0		(0x1u<<0)

// CCR4 Configuration

#define	BDMA_CCR4_CT			(0x1u<<16)
#define	BDMA_CCR4_DBM			(0x1u<<15)
#define	BDMA_CCR4_MEM2MEM		(0x1u<<14)
#define	BDMA_CCR4_PL			(0x3u<<12)
#define	BDMA_CCR4_PL_0			(0x1u<<12)
#define	BDMA_CCR4_MSIZE			(0x3u<<10)
#define	BDMA_CCR4_MSIZE_0		(0x1u<<10)
#define	BDMA_CCR4_PSIZE			(0x3u<<8)
#define	BDMA_CCR4_PSIZE_0		(0x1u<<8)
#define	BDMA_CCR4_MINC			(0x1u<<7)
#define	BDMA_CCR4_PINC			(0x1u<<6)
#define	BDMA_CCR4_CIRC			(0x1u<<5)
#define	BDMA_CCR4_DIR			(0x1u<<4)
#define	BDMA_CCR4_TEIE			(0x1u<<3)
#define	BDMA_CCR4_HTIE			(0x1u<<2)
#define	BDMA_CCR4_TCIE			(0x1u<<1)
#define	BDMA_CCR4_EN			(0x1u<<0)
#define	BDMA_CCR4_CT_B_0X0		(0x0u<<16)
#define	BDMA_CCR4_CT_B_0X1		(0x1u<<16)
#define	BDMA_CCR4_DBM_B_0X0		(0x0u<<15)
#define	BDMA_CCR4_DBM_B_0X1		(0x1u<<15)
#define	BDMA_CCR4_MEM2MEM_B_0X0	(0x0u<<14)
#define	BDMA_CCR4_MEM2MEM_B_0X1	(0x1u<<14)
#define	BDMA_CCR4_PL_B_0X0		(0x0u<<12)
#define	BDMA_CCR4_PL_B_0X1		(0x1u<<12)
#define	BDMA_CCR4_PL_B_0X2		(0x2u<<12)
#define	BDMA_CCR4_PL_B_0X3		(0x3u<<12)
#define	BDMA_CCR4_MSIZE_B_0X0	(0x0u<<10)
#define	BDMA_CCR4_MSIZE_B_0X1	(0x1u<<10)
#define	BDMA_CCR4_MSIZE_B_0X2	(0x2u<<10)
#define	BDMA_CCR4_PSIZE_B_0X0	(0x0u<<8)
#define	BDMA_CCR4_PSIZE_B_0X1	(0x1u<<8)
#define	BDMA_CCR4_PSIZE_B_0X2	(0x2u<<8)
#define	BDMA_CCR4_MINC_B_0X0	(0x0u<<7)
#define	BDMA_CCR4_MINC_B_0X1	(0x1u<<7)
#define	BDMA_CCR4_PINC_B_0X0	(0x0u<<6)
#define	BDMA_CCR4_PINC_B_0X1	(0x1u<<6)
#define	BDMA_CCR4_CIRC_B_0X0	(0x0u<<5)
#define	BDMA_CCR4_CIRC_B_0X1	(0x1u<<5)
#define	BDMA_CCR4_DIR_B_0X0		(0x0u<<4)
#define	BDMA_CCR4_DIR_B_0X1		(0x1u<<4)
#define	BDMA_CCR4_TEIE_B_0X0	(0x0u<<3)
#define	BDMA_CCR4_TEIE_B_0X1	(0x1u<<3)
#define	BDMA_CCR4_HTIE_B_0X0	(0x0u<<2)
#define	BDMA_CCR4_HTIE_B_0X1	(0x1u<<2)
#define	BDMA_CCR4_TCIE_B_0X0	(0x0u<<1)
#define	BDMA_CCR4_TCIE_B_0X1	(0x1u<<1)
#define	BDMA_CCR4_EN_B_0X0		(0x0u<<0)
#define	BDMA_CCR4_EN_B_0X1		(0x1u<<0)

// CNDTR4 Configuration

#define	BDMA_CNDTR4_NDT			(0xFFFFu<<0)
#define	BDMA_CNDTR4_NDT_0		(0x1u<<0)

// CPAR4 Configuration

#define	BDMA_CPAR4_PA			(0xFFFFFFFFu<<0)
#define	BDMA_CPAR4_PA_0			(0x1u<<0)

// CM0AR4 Configuration

#define	BDMA_CM0AR4_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM0AR4_MA_0		(0x1u<<0)

// CM1AR4 Configuration

#define	BDMA_CM1AR4_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM1AR4_MA_0		(0x1u<<0)

// CCR5 Configuration

#define	BDMA_CCR5_CT			(0x1u<<16)
#define	BDMA_CCR5_DBM			(0x1u<<15)
#define	BDMA_CCR5_MEM2MEM		(0x1u<<14)
#define	BDMA_CCR5_PL			(0x3u<<12)
#define	BDMA_CCR5_PL_0			(0x1u<<12)
#define	BDMA_CCR5_MSIZE			(0x3u<<10)
#define	BDMA_CCR5_MSIZE_0		(0x1u<<10)
#define	BDMA_CCR5_PSIZE			(0x3u<<8)
#define	BDMA_CCR5_PSIZE_0		(0x1u<<8)
#define	BDMA_CCR5_MINC			(0x1u<<7)
#define	BDMA_CCR5_PINC			(0x1u<<6)
#define	BDMA_CCR5_CIRC			(0x1u<<5)
#define	BDMA_CCR5_DIR			(0x1u<<4)
#define	BDMA_CCR5_TEIE			(0x1u<<3)
#define	BDMA_CCR5_HTIE			(0x1u<<2)
#define	BDMA_CCR5_TCIE			(0x1u<<1)
#define	BDMA_CCR5_EN			(0x1u<<0)
#define	BDMA_CCR5_CT_B_0X0		(0x0u<<16)
#define	BDMA_CCR5_CT_B_0X1		(0x1u<<16)
#define	BDMA_CCR5_DBM_B_0X0		(0x0u<<15)
#define	BDMA_CCR5_DBM_B_0X1		(0x1u<<15)
#define	BDMA_CCR5_MEM2MEM_B_0X0	(0x0u<<14)
#define	BDMA_CCR5_MEM2MEM_B_0X1	(0x1u<<14)
#define	BDMA_CCR5_PL_B_0X0		(0x0u<<12)
#define	BDMA_CCR5_PL_B_0X1		(0x1u<<12)
#define	BDMA_CCR5_PL_B_0X2		(0x2u<<12)
#define	BDMA_CCR5_PL_B_0X3		(0x3u<<12)
#define	BDMA_CCR5_MSIZE_B_0X0	(0x0u<<10)
#define	BDMA_CCR5_MSIZE_B_0X1	(0x1u<<10)
#define	BDMA_CCR5_MSIZE_B_0X2	(0x2u<<10)
#define	BDMA_CCR5_PSIZE_B_0X0	(0x0u<<8)
#define	BDMA_CCR5_PSIZE_B_0X1	(0x1u<<8)
#define	BDMA_CCR5_PSIZE_B_0X2	(0x2u<<8)
#define	BDMA_CCR5_MINC_B_0X0	(0x0u<<7)
#define	BDMA_CCR5_MINC_B_0X1	(0x1u<<7)
#define	BDMA_CCR5_PINC_B_0X0	(0x0u<<6)
#define	BDMA_CCR5_PINC_B_0X1	(0x1u<<6)
#define	BDMA_CCR5_CIRC_B_0X0	(0x0u<<5)
#define	BDMA_CCR5_CIRC_B_0X1	(0x1u<<5)
#define	BDMA_CCR5_DIR_B_0X0		(0x0u<<4)
#define	BDMA_CCR5_DIR_B_0X1		(0x1u<<4)
#define	BDMA_CCR5_TEIE_B_0X0	(0x0u<<3)
#define	BDMA_CCR5_TEIE_B_0X1	(0x1u<<3)
#define	BDMA_CCR5_HTIE_B_0X0	(0x0u<<2)
#define	BDMA_CCR5_HTIE_B_0X1	(0x1u<<2)
#define	BDMA_CCR5_TCIE_B_0X0	(0x0u<<1)
#define	BDMA_CCR5_TCIE_B_0X1	(0x1u<<1)
#define	BDMA_CCR5_EN_B_0X0		(0x0u<<0)
#define	BDMA_CCR5_EN_B_0X1		(0x1u<<0)

// CNDTR5 Configuration

#define	BDMA_CNDTR5_NDT			(0xFFFFu<<0)
#define	BDMA_CNDTR5_NDT_0		(0x1u<<0)

// CPAR5 Configuration

#define	BDMA_CPAR5_PA			(0xFFFFFFFFu<<0)
#define	BDMA_CPAR5_PA_0			(0x1u<<0)

// CM0AR5 Configuration

#define	BDMA_CM0AR5_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM0AR5_MA_0		(0x1u<<0)

// CM1AR5 Configuration

#define	BDMA_CM1AR5_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM1AR5_MA_0		(0x1u<<0)

// CCR6 Configuration

#define	BDMA_CCR6_CT			(0x1u<<16)
#define	BDMA_CCR6_DBM			(0x1u<<15)
#define	BDMA_CCR6_MEM2MEM		(0x1u<<14)
#define	BDMA_CCR6_PL			(0x3u<<12)
#define	BDMA_CCR6_PL_0			(0x1u<<12)
#define	BDMA_CCR6_MSIZE			(0x3u<<10)
#define	BDMA_CCR6_MSIZE_0		(0x1u<<10)
#define	BDMA_CCR6_PSIZE			(0x3u<<8)
#define	BDMA_CCR6_PSIZE_0		(0x1u<<8)
#define	BDMA_CCR6_MINC			(0x1u<<7)
#define	BDMA_CCR6_PINC			(0x1u<<6)
#define	BDMA_CCR6_CIRC			(0x1u<<5)
#define	BDMA_CCR6_DIR			(0x1u<<4)
#define	BDMA_CCR6_TEIE			(0x1u<<3)
#define	BDMA_CCR6_HTIE			(0x1u<<2)
#define	BDMA_CCR6_TCIE			(0x1u<<1)
#define	BDMA_CCR6_EN			(0x1u<<0)
#define	BDMA_CCR6_CT_B_0X0		(0x0u<<16)
#define	BDMA_CCR6_CT_B_0X1		(0x1u<<16)
#define	BDMA_CCR6_DBM_B_0X0		(0x0u<<15)
#define	BDMA_CCR6_DBM_B_0X1		(0x1u<<15)
#define	BDMA_CCR6_MEM2MEM_B_0X0	(0x0u<<14)
#define	BDMA_CCR6_MEM2MEM_B_0X1	(0x1u<<14)
#define	BDMA_CCR6_PL_B_0X0		(0x0u<<12)
#define	BDMA_CCR6_PL_B_0X1		(0x1u<<12)
#define	BDMA_CCR6_PL_B_0X2		(0x2u<<12)
#define	BDMA_CCR6_PL_B_0X3		(0x3u<<12)
#define	BDMA_CCR6_MSIZE_B_0X0	(0x0u<<10)
#define	BDMA_CCR6_MSIZE_B_0X1	(0x1u<<10)
#define	BDMA_CCR6_MSIZE_B_0X2	(0x2u<<10)
#define	BDMA_CCR6_PSIZE_B_0X0	(0x0u<<8)
#define	BDMA_CCR6_PSIZE_B_0X1	(0x1u<<8)
#define	BDMA_CCR6_PSIZE_B_0X2	(0x2u<<8)
#define	BDMA_CCR6_MINC_B_0X0	(0x0u<<7)
#define	BDMA_CCR6_MINC_B_0X1	(0x1u<<7)
#define	BDMA_CCR6_PINC_B_0X0	(0x0u<<6)
#define	BDMA_CCR6_PINC_B_0X1	(0x1u<<6)
#define	BDMA_CCR6_CIRC_B_0X0	(0x0u<<5)
#define	BDMA_CCR6_CIRC_B_0X1	(0x1u<<5)
#define	BDMA_CCR6_DIR_B_0X0		(0x0u<<4)
#define	BDMA_CCR6_DIR_B_0X1		(0x1u<<4)
#define	BDMA_CCR6_TEIE_B_0X0	(0x0u<<3)
#define	BDMA_CCR6_TEIE_B_0X1	(0x1u<<3)
#define	BDMA_CCR6_HTIE_B_0X0	(0x0u<<2)
#define	BDMA_CCR6_HTIE_B_0X1	(0x1u<<2)
#define	BDMA_CCR6_TCIE_B_0X0	(0x0u<<1)
#define	BDMA_CCR6_TCIE_B_0X1	(0x1u<<1)
#define	BDMA_CCR6_EN_B_0X0		(0x0u<<0)
#define	BDMA_CCR6_EN_B_0X1		(0x1u<<0)

// CNDTR6 Configuration

#define	BDMA_CNDTR6_NDT			(0xFFFFu<<0)
#define	BDMA_CNDTR6_NDT_0		(0x1u<<0)

// CPAR6 Configuration

#define	BDMA_CPAR6_PA			(0xFFFFFFFFu<<0)
#define	BDMA_CPAR6_PA_0			(0x1u<<0)

// CM0AR6 Configuration

#define	BDMA_CM0AR6_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM0AR6_MA_0		(0x1u<<0)

// CM1AR6 Configuration

#define	BDMA_CM1AR6_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM1AR6_MA_0		(0x1u<<0)

// CCR7 Configuration

#define	BDMA_CCR7_CT			(0x1u<<16)
#define	BDMA_CCR7_DBM			(0x1u<<15)
#define	BDMA_CCR7_MEM2MEM		(0x1u<<14)
#define	BDMA_CCR7_PL			(0x3u<<12)
#define	BDMA_CCR7_PL_0			(0x1u<<12)
#define	BDMA_CCR7_MSIZE			(0x3u<<10)
#define	BDMA_CCR7_MSIZE_0		(0x1u<<10)
#define	BDMA_CCR7_PSIZE			(0x3u<<8)
#define	BDMA_CCR7_PSIZE_0		(0x1u<<8)
#define	BDMA_CCR7_MINC			(0x1u<<7)
#define	BDMA_CCR7_PINC			(0x1u<<6)
#define	BDMA_CCR7_CIRC			(0x1u<<5)
#define	BDMA_CCR7_DIR			(0x1u<<4)
#define	BDMA_CCR7_TEIE			(0x1u<<3)
#define	BDMA_CCR7_HTIE			(0x1u<<2)
#define	BDMA_CCR7_TCIE			(0x1u<<1)
#define	BDMA_CCR7_EN			(0x1u<<0)
#define	BDMA_CCR7_CT_B_0X0		(0x0u<<16)
#define	BDMA_CCR7_CT_B_0X1		(0x1u<<16)
#define	BDMA_CCR7_DBM_B_0X0		(0x0u<<15)
#define	BDMA_CCR7_DBM_B_0X1		(0x1u<<15)
#define	BDMA_CCR7_MEM2MEM_B_0X0	(0x0u<<14)
#define	BDMA_CCR7_MEM2MEM_B_0X1	(0x1u<<14)
#define	BDMA_CCR7_PL_B_0X0		(0x0u<<12)
#define	BDMA_CCR7_PL_B_0X1		(0x1u<<12)
#define	BDMA_CCR7_PL_B_0X2		(0x2u<<12)
#define	BDMA_CCR7_PL_B_0X3		(0x3u<<12)
#define	BDMA_CCR7_MSIZE_B_0X0	(0x0u<<10)
#define	BDMA_CCR7_MSIZE_B_0X1	(0x1u<<10)
#define	BDMA_CCR7_MSIZE_B_0X2	(0x2u<<10)
#define	BDMA_CCR7_PSIZE_B_0X0	(0x0u<<8)
#define	BDMA_CCR7_PSIZE_B_0X1	(0x1u<<8)
#define	BDMA_CCR7_PSIZE_B_0X2	(0x2u<<8)
#define	BDMA_CCR7_MINC_B_0X0	(0x0u<<7)
#define	BDMA_CCR7_MINC_B_0X1	(0x1u<<7)
#define	BDMA_CCR7_PINC_B_0X0	(0x0u<<6)
#define	BDMA_CCR7_PINC_B_0X1	(0x1u<<6)
#define	BDMA_CCR7_CIRC_B_0X0	(0x0u<<5)
#define	BDMA_CCR7_CIRC_B_0X1	(0x1u<<5)
#define	BDMA_CCR7_DIR_B_0X0		(0x0u<<4)
#define	BDMA_CCR7_DIR_B_0X1		(0x1u<<4)
#define	BDMA_CCR7_TEIE_B_0X0	(0x0u<<3)
#define	BDMA_CCR7_TEIE_B_0X1	(0x1u<<3)
#define	BDMA_CCR7_HTIE_B_0X0	(0x0u<<2)
#define	BDMA_CCR7_HTIE_B_0X1	(0x1u<<2)
#define	BDMA_CCR7_TCIE_B_0X0	(0x0u<<1)
#define	BDMA_CCR7_TCIE_B_0X1	(0x1u<<1)
#define	BDMA_CCR7_EN_B_0X0		(0x0u<<0)
#define	BDMA_CCR7_EN_B_0X1		(0x1u<<0)

// CNDTR7 Configuration

#define	BDMA_CNDTR7_NDT			(0xFFFFu<<0)
#define	BDMA_CNDTR7_NDT_0		(0x1u<<0)

// CPAR7 Configuration

#define	BDMA_CPAR7_PA			(0xFFFFFFFFu<<0)
#define	BDMA_CPAR7_PA_0			(0x1u<<0)

// CM0AR7 Configuration

#define	BDMA_CM0AR7_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM0AR7_MA_0		(0x1u<<0)

// CM1AR7 Configuration

#define	BDMA_CM1AR7_MA			(0xFFFFFFFFu<<0)
#define	BDMA_CM1AR7_MA_0		(0x1u<<0)
