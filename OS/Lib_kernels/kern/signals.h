/*
; signals.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Signal management.
;
;			This module implements the signals primitives.
;
; 			Software signal system calls
; 			----------------------------
;
;			void	signals_init(void);
;			int32_t	kern_createSignalGroup(const char_t *identifier, sign_t **handle);
;			int32_t	kern_createBitSignal(sign_t *handle, uint8_t *bit);
;			int32_t	kern_signalSignal(sign_t *handle, uint32_t signals, proc_t *toProcess, uint32_t mode);
;			int32_t	kern_waitSignal(sign_t *handle, uint32_t *signals, proc_t *fromProcess, uint32_t timeout);
;			int32_t	kern_getWaitingSignalMask(sign_t *handle, uint32_t *waitingSignals);
;			int32_t	kern_clearPendingSignal(sign_t *handle, uint32_t toClearMask);
;			int32_t	kern_killSignalGroup(sign_t *handle);
;			int32_t	kern_killBitSignal(sign_t *handle, uint8_t bitSignal);
;			int32_t	kern_getSignalGroupById(char_t *identifier, sign_t **handle);
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
 * \defgroup signals Signals
 *
 * \brief Signals
 *
 * Signal management
 *
 * @{
 */

#define	KSIGN_NB_SIGNALS_PER_GROUP				32u				// Number of signals per group (always 32 ... uint32_t)
#define	KSIGN_SIGNALE_WITH_CONTEXT_SWITCH		0u				// Signal with the context switching
#define	KSIGN_SIGNALE_WITHOUT_CONTEXT_SWITCH	1u				// Signal without the context switching

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	void	signals_init(void);

/*!
 * \brief Create a signal group
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t      status;
 *          sign_t       *signalGroup;
 * const    char_t       identifier[] = ”Chrono trigger”;
 *
 *    status = kern_createSignalGroup(identifier, &signalGroup);
 * \endcode
 *
 * \param[in]	*identifier		Ptr on the signal group identifier (nullptr = anonymous)
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_SIFUL	No more signal group
 * \return		KERR_KERN_IDSIO	The signal group identifier is already used
 *
 */
extern	int32_t	kern_createSignalGroup(const char_t *identifier, sign_t **handle);

/*!
 * \brief Create a bit signal
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint8_t      bitSignal;
 * sign_t       *signalGroup;
 *
 *    status = kern_createBitSignal(signalGroup, &bitSignal);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	*bitSignal		Ptr on the bitSignal (0..31)
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 * \return		KERR_KERN_NOSIG	No more bitSignal
 *
 */
extern	int32_t	kern_createBitSignal(sign_t *handle, uint8_t *bitSignal);

/*!
 * \brief set the signals
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint32_t     Signals;
 * sign_t       *signalGroup;
 * proc_t       *toProcess;
 *
 *    while (kern_getProcessById(“My process”, &toProcess) != KERR_KERN_NOERR) {
 *        kern_suspendProcess(1u);
 *    }
 *
 * // Mode selective
 *
 *    status = kern_signalSignal(signalGroup, signals, toProcess, KSIGN_SIGNALE_WITH_CONTEXT_SWITCH);
 *
 * // Mode broadcast
 *
 *    status = kern_signalSignal(signalGroup, signals, KKERN_HANDLE_BROADCAST, KSIGN_SIGNALE_WITH_CONTEXT_SWITCH);
 * \endcode
 *
 * - If (mode == KSIGN_SIGNALE_WITH_CONTEXT_SWITCH)
 *   - With the context switching
 *
 * - If (mode == KSIGN_SIGNALE_WITHOUT_CONTEXT_SWITCH)
 *   - Without the context switching
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	signals			Signals
 * \param[in]	*toProcess		Ptr on the process handle (selective signal)
 *								KKERN_HANDLE_BROADCAST, broadcast to all the installed processes the signals
 * \param[in]	mode			KSIGN_SIGNALE_WITH_CONTEXT_SWITCH		-> (synchro with the context switching)
 *								KSIGN_SIGNALE_WITHOUT_CONTEXT_SWITCH	-> (synchro without the context switching)
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
extern	int32_t	kern_signalSignal(sign_t *handle, uint32_t signals, proc_t *toProcess, uint32_t mode);

/*!
 * \brief Wait for the signals
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint32_t     waitSignals;
 * sign_t       *signalGroup;
 * proc_t       *fromProcess;
 *
 * #define    BMYSIGNAL    3
 *
 *    status = kern_getSignalGroupById(“Chrono trigger”, &signalGroup);
 *
 *    waitSignals = (1u<<BMYSIGNAL)
 *    status = kern_waitSignal(signalGroup, &waitSignals, fromProcess, 1000);
 * \endcode
 *
 * - Disconnect a process from the execution list
 * - Connect the process to the signal list
 *
 * \param[in]		*handle			Ptr on the handle
 * \param[in, out]	*signals		Ptr on the signal (1 or more)
 * \param[in]		*fromProcess	Ptr on the process handle (selective signal)
 *									KKERN_HANDLE_BROADCAST, broadcast to all the installed processes the signals
 *									KKERN_HANDLE_FROM_ISR, selective signal coming from an ISR
 * \param[in]		timeout			Timeout (1-ms of resolution)
 *									KWAIT_INFINITY, waiting forever
 *									KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return			KERR_KERN_NOERR	OK
 * \return			KERR_KERN_NOGRO	The signal group does not exist
 * \return			KERR_KERN_NOPRO	The process does not exist
 * \return			KERR_KERN_SIKIL	The signal has been killed (with processes in its list)
 * \return			KERR_KERN_TIMEO	Timeout
 *
 */
extern	int32_t	kern_waitSignal(sign_t *handle, uint32_t *signals, proc_t *fromProcess, uint32_t timeout);

/*!
 * \brief Retrieve the cumulative bits which are requested by all processes for the signal group
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint32_t     signal = 0x00000003
 * sign_t       *signalGroup;
 *
 *    status = kern_getWaitingSignalMask(signalGroup, &signal);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	*waitingSignals	Ptr to variable which will hold resulting bit mask
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 *
 */
extern	int32_t kern_getWaitingSignalMask(sign_t *handle, uint32_t *waitingSignals);

/*!
 * \brief Clear pending signals for the process in the signal group
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint32_t     mask = 0x00000003
 * sign_t       *signalGroup;
 *
 *    status = kern_clearPendingSignal(signalGroup, mask);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	toClearMask		Signal bit-mask to clear
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 *
 */
extern	int32_t kern_clearPendingSignal(sign_t *handle, uint32_t toClearMask);

/*!
 * \brief Kill the signal group
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * sign_t       *signalGroup;
 *
 *    status = kern_killSignalGroup(signalGroup);
 * \endcode
 *
 * - If (process still connected to the signal list)
 *   - Then return error
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal does not exist
 *
 */
extern	int32_t	kern_killSignalGroup(sign_t *handle);

/*!
 * \brief Kill a bit signal
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint8_t      bitSignal;
 * sign_t       *signalGroup;
 *
 *    status = kern_killBitSignal(signalGroup, bitSignal);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	*bitSignal		Ptr on the bitSignal (0..31)
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 *
 */
extern	int32_t	kern_killBitSignal(sign_t *handle, uint8_t bitSignal);

/*!
 * \brief Get the handle of an signal group by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t      status;
 *          sign_t       *signalGroup;
 * const    char_t       identifier[] = ”Signal 0”;
 *
 *    status = kern_getSignalGroupById(identifier, &signalGroup);
 * \endcode
 *
 * - This function returns the handle of the signal
 *
 * \param[in]	*identifier		Ptr on the signal group identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 *
 */
extern	int32_t	kern_getSignalGroupById(const char_t *identifier, sign_t **handle);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
