/*
; softwareTimers.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Software timers.
;
;			This module implements the software primitives.
;
;			Software timer system calls
;			---------------------------
;
;			void	softwareTimers_init(void);
;			int32_t	kern_createSoftwareTimer(const char_t *identifier, stim_t **handle);
;			int32_t	kern_setSoftwareTimer(stim_t *handle, const tspc_t *configure);
;			int32_t	kern_killSoftwareTimer(stim_t *handle);
;			int32_t	kern_getSoftwareTimerById(const char_t *identifier, stim_t **handle);
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
#include	"kern/private/private_kern.h"
#include	"kern/private/private_softwareTimer.h"
#include	"kern/private/private_processes.h"
#include	"kern/private/private_identifiers.h"
#include	"kern/private/private_lists.h"

#if (KKERN_NB_SOFTWARE_TIMERS > 0)
#define	KNB_MAX_STIM_IN_QUEUE	10u

stim_t		vKern_stim[KNB_CORES][KKERN_NB_SOFTWARE_TIMERS];
uint16_t	vKern_nbStim[KNB_CORES];
uint16_t	vKern_nbMaxStim[KNB_CORES];
uint16_t	vKern_curStim[KNB_CORES];

/*
 * \brief Initialise the manager
 *
 * - This function initialises the "softwareTimers" manager
 *   Before using the manager functions, it is necessary to
 *   call this function
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	softwareTimers_init(void) {
	uint16_t	i;
	uint32_t	core;
	mcnf_t		configure;
	mbox_t		*mailBox;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	for (i = 0u; i < KKERN_NB_SOFTWARE_TIMERS; i++) {
		vKern_stim[core][i].oIdentifier				= nullptr;
		vKern_stim[core][i].oState					= 0u;
		vKern_stim[core][i].oInitCounter			= 0u;
		vKern_stim[core][i].oCounter				= 0u;
		vKern_stim[core][i].oTimerSpec.oMode		= KSTIM_STOP;
		vKern_stim[core][i].oTimerSpec.oInitialTime	= 0u;
		vKern_stim[core][i].oTimerSpec.oTime		= 0u;
		vKern_stim[core][i].oTimerSpec.oArgument	= nullptr;
		vKern_stim[core][i].oTimerSpec.oCode		= nullptr;
	}

// Create and configure the software timer queue

	configure.oNbMaxPacks	 = KNB_MAX_STIM_IN_QUEUE;
	configure.oDataEntrySize = 0u;

	if (kern_createMailbox(KMBOX_SOFTWARE_TIMER, &mailBox) != KERR_KERN_NOERR) { LOG(KFATAL_KERNEL, "stim: create mailbox"); exit(EXIT_OS_PANIC); }
	if (kern_setMailbox(mailBox, &configure)               != KERR_KERN_NOERR) { LOG(KFATAL_KERNEL, "stim: set mailbox");	 exit(EXIT_OS_PANIC); }

	vKern_nbStim[core]	  = 0u;
	vKern_nbMaxStim[core] = 0u;
	DEBUG_KERN_TRACE("exit: OK");
}

/*
 * \brief Create a software timer
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          stim_t     *softwareTimer;
 * const    char_t     identifier[] = ”Timer acquisition”;
 *
 *    status = kern_createSoftwareTimer(identifier, &softwareTimer);
 * \endcode
 *
 * \param[in]	*identifier		Ptr on the software timer identifier (nullptr = anonymous)
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_STFUL	No more software timer
 * \return		KERR_KERN_IDSTI	The software timer identifier is already used
 *
 */
int32_t	kern_createSoftwareTimer(const char_t *identifier, stim_t **handle) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

// Check if the identifier is already used (nullptr = anonymous)
// If the identifier is already used, then, return an error but
// with the handle of the previously created object

	if (identifier != nullptr) {
		for (i = 0u; i < KKERN_NB_SOFTWARE_TIMERS; i++) {
			if (identifiers_cmpStrings(vKern_stim[core][i].oIdentifier, identifier) == true) {
				*handle = &vKern_stim[core][i];
				DEBUG_KERN_TRACE("exit: KO 1");
				INTERRUPTION_RESTORE;
				PRIVILEGE_RESTORE;
				return (KERR_KERN_IDSTI);
			}

		}
	}

	for (i = 0u; i < KKERN_NB_SOFTWARE_TIMERS; i++) {
		if (vKern_stim[core][i].oIdentifier == nullptr) {
			vKern_stim[core][i].oIdentifier				= (identifier == nullptr) ? (KSTIM_ANONYMOUS) : (identifier);
			vKern_stim[core][i].oState					= (1u<<BSTIM_INSTALLED);
			vKern_stim[core][i].oInitCounter			= 0u;
			vKern_stim[core][i].oCounter				= 0u;
			vKern_stim[core][i].oTimerSpec.oMode		= KSTIM_STOP;
			vKern_stim[core][i].oTimerSpec.oInitialTime	= 0u;
			vKern_stim[core][i].oTimerSpec.oTime		= 0u;
			vKern_stim[core][i].oTimerSpec.oArgument	= nullptr;
			vKern_stim[core][i].oTimerSpec.oCode		= nullptr;
			*handle = &vKern_stim[core][i];

			vKern_nbStim[core]    = (uint16_t)(vKern_nbStim[core] + 1);
			vKern_nbMaxStim[core] = (vKern_nbStim[core] > vKern_nbMaxStim[core]) ? (vKern_nbStim[core]) : (vKern_nbMaxStim[core]);
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 2");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_STFUL);
}

/*
 * \brief Set a software timer
 *
 * Call example in C:
 *
 * \code{.c}
 * static     void    _changeStateLed(void);
 *
 * int32_t    status;
 * tspc_t     configure;
 * stim_t     *softwareTimer;
 *
 *    configure.oMode        = KSTIM_CONTINUOUS;
 *    configure.oInitialTime = 10000;
 *    configure.oTime        = 1000;
 *    configure.oArgument    = nullptr;
 *    configure.oCode        = _changeStateLed;
 *
 *    status = kern_setSoftwareTimer(softwareTimer, &configure);
 *
 *    // My callback routine
 *
 *    static    void    _changeStateLed(void) {
 *
 *        led_toggle(KLED_0);
 *    }
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSTI	The software timer does not exist
 * \return		KERR_KERN_CFSTI	The software timer cannot be configured
 *
 */
int32_t	kern_setSoftwareTimer(stim_t *handle, const tspc_t *configure) {
			uint32_t	core;
			mbox_t		*mailBox;
			uint8_t		i;
	static	uint8_t		vI[KNB_CORES] = MCSET(0u);
	static	stim_t		*vSoftTimer[KNB_CORES][KNB_MAX_STIM_IN_QUEUE + 1u];

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	i = vI[core];
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	vSoftTimer[core][i] = handle;
	if (vSoftTimer[core][i] == nullptr)								 { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOSTI); }
	if ((vSoftTimer[core][i]->oState & (1u<<BSTIM_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOSTI); }

	vSoftTimer[core][i]->oInitCounter			 = configure->oInitialTime / KKERN_TIC_TIME;
	vSoftTimer[core][i]->oCounter				 = configure->oTime	/ KKERN_TIC_TIME;
	vSoftTimer[core][i]->oTimerSpec.oMode		 = configure->oMode;
	vSoftTimer[core][i]->oTimerSpec.oInitialTime = configure->oInitialTime / KKERN_TIC_TIME;
	vSoftTimer[core][i]->oTimerSpec.oTime		 = configure->oTime	/ KKERN_TIC_TIME;
	vSoftTimer[core][i]->oTimerSpec.oArgument	 = configure->oArgument;
	vSoftTimer[core][i]->oTimerSpec.oCode		 = configure->oCode;
	vSoftTimer[core][i]->oState					|= (1u<<BSTIM_RE_CONFIGURED);

// Prepare the pack for the software timer process

	if (kern_getMailboxById(KMBOX_SOFTWARE_TIMER, &mailBox) == KERR_KERN_NOERR) {
		if (kern_writeQueue(mailBox, (uintptr_t)vSoftTimer[core][i], 0u) == KERR_KERN_NOERR) {

			vI[core]++;
			vI[core] = (vI[core] == (KNB_MAX_STIM_IN_QUEUE + 1u)) ? (0u) : (vI[core]);

// If the software timer process is suspended for ever, then, relaunch it

			if ((vStimer_handle[core]->oInternal.oState & (1u<<BPROC_LIKE_ISR)) == 0u) {
				vStimer_handle[core]->oInternal.oTimeout = 0u;
			}
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;

			temporal_testEOTime(0u);
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 3");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_CFSTI);
}

/*
 * \brief Kill the software timer
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * stim_t     *softwareTimer;
 *
 *    status = kern_killSoftwareTimer(softwareTimer);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSTI	The software timer does not exist
 *
 */
int32_t	kern_killSoftwareTimer(stim_t *handle) {
	uint32_t	core;
	stim_t		*softwareTimer;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	softwareTimer = handle;
	if (softwareTimer == nullptr)							   { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOSTI); }
	if ((softwareTimer->oState & (1u<<BSTIM_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOSTI); }

	softwareTimer->oIdentifier			   = nullptr;
	softwareTimer->oState				   = 0u;
	softwareTimer->oInitCounter			   = 0u;
	softwareTimer->oCounter				   = 0u;
	softwareTimer->oTimerSpec.oMode		   = KSTIM_STOP;
	softwareTimer->oTimerSpec.oInitialTime = 0u;
	softwareTimer->oTimerSpec.oTime		   = 0u;
	softwareTimer->oTimerSpec.oArgument	   = nullptr;
	softwareTimer->oTimerSpec.oCode		   = nullptr;

	if (vKern_nbStim[core] != 0u) { vKern_nbStim[core] = (uint16_t)(vKern_nbStim[core] - 1u); }
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Get the handle of a software timer by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          stim_t     *softwareTimer;
 * const    char_t     identifier[] = ”Timer acquisition”;
 *
 *    status = kern_getSoftwareTimerById(identifier, &softwareTimer);
 * \endcode
 *
 * - This function returns the handle of the software timer
 *
 * \param[in]	*identifier		Ptr on the software timer identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSTI	The software timer does not exist
 *
 */
int32_t	kern_getSoftwareTimerById(const char_t *identifier, stim_t **handle) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

	for (i = 0u; i < KKERN_NB_SOFTWARE_TIMERS; i++) {
		if (identifiers_cmpStrings(vKern_stim[core][i].oIdentifier, identifier) == true) {
			*handle = &vKern_stim[core][i];
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 1");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOSTI);
}
#endif
