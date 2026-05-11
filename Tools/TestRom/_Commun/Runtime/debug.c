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

#include	"tests.h"

static	char_t	vString[30];

// Prototypes

static	void	local_cnvtInt32HASCII(int32_t binary, char_t *ascii, uint8_t nbDigits);
static	void	local_cnvtInt32DASCII(int32_t binary, char_t *ascii);

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
void	debug_cnvtValInt32ToHexAscii(char_t *ascii, const int32_t *binary) {

	local_cnvtInt32HASCII(*binary, ascii, 8);
}

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
void	debug_cnvtValInt32ToDecAscii(char_t *ascii, const int32_t *binary) {

	local_cnvtInt32DASCII(*binary, ascii);
}

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
void	debug_printValueH(volatile int32_t binary) {

	debug_cnvtValInt32ToHexAscii(vString, (int32_t *)&binary);
	cmns_send(0, "Value  0x"); cmns_send(0, vString); cmns_send(0, "\n");
}

/*
 * \brief Print a 32-bit value (decimal)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    value = -233;
 *
 *   debug_printValueHD(value);
 * \endcode
 *
 * \param[in]	*binary		Ptr on the binary value
 *
 * \note This function does not return a value (None).
 *
 */
void	debug_printValueD(volatile int32_t binary) {

	debug_cnvtValInt32ToDecAscii(vString, (int32_t *)&binary);
	cmns_send(0, "Value    "); cmns_send(0, vString); cmns_send(0, "\n");
}

/*
 * \brief local_cnvtInt32HASCII
 *
 * - Conversion from a int32_t value to a hexadecimal ASCII buffer
 *
 */
static	void	local_cnvtInt32HASCII(int32_t binary, char_t *ascii, uint8_t nbDigits) {
					uint8_t		i, number;
	static	const	char_t		tabHX[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

	for (i = 0; i < nbDigits; i++) {
		number = (uint8_t)binary & 0xF;
		binary >>= 4;
		ascii[nbDigits - 1 - i] = tabHX[number];
	}
	ascii[nbDigits] = '\0';
}

/*
 * \brief local_cnvtInt32DASCII
 *
 * - Conversion from a int32_t value to a decimal ASCII buffer
 *
 */
static	void	local_cnvtInt32DASCII(int32_t binary, char_t *ascii) {
					uint8_t		i, digit;
					bool		zero = true;
					int32_t		wkBinary = binary;
					char_t		*wkAscii = ascii;
	static	const	int32_t		tabDF[] = {
									1000000000,
									100000000,
									10000000,
									1000000,
									100000,
									10000,
									1000,
									100,
									10,
									1
								};

// Process only positive numbers of max. 10 digits

	for (i = 0; i < 10; i++) {
		digit = 0;
		do {
			digit++;
			wkBinary -= tabDF[i];
		} while (wkBinary >= 0);
		digit--;
		wkBinary += tabDF[i];

		if (digit != 0) {
			zero = false;
		}
		if (zero == false) {
			*wkAscii = (char_t)digit + '0';
			wkAscii++;
		}
	}
	if (zero == true) {
		*wkAscii = '0';
		wkAscii++;
	}
	*wkAscii = '\0';
}
