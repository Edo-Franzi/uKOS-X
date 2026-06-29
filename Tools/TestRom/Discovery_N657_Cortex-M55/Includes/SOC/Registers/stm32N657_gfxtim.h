/*
; stm32N657_gfxtim.
; =================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_gfxtim equates.
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

// GFXTIM address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	CGCR;
	volatile	uint32_t	TCR;
	volatile	uint32_t	TDR;
	volatile	uint32_t	EVCR;
	volatile	uint32_t	EVSR;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	WDGTCR;
	volatile	uint32_t	RESERVED1[3];
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	IER;
	volatile	uint32_t	TSR;
	volatile	uint32_t	LCCRR;
	volatile	uint32_t	FCCRR;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	ATR;
	volatile	uint32_t	AFCR;
	volatile	uint32_t	ALCR;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	AFCC1R;
	volatile	uint32_t	RESERVED4[3];
	volatile	uint32_t	ALCC1R;
	volatile	uint32_t	ALCC2R;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	RFC1R;
	volatile	uint32_t	RFC1RR;
	volatile	uint32_t	RFC2R;
	volatile	uint32_t	RFC2RR;
	volatile	uint32_t	RESERVED6[4];
	volatile	uint32_t	WDGCR;
	volatile	uint32_t	WDGRR;
	volatile	uint32_t	WDGPAR;
} GFXTIM_TypeDef;

#if (defined(__cplusplus))
#define	GFXTIM_NS	reinterpret_cast<GFXTIM_TypeDef *>(0x48004000u)
#define	GFXTIM_S	reinterpret_cast<GFXTIM_TypeDef *>(0x58004000u)

#else
#define	GFXTIM_NS	((GFXTIM_TypeDef *)0x48004000u)
#define	GFXTIM_S	((GFXTIM_TypeDef *)0x58004000u)
#endif

// CR Configuration

#define	GFXTIM_CR_LCCOE					(0x1u<<17)
#define	GFXTIM_CR_FCCOE					(0x1u<<16)
#define	GFXTIM_CR_SYNCS					(0x3u<<8)
#define	GFXTIM_CR_SYNCS_0				(0x1u<<8)
#define	GFXTIM_CR_TEPOL					(0x1u<<4)
#define	GFXTIM_CR_TES					(0x3u<<0)
#define	GFXTIM_CR_TES_0					(0x1u<<0)

#define	GFXTIM_CR_LCCOE_B_0X0			(0x0u<<17)
#define	GFXTIM_CR_LCCOE_B_0X1			(0x1u<<17)
#define	GFXTIM_CR_FCCOE_B_0X0			(0x0u<<16)
#define	GFXTIM_CR_FCCOE_B_0X1			(0x1u<<16)
#define	GFXTIM_CR_SYNCS_B_0X0			(0x0u<<8)
#define	GFXTIM_CR_SYNCS_B_0X1			(0x1u<<8)
#define	GFXTIM_CR_SYNCS_B_0X2			(0x2u<<8)
#define	GFXTIM_CR_SYNCS_B_0X3			(0x3u<<8)
#define	GFXTIM_CR_TEPOL_B_0X0			(0x0u<<4)
#define	GFXTIM_CR_TEPOL_B_0X1			(0x1u<<4)
#define	GFXTIM_CR_TES_B_0X0				(0x0u<<0)
#define	GFXTIM_CR_TES_B_0X1				(0x1u<<0)
#define	GFXTIM_CR_TES_B_0X2				(0x2u<<0)
#define	GFXTIM_CR_TES_B_0X3				(0x3u<<0)

// CGCR Configuration

#define	GFXTIM_CGCR_FCCHRS				(0x7u<<28)
#define	GFXTIM_CGCR_FCCHRS_0			(0x1u<<28)
#define	GFXTIM_CGCR_FCCFR				(0x1u<<24)
#define	GFXTIM_CGCR_FCCCS				(0x7u<<20)
#define	GFXTIM_CGCR_FCCCS_0				(0x1u<<20)
#define	GFXTIM_CGCR_FCS					(0x7u<<16)
#define	GFXTIM_CGCR_FCS_0				(0x1u<<16)
#define	GFXTIM_CGCR_LCCHRS				(0x7u<<12)
#define	GFXTIM_CGCR_LCCHRS_0			(0x1u<<12)
#define	GFXTIM_CGCR_LCCFR				(0x1u<<8)
#define	GFXTIM_CGCR_LCCCS				(0x1u<<4)
#define	GFXTIM_CGCR_LCS					(0x7u<<0)
#define	GFXTIM_CGCR_LCS_0				(0x1u<<0)

#define	GFXTIM_CGCR_FCCHRS_B_0X0		(0x0u<<28)
#define	GFXTIM_CGCR_FCCHRS_B_0X1		(0x1u<<28)
#define	GFXTIM_CGCR_FCCHRS_B_0X2		(0x2u<<28)
#define	GFXTIM_CGCR_FCCHRS_B_0X3		(0x3u<<28)
#define	GFXTIM_CGCR_FCCHRS_B_0X4		(0x4u<<28)
#define	GFXTIM_CGCR_FCCHRS_B_0X5		(0x5u<<28)
#define	GFXTIM_CGCR_FCCHRS_B_0X6		(0x6u<<28)
#define	GFXTIM_CGCR_FCCHRS_B_0X7		(0x7u<<28)
#define	GFXTIM_CGCR_FCCFR_B_0X0			(0x0u<<24)
#define	GFXTIM_CGCR_FCCFR_B_0X1			(0x1u<<24)
#define	GFXTIM_CGCR_FCCCS_B_0X0			(0x0u<<20)
#define	GFXTIM_CGCR_FCCCS_B_0X1			(0x1u<<20)
#define	GFXTIM_CGCR_FCCCS_B_0X2			(0x2u<<20)
#define	GFXTIM_CGCR_FCCCS_B_0X3			(0x3u<<20)
#define	GFXTIM_CGCR_FCCCS_B_0X4			(0x4u<<20)
#define	GFXTIM_CGCR_FCCCS_B_0X5			(0x5u<<20)
#define	GFXTIM_CGCR_FCCCS_B_0X6			(0x6u<<20)
#define	GFXTIM_CGCR_FCCCS_B_0X7			(0x7u<<20)
#define	GFXTIM_CGCR_FCS_B_0X0			(0x0u<<16)
#define	GFXTIM_CGCR_FCS_B_0X1			(0x1u<<16)
#define	GFXTIM_CGCR_FCS_B_0X2			(0x2u<<16)
#define	GFXTIM_CGCR_FCS_B_0X3			(0x3u<<16)
#define	GFXTIM_CGCR_FCS_B_0X4			(0x4u<<16)
#define	GFXTIM_CGCR_FCS_B_0X5			(0x5u<<16)
#define	GFXTIM_CGCR_FCS_B_0X6			(0x6u<<16)
#define	GFXTIM_CGCR_FCS_B_0X7			(0x7u<<16)
#define	GFXTIM_CGCR_LCCHRS_B_0X0		(0x0u<<12)
#define	GFXTIM_CGCR_LCCHRS_B_0X1		(0x1u<<12)
#define	GFXTIM_CGCR_LCCHRS_B_0X2		(0x2u<<12)
#define	GFXTIM_CGCR_LCCHRS_B_0X3		(0x3u<<12)
#define	GFXTIM_CGCR_LCCHRS_B_0X4		(0x4u<<12)
#define	GFXTIM_CGCR_LCCHRS_B_0X5		(0x5u<<12)
#define	GFXTIM_CGCR_LCCHRS_B_0X6		(0x6u<<12)
#define	GFXTIM_CGCR_LCCHRS_B_0X7		(0x7u<<12)
#define	GFXTIM_CGCR_LCCFR_B_0X0			(0x0u<<8)
#define	GFXTIM_CGCR_LCCFR_B_0X1			(0x1u<<8)
#define	GFXTIM_CGCR_LCCCS_B_0X0			(0x0u<<4)
#define	GFXTIM_CGCR_LCCCS_B_0X1			(0x1u<<4)
#define	GFXTIM_CGCR_LCS_B_0X0			(0x0u<<0)
#define	GFXTIM_CGCR_LCS_B_0X1			(0x1u<<0)
#define	GFXTIM_CGCR_LCS_B_0X2			(0x2u<<0)
#define	GFXTIM_CGCR_LCS_B_0X3			(0x3u<<0)
#define	GFXTIM_CGCR_LCS_B_0X4			(0x4u<<0)
#define	GFXTIM_CGCR_LCS_B_0X5			(0x5u<<0)
#define	GFXTIM_CGCR_LCS_B_0X6			(0x6u<<0)
#define	GFXTIM_CGCR_LCS_B_0X7			(0x7u<<0)

// TCR Configuration

#define	GFXTIM_TCR_FRFC2R				(0x1u<<22)
#define	GFXTIM_TCR_RFC2CM				(0x1u<<21)
#define	GFXTIM_TCR_RFC2EN				(0x1u<<20)
#define	GFXTIM_TCR_FRFC1R				(0x1u<<18)
#define	GFXTIM_TCR_RFC1CM				(0x1u<<17)
#define	GFXTIM_TCR_RFC1EN				(0x1u<<16)
#define	GFXTIM_TCR_FALCR				(0x1u<<5)
#define	GFXTIM_TCR_ALCEN				(0x1u<<4)
#define	GFXTIM_TCR_FAFCR				(0x1u<<1)
#define	GFXTIM_TCR_AFCEN				(0x1u<<0)

#define	GFXTIM_TCR_FRFC2R_B_0X0			(0x0u<<22)
#define	GFXTIM_TCR_FRFC2R_B_0X1			(0x1u<<22)
#define	GFXTIM_TCR_RFC2CM_B_0X0			(0x0u<<21)
#define	GFXTIM_TCR_RFC2CM_B_0X1			(0x1u<<21)
#define	GFXTIM_TCR_RFC2EN_B_0X0			(0x0u<<20)
#define	GFXTIM_TCR_RFC2EN_B_0X1			(0x1u<<20)
#define	GFXTIM_TCR_FRFC1R_B_0X0			(0x0u<<18)
#define	GFXTIM_TCR_FRFC1R_B_0X1			(0x1u<<18)
#define	GFXTIM_TCR_RFC1CM_B_0X0			(0x0u<<17)
#define	GFXTIM_TCR_RFC1CM_B_0X1			(0x1u<<17)
#define	GFXTIM_TCR_RFC1EN_B_0X0			(0x0u<<16)
#define	GFXTIM_TCR_RFC1EN_B_0X1			(0x1u<<16)
#define	GFXTIM_TCR_FALCR_B_0X0			(0x0u<<5)
#define	GFXTIM_TCR_FALCR_B_0X1			(0x1u<<5)
#define	GFXTIM_TCR_ALCEN_B_0X0			(0x0u<<4)
#define	GFXTIM_TCR_ALCEN_B_0X1			(0x1u<<4)
#define	GFXTIM_TCR_FAFCR_B_0X0			(0x0u<<1)
#define	GFXTIM_TCR_FAFCR_B_0X1			(0x1u<<1)
#define	GFXTIM_TCR_AFCEN_B_0X0			(0x0u<<0)
#define	GFXTIM_TCR_AFCEN_B_0X1			(0x1u<<0)

// TDR Configuration

#define	GFXTIM_TDR_RFC2DIS				(0x1u<<20)
#define	GFXTIM_TDR_RFC1DIS				(0x1u<<16)
#define	GFXTIM_TDR_ALCDIS				(0x1u<<4)
#define	GFXTIM_TDR_AFCDIS				(0x1u<<0)

#define	GFXTIM_TDR_RFC2DIS_B_0X0		(0x0u<<20)
#define	GFXTIM_TDR_RFC2DIS_B_0X1		(0x1u<<20)
#define	GFXTIM_TDR_RFC1DIS_B_0X0		(0x0u<<16)
#define	GFXTIM_TDR_RFC1DIS_B_0X1		(0x1u<<16)
#define	GFXTIM_TDR_ALCDIS_B_0X0			(0x0u<<4)
#define	GFXTIM_TDR_ALCDIS_B_0X1			(0x1u<<4)
#define	GFXTIM_TDR_AFCDIS_B_0X0			(0x0u<<0)
#define	GFXTIM_TDR_AFCDIS_B_0X1			(0x1u<<0)

// EVCR Configuration

#define	GFXTIM_EVCR_EV4EN				(0x1u<<3)
#define	GFXTIM_EVCR_EV3EN				(0x1u<<2)
#define	GFXTIM_EVCR_EV2EN				(0x1u<<1)
#define	GFXTIM_EVCR_EV1EN				(0x1u<<0)

#define	GFXTIM_EVCR_EV4EN_B_0X0			(0x0u<<3)
#define	GFXTIM_EVCR_EV4EN_B_0X1			(0x1u<<3)
#define	GFXTIM_EVCR_EV3EN_B_0X0			(0x0u<<2)
#define	GFXTIM_EVCR_EV3EN_B_0X1			(0x1u<<2)
#define	GFXTIM_EVCR_EV2EN_B_0X0			(0x0u<<1)
#define	GFXTIM_EVCR_EV2EN_B_0X1			(0x1u<<1)
#define	GFXTIM_EVCR_EV1EN_B_0X0			(0x0u<<0)
#define	GFXTIM_EVCR_EV1EN_B_0X1			(0x1u<<0)

// EVSR Configuration

#define	GFXTIM_EVSR_FES4				(0x7u<<28)
#define	GFXTIM_EVSR_FES4_0				(0x1u<<28)
#define	GFXTIM_EVSR_LES4				(0x7u<<24)
#define	GFXTIM_EVSR_LES4_0				(0x1u<<24)
#define	GFXTIM_EVSR_FES3				(0x7u<<20)
#define	GFXTIM_EVSR_FES3_0				(0x1u<<20)
#define	GFXTIM_EVSR_LES3				(0x7u<<16)
#define	GFXTIM_EVSR_LES3_0				(0x1u<<16)
#define	GFXTIM_EVSR_FES2				(0x7u<<12)
#define	GFXTIM_EVSR_FES2_0				(0x1u<<12)
#define	GFXTIM_EVSR_LES2				(0x7u<<8)
#define	GFXTIM_EVSR_LES2_0				(0x1u<<8)
#define	GFXTIM_EVSR_FES1				(0x7u<<4)
#define	GFXTIM_EVSR_FES1_0				(0x1u<<4)
#define	GFXTIM_EVSR_LES1				(0x7u<<0)
#define	GFXTIM_EVSR_LES1_0				(0x1u<<0)

#define	GFXTIM_EVSR_FES4_B_0X0			(0x0u<<28)
#define	GFXTIM_EVSR_FES4_B_0X1			(0x1u<<28)
#define	GFXTIM_EVSR_FES4_B_0X2			(0x2u<<28)
#define	GFXTIM_EVSR_FES4_B_0X4			(0x4u<<28)
#define	GFXTIM_EVSR_FES4_B_0X5			(0x5u<<28)
#define	GFXTIM_EVSR_LES4_B_0X0			(0x0u<<24)
#define	GFXTIM_EVSR_LES4_B_0X1			(0x1u<<24)
#define	GFXTIM_EVSR_LES4_B_0X2			(0x2u<<24)
#define	GFXTIM_EVSR_LES4_B_0X4			(0x4u<<24)
#define	GFXTIM_EVSR_LES4_B_0X5			(0x5u<<24)
#define	GFXTIM_EVSR_FES3_B_0X0			(0x0u<<20)
#define	GFXTIM_EVSR_FES3_B_0X1			(0x1u<<20)
#define	GFXTIM_EVSR_FES3_B_0X2			(0x2u<<20)
#define	GFXTIM_EVSR_FES3_B_0X4			(0x4u<<20)
#define	GFXTIM_EVSR_FES3_B_0X5			(0x5u<<20)
#define	GFXTIM_EVSR_LES3_B_0X0			(0x0u<<16)
#define	GFXTIM_EVSR_LES3_B_0X1			(0x1u<<16)
#define	GFXTIM_EVSR_LES3_B_0X2			(0x2u<<16)
#define	GFXTIM_EVSR_LES3_B_0X4			(0x4u<<16)
#define	GFXTIM_EVSR_LES3_B_0X5			(0x5u<<16)
#define	GFXTIM_EVSR_FES2_B_0X0			(0x0u<<12)
#define	GFXTIM_EVSR_FES2_B_0X1			(0x1u<<12)
#define	GFXTIM_EVSR_FES2_B_0X2			(0x2u<<12)
#define	GFXTIM_EVSR_FES2_B_0X4			(0x4u<<12)
#define	GFXTIM_EVSR_FES2_B_0X5			(0x5u<<12)
#define	GFXTIM_EVSR_LES2_B_0X0			(0x0u<<8)
#define	GFXTIM_EVSR_LES2_B_0X1			(0x1u<<8)
#define	GFXTIM_EVSR_LES2_B_0X2			(0x2u<<8)
#define	GFXTIM_EVSR_LES2_B_0X4			(0x4u<<8)
#define	GFXTIM_EVSR_LES2_B_0X5			(0x5u<<8)
#define	GFXTIM_EVSR_FES1_B_0X0			(0x0u<<4)
#define	GFXTIM_EVSR_FES1_B_0X1			(0x1u<<4)
#define	GFXTIM_EVSR_FES1_B_0X2			(0x2u<<4)
#define	GFXTIM_EVSR_FES1_B_0X4			(0x4u<<4)
#define	GFXTIM_EVSR_FES1_B_0X5			(0x5u<<4)
#define	GFXTIM_EVSR_LES1_B_0X0			(0x0u<<0)
#define	GFXTIM_EVSR_LES1_B_0X1			(0x1u<<0)
#define	GFXTIM_EVSR_LES1_B_0X2			(0x2u<<0)
#define	GFXTIM_EVSR_LES1_B_0X4			(0x4u<<0)
#define	GFXTIM_EVSR_LES1_B_0X5			(0x5u<<0)

// WDGTCR Configuration

#define	GFXTIM_WDGTCR_FWDGR				(0x1u<<16)
#define	GFXTIM_WDGTCR_WDGCS				(0xFu<<8)
#define	GFXTIM_WDGTCR_WDGCS_0			(0x1u<<8)
#define	GFXTIM_WDGTCR_WDGHRC			(0x3u<<4)
#define	GFXTIM_WDGTCR_WDGHRC_0			(0x1u<<4)
#define	GFXTIM_WDGTCR_WDGS				(0x1u<<2)
#define	GFXTIM_WDGTCR_WDGDIS			(0x1u<<1)
#define	GFXTIM_WDGTCR_WDGEN				(0x1u<<0)

#define	GFXTIM_WDGTCR_FWDGR_B_0X0		(0x0u<<16)
#define	GFXTIM_WDGTCR_FWDGR_B_0X1		(0x1u<<16)
#define	GFXTIM_WDGTCR_WDGCS_B_0X0		(0x0u<<8)
#define	GFXTIM_WDGTCR_WDGCS_B_0X1		(0x1u<<8)
#define	GFXTIM_WDGTCR_WDGCS_B_0X2		(0x2u<<8)
#define	GFXTIM_WDGTCR_WDGCS_B_0X3		(0x3u<<8)
#define	GFXTIM_WDGTCR_WDGCS_B_0X4		(0x4u<<8)
#define	GFXTIM_WDGTCR_WDGCS_B_0X5		(0x5u<<8)
#define	GFXTIM_WDGTCR_WDGCS_B_0X6		(0x6u<<8)
#define	GFXTIM_WDGTCR_WDGCS_B_0X7		(0x7u<<8)
#define	GFXTIM_WDGTCR_WDGCS_B_0X8		(0x8u<<8)
#define	GFXTIM_WDGTCR_WDGCS_B_0X9		(0x9u<<8)
#define	GFXTIM_WDGTCR_WDGCS_B_0XA		(0xAu<<8)
#define	GFXTIM_WDGTCR_WDGCS_B_0XB		(0xBu<<8)
#define	GFXTIM_WDGTCR_WDGHRC_B_0X0		(0x0u<<4)
#define	GFXTIM_WDGTCR_WDGHRC_B_0X1		(0x1u<<4)
#define	GFXTIM_WDGTCR_WDGHRC_B_0X2		(0x2u<<4)
#define	GFXTIM_WDGTCR_WDGS_B_0X0		(0x0u<<2)
#define	GFXTIM_WDGTCR_WDGS_B_0X1		(0x1u<<2)
#define	GFXTIM_WDGTCR_WDGDIS_B_0X0		(0x0u<<1)
#define	GFXTIM_WDGTCR_WDGDIS_B_0X1		(0x1u<<1)
#define	GFXTIM_WDGTCR_WDGEN_B_0X0		(0x0u<<0)
#define	GFXTIM_WDGTCR_WDGEN_B_0X1		(0x1u<<0)

// ISR Configuration

#define	GFXTIM_ISR_WDGPF				(0x1u<<25)
#define	GFXTIM_ISR_WDGAF				(0x1u<<24)
#define	GFXTIM_ISR_EV4F					(0x1u<<19)
#define	GFXTIM_ISR_EV3F					(0x1u<<18)
#define	GFXTIM_ISR_EV2F					(0x1u<<17)
#define	GFXTIM_ISR_EV1F					(0x1u<<16)
#define	GFXTIM_ISR_RFC2RF				(0x1u<<13)
#define	GFXTIM_ISR_RFC1RF				(0x1u<<12)
#define	GFXTIM_ISR_ALCC2F				(0x1u<<9)
#define	GFXTIM_ISR_ALCC1F				(0x1u<<8)
#define	GFXTIM_ISR_AFCC1F				(0x1u<<4)
#define	GFXTIM_ISR_TEF					(0x1u<<2)
#define	GFXTIM_ISR_ALCOF				(0x1u<<1)
#define	GFXTIM_ISR_AFCOF				(0x1u<<0)

#define	GFXTIM_ISR_WDGPF_B_0X0			(0x0u<<25)
#define	GFXTIM_ISR_WDGPF_B_0X1			(0x1u<<25)
#define	GFXTIM_ISR_WDGAF_B_0X0			(0x0u<<24)
#define	GFXTIM_ISR_WDGAF_B_0X1			(0x1u<<24)
#define	GFXTIM_ISR_EV4F_B_0X0			(0x0u<<19)
#define	GFXTIM_ISR_EV4F_B_0X1			(0x1u<<19)
#define	GFXTIM_ISR_EV3F_B_0X0			(0x0u<<18)
#define	GFXTIM_ISR_EV3F_B_0X1			(0x1u<<18)
#define	GFXTIM_ISR_EV2F_B_0X0			(0x0u<<17)
#define	GFXTIM_ISR_EV2F_B_0X1			(0x1u<<17)
#define	GFXTIM_ISR_EV1F_B_0X0			(0x0u<<16)
#define	GFXTIM_ISR_EV1F_B_0X1			(0x1u<<16)
#define	GFXTIM_ISR_RFC2RF_B_0X0			(0x0u<<13)
#define	GFXTIM_ISR_RFC2RF_B_0X1			(0x1u<<13)
#define	GFXTIM_ISR_RFC1RF_B_0X0			(0x0u<<12)
#define	GFXTIM_ISR_RFC1RF_B_0X1			(0x1u<<12)
#define	GFXTIM_ISR_ALCC2F_B_0X0			(0x0u<<9)
#define	GFXTIM_ISR_ALCC2F_B_0X1			(0x1u<<9)
#define	GFXTIM_ISR_ALCC1F_B_0X0			(0x0u<<8)
#define	GFXTIM_ISR_ALCC1F_B_0X1			(0x1u<<8)
#define	GFXTIM_ISR_AFCC1F_B_0X0			(0x0u<<4)
#define	GFXTIM_ISR_AFCC1F_B_0X1			(0x1u<<4)
#define	GFXTIM_ISR_TEF_B_0X0			(0x0u<<2)
#define	GFXTIM_ISR_TEF_B_0X1			(0x1u<<2)
#define	GFXTIM_ISR_ALCOF_B_0X0			(0x0u<<1)
#define	GFXTIM_ISR_ALCOF_B_0X1			(0x1u<<1)
#define	GFXTIM_ISR_AFCOF_B_0X0			(0x0u<<0)
#define	GFXTIM_ISR_AFCOF_B_0X1			(0x1u<<0)

// ICR Configuration

#define	GFXTIM_ICR_CWDGPF				(0x1u<<25)
#define	GFXTIM_ICR_CWDGAF				(0x1u<<24)
#define	GFXTIM_ICR_CEV4F				(0x1u<<19)
#define	GFXTIM_ICR_CEV3F				(0x1u<<18)
#define	GFXTIM_ICR_CEV2F				(0x1u<<17)
#define	GFXTIM_ICR_CEV1F				(0x1u<<16)
#define	GFXTIM_ICR_CRFC2RF				(0x1u<<13)
#define	GFXTIM_ICR_CRFC1RF				(0x1u<<12)
#define	GFXTIM_ICR_CALCC2F				(0x1u<<9)
#define	GFXTIM_ICR_CALCC1F				(0x1u<<8)
#define	GFXTIM_ICR_CAFCC1F				(0x1u<<4)
#define	GFXTIM_ICR_CTEF					(0x1u<<2)
#define	GFXTIM_ICR_CALCOF				(0x1u<<1)
#define	GFXTIM_ICR_CAFCOF				(0x1u<<0)

#define	GFXTIM_ICR_CWDGPF_B_0X0			(0x0u<<25)
#define	GFXTIM_ICR_CWDGPF_B_0X1			(0x1u<<25)
#define	GFXTIM_ICR_CWDGAF_B_0X0			(0x0u<<24)
#define	GFXTIM_ICR_CWDGAF_B_0X1			(0x1u<<24)
#define	GFXTIM_ICR_CEV4F_B_0X0			(0x0u<<19)
#define	GFXTIM_ICR_CEV4F_B_0X1			(0x1u<<19)
#define	GFXTIM_ICR_CEV3F_B_0X0			(0x0u<<18)
#define	GFXTIM_ICR_CEV3F_B_0X1			(0x1u<<18)
#define	GFXTIM_ICR_CEV2F_B_0X0			(0x0u<<17)
#define	GFXTIM_ICR_CEV2F_B_0X1			(0x1u<<17)
#define	GFXTIM_ICR_CEV1F_B_0X0			(0x0u<<16)
#define	GFXTIM_ICR_CEV1F_B_0X1			(0x1u<<16)
#define	GFXTIM_ICR_CRFC2RF_B_0X0		(0x0u<<13)
#define	GFXTIM_ICR_CRFC2RF_B_0X1		(0x1u<<13)
#define	GFXTIM_ICR_CRFC1RF_B_0X0		(0x0u<<12)
#define	GFXTIM_ICR_CRFC1RF_B_0X1		(0x1u<<12)
#define	GFXTIM_ICR_CALCC2F_B_0X0		(0x0u<<9)
#define	GFXTIM_ICR_CALCC2F_B_0X1		(0x1u<<9)
#define	GFXTIM_ICR_CALCC1F_B_0X0		(0x0u<<8)
#define	GFXTIM_ICR_CALCC1F_B_0X1		(0x1u<<8)
#define	GFXTIM_ICR_CAFCC1F_B_0X0		(0x0u<<4)
#define	GFXTIM_ICR_CAFCC1F_B_0X1		(0x1u<<4)
#define	GFXTIM_ICR_CTEF_B_0X0			(0x0u<<2)
#define	GFXTIM_ICR_CTEF_B_0X1			(0x1u<<2)
#define	GFXTIM_ICR_CALCOF_B_0X0			(0x0u<<1)
#define	GFXTIM_ICR_CALCOF_B_0X1			(0x1u<<1)
#define	GFXTIM_ICR_CAFCOF_B_0X0			(0x0u<<0)
#define	GFXTIM_ICR_CAFCOF_B_0X1			(0x1u<<0)

// IER Configuration

#define	GFXTIM_IER_WDGPIE				(0x1u<<25)
#define	GFXTIM_IER_WDGAIE				(0x1u<<24)
#define	GFXTIM_IER_EV4IE				(0x1u<<19)
#define	GFXTIM_IER_EV3IE				(0x1u<<18)
#define	GFXTIM_IER_EV2IE				(0x1u<<17)
#define	GFXTIM_IER_EV1IE				(0x1u<<16)
#define	GFXTIM_IER_RFC2RIE				(0x1u<<13)
#define	GFXTIM_IER_RFC1RIE				(0x1u<<12)
#define	GFXTIM_IER_ALCC2IE				(0x1u<<9)
#define	GFXTIM_IER_ALCC1IE				(0x1u<<8)
#define	GFXTIM_IER_AFCC1IE				(0x1u<<4)
#define	GFXTIM_IER_TEIE					(0x1u<<2)
#define	GFXTIM_IER_ALCOIE				(0x1u<<1)
#define	GFXTIM_IER_AFCOIE				(0x1u<<0)

#define	GFXTIM_IER_WDGPIE_B_0X0			(0x0u<<25)
#define	GFXTIM_IER_WDGPIE_B_0X1			(0x1u<<25)
#define	GFXTIM_IER_WDGAIE_B_0X0			(0x0u<<24)
#define	GFXTIM_IER_WDGAIE_B_0X1			(0x1u<<24)
#define	GFXTIM_IER_EV4IE_B_0X0			(0x0u<<19)
#define	GFXTIM_IER_EV4IE_B_0X1			(0x1u<<19)
#define	GFXTIM_IER_EV3IE_B_0X0			(0x0u<<18)
#define	GFXTIM_IER_EV3IE_B_0X1			(0x1u<<18)
#define	GFXTIM_IER_EV2IE_B_0X0			(0x0u<<17)
#define	GFXTIM_IER_EV2IE_B_0X1			(0x1u<<17)
#define	GFXTIM_IER_EV1IE_B_0X0			(0x0u<<16)
#define	GFXTIM_IER_EV1IE_B_0X1			(0x1u<<16)
#define	GFXTIM_IER_RFC2RIE_B_0X0		(0x0u<<13)
#define	GFXTIM_IER_RFC2RIE_B_0X1		(0x1u<<13)
#define	GFXTIM_IER_RFC1RIE_B_0X0		(0x0u<<12)
#define	GFXTIM_IER_RFC1RIE_B_0X1		(0x1u<<12)
#define	GFXTIM_IER_ALCC2IE_B_0X0		(0x0u<<9)
#define	GFXTIM_IER_ALCC2IE_B_0X1		(0x1u<<9)
#define	GFXTIM_IER_ALCC1IE_B_0X0		(0x0u<<8)
#define	GFXTIM_IER_ALCC1IE_B_0X1		(0x1u<<8)
#define	GFXTIM_IER_AFCC1IE_B_0X0		(0x0u<<4)
#define	GFXTIM_IER_AFCC1IE_B_0X1		(0x1u<<4)
#define	GFXTIM_IER_TEIE_B_0X0			(0x0u<<2)
#define	GFXTIM_IER_TEIE_B_0X1			(0x1u<<2)
#define	GFXTIM_IER_ALCOIE_B_0X0			(0x0u<<1)
#define	GFXTIM_IER_ALCOIE_B_0X1			(0x1u<<1)
#define	GFXTIM_IER_AFCOIE_B_0X0			(0x0u<<0)
#define	GFXTIM_IER_AFCOIE_B_0X1			(0x1u<<0)

// TSR Configuration

#define	GFXTIM_TSR_RFC2S				(0x1u<<20)
#define	GFXTIM_TSR_RFC1S				(0x1u<<16)
#define	GFXTIM_TSR_ALCS					(0x1u<<4)
#define	GFXTIM_TSR_AFCS					(0x1u<<0)

#define	GFXTIM_TSR_RFC2S_B_0X0			(0x0u<<20)
#define	GFXTIM_TSR_RFC2S_B_0X1			(0x1u<<20)
#define	GFXTIM_TSR_RFC1S_B_0X0			(0x0u<<16)
#define	GFXTIM_TSR_RFC1S_B_0X1			(0x1u<<16)
#define	GFXTIM_TSR_ALCS_B_0X0			(0x0u<<4)
#define	GFXTIM_TSR_ALCS_B_0X1			(0x1u<<4)
#define	GFXTIM_TSR_AFCS_B_0X0			(0x0u<<0)
#define	GFXTIM_TSR_AFCS_B_0X1			(0x1u<<0)

// LCCRR Configuration

#define	GFXTIM_LCCRR_RELOAD				(0x3FFFFFu<<0)
#define	GFXTIM_LCCRR_RELOAD_0			(0x1u<<0)

// FCCRR Configuration

#define	GFXTIM_FCCRR_RELOAD				(0xFFFu<<0)
#define	GFXTIM_FCCRR_RELOAD_0			(0x1u<<0)

// ATR Configuration

#define	GFXTIM_ATR_FRAME				(0xFFFFFu<<12)
#define	GFXTIM_ATR_FRAME_0				(0x1u<<12)
#define	GFXTIM_ATR_LINE					(0xFFFu<<0)
#define	GFXTIM_ATR_LINE_0				(0x1u<<0)

// AFCR Configuration

#define	GFXTIM_AFCR_FRAME				(0xFFFFFu<<0)
#define	GFXTIM_AFCR_FRAME_0				(0x1u<<0)

// ALCR Configuration

#define	GFXTIM_ALCR_LINE				(0xFFFu<<0)
#define	GFXTIM_ALCR_LINE_0				(0x1u<<0)

// AFCC1R Configuration

#define	GFXTIM_AFCC1R_FRAME				(0xFFFFFu<<0)
#define	GFXTIM_AFCC1R_FRAME_0			(0x1u<<0)

// ALCC1R Configuration

#define	GFXTIM_ALCC1R_LINE				(0xFFFu<<0)
#define	GFXTIM_ALCC1R_LINE_0			(0x1u<<0)

// ALCC2R Configuration

#define	GFXTIM_ALCC2R_LINE				(0xFFFu<<0)
#define	GFXTIM_ALCC2R_LINE_0			(0x1u<<0)

// RFC1R Configuration

#define	GFXTIM_RFC1R_FRAME				(0xFFFu<<0)
#define	GFXTIM_RFC1R_FRAME_0			(0x1u<<0)

// RFC1RR Configuration

#define	GFXTIM_RFC1RR_FRAME				(0xFFFu<<0)
#define	GFXTIM_RFC1RR_FRAME_0			(0x1u<<0)

// RFC2R Configuration

#define	GFXTIM_RFC2R_FRAME				(0xFFFu<<0)
#define	GFXTIM_RFC2R_FRAME_0			(0x1u<<0)

// RFC2RR Configuration

#define	GFXTIM_RFC2RR_FRAME				(0xFFFu<<0)
#define	GFXTIM_RFC2RR_FRAME_0			(0x1u<<0)

// WDGCR Configuration

#define	GFXTIM_WDGCR_VALUE				(0xFFFFu<<0)
#define	GFXTIM_WDGCR_VALUE_0			(0x1u<<0)

// WDGRR Configuration

#define	GFXTIM_WDGRR_RELOAD				(0xFFFFu<<0)
#define	GFXTIM_WDGRR_RELOAD_0			(0x1u<<0)

// WDGPAR Configuration

#define	GFXTIM_WDGPAR_PREALARM			(0xFFFFu<<0)
#define	GFXTIM_WDGPAR_PREALARM_0		(0x1u<<0)
