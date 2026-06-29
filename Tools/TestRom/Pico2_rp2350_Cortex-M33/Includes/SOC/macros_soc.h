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

#define	KNB_CORES				2u
#define	KCORE_0					0u
#define	KCORE_1					1u

#if (!defined(GET_RUNNING_CORE))
#define	GET_RUNNING_CORE		(REG(SIO)->CPUID & 1u)
#endif

#if (!defined(MCSET))
#if (KNB_CORES == 1)
#define MCSET(v)				{ (v) }
#elif (KNB_CORES == 2)
#define	MCSET(v)				{ (v), (v) }
#else
#error	"*** The number of cores (KNB_CORES) exceed 2"
#endif
#endif

// Baudrate macro
// --------------

#define	BAUDRATE(UART, ck, baudrate)																							\
	do {																														\
		const uint32_t _den  = 16u * (uint32_t)(baudrate);																		\
		const uint32_t _ibrd = (uint32_t)((uint32_t)(ck) / _den);																\
		const uint32_t _rem  = (uint32_t)((uint32_t)(ck) % _den);																\
																																\
		const uint32_t _fbrd = (uint32_t)((((uint64_t)_rem * (uint64_t)64u) + ((uint64_t)_den / 2u)) / (uint64_t)_den);			\
		REG(UART)->UARTIBRD = _ibrd;																							\
		REG(UART)->UARTFBRD = _fbrd;																							\
	} while (0)

// Interruption macros
// -------------------

enum {

// Reserved names: all the possible levels
// Priorities used to set the NVIC. levels indicated with _KERNEL_
// are reserved for the uKernel (!!! do not change those values)

		KINT_LEVEL_KERNEL_SWI = 1u,
		KINT_LEVEL_VERY_HS_PERIPHERALS,
		KINT_LEVEL_COMMUNICATIONS,
		KINT_LEVEL_PERIPHERALS,
		KINT_LEVEL_KERNEL_TIMERS,
		KINT_LEVEL_KERNEL_PREEMPTION,
		KINT_LEVEL_ALL
};

// Reserved names: all the possible masks
// Masks used to filter some priorities
// KINT_IMASK_OFF					Allows only NMI, SWI
// KINT_IMASK_KERNEL_SWI			Allows only NMI, SWI
// KINT_LEVEL_VERY_HS_PERIPHERALS	Allows only NMI, SWI, HS peripherals, communications
// KINT_IMASK_COMMUNICATIONS		Allows only NMI, SWI, HS peripherals, communications
// KINT_IMASK_PERIPHERALS			Allows only NMI, SWI, HS peripherals, communications, peripherals
// KINT_IMASK_KERNEL_TIMERS			Allows only NMI, SWI, HS peripherals, communications, peripherals, kernel timers
// KINT_IMASK_KERNEL_PREEMPTION		Allows only NMI, SWI, HS peripherals, communications, peripherals, kernel timers, kernel preemptions
// KINT_IMASK_ALL					Allows all

#define	KINT_IMASK_OFF					(KINT_LEVEL_KERNEL_SWI + 1u)
#define	KINT_IMASK_KERNEL_SWI			(KINT_LEVEL_KERNEL_SWI + 1u)
#define	KINT_IMASK_VERY_HS_PERIPHERALS	(KINT_LEVEL_VERY_HS_PERIPHERALS + 1u)
#define	KINT_IMASK_COMMUNICATIONS		(KINT_LEVEL_COMMUNICATIONS + 1u)
#define	KINT_IMASK_PERIPHERALS			(KINT_LEVEL_PERIPHERALS + 1u)
#define	KINT_IMASK_KERNEL_TIMERS		(KINT_LEVEL_KERNEL_TIMERS + 1u)
#define	KINT_IMASK_KERNEL_PREEMPTION	(KINT_LEVEL_KERNEL_PREEMPTION + 1u)
#define	KINT_IMASK_ALL					(KINT_LEVEL_ALL + 1u)

// Names for the user applications

#define	KHW_PRIORITY_LOW				KINT_LEVEL_KERNEL_PREEMPTION
#define	KHW_PRIORITY_MODERATE			KINT_LEVEL_KERNEL_TIMERS
#define	KHW_PRIORITY_HIGH				KINT_LEVEL_PERIPHERALS
#define	KHW_PRIORITY_VERY_HIGH			KINT_LEVEL_COMMUNICATIONS

// 2^4 priority levels
// Priority shift inside the NVIC->PR (P3 P2 P1 P0 x x x x) !!! Vendor specific

#define	KNVIC_PRIORITY_BITS		4u
#define	KNVIC_PRIORITY_SHIFT	(8u - KNVIC_PRIORITY_BITS)

// PENDSVSET used for preemption (change the context)

#define	BKERN_PREEMPTION		28u

#define	EXCEPTION_VECTOR(vectorNb, address)																						\
								vExce_indExcVectors[GET_RUNNING_CORE][(int32_t)vectorNb + (int32_t)KNB_EXCEPTIONS] = address

#define	INTERRUPT_VECTOR(vectorNb, address)																						\
								vExce_indIntVectors[GET_RUNNING_CORE][vectorNb] = address
