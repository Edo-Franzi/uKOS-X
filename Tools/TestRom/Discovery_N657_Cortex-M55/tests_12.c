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
; Goal:		Test of some RAM limits.
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

#if (defined(TEST_12_S))
#define	AXISRAM1_BASE	0x34000000u
#define	AXISRAM1_SIZE	(1u * 1024u * 1024u)
#define	AXISRAM2_BASE	0x34100000u
#define	AXISRAM2_SIZE	(1u * 1024u * 1024u)
#define	AXISRAM3_BASE	0x34200000u
#define	AXISRAM3_SIZE	(448u * 1024u)
#define	AXISRAM4_BASE	0x34270000u
#define	AXISRAM4_SIZE	(448u * 1024u)
#define	AXISRAM5_BASE	0x342E0000u
#define	AXISRAM5_SIZE	(448u * 1024u)
#define	AXISRAM6_BASE	0x34350000u
#define	AXISRAM6_SIZE	(448u * 1024u)
#define	CACHEAXI_BASE	0x343C0000u
#define	CACHEAXI_SIZE	(256u * 1024u)
#define	VENCRAM_BASE	0x34400000u
#define	VENCRAM_SIZE	(256u * 1024u)

#define	KRAM			AXISRAM6_BASE
#define	KRAM_SIZE		AXISRAM6_SIZE

/*
 * \brief test_12
 *
 * - Test of some RAM limits
 *
 */
void	test_12(void) {
				uint32_t	i, ramSize = KRAM_SIZE;
	volatile	uint8_t		*ram = (uint8_t *)(KRAM);

// Erase the SRAM

	for (i = 0; i < ramSize; i++) {
		ram[i] = 0u;
	}

// Write

	while (true) {
		for (i = 0; i < ramSize; i++) {
			ram[i] = (uint8_t)i;
		}
		LED_RED_TOGGLE;

// Read & test

		for (i = 0; i < ramSize; i++) {
			if (ram[i] != (uint8_t)i) {
				LED_RED_ON;
				LED_GREEN_OFF;
				while (true) { ; }
			}
		}
		LED_GREEN_TOGGLE;
	}
}
#endif
