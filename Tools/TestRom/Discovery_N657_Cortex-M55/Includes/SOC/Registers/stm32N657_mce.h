/*
; stm32N657_mce.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_mce equates.
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

// MCE address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	IASR;
	volatile	uint32_t	IACR;
	volatile	uint32_t	IAIER;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	IADDR;
	volatile	uint32_t	RESERVED1[6];
	volatile	uint32_t	REGCR1;
	volatile	uint32_t	SADDR1;
	volatile	uint32_t	EADDR1;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	REGCR2;
	volatile	uint32_t	SADDR2;
	volatile	uint32_t	EADDR2;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	REGCR3;
	volatile	uint32_t	SADDR3;
	volatile	uint32_t	EADDR3;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	REGCR4;
	volatile	uint32_t	SADDR4;
	volatile	uint32_t	EADDR4;
	volatile	uint32_t	RESERVED5[97];
	volatile	uint32_t	MKEYR0;
	volatile	uint32_t	MKEYR1;
	volatile	uint32_t	MKEYR2;
	volatile	uint32_t	MKEYR3;
	volatile	uint32_t	MKEYR4;
	volatile	uint32_t	MKEYR5;
	volatile	uint32_t	MKEYR6;
	volatile	uint32_t	MKEYR7;
	volatile	uint32_t	FMKEYR0;
	volatile	uint32_t	FMKEYR1;
	volatile	uint32_t	FMKEYR2;
	volatile	uint32_t	FMKEYR3;
	volatile	uint32_t	FMKEYR4;
	volatile	uint32_t	FMKEYR5;
	volatile	uint32_t	FMKEYR6;
	volatile	uint32_t	FMKEYR7;
	volatile	uint32_t	CC1CFGR;
	volatile	uint32_t	CC1NR0;
	volatile	uint32_t	CC1NR1;
	volatile	uint32_t	CC1KEYR0;
	volatile	uint32_t	CC1KEYR1;
	volatile	uint32_t	CC1KEYR2;
	volatile	uint32_t	CC1KEYR3;
	volatile	uint32_t	RESERVED6[5];
	volatile	uint32_t	CC2CFGR;
	volatile	uint32_t	CC2NR0;
	volatile	uint32_t	CC2NR1;
	volatile	uint32_t	CC2KEYR0;
	volatile	uint32_t	CC2KEYR1;
	volatile	uint32_t	CC2KEYR2;
	volatile	uint32_t	CC2KEYR3;
} MCE_TypeDef;

#if (defined(__cplusplus))
#define	MCE1_NS	reinterpret_cast<MCE_TypeDef *>(0x4802B800u)
#define	MCE1_S	reinterpret_cast<MCE_TypeDef *>(0x5802B800u)
#define	MCE2_NS	reinterpret_cast<MCE_TypeDef *>(0x4802BC00u)
#define	MCE2_S	reinterpret_cast<MCE_TypeDef *>(0x5802BC00u)
#define	MCE3_NS	reinterpret_cast<MCE_TypeDef *>(0x4802C000u)
#define	MCE3_S	reinterpret_cast<MCE_TypeDef *>(0x5802C000u)
#define	MCE4_NS	reinterpret_cast<MCE_TypeDef *>(0x4802E000u)
#define	MCE4_S	reinterpret_cast<MCE_TypeDef *>(0x5802E000u)

#else
#define	MCE1_NS	((MCE_TypeDef *)0x4802B800u)
#define	MCE1_S	((MCE_TypeDef *)0x5802B800u)
#define	MCE2_NS	((MCE_TypeDef *)0x4802BC00u)
#define	MCE2_S	((MCE_TypeDef *)0x5802BC00u)
#define	MCE3_NS	((MCE_TypeDef *)0x4802C000u)
#define	MCE3_S	((MCE_TypeDef *)0x5802C000u)
#define	MCE4_NS	((MCE_TypeDef *)0x4802E000u)
#define	MCE4_S	((MCE_TypeDef *)0x5802E000u)
#endif

// CR Configuration

#define	MCE_CR_CIPHERSEL			(0x3u<<4)
#define	MCE_CR_CIPHERSEL_0			(0x1u<<4)
#define	MCE_CR_MKLOCK				(0x1u<<1)
#define	MCE_CR_GLOCK				(0x1u<<0)

#define	MCE_CR_CIPHERSEL_B_0X1		(0x1u<<4)
#define	MCE_CR_CIPHERSEL_B_0X2		(0x2u<<4)
#define	MCE_CR_CIPHERSEL_B_0X3		(0x3u<<4)
#define	MCE_CR_CIPHERSEL_B_0X0		(0x0u<<4)
#define	MCE_CR_MKLOCK_B_0X0			(0x0u<<1)
#define	MCE_CR_MKLOCK_B_0X1			(0x1u<<1)
#define	MCE_CR_GLOCK_B_0X0			(0x0u<<0)
#define	MCE_CR_GLOCK_B_0X1			(0x1u<<0)

// SR Configuration

#define	MCE_SR_ENCDIS				(0x1u<<4)
#define	MCE_SR_FMKVALID				(0x1u<<2)
#define	MCE_SR_MKVALID				(0x1u<<0)

#define	MCE_SR_ENCDIS_B_0X0			(0x0u<<4)
#define	MCE_SR_ENCDIS_B_0X1			(0x1u<<4)
#define	MCE_SR_FMKVALID_B_0X0		(0x0u<<2)
#define	MCE_SR_FMKVALID_B_0X1		(0x1u<<2)
#define	MCE_SR_MKVALID_B_0X0		(0x0u<<0)
#define	MCE_SR_MKVALID_B_0X1		(0x1u<<0)

// IASR Configuration

#define	MCE_IASR_IAEF				(0x1u<<1)

// IACR Configuration

#define	MCE_IACR_IAEF				(0x1u<<1)

// IAIER Configuration

#define	MCE_IAIER_IAEIE				(0x1u<<1)

#define	MCE_IAIER_IAEIE_B_0X0		(0x0u<<1)
#define	MCE_IAIER_IAEIE_B_0X1		(0x1u<<1)

// IADDR Configuration

#define	MCE_IADDR_IADD				(0xFFFFFFFFu<<0)
#define	MCE_IADDR_IADD_0			(0x1u<<0)

// REGCR1 Configuration

#define	MCE_REGCR1_ENC				(0x3u<<14)
#define	MCE_REGCR1_ENC_0			(0x1u<<14)
#define	MCE_REGCR1_CTXID			(0x3u<<9)
#define	MCE_REGCR1_CTXID_0			(0x1u<<9)
#define	MCE_REGCR1_BREN				(0x1u<<0)

#define	MCE_REGCR1_ENC_B_0X0		(0x0u<<14)
#define	MCE_REGCR1_ENC_B_0X1		(0x1u<<14)
#define	MCE_REGCR1_ENC_B_0X2		(0x2u<<14)
#define	MCE_REGCR1_ENC_B_0X3		(0x3u<<14)
#define	MCE_REGCR1_CTXID_B_0X0		(0x0u<<9)
#define	MCE_REGCR1_CTXID_B_0X1		(0x1u<<9)
#define	MCE_REGCR1_CTXID_B_0X2		(0x2u<<9)
#define	MCE_REGCR1_BREN_B_0X0		(0x0u<<0)
#define	MCE_REGCR1_BREN_B_0X1		(0x1u<<0)

// SADDR1 Configuration

#define	MCE_SADDR1_BADDSTART		(0xFFFFFu<<12)
#define	MCE_SADDR1_BADDSTART_0		(0x1u<<12)

// EADDR1 Configuration

#define	MCE_EADDR1_BADDEND			(0xFFFFFu<<12)
#define	MCE_EADDR1_BADDEND_0		(0x1u<<12)

// REGCR2 Configuration

#define	MCE_REGCR2_ENC				(0x3u<<14)
#define	MCE_REGCR2_ENC_0			(0x1u<<14)
#define	MCE_REGCR2_CTXID			(0x3u<<9)
#define	MCE_REGCR2_CTXID_0			(0x1u<<9)
#define	MCE_REGCR2_BREN				(0x1u<<0)

#define	MCE_REGCR2_ENC_B_0X0		(0x0u<<14)
#define	MCE_REGCR2_ENC_B_0X1		(0x1u<<14)
#define	MCE_REGCR2_ENC_B_0X2		(0x2u<<14)
#define	MCE_REGCR2_ENC_B_0X3		(0x3u<<14)
#define	MCE_REGCR2_CTXID_B_0X0		(0x0u<<9)
#define	MCE_REGCR2_CTXID_B_0X1		(0x1u<<9)
#define	MCE_REGCR2_CTXID_B_0X2		(0x2u<<9)
#define	MCE_REGCR2_BREN_B_0X0		(0x0u<<0)
#define	MCE_REGCR2_BREN_B_0X1		(0x1u<<0)

// SADDR2 Configuration

#define	MCE_SADDR2_BADDSTART		(0xFFFFFu<<12)
#define	MCE_SADDR2_BADDSTART_0		(0x1u<<12)

// EADDR2 Configuration

#define	MCE_EADDR2_BADDEND			(0xFFFFFu<<12)
#define	MCE_EADDR2_BADDEND_0		(0x1u<<12)

// REGCR3 Configuration

#define	MCE_REGCR3_ENC				(0x3u<<14)
#define	MCE_REGCR3_ENC_0			(0x1u<<14)
#define	MCE_REGCR3_CTXID			(0x3u<<9)
#define	MCE_REGCR3_CTXID_0			(0x1u<<9)
#define	MCE_REGCR3_BREN				(0x1u<<0)

#define	MCE_REGCR3_ENC_B_0X0		(0x0u<<14)
#define	MCE_REGCR3_ENC_B_0X1		(0x1u<<14)
#define	MCE_REGCR3_ENC_B_0X2		(0x2u<<14)
#define	MCE_REGCR3_ENC_B_0X3		(0x3u<<14)
#define	MCE_REGCR3_CTXID_B_0X0		(0x0u<<9)
#define	MCE_REGCR3_CTXID_B_0X1		(0x1u<<9)
#define	MCE_REGCR3_CTXID_B_0X2		(0x2u<<9)
#define	MCE_REGCR3_BREN_B_0X0		(0x0u<<0)
#define	MCE_REGCR3_BREN_B_0X1		(0x1u<<0)

// SADDR3 Configuration

#define	MCE_SADDR3_BADDSTART		(0xFFFFFu<<12)
#define	MCE_SADDR3_BADDSTART_0		(0x1u<<12)

// EADDR3 Configuration

#define	MCE_EADDR3_BADDEND			(0xFFFFFu<<12)
#define	MCE_EADDR3_BADDEND_0		(0x1u<<12)

// REGCR4 Configuration

#define	MCE_REGCR4_ENC				(0x3u<<14)
#define	MCE_REGCR4_ENC_0			(0x1u<<14)
#define	MCE_REGCR4_CTXID			(0x3u<<9)
#define	MCE_REGCR4_CTXID_0			(0x1u<<9)
#define	MCE_REGCR4_BREN				(0x1u<<0)

#define	MCE_REGCR4_ENC_B_0X0		(0x0u<<14)
#define	MCE_REGCR4_ENC_B_0X1		(0x1u<<14)
#define	MCE_REGCR4_ENC_B_0X2		(0x2u<<14)
#define	MCE_REGCR4_ENC_B_0X3		(0x3u<<14)
#define	MCE_REGCR4_CTXID_B_0X0		(0x0u<<9)
#define	MCE_REGCR4_CTXID_B_0X1		(0x1u<<9)
#define	MCE_REGCR4_CTXID_B_0X2		(0x2u<<9)
#define	MCE_REGCR4_BREN_B_0X0		(0x0u<<0)
#define	MCE_REGCR4_BREN_B_0X1		(0x1u<<0)

// SADDR4 Configuration

#define	MCE_SADDR4_BADDSTART		(0xFFFFFu<<12)
#define	MCE_SADDR4_BADDSTART_0		(0x1u<<12)

// EADDR4 Configuration

#define	MCE_EADDR4_BADDEND			(0xFFFFFu<<12)
#define	MCE_EADDR4_BADDEND_0		(0x1u<<12)

// MKEYR0 Configuration

#define	MCE_MKEYR0_MKEY31			(0x1u<<31)
#define	MCE_MKEYR0_MKEY30			(0x1u<<30)
#define	MCE_MKEYR0_MKEY29			(0x1u<<29)
#define	MCE_MKEYR0_MKEY28			(0x1u<<28)
#define	MCE_MKEYR0_MKEY27			(0x1u<<27)
#define	MCE_MKEYR0_MKEY26			(0x1u<<26)
#define	MCE_MKEYR0_MKEY25			(0x1u<<25)
#define	MCE_MKEYR0_MKEY24			(0x1u<<24)
#define	MCE_MKEYR0_MKEY23			(0x1u<<23)
#define	MCE_MKEYR0_MKEY22			(0x1u<<22)
#define	MCE_MKEYR0_MKEY21			(0x1u<<21)
#define	MCE_MKEYR0_MKEY20			(0x1u<<20)
#define	MCE_MKEYR0_MKEY19			(0x1u<<19)
#define	MCE_MKEYR0_MKEY18			(0x1u<<18)
#define	MCE_MKEYR0_MKEY17			(0x1u<<17)
#define	MCE_MKEYR0_MKEY16			(0x1u<<16)
#define	MCE_MKEYR0_MKEY15			(0x1u<<15)
#define	MCE_MKEYR0_MKEY14			(0x1u<<14)
#define	MCE_MKEYR0_MKEY13			(0x1u<<13)
#define	MCE_MKEYR0_MKEY12			(0x1u<<12)
#define	MCE_MKEYR0_MKEY11			(0x1u<<11)
#define	MCE_MKEYR0_MKEY10			(0x1u<<10)
#define	MCE_MKEYR0_MKEY9			(0x1u<<9)
#define	MCE_MKEYR0_MKEY8			(0x1u<<8)
#define	MCE_MKEYR0_MKEY7			(0x1u<<7)
#define	MCE_MKEYR0_MKEY6			(0x1u<<6)
#define	MCE_MKEYR0_MKEY5			(0x1u<<5)
#define	MCE_MKEYR0_MKEY4			(0x1u<<4)
#define	MCE_MKEYR0_MKEY3			(0x1u<<3)
#define	MCE_MKEYR0_MKEY2			(0x1u<<2)
#define	MCE_MKEYR0_MKEY1			(0x1u<<1)
#define	MCE_MKEYR0_MKEY0			(0x1u<<0)

// MKEYR1 Configuration

#define	MCE_MKEYR1_MKEY63			(0x1u<<31)
#define	MCE_MKEYR1_MKEY62			(0x1u<<30)
#define	MCE_MKEYR1_MKEY61			(0x1u<<29)
#define	MCE_MKEYR1_MKEY60			(0x1u<<28)
#define	MCE_MKEYR1_MKEY59			(0x1u<<27)
#define	MCE_MKEYR1_MKEY58			(0x1u<<26)
#define	MCE_MKEYR1_MKEY57			(0x1u<<25)
#define	MCE_MKEYR1_MKEY56			(0x1u<<24)
#define	MCE_MKEYR1_MKEY55			(0x1u<<23)
#define	MCE_MKEYR1_MKEY54			(0x1u<<22)
#define	MCE_MKEYR1_MKEY53			(0x1u<<21)
#define	MCE_MKEYR1_MKEY52			(0x1u<<20)
#define	MCE_MKEYR1_MKEY51			(0x1u<<19)
#define	MCE_MKEYR1_MKEY50			(0x1u<<18)
#define	MCE_MKEYR1_MKEY49			(0x1u<<17)
#define	MCE_MKEYR1_MKEY48			(0x1u<<16)
#define	MCE_MKEYR1_MKEY47			(0x1u<<15)
#define	MCE_MKEYR1_MKEY46			(0x1u<<14)
#define	MCE_MKEYR1_MKEY45			(0x1u<<13)
#define	MCE_MKEYR1_MKEY44			(0x1u<<12)
#define	MCE_MKEYR1_MKEY43			(0x1u<<11)
#define	MCE_MKEYR1_MKEY42			(0x1u<<10)
#define	MCE_MKEYR1_MKEY41			(0x1u<<9)
#define	MCE_MKEYR1_MKEY40			(0x1u<<8)
#define	MCE_MKEYR1_MKEY39			(0x1u<<7)
#define	MCE_MKEYR1_MKEY38			(0x1u<<6)
#define	MCE_MKEYR1_MKEY37			(0x1u<<5)
#define	MCE_MKEYR1_MKEY36			(0x1u<<4)
#define	MCE_MKEYR1_MKEY35			(0x1u<<3)
#define	MCE_MKEYR1_MKEY34			(0x1u<<2)
#define	MCE_MKEYR1_MKEY33			(0x1u<<1)
#define	MCE_MKEYR1_MKEY32			(0x1u<<0)

// MKEYR2 Configuration

#define	MCE_MKEYR2_MKEY95			(0x1u<<31)
#define	MCE_MKEYR2_MKEY94			(0x1u<<30)
#define	MCE_MKEYR2_MKEY93			(0x1u<<29)
#define	MCE_MKEYR2_MKEY92			(0x1u<<28)
#define	MCE_MKEYR2_MKEY91			(0x1u<<27)
#define	MCE_MKEYR2_MKEY90			(0x1u<<26)
#define	MCE_MKEYR2_MKEY89			(0x1u<<25)
#define	MCE_MKEYR2_MKEY88			(0x1u<<24)
#define	MCE_MKEYR2_MKEY87			(0x1u<<23)
#define	MCE_MKEYR2_MKEY86			(0x1u<<22)
#define	MCE_MKEYR2_MKEY85			(0x1u<<21)
#define	MCE_MKEYR2_MKEY84			(0x1u<<20)
#define	MCE_MKEYR2_MKEY83			(0x1u<<19)
#define	MCE_MKEYR2_MKEY82			(0x1u<<18)
#define	MCE_MKEYR2_MKEY81			(0x1u<<17)
#define	MCE_MKEYR2_MKEY80			(0x1u<<16)
#define	MCE_MKEYR2_MKEY79			(0x1u<<15)
#define	MCE_MKEYR2_MKEY78			(0x1u<<14)
#define	MCE_MKEYR2_MKEY77			(0x1u<<13)
#define	MCE_MKEYR2_MKEY76			(0x1u<<12)
#define	MCE_MKEYR2_MKEY75			(0x1u<<11)
#define	MCE_MKEYR2_MKEY74			(0x1u<<10)
#define	MCE_MKEYR2_MKEY73			(0x1u<<9)
#define	MCE_MKEYR2_MKEY72			(0x1u<<8)
#define	MCE_MKEYR2_MKEY71			(0x1u<<7)
#define	MCE_MKEYR2_MKEY70			(0x1u<<6)
#define	MCE_MKEYR2_MKEY69			(0x1u<<5)
#define	MCE_MKEYR2_MKEY68			(0x1u<<4)
#define	MCE_MKEYR2_MKEY67			(0x1u<<3)
#define	MCE_MKEYR2_MKEY66			(0x1u<<2)
#define	MCE_MKEYR2_MKEY65			(0x1u<<1)
#define	MCE_MKEYR2_MKEY64			(0x1u<<0)

// MKEYR3 Configuration

#define	MCE_MKEYR3_MKEY127			(0x1u<<31)
#define	MCE_MKEYR3_MKEY126			(0x1u<<30)
#define	MCE_MKEYR3_MKEY125			(0x1u<<29)
#define	MCE_MKEYR3_MKEY124			(0x1u<<28)
#define	MCE_MKEYR3_MKEY123			(0x1u<<27)
#define	MCE_MKEYR3_MKEY122			(0x1u<<26)
#define	MCE_MKEYR3_MKEY121			(0x1u<<25)
#define	MCE_MKEYR3_MKEY120			(0x1u<<24)
#define	MCE_MKEYR3_MKEY119			(0x1u<<23)
#define	MCE_MKEYR3_MKEY118			(0x1u<<22)
#define	MCE_MKEYR3_MKEY117			(0x1u<<21)
#define	MCE_MKEYR3_MKEY116			(0x1u<<20)
#define	MCE_MKEYR3_MKEY115			(0x1u<<19)
#define	MCE_MKEYR3_MKEY114			(0x1u<<18)
#define	MCE_MKEYR3_MKEY113			(0x1u<<17)
#define	MCE_MKEYR3_MKEY112			(0x1u<<16)
#define	MCE_MKEYR3_MKEY111			(0x1u<<15)
#define	MCE_MKEYR3_MKEY110			(0x1u<<14)
#define	MCE_MKEYR3_MKEY109			(0x1u<<13)
#define	MCE_MKEYR3_MKEY108			(0x1u<<12)
#define	MCE_MKEYR3_MKEY107			(0x1u<<11)
#define	MCE_MKEYR3_MKEY106			(0x1u<<10)
#define	MCE_MKEYR3_MKEY105			(0x1u<<9)
#define	MCE_MKEYR3_MKEY104			(0x1u<<8)
#define	MCE_MKEYR3_MKEY103			(0x1u<<7)
#define	MCE_MKEYR3_MKEY102			(0x1u<<6)
#define	MCE_MKEYR3_MKEY101			(0x1u<<5)
#define	MCE_MKEYR3_MKEY100			(0x1u<<4)
#define	MCE_MKEYR3_MKEY99			(0x1u<<3)
#define	MCE_MKEYR3_MKEY98			(0x1u<<2)
#define	MCE_MKEYR3_MKEY97			(0x1u<<1)
#define	MCE_MKEYR3_MKEY96			(0x1u<<0)

// MKEYR4 Configuration

#define	MCE_MKEYR4_MKEY159			(0x1u<<31)
#define	MCE_MKEYR4_MKEY158			(0x1u<<30)
#define	MCE_MKEYR4_MKEY157			(0x1u<<29)
#define	MCE_MKEYR4_MKEY156			(0x1u<<28)
#define	MCE_MKEYR4_MKEY155			(0x1u<<27)
#define	MCE_MKEYR4_MKEY154			(0x1u<<26)
#define	MCE_MKEYR4_MKEY153			(0x1u<<25)
#define	MCE_MKEYR4_MKEY152			(0x1u<<24)
#define	MCE_MKEYR4_MKEY151			(0x1u<<23)
#define	MCE_MKEYR4_MKEY150			(0x1u<<22)
#define	MCE_MKEYR4_MKEY149			(0x1u<<21)
#define	MCE_MKEYR4_MKEY148			(0x1u<<20)
#define	MCE_MKEYR4_MKEY147			(0x1u<<19)
#define	MCE_MKEYR4_MKEY146			(0x1u<<18)
#define	MCE_MKEYR4_MKEY145			(0x1u<<17)
#define	MCE_MKEYR4_MKEY144			(0x1u<<16)
#define	MCE_MKEYR4_MKEY143			(0x1u<<15)
#define	MCE_MKEYR4_MKEY142			(0x1u<<14)
#define	MCE_MKEYR4_MKEY141			(0x1u<<13)
#define	MCE_MKEYR4_MKEY140			(0x1u<<12)
#define	MCE_MKEYR4_MKEY139			(0x1u<<11)
#define	MCE_MKEYR4_MKEY138			(0x1u<<10)
#define	MCE_MKEYR4_MKEY137			(0x1u<<9)
#define	MCE_MKEYR4_MKEY136			(0x1u<<8)
#define	MCE_MKEYR4_MKEY135			(0x1u<<7)
#define	MCE_MKEYR4_MKEY134			(0x1u<<6)
#define	MCE_MKEYR4_MKEY133			(0x1u<<5)
#define	MCE_MKEYR4_MKEY132			(0x1u<<4)
#define	MCE_MKEYR4_MKEY131			(0x1u<<3)
#define	MCE_MKEYR4_MKEY130			(0x1u<<2)
#define	MCE_MKEYR4_MKEY129			(0x1u<<1)
#define	MCE_MKEYR4_MKEY128			(0x1u<<0)

// MKEYR5 Configuration

#define	MCE_MKEYR5_MKEY191			(0x1u<<31)
#define	MCE_MKEYR5_MKEY190			(0x1u<<30)
#define	MCE_MKEYR5_MKEY189			(0x1u<<29)
#define	MCE_MKEYR5_MKEY188			(0x1u<<28)
#define	MCE_MKEYR5_MKEY187			(0x1u<<27)
#define	MCE_MKEYR5_MKEY186			(0x1u<<26)
#define	MCE_MKEYR5_MKEY185			(0x1u<<25)
#define	MCE_MKEYR5_MKEY184			(0x1u<<24)
#define	MCE_MKEYR5_MKEY183			(0x1u<<23)
#define	MCE_MKEYR5_MKEY182			(0x1u<<22)
#define	MCE_MKEYR5_MKEY181			(0x1u<<21)
#define	MCE_MKEYR5_MKEY180			(0x1u<<20)
#define	MCE_MKEYR5_MKEY179			(0x1u<<19)
#define	MCE_MKEYR5_MKEY178			(0x1u<<18)
#define	MCE_MKEYR5_MKEY177			(0x1u<<17)
#define	MCE_MKEYR5_MKEY176			(0x1u<<16)
#define	MCE_MKEYR5_MKEY175			(0x1u<<15)
#define	MCE_MKEYR5_MKEY174			(0x1u<<14)
#define	MCE_MKEYR5_MKEY173			(0x1u<<13)
#define	MCE_MKEYR5_MKEY172			(0x1u<<12)
#define	MCE_MKEYR5_MKEY171			(0x1u<<11)
#define	MCE_MKEYR5_MKEY170			(0x1u<<10)
#define	MCE_MKEYR5_MKEY169			(0x1u<<9)
#define	MCE_MKEYR5_MKEY168			(0x1u<<8)
#define	MCE_MKEYR5_MKEY167			(0x1u<<7)
#define	MCE_MKEYR5_MKEY166			(0x1u<<6)
#define	MCE_MKEYR5_MKEY165			(0x1u<<5)
#define	MCE_MKEYR5_MKEY164			(0x1u<<4)
#define	MCE_MKEYR5_MKEY163			(0x1u<<3)
#define	MCE_MKEYR5_MKEY162			(0x1u<<2)
#define	MCE_MKEYR5_MKEY161			(0x1u<<1)
#define	MCE_MKEYR5_MKEY160			(0x1u<<0)

// MKEYR6 Configuration

#define	MCE_MKEYR6_MKEY223			(0x1u<<31)
#define	MCE_MKEYR6_MKEY222			(0x1u<<30)
#define	MCE_MKEYR6_MKEY221			(0x1u<<29)
#define	MCE_MKEYR6_MKEY220			(0x1u<<28)
#define	MCE_MKEYR6_MKEY219			(0x1u<<27)
#define	MCE_MKEYR6_MKEY218			(0x1u<<26)
#define	MCE_MKEYR6_MKEY217			(0x1u<<25)
#define	MCE_MKEYR6_MKEY216			(0x1u<<24)
#define	MCE_MKEYR6_MKEY215			(0x1u<<23)
#define	MCE_MKEYR6_MKEY214			(0x1u<<22)
#define	MCE_MKEYR6_MKEY213			(0x1u<<21)
#define	MCE_MKEYR6_MKEY212			(0x1u<<20)
#define	MCE_MKEYR6_MKEY211			(0x1u<<19)
#define	MCE_MKEYR6_MKEY210			(0x1u<<18)
#define	MCE_MKEYR6_MKEY209			(0x1u<<17)
#define	MCE_MKEYR6_MKEY208			(0x1u<<16)
#define	MCE_MKEYR6_MKEY207			(0x1u<<15)
#define	MCE_MKEYR6_MKEY206			(0x1u<<14)
#define	MCE_MKEYR6_MKEY205			(0x1u<<13)
#define	MCE_MKEYR6_MKEY204			(0x1u<<12)
#define	MCE_MKEYR6_MKEY203			(0x1u<<11)
#define	MCE_MKEYR6_MKEY202			(0x1u<<10)
#define	MCE_MKEYR6_MKEY201			(0x1u<<9)
#define	MCE_MKEYR6_MKEY200			(0x1u<<8)
#define	MCE_MKEYR6_MKEY199			(0x1u<<7)
#define	MCE_MKEYR6_MKEY198			(0x1u<<6)
#define	MCE_MKEYR6_MKEY197			(0x1u<<5)
#define	MCE_MKEYR6_MKEY196			(0x1u<<4)
#define	MCE_MKEYR6_MKEY195			(0x1u<<3)
#define	MCE_MKEYR6_MKEY194			(0x1u<<2)
#define	MCE_MKEYR6_MKEY193			(0x1u<<1)
#define	MCE_MKEYR6_MKEY192			(0x1u<<0)

// MKEYR7 Configuration

#define	MCE_MKEYR7_MKEY255			(0x1u<<31)
#define	MCE_MKEYR7_MKEY254			(0x1u<<30)
#define	MCE_MKEYR7_MKEY253			(0x1u<<29)
#define	MCE_MKEYR7_MKEY252			(0x1u<<28)
#define	MCE_MKEYR7_MKEY251			(0x1u<<27)
#define	MCE_MKEYR7_MKEY250			(0x1u<<26)
#define	MCE_MKEYR7_MKEY249			(0x1u<<25)
#define	MCE_MKEYR7_MKEY248			(0x1u<<24)
#define	MCE_MKEYR7_MKEY247			(0x1u<<23)
#define	MCE_MKEYR7_MKEY246			(0x1u<<22)
#define	MCE_MKEYR7_MKEY245			(0x1u<<21)
#define	MCE_MKEYR7_MKEY244			(0x1u<<20)
#define	MCE_MKEYR7_MKEY243			(0x1u<<19)
#define	MCE_MKEYR7_MKEY242			(0x1u<<18)
#define	MCE_MKEYR7_MKEY241			(0x1u<<17)
#define	MCE_MKEYR7_MKEY240			(0x1u<<16)
#define	MCE_MKEYR7_MKEY239			(0x1u<<15)
#define	MCE_MKEYR7_MKEY238			(0x1u<<14)
#define	MCE_MKEYR7_MKEY237			(0x1u<<13)
#define	MCE_MKEYR7_MKEY236			(0x1u<<12)
#define	MCE_MKEYR7_MKEY235			(0x1u<<11)
#define	MCE_MKEYR7_MKEY234			(0x1u<<10)
#define	MCE_MKEYR7_MKEY233			(0x1u<<9)
#define	MCE_MKEYR7_MKEY232			(0x1u<<8)
#define	MCE_MKEYR7_MKEY231			(0x1u<<7)
#define	MCE_MKEYR7_MKEY230			(0x1u<<6)
#define	MCE_MKEYR7_MKEY229			(0x1u<<5)
#define	MCE_MKEYR7_MKEY228			(0x1u<<4)
#define	MCE_MKEYR7_MKEY227			(0x1u<<3)
#define	MCE_MKEYR7_MKEY226			(0x1u<<2)
#define	MCE_MKEYR7_MKEY225			(0x1u<<1)
#define	MCE_MKEYR7_MKEY224			(0x1u<<0)

// FMKEYR0 Configuration

#define	MCE_FMKEYR0_FMKEY31			(0x1u<<31)
#define	MCE_FMKEYR0_FMKEY30			(0x1u<<30)
#define	MCE_FMKEYR0_FMKEY29			(0x1u<<29)
#define	MCE_FMKEYR0_FMKEY28			(0x1u<<28)
#define	MCE_FMKEYR0_FMKEY27			(0x1u<<27)
#define	MCE_FMKEYR0_FMKEY26			(0x1u<<26)
#define	MCE_FMKEYR0_FMKEY25			(0x1u<<25)
#define	MCE_FMKEYR0_FMKEY24			(0x1u<<24)
#define	MCE_FMKEYR0_FMKEY23			(0x1u<<23)
#define	MCE_FMKEYR0_FMKEY22			(0x1u<<22)
#define	MCE_FMKEYR0_FMKEY21			(0x1u<<21)
#define	MCE_FMKEYR0_FMKEY20			(0x1u<<20)
#define	MCE_FMKEYR0_FMKEY19			(0x1u<<19)
#define	MCE_FMKEYR0_FMKEY18			(0x1u<<18)
#define	MCE_FMKEYR0_FMKEY17			(0x1u<<17)
#define	MCE_FMKEYR0_FMKEY16			(0x1u<<16)
#define	MCE_FMKEYR0_FMKEY15			(0x1u<<15)
#define	MCE_FMKEYR0_FMKEY14			(0x1u<<14)
#define	MCE_FMKEYR0_FMKEY13			(0x1u<<13)
#define	MCE_FMKEYR0_FMKEY12			(0x1u<<12)
#define	MCE_FMKEYR0_FMKEY11			(0x1u<<11)
#define	MCE_FMKEYR0_FMKEY10			(0x1u<<10)
#define	MCE_FMKEYR0_FMKEY9			(0x1u<<9)
#define	MCE_FMKEYR0_FMKEY8			(0x1u<<8)
#define	MCE_FMKEYR0_FMKEY7			(0x1u<<7)
#define	MCE_FMKEYR0_FMKEY6			(0x1u<<6)
#define	MCE_FMKEYR0_FMKEY5			(0x1u<<5)
#define	MCE_FMKEYR0_FMKEY4			(0x1u<<4)
#define	MCE_FMKEYR0_FMKEY3			(0x1u<<3)
#define	MCE_FMKEYR0_FMKEY2			(0x1u<<2)
#define	MCE_FMKEYR0_FMKEY1			(0x1u<<1)
#define	MCE_FMKEYR0_FMKEY0			(0x1u<<0)

// FMKEYR1 Configuration

#define	MCE_FMKEYR1_FMKEY63			(0x1u<<31)
#define	MCE_FMKEYR1_FMKEY62			(0x1u<<30)
#define	MCE_FMKEYR1_FMKEY61			(0x1u<<29)
#define	MCE_FMKEYR1_FMKEY60			(0x1u<<28)
#define	MCE_FMKEYR1_FMKEY59			(0x1u<<27)
#define	MCE_FMKEYR1_FMKEY58			(0x1u<<26)
#define	MCE_FMKEYR1_FMKEY57			(0x1u<<25)
#define	MCE_FMKEYR1_FMKEY56			(0x1u<<24)
#define	MCE_FMKEYR1_FMKEY55			(0x1u<<23)
#define	MCE_FMKEYR1_FMKEY54			(0x1u<<22)
#define	MCE_FMKEYR1_FMKEY53			(0x1u<<21)
#define	MCE_FMKEYR1_FMKEY52			(0x1u<<20)
#define	MCE_FMKEYR1_FMKEY51			(0x1u<<19)
#define	MCE_FMKEYR1_FMKEY50			(0x1u<<18)
#define	MCE_FMKEYR1_FMKEY49			(0x1u<<17)
#define	MCE_FMKEYR1_FMKEY48			(0x1u<<16)
#define	MCE_FMKEYR1_FMKEY47			(0x1u<<15)
#define	MCE_FMKEYR1_FMKEY46			(0x1u<<14)
#define	MCE_FMKEYR1_FMKEY45			(0x1u<<13)
#define	MCE_FMKEYR1_FMKEY44			(0x1u<<12)
#define	MCE_FMKEYR1_FMKEY43			(0x1u<<11)
#define	MCE_FMKEYR1_FMKEY42			(0x1u<<10)
#define	MCE_FMKEYR1_FMKEY41			(0x1u<<9)
#define	MCE_FMKEYR1_FMKEY40			(0x1u<<8)
#define	MCE_FMKEYR1_FMKEY39			(0x1u<<7)
#define	MCE_FMKEYR1_FMKEY38			(0x1u<<6)
#define	MCE_FMKEYR1_FMKEY37			(0x1u<<5)
#define	MCE_FMKEYR1_FMKEY36			(0x1u<<4)
#define	MCE_FMKEYR1_FMKEY35			(0x1u<<3)
#define	MCE_FMKEYR1_FMKEY34			(0x1u<<2)
#define	MCE_FMKEYR1_FMKEY33			(0x1u<<1)
#define	MCE_FMKEYR1_FMKEY32			(0x1u<<0)

// FMKEYR2 Configuration

#define	MCE_FMKEYR2_FMKEY95			(0x1u<<31)
#define	MCE_FMKEYR2_FMKEY94			(0x1u<<30)
#define	MCE_FMKEYR2_FMKEY93			(0x1u<<29)
#define	MCE_FMKEYR2_FMKEY92			(0x1u<<28)
#define	MCE_FMKEYR2_FMKEY91			(0x1u<<27)
#define	MCE_FMKEYR2_FMKEY90			(0x1u<<26)
#define	MCE_FMKEYR2_FMKEY89			(0x1u<<25)
#define	MCE_FMKEYR2_FMKEY88			(0x1u<<24)
#define	MCE_FMKEYR2_FMKEY87			(0x1u<<23)
#define	MCE_FMKEYR2_FMKEY86			(0x1u<<22)
#define	MCE_FMKEYR2_FMKEY85			(0x1u<<21)
#define	MCE_FMKEYR2_FMKEY84			(0x1u<<20)
#define	MCE_FMKEYR2_FMKEY83			(0x1u<<19)
#define	MCE_FMKEYR2_FMKEY82			(0x1u<<18)
#define	MCE_FMKEYR2_FMKEY81			(0x1u<<17)
#define	MCE_FMKEYR2_FMKEY80			(0x1u<<16)
#define	MCE_FMKEYR2_FMKEY79			(0x1u<<15)
#define	MCE_FMKEYR2_FMKEY78			(0x1u<<14)
#define	MCE_FMKEYR2_FMKEY77			(0x1u<<13)
#define	MCE_FMKEYR2_FMKEY76			(0x1u<<12)
#define	MCE_FMKEYR2_FMKEY75			(0x1u<<11)
#define	MCE_FMKEYR2_FMKEY74			(0x1u<<10)
#define	MCE_FMKEYR2_FMKEY73			(0x1u<<9)
#define	MCE_FMKEYR2_FMKEY72			(0x1u<<8)
#define	MCE_FMKEYR2_FMKEY71			(0x1u<<7)
#define	MCE_FMKEYR2_FMKEY70			(0x1u<<6)
#define	MCE_FMKEYR2_FMKEY69			(0x1u<<5)
#define	MCE_FMKEYR2_FMKEY68			(0x1u<<4)
#define	MCE_FMKEYR2_FMKEY67			(0x1u<<3)
#define	MCE_FMKEYR2_FMKEY66			(0x1u<<2)
#define	MCE_FMKEYR2_FMKEY65			(0x1u<<1)
#define	MCE_FMKEYR2_FMKEY64			(0x1u<<0)

// FMKEYR3 Configuration

#define	MCE_FMKEYR3_FMKEY127		(0x1u<<31)
#define	MCE_FMKEYR3_FMKEY126		(0x1u<<30)
#define	MCE_FMKEYR3_FMKEY125		(0x1u<<29)
#define	MCE_FMKEYR3_FMKEY124		(0x1u<<28)
#define	MCE_FMKEYR3_FMKEY123		(0x1u<<27)
#define	MCE_FMKEYR3_FMKEY122		(0x1u<<26)
#define	MCE_FMKEYR3_FMKEY121		(0x1u<<25)
#define	MCE_FMKEYR3_FMKEY120		(0x1u<<24)
#define	MCE_FMKEYR3_FMKEY119		(0x1u<<23)
#define	MCE_FMKEYR3_FMKEY118		(0x1u<<22)
#define	MCE_FMKEYR3_FMKEY117		(0x1u<<21)
#define	MCE_FMKEYR3_FMKEY116		(0x1u<<20)
#define	MCE_FMKEYR3_FMKEY115		(0x1u<<19)
#define	MCE_FMKEYR3_FMKEY114		(0x1u<<18)
#define	MCE_FMKEYR3_FMKEY113		(0x1u<<17)
#define	MCE_FMKEYR3_FMKEY112		(0x1u<<16)
#define	MCE_FMKEYR3_FMKEY111		(0x1u<<15)
#define	MCE_FMKEYR3_FMKEY110		(0x1u<<14)
#define	MCE_FMKEYR3_FMKEY109		(0x1u<<13)
#define	MCE_FMKEYR3_FMKEY108		(0x1u<<12)
#define	MCE_FMKEYR3_FMKEY107		(0x1u<<11)
#define	MCE_FMKEYR3_FMKEY106		(0x1u<<10)
#define	MCE_FMKEYR3_FMKEY105		(0x1u<<9)
#define	MCE_FMKEYR3_FMKEY104		(0x1u<<8)
#define	MCE_FMKEYR3_FMKEY103		(0x1u<<7)
#define	MCE_FMKEYR3_FMKEY102		(0x1u<<6)
#define	MCE_FMKEYR3_FMKEY101		(0x1u<<5)
#define	MCE_FMKEYR3_FMKEY100		(0x1u<<4)
#define	MCE_FMKEYR3_FMKEY99			(0x1u<<3)
#define	MCE_FMKEYR3_FMKEY98			(0x1u<<2)
#define	MCE_FMKEYR3_FMKEY97			(0x1u<<1)
#define	MCE_FMKEYR3_FMKEY96			(0x1u<<0)

// FMKEYR4 Configuration

#define	MCE_FMKEYR4_FMKEY159		(0x1u<<31)
#define	MCE_FMKEYR4_FMKEY158		(0x1u<<30)
#define	MCE_FMKEYR4_FMKEY157		(0x1u<<29)
#define	MCE_FMKEYR4_FMKEY156		(0x1u<<28)
#define	MCE_FMKEYR4_FMKEY155		(0x1u<<27)
#define	MCE_FMKEYR4_FMKEY154		(0x1u<<26)
#define	MCE_FMKEYR4_FMKEY153		(0x1u<<25)
#define	MCE_FMKEYR4_FMKEY152		(0x1u<<24)
#define	MCE_FMKEYR4_FMKEY151		(0x1u<<23)
#define	MCE_FMKEYR4_FMKEY150		(0x1u<<22)
#define	MCE_FMKEYR4_FMKEY149		(0x1u<<21)
#define	MCE_FMKEYR4_FMKEY148		(0x1u<<20)
#define	MCE_FMKEYR4_FMKEY147		(0x1u<<19)
#define	MCE_FMKEYR4_FMKEY146		(0x1u<<18)
#define	MCE_FMKEYR4_FMKEY145		(0x1u<<17)
#define	MCE_FMKEYR4_FMKEY144		(0x1u<<16)
#define	MCE_FMKEYR4_FMKEY143		(0x1u<<15)
#define	MCE_FMKEYR4_FMKEY142		(0x1u<<14)
#define	MCE_FMKEYR4_FMKEY141		(0x1u<<13)
#define	MCE_FMKEYR4_FMKEY140		(0x1u<<12)
#define	MCE_FMKEYR4_FMKEY139		(0x1u<<11)
#define	MCE_FMKEYR4_FMKEY138		(0x1u<<10)
#define	MCE_FMKEYR4_FMKEY137		(0x1u<<9)
#define	MCE_FMKEYR4_FMKEY136		(0x1u<<8)
#define	MCE_FMKEYR4_FMKEY135		(0x1u<<7)
#define	MCE_FMKEYR4_FMKEY134		(0x1u<<6)
#define	MCE_FMKEYR4_FMKEY133		(0x1u<<5)
#define	MCE_FMKEYR4_FMKEY132		(0x1u<<4)
#define	MCE_FMKEYR4_FMKEY131		(0x1u<<3)
#define	MCE_FMKEYR4_FMKEY130		(0x1u<<2)
#define	MCE_FMKEYR4_FMKEY129		(0x1u<<1)
#define	MCE_FMKEYR4_FMKEY128		(0x1u<<0)

// FMKEYR5 Configuration

#define	MCE_FMKEYR5_FMKEY191		(0x1u<<31)
#define	MCE_FMKEYR5_FMKEY190		(0x1u<<30)
#define	MCE_FMKEYR5_FMKEY189		(0x1u<<29)
#define	MCE_FMKEYR5_FMKEY188		(0x1u<<28)
#define	MCE_FMKEYR5_FMKEY187		(0x1u<<27)
#define	MCE_FMKEYR5_FMKEY186		(0x1u<<26)
#define	MCE_FMKEYR5_FMKEY185		(0x1u<<25)
#define	MCE_FMKEYR5_FMKEY184		(0x1u<<24)
#define	MCE_FMKEYR5_FMKEY183		(0x1u<<23)
#define	MCE_FMKEYR5_FMKEY182		(0x1u<<22)
#define	MCE_FMKEYR5_FMKEY181		(0x1u<<21)
#define	MCE_FMKEYR5_FMKEY180		(0x1u<<20)
#define	MCE_FMKEYR5_FMKEY179		(0x1u<<19)
#define	MCE_FMKEYR5_FMKEY178		(0x1u<<18)
#define	MCE_FMKEYR5_FMKEY177		(0x1u<<17)
#define	MCE_FMKEYR5_FMKEY176		(0x1u<<16)
#define	MCE_FMKEYR5_FMKEY175		(0x1u<<15)
#define	MCE_FMKEYR5_FMKEY174		(0x1u<<14)
#define	MCE_FMKEYR5_FMKEY173		(0x1u<<13)
#define	MCE_FMKEYR5_FMKEY172		(0x1u<<12)
#define	MCE_FMKEYR5_FMKEY171		(0x1u<<11)
#define	MCE_FMKEYR5_FMKEY170		(0x1u<<10)
#define	MCE_FMKEYR5_FMKEY169		(0x1u<<9)
#define	MCE_FMKEYR5_FMKEY168		(0x1u<<8)
#define	MCE_FMKEYR5_FMKEY167		(0x1u<<7)
#define	MCE_FMKEYR5_FMKEY166		(0x1u<<6)
#define	MCE_FMKEYR5_FMKEY165		(0x1u<<5)
#define	MCE_FMKEYR5_FMKEY164		(0x1u<<4)
#define	MCE_FMKEYR5_FMKEY163		(0x1u<<3)
#define	MCE_FMKEYR5_FMKEY162		(0x1u<<2)
#define	MCE_FMKEYR5_FMKEY161		(0x1u<<1)
#define	MCE_FMKEYR5_FMKEY160		(0x1u<<0)

// FMKEYR6 Configuration

#define	MCE_FMKEYR6_FMKEY223		(0x1u<<31)
#define	MCE_FMKEYR6_FMKEY222		(0x1u<<30)
#define	MCE_FMKEYR6_FMKEY221		(0x1u<<29)
#define	MCE_FMKEYR6_FMKEY220		(0x1u<<28)
#define	MCE_FMKEYR6_FMKEY219		(0x1u<<27)
#define	MCE_FMKEYR6_FMKEY218		(0x1u<<26)
#define	MCE_FMKEYR6_FMKEY217		(0x1u<<25)
#define	MCE_FMKEYR6_FMKEY216		(0x1u<<24)
#define	MCE_FMKEYR6_FMKEY215		(0x1u<<23)
#define	MCE_FMKEYR6_FMKEY214		(0x1u<<22)
#define	MCE_FMKEYR6_FMKEY213		(0x1u<<21)
#define	MCE_FMKEYR6_FMKEY212		(0x1u<<20)
#define	MCE_FMKEYR6_FMKEY211		(0x1u<<19)
#define	MCE_FMKEYR6_FMKEY210		(0x1u<<18)
#define	MCE_FMKEYR6_FMKEY209		(0x1u<<17)
#define	MCE_FMKEYR6_FMKEY208		(0x1u<<16)
#define	MCE_FMKEYR6_FMKEY207		(0x1u<<15)
#define	MCE_FMKEYR6_FMKEY206		(0x1u<<14)
#define	MCE_FMKEYR6_FMKEY205		(0x1u<<13)
#define	MCE_FMKEYR6_FMKEY204		(0x1u<<12)
#define	MCE_FMKEYR6_FMKEY203		(0x1u<<11)
#define	MCE_FMKEYR6_FMKEY202		(0x1u<<10)
#define	MCE_FMKEYR6_FMKEY201		(0x1u<<9)
#define	MCE_FMKEYR6_FMKEY200		(0x1u<<8)
#define	MCE_FMKEYR6_FMKEY199		(0x1u<<7)
#define	MCE_FMKEYR6_FMKEY198		(0x1u<<6)
#define	MCE_FMKEYR6_FMKEY197		(0x1u<<5)
#define	MCE_FMKEYR6_FMKEY196		(0x1u<<4)
#define	MCE_FMKEYR6_FMKEY195		(0x1u<<3)
#define	MCE_FMKEYR6_FMKEY194		(0x1u<<2)
#define	MCE_FMKEYR6_FMKEY193		(0x1u<<1)
#define	MCE_FMKEYR6_FMKEY192		(0x1u<<0)

// FMKEYR7 Configuration

#define	MCE_FMKEYR7_FMKEY255		(0x1u<<31)
#define	MCE_FMKEYR7_FMKEY254		(0x1u<<30)
#define	MCE_FMKEYR7_FMKEY253		(0x1u<<29)
#define	MCE_FMKEYR7_FMKEY252		(0x1u<<28)
#define	MCE_FMKEYR7_FMKEY251		(0x1u<<27)
#define	MCE_FMKEYR7_FMKEY250		(0x1u<<26)
#define	MCE_FMKEYR7_FMKEY249		(0x1u<<25)
#define	MCE_FMKEYR7_FMKEY248		(0x1u<<24)
#define	MCE_FMKEYR7_FMKEY247		(0x1u<<23)
#define	MCE_FMKEYR7_FMKEY246		(0x1u<<22)
#define	MCE_FMKEYR7_FMKEY245		(0x1u<<21)
#define	MCE_FMKEYR7_FMKEY244		(0x1u<<20)
#define	MCE_FMKEYR7_FMKEY243		(0x1u<<19)
#define	MCE_FMKEYR7_FMKEY242		(0x1u<<18)
#define	MCE_FMKEYR7_FMKEY241		(0x1u<<17)
#define	MCE_FMKEYR7_FMKEY240		(0x1u<<16)
#define	MCE_FMKEYR7_FMKEY239		(0x1u<<15)
#define	MCE_FMKEYR7_FMKEY238		(0x1u<<14)
#define	MCE_FMKEYR7_FMKEY237		(0x1u<<13)
#define	MCE_FMKEYR7_FMKEY236		(0x1u<<12)
#define	MCE_FMKEYR7_FMKEY235		(0x1u<<11)
#define	MCE_FMKEYR7_FMKEY234		(0x1u<<10)
#define	MCE_FMKEYR7_FMKEY233		(0x1u<<9)
#define	MCE_FMKEYR7_FMKEY232		(0x1u<<8)
#define	MCE_FMKEYR7_FMKEY231		(0x1u<<7)
#define	MCE_FMKEYR7_FMKEY230		(0x1u<<6)
#define	MCE_FMKEYR7_FMKEY229		(0x1u<<5)
#define	MCE_FMKEYR7_FMKEY228		(0x1u<<4)
#define	MCE_FMKEYR7_FMKEY227		(0x1u<<3)
#define	MCE_FMKEYR7_FMKEY226		(0x1u<<2)
#define	MCE_FMKEYR7_FMKEY225		(0x1u<<1)
#define	MCE_FMKEYR7_FMKEY224		(0x1u<<0)

// CC1CFGR Configuration

#define	MCE_CC1CFGR_VERSION			(0xFFFFu<<16)
#define	MCE_CC1CFGR_VERSION_0		(0x1u<<16)
#define	MCE_CC1CFGR_KEYCRC			(0xFFu<<8)
#define	MCE_CC1CFGR_KEYCRC_0		(0x1u<<8)
#define	MCE_CC1CFGR_MODE			(0x3u<<4)
#define	MCE_CC1CFGR_MODE_0			(0x1u<<4)
#define	MCE_CC1CFGR_KEYLOCK			(0x1u<<2)
#define	MCE_CC1CFGR_CCLOCK			(0x1u<<1)
#define	MCE_CC1CFGR_CCEN			(0x1u<<0)

#define	MCE_CC1CFGR_MODE_B_0X2		(0x2u<<4)
#define	MCE_CC1CFGR_MODE_B_0X3		(0x3u<<4)
#define	MCE_CC1CFGR_KEYLOCK_B_0X0	(0x0u<<2)
#define	MCE_CC1CFGR_KEYLOCK_B_0X1	(0x1u<<2)
#define	MCE_CC1CFGR_CCLOCK_B_0X0	(0x0u<<1)
#define	MCE_CC1CFGR_CCLOCK_B_0X1	(0x1u<<1)
#define	MCE_CC1CFGR_CCEN_B_0X0		(0x0u<<0)
#define	MCE_CC1CFGR_CCEN_B_0X1		(0x1u<<0)

// CC1NR0 Configuration

#define	MCE_CC1NR0_SCNONCE			(0xFFFFFFFFu<<0)
#define	MCE_CC1NR0_SCNONCE_0		(0x1u<<0)

// CC1NR1 Configuration

#define	MCE_CC1NR1_SCNONCE			(0xFFFFFFFFu<<0)
#define	MCE_CC1NR1_SCNONCE_0		(0x1u<<0)

// CC1KEYR0 Configuration

#define	MCE_CC1KEYR0_KEY			(0xFFFFFFFFu<<0)
#define	MCE_CC1KEYR0_KEY_0			(0x1u<<0)

// CC1KEYR1 Configuration

#define	MCE_CC1KEYR1_KEY			(0xFFFFFFFFu<<0)
#define	MCE_CC1KEYR1_KEY_0			(0x1u<<0)

// CC1KEYR2 Configuration

#define	MCE_CC1KEYR2_KEY			(0xFFFFFFFFu<<0)
#define	MCE_CC1KEYR2_KEY_0			(0x1u<<0)

// CC1KEYR3 Configuration

#define	MCE_CC1KEYR3_KEY			(0xFFFFFFFFu<<0)
#define	MCE_CC1KEYR3_KEY_0			(0x1u<<0)

// CC2CFGR Configuration

#define	MCE_CC2CFGR_VERSION			(0xFFFFu<<16)
#define	MCE_CC2CFGR_VERSION_0		(0x1u<<16)
#define	MCE_CC2CFGR_KEYCRC			(0xFFu<<8)
#define	MCE_CC2CFGR_KEYCRC_0		(0x1u<<8)
#define	MCE_CC2CFGR_MODE			(0x3u<<4)
#define	MCE_CC2CFGR_MODE_0			(0x1u<<4)
#define	MCE_CC2CFGR_KEYLOCK			(0x1u<<2)
#define	MCE_CC2CFGR_CCLOCK			(0x1u<<1)
#define	MCE_CC2CFGR_CCEN			(0x1u<<0)

#define	MCE_CC2CFGR_MODE_B_0X2		(0x2u<<4)
#define	MCE_CC2CFGR_MODE_B_0X3		(0x3u<<4)
#define	MCE_CC2CFGR_KEYLOCK_B_0X0	(0x0u<<2)
#define	MCE_CC2CFGR_KEYLOCK_B_0X1	(0x1u<<2)
#define	MCE_CC2CFGR_CCLOCK_B_0X0	(0x0u<<1)
#define	MCE_CC2CFGR_CCLOCK_B_0X1	(0x1u<<1)
#define	MCE_CC2CFGR_CCEN_B_0X0		(0x0u<<0)
#define	MCE_CC2CFGR_CCEN_B_0X1		(0x1u<<0)

// CC2NR0 Configuration

#define	MCE_CC2NR0_SCNONCE			(0xFFFFFFFFu<<0)
#define	MCE_CC2NR0_SCNONCE_0		(0x1u<<0)

// CC2NR1 Configuration

#define	MCE_CC2NR1_SCNONCE			(0xFFFFFFFFu<<0)
#define	MCE_CC2NR1_SCNONCE_0		(0x1u<<0)

// CC2KEYR0 Configuration

#define	MCE_CC2KEYR0_KEY			(0xFFFFFFFFu<<0)
#define	MCE_CC2KEYR0_KEY_0			(0x1u<<0)

// CC2KEYR1 Configuration

#define	MCE_CC2KEYR1_KEY			(0xFFFFFFFFu<<0)
#define	MCE_CC2KEYR1_KEY_0			(0x1u<<0)

// CC2KEYR2 Configuration

#define	MCE_CC2KEYR2_KEY			(0xFFFFFFFFu<<0)
#define	MCE_CC2KEYR2_KEY_0			(0x1u<<0)

// CC2KEYR3 Configuration

#define	MCE_CC2KEYR3_KEY			(0xFFFFFFFFu<<0)
#define	MCE_CC2KEYR3_KEY_0			(0x1u<<0)
