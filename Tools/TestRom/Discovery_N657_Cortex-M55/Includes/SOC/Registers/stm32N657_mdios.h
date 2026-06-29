/*
; stm32N657_mdios.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_mdios equates.
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

// MDIOS address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	WRFR;
	volatile	uint32_t	CWRFR;
	volatile	uint32_t	RDFR;
	volatile	uint32_t	CRDFR;
	volatile	uint32_t	SR;
	volatile	uint32_t	CLRFR;
	volatile	uint32_t	RESERVED0[57];
	volatile	uint32_t	DINR0;
	volatile	uint32_t	DINR1;
	volatile	uint32_t	DINR2;
	volatile	uint32_t	DINR3;
	volatile	uint32_t	DINR4;
	volatile	uint32_t	DINR5;
	volatile	uint32_t	DINR6;
	volatile	uint32_t	DINR7;
	volatile	uint32_t	DINR8;
	volatile	uint32_t	DINR9;
	volatile	uint32_t	DINR10;
	volatile	uint32_t	DINR11;
	volatile	uint32_t	DINR12;
	volatile	uint32_t	DINR13;
	volatile	uint32_t	DINR14;
	volatile	uint32_t	DINR15;
	volatile	uint32_t	DINR16;
	volatile	uint32_t	DINR17;
	volatile	uint32_t	DINR18;
	volatile	uint32_t	DINR19;
	volatile	uint32_t	DINR20;
	volatile	uint32_t	DINR21;
	volatile	uint32_t	DINR22;
	volatile	uint32_t	DINR23;
	volatile	uint32_t	DINR24;
	volatile	uint32_t	DINR25;
	volatile	uint32_t	DINR26;
	volatile	uint32_t	DINR27;
	volatile	uint32_t	DINR28;
	volatile	uint32_t	DINR29;
	volatile	uint32_t	DINR30;
	volatile	uint32_t	DINR31;
	volatile	uint32_t	DOUTR0;
	volatile	uint32_t	DOUTR1;
	volatile	uint32_t	DOUTR2;
	volatile	uint32_t	DOUTR3;
	volatile	uint32_t	DOUTR4;
	volatile	uint32_t	DOUTR5;
	volatile	uint32_t	DOUTR6;
	volatile	uint32_t	DOUTR7;
	volatile	uint32_t	DOUTR8;
	volatile	uint32_t	DOUTR9;
	volatile	uint32_t	DOUTR10;
	volatile	uint32_t	DOUTR11;
	volatile	uint32_t	DOUTR12;
	volatile	uint32_t	DOUTR13;
	volatile	uint32_t	DOUTR14;
	volatile	uint32_t	DOUTR15;
	volatile	uint32_t	DOUTR16;
	volatile	uint32_t	DOUTR17;
	volatile	uint32_t	DOUTR18;
	volatile	uint32_t	DOUTR19;
	volatile	uint32_t	DOUTR20;
	volatile	uint32_t	DOUTR21;
	volatile	uint32_t	DOUTR22;
	volatile	uint32_t	DOUTR23;
	volatile	uint32_t	DOUTR24;
	volatile	uint32_t	DOUTR25;
	volatile	uint32_t	DOUTR26;
	volatile	uint32_t	DOUTR27;
	volatile	uint32_t	DOUTR28;
	volatile	uint32_t	DOUTR29;
	volatile	uint32_t	DOUTR30;
	volatile	uint32_t	DOUTR31;
} MDIOS_TypeDef;

#if (defined(__cplusplus))
#define	MDIOS_NS	reinterpret_cast<MDIOS_TypeDef *>(0x40009400u)
#define	MDIOS_S		reinterpret_cast<MDIOS_TypeDef *>(0x50009400u)

#else
#define	MDIOS_NS	((MDIOS_TypeDef *)0x40009400u)
#define	MDIOS_S		((MDIOS_TypeDef *)0x50009400u)
#endif

// CR Configuration

#define	MDIOS_CR_PORT_ADDRESS	(0x1Fu<<8)
#define	MDIOS_CR_PORT_ADDRESS_0	(0x1u<<8)
#define	MDIOS_CR_DPC			(0x1u<<7)
#define	MDIOS_CR_EIE			(0x1u<<3)
#define	MDIOS_CR_RDIE			(0x1u<<2)
#define	MDIOS_CR_WRIE			(0x1u<<1)
#define	MDIOS_CR_EN				(0x1u<<0)

#define	MDIOS_CR_DPC_B_0X0		(0x0u<<7)
#define	MDIOS_CR_DPC_B_0X1		(0x1u<<7)
#define	MDIOS_CR_EIE_B_0X0		(0x0u<<3)
#define	MDIOS_CR_EIE_B_0X1		(0x1u<<3)
#define	MDIOS_CR_RDIE_B_0X0		(0x0u<<2)
#define	MDIOS_CR_RDIE_B_0X1		(0x1u<<2)
#define	MDIOS_CR_WRIE_B_0X0		(0x0u<<1)
#define	MDIOS_CR_WRIE_B_0X1		(0x1u<<1)
#define	MDIOS_CR_EN_B_0X0		(0x0u<<0)
#define	MDIOS_CR_EN_B_0X1		(0x1u<<0)

// WRFR Configuration

#define	MDIOS_WRFR_WRF			(0xFFFFFFFFu<<0)
#define	MDIOS_WRFR_WRF_0		(0x1u<<0)

#define	MDIOS_WRFR_WRF_B_0X0	(0x0u<<0)
#define	MDIOS_WRFR_WRF_B_0X1	(0x1u<<0)

// CWRFR Configuration

#define	MDIOS_CWRFR_CWRF		(0xFFFFFFFFu<<0)
#define	MDIOS_CWRFR_CWRF_0		(0x1u<<0)

// RDFR Configuration

#define	MDIOS_RDFR_RDF			(0xFFFFFFFFu<<0)
#define	MDIOS_RDFR_RDF_0		(0x1u<<0)

#define	MDIOS_RDFR_RDF_B_0X0	(0x0u<<0)
#define	MDIOS_RDFR_RDF_B_0X1	(0x1u<<0)

// CRDFR Configuration

#define	MDIOS_CRDFR_CRDF		(0xFFFFFFFFu<<0)
#define	MDIOS_CRDFR_CRDF_0		(0x1u<<0)

// SR Configuration

#define	MDIOS_SR_TERF			(0x1u<<2)
#define	MDIOS_SR_SERF			(0x1u<<1)
#define	MDIOS_SR_PERF			(0x1u<<0)

#define	MDIOS_SR_TERF_B_0X0		(0x0u<<2)
#define	MDIOS_SR_TERF_B_0X1		(0x1u<<2)
#define	MDIOS_SR_SERF_B_0X0		(0x0u<<1)
#define	MDIOS_SR_SERF_B_0X1		(0x1u<<1)
#define	MDIOS_SR_PERF_B_0X0		(0x0u<<0)
#define	MDIOS_SR_PERF_B_0X1		(0x1u<<0)

// CLRFR Configuration

#define	MDIOS_CLRFR_CTERF		(0x1u<<2)
#define	MDIOS_CLRFR_CSERF		(0x1u<<1)
#define	MDIOS_CLRFR_CPERF		(0x1u<<0)

// DINR0 Configuration

#define	MDIOS_DINR0_DIN			(0xFFFFu<<0)
#define	MDIOS_DINR0_DIN_0		(0x1u<<0)

// DINR1 Configuration

#define	MDIOS_DINR1_DIN			(0xFFFFu<<0)
#define	MDIOS_DINR1_DIN_0		(0x1u<<0)

// DINR2 Configuration

#define	MDIOS_DINR2_DIN			(0xFFFFu<<0)
#define	MDIOS_DINR2_DIN_0		(0x1u<<0)

// DINR3 Configuration

#define	MDIOS_DINR3_DIN			(0xFFFFu<<0)
#define	MDIOS_DINR3_DIN_0		(0x1u<<0)

// DINR4 Configuration

#define	MDIOS_DINR4_DIN			(0xFFFFu<<0)
#define	MDIOS_DINR4_DIN_0		(0x1u<<0)

// DINR5 Configuration

#define	MDIOS_DINR5_DIN			(0xFFFFu<<0)
#define	MDIOS_DINR5_DIN_0		(0x1u<<0)

// DINR6 Configuration

#define	MDIOS_DINR6_DIN			(0xFFFFu<<0)
#define	MDIOS_DINR6_DIN_0		(0x1u<<0)

// DINR7 Configuration

#define	MDIOS_DINR7_DIN			(0xFFFFu<<0)
#define	MDIOS_DINR7_DIN_0		(0x1u<<0)

// DINR8 Configuration

#define	MDIOS_DINR8_DIN			(0xFFFFu<<0)
#define	MDIOS_DINR8_DIN_0		(0x1u<<0)

// DINR9 Configuration

#define	MDIOS_DINR9_DIN			(0xFFFFu<<0)
#define	MDIOS_DINR9_DIN_0		(0x1u<<0)

// DINR10 Configuration

#define	MDIOS_DINR10_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR10_DIN_0		(0x1u<<0)

// DINR11 Configuration

#define	MDIOS_DINR11_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR11_DIN_0		(0x1u<<0)

// DINR12 Configuration

#define	MDIOS_DINR12_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR12_DIN_0		(0x1u<<0)

// DINR13 Configuration

#define	MDIOS_DINR13_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR13_DIN_0		(0x1u<<0)

// DINR14 Configuration

#define	MDIOS_DINR14_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR14_DIN_0		(0x1u<<0)

// DINR15 Configuration

#define	MDIOS_DINR15_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR15_DIN_0		(0x1u<<0)

// DINR16 Configuration

#define	MDIOS_DINR16_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR16_DIN_0		(0x1u<<0)

// DINR17 Configuration

#define	MDIOS_DINR17_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR17_DIN_0		(0x1u<<0)

// DINR18 Configuration

#define	MDIOS_DINR18_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR18_DIN_0		(0x1u<<0)

// DINR19 Configuration

#define	MDIOS_DINR19_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR19_DIN_0		(0x1u<<0)

// DINR20 Configuration

#define	MDIOS_DINR20_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR20_DIN_0		(0x1u<<0)

// DINR21 Configuration

#define	MDIOS_DINR21_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR21_DIN_0		(0x1u<<0)

// DINR22 Configuration

#define	MDIOS_DINR22_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR22_DIN_0		(0x1u<<0)

// DINR23 Configuration

#define	MDIOS_DINR23_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR23_DIN_0		(0x1u<<0)

// DINR24 Configuration

#define	MDIOS_DINR24_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR24_DIN_0		(0x1u<<0)

// DINR25 Configuration

#define	MDIOS_DINR25_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR25_DIN_0		(0x1u<<0)

// DINR26 Configuration

#define	MDIOS_DINR26_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR26_DIN_0		(0x1u<<0)

// DINR27 Configuration

#define	MDIOS_DINR27_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR27_DIN_0		(0x1u<<0)

// DINR28 Configuration

#define	MDIOS_DINR28_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR28_DIN_0		(0x1u<<0)

// DINR29 Configuration

#define	MDIOS_DINR29_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR29_DIN_0		(0x1u<<0)

// DINR30 Configuration

#define	MDIOS_DINR30_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR30_DIN_0		(0x1u<<0)

// DINR31 Configuration

#define	MDIOS_DINR31_DIN		(0xFFFFu<<0)
#define	MDIOS_DINR31_DIN_0		(0x1u<<0)

// DOUTR0 Configuration

#define	MDIOS_DOUTR0_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR0_DOUT_0		(0x1u<<0)

// DOUTR1 Configuration

#define	MDIOS_DOUTR1_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR1_DOUT_0		(0x1u<<0)

// DOUTR2 Configuration

#define	MDIOS_DOUTR2_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR2_DOUT_0		(0x1u<<0)

// DOUTR3 Configuration

#define	MDIOS_DOUTR3_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR3_DOUT_0		(0x1u<<0)

// DOUTR4 Configuration

#define	MDIOS_DOUTR4_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR4_DOUT_0		(0x1u<<0)

// DOUTR5 Configuration

#define	MDIOS_DOUTR5_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR5_DOUT_0		(0x1u<<0)

// DOUTR6 Configuration

#define	MDIOS_DOUTR6_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR6_DOUT_0		(0x1u<<0)

// DOUTR7 Configuration

#define	MDIOS_DOUTR7_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR7_DOUT_0		(0x1u<<0)

// DOUTR8 Configuration

#define	MDIOS_DOUTR8_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR8_DOUT_0		(0x1u<<0)

// DOUTR9 Configuration

#define	MDIOS_DOUTR9_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR9_DOUT_0		(0x1u<<0)

// DOUTR10 Configuration

#define	MDIOS_DOUTR10_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR10_DOUT_0	(0x1u<<0)

// DOUTR11 Configuration

#define	MDIOS_DOUTR11_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR11_DOUT_0	(0x1u<<0)

// DOUTR12 Configuration

#define	MDIOS_DOUTR12_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR12_DOUT_0	(0x1u<<0)

// DOUTR13 Configuration

#define	MDIOS_DOUTR13_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR13_DOUT_0	(0x1u<<0)

// DOUTR14 Configuration

#define	MDIOS_DOUTR14_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR14_DOUT_0	(0x1u<<0)

// DOUTR15 Configuration

#define	MDIOS_DOUTR15_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR15_DOUT_0	(0x1u<<0)

// DOUTR16 Configuration

#define	MDIOS_DOUTR16_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR16_DOUT_0	(0x1u<<0)

// DOUTR17 Configuration

#define	MDIOS_DOUTR17_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR17_DOUT_0	(0x1u<<0)

// DOUTR18 Configuration

#define	MDIOS_DOUTR18_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR18_DOUT_0	(0x1u<<0)

// DOUTR19 Configuration

#define	MDIOS_DOUTR19_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR19_DOUT_0	(0x1u<<0)

// DOUTR20 Configuration

#define	MDIOS_DOUTR20_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR20_DOUT_0	(0x1u<<0)

// DOUTR21 Configuration

#define	MDIOS_DOUTR21_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR21_DOUT_0	(0x1u<<0)

// DOUTR22 Configuration

#define	MDIOS_DOUTR22_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR22_DOUT_0	(0x1u<<0)

// DOUTR23 Configuration

#define	MDIOS_DOUTR23_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR23_DOUT_0	(0x1u<<0)

// DOUTR24 Configuration

#define	MDIOS_DOUTR24_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR24_DOUT_0	(0x1u<<0)

// DOUTR25 Configuration

#define	MDIOS_DOUTR25_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR25_DOUT_0	(0x1u<<0)

// DOUTR26 Configuration

#define	MDIOS_DOUTR26_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR26_DOUT_0	(0x1u<<0)

// DOUTR27 Configuration

#define	MDIOS_DOUTR27_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR27_DOUT_0	(0x1u<<0)

// DOUTR28 Configuration

#define	MDIOS_DOUTR28_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR28_DOUT_0	(0x1u<<0)

// DOUTR29 Configuration

#define	MDIOS_DOUTR29_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR29_DOUT_0	(0x1u<<0)

// DOUTR30 Configuration

#define	MDIOS_DOUTR30_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR30_DOUT_0	(0x1u<<0)

// DOUTR31 Configuration

#define	MDIOS_DOUTR31_DOUT		(0xFFFFu<<0)
#define	MDIOS_DOUTR31_DOUT_0	(0x1u<<0)
