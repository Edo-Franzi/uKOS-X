/*
; stm32H747_CM4_adc3_common.
; ==========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM4_adc3_common equates.
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

// ADC3_COMMON address definitions
// -------------------------------

typedef struct {
	volatile	uint32_t	CSR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	CCR;
	volatile	uint32_t	CDR;
	volatile	uint32_t	CDR2;
} ADC3_COMMON_TypeDef;

#if (defined(__cplusplus))
#define	ADC3_COMMON	reinterpret_cast<ADC3_COMMON_TypeDef *>(0x58026300u)

#else
#define	ADC3_COMMON	((ADC3_COMMON_TypeDef *)0x58026300u)
#endif

// CSR Configuration

#define	ADC3_COMMON_CSR_JQOVF_SLV		(0x1u<<26)
#define	ADC3_COMMON_CSR_AWD3_SLV		(0x1u<<25)
#define	ADC3_COMMON_CSR_AWD2_SLV		(0x1u<<24)
#define	ADC3_COMMON_CSR_AWD1_SLV		(0x1u<<23)
#define	ADC3_COMMON_CSR_JEOS_SLV		(0x1u<<22)
#define	ADC3_COMMON_CSR_JEOC_SLV		(0x1u<<21)
#define	ADC3_COMMON_CSR_OVR_SLV			(0x1u<<20)
#define	ADC3_COMMON_CSR_EOS_SLV			(0x1u<<19)
#define	ADC3_COMMON_CSR_EOC_SLV			(0x1u<<18)
#define	ADC3_COMMON_CSR_EOSMP_SLV		(0x1u<<17)
#define	ADC3_COMMON_CSR_ADRDY_SLV		(0x1u<<16)
#define	ADC3_COMMON_CSR_JQOVF_MST		(0x1u<<10)
#define	ADC3_COMMON_CSR_AWD3_MST		(0x1u<<9)
#define	ADC3_COMMON_CSR_AWD2_MST		(0x1u<<8)
#define	ADC3_COMMON_CSR_AWD1_MST		(0x1u<<7)
#define	ADC3_COMMON_CSR_JEOS_MST		(0x1u<<6)
#define	ADC3_COMMON_CSR_JEOC_MST		(0x1u<<5)
#define	ADC3_COMMON_CSR_OVR_MST			(0x1u<<4)
#define	ADC3_COMMON_CSR_EOS_MST			(0x1u<<3)
#define	ADC3_COMMON_CSR_EOC_MST			(0x1u<<2)
#define	ADC3_COMMON_CSR_EOSMP_MST		(0x1u<<1)
#define	ADC3_COMMON_CSR_ADRDY_MST		(0x1u<<0)

// CCR Configuration

#define	ADC3_COMMON_CCR_VBATEN			(0x1u<<24)
#define	ADC3_COMMON_CCR_VSENSEEN		(0x1u<<23)
#define	ADC3_COMMON_CCR_VREFEN			(0x1u<<22)
#define	ADC3_COMMON_CCR_PRESC			(0xFu<<18)
#define	ADC3_COMMON_CCR_PRESC_0			(0x1u<<18)
#define	ADC3_COMMON_CCR_CKMODE			(0x3u<<16)
#define	ADC3_COMMON_CCR_CKMODE_0		(0x1u<<16)
#define	ADC3_COMMON_CCR_DAMDF			(0x3u<<14)
#define	ADC3_COMMON_CCR_DAMDF_0			(0x1u<<14)
#define	ADC3_COMMON_CCR_DELAY			(0xFu<<8)
#define	ADC3_COMMON_CCR_DELAY_0			(0x1u<<8)
#define	ADC3_COMMON_CCR_DUAL			(0x1Fu<<0)
#define	ADC3_COMMON_CCR_DUAL_0			(0x1u<<0)

// CDR Configuration

#define	ADC3_COMMON_CDR_RDATA_MST		(0xFFFFu<<0)
#define	ADC3_COMMON_CDR_RDATA_MST_0		(0x1u<<0)
#define	ADC3_COMMON_CDR_RDATA_SLV		(0xFFFFu<<16)
#define	ADC3_COMMON_CDR_RDATA_SLV_0		(0x1u<<16)

// CDR2 Configuration

#define	ADC3_COMMON_CDR2_RDATA_ALT		(0xFFFFFFFFu<<0)
#define	ADC3_COMMON_CDR2_RDATA_ALT_0	(0x1u<<0)
