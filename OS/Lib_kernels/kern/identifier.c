/*
; identifier.
; ===========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Identifier management (compare the object IDs)
;
;			This module is responsible for manipulating the identifiers of the uKernel.
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

#include	"uKOS.h"

/*
 * \brief Compare 2 identifiers (string_1 -> string_2)
 *
 * \param[in]	*string_1	Ptr on the identifiers string_1
 * \param[in]	*string_2	Ptr on the identifiers string_2
 * \return		true		string_1 == string_2
 * \return		false		string_1 != string_2
 *
 */
bool	identifiers_cmpStrings(const char_t *string_1, const char_t *string_2) {
	uint8_t		i;
	bool		status;

	if ((string_1 == nullptr) || (string_2 == nullptr)) {
		return (false);
	}

	for (i = 0u; i < KKERN_OBJECT_SZ_ID; i++) {
		if ((string_1[i] == '\0') || (string_2[i] == '\0')) {
			status = (string_1[i] == string_2[i]) ? (true) : (false);
			return (status);
		}

		if (string_1[i] != string_2[i]) {
			return (false);
		}

	}
	return (true);
}
