/*
; tests_10.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of a preliminary pico kernel (with messages EXTI) and with the macro_core.
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

#if (defined(TEST_10_S))

#undef	__VERBOSE__

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
 * \brief test_10
 *
 * - Test of a preliminary pico kernel (with messages EXTI) and with the macro_core
 *
 */
void	test_10(void) {
	volatile	uintptr_t	*stack;

	cmns_init();

	EXTI->INTEN = 0;
	EXTI->SWIEV = 0;
	EXTI->PD    = 0x7FF;
	EXTI->INTEN =(1u<<BKERN_MESSAGES);

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

	ECLIC->CLICINT[EXTI0_IRQn].CTL  = KINT_LEVEL_KERNEL_SWI;
	ECLIC->CLICINT[EXTI0_IRQn].IP   = 0;
	ECLIC->CLICINT[EXTI0_IRQn].IE   = 1;
	ECLIC->CLICINT[EXTI0_IRQn].ATTR = ECLIC_INT_ATTR_SHV | ECLIC_INT_ATTR_TRIG_EDGE_RISING;
	ECLIC->MTH = KINT_IMASK_ALL;

// Initialise the stack-frame for the process P0
// Initialise the stack-frame for the process P1

	stack = &vStackP0[800 - 4];
	KERN_PREPARE_FRAME(stack, process_0, nullptr, KINT_IMASK_ALL)
	vStackCurP0 = (uintptr_t)stack;

	stack = &vStackP1[800 - 4];
	KERN_PREPARE_FRAME(stack, process_1, nullptr, KINT_IMASK_ALL)
	vStackCurP1 = (uintptr_t)stack;

// Waiting for the multitasking

	INTERRUPTION_ON_HARD;

	GOTO_KERN_I(KMSGFIRST);
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
	uint32_t	message = KMSGRUNP1;

	UNUSED(argument);

	cmns_send(KURT0, "Enter P0\n");
	ECLIC->MTH = KINT_IMASK_ALL+10;

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
 * - Blink the YELLOW Led
 *
 */
void	process_1(uintptr_t *argument) {
	uint32_t	message = KMSGRUNP0;

	UNUSED(argument);

	cmns_send(KURT0, "Enter P1\n");
	ECLIC->MTH = KINT_IMASK_ALL+11;

	while (true) {
		cmns_send(KURT0, "Run P1\n");
		LED_BLUE_ON;
		cmns_wait(100000);
		LED_BLUE_OFF;
		cmns_wait(100000);

		GOTO_KERN_M(message);
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

// Save the context
// Recover the message

	KERN_SAVE_FRAME;
	KERN_RECOVER_MESSAGE;

	EXTI->SWIEV &= (uint32_t)~(1u<<BKERN_MESSAGES);
	EXTI->PD     =			  (1u<<BKERN_MESSAGES);
	local_scheduler();

// Restore a new context

	KERN_NEW_FRAME;
	KERN_RETURN;
}

/*
 * \brief local_scheduler
 *
 * - Pico scheduler
 *
 */
[[gnu::noinline]]
static	void	local_scheduler(void) {
	uint8_t		mth8;
	uint32_t	mth32;

	mth8 = ECLIC->MTH; mth32 = (uint32_t)mth8;
	debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&mth32);
	cmns_send(KURT0, "ECLIC mth 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");

	switch (vKern_message) {
		default:

// Request to leave the Process First
// - Save the stack
// - Prepare for running the process 0

		case KMSGFIRST: {

			#if (defined(__VERBOSE__))
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vKern_stackProc);
			cmns_send(KURT0, "Kernel First    Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vStackCurP0);
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
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vKern_stackProc);
			cmns_send(KURT0, "Kernel go to P0 Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vStackCurP0);
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
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vKern_stackProc);
			cmns_send(KURT0, "Kernel go to P1 Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vStackCurP1);
			cmns_send(KURT0, "Kernel go to P1 Stack P1 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
			#endif

			vStackCurP0		= vKern_stackProc;
			vKern_stackProc	= vStackCurP1;
			break;
		}
	}
}
#endif
