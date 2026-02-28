/*
; icb.
; ====

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		ICB equates.
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

// ICB address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	ICTR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	ACTLR;
	volatile	uint32_t	CPPWR;
} ICB_TypeDef;

#if (defined(__cplusplus))
#define	ICB_S	reinterpret_cast<ICB_TypeDef *>(0xE000E004u)
#define	ICB_NS	reinterpret_cast<ICB_TypeDef *>(0xE000E004u)

#else
#define	ICB_S	((ICB_TypeDef *)0xE000E004u)
#define	ICB_NS	((ICB_TypeDef *)0xE000E004u)
#endif

// ICTR Configuration

#define	ICB_ICTR_INTLINESNUM		(0xFu<<0)
#define	ICB_ICTR_INTLINESNUM_0		(0x1u<<0)

// ACTLR Configuration

#define	ICB_ACTLR_DISCRITAXIRUW		(0x1u<<27)
#define	ICB_ACTLR_DISDI				(0x3u<<16)
#define	ICB_ACTLR_DISDI_0			(0x1u<<16)
#define	ICB_ACTLR_DISCRITAXIRUR		(0x1u<<15)
#define	ICB_ACTLR_EVENTBUSEN		(0x1u<<14)
#define	ICB_ACTLR_EVENTBUSEN_S		(0x1u<<13)
#define	ICB_ACTLR_DISITMATBFLUSH	(0x1u<<12)
#define	ICB_ACTLR_DISNWAMODE		(0x1u<<11)
#define	ICB_ACTLR_FPEXCODIS			(0x1u<<10)
#define	ICB_ACTLR_DISOLAP			(0x1u<<7)
#define	ICB_ACTLR_DISOLAPS			(0x1u<<6)
#define	ICB_ACTLR_DISLOBR			(0x1u<<5)
#define	ICB_ACTLR_DISLO				(0x1u<<4)
#define	ICB_ACTLR_DISLOLEP			(0x1u<<3)
#define	ICB_ACTLR_DISFOLD			(0x1u<<2)

// CPPWR Configuration

#define	ICB_CPPWR_SUS11				(0x1u<<23)
#define	ICB_CPPWR_SU11				(0x1u<<22)
#define	ICB_CPPWR_SUS10				(0x1u<<21)
#define	ICB_CPPWR_SU10				(0x1u<<20)
#define	ICB_CPPWR_SUS7				(0x1u<<15)
#define	ICB_CPPWR_SU7				(0x1u<<14)
#define	ICB_CPPWR_SUS6				(0x1u<<13)
#define	ICB_CPPWR_SU6				(0x1u<<12)
#define	ICB_CPPWR_SUS5				(0x1u<<11)
#define	ICB_CPPWR_SU5				(0x1u<<10)
#define	ICB_CPPWR_SUS4				(0x1u<<9)
#define	ICB_CPPWR_SU4				(0x1u<<8)
#define	ICB_CPPWR_SUS3				(0x1u<<7)
#define	ICB_CPPWR_SU3				(0x1u<<6)
#define	ICB_CPPWR_SUS2				(0x1u<<5)
#define	ICB_CPPWR_SU2				(0x1u<<4)
#define	ICB_CPPWR_SUS1				(0x1u<<3)
#define	ICB_CPPWR_SU1				(0x1u<<2)
#define	ICB_CPPWR_SUS0				(0x1u<<1)
#define	ICB_CPPWR_SU0				(0x1u<<0)

