/*
; random.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		random manager.
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

#pragma	once

/*!
 * \addtogroup Lib_cryptographics
 */
/**@{*/

/*!
 * \defgroup random Random
 *
 * \brief Random
 *
 * Random management
 *
 * @{
 */

typedef	enum {
			KRANDOM_SOFT = 0u,									// Software generator
			KRANDOM_HARD										// Hardware generator
} randomGenerator_t;

#define	KRAND_MAX	((1u<<31u) - 1)								// RAND_MAX for 32 bit generator

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
 * \brief Read a pool of random numbers
 *
 * Call example in C:
 *
 * \code{.c}
 * #define     KNB_NUMBERS    123
 *
 * int32_t     status;
 * uint32_t    number[KNB_NUMBERS];
 *
 *    status = random_read(KRANDOM_SOFT, &number[0], KNB_NUMBERS);
 * \endcode
 *
 * \param[in]	generator			KRANDOM_SOFT, use the software implementation
 * \param[in]	-					KRANDOM_HARD, use the hardware implementation
 * \param[out]	*number				Ptr on the number
 * \param[in]	nbNumbers			Number of numbers
 * \return		KERR_RANDOM_NOERR	OK
 * \return		KERR_RANDOM_NOERR	General error
 *
 */
extern	int32_t random_read(randomGenerator_t generator, uint32_t *number, uint32_t nbNumbers);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
