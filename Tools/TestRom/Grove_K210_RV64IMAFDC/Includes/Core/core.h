/*
; core.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Collection of core routines
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

#pragma	once

#include	"core_reg.h"

/*
 * \brief core_getCSR
 *
 * - Get a CSR register value
 *
 * \param[in]	reg			The CSR register
 * \return		value		The register value
 *
 */
[[gnu::always_inline]]
static	inline	uint64_t	core_getCSR(uint64_t reg) {
	uint64_t	value;

	__asm volatile (
	"csrr		%0,%1"
	: "=r" (value)
	: "i" (reg)
	);

	return (value);
}

/*
 * \brief core_putCSR
 *
 * - Put a value in a CSR register
 *
 * \param[in]	reg			The CSR register
 * \param[in]	value		The register value
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static	inline	void	core_putCSR(uint64_t reg, uint64_t value) {

	if (__builtin_constant_p(value) && ((uint64_t)(value) < 32u)) {
		__asm volatile (
		"csrw		%0,%1"
		:
		: "i" (reg), "i" (value)
		);
	}
	else {
		__asm volatile (
		"csrw		%0,%1"
		:
		: "i" (reg), "r" (value)
		);
	}
}

/*
 * \brief core_setBitCSR
 *
 * - Set a bit in a CSR register
 *
 * \param[in]	reg			The CSR register
 * \param[in]	mask		The mask value
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static	inline	void	core_setBitCSR(uint64_t reg, uint64_t mask) {

	if (__builtin_constant_p(mask) && ((uint64_t)(mask) < 32u)) {
		__asm volatile (
		"csrs		%0,%1"
		:
		: "i" (reg), "i" (mask)
		);
	}
	else {
		__asm volatile (
		"csrs		%0,%1"
		:
		: "i" (reg), "r" (mask)
		);
	}
}

/*
 * \brief core_clrBitCSR
 *
 * - Clear a bit in a CSR register
 *
 * \param[in]	reg			The CSR register
 * \param[in]	mask		The mask value
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static	inline	void	core_clrBitCSR(uint64_t reg, uint64_t mask) {

	if (__builtin_constant_p(mask) && ((uint64_t)(mask) < 32u)) {
		__asm volatile (
		"csrci		%0,%1"
		:
		: "i" (reg), "i" (mask)
		);
	}
	else {
		__asm volatile (
		"csrc		%0,%1"
		:
		: "i" (reg), "r" (mask)
		);
	}
}
