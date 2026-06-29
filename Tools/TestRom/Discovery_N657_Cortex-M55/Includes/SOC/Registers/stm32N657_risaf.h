/*
; stm32N657_risaf.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_risaf equates.
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

// RISAF address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	IASR;
	volatile	uint32_t	IACR;
	volatile	uint32_t	RESERVED1[4];
	volatile	uint32_t	IAESR;
	volatile	uint32_t	IADDR;
	volatile	uint32_t	RESERVED2[6];
	volatile	uint32_t	REG1_CFGR;
	volatile	uint32_t	REG1_STARTR;
	volatile	uint32_t	REG1_ENDR;
	volatile	uint32_t	REG1_CIDCFGR;
	volatile	uint32_t	REG1_ACFGR;
	volatile	uint32_t	REG1_ASTARTR;
	volatile	uint32_t	REG1_AENDR;
	volatile	uint32_t	REG1_ANESTR;
	volatile	uint32_t	REG1_BCFGR;
	volatile	uint32_t	REG1_BSTARTR;
	volatile	uint32_t	REG1_BENDR;
	volatile	uint32_t	REG1_BNESTR;
	volatile	uint32_t	RESERVED3[4];
	volatile	uint32_t	REG2_CFGR;
	volatile	uint32_t	REG2_STARTR;
	volatile	uint32_t	REG2_ENDR;
	volatile	uint32_t	REG2_CIDCFGR;
	volatile	uint32_t	REG2_ACFGR;
	volatile	uint32_t	REG2_ASTARTR;
	volatile	uint32_t	REG2_AENDR;
	volatile	uint32_t	REG2_ANESTR;
	volatile	uint32_t	REG2_BCFGR;
	volatile	uint32_t	REG2_BSTARTR;
	volatile	uint32_t	REG2_BENDR;
	volatile	uint32_t	REG2_BNESTR;
	volatile	uint32_t	RESERVED4[4];
	volatile	uint32_t	REG3_CFGR;
	volatile	uint32_t	REG3_STARTR;
	volatile	uint32_t	REG3_ENDR;
	volatile	uint32_t	REG3_CIDCFGR;
	volatile	uint32_t	REG3_ACFGR;
	volatile	uint32_t	REG3_ASTARTR;
	volatile	uint32_t	REG3_AENDR;
	volatile	uint32_t	REG3_ANESTR;
	volatile	uint32_t	REG3_BCFGR;
	volatile	uint32_t	REG3_BSTARTR;
	volatile	uint32_t	REG3_BENDR;
	volatile	uint32_t	REG3_BNESTR;
	volatile	uint32_t	RESERVED5[4];
	volatile	uint32_t	REG4_CFGR;
	volatile	uint32_t	REG4_STARTR;
	volatile	uint32_t	REG4_ENDR;
	volatile	uint32_t	REG4_CIDCFGR;
	volatile	uint32_t	REG4_ACFGR;
	volatile	uint32_t	REG4_ASTARTR;
	volatile	uint32_t	REG4_AENDR;
	volatile	uint32_t	REG4_ANESTR;
	volatile	uint32_t	REG4_BCFGR;
	volatile	uint32_t	REG4_BSTARTR;
	volatile	uint32_t	REG4_BENDR;
	volatile	uint32_t	REG4_BNESTR;
	volatile	uint32_t	RESERVED6[4];
	volatile	uint32_t	REG5_CFGR;
	volatile	uint32_t	REG5_STARTR;
	volatile	uint32_t	REG5_ENDR;
	volatile	uint32_t	REG5_CIDCFGR;
	volatile	uint32_t	REG5_ACFGR;
	volatile	uint32_t	REG5_ASTARTR;
	volatile	uint32_t	REG5_AENDR;
	volatile	uint32_t	REG5_ANESTR;
	volatile	uint32_t	REG5_BCFGR;
	volatile	uint32_t	REG5_BSTARTR;
	volatile	uint32_t	REG5_BENDR;
	volatile	uint32_t	REG5_BNESTR;
	volatile	uint32_t	RESERVED7[4];
	volatile	uint32_t	REG6_CFGR;
	volatile	uint32_t	REG6_STARTR;
	volatile	uint32_t	REG6_ENDR;
	volatile	uint32_t	REG6_CIDCFGR;
	volatile	uint32_t	REG6_ACFGR;
	volatile	uint32_t	REG6_ASTARTR;
	volatile	uint32_t	REG6_AENDR;
	volatile	uint32_t	REG6_ANESTR;
	volatile	uint32_t	REG6_BCFGR;
	volatile	uint32_t	REG6_BSTARTR;
	volatile	uint32_t	REG6_BENDR;
	volatile	uint32_t	REG6_BNESTR;
	volatile	uint32_t	RESERVED8[4];
	volatile	uint32_t	REG7_CFGR;
	volatile	uint32_t	REG7_STARTR;
	volatile	uint32_t	REG7_ENDR;
	volatile	uint32_t	REG7_CIDCFGR;
	volatile	uint32_t	REG7_ACFGR;
	volatile	uint32_t	REG7_ASTARTR;
	volatile	uint32_t	REG7_AENDR;
	volatile	uint32_t	REG7_ANESTR;
	volatile	uint32_t	REG7_BCFGR;
	volatile	uint32_t	REG7_BSTARTR;
	volatile	uint32_t	REG7_BENDR;
	volatile	uint32_t	REG7_BNESTR;
	volatile	uint32_t	RESERVED9[4];
	volatile	uint32_t	REG8_CFGR;
	volatile	uint32_t	REG8_STARTR;
	volatile	uint32_t	REG8_ENDR;
	volatile	uint32_t	REG8_CIDCFGR;
	volatile	uint32_t	REG8_ACFGR;
	volatile	uint32_t	REG8_ASTARTR;
	volatile	uint32_t	REG8_AENDR;
	volatile	uint32_t	REG8_ANESTR;
	volatile	uint32_t	REG8_BCFGR;
	volatile	uint32_t	REG8_BSTARTR;
	volatile	uint32_t	REG8_BENDR;
	volatile	uint32_t	REG8_BNESTR;
	volatile	uint32_t	RESERVED10[4];
	volatile	uint32_t	REG9_CFGR;
	volatile	uint32_t	REG9_STARTR;
	volatile	uint32_t	REG9_ENDR;
	volatile	uint32_t	REG9_CIDCFGR;
	volatile	uint32_t	REG9_ACFGR;
	volatile	uint32_t	REG9_ASTARTR;
	volatile	uint32_t	REG9_AENDR;
	volatile	uint32_t	REG9_ANESTR;
	volatile	uint32_t	REG9_BCFGR;
	volatile	uint32_t	REG9_BSTARTR;
	volatile	uint32_t	REG9_BENDR;
	volatile	uint32_t	REG9_BNESTR;
	volatile	uint32_t	RESERVED11[4];
	volatile	uint32_t	REG10_CFGR;
	volatile	uint32_t	REG10_STARTR;
	volatile	uint32_t	REG10_ENDR;
	volatile	uint32_t	REG10_CIDCFGR;
	volatile	uint32_t	REG10_ACFGR;
	volatile	uint32_t	REG10_ASTARTR;
	volatile	uint32_t	REG10_AENDR;
	volatile	uint32_t	REG10_ANESTR;
	volatile	uint32_t	REG10_BCFGR;
	volatile	uint32_t	REG10_BSTARTR;
	volatile	uint32_t	REG10_BENDR;
	volatile	uint32_t	REG10_BNESTR;
	volatile	uint32_t	RESERVED12[4];
	volatile	uint32_t	REG11_CFGR;
	volatile	uint32_t	REG11_STARTR;
	volatile	uint32_t	REG11_ENDR;
	volatile	uint32_t	REG11_CIDCFGR;
	volatile	uint32_t	REG11_ACFGR;
	volatile	uint32_t	REG11_ASTARTR;
	volatile	uint32_t	REG11_AENDR;
	volatile	uint32_t	REG11_ANESTR;
	volatile	uint32_t	REG11_BCFGR;
	volatile	uint32_t	REG11_BSTARTR;
	volatile	uint32_t	REG11_BENDR;
	volatile	uint32_t	REG11_BNESTR;
	volatile	uint32_t	RESERVED13[4];
	volatile	uint32_t	REG12_CFGR;
	volatile	uint32_t	REG12_STARTR;
	volatile	uint32_t	REG12_ENDR;
	volatile	uint32_t	REG12_CIDCFGR;
	volatile	uint32_t	REG12_ACFGR;
	volatile	uint32_t	REG12_ASTARTR;
	volatile	uint32_t	REG12_AENDR;
	volatile	uint32_t	REG12_ANESTR;
	volatile	uint32_t	REG12_BCFGR;
	volatile	uint32_t	REG12_BSTARTR;
	volatile	uint32_t	REG12_BENDR;
	volatile	uint32_t	REG12_BNESTR;
	volatile	uint32_t	RESERVED14[4];
	volatile	uint32_t	REG13_CFGR;
	volatile	uint32_t	REG13_STARTR;
	volatile	uint32_t	REG13_ENDR;
	volatile	uint32_t	REG13_CIDCFGR;
	volatile	uint32_t	REG13_ACFGR;
	volatile	uint32_t	REG13_ASTARTR;
	volatile	uint32_t	REG13_AENDR;
	volatile	uint32_t	REG13_ANESTR;
	volatile	uint32_t	REG13_BCFGR;
	volatile	uint32_t	REG13_BSTARTR;
	volatile	uint32_t	REG13_BENDR;
	volatile	uint32_t	REG13_BNESTR;
	volatile	uint32_t	RESERVED15[4];
	volatile	uint32_t	REG14_CFGR;
	volatile	uint32_t	REG14_STARTR;
	volatile	uint32_t	REG14_ENDR;
	volatile	uint32_t	REG14_CIDCFGR;
	volatile	uint32_t	REG14_ACFGR;
	volatile	uint32_t	REG14_ASTARTR;
	volatile	uint32_t	REG14_AENDR;
	volatile	uint32_t	REG14_ANESTR;
	volatile	uint32_t	REG14_BCFGR;
	volatile	uint32_t	REG14_BSTARTR;
	volatile	uint32_t	REG14_BENDR;
	volatile	uint32_t	REG14_BNESTR;
	volatile	uint32_t	RESERVED16[4];
	volatile	uint32_t	REG15_CFGR;
	volatile	uint32_t	REG15_STARTR;
	volatile	uint32_t	REG15_ENDR;
	volatile	uint32_t	REG15_CIDCFGR;
	volatile	uint32_t	REG15_ACFGR;
	volatile	uint32_t	REG15_ASTARTR;
	volatile	uint32_t	REG15_AENDR;
	volatile	uint32_t	REG15_ANESTR;
	volatile	uint32_t	REG15_BCFGR;
	volatile	uint32_t	REG15_BSTARTR;
	volatile	uint32_t	REG15_BENDR;
	volatile	uint32_t	REG15_BNESTR;
} RISAF_TypeDef;

#if (defined(__cplusplus))
#define	RISAF_NS	reinterpret_cast<RISAF_TypeDef *>(0x44026000u)
#define	RISAF_S		reinterpret_cast<RISAF_TypeDef *>(0x54026000u)

#else
#define	RISAF_NS	((RISAF_TypeDef *)0x44026000u)
#define	RISAF_S		((RISAF_TypeDef *)0x54026000u)
#endif

// CR Configuration

#define	RISAF_CR_GLOCK						(0x1u<<0)

#define	RISAF_CR_GLOCK_B_0X0				(0x0u<<0)
#define	RISAF_CR_GLOCK_B_0X1				(0x1u<<0)

// IASR Configuration

#define	RISAF_IASR_IAEF						(0x1u<<1)
#define	RISAF_IASR_CAEF						(0x1u<<0)

// IACR Configuration

#define	RISAF_IACR_IAEF						(0x1u<<1)
#define	RISAF_IACR_CAEF						(0x1u<<0)

// IAESR Configuration

#define	RISAF_IAESR_IANRW					(0x1u<<7)
#define	RISAF_IAESR_IASEC					(0x1u<<5)
#define	RISAF_IAESR_IAPRIV					(0x1u<<4)
#define	RISAF_IAESR_IACID					(0x7u<<0)
#define	RISAF_IAESR_IACID_0					(0x1u<<0)

#define	RISAF_IAESR_IANRW_B_0X0				(0x0u<<7)
#define	RISAF_IAESR_IANRW_B_0X1				(0x1u<<7)
#define	RISAF_IAESR_IASEC_B_0X0				(0x0u<<5)
#define	RISAF_IAESR_IASEC_B_0X1				(0x1u<<5)
#define	RISAF_IAESR_IAPRIV_B_0X0			(0x0u<<4)
#define	RISAF_IAESR_IAPRIV_B_0X1			(0x1u<<4)

// IADDR Configuration

#define	RISAF_IADDR_IADD					(0xFFFFFFFFu<<0)
#define	RISAF_IADDR_IADD_0					(0x1u<<0)

// REG1_CFGR Configuration

#define	RISAF_REG1_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG1_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG1_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG1_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG1_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG1_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG1_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG1_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG1_CFGR_SEC					(0x1u<<8)
#define	RISAF_REG1_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG1_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG1_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG1_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG1_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG1_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG1_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG1_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG1_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG1_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG1_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG1_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG1_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG1_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG1_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG1_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG1_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG1_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG1_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG1_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG1_CFGR_BREN_B_0X1			(0x1u<<0)

// REG1_STARTR Configuration

#define	RISAF_REG1_STARTR_BADDSTART			(0xFFFFFFFFu<<0)
#define	RISAF_REG1_STARTR_BADDSTART_0		(0x1u<<0)

// REG1_ENDR Configuration

#define	RISAF_REG1_ENDR_BADDEND				(0xFFFFFFFFu<<0)
#define	RISAF_REG1_ENDR_BADDEND_0			(0x1u<<0)

// REG1_CIDCFGR Configuration

#define	RISAF_REG1_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG1_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG1_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG1_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG1_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG1_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG1_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG1_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG1_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG1_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG1_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG1_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG1_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG1_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG1_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG1_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG1_CIDCFGR_WRENC7_B_0X0		(0x0u<<23)
#define	RISAF_REG1_CIDCFGR_WRENC7_B_0X1		(0x1u<<23)
#define	RISAF_REG1_CIDCFGR_WRENC6_B_0X0		(0x0u<<22)
#define	RISAF_REG1_CIDCFGR_WRENC6_B_0X1		(0x1u<<22)
#define	RISAF_REG1_CIDCFGR_WRENC5_B_0X0		(0x0u<<21)
#define	RISAF_REG1_CIDCFGR_WRENC5_B_0X1		(0x1u<<21)
#define	RISAF_REG1_CIDCFGR_WRENC4_B_0X0		(0x0u<<20)
#define	RISAF_REG1_CIDCFGR_WRENC4_B_0X1		(0x1u<<20)
#define	RISAF_REG1_CIDCFGR_WRENC3_B_0X0		(0x0u<<19)
#define	RISAF_REG1_CIDCFGR_WRENC3_B_0X1		(0x1u<<19)
#define	RISAF_REG1_CIDCFGR_WRENC2_B_0X0		(0x0u<<18)
#define	RISAF_REG1_CIDCFGR_WRENC2_B_0X1		(0x1u<<18)
#define	RISAF_REG1_CIDCFGR_WRENC1_B_0X0		(0x0u<<17)
#define	RISAF_REG1_CIDCFGR_WRENC1_B_0X1		(0x1u<<17)
#define	RISAF_REG1_CIDCFGR_WRENC0_B_0X0		(0x0u<<16)
#define	RISAF_REG1_CIDCFGR_WRENC0_B_0X1		(0x1u<<16)
#define	RISAF_REG1_CIDCFGR_RDENC7_B_0X0		(0x0u<<7)
#define	RISAF_REG1_CIDCFGR_RDENC7_B_0X1		(0x1u<<7)
#define	RISAF_REG1_CIDCFGR_RDENC6_B_0X0		(0x0u<<6)
#define	RISAF_REG1_CIDCFGR_RDENC6_B_0X1		(0x1u<<6)
#define	RISAF_REG1_CIDCFGR_RDENC5_B_0X0		(0x0u<<5)
#define	RISAF_REG1_CIDCFGR_RDENC5_B_0X1		(0x1u<<5)
#define	RISAF_REG1_CIDCFGR_RDENC4_B_0X0		(0x0u<<4)
#define	RISAF_REG1_CIDCFGR_RDENC4_B_0X1		(0x1u<<4)
#define	RISAF_REG1_CIDCFGR_RDENC3_B_0X0		(0x0u<<3)
#define	RISAF_REG1_CIDCFGR_RDENC3_B_0X1		(0x1u<<3)
#define	RISAF_REG1_CIDCFGR_RDENC2_B_0X0		(0x0u<<2)
#define	RISAF_REG1_CIDCFGR_RDENC2_B_0X1		(0x1u<<2)
#define	RISAF_REG1_CIDCFGR_RDENC1_B_0X0		(0x0u<<1)
#define	RISAF_REG1_CIDCFGR_RDENC1_B_0X1		(0x1u<<1)
#define	RISAF_REG1_CIDCFGR_RDENC0_B_0X0		(0x0u<<0)
#define	RISAF_REG1_CIDCFGR_RDENC0_B_0X1		(0x1u<<0)

// REG1_ACFGR Configuration

#define	RISAF_REG1_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG1_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG1_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG1_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG1_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG1_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG1_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG1_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG1_ACFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG1_ACFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG1_ACFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG1_ACFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG1_ACFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG1_ACFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG1_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG1_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG1_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG1_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG1_ACFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG1_ACFGR_SREN_B_0X1			(0x1u<<0)

// REG1_ASTARTR Configuration

#define	RISAF_REG1_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG1_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG1_AENDR Configuration

#define	RISAF_REG1_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG1_AENDR_SADDEND_0			(0x1u<<0)

// REG1_ANESTR Configuration

#define	RISAF_REG1_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG1_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG1_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG1_BCFGR Configuration

#define	RISAF_REG1_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG1_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG1_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG1_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG1_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG1_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG1_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG1_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG1_BCFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG1_BCFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG1_BCFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG1_BCFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG1_BCFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG1_BCFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG1_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG1_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG1_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG1_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG1_BCFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG1_BCFGR_SREN_B_0X1			(0x1u<<0)

// REG1_BSTARTR Configuration

#define	RISAF_REG1_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG1_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG1_BENDR Configuration

#define	RISAF_REG1_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG1_BENDR_SADDEND_0			(0x1u<<0)

// REG1_BNESTR Configuration

#define	RISAF_REG1_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG1_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG1_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG2_CFGR Configuration

#define	RISAF_REG2_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG2_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG2_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG2_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG2_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG2_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG2_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG2_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG2_CFGR_SEC					(0x1u<<8)
#define	RISAF_REG2_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG2_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG2_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG2_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG2_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG2_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG2_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG2_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG2_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG2_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG2_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG2_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG2_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG2_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG2_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG2_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG2_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG2_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG2_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG2_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG2_CFGR_BREN_B_0X1			(0x1u<<0)

// REG2_STARTR Configuration

#define	RISAF_REG2_STARTR_BADDSTART			(0xFFFFFFFFu<<0)
#define	RISAF_REG2_STARTR_BADDSTART_0		(0x1u<<0)

// REG2_ENDR Configuration

#define	RISAF_REG2_ENDR_BADDEND				(0xFFFFFFFFu<<0)
#define	RISAF_REG2_ENDR_BADDEND_0			(0x1u<<0)

// REG2_CIDCFGR Configuration

#define	RISAF_REG2_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG2_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG2_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG2_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG2_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG2_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG2_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG2_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG2_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG2_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG2_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG2_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG2_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG2_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG2_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG2_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG2_CIDCFGR_WRENC7_B_0X0		(0x0u<<23)
#define	RISAF_REG2_CIDCFGR_WRENC7_B_0X1		(0x1u<<23)
#define	RISAF_REG2_CIDCFGR_WRENC6_B_0X0		(0x0u<<22)
#define	RISAF_REG2_CIDCFGR_WRENC6_B_0X1		(0x1u<<22)
#define	RISAF_REG2_CIDCFGR_WRENC5_B_0X0		(0x0u<<21)
#define	RISAF_REG2_CIDCFGR_WRENC5_B_0X1		(0x1u<<21)
#define	RISAF_REG2_CIDCFGR_WRENC4_B_0X0		(0x0u<<20)
#define	RISAF_REG2_CIDCFGR_WRENC4_B_0X1		(0x1u<<20)
#define	RISAF_REG2_CIDCFGR_WRENC3_B_0X0		(0x0u<<19)
#define	RISAF_REG2_CIDCFGR_WRENC3_B_0X1		(0x1u<<19)
#define	RISAF_REG2_CIDCFGR_WRENC2_B_0X0		(0x0u<<18)
#define	RISAF_REG2_CIDCFGR_WRENC2_B_0X1		(0x1u<<18)
#define	RISAF_REG2_CIDCFGR_WRENC1_B_0X0		(0x0u<<17)
#define	RISAF_REG2_CIDCFGR_WRENC1_B_0X1		(0x1u<<17)
#define	RISAF_REG2_CIDCFGR_WRENC0_B_0X0		(0x0u<<16)
#define	RISAF_REG2_CIDCFGR_WRENC0_B_0X1		(0x1u<<16)
#define	RISAF_REG2_CIDCFGR_RDENC7_B_0X0		(0x0u<<7)
#define	RISAF_REG2_CIDCFGR_RDENC7_B_0X1		(0x1u<<7)
#define	RISAF_REG2_CIDCFGR_RDENC6_B_0X0		(0x0u<<6)
#define	RISAF_REG2_CIDCFGR_RDENC6_B_0X1		(0x1u<<6)
#define	RISAF_REG2_CIDCFGR_RDENC5_B_0X0		(0x0u<<5)
#define	RISAF_REG2_CIDCFGR_RDENC5_B_0X1		(0x1u<<5)
#define	RISAF_REG2_CIDCFGR_RDENC4_B_0X0		(0x0u<<4)
#define	RISAF_REG2_CIDCFGR_RDENC4_B_0X1		(0x1u<<4)
#define	RISAF_REG2_CIDCFGR_RDENC3_B_0X0		(0x0u<<3)
#define	RISAF_REG2_CIDCFGR_RDENC3_B_0X1		(0x1u<<3)
#define	RISAF_REG2_CIDCFGR_RDENC2_B_0X0		(0x0u<<2)
#define	RISAF_REG2_CIDCFGR_RDENC2_B_0X1		(0x1u<<2)
#define	RISAF_REG2_CIDCFGR_RDENC1_B_0X0		(0x0u<<1)
#define	RISAF_REG2_CIDCFGR_RDENC1_B_0X1		(0x1u<<1)
#define	RISAF_REG2_CIDCFGR_RDENC0_B_0X0		(0x0u<<0)
#define	RISAF_REG2_CIDCFGR_RDENC0_B_0X1		(0x1u<<0)

// REG2_ACFGR Configuration

#define	RISAF_REG2_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG2_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG2_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG2_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG2_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG2_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG2_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG2_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG2_ACFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG2_ACFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG2_ACFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG2_ACFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG2_ACFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG2_ACFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG2_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG2_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG2_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG2_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG2_ACFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG2_ACFGR_SREN_B_0X1			(0x1u<<0)

// REG2_ASTARTR Configuration

#define	RISAF_REG2_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG2_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG2_AENDR Configuration

#define	RISAF_REG2_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG2_AENDR_SADDEND_0			(0x1u<<0)

// REG2_ANESTR Configuration

#define	RISAF_REG2_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG2_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG2_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG2_BCFGR Configuration

#define	RISAF_REG2_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG2_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG2_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG2_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG2_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG2_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG2_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG2_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG2_BCFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG2_BCFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG2_BCFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG2_BCFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG2_BCFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG2_BCFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG2_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG2_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG2_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG2_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG2_BCFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG2_BCFGR_SREN_B_0X1			(0x1u<<0)

// REG2_BSTARTR Configuration

#define	RISAF_REG2_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG2_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG2_BENDR Configuration

#define	RISAF_REG2_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG2_BENDR_SADDEND_0			(0x1u<<0)

// REG2_BNESTR Configuration

#define	RISAF_REG2_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG2_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG2_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG3_CFGR Configuration

#define	RISAF_REG3_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG3_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG3_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG3_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG3_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG3_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG3_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG3_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG3_CFGR_SEC					(0x1u<<8)
#define	RISAF_REG3_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG3_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG3_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG3_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG3_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG3_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG3_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG3_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG3_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG3_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG3_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG3_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG3_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG3_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG3_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG3_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG3_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG3_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG3_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG3_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG3_CFGR_BREN_B_0X1			(0x1u<<0)

// REG3_STARTR Configuration

#define	RISAF_REG3_STARTR_BADDSTART			(0xFFFFFFFFu<<0)
#define	RISAF_REG3_STARTR_BADDSTART_0		(0x1u<<0)

// REG3_ENDR Configuration

#define	RISAF_REG3_ENDR_BADDEND				(0xFFFFFFFFu<<0)
#define	RISAF_REG3_ENDR_BADDEND_0			(0x1u<<0)

// REG3_CIDCFGR Configuration

#define	RISAF_REG3_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG3_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG3_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG3_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG3_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG3_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG3_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG3_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG3_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG3_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG3_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG3_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG3_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG3_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG3_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG3_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG3_CIDCFGR_WRENC7_B_0X0		(0x0u<<23)
#define	RISAF_REG3_CIDCFGR_WRENC7_B_0X1		(0x1u<<23)
#define	RISAF_REG3_CIDCFGR_WRENC6_B_0X0		(0x0u<<22)
#define	RISAF_REG3_CIDCFGR_WRENC6_B_0X1		(0x1u<<22)
#define	RISAF_REG3_CIDCFGR_WRENC5_B_0X0		(0x0u<<21)
#define	RISAF_REG3_CIDCFGR_WRENC5_B_0X1		(0x1u<<21)
#define	RISAF_REG3_CIDCFGR_WRENC4_B_0X0		(0x0u<<20)
#define	RISAF_REG3_CIDCFGR_WRENC4_B_0X1		(0x1u<<20)
#define	RISAF_REG3_CIDCFGR_WRENC3_B_0X0		(0x0u<<19)
#define	RISAF_REG3_CIDCFGR_WRENC3_B_0X1		(0x1u<<19)
#define	RISAF_REG3_CIDCFGR_WRENC2_B_0X0		(0x0u<<18)
#define	RISAF_REG3_CIDCFGR_WRENC2_B_0X1		(0x1u<<18)
#define	RISAF_REG3_CIDCFGR_WRENC1_B_0X0		(0x0u<<17)
#define	RISAF_REG3_CIDCFGR_WRENC1_B_0X1		(0x1u<<17)
#define	RISAF_REG3_CIDCFGR_WRENC0_B_0X0		(0x0u<<16)
#define	RISAF_REG3_CIDCFGR_WRENC0_B_0X1		(0x1u<<16)
#define	RISAF_REG3_CIDCFGR_RDENC7_B_0X0		(0x0u<<7)
#define	RISAF_REG3_CIDCFGR_RDENC7_B_0X1		(0x1u<<7)
#define	RISAF_REG3_CIDCFGR_RDENC6_B_0X0		(0x0u<<6)
#define	RISAF_REG3_CIDCFGR_RDENC6_B_0X1		(0x1u<<6)
#define	RISAF_REG3_CIDCFGR_RDENC5_B_0X0		(0x0u<<5)
#define	RISAF_REG3_CIDCFGR_RDENC5_B_0X1		(0x1u<<5)
#define	RISAF_REG3_CIDCFGR_RDENC4_B_0X0		(0x0u<<4)
#define	RISAF_REG3_CIDCFGR_RDENC4_B_0X1		(0x1u<<4)
#define	RISAF_REG3_CIDCFGR_RDENC3_B_0X0		(0x0u<<3)
#define	RISAF_REG3_CIDCFGR_RDENC3_B_0X1		(0x1u<<3)
#define	RISAF_REG3_CIDCFGR_RDENC2_B_0X0		(0x0u<<2)
#define	RISAF_REG3_CIDCFGR_RDENC2_B_0X1		(0x1u<<2)
#define	RISAF_REG3_CIDCFGR_RDENC1_B_0X0		(0x0u<<1)
#define	RISAF_REG3_CIDCFGR_RDENC1_B_0X1		(0x1u<<1)
#define	RISAF_REG3_CIDCFGR_RDENC0_B_0X0		(0x0u<<0)
#define	RISAF_REG3_CIDCFGR_RDENC0_B_0X1		(0x1u<<0)

// REG3_ACFGR Configuration

#define	RISAF_REG3_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG3_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG3_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG3_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG3_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG3_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG3_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG3_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG3_ACFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG3_ACFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG3_ACFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG3_ACFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG3_ACFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG3_ACFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG3_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG3_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG3_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG3_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG3_ACFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG3_ACFGR_SREN_B_0X1			(0x1u<<0)

// REG3_ASTARTR Configuration

#define	RISAF_REG3_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG3_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG3_AENDR Configuration

#define	RISAF_REG3_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG3_AENDR_SADDEND_0			(0x1u<<0)

// REG3_ANESTR Configuration

#define	RISAF_REG3_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG3_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG3_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG3_BCFGR Configuration

#define	RISAF_REG3_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG3_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG3_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG3_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG3_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG3_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG3_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG3_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG3_BCFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG3_BCFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG3_BCFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG3_BCFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG3_BCFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG3_BCFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG3_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG3_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG3_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG3_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG3_BCFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG3_BCFGR_SREN_B_0X1			(0x1u<<0)

// REG3_BSTARTR Configuration

#define	RISAF_REG3_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG3_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG3_BENDR Configuration

#define	RISAF_REG3_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG3_BENDR_SADDEND_0			(0x1u<<0)

// REG3_BNESTR Configuration

#define	RISAF_REG3_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG3_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG3_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG4_CFGR Configuration

#define	RISAF_REG4_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG4_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG4_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG4_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG4_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG4_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG4_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG4_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG4_CFGR_SEC					(0x1u<<8)
#define	RISAF_REG4_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG4_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG4_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG4_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG4_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG4_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG4_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG4_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG4_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG4_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG4_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG4_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG4_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG4_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG4_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG4_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG4_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG4_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG4_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG4_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG4_CFGR_BREN_B_0X1			(0x1u<<0)

// REG4_STARTR Configuration

#define	RISAF_REG4_STARTR_BADDSTART			(0xFFFFFFFFu<<0)
#define	RISAF_REG4_STARTR_BADDSTART_0		(0x1u<<0)

// REG4_ENDR Configuration

#define	RISAF_REG4_ENDR_BADDEND				(0xFFFFFFFFu<<0)
#define	RISAF_REG4_ENDR_BADDEND_0			(0x1u<<0)

// REG4_CIDCFGR Configuration

#define	RISAF_REG4_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG4_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG4_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG4_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG4_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG4_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG4_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG4_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG4_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG4_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG4_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG4_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG4_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG4_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG4_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG4_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG4_CIDCFGR_WRENC7_B_0X0		(0x0u<<23)
#define	RISAF_REG4_CIDCFGR_WRENC7_B_0X1		(0x1u<<23)
#define	RISAF_REG4_CIDCFGR_WRENC6_B_0X0		(0x0u<<22)
#define	RISAF_REG4_CIDCFGR_WRENC6_B_0X1		(0x1u<<22)
#define	RISAF_REG4_CIDCFGR_WRENC5_B_0X0		(0x0u<<21)
#define	RISAF_REG4_CIDCFGR_WRENC5_B_0X1		(0x1u<<21)
#define	RISAF_REG4_CIDCFGR_WRENC4_B_0X0		(0x0u<<20)
#define	RISAF_REG4_CIDCFGR_WRENC4_B_0X1		(0x1u<<20)
#define	RISAF_REG4_CIDCFGR_WRENC3_B_0X0		(0x0u<<19)
#define	RISAF_REG4_CIDCFGR_WRENC3_B_0X1		(0x1u<<19)
#define	RISAF_REG4_CIDCFGR_WRENC2_B_0X0		(0x0u<<18)
#define	RISAF_REG4_CIDCFGR_WRENC2_B_0X1		(0x1u<<18)
#define	RISAF_REG4_CIDCFGR_WRENC1_B_0X0		(0x0u<<17)
#define	RISAF_REG4_CIDCFGR_WRENC1_B_0X1		(0x1u<<17)
#define	RISAF_REG4_CIDCFGR_WRENC0_B_0X0		(0x0u<<16)
#define	RISAF_REG4_CIDCFGR_WRENC0_B_0X1		(0x1u<<16)
#define	RISAF_REG4_CIDCFGR_RDENC7_B_0X0		(0x0u<<7)
#define	RISAF_REG4_CIDCFGR_RDENC7_B_0X1		(0x1u<<7)
#define	RISAF_REG4_CIDCFGR_RDENC6_B_0X0		(0x0u<<6)
#define	RISAF_REG4_CIDCFGR_RDENC6_B_0X1		(0x1u<<6)
#define	RISAF_REG4_CIDCFGR_RDENC5_B_0X0		(0x0u<<5)
#define	RISAF_REG4_CIDCFGR_RDENC5_B_0X1		(0x1u<<5)
#define	RISAF_REG4_CIDCFGR_RDENC4_B_0X0		(0x0u<<4)
#define	RISAF_REG4_CIDCFGR_RDENC4_B_0X1		(0x1u<<4)
#define	RISAF_REG4_CIDCFGR_RDENC3_B_0X0		(0x0u<<3)
#define	RISAF_REG4_CIDCFGR_RDENC3_B_0X1		(0x1u<<3)
#define	RISAF_REG4_CIDCFGR_RDENC2_B_0X0		(0x0u<<2)
#define	RISAF_REG4_CIDCFGR_RDENC2_B_0X1		(0x1u<<2)
#define	RISAF_REG4_CIDCFGR_RDENC1_B_0X0		(0x0u<<1)
#define	RISAF_REG4_CIDCFGR_RDENC1_B_0X1		(0x1u<<1)
#define	RISAF_REG4_CIDCFGR_RDENC0_B_0X0		(0x0u<<0)
#define	RISAF_REG4_CIDCFGR_RDENC0_B_0X1		(0x1u<<0)

// REG4_ACFGR Configuration

#define	RISAF_REG4_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG4_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG4_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG4_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG4_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG4_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG4_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG4_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG4_ACFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG4_ACFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG4_ACFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG4_ACFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG4_ACFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG4_ACFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG4_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG4_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG4_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG4_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG4_ACFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG4_ACFGR_SREN_B_0X1			(0x1u<<0)

// REG4_ASTARTR Configuration

#define	RISAF_REG4_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG4_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG4_AENDR Configuration

#define	RISAF_REG4_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG4_AENDR_SADDEND_0			(0x1u<<0)

// REG4_ANESTR Configuration

#define	RISAF_REG4_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG4_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG4_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG4_BCFGR Configuration

#define	RISAF_REG4_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG4_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG4_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG4_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG4_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG4_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG4_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG4_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG4_BCFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG4_BCFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG4_BCFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG4_BCFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG4_BCFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG4_BCFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG4_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG4_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG4_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG4_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG4_BCFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG4_BCFGR_SREN_B_0X1			(0x1u<<0)

// REG4_BSTARTR Configuration

#define	RISAF_REG4_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG4_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG4_BENDR Configuration

#define	RISAF_REG4_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG4_BENDR_SADDEND_0			(0x1u<<0)

// REG4_BNESTR Configuration

#define	RISAF_REG4_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG4_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG4_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG5_CFGR Configuration

#define	RISAF_REG5_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG5_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG5_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG5_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG5_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG5_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG5_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG5_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG5_CFGR_SEC					(0x1u<<8)
#define	RISAF_REG5_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG5_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG5_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG5_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG5_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG5_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG5_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG5_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG5_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG5_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG5_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG5_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG5_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG5_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG5_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG5_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG5_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG5_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG5_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG5_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG5_CFGR_BREN_B_0X1			(0x1u<<0)

// REG5_STARTR Configuration

#define	RISAF_REG5_STARTR_BADDSTART			(0xFFFFFFFFu<<0)
#define	RISAF_REG5_STARTR_BADDSTART_0		(0x1u<<0)

// REG5_ENDR Configuration

#define	RISAF_REG5_ENDR_BADDEND				(0xFFFFFFFFu<<0)
#define	RISAF_REG5_ENDR_BADDEND_0			(0x1u<<0)

// REG5_CIDCFGR Configuration

#define	RISAF_REG5_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG5_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG5_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG5_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG5_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG5_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG5_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG5_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG5_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG5_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG5_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG5_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG5_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG5_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG5_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG5_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG5_CIDCFGR_WRENC7_B_0X0		(0x0u<<23)
#define	RISAF_REG5_CIDCFGR_WRENC7_B_0X1		(0x1u<<23)
#define	RISAF_REG5_CIDCFGR_WRENC6_B_0X0		(0x0u<<22)
#define	RISAF_REG5_CIDCFGR_WRENC6_B_0X1		(0x1u<<22)
#define	RISAF_REG5_CIDCFGR_WRENC5_B_0X0		(0x0u<<21)
#define	RISAF_REG5_CIDCFGR_WRENC5_B_0X1		(0x1u<<21)
#define	RISAF_REG5_CIDCFGR_WRENC4_B_0X0		(0x0u<<20)
#define	RISAF_REG5_CIDCFGR_WRENC4_B_0X1		(0x1u<<20)
#define	RISAF_REG5_CIDCFGR_WRENC3_B_0X0		(0x0u<<19)
#define	RISAF_REG5_CIDCFGR_WRENC3_B_0X1		(0x1u<<19)
#define	RISAF_REG5_CIDCFGR_WRENC2_B_0X0		(0x0u<<18)
#define	RISAF_REG5_CIDCFGR_WRENC2_B_0X1		(0x1u<<18)
#define	RISAF_REG5_CIDCFGR_WRENC1_B_0X0		(0x0u<<17)
#define	RISAF_REG5_CIDCFGR_WRENC1_B_0X1		(0x1u<<17)
#define	RISAF_REG5_CIDCFGR_WRENC0_B_0X0		(0x0u<<16)
#define	RISAF_REG5_CIDCFGR_WRENC0_B_0X1		(0x1u<<16)
#define	RISAF_REG5_CIDCFGR_RDENC7_B_0X0		(0x0u<<7)
#define	RISAF_REG5_CIDCFGR_RDENC7_B_0X1		(0x1u<<7)
#define	RISAF_REG5_CIDCFGR_RDENC6_B_0X0		(0x0u<<6)
#define	RISAF_REG5_CIDCFGR_RDENC6_B_0X1		(0x1u<<6)
#define	RISAF_REG5_CIDCFGR_RDENC5_B_0X0		(0x0u<<5)
#define	RISAF_REG5_CIDCFGR_RDENC5_B_0X1		(0x1u<<5)
#define	RISAF_REG5_CIDCFGR_RDENC4_B_0X0		(0x0u<<4)
#define	RISAF_REG5_CIDCFGR_RDENC4_B_0X1		(0x1u<<4)
#define	RISAF_REG5_CIDCFGR_RDENC3_B_0X0		(0x0u<<3)
#define	RISAF_REG5_CIDCFGR_RDENC3_B_0X1		(0x1u<<3)
#define	RISAF_REG5_CIDCFGR_RDENC2_B_0X0		(0x0u<<2)
#define	RISAF_REG5_CIDCFGR_RDENC2_B_0X1		(0x1u<<2)
#define	RISAF_REG5_CIDCFGR_RDENC1_B_0X0		(0x0u<<1)
#define	RISAF_REG5_CIDCFGR_RDENC1_B_0X1		(0x1u<<1)
#define	RISAF_REG5_CIDCFGR_RDENC0_B_0X0		(0x0u<<0)
#define	RISAF_REG5_CIDCFGR_RDENC0_B_0X1		(0x1u<<0)

// REG5_ACFGR Configuration

#define	RISAF_REG5_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG5_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG5_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG5_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG5_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG5_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG5_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG5_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG5_ACFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG5_ACFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG5_ACFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG5_ACFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG5_ACFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG5_ACFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG5_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG5_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG5_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG5_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG5_ACFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG5_ACFGR_SREN_B_0X1			(0x1u<<0)

// REG5_ASTARTR Configuration

#define	RISAF_REG5_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG5_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG5_AENDR Configuration

#define	RISAF_REG5_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG5_AENDR_SADDEND_0			(0x1u<<0)

// REG5_ANESTR Configuration

#define	RISAF_REG5_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG5_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG5_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG5_BCFGR Configuration

#define	RISAF_REG5_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG5_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG5_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG5_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG5_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG5_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG5_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG5_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG5_BCFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG5_BCFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG5_BCFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG5_BCFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG5_BCFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG5_BCFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG5_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG5_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG5_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG5_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG5_BCFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG5_BCFGR_SREN_B_0X1			(0x1u<<0)

// REG5_BSTARTR Configuration

#define	RISAF_REG5_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG5_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG5_BENDR Configuration

#define	RISAF_REG5_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG5_BENDR_SADDEND_0			(0x1u<<0)

// REG5_BNESTR Configuration

#define	RISAF_REG5_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG5_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG5_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG6_CFGR Configuration

#define	RISAF_REG6_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG6_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG6_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG6_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG6_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG6_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG6_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG6_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG6_CFGR_SEC					(0x1u<<8)
#define	RISAF_REG6_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG6_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG6_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG6_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG6_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG6_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG6_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG6_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG6_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG6_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG6_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG6_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG6_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG6_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG6_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG6_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG6_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG6_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG6_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG6_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG6_CFGR_BREN_B_0X1			(0x1u<<0)

// REG6_STARTR Configuration

#define	RISAF_REG6_STARTR_BADDSTART			(0xFFFFFFFFu<<0)
#define	RISAF_REG6_STARTR_BADDSTART_0		(0x1u<<0)

// REG6_ENDR Configuration

#define	RISAF_REG6_ENDR_BADDEND				(0xFFFFFFFFu<<0)
#define	RISAF_REG6_ENDR_BADDEND_0			(0x1u<<0)

// REG6_CIDCFGR Configuration

#define	RISAF_REG6_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG6_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG6_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG6_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG6_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG6_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG6_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG6_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG6_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG6_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG6_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG6_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG6_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG6_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG6_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG6_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG6_CIDCFGR_WRENC7_B_0X0		(0x0u<<23)
#define	RISAF_REG6_CIDCFGR_WRENC7_B_0X1		(0x1u<<23)
#define	RISAF_REG6_CIDCFGR_WRENC6_B_0X0		(0x0u<<22)
#define	RISAF_REG6_CIDCFGR_WRENC6_B_0X1		(0x1u<<22)
#define	RISAF_REG6_CIDCFGR_WRENC5_B_0X0		(0x0u<<21)
#define	RISAF_REG6_CIDCFGR_WRENC5_B_0X1		(0x1u<<21)
#define	RISAF_REG6_CIDCFGR_WRENC4_B_0X0		(0x0u<<20)
#define	RISAF_REG6_CIDCFGR_WRENC4_B_0X1		(0x1u<<20)
#define	RISAF_REG6_CIDCFGR_WRENC3_B_0X0		(0x0u<<19)
#define	RISAF_REG6_CIDCFGR_WRENC3_B_0X1		(0x1u<<19)
#define	RISAF_REG6_CIDCFGR_WRENC2_B_0X0		(0x0u<<18)
#define	RISAF_REG6_CIDCFGR_WRENC2_B_0X1		(0x1u<<18)
#define	RISAF_REG6_CIDCFGR_WRENC1_B_0X0		(0x0u<<17)
#define	RISAF_REG6_CIDCFGR_WRENC1_B_0X1		(0x1u<<17)
#define	RISAF_REG6_CIDCFGR_WRENC0_B_0X0		(0x0u<<16)
#define	RISAF_REG6_CIDCFGR_WRENC0_B_0X1		(0x1u<<16)
#define	RISAF_REG6_CIDCFGR_RDENC7_B_0X0		(0x0u<<7)
#define	RISAF_REG6_CIDCFGR_RDENC7_B_0X1		(0x1u<<7)
#define	RISAF_REG6_CIDCFGR_RDENC6_B_0X0		(0x0u<<6)
#define	RISAF_REG6_CIDCFGR_RDENC6_B_0X1		(0x1u<<6)
#define	RISAF_REG6_CIDCFGR_RDENC5_B_0X0		(0x0u<<5)
#define	RISAF_REG6_CIDCFGR_RDENC5_B_0X1		(0x1u<<5)
#define	RISAF_REG6_CIDCFGR_RDENC4_B_0X0		(0x0u<<4)
#define	RISAF_REG6_CIDCFGR_RDENC4_B_0X1		(0x1u<<4)
#define	RISAF_REG6_CIDCFGR_RDENC3_B_0X0		(0x0u<<3)
#define	RISAF_REG6_CIDCFGR_RDENC3_B_0X1		(0x1u<<3)
#define	RISAF_REG6_CIDCFGR_RDENC2_B_0X0		(0x0u<<2)
#define	RISAF_REG6_CIDCFGR_RDENC2_B_0X1		(0x1u<<2)
#define	RISAF_REG6_CIDCFGR_RDENC1_B_0X0		(0x0u<<1)
#define	RISAF_REG6_CIDCFGR_RDENC1_B_0X1		(0x1u<<1)
#define	RISAF_REG6_CIDCFGR_RDENC0_B_0X0		(0x0u<<0)
#define	RISAF_REG6_CIDCFGR_RDENC0_B_0X1		(0x1u<<0)

// REG6_ACFGR Configuration

#define	RISAF_REG6_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG6_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG6_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG6_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG6_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG6_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG6_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG6_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG6_ACFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG6_ACFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG6_ACFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG6_ACFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG6_ACFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG6_ACFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG6_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG6_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG6_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG6_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG6_ACFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG6_ACFGR_SREN_B_0X1			(0x1u<<0)

// REG6_ASTARTR Configuration

#define	RISAF_REG6_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG6_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG6_AENDR Configuration

#define	RISAF_REG6_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG6_AENDR_SADDEND_0			(0x1u<<0)

// REG6_ANESTR Configuration

#define	RISAF_REG6_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG6_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG6_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG6_BCFGR Configuration

#define	RISAF_REG6_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG6_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG6_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG6_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG6_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG6_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG6_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG6_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG6_BCFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG6_BCFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG6_BCFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG6_BCFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG6_BCFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG6_BCFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG6_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG6_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG6_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG6_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG6_BCFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG6_BCFGR_SREN_B_0X1			(0x1u<<0)

// REG6_BSTARTR Configuration

#define	RISAF_REG6_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG6_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG6_BENDR Configuration

#define	RISAF_REG6_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG6_BENDR_SADDEND_0			(0x1u<<0)

// REG6_BNESTR Configuration

#define	RISAF_REG6_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG6_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG6_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG7_CFGR Configuration

#define	RISAF_REG7_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG7_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG7_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG7_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG7_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG7_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG7_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG7_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG7_CFGR_SEC					(0x1u<<8)
#define	RISAF_REG7_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG7_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG7_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG7_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG7_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG7_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG7_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG7_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG7_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG7_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG7_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG7_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG7_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG7_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG7_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG7_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG7_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG7_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG7_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG7_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG7_CFGR_BREN_B_0X1			(0x1u<<0)

// REG7_STARTR Configuration

#define	RISAF_REG7_STARTR_BADDSTART			(0xFFFFFFFFu<<0)
#define	RISAF_REG7_STARTR_BADDSTART_0		(0x1u<<0)

// REG7_ENDR Configuration

#define	RISAF_REG7_ENDR_BADDEND				(0xFFFFFFFFu<<0)
#define	RISAF_REG7_ENDR_BADDEND_0			(0x1u<<0)

// REG7_CIDCFGR Configuration

#define	RISAF_REG7_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG7_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG7_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG7_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG7_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG7_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG7_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG7_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG7_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG7_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG7_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG7_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG7_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG7_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG7_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG7_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG7_CIDCFGR_WRENC7_B_0X0		(0x0u<<23)
#define	RISAF_REG7_CIDCFGR_WRENC7_B_0X1		(0x1u<<23)
#define	RISAF_REG7_CIDCFGR_WRENC6_B_0X0		(0x0u<<22)
#define	RISAF_REG7_CIDCFGR_WRENC6_B_0X1		(0x1u<<22)
#define	RISAF_REG7_CIDCFGR_WRENC5_B_0X0		(0x0u<<21)
#define	RISAF_REG7_CIDCFGR_WRENC5_B_0X1		(0x1u<<21)
#define	RISAF_REG7_CIDCFGR_WRENC4_B_0X0		(0x0u<<20)
#define	RISAF_REG7_CIDCFGR_WRENC4_B_0X1		(0x1u<<20)
#define	RISAF_REG7_CIDCFGR_WRENC3_B_0X0		(0x0u<<19)
#define	RISAF_REG7_CIDCFGR_WRENC3_B_0X1		(0x1u<<19)
#define	RISAF_REG7_CIDCFGR_WRENC2_B_0X0		(0x0u<<18)
#define	RISAF_REG7_CIDCFGR_WRENC2_B_0X1		(0x1u<<18)
#define	RISAF_REG7_CIDCFGR_WRENC1_B_0X0		(0x0u<<17)
#define	RISAF_REG7_CIDCFGR_WRENC1_B_0X1		(0x1u<<17)
#define	RISAF_REG7_CIDCFGR_WRENC0_B_0X0		(0x0u<<16)
#define	RISAF_REG7_CIDCFGR_WRENC0_B_0X1		(0x1u<<16)
#define	RISAF_REG7_CIDCFGR_RDENC7_B_0X0		(0x0u<<7)
#define	RISAF_REG7_CIDCFGR_RDENC7_B_0X1		(0x1u<<7)
#define	RISAF_REG7_CIDCFGR_RDENC6_B_0X0		(0x0u<<6)
#define	RISAF_REG7_CIDCFGR_RDENC6_B_0X1		(0x1u<<6)
#define	RISAF_REG7_CIDCFGR_RDENC5_B_0X0		(0x0u<<5)
#define	RISAF_REG7_CIDCFGR_RDENC5_B_0X1		(0x1u<<5)
#define	RISAF_REG7_CIDCFGR_RDENC4_B_0X0		(0x0u<<4)
#define	RISAF_REG7_CIDCFGR_RDENC4_B_0X1		(0x1u<<4)
#define	RISAF_REG7_CIDCFGR_RDENC3_B_0X0		(0x0u<<3)
#define	RISAF_REG7_CIDCFGR_RDENC3_B_0X1		(0x1u<<3)
#define	RISAF_REG7_CIDCFGR_RDENC2_B_0X0		(0x0u<<2)
#define	RISAF_REG7_CIDCFGR_RDENC2_B_0X1		(0x1u<<2)
#define	RISAF_REG7_CIDCFGR_RDENC1_B_0X0		(0x0u<<1)
#define	RISAF_REG7_CIDCFGR_RDENC1_B_0X1		(0x1u<<1)
#define	RISAF_REG7_CIDCFGR_RDENC0_B_0X0		(0x0u<<0)
#define	RISAF_REG7_CIDCFGR_RDENC0_B_0X1		(0x1u<<0)

// REG7_ACFGR Configuration

#define	RISAF_REG7_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG7_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG7_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG7_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG7_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG7_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG7_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG7_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG7_ACFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG7_ACFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG7_ACFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG7_ACFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG7_ACFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG7_ACFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG7_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG7_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG7_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG7_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG7_ACFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG7_ACFGR_SREN_B_0X1			(0x1u<<0)

// REG7_ASTARTR Configuration

#define	RISAF_REG7_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG7_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG7_AENDR Configuration

#define	RISAF_REG7_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG7_AENDR_SADDEND_0			(0x1u<<0)

// REG7_ANESTR Configuration

#define	RISAF_REG7_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG7_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG7_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG7_BCFGR Configuration

#define	RISAF_REG7_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG7_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG7_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG7_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG7_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG7_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG7_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG7_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG7_BCFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG7_BCFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG7_BCFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG7_BCFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG7_BCFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG7_BCFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG7_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG7_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG7_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG7_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG7_BCFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG7_BCFGR_SREN_B_0X1			(0x1u<<0)

// REG7_BSTARTR Configuration

#define	RISAF_REG7_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG7_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG7_BENDR Configuration

#define	RISAF_REG7_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG7_BENDR_SADDEND_0			(0x1u<<0)

// REG7_BNESTR Configuration

#define	RISAF_REG7_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG7_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG7_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG8_CFGR Configuration

#define	RISAF_REG8_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG8_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG8_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG8_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG8_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG8_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG8_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG8_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG8_CFGR_SEC					(0x1u<<8)
#define	RISAF_REG8_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG8_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG8_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG8_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG8_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG8_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG8_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG8_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG8_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG8_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG8_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG8_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG8_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG8_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG8_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG8_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG8_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG8_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG8_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG8_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG8_CFGR_BREN_B_0X1			(0x1u<<0)

// REG8_STARTR Configuration

#define	RISAF_REG8_STARTR_BADDSTART			(0xFFFFFFFFu<<0)
#define	RISAF_REG8_STARTR_BADDSTART_0		(0x1u<<0)

// REG8_ENDR Configuration

#define	RISAF_REG8_ENDR_BADDEND				(0xFFFFFFFFu<<0)
#define	RISAF_REG8_ENDR_BADDEND_0			(0x1u<<0)

// REG8_CIDCFGR Configuration

#define	RISAF_REG8_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG8_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG8_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG8_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG8_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG8_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG8_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG8_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG8_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG8_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG8_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG8_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG8_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG8_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG8_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG8_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG8_CIDCFGR_WRENC7_B_0X0		(0x0u<<23)
#define	RISAF_REG8_CIDCFGR_WRENC7_B_0X1		(0x1u<<23)
#define	RISAF_REG8_CIDCFGR_WRENC6_B_0X0		(0x0u<<22)
#define	RISAF_REG8_CIDCFGR_WRENC6_B_0X1		(0x1u<<22)
#define	RISAF_REG8_CIDCFGR_WRENC5_B_0X0		(0x0u<<21)
#define	RISAF_REG8_CIDCFGR_WRENC5_B_0X1		(0x1u<<21)
#define	RISAF_REG8_CIDCFGR_WRENC4_B_0X0		(0x0u<<20)
#define	RISAF_REG8_CIDCFGR_WRENC4_B_0X1		(0x1u<<20)
#define	RISAF_REG8_CIDCFGR_WRENC3_B_0X0		(0x0u<<19)
#define	RISAF_REG8_CIDCFGR_WRENC3_B_0X1		(0x1u<<19)
#define	RISAF_REG8_CIDCFGR_WRENC2_B_0X0		(0x0u<<18)
#define	RISAF_REG8_CIDCFGR_WRENC2_B_0X1		(0x1u<<18)
#define	RISAF_REG8_CIDCFGR_WRENC1_B_0X0		(0x0u<<17)
#define	RISAF_REG8_CIDCFGR_WRENC1_B_0X1		(0x1u<<17)
#define	RISAF_REG8_CIDCFGR_WRENC0_B_0X0		(0x0u<<16)
#define	RISAF_REG8_CIDCFGR_WRENC0_B_0X1		(0x1u<<16)
#define	RISAF_REG8_CIDCFGR_RDENC7_B_0X0		(0x0u<<7)
#define	RISAF_REG8_CIDCFGR_RDENC7_B_0X1		(0x1u<<7)
#define	RISAF_REG8_CIDCFGR_RDENC6_B_0X0		(0x0u<<6)
#define	RISAF_REG8_CIDCFGR_RDENC6_B_0X1		(0x1u<<6)
#define	RISAF_REG8_CIDCFGR_RDENC5_B_0X0		(0x0u<<5)
#define	RISAF_REG8_CIDCFGR_RDENC5_B_0X1		(0x1u<<5)
#define	RISAF_REG8_CIDCFGR_RDENC4_B_0X0		(0x0u<<4)
#define	RISAF_REG8_CIDCFGR_RDENC4_B_0X1		(0x1u<<4)
#define	RISAF_REG8_CIDCFGR_RDENC3_B_0X0		(0x0u<<3)
#define	RISAF_REG8_CIDCFGR_RDENC3_B_0X1		(0x1u<<3)
#define	RISAF_REG8_CIDCFGR_RDENC2_B_0X0		(0x0u<<2)
#define	RISAF_REG8_CIDCFGR_RDENC2_B_0X1		(0x1u<<2)
#define	RISAF_REG8_CIDCFGR_RDENC1_B_0X0		(0x0u<<1)
#define	RISAF_REG8_CIDCFGR_RDENC1_B_0X1		(0x1u<<1)
#define	RISAF_REG8_CIDCFGR_RDENC0_B_0X0		(0x0u<<0)
#define	RISAF_REG8_CIDCFGR_RDENC0_B_0X1		(0x1u<<0)

// REG8_ACFGR Configuration

#define	RISAF_REG8_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG8_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG8_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG8_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG8_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG8_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG8_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG8_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG8_ACFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG8_ACFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG8_ACFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG8_ACFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG8_ACFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG8_ACFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG8_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG8_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG8_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG8_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG8_ACFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG8_ACFGR_SREN_B_0X1			(0x1u<<0)

// REG8_ASTARTR Configuration

#define	RISAF_REG8_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG8_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG8_AENDR Configuration

#define	RISAF_REG8_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG8_AENDR_SADDEND_0			(0x1u<<0)

// REG8_ANESTR Configuration

#define	RISAF_REG8_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG8_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG8_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG8_BCFGR Configuration

#define	RISAF_REG8_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG8_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG8_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG8_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG8_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG8_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG8_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG8_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG8_BCFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG8_BCFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG8_BCFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG8_BCFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG8_BCFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG8_BCFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG8_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG8_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG8_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG8_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG8_BCFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG8_BCFGR_SREN_B_0X1			(0x1u<<0)

// REG8_BSTARTR Configuration

#define	RISAF_REG8_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG8_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG8_BENDR Configuration

#define	RISAF_REG8_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG8_BENDR_SADDEND_0			(0x1u<<0)

// REG8_BNESTR Configuration

#define	RISAF_REG8_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG8_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG8_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG9_CFGR Configuration

#define	RISAF_REG9_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG9_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG9_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG9_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG9_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG9_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG9_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG9_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG9_CFGR_SEC					(0x1u<<8)
#define	RISAF_REG9_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG9_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG9_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG9_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG9_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG9_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG9_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG9_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG9_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG9_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG9_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG9_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG9_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG9_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG9_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG9_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG9_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG9_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG9_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG9_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG9_CFGR_BREN_B_0X1			(0x1u<<0)

// REG9_STARTR Configuration

#define	RISAF_REG9_STARTR_BADDSTART			(0xFFFFFFFFu<<0)
#define	RISAF_REG9_STARTR_BADDSTART_0		(0x1u<<0)

// REG9_ENDR Configuration

#define	RISAF_REG9_ENDR_BADDEND				(0xFFFFFFFFu<<0)
#define	RISAF_REG9_ENDR_BADDEND_0			(0x1u<<0)

// REG9_CIDCFGR Configuration

#define	RISAF_REG9_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG9_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG9_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG9_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG9_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG9_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG9_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG9_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG9_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG9_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG9_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG9_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG9_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG9_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG9_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG9_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG9_CIDCFGR_WRENC7_B_0X0		(0x0u<<23)
#define	RISAF_REG9_CIDCFGR_WRENC7_B_0X1		(0x1u<<23)
#define	RISAF_REG9_CIDCFGR_WRENC6_B_0X0		(0x0u<<22)
#define	RISAF_REG9_CIDCFGR_WRENC6_B_0X1		(0x1u<<22)
#define	RISAF_REG9_CIDCFGR_WRENC5_B_0X0		(0x0u<<21)
#define	RISAF_REG9_CIDCFGR_WRENC5_B_0X1		(0x1u<<21)
#define	RISAF_REG9_CIDCFGR_WRENC4_B_0X0		(0x0u<<20)
#define	RISAF_REG9_CIDCFGR_WRENC4_B_0X1		(0x1u<<20)
#define	RISAF_REG9_CIDCFGR_WRENC3_B_0X0		(0x0u<<19)
#define	RISAF_REG9_CIDCFGR_WRENC3_B_0X1		(0x1u<<19)
#define	RISAF_REG9_CIDCFGR_WRENC2_B_0X0		(0x0u<<18)
#define	RISAF_REG9_CIDCFGR_WRENC2_B_0X1		(0x1u<<18)
#define	RISAF_REG9_CIDCFGR_WRENC1_B_0X0		(0x0u<<17)
#define	RISAF_REG9_CIDCFGR_WRENC1_B_0X1		(0x1u<<17)
#define	RISAF_REG9_CIDCFGR_WRENC0_B_0X0		(0x0u<<16)
#define	RISAF_REG9_CIDCFGR_WRENC0_B_0X1		(0x1u<<16)
#define	RISAF_REG9_CIDCFGR_RDENC7_B_0X0		(0x0u<<7)
#define	RISAF_REG9_CIDCFGR_RDENC7_B_0X1		(0x1u<<7)
#define	RISAF_REG9_CIDCFGR_RDENC6_B_0X0		(0x0u<<6)
#define	RISAF_REG9_CIDCFGR_RDENC6_B_0X1		(0x1u<<6)
#define	RISAF_REG9_CIDCFGR_RDENC5_B_0X0		(0x0u<<5)
#define	RISAF_REG9_CIDCFGR_RDENC5_B_0X1		(0x1u<<5)
#define	RISAF_REG9_CIDCFGR_RDENC4_B_0X0		(0x0u<<4)
#define	RISAF_REG9_CIDCFGR_RDENC4_B_0X1		(0x1u<<4)
#define	RISAF_REG9_CIDCFGR_RDENC3_B_0X0		(0x0u<<3)
#define	RISAF_REG9_CIDCFGR_RDENC3_B_0X1		(0x1u<<3)
#define	RISAF_REG9_CIDCFGR_RDENC2_B_0X0		(0x0u<<2)
#define	RISAF_REG9_CIDCFGR_RDENC2_B_0X1		(0x1u<<2)
#define	RISAF_REG9_CIDCFGR_RDENC1_B_0X0		(0x0u<<1)
#define	RISAF_REG9_CIDCFGR_RDENC1_B_0X1		(0x1u<<1)
#define	RISAF_REG9_CIDCFGR_RDENC0_B_0X0		(0x0u<<0)
#define	RISAF_REG9_CIDCFGR_RDENC0_B_0X1		(0x1u<<0)

// REG9_ACFGR Configuration

#define	RISAF_REG9_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG9_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG9_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG9_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG9_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG9_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG9_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG9_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG9_ACFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG9_ACFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG9_ACFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG9_ACFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG9_ACFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG9_ACFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG9_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG9_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG9_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG9_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG9_ACFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG9_ACFGR_SREN_B_0X1			(0x1u<<0)

// REG9_ASTARTR Configuration

#define	RISAF_REG9_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG9_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG9_AENDR Configuration

#define	RISAF_REG9_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG9_AENDR_SADDEND_0			(0x1u<<0)

// REG9_ANESTR Configuration

#define	RISAF_REG9_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG9_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG9_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG9_BCFGR Configuration

#define	RISAF_REG9_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG9_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG9_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG9_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG9_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG9_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG9_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG9_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG9_BCFGR_WREN_B_0X0			(0x0u<<13)
#define	RISAF_REG9_BCFGR_WREN_B_0X1			(0x1u<<13)
#define	RISAF_REG9_BCFGR_RDEN_B_0X0			(0x0u<<12)
#define	RISAF_REG9_BCFGR_RDEN_B_0X1			(0x1u<<12)
#define	RISAF_REG9_BCFGR_PRIV_B_0X0			(0x0u<<9)
#define	RISAF_REG9_BCFGR_PRIV_B_0X1			(0x1u<<9)
#define	RISAF_REG9_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG9_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG9_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG9_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG9_BCFGR_SREN_B_0X0			(0x0u<<0)
#define	RISAF_REG9_BCFGR_SREN_B_0X1			(0x1u<<0)

// REG9_BSTARTR Configuration

#define	RISAF_REG9_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG9_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG9_BENDR Configuration

#define	RISAF_REG9_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG9_BENDR_SADDEND_0			(0x1u<<0)

// REG9_BNESTR Configuration

#define	RISAF_REG9_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG9_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG9_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG10_CFGR Configuration

#define	RISAF_REG10_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG10_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG10_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG10_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG10_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG10_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG10_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG10_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG10_CFGR_SEC				(0x1u<<8)
#define	RISAF_REG10_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG10_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG10_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG10_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG10_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG10_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG10_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG10_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG10_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG10_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG10_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG10_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG10_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG10_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG10_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG10_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG10_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG10_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG10_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG10_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG10_CFGR_BREN_B_0X1			(0x1u<<0)

// REG10_STARTR Configuration

#define	RISAF_REG10_STARTR_BADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG10_STARTR_BADDSTART_0		(0x1u<<0)

// REG10_ENDR Configuration

#define	RISAF_REG10_ENDR_BADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG10_ENDR_BADDEND_0			(0x1u<<0)

// REG10_CIDCFGR Configuration

#define	RISAF_REG10_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG10_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG10_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG10_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG10_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG10_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG10_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG10_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG10_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG10_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG10_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG10_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG10_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG10_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG10_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG10_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG10_CIDCFGR_WRENC7_B_0X0	(0x0u<<23)
#define	RISAF_REG10_CIDCFGR_WRENC7_B_0X1	(0x1u<<23)
#define	RISAF_REG10_CIDCFGR_WRENC6_B_0X0	(0x0u<<22)
#define	RISAF_REG10_CIDCFGR_WRENC6_B_0X1	(0x1u<<22)
#define	RISAF_REG10_CIDCFGR_WRENC5_B_0X0	(0x0u<<21)
#define	RISAF_REG10_CIDCFGR_WRENC5_B_0X1	(0x1u<<21)
#define	RISAF_REG10_CIDCFGR_WRENC4_B_0X0	(0x0u<<20)
#define	RISAF_REG10_CIDCFGR_WRENC4_B_0X1	(0x1u<<20)
#define	RISAF_REG10_CIDCFGR_WRENC3_B_0X0	(0x0u<<19)
#define	RISAF_REG10_CIDCFGR_WRENC3_B_0X1	(0x1u<<19)
#define	RISAF_REG10_CIDCFGR_WRENC2_B_0X0	(0x0u<<18)
#define	RISAF_REG10_CIDCFGR_WRENC2_B_0X1	(0x1u<<18)
#define	RISAF_REG10_CIDCFGR_WRENC1_B_0X0	(0x0u<<17)
#define	RISAF_REG10_CIDCFGR_WRENC1_B_0X1	(0x1u<<17)
#define	RISAF_REG10_CIDCFGR_WRENC0_B_0X0	(0x0u<<16)
#define	RISAF_REG10_CIDCFGR_WRENC0_B_0X1	(0x1u<<16)
#define	RISAF_REG10_CIDCFGR_RDENC7_B_0X0	(0x0u<<7)
#define	RISAF_REG10_CIDCFGR_RDENC7_B_0X1	(0x1u<<7)
#define	RISAF_REG10_CIDCFGR_RDENC6_B_0X0	(0x0u<<6)
#define	RISAF_REG10_CIDCFGR_RDENC6_B_0X1	(0x1u<<6)
#define	RISAF_REG10_CIDCFGR_RDENC5_B_0X0	(0x0u<<5)
#define	RISAF_REG10_CIDCFGR_RDENC5_B_0X1	(0x1u<<5)
#define	RISAF_REG10_CIDCFGR_RDENC4_B_0X0	(0x0u<<4)
#define	RISAF_REG10_CIDCFGR_RDENC4_B_0X1	(0x1u<<4)
#define	RISAF_REG10_CIDCFGR_RDENC3_B_0X0	(0x0u<<3)
#define	RISAF_REG10_CIDCFGR_RDENC3_B_0X1	(0x1u<<3)
#define	RISAF_REG10_CIDCFGR_RDENC2_B_0X0	(0x0u<<2)
#define	RISAF_REG10_CIDCFGR_RDENC2_B_0X1	(0x1u<<2)
#define	RISAF_REG10_CIDCFGR_RDENC1_B_0X0	(0x0u<<1)
#define	RISAF_REG10_CIDCFGR_RDENC1_B_0X1	(0x1u<<1)
#define	RISAF_REG10_CIDCFGR_RDENC0_B_0X0	(0x0u<<0)
#define	RISAF_REG10_CIDCFGR_RDENC0_B_0X1	(0x1u<<0)

// REG10_ACFGR Configuration

#define	RISAF_REG10_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG10_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG10_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG10_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG10_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG10_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG10_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG10_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG10_ACFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG10_ACFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG10_ACFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG10_ACFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG10_ACFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG10_ACFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG10_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG10_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG10_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG10_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG10_ACFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG10_ACFGR_SREN_B_0X1		(0x1u<<0)

// REG10_ASTARTR Configuration

#define	RISAF_REG10_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG10_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG10_AENDR Configuration

#define	RISAF_REG10_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG10_AENDR_SADDEND_0			(0x1u<<0)

// REG10_ANESTR Configuration

#define	RISAF_REG10_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG10_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG10_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG10_BCFGR Configuration

#define	RISAF_REG10_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG10_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG10_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG10_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG10_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG10_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG10_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG10_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG10_BCFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG10_BCFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG10_BCFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG10_BCFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG10_BCFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG10_BCFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG10_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG10_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG10_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG10_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG10_BCFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG10_BCFGR_SREN_B_0X1		(0x1u<<0)

// REG10_BSTARTR Configuration

#define	RISAF_REG10_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG10_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG10_BENDR Configuration

#define	RISAF_REG10_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG10_BENDR_SADDEND_0			(0x1u<<0)

// REG10_BNESTR Configuration

#define	RISAF_REG10_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG10_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG10_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG11_CFGR Configuration

#define	RISAF_REG11_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG11_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG11_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG11_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG11_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG11_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG11_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG11_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG11_CFGR_SEC				(0x1u<<8)
#define	RISAF_REG11_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG11_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG11_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG11_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG11_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG11_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG11_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG11_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG11_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG11_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG11_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG11_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG11_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG11_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG11_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG11_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG11_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG11_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG11_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG11_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG11_CFGR_BREN_B_0X1			(0x1u<<0)

// REG11_STARTR Configuration

#define	RISAF_REG11_STARTR_BADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG11_STARTR_BADDSTART_0		(0x1u<<0)

// REG11_ENDR Configuration

#define	RISAF_REG11_ENDR_BADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG11_ENDR_BADDEND_0			(0x1u<<0)

// REG11_CIDCFGR Configuration

#define	RISAF_REG11_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG11_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG11_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG11_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG11_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG11_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG11_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG11_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG11_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG11_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG11_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG11_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG11_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG11_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG11_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG11_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG11_CIDCFGR_WRENC7_B_0X0	(0x0u<<23)
#define	RISAF_REG11_CIDCFGR_WRENC7_B_0X1	(0x1u<<23)
#define	RISAF_REG11_CIDCFGR_WRENC6_B_0X0	(0x0u<<22)
#define	RISAF_REG11_CIDCFGR_WRENC6_B_0X1	(0x1u<<22)
#define	RISAF_REG11_CIDCFGR_WRENC5_B_0X0	(0x0u<<21)
#define	RISAF_REG11_CIDCFGR_WRENC5_B_0X1	(0x1u<<21)
#define	RISAF_REG11_CIDCFGR_WRENC4_B_0X0	(0x0u<<20)
#define	RISAF_REG11_CIDCFGR_WRENC4_B_0X1	(0x1u<<20)
#define	RISAF_REG11_CIDCFGR_WRENC3_B_0X0	(0x0u<<19)
#define	RISAF_REG11_CIDCFGR_WRENC3_B_0X1	(0x1u<<19)
#define	RISAF_REG11_CIDCFGR_WRENC2_B_0X0	(0x0u<<18)
#define	RISAF_REG11_CIDCFGR_WRENC2_B_0X1	(0x1u<<18)
#define	RISAF_REG11_CIDCFGR_WRENC1_B_0X0	(0x0u<<17)
#define	RISAF_REG11_CIDCFGR_WRENC1_B_0X1	(0x1u<<17)
#define	RISAF_REG11_CIDCFGR_WRENC0_B_0X0	(0x0u<<16)
#define	RISAF_REG11_CIDCFGR_WRENC0_B_0X1	(0x1u<<16)
#define	RISAF_REG11_CIDCFGR_RDENC7_B_0X0	(0x0u<<7)
#define	RISAF_REG11_CIDCFGR_RDENC7_B_0X1	(0x1u<<7)
#define	RISAF_REG11_CIDCFGR_RDENC6_B_0X0	(0x0u<<6)
#define	RISAF_REG11_CIDCFGR_RDENC6_B_0X1	(0x1u<<6)
#define	RISAF_REG11_CIDCFGR_RDENC5_B_0X0	(0x0u<<5)
#define	RISAF_REG11_CIDCFGR_RDENC5_B_0X1	(0x1u<<5)
#define	RISAF_REG11_CIDCFGR_RDENC4_B_0X0	(0x0u<<4)
#define	RISAF_REG11_CIDCFGR_RDENC4_B_0X1	(0x1u<<4)
#define	RISAF_REG11_CIDCFGR_RDENC3_B_0X0	(0x0u<<3)
#define	RISAF_REG11_CIDCFGR_RDENC3_B_0X1	(0x1u<<3)
#define	RISAF_REG11_CIDCFGR_RDENC2_B_0X0	(0x0u<<2)
#define	RISAF_REG11_CIDCFGR_RDENC2_B_0X1	(0x1u<<2)
#define	RISAF_REG11_CIDCFGR_RDENC1_B_0X0	(0x0u<<1)
#define	RISAF_REG11_CIDCFGR_RDENC1_B_0X1	(0x1u<<1)
#define	RISAF_REG11_CIDCFGR_RDENC0_B_0X0	(0x0u<<0)
#define	RISAF_REG11_CIDCFGR_RDENC0_B_0X1	(0x1u<<0)

// REG11_ACFGR Configuration

#define	RISAF_REG11_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG11_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG11_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG11_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG11_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG11_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG11_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG11_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG11_ACFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG11_ACFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG11_ACFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG11_ACFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG11_ACFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG11_ACFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG11_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG11_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG11_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG11_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG11_ACFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG11_ACFGR_SREN_B_0X1		(0x1u<<0)

// REG11_ASTARTR Configuration

#define	RISAF_REG11_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG11_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG11_AENDR Configuration

#define	RISAF_REG11_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG11_AENDR_SADDEND_0			(0x1u<<0)

// REG11_ANESTR Configuration

#define	RISAF_REG11_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG11_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG11_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG11_BCFGR Configuration

#define	RISAF_REG11_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG11_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG11_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG11_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG11_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG11_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG11_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG11_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG11_BCFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG11_BCFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG11_BCFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG11_BCFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG11_BCFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG11_BCFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG11_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG11_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG11_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG11_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG11_BCFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG11_BCFGR_SREN_B_0X1		(0x1u<<0)

// REG11_BSTARTR Configuration

#define	RISAF_REG11_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG11_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG11_BENDR Configuration

#define	RISAF_REG11_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG11_BENDR_SADDEND_0			(0x1u<<0)

// REG11_BNESTR Configuration

#define	RISAF_REG11_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG11_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG11_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG12_CFGR Configuration

#define	RISAF_REG12_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG12_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG12_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG12_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG12_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG12_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG12_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG12_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG12_CFGR_SEC				(0x1u<<8)
#define	RISAF_REG12_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG12_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG12_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG12_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG12_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG12_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG12_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG12_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG12_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG12_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG12_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG12_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG12_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG12_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG12_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG12_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG12_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG12_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG12_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG12_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG12_CFGR_BREN_B_0X1			(0x1u<<0)

// REG12_STARTR Configuration

#define	RISAF_REG12_STARTR_BADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG12_STARTR_BADDSTART_0		(0x1u<<0)

// REG12_ENDR Configuration

#define	RISAF_REG12_ENDR_BADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG12_ENDR_BADDEND_0			(0x1u<<0)

// REG12_CIDCFGR Configuration

#define	RISAF_REG12_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG12_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG12_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG12_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG12_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG12_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG12_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG12_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG12_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG12_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG12_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG12_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG12_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG12_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG12_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG12_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG12_CIDCFGR_WRENC7_B_0X0	(0x0u<<23)
#define	RISAF_REG12_CIDCFGR_WRENC7_B_0X1	(0x1u<<23)
#define	RISAF_REG12_CIDCFGR_WRENC6_B_0X0	(0x0u<<22)
#define	RISAF_REG12_CIDCFGR_WRENC6_B_0X1	(0x1u<<22)
#define	RISAF_REG12_CIDCFGR_WRENC5_B_0X0	(0x0u<<21)
#define	RISAF_REG12_CIDCFGR_WRENC5_B_0X1	(0x1u<<21)
#define	RISAF_REG12_CIDCFGR_WRENC4_B_0X0	(0x0u<<20)
#define	RISAF_REG12_CIDCFGR_WRENC4_B_0X1	(0x1u<<20)
#define	RISAF_REG12_CIDCFGR_WRENC3_B_0X0	(0x0u<<19)
#define	RISAF_REG12_CIDCFGR_WRENC3_B_0X1	(0x1u<<19)
#define	RISAF_REG12_CIDCFGR_WRENC2_B_0X0	(0x0u<<18)
#define	RISAF_REG12_CIDCFGR_WRENC2_B_0X1	(0x1u<<18)
#define	RISAF_REG12_CIDCFGR_WRENC1_B_0X0	(0x0u<<17)
#define	RISAF_REG12_CIDCFGR_WRENC1_B_0X1	(0x1u<<17)
#define	RISAF_REG12_CIDCFGR_WRENC0_B_0X0	(0x0u<<16)
#define	RISAF_REG12_CIDCFGR_WRENC0_B_0X1	(0x1u<<16)
#define	RISAF_REG12_CIDCFGR_RDENC7_B_0X0	(0x0u<<7)
#define	RISAF_REG12_CIDCFGR_RDENC7_B_0X1	(0x1u<<7)
#define	RISAF_REG12_CIDCFGR_RDENC6_B_0X0	(0x0u<<6)
#define	RISAF_REG12_CIDCFGR_RDENC6_B_0X1	(0x1u<<6)
#define	RISAF_REG12_CIDCFGR_RDENC5_B_0X0	(0x0u<<5)
#define	RISAF_REG12_CIDCFGR_RDENC5_B_0X1	(0x1u<<5)
#define	RISAF_REG12_CIDCFGR_RDENC4_B_0X0	(0x0u<<4)
#define	RISAF_REG12_CIDCFGR_RDENC4_B_0X1	(0x1u<<4)
#define	RISAF_REG12_CIDCFGR_RDENC3_B_0X0	(0x0u<<3)
#define	RISAF_REG12_CIDCFGR_RDENC3_B_0X1	(0x1u<<3)
#define	RISAF_REG12_CIDCFGR_RDENC2_B_0X0	(0x0u<<2)
#define	RISAF_REG12_CIDCFGR_RDENC2_B_0X1	(0x1u<<2)
#define	RISAF_REG12_CIDCFGR_RDENC1_B_0X0	(0x0u<<1)
#define	RISAF_REG12_CIDCFGR_RDENC1_B_0X1	(0x1u<<1)
#define	RISAF_REG12_CIDCFGR_RDENC0_B_0X0	(0x0u<<0)
#define	RISAF_REG12_CIDCFGR_RDENC0_B_0X1	(0x1u<<0)

// REG12_ACFGR Configuration

#define	RISAF_REG12_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG12_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG12_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG12_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG12_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG12_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG12_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG12_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG12_ACFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG12_ACFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG12_ACFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG12_ACFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG12_ACFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG12_ACFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG12_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG12_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG12_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG12_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG12_ACFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG12_ACFGR_SREN_B_0X1		(0x1u<<0)

// REG12_ASTARTR Configuration

#define	RISAF_REG12_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG12_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG12_AENDR Configuration

#define	RISAF_REG12_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG12_AENDR_SADDEND_0			(0x1u<<0)

// REG12_ANESTR Configuration

#define	RISAF_REG12_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG12_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG12_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG12_BCFGR Configuration

#define	RISAF_REG12_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG12_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG12_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG12_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG12_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG12_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG12_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG12_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG12_BCFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG12_BCFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG12_BCFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG12_BCFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG12_BCFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG12_BCFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG12_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG12_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG12_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG12_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG12_BCFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG12_BCFGR_SREN_B_0X1		(0x1u<<0)

// REG12_BSTARTR Configuration

#define	RISAF_REG12_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG12_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG12_BENDR Configuration

#define	RISAF_REG12_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG12_BENDR_SADDEND_0			(0x1u<<0)

// REG12_BNESTR Configuration

#define	RISAF_REG12_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG12_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG12_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG13_CFGR Configuration

#define	RISAF_REG13_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG13_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG13_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG13_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG13_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG13_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG13_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG13_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG13_CFGR_SEC				(0x1u<<8)
#define	RISAF_REG13_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG13_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG13_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG13_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG13_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG13_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG13_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG13_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG13_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG13_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG13_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG13_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG13_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG13_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG13_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG13_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG13_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG13_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG13_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG13_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG13_CFGR_BREN_B_0X1			(0x1u<<0)

// REG13_STARTR Configuration

#define	RISAF_REG13_STARTR_BADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG13_STARTR_BADDSTART_0		(0x1u<<0)

// REG13_ENDR Configuration

#define	RISAF_REG13_ENDR_BADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG13_ENDR_BADDEND_0			(0x1u<<0)

// REG13_CIDCFGR Configuration

#define	RISAF_REG13_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG13_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG13_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG13_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG13_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG13_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG13_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG13_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG13_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG13_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG13_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG13_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG13_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG13_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG13_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG13_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG13_CIDCFGR_WRENC7_B_0X0	(0x0u<<23)
#define	RISAF_REG13_CIDCFGR_WRENC7_B_0X1	(0x1u<<23)
#define	RISAF_REG13_CIDCFGR_WRENC6_B_0X0	(0x0u<<22)
#define	RISAF_REG13_CIDCFGR_WRENC6_B_0X1	(0x1u<<22)
#define	RISAF_REG13_CIDCFGR_WRENC5_B_0X0	(0x0u<<21)
#define	RISAF_REG13_CIDCFGR_WRENC5_B_0X1	(0x1u<<21)
#define	RISAF_REG13_CIDCFGR_WRENC4_B_0X0	(0x0u<<20)
#define	RISAF_REG13_CIDCFGR_WRENC4_B_0X1	(0x1u<<20)
#define	RISAF_REG13_CIDCFGR_WRENC3_B_0X0	(0x0u<<19)
#define	RISAF_REG13_CIDCFGR_WRENC3_B_0X1	(0x1u<<19)
#define	RISAF_REG13_CIDCFGR_WRENC2_B_0X0	(0x0u<<18)
#define	RISAF_REG13_CIDCFGR_WRENC2_B_0X1	(0x1u<<18)
#define	RISAF_REG13_CIDCFGR_WRENC1_B_0X0	(0x0u<<17)
#define	RISAF_REG13_CIDCFGR_WRENC1_B_0X1	(0x1u<<17)
#define	RISAF_REG13_CIDCFGR_WRENC0_B_0X0	(0x0u<<16)
#define	RISAF_REG13_CIDCFGR_WRENC0_B_0X1	(0x1u<<16)
#define	RISAF_REG13_CIDCFGR_RDENC7_B_0X0	(0x0u<<7)
#define	RISAF_REG13_CIDCFGR_RDENC7_B_0X1	(0x1u<<7)
#define	RISAF_REG13_CIDCFGR_RDENC6_B_0X0	(0x0u<<6)
#define	RISAF_REG13_CIDCFGR_RDENC6_B_0X1	(0x1u<<6)
#define	RISAF_REG13_CIDCFGR_RDENC5_B_0X0	(0x0u<<5)
#define	RISAF_REG13_CIDCFGR_RDENC5_B_0X1	(0x1u<<5)
#define	RISAF_REG13_CIDCFGR_RDENC4_B_0X0	(0x0u<<4)
#define	RISAF_REG13_CIDCFGR_RDENC4_B_0X1	(0x1u<<4)
#define	RISAF_REG13_CIDCFGR_RDENC3_B_0X0	(0x0u<<3)
#define	RISAF_REG13_CIDCFGR_RDENC3_B_0X1	(0x1u<<3)
#define	RISAF_REG13_CIDCFGR_RDENC2_B_0X0	(0x0u<<2)
#define	RISAF_REG13_CIDCFGR_RDENC2_B_0X1	(0x1u<<2)
#define	RISAF_REG13_CIDCFGR_RDENC1_B_0X0	(0x0u<<1)
#define	RISAF_REG13_CIDCFGR_RDENC1_B_0X1	(0x1u<<1)
#define	RISAF_REG13_CIDCFGR_RDENC0_B_0X0	(0x0u<<0)
#define	RISAF_REG13_CIDCFGR_RDENC0_B_0X1	(0x1u<<0)

// REG13_ACFGR Configuration

#define	RISAF_REG13_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG13_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG13_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG13_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG13_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG13_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG13_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG13_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG13_ACFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG13_ACFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG13_ACFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG13_ACFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG13_ACFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG13_ACFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG13_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG13_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG13_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG13_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG13_ACFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG13_ACFGR_SREN_B_0X1		(0x1u<<0)

// REG13_ASTARTR Configuration

#define	RISAF_REG13_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG13_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG13_AENDR Configuration

#define	RISAF_REG13_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG13_AENDR_SADDEND_0			(0x1u<<0)

// REG13_ANESTR Configuration

#define	RISAF_REG13_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG13_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG13_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG13_BCFGR Configuration

#define	RISAF_REG13_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG13_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG13_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG13_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG13_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG13_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG13_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG13_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG13_BCFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG13_BCFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG13_BCFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG13_BCFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG13_BCFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG13_BCFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG13_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG13_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG13_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG13_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG13_BCFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG13_BCFGR_SREN_B_0X1		(0x1u<<0)

// REG13_BSTARTR Configuration

#define	RISAF_REG13_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG13_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG13_BENDR Configuration

#define	RISAF_REG13_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG13_BENDR_SADDEND_0			(0x1u<<0)

// REG13_BNESTR Configuration

#define	RISAF_REG13_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG13_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG13_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG14_CFGR Configuration

#define	RISAF_REG14_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG14_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG14_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG14_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG14_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG14_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG14_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG14_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG14_CFGR_SEC				(0x1u<<8)
#define	RISAF_REG14_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG14_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG14_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG14_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG14_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG14_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG14_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG14_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG14_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG14_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG14_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG14_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG14_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG14_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG14_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG14_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG14_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG14_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG14_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG14_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG14_CFGR_BREN_B_0X1			(0x1u<<0)

// REG14_STARTR Configuration

#define	RISAF_REG14_STARTR_BADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG14_STARTR_BADDSTART_0		(0x1u<<0)

// REG14_ENDR Configuration

#define	RISAF_REG14_ENDR_BADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG14_ENDR_BADDEND_0			(0x1u<<0)

// REG14_CIDCFGR Configuration

#define	RISAF_REG14_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG14_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG14_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG14_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG14_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG14_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG14_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG14_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG14_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG14_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG14_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG14_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG14_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG14_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG14_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG14_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG14_CIDCFGR_WRENC7_B_0X0	(0x0u<<23)
#define	RISAF_REG14_CIDCFGR_WRENC7_B_0X1	(0x1u<<23)
#define	RISAF_REG14_CIDCFGR_WRENC6_B_0X0	(0x0u<<22)
#define	RISAF_REG14_CIDCFGR_WRENC6_B_0X1	(0x1u<<22)
#define	RISAF_REG14_CIDCFGR_WRENC5_B_0X0	(0x0u<<21)
#define	RISAF_REG14_CIDCFGR_WRENC5_B_0X1	(0x1u<<21)
#define	RISAF_REG14_CIDCFGR_WRENC4_B_0X0	(0x0u<<20)
#define	RISAF_REG14_CIDCFGR_WRENC4_B_0X1	(0x1u<<20)
#define	RISAF_REG14_CIDCFGR_WRENC3_B_0X0	(0x0u<<19)
#define	RISAF_REG14_CIDCFGR_WRENC3_B_0X1	(0x1u<<19)
#define	RISAF_REG14_CIDCFGR_WRENC2_B_0X0	(0x0u<<18)
#define	RISAF_REG14_CIDCFGR_WRENC2_B_0X1	(0x1u<<18)
#define	RISAF_REG14_CIDCFGR_WRENC1_B_0X0	(0x0u<<17)
#define	RISAF_REG14_CIDCFGR_WRENC1_B_0X1	(0x1u<<17)
#define	RISAF_REG14_CIDCFGR_WRENC0_B_0X0	(0x0u<<16)
#define	RISAF_REG14_CIDCFGR_WRENC0_B_0X1	(0x1u<<16)
#define	RISAF_REG14_CIDCFGR_RDENC7_B_0X0	(0x0u<<7)
#define	RISAF_REG14_CIDCFGR_RDENC7_B_0X1	(0x1u<<7)
#define	RISAF_REG14_CIDCFGR_RDENC6_B_0X0	(0x0u<<6)
#define	RISAF_REG14_CIDCFGR_RDENC6_B_0X1	(0x1u<<6)
#define	RISAF_REG14_CIDCFGR_RDENC5_B_0X0	(0x0u<<5)
#define	RISAF_REG14_CIDCFGR_RDENC5_B_0X1	(0x1u<<5)
#define	RISAF_REG14_CIDCFGR_RDENC4_B_0X0	(0x0u<<4)
#define	RISAF_REG14_CIDCFGR_RDENC4_B_0X1	(0x1u<<4)
#define	RISAF_REG14_CIDCFGR_RDENC3_B_0X0	(0x0u<<3)
#define	RISAF_REG14_CIDCFGR_RDENC3_B_0X1	(0x1u<<3)
#define	RISAF_REG14_CIDCFGR_RDENC2_B_0X0	(0x0u<<2)
#define	RISAF_REG14_CIDCFGR_RDENC2_B_0X1	(0x1u<<2)
#define	RISAF_REG14_CIDCFGR_RDENC1_B_0X0	(0x0u<<1)
#define	RISAF_REG14_CIDCFGR_RDENC1_B_0X1	(0x1u<<1)
#define	RISAF_REG14_CIDCFGR_RDENC0_B_0X0	(0x0u<<0)
#define	RISAF_REG14_CIDCFGR_RDENC0_B_0X1	(0x1u<<0)

// REG14_ACFGR Configuration

#define	RISAF_REG14_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG14_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG14_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG14_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG14_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG14_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG14_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG14_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG14_ACFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG14_ACFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG14_ACFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG14_ACFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG14_ACFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG14_ACFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG14_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG14_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG14_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG14_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG14_ACFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG14_ACFGR_SREN_B_0X1		(0x1u<<0)

// REG14_ASTARTR Configuration

#define	RISAF_REG14_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG14_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG14_AENDR Configuration

#define	RISAF_REG14_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG14_AENDR_SADDEND_0			(0x1u<<0)

// REG14_ANESTR Configuration

#define	RISAF_REG14_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG14_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG14_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG14_BCFGR Configuration

#define	RISAF_REG14_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG14_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG14_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG14_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG14_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG14_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG14_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG14_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG14_BCFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG14_BCFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG14_BCFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG14_BCFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG14_BCFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG14_BCFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG14_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG14_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG14_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG14_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG14_BCFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG14_BCFGR_SREN_B_0X1		(0x1u<<0)

// REG14_BSTARTR Configuration

#define	RISAF_REG14_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG14_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG14_BENDR Configuration

#define	RISAF_REG14_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG14_BENDR_SADDEND_0			(0x1u<<0)

// REG14_BNESTR Configuration

#define	RISAF_REG14_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG14_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG14_BNESTR_DCEN_B_0X1		(0x1u<<2)

// REG15_CFGR Configuration

#define	RISAF_REG15_CFGR_PRIVC7				(0x1u<<23)
#define	RISAF_REG15_CFGR_PRIVC6				(0x1u<<22)
#define	RISAF_REG15_CFGR_PRIVC5				(0x1u<<21)
#define	RISAF_REG15_CFGR_PRIVC4				(0x1u<<20)
#define	RISAF_REG15_CFGR_PRIVC3				(0x1u<<19)
#define	RISAF_REG15_CFGR_PRIVC2				(0x1u<<18)
#define	RISAF_REG15_CFGR_PRIVC1				(0x1u<<17)
#define	RISAF_REG15_CFGR_PRIVC0				(0x1u<<16)
#define	RISAF_REG15_CFGR_SEC				(0x1u<<8)
#define	RISAF_REG15_CFGR_BREN				(0x1u<<0)

#define	RISAF_REG15_CFGR_PRIVC7_B_0X0		(0x0u<<23)
#define	RISAF_REG15_CFGR_PRIVC7_B_0X1		(0x1u<<23)
#define	RISAF_REG15_CFGR_PRIVC6_B_0X0		(0x0u<<22)
#define	RISAF_REG15_CFGR_PRIVC6_B_0X1		(0x1u<<22)
#define	RISAF_REG15_CFGR_PRIVC5_B_0X0		(0x0u<<21)
#define	RISAF_REG15_CFGR_PRIVC5_B_0X1		(0x1u<<21)
#define	RISAF_REG15_CFGR_PRIVC4_B_0X0		(0x0u<<20)
#define	RISAF_REG15_CFGR_PRIVC4_B_0X1		(0x1u<<20)
#define	RISAF_REG15_CFGR_PRIVC3_B_0X0		(0x0u<<19)
#define	RISAF_REG15_CFGR_PRIVC3_B_0X1		(0x1u<<19)
#define	RISAF_REG15_CFGR_PRIVC2_B_0X0		(0x0u<<18)
#define	RISAF_REG15_CFGR_PRIVC2_B_0X1		(0x1u<<18)
#define	RISAF_REG15_CFGR_PRIVC1_B_0X0		(0x0u<<17)
#define	RISAF_REG15_CFGR_PRIVC1_B_0X1		(0x1u<<17)
#define	RISAF_REG15_CFGR_PRIVC0_B_0X0		(0x0u<<16)
#define	RISAF_REG15_CFGR_PRIVC0_B_0X1		(0x1u<<16)
#define	RISAF_REG15_CFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG15_CFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG15_CFGR_BREN_B_0X0			(0x0u<<0)
#define	RISAF_REG15_CFGR_BREN_B_0X1			(0x1u<<0)

// REG15_STARTR Configuration

#define	RISAF_REG15_STARTR_BADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG15_STARTR_BADDSTART_0		(0x1u<<0)

// REG15_ENDR Configuration

#define	RISAF_REG15_ENDR_BADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG15_ENDR_BADDEND_0			(0x1u<<0)

// REG15_CIDCFGR Configuration

#define	RISAF_REG15_CIDCFGR_WRENC7			(0x1u<<23)
#define	RISAF_REG15_CIDCFGR_WRENC6			(0x1u<<22)
#define	RISAF_REG15_CIDCFGR_WRENC5			(0x1u<<21)
#define	RISAF_REG15_CIDCFGR_WRENC4			(0x1u<<20)
#define	RISAF_REG15_CIDCFGR_WRENC3			(0x1u<<19)
#define	RISAF_REG15_CIDCFGR_WRENC2			(0x1u<<18)
#define	RISAF_REG15_CIDCFGR_WRENC1			(0x1u<<17)
#define	RISAF_REG15_CIDCFGR_WRENC0			(0x1u<<16)
#define	RISAF_REG15_CIDCFGR_RDENC7			(0x1u<<7)
#define	RISAF_REG15_CIDCFGR_RDENC6			(0x1u<<6)
#define	RISAF_REG15_CIDCFGR_RDENC5			(0x1u<<5)
#define	RISAF_REG15_CIDCFGR_RDENC4			(0x1u<<4)
#define	RISAF_REG15_CIDCFGR_RDENC3			(0x1u<<3)
#define	RISAF_REG15_CIDCFGR_RDENC2			(0x1u<<2)
#define	RISAF_REG15_CIDCFGR_RDENC1			(0x1u<<1)
#define	RISAF_REG15_CIDCFGR_RDENC0			(0x1u<<0)

#define	RISAF_REG15_CIDCFGR_WRENC7_B_0X0	(0x0u<<23)
#define	RISAF_REG15_CIDCFGR_WRENC7_B_0X1	(0x1u<<23)
#define	RISAF_REG15_CIDCFGR_WRENC6_B_0X0	(0x0u<<22)
#define	RISAF_REG15_CIDCFGR_WRENC6_B_0X1	(0x1u<<22)
#define	RISAF_REG15_CIDCFGR_WRENC5_B_0X0	(0x0u<<21)
#define	RISAF_REG15_CIDCFGR_WRENC5_B_0X1	(0x1u<<21)
#define	RISAF_REG15_CIDCFGR_WRENC4_B_0X0	(0x0u<<20)
#define	RISAF_REG15_CIDCFGR_WRENC4_B_0X1	(0x1u<<20)
#define	RISAF_REG15_CIDCFGR_WRENC3_B_0X0	(0x0u<<19)
#define	RISAF_REG15_CIDCFGR_WRENC3_B_0X1	(0x1u<<19)
#define	RISAF_REG15_CIDCFGR_WRENC2_B_0X0	(0x0u<<18)
#define	RISAF_REG15_CIDCFGR_WRENC2_B_0X1	(0x1u<<18)
#define	RISAF_REG15_CIDCFGR_WRENC1_B_0X0	(0x0u<<17)
#define	RISAF_REG15_CIDCFGR_WRENC1_B_0X1	(0x1u<<17)
#define	RISAF_REG15_CIDCFGR_WRENC0_B_0X0	(0x0u<<16)
#define	RISAF_REG15_CIDCFGR_WRENC0_B_0X1	(0x1u<<16)
#define	RISAF_REG15_CIDCFGR_RDENC7_B_0X0	(0x0u<<7)
#define	RISAF_REG15_CIDCFGR_RDENC7_B_0X1	(0x1u<<7)
#define	RISAF_REG15_CIDCFGR_RDENC6_B_0X0	(0x0u<<6)
#define	RISAF_REG15_CIDCFGR_RDENC6_B_0X1	(0x1u<<6)
#define	RISAF_REG15_CIDCFGR_RDENC5_B_0X0	(0x0u<<5)
#define	RISAF_REG15_CIDCFGR_RDENC5_B_0X1	(0x1u<<5)
#define	RISAF_REG15_CIDCFGR_RDENC4_B_0X0	(0x0u<<4)
#define	RISAF_REG15_CIDCFGR_RDENC4_B_0X1	(0x1u<<4)
#define	RISAF_REG15_CIDCFGR_RDENC3_B_0X0	(0x0u<<3)
#define	RISAF_REG15_CIDCFGR_RDENC3_B_0X1	(0x1u<<3)
#define	RISAF_REG15_CIDCFGR_RDENC2_B_0X0	(0x0u<<2)
#define	RISAF_REG15_CIDCFGR_RDENC2_B_0X1	(0x1u<<2)
#define	RISAF_REG15_CIDCFGR_RDENC1_B_0X0	(0x0u<<1)
#define	RISAF_REG15_CIDCFGR_RDENC1_B_0X1	(0x1u<<1)
#define	RISAF_REG15_CIDCFGR_RDENC0_B_0X0	(0x0u<<0)
#define	RISAF_REG15_CIDCFGR_RDENC0_B_0X1	(0x1u<<0)

// REG15_ACFGR Configuration

#define	RISAF_REG15_ACFGR_WREN				(0x1u<<13)
#define	RISAF_REG15_ACFGR_RDEN				(0x1u<<12)
#define	RISAF_REG15_ACFGR_PRIV				(0x1u<<9)
#define	RISAF_REG15_ACFGR_SEC				(0x1u<<8)
#define	RISAF_REG15_ACFGR_SRCID				(0x7u<<4)
#define	RISAF_REG15_ACFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG15_ACFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG15_ACFGR_SREN				(0x1u<<0)

#define	RISAF_REG15_ACFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG15_ACFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG15_ACFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG15_ACFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG15_ACFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG15_ACFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG15_ACFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG15_ACFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG15_ACFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG15_ACFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG15_ACFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG15_ACFGR_SREN_B_0X1		(0x1u<<0)

// REG15_ASTARTR Configuration

#define	RISAF_REG15_ASTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG15_ASTARTR_SADDSTART_0		(0x1u<<0)

// REG15_AENDR Configuration

#define	RISAF_REG15_AENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG15_AENDR_SADDEND_0			(0x1u<<0)

// REG15_ANESTR Configuration

#define	RISAF_REG15_ANESTR_DCEN				(0x1u<<2)

#define	RISAF_REG15_ANESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG15_ANESTR_DCEN_B_0X1		(0x1u<<2)

// REG15_BCFGR Configuration

#define	RISAF_REG15_BCFGR_WREN				(0x1u<<13)
#define	RISAF_REG15_BCFGR_RDEN				(0x1u<<12)
#define	RISAF_REG15_BCFGR_PRIV				(0x1u<<9)
#define	RISAF_REG15_BCFGR_SEC				(0x1u<<8)
#define	RISAF_REG15_BCFGR_SRCID				(0x7u<<4)
#define	RISAF_REG15_BCFGR_SRCID_0			(0x1u<<4)
#define	RISAF_REG15_BCFGR_RLOCK				(0x1u<<1)
#define	RISAF_REG15_BCFGR_SREN				(0x1u<<0)

#define	RISAF_REG15_BCFGR_WREN_B_0X0		(0x0u<<13)
#define	RISAF_REG15_BCFGR_WREN_B_0X1		(0x1u<<13)
#define	RISAF_REG15_BCFGR_RDEN_B_0X0		(0x0u<<12)
#define	RISAF_REG15_BCFGR_RDEN_B_0X1		(0x1u<<12)
#define	RISAF_REG15_BCFGR_PRIV_B_0X0		(0x0u<<9)
#define	RISAF_REG15_BCFGR_PRIV_B_0X1		(0x1u<<9)
#define	RISAF_REG15_BCFGR_SEC_B_0X0			(0x0u<<8)
#define	RISAF_REG15_BCFGR_SEC_B_0X1			(0x1u<<8)
#define	RISAF_REG15_BCFGR_RLOCK_B_0X0		(0x0u<<1)
#define	RISAF_REG15_BCFGR_RLOCK_B_0X1		(0x1u<<1)
#define	RISAF_REG15_BCFGR_SREN_B_0X0		(0x0u<<0)
#define	RISAF_REG15_BCFGR_SREN_B_0X1		(0x1u<<0)

// REG15_BSTARTR Configuration

#define	RISAF_REG15_BSTARTR_SADDSTART		(0xFFFFFFFFu<<0)
#define	RISAF_REG15_BSTARTR_SADDSTART_0		(0x1u<<0)

// REG15_BENDR Configuration

#define	RISAF_REG15_BENDR_SADDEND			(0xFFFFFFFFu<<0)
#define	RISAF_REG15_BENDR_SADDEND_0			(0x1u<<0)

// REG15_BNESTR Configuration

#define	RISAF_REG15_BNESTR_DCEN				(0x1u<<2)

#define	RISAF_REG15_BNESTR_DCEN_B_0X0		(0x0u<<2)
#define	RISAF_REG15_BNESTR_DCEN_B_0X1		(0x1u<<2)
