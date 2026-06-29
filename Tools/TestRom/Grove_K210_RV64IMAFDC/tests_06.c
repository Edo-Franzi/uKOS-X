/*
; tests_06.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of an ECALL call.
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

#include	"tests.h"

#if (defined(TEST_06_S))
static	char_t		vString[20];
		uintptr_t	vKern_stackProc;

[[gnu::naked]]
static	void	syscall(uint64_t message) {
	__asm volatile ("ECALL" : : "r" (message));
	__asm volatile ("ret");
}

#define	MESSAGE(message)	syscall(message);

// Prototypes

static	void	local_message(uint32_t core, uint64_t message);
static	void	local_process(uint32_t core, uint64_t threshold, uint64_t message);

/*
 * \brief test_06
 *
 * - Test of an ECALL call
 *
 */
void	test_06(void) {
				uint32_t	core;
	volatile	uint64_t	message = 0;

	core  =	GET_RUNNING_CORE;
	vMsgs_process[core] = local_message;
	cmns_init();

	while (true) {
		cmns_wait(100000);
		LED_RED_1_TOGGLE;

		MESSAGE(message);
		message++;
	}
}

/*
 * \brief local_message
 *
 * - Display the message
 *
 */
[[gnu::naked, gnu::optimize("Os")]]
void	local_message(uint32_t core, uint64_t message) {
	uint64_t	threshold;

// The stack has to be aligned on boundary of 16-bytes
//
//	+544	x1 ra			=
//	+536	x5 t0			=
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
//	+144	"uKOS"			= KMAGICSTACK
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
//	+40		fcsr			=
//	+32		mepc			= process address
//	+24		mcause			=
//	+16		mstatus			=
//	+8		core			=
//	+0		PLIC->mth		= PLIC priority

	__asm volatile ("																				\n \
	addi		sp,sp,-(13*8)																		\n \
	sd			s11,12*8(sp)																		\n \
	sd			s10,11*8(sp)																		\n \
	sd			s9,10*8(sp)																			\n \
	sd			s8,9*8(sp)																			\n \
	sd			s7,8*8(sp)																			\n \
	sd			s6,7*8(sp)																			\n \
	sd			s5,6*8(sp)																			\n \
	sd			s4,5*8(sp)																			\n \
	sd			s3,4*8(sp)																			\n \
	sd			s2,3*8(sp)																			\n \
	sd			tp,2*8(sp)																			\n \
	sd			gp,1*8(sp)																			\n \
	sd			x0,0*8(sp)"																			   \
	);																								   \
																									   \
	__asm volatile ("																				\n \
	addi		sp,sp,-(13*8)																		\n \
	fsd			fs11,12*8(sp)																		\n \
	fsd			fs10,11*8(sp)																		\n \
	fsd			fs9,10*8(sp)																		\n \
	fsd			fs8,9*8(sp)																			\n \
	fsd			fs7,8*8(sp)																			\n \
	fsd			fs6,7*8(sp)																			\n \
	fsd			fs5,6*8(sp)																			\n \
	fsd			fs4,5*8(sp)																			\n \
	fsd			fs3,4*8(sp)																			\n \
	fsd			fs2,3*8(sp)																			\n \
	fsd			fs1,2*8(sp)																			\n \
	fsd			fs0,1*8(sp)																			\n \
	csrr		t0,fcsr																				\n \
	sd			t0,0*8(sp)"																			   \
	);																								   \
																									   \
	threshold = (uint64_t)plic->targets.target[core].priority_threshold & 0x00000000000000FF;		   \
																									   \
	__asm volatile ("																				\n \
	addi		sp,sp,-(5*8)																		\n \
	csrr		t0,mepc																				\n \
	sd			t0,4*8(sp)																			\n \
	csrr		t0,mcause																			\n \
	sd			t0,3*8(sp)																			\n \
	csrr		t0,mstatus																			\n \
	sd			t0,2*8(sp)																			\n \
	add			t0,x0,%2																			\n \
	sd			t0,1*8(sp)																			\n \
	add			t0,x0,%1																			\n \
	sd			t0,0*8(sp)																			\n \
	add			%0,x0,sp"																			   \
	: "=r" (vKern_stackProc)																		   \
	: "r" (threshold), "r" (core)																	   \
	:																								   \
	);																								   \

	local_process(core, threshold, message);

// The stack has to be aligned on boundary of 16-bytes
//
//	+544	x1 ra			=
//	+536	x5 t0			=
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
//	+144	"uKOS"			= KMAGICSTACK
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
//	+40		fcsr			=
//	+32		mepc			= process address
//	+24		mcause			=
//	+16		mstatus			=
//	+8		core			=
//	+0		PLIC->mth		= PLIC priority

	__asm volatile ("																				\n \
	add			sp,x0,%2																			\n \
	ld			t0,0*8(sp)																			\n \
	add			%0,x0,t0																			\n \
	ld			t0,1*8(sp)																			\n \
	add			%1,x0,t0																			\n \
	ld			t0,2*8(sp)																			\n \
	csrw		mstatus,t0																			\n \
	ld			t0,3*8(sp)																			\n \
	csrw		mcause,t0																			\n \
	ld			t0,4*8(sp)																			\n \
	csrw		mepc,t0																				\n \
	addi		sp,sp,(5*8)"																		   \
	: "=r" (threshold), "=r" (core)																	   \
	: "r" (vKern_stackProc)									  										   \
	:																								   \
	);																								   \
																									   \
	plic->targets.target[core].priority_threshold = (uint32_t)(threshold & 0x00000000000000FF);		   \
																									   \
	__asm volatile ("																				\n \
	ld			t0,0*8(sp)																			\n \
	csrw		fcsr,t0																				\n \
	fld			fs0,1*8(sp)																			\n \
	fld			fs1,2*8(sp)																			\n \
	fld			fs2,3*8(sp)																			\n \
	fld			fs3,4*8(sp)																			\n \
	fld			fs4,5*8(sp)																			\n \
	fld			fs5,6*8(sp)																			\n \
	fld			fs6,7*8(sp)																			\n \
	fld			fs7,8*8(sp)																			\n \
	fld			fs8,9*8(sp)																			\n \
	fld			fs9,10*8(sp)																		\n \
	fld			fs10,11*8(sp)																		\n \
	fld			fs11,12*8(sp)																		\n \
	addi		sp,sp,(13*8)"																		   \
	);																								   \
																									   \
	__asm volatile ("																				\n \
	ld			gp,1*8(sp)																			\n \
	ld			tp,2*8(sp)																			\n \
	ld			s2,3*8(sp)																			\n \
	ld			s3,4*8(sp)																			\n \
	ld			s4,5*8(sp)																			\n \
	ld			s5,6*8(sp)																			\n \
	ld			s6,7*8(sp)																			\n \
	ld			s7,8*8(sp)																			\n \
	ld			s8,9*8(sp)																			\n \
	ld			s9,10*8(sp)																			\n \
	ld			s10,11*8(sp)																		\n \
	ld			s11,12*8(sp)																		\n \
	addi		sp,sp,(13*8)"																		   \
	);																								   \
																									   \
	__asm volatile ("																				\n \
	ld			ra,39*8(sp)																			\n \
	lw			t0,37*8(sp)																			\n \
	fscsr		t0																					\n \
	ld			s0,34*8(sp)																			\n \
	ld			t0,38*8(sp)																			\n \
	ld			t1,36*8(sp)																			\n \
	ld			t2,35*8(sp)																			\n \
	ld			s1,33*8(sp)																			\n \
	ld			a0,32*8(sp)																			\n \
	ld			a1,31*8(sp)																			\n \
	ld			a2,30*8(sp)																			\n \
	ld			a3,29*8(sp)																			\n \
	ld			a4,28*8(sp)																			\n \
	ld			a5,27*8(sp)																			\n \
	ld			a6,26*8(sp)																			\n \
	ld			a7,25*8(sp)																			\n \
	ld			t3,24*8(sp)																			\n \
	ld			t4,23*8(sp)																			\n \
	ld			t5,22*8(sp)																			\n \
	ld			t6,21*8(sp)																			\n \
	fld			ft0,19*8(sp)																		\n \
	fld			ft1,18*8(sp)																		\n \
	fld			ft2,17*8(sp)																		\n \
	fld			ft3,16*8(sp)																		\n \
	fld			ft4,15*8(sp)																		\n \
	fld			ft5,14*8(sp)																		\n \
	fld			ft6,13*8(sp)																		\n \
	fld			ft7,12*8(sp)																		\n \
	fld			fa0,11*8(sp)																		\n \
	fld			fa1,10*8(sp)																		\n \
	fld			fa2,9*8(sp)																			\n \
	fld			fa3,8*8(sp)																			\n \
	fld			fa4,7*8(sp)																			\n \
	fld			fa5,6*8(sp)																			\n \
	fld			fa6,5*8(sp)																			\n \
	fld			fa7,4*8(sp)																			\n \
	fld			ft8,3*8(sp)																			\n \
	fld			ft9,2*8(sp)																			\n \
	fld			ft10,1*8(sp)																		\n \
	fld			ft11,0*8(sp)																		\n \
	addi		sp,sp,320																			\n \
	mret"																							   \
	);
}

/*
 * \brief local_process
 *
 * - Blink the Red 2 Led
 *
 */
[[gnu::noinline]]
static	void	local_process(uint32_t core, uint64_t threshold, uint64_t message) {
	uint32_t	msb, lsb;

	LED_RED_2_TOGGLE;

	msb = (uint32_t)(core);
	(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)msb);

	cmns_send(KURT0, "Core        0x"); cmns_send(KURT0, vString);

	msb = (uint32_t)(threshold);
	(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)msb);

	cmns_send(KURT0, "  Threshold 0x"); cmns_send(KURT0, vString);

	msb = (uint32_t)(message>>32);
	lsb = (uint32_t)(message);
	(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)msb);

	cmns_send(KURT0, "  Message   0x"); cmns_send(KURT0, vString);
	(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)lsb);

	cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
}
#endif
