/*
; tests.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test ROM routine collection.
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

/*!
 * \file
 * \ingroup Pico2_rp2350_RV32IFD
 * \brief Test ROM for Pico2_rp2350.
 *
 *		tests_00: Test blink the RED, GREEN, YELLOW and system Leds
 *		tests_01: Test sending data via the cnms manager
 *		tests_02: Test reading & sending data via the cnms manager
 *		tests_03: Test of the UART0 Rx interruption
 *		tests_04: Test of the UART0 Tx interruption
 *		tests_05: Test of the TIM0 Alarme 0 & 1 interruption
 *		tests_06: Test of a preliminary pico kernel (with messages swi)
 *		tests_07: Test of the UART0 Tx interruption
 *		tests_08: Test of the boot of the core 1
 *		tests_09: Test of the TIM0 Alarme 0 (core 0) & 1 (core 1) interruption
 *		tests_10: Test of the spin lock
 *		tests_11: Test of the door bell
 *
 */

#include	"tests.h"

			void	(*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
			void	(*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
			bool	vExce_isException[KNB_CORES] = MCSET(false);

#if (defined(TEST_00_S))
	void	test_00(void);
	#ifndef USING_CMAKE
		#include	"tests_00.c"
	#endif
	#define	test_current()	test_00()
#endif

#if (defined(TEST_01_S))
	void	test_01(void);
	#ifndef USING_CMAKE
		#include	"tests_01.c"
	#endif
	#define	test_current()	test_01()
#endif

#if (defined(TEST_02_S))
	void	test_02(void);
	#ifndef USING_CMAKE
		#include	"tests_02.c"
	#endif
	#define	test_current()	test_02()
#endif

#if (defined(TEST_03_S))
	void	test_03(void);
	#ifndef USING_CMAKE
		#include	"tests_03.c"
	#endif
	#define	test_current()	test_03()
#endif

#if (defined(TEST_04_S))
	void	test_04(void);
	#ifndef USING_CMAKE
		#include	"tests_04.c"
	#endif
	#define	test_current()	test_04()
#endif

#if (defined(TEST_05_S))
	void	test_05(void);
	#ifndef USING_CMAKE
		#include	"tests_05.c"
	#endif
	#define	test_current()	test_05()
#endif

#if (defined(TEST_06_S))
	void	test_06(void);
	#ifndef USING_CMAKE
		#include	"tests_06.c"
	#endif
	#define	test_current()	test_06()
#endif

#if (defined(TEST_07_S))
	void	test_07(void);
	#ifndef USING_CMAKE
		#include	"tests_07.c"
	#endif
	#define	test_current()	test_07()
#endif

#if (defined(TEST_08_S))
	void	test_08(void);
	#ifndef USING_CMAKE
		#include	"tests_08.c"
	#endif
	#define	test_current()	test_08()
#endif

#if (defined(TEST_09_S))
	void	test_09(void);
	#ifndef USING_CMAKE
		#include	"tests_09.c"
	#endif
	#define	test_current()	test_09()
#endif

#if (defined(TEST_10_S))
	void	test_10(void);
	#ifndef USING_CMAKE
		#include	"tests_10.c"
	#endif
	#define	test_current()	test_10()
#endif

#if (defined(TEST_11_S))
	void	test_11(void);
	#ifndef USING_CMAKE
		#include	"tests_11.c"
	#endif
	#define	test_current()	test_11()
#endif

/*
 * \brief main
 *
 * - Execute the selected test
 *
 */
int		main(int argc, const char_t *argv[]) {

// Launch the test

	test_current();

}

