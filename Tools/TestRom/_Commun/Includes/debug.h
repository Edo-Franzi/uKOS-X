/*
; debug.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Some debug tools.
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

#define	TIC_EXCEPTION_TIME
#define	TAC_EXCEPTION_TIME(core)
#define	KERNDIAG(a, b)

/*
 * \brief Convert a int32_t binary value to a hexadecimal ASCII buffer
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    256
 *
 * int32_t    value = -233;
 * char_t     ascii[KSIZE], *wkAscii;
 *
 *   debug_cnvtValInt32ToHexAscii(ascii, &value);
 * \endcode
 *
 * - int32_t input value:	ASCII output buffer:
 * - (.32) -0x92A			(ASCII) -0x92A
 *
 * \param[out]	*ascii		Ptr on the ASCII buffer
 * \param[in]	*binary		Ptr on the binary value
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	debug_cnvtValInt32ToHexAscii(char_t *ascii, const int32_t *binary);

/*
 * \brief Convert a int32_t binary value to a decimal ASCII buffer
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    256
 *
 * int32_t    value = -233;
 * char_t     ascii[KSIZE], *wkAscii;
 *
 *    debug_cnvtValInt32ToDecAscii(ascii, &value);
 * \endcode
 *
 * - int32_t input value:	ASCII output buffer:
 * - (.32) -0x929			(ASCII) -2345
 *
 * \param[out]	*ascii		Ptr on the ASCII buffer
 * \param[in]	*binary		Ptr on the binary value
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	debug_cnvtValInt32ToDecAscii(char_t *ascii, const int32_t *binary);

/*
 * \brief Print a 32-bit value (decimal)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    value = -233;
 *
 *   debug_printValueD(value);
 * \endcode
 *
 * \param[in]	*binary		Ptr on the binary value
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	debug_printValueD(volatile int32_t binary);

/*
 * \brief Print a 32-bit value (hexadecimal)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    value = -233;
 *
 *   debug_printValueH(value);
 * \endcode
 *
 * \param[in]	*binary		Ptr on the binary value
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	debug_printValueH(volatile int32_t binary);
