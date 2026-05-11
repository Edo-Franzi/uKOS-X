/*
; tests_12.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the shared RAM.
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
#include	"linker.h"

#if (defined(TEST_12_S))
static	char_t		vString[20];

/*
 * \brief test_12
 *
 * - Test of the shared RAM
 *
 */
void	test_12(void) {
	uint32_t	*start, testNb = 0;
	uintptr_t	i, lenght;

	start  = (uint32_t *)linker_stShare;
	lenght = (uintptr_t)(((uintptr_t)linker_lnShare) / 4);

	cmns_init();

	while (true) {

// Fill the memory

		for (i = 0; i < lenght; i++) {
			start[i] = i;
		}

// Verify the memory

		for (i = 0; i < lenght; i++) {
			if (start[i] != i) {
				cmns_send(KURT0, "Memory problem");
				while (true) { ; }
			}
		}

		debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&testNb);
		cmns_send(KURT0, "Test number 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
		testNb++;
	}
}
#endif
