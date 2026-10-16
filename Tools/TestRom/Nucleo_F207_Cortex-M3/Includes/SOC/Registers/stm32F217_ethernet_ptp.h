/*
; stm32F217_ethernet_ptp.
; =======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_ethernet_ptp equates.
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

// ETHERNET_PTP address definitions
// --------------------------------

typedef struct {
	volatile	uint32_t	PTPTSCR;
	volatile	uint32_t	PTPSSIR;
	volatile	uint32_t	PTPTSHR;
	volatile	uint32_t	PTPTSLR;
	volatile	uint32_t	PTPTSHUR;
	volatile	uint32_t	PTPTSLUR;
	volatile	uint32_t	PTPTSAR;
	volatile	uint32_t	PTPTTHR;
	volatile	uint32_t	PTPTTLR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	PTPTSSR;
	volatile	uint32_t	PTPPPSCR;
} ETHERNET_PTP_TypeDef;

#if (defined(__cplusplus))
#define	ETHERNET_PTP	reinterpret_cast<ETHERNET_PTP_TypeDef *>(0x40028700u)

#else
#define	ETHERNET_PTP	((ETHERNET_PTP_TypeDef *)0x40028700u)
#endif

// PTPTSCR Configuration

#define	ETHERNET_PTP_PTPTSCR_TSPFFMAE	(0x1u<<18)
#define	ETHERNET_PTP_PTPTSCR_TSCNT		(0x3u<<16)
#define	ETHERNET_PTP_PTPTSCR_TSCNT_0	(0x1u<<16)
#define	ETHERNET_PTP_PTPTSCR_TSSMRME	(0x1u<<15)
#define	ETHERNET_PTP_PTPTSCR_TSSEME		(0x1u<<14)
#define	ETHERNET_PTP_PTPTSCR_TSSIPV4FE	(0x1u<<13)
#define	ETHERNET_PTP_PTPTSCR_TSSIPV6FE	(0x1u<<12)
#define	ETHERNET_PTP_PTPTSCR_TSSPTPOEFE	(0x1u<<11)
#define	ETHERNET_PTP_PTPTSCR_TSPTPPSV2E	(0x1u<<10)
#define	ETHERNET_PTP_PTPTSCR_TSSSR		(0x1u<<9)
#define	ETHERNET_PTP_PTPTSCR_TSSARFE	(0x1u<<8)
#define	ETHERNET_PTP_PTPTSCR_TTSARU		(0x1u<<5)
#define	ETHERNET_PTP_PTPTSCR_TSITE		(0x1u<<4)
#define	ETHERNET_PTP_PTPTSCR_TSSTU		(0x1u<<3)
#define	ETHERNET_PTP_PTPTSCR_TSSTI		(0x1u<<2)
#define	ETHERNET_PTP_PTPTSCR_TSFCU		(0x1u<<1)
#define	ETHERNET_PTP_PTPTSCR_TSE		(0x1u<<0)

// PTPSSIR Configuration

#define	ETHERNET_PTP_PTPSSIR_STSSI		(0xFFu<<0)
#define	ETHERNET_PTP_PTPSSIR_STSSI_0	(0x1u<<0)

// PTPTSHR Configuration

#define	ETHERNET_PTP_PTPTSHR_STS		(0xFFFFFFFFu<<0)
#define	ETHERNET_PTP_PTPTSHR_STS_0		(0x1u<<0)

// PTPTSLR Configuration

#define	ETHERNET_PTP_PTPTSLR_STPNS		(0x1u<<31)
#define	ETHERNET_PTP_PTPTSLR_STSS		(0x7FFFFFFFu<<0)
#define	ETHERNET_PTP_PTPTSLR_STSS_0		(0x1u<<0)

// PTPTSHUR Configuration

#define	ETHERNET_PTP_PTPTSHUR_TSUS		(0xFFFFFFFFu<<0)
#define	ETHERNET_PTP_PTPTSHUR_TSUS_0	(0x1u<<0)

// PTPTSLUR Configuration

#define	ETHERNET_PTP_PTPTSLUR_TSUPNS	(0x1u<<31)
#define	ETHERNET_PTP_PTPTSLUR_TSUSS		(0x7FFFFFFFu<<0)
#define	ETHERNET_PTP_PTPTSLUR_TSUSS_0	(0x1u<<0)

// PTPTSAR Configuration

#define	ETHERNET_PTP_PTPTSAR_TSA		(0xFFFFFFFFu<<0)
#define	ETHERNET_PTP_PTPTSAR_TSA_0		(0x1u<<0)

// PTPTTHR Configuration

#define	ETHERNET_PTP_PTPTTHR_TTSH		(0xFFFFFFFFu<<0)
#define	ETHERNET_PTP_PTPTTHR_TTSH_0		(0x1u<<0)

// PTPTTLR Configuration

#define	ETHERNET_PTP_PTPTTLR_TTSL		(0xFFFFFFFFu<<0)
#define	ETHERNET_PTP_PTPTTLR_TTSL_0		(0x1u<<0)

// PTPTSSR Configuration

#define	ETHERNET_PTP_PTPTSSR_TSTTR		(0x1u<<1)
#define	ETHERNET_PTP_PTPTSSR_TSSO		(0x1u<<0)

// PTPPPSCR Configuration

#define	ETHERNET_PTP_PTPPPSCR_PPSFREQ	(0xFu<<0)
#define	ETHERNET_PTP_PTPPPSCR_PPSFREQ_0	(0x1u<<0)
