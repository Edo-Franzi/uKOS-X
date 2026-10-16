/*
; stm32L4R5_sai.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_sai equates.
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

// SAI address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	ACR1;
	volatile	uint32_t	ACR2;
	volatile	uint32_t	AFRCR;
	volatile	uint32_t	ASLOTR;
	volatile	uint32_t	AIM;
	volatile	uint32_t	ASR;
	volatile	uint32_t	ACLRFR;
	volatile	uint32_t	ADR;
	volatile	uint32_t	BCR1;
	volatile	uint32_t	BCR2;
	volatile	uint32_t	BFRCR;
	volatile	uint32_t	BSLOTR;
	volatile	uint32_t	BIM;
	volatile	uint32_t	BSR;
	volatile	uint32_t	BCLRFR;
	volatile	uint32_t	BDR;
} SAI_TypeDef;

#if (defined(__cplusplus))
#define	SAI1	reinterpret_cast<SAI_TypeDef *>(0x40015400u)
#define	SAI2	reinterpret_cast<SAI_TypeDef *>(0x40015800u)

#else
#define	SAI1	((SAI_TypeDef *)0x40015400u)
#define	SAI2	((SAI_TypeDef *)0x40015800u)
#endif

// ACR1 Configuration

#define	SAI_ACR1_MODE		(0x3u<<0)
#define	SAI_ACR1_MODE_0		(0x1u<<0)
#define	SAI_ACR1_PRTCFG		(0x3u<<2)
#define	SAI_ACR1_PRTCFG_0	(0x1u<<2)
#define	SAI_ACR1_DS			(0x7u<<5)
#define	SAI_ACR1_DS_0		(0x1u<<5)
#define	SAI_ACR1_LSBFIRST	(0x1u<<8)
#define	SAI_ACR1_CKSTR		(0x1u<<9)
#define	SAI_ACR1_SYNCEN		(0x3u<<10)
#define	SAI_ACR1_SYNCEN_0	(0x1u<<10)
#define	SAI_ACR1_MONO		(0x1u<<12)
#define	SAI_ACR1_OUTDRI		(0x1u<<13)
#define	SAI_ACR1_SAIAEN		(0x1u<<16)
#define	SAI_ACR1_DMAEN		(0x1u<<17)
#define	SAI_ACR1_NODIV		(0x1u<<19)
#define	SAI_ACR1_MCJDIV		(0xFu<<20)
#define	SAI_ACR1_MCJDIV_0	(0x1u<<20)

// ACR2 Configuration

#define	SAI_ACR2_FTH		(0x7u<<0)
#define	SAI_ACR2_FTH_0		(0x1u<<0)
#define	SAI_ACR2_FFLUS		(0x1u<<3)
#define	SAI_ACR2_TRIS		(0x1u<<4)
#define	SAI_ACR2_MUTE		(0x1u<<5)
#define	SAI_ACR2_MUTEVAL	(0x1u<<6)
#define	SAI_ACR2_MUTECN		(0x3Fu<<7)
#define	SAI_ACR2_MUTECN_0	(0x1u<<7)
#define	SAI_ACR2_CPL		(0x1u<<13)
#define	SAI_ACR2_COMP		(0x3u<<14)
#define	SAI_ACR2_COMP_0		(0x1u<<14)

// AFRCR Configuration

#define	SAI_AFRCR_FRL		(0xFFu<<0)
#define	SAI_AFRCR_FRL_0		(0x1u<<0)
#define	SAI_AFRCR_FSALL		(0x7Fu<<8)
#define	SAI_AFRCR_FSALL_0	(0x1u<<8)
#define	SAI_AFRCR_FSDEF		(0x1u<<16)
#define	SAI_AFRCR_FSPOL		(0x1u<<17)
#define	SAI_AFRCR_FSOFF		(0x1u<<18)

// ASLOTR Configuration

#define	SAI_ASLOTR_FBOFF	(0x1Fu<<0)
#define	SAI_ASLOTR_FBOFF_0	(0x1u<<0)
#define	SAI_ASLOTR_SLOTSZ	(0x3u<<6)
#define	SAI_ASLOTR_SLOTSZ_0	(0x1u<<6)
#define	SAI_ASLOTR_NBSLOT	(0xFu<<8)
#define	SAI_ASLOTR_NBSLOT_0	(0x1u<<8)
#define	SAI_ASLOTR_SLOTEN	(0xFFFFu<<16)
#define	SAI_ASLOTR_SLOTEN_0	(0x1u<<16)

// AIM Configuration

#define	SAI_AIM_OVRUDRIE	(0x1u<<0)
#define	SAI_AIM_MUTEDET		(0x1u<<1)
#define	SAI_AIM_WCKCFG		(0x1u<<2)
#define	SAI_AIM_FREQIE		(0x1u<<3)
#define	SAI_AIM_CNRDYIE		(0x1u<<4)
#define	SAI_AIM_AFSDETIE	(0x1u<<5)
#define	SAI_AIM_LFSDET		(0x1u<<6)

// ASR Configuration

#define	SAI_ASR_OVRUDR		(0x1u<<0)
#define	SAI_ASR_MUTEDET		(0x1u<<1)
#define	SAI_ASR_WCKCFG		(0x1u<<2)
#define	SAI_ASR_FREQ		(0x1u<<3)
#define	SAI_ASR_CNRDY		(0x1u<<4)
#define	SAI_ASR_AFSDET		(0x1u<<5)
#define	SAI_ASR_LFSDET		(0x1u<<6)
#define	SAI_ASR_FLVL		(0x7u<<16)
#define	SAI_ASR_FLVL_0		(0x1u<<16)

// ACLRFR Configuration

#define	SAI_ACLRFR_OVRUDR	(0x1u<<0)
#define	SAI_ACLRFR_MUTEDET	(0x1u<<1)
#define	SAI_ACLRFR_WCKCFG	(0x1u<<2)
#define	SAI_ACLRFR_CNRDY	(0x1u<<4)
#define	SAI_ACLRFR_CAFSDET	(0x1u<<5)
#define	SAI_ACLRFR_LFSDET	(0x1u<<6)

// ADR Configuration

#define	SAI_ADR_DATA		(0xFFFFFFFFu<<0)
#define	SAI_ADR_DATA_0		(0x1u<<0)

// BCR1 Configuration

#define	SAI_BCR1_MODE		(0x3u<<0)
#define	SAI_BCR1_MODE_0		(0x1u<<0)
#define	SAI_BCR1_PRTCFG		(0x3u<<2)
#define	SAI_BCR1_PRTCFG_0	(0x1u<<2)
#define	SAI_BCR1_DS			(0x7u<<5)
#define	SAI_BCR1_DS_0		(0x1u<<5)
#define	SAI_BCR1_LSBFIRST	(0x1u<<8)
#define	SAI_BCR1_CKSTR		(0x1u<<9)
#define	SAI_BCR1_SYNCEN		(0x3u<<10)
#define	SAI_BCR1_SYNCEN_0	(0x1u<<10)
#define	SAI_BCR1_MONO		(0x1u<<12)
#define	SAI_BCR1_OUTDRI		(0x1u<<13)
#define	SAI_BCR1_SAIBEN		(0x1u<<16)
#define	SAI_BCR1_DMAEN		(0x1u<<17)
#define	SAI_BCR1_NODIV		(0x1u<<19)
#define	SAI_BCR1_MCJDIV		(0xFu<<20)
#define	SAI_BCR1_MCJDIV_0	(0x1u<<20)

// BCR2 Configuration

#define	SAI_BCR2_FTH		(0x7u<<0)
#define	SAI_BCR2_FTH_0		(0x1u<<0)
#define	SAI_BCR2_FFLUS		(0x1u<<3)
#define	SAI_BCR2_TRIS		(0x1u<<4)
#define	SAI_BCR2_MUTE		(0x1u<<5)
#define	SAI_BCR2_MUTEVAL	(0x1u<<6)
#define	SAI_BCR2_MUTECN		(0x3Fu<<7)
#define	SAI_BCR2_MUTECN_0	(0x1u<<7)
#define	SAI_BCR2_CPL		(0x1u<<13)
#define	SAI_BCR2_COMP		(0x3u<<14)
#define	SAI_BCR2_COMP_0		(0x1u<<14)

// BFRCR Configuration

#define	SAI_BFRCR_FRL		(0xFFu<<0)
#define	SAI_BFRCR_FRL_0		(0x1u<<0)
#define	SAI_BFRCR_FSALL		(0x7Fu<<8)
#define	SAI_BFRCR_FSALL_0	(0x1u<<8)
#define	SAI_BFRCR_FSDEF		(0x1u<<16)
#define	SAI_BFRCR_FSPOL		(0x1u<<17)
#define	SAI_BFRCR_FSOFF		(0x1u<<18)

// BSLOTR Configuration

#define	SAI_BSLOTR_FBOFF	(0x1Fu<<0)
#define	SAI_BSLOTR_FBOFF_0	(0x1u<<0)
#define	SAI_BSLOTR_SLOTSZ	(0x3u<<6)
#define	SAI_BSLOTR_SLOTSZ_0	(0x1u<<6)
#define	SAI_BSLOTR_NBSLOT	(0xFu<<8)
#define	SAI_BSLOTR_NBSLOT_0	(0x1u<<8)
#define	SAI_BSLOTR_SLOTEN	(0xFFFFu<<16)
#define	SAI_BSLOTR_SLOTEN_0	(0x1u<<16)

// BIM Configuration

#define	SAI_BIM_OVRUDRIE	(0x1u<<0)
#define	SAI_BIM_MUTEDET		(0x1u<<1)
#define	SAI_BIM_WCKCFG		(0x1u<<2)
#define	SAI_BIM_FREQIE		(0x1u<<3)
#define	SAI_BIM_CNRDYIE		(0x1u<<4)
#define	SAI_BIM_AFSDETIE	(0x1u<<5)
#define	SAI_BIM_LFSDETIE	(0x1u<<6)

// BSR Configuration

#define	SAI_BSR_OVRUDR		(0x1u<<0)
#define	SAI_BSR_MUTEDET		(0x1u<<1)
#define	SAI_BSR_WCKCFG		(0x1u<<2)
#define	SAI_BSR_FREQ		(0x1u<<3)
#define	SAI_BSR_CNRDY		(0x1u<<4)
#define	SAI_BSR_AFSDET		(0x1u<<5)
#define	SAI_BSR_LFSDET		(0x1u<<6)
#define	SAI_BSR_FLVL		(0x7u<<16)
#define	SAI_BSR_FLVL_0		(0x1u<<16)

// BCLRFR Configuration

#define	SAI_BCLRFR_OVRUDR	(0x1u<<0)
#define	SAI_BCLRFR_MUTEDET	(0x1u<<1)
#define	SAI_BCLRFR_WCKCFG	(0x1u<<2)
#define	SAI_BCLRFR_CNRDY	(0x1u<<4)
#define	SAI_BCLRFR_CAFSDET	(0x1u<<5)
#define	SAI_BCLRFR_LFSDET	(0x1u<<6)

// BDR Configuration

#define	SAI_BDR_DATA		(0xFFFFFFFFu<<0)
#define	SAI_BDR_DATA_0		(0x1u<<0)
