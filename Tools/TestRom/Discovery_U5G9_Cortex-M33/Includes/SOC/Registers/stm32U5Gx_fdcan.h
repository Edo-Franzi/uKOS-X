/*
; stm32U5Gx_fdcan.
; ================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_fdcan equates.
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

// FDCAN address definitions
// -------------------------

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
	volatile	uint32_t	RXGFC;
	volatile	uint32_t	XIDAM;
	volatile	uint32_t	HPMS;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	RXF0S;
	volatile	uint32_t	RXF0A;
	volatile	uint32_t	RXF1S;
	volatile	uint32_t	RXF1A;
	volatile	uint32_t	RESERVED5[8];
	volatile	uint32_t	TXBC;
	volatile	uint32_t	TXFQS;
	volatile	uint32_t	TXBRP;
	volatile	uint32_t	TXBAR;
	volatile	uint32_t	TXBCR;
	volatile	uint32_t	TXBTO;
	volatile	uint32_t	TXBCF;
	volatile	uint32_t	TXBTIE;
	volatile	uint32_t	TXBCIE;
	volatile	uint32_t	TXEFS;
	volatile	uint32_t	TXEFA;
	volatile	uint32_t	RESERVED6[5];
	volatile	uint32_t	CKDIV;
} FDCAN_TypeDef;

#if (defined(__cplusplus))
#define	FDCAN1_RAM_NS	reinterpret_cast<FDCAN_TypeDef *>(0x4000AC00u)
#define	FDCAN1_RAM_S	reinterpret_cast<FDCAN_TypeDef *>(0x5000AC00u)
#define	FDCAN1_NS		reinterpret_cast<FDCAN_TypeDef *>(0x4000A400u)
#define	FDCAN1_S		reinterpret_cast<FDCAN_TypeDef *>(0x5000A400u)

#else
#define	FDCAN1_RAM_NS	((FDCAN_TypeDef *)0x4000AC00u)
#define	FDCAN1_RAM_S	((FDCAN_TypeDef *)0x5000AC00u)
#define	FDCAN1_NS		((FDCAN_TypeDef *)0x4000A400u)
#define	FDCAN1_S		((FDCAN_TypeDef *)0x5000A400u)
#endif

// CREL Configuration

#define	FDCAN_CREL_DAY			(0xFFu<<0)
#define	FDCAN_CREL_DAY_0		(0x1u<<0)
#define	FDCAN_CREL_MON			(0xFFu<<8)
#define	FDCAN_CREL_MON_0		(0x1u<<8)
#define	FDCAN_CREL_YEAR			(0xFu<<16)
#define	FDCAN_CREL_YEAR_0		(0x1u<<16)
#define	FDCAN_CREL_SUBSTEP		(0xFu<<20)
#define	FDCAN_CREL_SUBSTEP_0	(0x1u<<20)
#define	FDCAN_CREL_STEP			(0xFu<<24)
#define	FDCAN_CREL_STEP_0		(0x1u<<24)
#define	FDCAN_CREL_REL			(0xFu<<28)
#define	FDCAN_CREL_REL_0		(0x1u<<28)

// ENDN Configuration

#define	FDCAN_ENDN_ETV			(0xFFFFFFFFu<<0)
#define	FDCAN_ENDN_ETV_0		(0x1u<<0)

// DBTP Configuration

#define	FDCAN_DBTP_TDC			(0x1u<<23)
#define	FDCAN_DBTP_DBRP			(0x1Fu<<16)
#define	FDCAN_DBTP_DBRP_0		(0x1u<<16)
#define	FDCAN_DBTP_DTSEG1		(0x1Fu<<8)
#define	FDCAN_DBTP_DTSEG1_0		(0x1u<<8)
#define	FDCAN_DBTP_DTSEG2		(0xFu<<4)
#define	FDCAN_DBTP_DTSEG2_0		(0x1u<<4)
#define	FDCAN_DBTP_DSJW			(0xFu<<0)
#define	FDCAN_DBTP_DSJW_0		(0x1u<<0)

// TEST Configuration

#define	FDCAN_TEST_RX			(0x1u<<7)
#define	FDCAN_TEST_TX			(0x3u<<5)
#define	FDCAN_TEST_TX_0			(0x1u<<5)
#define	FDCAN_TEST_LBCK			(0x1u<<4)

// RWD Configuration

#define	FDCAN_RWD_WDC			(0xFFu<<0)
#define	FDCAN_RWD_WDC_0			(0x1u<<0)
#define	FDCAN_RWD_WDV			(0xFFu<<8)
#define	FDCAN_RWD_WDV_0			(0x1u<<8)

// CCCR Configuration

#define	FDCAN_CCCR_NISO			(0x1u<<15)
#define	FDCAN_CCCR_TXP			(0x1u<<14)
#define	FDCAN_CCCR_EFBI			(0x1u<<13)
#define	FDCAN_CCCR_PXHD			(0x1u<<12)
#define	FDCAN_CCCR_BRSE			(0x1u<<9)
#define	FDCAN_CCCR_FDOE			(0x1u<<8)
#define	FDCAN_CCCR_TEST			(0x1u<<7)
#define	FDCAN_CCCR_DAR			(0x1u<<6)
#define	FDCAN_CCCR_MON			(0x1u<<5)
#define	FDCAN_CCCR_CSR			(0x1u<<4)
#define	FDCAN_CCCR_CSA			(0x1u<<3)
#define	FDCAN_CCCR_ASM			(0x1u<<2)
#define	FDCAN_CCCR_CCE			(0x1u<<1)
#define	FDCAN_CCCR_INIT			(0x1u<<0)

// NBTP Configuration

#define	FDCAN_NBTP_NTSEG2		(0x7Fu<<0)
#define	FDCAN_NBTP_NTSEG2_0		(0x1u<<0)
#define	FDCAN_NBTP_NTSEG1		(0xFFu<<8)
#define	FDCAN_NBTP_NTSEG1_0		(0x1u<<8)
#define	FDCAN_NBTP_NBRP			(0x1FFu<<16)
#define	FDCAN_NBTP_NBRP_0		(0x1u<<16)
#define	FDCAN_NBTP_NSJW			(0x7Fu<<25)
#define	FDCAN_NBTP_NSJW_0		(0x1u<<25)

// TSCC Configuration

#define	FDCAN_TSCC_TSS			(0x3u<<0)
#define	FDCAN_TSCC_TSS_0		(0x1u<<0)
#define	FDCAN_TSCC_TCP			(0xFu<<16)
#define	FDCAN_TSCC_TCP_0		(0x1u<<16)

// TSCV Configuration

#define	FDCAN_TSCV_TSC			(0xFFFFu<<0)
#define	FDCAN_TSCV_TSC_0		(0x1u<<0)

// TOCC Configuration

#define	FDCAN_TOCC_TOP			(0xFFFFu<<16)
#define	FDCAN_TOCC_TOP_0		(0x1u<<16)
#define	FDCAN_TOCC_TOS			(0x3u<<1)
#define	FDCAN_TOCC_TOS_0		(0x1u<<1)
#define	FDCAN_TOCC_ETOC			(0x1u<<0)

// TOCV Configuration

#define	FDCAN_TOCV_TOC			(0xFFFFu<<0)
#define	FDCAN_TOCV_TOC_0		(0x1u<<0)

// ECR Configuration

#define	FDCAN_ECR_TEC			(0xFFu<<0)
#define	FDCAN_ECR_TEC_0			(0x1u<<0)
#define	FDCAN_ECR_REC			(0x7Fu<<8)
#define	FDCAN_ECR_REC_0			(0x1u<<8)
#define	FDCAN_ECR_RP			(0x1u<<15)
#define	FDCAN_ECR_CEL			(0xFFu<<16)
#define	FDCAN_ECR_CEL_0			(0x1u<<16)

// PSR Configuration

#define	FDCAN_PSR_TDCV			(0x7Fu<<16)
#define	FDCAN_PSR_TDCV_0		(0x1u<<16)
#define	FDCAN_PSR_PXE			(0x1u<<14)
#define	FDCAN_PSR_REDL			(0x1u<<13)
#define	FDCAN_PSR_RBRS			(0x1u<<12)
#define	FDCAN_PSR_RESI			(0x1u<<11)
#define	FDCAN_PSR_DLEC			(0x7u<<8)
#define	FDCAN_PSR_DLEC_0		(0x1u<<8)
#define	FDCAN_PSR_BO			(0x1u<<7)
#define	FDCAN_PSR_EW			(0x1u<<6)
#define	FDCAN_PSR_EP			(0x1u<<5)
#define	FDCAN_PSR_ACT			(0x3u<<3)
#define	FDCAN_PSR_ACT_0			(0x1u<<3)
#define	FDCAN_PSR_LEC			(0x7u<<0)
#define	FDCAN_PSR_LEC_0			(0x1u<<0)

// TDCR Configuration

#define	FDCAN_TDCR_TDCO			(0x7Fu<<8)
#define	FDCAN_TDCR_TDCO_0		(0x1u<<8)
#define	FDCAN_TDCR_TDCF			(0x7Fu<<0)
#define	FDCAN_TDCR_TDCF_0		(0x1u<<0)

// IR Configuration

#define	FDCAN_IR_ARA			(0x1u<<23)
#define	FDCAN_IR_PED			(0x1u<<22)
#define	FDCAN_IR_PEA			(0x1u<<21)
#define	FDCAN_IR_WDI			(0x1u<<20)
#define	FDCAN_IR_BO				(0x1u<<19)
#define	FDCAN_IR_EW				(0x1u<<18)
#define	FDCAN_IR_EP				(0x1u<<17)
#define	FDCAN_IR_ELO			(0x1u<<16)
#define	FDCAN_IR_TOO			(0x1u<<15)
#define	FDCAN_IR_MRAF			(0x1u<<14)
#define	FDCAN_IR_TSW			(0x1u<<13)
#define	FDCAN_IR_TEFL			(0x1u<<12)
#define	FDCAN_IR_TEFF			(0x1u<<11)
#define	FDCAN_IR_TEFN			(0x1u<<10)
#define	FDCAN_IR_TFE			(0x1u<<9)
#define	FDCAN_IR_TCF			(0x1u<<8)
#define	FDCAN_IR_TC				(0x1u<<7)
#define	FDCAN_IR_HPM			(0x1u<<6)
#define	FDCAN_IR_RF1L			(0x1u<<5)
#define	FDCAN_IR_RF1F			(0x1u<<4)
#define	FDCAN_IR_RF1N			(0x1u<<3)
#define	FDCAN_IR_RF0L			(0x1u<<2)
#define	FDCAN_IR_RF0F			(0x1u<<1)
#define	FDCAN_IR_RF0N			(0x1u<<0)

// IE Configuration

#define	FDCAN_IE_ARAE			(0x1u<<23)
#define	FDCAN_IE_PEDE			(0x1u<<22)
#define	FDCAN_IE_PEAE			(0x1u<<21)
#define	FDCAN_IE_WDIE			(0x1u<<20)
#define	FDCAN_IE_BOE			(0x1u<<19)
#define	FDCAN_IE_EWE			(0x1u<<18)
#define	FDCAN_IE_EPE			(0x1u<<17)
#define	FDCAN_IE_ELOE			(0x1u<<16)
#define	FDCAN_IE_TOOE			(0x1u<<15)
#define	FDCAN_IE_MRAFE			(0x1u<<14)
#define	FDCAN_IE_TSWE			(0x1u<<13)
#define	FDCAN_IE_TEFLE			(0x1u<<12)
#define	FDCAN_IE_TEFFE			(0x1u<<11)
#define	FDCAN_IE_TEFNE			(0x1u<<10)
#define	FDCAN_IE_TEFE			(0x1u<<9)
#define	FDCAN_IE_TCFE			(0x1u<<8)
#define	FDCAN_IE_TCE			(0x1u<<7)
#define	FDCAN_IE_HPME			(0x1u<<6)
#define	FDCAN_IE_RF1LE			(0x1u<<5)
#define	FDCAN_IE_RF1FE			(0x1u<<4)
#define	FDCAN_IE_RF1NE			(0x1u<<3)
#define	FDCAN_IE_RF0LE			(0x1u<<2)
#define	FDCAN_IE_RF0FE			(0x1u<<1)
#define	FDCAN_IE_RF0NE			(0x1u<<0)

// ILS Configuration

#define	FDCAN_ILS_PERR			(0x1u<<6)
#define	FDCAN_ILS_BERR			(0x1u<<5)
#define	FDCAN_ILS_MISC			(0x1u<<4)
#define	FDCAN_ILS_TFERR			(0x1u<<3)
#define	FDCAN_ILS_SMSG			(0x1u<<2)
#define	FDCAN_ILS_RXFIFO1		(0x1u<<1)
#define	FDCAN_ILS_RXFIFO0		(0x1u<<0)

// ILE Configuration

#define	FDCAN_ILE_EINT1			(0x1u<<1)
#define	FDCAN_ILE_EINT0			(0x1u<<0)

// RXGFC Configuration

#define	FDCAN_RXGFC_LSE			(0xFu<<24)
#define	FDCAN_RXGFC_LSE_0		(0x1u<<24)
#define	FDCAN_RXGFC_LSS			(0x1Fu<<16)
#define	FDCAN_RXGFC_LSS_0		(0x1u<<16)
#define	FDCAN_RXGFC_F0OM		(0x1u<<9)
#define	FDCAN_RXGFC_F1OM		(0x1u<<8)
#define	FDCAN_RXGFC_ANFS		(0x3u<<4)
#define	FDCAN_RXGFC_ANFS_0		(0x1u<<4)
#define	FDCAN_RXGFC_ANFE		(0x3u<<2)
#define	FDCAN_RXGFC_ANFE_0		(0x1u<<2)
#define	FDCAN_RXGFC_RRFS		(0x1u<<1)
#define	FDCAN_RXGFC_RRFE		(0x1u<<0)

// XIDAM Configuration

#define	FDCAN_XIDAM_EIDM		(0x1FFFFFFFu<<0)
#define	FDCAN_XIDAM_EIDM_0		(0x1u<<0)

// HPMS Configuration

#define	FDCAN_HPMS_FLST			(0x1u<<15)
#define	FDCAN_HPMS_FIDX			(0x1Fu<<8)
#define	FDCAN_HPMS_FIDX_0		(0x1u<<8)
#define	FDCAN_HPMS_MSI			(0x3u<<6)
#define	FDCAN_HPMS_MSI_0		(0x1u<<6)
#define	FDCAN_HPMS_BIDX			(0x7u<<0)
#define	FDCAN_HPMS_BIDX_0		(0x1u<<0)

// RXF0S Configuration

#define	FDCAN_RXF0S_RF0L		(0x1u<<25)
#define	FDCAN_RXF0S_F0F			(0x1u<<24)
#define	FDCAN_RXF0S_F0PI		(0x3u<<16)
#define	FDCAN_RXF0S_F0PI_0		(0x1u<<16)
#define	FDCAN_RXF0S_F0GI		(0x3u<<8)
#define	FDCAN_RXF0S_F0GI_0		(0x1u<<8)
#define	FDCAN_RXF0S_F0FL		(0xFu<<0)
#define	FDCAN_RXF0S_F0FL_0		(0x1u<<0)

// RXF0A Configuration

#define	FDCAN_RXF0A_F0AI		(0x7u<<0)
#define	FDCAN_RXF0A_F0AI_0		(0x1u<<0)

// RXF1S Configuration

#define	FDCAN_RXF1S_RF1L		(0x1u<<25)
#define	FDCAN_RXF1S_F1F			(0x1u<<24)
#define	FDCAN_RXF1S_F1PI		(0x3u<<16)
#define	FDCAN_RXF1S_F1PI_0		(0x1u<<16)
#define	FDCAN_RXF1S_F1GI		(0x3u<<8)
#define	FDCAN_RXF1S_F1GI_0		(0x1u<<8)
#define	FDCAN_RXF1S_F1FL		(0xFu<<0)
#define	FDCAN_RXF1S_F1FL_0		(0x1u<<0)

// RXF1A Configuration

#define	FDCAN_RXF1A_F1AI		(0x7u<<0)
#define	FDCAN_RXF1A_F1AI_0		(0x1u<<0)

// TXBC Configuration

#define	FDCAN_TXBC_TFQM			(0x1u<<24)

// TXFQS Configuration

#define	FDCAN_TXFQS_TFQF		(0x1u<<21)
#define	FDCAN_TXFQS_TFQPI		(0x3u<<16)
#define	FDCAN_TXFQS_TFQPI_0		(0x1u<<16)
#define	FDCAN_TXFQS_TFGI		(0x3u<<8)
#define	FDCAN_TXFQS_TFGI_0		(0x1u<<8)
#define	FDCAN_TXFQS_TFFL		(0x7u<<0)
#define	FDCAN_TXFQS_TFFL_0		(0x1u<<0)

// TXBRP Configuration

#define	FDCAN_TXBRP_TRP			(0x7u<<0)
#define	FDCAN_TXBRP_TRP_0		(0x1u<<0)

// TXBAR Configuration

#define	FDCAN_TXBAR_AR			(0x7u<<0)
#define	FDCAN_TXBAR_AR_0		(0x1u<<0)

// TXBCR Configuration

#define	FDCAN_TXBCR_CR			(0x7u<<0)
#define	FDCAN_TXBCR_CR_0		(0x1u<<0)

// TXBTO Configuration

#define	FDCAN_TXBTO_TO			(0x7u<<0)
#define	FDCAN_TXBTO_TO_0		(0x1u<<0)

// TXBCF Configuration

#define	FDCAN_TXBCF_CF			(0x7u<<0)
#define	FDCAN_TXBCF_CF_0		(0x1u<<0)

// TXBTIE Configuration

#define	FDCAN_TXBTIE_TIE		(0x7u<<0)
#define	FDCAN_TXBTIE_TIE_0		(0x1u<<0)

// TXBCIE Configuration

#define	FDCAN_TXBCIE_CFIE		(0x7u<<0)
#define	FDCAN_TXBCIE_CFIE_0		(0x1u<<0)

// TXEFS Configuration

#define	FDCAN_TXEFS_TEFL		(0x1u<<25)
#define	FDCAN_TXEFS_EFF			(0x1u<<24)
#define	FDCAN_TXEFS_EFPI		(0x3u<<16)
#define	FDCAN_TXEFS_EFPI_0		(0x1u<<16)
#define	FDCAN_TXEFS_EFGI		(0x3u<<8)
#define	FDCAN_TXEFS_EFGI_0		(0x1u<<8)
#define	FDCAN_TXEFS_EFFL		(0x7u<<0)
#define	FDCAN_TXEFS_EFFL_0		(0x1u<<0)

// TXEFA Configuration

#define	FDCAN_TXEFA_EFAI		(0x3u<<0)
#define	FDCAN_TXEFA_EFAI_0		(0x1u<<0)

// CKDIV Configuration

#define	FDCAN_CKDIV_PDIV		(0xFu<<0)
#define	FDCAN_CKDIV_PDIV_0		(0x1u<<0)
