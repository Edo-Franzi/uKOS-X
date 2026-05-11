/*
; macros_soc.
; ===========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Important macros.
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

// Multicore macro
// ---------------

#define	KNB_CORES				1u
#define	KCORE_0					0u

#if (!defined(GET_RUNNING_CORE))
#define	GET_RUNNING_CORE		0u
#endif

#if (!defined(MCSET))
#if		(KNB_CORES == 1)
#define MCSET(v)				{ (v) }
#else
#error	"*** The number of cores (KNB_CORES) exceed 1"
#endif
#endif

// Baudrate macro
// --------------

#define	DIV(ck, baudrate)		((uint32_t)(ck/(baudrate * 16u)))
#define	REM(ck, baudrate)		((uint32_t)((((ck/(baudrate * 16.0)) - DIV(ck, baudrate)) * 16.0) + 0.5))
#define	BAUDRATE(ck, baudrate)	(DIV(ck, baudrate)<<4u | REM(ck, baudrate))

// Interruption macros
// -------------------

// nlbit = 3 (LEVEL3) -> LLL1 1111 (set by default at the start-up)
//
// LLLH HHHH means that the possible interruption level should be:
//
// 000H HHHH	31
// 001H HHHH	63
// 010H HHHH	95
// 011H HHHH	127
// 100H HHHH	159
// 101H HHHH	191
// 110H HHHH	223
// 111H HHHH	255
//
// ctl = 7 -> LLL = 011, level = 127
// MTH = 31

enum {

// Reserved names: all the possible levels
// Priorities used to set the ECLIC. levels indicated with _KERNEL_
// are reserved for the uKernel (!!! do not change those values)

		KINT_LEVEL_ALL				 = 32u,
		KINT_LEVEL_KERNEL_PREEMPTION = 64u,
		KINT_LEVEL_KERNEL_TIMERS	 = 96u,
		KINT_LEVEL_PERIPHERALS		 = 128u,
		KINT_LEVEL_COMMUNICATIONS	 = 160u,
		KINT_LEVEL_KERNEL_SWI		 = 192u
};

// Reserved names: all the possible masks
// Masks used to filter some priorities
// KINT_IMASK_ALL				Allows all
// KINT_IMASK_KERNEL_PREEMPTION	Allows only NMI, SWI, communications, peripherals, kernel timers, kernel preemptions
// KINT_IMASK_PERIPHERALS		Allows only NMI, SWI, communications, peripherals
// KINT_IMASK_COMMUNICATIONS	Allows only NMI, SWI, communications
// KINT_IMASK_KERNEL_TIMERS		Allows only NMI, SWI, communications, peripherals, kernel timers
// KINT_IMASK_KERNEL_SWI		Allows only NMI, SWI
// KINT_IMASK_OFF				Allows only NMI, SWI

#define	KINT_IMASK_ALL					(KINT_LEVEL_ALL - 1u)
#define	KINT_IMASK_KERNEL_PREEMPTION	(KINT_LEVEL_KERNEL_PREEMPTION - 1u)
#define	KINT_IMASK_KERNEL_TIMERS		(KINT_LEVEL_KERNEL_TIMERS - 1u)
#define	KINT_IMASK_PERIPHERALS			(KINT_LEVEL_PERIPHERALS - 1u)
#define	KINT_IMASK_COMMUNICATIONS		(KINT_LEVEL_COMMUNICATIONS - 1u)
#define	KINT_IMASK_KERNEL_SWI			(KINT_LEVEL_KERNEL_SWI - 1u)
#define	KINT_IMASK_OFF					(KINT_LEVEL_KERNEL_SWI - 1u)

// Names for the user applications

#define	KHW_PRIORITY_LOW				KINT_LEVEL_KERNEL_PREEMPTION
#define	KHW_PRIORITY_MODERATE			KINT_LEVEL_KERNEL_TIMERS
#define	KHW_PRIORITY_HIGH				KINT_LEVEL_PERIPHERALS
#define	KHW_PRIORITY_VERY_HIGH			KINT_LEVEL_COMMUNICATIONS

// EXTI0 Used for passing messages (change the context)
// EXTI1 Used for preemption (change the context)

#define	BKERN_MESSAGES			0u
#define	BKERN_PREEMPTION		1u

#if (!defined(SET_MESSAGE))
#define	SET_MESSAGE				EXTI->SWIEV |= (1u<<BKERN_MESSAGES);															\
								while ((EXTI->SWIEV & (1u<<BKERN_MESSAGES)) != 0u) { ; }
#endif

#if (!defined(PREEMPTION))
#define	PREEMPTION				EXTI->SWIEV |= (1u<<BKERN_PREEMPTION)
#endif

#if (!defined(INTERRUPTION_SET))
#define	INTERRUPTION_SET		ECLIC->MTH = KINT_IMASK_ALL
#endif

#if (!defined(INTERRUPTION_SET_PERIPH))
#define	INTERRUPTION_SET_PERIPH	ECLIC->MTH = KINT_IMASK_PERIPHERALS
#endif

#if (!defined(INTERRUPTION_OFF))
#define	INTERRUPTION_OFF		[[maybe_unused]] volatile	uint32_t	__saveECLIC_msk;										\
								__saveECLIC_msk = (uint32_t)ECLIC->MTH;															\
								(void)__saveECLIC_msk;																			\
								ECLIC->MTH = KINT_IMASK_OFF
#endif

#if (!defined(INTERRUPTION_RESTORE))
#define	INTERRUPTION_RESTORE	ECLIC->MTH = (uint8_t)__saveECLIC_msk
#endif

#if (!defined(RETURN_INT_RESTORE))
#define	RETURN_INT_RESTORE(status)																								\
								INTERRUPTION_RESTORE;																			\
								return (status)
#endif

#if (!defined(INTERRUPTION_OFF_CRITICAL))
#define	INTERRUPTION_OFF_CRITICAL(savemMask)																					\
								savemMask = (volatile uint32_t)ECLIC->MTH;														\
								ECLIC->MTH = KINT_IMASK_OFF
#endif

#if (!defined(INTERRUPTION_RESTORE_CRITICAL))
#define	INTERRUPTION_RESTORE_CRITICAL(savemMask)																				\
								ECLIC->MTH = (uint8_t)(savemMask)
#endif

extern	bool	vExce_isException[KNB_CORES];

#if (!defined(IS_EXCEPTION))
#define	IS_EXCEPTION			(vExce_isException[0])
#endif

// The following macros should be located in the macro_core.
// However, there is no standard concerning the interruption management,
// so, to remain as generic as possible I decided to place these macros
// in the macr_soc

#define	EXCEPTION_VECTOR(vectorNb, address)																						\
								vExce_indExcVectors[GET_RUNNING_CORE][vectorNb] = address

#define	INTERRUPT_VECTOR(vectorNb, address)																						\
								vExce_indIntVectors[GET_RUNNING_CORE][vectorNb] = address
