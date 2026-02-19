/*
; text.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		text manager.
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
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \defgroup text Text
 *
 * \brief Text
 *
 * Text management
 *
 * @{
 */

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
 * \brief Get the arguments from a command line
 *
 * Call example in C:
 *
 * \code{.c}
 *          char_t      *argv[KLNINPBUF];
 *          uint32_t    argc;
 *          int32_t     status;
 * const    char_t      commandLine[KLNINPBUF] = ”Line: 3224.5 test 123”;
 *
 *    status = text_readArgs(commandLine, KLNINPBUF, argv, &argc);
 *
 *    (void)dprintf(KSYST, “%d\n”, argc);     // --> 4
 *    (void)dprintf(KSYST, “%d\n”, argv[0]);  // --> line
 *    (void)dprintf(KSYST, “%d\n”, argv[1]);  // --> 4.5
 *    (void)dprintf(KSYST, “%d\n”, argv[2]);  // --> test
 *    (void)dprintf(KSYST, “%d\n”, argv[3]);  // --> 123
 * \endcode
 *
 * - The char "_" is used for space!
 *   - Ex. buffer1 R________
 *         buffer2 RXYZCRLF\0
 *
 * \param[in]	*ascii			Ptr on the ASCII buffer
 * \param[in]	size			Size of the buffer
 * \param[out]	*argv			Ptr on the ASCII argument buffer
 * \param[out]	*argc			Ptr on the number of ASCII arguments
 * \return		KERR_TEXT_NOERR	OK
 *
 */
extern	int32_t	text_readArgs(char_t *ascii, uint32_t size, const char_t *argv[], uint32_t *argc);

/*!
 * \brief Copy 2 ASCII buffers (\0 is copied)
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    256
 *
 *          char_t     asciiD[KSIZE];
 *          int32_t    status;
 * const    char_t     asciiS[] = ”This is the buffer 2”;
 *
 *    status = text_copyBufferZ(asciiD, asciiS);
 * \endcode
 *
 * - The char "_" is used for space!
 *   - Ex. buffer1 R________
 *         buffer2 RXYZCRLF\0
 *
 * \param[out]	*asciiD			Ptr on the ASCII destination buffer
 * \param[in]	*asciiS			Ptr on the ASCII source buffer
 * \return		KERR_TEXT_NOERR	OK
 *
 */
extern	int32_t	text_copyAsciiBufferZ(char_t *asciiD, const char_t *asciiS);

/*!
 * \brief Copy 2 ASCII buffers (\0 is not copied)
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    256
 *
 *          char_t     asciiD[KSIZE];
 *          int32_t    status;
 * const    char_t     asciiS[] = ”This is the buffer 2”;
 *
 *    status = text_copyBufferN(asciiD, asciiS);
 * \endcode
 *
 * \param[in]	*asciiD			Ptr on the ASCII destination buffer
 * \param[in]	*asciiS			Ptr on the ASCII source buffer
 * \return		KERR_TEXT_NOERR	OK
 *
 */
extern	int32_t	text_copyAsciiBufferN(char_t *asciiD, const char_t *asciiS);

/*!
 * \brief Check if 2 ASCII buffers are identical
 *
 * Call example in C:
 *
 * \code{.c}
 *          boolc      *equal;
 *          int32_t    status;
 * const    char_t     ascii1[] = ”This is the buffer 1”;
 * const    char_t     ascii2[] = ”This is the buffer 2”;
 *
 *    status = text_checkAsciiBuffer(ascii1, ascii2, equals);
 * \endcode
 *
 * \param[in]	*ascii1			Ptr on the ASCII buffer 1
 * \param[in]	*ascii2			Ptr on the ASCII buffer 2
 * \param[out]	*equals			The 2 ASCII buffers are identical (true) or not (false)
 * \return		KERR_TEXT_NOERR	OK
 *
 */
extern	int32_t	text_checkAsciiBuffer(const char_t *ascii1, const char_t *ascii2, bool *equals);

/*!
 * \brief Waiting for an ASCII string from a Serial Communication Manager
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    256
 *
 * int32_t    status;
 * char_t     ascii[KSIZE];
 *
 *    status = text_waitString(KDEF0, ascii, KSIZE);
 * \endcode
 *
 * - Format of the order:
 *   - string\0 char is added at the end
 *     The CR or LF at the end are skipped
 *
 * \param[in]	serialManager	Serial Communication Manager
 * \param[in]	*ascii			Ptr on the ASCII buffer
 * \param[in]	size			Size of the ASCII buffer
 * \return		KERR_TEXT_NOERR	OK
 *
 */
extern	int32_t	text_waitString(serialManager_t serialManager, char_t *ascii, uint32_t size);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
