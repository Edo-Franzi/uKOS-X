/*
; stm32N657_fdcan.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_fdcan equates.
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
		union {
	volatile	uint32_t	CREL;
	volatile	uint32_t	CCU_CREL;
		};
		union {
	volatile	uint32_t	ENDN;
	volatile	uint32_t	CCU_CCFG;
		};
	volatile	uint32_t	CCU_CSTAT;
		union {
	volatile	uint32_t	DBTP;
	volatile	uint32_t	CCU_CWD;
		};
		union {
	volatile	uint32_t	TEST;
	volatile	uint32_t	CCU_IR;
		};
		union {
	volatile	uint32_t	RWD;
	volatile	uint32_t	CCU_IE;
		};
	volatile	uint32_t	CCCR;
	volatile	uint32_t	NBTP;
	volatile	uint32_t	TSCC;
	volatile	uint32_t	TSCV;
	volatile	uint32_t	TOCC;
	volatile	uint32_t	TOCV;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	ECR;
	volatile	uint32_t	PSR;
	volatile	uint32_t	TDCR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	IR;
	volatile	uint32_t	IE;
	volatile	uint32_t	ILS;
	volatile	uint32_t	ILE;
	volatile	uint32_t	RESERVED2[8];
	volatile	uint32_t	GFC;
	volatile	uint32_t	SIDFC;
	volatile	uint32_t	XIDFC;
	volatile	uint32_t	RESERVED3;
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
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	TXEFC;
	volatile	uint32_t	TXEFS;
	volatile	uint32_t	TXEFA;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	TTTMC;
	volatile	uint32_t	TTRMC;
	volatile	uint32_t	TTOCF;
	volatile	uint32_t	TTMLM;
	volatile	uint32_t	TURCF;
	volatile	uint32_t	TTOCN;
	volatile	uint32_t	TTGTP;
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
	volatile	uint32_t	RESERVED6[111];
	volatile	uint32_t	TTTS;
} FDCAN_TypeDef;

#if (defined(__cplusplus))
#define	FDCAN1_NS	reinterpret_cast<FDCAN_TypeDef *>(0x4000A000u)
#define	FDCAN1_S	reinterpret_cast<FDCAN_TypeDef *>(0x5000A000u)
#define	FDCAN2_NS	reinterpret_cast<FDCAN_TypeDef *>(0x4000A400u)
#define	FDCAN2_S	reinterpret_cast<FDCAN_TypeDef *>(0x5000A400u)
#define	FDCAN3_NS	reinterpret_cast<FDCAN_TypeDef *>(0x4000E800u)
#define	FDCAN3_S	reinterpret_cast<FDCAN_TypeDef *>(0x5000E800u)

#else
#define	FDCAN1_NS	((FDCAN_TypeDef *)0x4000A000u)
#define	FDCAN1_S	((FDCAN_TypeDef *)0x5000A000u)
#define	FDCAN2_NS	((FDCAN_TypeDef *)0x4000A400u)
#define	FDCAN2_S	((FDCAN_TypeDef *)0x5000A400u)
#define	FDCAN3_NS	((FDCAN_TypeDef *)0x4000E800u)
#define	FDCAN3_S	((FDCAN_TypeDef *)0x5000E800u)
#endif

// CREL Configuration

#define	FDCAN_CREL_REL					(0xFu<<28)
#define	FDCAN_CREL_REL_0				(0x1u<<28)
#define	FDCAN_CREL_STEP					(0xFu<<24)
#define	FDCAN_CREL_STEP_0				(0x1u<<24)
#define	FDCAN_CREL_SUBSTEP				(0xFu<<20)
#define	FDCAN_CREL_SUBSTEP_0			(0x1u<<20)
#define	FDCAN_CREL_YEAR					(0xFu<<16)
#define	FDCAN_CREL_YEAR_0				(0x1u<<16)
#define	FDCAN_CREL_MON					(0xFFu<<8)
#define	FDCAN_CREL_MON_0				(0x1u<<8)
#define	FDCAN_CREL_DAY					(0xFFu<<0)
#define	FDCAN_CREL_DAY_0				(0x1u<<0)

// CCU_CREL Configuration

#define	FDCAN_CCU_CREL_REL				(0xFu<<28)
#define	FDCAN_CCU_CREL_REL_0			(0x1u<<28)
#define	FDCAN_CCU_CREL_STEP				(0xFu<<24)
#define	FDCAN_CCU_CREL_STEP_0			(0x1u<<24)
#define	FDCAN_CCU_CREL_SUBSTEP			(0xFu<<20)
#define	FDCAN_CCU_CREL_SUBSTEP_0		(0x1u<<20)
#define	FDCAN_CCU_CREL_YEAR				(0xFu<<16)
#define	FDCAN_CCU_CREL_YEAR_0			(0x1u<<16)
#define	FDCAN_CCU_CREL_MON				(0xFFu<<8)
#define	FDCAN_CCU_CREL_MON_0			(0x1u<<8)
#define	FDCAN_CCU_CREL_DAY				(0xFFu<<0)
#define	FDCAN_CCU_CREL_DAY_0			(0x1u<<0)

// ENDN Configuration

#define	FDCAN_ENDN_ETV					(0xFFFFFFFFu<<0)
#define	FDCAN_ENDN_ETV_0				(0x1u<<0)

// CCU_CCFG Configuration

#define	FDCAN_CCU_CCFG_SWR				(0x1u<<31)
#define	FDCAN_CCU_CCFG_CDIV				(0xFu<<16)
#define	FDCAN_CCU_CCFG_CDIV_0			(0x1u<<16)
#define	FDCAN_CCU_CCFG_OCPM				(0xFFu<<8)
#define	FDCAN_CCU_CCFG_OCPM_0			(0x1u<<8)
#define	FDCAN_CCU_CCFG_CFL				(0x1u<<7)
#define	FDCAN_CCU_CCFG_BCC				(0x1u<<6)
#define	FDCAN_CCU_CCFG_TQBT				(0x1Fu<<0)
#define	FDCAN_CCU_CCFG_TQBT_0			(0x1u<<0)

#define	FDCAN_CCU_CCFG_CDIV_B_0X0		(0x0u<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0X1		(0x1u<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0X2		(0x2u<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0X3		(0x3u<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0X4		(0x4u<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0X5		(0x5u<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0X6		(0x6u<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0X7		(0x7u<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0X8		(0x8u<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0X9		(0x9u<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0XA		(0xAu<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0XB		(0xBu<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0XC		(0xCu<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0XD		(0xDu<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0XE		(0xEu<<16)
#define	FDCAN_CCU_CCFG_CDIV_B_0XF		(0xFu<<16)
#define	FDCAN_CCU_CCFG_CFL_B_0X0		(0x0u<<7)
#define	FDCAN_CCU_CCFG_CFL_B_0X1		(0x1u<<7)
#define	FDCAN_CCU_CCFG_BCC_B_0X0		(0x0u<<6)
#define	FDCAN_CCU_CCFG_BCC_B_0X1		(0x1u<<6)

// CCU_CSTAT Configuration

#define	FDCAN_CCU_CSTAT_CALS			(0x3u<<30)
#define	FDCAN_CCU_CSTAT_CALS_0			(0x1u<<30)
#define	FDCAN_CCU_CSTAT_TQC				(0x7FFu<<18)
#define	FDCAN_CCU_CSTAT_TQC_0			(0x1u<<18)
#define	FDCAN_CCU_CSTAT_OCPC			(0x3FFFFu<<0)
#define	FDCAN_CCU_CSTAT_OCPC_0			(0x1u<<0)

#define	FDCAN_CCU_CSTAT_CALS_B_0X0		(0x0u<<30)
#define	FDCAN_CCU_CSTAT_CALS_B_0X1		(0x1u<<30)
#define	FDCAN_CCU_CSTAT_CALS_B_0X2		(0x2u<<30)

// DBTP Configuration

#define	FDCAN_DBTP_TDC					(0x1u<<23)
#define	FDCAN_DBTP_DBRP					(0x1Fu<<16)
#define	FDCAN_DBTP_DBRP_0				(0x1u<<16)
#define	FDCAN_DBTP_DTSEG1				(0x1Fu<<8)
#define	FDCAN_DBTP_DTSEG1_0				(0x1u<<8)
#define	FDCAN_DBTP_DTSEG2				(0xFu<<4)
#define	FDCAN_DBTP_DTSEG2_0				(0x1u<<4)
#define	FDCAN_DBTP_DSJW					(0xFu<<0)
#define	FDCAN_DBTP_DSJW_0				(0x1u<<0)

#define	FDCAN_DBTP_TDC_B_0X0			(0x0u<<23)
#define	FDCAN_DBTP_TDC_B_0X1			(0x1u<<23)

// CCU_CWD Configuration

#define	FDCAN_CCU_CWD_WDV				(0xFFFFu<<16)
#define	FDCAN_CCU_CWD_WDV_0				(0x1u<<16)
#define	FDCAN_CCU_CWD_WDC				(0xFFFFu<<0)
#define	FDCAN_CCU_CWD_WDC_0				(0x1u<<0)

// TEST Configuration

#define	FDCAN_TEST_RX					(0x1u<<7)
#define	FDCAN_TEST_TX					(0x3u<<5)
#define	FDCAN_TEST_TX_0					(0x1u<<5)
#define	FDCAN_TEST_LBCK					(0x1u<<4)

#define	FDCAN_TEST_RX_B_0X0				(0x0u<<7)
#define	FDCAN_TEST_RX_B_0X1				(0x1u<<7)
#define	FDCAN_TEST_TX_B_0X0				(0x0u<<5)
#define	FDCAN_TEST_TX_B_0X1				(0x1u<<5)
#define	FDCAN_TEST_TX_B_0X2				(0x2u<<5)
#define	FDCAN_TEST_TX_B_0X3				(0x3u<<5)
#define	FDCAN_TEST_LBCK_B_0X0			(0x0u<<4)
#define	FDCAN_TEST_LBCK_B_0X1			(0x1u<<4)

// CCU_IR Configuration

#define	FDCAN_CCU_IR_CSC				(0x1u<<1)
#define	FDCAN_CCU_IR_CWE				(0x1u<<0)

#define	FDCAN_CCU_IR_CSC_B_0X0			(0x0u<<1)
#define	FDCAN_CCU_IR_CSC_B_0X1			(0x1u<<1)
#define	FDCAN_CCU_IR_CWE_B_0X0			(0x0u<<0)
#define	FDCAN_CCU_IR_CWE_B_0X1			(0x1u<<0)

// RWD Configuration

#define	FDCAN_RWD_WDV					(0xFFu<<8)
#define	FDCAN_RWD_WDV_0					(0x1u<<8)
#define	FDCAN_RWD_WDC					(0xFFu<<0)
#define	FDCAN_RWD_WDC_0					(0x1u<<0)

// CCU_IE Configuration

#define	FDCAN_CCU_IE_CSCE				(0x1u<<1)
#define	FDCAN_CCU_IE_CWEE				(0x1u<<0)

#define	FDCAN_CCU_IE_CSCE_B_0X0			(0x0u<<1)
#define	FDCAN_CCU_IE_CSCE_B_0X1			(0x1u<<1)
#define	FDCAN_CCU_IE_CWEE_B_0X0			(0x0u<<0)
#define	FDCAN_CCU_IE_CWEE_B_0X1			(0x1u<<0)

// CCCR Configuration

#define	FDCAN_CCCR_NISO					(0x1u<<15)
#define	FDCAN_CCCR_TXP					(0x1u<<14)
#define	FDCAN_CCCR_EFBI					(0x1u<<13)
#define	FDCAN_CCCR_PXHD					(0x1u<<12)
#define	FDCAN_CCCR_BRSE					(0x1u<<9)
#define	FDCAN_CCCR_FDOE					(0x1u<<8)
#define	FDCAN_CCCR_TEST					(0x1u<<7)
#define	FDCAN_CCCR_DAR					(0x1u<<6)
#define	FDCAN_CCCR_MON					(0x1u<<5)
#define	FDCAN_CCCR_CSR					(0x1u<<4)
#define	FDCAN_CCCR_CSA					(0x1u<<3)
#define	FDCAN_CCCR_ASM					(0x1u<<2)
#define	FDCAN_CCCR_CCE					(0x1u<<1)
#define	FDCAN_CCCR_INIT					(0x1u<<0)

#define	FDCAN_CCCR_NISO_B_0X0			(0x0u<<15)
#define	FDCAN_CCCR_NISO_B_0X1			(0x1u<<15)
#define	FDCAN_CCCR_TXP_B_0X0			(0x0u<<14)
#define	FDCAN_CCCR_TXP_B_0X1			(0x1u<<14)
#define	FDCAN_CCCR_EFBI_B_0X0			(0x0u<<13)
#define	FDCAN_CCCR_EFBI_B_0X1			(0x1u<<13)
#define	FDCAN_CCCR_PXHD_B_0X0			(0x0u<<12)
#define	FDCAN_CCCR_PXHD_B_0X1			(0x1u<<12)
#define	FDCAN_CCCR_BRSE_B_0X0			(0x0u<<9)
#define	FDCAN_CCCR_BRSE_B_0X1			(0x1u<<9)
#define	FDCAN_CCCR_FDOE_B_0X0			(0x0u<<8)
#define	FDCAN_CCCR_FDOE_B_0X1			(0x1u<<8)
#define	FDCAN_CCCR_TEST_B_0X0			(0x0u<<7)
#define	FDCAN_CCCR_TEST_B_0X1			(0x1u<<7)
#define	FDCAN_CCCR_DAR_B_0X0			(0x0u<<6)
#define	FDCAN_CCCR_DAR_B_0X1			(0x1u<<6)
#define	FDCAN_CCCR_MON_B_0X0			(0x0u<<5)
#define	FDCAN_CCCR_MON_B_0X1			(0x1u<<5)
#define	FDCAN_CCCR_CSR_B_0X0			(0x0u<<4)
#define	FDCAN_CCCR_CSR_B_0X1			(0x1u<<4)
#define	FDCAN_CCCR_CSA_B_0X0			(0x0u<<3)
#define	FDCAN_CCCR_CSA_B_0X1			(0x1u<<3)
#define	FDCAN_CCCR_ASM_B_0X0			(0x0u<<2)
#define	FDCAN_CCCR_ASM_B_0X1			(0x1u<<2)
#define	FDCAN_CCCR_CCE_B_0X0			(0x0u<<1)
#define	FDCAN_CCCR_CCE_B_0X1			(0x1u<<1)
#define	FDCAN_CCCR_INIT_B_0X0			(0x0u<<0)
#define	FDCAN_CCCR_INIT_B_0X1			(0x1u<<0)

// NBTP Configuration

#define	FDCAN_NBTP_NSJW					(0x7Fu<<25)
#define	FDCAN_NBTP_NSJW_0				(0x1u<<25)
#define	FDCAN_NBTP_NBRP					(0x1FFu<<16)
#define	FDCAN_NBTP_NBRP_0				(0x1u<<16)
#define	FDCAN_NBTP_NTSEG1				(0xFFu<<8)
#define	FDCAN_NBTP_NTSEG1_0				(0x1u<<8)
#define	FDCAN_NBTP_NTSEG2				(0x7Fu<<0)
#define	FDCAN_NBTP_NTSEG2_0				(0x1u<<0)

// TSCC Configuration

#define	FDCAN_TSCC_TCP					(0xFu<<16)
#define	FDCAN_TSCC_TCP_0				(0x1u<<16)
#define	FDCAN_TSCC_TSS					(0x3u<<0)
#define	FDCAN_TSCC_TSS_0				(0x1u<<0)

#define	FDCAN_TSCC_TSS_B_0X0			(0x0u<<0)
#define	FDCAN_TSCC_TSS_B_0X1			(0x1u<<0)
#define	FDCAN_TSCC_TSS_B_0X2			(0x2u<<0)
#define	FDCAN_TSCC_TSS_B_0X3			(0x3u<<0)

// TSCV Configuration

#define	FDCAN_TSCV_TSC					(0xFFFFu<<0)
#define	FDCAN_TSCV_TSC_0				(0x1u<<0)

// TOCC Configuration

#define	FDCAN_TOCC_TOP					(0xFFFFu<<16)
#define	FDCAN_TOCC_TOP_0				(0x1u<<16)
#define	FDCAN_TOCC_TOS					(0x3u<<1)
#define	FDCAN_TOCC_TOS_0				(0x1u<<1)
#define	FDCAN_TOCC_ETOC					(0x1u<<0)

#define	FDCAN_TOCC_TOS_B_0X0			(0x0u<<1)
#define	FDCAN_TOCC_TOS_B_0X1			(0x1u<<1)
#define	FDCAN_TOCC_TOS_B_0X2			(0x2u<<1)
#define	FDCAN_TOCC_TOS_B_0X3			(0x3u<<1)
#define	FDCAN_TOCC_ETOC_B_0X0			(0x0u<<0)
#define	FDCAN_TOCC_ETOC_B_0X1			(0x1u<<0)

// TOCV Configuration

#define	FDCAN_TOCV_TOC					(0xFFFFu<<0)
#define	FDCAN_TOCV_TOC_0				(0x1u<<0)

// ECR Configuration

#define	FDCAN_ECR_CEL					(0xFFu<<16)
#define	FDCAN_ECR_CEL_0					(0x1u<<16)
#define	FDCAN_ECR_RP					(0x1u<<15)
#define	FDCAN_ECR_REC					(0x7Fu<<8)
#define	FDCAN_ECR_REC_0					(0x1u<<8)
#define	FDCAN_ECR_TEC					(0xFFu<<0)
#define	FDCAN_ECR_TEC_0					(0x1u<<0)

#define	FDCAN_ECR_RP_B_0X0				(0x0u<<15)
#define	FDCAN_ECR_RP_B_0X1				(0x1u<<15)

// PSR Configuration

#define	FDCAN_PSR_TDCV					(0x7Fu<<16)
#define	FDCAN_PSR_TDCV_0				(0x1u<<16)
#define	FDCAN_PSR_PXE					(0x1u<<14)
#define	FDCAN_PSR_REDL					(0x1u<<13)
#define	FDCAN_PSR_RBRS					(0x1u<<12)
#define	FDCAN_PSR_RESI					(0x1u<<11)
#define	FDCAN_PSR_DLEC					(0x7u<<8)
#define	FDCAN_PSR_DLEC_0				(0x1u<<8)
#define	FDCAN_PSR_BO					(0x1u<<7)
#define	FDCAN_PSR_EW					(0x1u<<6)
#define	FDCAN_PSR_EP					(0x1u<<5)
#define	FDCAN_PSR_ACT					(0x3u<<3)
#define	FDCAN_PSR_ACT_0					(0x1u<<3)
#define	FDCAN_PSR_LEC					(0x7u<<0)
#define	FDCAN_PSR_LEC_0					(0x1u<<0)

#define	FDCAN_PSR_PXE_B_0X0				(0x0u<<14)
#define	FDCAN_PSR_PXE_B_0X1				(0x1u<<14)
#define	FDCAN_PSR_REDL_B_0X0			(0x0u<<13)
#define	FDCAN_PSR_REDL_B_0X1			(0x1u<<13)
#define	FDCAN_PSR_RBRS_B_0X0			(0x0u<<12)
#define	FDCAN_PSR_RBRS_B_0X1			(0x1u<<12)
#define	FDCAN_PSR_RESI_B_0X0			(0x0u<<11)
#define	FDCAN_PSR_RESI_B_0X1			(0x1u<<11)
#define	FDCAN_PSR_BO_B_0X0				(0x0u<<7)
#define	FDCAN_PSR_BO_B_0X1				(0x1u<<7)
#define	FDCAN_PSR_EW_B_0X0				(0x0u<<6)
#define	FDCAN_PSR_EW_B_0X1				(0x1u<<6)
#define	FDCAN_PSR_EP_B_0X0				(0x0u<<5)
#define	FDCAN_PSR_EP_B_0X1				(0x1u<<5)
#define	FDCAN_PSR_ACT_B_0X0				(0x0u<<3)
#define	FDCAN_PSR_ACT_B_0X1				(0x1u<<3)
#define	FDCAN_PSR_ACT_B_0X2				(0x2u<<3)
#define	FDCAN_PSR_ACT_B_0X3				(0x3u<<3)
#define	FDCAN_PSR_LEC_B_0X0				(0x0u<<0)
#define	FDCAN_PSR_LEC_B_0X1				(0x1u<<0)
#define	FDCAN_PSR_LEC_B_0X2				(0x2u<<0)
#define	FDCAN_PSR_LEC_B_0X3				(0x3u<<0)
#define	FDCAN_PSR_LEC_B_0X4				(0x4u<<0)
#define	FDCAN_PSR_LEC_B_0X5				(0x5u<<0)
#define	FDCAN_PSR_LEC_B_0X6				(0x6u<<0)
#define	FDCAN_PSR_LEC_B_0X7				(0x7u<<0)

// TDCR Configuration

#define	FDCAN_TDCR_TDCO					(0x7Fu<<8)
#define	FDCAN_TDCR_TDCO_0				(0x1u<<8)
#define	FDCAN_TDCR_TDCF					(0x7Fu<<0)
#define	FDCAN_TDCR_TDCF_0				(0x1u<<0)

// IR Configuration

#define	FDCAN_IR_ARA					(0x1u<<29)
#define	FDCAN_IR_PED					(0x1u<<28)
#define	FDCAN_IR_PEA					(0x1u<<27)
#define	FDCAN_IR_WDI					(0x1u<<26)
#define	FDCAN_IR_BO						(0x1u<<25)
#define	FDCAN_IR_EW						(0x1u<<24)
#define	FDCAN_IR_EP						(0x1u<<23)
#define	FDCAN_IR_ELO					(0x1u<<22)
#define	FDCAN_IR_DRX					(0x1u<<19)
#define	FDCAN_IR_TOO					(0x1u<<18)
#define	FDCAN_IR_MRAF					(0x1u<<17)
#define	FDCAN_IR_TSW					(0x1u<<16)
#define	FDCAN_IR_TEFL					(0x1u<<15)
#define	FDCAN_IR_TEFF					(0x1u<<14)
#define	FDCAN_IR_TEFW					(0x1u<<13)
#define	FDCAN_IR_TEFN					(0x1u<<12)
#define	FDCAN_IR_TFE					(0x1u<<11)
#define	FDCAN_IR_TCF					(0x1u<<10)
#define	FDCAN_IR_TC						(0x1u<<9)
#define	FDCAN_IR_HPM					(0x1u<<8)
#define	FDCAN_IR_RF1L					(0x1u<<7)
#define	FDCAN_IR_RF1F					(0x1u<<6)
#define	FDCAN_IR_RF1W					(0x1u<<5)
#define	FDCAN_IR_RF1N					(0x1u<<4)
#define	FDCAN_IR_RF0L					(0x1u<<3)
#define	FDCAN_IR_RF0F					(0x1u<<2)
#define	FDCAN_IR_RF0W					(0x1u<<1)
#define	FDCAN_IR_RF0N					(0x1u<<0)

#define	FDCAN_IR_ARA_B_0X0				(0x0u<<29)
#define	FDCAN_IR_ARA_B_0X1				(0x1u<<29)
#define	FDCAN_IR_PED_B_0X0				(0x0u<<28)
#define	FDCAN_IR_PED_B_0X1				(0x1u<<28)
#define	FDCAN_IR_PEA_B_0X0				(0x0u<<27)
#define	FDCAN_IR_PEA_B_0X1				(0x1u<<27)
#define	FDCAN_IR_WDI_B_0X0				(0x0u<<26)
#define	FDCAN_IR_WDI_B_0X1				(0x1u<<26)
#define	FDCAN_IR_BO_B_0X0				(0x0u<<25)
#define	FDCAN_IR_BO_B_0X1				(0x1u<<25)
#define	FDCAN_IR_EW_B_0X0				(0x0u<<24)
#define	FDCAN_IR_EW_B_0X1				(0x1u<<24)
#define	FDCAN_IR_EP_B_0X0				(0x0u<<23)
#define	FDCAN_IR_EP_B_0X1				(0x1u<<23)
#define	FDCAN_IR_ELO_B_0X0				(0x0u<<22)
#define	FDCAN_IR_ELO_B_0X1				(0x1u<<22)
#define	FDCAN_IR_DRX_B_0X0				(0x0u<<19)
#define	FDCAN_IR_DRX_B_0X1				(0x1u<<19)
#define	FDCAN_IR_TOO_B_0X0				(0x0u<<18)
#define	FDCAN_IR_TOO_B_0X1				(0x1u<<18)
#define	FDCAN_IR_MRAF_B_0X0				(0x0u<<17)
#define	FDCAN_IR_MRAF_B_0X1				(0x1u<<17)
#define	FDCAN_IR_TSW_B_0X0				(0x0u<<16)
#define	FDCAN_IR_TSW_B_0X1				(0x1u<<16)
#define	FDCAN_IR_TEFL_B_0X0				(0x0u<<15)
#define	FDCAN_IR_TEFL_B_0X1				(0x1u<<15)
#define	FDCAN_IR_TEFF_B_0X0				(0x0u<<14)
#define	FDCAN_IR_TEFF_B_0X1				(0x1u<<14)
#define	FDCAN_IR_TEFW_B_0X0				(0x0u<<13)
#define	FDCAN_IR_TEFW_B_0X1				(0x1u<<13)
#define	FDCAN_IR_TEFN_B_0X0				(0x0u<<12)
#define	FDCAN_IR_TEFN_B_0X1				(0x1u<<12)
#define	FDCAN_IR_TFE_B_0X0				(0x0u<<11)
#define	FDCAN_IR_TFE_B_0X1				(0x1u<<11)
#define	FDCAN_IR_TCF_B_0X0				(0x0u<<10)
#define	FDCAN_IR_TCF_B_0X1				(0x1u<<10)
#define	FDCAN_IR_TC_B_0X0				(0x0u<<9)
#define	FDCAN_IR_TC_B_0X1				(0x1u<<9)
#define	FDCAN_IR_HPM_B_0X0				(0x0u<<8)
#define	FDCAN_IR_HPM_B_0X1				(0x1u<<8)
#define	FDCAN_IR_RF1L_B_0X0				(0x0u<<7)
#define	FDCAN_IR_RF1L_B_0X1				(0x1u<<7)
#define	FDCAN_IR_RF1F_B_0X0				(0x0u<<6)
#define	FDCAN_IR_RF1F_B_0X1				(0x1u<<6)
#define	FDCAN_IR_RF1W_B_0X0				(0x0u<<5)
#define	FDCAN_IR_RF1W_B_0X1				(0x1u<<5)
#define	FDCAN_IR_RF1N_B_0X0				(0x0u<<4)
#define	FDCAN_IR_RF1N_B_0X1				(0x1u<<4)
#define	FDCAN_IR_RF0L_B_0X0				(0x0u<<3)
#define	FDCAN_IR_RF0L_B_0X1				(0x1u<<3)
#define	FDCAN_IR_RF0F_B_0X0				(0x0u<<2)
#define	FDCAN_IR_RF0F_B_0X1				(0x1u<<2)
#define	FDCAN_IR_RF0W_B_0X0				(0x0u<<1)
#define	FDCAN_IR_RF0W_B_0X1				(0x1u<<1)
#define	FDCAN_IR_RF0N_B_0X0				(0x0u<<0)
#define	FDCAN_IR_RF0N_B_0X1				(0x1u<<0)

// IE Configuration

#define	FDCAN_IE_ARAE					(0x1u<<29)
#define	FDCAN_IE_PEDE					(0x1u<<28)
#define	FDCAN_IE_PEAE					(0x1u<<27)
#define	FDCAN_IE_WDIE					(0x1u<<26)
#define	FDCAN_IE_BOE					(0x1u<<25)
#define	FDCAN_IE_EWE					(0x1u<<24)
#define	FDCAN_IE_EPE					(0x1u<<23)
#define	FDCAN_IE_ELOE					(0x1u<<22)
#define	FDCAN_IE_DRXE					(0x1u<<19)
#define	FDCAN_IE_TOOE					(0x1u<<18)
#define	FDCAN_IE_MRAFE					(0x1u<<17)
#define	FDCAN_IE_TSWE					(0x1u<<16)
#define	FDCAN_IE_TEFLE					(0x1u<<15)
#define	FDCAN_IE_TEFFE					(0x1u<<14)
#define	FDCAN_IE_TEFWE					(0x1u<<13)
#define	FDCAN_IE_TEFNE					(0x1u<<12)
#define	FDCAN_IE_TFEE					(0x1u<<11)
#define	FDCAN_IE_TCFE					(0x1u<<10)
#define	FDCAN_IE_TCE					(0x1u<<9)
#define	FDCAN_IE_HPME					(0x1u<<8)
#define	FDCAN_IE_RF1LE					(0x1u<<7)
#define	FDCAN_IE_RF1FE					(0x1u<<6)
#define	FDCAN_IE_RF1WE					(0x1u<<5)
#define	FDCAN_IE_RF1NE					(0x1u<<4)
#define	FDCAN_IE_RF0LE					(0x1u<<3)
#define	FDCAN_IE_RF0FE					(0x1u<<2)
#define	FDCAN_IE_RF0WE					(0x1u<<1)
#define	FDCAN_IE_RF0NE					(0x1u<<0)

#define	FDCAN_IE_WDIE_B_0X0				(0x0u<<26)
#define	FDCAN_IE_WDIE_B_0X1				(0x1u<<26)
#define	FDCAN_IE_BOE_B_0X0				(0x0u<<25)
#define	FDCAN_IE_BOE_B_0X1				(0x1u<<25)
#define	FDCAN_IE_EWE_B_0X0				(0x0u<<24)
#define	FDCAN_IE_EWE_B_0X1				(0x1u<<24)
#define	FDCAN_IE_EPE_B_0X0				(0x0u<<23)
#define	FDCAN_IE_EPE_B_0X1				(0x1u<<23)
#define	FDCAN_IE_ELOE_B_0X0				(0x0u<<22)
#define	FDCAN_IE_ELOE_B_0X1				(0x1u<<22)
#define	FDCAN_IE_DRXE_B_0X0				(0x0u<<19)
#define	FDCAN_IE_DRXE_B_0X1				(0x1u<<19)
#define	FDCAN_IE_TOOE_B_0X0				(0x0u<<18)
#define	FDCAN_IE_TOOE_B_0X1				(0x1u<<18)
#define	FDCAN_IE_MRAFE_B_0X0			(0x0u<<17)
#define	FDCAN_IE_MRAFE_B_0X1			(0x1u<<17)
#define	FDCAN_IE_TSWE_B_0X0				(0x0u<<16)
#define	FDCAN_IE_TSWE_B_0X1				(0x1u<<16)
#define	FDCAN_IE_TEFLE_B_0X0			(0x0u<<15)
#define	FDCAN_IE_TEFLE_B_0X1			(0x1u<<15)
#define	FDCAN_IE_TEFFE_B_0X0			(0x0u<<14)
#define	FDCAN_IE_TEFFE_B_0X1			(0x1u<<14)
#define	FDCAN_IE_TEFWE_B_0X0			(0x0u<<13)
#define	FDCAN_IE_TEFWE_B_0X1			(0x1u<<13)
#define	FDCAN_IE_TEFNE_B_0X0			(0x0u<<12)
#define	FDCAN_IE_TEFNE_B_0X1			(0x1u<<12)
#define	FDCAN_IE_TFEE_B_0X0				(0x0u<<11)
#define	FDCAN_IE_TFEE_B_0X1				(0x1u<<11)
#define	FDCAN_IE_TCFE_B_0X0				(0x0u<<10)
#define	FDCAN_IE_TCFE_B_0X1				(0x1u<<10)
#define	FDCAN_IE_TCE_B_0X0				(0x0u<<9)
#define	FDCAN_IE_TCE_B_0X1				(0x1u<<9)
#define	FDCAN_IE_HPME_B_0X0				(0x0u<<8)
#define	FDCAN_IE_HPME_B_0X1				(0x1u<<8)
#define	FDCAN_IE_RF1LE_B_0X0			(0x0u<<7)
#define	FDCAN_IE_RF1LE_B_0X1			(0x1u<<7)
#define	FDCAN_IE_RF1FE_B_0X0			(0x0u<<6)
#define	FDCAN_IE_RF1FE_B_0X1			(0x1u<<6)
#define	FDCAN_IE_RF1WE_B_0X0			(0x0u<<5)
#define	FDCAN_IE_RF1WE_B_0X1			(0x1u<<5)
#define	FDCAN_IE_RF1NE_B_0X0			(0x0u<<4)
#define	FDCAN_IE_RF1NE_B_0X1			(0x1u<<4)
#define	FDCAN_IE_RF0LE_B_0X0			(0x0u<<3)
#define	FDCAN_IE_RF0LE_B_0X1			(0x1u<<3)
#define	FDCAN_IE_RF0FE_B_0X0			(0x0u<<2)
#define	FDCAN_IE_RF0FE_B_0X1			(0x1u<<2)
#define	FDCAN_IE_RF0WE_B_0X0			(0x0u<<1)
#define	FDCAN_IE_RF0WE_B_0X1			(0x1u<<1)
#define	FDCAN_IE_RF0NE_B_0X0			(0x0u<<0)
#define	FDCAN_IE_RF0NE_B_0X1			(0x1u<<0)

// ILS Configuration

#define	FDCAN_ILS_ARAL					(0x1u<<29)
#define	FDCAN_ILS_PEDL					(0x1u<<28)
#define	FDCAN_ILS_PEAL					(0x1u<<27)
#define	FDCAN_ILS_WDIL					(0x1u<<26)
#define	FDCAN_ILS_BOL					(0x1u<<25)
#define	FDCAN_ILS_EWL					(0x1u<<24)
#define	FDCAN_ILS_EPL					(0x1u<<23)
#define	FDCAN_ILS_ELOL					(0x1u<<22)
#define	FDCAN_ILS_DRXL					(0x1u<<19)
#define	FDCAN_ILS_TOOL					(0x1u<<18)
#define	FDCAN_ILS_MRAFL					(0x1u<<17)
#define	FDCAN_ILS_TSWL					(0x1u<<16)
#define	FDCAN_ILS_TEFLL					(0x1u<<15)
#define	FDCAN_ILS_TEFFL					(0x1u<<14)
#define	FDCAN_ILS_TEFWL					(0x1u<<13)
#define	FDCAN_ILS_TEFNL					(0x1u<<12)
#define	FDCAN_ILS_TFEL					(0x1u<<11)
#define	FDCAN_ILS_TCFL					(0x1u<<10)
#define	FDCAN_ILS_TCL					(0x1u<<9)
#define	FDCAN_ILS_HPML					(0x1u<<8)
#define	FDCAN_ILS_RF1LL					(0x1u<<7)
#define	FDCAN_ILS_RF1FL					(0x1u<<6)
#define	FDCAN_ILS_RF1WL					(0x1u<<5)
#define	FDCAN_ILS_RF1NL					(0x1u<<4)
#define	FDCAN_ILS_RF0LL					(0x1u<<3)
#define	FDCAN_ILS_RF0FL					(0x1u<<2)
#define	FDCAN_ILS_RF0WL					(0x1u<<1)
#define	FDCAN_ILS_RF0NL					(0x1u<<0)

// ILE Configuration

#define	FDCAN_ILE_EINT1					(0x1u<<1)
#define	FDCAN_ILE_EINT0					(0x1u<<0)

#define	FDCAN_ILE_EINT1_B_0X0			(0x0u<<1)
#define	FDCAN_ILE_EINT1_B_0X1			(0x1u<<1)
#define	FDCAN_ILE_EINT0_B_0X0			(0x0u<<0)
#define	FDCAN_ILE_EINT0_B_0X1			(0x1u<<0)

// GFC Configuration

#define	FDCAN_GFC_ANFS					(0x3u<<4)
#define	FDCAN_GFC_ANFS_0				(0x1u<<4)
#define	FDCAN_GFC_ANFE					(0x3u<<2)
#define	FDCAN_GFC_ANFE_0				(0x1u<<2)
#define	FDCAN_GFC_RRFS					(0x1u<<1)
#define	FDCAN_GFC_RRFE					(0x1u<<0)

#define	FDCAN_GFC_ANFS_B_0X0			(0x0u<<4)
#define	FDCAN_GFC_ANFS_B_0X1			(0x1u<<4)
#define	FDCAN_GFC_ANFS_B_0X2			(0x2u<<4)
#define	FDCAN_GFC_ANFS_B_0X3			(0x3u<<4)
#define	FDCAN_GFC_ANFE_B_0X0			(0x0u<<2)
#define	FDCAN_GFC_ANFE_B_0X1			(0x1u<<2)
#define	FDCAN_GFC_ANFE_B_0X2			(0x2u<<2)
#define	FDCAN_GFC_ANFE_B_0X3			(0x3u<<2)
#define	FDCAN_GFC_RRFS_B_0X0			(0x0u<<1)
#define	FDCAN_GFC_RRFS_B_0X1			(0x1u<<1)
#define	FDCAN_GFC_RRFE_B_0X0			(0x0u<<0)
#define	FDCAN_GFC_RRFE_B_0X1			(0x1u<<0)

// SIDFC Configuration

#define	FDCAN_SIDFC_LSS					(0xFFu<<16)
#define	FDCAN_SIDFC_LSS_0				(0x1u<<16)
#define	FDCAN_SIDFC_FLSSA				(0x3FFFu<<2)
#define	FDCAN_SIDFC_FLSSA_0				(0x1u<<2)

#define	FDCAN_SIDFC_LSS_B_0X0			(0x0u<<16)

// XIDFC Configuration

#define	FDCAN_XIDFC_LSE					(0xFFu<<16)
#define	FDCAN_XIDFC_LSE_0				(0x1u<<16)
#define	FDCAN_XIDFC_FLESA				(0x3FFFu<<2)
#define	FDCAN_XIDFC_FLESA_0				(0x1u<<2)

#define	FDCAN_XIDFC_LSE_B_0X0			(0x0u<<16)

// XIDAM Configuration

#define	FDCAN_XIDAM_EIDM				(0x1FFFFFFFu<<0)
#define	FDCAN_XIDAM_EIDM_0				(0x1u<<0)

// HPMS Configuration

#define	FDCAN_HPMS_FLST					(0x1u<<15)
#define	FDCAN_HPMS_FIDX					(0x7Fu<<8)
#define	FDCAN_HPMS_FIDX_0				(0x1u<<8)
#define	FDCAN_HPMS_MSI					(0x3u<<6)
#define	FDCAN_HPMS_MSI_0				(0x1u<<6)
#define	FDCAN_HPMS_BIDX					(0x3Fu<<0)
#define	FDCAN_HPMS_BIDX_0				(0x1u<<0)

#define	FDCAN_HPMS_FLST_B_0X0			(0x0u<<15)
#define	FDCAN_HPMS_FLST_B_0X1			(0x1u<<15)
#define	FDCAN_HPMS_MSI_B_0X0			(0x0u<<6)
#define	FDCAN_HPMS_MSI_B_0X1			(0x1u<<6)
#define	FDCAN_HPMS_MSI_B_0X2			(0x2u<<6)
#define	FDCAN_HPMS_MSI_B_0X3			(0x3u<<6)

// NDAT1 Configuration

#define	FDCAN_NDAT1_ND31				(0x1u<<31)
#define	FDCAN_NDAT1_ND30				(0x1u<<30)
#define	FDCAN_NDAT1_ND29				(0x1u<<29)
#define	FDCAN_NDAT1_ND28				(0x1u<<28)
#define	FDCAN_NDAT1_ND27				(0x1u<<27)
#define	FDCAN_NDAT1_ND26				(0x1u<<26)
#define	FDCAN_NDAT1_ND25				(0x1u<<25)
#define	FDCAN_NDAT1_ND24				(0x1u<<24)
#define	FDCAN_NDAT1_ND23				(0x1u<<23)
#define	FDCAN_NDAT1_ND22				(0x1u<<22)
#define	FDCAN_NDAT1_ND21				(0x1u<<21)
#define	FDCAN_NDAT1_ND20				(0x1u<<20)
#define	FDCAN_NDAT1_ND19				(0x1u<<19)
#define	FDCAN_NDAT1_ND18				(0x1u<<18)
#define	FDCAN_NDAT1_ND17				(0x1u<<17)
#define	FDCAN_NDAT1_ND16				(0x1u<<16)
#define	FDCAN_NDAT1_ND15				(0x1u<<15)
#define	FDCAN_NDAT1_ND14				(0x1u<<14)
#define	FDCAN_NDAT1_ND13				(0x1u<<13)
#define	FDCAN_NDAT1_ND12				(0x1u<<12)
#define	FDCAN_NDAT1_ND11				(0x1u<<11)
#define	FDCAN_NDAT1_ND10				(0x1u<<10)
#define	FDCAN_NDAT1_ND9					(0x1u<<9)
#define	FDCAN_NDAT1_ND8					(0x1u<<8)
#define	FDCAN_NDAT1_ND7					(0x1u<<7)
#define	FDCAN_NDAT1_ND6					(0x1u<<6)
#define	FDCAN_NDAT1_ND5					(0x1u<<5)
#define	FDCAN_NDAT1_ND4					(0x1u<<4)
#define	FDCAN_NDAT1_ND3					(0x1u<<3)
#define	FDCAN_NDAT1_ND2					(0x1u<<2)
#define	FDCAN_NDAT1_ND1					(0x1u<<1)
#define	FDCAN_NDAT1_ND0					(0x1u<<0)

#define	FDCAN_NDAT1_ND31_B_0X0			(0x0u<<31)
#define	FDCAN_NDAT1_ND31_B_0X1			(0x1u<<31)
#define	FDCAN_NDAT1_ND30_B_0X0			(0x0u<<30)
#define	FDCAN_NDAT1_ND30_B_0X1			(0x1u<<30)
#define	FDCAN_NDAT1_ND29_B_0X0			(0x0u<<29)
#define	FDCAN_NDAT1_ND29_B_0X1			(0x1u<<29)
#define	FDCAN_NDAT1_ND28_B_0X0			(0x0u<<28)
#define	FDCAN_NDAT1_ND28_B_0X1			(0x1u<<28)
#define	FDCAN_NDAT1_ND27_B_0X0			(0x0u<<27)
#define	FDCAN_NDAT1_ND27_B_0X1			(0x1u<<27)
#define	FDCAN_NDAT1_ND26_B_0X0			(0x0u<<26)
#define	FDCAN_NDAT1_ND26_B_0X1			(0x1u<<26)
#define	FDCAN_NDAT1_ND25_B_0X0			(0x0u<<25)
#define	FDCAN_NDAT1_ND25_B_0X1			(0x1u<<25)
#define	FDCAN_NDAT1_ND24_B_0X0			(0x0u<<24)
#define	FDCAN_NDAT1_ND24_B_0X1			(0x1u<<24)
#define	FDCAN_NDAT1_ND23_B_0X0			(0x0u<<23)
#define	FDCAN_NDAT1_ND23_B_0X1			(0x1u<<23)
#define	FDCAN_NDAT1_ND22_B_0X0			(0x0u<<22)
#define	FDCAN_NDAT1_ND22_B_0X1			(0x1u<<22)
#define	FDCAN_NDAT1_ND21_B_0X0			(0x0u<<21)
#define	FDCAN_NDAT1_ND21_B_0X1			(0x1u<<21)
#define	FDCAN_NDAT1_ND20_B_0X0			(0x0u<<20)
#define	FDCAN_NDAT1_ND20_B_0X1			(0x1u<<20)
#define	FDCAN_NDAT1_ND19_B_0X0			(0x0u<<19)
#define	FDCAN_NDAT1_ND19_B_0X1			(0x1u<<19)
#define	FDCAN_NDAT1_ND18_B_0X0			(0x0u<<18)
#define	FDCAN_NDAT1_ND18_B_0X1			(0x1u<<18)
#define	FDCAN_NDAT1_ND17_B_0X0			(0x0u<<17)
#define	FDCAN_NDAT1_ND17_B_0X1			(0x1u<<17)
#define	FDCAN_NDAT1_ND16_B_0X0			(0x0u<<16)
#define	FDCAN_NDAT1_ND16_B_0X1			(0x1u<<16)
#define	FDCAN_NDAT1_ND15_B_0X0			(0x0u<<15)
#define	FDCAN_NDAT1_ND15_B_0X1			(0x1u<<15)
#define	FDCAN_NDAT1_ND14_B_0X0			(0x0u<<14)
#define	FDCAN_NDAT1_ND14_B_0X1			(0x1u<<14)
#define	FDCAN_NDAT1_ND13_B_0X0			(0x0u<<13)
#define	FDCAN_NDAT1_ND13_B_0X1			(0x1u<<13)
#define	FDCAN_NDAT1_ND12_B_0X0			(0x0u<<12)
#define	FDCAN_NDAT1_ND12_B_0X1			(0x1u<<12)
#define	FDCAN_NDAT1_ND11_B_0X0			(0x0u<<11)
#define	FDCAN_NDAT1_ND11_B_0X1			(0x1u<<11)
#define	FDCAN_NDAT1_ND10_B_0X0			(0x0u<<10)
#define	FDCAN_NDAT1_ND10_B_0X1			(0x1u<<10)
#define	FDCAN_NDAT1_ND9_B_0X0			(0x0u<<9)
#define	FDCAN_NDAT1_ND9_B_0X1			(0x1u<<9)
#define	FDCAN_NDAT1_ND8_B_0X0			(0x0u<<8)
#define	FDCAN_NDAT1_ND8_B_0X1			(0x1u<<8)
#define	FDCAN_NDAT1_ND7_B_0X0			(0x0u<<7)
#define	FDCAN_NDAT1_ND7_B_0X1			(0x1u<<7)
#define	FDCAN_NDAT1_ND6_B_0X0			(0x0u<<6)
#define	FDCAN_NDAT1_ND6_B_0X1			(0x1u<<6)
#define	FDCAN_NDAT1_ND5_B_0X0			(0x0u<<5)
#define	FDCAN_NDAT1_ND5_B_0X1			(0x1u<<5)
#define	FDCAN_NDAT1_ND4_B_0X0			(0x0u<<4)
#define	FDCAN_NDAT1_ND4_B_0X1			(0x1u<<4)
#define	FDCAN_NDAT1_ND3_B_0X0			(0x0u<<3)
#define	FDCAN_NDAT1_ND3_B_0X1			(0x1u<<3)
#define	FDCAN_NDAT1_ND2_B_0X0			(0x0u<<2)
#define	FDCAN_NDAT1_ND2_B_0X1			(0x1u<<2)
#define	FDCAN_NDAT1_ND1_B_0X0			(0x0u<<1)
#define	FDCAN_NDAT1_ND1_B_0X1			(0x1u<<1)
#define	FDCAN_NDAT1_ND0_B_0X0			(0x0u<<0)
#define	FDCAN_NDAT1_ND0_B_0X1			(0x1u<<0)

// NDAT2 Configuration

#define	FDCAN_NDAT2_ND63				(0x1u<<31)
#define	FDCAN_NDAT2_ND62				(0x1u<<30)
#define	FDCAN_NDAT2_ND61				(0x1u<<29)
#define	FDCAN_NDAT2_ND60				(0x1u<<28)
#define	FDCAN_NDAT2_ND59				(0x1u<<27)
#define	FDCAN_NDAT2_ND58				(0x1u<<26)
#define	FDCAN_NDAT2_ND57				(0x1u<<25)
#define	FDCAN_NDAT2_ND56				(0x1u<<24)
#define	FDCAN_NDAT2_ND55				(0x1u<<23)
#define	FDCAN_NDAT2_ND54				(0x1u<<22)
#define	FDCAN_NDAT2_ND53				(0x1u<<21)
#define	FDCAN_NDAT2_ND52				(0x1u<<20)
#define	FDCAN_NDAT2_ND51				(0x1u<<19)
#define	FDCAN_NDAT2_ND50				(0x1u<<18)
#define	FDCAN_NDAT2_ND49				(0x1u<<17)
#define	FDCAN_NDAT2_ND48				(0x1u<<16)
#define	FDCAN_NDAT2_ND47				(0x1u<<15)
#define	FDCAN_NDAT2_ND46				(0x1u<<14)
#define	FDCAN_NDAT2_ND45				(0x1u<<13)
#define	FDCAN_NDAT2_ND44				(0x1u<<12)
#define	FDCAN_NDAT2_ND43				(0x1u<<11)
#define	FDCAN_NDAT2_ND42				(0x1u<<10)
#define	FDCAN_NDAT2_ND41				(0x1u<<9)
#define	FDCAN_NDAT2_ND40				(0x1u<<8)
#define	FDCAN_NDAT2_ND39				(0x1u<<7)
#define	FDCAN_NDAT2_ND38				(0x1u<<6)
#define	FDCAN_NDAT2_ND37				(0x1u<<5)
#define	FDCAN_NDAT2_ND36				(0x1u<<4)
#define	FDCAN_NDAT2_ND35				(0x1u<<3)
#define	FDCAN_NDAT2_ND34				(0x1u<<2)
#define	FDCAN_NDAT2_ND33				(0x1u<<1)
#define	FDCAN_NDAT2_ND32				(0x1u<<0)

#define	FDCAN_NDAT2_ND63_B_0X0			(0x0u<<31)
#define	FDCAN_NDAT2_ND63_B_0X1			(0x1u<<31)
#define	FDCAN_NDAT2_ND62_B_0X0			(0x0u<<30)
#define	FDCAN_NDAT2_ND62_B_0X1			(0x1u<<30)
#define	FDCAN_NDAT2_ND61_B_0X0			(0x0u<<29)
#define	FDCAN_NDAT2_ND61_B_0X1			(0x1u<<29)
#define	FDCAN_NDAT2_ND60_B_0X0			(0x0u<<28)
#define	FDCAN_NDAT2_ND60_B_0X1			(0x1u<<28)
#define	FDCAN_NDAT2_ND59_B_0X0			(0x0u<<27)
#define	FDCAN_NDAT2_ND59_B_0X1			(0x1u<<27)
#define	FDCAN_NDAT2_ND58_B_0X0			(0x0u<<26)
#define	FDCAN_NDAT2_ND58_B_0X1			(0x1u<<26)
#define	FDCAN_NDAT2_ND57_B_0X0			(0x0u<<25)
#define	FDCAN_NDAT2_ND57_B_0X1			(0x1u<<25)
#define	FDCAN_NDAT2_ND56_B_0X0			(0x0u<<24)
#define	FDCAN_NDAT2_ND56_B_0X1			(0x1u<<24)
#define	FDCAN_NDAT2_ND55_B_0X0			(0x0u<<23)
#define	FDCAN_NDAT2_ND55_B_0X1			(0x1u<<23)
#define	FDCAN_NDAT2_ND54_B_0X0			(0x0u<<22)
#define	FDCAN_NDAT2_ND54_B_0X1			(0x1u<<22)
#define	FDCAN_NDAT2_ND53_B_0X0			(0x0u<<21)
#define	FDCAN_NDAT2_ND53_B_0X1			(0x1u<<21)
#define	FDCAN_NDAT2_ND52_B_0X0			(0x0u<<20)
#define	FDCAN_NDAT2_ND52_B_0X1			(0x1u<<20)
#define	FDCAN_NDAT2_ND51_B_0X0			(0x0u<<19)
#define	FDCAN_NDAT2_ND51_B_0X1			(0x1u<<19)
#define	FDCAN_NDAT2_ND50_B_0X0			(0x0u<<18)
#define	FDCAN_NDAT2_ND50_B_0X1			(0x1u<<18)
#define	FDCAN_NDAT2_ND49_B_0X0			(0x0u<<17)
#define	FDCAN_NDAT2_ND49_B_0X1			(0x1u<<17)
#define	FDCAN_NDAT2_ND48_B_0X0			(0x0u<<16)
#define	FDCAN_NDAT2_ND48_B_0X1			(0x1u<<16)
#define	FDCAN_NDAT2_ND47_B_0X0			(0x0u<<15)
#define	FDCAN_NDAT2_ND47_B_0X1			(0x1u<<15)
#define	FDCAN_NDAT2_ND46_B_0X0			(0x0u<<14)
#define	FDCAN_NDAT2_ND46_B_0X1			(0x1u<<14)
#define	FDCAN_NDAT2_ND45_B_0X0			(0x0u<<13)
#define	FDCAN_NDAT2_ND45_B_0X1			(0x1u<<13)
#define	FDCAN_NDAT2_ND44_B_0X0			(0x0u<<12)
#define	FDCAN_NDAT2_ND44_B_0X1			(0x1u<<12)
#define	FDCAN_NDAT2_ND43_B_0X0			(0x0u<<11)
#define	FDCAN_NDAT2_ND43_B_0X1			(0x1u<<11)
#define	FDCAN_NDAT2_ND42_B_0X0			(0x0u<<10)
#define	FDCAN_NDAT2_ND42_B_0X1			(0x1u<<10)
#define	FDCAN_NDAT2_ND41_B_0X0			(0x0u<<9)
#define	FDCAN_NDAT2_ND41_B_0X1			(0x1u<<9)
#define	FDCAN_NDAT2_ND40_B_0X0			(0x0u<<8)
#define	FDCAN_NDAT2_ND40_B_0X1			(0x1u<<8)
#define	FDCAN_NDAT2_ND39_B_0X0			(0x0u<<7)
#define	FDCAN_NDAT2_ND39_B_0X1			(0x1u<<7)
#define	FDCAN_NDAT2_ND38_B_0X0			(0x0u<<6)
#define	FDCAN_NDAT2_ND38_B_0X1			(0x1u<<6)
#define	FDCAN_NDAT2_ND37_B_0X0			(0x0u<<5)
#define	FDCAN_NDAT2_ND37_B_0X1			(0x1u<<5)
#define	FDCAN_NDAT2_ND36_B_0X0			(0x0u<<4)
#define	FDCAN_NDAT2_ND36_B_0X1			(0x1u<<4)
#define	FDCAN_NDAT2_ND35_B_0X0			(0x0u<<3)
#define	FDCAN_NDAT2_ND35_B_0X1			(0x1u<<3)
#define	FDCAN_NDAT2_ND34_B_0X0			(0x0u<<2)
#define	FDCAN_NDAT2_ND34_B_0X1			(0x1u<<2)
#define	FDCAN_NDAT2_ND33_B_0X0			(0x0u<<1)
#define	FDCAN_NDAT2_ND33_B_0X1			(0x1u<<1)
#define	FDCAN_NDAT2_ND32_B_0X0			(0x0u<<0)
#define	FDCAN_NDAT2_ND32_B_0X1			(0x1u<<0)

// RXF0C Configuration

#define	FDCAN_RXF0C_F0OM				(0x1u<<31)
#define	FDCAN_RXF0C_F0WM				(0x7Fu<<24)
#define	FDCAN_RXF0C_F0WM_0				(0x1u<<24)
#define	FDCAN_RXF0C_F0S					(0x7Fu<<16)
#define	FDCAN_RXF0C_F0S_0				(0x1u<<16)
#define	FDCAN_RXF0C_F0SA				(0x3FFFu<<2)
#define	FDCAN_RXF0C_F0SA_0				(0x1u<<2)

#define	FDCAN_RXF0C_F0OM_B_0X0			(0x0u<<31)
#define	FDCAN_RXF0C_F0OM_B_0X1			(0x1u<<31)
#define	FDCAN_RXF0C_F0WM_B_0X0			(0x0u<<24)
#define	FDCAN_RXF0C_F0S_B_0X0			(0x0u<<16)

// RXF0S Configuration

#define	FDCAN_RXF0S_RF0L				(0x1u<<25)
#define	FDCAN_RXF0S_F0F					(0x1u<<24)
#define	FDCAN_RXF0S_F0PI				(0x3Fu<<16)
#define	FDCAN_RXF0S_F0PI_0				(0x1u<<16)
#define	FDCAN_RXF0S_F0GI				(0x3Fu<<8)
#define	FDCAN_RXF0S_F0GI_0				(0x1u<<8)
#define	FDCAN_RXF0S_F0FL				(0x7Fu<<0)
#define	FDCAN_RXF0S_F0FL_0				(0x1u<<0)

#define	FDCAN_RXF0S_RF0L_B_0X0			(0x0u<<25)
#define	FDCAN_RXF0S_RF0L_B_0X1			(0x1u<<25)
#define	FDCAN_RXF0S_F0F_B_0X0			(0x0u<<24)
#define	FDCAN_RXF0S_F0F_B_0X1			(0x1u<<24)

// RXF0A Configuration

#define	FDCAN_RXF0A_F0AI				(0x3Fu<<0)
#define	FDCAN_RXF0A_F0AI_0				(0x1u<<0)

// RXBC Configuration

#define	FDCAN_RXBC_RBSA					(0x3FFFu<<2)
#define	FDCAN_RXBC_RBSA_0				(0x1u<<2)

// RXF1C Configuration

#define	FDCAN_RXF1C_F1OM				(0x1u<<31)
#define	FDCAN_RXF1C_F1WM				(0x7Fu<<24)
#define	FDCAN_RXF1C_F1WM_0				(0x1u<<24)
#define	FDCAN_RXF1C_F1S					(0x7Fu<<16)
#define	FDCAN_RXF1C_F1S_0				(0x1u<<16)
#define	FDCAN_RXF1C_F1SA				(0x3FFFu<<2)
#define	FDCAN_RXF1C_F1SA_0				(0x1u<<2)

#define	FDCAN_RXF1C_F1OM_B_0X0			(0x0u<<31)
#define	FDCAN_RXF1C_F1OM_B_0X1			(0x1u<<31)
#define	FDCAN_RXF1C_F1WM_B_0X0			(0x0u<<24)
#define	FDCAN_RXF1C_F1S_B_0X0			(0x0u<<16)

// RXF1S Configuration

#define	FDCAN_RXF1S_DMS					(0x3u<<30)
#define	FDCAN_RXF1S_DMS_0				(0x1u<<30)
#define	FDCAN_RXF1S_RF1L				(0x1u<<25)
#define	FDCAN_RXF1S_F1F					(0x1u<<24)
#define	FDCAN_RXF1S_F1PI				(0x3Fu<<16)
#define	FDCAN_RXF1S_F1PI_0				(0x1u<<16)
#define	FDCAN_RXF1S_F1GI				(0x3Fu<<8)
#define	FDCAN_RXF1S_F1GI_0				(0x1u<<8)
#define	FDCAN_RXF1S_F1FL				(0x7Fu<<0)
#define	FDCAN_RXF1S_F1FL_0				(0x1u<<0)

#define	FDCAN_RXF1S_DMS_B_0X0			(0x0u<<30)
#define	FDCAN_RXF1S_DMS_B_0X1			(0x1u<<30)
#define	FDCAN_RXF1S_DMS_B_0X2			(0x2u<<30)
#define	FDCAN_RXF1S_DMS_B_0X3			(0x3u<<30)
#define	FDCAN_RXF1S_RF1L_B_0X0			(0x0u<<25)
#define	FDCAN_RXF1S_RF1L_B_0X1			(0x1u<<25)
#define	FDCAN_RXF1S_F1F_B_0X0			(0x0u<<24)
#define	FDCAN_RXF1S_F1F_B_0X1			(0x1u<<24)

// RXF1A Configuration

#define	FDCAN_RXF1A_F1AI				(0x3Fu<<0)
#define	FDCAN_RXF1A_F1AI_0				(0x1u<<0)

// RXESC Configuration

#define	FDCAN_RXESC_RBDS				(0x7u<<8)
#define	FDCAN_RXESC_RBDS_0				(0x1u<<8)
#define	FDCAN_RXESC_F1DS				(0x7u<<4)
#define	FDCAN_RXESC_F1DS_0				(0x1u<<4)
#define	FDCAN_RXESC_F0DS				(0x7u<<0)
#define	FDCAN_RXESC_F0DS_0				(0x1u<<0)

#define	FDCAN_RXESC_RBDS_B_0X0			(0x0u<<8)
#define	FDCAN_RXESC_RBDS_B_0X1			(0x1u<<8)
#define	FDCAN_RXESC_RBDS_B_0X2			(0x2u<<8)
#define	FDCAN_RXESC_RBDS_B_0X3			(0x3u<<8)
#define	FDCAN_RXESC_RBDS_B_0X4			(0x4u<<8)
#define	FDCAN_RXESC_RBDS_B_0X5			(0x5u<<8)
#define	FDCAN_RXESC_RBDS_B_0X6			(0x6u<<8)
#define	FDCAN_RXESC_RBDS_B_0X7			(0x7u<<8)
#define	FDCAN_RXESC_F1DS_B_0X0			(0x0u<<4)
#define	FDCAN_RXESC_F1DS_B_0X1			(0x1u<<4)
#define	FDCAN_RXESC_F1DS_B_0X2			(0x2u<<4)
#define	FDCAN_RXESC_F1DS_B_0X3			(0x3u<<4)
#define	FDCAN_RXESC_F1DS_B_0X4			(0x4u<<4)
#define	FDCAN_RXESC_F1DS_B_0X5			(0x5u<<4)
#define	FDCAN_RXESC_F1DS_B_0X6			(0x6u<<4)
#define	FDCAN_RXESC_F1DS_B_0X7			(0x7u<<4)
#define	FDCAN_RXESC_F0DS_B_0X0			(0x0u<<0)
#define	FDCAN_RXESC_F0DS_B_0X1			(0x1u<<0)
#define	FDCAN_RXESC_F0DS_B_0X2			(0x2u<<0)
#define	FDCAN_RXESC_F0DS_B_0X3			(0x3u<<0)
#define	FDCAN_RXESC_F0DS_B_0X4			(0x4u<<0)
#define	FDCAN_RXESC_F0DS_B_0X5			(0x5u<<0)
#define	FDCAN_RXESC_F0DS_B_0X6			(0x6u<<0)
#define	FDCAN_RXESC_F0DS_B_0X7			(0x7u<<0)

// TXBC Configuration

#define	FDCAN_TXBC_TFQM					(0x1u<<30)
#define	FDCAN_TXBC_TFQS					(0x3Fu<<24)
#define	FDCAN_TXBC_TFQS_0				(0x1u<<24)
#define	FDCAN_TXBC_NDTB					(0x3Fu<<16)
#define	FDCAN_TXBC_NDTB_0				(0x1u<<16)
#define	FDCAN_TXBC_TBSA					(0x3FFFu<<2)
#define	FDCAN_TXBC_TBSA_0				(0x1u<<2)

#define	FDCAN_TXBC_TFQM_B_0X0			(0x0u<<30)
#define	FDCAN_TXBC_TFQM_B_0X1			(0x1u<<30)
#define	FDCAN_TXBC_TFQS_B_0X0			(0x0u<<24)
#define	FDCAN_TXBC_NDTB_B_0X0			(0x0u<<16)

// TXFQS Configuration

#define	FDCAN_TXFQS_TFQF				(0x1u<<21)
#define	FDCAN_TXFQS_TFQPI				(0x1Fu<<16)
#define	FDCAN_TXFQS_TFQPI_0				(0x1u<<16)
#define	FDCAN_TXFQS_TFGI				(0x1Fu<<8)
#define	FDCAN_TXFQS_TFGI_0				(0x1u<<8)
#define	FDCAN_TXFQS_TFFL				(0x3Fu<<0)
#define	FDCAN_TXFQS_TFFL_0				(0x1u<<0)

// TXESC Configuration

#define	FDCAN_TXESC_TBDS				(0x7u<<0)
#define	FDCAN_TXESC_TBDS_0				(0x1u<<0)

#define	FDCAN_TXESC_TBDS_B_0X0			(0x0u<<0)
#define	FDCAN_TXESC_TBDS_B_0X1			(0x1u<<0)
#define	FDCAN_TXESC_TBDS_B_0X2			(0x2u<<0)
#define	FDCAN_TXESC_TBDS_B_0X3			(0x3u<<0)
#define	FDCAN_TXESC_TBDS_B_0X4			(0x4u<<0)
#define	FDCAN_TXESC_TBDS_B_0X5			(0x5u<<0)
#define	FDCAN_TXESC_TBDS_B_0X6			(0x6u<<0)
#define	FDCAN_TXESC_TBDS_B_0X7			(0x7u<<0)

// TXBRP Configuration

#define	FDCAN_TXBRP_TRP					(0xFFFFFFFFu<<0)
#define	FDCAN_TXBRP_TRP_0				(0x1u<<0)

#define	FDCAN_TXBRP_TRP_B_0X0			(0x0u<<0)
#define	FDCAN_TXBRP_TRP_B_0X1			(0x1u<<0)

// TXBAR Configuration

#define	FDCAN_TXBAR_AR					(0xFFFFFFFFu<<0)
#define	FDCAN_TXBAR_AR_0				(0x1u<<0)

#define	FDCAN_TXBAR_AR_B_0X0			(0x0u<<0)
#define	FDCAN_TXBAR_AR_B_0X1			(0x1u<<0)

// TXBCR Configuration

#define	FDCAN_TXBCR_CR					(0xFFFFFFFFu<<0)
#define	FDCAN_TXBCR_CR_0				(0x1u<<0)

#define	FDCAN_TXBCR_CR_B_0X0			(0x0u<<0)
#define	FDCAN_TXBCR_CR_B_0X1			(0x1u<<0)

// TXBTO Configuration

#define	FDCAN_TXBTO_TO					(0xFFFFFFFFu<<0)
#define	FDCAN_TXBTO_TO_0				(0x1u<<0)

#define	FDCAN_TXBTO_TO_B_0X0			(0x0u<<0)
#define	FDCAN_TXBTO_TO_B_0X1			(0x1u<<0)

// TXBCF Configuration

#define	FDCAN_TXBCF_CF					(0xFFFFFFFFu<<0)
#define	FDCAN_TXBCF_CF_0				(0x1u<<0)

#define	FDCAN_TXBCF_CF_B_0X0			(0x0u<<0)
#define	FDCAN_TXBCF_CF_B_0X1			(0x1u<<0)

// TXBTIE Configuration

#define	FDCAN_TXBTIE_TIE				(0xFFFFFFFFu<<0)
#define	FDCAN_TXBTIE_TIE_0				(0x1u<<0)

#define	FDCAN_TXBTIE_TIE_B_0X0			(0x0u<<0)
#define	FDCAN_TXBTIE_TIE_B_0X1			(0x1u<<0)

// TXBCIE Configuration

#define	FDCAN_TXBCIE_CFIE				(0xFFFFFFFFu<<0)
#define	FDCAN_TXBCIE_CFIE_0				(0x1u<<0)

#define	FDCAN_TXBCIE_CFIE_B_0X0			(0x0u<<0)
#define	FDCAN_TXBCIE_CFIE_B_0X1			(0x1u<<0)

// TXEFC Configuration

#define	FDCAN_TXEFC_EFWM				(0x3Fu<<24)
#define	FDCAN_TXEFC_EFWM_0				(0x1u<<24)
#define	FDCAN_TXEFC_EFS					(0x3Fu<<16)
#define	FDCAN_TXEFC_EFS_0				(0x1u<<16)
#define	FDCAN_TXEFC_EFSA				(0x3FFFu<<2)
#define	FDCAN_TXEFC_EFSA_0				(0x1u<<2)

#define	FDCAN_TXEFC_EFWM_B_0X0			(0x0u<<24)
#define	FDCAN_TXEFC_EFS_B_0X0			(0x0u<<16)

// TXEFS Configuration

#define	FDCAN_TXEFS_TEFL				(0x1u<<25)
#define	FDCAN_TXEFS_EFF					(0x1u<<24)
#define	FDCAN_TXEFS_EFPI				(0x1Fu<<16)
#define	FDCAN_TXEFS_EFPI_0				(0x1u<<16)
#define	FDCAN_TXEFS_EFGI				(0x1Fu<<8)
#define	FDCAN_TXEFS_EFGI_0				(0x1u<<8)
#define	FDCAN_TXEFS_EFFL				(0x3Fu<<0)
#define	FDCAN_TXEFS_EFFL_0				(0x1u<<0)

#define	FDCAN_TXEFS_EFF_B_0X0			(0x0u<<24)
#define	FDCAN_TXEFS_EFF_B_0X1			(0x1u<<24)

// TXEFA Configuration

#define	FDCAN_TXEFA_EFAI				(0x1Fu<<0)
#define	FDCAN_TXEFA_EFAI_0				(0x1u<<0)

// TTTMC Configuration

#define	FDCAN_TTTMC_TME					(0x7Fu<<16)
#define	FDCAN_TTTMC_TME_0				(0x1u<<16)
#define	FDCAN_TTTMC_TMSA				(0x3FFFu<<2)
#define	FDCAN_TTTMC_TMSA_0				(0x1u<<2)

#define	FDCAN_TTTMC_TME_B_0X0			(0x0u<<16)

// TTRMC Configuration

#define	FDCAN_TTRMC_RMPS				(0x1u<<31)
#define	FDCAN_TTRMC_XTD					(0x1u<<30)
#define	FDCAN_TTRMC_RID					(0x1FFFFFFFu<<0)
#define	FDCAN_TTRMC_RID_0				(0x1u<<0)

#define	FDCAN_TTRMC_RMPS_B_0X0			(0x0u<<31)
#define	FDCAN_TTRMC_RMPS_B_0X1			(0x1u<<31)
#define	FDCAN_TTRMC_XTD_B_0X0			(0x0u<<30)
#define	FDCAN_TTRMC_XTD_B_0X1			(0x1u<<30)

// TTOCF Configuration

#define	FDCAN_TTOCF_EVTP				(0x1u<<26)
#define	FDCAN_TTOCF_ECC					(0x1u<<25)
#define	FDCAN_TTOCF_EGTF				(0x1u<<24)
#define	FDCAN_TTOCF_AWL					(0xFFu<<16)
#define	FDCAN_TTOCF_AWL_0				(0x1u<<16)
#define	FDCAN_TTOCF_EECS				(0x1u<<15)
#define	FDCAN_TTOCF_IRTO				(0x7Fu<<8)
#define	FDCAN_TTOCF_IRTO_0				(0x1u<<8)
#define	FDCAN_TTOCF_LDSDL				(0x7u<<5)
#define	FDCAN_TTOCF_LDSDL_0				(0x1u<<5)
#define	FDCAN_TTOCF_TM					(0x1u<<4)
#define	FDCAN_TTOCF_GEN					(0x1u<<3)
#define	FDCAN_TTOCF_OM					(0x3u<<0)
#define	FDCAN_TTOCF_OM_0				(0x1u<<0)

#define	FDCAN_TTOCF_EVTP_B_0X0			(0x0u<<26)
#define	FDCAN_TTOCF_EVTP_B_0X1			(0x1u<<26)
#define	FDCAN_TTOCF_ECC_B_0X0			(0x0u<<25)
#define	FDCAN_TTOCF_ECC_B_0X1			(0x1u<<25)
#define	FDCAN_TTOCF_EGTF_B_0X0			(0x0u<<24)
#define	FDCAN_TTOCF_EGTF_B_0X1			(0x1u<<24)
#define	FDCAN_TTOCF_EECS_B_0X0			(0x0u<<15)
#define	FDCAN_TTOCF_EECS_B_0X1			(0x1u<<15)
#define	FDCAN_TTOCF_TM_B_0X0			(0x0u<<4)
#define	FDCAN_TTOCF_TM_B_0X1			(0x1u<<4)
#define	FDCAN_TTOCF_GEN_B_0X0			(0x0u<<3)
#define	FDCAN_TTOCF_GEN_B_0X1			(0x1u<<3)
#define	FDCAN_TTOCF_OM_B_0X0			(0x0u<<0)
#define	FDCAN_TTOCF_OM_B_0X1			(0x1u<<0)
#define	FDCAN_TTOCF_OM_B_0X2			(0x2u<<0)
#define	FDCAN_TTOCF_OM_B_0X3			(0x3u<<0)

// TTMLM Configuration

#define	FDCAN_TTMLM_ENTT				(0xFFFu<<16)
#define	FDCAN_TTMLM_ENTT_0				(0x1u<<16)
#define	FDCAN_TTMLM_TXEW				(0xFu<<8)
#define	FDCAN_TTMLM_TXEW_0				(0x1u<<8)
#define	FDCAN_TTMLM_CSS					(0x3u<<6)
#define	FDCAN_TTMLM_CSS_0				(0x1u<<6)
#define	FDCAN_TTMLM_CCM					(0x3Fu<<0)
#define	FDCAN_TTMLM_CCM_0				(0x1u<<0)

#define	FDCAN_TTMLM_CSS_B_0X0			(0x0u<<6)
#define	FDCAN_TTMLM_CSS_B_0X1			(0x1u<<6)
#define	FDCAN_TTMLM_CSS_B_0X2			(0x2u<<6)
#define	FDCAN_TTMLM_CCM_B_0X00			(0x0u<<0)
#define	FDCAN_TTMLM_CCM_B_0X01			(0x1u<<0)
#define	FDCAN_TTMLM_CCM_B_0X03			(0x3u<<0)
#define	FDCAN_TTMLM_CCM_B_0X07			(0x7u<<0)
#define	FDCAN_TTMLM_CCM_B_0X0F			(0xFu<<0)
#define	FDCAN_TTMLM_CCM_B_0X1F			(0x1Fu<<0)
#define	FDCAN_TTMLM_CCM_B_0X3F			(0x3Fu<<0)

// TURCF Configuration

#define	FDCAN_TURCF_ELT					(0x1u<<31)
#define	FDCAN_TURCF_DC					(0x3FFFu<<16)
#define	FDCAN_TURCF_DC_0				(0x1u<<16)
#define	FDCAN_TURCF_NCL					(0xFFFFu<<0)
#define	FDCAN_TURCF_NCL_0				(0x1u<<0)

#define	FDCAN_TURCF_ELT_B_0X0			(0x0u<<31)
#define	FDCAN_TURCF_ELT_B_0X1			(0x1u<<31)
#define	FDCAN_TURCF_DC_B_0X0000			(0x0u<<16)

// TTOCN Configuration

#define	FDCAN_TTOCN_LCKC				(0x1u<<15)
#define	FDCAN_TTOCN_ESCN				(0x1u<<13)
#define	FDCAN_TTOCN_NIG					(0x1u<<12)
#define	FDCAN_TTOCN_TMG					(0x1u<<11)
#define	FDCAN_TTOCN_FGP					(0x1u<<10)
#define	FDCAN_TTOCN_GCS					(0x1u<<9)
#define	FDCAN_TTOCN_TTIE				(0x1u<<8)
#define	FDCAN_TTOCN_TMC					(0x3u<<6)
#define	FDCAN_TTOCN_TMC_0				(0x1u<<6)
#define	FDCAN_TTOCN_RTIE				(0x1u<<5)
#define	FDCAN_TTOCN_SWS					(0x3u<<3)
#define	FDCAN_TTOCN_SWS_0				(0x1u<<3)
#define	FDCAN_TTOCN_SWP					(0x1u<<2)
#define	FDCAN_TTOCN_ECS					(0x1u<<1)
#define	FDCAN_TTOCN_SGT					(0x1u<<0)

#define	FDCAN_TTOCN_LCKC_B_0X0			(0x0u<<15)
#define	FDCAN_TTOCN_LCKC_B_0X1			(0x1u<<15)
#define	FDCAN_TTOCN_ESCN_B_0X0			(0x0u<<13)
#define	FDCAN_TTOCN_ESCN_B_0X1			(0x1u<<13)
#define	FDCAN_TTOCN_NIG_B_0X0			(0x0u<<12)
#define	FDCAN_TTOCN_NIG_B_0X1			(0x1u<<12)
#define	FDCAN_TTOCN_TMG_B_0X0			(0x0u<<11)
#define	FDCAN_TTOCN_TMG_B_0X1			(0x1u<<11)
#define	FDCAN_TTOCN_FGP_B_0X0			(0x0u<<10)
#define	FDCAN_TTOCN_FGP_B_0X1			(0x1u<<10)
#define	FDCAN_TTOCN_GCS_B_0X0			(0x0u<<9)
#define	FDCAN_TTOCN_GCS_B_0X1			(0x1u<<9)
#define	FDCAN_TTOCN_TTIE_B_0X0			(0x0u<<8)
#define	FDCAN_TTOCN_TTIE_B_0X1			(0x1u<<8)
#define	FDCAN_TTOCN_TMC_B_0X0			(0x0u<<6)
#define	FDCAN_TTOCN_TMC_B_0X1			(0x1u<<6)
#define	FDCAN_TTOCN_TMC_B_0X2			(0x2u<<6)
#define	FDCAN_TTOCN_TMC_B_0X3			(0x3u<<6)
#define	FDCAN_TTOCN_RTIE_B_0X0			(0x0u<<5)
#define	FDCAN_TTOCN_RTIE_B_0X1			(0x1u<<5)
#define	FDCAN_TTOCN_SWS_B_0X0			(0x0u<<3)
#define	FDCAN_TTOCN_SWS_B_0X1			(0x1u<<3)
#define	FDCAN_TTOCN_SWS_B_0X2			(0x2u<<3)
#define	FDCAN_TTOCN_SWS_B_0X3			(0x3u<<3)
#define	FDCAN_TTOCN_SWP_B_0X0			(0x0u<<2)
#define	FDCAN_TTOCN_SWP_B_0X1			(0x1u<<2)

// TTGTP Configuration

#define	FDCAN_TTGTP_CTP					(0xFFFFu<<16)
#define	FDCAN_TTGTP_CTP_0				(0x1u<<16)
#define	FDCAN_TTGTP_TP					(0xFFFFu<<0)
#define	FDCAN_TTGTP_TP_0				(0x1u<<0)

// TTTMK Configuration

#define	FDCAN_TTTMK_LCKM				(0x1u<<31)
#define	FDCAN_TTTMK_TICC				(0x7Fu<<16)
#define	FDCAN_TTTMK_TICC_0				(0x1u<<16)
#define	FDCAN_TTTMK_TM					(0xFFFFu<<0)
#define	FDCAN_TTTMK_TM_0				(0x1u<<0)

#define	FDCAN_TTTMK_LCKM_B_0X0			(0x0u<<31)
#define	FDCAN_TTTMK_LCKM_B_0X1			(0x1u<<31)

// TTIR Configuration

#define	FDCAN_TTIR_CER					(0x1u<<18)
#define	FDCAN_TTIR_AW					(0x1u<<17)
#define	FDCAN_TTIR_WT					(0x1u<<16)
#define	FDCAN_TTIR_IWTG					(0x1u<<15)
#define	FDCAN_TTIR_ELC					(0x1u<<14)
#define	FDCAN_TTIR_SE2					(0x1u<<13)
#define	FDCAN_TTIR_SE1					(0x1u<<12)
#define	FDCAN_TTIR_TXO					(0x1u<<11)
#define	FDCAN_TTIR_TXU					(0x1u<<10)
#define	FDCAN_TTIR_GTE					(0x1u<<9)
#define	FDCAN_TTIR_GTD					(0x1u<<8)
#define	FDCAN_TTIR_GTW					(0x1u<<7)
#define	FDCAN_TTIR_SWE					(0x1u<<6)
#define	FDCAN_TTIR_TTMI					(0x1u<<5)
#define	FDCAN_TTIR_RTMI					(0x1u<<4)
#define	FDCAN_TTIR_SOG					(0x1u<<3)
#define	FDCAN_TTIR_CSM					(0x1u<<2)
#define	FDCAN_TTIR_SMC					(0x1u<<1)
#define	FDCAN_TTIR_SBC					(0x1u<<0)

#define	FDCAN_TTIR_CER_B_0X0			(0x0u<<18)
#define	FDCAN_TTIR_CER_B_0X1			(0x1u<<18)
#define	FDCAN_TTIR_AW_B_0X0				(0x0u<<17)
#define	FDCAN_TTIR_AW_B_0X1				(0x1u<<17)
#define	FDCAN_TTIR_WT_B_0X0				(0x0u<<16)
#define	FDCAN_TTIR_WT_B_0X1				(0x1u<<16)
#define	FDCAN_TTIR_ELC_B_0X0			(0x0u<<14)
#define	FDCAN_TTIR_ELC_B_0X1			(0x1u<<14)
#define	FDCAN_TTIR_SE2_B_0X0			(0x0u<<13)
#define	FDCAN_TTIR_SE2_B_0X1			(0x1u<<13)
#define	FDCAN_TTIR_SE1_B_0X0			(0x0u<<12)
#define	FDCAN_TTIR_SE1_B_0X1			(0x1u<<12)
#define	FDCAN_TTIR_TXO_B_0X0			(0x0u<<11)
#define	FDCAN_TTIR_TXO_B_0X1			(0x1u<<11)
#define	FDCAN_TTIR_TXU_B_0X0			(0x0u<<10)
#define	FDCAN_TTIR_TXU_B_0X1			(0x1u<<10)
#define	FDCAN_TTIR_GTE_B_0X0			(0x0u<<9)
#define	FDCAN_TTIR_GTE_B_0X1			(0x1u<<9)
#define	FDCAN_TTIR_GTD_B_0X0			(0x0u<<8)
#define	FDCAN_TTIR_GTD_B_0X1			(0x1u<<8)
#define	FDCAN_TTIR_GTW_B_0X0			(0x0u<<7)
#define	FDCAN_TTIR_GTW_B_0X1			(0x1u<<7)
#define	FDCAN_TTIR_SWE_B_0X0			(0x0u<<6)
#define	FDCAN_TTIR_SWE_B_0X1			(0x1u<<6)
#define	FDCAN_TTIR_TTMI_B_0X0			(0x0u<<5)
#define	FDCAN_TTIR_TTMI_B_0X1			(0x1u<<5)
#define	FDCAN_TTIR_RTMI_B_0X0			(0x0u<<4)
#define	FDCAN_TTIR_RTMI_B_0X1			(0x1u<<4)
#define	FDCAN_TTIR_CSM_B_0X0			(0x0u<<2)
#define	FDCAN_TTIR_CSM_B_0X1			(0x1u<<2)
#define	FDCAN_TTIR_SMC_B_0X0			(0x0u<<1)
#define	FDCAN_TTIR_SMC_B_0X1			(0x1u<<1)
#define	FDCAN_TTIR_SBC_B_0X0			(0x0u<<0)
#define	FDCAN_TTIR_SBC_B_0X1			(0x1u<<0)

// TTIE Configuration

#define	FDCAN_TTIE_CERE					(0x1u<<18)
#define	FDCAN_TTIE_AWE					(0x1u<<17)
#define	FDCAN_TTIE_WTE					(0x1u<<16)
#define	FDCAN_TTIE_IWTE					(0x1u<<15)
#define	FDCAN_TTIE_ELCE					(0x1u<<14)
#define	FDCAN_TTIE_SE2E					(0x1u<<13)
#define	FDCAN_TTIE_SE1E					(0x1u<<12)
#define	FDCAN_TTIE_TXOE					(0x1u<<11)
#define	FDCAN_TTIE_TXUE					(0x1u<<10)
#define	FDCAN_TTIE_GTEE					(0x1u<<9)
#define	FDCAN_TTIE_GTDE					(0x1u<<8)
#define	FDCAN_TTIE_GTWE					(0x1u<<7)
#define	FDCAN_TTIE_SWEE					(0x1u<<6)
#define	FDCAN_TTIE_TTMIE				(0x1u<<5)
#define	FDCAN_TTIE_RTMIE				(0x1u<<4)
#define	FDCAN_TTIE_SOGE					(0x1u<<3)
#define	FDCAN_TTIE_CSME					(0x1u<<2)
#define	FDCAN_TTIE_SMCE					(0x1u<<1)
#define	FDCAN_TTIE_SBCE					(0x1u<<0)

#define	FDCAN_TTIE_CERE_B_0X0			(0x0u<<18)
#define	FDCAN_TTIE_CERE_B_0X1			(0x1u<<18)
#define	FDCAN_TTIE_AWE_B_0X0			(0x0u<<17)
#define	FDCAN_TTIE_AWE_B_0X1			(0x1u<<17)
#define	FDCAN_TTIE_WTE_B_0X0			(0x0u<<16)
#define	FDCAN_TTIE_WTE_B_0X1			(0x1u<<16)
#define	FDCAN_TTIE_IWTE_B_0X0			(0x0u<<15)
#define	FDCAN_TTIE_IWTE_B_0X1			(0x1u<<15)
#define	FDCAN_TTIE_ELCE_B_0X0			(0x0u<<14)
#define	FDCAN_TTIE_ELCE_B_0X1			(0x1u<<14)
#define	FDCAN_TTIE_SE2E_B_0X0			(0x0u<<13)
#define	FDCAN_TTIE_SE2E_B_0X1			(0x1u<<13)
#define	FDCAN_TTIE_SE1E_B_0X0			(0x0u<<12)
#define	FDCAN_TTIE_SE1E_B_0X1			(0x1u<<12)
#define	FDCAN_TTIE_TXOE_B_0X0			(0x0u<<11)
#define	FDCAN_TTIE_TXOE_B_0X1			(0x1u<<11)
#define	FDCAN_TTIE_TXUE_B_0X0			(0x0u<<10)
#define	FDCAN_TTIE_TXUE_B_0X1			(0x1u<<10)
#define	FDCAN_TTIE_GTEE_B_0X0			(0x0u<<9)
#define	FDCAN_TTIE_GTEE_B_0X1			(0x1u<<9)
#define	FDCAN_TTIE_GTDE_B_0X0			(0x0u<<8)
#define	FDCAN_TTIE_GTDE_B_0X1			(0x1u<<8)
#define	FDCAN_TTIE_GTWE_B_0X0			(0x0u<<7)
#define	FDCAN_TTIE_GTWE_B_0X1			(0x1u<<7)
#define	FDCAN_TTIE_SWEE_B_0X0			(0x0u<<6)
#define	FDCAN_TTIE_SWEE_B_0X1			(0x1u<<6)
#define	FDCAN_TTIE_TTMIE_B_0X0			(0x0u<<5)
#define	FDCAN_TTIE_TTMIE_B_0X1			(0x1u<<5)
#define	FDCAN_TTIE_RTMIE_B_0X0			(0x0u<<4)
#define	FDCAN_TTIE_RTMIE_B_0X1			(0x1u<<4)
#define	FDCAN_TTIE_SOGE_B_0X0			(0x0u<<3)
#define	FDCAN_TTIE_SOGE_B_0X1			(0x1u<<3)
#define	FDCAN_TTIE_CSME_B_0X0			(0x0u<<2)
#define	FDCAN_TTIE_CSME_B_0X1			(0x1u<<2)
#define	FDCAN_TTIE_SMCE_B_0X0			(0x0u<<1)
#define	FDCAN_TTIE_SMCE_B_0X1			(0x1u<<1)
#define	FDCAN_TTIE_SBCE_B_0X0			(0x0u<<0)
#define	FDCAN_TTIE_SBCE_B_0X1			(0x1u<<0)

// TTILS Configuration

#define	FDCAN_TTILS_CERL				(0x1u<<18)
#define	FDCAN_TTILS_AWL					(0x1u<<17)
#define	FDCAN_TTILS_WTL					(0x1u<<16)
#define	FDCAN_TTILS_IWTL				(0x1u<<15)
#define	FDCAN_TTILS_ELCL				(0x1u<<14)
#define	FDCAN_TTILS_SE2L				(0x1u<<13)
#define	FDCAN_TTILS_SE1L				(0x1u<<12)
#define	FDCAN_TTILS_TXOL				(0x1u<<11)
#define	FDCAN_TTILS_TXUL				(0x1u<<10)
#define	FDCAN_TTILS_GTEL				(0x1u<<9)
#define	FDCAN_TTILS_GTDL				(0x1u<<8)
#define	FDCAN_TTILS_GTWL				(0x1u<<7)
#define	FDCAN_TTILS_SWEL				(0x1u<<6)
#define	FDCAN_TTILS_TTMIL				(0x1u<<5)
#define	FDCAN_TTILS_RTMIL				(0x1u<<4)
#define	FDCAN_TTILS_SOGL				(0x1u<<3)
#define	FDCAN_TTILS_CSML				(0x1u<<2)
#define	FDCAN_TTILS_SMCL				(0x1u<<1)
#define	FDCAN_TTILS_SBCL				(0x1u<<0)

#define	FDCAN_TTILS_CERL_B_0X0			(0x0u<<18)
#define	FDCAN_TTILS_CERL_B_0X1			(0x1u<<18)
#define	FDCAN_TTILS_AWL_B_0X0			(0x0u<<17)
#define	FDCAN_TTILS_AWL_B_0X1			(0x1u<<17)
#define	FDCAN_TTILS_WTL_B_0X0			(0x0u<<16)
#define	FDCAN_TTILS_WTL_B_0X1			(0x1u<<16)
#define	FDCAN_TTILS_IWTL_B_0X0			(0x0u<<15)
#define	FDCAN_TTILS_IWTL_B_0X1			(0x1u<<15)
#define	FDCAN_TTILS_ELCL_B_0X0			(0x0u<<14)
#define	FDCAN_TTILS_ELCL_B_0X1			(0x1u<<14)
#define	FDCAN_TTILS_SE2L_B_0X0			(0x0u<<13)
#define	FDCAN_TTILS_SE2L_B_0X1			(0x1u<<13)
#define	FDCAN_TTILS_SE1L_B_0X0			(0x0u<<12)
#define	FDCAN_TTILS_SE1L_B_0X1			(0x1u<<12)
#define	FDCAN_TTILS_TXOL_B_0X0			(0x0u<<11)
#define	FDCAN_TTILS_TXOL_B_0X1			(0x1u<<11)
#define	FDCAN_TTILS_TXUL_B_0X0			(0x0u<<10)
#define	FDCAN_TTILS_TXUL_B_0X1			(0x1u<<10)
#define	FDCAN_TTILS_GTEL_B_0X0			(0x0u<<9)
#define	FDCAN_TTILS_GTEL_B_0X1			(0x1u<<9)
#define	FDCAN_TTILS_GTDL_B_0X0			(0x0u<<8)
#define	FDCAN_TTILS_GTDL_B_0X1			(0x1u<<8)
#define	FDCAN_TTILS_GTWL_B_0X0			(0x0u<<7)
#define	FDCAN_TTILS_GTWL_B_0X1			(0x1u<<7)
#define	FDCAN_TTILS_SWEL_B_0X0			(0x0u<<6)
#define	FDCAN_TTILS_SWEL_B_0X1			(0x1u<<6)
#define	FDCAN_TTILS_TTMIL_B_0X0			(0x0u<<5)
#define	FDCAN_TTILS_TTMIL_B_0X1			(0x1u<<5)
#define	FDCAN_TTILS_RTMIL_B_0X0			(0x0u<<4)
#define	FDCAN_TTILS_RTMIL_B_0X1			(0x1u<<4)
#define	FDCAN_TTILS_SOGL_B_0X0			(0x0u<<3)
#define	FDCAN_TTILS_SOGL_B_0X1			(0x1u<<3)
#define	FDCAN_TTILS_CSML_B_0X0			(0x0u<<2)
#define	FDCAN_TTILS_CSML_B_0X1			(0x1u<<2)
#define	FDCAN_TTILS_SMCL_B_0X0			(0x0u<<1)
#define	FDCAN_TTILS_SMCL_B_0X1			(0x1u<<1)
#define	FDCAN_TTILS_SBCL_B_0X0			(0x0u<<0)
#define	FDCAN_TTILS_SBCL_B_0X1			(0x1u<<0)

// TTOST Configuration

#define	FDCAN_TTOST_SPL					(0x1u<<31)
#define	FDCAN_TTOST_WECS				(0x1u<<30)
#define	FDCAN_TTOST_AWE					(0x1u<<29)
#define	FDCAN_TTOST_WFE					(0x1u<<28)
#define	FDCAN_TTOST_GSI					(0x1u<<27)
#define	FDCAN_TTOST_TMP					(0x7u<<24)
#define	FDCAN_TTOST_TMP_0				(0x1u<<24)
#define	FDCAN_TTOST_GFI					(0x1u<<23)
#define	FDCAN_TTOST_WGTD				(0x1u<<22)
#define	FDCAN_TTOST_RTO					(0xFFu<<8)
#define	FDCAN_TTOST_RTO_0				(0x1u<<8)
#define	FDCAN_TTOST_QCS					(0x1u<<7)
#define	FDCAN_TTOST_QGTP				(0x1u<<6)
#define	FDCAN_TTOST_SYS					(0x3u<<4)
#define	FDCAN_TTOST_SYS_0				(0x1u<<4)
#define	FDCAN_TTOST_MS					(0x3u<<2)
#define	FDCAN_TTOST_MS_0				(0x1u<<2)
#define	FDCAN_TTOST_EL					(0x3u<<0)
#define	FDCAN_TTOST_EL_0				(0x1u<<0)

#define	FDCAN_TTOST_SPL_B_0X0			(0x0u<<31)
#define	FDCAN_TTOST_SPL_B_0X1			(0x1u<<31)
#define	FDCAN_TTOST_WECS_B_0X0			(0x0u<<30)
#define	FDCAN_TTOST_WECS_B_0X1			(0x1u<<30)
#define	FDCAN_TTOST_AWE_B_0X0			(0x0u<<29)
#define	FDCAN_TTOST_AWE_B_0X1			(0x1u<<29)
#define	FDCAN_TTOST_WFE_B_0X0			(0x0u<<28)
#define	FDCAN_TTOST_WFE_B_0X1			(0x1u<<28)
#define	FDCAN_TTOST_GSI_B_0X0			(0x0u<<27)
#define	FDCAN_TTOST_GSI_B_0X1			(0x1u<<27)
#define	FDCAN_TTOST_GFI_B_0X0			(0x0u<<23)
#define	FDCAN_TTOST_GFI_B_0X1			(0x1u<<23)
#define	FDCAN_TTOST_WGTD_B_0X0			(0x0u<<22)
#define	FDCAN_TTOST_WGTD_B_0X1			(0x1u<<22)
#define	FDCAN_TTOST_QCS_B_0X0			(0x0u<<7)
#define	FDCAN_TTOST_QCS_B_0X1			(0x1u<<7)
#define	FDCAN_TTOST_QGTP_B_0X0			(0x0u<<6)
#define	FDCAN_TTOST_QGTP_B_0X1			(0x1u<<6)
#define	FDCAN_TTOST_SYS_B_0X0			(0x0u<<4)
#define	FDCAN_TTOST_SYS_B_0X1			(0x1u<<4)
#define	FDCAN_TTOST_SYS_B_0X2			(0x2u<<4)
#define	FDCAN_TTOST_SYS_B_0X3			(0x3u<<4)
#define	FDCAN_TTOST_MS_B_0X0			(0x0u<<2)
#define	FDCAN_TTOST_MS_B_0X1			(0x1u<<2)
#define	FDCAN_TTOST_MS_B_0X2			(0x2u<<2)
#define	FDCAN_TTOST_MS_B_0X3			(0x3u<<2)
#define	FDCAN_TTOST_EL_B_0X0			(0x0u<<0)
#define	FDCAN_TTOST_EL_B_0X1			(0x1u<<0)
#define	FDCAN_TTOST_EL_B_0X2			(0x2u<<0)
#define	FDCAN_TTOST_EL_B_0X3			(0x3u<<0)

// TURNA Configuration

#define	FDCAN_TURNA_NAV					(0x3FFFFu<<0)
#define	FDCAN_TURNA_NAV_0				(0x1u<<0)

#define	FDCAN_TURNA_NAV_B_0X0EFFF		(0xEFFFu<<0)
#define	FDCAN_TURNA_NAV_B_0X21000		(0x21000u<<0)

// TTLGT Configuration

#define	FDCAN_TTLGT_GT					(0xFFFFu<<16)
#define	FDCAN_TTLGT_GT_0				(0x1u<<16)
#define	FDCAN_TTLGT_LT					(0xFFFFu<<0)
#define	FDCAN_TTLGT_LT_0				(0x1u<<0)

// TTCTC Configuration

#define	FDCAN_TTCTC_CC					(0x3Fu<<16)
#define	FDCAN_TTCTC_CC_0				(0x1u<<16)
#define	FDCAN_TTCTC_CT					(0xFFFFu<<0)
#define	FDCAN_TTCTC_CT_0				(0x1u<<0)

// TTCPT Configuration

#define	FDCAN_TTCPT_SWV					(0xFFFFu<<16)
#define	FDCAN_TTCPT_SWV_0				(0x1u<<16)
#define	FDCAN_TTCPT_CCV					(0x3Fu<<0)
#define	FDCAN_TTCPT_CCV_0				(0x1u<<0)

// TTCSM Configuration

#define	FDCAN_TTCSM_CSM					(0xFFFFu<<0)
#define	FDCAN_TTCSM_CSM_0				(0x1u<<0)

// TTTS Configuration

#define	FDCAN_TTTS_EVTSEL				(0x3u<<4)
#define	FDCAN_TTTS_EVTSEL_0				(0x1u<<4)
#define	FDCAN_TTTS_SWTDEL				(0x3u<<0)
#define	FDCAN_TTTS_SWTDEL_0				(0x1u<<0)

#define	FDCAN_TTTS_EVTSEL_B_0X0			(0x0u<<4)
#define	FDCAN_TTTS_EVTSEL_B_0X1			(0x1u<<4)
#define	FDCAN_TTTS_EVTSEL_B_0X2			(0x2u<<4)
#define	FDCAN_TTTS_EVTSEL_B_0X3			(0x3u<<4)
#define	FDCAN_TTTS_SWTDEL_B_0X0			(0x0u<<0)
#define	FDCAN_TTTS_SWTDEL_B_0X1			(0x1u<<0)
#define	FDCAN_TTTS_SWTDEL_B_0X2			(0x2u<<0)
#define	FDCAN_TTTS_SWTDEL_B_0X3			(0x3u<<0)
