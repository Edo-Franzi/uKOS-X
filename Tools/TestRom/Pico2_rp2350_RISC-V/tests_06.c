/*
; tests_06.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of a preliminary pico kernel (with messages ecall).
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

#include	"tests.h"

#if (defined(TEST_06_S))

#define	VERBOSE_S

// Ecall context-switch support (defined in first_rv.c, used by the trap handler)

extern	volatile	uintptr_t	vSaveStack;
extern	volatile	uint32_t	vMessage;

#define	MESSAGE(msg)	__asm volatile (				\
						"li		a0,%0			\n"		\
						"ecall					\n"		\
						"fence					\n"		\
						:								\
						: "i" (msg)						\
						: "a0"							\
						)

#define	KMSGFIRST		0xA0												// Message (run P0)
#define	KMSGRUNP0		0xA1												// Message (run P0)
#define	KMSGRUNP1		0xA2												// Message (run P1)

#if (defined(VERBOSE_S))
static		char_t		vString[20];
#endif

volatile	uintptr_t	vStackP0[200] __attribute__ ((aligned (16)));		//
volatile	uintptr_t	vStackP1[200] __attribute__ ((aligned (16)));		//
volatile	uintptr_t	vStackCurFs;										//
volatile	uintptr_t	vStackCurP0;										//
volatile	uintptr_t	vStackCurP1;										//

// Prototypes

		void	process_0(uintptr_t *argument);
		void	process_1(uintptr_t *argument);
static	void	local_scheduler(void);

/*
 * \brief test_06
 *
 * - Test of a preliminary pico kernel (with messages ecall)
 *
 * Stack layout for a suspended process (28 words, 112 bytes):
 *   [0..11]  s0-s11  (callee-saved, saved by ecall path)
 *   [12..27] trap frame: ra, t0-t2, a0-a7, mcause, mepc, pad, pad
 *
 */
void	test_06(void) {
	volatile	uintptr_t	*stack;

	cmns_init();

// Initialise the stack-frame for the process P0

	stack = &vStackP0[200];						// Stack of the process 0

	*(--stack) = 0x00000000;					// pad (15)
	*(--stack) = 0x00000000;					// pad (14)
	*(--stack) = (uintptr_t)process_0;			// mepc (13) - process entry point
	*(--stack) = 0x00000000;					// mcause (12)
	*(--stack) = 0x17171717;					// a7 (11)
	*(--stack) = 0x16161616;					// a6 (10)
	*(--stack) = 0x15151515;					// a5 (9)
	*(--stack) = 0x14141414;					// a4 (8)
	*(--stack) = 0x13131313;					// a3 (7)
	*(--stack) = 0x12121212;					// a2 (6)
	*(--stack) = 0x11111111;					// a1 (5)
	*(--stack) = 0x00000000;					// a0 (4) - process arguments
	*(--stack) = 0x07070707;					// t2 (3)
	*(--stack) = 0x06060606;					// t1 (2)
	*(--stack) = 0x05050505;					// t0 (1)
	*(--stack) = 0xDEADBEEF;					// ra (0)

	*(--stack) = 0x27272727;					// s11
	*(--stack) = 0x26262626;					// s10
	*(--stack) = 0x25252525;					// s9
	*(--stack) = 0x24242424;					// s8
	*(--stack) = 0x23232323;					// s7
	*(--stack) = 0x22222222;					// s6
	*(--stack) = 0x21212121;					// s5
	*(--stack) = 0x20202020;					// s4
	*(--stack) = 0x19191919;					// s3
	*(--stack) = 0x18181818;					// s2
	*(--stack) = 0x09090909;					// s1
	*(--stack) = 0x08080808;					// s0

	vStackCurP0 = (uintptr_t)stack;				// Stack of the process 0

// Initialise the stack-frame for the process P1

	stack = &vStackP1[200];						// Stack of the process 1

	*(--stack) = 0x00000000;					// pad (15)
	*(--stack) = 0x00000000;					// pad (14)
	*(--stack) = (uintptr_t)process_1;			// mepc (13) - process entry point
	*(--stack) = 0x00000000;					// mcause (12)
	*(--stack) = 0x17171717;					// a7 (11)
	*(--stack) = 0x16161616;					// a6 (10)
	*(--stack) = 0x15151515;					// a5 (9)
	*(--stack) = 0x14141414;					// a4 (8)
	*(--stack) = 0x13131313;					// a3 (7)
	*(--stack) = 0x12121212;					// a2 (6)
	*(--stack) = 0x11111111;					// a1 (5)
	*(--stack) = 0x00000000;					// a0 (4) - process arguments
	*(--stack) = 0x07070707;					// t2 (3)
	*(--stack) = 0x06060606;					// t1 (2)
	*(--stack) = 0x05050505;					// t0 (1)
	*(--stack) = 0xDEADBEEF;					// ra (0)

	*(--stack) = 0x27272727;					// s11
	*(--stack) = 0x26262626;					// s10
	*(--stack) = 0x25252525;					// s9
	*(--stack) = 0x24242424;					// s8
	*(--stack) = 0x23232323;					// s7
	*(--stack) = 0x22222222;					// s6
	*(--stack) = 0x21212121;					// s5
	*(--stack) = 0x20202020;					// s4
	*(--stack) = 0x19191919;					// s3
	*(--stack) = 0x18181818;					// s2
	*(--stack) = 0x09090909;					// s1
	*(--stack) = 0x08080808;					// s0

	vStackCurP1 = (uintptr_t)stack;				// Stack of the process 1

// Register the ecall handler (exception code 11 = ecall from M-mode)

	EXCEPTION_VECTOR(11, local_scheduler);

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
		LED_RED_ON;
		cmns_wait(100000);
		LED_RED_OFF;
		cmns_wait(100000);
		MESSAGE(KMSGRUNP1);
	}
}

/*
 * \brief process_1
 *
 * - Blink the GREEN Led
 *
 */
void	process_1(uintptr_t *argument) {

	UNUSED(argument);

	cmns_send(KURT0, "Enter P1\n");

	while (true) {
		cmns_send(KURT0, "Run P1\n");
		LED_GREEN_ON;
		cmns_wait(100000);
		LED_GREEN_OFF;
		cmns_wait(100000);
		MESSAGE(KMSGRUNP0);
	}
}

/*
 * \brief local_scheduler
 *
 * - Pico scheduler
 *
 */
static	void	__attribute__ ((noinline)) local_scheduler(void) {

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
