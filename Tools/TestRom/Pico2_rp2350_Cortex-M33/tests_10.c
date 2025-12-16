/*
; tests_10.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the spin lock.
;
;   (c) 2025-20xx, Edo. Franzi
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
#define	KTIM_ESAMPLING_0	((float64_t)(0.5))									// 2000-ms
#define KDELTA_TIME_0		((uint32_t)(KFREQUENCY_TIM * KTIM_ESAMPLING_0))		// Delta time

#define	KTIM_ESAMPLING_1	((float64_t)(0.1))									// 100-ms
#define KDELTA_TIME_1		((uint32_t)(KFREQUENCY_TIM * KTIM_ESAMPLING_1))		// Delta time

// Prototypes

		void	local_TIM0_0_IRQHandler(void);
		void	local_TIM0_1_IRQHandler(void);
extern	void	init_launchCore_1(void (*entry)(void));

extern	uint8_t		linker_topStackFirst_C1[];
extern	uint8_t		linker_topStackSystem_C1[];
static	spinlock_t	vTest_10 = SPIN_LOCK_INIT;

// CORE 1
// ======

/*
 * \brief local_CodeCore_1
 *
 * - Blink the GREEN Led
 *
 */
static	void	local_codeCore_1(void) {

	SET_MSP_STACK(linker_topStackSystem_C1);
	SET_THREAD_STACK(linker_topStackFirst_C1);

// Initialise the TIM0 Alarme 1 to generate an interruption every 100-ms

	REG(TIMER0)->INTE	= REG(TIMER0)->INTE | TIMER_INTE_ALARM_1;
	REG(TIMER0)->ALARM1 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_1;

	INTERRUPT_VECTOR(TIMER0_IRQ_1_C1_IRQn, local_TIM0_1_IRQHandler);
	NVIC_SetPriority(TIMER0_IRQ_1_C1_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(TIMER0_IRQ_1_C1_IRQn);

// Waiting for the TIM0 Alarme 1 interruption

	__asm volatile ("			\n \
	cpsie		i"				   \
	);

	while (true) {
		cmns_wait(100000);
		LED_SYSTEM_TOGGLE;
	}
}

/*
 * \brief local_TIM0_1_IRQHandler
 *
 * - Blink the YELLOW & GREEN Leds
 *
 */
void	local_TIM0_1_IRQHandler(void) {

	static	bool	spin = false;

	if (spin == false) { spin = true;  SPIN_LOCK(vTest_10);  }
	else			   { spin = false; SPIN_UNOCK(vTest_10); }

// Acknowledge the TIM0 Alarme 1 interruption

	if ((REG(TIMER0)->INTS & TIMER_INTS_ALARM_1) != 0) {
		REG(TIMER0)->INTR = TIMER_INTR_ALARM_1;

		REG(TIMER0)->ALARM1 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_1;
		LED_YELLOW_TOGGLE;
	}
}

// CORE 0
// ======

/*
 * \brief test_10
 *
 * - Test of the spin lock
 *
 */
void	test_10(void) {

// Reset of the device

	REG(RESETS)->RESET &= ~RESETS_RESET_TIMER0;
	while ((REG(RESETS)->RESET_DONE & RESETS_RESET_TIMER0) != RESETS_RESET_TIMER0) { ; }

	REG(TIMER0)->INTR = 0xFFFFFFFFu;

	init_launchCore_1(local_codeCore_1);

// Initialise the TIM0 Alarme 0 to generate an interruption every 500-ms

	REG(TIMER0)->INTE	= REG(TIMER0)->INTE | TIMER_INTE_ALARM_0;
	REG(TIMER0)->ALARM0 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_0;

	INTERRUPT_VECTOR(TIMER0_IRQ_0_C0_IRQn, local_TIM0_0_IRQHandler);
	NVIC_SetPriority(TIMER0_IRQ_0_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(TIMER0_IRQ_0_C0_IRQn);

// Waiting for the TIM0 Alarme 0 interruption

	__asm volatile ("			\n \
	cpsie		i"				   \
	);

	while (true) {
		cmns_wait(1000000);
		LED_RED_TOGGLE;
	}
}

/*
 * \brief local_TIM0_0_IRQHandler
 *
 * - Blink the GREEN Led
 *
 */
void	local_TIM0_0_IRQHandler(void) {
	static	bool	spin = false;

	if (spin == false) { spin = true;  SPIN_LOCK(vTest_10);   }
	else			   { spin = false; SPIN_UNLOCK(vTest_10); }

// Acknowledge the TIM0 Alarme 0 interruption

	if ((REG(TIMER0)->INTS & TIMER_INTS_ALARM_0) != 0) {
		REG(TIMER0)->INTR = TIMER_INTR_ALARM_0;

		REG(TIMER0)->ALARM0 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_0;
		LED_GREEN_TOGGLE;
	}
}
#endif
