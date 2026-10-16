/*
; stm32H747_CM7_dmamux1.
; ======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM7_dmamux1 equates.
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

// DMAMUX1 address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	C0CR;
	volatile	uint32_t	C1CR;
	volatile	uint32_t	C2CR;
	volatile	uint32_t	C3CR;
	volatile	uint32_t	C4CR;
	volatile	uint32_t	C5CR;
	volatile	uint32_t	C6CR;
	volatile	uint32_t	C7CR;
	volatile	uint32_t	C8CR;
	volatile	uint32_t	C9CR;
	volatile	uint32_t	C10CR;
	volatile	uint32_t	C11CR;
	volatile	uint32_t	C12CR;
	volatile	uint32_t	C13CR;
	volatile	uint32_t	C14CR;
	volatile	uint32_t	C15CR;
	volatile	uint32_t	RESERVED0[16];
	volatile	uint32_t	CSR;
	volatile	uint32_t	CFR;
	volatile	uint32_t	RESERVED1[30];
	volatile	uint32_t	RG0CR;
	volatile	uint32_t	RG1CR;
	volatile	uint32_t	RG2CR;
	volatile	uint32_t	RG3CR;
	volatile	uint32_t	RG4CR;
	volatile	uint32_t	RG5CR;
	volatile	uint32_t	RG6CR;
	volatile	uint32_t	RG7CR;
	volatile	uint32_t	RESERVED2[8];
	volatile	uint32_t	RGSR;
	volatile	uint32_t	RGCFR;
} DMAMUX1_TypeDef;

#if (defined(__cplusplus))
#define	DMAMUX1	reinterpret_cast<DMAMUX1_TypeDef *>(0x40020800u)

#else
#define	DMAMUX1	((DMAMUX1_TypeDef *)0x40020800u)
#endif

// C0CR Configuration

#define	DMAMUX1_C0CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C0CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C0CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C0CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C0CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C0CR_SPOL_0			(0x1u<<17)
#define	DMAMUX1_C0CR_SE				(0x1u<<16)
#define	DMAMUX1_C0CR_EGE			(0x1u<<9)
#define	DMAMUX1_C0CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C0CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C0CR_DMAREQ_ID_0	(0x1u<<0)

// C1CR Configuration

#define	DMAMUX1_C1CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C1CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C1CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C1CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C1CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C1CR_SPOL_0			(0x1u<<17)
#define	DMAMUX1_C1CR_SE				(0x1u<<16)
#define	DMAMUX1_C1CR_EGE			(0x1u<<9)
#define	DMAMUX1_C1CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C1CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C1CR_DMAREQ_ID_0	(0x1u<<0)

// C2CR Configuration

#define	DMAMUX1_C2CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C2CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C2CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C2CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C2CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C2CR_SPOL_0			(0x1u<<17)
#define	DMAMUX1_C2CR_SE				(0x1u<<16)
#define	DMAMUX1_C2CR_EGE			(0x1u<<9)
#define	DMAMUX1_C2CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C2CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C2CR_DMAREQ_ID_0	(0x1u<<0)

// C3CR Configuration

#define	DMAMUX1_C3CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C3CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C3CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C3CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C3CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C3CR_SPOL_0			(0x1u<<17)
#define	DMAMUX1_C3CR_SE				(0x1u<<16)
#define	DMAMUX1_C3CR_EGE			(0x1u<<9)
#define	DMAMUX1_C3CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C3CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C3CR_DMAREQ_ID_0	(0x1u<<0)

// C4CR Configuration

#define	DMAMUX1_C4CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C4CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C4CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C4CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C4CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C4CR_SPOL_0			(0x1u<<17)
#define	DMAMUX1_C4CR_SE				(0x1u<<16)
#define	DMAMUX1_C4CR_EGE			(0x1u<<9)
#define	DMAMUX1_C4CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C4CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C4CR_DMAREQ_ID_0	(0x1u<<0)

// C5CR Configuration

#define	DMAMUX1_C5CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C5CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C5CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C5CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C5CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C5CR_SPOL_0			(0x1u<<17)
#define	DMAMUX1_C5CR_SE				(0x1u<<16)
#define	DMAMUX1_C5CR_EGE			(0x1u<<9)
#define	DMAMUX1_C5CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C5CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C5CR_DMAREQ_ID_0	(0x1u<<0)

// C6CR Configuration

#define	DMAMUX1_C6CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C6CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C6CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C6CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C6CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C6CR_SPOL_0			(0x1u<<17)
#define	DMAMUX1_C6CR_SE				(0x1u<<16)
#define	DMAMUX1_C6CR_EGE			(0x1u<<9)
#define	DMAMUX1_C6CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C6CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C6CR_DMAREQ_ID_0	(0x1u<<0)

// C7CR Configuration

#define	DMAMUX1_C7CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C7CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C7CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C7CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C7CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C7CR_SPOL_0			(0x1u<<17)
#define	DMAMUX1_C7CR_SE				(0x1u<<16)
#define	DMAMUX1_C7CR_EGE			(0x1u<<9)
#define	DMAMUX1_C7CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C7CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C7CR_DMAREQ_ID_0	(0x1u<<0)

// C8CR Configuration

#define	DMAMUX1_C8CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C8CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C8CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C8CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C8CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C8CR_SPOL_0			(0x1u<<17)
#define	DMAMUX1_C8CR_SE				(0x1u<<16)
#define	DMAMUX1_C8CR_EGE			(0x1u<<9)
#define	DMAMUX1_C8CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C8CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C8CR_DMAREQ_ID_0	(0x1u<<0)

// C9CR Configuration

#define	DMAMUX1_C9CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C9CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C9CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C9CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C9CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C9CR_SPOL_0			(0x1u<<17)
#define	DMAMUX1_C9CR_SE				(0x1u<<16)
#define	DMAMUX1_C9CR_EGE			(0x1u<<9)
#define	DMAMUX1_C9CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C9CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C9CR_DMAREQ_ID_0	(0x1u<<0)

// C10CR Configuration

#define	DMAMUX1_C10CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C10CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C10CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C10CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C10CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C10CR_SPOL_0		(0x1u<<17)
#define	DMAMUX1_C10CR_SE			(0x1u<<16)
#define	DMAMUX1_C10CR_EGE			(0x1u<<9)
#define	DMAMUX1_C10CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C10CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C10CR_DMAREQ_ID_0	(0x1u<<0)

// C11CR Configuration

#define	DMAMUX1_C11CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C11CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C11CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C11CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C11CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C11CR_SPOL_0		(0x1u<<17)
#define	DMAMUX1_C11CR_SE			(0x1u<<16)
#define	DMAMUX1_C11CR_EGE			(0x1u<<9)
#define	DMAMUX1_C11CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C11CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C11CR_DMAREQ_ID_0	(0x1u<<0)

// C12CR Configuration

#define	DMAMUX1_C12CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C12CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C12CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C12CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C12CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C12CR_SPOL_0		(0x1u<<17)
#define	DMAMUX1_C12CR_SE			(0x1u<<16)
#define	DMAMUX1_C12CR_EGE			(0x1u<<9)
#define	DMAMUX1_C12CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C12CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C12CR_DMAREQ_ID_0	(0x1u<<0)

// C13CR Configuration

#define	DMAMUX1_C13CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C13CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C13CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C13CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C13CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C13CR_SPOL_0		(0x1u<<17)
#define	DMAMUX1_C13CR_SE			(0x1u<<16)
#define	DMAMUX1_C13CR_EGE			(0x1u<<9)
#define	DMAMUX1_C13CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C13CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C13CR_DMAREQ_ID_0	(0x1u<<0)

// C14CR Configuration

#define	DMAMUX1_C14CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C14CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C14CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C14CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C14CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C14CR_SPOL_0		(0x1u<<17)
#define	DMAMUX1_C14CR_SE			(0x1u<<16)
#define	DMAMUX1_C14CR_EGE			(0x1u<<9)
#define	DMAMUX1_C14CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C14CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C14CR_DMAREQ_ID_0	(0x1u<<0)

// C15CR Configuration

#define	DMAMUX1_C15CR_SYNC_ID		(0x1Fu<<24)
#define	DMAMUX1_C15CR_SYNC_ID_0		(0x1u<<24)
#define	DMAMUX1_C15CR_NBREQ			(0x1Fu<<19)
#define	DMAMUX1_C15CR_NBREQ_0		(0x1u<<19)
#define	DMAMUX1_C15CR_SPOL			(0x3u<<17)
#define	DMAMUX1_C15CR_SPOL_0		(0x1u<<17)
#define	DMAMUX1_C15CR_SE			(0x1u<<16)
#define	DMAMUX1_C15CR_EGE			(0x1u<<9)
#define	DMAMUX1_C15CR_SOIE			(0x1u<<8)
#define	DMAMUX1_C15CR_DMAREQ_ID		(0xFFu<<0)
#define	DMAMUX1_C15CR_DMAREQ_ID_0	(0x1u<<0)

// CSR Configuration

#define	DMAMUX1_CSR_SOF				(0xFFFFu<<0)
#define	DMAMUX1_CSR_SOF_0			(0x1u<<0)

// CFR Configuration

#define	DMAMUX1_CFR_CSOF			(0xFFFFu<<0)
#define	DMAMUX1_CFR_CSOF_0			(0x1u<<0)

// RG0CR Configuration

#define	DMAMUX1_RG0CR_GNBREQ		(0x1Fu<<19)
#define	DMAMUX1_RG0CR_GNBREQ_0		(0x1u<<19)
#define	DMAMUX1_RG0CR_GPOL			(0x3u<<17)
#define	DMAMUX1_RG0CR_GPOL_0		(0x1u<<17)
#define	DMAMUX1_RG0CR_GE			(0x1u<<16)
#define	DMAMUX1_RG0CR_OIE			(0x1u<<8)
#define	DMAMUX1_RG0CR_SIG_ID		(0x1Fu<<0)
#define	DMAMUX1_RG0CR_SIG_ID_0		(0x1u<<0)

// RG1CR Configuration

#define	DMAMUX1_RG1CR_GNBREQ		(0x1Fu<<19)
#define	DMAMUX1_RG1CR_GNBREQ_0		(0x1u<<19)
#define	DMAMUX1_RG1CR_GPOL			(0x3u<<17)
#define	DMAMUX1_RG1CR_GPOL_0		(0x1u<<17)
#define	DMAMUX1_RG1CR_GE			(0x1u<<16)
#define	DMAMUX1_RG1CR_OIE			(0x1u<<8)
#define	DMAMUX1_RG1CR_SIG_ID		(0x1Fu<<0)
#define	DMAMUX1_RG1CR_SIG_ID_0		(0x1u<<0)

// RG2CR Configuration

#define	DMAMUX1_RG2CR_GNBREQ		(0x1Fu<<19)
#define	DMAMUX1_RG2CR_GNBREQ_0		(0x1u<<19)
#define	DMAMUX1_RG2CR_GPOL			(0x3u<<17)
#define	DMAMUX1_RG2CR_GPOL_0		(0x1u<<17)
#define	DMAMUX1_RG2CR_GE			(0x1u<<16)
#define	DMAMUX1_RG2CR_OIE			(0x1u<<8)
#define	DMAMUX1_RG2CR_SIG_ID		(0x1Fu<<0)
#define	DMAMUX1_RG2CR_SIG_ID_0		(0x1u<<0)

// RG3CR Configuration

#define	DMAMUX1_RG3CR_GNBREQ		(0x1Fu<<19)
#define	DMAMUX1_RG3CR_GNBREQ_0		(0x1u<<19)
#define	DMAMUX1_RG3CR_GPOL			(0x3u<<17)
#define	DMAMUX1_RG3CR_GPOL_0		(0x1u<<17)
#define	DMAMUX1_RG3CR_GE			(0x1u<<16)
#define	DMAMUX1_RG3CR_OIE			(0x1u<<8)
#define	DMAMUX1_RG3CR_SIG_ID		(0x1Fu<<0)
#define	DMAMUX1_RG3CR_SIG_ID_0		(0x1u<<0)

// RG4CR Configuration

#define	DMAMUX1_RG4CR_GNBREQ		(0x1Fu<<19)
#define	DMAMUX1_RG4CR_GNBREQ_0		(0x1u<<19)
#define	DMAMUX1_RG4CR_GPOL			(0x3u<<17)
#define	DMAMUX1_RG4CR_GPOL_0		(0x1u<<17)
#define	DMAMUX1_RG4CR_GE			(0x1u<<16)
#define	DMAMUX1_RG4CR_OIE			(0x1u<<8)
#define	DMAMUX1_RG4CR_SIG_ID		(0x1Fu<<0)
#define	DMAMUX1_RG4CR_SIG_ID_0		(0x1u<<0)

// RG5CR Configuration

#define	DMAMUX1_RG5CR_GNBREQ		(0x1Fu<<19)
#define	DMAMUX1_RG5CR_GNBREQ_0		(0x1u<<19)
#define	DMAMUX1_RG5CR_GPOL			(0x3u<<17)
#define	DMAMUX1_RG5CR_GPOL_0		(0x1u<<17)
#define	DMAMUX1_RG5CR_GE			(0x1u<<16)
#define	DMAMUX1_RG5CR_OIE			(0x1u<<8)
#define	DMAMUX1_RG5CR_SIG_ID		(0x1Fu<<0)
#define	DMAMUX1_RG5CR_SIG_ID_0		(0x1u<<0)

// RG6CR Configuration

#define	DMAMUX1_RG6CR_GNBREQ		(0x1Fu<<19)
#define	DMAMUX1_RG6CR_GNBREQ_0		(0x1u<<19)
#define	DMAMUX1_RG6CR_GPOL			(0x3u<<17)
#define	DMAMUX1_RG6CR_GPOL_0		(0x1u<<17)
#define	DMAMUX1_RG6CR_GE			(0x1u<<16)
#define	DMAMUX1_RG6CR_OIE			(0x1u<<8)
#define	DMAMUX1_RG6CR_SIG_ID		(0x1Fu<<0)
#define	DMAMUX1_RG6CR_SIG_ID_0		(0x1u<<0)

// RG7CR Configuration

#define	DMAMUX1_RG7CR_GNBREQ		(0x1Fu<<19)
#define	DMAMUX1_RG7CR_GNBREQ_0		(0x1u<<19)
#define	DMAMUX1_RG7CR_GPOL			(0x3u<<17)
#define	DMAMUX1_RG7CR_GPOL_0		(0x1u<<17)
#define	DMAMUX1_RG7CR_GE			(0x1u<<16)
#define	DMAMUX1_RG7CR_OIE			(0x1u<<8)
#define	DMAMUX1_RG7CR_SIG_ID		(0x1Fu<<0)
#define	DMAMUX1_RG7CR_SIG_ID_0		(0x1u<<0)

// RGSR Configuration

#define	DMAMUX1_RGSR_OF				(0xFFu<<0)
#define	DMAMUX1_RGSR_OF_0			(0x1u<<0)

// RGCFR Configuration

#define	DMAMUX1_RGCFR_COF			(0xFFu<<0)
#define	DMAMUX1_RGCFR_COF_0			(0x1u<<0)
