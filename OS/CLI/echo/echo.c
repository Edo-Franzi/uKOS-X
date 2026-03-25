/*
; echo.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		echo tool; echo from a Serial Communication Manager.
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

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"echo         echo function.                            (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "echo\n"
									"====\n\n"

									"This tool performs an echo on a Serial Communication Manager\n\n"

									"Input format:  echo {serialManager1, serialManager2}\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Echo,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_ECHO,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KTIMEOUT_5S		5000000u
#define	KTIMEOUT_10S	10000000u

// Prototypes

static	bool	local_getByte(serialManager_t serialManager, uint8_t *buffer, uint64_t timeout);
static	void	local_putByte(serialManager_t serialManager, const uint8_t *buffer);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
			uint8_t				data;
			int32_t				status;
			serialManager_t		serialManager0, serialManager1;
			uint64_t			timeout;
			bool				terminate = false;
			enum				{ KERR_NOT, KERR_INA, KERR_CHA, KERR_BSY } error = KERR_NOT;
	const	char_t				*comm = "", *comm0, *comm1;

	(void)dprintf(KSYST, "Communication echo.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// echo urt0 urt1

	if (argc < 3) {
		error = KERR_INA;
	}
	else {
		comm0 = argv[1];
		comm1 = argv[2];
		serialManager0 = (serialManager_t)(GET_PTR_32(comm0));
		serialManager1 = (serialManager_t)(GET_PTR_32(comm1));

// Reserve the serialManager0 and serialManager1 managers

		switch (serial_reserve(serialManager0, KMODE_READ, 1000u)) {
			case KERR_SERIAL_NODEV: {
				error = KERR_CHA;
				comm = comm0;
				terminate = true;
				break;
			}
			case KERR_SERIAL_CHBSY: {
				error = KERR_BSY;
				comm = comm0;
				terminate = true;
				break;
			}
			default: {

// Make MISRA happy :-)

				break;
			}
		}

		switch (serial_reserve(serialManager1, KMODE_WRITE, 1000u)) {
			case KERR_SERIAL_NODEV: {
				error = KERR_CHA;
				comm = comm1;
				terminate = true;
				RELEASE_SERIAL(serialManager0, KMODE_READ);
				break;
			}
			case KERR_SERIAL_CHBSY: {
				error = KERR_BSY;
				comm = comm1;
				terminate = true;
				RELEASE_SERIAL(serialManager0, KMODE_READ);
				break;
			}
			default: {

// Make MISRA happy :-)

				break;
			}
		}

		serial_flush(serialManager0);
		timeout = KTIMEOUT_10S;

		while (terminate == false) {

// Read serialManager0 under a 10s or 5s timeout (10s for the first char) and write on the serialManager1

			if (local_getByte(serialManager0, &data, timeout) == false) {
				error = KERR_NOT;
				serial_flush(serialManager0);
				RELEASE_SERIAL(serialManager0, KMODE_READ);
				RELEASE_SERIAL(serialManager1, KMODE_WRITE);
				local_putByte(serialManager1, &data);
				terminate = true;
			}
			else {
				local_putByte(serialManager1, &data);
				timeout = KTIMEOUT_5S;
			}
		}
	}

	led_off(KLED_1);

	switch (error) {
		case KERR_NOT: { (void)dprintf(KSYST, "\n");											  status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_INA: { (void)dprintf(KSYST, "Incorrect arguments.\n\n");						  status = EXIT_OS_FAILURE;     break; }
		case KERR_CHA: { (void)dprintf(KSYST, "Bad Serial Communication Manager: %s\n\n", comm);  status = EXIT_OS_FAILURE;     break; }
		case KERR_BSY: { (void)dprintf(KSYST, "Serial Communication Manager busy: %s\n\n", comm); status = EXIT_OS_FAILURE;     break; }
		default:	   {																		  status = EXIT_OS_FAILURE;     break; }
	}
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_getByte
 *
 * - Read a Byte
 *
 */
static	bool	local_getByte(serialManager_t serialManager, uint8_t *buffer, uint64_t timeout) {
	int32_t		status;
	uint32_t	size;
	uint64_t	time[2];

	*buffer = 0u;
	kern_readTickCount(&time[0]);

	do {
		kern_readTickCount(&time[1]);
		if ((time[1] - time[0]) >= timeout) {
			return (false);
		}

		kern_switchFast();
		size = 1u;
		status = serial_read(serialManager, buffer, &size);
	} while (status != KERR_SERIAL_NOERR);

	led_toggle(KLED_1);
	return (true);
}

/*
 * \brief local_putByte
 *
 * - Write a Byte
 *
 */
static	void	local_putByte(serialManager_t serialManager, const uint8_t *buffer) {
	int32_t		status;

	do {
		kern_switchFast();

		status = serial_write(serialManager, buffer, 1u);
	} while (status != KERR_SERIAL_NOERR);
}
