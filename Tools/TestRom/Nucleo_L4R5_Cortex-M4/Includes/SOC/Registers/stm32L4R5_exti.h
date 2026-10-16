/*
; stm32L4R5_exti.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_exti equates.
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
	volatile	uint32_t	IMR1;
	volatile	uint32_t	EMR1;
	volatile	uint32_t	RTSR1;
	volatile	uint32_t	FTSR1;
	volatile	uint32_t	SWIER1;
	volatile	uint32_t	PR1;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	IMR2;
	volatile	uint32_t	EMR2;
	volatile	uint32_t	RTSR2;
	volatile	uint32_t	FTSR2;
	volatile	uint32_t	SWIER2;
	volatile	uint32_t	PR2;
} EXTI_TypeDef;

#if (defined(__cplusplus))
#define	EXTI	reinterpret_cast<EXTI_TypeDef *>(0x40010400u)

#else
#define	EXTI	((EXTI_TypeDef *)0x40010400u)
#endif

// IMR1 Configuration

#define	EXTI_IMR1_MR31		(0x1u<<31)
#define	EXTI_IMR1_MR30		(0x1u<<30)
#define	EXTI_IMR1_MR29		(0x1u<<29)
#define	EXTI_IMR1_MR28		(0x1u<<28)
#define	EXTI_IMR1_MR27		(0x1u<<27)
#define	EXTI_IMR1_MR26		(0x1u<<26)
#define	EXTI_IMR1_MR25		(0x1u<<25)
#define	EXTI_IMR1_MR24		(0x1u<<24)
#define	EXTI_IMR1_MR23		(0x1u<<23)
#define	EXTI_IMR1_MR22		(0x1u<<22)
#define	EXTI_IMR1_MR21		(0x1u<<21)
#define	EXTI_IMR1_MR20		(0x1u<<20)
#define	EXTI_IMR1_MR19		(0x1u<<19)
#define	EXTI_IMR1_MR18		(0x1u<<18)
#define	EXTI_IMR1_MR17		(0x1u<<17)
#define	EXTI_IMR1_MR16		(0x1u<<16)
#define	EXTI_IMR1_MR15		(0x1u<<15)
#define	EXTI_IMR1_MR14		(0x1u<<14)
#define	EXTI_IMR1_MR13		(0x1u<<13)
#define	EXTI_IMR1_MR12		(0x1u<<12)
#define	EXTI_IMR1_MR11		(0x1u<<11)
#define	EXTI_IMR1_MR10		(0x1u<<10)
#define	EXTI_IMR1_MR9		(0x1u<<9)
#define	EXTI_IMR1_MR8		(0x1u<<8)
#define	EXTI_IMR1_MR7		(0x1u<<7)
#define	EXTI_IMR1_MR6		(0x1u<<6)
#define	EXTI_IMR1_MR5		(0x1u<<5)
#define	EXTI_IMR1_MR4		(0x1u<<4)
#define	EXTI_IMR1_MR3		(0x1u<<3)
#define	EXTI_IMR1_MR2		(0x1u<<2)
#define	EXTI_IMR1_MR1		(0x1u<<1)
#define	EXTI_IMR1_MR0		(0x1u<<0)

// EMR1 Configuration

#define	EXTI_EMR1_MR31		(0x1u<<31)
#define	EXTI_EMR1_MR30		(0x1u<<30)
#define	EXTI_EMR1_MR29		(0x1u<<29)
#define	EXTI_EMR1_MR28		(0x1u<<28)
#define	EXTI_EMR1_MR27		(0x1u<<27)
#define	EXTI_EMR1_MR26		(0x1u<<26)
#define	EXTI_EMR1_MR25		(0x1u<<25)
#define	EXTI_EMR1_MR24		(0x1u<<24)
#define	EXTI_EMR1_MR23		(0x1u<<23)
#define	EXTI_EMR1_MR22		(0x1u<<22)
#define	EXTI_EMR1_MR21		(0x1u<<21)
#define	EXTI_EMR1_MR20		(0x1u<<20)
#define	EXTI_EMR1_MR19		(0x1u<<19)
#define	EXTI_EMR1_MR18		(0x1u<<18)
#define	EXTI_EMR1_MR17		(0x1u<<17)
#define	EXTI_EMR1_MR16		(0x1u<<16)
#define	EXTI_EMR1_MR15		(0x1u<<15)
#define	EXTI_EMR1_MR14		(0x1u<<14)
#define	EXTI_EMR1_MR13		(0x1u<<13)
#define	EXTI_EMR1_MR12		(0x1u<<12)
#define	EXTI_EMR1_MR11		(0x1u<<11)
#define	EXTI_EMR1_MR10		(0x1u<<10)
#define	EXTI_EMR1_MR9		(0x1u<<9)
#define	EXTI_EMR1_MR8		(0x1u<<8)
#define	EXTI_EMR1_MR7		(0x1u<<7)
#define	EXTI_EMR1_MR6		(0x1u<<6)
#define	EXTI_EMR1_MR5		(0x1u<<5)
#define	EXTI_EMR1_MR4		(0x1u<<4)
#define	EXTI_EMR1_MR3		(0x1u<<3)
#define	EXTI_EMR1_MR2		(0x1u<<2)
#define	EXTI_EMR1_MR1		(0x1u<<1)
#define	EXTI_EMR1_MR0		(0x1u<<0)

// RTSR1 Configuration

#define	EXTI_RTSR1_TR22		(0x1u<<22)
#define	EXTI_RTSR1_TR21		(0x1u<<21)
#define	EXTI_RTSR1_TR20		(0x1u<<20)
#define	EXTI_RTSR1_TR19		(0x1u<<19)
#define	EXTI_RTSR1_TR18		(0x1u<<18)
#define	EXTI_RTSR1_TR16		(0x1u<<16)
#define	EXTI_RTSR1_TR15		(0x1u<<15)
#define	EXTI_RTSR1_TR14		(0x1u<<14)
#define	EXTI_RTSR1_TR13		(0x1u<<13)
#define	EXTI_RTSR1_TR12		(0x1u<<12)
#define	EXTI_RTSR1_TR11		(0x1u<<11)
#define	EXTI_RTSR1_TR10		(0x1u<<10)
#define	EXTI_RTSR1_TR9		(0x1u<<9)
#define	EXTI_RTSR1_TR8		(0x1u<<8)
#define	EXTI_RTSR1_TR7		(0x1u<<7)
#define	EXTI_RTSR1_TR6		(0x1u<<6)
#define	EXTI_RTSR1_TR5		(0x1u<<5)
#define	EXTI_RTSR1_TR4		(0x1u<<4)
#define	EXTI_RTSR1_TR3		(0x1u<<3)
#define	EXTI_RTSR1_TR2		(0x1u<<2)
#define	EXTI_RTSR1_TR1		(0x1u<<1)
#define	EXTI_RTSR1_TR0		(0x1u<<0)

// FTSR1 Configuration

#define	EXTI_FTSR1_TR22		(0x1u<<22)
#define	EXTI_FTSR1_TR21		(0x1u<<21)
#define	EXTI_FTSR1_TR20		(0x1u<<20)
#define	EXTI_FTSR1_TR19		(0x1u<<19)
#define	EXTI_FTSR1_TR18		(0x1u<<18)
#define	EXTI_FTSR1_TR16		(0x1u<<16)
#define	EXTI_FTSR1_TR15		(0x1u<<15)
#define	EXTI_FTSR1_TR14		(0x1u<<14)
#define	EXTI_FTSR1_TR13		(0x1u<<13)
#define	EXTI_FTSR1_TR12		(0x1u<<12)
#define	EXTI_FTSR1_TR11		(0x1u<<11)
#define	EXTI_FTSR1_TR10		(0x1u<<10)
#define	EXTI_FTSR1_TR9		(0x1u<<9)
#define	EXTI_FTSR1_TR8		(0x1u<<8)
#define	EXTI_FTSR1_TR7		(0x1u<<7)
#define	EXTI_FTSR1_TR6		(0x1u<<6)
#define	EXTI_FTSR1_TR5		(0x1u<<5)
#define	EXTI_FTSR1_TR4		(0x1u<<4)
#define	EXTI_FTSR1_TR3		(0x1u<<3)
#define	EXTI_FTSR1_TR2		(0x1u<<2)
#define	EXTI_FTSR1_TR1		(0x1u<<1)
#define	EXTI_FTSR1_TR0		(0x1u<<0)

// SWIER1 Configuration

#define	EXTI_SWIER1_SWIER22	(0x1u<<22)
#define	EXTI_SWIER1_SWIER21	(0x1u<<21)
#define	EXTI_SWIER1_SWIER20	(0x1u<<20)
#define	EXTI_SWIER1_SWIER19	(0x1u<<19)
#define	EXTI_SWIER1_SWIER18	(0x1u<<18)
#define	EXTI_SWIER1_SWIER16	(0x1u<<16)
#define	EXTI_SWIER1_SWIER15	(0x1u<<15)
#define	EXTI_SWIER1_SWIER14	(0x1u<<14)
#define	EXTI_SWIER1_SWIER13	(0x1u<<13)
#define	EXTI_SWIER1_SWIER12	(0x1u<<12)
#define	EXTI_SWIER1_SWIER11	(0x1u<<11)
#define	EXTI_SWIER1_SWIER10	(0x1u<<10)
#define	EXTI_SWIER1_SWIER9	(0x1u<<9)
#define	EXTI_SWIER1_SWIER8	(0x1u<<8)
#define	EXTI_SWIER1_SWIER7	(0x1u<<7)
#define	EXTI_SWIER1_SWIER6	(0x1u<<6)
#define	EXTI_SWIER1_SWIER5	(0x1u<<5)
#define	EXTI_SWIER1_SWIER4	(0x1u<<4)
#define	EXTI_SWIER1_SWIER3	(0x1u<<3)
#define	EXTI_SWIER1_SWIER2	(0x1u<<2)
#define	EXTI_SWIER1_SWIER1	(0x1u<<1)
#define	EXTI_SWIER1_SWIER0	(0x1u<<0)

// PR1 Configuration

#define	EXTI_PR1_PR22		(0x1u<<22)
#define	EXTI_PR1_PR21		(0x1u<<21)
#define	EXTI_PR1_PR20		(0x1u<<20)
#define	EXTI_PR1_PR19		(0x1u<<19)
#define	EXTI_PR1_PR18		(0x1u<<18)
#define	EXTI_PR1_PR16		(0x1u<<16)
#define	EXTI_PR1_PR15		(0x1u<<15)
#define	EXTI_PR1_PR14		(0x1u<<14)
#define	EXTI_PR1_PR13		(0x1u<<13)
#define	EXTI_PR1_PR12		(0x1u<<12)
#define	EXTI_PR1_PR11		(0x1u<<11)
#define	EXTI_PR1_PR10		(0x1u<<10)
#define	EXTI_PR1_PR9		(0x1u<<9)
#define	EXTI_PR1_PR8		(0x1u<<8)
#define	EXTI_PR1_PR7		(0x1u<<7)
#define	EXTI_PR1_PR6		(0x1u<<6)
#define	EXTI_PR1_PR5		(0x1u<<5)
#define	EXTI_PR1_PR4		(0x1u<<4)
#define	EXTI_PR1_PR3		(0x1u<<3)
#define	EXTI_PR1_PR2		(0x1u<<2)
#define	EXTI_PR1_PR1		(0x1u<<1)
#define	EXTI_PR1_PR0		(0x1u<<0)

// IMR2 Configuration

#define	EXTI_IMR2_MR39		(0x1u<<7)
#define	EXTI_IMR2_MR38		(0x1u<<6)
#define	EXTI_IMR2_MR37		(0x1u<<5)
#define	EXTI_IMR2_MR36		(0x1u<<4)
#define	EXTI_IMR2_MR35		(0x1u<<3)
#define	EXTI_IMR2_MR34		(0x1u<<2)
#define	EXTI_IMR2_MR33		(0x1u<<1)
#define	EXTI_IMR2_MR32		(0x1u<<0)

// EMR2 Configuration

#define	EXTI_EMR2_MR39		(0x1u<<7)
#define	EXTI_EMR2_MR38		(0x1u<<6)
#define	EXTI_EMR2_MR37		(0x1u<<5)
#define	EXTI_EMR2_MR36		(0x1u<<4)
#define	EXTI_EMR2_MR35		(0x1u<<3)
#define	EXTI_EMR2_MR34		(0x1u<<2)
#define	EXTI_EMR2_MR33		(0x1u<<1)
#define	EXTI_EMR2_MR32		(0x1u<<0)

// RTSR2 Configuration

#define	EXTI_RTSR2_RT38		(0x1u<<6)
#define	EXTI_RTSR2_RT37		(0x1u<<5)
#define	EXTI_RTSR2_RT36		(0x1u<<4)
#define	EXTI_RTSR2_RT35		(0x1u<<3)

// FTSR2 Configuration

#define	EXTI_FTSR2_FT38		(0x1u<<6)
#define	EXTI_FTSR2_FT37		(0x1u<<5)
#define	EXTI_FTSR2_FT36		(0x1u<<4)
#define	EXTI_FTSR2_FT35		(0x1u<<3)

// SWIER2 Configuration

#define	EXTI_SWIER2_SWI38	(0x1u<<6)
#define	EXTI_SWIER2_SWI37	(0x1u<<5)
#define	EXTI_SWIER2_SWI36	(0x1u<<4)
#define	EXTI_SWIER2_SWI35	(0x1u<<3)

// PR2 Configuration

#define	EXTI_PR2_PIF38		(0x1u<<6)
#define	EXTI_PR2_PIF37		(0x1u<<5)
#define	EXTI_PR2_PIF36		(0x1u<<4)
#define	EXTI_PR2_PIF35		(0x1u<<3)
