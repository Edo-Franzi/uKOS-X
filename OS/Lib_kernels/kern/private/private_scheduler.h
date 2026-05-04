/*
; private_scheduler.
; ==================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Scheduler management.
;
;			Private uKernel variables.
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

#pragma	once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \addtogroup scheduler
 * @{
 */

/*!
 * \defgroup private_scheduler Private Scheduler
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

enum {
		KSCHE_FORCE_SWITCH_NORM = 0u,							// Switching process nprmal
		KSCHE_TIMEOUT_SWITCH_NORM								// Switching process due to a timeaout
};

extern	uintptr_t	*vKern_stackProc[KNB_CORES];				// Process stack (entry point by Trap)

// Prototypes

/*!
 * \brief Connect the current process to a list and change the context
 *
 * \param[in]	force	false process timeout
 *						true force to change the context
 * \param[in]	*list	Ptr on the list
 * \param[in]	bitNb	bit number (flag for suspending)
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
extern	void	scheduler_changeContext(bool force, list_t *list, uint8_t bitNb);

/*!
 * \brief scheduler_callBackFast
 *
 * !!! Normal uKernel logic for dynamic priority management would require to execute
 *     the command local_updateDynaPriority only in uKernel model call-backs ...
 *	   scheduler_callBackSlow
 *	   scheduler_callBackTrap
 *	   To avoid multiple process switches, the dynamic priority is incremented in the scheduler_callBackSlow callback
 *	   This is not optimal but it's the best compromise.
 *
 * - Update the dynamic priority
 * - Verify the timeout condition of the suspended processes
 *
 * \param[in]	time	Suspend the process for a time (1-ms of resolution)
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
extern	void	scheduler_callBackFast(uint32_t time);

/*!
 * \brief scheduler_callBackSlow
 *
 * - Change the context and prepare the next process
 * - INT acknowledge and new time for the next process
 *
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
extern	void	scheduler_callBackSlow(void);

/*!
 * \brief scheduler_callBackTrap
 *
 * - Analysis of the message
 *
 * - Basic services: KKERN_MSG_NO_PARAM
 *	 - KKERN_MSG_JUMP_KERN	force the process switching
 *	 - KKERN_MSG_WAIT_TIME	waiting for a time
 *	 - KKERN_MSG_WAIT_SIGN	waiting for a signal
 *
 * - Semaphore synchronizations: KKERN_MSG_WAIT_SEMA_SYN
 *	 - KKERN_MSG_WAIT_SEMA_SYN		waiting for a semaphore synchro
 *
 * \param[in]	message		Message from the process
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
extern	void	scheduler_callBackTrap(uint32_t message);

/**@}*/
/**@}*/
/**@}*/
