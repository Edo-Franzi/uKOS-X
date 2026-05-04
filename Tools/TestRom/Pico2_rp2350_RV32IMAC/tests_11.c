/*
; tests_11.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the door bell
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

// Prototypes

		void	local_doorBell_IRQHandler(void);
extern	void	init_launchCore_1(void (*entry)(void));

extern	uint8_t		linker_topStackFirst_C1[];

// CORE 1
// ======

/*
 * \brief local_CodeCore_1
 *
 * - Blink the GREEN Led
 *
 */
static	void	local_codeCore_1(void) {

	__asm volatile ("la	sp,linker_topStackFirst_C1");
	__asm volatile (
		".option push            \n"
		".option norelax         \n"
		"la     gp,__global_pointer$  \n"
		".option pop             \n"
	);

// Initialise the door bell interruption
// NOTE: Hazard3 MEIPRA defaults to priority 0 for SIO_IRQ_BELL,
//       which means "never taken". Explicit priority > 0 is required.

	INTERRUPT_VECTOR(SIO_IRQ_BELL_C1_IRQn, local_doorBell_IRQHandler);
	core_setExternalIRQPriority(SIO_IRQ_BELL_C1_IRQn, 1u);
	core_enableExternalIRQ(SIO_IRQ_BELL_C1_IRQn);
	core_setBitCSR(RV_CSR_MIE, MIE_MEIE);

// Waiting for the door bell interruption

	INTERRUPTION_ON_HARD;

	while (true) {
		cmns_wait(100000);
		LED_SYSTEM_TOGGLE;
	}
}

/*
 * \brief local_doorBell_IRQHandler
 *
 * - Blink the YELLOW & GREEN Leds
 *
 */
void	local_doorBell_IRQHandler(void) {

// Acknowledge the door bell interruption

	if ((REG(SIO)->DOORBELL_IN_CLR & 0x1u) != 0u) { REG(SIO)->DOORBELL_IN_CLR = 0x1u; LED_YELLOW_TOGGLE; }
	if ((REG(SIO)->DOORBELL_IN_CLR & 0x2u) != 0u) { REG(SIO)->DOORBELL_IN_CLR = 0x2u; LED_GREEN_TOGGLE;	 }
}

// CORE 0
// ======

/*
 * \brief test_11
 *
 * - Test of the door bell
 *
 */
void	test_11(void) {
	uint32_t	cpt = 0;

	init_launchCore_1(local_codeCore_1);

// Generate a door bell on the core 1

	INTERRUPTION_ON_HARD;

	while (true) {
		cpt++;
		cmns_wait(1000000);
		LED_RED_TOGGLE;
		REG(SIO)->DOORBELL_OUT_SET = 0x1u;
		if ((cpt % 10u) == 0u) { REG(SIO)->DOORBELL_OUT_SET = 0x2u; }
	}
}
