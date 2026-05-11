/*
; wki2c.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		wki2c tool.
;			This tool allows to operate with an i2c device.
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

STRG_LOC_CONST(aStrApplication[]) =	"wki2c        Communicate with the i2c x device.        (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Read/write on the i2c x device\n"
									"==============================\n\n"

									"This tool allows to read/write data on the i2c x bus.\n"
									"wki2c {device} -W address register/byte0..byteN\n"
									"wki2c {device} -R address register nbBytes\n"
									"   register  = -1 -> no register to be written\n"
									"   register != -1 -> register to be written\n\n"

									"Example\n"
									"   wki2c 0 -W 7C -1 A4 6D 2D    write on the device address 0x7C\n"
									"                                0xA4 0x6D 0x2D\n"
									"   wki2c 0 -W 7C 47 A4 6D 2D    write on the device address 0x7C\n"
									"                                first write 0x47 (the register number)\n"
									"                                then write the data 0xA4 0x6D 0x2D\n"
									"   wki2c 1 -R 84 -1 26          read from the device address 0x84 0x26-bytes\n"
									"   wki2c 1 -R 84 34 26          read from the device address 0x7C\n"
									"                                first write 0x34 (the register number)\n"
									"                                then read 0x26-bytes\n\n"

									"Input format:  wki2c {device} -W address, register/bytes..\n"
									"Input format:  wki2c {device} -R address, register nbBytes\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Wki2c,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_WK_I2C,								// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KNB_PARAMETERS	10u

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
					char_t			*dummy;
					int32_t			status;
					uint16_t		i, number = 0u;
					uint8_t			unit = 0u, address = 0u, chipRegister = 0u, buffer8[KNB_PARAMETERS];
					bool			equals;
					i2cManager_t	i2cManager;
					enum			{ KWRITE, KREAD } mode = KREAD;
					enum			{ KOKWRITE, KOKREAD, KERRBUSY, KERRINA, KERRGEN } error = KERRINA;
	static	const	i2cCnf_t		aConfigure = {
										.oTimeout  = 1000u,
										.oSpeed    = KI2C_100KBPS,
									};

	(void)dprintf(KSYST, "wki2c operations.\n");

// Analyse the command line
// ------------------------
//
// Examples:
//
// Write mode
//  wki2c 0 -W address register/byte0..byteN
//
// Read mode (direct)
//  wki2c 1 -R address -1 nbBytes
//
// Read mode (with write register)
//  wki2c 1 -R address register nbBytes

	unit = (uint8_t)strtoul(argv[1], &dummy, 10u);
	switch (unit) {
		default:
		case 0u: { i2cManager = KI2C0; break; }
		case 1u: { i2cManager = KI2C1; break; }
		case 2u: { i2cManager = KI2C2; break; }
		case 3u: { i2cManager = KI2C3; break; }
	}

	if (i2c_reserve(i2cManager, KMODE_READ_WRITE, 2000u) == KERR_I2C_NOERR) {
		i2c_configure(i2cManager, &aConfigure);

		if (argc > 5u) {
			address = (uint8_t)strtoul(argv[3], &dummy, 16u);

			text_checkAsciiBuffer(argv[2], "-W", &equals); if (equals == true) { mode = KWRITE; }
			text_checkAsciiBuffer(argv[2], "-R", &equals); if (equals == true) { mode = KREAD;  }

			switch (mode) {
				case KWRITE: {
					number = (uint16_t)(argc - 4u);
					for (i = 0u; i < number; i++) {
						buffer8[i] = (uint8_t)strtoul(argv[4 + i], &dummy, 16u);
					}
					status = i2c_write(i2cManager, address, &buffer8[0], number);
					switch (status) {
						case KERR_I2C_NOERR: { error = KOKWRITE; break; }
						default:			 { error = KERRGEN;  break; }
					}
					break;
				}
				case KREAD: {
					number		 = (uint16_t)strtoul(argv[5], &dummy, 10u);
					chipRegister = (uint8_t) strtoul(argv[4], &dummy, 16u);
					buffer8[0]	 = chipRegister;

					status = i2c_read(i2cManager, address, &buffer8[0], number);
					switch (status) {
						case KERR_I2C_NOERR: { error = KOKREAD; break; }
						default:			 { error = KERRGEN; break; }
					}
					break;
				}
				default: {
					error = KERRINA;
					break;
				}
			}
		}
		i2c_release(i2cManager, KMODE_READ_WRITE);
	}
	else {
		error = KERRBUSY;
	}

	switch (error) {
		case KOKWRITE: { (void)dprintf(KSYST, "i2c%d address %02X written", unit, address);
						 for (i = 0u; i < number; i++) { (void)dprintf(KSYST, " %02X", buffer8[i]); }
						 (void)dprintf(KSYST, "\n\n");													status = EXIT_OS_SUCCESS_CLI; break; }

		case KOKREAD:  { (void)dprintf(KSYST, "i2c%d address %02X read", unit, address);
						 for (i = 0u; i < number; i++) { (void)dprintf(KSYST, " %02X", buffer8[i]); }
						 (void)dprintf(KSYST, "\n\n");													status = EXIT_OS_SUCCESS_CLI; break; }

		case KERRINA:  { (void)dprintf(KSYST, "Incorrect arguments.\n\n");								status = EXIT_OS_FAILURE;     break; }
		case KERRGEN:  { (void)dprintf(KSYST, "i2c%d general problem.\n\n", unit);						status = EXIT_OS_FAILURE;     break; }
		case KERRBUSY: { (void)dprintf(KSYST, "i2c%d busy or not existent\n\n", unit);					status = EXIT_OS_FAILURE;     break; }
		default:	   {																				status = EXIT_OS_FAILURE;     break; }
	}
	return (status);
}
