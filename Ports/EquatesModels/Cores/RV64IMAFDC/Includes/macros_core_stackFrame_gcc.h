/*
; macros_core_stackFrame_gcc_14.
; ==============================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Stack frame management macros (gcc-14 version).
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
#define	BREAK_IFDEBUGGING
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
#define	KSTACK_ALIGNMENT		(16u)
#define	KSTACK_ALIGNMENT_MASK	(~(KSTACK_ALIGNMENT - 1u))
#define	KSTACK_ALIGNMENT_MEMO	(KMEMO_ALIGN_16)
#endif

// Critical stack size when < (70+10) 32-bit words (stack frame + reserve)

#if (!defined(KKERN_CRITICAL_SZ_STACK))
#define	KKERN_CRITICAL_SZ_STACK		(70u + 10u)
#endif

// Stack sizes (in machine words of 32-bit)

#if (!defined(KKERN_SZ_STACK_SS))
#define	KKERN_SZ_STACK_SS			400u
#endif
#if (!defined(KKERN_SZ_STACK_MM))
#define	KKERN_SZ_STACK_MM			500u
#endif
#if (!defined(KKERN_SZ_STACK_LL))
#define	KKERN_SZ_STACK_LL			600u
#endif
#if (!defined(KKERN_SZ_STACK_XL))
#define	KKERN_SZ_STACK_XL			1000u
#endif
#if (!defined(KKERN_SZ_STACK_MIN))
#define	KKERN_SZ_STACK_MIN			400u
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
// The stack has to be aligned on boundary of 16-bytes
// In this case the (552 + 8) mod 16 has to be 0
//
//	+552	x1 ra			=
//	+544	x5 t0			=
//	+536	fcsr			=
//	+528	x6 t1			=
//	+520	x7 t2			=
//	+512	x8 s0 fp		=
//	+504	x9 s1			=
//	+496	x10 a0			= process arguments
//	+488	x11 a1			=
//	+480	x12 a2			=
//	+472	x13 a3			=
//	+464	x14 a4			=
//	+456	x15 a5			=
//	+448	x16 a6			=
//	+440	x17 a7			=
//	+432	x28 t3			=
//	+424	x29 t4			=
//	+416	x30 t5			=
//	+408	x31 t6			=
//	+400	x0 = 0			= Dummy
//	+392	ft0				=
//	+384	ft1				=
//	+376	ft2				=
//	+368	ft3				=
//	+360	ft4				=
//	+352	ft5				=
//	+344	ft6				=
//	+336	ft7				=
//	+328	fa0				=
//	+320	fa1				=
//	+312	fa2				=
//	+304	fa3				=
//	+296	fa4				=
//	+288	fa5				=
//	+280	fa6				=
//	+272	fa7				=
//	+264	ft8				=
//	+256	ft9				=
//	+248	ft10			=
//	+240	ft11			=
//	+232	x27 s11			=
//	+224	x26 s10			=
//	+216	x25 s9			=
//	+208	x24 s8			=
//	+200	x23 s7			=
//	+192	x22 s6			=
//	+184	x21 s5			=
//	+176	x20 s4			=
//	+168	x19 s3			=
//	+160	x18 s2			=
//	+152	x4 tp			=
//	+144	x3 gp			=
//	+136	x0 = 0			=
//	+128	fs11			=
//	+120	fs10			=
//	+112	fs9				=
//	+104	fs8				=
//	+96		fs7				=
//	+88		fs6				=
//	+80		fs5				=
//	+72		fs4				=
//	+64		fs3				=
//	+56		fs2				=
//	+48		fs1				=
//	+40		fs0				=
//	+32		mepc			= process address
//	+24		mcause			=
//	+16		mstatus			=
//	+8		core			=
//	+0		PLIC->mth		= PLIC priority

#if (!defined(KERN_PREPARE_FRAME))
#define KERN_PREPARE_FRAME(stack, code, core, argument, priority)																\
								*(--stack) = 0x00000000u;					/*	+552	x1 ra			*/						\
								*(--stack) = 0x05050505u;					/*	+544	x5 t0			*/						\
								*(--stack) = 0x00000000u;					/*	+536	fcsr			*/						\
								*(--stack) = 0x06060606u;					/*	+528	x6 t1			*/						\
								*(--stack) = 0x07070707u;					/*	+520	x7 t2			*/						\
								*(--stack) = 0x08080808u;					/*	+512	x8 s0 fp		*/						\
								*(--stack) = 0x09090909u;					/*	+504	x9 s1			*/						\
								*(--stack) = (uintptr_t)argument;			/*	+496	x10 a0			*/						\
								*(--stack) = 0x11111111u;					/*	+488	x11 a1			*/						\
								*(--stack) = 0x12121212u;					/*	+480	x12 a2			*/						\
								*(--stack) = 0x13131313u;					/*	+472	x13 a3			*/						\
								*(--stack) = 0x14141414u;					/*	+464	x14 a4			*/						\
								*(--stack) = 0x15151515u;					/*	+456	x15 a5			*/						\
								*(--stack) = 0x16161616u;					/*	+448	x16 a6			*/						\
								*(--stack) = 0x17171717u;					/*	+440	x17 a7			*/						\
								*(--stack) = 0x28282828u;					/*	+432	x28 t3			*/						\
								*(--stack) = 0x29292929u;					/*	+424	x29 t4			*/						\
								*(--stack) = 0x30303030u;					/*	+416	x30 t5			*/						\
								*(--stack) = 0x31313131u;					/*	+408	x31 t6			*/						\
								*(--stack) = 0x00000000u;					/*	+400	x0 = 0, dummy	*/						\
								*(--stack) = 0xF00F00F0u;					/*	+392	ft0				*/						\
								*(--stack) = 0xF01F01F0u;					/*	+384	ft1				*/						\
								*(--stack) = 0xF02F02F0u;					/*	+376	ft2				*/						\
								*(--stack) = 0xF03F03F0u;					/*	+368	ft3				*/						\
								*(--stack) = 0xF04F04F0u;					/*	+360	ft4				*/						\
								*(--stack) = 0xF05F05F0u;					/*	+352	ft5				*/						\
								*(--stack) = 0xF06F06F0u;					/*	+344	ft6				*/						\
								*(--stack) = 0xF07F07F0u;					/*	+336	ft7				*/						\
								*(--stack) = 0xFA0FA0F0u;					/*	+328	fa0				*/						\
								*(--stack) = 0xFA1FA1F0u;					/*	+320	fa1				*/						\
								*(--stack) = 0xFA2FA2F0u;					/*	+312	fa2				*/						\
								*(--stack) = 0xFA3FA3F0u;					/*	+304	fa3				*/						\
								*(--stack) = 0xFA4FA4F0u;					/*	+296	fa4				*/						\
								*(--stack) = 0xFA5FA5F0u;					/*	+288	fa5				*/						\
								*(--stack) = 0xFA6FA6F0u;					/*	+280	fa6				*/						\
								*(--stack) = 0xFA7FA7F0u;					/*	+272	fa7				*/						\
								*(--stack) = 0xF08F08F0u;					/*	+264	ft8				*/						\
								*(--stack) = 0xF09F09F0u;					/*	+256	ft9				*/						\
								*(--stack) = 0xF0AF0AF0u;					/*	+248	ft10			*/						\
								*(--stack) = 0xF0BF0BF0u;					/*	+240	ft11			*/						\
								*(--stack) = 0x27272727u;					/*	+232	x27 s11			*/						\
								*(--stack) = 0x26262626u;					/*	+224	x26 s10			*/						\
								*(--stack) = 0x25252525u;					/*	+216	x25 s9			*/						\
								*(--stack) = 0x24242424u;					/*	+208	x24 s8			*/						\
								*(--stack) = 0x23232324u;					/*	+200	x23 s7			*/						\
								*(--stack) = 0x22222222u;					/*	+192	x22 s6			*/						\
								*(--stack) = 0x21212121u;					/*	+184	x21 s5			*/						\
								*(--stack) = 0x20202020u;					/*	+176	x20 s4			*/						\
								*(--stack) = 0x19191919u;					/*	+168	x19 s3			*/						\
								*(--stack) = 0x18181818u;					/*	+160	x18 s2			*/						\
								*(--stack) = 0x04040404u;					/*	+152	x4 tp			*/						\
								*(--stack) = 0x03030303u;					/*	+144	x3 gp			*/						\
								*(--stack) = 0x00000000u;					/*	+136	x0 = 0			*/						\
								*(--stack) = 0xFFBFFBF0u;					/*	+128	fs11			*/						\
								*(--stack) = 0xFFAFFAF0u;					/*	+120	fs10			*/						\
								*(--stack) = 0xFF9FF9F0u;					/*	+112	fs9				*/						\
								*(--stack) = 0xFF8FF8F0u;					/*	+104	fs8				*/						\
								*(--stack) = 0xFF7FF7F0u;					/*	+96		fs7				*/						\
								*(--stack) = 0xFF6FF6F0u;					/*	+88		fs6				*/						\
								*(--stack) = 0xFF5FF5F0u;					/*	+80		fs5				*/						\
								*(--stack) = 0xFF4FF4F0u;					/*	+72		fs4				*/						\
								*(--stack) = 0xFF3FF3F0u;					/*	+64		fs3				*/						\
								*(--stack) = 0xFF2FF2F0u;					/*	+56		fs2				*/						\
								*(--stack) = 0xFF1FF1F0u;					/*	+48		fs1				*/						\
								*(--stack) = 0xFF0FF0F0u;					/*	+40		fs0				*/						\
								*(--stack) = (uintptr_t)code;				/*	+32		mepc			*/						\
								*(--stack) = KPROCESS_INIT_MCAUSE;			/*	+24		mcause			*/						\
								*(--stack) = KSTATUS;						/*	+16		mstatus			*/						\
								*(--stack) = core; 							/*	+8		core			*/						\
								*(--stack) = priority;						/*	+0		PLIC->mth		*/
#endif

// Save the frame
//
// The stack has to be aligned on boundary of 16-bytes
// In this case the (552 + 8) mod 16 has to be 0
//
//	+552	x1 ra			=
//	+544	x5 t0			=
//	+536	fcsr			=
//	+528	x6 t1			=
//	+520	x7 t2			=
//	+512	x8 s0 fp		=
//	+504	x9 s1			=
//	+496	x10 a0			= process arguments
//	+488	x11 a1			=
//	+480	x12 a2			=
//	+472	x13 a3			=
//	+464	x14 a4			=
//	+456	x15 a5			=
//	+448	x16 a6			=
//	+440	x17 a7			=
//	+432	x28 t3			=
//	+424	x29 t4			=
//	+416	x30 t5			=
//	+408	x31 t6			=
//	+400	x0 = 0			= Dummy
//	+392	ft0				=
//	+384	ft1				=
//	+376	ft2				=
//	+368	ft3				=
//	+360	ft4				=
//	+352	ft5				=
//	+344	ft6				=
//	+336	ft7				=
//	+328	fa0				=
//	+320	fa1				=
//	+312	fa2				=
//	+304	fa3				=
//	+296	fa4				=
//	+288	fa5				=
//	+280	fa6				=
//	+272	fa7				=
//	+264	ft8				=
//	+256	ft9				=
//	+248	ft10			=
//	+240	ft11			=
//	+232	x27 s11			=
//	+224	x26 s10			=
//	+216	x25 s9			=
//	+208	x24 s8			=
//	+200	x23 s7			=
//	+192	x22 s6			=
//	+184	x21 s5			=
//	+176	x20 s4			=
//	+168	x19 s3			=
//	+160	x18 s2			=
//	+152	x4 tp			=
//	+144	x3 gp			=
//	+136	x0 = 0			=
//	+128	fs11			=
//	+120	fs10			=
//	+112	fs9				=
//	+104	fs8				=
//	+96		fs7				=
//	+88		fs6				=
//	+80		fs5				=
//	+72		fs4				=
//	+64		fs3				=
//	+56		fs2				=
//	+48		fs1				=
//	+40		fs0				=
//	+32		mepc			= process address
//	+24		mcause			=
//	+16		mstatus			=
//	+8		core			=
//	+0		PLIC->mth		= PLIC priority
//
// Prepare for the model
//
// a0 -> core
// a1 -> parameter
// a2 -> *threshold
// a3 -> *stack

#if (!defined(KERN_SAVE_FRAME))
#define	KERN_SAVE_FRAME			__asm volatile ("																			 \n \
								addi		sp,sp,-(13*8)																	 \n \
								sd			s11,12*8(sp)																	 \n \
								sd			s10,11*8(sp)																	 \n \
								sd			s9,10*8(sp)																		 \n \
								sd			s8,9*8(sp)																		 \n \
								sd			s7,8*8(sp)																		 \n \
								sd			s6,7*8(sp)																		 \n \
								sd			s5,6*8(sp)																		 \n \
								sd			s4,5*8(sp)																		 \n \
								sd			s3,4*8(sp)																		 \n \
								sd			s2,3*8(sp)																		 \n \
								sd			tp,2*8(sp)																		 \n \
								sd			gp,1*8(sp)																		 \n \
								sd			x0,0*8(sp)"																		 	\
								);																							 	\
																															 	\
								__asm volatile ("																			 \n \
								addi		sp,sp,-(12*8)																	 \n \
								fsd			fs11,11*8(sp)																	 \n \
								fsd			fs10,10*8(sp)																	 \n \
								fsd			fs9,9*8(sp)																		 \n \
								fsd			fs8,8*8(sp)																		 \n \
								fsd			fs7,7*8(sp)																		 \n \
								fsd			fs6,6*8(sp)																		 \n \
								fsd			fs5,5*8(sp)																		 \n \
								fsd			fs4,4*8(sp)																		 \n \
								fsd			fs3,3*8(sp)																		 \n \
								fsd			fs2,2*8(sp)																		 \n \
								fsd			fs1,1*8(sp)																		 \n \
								fsd			fs0,0*8(sp)"																	 	\
								);																							 	\
																															 	\
								__asm volatile ("																			 \n \
								addi		sp,sp,-(5*8)																	 \n \
								csrr		t0,mepc																			 \n \
								sd			t0,4*8(sp)																		 \n \
								csrr		t0,mcause																		 \n \
								sd			t0,3*8(sp)																		 \n \
								csrr		t0,mstatus																		 \n \
								sd			t0,2*8(sp)																		 \n \
								add			t0,x0,a0																		 \n \
								sd			t0,1*8(sp)																		 \n \
								add			t0,x0,x0																		 \n \
								sd			t0,0*8(sp)																		 \n \
								add			a2,x0,sp																		 \n \
								add			a2,a2,0*8																		 \n \
								add			a3,x0,sp"																		 	\
								)
#endif

// New frame
//
// The stack has to be aligned on boundary of 16-bytes
// In this case the (552 + 8) mod 16 has to be 0
//
//	+552	x1 ra			=
//	+544	x5 t0			=
//	+536	fcsr			=
//	+528	x6 t1			=
//	+520	x7 t2			=
//	+512	x8 s0 fp		=
//	+504	x9 s1			=
//	+496	x10 a0			= process arguments
//	+488	x11 a1			=
//	+480	x12 a2			=
//	+472	x13 a3			=
//	+464	x14 a4			=
//	+456	x15 a5			=
//	+448	x16 a6			=
//	+440	x17 a7			=
//	+432	x28 t3			=
//	+424	x29 t4			=
//	+416	x30 t5			=
//	+408	x31 t6			=
//	+400	x0 = 0			= Dummy
//	+392	ft0				=
//	+384	ft1				=
//	+376	ft2				=
//	+368	ft3				=
//	+360	ft4				=
//	+352	ft5				=
//	+344	ft6				=
//	+336	ft7				=
//	+328	fa0				=
//	+320	fa1				=
//	+312	fa2				=
//	+304	fa3				=
//	+296	fa4				=
//	+288	fa5				=
//	+280	fa6				=
//	+272	fa7				=
//	+264	ft8				=
//	+256	ft9				=
//	+248	ft10			=
//	+240	ft11			=
//	+232	x27 s11			=
//	+224	x26 s10			=
//	+216	x25 s9			=
//	+208	x24 s8			=
//	+200	x23 s7			=
//	+192	x22 s6			=
//	+184	x21 s5			=
//	+176	x20 s4			=
//	+168	x19 s3			=
//	+160	x18 s2			=
//	+152	x4 tp			=
//	+144	x3 gp			=
//	+136	x0 = 0			=
//	+128	fs11			=
//	+120	fs10			=
//	+112	fs9				=
//	+104	fs8				=
//	+96		fs7				=
//	+88		fs6				=
//	+80		fs5				=
//	+72		fs4				=
//	+64		fs3				=
//	+56		fs2				=
//	+48		fs1				=
//	+40		fs0				=
//	+32		mepc			= process address
//	+24		mcause			=
//	+16		mstatus			=
//	+8		core			=
//	+0		PLIC->mth		= PLIC priority
//
// Prepare for the model
//
// a1 -> *newStack

#if (!defined(KERN_NEW_FRAME))
#define	KERN_NEW_FRAME			__asm volatile ("																			 \n \
								add			sp,x0,a1																		 \n \
								ld			t0,2*8(sp)																		 \n \
								csrw		mstatus,t0																		 \n \
								ld			t0,3*8(sp)																		 \n \
								csrw		mcause,t0																		 \n \
								ld			t0,4*8(sp)																		 \n \
								csrw		mepc,t0																			 \n \
								addi		sp,sp,(5*8)"																	 	\
								);																							 	\
																															 	\
								__asm volatile ("																			 \n \
								fld			fs0,0*8(sp)																		 \n \
								fld			fs1,1*8(sp)																		 \n \
								fld			fs2,2*8(sp)																		 \n \
								fld			fs3,3*8(sp)																		 \n \
								fld			fs4,4*8(sp)																		 \n \
								fld			fs5,5*8(sp)																		 \n \
								fld			fs6,6*8(sp)																		 \n \
								fld			fs7,7*8(sp)																		 \n \
								fld			fs8,8*8(sp)																		 \n \
								fld			fs9,9*8(sp)																		 \n \
								fld			fs10,10*8(sp)																	 \n \
								fld			fs11,11*8(sp)																	 \n \
								addi		sp,sp,(12*8)"																	 	\
								);																							 	\
																															 	\
								__asm volatile ("																			 \n \
								ld			x0,0*8(sp)																		 \n \
								ld			gp,1*8(sp)																		 \n \
								ld			tp,2*8(sp)																		 \n \
								ld			s2,3*8(sp)																		 \n \
								ld			s3,4*8(sp)																		 \n \
								ld			s4,5*8(sp)																		 \n \
								ld			s5,6*8(sp)																		 \n \
								ld			s6,7*8(sp)																		 \n \
								ld			s7,8*8(sp)																		 \n \
								ld			s8,9*8(sp)																		 \n \
								ld			s9,10*8(sp)																		 \n \
								ld			s10,11*8(sp)																	 \n \
								ld			s11,12*8(sp)																	 \n \
								addi		sp,sp,(13*8)"																	 	\
								);																							 	\
																															 	\
								__asm volatile ("																			 \n \
								ld			ra,39*8(sp)																		 \n \
								lw			t0,37*8(sp)																		 \n \
								fscsr		t0																				 \n \
								ld			s0,34*8(sp)																		 \n \
								ld			t0,38*8(sp)																		 \n \
								ld			t1,36*8(sp)																		 \n \
								ld			t2,35*8(sp)																		 \n \
								ld			s1,33*8(sp)																		 \n \
								ld			a0,32*8(sp)																		 \n \
								ld			a1,31*8(sp)																		 \n \
								ld			a2,30*8(sp)																		 \n \
								ld			a3,29*8(sp)																		 \n \
								ld			a4,28*8(sp)																		 \n \
								ld			a5,27*8(sp)																		 \n \
								ld			a6,26*8(sp)																		 \n \
								ld			a7,25*8(sp)																		 \n \
								ld			t3,24*8(sp)																		 \n \
								ld			t4,23*8(sp)																		 \n \
								ld			t5,22*8(sp)																		 \n \
								ld			t6,21*8(sp)																		 \n \
								fld			ft0,19*8(sp)																	 \n \
								fld			ft1,18*8(sp)																	 \n \
								fld			ft2,17*8(sp)																	 \n \
								fld			ft3,16*8(sp)																	 \n \
								fld			ft4,15*8(sp)																	 \n \
								fld			ft5,14*8(sp)																	 \n \
								fld			ft6,13*8(sp)																	 \n \
								fld			ft7,12*8(sp)																	 \n \
								fld			fa0,11*8(sp)																	 \n \
								fld			fa1,10*8(sp)																	 \n \
								fld			fa2,9*8(sp)																		 \n \
								fld			fa3,8*8(sp)																		 \n \
								fld			fa4,7*8(sp)																		 \n \
								fld			fa5,6*8(sp)																		 \n \
								fld			fa6,5*8(sp)																		 \n \
								fld			fa7,4*8(sp)																		 \n \
								fld			ft8,3*8(sp)																		 \n \
								fld			ft9,2*8(sp)																		 \n \
								fld			ft10,1*8(sp)																	 \n \
								fld			ft11,0*8(sp)																	 \n \
								addi		sp,sp,(40*8)"																	    \
								)
#endif

// Return to a new context

#if (!defined(KERN_RETURN))
#define	KERN_RETURN				__asm volatile ("																			 \n \
								mret"																						 	\
								)
#endif

// Messages: _I (immediate) _M (memory)

#if (!defined(GOTO_KERN_I))
#define	GOTO_KERN_I(msg)		__asm volatile ("																			 \n \
								addi		sp,sp,-(1*8)																	 \n \
								sd			a0,0*8(sp)																		 \n \
								add			a0,x0,%0																		 \n \
								ecall																						 \n \
								ld			a0,0*8(sp)																		 \n \
								addi		sp,sp,(1*8)"																		\
								:																								\
								: "r" (msg)																	  					\
								:																								\
								)
#endif

#if (!defined(GOTO_KERN_M))
#define	GOTO_KERN_M(msg)		__asm volatile ("																			 \n \
								addi		sp,sp,-(1*8)																	 \n \
								sd			a0,0*8(sp)																		 \n \
								add			a0,x0,%0																		 \n \
								ecall																						 \n \
								ld			a0,0*8(sp)																		 \n \
								addi		sp,sp,(1*8)"																		\
								:																								\
								: "r" (msg)																	  					\
								:																								\
								)
#endif

// Core dump register collection

//	+560	x1 ra			=
//	+552	x5 t0			=
//	+544	fcsr			=
//	+536	x6 t1			=
//	+528	x7 t2			=
//	+520	x8 s0 fp		=
//	+512	x9 s1			=
//	+504	x10 a0			= process arguments
//	+496	x11 a1			=
//	+488	x12 a2			=
//	+480	x13 a3			=
//	+472	x14 a4			=
//	+464	x15 a5			=
//	+456	x16 a6			=
//	+448	x17 a7			=
//	+440	x28 t3			=
//	+432	x29 t4			=
//	+424	x30 t5			=
//	+416	x31 t6			=
//	+408	x0 = 0			= Dummy
//	+400	ft0				=
//	+392	ft1				=
//	+384	ft2				=
//	+376	ft3				=
//	+368	ft4				=
//	+360	ft5				=
//	+352	ft6				=
//	+344	ft7				=
//	+336	fa0				=
//	+328	fa1				=
//	+320	fa2				=
//	+312	fa3				=
//	+304	fa4				=
//	+296	fa5				=
//	+288	fa6				=
//	+280	fa7				=
//	+272	ft8				=
//	+264	ft9				=
//	+256	ft10			=
//	+248	ft11			=
//	+240	x27 s11			=
//	+232	x26 s10			=
//	+224	x25 s9			=
//	+216	x24 s8			=
//	+208	x23 s7			=
//	+200	x22 s6			=
//	+192	x21 s5			=
//	+184	x20 s4			=
//	+176	x19 s3			=
//	+168	x18 s2			=
//	+160	x4 tp			=
//	+152	x3 gp			=
//	+144	x0 = 0			=
//	+136	fs11			=
//	+128	fs10			=
//	+120	fs9				=
//	+112	fs8				=
//	+104	fs7				=
//	+96		fs6				=
//	+88		fs5				=
//	+80		fs4				=
//	+72		fs3				=
//	+64		fs2				=
//	+56		fs1				=
//	+48		fs0				=
//	+40		mepc			= process address
//	+32		mcause			=
//	+24		mstatus			=
//	+16		core			=
//	+8		Reserve			=
//	+0		sp				=
//
// Prepare for the core dump
//
// a0 -> core
// a1 -> number
// a2 -> *stackBefore
// a3 -> *stackAfter

enum {
		sp = 0u,														// sp + 0
		Reserve,														// sp + 1
		coreId,															// sp + 2
		statusm, causem, pcm,											// sp + 3..5
		fs0, fs1, fs2, fs3, fs4, fs5, fs6, fs7, fs8, fs9, fs10, fs11,	// sp + 6..17
		dummy_1,														// sp + 18
		gp, tp,															// sp + 19..20
		s2, s3, s4, s5, s6, s7, s8, s9, s10, s11,						// sp + 21..30
		ft11, ft10, ft9, ft8,											// sp + 31..34
		fa7, fa6, fa5, fa4, fa3, fa2, fa1, fa0,							// sp + 35..42
		ft7, ft6, ft5, ft4, ft3, ft2, ft1, ft0,							// sp + 43..50
		dummy_2,														// sp + 51
		t6, t5, t4, t3,													// sp + 52..55
		a7, a6, a5, a4, a3, a2, a1, a0,									// sp + 56..63
		s1, s0,															// sp + 64..65
		t2, t1,															// sp + 66..67
		fcsr,															// sp + 68
		t0,																// sp + 69
		ra,																// sp + 70
		ENDREG															// sp + 71
};

// IMPORTANT! This macro HAS to prepare a0, a1, a2, a3 with
// the value of the core, the number, the stack before and after the stacking
// to comply with the ABI of local_processIntInt(uint32_t core, uint64_t number, uintptr_t *stackBefore, uintptr_t *stackAfter)
// a0 & a1 are provided by the first.c

#if (!defined(CORE_DUMP_SAVE_STACK_FRAME))
#define CORE_DUMP_SAVE_STACK_FRAME																								\
								__asm volatile ("																			 \n \
								addi		sp,sp,-(13*8)																	 \n \
								sd			s11,12*8(sp)																	 \n \
								sd			s10,11*8(sp)																	 \n \
								sd			s9,10*8(sp)																		 \n \
								sd			s8,9*8(sp)																		 \n \
								sd			s7,8*8(sp)																		 \n \
								sd			s6,7*8(sp)																		 \n \
								sd			s5,6*8(sp)																		 \n \
								sd			s4,5*8(sp)																		 \n \
								sd			s3,4*8(sp)																		 \n \
								sd			s2,3*8(sp)																		 \n \
								sd			tp,2*8(sp)																		 \n \
								sd			gp,1*8(sp)																		 \n \
								sd			x0,0*8(sp)"																		 	\
								);																							 	\
																															 	\
								__asm volatile ("																			 \n \
								addi		sp,sp,-(12*8)																	 \n \
								fsd			fs11,11*8(sp)																	 \n \
								fsd			fs10,10*8(sp)																	 \n \
								fsd			fs9,9*8(sp)																		 \n \
								fsd			fs8,8*8(sp)																		 \n \
								fsd			fs7,7*8(sp)																		 \n \
								fsd			fs6,6*8(sp)																		 \n \
								fsd			fs5,5*8(sp)																		 \n \
								fsd			fs4,4*8(sp)																		 \n \
								fsd			fs3,3*8(sp)																		 \n \
								fsd			fs2,2*8(sp)																		 \n \
								fsd			fs1,1*8(sp)																		 \n \
								fsd			fs0,0*8(sp)"																	 	\
								);																							 	\
																															 	\
								__asm volatile ("																			 \n \
								addi		sp,sp,-(6*8)																	 \n \
								csrr		t0,mepc																			 \n \
								sd			t0,5*8(sp)																		 \n \
								csrr		t0,mcause																		 \n \
								sd			t0,4*8(sp)																		 \n \
								csrr		t0,mstatus																		 \n \
								sd			t0,3*8(sp)																		 \n \
								add			t0,x0,a0																		 \n \
								sd			t0,2*8(sp)																		 \n \
								add			t0,x0,x0																		 \n \
								sd			t0,1*8(sp)																		 \n \
								add			t0,x0,sp 																		 \n \
								sd			t0,0*8(sp)																		 \n \
								add			t0,x0,sp																		 \n \
								addi		a2,t0,((6 + 12 + 13 + 40)*8)													 \n \
								add			a3,x0,sp"																		 	\
								)
#endif
