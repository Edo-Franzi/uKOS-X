/*
; preciseSignals.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Precise signals.
;
;			This module implements the software primitives.
;
; 			Precise signal system calls
; 			---------------------------
;
;			void	preciseSignals_init(void);
;			int32_t	kern_createPreciseSignal(const char_t *identifier, prcs_t **handle);
;			int32_t	kern_setPreciseSignal(prcs_t *handle, sign_t **sigGroup, proc_t *toProcess, uint64_t period, uint8_t mode, uint32_t signal);
;			int32_t	kern_killPreciseSignal(prcs_t *handle);
;			int32_t	kern_getPreciseSignalById(const char_t *identifier, prcs_t **handle);
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
#include	"kern/private/private_preciseSignals.h"
#include	"kern/private/private_processes.h"
#include	"kern/private/private_identifiers.h"
#include	"kern/private/private_lists.h"

#if (KKERN_NB_PRECISE_SIGNALS > 0)

prcs_t		vKern_prcs[KNB_CORES][KKERN_NB_PRECISE_SIGNALS];
uint16_t	vKern_nbPrcs[KNB_CORES];
uint16_t	vKern_nbMaxPrcs[KNB_CORES];
sign_t		*vDefaultSignalGroup[KNB_CORES];

/*
 * \brief Initialise the manager
 *
 * - This function initialises the "preciseSignals" manager
 *   Before using the manager functions, it is necessary to
 *   call this function
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	preciseSignals_init(void) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

// Create and configure the precise signal signal group

	if (kern_createSignalGroup(KPRCS_DEFAULT_SIGNAL_GROUP, &vDefaultSignalGroup[core]) != KERR_KERN_NOERR) { LOG(KFATAL_KERNEL, "prcs: create prcs"); exit(EXIT_OS_FAILURE); }

	for (i = 0u; i < KKERN_NB_PRECISE_SIGNALS; i++) {
		vKern_prcs[core][i].oIdentifier	 = nullptr;
		vKern_prcs[core][i].oState		 = 0u;
		vKern_prcs[core][i].oMode		 = KPRCS_STOP;
		vKern_prcs[core][i].oSignalGroup = vDefaultSignalGroup[core];
		vKern_prcs[core][i].oToProcess	 = nullptr;
		vKern_prcs[core][i].oSignal		 = 0u;
		vKern_prcs[core][i].oPeriod		 = 0u;
		vKern_prcs[core][i].oNextTime	 = 0u;
	}

	vKern_nbPrcs[core]	  = 0u;
	vKern_nbMaxPrcs[core] = 0u;
	DEBUG_KERN_TRACE("exit: OK");
}

/*
 * \brief Create a precise signal
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          prcs_t     *preciseSignal;
 * const    char_t     identifier[] = ”Top acquisition”;
 *
 *    status = kern_createPreciseSignal(identifier, &preciseSignal);
 * \endcode
 *
 * \param[in]	*identifier		Ptr on the precise signal identifier (nullptr = anonymous)
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_PRFUL	No more precise signal
 * \return		KERR_KERN_IDPRC	The precise signal identifier is already used
 *
 */
int32_t	kern_createPreciseSignal(const char_t *identifier, prcs_t **handle) {
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
		for (i = 0u; i < KKERN_NB_PRECISE_SIGNALS; i++) {
			if (identifiers_cmpStrings(vKern_prcs[core][i].oIdentifier, identifier) == true) {
				*handle = &vKern_prcs[core][i];
				DEBUG_KERN_TRACE("exit: KO 1");
				INTERRUPTION_RESTORE;
				PRIVILEGE_RESTORE;
				return (KERR_KERN_IDPRC);
			}

		}
	}

	for (i = 0u; i < KKERN_NB_PRECISE_SIGNALS; i++) {
		if (vKern_prcs[core][i].oIdentifier == nullptr) {
			vKern_prcs[core][i].oIdentifier  = (identifier == nullptr) ? (KPRCS_ANONYMOUS_ID) : (identifier);
			vKern_prcs[core][i].oState		 = (1u<<BPRCS_INSTALLED);
			vKern_prcs[core][i].oMode		 = KPRCS_STOP;
			vKern_prcs[core][i].oSignalGroup = vDefaultSignalGroup[core];
			vKern_prcs[core][i].oToProcess	 = nullptr;
			vKern_prcs[core][i].oSignal		 = 0u;
			vKern_prcs[core][i].oPeriod		 = 0u;
			vKern_prcs[core][i].oNextTime	 = 0u;
			*handle = &vKern_prcs[core][i];

			vKern_nbPrcs[core]    = (uint16_t)(vKern_nbPrcs[core] + 1u);
			vKern_nbMaxPrcs[core] = (vKern_nbPrcs[core] > vKern_nbMaxPrcs[core]) ? (vKern_nbPrcs[core]) : (vKern_nbMaxPrcs[core]);
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 2");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_PRFUL);
}

/*
 * \brief Set a precise signal
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KTOPACQ    (1u<<0) | (1u<<28)
 *
 *    static  void     aProcess(const void *argument) {
 *        uint32_t     signal;
 *        prcs_t       *preciseSignal;
 *        proc_t       *process23;
 *        sign_t       *oSignalGroup = nullptr;
 *
 *        // In this example the "signal" is hard-coded. The user can also use the
 *        // system call kern_createBitSignal to automatically obtain a signal.
 *        //
 *        // Create and initialise a precise signal "Test_prcs"
 *        //     Continuous run, period = 200-us, generate the signals (1u<<0) | (1u<<28) on the default signal group, selectively to the process 23
 *
 *        if (kern_createPreciseSignal("Test_prcs", &preciseSignal)                                         != KERR_KERN_NOERR) { exit(EXIT_OS_FAILURE); }
 *        if (kern_setPreciseSignal(preciseSignal, &signalGroup, process23, 200, KPRCS_CONTINUOUS, KTOPACQ) != KERR_KERN_NOERR) { exit(EXIT_OS_FAILURE); }
 *
 *        while (true) {
 *
 *        // Waiting for the signal (1u<<0) coming from the ISR (always the case)
 *
 *            signal = (1u<<0);
 *            kern_waitSignal(signalGroup, &signal, KKERN_HANDLE_FROM_ISR, KWAIT_INFINITY);
 *            led_toggle(KLED_0);
 *        }
 *    }
 * \endcode
 *
 * \param[in]		*handle			Ptr on the handle
 * \param[in, out]	**sigGroup		Ptr on the sigGroup handle. Set variable to nullptr for the default group
 * \param[in]		*toProcess		Ptr on the process handle (selective signal)
 * \param[in]		-				KKERN_HANDLE_BROADCAST, broadcast to all the installed processes the signals
 * \param[in]		period			Time period in us
 * \param[in]		mode			KPRCS_STOP			-> stop the ongoing timer
 * \param[in]		-				KPRCS_SINGLE_SHOT	-> single shot timer
 * \param[in]		-				KPRCS_CONTINUOUS	-> continuous timer
 * \param[in]		signal			Signal(s) to generate
 * \return			KERR_KERN_NOERR	OK
 * \return			KERR_KERN_NOPRC	The precise signal does not exist
 *
 */
int32_t	kern_setPreciseSignal(prcs_t *handle, sign_t **sigGroup, proc_t *toProcess, uint64_t period, uint8_t mode, uint32_t signal) {
	uint32_t	core;
	prcs_t		*preciseSignal;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	preciseSignal = handle;
	if (preciseSignal == nullptr)							   { *sigGroup = nullptr; DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRC); }
	if ((preciseSignal->oState & (1u<<BPRCS_INSTALLED)) == 0u) { *sigGroup = nullptr; DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRC); }

	preciseSignal->oMode  		= mode;
	preciseSignal->oSignalGroup = (*sigGroup == nullptr) ? (vDefaultSignalGroup[core]) : (*sigGroup);
	preciseSignal->oToProcess	= toProcess;
	preciseSignal->oSignal		= signal;
	preciseSignal->oPeriod		= period;
	*sigGroup					= preciseSignal->oSignalGroup;

	stub_kern_setPreciseSignal(preciseSignal);

	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Kill the precise signal
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * prcs_t     *preciseSignal;
 *
 *    status = kern_killPreciseSignal(preciseSignal);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRC	The precise signal does not exist
 *
 */
int32_t	kern_killPreciseSignal(prcs_t *handle) {
	prcs_t		*preciseSignal;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	preciseSignal = handle;
	if (preciseSignal == nullptr)							   { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRC); }
	if ((preciseSignal->oState & (1u<<BPRCS_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRC); }

	preciseSignal->oIdentifier	= nullptr;
	preciseSignal->oState		= 0u;
	preciseSignal->oMode		= KPRCS_STOP;
	preciseSignal->oSignalGroup	= nullptr;
	preciseSignal->oToProcess	= nullptr;
	preciseSignal->oSignal		= 0u;
	preciseSignal->oPeriod		= 0u;
	preciseSignal->oNextTime	= 0u;

	if (vKern_nbPrcs[core] != 0u) { vKern_nbPrcs[core] = (uint16_t)(vKern_nbPrcs[core] - 1u); }
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Get the handle of a precise signal by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          prcs_t     *preciseSignal;
 * const    char_t     identifier[] = ”Top acquisition”;
 *
 *    status = kern_getPreciseSignalById(identifier, &softwareTimer);
 * \endcode
 *
 * - This function returns the handle of the precise signal
 *
 * \param[in]	*identifier		Ptr on the precise signal identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRC	The precise signal does not exist
 *
 */
int32_t	kern_getPreciseSignalById(const char_t *identifier, prcs_t **handle) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

	for (i = 0u; i < KKERN_NB_PRECISE_SIGNALS; i++) {
		if (identifiers_cmpStrings(vKern_prcs[core][i].oIdentifier, identifier) == true) {
			*handle = &vKern_prcs[core][i];
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 1");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOPRC);
}
#endif
