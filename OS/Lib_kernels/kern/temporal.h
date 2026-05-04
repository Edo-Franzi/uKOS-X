/*
; temporal.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - time management.
;
;			This module implements the temporal and the call-back primitives.
;
; 			Temporal system calls
; 			---------------------
;
;			void	temporal_init(void);
;			int32_t	kern_suspendProcess(uint32_t time);
;			int32_t	kern_setNewTimeout(proc_t *handle, uint32_t timeout);
;			int32_t	kern_resumeProcessWithTimeout(proc_t *handle);
;			int32_t	kern_readRemainingProcessTimeout(uint32_t *timeout);
;			int32_t	kern_switchFast(void);
;			int32_t	kern_readTickCount(uint64_t *tickCount);
;			int32_t	kern_waitAtLeast(uint16_t time);
;			int32_t	kern_hasPendingTimeoutProcesses(bool *nonInfTOActive);
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
 * \defgroup temporal Temporal
 *
 * \brief Temporal
 *
 * Temporal management
 *
 * @{
 */

#define	KWAIT_INFINITY			((uint32_t)(-1))				// Waiting forever
#define	KWAIT_REMAINING_TIMEOUT	((uint32_t)(-2))				// Waiting for the remaining timeout

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	void	temporal_init(void);
extern	void	temporal_testEOTime(uint32_t time);

/*!
 * \brief Suspend the process for a time
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KWAIT312MS    312    // Wait for 312-ms
 *
 * int32_t    status;
 *
 *    status = kern_suspendProcess(KWAIT312MS);
 * \endcode
 *
 * - Disconnect a process from the execution list
 * - Connect the process to the time list
 *
 * \param[in]	time			Suspend the process for a time (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_FRISR	Execution from ISR
 *
 */
extern	int32_t	kern_suspendProcess(uint32_t time);

/*!
 * \brief Set a new timeout
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KWAIT312MS    312    // Wait for 312-ms
 *
 * proc_t     *process;
 * int32_t    status;
 *
 *    status = kern_setNewTimeout(nullptr, KWAIT312MS);
 * \endcode
 *
 * - Just change the internal timeout counter
 * - Do not de-schedule the process
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	timeout			Set a new timeout (1-ms of resolution)
 *								Set with KWAIT_INFINITY, waiting forever
 *								Set with KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
extern	int32_t	kern_setNewTimeout(proc_t *handle, uint32_t timeout);

/*!
 * \brief Restore a waiting process by forcing a timeout
 *
 * Resume a process waiting on an event (elapsed time (suspend), semaphore,
 * signal, ...) before its time with a KERR_KERN_TIMEO status.
 *
 * \note: This will distort the timing of a process relying upon an adequate
 * time-out interval.
 *
 * Call example in C:
 *
 * \code{.c}
 * proc_t      *process;
 * int32_t     status;
 *
 *    status = kern_resumeProcessWithTimeout(process);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 * \return		KERR_KERN_TIMEO	Timeout
 *
 */
extern	int32_t	kern_resumeProcessWithTimeout(proc_t *handle);

/*!
 * \brief Read the remaining process timeout
 *
 * Call example in C:
 *
 * \code{.c}
 *
 * int32_t     status;
 * uint32_t    timeout;
 *
 *    status = kern_readRemainingProcessTimeout(&timeout);
 * \endcode
 *
 * \param[in]	*timeout		Ptr on the timeout
 * \return		KERR_KERN_NOERR	OK
 *
 */
extern	int32_t	kern_readRemainingProcessTimeout(uint32_t *timeout);

/*!
 * \brief Force the context switching
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = kern_switchFast();
 * \endcode
 *
 * - Force a context switch
 *
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_FRISR	Execution from ISR
 *
 */
extern	int32_t	kern_switchFast(void);

/*!
 * \brief Read the tickCount (1-us) from the start of the uKernel
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint64_t    tickCount;
 *
 *    status = kern_readTickCount(&tickCount);
 * \endcode
 *
 * - Return the 1-us tickCount value from the start of the uKernel
 *
 * \param[out]	*tickCount		Ptr on the tickCount
 * \return		KERR_KERN_NOERR	OK
 *
 */
extern	int32_t	kern_readTickCount(uint64_t *tickCount);

/*!
 * \brief Waiting for short times (at least ... a certain time)
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KWAITMIN    120    // Wait at least 120-µs
 *
 * int32_t    status;
 *
 *    status = kern_waitAtLeast(KWAITMIN);
 * \endcode
 *
 * - Return when the time is reached. Max. 65536-us
 *   This call ensure the minimum time but not the maximum
 *
 * \param[in]	time			Suspend the process for a time (1-us of resolution)
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_FRISR	Execution from ISR
 *
 */
extern	int32_t	kern_waitAtLeast(uint16_t time);

/*!
 * \brief Check if a waiting process has a timeout set
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * bool      nonInfTOActive;
 *
 *    status = kern_hasPendingTimeoutProcesses(&nonInfTOActive);
 * \endcode
 *
 * - This functions scans the currently waiting processes and check
 *   if all timeouts are infinite or not
 *
 * \param[out]	*nonInfTOActive	Non infinite active timeout
 *								true, If a non-infinite timeout is active
 *								false, All waiting processes have an KWAIT_INFINITY timeout
 * \return		KERR_KERN_NOERR	OK
 *
 */
extern	int32_t	kern_hasPendingTimeoutProcesses(bool *nonInfTOActive);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
