/*
; watchdog.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		watchdog manager.
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

#if (defined(CONFIG_MAN_WATCHDOG_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"watchdog     watchdog manager.                         (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "watchdog manager\n"
									"================\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Watchdog,						// Module name (the first letter has to be upper case)
	KID_FAM_PERIPHERALS,			// Family (defined in the module.h)
	KNUM_WATCHDOG,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

typedef	struct	watchdogPack	watchdogPack_t;

struct	watchdogPack {
			uint32_t	oTime;
			bool		*oReleasePack;
		};

// Prototypes

static	void	local_process_watchdog(const void *argument);
extern	void	stub_watchdog_arm(uint32_t time);

/*
 * \brief Arm the watchdog
 *
 * \warning	This function is hardware dependent
 *
 * Call example in C:
 *
 * \code{.c}
 * // KWATCHDOG_AUTO      -> Automatic mode (a daemon handles the watchdog)
 * // KWATCHDOG_MANUAL    -> Manual mode (the user handles the watchdog)
 *
 * #define    KWATCHDOG_TIME    10000    // Reset after 10000-ms
 *
 * int32_t    status;
 *
 *    status = watchdog_arm(KWATCHDOG_TIME, KWATCHDOG_AUTO);
 * \endcode
 *
 * - Generate a reset if the timer is not reactivated
 *   The min-max time is hardware dependent (0 < time < 4294967296-ms)
 *   I.e for the stm32 series the min-max time is 8-ms < time < 32768-ms
 *   I.e for the gd32vf103 series the min-max time is 6.4 < time < 26214.4-ms
 *
 * \param[in]	time				Restart time if the watchdog is not re-activated
 * \param[in]	mode				KWATCHDOG_AUTO, create a daemon to re-activate the watchdog
 * 				-					KWATCHDOG_MANUAL, the user is responsible to re-activate the watchdog
 * \return		KERR_WATCHDOG_NOERR	OK
 *
 */
int32_t	watchdog_arm(uint32_t time, uint8_t mode) {
			uint32_t		core, wkTime = time;
			watchdogPack_t	pack;
			bool			releasePack = false;
	static	proc_t			*process_watchdog[KNB_CORES] = MCSET(nullptr);

// -------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden[]) = "Daemon_watchdog";
	STRG_LOC_CONST(aStrText[]) = "Daemon, watchdog process.                 (c) EFr-2026";

	#undef	KDAEMON_STACK_SIZE
	#define	KDAEMON_STACK_SIZE	KKERN_SZ_STACK_SS
	VAR_DECLARED_ALIGN(static	uintptr_t	vStack[KNB_CORES][KDAEMON_STACK_SIZE], KSTACK_ALIGNMENT);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;

	wkTime = (wkTime > KWATCHDOG_MAX_TIME_MS) ? (KWATCHDOG_MAX_TIME_MS) : (wkTime);

	switch (mode) {
		case KWATCHDOG_AUTO: {
			if (process_watchdog[core] == nullptr) {
				stub_watchdog_arm(wkTime);

				pack.oTime		  = wkTime;
				pack.oReleasePack = &releasePack;

				DAEMON_PRIVILEGED(core, specification, aStrText, vStack, KDAEMON_STACK_SIZE, local_process_watchdog, aStrIden, KSYST, KKERN_PRIORITY_HIGH_15);
				if (kern_createProcess(&specification, &pack, &process_watchdog[core]) != KERR_KERN_NOERR) { LOG(KFATAL_KERNEL, "wdog: Create process watchdog"); exit(EXIT_OS_PANIC); }

				do { kern_suspendProcess(1u); } while (releasePack == false);
			}
			break;
		}
		case KWATCHDOG_MANUAL: {
			if (process_watchdog[core] != nullptr) {
				kern_killProcess(process_watchdog[core]);
				process_watchdog[core] = nullptr;
			}
			stub_watchdog_arm(wkTime);
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	PRIVILEGE_RESTORE;
	return (KERR_WATCHDOG_NOERR);
}

// Local routines
// ==============

/*
 * \brief local_process_watchdog
 *
 * - Cyclically re-arm the watchdog
 *
 */
static void __attribute__ ((noreturn)) local_process_watchdog(const void *argument) {
			uint32_t		time, watchdog;
			bool			*releasePack;
	const	watchdogPack_t	*pack;

// Recover the process arguments

	pack = (const watchdogPack_t *)argument;

	watchdog = pack->oTime;
	time     = (uint32_t)((float64_t)pack->oTime * KWATCHDOG_MARGIN);

	time = (time == 0u) ? (1u) : (time);
	releasePack  = pack->oReleasePack;
	*releasePack = true;

	while (true) {
		kern_suspendProcess(time);
		stub_watchdog_arm(watchdog);
	}
}

#endif
