/*
; tests_07.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of a preliminary pico kernel (with messages swi).
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

#if (defined(TEST_07_S))

#undef	VERBOSE_S

#define	MESSAGE(msg)	__asm volatile ("										\n \
						movw		r0,%0										\n \
						movt		r0,%1										\n \
						push		{r0}										\n \
						push		{r0}"										   \
						:														   \
						: "i" ((msg) & 0x0000FFFF), "i" ((msg) >> 16)			   \
						: "r0"													   \
						);														   \
						__asm volatile ("										\n \
						svc			0											\n \
						dmb														\n \
						dsb														\n \
						isb														\n \
						mrs			r0,psp										\n \
						add			r0,r0,#8									\n \
						msr			psp,r0"										   \
						:														   \
						:														   \
						: "r0"													   \
						);

#define	KMSGFIRST		0xA0												// Message (run P0)
#define	KMSGRUNP0		0xA1												// Message (run P0)
#define	KMSGRUNP1		0xA2												// Message (run P1)

#if (defined(VERBOSE_S))
static		char_t		vString[20];
#endif

[[gnu::aligned(8)]]
volatile	uintptr_t	vStackFs[200];										//

[[gnu::aligned(8)]]
volatile	uintptr_t	vStackP0[200];										//

[[gnu::aligned(8)]]
volatile	uintptr_t	vStackP1[200];										//
volatile	uintptr_t	vStackCurFs;										//
volatile	uintptr_t	vStackCurP0;										//
volatile	uintptr_t	vStackCurP1;										//
volatile	uintptr_t	vSaveStack;											// Stacks
volatile	uint32_t	vMessage;											// Messages

// Prototypes

		void	process_0(uintptr_t *argument);
		void	process_1(uintptr_t *argument);
static	void	local_scheduler(void);

/*
 * \brief test_07
 *
 * - Test of a preliminary pico kernel (with messages swi)
 *
 */
void	test_07(void) {
	volatile	uintptr_t	*stack;
	volatile	uint32_t	priority;

	cmns_init();

// Initialise the stack-frame for the process P0

	priority = (KINT_IMASK_ALL<<KNVIC_PRIORITY_SHIFT);

	stack = &vStackP0[200];						// Stack of the process 0

	*(--stack) = 0x01000000;					// xPSR
	*(--stack) = (uintptr_t)process_0;			// pc Process address
	*(--stack) = 0xFFFFFFFD;					// lr
	*(--stack) = 0x12121212;					// r12
	*(--stack) = 0x03030303;					// r3
	*(--stack) = 0x02020202;					// r2
	*(--stack) = 0x01010101;					// r1
	*(--stack) = 0x00000000;					// r0 process arguments
	*(--stack) = 0x11111111;					// r11
	*(--stack) = 0x10101010;					// r10
	*(--stack) = 0x09090909;					// r9
	*(--stack) = 0x08080808;					// r8
	*(--stack) = 0x07070707;					// r7
	*(--stack) = 0x06060606;					// r6
	*(--stack) = 0x05050505;					// r5
	*(--stack) = 0x04040404;					// r4
	*(--stack) = priority;						// basepri
	*(--stack) = 0xFFFFFFFD;					// lr

	vStackCurP0 = (uintptr_t)stack;				// Stack of the process 0

// Initialise the stack-frame for the process P1

	priority = (KINT_IMASK_ALL<<KNVIC_PRIORITY_SHIFT);

	stack = &vStackP1[200];						// Stack of the process 1

	*(--stack) = 0x01000000;					// xPSR
	*(--stack) = (uintptr_t)process_1;			// pc Process address
	*(--stack) = 0xFFFFFFFD;					// lr
	*(--stack) = 0x12121212;					// r12
	*(--stack) = 0x03030303;					// r3
	*(--stack) = 0x02020202;					// r2
	*(--stack) = 0x01010101;					// r1
	*(--stack) = 0x00000000;					// r0 process arguments
	*(--stack) = 0x11111111;					// r11
	*(--stack) = 0x10101010;					// r10
	*(--stack) = 0x09090909;					// r9
	*(--stack) = 0x08080808;					// r8
	*(--stack) = 0x07070707;					// r7
	*(--stack) = 0x06060606;					// r6
	*(--stack) = 0x05050505;					// r5
	*(--stack) = 0x04040404;					// r4
	*(--stack) = priority;						// basepri
	*(--stack) = 0xFFFFFFFD;					// lr

	vStackCurP1 = (uintptr_t)stack;				// Stack of the process 1

// Waiting for the multitasking

	INTERRUPTION_ON_HARD;

	MESSAGE(KMSGFIRST);
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
		LED_0_ON;
		cmns_wait(100000);
		LED_0_OFF;
		cmns_wait(100000);
		MESSAGE(KMSGRUNP1);
	}
}

/*
 * \brief process_1
 *
 * - Blink the BLUE Led
 *
 */
void	process_1(uintptr_t *argument) {

	UNUSED(argument);

	cmns_send(KURT0, "Enter P1\n");

	while (true) {
		cmns_send(KURT0, "Run P1\n");
		LED_1_ON;
		cmns_wait(100000);
		LED_1_OFF;
		cmns_wait(100000);
		MESSAGE(KMSGRUNP0);
	}
}

/*
 * \brief SVCall_IRQHandler
 *
 * - Change the context f(message)
 *
 */
#define	KSAVEREGISTERS	"r0", "r1", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11"

[[gnu::naked, gnu::optimize("Os")]]
void	SVCall_IRQHandler(void) {

// Recover the message

	__asm volatile ("							\n \
	cpsid		i								\n \
	tst			lr,#0x4							\n \
	ite 		eq								\n \
	mrseq		r0,msp							\n \
	mrsne		r0,psp							\n \
	add			r1,r0,#(32+4)					\n \
	ldr			r1,[r1]							\n \
	str			r1,%0"							   \
	:											   \
	: "m" (vMessage)							   \
	: KSAVEREGISTERS							   \
	);

// Save the machine context

	__asm volatile ("							\n \
	mrs			r1,basepri						\n \
	stmdb 		r0!,{r1,r4-r11}					\n \
	stmdb 		r0!,{lr}						\n \
	tst			lr,#0x4							\n \
	ite 		eq								\n \
	msreq		msp,r0							\n \
	msrne		psp,r0							\n \
	str			r0,%0							\n \
	cpsie		i"								   \
	:											   \
	: "m" (vSaveStack)							   \
	: KSAVEREGISTERS							   \
	);

		local_scheduler();

// Run the next process
// --------------------

// Final restore
// - Recover the new Px stack
// - Restore the machine context
// - Returm to the process

	__asm volatile ("							\n \
	cpsid		i								\n \
	ldr			r0,%0							\n \
	ldmia		r0!,{lr}						\n \
	ldmia 		r0!,{r1,r4-r11}					\n \
	tst			lr,#0x4							\n \
	ite 		eq								\n \
	msreq		msp,r0							\n \
	msrne		psp,r0							\n \
	msr			basepri,r1"						   \
	:											   \
	: "m" (vSaveStack)							   \
	: KSAVEREGISTERS							   \
	);

	__asm volatile ("							\n \
	cpsie		i								\n \
	dmb											\n \
	dsb											\n \
	isb											\n \
	bx			lr"								   \
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

	switch (vMessage) {
		default:

// Request to leave the Process First
// - Save the stack
// - Prepare for running the process 0

		case KMSGFIRST: {

			#if (defined(VERBOSE_S))
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vSaveStack);
			cmns_send(KURT0, "Kernel First    Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vStackCurP0);
			cmns_send(KURT0, "Kernel First    Stack P0 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			#endif

			vStackCurFs	= vSaveStack;
			vSaveStack	= vStackCurP0;
			break;
		}

// Request to run the Process P0
// - Save the stack
// - Prepare for running the process 0

		case KMSGRUNP0: {

			#if (defined(VERBOSE_S))
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vSaveStack);
			cmns_send(KURT0, "Kernel go to P0 Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vStackCurP0);
			cmns_send(KURT0, "Kernel go to P0 Stack P0 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			#endif

			vStackCurP1	= vSaveStack;
			vSaveStack	= vStackCurP0;
			break;
		}

// Request to run the Process P1
// - Save the stack
// - Prepare for running the process 1

		case KMSGRUNP1: {

			#if (defined(VERBOSE_S))
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vSaveStack);
			cmns_send(KURT0, "Kernel go to P1 Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vStackCurP1);
			cmns_send(KURT0, "Kernel go to P1 Stack P1 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			#endif

			vStackCurP0	= vSaveStack;
			vSaveStack	= vStackCurP1;
			break;
		}
	}
}
#endif
