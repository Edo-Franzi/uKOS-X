/*
; stm32H747_CM7_usart.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM7_usart equates.
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

// USART address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	CR1;
	volatile	uint32_t	CR2;
	volatile	uint32_t	CR3;
	volatile	uint32_t	BRR;
	volatile	uint32_t	GTPR;
	volatile	uint32_t	RTOR;
	volatile	uint32_t	RQR;
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	RDR;
	volatile	uint32_t	TDR;
	volatile	uint32_t	PRESC;
} USART_TypeDef;

#if (defined(__cplusplus))
#define	USART1	reinterpret_cast<USART_TypeDef *>(0x40011000u)
#define	USART2	reinterpret_cast<USART_TypeDef *>(0x40004400u)
#define	USART3	reinterpret_cast<USART_TypeDef *>(0x40004800u)
#define	UART4	reinterpret_cast<USART_TypeDef *>(0x40004C00u)
#define	UART5	reinterpret_cast<USART_TypeDef *>(0x40005000u)
#define	USART6	reinterpret_cast<USART_TypeDef *>(0x40011400u)
#define	UART7	reinterpret_cast<USART_TypeDef *>(0x40007800u)
#define	UART8	reinterpret_cast<USART_TypeDef *>(0x40007C00u)

#else
#define	USART1	((USART_TypeDef *)0x40011000u)
#define	USART2	((USART_TypeDef *)0x40004400u)
#define	USART3	((USART_TypeDef *)0x40004800u)
#define	UART4	((USART_TypeDef *)0x40004C00u)
#define	UART5	((USART_TypeDef *)0x40005000u)
#define	USART6	((USART_TypeDef *)0x40011400u)
#define	UART7	((USART_TypeDef *)0x40007800u)
#define	UART8	((USART_TypeDef *)0x40007C00u)
#endif

// CR1 Configuration

#define	USART_CR1_UE			(0x1u<<0)
#define	USART_CR1_UESM			(0x1u<<1)
#define	USART_CR1_RE			(0x1u<<2)
#define	USART_CR1_TE			(0x1u<<3)
#define	USART_CR1_IDLEIE		(0x1u<<4)
#define	USART_CR1_RXNEIE		(0x1u<<5)
#define	USART_CR1_TCIE			(0x1u<<6)
#define	USART_CR1_TXEIE			(0x1u<<7)
#define	USART_CR1_PEIE			(0x1u<<8)
#define	USART_CR1_PS			(0x1u<<9)
#define	USART_CR1_PCE			(0x1u<<10)
#define	USART_CR1_WAKE			(0x1u<<11)
#define	USART_CR1_M0			(0x1u<<12)
#define	USART_CR1_MME			(0x1u<<13)
#define	USART_CR1_CMIE			(0x1u<<14)
#define	USART_CR1_OVER8			(0x1u<<15)
#define	USART_CR1_DEDT0			(0x1u<<16)
#define	USART_CR1_DEDT1			(0x1u<<17)
#define	USART_CR1_DEDT2			(0x1u<<18)
#define	USART_CR1_DEDT3			(0x1u<<19)
#define	USART_CR1_DEDT4			(0x1u<<20)
#define	USART_CR1_DEAT0			(0x1u<<21)
#define	USART_CR1_DEAT1			(0x1u<<22)
#define	USART_CR1_DEAT2			(0x1u<<23)
#define	USART_CR1_DEAT3			(0x1u<<24)
#define	USART_CR1_DEAT4			(0x1u<<25)
#define	USART_CR1_RTOIE			(0x1u<<26)
#define	USART_CR1_EOBIE			(0x1u<<27)
#define	USART_CR1_M1			(0x1u<<28)
#define	USART_CR1_FIFOEN		(0x1u<<29)
#define	USART_CR1_TXFEIE		(0x1u<<30)
#define	USART_CR1_RXFFIE		(0x1u<<31)

// CR2 Configuration

#define	USART_CR2_SLVEN			(0x1u<<0)
#define	USART_CR2_DIS_NSS		(0x1u<<3)
#define	USART_CR2_ADDM7			(0x1u<<4)
#define	USART_CR2_LBDL			(0x1u<<5)
#define	USART_CR2_LBDIE			(0x1u<<6)
#define	USART_CR2_LBCL			(0x1u<<8)
#define	USART_CR2_CPHA			(0x1u<<9)
#define	USART_CR2_CPOL			(0x1u<<10)
#define	USART_CR2_CLKEN			(0x1u<<11)
#define	USART_CR2_STOP			(0x3u<<12)
#define	USART_CR2_STOP_0		(0x1u<<12)
#define	USART_CR2_LINEN			(0x1u<<14)
#define	USART_CR2_SWAP			(0x1u<<15)
#define	USART_CR2_RXINV			(0x1u<<16)
#define	USART_CR2_TXINV			(0x1u<<17)
#define	USART_CR2_TAINV			(0x1u<<18)
#define	USART_CR2_MSBFIRST		(0x1u<<19)
#define	USART_CR2_ABREN			(0x1u<<20)
#define	USART_CR2_ABRMOD0		(0x1u<<21)
#define	USART_CR2_ABRMOD1		(0x1u<<22)
#define	USART_CR2_RTOEN			(0x1u<<23)
#define	USART_CR2_ADD0_3		(0xFu<<24)
#define	USART_CR2_ADD0_3_0		(0x1u<<24)
#define	USART_CR2_ADD4_7		(0xFu<<28)
#define	USART_CR2_ADD4_7_0		(0x1u<<28)

// CR3 Configuration

#define	USART_CR3_EIE			(0x1u<<0)
#define	USART_CR3_IREN			(0x1u<<1)
#define	USART_CR3_IRLP			(0x1u<<2)
#define	USART_CR3_HDSEL			(0x1u<<3)
#define	USART_CR3_NACK			(0x1u<<4)
#define	USART_CR3_SCEN			(0x1u<<5)
#define	USART_CR3_DMAR			(0x1u<<6)
#define	USART_CR3_DMAT			(0x1u<<7)
#define	USART_CR3_RTSE			(0x1u<<8)
#define	USART_CR3_CTSE			(0x1u<<9)
#define	USART_CR3_CTSIE			(0x1u<<10)
#define	USART_CR3_ONEBIT		(0x1u<<11)
#define	USART_CR3_OVRDIS		(0x1u<<12)
#define	USART_CR3_DDRE			(0x1u<<13)
#define	USART_CR3_DEM			(0x1u<<14)
#define	USART_CR3_DEP			(0x1u<<15)
#define	USART_CR3_SCARCNT		(0x7u<<17)
#define	USART_CR3_SCARCNT_0		(0x1u<<17)
#define	USART_CR3_WUS			(0x3u<<20)
#define	USART_CR3_WUS_0			(0x1u<<20)
#define	USART_CR3_WUFIE			(0x1u<<22)
#define	USART_CR3_TXFTIE		(0x1u<<23)
#define	USART_CR3_TCBGTIE		(0x1u<<24)
#define	USART_CR3_RXFTCFG		(0x7u<<25)
#define	USART_CR3_RXFTCFG_0		(0x1u<<25)
#define	USART_CR3_RXFTIE		(0x1u<<28)
#define	USART_CR3_TXFTCFG		(0x7u<<29)
#define	USART_CR3_TXFTCFG_0		(0x1u<<29)

// BRR Configuration

#define	USART_BRR_BRR_0_3		(0xFu<<0)
#define	USART_BRR_BRR_0_3_0		(0x1u<<0)
#define	USART_BRR_BRR_4_15		(0xFFFu<<4)
#define	USART_BRR_BRR_4_15_0	(0x1u<<4)

// GTPR Configuration

#define	USART_GTPR_PSC			(0xFFu<<0)
#define	USART_GTPR_PSC_0		(0x1u<<0)
#define	USART_GTPR_GT			(0xFFu<<8)
#define	USART_GTPR_GT_0			(0x1u<<8)

// RTOR Configuration

#define	USART_RTOR_RTO			(0xFFFFFFu<<0)
#define	USART_RTOR_RTO_0		(0x1u<<0)
#define	USART_RTOR_BLEN			(0xFFu<<24)
#define	USART_RTOR_BLEN_0		(0x1u<<24)

// RQR Configuration

#define	USART_RQR_ABRRQ			(0x1u<<0)
#define	USART_RQR_SBKRQ			(0x1u<<1)
#define	USART_RQR_MMRQ			(0x1u<<2)
#define	USART_RQR_RXFRQ			(0x1u<<3)
#define	USART_RQR_TXFRQ			(0x1u<<4)

// ISR Configuration

#define	USART_ISR_PE			(0x1u<<0)
#define	USART_ISR_FE			(0x1u<<1)
#define	USART_ISR_NF			(0x1u<<2)
#define	USART_ISR_ORE			(0x1u<<3)
#define	USART_ISR_IDLE			(0x1u<<4)
#define	USART_ISR_RXNE			(0x1u<<5)
#define	USART_ISR_TC			(0x1u<<6)
#define	USART_ISR_TXE			(0x1u<<7)
#define	USART_ISR_LBDF			(0x1u<<8)
#define	USART_ISR_CTSIF			(0x1u<<9)
#define	USART_ISR_CTS			(0x1u<<10)
#define	USART_ISR_RTOF			(0x1u<<11)
#define	USART_ISR_EOBF			(0x1u<<12)
#define	USART_ISR_UDR			(0x1u<<13)
#define	USART_ISR_ABRE			(0x1u<<14)
#define	USART_ISR_ABRF			(0x1u<<15)
#define	USART_ISR_BUSY			(0x1u<<16)
#define	USART_ISR_CMF			(0x1u<<17)
#define	USART_ISR_SBKF			(0x1u<<18)
#define	USART_ISR_RWU			(0x1u<<19)
#define	USART_ISR_WUF			(0x1u<<20)
#define	USART_ISR_TEACK			(0x1u<<21)
#define	USART_ISR_REACK			(0x1u<<22)
#define	USART_ISR_TXFE			(0x1u<<23)
#define	USART_ISR_RXFF			(0x1u<<24)
#define	USART_ISR_TCBGT			(0x1u<<25)
#define	USART_ISR_RXFT			(0x1u<<26)
#define	USART_ISR_TXFT			(0x1u<<27)

// ICR Configuration

#define	USART_ICR_PECF			(0x1u<<0)
#define	USART_ICR_FECF			(0x1u<<1)
#define	USART_ICR_NCF			(0x1u<<2)
#define	USART_ICR_ORECF			(0x1u<<3)
#define	USART_ICR_IDLECF		(0x1u<<4)
#define	USART_ICR_TXFECF		(0x1u<<5)
#define	USART_ICR_TCCF			(0x1u<<6)
#define	USART_ICR_TCBGTC		(0x1u<<7)
#define	USART_ICR_LBDCF			(0x1u<<8)
#define	USART_ICR_CTSCF			(0x1u<<9)
#define	USART_ICR_RTOCF			(0x1u<<11)
#define	USART_ICR_EOBCF			(0x1u<<12)
#define	USART_ICR_UDRCF			(0x1u<<13)
#define	USART_ICR_CMCF			(0x1u<<17)
#define	USART_ICR_WUCF			(0x1u<<20)

// RDR Configuration

#define	USART_RDR_RDR			(0x1FFu<<0)
#define	USART_RDR_RDR_0			(0x1u<<0)

// TDR Configuration

#define	USART_TDR_TDR			(0x1FFu<<0)
#define	USART_TDR_TDR_0			(0x1u<<0)

// PRESC Configuration

#define	USART_PRESC_PRESCALER	(0xFu<<0)
#define	USART_PRESC_PRESCALER_0	(0x1u<<0)
