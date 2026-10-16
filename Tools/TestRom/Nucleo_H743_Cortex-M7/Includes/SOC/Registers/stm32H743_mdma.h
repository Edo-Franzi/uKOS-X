/*
; stm32H743_mdma.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_mdma equates.
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

// MDMA address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	GISR0;
	volatile	uint32_t	RESERVED0[15];
	volatile	uint32_t	C0ISR;
	volatile	uint32_t	C0IFCR;
	volatile	uint32_t	C0ESR;
	volatile	uint32_t	C0CR;
	volatile	uint32_t	C0TCR;
	volatile	uint32_t	C0BNDTR;
	volatile	uint32_t	C0SAR;
	volatile	uint32_t	C0DAR;
	volatile	uint32_t	C0BRUR;
	volatile	uint32_t	C0LAR;
	volatile	uint32_t	C0TBR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	C0MAR;
	volatile	uint32_t	C0MDR;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	C1ISR;
	volatile	uint32_t	C1IFCR;
	volatile	uint32_t	C1ESR;
	volatile	uint32_t	C1CR;
	volatile	uint32_t	C1TCR;
	volatile	uint32_t	C1BNDTR;
	volatile	uint32_t	C1SAR;
	volatile	uint32_t	C1DAR;
	volatile	uint32_t	C1BRUR;
	volatile	uint32_t	C1LAR;
	volatile	uint32_t	C1TBR;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	C1MAR;
	volatile	uint32_t	C1MDR;
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	C2ISR;
	volatile	uint32_t	C2IFCR;
	volatile	uint32_t	C2ESR;
	volatile	uint32_t	C2CR;
	volatile	uint32_t	C2TCR;
	volatile	uint32_t	C2BNDTR;
	volatile	uint32_t	C2SAR;
	volatile	uint32_t	C2DAR;
	volatile	uint32_t	C2BRUR;
	volatile	uint32_t	C2LAR;
	volatile	uint32_t	C2TBR;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	C2MAR;
	volatile	uint32_t	C2MDR;
	volatile	uint32_t	RESERVED6[2];
	volatile	uint32_t	C3ISR;
	volatile	uint32_t	C3IFCR;
	volatile	uint32_t	C3ESR;
	volatile	uint32_t	C3CR;
	volatile	uint32_t	C3TCR;
	volatile	uint32_t	C3BNDTR;
	volatile	uint32_t	C3SAR;
	volatile	uint32_t	C3DAR;
	volatile	uint32_t	C3BRUR;
	volatile	uint32_t	C3LAR;
	volatile	uint32_t	C3TBR;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	C3MAR;
	volatile	uint32_t	C3MDR;
	volatile	uint32_t	RESERVED8[2];
	volatile	uint32_t	C4ISR;
	volatile	uint32_t	C4IFCR;
	volatile	uint32_t	C4ESR;
	volatile	uint32_t	C4CR;
	volatile	uint32_t	C4TCR;
	volatile	uint32_t	C4BNDTR;
	volatile	uint32_t	C4SAR;
	volatile	uint32_t	C4DAR;
	volatile	uint32_t	C4BRUR;
	volatile	uint32_t	C4LAR;
	volatile	uint32_t	C4TBR;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	C4MAR;
	volatile	uint32_t	C4MDR;
	volatile	uint32_t	RESERVED10[2];
	volatile	uint32_t	C5ISR;
	volatile	uint32_t	C5IFCR;
	volatile	uint32_t	C5ESR;
	volatile	uint32_t	C5CR;
	volatile	uint32_t	C5TCR;
	volatile	uint32_t	C5BNDTR;
	volatile	uint32_t	C5SAR;
	volatile	uint32_t	C5DAR;
	volatile	uint32_t	C5BRUR;
	volatile	uint32_t	C5LAR;
	volatile	uint32_t	C5TBR;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	C5MAR;
	volatile	uint32_t	C5MDR;
	volatile	uint32_t	RESERVED12[2];
	volatile	uint32_t	C6ISR;
	volatile	uint32_t	C6IFCR;
	volatile	uint32_t	C6ESR;
	volatile	uint32_t	C6CR;
	volatile	uint32_t	C6TCR;
	volatile	uint32_t	C6BNDTR;
	volatile	uint32_t	C6SAR;
	volatile	uint32_t	C6DAR;
	volatile	uint32_t	C6BRUR;
	volatile	uint32_t	C6LAR;
	volatile	uint32_t	C6TBR;
	volatile	uint32_t	RESERVED13;
	volatile	uint32_t	C6MAR;
	volatile	uint32_t	C6MDR;
	volatile	uint32_t	RESERVED14[2];
	volatile	uint32_t	C7ISR;
	volatile	uint32_t	C7IFCR;
	volatile	uint32_t	C7ESR;
	volatile	uint32_t	C7CR;
	volatile	uint32_t	C7TCR;
	volatile	uint32_t	C7BNDTR;
	volatile	uint32_t	C7SAR;
	volatile	uint32_t	C7DAR;
	volatile	uint32_t	C7BRUR;
	volatile	uint32_t	C7LAR;
	volatile	uint32_t	C7TBR;
	volatile	uint32_t	RESERVED15;
	volatile	uint32_t	C7MAR;
	volatile	uint32_t	C7MDR;
	volatile	uint32_t	RESERVED16[2];
	volatile	uint32_t	C8ISR;
	volatile	uint32_t	C8IFCR;
	volatile	uint32_t	C8ESR;
	volatile	uint32_t	C8CR;
	volatile	uint32_t	C8TCR;
	volatile	uint32_t	C8BNDTR;
	volatile	uint32_t	C8SAR;
	volatile	uint32_t	C8DAR;
	volatile	uint32_t	C8BRUR;
	volatile	uint32_t	C8LAR;
	volatile	uint32_t	C8TBR;
	volatile	uint32_t	RESERVED17;
	volatile	uint32_t	C8MAR;
	volatile	uint32_t	C8MDR;
	volatile	uint32_t	RESERVED18[2];
	volatile	uint32_t	C9ISR;
	volatile	uint32_t	C9IFCR;
	volatile	uint32_t	C9ESR;
	volatile	uint32_t	C9CR;
	volatile	uint32_t	C9TCR;
	volatile	uint32_t	C9BNDTR;
	volatile	uint32_t	C9SAR;
	volatile	uint32_t	C9DAR;
	volatile	uint32_t	C9BRUR;
	volatile	uint32_t	C9LAR;
	volatile	uint32_t	C9TBR;
	volatile	uint32_t	RESERVED19;
	volatile	uint32_t	C9MAR;
	volatile	uint32_t	C9MDR;
	volatile	uint32_t	RESERVED20[2];
	volatile	uint32_t	C10ISR;
	volatile	uint32_t	C10IFCR;
	volatile	uint32_t	C10ESR;
	volatile	uint32_t	C10CR;
	volatile	uint32_t	C10TCR;
	volatile	uint32_t	C10BNDTR;
	volatile	uint32_t	C10SAR;
	volatile	uint32_t	C10DAR;
	volatile	uint32_t	C10BRUR;
	volatile	uint32_t	C10LAR;
	volatile	uint32_t	C10TBR;
	volatile	uint32_t	RESERVED21;
	volatile	uint32_t	C10MAR;
	volatile	uint32_t	C10MDR;
	volatile	uint32_t	RESERVED22[2];
	volatile	uint32_t	C11ISR;
	volatile	uint32_t	C11IFCR;
	volatile	uint32_t	C11ESR;
	volatile	uint32_t	C11CR;
	volatile	uint32_t	C11TCR;
	volatile	uint32_t	C11BNDTR;
	volatile	uint32_t	C11SAR;
	volatile	uint32_t	C11DAR;
	volatile	uint32_t	C11BRUR;
	volatile	uint32_t	C11LAR;
	volatile	uint32_t	C11TBR;
	volatile	uint32_t	RESERVED23;
	volatile	uint32_t	C11MAR;
	volatile	uint32_t	C11MDR;
	volatile	uint32_t	RESERVED24[2];
	volatile	uint32_t	C12ISR;
	volatile	uint32_t	C12IFCR;
	volatile	uint32_t	C12ESR;
	volatile	uint32_t	C12CR;
	volatile	uint32_t	C12TCR;
	volatile	uint32_t	C12BNDTR;
	volatile	uint32_t	C12SAR;
	volatile	uint32_t	C12DAR;
	volatile	uint32_t	C12BRUR;
	volatile	uint32_t	C12LAR;
	volatile	uint32_t	C12TBR;
	volatile	uint32_t	RESERVED25;
	volatile	uint32_t	C12MAR;
	volatile	uint32_t	C12MDR;
	volatile	uint32_t	RESERVED26[2];
	volatile	uint32_t	C13ISR;
	volatile	uint32_t	C13IFCR;
	volatile	uint32_t	C13ESR;
	volatile	uint32_t	C13CR;
	volatile	uint32_t	C13TCR;
	volatile	uint32_t	C13BNDTR;
	volatile	uint32_t	C13SAR;
	volatile	uint32_t	C13DAR;
	volatile	uint32_t	C13BRUR;
	volatile	uint32_t	C13LAR;
	volatile	uint32_t	C13TBR;
	volatile	uint32_t	RESERVED27;
	volatile	uint32_t	C13MAR;
	volatile	uint32_t	C13MDR;
	volatile	uint32_t	RESERVED28[2];
	volatile	uint32_t	C14ISR;
	volatile	uint32_t	C14IFCR;
	volatile	uint32_t	C14ESR;
	volatile	uint32_t	C14CR;
	volatile	uint32_t	C14TCR;
	volatile	uint32_t	C14BNDTR;
	volatile	uint32_t	C14SAR;
	volatile	uint32_t	C14DAR;
	volatile	uint32_t	C14BRUR;
	volatile	uint32_t	C14LAR;
	volatile	uint32_t	C14TBR;
	volatile	uint32_t	RESERVED29;
	volatile	uint32_t	C14MAR;
	volatile	uint32_t	C14MDR;
	volatile	uint32_t	RESERVED30[2];
	volatile	uint32_t	C15ISR;
	volatile	uint32_t	C15IFCR;
	volatile	uint32_t	C15ESR;
	volatile	uint32_t	C15CR;
	volatile	uint32_t	C15TCR;
	volatile	uint32_t	C15BNDTR;
	volatile	uint32_t	C15SAR;
	volatile	uint32_t	C15DAR;
	volatile	uint32_t	C15BRUR;
	volatile	uint32_t	C15LAR;
	volatile	uint32_t	C15TBR;
	volatile	uint32_t	RESERVED31;
	volatile	uint32_t	C15MAR;
	volatile	uint32_t	C15MDR;
} MDMA_TypeDef;

#if (defined(__cplusplus))
#define	MDMA	reinterpret_cast<MDMA_TypeDef *>(0x52000000u)

#else
#define	MDMA	((MDMA_TypeDef *)0x52000000u)
#endif

// GISR0 Configuration

#define	MDMA_GISR0_GIF15		(0x1u<<15)
#define	MDMA_GISR0_GIF14		(0x1u<<14)
#define	MDMA_GISR0_GIF13		(0x1u<<13)
#define	MDMA_GISR0_GIF12		(0x1u<<12)
#define	MDMA_GISR0_GIF11		(0x1u<<11)
#define	MDMA_GISR0_GIF10		(0x1u<<10)
#define	MDMA_GISR0_GIF9			(0x1u<<9)
#define	MDMA_GISR0_GIF8			(0x1u<<8)
#define	MDMA_GISR0_GIF7			(0x1u<<7)
#define	MDMA_GISR0_GIF6			(0x1u<<6)
#define	MDMA_GISR0_GIF5			(0x1u<<5)
#define	MDMA_GISR0_GIF4			(0x1u<<4)
#define	MDMA_GISR0_GIF3			(0x1u<<3)
#define	MDMA_GISR0_GIF2			(0x1u<<2)
#define	MDMA_GISR0_GIF1			(0x1u<<1)
#define	MDMA_GISR0_GIF0			(0x1u<<0)

// C0ISR Configuration

#define	MDMA_C0ISR_CRQA0		(0x1u<<16)
#define	MDMA_C0ISR_TCIF0		(0x1u<<4)
#define	MDMA_C0ISR_BTIF0		(0x1u<<3)
#define	MDMA_C0ISR_BRTIF0		(0x1u<<2)
#define	MDMA_C0ISR_CTCIF0		(0x1u<<1)
#define	MDMA_C0ISR_TEIF0		(0x1u<<0)

// C0IFCR Configuration

#define	MDMA_C0IFCR_CLTCIF0		(0x1u<<4)
#define	MDMA_C0IFCR_CBTIF0		(0x1u<<3)
#define	MDMA_C0IFCR_CBRTIF0		(0x1u<<2)
#define	MDMA_C0IFCR_CCTCIF0		(0x1u<<1)
#define	MDMA_C0IFCR_CTEIF0		(0x1u<<0)

// C0ESR Configuration

#define	MDMA_C0ESR_BSE			(0x1u<<11)
#define	MDMA_C0ESR_ASE			(0x1u<<10)
#define	MDMA_C0ESR_TEMD			(0x1u<<9)
#define	MDMA_C0ESR_TELD			(0x1u<<8)
#define	MDMA_C0ESR_TED			(0x1u<<7)
#define	MDMA_C0ESR_TEA			(0x7Fu<<0)
#define	MDMA_C0ESR_TEA_0		(0x1u<<0)

// C0CR Configuration

#define	MDMA_C0CR_SWRQ			(0x1u<<16)
#define	MDMA_C0CR_WEX			(0x1u<<14)
#define	MDMA_C0CR_HEX			(0x1u<<13)
#define	MDMA_C0CR_BEX			(0x1u<<12)
#define	MDMA_C0CR_PL			(0x3u<<6)
#define	MDMA_C0CR_PL_0			(0x1u<<6)
#define	MDMA_C0CR_TCIE			(0x1u<<5)
#define	MDMA_C0CR_BTIE			(0x1u<<4)
#define	MDMA_C0CR_BRTIE			(0x1u<<3)
#define	MDMA_C0CR_CTCIE			(0x1u<<2)
#define	MDMA_C0CR_TEIE			(0x1u<<1)
#define	MDMA_C0CR_EN			(0x1u<<0)

// C0TCR Configuration

#define	MDMA_C0TCR_BWM			(0x1u<<31)
#define	MDMA_C0TCR_SWRM			(0x1u<<30)
#define	MDMA_C0TCR_TRGM			(0x3u<<28)
#define	MDMA_C0TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C0TCR_PAM			(0x3u<<26)
#define	MDMA_C0TCR_PAM_0		(0x1u<<26)
#define	MDMA_C0TCR_PKE			(0x1u<<25)
#define	MDMA_C0TCR_TLEN			(0x7Fu<<18)
#define	MDMA_C0TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C0TCR_DBURST		(0x7u<<15)
#define	MDMA_C0TCR_DBURST_0		(0x1u<<15)
#define	MDMA_C0TCR_SBURST		(0x7u<<12)
#define	MDMA_C0TCR_SBURST_0		(0x1u<<12)
#define	MDMA_C0TCR_DINCOS		(0x3u<<10)
#define	MDMA_C0TCR_DINCOS_0		(0x1u<<10)
#define	MDMA_C0TCR_SINCOS		(0x3u<<8)
#define	MDMA_C0TCR_SINCOS_0		(0x1u<<8)
#define	MDMA_C0TCR_DSIZE		(0x3u<<6)
#define	MDMA_C0TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C0TCR_SSIZE		(0x3u<<4)
#define	MDMA_C0TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C0TCR_DINC			(0x3u<<2)
#define	MDMA_C0TCR_DINC_0		(0x1u<<2)
#define	MDMA_C0TCR_SINC			(0x3u<<0)
#define	MDMA_C0TCR_SINC_0		(0x1u<<0)

// C0BNDTR Configuration

#define	MDMA_C0BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C0BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C0BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C0BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C0BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C0BNDTR_BNDT_0		(0x1u<<0)

// C0SAR Configuration

#define	MDMA_C0SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C0SAR_SAR_0		(0x1u<<0)

// C0DAR Configuration

#define	MDMA_C0DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C0DAR_DAR_0		(0x1u<<0)

// C0BRUR Configuration

#define	MDMA_C0BRUR_DUV			(0xFFFFu<<16)
#define	MDMA_C0BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C0BRUR_SUV			(0xFFFFu<<0)
#define	MDMA_C0BRUR_SUV_0		(0x1u<<0)

// C0LAR Configuration

#define	MDMA_C0LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C0LAR_LAR_0		(0x1u<<0)

// C0TBR Configuration

#define	MDMA_C0TBR_DBUS			(0x1u<<17)
#define	MDMA_C0TBR_SBUS			(0x1u<<16)
#define	MDMA_C0TBR_TSEL			(0x3Fu<<0)
#define	MDMA_C0TBR_TSEL_0		(0x1u<<0)

// C0MAR Configuration

#define	MDMA_C0MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C0MAR_MAR_0		(0x1u<<0)

// C0MDR Configuration

#define	MDMA_C0MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C0MDR_MDR_0		(0x1u<<0)

// C1ISR Configuration

#define	MDMA_C1ISR_CRQA1		(0x1u<<16)
#define	MDMA_C1ISR_TCIF1		(0x1u<<4)
#define	MDMA_C1ISR_BTIF1		(0x1u<<3)
#define	MDMA_C1ISR_BRTIF1		(0x1u<<2)
#define	MDMA_C1ISR_CTCIF1		(0x1u<<1)
#define	MDMA_C1ISR_TEIF1		(0x1u<<0)

// C1IFCR Configuration

#define	MDMA_C1IFCR_CLTCIF1		(0x1u<<4)
#define	MDMA_C1IFCR_CBTIF1		(0x1u<<3)
#define	MDMA_C1IFCR_CBRTIF1		(0x1u<<2)
#define	MDMA_C1IFCR_CCTCIF1		(0x1u<<1)
#define	MDMA_C1IFCR_CTEIF1		(0x1u<<0)

// C1ESR Configuration

#define	MDMA_C1ESR_BSE			(0x1u<<11)
#define	MDMA_C1ESR_ASE			(0x1u<<10)
#define	MDMA_C1ESR_TEMD			(0x1u<<9)
#define	MDMA_C1ESR_TELD			(0x1u<<8)
#define	MDMA_C1ESR_TED			(0x1u<<7)
#define	MDMA_C1ESR_TEA			(0x7Fu<<0)
#define	MDMA_C1ESR_TEA_0		(0x1u<<0)

// C1CR Configuration

#define	MDMA_C1CR_SWRQ			(0x1u<<16)
#define	MDMA_C1CR_WEX			(0x1u<<14)
#define	MDMA_C1CR_HEX			(0x1u<<13)
#define	MDMA_C1CR_BEX			(0x1u<<12)
#define	MDMA_C1CR_PL			(0x3u<<6)
#define	MDMA_C1CR_PL_0			(0x1u<<6)
#define	MDMA_C1CR_TCIE			(0x1u<<5)
#define	MDMA_C1CR_BTIE			(0x1u<<4)
#define	MDMA_C1CR_BRTIE			(0x1u<<3)
#define	MDMA_C1CR_CTCIE			(0x1u<<2)
#define	MDMA_C1CR_TEIE			(0x1u<<1)
#define	MDMA_C1CR_EN			(0x1u<<0)

// C1TCR Configuration

#define	MDMA_C1TCR_BWM			(0x1u<<31)
#define	MDMA_C1TCR_SWRM			(0x1u<<30)
#define	MDMA_C1TCR_TRGM			(0x3u<<28)
#define	MDMA_C1TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C1TCR_PAM			(0x3u<<26)
#define	MDMA_C1TCR_PAM_0		(0x1u<<26)
#define	MDMA_C1TCR_PKE			(0x1u<<25)
#define	MDMA_C1TCR_TLEN			(0x7Fu<<18)
#define	MDMA_C1TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C1TCR_DBURST		(0x7u<<15)
#define	MDMA_C1TCR_DBURST_0		(0x1u<<15)
#define	MDMA_C1TCR_SBURST		(0x7u<<12)
#define	MDMA_C1TCR_SBURST_0		(0x1u<<12)
#define	MDMA_C1TCR_DINCOS		(0x3u<<10)
#define	MDMA_C1TCR_DINCOS_0		(0x1u<<10)
#define	MDMA_C1TCR_SINCOS		(0x3u<<8)
#define	MDMA_C1TCR_SINCOS_0		(0x1u<<8)
#define	MDMA_C1TCR_DSIZE		(0x3u<<6)
#define	MDMA_C1TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C1TCR_SSIZE		(0x3u<<4)
#define	MDMA_C1TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C1TCR_DINC			(0x3u<<2)
#define	MDMA_C1TCR_DINC_0		(0x1u<<2)
#define	MDMA_C1TCR_SINC			(0x3u<<0)
#define	MDMA_C1TCR_SINC_0		(0x1u<<0)

// C1BNDTR Configuration

#define	MDMA_C1BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C1BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C1BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C1BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C1BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C1BNDTR_BNDT_0		(0x1u<<0)

// C1SAR Configuration

#define	MDMA_C1SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C1SAR_SAR_0		(0x1u<<0)

// C1DAR Configuration

#define	MDMA_C1DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C1DAR_DAR_0		(0x1u<<0)

// C1BRUR Configuration

#define	MDMA_C1BRUR_DUV			(0xFFFFu<<16)
#define	MDMA_C1BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C1BRUR_SUV			(0xFFFFu<<0)
#define	MDMA_C1BRUR_SUV_0		(0x1u<<0)

// C1LAR Configuration

#define	MDMA_C1LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C1LAR_LAR_0		(0x1u<<0)

// C1TBR Configuration

#define	MDMA_C1TBR_DBUS			(0x1u<<17)
#define	MDMA_C1TBR_SBUS			(0x1u<<16)
#define	MDMA_C1TBR_TSEL			(0x3Fu<<0)
#define	MDMA_C1TBR_TSEL_0		(0x1u<<0)

// C1MAR Configuration

#define	MDMA_C1MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C1MAR_MAR_0		(0x1u<<0)

// C1MDR Configuration

#define	MDMA_C1MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C1MDR_MDR_0		(0x1u<<0)

// C2ISR Configuration

#define	MDMA_C2ISR_CRQA2		(0x1u<<16)
#define	MDMA_C2ISR_TCIF2		(0x1u<<4)
#define	MDMA_C2ISR_BTIF2		(0x1u<<3)
#define	MDMA_C2ISR_BRTIF2		(0x1u<<2)
#define	MDMA_C2ISR_CTCIF2		(0x1u<<1)
#define	MDMA_C2ISR_TEIF2		(0x1u<<0)

// C2IFCR Configuration

#define	MDMA_C2IFCR_CLTCIF2		(0x1u<<4)
#define	MDMA_C2IFCR_CBTIF2		(0x1u<<3)
#define	MDMA_C2IFCR_CBRTIF2		(0x1u<<2)
#define	MDMA_C2IFCR_CCTCIF2		(0x1u<<1)
#define	MDMA_C2IFCR_CTEIF2		(0x1u<<0)

// C2ESR Configuration

#define	MDMA_C2ESR_BSE			(0x1u<<11)
#define	MDMA_C2ESR_ASE			(0x1u<<10)
#define	MDMA_C2ESR_TEMD			(0x1u<<9)
#define	MDMA_C2ESR_TELD			(0x1u<<8)
#define	MDMA_C2ESR_TED			(0x1u<<7)
#define	MDMA_C2ESR_TEA			(0x7Fu<<0)
#define	MDMA_C2ESR_TEA_0		(0x1u<<0)

// C2CR Configuration

#define	MDMA_C2CR_SWRQ			(0x1u<<16)
#define	MDMA_C2CR_WEX			(0x1u<<14)
#define	MDMA_C2CR_HEX			(0x1u<<13)
#define	MDMA_C2CR_BEX			(0x1u<<12)
#define	MDMA_C2CR_PL			(0x3u<<6)
#define	MDMA_C2CR_PL_0			(0x1u<<6)
#define	MDMA_C2CR_TCIE			(0x1u<<5)
#define	MDMA_C2CR_BTIE			(0x1u<<4)
#define	MDMA_C2CR_BRTIE			(0x1u<<3)
#define	MDMA_C2CR_CTCIE			(0x1u<<2)
#define	MDMA_C2CR_TEIE			(0x1u<<1)
#define	MDMA_C2CR_EN			(0x1u<<0)

// C2TCR Configuration

#define	MDMA_C2TCR_BWM			(0x1u<<31)
#define	MDMA_C2TCR_SWRM			(0x1u<<30)
#define	MDMA_C2TCR_TRGM			(0x3u<<28)
#define	MDMA_C2TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C2TCR_PAM			(0x3u<<26)
#define	MDMA_C2TCR_PAM_0		(0x1u<<26)
#define	MDMA_C2TCR_PKE			(0x1u<<25)
#define	MDMA_C2TCR_TLEN			(0x7Fu<<18)
#define	MDMA_C2TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C2TCR_DBURST		(0x7u<<15)
#define	MDMA_C2TCR_DBURST_0		(0x1u<<15)
#define	MDMA_C2TCR_SBURST		(0x7u<<12)
#define	MDMA_C2TCR_SBURST_0		(0x1u<<12)
#define	MDMA_C2TCR_DINCOS		(0x3u<<10)
#define	MDMA_C2TCR_DINCOS_0		(0x1u<<10)
#define	MDMA_C2TCR_SINCOS		(0x3u<<8)
#define	MDMA_C2TCR_SINCOS_0		(0x1u<<8)
#define	MDMA_C2TCR_DSIZE		(0x3u<<6)
#define	MDMA_C2TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C2TCR_SSIZE		(0x3u<<4)
#define	MDMA_C2TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C2TCR_DINC			(0x3u<<2)
#define	MDMA_C2TCR_DINC_0		(0x1u<<2)
#define	MDMA_C2TCR_SINC			(0x3u<<0)
#define	MDMA_C2TCR_SINC_0		(0x1u<<0)

// C2BNDTR Configuration

#define	MDMA_C2BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C2BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C2BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C2BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C2BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C2BNDTR_BNDT_0		(0x1u<<0)

// C2SAR Configuration

#define	MDMA_C2SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C2SAR_SAR_0		(0x1u<<0)

// C2DAR Configuration

#define	MDMA_C2DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C2DAR_DAR_0		(0x1u<<0)

// C2BRUR Configuration

#define	MDMA_C2BRUR_DUV			(0xFFFFu<<16)
#define	MDMA_C2BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C2BRUR_SUV			(0xFFFFu<<0)
#define	MDMA_C2BRUR_SUV_0		(0x1u<<0)

// C2LAR Configuration

#define	MDMA_C2LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C2LAR_LAR_0		(0x1u<<0)

// C2TBR Configuration

#define	MDMA_C2TBR_DBUS			(0x1u<<17)
#define	MDMA_C2TBR_SBUS			(0x1u<<16)
#define	MDMA_C2TBR_TSEL			(0x3Fu<<0)
#define	MDMA_C2TBR_TSEL_0		(0x1u<<0)

// C2MAR Configuration

#define	MDMA_C2MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C2MAR_MAR_0		(0x1u<<0)

// C2MDR Configuration

#define	MDMA_C2MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C2MDR_MDR_0		(0x1u<<0)

// C3ISR Configuration

#define	MDMA_C3ISR_CRQA3		(0x1u<<16)
#define	MDMA_C3ISR_TCIF3		(0x1u<<4)
#define	MDMA_C3ISR_BTIF3		(0x1u<<3)
#define	MDMA_C3ISR_BRTIF3		(0x1u<<2)
#define	MDMA_C3ISR_CTCIF3		(0x1u<<1)
#define	MDMA_C3ISR_TEIF3		(0x1u<<0)

// C3IFCR Configuration

#define	MDMA_C3IFCR_CLTCIF3		(0x1u<<4)
#define	MDMA_C3IFCR_CBTIF3		(0x1u<<3)
#define	MDMA_C3IFCR_CBRTIF3		(0x1u<<2)
#define	MDMA_C3IFCR_CCTCIF3		(0x1u<<1)
#define	MDMA_C3IFCR_CTEIF3		(0x1u<<0)

// C3ESR Configuration

#define	MDMA_C3ESR_BSE			(0x1u<<11)
#define	MDMA_C3ESR_ASE			(0x1u<<10)
#define	MDMA_C3ESR_TEMD			(0x1u<<9)
#define	MDMA_C3ESR_TELD			(0x1u<<8)
#define	MDMA_C3ESR_TED			(0x1u<<7)
#define	MDMA_C3ESR_TEA			(0x7Fu<<0)
#define	MDMA_C3ESR_TEA_0		(0x1u<<0)

// C3CR Configuration

#define	MDMA_C3CR_SWRQ			(0x1u<<16)
#define	MDMA_C3CR_WEX			(0x1u<<14)
#define	MDMA_C3CR_HEX			(0x1u<<13)
#define	MDMA_C3CR_BEX			(0x1u<<12)
#define	MDMA_C3CR_PL			(0x3u<<6)
#define	MDMA_C3CR_PL_0			(0x1u<<6)
#define	MDMA_C3CR_TCIE			(0x1u<<5)
#define	MDMA_C3CR_BTIE			(0x1u<<4)
#define	MDMA_C3CR_BRTIE			(0x1u<<3)
#define	MDMA_C3CR_CTCIE			(0x1u<<2)
#define	MDMA_C3CR_TEIE			(0x1u<<1)
#define	MDMA_C3CR_EN			(0x1u<<0)

// C3TCR Configuration

#define	MDMA_C3TCR_BWM			(0x1u<<31)
#define	MDMA_C3TCR_SWRM			(0x1u<<30)
#define	MDMA_C3TCR_TRGM			(0x3u<<28)
#define	MDMA_C3TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C3TCR_PAM			(0x3u<<26)
#define	MDMA_C3TCR_PAM_0		(0x1u<<26)
#define	MDMA_C3TCR_PKE			(0x1u<<25)
#define	MDMA_C3TCR_TLEN			(0x7Fu<<18)
#define	MDMA_C3TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C3TCR_DBURST		(0x7u<<15)
#define	MDMA_C3TCR_DBURST_0		(0x1u<<15)
#define	MDMA_C3TCR_SBURST		(0x7u<<12)
#define	MDMA_C3TCR_SBURST_0		(0x1u<<12)
#define	MDMA_C3TCR_DINCOS		(0x3u<<10)
#define	MDMA_C3TCR_DINCOS_0		(0x1u<<10)
#define	MDMA_C3TCR_SINCOS		(0x3u<<8)
#define	MDMA_C3TCR_SINCOS_0		(0x1u<<8)
#define	MDMA_C3TCR_DSIZE		(0x3u<<6)
#define	MDMA_C3TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C3TCR_SSIZE		(0x3u<<4)
#define	MDMA_C3TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C3TCR_DINC			(0x3u<<2)
#define	MDMA_C3TCR_DINC_0		(0x1u<<2)
#define	MDMA_C3TCR_SINC			(0x3u<<0)
#define	MDMA_C3TCR_SINC_0		(0x1u<<0)

// C3BNDTR Configuration

#define	MDMA_C3BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C3BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C3BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C3BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C3BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C3BNDTR_BNDT_0		(0x1u<<0)

// C3SAR Configuration

#define	MDMA_C3SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C3SAR_SAR_0		(0x1u<<0)

// C3DAR Configuration

#define	MDMA_C3DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C3DAR_DAR_0		(0x1u<<0)

// C3BRUR Configuration

#define	MDMA_C3BRUR_DUV			(0xFFFFu<<16)
#define	MDMA_C3BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C3BRUR_SUV			(0xFFFFu<<0)
#define	MDMA_C3BRUR_SUV_0		(0x1u<<0)

// C3LAR Configuration

#define	MDMA_C3LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C3LAR_LAR_0		(0x1u<<0)

// C3TBR Configuration

#define	MDMA_C3TBR_DBUS			(0x1u<<17)
#define	MDMA_C3TBR_SBUS			(0x1u<<16)
#define	MDMA_C3TBR_TSEL			(0x3Fu<<0)
#define	MDMA_C3TBR_TSEL_0		(0x1u<<0)

// C3MAR Configuration

#define	MDMA_C3MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C3MAR_MAR_0		(0x1u<<0)

// C3MDR Configuration

#define	MDMA_C3MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C3MDR_MDR_0		(0x1u<<0)

// C4ISR Configuration

#define	MDMA_C4ISR_CRQA4		(0x1u<<16)
#define	MDMA_C4ISR_TCIF4		(0x1u<<4)
#define	MDMA_C4ISR_BTIF4		(0x1u<<3)
#define	MDMA_C4ISR_BRTIF4		(0x1u<<2)
#define	MDMA_C4ISR_CTCIF4		(0x1u<<1)
#define	MDMA_C4ISR_TEIF4		(0x1u<<0)

// C4IFCR Configuration

#define	MDMA_C4IFCR_CLTCIF4		(0x1u<<4)
#define	MDMA_C4IFCR_CBTIF4		(0x1u<<3)
#define	MDMA_C4IFCR_CBRTIF4		(0x1u<<2)
#define	MDMA_C4IFCR_CCTCIF4		(0x1u<<1)
#define	MDMA_C4IFCR_CTEIF4		(0x1u<<0)

// C4ESR Configuration

#define	MDMA_C4ESR_BSE			(0x1u<<11)
#define	MDMA_C4ESR_ASE			(0x1u<<10)
#define	MDMA_C4ESR_TEMD			(0x1u<<9)
#define	MDMA_C4ESR_TELD			(0x1u<<8)
#define	MDMA_C4ESR_TED			(0x1u<<7)
#define	MDMA_C4ESR_TEA			(0x7Fu<<0)
#define	MDMA_C4ESR_TEA_0		(0x1u<<0)

// C4CR Configuration

#define	MDMA_C4CR_SWRQ			(0x1u<<16)
#define	MDMA_C4CR_WEX			(0x1u<<14)
#define	MDMA_C4CR_HEX			(0x1u<<13)
#define	MDMA_C4CR_BEX			(0x1u<<12)
#define	MDMA_C4CR_PL			(0x3u<<6)
#define	MDMA_C4CR_PL_0			(0x1u<<6)
#define	MDMA_C4CR_TCIE			(0x1u<<5)
#define	MDMA_C4CR_BTIE			(0x1u<<4)
#define	MDMA_C4CR_BRTIE			(0x1u<<3)
#define	MDMA_C4CR_CTCIE			(0x1u<<2)
#define	MDMA_C4CR_TEIE			(0x1u<<1)
#define	MDMA_C4CR_EN			(0x1u<<0)

// C4TCR Configuration

#define	MDMA_C4TCR_BWM			(0x1u<<31)
#define	MDMA_C4TCR_SWRM			(0x1u<<30)
#define	MDMA_C4TCR_TRGM			(0x3u<<28)
#define	MDMA_C4TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C4TCR_PAM			(0x3u<<26)
#define	MDMA_C4TCR_PAM_0		(0x1u<<26)
#define	MDMA_C4TCR_PKE			(0x1u<<25)
#define	MDMA_C4TCR_TLEN			(0x7Fu<<18)
#define	MDMA_C4TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C4TCR_DBURST		(0x7u<<15)
#define	MDMA_C4TCR_DBURST_0		(0x1u<<15)
#define	MDMA_C4TCR_SBURST		(0x7u<<12)
#define	MDMA_C4TCR_SBURST_0		(0x1u<<12)
#define	MDMA_C4TCR_DINCOS		(0x3u<<10)
#define	MDMA_C4TCR_DINCOS_0		(0x1u<<10)
#define	MDMA_C4TCR_SINCOS		(0x3u<<8)
#define	MDMA_C4TCR_SINCOS_0		(0x1u<<8)
#define	MDMA_C4TCR_DSIZE		(0x3u<<6)
#define	MDMA_C4TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C4TCR_SSIZE		(0x3u<<4)
#define	MDMA_C4TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C4TCR_DINC			(0x3u<<2)
#define	MDMA_C4TCR_DINC_0		(0x1u<<2)
#define	MDMA_C4TCR_SINC			(0x3u<<0)
#define	MDMA_C4TCR_SINC_0		(0x1u<<0)

// C4BNDTR Configuration

#define	MDMA_C4BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C4BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C4BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C4BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C4BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C4BNDTR_BNDT_0		(0x1u<<0)

// C4SAR Configuration

#define	MDMA_C4SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C4SAR_SAR_0		(0x1u<<0)

// C4DAR Configuration

#define	MDMA_C4DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C4DAR_DAR_0		(0x1u<<0)

// C4BRUR Configuration

#define	MDMA_C4BRUR_DUV			(0xFFFFu<<16)
#define	MDMA_C4BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C4BRUR_SUV			(0xFFFFu<<0)
#define	MDMA_C4BRUR_SUV_0		(0x1u<<0)

// C4LAR Configuration

#define	MDMA_C4LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C4LAR_LAR_0		(0x1u<<0)

// C4TBR Configuration

#define	MDMA_C4TBR_DBUS			(0x1u<<17)
#define	MDMA_C4TBR_SBUS			(0x1u<<16)
#define	MDMA_C4TBR_TSEL			(0x3Fu<<0)
#define	MDMA_C4TBR_TSEL_0		(0x1u<<0)

// C4MAR Configuration

#define	MDMA_C4MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C4MAR_MAR_0		(0x1u<<0)

// C4MDR Configuration

#define	MDMA_C4MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C4MDR_MDR_0		(0x1u<<0)

// C5ISR Configuration

#define	MDMA_C5ISR_CRQA5		(0x1u<<16)
#define	MDMA_C5ISR_TCIF5		(0x1u<<4)
#define	MDMA_C5ISR_BTIF5		(0x1u<<3)
#define	MDMA_C5ISR_BRTIF5		(0x1u<<2)
#define	MDMA_C5ISR_CTCIF5		(0x1u<<1)
#define	MDMA_C5ISR_TEIF5		(0x1u<<0)

// C5IFCR Configuration

#define	MDMA_C5IFCR_CLTCIF5		(0x1u<<4)
#define	MDMA_C5IFCR_CBTIF5		(0x1u<<3)
#define	MDMA_C5IFCR_CBRTIF5		(0x1u<<2)
#define	MDMA_C5IFCR_CCTCIF5		(0x1u<<1)
#define	MDMA_C5IFCR_CTEIF5		(0x1u<<0)

// C5ESR Configuration

#define	MDMA_C5ESR_BSE			(0x1u<<11)
#define	MDMA_C5ESR_ASE			(0x1u<<10)
#define	MDMA_C5ESR_TEMD			(0x1u<<9)
#define	MDMA_C5ESR_TELD			(0x1u<<8)
#define	MDMA_C5ESR_TED			(0x1u<<7)
#define	MDMA_C5ESR_TEA			(0x7Fu<<0)
#define	MDMA_C5ESR_TEA_0		(0x1u<<0)

// C5CR Configuration

#define	MDMA_C5CR_SWRQ			(0x1u<<16)
#define	MDMA_C5CR_WEX			(0x1u<<14)
#define	MDMA_C5CR_HEX			(0x1u<<13)
#define	MDMA_C5CR_BEX			(0x1u<<12)
#define	MDMA_C5CR_PL			(0x3u<<6)
#define	MDMA_C5CR_PL_0			(0x1u<<6)
#define	MDMA_C5CR_TCIE			(0x1u<<5)
#define	MDMA_C5CR_BTIE			(0x1u<<4)
#define	MDMA_C5CR_BRTIE			(0x1u<<3)
#define	MDMA_C5CR_CTCIE			(0x1u<<2)
#define	MDMA_C5CR_TEIE			(0x1u<<1)
#define	MDMA_C5CR_EN			(0x1u<<0)

// C5TCR Configuration

#define	MDMA_C5TCR_BWM			(0x1u<<31)
#define	MDMA_C5TCR_SWRM			(0x1u<<30)
#define	MDMA_C5TCR_TRGM			(0x3u<<28)
#define	MDMA_C5TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C5TCR_PAM			(0x3u<<26)
#define	MDMA_C5TCR_PAM_0		(0x1u<<26)
#define	MDMA_C5TCR_PKE			(0x1u<<25)
#define	MDMA_C5TCR_TLEN			(0x7Fu<<18)
#define	MDMA_C5TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C5TCR_DBURST		(0x7u<<15)
#define	MDMA_C5TCR_DBURST_0		(0x1u<<15)
#define	MDMA_C5TCR_SBURST		(0x7u<<12)
#define	MDMA_C5TCR_SBURST_0		(0x1u<<12)
#define	MDMA_C5TCR_DINCOS		(0x3u<<10)
#define	MDMA_C5TCR_DINCOS_0		(0x1u<<10)
#define	MDMA_C5TCR_SINCOS		(0x3u<<8)
#define	MDMA_C5TCR_SINCOS_0		(0x1u<<8)
#define	MDMA_C5TCR_DSIZE		(0x3u<<6)
#define	MDMA_C5TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C5TCR_SSIZE		(0x3u<<4)
#define	MDMA_C5TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C5TCR_DINC			(0x3u<<2)
#define	MDMA_C5TCR_DINC_0		(0x1u<<2)
#define	MDMA_C5TCR_SINC			(0x3u<<0)
#define	MDMA_C5TCR_SINC_0		(0x1u<<0)

// C5BNDTR Configuration

#define	MDMA_C5BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C5BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C5BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C5BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C5BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C5BNDTR_BNDT_0		(0x1u<<0)

// C5SAR Configuration

#define	MDMA_C5SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C5SAR_SAR_0		(0x1u<<0)

// C5DAR Configuration

#define	MDMA_C5DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C5DAR_DAR_0		(0x1u<<0)

// C5BRUR Configuration

#define	MDMA_C5BRUR_DUV			(0xFFFFu<<16)
#define	MDMA_C5BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C5BRUR_SUV			(0xFFFFu<<0)
#define	MDMA_C5BRUR_SUV_0		(0x1u<<0)

// C5LAR Configuration

#define	MDMA_C5LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C5LAR_LAR_0		(0x1u<<0)

// C5TBR Configuration

#define	MDMA_C5TBR_DBUS			(0x1u<<17)
#define	MDMA_C5TBR_SBUS			(0x1u<<16)
#define	MDMA_C5TBR_TSEL			(0x3Fu<<0)
#define	MDMA_C5TBR_TSEL_0		(0x1u<<0)

// C5MAR Configuration

#define	MDMA_C5MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C5MAR_MAR_0		(0x1u<<0)

// C5MDR Configuration

#define	MDMA_C5MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C5MDR_MDR_0		(0x1u<<0)

// C6ISR Configuration

#define	MDMA_C6ISR_CRQA6		(0x1u<<16)
#define	MDMA_C6ISR_TCIF6		(0x1u<<4)
#define	MDMA_C6ISR_BTIF6		(0x1u<<3)
#define	MDMA_C6ISR_BRTIF6		(0x1u<<2)
#define	MDMA_C6ISR_CTCIF6		(0x1u<<1)
#define	MDMA_C6ISR_TEIF6		(0x1u<<0)

// C6IFCR Configuration

#define	MDMA_C6IFCR_CLTCIF6		(0x1u<<4)
#define	MDMA_C6IFCR_CBTIF6		(0x1u<<3)
#define	MDMA_C6IFCR_CBRTIF6		(0x1u<<2)
#define	MDMA_C6IFCR_CCTCIF6		(0x1u<<1)
#define	MDMA_C6IFCR_CTEIF6		(0x1u<<0)

// C6ESR Configuration

#define	MDMA_C6ESR_BSE			(0x1u<<11)
#define	MDMA_C6ESR_ASE			(0x1u<<10)
#define	MDMA_C6ESR_TEMD			(0x1u<<9)
#define	MDMA_C6ESR_TELD			(0x1u<<8)
#define	MDMA_C6ESR_TED			(0x1u<<7)
#define	MDMA_C6ESR_TEA			(0x7Fu<<0)
#define	MDMA_C6ESR_TEA_0		(0x1u<<0)

// C6CR Configuration

#define	MDMA_C6CR_SWRQ			(0x1u<<16)
#define	MDMA_C6CR_WEX			(0x1u<<14)
#define	MDMA_C6CR_HEX			(0x1u<<13)
#define	MDMA_C6CR_BEX			(0x1u<<12)
#define	MDMA_C6CR_PL			(0x3u<<6)
#define	MDMA_C6CR_PL_0			(0x1u<<6)
#define	MDMA_C6CR_TCIE			(0x1u<<5)
#define	MDMA_C6CR_BTIE			(0x1u<<4)
#define	MDMA_C6CR_BRTIE			(0x1u<<3)
#define	MDMA_C6CR_CTCIE			(0x1u<<2)
#define	MDMA_C6CR_TEIE			(0x1u<<1)
#define	MDMA_C6CR_EN			(0x1u<<0)

// C6TCR Configuration

#define	MDMA_C6TCR_BWM			(0x1u<<31)
#define	MDMA_C6TCR_SWRM			(0x1u<<30)
#define	MDMA_C6TCR_TRGM			(0x3u<<28)
#define	MDMA_C6TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C6TCR_PAM			(0x3u<<26)
#define	MDMA_C6TCR_PAM_0		(0x1u<<26)
#define	MDMA_C6TCR_PKE			(0x1u<<25)
#define	MDMA_C6TCR_TLEN			(0x7Fu<<18)
#define	MDMA_C6TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C6TCR_DBURST		(0x7u<<15)
#define	MDMA_C6TCR_DBURST_0		(0x1u<<15)
#define	MDMA_C6TCR_SBURST		(0x7u<<12)
#define	MDMA_C6TCR_SBURST_0		(0x1u<<12)
#define	MDMA_C6TCR_DINCOS		(0x3u<<10)
#define	MDMA_C6TCR_DINCOS_0		(0x1u<<10)
#define	MDMA_C6TCR_SINCOS		(0x3u<<8)
#define	MDMA_C6TCR_SINCOS_0		(0x1u<<8)
#define	MDMA_C6TCR_DSIZE		(0x3u<<6)
#define	MDMA_C6TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C6TCR_SSIZE		(0x3u<<4)
#define	MDMA_C6TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C6TCR_DINC			(0x3u<<2)
#define	MDMA_C6TCR_DINC_0		(0x1u<<2)
#define	MDMA_C6TCR_SINC			(0x3u<<0)
#define	MDMA_C6TCR_SINC_0		(0x1u<<0)

// C6BNDTR Configuration

#define	MDMA_C6BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C6BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C6BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C6BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C6BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C6BNDTR_BNDT_0		(0x1u<<0)

// C6SAR Configuration

#define	MDMA_C6SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C6SAR_SAR_0		(0x1u<<0)

// C6DAR Configuration

#define	MDMA_C6DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C6DAR_DAR_0		(0x1u<<0)

// C6BRUR Configuration

#define	MDMA_C6BRUR_DUV			(0xFFFFu<<16)
#define	MDMA_C6BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C6BRUR_SUV			(0xFFFFu<<0)
#define	MDMA_C6BRUR_SUV_0		(0x1u<<0)

// C6LAR Configuration

#define	MDMA_C6LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C6LAR_LAR_0		(0x1u<<0)

// C6TBR Configuration

#define	MDMA_C6TBR_DBUS			(0x1u<<17)
#define	MDMA_C6TBR_SBUS			(0x1u<<16)
#define	MDMA_C6TBR_TSEL			(0x3Fu<<0)
#define	MDMA_C6TBR_TSEL_0		(0x1u<<0)

// C6MAR Configuration

#define	MDMA_C6MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C6MAR_MAR_0		(0x1u<<0)

// C6MDR Configuration

#define	MDMA_C6MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C6MDR_MDR_0		(0x1u<<0)

// C7ISR Configuration

#define	MDMA_C7ISR_CRQA7		(0x1u<<16)
#define	MDMA_C7ISR_TCIF7		(0x1u<<4)
#define	MDMA_C7ISR_BTIF7		(0x1u<<3)
#define	MDMA_C7ISR_BRTIF7		(0x1u<<2)
#define	MDMA_C7ISR_CTCIF7		(0x1u<<1)
#define	MDMA_C7ISR_TEIF7		(0x1u<<0)

// C7IFCR Configuration

#define	MDMA_C7IFCR_CLTCIF7		(0x1u<<4)
#define	MDMA_C7IFCR_CBTIF7		(0x1u<<3)
#define	MDMA_C7IFCR_CBRTIF7		(0x1u<<2)
#define	MDMA_C7IFCR_CCTCIF7		(0x1u<<1)
#define	MDMA_C7IFCR_CTEIF7		(0x1u<<0)

// C7ESR Configuration

#define	MDMA_C7ESR_BSE			(0x1u<<11)
#define	MDMA_C7ESR_ASE			(0x1u<<10)
#define	MDMA_C7ESR_TEMD			(0x1u<<9)
#define	MDMA_C7ESR_TELD			(0x1u<<8)
#define	MDMA_C7ESR_TED			(0x1u<<7)
#define	MDMA_C7ESR_TEA			(0x7Fu<<0)
#define	MDMA_C7ESR_TEA_0		(0x1u<<0)

// C7CR Configuration

#define	MDMA_C7CR_SWRQ			(0x1u<<16)
#define	MDMA_C7CR_WEX			(0x1u<<14)
#define	MDMA_C7CR_HEX			(0x1u<<13)
#define	MDMA_C7CR_BEX			(0x1u<<12)
#define	MDMA_C7CR_PL			(0x3u<<6)
#define	MDMA_C7CR_PL_0			(0x1u<<6)
#define	MDMA_C7CR_TCIE			(0x1u<<5)
#define	MDMA_C7CR_BTIE			(0x1u<<4)
#define	MDMA_C7CR_BRTIE			(0x1u<<3)
#define	MDMA_C7CR_CTCIE			(0x1u<<2)
#define	MDMA_C7CR_TEIE			(0x1u<<1)
#define	MDMA_C7CR_EN			(0x1u<<0)

// C7TCR Configuration

#define	MDMA_C7TCR_BWM			(0x1u<<31)
#define	MDMA_C7TCR_SWRM			(0x1u<<30)
#define	MDMA_C7TCR_TRGM			(0x3u<<28)
#define	MDMA_C7TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C7TCR_PAM			(0x3u<<26)
#define	MDMA_C7TCR_PAM_0		(0x1u<<26)
#define	MDMA_C7TCR_PKE			(0x1u<<25)
#define	MDMA_C7TCR_TLEN			(0x7Fu<<18)
#define	MDMA_C7TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C7TCR_DBURST		(0x7u<<15)
#define	MDMA_C7TCR_DBURST_0		(0x1u<<15)
#define	MDMA_C7TCR_SBURST		(0x7u<<12)
#define	MDMA_C7TCR_SBURST_0		(0x1u<<12)
#define	MDMA_C7TCR_DINCOS		(0x3u<<10)
#define	MDMA_C7TCR_DINCOS_0		(0x1u<<10)
#define	MDMA_C7TCR_SINCOS		(0x3u<<8)
#define	MDMA_C7TCR_SINCOS_0		(0x1u<<8)
#define	MDMA_C7TCR_DSIZE		(0x3u<<6)
#define	MDMA_C7TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C7TCR_SSIZE		(0x3u<<4)
#define	MDMA_C7TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C7TCR_DINC			(0x3u<<2)
#define	MDMA_C7TCR_DINC_0		(0x1u<<2)
#define	MDMA_C7TCR_SINC			(0x3u<<0)
#define	MDMA_C7TCR_SINC_0		(0x1u<<0)

// C7BNDTR Configuration

#define	MDMA_C7BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C7BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C7BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C7BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C7BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C7BNDTR_BNDT_0		(0x1u<<0)

// C7SAR Configuration

#define	MDMA_C7SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C7SAR_SAR_0		(0x1u<<0)

// C7DAR Configuration

#define	MDMA_C7DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C7DAR_DAR_0		(0x1u<<0)

// C7BRUR Configuration

#define	MDMA_C7BRUR_DUV			(0xFFFFu<<16)
#define	MDMA_C7BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C7BRUR_SUV			(0xFFFFu<<0)
#define	MDMA_C7BRUR_SUV_0		(0x1u<<0)

// C7LAR Configuration

#define	MDMA_C7LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C7LAR_LAR_0		(0x1u<<0)

// C7TBR Configuration

#define	MDMA_C7TBR_DBUS			(0x1u<<17)
#define	MDMA_C7TBR_SBUS			(0x1u<<16)
#define	MDMA_C7TBR_TSEL			(0x3Fu<<0)
#define	MDMA_C7TBR_TSEL_0		(0x1u<<0)

// C7MAR Configuration

#define	MDMA_C7MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C7MAR_MAR_0		(0x1u<<0)

// C7MDR Configuration

#define	MDMA_C7MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C7MDR_MDR_0		(0x1u<<0)

// C8ISR Configuration

#define	MDMA_C8ISR_CRQA8		(0x1u<<16)
#define	MDMA_C8ISR_TCIF8		(0x1u<<4)
#define	MDMA_C8ISR_BTIF8		(0x1u<<3)
#define	MDMA_C8ISR_BRTIF8		(0x1u<<2)
#define	MDMA_C8ISR_CTCIF8		(0x1u<<1)
#define	MDMA_C8ISR_TEIF8		(0x1u<<0)

// C8IFCR Configuration

#define	MDMA_C8IFCR_CLTCIF8		(0x1u<<4)
#define	MDMA_C8IFCR_CBTIF8		(0x1u<<3)
#define	MDMA_C8IFCR_CBRTIF8		(0x1u<<2)
#define	MDMA_C8IFCR_CCTCIF8		(0x1u<<1)
#define	MDMA_C8IFCR_CTEIF8		(0x1u<<0)

// C8ESR Configuration

#define	MDMA_C8ESR_BSE			(0x1u<<11)
#define	MDMA_C8ESR_ASE			(0x1u<<10)
#define	MDMA_C8ESR_TEMD			(0x1u<<9)
#define	MDMA_C8ESR_TELD			(0x1u<<8)
#define	MDMA_C8ESR_TED			(0x1u<<7)
#define	MDMA_C8ESR_TEA			(0x7Fu<<0)
#define	MDMA_C8ESR_TEA_0		(0x1u<<0)

// C8CR Configuration

#define	MDMA_C8CR_SWRQ			(0x1u<<16)
#define	MDMA_C8CR_WEX			(0x1u<<14)
#define	MDMA_C8CR_HEX			(0x1u<<13)
#define	MDMA_C8CR_BEX			(0x1u<<12)
#define	MDMA_C8CR_PL			(0x3u<<6)
#define	MDMA_C8CR_PL_0			(0x1u<<6)
#define	MDMA_C8CR_TCIE			(0x1u<<5)
#define	MDMA_C8CR_BTIE			(0x1u<<4)
#define	MDMA_C8CR_BRTIE			(0x1u<<3)
#define	MDMA_C8CR_CTCIE			(0x1u<<2)
#define	MDMA_C8CR_TEIE			(0x1u<<1)
#define	MDMA_C8CR_EN			(0x1u<<0)

// C8TCR Configuration

#define	MDMA_C8TCR_BWM			(0x1u<<31)
#define	MDMA_C8TCR_SWRM			(0x1u<<30)
#define	MDMA_C8TCR_TRGM			(0x3u<<28)
#define	MDMA_C8TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C8TCR_PAM			(0x3u<<26)
#define	MDMA_C8TCR_PAM_0		(0x1u<<26)
#define	MDMA_C8TCR_PKE			(0x1u<<25)
#define	MDMA_C8TCR_TLEN			(0x7Fu<<18)
#define	MDMA_C8TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C8TCR_DBURST		(0x7u<<15)
#define	MDMA_C8TCR_DBURST_0		(0x1u<<15)
#define	MDMA_C8TCR_SBURST		(0x7u<<12)
#define	MDMA_C8TCR_SBURST_0		(0x1u<<12)
#define	MDMA_C8TCR_DINCOS		(0x3u<<10)
#define	MDMA_C8TCR_DINCOS_0		(0x1u<<10)
#define	MDMA_C8TCR_SINCOS		(0x3u<<8)
#define	MDMA_C8TCR_SINCOS_0		(0x1u<<8)
#define	MDMA_C8TCR_DSIZE		(0x3u<<6)
#define	MDMA_C8TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C8TCR_SSIZE		(0x3u<<4)
#define	MDMA_C8TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C8TCR_DINC			(0x3u<<2)
#define	MDMA_C8TCR_DINC_0		(0x1u<<2)
#define	MDMA_C8TCR_SINC			(0x3u<<0)
#define	MDMA_C8TCR_SINC_0		(0x1u<<0)

// C8BNDTR Configuration

#define	MDMA_C8BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C8BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C8BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C8BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C8BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C8BNDTR_BNDT_0		(0x1u<<0)

// C8SAR Configuration

#define	MDMA_C8SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C8SAR_SAR_0		(0x1u<<0)

// C8DAR Configuration

#define	MDMA_C8DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C8DAR_DAR_0		(0x1u<<0)

// C8BRUR Configuration

#define	MDMA_C8BRUR_DUV			(0xFFFFu<<16)
#define	MDMA_C8BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C8BRUR_SUV			(0xFFFFu<<0)
#define	MDMA_C8BRUR_SUV_0		(0x1u<<0)

// C8LAR Configuration

#define	MDMA_C8LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C8LAR_LAR_0		(0x1u<<0)

// C8TBR Configuration

#define	MDMA_C8TBR_DBUS			(0x1u<<17)
#define	MDMA_C8TBR_SBUS			(0x1u<<16)
#define	MDMA_C8TBR_TSEL			(0x3Fu<<0)
#define	MDMA_C8TBR_TSEL_0		(0x1u<<0)

// C8MAR Configuration

#define	MDMA_C8MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C8MAR_MAR_0		(0x1u<<0)

// C8MDR Configuration

#define	MDMA_C8MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C8MDR_MDR_0		(0x1u<<0)

// C9ISR Configuration

#define	MDMA_C9ISR_CRQA9		(0x1u<<16)
#define	MDMA_C9ISR_TCIF9		(0x1u<<4)
#define	MDMA_C9ISR_BTIF9		(0x1u<<3)
#define	MDMA_C9ISR_BRTIF9		(0x1u<<2)
#define	MDMA_C9ISR_CTCIF9		(0x1u<<1)
#define	MDMA_C9ISR_TEIF9		(0x1u<<0)

// C9IFCR Configuration

#define	MDMA_C9IFCR_CLTCIF9		(0x1u<<4)
#define	MDMA_C9IFCR_CBTIF9		(0x1u<<3)
#define	MDMA_C9IFCR_CBRTIF9		(0x1u<<2)
#define	MDMA_C9IFCR_CCTCIF9		(0x1u<<1)
#define	MDMA_C9IFCR_CTEIF9		(0x1u<<0)

// C9ESR Configuration

#define	MDMA_C9ESR_BSE			(0x1u<<11)
#define	MDMA_C9ESR_ASE			(0x1u<<10)
#define	MDMA_C9ESR_TEMD			(0x1u<<9)
#define	MDMA_C9ESR_TELD			(0x1u<<8)
#define	MDMA_C9ESR_TED			(0x1u<<7)
#define	MDMA_C9ESR_TEA			(0x7Fu<<0)
#define	MDMA_C9ESR_TEA_0		(0x1u<<0)

// C9CR Configuration

#define	MDMA_C9CR_SWRQ			(0x1u<<16)
#define	MDMA_C9CR_WEX			(0x1u<<14)
#define	MDMA_C9CR_HEX			(0x1u<<13)
#define	MDMA_C9CR_BEX			(0x1u<<12)
#define	MDMA_C9CR_PL			(0x3u<<6)
#define	MDMA_C9CR_PL_0			(0x1u<<6)
#define	MDMA_C9CR_TCIE			(0x1u<<5)
#define	MDMA_C9CR_BTIE			(0x1u<<4)
#define	MDMA_C9CR_BRTIE			(0x1u<<3)
#define	MDMA_C9CR_CTCIE			(0x1u<<2)
#define	MDMA_C9CR_TEIE			(0x1u<<1)
#define	MDMA_C9CR_EN			(0x1u<<0)

// C9TCR Configuration

#define	MDMA_C9TCR_BWM			(0x1u<<31)
#define	MDMA_C9TCR_SWRM			(0x1u<<30)
#define	MDMA_C9TCR_TRGM			(0x3u<<28)
#define	MDMA_C9TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C9TCR_PAM			(0x3u<<26)
#define	MDMA_C9TCR_PAM_0		(0x1u<<26)
#define	MDMA_C9TCR_PKE			(0x1u<<25)
#define	MDMA_C9TCR_TLEN			(0x7Fu<<18)
#define	MDMA_C9TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C9TCR_DBURST		(0x7u<<15)
#define	MDMA_C9TCR_DBURST_0		(0x1u<<15)
#define	MDMA_C9TCR_SBURST		(0x7u<<12)
#define	MDMA_C9TCR_SBURST_0		(0x1u<<12)
#define	MDMA_C9TCR_DINCOS		(0x3u<<10)
#define	MDMA_C9TCR_DINCOS_0		(0x1u<<10)
#define	MDMA_C9TCR_SINCOS		(0x3u<<8)
#define	MDMA_C9TCR_SINCOS_0		(0x1u<<8)
#define	MDMA_C9TCR_DSIZE		(0x3u<<6)
#define	MDMA_C9TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C9TCR_SSIZE		(0x3u<<4)
#define	MDMA_C9TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C9TCR_DINC			(0x3u<<2)
#define	MDMA_C9TCR_DINC_0		(0x1u<<2)
#define	MDMA_C9TCR_SINC			(0x3u<<0)
#define	MDMA_C9TCR_SINC_0		(0x1u<<0)

// C9BNDTR Configuration

#define	MDMA_C9BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C9BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C9BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C9BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C9BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C9BNDTR_BNDT_0		(0x1u<<0)

// C9SAR Configuration

#define	MDMA_C9SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C9SAR_SAR_0		(0x1u<<0)

// C9DAR Configuration

#define	MDMA_C9DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C9DAR_DAR_0		(0x1u<<0)

// C9BRUR Configuration

#define	MDMA_C9BRUR_DUV			(0xFFFFu<<16)
#define	MDMA_C9BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C9BRUR_SUV			(0xFFFFu<<0)
#define	MDMA_C9BRUR_SUV_0		(0x1u<<0)

// C9LAR Configuration

#define	MDMA_C9LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C9LAR_LAR_0		(0x1u<<0)

// C9TBR Configuration

#define	MDMA_C9TBR_DBUS			(0x1u<<17)
#define	MDMA_C9TBR_SBUS			(0x1u<<16)
#define	MDMA_C9TBR_TSEL			(0x3Fu<<0)
#define	MDMA_C9TBR_TSEL_0		(0x1u<<0)

// C9MAR Configuration

#define	MDMA_C9MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C9MAR_MAR_0		(0x1u<<0)

// C9MDR Configuration

#define	MDMA_C9MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C9MDR_MDR_0		(0x1u<<0)

// C10ISR Configuration

#define	MDMA_C10ISR_CRQA10		(0x1u<<16)
#define	MDMA_C10ISR_TCIF10		(0x1u<<4)
#define	MDMA_C10ISR_BTIF10		(0x1u<<3)
#define	MDMA_C10ISR_BRTIF10		(0x1u<<2)
#define	MDMA_C10ISR_CTCIF10		(0x1u<<1)
#define	MDMA_C10ISR_TEIF10		(0x1u<<0)

// C10IFCR Configuration

#define	MDMA_C10IFCR_CLTCIF10	(0x1u<<4)
#define	MDMA_C10IFCR_CBTIF10	(0x1u<<3)
#define	MDMA_C10IFCR_CBRTIF10	(0x1u<<2)
#define	MDMA_C10IFCR_CCTCIF10	(0x1u<<1)
#define	MDMA_C10IFCR_CTEIF10	(0x1u<<0)

// C10ESR Configuration

#define	MDMA_C10ESR_BSE			(0x1u<<11)
#define	MDMA_C10ESR_ASE			(0x1u<<10)
#define	MDMA_C10ESR_TEMD		(0x1u<<9)
#define	MDMA_C10ESR_TELD		(0x1u<<8)
#define	MDMA_C10ESR_TED			(0x1u<<7)
#define	MDMA_C10ESR_TEA			(0x7Fu<<0)
#define	MDMA_C10ESR_TEA_0		(0x1u<<0)

// C10CR Configuration

#define	MDMA_C10CR_SWRQ			(0x1u<<16)
#define	MDMA_C10CR_WEX			(0x1u<<14)
#define	MDMA_C10CR_HEX			(0x1u<<13)
#define	MDMA_C10CR_BEX			(0x1u<<12)
#define	MDMA_C10CR_PL			(0x3u<<6)
#define	MDMA_C10CR_PL_0			(0x1u<<6)
#define	MDMA_C10CR_TCIE			(0x1u<<5)
#define	MDMA_C10CR_BTIE			(0x1u<<4)
#define	MDMA_C10CR_BRTIE		(0x1u<<3)
#define	MDMA_C10CR_CTCIE		(0x1u<<2)
#define	MDMA_C10CR_TEIE			(0x1u<<1)
#define	MDMA_C10CR_EN			(0x1u<<0)

// C10TCR Configuration

#define	MDMA_C10TCR_BWM			(0x1u<<31)
#define	MDMA_C10TCR_SWRM		(0x1u<<30)
#define	MDMA_C10TCR_TRGM		(0x3u<<28)
#define	MDMA_C10TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C10TCR_PAM			(0x3u<<26)
#define	MDMA_C10TCR_PAM_0		(0x1u<<26)
#define	MDMA_C10TCR_PKE			(0x1u<<25)
#define	MDMA_C10TCR_TLEN		(0x7Fu<<18)
#define	MDMA_C10TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C10TCR_DBURST		(0x7u<<15)
#define	MDMA_C10TCR_DBURST_0	(0x1u<<15)
#define	MDMA_C10TCR_SBURST		(0x7u<<12)
#define	MDMA_C10TCR_SBURST_0	(0x1u<<12)
#define	MDMA_C10TCR_DINCOS		(0x3u<<10)
#define	MDMA_C10TCR_DINCOS_0	(0x1u<<10)
#define	MDMA_C10TCR_SINCOS		(0x3u<<8)
#define	MDMA_C10TCR_SINCOS_0	(0x1u<<8)
#define	MDMA_C10TCR_DSIZE		(0x3u<<6)
#define	MDMA_C10TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C10TCR_SSIZE		(0x3u<<4)
#define	MDMA_C10TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C10TCR_DINC		(0x3u<<2)
#define	MDMA_C10TCR_DINC_0		(0x1u<<2)
#define	MDMA_C10TCR_SINC		(0x3u<<0)
#define	MDMA_C10TCR_SINC_0		(0x1u<<0)

// C10BNDTR Configuration

#define	MDMA_C10BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C10BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C10BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C10BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C10BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C10BNDTR_BNDT_0	(0x1u<<0)

// C10SAR Configuration

#define	MDMA_C10SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C10SAR_SAR_0		(0x1u<<0)

// C10DAR Configuration

#define	MDMA_C10DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C10DAR_DAR_0		(0x1u<<0)

// C10BRUR Configuration

#define	MDMA_C10BRUR_DUV		(0xFFFFu<<16)
#define	MDMA_C10BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C10BRUR_SUV		(0xFFFFu<<0)
#define	MDMA_C10BRUR_SUV_0		(0x1u<<0)

// C10LAR Configuration

#define	MDMA_C10LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C10LAR_LAR_0		(0x1u<<0)

// C10TBR Configuration

#define	MDMA_C10TBR_DBUS		(0x1u<<17)
#define	MDMA_C10TBR_SBUS		(0x1u<<16)
#define	MDMA_C10TBR_TSEL		(0x3Fu<<0)
#define	MDMA_C10TBR_TSEL_0		(0x1u<<0)

// C10MAR Configuration

#define	MDMA_C10MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C10MAR_MAR_0		(0x1u<<0)

// C10MDR Configuration

#define	MDMA_C10MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C10MDR_MDR_0		(0x1u<<0)

// C11ISR Configuration

#define	MDMA_C11ISR_CRQA11		(0x1u<<16)
#define	MDMA_C11ISR_TCIF11		(0x1u<<4)
#define	MDMA_C11ISR_BTIF11		(0x1u<<3)
#define	MDMA_C11ISR_BRTIF11		(0x1u<<2)
#define	MDMA_C11ISR_CTCIF11		(0x1u<<1)
#define	MDMA_C11ISR_TEIF11		(0x1u<<0)

// C11IFCR Configuration

#define	MDMA_C11IFCR_CLTCIF11	(0x1u<<4)
#define	MDMA_C11IFCR_CBTIF11	(0x1u<<3)
#define	MDMA_C11IFCR_CBRTIF11	(0x1u<<2)
#define	MDMA_C11IFCR_CCTCIF11	(0x1u<<1)
#define	MDMA_C11IFCR_CTEIF11	(0x1u<<0)

// C11ESR Configuration

#define	MDMA_C11ESR_BSE			(0x1u<<11)
#define	MDMA_C11ESR_ASE			(0x1u<<10)
#define	MDMA_C11ESR_TEMD		(0x1u<<9)
#define	MDMA_C11ESR_TELD		(0x1u<<8)
#define	MDMA_C11ESR_TED			(0x1u<<7)
#define	MDMA_C11ESR_TEA			(0x7Fu<<0)
#define	MDMA_C11ESR_TEA_0		(0x1u<<0)

// C11CR Configuration

#define	MDMA_C11CR_SWRQ			(0x1u<<16)
#define	MDMA_C11CR_WEX			(0x1u<<14)
#define	MDMA_C11CR_HEX			(0x1u<<13)
#define	MDMA_C11CR_BEX			(0x1u<<12)
#define	MDMA_C11CR_PL			(0x3u<<6)
#define	MDMA_C11CR_PL_0			(0x1u<<6)
#define	MDMA_C11CR_TCIE			(0x1u<<5)
#define	MDMA_C11CR_BTIE			(0x1u<<4)
#define	MDMA_C11CR_BRTIE		(0x1u<<3)
#define	MDMA_C11CR_CTCIE		(0x1u<<2)
#define	MDMA_C11CR_TEIE			(0x1u<<1)
#define	MDMA_C11CR_EN			(0x1u<<0)

// C11TCR Configuration

#define	MDMA_C11TCR_BWM			(0x1u<<31)
#define	MDMA_C11TCR_SWRM		(0x1u<<30)
#define	MDMA_C11TCR_TRGM		(0x3u<<28)
#define	MDMA_C11TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C11TCR_PAM			(0x3u<<26)
#define	MDMA_C11TCR_PAM_0		(0x1u<<26)
#define	MDMA_C11TCR_PKE			(0x1u<<25)
#define	MDMA_C11TCR_TLEN		(0x7Fu<<18)
#define	MDMA_C11TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C11TCR_DBURST		(0x7u<<15)
#define	MDMA_C11TCR_DBURST_0	(0x1u<<15)
#define	MDMA_C11TCR_SBURST		(0x7u<<12)
#define	MDMA_C11TCR_SBURST_0	(0x1u<<12)
#define	MDMA_C11TCR_DINCOS		(0x3u<<10)
#define	MDMA_C11TCR_DINCOS_0	(0x1u<<10)
#define	MDMA_C11TCR_SINCOS		(0x3u<<8)
#define	MDMA_C11TCR_SINCOS_0	(0x1u<<8)
#define	MDMA_C11TCR_DSIZE		(0x3u<<6)
#define	MDMA_C11TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C11TCR_SSIZE		(0x3u<<4)
#define	MDMA_C11TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C11TCR_DINC		(0x3u<<2)
#define	MDMA_C11TCR_DINC_0		(0x1u<<2)
#define	MDMA_C11TCR_SINC		(0x3u<<0)
#define	MDMA_C11TCR_SINC_0		(0x1u<<0)

// C11BNDTR Configuration

#define	MDMA_C11BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C11BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C11BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C11BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C11BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C11BNDTR_BNDT_0	(0x1u<<0)

// C11SAR Configuration

#define	MDMA_C11SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C11SAR_SAR_0		(0x1u<<0)

// C11DAR Configuration

#define	MDMA_C11DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C11DAR_DAR_0		(0x1u<<0)

// C11BRUR Configuration

#define	MDMA_C11BRUR_DUV		(0xFFFFu<<16)
#define	MDMA_C11BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C11BRUR_SUV		(0xFFFFu<<0)
#define	MDMA_C11BRUR_SUV_0		(0x1u<<0)

// C11LAR Configuration

#define	MDMA_C11LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C11LAR_LAR_0		(0x1u<<0)

// C11TBR Configuration

#define	MDMA_C11TBR_DBUS		(0x1u<<17)
#define	MDMA_C11TBR_SBUS		(0x1u<<16)
#define	MDMA_C11TBR_TSEL		(0x3Fu<<0)
#define	MDMA_C11TBR_TSEL_0		(0x1u<<0)

// C11MAR Configuration

#define	MDMA_C11MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C11MAR_MAR_0		(0x1u<<0)

// C11MDR Configuration

#define	MDMA_C11MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C11MDR_MDR_0		(0x1u<<0)

// C12ISR Configuration

#define	MDMA_C12ISR_CRQA12		(0x1u<<16)
#define	MDMA_C12ISR_TCIF12		(0x1u<<4)
#define	MDMA_C12ISR_BTIF12		(0x1u<<3)
#define	MDMA_C12ISR_BRTIF12		(0x1u<<2)
#define	MDMA_C12ISR_CTCIF12		(0x1u<<1)
#define	MDMA_C12ISR_TEIF12		(0x1u<<0)

// C12IFCR Configuration

#define	MDMA_C12IFCR_CLTCIF12	(0x1u<<4)
#define	MDMA_C12IFCR_CBTIF12	(0x1u<<3)
#define	MDMA_C12IFCR_CBRTIF12	(0x1u<<2)
#define	MDMA_C12IFCR_CCTCIF12	(0x1u<<1)
#define	MDMA_C12IFCR_CTEIF12	(0x1u<<0)

// C12ESR Configuration

#define	MDMA_C12ESR_BSE			(0x1u<<11)
#define	MDMA_C12ESR_ASE			(0x1u<<10)
#define	MDMA_C12ESR_TEMD		(0x1u<<9)
#define	MDMA_C12ESR_TELD		(0x1u<<8)
#define	MDMA_C12ESR_TED			(0x1u<<7)
#define	MDMA_C12ESR_TEA			(0x7Fu<<0)
#define	MDMA_C12ESR_TEA_0		(0x1u<<0)

// C12CR Configuration

#define	MDMA_C12CR_SWRQ			(0x1u<<16)
#define	MDMA_C12CR_WEX			(0x1u<<14)
#define	MDMA_C12CR_HEX			(0x1u<<13)
#define	MDMA_C12CR_BEX			(0x1u<<12)
#define	MDMA_C12CR_PL			(0x3u<<6)
#define	MDMA_C12CR_PL_0			(0x1u<<6)
#define	MDMA_C12CR_TCIE			(0x1u<<5)
#define	MDMA_C12CR_BTIE			(0x1u<<4)
#define	MDMA_C12CR_BRTIE		(0x1u<<3)
#define	MDMA_C12CR_CTCIE		(0x1u<<2)
#define	MDMA_C12CR_TEIE			(0x1u<<1)
#define	MDMA_C12CR_EN			(0x1u<<0)

// C12TCR Configuration

#define	MDMA_C12TCR_BWM			(0x1u<<31)
#define	MDMA_C12TCR_SWRM		(0x1u<<30)
#define	MDMA_C12TCR_TRGM		(0x3u<<28)
#define	MDMA_C12TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C12TCR_PAM			(0x3u<<26)
#define	MDMA_C12TCR_PAM_0		(0x1u<<26)
#define	MDMA_C12TCR_PKE			(0x1u<<25)
#define	MDMA_C12TCR_TLEN		(0x7Fu<<18)
#define	MDMA_C12TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C12TCR_DBURST		(0x7u<<15)
#define	MDMA_C12TCR_DBURST_0	(0x1u<<15)
#define	MDMA_C12TCR_SBURST		(0x7u<<12)
#define	MDMA_C12TCR_SBURST_0	(0x1u<<12)
#define	MDMA_C12TCR_DINCOS		(0x3u<<10)
#define	MDMA_C12TCR_DINCOS_0	(0x1u<<10)
#define	MDMA_C12TCR_SINCOS		(0x3u<<8)
#define	MDMA_C12TCR_SINCOS_0	(0x1u<<8)
#define	MDMA_C12TCR_DSIZE		(0x3u<<6)
#define	MDMA_C12TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C12TCR_SSIZE		(0x3u<<4)
#define	MDMA_C12TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C12TCR_DINC		(0x3u<<2)
#define	MDMA_C12TCR_DINC_0		(0x1u<<2)
#define	MDMA_C12TCR_SINC		(0x3u<<0)
#define	MDMA_C12TCR_SINC_0		(0x1u<<0)

// C12BNDTR Configuration

#define	MDMA_C12BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C12BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C12BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C12BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C12BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C12BNDTR_BNDT_0	(0x1u<<0)

// C12SAR Configuration

#define	MDMA_C12SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C12SAR_SAR_0		(0x1u<<0)

// C12DAR Configuration

#define	MDMA_C12DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C12DAR_DAR_0		(0x1u<<0)

// C12BRUR Configuration

#define	MDMA_C12BRUR_DUV		(0xFFFFu<<16)
#define	MDMA_C12BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C12BRUR_SUV		(0xFFFFu<<0)
#define	MDMA_C12BRUR_SUV_0		(0x1u<<0)

// C12LAR Configuration

#define	MDMA_C12LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C12LAR_LAR_0		(0x1u<<0)

// C12TBR Configuration

#define	MDMA_C12TBR_DBUS		(0x1u<<17)
#define	MDMA_C12TBR_SBUS		(0x1u<<16)
#define	MDMA_C12TBR_TSEL		(0x3Fu<<0)
#define	MDMA_C12TBR_TSEL_0		(0x1u<<0)

// C12MAR Configuration

#define	MDMA_C12MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C12MAR_MAR_0		(0x1u<<0)

// C12MDR Configuration

#define	MDMA_C12MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C12MDR_MDR_0		(0x1u<<0)

// C13ISR Configuration

#define	MDMA_C13ISR_CRQA13		(0x1u<<16)
#define	MDMA_C13ISR_TCIF13		(0x1u<<4)
#define	MDMA_C13ISR_BTIF13		(0x1u<<3)
#define	MDMA_C13ISR_BRTIF13		(0x1u<<2)
#define	MDMA_C13ISR_CTCIF13		(0x1u<<1)
#define	MDMA_C13ISR_TEIF13		(0x1u<<0)

// C13IFCR Configuration

#define	MDMA_C13IFCR_CLTCIF13	(0x1u<<4)
#define	MDMA_C13IFCR_CBTIF13	(0x1u<<3)
#define	MDMA_C13IFCR_CBRTIF13	(0x1u<<2)
#define	MDMA_C13IFCR_CCTCIF13	(0x1u<<1)
#define	MDMA_C13IFCR_CTEIF13	(0x1u<<0)

// C13ESR Configuration

#define	MDMA_C13ESR_BSE			(0x1u<<11)
#define	MDMA_C13ESR_ASE			(0x1u<<10)
#define	MDMA_C13ESR_TEMD		(0x1u<<9)
#define	MDMA_C13ESR_TELD		(0x1u<<8)
#define	MDMA_C13ESR_TED			(0x1u<<7)
#define	MDMA_C13ESR_TEA			(0x7Fu<<0)
#define	MDMA_C13ESR_TEA_0		(0x1u<<0)

// C13CR Configuration

#define	MDMA_C13CR_SWRQ			(0x1u<<16)
#define	MDMA_C13CR_WEX			(0x1u<<14)
#define	MDMA_C13CR_HEX			(0x1u<<13)
#define	MDMA_C13CR_BEX			(0x1u<<12)
#define	MDMA_C13CR_PL			(0x3u<<6)
#define	MDMA_C13CR_PL_0			(0x1u<<6)
#define	MDMA_C13CR_TCIE			(0x1u<<5)
#define	MDMA_C13CR_BTIE			(0x1u<<4)
#define	MDMA_C13CR_BRTIE		(0x1u<<3)
#define	MDMA_C13CR_CTCIE		(0x1u<<2)
#define	MDMA_C13CR_TEIE			(0x1u<<1)
#define	MDMA_C13CR_EN			(0x1u<<0)

// C13TCR Configuration

#define	MDMA_C13TCR_BWM			(0x1u<<31)
#define	MDMA_C13TCR_SWRM		(0x1u<<30)
#define	MDMA_C13TCR_TRGM		(0x3u<<28)
#define	MDMA_C13TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C13TCR_PAM			(0x3u<<26)
#define	MDMA_C13TCR_PAM_0		(0x1u<<26)
#define	MDMA_C13TCR_PKE			(0x1u<<25)
#define	MDMA_C13TCR_TLEN		(0x7Fu<<18)
#define	MDMA_C13TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C13TCR_DBURST		(0x7u<<15)
#define	MDMA_C13TCR_DBURST_0	(0x1u<<15)
#define	MDMA_C13TCR_SBURST		(0x7u<<12)
#define	MDMA_C13TCR_SBURST_0	(0x1u<<12)
#define	MDMA_C13TCR_DINCOS		(0x3u<<10)
#define	MDMA_C13TCR_DINCOS_0	(0x1u<<10)
#define	MDMA_C13TCR_SINCOS		(0x3u<<8)
#define	MDMA_C13TCR_SINCOS_0	(0x1u<<8)
#define	MDMA_C13TCR_DSIZE		(0x3u<<6)
#define	MDMA_C13TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C13TCR_SSIZE		(0x3u<<4)
#define	MDMA_C13TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C13TCR_DINC		(0x3u<<2)
#define	MDMA_C13TCR_DINC_0		(0x1u<<2)
#define	MDMA_C13TCR_SINC		(0x3u<<0)
#define	MDMA_C13TCR_SINC_0		(0x1u<<0)

// C13BNDTR Configuration

#define	MDMA_C13BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C13BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C13BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C13BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C13BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C13BNDTR_BNDT_0	(0x1u<<0)

// C13SAR Configuration

#define	MDMA_C13SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C13SAR_SAR_0		(0x1u<<0)

// C13DAR Configuration

#define	MDMA_C13DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C13DAR_DAR_0		(0x1u<<0)

// C13BRUR Configuration

#define	MDMA_C13BRUR_DUV		(0xFFFFu<<16)
#define	MDMA_C13BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C13BRUR_SUV		(0xFFFFu<<0)
#define	MDMA_C13BRUR_SUV_0		(0x1u<<0)

// C13LAR Configuration

#define	MDMA_C13LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C13LAR_LAR_0		(0x1u<<0)

// C13TBR Configuration

#define	MDMA_C13TBR_DBUS		(0x1u<<17)
#define	MDMA_C13TBR_SBUS		(0x1u<<16)
#define	MDMA_C13TBR_TSEL		(0x3Fu<<0)
#define	MDMA_C13TBR_TSEL_0		(0x1u<<0)

// C13MAR Configuration

#define	MDMA_C13MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C13MAR_MAR_0		(0x1u<<0)

// C13MDR Configuration

#define	MDMA_C13MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C13MDR_MDR_0		(0x1u<<0)

// C14ISR Configuration

#define	MDMA_C14ISR_CRQA14		(0x1u<<16)
#define	MDMA_C14ISR_TCIF14		(0x1u<<4)
#define	MDMA_C14ISR_BTIF14		(0x1u<<3)
#define	MDMA_C14ISR_BRTIF14		(0x1u<<2)
#define	MDMA_C14ISR_CTCIF14		(0x1u<<1)
#define	MDMA_C14ISR_TEIF14		(0x1u<<0)

// C14IFCR Configuration

#define	MDMA_C14IFCR_CLTCIF14	(0x1u<<4)
#define	MDMA_C14IFCR_CBTIF14	(0x1u<<3)
#define	MDMA_C14IFCR_CBRTIF14	(0x1u<<2)
#define	MDMA_C14IFCR_CCTCIF14	(0x1u<<1)
#define	MDMA_C14IFCR_CTEIF14	(0x1u<<0)

// C14ESR Configuration

#define	MDMA_C14ESR_BSE			(0x1u<<11)
#define	MDMA_C14ESR_ASE			(0x1u<<10)
#define	MDMA_C14ESR_TEMD		(0x1u<<9)
#define	MDMA_C14ESR_TELD		(0x1u<<8)
#define	MDMA_C14ESR_TED			(0x1u<<7)
#define	MDMA_C14ESR_TEA			(0x7Fu<<0)
#define	MDMA_C14ESR_TEA_0		(0x1u<<0)

// C14CR Configuration

#define	MDMA_C14CR_SWRQ			(0x1u<<16)
#define	MDMA_C14CR_WEX			(0x1u<<14)
#define	MDMA_C14CR_HEX			(0x1u<<13)
#define	MDMA_C14CR_BEX			(0x1u<<12)
#define	MDMA_C14CR_PL			(0x3u<<6)
#define	MDMA_C14CR_PL_0			(0x1u<<6)
#define	MDMA_C14CR_TCIE			(0x1u<<5)
#define	MDMA_C14CR_BTIE			(0x1u<<4)
#define	MDMA_C14CR_BRTIE		(0x1u<<3)
#define	MDMA_C14CR_CTCIE		(0x1u<<2)
#define	MDMA_C14CR_TEIE			(0x1u<<1)
#define	MDMA_C14CR_EN			(0x1u<<0)

// C14TCR Configuration

#define	MDMA_C14TCR_BWM			(0x1u<<31)
#define	MDMA_C14TCR_SWRM		(0x1u<<30)
#define	MDMA_C14TCR_TRGM		(0x3u<<28)
#define	MDMA_C14TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C14TCR_PAM			(0x3u<<26)
#define	MDMA_C14TCR_PAM_0		(0x1u<<26)
#define	MDMA_C14TCR_PKE			(0x1u<<25)
#define	MDMA_C14TCR_TLEN		(0x7Fu<<18)
#define	MDMA_C14TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C14TCR_DBURST		(0x7u<<15)
#define	MDMA_C14TCR_DBURST_0	(0x1u<<15)
#define	MDMA_C14TCR_SBURST		(0x7u<<12)
#define	MDMA_C14TCR_SBURST_0	(0x1u<<12)
#define	MDMA_C14TCR_DINCOS		(0x3u<<10)
#define	MDMA_C14TCR_DINCOS_0	(0x1u<<10)
#define	MDMA_C14TCR_SINCOS		(0x3u<<8)
#define	MDMA_C14TCR_SINCOS_0	(0x1u<<8)
#define	MDMA_C14TCR_DSIZE		(0x3u<<6)
#define	MDMA_C14TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C14TCR_SSIZE		(0x3u<<4)
#define	MDMA_C14TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C14TCR_DINC		(0x3u<<2)
#define	MDMA_C14TCR_DINC_0		(0x1u<<2)
#define	MDMA_C14TCR_SINC		(0x3u<<0)
#define	MDMA_C14TCR_SINC_0		(0x1u<<0)

// C14BNDTR Configuration

#define	MDMA_C14BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C14BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C14BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C14BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C14BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C14BNDTR_BNDT_0	(0x1u<<0)

// C14SAR Configuration

#define	MDMA_C14SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C14SAR_SAR_0		(0x1u<<0)

// C14DAR Configuration

#define	MDMA_C14DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C14DAR_DAR_0		(0x1u<<0)

// C14BRUR Configuration

#define	MDMA_C14BRUR_DUV		(0xFFFFu<<16)
#define	MDMA_C14BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C14BRUR_SUV		(0xFFFFu<<0)
#define	MDMA_C14BRUR_SUV_0		(0x1u<<0)

// C14LAR Configuration

#define	MDMA_C14LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C14LAR_LAR_0		(0x1u<<0)

// C14TBR Configuration

#define	MDMA_C14TBR_DBUS		(0x1u<<17)
#define	MDMA_C14TBR_SBUS		(0x1u<<16)
#define	MDMA_C14TBR_TSEL		(0x3Fu<<0)
#define	MDMA_C14TBR_TSEL_0		(0x1u<<0)

// C14MAR Configuration

#define	MDMA_C14MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C14MAR_MAR_0		(0x1u<<0)

// C14MDR Configuration

#define	MDMA_C14MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C14MDR_MDR_0		(0x1u<<0)

// C15ISR Configuration

#define	MDMA_C15ISR_CRQA15		(0x1u<<16)
#define	MDMA_C15ISR_TCIF15		(0x1u<<4)
#define	MDMA_C15ISR_BTIF15		(0x1u<<3)
#define	MDMA_C15ISR_BRTIF15		(0x1u<<2)
#define	MDMA_C15ISR_CTCIF15		(0x1u<<1)
#define	MDMA_C15ISR_TEIF15		(0x1u<<0)

// C15IFCR Configuration

#define	MDMA_C15IFCR_CLTCIF15	(0x1u<<4)
#define	MDMA_C15IFCR_CBTIF15	(0x1u<<3)
#define	MDMA_C15IFCR_CBRTIF15	(0x1u<<2)
#define	MDMA_C15IFCR_CCTCIF15	(0x1u<<1)
#define	MDMA_C15IFCR_CTEIF15	(0x1u<<0)

// C15ESR Configuration

#define	MDMA_C15ESR_BSE			(0x1u<<11)
#define	MDMA_C15ESR_ASE			(0x1u<<10)
#define	MDMA_C15ESR_TEMD		(0x1u<<9)
#define	MDMA_C15ESR_TELD		(0x1u<<8)
#define	MDMA_C15ESR_TED			(0x1u<<7)
#define	MDMA_C15ESR_TEA			(0x7Fu<<0)
#define	MDMA_C15ESR_TEA_0		(0x1u<<0)

// C15CR Configuration

#define	MDMA_C15CR_SWRQ			(0x1u<<16)
#define	MDMA_C15CR_WEX			(0x1u<<14)
#define	MDMA_C15CR_HEX			(0x1u<<13)
#define	MDMA_C15CR_BEX			(0x1u<<12)
#define	MDMA_C15CR_PL			(0x3u<<6)
#define	MDMA_C15CR_PL_0			(0x1u<<6)
#define	MDMA_C15CR_TCIE			(0x1u<<5)
#define	MDMA_C15CR_BTIE			(0x1u<<4)
#define	MDMA_C15CR_BRTIE		(0x1u<<3)
#define	MDMA_C15CR_CTCIE		(0x1u<<2)
#define	MDMA_C15CR_TEIE			(0x1u<<1)
#define	MDMA_C15CR_EN			(0x1u<<0)

// C15TCR Configuration

#define	MDMA_C15TCR_BWM			(0x1u<<31)
#define	MDMA_C15TCR_SWRM		(0x1u<<30)
#define	MDMA_C15TCR_TRGM		(0x3u<<28)
#define	MDMA_C15TCR_TRGM_0		(0x1u<<28)
#define	MDMA_C15TCR_PAM			(0x3u<<26)
#define	MDMA_C15TCR_PAM_0		(0x1u<<26)
#define	MDMA_C15TCR_PKE			(0x1u<<25)
#define	MDMA_C15TCR_TLEN		(0x7Fu<<18)
#define	MDMA_C15TCR_TLEN_0		(0x1u<<18)
#define	MDMA_C15TCR_DBURST		(0x7u<<15)
#define	MDMA_C15TCR_DBURST_0	(0x1u<<15)
#define	MDMA_C15TCR_SBURST		(0x7u<<12)
#define	MDMA_C15TCR_SBURST_0	(0x1u<<12)
#define	MDMA_C15TCR_DINCOS		(0x3u<<10)
#define	MDMA_C15TCR_DINCOS_0	(0x1u<<10)
#define	MDMA_C15TCR_SINCOS		(0x3u<<8)
#define	MDMA_C15TCR_SINCOS_0	(0x1u<<8)
#define	MDMA_C15TCR_DSIZE		(0x3u<<6)
#define	MDMA_C15TCR_DSIZE_0		(0x1u<<6)
#define	MDMA_C15TCR_SSIZE		(0x3u<<4)
#define	MDMA_C15TCR_SSIZE_0		(0x1u<<4)
#define	MDMA_C15TCR_DINC		(0x3u<<2)
#define	MDMA_C15TCR_DINC_0		(0x1u<<2)
#define	MDMA_C15TCR_SINC		(0x3u<<0)
#define	MDMA_C15TCR_SINC_0		(0x1u<<0)

// C15BNDTR Configuration

#define	MDMA_C15BNDTR_BRC		(0xFFFu<<20)
#define	MDMA_C15BNDTR_BRC_0		(0x1u<<20)
#define	MDMA_C15BNDTR_BRDUM		(0x1u<<19)
#define	MDMA_C15BNDTR_BRSUM		(0x1u<<18)
#define	MDMA_C15BNDTR_BNDT		(0x1FFFFu<<0)
#define	MDMA_C15BNDTR_BNDT_0	(0x1u<<0)

// C15SAR Configuration

#define	MDMA_C15SAR_SAR			(0xFFFFFFFFu<<0)
#define	MDMA_C15SAR_SAR_0		(0x1u<<0)

// C15DAR Configuration

#define	MDMA_C15DAR_DAR			(0xFFFFFFFFu<<0)
#define	MDMA_C15DAR_DAR_0		(0x1u<<0)

// C15BRUR Configuration

#define	MDMA_C15BRUR_DUV		(0xFFFFu<<16)
#define	MDMA_C15BRUR_DUV_0		(0x1u<<16)
#define	MDMA_C15BRUR_SUV		(0xFFFFu<<0)
#define	MDMA_C15BRUR_SUV_0		(0x1u<<0)

// C15LAR Configuration

#define	MDMA_C15LAR_LAR			(0xFFFFFFFFu<<0)
#define	MDMA_C15LAR_LAR_0		(0x1u<<0)

// C15TBR Configuration

#define	MDMA_C15TBR_DBUS		(0x1u<<17)
#define	MDMA_C15TBR_SBUS		(0x1u<<16)
#define	MDMA_C15TBR_TSEL		(0x3Fu<<0)
#define	MDMA_C15TBR_TSEL_0		(0x1u<<0)

// C15MAR Configuration

#define	MDMA_C15MAR_MAR			(0xFFFFFFFFu<<0)
#define	MDMA_C15MAR_MAR_0		(0x1u<<0)

// C15MDR Configuration

#define	MDMA_C15MDR_MDR			(0xFFFFFFFFu<<0)
#define	MDMA_C15MDR_MDR_0		(0x1u<<0)
