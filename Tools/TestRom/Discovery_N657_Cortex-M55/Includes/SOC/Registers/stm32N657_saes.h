/*
; stm32N657_saes.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_saes equates.
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

// SAES address definitions
// ------------------------

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
	volatile	uint32_t	SUSPR0;
	volatile	uint32_t	SUSPR1;
	volatile	uint32_t	SUSPR2;
	volatile	uint32_t	SUSPR3;
	volatile	uint32_t	SUSPR4;
	volatile	uint32_t	SUSPR5;
	volatile	uint32_t	SUSPR6;
	volatile	uint32_t	SUSPR7;
	volatile	uint32_t	RESERVED0[168];
	volatile	uint32_t	IER;
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
} SAES_TypeDef;

#if (defined(__cplusplus))
#define	SAES_NS	reinterpret_cast<SAES_TypeDef *>(0x44021000u)
#define	SAES_S	reinterpret_cast<SAES_TypeDef *>(0x54021000u)

#else
#define	SAES_NS	((SAES_TypeDef *)0x44021000u)
#define	SAES_S	((SAES_TypeDef *)0x54021000u)
#endif

// CR Configuration

#define	SAES_CR_IPRST				(0x1u<<31)
#define	SAES_CR_KEYSEL				(0x7u<<28)
#define	SAES_CR_KEYSEL_0			(0x1u<<28)
#define	SAES_CR_KSHAREID			(0x3u<<26)
#define	SAES_CR_KSHAREID_0			(0x1u<<26)
#define	SAES_CR_KMOD				(0x3u<<24)
#define	SAES_CR_KMOD_0				(0x1u<<24)
#define	SAES_CR_NPBLB				(0xFu<<20)
#define	SAES_CR_NPBLB_0				(0x1u<<20)
#define	SAES_CR_KEYPROT				(0x1u<<19)
#define	SAES_CR_KEYSIZE				(0x1u<<18)
#define	SAES_CR_CHMOD_1				(0x1u<<16)
#define	SAES_CR_GCMPH				(0x3u<<13)
#define	SAES_CR_GCMPH_0				(0x1u<<13)
#define	SAES_CR_DMAOUTEN			(0x1u<<12)
#define	SAES_CR_DMAINEN				(0x1u<<11)
#define	SAES_CR_CHMOD				(0x3u<<5)
#define	SAES_CR_CHMOD_0				(0x1u<<5)
#define	SAES_CR_MODE				(0x3u<<3)
#define	SAES_CR_MODE_0				(0x1u<<3)
#define	SAES_CR_DATATYPE			(0x3u<<1)
#define	SAES_CR_DATATYPE_0			(0x1u<<1)
#define	SAES_CR_EN					(0x1u<<0)

#define	SAES_CR_KEYSEL_B_0X0		(0x0u<<28)
#define	SAES_CR_KEYSEL_B_0X1		(0x1u<<28)
#define	SAES_CR_KEYSEL_B_0X2		(0x2u<<28)
#define	SAES_CR_KEYSEL_B_0X4		(0x4u<<28)
#define	SAES_CR_KEYSEL_B_0X7		(0x7u<<28)
#define	SAES_CR_KSHAREID_B_0X0		(0x0u<<26)
#define	SAES_CR_KMOD_B_0X0			(0x0u<<24)
#define	SAES_CR_KMOD_B_0X1			(0x1u<<24)
#define	SAES_CR_KMOD_B_0X2			(0x2u<<24)
#define	SAES_CR_NPBLB_B_0X0			(0x0u<<20)
#define	SAES_CR_NPBLB_B_0X1			(0x1u<<20)
#define	SAES_CR_NPBLB_B_0XF			(0xFu<<20)
#define	SAES_CR_KEYPROT_B_0X0		(0x0u<<19)
#define	SAES_CR_KEYPROT_B_0X1		(0x1u<<19)
#define	SAES_CR_KEYSIZE_B_0X0		(0x0u<<18)
#define	SAES_CR_KEYSIZE_B_0X1		(0x1u<<18)
#define	SAES_CR_GCMPH_B_0X0			(0x0u<<13)
#define	SAES_CR_GCMPH_B_0X1			(0x1u<<13)
#define	SAES_CR_GCMPH_B_0X2			(0x2u<<13)
#define	SAES_CR_GCMPH_B_0X3			(0x3u<<13)
#define	SAES_CR_DMAOUTEN_B_0X0		(0x0u<<12)
#define	SAES_CR_DMAOUTEN_B_0X1		(0x1u<<12)
#define	SAES_CR_DMAINEN_B_0X0		(0x0u<<11)
#define	SAES_CR_DMAINEN_B_0X1		(0x1u<<11)
#define	SAES_CR_CHMOD_B_0X0			(0x0u<<5)
#define	SAES_CR_CHMOD_B_0X1			(0x1u<<5)
#define	SAES_CR_CHMOD_B_0X2			(0x2u<<5)
#define	SAES_CR_CHMOD_B_0X3			(0x3u<<5)
#define	SAES_CR_MODE_B_0X0			(0x0u<<3)
#define	SAES_CR_MODE_B_0X1			(0x1u<<3)
#define	SAES_CR_MODE_B_0X2			(0x2u<<3)
#define	SAES_CR_DATATYPE_B_0X0		(0x0u<<1)
#define	SAES_CR_DATATYPE_B_0X1		(0x1u<<1)
#define	SAES_CR_DATATYPE_B_0X2		(0x2u<<1)
#define	SAES_CR_DATATYPE_B_0X3		(0x3u<<1)
#define	SAES_CR_EN_B_0X0			(0x0u<<0)
#define	SAES_CR_EN_B_0X1			(0x1u<<0)

// SR Configuration

#define	SAES_SR_KEYVALID			(0x1u<<7)
#define	SAES_SR_BUSY				(0x1u<<3)
#define	SAES_SR_WRERRF				(0x1u<<2)
#define	SAES_SR_RDERRF				(0x1u<<1)

#define	SAES_SR_KEYVALID_B_0X0		(0x0u<<7)
#define	SAES_SR_KEYVALID_B_0X1		(0x1u<<7)
#define	SAES_SR_BUSY_B_0X0			(0x0u<<3)
#define	SAES_SR_BUSY_B_0X1			(0x1u<<3)
#define	SAES_SR_WRERRF_B_0X0		(0x0u<<2)
#define	SAES_SR_WRERRF_B_0X1		(0x1u<<2)
#define	SAES_SR_RDERRF_B_0X0		(0x0u<<1)
#define	SAES_SR_RDERRF_B_0X1		(0x1u<<1)

// DINR Configuration

#define	SAES_DINR_DIN				(0xFFFFFFFFu<<0)
#define	SAES_DINR_DIN_0				(0x1u<<0)

// DOUTR Configuration

#define	SAES_DOUTR_DOUT				(0xFFFFFFFFu<<0)
#define	SAES_DOUTR_DOUT_0			(0x1u<<0)

// KEYR0 Configuration

#define	SAES_KEYR0_KEY				(0xFFFFFFFFu<<0)
#define	SAES_KEYR0_KEY_0			(0x1u<<0)

// KEYR1 Configuration

#define	SAES_KEYR1_KEY				(0xFFFFFFFFu<<0)
#define	SAES_KEYR1_KEY_0			(0x1u<<0)

// KEYR2 Configuration

#define	SAES_KEYR2_KEY				(0xFFFFFFFFu<<0)
#define	SAES_KEYR2_KEY_0			(0x1u<<0)

// KEYR3 Configuration

#define	SAES_KEYR3_KEY				(0xFFFFFFFFu<<0)
#define	SAES_KEYR3_KEY_0			(0x1u<<0)

// IVR0 Configuration

#define	SAES_IVR0_IVI				(0xFFFFFFFFu<<0)
#define	SAES_IVR0_IVI_0				(0x1u<<0)

// IVR1 Configuration

#define	SAES_IVR1_IVI				(0xFFFFFFFFu<<0)
#define	SAES_IVR1_IVI_0				(0x1u<<0)

// IVR2 Configuration

#define	SAES_IVR2_IVI				(0xFFFFFFFFu<<0)
#define	SAES_IVR2_IVI_0				(0x1u<<0)

// IVR3 Configuration

#define	SAES_IVR3_IVI				(0xFFFFFFFFu<<0)
#define	SAES_IVR3_IVI_0				(0x1u<<0)

// KEYR4 Configuration

#define	SAES_KEYR4_KEY				(0xFFFFFFFFu<<0)
#define	SAES_KEYR4_KEY_0			(0x1u<<0)

// KEYR5 Configuration

#define	SAES_KEYR5_KEY				(0xFFFFFFFFu<<0)
#define	SAES_KEYR5_KEY_0			(0x1u<<0)

// KEYR6 Configuration

#define	SAES_KEYR6_KEY				(0xFFFFFFFFu<<0)
#define	SAES_KEYR6_KEY_0			(0x1u<<0)

// KEYR7 Configuration

#define	SAES_KEYR7_KEY				(0xFFFFFFFFu<<0)
#define	SAES_KEYR7_KEY_0			(0x1u<<0)

// SUSPR0 Configuration

#define	SAES_SUSPR0_SUSP			(0xFFFFFFFFu<<0)
#define	SAES_SUSPR0_SUSP_0			(0x1u<<0)

// SUSPR1 Configuration

#define	SAES_SUSPR1_SUSP			(0xFFFFFFFFu<<0)
#define	SAES_SUSPR1_SUSP_0			(0x1u<<0)

// SUSPR2 Configuration

#define	SAES_SUSPR2_SUSP			(0xFFFFFFFFu<<0)
#define	SAES_SUSPR2_SUSP_0			(0x1u<<0)

// SUSPR3 Configuration

#define	SAES_SUSPR3_SUSP			(0xFFFFFFFFu<<0)
#define	SAES_SUSPR3_SUSP_0			(0x1u<<0)

// SUSPR4 Configuration

#define	SAES_SUSPR4_SUSP			(0xFFFFFFFFu<<0)
#define	SAES_SUSPR4_SUSP_0			(0x1u<<0)

// SUSPR5 Configuration

#define	SAES_SUSPR5_SUSP			(0xFFFFFFFFu<<0)
#define	SAES_SUSPR5_SUSP_0			(0x1u<<0)

// SUSPR6 Configuration

#define	SAES_SUSPR6_SUSP			(0xFFFFFFFFu<<0)
#define	SAES_SUSPR6_SUSP_0			(0x1u<<0)

// SUSPR7 Configuration

#define	SAES_SUSPR7_SUSP			(0xFFFFFFFFu<<0)
#define	SAES_SUSPR7_SUSP_0			(0x1u<<0)

// IER Configuration

#define	SAES_IER_RNGEIE				(0x1u<<3)
#define	SAES_IER_KEIE				(0x1u<<2)
#define	SAES_IER_RWEIE				(0x1u<<1)
#define	SAES_IER_CCFIE				(0x1u<<0)

#define	SAES_IER_RNGEIE_B_0X0		(0x0u<<3)
#define	SAES_IER_RNGEIE_B_0X1		(0x1u<<3)
#define	SAES_IER_KEIE_B_0X0			(0x0u<<2)
#define	SAES_IER_KEIE_B_0X1			(0x1u<<2)
#define	SAES_IER_RWEIE_B_0X0		(0x0u<<1)
#define	SAES_IER_RWEIE_B_0X1		(0x1u<<1)
#define	SAES_IER_CCFIE_B_0X0		(0x0u<<0)
#define	SAES_IER_CCFIE_B_0X1		(0x1u<<0)

// ISR Configuration

#define	SAES_ISR_RNGEIF				(0x1u<<3)
#define	SAES_ISR_KEIF				(0x1u<<2)
#define	SAES_ISR_RWEIF				(0x1u<<1)
#define	SAES_ISR_CCF				(0x1u<<0)

#define	SAES_ISR_RNGEIF_B_0X0		(0x0u<<3)
#define	SAES_ISR_RNGEIF_B_0X1		(0x1u<<3)
#define	SAES_ISR_KEIF_B_0X0			(0x0u<<2)
#define	SAES_ISR_KEIF_B_0X1			(0x1u<<2)
#define	SAES_ISR_RWEIF_B_0X0		(0x0u<<1)
#define	SAES_ISR_RWEIF_B_0X1		(0x1u<<1)
#define	SAES_ISR_CCF_B_0X0			(0x0u<<0)
#define	SAES_ISR_CCF_B_0X1			(0x1u<<0)

// ICR Configuration

#define	SAES_ICR_RNGEIF				(0x1u<<3)
#define	SAES_ICR_KEIF				(0x1u<<2)
#define	SAES_ICR_RWEIF				(0x1u<<1)
#define	SAES_ICR_CCF				(0x1u<<0)
