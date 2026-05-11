/*
; macros_core.
; ============

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

// uKernel macros
// --------------

// Core machine in bits

#define	KMACHINE_BITS			(64u)

// Preemptions

#if (!defined(KSTATUS))
#define	KSTATUS					(MSTATUS64_SD | MSTATUS_FS | MSTATUS_MPP | MSTATUS_MPIE)
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
#define	KPROCESS_INIT_MCAUSE	(MCAUSE_INTERRUPT | 11u)
#endif

#if (!defined(RETURN_INT_RESTORE))
#define	RETURN_INT_RESTORE(status)																								\
								INTERRUPTION_RESTORE;																			\
								return (status)
#endif


#if (!defined(WAITING_INTERRUPTION))
#define	WAITING_INTERRUPTION	__asm volatile ("																			 \n \
								wfi"																							\
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

#if (!defined(NOP))
#define	NOP 					__asm volatile ("																			 \n \
								nop"																							\
								)
#endif

#if (!defined(JUMP_FNCT))
#define JUMP_FNCT(function)																										\
								__asm volatile ("																			 \n \
								j			"#function																			\
								)
#endif

// Stack frame macros
// ------------------

#if ((!defined(__clang__)) && (__GNUC__ >= 14))
#include	"macros_core_stackFrame_gcc.h"
#endif

#if (defined(__clang__))
#include	"macros_core_stackFrame_clang.h"
#endif
