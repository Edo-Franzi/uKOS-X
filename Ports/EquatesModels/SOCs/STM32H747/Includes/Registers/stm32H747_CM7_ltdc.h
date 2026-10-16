/*
; stm32H747_CM7_ltdc.
; ===================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM7_ltdc equates.
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
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	SRCR;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	BCCR;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	IER;
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	LIPCR;
	volatile	uint32_t	CPSR;
	volatile	uint32_t	CDSR;
	volatile	uint32_t	RESERVED4[14];
	volatile	uint32_t	L1CR;
	volatile	uint32_t	L1WHPCR;
	volatile	uint32_t	L1WVPCR;
	volatile	uint32_t	L1CKCR;
	volatile	uint32_t	L1PFCR;
	volatile	uint32_t	L1CACR;
	volatile	uint32_t	L1DCCR;
	volatile	uint32_t	L1BFCR;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	L1CFBAR;
	volatile	uint32_t	L1CFBLR;
	volatile	uint32_t	L1CFBLNR;
	volatile	uint32_t	RESERVED6[3];
	volatile	uint32_t	L1CLUTWR;
	volatile	uint32_t	RESERVED7[15];
	volatile	uint32_t	L2CR;
	volatile	uint32_t	L2WHPCR;
	volatile	uint32_t	L2WVPCR;
	volatile	uint32_t	L2CKCR;
	volatile	uint32_t	L2PFCR;
	volatile	uint32_t	L2CACR;
	volatile	uint32_t	L2DCCR;
	volatile	uint32_t	L2BFCR;
	volatile	uint32_t	RESERVED8[2];
	volatile	uint32_t	L2CFBAR;
	volatile	uint32_t	L2CFBLR;
	volatile	uint32_t	L2CFBLNR;
	volatile	uint32_t	RESERVED9[3];
	volatile	uint32_t	L2CLUTWR;
} LTDC_TypeDef;

#if (defined(__cplusplus))
#define	LTDC	reinterpret_cast<LTDC_TypeDef *>(0x50001000u)

#else
#define	LTDC	((LTDC_TypeDef *)0x50001000u)
#endif

// SSCR Configuration

#define	LTDC_SSCR_VSH			(0x7FFu<<0)
#define	LTDC_SSCR_VSH_0			(0x1u<<0)
#define	LTDC_SSCR_HSW			(0x3FFu<<16)
#define	LTDC_SSCR_HSW_0			(0x1u<<16)

// BPCR Configuration

#define	LTDC_BPCR_AVBP			(0x7FFu<<0)
#define	LTDC_BPCR_AVBP_0		(0x1u<<0)
#define	LTDC_BPCR_AHBP			(0xFFFu<<16)
#define	LTDC_BPCR_AHBP_0		(0x1u<<16)

// AWCR Configuration

#define	LTDC_AWCR_AAH			(0x7FFu<<0)
#define	LTDC_AWCR_AAH_0			(0x1u<<0)
#define	LTDC_AWCR_AAV			(0xFFFu<<16)
#define	LTDC_AWCR_AAV_0			(0x1u<<16)

// TWCR Configuration

#define	LTDC_TWCR_TOTALH		(0x7FFu<<0)
#define	LTDC_TWCR_TOTALH_0		(0x1u<<0)
#define	LTDC_TWCR_TOTALW		(0xFFFu<<16)
#define	LTDC_TWCR_TOTALW_0		(0x1u<<16)

// GCR Configuration

#define	LTDC_GCR_LTDCEN			(0x1u<<0)
#define	LTDC_GCR_DBW			(0x7u<<4)
#define	LTDC_GCR_DBW_0			(0x1u<<4)
#define	LTDC_GCR_DGW			(0x7u<<8)
#define	LTDC_GCR_DGW_0			(0x1u<<8)
#define	LTDC_GCR_DRW			(0x7u<<12)
#define	LTDC_GCR_DRW_0			(0x1u<<12)
#define	LTDC_GCR_DEN			(0x1u<<16)
#define	LTDC_GCR_PCPOL			(0x1u<<28)
#define	LTDC_GCR_DEPOL			(0x1u<<29)
#define	LTDC_GCR_VSPOL			(0x1u<<30)
#define	LTDC_GCR_HSPOL			(0x1u<<31)

// SRCR Configuration

#define	LTDC_SRCR_IMR			(0x1u<<0)
#define	LTDC_SRCR_VBR			(0x1u<<1)

// BCCR Configuration

#define	LTDC_BCCR_BCRED			(0xFFu<<16)
#define	LTDC_BCCR_BCRED_0		(0x1u<<16)
#define	LTDC_BCCR_BCGREEN		(0xFFu<<8)
#define	LTDC_BCCR_BCGREEN_0		(0x1u<<8)
#define	LTDC_BCCR_BCBLUE		(0xFFu<<0)
#define	LTDC_BCCR_BCBLUE_0		(0x1u<<0)

// IER Configuration

#define	LTDC_IER_LIE			(0x1u<<0)
#define	LTDC_IER_FUIE			(0x1u<<1)
#define	LTDC_IER_TERRIE			(0x1u<<2)
#define	LTDC_IER_RRIE			(0x1u<<3)

// ISR Configuration

#define	LTDC_ISR_LIF			(0x1u<<0)
#define	LTDC_ISR_FUIF			(0x1u<<1)
#define	LTDC_ISR_TERRIF			(0x1u<<2)
#define	LTDC_ISR_RRIF			(0x1u<<3)

// ICR Configuration

#define	LTDC_ICR_CLIF			(0x1u<<0)
#define	LTDC_ICR_CFUIF			(0x1u<<1)
#define	LTDC_ICR_CTERRIF		(0x1u<<2)
#define	LTDC_ICR_CRRIF			(0x1u<<3)

// LIPCR Configuration

#define	LTDC_LIPCR_LIPOS		(0x7FFu<<0)
#define	LTDC_LIPCR_LIPOS_0		(0x1u<<0)

// CPSR Configuration

#define	LTDC_CPSR_CYPOS			(0xFFFFu<<0)
#define	LTDC_CPSR_CYPOS_0		(0x1u<<0)
#define	LTDC_CPSR_CXPOS			(0xFFFFu<<16)
#define	LTDC_CPSR_CXPOS_0		(0x1u<<16)

// CDSR Configuration

#define	LTDC_CDSR_VDES			(0x1u<<0)
#define	LTDC_CDSR_HDES			(0x1u<<1)
#define	LTDC_CDSR_VSYNCS		(0x1u<<2)
#define	LTDC_CDSR_HSYNCS		(0x1u<<3)

// L1CR Configuration

#define	LTDC_L1CR_LEN			(0x1u<<0)
#define	LTDC_L1CR_COLKEN		(0x1u<<1)
#define	LTDC_L1CR_CLUTEN		(0x1u<<4)

// L1WHPCR Configuration

#define	LTDC_L1WHPCR_WHSTPOS	(0xFFFu<<0)
#define	LTDC_L1WHPCR_WHSTPOS_0	(0x1u<<0)
#define	LTDC_L1WHPCR_WHSPPOS	(0xFFFu<<16)
#define	LTDC_L1WHPCR_WHSPPOS_0	(0x1u<<16)

// L1WVPCR Configuration

#define	LTDC_L1WVPCR_WVSTPOS	(0x7FFu<<0)
#define	LTDC_L1WVPCR_WVSTPOS_0	(0x1u<<0)
#define	LTDC_L1WVPCR_WVSPPOS	(0x7FFu<<16)
#define	LTDC_L1WVPCR_WVSPPOS_0	(0x1u<<16)

// L1CKCR Configuration

#define	LTDC_L1CKCR_CKBLUE		(0xFFu<<0)
#define	LTDC_L1CKCR_CKBLUE_0	(0x1u<<0)
#define	LTDC_L1CKCR_CKGREEN		(0xFFu<<8)
#define	LTDC_L1CKCR_CKGREEN_0	(0x1u<<8)
#define	LTDC_L1CKCR_CKRED		(0xFFu<<16)
#define	LTDC_L1CKCR_CKRED_0		(0x1u<<16)

// L1PFCR Configuration

#define	LTDC_L1PFCR_PF			(0x7u<<0)
#define	LTDC_L1PFCR_PF_0		(0x1u<<0)

// L1CACR Configuration

#define	LTDC_L1CACR_CONSTA		(0xFFu<<0)
#define	LTDC_L1CACR_CONSTA_0	(0x1u<<0)

// L1DCCR Configuration

#define	LTDC_L1DCCR_DCBLUE		(0xFFu<<0)
#define	LTDC_L1DCCR_DCBLUE_0	(0x1u<<0)
#define	LTDC_L1DCCR_DCGREEN		(0xFFu<<8)
#define	LTDC_L1DCCR_DCGREEN_0	(0x1u<<8)
#define	LTDC_L1DCCR_DCRED		(0xFFu<<16)
#define	LTDC_L1DCCR_DCRED_0		(0x1u<<16)
#define	LTDC_L1DCCR_DCALPHA		(0xFFu<<24)
#define	LTDC_L1DCCR_DCALPHA_0	(0x1u<<24)

// L1BFCR Configuration

#define	LTDC_L1BFCR_BF2			(0x7u<<0)
#define	LTDC_L1BFCR_BF2_0		(0x1u<<0)
#define	LTDC_L1BFCR_BF1			(0x7u<<8)
#define	LTDC_L1BFCR_BF1_0		(0x1u<<8)

// L1CFBAR Configuration

#define	LTDC_L1CFBAR_CFBADD		(0xFFFFFFFFu<<0)
#define	LTDC_L1CFBAR_CFBADD_0	(0x1u<<0)

// L1CFBLR Configuration

#define	LTDC_L1CFBLR_CFBLL		(0x1FFFu<<0)
#define	LTDC_L1CFBLR_CFBLL_0	(0x1u<<0)
#define	LTDC_L1CFBLR_CFBP		(0x1FFFu<<16)
#define	LTDC_L1CFBLR_CFBP_0		(0x1u<<16)

// L1CFBLNR Configuration

#define	LTDC_L1CFBLNR_CFBLNBR	(0x7FFu<<0)
#define	LTDC_L1CFBLNR_CFBLNBR_0	(0x1u<<0)

// L1CLUTWR Configuration

#define	LTDC_L1CLUTWR_BLUE		(0xFFu<<0)
#define	LTDC_L1CLUTWR_BLUE_0	(0x1u<<0)
#define	LTDC_L1CLUTWR_GREEN		(0xFFu<<8)
#define	LTDC_L1CLUTWR_GREEN_0	(0x1u<<8)
#define	LTDC_L1CLUTWR_RED		(0xFFu<<16)
#define	LTDC_L1CLUTWR_RED_0		(0x1u<<16)
#define	LTDC_L1CLUTWR_CLUTADD	(0xFFu<<24)
#define	LTDC_L1CLUTWR_CLUTADD_0	(0x1u<<24)

// L2CR Configuration

#define	LTDC_L2CR_LEN			(0x1u<<0)
#define	LTDC_L2CR_COLKEN		(0x1u<<1)
#define	LTDC_L2CR_CLUTEN		(0x1u<<4)

// L2WHPCR Configuration

#define	LTDC_L2WHPCR_WHSTPOS	(0xFFFu<<0)
#define	LTDC_L2WHPCR_WHSTPOS_0	(0x1u<<0)
#define	LTDC_L2WHPCR_WHSPPOS	(0xFFFu<<16)
#define	LTDC_L2WHPCR_WHSPPOS_0	(0x1u<<16)

// L2WVPCR Configuration

#define	LTDC_L2WVPCR_WVSTPOS	(0x7FFu<<0)
#define	LTDC_L2WVPCR_WVSTPOS_0	(0x1u<<0)
#define	LTDC_L2WVPCR_WVSPPOS	(0x7FFu<<16)
#define	LTDC_L2WVPCR_WVSPPOS_0	(0x1u<<16)

// L2CKCR Configuration

#define	LTDC_L2CKCR_CKBLUE		(0xFFu<<0)
#define	LTDC_L2CKCR_CKBLUE_0	(0x1u<<0)
#define	LTDC_L2CKCR_CKGREEN		(0xFFu<<8)
#define	LTDC_L2CKCR_CKGREEN_0	(0x1u<<8)
#define	LTDC_L2CKCR_CKRED		(0xFFu<<16)
#define	LTDC_L2CKCR_CKRED_0		(0x1u<<16)

// L2PFCR Configuration

#define	LTDC_L2PFCR_PF			(0x7u<<0)
#define	LTDC_L2PFCR_PF_0		(0x1u<<0)

// L2CACR Configuration

#define	LTDC_L2CACR_CONSTA		(0xFFu<<0)
#define	LTDC_L2CACR_CONSTA_0	(0x1u<<0)

// L2DCCR Configuration

#define	LTDC_L2DCCR_DCBLUE		(0xFFu<<0)
#define	LTDC_L2DCCR_DCBLUE_0	(0x1u<<0)
#define	LTDC_L2DCCR_DCGREEN		(0xFFu<<8)
#define	LTDC_L2DCCR_DCGREEN_0	(0x1u<<8)
#define	LTDC_L2DCCR_DCRED		(0xFFu<<16)
#define	LTDC_L2DCCR_DCRED_0		(0x1u<<16)
#define	LTDC_L2DCCR_DCALPHA		(0xFFu<<24)
#define	LTDC_L2DCCR_DCALPHA_0	(0x1u<<24)

// L2BFCR Configuration

#define	LTDC_L2BFCR_BF2			(0x7u<<0)
#define	LTDC_L2BFCR_BF2_0		(0x1u<<0)
#define	LTDC_L2BFCR_BF1			(0x7u<<8)
#define	LTDC_L2BFCR_BF1_0		(0x1u<<8)

// L2CFBAR Configuration

#define	LTDC_L2CFBAR_CFBADD		(0xFFFFFFFFu<<0)
#define	LTDC_L2CFBAR_CFBADD_0	(0x1u<<0)

// L2CFBLR Configuration

#define	LTDC_L2CFBLR_CFBLL		(0x1FFFu<<0)
#define	LTDC_L2CFBLR_CFBLL_0	(0x1u<<0)
#define	LTDC_L2CFBLR_CFBP		(0x1FFFu<<16)
#define	LTDC_L2CFBLR_CFBP_0		(0x1u<<16)

// L2CFBLNR Configuration

#define	LTDC_L2CFBLNR_CFBLNBR	(0x7FFu<<0)
#define	LTDC_L2CFBLNR_CFBLNBR_0	(0x1u<<0)

// L2CLUTWR Configuration

#define	LTDC_L2CLUTWR_BLUE		(0xFFu<<0)
#define	LTDC_L2CLUTWR_BLUE_0	(0x1u<<0)
#define	LTDC_L2CLUTWR_GREEN		(0xFFu<<8)
#define	LTDC_L2CLUTWR_GREEN_0	(0x1u<<8)
#define	LTDC_L2CLUTWR_RED		(0xFFu<<16)
#define	LTDC_L2CLUTWR_RED_0		(0x1u<<16)
#define	LTDC_L2CLUTWR_CLUTADD	(0xFFu<<24)
#define	LTDC_L2CLUTWR_CLUTADD_0	(0x1u<<24)
