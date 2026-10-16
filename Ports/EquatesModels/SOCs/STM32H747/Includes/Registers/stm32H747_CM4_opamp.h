/*
; stm32H747_CM4_opamp.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM4_opamp equates.
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
	volatile	uint32_t	OPAMP1_HSOTR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	OPAMP2_CSR;
	volatile	uint32_t	OPAMP2_OTR;
	volatile	uint32_t	OPAMP2_HSOTR;
} OPAMP_TypeDef;

#if (defined(__cplusplus))
#define	OPAMP	reinterpret_cast<OPAMP_TypeDef *>(0x40009000u)

#else
#define	OPAMP	((OPAMP_TypeDef *)0x40009000u)
#endif

// OPAMP1_CSR Configuration

#define	OPAMP_OPAMP1_CSR_CALOUT				(0x1u<<30)
#define	OPAMP_OPAMP1_CSR_TSTREF				(0x1u<<29)
#define	OPAMP_OPAMP1_CSR_USERTRIM			(0x1u<<18)
#define	OPAMP_OPAMP1_CSR_PGA_GAIN			(0xFu<<14)
#define	OPAMP_OPAMP1_CSR_PGA_GAIN_0			(0x1u<<14)
#define	OPAMP_OPAMP1_CSR_CALSEL				(0x3u<<12)
#define	OPAMP_OPAMP1_CSR_CALSEL_0			(0x1u<<12)
#define	OPAMP_OPAMP1_CSR_CALON				(0x1u<<11)
#define	OPAMP_OPAMP1_CSR_OPAHSM				(0x1u<<8)
#define	OPAMP_OPAMP1_CSR_VM_SEL				(0x3u<<5)
#define	OPAMP_OPAMP1_CSR_VM_SEL_0			(0x1u<<5)
#define	OPAMP_OPAMP1_CSR_VP_SEL				(0x3u<<2)
#define	OPAMP_OPAMP1_CSR_VP_SEL_0			(0x1u<<2)
#define	OPAMP_OPAMP1_CSR_FORCE_VP			(0x1u<<1)
#define	OPAMP_OPAMP1_CSR_OPAEN				(0x1u<<0)

// OPAMP1_OTR Configuration

#define	OPAMP_OPAMP1_OTR_TRIMOFFSETP		(0x1Fu<<8)
#define	OPAMP_OPAMP1_OTR_TRIMOFFSETP_0		(0x1u<<8)
#define	OPAMP_OPAMP1_OTR_TRIMOFFSETN		(0x1Fu<<0)
#define	OPAMP_OPAMP1_OTR_TRIMOFFSETN_0		(0x1u<<0)

// OPAMP1_HSOTR Configuration

#define	OPAMP_OPAMP1_HSOTR_TRIMLPOFFSETP	(0x1Fu<<8)
#define	OPAMP_OPAMP1_HSOTR_TRIMLPOFFSETP_0	(0x1u<<8)
#define	OPAMP_OPAMP1_HSOTR_TRIMLPOFFSETN	(0x1Fu<<0)
#define	OPAMP_OPAMP1_HSOTR_TRIMLPOFFSETN_0	(0x1u<<0)

// OPAMP2_CSR Configuration

#define	OPAMP_OPAMP2_CSR_CALOUT				(0x1u<<30)
#define	OPAMP_OPAMP2_CSR_TSTREF				(0x1u<<29)
#define	OPAMP_OPAMP2_CSR_USERTRIM			(0x1u<<18)
#define	OPAMP_OPAMP2_CSR_PGA_GAIN			(0xFu<<14)
#define	OPAMP_OPAMP2_CSR_PGA_GAIN_0			(0x1u<<14)
#define	OPAMP_OPAMP2_CSR_CALSEL				(0x3u<<12)
#define	OPAMP_OPAMP2_CSR_CALSEL_0			(0x1u<<12)
#define	OPAMP_OPAMP2_CSR_CALON				(0x1u<<11)
#define	OPAMP_OPAMP2_CSR_OPAHSM				(0x1u<<8)
#define	OPAMP_OPAMP2_CSR_VM_SEL				(0x3u<<5)
#define	OPAMP_OPAMP2_CSR_VM_SEL_0			(0x1u<<5)
#define	OPAMP_OPAMP2_CSR_FORCE_VP			(0x1u<<1)
#define	OPAMP_OPAMP2_CSR_OPAEN				(0x1u<<0)

// OPAMP2_OTR Configuration

#define	OPAMP_OPAMP2_OTR_TRIMOFFSETP		(0x1Fu<<8)
#define	OPAMP_OPAMP2_OTR_TRIMOFFSETP_0		(0x1u<<8)
#define	OPAMP_OPAMP2_OTR_TRIMOFFSETN		(0x1Fu<<0)
#define	OPAMP_OPAMP2_OTR_TRIMOFFSETN_0		(0x1u<<0)

// OPAMP2_HSOTR Configuration

#define	OPAMP_OPAMP2_HSOTR_TRIMLPOFFSETP	(0x1Fu<<8)
#define	OPAMP_OPAMP2_HSOTR_TRIMLPOFFSETP_0	(0x1u<<8)
#define	OPAMP_OPAMP2_HSOTR_TRIMLPOFFSETN	(0x1Fu<<0)
#define	OPAMP_OPAMP2_HSOTR_TRIMLPOFFSETN_0	(0x1u<<0)
