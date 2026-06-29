/*
; stm32N657_adf.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_adf equates.
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

// ADF address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	GCR;
	volatile	uint32_t	CKGCR;
	volatile	uint32_t	RESERVED0[30];
	volatile	uint32_t	SITF0CR;
	volatile	uint32_t	BSMX0CR;
	volatile	uint32_t	DFLT0CR;
	volatile	uint32_t	DFLT0CICR;
	volatile	uint32_t	DFLT0RSFR;
	volatile	uint32_t	RESERVED1[4];
	volatile	uint32_t	DLY0CR;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	DFLT0IER;
	volatile	uint32_t	DFLT0ISR;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	SADCR;
	volatile	uint32_t	SADCFGR;
	volatile	uint32_t	SADSDLVR;
	volatile	uint32_t	SADANLVR;
	volatile	uint32_t	RESERVED4[10];
	volatile	uint32_t	DFLT0DR;
} ADF_TypeDef;

#if (defined(__cplusplus))
#define	ADF_NS	reinterpret_cast<ADF_TypeDef *>(0x42026000u)
#define	ADF_S	reinterpret_cast<ADF_TypeDef *>(0x52026000u)

#else
#define	ADF_NS	((ADF_TypeDef *)0x42026000u)
#define	ADF_S	((ADF_TypeDef *)0x52026000u)
#endif

// GCR Configuration

#define	ADF_GCR_TRGO					(0x1u<<0)

#define	ADF_GCR_TRGO_B_0X0				(0x0u<<0)
#define	ADF_GCR_TRGO_B_0X1				(0x1u<<0)

// CKGCR Configuration

#define	ADF_CKGCR_CKGACTIVE				(0x1u<<31)
#define	ADF_CKGCR_PROCDIV				(0x7Fu<<24)
#define	ADF_CKGCR_PROCDIV_0				(0x1u<<24)
#define	ADF_CKGCR_CCKDIV				(0xFu<<16)
#define	ADF_CKGCR_CCKDIV_0				(0x1u<<16)
#define	ADF_CKGCR_TRGSRC				(0xFu<<12)
#define	ADF_CKGCR_TRGSRC_0				(0x1u<<12)
#define	ADF_CKGCR_TRGSENS				(0x1u<<8)
#define	ADF_CKGCR_CCK1DIR				(0x1u<<6)
#define	ADF_CKGCR_CCK0DIR				(0x1u<<5)
#define	ADF_CKGCR_CKGMOD				(0x1u<<4)
#define	ADF_CKGCR_CCK1EN				(0x1u<<2)
#define	ADF_CKGCR_CCK0EN				(0x1u<<1)
#define	ADF_CKGCR_CKGDEN				(0x1u<<0)

#define	ADF_CKGCR_CKGACTIVE_B_0X0		(0x0u<<31)
#define	ADF_CKGCR_CKGACTIVE_B_0X1		(0x1u<<31)
#define	ADF_CKGCR_PROCDIV_B_0X0			(0x0u<<24)
#define	ADF_CKGCR_PROCDIV_B_0X1			(0x1u<<24)
#define	ADF_CKGCR_CCKDIV_B_0X0			(0x0u<<16)
#define	ADF_CKGCR_CCKDIV_B_0X1			(0x1u<<16)
#define	ADF_CKGCR_CCKDIV_B_0X2			(0x2u<<16)
#define	ADF_CKGCR_CCKDIV_B_0XF			(0xFu<<16)
#define	ADF_CKGCR_TRGSRC_B_0X2			(0x2u<<12)
#define	ADF_CKGCR_TRGSENS_B_0X0			(0x0u<<8)
#define	ADF_CKGCR_TRGSENS_B_0X1			(0x1u<<8)
#define	ADF_CKGCR_CCK1DIR_B_0X0			(0x0u<<6)
#define	ADF_CKGCR_CCK1DIR_B_0X1			(0x1u<<6)
#define	ADF_CKGCR_CCK0DIR_B_0X0			(0x0u<<5)
#define	ADF_CKGCR_CCK0DIR_B_0X1			(0x1u<<5)
#define	ADF_CKGCR_CKGMOD_B_0X0			(0x0u<<4)
#define	ADF_CKGCR_CKGMOD_B_0X1			(0x1u<<4)
#define	ADF_CKGCR_CCK1EN_B_0X0			(0x0u<<2)
#define	ADF_CKGCR_CCK1EN_B_0X1			(0x1u<<2)
#define	ADF_CKGCR_CCK0EN_B_0X0			(0x0u<<1)
#define	ADF_CKGCR_CCK0EN_B_0X1			(0x1u<<1)
#define	ADF_CKGCR_CKGDEN_B_0X0			(0x0u<<0)
#define	ADF_CKGCR_CKGDEN_B_0X1			(0x1u<<0)

// SITF0CR Configuration

#define	ADF_SITF0CR_SITFACTIVE			(0x1u<<31)
#define	ADF_SITF0CR_STH					(0x1Fu<<8)
#define	ADF_SITF0CR_STH_0				(0x1u<<8)
#define	ADF_SITF0CR_SITFMOD				(0x3u<<4)
#define	ADF_SITF0CR_SITFMOD_0			(0x1u<<4)
#define	ADF_SITF0CR_SCKSRC				(0x3u<<1)
#define	ADF_SITF0CR_SCKSRC_0			(0x1u<<1)
#define	ADF_SITF0CR_SITFEN				(0x1u<<0)

#define	ADF_SITF0CR_SITFACTIVE_B_0X0	(0x0u<<31)
#define	ADF_SITF0CR_SITFACTIVE_B_0X1	(0x1u<<31)
#define	ADF_SITF0CR_SITFMOD_B_0X0		(0x0u<<4)
#define	ADF_SITF0CR_SITFMOD_B_0X1		(0x1u<<4)
#define	ADF_SITF0CR_SITFMOD_B_0X2		(0x2u<<4)
#define	ADF_SITF0CR_SITFMOD_B_0X3		(0x3u<<4)
#define	ADF_SITF0CR_SCKSRC_B_0X0		(0x0u<<1)
#define	ADF_SITF0CR_SCKSRC_B_0X1		(0x1u<<1)
#define	ADF_SITF0CR_SITFEN_B_0X0		(0x0u<<0)
#define	ADF_SITF0CR_SITFEN_B_0X1		(0x1u<<0)

// BSMX0CR Configuration

#define	ADF_BSMX0CR_BSMXACTIVE			(0x1u<<31)
#define	ADF_BSMX0CR_BSSEL				(0x1Fu<<0)
#define	ADF_BSMX0CR_BSSEL_0				(0x1u<<0)

#define	ADF_BSMX0CR_BSMXACTIVE_B_0X0	(0x0u<<31)
#define	ADF_BSMX0CR_BSMXACTIVE_B_0X1	(0x1u<<31)
#define	ADF_BSMX0CR_BSSEL_B_0X0			(0x0u<<0)
#define	ADF_BSMX0CR_BSSEL_B_0X1			(0x1u<<0)

// DFLT0CR Configuration

#define	ADF_DFLT0CR_DFLTACTIVE			(0x1u<<31)
#define	ADF_DFLT0CR_DFLTRUN				(0x1u<<30)
#define	ADF_DFLT0CR_NBDIS				(0xFFu<<20)
#define	ADF_DFLT0CR_NBDIS_0				(0x1u<<20)
#define	ADF_DFLT0CR_TRGSRC				(0xFu<<12)
#define	ADF_DFLT0CR_TRGSRC_0			(0x1u<<12)
#define	ADF_DFLT0CR_TRGSENS				(0x1u<<8)
#define	ADF_DFLT0CR_ACQMOD				(0x7u<<4)
#define	ADF_DFLT0CR_ACQMOD_0			(0x1u<<4)
#define	ADF_DFLT0CR_FTH					(0x1u<<2)
#define	ADF_DFLT0CR_DMAEN				(0x1u<<1)
#define	ADF_DFLT0CR_DFLTEN				(0x1u<<0)

#define	ADF_DFLT0CR_DFLTACTIVE_B_0X0	(0x0u<<31)
#define	ADF_DFLT0CR_DFLTACTIVE_B_0X1	(0x1u<<31)
#define	ADF_DFLT0CR_DFLTRUN_B_0X0		(0x0u<<30)
#define	ADF_DFLT0CR_DFLTRUN_B_0X1		(0x1u<<30)
#define	ADF_DFLT0CR_NBDIS_B_0X0			(0x0u<<20)
#define	ADF_DFLT0CR_NBDIS_B_0X1			(0x1u<<20)
#define	ADF_DFLT0CR_TRGSRC_B_0X0		(0x0u<<12)
#define	ADF_DFLT0CR_TRGSRC_B_0X2		(0x2u<<12)
#define	ADF_DFLT0CR_TRGSENS_B_0X0		(0x0u<<8)
#define	ADF_DFLT0CR_TRGSENS_B_0X1		(0x1u<<8)
#define	ADF_DFLT0CR_ACQMOD_B_0X0		(0x0u<<4)
#define	ADF_DFLT0CR_ACQMOD_B_0X1		(0x1u<<4)
#define	ADF_DFLT0CR_ACQMOD_B_0X2		(0x2u<<4)
#define	ADF_DFLT0CR_ACQMOD_B_0X3		(0x3u<<4)
#define	ADF_DFLT0CR_ACQMOD_B_0X4		(0x4u<<4)
#define	ADF_DFLT0CR_FTH_B_0X0			(0x0u<<2)
#define	ADF_DFLT0CR_FTH_B_0X1			(0x1u<<2)
#define	ADF_DFLT0CR_DMAEN_B_0X0			(0x0u<<1)
#define	ADF_DFLT0CR_DMAEN_B_0X1			(0x1u<<1)
#define	ADF_DFLT0CR_DFLTEN_B_0X0		(0x0u<<0)
#define	ADF_DFLT0CR_DFLTEN_B_0X1		(0x1u<<0)

// DFLT0CICR Configuration

#define	ADF_DFLT0CICR_SCALE				(0x3Fu<<20)
#define	ADF_DFLT0CICR_SCALE_0			(0x1u<<20)
#define	ADF_DFLT0CICR_MCICD8			(0x1u<<16)
#define	ADF_DFLT0CICR_MCICD				(0xFFu<<8)
#define	ADF_DFLT0CICR_MCICD_0			(0x1u<<8)
#define	ADF_DFLT0CICR_CICMOD			(0x7u<<4)
#define	ADF_DFLT0CICR_CICMOD_0			(0x1u<<4)
#define	ADF_DFLT0CICR_DATSRC			(0x3u<<0)
#define	ADF_DFLT0CICR_DATSRC_0			(0x1u<<0)

#define	ADF_DFLT0CICR_SCALE_B_0X0		(0x0u<<20)
#define	ADF_DFLT0CICR_SCALE_B_0X1		(0x1u<<20)
#define	ADF_DFLT0CICR_SCALE_B_0X2		(0x2u<<20)
#define	ADF_DFLT0CICR_SCALE_B_0X18		(0x18u<<20)
#define	ADF_DFLT0CICR_SCALE_B_0X20		(0x20u<<20)
#define	ADF_DFLT0CICR_SCALE_B_0X21		(0x21u<<20)
#define	ADF_DFLT0CICR_SCALE_B_0X22		(0x22u<<20)
#define	ADF_DFLT0CICR_SCALE_B_0X23		(0x23u<<20)
#define	ADF_DFLT0CICR_SCALE_B_0X2E		(0x2Eu<<20)
#define	ADF_DFLT0CICR_SCALE_B_0X2F		(0x2Fu<<20)
#define	ADF_DFLT0CICR_MCICD8_B_0X0		(0x0u<<16)
#define	ADF_DFLT0CICR_MCICD8_B_0X1		(0x1u<<16)
#define	ADF_DFLT0CICR_MCICD_B_0X0		(0x0u<<8)
#define	ADF_DFLT0CICR_MCICD_B_0X1		(0x1u<<8)
#define	ADF_DFLT0CICR_CICMOD_B_0X4		(0x4u<<4)
#define	ADF_DFLT0CICR_CICMOD_B_0X5		(0x5u<<4)
#define	ADF_DFLT0CICR_DATSRC_B_0X2		(0x2u<<0)
#define	ADF_DFLT0CICR_DATSRC_B_0X3		(0x3u<<0)

// DFLT0RSFR Configuration

#define	ADF_DFLT0RSFR_HPFC				(0x3u<<8)
#define	ADF_DFLT0RSFR_HPFC_0			(0x1u<<8)
#define	ADF_DFLT0RSFR_HPFBYP			(0x1u<<7)
#define	ADF_DFLT0RSFR_RSFLTD			(0x1u<<4)
#define	ADF_DFLT0RSFR_RSFLTBYP			(0x1u<<0)

#define	ADF_DFLT0RSFR_HPFC_B_0X0		(0x0u<<8)
#define	ADF_DFLT0RSFR_HPFC_B_0X1		(0x1u<<8)
#define	ADF_DFLT0RSFR_HPFC_B_0X2		(0x2u<<8)
#define	ADF_DFLT0RSFR_HPFC_B_0X3		(0x3u<<8)
#define	ADF_DFLT0RSFR_HPFBYP_B_0X0		(0x0u<<7)
#define	ADF_DFLT0RSFR_HPFBYP_B_0X1		(0x1u<<7)
#define	ADF_DFLT0RSFR_RSFLTD_B_0X0		(0x0u<<4)
#define	ADF_DFLT0RSFR_RSFLTD_B_0X1		(0x1u<<4)
#define	ADF_DFLT0RSFR_RSFLTBYP_B_0X0	(0x0u<<0)
#define	ADF_DFLT0RSFR_RSFLTBYP_B_0X1	(0x1u<<0)

// DLY0CR Configuration

#define	ADF_DLY0CR_SKPBF				(0x1u<<31)
#define	ADF_DLY0CR_SKPDLY				(0x7Fu<<0)
#define	ADF_DLY0CR_SKPDLY_0				(0x1u<<0)

#define	ADF_DLY0CR_SKPBF_B_0X0			(0x0u<<31)
#define	ADF_DLY0CR_SKPBF_B_0X1			(0x1u<<31)
#define	ADF_DLY0CR_SKPDLY_B_0X0			(0x0u<<0)
#define	ADF_DLY0CR_SKPDLY_B_0X1			(0x1u<<0)

// DFLT0IER Configuration

#define	ADF_DFLT0IER_SDLVLIE			(0x1u<<13)
#define	ADF_DFLT0IER_SDDETIE			(0x1u<<12)
#define	ADF_DFLT0IER_RFOVRIE			(0x1u<<11)
#define	ADF_DFLT0IER_CKABIE				(0x1u<<10)
#define	ADF_DFLT0IER_SATIE				(0x1u<<9)
#define	ADF_DFLT0IER_DOVRIE				(0x1u<<1)
#define	ADF_DFLT0IER_FTHIE				(0x1u<<0)

#define	ADF_DFLT0IER_SDLVLIE_B_0X0		(0x0u<<13)
#define	ADF_DFLT0IER_SDLVLIE_B_0X1		(0x1u<<13)
#define	ADF_DFLT0IER_SDDETIE_B_0X0		(0x0u<<12)
#define	ADF_DFLT0IER_SDDETIE_B_0X1		(0x1u<<12)
#define	ADF_DFLT0IER_RFOVRIE_B_0X0		(0x0u<<11)
#define	ADF_DFLT0IER_RFOVRIE_B_0X1		(0x1u<<11)
#define	ADF_DFLT0IER_CKABIE_B_0X0		(0x0u<<10)
#define	ADF_DFLT0IER_CKABIE_B_0X1		(0x1u<<10)
#define	ADF_DFLT0IER_SATIE_B_0X0		(0x0u<<9)
#define	ADF_DFLT0IER_SATIE_B_0X1		(0x1u<<9)
#define	ADF_DFLT0IER_DOVRIE_B_0X0		(0x0u<<1)
#define	ADF_DFLT0IER_DOVRIE_B_0X1		(0x1u<<1)
#define	ADF_DFLT0IER_FTHIE_B_0X0		(0x0u<<0)
#define	ADF_DFLT0IER_FTHIE_B_0X1		(0x1u<<0)

// DFLT0ISR Configuration

#define	ADF_DFLT0ISR_SDLVLF				(0x1u<<13)
#define	ADF_DFLT0ISR_SDDETF				(0x1u<<12)
#define	ADF_DFLT0ISR_RFOVRF				(0x1u<<11)
#define	ADF_DFLT0ISR_CKABF				(0x1u<<10)
#define	ADF_DFLT0ISR_SATF				(0x1u<<9)
#define	ADF_DFLT0ISR_RXNEF				(0x1u<<3)
#define	ADF_DFLT0ISR_DOVRF				(0x1u<<1)
#define	ADF_DFLT0ISR_FTHF				(0x1u<<0)

#define	ADF_DFLT0ISR_SDLVLF_B_0X0		(0x0u<<13)
#define	ADF_DFLT0ISR_SDLVLF_B_0X1		(0x1u<<13)
#define	ADF_DFLT0ISR_SDDETF_B_0X0		(0x0u<<12)
#define	ADF_DFLT0ISR_SDDETF_B_0X1		(0x1u<<12)
#define	ADF_DFLT0ISR_RFOVRF_B_0X0		(0x0u<<11)
#define	ADF_DFLT0ISR_RFOVRF_B_0X1		(0x1u<<11)
#define	ADF_DFLT0ISR_CKABF_B_0X0		(0x0u<<10)
#define	ADF_DFLT0ISR_CKABF_B_0X1		(0x1u<<10)
#define	ADF_DFLT0ISR_SATF_B_0X0			(0x0u<<9)
#define	ADF_DFLT0ISR_SATF_B_0X1			(0x1u<<9)
#define	ADF_DFLT0ISR_RXNEF_B_0X0		(0x0u<<3)
#define	ADF_DFLT0ISR_RXNEF_B_0X1		(0x1u<<3)
#define	ADF_DFLT0ISR_DOVRF_B_0X0		(0x0u<<1)
#define	ADF_DFLT0ISR_DOVRF_B_0X1		(0x1u<<1)
#define	ADF_DFLT0ISR_FTHF_B_0X0			(0x0u<<0)
#define	ADF_DFLT0ISR_FTHF_B_0X1			(0x1u<<0)

// SADCR Configuration

#define	ADF_SADCR_SADACTIVE				(0x1u<<31)
#define	ADF_SADCR_SADMOD				(0x3u<<12)
#define	ADF_SADCR_SADMOD_0				(0x1u<<12)
#define	ADF_SADCR_FRSIZE				(0x7u<<8)
#define	ADF_SADCR_FRSIZE_0				(0x1u<<8)
#define	ADF_SADCR_HYSTEN				(0x1u<<7)
#define	ADF_SADCR_SADST					(0x3u<<4)
#define	ADF_SADCR_SADST_0				(0x1u<<4)
#define	ADF_SADCR_DETCFG				(0x1u<<3)
#define	ADF_SADCR_DATCAP				(0x3u<<1)
#define	ADF_SADCR_DATCAP_0				(0x1u<<1)
#define	ADF_SADCR_SADEN					(0x1u<<0)

#define	ADF_SADCR_SADACTIVE_B_0X0		(0x0u<<31)
#define	ADF_SADCR_SADACTIVE_B_0X1		(0x1u<<31)
#define	ADF_SADCR_SADMOD_B_0X0			(0x0u<<12)
#define	ADF_SADCR_SADMOD_B_0X1			(0x1u<<12)
#define	ADF_SADCR_FRSIZE_B_0X0			(0x0u<<8)
#define	ADF_SADCR_FRSIZE_B_0X1			(0x1u<<8)
#define	ADF_SADCR_FRSIZE_B_0X2			(0x2u<<8)
#define	ADF_SADCR_FRSIZE_B_0X3			(0x3u<<8)
#define	ADF_SADCR_FRSIZE_B_0X4			(0x4u<<8)
#define	ADF_SADCR_FRSIZE_B_0X5			(0x5u<<8)
#define	ADF_SADCR_HYSTEN_B_0X0			(0x0u<<7)
#define	ADF_SADCR_HYSTEN_B_0X1			(0x1u<<7)
#define	ADF_SADCR_SADST_B_0X0			(0x0u<<4)
#define	ADF_SADCR_SADST_B_0X1			(0x1u<<4)
#define	ADF_SADCR_SADST_B_0X3			(0x3u<<4)
#define	ADF_SADCR_DETCFG_B_0X0			(0x0u<<3)
#define	ADF_SADCR_DETCFG_B_0X1			(0x1u<<3)
#define	ADF_SADCR_DATCAP_B_0X0			(0x0u<<1)
#define	ADF_SADCR_DATCAP_B_0X1			(0x1u<<1)
#define	ADF_SADCR_SADEN_B_0X0			(0x0u<<0)
#define	ADF_SADCR_SADEN_B_0X1			(0x1u<<0)

// SADCFGR Configuration

#define	ADF_SADCFGR_ANMIN				(0x1FFFu<<16)
#define	ADF_SADCFGR_ANMIN_0				(0x1u<<16)
#define	ADF_SADCFGR_HGOVR				(0x7u<<12)
#define	ADF_SADCFGR_HGOVR_0				(0x1u<<12)
#define	ADF_SADCFGR_LFRNB				(0x7u<<8)
#define	ADF_SADCFGR_LFRNB_0				(0x1u<<8)
#define	ADF_SADCFGR_ANSLP				(0x7u<<4)
#define	ADF_SADCFGR_ANSLP_0				(0x1u<<4)
#define	ADF_SADCFGR_SNTHR				(0xFu<<0)
#define	ADF_SADCFGR_SNTHR_0				(0x1u<<0)

#define	ADF_SADCFGR_HGOVR_B_0X0			(0x0u<<12)
#define	ADF_SADCFGR_HGOVR_B_0X1			(0x1u<<12)
#define	ADF_SADCFGR_HGOVR_B_0X2			(0x2u<<12)
#define	ADF_SADCFGR_HGOVR_B_0X3			(0x3u<<12)
#define	ADF_SADCFGR_HGOVR_B_0X4			(0x4u<<12)
#define	ADF_SADCFGR_HGOVR_B_0X5			(0x5u<<12)
#define	ADF_SADCFGR_HGOVR_B_0X6			(0x6u<<12)
#define	ADF_SADCFGR_HGOVR_B_0X7			(0x7u<<12)
#define	ADF_SADCFGR_LFRNB_B_0X0			(0x0u<<8)
#define	ADF_SADCFGR_LFRNB_B_0X1			(0x1u<<8)
#define	ADF_SADCFGR_LFRNB_B_0X2			(0x2u<<8)
#define	ADF_SADCFGR_LFRNB_B_0X3			(0x3u<<8)
#define	ADF_SADCFGR_SNTHR_B_0X0			(0x0u<<0)
#define	ADF_SADCFGR_SNTHR_B_0X1			(0x1u<<0)
#define	ADF_SADCFGR_SNTHR_B_0X2			(0x2u<<0)
#define	ADF_SADCFGR_SNTHR_B_0X3			(0x3u<<0)
#define	ADF_SADCFGR_SNTHR_B_0X4			(0x4u<<0)
#define	ADF_SADCFGR_SNTHR_B_0X5			(0x5u<<0)
#define	ADF_SADCFGR_SNTHR_B_0X6			(0x6u<<0)
#define	ADF_SADCFGR_SNTHR_B_0X7			(0x7u<<0)
#define	ADF_SADCFGR_SNTHR_B_0X8			(0x8u<<0)
#define	ADF_SADCFGR_SNTHR_B_0X9			(0x9u<<0)

// SADSDLVR Configuration

#define	ADF_SADSDLVR_SDLVL				(0x7FFFu<<0)
#define	ADF_SADSDLVR_SDLVL_0			(0x1u<<0)

// SADANLVR Configuration

#define	ADF_SADANLVR_ANLVL				(0x7FFFu<<0)
#define	ADF_SADANLVR_ANLVL_0			(0x1u<<0)

// DFLT0DR Configuration

#define	ADF_DFLT0DR_DR					(0xFFFFFFu<<8)
#define	ADF_DFLT0DR_DR_0				(0x1u<<8)
