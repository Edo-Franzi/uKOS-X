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
; Goal:		Test of a preliminary pico kernel (with messages ECALL) and with the macro_core.
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
#define	VERBOSE_S

#define	KMSGFIRST		0xA0												// Message (run P0)
#define	KMSGRUNP0		0xA1												// Message (run P0)
#define	KMSGRUNP1		0xA2												// Message (run P1)

#if (defined(VERBOSE_S))
static		char_t		vString[20];
#endif

[[gnu::aligned(16)]]
volatile	uintptr_t	vStackFs[800];										//

[[gnu::aligned(16)]]
volatile	uintptr_t	vStackP0[800];										//

[[gnu::aligned(16)]]
volatile	uintptr_t	vStackP1[800];										//
volatile	uintptr_t	vStackCurFs;										//
volatile	uintptr_t	vStackCurP0;										//
volatile	uintptr_t	vStackCurP1;										//
volatile	uintptr_t	vKern_stackProc[KNB_CORES];							// Stacks

// Prototypes

		void	process_0(uintptr_t *argument);
		void	process_1(uintptr_t *argument);
static	void	local_message(uint32_t core, uint64_t message);

/*
 * \brief test_09
 *
 * - Test of a preliminary pico kernel (with messages ECALL) and with the macro_core
 *
 */
void	test_09(void) {
				uint32_t	core;
	volatile	uintptr_t	*stack;

	core = GET_RUNNING_CORE;
	vMsgs_process[core] = local_message;
	cmns_init();

// Initialise the stack-frame for the process P0
// Initialise the stack-frame for the process P1

	stack = &vStackP0[800 - 8];
	KERN_PREPARE_FRAME(stack, process_0, core, nullptr, KINT_IMASK_ALL)
	vStackCurP0 = (uintptr_t)stack;

	stack = &vStackP1[800 - 8];
	KERN_PREPARE_FRAME(stack, process_1, core, nullptr, KINT_IMASK_ALL)
	vStackCurP1 = (uintptr_t)stack;

// Waiting for the multitasking

	GOTO_KERN_I(KMSGFIRST);
	while (true) {
		cmns_send(KURT0, "Running first!!!\n");
	}
}

/*
 * \brief process_0
 *
 * - Blink the Red 1 Led
 *
 */
void	process_0(uintptr_t *argument) {
	uint32_t	message = KMSGRUNP1;

	UNUSED(argument);

	cmns_send(KURT0, "Enter P0\n");

	while (true) {
		cmns_send(KURT0, "Run P0\n");
		LED_RED_ON;
		cmns_wait(100000);
		LED_RED_OFF;
		cmns_wait(100000);

		GOTO_KERN_M(message);
	}
}

/*
 * \brief process_1
 *
 * - Blink the Green 1 Led
 *
 */
void	process_1(uintptr_t *argument) {
	uint32_t	message = KMSGRUNP0;

	UNUSED(argument);

	cmns_send(KURT0, "Enter P1\n");

	while (true) {
		cmns_send(KURT0, "Run P1\n");
		LED_GREEN_ON;
		cmns_wait(100000);
		LED_GREEN_OFF;
		cmns_wait(100000);

		GOTO_KERN_M(message);
	}
}

/*
 * \brief local_message
 *
 * - Change the context f(message)
 *
 */
[[gnu::naked, gnu::optimize("Os")]]
void	local_message(uint32_t core, uint64_t message) {

// Save the context
// Recover the message
// Restore a new context

	KERN_SAVE_FRAME;

	JUMP_FNCT(local_scheduler);
}

/*
 * \brief local_scheduler
 *
 * - Pico scheduler
 *
 */
[[gnu::noinline]]
void	local_scheduler(uint32_t core, uint64_t message, uint64_t *threshold, volatile uintptr_t *stack) {
	volatile	uint64_t	*newStack;

// Save the plic threshold on the current process stack
// Save the current process stack

	*threshold = (uint64_t)plic->targets.target[core].priority_threshold & 0x00000000000000FF;
	vKern_stackProc[core] = (uintptr_t)stack;

	debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&message);
	cmns_send(KURT0, "Message                  0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");

	switch (message) {
		default:

// Request to leave the Process First
// - Save the stack
// - Prepare for running the process 0

		case KMSGFIRST: {

			#if (defined(VERBOSE_S))
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vKern_stackProc[core]);
			cmns_send(KURT0, "Kernel First    Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vStackCurP0);
			cmns_send(KURT0, "Kernel First    Stack P0 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			#endif

			vStackCurFs = vKern_stackProc[core];
			vKern_stackProc[core] = vStackCurP0;
			break;
		}

// Request to run the Process P0
// - Save the stack
// - Prepare for running the process 0

		case KMSGRUNP0: {

			#if (defined(VERBOSE_S))
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vKern_stackProc[core]);
			cmns_send(KURT0, "Kernel go to P0 Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vStackCurP0);
			cmns_send(KURT0, "Kernel go to P0 Stack P0 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			#endif

			vStackCurP1 = vKern_stackProc[core];
			vKern_stackProc[core] = vStackCurP0;
			break;
		}

// Request to run the Process P1
// - Save the stack
// - Prepare for running the process 1

		case KMSGRUNP1: {

			#if (defined(VERBOSE_S))
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vKern_stackProc[core]);
			cmns_send(KURT0, "Kernel go to P1 Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vStackCurP1);
			cmns_send(KURT0, "Kernel go to P1 Stack P1 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			#endif

			vStackCurP0 = vKern_stackProc[core];
			vKern_stackProc[core] = vStackCurP1;
			break;
		}
	}

	newStack = (volatile uint64_t *)vKern_stackProc[core];
	plic->targets.target[core].priority_threshold = (uint32_t)(newStack[0] & 0x00000000000000FF);

// Prepare a1 with the pointer on the new stack (see macro KERN_NEW_FRAME)

	__asm volatile ("add	a1,x0,%0" : : "r" (newStack) :);																									\

	KERN_NEW_FRAME;
	KERN_RETURN;
}
#endif
