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

#include	"./kern/privileges.h"
#include	"linker.h"

// uKernel macros
// --------------

// For selecting Secure/NSecure

#if (defined(SECURE_S))
#define	REG(x)					(x ## _S)
#elif (defined(SECURE_NS))
#define	REG(x)					(x ## _NS)
#else
#define	REG(x)					(x ## _S)
#endif

#define	SEC(x)					(x ## _S)
#define	NONSEC(x)				(x ## _NS)

// Core machine in bits

#define	KMACHINE_BITS			(32u)

// Preemptions

#if (!defined(PREEMPTION))
#define	PREEMPTION				stub_kern_stopProcessTimeout();																	\
								REG(SCB)->ICSR = (1u<<BKERN_PREEMPTION);														\
								__asm volatile ("																			 \n \
								sev"																							\
								);																								\
								MEMO_SYNC_BARRIER;																				\
								DATA_SYNC_BARRIER;																				\
								INST_SYNC_BARRIER;
#endif

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
#if (defined(PRIVILEGED_USER_S))
#define	PRIVILEGE_ELEVATE		kern_setPrivilegeMode(KPROC_PRIVILEGED)

#else
#define	PRIVILEGE_ELEVATE
#endif
#endif

#if (!defined(PRIVILEGE_RESTORE))
#if (defined(PRIVILEGED_USER_S))
#define	PRIVILEGE_RESTORE		kern_setPrivilegeMode(KPROC_USER)

#else
#define	PRIVILEGE_RESTORE
#endif
#endif

#if (!defined(RIGHTS_ELEVATION))
#define	RIGHTS_ELEVATION		__asm volatile ("																			 \n \
								.global		priv_returnElevation															 \n \
								svc			%0																				 \n \
								priv_returnElevation:"																			\
								:																								\
								: "i" (KPRIV_ELEVATION)																			\
								:																								\
								);																								\
								MEMO_SYNC_BARRIER;																				\
								DATA_SYNC_BARRIER;																				\
								INST_SYNC_BARRIER;
#endif

#if (!defined(SET_USER_MODE))
#define	SET_USER_MODE			core_setCONTROL(core_getCONTROL() | CONTROL_SET_USER_MODE);										\
								INST_SYNC_BARRIER
#endif

#if (!defined(SET_PRIVILEGED_MODE))
#define	SET_PRIVILEGED_MODE		core_setCONTROL(core_getCONTROL() & ~CONTROL_SET_USER_MODE);									\
								INST_SYNC_BARRIER
#endif

#if (!defined(GET_ADDRESS_ELEVATION_CALLER))
#define GET_ADDRESS_ELEVATION_CALLER																							\
								__asm volatile ("																			 \n \
								tst			lr,#0x4																			 \n \
								ite 		eq																				 \n \
								mrseq		r0,msp																			 \n \
								mrsne		r0,psp																			 \n \
								ldr			r0,[r0,#24]"																		\
								)
#endif

#if (!defined(GET_ADDRESS_CALLER))
#define GET_ADDRESS_CALLER(address)																								\
								address = core_getLR()
#endif

#if (!defined(CALL_FNCT_ELEVATION))
#define CALL_FNCT_ELEVATION(function)																							\
								__asm volatile ("																			 \n	\
								push		{lr}																			 \n	\
								mov			r1,%0																			 \n	\
								blx			r1																				 \n	\
								pop			{lr}"																				\
								:																								\
								: "r" (function)																				\
								: "r0"																							\
								)
#endif

#if (!defined(KERN_RETURN_ELEVATION))
#define	KERN_RETURN_ELEVATION	__asm volatile ("																			 \n \
								bx			lr"																					\
								)
#endif

// Interruption macros
// -------------------

#if (!defined(INTERRUPTION_SET))
#define	INTERRUPTION_SET		core_setBASEPRI((uint32_t)KINT_IMASK_ALL<<(uint32_t)KNVIC_PRIORITY_SHIFT)
#endif

#if (!defined(INTERRUPTION_SET_PERIPH))
#define	INTERRUPTION_SET_PERIPH	core_setBASEPRI((uint32_t)KINT_IMASK_PERIPHERALS<<(uint32_t)KNVIC_PRIORITY_SHIFT)
#endif

#if (!defined(INTERRUPTION_OFF_HARD))
#define	INTERRUPTION_OFF_HARD	__asm volatile ("																			 \n \
								cpsid		i"																					\
								);																								\
								INST_SYNC_BARRIER;
#endif

#if (!defined(INTERRUPTION_ON_HARD))
#define	INTERRUPTION_ON_HARD	__asm volatile ("																			 \n \
								cpsie		i"																					\
								);																								\
								INST_SYNC_BARRIER;
#endif

#if (!defined(INTERRUPTION_OFF))
#define	INTERRUPTION_OFF		volatile	uint32_t	saveBASEPRI __attribute__ ((unused));									\
																																\
								saveBASEPRI = core_getBASEPRI();																\
								(void)saveBASEPRI;																				\
								core_setBASEPRI((uint32_t)KINT_IMASK_OFF<<(uint32_t)KNVIC_PRIORITY_SHIFT)
#endif

#if (!defined(INTERRUPTION_RESTORE))
#define	INTERRUPTION_RESTORE	core_setBASEPRI(saveBASEPRI)
#endif

#if (!defined(RETURN_INT_RESTORE))
#define	RETURN_INT_RESTORE(status)																								\
								INTERRUPTION_RESTORE;																			\
								return (status)
#endif

#if (!defined(INTERRUPTION_OFF_CRITICAL))
#define	INTERRUPTION_OFF_CRITICAL(savemMask)																					\
								savemMask = core_getBASEPRI();																	\
								core_setBASEPRI((uint32_t)KINT_IMASK_OFF<<(uint32_t)KNVIC_PRIORITY_SHIFT)
#endif

#if (!defined(INTERRUPTION_RESTORE_CRITICAL))
#define	INTERRUPTION_RESTORE_CRITICAL(savemMask)																				\
								core_setBASEPRI(savemMask)
#endif

#if (!defined(WAITING_INTERRUPTION))
#define	WAITING_INTERRUPTION	DATA_SYNC_BARRIER;																				\
								__asm volatile ("																			 \n \
								wfi"																							\
								);																								\
								INST_SYNC_BARRIER;
#endif

#if (!defined(WAITING_EVENT))
#define	WAITING_EVENT			DATA_SYNC_BARRIER;																				\
								__asm volatile ("																			 \n \
								wfe"																							\
								);																								\
								INST_SYNC_BARRIER;
#endif

#if (!defined(IS_EXCEPTION))
#define	IS_EXCEPTION			((REG(SCB)->ICSR & 0x000001FFu) != 0u)
#endif

#if (!defined(GET_CURRENT_PROCESS_STACK))
#define GET_CURRENT_PROCESS_STACK(stack)										 												\
								stack = core_getPSP()
#endif

#if (!defined(EXCEPTION_SPECIFIC_HANDLER))
#define KEXCEPTION				0u

extern	volatile	bool	vPriv_insideException[KNB_CORES];
extern				void	(*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);

#define	EXCEPTION_SPECIFIC_HANDLER(irq)																							\
								void irq##_IRQHandler(void) __attribute__ ((weak));												\
								void irq##_IRQHandler(void) {																	\
									uint32_t	core;																			\
									void		(*go)(void);																	\
																																\
									core = GET_RUNNING_CORE;																	\
									vPriv_insideException[core] = true;															\
									go = vExce_indExcVectors[core][(int32_t)irq##_IRQn + (int32_t)KNB_EXCEPTIONS];				\
									(*go)();																					\
								}
#endif

#if (!defined(INTERRUPT_SPECIFIC_HANDLER))
#define KINTERRUPTION			1u

extern	void	(*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);

#define	INTERRUPT_SPECIFIC_HANDLER(irq)																							\
								void irq##_IRQHandler(void) __attribute__ ((weak));												\
								void irq##_IRQHandler(void) {																	\
									uint32_t	core;																			\
									void		(*go)(void);																	\
																																\
									core = GET_RUNNING_CORE;																	\
									TIC_EXCEPTION_TIME;																			\
									go = vExce_indIntVectors[core][irq##_IRQn];													\
									(*go)();																					\
									TAC_EXCEPTION_TIME(core);																	\
								}
#endif

// Misc assembler macro
// --------------------

#if (!defined(SET_PSP_STACK))
#define	SET_PSP_STACK(stack)	core_setPSP((uintptr_t)stack)
#endif

#if (!defined(SET_MSP_STACK))
#define	SET_MSP_STACK(stack)	core_setMSP((uintptr_t)stack)
#endif

#if (!defined(SET_THREAD_STACK))
#define	SET_THREAD_STACK(stack)	__asm volatile ("																			 \n \
								msr			psp,%0"																				\
								:																								\
								: "r" (stack)																					\
								:																								\
								);																								\
								core_setCONTROL(core_getCONTROL() | CONTROL_SET_PSP_STACK);										\
								INST_SYNC_BARRIER
#endif

// Check in wich stack we are operating
// If we operate from the MSP
// - Copy the MSP to the PSP
// - Set the PSP as the active stack

#if (!defined(CHECKSET_THREAD_STACK))
#define	CHECKSET_THREAD_STACK	if (core_getPSP() == 0u) {										 								\
									core_setPSP(core_getMSP());									 								\
									core_setCONTROL(core_getCONTROL() | CONTROL_SET_PSP_STACK);	 								\
									INST_SYNC_BARRIER;											 								\
								}
#endif

#if (!defined(NOP))
#define	NOP 					__asm volatile ("																			 \n \
								nop"																							\
								)
#endif

#if (!defined(DATA_SYNC_BARRIER))
#define	DATA_SYNC_BARRIER		__asm volatile ("																			 \n \
								dsb			0xF"																				\
								:																								\
								:																								\
								: "memory"																						\
								)
#endif

#if (!defined(INST_SYNC_BARRIER))
#define	INST_SYNC_BARRIER		__asm volatile ("																			 \n \
								isb			0xF"															  					\
								:																								\
								:																								\
								: "memory"																						\
								)
#endif

#if (!defined(MEMO_SYNC_BARRIER))
#define	MEMO_SYNC_BARRIER		__asm volatile ("																			 \n \
								dmb			0xF"															  					\
								:																								\
								:																								\
								: "memory"																						\
								)
#endif

#if (!defined(STRONG_BARRIER))
#define	STRONG_BARRIER			MEMO_SYNC_BARRIER;																				\
								DATA_SYNC_BARRIER;																				\
								INST_SYNC_BARRIER
#endif

#if (!defined(JUMP_FNCT))
#define JUMP_FNCT(function)																										\
								__asm volatile ("																			 \n \
								b			"#function																			\
								)
#endif

#if (!defined(CALL_FNCT))
#define CALL_FNCT(function)																										\
								__asm volatile ("																			 \n \
								bl			"#function																			\
								:																								\
								:																								\
								: "lr"																							\
								)
#endif

// Stack frame macros
// ------------------

#include	"macros_core_stackFrame.h"
