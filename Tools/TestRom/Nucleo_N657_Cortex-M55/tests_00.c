/*
; tests_00.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the clocks via MCO1-2.
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

#if (defined(TEST_00_S))
#define BLINK_PAUSE	1000000

/*
 * \brief test_00
 *
 * - Test of the clocks via MCO1-2
 *
 */
void	test_00(void) {
	volatile	uint32_t	value;

	REG(RCC)->MISCENR |= RCC_MISCENR_MCO2EN;
	STRONG_BARRIER;

// PA08, MCO1 (not usable)
// PC09, MCO2 (maybe blocked by OTP124)

	value = REG(RCC)->CCIPR5 & ((0xFFF8u<<19) | (0x1u<<11) | (0x1u<<3));

// MCO2
//
// n = 0, hsi_div_ck	(OK, ~64-MHz !!!)
// n = 1, lse_ck		(KO)
// n = 2, msi_ck		(KO)
// n = 3, lsi_ck		(OK, ~32-KHz !!!)
// n = 4, hse_ck		(OK, ~48-MHz !!!)
// n = 5a, ic15_ck		(OK, ~312-MHz !!!) = pll1 / 2 -> pll1 = 624-MHz
// n = 5b, ic15_ck		(OK, ~384-MHz !!!) = pll2 / 2 -> pll2 = 768-MHz
// n = 6, ic20_ck		(OK, ~135-MHz !!!) = pll3 / 3 -> pll3 = 405-MHz
// n = 7, sysb_ck		(OK, ~384-MHz !!!) = pll4

#define	n	7

	value |= (n		   * RCC_CCIPR5_MCO2SEL_0)		//
		   | ((10 - 1) * RCC_CCIPR5_MCO2PRE_0);		// Clock / 10
	REG(RCC)->CCIPR5 = value;						//

	while (true) {
		LED_GREEN_TOGGLE;
		ANALYSER_TOGGLE;
		cmns_wait(BLINK_PAUSE);
	}
}
#endif
