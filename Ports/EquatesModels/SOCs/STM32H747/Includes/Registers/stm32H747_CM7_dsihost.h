/*
; stm32H747_CM7_dsihost.
; ======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM7_dsihost equates.
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

// DSIHOST address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	DSI_VR;
	volatile	uint32_t	DSI_CR;
	volatile	uint32_t	DSI_CCR;
	volatile	uint32_t	DSI_LVCIDR;
	volatile	uint32_t	DSI_LCOLCR;
	volatile	uint32_t	DSI_LPCR;
	volatile	uint32_t	DSI_LPMCR;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	DSI_PCR;
	volatile	uint32_t	DSI_GVCIDR;
	volatile	uint32_t	DSI_MCR;
	volatile	uint32_t	DSI_VMCR;
	volatile	uint32_t	DSI_VPCR;
	volatile	uint32_t	DSI_VCCR;
	volatile	uint32_t	DSI_VNPCR;
	volatile	uint32_t	DSI_VHSACR;
	volatile	uint32_t	DSI_VHBPCR;
	volatile	uint32_t	DSI_VLCR;
	volatile	uint32_t	DSI_VVSACR;
	volatile	uint32_t	DSI_VVBPCR;
	volatile	uint32_t	DSI_VVFPCR;
	volatile	uint32_t	DSI_VVACR;
	volatile	uint32_t	DSI_LCCR;
	volatile	uint32_t	DSI_CMCR;
	volatile	uint32_t	DSI_GHCR;
	volatile	uint32_t	DSI_GPDR;
	volatile	uint32_t	DSI_GPSR;
	volatile	uint32_t	DSI_TCCR0;
	volatile	uint32_t	DSI_TCCR1;
	volatile	uint32_t	DSI_TCCR2;
	volatile	uint32_t	DSI_TCCR3;
	volatile	uint32_t	DSI_TCCR4;
	volatile	uint32_t	DSI_TCCR5;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	DSI_CLCR;
	volatile	uint32_t	DSI_CLTCR;
	volatile	uint32_t	DSI_DLTCR;
	volatile	uint32_t	DSI_PCTLR;
	volatile	uint32_t	DSI_PCONFR;
	volatile	uint32_t	DSI_PUCR;
	volatile	uint32_t	DSI_PTTCR;
	volatile	uint32_t	DSI_PSR;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	DSI_ISR0;
	volatile	uint32_t	DSI_ISR1;
	volatile	uint32_t	DSI_IER0;
	volatile	uint32_t	DSI_IER1;
	volatile	uint32_t	RESERVED3[3];
	volatile	uint32_t	DSI_FIR0;
	volatile	uint32_t	DSI_FIR1;
	volatile	uint32_t	RESERVED4[8];
	volatile	uint32_t	DSI_VSCR;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	DSI_LCVCIDR;
	volatile	uint32_t	DSI_LCCCR;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	DSI_LPMCCR;
	volatile	uint32_t	RESERVED7[7];
	volatile	uint32_t	DSI_VMCCR;
	volatile	uint32_t	DSI_VPCCR;
	volatile	uint32_t	DSI_VCCCR;
	volatile	uint32_t	DSI_VNPCCR;
	volatile	uint32_t	DSI_VHSACCR;
	volatile	uint32_t	DSI_VHBPCCR;
	volatile	uint32_t	DSI_VLCCR;
	volatile	uint32_t	DSI_VVSACCR;
	volatile	uint32_t	DSI_VVBPCCR;
	volatile	uint32_t	DSI_VVFPCCR;
	volatile	uint32_t	DSI_VVACCR;
	volatile	uint32_t	RESERVED8[167];
	volatile	uint32_t	DSI_WCFGR;
	volatile	uint32_t	DSI_WCR;
	volatile	uint32_t	DSI_WIER;
	volatile	uint32_t	DSI_WISR;
	volatile	uint32_t	DSI_WIFCR;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	DSI_WPCR0;
	volatile	uint32_t	DSI_WPCR1;
	volatile	uint32_t	DSI_WPCR2;
	volatile	uint32_t	DSI_WPCR3;
	volatile	uint32_t	DSI_WPCR4;
	volatile	uint32_t	RESERVED10;
	volatile	uint32_t	DSI_WRPCR;
} DSIHOST_TypeDef;

#if (defined(__cplusplus))
#define	DSIHOST	reinterpret_cast<DSIHOST_TypeDef *>(0x50000000u)

#else
#define	DSIHOST	((DSIHOST_TypeDef *)0x50000000u)
#endif

// DSI_VR Configuration

#define	DSIHOST_DSI_VR_VERSION			(0xFFFFFFFFu<<0)
#define	DSIHOST_DSI_VR_VERSION_0		(0x1u<<0)

// DSI_CR Configuration

#define	DSIHOST_DSI_CR_EN				(0x1u<<0)

// DSI_CCR Configuration

#define	DSIHOST_DSI_CCR_TOCKDIV			(0xFFu<<8)
#define	DSIHOST_DSI_CCR_TOCKDIV_0		(0x1u<<8)
#define	DSIHOST_DSI_CCR_TXECKDIV		(0xFFu<<0)
#define	DSIHOST_DSI_CCR_TXECKDIV_0		(0x1u<<0)

// DSI_LVCIDR Configuration

#define	DSIHOST_DSI_LVCIDR_VCID			(0x3u<<0)
#define	DSIHOST_DSI_LVCIDR_VCID_0		(0x1u<<0)

// DSI_LCOLCR Configuration

#define	DSIHOST_DSI_LCOLCR_LPE			(0x1u<<8)
#define	DSIHOST_DSI_LCOLCR_COLC			(0xFu<<0)
#define	DSIHOST_DSI_LCOLCR_COLC_0		(0x1u<<0)

// DSI_LPCR Configuration

#define	DSIHOST_DSI_LPCR_HSP			(0x1u<<2)
#define	DSIHOST_DSI_LPCR_VSP			(0x1u<<1)
#define	DSIHOST_DSI_LPCR_DEP			(0x1u<<0)

// DSI_LPMCR Configuration

#define	DSIHOST_DSI_LPMCR_LPSIZE		(0xFFu<<16)
#define	DSIHOST_DSI_LPMCR_LPSIZE_0		(0x1u<<16)
#define	DSIHOST_DSI_LPMCR_VLPSIZE		(0xFFu<<0)
#define	DSIHOST_DSI_LPMCR_VLPSIZE_0		(0x1u<<0)

// DSI_PCR Configuration

#define	DSIHOST_DSI_PCR_CRCRXE			(0x1u<<4)
#define	DSIHOST_DSI_PCR_ECCRXE			(0x1u<<3)
#define	DSIHOST_DSI_PCR_BTAE			(0x1u<<2)
#define	DSIHOST_DSI_PCR_ETRXE			(0x1u<<1)
#define	DSIHOST_DSI_PCR_ETTXE			(0x1u<<0)

// DSI_GVCIDR Configuration

#define	DSIHOST_DSI_GVCIDR_VCID			(0x3u<<0)
#define	DSIHOST_DSI_GVCIDR_VCID_0		(0x1u<<0)

// DSI_MCR Configuration

#define	DSIHOST_DSI_MCR_CMDM			(0x1u<<0)

// DSI_VMCR Configuration

#define	DSIHOST_DSI_VMCR_PGO			(0x1u<<24)
#define	DSIHOST_DSI_VMCR_PGM			(0x1u<<20)
#define	DSIHOST_DSI_VMCR_PGE			(0x1u<<16)
#define	DSIHOST_DSI_VMCR_LPCE			(0x1u<<15)
#define	DSIHOST_DSI_VMCR_FBTAAE			(0x1u<<14)
#define	DSIHOST_DSI_VMCR_LPHFPE			(0x1u<<13)
#define	DSIHOST_DSI_VMCR_LPHBPE			(0x1u<<12)
#define	DSIHOST_DSI_VMCR_LPVAE			(0x1u<<11)
#define	DSIHOST_DSI_VMCR_LPVFPE			(0x1u<<10)
#define	DSIHOST_DSI_VMCR_LPVBPE			(0x1u<<9)
#define	DSIHOST_DSI_VMCR_LPVSAE			(0x1u<<8)
#define	DSIHOST_DSI_VMCR_VMT			(0x3u<<0)
#define	DSIHOST_DSI_VMCR_VMT_0			(0x1u<<0)

// DSI_VPCR Configuration

#define	DSIHOST_DSI_VPCR_VPSIZE			(0x3FFFu<<0)
#define	DSIHOST_DSI_VPCR_VPSIZE_0		(0x1u<<0)

// DSI_VCCR Configuration

#define	DSIHOST_DSI_VCCR_NUMC			(0x1FFFu<<0)
#define	DSIHOST_DSI_VCCR_NUMC_0			(0x1u<<0)

// DSI_VNPCR Configuration

#define	DSIHOST_DSI_VNPCR_NPSIZE		(0x1FFFu<<0)
#define	DSIHOST_DSI_VNPCR_NPSIZE_0		(0x1u<<0)

// DSI_VHSACR Configuration

#define	DSIHOST_DSI_VHSACR_HSA			(0xFFFu<<0)
#define	DSIHOST_DSI_VHSACR_HSA_0		(0x1u<<0)

// DSI_VHBPCR Configuration

#define	DSIHOST_DSI_VHBPCR_HBP			(0xFFFu<<0)
#define	DSIHOST_DSI_VHBPCR_HBP_0		(0x1u<<0)

// DSI_VLCR Configuration

#define	DSIHOST_DSI_VLCR_HLINE			(0x7FFFu<<0)
#define	DSIHOST_DSI_VLCR_HLINE_0		(0x1u<<0)

// DSI_VVSACR Configuration

#define	DSIHOST_DSI_VVSACR_VSA			(0x3FFu<<0)
#define	DSIHOST_DSI_VVSACR_VSA_0		(0x1u<<0)

// DSI_VVBPCR Configuration

#define	DSIHOST_DSI_VVBPCR_VBP			(0x3FFu<<0)
#define	DSIHOST_DSI_VVBPCR_VBP_0		(0x1u<<0)

// DSI_VVFPCR Configuration

#define	DSIHOST_DSI_VVFPCR_VFP			(0x3FFu<<0)
#define	DSIHOST_DSI_VVFPCR_VFP_0		(0x1u<<0)

// DSI_VVACR Configuration

#define	DSIHOST_DSI_VVACR_VA			(0x3FFFu<<0)
#define	DSIHOST_DSI_VVACR_VA_0			(0x1u<<0)

// DSI_LCCR Configuration

#define	DSIHOST_DSI_LCCR_CMDSIZE		(0xFFFFu<<0)
#define	DSIHOST_DSI_LCCR_CMDSIZE_0		(0x1u<<0)

// DSI_CMCR Configuration

#define	DSIHOST_DSI_CMCR_MRDPS			(0x1u<<24)
#define	DSIHOST_DSI_CMCR_DLWTX			(0x1u<<19)
#define	DSIHOST_DSI_CMCR_DSR0TX			(0x1u<<18)
#define	DSIHOST_DSI_CMCR_DSW1TX			(0x1u<<17)
#define	DSIHOST_DSI_CMCR_DSW0TX			(0x1u<<16)
#define	DSIHOST_DSI_CMCR_GLWTX			(0x1u<<14)
#define	DSIHOST_DSI_CMCR_GSR2TX			(0x1u<<13)
#define	DSIHOST_DSI_CMCR_GSR1TX			(0x1u<<12)
#define	DSIHOST_DSI_CMCR_GSR0TX			(0x1u<<11)
#define	DSIHOST_DSI_CMCR_GSW2TX			(0x1u<<10)
#define	DSIHOST_DSI_CMCR_GSW1TX			(0x1u<<9)
#define	DSIHOST_DSI_CMCR_GSW0TX			(0x1u<<8)
#define	DSIHOST_DSI_CMCR_ARE			(0x1u<<1)
#define	DSIHOST_DSI_CMCR_TEARE			(0x1u<<0)

// DSI_GHCR Configuration

#define	DSIHOST_DSI_GHCR_WCMSB			(0xFFu<<16)
#define	DSIHOST_DSI_GHCR_WCMSB_0		(0x1u<<16)
#define	DSIHOST_DSI_GHCR_WCLSB			(0xFFu<<8)
#define	DSIHOST_DSI_GHCR_WCLSB_0		(0x1u<<8)
#define	DSIHOST_DSI_GHCR_VCID			(0x3u<<6)
#define	DSIHOST_DSI_GHCR_VCID_0			(0x1u<<6)
#define	DSIHOST_DSI_GHCR_DT				(0x3Fu<<0)
#define	DSIHOST_DSI_GHCR_DT_0			(0x1u<<0)

// DSI_GPDR Configuration

#define	DSIHOST_DSI_GPDR_DATA4			(0xFFu<<24)
#define	DSIHOST_DSI_GPDR_DATA4_0		(0x1u<<24)
#define	DSIHOST_DSI_GPDR_DATA3			(0xFFu<<16)
#define	DSIHOST_DSI_GPDR_DATA3_0		(0x1u<<16)
#define	DSIHOST_DSI_GPDR_DATA2			(0xFFu<<8)
#define	DSIHOST_DSI_GPDR_DATA2_0		(0x1u<<8)
#define	DSIHOST_DSI_GPDR_DATA1			(0xFFu<<0)
#define	DSIHOST_DSI_GPDR_DATA1_0		(0x1u<<0)

// DSI_GPSR Configuration

#define	DSIHOST_DSI_GPSR_RCB			(0x1u<<6)
#define	DSIHOST_DSI_GPSR_PRDFF			(0x1u<<5)
#define	DSIHOST_DSI_GPSR_PRDFE			(0x1u<<4)
#define	DSIHOST_DSI_GPSR_PWRFF			(0x1u<<3)
#define	DSIHOST_DSI_GPSR_PWRFE			(0x1u<<2)
#define	DSIHOST_DSI_GPSR_CMDFF			(0x1u<<1)
#define	DSIHOST_DSI_GPSR_CMDFE			(0x1u<<0)

// DSI_TCCR0 Configuration

#define	DSIHOST_DSI_TCCR0_HSTX_TOCNT	(0xFFFFu<<16)
#define	DSIHOST_DSI_TCCR0_HSTX_TOCNT_0	(0x1u<<16)
#define	DSIHOST_DSI_TCCR0_LPRX_TOCNT	(0xFFFFu<<0)
#define	DSIHOST_DSI_TCCR0_LPRX_TOCNT_0	(0x1u<<0)

// DSI_TCCR1 Configuration

#define	DSIHOST_DSI_TCCR1_HSRD_TOCNT	(0xFFFFu<<0)
#define	DSIHOST_DSI_TCCR1_HSRD_TOCNT_0	(0x1u<<0)

// DSI_TCCR2 Configuration

#define	DSIHOST_DSI_TCCR2_LPRD_TOCNT	(0xFFFFu<<0)
#define	DSIHOST_DSI_TCCR2_LPRD_TOCNT_0	(0x1u<<0)

// DSI_TCCR3 Configuration

#define	DSIHOST_DSI_TCCR3_PM			(0x1u<<24)
#define	DSIHOST_DSI_TCCR3_HSWR_TOCNT	(0xFFFFu<<0)
#define	DSIHOST_DSI_TCCR3_HSWR_TOCNT_0	(0x1u<<0)

// DSI_TCCR4 Configuration

#define	DSIHOST_DSI_TCCR4_LPWR_TOCNT	(0xFFFFu<<0)
#define	DSIHOST_DSI_TCCR4_LPWR_TOCNT_0	(0x1u<<0)

// DSI_TCCR5 Configuration

#define	DSIHOST_DSI_TCCR5_BTA_TOCNT		(0xFFFFu<<0)
#define	DSIHOST_DSI_TCCR5_BTA_TOCNT_0	(0x1u<<0)

// DSI_CLCR Configuration

#define	DSIHOST_DSI_CLCR_ACR			(0x1u<<1)
#define	DSIHOST_DSI_CLCR_DPCC			(0x1u<<0)

// DSI_CLTCR Configuration

#define	DSIHOST_DSI_CLTCR_HS2LP_TIME	(0x3FFu<<16)
#define	DSIHOST_DSI_CLTCR_HS2LP_TIME_0	(0x1u<<16)
#define	DSIHOST_DSI_CLTCR_LP2HS_TIME	(0x3FFu<<0)
#define	DSIHOST_DSI_CLTCR_LP2HS_TIME_0	(0x1u<<0)

// DSI_DLTCR Configuration

#define	DSIHOST_DSI_DLTCR_HS2LP_TIME	(0xFFu<<24)
#define	DSIHOST_DSI_DLTCR_HS2LP_TIME_0	(0x1u<<24)
#define	DSIHOST_DSI_DLTCR_LP2HS_TIME	(0xFFu<<16)
#define	DSIHOST_DSI_DLTCR_LP2HS_TIME_0	(0x1u<<16)
#define	DSIHOST_DSI_DLTCR_MRD_TIME		(0x7FFFu<<0)
#define	DSIHOST_DSI_DLTCR_MRD_TIME_0	(0x1u<<0)

// DSI_PCTLR Configuration

#define	DSIHOST_DSI_PCTLR_CKE			(0x1u<<2)
#define	DSIHOST_DSI_PCTLR_DEN			(0x1u<<1)

// DSI_PCONFR Configuration

#define	DSIHOST_DSI_PCONFR_SW_TIME		(0xFFu<<8)
#define	DSIHOST_DSI_PCONFR_SW_TIME_0	(0x1u<<8)
#define	DSIHOST_DSI_PCONFR_NL			(0x3u<<0)
#define	DSIHOST_DSI_PCONFR_NL_0			(0x1u<<0)

// DSI_PUCR Configuration

#define	DSIHOST_DSI_PUCR_UEDL			(0x1u<<3)
#define	DSIHOST_DSI_PUCR_URDL			(0x1u<<2)
#define	DSIHOST_DSI_PUCR_UECL			(0x1u<<1)
#define	DSIHOST_DSI_PUCR_URCL			(0x1u<<0)

// DSI_PTTCR Configuration

#define	DSIHOST_DSI_PTTCR_TX_TRIG		(0xFu<<0)
#define	DSIHOST_DSI_PTTCR_TX_TRIG_0		(0x1u<<0)

// DSI_PSR Configuration

#define	DSIHOST_DSI_PSR_UAN1			(0x1u<<8)
#define	DSIHOST_DSI_PSR_PSS1			(0x1u<<7)
#define	DSIHOST_DSI_PSR_RUE0			(0x1u<<6)
#define	DSIHOST_DSI_PSR_UAN0			(0x1u<<5)
#define	DSIHOST_DSI_PSR_PSS0			(0x1u<<4)
#define	DSIHOST_DSI_PSR_UANC			(0x1u<<3)
#define	DSIHOST_DSI_PSR_PSSC			(0x1u<<2)
#define	DSIHOST_DSI_PSR_PD				(0x1u<<1)

// DSI_ISR0 Configuration

#define	DSIHOST_DSI_ISR0_PE4			(0x1u<<20)
#define	DSIHOST_DSI_ISR0_PE3			(0x1u<<19)
#define	DSIHOST_DSI_ISR0_PE2			(0x1u<<18)
#define	DSIHOST_DSI_ISR0_PE1			(0x1u<<17)
#define	DSIHOST_DSI_ISR0_PE0			(0x1u<<16)
#define	DSIHOST_DSI_ISR0_AE15			(0x1u<<15)
#define	DSIHOST_DSI_ISR0_AE14			(0x1u<<14)
#define	DSIHOST_DSI_ISR0_AE13			(0x1u<<13)
#define	DSIHOST_DSI_ISR0_AE12			(0x1u<<12)
#define	DSIHOST_DSI_ISR0_AE11			(0x1u<<11)
#define	DSIHOST_DSI_ISR0_AE10			(0x1u<<10)
#define	DSIHOST_DSI_ISR0_AE9			(0x1u<<9)
#define	DSIHOST_DSI_ISR0_AE8			(0x1u<<8)
#define	DSIHOST_DSI_ISR0_AE7			(0x1u<<7)
#define	DSIHOST_DSI_ISR0_AE6			(0x1u<<6)
#define	DSIHOST_DSI_ISR0_AE5			(0x1u<<5)
#define	DSIHOST_DSI_ISR0_AE4			(0x1u<<4)
#define	DSIHOST_DSI_ISR0_AE3			(0x1u<<3)
#define	DSIHOST_DSI_ISR0_AE2			(0x1u<<2)
#define	DSIHOST_DSI_ISR0_AE1			(0x1u<<1)
#define	DSIHOST_DSI_ISR0_AE0			(0x1u<<0)

// DSI_ISR1 Configuration

#define	DSIHOST_DSI_ISR1_GPRXE			(0x1u<<12)
#define	DSIHOST_DSI_ISR1_GPRDE			(0x1u<<11)
#define	DSIHOST_DSI_ISR1_GPTXE			(0x1u<<10)
#define	DSIHOST_DSI_ISR1_GPWRE			(0x1u<<9)
#define	DSIHOST_DSI_ISR1_GCWRE			(0x1u<<8)
#define	DSIHOST_DSI_ISR1_LPWRE			(0x1u<<7)
#define	DSIHOST_DSI_ISR1_EOTPE			(0x1u<<6)
#define	DSIHOST_DSI_ISR1_PSE			(0x1u<<5)
#define	DSIHOST_DSI_ISR1_CRCE			(0x1u<<4)
#define	DSIHOST_DSI_ISR1_ECCME			(0x1u<<3)
#define	DSIHOST_DSI_ISR1_ECCSE			(0x1u<<2)
#define	DSIHOST_DSI_ISR1_TOLPRX			(0x1u<<1)
#define	DSIHOST_DSI_ISR1_TOHSTX			(0x1u<<0)

// DSI_IER0 Configuration

#define	DSIHOST_DSI_IER0_PE4IE			(0x1u<<20)
#define	DSIHOST_DSI_IER0_PE3IE			(0x1u<<19)
#define	DSIHOST_DSI_IER0_PE2IE			(0x1u<<18)
#define	DSIHOST_DSI_IER0_PE1IE			(0x1u<<17)
#define	DSIHOST_DSI_IER0_PE0IE			(0x1u<<16)
#define	DSIHOST_DSI_IER0_AE15IE			(0x1u<<15)
#define	DSIHOST_DSI_IER0_AE14IE			(0x1u<<14)
#define	DSIHOST_DSI_IER0_AE13IE			(0x1u<<13)
#define	DSIHOST_DSI_IER0_AE12IE			(0x1u<<12)
#define	DSIHOST_DSI_IER0_AE11IE			(0x1u<<11)
#define	DSIHOST_DSI_IER0_AE10IE			(0x1u<<10)
#define	DSIHOST_DSI_IER0_AE9IE			(0x1u<<9)
#define	DSIHOST_DSI_IER0_AE8IE			(0x1u<<8)
#define	DSIHOST_DSI_IER0_AE7IE			(0x1u<<7)
#define	DSIHOST_DSI_IER0_AE6IE			(0x1u<<6)
#define	DSIHOST_DSI_IER0_AE5IE			(0x1u<<5)
#define	DSIHOST_DSI_IER0_AE4IE			(0x1u<<4)
#define	DSIHOST_DSI_IER0_AE3IE			(0x1u<<3)
#define	DSIHOST_DSI_IER0_AE2IE			(0x1u<<2)
#define	DSIHOST_DSI_IER0_AE1IE			(0x1u<<1)
#define	DSIHOST_DSI_IER0_AE0IE			(0x1u<<0)

// DSI_IER1 Configuration

#define	DSIHOST_DSI_IER1_GPRXEIE		(0x1u<<12)
#define	DSIHOST_DSI_IER1_GPRDEIE		(0x1u<<11)
#define	DSIHOST_DSI_IER1_GPTXEIE		(0x1u<<10)
#define	DSIHOST_DSI_IER1_GPWREIE		(0x1u<<9)
#define	DSIHOST_DSI_IER1_GCWREIE		(0x1u<<8)
#define	DSIHOST_DSI_IER1_LPWREIE		(0x1u<<7)
#define	DSIHOST_DSI_IER1_EOTPEIE		(0x1u<<6)
#define	DSIHOST_DSI_IER1_PSEIE			(0x1u<<5)
#define	DSIHOST_DSI_IER1_CRCEIE			(0x1u<<4)
#define	DSIHOST_DSI_IER1_ECCMEIE		(0x1u<<3)
#define	DSIHOST_DSI_IER1_ECCSEIE		(0x1u<<2)
#define	DSIHOST_DSI_IER1_TOLPRXIE		(0x1u<<1)
#define	DSIHOST_DSI_IER1_TOHSTXIE		(0x1u<<0)

// DSI_FIR0 Configuration

#define	DSIHOST_DSI_FIR0_FPE4			(0x1u<<20)
#define	DSIHOST_DSI_FIR0_FPE3			(0x1u<<19)
#define	DSIHOST_DSI_FIR0_FPE2			(0x1u<<18)
#define	DSIHOST_DSI_FIR0_FPE1			(0x1u<<17)
#define	DSIHOST_DSI_FIR0_FPE0			(0x1u<<16)
#define	DSIHOST_DSI_FIR0_FAE15			(0x1u<<15)
#define	DSIHOST_DSI_FIR0_FAE14			(0x1u<<14)
#define	DSIHOST_DSI_FIR0_FAE13			(0x1u<<13)
#define	DSIHOST_DSI_FIR0_FAE12			(0x1u<<12)
#define	DSIHOST_DSI_FIR0_FAE11			(0x1u<<11)
#define	DSIHOST_DSI_FIR0_FAE10			(0x1u<<10)
#define	DSIHOST_DSI_FIR0_FAE9			(0x1u<<9)
#define	DSIHOST_DSI_FIR0_FAE8			(0x1u<<8)
#define	DSIHOST_DSI_FIR0_FAE7			(0x1u<<7)
#define	DSIHOST_DSI_FIR0_FAE6			(0x1u<<6)
#define	DSIHOST_DSI_FIR0_FAE5			(0x1u<<5)
#define	DSIHOST_DSI_FIR0_FAE4			(0x1u<<4)
#define	DSIHOST_DSI_FIR0_FAE3			(0x1u<<3)
#define	DSIHOST_DSI_FIR0_FAE2			(0x1u<<2)
#define	DSIHOST_DSI_FIR0_FAE1			(0x1u<<1)
#define	DSIHOST_DSI_FIR0_FAE0			(0x1u<<0)

// DSI_FIR1 Configuration

#define	DSIHOST_DSI_FIR1_FGPRXE			(0x1u<<12)
#define	DSIHOST_DSI_FIR1_FGPRDE			(0x1u<<11)
#define	DSIHOST_DSI_FIR1_FGPTXE			(0x1u<<10)
#define	DSIHOST_DSI_FIR1_FGPWRE			(0x1u<<9)
#define	DSIHOST_DSI_FIR1_FGCWRE			(0x1u<<8)
#define	DSIHOST_DSI_FIR1_FLPWRE			(0x1u<<7)
#define	DSIHOST_DSI_FIR1_FEOTPE			(0x1u<<6)
#define	DSIHOST_DSI_FIR1_FPSE			(0x1u<<5)
#define	DSIHOST_DSI_FIR1_FCRCE			(0x1u<<4)
#define	DSIHOST_DSI_FIR1_FECCME			(0x1u<<3)
#define	DSIHOST_DSI_FIR1_FECCSE			(0x1u<<2)
#define	DSIHOST_DSI_FIR1_FTOLPRX		(0x1u<<1)
#define	DSIHOST_DSI_FIR1_FTOHSTX		(0x1u<<0)

// DSI_VSCR Configuration

#define	DSIHOST_DSI_VSCR_UR				(0x1u<<8)
#define	DSIHOST_DSI_VSCR_EN				(0x1u<<0)

// DSI_LCVCIDR Configuration

#define	DSIHOST_DSI_LCVCIDR_VCID		(0x3u<<0)
#define	DSIHOST_DSI_LCVCIDR_VCID_0		(0x1u<<0)

// DSI_LCCCR Configuration

#define	DSIHOST_DSI_LCCCR_LPE			(0x1u<<8)
#define	DSIHOST_DSI_LCCCR_COLC			(0xFu<<0)
#define	DSIHOST_DSI_LCCCR_COLC_0		(0x1u<<0)

// DSI_LPMCCR Configuration

#define	DSIHOST_DSI_LPMCCR_LPSIZE		(0xFFu<<16)
#define	DSIHOST_DSI_LPMCCR_LPSIZE_0		(0x1u<<16)
#define	DSIHOST_DSI_LPMCCR_VLPSIZE		(0xFFu<<0)
#define	DSIHOST_DSI_LPMCCR_VLPSIZE_0	(0x1u<<0)

// DSI_VMCCR Configuration

#define	DSIHOST_DSI_VMCCR_LPCE			(0x1u<<9)
#define	DSIHOST_DSI_VMCCR_FBTAAE		(0x1u<<8)
#define	DSIHOST_DSI_VMCCR_LPHFE			(0x1u<<7)
#define	DSIHOST_DSI_VMCCR_LPHBPE		(0x1u<<6)
#define	DSIHOST_DSI_VMCCR_LPVAE			(0x1u<<5)
#define	DSIHOST_DSI_VMCCR_LPVFPE		(0x1u<<4)
#define	DSIHOST_DSI_VMCCR_LPVBPE		(0x1u<<3)
#define	DSIHOST_DSI_VMCCR_LPVSAE		(0x1u<<2)
#define	DSIHOST_DSI_VMCCR_VMT			(0x3u<<0)
#define	DSIHOST_DSI_VMCCR_VMT_0			(0x1u<<0)

// DSI_VPCCR Configuration

#define	DSIHOST_DSI_VPCCR_VPSIZE		(0x3FFFu<<0)
#define	DSIHOST_DSI_VPCCR_VPSIZE_0		(0x1u<<0)

// DSI_VCCCR Configuration

#define	DSIHOST_DSI_VCCCR_NUMC			(0x1FFFu<<0)
#define	DSIHOST_DSI_VCCCR_NUMC_0		(0x1u<<0)

// DSI_VNPCCR Configuration

#define	DSIHOST_DSI_VNPCCR_NPSIZE		(0x1FFFu<<0)
#define	DSIHOST_DSI_VNPCCR_NPSIZE_0		(0x1u<<0)

// DSI_VHSACCR Configuration

#define	DSIHOST_DSI_VHSACCR_HSA			(0xFFFu<<0)
#define	DSIHOST_DSI_VHSACCR_HSA_0		(0x1u<<0)

// DSI_VHBPCCR Configuration

#define	DSIHOST_DSI_VHBPCCR_HBP			(0xFFFu<<0)
#define	DSIHOST_DSI_VHBPCCR_HBP_0		(0x1u<<0)

// DSI_VLCCR Configuration

#define	DSIHOST_DSI_VLCCR_HLINE			(0x7FFFu<<0)
#define	DSIHOST_DSI_VLCCR_HLINE_0		(0x1u<<0)

// DSI_VVSACCR Configuration

#define	DSIHOST_DSI_VVSACCR_VSA			(0x3FFu<<0)
#define	DSIHOST_DSI_VVSACCR_VSA_0		(0x1u<<0)

// DSI_VVBPCCR Configuration

#define	DSIHOST_DSI_VVBPCCR_VBP			(0x3FFu<<0)
#define	DSIHOST_DSI_VVBPCCR_VBP_0		(0x1u<<0)

// DSI_VVFPCCR Configuration

#define	DSIHOST_DSI_VVFPCCR_VFP			(0x3FFu<<0)
#define	DSIHOST_DSI_VVFPCCR_VFP_0		(0x1u<<0)

// DSI_VVACCR Configuration

#define	DSIHOST_DSI_VVACCR_VA			(0x3FFFu<<0)
#define	DSIHOST_DSI_VVACCR_VA_0			(0x1u<<0)

// DSI_WCFGR Configuration

#define	DSIHOST_DSI_WCFGR_VSPOL			(0x1u<<7)
#define	DSIHOST_DSI_WCFGR_AR			(0x1u<<6)
#define	DSIHOST_DSI_WCFGR_TEPOL			(0x1u<<5)
#define	DSIHOST_DSI_WCFGR_TESRC			(0x1u<<4)
#define	DSIHOST_DSI_WCFGR_COLMUX		(0x7u<<1)
#define	DSIHOST_DSI_WCFGR_COLMUX_0		(0x1u<<1)
#define	DSIHOST_DSI_WCFGR_DSIM			(0x1u<<0)

// DSI_WCR Configuration

#define	DSIHOST_DSI_WCR_DSIEN			(0x1u<<3)
#define	DSIHOST_DSI_WCR_LTDCEN			(0x1u<<2)
#define	DSIHOST_DSI_WCR_SHTDN			(0x1u<<1)
#define	DSIHOST_DSI_WCR_COLM			(0x1u<<0)

// DSI_WIER Configuration

#define	DSIHOST_DSI_WIER_RRIE			(0x1u<<13)
#define	DSIHOST_DSI_WIER_PLLUIE			(0x1u<<10)
#define	DSIHOST_DSI_WIER_PLLLIE			(0x1u<<9)
#define	DSIHOST_DSI_WIER_ERIE			(0x1u<<1)
#define	DSIHOST_DSI_WIER_TEIE			(0x1u<<0)

// DSI_WISR Configuration

#define	DSIHOST_DSI_WISR_RRIF			(0x1u<<13)
#define	DSIHOST_DSI_WISR_RRS			(0x1u<<12)
#define	DSIHOST_DSI_WISR_PLLUIF			(0x1u<<10)
#define	DSIHOST_DSI_WISR_PLLLIF			(0x1u<<9)
#define	DSIHOST_DSI_WISR_PLLLS			(0x1u<<8)
#define	DSIHOST_DSI_WISR_BUSY			(0x1u<<2)
#define	DSIHOST_DSI_WISR_ERIF			(0x1u<<1)
#define	DSIHOST_DSI_WISR_TEIF			(0x1u<<0)

// DSI_WIFCR Configuration

#define	DSIHOST_DSI_WIFCR_CRRIF			(0x1u<<13)
#define	DSIHOST_DSI_WIFCR_CPLLUIF		(0x1u<<10)
#define	DSIHOST_DSI_WIFCR_CPLLLIF		(0x1u<<9)
#define	DSIHOST_DSI_WIFCR_CERIF			(0x1u<<1)
#define	DSIHOST_DSI_WIFCR_CTEIF			(0x1u<<0)

// DSI_WPCR0 Configuration

#define	DSIHOST_DSI_WPCR0_TCLKPOSTEN	(0x1u<<27)
#define	DSIHOST_DSI_WPCR0_TLPXCEN		(0x1u<<26)
#define	DSIHOST_DSI_WPCR0_THSEXITEN		(0x1u<<25)
#define	DSIHOST_DSI_WPCR0_TLPXDEN		(0x1u<<24)
#define	DSIHOST_DSI_WPCR0_THSZEROEN		(0x1u<<23)
#define	DSIHOST_DSI_WPCR0_THSTRAILEN	(0x1u<<22)
#define	DSIHOST_DSI_WPCR0_THSPREPEN		(0x1u<<21)
#define	DSIHOST_DSI_WPCR0_TCLKZEROEN	(0x1u<<20)
#define	DSIHOST_DSI_WPCR0_TCLKPREPEN	(0x1u<<19)
#define	DSIHOST_DSI_WPCR0_PDEN			(0x1u<<18)
#define	DSIHOST_DSI_WPCR0_TDDL			(0x1u<<16)
#define	DSIHOST_DSI_WPCR0_CDOFFDL		(0x1u<<14)
#define	DSIHOST_DSI_WPCR0_FTXSMDL		(0x1u<<13)
#define	DSIHOST_DSI_WPCR0_FTXSMCL		(0x1u<<12)
#define	DSIHOST_DSI_WPCR0_HSIDL1		(0x1u<<11)
#define	DSIHOST_DSI_WPCR0_HSIDL0		(0x1u<<10)
#define	DSIHOST_DSI_WPCR0_HSICL			(0x1u<<9)
#define	DSIHOST_DSI_WPCR0_SWDL1			(0x1u<<8)
#define	DSIHOST_DSI_WPCR0_SWDL0			(0x1u<<7)
#define	DSIHOST_DSI_WPCR0_SWCL			(0x1u<<6)
#define	DSIHOST_DSI_WPCR0_UIX4			(0x3Fu<<0)
#define	DSIHOST_DSI_WPCR0_UIX4_0		(0x1u<<0)

// DSI_WPCR1 Configuration

#define	DSIHOST_DSI_WPCR1_LPRXFT		(0x3u<<25)
#define	DSIHOST_DSI_WPCR1_LPRXFT_0		(0x1u<<25)
#define	DSIHOST_DSI_WPCR1_FLPRXLPM		(0x1u<<22)
#define	DSIHOST_DSI_WPCR1_HSTXSRCDL		(0x3u<<18)
#define	DSIHOST_DSI_WPCR1_HSTXSRCDL_0	(0x1u<<18)
#define	DSIHOST_DSI_WPCR1_HSTXSRCCL		(0x3u<<16)
#define	DSIHOST_DSI_WPCR1_HSTXSRCCL_0	(0x1u<<16)
#define	DSIHOST_DSI_WPCR1_SDDC			(0x1u<<12)
#define	DSIHOST_DSI_WPCR1_LPSRCDL		(0x3u<<8)
#define	DSIHOST_DSI_WPCR1_LPSRCDL_0		(0x1u<<8)
#define	DSIHOST_DSI_WPCR1_LPSRCCL		(0x3u<<6)
#define	DSIHOST_DSI_WPCR1_LPSRCCL_0		(0x1u<<6)
#define	DSIHOST_DSI_WPCR1_HSTXDDL		(0x3u<<2)
#define	DSIHOST_DSI_WPCR1_HSTXDDL_0		(0x1u<<2)
#define	DSIHOST_DSI_WPCR1_HSTXDCL		(0x3u<<0)
#define	DSIHOST_DSI_WPCR1_HSTXDCL_0		(0x1u<<0)

// DSI_WPCR2 Configuration

#define	DSIHOST_DSI_WPCR2_THSTRAIL		(0xFFu<<24)
#define	DSIHOST_DSI_WPCR2_THSTRAIL_0	(0x1u<<24)
#define	DSIHOST_DSI_WPCR2_THSPREP		(0xFFu<<16)
#define	DSIHOST_DSI_WPCR2_THSPREP_0		(0x1u<<16)
#define	DSIHOST_DSI_WPCR2_TCLKZERO		(0xFFu<<8)
#define	DSIHOST_DSI_WPCR2_TCLKZERO_0	(0x1u<<8)
#define	DSIHOST_DSI_WPCR2_TCLKPREP		(0xFFu<<0)
#define	DSIHOST_DSI_WPCR2_TCLKPREP_0	(0x1u<<0)

// DSI_WPCR3 Configuration

#define	DSIHOST_DSI_WPCR3_TLPXC			(0xFFu<<24)
#define	DSIHOST_DSI_WPCR3_TLPXC_0		(0x1u<<24)
#define	DSIHOST_DSI_WPCR3_THSEXIT		(0xFFu<<16)
#define	DSIHOST_DSI_WPCR3_THSEXIT_0		(0x1u<<16)
#define	DSIHOST_DSI_WPCR3_TLPXD			(0xFFu<<8)
#define	DSIHOST_DSI_WPCR3_TLPXD_0		(0x1u<<8)
#define	DSIHOST_DSI_WPCR3_THSZERO		(0xFFu<<0)
#define	DSIHOST_DSI_WPCR3_THSZERO_0		(0x1u<<0)

// DSI_WPCR4 Configuration

#define	DSIHOST_DSI_WPCR4_TCLKPOST		(0xFFu<<0)
#define	DSIHOST_DSI_WPCR4_TCLKPOST_0	(0x1u<<0)

// DSI_WRPCR Configuration

#define	DSIHOST_DSI_WRPCR_REGEN			(0x1u<<24)
#define	DSIHOST_DSI_WRPCR_ODF			(0x3u<<16)
#define	DSIHOST_DSI_WRPCR_ODF_0			(0x1u<<16)
#define	DSIHOST_DSI_WRPCR_IDF			(0xFu<<11)
#define	DSIHOST_DSI_WRPCR_IDF_0			(0x1u<<11)
#define	DSIHOST_DSI_WRPCR_NDIV			(0x7Fu<<2)
#define	DSIHOST_DSI_WRPCR_NDIV_0		(0x1u<<2)
#define	DSIHOST_DSI_WRPCR_PLLEN			(0x1u<<0)
