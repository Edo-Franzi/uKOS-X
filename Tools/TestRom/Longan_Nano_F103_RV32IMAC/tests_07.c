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
; Goal:		Test of a double EXTI call.
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
static		char_t		vString[20];
			uint32_t	vKern_message_0, vKern_message_1;
			uint32_t	vKern_stackProcess_0, vKern_stackProcess_1;

#define	BKERNMESSAGES_0		0
#define	BKERNMESSAGES_1		1

#define	MESSAGE_0(msg)	__asm volatile ("												\n \
						add			t0,x0,%0											\n \
						addi		sp,sp,-8											\n \
						sw			t0,0(sp)											\n \
						sw			t0,4(sp)"											   \
						:																   \
						: "r" (msg)														   \
						: "t0"															   \
						);																   \
						EXTI->SWIEV |=(1u<<BKERNMESSAGES_0);							   \
						while ((EXTI->SWIEV & (1u<<BKERNMESSAGES_0)) != 0);				   \
						__asm volatile ("												\n \
						addi		sp,sp,8"											   \
						);

#define	MESSAGE_1(msg)	__asm volatile ("												\n \
						add			t0,x0,%0											\n \
						addi		sp,sp,-8											\n \
						sw			t0,0(sp)											\n \
						sw			t0,4(sp)"											   \
						:																   \
						: "r" (msg)														   \
						: "t0"															   \
						);																   \
						EXTI->SWIEV |= (1u<<BKERNMESSAGES_1);							   \
						while ((EXTI->SWIEV & (1u<<BKERNMESSAGES_1)) != 0);				   \
						__asm volatile ("												\n \
						addi		sp,sp,8"											   \
						);

// Prototypes

static	void	local_process(uint32_t message);

/*
 * \brief test_07
 *
 * - Test of a double EXTI call
 *
 */
void	test_07(void) {
	volatile	uint32_t	message_0 = 0, message_1 = 0;

	EXTI->INTEN = 0;
	EXTI->SWIEV = 0;
	EXTI->PD    = 0x7FF;
	EXTI->INTEN = (1u<<BKERNMESSAGES_0) | (1u<<BKERNMESSAGES_1);

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

	ECLIC->CLICINT[EXTI1_IRQn].CTL  = KINT_LEVEL_ALL;
	ECLIC->CLICINT[EXTI1_IRQn].IP   = 0;
	ECLIC->CLICINT[EXTI1_IRQn].IE   = 1;
	ECLIC->CLICINT[EXTI1_IRQn].ATTR = ECLIC_INT_ATTR_SHV | ECLIC_INT_ATTR_TRIG_EDGE_RISING;

	ECLIC->MTH = KINT_IMASK_ALL;

	INTERRUPTION_ON_HARD;

	cmns_init();

	while (true) {
		cmns_wait(1000000);
		LED_RED_TOGGLE;

		MESSAGE_0(message_0);
		MESSAGE_1(message_1);
		message_0++, message_1--;
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
	: "=r" (vKern_stackProcess_0)					   \
	: "i" (&ECLIC->MTH)								   \
	:												   \
	);

// Recover the message

	__asm volatile ("								\n \
	lw			t0,144(sp)							\n \
	sw			t0,%0"								   \
	:												   \
	: "m" (vKern_message_0)							   \
	:												   \
	);

	EXTI->SWIEV &= (uint32_t)~(1u<<BKERNMESSAGES_0);
	EXTI->PD     =			  (1u<<BKERNMESSAGES_0);
	local_process(vKern_message_0);

	__asm volatile ("								\n \
	add			sp,x0,%0							\n \
	lw			x1,4(sp)							\n \
	lw			x3,8(sp)							\n \
	lw			x4,12(sp)							\n \
	lw			x6,20(sp)							\n \
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
	: "r" (vKern_stackProcess_0), "i" (&ECLIC->MTH)	   \
	:												   \
	);
}

/*
 * \brief EXTI1_IRQHandler
 *
 * - Change the context f(message)
 *
 */
[[gnu::naked, gnu::optimize("Os")]]
void	EXTI1_IRQHandler(void) {

	__asm volatile ("								\n \
	addi		sp,sp,-136							\n \
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
	: "=r" (vKern_stackProcess_1)					   \
	: "i" (&ECLIC->MTH)								   \
	:												   \
	);

// Recover the message

	__asm volatile ("								\n \
	lw			t0,140(sp)							\n \
	sw			t0,%0"								   \
	:												   \
	: "m" (vKern_message_1)							   \
	: "t0"											   \
	);

	EXTI->SWIEV &= (uint32_t)~(1u<<BKERNMESSAGES_1);
	EXTI->PD     =			  (1u<<BKERNMESSAGES_1);
	local_process(vKern_message_1);

	__asm volatile ("								\n \
	add			sp,x0,%0							\n \
	lw			x1,4(sp)							\n \
	lw			x3,8(sp)							\n \
	lw			x4,12(sp)							\n \
	lw			x6,20(sp)							\n \
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
	addi		sp,sp,136							\n \
	mret"											   \
	:												   \
	: "r" (vKern_stackProcess_1), "i" (&ECLIC->MTH)	   \
	:												   \
	);
}

/*
 * \brief local_process
 *
 * - Blink the YELLOW Led
 *
 */
[[gnu::noinline]]
static	void	local_process(uint32_t message) {

	LED_BLUE_TOGGLE;

	debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&message);
	cmns_send(KURT0, "Message 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
}
#endif
