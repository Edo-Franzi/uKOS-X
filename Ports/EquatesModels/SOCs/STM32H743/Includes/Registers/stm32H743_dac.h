/*
; stm32H743_dac.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_dac equates.
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

// DAC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SWTRGR;
	volatile	uint32_t	DHR12R1;
	volatile	uint32_t	DHR12L1;
	volatile	uint32_t	DHR8R1;
	volatile	uint32_t	DHR12R2;
	volatile	uint32_t	DHR12L2;
	volatile	uint32_t	DHR8R2;
	volatile	uint32_t	DHR12RD;
	volatile	uint32_t	DHR12LD;
	volatile	uint32_t	DHR8RD;
	volatile	uint32_t	DOR1;
	volatile	uint32_t	DOR2;
	volatile	uint32_t	SR;
	volatile	uint32_t	CCR;
	volatile	uint32_t	MCR;
	volatile	uint32_t	SHSR1;
	volatile	uint32_t	SHSR2;
	volatile	uint32_t	SHHR;
	volatile	uint32_t	SHRR;
} DAC_TypeDef;

#if (defined(__cplusplus))
#define	DAC	reinterpret_cast<DAC_TypeDef *>(0x40007400u)

#else
#define	DAC	((DAC_TypeDef *)0x40007400u)
#endif

// CR Configuration

#define	DAC_CR_CEN2				(0x1u<<30)
#define	DAC_CR_DMAUDRIE2		(0x1u<<29)
#define	DAC_CR_DMAEN2			(0x1u<<28)
#define	DAC_CR_MAMP2			(0xFu<<24)
#define	DAC_CR_MAMP2_0			(0x1u<<24)
#define	DAC_CR_WAVE2			(0x3u<<22)
#define	DAC_CR_WAVE2_0			(0x1u<<22)
#define	DAC_CR_TSEL2			(0x7u<<18)
#define	DAC_CR_TSEL2_0			(0x1u<<18)
#define	DAC_CR_TEN2				(0x1u<<17)
#define	DAC_CR_EN2				(0x1u<<16)
#define	DAC_CR_CEN1				(0x1u<<14)
#define	DAC_CR_DMAUDRIE1		(0x1u<<13)
#define	DAC_CR_DMAEN1			(0x1u<<12)
#define	DAC_CR_MAMP1			(0xFu<<8)
#define	DAC_CR_MAMP1_0			(0x1u<<8)
#define	DAC_CR_WAVE1			(0x3u<<6)
#define	DAC_CR_WAVE1_0			(0x1u<<6)
#define	DAC_CR_TSEL1			(0x7u<<2)
#define	DAC_CR_TSEL1_0			(0x1u<<2)
#define	DAC_CR_TEN1				(0x1u<<1)
#define	DAC_CR_EN1				(0x1u<<0)

// SWTRGR Configuration

#define	DAC_SWTRGR_SWTRIG2		(0x1u<<1)
#define	DAC_SWTRGR_SWTRIG1		(0x1u<<0)

// DHR12R1 Configuration

#define	DAC_DHR12R1_DACC1DHR	(0xFFFu<<0)
#define	DAC_DHR12R1_DACC1DHR_0	(0x1u<<0)

// DHR12L1 Configuration

#define	DAC_DHR12L1_DACC1DHR	(0xFFFu<<4)
#define	DAC_DHR12L1_DACC1DHR_0	(0x1u<<4)

// DHR8R1 Configuration

#define	DAC_DHR8R1_DACC1DHR		(0xFFu<<0)
#define	DAC_DHR8R1_DACC1DHR_0	(0x1u<<0)

// DHR12R2 Configuration

#define	DAC_DHR12R2_DACC2DHR	(0xFFFu<<0)
#define	DAC_DHR12R2_DACC2DHR_0	(0x1u<<0)

// DHR12L2 Configuration

#define	DAC_DHR12L2_DACC2DHR	(0xFFFu<<4)
#define	DAC_DHR12L2_DACC2DHR_0	(0x1u<<4)

// DHR8R2 Configuration

#define	DAC_DHR8R2_DACC2DHR		(0xFFu<<0)
#define	DAC_DHR8R2_DACC2DHR_0	(0x1u<<0)

// DHR12RD Configuration

#define	DAC_DHR12RD_DACC2DHR	(0xFFFu<<16)
#define	DAC_DHR12RD_DACC2DHR_0	(0x1u<<16)
#define	DAC_DHR12RD_DACC1DHR	(0xFFFu<<0)
#define	DAC_DHR12RD_DACC1DHR_0	(0x1u<<0)

// DHR12LD Configuration

#define	DAC_DHR12LD_DACC2DHR	(0xFFFu<<20)
#define	DAC_DHR12LD_DACC2DHR_0	(0x1u<<20)
#define	DAC_DHR12LD_DACC1DHR	(0xFFFu<<4)
#define	DAC_DHR12LD_DACC1DHR_0	(0x1u<<4)

// DHR8RD Configuration

#define	DAC_DHR8RD_DACC2DHR		(0xFFu<<8)
#define	DAC_DHR8RD_DACC2DHR_0	(0x1u<<8)
#define	DAC_DHR8RD_DACC1DHR		(0xFFu<<0)
#define	DAC_DHR8RD_DACC1DHR_0	(0x1u<<0)

// DOR1 Configuration

#define	DAC_DOR1_DACC1DOR		(0xFFFu<<0)
#define	DAC_DOR1_DACC1DOR_0		(0x1u<<0)

// DOR2 Configuration

#define	DAC_DOR2_DACC2DOR		(0xFFFu<<0)
#define	DAC_DOR2_DACC2DOR_0		(0x1u<<0)

// SR Configuration

#define	DAC_SR_BWST2			(0x1u<<31)
#define	DAC_SR_CAL_FLAG2		(0x1u<<30)
#define	DAC_SR_DMAUDR2			(0x1u<<29)
#define	DAC_SR_BWST1			(0x1u<<15)
#define	DAC_SR_CAL_FLAG1		(0x1u<<14)
#define	DAC_SR_DMAUDR1			(0x1u<<13)

// CCR Configuration

#define	DAC_CCR_OTRIM2			(0x1Fu<<16)
#define	DAC_CCR_OTRIM2_0		(0x1u<<16)
#define	DAC_CCR_OTRIM1			(0x1Fu<<0)
#define	DAC_CCR_OTRIM1_0		(0x1u<<0)

// MCR Configuration

#define	DAC_MCR_MODE2			(0x7u<<16)
#define	DAC_MCR_MODE2_0			(0x1u<<16)
#define	DAC_MCR_MODE1			(0x7u<<0)
#define	DAC_MCR_MODE1_0			(0x1u<<0)

// SHSR1 Configuration

#define	DAC_SHSR1_TSAMPLE1		(0x3FFu<<0)
#define	DAC_SHSR1_TSAMPLE1_0	(0x1u<<0)

// SHSR2 Configuration

#define	DAC_SHSR2_TSAMPLE2		(0x3FFu<<0)
#define	DAC_SHSR2_TSAMPLE2_0	(0x1u<<0)

// SHHR Configuration

#define	DAC_SHHR_THOLD2			(0x3FFu<<16)
#define	DAC_SHHR_THOLD2_0		(0x1u<<16)
#define	DAC_SHHR_THOLD1			(0x3FFu<<0)
#define	DAC_SHHR_THOLD1_0		(0x1u<<0)

// SHRR Configuration

#define	DAC_SHRR_TREFRESH2		(0xFFu<<16)
#define	DAC_SHRR_TREFRESH2_0	(0x1u<<16)
#define	DAC_SHRR_TREFRESH1		(0xFFu<<0)
#define	DAC_SHRR_TREFRESH1_0	(0x1u<<0)
