/*
; calendar.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		calendar manager.
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
#include	<stdlib.h>
#include	<string.h>
#include	<time.h>

#if (defined(CONFIG_MAN_CALENDAR_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"calendar     calendar manager.                         (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "calendar manager\n"
									"================\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Calendar,						// Module name (the first letter has to be upper case)
	KID_FAM_GENERICS,				// Family (defined in the module.h)
	KNUM_CALENDAR,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

#ifndef	TZ_UTC_SHIFT
#define	TZ_UTC_SHIFT		"CET-1"
#endif

#ifndef	TZ_DST_SPEC
#define	TZ_DST_SPEC			"CEST,M3.5.0/2,M10.5.0/2"
#endif

#define	KSZ_TZ_UTC_SHIFT	(16u + 1u)
#define	KSZ_TZ_DST_SPEC		(32u + 1u)
#define	KSZ_TZ_TIME_ZONE	(KSZ_TZ_UTC_SHIFT + KSZ_TZ_DST_SPEC)

// UTC shift (e.g CET-1, GMT+12, etc.)
// DST summer time sec
// Time zone string for newlib (UTC + DST)

static	char_t		calendar_tzUTCShift[KNB_CORES][KSZ_TZ_UTC_SHIFT];
static	char_t		calendar_tzDSTSpec[KNB_CORES][KSZ_TZ_DST_SPEC];
static	char_t		calendar_tzTimeZone[KNB_CORES][KSZ_TZ_TIME_ZONE];

static	uint64_t	vUnixTime[KNB_CORES]	 =  MCSET(0u);
static	uint64_t	vOldTickCount[KNB_CORES] =  MCSET(0u);

// Prototypes

static	int32_t	local_init(void);
static	void	local_composeTimeZone(char_t *timeZone, const char_t *utcLocation, const char_t *dstLocation);

#if (KCALENDAR_WITH_HW_RTC_S == true)
extern	void	model_rtc_readUnixTime(uint64_t *unixTime);
extern	void	model_rtc_update(uint64_t unixTime);
#endif

/*
 * \brief Set UTC
 *
 * Call example in C:
 *
 * \code{.c}
 * char_t     utcLocation[] = { "CET+1"};
 * int32_t    status;
 *
 *    status = calendar_setUTCLocation(&utcLocation[0]);
 * \endcode
 *
 * \param[out]	*utcLocation		Ptr on the UTC location
 * \return		KERR_CALENDAR_NOERR	OK
 *
 */
int32_t	calendar_setUTCLocation(const char_t *utcLocation) {
	int32_t		status;
	uint32_t	core;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_CALENDAR_NOERR) { PRIVILEGE_RESTORE; return (status); }

	strcpy(&calendar_tzUTCShift[core][0], &utcLocation[0]);
	calendar_tzUTCShift[core][3] = (calendar_tzUTCShift[core][3] == '-') ? ('+') : ('-');

//	calendar_tzTimeZone[core][0] = '\0';

	memset(&calendar_tzTimeZone[core][0], '\0', KSZ_TZ_TIME_ZONE);
	local_composeTimeZone(&calendar_tzTimeZone[core][0], &calendar_tzUTCShift[core][0], &calendar_tzDSTSpec[core][0]);

	setenv("TZ", &calendar_tzTimeZone[core][0], 1u);
	tzset();
	PRIVILEGE_RESTORE;
	return (KERR_CALENDAR_NOERR);
}

/*
 * \brief Write the Unix time
 *
 * Call example in C:
 *
 * \code{.c}
 * uint64_t    unixTime;
 * int32_t     status;
 *
 *    status = calendar_writeUnixTime(&unixTime);
 * \endcode
 *
 * \param[out]	*unixTime			Unix time
 * \return		KERR_CALENDAR_NOERR	OK
 *
 */
int32_t	calendar_writeUnixTime(uint64_t unixTime) {
	int32_t		status;
	uint32_t	core;
	uint64_t	tickCount;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_CALENDAR_NOERR) { PRIVILEGE_RESTORE; return (status); }

	kern_readTickCount(&tickCount);
	vOldTickCount[core] = tickCount;
	vUnixTime[core]		= unixTime;

	#if (KCALENDAR_WITH_HW_RTC_S == true)
	model_rtc_update(unixTime);
	#endif

	PRIVILEGE_RESTORE;
	return (KERR_CALENDAR_NOERR);
}

/*
 * \brief Read the Unix time
 *
 * Call example in C:
 *
 * \code{.c}
 * uint64_t    unixTime;
 * int32_t     status;
 *
 *    status = calendar_readUnixTime(KFROM_TIMER, &unixTime);
 * \endcode
 *
 * \param[in]	fromTimer			KFROM_TIMER, use the Unix time from the Timer (normal mode)
 * \param[in]	-					KFROM_RTC, use the Unix time from the RTC (used for better precision)
 * \param[out]	*unixTime			Ptr on the Unix time
 * \return		KERR_CALENDAR_NOERR	OK
 *
 */
int32_t	calendar_readUnixTime(calendarFromTimer_t fromTimer, uint64_t *unixTime) {
	int32_t		status;
	uint32_t	core;
	uint64_t	tickCount, deltaTickCount;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_CALENDAR_NOERR) { PRIVILEGE_RESTORE; return (status); }

	kern_readTickCount(&tickCount);
	deltaTickCount		= tickCount - vOldTickCount[core];
	vOldTickCount[core]	= tickCount;
	vUnixTime[core]		= vUnixTime[core] + deltaTickCount;

	if (fromTimer == KFROM_RTC) {

		#if (KCALENDAR_WITH_HW_RTC_S == true)
		model_rtc_readUnixTime(&vUnixTime[core]);
		#endif

	}
	*unixTime = vUnixTime[core];

	PRIVILEGE_RESTORE;
	return (KERR_CALENDAR_NOERR);
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static	int32_t	local_init(void) {
			int32_t		status = KERR_CALENDAR_NOERR;
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

		memset(&calendar_tzUTCShift[core][0], '\0', KSZ_TZ_UTC_SHIFT);
		memcpy(&calendar_tzUTCShift[core][0], TZ_UTC_SHIFT, sizeof(TZ_UTC_SHIFT));
		calendar_tzUTCShift[core][KSZ_TZ_UTC_SHIFT - 1] = '\0';

		memset(&calendar_tzDSTSpec[core][0], '\0', KSZ_TZ_DST_SPEC);
		memcpy(&calendar_tzDSTSpec[core][0], TZ_DST_SPEC, sizeof(TZ_DST_SPEC));
		calendar_tzDSTSpec[core][KSZ_TZ_DST_SPEC - 1] = '\0';

		memset(&calendar_tzTimeZone[core][0], '\0', KSZ_TZ_TIME_ZONE);
		local_composeTimeZone(&calendar_tzTimeZone[core][0], &calendar_tzUTCShift[core][0], &calendar_tzDSTSpec[core][0]);

// Set the environment

		setenv("TZ", &calendar_tzTimeZone[core][0], 1);
		tzset();

		#if (KCALENDAR_WITH_HW_RTC_S == true)
		model_rtc_readUnixTime(&vUnixTime[core]);
		#endif

	}
	RETURN_INT_RESTORE(status);
}

/*
 * \brief local_composeTimeZone
 *
 * - This function recover timeZone = CET-1CEST,M3.5.0/2,M10.5.0/2
 *						   from ...
 *						   utcLocation = CET-1
 *						   dstLocation = CEST,M3.5.0/2,M10.5.0/2
 *
 */
static	void	local_composeTimeZone(char_t *timeZone, const char_t *utcLocation, const char_t *dstLocation) {

	strcat(&timeZone[0], &utcLocation[0]);
	strcat(&timeZone[0], &dstLocation[0]);
}

#if (KCALENDAR_WITH_HW_RTC_S == true)
#include	"model_rtc.c_inc"
#endif

#endif
