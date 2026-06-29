/*
; tests_15.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of core ID.
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

#if (defined(TEST_15_S))
static	char_t	vString[20];

/*
 * \brief test_15
 *
 * - Test of core ID
 *
 */
void	test_15(void) {
	uint32_t	configID;
	uint32_t	coreID;
	uint32_t	infoPart;
	uint32_t	deviceID[2];

	cmns_init();

	while (true) {
		cmns_wait(1000000);

		configID	= REG(FICR)->INFO_CONFIGID;

		coreID		= ((REG(SCB)->CPUID & 0x0000FFF0u)>>4);

		infoPart	= REG(FICR)->INFO_PART;

		deviceID[0] = REG(FICR)->INFO_DEVICEID[0];
		deviceID[1] = REG(FICR)->INFO_DEVICEID[1];

		(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)configID);
		cmns_send(KURT0, "Config ID 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");

		(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)coreID);
		cmns_send(KURT0, "Core ID   0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");

		(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)infoPart);
		cmns_send(KURT0, "Info part 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");

		(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)deviceID[0]);
		cmns_send(KURT0, "Device ID 0x"); cmns_send(KURT0, vString);
		(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)deviceID[1]);
										  cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
	}
}
#endif
