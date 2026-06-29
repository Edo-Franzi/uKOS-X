/*
; stm32N657_ltdc.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_ltdc equates.
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

// LTDC address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	SSCR;
	volatile	uint32_t	BPCR;
	volatile	uint32_t	AWCR;
	volatile	uint32_t	TWCR;
	volatile	uint32_t	GCR;
	volatile	uint32_t	GC1R;
	volatile	uint32_t	GC2R;
	volatile	uint32_t	SRCR;
	volatile	uint32_t	GCCR;
	volatile	uint32_t	BCCR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	IER;
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	LIPCR;
	volatile	uint32_t	CPSR;
	volatile	uint32_t	CDSR;
	volatile	uint32_t	RESERVED2[5];
	volatile	uint32_t	EDCR;
	volatile	uint32_t	IER2;
	volatile	uint32_t	ISR2;
	volatile	uint32_t	ICR2;
	volatile	uint32_t	LIPCR2;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	ECRCR;
	volatile	uint32_t	CCRCR;
	volatile	uint32_t	RESERVED4[4];
	volatile	uint32_t	FUTR;
	volatile	uint32_t	RESERVED5[27];
	volatile	uint32_t	L1C0R;
	volatile	uint32_t	L1C1R;
	volatile	uint32_t	L1RCR;
	volatile	uint32_t	L1CR;
	volatile	uint32_t	L1WHPCR;
	volatile	uint32_t	L1WVPCR;
	volatile	uint32_t	L1CKCR;
	volatile	uint32_t	L1PFCR;
	volatile	uint32_t	L1CACR;
	volatile	uint32_t	L1DCCR;
	volatile	uint32_t	L1BFCR;
	volatile	uint32_t	L1BLCR;
	volatile	uint32_t	L1PCR;
	volatile	uint32_t	L1CFBAR;
	volatile	uint32_t	L1CFBLR;
	volatile	uint32_t	L1CFBLNR;
	volatile	uint32_t	L1AFBA0R;
	volatile	uint32_t	L1AFBA1R;
	volatile	uint32_t	L1AFBLR;
	volatile	uint32_t	L1AFBLNR;
	volatile	uint32_t	L1CLUTWR;
	volatile	uint32_t	RESERVED6[6];
	volatile	uint32_t	L1CYR0R;
	volatile	uint32_t	L1CYR1R;
	volatile	uint32_t	L1FPF0R;
	volatile	uint32_t	L1FPF1R;
	volatile	uint32_t	RESERVED7[33];
	volatile	uint32_t	L2C0R;
	volatile	uint32_t	L2C1R;
	volatile	uint32_t	L2RCR;
	volatile	uint32_t	L2CR;
	volatile	uint32_t	L2WHPCR;
	volatile	uint32_t	L2WVPCR;
	volatile	uint32_t	L2CKCR;
	volatile	uint32_t	L2PFCR;
	volatile	uint32_t	L2CACR;
	volatile	uint32_t	L2DCCR;
	volatile	uint32_t	L2BFCR;
	volatile	uint32_t	L2BLCR;
	volatile	uint32_t	L2PCR;
	volatile	uint32_t	L2CFBAR;
	volatile	uint32_t	L2CFBLR;
	volatile	uint32_t	L2CFBLNR;
	volatile	uint32_t	RESERVED8[4];
	volatile	uint32_t	L2CLUTWR;
	volatile	uint32_t	RESERVED9[6];
	volatile	uint32_t	L2CYR0R;
	volatile	uint32_t	L2CYR1R;
	volatile	uint32_t	L2FPF0R;
	volatile	uint32_t	L2FPF1R;
} LTDC_TypeDef;

#if (defined(__cplusplus))
#define	LTDC_NS	reinterpret_cast<LTDC_TypeDef *>(0x48001000u)
#define	LTDC_S	reinterpret_cast<LTDC_TypeDef *>(0x58001000u)

#else
#define	LTDC_NS	((LTDC_TypeDef *)0x48001000u)
#define	LTDC_S	((LTDC_TypeDef *)0x58001000u)
#endif

// SSCR Configuration

#define	LTDC_SSCR_HSW			(0xFFFFu<<16)
#define	LTDC_SSCR_HSW_0			(0x1u<<16)
#define	LTDC_SSCR_VSH			(0xFFFFu<<0)
#define	LTDC_SSCR_VSH_0			(0x1u<<0)

// BPCR Configuration

#define	LTDC_BPCR_AHBP			(0xFFFFu<<16)
#define	LTDC_BPCR_AHBP_0		(0x1u<<16)
#define	LTDC_BPCR_AVBP			(0xFFFFu<<0)
#define	LTDC_BPCR_AVBP_0		(0x1u<<0)

// AWCR Configuration

#define	LTDC_AWCR_AAW			(0xFFFFu<<16)
#define	LTDC_AWCR_AAW_0			(0x1u<<16)
#define	LTDC_AWCR_AAH			(0xFFFFu<<0)
#define	LTDC_AWCR_AAH_0			(0x1u<<0)

// TWCR Configuration

#define	LTDC_TWCR_TOTALW		(0xFFFFu<<16)
#define	LTDC_TWCR_TOTALW_0		(0x1u<<16)
#define	LTDC_TWCR_TOTALH		(0xFFFFu<<0)
#define	LTDC_TWCR_TOTALH_0		(0x1u<<0)

// GCR Configuration

#define	LTDC_GCR_HSPOL			(0x1u<<31)
#define	LTDC_GCR_VSPOL			(0x1u<<30)
#define	LTDC_GCR_DEPOL			(0x1u<<29)
#define	LTDC_GCR_PCPOL			(0x1u<<28)
#define	LTDC_GCR_SFSWTR			(0x1u<<25)
#define	LTDC_GCR_SFEN			(0x1u<<24)
#define	LTDC_GCR_CRCEN			(0x1u<<19)
#define	LTDC_GCR_DEN			(0x1u<<16)
#define	LTDC_GCR_DRW			(0x7u<<12)
#define	LTDC_GCR_DRW_0			(0x1u<<12)
#define	LTDC_GCR_DGW			(0x7u<<8)
#define	LTDC_GCR_DGW_0			(0x1u<<8)
#define	LTDC_GCR_DBW			(0x7u<<4)
#define	LTDC_GCR_DBW_0			(0x1u<<4)
#define	LTDC_GCR_GAMEN			(0x1u<<1)
#define	LTDC_GCR_LTDCEN			(0x1u<<0)

#define	LTDC_GCR_HSPOL_B_0X0	(0x0u<<31)
#define	LTDC_GCR_HSPOL_B_0X1	(0x1u<<31)
#define	LTDC_GCR_VSPOL_B_0X0	(0x0u<<30)
#define	LTDC_GCR_VSPOL_B_0X1	(0x1u<<30)
#define	LTDC_GCR_DEPOL_B_0X0	(0x0u<<29)
#define	LTDC_GCR_DEPOL_B_0X1	(0x1u<<29)
#define	LTDC_GCR_PCPOL_B_0X0	(0x0u<<28)
#define	LTDC_GCR_PCPOL_B_0X1	(0x1u<<28)
#define	LTDC_GCR_SFSWTR_B_0X0	(0x0u<<25)
#define	LTDC_GCR_SFSWTR_B_0X1	(0x1u<<25)
#define	LTDC_GCR_SFEN_B_0X0		(0x0u<<24)
#define	LTDC_GCR_SFEN_B_0X1		(0x1u<<24)
#define	LTDC_GCR_CRCEN_B_0X0	(0x0u<<19)
#define	LTDC_GCR_CRCEN_B_0X1	(0x1u<<19)
#define	LTDC_GCR_DEN_B_0X0		(0x0u<<16)
#define	LTDC_GCR_DEN_B_0X1		(0x1u<<16)
#define	LTDC_GCR_GAMEN_B_0X0	(0x0u<<1)
#define	LTDC_GCR_GAMEN_B_0X1	(0x1u<<1)
#define	LTDC_GCR_LTDCEN_B_0X0	(0x0u<<0)
#define	LTDC_GCR_LTDCEN_B_0X1	(0x1u<<0)

// GC1R Configuration

#define	LTDC_GC1R_BMA			(0x1u<<31)
#define	LTDC_GC1R_CRMA			(0x1u<<30)
#define	LTDC_GC1R_STRA			(0x1u<<29)
#define	LTDC_GC1R_DWP			(0x1u<<28)
#define	LTDC_GC1R_SPP			(0x1u<<27)
#define	LTDC_GC1R_TP			(0x1u<<25)
#define	LTDC_GC1R_LNIP			(0x1u<<24)
#define	LTDC_GC1R_BBA			(0x1u<<23)
#define	LTDC_GC1R_BCP			(0x1u<<22)
#define	LTDC_GC1R_SHRA			(0x1u<<21)
#define	LTDC_GC1R_GCT			(0x7u<<17)
#define	LTDC_GC1R_GCT_0			(0x1u<<17)
#define	LTDC_GC1R_DT			(0x3u<<14)
#define	LTDC_GC1R_DT_0			(0x1u<<14)
#define	LTDC_GC1R_PRBA			(0x1u<<12)
#define	LTDC_GC1R_WRCH			(0xFu<<8)
#define	LTDC_GC1R_WRCH_0		(0x1u<<8)
#define	LTDC_GC1R_WGCH			(0xFu<<4)
#define	LTDC_GC1R_WGCH_0		(0x1u<<4)
#define	LTDC_GC1R_WBCH			(0xFu<<0)
#define	LTDC_GC1R_WBCH_0		(0x1u<<0)

#define	LTDC_GC1R_GCT_B_0X0		(0x0u<<17)
#define	LTDC_GC1R_GCT_B_0X1		(0x1u<<17)
#define	LTDC_GC1R_GCT_B_0X2		(0x2u<<17)
#define	LTDC_GC1R_DT_B_0X0		(0x0u<<14)
#define	LTDC_GC1R_DT_B_0X1		(0x1u<<14)
#define	LTDC_GC1R_DT_B_0X3		(0x3u<<14)

// GC2R Configuration

#define	LTDC_GC2R_BOA			(0x1u<<15)
#define	LTDC_GC2R_CRCA			(0x1u<<13)
#define	LTDC_GC2R_SFA			(0x1u<<12)
#define	LTDC_GC2R_SISA			(0x1u<<11)
#define	LTDC_GC2R_ROTA			(0x1u<<10)
#define	LTDC_GC2R_AXIIDA		(0x1u<<9)
#define	LTDC_GC2R_OCA			(0x1u<<8)
#define	LTDC_GC2R_EDCA			(0x1u<<7)
#define	LTDC_GC2R_BW			(0x7u<<4)
#define	LTDC_GC2R_BW_0			(0x1u<<4)
#define	LTDC_GC2R_DPA			(0x1u<<3)
#define	LTDC_GC2R_DVA			(0x1u<<2)
#define	LTDC_GC2R_STSA			(0x1u<<1)
#define	LTDC_GC2R_BLA			(0x1u<<0)

#define	LTDC_GC2R_BOA_B_0X0		(0x0u<<15)
#define	LTDC_GC2R_BOA_B_0X1		(0x1u<<15)
#define	LTDC_GC2R_CRCA_B_0X0	(0x0u<<13)
#define	LTDC_GC2R_CRCA_B_0X1	(0x1u<<13)
#define	LTDC_GC2R_SFA_B_0X0		(0x0u<<12)
#define	LTDC_GC2R_SFA_B_0X1		(0x1u<<12)
#define	LTDC_GC2R_SISA_B_0X0	(0x0u<<11)
#define	LTDC_GC2R_SISA_B_0X1	(0x1u<<11)
#define	LTDC_GC2R_BW_B_0X2		(0x2u<<4)
#define	LTDC_GC2R_BW_B_0X3		(0x3u<<4)
#define	LTDC_GC2R_BW_B_0X4		(0x4u<<4)

// SRCR Configuration

#define	LTDC_SRCR_VBR			(0x1u<<1)
#define	LTDC_SRCR_IMR			(0x1u<<0)

#define	LTDC_SRCR_VBR_B_0X0		(0x0u<<1)
#define	LTDC_SRCR_VBR_B_0X1		(0x1u<<1)
#define	LTDC_SRCR_IMR_B_0X0		(0x0u<<0)
#define	LTDC_SRCR_IMR_B_0X1		(0x1u<<0)

// GCCR Configuration

#define	LTDC_GCCR_REN			(0x1u<<18)
#define	LTDC_GCCR_GEN			(0x1u<<17)
#define	LTDC_GCCR_BEN			(0x1u<<16)
#define	LTDC_GCCR_COMP			(0xFFu<<8)
#define	LTDC_GCCR_COMP_0		(0x1u<<8)
#define	LTDC_GCCR_ADDR			(0xFFu<<0)
#define	LTDC_GCCR_ADDR_0		(0x1u<<0)

#define	LTDC_GCCR_REN_B_0X0		(0x0u<<18)
#define	LTDC_GCCR_REN_B_0X1		(0x1u<<18)
#define	LTDC_GCCR_GEN_B_0X0		(0x0u<<17)
#define	LTDC_GCCR_GEN_B_0X1		(0x1u<<17)
#define	LTDC_GCCR_BEN_B_0X0		(0x0u<<16)
#define	LTDC_GCCR_BEN_B_0X1		(0x1u<<16)

// BCCR Configuration

#define	LTDC_BCCR_BCRED			(0xFFu<<16)
#define	LTDC_BCCR_BCRED_0		(0x1u<<16)
#define	LTDC_BCCR_BCGREEN		(0xFFu<<8)
#define	LTDC_BCCR_BCGREEN_0		(0x1u<<8)
#define	LTDC_BCCR_BCBLUE		(0xFFu<<0)
#define	LTDC_BCCR_BCBLUE_0		(0x1u<<0)

// IER Configuration

#define	LTDC_IER_CRCIE			(0x1u<<7)
#define	LTDC_IER_FUIE			(0x1u<<6)
#define	LTDC_IER_RRIE			(0x1u<<3)
#define	LTDC_IER_TERRIE			(0x1u<<2)
#define	LTDC_IER_FUWIE			(0x1u<<1)
#define	LTDC_IER_LIE			(0x1u<<0)

#define	LTDC_IER_CRCIE_B_0X0	(0x0u<<7)
#define	LTDC_IER_CRCIE_B_0X1	(0x1u<<7)
#define	LTDC_IER_FUIE_B_0X0		(0x0u<<6)
#define	LTDC_IER_FUIE_B_0X1		(0x1u<<6)
#define	LTDC_IER_RRIE_B_0X0		(0x0u<<3)
#define	LTDC_IER_RRIE_B_0X1		(0x1u<<3)
#define	LTDC_IER_TERRIE_B_0X0	(0x0u<<2)
#define	LTDC_IER_TERRIE_B_0X1	(0x1u<<2)
#define	LTDC_IER_FUWIE_B_0X0	(0x0u<<1)
#define	LTDC_IER_FUWIE_B_0X1	(0x1u<<1)
#define	LTDC_IER_LIE_B_0X0		(0x0u<<0)
#define	LTDC_IER_LIE_B_0X1		(0x1u<<0)

// ISR Configuration

#define	LTDC_ISR_CRCIF			(0x1u<<7)
#define	LTDC_ISR_FUIF			(0x1u<<6)
#define	LTDC_ISR_RRIF			(0x1u<<3)
#define	LTDC_ISR_TERRIF			(0x1u<<2)
#define	LTDC_ISR_FUWIF			(0x1u<<1)
#define	LTDC_ISR_LIF			(0x1u<<0)

#define	LTDC_ISR_CRCIF_B_0X0	(0x0u<<7)
#define	LTDC_ISR_CRCIF_B_0X1	(0x1u<<7)
#define	LTDC_ISR_FUIF_B_0X0		(0x0u<<6)
#define	LTDC_ISR_FUIF_B_0X1		(0x1u<<6)
#define	LTDC_ISR_RRIF_B_0X0		(0x0u<<3)
#define	LTDC_ISR_RRIF_B_0X1		(0x1u<<3)
#define	LTDC_ISR_TERRIF_B_0X0	(0x0u<<2)
#define	LTDC_ISR_TERRIF_B_0X1	(0x1u<<2)
#define	LTDC_ISR_FUWIF_B_0X0	(0x0u<<1)
#define	LTDC_ISR_FUWIF_B_0X1	(0x1u<<1)
#define	LTDC_ISR_LIF_B_0X0		(0x0u<<0)
#define	LTDC_ISR_LIF_B_0X1		(0x1u<<0)

// ICR Configuration

#define	LTDC_ICR_CCRCIF			(0x1u<<7)
#define	LTDC_ICR_CFUIF			(0x1u<<6)
#define	LTDC_ICR_CRRIF			(0x1u<<3)
#define	LTDC_ICR_CTERRIF		(0x1u<<2)
#define	LTDC_ICR_CFUWIF			(0x1u<<1)
#define	LTDC_ICR_CLIF			(0x1u<<0)

#define	LTDC_ICR_CCRCIF_B_0X0	(0x0u<<7)
#define	LTDC_ICR_CCRCIF_B_0X1	(0x1u<<7)
#define	LTDC_ICR_CFUIF_B_0X0	(0x0u<<6)
#define	LTDC_ICR_CFUIF_B_0X1	(0x1u<<6)
#define	LTDC_ICR_CRRIF_B_0X0	(0x0u<<3)
#define	LTDC_ICR_CRRIF_B_0X1	(0x1u<<3)
#define	LTDC_ICR_CTERRIF_B_0X0	(0x0u<<2)
#define	LTDC_ICR_CTERRIF_B_0X1	(0x1u<<2)
#define	LTDC_ICR_CFUWIF_B_0X0	(0x0u<<1)
#define	LTDC_ICR_CFUWIF_B_0X1	(0x1u<<1)
#define	LTDC_ICR_CLIF_B_0X0		(0x0u<<0)
#define	LTDC_ICR_CLIF_B_0X1		(0x1u<<0)

// LIPCR Configuration

#define	LTDC_LIPCR_LIPOS		(0xFFFFu<<0)
#define	LTDC_LIPCR_LIPOS_0		(0x1u<<0)

// CPSR Configuration

#define	LTDC_CPSR_CXPOS			(0xFFFFu<<16)
#define	LTDC_CPSR_CXPOS_0		(0x1u<<16)
#define	LTDC_CPSR_CYPOS			(0xFFFFu<<0)
#define	LTDC_CPSR_CYPOS_0		(0x1u<<0)

// CDSR Configuration

#define	LTDC_CDSR_HSYNCS		(0x1u<<3)
#define	LTDC_CDSR_VSYNCS		(0x1u<<2)
#define	LTDC_CDSR_HDES			(0x1u<<1)
#define	LTDC_CDSR_VDES			(0x1u<<0)

#define	LTDC_CDSR_HSYNCS_B_0X0	(0x0u<<3)
#define	LTDC_CDSR_HSYNCS_B_0X1	(0x1u<<3)
#define	LTDC_CDSR_VSYNCS_B_0X0	(0x0u<<2)
#define	LTDC_CDSR_VSYNCS_B_0X1	(0x1u<<2)
#define	LTDC_CDSR_HDES_B_0X0	(0x0u<<1)
#define	LTDC_CDSR_HDES_B_0X1	(0x1u<<1)
#define	LTDC_CDSR_VDES_B_0X0	(0x0u<<0)
#define	LTDC_CDSR_VDES_B_0X1	(0x1u<<0)

// EDCR Configuration

#define	LTDC_EDCR_OCYCO			(0x1u<<27)
#define	LTDC_EDCR_OCYSEL		(0x1u<<26)
#define	LTDC_EDCR_OCYEN			(0x1u<<25)

#define	LTDC_EDCR_OCYCO_B_0X0	(0x0u<<27)
#define	LTDC_EDCR_OCYCO_B_0X1	(0x1u<<27)
#define	LTDC_EDCR_OCYSEL_B_0X0	(0x0u<<26)
#define	LTDC_EDCR_OCYSEL_B_0X1	(0x1u<<26)
#define	LTDC_EDCR_OCYEN_B_0X0	(0x0u<<25)
#define	LTDC_EDCR_OCYEN_B_0X1	(0x1u<<25)

// IER2 Configuration

#define	LTDC_IER2_CRCIE			(0x1u<<7)
#define	LTDC_IER2_FUIE			(0x1u<<6)
#define	LTDC_IER2_RRIE			(0x1u<<3)
#define	LTDC_IER2_TERRIE		(0x1u<<2)
#define	LTDC_IER2_FUWIE			(0x1u<<1)
#define	LTDC_IER2_LIE			(0x1u<<0)

#define	LTDC_IER2_CRCIE_B_0X0	(0x0u<<7)
#define	LTDC_IER2_CRCIE_B_0X1	(0x1u<<7)
#define	LTDC_IER2_FUIE_B_0X0	(0x0u<<6)
#define	LTDC_IER2_FUIE_B_0X1	(0x1u<<6)
#define	LTDC_IER2_RRIE_B_0X0	(0x0u<<3)
#define	LTDC_IER2_RRIE_B_0X1	(0x1u<<3)
#define	LTDC_IER2_TERRIE_B_0X0	(0x0u<<2)
#define	LTDC_IER2_TERRIE_B_0X1	(0x1u<<2)
#define	LTDC_IER2_FUWIE_B_0X0	(0x0u<<1)
#define	LTDC_IER2_FUWIE_B_0X1	(0x1u<<1)
#define	LTDC_IER2_LIE_B_0X0		(0x0u<<0)
#define	LTDC_IER2_LIE_B_0X1		(0x1u<<0)

// ISR2 Configuration

#define	LTDC_ISR2_CRCIF			(0x1u<<7)
#define	LTDC_ISR2_FUIF			(0x1u<<6)
#define	LTDC_ISR2_RRIF			(0x1u<<3)
#define	LTDC_ISR2_TERRIF		(0x1u<<2)
#define	LTDC_ISR2_FUWIF			(0x1u<<1)
#define	LTDC_ISR2_LIF			(0x1u<<0)

#define	LTDC_ISR2_CRCIF_B_0X0	(0x0u<<7)
#define	LTDC_ISR2_CRCIF_B_0X1	(0x1u<<7)
#define	LTDC_ISR2_FUIF_B_0X0	(0x0u<<6)
#define	LTDC_ISR2_FUIF_B_0X1	(0x1u<<6)
#define	LTDC_ISR2_RRIF_B_0X0	(0x0u<<3)
#define	LTDC_ISR2_RRIF_B_0X1	(0x1u<<3)
#define	LTDC_ISR2_TERRIF_B_0X0	(0x0u<<2)
#define	LTDC_ISR2_TERRIF_B_0X1	(0x1u<<2)
#define	LTDC_ISR2_FUWIF_B_0X0	(0x0u<<1)
#define	LTDC_ISR2_FUWIF_B_0X1	(0x1u<<1)
#define	LTDC_ISR2_LIF_B_0X0		(0x0u<<0)
#define	LTDC_ISR2_LIF_B_0X1		(0x1u<<0)

// ICR2 Configuration

#define	LTDC_ICR2_CCRCIF		(0x1u<<7)
#define	LTDC_ICR2_CFUIF			(0x1u<<6)
#define	LTDC_ICR2_CRRIF			(0x1u<<3)
#define	LTDC_ICR2_CTERRIF		(0x1u<<2)
#define	LTDC_ICR2_CFUWIF		(0x1u<<1)
#define	LTDC_ICR2_CLIF			(0x1u<<0)

#define	LTDC_ICR2_CCRCIF_B_0X0	(0x0u<<7)
#define	LTDC_ICR2_CCRCIF_B_0X1	(0x1u<<7)
#define	LTDC_ICR2_CFUIF_B_0X0	(0x0u<<6)
#define	LTDC_ICR2_CFUIF_B_0X1	(0x1u<<6)
#define	LTDC_ICR2_CRRIF_B_0X0	(0x0u<<3)
#define	LTDC_ICR2_CRRIF_B_0X1	(0x1u<<3)
#define	LTDC_ICR2_CTERRIF_B_0X0	(0x0u<<2)
#define	LTDC_ICR2_CTERRIF_B_0X1	(0x1u<<2)
#define	LTDC_ICR2_CFUWIF_B_0X0	(0x0u<<1)
#define	LTDC_ICR2_CFUWIF_B_0X1	(0x1u<<1)
#define	LTDC_ICR2_CLIF_B_0X0	(0x0u<<0)
#define	LTDC_ICR2_CLIF_B_0X1	(0x1u<<0)

// LIPCR2 Configuration

#define	LTDC_LIPCR2_LIPOS		(0xFFFFu<<0)
#define	LTDC_LIPCR2_LIPOS_0		(0x1u<<0)

// ECRCR Configuration

#define	LTDC_ECRCR_ECRC			(0xFFFFu<<0)
#define	LTDC_ECRCR_ECRC_0		(0x1u<<0)

// CCRCR Configuration

#define	LTDC_CCRCR_CCRC			(0xFFFFu<<0)
#define	LTDC_CCRCR_CCRC_0		(0x1u<<0)

// FUTR Configuration

#define	LTDC_FUTR_THRE			(0xFFFFu<<0)
#define	LTDC_FUTR_THRE_0		(0x1u<<0)

// L1C0R Configuration

#define	LTDC_L1C0R_ARGB8888		(0x1u<<31)
#define	LTDC_L1C0R_ABGR8888		(0x1u<<30)
#define	LTDC_L1C0R_RGBA8888		(0x1u<<29)
#define	LTDC_L1C0R_BGRA888		(0x1u<<28)
#define	LTDC_L1C0R_RGB565		(0x1u<<27)
#define	LTDC_L1C0R_BGR565		(0x1u<<26)
#define	LTDC_L1C0R_RGB888		(0x1u<<25)
#define	LTDC_L1C0R_FF			(0x1u<<24)
#define	LTDC_L1C0R_F11PC		(0x1u<<23)
#define	LTDC_L1C0R_F1PC			(0x1u<<22)
#define	LTDC_L1C0R_F11C			(0x1u<<21)
#define	LTDC_L1C0R_F1C			(0x1u<<20)
#define	LTDC_L1C0R_F11P			(0x1u<<19)
#define	LTDC_L1C0R_F1P			(0x1u<<18)
#define	LTDC_L1C0R_F10			(0x1u<<17)
#define	LTDC_L1C0R_F11			(0x1u<<16)
#define	LTDC_L1C0R_F21PC		(0x1u<<15)
#define	LTDC_L1C0R_F2PC			(0x1u<<14)
#define	LTDC_L1C0R_F21C			(0x1u<<13)
#define	LTDC_L1C0R_F2C			(0x1u<<12)
#define	LTDC_L1C0R_F21P			(0x1u<<11)
#define	LTDC_L1C0R_F2P			(0x1u<<10)
#define	LTDC_L1C0R_F20			(0x1u<<9)
#define	LTDC_L1C0R_F21			(0x1u<<8)
#define	LTDC_L1C0R_CKRA			(0x1u<<7)
#define	LTDC_L1C0R_CLUTA		(0x1u<<6)
#define	LTDC_L1C0R_WINA			(0x1u<<5)
#define	LTDC_L1C0R_DCP			(0x1u<<4)
#define	LTDC_L1C0R_APA			(0x1u<<3)
#define	LTDC_L1C0R_CFBPA		(0x1u<<2)
#define	LTDC_L1C0R_CFBDA		(0x1u<<1)
#define	LTDC_L1C0R_CKTA			(0x1u<<0)

// L1C1R Configuration

#define	LTDC_L1C1R_SCA			(0x1u<<31)
#define	LTDC_L1C1R_YFPA			(0x1u<<2)
#define	LTDC_L1C1R_YSPA			(0x1u<<1)
#define	LTDC_L1C1R_YIA			(0x1u<<0)

#define	LTDC_L1C1R_SCA_B_0X0	(0x0u<<31)
#define	LTDC_L1C1R_SCA_B_0X1	(0x1u<<31)
#define	LTDC_L1C1R_YFPA_B_0X0	(0x0u<<2)
#define	LTDC_L1C1R_YFPA_B_0X1	(0x1u<<2)
#define	LTDC_L1C1R_YSPA_B_0X0	(0x0u<<1)
#define	LTDC_L1C1R_YSPA_B_0X1	(0x1u<<1)
#define	LTDC_L1C1R_YIA_B_0X0	(0x0u<<0)
#define	LTDC_L1C1R_YIA_B_0X1	(0x1u<<0)

// L1RCR Configuration

#define	LTDC_L1RCR_GRMSK		(0x1u<<2)
#define	LTDC_L1RCR_VBR			(0x1u<<1)
#define	LTDC_L1RCR_IMR			(0x1u<<0)

#define	LTDC_L1RCR_GRMSK_B_0X0	(0x0u<<2)
#define	LTDC_L1RCR_GRMSK_B_0X1	(0x1u<<2)
#define	LTDC_L1RCR_VBR_B_0X0	(0x0u<<1)
#define	LTDC_L1RCR_VBR_B_0X1	(0x1u<<1)
#define	LTDC_L1RCR_IMR_B_0X0	(0x0u<<0)
#define	LTDC_L1RCR_IMR_B_0X1	(0x1u<<0)

// L1CR Configuration

#define	LTDC_L1CR_DCBEN			(0x1u<<9)
#define	LTDC_L1CR_HMEN			(0x1u<<8)
#define	LTDC_L1CR_CLUTEN		(0x1u<<4)
#define	LTDC_L1CR_CKEN			(0x1u<<1)
#define	LTDC_L1CR_LEN			(0x1u<<0)

#define	LTDC_L1CR_DCBEN_B_0X0	(0x0u<<9)
#define	LTDC_L1CR_DCBEN_B_0X1	(0x1u<<9)
#define	LTDC_L1CR_HMEN_B_0X0	(0x0u<<8)
#define	LTDC_L1CR_HMEN_B_0X1	(0x1u<<8)
#define	LTDC_L1CR_CLUTEN_B_0X0	(0x0u<<4)
#define	LTDC_L1CR_CLUTEN_B_0X1	(0x1u<<4)
#define	LTDC_L1CR_CKEN_B_0X0	(0x0u<<1)
#define	LTDC_L1CR_CKEN_B_0X1	(0x1u<<1)
#define	LTDC_L1CR_LEN_B_0X0		(0x0u<<0)
#define	LTDC_L1CR_LEN_B_0X1		(0x1u<<0)

// L1WHPCR Configuration

#define	LTDC_L1WHPCR_WHSPPOS	(0xFFFFu<<16)
#define	LTDC_L1WHPCR_WHSPPOS_0	(0x1u<<16)
#define	LTDC_L1WHPCR_WHSTPOS	(0xFFFFu<<0)
#define	LTDC_L1WHPCR_WHSTPOS_0	(0x1u<<0)

// L1WVPCR Configuration

#define	LTDC_L1WVPCR_WVSPPOS	(0xFFFFu<<16)
#define	LTDC_L1WVPCR_WVSPPOS_0	(0x1u<<16)
#define	LTDC_L1WVPCR_WVSTPOS	(0xFFFFu<<0)
#define	LTDC_L1WVPCR_WVSTPOS_0	(0x1u<<0)

// L1CKCR Configuration

#define	LTDC_L1CKCR_CKRED		(0xFFu<<16)
#define	LTDC_L1CKCR_CKRED_0		(0x1u<<16)
#define	LTDC_L1CKCR_CKGREEN		(0xFFu<<8)
#define	LTDC_L1CKCR_CKGREEN_0	(0x1u<<8)
#define	LTDC_L1CKCR_CKBLUE		(0xFFu<<0)
#define	LTDC_L1CKCR_CKBLUE_0	(0x1u<<0)

// L1PFCR Configuration

#define	LTDC_L1PFCR_PF			(0x7u<<0)
#define	LTDC_L1PFCR_PF_0		(0x1u<<0)

#define	LTDC_L1PFCR_PF_B_0X0	(0x0u<<0)
#define	LTDC_L1PFCR_PF_B_0X1	(0x1u<<0)
#define	LTDC_L1PFCR_PF_B_0X2	(0x2u<<0)
#define	LTDC_L1PFCR_PF_B_0X3	(0x3u<<0)
#define	LTDC_L1PFCR_PF_B_0X4	(0x4u<<0)
#define	LTDC_L1PFCR_PF_B_0X5	(0x5u<<0)
#define	LTDC_L1PFCR_PF_B_0X6	(0x6u<<0)
#define	LTDC_L1PFCR_PF_B_0X7	(0x7u<<0)

// L1CACR Configuration

#define	LTDC_L1CACR_CONSTA		(0xFFu<<0)
#define	LTDC_L1CACR_CONSTA_0	(0x1u<<0)

// L1DCCR Configuration

#define	LTDC_L1DCCR_DCALPHA		(0xFFu<<24)
#define	LTDC_L1DCCR_DCALPHA_0	(0x1u<<24)
#define	LTDC_L1DCCR_DCRED		(0xFFu<<16)
#define	LTDC_L1DCCR_DCRED_0		(0x1u<<16)
#define	LTDC_L1DCCR_DCGREEN		(0xFFu<<8)
#define	LTDC_L1DCCR_DCGREEN_0	(0x1u<<8)
#define	LTDC_L1DCCR_DCBLUE		(0xFFu<<0)
#define	LTDC_L1DCCR_DCBLUE_0	(0x1u<<0)

// L1BFCR Configuration

#define	LTDC_L1BFCR_BOR			(0x1u<<16)
#define	LTDC_L1BFCR_BF1			(0x7u<<8)
#define	LTDC_L1BFCR_BF1_0		(0x1u<<8)
#define	LTDC_L1BFCR_BF2			(0x7u<<0)
#define	LTDC_L1BFCR_BF2_0		(0x1u<<0)

#define	LTDC_L1BFCR_BOR_B_0X0	(0x0u<<16)
#define	LTDC_L1BFCR_BOR_B_0X1	(0x1u<<16)
#define	LTDC_L1BFCR_BF1_B_0X4	(0x4u<<8)
#define	LTDC_L1BFCR_BF1_B_0X6	(0x6u<<8)
#define	LTDC_L1BFCR_BF2_B_0X5	(0x5u<<0)
#define	LTDC_L1BFCR_BF2_B_0X7	(0x7u<<0)

// L1BLCR Configuration

#define	LTDC_L1BLCR_BL			(0xFFu<<0)
#define	LTDC_L1BLCR_BL_0		(0x1u<<0)

#define	LTDC_L1BLCR_BL_B_0X00	(0x0u<<0)
#define	LTDC_L1BLCR_BL_B_0X01	(0x1u<<0)
#define	LTDC_L1BLCR_BL_B_0X10	(0x10u<<0)

// L1PCR Configuration

#define	LTDC_L1PCR_YREN			(0x1u<<9)
#define	LTDC_L1PCR_OF			(0x1u<<8)
#define	LTDC_L1PCR_CBF			(0x1u<<7)
#define	LTDC_L1PCR_YF			(0x1u<<6)
#define	LTDC_L1PCR_YCM			(0x3u<<4)
#define	LTDC_L1PCR_YCM_0		(0x1u<<4)
#define	LTDC_L1PCR_YCEN			(0x1u<<3)

#define	LTDC_L1PCR_YREN_B_0X0	(0x0u<<9)
#define	LTDC_L1PCR_YREN_B_0X1	(0x1u<<9)
#define	LTDC_L1PCR_OF_B_0X0		(0x0u<<8)
#define	LTDC_L1PCR_OF_B_0X1		(0x1u<<8)
#define	LTDC_L1PCR_CBF_B_0X0	(0x0u<<7)
#define	LTDC_L1PCR_CBF_B_0X1	(0x1u<<7)
#define	LTDC_L1PCR_YF_B_0X0		(0x0u<<6)
#define	LTDC_L1PCR_YF_B_0X1		(0x1u<<6)
#define	LTDC_L1PCR_YCM_B_0X0	(0x0u<<4)
#define	LTDC_L1PCR_YCM_B_0X1	(0x1u<<4)
#define	LTDC_L1PCR_YCM_B_0X2	(0x2u<<4)
#define	LTDC_L1PCR_YCEN_B_0X0	(0x0u<<3)
#define	LTDC_L1PCR_YCEN_B_0X1	(0x1u<<3)

// L1CFBAR Configuration

#define	LTDC_L1CFBAR_CFBADD		(0xFFFFFFFFu<<0)
#define	LTDC_L1CFBAR_CFBADD_0	(0x1u<<0)

// L1CFBLR Configuration

#define	LTDC_L1CFBLR_CFBP		(0xFFFFu<<16)
#define	LTDC_L1CFBLR_CFBP_0		(0x1u<<16)
#define	LTDC_L1CFBLR_CFBLL		(0xFFFFu<<0)
#define	LTDC_L1CFBLR_CFBLL_0	(0x1u<<0)

// L1CFBLNR Configuration

#define	LTDC_L1CFBLNR_CFBLNBR	(0xFFFFu<<0)
#define	LTDC_L1CFBLNR_CFBLNBR_0	(0x1u<<0)

// L1AFBA0R Configuration

#define	LTDC_L1AFBA0R_AFBADD0	(0xFFFFFFFFu<<0)
#define	LTDC_L1AFBA0R_AFBADD0_0	(0x1u<<0)

// L1AFBA1R Configuration

#define	LTDC_L1AFBA1R_AFBADD1	(0xFFFFFFFFu<<0)
#define	LTDC_L1AFBA1R_AFBADD1_0	(0x1u<<0)

// L1AFBLR Configuration

#define	LTDC_L1AFBLR_AFBP		(0xFFFFu<<16)
#define	LTDC_L1AFBLR_AFBP_0		(0x1u<<16)
#define	LTDC_L1AFBLR_AFBLL		(0xFFFFu<<0)
#define	LTDC_L1AFBLR_AFBLL_0	(0x1u<<0)

// L1AFBLNR Configuration

#define	LTDC_L1AFBLNR_AFBLNBR	(0xFFFFu<<0)
#define	LTDC_L1AFBLNR_AFBLNBR_0	(0x1u<<0)

// L1CLUTWR Configuration

#define	LTDC_L1CLUTWR_CLUTADD	(0xFFu<<24)
#define	LTDC_L1CLUTWR_CLUTADD_0	(0x1u<<24)
#define	LTDC_L1CLUTWR_RED		(0xFFu<<16)
#define	LTDC_L1CLUTWR_RED_0		(0x1u<<16)
#define	LTDC_L1CLUTWR_GREEN		(0xFFu<<8)
#define	LTDC_L1CLUTWR_GREEN_0	(0x1u<<8)
#define	LTDC_L1CLUTWR_BLUE		(0xFFu<<0)
#define	LTDC_L1CLUTWR_BLUE_0	(0x1u<<0)

// L1CYR0R Configuration

#define	LTDC_L1CYR0R_CB2B		(0x3FFu<<16)
#define	LTDC_L1CYR0R_CB2B_0		(0x1u<<16)
#define	LTDC_L1CYR0R_CR2R		(0x3FFu<<0)
#define	LTDC_L1CYR0R_CR2R_0		(0x1u<<0)

// L1CYR1R Configuration

#define	LTDC_L1CYR1R_CB2G		(0x3FFu<<16)
#define	LTDC_L1CYR1R_CB2G_0		(0x1u<<16)
#define	LTDC_L1CYR1R_CR2G		(0x3FFu<<0)
#define	LTDC_L1CYR1R_CR2G_0		(0x1u<<0)

// L1FPF0R Configuration

#define	LTDC_L1FPF0R_RLEN		(0xFu<<14)
#define	LTDC_L1FPF0R_RLEN_0		(0x1u<<14)
#define	LTDC_L1FPF0R_RPOS		(0x1Fu<<9)
#define	LTDC_L1FPF0R_RPOS_0		(0x1u<<9)
#define	LTDC_L1FPF0R_ALEN		(0xFu<<5)
#define	LTDC_L1FPF0R_ALEN_0		(0x1u<<5)
#define	LTDC_L1FPF0R_APOS		(0x1Fu<<0)
#define	LTDC_L1FPF0R_APOS_0		(0x1u<<0)

// L1FPF1R Configuration

#define	LTDC_L1FPF1R_PSIZE		(0x7u<<18)
#define	LTDC_L1FPF1R_PSIZE_0	(0x1u<<18)
#define	LTDC_L1FPF1R_BLEN		(0xFu<<14)
#define	LTDC_L1FPF1R_BLEN_0		(0x1u<<14)
#define	LTDC_L1FPF1R_BPOS		(0x1Fu<<9)
#define	LTDC_L1FPF1R_BPOS_0		(0x1u<<9)
#define	LTDC_L1FPF1R_GLEN		(0xFu<<5)
#define	LTDC_L1FPF1R_GLEN_0		(0x1u<<5)
#define	LTDC_L1FPF1R_GPOS		(0x1Fu<<0)
#define	LTDC_L1FPF1R_GPOS_0		(0x1u<<0)

// L2C0R Configuration

#define	LTDC_L2C0R_ARGB8888		(0x1u<<31)
#define	LTDC_L2C0R_ABGR8888		(0x1u<<30)
#define	LTDC_L2C0R_RGBA8888		(0x1u<<29)
#define	LTDC_L2C0R_BGRA888		(0x1u<<28)
#define	LTDC_L2C0R_RGB565		(0x1u<<27)
#define	LTDC_L2C0R_BGR565		(0x1u<<26)
#define	LTDC_L2C0R_RGB888		(0x1u<<25)
#define	LTDC_L2C0R_FF			(0x1u<<24)
#define	LTDC_L2C0R_F11PC		(0x1u<<23)
#define	LTDC_L2C0R_F1PC			(0x1u<<22)
#define	LTDC_L2C0R_F11C			(0x1u<<21)
#define	LTDC_L2C0R_F1C			(0x1u<<20)
#define	LTDC_L2C0R_F11P			(0x1u<<19)
#define	LTDC_L2C0R_F1P			(0x1u<<18)
#define	LTDC_L2C0R_F10			(0x1u<<17)
#define	LTDC_L2C0R_F11			(0x1u<<16)
#define	LTDC_L2C0R_F21PC		(0x1u<<15)
#define	LTDC_L2C0R_F2PC			(0x1u<<14)
#define	LTDC_L2C0R_F21C			(0x1u<<13)
#define	LTDC_L2C0R_F2C			(0x1u<<12)
#define	LTDC_L2C0R_F21P			(0x1u<<11)
#define	LTDC_L2C0R_F2P			(0x1u<<10)
#define	LTDC_L2C0R_F20			(0x1u<<9)
#define	LTDC_L2C0R_F21			(0x1u<<8)
#define	LTDC_L2C0R_CKRA			(0x1u<<7)
#define	LTDC_L2C0R_CLUTA		(0x1u<<6)
#define	LTDC_L2C0R_WINA			(0x1u<<5)
#define	LTDC_L2C0R_DCP			(0x1u<<4)
#define	LTDC_L2C0R_APA			(0x1u<<3)
#define	LTDC_L2C0R_CFBPA		(0x1u<<2)
#define	LTDC_L2C0R_CFBDA		(0x1u<<1)
#define	LTDC_L2C0R_CKTA			(0x1u<<0)

// L2C1R Configuration

#define	LTDC_L2C1R_SCA			(0x1u<<31)
#define	LTDC_L2C1R_YFPA			(0x1u<<2)
#define	LTDC_L2C1R_YSPA			(0x1u<<1)
#define	LTDC_L2C1R_YIA			(0x1u<<0)

#define	LTDC_L2C1R_SCA_B_0X0	(0x0u<<31)
#define	LTDC_L2C1R_SCA_B_0X1	(0x1u<<31)
#define	LTDC_L2C1R_YFPA_B_0X0	(0x0u<<2)
#define	LTDC_L2C1R_YFPA_B_0X1	(0x1u<<2)
#define	LTDC_L2C1R_YSPA_B_0X0	(0x0u<<1)
#define	LTDC_L2C1R_YSPA_B_0X1	(0x1u<<1)
#define	LTDC_L2C1R_YIA_B_0X0	(0x0u<<0)
#define	LTDC_L2C1R_YIA_B_0X1	(0x1u<<0)

// L2RCR Configuration

#define	LTDC_L2RCR_GRMSK		(0x1u<<2)
#define	LTDC_L2RCR_VBR			(0x1u<<1)
#define	LTDC_L2RCR_IMR			(0x1u<<0)

#define	LTDC_L2RCR_GRMSK_B_0X0	(0x0u<<2)
#define	LTDC_L2RCR_GRMSK_B_0X1	(0x1u<<2)
#define	LTDC_L2RCR_VBR_B_0X0	(0x0u<<1)
#define	LTDC_L2RCR_VBR_B_0X1	(0x1u<<1)
#define	LTDC_L2RCR_IMR_B_0X0	(0x0u<<0)
#define	LTDC_L2RCR_IMR_B_0X1	(0x1u<<0)

// L2CR Configuration

#define	LTDC_L2CR_DCBEN			(0x1u<<9)
#define	LTDC_L2CR_HMEN			(0x1u<<8)
#define	LTDC_L2CR_CLUTEN		(0x1u<<4)
#define	LTDC_L2CR_CKEN			(0x1u<<1)
#define	LTDC_L2CR_LEN			(0x1u<<0)

#define	LTDC_L2CR_DCBEN_B_0X0	(0x0u<<9)
#define	LTDC_L2CR_DCBEN_B_0X1	(0x1u<<9)
#define	LTDC_L2CR_HMEN_B_0X0	(0x0u<<8)
#define	LTDC_L2CR_HMEN_B_0X1	(0x1u<<8)
#define	LTDC_L2CR_CLUTEN_B_0X0	(0x0u<<4)
#define	LTDC_L2CR_CLUTEN_B_0X1	(0x1u<<4)
#define	LTDC_L2CR_CKEN_B_0X0	(0x0u<<1)
#define	LTDC_L2CR_CKEN_B_0X1	(0x1u<<1)
#define	LTDC_L2CR_LEN_B_0X0		(0x0u<<0)
#define	LTDC_L2CR_LEN_B_0X1		(0x1u<<0)

// L2WHPCR Configuration

#define	LTDC_L2WHPCR_WHSPPOS	(0xFFFFu<<16)
#define	LTDC_L2WHPCR_WHSPPOS_0	(0x1u<<16)
#define	LTDC_L2WHPCR_WHSTPOS	(0xFFFFu<<0)
#define	LTDC_L2WHPCR_WHSTPOS_0	(0x1u<<0)

// L2WVPCR Configuration

#define	LTDC_L2WVPCR_WVSPPOS	(0xFFFFu<<16)
#define	LTDC_L2WVPCR_WVSPPOS_0	(0x1u<<16)
#define	LTDC_L2WVPCR_WVSTPOS	(0xFFFFu<<0)
#define	LTDC_L2WVPCR_WVSTPOS_0	(0x1u<<0)

// L2CKCR Configuration

#define	LTDC_L2CKCR_CKRED		(0xFFu<<16)
#define	LTDC_L2CKCR_CKRED_0		(0x1u<<16)
#define	LTDC_L2CKCR_CKGREEN		(0xFFu<<8)
#define	LTDC_L2CKCR_CKGREEN_0	(0x1u<<8)
#define	LTDC_L2CKCR_CKBLUE		(0xFFu<<0)
#define	LTDC_L2CKCR_CKBLUE_0	(0x1u<<0)

// L2PFCR Configuration

#define	LTDC_L2PFCR_PF			(0x7u<<0)
#define	LTDC_L2PFCR_PF_0		(0x1u<<0)

#define	LTDC_L2PFCR_PF_B_0X0	(0x0u<<0)
#define	LTDC_L2PFCR_PF_B_0X1	(0x1u<<0)
#define	LTDC_L2PFCR_PF_B_0X2	(0x2u<<0)
#define	LTDC_L2PFCR_PF_B_0X3	(0x3u<<0)
#define	LTDC_L2PFCR_PF_B_0X4	(0x4u<<0)
#define	LTDC_L2PFCR_PF_B_0X5	(0x5u<<0)
#define	LTDC_L2PFCR_PF_B_0X6	(0x6u<<0)
#define	LTDC_L2PFCR_PF_B_0X7	(0x7u<<0)

// L2CACR Configuration

#define	LTDC_L2CACR_CONSTA		(0xFFu<<0)
#define	LTDC_L2CACR_CONSTA_0	(0x1u<<0)

// L2DCCR Configuration

#define	LTDC_L2DCCR_DCALPHA		(0xFFu<<24)
#define	LTDC_L2DCCR_DCALPHA_0	(0x1u<<24)
#define	LTDC_L2DCCR_DCRED		(0xFFu<<16)
#define	LTDC_L2DCCR_DCRED_0		(0x1u<<16)
#define	LTDC_L2DCCR_DCGREEN		(0xFFu<<8)
#define	LTDC_L2DCCR_DCGREEN_0	(0x1u<<8)
#define	LTDC_L2DCCR_DCBLUE		(0xFFu<<0)
#define	LTDC_L2DCCR_DCBLUE_0	(0x1u<<0)

// L2BFCR Configuration

#define	LTDC_L2BFCR_BOR			(0x1u<<16)
#define	LTDC_L2BFCR_BF1			(0x7u<<8)
#define	LTDC_L2BFCR_BF1_0		(0x1u<<8)
#define	LTDC_L2BFCR_BF2			(0x7u<<0)
#define	LTDC_L2BFCR_BF2_0		(0x1u<<0)

#define	LTDC_L2BFCR_BOR_B_0X0	(0x0u<<16)
#define	LTDC_L2BFCR_BOR_B_0X1	(0x1u<<16)
#define	LTDC_L2BFCR_BF1_B_0X4	(0x4u<<8)
#define	LTDC_L2BFCR_BF1_B_0X6	(0x6u<<8)
#define	LTDC_L2BFCR_BF2_B_0X5	(0x5u<<0)
#define	LTDC_L2BFCR_BF2_B_0X7	(0x7u<<0)

// L2BLCR Configuration

#define	LTDC_L2BLCR_BL			(0xFFu<<0)
#define	LTDC_L2BLCR_BL_0		(0x1u<<0)

#define	LTDC_L2BLCR_BL_B_0X00	(0x0u<<0)
#define	LTDC_L2BLCR_BL_B_0X01	(0x1u<<0)
#define	LTDC_L2BLCR_BL_B_0X10	(0x10u<<0)

// L2PCR Configuration

#define	LTDC_L2PCR_YREN			(0x1u<<9)
#define	LTDC_L2PCR_OF			(0x1u<<8)
#define	LTDC_L2PCR_CBF			(0x1u<<7)
#define	LTDC_L2PCR_YF			(0x1u<<6)
#define	LTDC_L2PCR_YCM			(0x3u<<4)
#define	LTDC_L2PCR_YCM_0		(0x1u<<4)
#define	LTDC_L2PCR_YCEN			(0x1u<<3)

#define	LTDC_L2PCR_YREN_B_0X0	(0x0u<<9)
#define	LTDC_L2PCR_YREN_B_0X1	(0x1u<<9)
#define	LTDC_L2PCR_OF_B_0X0		(0x0u<<8)
#define	LTDC_L2PCR_OF_B_0X1		(0x1u<<8)
#define	LTDC_L2PCR_CBF_B_0X0	(0x0u<<7)
#define	LTDC_L2PCR_CBF_B_0X1	(0x1u<<7)
#define	LTDC_L2PCR_YF_B_0X0		(0x0u<<6)
#define	LTDC_L2PCR_YF_B_0X1		(0x1u<<6)
#define	LTDC_L2PCR_YCM_B_0X0	(0x0u<<4)
#define	LTDC_L2PCR_YCM_B_0X1	(0x1u<<4)
#define	LTDC_L2PCR_YCM_B_0X2	(0x2u<<4)
#define	LTDC_L2PCR_YCEN_B_0X0	(0x0u<<3)
#define	LTDC_L2PCR_YCEN_B_0X1	(0x1u<<3)

// L2CFBAR Configuration

#define	LTDC_L2CFBAR_CFBADD		(0xFFFFFFFFu<<0)
#define	LTDC_L2CFBAR_CFBADD_0	(0x1u<<0)

// L2CFBLR Configuration

#define	LTDC_L2CFBLR_CFBP		(0xFFFFu<<16)
#define	LTDC_L2CFBLR_CFBP_0		(0x1u<<16)
#define	LTDC_L2CFBLR_CFBLL		(0xFFFFu<<0)
#define	LTDC_L2CFBLR_CFBLL_0	(0x1u<<0)

// L2CFBLNR Configuration

#define	LTDC_L2CFBLNR_CFBLNBR	(0xFFFFu<<0)
#define	LTDC_L2CFBLNR_CFBLNBR_0	(0x1u<<0)

// L2CLUTWR Configuration

#define	LTDC_L2CLUTWR_CLUTADD	(0xFFu<<24)
#define	LTDC_L2CLUTWR_CLUTADD_0	(0x1u<<24)
#define	LTDC_L2CLUTWR_RED		(0xFFu<<16)
#define	LTDC_L2CLUTWR_RED_0		(0x1u<<16)
#define	LTDC_L2CLUTWR_GREEN		(0xFFu<<8)
#define	LTDC_L2CLUTWR_GREEN_0	(0x1u<<8)
#define	LTDC_L2CLUTWR_BLUE		(0xFFu<<0)
#define	LTDC_L2CLUTWR_BLUE_0	(0x1u<<0)

// L2CYR0R Configuration

#define	LTDC_L2CYR0R_CB2B		(0x3FFu<<16)
#define	LTDC_L2CYR0R_CB2B_0		(0x1u<<16)
#define	LTDC_L2CYR0R_CR2R		(0x3FFu<<0)
#define	LTDC_L2CYR0R_CR2R_0		(0x1u<<0)

// L2CYR1R Configuration

#define	LTDC_L2CYR1R_CB2G		(0x3FFu<<16)
#define	LTDC_L2CYR1R_CB2G_0		(0x1u<<16)
#define	LTDC_L2CYR1R_CR2G		(0x3FFu<<0)
#define	LTDC_L2CYR1R_CR2G_0		(0x1u<<0)

// L2FPF0R Configuration

#define	LTDC_L2FPF0R_RLEN		(0xFu<<14)
#define	LTDC_L2FPF0R_RLEN_0		(0x1u<<14)
#define	LTDC_L2FPF0R_RPOS		(0x1Fu<<9)
#define	LTDC_L2FPF0R_RPOS_0		(0x1u<<9)
#define	LTDC_L2FPF0R_ALEN		(0xFu<<5)
#define	LTDC_L2FPF0R_ALEN_0		(0x1u<<5)
#define	LTDC_L2FPF0R_APOS		(0x1Fu<<0)
#define	LTDC_L2FPF0R_APOS_0		(0x1u<<0)

// L2FPF1R Configuration

#define	LTDC_L2FPF1R_PSIZE		(0x7u<<18)
#define	LTDC_L2FPF1R_PSIZE_0	(0x1u<<18)
#define	LTDC_L2FPF1R_BLEN		(0xFu<<14)
#define	LTDC_L2FPF1R_BLEN_0		(0x1u<<14)
#define	LTDC_L2FPF1R_BPOS		(0x1Fu<<9)
#define	LTDC_L2FPF1R_BPOS_0		(0x1u<<9)
#define	LTDC_L2FPF1R_GLEN		(0xFu<<5)
#define	LTDC_L2FPF1R_GLEN_0		(0x1u<<5)
#define	LTDC_L2FPF1R_GPOS		(0x1Fu<<0)
#define	LTDC_L2FPF1R_GPOS_0		(0x1u<<0)
