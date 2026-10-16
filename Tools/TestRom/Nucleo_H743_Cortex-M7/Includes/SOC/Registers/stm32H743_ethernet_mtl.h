/*
; stm32H743_ethernet_mtl.
; =======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_ethernet_mtl equates.
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

// ETHERNET_MTL address definitions
// --------------------------------

typedef struct {
	volatile	uint32_t	MTLOMR;
	volatile	uint32_t	RESERVED0[7];
	volatile	uint32_t	MTLISR;
	volatile	uint32_t	RESERVED1[55];
	volatile	uint32_t	MTLTXQOMR;
	volatile	uint32_t	MTLTXQUR;
	volatile	uint32_t	MTLTXQDR;
	volatile	uint32_t	RESERVED2[8];
	volatile	uint32_t	MTLQICSR;
	volatile	uint32_t	MTLRXQOMR;
	volatile	uint32_t	MTLRXQMPOCR;
	volatile	uint32_t	MTLRXQDR;
} ETHERNET_MTL_TypeDef;

#if (defined(__cplusplus))
#define	ETHERNET_MTL	reinterpret_cast<ETHERNET_MTL_TypeDef *>(0x40028C00u)

#else
#define	ETHERNET_MTL	((ETHERNET_MTL_TypeDef *)0x40028C00u)
#endif

// MTLOMR Configuration

#define	ETHERNET_MTL_MTLOMR_CNTCLR				(0x1u<<9)
#define	ETHERNET_MTL_MTLOMR_CNTPRST				(0x1u<<8)
#define	ETHERNET_MTL_MTLOMR_DTXSTS				(0x1u<<1)

// MTLISR Configuration

#define	ETHERNET_MTL_MTLISR_Q0IS				(0x1u<<0)

// MTLTXQOMR Configuration

#define	ETHERNET_MTL_MTLTXQOMR_TQS				(0x7u<<16)
#define	ETHERNET_MTL_MTLTXQOMR_TQS_0			(0x1u<<16)
#define	ETHERNET_MTL_MTLTXQOMR_TTC				(0x7u<<4)
#define	ETHERNET_MTL_MTLTXQOMR_TTC_0			(0x1u<<4)
#define	ETHERNET_MTL_MTLTXQOMR_TXQEN			(0x3u<<2)
#define	ETHERNET_MTL_MTLTXQOMR_TXQEN_0			(0x1u<<2)
#define	ETHERNET_MTL_MTLTXQOMR_TSF				(0x1u<<1)
#define	ETHERNET_MTL_MTLTXQOMR_FTQ				(0x1u<<0)

// MTLTXQUR Configuration

#define	ETHERNET_MTL_MTLTXQUR_UFCNTOVF			(0x1u<<11)
#define	ETHERNET_MTL_MTLTXQUR_UFFRMCNT			(0x7FFu<<0)
#define	ETHERNET_MTL_MTLTXQUR_UFFRMCNT_0		(0x1u<<0)

// MTLTXQDR Configuration

#define	ETHERNET_MTL_MTLTXQDR_STXSTSF			(0x7u<<20)
#define	ETHERNET_MTL_MTLTXQDR_STXSTSF_0			(0x1u<<20)
#define	ETHERNET_MTL_MTLTXQDR_PTXQ				(0x7u<<16)
#define	ETHERNET_MTL_MTLTXQDR_PTXQ_0			(0x1u<<16)
#define	ETHERNET_MTL_MTLTXQDR_TXSTSFSTS			(0x1u<<5)
#define	ETHERNET_MTL_MTLTXQDR_TXQSTS			(0x1u<<4)
#define	ETHERNET_MTL_MTLTXQDR_TWCSTS			(0x1u<<3)
#define	ETHERNET_MTL_MTLTXQDR_TRCSTS			(0x3u<<1)
#define	ETHERNET_MTL_MTLTXQDR_TRCSTS_0			(0x1u<<1)
#define	ETHERNET_MTL_MTLTXQDR_TXQPAUSED			(0x1u<<0)

// MTLQICSR Configuration

#define	ETHERNET_MTL_MTLQICSR_RXOIE				(0x1u<<24)
#define	ETHERNET_MTL_MTLQICSR_RXOVFIS			(0x1u<<16)
#define	ETHERNET_MTL_MTLQICSR_TXUIE				(0x1u<<8)
#define	ETHERNET_MTL_MTLQICSR_TXUNFIS			(0x1u<<0)

// MTLRXQOMR Configuration

#define	ETHERNET_MTL_MTLRXQOMR_RQS				(0x7u<<20)
#define	ETHERNET_MTL_MTLRXQOMR_RQS_0			(0x1u<<20)
#define	ETHERNET_MTL_MTLRXQOMR_RFD				(0x7u<<14)
#define	ETHERNET_MTL_MTLRXQOMR_RFD_0			(0x1u<<14)
#define	ETHERNET_MTL_MTLRXQOMR_RFA				(0x7u<<8)
#define	ETHERNET_MTL_MTLRXQOMR_RFA_0			(0x1u<<8)
#define	ETHERNET_MTL_MTLRXQOMR_EHFC				(0x1u<<7)
#define	ETHERNET_MTL_MTLRXQOMR_DIS_TCP_EF		(0x1u<<6)
#define	ETHERNET_MTL_MTLRXQOMR_RSF				(0x1u<<5)
#define	ETHERNET_MTL_MTLRXQOMR_FEP				(0x1u<<4)
#define	ETHERNET_MTL_MTLRXQOMR_FUP				(0x1u<<3)
#define	ETHERNET_MTL_MTLRXQOMR_RTC				(0x3u<<0)
#define	ETHERNET_MTL_MTLRXQOMR_RTC_0			(0x1u<<0)

// MTLRXQMPOCR Configuration

#define	ETHERNET_MTL_MTLRXQMPOCR_MISCNTOVF		(0x1u<<27)
#define	ETHERNET_MTL_MTLRXQMPOCR_MISPKTCNT		(0x7FFu<<16)
#define	ETHERNET_MTL_MTLRXQMPOCR_MISPKTCNT_0	(0x1u<<16)
#define	ETHERNET_MTL_MTLRXQMPOCR_OVFCNTOVF		(0x1u<<11)
#define	ETHERNET_MTL_MTLRXQMPOCR_OVFPKTCNT		(0x7FFu<<0)
#define	ETHERNET_MTL_MTLRXQMPOCR_OVFPKTCNT_0	(0x1u<<0)

// MTLRXQDR Configuration

#define	ETHERNET_MTL_MTLRXQDR_PRXQ				(0x3FFFu<<16)
#define	ETHERNET_MTL_MTLRXQDR_PRXQ_0			(0x1u<<16)
#define	ETHERNET_MTL_MTLRXQDR_RXQSTS			(0x3u<<4)
#define	ETHERNET_MTL_MTLRXQDR_RXQSTS_0			(0x1u<<4)
#define	ETHERNET_MTL_MTLRXQDR_RRCSTS			(0x3u<<1)
#define	ETHERNET_MTL_MTLRXQDR_RRCSTS_0			(0x1u<<1)
#define	ETHERNET_MTL_MTLRXQDR_RWCSTS			(0x1u<<0)
