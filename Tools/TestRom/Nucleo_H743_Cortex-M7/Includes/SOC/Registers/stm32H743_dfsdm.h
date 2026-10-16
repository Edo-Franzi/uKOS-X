/*
; stm32H743_dfsdm.
; ================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_dfsdm equates.
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

// DFSDM address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	CHCFG0R1;
	volatile	uint32_t	CHCFG1R1;
	volatile	uint32_t	CHCFG2R1;
	volatile	uint32_t	CHCFG3R1;
	volatile	uint32_t	CHCFG4R1;
	volatile	uint32_t	CHCFG5R1;
	volatile	uint32_t	CHCFG6R1;
	volatile	uint32_t	CHCFG7R1;
	volatile	uint32_t	CHCFG0R2;
	volatile	uint32_t	CHCFG1R2;
	volatile	uint32_t	CHCFG2R2;
	volatile	uint32_t	CHCFG3R2;
	volatile	uint32_t	CHCFG4R2;
	volatile	uint32_t	CHCFG5R2;
	volatile	uint32_t	CHCFG6R2;
	volatile	uint32_t	CHCFG7R2;
	volatile	uint32_t	AWSCD0R;
	volatile	uint32_t	AWSCD1R;
	volatile	uint32_t	AWSCD2R;
	volatile	uint32_t	AWSCD3R;
	volatile	uint32_t	AWSCD4R;
	volatile	uint32_t	AWSCD5R;
	volatile	uint32_t	AWSCD6R;
	volatile	uint32_t	AWSCD7R;
	volatile	uint32_t	CHWDAT0R;
	volatile	uint32_t	CHWDAT1R;
	volatile	uint32_t	CHWDAT2R;
	volatile	uint32_t	CHWDAT3R;
	volatile	uint32_t	CHWDAT4R;
	volatile	uint32_t	CHWDAT5R;
	volatile	uint32_t	CHWDAT6R;
	volatile	uint32_t	CHWDAT7R;
	volatile	uint32_t	CHDATIN0R;
	volatile	uint32_t	CHDATIN1R;
	volatile	uint32_t	CHDATIN2R;
	volatile	uint32_t	CHDATIN3R;
	volatile	uint32_t	CHDATIN4R;
	volatile	uint32_t	CHDATIN5R;
	volatile	uint32_t	CHDATIN6R;
	volatile	uint32_t	CHDATIN7R;
	volatile	uint32_t	DFSDM0_CR1;
	volatile	uint32_t	DFSDM1_CR1;
	volatile	uint32_t	DFSDM2_CR1;
	volatile	uint32_t	DFSDM3_CR1;
	volatile	uint32_t	DFSDM0_CR2;
	volatile	uint32_t	DFSDM1_CR2;
	volatile	uint32_t	DFSDM2_CR2;
	volatile	uint32_t	DFSDM3_CR2;
	volatile	uint32_t	DFSDM0_ISR;
	volatile	uint32_t	DFSDM1_ISR;
	volatile	uint32_t	DFSDM2_ISR;
	volatile	uint32_t	DFSDM3_ISR;
	volatile	uint32_t	DFSDM0_ICR;
	volatile	uint32_t	DFSDM1_ICR;
	volatile	uint32_t	DFSDM2_ICR;
	volatile	uint32_t	DFSDM3_ICR;
	volatile	uint32_t	DFSDM0_JCHGR;
	volatile	uint32_t	DFSDM1_JCHGR;
	volatile	uint32_t	DFSDM2_JCHGR;
	volatile	uint32_t	DFSDM3_JCHGR;
	volatile	uint32_t	DFSDM0_FCR;
	volatile	uint32_t	DFSDM1_FCR;
	volatile	uint32_t	DFSDM2_FCR;
	volatile	uint32_t	DFSDM3_FCR;
	volatile	uint32_t	DFSDM0_JDATAR;
	volatile	uint32_t	DFSDM1_JDATAR;
	volatile	uint32_t	DFSDM2_JDATAR;
	volatile	uint32_t	DFSDM3_JDATAR;
	volatile	uint32_t	DFSDM0_RDATAR;
	volatile	uint32_t	DFSDM1_RDATAR;
	volatile	uint32_t	DFSDM2_RDATAR;
	volatile	uint32_t	DFSDM3_RDATAR;
	volatile	uint32_t	DFSDM0_AWHTR;
	volatile	uint32_t	DFSDM1_AWHTR;
	volatile	uint32_t	DFSDM2_AWHTR;
	volatile	uint32_t	DFSDM3_AWHTR;
	volatile	uint32_t	DFSDM0_AWLTR;
	volatile	uint32_t	DFSDM1_AWLTR;
	volatile	uint32_t	DFSDM2_AWLTR;
	volatile	uint32_t	DFSDM3_AWLTR;
	volatile	uint32_t	DFSDM0_AWSR;
	volatile	uint32_t	DFSDM1_AWSR;
	volatile	uint32_t	DFSDM2_AWSR;
	volatile	uint32_t	DFSDM3_AWSR;
	volatile	uint32_t	DFSDM0_AWCFR;
	volatile	uint32_t	DFSDM1_AWCFR;
	volatile	uint32_t	DFSDM2_AWCFR;
	volatile	uint32_t	DFSDM3_AWCFR;
	volatile	uint32_t	DFSDM0_EXMAX;
	volatile	uint32_t	DFSDM1_EXMAX;
	volatile	uint32_t	DFSDM2_EXMAX;
	volatile	uint32_t	DFSDM3_EXMAX;
	volatile	uint32_t	DFSDM0_EXMIN;
	volatile	uint32_t	DFSDM1_EXMIN;
	volatile	uint32_t	DFSDM2_EXMIN;
	volatile	uint32_t	DFSDM3_EXMIN;
	volatile	uint32_t	DFSDM0_CNVTIMR;
	volatile	uint32_t	DFSDM1_CNVTIMR;
	volatile	uint32_t	DFSDM2_CNVTIMR;
	volatile	uint32_t	DFSDM3_CNVTIMR;
} DFSDM_TypeDef;

#if (defined(__cplusplus))
#define	DFSDM	reinterpret_cast<DFSDM_TypeDef *>(0x40017000u)

#else
#define	DFSDM	((DFSDM_TypeDef *)0x40017000u)
#endif

// CHCFG0R1 Configuration

#define	DFSDM_CHCFG0R1_DFSDMEN			(0x1u<<31)
#define	DFSDM_CHCFG0R1_CKOUTSRC			(0x1u<<30)
#define	DFSDM_CHCFG0R1_CKOUTDIV			(0xFFu<<16)
#define	DFSDM_CHCFG0R1_CKOUTDIV_0		(0x1u<<16)
#define	DFSDM_CHCFG0R1_DATPACK			(0x3u<<14)
#define	DFSDM_CHCFG0R1_DATPACK_0		(0x1u<<14)
#define	DFSDM_CHCFG0R1_DATMPX			(0x3u<<12)
#define	DFSDM_CHCFG0R1_DATMPX_0			(0x1u<<12)
#define	DFSDM_CHCFG0R1_CHINSEL			(0x1u<<8)
#define	DFSDM_CHCFG0R1_CHEN				(0x1u<<7)
#define	DFSDM_CHCFG0R1_CKABEN			(0x1u<<6)
#define	DFSDM_CHCFG0R1_SCDEN			(0x1u<<5)
#define	DFSDM_CHCFG0R1_SPICKSEL			(0x3u<<2)
#define	DFSDM_CHCFG0R1_SPICKSEL_0		(0x1u<<2)
#define	DFSDM_CHCFG0R1_SITP				(0x3u<<0)
#define	DFSDM_CHCFG0R1_SITP_0			(0x1u<<0)

// CHCFG1R1 Configuration

#define	DFSDM_CHCFG1R1_DFSDMEN			(0x1u<<31)
#define	DFSDM_CHCFG1R1_CKOUTSRC			(0x1u<<30)
#define	DFSDM_CHCFG1R1_CKOUTDIV			(0xFFu<<16)
#define	DFSDM_CHCFG1R1_CKOUTDIV_0		(0x1u<<16)
#define	DFSDM_CHCFG1R1_DATPACK			(0x3u<<14)
#define	DFSDM_CHCFG1R1_DATPACK_0		(0x1u<<14)
#define	DFSDM_CHCFG1R1_DATMPX			(0x3u<<12)
#define	DFSDM_CHCFG1R1_DATMPX_0			(0x1u<<12)
#define	DFSDM_CHCFG1R1_CHINSEL			(0x1u<<8)
#define	DFSDM_CHCFG1R1_CHEN				(0x1u<<7)
#define	DFSDM_CHCFG1R1_CKABEN			(0x1u<<6)
#define	DFSDM_CHCFG1R1_SCDEN			(0x1u<<5)
#define	DFSDM_CHCFG1R1_SPICKSEL			(0x3u<<2)
#define	DFSDM_CHCFG1R1_SPICKSEL_0		(0x1u<<2)
#define	DFSDM_CHCFG1R1_SITP				(0x3u<<0)
#define	DFSDM_CHCFG1R1_SITP_0			(0x1u<<0)

// CHCFG2R1 Configuration

#define	DFSDM_CHCFG2R1_DFSDMEN			(0x1u<<31)
#define	DFSDM_CHCFG2R1_CKOUTSRC			(0x1u<<30)
#define	DFSDM_CHCFG2R1_CKOUTDIV			(0xFFu<<16)
#define	DFSDM_CHCFG2R1_CKOUTDIV_0		(0x1u<<16)
#define	DFSDM_CHCFG2R1_DATPACK			(0x3u<<14)
#define	DFSDM_CHCFG2R1_DATPACK_0		(0x1u<<14)
#define	DFSDM_CHCFG2R1_DATMPX			(0x3u<<12)
#define	DFSDM_CHCFG2R1_DATMPX_0			(0x1u<<12)
#define	DFSDM_CHCFG2R1_CHINSEL			(0x1u<<8)
#define	DFSDM_CHCFG2R1_CHEN				(0x1u<<7)
#define	DFSDM_CHCFG2R1_CKABEN			(0x1u<<6)
#define	DFSDM_CHCFG2R1_SCDEN			(0x1u<<5)
#define	DFSDM_CHCFG2R1_SPICKSEL			(0x3u<<2)
#define	DFSDM_CHCFG2R1_SPICKSEL_0		(0x1u<<2)
#define	DFSDM_CHCFG2R1_SITP				(0x3u<<0)
#define	DFSDM_CHCFG2R1_SITP_0			(0x1u<<0)

// CHCFG3R1 Configuration

#define	DFSDM_CHCFG3R1_DFSDMEN			(0x1u<<31)
#define	DFSDM_CHCFG3R1_CKOUTSRC			(0x1u<<30)
#define	DFSDM_CHCFG3R1_CKOUTDIV			(0xFFu<<16)
#define	DFSDM_CHCFG3R1_CKOUTDIV_0		(0x1u<<16)
#define	DFSDM_CHCFG3R1_DATPACK			(0x3u<<14)
#define	DFSDM_CHCFG3R1_DATPACK_0		(0x1u<<14)
#define	DFSDM_CHCFG3R1_DATMPX			(0x3u<<12)
#define	DFSDM_CHCFG3R1_DATMPX_0			(0x1u<<12)
#define	DFSDM_CHCFG3R1_CHINSEL			(0x1u<<8)
#define	DFSDM_CHCFG3R1_CHEN				(0x1u<<7)
#define	DFSDM_CHCFG3R1_CKABEN			(0x1u<<6)
#define	DFSDM_CHCFG3R1_SCDEN			(0x1u<<5)
#define	DFSDM_CHCFG3R1_SPICKSEL			(0x3u<<2)
#define	DFSDM_CHCFG3R1_SPICKSEL_0		(0x1u<<2)
#define	DFSDM_CHCFG3R1_SITP				(0x3u<<0)
#define	DFSDM_CHCFG3R1_SITP_0			(0x1u<<0)

// CHCFG4R1 Configuration

#define	DFSDM_CHCFG4R1_DFSDMEN			(0x1u<<31)
#define	DFSDM_CHCFG4R1_CKOUTSRC			(0x1u<<30)
#define	DFSDM_CHCFG4R1_CKOUTDIV			(0xFFu<<16)
#define	DFSDM_CHCFG4R1_CKOUTDIV_0		(0x1u<<16)
#define	DFSDM_CHCFG4R1_DATPACK			(0x3u<<14)
#define	DFSDM_CHCFG4R1_DATPACK_0		(0x1u<<14)
#define	DFSDM_CHCFG4R1_DATMPX			(0x3u<<12)
#define	DFSDM_CHCFG4R1_DATMPX_0			(0x1u<<12)
#define	DFSDM_CHCFG4R1_CHINSEL			(0x1u<<8)
#define	DFSDM_CHCFG4R1_CHEN				(0x1u<<7)
#define	DFSDM_CHCFG4R1_CKABEN			(0x1u<<6)
#define	DFSDM_CHCFG4R1_SCDEN			(0x1u<<5)
#define	DFSDM_CHCFG4R1_SPICKSEL			(0x3u<<2)
#define	DFSDM_CHCFG4R1_SPICKSEL_0		(0x1u<<2)
#define	DFSDM_CHCFG4R1_SITP				(0x3u<<0)
#define	DFSDM_CHCFG4R1_SITP_0			(0x1u<<0)

// CHCFG5R1 Configuration

#define	DFSDM_CHCFG5R1_DFSDMEN			(0x1u<<31)
#define	DFSDM_CHCFG5R1_CKOUTSRC			(0x1u<<30)
#define	DFSDM_CHCFG5R1_CKOUTDIV			(0xFFu<<16)
#define	DFSDM_CHCFG5R1_CKOUTDIV_0		(0x1u<<16)
#define	DFSDM_CHCFG5R1_DATPACK			(0x3u<<14)
#define	DFSDM_CHCFG5R1_DATPACK_0		(0x1u<<14)
#define	DFSDM_CHCFG5R1_DATMPX			(0x3u<<12)
#define	DFSDM_CHCFG5R1_DATMPX_0			(0x1u<<12)
#define	DFSDM_CHCFG5R1_CHINSEL			(0x1u<<8)
#define	DFSDM_CHCFG5R1_CHEN				(0x1u<<7)
#define	DFSDM_CHCFG5R1_CKABEN			(0x1u<<6)
#define	DFSDM_CHCFG5R1_SCDEN			(0x1u<<5)
#define	DFSDM_CHCFG5R1_SPICKSEL			(0x3u<<2)
#define	DFSDM_CHCFG5R1_SPICKSEL_0		(0x1u<<2)
#define	DFSDM_CHCFG5R1_SITP				(0x3u<<0)
#define	DFSDM_CHCFG5R1_SITP_0			(0x1u<<0)

// CHCFG6R1 Configuration

#define	DFSDM_CHCFG6R1_DFSDMEN			(0x1u<<31)
#define	DFSDM_CHCFG6R1_CKOUTSRC			(0x1u<<30)
#define	DFSDM_CHCFG6R1_CKOUTDIV			(0xFFu<<16)
#define	DFSDM_CHCFG6R1_CKOUTDIV_0		(0x1u<<16)
#define	DFSDM_CHCFG6R1_DATPACK			(0x3u<<14)
#define	DFSDM_CHCFG6R1_DATPACK_0		(0x1u<<14)
#define	DFSDM_CHCFG6R1_DATMPX			(0x3u<<12)
#define	DFSDM_CHCFG6R1_DATMPX_0			(0x1u<<12)
#define	DFSDM_CHCFG6R1_CHINSEL			(0x1u<<8)
#define	DFSDM_CHCFG6R1_CHEN				(0x1u<<7)
#define	DFSDM_CHCFG6R1_CKABEN			(0x1u<<6)
#define	DFSDM_CHCFG6R1_SCDEN			(0x1u<<5)
#define	DFSDM_CHCFG6R1_SPICKSEL			(0x3u<<2)
#define	DFSDM_CHCFG6R1_SPICKSEL_0		(0x1u<<2)
#define	DFSDM_CHCFG6R1_SITP				(0x3u<<0)
#define	DFSDM_CHCFG6R1_SITP_0			(0x1u<<0)

// CHCFG7R1 Configuration

#define	DFSDM_CHCFG7R1_DFSDMEN			(0x1u<<31)
#define	DFSDM_CHCFG7R1_CKOUTSRC			(0x1u<<30)
#define	DFSDM_CHCFG7R1_CKOUTDIV			(0xFFu<<16)
#define	DFSDM_CHCFG7R1_CKOUTDIV_0		(0x1u<<16)
#define	DFSDM_CHCFG7R1_DATPACK			(0x3u<<14)
#define	DFSDM_CHCFG7R1_DATPACK_0		(0x1u<<14)
#define	DFSDM_CHCFG7R1_DATMPX			(0x3u<<12)
#define	DFSDM_CHCFG7R1_DATMPX_0			(0x1u<<12)
#define	DFSDM_CHCFG7R1_CHINSEL			(0x1u<<8)
#define	DFSDM_CHCFG7R1_CHEN				(0x1u<<7)
#define	DFSDM_CHCFG7R1_CKABEN			(0x1u<<6)
#define	DFSDM_CHCFG7R1_SCDEN			(0x1u<<5)
#define	DFSDM_CHCFG7R1_SPICKSEL			(0x3u<<2)
#define	DFSDM_CHCFG7R1_SPICKSEL_0		(0x1u<<2)
#define	DFSDM_CHCFG7R1_SITP				(0x3u<<0)
#define	DFSDM_CHCFG7R1_SITP_0			(0x1u<<0)

// CHCFG0R2 Configuration

#define	DFSDM_CHCFG0R2_OFFSET			(0xFFFFFFu<<8)
#define	DFSDM_CHCFG0R2_OFFSET_0			(0x1u<<8)
#define	DFSDM_CHCFG0R2_DTRBS			(0x1Fu<<3)
#define	DFSDM_CHCFG0R2_DTRBS_0			(0x1u<<3)

// CHCFG1R2 Configuration

#define	DFSDM_CHCFG1R2_OFFSET			(0xFFFFFFu<<8)
#define	DFSDM_CHCFG1R2_OFFSET_0			(0x1u<<8)
#define	DFSDM_CHCFG1R2_DTRBS			(0x1Fu<<3)
#define	DFSDM_CHCFG1R2_DTRBS_0			(0x1u<<3)

// CHCFG2R2 Configuration

#define	DFSDM_CHCFG2R2_OFFSET			(0xFFFFFFu<<8)
#define	DFSDM_CHCFG2R2_OFFSET_0			(0x1u<<8)
#define	DFSDM_CHCFG2R2_DTRBS			(0x1Fu<<3)
#define	DFSDM_CHCFG2R2_DTRBS_0			(0x1u<<3)

// CHCFG3R2 Configuration

#define	DFSDM_CHCFG3R2_OFFSET			(0xFFFFFFu<<8)
#define	DFSDM_CHCFG3R2_OFFSET_0			(0x1u<<8)
#define	DFSDM_CHCFG3R2_DTRBS			(0x1Fu<<3)
#define	DFSDM_CHCFG3R2_DTRBS_0			(0x1u<<3)

// CHCFG4R2 Configuration

#define	DFSDM_CHCFG4R2_OFFSET			(0xFFFFFFu<<8)
#define	DFSDM_CHCFG4R2_OFFSET_0			(0x1u<<8)
#define	DFSDM_CHCFG4R2_DTRBS			(0x1Fu<<3)
#define	DFSDM_CHCFG4R2_DTRBS_0			(0x1u<<3)

// CHCFG5R2 Configuration

#define	DFSDM_CHCFG5R2_OFFSET			(0xFFFFFFu<<8)
#define	DFSDM_CHCFG5R2_OFFSET_0			(0x1u<<8)
#define	DFSDM_CHCFG5R2_DTRBS			(0x1Fu<<3)
#define	DFSDM_CHCFG5R2_DTRBS_0			(0x1u<<3)

// CHCFG6R2 Configuration

#define	DFSDM_CHCFG6R2_OFFSET			(0xFFFFFFu<<8)
#define	DFSDM_CHCFG6R2_OFFSET_0			(0x1u<<8)
#define	DFSDM_CHCFG6R2_DTRBS			(0x1Fu<<3)
#define	DFSDM_CHCFG6R2_DTRBS_0			(0x1u<<3)

// CHCFG7R2 Configuration

#define	DFSDM_CHCFG7R2_OFFSET			(0xFFFFFFu<<8)
#define	DFSDM_CHCFG7R2_OFFSET_0			(0x1u<<8)
#define	DFSDM_CHCFG7R2_DTRBS			(0x1Fu<<3)
#define	DFSDM_CHCFG7R2_DTRBS_0			(0x1u<<3)

// AWSCD0R Configuration

#define	DFSDM_AWSCD0R_AWFORD			(0x3u<<22)
#define	DFSDM_AWSCD0R_AWFORD_0			(0x1u<<22)
#define	DFSDM_AWSCD0R_AWFOSR			(0x1Fu<<16)
#define	DFSDM_AWSCD0R_AWFOSR_0			(0x1u<<16)
#define	DFSDM_AWSCD0R_BKSCD				(0xFu<<12)
#define	DFSDM_AWSCD0R_BKSCD_0			(0x1u<<12)
#define	DFSDM_AWSCD0R_SCDT				(0xFFu<<0)
#define	DFSDM_AWSCD0R_SCDT_0			(0x1u<<0)

// AWSCD1R Configuration

#define	DFSDM_AWSCD1R_AWFORD			(0x3u<<22)
#define	DFSDM_AWSCD1R_AWFORD_0			(0x1u<<22)
#define	DFSDM_AWSCD1R_AWFOSR			(0x1Fu<<16)
#define	DFSDM_AWSCD1R_AWFOSR_0			(0x1u<<16)
#define	DFSDM_AWSCD1R_BKSCD				(0xFu<<12)
#define	DFSDM_AWSCD1R_BKSCD_0			(0x1u<<12)
#define	DFSDM_AWSCD1R_SCDT				(0xFFu<<0)
#define	DFSDM_AWSCD1R_SCDT_0			(0x1u<<0)

// AWSCD2R Configuration

#define	DFSDM_AWSCD2R_AWFORD			(0x3u<<22)
#define	DFSDM_AWSCD2R_AWFORD_0			(0x1u<<22)
#define	DFSDM_AWSCD2R_AWFOSR			(0x1Fu<<16)
#define	DFSDM_AWSCD2R_AWFOSR_0			(0x1u<<16)
#define	DFSDM_AWSCD2R_BKSCD				(0xFu<<12)
#define	DFSDM_AWSCD2R_BKSCD_0			(0x1u<<12)
#define	DFSDM_AWSCD2R_SCDT				(0xFFu<<0)
#define	DFSDM_AWSCD2R_SCDT_0			(0x1u<<0)

// AWSCD3R Configuration

#define	DFSDM_AWSCD3R_AWFORD			(0x3u<<22)
#define	DFSDM_AWSCD3R_AWFORD_0			(0x1u<<22)
#define	DFSDM_AWSCD3R_AWFOSR			(0x1Fu<<16)
#define	DFSDM_AWSCD3R_AWFOSR_0			(0x1u<<16)
#define	DFSDM_AWSCD3R_BKSCD				(0xFu<<12)
#define	DFSDM_AWSCD3R_BKSCD_0			(0x1u<<12)
#define	DFSDM_AWSCD3R_SCDT				(0xFFu<<0)
#define	DFSDM_AWSCD3R_SCDT_0			(0x1u<<0)

// AWSCD4R Configuration

#define	DFSDM_AWSCD4R_AWFORD			(0x3u<<22)
#define	DFSDM_AWSCD4R_AWFORD_0			(0x1u<<22)
#define	DFSDM_AWSCD4R_AWFOSR			(0x1Fu<<16)
#define	DFSDM_AWSCD4R_AWFOSR_0			(0x1u<<16)
#define	DFSDM_AWSCD4R_BKSCD				(0xFu<<12)
#define	DFSDM_AWSCD4R_BKSCD_0			(0x1u<<12)
#define	DFSDM_AWSCD4R_SCDT				(0xFFu<<0)
#define	DFSDM_AWSCD4R_SCDT_0			(0x1u<<0)

// AWSCD5R Configuration

#define	DFSDM_AWSCD5R_AWFORD			(0x3u<<22)
#define	DFSDM_AWSCD5R_AWFORD_0			(0x1u<<22)
#define	DFSDM_AWSCD5R_AWFOSR			(0x1Fu<<16)
#define	DFSDM_AWSCD5R_AWFOSR_0			(0x1u<<16)
#define	DFSDM_AWSCD5R_BKSCD				(0xFu<<12)
#define	DFSDM_AWSCD5R_BKSCD_0			(0x1u<<12)
#define	DFSDM_AWSCD5R_SCDT				(0xFFu<<0)
#define	DFSDM_AWSCD5R_SCDT_0			(0x1u<<0)

// AWSCD6R Configuration

#define	DFSDM_AWSCD6R_AWFORD			(0x3u<<22)
#define	DFSDM_AWSCD6R_AWFORD_0			(0x1u<<22)
#define	DFSDM_AWSCD6R_AWFOSR			(0x1Fu<<16)
#define	DFSDM_AWSCD6R_AWFOSR_0			(0x1u<<16)
#define	DFSDM_AWSCD6R_BKSCD				(0xFu<<12)
#define	DFSDM_AWSCD6R_BKSCD_0			(0x1u<<12)
#define	DFSDM_AWSCD6R_SCDT				(0xFFu<<0)
#define	DFSDM_AWSCD6R_SCDT_0			(0x1u<<0)

// AWSCD7R Configuration

#define	DFSDM_AWSCD7R_AWFORD			(0x3u<<22)
#define	DFSDM_AWSCD7R_AWFORD_0			(0x1u<<22)
#define	DFSDM_AWSCD7R_AWFOSR			(0x1Fu<<16)
#define	DFSDM_AWSCD7R_AWFOSR_0			(0x1u<<16)
#define	DFSDM_AWSCD7R_BKSCD				(0xFu<<12)
#define	DFSDM_AWSCD7R_BKSCD_0			(0x1u<<12)
#define	DFSDM_AWSCD7R_SCDT				(0xFFu<<0)
#define	DFSDM_AWSCD7R_SCDT_0			(0x1u<<0)

// CHWDAT0R Configuration

#define	DFSDM_CHWDAT0R_WDATA			(0xFFFFu<<0)
#define	DFSDM_CHWDAT0R_WDATA_0			(0x1u<<0)

// CHWDAT1R Configuration

#define	DFSDM_CHWDAT1R_WDATA			(0xFFFFu<<0)
#define	DFSDM_CHWDAT1R_WDATA_0			(0x1u<<0)

// CHWDAT2R Configuration

#define	DFSDM_CHWDAT2R_WDATA			(0xFFFFu<<0)
#define	DFSDM_CHWDAT2R_WDATA_0			(0x1u<<0)

// CHWDAT3R Configuration

#define	DFSDM_CHWDAT3R_WDATA			(0xFFFFu<<0)
#define	DFSDM_CHWDAT3R_WDATA_0			(0x1u<<0)

// CHWDAT4R Configuration

#define	DFSDM_CHWDAT4R_WDATA			(0xFFFFu<<0)
#define	DFSDM_CHWDAT4R_WDATA_0			(0x1u<<0)

// CHWDAT5R Configuration

#define	DFSDM_CHWDAT5R_WDATA			(0xFFFFu<<0)
#define	DFSDM_CHWDAT5R_WDATA_0			(0x1u<<0)

// CHWDAT6R Configuration

#define	DFSDM_CHWDAT6R_WDATA			(0xFFFFu<<0)
#define	DFSDM_CHWDAT6R_WDATA_0			(0x1u<<0)

// CHWDAT7R Configuration

#define	DFSDM_CHWDAT7R_WDATA			(0xFFFFu<<0)
#define	DFSDM_CHWDAT7R_WDATA_0			(0x1u<<0)

// CHDATIN0R Configuration

#define	DFSDM_CHDATIN0R_INDAT1			(0xFFFFu<<16)
#define	DFSDM_CHDATIN0R_INDAT1_0		(0x1u<<16)
#define	DFSDM_CHDATIN0R_INDAT0			(0xFFFFu<<0)
#define	DFSDM_CHDATIN0R_INDAT0_0		(0x1u<<0)

// CHDATIN1R Configuration

#define	DFSDM_CHDATIN1R_INDAT1			(0xFFFFu<<16)
#define	DFSDM_CHDATIN1R_INDAT1_0		(0x1u<<16)
#define	DFSDM_CHDATIN1R_INDAT0			(0xFFFFu<<0)
#define	DFSDM_CHDATIN1R_INDAT0_0		(0x1u<<0)

// CHDATIN2R Configuration

#define	DFSDM_CHDATIN2R_INDAT1			(0xFFFFu<<16)
#define	DFSDM_CHDATIN2R_INDAT1_0		(0x1u<<16)
#define	DFSDM_CHDATIN2R_INDAT0			(0xFFFFu<<0)
#define	DFSDM_CHDATIN2R_INDAT0_0		(0x1u<<0)

// CHDATIN3R Configuration

#define	DFSDM_CHDATIN3R_INDAT1			(0xFFFFu<<16)
#define	DFSDM_CHDATIN3R_INDAT1_0		(0x1u<<16)
#define	DFSDM_CHDATIN3R_INDAT0			(0xFFFFu<<0)
#define	DFSDM_CHDATIN3R_INDAT0_0		(0x1u<<0)

// CHDATIN4R Configuration

#define	DFSDM_CHDATIN4R_INDAT1			(0xFFFFu<<16)
#define	DFSDM_CHDATIN4R_INDAT1_0		(0x1u<<16)
#define	DFSDM_CHDATIN4R_INDAT0			(0xFFFFu<<0)
#define	DFSDM_CHDATIN4R_INDAT0_0		(0x1u<<0)

// CHDATIN5R Configuration

#define	DFSDM_CHDATIN5R_INDAT1			(0xFFFFu<<16)
#define	DFSDM_CHDATIN5R_INDAT1_0		(0x1u<<16)
#define	DFSDM_CHDATIN5R_INDAT0			(0xFFFFu<<0)
#define	DFSDM_CHDATIN5R_INDAT0_0		(0x1u<<0)

// CHDATIN6R Configuration

#define	DFSDM_CHDATIN6R_INDAT1			(0xFFFFu<<16)
#define	DFSDM_CHDATIN6R_INDAT1_0		(0x1u<<16)
#define	DFSDM_CHDATIN6R_INDAT0			(0xFFFFu<<0)
#define	DFSDM_CHDATIN6R_INDAT0_0		(0x1u<<0)

// CHDATIN7R Configuration

#define	DFSDM_CHDATIN7R_INDAT1			(0xFFFFu<<16)
#define	DFSDM_CHDATIN7R_INDAT1_0		(0x1u<<16)
#define	DFSDM_CHDATIN7R_INDAT0			(0xFFFFu<<0)
#define	DFSDM_CHDATIN7R_INDAT0_0		(0x1u<<0)

// DFSDM0_CR1 Configuration

#define	DFSDM_DFSDM0_CR1_AWFSEL			(0x1u<<30)
#define	DFSDM_DFSDM0_CR1_FAST			(0x1u<<29)
#define	DFSDM_DFSDM0_CR1_RCH			(0x7u<<24)
#define	DFSDM_DFSDM0_CR1_RCH_0			(0x1u<<24)
#define	DFSDM_DFSDM0_CR1_RDMAEN			(0x1u<<21)
#define	DFSDM_DFSDM0_CR1_RSYNC			(0x1u<<19)
#define	DFSDM_DFSDM0_CR1_RCONT			(0x1u<<18)
#define	DFSDM_DFSDM0_CR1_RSWSTART		(0x1u<<17)
#define	DFSDM_DFSDM0_CR1_JEXTEN			(0x3u<<13)
#define	DFSDM_DFSDM0_CR1_JEXTEN_0		(0x1u<<13)
#define	DFSDM_DFSDM0_CR1_JEXTSEL		(0x1Fu<<8)
#define	DFSDM_DFSDM0_CR1_JEXTSEL_0		(0x1u<<8)
#define	DFSDM_DFSDM0_CR1_JDMAEN			(0x1u<<5)
#define	DFSDM_DFSDM0_CR1_JSCAN			(0x1u<<4)
#define	DFSDM_DFSDM0_CR1_JSYNC			(0x1u<<3)
#define	DFSDM_DFSDM0_CR1_JSWSTART		(0x1u<<1)
#define	DFSDM_DFSDM0_CR1_DFEN			(0x1u<<0)

// DFSDM1_CR1 Configuration

#define	DFSDM_DFSDM1_CR1_AWFSEL			(0x1u<<30)
#define	DFSDM_DFSDM1_CR1_FAST			(0x1u<<29)
#define	DFSDM_DFSDM1_CR1_RCH			(0x7u<<24)
#define	DFSDM_DFSDM1_CR1_RCH_0			(0x1u<<24)
#define	DFSDM_DFSDM1_CR1_RDMAEN			(0x1u<<21)
#define	DFSDM_DFSDM1_CR1_RSYNC			(0x1u<<19)
#define	DFSDM_DFSDM1_CR1_RCONT			(0x1u<<18)
#define	DFSDM_DFSDM1_CR1_RSWSTART		(0x1u<<17)
#define	DFSDM_DFSDM1_CR1_JEXTEN			(0x3u<<13)
#define	DFSDM_DFSDM1_CR1_JEXTEN_0		(0x1u<<13)
#define	DFSDM_DFSDM1_CR1_JEXTSEL		(0x1Fu<<8)
#define	DFSDM_DFSDM1_CR1_JEXTSEL_0		(0x1u<<8)
#define	DFSDM_DFSDM1_CR1_JDMAEN			(0x1u<<5)
#define	DFSDM_DFSDM1_CR1_JSCAN			(0x1u<<4)
#define	DFSDM_DFSDM1_CR1_JSYNC			(0x1u<<3)
#define	DFSDM_DFSDM1_CR1_JSWSTART		(0x1u<<1)
#define	DFSDM_DFSDM1_CR1_DFEN			(0x1u<<0)

// DFSDM2_CR1 Configuration

#define	DFSDM_DFSDM2_CR1_AWFSEL			(0x1u<<30)
#define	DFSDM_DFSDM2_CR1_FAST			(0x1u<<29)
#define	DFSDM_DFSDM2_CR1_RCH			(0x7u<<24)
#define	DFSDM_DFSDM2_CR1_RCH_0			(0x1u<<24)
#define	DFSDM_DFSDM2_CR1_RDMAEN			(0x1u<<21)
#define	DFSDM_DFSDM2_CR1_RSYNC			(0x1u<<19)
#define	DFSDM_DFSDM2_CR1_RCONT			(0x1u<<18)
#define	DFSDM_DFSDM2_CR1_RSWSTART		(0x1u<<17)
#define	DFSDM_DFSDM2_CR1_JEXTEN			(0x3u<<13)
#define	DFSDM_DFSDM2_CR1_JEXTEN_0		(0x1u<<13)
#define	DFSDM_DFSDM2_CR1_JEXTSEL		(0x1Fu<<8)
#define	DFSDM_DFSDM2_CR1_JEXTSEL_0		(0x1u<<8)
#define	DFSDM_DFSDM2_CR1_JDMAEN			(0x1u<<5)
#define	DFSDM_DFSDM2_CR1_JSCAN			(0x1u<<4)
#define	DFSDM_DFSDM2_CR1_JSYNC			(0x1u<<3)
#define	DFSDM_DFSDM2_CR1_JSWSTART		(0x1u<<1)
#define	DFSDM_DFSDM2_CR1_DFEN			(0x1u<<0)

// DFSDM3_CR1 Configuration

#define	DFSDM_DFSDM3_CR1_AWFSEL			(0x1u<<30)
#define	DFSDM_DFSDM3_CR1_FAST			(0x1u<<29)
#define	DFSDM_DFSDM3_CR1_RCH			(0x7u<<24)
#define	DFSDM_DFSDM3_CR1_RCH_0			(0x1u<<24)
#define	DFSDM_DFSDM3_CR1_RDMAEN			(0x1u<<21)
#define	DFSDM_DFSDM3_CR1_RSYNC			(0x1u<<19)
#define	DFSDM_DFSDM3_CR1_RCONT			(0x1u<<18)
#define	DFSDM_DFSDM3_CR1_RSWSTART		(0x1u<<17)
#define	DFSDM_DFSDM3_CR1_JEXTEN			(0x3u<<13)
#define	DFSDM_DFSDM3_CR1_JEXTEN_0		(0x1u<<13)
#define	DFSDM_DFSDM3_CR1_JEXTSEL		(0x1Fu<<8)
#define	DFSDM_DFSDM3_CR1_JEXTSEL_0		(0x1u<<8)
#define	DFSDM_DFSDM3_CR1_JDMAEN			(0x1u<<5)
#define	DFSDM_DFSDM3_CR1_JSCAN			(0x1u<<4)
#define	DFSDM_DFSDM3_CR1_JSYNC			(0x1u<<3)
#define	DFSDM_DFSDM3_CR1_JSWSTART		(0x1u<<1)
#define	DFSDM_DFSDM3_CR1_DFEN			(0x1u<<0)

// DFSDM0_CR2 Configuration

#define	DFSDM_DFSDM0_CR2_AWDCH			(0xFFu<<16)
#define	DFSDM_DFSDM0_CR2_AWDCH_0		(0x1u<<16)
#define	DFSDM_DFSDM0_CR2_EXCH			(0xFFu<<8)
#define	DFSDM_DFSDM0_CR2_EXCH_0			(0x1u<<8)
#define	DFSDM_DFSDM0_CR2_CKABIE			(0x1u<<6)
#define	DFSDM_DFSDM0_CR2_SCDIE			(0x1u<<5)
#define	DFSDM_DFSDM0_CR2_AWDIE			(0x1u<<4)
#define	DFSDM_DFSDM0_CR2_ROVRIE			(0x1u<<3)
#define	DFSDM_DFSDM0_CR2_JOVRIE			(0x1u<<2)
#define	DFSDM_DFSDM0_CR2_REOCIE			(0x1u<<1)
#define	DFSDM_DFSDM0_CR2_JEOCIE			(0x1u<<0)

// DFSDM1_CR2 Configuration

#define	DFSDM_DFSDM1_CR2_AWDCH			(0xFFu<<16)
#define	DFSDM_DFSDM1_CR2_AWDCH_0		(0x1u<<16)
#define	DFSDM_DFSDM1_CR2_EXCH			(0xFFu<<8)
#define	DFSDM_DFSDM1_CR2_EXCH_0			(0x1u<<8)
#define	DFSDM_DFSDM1_CR2_CKABIE			(0x1u<<6)
#define	DFSDM_DFSDM1_CR2_SCDIE			(0x1u<<5)
#define	DFSDM_DFSDM1_CR2_AWDIE			(0x1u<<4)
#define	DFSDM_DFSDM1_CR2_ROVRIE			(0x1u<<3)
#define	DFSDM_DFSDM1_CR2_JOVRIE			(0x1u<<2)
#define	DFSDM_DFSDM1_CR2_REOCIE			(0x1u<<1)
#define	DFSDM_DFSDM1_CR2_JEOCIE			(0x1u<<0)

// DFSDM2_CR2 Configuration

#define	DFSDM_DFSDM2_CR2_AWDCH			(0xFFu<<16)
#define	DFSDM_DFSDM2_CR2_AWDCH_0		(0x1u<<16)
#define	DFSDM_DFSDM2_CR2_EXCH			(0xFFu<<8)
#define	DFSDM_DFSDM2_CR2_EXCH_0			(0x1u<<8)
#define	DFSDM_DFSDM2_CR2_CKABIE			(0x1u<<6)
#define	DFSDM_DFSDM2_CR2_SCDIE			(0x1u<<5)
#define	DFSDM_DFSDM2_CR2_AWDIE			(0x1u<<4)
#define	DFSDM_DFSDM2_CR2_ROVRIE			(0x1u<<3)
#define	DFSDM_DFSDM2_CR2_JOVRIE			(0x1u<<2)
#define	DFSDM_DFSDM2_CR2_REOCIE			(0x1u<<1)
#define	DFSDM_DFSDM2_CR2_JEOCIE			(0x1u<<0)

// DFSDM3_CR2 Configuration

#define	DFSDM_DFSDM3_CR2_AWDCH			(0xFFu<<16)
#define	DFSDM_DFSDM3_CR2_AWDCH_0		(0x1u<<16)
#define	DFSDM_DFSDM3_CR2_EXCH			(0xFFu<<8)
#define	DFSDM_DFSDM3_CR2_EXCH_0			(0x1u<<8)
#define	DFSDM_DFSDM3_CR2_CKABIE			(0x1u<<6)
#define	DFSDM_DFSDM3_CR2_SCDIE			(0x1u<<5)
#define	DFSDM_DFSDM3_CR2_AWDIE			(0x1u<<4)
#define	DFSDM_DFSDM3_CR2_ROVRIE			(0x1u<<3)
#define	DFSDM_DFSDM3_CR2_JOVRIE			(0x1u<<2)
#define	DFSDM_DFSDM3_CR2_REOCIE			(0x1u<<1)
#define	DFSDM_DFSDM3_CR2_JEOCIE			(0x1u<<0)

// DFSDM0_ISR Configuration

#define	DFSDM_DFSDM0_ISR_SCDF			(0xFFu<<24)
#define	DFSDM_DFSDM0_ISR_SCDF_0			(0x1u<<24)
#define	DFSDM_DFSDM0_ISR_CKABF			(0xFFu<<16)
#define	DFSDM_DFSDM0_ISR_CKABF_0		(0x1u<<16)
#define	DFSDM_DFSDM0_ISR_RCIP			(0x1u<<14)
#define	DFSDM_DFSDM0_ISR_JCIP			(0x1u<<13)
#define	DFSDM_DFSDM0_ISR_AWDF			(0x1u<<4)
#define	DFSDM_DFSDM0_ISR_ROVRF			(0x1u<<3)
#define	DFSDM_DFSDM0_ISR_JOVRF			(0x1u<<2)
#define	DFSDM_DFSDM0_ISR_REOCF			(0x1u<<1)
#define	DFSDM_DFSDM0_ISR_JEOCF			(0x1u<<0)

// DFSDM1_ISR Configuration

#define	DFSDM_DFSDM1_ISR_SCDF			(0xFFu<<24)
#define	DFSDM_DFSDM1_ISR_SCDF_0			(0x1u<<24)
#define	DFSDM_DFSDM1_ISR_CKABF			(0xFFu<<16)
#define	DFSDM_DFSDM1_ISR_CKABF_0		(0x1u<<16)
#define	DFSDM_DFSDM1_ISR_RCIP			(0x1u<<14)
#define	DFSDM_DFSDM1_ISR_JCIP			(0x1u<<13)
#define	DFSDM_DFSDM1_ISR_AWDF			(0x1u<<4)
#define	DFSDM_DFSDM1_ISR_ROVRF			(0x1u<<3)
#define	DFSDM_DFSDM1_ISR_JOVRF			(0x1u<<2)
#define	DFSDM_DFSDM1_ISR_REOCF			(0x1u<<1)
#define	DFSDM_DFSDM1_ISR_JEOCF			(0x1u<<0)

// DFSDM2_ISR Configuration

#define	DFSDM_DFSDM2_ISR_SCDF			(0xFFu<<24)
#define	DFSDM_DFSDM2_ISR_SCDF_0			(0x1u<<24)
#define	DFSDM_DFSDM2_ISR_CKABF			(0xFFu<<16)
#define	DFSDM_DFSDM2_ISR_CKABF_0		(0x1u<<16)
#define	DFSDM_DFSDM2_ISR_RCIP			(0x1u<<14)
#define	DFSDM_DFSDM2_ISR_JCIP			(0x1u<<13)
#define	DFSDM_DFSDM2_ISR_AWDF			(0x1u<<4)
#define	DFSDM_DFSDM2_ISR_ROVRF			(0x1u<<3)
#define	DFSDM_DFSDM2_ISR_JOVRF			(0x1u<<2)
#define	DFSDM_DFSDM2_ISR_REOCF			(0x1u<<1)
#define	DFSDM_DFSDM2_ISR_JEOCF			(0x1u<<0)

// DFSDM3_ISR Configuration

#define	DFSDM_DFSDM3_ISR_SCDF			(0xFFu<<24)
#define	DFSDM_DFSDM3_ISR_SCDF_0			(0x1u<<24)
#define	DFSDM_DFSDM3_ISR_CKABF			(0xFFu<<16)
#define	DFSDM_DFSDM3_ISR_CKABF_0		(0x1u<<16)
#define	DFSDM_DFSDM3_ISR_RCIP			(0x1u<<14)
#define	DFSDM_DFSDM3_ISR_JCIP			(0x1u<<13)
#define	DFSDM_DFSDM3_ISR_AWDF			(0x1u<<4)
#define	DFSDM_DFSDM3_ISR_ROVRF			(0x1u<<3)
#define	DFSDM_DFSDM3_ISR_JOVRF			(0x1u<<2)
#define	DFSDM_DFSDM3_ISR_REOCF			(0x1u<<1)
#define	DFSDM_DFSDM3_ISR_JEOCF			(0x1u<<0)

// DFSDM0_ICR Configuration

#define	DFSDM_DFSDM0_ICR_CLRSCDF		(0xFFu<<24)
#define	DFSDM_DFSDM0_ICR_CLRSCDF_0		(0x1u<<24)
#define	DFSDM_DFSDM0_ICR_CLRCKABF		(0xFFu<<16)
#define	DFSDM_DFSDM0_ICR_CLRCKABF_0		(0x1u<<16)
#define	DFSDM_DFSDM0_ICR_CLRROVRF		(0x1u<<3)
#define	DFSDM_DFSDM0_ICR_CLRJOVRF		(0x1u<<2)

// DFSDM1_ICR Configuration

#define	DFSDM_DFSDM1_ICR_CLRSCDF		(0xFFu<<24)
#define	DFSDM_DFSDM1_ICR_CLRSCDF_0		(0x1u<<24)
#define	DFSDM_DFSDM1_ICR_CLRCKABF		(0xFFu<<16)
#define	DFSDM_DFSDM1_ICR_CLRCKABF_0		(0x1u<<16)
#define	DFSDM_DFSDM1_ICR_CLRROVRF		(0x1u<<3)
#define	DFSDM_DFSDM1_ICR_CLRJOVRF		(0x1u<<2)

// DFSDM2_ICR Configuration

#define	DFSDM_DFSDM2_ICR_CLRSCDF		(0xFFu<<24)
#define	DFSDM_DFSDM2_ICR_CLRSCDF_0		(0x1u<<24)
#define	DFSDM_DFSDM2_ICR_CLRCKABF		(0xFFu<<16)
#define	DFSDM_DFSDM2_ICR_CLRCKABF_0		(0x1u<<16)
#define	DFSDM_DFSDM2_ICR_CLRROVRF		(0x1u<<3)
#define	DFSDM_DFSDM2_ICR_CLRJOVRF		(0x1u<<2)

// DFSDM3_ICR Configuration

#define	DFSDM_DFSDM3_ICR_CLRSCDF		(0xFFu<<24)
#define	DFSDM_DFSDM3_ICR_CLRSCDF_0		(0x1u<<24)
#define	DFSDM_DFSDM3_ICR_CLRCKABF		(0xFFu<<16)
#define	DFSDM_DFSDM3_ICR_CLRCKABF_0		(0x1u<<16)
#define	DFSDM_DFSDM3_ICR_CLRROVRF		(0x1u<<3)
#define	DFSDM_DFSDM3_ICR_CLRJOVRF		(0x1u<<2)

// DFSDM0_JCHGR Configuration

#define	DFSDM_DFSDM0_JCHGR_JCHG			(0xFFu<<0)
#define	DFSDM_DFSDM0_JCHGR_JCHG_0		(0x1u<<0)

// DFSDM1_JCHGR Configuration

#define	DFSDM_DFSDM1_JCHGR_JCHG			(0xFFu<<0)
#define	DFSDM_DFSDM1_JCHGR_JCHG_0		(0x1u<<0)

// DFSDM2_JCHGR Configuration

#define	DFSDM_DFSDM2_JCHGR_JCHG			(0xFFu<<0)
#define	DFSDM_DFSDM2_JCHGR_JCHG_0		(0x1u<<0)

// DFSDM3_JCHGR Configuration

#define	DFSDM_DFSDM3_JCHGR_JCHG			(0xFFu<<0)
#define	DFSDM_DFSDM3_JCHGR_JCHG_0		(0x1u<<0)

// DFSDM0_FCR Configuration

#define	DFSDM_DFSDM0_FCR_FORD			(0x7u<<29)
#define	DFSDM_DFSDM0_FCR_FORD_0			(0x1u<<29)
#define	DFSDM_DFSDM0_FCR_FOSR			(0x3FFu<<16)
#define	DFSDM_DFSDM0_FCR_FOSR_0			(0x1u<<16)
#define	DFSDM_DFSDM0_FCR_IOSR			(0xFFu<<0)
#define	DFSDM_DFSDM0_FCR_IOSR_0			(0x1u<<0)

// DFSDM1_FCR Configuration

#define	DFSDM_DFSDM1_FCR_FORD			(0x7u<<29)
#define	DFSDM_DFSDM1_FCR_FORD_0			(0x1u<<29)
#define	DFSDM_DFSDM1_FCR_FOSR			(0x3FFu<<16)
#define	DFSDM_DFSDM1_FCR_FOSR_0			(0x1u<<16)
#define	DFSDM_DFSDM1_FCR_IOSR			(0xFFu<<0)
#define	DFSDM_DFSDM1_FCR_IOSR_0			(0x1u<<0)

// DFSDM2_FCR Configuration

#define	DFSDM_DFSDM2_FCR_FORD			(0x7u<<29)
#define	DFSDM_DFSDM2_FCR_FORD_0			(0x1u<<29)
#define	DFSDM_DFSDM2_FCR_FOSR			(0x3FFu<<16)
#define	DFSDM_DFSDM2_FCR_FOSR_0			(0x1u<<16)
#define	DFSDM_DFSDM2_FCR_IOSR			(0xFFu<<0)
#define	DFSDM_DFSDM2_FCR_IOSR_0			(0x1u<<0)

// DFSDM3_FCR Configuration

#define	DFSDM_DFSDM3_FCR_FORD			(0x7u<<29)
#define	DFSDM_DFSDM3_FCR_FORD_0			(0x1u<<29)
#define	DFSDM_DFSDM3_FCR_FOSR			(0x3FFu<<16)
#define	DFSDM_DFSDM3_FCR_FOSR_0			(0x1u<<16)
#define	DFSDM_DFSDM3_FCR_IOSR			(0xFFu<<0)
#define	DFSDM_DFSDM3_FCR_IOSR_0			(0x1u<<0)

// DFSDM0_JDATAR Configuration

#define	DFSDM_DFSDM0_JDATAR_JDATA		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM0_JDATAR_JDATA_0		(0x1u<<8)
#define	DFSDM_DFSDM0_JDATAR_JDATACH		(0x7u<<0)
#define	DFSDM_DFSDM0_JDATAR_JDATACH_0	(0x1u<<0)

// DFSDM1_JDATAR Configuration

#define	DFSDM_DFSDM1_JDATAR_JDATA		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM1_JDATAR_JDATA_0		(0x1u<<8)
#define	DFSDM_DFSDM1_JDATAR_JDATACH		(0x7u<<0)
#define	DFSDM_DFSDM1_JDATAR_JDATACH_0	(0x1u<<0)

// DFSDM2_JDATAR Configuration

#define	DFSDM_DFSDM2_JDATAR_JDATA		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM2_JDATAR_JDATA_0		(0x1u<<8)
#define	DFSDM_DFSDM2_JDATAR_JDATACH		(0x7u<<0)
#define	DFSDM_DFSDM2_JDATAR_JDATACH_0	(0x1u<<0)

// DFSDM3_JDATAR Configuration

#define	DFSDM_DFSDM3_JDATAR_JDATA		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM3_JDATAR_JDATA_0		(0x1u<<8)
#define	DFSDM_DFSDM3_JDATAR_JDATACH		(0x7u<<0)
#define	DFSDM_DFSDM3_JDATAR_JDATACH_0	(0x1u<<0)

// DFSDM0_RDATAR Configuration

#define	DFSDM_DFSDM0_RDATAR_RDATA		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM0_RDATAR_RDATA_0		(0x1u<<8)
#define	DFSDM_DFSDM0_RDATAR_RPEND		(0x1u<<4)
#define	DFSDM_DFSDM0_RDATAR_RDATACH		(0x7u<<0)
#define	DFSDM_DFSDM0_RDATAR_RDATACH_0	(0x1u<<0)

// DFSDM1_RDATAR Configuration

#define	DFSDM_DFSDM1_RDATAR_RDATA		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM1_RDATAR_RDATA_0		(0x1u<<8)
#define	DFSDM_DFSDM1_RDATAR_RPEND		(0x1u<<4)
#define	DFSDM_DFSDM1_RDATAR_RDATACH		(0x7u<<0)
#define	DFSDM_DFSDM1_RDATAR_RDATACH_0	(0x1u<<0)

// DFSDM2_RDATAR Configuration

#define	DFSDM_DFSDM2_RDATAR_RDATA		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM2_RDATAR_RDATA_0		(0x1u<<8)
#define	DFSDM_DFSDM2_RDATAR_RPEND		(0x1u<<4)
#define	DFSDM_DFSDM2_RDATAR_RDATACH		(0x7u<<0)
#define	DFSDM_DFSDM2_RDATAR_RDATACH_0	(0x1u<<0)

// DFSDM3_RDATAR Configuration

#define	DFSDM_DFSDM3_RDATAR_RDATA		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM3_RDATAR_RDATA_0		(0x1u<<8)
#define	DFSDM_DFSDM3_RDATAR_RPEND		(0x1u<<4)
#define	DFSDM_DFSDM3_RDATAR_RDATACH		(0x7u<<0)
#define	DFSDM_DFSDM3_RDATAR_RDATACH_0	(0x1u<<0)

// DFSDM0_AWHTR Configuration

#define	DFSDM_DFSDM0_AWHTR_AWHT			(0xFFFFFFu<<8)
#define	DFSDM_DFSDM0_AWHTR_AWHT_0		(0x1u<<8)
#define	DFSDM_DFSDM0_AWHTR_BKAWH		(0xFu<<0)
#define	DFSDM_DFSDM0_AWHTR_BKAWH_0		(0x1u<<0)

// DFSDM1_AWHTR Configuration

#define	DFSDM_DFSDM1_AWHTR_AWHT			(0xFFFFFFu<<8)
#define	DFSDM_DFSDM1_AWHTR_AWHT_0		(0x1u<<8)
#define	DFSDM_DFSDM1_AWHTR_BKAWH		(0xFu<<0)
#define	DFSDM_DFSDM1_AWHTR_BKAWH_0		(0x1u<<0)

// DFSDM2_AWHTR Configuration

#define	DFSDM_DFSDM2_AWHTR_AWHT			(0xFFFFFFu<<8)
#define	DFSDM_DFSDM2_AWHTR_AWHT_0		(0x1u<<8)
#define	DFSDM_DFSDM2_AWHTR_BKAWH		(0xFu<<0)
#define	DFSDM_DFSDM2_AWHTR_BKAWH_0		(0x1u<<0)

// DFSDM3_AWHTR Configuration

#define	DFSDM_DFSDM3_AWHTR_AWHT			(0xFFFFFFu<<8)
#define	DFSDM_DFSDM3_AWHTR_AWHT_0		(0x1u<<8)
#define	DFSDM_DFSDM3_AWHTR_BKAWH		(0xFu<<0)
#define	DFSDM_DFSDM3_AWHTR_BKAWH_0		(0x1u<<0)

// DFSDM0_AWLTR Configuration

#define	DFSDM_DFSDM0_AWLTR_AWLT			(0xFFFFFFu<<8)
#define	DFSDM_DFSDM0_AWLTR_AWLT_0		(0x1u<<8)
#define	DFSDM_DFSDM0_AWLTR_BKAWL		(0xFu<<0)
#define	DFSDM_DFSDM0_AWLTR_BKAWL_0		(0x1u<<0)

// DFSDM1_AWLTR Configuration

#define	DFSDM_DFSDM1_AWLTR_AWLT			(0xFFFFFFu<<8)
#define	DFSDM_DFSDM1_AWLTR_AWLT_0		(0x1u<<8)
#define	DFSDM_DFSDM1_AWLTR_BKAWL		(0xFu<<0)
#define	DFSDM_DFSDM1_AWLTR_BKAWL_0		(0x1u<<0)

// DFSDM2_AWLTR Configuration

#define	DFSDM_DFSDM2_AWLTR_AWLT			(0xFFFFFFu<<8)
#define	DFSDM_DFSDM2_AWLTR_AWLT_0		(0x1u<<8)
#define	DFSDM_DFSDM2_AWLTR_BKAWL		(0xFu<<0)
#define	DFSDM_DFSDM2_AWLTR_BKAWL_0		(0x1u<<0)

// DFSDM3_AWLTR Configuration

#define	DFSDM_DFSDM3_AWLTR_AWLT			(0xFFFFFFu<<8)
#define	DFSDM_DFSDM3_AWLTR_AWLT_0		(0x1u<<8)
#define	DFSDM_DFSDM3_AWLTR_BKAWL		(0xFu<<0)
#define	DFSDM_DFSDM3_AWLTR_BKAWL_0		(0x1u<<0)

// DFSDM0_AWSR Configuration

#define	DFSDM_DFSDM0_AWSR_AWHTF			(0xFFu<<8)
#define	DFSDM_DFSDM0_AWSR_AWHTF_0		(0x1u<<8)
#define	DFSDM_DFSDM0_AWSR_AWLTF			(0xFFu<<0)
#define	DFSDM_DFSDM0_AWSR_AWLTF_0		(0x1u<<0)

// DFSDM1_AWSR Configuration

#define	DFSDM_DFSDM1_AWSR_AWHTF			(0xFFu<<8)
#define	DFSDM_DFSDM1_AWSR_AWHTF_0		(0x1u<<8)
#define	DFSDM_DFSDM1_AWSR_AWLTF			(0xFFu<<0)
#define	DFSDM_DFSDM1_AWSR_AWLTF_0		(0x1u<<0)

// DFSDM2_AWSR Configuration

#define	DFSDM_DFSDM2_AWSR_AWHTF			(0xFFu<<8)
#define	DFSDM_DFSDM2_AWSR_AWHTF_0		(0x1u<<8)
#define	DFSDM_DFSDM2_AWSR_AWLTF			(0xFFu<<0)
#define	DFSDM_DFSDM2_AWSR_AWLTF_0		(0x1u<<0)

// DFSDM3_AWSR Configuration

#define	DFSDM_DFSDM3_AWSR_AWHTF			(0xFFu<<8)
#define	DFSDM_DFSDM3_AWSR_AWHTF_0		(0x1u<<8)
#define	DFSDM_DFSDM3_AWSR_AWLTF			(0xFFu<<0)
#define	DFSDM_DFSDM3_AWSR_AWLTF_0		(0x1u<<0)

// DFSDM0_AWCFR Configuration

#define	DFSDM_DFSDM0_AWCFR_CLRAWHTF		(0xFFu<<8)
#define	DFSDM_DFSDM0_AWCFR_CLRAWHTF_0	(0x1u<<8)
#define	DFSDM_DFSDM0_AWCFR_CLRAWLTF		(0xFFu<<0)
#define	DFSDM_DFSDM0_AWCFR_CLRAWLTF_0	(0x1u<<0)

// DFSDM1_AWCFR Configuration

#define	DFSDM_DFSDM1_AWCFR_CLRAWHTF		(0xFFu<<8)
#define	DFSDM_DFSDM1_AWCFR_CLRAWHTF_0	(0x1u<<8)
#define	DFSDM_DFSDM1_AWCFR_CLRAWLTF		(0xFFu<<0)
#define	DFSDM_DFSDM1_AWCFR_CLRAWLTF_0	(0x1u<<0)

// DFSDM2_AWCFR Configuration

#define	DFSDM_DFSDM2_AWCFR_CLRAWHTF		(0xFFu<<8)
#define	DFSDM_DFSDM2_AWCFR_CLRAWHTF_0	(0x1u<<8)
#define	DFSDM_DFSDM2_AWCFR_CLRAWLTF		(0xFFu<<0)
#define	DFSDM_DFSDM2_AWCFR_CLRAWLTF_0	(0x1u<<0)

// DFSDM3_AWCFR Configuration

#define	DFSDM_DFSDM3_AWCFR_CLRAWHTF		(0xFFu<<8)
#define	DFSDM_DFSDM3_AWCFR_CLRAWHTF_0	(0x1u<<8)
#define	DFSDM_DFSDM3_AWCFR_CLRAWLTF		(0xFFu<<0)
#define	DFSDM_DFSDM3_AWCFR_CLRAWLTF_0	(0x1u<<0)

// DFSDM0_EXMAX Configuration

#define	DFSDM_DFSDM0_EXMAX_EXMAX		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM0_EXMAX_EXMAX_0		(0x1u<<8)
#define	DFSDM_DFSDM0_EXMAX_EXMAXCH		(0x7u<<0)
#define	DFSDM_DFSDM0_EXMAX_EXMAXCH_0	(0x1u<<0)

// DFSDM1_EXMAX Configuration

#define	DFSDM_DFSDM1_EXMAX_EXMAX		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM1_EXMAX_EXMAX_0		(0x1u<<8)
#define	DFSDM_DFSDM1_EXMAX_EXMAXCH		(0x7u<<0)
#define	DFSDM_DFSDM1_EXMAX_EXMAXCH_0	(0x1u<<0)

// DFSDM2_EXMAX Configuration

#define	DFSDM_DFSDM2_EXMAX_EXMAX		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM2_EXMAX_EXMAX_0		(0x1u<<8)
#define	DFSDM_DFSDM2_EXMAX_EXMAXCH		(0x7u<<0)
#define	DFSDM_DFSDM2_EXMAX_EXMAXCH_0	(0x1u<<0)

// DFSDM3_EXMAX Configuration

#define	DFSDM_DFSDM3_EXMAX_EXMAX		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM3_EXMAX_EXMAX_0		(0x1u<<8)
#define	DFSDM_DFSDM3_EXMAX_EXMAXCH		(0x7u<<0)
#define	DFSDM_DFSDM3_EXMAX_EXMAXCH_0	(0x1u<<0)

// DFSDM0_EXMIN Configuration

#define	DFSDM_DFSDM0_EXMIN_EXMIN		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM0_EXMIN_EXMIN_0		(0x1u<<8)
#define	DFSDM_DFSDM0_EXMIN_EXMINCH		(0x7u<<0)
#define	DFSDM_DFSDM0_EXMIN_EXMINCH_0	(0x1u<<0)

// DFSDM1_EXMIN Configuration

#define	DFSDM_DFSDM1_EXMIN_EXMIN		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM1_EXMIN_EXMIN_0		(0x1u<<8)
#define	DFSDM_DFSDM1_EXMIN_EXMINCH		(0x7u<<0)
#define	DFSDM_DFSDM1_EXMIN_EXMINCH_0	(0x1u<<0)

// DFSDM2_EXMIN Configuration

#define	DFSDM_DFSDM2_EXMIN_EXMIN		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM2_EXMIN_EXMIN_0		(0x1u<<8)
#define	DFSDM_DFSDM2_EXMIN_EXMINCH		(0x7u<<0)
#define	DFSDM_DFSDM2_EXMIN_EXMINCH_0	(0x1u<<0)

// DFSDM3_EXMIN Configuration

#define	DFSDM_DFSDM3_EXMIN_EXMIN		(0xFFFFFFu<<8)
#define	DFSDM_DFSDM3_EXMIN_EXMIN_0		(0x1u<<8)
#define	DFSDM_DFSDM3_EXMIN_EXMINCH		(0x7u<<0)
#define	DFSDM_DFSDM3_EXMIN_EXMINCH_0	(0x1u<<0)

// DFSDM0_CNVTIMR Configuration

#define	DFSDM_DFSDM0_CNVTIMR_CNVCNT		(0xFFFFFFFu<<4)
#define	DFSDM_DFSDM0_CNVTIMR_CNVCNT_0	(0x1u<<4)

// DFSDM1_CNVTIMR Configuration

#define	DFSDM_DFSDM1_CNVTIMR_CNVCNT		(0xFFFFFFFu<<4)
#define	DFSDM_DFSDM1_CNVTIMR_CNVCNT_0	(0x1u<<4)

// DFSDM2_CNVTIMR Configuration

#define	DFSDM_DFSDM2_CNVTIMR_CNVCNT		(0xFFFFFFFu<<4)
#define	DFSDM_DFSDM2_CNVTIMR_CNVCNT_0	(0x1u<<4)

// DFSDM3_CNVTIMR Configuration

#define	DFSDM_DFSDM3_CNVTIMR_CNVCNT		(0xFFFFFFFu<<4)
#define	DFSDM_DFSDM3_CNVTIMR_CNVCNT_0	(0x1u<<4)
