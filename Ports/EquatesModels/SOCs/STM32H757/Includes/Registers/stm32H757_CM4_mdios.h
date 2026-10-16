/*
; stm32H757_CM4_mdios.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H757_CM4_mdios equates.
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
#define	MDIOS	reinterpret_cast<MDIOS_TypeDef *>(0x40009400u)

#else
#define	MDIOS	((MDIOS_TypeDef *)0x40009400u)
#endif

// CR Configuration

#define	MDIOS_CR_PORT_ADDRESS	(0x1Fu<<8)
#define	MDIOS_CR_PORT_ADDRESS_0	(0x1u<<8)
#define	MDIOS_CR_DPC			(0x1u<<7)
#define	MDIOS_CR_EIE			(0x1u<<3)
#define	MDIOS_CR_RDIE			(0x1u<<2)
#define	MDIOS_CR_WRIE			(0x1u<<1)
#define	MDIOS_CR_EN				(0x1u<<0)

// WRFR Configuration

#define	MDIOS_WRFR_WRF			(0xFFFFFFFFu<<0)
#define	MDIOS_WRFR_WRF_0		(0x1u<<0)

// CWRFR Configuration

#define	MDIOS_CWRFR_CWRF		(0xFFFFFFFFu<<0)
#define	MDIOS_CWRFR_CWRF_0		(0x1u<<0)

// RDFR Configuration

#define	MDIOS_RDFR_RDF			(0xFFFFFFFFu<<0)
#define	MDIOS_RDFR_RDF_0		(0x1u<<0)

// CRDFR Configuration

#define	MDIOS_CRDFR_CRDF		(0xFFFFFFFFu<<0)
#define	MDIOS_CRDFR_CRDF_0		(0x1u<<0)

// SR Configuration

#define	MDIOS_SR_TERF			(0x1u<<2)
#define	MDIOS_SR_SERF			(0x1u<<1)
#define	MDIOS_SR_PERF			(0x1u<<0)

// CLRFR Configuration

#define	MDIOS_CLRFR_CTERF		(0x1u<<2)
#define	MDIOS_CLRFR_CSERF		(0x1u<<1)
#define	MDIOS_CLRFR_CPERF		(0x1u<<0)

// DINR0 Configuration

#define	MDIOS_DINR0_DIN0		(0xFFFFu<<0)
#define	MDIOS_DINR0_DIN0_0		(0x1u<<0)

// DINR1 Configuration

#define	MDIOS_DINR1_DIN1		(0xFFFFu<<0)
#define	MDIOS_DINR1_DIN1_0		(0x1u<<0)

// DINR2 Configuration

#define	MDIOS_DINR2_DIN2		(0xFFFFu<<0)
#define	MDIOS_DINR2_DIN2_0		(0x1u<<0)

// DINR3 Configuration

#define	MDIOS_DINR3_DIN3		(0xFFFFu<<0)
#define	MDIOS_DINR3_DIN3_0		(0x1u<<0)

// DINR4 Configuration

#define	MDIOS_DINR4_DIN4		(0xFFFFu<<0)
#define	MDIOS_DINR4_DIN4_0		(0x1u<<0)

// DINR5 Configuration

#define	MDIOS_DINR5_DIN5		(0xFFFFu<<0)
#define	MDIOS_DINR5_DIN5_0		(0x1u<<0)

// DINR6 Configuration

#define	MDIOS_DINR6_DIN6		(0xFFFFu<<0)
#define	MDIOS_DINR6_DIN6_0		(0x1u<<0)

// DINR7 Configuration

#define	MDIOS_DINR7_DIN7		(0xFFFFu<<0)
#define	MDIOS_DINR7_DIN7_0		(0x1u<<0)

// DINR8 Configuration

#define	MDIOS_DINR8_DIN8		(0xFFFFu<<0)
#define	MDIOS_DINR8_DIN8_0		(0x1u<<0)

// DINR9 Configuration

#define	MDIOS_DINR9_DIN9		(0xFFFFu<<0)
#define	MDIOS_DINR9_DIN9_0		(0x1u<<0)

// DINR10 Configuration

#define	MDIOS_DINR10_DIN10		(0xFFFFu<<0)
#define	MDIOS_DINR10_DIN10_0	(0x1u<<0)

// DINR11 Configuration

#define	MDIOS_DINR11_DIN11		(0xFFFFu<<0)
#define	MDIOS_DINR11_DIN11_0	(0x1u<<0)

// DINR12 Configuration

#define	MDIOS_DINR12_DIN12		(0xFFFFu<<0)
#define	MDIOS_DINR12_DIN12_0	(0x1u<<0)

// DINR13 Configuration

#define	MDIOS_DINR13_DIN13		(0xFFFFu<<0)
#define	MDIOS_DINR13_DIN13_0	(0x1u<<0)

// DINR14 Configuration

#define	MDIOS_DINR14_DIN14		(0xFFFFu<<0)
#define	MDIOS_DINR14_DIN14_0	(0x1u<<0)

// DINR15 Configuration

#define	MDIOS_DINR15_DIN15		(0xFFFFu<<0)
#define	MDIOS_DINR15_DIN15_0	(0x1u<<0)

// DINR16 Configuration

#define	MDIOS_DINR16_DIN16		(0xFFFFu<<0)
#define	MDIOS_DINR16_DIN16_0	(0x1u<<0)

// DINR17 Configuration

#define	MDIOS_DINR17_DIN17		(0xFFFFu<<0)
#define	MDIOS_DINR17_DIN17_0	(0x1u<<0)

// DINR18 Configuration

#define	MDIOS_DINR18_DIN18		(0xFFFFu<<0)
#define	MDIOS_DINR18_DIN18_0	(0x1u<<0)

// DINR19 Configuration

#define	MDIOS_DINR19_DIN19		(0xFFFFu<<0)
#define	MDIOS_DINR19_DIN19_0	(0x1u<<0)

// DINR20 Configuration

#define	MDIOS_DINR20_DIN20		(0xFFFFu<<0)
#define	MDIOS_DINR20_DIN20_0	(0x1u<<0)

// DINR21 Configuration

#define	MDIOS_DINR21_DIN21		(0xFFFFu<<0)
#define	MDIOS_DINR21_DIN21_0	(0x1u<<0)

// DINR22 Configuration

#define	MDIOS_DINR22_DIN22		(0xFFFFu<<0)
#define	MDIOS_DINR22_DIN22_0	(0x1u<<0)

// DINR23 Configuration

#define	MDIOS_DINR23_DIN23		(0xFFFFu<<0)
#define	MDIOS_DINR23_DIN23_0	(0x1u<<0)

// DINR24 Configuration

#define	MDIOS_DINR24_DIN24		(0xFFFFu<<0)
#define	MDIOS_DINR24_DIN24_0	(0x1u<<0)

// DINR25 Configuration

#define	MDIOS_DINR25_DIN25		(0xFFFFu<<0)
#define	MDIOS_DINR25_DIN25_0	(0x1u<<0)

// DINR26 Configuration

#define	MDIOS_DINR26_DIN26		(0xFFFFu<<0)
#define	MDIOS_DINR26_DIN26_0	(0x1u<<0)

// DINR27 Configuration

#define	MDIOS_DINR27_DIN27		(0xFFFFu<<0)
#define	MDIOS_DINR27_DIN27_0	(0x1u<<0)

// DINR28 Configuration

#define	MDIOS_DINR28_DIN28		(0xFFFFu<<0)
#define	MDIOS_DINR28_DIN28_0	(0x1u<<0)

// DINR29 Configuration

#define	MDIOS_DINR29_DIN29		(0xFFFFu<<0)
#define	MDIOS_DINR29_DIN29_0	(0x1u<<0)

// DINR30 Configuration

#define	MDIOS_DINR30_DIN30		(0xFFFFu<<0)
#define	MDIOS_DINR30_DIN30_0	(0x1u<<0)

// DINR31 Configuration

#define	MDIOS_DINR31_DIN31		(0xFFFFu<<0)
#define	MDIOS_DINR31_DIN31_0	(0x1u<<0)

// DOUTR0 Configuration

#define	MDIOS_DOUTR0_DOUT0		(0xFFFFu<<0)
#define	MDIOS_DOUTR0_DOUT0_0	(0x1u<<0)

// DOUTR1 Configuration

#define	MDIOS_DOUTR1_DOUT1		(0xFFFFu<<0)
#define	MDIOS_DOUTR1_DOUT1_0	(0x1u<<0)

// DOUTR2 Configuration

#define	MDIOS_DOUTR2_DOUT2		(0xFFFFu<<0)
#define	MDIOS_DOUTR2_DOUT2_0	(0x1u<<0)

// DOUTR3 Configuration

#define	MDIOS_DOUTR3_DOUT3		(0xFFFFu<<0)
#define	MDIOS_DOUTR3_DOUT3_0	(0x1u<<0)

// DOUTR4 Configuration

#define	MDIOS_DOUTR4_DOUT4		(0xFFFFu<<0)
#define	MDIOS_DOUTR4_DOUT4_0	(0x1u<<0)

// DOUTR5 Configuration

#define	MDIOS_DOUTR5_DOUT5		(0xFFFFu<<0)
#define	MDIOS_DOUTR5_DOUT5_0	(0x1u<<0)

// DOUTR6 Configuration

#define	MDIOS_DOUTR6_DOUT6		(0xFFFFu<<0)
#define	MDIOS_DOUTR6_DOUT6_0	(0x1u<<0)

// DOUTR7 Configuration

#define	MDIOS_DOUTR7_DOUT7		(0xFFFFu<<0)
#define	MDIOS_DOUTR7_DOUT7_0	(0x1u<<0)

// DOUTR8 Configuration

#define	MDIOS_DOUTR8_DOUT8		(0xFFFFu<<0)
#define	MDIOS_DOUTR8_DOUT8_0	(0x1u<<0)

// DOUTR9 Configuration

#define	MDIOS_DOUTR9_DOUT9		(0xFFFFu<<0)
#define	MDIOS_DOUTR9_DOUT9_0	(0x1u<<0)

// DOUTR10 Configuration

#define	MDIOS_DOUTR10_DOUT10	(0xFFFFu<<0)
#define	MDIOS_DOUTR10_DOUT10_0	(0x1u<<0)

// DOUTR11 Configuration

#define	MDIOS_DOUTR11_DOUT11	(0xFFFFu<<0)
#define	MDIOS_DOUTR11_DOUT11_0	(0x1u<<0)

// DOUTR12 Configuration

#define	MDIOS_DOUTR12_DOUT12	(0xFFFFu<<0)
#define	MDIOS_DOUTR12_DOUT12_0	(0x1u<<0)

// DOUTR13 Configuration

#define	MDIOS_DOUTR13_DOUT13	(0xFFFFu<<0)
#define	MDIOS_DOUTR13_DOUT13_0	(0x1u<<0)

// DOUTR14 Configuration

#define	MDIOS_DOUTR14_DOUT14	(0xFFFFu<<0)
#define	MDIOS_DOUTR14_DOUT14_0	(0x1u<<0)

// DOUTR15 Configuration

#define	MDIOS_DOUTR15_DOUT15	(0xFFFFu<<0)
#define	MDIOS_DOUTR15_DOUT15_0	(0x1u<<0)

// DOUTR16 Configuration

#define	MDIOS_DOUTR16_DOUT16	(0xFFFFu<<0)
#define	MDIOS_DOUTR16_DOUT16_0	(0x1u<<0)

// DOUTR17 Configuration

#define	MDIOS_DOUTR17_DOUT17	(0xFFFFu<<0)
#define	MDIOS_DOUTR17_DOUT17_0	(0x1u<<0)

// DOUTR18 Configuration

#define	MDIOS_DOUTR18_DOUT18	(0xFFFFu<<0)
#define	MDIOS_DOUTR18_DOUT18_0	(0x1u<<0)

// DOUTR19 Configuration

#define	MDIOS_DOUTR19_DOUT19	(0xFFFFu<<0)
#define	MDIOS_DOUTR19_DOUT19_0	(0x1u<<0)

// DOUTR20 Configuration

#define	MDIOS_DOUTR20_DOUT20	(0xFFFFu<<0)
#define	MDIOS_DOUTR20_DOUT20_0	(0x1u<<0)

// DOUTR21 Configuration

#define	MDIOS_DOUTR21_DOUT21	(0xFFFFu<<0)
#define	MDIOS_DOUTR21_DOUT21_0	(0x1u<<0)

// DOUTR22 Configuration

#define	MDIOS_DOUTR22_DOUT22	(0xFFFFu<<0)
#define	MDIOS_DOUTR22_DOUT22_0	(0x1u<<0)

// DOUTR23 Configuration

#define	MDIOS_DOUTR23_DOUT23	(0xFFFFu<<0)
#define	MDIOS_DOUTR23_DOUT23_0	(0x1u<<0)

// DOUTR24 Configuration

#define	MDIOS_DOUTR24_DOUT24	(0xFFFFu<<0)
#define	MDIOS_DOUTR24_DOUT24_0	(0x1u<<0)

// DOUTR25 Configuration

#define	MDIOS_DOUTR25_DOUT25	(0xFFFFu<<0)
#define	MDIOS_DOUTR25_DOUT25_0	(0x1u<<0)

// DOUTR26 Configuration

#define	MDIOS_DOUTR26_DOUT26	(0xFFFFu<<0)
#define	MDIOS_DOUTR26_DOUT26_0	(0x1u<<0)

// DOUTR27 Configuration

#define	MDIOS_DOUTR27_DOUT27	(0xFFFFu<<0)
#define	MDIOS_DOUTR27_DOUT27_0	(0x1u<<0)

// DOUTR28 Configuration

#define	MDIOS_DOUTR28_DOUT28	(0xFFFFu<<0)
#define	MDIOS_DOUTR28_DOUT28_0	(0x1u<<0)

// DOUTR29 Configuration

#define	MDIOS_DOUTR29_DOUT29	(0xFFFFu<<0)
#define	MDIOS_DOUTR29_DOUT29_0	(0x1u<<0)

// DOUTR30 Configuration

#define	MDIOS_DOUTR30_DOUT30	(0xFFFFu<<0)
#define	MDIOS_DOUTR30_DOUT30_0	(0x1u<<0)

// DOUTR31 Configuration

#define	MDIOS_DOUTR31_DOUT31	(0xFFFFu<<0)
#define	MDIOS_DOUTR31_DOUT31_0	(0x1u<<0)
