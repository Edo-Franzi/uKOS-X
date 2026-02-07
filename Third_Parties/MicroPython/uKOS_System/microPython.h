/*
; microPython.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		microPython library.
;			uKOS-X interface for MicroPython (www.micropython.com).
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
 * \addtogroup Third_Parties
 */
/**@{*/

/*!
 * \defgroup microPython MicroPython
 *
 * \brief MicroPython
 *
 * MicroPython management
 *
 * @{
 */

// mpyt access macros
// ------------------

#define	MICROPYTHON_CMDLINE		microPython_exchangeData(nullptr);
#define	MICROPYTHON_COMPUTE(x)	microPython_exchangeData(x);

// Configuration structure
// -----------------------

typedef	struct	microPythonCnf		microPythonCnf_t;

struct microPythonCnf {
			uint32_t	oSize;									// Size of the memory
			uint8_t		*oMemory;								// Ptr on the memory location
};

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
 * \brief Configure the microPython manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t              status;
 * microPythonCnf_t    configure;
 *
 *    configure.oSize = 90000;
 *    configure.oMemory = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, configure.oSize, "mpyt");
 *    if (configure.oMemory == 0) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 *
 *    status = microPython_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure				Ptr on the configuration buffer
 * \return		KERR_MICROPYTHON_NOERR	OK
 *
 */
extern	int32_t	microPython_configure(microPythonCnf_t *configure);

/*!
 * \brief Exchange data with the microPython manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 * const    char_t     myRoutine [] = "def plus(a,b):\n"
 *                                    "    return a + b\n";
 *
 *    status = microPython_exchangeData(nullptr);
 *    status = microPython_exchangeData(myRoutine);
 * \endcode
 *
 * \param[in]	*pyProgram				nullptr = Command line interpreter mode
 * \param[in]	-						Ptr on the ascii script / program
 * \return		KERR_MICROPYTHON_NOERR	OK
 *
 */
extern	int32_t	microPython_exchangeData(const char_t *pyProgram);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
