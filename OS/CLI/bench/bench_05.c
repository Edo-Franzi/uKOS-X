/*
; bench_05.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Bench 05: 	Compute a simple loop. 1000000 iterations.
;
;			Target used: Nucleo_H743 @ 480-MHz
;			Target used: Nucleo_N657 @ 600-MHz
;			Target used: MAiXDUiNO_K210 @ 400-MHz
;			Target used: Discovery_U5G9 @ 160-MHz
;
;			Bench results in [us]:
;
;										_loop
;			Nucleo_H743 @ 480-MHz		10400
;			Nucleo_N657 @ 600-MHz		13240
;			MAiXDUiNO_K210 @ 400-MHz	-
;			Discovery_U5G9 @ 160-MHz	-
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

#include	"uKOS.h"

// CLI tool specific
// =================

#define	KNB_TESTS	1000000u

/*
 * \brief bench_05
 *
 * - loop
 *
 */
#if (!defined(Nucleo_H743_S) && !defined(Nucleo_N657_S))

bool	bench_05(void) {

	(void)dprintf(KSYST, "Bench 05: not available for this target\n");
	return true;
}

#else
static	void	 local_loop(uint32_t nb);

bool	bench_05(void) {

	(void)dprintf(KSYST, "Bench 05: For scope tests!\n");

	kern_suspendProcess(1000u);

	INTERRUPTION_OFF_HARD;
	while (true) {

		ANALYSER_TOGGLE;
		local_loop(KNB_TESTS);
	}

	return (true);
}

// Local routines
// ==============

/*
 * \brief local_loop
 *
 * - Execute the nop
 *
 */
static	void local_loop(uint32_t nb) {
	volatile	uint32_t	i;

	for (i = 0u; i < nb; i++) {
		NOP;
	}
}

#endif
