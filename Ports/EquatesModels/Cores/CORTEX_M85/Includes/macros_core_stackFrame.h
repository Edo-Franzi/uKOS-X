/*
; macros_core_stackFrame.
; =======================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Stack frame management macros.
;			This file conains the most sensitive macros
;			for the uKernel management
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

// For the stack sanity

#if (!defined(KMAGICSTACK))
#define KMAGICSTACK				(((uint32_t)'u'<<24u) | ((uint32_t)'K'<<16u) | ((uint32_t)'O'<<8u) | (uint32_t)'S')
#endif

#if (!defined(BREAK_IFDEBUGGING))
#define	BREAK_IFDEBUGGING		if ((REG(CoreDebug)->DEMCR & CoreDebug_DEMCR_TRCENA) != 0u) {									\
									__asm volatile ("bkpt		#1");															\
								}
#endif

#if (!defined(CHECK_STACK_SANITY))
#define CHECK_STACK_SANITY(core)																								\
								if ((vKern_runProc[core]->oInternal.oState != 0u) && 											\
									((vKern_runProc[core]->oInternal.oState & (1u<<BPROC_FIRST)) == 0u)) {						\
									if ((vKern_runProc[core]->oSpecification.oStackStart > vKern_stackProc[core]) ||			\
										(vKern_runProc[core]->oSpecification.oStackStart[core] != KMAGICSTACK)) {			  	\
										LOG(KFATAL_KERNEL, "kern: stack underflow");										  	\
										BREAK_IFDEBUGGING;															  			\
										exit(EXIT_OS_PANIC_STACK_UNDERFLOW);											  		\
									}																				  			\
								}
#endif

// Stack alignment (see processes.h)

#if (!defined(KSTACK_ALIGNMENT))
#define	KSTACK_ALIGNMENT		(8u)
#define	KSTACK_ALIGNMENT_MASK	(~(KSTACK_ALIGNMENT - 1u))
#define	KSTACK_ALIGNMENT_MEMO	(KMEMO_ALIGN_8)
#endif

// Critical stack size when < (51+10) 32-bit words (stack frame + reserve)

#if (!defined(KKERN_CRITICAL_SZ_STACK))
#define	KKERN_CRITICAL_SZ_STACK		(51u + 10u)
#endif

// Stack sizes (in machine words of 32-bit)

#if (!defined(KKERN_SZ_STACK_SS))
#define	KKERN_SZ_STACK_SS			200u
#endif
#if (!defined(KKERN_SZ_STACK_MM))
#define	KKERN_SZ_STACK_MM			400u
#endif
#if (!defined(KKERN_SZ_STACK_LL))
#define	KKERN_SZ_STACK_LL			600u
#endif
#if (!defined(KKERN_SZ_STACK_XL))
#define	KKERN_SZ_STACK_XL			1000u
#endif
#if (!defined(KKERN_SZ_STACK_MIN))
#define	KKERN_SZ_STACK_MIN			300u
#endif
#if (!defined(KKERN_SZ_STACK_XLIB))
#define	KKERN_SZ_STACK_XLIB			(400u + 1000u)
#endif
#if (!defined(KKERN_SZ_STACK_MPY))
#define	KKERN_SZ_STACK_MPY			(400u + 1000u)
#endif

// Stack frame macros
// ------------------

// Prepare the stack frame
//
// The stack has to be aligned on boundary of 8-bytes
// In this case the (68 + 4) mod 8 has to be 0
//
//  +68	xPSR		= 0x01000000
//  +64 pc			= process address
//  +60 lr			= address of the routine exit_terminate()
//  +56 r12			=
//  +52 r3			=
//  +48 r2			=
//  +44 r1			= init registers
//  +40 r0			= process arguments
//  +36 r11			=
//  +32 r10			=
//  +28 r9			=
//  +24 r8			=
//  +20 r7			=
//  +16 r6			=
//  +12 r5			=
//  +8  r4			= init registers
//	+4  basepri		= NVIC priority
//  +0  0xFFFFFFFD	= Initial exception return (Thread mode without FPU, SP = PSP)

#if (!defined(KERN_PREPARE_FRAME))
#define KERN_PREPARE_FRAME(stack, code, core, argument, priority)																\
								*(--stack) = 0x01000000u;																		\
								*(--stack) = (uintptr_t)code;																	\
								*(--stack) = (uintptr_t)exit_terminate;															\
								*(--stack) = 0x12121212u;																		\
								*(--stack) = 0x03030303u;																		\
								*(--stack) = 0x02020202u;																		\
								*(--stack) = 0x01010101u;																		\
								*(--stack) = (uintptr_t)argument;																\
								*(--stack) = 0x11111111u;																		\
								*(--stack) = 0x10101010u;																		\
								*(--stack) = 0x09090909u;																		\
								*(--stack) = 0x08080808u;																		\
								*(--stack) = 0x07070707u;																		\
								*(--stack) = 0x06060606u;																		\
								*(--stack) = 0x05050505u;																		\
								*(--stack) = 0x04040404u;																		\
								*(--stack) = ((uintptr_t)priority<<(uintptr_t)KNVIC_PRIORITY_SHIFT);							\
								*(--stack) = 0xFFFFFFFDu;																		\
								UNUSED(core)
#endif

// Recover the message & save the frame message
//
//	+108 (104)	Message					uKOS-X message
//	+104 (100)	Message					uKOS-X message
//	+100		(possible aligner)		(implementation dependent)
//	+96			FPSCR
//	+92			s15..s0
//	+28			xPSR
//	+24			pc
//	+20			lr
//	+16			r12
//	+12			r3
//	+8			r2
//	+4			r1
//	+0			r0	<-- Stacked automatically
//	-32			r11..r4
//	-36			basepri
//	-100		s31..s16
//	-104		lr	<-- Stacked manually
//
// Prepare for the model
//
// r0 -> *stack
// r1 -> message

#if (!defined(KERN_RECOVER_MESSAGE))
#define	KERN_RECOVER_MESSAGE	__asm volatile ("																			 \n \
								tst			lr,#0x4																			 \n \
								ite 		eq																				 \n \
								mrseq		r0,msp																			 \n \
								mrsne		r0,psp																			 \n \
								add			r1,r0,#(32+4)																	 \n \
								tst			lr,#0x10																		 \n \
								it 			eq																				 \n \
								addeq		r1,r0,#(32+68+4)																 \n \
								ldr			r1,[r1]"																			\
								)
#endif

#if (!defined(KERN_SAVE_FRAME_MESSAGE))
#define	KERN_SAVE_FRAME_MESSAGE	__asm volatile ("																			 \n \
								mrs			r2,basepri																		 \n \
								stmdb 		r0!,{r2,r4-r11}																	 \n \
								tst			lr,#0x10																		 \n \
								it 			eq																				 \n \
								vstmdbeq	r0!,{s16-s31}																	 \n \
								stmdb 		r0!,{lr}																		 \n \
								tst			lr,#0x4																			 \n \
								ite 		eq																				 \n \
								msreq		msp,r0																			 \n \
								msrne		psp,r0"																				\
								)
#endif

// Save the frame
//
//	+96			FPSCR
//	+92			s15..s0
//	+28			xPSR
//	+24			pc
//	+20			lr
//	+16			r12
//	+12			r3
//	+8			r2
//	+4			r1
//	+0			r0		<-- Stacked automatically
//	-32			r11..r4
//	-36			basepri
//	-100		s31..s16
//	-104		lr		<-- Stacked manually
//
// Prepare for the model
//
// r0 -> *stack

#if (!defined(KERN_SAVE_FRAME_NORMAL))
#define	KERN_SAVE_FRAME_NORMAL	__asm volatile ("																			 \n \
								tst			lr,#0x4																			 \n \
								ite 		eq																				 \n \
								mrseq		r0,msp																			 \n \
								mrsne		r0,psp																			 \n \
								mrs			r1,basepri																		 \n \
								stmdb 		r0!,{r1,r4-r11}																	 \n \
								tst			lr,#0x10																		 \n \
								it 			eq																				 \n \
								vstmdbeq	r0!,{s16-s31}																	 \n \
								stmdb 		r0!,{lr}																		 \n \
								tst			lr,#0x4																			 \n \
								ite 		eq																				 \n \
								msreq		msp,r0																			 \n \
								msrne		psp,r0"																				\
								)
#endif

// New frame
//
//	-104		lr
//	-100		s31..s16
//	-36			basepri
//	-32			r4..r11	<-- De-stacked manually
//	+0			r0
//	+4			r1
//	+8			r2
//	+12			r3
//	+16			r12
//	+20			lr
//	+24			pc
//	+28			xPSR
//	+92			s15..s0
//	+96			FPSCR	<-- De-stacked automatically
//
// Prepare for the model
//
// r0 -> *stack of the new process

#if (!defined(KERN_NEW_FRAME))
#define	KERN_NEW_FRAME			__asm volatile ("																			 \n \
								ldmia		r0!,{lr}																		 \n \
								tst			lr,#0x10																		 \n \
								it 			eq																				 \n \
								vldmiaeq 	r0!,{s16-s31}																	 \n \
								ldmia 		r0!,{r1,r4-r11}																	 \n \
								tst			lr,#0x4																			 \n \
								ite 		eq																				 \n \
								msreq		msp,r0																			 \n \
								msrne		psp,r0																			 \n \
								msr			basepri,r1"																			\
								)
#endif

// Return to a new context

#if (!defined(KERN_RETURN))
#define	KERN_RETURN				__asm volatile ("																			 \n \
								dmb																							 \n \
								dsb																							 \n \
								isb																							 \n \
								bx			lr"																					\
								)
#endif

// Messages: _I (immediate) _M (memory)

#if (!defined(GOTO_KERN_I))
#define	GOTO_KERN_I(msg)		stub_kern_stopProcessTimeout();																	\
								__asm volatile ("																			 \n \
								movw		r0,%0																			 \n \
								movt		r0,%1																			 \n \
								push		{r0}																			 \n \
								push		{r0}"																				\
								:																								\
								: "i" ((msg) & 0x0000FFFFu), "i" ((msg)>>16u)													\
								: "r0"																							\
								);																								\
								__asm volatile ("																			 \n \
								svc			%0																				 \n \
								dmb																							 \n \
								dsb																							 \n \
								isb																							 \n \
								mrs			r0,psp																			 \n \
								add			r0,r0,#8																		 \n \
								msr			psp,r0"																				\
								:																								\
								: "i" (KKERN_MESSAGE)																			\
								: "r0"																							\
								)
#endif

#if (!defined(GOTO_KERN_M))
#define	GOTO_KERN_M(msg)		stub_kern_stopProcessTimeout();																	\
								__asm volatile ("																			 \n \
								push		{%0}																			 \n \
								push		{%0}"																				\
								:																								\
								: "r" (msg)																						\
								:																								\
								);																								\
								__asm volatile ("																			 \n \
								svc			%0																				 \n \
								dmb																							 \n \
								dsb																							 \n \
								isb																							 \n \
								mrs			r0,psp																			 \n \
								add			r0,r0,#8																		 \n \
								msr			psp,r0"																				\
								:																								\
								: "i" (KKERN_MESSAGE)																			\
								: "r0"																							\
								)
#endif

// Dispatcher macros
//
// Stack frame after the svc(x) instruction
//
//	+92			...
//	+28			xPSR
//	+24			pc
//	+20			lr
//	+16			r12
//	+12			r3
//	+8			r2
//	+4			r1
//	+0			r0
//
// Determine the current stack
// If svc #0 ---> kernel_message
// If svc #1 ---> kern_privilegeElevate

#if (!defined(SVC_DISPATCHER_C0))
#if (defined(PRIVILEGED_USER_S))
#define SVC_DISPATCHER_C0		__asm volatile ("																			 \n \
								tst			lr,#0x4																			 \n \
								ite 		eq																				 \n \
								mrseq		r0,msp																			 \n \
								mrsne		r0,psp																			 \n \
								ldr			r1,[r0,#24]																		 \n \
								ldrb.w		r1,[r1,#-2]																		 \n \
								cmp			r1,#0																			 \n \
								beq.w		kernel_message_C0																 \n \
								cmp			r1,#1																			 \n \
								beq.w		kern_privilegeElevate															 \n \
								push		{lr}																			 \n \
								bl			syscall																			 \n \
								pop			{lr}																			 \n \
								tst			lr,#0x4																			 \n \
								ite 		eq																				 \n \
								mrseq		r1,msp																			 \n \
								mrsne		r1,psp																			 \n \
								str			r0,[r1,#0]																		 \n \
								bx			lr"																					\
								)

#else
#define SVC_DISPATCHER_C0		__asm volatile ("																			 \n \
								tst			lr,#0x4																			 \n \
								ite 		eq																				 \n \
								mrseq		r0,msp																			 \n \
								mrsne		r0,psp																			 \n \
								ldr			r1,[r0,#24]																		 \n \
								ldrb.w		r1,[r1,#-2]																		 \n \
								cmp			r1,#0																			 \n \
								beq.w		kernel_message_C0																 \n \
								push		{lr}																			 \n \
								bl			syscall																			 \n \
								pop			{lr}																			 \n \
								tst			lr,#0x4																			 \n \
								ite 		eq																				 \n \
								mrseq		r1,msp																			 \n \
								mrsne		r1,psp																			 \n \
								str			r0,[r1,#0]																		 \n \
								bx			lr"																					\
								)
#endif
#endif

// Core dump register collection
//
//	+96			FPSCR
//	+92			s15..s0
//	+28			xPSR
//	+24			pc
//	+20			lr
//	+16			r12
//	+12			r3
//	+8			r2
//	+4			r1
//	+0			r0		<-- Stacked automatically
//	-32			r11..r4
//	-36			basepri
//	-100		s31..s16
//	-104		lr
//	-108		psp
//	-112		msp		<-- Stacked manually
//	-116		spp
//
// Prepare for the model
//
// r0 -> *stackBefore saving the frame
// r1 -> *stackAfter having saved the frame

enum {
		SPP = 0u,																			// spp + 0
		PSP, MSP,																			// spp + 1..2
		LR,																					// spp + 3
		s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27, s28, s29, s30, s31,		// spp + 4..19
		BASEPRI,																			// spp + 20
		r04, r05, r06, r07, r08, r09, r10, r11, r00, r01, r02, r03, r12, r14,				// spp + 21..34
		PC, xPSR,																			// spp + 35..36
		s00, s01, s02, s03, s04, s05, s06, s07, s08, s09, s10, s11, s12, s13, s14, s15,		// spp + 37..52
		FPSCR,																				// spp + 53
		ENDREG																				// spp + 54
};

// IMPORTANT! This macro HAS to prepare r0 & r1 with
// the value of the stack before and after the stacking
// to comply with the ABI of local_processException(uintptr_t *stackBefore, uintptr_t *stackAfter)

#if (!defined(CORE_DUMP_SAVE_STACK_FRAME))
#define CORE_DUMP_SAVE_STACK_FRAME												 												\
								__asm volatile ("																			 \n \
								cpsid		i																				 \n \
								tst			lr,#0x4																			 \n \
								ite 		eq																				 \n \
								mrseq		r1,msp																			 \n \
								mrsne		r1,psp																			 \n \
								push		{r1}																			 \n \
								mrs			r2,basepri																		 \n \
								stmdb 		r1!,{r2,r4-r11}																	 \n \
								vstmdb		r1!,{s16-s31}																	 \n \
								stmdb 		r1!,{lr}																		 \n \
								mrs			r2,msp																			 \n \
								stmdb 		r1!,{r2}																		 \n \
								mrs			r2,psp																			 \n \
								stmdb 		r1!,{r2}																		 \n \
								pop			{r0}"																				\
								)
#endif
