/*
; stm32F217_exti.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_exti equates.
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
	volatile	uint32_t	IMR;
	volatile	uint32_t	EMR;
	volatile	uint32_t	RTSR;
	volatile	uint32_t	FTSR;
	volatile	uint32_t	SWIER;
	volatile	uint32_t	PR;
} EXTI_TypeDef;

#if (defined(__cplusplus))
#define	EXTI	reinterpret_cast<EXTI_TypeDef *>(0x40013C00u)

#else
#define	EXTI	((EXTI_TypeDef *)0x40013C00u)
#endif

// IMR Configuration

#define	EXTI_IMR_MR22		(0x1u<<22)
#define	EXTI_IMR_MR21		(0x1u<<21)
#define	EXTI_IMR_MR20		(0x1u<<20)
#define	EXTI_IMR_MR19		(0x1u<<19)
#define	EXTI_IMR_MR18		(0x1u<<18)
#define	EXTI_IMR_MR17		(0x1u<<17)
#define	EXTI_IMR_MR16		(0x1u<<16)
#define	EXTI_IMR_MR15		(0x1u<<15)
#define	EXTI_IMR_MR14		(0x1u<<14)
#define	EXTI_IMR_MR13		(0x1u<<13)
#define	EXTI_IMR_MR12		(0x1u<<12)
#define	EXTI_IMR_MR11		(0x1u<<11)
#define	EXTI_IMR_MR10		(0x1u<<10)
#define	EXTI_IMR_MR9		(0x1u<<9)
#define	EXTI_IMR_MR8		(0x1u<<8)
#define	EXTI_IMR_MR7		(0x1u<<7)
#define	EXTI_IMR_MR6		(0x1u<<6)
#define	EXTI_IMR_MR5		(0x1u<<5)
#define	EXTI_IMR_MR4		(0x1u<<4)
#define	EXTI_IMR_MR3		(0x1u<<3)
#define	EXTI_IMR_MR2		(0x1u<<2)
#define	EXTI_IMR_MR1		(0x1u<<1)
#define	EXTI_IMR_MR0		(0x1u<<0)

// EMR Configuration

#define	EXTI_EMR_MR22		(0x1u<<22)
#define	EXTI_EMR_MR21		(0x1u<<21)
#define	EXTI_EMR_MR20		(0x1u<<20)
#define	EXTI_EMR_MR19		(0x1u<<19)
#define	EXTI_EMR_MR18		(0x1u<<18)
#define	EXTI_EMR_MR17		(0x1u<<17)
#define	EXTI_EMR_MR16		(0x1u<<16)
#define	EXTI_EMR_MR15		(0x1u<<15)
#define	EXTI_EMR_MR14		(0x1u<<14)
#define	EXTI_EMR_MR13		(0x1u<<13)
#define	EXTI_EMR_MR12		(0x1u<<12)
#define	EXTI_EMR_MR11		(0x1u<<11)
#define	EXTI_EMR_MR10		(0x1u<<10)
#define	EXTI_EMR_MR9		(0x1u<<9)
#define	EXTI_EMR_MR8		(0x1u<<8)
#define	EXTI_EMR_MR7		(0x1u<<7)
#define	EXTI_EMR_MR6		(0x1u<<6)
#define	EXTI_EMR_MR5		(0x1u<<5)
#define	EXTI_EMR_MR4		(0x1u<<4)
#define	EXTI_EMR_MR3		(0x1u<<3)
#define	EXTI_EMR_MR2		(0x1u<<2)
#define	EXTI_EMR_MR1		(0x1u<<1)
#define	EXTI_EMR_MR0		(0x1u<<0)

// RTSR Configuration

#define	EXTI_RTSR_TR22		(0x1u<<22)
#define	EXTI_RTSR_TR21		(0x1u<<21)
#define	EXTI_RTSR_TR20		(0x1u<<20)
#define	EXTI_RTSR_TR19		(0x1u<<19)
#define	EXTI_RTSR_TR18		(0x1u<<18)
#define	EXTI_RTSR_TR17		(0x1u<<17)
#define	EXTI_RTSR_TR16		(0x1u<<16)
#define	EXTI_RTSR_TR15		(0x1u<<15)
#define	EXTI_RTSR_TR14		(0x1u<<14)
#define	EXTI_RTSR_TR13		(0x1u<<13)
#define	EXTI_RTSR_TR12		(0x1u<<12)
#define	EXTI_RTSR_TR11		(0x1u<<11)
#define	EXTI_RTSR_TR10		(0x1u<<10)
#define	EXTI_RTSR_TR9		(0x1u<<9)
#define	EXTI_RTSR_TR8		(0x1u<<8)
#define	EXTI_RTSR_TR7		(0x1u<<7)
#define	EXTI_RTSR_TR6		(0x1u<<6)
#define	EXTI_RTSR_TR5		(0x1u<<5)
#define	EXTI_RTSR_TR4		(0x1u<<4)
#define	EXTI_RTSR_TR3		(0x1u<<3)
#define	EXTI_RTSR_TR2		(0x1u<<2)
#define	EXTI_RTSR_TR1		(0x1u<<1)
#define	EXTI_RTSR_TR0		(0x1u<<0)

// FTSR Configuration

#define	EXTI_FTSR_TR22		(0x1u<<22)
#define	EXTI_FTSR_TR21		(0x1u<<21)
#define	EXTI_FTSR_TR20		(0x1u<<20)
#define	EXTI_FTSR_TR19		(0x1u<<19)
#define	EXTI_FTSR_TR18		(0x1u<<18)
#define	EXTI_FTSR_TR17		(0x1u<<17)
#define	EXTI_FTSR_TR16		(0x1u<<16)
#define	EXTI_FTSR_TR15		(0x1u<<15)
#define	EXTI_FTSR_TR14		(0x1u<<14)
#define	EXTI_FTSR_TR13		(0x1u<<13)
#define	EXTI_FTSR_TR12		(0x1u<<12)
#define	EXTI_FTSR_TR11		(0x1u<<11)
#define	EXTI_FTSR_TR10		(0x1u<<10)
#define	EXTI_FTSR_TR9		(0x1u<<9)
#define	EXTI_FTSR_TR8		(0x1u<<8)
#define	EXTI_FTSR_TR7		(0x1u<<7)
#define	EXTI_FTSR_TR6		(0x1u<<6)
#define	EXTI_FTSR_TR5		(0x1u<<5)
#define	EXTI_FTSR_TR4		(0x1u<<4)
#define	EXTI_FTSR_TR3		(0x1u<<3)
#define	EXTI_FTSR_TR2		(0x1u<<2)
#define	EXTI_FTSR_TR1		(0x1u<<1)
#define	EXTI_FTSR_TR0		(0x1u<<0)

// SWIER Configuration

#define	EXTI_SWIER_SWIER22	(0x1u<<22)
#define	EXTI_SWIER_SWIER21	(0x1u<<21)
#define	EXTI_SWIER_SWIER20	(0x1u<<20)
#define	EXTI_SWIER_SWIER19	(0x1u<<19)
#define	EXTI_SWIER_SWIER18	(0x1u<<18)
#define	EXTI_SWIER_SWIER17	(0x1u<<17)
#define	EXTI_SWIER_SWIER16	(0x1u<<16)
#define	EXTI_SWIER_SWIER15	(0x1u<<15)
#define	EXTI_SWIER_SWIER14	(0x1u<<14)
#define	EXTI_SWIER_SWIER13	(0x1u<<13)
#define	EXTI_SWIER_SWIER12	(0x1u<<12)
#define	EXTI_SWIER_SWIER11	(0x1u<<11)
#define	EXTI_SWIER_SWIER10	(0x1u<<10)
#define	EXTI_SWIER_SWIER9	(0x1u<<9)
#define	EXTI_SWIER_SWIER8	(0x1u<<8)
#define	EXTI_SWIER_SWIER7	(0x1u<<7)
#define	EXTI_SWIER_SWIER6	(0x1u<<6)
#define	EXTI_SWIER_SWIER5	(0x1u<<5)
#define	EXTI_SWIER_SWIER4	(0x1u<<4)
#define	EXTI_SWIER_SWIER3	(0x1u<<3)
#define	EXTI_SWIER_SWIER2	(0x1u<<2)
#define	EXTI_SWIER_SWIER1	(0x1u<<1)
#define	EXTI_SWIER_SWIER0	(0x1u<<0)

// PR Configuration

#define	EXTI_PR_PR22		(0x1u<<22)
#define	EXTI_PR_PR21		(0x1u<<21)
#define	EXTI_PR_PR20		(0x1u<<20)
#define	EXTI_PR_PR19		(0x1u<<19)
#define	EXTI_PR_PR18		(0x1u<<18)
#define	EXTI_PR_PR17		(0x1u<<17)
#define	EXTI_PR_PR16		(0x1u<<16)
#define	EXTI_PR_PR15		(0x1u<<15)
#define	EXTI_PR_PR14		(0x1u<<14)
#define	EXTI_PR_PR13		(0x1u<<13)
#define	EXTI_PR_PR12		(0x1u<<12)
#define	EXTI_PR_PR11		(0x1u<<11)
#define	EXTI_PR_PR10		(0x1u<<10)
#define	EXTI_PR_PR9			(0x1u<<9)
#define	EXTI_PR_PR8			(0x1u<<8)
#define	EXTI_PR_PR7			(0x1u<<7)
#define	EXTI_PR_PR6			(0x1u<<6)
#define	EXTI_PR_PR5			(0x1u<<5)
#define	EXTI_PR_PR4			(0x1u<<4)
#define	EXTI_PR_PR3			(0x1u<<3)
#define	EXTI_PR_PR2			(0x1u<<2)
#define	EXTI_PR_PR1			(0x1u<<1)
#define	EXTI_PR_PR0			(0x1u<<0)
