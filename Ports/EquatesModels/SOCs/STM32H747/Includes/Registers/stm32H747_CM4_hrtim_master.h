/*
; stm32H747_CM4_hrtim_master.
; ===========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM4_hrtim_master equates.
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

// HRTIM_MASTER address definitions
// --------------------------------

typedef struct {
	volatile	uint32_t	MCR;
	volatile	uint32_t	MISR;
	volatile	uint32_t	MICR;
	volatile	uint32_t	MDIER4;
	volatile	uint32_t	MCNTR;
	volatile	uint32_t	MPER;
	volatile	uint32_t	MREP;
	volatile	uint32_t	MCMP1R;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	MCMP2R;
	volatile	uint32_t	MCMP3R;
	volatile	uint32_t	MCMP4R;
} HRTIM_MASTER_TypeDef;

#if (defined(__cplusplus))
#define	HRTIM_MASTER	reinterpret_cast<HRTIM_MASTER_TypeDef *>(0x40017400u)

#else
#define	HRTIM_MASTER	((HRTIM_MASTER_TypeDef *)0x40017400u)
#endif

// MCR Configuration

#define	HRTIM_MASTER_MCR_CK_PSC		(0x7u<<0)
#define	HRTIM_MASTER_MCR_CK_PSC_0	(0x1u<<0)
#define	HRTIM_MASTER_MCR_CONT		(0x1u<<3)
#define	HRTIM_MASTER_MCR_RETRIG		(0x1u<<4)
#define	HRTIM_MASTER_MCR_HALF		(0x1u<<5)
#define	HRTIM_MASTER_MCR_SYNC_IN	(0x3u<<8)
#define	HRTIM_MASTER_MCR_SYNC_IN_0	(0x1u<<8)
#define	HRTIM_MASTER_MCR_SYNCRSTM	(0x1u<<10)
#define	HRTIM_MASTER_MCR_SYNCSTRTM	(0x1u<<11)
#define	HRTIM_MASTER_MCR_SYNC_OUT	(0x3u<<12)
#define	HRTIM_MASTER_MCR_SYNC_OUT_0	(0x1u<<12)
#define	HRTIM_MASTER_MCR_SYNC_SRC	(0x3u<<14)
#define	HRTIM_MASTER_MCR_SYNC_SRC_0	(0x1u<<14)
#define	HRTIM_MASTER_MCR_MCEN		(0x1u<<16)
#define	HRTIM_MASTER_MCR_TACEN		(0x1u<<17)
#define	HRTIM_MASTER_MCR_TBCEN		(0x1u<<18)
#define	HRTIM_MASTER_MCR_TCCEN		(0x1u<<19)
#define	HRTIM_MASTER_MCR_TDCEN		(0x1u<<20)
#define	HRTIM_MASTER_MCR_TECEN		(0x1u<<21)
#define	HRTIM_MASTER_MCR_DACSYNC	(0x3u<<25)
#define	HRTIM_MASTER_MCR_DACSYNC_0	(0x1u<<25)
#define	HRTIM_MASTER_MCR_PREEN		(0x1u<<27)
#define	HRTIM_MASTER_MCR_MREPU		(0x1u<<29)
#define	HRTIM_MASTER_MCR_BRSTDMA	(0x3u<<30)
#define	HRTIM_MASTER_MCR_BRSTDMA_0	(0x1u<<30)

// MISR Configuration

#define	HRTIM_MASTER_MISR_MCMP1		(0x1u<<0)
#define	HRTIM_MASTER_MISR_MCMP2		(0x1u<<1)
#define	HRTIM_MASTER_MISR_MCMP3		(0x1u<<2)
#define	HRTIM_MASTER_MISR_MCMP4		(0x1u<<3)
#define	HRTIM_MASTER_MISR_MREP		(0x1u<<4)
#define	HRTIM_MASTER_MISR_SYNC		(0x1u<<5)
#define	HRTIM_MASTER_MISR_MUPD		(0x1u<<6)

// MICR Configuration

#define	HRTIM_MASTER_MICR_MCMP1C	(0x1u<<0)
#define	HRTIM_MASTER_MICR_MCMP2C	(0x1u<<1)
#define	HRTIM_MASTER_MICR_MCMP3C	(0x1u<<2)
#define	HRTIM_MASTER_MICR_MCMP4C	(0x1u<<3)
#define	HRTIM_MASTER_MICR_MREPC		(0x1u<<4)
#define	HRTIM_MASTER_MICR_SYNCC		(0x1u<<5)
#define	HRTIM_MASTER_MICR_MUPDC		(0x1u<<6)

// MDIER4 Configuration

#define	HRTIM_MASTER_MDIER4_MCMP1IE	(0x1u<<0)
#define	HRTIM_MASTER_MDIER4_MCMP2IE	(0x1u<<1)
#define	HRTIM_MASTER_MDIER4_MCMP3IE	(0x1u<<2)
#define	HRTIM_MASTER_MDIER4_MCMP4IE	(0x1u<<3)
#define	HRTIM_MASTER_MDIER4_MREPIE	(0x1u<<4)
#define	HRTIM_MASTER_MDIER4_SYNCIE	(0x1u<<5)
#define	HRTIM_MASTER_MDIER4_MUPDIE	(0x1u<<6)
#define	HRTIM_MASTER_MDIER4_MCMP1DE	(0x1u<<16)
#define	HRTIM_MASTER_MDIER4_MCMP2DE	(0x1u<<17)
#define	HRTIM_MASTER_MDIER4_MCMP3DE	(0x1u<<18)
#define	HRTIM_MASTER_MDIER4_MCMP4DE	(0x1u<<19)
#define	HRTIM_MASTER_MDIER4_MREPDE	(0x1u<<20)
#define	HRTIM_MASTER_MDIER4_SYNCDE	(0x1u<<21)
#define	HRTIM_MASTER_MDIER4_MUPDDE	(0x1u<<22)

// MCNTR Configuration

#define	HRTIM_MASTER_MCNTR_MCNT		(0xFFFFu<<0)
#define	HRTIM_MASTER_MCNTR_MCNT_0	(0x1u<<0)

// MPER Configuration

#define	HRTIM_MASTER_MPER_MPER		(0xFFFFu<<0)
#define	HRTIM_MASTER_MPER_MPER_0	(0x1u<<0)

// MREP Configuration

#define	HRTIM_MASTER_MREP_MREP		(0xFFu<<0)
#define	HRTIM_MASTER_MREP_MREP_0	(0x1u<<0)

// MCMP1R Configuration

#define	HRTIM_MASTER_MCMP1R_MCMP1	(0xFFFFu<<0)
#define	HRTIM_MASTER_MCMP1R_MCMP1_0	(0x1u<<0)

// MCMP2R Configuration

#define	HRTIM_MASTER_MCMP2R_MCMP2	(0xFFFFu<<0)
#define	HRTIM_MASTER_MCMP2R_MCMP2_0	(0x1u<<0)

// MCMP3R Configuration

#define	HRTIM_MASTER_MCMP3R_MCMP3	(0xFFFFu<<0)
#define	HRTIM_MASTER_MCMP3R_MCMP3_0	(0x1u<<0)

// MCMP4R Configuration

#define	HRTIM_MASTER_MCMP4R_MCMP4	(0xFFFFu<<0)
#define	HRTIM_MASTER_MCMP4R_MCMP4_0	(0x1u<<0)
