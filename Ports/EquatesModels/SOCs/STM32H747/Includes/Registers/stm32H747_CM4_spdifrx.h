/*
; stm32H747_CM4_spdifrx.
; ======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM4_spdifrx equates.
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

// SPDIFRX address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	IMR;
	volatile	uint32_t	SR;
	volatile	uint32_t	IFCR;
		union {
	volatile	uint32_t	DR_00;
	volatile	uint32_t	DR_01;
	volatile	uint32_t	DR_10;
		};
	volatile	uint32_t	CSR;
	volatile	uint32_t	DIR;
	volatile	uint32_t	RESERVED0[246];
	volatile	uint32_t	VERR;
	volatile	uint32_t	IDR;
	volatile	uint32_t	SIDR;
} SPDIFRX_TypeDef;

#if (defined(__cplusplus))
#define	SPDIFRX	reinterpret_cast<SPDIFRX_TypeDef *>(0x40004000u)

#else
#define	SPDIFRX	((SPDIFRX_TypeDef *)0x40004000u)
#endif

// CR Configuration

#define	SPDIFRX_CR_CKSBKPEN		(0x1u<<21)
#define	SPDIFRX_CR_CKSEN		(0x1u<<20)
#define	SPDIFRX_CR_INSEL		(0x7u<<16)
#define	SPDIFRX_CR_INSEL_0		(0x1u<<16)
#define	SPDIFRX_CR_WFA			(0x1u<<14)
#define	SPDIFRX_CR_NBTR			(0x3u<<12)
#define	SPDIFRX_CR_NBTR_0		(0x1u<<12)
#define	SPDIFRX_CR_CHSEL		(0x1u<<11)
#define	SPDIFRX_CR_CBDMAEN		(0x1u<<10)
#define	SPDIFRX_CR_PTMSK		(0x1u<<9)
#define	SPDIFRX_CR_CUMSK		(0x1u<<8)
#define	SPDIFRX_CR_VMSK			(0x1u<<7)
#define	SPDIFRX_CR_PMSK			(0x1u<<6)
#define	SPDIFRX_CR_DRFMT		(0x3u<<4)
#define	SPDIFRX_CR_DRFMT_0		(0x1u<<4)
#define	SPDIFRX_CR_RXSTEO		(0x1u<<3)
#define	SPDIFRX_CR_RXDMAEN		(0x1u<<2)
#define	SPDIFRX_CR_SPDIFRXEN	(0x3u<<0)
#define	SPDIFRX_CR_SPDIFRXEN_0	(0x1u<<0)

// IMR Configuration

#define	SPDIFRX_IMR_IFEIE		(0x1u<<6)
#define	SPDIFRX_IMR_SYNCDIE		(0x1u<<5)
#define	SPDIFRX_IMR_SBLKIE		(0x1u<<4)
#define	SPDIFRX_IMR_OVRIE		(0x1u<<3)
#define	SPDIFRX_IMR_PERRIE		(0x1u<<2)
#define	SPDIFRX_IMR_CSRNEIE		(0x1u<<1)
#define	SPDIFRX_IMR_RXNEIE		(0x1u<<0)

// SR Configuration

#define	SPDIFRX_SR_WIDTH5		(0x7FFFu<<16)
#define	SPDIFRX_SR_WIDTH5_0		(0x1u<<16)
#define	SPDIFRX_SR_TERR			(0x1u<<8)
#define	SPDIFRX_SR_SERR			(0x1u<<7)
#define	SPDIFRX_SR_FERR			(0x1u<<6)
#define	SPDIFRX_SR_SYNCD		(0x1u<<5)
#define	SPDIFRX_SR_SBD			(0x1u<<4)
#define	SPDIFRX_SR_OVR			(0x1u<<3)
#define	SPDIFRX_SR_PERR			(0x1u<<2)
#define	SPDIFRX_SR_CSRNE		(0x1u<<1)
#define	SPDIFRX_SR_RXNE			(0x1u<<0)

// IFCR Configuration

#define	SPDIFRX_IFCR_SYNCDCF	(0x1u<<5)
#define	SPDIFRX_IFCR_SBDCF		(0x1u<<4)
#define	SPDIFRX_IFCR_OVRCF		(0x1u<<3)
#define	SPDIFRX_IFCR_PERRCF		(0x1u<<2)

// DR_00 Configuration

#define	SPDIFRX_DR_00_PT		(0x3u<<28)
#define	SPDIFRX_DR_00_PT_0		(0x1u<<28)
#define	SPDIFRX_DR_00_C			(0x1u<<27)
#define	SPDIFRX_DR_00_U			(0x1u<<26)
#define	SPDIFRX_DR_00_V			(0x1u<<25)
#define	SPDIFRX_DR_00_PE		(0x1u<<24)
#define	SPDIFRX_DR_00_DR		(0xFFFFFFu<<0)
#define	SPDIFRX_DR_00_DR_0		(0x1u<<0)

// DR_01 Configuration

#define	SPDIFRX_DR_01_DR		(0xFFFFFFu<<8)
#define	SPDIFRX_DR_01_DR_0		(0x1u<<8)
#define	SPDIFRX_DR_01_PT		(0x3u<<4)
#define	SPDIFRX_DR_01_PT_0		(0x1u<<4)
#define	SPDIFRX_DR_01_C			(0x1u<<3)
#define	SPDIFRX_DR_01_U			(0x1u<<2)
#define	SPDIFRX_DR_01_V			(0x1u<<1)
#define	SPDIFRX_DR_01_PE		(0x1u<<0)

// DR_10 Configuration

#define	SPDIFRX_DR_10_DRNL2		(0xFFFFu<<16)
#define	SPDIFRX_DR_10_DRNL2_0	(0x1u<<16)
#define	SPDIFRX_DR_10_DRNL1		(0xFFFFu<<0)
#define	SPDIFRX_DR_10_DRNL1_0	(0x1u<<0)

// CSR Configuration

#define	SPDIFRX_CSR_SOB			(0x1u<<24)
#define	SPDIFRX_CSR_CS			(0xFFu<<16)
#define	SPDIFRX_CSR_CS_0		(0x1u<<16)
#define	SPDIFRX_CSR_USR			(0xFFFFu<<0)
#define	SPDIFRX_CSR_USR_0		(0x1u<<0)

// DIR Configuration

#define	SPDIFRX_DIR_TLO			(0x1FFFu<<16)
#define	SPDIFRX_DIR_TLO_0		(0x1u<<16)
#define	SPDIFRX_DIR_THI			(0x1FFFu<<0)
#define	SPDIFRX_DIR_THI_0		(0x1u<<0)

// VERR Configuration

#define	SPDIFRX_VERR_MAJREV		(0xFu<<4)
#define	SPDIFRX_VERR_MAJREV_0	(0x1u<<4)
#define	SPDIFRX_VERR_MINREV		(0xFu<<0)
#define	SPDIFRX_VERR_MINREV_0	(0x1u<<0)

// IDR Configuration

#define	SPDIFRX_IDR_ID			(0xFFFFFFFFu<<0)
#define	SPDIFRX_IDR_ID_0		(0x1u<<0)

// SIDR Configuration

#define	SPDIFRX_SIDR_SID		(0xFFFFFFFFu<<0)
#define	SPDIFRX_SIDR_SID_0		(0x1u<<0)
