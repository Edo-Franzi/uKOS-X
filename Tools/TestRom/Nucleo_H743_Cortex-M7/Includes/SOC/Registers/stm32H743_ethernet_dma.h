/*
; stm32H743_ethernet_dma.
; =======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_ethernet_dma equates.
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
	volatile	uint32_t	DMAMR;
	volatile	uint32_t	DMASBMR;
	volatile	uint32_t	DMAISR;
	volatile	uint32_t	DMADSR;
	volatile	uint32_t	RESERVED0[60];
	volatile	uint32_t	DMACCR;
	volatile	uint32_t	DMACTXCR;
	volatile	uint32_t	DMACRXCR;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	DMACTXDLAR;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	DMACRXDLAR;
	volatile	uint32_t	DMACTXDTPR;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	DMACRXDTPR;
	volatile	uint32_t	DMACTXRLR;
	volatile	uint32_t	DMACRXRLR;
	volatile	uint32_t	DMACIER;
	volatile	uint32_t	DMACRXIWTR;
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	DMACCATXDR;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	DMACCARXDR;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	DMACCATXBR;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	DMACCARXBR;
	volatile	uint32_t	DMACSR;
	volatile	uint32_t	RESERVED8[2];
	volatile	uint32_t	DMACMFCR;
} ETHERNET_DMA_TypeDef;

#if (defined(__cplusplus))
#define	ETHERNET_DMA	reinterpret_cast<ETHERNET_DMA_TypeDef *>(0x40029000u)

#else
#define	ETHERNET_DMA	((ETHERNET_DMA_TypeDef *)0x40029000u)
#endif

// DMAMR Configuration

#define	ETHERNET_DMA_DMAMR_INTM					(0x1u<<16)
#define	ETHERNET_DMA_DMAMR_PR					(0x7u<<12)
#define	ETHERNET_DMA_DMAMR_PR_0					(0x1u<<12)
#define	ETHERNET_DMA_DMAMR_TXPR					(0x1u<<11)
#define	ETHERNET_DMA_DMAMR_DA					(0x1u<<1)
#define	ETHERNET_DMA_DMAMR_SWR					(0x1u<<0)

// DMASBMR Configuration

#define	ETHERNET_DMA_DMASBMR_RB					(0x1u<<15)
#define	ETHERNET_DMA_DMASBMR_MB					(0x1u<<14)
#define	ETHERNET_DMA_DMASBMR_AAL				(0x1u<<12)
#define	ETHERNET_DMA_DMASBMR_FB					(0x1u<<0)

// DMAISR Configuration

#define	ETHERNET_DMA_DMAISR_MACIS				(0x1u<<17)
#define	ETHERNET_DMA_DMAISR_MTLIS				(0x1u<<16)
#define	ETHERNET_DMA_DMAISR_DC0IS				(0x1u<<0)

// DMADSR Configuration

#define	ETHERNET_DMA_DMADSR_TPS0				(0xFu<<12)
#define	ETHERNET_DMA_DMADSR_TPS0_0				(0x1u<<12)
#define	ETHERNET_DMA_DMADSR_RPS0				(0xFu<<8)
#define	ETHERNET_DMA_DMADSR_RPS0_0				(0x1u<<8)
#define	ETHERNET_DMA_DMADSR_AXWHSTS				(0x1u<<0)

// DMACCR Configuration

#define	ETHERNET_DMA_DMACCR_DSL					(0x7u<<18)
#define	ETHERNET_DMA_DMACCR_DSL_0				(0x1u<<18)
#define	ETHERNET_DMA_DMACCR_PBLX8				(0x1u<<16)
#define	ETHERNET_DMA_DMACCR_MSS					(0x3FFFu<<0)
#define	ETHERNET_DMA_DMACCR_MSS_0				(0x1u<<0)

// DMACTXCR Configuration

#define	ETHERNET_DMA_DMACTXCR_TXPBL				(0x3Fu<<16)
#define	ETHERNET_DMA_DMACTXCR_TXPBL_0			(0x1u<<16)
#define	ETHERNET_DMA_DMACTXCR_TSE				(0x1u<<12)
#define	ETHERNET_DMA_DMACTXCR_OSF				(0x1u<<4)
#define	ETHERNET_DMA_DMACTXCR_ST				(0x1u<<0)

// DMACRXCR Configuration

#define	ETHERNET_DMA_DMACRXCR_RPF				(0x1u<<31)
#define	ETHERNET_DMA_DMACRXCR_RXPBL				(0x3Fu<<16)
#define	ETHERNET_DMA_DMACRXCR_RXPBL_0			(0x1u<<16)
#define	ETHERNET_DMA_DMACRXCR_RBSZ				(0x3FFFu<<1)
#define	ETHERNET_DMA_DMACRXCR_RBSZ_0			(0x1u<<1)
#define	ETHERNET_DMA_DMACRXCR_SR				(0x1u<<0)

// DMACTXDLAR Configuration

#define	ETHERNET_DMA_DMACTXDLAR_TDESLA			(0x3FFFFFFFu<<2)
#define	ETHERNET_DMA_DMACTXDLAR_TDESLA_0		(0x1u<<2)

// DMACRXDLAR Configuration

#define	ETHERNET_DMA_DMACRXDLAR_RDESLA			(0x3FFFFFFFu<<2)
#define	ETHERNET_DMA_DMACRXDLAR_RDESLA_0		(0x1u<<2)

// DMACTXDTPR Configuration

#define	ETHERNET_DMA_DMACTXDTPR_TDT				(0x3FFFFFFFu<<2)
#define	ETHERNET_DMA_DMACTXDTPR_TDT_0			(0x1u<<2)

// DMACRXDTPR Configuration

#define	ETHERNET_DMA_DMACRXDTPR_RDT				(0x3FFFFFFFu<<2)
#define	ETHERNET_DMA_DMACRXDTPR_RDT_0			(0x1u<<2)

// DMACTXRLR Configuration

#define	ETHERNET_DMA_DMACTXRLR_TDRL				(0x3FFu<<0)
#define	ETHERNET_DMA_DMACTXRLR_TDRL_0			(0x1u<<0)

// DMACRXRLR Configuration

#define	ETHERNET_DMA_DMACRXRLR_RDRL				(0x3FFu<<0)
#define	ETHERNET_DMA_DMACRXRLR_RDRL_0			(0x1u<<0)

// DMACIER Configuration

#define	ETHERNET_DMA_DMACIER_NIE				(0x1u<<15)
#define	ETHERNET_DMA_DMACIER_AIE				(0x1u<<14)
#define	ETHERNET_DMA_DMACIER_CDEE				(0x1u<<13)
#define	ETHERNET_DMA_DMACIER_FBEE				(0x1u<<12)
#define	ETHERNET_DMA_DMACIER_ERIE				(0x1u<<11)
#define	ETHERNET_DMA_DMACIER_ETIE				(0x1u<<10)
#define	ETHERNET_DMA_DMACIER_RWTE				(0x1u<<9)
#define	ETHERNET_DMA_DMACIER_RSE				(0x1u<<8)
#define	ETHERNET_DMA_DMACIER_RBUE				(0x1u<<7)
#define	ETHERNET_DMA_DMACIER_RIE				(0x1u<<6)
#define	ETHERNET_DMA_DMACIER_TBUE				(0x1u<<2)
#define	ETHERNET_DMA_DMACIER_TXSE				(0x1u<<1)
#define	ETHERNET_DMA_DMACIER_TIE				(0x1u<<0)

// DMACRXIWTR Configuration

#define	ETHERNET_DMA_DMACRXIWTR_RWT				(0xFFu<<0)
#define	ETHERNET_DMA_DMACRXIWTR_RWT_0			(0x1u<<0)

// DMACCATXDR Configuration

#define	ETHERNET_DMA_DMACCATXDR_CURTDESAPTR		(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMACCATXDR_CURTDESAPTR_0	(0x1u<<0)

// DMACCARXDR Configuration

#define	ETHERNET_DMA_DMACCARXDR_CURRDESAPTR		(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMACCARXDR_CURRDESAPTR_0	(0x1u<<0)

// DMACCATXBR Configuration

#define	ETHERNET_DMA_DMACCATXBR_CURTBUFAPTR		(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMACCATXBR_CURTBUFAPTR_0	(0x1u<<0)

// DMACCARXBR Configuration

#define	ETHERNET_DMA_DMACCARXBR_CURRBUFAPTR		(0xFFFFFFFFu<<0)
#define	ETHERNET_DMA_DMACCARXBR_CURRBUFAPTR_0	(0x1u<<0)

// DMACSR Configuration

#define	ETHERNET_DMA_DMACSR_REB					(0x7u<<19)
#define	ETHERNET_DMA_DMACSR_REB_0				(0x1u<<19)
#define	ETHERNET_DMA_DMACSR_TEB					(0x7u<<16)
#define	ETHERNET_DMA_DMACSR_TEB_0				(0x1u<<16)
#define	ETHERNET_DMA_DMACSR_NIS					(0x1u<<15)
#define	ETHERNET_DMA_DMACSR_AIS					(0x1u<<14)
#define	ETHERNET_DMA_DMACSR_CDE					(0x1u<<13)
#define	ETHERNET_DMA_DMACSR_FBE					(0x1u<<12)
#define	ETHERNET_DMA_DMACSR_ER					(0x1u<<11)
#define	ETHERNET_DMA_DMACSR_ET					(0x1u<<10)
#define	ETHERNET_DMA_DMACSR_RWT					(0x1u<<9)
#define	ETHERNET_DMA_DMACSR_RPS					(0x1u<<8)
#define	ETHERNET_DMA_DMACSR_RBU					(0x1u<<7)
#define	ETHERNET_DMA_DMACSR_RI					(0x1u<<6)
#define	ETHERNET_DMA_DMACSR_TBU					(0x1u<<2)
#define	ETHERNET_DMA_DMACSR_TPS					(0x1u<<1)
#define	ETHERNET_DMA_DMACSR_TI					(0x1u<<0)

// DMACMFCR Configuration

#define	ETHERNET_DMA_DMACMFCR_MFCO				(0x1u<<15)
#define	ETHERNET_DMA_DMACMFCR_MFC				(0x7FFu<<0)
#define	ETHERNET_DMA_DMACMFCR_MFC_0				(0x1u<<0)
