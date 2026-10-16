/*
; stm32H757_CM7_jpeg.
; ===================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H757_CM7_jpeg equates.
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

// JPEG address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CONFR0;
	volatile	uint32_t	CONFR1;
	volatile	uint32_t	CONFR2;
	volatile	uint32_t	CONFR3;
	volatile	uint32_t	CONFRN1;
	volatile	uint32_t	CONFRN2;
	volatile	uint32_t	CONFRN3;
	volatile	uint32_t	CONFRN4;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	CFR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	DIR;
	volatile	uint32_t	DOR;
} JPEG_TypeDef;

#if (defined(__cplusplus))
#define	JPEG	reinterpret_cast<JPEG_TypeDef *>(0x52003000u)

#else
#define	JPEG	((JPEG_TypeDef *)0x52003000u)
#endif

// CONFR0 Configuration

#define	JPEG_CONFR0_START			(0x1u<<0)

// CONFR1 Configuration

#define	JPEG_CONFR1_YSIZE			(0xFFFFu<<16)
#define	JPEG_CONFR1_YSIZE_0			(0x1u<<16)
#define	JPEG_CONFR1_HDR				(0x1u<<8)
#define	JPEG_CONFR1_NS				(0x3u<<6)
#define	JPEG_CONFR1_NS_0			(0x1u<<6)
#define	JPEG_CONFR1_COLORSPACE		(0x3u<<4)
#define	JPEG_CONFR1_COLORSPACE_0	(0x1u<<4)
#define	JPEG_CONFR1_DE				(0x1u<<3)
#define	JPEG_CONFR1_NF				(0x3u<<0)
#define	JPEG_CONFR1_NF_0			(0x1u<<0)

// CONFR2 Configuration

#define	JPEG_CONFR2_NMCU			(0x3FFFFFFu<<0)
#define	JPEG_CONFR2_NMCU_0			(0x1u<<0)

// CONFR3 Configuration

#define	JPEG_CONFR3_XSIZE			(0xFFFFu<<16)
#define	JPEG_CONFR3_XSIZE_0			(0x1u<<16)

// CONFRN1 Configuration

#define	JPEG_CONFRN1_HSF			(0xFu<<12)
#define	JPEG_CONFRN1_HSF_0			(0x1u<<12)
#define	JPEG_CONFRN1_VSF			(0xFu<<8)
#define	JPEG_CONFRN1_VSF_0			(0x1u<<8)
#define	JPEG_CONFRN1_NB				(0xFu<<4)
#define	JPEG_CONFRN1_NB_0			(0x1u<<4)
#define	JPEG_CONFRN1_QT				(0x3u<<2)
#define	JPEG_CONFRN1_QT_0			(0x1u<<2)
#define	JPEG_CONFRN1_HA				(0x1u<<1)
#define	JPEG_CONFRN1_HD				(0x1u<<0)

// CONFRN2 Configuration

#define	JPEG_CONFRN2_HSF			(0xFu<<12)
#define	JPEG_CONFRN2_HSF_0			(0x1u<<12)
#define	JPEG_CONFRN2_VSF			(0xFu<<8)
#define	JPEG_CONFRN2_VSF_0			(0x1u<<8)
#define	JPEG_CONFRN2_NB				(0xFu<<4)
#define	JPEG_CONFRN2_NB_0			(0x1u<<4)
#define	JPEG_CONFRN2_QT				(0x3u<<2)
#define	JPEG_CONFRN2_QT_0			(0x1u<<2)
#define	JPEG_CONFRN2_HA				(0x1u<<1)
#define	JPEG_CONFRN2_HD				(0x1u<<0)

// CONFRN3 Configuration

#define	JPEG_CONFRN3_HSF			(0xFu<<12)
#define	JPEG_CONFRN3_HSF_0			(0x1u<<12)
#define	JPEG_CONFRN3_VSF			(0xFu<<8)
#define	JPEG_CONFRN3_VSF_0			(0x1u<<8)
#define	JPEG_CONFRN3_NB				(0xFu<<4)
#define	JPEG_CONFRN3_NB_0			(0x1u<<4)
#define	JPEG_CONFRN3_QT				(0x3u<<2)
#define	JPEG_CONFRN3_QT_0			(0x1u<<2)
#define	JPEG_CONFRN3_HA				(0x1u<<1)
#define	JPEG_CONFRN3_HD				(0x1u<<0)

// CONFRN4 Configuration

#define	JPEG_CONFRN4_HSF			(0xFu<<12)
#define	JPEG_CONFRN4_HSF_0			(0x1u<<12)
#define	JPEG_CONFRN4_VSF			(0xFu<<8)
#define	JPEG_CONFRN4_VSF_0			(0x1u<<8)
#define	JPEG_CONFRN4_NB				(0xFu<<4)
#define	JPEG_CONFRN4_NB_0			(0x1u<<4)
#define	JPEG_CONFRN4_QT				(0x3u<<2)
#define	JPEG_CONFRN4_QT_0			(0x1u<<2)
#define	JPEG_CONFRN4_HA				(0x1u<<1)
#define	JPEG_CONFRN4_HD				(0x1u<<0)

// CR Configuration

#define	JPEG_CR_OFF					(0x1u<<14)
#define	JPEG_CR_IFF					(0x1u<<13)
#define	JPEG_CR_ODMAEN				(0x1u<<12)
#define	JPEG_CR_IDMAEN				(0x1u<<11)
#define	JPEG_CR_HPDIE				(0x1u<<6)
#define	JPEG_CR_EOCIE				(0x1u<<5)
#define	JPEG_CR_OFNEIE				(0x1u<<4)
#define	JPEG_CR_OFTIE				(0x1u<<3)
#define	JPEG_CR_IFNFIE				(0x1u<<2)
#define	JPEG_CR_IFTIE				(0x1u<<1)
#define	JPEG_CR_JCEN				(0x1u<<0)

// SR Configuration

#define	JPEG_SR_COF					(0x1u<<7)
#define	JPEG_SR_HPDF				(0x1u<<6)
#define	JPEG_SR_EOCF				(0x1u<<5)
#define	JPEG_SR_OFNEF				(0x1u<<4)
#define	JPEG_SR_OFTF				(0x1u<<3)
#define	JPEG_SR_IFNFF				(0x1u<<2)
#define	JPEG_SR_IFTF				(0x1u<<1)

// CFR Configuration

#define	JPEG_CFR_CHPDF				(0x1u<<6)
#define	JPEG_CFR_CEOCF				(0x1u<<5)

// DIR Configuration

#define	JPEG_DIR_DATAIN				(0xFFFFFFFFu<<0)
#define	JPEG_DIR_DATAIN_0			(0x1u<<0)

// DOR Configuration

#define	JPEG_DOR_DATAOUT			(0xFFFFFFFFu<<0)
#define	JPEG_DOR_DATAOUT_0			(0x1u<<0)
