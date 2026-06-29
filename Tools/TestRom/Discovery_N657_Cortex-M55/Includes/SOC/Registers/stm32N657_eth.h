/*
; stm32N657_eth.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_eth equates.
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

// ETH address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	MACCR;
	volatile	uint32_t	MACECR;
	volatile	uint32_t	MACPFR;
	volatile	uint32_t	MACWTR;
	volatile	uint32_t	MACHT0R;
	volatile	uint32_t	MACHT1R;
	volatile	uint32_t	RESERVED0[14];
	volatile	uint32_t	MACVTCR;
	volatile	uint32_t	MACVTDR;
	volatile	uint32_t	MACVHTR;
	volatile	uint32_t	RESERVED1;
		union {
	volatile	uint32_t	MACVIR;
	volatile	uint32_t	MACVIR_ALTERNATE;
		};
	volatile	uint32_t	MACIVIR;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	MACQ0TXFCR;
	volatile	uint32_t	RESERVED3[7];
	volatile	uint32_t	MACRXFCR;
	volatile	uint32_t	MACRXQCR;
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	MACRXQC0R;
	volatile	uint32_t	MACRXQC1R;
	volatile	uint32_t	MACRXQC2R;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	MACISR;
	volatile	uint32_t	MACIER;
	volatile	uint32_t	MACRXTXSR;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	MACPCSR;
	volatile	uint32_t	MACRWKPFR;
	volatile	uint32_t	RESERVED7[2];
	volatile	uint32_t	MACLCSR;
	volatile	uint32_t	MACLTCR;
	volatile	uint32_t	MACLETR;
	volatile	uint32_t	MAC1USTCR;
	volatile	uint32_t	RESERVED8[6];
	volatile	uint32_t	MACPHYCSR;
	volatile	uint32_t	RESERVED9[5];
	volatile	uint32_t	MACVR;
	volatile	uint32_t	MACDR;
	volatile	uint32_t	RESERVED10;
	volatile	uint32_t	MACHWF0R;
	volatile	uint32_t	MACHWF1R;
	volatile	uint32_t	MACHWF2R;
	volatile	uint32_t	MACHWF3R;
	volatile	uint32_t	RESERVED11[53];
	volatile	uint32_t	MACMDIOAR;
	volatile	uint32_t	MACMDIODR;
	volatile	uint32_t	RESERVED12[2];
	volatile	uint32_t	MACARPAR;
	volatile	uint32_t	RESERVED13[7];
	volatile	uint32_t	MACCSRSWCR;
	volatile	uint32_t	MACFPECSR;
	volatile	uint32_t	RESERVED14[2];
	volatile	uint32_t	MACPRSTIMR;
	volatile	uint32_t	MACPRSTIMUR;
	volatile	uint32_t	RESERVED15[46];
	volatile	uint32_t	MACA0HR;
	volatile	uint32_t	MACA0LR;
	volatile	uint32_t	MACA1HR;
	volatile	uint32_t	MACA1LR;
	volatile	uint32_t	MACA2HR;
	volatile	uint32_t	MACA2LR;
	volatile	uint32_t	MACA3HR;
	volatile	uint32_t	MACA3LR;
	volatile	uint32_t	RESERVED16[248];
	volatile	uint32_t	MMC_CONTROL;
	volatile	uint32_t	MMC_RX_INTERRUPT;
	volatile	uint32_t	MMC_TX_INTERRUPT;
	volatile	uint32_t	MMC_RX_INTERRUPT_MASK;
	volatile	uint32_t	MMC_TX_INTERRUPT_MASK;
	volatile	uint32_t	RESERVED17[14];
	volatile	uint32_t	TX_SINGLE_COLLISION_GOOD_PACKETS;
	volatile	uint32_t	TX_MULTIPLE_COLLISION_GOOD_PACKETS;
	volatile	uint32_t	RESERVED18[5];
	volatile	uint32_t	TX_PACKET_COUNT_GOOD;
	volatile	uint32_t	RESERVED19[10];
	volatile	uint32_t	RX_CRC_ERROR_PACKETS;
	volatile	uint32_t	RX_ALIGNMENT_ERROR_PACKETS;
	volatile	uint32_t	RESERVED20[10];
	volatile	uint32_t	RX_UNICAST_PACKETS_GOOD;
	volatile	uint32_t	RESERVED21[9];
	volatile	uint32_t	TX_LPI_USEC_CNTR;
	volatile	uint32_t	TX_LPI_TRAN_CNTR;
	volatile	uint32_t	RX_LPI_USEC_CNTR;
	volatile	uint32_t	RX_LPI_TRAN_CNTR;
	volatile	uint32_t	RESERVED22[41];
	volatile	uint32_t	MMC_FPE_TX_ISR;
	volatile	uint32_t	MMC_FPE_TX_IMR;
	volatile	uint32_t	MMC_FPE_TX_FCR;
	volatile	uint32_t	MMC_TX_HRCR;
	volatile	uint32_t	RESERVED23[4];
	volatile	uint32_t	MMC_FPE_RX_ISR;
	volatile	uint32_t	MMC_FPE_RX_IMR;
	volatile	uint32_t	RX_PACKET_ASM_ERR;
	volatile	uint32_t	RX_PACKET_SMD_ERR;
	volatile	uint32_t	RX_PACKET_ASM_OKR;
	volatile	uint32_t	RX_FPE_FRAG_CR;
	volatile	uint32_t	RESERVED24[10];
	volatile	uint32_t	MACL3L4C0R;
	volatile	uint32_t	MACL4A0R;
	volatile	uint32_t	RESERVED25[2];
	volatile	uint32_t	MACL3A00R;
	volatile	uint32_t	MACL3A10R;
	volatile	uint32_t	MACL3A20R;
	volatile	uint32_t	MACL3A30R;
	volatile	uint32_t	RESERVED26[4];
	volatile	uint32_t	MACL3L4C1R;
	volatile	uint32_t	MACL4A1R;
	volatile	uint32_t	RESERVED27[2];
	volatile	uint32_t	MACL3A01R;
	volatile	uint32_t	MACL3A11R;
	volatile	uint32_t	MACL3A21R;
	volatile	uint32_t	MACL3A31R;
	volatile	uint32_t	RESERVED28[72];
	volatile	uint32_t	MAC_IACR;
	volatile	uint32_t	MAC_TMRQR;
	volatile	uint32_t	RESERVED29[34];
	volatile	uint32_t	MACTSCR;
	volatile	uint32_t	MACSSIR;
	volatile	uint32_t	MACSTSR;
	volatile	uint32_t	MACSTNR;
	volatile	uint32_t	MACSTSUR;
	volatile	uint32_t	MACSTNUR;
	volatile	uint32_t	MACTSAR;
	volatile	uint32_t	RESERVED30;
	volatile	uint32_t	MACTSSR;
	volatile	uint32_t	RESERVED31[3];
	volatile	uint32_t	MACTXTSSNR;
	volatile	uint32_t	MACTXTSSSR;
	volatile	uint32_t	RESERVED32[2];
	volatile	uint32_t	MACACR;
	volatile	uint32_t	RESERVED33;
	volatile	uint32_t	MACATSNR;
	volatile	uint32_t	MACATSSR;
	volatile	uint32_t	MACTSIACR;
	volatile	uint32_t	MACTSEACR;
	volatile	uint32_t	MACTSICNR;
	volatile	uint32_t	MACTSECNR;
	volatile	uint32_t	RESERVED34[2];
	volatile	uint32_t	MACTSILR;
	volatile	uint32_t	MACTSELR;
		union {
	volatile	uint32_t	MACPPSCR;
	volatile	uint32_t	MACPPSCR_ALTERNATE;
		};
	volatile	uint32_t	RESERVED35[3];
	volatile	uint32_t	MACPPSTTS0R;
	volatile	uint32_t	MACPPSTTN0R;
	volatile	uint32_t	MACPPSI0R;
	volatile	uint32_t	MACPPSW0R;
	volatile	uint32_t	MACPPSTTS1R;
	volatile	uint32_t	MACPPSTTN1R;
	volatile	uint32_t	MACPPSI1R;
	volatile	uint32_t	MACPPSW1R;
	volatile	uint32_t	RESERVED36[8];
	volatile	uint32_t	MACPOCR;
	volatile	uint32_t	MACSPI0R;
	volatile	uint32_t	MACSPI1R;
	volatile	uint32_t	MACSPI2R;
	volatile	uint32_t	MACLMIR;
	volatile	uint32_t	RESERVED37[11];
	volatile	uint32_t	MTLOMR;
	volatile	uint32_t	RESERVED38[7];
	volatile	uint32_t	MTLISR;
	volatile	uint32_t	RESERVED39[3];
	volatile	uint32_t	MTLRXQDMAMR;
	volatile	uint32_t	RESERVED40[3];
	volatile	uint32_t	MTLTBSCR;
	volatile	uint32_t	RESERVED41[3];
	volatile	uint32_t	MTLESTCR;
	volatile	uint32_t	MTLESTECR;
	volatile	uint32_t	MTLESTSR;
	volatile	uint32_t	RESERVED42;
	volatile	uint32_t	MTLESTSCHER;
	volatile	uint32_t	MTLESTFSER;
	volatile	uint32_t	MTLESTFSCR;
	volatile	uint32_t	RESERVED43;
	volatile	uint32_t	MTLESTIER;
	volatile	uint32_t	RESERVED44[3];
	volatile	uint32_t	MTLESTGCLCR;
	volatile	uint32_t	MTLESTGCLDR;
	volatile	uint32_t	RESERVED45[2];
	volatile	uint32_t	MTLFPECSR;
	volatile	uint32_t	MTLFPEAR;
	volatile	uint32_t	RESERVED46[26];
	volatile	uint32_t	MTLTXQ0OMR;
	volatile	uint32_t	MTLTXQ0UR;
	volatile	uint32_t	MTLTXQ0DR;
	volatile	uint32_t	RESERVED47[2];
	volatile	uint32_t	MTLTXQ0ESR;
	volatile	uint32_t	MTLTXQ0QWR;
	volatile	uint32_t	RESERVED48[4];
	volatile	uint32_t	MTLQ0ICSR;
	volatile	uint32_t	MTLRXQ0OMR;
	volatile	uint32_t	MTLRXQ0MPOCR;
	volatile	uint32_t	MTLRXQ0DR;
	volatile	uint32_t	MTLRXQ0CR;
	volatile	uint32_t	MTLTXQ1OMR;
	volatile	uint32_t	MTLTXQ1UR;
	volatile	uint32_t	MTLTXQ1DR;
	volatile	uint32_t	RESERVED49;
	volatile	uint32_t	MTLTXQ1ECR;
	volatile	uint32_t	MTLTXQ1ESR;
	volatile	uint32_t	MTLTXQ1QWR;
	volatile	uint32_t	MTLTXQ1SSCR;
	volatile	uint32_t	MTLTXQ1HCR;
	volatile	uint32_t	MTLTXQ1LCR;
	volatile	uint32_t	RESERVED50;
	volatile	uint32_t	MTLQ1ICSR;
	volatile	uint32_t	MTLRXQ1OMR;
	volatile	uint32_t	MTLRXQ1MPOCR;
	volatile	uint32_t	MTLRXQ1DR;
	volatile	uint32_t	MTLRXQ1CR;
	volatile	uint32_t	RESERVED51[160];
	volatile	uint32_t	DMAMR;
	volatile	uint32_t	DMASBMR;
	volatile	uint32_t	DMAISR;
	volatile	uint32_t	DMADSR;
	volatile	uint32_t	RESERVED52[4];
	volatile	uint32_t	DMAA4TXACR;
	volatile	uint32_t	DMAA4RXACR;
	volatile	uint32_t	DMAA4DACR;
	volatile	uint32_t	RESERVED53[5];
	volatile	uint32_t	DMALPIEI;
	volatile	uint32_t	RESERVED54[3];
	volatile	uint32_t	DMATBSCTRL0R;
	volatile	uint32_t	RESERVED55[43];
	volatile	uint32_t	DMAC0CR;
	volatile	uint32_t	DMAC0TXCR;
	volatile	uint32_t	DMAC0RXCR;
	volatile	uint32_t	RESERVED56[2];
	volatile	uint32_t	DMAC0TXDLAR;
	volatile	uint32_t	RESERVED57;
	volatile	uint32_t	DMAC0RXDLAR;
	volatile	uint32_t	DMAC0TXDTPR;
	volatile	uint32_t	RESERVED58;
	volatile	uint32_t	DMAC0RXDTPR;
	volatile	uint32_t	DMAC0TXRLR;
	volatile	uint32_t	DMAC0RXRLR;
	volatile	uint32_t	DMAC0IER;
	volatile	uint32_t	DMAC0RXIWTR;
	volatile	uint32_t	DMAC0SFCSR;
	volatile	uint32_t	RESERVED59;
	volatile	uint32_t	DMAC0CATXDR;
	volatile	uint32_t	RESERVED60;
	volatile	uint32_t	DMAC0CARXDR;
	volatile	uint32_t	RESERVED61;
	volatile	uint32_t	DMAC0CATXBR;
	volatile	uint32_t	RESERVED62;
	volatile	uint32_t	DMAC0CARXBR;
	volatile	uint32_t	DMAC0SR;
	volatile	uint32_t	DMAC0MFCR;
	volatile	uint32_t	RESERVED63[6];
	volatile	uint32_t	DMAC1CR;
	volatile	uint32_t	DMAC1TXCR;
	volatile	uint32_t	DMAC1RXCR;
	volatile	uint32_t	RESERVED64[2];
	volatile	uint32_t	DMAC1TXDLAR;
	volatile	uint32_t	RESERVED65[2];
	volatile	uint32_t	DMAC1TXDTPR;
	volatile	uint32_t	RESERVED66;
	volatile	uint32_t	DMAC1RXDTPR;
	volatile	uint32_t	DMAC1TXRLR;
	volatile	uint32_t	DMAC1RXRLR;
	volatile	uint32_t	DMAC1IER;
	volatile	uint32_t	DMAC1RXIWTR;
	volatile	uint32_t	DMAC1SFCSR;
	volatile	uint32_t	RESERVED67;
	volatile	uint32_t	DMAC1CATXDR;
	volatile	uint32_t	RESERVED68;
	volatile	uint32_t	DMAC1CARXDR;
	volatile	uint32_t	RESERVED69;
	volatile	uint32_t	DMAC1CATXBR;
	volatile	uint32_t	RESERVED70;
	volatile	uint32_t	DMAC1CARXBR;
	volatile	uint32_t	DMAC1SR;
	volatile	uint32_t	DMAC1MFCR;
} ETH_TypeDef;

#if (defined(__cplusplus))
#define	ETH_NS	reinterpret_cast<ETH_TypeDef *>(0x48036000u)
#define	ETH_S	reinterpret_cast<ETH_TypeDef *>(0x58036000u)

#else
#define	ETH_NS	((ETH_TypeDef *)0x48036000u)
#define	ETH_S	((ETH_TypeDef *)0x58036000u)
#endif

// MACCR Configuration

#define	ETH_MACCR_ARPEN										(0x1u<<31)
#define	ETH_MACCR_SARC										(0x7u<<28)
#define	ETH_MACCR_SARC_0									(0x1u<<28)
#define	ETH_MACCR_IPC										(0x1u<<27)
#define	ETH_MACCR_IPG										(0x7u<<24)
#define	ETH_MACCR_IPG_0										(0x1u<<24)
#define	ETH_MACCR_GPSLCE									(0x1u<<23)
#define	ETH_MACCR_S2KP										(0x1u<<22)
#define	ETH_MACCR_CST										(0x1u<<21)
#define	ETH_MACCR_ACS										(0x1u<<20)
#define	ETH_MACCR_WD										(0x1u<<19)
#define	ETH_MACCR_BE										(0x1u<<18)
#define	ETH_MACCR_JD										(0x1u<<17)
#define	ETH_MACCR_JE										(0x1u<<16)
#define	ETH_MACCR_PS										(0x1u<<15)
#define	ETH_MACCR_FES										(0x1u<<14)
#define	ETH_MACCR_DM										(0x1u<<13)
#define	ETH_MACCR_LM										(0x1u<<12)
#define	ETH_MACCR_ECRSFD									(0x1u<<11)
#define	ETH_MACCR_DO										(0x1u<<10)
#define	ETH_MACCR_DCRS										(0x1u<<9)
#define	ETH_MACCR_DR										(0x1u<<8)
#define	ETH_MACCR_BL										(0x3u<<5)
#define	ETH_MACCR_BL_0										(0x1u<<5)
#define	ETH_MACCR_DC										(0x1u<<4)
#define	ETH_MACCR_PRELEN									(0x3u<<2)
#define	ETH_MACCR_PRELEN_0									(0x1u<<2)
#define	ETH_MACCR_TE										(0x1u<<1)
#define	ETH_MACCR_RE										(0x1u<<0)

#define	ETH_MACCR_SARC_B_0X2								(0x2u<<28)
#define	ETH_MACCR_SARC_B_0X3								(0x3u<<28)
#define	ETH_MACCR_SARC_B_0X6								(0x6u<<28)
#define	ETH_MACCR_SARC_B_0X7								(0x7u<<28)
#define	ETH_MACCR_IPG_B_0X0									(0x0u<<24)
#define	ETH_MACCR_IPG_B_0X1									(0x1u<<24)
#define	ETH_MACCR_IPG_B_0X2									(0x2u<<24)
#define	ETH_MACCR_IPG_B_0X7									(0x7u<<24)
#define	ETH_MACCR_PS_B_0X0									(0x0u<<15)
#define	ETH_MACCR_PS_B_0X1									(0x1u<<15)
#define	ETH_MACCR_FES_B_0X0									(0x0u<<14)
#define	ETH_MACCR_FES_B_0X1									(0x1u<<14)
#define	ETH_MACCR_BL_B_0X0									(0x0u<<5)
#define	ETH_MACCR_BL_B_0X1									(0x1u<<5)
#define	ETH_MACCR_BL_B_0X2									(0x2u<<5)
#define	ETH_MACCR_BL_B_0X3									(0x3u<<5)
#define	ETH_MACCR_PRELEN_B_0X0								(0x0u<<2)
#define	ETH_MACCR_PRELEN_B_0X1								(0x1u<<2)
#define	ETH_MACCR_PRELEN_B_0X2								(0x2u<<2)

// MACECR Configuration

#define	ETH_MACECR_APDIM									(0x1u<<30)
#define	ETH_MACECR_EIPG										(0x1Fu<<25)
#define	ETH_MACECR_EIPG_0									(0x1u<<25)
#define	ETH_MACECR_EIPGEN									(0x1u<<24)
#define	ETH_MACECR_USP										(0x1u<<18)
#define	ETH_MACECR_SPEN										(0x1u<<17)
#define	ETH_MACECR_DCRCC									(0x1u<<16)
#define	ETH_MACECR_GPSL										(0x3FFFu<<0)
#define	ETH_MACECR_GPSL_0									(0x1u<<0)

// MACPFR Configuration

#define	ETH_MACPFR_RA										(0x1u<<31)
#define	ETH_MACPFR_DNTU										(0x1u<<21)
#define	ETH_MACPFR_IPFE										(0x1u<<20)
#define	ETH_MACPFR_VTFE										(0x1u<<16)
#define	ETH_MACPFR_HPF										(0x1u<<10)
#define	ETH_MACPFR_SAF										(0x1u<<9)
#define	ETH_MACPFR_SAIF										(0x1u<<8)
#define	ETH_MACPFR_PCF										(0x3u<<6)
#define	ETH_MACPFR_PCF_0									(0x1u<<6)
#define	ETH_MACPFR_DBF										(0x1u<<5)
#define	ETH_MACPFR_PM										(0x1u<<4)
#define	ETH_MACPFR_DAIF										(0x1u<<3)
#define	ETH_MACPFR_HMC										(0x1u<<2)
#define	ETH_MACPFR_HUC										(0x1u<<1)
#define	ETH_MACPFR_PR										(0x1u<<0)

#define	ETH_MACPFR_PCF_B_0X0								(0x0u<<6)
#define	ETH_MACPFR_PCF_B_0X1								(0x1u<<6)
#define	ETH_MACPFR_PCF_B_0X2								(0x2u<<6)
#define	ETH_MACPFR_PCF_B_0X3								(0x3u<<6)

// MACWTR Configuration

#define	ETH_MACWTR_PWE										(0x1u<<8)
#define	ETH_MACWTR_WTO										(0xFu<<0)
#define	ETH_MACWTR_WTO_0									(0x1u<<0)

#define	ETH_MACWTR_WTO_B_0X0								(0x0u<<0)
#define	ETH_MACWTR_WTO_B_0X1								(0x1u<<0)
#define	ETH_MACWTR_WTO_B_0X2								(0x2u<<0)
#define	ETH_MACWTR_WTO_B_0X3								(0x3u<<0)
#define	ETH_MACWTR_WTO_B_0XC								(0xCu<<0)
#define	ETH_MACWTR_WTO_B_0XD								(0xDu<<0)
#define	ETH_MACWTR_WTO_B_0XE								(0xEu<<0)

// MACHT0R Configuration

#define	ETH_MACHT0R_HT31T0									(0xFFFFFFFFu<<0)
#define	ETH_MACHT0R_HT31T0_0								(0x1u<<0)

// MACHT1R Configuration

#define	ETH_MACHT1R_HT63T32									(0xFFFFFFFFu<<0)
#define	ETH_MACHT1R_HT63T32_0								(0x1u<<0)

// MACVTCR Configuration

#define	ETH_MACVTCR_EIVLRXS									(0x1u<<31)
#define	ETH_MACVTCR_EIVLS									(0x3u<<28)
#define	ETH_MACVTCR_EIVLS_0									(0x1u<<28)
#define	ETH_MACVTCR_ERIVLT									(0x1u<<27)
#define	ETH_MACVTCR_EDVLP									(0x1u<<26)
#define	ETH_MACVTCR_VTHM									(0x1u<<25)
#define	ETH_MACVTCR_EVLRXS									(0x1u<<24)
#define	ETH_MACVTCR_EVLS									(0x3u<<21)
#define	ETH_MACVTCR_EVLS_0									(0x1u<<21)
#define	ETH_MACVTCR_DOVLTC									(0x1u<<20)
#define	ETH_MACVTCR_ERSVLM									(0x1u<<19)
#define	ETH_MACVTCR_ESVL									(0x1u<<18)
#define	ETH_MACVTCR_VTIM									(0x1u<<17)
#define	ETH_MACVTCR_ETV										(0x1u<<16)
#define	ETH_MACVTCR_OFS										(0x3u<<2)
#define	ETH_MACVTCR_OFS_0									(0x1u<<2)
#define	ETH_MACVTCR_CT										(0x1u<<1)
#define	ETH_MACVTCR_OB										(0x1u<<0)

#define	ETH_MACVTCR_EIVLS_B_0X0								(0x0u<<28)
#define	ETH_MACVTCR_EIVLS_B_0X1								(0x1u<<28)
#define	ETH_MACVTCR_EIVLS_B_0X2								(0x2u<<28)
#define	ETH_MACVTCR_EIVLS_B_0X3								(0x3u<<28)
#define	ETH_MACVTCR_EVLS_B_0X0								(0x0u<<21)
#define	ETH_MACVTCR_EVLS_B_0X1								(0x1u<<21)
#define	ETH_MACVTCR_EVLS_B_0X2								(0x2u<<21)
#define	ETH_MACVTCR_EVLS_B_0X3								(0x3u<<21)
#define	ETH_MACVTCR_OFS_B_0X0								(0x0u<<2)
#define	ETH_MACVTCR_OFS_B_0X1								(0x1u<<2)
#define	ETH_MACVTCR_OFS_B_0X2								(0x2u<<2)
#define	ETH_MACVTCR_OFS_B_0X3								(0x3u<<2)

// MACVTDR Configuration

#define	ETH_MACVTDR_DMACHN									(0x1u<<25)
#define	ETH_MACVTDR_DMACHEN									(0x1u<<24)
#define	ETH_MACVTDR_ERIVLT									(0x1u<<20)
#define	ETH_MACVTDR_ERSVLM									(0x1u<<19)
#define	ETH_MACVTDR_DOVLTC									(0x1u<<18)
#define	ETH_MACVTDR_ETV										(0x1u<<17)
#define	ETH_MACVTDR_VEN										(0x1u<<16)
#define	ETH_MACVTDR_VID										(0xFFFFu<<0)
#define	ETH_MACVTDR_VID_0									(0x1u<<0)

#define	ETH_MACVTDR_ETV_B_0X0								(0x0u<<17)
#define	ETH_MACVTDR_ETV_B_0X1								(0x1u<<17)

// MACVHTR Configuration

#define	ETH_MACVHTR_VLHT									(0xFFFFu<<0)
#define	ETH_MACVHTR_VLHT_0									(0x1u<<0)

// MACVIR Configuration

#define	ETH_MACVIR_BUSY										(0x1u<<31)
#define	ETH_MACVIR_RDWR										(0x1u<<30)
#define	ETH_MACVIR_ADDR										(0x1u<<24)
#define	ETH_MACVIR_CBTI										(0x1u<<21)
#define	ETH_MACVIR_VLTI										(0x1u<<20)
#define	ETH_MACVIR_CSVL										(0x1u<<19)
#define	ETH_MACVIR_VLP										(0x1u<<18)
#define	ETH_MACVIR_VLC										(0x3u<<16)
#define	ETH_MACVIR_VLC_0									(0x1u<<16)
#define	ETH_MACVIR_VLT										(0xFFFFu<<0)
#define	ETH_MACVIR_VLT_0									(0x1u<<0)

#define	ETH_MACVIR_ADDR_B_0X0								(0x0u<<24)
#define	ETH_MACVIR_ADDR_B_0X1								(0x1u<<24)
#define	ETH_MACVIR_CSVL_B_0X0								(0x0u<<19)
#define	ETH_MACVIR_CSVL_B_0X1								(0x1u<<19)
#define	ETH_MACVIR_VLC_B_0X0								(0x0u<<16)
#define	ETH_MACVIR_VLC_B_0X1								(0x1u<<16)
#define	ETH_MACVIR_VLC_B_0X2								(0x2u<<16)
#define	ETH_MACVIR_VLC_B_0X3								(0x3u<<16)

// MACVIR_ALTERNATE Configuration

#define	ETH_MACVIR_ALTERNATE_CSVL							(0x1u<<19)
#define	ETH_MACVIR_ALTERNATE_VLT							(0xFFFFu<<0)
#define	ETH_MACVIR_ALTERNATE_VLT_0							(0x1u<<0)

#define	ETH_MACVIR_ALTERNATE_CSVL_B_0X0						(0x0u<<19)
#define	ETH_MACVIR_ALTERNATE_CSVL_B_0X1						(0x1u<<19)

// MACIVIR Configuration

#define	ETH_MACIVIR_VLTI									(0x1u<<20)
#define	ETH_MACIVIR_CSVL									(0x1u<<19)
#define	ETH_MACIVIR_VLP										(0x1u<<18)
#define	ETH_MACIVIR_VLC										(0x3u<<16)
#define	ETH_MACIVIR_VLC_0									(0x1u<<16)
#define	ETH_MACIVIR_VLT										(0xFFFFu<<0)
#define	ETH_MACIVIR_VLT_0									(0x1u<<0)

#define	ETH_MACIVIR_CSVL_B_0X0								(0x0u<<19)
#define	ETH_MACIVIR_CSVL_B_0X1								(0x1u<<19)
#define	ETH_MACIVIR_VLC_B_0X0								(0x0u<<16)
#define	ETH_MACIVIR_VLC_B_0X1								(0x1u<<16)
#define	ETH_MACIVIR_VLC_B_0X2								(0x2u<<16)
#define	ETH_MACIVIR_VLC_B_0X3								(0x3u<<16)

// MACQ0TXFCR Configuration

#define	ETH_MACQ0TXFCR_PT									(0xFFFFu<<16)
#define	ETH_MACQ0TXFCR_PT_0									(0x1u<<16)
#define	ETH_MACQ0TXFCR_DZPQ									(0x1u<<7)
#define	ETH_MACQ0TXFCR_PLT									(0x7u<<4)
#define	ETH_MACQ0TXFCR_PLT_0								(0x1u<<4)
#define	ETH_MACQ0TXFCR_TFE									(0x1u<<1)
#define	ETH_MACQ0TXFCR_FCB_BPA								(0x1u<<0)

#define	ETH_MACQ0TXFCR_PLT_B_0X0							(0x0u<<4)
#define	ETH_MACQ0TXFCR_PLT_B_0X1							(0x1u<<4)
#define	ETH_MACQ0TXFCR_PLT_B_0X2							(0x2u<<4)
#define	ETH_MACQ0TXFCR_PLT_B_0X3							(0x3u<<4)
#define	ETH_MACQ0TXFCR_PLT_B_0X4							(0x4u<<4)
#define	ETH_MACQ0TXFCR_PLT_B_0X5							(0x5u<<4)

// MACRXFCR Configuration

#define	ETH_MACRXFCR_UP										(0x1u<<1)
#define	ETH_MACRXFCR_RFE									(0x1u<<0)

// MACRXQCR Configuration

#define	ETH_MACRXQCR_VFFQ									(0x1u<<17)
#define	ETH_MACRXQCR_VFFQE									(0x1u<<16)
#define	ETH_MACRXQCR_MFFQ									(0x1u<<9)
#define	ETH_MACRXQCR_MFFQE									(0x1u<<8)
#define	ETH_MACRXQCR_UFFQ									(0x1u<<1)
#define	ETH_MACRXQCR_UFFQE									(0x1u<<0)

#define	ETH_MACRXQCR_VFFQ_B_0X0								(0x0u<<17)
#define	ETH_MACRXQCR_VFFQ_B_0X1								(0x1u<<17)
#define	ETH_MACRXQCR_VFFQE_B_0X0							(0x0u<<16)
#define	ETH_MACRXQCR_VFFQE_B_0X1							(0x1u<<16)
#define	ETH_MACRXQCR_MFFQ_B_0X0								(0x0u<<9)
#define	ETH_MACRXQCR_MFFQ_B_0X1								(0x1u<<9)
#define	ETH_MACRXQCR_UFFQ_B_0X0								(0x0u<<1)
#define	ETH_MACRXQCR_UFFQ_B_0X1								(0x1u<<1)

// MACRXQC0R Configuration

#define	ETH_MACRXQC0R_RXQ1EN								(0x3u<<2)
#define	ETH_MACRXQC0R_RXQ1EN_0								(0x1u<<2)
#define	ETH_MACRXQC0R_RXQ0EN								(0x3u<<0)
#define	ETH_MACRXQC0R_RXQ0EN_0								(0x1u<<0)

#define	ETH_MACRXQC0R_RXQ1EN_B_0X0							(0x0u<<2)
#define	ETH_MACRXQC0R_RXQ1EN_B_0X1							(0x1u<<2)
#define	ETH_MACRXQC0R_RXQ1EN_B_0X2							(0x2u<<2)
#define	ETH_MACRXQC0R_RXQ0EN_B_0X0							(0x0u<<0)
#define	ETH_MACRXQC0R_RXQ0EN_B_0X1							(0x1u<<0)
#define	ETH_MACRXQC0R_RXQ0EN_B_0X2							(0x2u<<0)

// MACRXQC1R Configuration

#define	ETH_MACRXQC1R_TBRQE									(0x1u<<29)
#define	ETH_MACRXQC1R_OMCBCQ								(0x1u<<28)
#define	ETH_MACRXQC1R_FPRQ2									(0x1u<<26)
#define	ETH_MACRXQC1R_FPRQ1									(0x1u<<25)
#define	ETH_MACRXQC1R_FPRQ0									(0x1u<<24)
#define	ETH_MACRXQC1R_TPQC									(0x3u<<22)
#define	ETH_MACRXQC1R_TPQC_0								(0x1u<<22)
#define	ETH_MACRXQC1R_TACPQE								(0x1u<<21)
#define	ETH_MACRXQC1R_MCBCQEN								(0x1u<<20)
#define	ETH_MACRXQC1R_MCBCQ									(0x7u<<16)
#define	ETH_MACRXQC1R_MCBCQ_0								(0x1u<<16)
#define	ETH_MACRXQC1R_UPQ									(0x7u<<12)
#define	ETH_MACRXQC1R_UPQ_0									(0x1u<<12)
#define	ETH_MACRXQC1R_PTPQ									(0x7u<<4)
#define	ETH_MACRXQC1R_PTPQ_0								(0x1u<<4)
#define	ETH_MACRXQC1R_AVCPQ2								(0x1u<<2)
#define	ETH_MACRXQC1R_AVCPQ1								(0x1u<<1)
#define	ETH_MACRXQC1R_AVCPQ0								(0x1u<<0)

#define	ETH_MACRXQC1R_OMCBCQ_B_0X1							(0x1u<<28)
#define	ETH_MACRXQC1R_OMCBCQ_B_0X0							(0x0u<<28)
#define	ETH_MACRXQC1R_FPRQ2_B_0X1							(0x1u<<26)
#define	ETH_MACRXQC1R_FPRQ1_B_0X1							(0x1u<<25)
#define	ETH_MACRXQC1R_FPRQ0_B_0X1							(0x1u<<24)
#define	ETH_MACRXQC1R_TPQC_B_0X0							(0x0u<<22)
#define	ETH_MACRXQC1R_TPQC_B_0X1							(0x1u<<22)
#define	ETH_MACRXQC1R_TPQC_B_0X2							(0x2u<<22)
#define	ETH_MACRXQC1R_MCBCQ_B_0X0							(0x0u<<16)
#define	ETH_MACRXQC1R_MCBCQ_B_0X1							(0x1u<<16)
#define	ETH_MACRXQC1R_UPQ_B_0X0								(0x0u<<12)
#define	ETH_MACRXQC1R_UPQ_B_0X1								(0x1u<<12)
#define	ETH_MACRXQC1R_PTPQ_B_0X0							(0x0u<<4)
#define	ETH_MACRXQC1R_PTPQ_B_0X1							(0x1u<<4)
#define	ETH_MACRXQC1R_AVCPQ2_B_0X0							(0x0u<<2)
#define	ETH_MACRXQC1R_AVCPQ2_B_0X1							(0x1u<<2)
#define	ETH_MACRXQC1R_AVCPQ1_B_0X0							(0x0u<<1)
#define	ETH_MACRXQC1R_AVCPQ1_B_0X1							(0x1u<<1)
#define	ETH_MACRXQC1R_AVCPQ0_B_0X0							(0x0u<<0)
#define	ETH_MACRXQC1R_AVCPQ0_B_0X1							(0x1u<<0)

// MACRXQC2R Configuration

#define	ETH_MACRXQC2R_PSRQ1									(0xFFu<<8)
#define	ETH_MACRXQC2R_PSRQ1_0								(0x1u<<8)
#define	ETH_MACRXQC2R_PSRQ0									(0xFFu<<0)
#define	ETH_MACRXQC2R_PSRQ0_0								(0x1u<<0)

// MACISR Configuration

#define	ETH_MACISR_MFRIS									(0x1u<<20)
#define	ETH_MACISR_MFTIS									(0x1u<<19)
#define	ETH_MACISR_MDIOIS									(0x1u<<18)
#define	ETH_MACISR_FPEIS									(0x1u<<17)
#define	ETH_MACISR_RXSTSIS									(0x1u<<14)
#define	ETH_MACISR_TXSTSIS									(0x1u<<13)
#define	ETH_MACISR_TSIS										(0x1u<<12)
#define	ETH_MACISR_MMCTXIS									(0x1u<<10)
#define	ETH_MACISR_MMCRXIS									(0x1u<<9)
#define	ETH_MACISR_MMCIS									(0x1u<<8)
#define	ETH_MACISR_LPIIS									(0x1u<<5)
#define	ETH_MACISR_PMTIS									(0x1u<<4)
#define	ETH_MACISR_PHYIS									(0x1u<<3)
#define	ETH_MACISR_RGSMIIIS									(0x1u<<0)

// MACIER Configuration

#define	ETH_MACIER_MDIOIE									(0x1u<<18)
#define	ETH_MACIER_FPEIE									(0x1u<<17)
#define	ETH_MACIER_RXSTSIE									(0x1u<<14)
#define	ETH_MACIER_TXSTSIE									(0x1u<<13)
#define	ETH_MACIER_TSIE										(0x1u<<12)
#define	ETH_MACIER_LPIIE									(0x1u<<5)
#define	ETH_MACIER_PMTIE									(0x1u<<4)
#define	ETH_MACIER_PHYIE									(0x1u<<3)
#define	ETH_MACIER_RGSMIIIE									(0x1u<<0)

// MACRXTXSR Configuration

#define	ETH_MACRXTXSR_RWT									(0x1u<<8)
#define	ETH_MACRXTXSR_EXCOL									(0x1u<<5)
#define	ETH_MACRXTXSR_LCOL									(0x1u<<4)
#define	ETH_MACRXTXSR_EXDEF									(0x1u<<3)
#define	ETH_MACRXTXSR_LCARR									(0x1u<<2)
#define	ETH_MACRXTXSR_NCARR									(0x1u<<1)
#define	ETH_MACRXTXSR_TJT									(0x1u<<0)

// MACPCSR Configuration

#define	ETH_MACPCSR_RWKFILTRST								(0x1u<<31)
#define	ETH_MACPCSR_RWKPTR									(0x1Fu<<24)
#define	ETH_MACPCSR_RWKPTR_0								(0x1u<<24)
#define	ETH_MACPCSR_RWKPFE									(0x1u<<10)
#define	ETH_MACPCSR_GLBLUCAST								(0x1u<<9)
#define	ETH_MACPCSR_RWKPRCVD								(0x1u<<6)
#define	ETH_MACPCSR_MGKPRCVD								(0x1u<<5)
#define	ETH_MACPCSR_RWKPKTEN								(0x1u<<2)
#define	ETH_MACPCSR_MGKPKTEN								(0x1u<<1)
#define	ETH_MACPCSR_PWRDWN									(0x1u<<0)

// MACRWKPFR Configuration

#define	ETH_MACRWKPFR_MACRWKPFR								(0xFFFFFFFFu<<0)
#define	ETH_MACRWKPFR_MACRWKPFR_0							(0x1u<<0)

// MACLCSR Configuration

#define	ETH_MACLCSR_LPITCSE									(0x1u<<21)
#define	ETH_MACLCSR_LPITE									(0x1u<<20)
#define	ETH_MACLCSR_LPITXA									(0x1u<<19)
#define	ETH_MACLCSR_PLSEN									(0x1u<<18)
#define	ETH_MACLCSR_PLS										(0x1u<<17)
#define	ETH_MACLCSR_LPIEN									(0x1u<<16)
#define	ETH_MACLCSR_RLPIST									(0x1u<<9)
#define	ETH_MACLCSR_TLPIST									(0x1u<<8)
#define	ETH_MACLCSR_RLPIEX									(0x1u<<3)
#define	ETH_MACLCSR_RLPIEN									(0x1u<<2)
#define	ETH_MACLCSR_TLPIEX									(0x1u<<1)
#define	ETH_MACLCSR_TLPIEN									(0x1u<<0)

// MACLTCR Configuration

#define	ETH_MACLTCR_LST										(0x3FFu<<16)
#define	ETH_MACLTCR_LST_0									(0x1u<<16)
#define	ETH_MACLTCR_TWT										(0xFFFFu<<0)
#define	ETH_MACLTCR_TWT_0									(0x1u<<0)

// MACLETR Configuration

#define	ETH_MACLETR_LPIET									(0xFFFFFu<<0)
#define	ETH_MACLETR_LPIET_0									(0x1u<<0)

// MAC1USTCR Configuration

#define	ETH_MAC1USTCR_TIC_1US_CNTR							(0xFFFu<<0)
#define	ETH_MAC1USTCR_TIC_1US_CNTR_0						(0x1u<<0)

// MACPHYCSR Configuration

#define	ETH_MACPHYCSR_LNKSTS								(0x1u<<19)
#define	ETH_MACPHYCSR_LNKSPEED								(0x3u<<17)
#define	ETH_MACPHYCSR_LNKSPEED_0							(0x1u<<17)
#define	ETH_MACPHYCSR_LNKMOD								(0x1u<<16)
#define	ETH_MACPHYCSR_LUD									(0x1u<<1)
#define	ETH_MACPHYCSR_TC									(0x1u<<0)

#define	ETH_MACPHYCSR_LNKSTS_B_0X0							(0x0u<<19)
#define	ETH_MACPHYCSR_LNKSTS_B_0X1							(0x1u<<19)
#define	ETH_MACPHYCSR_LNKSPEED_B_0X0						(0x0u<<17)
#define	ETH_MACPHYCSR_LNKSPEED_B_0X1						(0x1u<<17)
#define	ETH_MACPHYCSR_LNKSPEED_B_0X2						(0x2u<<17)
#define	ETH_MACPHYCSR_LNKMOD_B_0X0							(0x0u<<16)
#define	ETH_MACPHYCSR_LNKMOD_B_0X1							(0x1u<<16)
#define	ETH_MACPHYCSR_LUD_B_0X0								(0x0u<<1)
#define	ETH_MACPHYCSR_LUD_B_0X1								(0x1u<<1)

// MACVR Configuration

#define	ETH_MACVR_USERVER									(0xFFu<<8)
#define	ETH_MACVR_USERVER_0									(0x1u<<8)
#define	ETH_MACVR_SNPSVER									(0xFFu<<0)
#define	ETH_MACVR_SNPSVER_0									(0x1u<<0)

// MACDR Configuration

#define	ETH_MACDR_TFCSTS									(0x3u<<17)
#define	ETH_MACDR_TFCSTS_0									(0x1u<<17)
#define	ETH_MACDR_TPESTS									(0x1u<<16)
#define	ETH_MACDR_RFCFCSTS									(0x3u<<1)
#define	ETH_MACDR_RFCFCSTS_0								(0x1u<<1)
#define	ETH_MACDR_RPESTS									(0x1u<<0)

#define	ETH_MACDR_TFCSTS_B_0X0								(0x0u<<17)
#define	ETH_MACDR_TFCSTS_B_0X1								(0x1u<<17)
#define	ETH_MACDR_TFCSTS_B_0X2								(0x2u<<17)
#define	ETH_MACDR_TFCSTS_B_0X3								(0x3u<<17)

// MACHWF0R Configuration

#define	ETH_MACHWF0R_ACTPHYSEL								(0x7u<<28)
#define	ETH_MACHWF0R_ACTPHYSEL_0							(0x1u<<28)
#define	ETH_MACHWF0R_SAVLANINS								(0x1u<<27)
#define	ETH_MACHWF0R_TSSTSSEL								(0x3u<<25)
#define	ETH_MACHWF0R_TSSTSSEL_0								(0x1u<<25)
#define	ETH_MACHWF0R_MACADR64SEL							(0x1u<<24)
#define	ETH_MACHWF0R_MACADR32SEL							(0x1u<<23)
#define	ETH_MACHWF0R_ADDMACADRSEL							(0x1Fu<<18)
#define	ETH_MACHWF0R_ADDMACADRSEL_0							(0x1u<<18)
#define	ETH_MACHWF0R_RXCOESEL								(0x1u<<16)
#define	ETH_MACHWF0R_TXCOESEL								(0x1u<<14)
#define	ETH_MACHWF0R_EEESEL									(0x1u<<13)
#define	ETH_MACHWF0R_TSSEL									(0x1u<<12)
#define	ETH_MACHWF0R_ARPOFFSEL								(0x1u<<9)
#define	ETH_MACHWF0R_MMCSEL									(0x1u<<8)
#define	ETH_MACHWF0R_MGKSEL									(0x1u<<7)
#define	ETH_MACHWF0R_RWKSEL									(0x1u<<6)
#define	ETH_MACHWF0R_SMASEL									(0x1u<<5)
#define	ETH_MACHWF0R_VLHASH									(0x1u<<4)
#define	ETH_MACHWF0R_PCSSEL									(0x1u<<3)
#define	ETH_MACHWF0R_HDSEL									(0x1u<<2)
#define	ETH_MACHWF0R_GMIISEL								(0x1u<<1)
#define	ETH_MACHWF0R_MIISEL									(0x1u<<0)

#define	ETH_MACHWF0R_ACTPHYSEL_B_0X0						(0x0u<<28)
#define	ETH_MACHWF0R_ACTPHYSEL_B_0X1						(0x1u<<28)
#define	ETH_MACHWF0R_ACTPHYSEL_B_0X2						(0x2u<<28)
#define	ETH_MACHWF0R_ACTPHYSEL_B_0X3						(0x3u<<28)
#define	ETH_MACHWF0R_ACTPHYSEL_B_0X4						(0x4u<<28)
#define	ETH_MACHWF0R_ACTPHYSEL_B_0X5						(0x5u<<28)
#define	ETH_MACHWF0R_ACTPHYSEL_B_0X6						(0x6u<<28)
#define	ETH_MACHWF0R_TSSTSSEL_B_0X1							(0x1u<<25)
#define	ETH_MACHWF0R_TSSTSSEL_B_0X2							(0x2u<<25)
#define	ETH_MACHWF0R_TSSTSSEL_B_0X3							(0x3u<<25)

// MACHWF1R Configuration

#define	ETH_MACHWF1R_L3L4FNUM								(0xFu<<27)
#define	ETH_MACHWF1R_L3L4FNUM_0								(0x1u<<27)
#define	ETH_MACHWF1R_HASHTBLSZ								(0x3u<<24)
#define	ETH_MACHWF1R_HASHTBLSZ_0							(0x1u<<24)
#define	ETH_MACHWF1R_POUOST									(0x1u<<23)
#define	ETH_MACHWF1R_RAVSEL									(0x1u<<21)
#define	ETH_MACHWF1R_AVSEL									(0x1u<<20)
#define	ETH_MACHWF1R_DBGMEMA								(0x1u<<19)
#define	ETH_MACHWF1R_TSOEN									(0x1u<<18)
#define	ETH_MACHWF1R_SPHEN									(0x1u<<17)
#define	ETH_MACHWF1R_DCBEN									(0x1u<<16)
#define	ETH_MACHWF1R_ADDR64									(0x3u<<14)
#define	ETH_MACHWF1R_ADDR64_0								(0x1u<<14)
#define	ETH_MACHWF1R_ADVTHWORD								(0x1u<<13)
#define	ETH_MACHWF1R_PTOEN									(0x1u<<12)
#define	ETH_MACHWF1R_OSTEN									(0x1u<<11)
#define	ETH_MACHWF1R_TXFIFOSIZE								(0x1Fu<<6)
#define	ETH_MACHWF1R_TXFIFOSIZE_0							(0x1u<<6)
#define	ETH_MACHWF1R_SPRAM									(0x1u<<5)
#define	ETH_MACHWF1R_RXFIFOSIZE								(0x1Fu<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_0							(0x1u<<0)

#define	ETH_MACHWF1R_L3L4FNUM_B_0X0							(0x0u<<27)
#define	ETH_MACHWF1R_L3L4FNUM_B_0X1							(0x1u<<27)
#define	ETH_MACHWF1R_L3L4FNUM_B_0X2							(0x2u<<27)
#define	ETH_MACHWF1R_L3L4FNUM_B_0X8							(0x8u<<27)
#define	ETH_MACHWF1R_HASHTBLSZ_B_0X0						(0x0u<<24)
#define	ETH_MACHWF1R_HASHTBLSZ_B_0X1						(0x1u<<24)
#define	ETH_MACHWF1R_HASHTBLSZ_B_0X2						(0x2u<<24)
#define	ETH_MACHWF1R_HASHTBLSZ_B_0X3						(0x3u<<24)
#define	ETH_MACHWF1R_ADDR64_B_0X0							(0x0u<<14)
#define	ETH_MACHWF1R_TXFIFOSIZE_B_0X0						(0x0u<<6)
#define	ETH_MACHWF1R_TXFIFOSIZE_B_0X1						(0x1u<<6)
#define	ETH_MACHWF1R_TXFIFOSIZE_B_0X2						(0x2u<<6)
#define	ETH_MACHWF1R_TXFIFOSIZE_B_0X3						(0x3u<<6)
#define	ETH_MACHWF1R_TXFIFOSIZE_B_0X4						(0x4u<<6)
#define	ETH_MACHWF1R_TXFIFOSIZE_B_0X5						(0x5u<<6)
#define	ETH_MACHWF1R_TXFIFOSIZE_B_0X6						(0x6u<<6)
#define	ETH_MACHWF1R_TXFIFOSIZE_B_0X7						(0x7u<<6)
#define	ETH_MACHWF1R_TXFIFOSIZE_B_0X8						(0x8u<<6)
#define	ETH_MACHWF1R_TXFIFOSIZE_B_0X9						(0x9u<<6)
#define	ETH_MACHWF1R_TXFIFOSIZE_B_0XA						(0xAu<<6)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0X0						(0x0u<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0X1						(0x1u<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0X2						(0x2u<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0X3						(0x3u<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0X4						(0x4u<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0X5						(0x5u<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0X6						(0x6u<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0X7						(0x7u<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0X8						(0x8u<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0X9						(0x9u<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0XA						(0xAu<<0)
#define	ETH_MACHWF1R_RXFIFOSIZE_B_0XB						(0xBu<<0)

// MACHWF2R Configuration

#define	ETH_MACHWF2R_AUXSNAPNUM								(0x7u<<28)
#define	ETH_MACHWF2R_AUXSNAPNUM_0							(0x1u<<28)
#define	ETH_MACHWF2R_PPSOUTNUM								(0x7u<<24)
#define	ETH_MACHWF2R_PPSOUTNUM_0							(0x1u<<24)
#define	ETH_MACHWF2R_TDCSZ									(0x3u<<22)
#define	ETH_MACHWF2R_TDCSZ_0								(0x1u<<22)
#define	ETH_MACHWF2R_TXCHCNT								(0xFu<<18)
#define	ETH_MACHWF2R_TXCHCNT_0								(0x1u<<18)
#define	ETH_MACHWF2R_RDCSZ									(0x3u<<16)
#define	ETH_MACHWF2R_RDCSZ_0								(0x1u<<16)
#define	ETH_MACHWF2R_RXCHCNT								(0xFu<<12)
#define	ETH_MACHWF2R_RXCHCNT_0								(0x1u<<12)
#define	ETH_MACHWF2R_TXQCNT									(0xFu<<6)
#define	ETH_MACHWF2R_TXQCNT_0								(0x1u<<6)
#define	ETH_MACHWF2R_RXQCNT									(0xFu<<0)
#define	ETH_MACHWF2R_RXQCNT_0								(0x1u<<0)

#define	ETH_MACHWF2R_AUXSNAPNUM_B_0X0						(0x0u<<28)
#define	ETH_MACHWF2R_AUXSNAPNUM_B_0X1						(0x1u<<28)
#define	ETH_MACHWF2R_AUXSNAPNUM_B_0X2						(0x2u<<28)
#define	ETH_MACHWF2R_AUXSNAPNUM_B_0X3						(0x3u<<28)
#define	ETH_MACHWF2R_AUXSNAPNUM_B_0X4						(0x4u<<28)
#define	ETH_MACHWF2R_PPSOUTNUM_B_0X0						(0x0u<<24)
#define	ETH_MACHWF2R_PPSOUTNUM_B_0X1						(0x1u<<24)
#define	ETH_MACHWF2R_PPSOUTNUM_B_0X2						(0x2u<<24)
#define	ETH_MACHWF2R_PPSOUTNUM_B_0X3						(0x3u<<24)
#define	ETH_MACHWF2R_PPSOUTNUM_B_0X4						(0x4u<<24)
#define	ETH_MACHWF2R_TDCSZ_B_0X0							(0x0u<<22)
#define	ETH_MACHWF2R_TDCSZ_B_0X1							(0x1u<<22)
#define	ETH_MACHWF2R_TDCSZ_B_0X2							(0x2u<<22)
#define	ETH_MACHWF2R_TDCSZ_B_0X3							(0x3u<<22)
#define	ETH_MACHWF2R_TXCHCNT_B_0X0							(0x0u<<18)
#define	ETH_MACHWF2R_TXCHCNT_B_0X1							(0x1u<<18)
#define	ETH_MACHWF2R_TXCHCNT_B_0X7							(0x7u<<18)
#define	ETH_MACHWF2R_RDCSZ_B_0X0							(0x0u<<16)
#define	ETH_MACHWF2R_RDCSZ_B_0X1							(0x1u<<16)
#define	ETH_MACHWF2R_RDCSZ_B_0X2							(0x2u<<16)
#define	ETH_MACHWF2R_RDCSZ_B_0X3							(0x3u<<16)
#define	ETH_MACHWF2R_RXCHCNT_B_0X0							(0x0u<<12)
#define	ETH_MACHWF2R_RXCHCNT_B_0X1							(0x1u<<12)
#define	ETH_MACHWF2R_RXCHCNT_B_0X7							(0x7u<<12)
#define	ETH_MACHWF2R_TXQCNT_B_0X0							(0x0u<<6)
#define	ETH_MACHWF2R_TXQCNT_B_0X1							(0x1u<<6)
#define	ETH_MACHWF2R_TXQCNT_B_0X7							(0x7u<<6)
#define	ETH_MACHWF2R_RXQCNT_B_0X0							(0x0u<<0)
#define	ETH_MACHWF2R_RXQCNT_B_0X1							(0x1u<<0)
#define	ETH_MACHWF2R_RXQCNT_B_0X7							(0x7u<<0)

// MACHWF3R Configuration

#define	ETH_MACHWF3R_ASP									(0x3u<<28)
#define	ETH_MACHWF3R_ASP_0									(0x1u<<28)
#define	ETH_MACHWF3R_TBSSEL									(0x1u<<27)
#define	ETH_MACHWF3R_FPESEL									(0x1u<<26)
#define	ETH_MACHWF3R_ESTWID									(0x3u<<20)
#define	ETH_MACHWF3R_ESTWID_0								(0x1u<<20)
#define	ETH_MACHWF3R_ESTDEP									(0x7u<<17)
#define	ETH_MACHWF3R_ESTDEP_0								(0x1u<<17)
#define	ETH_MACHWF3R_ESTSEL									(0x1u<<16)
#define	ETH_MACHWF3R_FRPES									(0x3u<<13)
#define	ETH_MACHWF3R_FRPES_0								(0x1u<<13)
#define	ETH_MACHWF3R_FRPBS									(0x3u<<11)
#define	ETH_MACHWF3R_FRPBS_0								(0x1u<<11)
#define	ETH_MACHWF3R_FRPSEL									(0x1u<<10)
#define	ETH_MACHWF3R_PDUPSEL								(0x1u<<9)
#define	ETH_MACHWF3R_DVLAN									(0x1u<<5)
#define	ETH_MACHWF3R_CBTISEL								(0x1u<<4)
#define	ETH_MACHWF3R_NRVF									(0x7u<<0)
#define	ETH_MACHWF3R_NRVF_0									(0x1u<<0)

#define	ETH_MACHWF3R_ASP_B_0X0								(0x0u<<28)
#define	ETH_MACHWF3R_ASP_B_0X1								(0x1u<<28)
#define	ETH_MACHWF3R_ASP_B_0X2								(0x2u<<28)
#define	ETH_MACHWF3R_ASP_B_0X3								(0x3u<<28)
#define	ETH_MACHWF3R_ESTWID_B_0X0							(0x0u<<20)
#define	ETH_MACHWF3R_ESTWID_B_0X1							(0x1u<<20)
#define	ETH_MACHWF3R_ESTWID_B_0X2							(0x2u<<20)
#define	ETH_MACHWF3R_ESTWID_B_0X3							(0x3u<<20)
#define	ETH_MACHWF3R_ESTDEP_B_0X0							(0x0u<<17)
#define	ETH_MACHWF3R_ESTDEP_B_0X1							(0x1u<<17)
#define	ETH_MACHWF3R_ESTDEP_B_0X2							(0x2u<<17)
#define	ETH_MACHWF3R_ESTDEP_B_0X3							(0x3u<<17)
#define	ETH_MACHWF3R_ESTDEP_B_0X4							(0x4u<<17)
#define	ETH_MACHWF3R_ESTDEP_B_0X5							(0x5u<<17)
#define	ETH_MACHWF3R_FRPES_B_0X0							(0x0u<<13)
#define	ETH_MACHWF3R_FRPES_B_0X1							(0x1u<<13)
#define	ETH_MACHWF3R_FRPES_B_0X2							(0x2u<<13)
#define	ETH_MACHWF3R_FRPBS_B_0X0							(0x0u<<11)
#define	ETH_MACHWF3R_FRPBS_B_0X1							(0x1u<<11)
#define	ETH_MACHWF3R_FRPBS_B_0X2							(0x2u<<11)
#define	ETH_MACHWF3R_NRVF_B_0X0								(0x0u<<0)
#define	ETH_MACHWF3R_NRVF_B_0X1								(0x1u<<0)
#define	ETH_MACHWF3R_NRVF_B_0X2								(0x2u<<0)
#define	ETH_MACHWF3R_NRVF_B_0X3								(0x3u<<0)
#define	ETH_MACHWF3R_NRVF_B_0X4								(0x4u<<0)
#define	ETH_MACHWF3R_NRVF_B_0X5								(0x5u<<0)

// MACMDIOAR Configuration

#define	ETH_MACMDIOAR_PSE									(0x1u<<27)
#define	ETH_MACMDIOAR_BTB									(0x1u<<26)
#define	ETH_MACMDIOAR_PA									(0x1Fu<<21)
#define	ETH_MACMDIOAR_PA_0									(0x1u<<21)
#define	ETH_MACMDIOAR_RDA									(0x1Fu<<16)
#define	ETH_MACMDIOAR_RDA_0									(0x1u<<16)
#define	ETH_MACMDIOAR_NTC									(0x7u<<12)
#define	ETH_MACMDIOAR_NTC_0									(0x1u<<12)
#define	ETH_MACMDIOAR_CR									(0xFu<<8)
#define	ETH_MACMDIOAR_CR_0									(0x1u<<8)
#define	ETH_MACMDIOAR_SKAP									(0x1u<<4)
#define	ETH_MACMDIOAR_GOC									(0x3u<<2)
#define	ETH_MACMDIOAR_GOC_0									(0x1u<<2)
#define	ETH_MACMDIOAR_C45E									(0x1u<<1)
#define	ETH_MACMDIOAR_GB									(0x1u<<0)

#define	ETH_MACMDIOAR_CR_B_0X0								(0x0u<<8)
#define	ETH_MACMDIOAR_CR_B_0X1								(0x1u<<8)
#define	ETH_MACMDIOAR_CR_B_0X2								(0x2u<<8)
#define	ETH_MACMDIOAR_CR_B_0X3								(0x3u<<8)
#define	ETH_MACMDIOAR_CR_B_0X4								(0x4u<<8)
#define	ETH_MACMDIOAR_CR_B_0X5								(0x5u<<8)
#define	ETH_MACMDIOAR_CR_B_0X6								(0x6u<<8)
#define	ETH_MACMDIOAR_CR_B_0X7								(0x7u<<8)
#define	ETH_MACMDIOAR_CR_B_0X8								(0x8u<<8)
#define	ETH_MACMDIOAR_CR_B_0X9								(0x9u<<8)
#define	ETH_MACMDIOAR_CR_B_0XA								(0xAu<<8)
#define	ETH_MACMDIOAR_CR_B_0XB								(0xBu<<8)
#define	ETH_MACMDIOAR_CR_B_0XC								(0xCu<<8)
#define	ETH_MACMDIOAR_CR_B_0XD								(0xDu<<8)
#define	ETH_MACMDIOAR_CR_B_0XE								(0xEu<<8)
#define	ETH_MACMDIOAR_CR_B_0XF								(0xFu<<8)
#define	ETH_MACMDIOAR_GOC_B_0X1								(0x1u<<2)
#define	ETH_MACMDIOAR_GOC_B_0X2								(0x2u<<2)
#define	ETH_MACMDIOAR_GOC_B_0X3								(0x3u<<2)

// MACMDIODR Configuration

#define	ETH_MACMDIODR_RA									(0xFFFFu<<16)
#define	ETH_MACMDIODR_RA_0									(0x1u<<16)
#define	ETH_MACMDIODR_GD									(0xFFFFu<<0)
#define	ETH_MACMDIODR_GD_0									(0x1u<<0)

// MACARPAR Configuration

#define	ETH_MACARPAR_ARPPA									(0xFFFFFFFFu<<0)
#define	ETH_MACARPAR_ARPPA_0								(0x1u<<0)

// MACCSRSWCR Configuration

#define	ETH_MACCSRSWCR_SEEN									(0x1u<<8)
#define	ETH_MACCSRSWCR_RCWE									(0x1u<<0)

// MACFPECSR Configuration

#define	ETH_MACFPECSR_TRSP									(0x1u<<19)
#define	ETH_MACFPECSR_TVER									(0x1u<<18)
#define	ETH_MACFPECSR_RRSP									(0x1u<<17)
#define	ETH_MACFPECSR_RVER									(0x1u<<16)
#define	ETH_MACFPECSR_SRSP									(0x1u<<2)
#define	ETH_MACFPECSR_SVER									(0x1u<<1)
#define	ETH_MACFPECSR_EFPE									(0x1u<<0)

// MACPRSTIMR Configuration

#define	ETH_MACPRSTIMR_MPTN									(0xFFFFFFFFu<<0)
#define	ETH_MACPRSTIMR_MPTN_0								(0x1u<<0)

// MACPRSTIMUR Configuration

#define	ETH_MACPRSTIMUR_MPTU								(0xFFFFFFFFu<<0)
#define	ETH_MACPRSTIMUR_MPTU_0								(0x1u<<0)

// MACA0HR Configuration

#define	ETH_MACA0HR_AE										(0x1u<<31)
#define	ETH_MACA0HR_DCS										(0x1u<<16)
#define	ETH_MACA0HR_ADDRHI									(0xFFFFu<<0)
#define	ETH_MACA0HR_ADDRHI_0								(0x1u<<0)

#define	ETH_MACA0HR_DCS_B_0X0								(0x0u<<16)
#define	ETH_MACA0HR_DCS_B_0X1								(0x1u<<16)

// MACA0LR Configuration

#define	ETH_MACA0LR_ADDRLO									(0xFFFFFFFFu<<0)
#define	ETH_MACA0LR_ADDRLO_0								(0x1u<<0)

// MACA1HR Configuration

#define	ETH_MACA1HR_AE										(0x1u<<31)
#define	ETH_MACA1HR_SA										(0x1u<<30)
#define	ETH_MACA1HR_MBC										(0x3Fu<<24)
#define	ETH_MACA1HR_MBC_0									(0x1u<<24)
#define	ETH_MACA1HR_DCS										(0x1u<<16)
#define	ETH_MACA1HR_ADDRHI									(0xFFFFu<<0)
#define	ETH_MACA1HR_ADDRHI_0								(0x1u<<0)

#define	ETH_MACA1HR_SA_B_0X0								(0x0u<<30)
#define	ETH_MACA1HR_SA_B_0X1								(0x1u<<30)
#define	ETH_MACA1HR_DCS_B_0X0								(0x0u<<16)
#define	ETH_MACA1HR_DCS_B_0X1								(0x1u<<16)

// MACA1LR Configuration

#define	ETH_MACA1LR_ADDRLO									(0xFFFFFFFFu<<0)
#define	ETH_MACA1LR_ADDRLO_0								(0x1u<<0)

// MACA2HR Configuration

#define	ETH_MACA2HR_AE										(0x1u<<31)
#define	ETH_MACA2HR_SA										(0x1u<<30)
#define	ETH_MACA2HR_MBC										(0x3Fu<<24)
#define	ETH_MACA2HR_MBC_0									(0x1u<<24)
#define	ETH_MACA2HR_DCS										(0x1u<<16)
#define	ETH_MACA2HR_ADDRHI									(0xFFFFu<<0)
#define	ETH_MACA2HR_ADDRHI_0								(0x1u<<0)

#define	ETH_MACA2HR_SA_B_0X0								(0x0u<<30)
#define	ETH_MACA2HR_SA_B_0X1								(0x1u<<30)
#define	ETH_MACA2HR_DCS_B_0X0								(0x0u<<16)
#define	ETH_MACA2HR_DCS_B_0X1								(0x1u<<16)

// MACA2LR Configuration

#define	ETH_MACA2LR_ADDRLO									(0xFFFFFFFFu<<0)
#define	ETH_MACA2LR_ADDRLO_0								(0x1u<<0)

// MACA3HR Configuration

#define	ETH_MACA3HR_AE										(0x1u<<31)
#define	ETH_MACA3HR_SA										(0x1u<<30)
#define	ETH_MACA3HR_MBC										(0x3Fu<<24)
#define	ETH_MACA3HR_MBC_0									(0x1u<<24)
#define	ETH_MACA3HR_DCS										(0x1u<<16)
#define	ETH_MACA3HR_ADDRHI									(0xFFFFu<<0)
#define	ETH_MACA3HR_ADDRHI_0								(0x1u<<0)

#define	ETH_MACA3HR_SA_B_0X0								(0x0u<<30)
#define	ETH_MACA3HR_SA_B_0X1								(0x1u<<30)
#define	ETH_MACA3HR_DCS_B_0X0								(0x0u<<16)
#define	ETH_MACA3HR_DCS_B_0X1								(0x1u<<16)

// MACA3LR Configuration

#define	ETH_MACA3LR_ADDRLO									(0xFFFFFFFFu<<0)
#define	ETH_MACA3LR_ADDRLO_0								(0x1u<<0)

// MMC_CONTROL Configuration

#define	ETH_MMC_CONTROL_UCDBC								(0x1u<<8)
#define	ETH_MMC_CONTROL_CNTPRSTLVL							(0x1u<<5)
#define	ETH_MMC_CONTROL_CNTPRST								(0x1u<<4)
#define	ETH_MMC_CONTROL_CNTFREEZ							(0x1u<<3)
#define	ETH_MMC_CONTROL_RSTONRD								(0x1u<<2)
#define	ETH_MMC_CONTROL_CNTSTOPRO							(0x1u<<1)
#define	ETH_MMC_CONTROL_CNTRST								(0x1u<<0)

// MMC_RX_INTERRUPT Configuration

#define	ETH_MMC_RX_INTERRUPT_RXLPITRCIS						(0x1u<<27)
#define	ETH_MMC_RX_INTERRUPT_RXLPIUSCIS						(0x1u<<26)
#define	ETH_MMC_RX_INTERRUPT_RXUCGPIS						(0x1u<<17)
#define	ETH_MMC_RX_INTERRUPT_RXALGNERPIS					(0x1u<<6)
#define	ETH_MMC_RX_INTERRUPT_RXCRCERPIS						(0x1u<<5)

// MMC_TX_INTERRUPT Configuration

#define	ETH_MMC_TX_INTERRUPT_TXLPITRCIS						(0x1u<<27)
#define	ETH_MMC_TX_INTERRUPT_TXLPIUSCIS						(0x1u<<26)
#define	ETH_MMC_TX_INTERRUPT_TXGPKTIS						(0x1u<<21)
#define	ETH_MMC_TX_INTERRUPT_TXMCOLGPIS						(0x1u<<15)
#define	ETH_MMC_TX_INTERRUPT_TXSCOLGPIS						(0x1u<<14)

// MMC_RX_INTERRUPT_MASK Configuration

#define	ETH_MMC_RX_INTERRUPT_MASK_RXLPITRCIM				(0x1u<<27)
#define	ETH_MMC_RX_INTERRUPT_MASK_RXLPIUSCIM				(0x1u<<26)
#define	ETH_MMC_RX_INTERRUPT_MASK_RXUCGPIM					(0x1u<<17)
#define	ETH_MMC_RX_INTERRUPT_MASK_RXALGNERPIM				(0x1u<<6)
#define	ETH_MMC_RX_INTERRUPT_MASK_RXCRCERPIM				(0x1u<<5)

// MMC_TX_INTERRUPT_MASK Configuration

#define	ETH_MMC_TX_INTERRUPT_MASK_TXLPITRCIM				(0x1u<<27)
#define	ETH_MMC_TX_INTERRUPT_MASK_TXLPIUSCIM				(0x1u<<26)
#define	ETH_MMC_TX_INTERRUPT_MASK_TXGPKTIM					(0x1u<<21)
#define	ETH_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM				(0x1u<<15)
#define	ETH_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM				(0x1u<<14)

// TX_SINGLE_COLLISION_GOOD_PACKETS Configuration

#define	ETH_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG		(0xFFFFFFFFu<<0)
#define	ETH_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_0	(0x1u<<0)

// TX_MULTIPLE_COLLISION_GOOD_PACKETS Configuration

#define	ETH_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG	(0xFFFFFFFFu<<0)
#define	ETH_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_0	(0x1u<<0)

// TX_PACKET_COUNT_GOOD Configuration

#define	ETH_TX_PACKET_COUNT_GOOD_TXPKTG						(0xFFFFFFFFu<<0)
#define	ETH_TX_PACKET_COUNT_GOOD_TXPKTG_0					(0x1u<<0)

// RX_CRC_ERROR_PACKETS Configuration

#define	ETH_RX_CRC_ERROR_PACKETS_RXCRCERR					(0xFFFFFFFFu<<0)
#define	ETH_RX_CRC_ERROR_PACKETS_RXCRCERR_0					(0x1u<<0)

// RX_ALIGNMENT_ERROR_PACKETS Configuration

#define	ETH_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR			(0xFFFFFFFFu<<0)
#define	ETH_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_0			(0x1u<<0)

// RX_UNICAST_PACKETS_GOOD Configuration

#define	ETH_RX_UNICAST_PACKETS_GOOD_RXUCASTG				(0xFFFFFFFFu<<0)
#define	ETH_RX_UNICAST_PACKETS_GOOD_RXUCASTG_0				(0x1u<<0)

// TX_LPI_USEC_CNTR Configuration

#define	ETH_TX_LPI_USEC_CNTR_TXLPIUSC						(0xFFFFFFFFu<<0)
#define	ETH_TX_LPI_USEC_CNTR_TXLPIUSC_0						(0x1u<<0)

// TX_LPI_TRAN_CNTR Configuration

#define	ETH_TX_LPI_TRAN_CNTR_TXLPITRC						(0xFFFFFFFFu<<0)
#define	ETH_TX_LPI_TRAN_CNTR_TXLPITRC_0						(0x1u<<0)

// RX_LPI_USEC_CNTR Configuration

#define	ETH_RX_LPI_USEC_CNTR_RXLPIUSC						(0xFFFFFFFFu<<0)
#define	ETH_RX_LPI_USEC_CNTR_RXLPIUSC_0						(0x1u<<0)

// RX_LPI_TRAN_CNTR Configuration

#define	ETH_RX_LPI_TRAN_CNTR_RXLPITRC						(0xFFFFFFFFu<<0)
#define	ETH_RX_LPI_TRAN_CNTR_RXLPITRC_0						(0x1u<<0)

// MMC_FPE_TX_ISR Configuration

#define	ETH_MMC_FPE_TX_ISR_HRCIS							(0x1u<<1)
#define	ETH_MMC_FPE_TX_ISR_FCIS								(0x1u<<0)

// MMC_FPE_TX_IMR Configuration

#define	ETH_MMC_FPE_TX_IMR_HRCIM							(0x1u<<1)
#define	ETH_MMC_FPE_TX_IMR_FCIM								(0x1u<<0)

// MMC_FPE_TX_FCR Configuration

#define	ETH_MMC_FPE_TX_FCR_TXFFC							(0xFFFFFFFFu<<0)
#define	ETH_MMC_FPE_TX_FCR_TXFFC_0							(0x1u<<0)

// MMC_TX_HRCR Configuration

#define	ETH_MMC_TX_HRCR_TXHRC								(0xFFFFFFFFu<<0)
#define	ETH_MMC_TX_HRCR_TXHRC_0								(0x1u<<0)

// MMC_FPE_RX_ISR Configuration

#define	ETH_MMC_FPE_RX_ISR_FCIS								(0x1u<<3)
#define	ETH_MMC_FPE_RX_ISR_PAOCIS							(0x1u<<2)
#define	ETH_MMC_FPE_RX_ISR_PSECIS							(0x1u<<1)
#define	ETH_MMC_FPE_RX_ISR_PAECIS							(0x1u<<0)

// MMC_FPE_RX_IMR Configuration

#define	ETH_MMC_FPE_RX_IMR_FCIM								(0x1u<<3)
#define	ETH_MMC_FPE_RX_IMR_PAOCIM							(0x1u<<2)
#define	ETH_MMC_FPE_RX_IMR_PSECIM							(0x1u<<1)
#define	ETH_MMC_FPE_RX_IMR_PAECIM							(0x1u<<0)

// RX_PACKET_ASM_ERR Configuration

#define	ETH_RX_PACKET_ASM_ERR_PAEC							(0xFFFFFFFFu<<0)
#define	ETH_RX_PACKET_ASM_ERR_PAEC_0						(0x1u<<0)

// RX_PACKET_SMD_ERR Configuration

#define	ETH_RX_PACKET_SMD_ERR_PSEC							(0xFFFFFFFFu<<0)
#define	ETH_RX_PACKET_SMD_ERR_PSEC_0						(0x1u<<0)

// RX_PACKET_ASM_OKR Configuration

#define	ETH_RX_PACKET_ASM_OKR_PAOC							(0xFFFFFFFFu<<0)
#define	ETH_RX_PACKET_ASM_OKR_PAOC_0						(0x1u<<0)

// RX_FPE_FRAG_CR Configuration

#define	ETH_RX_FPE_FRAG_CR_FFC								(0xFFFFFFFFu<<0)
#define	ETH_RX_FPE_FRAG_CR_FFC_0							(0x1u<<0)

// MACL3L4C0R Configuration

#define	ETH_MACL3L4C0R_DMCHEN0								(0x1u<<28)
#define	ETH_MACL3L4C0R_DMCHN0								(0x1u<<24)
#define	ETH_MACL3L4C0R_L4DPIM0								(0x1u<<21)
#define	ETH_MACL3L4C0R_L4DPM0								(0x1u<<20)
#define	ETH_MACL3L4C0R_L4SPIM0								(0x1u<<19)
#define	ETH_MACL3L4C0R_L4SPM0								(0x1u<<18)
#define	ETH_MACL3L4C0R_L4PEN0								(0x1u<<16)
#define	ETH_MACL3L4C0R_L3HDBM0								(0x1Fu<<11)
#define	ETH_MACL3L4C0R_L3HDBM0_0							(0x1u<<11)
#define	ETH_MACL3L4C0R_L3HSBM0								(0x1Fu<<6)
#define	ETH_MACL3L4C0R_L3HSBM0_0							(0x1u<<6)
#define	ETH_MACL3L4C0R_L3DAIM0								(0x1u<<5)
#define	ETH_MACL3L4C0R_L3DAM0								(0x1u<<4)
#define	ETH_MACL3L4C0R_L3SAIM0								(0x1u<<3)
#define	ETH_MACL3L4C0R_L3SAM0								(0x1u<<2)
#define	ETH_MACL3L4C0R_L3PEN0								(0x1u<<0)

#define	ETH_MACL3L4C0R_DMCHN0_B_0X0							(0x0u<<24)
#define	ETH_MACL3L4C0R_DMCHN0_B_0X1							(0x1u<<24)
#define	ETH_MACL3L4C0R_L3HDBM0_B_0X0_IPV4_PACKETS			(0x0u<<11)
#define	ETH_MACL3L4C0R_L3HDBM0_B_0X1_IPV4_PACKETS			(0x1u<<11)
#define	ETH_MACL3L4C0R_L3HSBM0_B_0X0_IPV4_PACKETS			(0x0u<<6)
#define	ETH_MACL3L4C0R_L3HSBM0_B_0X1_IPV4_PACKETS			(0x1u<<6)

// MACL4A0R Configuration

#define	ETH_MACL4A0R_L4DP0									(0xFFFFu<<16)
#define	ETH_MACL4A0R_L4DP0_0								(0x1u<<16)
#define	ETH_MACL4A0R_L4SP0									(0xFFFFu<<0)
#define	ETH_MACL4A0R_L4SP0_0								(0x1u<<0)

// MACL3A00R Configuration

#define	ETH_MACL3A00R_L3A00									(0xFFFFFFFFu<<0)
#define	ETH_MACL3A00R_L3A00_0								(0x1u<<0)

// MACL3A10R Configuration

#define	ETH_MACL3A10R_L3A10									(0xFFFFFFFFu<<0)
#define	ETH_MACL3A10R_L3A10_0								(0x1u<<0)

// MACL3A20R Configuration

#define	ETH_MACL3A20R_L3A20									(0xFFFFFFFFu<<0)
#define	ETH_MACL3A20R_L3A20_0								(0x1u<<0)

// MACL3A30R Configuration

#define	ETH_MACL3A30R_L3A30									(0xFFFFFFFFu<<0)
#define	ETH_MACL3A30R_L3A30_0								(0x1u<<0)

// MACL3L4C1R Configuration

#define	ETH_MACL3L4C1R_DMCHEN1								(0x1u<<28)
#define	ETH_MACL3L4C1R_DMCHN1								(0x1u<<24)
#define	ETH_MACL3L4C1R_L4DPIM1								(0x1u<<21)
#define	ETH_MACL3L4C1R_L4DPM1								(0x1u<<20)
#define	ETH_MACL3L4C1R_L4SPIM1								(0x1u<<19)
#define	ETH_MACL3L4C1R_L4SPM1								(0x1u<<18)
#define	ETH_MACL3L4C1R_L4PEN1								(0x1u<<16)
#define	ETH_MACL3L4C1R_L3HDBM1								(0x1Fu<<11)
#define	ETH_MACL3L4C1R_L3HDBM1_0							(0x1u<<11)
#define	ETH_MACL3L4C1R_L3HSBM1								(0x1Fu<<6)
#define	ETH_MACL3L4C1R_L3HSBM1_0							(0x1u<<6)
#define	ETH_MACL3L4C1R_L3DAIM1								(0x1u<<5)
#define	ETH_MACL3L4C1R_L3DAM1								(0x1u<<4)
#define	ETH_MACL3L4C1R_L3SAIM1								(0x1u<<3)
#define	ETH_MACL3L4C1R_L3SAM1								(0x1u<<2)
#define	ETH_MACL3L4C1R_L3PEN1								(0x1u<<0)

#define	ETH_MACL3L4C1R_L3HDBM1_B_0X0_IPV4_PACKETS			(0x0u<<11)
#define	ETH_MACL3L4C1R_L3HDBM1_B_0X1_IPV4_PACKETS			(0x1u<<11)
#define	ETH_MACL3L4C1R_L3HSBM1_B_0X0_IPV4_PACKETS			(0x0u<<6)
#define	ETH_MACL3L4C1R_L3HSBM1_B_0X1_IPV4_PACKETS			(0x1u<<6)

// MACL4A1R Configuration

#define	ETH_MACL4A1R_L4DP1									(0xFFFFu<<16)
#define	ETH_MACL4A1R_L4DP1_0								(0x1u<<16)
#define	ETH_MACL4A1R_L4SP1									(0xFFFFu<<0)
#define	ETH_MACL4A1R_L4SP1_0								(0x1u<<0)

// MACL3A01R Configuration

#define	ETH_MACL3A01R_L3A01									(0xFFFFFFFFu<<0)
#define	ETH_MACL3A01R_L3A01_0								(0x1u<<0)

// MACL3A11R Configuration

#define	ETH_MACL3A11R_L3A11									(0xFFFFFFFFu<<0)
#define	ETH_MACL3A11R_L3A11_0								(0x1u<<0)

// MACL3A21R Configuration

#define	ETH_MACL3A21R_L3A21									(0xFFFFFFFFu<<0)
#define	ETH_MACL3A21R_L3A21_0								(0x1u<<0)

// MACL3A31R Configuration

#define	ETH_MACL3A31R_L3A31									(0xFFFFFFFFu<<0)
#define	ETH_MACL3A31R_L3A31_0								(0x1u<<0)

// MAC_IACR Configuration

#define	ETH_MAC_IACR_MSEL									(0xFu<<16)
#define	ETH_MAC_IACR_MSEL_0									(0x1u<<16)
#define	ETH_MAC_IACR_AOFF									(0xFFu<<8)
#define	ETH_MAC_IACR_AOFF_0									(0x1u<<8)
#define	ETH_MAC_IACR_AUTO									(0x1u<<5)
#define	ETH_MAC_IACR_COM									(0x1u<<1)
#define	ETH_MAC_IACR_OB										(0x1u<<0)

#define	ETH_MAC_IACR_MSEL_B_0X0								(0x0u<<16)
#define	ETH_MAC_IACR_AOFF_B_0X0								(0x0u<<8)
#define	ETH_MAC_IACR_AOFF_B_0X1								(0x1u<<8)
#define	ETH_MAC_IACR_AOFF_B_0X7								(0x7u<<8)
#define	ETH_MAC_IACR_AUTO_B_0X1								(0x1u<<5)
#define	ETH_MAC_IACR_AUTO_B_0X0								(0x0u<<5)
#define	ETH_MAC_IACR_COM_B_0X1								(0x1u<<1)
#define	ETH_MAC_IACR_COM_B_0X0								(0x0u<<1)

// MAC_TMRQR Configuration

#define	ETH_MAC_TMRQR_PFEX									(0x1u<<20)
#define	ETH_MAC_TMRQR_TMRQ									(0x7u<<16)
#define	ETH_MAC_TMRQR_TMRQ_0								(0x1u<<16)
#define	ETH_MAC_TMRQR_TYP									(0xFFFFu<<0)
#define	ETH_MAC_TMRQR_TYP_0									(0x1u<<0)

#define	ETH_MAC_TMRQR_PFEX_B_0X0							(0x0u<<20)
#define	ETH_MAC_TMRQR_PFEX_B_0X1							(0x1u<<20)

// MACTSCR Configuration

#define	ETH_MACTSCR_AV8021ASMEN								(0x1u<<28)
#define	ETH_MACTSCR_TXTSSTSM								(0x1u<<24)
#define	ETH_MACTSCR_ESTI									(0x1u<<20)
#define	ETH_MACTSCR_TSENMACADDR								(0x1u<<18)
#define	ETH_MACTSCR_SNAPTYPSEL								(0x3u<<16)
#define	ETH_MACTSCR_SNAPTYPSEL_0							(0x1u<<16)
#define	ETH_MACTSCR_TSMSTRENA								(0x1u<<15)
#define	ETH_MACTSCR_TSEVNTENA								(0x1u<<14)
#define	ETH_MACTSCR_TSIPV4ENA								(0x1u<<13)
#define	ETH_MACTSCR_TSIPV6ENA								(0x1u<<12)
#define	ETH_MACTSCR_TSIPENA									(0x1u<<11)
#define	ETH_MACTSCR_TSVER2ENA								(0x1u<<10)
#define	ETH_MACTSCR_TSCTRLSSR								(0x1u<<9)
#define	ETH_MACTSCR_TSENALL									(0x1u<<8)
#define	ETH_MACTSCR_PTGE									(0x1u<<6)
#define	ETH_MACTSCR_TSADDREG								(0x1u<<5)
#define	ETH_MACTSCR_TSUPDT									(0x1u<<3)
#define	ETH_MACTSCR_TSINIT									(0x1u<<2)
#define	ETH_MACTSCR_TSCFUPDT								(0x1u<<1)
#define	ETH_MACTSCR_TSENA									(0x1u<<0)

// MACSSIR Configuration

#define	ETH_MACSSIR_SSINC									(0xFFu<<16)
#define	ETH_MACSSIR_SSINC_0									(0x1u<<16)

// MACSTSR Configuration

#define	ETH_MACSTSR_TSS										(0xFFFFFFFFu<<0)
#define	ETH_MACSTSR_TSS_0									(0x1u<<0)

// MACSTNR Configuration

#define	ETH_MACSTNR_TSSS									(0x7FFFFFFFu<<0)
#define	ETH_MACSTNR_TSSS_0									(0x1u<<0)

// MACSTSUR Configuration

#define	ETH_MACSTSUR_TSS									(0xFFFFFFFFu<<0)
#define	ETH_MACSTSUR_TSS_0									(0x1u<<0)

// MACSTNUR Configuration

#define	ETH_MACSTNUR_ADDSUB									(0x1u<<31)
#define	ETH_MACSTNUR_TSSS									(0x7FFFFFFFu<<0)
#define	ETH_MACSTNUR_TSSS_0									(0x1u<<0)

// MACTSAR Configuration

#define	ETH_MACTSAR_TSAR									(0xFFFFFFFFu<<0)
#define	ETH_MACTSAR_TSAR_0									(0x1u<<0)

// MACTSSR Configuration

#define	ETH_MACTSSR_ATSNS									(0x1Fu<<25)
#define	ETH_MACTSSR_ATSNS_0									(0x1u<<25)
#define	ETH_MACTSSR_ATSSTM									(0x1u<<24)
#define	ETH_MACTSSR_ATSSTN									(0xFu<<16)
#define	ETH_MACTSSR_ATSSTN_0								(0x1u<<16)
#define	ETH_MACTSSR_TXTSSIS									(0x1u<<15)
#define	ETH_MACTSSR_TSTRGTERR1								(0x1u<<5)
#define	ETH_MACTSSR_TSTARGT1								(0x1u<<4)
#define	ETH_MACTSSR_TSTRGTERR0								(0x1u<<3)
#define	ETH_MACTSSR_AUXTSTRIG								(0x1u<<2)
#define	ETH_MACTSSR_TSTARGT0								(0x1u<<1)
#define	ETH_MACTSSR_TSSOVF									(0x1u<<0)

// MACTXTSSNR Configuration

#define	ETH_MACTXTSSNR_TXTSSMIS								(0x1u<<31)
#define	ETH_MACTXTSSNR_TXTSSLO								(0x7FFFFFFFu<<0)
#define	ETH_MACTXTSSNR_TXTSSLO_0							(0x1u<<0)

// MACTXTSSSR Configuration

#define	ETH_MACTXTSSSR_TXTSSHI								(0xFFFFFFFFu<<0)
#define	ETH_MACTXTSSSR_TXTSSHI_0							(0x1u<<0)

// MACACR Configuration

#define	ETH_MACACR_ATSEN3									(0x1u<<7)
#define	ETH_MACACR_ATSEN2									(0x1u<<6)
#define	ETH_MACACR_ATSEN1									(0x1u<<5)
#define	ETH_MACACR_ATSEN0									(0x1u<<4)
#define	ETH_MACACR_ATSFC									(0x1u<<0)

// MACATSNR Configuration

#define	ETH_MACATSNR_AUXTSLO								(0x7FFFFFFFu<<0)
#define	ETH_MACATSNR_AUXTSLO_0								(0x1u<<0)

// MACATSSR Configuration

#define	ETH_MACATSSR_AUXTSHI								(0xFFFFFFFFu<<0)
#define	ETH_MACATSSR_AUXTSHI_0								(0x1u<<0)

// MACTSIACR Configuration

#define	ETH_MACTSIACR_OSTIAC								(0xFFFFFFFFu<<0)
#define	ETH_MACTSIACR_OSTIAC_0								(0x1u<<0)

// MACTSEACR Configuration

#define	ETH_MACTSEACR_OSTEAC								(0xFFFFFFFFu<<0)
#define	ETH_MACTSEACR_OSTEAC_0								(0x1u<<0)

// MACTSICNR Configuration

#define	ETH_MACTSICNR_TSIC									(0xFFFFFFFFu<<0)
#define	ETH_MACTSICNR_TSIC_0								(0x1u<<0)

// MACTSECNR Configuration

#define	ETH_MACTSECNR_TSEC									(0xFFFFFFFFu<<0)
#define	ETH_MACTSECNR_TSEC_0								(0x1u<<0)

// MACTSILR Configuration

#define	ETH_MACTSILR_ITLNS									(0xFFFu<<16)
#define	ETH_MACTSILR_ITLNS_0								(0x1u<<16)
#define	ETH_MACTSILR_ITLSNS									(0xFFu<<8)
#define	ETH_MACTSILR_ITLSNS_0								(0x1u<<8)

// MACTSELR Configuration

#define	ETH_MACTSELR_ETLNS									(0xFFFu<<16)
#define	ETH_MACTSELR_ETLNS_0								(0x1u<<16)
#define	ETH_MACTSELR_ETLSNS									(0xFFu<<8)
#define	ETH_MACTSELR_ETLSNS_0								(0x1u<<8)

// MACPPSCR Configuration

#define	ETH_MACPPSCR_TIMESEL								(0x1u<<28)
#define	ETH_MACPPSCR_MCGREN0								(0x1u<<7)
#define	ETH_MACPPSCR_TRGTMODSEL0							(0x3u<<5)
#define	ETH_MACPPSCR_TRGTMODSEL0_0							(0x1u<<5)
#define	ETH_MACPPSCR_PPSEN0									(0x1u<<4)
#define	ETH_MACPPSCR_PPSCTRL								(0xFu<<0)
#define	ETH_MACPPSCR_PPSCTRL_0								(0x1u<<0)

#define	ETH_MACPPSCR_MCGREN0_B_0X0							(0x0u<<7)
#define	ETH_MACPPSCR_MCGREN0_B_0X1							(0x1u<<7)
#define	ETH_MACPPSCR_TRGTMODSEL0_B_0X0						(0x0u<<5)
#define	ETH_MACPPSCR_TRGTMODSEL0_B_0X1						(0x1u<<5)
#define	ETH_MACPPSCR_TRGTMODSEL0_B_0X2						(0x2u<<5)
#define	ETH_MACPPSCR_TRGTMODSEL0_B_0X3						(0x3u<<5)
#define	ETH_MACPPSCR_PPSCTRL_B_0X1							(0x1u<<0)
#define	ETH_MACPPSCR_PPSCTRL_B_0X2							(0x2u<<0)
#define	ETH_MACPPSCR_PPSCTRL_B_0X3							(0x3u<<0)
#define	ETH_MACPPSCR_PPSCTRL_B_0X4							(0x4u<<0)
#define	ETH_MACPPSCR_PPSCTRL_B_0XF							(0xFu<<0)

// MACPPSCR_ALTERNATE Configuration

#define	ETH_MACPPSCR_ALTERNATE_TIMESEL						(0x1u<<28)
#define	ETH_MACPPSCR_ALTERNATE_MCGREN1						(0x1u<<15)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1					(0x3u<<13)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1_0				(0x1u<<13)
#define	ETH_MACPPSCR_ALTERNATE_PPSCMD1						(0xFu<<8)
#define	ETH_MACPPSCR_ALTERNATE_PPSCMD1_0					(0x1u<<8)
#define	ETH_MACPPSCR_ALTERNATE_MCGREN0						(0x1u<<7)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0					(0x3u<<5)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0_0				(0x1u<<5)
#define	ETH_MACPPSCR_ALTERNATE_PPSEN0						(0x1u<<4)
#define	ETH_MACPPSCR_ALTERNATE_PPSCMD						(0xFu<<0)
#define	ETH_MACPPSCR_ALTERNATE_PPSCMD_0						(0x1u<<0)

#define	ETH_MACPPSCR_ALTERNATE_MCGREN1_B_0X0				(0x0u<<15)
#define	ETH_MACPPSCR_ALTERNATE_MCGREN1_B_0X1				(0x1u<<15)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1_B_0X0			(0x0u<<13)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1_B_0X1			(0x1u<<13)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1_B_0X2			(0x2u<<13)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1_B_0X3			(0x3u<<13)
#define	ETH_MACPPSCR_ALTERNATE_MCGREN0_B_0X0				(0x0u<<7)
#define	ETH_MACPPSCR_ALTERNATE_MCGREN0_B_0X1				(0x1u<<7)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0_B_0X0			(0x0u<<5)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0_B_0X1			(0x1u<<5)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0_B_0X2			(0x2u<<5)
#define	ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0_B_0X3			(0x3u<<5)
#define	ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X0					(0x0u<<0)
#define	ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X1					(0x1u<<0)
#define	ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X2					(0x2u<<0)
#define	ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X3					(0x3u<<0)
#define	ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X4					(0x4u<<0)
#define	ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X5					(0x5u<<0)
#define	ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X6					(0x6u<<0)

// MACPPSTTS0R Configuration

#define	ETH_MACPPSTTS0R_TSTRH0								(0xFFFFFFFFu<<0)
#define	ETH_MACPPSTTS0R_TSTRH0_0							(0x1u<<0)

// MACPPSTTN0R Configuration

#define	ETH_MACPPSTTN0R_TRGTBUSY0							(0x1u<<31)
#define	ETH_MACPPSTTN0R_TTSL0								(0x7FFFFFFFu<<0)
#define	ETH_MACPPSTTN0R_TTSL0_0								(0x1u<<0)

// MACPPSI0R Configuration

#define	ETH_MACPPSI0R_PPSINT0								(0xFFFFFFFFu<<0)
#define	ETH_MACPPSI0R_PPSINT0_0								(0x1u<<0)

// MACPPSW0R Configuration

#define	ETH_MACPPSW0R_PPSWIDTH0								(0xFFFFFFFFu<<0)
#define	ETH_MACPPSW0R_PPSWIDTH0_0							(0x1u<<0)

// MACPPSTTS1R Configuration

#define	ETH_MACPPSTTS1R_TSTRH0								(0xFFFFFFFFu<<0)
#define	ETH_MACPPSTTS1R_TSTRH0_0							(0x1u<<0)

// MACPPSTTN1R Configuration

#define	ETH_MACPPSTTN1R_TRGTBUSY0							(0x1u<<31)
#define	ETH_MACPPSTTN1R_TTSL0								(0x7FFFFFFFu<<0)
#define	ETH_MACPPSTTN1R_TTSL0_0								(0x1u<<0)

// MACPPSI1R Configuration

#define	ETH_MACPPSI1R_PPSINT0								(0xFFFFFFFFu<<0)
#define	ETH_MACPPSI1R_PPSINT0_0								(0x1u<<0)

// MACPPSW1R Configuration

#define	ETH_MACPPSW1R_PPSWIDTH0								(0xFFFFFFFFu<<0)
#define	ETH_MACPPSW1R_PPSWIDTH0_0							(0x1u<<0)

// MACPOCR Configuration

#define	ETH_MACPOCR_DN										(0xFFu<<8)
#define	ETH_MACPOCR_DN_0									(0x1u<<8)
#define	ETH_MACPOCR_PDRDIS									(0x1u<<7)
#define	ETH_MACPOCR_DRRDIS									(0x1u<<6)
#define	ETH_MACPOCR_APDREQTRIG								(0x1u<<5)
#define	ETH_MACPOCR_ASYNCTRIG								(0x1u<<4)
#define	ETH_MACPOCR_APDREQEN								(0x1u<<2)
#define	ETH_MACPOCR_ASYNCEN									(0x1u<<1)
#define	ETH_MACPOCR_PTOEN									(0x1u<<0)

// MACSPI0R Configuration

#define	ETH_MACSPI0R_SPI0									(0xFFFFFFFFu<<0)
#define	ETH_MACSPI0R_SPI0_0									(0x1u<<0)

// MACSPI1R Configuration

#define	ETH_MACSPI1R_SPI1									(0xFFFFFFFFu<<0)
#define	ETH_MACSPI1R_SPI1_0									(0x1u<<0)

// MACSPI2R Configuration

#define	ETH_MACSPI2R_SPI2									(0xFFFFu<<0)
#define	ETH_MACSPI2R_SPI2_0									(0x1u<<0)

// MACLMIR Configuration

#define	ETH_MACLMIR_LMPDRI									(0xFFu<<24)
#define	ETH_MACLMIR_LMPDRI_0								(0x1u<<24)
#define	ETH_MACLMIR_DRSYNCR									(0x7u<<8)
#define	ETH_MACLMIR_DRSYNCR_0								(0x1u<<8)
#define	ETH_MACLMIR_LSI										(0xFFu<<0)
#define	ETH_MACLMIR_LSI_0									(0x1u<<0)

#define	ETH_MACLMIR_DRSYNCR_B_0X0							(0x0u<<8)
#define	ETH_MACLMIR_DRSYNCR_B_0X1							(0x1u<<8)

// MTLOMR Configuration

#define	ETH_MTLOMR_CNTCLR									(0x1u<<9)
#define	ETH_MTLOMR_CNTPRST									(0x1u<<8)
#define	ETH_MTLOMR_SCHALG									(0x3u<<5)
#define	ETH_MTLOMR_SCHALG_0									(0x1u<<5)
#define	ETH_MTLOMR_RAA										(0x1u<<2)
#define	ETH_MTLOMR_DTXSTS									(0x1u<<1)

#define	ETH_MTLOMR_SCHALG_B_0X0								(0x0u<<5)
#define	ETH_MTLOMR_SCHALG_B_0X3								(0x3u<<5)
#define	ETH_MTLOMR_RAA_B_0X0								(0x0u<<2)
#define	ETH_MTLOMR_RAA_B_0X1								(0x1u<<2)

// MTLISR Configuration

#define	ETH_MTLISR_ESTIS									(0x1u<<18)
#define	ETH_MTLISR_Q1IS										(0x1u<<1)
#define	ETH_MTLISR_Q0IS										(0x1u<<0)

// MTLRXQDMAMR Configuration

#define	ETH_MTLRXQDMAMR_Q1DDMACH							(0x1u<<12)
#define	ETH_MTLRXQDMAMR_Q1MDMACH							(0x1u<<8)
#define	ETH_MTLRXQDMAMR_Q0DDMACH							(0x1u<<4)
#define	ETH_MTLRXQDMAMR_Q0MDMACH							(0x1u<<0)

#define	ETH_MTLRXQDMAMR_Q1MDMACH_B_0X0						(0x0u<<8)
#define	ETH_MTLRXQDMAMR_Q1MDMACH_B_0X1						(0x1u<<8)
#define	ETH_MTLRXQDMAMR_Q0MDMACH_B_0X0						(0x0u<<0)
#define	ETH_MTLRXQDMAMR_Q0MDMACH_B_0X1						(0x1u<<0)

// MTLTBSCR Configuration

#define	ETH_MTLTBSCR_LEOS									(0xFFFFFFu<<8)
#define	ETH_MTLTBSCR_LEOS_0									(0x1u<<8)
#define	ETH_MTLTBSCR_LEGOS									(0x7u<<4)
#define	ETH_MTLTBSCR_LEGOS_0								(0x1u<<4)
#define	ETH_MTLTBSCR_LEOV									(0x1u<<1)
#define	ETH_MTLTBSCR_ESTM									(0x1u<<0)

#define	ETH_MTLTBSCR_LEOV_B_0X0								(0x0u<<1)
#define	ETH_MTLTBSCR_LEOV_B_0X1								(0x1u<<1)
#define	ETH_MTLTBSCR_ESTM_B_0X0								(0x0u<<0)
#define	ETH_MTLTBSCR_ESTM_B_0X1								(0x1u<<0)

// MTLESTCR Configuration

#define	ETH_MTLESTCR_PTOV									(0xFFu<<24)
#define	ETH_MTLESTCR_PTOV_0									(0x1u<<24)
#define	ETH_MTLESTCR_CTOV									(0xFFFu<<12)
#define	ETH_MTLESTCR_CTOV_0									(0x1u<<12)
#define	ETH_MTLESTCR_TILS									(0x7u<<8)
#define	ETH_MTLESTCR_TILS_0									(0x1u<<8)
#define	ETH_MTLESTCR_LCSE									(0x3u<<6)
#define	ETH_MTLESTCR_LCSE_0									(0x1u<<6)
#define	ETH_MTLESTCR_DFBS									(0x1u<<5)
#define	ETH_MTLESTCR_DDBF									(0x1u<<4)
#define	ETH_MTLESTCR_SSWL									(0x1u<<1)
#define	ETH_MTLESTCR_EEST									(0x1u<<0)

#define	ETH_MTLESTCR_TILS_B_0X0								(0x0u<<8)
#define	ETH_MTLESTCR_TILS_B_0X1								(0x1u<<8)
#define	ETH_MTLESTCR_TILS_B_0X2								(0x2u<<8)
#define	ETH_MTLESTCR_TILS_B_0X4								(0x4u<<8)
#define	ETH_MTLESTCR_LCSE_B_0X0								(0x0u<<6)
#define	ETH_MTLESTCR_LCSE_B_0X1								(0x1u<<6)
#define	ETH_MTLESTCR_LCSE_B_0X2								(0x2u<<6)
#define	ETH_MTLESTCR_LCSE_B_0X3								(0x3u<<6)
#define	ETH_MTLESTCR_DFBS_B_0X0								(0x0u<<5)
#define	ETH_MTLESTCR_DFBS_B_0X1								(0x1u<<5)
#define	ETH_MTLESTCR_DDBF_B_0X0								(0x0u<<4)
#define	ETH_MTLESTCR_DDBF_B_0X1								(0x1u<<4)
#define	ETH_MTLESTCR_EEST_B_0X0								(0x0u<<0)
#define	ETH_MTLESTCR_EEST_B_0X1								(0x1u<<0)

// MTLESTECR Configuration

#define	ETH_MTLESTECR_OVHD									(0x3Fu<<0)
#define	ETH_MTLESTECR_OVHD_0								(0x1u<<0)

// MTLESTSR Configuration

#define	ETH_MTLESTSR_CGSN									(0xFu<<16)
#define	ETH_MTLESTSR_CGSN_0									(0x1u<<16)
#define	ETH_MTLESTSR_BTRL									(0xFFu<<8)
#define	ETH_MTLESTSR_BTRL_0									(0x1u<<8)
#define	ETH_MTLESTSR_SWOL									(0x1u<<7)
#define	ETH_MTLESTSR_CGCE									(0x1u<<4)
#define	ETH_MTLESTSR_HLBS									(0x1u<<3)
#define	ETH_MTLESTSR_HLBF									(0x1u<<2)
#define	ETH_MTLESTSR_BTRE									(0x1u<<1)
#define	ETH_MTLESTSR_SWLC									(0x1u<<0)

#define	ETH_MTLESTSR_SWOL_B_0X0								(0x0u<<7)
#define	ETH_MTLESTSR_SWOL_B_0X1								(0x1u<<7)
#define	ETH_MTLESTSR_CGCE_B_0X0								(0x0u<<4)
#define	ETH_MTLESTSR_CGCE_B_0X1								(0x1u<<4)
#define	ETH_MTLESTSR_HLBS_B_0X0								(0x0u<<3)
#define	ETH_MTLESTSR_HLBS_B_0X1								(0x1u<<3)
#define	ETH_MTLESTSR_BTRE_B_0X0								(0x0u<<1)
#define	ETH_MTLESTSR_BTRE_B_0X1								(0x1u<<1)
#define	ETH_MTLESTSR_SWLC_B_0X0								(0x0u<<0)
#define	ETH_MTLESTSR_SWLC_B_0X1								(0x1u<<0)

// MTLESTSCHER Configuration

#define	ETH_MTLESTSCHER_SEQN								(0x3u<<0)
#define	ETH_MTLESTSCHER_SEQN_0								(0x1u<<0)

// MTLESTFSER Configuration

#define	ETH_MTLESTFSER_FEQN									(0x3u<<0)
#define	ETH_MTLESTFSER_FEQN_0								(0x1u<<0)

// MTLESTFSCR Configuration

#define	ETH_MTLESTFSCR_HBFQ									(0x1u<<16)
#define	ETH_MTLESTFSCR_HBFS									(0x7FFFu<<0)
#define	ETH_MTLESTFSCR_HBFS_0								(0x1u<<0)

// MTLESTIER Configuration

#define	ETH_MTLESTIER_CGCE									(0x1u<<4)
#define	ETH_MTLESTIER_IEHS									(0x1u<<3)
#define	ETH_MTLESTIER_IEHF									(0x1u<<2)
#define	ETH_MTLESTIER_IEBE									(0x1u<<1)
#define	ETH_MTLESTIER_IECC									(0x1u<<0)

// MTLESTGCLCR Configuration

#define	ETH_MTLESTGCLCR_ADDR								(0x3Fu<<8)
#define	ETH_MTLESTGCLCR_ADDR_0								(0x1u<<8)
#define	ETH_MTLESTGCLCR_DBGB								(0x1u<<5)
#define	ETH_MTLESTGCLCR_DBGM								(0x1u<<4)
#define	ETH_MTLESTGCLCR_GCRR								(0x1u<<2)
#define	ETH_MTLESTGCLCR_R1W0								(0x1u<<1)
#define	ETH_MTLESTGCLCR_SRWO								(0x1u<<0)

#define	ETH_MTLESTGCLCR_ADDR_B_0X0_GCRR__EQUAL_1			(0x0u<<8)
#define	ETH_MTLESTGCLCR_ADDR_B_0X1_GCRR__EQUAL_1			(0x1u<<8)
#define	ETH_MTLESTGCLCR_ADDR_B_0X2_GCRR__EQUAL_1			(0x2u<<8)
#define	ETH_MTLESTGCLCR_ADDR_B_0X3_GCRR__EQUAL_1			(0x3u<<8)
#define	ETH_MTLESTGCLCR_ADDR_B_0X4_GCRR__EQUAL_1			(0x4u<<8)
#define	ETH_MTLESTGCLCR_ADDR_B_0X5_GCRR__EQUAL_1			(0x5u<<8)
#define	ETH_MTLESTGCLCR_DBGB_B_0X0							(0x0u<<5)
#define	ETH_MTLESTGCLCR_DBGB_B_0X1							(0x1u<<5)
#define	ETH_MTLESTGCLCR_R1W0_B_0X1							(0x1u<<1)
#define	ETH_MTLESTGCLCR_R1W0_B_0X0							(0x0u<<1)
#define	ETH_MTLESTGCLCR_SRWO_B_0X1							(0x1u<<0)

// MTLESTGCLDR Configuration

#define	ETH_MTLESTGCLDR_GCD									(0xFFFFFFFFu<<0)
#define	ETH_MTLESTGCLDR_GCD_0								(0x1u<<0)

// MTLFPECSR Configuration

#define	ETH_MTLFPECSR_HRS									(0x1u<<28)
#define	ETH_MTLFPECSR_PEC									(0x3u<<8)
#define	ETH_MTLFPECSR_PEC_0									(0x1u<<8)
#define	ETH_MTLFPECSR_AFSZ									(0x3u<<0)
#define	ETH_MTLFPECSR_AFSZ_0								(0x1u<<0)

#define	ETH_MTLFPECSR_HRS_B_0X1								(0x1u<<28)
#define	ETH_MTLFPECSR_HRS_B_0X0								(0x0u<<28)

// MTLFPEAR Configuration

#define	ETH_MTLFPEAR_RADV									(0xFFFFu<<16)
#define	ETH_MTLFPEAR_RADV_0									(0x1u<<16)
#define	ETH_MTLFPEAR_HADV									(0xFFFFu<<0)
#define	ETH_MTLFPEAR_HADV_0									(0x1u<<0)

// MTLTXQ0OMR Configuration

#define	ETH_MTLTXQ0OMR_TQS									(0xFu<<16)
#define	ETH_MTLTXQ0OMR_TQS_0								(0x1u<<16)
#define	ETH_MTLTXQ0OMR_TTC									(0x7u<<4)
#define	ETH_MTLTXQ0OMR_TTC_0								(0x1u<<4)
#define	ETH_MTLTXQ0OMR_TXQEN								(0x3u<<2)
#define	ETH_MTLTXQ0OMR_TXQEN_0								(0x1u<<2)
#define	ETH_MTLTXQ0OMR_TSF									(0x1u<<1)
#define	ETH_MTLTXQ0OMR_FTQ									(0x1u<<0)

#define	ETH_MTLTXQ0OMR_TTC_B_0X0							(0x0u<<4)
#define	ETH_MTLTXQ0OMR_TTC_B_0X1							(0x1u<<4)
#define	ETH_MTLTXQ0OMR_TTC_B_0X2							(0x2u<<4)
#define	ETH_MTLTXQ0OMR_TTC_B_0X3							(0x3u<<4)
#define	ETH_MTLTXQ0OMR_TTC_B_0X4							(0x4u<<4)
#define	ETH_MTLTXQ0OMR_TTC_B_0X5							(0x5u<<4)
#define	ETH_MTLTXQ0OMR_TTC_B_0X6							(0x6u<<4)
#define	ETH_MTLTXQ0OMR_TTC_B_0X7							(0x7u<<4)
#define	ETH_MTLTXQ0OMR_TXQEN_B_0X0							(0x0u<<2)
#define	ETH_MTLTXQ0OMR_TXQEN_B_0X1							(0x1u<<2)
#define	ETH_MTLTXQ0OMR_TXQEN_B_0X2							(0x2u<<2)

// MTLTXQ0UR Configuration

#define	ETH_MTLTXQ0UR_UFCNTOVF								(0x1u<<11)
#define	ETH_MTLTXQ0UR_UFFRMCNT								(0x7FFu<<0)
#define	ETH_MTLTXQ0UR_UFFRMCNT_0							(0x1u<<0)

// MTLTXQ0DR Configuration

#define	ETH_MTLTXQ0DR_STXSTSF								(0x7u<<20)
#define	ETH_MTLTXQ0DR_STXSTSF_0								(0x1u<<20)
#define	ETH_MTLTXQ0DR_PTXQ									(0x7u<<16)
#define	ETH_MTLTXQ0DR_PTXQ_0								(0x1u<<16)
#define	ETH_MTLTXQ0DR_TXSTSFSTS								(0x1u<<5)
#define	ETH_MTLTXQ0DR_TXQSTS								(0x1u<<4)
#define	ETH_MTLTXQ0DR_TWCSTS								(0x1u<<3)
#define	ETH_MTLTXQ0DR_TRCSTS								(0x3u<<1)
#define	ETH_MTLTXQ0DR_TRCSTS_0								(0x1u<<1)
#define	ETH_MTLTXQ0DR_TXQPAUSED								(0x1u<<0)

#define	ETH_MTLTXQ0DR_TRCSTS_B_0X0							(0x0u<<1)
#define	ETH_MTLTXQ0DR_TRCSTS_B_0X1							(0x1u<<1)
#define	ETH_MTLTXQ0DR_TRCSTS_B_0X2							(0x2u<<1)
#define	ETH_MTLTXQ0DR_TRCSTS_B_0X3							(0x3u<<1)

// MTLTXQ0ESR Configuration

#define	ETH_MTLTXQ0ESR_ABS									(0xFFFFFFu<<0)
#define	ETH_MTLTXQ0ESR_ABS_0								(0x1u<<0)

// MTLTXQ0QWR Configuration

#define	ETH_MTLTXQ0QWR_ISCQW								(0x7Fu<<0)
#define	ETH_MTLTXQ0QWR_ISCQW_0								(0x1u<<0)

// MTLQ0ICSR Configuration

#define	ETH_MTLQ0ICSR_RXOIE									(0x1u<<24)
#define	ETH_MTLQ0ICSR_RXOVFIS								(0x1u<<16)
#define	ETH_MTLQ0ICSR_ABPSIE								(0x1u<<9)
#define	ETH_MTLQ0ICSR_TXUIE									(0x1u<<8)
#define	ETH_MTLQ0ICSR_ABPSIS								(0x1u<<1)
#define	ETH_MTLQ0ICSR_TXUNFIS								(0x1u<<0)

// MTLRXQ0OMR Configuration

#define	ETH_MTLRXQ0OMR_RQS									(0xFu<<20)
#define	ETH_MTLRXQ0OMR_RQS_0								(0x1u<<20)
#define	ETH_MTLRXQ0OMR_RFD									(0x7u<<14)
#define	ETH_MTLRXQ0OMR_RFD_0								(0x1u<<14)
#define	ETH_MTLRXQ0OMR_RFA									(0x7u<<8)
#define	ETH_MTLRXQ0OMR_RFA_0								(0x1u<<8)
#define	ETH_MTLRXQ0OMR_EHFC									(0x1u<<7)
#define	ETH_MTLRXQ0OMR_DIS_TCP_EF							(0x1u<<6)
#define	ETH_MTLRXQ0OMR_RSF									(0x1u<<5)
#define	ETH_MTLRXQ0OMR_FEP									(0x1u<<4)
#define	ETH_MTLRXQ0OMR_FUP									(0x1u<<3)
#define	ETH_MTLRXQ0OMR_RTC									(0x3u<<0)
#define	ETH_MTLRXQ0OMR_RTC_0								(0x1u<<0)

#define	ETH_MTLRXQ0OMR_RFD_B_0X0							(0x0u<<14)
#define	ETH_MTLRXQ0OMR_RFD_B_0X1							(0x1u<<14)
#define	ETH_MTLRXQ0OMR_RTC_B_0X0							(0x0u<<0)
#define	ETH_MTLRXQ0OMR_RTC_B_0X1							(0x1u<<0)
#define	ETH_MTLRXQ0OMR_RTC_B_0X2							(0x2u<<0)
#define	ETH_MTLRXQ0OMR_RTC_B_0X3							(0x3u<<0)

// MTLRXQ0MPOCR Configuration

#define	ETH_MTLRXQ0MPOCR_MISCNTOVF							(0x1u<<27)
#define	ETH_MTLRXQ0MPOCR_MISPKTCNT							(0x7FFu<<16)
#define	ETH_MTLRXQ0MPOCR_MISPKTCNT_0						(0x1u<<16)
#define	ETH_MTLRXQ0MPOCR_OVFCNTOVF							(0x1u<<11)
#define	ETH_MTLRXQ0MPOCR_OVFPKTCNT							(0x7FFu<<0)
#define	ETH_MTLRXQ0MPOCR_OVFPKTCNT_0						(0x1u<<0)

// MTLRXQ0DR Configuration

#define	ETH_MTLRXQ0DR_PRXQ									(0x3FFFu<<16)
#define	ETH_MTLRXQ0DR_PRXQ_0								(0x1u<<16)
#define	ETH_MTLRXQ0DR_RXQSTS								(0x3u<<4)
#define	ETH_MTLRXQ0DR_RXQSTS_0								(0x1u<<4)
#define	ETH_MTLRXQ0DR_RRCSTS								(0x3u<<1)
#define	ETH_MTLRXQ0DR_RRCSTS_0								(0x1u<<1)
#define	ETH_MTLRXQ0DR_RWCSTS								(0x1u<<0)

#define	ETH_MTLRXQ0DR_RXQSTS_B_0X0							(0x0u<<4)
#define	ETH_MTLRXQ0DR_RXQSTS_B_0X1							(0x1u<<4)
#define	ETH_MTLRXQ0DR_RXQSTS_B_0X2							(0x2u<<4)
#define	ETH_MTLRXQ0DR_RXQSTS_B_0X3							(0x3u<<4)
#define	ETH_MTLRXQ0DR_RRCSTS_B_0X0							(0x0u<<1)
#define	ETH_MTLRXQ0DR_RRCSTS_B_0X1							(0x1u<<1)
#define	ETH_MTLRXQ0DR_RRCSTS_B_0X2							(0x2u<<1)
#define	ETH_MTLRXQ0DR_RRCSTS_B_0X3							(0x3u<<1)

// MTLRXQ0CR Configuration

#define	ETH_MTLRXQ0CR_RXQ_FRM_ARBIT							(0x1u<<3)
#define	ETH_MTLRXQ0CR_RXQ_WEGT								(0x7u<<0)
#define	ETH_MTLRXQ0CR_RXQ_WEGT_0							(0x1u<<0)

// MTLTXQ1OMR Configuration

#define	ETH_MTLTXQ1OMR_TQS									(0xFu<<16)
#define	ETH_MTLTXQ1OMR_TQS_0								(0x1u<<16)
#define	ETH_MTLTXQ1OMR_TTC									(0x7u<<4)
#define	ETH_MTLTXQ1OMR_TTC_0								(0x1u<<4)
#define	ETH_MTLTXQ1OMR_TXQEN								(0x3u<<2)
#define	ETH_MTLTXQ1OMR_TXQEN_0								(0x1u<<2)
#define	ETH_MTLTXQ1OMR_TSF									(0x1u<<1)
#define	ETH_MTLTXQ1OMR_FTQ									(0x1u<<0)

#define	ETH_MTLTXQ1OMR_TTC_B_0X0							(0x0u<<4)
#define	ETH_MTLTXQ1OMR_TTC_B_0X1							(0x1u<<4)
#define	ETH_MTLTXQ1OMR_TTC_B_0X2							(0x2u<<4)
#define	ETH_MTLTXQ1OMR_TTC_B_0X3							(0x3u<<4)
#define	ETH_MTLTXQ1OMR_TTC_B_0X4							(0x4u<<4)
#define	ETH_MTLTXQ1OMR_TTC_B_0X5							(0x5u<<4)
#define	ETH_MTLTXQ1OMR_TTC_B_0X6							(0x6u<<4)
#define	ETH_MTLTXQ1OMR_TTC_B_0X7							(0x7u<<4)
#define	ETH_MTLTXQ1OMR_TXQEN_B_0X0							(0x0u<<2)
#define	ETH_MTLTXQ1OMR_TXQEN_B_0X1							(0x1u<<2)
#define	ETH_MTLTXQ1OMR_TXQEN_B_0X2							(0x2u<<2)

// MTLTXQ1UR Configuration

#define	ETH_MTLTXQ1UR_UFCNTOVF								(0x1u<<11)
#define	ETH_MTLTXQ1UR_UFFRMCNT								(0x7FFu<<0)
#define	ETH_MTLTXQ1UR_UFFRMCNT_0							(0x1u<<0)

// MTLTXQ1DR Configuration

#define	ETH_MTLTXQ1DR_STXSTSF								(0x7u<<20)
#define	ETH_MTLTXQ1DR_STXSTSF_0								(0x1u<<20)
#define	ETH_MTLTXQ1DR_PTXQ									(0x7u<<16)
#define	ETH_MTLTXQ1DR_PTXQ_0								(0x1u<<16)
#define	ETH_MTLTXQ1DR_TXSTSFSTS								(0x1u<<5)
#define	ETH_MTLTXQ1DR_TXQSTS								(0x1u<<4)
#define	ETH_MTLTXQ1DR_TWCSTS								(0x1u<<3)
#define	ETH_MTLTXQ1DR_TRCSTS								(0x3u<<1)
#define	ETH_MTLTXQ1DR_TRCSTS_0								(0x1u<<1)
#define	ETH_MTLTXQ1DR_TXQPAUSED								(0x1u<<0)

#define	ETH_MTLTXQ1DR_TRCSTS_B_0X0							(0x0u<<1)
#define	ETH_MTLTXQ1DR_TRCSTS_B_0X1							(0x1u<<1)
#define	ETH_MTLTXQ1DR_TRCSTS_B_0X2							(0x2u<<1)
#define	ETH_MTLTXQ1DR_TRCSTS_B_0X3							(0x3u<<1)

// MTLTXQ1ECR Configuration

#define	ETH_MTLTXQ1ECR_SLC									(0x7u<<4)
#define	ETH_MTLTXQ1ECR_SLC_0								(0x1u<<4)
#define	ETH_MTLTXQ1ECR_CC									(0x1u<<3)
#define	ETH_MTLTXQ1ECR_AVALG								(0x1u<<2)

#define	ETH_MTLTXQ1ECR_SLC_B_0X0							(0x0u<<4)
#define	ETH_MTLTXQ1ECR_SLC_B_0X1							(0x1u<<4)
#define	ETH_MTLTXQ1ECR_SLC_B_0X2							(0x2u<<4)
#define	ETH_MTLTXQ1ECR_SLC_B_0X3							(0x3u<<4)
#define	ETH_MTLTXQ1ECR_SLC_B_0X4							(0x4u<<4)

// MTLTXQ1ESR Configuration

#define	ETH_MTLTXQ1ESR_ABS									(0xFFFFFFu<<0)
#define	ETH_MTLTXQ1ESR_ABS_0								(0x1u<<0)

// MTLTXQ1QWR Configuration

#define	ETH_MTLTXQ1QWR_ISCQW								(0x3FFFu<<0)
#define	ETH_MTLTXQ1QWR_ISCQW_0								(0x1u<<0)

// MTLTXQ1SSCR Configuration

#define	ETH_MTLTXQ1SSCR_SSC									(0x3FFFu<<0)
#define	ETH_MTLTXQ1SSCR_SSC_0								(0x1u<<0)

// MTLTXQ1HCR Configuration

#define	ETH_MTLTXQ1HCR_HC									(0x1FFFFFFFu<<0)
#define	ETH_MTLTXQ1HCR_HC_0									(0x1u<<0)

// MTLTXQ1LCR Configuration

#define	ETH_MTLTXQ1LCR_LC									(0x1FFFFFFFu<<0)
#define	ETH_MTLTXQ1LCR_LC_0									(0x1u<<0)

// MTLQ1ICSR Configuration

#define	ETH_MTLQ1ICSR_RXOIE									(0x1u<<24)
#define	ETH_MTLQ1ICSR_RXOVFIS								(0x1u<<16)
#define	ETH_MTLQ1ICSR_ABPSIE								(0x1u<<9)
#define	ETH_MTLQ1ICSR_TXUIE									(0x1u<<8)
#define	ETH_MTLQ1ICSR_ABPSIS								(0x1u<<1)
#define	ETH_MTLQ1ICSR_TXUNFIS								(0x1u<<0)

// MTLRXQ1OMR Configuration

#define	ETH_MTLRXQ1OMR_RQS									(0xFu<<20)
#define	ETH_MTLRXQ1OMR_RQS_0								(0x1u<<20)
#define	ETH_MTLRXQ1OMR_RFD									(0x7u<<14)
#define	ETH_MTLRXQ1OMR_RFD_0								(0x1u<<14)
#define	ETH_MTLRXQ1OMR_RFA									(0x7u<<8)
#define	ETH_MTLRXQ1OMR_RFA_0								(0x1u<<8)
#define	ETH_MTLRXQ1OMR_EHFC									(0x1u<<7)
#define	ETH_MTLRXQ1OMR_DIS_TCP_EF							(0x1u<<6)
#define	ETH_MTLRXQ1OMR_RSF									(0x1u<<5)
#define	ETH_MTLRXQ1OMR_FEP									(0x1u<<4)
#define	ETH_MTLRXQ1OMR_FUP									(0x1u<<3)
#define	ETH_MTLRXQ1OMR_RTC									(0x3u<<0)
#define	ETH_MTLRXQ1OMR_RTC_0								(0x1u<<0)

#define	ETH_MTLRXQ1OMR_RFD_B_0X0							(0x0u<<14)
#define	ETH_MTLRXQ1OMR_RFD_B_0X1							(0x1u<<14)
#define	ETH_MTLRXQ1OMR_RTC_B_0X0							(0x0u<<0)
#define	ETH_MTLRXQ1OMR_RTC_B_0X1							(0x1u<<0)
#define	ETH_MTLRXQ1OMR_RTC_B_0X2							(0x2u<<0)
#define	ETH_MTLRXQ1OMR_RTC_B_0X3							(0x3u<<0)

// MTLRXQ1MPOCR Configuration

#define	ETH_MTLRXQ1MPOCR_MISCNTOVF							(0x1u<<27)
#define	ETH_MTLRXQ1MPOCR_MISPKTCNT							(0x7FFu<<16)
#define	ETH_MTLRXQ1MPOCR_MISPKTCNT_0						(0x1u<<16)
#define	ETH_MTLRXQ1MPOCR_OVFCNTOVF							(0x1u<<11)
#define	ETH_MTLRXQ1MPOCR_OVFPKTCNT							(0x7FFu<<0)
#define	ETH_MTLRXQ1MPOCR_OVFPKTCNT_0						(0x1u<<0)

// MTLRXQ1DR Configuration

#define	ETH_MTLRXQ1DR_PRXQ									(0x3FFFu<<16)
#define	ETH_MTLRXQ1DR_PRXQ_0								(0x1u<<16)
#define	ETH_MTLRXQ1DR_RXQSTS								(0x3u<<4)
#define	ETH_MTLRXQ1DR_RXQSTS_0								(0x1u<<4)
#define	ETH_MTLRXQ1DR_RRCSTS								(0x3u<<1)
#define	ETH_MTLRXQ1DR_RRCSTS_0								(0x1u<<1)
#define	ETH_MTLRXQ1DR_RWCSTS								(0x1u<<0)

#define	ETH_MTLRXQ1DR_RXQSTS_B_0X0							(0x0u<<4)
#define	ETH_MTLRXQ1DR_RXQSTS_B_0X1							(0x1u<<4)
#define	ETH_MTLRXQ1DR_RXQSTS_B_0X2							(0x2u<<4)
#define	ETH_MTLRXQ1DR_RXQSTS_B_0X3							(0x3u<<4)
#define	ETH_MTLRXQ1DR_RRCSTS_B_0X0							(0x0u<<1)
#define	ETH_MTLRXQ1DR_RRCSTS_B_0X1							(0x1u<<1)
#define	ETH_MTLRXQ1DR_RRCSTS_B_0X2							(0x2u<<1)
#define	ETH_MTLRXQ1DR_RRCSTS_B_0X3							(0x3u<<1)

// MTLRXQ1CR Configuration

#define	ETH_MTLRXQ1CR_RXQ_FRM_ARBIT							(0x1u<<3)
#define	ETH_MTLRXQ1CR_RXQ_WEGT								(0x7u<<0)
#define	ETH_MTLRXQ1CR_RXQ_WEGT_0							(0x1u<<0)

// DMAMR Configuration

#define	ETH_DMAMR_INTM										(0x3u<<16)
#define	ETH_DMAMR_INTM_0									(0x1u<<16)
#define	ETH_DMAMR_TXPR										(0x1u<<11)
#define	ETH_DMAMR_DSPW										(0x1u<<8)
#define	ETH_DMAMR_TAA										(0x7u<<2)
#define	ETH_DMAMR_TAA_0										(0x1u<<2)
#define	ETH_DMAMR_SWR										(0x1u<<0)

#define	ETH_DMAMR_DSPW_B_0X0								(0x0u<<8)
#define	ETH_DMAMR_DSPW_B_0X1								(0x1u<<8)
#define	ETH_DMAMR_TAA_B_0X0									(0x0u<<2)
#define	ETH_DMAMR_TAA_B_0X1									(0x1u<<2)
#define	ETH_DMAMR_TAA_B_0X2									(0x2u<<2)

// DMASBMR Configuration

#define	ETH_DMASBMR_EN_LPI									(0x1u<<31)
#define	ETH_DMASBMR_LPI_XIT_PKT								(0x1u<<30)
#define	ETH_DMASBMR_WR_OSR_LMT								(0x3u<<24)
#define	ETH_DMASBMR_WR_OSR_LMT_0							(0x1u<<24)
#define	ETH_DMASBMR_RD_OSR_LMT								(0x3u<<16)
#define	ETH_DMASBMR_RD_OSR_LMT_0							(0x1u<<16)
#define	ETH_DMASBMR_ONEKBBE									(0x1u<<13)
#define	ETH_DMASBMR_AAL										(0x1u<<12)
#define	ETH_DMASBMR_AALE									(0x1u<<10)
#define	ETH_DMASBMR_BLEN256									(0x1u<<7)
#define	ETH_DMASBMR_BLEN128									(0x1u<<6)
#define	ETH_DMASBMR_BLEN64									(0x1u<<5)
#define	ETH_DMASBMR_BLEN32									(0x1u<<4)
#define	ETH_DMASBMR_BLEN16									(0x1u<<3)
#define	ETH_DMASBMR_BLEN8									(0x1u<<2)
#define	ETH_DMASBMR_BLEN4									(0x1u<<1)
#define	ETH_DMASBMR_FB										(0x1u<<0)

// DMAISR Configuration

#define	ETH_DMAISR_MACIS									(0x1u<<17)
#define	ETH_DMAISR_MTLIS									(0x1u<<16)
#define	ETH_DMAISR_DC1IS									(0x1u<<1)
#define	ETH_DMAISR_DC0IS									(0x1u<<0)

// DMADSR Configuration

#define	ETH_DMADSR_TPS1										(0xFu<<20)
#define	ETH_DMADSR_TPS1_0									(0x1u<<20)
#define	ETH_DMADSR_RPS1										(0xFu<<16)
#define	ETH_DMADSR_RPS1_0									(0x1u<<16)
#define	ETH_DMADSR_TPS0										(0xFu<<12)
#define	ETH_DMADSR_TPS0_0									(0x1u<<12)
#define	ETH_DMADSR_RPS0										(0xFu<<8)
#define	ETH_DMADSR_RPS0_0									(0x1u<<8)
#define	ETH_DMADSR_AXRHSTS									(0x1u<<1)
#define	ETH_DMADSR_AXWHSTS									(0x1u<<0)

#define	ETH_DMADSR_TPS0_B_0X0								(0x0u<<12)
#define	ETH_DMADSR_TPS0_B_0X1								(0x1u<<12)
#define	ETH_DMADSR_TPS0_B_0X2								(0x2u<<12)
#define	ETH_DMADSR_TPS0_B_0X3								(0x3u<<12)
#define	ETH_DMADSR_TPS0_B_0X4								(0x4u<<12)
#define	ETH_DMADSR_TPS0_B_0X6								(0x6u<<12)
#define	ETH_DMADSR_TPS0_B_0X7								(0x7u<<12)
#define	ETH_DMADSR_RPS0_B_0X0								(0x0u<<8)
#define	ETH_DMADSR_RPS0_B_0X1								(0x1u<<8)
#define	ETH_DMADSR_RPS0_B_0X3								(0x3u<<8)
#define	ETH_DMADSR_RPS0_B_0X4								(0x4u<<8)
#define	ETH_DMADSR_RPS0_B_0X5								(0x5u<<8)
#define	ETH_DMADSR_RPS0_B_0X6								(0x6u<<8)
#define	ETH_DMADSR_RPS0_B_0X7								(0x7u<<8)

// DMAA4TXACR Configuration

#define	ETH_DMAA4TXACR_THC									(0xFu<<16)
#define	ETH_DMAA4TXACR_THC_0								(0x1u<<16)
#define	ETH_DMAA4TXACR_TEC									(0xFu<<8)
#define	ETH_DMAA4TXACR_TEC_0								(0x1u<<8)
#define	ETH_DMAA4TXACR_TDRC									(0xFu<<0)
#define	ETH_DMAA4TXACR_TDRC_0								(0x1u<<0)

// DMAA4RXACR Configuration

#define	ETH_DMAA4RXACR_RDC									(0xFu<<24)
#define	ETH_DMAA4RXACR_RDC_0								(0x1u<<24)
#define	ETH_DMAA4RXACR_RHC									(0xFu<<16)
#define	ETH_DMAA4RXACR_RHC_0								(0x1u<<16)
#define	ETH_DMAA4RXACR_RPC									(0xFu<<8)
#define	ETH_DMAA4RXACR_RPC_0								(0x1u<<8)
#define	ETH_DMAA4RXACR_RDWC									(0xFu<<0)
#define	ETH_DMAA4RXACR_RDWC_0								(0x1u<<0)

// DMAA4DACR Configuration

#define	ETH_DMAA4DACR_RDRC									(0xFu<<8)
#define	ETH_DMAA4DACR_RDRC_0								(0x1u<<8)
#define	ETH_DMAA4DACR_TDWD									(0x3u<<4)
#define	ETH_DMAA4DACR_TDWD_0								(0x1u<<4)
#define	ETH_DMAA4DACR_TDWC									(0xFu<<0)
#define	ETH_DMAA4DACR_TDWC_0								(0x1u<<0)

// DMALPIEI Configuration

#define	ETH_DMALPIEI_LPIEI									(0xFu<<0)
#define	ETH_DMALPIEI_LPIEI_0								(0x1u<<0)

// DMATBSCTRL0R Configuration

#define	ETH_DMATBSCTRL0R_FTOS								(0xFFFFFFu<<8)
#define	ETH_DMATBSCTRL0R_FTOS_0								(0x1u<<8)
#define	ETH_DMATBSCTRL0R_FGOS								(0x7u<<4)
#define	ETH_DMATBSCTRL0R_FGOS_0								(0x1u<<4)
#define	ETH_DMATBSCTRL0R_FTOV								(0x1u<<0)

#define	ETH_DMATBSCTRL0R_FTOV_B_0X0							(0x0u<<0)
#define	ETH_DMATBSCTRL0R_FTOV_B_0X1							(0x1u<<0)

// DMAC0CR Configuration

#define	ETH_DMAC0CR_DSL										(0x7u<<18)
#define	ETH_DMAC0CR_DSL_0									(0x1u<<18)
#define	ETH_DMAC0CR_PBLX8									(0x1u<<16)
#define	ETH_DMAC0CR_MSS										(0x3FFFu<<0)
#define	ETH_DMAC0CR_MSS_0									(0x1u<<0)

// DMAC0TXCR Configuration

#define	ETH_DMAC0TXCR_EDSE									(0x1u<<28)
#define	ETH_DMAC0TXCR_TQOS									(0xFu<<24)
#define	ETH_DMAC0TXCR_TQOS_0								(0x1u<<24)
#define	ETH_DMAC0TXCR_TXPBL									(0x3Fu<<16)
#define	ETH_DMAC0TXCR_TXPBL_0								(0x1u<<16)
#define	ETH_DMAC0TXCR_IPBL									(0x1u<<15)
#define	ETH_DMAC0TXCR_TSE									(0x1u<<12)
#define	ETH_DMAC0TXCR_OSF									(0x1u<<4)
#define	ETH_DMAC0TXCR_TCW									(0x7u<<1)
#define	ETH_DMAC0TXCR_TCW_0									(0x1u<<1)
#define	ETH_DMAC0TXCR_ST									(0x1u<<0)

// DMAC0RXCR Configuration

#define	ETH_DMAC0RXCR_RPF									(0x1u<<31)
#define	ETH_DMAC0RXCR_RQOS									(0xFu<<24)
#define	ETH_DMAC0RXCR_RQOS_0								(0x1u<<24)
#define	ETH_DMAC0RXCR_RXPBL									(0x3Fu<<16)
#define	ETH_DMAC0RXCR_RXPBL_0								(0x1u<<16)
#define	ETH_DMAC0RXCR_RBSZ									(0x3FFFu<<1)
#define	ETH_DMAC0RXCR_RBSZ_0								(0x1u<<1)
#define	ETH_DMAC0RXCR_SR									(0x1u<<0)

// DMAC0TXDLAR Configuration

#define	ETH_DMAC0TXDLAR_TDESLA								(0xFFFFFFFFu<<0)
#define	ETH_DMAC0TXDLAR_TDESLA_0							(0x1u<<0)

// DMAC0RXDLAR Configuration

#define	ETH_DMAC0RXDLAR_RDESLA								(0xFFFFFFFFu<<0)
#define	ETH_DMAC0RXDLAR_RDESLA_0							(0x1u<<0)

// DMAC0TXDTPR Configuration

#define	ETH_DMAC0TXDTPR_TDT									(0xFFFFFFFFu<<0)
#define	ETH_DMAC0TXDTPR_TDT_0								(0x1u<<0)

// DMAC0RXDTPR Configuration

#define	ETH_DMAC0RXDTPR_RDT									(0xFFFFFFFFu<<0)
#define	ETH_DMAC0RXDTPR_RDT_0								(0x1u<<0)

// DMAC0TXRLR Configuration

#define	ETH_DMAC0TXRLR_TDRL									(0x3FFu<<0)
#define	ETH_DMAC0TXRLR_TDRL_0								(0x1u<<0)

// DMAC0RXRLR Configuration

#define	ETH_DMAC0RXRLR_ARBS									(0x7Fu<<17)
#define	ETH_DMAC0RXRLR_ARBS_0								(0x1u<<17)
#define	ETH_DMAC0RXRLR_RDRL									(0x3FFu<<0)
#define	ETH_DMAC0RXRLR_RDRL_0								(0x1u<<0)

// DMAC0IER Configuration

#define	ETH_DMAC0IER_NIE									(0x1u<<15)
#define	ETH_DMAC0IER_AIE									(0x1u<<14)
#define	ETH_DMAC0IER_CDEE									(0x1u<<13)
#define	ETH_DMAC0IER_FBEE									(0x1u<<12)
#define	ETH_DMAC0IER_ERIE									(0x1u<<11)
#define	ETH_DMAC0IER_ETIE									(0x1u<<10)
#define	ETH_DMAC0IER_RWTE									(0x1u<<9)
#define	ETH_DMAC0IER_RSE									(0x1u<<8)
#define	ETH_DMAC0IER_RBUE									(0x1u<<7)
#define	ETH_DMAC0IER_RIE									(0x1u<<6)
#define	ETH_DMAC0IER_TBUE									(0x1u<<2)
#define	ETH_DMAC0IER_TXSE									(0x1u<<1)
#define	ETH_DMAC0IER_TIE									(0x1u<<0)

// DMAC0RXIWTR Configuration

#define	ETH_DMAC0RXIWTR_RWTU								(0x3u<<16)
#define	ETH_DMAC0RXIWTR_RWTU_0								(0x1u<<16)
#define	ETH_DMAC0RXIWTR_RWT									(0xFFu<<0)
#define	ETH_DMAC0RXIWTR_RWT_0								(0x1u<<0)

#define	ETH_DMAC0RXIWTR_RWTU_B_0X0							(0x0u<<16)
#define	ETH_DMAC0RXIWTR_RWTU_B_0X1							(0x1u<<16)
#define	ETH_DMAC0RXIWTR_RWTU_B_0X2							(0x2u<<16)
#define	ETH_DMAC0RXIWTR_RWTU_B_0X3							(0x3u<<16)

// DMAC0SFCSR Configuration

#define	ETH_DMAC0SFCSR_RSN									(0xFu<<16)
#define	ETH_DMAC0SFCSR_RSN_0								(0x1u<<16)
#define	ETH_DMAC0SFCSR_SIV									(0xFFFu<<4)
#define	ETH_DMAC0SFCSR_SIV_0								(0x1u<<4)
#define	ETH_DMAC0SFCSR_ASC									(0x1u<<1)
#define	ETH_DMAC0SFCSR_ESC									(0x1u<<0)

// DMAC0CATXDR Configuration

#define	ETH_DMAC0CATXDR_CURTDESAPTR							(0xFFFFFFFFu<<0)
#define	ETH_DMAC0CATXDR_CURTDESAPTR_0						(0x1u<<0)

// DMAC0CARXDR Configuration

#define	ETH_DMAC0CARXDR_CURRDESAPTR							(0xFFFFFFFFu<<0)
#define	ETH_DMAC0CARXDR_CURRDESAPTR_0						(0x1u<<0)

// DMAC0CATXBR Configuration

#define	ETH_DMAC0CATXBR_CURTBUFAPTR							(0xFFFFFFFFu<<0)
#define	ETH_DMAC0CATXBR_CURTBUFAPTR_0						(0x1u<<0)

// DMAC0CARXBR Configuration

#define	ETH_DMAC0CARXBR_CURRBUFAPTR							(0xFFFFFFFFu<<0)
#define	ETH_DMAC0CARXBR_CURRBUFAPTR_0						(0x1u<<0)

// DMAC0SR Configuration

#define	ETH_DMAC0SR_REB										(0x7u<<19)
#define	ETH_DMAC0SR_REB_0									(0x1u<<19)
#define	ETH_DMAC0SR_TEB										(0x7u<<16)
#define	ETH_DMAC0SR_TEB_0									(0x1u<<16)
#define	ETH_DMAC0SR_NIS										(0x1u<<15)
#define	ETH_DMAC0SR_AIS										(0x1u<<14)
#define	ETH_DMAC0SR_CDE										(0x1u<<13)
#define	ETH_DMAC0SR_FBE										(0x1u<<12)
#define	ETH_DMAC0SR_ERI										(0x1u<<11)
#define	ETH_DMAC0SR_ETI										(0x1u<<10)
#define	ETH_DMAC0SR_RWT										(0x1u<<9)
#define	ETH_DMAC0SR_RPS										(0x1u<<8)
#define	ETH_DMAC0SR_RBU										(0x1u<<7)
#define	ETH_DMAC0SR_RI										(0x1u<<6)
#define	ETH_DMAC0SR_TBU										(0x1u<<2)
#define	ETH_DMAC0SR_TPS										(0x1u<<1)
#define	ETH_DMAC0SR_TI										(0x1u<<0)

// DMAC0MFCR Configuration

#define	ETH_DMAC0MFCR_MFCO									(0x1u<<15)
#define	ETH_DMAC0MFCR_MFC									(0x7FFu<<0)
#define	ETH_DMAC0MFCR_MFC_0									(0x1u<<0)

// DMAC1CR Configuration

#define	ETH_DMAC1CR_DSL										(0x7u<<18)
#define	ETH_DMAC1CR_DSL_0									(0x1u<<18)
#define	ETH_DMAC1CR_PBLX8									(0x1u<<16)
#define	ETH_DMAC1CR_MSS										(0x3FFFu<<0)
#define	ETH_DMAC1CR_MSS_0									(0x1u<<0)

// DMAC1TXCR Configuration

#define	ETH_DMAC1TXCR_EDSE									(0x1u<<28)
#define	ETH_DMAC1TXCR_TQOS									(0xFu<<24)
#define	ETH_DMAC1TXCR_TQOS_0								(0x1u<<24)
#define	ETH_DMAC1TXCR_TXPBL									(0x3Fu<<16)
#define	ETH_DMAC1TXCR_TXPBL_0								(0x1u<<16)
#define	ETH_DMAC1TXCR_IPBL									(0x1u<<15)
#define	ETH_DMAC1TXCR_TSE									(0x1u<<12)
#define	ETH_DMAC1TXCR_OSF									(0x1u<<4)
#define	ETH_DMAC1TXCR_TCW									(0x7u<<1)
#define	ETH_DMAC1TXCR_TCW_0									(0x1u<<1)
#define	ETH_DMAC1TXCR_ST									(0x1u<<0)

// DMAC1RXCR Configuration

#define	ETH_DMAC1RXCR_RPF									(0x1u<<31)
#define	ETH_DMAC1RXCR_RQOS									(0xFu<<24)
#define	ETH_DMAC1RXCR_RQOS_0								(0x1u<<24)
#define	ETH_DMAC1RXCR_RXPBL									(0x3Fu<<16)
#define	ETH_DMAC1RXCR_RXPBL_0								(0x1u<<16)
#define	ETH_DMAC1RXCR_RBSZ									(0x3FFFu<<1)
#define	ETH_DMAC1RXCR_RBSZ_0								(0x1u<<1)
#define	ETH_DMAC1RXCR_SR									(0x1u<<0)

// DMAC1TXDLAR Configuration

#define	ETH_DMAC1TXDLAR_TDESLA								(0xFFFFFFFFu<<0)
#define	ETH_DMAC1TXDLAR_TDESLA_0							(0x1u<<0)

// DMAC1TXDTPR Configuration

#define	ETH_DMAC1TXDTPR_TDT									(0xFFFFFFFFu<<0)
#define	ETH_DMAC1TXDTPR_TDT_0								(0x1u<<0)

// DMAC1RXDTPR Configuration

#define	ETH_DMAC1RXDTPR_RDT									(0xFFFFFFFFu<<0)
#define	ETH_DMAC1RXDTPR_RDT_0								(0x1u<<0)

// DMAC1TXRLR Configuration

#define	ETH_DMAC1TXRLR_TDRL									(0x3FFu<<0)
#define	ETH_DMAC1TXRLR_TDRL_0								(0x1u<<0)

// DMAC1RXRLR Configuration

#define	ETH_DMAC1RXRLR_ARBS									(0x7Fu<<17)
#define	ETH_DMAC1RXRLR_ARBS_0								(0x1u<<17)
#define	ETH_DMAC1RXRLR_RDRL									(0x3FFu<<0)
#define	ETH_DMAC1RXRLR_RDRL_0								(0x1u<<0)

// DMAC1IER Configuration

#define	ETH_DMAC1IER_NIE									(0x1u<<15)
#define	ETH_DMAC1IER_AIE									(0x1u<<14)
#define	ETH_DMAC1IER_CDEE									(0x1u<<13)
#define	ETH_DMAC1IER_FBEE									(0x1u<<12)
#define	ETH_DMAC1IER_ERIE									(0x1u<<11)
#define	ETH_DMAC1IER_ETIE									(0x1u<<10)
#define	ETH_DMAC1IER_RWTE									(0x1u<<9)
#define	ETH_DMAC1IER_RSE									(0x1u<<8)
#define	ETH_DMAC1IER_RBUE									(0x1u<<7)
#define	ETH_DMAC1IER_RIE									(0x1u<<6)
#define	ETH_DMAC1IER_TBUE									(0x1u<<2)
#define	ETH_DMAC1IER_TXSE									(0x1u<<1)
#define	ETH_DMAC1IER_TIE									(0x1u<<0)

// DMAC1RXIWTR Configuration

#define	ETH_DMAC1RXIWTR_RWTU								(0x3u<<16)
#define	ETH_DMAC1RXIWTR_RWTU_0								(0x1u<<16)
#define	ETH_DMAC1RXIWTR_RWT									(0xFFu<<0)
#define	ETH_DMAC1RXIWTR_RWT_0								(0x1u<<0)

#define	ETH_DMAC1RXIWTR_RWTU_B_0X0							(0x0u<<16)
#define	ETH_DMAC1RXIWTR_RWTU_B_0X1							(0x1u<<16)
#define	ETH_DMAC1RXIWTR_RWTU_B_0X2							(0x2u<<16)
#define	ETH_DMAC1RXIWTR_RWTU_B_0X3							(0x3u<<16)

// DMAC1SFCSR Configuration

#define	ETH_DMAC1SFCSR_RSN									(0xFu<<16)
#define	ETH_DMAC1SFCSR_RSN_0								(0x1u<<16)
#define	ETH_DMAC1SFCSR_SIV									(0xFFFu<<4)
#define	ETH_DMAC1SFCSR_SIV_0								(0x1u<<4)
#define	ETH_DMAC1SFCSR_ASC									(0x1u<<1)
#define	ETH_DMAC1SFCSR_ESC									(0x1u<<0)

// DMAC1CATXDR Configuration

#define	ETH_DMAC1CATXDR_CURTDESAPTR							(0xFFFFFFFFu<<0)
#define	ETH_DMAC1CATXDR_CURTDESAPTR_0						(0x1u<<0)

// DMAC1CARXDR Configuration

#define	ETH_DMAC1CARXDR_CURRDESAPTR							(0xFFFFFFFFu<<0)
#define	ETH_DMAC1CARXDR_CURRDESAPTR_0						(0x1u<<0)

// DMAC1CATXBR Configuration

#define	ETH_DMAC1CATXBR_CURTBUFAPTR							(0xFFFFFFFFu<<0)
#define	ETH_DMAC1CATXBR_CURTBUFAPTR_0						(0x1u<<0)

// DMAC1CARXBR Configuration

#define	ETH_DMAC1CARXBR_CURRBUFAPTR							(0xFFFFFFFFu<<0)
#define	ETH_DMAC1CARXBR_CURRBUFAPTR_0						(0x1u<<0)

// DMAC1SR Configuration

#define	ETH_DMAC1SR_REB										(0x7u<<19)
#define	ETH_DMAC1SR_REB_0									(0x1u<<19)
#define	ETH_DMAC1SR_TEB										(0x7u<<16)
#define	ETH_DMAC1SR_TEB_0									(0x1u<<16)
#define	ETH_DMAC1SR_NIS										(0x1u<<15)
#define	ETH_DMAC1SR_AIS										(0x1u<<14)
#define	ETH_DMAC1SR_CDE										(0x1u<<13)
#define	ETH_DMAC1SR_FBE										(0x1u<<12)
#define	ETH_DMAC1SR_ERI										(0x1u<<11)
#define	ETH_DMAC1SR_ETI										(0x1u<<10)
#define	ETH_DMAC1SR_RWT										(0x1u<<9)
#define	ETH_DMAC1SR_RPS										(0x1u<<8)
#define	ETH_DMAC1SR_RBU										(0x1u<<7)
#define	ETH_DMAC1SR_RI										(0x1u<<6)
#define	ETH_DMAC1SR_TBU										(0x1u<<2)
#define	ETH_DMAC1SR_TPS										(0x1u<<1)
#define	ETH_DMAC1SR_TI										(0x1u<<0)

// DMAC1MFCR Configuration

#define	ETH_DMAC1MFCR_MFCO									(0x1u<<15)
#define	ETH_DMAC1MFCR_MFC									(0x7FFu<<0)
#define	ETH_DMAC1MFCR_MFC_0									(0x1u<<0)
