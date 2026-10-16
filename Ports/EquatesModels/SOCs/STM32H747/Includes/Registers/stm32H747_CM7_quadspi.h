/*
; stm32H747_CM7_quadspi.
; ======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM7_quadspi equates.
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

// QUADSPI address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	DCR;
	volatile	uint32_t	SR;
	volatile	uint32_t	FCR;
	volatile	uint32_t	DLR;
	volatile	uint32_t	CCR;
	volatile	uint32_t	AR;
	volatile	uint32_t	ABR;
	volatile	uint32_t	DR;
	volatile	uint32_t	PSMKR;
	volatile	uint32_t	PSMAR;
	volatile	uint32_t	PIR;
	volatile	uint32_t	LPTR;
} QUADSPI_TypeDef;

#if (defined(__cplusplus))
#define	QUADSPI	reinterpret_cast<QUADSPI_TypeDef *>(0x52005000u)

#else
#define	QUADSPI	((QUADSPI_TypeDef *)0x52005000u)
#endif

// CR Configuration

#define	QUADSPI_CR_PRESCALER		(0xFFu<<24)
#define	QUADSPI_CR_PRESCALER_0		(0x1u<<24)
#define	QUADSPI_CR_PMM				(0x1u<<23)
#define	QUADSPI_CR_APMS				(0x1u<<22)
#define	QUADSPI_CR_TOIE				(0x1u<<20)
#define	QUADSPI_CR_SMIE				(0x1u<<19)
#define	QUADSPI_CR_FTIE				(0x1u<<18)
#define	QUADSPI_CR_TCIE				(0x1u<<17)
#define	QUADSPI_CR_TEIE				(0x1u<<16)
#define	QUADSPI_CR_FTHRES			(0x1Fu<<8)
#define	QUADSPI_CR_FTHRES_0			(0x1u<<8)
#define	QUADSPI_CR_FSEL				(0x1u<<7)
#define	QUADSPI_CR_DFM				(0x1u<<6)
#define	QUADSPI_CR_SSHIFT			(0x1u<<4)
#define	QUADSPI_CR_TCEN				(0x1u<<3)
#define	QUADSPI_CR_DMAEN			(0x1u<<2)
#define	QUADSPI_CR_ABORT			(0x1u<<1)
#define	QUADSPI_CR_EN				(0x1u<<0)

// DCR Configuration

#define	QUADSPI_DCR_FSIZE			(0x1Fu<<16)
#define	QUADSPI_DCR_FSIZE_0			(0x1u<<16)
#define	QUADSPI_DCR_CSHT			(0x7u<<8)
#define	QUADSPI_DCR_CSHT_0			(0x1u<<8)
#define	QUADSPI_DCR_CKMODE			(0x1u<<0)

// SR Configuration

#define	QUADSPI_SR_FLEVEL			(0x3Fu<<8)
#define	QUADSPI_SR_FLEVEL_0			(0x1u<<8)
#define	QUADSPI_SR_BUSY				(0x1u<<5)
#define	QUADSPI_SR_TOF				(0x1u<<4)
#define	QUADSPI_SR_SMF				(0x1u<<3)
#define	QUADSPI_SR_FTF				(0x1u<<2)
#define	QUADSPI_SR_TCF				(0x1u<<1)
#define	QUADSPI_SR_TEF				(0x1u<<0)

// FCR Configuration

#define	QUADSPI_FCR_CTOF			(0x1u<<4)
#define	QUADSPI_FCR_CSMF			(0x1u<<3)
#define	QUADSPI_FCR_CTCF			(0x1u<<1)
#define	QUADSPI_FCR_CTEF			(0x1u<<0)

// DLR Configuration

#define	QUADSPI_DLR_DL				(0xFFFFFFFFu<<0)
#define	QUADSPI_DLR_DL_0			(0x1u<<0)

// CCR Configuration

#define	QUADSPI_CCR_DDRM			(0x1u<<31)
#define	QUADSPI_CCR_DHHC			(0x1u<<30)
#define	QUADSPI_CCR_SIOO			(0x1u<<28)
#define	QUADSPI_CCR_FMODE			(0x3u<<26)
#define	QUADSPI_CCR_FMODE_0			(0x1u<<26)
#define	QUADSPI_CCR_DMODE			(0x3u<<24)
#define	QUADSPI_CCR_DMODE_0			(0x1u<<24)
#define	QUADSPI_CCR_DCYC			(0x1Fu<<18)
#define	QUADSPI_CCR_DCYC_0			(0x1u<<18)
#define	QUADSPI_CCR_ABSIZE			(0x3u<<16)
#define	QUADSPI_CCR_ABSIZE_0		(0x1u<<16)
#define	QUADSPI_CCR_ABMODE			(0x3u<<14)
#define	QUADSPI_CCR_ABMODE_0		(0x1u<<14)
#define	QUADSPI_CCR_ADSIZE			(0x3u<<12)
#define	QUADSPI_CCR_ADSIZE_0		(0x1u<<12)
#define	QUADSPI_CCR_ADMODE			(0x3u<<10)
#define	QUADSPI_CCR_ADMODE_0		(0x1u<<10)
#define	QUADSPI_CCR_IMODE			(0x3u<<8)
#define	QUADSPI_CCR_IMODE_0			(0x1u<<8)
#define	QUADSPI_CCR_INSTRUCTION		(0xFFu<<0)
#define	QUADSPI_CCR_INSTRUCTION_0	(0x1u<<0)

// AR Configuration

#define	QUADSPI_AR_ADDRESS			(0xFFFFFFFFu<<0)
#define	QUADSPI_AR_ADDRESS_0		(0x1u<<0)

// ABR Configuration

#define	QUADSPI_ABR_ALTERNATE		(0xFFFFFFFFu<<0)
#define	QUADSPI_ABR_ALTERNATE_0		(0x1u<<0)

// DR Configuration

#define	QUADSPI_DR_DATA				(0xFFFFFFFFu<<0)
#define	QUADSPI_DR_DATA_0			(0x1u<<0)

// PSMKR Configuration

#define	QUADSPI_PSMKR_MASK			(0xFFFFFFFFu<<0)
#define	QUADSPI_PSMKR_MASK_0		(0x1u<<0)

// PSMAR Configuration

#define	QUADSPI_PSMAR_MATCH			(0xFFFFFFFFu<<0)
#define	QUADSPI_PSMAR_MATCH_0		(0x1u<<0)

// PIR Configuration

#define	QUADSPI_PIR_INTERVAL		(0xFFFFu<<0)
#define	QUADSPI_PIR_INTERVAL_0		(0x1u<<0)

// LPTR Configuration

#define	QUADSPI_LPTR_TIMEOUT		(0xFFFFu<<0)
#define	QUADSPI_LPTR_TIMEOUT_0		(0x1u<<0)
