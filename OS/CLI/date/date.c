/*
; date.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		This tool allows to display the date based on the
;			system Unix time.
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
#include	"kern/private/private_temporal.h"
#include	<time.h>

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"date         Set / display date and time.              (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Set/display the date\n"
									"====================\n\n"

									"This tool displays the current date and time from the\n"
									"OS system clock.\n\n"

									"Input format:  date\n"
									"               date -rtc\n"
									"               date -gmt [GMT[+/-n]]\n"
									"               date [dd mm yyyy hh MM ss]\n"
									"               Ex. date -gmt GMT+1 (for utc + 1h)\n"
									"               Ex. date -gmt GMT-1:45 (for utc - 1h45m)\n"
									"               Ex. date 31 3 2025 18 00 22\n"
									"Output format: Local time: Epoch = 1743444022204019, Local time: Mon Mar 31 18:00:22 2025\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Date,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_DATE,									// Module identifier (defined in the module.h)
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
	char_t		*dummy;
	int32_t		parameter;
	int32_t		status;
	bool		equals;
	enum		{ KERR_NOT, KERR_INA, KERR_FMT, KERR_RTC } error = KERR_NOT;
	uint64_t	unixTime;
	time_t		now;
	tm_t		utcTime, localTime, currentTime;

	(void)dprintf(KSYST, "Set/display the date.\n");

// Analyse the command line
// ------------------------
//
// Examples:
//
// date: 0 parameter -> display UTC (from the timer)	date						-> "Thu 10.01.1970 00:01:01  Epoch = 61"
// date: 1 parameter -> display UTC (from the RTC)		date -rtc					-> "Thu 10.01.1970 00:01:01  Epoch = 61"
// date: 3 parameter -> set the GMT						date -gmt "GMT+1, GMT+5:45"
// date: 7 parameter -> set the date					date "2 4 2025 10 28 00"

	switch (argc) {

// date: 0 parameters -> get the UTC & the local time from the internal 64-bit counter

		case 1u: {
			calendar_readUnixTime(KFROM_TIMER, &unixTime);

			now = time(nullptr);
			gmtime_r(&now, &utcTime);
			localtime_r(&now, &localTime);

			(void)dprintf(KSYST, "From timer: Epoch = %"PRIu64", UTC time:    %s", unixTime, asctime(&utcTime));
			(void)dprintf(KSYST, "From timer: Epoch = %"PRIu64", Local time:  %s", unixTime, asctime(&localTime));
			break;
		}

// date: 3 parameters -> get the UTC & the local time from the internal 64-bit counter

		case 2u: {
			text_checkAsciiBuffer(argv[1], "-rtc", &equals);
			if (equals == true) {

				#if (KCALENDAR_WITH_HW_RTC_S == true)
				calendar_readUnixTime(KFROM_RTC, &unixTime);

				now = time(nullptr);
				gmtime_r(&now, &utcTime);
				localtime_r(&now, &localTime);

				(void)dprintf(KSYST, "From RTC: Epoch = %"PRIu64", UTC time:    %s", unixTime, asctime(&utcTime));
				(void)dprintf(KSYST, "From RTC: Epoch = %"PRIu64", Local time:  %s", unixTime, asctime(&localTime));

				#else
				error = KERR_RTC;
				#endif
			}
			else {
				error = KERR_FMT;
			}
			break;
		}

// date: 3 parameters -> set the date (i.e. "GMT+1, GMT+5:45")

		case 3u: {
			text_checkAsciiBuffer(argv[1], "-gmt", &equals);
			if (equals == true) {
				calendar_setUTCLocation(argv[1]);
			}
			else {
				error = KERR_FMT;
			}
			break;
		}

// date: 7 parameters -> set the date	"2 4 2025 10 28 00"

		case 7u: {
			parameter = (int32_t)strtol(argv[1], &dummy, 10u); currentTime.tm_mday  = (int)(parameter);
			parameter = (int32_t)strtol(argv[2], &dummy, 10u); currentTime.tm_mon   = (int)(parameter - 1);
			parameter = (int32_t)strtol(argv[3], &dummy, 10u); currentTime.tm_year  = (int)(parameter - 1900);
			parameter = (int32_t)strtol(argv[4], &dummy, 10u); currentTime.tm_hour  = (int)(parameter);
			parameter = (int32_t)strtol(argv[5], &dummy, 10u); currentTime.tm_min   = (int)(parameter);
			parameter = (int32_t)strtol(argv[6], &dummy, 10u); currentTime.tm_sec   = (int)(parameter);
															   currentTime.tm_isdst = -1;

			now = mktime(&currentTime);

			if (now != -1 ) {
				unixTime = (uint64_t)(now * CLOCKS_PER_SEC);
				calendar_writeUnixTime(unixTime);
			}
			else {
				error = KERR_FMT;
			}
			break;
		}
		default: {
			error = KERR_INA;
			break;
		}
	}

	switch (error) {
		case KERR_NOT: { (void)dprintf(KSYST, "\n");					   status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_RTC: { (void)dprintf(KSYST, "RTC not available.\n\n");   status = EXIT_OS_FAILURE;     break; }
		case KERR_INA: { (void)dprintf(KSYST, "Incorrect arguments.\n\n"); status = EXIT_OS_FAILURE;     break; }
		case KERR_FMT: { (void)dprintf(KSYST, "Incorrect format.\n\n");	   status = EXIT_OS_FAILURE;     break; }
		default:	   {												   status = EXIT_OS_FAILURE;     break; }
	}
	return (status);
}
