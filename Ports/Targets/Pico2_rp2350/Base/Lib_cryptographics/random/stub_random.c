/*
; stub_random.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the "random" manager module.
;
;   (c) 2025-20xx, Edo. Franzi
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

// Prototypes

void	model_random_soft_init(void);
void	model_random_soft_read(uint32_t *number);
void	model_random_hard_init(void);
void	model_random_hard_read(uint32_t *number);

/*
 * \brief stub_random_init
 *
 * - Initialise some specific CPU parts
 *
 */
void	stub_random_init(void) {

	model_random_soft_init();
	model_random_hard_init();
}

/*
 * \brief stub_rand_read
 *
 * - Return the random number
 *
 */
int32_t	stub_rand_read(randomGenerator_t generator, uint32_t *number) {

	if (generator == KRANDOM_SOFT) { model_random_soft_read(number); return (KERR_RANDOM_NOERR); }
	if (generator == KRANDOM_HARD) { model_random_hard_read(number); return (KERR_RANDOM_NOERR); }
	return (KERR_RANDOM_GEERR);
}

// Local routines
// ==============

#include	"model_random_soft.c_inc"
#include	"model_random_hard.c_inc"
