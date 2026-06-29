/*
; tests_09.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of a preliminary pico kernel (with messages EXTI).
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

#if (defined(TEST_09_S))

#define	__VERBOSE__

#define	MESSAGE_I(msg)	__asm volatile ("									\n \
						lui			t0,%%hi(%0)								\n \
						li			t0,%%lo(%0)								\n \
						addi		sp,sp,-4								\n \
						sw			t0,0(sp)"								   \
						:													   \
						: "i" (msg)											   \
						: "t0"												   \
						);													   \
						EXTI->SWIEV |=(1u<<BKERN_MESSAGES);					   \
						while ((EXTI->SWIEV & (1u<<BKERN_MESSAGES)) != 0);	   \
						__asm volatile ("									\n \
						addi		sp,sp,4"								   \
						);

#define	MESSAGE_M(msg)	__asm volatile ("									\n \
						add			t0,x0,%0								\n \
						addi		sp,sp,-4								\n \
						sw			t0,0(sp)"								   \
						:													   \
						: "r" (msg)											   \
						: "t0"												   \
						);													   \
						EXTI->SWIEV |= (1u<<BKERN_MESSAGES);				   \
						while ((EXTI->SWIEV & (1u<<BKERN_MESSAGES)) != 0);	   \
						__asm volatile ("									\n \
						addi		sp,sp,4"								   \
						);

#define	KMSGFIRST		0xA0												// Message (run P0)
#define	KMSGRUNP0		0xA1												// Message (run P0)
#define	KMSGRUNP1		0xA2												// Message (run P1)

static		char_t		vString[20];
[[gnu::aligned(16)]]
volatile	uintptr_t	vStackFs[800];										//

[[gnu::aligned(16)]]
volatile	uintptr_t	vStackP0[800];										//

[[gnu::aligned(16)]]
volatile	uintptr_t	vStackP1[800];										//
volatile	uintptr_t	vStackCurFs;										//
volatile	uintptr_t	vStackCurP0;										//
volatile	uintptr_t	vStackCurP1;										//
volatile	uintptr_t	vKern_stackProc;									// Stacks
volatile	uint32_t	vKern_message;										// Messages

// Prototypes

		void	process_0(uintptr_t *argument);
		void	process_1(uintptr_t *argument);
static	void	local_scheduler(void);

/*
 * \brief test_09
 *
 * - Test of a preliminary pico kernel (with messages EXTI)
 *
 */
void	test_09(void) {
	volatile	uintptr_t	*stack;

	cmns_init();

	EXTI->INTEN = 0;
	EXTI->SWIEV = 0;
	EXTI->PD    = 0x7FF;
	EXTI->INTEN = (1u<<BKERN_MESSAGES);

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
// mth = 31 (KINT_IMASK_ALL)

	ECLIC->CLICINT[EXTI0_IRQn].CTL  = KINT_LEVEL_ALL;
	ECLIC->CLICINT[EXTI0_IRQn].IP   = 0;
	ECLIC->CLICINT[EXTI0_IRQn].IE   = 1;
	ECLIC->CLICINT[EXTI0_IRQn].ATTR = ECLIC_INT_ATTR_SHV | ECLIC_INT_ATTR_TRIG_EDGE_RISING;
	ECLIC->MTH = KINT_IMASK_ALL;

// Initialise the stack-frame for the process P0

	stack = &vStackP0[800 - 8];						// Stack of the process 0

	*(--stack) = KMAGICSTACK;						// "uKOS"
	*(--stack) = (uintptr_t)process_0;				// mepc
	*(--stack) = KPROCESS_INIT_MCAUSE;				// mcause
	*(--stack) = MSTATUS_MPP | MSTATUS_MPIE;		// mstatus
	*(--stack) = (uint32_t)ECLIC->MTH;				// ECLIC->MTH
	*(--stack) = 0x31313131;						// x31 t6
	*(--stack) = 0x30303030;						// x30 t5
	*(--stack) = 0x29292929;						// x29 t4
	*(--stack) = 0x28282828;						// x28 t3
	*(--stack) = 0x27272727;						// x27 s11
	*(--stack) = 0x26262626;						// x26 s10
	*(--stack) = 0x25252525;						// x25 s9
	*(--stack) = 0x24242424;						// x24 s8
	*(--stack) = 0x23232324;						// x23 s7
	*(--stack) = 0x22222222;						// x22 s6
	*(--stack) = 0x21212121;						// x21 s5
	*(--stack) = 0x20202020;						// x20 s4
	*(--stack) = 0x19191919;						// x19 s3
	*(--stack) = 0x18181818;						// x18 s2
	*(--stack) = 0x17171717;						// x17 a7
	*(--stack) = 0x16161616;						// x16 a6
	*(--stack) = 0x15151515;						// x15 a5
	*(--stack) = 0x14141414;						// x14 a4
	*(--stack) = 0x13131313;						// x13 a3
	*(--stack) = 0x12121212;						// x12 a2
	*(--stack) = 0x11111111;						// x11 a1
	*(--stack) = 0x01234567;						// x10 a0
	*(--stack) = 0x09090909;						// x9 s1
	*(--stack) = 0x08080808;						// x8 s0 fp
	*(--stack) = 0x07070707;						// x7 t2
	*(--stack) = 0x06060606;						// x6 t1
	*(--stack) = 0x05050505;						// x5 t0
	*(--stack) = 0x04040404;						// x4 tp
	*(--stack) = 0x03030303;						// x3 gp
	*(--stack) = 0x01010101;						// x1 ra
	--stack;

	vStackCurP0 = (uintptr_t)stack;					// Stack of the process 0

// Initialise the stack-frame for the process P1

	stack = &vStackP1[800 - 8];						// Stack of the process 1

	*(--stack) = KMAGICSTACK;						// "uKOS"
	*(--stack) = (uintptr_t)process_1;				// mepc
	*(--stack) = KPROCESS_INIT_MCAUSE;				// mcause
	*(--stack) = MSTATUS_MPP | MSTATUS_MPIE;		// mstatus
	*(--stack) = (uint32_t)ECLIC->MTH;				// ECLIC->MTH
	*(--stack) = 0x31313131;						// x31 t6
	*(--stack) = 0x30303030;						// x30 t5
	*(--stack) = 0x29292929;						// x29 t4
	*(--stack) = 0x28282828;						// x28 t3
	*(--stack) = 0x27272727;						// x27 s11
	*(--stack) = 0x26262626;						// x26 s10
	*(--stack) = 0x25252525;						// x25 s9
	*(--stack) = 0x24242424;						// x24 s8
	*(--stack) = 0x23232324;						// x23 s7
	*(--stack) = 0x22222222;						// x22 s6
	*(--stack) = 0x21212121;						// x21 s5
	*(--stack) = 0x20202020;						// x20 s4
	*(--stack) = 0x19191919;						// x19 s3
	*(--stack) = 0x18181818;						// x18 s2
	*(--stack) = 0x17171717;						// x17 a7
	*(--stack) = 0x16161616;						// x16 a6
	*(--stack) = 0x15151515;						// x15 a5
	*(--stack) = 0x14141414;						// x14 a4
	*(--stack) = 0x13131313;						// x13 a3
	*(--stack) = 0x12121212;						// x12 a2
	*(--stack) = 0x11111111;						// x11 a1
	*(--stack) = 0x01234567;						// x10 a0
	*(--stack) = 0x09090909;						// x9 s1
	*(--stack) = 0x08080808;						// x8 s0 fp
	*(--stack) = 0x07070707;						// x7 t2
	*(--stack) = 0x06060606;						// x6 t1
	*(--stack) = 0x05050505;						// x5 t0
	*(--stack) = 0x04040404;						// x4 tp
	*(--stack) = 0x03030303;						// x3 gp
	*(--stack) = 0x01010101;						// x1 ra
	--stack;

	vStackCurP1 = (uintptr_t)stack;					// Stack of the process 1

// Waiting for the multitasking

	core_setBitCSR(RV_CSR_MSTATUS, MSTATUS_MIE);

	MESSAGE_I(KMSGFIRST);
	while (true) {
		cmns_send(KURT0, "Running first!!!\n");
	}
}

/*
 * \brief process_0
 *
 * - Blink the RED Led
 *
 */
void	process_0(uintptr_t *argument) {

	UNUSED(argument);

	cmns_send(KURT0, "Enter P0\n");

	while (true) {
		cmns_send(KURT0, "Run P0\n");
		LED_RED_ON;
		cmns_wait(100000);
		LED_RED_OFF;
		cmns_wait(100000);
		MESSAGE_I(KMSGRUNP1);
	}
}

/*
 * \brief process_1
 *
 * - Blink the YELLOW Led
 *
 */
void	process_1(uintptr_t *argument) {
	uint32_t	message = KMSGRUNP0;

	UNUSED(argument);

	cmns_send(KURT0, "Enter P1\n");

	while (true) {
		cmns_send(KURT0, "Run P1\n");
		LED_BLUE_ON;
		cmns_wait(100000);
		LED_BLUE_OFF;
		cmns_wait(100000);
		MESSAGE_M(message);
	}
}

/*
 * \brief EXTI0_IRQHandler
 *
 * - Change the context f(message)
 *
 */
[[gnu::naked, gnu::optimize("Os")]]
void	EXTI0_IRQHandler(void) {

	__asm volatile ("								\n \
	addi		sp,sp,-140							\n \
	sw			x1,4(sp)							\n \
	sw			x3,8(sp)							\n \
	sw			x4,12(sp)							\n \
	sw			x5,16(sp)							\n \
	sw			x6,20(sp)							\n \
	sw			x7,24(sp)							\n \
	sw			x8,28(sp)							\n \
	sw			x9,32(sp)							\n \
	sw			x10,36(sp)							\n \
	sw			x11,40(sp)							\n \
	sw			x12,44(sp)							\n \
	sw			x13,48(sp)							\n \
	sw			x14,52(sp)							\n \
	sw			x15,56(sp)							\n \
	sw			x16,60(sp)							\n \
	sw			x17,64(sp)							\n \
	sw			x18,68(sp)							\n \
	sw			x19,72(sp)							\n \
	sw			x20,76(sp)							\n \
	sw			x21,80(sp)							\n \
	sw			x22,84(sp)							\n \
	sw			x23,88(sp)							\n \
	sw			x24,92(sp)							\n \
	sw			x25,96(sp)							\n \
	sw			x26,100(sp)							\n \
	sw			x27,104(sp)							\n \
	sw			x28,108(sp)							\n \
	sw			x29,112(sp)							\n \
	sw			x30,116(sp)							\n \
	sw			x31,120(sp)							\n \
	lui			t0,%%hi(%1)							\n \
	lbu			t1,%%lo(%1)(t0)						\n \
	andi		t1,t1,0xFF							\n \
	sw			t1,124(sp)							\n \
	csrr		t0,mstatus							\n \
	sw			t0,128(sp)							\n \
	csrr		t0,mcause							\n \
	sw			t0,132(sp)							\n \
	csrr		t0,mepc								\n \
	sw			t0,136(sp)							\n \
	add			%0,x0,sp"							   \
	: "=r" (vKern_stackProc)						   \
	: "i" (&ECLIC->MTH)								   \
	:												   \
	);

// Recover the message

	__asm volatile ("								\n \
	lw			t0,140(sp)							\n \
	sw			t0,%0"								   \
	:												   \
	: "m" (vKern_message)							   \
	:												   \
	);

	EXTI->SWIEV &= (uint32_t)~(1u<<BKERN_MESSAGES);
	EXTI->PD     =			  (1u<<BKERN_MESSAGES);
	local_scheduler();

// Run the next process
// --------------------

// Final restore
// - Recover the new Px stack
// - Restore the machine context
// - Returm to the process

	__asm volatile ("								\n \
	add			sp,x0,%0							\n \
	lw			x1,4(sp)							\n \
	lw			x3,8(sp)							\n \
	lw			x4,12(sp)							\n \
	lw			x7,24(sp)							\n \
	lw			x8,28(sp)							\n \
	lw			x9,32(sp)							\n \
	lw			x10,36(sp)							\n \
	lw			x11,40(sp)							\n \
	lw			x12,44(sp)							\n \
	lw			x13,48(sp)							\n \
	lw			x14,52(sp)							\n \
	lw			x15,56(sp)							\n \
	lw			x16,60(sp)							\n \
	lw			x17,64(sp)							\n \
	lw			x18,68(sp)							\n \
	lw			x19,72(sp)							\n \
	lw			x20,76(sp)							\n \
	lw			x21,80(sp)							\n \
	lw			x22,84(sp)							\n \
	lw			x23,88(sp)							\n \
	lw			x24,92(sp)							\n \
	lw			x25,96(sp)							\n \
	lw			x26,100(sp)							\n \
	lw			x27,104(sp)							\n \
	lw			x28,108(sp)							\n \
	lw			x29,112(sp)							\n \
	lw			x30,116(sp)							\n \
	lw			x31,120(sp)							\n \
	lw			t1,124(sp)							\n \
	andi		t1,t1,0xFF							\n \
	lui			t0,%%hi(%1)							\n \
	sb			t1,%%lo(%1)(t0)						\n \
	lw			t0,128(sp)							\n \
	csrw		mstatus,t0							\n \
	lw			t0,132(sp)							\n \
	csrw		mcause,t0							\n \
	lw			t0,136(sp)							\n \
	csrw		mepc,t0								\n \
	lw			x5,16(sp)							\n \
	lw			x6,20(sp)							\n \
	addi		sp,sp,140							\n \
	mret"											   \
	:												   \
	: "r" (vKern_stackProc), "i" (&ECLIC->MTH)	 	   \
	:												   \
	);
}

/*
 * \brief local_scheduler
 *
 * - Pico scheduler
 *
 */
[[gnu::noinline]]
static	void	local_scheduler(void) {

	(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vKern_message);
	cmns_send(KURT0, "Message 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");

	switch (vKern_message) {
		default:

// Request to leave the Process First
// - Save the stack
// - Prepare for running the process 0

		case KMSGFIRST: {

			#if (defined(__VERBOSE__))
			(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vKern_stackProc);
			cmns_send(KURT0, "Kernel First    Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vStackCurP0);
			cmns_send(KURT0, "Kernel First    Stack P0 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			#endif

			vStackCurFs		= vKern_stackProc;
			vKern_stackProc	= vStackCurP0;
			break;
		}

// Request to run the Process P0
// - Save the stack
// - Prepare for running the process 0

		case KMSGRUNP0: {

			#if (defined(__VERBOSE__))
			(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vKern_stackProc);
			cmns_send(KURT0, "Kernel go to P0 Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vStackCurP0);
			cmns_send(KURT0, "Kernel go to P0 Stack P0 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			#endif

			vStackCurP1		= vKern_stackProc;
			vKern_stackProc	= vStackCurP0;
			break;
		}

// Request to run the Process P1
// - Save the stack
// - Prepare for running the process 1

		case KMSGRUNP1: {

			#if (defined(__VERBOSE__))
			(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vKern_stackProc);
			cmns_send(KURT0, "Kernel go to P1 Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vStackCurP1);
			cmns_send(KURT0, "Kernel go to P1 Stack P1 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			#endif

			vStackCurP0		= vKern_stackProc;
			vKern_stackProc	= vStackCurP1;
			break;
		}
	}
}
#endif
