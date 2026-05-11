/*
; lib_cryptographics.
; ===================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		lib_cryptographics system call interface module.
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

/*!
 * \defgroup Lib_cryptographics Library for the crypto tools
 *
 * \brief Cryptographic manager system calls
 *
 * The Lib_cryptographics library provides a manager devoted to randomness.
 * Its role is to ensure that numbers may be created without pattern or bias.
 *
 * The random manager may rely on hardware entropy or on software routines.
 * In both cases, it delivers values that resist prediction and imitation.
 * Randomness is vital for security. Keys, tokens, and nonces all depend on
 * numbers that cannot be guessed. Without them, encryption would be fragile.
 * Beyond security, randomness brings life to simulations, games, and models.
 * It allows fair trials, varied outcomes, and realistic scientific results.
 * By offering both speed and reliability, the random manager turns chance
 * into a controlled resource. It shows that uncertainty can be engineered.
 *
 * Together these managers show that discipline and design can live side by side.
 * Lib_cryptographics is both a toolbox for developers and a lesson in clarity.
 *
 * @{
 */

// IWYU pragma: begin_exports

#if (defined(CONFIG_MAN_RANDOM_S))
#include	"random/random.h"
#endif

// IWYU pragma: end_exports

/**!@}*/
