/*
; date.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

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
									"               Ranges: dd 1..31, mm 1..12, yyyy 1970..9999,\n"
									"                       hh 0..23, MM 0..59, ss 0..59\n"
									"Output format: From timer: Epoch = 1743444022204019, Local time:  Mon Mar 31 18:00:22 2025\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]);

MODULE(
	Date,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_DATE,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.1",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// Local prototypes

static	bool	local_getField(const char_t *ascii, long minimum, long maximum, int *value);
static	bool	local_checkLocation(const char_t *location);
static	bool	local_showTime(const char_t *origin, uint64_t unixTime);

/*
 * \brief Main entry point
 *
 */
static	int32_t prgm(uint32_t argc, const char_t *argv[]) {
	int32_t		status;
	bool		equals;
	enum		{ KERR_NOT, KERR_INA, KERR_FMT, KERR_RTC, KERR_CAL, KERR_TIM } error = KERR_NOT;
	uint64_t	unixTime;

	(void)dprintf(KSYST, "Set/display the date.\n");

// Analyse the command line
// ------------------------
//
// Examples:
//
// date: 0 parameter  -> display UTC (from the timer)	date						-> "Thu 10.01.1970 00:01:01	 Epoch = 61"
// date: 1 parameter  -> display UTC (from the RTC)		date -rtc					-> "Thu 10.01.1970 00:01:01	 Epoch = 61"
// date: 2 parameters -> set the GMT					date -gmt "GMT+1, GMT+5:45"
// date: 6 parameters -> set the date					date "2 4 2025 10 28 00"

	switch (argc) {

// date: 0 parameters -> get the UTC & the local time from the internal 64-bit counter

		case 1u: {
			if (calendar_readUnixTime(KFROM_TIMER, &unixTime) != KERR_CALENDAR_NOERR) {
				error = KERR_CAL;
				break;
			}

			if (local_showTime("From timer:", unixTime) == false) {
				error = KERR_TIM;
			}
			break;
		}

// date: 1 parameter -> get the UTC & the local time from the RTC

		case 2u: {
			text_checkAsciiBuffer(argv[1], "-rtc", &equals);
			if (equals == true) {

				#if (KCALENDAR_WITH_HW_RTC_S == true)
				if (calendar_readUnixTime(KFROM_RTC, &unixTime) != KERR_CALENDAR_NOERR) {
					error = KERR_CAL;
					break;
				}

				if (local_showTime("From RTC:", unixTime) == false) {
					error = KERR_TIM;
				}

				#else
				error = KERR_RTC;
				#endif
			}
			else {
				error = KERR_FMT;
			}
			break;
		}

// date: 2 parameters -> set the UTC location (i.e. "GMT+1, GMT+5:45")

		case 3u: {
			text_checkAsciiBuffer(argv[1], "-gmt", &equals);
			if (equals && local_checkLocation(argv[2]) == true) {
				if (calendar_setUTCLocation(argv[2]) != KERR_CALENDAR_NOERR) {
					error = KERR_CAL;
				}
			}
			else {
				error = KERR_FMT;
			}
			break;
		}

// date: 6 parameters -> set the date	"2 4 2025 10 28 00"

		case 7u: {
			tm_t	currentTime;
			time_t	now;
			int		mday, mon, year, hour, minute, sec;

			if (   (local_getField(argv[1],	   1,	31, &mday)	 == false)
				|| (local_getField(argv[2],	   1,	12, &mon)	 == false)
				|| (local_getField(argv[3], 1970, 9999, &year)	 == false)
				|| (local_getField(argv[4],	   0,	23, &hour)	 == false)
				|| (local_getField(argv[5],	   0,	59, &minute) == false)
				|| (local_getField(argv[6],	   0,	59, &sec)	 == false)) {
				error = KERR_FMT;
				break;
			}

// mktime() reads more of the structure than the six fields above, so start
// from a cleared one rather than from whatever the stack held

			(void)memset(&currentTime, 0, sizeof currentTime);
			currentTime.tm_mday	 = mday;
			currentTime.tm_mon	 = mon - 1;
			currentTime.tm_year	 = year - 1900;
			currentTime.tm_hour	 = hour;
			currentTime.tm_min	 = minute;
			currentTime.tm_sec	 = sec;
			currentTime.tm_isdst = -1;
			now = mktime(&currentTime);

// The year is constrained to 1970..9999, so epoch -1 (31.12.1969 23:59:59 UTC)
// can no longer be a legitimate result and (time_t)-1 unambiguously reports a
// failure - typically a 32-bit time_t overflowing

			if (now == (time_t)-1) {
				error = KERR_FMT;
				break;
			}

// mktime() silently normalises a date that does not exist (31 February becomes
// 3 March); comparing the fields back is what rejects it

			if (   (currentTime.tm_mday != mday)
				|| (currentTime.tm_mon	!= (mon	 - 1))
				|| (currentTime.tm_year != (year - 1900))) {
				error = KERR_FMT;
				break;
			}

			unixTime = (uint64_t)now * (uint64_t)CLOCKS_PER_SEC;

			if (calendar_writeUnixTime(unixTime) != KERR_CALENDAR_NOERR) {
				error = KERR_CAL;
			}
			break;
		}
		default: {
			error = KERR_INA;
			break;
		}
	}

	switch (error) {
		case KERR_NOT: { (void)dprintf(KSYST, "\n");							status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_RTC: { (void)dprintf(KSYST, "RTC not available.\n\n");		status = EXIT_OS_FAILURE;	  break; }
		case KERR_INA: { (void)dprintf(KSYST, "Incorrect arguments.\n\n");		status = EXIT_OS_FAILURE;	  break; }
		case KERR_FMT: { (void)dprintf(KSYST, "Incorrect format.\n\n");			status = EXIT_OS_FAILURE;	  break; }
		case KERR_CAL: { (void)dprintf(KSYST, "Calendar not available.\n\n");	status = EXIT_OS_FAILURE;	  break; }
		case KERR_TIM: { (void)dprintf(KSYST, "Time out of range.\n\n");		status = EXIT_OS_FAILURE;	  break; }
		default:	   {														status = EXIT_OS_FAILURE;	  break; }
	}
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_getField
 *
 * Convert one fully consumed decimal field and range check it
 *
 * strtoul() alone accepts "31abc" as 31 and "" as 0, and wraps a leading '-'
 * into a huge unsigned value. The end pointer and the range are both checked
 * here so that only a complete, plausible field is accepted.
 *
 */
static	bool	local_getField(const char_t *ascii, long minimum, long maximum, int *value) {
	char_t		*end;
	long		parsed;

	parsed = strtol(ascii, &end, 10);

// Reject an empty field and any unconsumed remainder

	if ((end == ascii) || (*end != '\0')) {
		return (false);
	}

	if ((parsed < minimum) || (parsed > maximum)) {
		return (false);
	}

	*value = (int)parsed;
	return (true);
}

/*
 * \brief local_checkLocation
 *
 * Check that a UTC location is long enough for the calendar manager
 *
 * calendar_setUTCLocation() copies the string and then overwrites index 3 to
 * invert the POSIX sign convention, so anything shorter than 4 characters
 * would lose its terminator.
 *
 */
static	bool	local_checkLocation(const char_t *location) {

	return (strlen(location) >= 4u);
}

/*
 * \brief local_showTime
 *
 * Display one Unix time as UTC and as local time
 *
 * Both renderings are derived from the Unix time that was just read, never
 * from a second clock, so the printed epoch and the printed date always
 * describe the same instant - including for the RTC, which may well disagree
 * with the system timer.
 *
 */
static	bool	local_showTime(const char_t *origin, uint64_t unixTime) {
			time_t	seconds;
			tm_t	utcTime, localTime;
	const	char_t	*ascii;

	seconds = (time_t)(unixTime / (uint64_t)CLOCKS_PER_SEC);

	if (gmtime_r(&seconds, &utcTime) == nullptr) {
		return (false);
	}

	ascii = asctime(&utcTime);
	if (ascii == nullptr) {
		return (false);
	}

	(void)dprintf(KSYST, "%s Epoch = %"PRIu64", UTC time:    %s", origin, unixTime, ascii);

// asctime() hands back a pointer to its own static buffer, so the second
// conversion has to happen after the first one has been printed

	if (localtime_r(&seconds, &localTime) == nullptr) {
		return (false);
	}

	ascii = asctime(&localTime);
	if (ascii == nullptr) {
		return (false);
	}

	(void)dprintf(KSYST, "%s Epoch = %"PRIu64", Local time:  %s", origin, unixTime, ascii);
	return (true);
}

