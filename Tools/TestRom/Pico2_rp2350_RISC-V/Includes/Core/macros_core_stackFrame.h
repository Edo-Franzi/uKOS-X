/*
; macros_core_stackFrame.
; =======================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Stack frame management macros.
;			This file conains the most sensitive macros
;			for the uKernel management
;
;   (c) 2025-2026, Laurent von Allmen
;   ---------------------------------
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

#include	<stdlib.h>		// IWYU pragma: keep (for exit)

#include	"macros_soc.h"
#include	"types.h"		// IWYU pragma: keep (for EXIT_OS_PANIC_STACK_UNDERFLOW)

// For the stack sanity

#ifndef KMAGICSTACK
#define KMAGICSTACK				(((uint32_t)'u'<<24U) | ((uint32_t)'K'<<16U) | ((uint32_t)'O'<<8U) | (uint32_t)'S')
#endif

#ifndef BREAK_IFDEBUGGING
#define	BREAK_IFDEBUGGING
#endif

#ifndef CHECK_STACK_SANITY
#define CHECK_STACK_SANITY(core)																								\
								if ((vKern_runProc[core]->oInternal.oState != 0U) && 											\
									((vKern_runProc[core]->oInternal.oState & (1U<<BPROC_FIRST)) == 0U)) {						\
									if ((vKern_runProc[core]->oSpecification.oStackStart > vKern_stackProc[core]) ||			\
										(vKern_runProc[core]->oSpecification.oStackStart[core] != KMAGICSTACK)) {			  	\
										LOG(KFATAL_KERNEL, "kern: stack underflow");										  	\
										BREAK_IFDEBUGGING;															  			\
										exit(EXIT_OS_PANIC_STACK_UNDERFLOW);											  		\
									}																				  			\
								}
#endif

// Stack alignment (see processes.h)

#ifndef KSTACK_ALIGNMENT
#define	KSTACK_ALIGNMENT		(16U)
#define	KSTACK_ALIGNMENT_MASK	(~(KSTACK_ALIGNMENT - 1U))
#define	KSTACK_ALIGNMENT_MEMO	(KMEMO_ALIGN_16)
#endif

// Critical stack size when < (35+10) 32-bit words (stack frame + reserve)

#ifndef KKERN_CRITICAL_SZ_STACK
#define	KKERN_CRITICAL_SZ_STACK		(35U + 10U)
#endif

// Stack sizes (in machine words of 32-bit)

#ifndef KKERN_SZ_STACK_SS
#define	KKERN_SZ_STACK_SS			200U
#endif
#ifndef KKERN_SZ_STACK_MM
#define	KKERN_SZ_STACK_MM			400U
#endif
#ifndef KKERN_SZ_STACK_LL
#define	KKERN_SZ_STACK_LL			600U
#endif
#ifndef KKERN_SZ_STACK_XL
#define	KKERN_SZ_STACK_XL			1000U
#endif
#ifndef KKERN_SZ_STACK_MIN
#define	KKERN_SZ_STACK_MIN			300U
#endif
#ifndef KKERN_SZ_STACK_XLIB
#define	KKERN_SZ_STACK_XLIB			(400U + 1000U)
#endif
#ifndef KKERN_SZ_STACK_MPY
#define	KKERN_SZ_STACK_MPY			(400U + 1000U)
#endif

// Stack frame macros
// ------------------

// Prepare the stack frame
//
// The stack has to be aligned on boundary of 16-bytes
// In this case the (140 + 4) mod 16 has to be 0
//
//	+140	"uKOS"			= KMAGICSTACK
//	+136	x1 ra			= address of the routine exit_terminate()
//	+132	x5 t0			=
//	+128	x6 t1			=
//	+124	x7 t2			=
//	+120	x8 s0 fp		=
//	+116	x10 a0			= process arguments
//	+112	x11 a1			=
//	+108	x12 a2			=
//	+104	x13 a3			=
//	+100	x14 a4			=
//	+96		x15 a5			=
//	+92		x16 a6			=
//	+88		x17 a7			=
//	+84		x28 t3			=
//	+80		x29 t4			=
//	+76		x30 t5			=
//	+72		x31 t6			=
//	+68		void (skip x0)	=
//	+64		x3 gp			=
//	+60		x4 tp			=
//	+56		x9 s1			=
//	+52		x18 s2			=
//	+48		x19 s3			=
//	+44		x20 s4			=
//	+40		x21 s5			=
//	+36		x22 s6			=
//	+32		x23 s7			=
//	+28		x24 s8			=
//	+24		x25 s9			=
//	+20		x26 s10			=
//	+16		x27 s11			=
//	+12		ECLIC-mth		=
//	+8		mstatus			=
//	+4		mcause			=
//	+0		mepc			= process address

#ifndef KERN_PREPARE_FRAME
#define KERN_PREPARE_FRAME(stack, code, core, argument, priority)										  						\
								*(--stack) = KMAGICSTACK;							/* "uKOS"			*/						\
								*(--stack) = (uintptr_t)exit_terminate;				/* x1 ra			*/						\
								*(--stack) = 0x05050505u;							/* x5 t0			*/						\
								*(--stack) = 0x06060606u;							/* x6 t1			*/						\
								*(--stack) = 0x07070707u;							/* x7 t2			*/						\
								*(--stack) = 0x08080808u;							/* x8 s0 fp			*/						\
								*(--stack) = (uintptr_t)argument;					/* x10 a0			*/						\
								*(--stack) = 0x11111111u;							/* x11 a1			*/						\
								*(--stack) = 0x12121212u;							/* x12 a2			*/						\
								*(--stack) = 0x13131313u;							/* x13 a3			*/						\
								*(--stack) = 0x14141414u;							/* x14 a4			*/						\
								*(--stack) = 0x15151515u;							/* x15 a5			*/						\
								*(--stack) = 0x16161616u;							/* x16 a6			*/						\
								*(--stack) = 0x17171717u;							/* x17 a7			*/						\
								*(--stack) = 0x28282828u;							/* x28 t3			*/						\
								*(--stack) = 0x29292929u;							/* x29 t4			*/						\
								*(--stack) = 0x30303030u;							/* x30 t5			*/						\
								*(--stack) = 0x31313131u;							/* x31 t6			*/						\
								--stack;											/* void (skip x0)	*/						\
								*(--stack) = 0x03030303u;							/* x3 gp			*/						\
								*(--stack) = 0x04040404u;							/* x4 tp			*/						\
								*(--stack) = 0x09090909u;							/* x9 s1			*/						\
								*(--stack) = 0x18181818u;							/* x18 s2			*/						\
								*(--stack) = 0x19191919u;							/* x19 s3			*/						\
								*(--stack) = 0x20202020u;							/* x20 s4			*/						\
								*(--stack) = 0x21212121u;							/* x21 s5			*/						\
								*(--stack) = 0x22222222u;							/* x22 s6			*/						\
								*(--stack) = 0x23232323u;							/* x23 s7			*/						\
								*(--stack) = 0x24242424u;							/* x24 s8			*/						\
								*(--stack) = 0x25252525u;							/* x25 s9			*/						\
								*(--stack) = 0x26262626u;							/* x26 s10			*/						\
								*(--stack) = 0x27272727u;							/* x27 s11			*/						\
								*(--stack) = priority;								/* Priority			*/						\
								*(--stack) = MSTATUS_MPP | MSTATUS_MPIE;			/* mstatus			*/						\
								*(--stack) = KPROCESS_INIT_MCAUSE;					/* mcause			*/						\
								*(--stack) = (uintptr_t)code;						/* mepc				*/						\
								(void)(core)
#endif

// Recover the message
//
//	+140	Message			= uKOS-X message
//	+136	x1 ra			=
//	+132	x5 t0			=
//	+128	x6 t1			=
//	+124	x7 t2			=
//	+120	x8 s0 fp		=
//	+116	x10 a0			= process arguments
//	+112	x11 a1			=
//	+108	x12 a2			=
//	+104	x13 a3			=
//	+100	x14 a4			=
//	+96		x15 a5			=
//	+92		x16 a6			=
//	+88		x17 a7			=
//	+84		x28 t3			=
//	+80		x29 t4			=
//	+76		x30 t5			=
//	+72		x31 t6			=
//	+68		void (skip x0)	=
//	+64		x3 gp			=
//	+60		x4 tp			=
//	+56		x9 s1			=
//	+52		x18 s2			=
//	+48		x19 s3			=
//	+44		x20 s4			=
//	+40		x21 s5			=
//	+36		x22 s6			=
//	+32		x23 s7			=
//	+28		x24 s8			=
//	+24		x25 s9			=
//	+20		x26 s10			=
//	+16		x27 s11			=
//	+12		ECLIC-mth		= (reserve the place; it is filled in the model_kernel)
//	+8		mstatus			=
//	+4		mcause			=
//	+0		mepc			= process address
//
// Prepare for the model
//
// a0 -> *stack
// a1 -> message

#ifndef KERN_RECOVER_MESSAGE
#define	KERN_RECOVER_MESSAGE	__asm volatile ("																			 \n \
								lw			t0,35*4(sp)																	 	 \n \
								add			a1,x0,t0"																			\
								)
#endif

// Save the frame
//
//	+136	x1 ra			=
//	+132	x5 t0			=
//	+128	x6 t1			=
//	+124	x7 t2			=
//	+120	x8 s0 fp		=
//	+116	x10 a0			= process arguments
//	+112	x11 a1			=
//	+108	x12 a2			=
//	+104	x13 a3			=
//	+100	x14 a4			=
//	+96		x15 a5			=
//	+92		x16 a6			=
//	+88		x17 a7			=
//	+84		x28 t3			=
//	+80		x29 t4			=
//	+76		x30 t5			=
//	+72		x31 t6			=
//	+68		void (skip x0)	=
//	+64		x3 gp			=
//	+60		x4 tp			=
//	+56		x9 s1			=
//	+52		x18 s2			=
//	+48		x19 s3			=
//	+44		x20 s4			=
//	+40		x21 s5			=
//	+36		x22 s6			=
//	+32		x23 s7			=
//	+28		x24 s8			=
//	+24		x25 s9			=
//	+20		x26 s10			=
//	+16		x27 s11			=
//	+12		ECLIC-mth		= (reserve the place; it is filled in the model_kernel)
//	+8		mstatus			=
//	+4		mcause			=
//	+0		mepc			= process address
//
// Prepare for the model
//
// a0 -> *stack

#ifndef KERN_SAVE_FRAME
#define	KERN_SAVE_FRAME			__asm volatile ("																			 \n \
								addi		sp,sp,-(35*4)																	 \n \
								sw			ra,34*4(sp)																		 \n \
								sw			t0,33*4(sp)																		 \n \
								sw			t1,32*4(sp)																		 \n \
								sw			t2,31*4(sp)																		 \n \
								sw			s0,30*4(sp)																		 \n \
								sw			a0,29*4(sp)																		 \n \
								sw			a1,28*4(sp)																		 \n \
								sw			a2,27*4(sp)																		 \n \
								sw			a3,26*4(sp)																		 \n \
								sw			a4,25*4(sp)																		 \n \
								sw			a5,24*4(sp)																		 \n \
								sw			a6,23*4(sp)																		 \n \
								sw			a7,22*4(sp)																		 \n \
								sw			t3,21*4(sp)																		 \n \
								sw			t4,20*4(sp)																		 \n \
								sw			t5,19*4(sp)																		 \n \
								sw			t6,18*4(sp)																		 \n \
								sw			gp,16*4(sp)																		 \n \
								sw			tp,15*4(sp)																		 \n \
								sw			s1,14*4(sp)																		 \n \
								sw			s2,13*4(sp)																		 \n \
								sw			s3,12*4(sp)																		 \n \
								sw			s4,11*4(sp)																		 \n \
								sw			s5,10*4(sp)																		 \n \
								sw			s6,9*4(sp)																		 \n \
								sw			s7,8*4(sp)																		 \n \
								sw			s8,7*4(sp)																		 \n \
								sw			s9,6*4(sp)																		 \n \
								sw			s10,5*4(sp)																		 \n \
								sw			s11,4*4(sp)																		 \n \
								csrr		t0,mstatus																		 \n \
								sw			t0,2*4(sp)																		 \n \
								csrr		t0,mcause																		 \n \
								sw			t0,1*4(sp)																		 \n \
								csrr		t0,mepc																			 \n \
								sw			t0,0*4(sp)																		 \n \
								add			a0,x0,sp"																		    \
								)
#endif

// Only for non vectorised interruption cores
//
// Caller registers already saved on stack with INTERRUPTION_IN macro (stack already increased by 80, 64 remaining):
// Save the frame
//
//	+136	x1 ra			=
//	+132	x5 t0			=
//	+128	x6 t1			=
//	+124	x7 t2			=
//	+120	x8 s0 fp		=
//	+116	x10 a0			= process arguments
//	+112	x11 a1			=
//	+108	x12 a2			=
//	+104	x13 a3			=
//	+100	x14 a4			=
//	+96		x15 a5			=
//	+92		x16 a6			=
//	+88		x17 a7			=
//	+84		x28 t3			=
//	+80		x29 t4			=
//	+76		x30 t5			=
//	+72		x31 t6			=
//
//	+68		void (skip x0)	=
//	+64		x3 gp			=
//	+60		x4 tp			=
//	+56		x9 s1			=
//	+52		x18 s2			=
//	+48		x19 s3			=
//	+44		x20 s4			=
//	+40		x21 s5			=
//	+36		x22 s6			=
//	+32		x23 s7			=
//	+28		x24 s8			=
//	+24		x25 s9			=
//	+20		x26 s10			=
//	+16		x27 s11			=
//	+12		ECLIC-mth		= (reserve the place; it is filled in the model_kernel)
//	+8		mstatus			=
//	+4		mcause			=
//	+0		mepc			= process address
//
// Prepare for the model
//
// a0 -> *stack

#ifndef KERN_SAVE_FRAME_NO_VECT
#define	KERN_SAVE_FRAME_NO_VECT	__asm volatile ("																			 \n \
								addi		sp,sp,-(18*4)																	 \n \
								sw			gp,16*4(sp)																		 \n \
								sw			tp,15*4(sp)																		 \n \
								sw			s1,14*4(sp)																		 \n \
								sw			s2,13*4(sp)																		 \n \
								sw			s3,12*4(sp)																		 \n \
								sw			s4,11*4(sp)																		 \n \
								sw			s5,10*4(sp)																		 \n \
								sw			s6,9*4(sp)																		 \n \
								sw			s7,8*4(sp)																		 \n \
								sw			s8,7*4(sp)																		 \n \
								sw			s9,6*4(sp)																		 \n \
								sw			s10,5*4(sp)																		 \n \
								sw			s11,4*4(sp)																		 \n \
								csrr		t0,mstatus																		 \n \
								sw			t0,2*4(sp)																		 \n \
								csrr		t0,mcause																		 \n \
								sw			t0,1*4(sp)																		 \n \
								csrr		t0,mepc																			 \n \
								sw			t0,0*4(sp)																		 \n \
								add			a0,x0,sp"																		    \
								);
#endif

// New frame
//
//	+136	x1 ra			=
//	+132	x5 t0			=
//	+128	x6 t1			=
//	+124	x7 t2			=
//	+120	x8 s0 fp		=
//	+116	x10 a0			= process arguments
//	+112	x11 a1			=
//	+108	x12 a2			=
//	+104	x13 a3			=
//	+100	x14 a4			=
//	+96		x15 a5			=
//	+92		x16 a6			=
//	+88		x17 a7			=
//	+84		x28 t3			=
//	+80		x29 t4			=
//	+76		x30 t5			=
//	+72		x31 t6			=
//	+68		void (skip x0)	=
//	+64		x3 gp			=
//	+60		x4 tp			=
//	+56		x9 s1			=
//	+52		x18 s2			=
//	+48		x19 s3			=
//	+44		x20 s4			=
//	+40		x21 s5			=
//	+36		x22 s6			=
//	+32		x23 s7			=
//	+28		x24 s8			=
//	+24		x25 s9			=
//	+20		x26 s10			=
//	+16		x27 s11			=
//	+12		ECLIC-mth		= (reserve the place; it is filled in the model_kernel)
//	+8		mstatus			=
//	+4		mcause			=
//	+0		mepc			= process address
//
// Prepare for the model
//
// a0 -> *stack

#ifndef KERN_NEW_FRAME
#define	KERN_NEW_FRAME			__asm volatile ("																			 \n \
								add			sp,x0,a0																		 \n \
								lw			t0,0*4(sp)																		 \n \
								csrw		mepc,t0																			 \n \
								lw			t0,1*4(sp)																		 \n \
								csrw		mcause,t0																		 \n \
								lw			t0,2*4(sp)																		 \n \
								csrw		mstatus,t0																		 \n \
								lw			s11,4*4(sp)																		 \n \
								lw			s10,5*4(sp)																		 \n \
								lw			s9,6*4(sp)																		 \n \
								lw			s8,7*4(sp)																		 \n \
								lw			s7,8*4(sp)																		 \n \
								lw			s6,9*4(sp)																		 \n \
								lw			s5,10*4(sp)																		 \n \
								lw			s4,11*4(sp)																		 \n \
								lw			s3,12*4(sp)																		 \n \
								lw			s2,13*4(sp)																		 \n \
								lw			s1,14*4(sp)																		 \n \
								lw			tp,15*4(sp)																		 \n \
								lw			gp,16*4(sp)																		 \n \
								lw			t6,18*4(sp)																		 \n \
								lw			t5,19*4(sp)																		 \n \
								lw			t4,20*4(sp)																		 \n \
								lw			t3,21*4(sp)																		 \n \
								lw			a7,22*4(sp)																		 \n \
								lw			a6,23*4(sp)																		 \n \
								lw			a5,24*4(sp)																		 \n \
								lw			a4,25*4(sp)																		 \n \
								lw			a3,26*4(sp)																		 \n \
								lw			a2,27*4(sp)																		 \n \
								lw			a1,28*4(sp)																		 \n \
								lw			a0,29*4(sp)																		 \n \
								lw			s0,30*4(sp)																		 \n \
								lw			t2,31*4(sp)																		 \n \
								lw			t1,32*4(sp)																		 \n \
								lw			t0,33*4(sp)																		 \n \
								lw			ra,34*4(sp)																		 \n \
								addi		sp,sp,(35*4)"														 				\
								)
#endif

// Return to a new context

#ifndef KERN_RETURN
#define	KERN_RETURN				__asm volatile ("																			 \n \
								mret"																							\
								)
#endif

// Messages: _I (immediate) _M (memory)

#ifndef GOTO_KERN_I
#define	GOTO_KERN_I(msg)		__asm	volatile ("																			 \n \
								lui			t0,%%hi(%0)																		 \n \
								li			t0,%%lo(%0)																		 \n \
								addi		sp,sp,-8																		 \n \
								sw			t0,0(sp)																		 \n \
								sw			t0,4(sp)"																		 	\
								:																							 	\
								: "i" (msg)																					 	\
								: "t0"																						 	\
								);																							 	\
								SET_MESSAGE;																				 	\
								__asm volatile ("																			 \n \
								addi		sp,sp,8"																		 	\
								)
#endif

#ifndef GOTO_KERN_M
#define	GOTO_KERN_M(msg)		__asm volatile ("																			 \n \
								add			t0,x0,%0																		 \n \
								addi		sp,sp,-8																		 \n \
								sw			t0,0(sp)																		 \n \
								sw			t0,4(sp)"																		 	\
								:																							 	\
								: "r" (msg)																					 	\
								: "t0"																						 	\
								);																							 	\
								SET_MESSAGE;																				 	\
								__asm volatile ("																			 \n \
								addi		sp,sp,8"																		 	\
								)
#endif

// Interruption macros (IN / OUT)
// Position 0*4 is an empty space ()

#ifndef INTERRUPTION_IN
#define	INTERRUPTION_IN			__asm volatile ("																			 \n \
								addi		sp,sp,-(17*4)																	 \n \
								sw			ra,16*4(sp)																		 \n \
								sw			t0,15*4(sp)																		 \n \
								sw			t1,14*4(sp)																		 \n \
								sw			t2,13*4(sp)																		 \n \
								sw			s0,12*4(sp)																		 \n \
								sw			a0,11*4(sp)																		 \n \
								sw			a1,10*4(sp)																		 \n \
								sw			a2,9*4(sp)																		 \n \
								sw			a3,8*4(sp)																		 \n \
								sw			a4,7*4(sp)																		 \n \
								sw			a5,6*4(sp)																		 \n \
								sw			a6,5*4(sp)																		 \n \
								sw			a7,4*4(sp)																		 \n \
								sw			t3,3*4(sp)																		 \n \
								sw			t4,2*4(sp)																		 \n \
								sw			t5,1*4(sp)																		 \n \
								sw			t6,0*4(sp)"																			\
								)
#endif

#ifndef INTERRUPTION_OUT
#define	INTERRUPTION_OUT		__asm volatile ("																			 \n \
								lw			ra,16*4(sp)																		 \n \
								lw			t0,15*4(sp)																		 \n \
								lw			t1,14*4(sp)																		 \n \
								lw			t2,13*4(sp)																		 \n \
								lw			s0,12*4(sp)																		 \n \
								lw			a0,11*4(sp)																		 \n \
								lw			a1,10*4(sp)																		 \n \
								lw			a2,9*4(sp)																		 \n \
								lw			a3,8*4(sp)																		 \n \
								lw			a4,7*4(sp)																		 \n \
								lw			a5,6*4(sp)																		 \n \
								lw			a6,5*4(sp)																		 \n \
								lw			a7,4*4(sp)																		 \n \
								lw			t3,3*4(sp)																		 \n \
								lw			t4,2*4(sp)																		 \n \
								lw			t5,1*4(sp)																		 \n \
								lw			t6,0*4(sp)																		 \n \
								addi		sp,sp,(17*4)																	 \n \
								mret"																						 	\
								)
#endif

// Core dump register collection
//
//	+152	x1 ra			=
//	+148	x5 t0			=
//	+144	x6 t1			=
//	+140	x7 t2			=
//	+136	x8 s0 fp		=
//	+132	x10 a0			=
//	+128	x11 a1			=
//	+124	x12 a2			=
//	+120	x13 a3			=
//	+116	x14 a4			=
//	+112	x15 a5			=
//	+108	x16 a6			=
//	+104	x17 a7			=
//	+100	x28 t3			=
//	+96		x29 t4			=
//	+92		x30 t5			=
//	+88		x31 t6			= <---- Saved by INTERRUPTION_IN
//
// gcc-14 add 4-words
//
//	+72		x0				=
//  +68		x3 gp			=
//	+64		x4 tp			=
//	+60		x9 s1			=
//	+56		x18 s2			=
//	+52		x19 s3			=
//	+48		x20 s4			=
//	+44		x21 s5			=
//	+40		x22 s6			=
//	+36		x23 s7			=
//	+32		x24 s8			=
//	+28		x25 s9			=
//	+24		x26 s10			=
//	+20		x27 s11			=
//	+16		Reserve			=
//	+12		mstatus			=
//	+8		mcause			=
//	+4		mepc			= process address
//	+0		sp				=
//
// Prepare for the model
//
// a0 -> *stackBefore saving the frame
// a1 -> *stackAfter having saved the frame

enum {
		sp = 0U,										// sp + 0
		epcm, causem, statusm, 							// sp + 1..3
		Reserve,										// sp + 4
		s11, s10, s9, s8, s7, s6, s5, s4, s3, s2, s1,	// sp + 5..15
		tp,	 gp,										// sp + 16..17
		x0,												// sp + 18
		t6 = (x0 + 1 + 4), t5, t4, t3,					// sp + (20..23) + 5
		a7, a6, a5, a4, a3, a2, a1, a0,					// sp + (24..31) + 5
		s0,												// sp + (32) + 5
		t2, t1, t0,										// sp + (33..35) + 5
		ra,												// sp + (36) + 5
		ENDREG											// sp + (37) + 5
};

// IMPORTANT! This macro HAS to prepare a0 & a1 with
// the value of the stack before and after the stacking
// to comply with the ABI of local_processException(uintptr_t *stackBefore, uintptr_t *stackAfter)

#ifndef CORE_DUMP_SAVE_STACK_FRAME
#define CORE_DUMP_SAVE_STACK_FRAME																								\
								__asm volatile ("																			 \n \
								addi		sp,sp,-(19*4)																	 \n \
								sw			x0,18*4(sp)																		 \n \
								sw			gp,17*4(sp)																		 \n \
								sw			tp,16*4(sp)																		 \n \
								sw			s1,15*4(sp)																		 \n \
								sw			s2,14*4(sp)																		 \n \
								sw			s3,13*4(sp)																		 \n \
								sw			s4,12*4(sp)																		 \n \
								sw			s5,11*4(sp)																		 \n \
								sw			s6,10*4(sp)																		 \n \
								sw			s7,9*4(sp)																		 \n \
								sw			s8,8*4(sp)																		 \n \
								sw			s9,7*4(sp)																		 \n \
								sw			s10,6*6(sp)																		 \n \
								sw			s11,5*4(sp)																		 \n \
								add			t0,x0,x0																		 \n \
								sw			t0,4*4(sp)																		 \n \
								csrr		t0,mstatus																		 \n \
								sw			t0,3*4(sp)																		 \n \
								csrr		t0,mcause																		 \n \
								sw			t0,2*4(sp)																		 \n \
								csrr		t0,mepc																			 \n \
								sw			t0,1*4(sp)																		 \n \
								add			t0,x0,sp 																		 \n \
								sw			t0,0*4(sp)																		 \n \
								add			a1,x0,((19 + 4 + 17)*4)															 \n \
								add			a1,a1,sp																		 \n \
								add			a0,x0,sp"																		 	\
								)
#endif
