/*
; stm32U5Gx_lpuart.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_lpuart equates.
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

// LPUART address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	CR1;
	volatile	uint32_t	CR2;
	volatile	uint32_t	CR3;
	volatile	uint32_t	BRR;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	RQR;
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	RDR;
	volatile	uint32_t	TDR;
	volatile	uint32_t	PRESC;
	volatile	uint32_t	AUTOCR;
} LPUART_TypeDef;

#if (defined(__cplusplus))
#define	LPUART1_NS	reinterpret_cast<LPUART_TypeDef *>(0x46002400u)
#define	LPUART1_S	reinterpret_cast<LPUART_TypeDef *>(0x56002400u)

#else
#define	LPUART1_NS	((LPUART_TypeDef *)0x46002400u)
#define	LPUART1_S	((LPUART_TypeDef *)0x56002400u)
#endif

// CR1 Configuration

#define	LPUART_CR1_UE				(0x1u<<0)
#define	LPUART_CR1_UESM				(0x1u<<1)
#define	LPUART_CR1_RE				(0x1u<<2)
#define	LPUART_CR1_TE				(0x1u<<3)
#define	LPUART_CR1_IDLEIE			(0x1u<<4)
#define	LPUART_CR1_RXFNEIE			(0x1u<<5)
#define	LPUART_CR1_TCIE				(0x1u<<6)
#define	LPUART_CR1_TXFNFIE			(0x1u<<7)
#define	LPUART_CR1_PEIE				(0x1u<<8)
#define	LPUART_CR1_PS				(0x1u<<9)
#define	LPUART_CR1_PCE				(0x1u<<10)
#define	LPUART_CR1_WAKE				(0x1u<<11)
#define	LPUART_CR1_M0				(0x1u<<12)
#define	LPUART_CR1_MME				(0x1u<<13)
#define	LPUART_CR1_CMIE				(0x1u<<14)
#define	LPUART_CR1_DEDT				(0x1Fu<<16)
#define	LPUART_CR1_DEDT_0			(0x1u<<16)
#define	LPUART_CR1_DEAT				(0x1Fu<<21)
#define	LPUART_CR1_DEAT_0			(0x1u<<21)
#define	LPUART_CR1_M1				(0x1u<<28)
#define	LPUART_CR1_FIFOEN			(0x1u<<29)
#define	LPUART_CR1_TXFEIE			(0x1u<<30)
#define	LPUART_CR1_RXFFIE			(0x1u<<31)

// CR2 Configuration

#define	LPUART_CR2_ADDM7			(0x1u<<4)
#define	LPUART_CR2_STOP				(0x3u<<12)
#define	LPUART_CR2_STOP_0			(0x1u<<12)
#define	LPUART_CR2_SWAP				(0x1u<<15)
#define	LPUART_CR2_RXINV			(0x1u<<16)
#define	LPUART_CR2_TXINV			(0x1u<<17)
#define	LPUART_CR2_DATAINV			(0x1u<<18)
#define	LPUART_CR2_MSBFIRST			(0x1u<<19)
#define	LPUART_CR2_ADD				(0xFFu<<24)
#define	LPUART_CR2_ADD_0			(0x1u<<24)

// CR3 Configuration

#define	LPUART_CR3_EIE				(0x1u<<0)
#define	LPUART_CR3_HDSEL			(0x1u<<3)
#define	LPUART_CR3_DMAR				(0x1u<<6)
#define	LPUART_CR3_DMAT				(0x1u<<7)
#define	LPUART_CR3_RTSE				(0x1u<<8)
#define	LPUART_CR3_CTSE				(0x1u<<9)
#define	LPUART_CR3_CTSIE			(0x1u<<10)
#define	LPUART_CR3_OVRDIS			(0x1u<<12)
#define	LPUART_CR3_DDRE				(0x1u<<13)
#define	LPUART_CR3_DEM				(0x1u<<14)
#define	LPUART_CR3_DEP				(0x1u<<15)
#define	LPUART_CR3_TXFTIE			(0x1u<<23)
#define	LPUART_CR3_RXFTCFG			(0x7u<<25)
#define	LPUART_CR3_RXFTCFG_0		(0x1u<<25)
#define	LPUART_CR3_RXFTIE			(0x1u<<28)
#define	LPUART_CR3_TXFTCFG			(0x7u<<29)
#define	LPUART_CR3_TXFTCFG_0		(0x1u<<29)

// BRR Configuration

#define	LPUART_BRR_BRR				(0xFFFFFu<<0)
#define	LPUART_BRR_BRR_0			(0x1u<<0)

// RQR Configuration

#define	LPUART_RQR_SBKRQ			(0x1u<<1)
#define	LPUART_RQR_MMRQ				(0x1u<<2)
#define	LPUART_RQR_RXFRQ			(0x1u<<3)
#define	LPUART_RQR_TXFRQ			(0x1u<<4)

// ISR Configuration

#define	LPUART_ISR_PE				(0x1u<<0)
#define	LPUART_ISR_FE				(0x1u<<1)
#define	LPUART_ISR_NE				(0x1u<<2)
#define	LPUART_ISR_ORE				(0x1u<<3)
#define	LPUART_ISR_IDLE				(0x1u<<4)
#define	LPUART_ISR_RXFNE			(0x1u<<5)
#define	LPUART_ISR_TC				(0x1u<<6)
#define	LPUART_ISR_TXFNF			(0x1u<<7)
#define	LPUART_ISR_CTSIF			(0x1u<<9)
#define	LPUART_ISR_CTS				(0x1u<<10)
#define	LPUART_ISR_BUSY				(0x1u<<16)
#define	LPUART_ISR_CMF				(0x1u<<17)
#define	LPUART_ISR_SBKF				(0x1u<<18)
#define	LPUART_ISR_RWU				(0x1u<<19)
#define	LPUART_ISR_TEACK			(0x1u<<21)
#define	LPUART_ISR_REACK			(0x1u<<22)
#define	LPUART_ISR_TXFF				(0x1u<<23)
#define	LPUART_ISR_RXFF				(0x1u<<24)
#define	LPUART_ISR_RXFT				(0x1u<<26)
#define	LPUART_ISR_TXFT				(0x1u<<27)

// ICR Configuration

#define	LPUART_ICR_PECF				(0x1u<<0)
#define	LPUART_ICR_FECF				(0x1u<<1)
#define	LPUART_ICR_NECF				(0x1u<<2)
#define	LPUART_ICR_ORECF			(0x1u<<3)
#define	LPUART_ICR_IDLECF			(0x1u<<4)
#define	LPUART_ICR_TCCF				(0x1u<<6)
#define	LPUART_ICR_CTSCF			(0x1u<<9)
#define	LPUART_ICR_CMCF				(0x1u<<17)

// RDR Configuration

#define	LPUART_RDR_RDR				(0x1FFu<<0)
#define	LPUART_RDR_RDR_0			(0x1u<<0)

// TDR Configuration

#define	LPUART_TDR_TDR				(0x1FFu<<0)
#define	LPUART_TDR_TDR_0			(0x1u<<0)

// PRESC Configuration

#define	LPUART_PRESC_PRESCALER		(0xFu<<0)
#define	LPUART_PRESC_PRESCALER_0	(0x1u<<0)

// AUTOCR Configuration

#define	LPUART_AUTOCR_TRIGSEL		(0xFu<<19)
#define	LPUART_AUTOCR_TRIGSEL_0		(0x1u<<19)
#define	LPUART_AUTOCR_IDLEDIS		(0x1u<<18)
#define	LPUART_AUTOCR_TRIGEN		(0x1u<<17)
#define	LPUART_AUTOCR_TRIGPOL		(0x1u<<16)
#define	LPUART_AUTOCR_TDN			(0xFFFFu<<0)
#define	LPUART_AUTOCR_TDN_0			(0x1u<<0)
