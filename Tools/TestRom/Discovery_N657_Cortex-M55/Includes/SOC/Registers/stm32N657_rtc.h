/*
; stm32N657_rtc.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_rtc equates.
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

// RTC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	TR;
	volatile	uint32_t	DR;
	volatile	uint32_t	SSR;
	volatile	uint32_t	ICSR;
	volatile	uint32_t	PRER;
	volatile	uint32_t	WUTR;
	volatile	uint32_t	CR;
	volatile	uint32_t	PRIVCFGR;
	volatile	uint32_t	SECCFGR;
	volatile	uint32_t	WPR;
	volatile	uint32_t	CALR;
	volatile	uint32_t	SHIFTR;
	volatile	uint32_t	TSTR;
	volatile	uint32_t	TSDR;
	volatile	uint32_t	TSSSR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	ALRMAR;
	volatile	uint32_t	ALRMASSR;
	volatile	uint32_t	ALRMBR;
	volatile	uint32_t	ALRMBSSR;
	volatile	uint32_t	SR;
	volatile	uint32_t	MISR;
	volatile	uint32_t	SMISR;
	volatile	uint32_t	SCR;
	volatile	uint32_t	RESERVED1[4];
	volatile	uint32_t	ALRABINR;
	volatile	uint32_t	ALRBBINR;
} RTC_TypeDef;

#if (defined(__cplusplus))
#define	RTC_NS	reinterpret_cast<RTC_TypeDef *>(0x46004000u)
#define	RTC_S	reinterpret_cast<RTC_TypeDef *>(0x56004000u)

#else
#define	RTC_NS	((RTC_TypeDef *)0x46004000u)
#define	RTC_S	((RTC_TypeDef *)0x56004000u)
#endif

// TR Configuration

#define	RTC_TR_PM					(0x1u<<22)
#define	RTC_TR_HT					(0x3u<<20)
#define	RTC_TR_HT_0					(0x1u<<20)
#define	RTC_TR_HU					(0xFu<<16)
#define	RTC_TR_HU_0					(0x1u<<16)
#define	RTC_TR_MNT					(0x7u<<12)
#define	RTC_TR_MNT_0				(0x1u<<12)
#define	RTC_TR_MNU					(0xFu<<8)
#define	RTC_TR_MNU_0				(0x1u<<8)
#define	RTC_TR_ST					(0x7u<<4)
#define	RTC_TR_ST_0					(0x1u<<4)
#define	RTC_TR_SU					(0xFu<<0)
#define	RTC_TR_SU_0					(0x1u<<0)

#define	RTC_TR_PM_B_0X0				(0x0u<<22)
#define	RTC_TR_PM_B_0X1				(0x1u<<22)

// DR Configuration

#define	RTC_DR_YT					(0xFu<<20)
#define	RTC_DR_YT_0					(0x1u<<20)
#define	RTC_DR_YU					(0xFu<<16)
#define	RTC_DR_YU_0					(0x1u<<16)
#define	RTC_DR_WDU					(0x7u<<13)
#define	RTC_DR_WDU_0				(0x1u<<13)
#define	RTC_DR_MT					(0x1u<<12)
#define	RTC_DR_MU					(0xFu<<8)
#define	RTC_DR_MU_0					(0x1u<<8)
#define	RTC_DR_DT					(0x3u<<4)
#define	RTC_DR_DT_0					(0x1u<<4)
#define	RTC_DR_DU					(0xFu<<0)
#define	RTC_DR_DU_0					(0x1u<<0)

#define	RTC_DR_WDU_B_0X0			(0x0u<<13)
#define	RTC_DR_WDU_B_0X1			(0x1u<<13)
#define	RTC_DR_WDU_B_0X7			(0x7u<<13)

// SSR Configuration

#define	RTC_SSR_SS					(0xFFFFFFFFu<<0)
#define	RTC_SSR_SS_0				(0x1u<<0)

// ICSR Configuration

#define	RTC_ICSR_RECALPF			(0x1u<<16)
#define	RTC_ICSR_BCDU				(0x7u<<10)
#define	RTC_ICSR_BCDU_0				(0x1u<<10)
#define	RTC_ICSR_BIN				(0x3u<<8)
#define	RTC_ICSR_BIN_0				(0x1u<<8)
#define	RTC_ICSR_INIT				(0x1u<<7)
#define	RTC_ICSR_INITF				(0x1u<<6)
#define	RTC_ICSR_RSF				(0x1u<<5)
#define	RTC_ICSR_INITS				(0x1u<<4)
#define	RTC_ICSR_SHPF				(0x1u<<3)
#define	RTC_ICSR_WUTWF				(0x1u<<2)

#define	RTC_ICSR_BCDU_B_0X0			(0x0u<<10)
#define	RTC_ICSR_BCDU_B_0X1			(0x1u<<10)
#define	RTC_ICSR_BCDU_B_0X2			(0x2u<<10)
#define	RTC_ICSR_BCDU_B_0X3			(0x3u<<10)
#define	RTC_ICSR_BCDU_B_0X4			(0x4u<<10)
#define	RTC_ICSR_BCDU_B_0X5			(0x5u<<10)
#define	RTC_ICSR_BCDU_B_0X6			(0x6u<<10)
#define	RTC_ICSR_BCDU_B_0X7			(0x7u<<10)
#define	RTC_ICSR_BIN_B_0X0			(0x0u<<8)
#define	RTC_ICSR_BIN_B_0X1			(0x1u<<8)
#define	RTC_ICSR_BIN_B_0X2			(0x2u<<8)
#define	RTC_ICSR_BIN_B_0X3			(0x3u<<8)
#define	RTC_ICSR_INIT_B_0X0			(0x0u<<7)
#define	RTC_ICSR_INIT_B_0X1			(0x1u<<7)
#define	RTC_ICSR_INITF_B_0X0		(0x0u<<6)
#define	RTC_ICSR_INITF_B_0X1		(0x1u<<6)
#define	RTC_ICSR_RSF_B_0X0			(0x0u<<5)
#define	RTC_ICSR_RSF_B_0X1			(0x1u<<5)
#define	RTC_ICSR_INITS_B_0X0		(0x0u<<4)
#define	RTC_ICSR_INITS_B_0X1		(0x1u<<4)
#define	RTC_ICSR_SHPF_B_0X0			(0x0u<<3)
#define	RTC_ICSR_SHPF_B_0X1			(0x1u<<3)
#define	RTC_ICSR_WUTWF_B_0X0		(0x0u<<2)
#define	RTC_ICSR_WUTWF_B_0X1		(0x1u<<2)

// PRER Configuration

#define	RTC_PRER_PREDIV_A			(0x7Fu<<16)
#define	RTC_PRER_PREDIV_A_0			(0x1u<<16)
#define	RTC_PRER_PREDIV_S			(0x7FFFu<<0)
#define	RTC_PRER_PREDIV_S_0			(0x1u<<0)

// WUTR Configuration

#define	RTC_WUTR_WUTOCLR			(0xFFFFu<<16)
#define	RTC_WUTR_WUTOCLR_0			(0x1u<<16)
#define	RTC_WUTR_WUT				(0xFFFFu<<0)
#define	RTC_WUTR_WUT_0				(0x1u<<0)

// CR Configuration

#define	RTC_CR_OUT2EN				(0x1u<<31)
#define	RTC_CR_TAMPALRM_TYPE		(0x1u<<30)
#define	RTC_CR_TAMPALRM_PU			(0x1u<<29)
#define	RTC_CR_ALRBFCLR				(0x1u<<28)
#define	RTC_CR_ALRAFCLR				(0x1u<<27)
#define	RTC_CR_TAMPOE				(0x1u<<26)
#define	RTC_CR_TAMPTS				(0x1u<<25)
#define	RTC_CR_ITSE					(0x1u<<24)
#define	RTC_CR_COE					(0x1u<<23)
#define	RTC_CR_OSEL					(0x3u<<21)
#define	RTC_CR_OSEL_0				(0x1u<<21)
#define	RTC_CR_POL					(0x1u<<20)
#define	RTC_CR_COSEL				(0x1u<<19)
#define	RTC_CR_BKP					(0x1u<<18)
#define	RTC_CR_SUB1H				(0x1u<<17)
#define	RTC_CR_ADD1H				(0x1u<<16)
#define	RTC_CR_TSIE					(0x1u<<15)
#define	RTC_CR_WUTIE				(0x1u<<14)
#define	RTC_CR_ALRBIE				(0x1u<<13)
#define	RTC_CR_ALRAIE				(0x1u<<12)
#define	RTC_CR_TSE					(0x1u<<11)
#define	RTC_CR_WUTE					(0x1u<<10)
#define	RTC_CR_ALRBE				(0x1u<<9)
#define	RTC_CR_ALRAE				(0x1u<<8)
#define	RTC_CR_SSRUIE				(0x1u<<7)
#define	RTC_CR_FMT					(0x1u<<6)
#define	RTC_CR_BYPSHAD				(0x1u<<5)
#define	RTC_CR_REFCKON				(0x1u<<4)
#define	RTC_CR_TSEDGE				(0x1u<<3)
#define	RTC_CR_WUCKSEL				(0x7u<<0)
#define	RTC_CR_WUCKSEL_0			(0x1u<<0)

#define	RTC_CR_TAMPALRM_TYPE_B_0X0	(0x0u<<30)
#define	RTC_CR_TAMPALRM_TYPE_B_0X1	(0x1u<<30)
#define	RTC_CR_TAMPALRM_PU_B_0X0	(0x0u<<29)
#define	RTC_CR_TAMPALRM_PU_B_0X1	(0x1u<<29)
#define	RTC_CR_ALRBFCLR_B_0X0		(0x0u<<28)
#define	RTC_CR_ALRBFCLR_B_0X1		(0x1u<<28)
#define	RTC_CR_ALRAFCLR_B_0X0		(0x0u<<27)
#define	RTC_CR_ALRAFCLR_B_0X1		(0x1u<<27)
#define	RTC_CR_TAMPOE_B_0X0			(0x0u<<26)
#define	RTC_CR_TAMPOE_B_0X1			(0x1u<<26)
#define	RTC_CR_TAMPTS_B_0X0			(0x0u<<25)
#define	RTC_CR_TAMPTS_B_0X1			(0x1u<<25)
#define	RTC_CR_ITSE_B_0X0			(0x0u<<24)
#define	RTC_CR_ITSE_B_0X1			(0x1u<<24)
#define	RTC_CR_COE_B_0X0			(0x0u<<23)
#define	RTC_CR_COE_B_0X1			(0x1u<<23)
#define	RTC_CR_OSEL_B_0X0			(0x0u<<21)
#define	RTC_CR_OSEL_B_0X1			(0x1u<<21)
#define	RTC_CR_OSEL_B_0X2			(0x2u<<21)
#define	RTC_CR_OSEL_B_0X3			(0x3u<<21)
#define	RTC_CR_POL_B_0X0			(0x0u<<20)
#define	RTC_CR_POL_B_0X1			(0x1u<<20)
#define	RTC_CR_COSEL_B_0X0			(0x0u<<19)
#define	RTC_CR_COSEL_B_0X1			(0x1u<<19)
#define	RTC_CR_SUB1H_B_0X0			(0x0u<<17)
#define	RTC_CR_SUB1H_B_0X1			(0x1u<<17)
#define	RTC_CR_ADD1H_B_0X0			(0x0u<<16)
#define	RTC_CR_ADD1H_B_0X1			(0x1u<<16)
#define	RTC_CR_TSIE_B_0X0			(0x0u<<15)
#define	RTC_CR_TSIE_B_0X1			(0x1u<<15)
#define	RTC_CR_WUTIE_B_0X0			(0x0u<<14)
#define	RTC_CR_WUTIE_B_0X1			(0x1u<<14)
#define	RTC_CR_ALRBIE_B_0X0			(0x0u<<13)
#define	RTC_CR_ALRBIE_B_0X1			(0x1u<<13)
#define	RTC_CR_ALRAIE_B_0X0			(0x0u<<12)
#define	RTC_CR_ALRAIE_B_0X1			(0x1u<<12)
#define	RTC_CR_TSE_B_0X0			(0x0u<<11)
#define	RTC_CR_TSE_B_0X1			(0x1u<<11)
#define	RTC_CR_WUTE_B_0X0			(0x0u<<10)
#define	RTC_CR_WUTE_B_0X1			(0x1u<<10)
#define	RTC_CR_ALRBE_B_0X0			(0x0u<<9)
#define	RTC_CR_ALRBE_B_0X1			(0x1u<<9)
#define	RTC_CR_ALRAE_B_0X0			(0x0u<<8)
#define	RTC_CR_ALRAE_B_0X1			(0x1u<<8)
#define	RTC_CR_SSRUIE_B_0X0			(0x0u<<7)
#define	RTC_CR_SSRUIE_B_0X1			(0x1u<<7)
#define	RTC_CR_FMT_B_0X0			(0x0u<<6)
#define	RTC_CR_FMT_B_0X1			(0x1u<<6)
#define	RTC_CR_BYPSHAD_B_0X0		(0x0u<<5)
#define	RTC_CR_BYPSHAD_B_0X1		(0x1u<<5)
#define	RTC_CR_REFCKON_B_0X0		(0x0u<<4)
#define	RTC_CR_REFCKON_B_0X1		(0x1u<<4)
#define	RTC_CR_TSEDGE_B_0X0			(0x0u<<3)
#define	RTC_CR_TSEDGE_B_0X1			(0x1u<<3)
#define	RTC_CR_WUCKSEL_B_0X0		(0x0u<<0)
#define	RTC_CR_WUCKSEL_B_0X1		(0x1u<<0)
#define	RTC_CR_WUCKSEL_B_0X2		(0x2u<<0)
#define	RTC_CR_WUCKSEL_B_0X3		(0x3u<<0)

// PRIVCFGR Configuration

#define	RTC_PRIVCFGR_PRIV			(0x1u<<15)
#define	RTC_PRIVCFGR_INITPRIV		(0x1u<<14)
#define	RTC_PRIVCFGR_CALPRIV		(0x1u<<13)
#define	RTC_PRIVCFGR_TSPRIV			(0x1u<<3)
#define	RTC_PRIVCFGR_WUTPRIV		(0x1u<<2)
#define	RTC_PRIVCFGR_ALRBPRIV		(0x1u<<1)
#define	RTC_PRIVCFGR_ALRAPRIV		(0x1u<<0)

#define	RTC_PRIVCFGR_PRIV_B_0X0		(0x0u<<15)
#define	RTC_PRIVCFGR_PRIV_B_0X1		(0x1u<<15)
#define	RTC_PRIVCFGR_INITPRIV_B_0X0	(0x0u<<14)
#define	RTC_PRIVCFGR_INITPRIV_B_0X1	(0x1u<<14)
#define	RTC_PRIVCFGR_CALPRIV_B_0X0	(0x0u<<13)
#define	RTC_PRIVCFGR_CALPRIV_B_0X1	(0x1u<<13)
#define	RTC_PRIVCFGR_TSPRIV_B_0X0	(0x0u<<3)
#define	RTC_PRIVCFGR_TSPRIV_B_0X1	(0x1u<<3)
#define	RTC_PRIVCFGR_WUTPRIV_B_0X0	(0x0u<<2)
#define	RTC_PRIVCFGR_WUTPRIV_B_0X1	(0x1u<<2)
#define	RTC_PRIVCFGR_ALRBPRIV_B_0X0	(0x0u<<1)
#define	RTC_PRIVCFGR_ALRBPRIV_B_0X1	(0x1u<<1)
#define	RTC_PRIVCFGR_ALRAPRIV_B_0X0	(0x0u<<0)
#define	RTC_PRIVCFGR_ALRAPRIV_B_0X1	(0x1u<<0)

// SECCFGR Configuration

#define	RTC_SECCFGR_SEC				(0x1u<<15)
#define	RTC_SECCFGR_INITSEC			(0x1u<<14)
#define	RTC_SECCFGR_CALSEC			(0x1u<<13)
#define	RTC_SECCFGR_TSSEC			(0x1u<<3)
#define	RTC_SECCFGR_WUTSEC			(0x1u<<2)
#define	RTC_SECCFGR_ALRBSEC			(0x1u<<1)
#define	RTC_SECCFGR_ALRASEC			(0x1u<<0)

#define	RTC_SECCFGR_SEC_B_0X0		(0x0u<<15)
#define	RTC_SECCFGR_SEC_B_0X1		(0x1u<<15)
#define	RTC_SECCFGR_INITSEC_B_0X0	(0x0u<<14)
#define	RTC_SECCFGR_INITSEC_B_0X1	(0x1u<<14)
#define	RTC_SECCFGR_CALSEC_B_0X0	(0x0u<<13)
#define	RTC_SECCFGR_CALSEC_B_0X1	(0x1u<<13)
#define	RTC_SECCFGR_TSSEC_B_0X0		(0x0u<<3)
#define	RTC_SECCFGR_TSSEC_B_0X1		(0x1u<<3)
#define	RTC_SECCFGR_WUTSEC_B_0X0	(0x0u<<2)
#define	RTC_SECCFGR_WUTSEC_B_0X1	(0x1u<<2)
#define	RTC_SECCFGR_ALRBSEC_B_0X0	(0x0u<<1)
#define	RTC_SECCFGR_ALRBSEC_B_0X1	(0x1u<<1)
#define	RTC_SECCFGR_ALRASEC_B_0X0	(0x0u<<0)
#define	RTC_SECCFGR_ALRASEC_B_0X1	(0x1u<<0)

// WPR Configuration

#define	RTC_WPR_KEY					(0xFFu<<0)
#define	RTC_WPR_KEY_0				(0x1u<<0)

// CALR Configuration

#define	RTC_CALR_CALP				(0x1u<<15)
#define	RTC_CALR_CALW8				(0x1u<<14)
#define	RTC_CALR_CALW16				(0x1u<<13)
#define	RTC_CALR_LPCAL				(0x1u<<12)
#define	RTC_CALR_CALM				(0x1FFu<<0)
#define	RTC_CALR_CALM_0				(0x1u<<0)

#define	RTC_CALR_CALP_B_0X0			(0x0u<<15)
#define	RTC_CALR_CALP_B_0X1			(0x1u<<15)
#define	RTC_CALR_LPCAL_B_0X0		(0x0u<<12)
#define	RTC_CALR_LPCAL_B_0X1		(0x1u<<12)

// SHIFTR Configuration

#define	RTC_SHIFTR_ADD1S			(0x1u<<31)
#define	RTC_SHIFTR_SUBFS			(0x7FFFu<<0)
#define	RTC_SHIFTR_SUBFS_0			(0x1u<<0)

#define	RTC_SHIFTR_ADD1S_B_0X0		(0x0u<<31)
#define	RTC_SHIFTR_ADD1S_B_0X1		(0x1u<<31)

// TSTR Configuration

#define	RTC_TSTR_PM					(0x1u<<22)
#define	RTC_TSTR_HT					(0x3u<<20)
#define	RTC_TSTR_HT_0				(0x1u<<20)
#define	RTC_TSTR_HU					(0xFu<<16)
#define	RTC_TSTR_HU_0				(0x1u<<16)
#define	RTC_TSTR_MNT				(0x7u<<12)
#define	RTC_TSTR_MNT_0				(0x1u<<12)
#define	RTC_TSTR_MNU				(0xFu<<8)
#define	RTC_TSTR_MNU_0				(0x1u<<8)
#define	RTC_TSTR_ST					(0x7u<<4)
#define	RTC_TSTR_ST_0				(0x1u<<4)
#define	RTC_TSTR_SU					(0xFu<<0)
#define	RTC_TSTR_SU_0				(0x1u<<0)

#define	RTC_TSTR_PM_B_0X0			(0x0u<<22)
#define	RTC_TSTR_PM_B_0X1			(0x1u<<22)

// TSDR Configuration

#define	RTC_TSDR_WDU				(0x7u<<13)
#define	RTC_TSDR_WDU_0				(0x1u<<13)
#define	RTC_TSDR_MT					(0x1u<<12)
#define	RTC_TSDR_MU					(0xFu<<8)
#define	RTC_TSDR_MU_0				(0x1u<<8)
#define	RTC_TSDR_DT					(0x3u<<4)
#define	RTC_TSDR_DT_0				(0x1u<<4)
#define	RTC_TSDR_DU					(0xFu<<0)
#define	RTC_TSDR_DU_0				(0x1u<<0)

// TSSSR Configuration

#define	RTC_TSSSR_SS				(0xFFFFFFFFu<<0)
#define	RTC_TSSSR_SS_0				(0x1u<<0)

// ALRMAR Configuration

#define	RTC_ALRMAR_MSK4				(0x1u<<31)
#define	RTC_ALRMAR_WDSEL			(0x1u<<30)
#define	RTC_ALRMAR_DT				(0x3u<<28)
#define	RTC_ALRMAR_DT_0				(0x1u<<28)
#define	RTC_ALRMAR_DU				(0xFu<<24)
#define	RTC_ALRMAR_DU_0				(0x1u<<24)
#define	RTC_ALRMAR_MSK3				(0x1u<<23)
#define	RTC_ALRMAR_PM				(0x1u<<22)
#define	RTC_ALRMAR_HT				(0x3u<<20)
#define	RTC_ALRMAR_HT_0				(0x1u<<20)
#define	RTC_ALRMAR_HU				(0xFu<<16)
#define	RTC_ALRMAR_HU_0				(0x1u<<16)
#define	RTC_ALRMAR_MSK2				(0x1u<<15)
#define	RTC_ALRMAR_MNT				(0x7u<<12)
#define	RTC_ALRMAR_MNT_0			(0x1u<<12)
#define	RTC_ALRMAR_MNU				(0xFu<<8)
#define	RTC_ALRMAR_MNU_0			(0x1u<<8)
#define	RTC_ALRMAR_MSK1				(0x1u<<7)
#define	RTC_ALRMAR_ST				(0x7u<<4)
#define	RTC_ALRMAR_ST_0				(0x1u<<4)
#define	RTC_ALRMAR_SU				(0xFu<<0)
#define	RTC_ALRMAR_SU_0				(0x1u<<0)

#define	RTC_ALRMAR_MSK4_B_0X0		(0x0u<<31)
#define	RTC_ALRMAR_MSK4_B_0X1		(0x1u<<31)
#define	RTC_ALRMAR_WDSEL_B_0X0		(0x0u<<30)
#define	RTC_ALRMAR_WDSEL_B_0X1		(0x1u<<30)
#define	RTC_ALRMAR_MSK3_B_0X0		(0x0u<<23)
#define	RTC_ALRMAR_MSK3_B_0X1		(0x1u<<23)
#define	RTC_ALRMAR_PM_B_0X0			(0x0u<<22)
#define	RTC_ALRMAR_PM_B_0X1			(0x1u<<22)
#define	RTC_ALRMAR_MSK2_B_0X0		(0x0u<<15)
#define	RTC_ALRMAR_MSK2_B_0X1		(0x1u<<15)
#define	RTC_ALRMAR_MSK1_B_0X0		(0x0u<<7)
#define	RTC_ALRMAR_MSK1_B_0X1		(0x1u<<7)

// ALRMASSR Configuration

#define	RTC_ALRMASSR_SSCLR			(0x1u<<31)
#define	RTC_ALRMASSR_MASKSS			(0x3Fu<<24)
#define	RTC_ALRMASSR_MASKSS_0		(0x1u<<24)
#define	RTC_ALRMASSR_SS				(0x7FFFu<<0)
#define	RTC_ALRMASSR_SS_0			(0x1u<<0)

#define	RTC_ALRMASSR_SSCLR_B_0X0	(0x0u<<31)
#define	RTC_ALRMASSR_SSCLR_B_0X1	(0x1u<<31)
#define	RTC_ALRMASSR_MASKSS_B_0X0	(0x0u<<24)
#define	RTC_ALRMASSR_MASKSS_B_0X1	(0x1u<<24)

// ALRMBR Configuration

#define	RTC_ALRMBR_MSK4				(0x1u<<31)
#define	RTC_ALRMBR_WDSEL			(0x1u<<30)
#define	RTC_ALRMBR_DT				(0x3u<<28)
#define	RTC_ALRMBR_DT_0				(0x1u<<28)
#define	RTC_ALRMBR_DU				(0xFu<<24)
#define	RTC_ALRMBR_DU_0				(0x1u<<24)
#define	RTC_ALRMBR_MSK3				(0x1u<<23)
#define	RTC_ALRMBR_PM				(0x1u<<22)
#define	RTC_ALRMBR_HT				(0x3u<<20)
#define	RTC_ALRMBR_HT_0				(0x1u<<20)
#define	RTC_ALRMBR_HU				(0xFu<<16)
#define	RTC_ALRMBR_HU_0				(0x1u<<16)
#define	RTC_ALRMBR_MSK2				(0x1u<<15)
#define	RTC_ALRMBR_MNT				(0x7u<<12)
#define	RTC_ALRMBR_MNT_0			(0x1u<<12)
#define	RTC_ALRMBR_MNU				(0xFu<<8)
#define	RTC_ALRMBR_MNU_0			(0x1u<<8)
#define	RTC_ALRMBR_MSK1				(0x1u<<7)
#define	RTC_ALRMBR_ST				(0x7u<<4)
#define	RTC_ALRMBR_ST_0				(0x1u<<4)
#define	RTC_ALRMBR_SU				(0xFu<<0)
#define	RTC_ALRMBR_SU_0				(0x1u<<0)

#define	RTC_ALRMBR_MSK4_B_0X0		(0x0u<<31)
#define	RTC_ALRMBR_MSK4_B_0X1		(0x1u<<31)
#define	RTC_ALRMBR_WDSEL_B_0X0		(0x0u<<30)
#define	RTC_ALRMBR_WDSEL_B_0X1		(0x1u<<30)
#define	RTC_ALRMBR_MSK3_B_0X0		(0x0u<<23)
#define	RTC_ALRMBR_MSK3_B_0X1		(0x1u<<23)
#define	RTC_ALRMBR_PM_B_0X0			(0x0u<<22)
#define	RTC_ALRMBR_PM_B_0X1			(0x1u<<22)
#define	RTC_ALRMBR_MSK2_B_0X0		(0x0u<<15)
#define	RTC_ALRMBR_MSK2_B_0X1		(0x1u<<15)
#define	RTC_ALRMBR_MSK1_B_0X0		(0x0u<<7)
#define	RTC_ALRMBR_MSK1_B_0X1		(0x1u<<7)

// ALRMBSSR Configuration

#define	RTC_ALRMBSSR_SSCLR			(0x1u<<31)
#define	RTC_ALRMBSSR_MASKSS			(0x3Fu<<24)
#define	RTC_ALRMBSSR_MASKSS_0		(0x1u<<24)
#define	RTC_ALRMBSSR_SS				(0x7FFFu<<0)
#define	RTC_ALRMBSSR_SS_0			(0x1u<<0)

#define	RTC_ALRMBSSR_SSCLR_B_0X0	(0x0u<<31)
#define	RTC_ALRMBSSR_SSCLR_B_0X1	(0x1u<<31)
#define	RTC_ALRMBSSR_MASKSS_B_0X0	(0x0u<<24)
#define	RTC_ALRMBSSR_MASKSS_B_0X1	(0x1u<<24)

// SR Configuration

#define	RTC_SR_SSRUF				(0x1u<<6)
#define	RTC_SR_ITSF					(0x1u<<5)
#define	RTC_SR_TSOVF				(0x1u<<4)
#define	RTC_SR_TSF					(0x1u<<3)
#define	RTC_SR_WUTF					(0x1u<<2)
#define	RTC_SR_ALRBF				(0x1u<<1)
#define	RTC_SR_ALRAF				(0x1u<<0)

// MISR Configuration

#define	RTC_MISR_SSRUMF				(0x1u<<6)
#define	RTC_MISR_ITSMF				(0x1u<<5)
#define	RTC_MISR_TSOVMF				(0x1u<<4)
#define	RTC_MISR_TSMF				(0x1u<<3)
#define	RTC_MISR_WUTMF				(0x1u<<2)
#define	RTC_MISR_ALRBMF				(0x1u<<1)
#define	RTC_MISR_ALRAMF				(0x1u<<0)

// SMISR Configuration

#define	RTC_SMISR_SSRUMF			(0x1u<<6)
#define	RTC_SMISR_ITSMF				(0x1u<<5)
#define	RTC_SMISR_TSOVMF			(0x1u<<4)
#define	RTC_SMISR_TSMF				(0x1u<<3)
#define	RTC_SMISR_WUTMF				(0x1u<<2)
#define	RTC_SMISR_ALRBMF			(0x1u<<1)
#define	RTC_SMISR_ALRAMF			(0x1u<<0)

// SCR Configuration

#define	RTC_SCR_CSSRUF				(0x1u<<6)
#define	RTC_SCR_CITSF				(0x1u<<5)
#define	RTC_SCR_CTSOVF				(0x1u<<4)
#define	RTC_SCR_CTSF				(0x1u<<3)
#define	RTC_SCR_CWUTF				(0x1u<<2)
#define	RTC_SCR_CALRBF				(0x1u<<1)
#define	RTC_SCR_CALRAF				(0x1u<<0)

// ALRABINR Configuration

#define	RTC_ALRABINR_SS				(0xFFFFFFFFu<<0)
#define	RTC_ALRABINR_SS_0			(0x1u<<0)

// ALRBBINR Configuration

#define	RTC_ALRBBINR_SS				(0xFFFFFFFFu<<0)
#define	RTC_ALRBBINR_SS_0			(0x1u<<0)
