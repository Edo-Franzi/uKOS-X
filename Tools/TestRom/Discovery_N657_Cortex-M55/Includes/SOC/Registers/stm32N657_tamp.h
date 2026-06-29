/*
; stm32N657_tamp.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_tamp equates.
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

// TAMP address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CR1;
	volatile	uint32_t	CR2;
	volatile	uint32_t	CR3;
	volatile	uint32_t	FLTCR;
	volatile	uint32_t	ATCR1;
	volatile	uint32_t	ATSEEDR;
	volatile	uint32_t	ATOR;
	volatile	uint32_t	ATCR2;
	volatile	uint32_t	SECCFGR;
	volatile	uint32_t	PRIVCFGR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	IER;
	volatile	uint32_t	SR;
	volatile	uint32_t	MISR;
	volatile	uint32_t	SMISR;
	volatile	uint32_t	SCR;
	volatile	uint32_t	COUNT1R;
	volatile	uint32_t	RESERVED1[3];
	volatile	uint32_t	OR;
	volatile	uint32_t	RPCFGR;
	volatile	uint32_t	RESERVED2[42];
	volatile	uint32_t	BKP0R;
	volatile	uint32_t	BKP1R;
	volatile	uint32_t	BKP2R;
	volatile	uint32_t	BKP3R;
	volatile	uint32_t	BKP4R;
	volatile	uint32_t	BKP5R;
	volatile	uint32_t	BKP6R;
	volatile	uint32_t	BKP7R;
	volatile	uint32_t	BKP8R;
	volatile	uint32_t	BKP9R;
	volatile	uint32_t	BKP10R;
	volatile	uint32_t	BKP11R;
	volatile	uint32_t	BKP12R;
	volatile	uint32_t	BKP13R;
	volatile	uint32_t	BKP14R;
	volatile	uint32_t	BKP15R;
	volatile	uint32_t	BKP16R;
	volatile	uint32_t	BKP17R;
	volatile	uint32_t	BKP18R;
	volatile	uint32_t	BKP19R;
	volatile	uint32_t	BKP20R;
	volatile	uint32_t	BKP21R;
	volatile	uint32_t	BKP22R;
	volatile	uint32_t	BKP23R;
	volatile	uint32_t	BKP24R;
	volatile	uint32_t	BKP25R;
	volatile	uint32_t	BKP26R;
	volatile	uint32_t	BKP27R;
	volatile	uint32_t	BKP28R;
	volatile	uint32_t	BKP29R;
	volatile	uint32_t	BKP30R;
	volatile	uint32_t	BKP31R;
} TAMP_TypeDef;

#if (defined(__cplusplus))
#define	TAMP_NS	reinterpret_cast<TAMP_TypeDef *>(0x46004400u)
#define	TAMP_S	reinterpret_cast<TAMP_TypeDef *>(0x56004400u)

#else
#define	TAMP_NS	((TAMP_TypeDef *)0x46004400u)
#define	TAMP_S	((TAMP_TypeDef *)0x56004400u)
#endif

// CR1 Configuration

#define	TAMP_CR1_ITAMP11E				(0x1u<<26)
#define	TAMP_CR1_ITAMP9E				(0x1u<<24)
#define	TAMP_CR1_ITAMP8E				(0x1u<<23)
#define	TAMP_CR1_ITAMP7E				(0x1u<<22)
#define	TAMP_CR1_ITAMP6E				(0x1u<<21)
#define	TAMP_CR1_ITAMP5E				(0x1u<<20)
#define	TAMP_CR1_ITAMP4E				(0x1u<<19)
#define	TAMP_CR1_ITAMP3E				(0x1u<<18)
#define	TAMP_CR1_ITAMP2E				(0x1u<<17)
#define	TAMP_CR1_ITAMP1E				(0x1u<<16)
#define	TAMP_CR1_TAMP7E					(0x1u<<6)
#define	TAMP_CR1_TAMP6E					(0x1u<<5)
#define	TAMP_CR1_TAMP5E					(0x1u<<4)
#define	TAMP_CR1_TAMP4E					(0x1u<<3)
#define	TAMP_CR1_TAMP3E					(0x1u<<2)
#define	TAMP_CR1_TAMP2E					(0x1u<<1)
#define	TAMP_CR1_TAMP1E					(0x1u<<0)

#define	TAMP_CR1_ITAMP11E_B_0X0			(0x0u<<26)
#define	TAMP_CR1_ITAMP11E_B_0X1			(0x1u<<26)
#define	TAMP_CR1_ITAMP9E_B_0X0			(0x0u<<24)
#define	TAMP_CR1_ITAMP9E_B_0X1			(0x1u<<24)
#define	TAMP_CR1_ITAMP8E_B_0X0			(0x0u<<23)
#define	TAMP_CR1_ITAMP8E_B_0X1			(0x1u<<23)
#define	TAMP_CR1_ITAMP7E_B_0X0			(0x0u<<22)
#define	TAMP_CR1_ITAMP7E_B_0X1			(0x1u<<22)
#define	TAMP_CR1_ITAMP6E_B_0X0			(0x0u<<21)
#define	TAMP_CR1_ITAMP6E_B_0X1			(0x1u<<21)
#define	TAMP_CR1_ITAMP5E_B_0X0			(0x0u<<20)
#define	TAMP_CR1_ITAMP5E_B_0X1			(0x1u<<20)
#define	TAMP_CR1_ITAMP4E_B_0X0			(0x0u<<19)
#define	TAMP_CR1_ITAMP4E_B_0X1			(0x1u<<19)
#define	TAMP_CR1_ITAMP3E_B_0X0			(0x0u<<18)
#define	TAMP_CR1_ITAMP3E_B_0X1			(0x1u<<18)
#define	TAMP_CR1_ITAMP2E_B_0X0			(0x0u<<17)
#define	TAMP_CR1_ITAMP2E_B_0X1			(0x1u<<17)
#define	TAMP_CR1_ITAMP1E_B_0X0			(0x0u<<16)
#define	TAMP_CR1_ITAMP1E_B_0X1			(0x1u<<16)
#define	TAMP_CR1_TAMP7E_B_0X0			(0x0u<<6)
#define	TAMP_CR1_TAMP7E_B_0X1			(0x1u<<6)
#define	TAMP_CR1_TAMP6E_B_0X0			(0x0u<<5)
#define	TAMP_CR1_TAMP6E_B_0X1			(0x1u<<5)
#define	TAMP_CR1_TAMP5E_B_0X0			(0x0u<<4)
#define	TAMP_CR1_TAMP5E_B_0X1			(0x1u<<4)
#define	TAMP_CR1_TAMP4E_B_0X0			(0x0u<<3)
#define	TAMP_CR1_TAMP4E_B_0X1			(0x1u<<3)
#define	TAMP_CR1_TAMP3E_B_0X0			(0x0u<<2)
#define	TAMP_CR1_TAMP3E_B_0X1			(0x1u<<2)
#define	TAMP_CR1_TAMP2E_B_0X0			(0x0u<<1)
#define	TAMP_CR1_TAMP2E_B_0X1			(0x1u<<1)
#define	TAMP_CR1_TAMP1E_B_0X0			(0x0u<<0)
#define	TAMP_CR1_TAMP1E_B_0X1			(0x1u<<0)

// CR2 Configuration

#define	TAMP_CR2_TAMP7TRG				(0x1u<<30)
#define	TAMP_CR2_TAMP6TRG				(0x1u<<29)
#define	TAMP_CR2_TAMP5TRG				(0x1u<<28)
#define	TAMP_CR2_TAMP4TRG				(0x1u<<27)
#define	TAMP_CR2_TAMP3TRG				(0x1u<<26)
#define	TAMP_CR2_TAMP2TRG				(0x1u<<25)
#define	TAMP_CR2_TAMP1TRG				(0x1u<<24)
#define	TAMP_CR2_BKERASE				(0x1u<<23)
#define	TAMP_CR2_BKBLOCK				(0x1u<<22)
#define	TAMP_CR2_TAMP3MSK				(0x1u<<18)
#define	TAMP_CR2_TAMP2MSK				(0x1u<<17)
#define	TAMP_CR2_TAMP1MSK				(0x1u<<16)
#define	TAMP_CR2_TAMP7POM				(0x1u<<6)
#define	TAMP_CR2_TAMP6POM				(0x1u<<5)
#define	TAMP_CR2_TAMP5POM				(0x1u<<4)
#define	TAMP_CR2_TAMP4POM				(0x1u<<3)
#define	TAMP_CR2_TAMP3POM				(0x1u<<2)
#define	TAMP_CR2_TAMP2POM				(0x1u<<1)
#define	TAMP_CR2_TAMP1POM				(0x1u<<0)

#define	TAMP_CR2_TAMP7TRG_B_0X0			(0x0u<<30)
#define	TAMP_CR2_TAMP7TRG_B_0X1			(0x1u<<30)
#define	TAMP_CR2_TAMP6TRG_B_0X0			(0x0u<<29)
#define	TAMP_CR2_TAMP6TRG_B_0X1			(0x1u<<29)
#define	TAMP_CR2_TAMP5TRG_B_0X0			(0x0u<<28)
#define	TAMP_CR2_TAMP5TRG_B_0X1			(0x1u<<28)
#define	TAMP_CR2_TAMP4TRG_B_0X0			(0x0u<<27)
#define	TAMP_CR2_TAMP4TRG_B_0X1			(0x1u<<27)
#define	TAMP_CR2_TAMP3TRG_B_0X0			(0x0u<<26)
#define	TAMP_CR2_TAMP3TRG_B_0X1			(0x1u<<26)
#define	TAMP_CR2_TAMP2TRG_B_0X0			(0x0u<<25)
#define	TAMP_CR2_TAMP2TRG_B_0X1			(0x1u<<25)
#define	TAMP_CR2_TAMP1TRG_B_0X0			(0x0u<<24)
#define	TAMP_CR2_TAMP1TRG_B_0X1			(0x1u<<24)
#define	TAMP_CR2_BKBLOCK_B_0X0			(0x0u<<22)
#define	TAMP_CR2_BKBLOCK_B_0X1			(0x1u<<22)
#define	TAMP_CR2_TAMP3MSK_B_0X0			(0x0u<<18)
#define	TAMP_CR2_TAMP3MSK_B_0X1			(0x1u<<18)
#define	TAMP_CR2_TAMP2MSK_B_0X0			(0x0u<<17)
#define	TAMP_CR2_TAMP2MSK_B_0X1			(0x1u<<17)
#define	TAMP_CR2_TAMP1MSK_B_0X0			(0x0u<<16)
#define	TAMP_CR2_TAMP1MSK_B_0X1			(0x1u<<16)
#define	TAMP_CR2_TAMP7POM_B_0X0			(0x0u<<6)
#define	TAMP_CR2_TAMP7POM_B_0X1			(0x1u<<6)
#define	TAMP_CR2_TAMP6POM_B_0X0			(0x0u<<5)
#define	TAMP_CR2_TAMP6POM_B_0X1			(0x1u<<5)
#define	TAMP_CR2_TAMP5POM_B_0X0			(0x0u<<4)
#define	TAMP_CR2_TAMP5POM_B_0X1			(0x1u<<4)
#define	TAMP_CR2_TAMP4POM_B_0X0			(0x0u<<3)
#define	TAMP_CR2_TAMP4POM_B_0X1			(0x1u<<3)
#define	TAMP_CR2_TAMP3POM_B_0X0			(0x0u<<2)
#define	TAMP_CR2_TAMP3POM_B_0X1			(0x1u<<2)
#define	TAMP_CR2_TAMP2POM_B_0X0			(0x0u<<1)
#define	TAMP_CR2_TAMP2POM_B_0X1			(0x1u<<1)
#define	TAMP_CR2_TAMP1POM_B_0X0			(0x0u<<0)
#define	TAMP_CR2_TAMP1POM_B_0X1			(0x1u<<0)

// CR3 Configuration

#define	TAMP_CR3_ITAMP11POM				(0x1u<<10)
#define	TAMP_CR3_ITAMP9POM				(0x1u<<8)
#define	TAMP_CR3_ITAMP8POM				(0x1u<<7)
#define	TAMP_CR3_ITAMP7POM				(0x1u<<6)
#define	TAMP_CR3_ITAMP6POM				(0x1u<<5)
#define	TAMP_CR3_ITAMP5POM				(0x1u<<4)
#define	TAMP_CR3_ITAMP4POM				(0x1u<<3)
#define	TAMP_CR3_ITAMP3POM				(0x1u<<2)
#define	TAMP_CR3_ITAMP2POM				(0x1u<<1)
#define	TAMP_CR3_ITAMP1POM				(0x1u<<0)

#define	TAMP_CR3_ITAMP11POM_B_0X0		(0x0u<<10)
#define	TAMP_CR3_ITAMP11POM_B_0X1		(0x1u<<10)
#define	TAMP_CR3_ITAMP9POM_B_0X0		(0x0u<<8)
#define	TAMP_CR3_ITAMP9POM_B_0X1		(0x1u<<8)
#define	TAMP_CR3_ITAMP8POM_B_0X0		(0x0u<<7)
#define	TAMP_CR3_ITAMP8POM_B_0X1		(0x1u<<7)
#define	TAMP_CR3_ITAMP7POM_B_0X0		(0x0u<<6)
#define	TAMP_CR3_ITAMP7POM_B_0X1		(0x1u<<6)
#define	TAMP_CR3_ITAMP6POM_B_0X0		(0x0u<<5)
#define	TAMP_CR3_ITAMP6POM_B_0X1		(0x1u<<5)
#define	TAMP_CR3_ITAMP5POM_B_0X0		(0x0u<<4)
#define	TAMP_CR3_ITAMP5POM_B_0X1		(0x1u<<4)
#define	TAMP_CR3_ITAMP4POM_B_0X0		(0x0u<<3)
#define	TAMP_CR3_ITAMP4POM_B_0X1		(0x1u<<3)
#define	TAMP_CR3_ITAMP3POM_B_0X0		(0x0u<<2)
#define	TAMP_CR3_ITAMP3POM_B_0X1		(0x1u<<2)
#define	TAMP_CR3_ITAMP2POM_B_0X0		(0x0u<<1)
#define	TAMP_CR3_ITAMP2POM_B_0X1		(0x1u<<1)
#define	TAMP_CR3_ITAMP1POM_B_0X0		(0x0u<<0)
#define	TAMP_CR3_ITAMP1POM_B_0X1		(0x1u<<0)

// FLTCR Configuration

#define	TAMP_FLTCR_TAMPPUDIS			(0x1u<<7)
#define	TAMP_FLTCR_TAMPPRCH				(0x3u<<5)
#define	TAMP_FLTCR_TAMPPRCH_0			(0x1u<<5)
#define	TAMP_FLTCR_TAMPFLT				(0x3u<<3)
#define	TAMP_FLTCR_TAMPFLT_0			(0x1u<<3)
#define	TAMP_FLTCR_TAMPFREQ				(0x7u<<0)
#define	TAMP_FLTCR_TAMPFREQ_0			(0x1u<<0)

#define	TAMP_FLTCR_TAMPPUDIS_B_0X0		(0x0u<<7)
#define	TAMP_FLTCR_TAMPPUDIS_B_0X1		(0x1u<<7)
#define	TAMP_FLTCR_TAMPPRCH_B_0X0		(0x0u<<5)
#define	TAMP_FLTCR_TAMPPRCH_B_0X1		(0x1u<<5)
#define	TAMP_FLTCR_TAMPPRCH_B_0X2		(0x2u<<5)
#define	TAMP_FLTCR_TAMPPRCH_B_0X3		(0x3u<<5)
#define	TAMP_FLTCR_TAMPFLT_B_0X0		(0x0u<<3)
#define	TAMP_FLTCR_TAMPFLT_B_0X1		(0x1u<<3)
#define	TAMP_FLTCR_TAMPFLT_B_0X2		(0x2u<<3)
#define	TAMP_FLTCR_TAMPFLT_B_0X3		(0x3u<<3)
#define	TAMP_FLTCR_TAMPFREQ_B_0X0		(0x0u<<0)
#define	TAMP_FLTCR_TAMPFREQ_B_0X1		(0x1u<<0)
#define	TAMP_FLTCR_TAMPFREQ_B_0X2		(0x2u<<0)
#define	TAMP_FLTCR_TAMPFREQ_B_0X3		(0x3u<<0)
#define	TAMP_FLTCR_TAMPFREQ_B_0X4		(0x4u<<0)
#define	TAMP_FLTCR_TAMPFREQ_B_0X5		(0x5u<<0)
#define	TAMP_FLTCR_TAMPFREQ_B_0X6		(0x6u<<0)
#define	TAMP_FLTCR_TAMPFREQ_B_0X7		(0x7u<<0)

// ATCR1 Configuration

#define	TAMP_ATCR1_FLTEN				(0x1u<<31)
#define	TAMP_ATCR1_ATOSHARE				(0x1u<<30)
#define	TAMP_ATCR1_ATPER				(0x7u<<24)
#define	TAMP_ATCR1_ATPER_0				(0x1u<<24)
#define	TAMP_ATCR1_ATCKSEL				(0xFu<<16)
#define	TAMP_ATCR1_ATCKSEL_0			(0x1u<<16)
#define	TAMP_ATCR1_ATOSEL4				(0x3u<<14)
#define	TAMP_ATCR1_ATOSEL4_0			(0x1u<<14)
#define	TAMP_ATCR1_ATOSEL3				(0x3u<<12)
#define	TAMP_ATCR1_ATOSEL3_0			(0x1u<<12)
#define	TAMP_ATCR1_ATOSEL2				(0x3u<<10)
#define	TAMP_ATCR1_ATOSEL2_0			(0x1u<<10)
#define	TAMP_ATCR1_ATOSEL1				(0x3u<<8)
#define	TAMP_ATCR1_ATOSEL1_0			(0x1u<<8)
#define	TAMP_ATCR1_TAMP7AM				(0x1u<<6)
#define	TAMP_ATCR1_TAMP6AM				(0x1u<<5)
#define	TAMP_ATCR1_TAMP5AM				(0x1u<<4)
#define	TAMP_ATCR1_TAMP4AM				(0x1u<<3)
#define	TAMP_ATCR1_TAMP3AM				(0x1u<<2)
#define	TAMP_ATCR1_TAMP2AM				(0x1u<<1)
#define	TAMP_ATCR1_TAMP1AM				(0x1u<<0)

#define	TAMP_ATCR1_FLTEN_B_0X0			(0x0u<<31)
#define	TAMP_ATCR1_FLTEN_B_0X1			(0x1u<<31)
#define	TAMP_ATCR1_ATOSHARE_B_0X0		(0x0u<<30)
#define	TAMP_ATCR1_ATOSHARE_B_0X1		(0x1u<<30)
#define	TAMP_ATCR1_ATOSEL4_B_0X0		(0x0u<<14)
#define	TAMP_ATCR1_ATOSEL4_B_0X1		(0x1u<<14)
#define	TAMP_ATCR1_ATOSEL4_B_0X2		(0x2u<<14)
#define	TAMP_ATCR1_ATOSEL4_B_0X3		(0x3u<<14)
#define	TAMP_ATCR1_ATOSEL3_B_0X0		(0x0u<<12)
#define	TAMP_ATCR1_ATOSEL3_B_0X1		(0x1u<<12)
#define	TAMP_ATCR1_ATOSEL3_B_0X2		(0x2u<<12)
#define	TAMP_ATCR1_ATOSEL3_B_0X3		(0x3u<<12)
#define	TAMP_ATCR1_ATOSEL2_B_0X0		(0x0u<<10)
#define	TAMP_ATCR1_ATOSEL2_B_0X1		(0x1u<<10)
#define	TAMP_ATCR1_ATOSEL2_B_0X2		(0x2u<<10)
#define	TAMP_ATCR1_ATOSEL2_B_0X3		(0x3u<<10)
#define	TAMP_ATCR1_ATOSEL1_B_0X0		(0x0u<<8)
#define	TAMP_ATCR1_ATOSEL1_B_0X1		(0x1u<<8)
#define	TAMP_ATCR1_ATOSEL1_B_0X2		(0x2u<<8)
#define	TAMP_ATCR1_ATOSEL1_B_0X3		(0x3u<<8)
#define	TAMP_ATCR1_TAMP7AM_B_0X0		(0x0u<<6)
#define	TAMP_ATCR1_TAMP7AM_B_0X1		(0x1u<<6)
#define	TAMP_ATCR1_TAMP6AM_B_0X0		(0x0u<<5)
#define	TAMP_ATCR1_TAMP6AM_B_0X1		(0x1u<<5)
#define	TAMP_ATCR1_TAMP5AM_B_0X0		(0x0u<<4)
#define	TAMP_ATCR1_TAMP5AM_B_0X1		(0x1u<<4)
#define	TAMP_ATCR1_TAMP4AM_B_0X0		(0x0u<<3)
#define	TAMP_ATCR1_TAMP4AM_B_0X1		(0x1u<<3)
#define	TAMP_ATCR1_TAMP3AM_B_0X0		(0x0u<<2)
#define	TAMP_ATCR1_TAMP3AM_B_0X1		(0x1u<<2)
#define	TAMP_ATCR1_TAMP2AM_B_0X0		(0x0u<<1)
#define	TAMP_ATCR1_TAMP2AM_B_0X1		(0x1u<<1)
#define	TAMP_ATCR1_TAMP1AM_B_0X0		(0x0u<<0)
#define	TAMP_ATCR1_TAMP1AM_B_0X1		(0x1u<<0)

// ATSEEDR Configuration

#define	TAMP_ATSEEDR_SEED				(0xFFFFFFFFu<<0)
#define	TAMP_ATSEEDR_SEED_0				(0x1u<<0)

// ATOR Configuration

#define	TAMP_ATOR_INITS					(0x1u<<15)
#define	TAMP_ATOR_SEEDF					(0x1u<<14)
#define	TAMP_ATOR_PRNG					(0xFFu<<0)
#define	TAMP_ATOR_PRNG_0				(0x1u<<0)

// ATCR2 Configuration

#define	TAMP_ATCR2_ATOSEL7				(0x7u<<26)
#define	TAMP_ATCR2_ATOSEL7_0			(0x1u<<26)
#define	TAMP_ATCR2_ATOSEL6				(0x7u<<23)
#define	TAMP_ATCR2_ATOSEL6_0			(0x1u<<23)
#define	TAMP_ATCR2_ATOSEL5				(0x7u<<20)
#define	TAMP_ATCR2_ATOSEL5_0			(0x1u<<20)
#define	TAMP_ATCR2_ATOSEL4				(0x7u<<17)
#define	TAMP_ATCR2_ATOSEL4_0			(0x1u<<17)
#define	TAMP_ATCR2_ATOSEL3				(0x7u<<14)
#define	TAMP_ATCR2_ATOSEL3_0			(0x1u<<14)
#define	TAMP_ATCR2_ATOSEL2				(0x7u<<11)
#define	TAMP_ATCR2_ATOSEL2_0			(0x1u<<11)
#define	TAMP_ATCR2_ATOSEL1				(0x7u<<8)
#define	TAMP_ATCR2_ATOSEL1_0			(0x1u<<8)

#define	TAMP_ATCR2_ATOSEL7_B_0X0		(0x0u<<26)
#define	TAMP_ATCR2_ATOSEL7_B_0X1		(0x1u<<26)
#define	TAMP_ATCR2_ATOSEL7_B_0X2		(0x2u<<26)
#define	TAMP_ATCR2_ATOSEL7_B_0X3		(0x3u<<26)
#define	TAMP_ATCR2_ATOSEL7_B_0X4		(0x4u<<26)
#define	TAMP_ATCR2_ATOSEL7_B_0X5		(0x5u<<26)
#define	TAMP_ATCR2_ATOSEL7_B_0X6		(0x6u<<26)
#define	TAMP_ATCR2_ATOSEL7_B_0X7		(0x7u<<26)
#define	TAMP_ATCR2_ATOSEL6_B_0X0		(0x0u<<23)
#define	TAMP_ATCR2_ATOSEL6_B_0X1		(0x1u<<23)
#define	TAMP_ATCR2_ATOSEL6_B_0X2		(0x2u<<23)
#define	TAMP_ATCR2_ATOSEL6_B_0X3		(0x3u<<23)
#define	TAMP_ATCR2_ATOSEL6_B_0X4		(0x4u<<23)
#define	TAMP_ATCR2_ATOSEL6_B_0X5		(0x5u<<23)
#define	TAMP_ATCR2_ATOSEL6_B_0X6		(0x6u<<23)
#define	TAMP_ATCR2_ATOSEL6_B_0X7		(0x7u<<23)
#define	TAMP_ATCR2_ATOSEL5_B_0X0		(0x0u<<20)
#define	TAMP_ATCR2_ATOSEL5_B_0X1		(0x1u<<20)
#define	TAMP_ATCR2_ATOSEL5_B_0X2		(0x2u<<20)
#define	TAMP_ATCR2_ATOSEL5_B_0X3		(0x3u<<20)
#define	TAMP_ATCR2_ATOSEL5_B_0X4		(0x4u<<20)
#define	TAMP_ATCR2_ATOSEL5_B_0X5		(0x5u<<20)
#define	TAMP_ATCR2_ATOSEL5_B_0X6		(0x6u<<20)
#define	TAMP_ATCR2_ATOSEL5_B_0X7		(0x7u<<20)
#define	TAMP_ATCR2_ATOSEL4_B_0X0		(0x0u<<17)
#define	TAMP_ATCR2_ATOSEL4_B_0X1		(0x1u<<17)
#define	TAMP_ATCR2_ATOSEL4_B_0X2		(0x2u<<17)
#define	TAMP_ATCR2_ATOSEL4_B_0X3		(0x3u<<17)
#define	TAMP_ATCR2_ATOSEL4_B_0X4		(0x4u<<17)
#define	TAMP_ATCR2_ATOSEL4_B_0X5		(0x5u<<17)
#define	TAMP_ATCR2_ATOSEL4_B_0X6		(0x6u<<17)
#define	TAMP_ATCR2_ATOSEL4_B_0X7		(0x7u<<17)
#define	TAMP_ATCR2_ATOSEL3_B_0X0		(0x0u<<14)
#define	TAMP_ATCR2_ATOSEL3_B_0X1		(0x1u<<14)
#define	TAMP_ATCR2_ATOSEL3_B_0X2		(0x2u<<14)
#define	TAMP_ATCR2_ATOSEL3_B_0X3		(0x3u<<14)
#define	TAMP_ATCR2_ATOSEL3_B_0X4		(0x4u<<14)
#define	TAMP_ATCR2_ATOSEL3_B_0X5		(0x5u<<14)
#define	TAMP_ATCR2_ATOSEL3_B_0X6		(0x6u<<14)
#define	TAMP_ATCR2_ATOSEL3_B_0X7		(0x7u<<14)
#define	TAMP_ATCR2_ATOSEL2_B_0X0		(0x0u<<11)
#define	TAMP_ATCR2_ATOSEL2_B_0X1		(0x1u<<11)
#define	TAMP_ATCR2_ATOSEL2_B_0X2		(0x2u<<11)
#define	TAMP_ATCR2_ATOSEL2_B_0X3		(0x3u<<11)
#define	TAMP_ATCR2_ATOSEL2_B_0X4		(0x4u<<11)
#define	TAMP_ATCR2_ATOSEL2_B_0X5		(0x5u<<11)
#define	TAMP_ATCR2_ATOSEL2_B_0X6		(0x6u<<11)
#define	TAMP_ATCR2_ATOSEL2_B_0X7		(0x7u<<11)
#define	TAMP_ATCR2_ATOSEL1_B_0X0		(0x0u<<8)
#define	TAMP_ATCR2_ATOSEL1_B_0X1		(0x1u<<8)
#define	TAMP_ATCR2_ATOSEL1_B_0X2		(0x2u<<8)
#define	TAMP_ATCR2_ATOSEL1_B_0X3		(0x3u<<8)
#define	TAMP_ATCR2_ATOSEL1_B_0X4		(0x4u<<8)
#define	TAMP_ATCR2_ATOSEL1_B_0X5		(0x5u<<8)
#define	TAMP_ATCR2_ATOSEL1_B_0X6		(0x6u<<8)
#define	TAMP_ATCR2_ATOSEL1_B_0X7		(0x7u<<8)

// SECCFGR Configuration

#define	TAMP_SECCFGR_TAMPSEC			(0x1u<<31)
#define	TAMP_SECCFGR_BHKLOCK			(0x1u<<30)
#define	TAMP_SECCFGR_BKPWSEC			(0xFFu<<16)
#define	TAMP_SECCFGR_BKPWSEC_0			(0x1u<<16)
#define	TAMP_SECCFGR_CNT1SEC			(0x1u<<15)
#define	TAMP_SECCFGR_BKPRWSEC			(0xFFu<<0)
#define	TAMP_SECCFGR_BKPRWSEC_0			(0x1u<<0)

#define	TAMP_SECCFGR_TAMPSEC_B_0X0		(0x0u<<31)
#define	TAMP_SECCFGR_TAMPSEC_B_0X1		(0x1u<<31)
#define	TAMP_SECCFGR_BHKLOCK_B_0X0		(0x0u<<30)
#define	TAMP_SECCFGR_BHKLOCK_B_0X1		(0x1u<<30)
#define	TAMP_SECCFGR_CNT1SEC_B_0X0		(0x0u<<15)
#define	TAMP_SECCFGR_CNT1SEC_B_0X1		(0x1u<<15)

// PRIVCFGR Configuration

#define	TAMP_PRIVCFGR_TAMPPRIV			(0x1u<<31)
#define	TAMP_PRIVCFGR_BKPWPRIV			(0x1u<<30)
#define	TAMP_PRIVCFGR_BKPRWPRIV			(0x1u<<29)
#define	TAMP_PRIVCFGR_CNT1PRIV			(0x1u<<15)

#define	TAMP_PRIVCFGR_TAMPPRIV_B_0X0	(0x0u<<31)
#define	TAMP_PRIVCFGR_TAMPPRIV_B_0X1	(0x1u<<31)
#define	TAMP_PRIVCFGR_BKPWPRIV_B_0X0	(0x0u<<30)
#define	TAMP_PRIVCFGR_BKPWPRIV_B_0X1	(0x1u<<30)
#define	TAMP_PRIVCFGR_BKPRWPRIV_B_0X0	(0x0u<<29)
#define	TAMP_PRIVCFGR_BKPRWPRIV_B_0X1	(0x1u<<29)
#define	TAMP_PRIVCFGR_CNT1PRIV_B_0X0	(0x0u<<15)
#define	TAMP_PRIVCFGR_CNT1PRIV_B_0X1	(0x1u<<15)

// IER Configuration

#define	TAMP_IER_ITAMP11IE				(0x1u<<26)
#define	TAMP_IER_ITAMP9IE				(0x1u<<24)
#define	TAMP_IER_ITAMP8IE				(0x1u<<23)
#define	TAMP_IER_ITAMP7IE				(0x1u<<22)
#define	TAMP_IER_ITAMP6IE				(0x1u<<21)
#define	TAMP_IER_ITAMP5IE				(0x1u<<20)
#define	TAMP_IER_ITAMP4IE				(0x1u<<19)
#define	TAMP_IER_ITAMP3IE				(0x1u<<18)
#define	TAMP_IER_ITAMP2IE				(0x1u<<17)
#define	TAMP_IER_ITAMP1IE				(0x1u<<16)
#define	TAMP_IER_TAMP7IE				(0x1u<<6)
#define	TAMP_IER_TAMP6IE				(0x1u<<5)
#define	TAMP_IER_TAMP5IE				(0x1u<<4)
#define	TAMP_IER_TAMP4IE				(0x1u<<3)
#define	TAMP_IER_TAMP3IE				(0x1u<<2)
#define	TAMP_IER_TAMP2IE				(0x1u<<1)
#define	TAMP_IER_TAMP1IE				(0x1u<<0)

#define	TAMP_IER_ITAMP11IE_B_0X0		(0x0u<<26)
#define	TAMP_IER_ITAMP11IE_B_0X1		(0x1u<<26)
#define	TAMP_IER_ITAMP9IE_B_0X0			(0x0u<<24)
#define	TAMP_IER_ITAMP9IE_B_0X1			(0x1u<<24)
#define	TAMP_IER_ITAMP8IE_B_0X0			(0x0u<<23)
#define	TAMP_IER_ITAMP8IE_B_0X1			(0x1u<<23)
#define	TAMP_IER_ITAMP7IE_B_0X0			(0x0u<<22)
#define	TAMP_IER_ITAMP7IE_B_0X1			(0x1u<<22)
#define	TAMP_IER_ITAMP6IE_B_0X0			(0x0u<<21)
#define	TAMP_IER_ITAMP6IE_B_0X1			(0x1u<<21)
#define	TAMP_IER_ITAMP5IE_B_0X0			(0x0u<<20)
#define	TAMP_IER_ITAMP5IE_B_0X1			(0x1u<<20)
#define	TAMP_IER_ITAMP4IE_B_0X0			(0x0u<<19)
#define	TAMP_IER_ITAMP4IE_B_0X1			(0x1u<<19)
#define	TAMP_IER_ITAMP3IE_B_0X0			(0x0u<<18)
#define	TAMP_IER_ITAMP3IE_B_0X1			(0x1u<<18)
#define	TAMP_IER_ITAMP2IE_B_0X0			(0x0u<<17)
#define	TAMP_IER_ITAMP2IE_B_0X1			(0x1u<<17)
#define	TAMP_IER_ITAMP1IE_B_0X0			(0x0u<<16)
#define	TAMP_IER_ITAMP1IE_B_0X1			(0x1u<<16)
#define	TAMP_IER_TAMP7IE_B_0X0			(0x0u<<6)
#define	TAMP_IER_TAMP7IE_B_0X1			(0x1u<<6)
#define	TAMP_IER_TAMP6IE_B_0X0			(0x0u<<5)
#define	TAMP_IER_TAMP6IE_B_0X1			(0x1u<<5)
#define	TAMP_IER_TAMP5IE_B_0X0			(0x0u<<4)
#define	TAMP_IER_TAMP5IE_B_0X1			(0x1u<<4)
#define	TAMP_IER_TAMP4IE_B_0X0			(0x0u<<3)
#define	TAMP_IER_TAMP4IE_B_0X1			(0x1u<<3)
#define	TAMP_IER_TAMP3IE_B_0X0			(0x0u<<2)
#define	TAMP_IER_TAMP3IE_B_0X1			(0x1u<<2)
#define	TAMP_IER_TAMP2IE_B_0X0			(0x0u<<1)
#define	TAMP_IER_TAMP2IE_B_0X1			(0x1u<<1)
#define	TAMP_IER_TAMP1IE_B_0X0			(0x0u<<0)
#define	TAMP_IER_TAMP1IE_B_0X1			(0x1u<<0)

// SR Configuration

#define	TAMP_SR_ITAMP11F				(0x1u<<26)
#define	TAMP_SR_ITAMP9F					(0x1u<<24)
#define	TAMP_SR_ITAMP8F					(0x1u<<23)
#define	TAMP_SR_ITAMP7F					(0x1u<<22)
#define	TAMP_SR_ITAMP6F					(0x1u<<21)
#define	TAMP_SR_ITAMP5F					(0x1u<<20)
#define	TAMP_SR_ITAMP4F					(0x1u<<19)
#define	TAMP_SR_ITAMP3F					(0x1u<<18)
#define	TAMP_SR_ITAMP2F					(0x1u<<17)
#define	TAMP_SR_ITAMP1F					(0x1u<<16)
#define	TAMP_SR_TAMP7F					(0x1u<<6)
#define	TAMP_SR_TAMP6F					(0x1u<<5)
#define	TAMP_SR_TAMP5F					(0x1u<<4)
#define	TAMP_SR_TAMP4F					(0x1u<<3)
#define	TAMP_SR_TAMP3F					(0x1u<<2)
#define	TAMP_SR_TAMP2F					(0x1u<<1)
#define	TAMP_SR_TAMP1F					(0x1u<<0)

// MISR Configuration

#define	TAMP_MISR_ITAMP11MF				(0x1u<<26)
#define	TAMP_MISR_ITAMP9MF				(0x1u<<24)
#define	TAMP_MISR_ITAMP8MF				(0x1u<<23)
#define	TAMP_MISR_ITAMP7MF				(0x1u<<22)
#define	TAMP_MISR_ITAMP6MF				(0x1u<<21)
#define	TAMP_MISR_ITAMP5MF				(0x1u<<20)
#define	TAMP_MISR_ITAMP4MF				(0x1u<<19)
#define	TAMP_MISR_ITAMP3MF				(0x1u<<18)
#define	TAMP_MISR_ITAMP2MF				(0x1u<<17)
#define	TAMP_MISR_ITAMP1MF				(0x1u<<16)
#define	TAMP_MISR_TAMP7MF				(0x1u<<6)
#define	TAMP_MISR_TAMP6MF				(0x1u<<5)
#define	TAMP_MISR_TAMP5MF				(0x1u<<4)
#define	TAMP_MISR_TAMP4MF				(0x1u<<3)
#define	TAMP_MISR_TAMP3MF				(0x1u<<2)
#define	TAMP_MISR_TAMP2MF				(0x1u<<1)
#define	TAMP_MISR_TAMP1MF				(0x1u<<0)

// SMISR Configuration

#define	TAMP_SMISR_ITAMP11MF			(0x1u<<26)
#define	TAMP_SMISR_ITAMP9MF				(0x1u<<24)
#define	TAMP_SMISR_ITAMP8MF				(0x1u<<23)
#define	TAMP_SMISR_ITAMP7MF				(0x1u<<22)
#define	TAMP_SMISR_ITAMP6MF				(0x1u<<21)
#define	TAMP_SMISR_ITAMP5MF				(0x1u<<20)
#define	TAMP_SMISR_ITAMP4MF				(0x1u<<19)
#define	TAMP_SMISR_ITAMP3MF				(0x1u<<18)
#define	TAMP_SMISR_ITAMP2MF				(0x1u<<17)
#define	TAMP_SMISR_ITAMP1MF				(0x1u<<16)
#define	TAMP_SMISR_TAMP7MF				(0x1u<<6)
#define	TAMP_SMISR_TAMP6MF				(0x1u<<5)
#define	TAMP_SMISR_TAMP5MF				(0x1u<<4)
#define	TAMP_SMISR_TAMP4MF				(0x1u<<3)
#define	TAMP_SMISR_TAMP3MF				(0x1u<<2)
#define	TAMP_SMISR_TAMP2MF				(0x1u<<1)
#define	TAMP_SMISR_TAMP1MF				(0x1u<<0)

// SCR Configuration

#define	TAMP_SCR_CITAMP11F				(0x1u<<26)
#define	TAMP_SCR_CITAMP9F				(0x1u<<24)
#define	TAMP_SCR_CITAMP8F				(0x1u<<23)
#define	TAMP_SCR_CITAMP7F				(0x1u<<22)
#define	TAMP_SCR_CITAMP6F				(0x1u<<21)
#define	TAMP_SCR_CITAMP5F				(0x1u<<20)
#define	TAMP_SCR_CITAMP4F				(0x1u<<19)
#define	TAMP_SCR_CITAMP3F				(0x1u<<18)
#define	TAMP_SCR_CITAMP2F				(0x1u<<17)
#define	TAMP_SCR_CITAMP1F				(0x1u<<16)
#define	TAMP_SCR_CTAMP7F				(0x1u<<6)
#define	TAMP_SCR_CTAMP6F				(0x1u<<5)
#define	TAMP_SCR_CTAMP5F				(0x1u<<4)
#define	TAMP_SCR_CTAMP4F				(0x1u<<3)
#define	TAMP_SCR_CTAMP3F				(0x1u<<2)
#define	TAMP_SCR_CTAMP2F				(0x1u<<1)
#define	TAMP_SCR_CTAMP1F				(0x1u<<0)

// COUNT1R Configuration

#define	TAMP_COUNT1R_COUNT				(0xFFFFFFFFu<<0)
#define	TAMP_COUNT1R_COUNT_0			(0x1u<<0)

// OR Configuration

#define	TAMP_OR_BSEN					(0x1u<<1)
#define	TAMP_OR_VCOREMEN				(0x1u<<0)

#define	TAMP_OR_BSEN_B_0X0				(0x0u<<1)
#define	TAMP_OR_BSEN_B_0X1				(0x1u<<1)
#define	TAMP_OR_VCOREMEN_B_0X0			(0x0u<<0)
#define	TAMP_OR_VCOREMEN_B_0X1			(0x1u<<0)

// RPCFGR Configuration

#define	TAMP_RPCFGR_RPCFG0				(0x1u<<0)

#define	TAMP_RPCFGR_RPCFG0_B_0X0		(0x0u<<0)
#define	TAMP_RPCFGR_RPCFG0_B_0X1		(0x1u<<0)

// BKP0R Configuration

#define	TAMP_BKP0R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP0R_BKP_0				(0x1u<<0)

// BKP1R Configuration

#define	TAMP_BKP1R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP1R_BKP_0				(0x1u<<0)

// BKP2R Configuration

#define	TAMP_BKP2R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP2R_BKP_0				(0x1u<<0)

// BKP3R Configuration

#define	TAMP_BKP3R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP3R_BKP_0				(0x1u<<0)

// BKP4R Configuration

#define	TAMP_BKP4R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP4R_BKP_0				(0x1u<<0)

// BKP5R Configuration

#define	TAMP_BKP5R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP5R_BKP_0				(0x1u<<0)

// BKP6R Configuration

#define	TAMP_BKP6R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP6R_BKP_0				(0x1u<<0)

// BKP7R Configuration

#define	TAMP_BKP7R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP7R_BKP_0				(0x1u<<0)

// BKP8R Configuration

#define	TAMP_BKP8R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP8R_BKP_0				(0x1u<<0)

// BKP9R Configuration

#define	TAMP_BKP9R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP9R_BKP_0				(0x1u<<0)

// BKP10R Configuration

#define	TAMP_BKP10R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP10R_BKP_0				(0x1u<<0)

// BKP11R Configuration

#define	TAMP_BKP11R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP11R_BKP_0				(0x1u<<0)

// BKP12R Configuration

#define	TAMP_BKP12R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP12R_BKP_0				(0x1u<<0)

// BKP13R Configuration

#define	TAMP_BKP13R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP13R_BKP_0				(0x1u<<0)

// BKP14R Configuration

#define	TAMP_BKP14R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP14R_BKP_0				(0x1u<<0)

// BKP15R Configuration

#define	TAMP_BKP15R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP15R_BKP_0				(0x1u<<0)

// BKP16R Configuration

#define	TAMP_BKP16R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP16R_BKP_0				(0x1u<<0)

// BKP17R Configuration

#define	TAMP_BKP17R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP17R_BKP_0				(0x1u<<0)

// BKP18R Configuration

#define	TAMP_BKP18R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP18R_BKP_0				(0x1u<<0)

// BKP19R Configuration

#define	TAMP_BKP19R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP19R_BKP_0				(0x1u<<0)

// BKP20R Configuration

#define	TAMP_BKP20R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP20R_BKP_0				(0x1u<<0)

// BKP21R Configuration

#define	TAMP_BKP21R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP21R_BKP_0				(0x1u<<0)

// BKP22R Configuration

#define	TAMP_BKP22R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP22R_BKP_0				(0x1u<<0)

// BKP23R Configuration

#define	TAMP_BKP23R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP23R_BKP_0				(0x1u<<0)

// BKP24R Configuration

#define	TAMP_BKP24R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP24R_BKP_0				(0x1u<<0)

// BKP25R Configuration

#define	TAMP_BKP25R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP25R_BKP_0				(0x1u<<0)

// BKP26R Configuration

#define	TAMP_BKP26R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP26R_BKP_0				(0x1u<<0)

// BKP27R Configuration

#define	TAMP_BKP27R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP27R_BKP_0				(0x1u<<0)

// BKP28R Configuration

#define	TAMP_BKP28R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP28R_BKP_0				(0x1u<<0)

// BKP29R Configuration

#define	TAMP_BKP29R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP29R_BKP_0				(0x1u<<0)

// BKP30R Configuration

#define	TAMP_BKP30R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP30R_BKP_0				(0x1u<<0)

// BKP31R Configuration

#define	TAMP_BKP31R_BKP					(0xFFFFFFFFu<<0)
#define	TAMP_BKP31R_BKP_0				(0x1u<<0)
