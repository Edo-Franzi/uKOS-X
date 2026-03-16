/*
; tests.
; ======

; SPDX-License-Identifier: MIT

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
 * \ingroup Nucleo_H743_Cortex-M7
 * \brief Test ROM for Nucleo_H743.
 *
 *		tests_00: Test blink the RED & YELLOW Leds
 *
 */

#include	"tests.h"

			void	(*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
			void	(*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
volatile	bool	vPriv_insideException[KNB_CORES] = MCSET(false);

void	__attribute__ ((noreturn)) model_coreDump_displayExceptions(uintptr_t lr, uintptr_t *msp) {

	UNUSED(lr);
	UNUSED(msp);

	while (true) { ; }
}

void	__attribute__ ((noreturn)) model_coreDump_displayInterruptions(uintptr_t lr, uintptr_t *msp) {

	UNUSED(lr);
	UNUSED(msp);

	while (true) { ; }
}

/*
 * \brief main
 *
 * - Execute the selected test
 *
 */
int		main(int argc, const char_t *argv[]) {

// Launch the test

#if (defined(TEST_00_S))
void	test_00(void);
	test_00();
#endif

}

#include	"tests_00.c"
