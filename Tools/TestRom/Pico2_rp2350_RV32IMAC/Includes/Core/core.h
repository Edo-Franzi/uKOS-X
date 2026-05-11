/*
; core.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Collection of core routines
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
static	inline	uint32_t	core_getCSR(uint32_t reg) {
	uint32_t	value;

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
static	inline	void	core_putCSR(uint32_t reg, uint32_t value) {

	if (__builtin_constant_p(value) && ((uint32_t)(value) < 32U)) {
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
static	inline	void	core_setBitCSR(uint32_t reg, uint32_t mask) {

	if (__builtin_constant_p(mask) && ((uint32_t)(mask) < 32U)) {
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
static	inline	void	core_clrBitCSR(uint32_t reg, uint32_t mask) {

	if (__builtin_constant_p(mask) && ((uint32_t)(mask) < 32U)) {
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

/*
 * \brief core_enableExternalIRQ
 *
 * - Enable a Hazard3 external interrupt via the MEIEA CSR array
 *
 * \param[in]	irqNum		The IRQ number to enable
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static	inline	void	core_enableExternalIRQ(uint32_t irqNum) {
	uint32_t	index = irqNum / 16u;
	uint32_t	bit   = 1u<<(irqNum % 16u);

// Write index in low bits, data in high 16 bits; csrs does atomic OR

	__asm volatile ("csrs 0xBE0, %0" :: "r" (index | (bit<<16)));
}

/*
 * \brief core_disableExternalIRQ
 *
 * - Disable a Hazard3 external interrupt via the MEIEA CSR array
 *
 * \param[in]	irqNum		The IRQ number to disable
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static	inline	void	core_disableExternalIRQ(uint32_t irqNum) {
	uint32_t	index = irqNum / 16u;
	uint32_t	bit   = 1u<<(irqNum % 16u);

// csrc does atomic AND-NOT

	__asm volatile ("csrc 0xBE0, %0" :: "r" (index | (bit<<16)));
}

/*
 * \brief core_setPendingExternalIRQ
 *
 * - Force-pend a Hazard3 external interrupt via the MEIFA CSR array
 *
 * \param[in]	irqNum		The IRQ number to force-pend
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static	inline	void	core_setPendingExternalIRQ(uint32_t irqNum) {
	uint32_t	index = irqNum / 16u;
	uint32_t	bit   = 1u<<(irqNum % 16u);

	__asm volatile ("csrs 0xBE2, %0" :: "r" (index | (bit<<16)));
}

/*
 * \brief core_clearPendingExternalIRQ
 *
 * - Clear a force-pended Hazard3 external interrupt via the MEIFA CSR array
 *
 * \param[in]	irqNum		The IRQ number to clear
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static	inline	void	core_clearPendingExternalIRQ(uint32_t irqNum) {
	uint32_t	index = irqNum / 16u;
	uint32_t	bit   = 1u<<(irqNum % 16u);

	__asm volatile ("csrc 0xBE2, %0" :: "r" (index | (bit<<16)));
}

/*
 * \brief core_setExternalIRQPriority
 *
 * - Set the priority of a Hazard3 external interrupt via the MEIPRA CSR array
 * - MEIPRA packs 4 IRQ priorities (4 bits each) per 16-bit window
 * - Priority 0 = never taken, 1..15 = valid (1 = lowest)
 *
 * \param[in]	irqNum		The IRQ number
 * \param[in]	priority	The priority (0-15)
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static	inline	void	core_setExternalIRQPriority(uint32_t irqNum, uint32_t priority) {
	uint32_t	index = irqNum / 4u;
	uint32_t	shift = (irqNum % 4u) * 4u;

// csrs ORs the priority bits into the selected window

	__asm volatile ("csrs 0xBE3, %0" :: "r" (index | ((priority & 0xFu)<<(shift + 16u))));
}

/*
 * \brief core_getNextExternalIRQ
 *
 * - Read the Hazard3 MEINEXT CSR to get the next pending external IRQ
 *
 * \return		meinext		The MEINEXT register value
 *
 */
[[gnu::always_inline]]
static	inline	uint32_t	core_getNextExternalIRQ(void) {
	uint32_t	meinext;

	__asm volatile ("csrr %0, 0xBE4" : "=r" (meinext));
	return (meinext);
}
