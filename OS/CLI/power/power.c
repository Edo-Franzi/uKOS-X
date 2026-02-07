/*
; power.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Give the battery information.
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

STRG_LOC_CONST(aStrApplication[]) =	"power        Give the battery information.             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Give the battery information\n"
									"============================\n\n"

									"This tool displays the battery information.\n\n"

									"Input format:  power\n"
									"Output format: Voltage:               xx [V]\n"
									"               Current:               xx [mA]\n"
									"               Temperature:           xx [K]\n"
									"               Full charged capacity: xx [mAh]\n"
									"               Remaining capacity:    xx [mAh]\n"
									"               Time to empty:         xx [m]\n"
									"               Number of cycles:      xx [-]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Power,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_POWER,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
			batteryInfo_t	batteryInfo;
			int32_t			status;
			uint16_t		i2cTries = 0;
	static	uint16_t		maxI2cTries = 0;

	UNUSED(argc);
	UNUSED(argv);

	(void)dprintf(KSYST, "Battery information.\n");

	RESERVE(BATTERY, KMODE_READ_WRITE);
	do { status = battery_read(&batteryInfo); i2cTries++; } while (status != KERR_BATTERY_NOERR);
	RELEASE(BATTERY, KMODE_READ_WRITE);

	maxI2cTries = (i2cTries > maxI2cTries) ? (i2cTries) : (maxI2cTries);

	if (status != KERR_BATTERY_NOERR) { (void)dprintf(KSYST, "Battery manager problem!\n\n"); return (EXIT_OS_FAILURE); }

	(void)dprintf(KSYST, "Battery voltage:       %7.2f [V]\n",		batteryInfo.oVoltage);
	(void)dprintf(KSYST, "Battery current:       %7.2f [mA]\n",		batteryInfo.oCurrent);
	(void)dprintf(KSYST, "Battery temperature:   %7.2f [K]\n",		batteryInfo.oTemperature);
	(void)dprintf(KSYST, "Full charged capacity: %7.2f [mAh]\n",	batteryInfo.oFullChargedCapacity);
	(void)dprintf(KSYST, "Remaining capacity:    %7.2f [mAh]\n",	batteryInfo.oRemainingCapacity);

	if (batteryInfo.oTimeToEmpty < 65535u) {
		(void)dprintf(KSYST, "Time to empty:          %6d [m]\n",	batteryInfo.oTimeToEmpty);
	}
		(void)dprintf(KSYST, "Cycles:                 %6d [-]\n",	batteryInfo.oCycles);
		(void)dprintf(KSYST, "Max i2c nb tries:       %6d [-]\n\n",	maxI2cTries);
	return (EXIT_OS_SUCCESS_CLI);
}
