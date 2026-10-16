/*
; stm32H743_dma.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_dma equates.
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

// DMA address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	LISR;
	volatile	uint32_t	HISR;
	volatile	uint32_t	LIFCR;
	volatile	uint32_t	HIFCR;
	volatile	uint32_t	S0CR;
	volatile	uint32_t	S0NDTR;
	volatile	uint32_t	S0PAR;
	volatile	uint32_t	S0M0AR;
	volatile	uint32_t	S0M1AR;
	volatile	uint32_t	S0FCR;
	volatile	uint32_t	S1CR;
	volatile	uint32_t	S1NDTR;
	volatile	uint32_t	S1PAR;
	volatile	uint32_t	S1M0AR;
	volatile	uint32_t	S1M1AR;
	volatile	uint32_t	S1FCR;
	volatile	uint32_t	S2CR;
	volatile	uint32_t	S2NDTR;
	volatile	uint32_t	S2PAR;
	volatile	uint32_t	S2M0AR;
	volatile	uint32_t	S2M1AR;
	volatile	uint32_t	S2FCR;
	volatile	uint32_t	S3CR;
	volatile	uint32_t	S3NDTR;
	volatile	uint32_t	S3PAR;
	volatile	uint32_t	S3M0AR;
	volatile	uint32_t	S3M1AR;
	volatile	uint32_t	S3FCR;
	volatile	uint32_t	S4CR;
	volatile	uint32_t	S4NDTR;
	volatile	uint32_t	S4PAR;
	volatile	uint32_t	S4M0AR;
	volatile	uint32_t	S4M1AR;
	volatile	uint32_t	S4FCR;
	volatile	uint32_t	S5CR;
	volatile	uint32_t	S5NDTR;
	volatile	uint32_t	S5PAR;
	volatile	uint32_t	S5M0AR;
	volatile	uint32_t	S5M1AR;
	volatile	uint32_t	S5FCR;
	volatile	uint32_t	S6CR;
	volatile	uint32_t	S6NDTR;
	volatile	uint32_t	S6PAR;
	volatile	uint32_t	S6M0AR;
	volatile	uint32_t	S6M1AR;
	volatile	uint32_t	S6FCR;
	volatile	uint32_t	S7CR;
	volatile	uint32_t	S7NDTR;
	volatile	uint32_t	S7PAR;
	volatile	uint32_t	S7M0AR;
	volatile	uint32_t	S7M1AR;
	volatile	uint32_t	S7FCR;
} DMA_TypeDef;

#if (defined(__cplusplus))
#define	DMA1	reinterpret_cast<DMA_TypeDef *>(0x40020000u)
#define	DMA2	reinterpret_cast<DMA_TypeDef *>(0x40020400u)

#else
#define	DMA1	((DMA_TypeDef *)0x40020000u)
#define	DMA2	((DMA_TypeDef *)0x40020400u)
#endif

// LISR Configuration

#define	DMA_LISR_FEIF0		(0x1u<<0)
#define	DMA_LISR_DMEIF0		(0x1u<<2)
#define	DMA_LISR_TEIF0		(0x1u<<3)
#define	DMA_LISR_HTIF0		(0x1u<<4)
#define	DMA_LISR_TCIF0		(0x1u<<5)
#define	DMA_LISR_FEIF1		(0x1u<<6)
#define	DMA_LISR_DMEIF1		(0x1u<<8)
#define	DMA_LISR_TEIF1		(0x1u<<9)
#define	DMA_LISR_HTIF1		(0x1u<<10)
#define	DMA_LISR_TCIF1		(0x1u<<11)
#define	DMA_LISR_FEIF2		(0x1u<<16)
#define	DMA_LISR_DMEIF2		(0x1u<<18)
#define	DMA_LISR_TEIF2		(0x1u<<19)
#define	DMA_LISR_HTIF2		(0x1u<<20)
#define	DMA_LISR_TCIF2		(0x1u<<21)
#define	DMA_LISR_FEIF3		(0x1u<<22)
#define	DMA_LISR_DMEIF3		(0x1u<<24)
#define	DMA_LISR_TEIF3		(0x1u<<25)
#define	DMA_LISR_HTIF3		(0x1u<<26)
#define	DMA_LISR_TCIF3		(0x1u<<27)

// HISR Configuration

#define	DMA_HISR_FEIF4		(0x1u<<0)
#define	DMA_HISR_DMEIF4		(0x1u<<2)
#define	DMA_HISR_TEIF4		(0x1u<<3)
#define	DMA_HISR_HTIF4		(0x1u<<4)
#define	DMA_HISR_TCIF4		(0x1u<<5)
#define	DMA_HISR_FEIF5		(0x1u<<6)
#define	DMA_HISR_DMEIF5		(0x1u<<8)
#define	DMA_HISR_TEIF5		(0x1u<<9)
#define	DMA_HISR_HTIF5		(0x1u<<10)
#define	DMA_HISR_TCIF5		(0x1u<<11)
#define	DMA_HISR_FEIF6		(0x1u<<16)
#define	DMA_HISR_DMEIF6		(0x1u<<18)
#define	DMA_HISR_TEIF6		(0x1u<<19)
#define	DMA_HISR_HTIF6		(0x1u<<20)
#define	DMA_HISR_TCIF6		(0x1u<<21)
#define	DMA_HISR_FEIF7		(0x1u<<22)
#define	DMA_HISR_DMEIF7		(0x1u<<24)
#define	DMA_HISR_TEIF7		(0x1u<<25)
#define	DMA_HISR_HTIF7		(0x1u<<26)
#define	DMA_HISR_TCIF7		(0x1u<<27)

// LIFCR Configuration

#define	DMA_LIFCR_CFEIF0	(0x1u<<0)
#define	DMA_LIFCR_CDMEIF0	(0x1u<<2)
#define	DMA_LIFCR_CTEIF0	(0x1u<<3)
#define	DMA_LIFCR_CHTIF0	(0x1u<<4)
#define	DMA_LIFCR_CTCIF0	(0x1u<<5)
#define	DMA_LIFCR_CFEIF1	(0x1u<<6)
#define	DMA_LIFCR_CDMEIF1	(0x1u<<8)
#define	DMA_LIFCR_CTEIF1	(0x1u<<9)
#define	DMA_LIFCR_CHTIF1	(0x1u<<10)
#define	DMA_LIFCR_CTCIF1	(0x1u<<11)
#define	DMA_LIFCR_CFEIF2	(0x1u<<16)
#define	DMA_LIFCR_CDMEIF2	(0x1u<<18)
#define	DMA_LIFCR_CTEIF2	(0x1u<<19)
#define	DMA_LIFCR_CHTIF2	(0x1u<<20)
#define	DMA_LIFCR_CTCIF2	(0x1u<<21)
#define	DMA_LIFCR_CFEIF3	(0x1u<<22)
#define	DMA_LIFCR_CDMEIF3	(0x1u<<24)
#define	DMA_LIFCR_CTEIF3	(0x1u<<25)
#define	DMA_LIFCR_CHTIF3	(0x1u<<26)
#define	DMA_LIFCR_CTCIF3	(0x1u<<27)

// HIFCR Configuration

#define	DMA_HIFCR_CFEIF4	(0x1u<<0)
#define	DMA_HIFCR_CDMEIF4	(0x1u<<2)
#define	DMA_HIFCR_CTEIF4	(0x1u<<3)
#define	DMA_HIFCR_CHTIF4	(0x1u<<4)
#define	DMA_HIFCR_CTCIF4	(0x1u<<5)
#define	DMA_HIFCR_CFEIF5	(0x1u<<6)
#define	DMA_HIFCR_CDMEIF5	(0x1u<<8)
#define	DMA_HIFCR_CTEIF5	(0x1u<<9)
#define	DMA_HIFCR_CHTIF5	(0x1u<<10)
#define	DMA_HIFCR_CTCIF5	(0x1u<<11)
#define	DMA_HIFCR_CFEIF6	(0x1u<<16)
#define	DMA_HIFCR_CDMEIF6	(0x1u<<18)
#define	DMA_HIFCR_CTEIF6	(0x1u<<19)
#define	DMA_HIFCR_CHTIF6	(0x1u<<20)
#define	DMA_HIFCR_CTCIF6	(0x1u<<21)
#define	DMA_HIFCR_CFEIF7	(0x1u<<22)
#define	DMA_HIFCR_CDMEIF7	(0x1u<<24)
#define	DMA_HIFCR_CTEIF7	(0x1u<<25)
#define	DMA_HIFCR_CHTIF7	(0x1u<<26)
#define	DMA_HIFCR_CTCIF7	(0x1u<<27)

// S0CR Configuration

#define	DMA_S0CR_EN			(0x1u<<0)
#define	DMA_S0CR_DMEIE		(0x1u<<1)
#define	DMA_S0CR_TEIE		(0x1u<<2)
#define	DMA_S0CR_HTIE		(0x1u<<3)
#define	DMA_S0CR_TCIE		(0x1u<<4)
#define	DMA_S0CR_PFCTRL		(0x1u<<5)
#define	DMA_S0CR_DIR		(0x3u<<6)
#define	DMA_S0CR_DIR_0		(0x1u<<6)
#define	DMA_S0CR_CIRC		(0x1u<<8)
#define	DMA_S0CR_PINC		(0x1u<<9)
#define	DMA_S0CR_MINC		(0x1u<<10)
#define	DMA_S0CR_PSIZE		(0x3u<<11)
#define	DMA_S0CR_PSIZE_0	(0x1u<<11)
#define	DMA_S0CR_MSIZE		(0x3u<<13)
#define	DMA_S0CR_MSIZE_0	(0x1u<<13)
#define	DMA_S0CR_PINCOS		(0x1u<<15)
#define	DMA_S0CR_PL			(0x3u<<16)
#define	DMA_S0CR_PL_0		(0x1u<<16)
#define	DMA_S0CR_DBM		(0x1u<<18)
#define	DMA_S0CR_CT			(0x1u<<19)
#define	DMA_S0CR_PBURST		(0x3u<<21)
#define	DMA_S0CR_PBURST_0	(0x1u<<21)
#define	DMA_S0CR_MBURST		(0x3u<<23)
#define	DMA_S0CR_MBURST_0	(0x1u<<23)

// S0NDTR Configuration

#define	DMA_S0NDTR_NDT		(0xFFFFu<<0)
#define	DMA_S0NDTR_NDT_0	(0x1u<<0)

// S0PAR Configuration

#define	DMA_S0PAR_PA		(0xFFFFFFFFu<<0)
#define	DMA_S0PAR_PA_0		(0x1u<<0)

// S0M0AR Configuration

#define	DMA_S0M0AR_M0A		(0xFFFFFFFFu<<0)
#define	DMA_S0M0AR_M0A_0	(0x1u<<0)

// S0M1AR Configuration

#define	DMA_S0M1AR_M1A		(0xFFFFFFFFu<<0)
#define	DMA_S0M1AR_M1A_0	(0x1u<<0)

// S0FCR Configuration

#define	DMA_S0FCR_FTH		(0x3u<<0)
#define	DMA_S0FCR_FTH_0		(0x1u<<0)
#define	DMA_S0FCR_DMDIS		(0x1u<<2)
#define	DMA_S0FCR_FS		(0x7u<<3)
#define	DMA_S0FCR_FS_0		(0x1u<<3)
#define	DMA_S0FCR_FEIE		(0x1u<<7)

// S1CR Configuration

#define	DMA_S1CR_EN			(0x1u<<0)
#define	DMA_S1CR_DMEIE		(0x1u<<1)
#define	DMA_S1CR_TEIE		(0x1u<<2)
#define	DMA_S1CR_HTIE		(0x1u<<3)
#define	DMA_S1CR_TCIE		(0x1u<<4)
#define	DMA_S1CR_PFCTRL		(0x1u<<5)
#define	DMA_S1CR_DIR		(0x3u<<6)
#define	DMA_S1CR_DIR_0		(0x1u<<6)
#define	DMA_S1CR_CIRC		(0x1u<<8)
#define	DMA_S1CR_PINC		(0x1u<<9)
#define	DMA_S1CR_MINC		(0x1u<<10)
#define	DMA_S1CR_PSIZE		(0x3u<<11)
#define	DMA_S1CR_PSIZE_0	(0x1u<<11)
#define	DMA_S1CR_MSIZE		(0x3u<<13)
#define	DMA_S1CR_MSIZE_0	(0x1u<<13)
#define	DMA_S1CR_PINCOS		(0x1u<<15)
#define	DMA_S1CR_PL			(0x3u<<16)
#define	DMA_S1CR_PL_0		(0x1u<<16)
#define	DMA_S1CR_DBM		(0x1u<<18)
#define	DMA_S1CR_CT			(0x1u<<19)
#define	DMA_S1CR_ACK		(0x1u<<20)
#define	DMA_S1CR_PBURST		(0x3u<<21)
#define	DMA_S1CR_PBURST_0	(0x1u<<21)
#define	DMA_S1CR_MBURST		(0x3u<<23)
#define	DMA_S1CR_MBURST_0	(0x1u<<23)

// S1NDTR Configuration

#define	DMA_S1NDTR_NDT		(0xFFFFu<<0)
#define	DMA_S1NDTR_NDT_0	(0x1u<<0)

// S1PAR Configuration

#define	DMA_S1PAR_PA		(0xFFFFFFFFu<<0)
#define	DMA_S1PAR_PA_0		(0x1u<<0)

// S1M0AR Configuration

#define	DMA_S1M0AR_M0A		(0xFFFFFFFFu<<0)
#define	DMA_S1M0AR_M0A_0	(0x1u<<0)

// S1M1AR Configuration

#define	DMA_S1M1AR_M1A		(0xFFFFFFFFu<<0)
#define	DMA_S1M1AR_M1A_0	(0x1u<<0)

// S1FCR Configuration

#define	DMA_S1FCR_FTH		(0x3u<<0)
#define	DMA_S1FCR_FTH_0		(0x1u<<0)
#define	DMA_S1FCR_DMDIS		(0x1u<<2)
#define	DMA_S1FCR_FS		(0x7u<<3)
#define	DMA_S1FCR_FS_0		(0x1u<<3)
#define	DMA_S1FCR_FEIE		(0x1u<<7)

// S2CR Configuration

#define	DMA_S2CR_EN			(0x1u<<0)
#define	DMA_S2CR_DMEIE		(0x1u<<1)
#define	DMA_S2CR_TEIE		(0x1u<<2)
#define	DMA_S2CR_HTIE		(0x1u<<3)
#define	DMA_S2CR_TCIE		(0x1u<<4)
#define	DMA_S2CR_PFCTRL		(0x1u<<5)
#define	DMA_S2CR_DIR		(0x3u<<6)
#define	DMA_S2CR_DIR_0		(0x1u<<6)
#define	DMA_S2CR_CIRC		(0x1u<<8)
#define	DMA_S2CR_PINC		(0x1u<<9)
#define	DMA_S2CR_MINC		(0x1u<<10)
#define	DMA_S2CR_PSIZE		(0x3u<<11)
#define	DMA_S2CR_PSIZE_0	(0x1u<<11)
#define	DMA_S2CR_MSIZE		(0x3u<<13)
#define	DMA_S2CR_MSIZE_0	(0x1u<<13)
#define	DMA_S2CR_PINCOS		(0x1u<<15)
#define	DMA_S2CR_PL			(0x3u<<16)
#define	DMA_S2CR_PL_0		(0x1u<<16)
#define	DMA_S2CR_DBM		(0x1u<<18)
#define	DMA_S2CR_CT			(0x1u<<19)
#define	DMA_S2CR_ACK		(0x1u<<20)
#define	DMA_S2CR_PBURST		(0x3u<<21)
#define	DMA_S2CR_PBURST_0	(0x1u<<21)
#define	DMA_S2CR_MBURST		(0x3u<<23)
#define	DMA_S2CR_MBURST_0	(0x1u<<23)

// S2NDTR Configuration

#define	DMA_S2NDTR_NDT		(0xFFFFu<<0)
#define	DMA_S2NDTR_NDT_0	(0x1u<<0)

// S2PAR Configuration

#define	DMA_S2PAR_PA		(0xFFFFFFFFu<<0)
#define	DMA_S2PAR_PA_0		(0x1u<<0)

// S2M0AR Configuration

#define	DMA_S2M0AR_M0A		(0xFFFFFFFFu<<0)
#define	DMA_S2M0AR_M0A_0	(0x1u<<0)

// S2M1AR Configuration

#define	DMA_S2M1AR_M1A		(0xFFFFFFFFu<<0)
#define	DMA_S2M1AR_M1A_0	(0x1u<<0)

// S2FCR Configuration

#define	DMA_S2FCR_FTH		(0x3u<<0)
#define	DMA_S2FCR_FTH_0		(0x1u<<0)
#define	DMA_S2FCR_DMDIS		(0x1u<<2)
#define	DMA_S2FCR_FS		(0x7u<<3)
#define	DMA_S2FCR_FS_0		(0x1u<<3)
#define	DMA_S2FCR_FEIE		(0x1u<<7)

// S3CR Configuration

#define	DMA_S3CR_EN			(0x1u<<0)
#define	DMA_S3CR_DMEIE		(0x1u<<1)
#define	DMA_S3CR_TEIE		(0x1u<<2)
#define	DMA_S3CR_HTIE		(0x1u<<3)
#define	DMA_S3CR_TCIE		(0x1u<<4)
#define	DMA_S3CR_PFCTRL		(0x1u<<5)
#define	DMA_S3CR_DIR		(0x3u<<6)
#define	DMA_S3CR_DIR_0		(0x1u<<6)
#define	DMA_S3CR_CIRC		(0x1u<<8)
#define	DMA_S3CR_PINC		(0x1u<<9)
#define	DMA_S3CR_MINC		(0x1u<<10)
#define	DMA_S3CR_PSIZE		(0x3u<<11)
#define	DMA_S3CR_PSIZE_0	(0x1u<<11)
#define	DMA_S3CR_MSIZE		(0x3u<<13)
#define	DMA_S3CR_MSIZE_0	(0x1u<<13)
#define	DMA_S3CR_PINCOS		(0x1u<<15)
#define	DMA_S3CR_PL			(0x3u<<16)
#define	DMA_S3CR_PL_0		(0x1u<<16)
#define	DMA_S3CR_DBM		(0x1u<<18)
#define	DMA_S3CR_CT			(0x1u<<19)
#define	DMA_S3CR_ACK		(0x1u<<20)
#define	DMA_S3CR_PBURST		(0x3u<<21)
#define	DMA_S3CR_PBURST_0	(0x1u<<21)
#define	DMA_S3CR_MBURST		(0x3u<<23)
#define	DMA_S3CR_MBURST_0	(0x1u<<23)

// S3NDTR Configuration

#define	DMA_S3NDTR_NDT		(0xFFFFu<<0)
#define	DMA_S3NDTR_NDT_0	(0x1u<<0)

// S3PAR Configuration

#define	DMA_S3PAR_PA		(0xFFFFFFFFu<<0)
#define	DMA_S3PAR_PA_0		(0x1u<<0)

// S3M0AR Configuration

#define	DMA_S3M0AR_M0A		(0xFFFFFFFFu<<0)
#define	DMA_S3M0AR_M0A_0	(0x1u<<0)

// S3M1AR Configuration

#define	DMA_S3M1AR_M1A		(0xFFFFFFFFu<<0)
#define	DMA_S3M1AR_M1A_0	(0x1u<<0)

// S3FCR Configuration

#define	DMA_S3FCR_FTH		(0x3u<<0)
#define	DMA_S3FCR_FTH_0		(0x1u<<0)
#define	DMA_S3FCR_DMDIS		(0x1u<<2)
#define	DMA_S3FCR_FS		(0x7u<<3)
#define	DMA_S3FCR_FS_0		(0x1u<<3)
#define	DMA_S3FCR_FEIE		(0x1u<<7)

// S4CR Configuration

#define	DMA_S4CR_EN			(0x1u<<0)
#define	DMA_S4CR_DMEIE		(0x1u<<1)
#define	DMA_S4CR_TEIE		(0x1u<<2)
#define	DMA_S4CR_HTIE		(0x1u<<3)
#define	DMA_S4CR_TCIE		(0x1u<<4)
#define	DMA_S4CR_PFCTRL		(0x1u<<5)
#define	DMA_S4CR_DIR		(0x3u<<6)
#define	DMA_S4CR_DIR_0		(0x1u<<6)
#define	DMA_S4CR_CIRC		(0x1u<<8)
#define	DMA_S4CR_PINC		(0x1u<<9)
#define	DMA_S4CR_MINC		(0x1u<<10)
#define	DMA_S4CR_PSIZE		(0x3u<<11)
#define	DMA_S4CR_PSIZE_0	(0x1u<<11)
#define	DMA_S4CR_MSIZE		(0x3u<<13)
#define	DMA_S4CR_MSIZE_0	(0x1u<<13)
#define	DMA_S4CR_PINCOS		(0x1u<<15)
#define	DMA_S4CR_PL			(0x3u<<16)
#define	DMA_S4CR_PL_0		(0x1u<<16)
#define	DMA_S4CR_DBM		(0x1u<<18)
#define	DMA_S4CR_CT			(0x1u<<19)
#define	DMA_S4CR_ACK		(0x1u<<20)
#define	DMA_S4CR_PBURST		(0x3u<<21)
#define	DMA_S4CR_PBURST_0	(0x1u<<21)
#define	DMA_S4CR_MBURST		(0x3u<<23)
#define	DMA_S4CR_MBURST_0	(0x1u<<23)

// S4NDTR Configuration

#define	DMA_S4NDTR_NDT		(0xFFFFu<<0)
#define	DMA_S4NDTR_NDT_0	(0x1u<<0)

// S4PAR Configuration

#define	DMA_S4PAR_PA		(0xFFFFFFFFu<<0)
#define	DMA_S4PAR_PA_0		(0x1u<<0)

// S4M0AR Configuration

#define	DMA_S4M0AR_M0A		(0xFFFFFFFFu<<0)
#define	DMA_S4M0AR_M0A_0	(0x1u<<0)

// S4M1AR Configuration

#define	DMA_S4M1AR_M1A		(0xFFFFFFFFu<<0)
#define	DMA_S4M1AR_M1A_0	(0x1u<<0)

// S4FCR Configuration

#define	DMA_S4FCR_FTH		(0x3u<<0)
#define	DMA_S4FCR_FTH_0		(0x1u<<0)
#define	DMA_S4FCR_DMDIS		(0x1u<<2)
#define	DMA_S4FCR_FS		(0x7u<<3)
#define	DMA_S4FCR_FS_0		(0x1u<<3)
#define	DMA_S4FCR_FEIE		(0x1u<<7)

// S5CR Configuration

#define	DMA_S5CR_EN			(0x1u<<0)
#define	DMA_S5CR_DMEIE		(0x1u<<1)
#define	DMA_S5CR_TEIE		(0x1u<<2)
#define	DMA_S5CR_HTIE		(0x1u<<3)
#define	DMA_S5CR_TCIE		(0x1u<<4)
#define	DMA_S5CR_PFCTRL		(0x1u<<5)
#define	DMA_S5CR_DIR		(0x3u<<6)
#define	DMA_S5CR_DIR_0		(0x1u<<6)
#define	DMA_S5CR_CIRC		(0x1u<<8)
#define	DMA_S5CR_PINC		(0x1u<<9)
#define	DMA_S5CR_MINC		(0x1u<<10)
#define	DMA_S5CR_PSIZE		(0x3u<<11)
#define	DMA_S5CR_PSIZE_0	(0x1u<<11)
#define	DMA_S5CR_MSIZE		(0x3u<<13)
#define	DMA_S5CR_MSIZE_0	(0x1u<<13)
#define	DMA_S5CR_PINCOS		(0x1u<<15)
#define	DMA_S5CR_PL			(0x3u<<16)
#define	DMA_S5CR_PL_0		(0x1u<<16)
#define	DMA_S5CR_DBM		(0x1u<<18)
#define	DMA_S5CR_CT			(0x1u<<19)
#define	DMA_S5CR_ACK		(0x1u<<20)
#define	DMA_S5CR_PBURST		(0x3u<<21)
#define	DMA_S5CR_PBURST_0	(0x1u<<21)
#define	DMA_S5CR_MBURST		(0x3u<<23)
#define	DMA_S5CR_MBURST_0	(0x1u<<23)

// S5NDTR Configuration

#define	DMA_S5NDTR_NDT		(0xFFFFu<<0)
#define	DMA_S5NDTR_NDT_0	(0x1u<<0)

// S5PAR Configuration

#define	DMA_S5PAR_PA		(0xFFFFFFFFu<<0)
#define	DMA_S5PAR_PA_0		(0x1u<<0)

// S5M0AR Configuration

#define	DMA_S5M0AR_M0A		(0xFFFFFFFFu<<0)
#define	DMA_S5M0AR_M0A_0	(0x1u<<0)

// S5M1AR Configuration

#define	DMA_S5M1AR_M1A		(0xFFFFFFFFu<<0)
#define	DMA_S5M1AR_M1A_0	(0x1u<<0)

// S5FCR Configuration

#define	DMA_S5FCR_FTH		(0x3u<<0)
#define	DMA_S5FCR_FTH_0		(0x1u<<0)
#define	DMA_S5FCR_DMDIS		(0x1u<<2)
#define	DMA_S5FCR_FS		(0x7u<<3)
#define	DMA_S5FCR_FS_0		(0x1u<<3)
#define	DMA_S5FCR_FEIE		(0x1u<<7)

// S6CR Configuration

#define	DMA_S6CR_EN			(0x1u<<0)
#define	DMA_S6CR_DMEIE		(0x1u<<1)
#define	DMA_S6CR_TEIE		(0x1u<<2)
#define	DMA_S6CR_HTIE		(0x1u<<3)
#define	DMA_S6CR_TCIE		(0x1u<<4)
#define	DMA_S6CR_PFCTRL		(0x1u<<5)
#define	DMA_S6CR_DIR		(0x3u<<6)
#define	DMA_S6CR_DIR_0		(0x1u<<6)
#define	DMA_S6CR_CIRC		(0x1u<<8)
#define	DMA_S6CR_PINC		(0x1u<<9)
#define	DMA_S6CR_MINC		(0x1u<<10)
#define	DMA_S6CR_PSIZE		(0x3u<<11)
#define	DMA_S6CR_PSIZE_0	(0x1u<<11)
#define	DMA_S6CR_MSIZE		(0x3u<<13)
#define	DMA_S6CR_MSIZE_0	(0x1u<<13)
#define	DMA_S6CR_PINCOS		(0x1u<<15)
#define	DMA_S6CR_PL			(0x3u<<16)
#define	DMA_S6CR_PL_0		(0x1u<<16)
#define	DMA_S6CR_DBM		(0x1u<<18)
#define	DMA_S6CR_CT			(0x1u<<19)
#define	DMA_S6CR_ACK		(0x1u<<20)
#define	DMA_S6CR_PBURST		(0x3u<<21)
#define	DMA_S6CR_PBURST_0	(0x1u<<21)
#define	DMA_S6CR_MBURST		(0x3u<<23)
#define	DMA_S6CR_MBURST_0	(0x1u<<23)

// S6NDTR Configuration

#define	DMA_S6NDTR_NDT		(0xFFFFu<<0)
#define	DMA_S6NDTR_NDT_0	(0x1u<<0)

// S6PAR Configuration

#define	DMA_S6PAR_PA		(0xFFFFFFFFu<<0)
#define	DMA_S6PAR_PA_0		(0x1u<<0)

// S6M0AR Configuration

#define	DMA_S6M0AR_M0A		(0xFFFFFFFFu<<0)
#define	DMA_S6M0AR_M0A_0	(0x1u<<0)

// S6M1AR Configuration

#define	DMA_S6M1AR_M1A		(0xFFFFFFFFu<<0)
#define	DMA_S6M1AR_M1A_0	(0x1u<<0)

// S6FCR Configuration

#define	DMA_S6FCR_FTH		(0x3u<<0)
#define	DMA_S6FCR_FTH_0		(0x1u<<0)
#define	DMA_S6FCR_DMDIS		(0x1u<<2)
#define	DMA_S6FCR_FS		(0x7u<<3)
#define	DMA_S6FCR_FS_0		(0x1u<<3)
#define	DMA_S6FCR_FEIE		(0x1u<<7)

// S7CR Configuration

#define	DMA_S7CR_EN			(0x1u<<0)
#define	DMA_S7CR_DMEIE		(0x1u<<1)
#define	DMA_S7CR_TEIE		(0x1u<<2)
#define	DMA_S7CR_HTIE		(0x1u<<3)
#define	DMA_S7CR_TCIE		(0x1u<<4)
#define	DMA_S7CR_PFCTRL		(0x1u<<5)
#define	DMA_S7CR_DIR		(0x3u<<6)
#define	DMA_S7CR_DIR_0		(0x1u<<6)
#define	DMA_S7CR_CIRC		(0x1u<<8)
#define	DMA_S7CR_PINC		(0x1u<<9)
#define	DMA_S7CR_MINC		(0x1u<<10)
#define	DMA_S7CR_PSIZE		(0x3u<<11)
#define	DMA_S7CR_PSIZE_0	(0x1u<<11)
#define	DMA_S7CR_MSIZE		(0x3u<<13)
#define	DMA_S7CR_MSIZE_0	(0x1u<<13)
#define	DMA_S7CR_PINCOS		(0x1u<<15)
#define	DMA_S7CR_PL			(0x3u<<16)
#define	DMA_S7CR_PL_0		(0x1u<<16)
#define	DMA_S7CR_DBM		(0x1u<<18)
#define	DMA_S7CR_CT			(0x1u<<19)
#define	DMA_S7CR_ACK		(0x1u<<20)
#define	DMA_S7CR_PBURST		(0x3u<<21)
#define	DMA_S7CR_PBURST_0	(0x1u<<21)
#define	DMA_S7CR_MBURST		(0x3u<<23)
#define	DMA_S7CR_MBURST_0	(0x1u<<23)

// S7NDTR Configuration

#define	DMA_S7NDTR_NDT		(0xFFFFu<<0)
#define	DMA_S7NDTR_NDT_0	(0x1u<<0)

// S7PAR Configuration

#define	DMA_S7PAR_PA		(0xFFFFFFFFu<<0)
#define	DMA_S7PAR_PA_0		(0x1u<<0)

// S7M0AR Configuration

#define	DMA_S7M0AR_M0A		(0xFFFFFFFFu<<0)
#define	DMA_S7M0AR_M0A_0	(0x1u<<0)

// S7M1AR Configuration

#define	DMA_S7M1AR_M1A		(0xFFFFFFFFu<<0)
#define	DMA_S7M1AR_M1A_0	(0x1u<<0)

// S7FCR Configuration

#define	DMA_S7FCR_FTH		(0x3u<<0)
#define	DMA_S7FCR_FTH_0		(0x1u<<0)
#define	DMA_S7FCR_DMDIS		(0x1u<<2)
#define	DMA_S7FCR_FS		(0x7u<<3)
#define	DMA_S7FCR_FS_0		(0x1u<<3)
#define	DMA_S7FCR_FEIE		(0x1u<<7)
