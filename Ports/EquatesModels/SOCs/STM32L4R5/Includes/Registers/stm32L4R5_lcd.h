/*
; stm32L4R5_lcd.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_lcd equates.
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

// LCD address definitions
// -----------------------

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
	volatile	uint32_t	RESERVED8;
	volatile	uint32_t	L2BFCR;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	L2CFBAR;
	volatile	uint32_t	L2CFBLR;
	volatile	uint32_t	L2CFBLNR;
	volatile	uint32_t	RESERVED10[3];
	volatile	uint32_t	L2CLUTWR;
} LCD_TypeDef;

#if (defined(__cplusplus))
#define	LTCD	reinterpret_cast<LCD_TypeDef *>(0x40016800u)

#else
#define	LTCD	((LCD_TypeDef *)0x40016800u)
#endif

// SSCR Configuration

#define	LCD_SSCR_HSW			(0xFFFu<<16)
#define	LCD_SSCR_HSW_0			(0x1u<<16)
#define	LCD_SSCR_VSH			(0x7FFu<<0)
#define	LCD_SSCR_VSH_0			(0x1u<<0)

// BPCR Configuration

#define	LCD_BPCR_AHBP			(0xFFFu<<16)
#define	LCD_BPCR_AHBP_0			(0x1u<<16)
#define	LCD_BPCR_AVBP			(0x7FFu<<0)
#define	LCD_BPCR_AVBP_0			(0x1u<<0)

// AWCR Configuration

#define	LCD_AWCR_AAW			(0xFFFu<<16)
#define	LCD_AWCR_AAW_0			(0x1u<<16)
#define	LCD_AWCR_AAH			(0x7FFu<<0)
#define	LCD_AWCR_AAH_0			(0x1u<<0)

// TWCR Configuration

#define	LCD_TWCR_TOTALW			(0xFFFu<<16)
#define	LCD_TWCR_TOTALW_0		(0x1u<<16)
#define	LCD_TWCR_TOTALH			(0x7FFu<<0)
#define	LCD_TWCR_TOTALH_0		(0x1u<<0)

// GCR Configuration

#define	LCD_GCR_HSPOL			(0x1u<<31)
#define	LCD_GCR_VSPOL			(0x1u<<30)
#define	LCD_GCR_DEPOL			(0x1u<<29)
#define	LCD_GCR_PCPOL			(0x1u<<28)
#define	LCD_GCR_DEN				(0x1u<<16)
#define	LCD_GCR_DRW				(0x7u<<12)
#define	LCD_GCR_DRW_0			(0x1u<<12)
#define	LCD_GCR_DGW				(0x7u<<8)
#define	LCD_GCR_DGW_0			(0x1u<<8)
#define	LCD_GCR_DBW				(0x7u<<4)
#define	LCD_GCR_DBW_0			(0x1u<<4)
#define	LCD_GCR_LTDCEN			(0x1u<<0)

// SRCR Configuration

#define	LCD_SRCR_VBR			(0x1u<<1)
#define	LCD_SRCR_IMR			(0x1u<<0)

// BCCR Configuration

#define	LCD_BCCR_BCRED			(0xFFu<<16)
#define	LCD_BCCR_BCRED_0		(0x1u<<16)
#define	LCD_BCCR_BCGREEN		(0xFFu<<8)
#define	LCD_BCCR_BCGREEN_0		(0x1u<<8)
#define	LCD_BCCR_BCBLUE			(0xFFu<<0)
#define	LCD_BCCR_BCBLUE_0		(0x1u<<0)

// IER Configuration

#define	LCD_IER_RRIE			(0x1u<<3)
#define	LCD_IER_TERRIE			(0x1u<<2)
#define	LCD_IER_FUIE			(0x1u<<1)
#define	LCD_IER_LIE				(0x1u<<0)

// ISR Configuration

#define	LCD_ISR_RRIF			(0x1u<<3)
#define	LCD_ISR_TERRIF			(0x1u<<2)
#define	LCD_ISR_FUIF			(0x1u<<1)
#define	LCD_ISR_LIF				(0x1u<<0)

// ICR Configuration

#define	LCD_ICR_CRRIF			(0x1u<<3)
#define	LCD_ICR_CTERRIF			(0x1u<<2)
#define	LCD_ICR_CFUIF			(0x1u<<1)
#define	LCD_ICR_CLIF			(0x1u<<0)

// LIPCR Configuration

#define	LCD_LIPCR_LIPOS			(0x7FFu<<0)
#define	LCD_LIPCR_LIPOS_0		(0x1u<<0)

// CPSR Configuration

#define	LCD_CPSR_CXPOS			(0xFFFFu<<16)
#define	LCD_CPSR_CXPOS_0		(0x1u<<16)
#define	LCD_CPSR_CYPOS			(0xFFFFu<<0)
#define	LCD_CPSR_CYPOS_0		(0x1u<<0)

// CDSR Configuration

#define	LCD_CDSR_HSYNCS			(0x1u<<3)
#define	LCD_CDSR_VSYNCS			(0x1u<<2)
#define	LCD_CDSR_HDES			(0x1u<<1)
#define	LCD_CDSR_VDES			(0x1u<<0)

// L1CR Configuration

#define	LCD_L1CR_CLUTEN			(0x1u<<4)
#define	LCD_L1CR_COLKEN			(0x1u<<1)
#define	LCD_L1CR_LEN			(0x1u<<0)

// L1WHPCR Configuration

#define	LCD_L1WHPCR_WHSPPOS		(0xFFFu<<16)
#define	LCD_L1WHPCR_WHSPPOS_0	(0x1u<<16)
#define	LCD_L1WHPCR_WHSTPOS		(0xFFFu<<0)
#define	LCD_L1WHPCR_WHSTPOS_0	(0x1u<<0)

// L1WVPCR Configuration

#define	LCD_L1WVPCR_WVSPPOS		(0x7FFu<<16)
#define	LCD_L1WVPCR_WVSPPOS_0	(0x1u<<16)
#define	LCD_L1WVPCR_WVSTPOS		(0x7FFu<<0)
#define	LCD_L1WVPCR_WVSTPOS_0	(0x1u<<0)

// L1CKCR Configuration

#define	LCD_L1CKCR_CKRED		(0xFFu<<16)
#define	LCD_L1CKCR_CKRED_0		(0x1u<<16)
#define	LCD_L1CKCR_CKGREEN		(0xFFu<<8)
#define	LCD_L1CKCR_CKGREEN_0	(0x1u<<8)
#define	LCD_L1CKCR_CKBLUE		(0xFFu<<0)
#define	LCD_L1CKCR_CKBLUE_0		(0x1u<<0)

// L1PFCR Configuration

#define	LCD_L1PFCR_PF			(0x7u<<0)
#define	LCD_L1PFCR_PF_0			(0x1u<<0)

// L1CACR Configuration

#define	LCD_L1CACR_CONSTA		(0xFFu<<0)
#define	LCD_L1CACR_CONSTA_0		(0x1u<<0)

// L1DCCR Configuration

#define	LCD_L1DCCR_DCALPHA		(0xFFu<<24)
#define	LCD_L1DCCR_DCALPHA_0	(0x1u<<24)
#define	LCD_L1DCCR_DCRED		(0xFFu<<16)
#define	LCD_L1DCCR_DCRED_0		(0x1u<<16)
#define	LCD_L1DCCR_DCGREEN		(0xFFu<<8)
#define	LCD_L1DCCR_DCGREEN_0	(0x1u<<8)
#define	LCD_L1DCCR_DCBLUE		(0xFFu<<0)
#define	LCD_L1DCCR_DCBLUE_0		(0x1u<<0)

// L1BFCR Configuration

#define	LCD_L1BFCR_BF1			(0x7u<<8)
#define	LCD_L1BFCR_BF1_0		(0x1u<<8)
#define	LCD_L1BFCR_BF2			(0x7u<<0)
#define	LCD_L1BFCR_BF2_0		(0x1u<<0)

// L1CFBAR Configuration

#define	LCD_L1CFBAR_CFBADD		(0xFFFFFFFFu<<0)
#define	LCD_L1CFBAR_CFBADD_0	(0x1u<<0)

// L1CFBLR Configuration

#define	LCD_L1CFBLR_CFBP		(0x1FFFu<<16)
#define	LCD_L1CFBLR_CFBP_0		(0x1u<<16)
#define	LCD_L1CFBLR_CFBLL		(0x1FFFu<<0)
#define	LCD_L1CFBLR_CFBLL_0		(0x1u<<0)

// L1CFBLNR Configuration

#define	LCD_L1CFBLNR_CFBLNBR	(0x7FFu<<0)
#define	LCD_L1CFBLNR_CFBLNBR_0	(0x1u<<0)

// L1CLUTWR Configuration

#define	LCD_L1CLUTWR_CLUTADD	(0xFFu<<24)
#define	LCD_L1CLUTWR_CLUTADD_0	(0x1u<<24)
#define	LCD_L1CLUTWR_RED		(0xFFu<<16)
#define	LCD_L1CLUTWR_RED_0		(0x1u<<16)
#define	LCD_L1CLUTWR_GREEN		(0xFFu<<8)
#define	LCD_L1CLUTWR_GREEN_0	(0x1u<<8)
#define	LCD_L1CLUTWR_BLUE		(0xFFu<<0)
#define	LCD_L1CLUTWR_BLUE_0		(0x1u<<0)

// L2CR Configuration

#define	LCD_L2CR_CLUTEN			(0x1u<<4)
#define	LCD_L2CR_COLKEN			(0x1u<<1)
#define	LCD_L2CR_LEN			(0x1u<<0)

// L2WHPCR Configuration

#define	LCD_L2WHPCR_WHSPPOS		(0xFFFu<<16)
#define	LCD_L2WHPCR_WHSPPOS_0	(0x1u<<16)
#define	LCD_L2WHPCR_WHSTPOS		(0xFFFu<<0)
#define	LCD_L2WHPCR_WHSTPOS_0	(0x1u<<0)

// L2WVPCR Configuration

#define	LCD_L2WVPCR_WVSPPOS		(0x7FFu<<16)
#define	LCD_L2WVPCR_WVSPPOS_0	(0x1u<<16)
#define	LCD_L2WVPCR_WVSTPOS		(0x7FFu<<0)
#define	LCD_L2WVPCR_WVSTPOS_0	(0x1u<<0)

// L2CKCR Configuration

#define	LCD_L2CKCR_CKRED		(0xFFu<<16)
#define	LCD_L2CKCR_CKRED_0		(0x1u<<16)
#define	LCD_L2CKCR_CKGREEN		(0xFFu<<8)
#define	LCD_L2CKCR_CKGREEN_0	(0x1u<<8)
#define	LCD_L2CKCR_CKBLUE		(0xFFu<<0)
#define	LCD_L2CKCR_CKBLUE_0		(0x1u<<0)

// L2PFCR Configuration

#define	LCD_L2PFCR_PF			(0x7u<<0)
#define	LCD_L2PFCR_PF_0			(0x1u<<0)

// L2CACR Configuration

#define	LCD_L2CACR_CONSTA		(0xFFu<<0)
#define	LCD_L2CACR_CONSTA_0		(0x1u<<0)

// L2DCCR Configuration

#define	LCD_L2DCCR_DCALPHA		(0xFFu<<24)
#define	LCD_L2DCCR_DCALPHA_0	(0x1u<<24)
#define	LCD_L2DCCR_DCRED		(0xFFu<<16)
#define	LCD_L2DCCR_DCRED_0		(0x1u<<16)
#define	LCD_L2DCCR_DCGREEN		(0xFFu<<8)
#define	LCD_L2DCCR_DCGREEN_0	(0x1u<<8)
#define	LCD_L2DCCR_DCBLUE		(0xFFu<<0)
#define	LCD_L2DCCR_DCBLUE_0		(0x1u<<0)

// L2BFCR Configuration

#define	LCD_L2BFCR_BF1			(0x7u<<8)
#define	LCD_L2BFCR_BF1_0		(0x1u<<8)
#define	LCD_L2BFCR_BF2			(0x7u<<0)
#define	LCD_L2BFCR_BF2_0		(0x1u<<0)

// L2CFBAR Configuration

#define	LCD_L2CFBAR_CFBADD		(0xFFFFFFFFu<<0)
#define	LCD_L2CFBAR_CFBADD_0	(0x1u<<0)

// L2CFBLR Configuration

#define	LCD_L2CFBLR_CFBP		(0x1FFFu<<16)
#define	LCD_L2CFBLR_CFBP_0		(0x1u<<16)
#define	LCD_L2CFBLR_CFBLL		(0x1FFFu<<0)
#define	LCD_L2CFBLR_CFBLL_0		(0x1u<<0)

// L2CFBLNR Configuration

#define	LCD_L2CFBLNR_CFBLNBR	(0x7FFu<<0)
#define	LCD_L2CFBLNR_CFBLNBR_0	(0x1u<<0)

// L2CLUTWR Configuration

#define	LCD_L2CLUTWR_CLUTADD	(0xFFu<<24)
#define	LCD_L2CLUTWR_CLUTADD_0	(0x1u<<24)
#define	LCD_L2CLUTWR_RED		(0xFFu<<16)
#define	LCD_L2CLUTWR_RED_0		(0x1u<<16)
#define	LCD_L2CLUTWR_GREEN		(0xFFu<<8)
#define	LCD_L2CLUTWR_GREEN_0	(0x1u<<8)
#define	LCD_L2CLUTWR_BLUE		(0xFFu<<0)
#define	LCD_L2CLUTWR_BLUE_0		(0x1u<<0)
