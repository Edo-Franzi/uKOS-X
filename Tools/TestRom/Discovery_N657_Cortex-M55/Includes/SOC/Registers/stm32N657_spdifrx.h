/*
; stm32N657_spdifrx.
; ==================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_spdifrx equates.
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

// SPDIFRX address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	IMR;
	volatile	uint32_t	SR;
	volatile	uint32_t	IFCR;
		union {
	volatile	uint32_t	FMT0_DR;
	volatile	uint32_t	FMT1_DR;
	volatile	uint32_t	FMT2_DR;
		};
	volatile	uint32_t	CSR;
	volatile	uint32_t	DIR;
} SPDIFRX_TypeDef;

#if (defined(__cplusplus))
#define	SPDIFRX_NS	reinterpret_cast<SPDIFRX_TypeDef *>(0x40004000u)
#define	SPDIFRX_S	reinterpret_cast<SPDIFRX_TypeDef *>(0x50004000u)

#else
#define	SPDIFRX_NS	((SPDIFRX_TypeDef *)0x40004000u)
#define	SPDIFRX_S	((SPDIFRX_TypeDef *)0x50004000u)
#endif

// CR Configuration

#define	SPDIFRX_CR_CKSBKPEN				(0x1u<<21)
#define	SPDIFRX_CR_CKSEN				(0x1u<<20)
#define	SPDIFRX_CR_INSEL				(0x7u<<16)
#define	SPDIFRX_CR_INSEL_0				(0x1u<<16)
#define	SPDIFRX_CR_WFA					(0x1u<<14)
#define	SPDIFRX_CR_NBTR					(0x3u<<12)
#define	SPDIFRX_CR_NBTR_0				(0x1u<<12)
#define	SPDIFRX_CR_CHSEL				(0x1u<<11)
#define	SPDIFRX_CR_CBDMAEN				(0x1u<<10)
#define	SPDIFRX_CR_PTMSK				(0x1u<<9)
#define	SPDIFRX_CR_CUMSK				(0x1u<<8)
#define	SPDIFRX_CR_VMSK					(0x1u<<7)
#define	SPDIFRX_CR_PMSK					(0x1u<<6)
#define	SPDIFRX_CR_DRFMT				(0x3u<<4)
#define	SPDIFRX_CR_DRFMT_0				(0x1u<<4)
#define	SPDIFRX_CR_RXSTEO				(0x1u<<3)
#define	SPDIFRX_CR_RXDMAEN				(0x1u<<2)
#define	SPDIFRX_CR_SPDIFRXEN			(0x3u<<0)
#define	SPDIFRX_CR_SPDIFRXEN_0			(0x1u<<0)

#define	SPDIFRX_CR_CKSBKPEN_B_0X1		(0x1u<<21)
#define	SPDIFRX_CR_CKSBKPEN_B_0X0		(0x0u<<21)
#define	SPDIFRX_CR_CKSEN_B_0X1			(0x1u<<20)
#define	SPDIFRX_CR_CKSEN_B_0X0			(0x0u<<20)
#define	SPDIFRX_CR_INSEL_B_0X0			(0x0u<<16)
#define	SPDIFRX_CR_INSEL_B_0X1			(0x1u<<16)
#define	SPDIFRX_CR_INSEL_B_0X2			(0x2u<<16)
#define	SPDIFRX_CR_INSEL_B_0X3			(0x3u<<16)
#define	SPDIFRX_CR_WFA_B_0X1			(0x1u<<14)
#define	SPDIFRX_CR_WFA_B_0X0			(0x0u<<14)
#define	SPDIFRX_CR_NBTR_B_0X0			(0x0u<<12)
#define	SPDIFRX_CR_NBTR_B_0X1			(0x1u<<12)
#define	SPDIFRX_CR_NBTR_B_0X2			(0x2u<<12)
#define	SPDIFRX_CR_NBTR_B_0X3			(0x3u<<12)
#define	SPDIFRX_CR_CHSEL_B_0X1			(0x1u<<11)
#define	SPDIFRX_CR_CHSEL_B_0X0			(0x0u<<11)
#define	SPDIFRX_CR_CBDMAEN_B_0X1		(0x1u<<10)
#define	SPDIFRX_CR_CBDMAEN_B_0X0		(0x0u<<10)
#define	SPDIFRX_CR_PTMSK_B_0X1			(0x1u<<9)
#define	SPDIFRX_CR_PTMSK_B_0X0			(0x0u<<9)
#define	SPDIFRX_CR_CUMSK_B_0X1			(0x1u<<8)
#define	SPDIFRX_CR_CUMSK_B_0X0			(0x0u<<8)
#define	SPDIFRX_CR_VMSK_B_0X1			(0x1u<<7)
#define	SPDIFRX_CR_VMSK_B_0X0			(0x0u<<7)
#define	SPDIFRX_CR_PMSK_B_0X1			(0x1u<<6)
#define	SPDIFRX_CR_PMSK_B_0X0			(0x0u<<6)
#define	SPDIFRX_CR_DRFMT_B_0X2			(0x2u<<4)
#define	SPDIFRX_CR_DRFMT_B_0X1			(0x1u<<4)
#define	SPDIFRX_CR_DRFMT_B_0X0			(0x0u<<4)
#define	SPDIFRX_CR_RXSTEO_B_0X1			(0x1u<<3)
#define	SPDIFRX_CR_RXSTEO_B_0X0			(0x0u<<3)
#define	SPDIFRX_CR_RXDMAEN_B_0X1		(0x1u<<2)
#define	SPDIFRX_CR_RXDMAEN_B_0X0		(0x0u<<2)
#define	SPDIFRX_CR_SPDIFRXEN_B_0X0		(0x0u<<0)
#define	SPDIFRX_CR_SPDIFRXEN_B_0X1		(0x1u<<0)
#define	SPDIFRX_CR_SPDIFRXEN_B_0X3		(0x3u<<0)

// IMR Configuration

#define	SPDIFRX_IMR_IFEIE				(0x1u<<6)
#define	SPDIFRX_IMR_SYNCDIE				(0x1u<<5)
#define	SPDIFRX_IMR_SBLKIE				(0x1u<<4)
#define	SPDIFRX_IMR_OVRIE				(0x1u<<3)
#define	SPDIFRX_IMR_PERRIE				(0x1u<<2)
#define	SPDIFRX_IMR_CSRNEIE				(0x1u<<1)
#define	SPDIFRX_IMR_RXNEIE				(0x1u<<0)

#define	SPDIFRX_IMR_IFEIE_B_0X0			(0x0u<<6)
#define	SPDIFRX_IMR_IFEIE_B_0X1			(0x1u<<6)
#define	SPDIFRX_IMR_SYNCDIE_B_0X0		(0x0u<<5)
#define	SPDIFRX_IMR_SYNCDIE_B_0X1		(0x1u<<5)
#define	SPDIFRX_IMR_SBLKIE_B_0X0		(0x0u<<4)
#define	SPDIFRX_IMR_SBLKIE_B_0X1		(0x1u<<4)
#define	SPDIFRX_IMR_OVRIE_B_0X0			(0x0u<<3)
#define	SPDIFRX_IMR_OVRIE_B_0X1			(0x1u<<3)
#define	SPDIFRX_IMR_PERRIE_B_0X0		(0x0u<<2)
#define	SPDIFRX_IMR_PERRIE_B_0X1		(0x1u<<2)
#define	SPDIFRX_IMR_CSRNEIE_B_0X0		(0x0u<<1)
#define	SPDIFRX_IMR_CSRNEIE_B_0X1		(0x1u<<1)
#define	SPDIFRX_IMR_RXNEIE_B_0X0		(0x0u<<0)
#define	SPDIFRX_IMR_RXNEIE_B_0X1		(0x1u<<0)

// SR Configuration

#define	SPDIFRX_SR_WIDTH5				(0x7FFFu<<16)
#define	SPDIFRX_SR_WIDTH5_0				(0x1u<<16)
#define	SPDIFRX_SR_TERR					(0x1u<<8)
#define	SPDIFRX_SR_SERR					(0x1u<<7)
#define	SPDIFRX_SR_FERR					(0x1u<<6)
#define	SPDIFRX_SR_SYNCD				(0x1u<<5)
#define	SPDIFRX_SR_SBD					(0x1u<<4)
#define	SPDIFRX_SR_OVR					(0x1u<<3)
#define	SPDIFRX_SR_PERR					(0x1u<<2)
#define	SPDIFRX_SR_CSRNE				(0x1u<<1)
#define	SPDIFRX_SR_RXNE					(0x1u<<0)

#define	SPDIFRX_SR_TERR_B_0X0			(0x0u<<8)
#define	SPDIFRX_SR_TERR_B_0X1			(0x1u<<8)
#define	SPDIFRX_SR_SERR_B_0X0			(0x0u<<7)
#define	SPDIFRX_SR_SERR_B_0X1			(0x1u<<7)
#define	SPDIFRX_SR_FERR_B_0X0			(0x0u<<6)
#define	SPDIFRX_SR_FERR_B_0X1			(0x1u<<6)
#define	SPDIFRX_SR_SYNCD_B_0X0			(0x0u<<5)
#define	SPDIFRX_SR_SYNCD_B_0X1			(0x1u<<5)
#define	SPDIFRX_SR_SBD_B_0X0			(0x0u<<4)
#define	SPDIFRX_SR_SBD_B_0X1			(0x1u<<4)
#define	SPDIFRX_SR_OVR_B_0X0			(0x0u<<3)
#define	SPDIFRX_SR_OVR_B_0X1			(0x1u<<3)
#define	SPDIFRX_SR_PERR_B_0X0			(0x0u<<2)
#define	SPDIFRX_SR_PERR_B_0X1			(0x1u<<2)
#define	SPDIFRX_SR_CSRNE_B_0X0			(0x0u<<1)
#define	SPDIFRX_SR_CSRNE_B_0X1			(0x1u<<1)
#define	SPDIFRX_SR_RXNE_B_0X0			(0x0u<<0)
#define	SPDIFRX_SR_RXNE_B_0X1			(0x1u<<0)

// IFCR Configuration

#define	SPDIFRX_IFCR_SYNCDCF			(0x1u<<5)
#define	SPDIFRX_IFCR_SBDCF				(0x1u<<4)
#define	SPDIFRX_IFCR_OVRCF				(0x1u<<3)
#define	SPDIFRX_IFCR_PERRCF				(0x1u<<2)

// FMT0_DR Configuration

#define	SPDIFRX_FMT0_DR_PT				(0x3u<<28)
#define	SPDIFRX_FMT0_DR_PT_0			(0x1u<<28)
#define	SPDIFRX_FMT0_DR_C				(0x1u<<27)
#define	SPDIFRX_FMT0_DR_U				(0x1u<<26)
#define	SPDIFRX_FMT0_DR_V				(0x1u<<25)
#define	SPDIFRX_FMT0_DR_PE				(0x1u<<24)
#define	SPDIFRX_FMT0_DR_DR				(0xFFFFFFu<<0)
#define	SPDIFRX_FMT0_DR_DR_0			(0x1u<<0)

#define	SPDIFRX_FMT0_DR_PT_B_0X0		(0x0u<<28)
#define	SPDIFRX_FMT0_DR_PT_B_0X1		(0x1u<<28)
#define	SPDIFRX_FMT0_DR_PT_B_0X2		(0x2u<<28)
#define	SPDIFRX_FMT0_DR_PT_B_0X3		(0x3u<<28)

// FMT1_DR Configuration

#define	SPDIFRX_FMT1_DR_DR				(0xFFFFFFu<<8)
#define	SPDIFRX_FMT1_DR_DR_0			(0x1u<<8)
#define	SPDIFRX_FMT1_DR_PT				(0x3u<<4)
#define	SPDIFRX_FMT1_DR_PT_0			(0x1u<<4)
#define	SPDIFRX_FMT1_DR_C				(0x1u<<3)
#define	SPDIFRX_FMT1_DR_U				(0x1u<<2)
#define	SPDIFRX_FMT1_DR_V				(0x1u<<1)
#define	SPDIFRX_FMT1_DR_PE				(0x1u<<0)

#define	SPDIFRX_FMT1_DR_PT_B_0X0		(0x0u<<4)
#define	SPDIFRX_FMT1_DR_PT_B_0X1		(0x1u<<4)
#define	SPDIFRX_FMT1_DR_PT_B_0X2		(0x2u<<4)
#define	SPDIFRX_FMT1_DR_PT_B_0X3		(0x3u<<4)

// FMT2_DR Configuration

#define	SPDIFRX_FMT2_DR_DRNL2			(0xFFFFu<<16)
#define	SPDIFRX_FMT2_DR_DRNL2_0			(0x1u<<16)
#define	SPDIFRX_FMT2_DR_DRNL1			(0xFFFFu<<0)
#define	SPDIFRX_FMT2_DR_DRNL1_0			(0x1u<<0)

// CSR Configuration

#define	SPDIFRX_CSR_SOB					(0x1u<<24)
#define	SPDIFRX_CSR_CS					(0xFFu<<16)
#define	SPDIFRX_CSR_CS_0				(0x1u<<16)
#define	SPDIFRX_CSR_USR					(0xFFFFu<<0)
#define	SPDIFRX_CSR_USR_0				(0x1u<<0)

#define	SPDIFRX_CSR_SOB_B_0X0			(0x0u<<24)
#define	SPDIFRX_CSR_SOB_B_0X1			(0x1u<<24)

// DIR Configuration

#define	SPDIFRX_DIR_TLO					(0x1FFFu<<16)
#define	SPDIFRX_DIR_TLO_0				(0x1u<<16)
#define	SPDIFRX_DIR_THI					(0x1FFFu<<0)
#define	SPDIFRX_DIR_THI_0				(0x1u<<0)
