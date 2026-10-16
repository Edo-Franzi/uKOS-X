/*
; stm32U5Gx_lpgpio.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_lpgpio equates.
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

// LPGPIO address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	MODER;
	volatile	uint32_t	RESERVED0[3];
	volatile	uint32_t	IDR;
	volatile	uint32_t	ODR;
	volatile	uint32_t	BSRR;
	volatile	uint32_t	RESERVED1[3];
	volatile	uint32_t	BRR;
} LPGPIO_TypeDef;

#if (defined(__cplusplus))
#define	LPGPIO1_NS	reinterpret_cast<LPGPIO_TypeDef *>(0x46020000u)
#define	LPGPIO1_S	reinterpret_cast<LPGPIO_TypeDef *>(0x56020000u)

#else
#define	LPGPIO1_NS	((LPGPIO_TypeDef *)0x46020000u)
#define	LPGPIO1_S	((LPGPIO_TypeDef *)0x56020000u)
#endif

// MODER Configuration

#define	LPGPIO_MODER_MODE0	(0x1u<<0)
#define	LPGPIO_MODER_MODE1	(0x1u<<1)
#define	LPGPIO_MODER_MODE2	(0x1u<<2)
#define	LPGPIO_MODER_MODE3	(0x1u<<3)
#define	LPGPIO_MODER_MODE4	(0x1u<<4)
#define	LPGPIO_MODER_MODE5	(0x1u<<5)
#define	LPGPIO_MODER_MODE6	(0x1u<<6)
#define	LPGPIO_MODER_MODE7	(0x1u<<7)
#define	LPGPIO_MODER_MODE8	(0x1u<<8)
#define	LPGPIO_MODER_MODE9	(0x1u<<9)
#define	LPGPIO_MODER_MODE10	(0x1u<<10)
#define	LPGPIO_MODER_MODE11	(0x1u<<11)
#define	LPGPIO_MODER_MODE12	(0x1u<<12)
#define	LPGPIO_MODER_MODE13	(0x1u<<13)
#define	LPGPIO_MODER_MODE14	(0x1u<<14)
#define	LPGPIO_MODER_MODE15	(0x1u<<15)

// IDR Configuration

#define	LPGPIO_IDR_ID0		(0x1u<<0)
#define	LPGPIO_IDR_ID1		(0x1u<<1)
#define	LPGPIO_IDR_ID2		(0x1u<<2)
#define	LPGPIO_IDR_ID3		(0x1u<<3)
#define	LPGPIO_IDR_ID4		(0x1u<<4)
#define	LPGPIO_IDR_ID5		(0x1u<<5)
#define	LPGPIO_IDR_ID6		(0x1u<<6)
#define	LPGPIO_IDR_ID7		(0x1u<<7)
#define	LPGPIO_IDR_ID8		(0x1u<<8)
#define	LPGPIO_IDR_ID9		(0x1u<<9)
#define	LPGPIO_IDR_ID10		(0x1u<<10)
#define	LPGPIO_IDR_ID11		(0x1u<<11)
#define	LPGPIO_IDR_ID12		(0x1u<<12)
#define	LPGPIO_IDR_ID13		(0x1u<<13)
#define	LPGPIO_IDR_ID14		(0x1u<<14)
#define	LPGPIO_IDR_ID15		(0x1u<<15)

// ODR Configuration

#define	LPGPIO_ODR_OD0		(0x1u<<0)
#define	LPGPIO_ODR_OD1		(0x1u<<1)
#define	LPGPIO_ODR_OD2		(0x1u<<2)
#define	LPGPIO_ODR_OD3		(0x1u<<3)
#define	LPGPIO_ODR_OD4		(0x1u<<4)
#define	LPGPIO_ODR_OD5		(0x1u<<5)
#define	LPGPIO_ODR_OD6		(0x1u<<6)
#define	LPGPIO_ODR_OD7		(0x1u<<7)
#define	LPGPIO_ODR_OD8		(0x1u<<8)
#define	LPGPIO_ODR_OD9		(0x1u<<9)
#define	LPGPIO_ODR_OD10		(0x1u<<10)
#define	LPGPIO_ODR_OD11		(0x1u<<11)
#define	LPGPIO_ODR_OD12		(0x1u<<12)
#define	LPGPIO_ODR_OD13		(0x1u<<13)
#define	LPGPIO_ODR_OD14		(0x1u<<14)
#define	LPGPIO_ODR_OD15		(0x1u<<15)

// BSRR Configuration

#define	LPGPIO_BSRR_BS0		(0x1u<<0)
#define	LPGPIO_BSRR_BS1		(0x1u<<1)
#define	LPGPIO_BSRR_BS2		(0x1u<<2)
#define	LPGPIO_BSRR_BS3		(0x1u<<3)
#define	LPGPIO_BSRR_BS4		(0x1u<<4)
#define	LPGPIO_BSRR_BS5		(0x1u<<5)
#define	LPGPIO_BSRR_BS6		(0x1u<<6)
#define	LPGPIO_BSRR_BS7		(0x1u<<7)
#define	LPGPIO_BSRR_BS8		(0x1u<<8)
#define	LPGPIO_BSRR_BS9		(0x1u<<9)
#define	LPGPIO_BSRR_BS10	(0x1u<<10)
#define	LPGPIO_BSRR_BS11	(0x1u<<11)
#define	LPGPIO_BSRR_BS12	(0x1u<<12)
#define	LPGPIO_BSRR_BS13	(0x1u<<13)
#define	LPGPIO_BSRR_BS14	(0x1u<<14)
#define	LPGPIO_BSRR_BS15	(0x1u<<15)
#define	LPGPIO_BSRR_BR0		(0x1u<<16)
#define	LPGPIO_BSRR_BR1		(0x1u<<17)
#define	LPGPIO_BSRR_BR2		(0x1u<<18)
#define	LPGPIO_BSRR_BR3		(0x1u<<19)
#define	LPGPIO_BSRR_BR4		(0x1u<<20)
#define	LPGPIO_BSRR_BR5		(0x1u<<21)
#define	LPGPIO_BSRR_BR6		(0x1u<<22)
#define	LPGPIO_BSRR_BR7		(0x1u<<23)
#define	LPGPIO_BSRR_BR8		(0x1u<<24)
#define	LPGPIO_BSRR_BR9		(0x1u<<25)
#define	LPGPIO_BSRR_BR10	(0x1u<<26)
#define	LPGPIO_BSRR_BR11	(0x1u<<27)
#define	LPGPIO_BSRR_BR12	(0x1u<<28)
#define	LPGPIO_BSRR_BR13	(0x1u<<29)
#define	LPGPIO_BSRR_BR14	(0x1u<<30)
#define	LPGPIO_BSRR_BR15	(0x1u<<31)

// BRR Configuration

#define	LPGPIO_BRR_BR0		(0x1u<<0)
#define	LPGPIO_BRR_BR1		(0x1u<<1)
#define	LPGPIO_BRR_BR2		(0x1u<<2)
#define	LPGPIO_BRR_BR3		(0x1u<<3)
#define	LPGPIO_BRR_BR4		(0x1u<<4)
#define	LPGPIO_BRR_BR5		(0x1u<<5)
#define	LPGPIO_BRR_BR6		(0x1u<<6)
#define	LPGPIO_BRR_BR7		(0x1u<<7)
#define	LPGPIO_BRR_BR8		(0x1u<<8)
#define	LPGPIO_BRR_BR9		(0x1u<<9)
#define	LPGPIO_BRR_BR10		(0x1u<<10)
#define	LPGPIO_BRR_BR11		(0x1u<<11)
#define	LPGPIO_BRR_BR12		(0x1u<<12)
#define	LPGPIO_BRR_BR13		(0x1u<<13)
#define	LPGPIO_BRR_BR14		(0x1u<<14)
#define	LPGPIO_BRR_BR15		(0x1u<<15)
