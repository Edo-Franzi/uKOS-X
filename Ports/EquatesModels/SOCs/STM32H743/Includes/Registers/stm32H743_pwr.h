/*
; stm32H743_pwr.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_pwr equates.
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

// PWR address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR1;
	volatile	uint32_t	CSR1;
	volatile	uint32_t	CR2;
	volatile	uint32_t	CR3;
	volatile	uint32_t	CPUCR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	D3CR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	WKUPCR;
	volatile	uint32_t	WKUPFR;
	volatile	uint32_t	WKUPEPR;
} PWR_TypeDef;

#if (defined(__cplusplus))
#define	PWR	reinterpret_cast<PWR_TypeDef *>(0x58024800u)

#else
#define	PWR	((PWR_TypeDef *)0x58024800u)
#endif

// CR1 Configuration

#define	PWR_CR1_ALS				(0x3u<<17)
#define	PWR_CR1_ALS_0			(0x1u<<17)
#define	PWR_CR1_AVDEN			(0x1u<<16)
#define	PWR_CR1_SVOS			(0x3u<<14)
#define	PWR_CR1_SVOS_0			(0x1u<<14)
#define	PWR_CR1_FLPS			(0x1u<<9)
#define	PWR_CR1_DBP				(0x1u<<8)
#define	PWR_CR1_PLS				(0x7u<<5)
#define	PWR_CR1_PLS_0			(0x1u<<5)
#define	PWR_CR1_PVDE			(0x1u<<4)
#define	PWR_CR1_LPDS			(0x1u<<0)

// CSR1 Configuration

#define	PWR_CSR1_AVDO			(0x1u<<16)
#define	PWR_CSR1_ACTVOS			(0x3u<<14)
#define	PWR_CSR1_ACTVOS_0		(0x1u<<14)
#define	PWR_CSR1_ACTVOSRDY		(0x1u<<13)
#define	PWR_CSR1_PVDO			(0x1u<<4)

// CR2 Configuration

#define	PWR_CR2_TEMPH			(0x1u<<23)
#define	PWR_CR2_TEMPL			(0x1u<<22)
#define	PWR_CR2_VBATH			(0x1u<<21)
#define	PWR_CR2_VBATL			(0x1u<<20)
#define	PWR_CR2_BRRDY			(0x1u<<16)
#define	PWR_CR2_MONEN			(0x1u<<4)
#define	PWR_CR2_BREN			(0x1u<<0)

// CR3 Configuration

#define	PWR_CR3_USB33RDY		(0x1u<<26)
#define	PWR_CR3_USBREGEN		(0x1u<<25)
#define	PWR_CR3_USB33DEN		(0x1u<<24)
#define	PWR_CR3_VBRS			(0x1u<<9)
#define	PWR_CR3_VBE				(0x1u<<8)
#define	PWR_CR3_SCUEN			(0x1u<<2)
#define	PWR_CR3_LDOEN			(0x1u<<1)
#define	PWR_CR3_BYPASS			(0x1u<<0)

// CPUCR Configuration

#define	PWR_CPUCR_RUN_D3		(0x1u<<11)
#define	PWR_CPUCR_CSSF			(0x1u<<9)
#define	PWR_CPUCR_SBF_D2		(0x1u<<8)
#define	PWR_CPUCR_SBF_D1		(0x1u<<7)
#define	PWR_CPUCR_SBF			(0x1u<<6)
#define	PWR_CPUCR_STOPF			(0x1u<<5)
#define	PWR_CPUCR_PDDS_D3		(0x1u<<2)
#define	PWR_CPUCR_PDDS_D2		(0x1u<<1)
#define	PWR_CPUCR_PDDS_D1		(0x1u<<0)

// D3CR Configuration

#define	PWR_D3CR_VOS			(0x3u<<14)
#define	PWR_D3CR_VOS_0			(0x1u<<14)
#define	PWR_D3CR_VOSRDY			(0x1u<<13)

// WKUPCR Configuration

#define	PWR_WKUPCR_WKUPC		(0x3Fu<<0)
#define	PWR_WKUPCR_WKUPC_0		(0x1u<<0)

// WKUPFR Configuration

#define	PWR_WKUPFR_WKUPF6		(0x1u<<5)
#define	PWR_WKUPFR_WKUPF5		(0x1u<<4)
#define	PWR_WKUPFR_WKUPF4		(0x1u<<3)
#define	PWR_WKUPFR_WKUPF3		(0x1u<<2)
#define	PWR_WKUPFR_WKUPF2		(0x1u<<1)
#define	PWR_WKUPFR_WKUPF1		(0x1u<<0)

// WKUPEPR Configuration

#define	PWR_WKUPEPR_WKUPPUPD6	(0x3u<<26)
#define	PWR_WKUPEPR_WKUPPUPD6_0	(0x1u<<26)
#define	PWR_WKUPEPR_WKUPPUPD5	(0x3u<<24)
#define	PWR_WKUPEPR_WKUPPUPD5_0	(0x1u<<24)
#define	PWR_WKUPEPR_WKUPPUPD4	(0x3u<<22)
#define	PWR_WKUPEPR_WKUPPUPD4_0	(0x1u<<22)
#define	PWR_WKUPEPR_WKUPPUPD3	(0x3u<<20)
#define	PWR_WKUPEPR_WKUPPUPD3_0	(0x1u<<20)
#define	PWR_WKUPEPR_WKUPPUPD2	(0x3u<<18)
#define	PWR_WKUPEPR_WKUPPUPD2_0	(0x1u<<18)
#define	PWR_WKUPEPR_WKUPPUPD1	(0x3u<<16)
#define	PWR_WKUPEPR_WKUPPUPD1_0	(0x1u<<16)
#define	PWR_WKUPEPR_WKUPP6		(0x1u<<13)
#define	PWR_WKUPEPR_WKUPP5		(0x1u<<12)
#define	PWR_WKUPEPR_WKUPP4		(0x1u<<11)
#define	PWR_WKUPEPR_WKUPP3		(0x1u<<10)
#define	PWR_WKUPEPR_WKUPP2		(0x1u<<9)
#define	PWR_WKUPEPR_WKUPP1		(0x1u<<8)
#define	PWR_WKUPEPR_WKUPEN6		(0x1u<<5)
#define	PWR_WKUPEPR_WKUPEN5		(0x1u<<4)
#define	PWR_WKUPEPR_WKUPEN4		(0x1u<<3)
#define	PWR_WKUPEPR_WKUPEN3		(0x1u<<2)
#define	PWR_WKUPEPR_WKUPEN2		(0x1u<<1)
#define	PWR_WKUPEPR_WKUPEN1		(0x1u<<0)
