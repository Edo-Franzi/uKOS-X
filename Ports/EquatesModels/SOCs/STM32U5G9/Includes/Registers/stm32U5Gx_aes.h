/*
; stm32U5Gx_aes.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_aes equates.
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

// AES address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	DINR;
	volatile	uint32_t	DOUTR;
	volatile	uint32_t	KEYR0;
	volatile	uint32_t	KEYR1;
	volatile	uint32_t	KEYR2;
	volatile	uint32_t	KEYR3;
	volatile	uint32_t	IVR0;
	volatile	uint32_t	IVR1;
	volatile	uint32_t	IVR2;
	volatile	uint32_t	IVR3;
	volatile	uint32_t	KEYR4;
	volatile	uint32_t	KEYR5;
	volatile	uint32_t	KEYR6;
	volatile	uint32_t	KEYR7;
	volatile	uint32_t	SUSP0R;
	volatile	uint32_t	SUSP1R;
	volatile	uint32_t	SUSP2R;
	volatile	uint32_t	SUSP3R;
	volatile	uint32_t	SUSP4R;
	volatile	uint32_t	SUSP5R;
	volatile	uint32_t	SUSP6R;
	volatile	uint32_t	SUSP7R;
	volatile	uint32_t	RESERVED0[168];
	volatile	uint32_t	IER;
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
} AES_TypeDef;

#if (defined(__cplusplus))
#define	AES_NS	reinterpret_cast<AES_TypeDef *>(0x420C0000u)
#define	AES_S	reinterpret_cast<AES_TypeDef *>(0x520C0000u)

#else
#define	AES_NS	((AES_TypeDef *)0x420C0000u)
#define	AES_S	((AES_TypeDef *)0x520C0000u)
#endif

// CR Configuration

#define	AES_CR_EN				(0x1u<<0)
#define	AES_CR_DATATYPE			(0x3u<<1)
#define	AES_CR_DATATYPE_0		(0x1u<<1)
#define	AES_CR_MODE				(0x3u<<3)
#define	AES_CR_MODE_0			(0x1u<<3)
#define	AES_CR_CHMOD			(0x3u<<5)
#define	AES_CR_CHMOD_0			(0x1u<<5)
#define	AES_CR_DMAINEN			(0x1u<<11)
#define	AES_CR_DMAOUTEN			(0x1u<<12)
#define	AES_CR_GCMPH			(0x3u<<13)
#define	AES_CR_GCMPH_0			(0x1u<<13)
#define	AES_CR_CHMOD_2			(0x1u<<16)
#define	AES_CR_KEYSIZE			(0x1u<<18)
#define	AES_CR_NPBLB			(0xFu<<20)
#define	AES_CR_NPBLB_0			(0x1u<<20)
#define	AES_CR_KMOD				(0x3u<<24)
#define	AES_CR_KMOD_0			(0x1u<<24)
#define	AES_CR_IPRST			(0x1u<<31)

// SR Configuration

#define	AES_SR_CCF				(0x1u<<0)
#define	AES_SR_RDERR			(0x1u<<1)
#define	AES_SR_WRERR			(0x1u<<2)
#define	AES_SR_BUSY				(0x1u<<3)
#define	AES_SR_KEYVALID			(0x1u<<7)

// DINR Configuration

#define	AES_DINR_DIN			(0xFFFFFFFFu<<0)
#define	AES_DINR_DIN_0			(0x1u<<0)

// DOUTR Configuration

#define	AES_DOUTR_DOUT			(0xFFFFFFFFu<<0)
#define	AES_DOUTR_DOUT_0		(0x1u<<0)

// KEYR0 Configuration

#define	AES_KEYR0_KEY			(0xFFFFFFFFu<<0)
#define	AES_KEYR0_KEY_0			(0x1u<<0)

// KEYR1 Configuration

#define	AES_KEYR1_KEY			(0xFFFFFFFFu<<0)
#define	AES_KEYR1_KEY_0			(0x1u<<0)

// KEYR2 Configuration

#define	AES_KEYR2_KEYR			(0xFFFFFFFFu<<0)
#define	AES_KEYR2_KEYR_0		(0x1u<<0)

// KEYR3 Configuration

#define	AES_KEYR3_AES_KEYR3		(0xFFFFFFFFu<<0)
#define	AES_KEYR3_AES_KEYR3_0	(0x1u<<0)

// IVR0 Configuration

#define	AES_IVR0_IVI			(0xFFFFFFFFu<<0)
#define	AES_IVR0_IVI_0			(0x1u<<0)

// IVR1 Configuration

#define	AES_IVR1_IVI			(0xFFFFFFFFu<<0)
#define	AES_IVR1_IVI_0			(0x1u<<0)

// IVR2 Configuration

#define	AES_IVR2_IVI			(0xFFFFFFFFu<<0)
#define	AES_IVR2_IVI_0			(0x1u<<0)

// IVR3 Configuration

#define	AES_IVR3_IVI			(0xFFFFFFFFu<<0)
#define	AES_IVR3_IVI_0			(0x1u<<0)

// KEYR4 Configuration

#define	AES_KEYR4_KEY			(0xFFFFFFFFu<<0)
#define	AES_KEYR4_KEY_0			(0x1u<<0)

// KEYR5 Configuration

#define	AES_KEYR5_KEY			(0xFFFFFFFFu<<0)
#define	AES_KEYR5_KEY_0			(0x1u<<0)

// KEYR6 Configuration

#define	AES_KEYR6_KEY			(0xFFFFFFFFu<<0)
#define	AES_KEYR6_KEY_0			(0x1u<<0)

// KEYR7 Configuration

#define	AES_KEYR7_KEY			(0xFFFFFFFFu<<0)
#define	AES_KEYR7_KEY_0			(0x1u<<0)

// SUSP0R Configuration

#define	AES_SUSP0R_SUSP0		(0xFFFFFFFFu<<0)
#define	AES_SUSP0R_SUSP0_0		(0x1u<<0)

// SUSP1R Configuration

#define	AES_SUSP1R_SUSP1		(0xFFFFFFFFu<<0)
#define	AES_SUSP1R_SUSP1_0		(0x1u<<0)

// SUSP2R Configuration

#define	AES_SUSP2R_SUSP2		(0xFFFFFFFFu<<0)
#define	AES_SUSP2R_SUSP2_0		(0x1u<<0)

// SUSP3R Configuration

#define	AES_SUSP3R_SUSP3		(0xFFFFFFFFu<<0)
#define	AES_SUSP3R_SUSP3_0		(0x1u<<0)

// SUSP4R Configuration

#define	AES_SUSP4R_SUSP4		(0xFFFFFFFFu<<0)
#define	AES_SUSP4R_SUSP4_0		(0x1u<<0)

// SUSP5R Configuration

#define	AES_SUSP5R_SUSP5		(0xFFFFFFFFu<<0)
#define	AES_SUSP5R_SUSP5_0		(0x1u<<0)

// SUSP6R Configuration

#define	AES_SUSP6R_SUSP6		(0xFFFFFFFFu<<0)
#define	AES_SUSP6R_SUSP6_0		(0x1u<<0)

// SUSP7R Configuration

#define	AES_SUSP7R_SUSP7		(0xFFFFFFFFu<<0)
#define	AES_SUSP7R_SUSP7_0		(0x1u<<0)

// IER Configuration

#define	AES_IER_CCFIE			(0x1u<<0)
#define	AES_IER_RWEIE			(0x1u<<1)
#define	AES_IER_KEIE			(0x1u<<2)

// ISR Configuration

#define	AES_ISR_CCF				(0x1u<<0)
#define	AES_ISR_RWEIF			(0x1u<<1)
#define	AES_ISR_KEIF			(0x1u<<2)

// ICR Configuration

#define	AES_ICR_CCF				(0x1u<<0)
#define	AES_ICR_RWEIF			(0x1u<<1)
#define	AES_ICR_KEIF			(0x1u<<2)
