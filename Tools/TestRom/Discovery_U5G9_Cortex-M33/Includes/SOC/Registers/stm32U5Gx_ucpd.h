/*
; stm32U5Gx_ucpd.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_ucpd equates.
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
	volatile	uint32_t	CFGR3;
	volatile	uint32_t	CR;
	volatile	uint32_t	IMR;
	volatile	uint32_t	SR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	TX_ORDSET;
	volatile	uint32_t	TX_PAYSZ;
	volatile	uint32_t	TXDR;
	volatile	uint32_t	RX_ORDSET;
	volatile	uint32_t	RX_PAYSZ;
	volatile	uint32_t	RXDR;
	volatile	uint32_t	RX_ORDEXT1;
	volatile	uint32_t	RX_ORDEXT2;
} UCPD_TypeDef;

#if (defined(__cplusplus))
#define	UCPD1_NS	reinterpret_cast<UCPD_TypeDef *>(0x4000DC00u)
#define	UCPD1_S		reinterpret_cast<UCPD_TypeDef *>(0x5000DC00u)

#else
#define	UCPD1_NS	((UCPD_TypeDef *)0x4000DC00u)
#define	UCPD1_S		((UCPD_TypeDef *)0x5000DC00u)
#endif

// CFGR1 Configuration

#define	UCPD_CFGR1_UCPDEN				(0x1u<<31)
#define	UCPD_CFGR1_RXDMAEN				(0x1u<<30)
#define	UCPD_CFGR1_TXDMAEN				(0x1u<<29)
#define	UCPD_CFGR1_RXORDSETEN			(0x1FFu<<20)
#define	UCPD_CFGR1_RXORDSETEN_0			(0x1u<<20)
#define	UCPD_CFGR1_PSC_USBPDCLK			(0x7u<<17)
#define	UCPD_CFGR1_PSC_USBPDCLK_0		(0x1u<<17)
#define	UCPD_CFGR1_TRANSWIN				(0x1Fu<<11)
#define	UCPD_CFGR1_TRANSWIN_0			(0x1u<<11)
#define	UCPD_CFGR1_IFRGAP				(0x1Fu<<6)
#define	UCPD_CFGR1_IFRGAP_0				(0x1u<<6)
#define	UCPD_CFGR1_HBITCLKDIV			(0x3Fu<<0)
#define	UCPD_CFGR1_HBITCLKDIV_0			(0x1u<<0)

// CFGR2 Configuration

#define	UCPD_CFGR2_WUPEN				(0x1u<<3)
#define	UCPD_CFGR2_FORCECLK				(0x1u<<2)
#define	UCPD_CFGR2_RXFILT2N3			(0x1u<<1)
#define	UCPD_CFGR2_RXFILTDIS			(0x1u<<0)

// CFGR3 Configuration

#define	UCPD_CFGR3_TRIM2_NG_CC3A0		(0xFu<<25)
#define	UCPD_CFGR3_TRIM2_NG_CC3A0_0		(0x1u<<25)
#define	UCPD_CFGR3_TRIM2_NG_CCRPD		(0xFu<<16)
#define	UCPD_CFGR3_TRIM2_NG_CCRPD_0		(0x1u<<16)
#define	UCPD_CFGR3_TRIM1_NG_CC3A0		(0xFu<<9)
#define	UCPD_CFGR3_TRIM1_NG_CC3A0_0		(0x1u<<9)
#define	UCPD_CFGR3_TRIM1_NG_CCRPD		(0xFu<<0)
#define	UCPD_CFGR3_TRIM1_NG_CCRPD_0		(0x1u<<0)

// CR Configuration

#define	UCPD_CR_CC2TCDIS				(0x1u<<21)
#define	UCPD_CR_CC1TCDIS				(0x1u<<20)
#define	UCPD_CR_RDCH					(0x1u<<18)
#define	UCPD_CR_FRSTX					(0x1u<<17)
#define	UCPD_CR_FRSRXEN					(0x1u<<16)
#define	UCPD_CR_CCENABLE				(0x3u<<10)
#define	UCPD_CR_CCENABLE_0				(0x1u<<10)
#define	UCPD_CR_ANAMODE					(0x1u<<9)
#define	UCPD_CR_ANASUBMODE				(0x3u<<7)
#define	UCPD_CR_ANASUBMODE_0			(0x1u<<7)
#define	UCPD_CR_PHYCCSEL				(0x1u<<6)
#define	UCPD_CR_PHYRXEN					(0x1u<<5)
#define	UCPD_CR_RXMODE					(0x1u<<4)
#define	UCPD_CR_TXHRST					(0x1u<<3)
#define	UCPD_CR_TXSEND					(0x1u<<2)
#define	UCPD_CR_TXMODE					(0x3u<<0)
#define	UCPD_CR_TXMODE_0				(0x1u<<0)

// IMR Configuration

#define	UCPD_IMR_FRSEVTIE				(0x1u<<20)
#define	UCPD_IMR_TYPECEVT2IE			(0x1u<<15)
#define	UCPD_IMR_TYPECEVT1IE			(0x1u<<14)
#define	UCPD_IMR_RXMSGENDIE				(0x1u<<12)
#define	UCPD_IMR_RXOVRIE				(0x1u<<11)
#define	UCPD_IMR_RXHRSTDETIE			(0x1u<<10)
#define	UCPD_IMR_RXORDDETIE				(0x1u<<9)
#define	UCPD_IMR_RXNEIE					(0x1u<<8)
#define	UCPD_IMR_TXUNDIE				(0x1u<<6)
#define	UCPD_IMR_HRSTSENTIE				(0x1u<<5)
#define	UCPD_IMR_HRSTDISCIE				(0x1u<<4)
#define	UCPD_IMR_TXMSGABTIE				(0x1u<<3)
#define	UCPD_IMR_TXMSGSENTIE			(0x1u<<2)
#define	UCPD_IMR_TXMSGDISCIE			(0x1u<<1)
#define	UCPD_IMR_TXISIE					(0x1u<<0)

// SR Configuration

#define	UCPD_SR_FRSEVT					(0x1u<<20)
#define	UCPD_SR_TYPEC_VSTATE_CC2		(0x3u<<18)
#define	UCPD_SR_TYPEC_VSTATE_CC2_0		(0x1u<<18)
#define	UCPD_SR_TYPEC_VSTATE_CC1		(0x3u<<16)
#define	UCPD_SR_TYPEC_VSTATE_CC1_0		(0x1u<<16)
#define	UCPD_SR_TYPECEVT2				(0x1u<<15)
#define	UCPD_SR_TYPECEVT1				(0x1u<<14)
#define	UCPD_SR_RXERR					(0x1u<<13)
#define	UCPD_SR_RXMSGEND				(0x1u<<12)
#define	UCPD_SR_RXOVR					(0x1u<<11)
#define	UCPD_SR_RXHRSTDET				(0x1u<<10)
#define	UCPD_SR_RXORDDET				(0x1u<<9)
#define	UCPD_SR_RXNE					(0x1u<<8)
#define	UCPD_SR_TXUND					(0x1u<<6)
#define	UCPD_SR_HRSTSENT				(0x1u<<5)
#define	UCPD_SR_HRSTDISC				(0x1u<<4)
#define	UCPD_SR_TXMSGABT				(0x1u<<3)
#define	UCPD_SR_TXMSGSENT				(0x1u<<2)
#define	UCPD_SR_TXMSGDISC				(0x1u<<1)
#define	UCPD_SR_TXIS					(0x1u<<0)

// ICR Configuration

#define	UCPD_ICR_FRSEVTCF				(0x1u<<20)
#define	UCPD_ICR_TYPECEVT2CF			(0x1u<<15)
#define	UCPD_ICR_TYPECEVT1CF			(0x1u<<14)
#define	UCPD_ICR_RXMSGENDCF				(0x1u<<12)
#define	UCPD_ICR_RXOVRCF				(0x1u<<11)
#define	UCPD_ICR_RXHRSTDETCF			(0x1u<<10)
#define	UCPD_ICR_RXORDDETCF				(0x1u<<9)
#define	UCPD_ICR_TXUNDCF				(0x1u<<6)
#define	UCPD_ICR_HRSTSENTCF				(0x1u<<5)
#define	UCPD_ICR_HRSTDISCCF				(0x1u<<4)
#define	UCPD_ICR_TXMSGABTCF				(0x1u<<3)
#define	UCPD_ICR_TXMSGSENTCF			(0x1u<<2)
#define	UCPD_ICR_TXMSGDISCCF			(0x1u<<1)

// TX_ORDSET Configuration

#define	UCPD_TX_ORDSET_TXORDSET			(0xFFFFFu<<0)
#define	UCPD_TX_ORDSET_TXORDSET_0		(0x1u<<0)

// TX_PAYSZ Configuration

#define	UCPD_TX_PAYSZ_TXPAYSZ			(0x3FFu<<0)
#define	UCPD_TX_PAYSZ_TXPAYSZ_0			(0x1u<<0)

// TXDR Configuration

#define	UCPD_TXDR_TXDATA				(0xFFu<<0)
#define	UCPD_TXDR_TXDATA_0				(0x1u<<0)

// RX_ORDSET Configuration

#define	UCPD_RX_ORDSET_RXSOPKINVALID	(0x7u<<4)
#define	UCPD_RX_ORDSET_RXSOPKINVALID_0	(0x1u<<4)
#define	UCPD_RX_ORDSET_RXSOP3OF4		(0x1u<<3)
#define	UCPD_RX_ORDSET_RXORDSET			(0x7u<<0)
#define	UCPD_RX_ORDSET_RXORDSET_0		(0x1u<<0)

// RX_PAYSZ Configuration

#define	UCPD_RX_PAYSZ_RXPAYSZ			(0x3FFu<<0)
#define	UCPD_RX_PAYSZ_RXPAYSZ_0			(0x1u<<0)

// RXDR Configuration

#define	UCPD_RXDR_RXDATA				(0xFFu<<0)
#define	UCPD_RXDR_RXDATA_0				(0x1u<<0)

// RX_ORDEXT1 Configuration

#define	UCPD_RX_ORDEXT1_RXSOPX1			(0xFFFFFu<<0)
#define	UCPD_RX_ORDEXT1_RXSOPX1_0		(0x1u<<0)

// RX_ORDEXT2 Configuration

#define	UCPD_RX_ORDEXT2_RXSOPX2			(0xFFFFFu<<0)
#define	UCPD_RX_ORDEXT2_RXSOPX2_0		(0x1u<<0)
