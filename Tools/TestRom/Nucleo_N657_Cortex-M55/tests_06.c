/*
; tests_06.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of a SVC call.
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
extern		uintptr_t	*vVectors;
static		char_t		vString[20];
			uint32_t	vMessage;

#define	MESSAGE(msg)	__asm volatile ("										\n \
						ldr			r0,%0										\n \
						push		{r0}										\n \
						push		{r0}"										   \
						:														   \
						: "m" (msg)												   \
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

// Prototypes

static	void	local_process(uint32_t message);

/*
 * \brief test_06
 *
 * - Test of a SVC call
 *
 */
void	test_06(void) {
	volatile	uint32_t	message = 0;

	vVectors[15 + SVCall_IRQn] = (uintptr_t)SVCall_C0_IRQHandler;

	cmns_init();

	while (true) {
		cmns_wait(100000);
		LED_RED_TOGGLE;

		MESSAGE(message)
		message++;
	}
}

/*
 * \brief SVCall_IRQHandler
 *
 * - Change the context f(message)
 *
 */
#define	KSAVEREGISTERS	"r0", "r1", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11"

void	SVCall_C0_IRQHandler(void) __attribute__ ((naked)) __attribute__ ((optimize("Os")));
void	SVCall_C0_IRQHandler(void) {

// Recover the message

	__asm volatile ("							\n \
	cpsid		i								\n \
	tst			lr,#0x4							\n \
	ite 		eq								\n \
	mrseq		r0,msp							\n \
	mrsne		r0,psp							\n \
	add			r1,r0,#(32+4)					\n \
	tst			lr,#0x10						\n \
	it 			eq								\n \
	addeq		r1,r0,#(32+68+4)				\n \
	ldr			r1,[r1]							\n \
	str			r1,%0							\n \
	push 		{lr}"							   \
	:											   \
	: "m" (vMessage)							   \
	: KSAVEREGISTERS							   \
	);

		local_process(vMessage);

	__asm volatile ("							\n \
	pop			{lr}							\n \
	cpsie		i								\n \
	dmb											\n \
	dsb											\n \
	isb											\n \
	bx			lr"								   \
	);
}

/*
 * \brief local_process
 *
 * - Blink the YELLOW Led
 *
 */
static	void	__attribute__ ((noinline)) local_process(uint32_t message) {

	LED_BLUE_TOGGLE;

	debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&message);
	cmns_send(KURT0, "Message 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
}
#endif
