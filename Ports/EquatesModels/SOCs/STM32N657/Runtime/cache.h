/*
; cache.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-06-25
; Modifs:
;
; Project:	uKOS-X
; Goal:		Cortex N657 L1 cache management.
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

/*
 * \brief cache_D_Enable
 *
 * - Enable the data cache
 *
 */
extern	void	cache_D_Enable(void);

/*
 * \brief cache_D_Disable
 *
 * - Disable the data cache
 *
 */
extern	void	cache_D_Disable(void);

/*
 * \brief cache_D_Invalidate
 *
 * - Invalidate the data cache
 *
 */
extern	void	cache_D_Invalidate(void);

/*
 * \brief cache_D_Invalidate_Add
 *
 * - Invalidate the data cache by address
 *
 */
extern	void	cache_D_Invalidate_Add(const void *address, int32_t size);

/*
 * \brief cache_D_Clean
 *
 * - Clean the data cache
 *
 */
extern	void	cache_D_Clean(void);

/*
 * \brief cache_D_Clean_Add
 *
 * - Clean the data cache by address
 *
 */
extern	void	cache_D_Clean_Add(const void *address, int32_t size);

/*
 * \brief cache_I_Enable
 *
 * - Enable the instruction cache
 *
 */
extern	void	cache_I_Enable(void);

/*
 * \brief cache_I_Disable
 *
 * - Disable the instruction cache
 *
 */
extern	void	cache_I_Disable(void);

/*
 * \brief cache_I_Invalidate
 *
 * - Invalidate the instruction cache
 *
 */
extern	void	cache_I_Invalidate(void);

/*
 * \brief cache_I_Invalidate_Add
 *
 * - Invalidate the instruction cache by address
 *
 */
extern	void	cache_I_Invalidate_Add(const void *address, int32_t size);
