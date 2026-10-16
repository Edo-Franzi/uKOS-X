/*
; stm32F217_ethernet_dma.
; =======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_ethernet_dma equates.
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

// ETHERNET_DMA address definitions
// --------------------------------

typedef struct {
	volatile	uint32_t	DMABMR;
	volatile	uint32_t	DMATPDR;
	volatile	uint32_t	DMARPDR;
	volatile	uint32_t	DMARDLAR;
	volatile	uint32_t	DMATDLAR;
	volatile	uint32_t	DMASR;
	volatile	uint32_t	DMAOMR;
	volatile	uint32_t	DMAIER;
	volatile	uint32_t	DMAMFBOCR;
	volatile	uint32_t	DMARSWTR;
	volatile	uint32_t	RESERVED0[8];
	volatile	uint32_t	DMACHTDR;
	volatile	uint32_t	DMACHRDR;
	volatile	uint32_t	DMACHTBAR;
	volatile	uint32_t	DMACHRBAR;
} ETHERNET_DMA_TypeDef;

#if (defined(__cplusplus))
#define	ETHERNET_DMA	reinterpret_cast<ETHERNET_DMA_TypeDef *>(0x40029000u)

#else
#define	ETHERNET_DMA	((ETHERNET_DMA_TypeDef *)0x40029000u)
#endif

// DMABMR Configuration

#define	ETHERNET_DMA_DMABMR_MB			(0x1u<<26)
#define	ETHERNET_DMA_DMABMR_AAB			(0x1u<<25)
#define	ETHERNET_DMA_DMABMR_FPM			(0x1u<<24)
#define	ETHERNET_DMA_DMABMR_USP			(0x1u<<23)
#define	ETHERNET_DMA_DMABMR_RDP			(0x3Fu<<17)
#define	ETHERNET_DMA_DMABMR_RDP_0		(0x1u<<17)
#define	ETHERNET_DMA_DMABMR_FB			(0x1u<<16)
#define	ETHERNET_DMA_DMABMR_RTPR		(0x3u<<14)
#define	ETHERNET_DMA_DMABMR_RTPR_0		(0x1u<<14)
#define	ETHERNET_DMA_DMABMR_PBL			(0x3Fu<<8)
#define	ETHERNET_DMA_DMABMR_PBL_0		(0x1u<<8)
#define	ETHERNET_DMA_DMABMR_EDFE		(0x1u<<7)
#define	ETHERNET_DMA_DMABMR_DSL			(0x1Fu<<2)
#define	ETHERNET_DMA_DMABMR_DSL_0		(0x1u<<2)
#define	ETHERNET_DMA_DMABMR_DA			(0x1u<<1)
#define	ETHERNET_DMA_DMABMR_SR			(0x1u<<0)

// DMATPDR Configuration

#define	ETHERNET_DMA_DMATPDR_TPD		(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMATPDR_TPD_0		(0x1u<<0)

// DMARPDR Configuration

#define	ETHERNET_DMA_DMARPDR_RPD		(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMARPDR_RPD_0		(0x1u<<0)

// DMARDLAR Configuration

#define	ETHERNET_DMA_DMARDLAR_SRL		(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMARDLAR_SRL_0		(0x1u<<0)

// DMATDLAR Configuration

#define	ETHERNET_DMA_DMATDLAR_STL		(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMATDLAR_STL_0		(0x1u<<0)

// DMASR Configuration

#define	ETHERNET_DMA_DMASR_TSTS			(0x1u<<29)
#define	ETHERNET_DMA_DMASR_PMTS			(0x1u<<28)
#define	ETHERNET_DMA_DMASR_MMCS			(0x1u<<27)
#define	ETHERNET_DMA_DMASR_EBS			(0x7u<<23)
#define	ETHERNET_DMA_DMASR_EBS_0		(0x1u<<23)
#define	ETHERNET_DMA_DMASR_TPS			(0x7u<<20)
#define	ETHERNET_DMA_DMASR_TPS_0		(0x1u<<20)
#define	ETHERNET_DMA_DMASR_RPS			(0x7u<<17)
#define	ETHERNET_DMA_DMASR_RPS_0		(0x1u<<17)
#define	ETHERNET_DMA_DMASR_NIS			(0x1u<<16)
#define	ETHERNET_DMA_DMASR_AIS			(0x1u<<15)
#define	ETHERNET_DMA_DMASR_ERS			(0x1u<<14)
#define	ETHERNET_DMA_DMASR_FBES			(0x1u<<13)
#define	ETHERNET_DMA_DMASR_ETS			(0x1u<<10)
#define	ETHERNET_DMA_DMASR_PWTS			(0x1u<<9)
#define	ETHERNET_DMA_DMASR_RPSS			(0x1u<<8)
#define	ETHERNET_DMA_DMASR_RBUS			(0x1u<<7)
#define	ETHERNET_DMA_DMASR_RS			(0x1u<<6)
#define	ETHERNET_DMA_DMASR_TUS			(0x1u<<5)
#define	ETHERNET_DMA_DMASR_ROS			(0x1u<<4)
#define	ETHERNET_DMA_DMASR_TJTS			(0x1u<<3)
#define	ETHERNET_DMA_DMASR_TBUS			(0x1u<<2)
#define	ETHERNET_DMA_DMASR_TPSS			(0x1u<<1)
#define	ETHERNET_DMA_DMASR_TS			(0x1u<<0)

// DMAOMR Configuration

#define	ETHERNET_DMA_DMAOMR_DTCEFD		(0x1u<<26)
#define	ETHERNET_DMA_DMAOMR_RSF			(0x1u<<25)
#define	ETHERNET_DMA_DMAOMR_DFRF		(0x1u<<24)
#define	ETHERNET_DMA_DMAOMR_TSF			(0x1u<<21)
#define	ETHERNET_DMA_DMAOMR_FTF			(0x1u<<20)
#define	ETHERNET_DMA_DMAOMR_TTC			(0x7u<<14)
#define	ETHERNET_DMA_DMAOMR_TTC_0		(0x1u<<14)
#define	ETHERNET_DMA_DMAOMR_ST			(0x1u<<13)
#define	ETHERNET_DMA_DMAOMR_FEF			(0x1u<<7)
#define	ETHERNET_DMA_DMAOMR_FUGF		(0x1u<<6)
#define	ETHERNET_DMA_DMAOMR_RTC			(0x3u<<3)
#define	ETHERNET_DMA_DMAOMR_RTC_0		(0x1u<<3)
#define	ETHERNET_DMA_DMAOMR_OSF			(0x1u<<2)
#define	ETHERNET_DMA_DMAOMR_SR			(0x1u<<1)

// DMAIER Configuration

#define	ETHERNET_DMA_DMAIER_NISE		(0x1u<<16)
#define	ETHERNET_DMA_DMAIER_AISE		(0x1u<<15)
#define	ETHERNET_DMA_DMAIER_ERIE		(0x1u<<14)
#define	ETHERNET_DMA_DMAIER_FBEIE		(0x1u<<13)
#define	ETHERNET_DMA_DMAIER_ETIE		(0x1u<<10)
#define	ETHERNET_DMA_DMAIER_RWTIE		(0x1u<<9)
#define	ETHERNET_DMA_DMAIER_RPSIE		(0x1u<<8)
#define	ETHERNET_DMA_DMAIER_RBUIE		(0x1u<<7)
#define	ETHERNET_DMA_DMAIER_RIE			(0x1u<<6)
#define	ETHERNET_DMA_DMAIER_TUIE		(0x1u<<5)
#define	ETHERNET_DMA_DMAIER_ROIE		(0x1u<<4)
#define	ETHERNET_DMA_DMAIER_TJTIE		(0x1u<<3)
#define	ETHERNET_DMA_DMAIER_TBUIE		(0x1u<<2)
#define	ETHERNET_DMA_DMAIER_TPSIE		(0x1u<<1)
#define	ETHERNET_DMA_DMAIER_TIE			(0x1u<<0)

// DMAMFBOCR Configuration

#define	ETHERNET_DMA_DMAMFBOCR_OFOC		(0x1u<<28)
#define	ETHERNET_DMA_DMAMFBOCR_MFA		(0x7FFu<<17)
#define	ETHERNET_DMA_DMAMFBOCR_MFA_0	(0x1u<<17)
#define	ETHERNET_DMA_DMAMFBOCR_OMFC		(0x1u<<16)
#define	ETHERNET_DMA_DMAMFBOCR_MFC		(0xFFFFu<<0)
#define	ETHERNET_DMA_DMAMFBOCR_MFC_0	(0x1u<<0)

// DMARSWTR Configuration

#define	ETHERNET_DMA_DMARSWTR_RSWTC		(0xFFu<<0)
#define	ETHERNET_DMA_DMARSWTR_RSWTC_0	(0x1u<<0)

// DMACHTDR Configuration

#define	ETHERNET_DMA_DMACHTDR_HTDAP		(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMACHTDR_HTDAP_0	(0x1u<<0)

// DMACHRDR Configuration

#define	ETHERNET_DMA_DMACHRDR_HRDAP		(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMACHRDR_HRDAP_0	(0x1u<<0)

// DMACHTBAR Configuration

#define	ETHERNET_DMA_DMACHTBAR_HTBAP	(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMACHTBAR_HTBAP_0	(0x1u<<0)

// DMACHRBAR Configuration

#define	ETHERNET_DMA_DMACHRBAR_HRBAP	(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMACHRBAR_HRBAP_0	(0x1u<<0)
