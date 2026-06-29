/*
; stm32N657_ucpd.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_ucpd equates.
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

// UCPD address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CFGR1;
	volatile	uint32_t	CFGR2;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	CR;
	volatile	uint32_t	IMR;
	volatile	uint32_t	SR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	TX_ORDSETR;
	volatile	uint32_t	TX_PAYSZR;
	volatile	uint32_t	TXDR;
	volatile	uint32_t	RX_ORDSETR;
	volatile	uint32_t	RX_PAYSZR;
	volatile	uint32_t	RXDR;
	volatile	uint32_t	RX_ORDEXTR1;
	volatile	uint32_t	RX_ORDEXTR2;
} UCPD_TypeDef;

#if (defined(__cplusplus))
#define	UCPD_NS	reinterpret_cast<UCPD_TypeDef *>(0x4000FC00u)
#define	UCPD_S	reinterpret_cast<UCPD_TypeDef *>(0x5000FC00u)

#else
#define	UCPD_NS	((UCPD_TypeDef *)0x4000FC00u)
#define	UCPD_S	((UCPD_TypeDef *)0x5000FC00u)
#endif

// CFGR1 Configuration

#define	UCPD_CFGR1_UCPDEN						(0x1u<<31)
#define	UCPD_CFGR1_RXDMAEN						(0x1u<<30)
#define	UCPD_CFGR1_TXDMAEN						(0x1u<<29)
#define	UCPD_CFGR1_RXORDSETEN					(0x1FFu<<20)
#define	UCPD_CFGR1_RXORDSETEN_0					(0x1u<<20)
#define	UCPD_CFGR1_PSC_USBPDCLK					(0x7u<<17)
#define	UCPD_CFGR1_PSC_USBPDCLK_0				(0x1u<<17)
#define	UCPD_CFGR1_TRANSWIN						(0x1Fu<<11)
#define	UCPD_CFGR1_TRANSWIN_0					(0x1u<<11)
#define	UCPD_CFGR1_IFRGAP						(0x1Fu<<6)
#define	UCPD_CFGR1_IFRGAP_0						(0x1u<<6)
#define	UCPD_CFGR1_HBITCLKDIV					(0x3Fu<<0)
#define	UCPD_CFGR1_HBITCLKDIV_0					(0x1u<<0)

#define	UCPD_CFGR1_UCPDEN_B_0X0					(0x0u<<31)
#define	UCPD_CFGR1_UCPDEN_B_0X1					(0x1u<<31)
#define	UCPD_CFGR1_RXDMAEN_B_0X0				(0x0u<<30)
#define	UCPD_CFGR1_RXDMAEN_B_0X1				(0x1u<<30)
#define	UCPD_CFGR1_TXDMAEN_B_0X0				(0x0u<<29)
#define	UCPD_CFGR1_TXDMAEN_B_0X1				(0x1u<<29)
#define	UCPD_CFGR1_PSC_USBPDCLK_B_0X0			(0x0u<<17)
#define	UCPD_CFGR1_PSC_USBPDCLK_B_0X1			(0x1u<<17)
#define	UCPD_CFGR1_PSC_USBPDCLK_B_0X2			(0x2u<<17)
#define	UCPD_CFGR1_PSC_USBPDCLK_B_0X3			(0x3u<<17)
#define	UCPD_CFGR1_PSC_USBPDCLK_B_0X4			(0x4u<<17)
#define	UCPD_CFGR1_TRANSWIN_B_0X00				(0x0u<<11)
#define	UCPD_CFGR1_TRANSWIN_B_0X01				(0x1u<<11)
#define	UCPD_CFGR1_TRANSWIN_B_0X09				(0x9u<<11)
#define	UCPD_CFGR1_TRANSWIN_B_0X1F				(0x1Fu<<11)
#define	UCPD_CFGR1_IFRGAP_B_0X00				(0x0u<<6)
#define	UCPD_CFGR1_IFRGAP_B_0X01				(0x1u<<6)
#define	UCPD_CFGR1_IFRGAP_B_0X0D				(0xDu<<6)
#define	UCPD_CFGR1_IFRGAP_B_0X0E				(0xEu<<6)
#define	UCPD_CFGR1_IFRGAP_B_0X0F				(0xFu<<6)
#define	UCPD_CFGR1_IFRGAP_B_0X1F				(0x1Fu<<6)
#define	UCPD_CFGR1_HBITCLKDIV_B_0X00			(0x0u<<0)
#define	UCPD_CFGR1_HBITCLKDIV_B_0X1A			(0x1Au<<0)
#define	UCPD_CFGR1_HBITCLKDIV_B_0X3F			(0x3Fu<<0)

// CFGR2 Configuration

#define	UCPD_CFGR2_WUPEN						(0x1u<<3)
#define	UCPD_CFGR2_FORCECLK						(0x1u<<2)
#define	UCPD_CFGR2_RXFILT2N3					(0x1u<<1)
#define	UCPD_CFGR2_RXFILTDIS					(0x1u<<0)

#define	UCPD_CFGR2_WUPEN_B_0X0					(0x0u<<3)
#define	UCPD_CFGR2_WUPEN_B_0X1					(0x1u<<3)
#define	UCPD_CFGR2_FORCECLK_B_0X0				(0x0u<<2)
#define	UCPD_CFGR2_FORCECLK_B_0X1				(0x1u<<2)
#define	UCPD_CFGR2_RXFILT2N3_B_0X0				(0x0u<<1)
#define	UCPD_CFGR2_RXFILT2N3_B_0X1				(0x1u<<1)
#define	UCPD_CFGR2_RXFILTDIS_B_0X0				(0x0u<<0)
#define	UCPD_CFGR2_RXFILTDIS_B_0X1				(0x1u<<0)

// CR Configuration

#define	UCPD_CR_CC2TCDIS						(0x1u<<21)
#define	UCPD_CR_CC1TCDIS						(0x1u<<20)
#define	UCPD_CR_RDCH							(0x1u<<18)
#define	UCPD_CR_FRSTX							(0x1u<<17)
#define	UCPD_CR_FRSRXEN							(0x1u<<16)
#define	UCPD_CR_CCENABLE						(0x3u<<10)
#define	UCPD_CR_CCENABLE_0						(0x1u<<10)
#define	UCPD_CR_ANAMODE							(0x1u<<9)
#define	UCPD_CR_ANASUBMODE						(0x3u<<7)
#define	UCPD_CR_ANASUBMODE_0					(0x1u<<7)
#define	UCPD_CR_PHYCCSEL						(0x1u<<6)
#define	UCPD_CR_PHYRXEN							(0x1u<<5)
#define	UCPD_CR_RXMODE							(0x1u<<4)
#define	UCPD_CR_TXHRST							(0x1u<<3)
#define	UCPD_CR_TXSEND							(0x1u<<2)
#define	UCPD_CR_TXMODE							(0x3u<<0)
#define	UCPD_CR_TXMODE_0						(0x1u<<0)

#define	UCPD_CR_CC2TCDIS_B_0X0					(0x0u<<21)
#define	UCPD_CR_CC2TCDIS_B_0X1					(0x1u<<21)
#define	UCPD_CR_CC1TCDIS_B_0X0					(0x0u<<20)
#define	UCPD_CR_CC1TCDIS_B_0X1					(0x1u<<20)
#define	UCPD_CR_RDCH_B_0X0						(0x0u<<18)
#define	UCPD_CR_RDCH_B_0X1						(0x1u<<18)
#define	UCPD_CR_FRSTX_B_0X0						(0x0u<<17)
#define	UCPD_CR_FRSTX_B_0X1						(0x1u<<17)
#define	UCPD_CR_FRSRXEN_B_0X1					(0x1u<<16)
#define	UCPD_CR_CCENABLE_B_0X0					(0x0u<<10)
#define	UCPD_CR_CCENABLE_B_0X1					(0x1u<<10)
#define	UCPD_CR_CCENABLE_B_0X2					(0x2u<<10)
#define	UCPD_CR_CCENABLE_B_0X3					(0x3u<<10)
#define	UCPD_CR_ANAMODE_B_0X0					(0x0u<<9)
#define	UCPD_CR_ANAMODE_B_0X1					(0x1u<<9)
#define	UCPD_CR_PHYCCSEL_B_0X0					(0x0u<<6)
#define	UCPD_CR_PHYCCSEL_B_0X1					(0x1u<<6)
#define	UCPD_CR_PHYRXEN_B_0X0					(0x0u<<5)
#define	UCPD_CR_PHYRXEN_B_0X1					(0x1u<<5)
#define	UCPD_CR_RXMODE_B_0X0					(0x0u<<4)
#define	UCPD_CR_RXMODE_B_0X1					(0x1u<<4)
#define	UCPD_CR_TXHRST_B_0X0					(0x0u<<3)
#define	UCPD_CR_TXHRST_B_0X1					(0x1u<<3)
#define	UCPD_CR_TXSEND_B_0X0					(0x0u<<2)
#define	UCPD_CR_TXSEND_B_0X1					(0x1u<<2)
#define	UCPD_CR_TXMODE_B_0X0					(0x0u<<0)
#define	UCPD_CR_TXMODE_B_0X1					(0x1u<<0)
#define	UCPD_CR_TXMODE_B_0X2					(0x2u<<0)

// IMR Configuration

#define	UCPD_IMR_FRSEVTIE						(0x1u<<20)
#define	UCPD_IMR_TYPECEVT2IE					(0x1u<<15)
#define	UCPD_IMR_TYPECEVT1IE					(0x1u<<14)
#define	UCPD_IMR_RXMSGENDIE						(0x1u<<12)
#define	UCPD_IMR_RXOVRIE						(0x1u<<11)
#define	UCPD_IMR_RXHRSTDETIE					(0x1u<<10)
#define	UCPD_IMR_RXORDDETIE						(0x1u<<9)
#define	UCPD_IMR_RXNEIE							(0x1u<<8)
#define	UCPD_IMR_TXUNDIE						(0x1u<<6)
#define	UCPD_IMR_HRSTSENTIE						(0x1u<<5)
#define	UCPD_IMR_HRSTDISCIE						(0x1u<<4)
#define	UCPD_IMR_TXMSGABTIE						(0x1u<<3)
#define	UCPD_IMR_TXMSGSENTIE					(0x1u<<2)
#define	UCPD_IMR_TXMSGDISCIE					(0x1u<<1)
#define	UCPD_IMR_TXISIE							(0x1u<<0)

#define	UCPD_IMR_FRSEVTIE_B_0X0					(0x0u<<20)
#define	UCPD_IMR_FRSEVTIE_B_0X1					(0x1u<<20)
#define	UCPD_IMR_TYPECEVT2IE_B_0X0				(0x0u<<15)
#define	UCPD_IMR_TYPECEVT2IE_B_0X1				(0x1u<<15)
#define	UCPD_IMR_RXMSGENDIE_B_0X0				(0x0u<<12)
#define	UCPD_IMR_RXMSGENDIE_B_0X1				(0x1u<<12)
#define	UCPD_IMR_RXOVRIE_B_0X0					(0x0u<<11)
#define	UCPD_IMR_RXOVRIE_B_0X1					(0x1u<<11)
#define	UCPD_IMR_RXHRSTDETIE_B_0X0				(0x0u<<10)
#define	UCPD_IMR_RXHRSTDETIE_B_0X1				(0x1u<<10)
#define	UCPD_IMR_RXORDDETIE_B_0X0				(0x0u<<9)
#define	UCPD_IMR_RXORDDETIE_B_0X1				(0x1u<<9)
#define	UCPD_IMR_RXNEIE_B_0X0					(0x0u<<8)
#define	UCPD_IMR_RXNEIE_B_0X1					(0x1u<<8)
#define	UCPD_IMR_TXUNDIE_B_0X0					(0x0u<<6)
#define	UCPD_IMR_TXUNDIE_B_0X1					(0x1u<<6)
#define	UCPD_IMR_HRSTSENTIE_B_0X0				(0x0u<<5)
#define	UCPD_IMR_HRSTSENTIE_B_0X1				(0x1u<<5)
#define	UCPD_IMR_HRSTDISCIE_B_0X0				(0x0u<<4)
#define	UCPD_IMR_HRSTDISCIE_B_0X1				(0x1u<<4)
#define	UCPD_IMR_TXMSGABTIE_B_0X0				(0x0u<<3)
#define	UCPD_IMR_TXMSGABTIE_B_0X1				(0x1u<<3)
#define	UCPD_IMR_TXMSGSENTIE_B_0X0				(0x0u<<2)
#define	UCPD_IMR_TXMSGSENTIE_B_0X1				(0x1u<<2)
#define	UCPD_IMR_TXMSGDISCIE_B_0X0				(0x0u<<1)
#define	UCPD_IMR_TXMSGDISCIE_B_0X1				(0x1u<<1)
#define	UCPD_IMR_TXISIE_B_0X0					(0x0u<<0)
#define	UCPD_IMR_TXISIE_B_0X1					(0x1u<<0)

// SR Configuration

#define	UCPD_SR_FRSEVT							(0x1u<<20)
#define	UCPD_SR_TYPEC_VSTATE_CC2				(0x3u<<18)
#define	UCPD_SR_TYPEC_VSTATE_CC2_0				(0x1u<<18)
#define	UCPD_SR_TYPEC_VSTATE_CC1				(0x3u<<16)
#define	UCPD_SR_TYPEC_VSTATE_CC1_0				(0x1u<<16)
#define	UCPD_SR_TYPECEVT2						(0x1u<<15)
#define	UCPD_SR_TYPECEVT1						(0x1u<<14)
#define	UCPD_SR_RXERR							(0x1u<<13)
#define	UCPD_SR_RXMSGEND						(0x1u<<12)
#define	UCPD_SR_RXOVR							(0x1u<<11)
#define	UCPD_SR_RXHRSTDET						(0x1u<<10)
#define	UCPD_SR_RXORDDET						(0x1u<<9)
#define	UCPD_SR_RXNE							(0x1u<<8)
#define	UCPD_SR_TXUND							(0x1u<<6)
#define	UCPD_SR_HRSTSENT						(0x1u<<5)
#define	UCPD_SR_HRSTDISC						(0x1u<<4)
#define	UCPD_SR_TXMSGABT						(0x1u<<3)
#define	UCPD_SR_TXMSGSENT						(0x1u<<2)
#define	UCPD_SR_TXMSGDISC						(0x1u<<1)
#define	UCPD_SR_TXIS							(0x1u<<0)

#define	UCPD_SR_FRSEVT_B_0X0					(0x0u<<20)
#define	UCPD_SR_FRSEVT_B_0X1					(0x1u<<20)
#define	UCPD_SR_TYPEC_VSTATE_CC2_B_0X0			(0x0u<<18)
#define	UCPD_SR_TYPEC_VSTATE_CC2_B_0X1			(0x1u<<18)
#define	UCPD_SR_TYPEC_VSTATE_CC2_B_0X2			(0x2u<<18)
#define	UCPD_SR_TYPEC_VSTATE_CC2_B_0X3			(0x3u<<18)
#define	UCPD_SR_TYPEC_VSTATE_CC1_B_0X0			(0x0u<<16)
#define	UCPD_SR_TYPEC_VSTATE_CC1_B_0X1			(0x1u<<16)
#define	UCPD_SR_TYPEC_VSTATE_CC1_B_0X2			(0x2u<<16)
#define	UCPD_SR_TYPEC_VSTATE_CC1_B_0X3			(0x3u<<16)
#define	UCPD_SR_TYPECEVT2_B_0X0					(0x0u<<15)
#define	UCPD_SR_TYPECEVT2_B_0X1					(0x1u<<15)
#define	UCPD_SR_TYPECEVT1_B_0X0					(0x0u<<14)
#define	UCPD_SR_TYPECEVT1_B_0X1					(0x1u<<14)
#define	UCPD_SR_RXERR_B_0X0						(0x0u<<13)
#define	UCPD_SR_RXERR_B_0X1						(0x1u<<13)
#define	UCPD_SR_RXMSGEND_B_0X0					(0x0u<<12)
#define	UCPD_SR_RXMSGEND_B_0X1					(0x1u<<12)
#define	UCPD_SR_RXOVR_B_0X0						(0x0u<<11)
#define	UCPD_SR_RXOVR_B_0X1						(0x1u<<11)
#define	UCPD_SR_RXHRSTDET_B_0X0					(0x0u<<10)
#define	UCPD_SR_RXHRSTDET_B_0X1					(0x1u<<10)
#define	UCPD_SR_RXORDDET_B_0X0					(0x0u<<9)
#define	UCPD_SR_RXORDDET_B_0X1					(0x1u<<9)
#define	UCPD_SR_RXNE_B_0X0						(0x0u<<8)
#define	UCPD_SR_RXNE_B_0X1						(0x1u<<8)
#define	UCPD_SR_TXUND_B_0X0						(0x0u<<6)
#define	UCPD_SR_TXUND_B_0X1						(0x1u<<6)
#define	UCPD_SR_HRSTSENT_B_0X0					(0x0u<<5)
#define	UCPD_SR_HRSTSENT_B_0X1					(0x1u<<5)
#define	UCPD_SR_HRSTDISC_B_0X0					(0x0u<<4)
#define	UCPD_SR_HRSTDISC_B_0X1					(0x1u<<4)
#define	UCPD_SR_TXMSGABT_B_0X0					(0x0u<<3)
#define	UCPD_SR_TXMSGABT_B_0X1					(0x1u<<3)
#define	UCPD_SR_TXMSGSENT_B_0X0					(0x0u<<2)
#define	UCPD_SR_TXMSGSENT_B_0X1					(0x1u<<2)
#define	UCPD_SR_TXMSGDISC_B_0X0					(0x0u<<1)
#define	UCPD_SR_TXMSGDISC_B_0X1					(0x1u<<1)
#define	UCPD_SR_TXIS_B_0X0						(0x0u<<0)
#define	UCPD_SR_TXIS_B_0X1						(0x1u<<0)

// ICR Configuration

#define	UCPD_ICR_FRSEVTCF						(0x1u<<20)
#define	UCPD_ICR_TYPECEVT2CF					(0x1u<<15)
#define	UCPD_ICR_TYPECEVT1CF					(0x1u<<14)
#define	UCPD_ICR_RXMSGENDCF						(0x1u<<12)
#define	UCPD_ICR_RXOVRCF						(0x1u<<11)
#define	UCPD_ICR_RXHRSTDETCF					(0x1u<<10)
#define	UCPD_ICR_RXORDDETCF						(0x1u<<9)
#define	UCPD_ICR_TXUNDCF						(0x1u<<6)
#define	UCPD_ICR_HRSTSENTCF						(0x1u<<5)
#define	UCPD_ICR_HRSTDISCCF						(0x1u<<4)
#define	UCPD_ICR_TXMSGABTCF						(0x1u<<3)
#define	UCPD_ICR_TXMSGSENTCF					(0x1u<<2)
#define	UCPD_ICR_TXMSGDISCCF					(0x1u<<1)

// TX_ORDSETR Configuration

#define	UCPD_TX_ORDSETR_TXORDSET				(0xFFFFFu<<0)
#define	UCPD_TX_ORDSETR_TXORDSET_0				(0x1u<<0)

// TX_PAYSZR Configuration

#define	UCPD_TX_PAYSZR_TXPAYSZ					(0x3FFu<<0)
#define	UCPD_TX_PAYSZR_TXPAYSZ_0				(0x1u<<0)

#define	UCPD_TX_PAYSZR_TXPAYSZ_B_0X2			(0x2u<<0)
#define	UCPD_TX_PAYSZR_TXPAYSZ_B_0X6			(0x6u<<0)
#define	UCPD_TX_PAYSZR_TXPAYSZ_B_0X1E			(0x1Eu<<0)
#define	UCPD_TX_PAYSZR_TXPAYSZ_B_0X106			(0x106u<<0)
#define	UCPD_TX_PAYSZR_TXPAYSZ_B_0X3FF			(0x3FFu<<0)

// TXDR Configuration

#define	UCPD_TXDR_TXDATA						(0xFFu<<0)
#define	UCPD_TXDR_TXDATA_0						(0x1u<<0)

// RX_ORDSETR Configuration

#define	UCPD_RX_ORDSETR_RXSOPKINVALID			(0x7u<<4)
#define	UCPD_RX_ORDSETR_RXSOPKINVALID_0			(0x1u<<4)
#define	UCPD_RX_ORDSETR_RXSOP3OF4				(0x1u<<3)
#define	UCPD_RX_ORDSETR_RXORDSET				(0x7u<<0)
#define	UCPD_RX_ORDSETR_RXORDSET_0				(0x1u<<0)

#define	UCPD_RX_ORDSETR_RXSOPKINVALID_B_0X0		(0x0u<<4)
#define	UCPD_RX_ORDSETR_RXSOPKINVALID_B_0X1		(0x1u<<4)
#define	UCPD_RX_ORDSETR_RXSOPKINVALID_B_0X2		(0x2u<<4)
#define	UCPD_RX_ORDSETR_RXSOPKINVALID_B_0X3		(0x3u<<4)
#define	UCPD_RX_ORDSETR_RXSOPKINVALID_B_0X4		(0x4u<<4)
#define	UCPD_RX_ORDSETR_RXSOP3OF4_B_0X0			(0x0u<<3)
#define	UCPD_RX_ORDSETR_RXSOP3OF4_B_0X1			(0x1u<<3)
#define	UCPD_RX_ORDSETR_RXORDSET_B_0X0			(0x0u<<0)
#define	UCPD_RX_ORDSETR_RXORDSET_B_0X1			(0x1u<<0)
#define	UCPD_RX_ORDSETR_RXORDSET_B_0X2			(0x2u<<0)
#define	UCPD_RX_ORDSETR_RXORDSET_B_0X3			(0x3u<<0)
#define	UCPD_RX_ORDSETR_RXORDSET_B_0X4			(0x4u<<0)
#define	UCPD_RX_ORDSETR_RXORDSET_B_0X5			(0x5u<<0)
#define	UCPD_RX_ORDSETR_RXORDSET_B_0X6			(0x6u<<0)
#define	UCPD_RX_ORDSETR_RXORDSET_B_0X7			(0x7u<<0)

// RX_PAYSZR Configuration

#define	UCPD_RX_PAYSZR_RXPAYSZ					(0x3FFu<<0)
#define	UCPD_RX_PAYSZR_RXPAYSZ_0				(0x1u<<0)

#define	UCPD_RX_PAYSZR_RXPAYSZ_B_0X2			(0x2u<<0)
#define	UCPD_RX_PAYSZR_RXPAYSZ_B_0X6			(0x6u<<0)
#define	UCPD_RX_PAYSZR_RXPAYSZ_B_0X1E			(0x1Eu<<0)
#define	UCPD_RX_PAYSZR_RXPAYSZ_B_0X106			(0x106u<<0)
#define	UCPD_RX_PAYSZR_RXPAYSZ_B_0X3FF			(0x3FFu<<0)

// RXDR Configuration

#define	UCPD_RXDR_RXDATA						(0xFFu<<0)
#define	UCPD_RXDR_RXDATA_0						(0x1u<<0)

// RX_ORDEXTR1 Configuration

#define	UCPD_RX_ORDEXTR1_RXSOPX1				(0xFFFFFu<<0)
#define	UCPD_RX_ORDEXTR1_RXSOPX1_0				(0x1u<<0)

// RX_ORDEXTR2 Configuration

#define	UCPD_RX_ORDEXTR2_RXSOPX2				(0xFFFFFu<<0)
#define	UCPD_RX_ORDEXTR2_RXSOPX2_0				(0x1u<<0)
