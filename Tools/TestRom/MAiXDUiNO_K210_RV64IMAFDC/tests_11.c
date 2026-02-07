/*
; tests_11.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of a preliminary pico kernel (with TIM_0) and with the macro_core.
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

#if (defined(TEST_11_S))
#undef	VERBOSE_S

#define	KTTIMESAMPLING	10000000										// 100-ms -> 100'000'000-ns

#if (defined(VERBOSE_S))
static		char_t		vString[20];
#endif

volatile	uint64_t	vStackP0[800] __attribute__ ((aligned (16)));	//
volatile	uint64_t	vStackP1[800] __attribute__ ((aligned (16)));	//
volatile	uintptr_t	vStackCurFs;									//
volatile	uintptr_t	vStackCurP0;									//
volatile	uintptr_t	vStackCurP1;									//
volatile	uintptr_t	vKern_stackProc[KNB_CORES];						// Stacks

// Prototypes

		void	process_0(uintptr_t *argument);
		void	process_1(uintptr_t *argument);
static	void	local_kern(uint32_t core, uint64_t number);

/*
 * \brief test_11
 *
 * - Test of a preliminary pico kernel (with TIM_0) and with the macro_core
 *
 */
void	test_11(void) {
				float64_t	step;
				uint32_t	core = 0, current;
	volatile	uintptr_t	*stackP0, *stackP1;

	INTERRUPTION_SET;
	INTERRUPTION_ON_HARD;

	cmns_init();

// Initialise the stack-frame for the process P0
// Initialise the stack-frame for the process P1

	stackP0 = &vStackP0[800 - 8];
	KERN_PREPARE_FRAME(stackP0, process_0, core, nullptr, KINT_IMASK_ALL)
	vStackCurP0 = (uintptr_t)stackP0;

	stackP1 = &vStackP1[800 - 8];
	KERN_PREPARE_FRAME(stackP1, process_1, core, nullptr, KINT_IMASK_ALL)
	vStackCurP1 = (uintptr_t)stackP1;

// Turn on the TIM0

	sysctl->clk_en_peri.timer0_clk_en = 1;

// Set the priority
// Get current enable bit array by IRQ number
// Set enable bit in enable bit array
// Write back the enable bit array

	core = GET_RUNNING_CORE;
	EXT_INTERRUPT_VECTOR(EINT_TIMER0A_INTERRUPT, local_kern);

	plic->source_priorities.priority[EINT_TIMER0A_INTERRUPT] = KINT_LEVEL_KERNEL_TIMERS;
	current = plic->target_enables.target[core].enable[EINT_TIMER0A_INTERRUPT / 32];
	current |= (uint32_t)(1u<<(EINT_TIMER0A_INTERRUPT % 32));
	plic->target_enables.target[core].enable[EINT_TIMER0A_INTERRUPT / 32] = current;

// Initialise the TIM0_0 to generate interruptions every 100-ms

	step = 1e9 / KFREQUENCY_TIM;
	timer0->channel[0].load_count = (uint32_t)(KTTIMESAMPLING / step);
	timer0->channel[0].control &= ~TIMER_CR_INTERRUPT_MASK;
	timer0->channel[0].control |= (TIMER_CR_USER_MODE | TIMER_CR_ENABLE);

// Waiting for the multitasking

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

	UNUSED(argument);

	cmns_send(KURT0, "Enter P0\n");

	while (true) {
		cmns_send(KURT0, "Run P0\n");
		LED_RED_ON;
		cmns_wait(10000);
		LED_RED_OFF;
		cmns_wait(10000);
	}
}

/*
 * \brief process_1
 *
 * - Blink the Green 1 Led
 *
 */
void	process_1(uintptr_t *argument) {

	UNUSED(argument);

	cmns_send(KURT0, "Enter P1\n");

	while (true) {
		cmns_send(KURT0, "Run P1\n");
		LED_GREEN_ON;
		cmns_wait(10000);
		LED_GREEN_OFF;
		cmns_wait(10000);
	}
}

/*
 * \brief local_kern
 *
 * - Change the context
 *
 */
void	local_kern(uint32_t core, uint64_t number) __attribute__ ((naked, optimize("Os")));
void	local_kern(uint32_t core, uint64_t number) {

// Save the context
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
void	__attribute__ ((noinline)) local_scheduler(uint32_t core, uint64_t parameter, uint64_t *threshold, volatile uintptr_t *stack) {
	static		uint8_t		vIndex = 0;
	volatile	uint64_t	*newStack;

// Save the plic threshold on the current process stack
// Save the current process stack

	*threshold = (uint64_t)plic->targets.target[core].priority_threshold & 0x00000000000000FF;
	vKern_stackProc[core] = (uintptr_t)stack;

// Acknowledge the TIM0_0 interruption
// Acknowledge the PLIC claim complete

	timer0->channel[0].eoi;
	plic->targets.target[core].claim_complete = (uint32_t)parameter;

	LED_BLUE_TOGGLE;

	switch (vIndex) {

// End first process

		default:
		case 0: {
			vStackCurFs = vKern_stackProc[core];
			vKern_stackProc[core] = vStackCurP0;
			vIndex = 1;
			break;
		}

// End process P0

		case 1: {
			vStackCurP0 = vKern_stackProc[core];
			vKern_stackProc[core] = vStackCurP1;
			vIndex = 2;
			break;
		}

// End process P1

		case 2: {
			vStackCurP1 = vKern_stackProc[core];
			vKern_stackProc[core] = vStackCurP0;
			vIndex = 1;
			break;
		}
	}

	#if (defined(VERBOSE_S))
	debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&vKern_stackProc[core]);
	cmns_send(KURT0, "stack  0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
	#endif

	newStack = (volatile uint64_t *)vKern_stackProc[core];
	plic->targets.target[core].priority_threshold = (uint32_t)(newStack[0] & 0x00000000000000FF);

// Prepare a1 with the pointer on the new stack (see macro KERN_NEW_FRAME)

	__asm volatile ("add	a1,x0,%0" : : "r" (newStack) :);																									\

	KERN_NEW_FRAME;
	KERN_RETURN;
}
#endif
