/*
; atom.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Atomic primitives for multi-core.
;			These calls uses the low level gcc implementation and
;			are core independent
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

#include	<stdatomic.h>

// Structures for locks
// --------------------

typedef	atomic_flag	atomic_flag_t;

// Prototypes

[[gnu::always_inline]]
static	inline	void	atom_init(atomic_flag_t *lock);

[[gnu::always_inline]]
static	inline	void	atom_lock(atomic_flag_t *lock);

[[gnu::always_inline]]
static	inline	void	atom_unlock(atomic_flag_t *lock);

/*
 * \brief atom_init
 *
 * - Initialise the core shared memory
 *
 * \param[in]	*lock		Prt on the atomic flag
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static	inline	void	atom_init(atomic_flag_t *lock) {

	atomic_flag_clear(lock);
}

/*
 * \brief atom_lock
 *
 * - Lock the access
 *
 * \param[in]	*lock		Prt on the atomic flag
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static	inline	void	atom_lock(atomic_flag_t *lock) {

	while (atomic_flag_test_and_set(lock) == true) { ; }
}

/*
 * \brief atom_unlock
 *
 * - Unlock the access
 *
 * \param[in]	*lock		Prt on the atomic flag
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static	inline	void	atom_unlock(atomic_flag_t *lock) {

	atomic_flag_clear(lock);
}
