/*
; stm32H747_CM7_ethernet.
; =======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM7_ethernet equates.
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

// ETHERNET address definitions
// ----------------------------

typedef struct {
	volatile	uint32_t	MACCR;
	volatile	uint32_t	MACECR;
	volatile	uint32_t	MACPFR;
	volatile	uint32_t	MACWTR;
	volatile	uint32_t	MACHT0R;
	volatile	uint32_t	MACHT1R;
	volatile	uint32_t	RESERVED0[14];
	volatile	uint32_t	MACVTR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	MACVHTR;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	MACVIR;
	volatile	uint32_t	MACIVIR;
	volatile	uint32_t	RESERVED3[2];
	volatile	uint32_t	MACQTXFCR;
	volatile	uint32_t	RESERVED4[7];
	volatile	uint32_t	MACRXFCR;
	volatile	uint32_t	RESERVED5[7];
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
	volatile	uint32_t	RESERVED8[12];
	volatile	uint32_t	MACVR;
	volatile	uint32_t	MACDR;
	volatile	uint32_t	RESERVED9[2];
	volatile	uint32_t	MACHWF1R;
	volatile	uint32_t	MACHWF2R;
	volatile	uint32_t	RESERVED10[54];
	volatile	uint32_t	MACMDIOAR;
	volatile	uint32_t	MACMDIODR;
	volatile	uint32_t	RESERVED11[62];
	volatile	uint32_t	MACA0HR;
	volatile	uint32_t	MACA0LR;
	volatile	uint32_t	MACA1HR;
	volatile	uint32_t	MACA1LR;
	volatile	uint32_t	MACA2HR;
	volatile	uint32_t	MACA2LR;
	volatile	uint32_t	MACA3HR;
	volatile	uint32_t	MACA3LR;
	volatile	uint32_t	RESERVED12[248];
	volatile	uint32_t	MMC_CONTROL;
	volatile	uint32_t	MMC_RX_INTERRUPT;
	volatile	uint32_t	MMC_TX_INTERRUPT;
	volatile	uint32_t	MMC_RX_INTERRUPT_MASK;
	volatile	uint32_t	MMC_TX_INTERRUPT_MASK;
	volatile	uint32_t	RESERVED13[14];
	volatile	uint32_t	TX_SINGLE_COLLISION_GOOD_PACKETS;
	volatile	uint32_t	TX_MULTIPLE_COLLISION_GOOD_PACKETS;
	volatile	uint32_t	RESERVED14[5];
	volatile	uint32_t	TX_PACKET_COUNT_GOOD;
	volatile	uint32_t	RESERVED15[10];
	volatile	uint32_t	RX_CRC_ERROR_PACKETS;
	volatile	uint32_t	RX_ALIGNMENT_ERROR_PACKETS;
	volatile	uint32_t	RESERVED16[10];
	volatile	uint32_t	RX_UNICAST_PACKETS_GOOD;
	volatile	uint32_t	RESERVED17[9];
	volatile	uint32_t	TX_LPI_USEC_CNTR;
	volatile	uint32_t	TX_LPI_TRAN_CNTR;
	volatile	uint32_t	RX_LPI_USEC_CNTR;
	volatile	uint32_t	RX_LPI_TRAN_CNTR;
	volatile	uint32_t	RESERVED18[65];
	volatile	uint32_t	MACL3L4C0R;
	volatile	uint32_t	MACL4A0R;
	volatile	uint32_t	RESERVED19[2];
	volatile	uint32_t	MACL3A00R;
	volatile	uint32_t	MACL3A10R;
	volatile	uint32_t	MACL3A20;
	volatile	uint32_t	MACL3A30;
	volatile	uint32_t	RESERVED20[4];
	volatile	uint32_t	MACL3L4C1R;
	volatile	uint32_t	MACL4A1R;
	volatile	uint32_t	RESERVED21[2];
	volatile	uint32_t	MACL3A01R;
	volatile	uint32_t	MACL3A11R;
	volatile	uint32_t	MACL3A21R;
	volatile	uint32_t	MACL3A31R;
	volatile	uint32_t	RESERVED22[100];
	volatile	uint32_t	MACARPAR;
	volatile	uint32_t	RESERVED23[7];
	volatile	uint32_t	MACTSCR;
	volatile	uint32_t	MACSSIR;
	volatile	uint32_t	MACSTSR;
	volatile	uint32_t	MACSTNR;
	volatile	uint32_t	MACSTSUR;
	volatile	uint32_t	MACSTNUR;
	volatile	uint32_t	MACTSAR;
	volatile	uint32_t	RESERVED24;
	volatile	uint32_t	MACTSSR;
	volatile	uint32_t	RESERVED25[3];
	volatile	uint32_t	MACTXTSSNR;
	volatile	uint32_t	MACTXTSSSR;
	volatile	uint32_t	RESERVED26[2];
	volatile	uint32_t	MACACR;
	volatile	uint32_t	RESERVED27;
	volatile	uint32_t	MACATSNR;
	volatile	uint32_t	MACATSSR;
	volatile	uint32_t	MACTSIACR;
	volatile	uint32_t	MACTSEACR;
	volatile	uint32_t	MACTSICNR;
	volatile	uint32_t	MACTSECNR;
	volatile	uint32_t	RESERVED28[4];
	volatile	uint32_t	MACPPSCR;
	volatile	uint32_t	RESERVED29[3];
	volatile	uint32_t	MACPPSTTSR;
	volatile	uint32_t	MACPPSTTNR;
	volatile	uint32_t	MACPPSIR;
	volatile	uint32_t	MACPPSWR;
	volatile	uint32_t	RESERVED30[12];
	volatile	uint32_t	MACPOCR;
	volatile	uint32_t	MACSPI0R;
	volatile	uint32_t	MACSPI1R;
	volatile	uint32_t	MACSPI2R;
	volatile	uint32_t	MACLMIR;
	volatile	uint32_t	RESERVED31[11];
	volatile	uint32_t	MTLOMR;
	volatile	uint32_t	RESERVED32[7];
	volatile	uint32_t	MTLISR;
	volatile	uint32_t	RESERVED33[55];
	volatile	uint32_t	MTLTXQOMR;
	volatile	uint32_t	MTLTXQUR;
	volatile	uint32_t	MTLTXQDR;
	volatile	uint32_t	RESERVED34[8];
	volatile	uint32_t	MTLQICSR;
	volatile	uint32_t	MTLRXQOMR;
	volatile	uint32_t	MTLRXQMPOCR;
	volatile	uint32_t	MTLRXQDR;
	volatile	uint32_t	RESERVED35[177];
	volatile	uint32_t	DMAMR;
	volatile	uint32_t	DMASBMR;
	volatile	uint32_t	DMAISR;
	volatile	uint32_t	DMADSR;
	volatile	uint32_t	RESERVED36[60];
	volatile	uint32_t	DMACCR;
	volatile	uint32_t	DMACTXCR;
	volatile	uint32_t	DMACRXCR;
	volatile	uint32_t	RESERVED37[2];
	volatile	uint32_t	DMACTXDLAR;
	volatile	uint32_t	RESERVED38;
	volatile	uint32_t	DMACRXDLAR;
	volatile	uint32_t	DMACTXDTPR;
	volatile	uint32_t	RESERVED39;
	volatile	uint32_t	DMACRXDTPR;
	volatile	uint32_t	DMACTXRLR;
	volatile	uint32_t	DMACRXRLR;
	volatile	uint32_t	DMACIER;
	volatile	uint32_t	DMACRXIWTR;
	volatile	uint32_t	RESERVED40[2];
	volatile	uint32_t	DMACCATXDR;
	volatile	uint32_t	RESERVED41;
	volatile	uint32_t	DMACCARXDR;
	volatile	uint32_t	RESERVED42;
	volatile	uint32_t	DMACCATXBR;
	volatile	uint32_t	RESERVED43;
	volatile	uint32_t	DMACCARXBR;
	volatile	uint32_t	DMACSR;
	volatile	uint32_t	RESERVED44[2];
	volatile	uint32_t	DMACMFCR;
} ETHERNET_TypeDef;

#if (defined(__cplusplus))
#define	ETHERNET_MAC	reinterpret_cast<ETHERNET_TypeDef *>(0x40028000u)

#else
#define	ETHERNET_MAC	((ETHERNET_TypeDef *)0x40028000u)
#endif

// MACCR Configuration

#define	ETHERNET_MACCR_ARPEN										(0x1u<<31)
#define	ETHERNET_MACCR_SARC											(0x7u<<28)
#define	ETHERNET_MACCR_SARC_0										(0x1u<<28)
#define	ETHERNET_MACCR_IPC											(0x1u<<27)
#define	ETHERNET_MACCR_IPG											(0x7u<<24)
#define	ETHERNET_MACCR_IPG_0										(0x1u<<24)
#define	ETHERNET_MACCR_GPSLCE										(0x1u<<23)
#define	ETHERNET_MACCR_S2KP											(0x1u<<22)
#define	ETHERNET_MACCR_CST											(0x1u<<21)
#define	ETHERNET_MACCR_ACS											(0x1u<<20)
#define	ETHERNET_MACCR_WD											(0x1u<<19)
#define	ETHERNET_MACCR_JD											(0x1u<<17)
#define	ETHERNET_MACCR_JE											(0x1u<<16)
#define	ETHERNET_MACCR_FES											(0x1u<<14)
#define	ETHERNET_MACCR_DM											(0x1u<<13)
#define	ETHERNET_MACCR_LM											(0x1u<<12)
#define	ETHERNET_MACCR_ECRSFD										(0x1u<<11)
#define	ETHERNET_MACCR_DO											(0x1u<<10)
#define	ETHERNET_MACCR_DCRS											(0x1u<<9)
#define	ETHERNET_MACCR_DR											(0x1u<<8)
#define	ETHERNET_MACCR_BL											(0x3u<<5)
#define	ETHERNET_MACCR_BL_0											(0x1u<<5)
#define	ETHERNET_MACCR_DC											(0x1u<<4)
#define	ETHERNET_MACCR_PRELEN										(0x3u<<2)
#define	ETHERNET_MACCR_PRELEN_0										(0x1u<<2)
#define	ETHERNET_MACCR_TE											(0x1u<<1)
#define	ETHERNET_MACCR_RE											(0x1u<<0)

// MACECR Configuration

#define	ETHERNET_MACECR_EIPG										(0x1Fu<<25)
#define	ETHERNET_MACECR_EIPG_0										(0x1u<<25)
#define	ETHERNET_MACECR_EIPGEN										(0x1u<<24)
#define	ETHERNET_MACECR_USP											(0x1u<<18)
#define	ETHERNET_MACECR_SPEN										(0x1u<<17)
#define	ETHERNET_MACECR_DCRCC										(0x1u<<16)
#define	ETHERNET_MACECR_GPSL										(0x3FFFu<<0)
#define	ETHERNET_MACECR_GPSL_0										(0x1u<<0)

// MACPFR Configuration

#define	ETHERNET_MACPFR_RA											(0x1u<<31)
#define	ETHERNET_MACPFR_DNTU										(0x1u<<21)
#define	ETHERNET_MACPFR_IPFE										(0x1u<<20)
#define	ETHERNET_MACPFR_VTFE										(0x1u<<16)
#define	ETHERNET_MACPFR_HPF											(0x1u<<10)
#define	ETHERNET_MACPFR_SAF											(0x1u<<9)
#define	ETHERNET_MACPFR_SAIF										(0x1u<<8)
#define	ETHERNET_MACPFR_PCF											(0x3u<<6)
#define	ETHERNET_MACPFR_PCF_0										(0x1u<<6)
#define	ETHERNET_MACPFR_DBF											(0x1u<<5)
#define	ETHERNET_MACPFR_PM											(0x1u<<4)
#define	ETHERNET_MACPFR_DAIF										(0x1u<<3)
#define	ETHERNET_MACPFR_HMC											(0x1u<<2)
#define	ETHERNET_MACPFR_HUC											(0x1u<<1)
#define	ETHERNET_MACPFR_PR											(0x1u<<0)

// MACWTR Configuration

#define	ETHERNET_MACWTR_PWE											(0x1u<<8)
#define	ETHERNET_MACWTR_WTO											(0xFu<<0)
#define	ETHERNET_MACWTR_WTO_0										(0x1u<<0)

// MACHT0R Configuration

#define	ETHERNET_MACHT0R_HT31T0										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACHT0R_HT31T0_0									(0x1u<<0)

// MACHT1R Configuration

#define	ETHERNET_MACHT1R_HT63T32									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACHT1R_HT63T32_0									(0x1u<<0)

// MACVTR Configuration

#define	ETHERNET_MACVTR_EIVLRXS										(0x1u<<31)
#define	ETHERNET_MACVTR_EIVLS										(0x3u<<28)
#define	ETHERNET_MACVTR_EIVLS_0										(0x1u<<28)
#define	ETHERNET_MACVTR_ERIVLT										(0x1u<<27)
#define	ETHERNET_MACVTR_EDVLP										(0x1u<<26)
#define	ETHERNET_MACVTR_VTHM										(0x1u<<25)
#define	ETHERNET_MACVTR_EVLRXS										(0x1u<<24)
#define	ETHERNET_MACVTR_EVLS										(0x3u<<21)
#define	ETHERNET_MACVTR_EVLS_0										(0x1u<<21)
#define	ETHERNET_MACVTR_DOVLTC										(0x1u<<20)
#define	ETHERNET_MACVTR_ERSVLM										(0x1u<<19)
#define	ETHERNET_MACVTR_ESVL										(0x1u<<18)
#define	ETHERNET_MACVTR_VTIM										(0x1u<<17)
#define	ETHERNET_MACVTR_ETV											(0x1u<<16)
#define	ETHERNET_MACVTR_VL											(0xFFFFu<<0)
#define	ETHERNET_MACVTR_VL_0										(0x1u<<0)

// MACVHTR Configuration

#define	ETHERNET_MACVHTR_VLHT										(0xFFFFu<<0)
#define	ETHERNET_MACVHTR_VLHT_0										(0x1u<<0)

// MACVIR Configuration

#define	ETHERNET_MACVIR_VLTI										(0x1u<<20)
#define	ETHERNET_MACVIR_CSVL										(0x1u<<19)
#define	ETHERNET_MACVIR_VLP											(0x1u<<18)
#define	ETHERNET_MACVIR_VLC											(0x3u<<16)
#define	ETHERNET_MACVIR_VLC_0										(0x1u<<16)
#define	ETHERNET_MACVIR_VLT											(0xFFFFu<<0)
#define	ETHERNET_MACVIR_VLT_0										(0x1u<<0)

// MACIVIR Configuration

#define	ETHERNET_MACIVIR_VLTI										(0x1u<<20)
#define	ETHERNET_MACIVIR_CSVL										(0x1u<<19)
#define	ETHERNET_MACIVIR_VLP										(0x1u<<18)
#define	ETHERNET_MACIVIR_VLC										(0x3u<<16)
#define	ETHERNET_MACIVIR_VLC_0										(0x1u<<16)
#define	ETHERNET_MACIVIR_VLT										(0xFFFFu<<0)
#define	ETHERNET_MACIVIR_VLT_0										(0x1u<<0)

// MACQTXFCR Configuration

#define	ETHERNET_MACQTXFCR_PT										(0xFFFFu<<16)
#define	ETHERNET_MACQTXFCR_PT_0										(0x1u<<16)
#define	ETHERNET_MACQTXFCR_DZPQ										(0x1u<<7)
#define	ETHERNET_MACQTXFCR_PLT										(0x7u<<4)
#define	ETHERNET_MACQTXFCR_PLT_0									(0x1u<<4)
#define	ETHERNET_MACQTXFCR_TFE										(0x1u<<1)
#define	ETHERNET_MACQTXFCR_FCB_BPA									(0x1u<<0)

// MACRXFCR Configuration

#define	ETHERNET_MACRXFCR_UP										(0x1u<<1)
#define	ETHERNET_MACRXFCR_RFE										(0x1u<<0)

// MACISR Configuration

#define	ETHERNET_MACISR_RXSTSIS										(0x1u<<14)
#define	ETHERNET_MACISR_TXSTSIS										(0x1u<<13)
#define	ETHERNET_MACISR_TSIS										(0x1u<<12)
#define	ETHERNET_MACISR_MMCTXIS										(0x1u<<10)
#define	ETHERNET_MACISR_MMCRXIS										(0x1u<<9)
#define	ETHERNET_MACISR_MMCIS										(0x1u<<8)
#define	ETHERNET_MACISR_LPIIS										(0x1u<<5)
#define	ETHERNET_MACISR_PMTIS										(0x1u<<4)
#define	ETHERNET_MACISR_PHYIS										(0x1u<<3)

// MACIER Configuration

#define	ETHERNET_MACIER_RXSTSIE										(0x1u<<14)
#define	ETHERNET_MACIER_TXSTSIE										(0x1u<<13)
#define	ETHERNET_MACIER_TSIE										(0x1u<<12)
#define	ETHERNET_MACIER_LPIIE										(0x1u<<5)
#define	ETHERNET_MACIER_PMTIE										(0x1u<<4)
#define	ETHERNET_MACIER_PHYIE										(0x1u<<3)

// MACRXTXSR Configuration

#define	ETHERNET_MACRXTXSR_RWT										(0x1u<<8)
#define	ETHERNET_MACRXTXSR_EXCOL									(0x1u<<5)
#define	ETHERNET_MACRXTXSR_LCOL										(0x1u<<4)
#define	ETHERNET_MACRXTXSR_EXDEF									(0x1u<<3)
#define	ETHERNET_MACRXTXSR_LCARR									(0x1u<<2)
#define	ETHERNET_MACRXTXSR_NCARR									(0x1u<<1)
#define	ETHERNET_MACRXTXSR_TJT										(0x1u<<0)

// MACPCSR Configuration

#define	ETHERNET_MACPCSR_RWKFILTRST									(0x1u<<31)
#define	ETHERNET_MACPCSR_RWKPTR										(0x1Fu<<24)
#define	ETHERNET_MACPCSR_RWKPTR_0									(0x1u<<24)
#define	ETHERNET_MACPCSR_RWKPFE										(0x1u<<10)
#define	ETHERNET_MACPCSR_GLBLUCAST									(0x1u<<9)
#define	ETHERNET_MACPCSR_RWKPRCVD									(0x1u<<6)
#define	ETHERNET_MACPCSR_MGKPRCVD									(0x1u<<5)
#define	ETHERNET_MACPCSR_RWKPKTEN									(0x1u<<2)
#define	ETHERNET_MACPCSR_MGKPKTEN									(0x1u<<1)
#define	ETHERNET_MACPCSR_PWRDWN										(0x1u<<0)

// MACRWKPFR Configuration

#define	ETHERNET_MACRWKPFR_WKUPFRMFTR								(0xFFFFFFFFu<<0)
#define	ETHERNET_MACRWKPFR_WKUPFRMFTR_0								(0x1u<<0)

// MACLCSR Configuration

#define	ETHERNET_MACLCSR_LPITCSE									(0x1u<<21)
#define	ETHERNET_MACLCSR_LPITE										(0x1u<<20)
#define	ETHERNET_MACLCSR_LPITXA										(0x1u<<19)
#define	ETHERNET_MACLCSR_PLSEN										(0x1u<<18)
#define	ETHERNET_MACLCSR_PLS										(0x1u<<17)
#define	ETHERNET_MACLCSR_LPIEN										(0x1u<<16)
#define	ETHERNET_MACLCSR_RLPIST										(0x1u<<9)
#define	ETHERNET_MACLCSR_TLPIST										(0x1u<<8)
#define	ETHERNET_MACLCSR_RLPIEX										(0x1u<<3)
#define	ETHERNET_MACLCSR_RLPIEN										(0x1u<<2)
#define	ETHERNET_MACLCSR_TLPIEX										(0x1u<<1)
#define	ETHERNET_MACLCSR_TLPIEN										(0x1u<<0)

// MACLTCR Configuration

#define	ETHERNET_MACLTCR_LST										(0x3FFu<<16)
#define	ETHERNET_MACLTCR_LST_0										(0x1u<<16)
#define	ETHERNET_MACLTCR_TWT										(0xFFFFu<<0)
#define	ETHERNET_MACLTCR_TWT_0										(0x1u<<0)

// MACLETR Configuration

#define	ETHERNET_MACLETR_LPIET										(0x1FFFFu<<0)
#define	ETHERNET_MACLETR_LPIET_0									(0x1u<<0)

// MAC1USTCR Configuration

#define	ETHERNET_MAC1USTCR_TIC_1US_CNTR								(0xFFFu<<0)
#define	ETHERNET_MAC1USTCR_TIC_1US_CNTR_0							(0x1u<<0)

// MACVR Configuration

#define	ETHERNET_MACVR_USERVER										(0xFFu<<8)
#define	ETHERNET_MACVR_USERVER_0									(0x1u<<8)
#define	ETHERNET_MACVR_SNPSVER										(0xFFu<<0)
#define	ETHERNET_MACVR_SNPSVER_0									(0x1u<<0)

// MACDR Configuration

#define	ETHERNET_MACDR_TFCSTS										(0x3u<<17)
#define	ETHERNET_MACDR_TFCSTS_0										(0x1u<<17)
#define	ETHERNET_MACDR_TPESTS										(0x1u<<16)
#define	ETHERNET_MACDR_RFCFCSTS										(0x3u<<1)
#define	ETHERNET_MACDR_RFCFCSTS_0									(0x1u<<1)
#define	ETHERNET_MACDR_RPESTS										(0x1u<<0)

// MACHWF1R Configuration

#define	ETHERNET_MACHWF1R_L3L4FNUM									(0xFu<<27)
#define	ETHERNET_MACHWF1R_L3L4FNUM_0								(0x1u<<27)
#define	ETHERNET_MACHWF1R_HASHTBLSZ									(0x3u<<24)
#define	ETHERNET_MACHWF1R_HASHTBLSZ_0								(0x1u<<24)
#define	ETHERNET_MACHWF1R_AVSEL										(0x1u<<20)
#define	ETHERNET_MACHWF1R_DBGMEMA									(0x1u<<19)
#define	ETHERNET_MACHWF1R_TSOEN										(0x1u<<18)
#define	ETHERNET_MACHWF1R_SPHEN										(0x1u<<17)
#define	ETHERNET_MACHWF1R_DCBEN										(0x1u<<16)
#define	ETHERNET_MACHWF1R_ADVTHWORD									(0x1u<<13)
#define	ETHERNET_MACHWF1R_PTOEN										(0x1u<<12)
#define	ETHERNET_MACHWF1R_OSTEN										(0x1u<<11)
#define	ETHERNET_MACHWF1R_TXFIFOSIZE								(0x1Fu<<6)
#define	ETHERNET_MACHWF1R_TXFIFOSIZE_0								(0x1u<<6)
#define	ETHERNET_MACHWF1R_RXFIFOSIZE								(0x1Fu<<0)
#define	ETHERNET_MACHWF1R_RXFIFOSIZE_0								(0x1u<<0)

// MACHWF2R Configuration

#define	ETHERNET_MACHWF2R_AUXSNAPNUM								(0x7u<<28)
#define	ETHERNET_MACHWF2R_AUXSNAPNUM_0								(0x1u<<28)
#define	ETHERNET_MACHWF2R_PPSOUTNUM									(0x7u<<24)
#define	ETHERNET_MACHWF2R_PPSOUTNUM_0								(0x1u<<24)
#define	ETHERNET_MACHWF2R_TXCHCNT									(0xFu<<18)
#define	ETHERNET_MACHWF2R_TXCHCNT_0									(0x1u<<18)
#define	ETHERNET_MACHWF2R_RXCHCNT									(0xFu<<12)
#define	ETHERNET_MACHWF2R_RXCHCNT_0									(0x1u<<12)
#define	ETHERNET_MACHWF2R_TXQCNT									(0xFu<<6)
#define	ETHERNET_MACHWF2R_TXQCNT_0									(0x1u<<6)
#define	ETHERNET_MACHWF2R_RXQCNT									(0xFu<<0)
#define	ETHERNET_MACHWF2R_RXQCNT_0									(0x1u<<0)

// MACMDIOAR Configuration

#define	ETHERNET_MACMDIOAR_PSE										(0x1u<<27)
#define	ETHERNET_MACMDIOAR_BTB										(0x1u<<26)
#define	ETHERNET_MACMDIOAR_PA										(0x1Fu<<21)
#define	ETHERNET_MACMDIOAR_PA_0										(0x1u<<21)
#define	ETHERNET_MACMDIOAR_RDA										(0x1Fu<<16)
#define	ETHERNET_MACMDIOAR_RDA_0									(0x1u<<16)
#define	ETHERNET_MACMDIOAR_NTC										(0x7u<<12)
#define	ETHERNET_MACMDIOAR_NTC_0									(0x1u<<12)
#define	ETHERNET_MACMDIOAR_CR										(0xFu<<8)
#define	ETHERNET_MACMDIOAR_CR_0										(0x1u<<8)
#define	ETHERNET_MACMDIOAR_SKAP										(0x1u<<4)
#define	ETHERNET_MACMDIOAR_GOC										(0x3u<<2)
#define	ETHERNET_MACMDIOAR_GOC_0									(0x1u<<2)
#define	ETHERNET_MACMDIOAR_C45E										(0x1u<<1)
#define	ETHERNET_MACMDIOAR_MB										(0x1u<<0)

// MACMDIODR Configuration

#define	ETHERNET_MACMDIODR_RA										(0xFFFFu<<16)
#define	ETHERNET_MACMDIODR_RA_0										(0x1u<<16)
#define	ETHERNET_MACMDIODR_MD										(0xFFFFu<<0)
#define	ETHERNET_MACMDIODR_MD_0										(0x1u<<0)

// MACA0HR Configuration

#define	ETHERNET_MACA0HR_AE											(0x1u<<31)
#define	ETHERNET_MACA0HR_ADDRHI										(0xFFFFu<<0)
#define	ETHERNET_MACA0HR_ADDRHI_0									(0x1u<<0)

// MACA0LR Configuration

#define	ETHERNET_MACA0LR_ADDRLO										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACA0LR_ADDRLO_0									(0x1u<<0)

// MACA1HR Configuration

#define	ETHERNET_MACA1HR_AE											(0x1u<<31)
#define	ETHERNET_MACA1HR_SA											(0x1u<<30)
#define	ETHERNET_MACA1HR_MBC										(0x3Fu<<24)
#define	ETHERNET_MACA1HR_MBC_0										(0x1u<<24)
#define	ETHERNET_MACA1HR_ADDRHI										(0xFFFFu<<0)
#define	ETHERNET_MACA1HR_ADDRHI_0									(0x1u<<0)

// MACA1LR Configuration

#define	ETHERNET_MACA1LR_ADDRLO										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACA1LR_ADDRLO_0									(0x1u<<0)

// MACA2HR Configuration

#define	ETHERNET_MACA2HR_AE											(0x1u<<31)
#define	ETHERNET_MACA2HR_SA											(0x1u<<30)
#define	ETHERNET_MACA2HR_MBC										(0x3Fu<<24)
#define	ETHERNET_MACA2HR_MBC_0										(0x1u<<24)
#define	ETHERNET_MACA2HR_ADDRHI										(0xFFFFu<<0)
#define	ETHERNET_MACA2HR_ADDRHI_0									(0x1u<<0)

// MACA2LR Configuration

#define	ETHERNET_MACA2LR_ADDRLO										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACA2LR_ADDRLO_0									(0x1u<<0)

// MACA3HR Configuration

#define	ETHERNET_MACA3HR_AE											(0x1u<<31)
#define	ETHERNET_MACA3HR_SA											(0x1u<<30)
#define	ETHERNET_MACA3HR_MBC										(0x3Fu<<24)
#define	ETHERNET_MACA3HR_MBC_0										(0x1u<<24)
#define	ETHERNET_MACA3HR_ADDRHI										(0xFFFFu<<0)
#define	ETHERNET_MACA3HR_ADDRHI_0									(0x1u<<0)

// MACA3LR Configuration

#define	ETHERNET_MACA3LR_ADDRLO										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACA3LR_ADDRLO_0									(0x1u<<0)

// MMC_CONTROL Configuration

#define	ETHERNET_MMC_CONTROL_UCDBC									(0x1u<<8)
#define	ETHERNET_MMC_CONTROL_CNTPRSTLVL								(0x1u<<5)
#define	ETHERNET_MMC_CONTROL_CNTPRST								(0x1u<<4)
#define	ETHERNET_MMC_CONTROL_CNTFREEZ								(0x1u<<3)
#define	ETHERNET_MMC_CONTROL_RSTONRD								(0x1u<<2)
#define	ETHERNET_MMC_CONTROL_CNTSTOPRO								(0x1u<<1)
#define	ETHERNET_MMC_CONTROL_CNTRST									(0x1u<<0)

// MMC_RX_INTERRUPT Configuration

#define	ETHERNET_MMC_RX_INTERRUPT_RXLPITRCIS						(0x1u<<27)
#define	ETHERNET_MMC_RX_INTERRUPT_RXLPIUSCIS						(0x1u<<26)
#define	ETHERNET_MMC_RX_INTERRUPT_RXUCGPIS							(0x1u<<17)
#define	ETHERNET_MMC_RX_INTERRUPT_RXALGNERPIS						(0x1u<<6)
#define	ETHERNET_MMC_RX_INTERRUPT_RXCRCERPIS						(0x1u<<5)

// MMC_TX_INTERRUPT Configuration

#define	ETHERNET_MMC_TX_INTERRUPT_TXLPITRCIS						(0x1u<<27)
#define	ETHERNET_MMC_TX_INTERRUPT_TXLPIUSCIS						(0x1u<<26)
#define	ETHERNET_MMC_TX_INTERRUPT_TXGPKTIS							(0x1u<<21)
#define	ETHERNET_MMC_TX_INTERRUPT_TXMCOLGPIS						(0x1u<<15)
#define	ETHERNET_MMC_TX_INTERRUPT_TXSCOLGPIS						(0x1u<<14)

// MMC_RX_INTERRUPT_MASK Configuration

#define	ETHERNET_MMC_RX_INTERRUPT_MASK_RXLPITRCIM					(0x1u<<27)
#define	ETHERNET_MMC_RX_INTERRUPT_MASK_RXLPIUSCIM					(0x1u<<26)
#define	ETHERNET_MMC_RX_INTERRUPT_MASK_RXUCGPIM						(0x1u<<17)
#define	ETHERNET_MMC_RX_INTERRUPT_MASK_RXALGNERPIM					(0x1u<<6)
#define	ETHERNET_MMC_RX_INTERRUPT_MASK_RXCRCERPIM					(0x1u<<5)

// MMC_TX_INTERRUPT_MASK Configuration

#define	ETHERNET_MMC_TX_INTERRUPT_MASK_TXLPITRCIM					(0x1u<<27)
#define	ETHERNET_MMC_TX_INTERRUPT_MASK_TXLPIUSCIM					(0x1u<<26)
#define	ETHERNET_MMC_TX_INTERRUPT_MASK_TXGPKTIM						(0x1u<<21)
#define	ETHERNET_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM					(0x1u<<15)
#define	ETHERNET_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM					(0x1u<<14)

// TX_SINGLE_COLLISION_GOOD_PACKETS Configuration

#define	ETHERNET_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG		(0xFFFFFFFFu<<0)
#define	ETHERNET_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_0		(0x1u<<0)

// TX_MULTIPLE_COLLISION_GOOD_PACKETS Configuration

#define	ETHERNET_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG		(0xFFFFFFFFu<<0)
#define	ETHERNET_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_0	(0x1u<<0)

// TX_PACKET_COUNT_GOOD Configuration

#define	ETHERNET_TX_PACKET_COUNT_GOOD_TXPKTG						(0xFFFFFFFFu<<0)
#define	ETHERNET_TX_PACKET_COUNT_GOOD_TXPKTG_0						(0x1u<<0)

// RX_CRC_ERROR_PACKETS Configuration

#define	ETHERNET_RX_CRC_ERROR_PACKETS_RXCRCERR						(0xFFFFFFFFu<<0)
#define	ETHERNET_RX_CRC_ERROR_PACKETS_RXCRCERR_0					(0x1u<<0)

// RX_ALIGNMENT_ERROR_PACKETS Configuration

#define	ETHERNET_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR				(0xFFFFFFFFu<<0)
#define	ETHERNET_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_0				(0x1u<<0)

// RX_UNICAST_PACKETS_GOOD Configuration

#define	ETHERNET_RX_UNICAST_PACKETS_GOOD_RXUCASTG					(0xFFFFFFFFu<<0)
#define	ETHERNET_RX_UNICAST_PACKETS_GOOD_RXUCASTG_0					(0x1u<<0)

// TX_LPI_USEC_CNTR Configuration

#define	ETHERNET_TX_LPI_USEC_CNTR_TXLPIUSC							(0xFFFFFFFFu<<0)
#define	ETHERNET_TX_LPI_USEC_CNTR_TXLPIUSC_0						(0x1u<<0)

// TX_LPI_TRAN_CNTR Configuration

#define	ETHERNET_TX_LPI_TRAN_CNTR_TXLPITRC							(0xFFFFFFFFu<<0)
#define	ETHERNET_TX_LPI_TRAN_CNTR_TXLPITRC_0						(0x1u<<0)

// RX_LPI_USEC_CNTR Configuration

#define	ETHERNET_RX_LPI_USEC_CNTR_RXLPIUSC							(0xFFFFFFFFu<<0)
#define	ETHERNET_RX_LPI_USEC_CNTR_RXLPIUSC_0						(0x1u<<0)

// RX_LPI_TRAN_CNTR Configuration

#define	ETHERNET_RX_LPI_TRAN_CNTR_RXLPITRC							(0xFFFFFFFFu<<0)
#define	ETHERNET_RX_LPI_TRAN_CNTR_RXLPITRC_0						(0x1u<<0)

// MACL3L4C0R Configuration

#define	ETHERNET_MACL3L4C0R_L4DPIM0									(0x1u<<21)
#define	ETHERNET_MACL3L4C0R_L4DPM0									(0x1u<<20)
#define	ETHERNET_MACL3L4C0R_L4SPIM0									(0x1u<<19)
#define	ETHERNET_MACL3L4C0R_L4SPM0									(0x1u<<18)
#define	ETHERNET_MACL3L4C0R_L4PEN0									(0x1u<<16)
#define	ETHERNET_MACL3L4C0R_L3HDBM0									(0x1Fu<<11)
#define	ETHERNET_MACL3L4C0R_L3HDBM0_0								(0x1u<<11)
#define	ETHERNET_MACL3L4C0R_L3HSBM0									(0x1Fu<<6)
#define	ETHERNET_MACL3L4C0R_L3HSBM0_0								(0x1u<<6)
#define	ETHERNET_MACL3L4C0R_L3DAIM0									(0x1u<<5)
#define	ETHERNET_MACL3L4C0R_L3DAM0									(0x1u<<4)
#define	ETHERNET_MACL3L4C0R_L3SAIM0									(0x1u<<3)
#define	ETHERNET_MACL3L4C0R_L3SAM0									(0x1u<<2)
#define	ETHERNET_MACL3L4C0R_L3PEN0									(0x1u<<0)

// MACL4A0R Configuration

#define	ETHERNET_MACL4A0R_L4DP0										(0xFFFFu<<16)
#define	ETHERNET_MACL4A0R_L4DP0_0									(0x1u<<16)
#define	ETHERNET_MACL4A0R_L4SP0										(0xFFFFu<<0)
#define	ETHERNET_MACL4A0R_L4SP0_0									(0x1u<<0)

// MACL3A00R Configuration

#define	ETHERNET_MACL3A00R_L3A00									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACL3A00R_L3A00_0									(0x1u<<0)

// MACL3A10R Configuration

#define	ETHERNET_MACL3A10R_L3A10									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACL3A10R_L3A10_0									(0x1u<<0)

// MACL3A20 Configuration

#define	ETHERNET_MACL3A20_L3A20										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACL3A20_L3A20_0									(0x1u<<0)

// MACL3A30 Configuration

#define	ETHERNET_MACL3A30_L3A30										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACL3A30_L3A30_0									(0x1u<<0)

// MACL3L4C1R Configuration

#define	ETHERNET_MACL3L4C1R_L4DPIM1									(0x1u<<21)
#define	ETHERNET_MACL3L4C1R_L4DPM1									(0x1u<<20)
#define	ETHERNET_MACL3L4C1R_L4SPIM1									(0x1u<<19)
#define	ETHERNET_MACL3L4C1R_L4SPM1									(0x1u<<18)
#define	ETHERNET_MACL3L4C1R_L4PEN1									(0x1u<<16)
#define	ETHERNET_MACL3L4C1R_L3HDBM1									(0x1Fu<<11)
#define	ETHERNET_MACL3L4C1R_L3HDBM1_0								(0x1u<<11)
#define	ETHERNET_MACL3L4C1R_L3HSBM1									(0x1Fu<<6)
#define	ETHERNET_MACL3L4C1R_L3HSBM1_0								(0x1u<<6)
#define	ETHERNET_MACL3L4C1R_L3DAIM1									(0x1u<<5)
#define	ETHERNET_MACL3L4C1R_L3DAM1									(0x1u<<4)
#define	ETHERNET_MACL3L4C1R_L3SAIM1									(0x1u<<3)
#define	ETHERNET_MACL3L4C1R_L3SAM1									(0x1u<<2)
#define	ETHERNET_MACL3L4C1R_L3PEN1									(0x1u<<0)

// MACL4A1R Configuration

#define	ETHERNET_MACL4A1R_L4DP1										(0xFFFFu<<16)
#define	ETHERNET_MACL4A1R_L4DP1_0									(0x1u<<16)
#define	ETHERNET_MACL4A1R_L4SP1										(0xFFFFu<<0)
#define	ETHERNET_MACL4A1R_L4SP1_0									(0x1u<<0)

// MACL3A01R Configuration

#define	ETHERNET_MACL3A01R_L3A01									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACL3A01R_L3A01_0									(0x1u<<0)

// MACL3A11R Configuration

#define	ETHERNET_MACL3A11R_L3A11									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACL3A11R_L3A11_0									(0x1u<<0)

// MACL3A21R Configuration

#define	ETHERNET_MACL3A21R_L3A21									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACL3A21R_L3A21_0									(0x1u<<0)

// MACL3A31R Configuration

#define	ETHERNET_MACL3A31R_L3A31									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACL3A31R_L3A31_0									(0x1u<<0)

// MACARPAR Configuration

#define	ETHERNET_MACARPAR_ARPPA										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACARPAR_ARPPA_0									(0x1u<<0)

// MACTSCR Configuration

#define	ETHERNET_MACTSCR_TXTSSTSM									(0x1u<<24)
#define	ETHERNET_MACTSCR_CSC										(0x1u<<19)
#define	ETHERNET_MACTSCR_TSENMACADDR								(0x1u<<18)
#define	ETHERNET_MACTSCR_SNAPTYPSEL									(0x3u<<16)
#define	ETHERNET_MACTSCR_SNAPTYPSEL_0								(0x1u<<16)
#define	ETHERNET_MACTSCR_TSMSTRENA									(0x1u<<15)
#define	ETHERNET_MACTSCR_TSEVNTENA									(0x1u<<14)
#define	ETHERNET_MACTSCR_TSIPV4ENA									(0x1u<<13)
#define	ETHERNET_MACTSCR_TSIPV6ENA									(0x1u<<12)
#define	ETHERNET_MACTSCR_TSIPENA									(0x1u<<11)
#define	ETHERNET_MACTSCR_TSVER2ENA									(0x1u<<10)
#define	ETHERNET_MACTSCR_TSCTRLSSR									(0x1u<<9)
#define	ETHERNET_MACTSCR_TSENALL									(0x1u<<8)
#define	ETHERNET_MACTSCR_TSADDREG									(0x1u<<5)
#define	ETHERNET_MACTSCR_TSUPDT										(0x1u<<3)
#define	ETHERNET_MACTSCR_TSINIT										(0x1u<<2)
#define	ETHERNET_MACTSCR_TSCFUPDT									(0x1u<<1)
#define	ETHERNET_MACTSCR_TSENA										(0x1u<<0)

// MACSSIR Configuration

#define	ETHERNET_MACSSIR_SSINC										(0xFFu<<16)
#define	ETHERNET_MACSSIR_SSINC_0									(0x1u<<16)
#define	ETHERNET_MACSSIR_SNSINC										(0xFFu<<8)
#define	ETHERNET_MACSSIR_SNSINC_0									(0x1u<<8)

// MACSTSR Configuration

#define	ETHERNET_MACSTSR_TSS										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACSTSR_TSS_0										(0x1u<<0)

// MACSTNR Configuration

#define	ETHERNET_MACSTNR_TSSS										(0x7FFFFFFFu<<0)
#define	ETHERNET_MACSTNR_TSSS_0										(0x1u<<0)

// MACSTSUR Configuration

#define	ETHERNET_MACSTSUR_TSS										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACSTSUR_TSS_0										(0x1u<<0)

// MACSTNUR Configuration

#define	ETHERNET_MACSTNUR_ADDSUB									(0x1u<<31)
#define	ETHERNET_MACSTNUR_TSSS										(0x7FFFFFFFu<<0)
#define	ETHERNET_MACSTNUR_TSSS_0									(0x1u<<0)

// MACTSAR Configuration

#define	ETHERNET_MACTSAR_TSAR										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACTSAR_TSAR_0										(0x1u<<0)

// MACTSSR Configuration

#define	ETHERNET_MACTSSR_ATSNS										(0x1Fu<<25)
#define	ETHERNET_MACTSSR_ATSNS_0									(0x1u<<25)
#define	ETHERNET_MACTSSR_ATSSTM										(0x1u<<24)
#define	ETHERNET_MACTSSR_ATSSTN										(0xFu<<16)
#define	ETHERNET_MACTSSR_ATSSTN_0									(0x1u<<16)
#define	ETHERNET_MACTSSR_TXTSSIS									(0x1u<<15)
#define	ETHERNET_MACTSSR_TSTRGTERR0									(0x1u<<3)
#define	ETHERNET_MACTSSR_AUXTSTRIG									(0x1u<<2)
#define	ETHERNET_MACTSSR_TSTARGT0									(0x1u<<1)
#define	ETHERNET_MACTSSR_TSSOVF										(0x1u<<0)

// MACTXTSSNR Configuration

#define	ETHERNET_MACTXTSSNR_TXTSSMIS								(0x1u<<31)
#define	ETHERNET_MACTXTSSNR_TXTSSLO									(0x7FFFFFFFu<<0)
#define	ETHERNET_MACTXTSSNR_TXTSSLO_0								(0x1u<<0)

// MACTXTSSSR Configuration

#define	ETHERNET_MACTXTSSSR_TXTSSHI									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACTXTSSSR_TXTSSHI_0								(0x1u<<0)

// MACACR Configuration

#define	ETHERNET_MACACR_ATSEN3										(0x1u<<7)
#define	ETHERNET_MACACR_ATSEN2										(0x1u<<6)
#define	ETHERNET_MACACR_ATSEN1										(0x1u<<5)
#define	ETHERNET_MACACR_ATSEN0										(0x1u<<4)
#define	ETHERNET_MACACR_ATSFC										(0x1u<<0)

// MACATSNR Configuration

#define	ETHERNET_MACATSNR_AUXTSLO									(0x7FFFFFFFu<<0)
#define	ETHERNET_MACATSNR_AUXTSLO_0									(0x1u<<0)

// MACATSSR Configuration

#define	ETHERNET_MACATSSR_AUXTSHI									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACATSSR_AUXTSHI_0									(0x1u<<0)

// MACTSIACR Configuration

#define	ETHERNET_MACTSIACR_OSTIAC									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACTSIACR_OSTIAC_0									(0x1u<<0)

// MACTSEACR Configuration

#define	ETHERNET_MACTSEACR_OSTEAC									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACTSEACR_OSTEAC_0									(0x1u<<0)

// MACTSICNR Configuration

#define	ETHERNET_MACTSICNR_TSIC										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACTSICNR_TSIC_0									(0x1u<<0)

// MACTSECNR Configuration

#define	ETHERNET_MACTSECNR_TSEC										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACTSECNR_TSEC_0									(0x1u<<0)

// MACPPSCR Configuration

#define	ETHERNET_MACPPSCR_TRGTMODSEL0								(0x3u<<5)
#define	ETHERNET_MACPPSCR_TRGTMODSEL0_0								(0x1u<<5)
#define	ETHERNET_MACPPSCR_PPSEN0									(0x1u<<4)
#define	ETHERNET_MACPPSCR_PPSCTRL									(0xFu<<0)
#define	ETHERNET_MACPPSCR_PPSCTRL_0									(0x1u<<0)

// MACPPSTTSR Configuration

#define	ETHERNET_MACPPSTTSR_TSTRH0									(0x7FFFFFFFu<<0)
#define	ETHERNET_MACPPSTTSR_TSTRH0_0								(0x1u<<0)

// MACPPSTTNR Configuration

#define	ETHERNET_MACPPSTTNR_TRGTBUSY0								(0x1u<<31)
#define	ETHERNET_MACPPSTTNR_TTSL0									(0x7FFFFFFFu<<0)
#define	ETHERNET_MACPPSTTNR_TTSL0_0									(0x1u<<0)

// MACPPSIR Configuration

#define	ETHERNET_MACPPSIR_PPSINT0									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACPPSIR_PPSINT0_0									(0x1u<<0)

// MACPPSWR Configuration

#define	ETHERNET_MACPPSWR_PPSWIDTH0									(0xFFFFFFFFu<<0)
#define	ETHERNET_MACPPSWR_PPSWIDTH0_0								(0x1u<<0)

// MACPOCR Configuration

#define	ETHERNET_MACPOCR_DN											(0xFFu<<8)
#define	ETHERNET_MACPOCR_DN_0										(0x1u<<8)
#define	ETHERNET_MACPOCR_DRRDIS										(0x1u<<6)
#define	ETHERNET_MACPOCR_APDREQTRIG									(0x1u<<5)
#define	ETHERNET_MACPOCR_ASYNCTRIG									(0x1u<<4)
#define	ETHERNET_MACPOCR_APDREQEN									(0x1u<<2)
#define	ETHERNET_MACPOCR_ASYNCEN									(0x1u<<1)
#define	ETHERNET_MACPOCR_PTOEN										(0x1u<<0)

// MACSPI0R Configuration

#define	ETHERNET_MACSPI0R_SPI0										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACSPI0R_SPI0_0									(0x1u<<0)

// MACSPI1R Configuration

#define	ETHERNET_MACSPI1R_SPI1										(0xFFFFFFFFu<<0)
#define	ETHERNET_MACSPI1R_SPI1_0									(0x1u<<0)

// MACSPI2R Configuration

#define	ETHERNET_MACSPI2R_SPI2										(0xFFFFu<<0)
#define	ETHERNET_MACSPI2R_SPI2_0									(0x1u<<0)

// MACLMIR Configuration

#define	ETHERNET_MACLMIR_LMPDRI										(0xFFu<<24)
#define	ETHERNET_MACLMIR_LMPDRI_0									(0x1u<<24)
#define	ETHERNET_MACLMIR_DRSYNCR									(0x7u<<8)
#define	ETHERNET_MACLMIR_DRSYNCR_0									(0x1u<<8)
#define	ETHERNET_MACLMIR_LSI										(0xFFu<<0)
#define	ETHERNET_MACLMIR_LSI_0										(0x1u<<0)

// MTLOMR Configuration

#define	ETHERNET_MTLOMR_CNTCLR										(0x1u<<9)
#define	ETHERNET_MTLOMR_CNTPRST										(0x1u<<8)
#define	ETHERNET_MTLOMR_DTXSTS										(0x1u<<1)

// MTLISR Configuration

#define	ETHERNET_MTLISR_Q0IS										(0x1u<<0)

// MTLTXQOMR Configuration

#define	ETHERNET_MTLTXQOMR_TQS										(0x1FFu<<16)
#define	ETHERNET_MTLTXQOMR_TQS_0									(0x1u<<16)
#define	ETHERNET_MTLTXQOMR_TTC										(0x7u<<4)
#define	ETHERNET_MTLTXQOMR_TTC_0									(0x1u<<4)
#define	ETHERNET_MTLTXQOMR_TXQEN									(0x3u<<2)
#define	ETHERNET_MTLTXQOMR_TXQEN_0									(0x1u<<2)
#define	ETHERNET_MTLTXQOMR_TSF										(0x1u<<1)
#define	ETHERNET_MTLTXQOMR_FTQ										(0x1u<<0)

// MTLTXQUR Configuration

#define	ETHERNET_MTLTXQUR_UFCNTOVF									(0x1u<<11)
#define	ETHERNET_MTLTXQUR_UFFRMCNT									(0x7FFu<<0)
#define	ETHERNET_MTLTXQUR_UFFRMCNT_0								(0x1u<<0)

// MTLTXQDR Configuration

#define	ETHERNET_MTLTXQDR_STXSTSF									(0x7u<<20)
#define	ETHERNET_MTLTXQDR_STXSTSF_0									(0x1u<<20)
#define	ETHERNET_MTLTXQDR_PTXQ										(0x7u<<16)
#define	ETHERNET_MTLTXQDR_PTXQ_0									(0x1u<<16)
#define	ETHERNET_MTLTXQDR_TXSTSFSTS									(0x1u<<5)
#define	ETHERNET_MTLTXQDR_TXQSTS									(0x1u<<4)
#define	ETHERNET_MTLTXQDR_TWCSTS									(0x1u<<3)
#define	ETHERNET_MTLTXQDR_TRCSTS									(0x3u<<1)
#define	ETHERNET_MTLTXQDR_TRCSTS_0									(0x1u<<1)
#define	ETHERNET_MTLTXQDR_TXQPAUSED									(0x1u<<0)

// MTLQICSR Configuration

#define	ETHERNET_MTLQICSR_RXOIE										(0x1u<<24)
#define	ETHERNET_MTLQICSR_RXOVFIS									(0x1u<<16)
#define	ETHERNET_MTLQICSR_TXUIE										(0x1u<<8)
#define	ETHERNET_MTLQICSR_TXUNFIS									(0x1u<<0)

// MTLRXQOMR Configuration

#define	ETHERNET_MTLRXQOMR_RQS										(0x7u<<20)
#define	ETHERNET_MTLRXQOMR_RQS_0									(0x1u<<20)
#define	ETHERNET_MTLRXQOMR_RFD										(0x7u<<14)
#define	ETHERNET_MTLRXQOMR_RFD_0									(0x1u<<14)
#define	ETHERNET_MTLRXQOMR_RFA										(0x7u<<8)
#define	ETHERNET_MTLRXQOMR_RFA_0									(0x1u<<8)
#define	ETHERNET_MTLRXQOMR_EHFC										(0x1u<<7)
#define	ETHERNET_MTLRXQOMR_DIS_TCP_EF								(0x1u<<6)
#define	ETHERNET_MTLRXQOMR_RSF										(0x1u<<5)
#define	ETHERNET_MTLRXQOMR_FEP										(0x1u<<4)
#define	ETHERNET_MTLRXQOMR_FUP										(0x1u<<3)
#define	ETHERNET_MTLRXQOMR_RTC										(0x3u<<0)
#define	ETHERNET_MTLRXQOMR_RTC_0									(0x1u<<0)

// MTLRXQMPOCR Configuration

#define	ETHERNET_MTLRXQMPOCR_MISCNTOVF								(0x1u<<27)
#define	ETHERNET_MTLRXQMPOCR_MISPKTCNT								(0x7FFu<<16)
#define	ETHERNET_MTLRXQMPOCR_MISPKTCNT_0							(0x1u<<16)
#define	ETHERNET_MTLRXQMPOCR_OVFCNTOVF								(0x1u<<11)
#define	ETHERNET_MTLRXQMPOCR_OVFPKTCNT								(0x7FFu<<0)
#define	ETHERNET_MTLRXQMPOCR_OVFPKTCNT_0							(0x1u<<0)

// MTLRXQDR Configuration

#define	ETHERNET_MTLRXQDR_PRXQ										(0x3FFFu<<16)
#define	ETHERNET_MTLRXQDR_PRXQ_0									(0x1u<<16)
#define	ETHERNET_MTLRXQDR_RXQSTS									(0x3u<<4)
#define	ETHERNET_MTLRXQDR_RXQSTS_0									(0x1u<<4)
#define	ETHERNET_MTLRXQDR_RRCSTS									(0x3u<<1)
#define	ETHERNET_MTLRXQDR_RRCSTS_0									(0x1u<<1)
#define	ETHERNET_MTLRXQDR_RWCSTS									(0x1u<<0)

// DMAMR Configuration

#define	ETHERNET_DMAMR_INTM											(0x1u<<16)
#define	ETHERNET_DMAMR_PR											(0x7u<<12)
#define	ETHERNET_DMAMR_PR_0											(0x1u<<12)
#define	ETHERNET_DMAMR_TXPR											(0x1u<<11)
#define	ETHERNET_DMAMR_DA											(0x1u<<1)
#define	ETHERNET_DMAMR_SWR											(0x1u<<0)

// DMASBMR Configuration

#define	ETHERNET_DMASBMR_RB											(0x1u<<15)
#define	ETHERNET_DMASBMR_MB											(0x1u<<14)
#define	ETHERNET_DMASBMR_AAL										(0x1u<<12)
#define	ETHERNET_DMASBMR_FB											(0x1u<<0)

// DMAISR Configuration

#define	ETHERNET_DMAISR_MACIS										(0x1u<<17)
#define	ETHERNET_DMAISR_MTLIS										(0x1u<<16)
#define	ETHERNET_DMAISR_DC0IS										(0x1u<<0)

// DMADSR Configuration

#define	ETHERNET_DMADSR_TPS0										(0xFu<<12)
#define	ETHERNET_DMADSR_TPS0_0										(0x1u<<12)
#define	ETHERNET_DMADSR_RPS0										(0xFu<<8)
#define	ETHERNET_DMADSR_RPS0_0										(0x1u<<8)
#define	ETHERNET_DMADSR_AXWHSTS										(0x1u<<0)

// DMACCR Configuration

#define	ETHERNET_DMACCR_DSL											(0x7u<<18)
#define	ETHERNET_DMACCR_DSL_0										(0x1u<<18)
#define	ETHERNET_DMACCR_PBLX8										(0x1u<<16)
#define	ETHERNET_DMACCR_MSS											(0x3FFFu<<0)
#define	ETHERNET_DMACCR_MSS_0										(0x1u<<0)

// DMACTXCR Configuration

#define	ETHERNET_DMACTXCR_TXPBL										(0x3Fu<<16)
#define	ETHERNET_DMACTXCR_TXPBL_0									(0x1u<<16)
#define	ETHERNET_DMACTXCR_TSE										(0x1u<<12)
#define	ETHERNET_DMACTXCR_OSF										(0x1u<<4)
#define	ETHERNET_DMACTXCR_ST										(0x1u<<0)

// DMACRXCR Configuration

#define	ETHERNET_DMACRXCR_RPF										(0x1u<<31)
#define	ETHERNET_DMACRXCR_RXPBL										(0x3Fu<<16)
#define	ETHERNET_DMACRXCR_RXPBL_0									(0x1u<<16)
#define	ETHERNET_DMACRXCR_RBSZ										(0x3FFFu<<1)
#define	ETHERNET_DMACRXCR_RBSZ_0									(0x1u<<1)
#define	ETHERNET_DMACRXCR_SR										(0x1u<<0)

// DMACTXDLAR Configuration

#define	ETHERNET_DMACTXDLAR_TDESLA									(0x3FFFFFFFu<<2)
#define	ETHERNET_DMACTXDLAR_TDESLA_0								(0x1u<<2)

// DMACRXDLAR Configuration

#define	ETHERNET_DMACRXDLAR_RDESLA									(0x3FFFFFFFu<<2)
#define	ETHERNET_DMACRXDLAR_RDESLA_0								(0x1u<<2)

// DMACTXDTPR Configuration

#define	ETHERNET_DMACTXDTPR_TDT										(0x3FFFFFFFu<<2)
#define	ETHERNET_DMACTXDTPR_TDT_0									(0x1u<<2)

// DMACRXDTPR Configuration

#define	ETHERNET_DMACRXDTPR_RDT										(0x3FFFFFFFu<<2)
#define	ETHERNET_DMACRXDTPR_RDT_0									(0x1u<<2)

// DMACTXRLR Configuration

#define	ETHERNET_DMACTXRLR_TDRL										(0x3FFu<<0)
#define	ETHERNET_DMACTXRLR_TDRL_0									(0x1u<<0)

// DMACRXRLR Configuration

#define	ETHERNET_DMACRXRLR_RDRL										(0x3FFu<<0)
#define	ETHERNET_DMACRXRLR_RDRL_0									(0x1u<<0)

// DMACIER Configuration

#define	ETHERNET_DMACIER_NIE										(0x1u<<15)
#define	ETHERNET_DMACIER_AIE										(0x1u<<14)
#define	ETHERNET_DMACIER_CDEE										(0x1u<<13)
#define	ETHERNET_DMACIER_FBEE										(0x1u<<12)
#define	ETHERNET_DMACIER_ERIE										(0x1u<<11)
#define	ETHERNET_DMACIER_ETIE										(0x1u<<10)
#define	ETHERNET_DMACIER_RWTE										(0x1u<<9)
#define	ETHERNET_DMACIER_RSE										(0x1u<<8)
#define	ETHERNET_DMACIER_RBUE										(0x1u<<7)
#define	ETHERNET_DMACIER_RIE										(0x1u<<6)
#define	ETHERNET_DMACIER_TBUE										(0x1u<<2)
#define	ETHERNET_DMACIER_TXSE										(0x1u<<1)
#define	ETHERNET_DMACIER_TIE										(0x1u<<0)

// DMACRXIWTR Configuration

#define	ETHERNET_DMACRXIWTR_RWT										(0xFFu<<0)
#define	ETHERNET_DMACRXIWTR_RWT_0									(0x1u<<0)

// DMACCATXDR Configuration

#define	ETHERNET_DMACCATXDR_CURTDESAPTR								(0xFFFFFFFFu<<0)
#define	ETHERNET_DMACCATXDR_CURTDESAPTR_0							(0x1u<<0)

// DMACCARXDR Configuration

#define	ETHERNET_DMACCARXDR_CURRDESAPTR								(0xFFFFFFFFu<<0)
#define	ETHERNET_DMACCARXDR_CURRDESAPTR_0							(0x1u<<0)

// DMACCATXBR Configuration

#define	ETHERNET_DMACCATXBR_CURTBUFAPTR								(0xFFFFFFFFu<<0)
#define	ETHERNET_DMACCATXBR_CURTBUFAPTR_0							(0x1u<<0)

// DMACCARXBR Configuration

#define	ETHERNET_DMACCARXBR_CURRBUFAPTR								(0xFFFFFFFFu<<0)
#define	ETHERNET_DMACCARXBR_CURRBUFAPTR_0							(0x1u<<0)

// DMACSR Configuration

#define	ETHERNET_DMACSR_REB											(0x7u<<19)
#define	ETHERNET_DMACSR_REB_0										(0x1u<<19)
#define	ETHERNET_DMACSR_TEB											(0x7u<<16)
#define	ETHERNET_DMACSR_TEB_0										(0x1u<<16)
#define	ETHERNET_DMACSR_NIS											(0x1u<<15)
#define	ETHERNET_DMACSR_AIS											(0x1u<<14)
#define	ETHERNET_DMACSR_CDE											(0x1u<<13)
#define	ETHERNET_DMACSR_FBE											(0x1u<<12)
#define	ETHERNET_DMACSR_ER											(0x1u<<11)
#define	ETHERNET_DMACSR_ET											(0x1u<<10)
#define	ETHERNET_DMACSR_RWT											(0x1u<<9)
#define	ETHERNET_DMACSR_RPS											(0x1u<<8)
#define	ETHERNET_DMACSR_RBU											(0x1u<<7)
#define	ETHERNET_DMACSR_RI											(0x1u<<6)
#define	ETHERNET_DMACSR_TBU											(0x1u<<2)
#define	ETHERNET_DMACSR_TPS											(0x1u<<1)
#define	ETHERNET_DMACSR_TI											(0x1u<<0)

// DMACMFCR Configuration

#define	ETHERNET_DMACMFCR_MFCO										(0x1u<<15)
#define	ETHERNET_DMACMFCR_MFC										(0x7FFu<<0)
#define	ETHERNET_DMACMFCR_MFC_0										(0x1u<<0)
