/*
; tests_XX.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the code size.
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

#define	TEST_STRUCTURE

#if (defined(TEST_XX_S))
typedef	struct objectParam	objectParam_t;

struct	objectParam {
	uint32_t	oP0;
	uint32_t	oP1;
	uint32_t	oP2;
	uint32_t	oP3;
};

// Prototypes

void	local_Test_a(objectParam_t *parameter);
void	local_Test_b(uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3);

/*
 * \brief test_XX
 *
 * - Test of the code size
 *
 */
void	test_XX(void) {

	#if (defined(TEST_STRUCTURE))
	objectParam_t	px;

	px.oP0	= 0;
	px.oP1	= 1;
	px.oP2	= 2;
	px.oP3	= 3;
	local_Test_a(&px);

	#else
	uint32_t	p0, p1, p2, p3;

	p0		= 0;
	p1		= 1;
	p2		= 2;
	p3		= 3;
	local_Test_b(p0, p1, p2, p3);
	#endif

}

#if (defined(TEST_STRUCTURE))
/*
 * \brief local_Test_a
 *
 * - Test
 *
 */
[[gnu::noinline]]
void	local_Test_a(objectParam_t *parameter) {
	volatile	uint32_t	*a = (volatile	uint32_t *)0x12345678;
	volatile	uint32_t	*b = (volatile	uint32_t *)0x23456789;
	volatile	uint32_t	*c = (volatile	uint32_t *)0x3456789A;
	volatile	uint32_t	*d = (volatile	uint32_t *)0x456789AB;

	*a = parameter->oP0;
	*b = parameter->oP1;
	*c = parameter->oP2;
	*d = parameter->oP3;
}

#else
/*
 * \brief local_Test_b
 *
 * - Test
 *
 */
[[gnu::noinline]]
void	local_Test_b(uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3) {
	volatile	uint32_t	*a = (volatile	uint32_t *)0x12345678;
	volatile	uint32_t	*b = (volatile	uint32_t *)0x23456789;
	volatile	uint32_t	*c = (volatile	uint32_t *)0x3456789A;
	volatile	uint32_t	*d = (volatile	uint32_t *)0x456789AB;

	*a = p0;
	*b = p1;
	*c = p2;
	*d = p3;
}
#endif

#endif
