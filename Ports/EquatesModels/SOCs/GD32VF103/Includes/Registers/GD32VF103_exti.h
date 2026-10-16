/*
; GD32VF103_exti.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_exti equates.
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

// EXTI address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	INTEN;
	volatile	uint32_t	EVEN;
	volatile	uint32_t	RTEN;
	volatile	uint32_t	FTEN;
	volatile	uint32_t	SWIEV;
	volatile	uint32_t	PD;
} EXTI_TypeDef;

#if (defined(__cplusplus))
#define	EXTI	reinterpret_cast<EXTI_TypeDef *>(0x40010400u)

#else
#define	EXTI	((EXTI_TypeDef *)0x40010400u)
#endif

// INTEN Configuration

#define	EXTI_INTEN_INTEN18	(0x1u<<18)
#define	EXTI_INTEN_INTEN17	(0x1u<<17)
#define	EXTI_INTEN_INTEN16	(0x1u<<16)
#define	EXTI_INTEN_INTEN15	(0x1u<<15)
#define	EXTI_INTEN_INTEN14	(0x1u<<14)
#define	EXTI_INTEN_INTEN13	(0x1u<<13)
#define	EXTI_INTEN_INTEN12	(0x1u<<12)
#define	EXTI_INTEN_INTEN11	(0x1u<<11)
#define	EXTI_INTEN_INTEN10	(0x1u<<10)
#define	EXTI_INTEN_INTEN9	(0x1u<<9)
#define	EXTI_INTEN_INTEN8	(0x1u<<8)
#define	EXTI_INTEN_INTEN7	(0x1u<<7)
#define	EXTI_INTEN_INTEN6	(0x1u<<6)
#define	EXTI_INTEN_INTEN5	(0x1u<<5)
#define	EXTI_INTEN_INTEN4	(0x1u<<4)
#define	EXTI_INTEN_INTEN3	(0x1u<<3)
#define	EXTI_INTEN_INTEN2	(0x1u<<2)
#define	EXTI_INTEN_INTEN1	(0x1u<<1)
#define	EXTI_INTEN_INTEN0	(0x1u<<0)

// EVEN Configuration

#define	EXTI_EVEN_EVEN18	(0x1u<<18)
#define	EXTI_EVEN_EVEN17	(0x1u<<17)
#define	EXTI_EVEN_EVEN16	(0x1u<<16)
#define	EXTI_EVEN_EVEN15	(0x1u<<15)
#define	EXTI_EVEN_EVEN14	(0x1u<<14)
#define	EXTI_EVEN_EVEN13	(0x1u<<13)
#define	EXTI_EVEN_EVEN12	(0x1u<<12)
#define	EXTI_EVEN_EVEN11	(0x1u<<11)
#define	EXTI_EVEN_EVEN10	(0x1u<<10)
#define	EXTI_EVEN_EVEN9		(0x1u<<9)
#define	EXTI_EVEN_EVEN8		(0x1u<<8)
#define	EXTI_EVEN_EVEN7		(0x1u<<7)
#define	EXTI_EVEN_EVEN6		(0x1u<<6)
#define	EXTI_EVEN_EVEN5		(0x1u<<5)
#define	EXTI_EVEN_EVEN4		(0x1u<<4)
#define	EXTI_EVEN_EVEN3		(0x1u<<3)
#define	EXTI_EVEN_EVEN2		(0x1u<<2)
#define	EXTI_EVEN_EVEN1		(0x1u<<1)
#define	EXTI_EVEN_EVEN0		(0x1u<<0)

// RTEN Configuration

#define	EXTI_RTEN_RTEN18	(0x1u<<18)
#define	EXTI_RTEN_RTEN17	(0x1u<<17)
#define	EXTI_RTEN_RTEN16	(0x1u<<16)
#define	EXTI_RTEN_RTEN15	(0x1u<<15)
#define	EXTI_RTEN_RTEN14	(0x1u<<14)
#define	EXTI_RTEN_RTEN13	(0x1u<<13)
#define	EXTI_RTEN_RTEN12	(0x1u<<12)
#define	EXTI_RTEN_RTEN11	(0x1u<<11)
#define	EXTI_RTEN_RTEN10	(0x1u<<10)
#define	EXTI_RTEN_RTEN9		(0x1u<<9)
#define	EXTI_RTEN_RTEN8		(0x1u<<8)
#define	EXTI_RTEN_RTEN7		(0x1u<<7)
#define	EXTI_RTEN_RTEN6		(0x1u<<6)
#define	EXTI_RTEN_RTEN5		(0x1u<<5)
#define	EXTI_RTEN_RTEN4		(0x1u<<4)
#define	EXTI_RTEN_RTEN3		(0x1u<<3)
#define	EXTI_RTEN_RTEN2		(0x1u<<2)
#define	EXTI_RTEN_RTEN1		(0x1u<<1)
#define	EXTI_RTEN_RTEN0		(0x1u<<0)

// FTEN Configuration

#define	EXTI_FTEN_FTEN18	(0x1u<<18)
#define	EXTI_FTEN_FTEN17	(0x1u<<17)
#define	EXTI_FTEN_FTEN16	(0x1u<<16)
#define	EXTI_FTEN_FTEN15	(0x1u<<15)
#define	EXTI_FTEN_FTEN14	(0x1u<<14)
#define	EXTI_FTEN_FTEN13	(0x1u<<13)
#define	EXTI_FTEN_FTEN12	(0x1u<<12)
#define	EXTI_FTEN_FTEN11	(0x1u<<11)
#define	EXTI_FTEN_FTEN10	(0x1u<<10)
#define	EXTI_FTEN_FTEN9		(0x1u<<9)
#define	EXTI_FTEN_FTEN8		(0x1u<<8)
#define	EXTI_FTEN_FTEN7		(0x1u<<7)
#define	EXTI_FTEN_FTEN6		(0x1u<<6)
#define	EXTI_FTEN_FTEN5		(0x1u<<5)
#define	EXTI_FTEN_FTEN4		(0x1u<<4)
#define	EXTI_FTEN_FTEN3		(0x1u<<3)
#define	EXTI_FTEN_FTEN2		(0x1u<<2)
#define	EXTI_FTEN_FTEN1		(0x1u<<1)
#define	EXTI_FTEN_FTEN0		(0x1u<<0)

// SWIEV Configuration

#define	EXTI_SWIEV_SWIEV18	(0x1u<<18)
#define	EXTI_SWIEV_SWIEV17	(0x1u<<17)
#define	EXTI_SWIEV_SWIEV16	(0x1u<<16)
#define	EXTI_SWIEV_SWIEV15	(0x1u<<15)
#define	EXTI_SWIEV_SWIEV14	(0x1u<<14)
#define	EXTI_SWIEV_SWIEV13	(0x1u<<13)
#define	EXTI_SWIEV_SWIEV12	(0x1u<<12)
#define	EXTI_SWIEV_SWIEV11	(0x1u<<11)
#define	EXTI_SWIEV_SWIEV10	(0x1u<<10)
#define	EXTI_SWIEV_SWIEV9	(0x1u<<9)
#define	EXTI_SWIEV_SWIEV8	(0x1u<<8)
#define	EXTI_SWIEV_SWIEV7	(0x1u<<7)
#define	EXTI_SWIEV_SWIEV6	(0x1u<<6)
#define	EXTI_SWIEV_SWIEV5	(0x1u<<5)
#define	EXTI_SWIEV_SWIEV4	(0x1u<<4)
#define	EXTI_SWIEV_SWIEV3	(0x1u<<3)
#define	EXTI_SWIEV_SWIEV2	(0x1u<<2)
#define	EXTI_SWIEV_SWIEV1	(0x1u<<1)
#define	EXTI_SWIEV_SWIEV0	(0x1u<<0)

// PD Configuration

#define	EXTI_PD_PD18		(0x1u<<18)
#define	EXTI_PD_PD17		(0x1u<<17)
#define	EXTI_PD_PD16		(0x1u<<16)
#define	EXTI_PD_PD15		(0x1u<<15)
#define	EXTI_PD_PD14		(0x1u<<14)
#define	EXTI_PD_PD13		(0x1u<<13)
#define	EXTI_PD_PD12		(0x1u<<12)
#define	EXTI_PD_PD11		(0x1u<<11)
#define	EXTI_PD_PD10		(0x1u<<10)
#define	EXTI_PD_PD9			(0x1u<<9)
#define	EXTI_PD_PD8			(0x1u<<8)
#define	EXTI_PD_PD7			(0x1u<<7)
#define	EXTI_PD_PD6			(0x1u<<6)
#define	EXTI_PD_PD5			(0x1u<<5)
#define	EXTI_PD_PD4			(0x1u<<4)
#define	EXTI_PD_PD3			(0x1u<<3)
#define	EXTI_PD_PD2			(0x1u<<2)
#define	EXTI_PD_PD1			(0x1u<<1)
#define	EXTI_PD_PD0			(0x1u<<0)
