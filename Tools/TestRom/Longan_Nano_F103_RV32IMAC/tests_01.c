/*
; tests_01.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the RTC interruption.
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

#if (defined(TEST_01_S))

// Prototypes

static	void	local_RTC_IRQHandler(void);

/*
 * \brief test_01
 *
 * - Test of the RTC interruption
 *
 */
void	test_01(void) {

	RCU->RSTSCK |= RCU_RSTSCK_IRC40KEN;
	RCU->APB1EN |= RCU_APB1EN_BKPIEN;
	RCU->APB1EN |= RCU_APB1EN_PMUEN;

	PMU->CTL	|= PMU_CTL_BKPWEN;

// Clock source XTAL 32768-Hz

	RCU->BDCTL   = RCU->BDCTL & ~RCU_BDCTL_RTCSRC;
	RCU->BDCTL  |= (1 * RCU_BDCTL_RTCSRC_0);
	RCU->BDCTL  |= RCU_BDCTL_RTCEN;

// Initialise the RTC to generate an interruption every 1000-ms

	RTC->CTL &= ~RTC_CTL_RSYNF;
	while ((RTC->CTL & RTC_CTL_RSYNF) == 0) { ; }

	while ((RTC->CTL & RTC_CTL_LWOFF) == 0) { ; }

	RTC->CTL   |= RTC_CTL_CMF;				while ((RTC->CTL & RTC_CTL_LWOFF) == 0);
	RTC->CTL   &= ~RTC_CTL_SCIF;			while ((RTC->CTL & RTC_CTL_LWOFF) == 0);
	RTC->INTEN |= RTC_INTEN_SCIE;			while ((RTC->CTL & RTC_CTL_LWOFF) == 0);
	RTC->PSCH   = ((32768 - 1)>>16);		while ((RTC->CTL & RTC_CTL_LWOFF) == 0);
	RTC->PSCL   = ((32768 - 1) & 0xFFFF);	while ((RTC->CTL & RTC_CTL_LWOFF) == 0);
	RTC->CTL   &= ~RTC_CTL_CMF;				while ((RTC->CTL & RTC_CTL_LWOFF) == 0);

	INTERRUPT_VECTOR(RTC_C0_IRQn, local_RTC_IRQHandler);

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

	ECLIC->CLICINT[RTC_IRQn].CTL  = KINT_LEVEL_ALL;
	ECLIC->CLICINT[RTC_IRQn].IP   = 0;
	ECLIC->CLICINT[RTC_IRQn].IE   = 1;
	ECLIC->CLICINT[RTC_IRQn].ATTR = ECLIC_INT_ATTR_SHV | ECLIC_INT_ATTR_TRIG_EDGE_RISING;
	ECLIC->MTH = KINT_IMASK_ALL;

	INTERRUPTION_ON_HARD;

// Waiting for the TIM2 interruption

	while (true) {
		__asm volatile ("wfi");
	}
}

/*
 * \brief local_RTC_IRQHandler
 *
 * - Blink the GREEN & BLUE Leds
 *
 */
static	void	local_RTC_IRQHandler(void) {
	static	uint8_t		state = 0;

	UNUSED(number);

	RTC->CTL &= ~RTC_CTL_SCIF;

	switch (state) {
		default:
		case 0: { state = 0; LED_GREEN_ON;	break; }
		case 1: {			 LED_GREEN_OFF;	break; }
		case 2: {			 LED_BLUE_ON;	break; }
		case 3: {			 LED_BLUE_OFF;	break; }
		case 4: {			 LED_RED_ON;	break; }
		case 5: {			 LED_RED_OFF;	break; }
	}
	state++;
}
#endif
