/*
; stm32U5Gx_lpdma.
; ================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_lpdma equates.
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

// LPDMA address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	SECCFGR;
	volatile	uint32_t	PRIVCFGR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	MISR;
	volatile	uint32_t	SMISR;
	volatile	uint32_t	RESERVED1[15];
	volatile	uint32_t	C0LBAR;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	C0FCR;
	volatile	uint32_t	C0SR;
	volatile	uint32_t	C0CR;
	volatile	uint32_t	RESERVED3[10];
	volatile	uint32_t	C0TR1;
	volatile	uint32_t	C0TR2;
	volatile	uint32_t	C0BR1;
	volatile	uint32_t	C0SAR;
	volatile	uint32_t	C0DAR;
	volatile	uint32_t	RESERVED4[10];
	volatile	uint32_t	C0LLR;
	volatile	uint32_t	C1LBAR;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	C1FCR;
	volatile	uint32_t	C1SR;
	volatile	uint32_t	C1CR;
	volatile	uint32_t	RESERVED6[10];
	volatile	uint32_t	C1TR1;
	volatile	uint32_t	C1TR2;
	volatile	uint32_t	C1BR1;
	volatile	uint32_t	C1SAR;
	volatile	uint32_t	C1DAR;
	volatile	uint32_t	RESERVED7[10];
	volatile	uint32_t	C1LLR;
	volatile	uint32_t	C2LBAR;
	volatile	uint32_t	RESERVED8[2];
	volatile	uint32_t	C2FCR;
	volatile	uint32_t	C2SR;
	volatile	uint32_t	C2CR;
	volatile	uint32_t	RESERVED9[10];
	volatile	uint32_t	C2TR1;
	volatile	uint32_t	C2TR2;
	volatile	uint32_t	C2BR1;
	volatile	uint32_t	C2SAR;
	volatile	uint32_t	C2DAR;
	volatile	uint32_t	RESERVED10[10];
	volatile	uint32_t	C2LLR;
	volatile	uint32_t	C3LBAR;
	volatile	uint32_t	RESERVED11[2];
	volatile	uint32_t	C3FCR;
	volatile	uint32_t	C3SR;
	volatile	uint32_t	C3CR;
	volatile	uint32_t	RESERVED12[10];
	volatile	uint32_t	C3TR1;
	volatile	uint32_t	C3TR2;
	volatile	uint32_t	C3BR1;
	volatile	uint32_t	C3SAR;
	volatile	uint32_t	C3DAR;
	volatile	uint32_t	RESERVED13[10];
	volatile	uint32_t	C3LLR;
} LPDMA_TypeDef;

#if (defined(__cplusplus))
#define	LPDMA1_NS	reinterpret_cast<LPDMA_TypeDef *>(0x46025000u)
#define	LPDMA1_S	reinterpret_cast<LPDMA_TypeDef *>(0x56025000u)

#else
#define	LPDMA1_NS	((LPDMA_TypeDef *)0x46025000u)
#define	LPDMA1_S	((LPDMA_TypeDef *)0x56025000u)
#endif

// SECCFGR Configuration

#define	LPDMA_SECCFGR_SEC3		(0x1u<<3)
#define	LPDMA_SECCFGR_SEC2		(0x1u<<2)
#define	LPDMA_SECCFGR_SEC1		(0x1u<<1)
#define	LPDMA_SECCFGR_SEC0		(0x1u<<0)

// PRIVCFGR Configuration

#define	LPDMA_PRIVCFGR_PRIV3	(0x1u<<3)
#define	LPDMA_PRIVCFGR_PRIV2	(0x1u<<2)
#define	LPDMA_PRIVCFGR_PRIV1	(0x1u<<1)
#define	LPDMA_PRIVCFGR_PRIV0	(0x1u<<0)

// MISR Configuration

#define	LPDMA_MISR_MIS3			(0x1u<<3)
#define	LPDMA_MISR_MIS2			(0x1u<<2)
#define	LPDMA_MISR_MIS1			(0x1u<<1)
#define	LPDMA_MISR_MIS0			(0x1u<<0)

// SMISR Configuration

#define	LPDMA_SMISR_MIS3		(0x1u<<3)
#define	LPDMA_SMISR_MIS2		(0x1u<<2)
#define	LPDMA_SMISR_MIS1		(0x1u<<1)
#define	LPDMA_SMISR_MIS0		(0x1u<<0)

// C0LBAR Configuration

#define	LPDMA_C0LBAR_LBA		(0xFFFFu<<16)
#define	LPDMA_C0LBAR_LBA_0		(0x1u<<16)

// C0FCR Configuration

#define	LPDMA_C0FCR_SUSPF		(0x1u<<13)
#define	LPDMA_C0FCR_USEF		(0x1u<<12)
#define	LPDMA_C0FCR_ULEF		(0x1u<<11)
#define	LPDMA_C0FCR_DTEF		(0x1u<<10)
#define	LPDMA_C0FCR_HTF			(0x1u<<9)
#define	LPDMA_C0FCR_TCF			(0x1u<<8)

// C0SR Configuration

#define	LPDMA_C0SR_SUSPF		(0x1u<<13)
#define	LPDMA_C0SR_USEF			(0x1u<<12)
#define	LPDMA_C0SR_ULEF			(0x1u<<11)
#define	LPDMA_C0SR_DTEF			(0x1u<<10)
#define	LPDMA_C0SR_HTF			(0x1u<<9)
#define	LPDMA_C0SR_TCF			(0x1u<<8)
#define	LPDMA_C0SR_IDLEF		(0x1u<<0)

// C0CR Configuration

#define	LPDMA_C0CR_PRIO			(0x3u<<22)
#define	LPDMA_C0CR_PRIO_0		(0x1u<<22)
#define	LPDMA_C0CR_LSM			(0x1u<<16)
#define	LPDMA_C0CR_SUSPIE		(0x1u<<13)
#define	LPDMA_C0CR_USEIE		(0x1u<<12)
#define	LPDMA_C0CR_ULEIE		(0x1u<<11)
#define	LPDMA_C0CR_DTEIE		(0x1u<<10)
#define	LPDMA_C0CR_HTIE			(0x1u<<9)
#define	LPDMA_C0CR_TCIE			(0x1u<<8)
#define	LPDMA_C0CR_SUSP			(0x1u<<2)
#define	LPDMA_C0CR_RESET		(0x1u<<1)
#define	LPDMA_C0CR_EN			(0x1u<<0)

// C0TR1 Configuration

#define	LPDMA_C0TR1_DSEC		(0x1u<<31)
#define	LPDMA_C0TR1_DINC		(0x1u<<19)
#define	LPDMA_C0TR1_DDW_LOG2	(0x3u<<16)
#define	LPDMA_C0TR1_DDW_LOG2_0	(0x1u<<16)
#define	LPDMA_C0TR1_SSEC		(0x1u<<15)
#define	LPDMA_C0TR1_PAM			(0x3u<<11)
#define	LPDMA_C0TR1_PAM_0		(0x1u<<11)
#define	LPDMA_C0TR1_SINC		(0x1u<<3)
#define	LPDMA_C0TR1_SDW_LOG2	(0x3u<<0)
#define	LPDMA_C0TR1_SDW_LOG2_0	(0x1u<<0)

// C0TR2 Configuration

#define	LPDMA_C0TR2_TCEM		(0x3u<<30)
#define	LPDMA_C0TR2_TCEM_0		(0x1u<<30)
#define	LPDMA_C0TR2_TRIGPOL		(0x3u<<24)
#define	LPDMA_C0TR2_TRIGPOL_0	(0x1u<<24)
#define	LPDMA_C0TR2_TRIGSEL		(0x1Fu<<16)
#define	LPDMA_C0TR2_TRIGSEL_0	(0x1u<<16)
#define	LPDMA_C0TR2_TRIGM		(0x3u<<14)
#define	LPDMA_C0TR2_TRIGM_0		(0x1u<<14)
#define	LPDMA_C0TR2_BREQ		(0x1u<<11)
#define	LPDMA_C0TR2_SWREQ		(0x1u<<9)
#define	LPDMA_C0TR2_REQSEL		(0x1Fu<<0)
#define	LPDMA_C0TR2_REQSEL_0	(0x1u<<0)

// C0BR1 Configuration

#define	LPDMA_C0BR1_BNDT		(0xFFFFu<<0)
#define	LPDMA_C0BR1_BNDT_0		(0x1u<<0)

// C0SAR Configuration

#define	LPDMA_C0SAR_SA			(0xFFFFFFFFu<<0)
#define	LPDMA_C0SAR_SA_0		(0x1u<<0)

// C0DAR Configuration

#define	LPDMA_C0DAR_DA			(0xFFFFFFFFu<<0)
#define	LPDMA_C0DAR_DA_0		(0x1u<<0)

// C0LLR Configuration

#define	LPDMA_C0LLR_UT1			(0x1u<<31)
#define	LPDMA_C0LLR_UT2			(0x1u<<30)
#define	LPDMA_C0LLR_UB1			(0x1u<<29)
#define	LPDMA_C0LLR_USA			(0x1u<<28)
#define	LPDMA_C0LLR_UDA			(0x1u<<27)
#define	LPDMA_C0LLR_ULL			(0x1u<<16)
#define	LPDMA_C0LLR_LA			(0x3FFFu<<2)
#define	LPDMA_C0LLR_LA_0		(0x1u<<2)

// C1LBAR Configuration

#define	LPDMA_C1LBAR_LBA		(0xFFFFu<<16)
#define	LPDMA_C1LBAR_LBA_0		(0x1u<<16)

// C1FCR Configuration

#define	LPDMA_C1FCR_SUSPF		(0x1u<<13)
#define	LPDMA_C1FCR_USEF		(0x1u<<12)
#define	LPDMA_C1FCR_ULEF		(0x1u<<11)
#define	LPDMA_C1FCR_DTEF		(0x1u<<10)
#define	LPDMA_C1FCR_HTF			(0x1u<<9)
#define	LPDMA_C1FCR_TCF			(0x1u<<8)

// C1SR Configuration

#define	LPDMA_C1SR_SUSPF		(0x1u<<13)
#define	LPDMA_C1SR_USEF			(0x1u<<12)
#define	LPDMA_C1SR_ULEF			(0x1u<<11)
#define	LPDMA_C1SR_DTEF			(0x1u<<10)
#define	LPDMA_C1SR_HTF			(0x1u<<9)
#define	LPDMA_C1SR_TCF			(0x1u<<8)
#define	LPDMA_C1SR_IDLEF		(0x1u<<0)

// C1CR Configuration

#define	LPDMA_C1CR_PRIO			(0x3u<<22)
#define	LPDMA_C1CR_PRIO_0		(0x1u<<22)
#define	LPDMA_C1CR_LSM			(0x1u<<16)
#define	LPDMA_C1CR_SUSPIE		(0x1u<<13)
#define	LPDMA_C1CR_USEIE		(0x1u<<12)
#define	LPDMA_C1CR_ULEIE		(0x1u<<11)
#define	LPDMA_C1CR_DTEIE		(0x1u<<10)
#define	LPDMA_C1CR_HTIE			(0x1u<<9)
#define	LPDMA_C1CR_TCIE			(0x1u<<8)
#define	LPDMA_C1CR_SUSP			(0x1u<<2)
#define	LPDMA_C1CR_RESET		(0x1u<<1)
#define	LPDMA_C1CR_EN			(0x1u<<0)

// C1TR1 Configuration

#define	LPDMA_C1TR1_DSEC		(0x1u<<31)
#define	LPDMA_C1TR1_DINC		(0x1u<<19)
#define	LPDMA_C1TR1_DDW_LOG2	(0x3u<<16)
#define	LPDMA_C1TR1_DDW_LOG2_0	(0x1u<<16)
#define	LPDMA_C1TR1_SSEC		(0x1u<<15)
#define	LPDMA_C1TR1_PAM			(0x3u<<11)
#define	LPDMA_C1TR1_PAM_0		(0x1u<<11)
#define	LPDMA_C1TR1_SINC		(0x1u<<3)
#define	LPDMA_C1TR1_SDW_LOG2	(0x3u<<0)
#define	LPDMA_C1TR1_SDW_LOG2_0	(0x1u<<0)

// C1TR2 Configuration

#define	LPDMA_C1TR2_TCEM		(0x3u<<30)
#define	LPDMA_C1TR2_TCEM_0		(0x1u<<30)
#define	LPDMA_C1TR2_TRIGPOL		(0x3u<<24)
#define	LPDMA_C1TR2_TRIGPOL_0	(0x1u<<24)
#define	LPDMA_C1TR2_TRIGSEL		(0x1Fu<<16)
#define	LPDMA_C1TR2_TRIGSEL_0	(0x1u<<16)
#define	LPDMA_C1TR2_TRIGM		(0x3u<<14)
#define	LPDMA_C1TR2_TRIGM_0		(0x1u<<14)
#define	LPDMA_C1TR2_BREQ		(0x1u<<11)
#define	LPDMA_C1TR2_SWREQ		(0x1u<<9)
#define	LPDMA_C1TR2_REQSEL		(0x1Fu<<0)
#define	LPDMA_C1TR2_REQSEL_0	(0x1u<<0)

// C1BR1 Configuration

#define	LPDMA_C1BR1_BNDT		(0xFFFFu<<0)
#define	LPDMA_C1BR1_BNDT_0		(0x1u<<0)

// C1SAR Configuration

#define	LPDMA_C1SAR_SA			(0xFFFFFFFFu<<0)
#define	LPDMA_C1SAR_SA_0		(0x1u<<0)

// C1DAR Configuration

#define	LPDMA_C1DAR_DA			(0xFFFFFFFFu<<0)
#define	LPDMA_C1DAR_DA_0		(0x1u<<0)

// C1LLR Configuration

#define	LPDMA_C1LLR_UT1			(0x1u<<31)
#define	LPDMA_C1LLR_UT2			(0x1u<<30)
#define	LPDMA_C1LLR_UB1			(0x1u<<29)
#define	LPDMA_C1LLR_USA			(0x1u<<28)
#define	LPDMA_C1LLR_UDA			(0x1u<<27)
#define	LPDMA_C1LLR_ULL			(0x1u<<16)
#define	LPDMA_C1LLR_LA			(0x3FFFu<<2)
#define	LPDMA_C1LLR_LA_0		(0x1u<<2)

// C2LBAR Configuration

#define	LPDMA_C2LBAR_LBA		(0xFFFFu<<16)
#define	LPDMA_C2LBAR_LBA_0		(0x1u<<16)

// C2FCR Configuration

#define	LPDMA_C2FCR_SUSPF		(0x1u<<13)
#define	LPDMA_C2FCR_USEF		(0x1u<<12)
#define	LPDMA_C2FCR_ULEF		(0x1u<<11)
#define	LPDMA_C2FCR_DTEF		(0x1u<<10)
#define	LPDMA_C2FCR_HTF			(0x1u<<9)
#define	LPDMA_C2FCR_TCF			(0x1u<<8)

// C2SR Configuration

#define	LPDMA_C2SR_SUSPF		(0x1u<<13)
#define	LPDMA_C2SR_USEF			(0x1u<<12)
#define	LPDMA_C2SR_ULEF			(0x1u<<11)
#define	LPDMA_C2SR_DTEF			(0x1u<<10)
#define	LPDMA_C2SR_HTF			(0x1u<<9)
#define	LPDMA_C2SR_TCF			(0x1u<<8)
#define	LPDMA_C2SR_IDLEF		(0x1u<<0)

// C2CR Configuration

#define	LPDMA_C2CR_PRIO			(0x3u<<22)
#define	LPDMA_C2CR_PRIO_0		(0x1u<<22)
#define	LPDMA_C2CR_LSM			(0x1u<<16)
#define	LPDMA_C2CR_SUSPIE		(0x1u<<13)
#define	LPDMA_C2CR_USEIE		(0x1u<<12)
#define	LPDMA_C2CR_ULEIE		(0x1u<<11)
#define	LPDMA_C2CR_DTEIE		(0x1u<<10)
#define	LPDMA_C2CR_HTIE			(0x1u<<9)
#define	LPDMA_C2CR_TCIE			(0x1u<<8)
#define	LPDMA_C2CR_SUSP			(0x1u<<2)
#define	LPDMA_C2CR_RESET		(0x1u<<1)
#define	LPDMA_C2CR_EN			(0x1u<<0)

// C2TR1 Configuration

#define	LPDMA_C2TR1_DSEC		(0x1u<<31)
#define	LPDMA_C2TR1_DINC		(0x1u<<19)
#define	LPDMA_C2TR1_DDW_LOG2	(0x3u<<16)
#define	LPDMA_C2TR1_DDW_LOG2_0	(0x1u<<16)
#define	LPDMA_C2TR1_SSEC		(0x1u<<15)
#define	LPDMA_C2TR1_PAM			(0x3u<<11)
#define	LPDMA_C2TR1_PAM_0		(0x1u<<11)
#define	LPDMA_C2TR1_SINC		(0x1u<<3)
#define	LPDMA_C2TR1_SDW_LOG2	(0x3u<<0)
#define	LPDMA_C2TR1_SDW_LOG2_0	(0x1u<<0)

// C2TR2 Configuration

#define	LPDMA_C2TR2_TCEM		(0x3u<<30)
#define	LPDMA_C2TR2_TCEM_0		(0x1u<<30)
#define	LPDMA_C2TR2_TRIGPOL		(0x3u<<24)
#define	LPDMA_C2TR2_TRIGPOL_0	(0x1u<<24)
#define	LPDMA_C2TR2_TRIGSEL		(0x1Fu<<16)
#define	LPDMA_C2TR2_TRIGSEL_0	(0x1u<<16)
#define	LPDMA_C2TR2_TRIGM		(0x3u<<14)
#define	LPDMA_C2TR2_TRIGM_0		(0x1u<<14)
#define	LPDMA_C2TR2_BREQ		(0x1u<<11)
#define	LPDMA_C2TR2_SWREQ		(0x1u<<9)
#define	LPDMA_C2TR2_REQSEL		(0x1Fu<<0)
#define	LPDMA_C2TR2_REQSEL_0	(0x1u<<0)

// C2BR1 Configuration

#define	LPDMA_C2BR1_BNDT		(0xFFFFu<<0)
#define	LPDMA_C2BR1_BNDT_0		(0x1u<<0)

// C2SAR Configuration

#define	LPDMA_C2SAR_SA			(0xFFFFFFFFu<<0)
#define	LPDMA_C2SAR_SA_0		(0x1u<<0)

// C2DAR Configuration

#define	LPDMA_C2DAR_DA			(0xFFFFFFFFu<<0)
#define	LPDMA_C2DAR_DA_0		(0x1u<<0)

// C2LLR Configuration

#define	LPDMA_C2LLR_UT1			(0x1u<<31)
#define	LPDMA_C2LLR_UT2			(0x1u<<30)
#define	LPDMA_C2LLR_UB1			(0x1u<<29)
#define	LPDMA_C2LLR_USA			(0x1u<<28)
#define	LPDMA_C2LLR_UDA			(0x1u<<27)
#define	LPDMA_C2LLR_ULL			(0x1u<<16)
#define	LPDMA_C2LLR_LA			(0x3FFFu<<2)
#define	LPDMA_C2LLR_LA_0		(0x1u<<2)

// C3LBAR Configuration

#define	LPDMA_C3LBAR_LBA		(0xFFFFu<<16)
#define	LPDMA_C3LBAR_LBA_0		(0x1u<<16)

// C3FCR Configuration

#define	LPDMA_C3FCR_SUSPF		(0x1u<<13)
#define	LPDMA_C3FCR_USEF		(0x1u<<12)
#define	LPDMA_C3FCR_ULEF		(0x1u<<11)
#define	LPDMA_C3FCR_DTEF		(0x1u<<10)
#define	LPDMA_C3FCR_HTF			(0x1u<<9)
#define	LPDMA_C3FCR_TCF			(0x1u<<8)

// C3SR Configuration

#define	LPDMA_C3SR_SUSPF		(0x1u<<13)
#define	LPDMA_C3SR_USEF			(0x1u<<12)
#define	LPDMA_C3SR_ULEF			(0x1u<<11)
#define	LPDMA_C3SR_DTEF			(0x1u<<10)
#define	LPDMA_C3SR_HTF			(0x1u<<9)
#define	LPDMA_C3SR_TCF			(0x1u<<8)
#define	LPDMA_C3SR_IDLEF		(0x1u<<0)

// C3CR Configuration

#define	LPDMA_C3CR_PRIO			(0x3u<<22)
#define	LPDMA_C3CR_PRIO_0		(0x1u<<22)
#define	LPDMA_C3CR_LSM			(0x1u<<16)
#define	LPDMA_C3CR_SUSPIE		(0x1u<<13)
#define	LPDMA_C3CR_USEIE		(0x1u<<12)
#define	LPDMA_C3CR_ULEIE		(0x1u<<11)
#define	LPDMA_C3CR_DTEIE		(0x1u<<10)
#define	LPDMA_C3CR_HTIE			(0x1u<<9)
#define	LPDMA_C3CR_TCIE			(0x1u<<8)
#define	LPDMA_C3CR_SUSP			(0x1u<<2)
#define	LPDMA_C3CR_RESET		(0x1u<<1)
#define	LPDMA_C3CR_EN			(0x1u<<0)

// C3TR1 Configuration

#define	LPDMA_C3TR1_DSEC		(0x1u<<31)
#define	LPDMA_C3TR1_DINC		(0x1u<<19)
#define	LPDMA_C3TR1_DDW_LOG2	(0x3u<<16)
#define	LPDMA_C3TR1_DDW_LOG2_0	(0x1u<<16)
#define	LPDMA_C3TR1_SSEC		(0x1u<<15)
#define	LPDMA_C3TR1_PAM			(0x3u<<11)
#define	LPDMA_C3TR1_PAM_0		(0x1u<<11)
#define	LPDMA_C3TR1_SINC		(0x1u<<3)
#define	LPDMA_C3TR1_SDW_LOG2	(0x3u<<0)
#define	LPDMA_C3TR1_SDW_LOG2_0	(0x1u<<0)

// C3TR2 Configuration

#define	LPDMA_C3TR2_TCEM		(0x3u<<30)
#define	LPDMA_C3TR2_TCEM_0		(0x1u<<30)
#define	LPDMA_C3TR2_TRIGPOL		(0x3u<<24)
#define	LPDMA_C3TR2_TRIGPOL_0	(0x1u<<24)
#define	LPDMA_C3TR2_TRIGSEL		(0x1Fu<<16)
#define	LPDMA_C3TR2_TRIGSEL_0	(0x1u<<16)
#define	LPDMA_C3TR2_TRIGM		(0x3u<<14)
#define	LPDMA_C3TR2_TRIGM_0		(0x1u<<14)
#define	LPDMA_C3TR2_BREQ		(0x1u<<11)
#define	LPDMA_C3TR2_SWREQ		(0x1u<<9)
#define	LPDMA_C3TR2_REQSEL		(0x1Fu<<0)
#define	LPDMA_C3TR2_REQSEL_0	(0x1u<<0)

// C3BR1 Configuration

#define	LPDMA_C3BR1_BNDT		(0xFFFFu<<0)
#define	LPDMA_C3BR1_BNDT_0		(0x1u<<0)

// C3SAR Configuration

#define	LPDMA_C3SAR_SA			(0xFFFFFFFFu<<0)
#define	LPDMA_C3SAR_SA_0		(0x1u<<0)

// C3DAR Configuration

#define	LPDMA_C3DAR_DA			(0xFFFFFFFFu<<0)
#define	LPDMA_C3DAR_DA_0		(0x1u<<0)

// C3LLR Configuration

#define	LPDMA_C3LLR_UT1			(0x1u<<31)
#define	LPDMA_C3LLR_UT2			(0x1u<<30)
#define	LPDMA_C3LLR_UB1			(0x1u<<29)
#define	LPDMA_C3LLR_USA			(0x1u<<28)
#define	LPDMA_C3LLR_UDA			(0x1u<<27)
#define	LPDMA_C3LLR_ULL			(0x1u<<16)
#define	LPDMA_C3LLR_LA			(0x3FFFu<<2)
#define	LPDMA_C3LLR_LA_0		(0x1u<<2)
