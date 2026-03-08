/*
; macros_core.
; ============

; SPDX-License-Identifier: MIT

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

// uKernel macros
// --------------

// Core machine in bits

#define	KMACHINE_BITS			(32u)

// Preemptions

#if (!defined(PREEMPTION_THRESHOLD))
#define	PREEMPTION_THRESHOLD(core)																								\
								do {																							\
									extern	proc_t	*vKern_runProc[KNB_CORES]; 													\
																																\
									if (vKern_runProc[(uint32_t)core]->oSpecification.oPriority > KKERN_PRIORITY_LOW_00) {		\
										PREEMPTION;																				\
									}																							\
								} while (0)
#endif

// Elevation macros
// ----------------

#if (!defined(PRIVILEGE_ELEVATE))
#define	PRIVILEGE_ELEVATE
#endif

#if (!defined(PRIVILEGE_RESTORE))
#define	PRIVILEGE_RESTORE
#endif

#if (!defined(RIGHTS_ELEVATION))
#define	RIGHTS_ELEVATION
#endif

#if (!defined(SET_USER_MODE))
#define	SET_USER_MODE
#endif

#if (!defined(SET_PRIVILEGED_MODE))
#define	SET_PRIVILEGED_MODE
#endif

#if (!defined(GET_ADDRESS_ELEVATION_CALLER))
#define GET_ADDRESS_ELEVATION_CALLER
#endif

#if (!defined(GET_ADDRESS_CALLER))
#define GET_ADDRESS_CALLER(address)
#endif

#if (!defined(CALL_FNCT_ELEVATION))
#define CALL_FNCT_ELEVATION(function)
#endif

#if (!defined(KERN_RETURN_ELEVATION))
#define	KERN_RETURN_ELEVATION
#endif

// Interruption macros
// -------------------

#if (!defined(KPROCESS_INIT_MCAUSE))
#define	KPROCESS_INIT_MCAUSE	(MCAUSE_INTERRUPT | RVBB_MCAUSE_MPP(3u) | RVBB_MCAUSE_MPIE | 11u)
#endif

#if (!defined(INTERRUPTION_OFF_HARD))
#define	INTERRUPTION_OFF_HARD	core_clrBitCSR(RV_CSR_MSTATUS, MSTATUS_MIE)
#endif

#if (!defined(INTERRUPTION_ON_HARD))
#define	INTERRUPTION_ON_HARD	core_setBitCSR(RV_CSR_MSTATUS, MSTATUS_MIE)
#endif

#if (!defined(WAITING_INTERRUPTION))
#define	WAITING_INTERRUPTION	__asm volatile ("																			 \n \
								wfi"																						 	\
								)
#endif

#if (!defined(GET_CURRENT_PROCESS_STACK))
#define GET_CURRENT_PROCESS_STACK(stack)										 												\
								__asm volatile ("																			 \n \
								add			%0,x0,sp"																			\
								: "=r" (stack)																					\
								:																								\
								:																								\
								)
#endif

#if (!defined(EXCEPTION_SPECIFIC_HANDLER))
#define KEXCEPTION				0u

extern	void	(*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
extern	bool	vExce_isException[KNB_CORES];

// Suppress the cppcheck warning for the following code portion
// ------------------------------------------------------------

#define EXCLUDE_CPPCHECK
#ifdef EXCLUDE_CPPCHECK

#define	EXCEPTION_SPECIFIC_HANDLER(exc)																							\
								void exc##_local_IRQHandler(void) {																\
									uint32_t	core;																			\
									void		(*go)(void);																	\
																																\
									core = GET_RUNNING_CORE;																	\
									vExce_isException[core] = true;																\
									go = vExce_indExcVectors[core][exc##_IRQn];													\
									(*go)();																					\
									vExce_isException[core] = false;															\
								}																								\
																																\
								void exc##_IRQHandler(void) __attribute__ ((weak, naked));										\
								void exc##_IRQHandler(void) {																	\
																																\
									INTERRUPTION_IN;																			\
									CALL_FNCT(exc##_local_IRQHandler);															\
									INTERRUPTION_OUT;																			\
								}
#endif

#else
#define	EXCEPTION_SPECIFIC_HANDLER(irq)
#endif

#if (!defined(INTERRUPT_SPECIFIC_HANDLER))
#define KINTERRUPTION			1u

extern	void	(*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
extern	bool	vExce_isException[KNB_CORES];

// Suppress the cppcheck warning for the following code portion
// ------------------------------------------------------------

#define EXCLUDE_CPPCHECK
#ifdef EXCLUDE_CPPCHECK

#define	INTERRUPT_SPECIFIC_HANDLER(irq)																							\
								void irq##_local_IRQHandler(void) {																\
									uint32_t	core;																			\
									void		(*go)(void);																	\
																																\
									core = GET_RUNNING_CORE;																	\
									vExce_isException[core] = true;																\
									go = vExce_indIntVectors[core][irq##_IRQn];													\
									(*go)();																					\
									vExce_isException[core] = false;															\
								}																								\
																																\
								void irq##_IRQHandler(void) __attribute__ ((weak, naked));										\
								void irq##_IRQHandler(void) {																	\
																																\
									INTERRUPTION_IN;																			\
									CALL_FNCT(irq##_local_IRQHandler);															\
									INTERRUPTION_OUT;																			\
								}
#endif

#else
#define	INTERRUPT_SPECIFIC_HANDLER(irq)
#endif

// Misc assembler macro
// --------------------

#if (!defined(NOP))
#define	NOP 					__asm volatile ("																			 \n \
								nop"																						 	\
								)
#endif

#if (!defined(JUMP_FNCT))
#define JUMP_FNCT(function)																										\
								__asm volatile ("																			 \n \
								j			"#function																			\
								)
#endif

#if (!defined(CALL_FNCT))
#define CALL_FNCT(function)																										\
								__asm volatile ("																			 \n \
								jal			"#function																			\
								)
#endif

// Stack frame macros
// ------------------

#include	"macros_core_stackFrame.h"
