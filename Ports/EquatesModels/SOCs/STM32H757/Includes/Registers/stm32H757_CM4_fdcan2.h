/*
; stm32H757_CM4_fdcan2.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H757_CM4_fdcan2 equates.
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

// FDCAN2 address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	CREL;
	volatile	uint32_t	ENDN;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	DBTP;
	volatile	uint32_t	TEST;
	volatile	uint32_t	RWD;
	volatile	uint32_t	CCCR;
	volatile	uint32_t	NBTP;
	volatile	uint32_t	TSCC;
	volatile	uint32_t	TSCV;
	volatile	uint32_t	TOCC;
	volatile	uint32_t	TOCV;
	volatile	uint32_t	RESERVED1[4];
	volatile	uint32_t	ECR;
	volatile	uint32_t	PSR;
	volatile	uint32_t	TDCR;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	IR;
	volatile	uint32_t	IE;
	volatile	uint32_t	ILS;
	volatile	uint32_t	ILE;
	volatile	uint32_t	RESERVED3[8];
	volatile	uint32_t	GFC;
	volatile	uint32_t	SIDFC;
	volatile	uint32_t	XIDFC;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	XIDAM;
	volatile	uint32_t	HPMS;
	volatile	uint32_t	NDAT1;
	volatile	uint32_t	NDAT2;
	volatile	uint32_t	RXF0C;
	volatile	uint32_t	RXF0S;
	volatile	uint32_t	RXF0A;
	volatile	uint32_t	RXBC;
	volatile	uint32_t	RXF1C;
	volatile	uint32_t	RXF1S;
	volatile	uint32_t	RXF1A;
	volatile	uint32_t	RXESC;
	volatile	uint32_t	TXBC;
	volatile	uint32_t	TXFQS;
	volatile	uint32_t	TXESC;
	volatile	uint32_t	TXBRP;
	volatile	uint32_t	TXBAR;
	volatile	uint32_t	TXBCR;
	volatile	uint32_t	TXBTO;
	volatile	uint32_t	TXBCF;
	volatile	uint32_t	TXBTIE;
	volatile	uint32_t	TXBCIE;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	TXEFC;
	volatile	uint32_t	TXEFS;
	volatile	uint32_t	TXEFA;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	TTTMC;
	volatile	uint32_t	TTRMC;
	volatile	uint32_t	TTOCF;
	volatile	uint32_t	TTMLM;
	volatile	uint32_t	TURCF;
	volatile	uint32_t	TTOCN;
	volatile	uint32_t	CAN_TTGTP;
	volatile	uint32_t	TTTMK;
	volatile	uint32_t	TTIR;
	volatile	uint32_t	TTIE;
	volatile	uint32_t	TTILS;
	volatile	uint32_t	TTOST;
	volatile	uint32_t	TURNA;
	volatile	uint32_t	TTLGT;
	volatile	uint32_t	TTCTC;
	volatile	uint32_t	TTCPT;
	volatile	uint32_t	TTCSM;
	volatile	uint32_t	RESERVED7[111];
	volatile	uint32_t	TTTS;
} FDCAN2_TypeDef;

#if (defined(__cplusplus))
#define	FDCAN2	reinterpret_cast<FDCAN2_TypeDef *>(0x4000A400u)

#else
#define	FDCAN2	((FDCAN2_TypeDef *)0x4000A400u)
#endif

// CREL Configuration

#define	FDCAN2_CREL_DAY			(0xFFu<<0)
#define	FDCAN2_CREL_DAY_0		(0x1u<<0)
#define	FDCAN2_CREL_MON			(0xFFu<<8)
#define	FDCAN2_CREL_MON_0		(0x1u<<8)
#define	FDCAN2_CREL_YEAR		(0xFu<<16)
#define	FDCAN2_CREL_YEAR_0		(0x1u<<16)
#define	FDCAN2_CREL_SUBSTEP		(0xFu<<20)
#define	FDCAN2_CREL_SUBSTEP_0	(0x1u<<20)
#define	FDCAN2_CREL_STEP		(0xFu<<24)
#define	FDCAN2_CREL_STEP_0		(0x1u<<24)
#define	FDCAN2_CREL_REL			(0xFu<<28)
#define	FDCAN2_CREL_REL_0		(0x1u<<28)

// ENDN Configuration

#define	FDCAN2_ENDN_ETV			(0xFFFFFFFFu<<0)
#define	FDCAN2_ENDN_ETV_0		(0x1u<<0)

// DBTP Configuration

#define	FDCAN2_DBTP_TDC			(0x1u<<23)
#define	FDCAN2_DBTP_DBRP		(0x1Fu<<16)
#define	FDCAN2_DBTP_DBRP_0		(0x1u<<16)
#define	FDCAN2_DBTP_DTSEG1		(0x1Fu<<8)
#define	FDCAN2_DBTP_DTSEG1_0	(0x1u<<8)
#define	FDCAN2_DBTP_DTSEG2		(0xFu<<4)
#define	FDCAN2_DBTP_DTSEG2_0	(0x1u<<4)
#define	FDCAN2_DBTP_DSJW		(0xFu<<0)
#define	FDCAN2_DBTP_DSJW_0		(0x1u<<0)

// TEST Configuration

#define	FDCAN2_TEST_RX			(0x1u<<7)
#define	FDCAN2_TEST_TX			(0x3u<<5)
#define	FDCAN2_TEST_TX_0		(0x1u<<5)
#define	FDCAN2_TEST_LBCK		(0x1u<<4)

// RWD Configuration

#define	FDCAN2_RWD_WDC			(0xFFu<<0)
#define	FDCAN2_RWD_WDC_0		(0x1u<<0)
#define	FDCAN2_RWD_WDV			(0xFFu<<8)
#define	FDCAN2_RWD_WDV_0		(0x1u<<8)

// CCCR Configuration

#define	FDCAN2_CCCR_NISO		(0x1u<<15)
#define	FDCAN2_CCCR_TXP			(0x1u<<14)
#define	FDCAN2_CCCR_EFBI		(0x1u<<13)
#define	FDCAN2_CCCR_PXHD		(0x1u<<12)
#define	FDCAN2_CCCR_BSE			(0x1u<<9)
#define	FDCAN2_CCCR_FDOE		(0x1u<<8)
#define	FDCAN2_CCCR_TEST		(0x1u<<7)
#define	FDCAN2_CCCR_DAR			(0x1u<<6)
#define	FDCAN2_CCCR_MON			(0x1u<<5)
#define	FDCAN2_CCCR_CSR			(0x1u<<4)
#define	FDCAN2_CCCR_CSA			(0x1u<<3)
#define	FDCAN2_CCCR_ASM			(0x1u<<2)
#define	FDCAN2_CCCR_CCE			(0x1u<<1)
#define	FDCAN2_CCCR_INIT		(0x1u<<0)

// NBTP Configuration

#define	FDCAN2_NBTP_TSEG2		(0x7Fu<<0)
#define	FDCAN2_NBTP_TSEG2_0		(0x1u<<0)
#define	FDCAN2_NBTP_NTSEG1		(0xFFu<<8)
#define	FDCAN2_NBTP_NTSEG1_0	(0x1u<<8)
#define	FDCAN2_NBTP_NBRP		(0x1FFu<<16)
#define	FDCAN2_NBTP_NBRP_0		(0x1u<<16)
#define	FDCAN2_NBTP_NSJW		(0x7Fu<<25)
#define	FDCAN2_NBTP_NSJW_0		(0x1u<<25)

// TSCC Configuration

#define	FDCAN2_TSCC_TSS			(0x3u<<0)
#define	FDCAN2_TSCC_TSS_0		(0x1u<<0)
#define	FDCAN2_TSCC_TCP			(0xFu<<16)
#define	FDCAN2_TSCC_TCP_0		(0x1u<<16)

// TSCV Configuration

#define	FDCAN2_TSCV_TSC			(0xFFFFu<<0)
#define	FDCAN2_TSCV_TSC_0		(0x1u<<0)

// TOCC Configuration

#define	FDCAN2_TOCC_TOP			(0xFFFFu<<16)
#define	FDCAN2_TOCC_TOP_0		(0x1u<<16)
#define	FDCAN2_TOCC_TOS			(0x3u<<1)
#define	FDCAN2_TOCC_TOS_0		(0x1u<<1)
#define	FDCAN2_TOCC_ETOC		(0x1u<<0)

// TOCV Configuration

#define	FDCAN2_TOCV_TOC			(0xFFFFu<<0)
#define	FDCAN2_TOCV_TOC_0		(0x1u<<0)

// ECR Configuration

#define	FDCAN2_ECR_TEC			(0xFFu<<0)
#define	FDCAN2_ECR_TEC_0		(0x1u<<0)
#define	FDCAN2_ECR_TREC			(0x7Fu<<8)
#define	FDCAN2_ECR_TREC_0		(0x1u<<8)
#define	FDCAN2_ECR_RP			(0x1u<<15)
#define	FDCAN2_ECR_CEL			(0xFFu<<16)
#define	FDCAN2_ECR_CEL_0		(0x1u<<16)

// PSR Configuration

#define	FDCAN2_PSR_TDCV			(0x7Fu<<16)
#define	FDCAN2_PSR_TDCV_0		(0x1u<<16)
#define	FDCAN2_PSR_PXE			(0x1u<<14)
#define	FDCAN2_PSR_REDL			(0x1u<<13)
#define	FDCAN2_PSR_RBRS			(0x1u<<12)
#define	FDCAN2_PSR_RESI			(0x1u<<11)
#define	FDCAN2_PSR_DLEC			(0x7u<<8)
#define	FDCAN2_PSR_DLEC_0		(0x1u<<8)
#define	FDCAN2_PSR_BO			(0x1u<<7)
#define	FDCAN2_PSR_EW			(0x1u<<6)
#define	FDCAN2_PSR_EP			(0x1u<<5)
#define	FDCAN2_PSR_ACT			(0x3u<<3)
#define	FDCAN2_PSR_ACT_0		(0x1u<<3)
#define	FDCAN2_PSR_LEC			(0x7u<<0)
#define	FDCAN2_PSR_LEC_0		(0x1u<<0)

// TDCR Configuration

#define	FDCAN2_TDCR_TDCO		(0x7Fu<<8)
#define	FDCAN2_TDCR_TDCO_0		(0x1u<<8)
#define	FDCAN2_TDCR_TDCF		(0x7Fu<<0)
#define	FDCAN2_TDCR_TDCF_0		(0x1u<<0)

// IR Configuration

#define	FDCAN2_IR_ARA			(0x1u<<29)
#define	FDCAN2_IR_PED			(0x1u<<28)
#define	FDCAN2_IR_PEA			(0x1u<<27)
#define	FDCAN2_IR_WDI			(0x1u<<26)
#define	FDCAN2_IR_BO			(0x1u<<25)
#define	FDCAN2_IR_EW			(0x1u<<24)
#define	FDCAN2_IR_EP			(0x1u<<23)
#define	FDCAN2_IR_ELO			(0x1u<<22)
#define	FDCAN2_IR_DRX			(0x1u<<19)
#define	FDCAN2_IR_TOO			(0x1u<<18)
#define	FDCAN2_IR_MRAF			(0x1u<<17)
#define	FDCAN2_IR_TSW			(0x1u<<16)
#define	FDCAN2_IR_TEFL			(0x1u<<15)
#define	FDCAN2_IR_TEFF			(0x1u<<14)
#define	FDCAN2_IR_TEFW			(0x1u<<13)
#define	FDCAN2_IR_TEFN			(0x1u<<12)
#define	FDCAN2_IR_TEF			(0x1u<<11)
#define	FDCAN2_IR_TCF			(0x1u<<10)
#define	FDCAN2_IR_TC			(0x1u<<9)
#define	FDCAN2_IR_HPM			(0x1u<<8)
#define	FDCAN2_IR_RF1L			(0x1u<<7)
#define	FDCAN2_IR_RF1F			(0x1u<<6)
#define	FDCAN2_IR_RF1W			(0x1u<<5)
#define	FDCAN2_IR_RF1N			(0x1u<<4)
#define	FDCAN2_IR_RF0L			(0x1u<<3)
#define	FDCAN2_IR_RF0F			(0x1u<<2)
#define	FDCAN2_IR_RF0W			(0x1u<<1)
#define	FDCAN2_IR_RF0N			(0x1u<<0)

// IE Configuration

#define	FDCAN2_IE_ARAE			(0x1u<<29)
#define	FDCAN2_IE_PEDE			(0x1u<<28)
#define	FDCAN2_IE_PEAE			(0x1u<<27)
#define	FDCAN2_IE_WDIE			(0x1u<<26)
#define	FDCAN2_IE_BOE			(0x1u<<25)
#define	FDCAN2_IE_EWE			(0x1u<<24)
#define	FDCAN2_IE_EPE			(0x1u<<23)
#define	FDCAN2_IE_ELOE			(0x1u<<22)
#define	FDCAN2_IE_BEUE			(0x1u<<21)
#define	FDCAN2_IE_BECE			(0x1u<<20)
#define	FDCAN2_IE_DRXE			(0x1u<<19)
#define	FDCAN2_IE_TOOE			(0x1u<<18)
#define	FDCAN2_IE_MRAFE			(0x1u<<17)
#define	FDCAN2_IE_TSWE			(0x1u<<16)
#define	FDCAN2_IE_TEFLE			(0x1u<<15)
#define	FDCAN2_IE_TEFFE			(0x1u<<14)
#define	FDCAN2_IE_TEFWE			(0x1u<<13)
#define	FDCAN2_IE_TEFNE			(0x1u<<12)
#define	FDCAN2_IE_TEFE			(0x1u<<11)
#define	FDCAN2_IE_TCFE			(0x1u<<10)
#define	FDCAN2_IE_TCE			(0x1u<<9)
#define	FDCAN2_IE_HPME			(0x1u<<8)
#define	FDCAN2_IE_RF1LE			(0x1u<<7)
#define	FDCAN2_IE_RF1FE			(0x1u<<6)
#define	FDCAN2_IE_RF1WE			(0x1u<<5)
#define	FDCAN2_IE_RF1NE			(0x1u<<4)
#define	FDCAN2_IE_RF0LE			(0x1u<<3)
#define	FDCAN2_IE_RF0FE			(0x1u<<2)
#define	FDCAN2_IE_RF0WE			(0x1u<<1)
#define	FDCAN2_IE_RF0NE			(0x1u<<0)

// ILS Configuration

#define	FDCAN2_ILS_ARAL			(0x1u<<29)
#define	FDCAN2_ILS_PEDL			(0x1u<<28)
#define	FDCAN2_ILS_PEAL			(0x1u<<27)
#define	FDCAN2_ILS_WDIL			(0x1u<<26)
#define	FDCAN2_ILS_BOL			(0x1u<<25)
#define	FDCAN2_ILS_EWL			(0x1u<<24)
#define	FDCAN2_ILS_EPL			(0x1u<<23)
#define	FDCAN2_ILS_ELOL			(0x1u<<22)
#define	FDCAN2_ILS_BEUL			(0x1u<<21)
#define	FDCAN2_ILS_BECL			(0x1u<<20)
#define	FDCAN2_ILS_DRXL			(0x1u<<19)
#define	FDCAN2_ILS_TOOL			(0x1u<<18)
#define	FDCAN2_ILS_MRAFL		(0x1u<<17)
#define	FDCAN2_ILS_TSWL			(0x1u<<16)
#define	FDCAN2_ILS_TEFLL		(0x1u<<15)
#define	FDCAN2_ILS_TEFFL		(0x1u<<14)
#define	FDCAN2_ILS_TEFWL		(0x1u<<13)
#define	FDCAN2_ILS_TEFNL		(0x1u<<12)
#define	FDCAN2_ILS_TEFL			(0x1u<<11)
#define	FDCAN2_ILS_TCFL			(0x1u<<10)
#define	FDCAN2_ILS_TCL			(0x1u<<9)
#define	FDCAN2_ILS_HPML			(0x1u<<8)
#define	FDCAN2_ILS_RF1LL		(0x1u<<7)
#define	FDCAN2_ILS_RF1FL		(0x1u<<6)
#define	FDCAN2_ILS_RF1WL		(0x1u<<5)
#define	FDCAN2_ILS_RF1NL		(0x1u<<4)
#define	FDCAN2_ILS_RF0LL		(0x1u<<3)
#define	FDCAN2_ILS_RF0FL		(0x1u<<2)
#define	FDCAN2_ILS_RF0WL		(0x1u<<1)
#define	FDCAN2_ILS_RF0NL		(0x1u<<0)

// ILE Configuration

#define	FDCAN2_ILE_EINT1		(0x1u<<1)
#define	FDCAN2_ILE_EINT0		(0x1u<<0)

// GFC Configuration

#define	FDCAN2_GFC_ANFS			(0x3u<<4)
#define	FDCAN2_GFC_ANFS_0		(0x1u<<4)
#define	FDCAN2_GFC_ANFE			(0x3u<<2)
#define	FDCAN2_GFC_ANFE_0		(0x1u<<2)
#define	FDCAN2_GFC_RRFS			(0x1u<<1)
#define	FDCAN2_GFC_RRFE			(0x1u<<0)

// SIDFC Configuration

#define	FDCAN2_SIDFC_LSS		(0xFFu<<16)
#define	FDCAN2_SIDFC_LSS_0		(0x1u<<16)
#define	FDCAN2_SIDFC_FLSSA		(0x3FFFu<<2)
#define	FDCAN2_SIDFC_FLSSA_0	(0x1u<<2)

// XIDFC Configuration

#define	FDCAN2_XIDFC_LSE		(0xFFu<<16)
#define	FDCAN2_XIDFC_LSE_0		(0x1u<<16)
#define	FDCAN2_XIDFC_FLESA		(0x3FFFu<<2)
#define	FDCAN2_XIDFC_FLESA_0	(0x1u<<2)

// XIDAM Configuration

#define	FDCAN2_XIDAM_EIDM		(0x1FFFFFFFu<<0)
#define	FDCAN2_XIDAM_EIDM_0		(0x1u<<0)

// HPMS Configuration

#define	FDCAN2_HPMS_FLST		(0x1u<<15)
#define	FDCAN2_HPMS_FIDX		(0x7Fu<<8)
#define	FDCAN2_HPMS_FIDX_0		(0x1u<<8)
#define	FDCAN2_HPMS_MSI			(0x3u<<6)
#define	FDCAN2_HPMS_MSI_0		(0x1u<<6)
#define	FDCAN2_HPMS_BIDX		(0x3Fu<<0)
#define	FDCAN2_HPMS_BIDX_0		(0x1u<<0)

// NDAT1 Configuration

#define	FDCAN2_NDAT1_ND31		(0x1u<<31)
#define	FDCAN2_NDAT1_ND30		(0x1u<<30)
#define	FDCAN2_NDAT1_ND29		(0x1u<<29)
#define	FDCAN2_NDAT1_ND28		(0x1u<<28)
#define	FDCAN2_NDAT1_ND27		(0x1u<<27)
#define	FDCAN2_NDAT1_ND26		(0x1u<<26)
#define	FDCAN2_NDAT1_ND25		(0x1u<<25)
#define	FDCAN2_NDAT1_ND24		(0x1u<<24)
#define	FDCAN2_NDAT1_ND23		(0x1u<<23)
#define	FDCAN2_NDAT1_ND22		(0x1u<<22)
#define	FDCAN2_NDAT1_ND21		(0x1u<<21)
#define	FDCAN2_NDAT1_ND20		(0x1u<<20)
#define	FDCAN2_NDAT1_ND19		(0x1u<<19)
#define	FDCAN2_NDAT1_ND18		(0x1u<<18)
#define	FDCAN2_NDAT1_ND17		(0x1u<<17)
#define	FDCAN2_NDAT1_ND16		(0x1u<<16)
#define	FDCAN2_NDAT1_ND15		(0x1u<<15)
#define	FDCAN2_NDAT1_ND14		(0x1u<<14)
#define	FDCAN2_NDAT1_ND13		(0x1u<<13)
#define	FDCAN2_NDAT1_ND12		(0x1u<<12)
#define	FDCAN2_NDAT1_ND11		(0x1u<<11)
#define	FDCAN2_NDAT1_ND10		(0x1u<<10)
#define	FDCAN2_NDAT1_ND9		(0x1u<<9)
#define	FDCAN2_NDAT1_ND8		(0x1u<<8)
#define	FDCAN2_NDAT1_ND7		(0x1u<<7)
#define	FDCAN2_NDAT1_ND6		(0x1u<<6)
#define	FDCAN2_NDAT1_ND5		(0x1u<<5)
#define	FDCAN2_NDAT1_ND4		(0x1u<<4)
#define	FDCAN2_NDAT1_ND3		(0x1u<<3)
#define	FDCAN2_NDAT1_ND2		(0x1u<<2)
#define	FDCAN2_NDAT1_ND1		(0x1u<<1)
#define	FDCAN2_NDAT1_ND0		(0x1u<<0)

// NDAT2 Configuration

#define	FDCAN2_NDAT2_ND63		(0x1u<<31)
#define	FDCAN2_NDAT2_ND62		(0x1u<<30)
#define	FDCAN2_NDAT2_ND61		(0x1u<<29)
#define	FDCAN2_NDAT2_ND60		(0x1u<<28)
#define	FDCAN2_NDAT2_ND59		(0x1u<<27)
#define	FDCAN2_NDAT2_ND58		(0x1u<<26)
#define	FDCAN2_NDAT2_ND57		(0x1u<<25)
#define	FDCAN2_NDAT2_ND56		(0x1u<<24)
#define	FDCAN2_NDAT2_ND55		(0x1u<<23)
#define	FDCAN2_NDAT2_ND54		(0x1u<<22)
#define	FDCAN2_NDAT2_ND53		(0x1u<<21)
#define	FDCAN2_NDAT2_ND52		(0x1u<<20)
#define	FDCAN2_NDAT2_ND51		(0x1u<<19)
#define	FDCAN2_NDAT2_ND50		(0x1u<<18)
#define	FDCAN2_NDAT2_ND49		(0x1u<<17)
#define	FDCAN2_NDAT2_ND48		(0x1u<<16)
#define	FDCAN2_NDAT2_ND47		(0x1u<<15)
#define	FDCAN2_NDAT2_ND46		(0x1u<<14)
#define	FDCAN2_NDAT2_ND45		(0x1u<<13)
#define	FDCAN2_NDAT2_ND44		(0x1u<<12)
#define	FDCAN2_NDAT2_ND43		(0x1u<<11)
#define	FDCAN2_NDAT2_ND42		(0x1u<<10)
#define	FDCAN2_NDAT2_ND41		(0x1u<<9)
#define	FDCAN2_NDAT2_ND40		(0x1u<<8)
#define	FDCAN2_NDAT2_ND39		(0x1u<<7)
#define	FDCAN2_NDAT2_ND38		(0x1u<<6)
#define	FDCAN2_NDAT2_ND37		(0x1u<<5)
#define	FDCAN2_NDAT2_ND36		(0x1u<<4)
#define	FDCAN2_NDAT2_ND35		(0x1u<<3)
#define	FDCAN2_NDAT2_ND34		(0x1u<<2)
#define	FDCAN2_NDAT2_ND33		(0x1u<<1)
#define	FDCAN2_NDAT2_ND32		(0x1u<<0)

// RXF0C Configuration

#define	FDCAN2_RXF0C_F0WM		(0xFFu<<24)
#define	FDCAN2_RXF0C_F0WM_0		(0x1u<<24)
#define	FDCAN2_RXF0C_F0S		(0xFFu<<16)
#define	FDCAN2_RXF0C_F0S_0		(0x1u<<16)
#define	FDCAN2_RXF0C_F0SA		(0x3FFFu<<2)
#define	FDCAN2_RXF0C_F0SA_0		(0x1u<<2)

// RXF0S Configuration

#define	FDCAN2_RXF0S_RF0L		(0x1u<<25)
#define	FDCAN2_RXF0S_F0F		(0x1u<<24)
#define	FDCAN2_RXF0S_F0P		(0x3Fu<<16)
#define	FDCAN2_RXF0S_F0P_0		(0x1u<<16)
#define	FDCAN2_RXF0S_F0G		(0x3Fu<<8)
#define	FDCAN2_RXF0S_F0G_0		(0x1u<<8)
#define	FDCAN2_RXF0S_F0FL		(0x7Fu<<0)
#define	FDCAN2_RXF0S_F0FL_0		(0x1u<<0)

// RXF0A Configuration

#define	FDCAN2_RXF0A_FA01		(0x3Fu<<0)
#define	FDCAN2_RXF0A_FA01_0		(0x1u<<0)

// RXBC Configuration

#define	FDCAN2_RXBC_RBSA		(0x3FFFu<<2)
#define	FDCAN2_RXBC_RBSA_0		(0x1u<<2)

// RXF1C Configuration

#define	FDCAN2_RXF1C_F1WM		(0x7Fu<<24)
#define	FDCAN2_RXF1C_F1WM_0		(0x1u<<24)
#define	FDCAN2_RXF1C_F1S		(0x7Fu<<16)
#define	FDCAN2_RXF1C_F1S_0		(0x1u<<16)
#define	FDCAN2_RXF1C_F1SA		(0x3FFFu<<2)
#define	FDCAN2_RXF1C_F1SA_0		(0x1u<<2)

// RXF1S Configuration

#define	FDCAN2_RXF1S_DMS		(0x3u<<30)
#define	FDCAN2_RXF1S_DMS_0		(0x1u<<30)
#define	FDCAN2_RXF1S_RF1L		(0x1u<<25)
#define	FDCAN2_RXF1S_F1F		(0x1u<<24)
#define	FDCAN2_RXF1S_F1PI		(0x7Fu<<16)
#define	FDCAN2_RXF1S_F1PI_0		(0x1u<<16)
#define	FDCAN2_RXF1S_F1GI		(0x7Fu<<8)
#define	FDCAN2_RXF1S_F1GI_0		(0x1u<<8)
#define	FDCAN2_RXF1S_F1FL		(0x7Fu<<0)
#define	FDCAN2_RXF1S_F1FL_0		(0x1u<<0)

// RXF1A Configuration

#define	FDCAN2_RXF1A_F1AI		(0x3Fu<<0)
#define	FDCAN2_RXF1A_F1AI_0		(0x1u<<0)

// RXESC Configuration

#define	FDCAN2_RXESC_RBDS		(0x7u<<8)
#define	FDCAN2_RXESC_RBDS_0		(0x1u<<8)
#define	FDCAN2_RXESC_F1DS		(0x7u<<4)
#define	FDCAN2_RXESC_F1DS_0		(0x1u<<4)
#define	FDCAN2_RXESC_F0DS		(0x7u<<0)
#define	FDCAN2_RXESC_F0DS_0		(0x1u<<0)

// TXBC Configuration

#define	FDCAN2_TXBC_TFQM		(0x1u<<30)
#define	FDCAN2_TXBC_TFQS		(0x3Fu<<24)
#define	FDCAN2_TXBC_TFQS_0		(0x1u<<24)
#define	FDCAN2_TXBC_NDTB		(0x3Fu<<16)
#define	FDCAN2_TXBC_NDTB_0		(0x1u<<16)
#define	FDCAN2_TXBC_TBSA		(0x3FFFu<<2)
#define	FDCAN2_TXBC_TBSA_0		(0x1u<<2)

// TXFQS Configuration

#define	FDCAN2_TXFQS_TFQF		(0x1u<<21)
#define	FDCAN2_TXFQS_TFQPI		(0x1Fu<<16)
#define	FDCAN2_TXFQS_TFQPI_0	(0x1u<<16)
#define	FDCAN2_TXFQS_TFGI		(0x1Fu<<8)
#define	FDCAN2_TXFQS_TFGI_0		(0x1u<<8)
#define	FDCAN2_TXFQS_TFFL		(0x3Fu<<0)
#define	FDCAN2_TXFQS_TFFL_0		(0x1u<<0)

// TXESC Configuration

#define	FDCAN2_TXESC_TBDS		(0x7u<<0)
#define	FDCAN2_TXESC_TBDS_0		(0x1u<<0)

// TXBRP Configuration

#define	FDCAN2_TXBRP_TRP		(0xFFFFFFFFu<<0)
#define	FDCAN2_TXBRP_TRP_0		(0x1u<<0)

// TXBAR Configuration

#define	FDCAN2_TXBAR_AR			(0xFFFFFFFFu<<0)
#define	FDCAN2_TXBAR_AR_0		(0x1u<<0)

// TXBCR Configuration

#define	FDCAN2_TXBCR_CR			(0xFFFFFFFFu<<0)
#define	FDCAN2_TXBCR_CR_0		(0x1u<<0)

// TXBTO Configuration

#define	FDCAN2_TXBTO_TO			(0xFFFFFFFFu<<0)
#define	FDCAN2_TXBTO_TO_0		(0x1u<<0)

// TXBCF Configuration

#define	FDCAN2_TXBCF_CF			(0xFFFFFFFFu<<0)
#define	FDCAN2_TXBCF_CF_0		(0x1u<<0)

// TXBTIE Configuration

#define	FDCAN2_TXBTIE_TIE		(0xFFFFFFFFu<<0)
#define	FDCAN2_TXBTIE_TIE_0		(0x1u<<0)

// TXBCIE Configuration

#define	FDCAN2_TXBCIE_CF		(0xFFFFFFFFu<<0)
#define	FDCAN2_TXBCIE_CF_0		(0x1u<<0)

// TXEFC Configuration

#define	FDCAN2_TXEFC_EFWM		(0x3Fu<<24)
#define	FDCAN2_TXEFC_EFWM_0		(0x1u<<24)
#define	FDCAN2_TXEFC_EFS		(0x3Fu<<16)
#define	FDCAN2_TXEFC_EFS_0		(0x1u<<16)
#define	FDCAN2_TXEFC_EFSA		(0x3FFFu<<2)
#define	FDCAN2_TXEFC_EFSA_0		(0x1u<<2)

// TXEFS Configuration

#define	FDCAN2_TXEFS_TEFL		(0x1u<<25)
#define	FDCAN2_TXEFS_EFF		(0x1u<<24)
#define	FDCAN2_TXEFS_EFPI		(0x1Fu<<16)
#define	FDCAN2_TXEFS_EFPI_0		(0x1u<<16)
#define	FDCAN2_TXEFS_EFGI		(0x1Fu<<8)
#define	FDCAN2_TXEFS_EFGI_0		(0x1u<<8)
#define	FDCAN2_TXEFS_EFFL		(0x3Fu<<0)
#define	FDCAN2_TXEFS_EFFL_0		(0x1u<<0)

// TXEFA Configuration

#define	FDCAN2_TXEFA_EFAI		(0x1Fu<<0)
#define	FDCAN2_TXEFA_EFAI_0		(0x1u<<0)

// TTTMC Configuration

#define	FDCAN2_TTTMC_TME		(0x7Fu<<16)
#define	FDCAN2_TTTMC_TME_0		(0x1u<<16)
#define	FDCAN2_TTTMC_TMSA		(0x3FFFu<<2)
#define	FDCAN2_TTTMC_TMSA_0		(0x1u<<2)

// TTRMC Configuration

#define	FDCAN2_TTRMC_RMPS		(0x1u<<31)
#define	FDCAN2_TTRMC_XTD		(0x1u<<30)
#define	FDCAN2_TTRMC_RID		(0x1FFFFFFFu<<0)
#define	FDCAN2_TTRMC_RID_0		(0x1u<<0)

// TTOCF Configuration

#define	FDCAN2_TTOCF_EVTP		(0x1u<<26)
#define	FDCAN2_TTOCF_ECC		(0x1u<<25)
#define	FDCAN2_TTOCF_EGTF		(0x1u<<24)
#define	FDCAN2_TTOCF_AWL		(0xFFu<<16)
#define	FDCAN2_TTOCF_AWL_0		(0x1u<<16)
#define	FDCAN2_TTOCF_EECS		(0x1u<<15)
#define	FDCAN2_TTOCF_IRTO		(0x7Fu<<8)
#define	FDCAN2_TTOCF_IRTO_0		(0x1u<<8)
#define	FDCAN2_TTOCF_LDSDL		(0x7u<<5)
#define	FDCAN2_TTOCF_LDSDL_0	(0x1u<<5)
#define	FDCAN2_TTOCF_TM			(0x1u<<4)
#define	FDCAN2_TTOCF_GEN		(0x1u<<3)
#define	FDCAN2_TTOCF_OM			(0x3u<<0)
#define	FDCAN2_TTOCF_OM_0		(0x1u<<0)

// TTMLM Configuration

#define	FDCAN2_TTMLM_ENTT		(0xFFFu<<16)
#define	FDCAN2_TTMLM_ENTT_0		(0x1u<<16)
#define	FDCAN2_TTMLM_TXEW		(0xFu<<8)
#define	FDCAN2_TTMLM_TXEW_0		(0x1u<<8)
#define	FDCAN2_TTMLM_CSS		(0x3u<<6)
#define	FDCAN2_TTMLM_CSS_0		(0x1u<<6)
#define	FDCAN2_TTMLM_CCM		(0x3Fu<<0)
#define	FDCAN2_TTMLM_CCM_0		(0x1u<<0)

// TURCF Configuration

#define	FDCAN2_TURCF_ELT		(0x1u<<31)
#define	FDCAN2_TURCF_DC			(0x3FFFu<<16)
#define	FDCAN2_TURCF_DC_0		(0x1u<<16)
#define	FDCAN2_TURCF_NCL		(0xFFFFu<<0)
#define	FDCAN2_TURCF_NCL_0		(0x1u<<0)

// TTOCN Configuration

#define	FDCAN2_TTOCN_LCKC		(0x1u<<15)
#define	FDCAN2_TTOCN_ESCN		(0x1u<<13)
#define	FDCAN2_TTOCN_NIG		(0x1u<<12)
#define	FDCAN2_TTOCN_TMG		(0x1u<<11)
#define	FDCAN2_TTOCN_FGP		(0x1u<<10)
#define	FDCAN2_TTOCN_GCS		(0x1u<<9)
#define	FDCAN2_TTOCN_TTIE		(0x1u<<8)
#define	FDCAN2_TTOCN_TMC		(0x3u<<6)
#define	FDCAN2_TTOCN_TMC_0		(0x1u<<6)
#define	FDCAN2_TTOCN_RTIE		(0x1u<<5)
#define	FDCAN2_TTOCN_SWS		(0x3u<<3)
#define	FDCAN2_TTOCN_SWS_0		(0x1u<<3)
#define	FDCAN2_TTOCN_SWP		(0x1u<<2)
#define	FDCAN2_TTOCN_ECS		(0x1u<<1)
#define	FDCAN2_TTOCN_SGT		(0x1u<<0)

// CAN_TTGTP Configuration

#define	FDCAN2_CAN_TTGTP_CTP	(0xFFFFu<<16)
#define	FDCAN2_CAN_TTGTP_CTP_0	(0x1u<<16)
#define	FDCAN2_CAN_TTGTP_NCL	(0xFFFFu<<0)
#define	FDCAN2_CAN_TTGTP_NCL_0	(0x1u<<0)

// TTTMK Configuration

#define	FDCAN2_TTTMK_LCKM		(0x1u<<31)
#define	FDCAN2_TTTMK_TICC		(0x7Fu<<16)
#define	FDCAN2_TTTMK_TICC_0		(0x1u<<16)
#define	FDCAN2_TTTMK_TM			(0xFFFFu<<0)
#define	FDCAN2_TTTMK_TM_0		(0x1u<<0)

// TTIR Configuration

#define	FDCAN2_TTIR_CER			(0x1u<<18)
#define	FDCAN2_TTIR_AW			(0x1u<<17)
#define	FDCAN2_TTIR_WT			(0x1u<<16)
#define	FDCAN2_TTIR_IWTG		(0x1u<<15)
#define	FDCAN2_TTIR_ELC			(0x1u<<14)
#define	FDCAN2_TTIR_SE2			(0x1u<<13)
#define	FDCAN2_TTIR_SE1			(0x1u<<12)
#define	FDCAN2_TTIR_TXO			(0x1u<<11)
#define	FDCAN2_TTIR_TXU			(0x1u<<10)
#define	FDCAN2_TTIR_GTE			(0x1u<<9)
#define	FDCAN2_TTIR_GTD			(0x1u<<8)
#define	FDCAN2_TTIR_GTW			(0x1u<<7)
#define	FDCAN2_TTIR_SWE			(0x1u<<6)
#define	FDCAN2_TTIR_TTMI		(0x1u<<5)
#define	FDCAN2_TTIR_RTMI		(0x1u<<4)
#define	FDCAN2_TTIR_SOG			(0x1u<<3)
#define	FDCAN2_TTIR_CSM			(0x1u<<2)
#define	FDCAN2_TTIR_SMC			(0x1u<<1)
#define	FDCAN2_TTIR_SBC			(0x1u<<0)

// TTIE Configuration

#define	FDCAN2_TTIE_CERE		(0x1u<<18)
#define	FDCAN2_TTIE_AWE			(0x1u<<17)
#define	FDCAN2_TTIE_WTE			(0x1u<<16)
#define	FDCAN2_TTIE_IWTGE		(0x1u<<15)
#define	FDCAN2_TTIE_ELCE		(0x1u<<14)
#define	FDCAN2_TTIE_SE2E		(0x1u<<13)
#define	FDCAN2_TTIE_SE1E		(0x1u<<12)
#define	FDCAN2_TTIE_TXOE		(0x1u<<11)
#define	FDCAN2_TTIE_TXUE		(0x1u<<10)
#define	FDCAN2_TTIE_GTEE		(0x1u<<9)
#define	FDCAN2_TTIE_GTDE		(0x1u<<8)
#define	FDCAN2_TTIE_GTWE		(0x1u<<7)
#define	FDCAN2_TTIE_SWEE		(0x1u<<6)
#define	FDCAN2_TTIE_TTMIE		(0x1u<<5)
#define	FDCAN2_TTIE_RTMIE		(0x1u<<4)
#define	FDCAN2_TTIE_SOGE		(0x1u<<3)
#define	FDCAN2_TTIE_CSME		(0x1u<<2)
#define	FDCAN2_TTIE_SMCE		(0x1u<<1)
#define	FDCAN2_TTIE_SBCE		(0x1u<<0)

// TTILS Configuration

#define	FDCAN2_TTILS_CERL		(0x1u<<18)
#define	FDCAN2_TTILS_AWL		(0x1u<<17)
#define	FDCAN2_TTILS_WTL		(0x1u<<16)
#define	FDCAN2_TTILS_IWTGL		(0x1u<<15)
#define	FDCAN2_TTILS_ELCL		(0x1u<<14)
#define	FDCAN2_TTILS_SE2L		(0x1u<<13)
#define	FDCAN2_TTILS_SE1L		(0x1u<<12)
#define	FDCAN2_TTILS_TXOL		(0x1u<<11)
#define	FDCAN2_TTILS_TXUL		(0x1u<<10)
#define	FDCAN2_TTILS_GTEL		(0x1u<<9)
#define	FDCAN2_TTILS_GTDL		(0x1u<<8)
#define	FDCAN2_TTILS_GTWL		(0x1u<<7)
#define	FDCAN2_TTILS_SWEL		(0x1u<<6)
#define	FDCAN2_TTILS_TTMIL		(0x1u<<5)
#define	FDCAN2_TTILS_RTMIL		(0x1u<<4)
#define	FDCAN2_TTILS_SOGL		(0x1u<<3)
#define	FDCAN2_TTILS_CSML		(0x1u<<2)
#define	FDCAN2_TTILS_SMCL		(0x1u<<1)
#define	FDCAN2_TTILS_SBCL		(0x1u<<0)

// TTOST Configuration

#define	FDCAN2_TTOST_SPL		(0x1u<<31)
#define	FDCAN2_TTOST_WECS		(0x1u<<30)
#define	FDCAN2_TTOST_AWE		(0x1u<<29)
#define	FDCAN2_TTOST_WFE		(0x1u<<28)
#define	FDCAN2_TTOST_GSI		(0x1u<<27)
#define	FDCAN2_TTOST_TMP		(0x7u<<24)
#define	FDCAN2_TTOST_TMP_0		(0x1u<<24)
#define	FDCAN2_TTOST_GFI		(0x1u<<23)
#define	FDCAN2_TTOST_WGTD		(0x1u<<22)
#define	FDCAN2_TTOST_RTO		(0xFFu<<8)
#define	FDCAN2_TTOST_RTO_0		(0x1u<<8)
#define	FDCAN2_TTOST_QCS		(0x1u<<7)
#define	FDCAN2_TTOST_GTP		(0x1u<<6)
#define	FDCAN2_TTOST_SYS		(0x3u<<4)
#define	FDCAN2_TTOST_SYS_0		(0x1u<<4)
#define	FDCAN2_TTOST_MS			(0x3u<<2)
#define	FDCAN2_TTOST_MS_0		(0x1u<<2)
#define	FDCAN2_TTOST_EL			(0x3u<<0)
#define	FDCAN2_TTOST_EL_0		(0x1u<<0)

// TURNA Configuration

#define	FDCAN2_TURNA_NAV		(0x3FFFFu<<0)
#define	FDCAN2_TURNA_NAV_0		(0x1u<<0)

// TTLGT Configuration

#define	FDCAN2_TTLGT_GT			(0xFFFFu<<16)
#define	FDCAN2_TTLGT_GT_0		(0x1u<<16)
#define	FDCAN2_TTLGT_LT			(0xFFFFu<<0)
#define	FDCAN2_TTLGT_LT_0		(0x1u<<0)

// TTCTC Configuration

#define	FDCAN2_TTCTC_CC			(0x3Fu<<16)
#define	FDCAN2_TTCTC_CC_0		(0x1u<<16)
#define	FDCAN2_TTCTC_CT			(0xFFFFu<<0)
#define	FDCAN2_TTCTC_CT_0		(0x1u<<0)

// TTCPT Configuration

#define	FDCAN2_TTCPT_SWV		(0xFFFFu<<16)
#define	FDCAN2_TTCPT_SWV_0		(0x1u<<16)
#define	FDCAN2_TTCPT_CT			(0x3Fu<<0)
#define	FDCAN2_TTCPT_CT_0		(0x1u<<0)

// TTCSM Configuration

#define	FDCAN2_TTCSM_CSM		(0xFFFFu<<0)
#define	FDCAN2_TTCSM_CSM_0		(0x1u<<0)

// TTTS Configuration

#define	FDCAN2_TTTS_EVTSEL		(0x3u<<4)
#define	FDCAN2_TTTS_EVTSEL_0	(0x1u<<4)
#define	FDCAN2_TTTS_SWTDEL		(0x3u<<0)
#define	FDCAN2_TTTS_SWTDEL_0	(0x1u<<0)
