/*
; stm32U5Gx_dsi.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_dsi equates.
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

// DSI address definitions
// -----------------------

#if (!defined(ADDITIONAL_DSI_S))
typedef struct {
	volatile	uint32_t	VR;
	volatile	uint32_t	CR;
	volatile	uint32_t	CCR;
	volatile	uint32_t	LVCIDR;
	volatile	uint32_t	LCOLCR;
	volatile	uint32_t	LPCR;
	volatile	uint32_t	LPMCR;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	PCR;
	volatile	uint32_t	GVCIDR;
	volatile	uint32_t	MCR;
	volatile	uint32_t	VMCR;
	volatile	uint32_t	VPCR;
	volatile	uint32_t	VCCR;
	volatile	uint32_t	VNPCR;
	volatile	uint32_t	VHSACR;
	volatile	uint32_t	VHBPCR;
	volatile	uint32_t	VLCR;
	volatile	uint32_t	VVSACR;
	volatile	uint32_t	VVBPCR;
	volatile	uint32_t	VVFPCR;
	volatile	uint32_t	VVACR;
	volatile	uint32_t	LCCR;
	volatile	uint32_t	CMCR;
	volatile	uint32_t	GHCR;
	volatile	uint32_t	GPDR;
	volatile	uint32_t	GPSR;
	volatile	uint32_t	TCCR0;
	volatile	uint32_t	TCCR1;
	volatile	uint32_t	TCCR2;
	volatile	uint32_t	TCCR3;
	volatile	uint32_t	TCCR4;
	volatile	uint32_t	TCCR5;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	CLCR;
	volatile	uint32_t	CLTCR;
	volatile	uint32_t	DLTCR;
	volatile	uint32_t	PCTLR;
	volatile	uint32_t	PCONFR;
	volatile	uint32_t	PUCR;
	volatile	uint32_t	PTTCR;
	volatile	uint32_t	PSR;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	ISR0;
	volatile	uint32_t	ISR1;
	volatile	uint32_t	IER0;
	volatile	uint32_t	IER1;
	volatile	uint32_t	RESERVED3[3];
	volatile	uint32_t	FIR0;
	volatile	uint32_t	FIR1;
	volatile	uint32_t	RESERVED4[5];
	volatile	uint32_t	DLTRCR;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	VSCR;
	volatile	uint32_t	RESERVED6[2];
	volatile	uint32_t	LCVCIDR;
	volatile	uint32_t	LCCCR;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	LPMCCR;
	volatile	uint32_t	RESERVED8[7];
	volatile	uint32_t	VMCCR;
	volatile	uint32_t	VPCCR;
	volatile	uint32_t	VCCCR;
	volatile	uint32_t	VNPCCR;
	volatile	uint32_t	VHSACCR;
	volatile	uint32_t	VHBPCCR;
	volatile	uint32_t	VLCCR;
	volatile	uint32_t	VVSACCR;
	volatile	uint32_t	VVBPCCR;
	volatile	uint32_t	VVFPCCR;
	volatile	uint32_t	VVACCR;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	FBSR;
	volatile	uint32_t	RESERVED10[165];
	volatile	uint32_t	WCFGR;
	volatile	uint32_t	WCR;
	volatile	uint32_t	WIER;
	volatile	uint32_t	WISR;
	volatile	uint32_t	WIFCR;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	WPCR0;
	volatile	uint32_t	RESERVED12[5];
	volatile	uint32_t	WRPCR;
	volatile	uint32_t	RESERVED13[245];
	volatile	uint32_t	BCFGR;
	volatile	uint32_t	RESERVED14[254];
	volatile	uint32_t	DPCBCR;
	volatile	uint32_t	RESERVED15[11];
	volatile	uint32_t	DPCSRCR;
	volatile	uint32_t	RESERVED16[14];
	volatile	uint32_t	DPDL0BCR;
	volatile	uint32_t	RESERVED17[11];
	volatile	uint32_t	DPDL0SRCR;
	volatile	uint32_t	RESERVED18[25];
	volatile	uint32_t	DPDL1BCR;
	volatile	uint32_t	RESERVED19[11];
	volatile	uint32_t	DPDL1SRCR;
} DSI_TypeDef;

#if (defined(__cplusplus))
#define	DSI_NS	reinterpret_cast<DSI_TypeDef *>(0x40016C00u)
#define	DSI_S	reinterpret_cast<DSI_TypeDef *>(0x50016C00u)

#else
#define	DSI_NS	((DSI_TypeDef *)0x40016C00u)
#define	DSI_S	((DSI_TypeDef *)0x50016C00u)
#endif
#endif

// VR Configuration

#define	DSI_VR_VERSION				(0xFFFFFFFFu<<0)
#define	DSI_VR_VERSION_0			(0x1u<<0)

// CR Configuration

#define	DSI_CR_EN					(0x1u<<0)
#define	DSI_CR_EN_B_0X0				(0x0u<<0)
#define	DSI_CR_EN_B_0X1				(0x1u<<0)

// CCR Configuration

#define	DSI_CCR_TOCKDIV				(0xFFu<<8)
#define	DSI_CCR_TOCKDIV_0			(0x1u<<8)
#define	DSI_CCR_TXECKDIV			(0xFFu<<0)
#define	DSI_CCR_TXECKDIV_0			(0x1u<<0)

// LVCIDR Configuration

#define	DSI_LVCIDR_VCID				(0x3u<<0)
#define	DSI_LVCIDR_VCID_0			(0x1u<<0)

// LCOLCR Configuration

#define	DSI_LCOLCR_LPE				(0x1u<<8)
#define	DSI_LCOLCR_COLC				(0xFu<<0)
#define	DSI_LCOLCR_COLC_0			(0x1u<<0)
#define	DSI_LCOLCR_LPE_B_0X0		(0x0u<<8)
#define	DSI_LCOLCR_LPE_B_0X1		(0x1u<<8)
#define	DSI_LCOLCR_COLC_B_0X0		(0x0u<<0)
#define	DSI_LCOLCR_COLC_B_0X1		(0x1u<<0)
#define	DSI_LCOLCR_COLC_B_0X2		(0x2u<<0)
#define	DSI_LCOLCR_COLC_B_0X3		(0x3u<<0)
#define	DSI_LCOLCR_COLC_B_0X4		(0x4u<<0)
#define	DSI_LCOLCR_COLC_B_0X5		(0x5u<<0)

// LPCR Configuration

#define	DSI_LPCR_HSP				(0x1u<<2)
#define	DSI_LPCR_VSP				(0x1u<<1)
#define	DSI_LPCR_DEP				(0x1u<<0)
#define	DSI_LPCR_HSP_B_0X0			(0x0u<<2)
#define	DSI_LPCR_HSP_B_0X1			(0x1u<<2)
#define	DSI_LPCR_VSP_B_0X0			(0x0u<<1)
#define	DSI_LPCR_VSP_B_0X1			(0x1u<<1)
#define	DSI_LPCR_DEP_B_0X0			(0x0u<<0)
#define	DSI_LPCR_DEP_B_0X1			(0x1u<<0)

// LPMCR Configuration

#define	DSI_LPMCR_LPSIZE			(0xFFu<<16)
#define	DSI_LPMCR_LPSIZE_0			(0x1u<<16)
#define	DSI_LPMCR_VLPSIZE			(0xFFu<<0)
#define	DSI_LPMCR_VLPSIZE_0			(0x1u<<0)

// PCR Configuration

#define	DSI_PCR_ETTXLPE				(0x1u<<5)
#define	DSI_PCR_CRCRXE				(0x1u<<4)
#define	DSI_PCR_ECCRXE				(0x1u<<3)
#define	DSI_PCR_BTAE				(0x1u<<2)
#define	DSI_PCR_ETRXE				(0x1u<<1)
#define	DSI_PCR_ETTXE				(0x1u<<0)
#define	DSI_PCR_ETTXLPE_B_0X0		(0x0u<<5)
#define	DSI_PCR_ETTXLPE_B_0X1		(0x1u<<5)
#define	DSI_PCR_CRCRXE_B_0X0		(0x0u<<4)
#define	DSI_PCR_CRCRXE_B_0X1		(0x1u<<4)
#define	DSI_PCR_ECCRXE_B_0X0		(0x0u<<3)
#define	DSI_PCR_ECCRXE_B_0X1		(0x1u<<3)
#define	DSI_PCR_BTAE_B_0X0			(0x0u<<2)
#define	DSI_PCR_BTAE_B_0X1			(0x1u<<2)
#define	DSI_PCR_ETRXE_B_0X0			(0x0u<<1)
#define	DSI_PCR_ETRXE_B_0X1			(0x1u<<1)
#define	DSI_PCR_ETTXE_B_0X0			(0x0u<<0)
#define	DSI_PCR_ETTXE_B_0X1			(0x1u<<0)

// GVCIDR Configuration

#define	DSI_GVCIDR_VCIDTX			(0x3u<<16)
#define	DSI_GVCIDR_VCIDTX_0			(0x1u<<16)
#define	DSI_GVCIDR_VCIDRX			(0x3u<<0)
#define	DSI_GVCIDR_VCIDRX_0			(0x1u<<0)

// MCR Configuration

#define	DSI_MCR_CMDM				(0x1u<<0)
#define	DSI_MCR_CMDM_B_0X0			(0x0u<<0)
#define	DSI_MCR_CMDM_B_0X1			(0x1u<<0)

// VMCR Configuration

#define	DSI_VMCR_PGO				(0x1u<<24)
#define	DSI_VMCR_PGM				(0x1u<<20)
#define	DSI_VMCR_PGE				(0x1u<<16)
#define	DSI_VMCR_LPCE				(0x1u<<15)
#define	DSI_VMCR_FBTAAE				(0x1u<<14)
#define	DSI_VMCR_LPHFPE				(0x1u<<13)
#define	DSI_VMCR_LPHBPE				(0x1u<<12)
#define	DSI_VMCR_LPVAE				(0x1u<<11)
#define	DSI_VMCR_LPVFPE				(0x1u<<10)
#define	DSI_VMCR_LPVBPE				(0x1u<<9)
#define	DSI_VMCR_LPVSAE				(0x1u<<8)
#define	DSI_VMCR_VMT				(0x3u<<0)
#define	DSI_VMCR_VMT_0				(0x1u<<0)
#define	DSI_VMCR_PGO_B_0X0			(0x0u<<24)
#define	DSI_VMCR_PGO_B_0X1			(0x1u<<24)
#define	DSI_VMCR_PGM_B_0X0			(0x0u<<20)
#define	DSI_VMCR_PGM_B_0X1			(0x1u<<20)
#define	DSI_VMCR_PGE_B_0X0			(0x0u<<16)
#define	DSI_VMCR_PGE_B_0X1			(0x1u<<16)
#define	DSI_VMCR_LPCE_B_0X0			(0x0u<<15)
#define	DSI_VMCR_LPCE_B_0X1			(0x1u<<15)
#define	DSI_VMCR_FBTAAE_B_0X0		(0x0u<<14)
#define	DSI_VMCR_FBTAAE_B_0X1		(0x1u<<14)
#define	DSI_VMCR_LPHFPE_B_0X0		(0x0u<<13)
#define	DSI_VMCR_LPHFPE_B_0X1		(0x1u<<13)
#define	DSI_VMCR_LPHBPE_B_0X0		(0x0u<<12)
#define	DSI_VMCR_LPHBPE_B_0X1		(0x1u<<12)
#define	DSI_VMCR_LPVAE_B_0X0		(0x0u<<11)
#define	DSI_VMCR_LPVAE_B_0X1		(0x1u<<11)
#define	DSI_VMCR_LPVFPE_B_0X0		(0x0u<<10)
#define	DSI_VMCR_LPVFPE_B_0X1		(0x1u<<10)
#define	DSI_VMCR_LPVBPE_B_0X0		(0x0u<<9)
#define	DSI_VMCR_LPVBPE_B_0X1		(0x1u<<9)
#define	DSI_VMCR_LPVSAE_B_0X0		(0x0u<<8)
#define	DSI_VMCR_LPVSAE_B_0X1		(0x1u<<8)
#define	DSI_VMCR_VMT_B_0X0			(0x0u<<0)
#define	DSI_VMCR_VMT_B_0X1			(0x1u<<0)

// VPCR Configuration

#define	DSI_VPCR_VPSIZE				(0x3FFFu<<0)
#define	DSI_VPCR_VPSIZE_0			(0x1u<<0)

// VCCR Configuration

#define	DSI_VCCR_NUMC				(0x1FFFu<<0)
#define	DSI_VCCR_NUMC_0				(0x1u<<0)

// VNPCR Configuration

#define	DSI_VNPCR_NPSIZE			(0x1FFFu<<0)
#define	DSI_VNPCR_NPSIZE_0			(0x1u<<0)

// VHSACR Configuration

#define	DSI_VHSACR_HSA				(0xFFFu<<0)
#define	DSI_VHSACR_HSA_0			(0x1u<<0)

// VHBPCR Configuration

#define	DSI_VHBPCR_HBP				(0xFFFu<<0)
#define	DSI_VHBPCR_HBP_0			(0x1u<<0)

// VLCR Configuration

#define	DSI_VLCR_HLINE				(0x7FFFu<<0)
#define	DSI_VLCR_HLINE_0			(0x1u<<0)

// VVSACR Configuration

#define	DSI_VVSACR_VSA				(0x3FFu<<0)
#define	DSI_VVSACR_VSA_0			(0x1u<<0)

// VVBPCR Configuration

#define	DSI_VVBPCR_VBP				(0x3FFu<<0)
#define	DSI_VVBPCR_VBP_0			(0x1u<<0)

// VVFPCR Configuration

#define	DSI_VVFPCR_VFP				(0x3FFu<<0)
#define	DSI_VVFPCR_VFP_0			(0x1u<<0)

// VVACR Configuration

#define	DSI_VVACR_VA				(0x3FFFu<<0)
#define	DSI_VVACR_VA_0				(0x1u<<0)

// LCCR Configuration

#define	DSI_LCCR_CMDSIZE			(0xFFFFu<<0)
#define	DSI_LCCR_CMDSIZE_0			(0x1u<<0)

// CMCR Configuration

#define	DSI_CMCR_MRDPS				(0x1u<<24)
#define	DSI_CMCR_DLWTX				(0x1u<<19)
#define	DSI_CMCR_DSR0TX				(0x1u<<18)
#define	DSI_CMCR_DSW1TX				(0x1u<<17)
#define	DSI_CMCR_DSW0TX				(0x1u<<16)
#define	DSI_CMCR_GLWTX				(0x1u<<14)
#define	DSI_CMCR_GSR2TX				(0x1u<<13)
#define	DSI_CMCR_GSR1TX				(0x1u<<12)
#define	DSI_CMCR_GSR0TX				(0x1u<<11)
#define	DSI_CMCR_GSW2TX				(0x1u<<10)
#define	DSI_CMCR_GSW1TX				(0x1u<<9)
#define	DSI_CMCR_GSW0TX				(0x1u<<8)
#define	DSI_CMCR_ARE				(0x1u<<1)
#define	DSI_CMCR_TEARE				(0x1u<<0)
#define	DSI_CMCR_MRDPS_B_0X0		(0x0u<<24)
#define	DSI_CMCR_MRDPS_B_0X1		(0x1u<<24)
#define	DSI_CMCR_DLWTX_B_0X0		(0x0u<<19)
#define	DSI_CMCR_DLWTX_B_0X1		(0x1u<<19)
#define	DSI_CMCR_DSR0TX_B_0X0		(0x0u<<18)
#define	DSI_CMCR_DSR0TX_B_0X1		(0x1u<<18)
#define	DSI_CMCR_DSW1TX_B_0X0		(0x0u<<17)
#define	DSI_CMCR_DSW1TX_B_0X1		(0x1u<<17)
#define	DSI_CMCR_DSW0TX_B_0X0		(0x0u<<16)
#define	DSI_CMCR_DSW0TX_B_0X1		(0x1u<<16)
#define	DSI_CMCR_GLWTX_B_0X0		(0x0u<<14)
#define	DSI_CMCR_GLWTX_B_0X1		(0x1u<<14)
#define	DSI_CMCR_GSR2TX_B_0X0		(0x0u<<13)
#define	DSI_CMCR_GSR2TX_B_0X1		(0x1u<<13)
#define	DSI_CMCR_GSR1TX_B_0X0		(0x0u<<12)
#define	DSI_CMCR_GSR1TX_B_0X1		(0x1u<<12)
#define	DSI_CMCR_GSR0TX_B_0X0		(0x0u<<11)
#define	DSI_CMCR_GSR0TX_B_0X1		(0x1u<<11)
#define	DSI_CMCR_GSW2TX_B_0X0		(0x0u<<10)
#define	DSI_CMCR_GSW2TX_B_0X1		(0x1u<<10)
#define	DSI_CMCR_GSW1TX_B_0X0		(0x0u<<9)
#define	DSI_CMCR_GSW1TX_B_0X1		(0x1u<<9)
#define	DSI_CMCR_GSW0TX_B_0X0		(0x0u<<8)
#define	DSI_CMCR_GSW0TX_B_0X1		(0x1u<<8)
#define	DSI_CMCR_ARE_B_0X0			(0x0u<<1)
#define	DSI_CMCR_ARE_B_0X1			(0x1u<<1)
#define	DSI_CMCR_TEARE_B_0X0		(0x0u<<0)
#define	DSI_CMCR_TEARE_B_0X1		(0x1u<<0)

// GHCR Configuration

#define	DSI_GHCR_WCMSB				(0xFFu<<16)
#define	DSI_GHCR_WCMSB_0			(0x1u<<16)
#define	DSI_GHCR_WCLSB				(0xFFu<<8)
#define	DSI_GHCR_WCLSB_0			(0x1u<<8)
#define	DSI_GHCR_VCID				(0x3u<<6)
#define	DSI_GHCR_VCID_0				(0x1u<<6)
#define	DSI_GHCR_DT					(0x3Fu<<0)
#define	DSI_GHCR_DT_0				(0x1u<<0)

// GPDR Configuration

#define	DSI_GPDR_DATA4				(0xFFu<<24)
#define	DSI_GPDR_DATA4_0			(0x1u<<24)
#define	DSI_GPDR_DATA3				(0xFFu<<16)
#define	DSI_GPDR_DATA3_0			(0x1u<<16)
#define	DSI_GPDR_DATA2				(0xFFu<<8)
#define	DSI_GPDR_DATA2_0			(0x1u<<8)
#define	DSI_GPDR_DATA1				(0xFFu<<0)
#define	DSI_GPDR_DATA1_0			(0x1u<<0)

// GPSR Configuration

#define	DSI_GPSR_PBF				(0x1u<<19)
#define	DSI_GPSR_PBE				(0x1u<<18)
#define	DSI_GPSR_CMDBF				(0x1u<<17)
#define	DSI_GPSR_CMDBE				(0x1u<<16)
#define	DSI_GPSR_RCB				(0x1u<<6)
#define	DSI_GPSR_PRDFF				(0x1u<<5)
#define	DSI_GPSR_PRDFE				(0x1u<<4)
#define	DSI_GPSR_PWRFF				(0x1u<<3)
#define	DSI_GPSR_PWRFE				(0x1u<<2)
#define	DSI_GPSR_CMDFF				(0x1u<<1)
#define	DSI_GPSR_CMDFE				(0x1u<<0)
#define	DSI_GPSR_PBF_B_0X0			(0x0u<<19)
#define	DSI_GPSR_PBF_B_0X1			(0x1u<<19)
#define	DSI_GPSR_PBE_B_0X0			(0x0u<<18)
#define	DSI_GPSR_PBE_B_0X1			(0x1u<<18)
#define	DSI_GPSR_CMDBF_B_0X0		(0x0u<<17)
#define	DSI_GPSR_CMDBF_B_0X1		(0x1u<<17)
#define	DSI_GPSR_CMDBE_B_0X0		(0x0u<<16)
#define	DSI_GPSR_CMDBE_B_0X1		(0x1u<<16)
#define	DSI_GPSR_RCB_B_0X0			(0x0u<<6)
#define	DSI_GPSR_RCB_B_0X1			(0x1u<<6)
#define	DSI_GPSR_PRDFF_B_0X0		(0x0u<<5)
#define	DSI_GPSR_PRDFF_B_0X1		(0x1u<<5)
#define	DSI_GPSR_PRDFE_B_0X0		(0x0u<<4)
#define	DSI_GPSR_PRDFE_B_0X1		(0x1u<<4)
#define	DSI_GPSR_PWRFF_B_0X0		(0x0u<<3)
#define	DSI_GPSR_PWRFF_B_0X1		(0x1u<<3)
#define	DSI_GPSR_PWRFE_B_0X0		(0x0u<<2)
#define	DSI_GPSR_PWRFE_B_0X1		(0x1u<<2)
#define	DSI_GPSR_CMDFF_B_0X0		(0x0u<<1)
#define	DSI_GPSR_CMDFF_B_0X1		(0x1u<<1)
#define	DSI_GPSR_CMDFE_B_0X0		(0x0u<<0)
#define	DSI_GPSR_CMDFE_B_0X1		(0x1u<<0)

// TCCR0 Configuration

#define	DSI_TCCR0_HSTX_TOCNT		(0xFFFFu<<16)
#define	DSI_TCCR0_HSTX_TOCNT_0		(0x1u<<16)
#define	DSI_TCCR0_LPRX_TOCNT		(0xFFFFu<<0)
#define	DSI_TCCR0_LPRX_TOCNT_0		(0x1u<<0)

// TCCR1 Configuration

#define	DSI_TCCR1_HSRD_TOCNT		(0xFFFFu<<0)
#define	DSI_TCCR1_HSRD_TOCNT_0		(0x1u<<0)

// TCCR2 Configuration

#define	DSI_TCCR2_LPRD_TOCNT		(0xFFFFu<<0)
#define	DSI_TCCR2_LPRD_TOCNT_0		(0x1u<<0)

// TCCR3 Configuration

#define	DSI_TCCR3_PM				(0x1u<<24)
#define	DSI_TCCR3_HSWR_TOCNT		(0xFFFFu<<0)
#define	DSI_TCCR3_HSWR_TOCNT_0		(0x1u<<0)

// TCCR4 Configuration

#define	DSI_TCCR4_LPWR_TOCNT		(0xFFFFu<<0)
#define	DSI_TCCR4_LPWR_TOCNT_0		(0x1u<<0)

// TCCR5 Configuration

#define	DSI_TCCR5_BTA_TOCNT			(0xFFFFu<<0)
#define	DSI_TCCR5_BTA_TOCNT_0		(0x1u<<0)

// CLCR Configuration

#define	DSI_CLCR_ACR				(0x1u<<1)
#define	DSI_CLCR_DPCC				(0x1u<<0)
#define	DSI_CLCR_ACR_B_0X0			(0x0u<<1)
#define	DSI_CLCR_ACR_B_0X1			(0x1u<<1)
#define	DSI_CLCR_DPCC_B_0X0			(0x0u<<0)
#define	DSI_CLCR_DPCC_B_0X1			(0x1u<<0)

// CLTCR Configuration

#define	DSI_CLTCR_HS2LP_TIME		(0x3FFu<<16)
#define	DSI_CLTCR_HS2LP_TIME_0		(0x1u<<16)
#define	DSI_CLTCR_LP2HS_TIME		(0x3FFu<<0)
#define	DSI_CLTCR_LP2HS_TIME_0		(0x1u<<0)

// DLTCR Configuration

#define	DSI_DLTCR_HS2LP_TIME		(0x3FFu<<16)
#define	DSI_DLTCR_HS2LP_TIME_0		(0x1u<<16)
#define	DSI_DLTCR_LP2HS_TIME		(0x3FFu<<0)
#define	DSI_DLTCR_LP2HS_TIME_0		(0x1u<<0)

// PCTLR Configuration

#define	DSI_PCTLR_CKE				(0x1u<<2)
#define	DSI_PCTLR_DEN				(0x1u<<1)
#define	DSI_PCTLR_CKE_B_0X0			(0x0u<<2)
#define	DSI_PCTLR_CKE_B_0X1			(0x1u<<2)
#define	DSI_PCTLR_DEN_B_0X0			(0x0u<<1)
#define	DSI_PCTLR_DEN_B_0X1			(0x1u<<1)

// PCONFR Configuration

#define	DSI_PCONFR_SW_TIME			(0xFFu<<8)
#define	DSI_PCONFR_SW_TIME_0		(0x1u<<8)
#define	DSI_PCONFR_NL				(0x3u<<0)
#define	DSI_PCONFR_NL_0				(0x1u<<0)
#define	DSI_PCONFR_NL_B_0X0			(0x0u<<0)
#define	DSI_PCONFR_NL_B_0X1			(0x1u<<0)

// PUCR Configuration

#define	DSI_PUCR_UEDL				(0x1u<<3)
#define	DSI_PUCR_URDL				(0x1u<<2)
#define	DSI_PUCR_UECL				(0x1u<<1)
#define	DSI_PUCR_URCL				(0x1u<<0)
#define	DSI_PUCR_UEDL_B_0X0			(0x0u<<3)
#define	DSI_PUCR_UEDL_B_0X1			(0x1u<<3)
#define	DSI_PUCR_URDL_B_0X0			(0x0u<<2)
#define	DSI_PUCR_URDL_B_0X1			(0x1u<<2)
#define	DSI_PUCR_UECL_B_0X0			(0x0u<<1)
#define	DSI_PUCR_UECL_B_0X1			(0x1u<<1)
#define	DSI_PUCR_URCL_B_0X0			(0x0u<<0)
#define	DSI_PUCR_URCL_B_0X1			(0x1u<<0)

// PTTCR Configuration

#define	DSI_PTTCR_TX_TRIG			(0xFu<<0)
#define	DSI_PTTCR_TX_TRIG_0			(0x1u<<0)

// PSR Configuration

#define	DSI_PSR_UAN1				(0x1u<<8)
#define	DSI_PSR_PSS1				(0x1u<<7)
#define	DSI_PSR_RUE0				(0x1u<<6)
#define	DSI_PSR_UAN0				(0x1u<<5)
#define	DSI_PSR_PSS0				(0x1u<<4)
#define	DSI_PSR_UANC				(0x1u<<3)
#define	DSI_PSR_PSSC				(0x1u<<2)
#define	DSI_PSR_PD					(0x1u<<1)

// ISR0 Configuration

#define	DSI_ISR0_PE4				(0x1u<<20)
#define	DSI_ISR0_PE3				(0x1u<<19)
#define	DSI_ISR0_PE2				(0x1u<<18)
#define	DSI_ISR0_PE1				(0x1u<<17)
#define	DSI_ISR0_PE0				(0x1u<<16)
#define	DSI_ISR0_AE15				(0x1u<<15)
#define	DSI_ISR0_AE14				(0x1u<<14)
#define	DSI_ISR0_AE13				(0x1u<<13)
#define	DSI_ISR0_AE12				(0x1u<<12)
#define	DSI_ISR0_AE11				(0x1u<<11)
#define	DSI_ISR0_AE10				(0x1u<<10)
#define	DSI_ISR0_AE9				(0x1u<<9)
#define	DSI_ISR0_AE8				(0x1u<<8)
#define	DSI_ISR0_AE7				(0x1u<<7)
#define	DSI_ISR0_AE6				(0x1u<<6)
#define	DSI_ISR0_AE5				(0x1u<<5)
#define	DSI_ISR0_AE4				(0x1u<<4)
#define	DSI_ISR0_AE3				(0x1u<<3)
#define	DSI_ISR0_AE2				(0x1u<<2)
#define	DSI_ISR0_AE1				(0x1u<<1)
#define	DSI_ISR0_AE0				(0x1u<<0)

// ISR1 Configuration

#define	DSI_ISR1_PBUE				(0x1u<<19)
#define	DSI_ISR1_GPRXE				(0x1u<<12)
#define	DSI_ISR1_GPRDE				(0x1u<<11)
#define	DSI_ISR1_GPTXE				(0x1u<<10)
#define	DSI_ISR1_GPWRE				(0x1u<<9)
#define	DSI_ISR1_GCWRE				(0x1u<<8)
#define	DSI_ISR1_LPWRE				(0x1u<<7)
#define	DSI_ISR1_EOTPE				(0x1u<<6)
#define	DSI_ISR1_PSE				(0x1u<<5)
#define	DSI_ISR1_CRCE				(0x1u<<4)
#define	DSI_ISR1_ECCME				(0x1u<<3)
#define	DSI_ISR1_ECCSE				(0x1u<<2)
#define	DSI_ISR1_TOLPRX				(0x1u<<1)
#define	DSI_ISR1_TOHSTX				(0x1u<<0)

// IER0 Configuration

#define	DSI_IER0_PE4IE				(0x1u<<20)
#define	DSI_IER0_PE3IE				(0x1u<<19)
#define	DSI_IER0_PE2IE				(0x1u<<18)
#define	DSI_IER0_PE1IE				(0x1u<<17)
#define	DSI_IER0_PE0IE				(0x1u<<16)
#define	DSI_IER0_AE15IE				(0x1u<<15)
#define	DSI_IER0_AE14IE				(0x1u<<14)
#define	DSI_IER0_AE13IE				(0x1u<<13)
#define	DSI_IER0_AE12IE				(0x1u<<12)
#define	DSI_IER0_AE11IE				(0x1u<<11)
#define	DSI_IER0_AE10IE				(0x1u<<10)
#define	DSI_IER0_AE9IE				(0x1u<<9)
#define	DSI_IER0_AE8IE				(0x1u<<8)
#define	DSI_IER0_AE7IE				(0x1u<<7)
#define	DSI_IER0_AE6IE				(0x1u<<6)
#define	DSI_IER0_AE5IE				(0x1u<<5)
#define	DSI_IER0_AE4IE				(0x1u<<4)
#define	DSI_IER0_AE3IE				(0x1u<<3)
#define	DSI_IER0_AE2IE				(0x1u<<2)
#define	DSI_IER0_AE1IE				(0x1u<<1)
#define	DSI_IER0_AE0IE				(0x1u<<0)
#define	DSI_IER0_PE4IE_B_0X0		(0x0u<<20)
#define	DSI_IER0_PE4IE_B_0X1		(0x1u<<20)
#define	DSI_IER0_PE3IE_B_0X0		(0x0u<<19)
#define	DSI_IER0_PE3IE_B_0X1		(0x1u<<19)
#define	DSI_IER0_PE2IE_B_0X0		(0x0u<<18)
#define	DSI_IER0_PE2IE_B_0X1		(0x1u<<18)
#define	DSI_IER0_PE1IE_B_0X0		(0x0u<<17)
#define	DSI_IER0_PE1IE_B_0X1		(0x1u<<17)
#define	DSI_IER0_PE0IE_B_0X0		(0x0u<<16)
#define	DSI_IER0_PE0IE_B_0X1		(0x1u<<16)
#define	DSI_IER0_AE15IE_B_0X0		(0x0u<<15)
#define	DSI_IER0_AE15IE_B_0X1		(0x1u<<15)
#define	DSI_IER0_AE14IE_B_0X0		(0x0u<<14)
#define	DSI_IER0_AE14IE_B_0X1		(0x1u<<14)
#define	DSI_IER0_AE13IE_B_0X0		(0x0u<<13)
#define	DSI_IER0_AE13IE_B_0X1		(0x1u<<13)
#define	DSI_IER0_AE12IE_B_0X0		(0x0u<<12)
#define	DSI_IER0_AE12IE_B_0X1		(0x1u<<12)
#define	DSI_IER0_AE11IE_B_0X0		(0x0u<<11)
#define	DSI_IER0_AE11IE_B_0X1		(0x1u<<11)
#define	DSI_IER0_AE10IE_B_0X0		(0x0u<<10)
#define	DSI_IER0_AE10IE_B_0X1		(0x1u<<10)
#define	DSI_IER0_AE9IE_B_0X0		(0x0u<<9)
#define	DSI_IER0_AE9IE_B_0X1		(0x1u<<9)
#define	DSI_IER0_AE8IE_B_0X0		(0x0u<<8)
#define	DSI_IER0_AE8IE_B_0X1		(0x1u<<8)
#define	DSI_IER0_AE7IE_B_0X0		(0x0u<<7)
#define	DSI_IER0_AE7IE_B_0X1		(0x1u<<7)
#define	DSI_IER0_AE6IE_B_0X0		(0x0u<<6)
#define	DSI_IER0_AE6IE_B_0X1		(0x1u<<6)
#define	DSI_IER0_AE5IE_B_0X0		(0x0u<<5)
#define	DSI_IER0_AE5IE_B_0X1		(0x1u<<5)
#define	DSI_IER0_AE4IE_B_0X0		(0x0u<<4)
#define	DSI_IER0_AE4IE_B_0X1		(0x1u<<4)
#define	DSI_IER0_AE3IE_B_0X0		(0x0u<<3)
#define	DSI_IER0_AE3IE_B_0X1		(0x1u<<3)
#define	DSI_IER0_AE2IE_B_0X0		(0x0u<<2)
#define	DSI_IER0_AE2IE_B_0X1		(0x1u<<2)
#define	DSI_IER0_AE1IE_B_0X0		(0x0u<<1)
#define	DSI_IER0_AE1IE_B_0X1		(0x1u<<1)
#define	DSI_IER0_AE0IE_B_0X0		(0x0u<<0)
#define	DSI_IER0_AE0IE_B_0X1		(0x1u<<0)

// IER1 Configuration

#define	DSI_IER1_PBUEIE				(0x1u<<19)
#define	DSI_IER1_GPRXEIE			(0x1u<<12)
#define	DSI_IER1_GPRDEIE			(0x1u<<11)
#define	DSI_IER1_GPTXEIE			(0x1u<<10)
#define	DSI_IER1_GPWREIE			(0x1u<<9)
#define	DSI_IER1_GCWREIE			(0x1u<<8)
#define	DSI_IER1_LPWREIE			(0x1u<<7)
#define	DSI_IER1_EOTPEIE			(0x1u<<6)
#define	DSI_IER1_PSEIE				(0x1u<<5)
#define	DSI_IER1_CRCEIE				(0x1u<<4)
#define	DSI_IER1_ECCMEIE			(0x1u<<3)
#define	DSI_IER1_ECCSEIE			(0x1u<<2)
#define	DSI_IER1_TOLPRXIE			(0x1u<<1)
#define	DSI_IER1_TOHSTXIE			(0x1u<<0)
#define	DSI_IER1_PBUEIE_B_0X0		(0x0u<<19)
#define	DSI_IER1_PBUEIE_B_0X1		(0x1u<<19)
#define	DSI_IER1_GPRXEIE_B_0X0		(0x0u<<12)
#define	DSI_IER1_GPRXEIE_B_0X1		(0x1u<<12)
#define	DSI_IER1_GPRDEIE_B_0X0		(0x0u<<11)
#define	DSI_IER1_GPRDEIE_B_0X1		(0x1u<<11)
#define	DSI_IER1_GPTXEIE_B_0X0		(0x0u<<10)
#define	DSI_IER1_GPTXEIE_B_0X1		(0x1u<<10)
#define	DSI_IER1_GPWREIE_B_0X0		(0x0u<<9)
#define	DSI_IER1_GPWREIE_B_0X1		(0x1u<<9)
#define	DSI_IER1_GCWREIE_B_0X0		(0x0u<<8)
#define	DSI_IER1_GCWREIE_B_0X1		(0x1u<<8)
#define	DSI_IER1_LPWREIE_B_0X0		(0x0u<<7)
#define	DSI_IER1_LPWREIE_B_0X1		(0x1u<<7)
#define	DSI_IER1_EOTPEIE_B_0X0		(0x0u<<6)
#define	DSI_IER1_EOTPEIE_B_0X1		(0x1u<<6)
#define	DSI_IER1_PSEIE_B_0X0		(0x0u<<5)
#define	DSI_IER1_PSEIE_B_0X1		(0x1u<<5)
#define	DSI_IER1_CRCEIE_B_0X0		(0x0u<<4)
#define	DSI_IER1_CRCEIE_B_0X1		(0x1u<<4)
#define	DSI_IER1_ECCMEIE_B_0X0		(0x0u<<3)
#define	DSI_IER1_ECCMEIE_B_0X1		(0x1u<<3)
#define	DSI_IER1_ECCSEIE_B_0X0		(0x0u<<2)
#define	DSI_IER1_ECCSEIE_B_0X1		(0x1u<<2)
#define	DSI_IER1_TOLPRXIE_B_0X0		(0x0u<<1)
#define	DSI_IER1_TOLPRXIE_B_0X1		(0x1u<<1)
#define	DSI_IER1_TOHSTXIE_B_0X0		(0x0u<<0)
#define	DSI_IER1_TOHSTXIE_B_0X1		(0x1u<<0)

// FIR0 Configuration

#define	DSI_FIR0_FPE4				(0x1u<<20)
#define	DSI_FIR0_FPE3				(0x1u<<19)
#define	DSI_FIR0_FPE2				(0x1u<<18)
#define	DSI_FIR0_FPE1				(0x1u<<17)
#define	DSI_FIR0_FPE0				(0x1u<<16)
#define	DSI_FIR0_FAE15				(0x1u<<15)
#define	DSI_FIR0_FAE14				(0x1u<<14)
#define	DSI_FIR0_FAE13				(0x1u<<13)
#define	DSI_FIR0_FAE12				(0x1u<<12)
#define	DSI_FIR0_FAE11				(0x1u<<11)
#define	DSI_FIR0_FAE10				(0x1u<<10)
#define	DSI_FIR0_FAE9				(0x1u<<9)
#define	DSI_FIR0_FAE8				(0x1u<<8)
#define	DSI_FIR0_FAE7				(0x1u<<7)
#define	DSI_FIR0_FAE6				(0x1u<<6)
#define	DSI_FIR0_FAE5				(0x1u<<5)
#define	DSI_FIR0_FAE4				(0x1u<<4)
#define	DSI_FIR0_FAE3				(0x1u<<3)
#define	DSI_FIR0_FAE2				(0x1u<<2)
#define	DSI_FIR0_FAE1				(0x1u<<1)
#define	DSI_FIR0_FAE0				(0x1u<<0)

// FIR1 Configuration

#define	DSI_FIR1_FPBUE				(0x1u<<19)
#define	DSI_FIR1_FGPRXE				(0x1u<<12)
#define	DSI_FIR1_FGPRDE				(0x1u<<11)
#define	DSI_FIR1_FGPTXE				(0x1u<<10)
#define	DSI_FIR1_FGPWRE				(0x1u<<9)
#define	DSI_FIR1_FGCWRE				(0x1u<<8)
#define	DSI_FIR1_FLPWRE				(0x1u<<7)
#define	DSI_FIR1_FEOTPE				(0x1u<<6)
#define	DSI_FIR1_FPSE				(0x1u<<5)
#define	DSI_FIR1_FCRCE				(0x1u<<4)
#define	DSI_FIR1_FECCME				(0x1u<<3)
#define	DSI_FIR1_FECCSE				(0x1u<<2)
#define	DSI_FIR1_FTOLPRX			(0x1u<<1)
#define	DSI_FIR1_FTOHSTX			(0x1u<<0)

// DLTRCR Configuration

#define	DSI_DLTRCR_MRD_TIME			(0x7FFFu<<0)
#define	DSI_DLTRCR_MRD_TIME_0		(0x1u<<0)

// VSCR Configuration

#define	DSI_VSCR_UR					(0x1u<<8)
#define	DSI_VSCR_EN					(0x1u<<0)
#define	DSI_VSCR_UR_B_0X0			(0x0u<<8)
#define	DSI_VSCR_UR_B_0X1			(0x1u<<8)
#define	DSI_VSCR_EN_B_0X0			(0x0u<<0)
#define	DSI_VSCR_EN_B_0X1			(0x1u<<0)

// LCVCIDR Configuration

#define	DSI_LCVCIDR_VCID			(0x3u<<0)
#define	DSI_LCVCIDR_VCID_0			(0x1u<<0)

// LCCCR Configuration

#define	DSI_LCCCR_LPE				(0x1u<<8)
#define	DSI_LCCCR_COLC				(0xFu<<0)
#define	DSI_LCCCR_COLC_0			(0x1u<<0)
#define	DSI_LCCCR_LPE_B_0X0			(0x0u<<8)
#define	DSI_LCCCR_LPE_B_0X1			(0x1u<<8)
#define	DSI_LCCCR_COLC_B_0X0		(0x0u<<0)
#define	DSI_LCCCR_COLC_B_0X1		(0x1u<<0)
#define	DSI_LCCCR_COLC_B_0X2		(0x2u<<0)
#define	DSI_LCCCR_COLC_B_0X3		(0x3u<<0)
#define	DSI_LCCCR_COLC_B_0X4		(0x4u<<0)
#define	DSI_LCCCR_COLC_B_0X5		(0x5u<<0)

// LPMCCR Configuration

#define	DSI_LPMCCR_LPSIZE			(0xFFu<<16)
#define	DSI_LPMCCR_LPSIZE_0			(0x1u<<16)
#define	DSI_LPMCCR_VLPSIZE			(0xFFu<<0)
#define	DSI_LPMCCR_VLPSIZE_0		(0x1u<<0)

// VMCCR Configuration

#define	DSI_VMCCR_LPCE				(0x1u<<9)
#define	DSI_VMCCR_FBTAAE			(0x1u<<8)
#define	DSI_VMCCR_LPHFE				(0x1u<<7)
#define	DSI_VMCCR_LPHBPE			(0x1u<<6)
#define	DSI_VMCCR_LPVAE				(0x1u<<5)
#define	DSI_VMCCR_LPVFPE			(0x1u<<4)
#define	DSI_VMCCR_LPVBPE			(0x1u<<3)
#define	DSI_VMCCR_LPVSAE			(0x1u<<2)
#define	DSI_VMCCR_VMT				(0x3u<<0)
#define	DSI_VMCCR_VMT_0				(0x1u<<0)
#define	DSI_VMCCR_LPCE_B_0X0		(0x0u<<9)
#define	DSI_VMCCR_LPCE_B_0X1		(0x1u<<9)
#define	DSI_VMCCR_FBTAAE_B_0X0		(0x0u<<8)
#define	DSI_VMCCR_FBTAAE_B_0X1		(0x1u<<8)
#define	DSI_VMCCR_LPHFE_B_0X0		(0x0u<<7)
#define	DSI_VMCCR_LPHFE_B_0X1		(0x1u<<7)
#define	DSI_VMCCR_LPHBPE_B_0X0		(0x0u<<6)
#define	DSI_VMCCR_LPHBPE_B_0X1		(0x1u<<6)
#define	DSI_VMCCR_LPVAE_B_0X0		(0x0u<<5)
#define	DSI_VMCCR_LPVAE_B_0X1		(0x1u<<5)
#define	DSI_VMCCR_LPVFPE_B_0X0		(0x0u<<4)
#define	DSI_VMCCR_LPVFPE_B_0X1		(0x1u<<4)
#define	DSI_VMCCR_LPVBPE_B_0X0		(0x0u<<3)
#define	DSI_VMCCR_LPVBPE_B_0X1		(0x1u<<3)
#define	DSI_VMCCR_LPVSAE_B_0X0		(0x0u<<2)
#define	DSI_VMCCR_LPVSAE_B_0X1		(0x1u<<2)
#define	DSI_VMCCR_VMT_B_0X0			(0x0u<<0)
#define	DSI_VMCCR_VMT_B_0X1			(0x1u<<0)

// VPCCR Configuration

#define	DSI_VPCCR_VPSIZE			(0x3FFFu<<0)
#define	DSI_VPCCR_VPSIZE_0			(0x1u<<0)

// VCCCR Configuration

#define	DSI_VCCCR_NUMC				(0x1FFFu<<0)
#define	DSI_VCCCR_NUMC_0			(0x1u<<0)

// VNPCCR Configuration

#define	DSI_VNPCCR_NPSIZE			(0x1FFFu<<0)
#define	DSI_VNPCCR_NPSIZE_0			(0x1u<<0)

// VHSACCR Configuration

#define	DSI_VHSACCR_HSA				(0xFFFu<<0)
#define	DSI_VHSACCR_HSA_0			(0x1u<<0)

// VHBPCCR Configuration

#define	DSI_VHBPCCR_HBP				(0xFFFu<<0)
#define	DSI_VHBPCCR_HBP_0			(0x1u<<0)

// VLCCR Configuration

#define	DSI_VLCCR_HLINE				(0x7FFFu<<0)
#define	DSI_VLCCR_HLINE_0			(0x1u<<0)

// VVSACCR Configuration

#define	DSI_VVSACCR_VSA				(0x3FFu<<0)
#define	DSI_VVSACCR_VSA_0			(0x1u<<0)

// VVBPCCR Configuration

#define	DSI_VVBPCCR_VBP				(0x3FFu<<0)
#define	DSI_VVBPCCR_VBP_0			(0x1u<<0)

// VVFPCCR Configuration

#define	DSI_VVFPCCR_VFP				(0x3FFu<<0)
#define	DSI_VVFPCCR_VFP_0			(0x1u<<0)

// VVACCR Configuration

#define	DSI_VVACCR_VA				(0x3FFFu<<0)
#define	DSI_VVACCR_VA_0				(0x1u<<0)

// FBSR Configuration

#define	DSI_FBSR_APBF				(0x1u<<23)
#define	DSI_FBSR_APBE				(0x1u<<22)
#define	DSI_FBSR_ACBF				(0x1u<<21)
#define	DSI_FBSR_ACBE				(0x1u<<20)
#define	DSI_FBSR_VPBF				(0x1u<<17)
#define	DSI_FBSR_VPBE				(0x1u<<16)
#define	DSI_FBSR_APWFF				(0x1u<<7)
#define	DSI_FBSR_APWFE				(0x1u<<6)
#define	DSI_FBSR_ACWFF				(0x1u<<5)
#define	DSI_FBSR_ACWFE				(0x1u<<4)
#define	DSI_FBSR_VPWFF				(0x1u<<3)
#define	DSI_FBSR_VPWFE				(0x1u<<2)
#define	DSI_FBSR_VCWFF				(0x1u<<1)
#define	DSI_FBSR_VCWFE				(0x1u<<0)
#define	DSI_FBSR_APBF_B_0X0			(0x0u<<23)
#define	DSI_FBSR_APBF_B_0X1			(0x1u<<23)
#define	DSI_FBSR_APBE_B_0X0			(0x0u<<22)
#define	DSI_FBSR_APBE_B_0X1			(0x1u<<22)
#define	DSI_FBSR_ACBF_B_0X0			(0x0u<<21)
#define	DSI_FBSR_ACBF_B_0X1			(0x1u<<21)
#define	DSI_FBSR_ACBE_B_0X0			(0x0u<<20)
#define	DSI_FBSR_ACBE_B_0X1			(0x1u<<20)
#define	DSI_FBSR_VPBF_B_0X0			(0x0u<<17)
#define	DSI_FBSR_VPBF_B_0X1			(0x1u<<17)
#define	DSI_FBSR_VPBE_B_0X0			(0x0u<<16)
#define	DSI_FBSR_VPBE_B_0X1			(0x1u<<16)
#define	DSI_FBSR_APWFF_B_0X0		(0x0u<<7)
#define	DSI_FBSR_APWFF_B_0X1		(0x1u<<7)
#define	DSI_FBSR_APWFE_B_0X0		(0x0u<<6)
#define	DSI_FBSR_APWFE_B_0X1		(0x1u<<6)
#define	DSI_FBSR_ACWFF_B_0X0		(0x0u<<5)
#define	DSI_FBSR_ACWFF_B_0X1		(0x1u<<5)
#define	DSI_FBSR_ACWFE_B_0X0		(0x0u<<4)
#define	DSI_FBSR_ACWFE_B_0X1		(0x1u<<4)
#define	DSI_FBSR_VPWFF_B_0X0		(0x0u<<3)
#define	DSI_FBSR_VPWFF_B_0X1		(0x1u<<3)
#define	DSI_FBSR_VPWFE_B_0X0		(0x0u<<2)
#define	DSI_FBSR_VPWFE_B_0X1		(0x1u<<2)
#define	DSI_FBSR_VCWFF_B_0X0		(0x0u<<1)
#define	DSI_FBSR_VCWFF_B_0X1		(0x1u<<1)
#define	DSI_FBSR_VCWFE_B_0X0		(0x0u<<0)
#define	DSI_FBSR_VCWFE_B_0X1		(0x1u<<0)

// WCFGR Configuration

#define	DSI_WCFGR_VSPOL				(0x1u<<7)
#define	DSI_WCFGR_AR				(0x1u<<6)
#define	DSI_WCFGR_TEPOL				(0x1u<<5)
#define	DSI_WCFGR_TESRC				(0x1u<<4)
#define	DSI_WCFGR_COLMUX			(0x7u<<1)
#define	DSI_WCFGR_COLMUX_0			(0x1u<<1)
#define	DSI_WCFGR_DSIM				(0x1u<<0)
#define	DSI_WCFGR_VSPOL_B_0X0		(0x0u<<7)
#define	DSI_WCFGR_VSPOL_B_0X1		(0x1u<<7)
#define	DSI_WCFGR_AR_B_0X0			(0x0u<<6)
#define	DSI_WCFGR_AR_B_0X1			(0x1u<<6)
#define	DSI_WCFGR_TEPOL_B_0X0		(0x0u<<5)
#define	DSI_WCFGR_TEPOL_B_0X1		(0x1u<<5)
#define	DSI_WCFGR_TESRC_B_0X0		(0x0u<<4)
#define	DSI_WCFGR_TESRC_B_0X1		(0x1u<<4)
#define	DSI_WCFGR_COLMUX_B_0X0		(0x0u<<1)
#define	DSI_WCFGR_COLMUX_B_0X1		(0x1u<<1)
#define	DSI_WCFGR_COLMUX_B_0X2		(0x2u<<1)
#define	DSI_WCFGR_COLMUX_B_0X3		(0x3u<<1)
#define	DSI_WCFGR_COLMUX_B_0X4		(0x4u<<1)
#define	DSI_WCFGR_COLMUX_B_0X5		(0x5u<<1)
#define	DSI_WCFGR_DSIM_B_0X0		(0x0u<<0)
#define	DSI_WCFGR_DSIM_B_0X1		(0x1u<<0)

// WCR Configuration

#define	DSI_WCR_DSIEN				(0x1u<<3)
#define	DSI_WCR_LTDCEN				(0x1u<<2)
#define	DSI_WCR_SHTDN				(0x1u<<1)
#define	DSI_WCR_COLM				(0x1u<<0)
#define	DSI_WCR_DSIEN_B_0X0			(0x0u<<3)
#define	DSI_WCR_DSIEN_B_0X1			(0x1u<<3)
#define	DSI_WCR_LTDCEN_B_0X0		(0x0u<<2)
#define	DSI_WCR_LTDCEN_B_0X1		(0x1u<<2)
#define	DSI_WCR_SHTDN_B_0X0			(0x0u<<1)
#define	DSI_WCR_SHTDN_B_0X1			(0x1u<<1)
#define	DSI_WCR_COLM_B_0X0			(0x0u<<0)
#define	DSI_WCR_COLM_B_0X1			(0x1u<<0)

// WIER Configuration

#define	DSI_WIER_PLLUIE				(0x1u<<10)
#define	DSI_WIER_PLLLIE				(0x1u<<9)
#define	DSI_WIER_ERIE				(0x1u<<1)
#define	DSI_WIER_TEIE				(0x1u<<0)
#define	DSI_WIER_PLLUIE_B_0X0		(0x0u<<10)
#define	DSI_WIER_PLLUIE_B_0X1		(0x1u<<10)
#define	DSI_WIER_PLLLIE_B_0X0		(0x0u<<9)
#define	DSI_WIER_PLLLIE_B_0X1		(0x1u<<9)
#define	DSI_WIER_ERIE_B_0X0			(0x0u<<1)
#define	DSI_WIER_ERIE_B_0X1			(0x1u<<1)
#define	DSI_WIER_TEIE_B_0X0			(0x0u<<0)
#define	DSI_WIER_TEIE_B_0X1			(0x1u<<0)

// WISR Configuration

#define	DSI_WISR_PLLUIF				(0x1u<<10)
#define	DSI_WISR_PLLLIF				(0x1u<<9)
#define	DSI_WISR_PLLLS				(0x1u<<8)
#define	DSI_WISR_BUSY				(0x1u<<2)
#define	DSI_WISR_ERIF				(0x1u<<1)
#define	DSI_WISR_TEIF				(0x1u<<0)
#define	DSI_WISR_PLLUIF_B_0X0		(0x0u<<10)
#define	DSI_WISR_PLLUIF_B_0X1		(0x1u<<10)
#define	DSI_WISR_PLLLIF_B_0X0		(0x0u<<9)
#define	DSI_WISR_PLLLIF_B_0X1		(0x1u<<9)
#define	DSI_WISR_PLLLS_B_0X0		(0x0u<<8)
#define	DSI_WISR_PLLLS_B_0X1		(0x1u<<8)
#define	DSI_WISR_BUSY_B_0X0			(0x0u<<2)
#define	DSI_WISR_BUSY_B_0X1			(0x1u<<2)
#define	DSI_WISR_ERIF_B_0X0			(0x0u<<1)
#define	DSI_WISR_ERIF_B_0X1			(0x1u<<1)
#define	DSI_WISR_TEIF_B_0X0			(0x0u<<0)
#define	DSI_WISR_TEIF_B_0X1			(0x1u<<0)

// WIFCR Configuration

#define	DSI_WIFCR_CPLLUIF			(0x1u<<10)
#define	DSI_WIFCR_CPLLLIF			(0x1u<<9)
#define	DSI_WIFCR_CERIF				(0x1u<<1)
#define	DSI_WIFCR_CTEIF				(0x1u<<0)

// WPCR0 Configuration

#define	DSI_WPCR0_FTXSMDL			(0x1u<<13)
#define	DSI_WPCR0_FTXSMCL			(0x1u<<12)
#define	DSI_WPCR0_SWDL1				(0x1u<<8)
#define	DSI_WPCR0_SWDL0				(0x1u<<7)
#define	DSI_WPCR0_SWCL				(0x1u<<6)
#define	DSI_WPCR0_FTXSMDL_B_0X0		(0x0u<<13)
#define	DSI_WPCR0_FTXSMDL_B_0X1		(0x1u<<13)
#define	DSI_WPCR0_FTXSMCL_B_0X0		(0x0u<<12)
#define	DSI_WPCR0_FTXSMCL_B_0X1		(0x1u<<12)
#define	DSI_WPCR0_SWDL1_B_0X0		(0x0u<<8)
#define	DSI_WPCR0_SWDL1_B_0X1		(0x1u<<8)
#define	DSI_WPCR0_SWDL0_B_0X0		(0x0u<<7)
#define	DSI_WPCR0_SWDL0_B_0X1		(0x1u<<7)
#define	DSI_WPCR0_SWCL_B_0X0		(0x0u<<6)
#define	DSI_WPCR0_SWCL_B_0X1		(0x1u<<6)

// WRPCR Configuration

#define	DSI_WRPCR_ODF				(0x1FFu<<20)
#define	DSI_WRPCR_ODF_0				(0x1u<<20)
#define	DSI_WRPCR_IDF				(0x1FFu<<11)
#define	DSI_WRPCR_IDF_0				(0x1u<<11)
#define	DSI_WRPCR_NDIV				(0x1FFu<<2)
#define	DSI_WRPCR_NDIV_0			(0x1u<<2)
#define	DSI_WRPCR_PLLEN				(0x1u<<0)
#define	DSI_WRPCR_ODF_B_0X0			(0x0u<<20)
#define	DSI_WRPCR_ODF_B_0X1			(0x1u<<20)
#define	DSI_WRPCR_IDF_B_0X0			(0x0u<<11)
#define	DSI_WRPCR_IDF_B_0X1			(0x1u<<11)
#define	DSI_WRPCR_NDIV_B_0X0		(0x0u<<2)
#define	DSI_WRPCR_NDIV_B_0X1		(0x1u<<2)
#define	DSI_WRPCR_PLLEN_B_0X0		(0x0u<<0)
#define	DSI_WRPCR_PLLEN_B_0X1		(0x1u<<0)

// BCFGR Configuration

#define	DSI_BCFGR_PWRUP				(0x1u<<6)
#define	DSI_BCFGR_PWRUP_B_0X0		(0x0u<<6)
#define	DSI_BCFGR_PWRUP_B_0X1		(0x1u<<6)

// DPCBCR Configuration

#define	DSI_DPCBCR_BC				(0x1Fu<<3)
#define	DSI_DPCBCR_BC_0				(0x1u<<3)
#define	DSI_DPCBCR_BC_B_0X0			(0x0u<<3)
#define	DSI_DPCBCR_BC_B_0X1			(0x1u<<3)
#define	DSI_DPCBCR_BC_B_0X2			(0x2u<<3)
#define	DSI_DPCBCR_BC_B_0X3			(0x3u<<3)
#define	DSI_DPCBCR_BC_B_0X4			(0x4u<<3)
#define	DSI_DPCBCR_BC_B_0X5			(0x5u<<3)
#define	DSI_DPCBCR_BC_B_0X6			(0x6u<<3)
#define	DSI_DPCBCR_BC_B_0X7			(0x7u<<3)
#define	DSI_DPCBCR_BC_B_0X8			(0x8u<<3)

// DPCSRCR Configuration

#define	DSI_DPCSRCR_SRC				(0xFFu<<0)
#define	DSI_DPCSRCR_SRC_0			(0x1u<<0)
#define	DSI_DPCSRCR_SRC_B_0XE		(0xEu<<0)

// DPDL0BCR Configuration

#define	DSI_DPDL0BCR_BC				(0x1Fu<<0)
#define	DSI_DPDL0BCR_BC_0			(0x1u<<0)
#define	DSI_DPDL0BCR_BC_B_0X0		(0x0u<<0)
#define	DSI_DPDL0BCR_BC_B_0X1		(0x1u<<0)
#define	DSI_DPDL0BCR_BC_B_0X2		(0x2u<<0)
#define	DSI_DPDL0BCR_BC_B_0X3		(0x3u<<0)
#define	DSI_DPDL0BCR_BC_B_0X4		(0x4u<<0)
#define	DSI_DPDL0BCR_BC_B_0X5		(0x5u<<0)
#define	DSI_DPDL0BCR_BC_B_0X6		(0x6u<<0)
#define	DSI_DPDL0BCR_BC_B_0X7		(0x7u<<0)
#define	DSI_DPDL0BCR_BC_B_0X8		(0x8u<<0)

// DPDL0SRCR Configuration

#define	DSI_DPDL0SRCR_SRC			(0xFFu<<0)
#define	DSI_DPDL0SRCR_SRC_0			(0x1u<<0)
#define	DSI_DPDL0SRCR_SRC_B_0XE		(0xEu<<0)

// DPDL1BCR Configuration

#define	DSI_DPDL1BCR_BC				(0x1Fu<<0)
#define	DSI_DPDL1BCR_BC_0			(0x1u<<0)
#define	DSI_DPDL1BCR_BC_B_0X0		(0x0u<<0)
#define	DSI_DPDL1BCR_BC_B_0X1		(0x1u<<0)
#define	DSI_DPDL1BCR_BC_B_0X2		(0x2u<<0)
#define	DSI_DPDL1BCR_BC_B_0X3		(0x3u<<0)
#define	DSI_DPDL1BCR_BC_B_0X4		(0x4u<<0)
#define	DSI_DPDL1BCR_BC_B_0X5		(0x5u<<0)
#define	DSI_DPDL1BCR_BC_B_0X6		(0x6u<<0)
#define	DSI_DPDL1BCR_BC_B_0X7		(0x7u<<0)
#define	DSI_DPDL1BCR_BC_B_0X8		(0x8u<<0)

// DPDL1SRCR Configuration

#define	DSI_DPDL1SRCR_SRC			(0xFFu<<0)
#define	DSI_DPDL1SRCR_SRC_0			(0x1u<<0)
#define	DSI_DPDL1SRCR_SRC_B_0XE		(0xEu<<0)
