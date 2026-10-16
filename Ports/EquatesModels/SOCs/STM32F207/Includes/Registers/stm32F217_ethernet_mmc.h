/*
; stm32F217_ethernet_mmc.
; =======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_ethernet_mmc equates.
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

// ETHERNET_MMC address definitions
// --------------------------------

typedef struct {
	volatile	uint32_t	MMCCR;
	volatile	uint32_t	MMCRIR;
	volatile	uint32_t	MMCTIR;
	volatile	uint32_t	MMCRIMR;
	volatile	uint32_t	MMCTIMR;
	volatile	uint32_t	RESERVED0[14];
	volatile	uint32_t	MMCTGFSCCR;
	volatile	uint32_t	MMCTGFMSCCR;
	volatile	uint32_t	RESERVED1[5];
	volatile	uint32_t	MMCTGFCR;
	volatile	uint32_t	RESERVED2[10];
	volatile	uint32_t	MMCRFCECR;
	volatile	uint32_t	MMCRFAECR;
	volatile	uint32_t	RESERVED3[10];
	volatile	uint32_t	MMCRGUFCR;
} ETHERNET_MMC_TypeDef;

#if (defined(__cplusplus))
#define	ETHERNET_MMC	reinterpret_cast<ETHERNET_MMC_TypeDef *>(0x40028100u)

#else
#define	ETHERNET_MMC	((ETHERNET_MMC_TypeDef *)0x40028100u)
#endif

// MMCCR Configuration

#define	ETHERNET_MMC_MMCCR_MCFHP			(0x1u<<5)
#define	ETHERNET_MMC_MMCCR_MCP				(0x1u<<4)
#define	ETHERNET_MMC_MMCCR_MCF				(0x1u<<3)
#define	ETHERNET_MMC_MMCCR_ROR				(0x1u<<2)
#define	ETHERNET_MMC_MMCCR_CSR				(0x1u<<1)
#define	ETHERNET_MMC_MMCCR_CR				(0x1u<<0)

// MMCRIR Configuration

#define	ETHERNET_MMC_MMCRIR_RGUFS			(0x1u<<17)
#define	ETHERNET_MMC_MMCRIR_RFAES			(0x1u<<6)
#define	ETHERNET_MMC_MMCRIR_RFCES			(0x1u<<5)

// MMCTIR Configuration

#define	ETHERNET_MMC_MMCTIR_TGFS			(0x1u<<21)
#define	ETHERNET_MMC_MMCTIR_TGFMSCS			(0x1u<<15)
#define	ETHERNET_MMC_MMCTIR_TGFSCS			(0x1u<<14)

// MMCRIMR Configuration

#define	ETHERNET_MMC_MMCRIMR_RGUFM			(0x1u<<17)
#define	ETHERNET_MMC_MMCRIMR_RFAEM			(0x1u<<6)
#define	ETHERNET_MMC_MMCRIMR_RFCEM			(0x1u<<5)

// MMCTIMR Configuration

#define	ETHERNET_MMC_MMCTIMR_TGFM			(0x1u<<21)
#define	ETHERNET_MMC_MMCTIMR_TGFMSCM		(0x1u<<15)
#define	ETHERNET_MMC_MMCTIMR_TGFSCM			(0x1u<<14)

// MMCTGFSCCR Configuration

#define	ETHERNET_MMC_MMCTGFSCCR_TGFSCC		(0xFFFFFFFFu<<0)
#define	ETHERNET_MMC_MMCTGFSCCR_TGFSCC_0	(0x1u<<0)

// MMCTGFMSCCR Configuration

#define	ETHERNET_MMC_MMCTGFMSCCR_TGFMSCC	(0xFFFFFFFFu<<0)
#define	ETHERNET_MMC_MMCTGFMSCCR_TGFMSCC_0	(0x1u<<0)

// MMCTGFCR Configuration

#define	ETHERNET_MMC_MMCTGFCR_TGFC			(0xFFFFFFFFu<<0)
#define	ETHERNET_MMC_MMCTGFCR_TGFC_0		(0x1u<<0)

// MMCRFCECR Configuration

#define	ETHERNET_MMC_MMCRFCECR_RFCFC		(0xFFFFFFFFu<<0)
#define	ETHERNET_MMC_MMCRFCECR_RFCFC_0		(0x1u<<0)

// MMCRFAECR Configuration

#define	ETHERNET_MMC_MMCRFAECR_RFAEC		(0xFFFFFFFFu<<0)
#define	ETHERNET_MMC_MMCRFAECR_RFAEC_0		(0x1u<<0)

// MMCRGUFCR Configuration

#define	ETHERNET_MMC_MMCRGUFCR_RGUFC		(0xFFFFFFFFu<<0)
#define	ETHERNET_MMC_MMCRGUFCR_RGUFC_0		(0x1u<<0)
