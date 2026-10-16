/*
; stm32U5Gx_gtzc2_mpcbb4.
; =======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_gtzc2_mpcbb4 equates.
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

// GTZC2_MPCBB4 address definitions
// --------------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	RESERVED0[3];
	volatile	uint32_t	CFGLOCK;
	volatile	uint32_t	RESERVED1[59];
	volatile	uint32_t	SECCFGR0;
	volatile	uint32_t	RESERVED2[63];
	volatile	uint32_t	PRIVCFGR0;
} GTZC2_MPCBB4_TypeDef;

#if (defined(__cplusplus))
#define	GTZC2_MPCBB4_NS	reinterpret_cast<GTZC2_MPCBB4_TypeDef *>(0x46023800u)
#define	GTZC2_MPCBB4_S	reinterpret_cast<GTZC2_MPCBB4_TypeDef *>(0x56023800u)

#else
#define	GTZC2_MPCBB4_NS	((GTZC2_MPCBB4_TypeDef *)0x46023800u)
#define	GTZC2_MPCBB4_S	((GTZC2_MPCBB4_TypeDef *)0x56023800u)
#endif

// CR Configuration

#define	GTZC2_MPCBB4_CR_SRWILADIS		(0x1u<<31)
#define	GTZC2_MPCBB4_CR_INVSECSTATE		(0x1u<<30)
#define	GTZC2_MPCBB4_CR_GLOCK			(0x1u<<0)

// CFGLOCK Configuration

#define	GTZC2_MPCBB4_CFGLOCK_SPLCK0		(0x1u<<0)

// SECCFGR0 Configuration

#define	GTZC2_MPCBB4_SECCFGR0_SEC31		(0x1u<<31)
#define	GTZC2_MPCBB4_SECCFGR0_SEC30		(0x1u<<30)
#define	GTZC2_MPCBB4_SECCFGR0_SEC29		(0x1u<<29)
#define	GTZC2_MPCBB4_SECCFGR0_SEC28		(0x1u<<28)
#define	GTZC2_MPCBB4_SECCFGR0_SEC27		(0x1u<<27)
#define	GTZC2_MPCBB4_SECCFGR0_SEC26		(0x1u<<26)
#define	GTZC2_MPCBB4_SECCFGR0_SEC25		(0x1u<<25)
#define	GTZC2_MPCBB4_SECCFGR0_SEC24		(0x1u<<24)
#define	GTZC2_MPCBB4_SECCFGR0_SEC23		(0x1u<<23)
#define	GTZC2_MPCBB4_SECCFGR0_SEC22		(0x1u<<22)
#define	GTZC2_MPCBB4_SECCFGR0_SEC21		(0x1u<<21)
#define	GTZC2_MPCBB4_SECCFGR0_SEC20		(0x1u<<20)
#define	GTZC2_MPCBB4_SECCFGR0_SEC19		(0x1u<<19)
#define	GTZC2_MPCBB4_SECCFGR0_SEC18		(0x1u<<18)
#define	GTZC2_MPCBB4_SECCFGR0_SEC17		(0x1u<<17)
#define	GTZC2_MPCBB4_SECCFGR0_SEC16		(0x1u<<16)
#define	GTZC2_MPCBB4_SECCFGR0_SEC15		(0x1u<<15)
#define	GTZC2_MPCBB4_SECCFGR0_SEC14		(0x1u<<14)
#define	GTZC2_MPCBB4_SECCFGR0_SEC13		(0x1u<<13)
#define	GTZC2_MPCBB4_SECCFGR0_SEC12		(0x1u<<12)
#define	GTZC2_MPCBB4_SECCFGR0_SEC11		(0x1u<<11)
#define	GTZC2_MPCBB4_SECCFGR0_SEC10		(0x1u<<10)
#define	GTZC2_MPCBB4_SECCFGR0_SEC9		(0x1u<<9)
#define	GTZC2_MPCBB4_SECCFGR0_SEC8		(0x1u<<8)
#define	GTZC2_MPCBB4_SECCFGR0_SEC7		(0x1u<<7)
#define	GTZC2_MPCBB4_SECCFGR0_SEC6		(0x1u<<6)
#define	GTZC2_MPCBB4_SECCFGR0_SEC5		(0x1u<<5)
#define	GTZC2_MPCBB4_SECCFGR0_SEC4		(0x1u<<4)
#define	GTZC2_MPCBB4_SECCFGR0_SEC3		(0x1u<<3)
#define	GTZC2_MPCBB4_SECCFGR0_SEC2		(0x1u<<2)
#define	GTZC2_MPCBB4_SECCFGR0_SEC1		(0x1u<<1)
#define	GTZC2_MPCBB4_SECCFGR0_SEC0		(0x1u<<0)

// PRIVCFGR0 Configuration

#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV31	(0x1u<<31)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV30	(0x1u<<30)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV29	(0x1u<<29)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV28	(0x1u<<28)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV27	(0x1u<<27)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV26	(0x1u<<26)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV25	(0x1u<<25)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV24	(0x1u<<24)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV23	(0x1u<<23)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV22	(0x1u<<22)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV21	(0x1u<<21)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV20	(0x1u<<20)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV19	(0x1u<<19)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV18	(0x1u<<18)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV17	(0x1u<<17)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV16	(0x1u<<16)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV15	(0x1u<<15)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV14	(0x1u<<14)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV13	(0x1u<<13)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV12	(0x1u<<12)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV11	(0x1u<<11)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV10	(0x1u<<10)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV9	(0x1u<<9)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV8	(0x1u<<8)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV7	(0x1u<<7)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV6	(0x1u<<6)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV5	(0x1u<<5)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV4	(0x1u<<4)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV3	(0x1u<<3)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV2	(0x1u<<2)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV1	(0x1u<<1)
#define	GTZC2_MPCBB4_PRIVCFGR0_PRIV0	(0x1u<<0)
