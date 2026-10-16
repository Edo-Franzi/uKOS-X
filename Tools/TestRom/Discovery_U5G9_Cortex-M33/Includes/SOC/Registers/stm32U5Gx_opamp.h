/*
; stm32U5Gx_opamp.
; ================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_opamp equates.
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

// OPAMP address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	OPAMP1_CSR;
	volatile	uint32_t	OPAMP1_OTR;
	volatile	uint32_t	OPAMP1_LPOTR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	OPAMP2_CRS;
	volatile	uint32_t	OPAMP2_OTR;
	volatile	uint32_t	OPAMP2_LPOTR;
} OPAMP_TypeDef;

#if (defined(__cplusplus))
#define	OPAMP_NS	reinterpret_cast<OPAMP_TypeDef *>(0x46005000u)
#define	OPAMP_S		reinterpret_cast<OPAMP_TypeDef *>(0x56005000u)

#else
#define	OPAMP_NS	((OPAMP_TypeDef *)0x46005000u)
#define	OPAMP_S		((OPAMP_TypeDef *)0x56005000u)
#endif

// OPAMP1_CSR Configuration

#define	OPAMP_OPAMP1_CSR_OPA_RANGE			(0x1u<<31)
#define	OPAMP_OPAMP1_CSR_OPAHSM				(0x1u<<30)
#define	OPAMP_OPAMP1_CSR_CALOUT				(0x1u<<15)
#define	OPAMP_OPAMP1_CSR_USERTRIM			(0x1u<<14)
#define	OPAMP_OPAMP1_CSR_CALSEL				(0x1u<<13)
#define	OPAMP_OPAMP1_CSR_CALON				(0x1u<<12)
#define	OPAMP_OPAMP1_CSR_VP_SEL				(0x1u<<10)
#define	OPAMP_OPAMP1_CSR_VM_SEL				(0x3u<<8)
#define	OPAMP_OPAMP1_CSR_VM_SEL_0			(0x1u<<8)
#define	OPAMP_OPAMP1_CSR_PGA_GAIN			(0x3u<<4)
#define	OPAMP_OPAMP1_CSR_PGA_GAIN_0			(0x1u<<4)
#define	OPAMP_OPAMP1_CSR_OPAMODE			(0x3u<<2)
#define	OPAMP_OPAMP1_CSR_OPAMODE_0			(0x1u<<2)
#define	OPAMP_OPAMP1_CSR_OPALPM				(0x1u<<1)
#define	OPAMP_OPAMP1_CSR_OPAEN				(0x1u<<0)
#define	OPAMP_OPAMP1_CSR_OPA_RANGE_B_0X0	(0x0u<<31)
#define	OPAMP_OPAMP1_CSR_OPA_RANGE_B_0X1	(0x1u<<31)
#define	OPAMP_OPAMP1_CSR_OPAHSM_B_0X0		(0x0u<<30)
#define	OPAMP_OPAMP1_CSR_OPAHSM_B_0X1		(0x1u<<30)
#define	OPAMP_OPAMP1_CSR_USERTRIM_B_0X0		(0x0u<<14)
#define	OPAMP_OPAMP1_CSR_USERTRIM_B_0X1		(0x1u<<14)
#define	OPAMP_OPAMP1_CSR_CALSEL_B_0X0		(0x0u<<13)
#define	OPAMP_OPAMP1_CSR_CALSEL_B_0X1		(0x1u<<13)
#define	OPAMP_OPAMP1_CSR_CALON_B_0X0		(0x0u<<12)
#define	OPAMP_OPAMP1_CSR_CALON_B_0X1		(0x1u<<12)
#define	OPAMP_OPAMP1_CSR_VP_SEL_B_0X0		(0x0u<<10)
#define	OPAMP_OPAMP1_CSR_VP_SEL_B_0X1		(0x1u<<10)
#define	OPAMP_OPAMP1_CSR_VM_SEL_B_0X0		(0x0u<<8)
#define	OPAMP_OPAMP1_CSR_VM_SEL_B_0X1		(0x1u<<8)
#define	OPAMP_OPAMP1_CSR_PGA_GAIN_B_0X0		(0x0u<<4)
#define	OPAMP_OPAMP1_CSR_PGA_GAIN_B_0X1		(0x1u<<4)
#define	OPAMP_OPAMP1_CSR_PGA_GAIN_B_0X2		(0x2u<<4)
#define	OPAMP_OPAMP1_CSR_PGA_GAIN_B_0X3		(0x3u<<4)
#define	OPAMP_OPAMP1_CSR_OPAMODE_B_0X2		(0x2u<<2)
#define	OPAMP_OPAMP1_CSR_OPAMODE_B_0X3		(0x3u<<2)
#define	OPAMP_OPAMP1_CSR_OPALPM_B_0X0		(0x0u<<1)
#define	OPAMP_OPAMP1_CSR_OPALPM_B_0X1		(0x1u<<1)
#define	OPAMP_OPAMP1_CSR_OPAEN_B_0X0		(0x0u<<0)
#define	OPAMP_OPAMP1_CSR_OPAEN_B_0X1		(0x1u<<0)

// OPAMP1_OTR Configuration

#define	OPAMP_OPAMP1_OTR_TRIMOFFSETP		(0x1Fu<<8)
#define	OPAMP_OPAMP1_OTR_TRIMOFFSETP_0		(0x1u<<8)
#define	OPAMP_OPAMP1_OTR_TRIMOFFSETN		(0x1Fu<<0)
#define	OPAMP_OPAMP1_OTR_TRIMOFFSETN_0		(0x1u<<0)

// OPAMP1_LPOTR Configuration

#define	OPAMP_OPAMP1_LPOTR_TRIMLPOFFSETP	(0x1Fu<<8)
#define	OPAMP_OPAMP1_LPOTR_TRIMLPOFFSETP_0	(0x1u<<8)
#define	OPAMP_OPAMP1_LPOTR_TRIMLPOFFSETN	(0x1Fu<<0)
#define	OPAMP_OPAMP1_LPOTR_TRIMLPOFFSETN_0	(0x1u<<0)

// OPAMP2_CRS Configuration

#define	OPAMP_OPAMP2_CRS_OPAHSM				(0x1u<<30)
#define	OPAMP_OPAMP2_CRS_CALOUT				(0x1u<<15)
#define	OPAMP_OPAMP2_CRS_USERTRIM			(0x1u<<14)
#define	OPAMP_OPAMP2_CRS_CALSEL				(0x1u<<13)
#define	OPAMP_OPAMP2_CRS_CALON				(0x1u<<12)
#define	OPAMP_OPAMP2_CRS_VP_SEL				(0x1u<<10)
#define	OPAMP_OPAMP2_CRS_VM_SEL				(0x3u<<8)
#define	OPAMP_OPAMP2_CRS_VM_SEL_0			(0x1u<<8)
#define	OPAMP_OPAMP2_CRS_PGA_GAIN			(0x3u<<4)
#define	OPAMP_OPAMP2_CRS_PGA_GAIN_0			(0x1u<<4)
#define	OPAMP_OPAMP2_CRS_OPAMODE			(0x3u<<2)
#define	OPAMP_OPAMP2_CRS_OPAMODE_0			(0x1u<<2)
#define	OPAMP_OPAMP2_CRS_OPALPM				(0x1u<<1)
#define	OPAMP_OPAMP2_CRS_OPAEN				(0x1u<<0)
#define	OPAMP_OPAMP2_CRS_OPAHSM_B_0X0		(0x0u<<30)
#define	OPAMP_OPAMP2_CRS_OPAHSM_B_0X1		(0x1u<<30)
#define	OPAMP_OPAMP2_CRS_USERTRIM_B_0X0		(0x0u<<14)
#define	OPAMP_OPAMP2_CRS_USERTRIM_B_0X1		(0x1u<<14)
#define	OPAMP_OPAMP2_CRS_CALSEL_B_0X0		(0x0u<<13)
#define	OPAMP_OPAMP2_CRS_CALSEL_B_0X1		(0x1u<<13)
#define	OPAMP_OPAMP2_CRS_CALON_B_0X0		(0x0u<<12)
#define	OPAMP_OPAMP2_CRS_CALON_B_0X1		(0x1u<<12)
#define	OPAMP_OPAMP2_CRS_VP_SEL_B_0X0		(0x0u<<10)
#define	OPAMP_OPAMP2_CRS_VP_SEL_B_0X1		(0x1u<<10)
#define	OPAMP_OPAMP2_CRS_VM_SEL_B_0X0		(0x0u<<8)
#define	OPAMP_OPAMP2_CRS_VM_SEL_B_0X1		(0x1u<<8)
#define	OPAMP_OPAMP2_CRS_PGA_GAIN_B_0X0		(0x0u<<4)
#define	OPAMP_OPAMP2_CRS_PGA_GAIN_B_0X1		(0x1u<<4)
#define	OPAMP_OPAMP2_CRS_PGA_GAIN_B_0X2		(0x2u<<4)
#define	OPAMP_OPAMP2_CRS_PGA_GAIN_B_0X3		(0x3u<<4)
#define	OPAMP_OPAMP2_CRS_OPAMODE_B_0X2		(0x2u<<2)
#define	OPAMP_OPAMP2_CRS_OPAMODE_B_0X3		(0x3u<<2)
#define	OPAMP_OPAMP2_CRS_OPALPM_B_0X0		(0x0u<<1)
#define	OPAMP_OPAMP2_CRS_OPALPM_B_0X1		(0x1u<<1)
#define	OPAMP_OPAMP2_CRS_OPAEN_B_0X0		(0x0u<<0)
#define	OPAMP_OPAMP2_CRS_OPAEN_B_0X1		(0x1u<<0)

// OPAMP2_OTR Configuration

#define	OPAMP_OPAMP2_OTR_TRIMOFFSETP		(0x1Fu<<8)
#define	OPAMP_OPAMP2_OTR_TRIMOFFSETP_0		(0x1u<<8)
#define	OPAMP_OPAMP2_OTR_TRIMOFFSETN		(0x1Fu<<0)
#define	OPAMP_OPAMP2_OTR_TRIMOFFSETN_0		(0x1u<<0)

// OPAMP2_LPOTR Configuration

#define	OPAMP_OPAMP2_LPOTR_TRIMLPOFFSETP	(0x1Fu<<8)
#define	OPAMP_OPAMP2_LPOTR_TRIMLPOFFSETP_0	(0x1u<<8)
#define	OPAMP_OPAMP2_LPOTR_TRIMLPOFFSETN	(0x1Fu<<0)
#define	OPAMP_OPAMP2_LPOTR_TRIMLPOFFSETN_0	(0x1u<<0)
