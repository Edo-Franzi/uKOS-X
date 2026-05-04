/*
; random.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		random manager.
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

#if (defined(CONFIG_MAN_RANDOM_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"random       random manager.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "random manager\n"
									"==============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Random,							// Module name (the first letter has to be upper case)
	KID_FAM_CRYPTOGRAPHICS,			// Family (defined in the module.h)
	KNUM_RANDOM,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

STRG_LOC_CONST(aStrIdSRandom[]) = "Critical_random";
static	mutx_t	*vMutex_Reserve_Random[KNB_CORES];

// Prototypes

static	int32_t		local_init(void);
extern	int32_t		stub_random_init(void);
extern	int32_t		stub_random_read(randomGenerator_t generator, uint32_t *number);

/*
 * \brief Read a pool of random numbers
 *
 * Call example in C:
 *
 * \code{.c}
 * #define     KNB_NUMBERS    123
 *
 * int32_t     status;
 * uint32_t    number[KNB_NUMBERS];
 *
 *    status = random_read(KRANDOM_SOFT, &number[0], KNB_NUMBERS);
 * \endcode
 *
 * \param[in]	generator			KRANDOM_SOFT, use the software implementation
 *									KRANDOM_HARD, use the hardware implementation
 * \param[out]	*number				Ptr on the number
 * \param[in]	nbNumbers			Number of numbers
 * \return		KERR_RANDOM_NOERR	OK
 * \return		KERR_RANDOM_GEERR	General error
 *
 */
int32_t random_read(randomGenerator_t generator, uint32_t *number, uint32_t nbNumbers) {
	uint32_t	core, i, *wkNumber = number;
	int32_t		status;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_RANDOM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	if ((number == nullptr) || (nbNumbers == 0u)) {
		PRIVILEGE_RESTORE;
		return (KERR_RANDOM_GEERR);
	}

	kern_lockMutex(vMutex_Reserve_Random[core], KWAIT_INFINITY);
	for (i = 0u; i < nbNumbers; i++) {
		stub_random_read(generator, wkNumber);
		wkNumber++;
	}
	kern_unlockMutex(vMutex_Reserve_Random[core]);
	PRIVILEGE_RESTORE;
	return (KERR_RANDOM_NOERR);
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
			int32_t		status = KERR_RANDOM_NOERR;
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

		if (kern_createMutex(aStrIdSRandom, &vMutex_Reserve_Random[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "rand: create mutx"); exit(EXIT_OS_PANIC); }

		status = stub_random_init();
	}
	RETURN_INT_RESTORE(status);
}

#endif
