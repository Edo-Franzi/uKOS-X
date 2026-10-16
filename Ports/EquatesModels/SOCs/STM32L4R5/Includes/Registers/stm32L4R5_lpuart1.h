/*
; stm32L4R5_lpuart1.
; ==================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_lpuart1 equates.
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

// LPUART1 address definitions
// ---------------------------

typedef struct {
		union {
	volatile	uint32_t	CR1;
	volatile	uint32_t	CR1_ALTERNATE;
		};
	volatile	uint32_t	CR2;
	volatile	uint32_t	CR3;
	volatile	uint32_t	BRR;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	RQR;
		union {
	volatile	uint32_t	ISR;
	volatile	uint32_t	ISR_ALTERNATE;
		};
	volatile	uint32_t	ICR;
	volatile	uint32_t	RDR;
	volatile	uint32_t	TDR;
	volatile	uint32_t	PRESC;
} LPUART1_TypeDef;

#if (defined(__cplusplus))
#define	LPUART1	reinterpret_cast<LPUART1_TypeDef *>(0x40008000u)

#else
#define	LPUART1	((LPUART1_TypeDef *)0x40008000u)
#endif

// CR1 Configuration

#define	LPUART1_CR1_RXFFIE					(0x1u<<31)
#define	LPUART1_CR1_TXFEIE					(0x1u<<30)
#define	LPUART1_CR1_FIFOEN					(0x1u<<29)
#define	LPUART1_CR1_M1						(0x1u<<28)
#define	LPUART1_CR1_DEAT					(0x1Fu<<21)
#define	LPUART1_CR1_DEAT_0					(0x1u<<21)
#define	LPUART1_CR1_DEDT					(0x1Fu<<16)
#define	LPUART1_CR1_DEDT_0					(0x1u<<16)
#define	LPUART1_CR1_CMIE					(0x1u<<14)
#define	LPUART1_CR1_MME						(0x1u<<13)
#define	LPUART1_CR1_M0						(0x1u<<12)
#define	LPUART1_CR1_WAKE					(0x1u<<11)
#define	LPUART1_CR1_PCE						(0x1u<<10)
#define	LPUART1_CR1_PS						(0x1u<<9)
#define	LPUART1_CR1_PEIE					(0x1u<<8)
#define	LPUART1_CR1_TXFNFIE					(0x1u<<7)
#define	LPUART1_CR1_TCIE					(0x1u<<6)
#define	LPUART1_CR1_RXFNEIE					(0x1u<<5)
#define	LPUART1_CR1_IDLEIE					(0x1u<<4)
#define	LPUART1_CR1_TE						(0x1u<<3)
#define	LPUART1_CR1_RE						(0x1u<<2)
#define	LPUART1_CR1_UESM					(0x1u<<1)
#define	LPUART1_CR1_UE						(0x1u<<0)
#define	LPUART1_CR1_RXFFIE_B_0X0			(0x0u<<31)
#define	LPUART1_CR1_RXFFIE_B_0X1			(0x1u<<31)
#define	LPUART1_CR1_TXFEIE_B_0X0			(0x0u<<30)
#define	LPUART1_CR1_TXFEIE_B_0X1			(0x1u<<30)
#define	LPUART1_CR1_FIFOEN_B_0X0			(0x0u<<29)
#define	LPUART1_CR1_FIFOEN_B_0X1			(0x1u<<29)
#define	LPUART1_CR1_CMIE_B_0X0				(0x0u<<14)
#define	LPUART1_CR1_CMIE_B_0X1				(0x1u<<14)
#define	LPUART1_CR1_MME_B_0X0				(0x0u<<13)
#define	LPUART1_CR1_MME_B_0X1				(0x1u<<13)
#define	LPUART1_CR1_WAKE_B_0X0				(0x0u<<11)
#define	LPUART1_CR1_WAKE_B_0X1				(0x1u<<11)
#define	LPUART1_CR1_PCE_B_0X0				(0x0u<<10)
#define	LPUART1_CR1_PCE_B_0X1				(0x1u<<10)
#define	LPUART1_CR1_PS_B_0X0				(0x0u<<9)
#define	LPUART1_CR1_PS_B_0X1				(0x1u<<9)
#define	LPUART1_CR1_PEIE_B_0X0				(0x0u<<8)
#define	LPUART1_CR1_PEIE_B_0X1				(0x1u<<8)
#define	LPUART1_CR1_TXFNFIE_B_0X0			(0x0u<<7)
#define	LPUART1_CR1_TXFNFIE_B_0X1			(0x1u<<7)
#define	LPUART1_CR1_TCIE_B_0X0				(0x0u<<6)
#define	LPUART1_CR1_TCIE_B_0X1				(0x1u<<6)
#define	LPUART1_CR1_RXFNEIE_B_0X0			(0x0u<<5)
#define	LPUART1_CR1_RXFNEIE_B_0X1			(0x1u<<5)
#define	LPUART1_CR1_IDLEIE_B_0X0			(0x0u<<4)
#define	LPUART1_CR1_IDLEIE_B_0X1			(0x1u<<4)
#define	LPUART1_CR1_TE_B_0X0				(0x0u<<3)
#define	LPUART1_CR1_TE_B_0X1				(0x1u<<3)
#define	LPUART1_CR1_RE_B_0X0				(0x0u<<2)
#define	LPUART1_CR1_RE_B_0X1				(0x1u<<2)
#define	LPUART1_CR1_UESM_B_0X0				(0x0u<<1)
#define	LPUART1_CR1_UESM_B_0X1				(0x1u<<1)
#define	LPUART1_CR1_UE_B_0X0				(0x0u<<0)
#define	LPUART1_CR1_UE_B_0X1				(0x1u<<0)

// CR1_ALTERNATE Configuration

#define	LPUART1_CR1_ALTERNATE_FIFOEN		(0x1u<<29)
#define	LPUART1_CR1_ALTERNATE_M1			(0x1u<<28)
#define	LPUART1_CR1_ALTERNATE_DEAT			(0x1Fu<<21)
#define	LPUART1_CR1_ALTERNATE_DEAT_0		(0x1u<<21)
#define	LPUART1_CR1_ALTERNATE_DEDT			(0x1Fu<<16)
#define	LPUART1_CR1_ALTERNATE_DEDT_0		(0x1u<<16)
#define	LPUART1_CR1_ALTERNATE_CMIE			(0x1u<<14)
#define	LPUART1_CR1_ALTERNATE_MME			(0x1u<<13)
#define	LPUART1_CR1_ALTERNATE_M0			(0x1u<<12)
#define	LPUART1_CR1_ALTERNATE_WAKE			(0x1u<<11)
#define	LPUART1_CR1_ALTERNATE_PCE			(0x1u<<10)
#define	LPUART1_CR1_ALTERNATE_PS			(0x1u<<9)
#define	LPUART1_CR1_ALTERNATE_PEIE			(0x1u<<8)
#define	LPUART1_CR1_ALTERNATE_TXEIE			(0x1u<<7)
#define	LPUART1_CR1_ALTERNATE_TCIE			(0x1u<<6)
#define	LPUART1_CR1_ALTERNATE_RXNEIE		(0x1u<<5)
#define	LPUART1_CR1_ALTERNATE_IDLEIE		(0x1u<<4)
#define	LPUART1_CR1_ALTERNATE_TE			(0x1u<<3)
#define	LPUART1_CR1_ALTERNATE_RE			(0x1u<<2)
#define	LPUART1_CR1_ALTERNATE_UESM			(0x1u<<1)
#define	LPUART1_CR1_ALTERNATE_UE			(0x1u<<0)
#define	LPUART1_CR1_ALTERNATE_FIFOEN_B_0X0	(0x0u<<29)
#define	LPUART1_CR1_ALTERNATE_FIFOEN_B_0X1	(0x1u<<29)
#define	LPUART1_CR1_ALTERNATE_CMIE_B_0X0	(0x0u<<14)
#define	LPUART1_CR1_ALTERNATE_CMIE_B_0X1	(0x1u<<14)
#define	LPUART1_CR1_ALTERNATE_MME_B_0X0		(0x0u<<13)
#define	LPUART1_CR1_ALTERNATE_MME_B_0X1		(0x1u<<13)
#define	LPUART1_CR1_ALTERNATE_WAKE_B_0X0	(0x0u<<11)
#define	LPUART1_CR1_ALTERNATE_WAKE_B_0X1	(0x1u<<11)
#define	LPUART1_CR1_ALTERNATE_PCE_B_0X0		(0x0u<<10)
#define	LPUART1_CR1_ALTERNATE_PCE_B_0X1		(0x1u<<10)
#define	LPUART1_CR1_ALTERNATE_PS_B_0X0		(0x0u<<9)
#define	LPUART1_CR1_ALTERNATE_PS_B_0X1		(0x1u<<9)
#define	LPUART1_CR1_ALTERNATE_PEIE_B_0X0	(0x0u<<8)
#define	LPUART1_CR1_ALTERNATE_PEIE_B_0X1	(0x1u<<8)
#define	LPUART1_CR1_ALTERNATE_TXEIE_B_0X0	(0x0u<<7)
#define	LPUART1_CR1_ALTERNATE_TXEIE_B_0X1	(0x1u<<7)
#define	LPUART1_CR1_ALTERNATE_TCIE_B_0X0	(0x0u<<6)
#define	LPUART1_CR1_ALTERNATE_TCIE_B_0X1	(0x1u<<6)
#define	LPUART1_CR1_ALTERNATE_RXNEIE_B_0X0	(0x0u<<5)
#define	LPUART1_CR1_ALTERNATE_RXNEIE_B_0X1	(0x1u<<5)
#define	LPUART1_CR1_ALTERNATE_IDLEIE_B_0X0	(0x0u<<4)
#define	LPUART1_CR1_ALTERNATE_IDLEIE_B_0X1	(0x1u<<4)
#define	LPUART1_CR1_ALTERNATE_TE_B_0X0		(0x0u<<3)
#define	LPUART1_CR1_ALTERNATE_TE_B_0X1		(0x1u<<3)
#define	LPUART1_CR1_ALTERNATE_RE_B_0X0		(0x0u<<2)
#define	LPUART1_CR1_ALTERNATE_RE_B_0X1		(0x1u<<2)
#define	LPUART1_CR1_ALTERNATE_UESM_B_0X0	(0x0u<<1)
#define	LPUART1_CR1_ALTERNATE_UESM_B_0X1	(0x1u<<1)
#define	LPUART1_CR1_ALTERNATE_UE_B_0X0		(0x0u<<0)
#define	LPUART1_CR1_ALTERNATE_UE_B_0X1		(0x1u<<0)

// CR2 Configuration

#define	LPUART1_CR2_ADD						(0xFFu<<24)
#define	LPUART1_CR2_ADD_0					(0x1u<<24)
#define	LPUART1_CR2_MSBFIRST				(0x1u<<19)
#define	LPUART1_CR2_DATAINV					(0x1u<<18)
#define	LPUART1_CR2_TXINV					(0x1u<<17)
#define	LPUART1_CR2_RXINV					(0x1u<<16)
#define	LPUART1_CR2_SWAP					(0x1u<<15)
#define	LPUART1_CR2_STOP					(0x3u<<12)
#define	LPUART1_CR2_STOP_0					(0x1u<<12)
#define	LPUART1_CR2_ADDM7					(0x1u<<4)
#define	LPUART1_CR2_MSBFIRST_B_0X0			(0x0u<<19)
#define	LPUART1_CR2_MSBFIRST_B_0X1			(0x1u<<19)
#define	LPUART1_CR2_DATAINV_B_0X0			(0x0u<<18)
#define	LPUART1_CR2_DATAINV_B_0X1			(0x1u<<18)
#define	LPUART1_CR2_TXINV_B_0X0				(0x0u<<17)
#define	LPUART1_CR2_TXINV_B_0X1				(0x1u<<17)
#define	LPUART1_CR2_RXINV_B_0X0				(0x0u<<16)
#define	LPUART1_CR2_RXINV_B_0X1				(0x1u<<16)
#define	LPUART1_CR2_SWAP_B_0X0				(0x0u<<15)
#define	LPUART1_CR2_SWAP_B_0X1				(0x1u<<15)
#define	LPUART1_CR2_STOP_B_0X0				(0x0u<<12)
#define	LPUART1_CR2_ADDM7_B_0X0				(0x0u<<4)
#define	LPUART1_CR2_ADDM7_B_0X1				(0x1u<<4)

// CR3 Configuration

#define	LPUART1_CR3_TXFTCFG					(0x7u<<29)
#define	LPUART1_CR3_TXFTCFG_0				(0x1u<<29)
#define	LPUART1_CR3_RXFTIE					(0x1u<<28)
#define	LPUART1_CR3_RXFTCFG					(0x7u<<25)
#define	LPUART1_CR3_RXFTCFG_0				(0x1u<<25)
#define	LPUART1_CR3_TXFTIE					(0x1u<<23)
#define	LPUART1_CR3_WUFIE					(0x1u<<22)
#define	LPUART1_CR3_WUS						(0x3u<<20)
#define	LPUART1_CR3_WUS_0					(0x1u<<20)
#define	LPUART1_CR3_DEP						(0x1u<<15)
#define	LPUART1_CR3_DEM						(0x1u<<14)
#define	LPUART1_CR3_DDRE					(0x1u<<13)
#define	LPUART1_CR3_OVRDIS					(0x1u<<12)
#define	LPUART1_CR3_CTSIE					(0x1u<<10)
#define	LPUART1_CR3_CTSE					(0x1u<<9)
#define	LPUART1_CR3_RTSE					(0x1u<<8)
#define	LPUART1_CR3_DMAT					(0x1u<<7)
#define	LPUART1_CR3_DMAR					(0x1u<<6)
#define	LPUART1_CR3_HDSEL					(0x1u<<3)
#define	LPUART1_CR3_EIE						(0x1u<<0)
#define	LPUART1_CR3_TXFTCFG_B_0X0			(0x0u<<29)
#define	LPUART1_CR3_TXFTCFG_B_0X1			(0x1u<<29)
#define	LPUART1_CR3_TXFTCFG_B_0X6			(0x6u<<29)
#define	LPUART1_CR3_TXFTCFG_B_0X3			(0x3u<<29)
#define	LPUART1_CR3_TXFTCFG_B_0X4			(0x4u<<29)
#define	LPUART1_CR3_TXFTCFG_B_0X5			(0x5u<<29)
#define	LPUART1_CR3_RXFTIE_B_0X0			(0x0u<<28)
#define	LPUART1_CR3_RXFTIE_B_0X1			(0x1u<<28)
#define	LPUART1_CR3_RXFTCFG_B_0X0			(0x0u<<25)
#define	LPUART1_CR3_RXFTCFG_B_0X1			(0x1u<<25)
#define	LPUART1_CR3_RXFTCFG_B_0X6			(0x6u<<25)
#define	LPUART1_CR3_RXFTCFG_B_0X3			(0x3u<<25)
#define	LPUART1_CR3_RXFTCFG_B_0X4			(0x4u<<25)
#define	LPUART1_CR3_RXFTCFG_B_0X5			(0x5u<<25)
#define	LPUART1_CR3_TXFTIE_B_0X0			(0x0u<<23)
#define	LPUART1_CR3_TXFTIE_B_0X1			(0x1u<<23)
#define	LPUART1_CR3_WUFIE_B_0X0				(0x0u<<22)
#define	LPUART1_CR3_WUFIE_B_0X1				(0x1u<<22)
#define	LPUART1_CR3_WUS_B_0X0				(0x0u<<20)
#define	LPUART1_CR3_WUS_B_0X2				(0x2u<<20)
#define	LPUART1_CR3_WUS_B_0X3				(0x3u<<20)
#define	LPUART1_CR3_DEP_B_0X0				(0x0u<<15)
#define	LPUART1_CR3_DEP_B_0X1				(0x1u<<15)
#define	LPUART1_CR3_DEM_B_0X0				(0x0u<<14)
#define	LPUART1_CR3_DEM_B_0X1				(0x1u<<14)
#define	LPUART1_CR3_DDRE_B_0X0				(0x0u<<13)
#define	LPUART1_CR3_DDRE_B_0X1				(0x1u<<13)
#define	LPUART1_CR3_OVRDIS_B_0X0			(0x0u<<12)
#define	LPUART1_CR3_OVRDIS_B_0X1			(0x1u<<12)
#define	LPUART1_CR3_CTSIE_B_0X0				(0x0u<<10)
#define	LPUART1_CR3_CTSIE_B_0X1				(0x1u<<10)
#define	LPUART1_CR3_CTSE_B_0X0				(0x0u<<9)
#define	LPUART1_CR3_CTSE_B_0X1				(0x1u<<9)
#define	LPUART1_CR3_RTSE_B_0X0				(0x0u<<8)
#define	LPUART1_CR3_RTSE_B_0X1				(0x1u<<8)
#define	LPUART1_CR3_DMAT_B_0X1				(0x1u<<7)
#define	LPUART1_CR3_DMAT_B_0X0				(0x0u<<7)
#define	LPUART1_CR3_DMAR_B_0X1				(0x1u<<6)
#define	LPUART1_CR3_DMAR_B_0X0				(0x0u<<6)
#define	LPUART1_CR3_HDSEL_B_0X0				(0x0u<<3)
#define	LPUART1_CR3_HDSEL_B_0X1				(0x1u<<3)
#define	LPUART1_CR3_EIE_B_0X0				(0x0u<<0)
#define	LPUART1_CR3_EIE_B_0X1				(0x1u<<0)

// BRR Configuration

#define	LPUART1_BRR_BRR						(0xFFFFFu<<0)
#define	LPUART1_BRR_BRR_0					(0x1u<<0)

// RQR Configuration

#define	LPUART1_RQR_TXFRQ					(0x1u<<4)
#define	LPUART1_RQR_RXFRQ					(0x1u<<3)
#define	LPUART1_RQR_MMRQ					(0x1u<<2)
#define	LPUART1_RQR_SBKRQ					(0x1u<<1)

// ISR Configuration

#define	LPUART1_ISR_TXFT					(0x1u<<27)
#define	LPUART1_ISR_RXFT					(0x1u<<26)
#define	LPUART1_ISR_RXFF					(0x1u<<24)
#define	LPUART1_ISR_TXFE					(0x1u<<23)
#define	LPUART1_ISR_REACK					(0x1u<<22)
#define	LPUART1_ISR_TEACK					(0x1u<<21)
#define	LPUART1_ISR_WUF						(0x1u<<20)
#define	LPUART1_ISR_RWU						(0x1u<<19)
#define	LPUART1_ISR_SBKF					(0x1u<<18)
#define	LPUART1_ISR_CMF						(0x1u<<17)
#define	LPUART1_ISR_BUSY					(0x1u<<16)
#define	LPUART1_ISR_CTS						(0x1u<<10)
#define	LPUART1_ISR_CTSIF					(0x1u<<9)
#define	LPUART1_ISR_TXFNF					(0x1u<<7)
#define	LPUART1_ISR_TC						(0x1u<<6)
#define	LPUART1_ISR_RXFNE					(0x1u<<5)
#define	LPUART1_ISR_IDLE					(0x1u<<4)
#define	LPUART1_ISR_ORE						(0x1u<<3)
#define	LPUART1_ISR_NE						(0x1u<<2)
#define	LPUART1_ISR_FE						(0x1u<<1)
#define	LPUART1_ISR_PE						(0x1u<<0)
#define	LPUART1_ISR_TXFT_B_0X0				(0x0u<<27)
#define	LPUART1_ISR_TXFT_B_0X1				(0x1u<<27)
#define	LPUART1_ISR_RXFT_B_0X0				(0x0u<<26)
#define	LPUART1_ISR_RXFT_B_0X1				(0x1u<<26)
#define	LPUART1_ISR_RXFF_B_0X0				(0x0u<<24)
#define	LPUART1_ISR_RXFF_B_0X1				(0x1u<<24)
#define	LPUART1_ISR_TXFE_B_0X0				(0x0u<<23)
#define	LPUART1_ISR_TXFE_B_0X1				(0x1u<<23)
#define	LPUART1_ISR_RWU_B_0X0				(0x0u<<19)
#define	LPUART1_ISR_RWU_B_0X1				(0x1u<<19)
#define	LPUART1_ISR_SBKF_B_0X0				(0x0u<<18)
#define	LPUART1_ISR_SBKF_B_0X1				(0x1u<<18)
#define	LPUART1_ISR_CMF_B_0X0				(0x0u<<17)
#define	LPUART1_ISR_CMF_B_0X1				(0x1u<<17)
#define	LPUART1_ISR_BUSY_B_0X0				(0x0u<<16)
#define	LPUART1_ISR_BUSY_B_0X1				(0x1u<<16)
#define	LPUART1_ISR_CTS_B_0X0				(0x0u<<10)
#define	LPUART1_ISR_CTS_B_0X1				(0x1u<<10)
#define	LPUART1_ISR_CTSIF_B_0X0				(0x0u<<9)
#define	LPUART1_ISR_CTSIF_B_0X1				(0x1u<<9)
#define	LPUART1_ISR_TXFNF_B_0X0				(0x0u<<7)
#define	LPUART1_ISR_TXFNF_B_0X1				(0x1u<<7)
#define	LPUART1_ISR_TC_B_0X0				(0x0u<<6)
#define	LPUART1_ISR_TC_B_0X1				(0x1u<<6)
#define	LPUART1_ISR_RXFNE_B_0X0				(0x0u<<5)
#define	LPUART1_ISR_RXFNE_B_0X1				(0x1u<<5)
#define	LPUART1_ISR_IDLE_B_0X0				(0x0u<<4)
#define	LPUART1_ISR_IDLE_B_0X1				(0x1u<<4)
#define	LPUART1_ISR_ORE_B_0X0				(0x0u<<3)
#define	LPUART1_ISR_ORE_B_0X1				(0x1u<<3)
#define	LPUART1_ISR_NE_B_0X0				(0x0u<<2)
#define	LPUART1_ISR_NE_B_0X1				(0x1u<<2)
#define	LPUART1_ISR_FE_B_0X0				(0x0u<<1)
#define	LPUART1_ISR_FE_B_0X1				(0x1u<<1)
#define	LPUART1_ISR_PE_B_0X0				(0x0u<<0)
#define	LPUART1_ISR_PE_B_0X1				(0x1u<<0)

// ISR_ALTERNATE Configuration

#define	LPUART1_ISR_ALTERNATE_REACK			(0x1u<<22)
#define	LPUART1_ISR_ALTERNATE_TEACK			(0x1u<<21)
#define	LPUART1_ISR_ALTERNATE_WUF			(0x1u<<20)
#define	LPUART1_ISR_ALTERNATE_RWU			(0x1u<<19)
#define	LPUART1_ISR_ALTERNATE_SBKF			(0x1u<<18)
#define	LPUART1_ISR_ALTERNATE_CMF			(0x1u<<17)
#define	LPUART1_ISR_ALTERNATE_BUSY			(0x1u<<16)
#define	LPUART1_ISR_ALTERNATE_CTS			(0x1u<<10)
#define	LPUART1_ISR_ALTERNATE_CTSIF			(0x1u<<9)
#define	LPUART1_ISR_ALTERNATE_TXE			(0x1u<<7)
#define	LPUART1_ISR_ALTERNATE_TC			(0x1u<<6)
#define	LPUART1_ISR_ALTERNATE_RXNE			(0x1u<<5)
#define	LPUART1_ISR_ALTERNATE_IDLE			(0x1u<<4)
#define	LPUART1_ISR_ALTERNATE_ORE			(0x1u<<3)
#define	LPUART1_ISR_ALTERNATE_NE			(0x1u<<2)
#define	LPUART1_ISR_ALTERNATE_FE			(0x1u<<1)
#define	LPUART1_ISR_ALTERNATE_PE			(0x1u<<0)
#define	LPUART1_ISR_ALTERNATE_RWU_B_0X0		(0x0u<<19)
#define	LPUART1_ISR_ALTERNATE_RWU_B_0X1		(0x1u<<19)
#define	LPUART1_ISR_ALTERNATE_SBKF_B_0X0	(0x0u<<18)
#define	LPUART1_ISR_ALTERNATE_SBKF_B_0X1	(0x1u<<18)
#define	LPUART1_ISR_ALTERNATE_CMF_B_0X0		(0x0u<<17)
#define	LPUART1_ISR_ALTERNATE_CMF_B_0X1		(0x1u<<17)
#define	LPUART1_ISR_ALTERNATE_BUSY_B_0X0	(0x0u<<16)
#define	LPUART1_ISR_ALTERNATE_BUSY_B_0X1	(0x1u<<16)
#define	LPUART1_ISR_ALTERNATE_CTS_B_0X0		(0x0u<<10)
#define	LPUART1_ISR_ALTERNATE_CTS_B_0X1		(0x1u<<10)
#define	LPUART1_ISR_ALTERNATE_CTSIF_B_0X0	(0x0u<<9)
#define	LPUART1_ISR_ALTERNATE_CTSIF_B_0X1	(0x1u<<9)
#define	LPUART1_ISR_ALTERNATE_TXE_B_0X0		(0x0u<<7)
#define	LPUART1_ISR_ALTERNATE_TXE_B_0X1		(0x1u<<7)
#define	LPUART1_ISR_ALTERNATE_TC_B_0X0		(0x0u<<6)
#define	LPUART1_ISR_ALTERNATE_TC_B_0X1		(0x1u<<6)
#define	LPUART1_ISR_ALTERNATE_RXNE_B_0X0	(0x0u<<5)
#define	LPUART1_ISR_ALTERNATE_RXNE_B_0X1	(0x1u<<5)
#define	LPUART1_ISR_ALTERNATE_IDLE_B_0X0	(0x0u<<4)
#define	LPUART1_ISR_ALTERNATE_IDLE_B_0X1	(0x1u<<4)
#define	LPUART1_ISR_ALTERNATE_ORE_B_0X0		(0x0u<<3)
#define	LPUART1_ISR_ALTERNATE_ORE_B_0X1		(0x1u<<3)
#define	LPUART1_ISR_ALTERNATE_NE_B_0X0		(0x0u<<2)
#define	LPUART1_ISR_ALTERNATE_NE_B_0X1		(0x1u<<2)
#define	LPUART1_ISR_ALTERNATE_FE_B_0X0		(0x0u<<1)
#define	LPUART1_ISR_ALTERNATE_FE_B_0X1		(0x1u<<1)
#define	LPUART1_ISR_ALTERNATE_PE_B_0X0		(0x0u<<0)
#define	LPUART1_ISR_ALTERNATE_PE_B_0X1		(0x1u<<0)

// ICR Configuration

#define	LPUART1_ICR_WUCF					(0x1u<<20)
#define	LPUART1_ICR_CMCF					(0x1u<<17)
#define	LPUART1_ICR_CTSCF					(0x1u<<9)
#define	LPUART1_ICR_TCCF					(0x1u<<6)
#define	LPUART1_ICR_IDLECF					(0x1u<<4)
#define	LPUART1_ICR_ORECF					(0x1u<<3)
#define	LPUART1_ICR_NECF					(0x1u<<2)
#define	LPUART1_ICR_FECF					(0x1u<<1)
#define	LPUART1_ICR_PECF					(0x1u<<0)

// RDR Configuration

#define	LPUART1_RDR_RDR						(0x1FFu<<0)
#define	LPUART1_RDR_RDR_0					(0x1u<<0)

// TDR Configuration

#define	LPUART1_TDR_TDR						(0x1FFu<<0)
#define	LPUART1_TDR_TDR_0					(0x1u<<0)

// PRESC Configuration

#define	LPUART1_PRESC_PRESCALER				(0xFu<<0)
#define	LPUART1_PRESC_PRESCALER_0			(0x1u<<0)
#define	LPUART1_PRESC_PRESCALER_B_0X0		(0x0u<<0)
#define	LPUART1_PRESC_PRESCALER_B_0X1		(0x1u<<0)
#define	LPUART1_PRESC_PRESCALER_B_0X2		(0x2u<<0)
#define	LPUART1_PRESC_PRESCALER_B_0X3		(0x3u<<0)
#define	LPUART1_PRESC_PRESCALER_B_0X4		(0x4u<<0)
#define	LPUART1_PRESC_PRESCALER_B_0X5		(0x5u<<0)
#define	LPUART1_PRESC_PRESCALER_B_0X6		(0x6u<<0)
#define	LPUART1_PRESC_PRESCALER_B_0X7		(0x7u<<0)
#define	LPUART1_PRESC_PRESCALER_B_0X8		(0x8u<<0)
#define	LPUART1_PRESC_PRESCALER_B_0X9		(0x9u<<0)
#define	LPUART1_PRESC_PRESCALER_B_0XA		(0xAu<<0)
#define	LPUART1_PRESC_PRESCALER_B_0XB		(0xBu<<0)
