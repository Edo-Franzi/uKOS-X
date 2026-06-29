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
; Goal:		Test of a TIM call.
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
#define	KTTIMESAMPLING	100000000						// 100-ms -> 100'000'000-ns

static		char_t		vString[20];
volatile	uintptr_t	vKern_stackProc[KNB_CORES];		// Stacks

// Prototypes

static	void	local_kern(uint32_t core, uint64_t parameter);

/*
 * \brief test_10
 *
 * - Generate a TIM call
 *
 */
void	test_10(void) {
	float64_t	step;
	uint32_t	core, current;

	INTERRUPTION_SET;
	INTERRUPTION_ON_HARD;

	cmns_init();

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

	while (true) {
		cmns_wait(100000);
		LED_RED_1_TOGGLE;
	}
}

/*
 * \brief local_kern
 *
 * - Display some information
 *
 */
[[gnu::naked, gnu::optimize("Os")]]
void	local_kern(uint32_t core, uint64_t parameter) {

// Save the context
// Recover the message
// Restore a new context

	KERN_SAVE_FRAME;

	JUMP_FNCT(local_process);
}

/*
 * \brief local_process
 *
 * - Blink the Red 2 Led
 *
 */
[[gnu::noinline]]
void	local_process(uint32_t core, uint64_t parameter, uint64_t *threshold, volatile uintptr_t *stack) {
				uint32_t	msb, lsb;
	volatile	uint64_t	*newStack;

// Save the plic threshold on the current process stack
// Save the current process stack

	*threshold = (uint64_t)plic->targets.target[core].priority_threshold & 0x00000000000000FF;
	vKern_stackProc[core] = (uintptr_t)stack;

// Acknowledge the TIM0_0 interruption
// Acknowledge the PLIC claim complete

	timer0->channel[0].eoi;
	plic->targets.target[core].claim_complete = (uint32_t)parameter;

	LED_RED_2_TOGGLE;

	msb = (uint32_t)(core);
	(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)msb);

	cmns_send(KURT0, "Core        0x"); cmns_send(KURT0, vString);

	msb = (uint32_t)(*threshold);
	(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)msb);

	cmns_send(KURT0, "  Threshold 0x"); cmns_send(KURT0, vString);

	msb = (uint32_t)(parameter>>32);
	lsb = (uint32_t)(parameter);
	(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)msb);

	cmns_send(KURT0, "  number    0x"); cmns_send(KURT0, vString);
	(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)lsb);

	cmns_send(KURT0, vString); cmns_send(KURT0, "\n");

	newStack = (volatile uint64_t *)vKern_stackProc[core];
	plic->targets.target[core].priority_threshold = (uint32_t)(newStack[0] & 0x00000000000000FF);

// Prepare a1 with the pointer on the new stack (see macro KERN_NEW_FRAME)

	__asm volatile ("add	a1,x0,%0" : : "r" (newStack) :);																									\

	KERN_NEW_FRAME;
	KERN_RETURN;
}
#endif
