/*
; tests.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test ROM routine collection.
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

/*!
 * \file
 * \ingroup Grove_K210_RV64IMAFDC
 * \brief Test ROM for K210.
 *
 *		tests_00: Test blink the Red 1 & Green 1 the Red 2 & Green 2 Leds
 *		tests_01: Test of the TIM0_0 interruption
 *		tests_02: Test sending data via the cnms manager
 *		tests_03: Test reading & sending data via the cnms manager
 *		tests_04: Test of the USART2 Rx interruption
 *		tests_05: Test of the USART2 Tx interruption
 *		tests_06: Test of an ECALL call
 *		tests_07: Test of the preemption interruption
 *		tests_08: Test of a preliminary pico kernel (with messages ECALL)
 *		tests_09: Test of a preliminary pico kernel (with messages ECALL) and with the macro_core
 *		tests_10: Test of a TIM call
 *		tests_11: Test of a preliminary pico kernel (with TIM_0) and with the macro_core
 *		tests_12: Test of the TIM0_0 TIM0_2 interruptions
 *		tests_13: Test of the TIM0_0 TIM0_1 interruptions
 *		tests_14: Test of the TIM1_0 TIM1_2 interruptions
 *		tests_15: Test of the TIM1_0 TIM1_1 interruptions
 *		tests_16: Test of the TIM2_0 TIM2_2 interruptions
 *		tests_17: Test of the TIM2_0 TIM2_1 interruptions
 *		tests_18: Test of the TIM0_0 used to generate a 64-bit 1-us counter
 *		tests_19: Test of the TIM0_0 in single shot (timeout tasks)
 *		tests_10: Test of the INTERRUPTION_OFF / INTERRUPTION_RESTORE
 *
 */

#include	"tests.h"

/*
 * \brief main
 *
 * - Execute the selected test
 *
 */
int		main(int argc, const char_t *argv[]) {

	gpiohs->output_en.u32[0] |= (1u<<BLED_0) | (1u<<BLED_1) | (1u<<BLED_2) | (1u<<BLED_3);

// Launch the test

#if (defined(TEST_00_S))
void	test_00(void);
	test_00();
#endif

#if (defined(TEST_01_S))
void	test_01(void);
	test_01();
#endif

#if (defined(TEST_02_S))
void	test_02(void);
	test_02();
#endif

#if (defined(TEST_03_S))
void	test_03(void);
	test_03();
#endif

#if (defined(TEST_04_S))
void	test_04(void);
	test_04();
#endif

#if (defined(TEST_05_S))
void	test_05(void);
	test_05();
#endif

#if (defined(TEST_06_S))
void	test_06(void);
	test_06();
#endif

#if (defined(TEST_07_S))
void	test_07(void);
	test_07();
#endif

#if (defined(TEST_08_S))
void	test_08(void);
	test_08();
#endif

#if (defined(TEST_09_S))
void	test_09(void);
	test_09();
#endif

#if (defined(TEST_10_S))
void	test_10(void);
	test_10();
#endif

#if (defined(TEST_11_S))
void	test_11(void);
	test_11();
#endif

#if (defined(TEST_12_S))
void	test_12(void);
	test_12();
#endif

#if (defined(TEST_13_S))
void	test_13(void);
	test_13();
#endif

#if (defined(TEST_14_S))
void	test_14(void);
	test_14();
#endif

#if (defined(TEST_15_S))
void	test_15(void);
	test_15();
#endif

#if (defined(TEST_16_S))
void	test_16(void);
	test_16();
#endif

#if (defined(TEST_17_S))
void	test_17(void);
	test_17();
#endif

#if (defined(TEST_18_S))
void	test_18(void);
	test_18();
#endif

#if (defined(TEST_19_S))
void	test_19(void);
	test_19();
#endif

#if (defined(TEST_20_S))
void	test_20(void);
	test_20();
#endif

}

#include	"tests_00.c"
#include	"tests_01.c"
#include	"tests_02.c"
#include	"tests_03.c"
#include	"tests_04.c"
#include	"tests_05.c"
#include	"tests_06.c"
#include	"tests_07.c"
#include	"tests_08.c"
#include	"tests_09.c"
#include	"tests_10.c"
#include	"tests_11.c"
#include	"tests_12.c"
#include	"tests_13.c"
#include	"tests_14.c"
#include	"tests_15.c"
#include	"tests_16.c"
#include	"tests_17.c"
#include	"tests_18.c"
#include	"tests_19.c"
#include	"tests_20.c"
