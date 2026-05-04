/*
; semaphores.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Semaphore management.
;
;			This module implements the semaphore primitives.
;
;			Semaphore system calls
;			----------------------
;
;			void	semaphores_init(void);
;			int32_t	kern_createSemaphore(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, sema_t **handle);
;			int32_t	kern_signalSemaphore(sema_t *handle);
;			int32_t	kern_waitSemaphore(sema_t *handle, uint32_t timeout);
;			int32_t	kern_killSemaphore(sema_t *handle);
;			int32_t	kern_restartSemaphore(sema_t *handle);
;			int32_t	kern_getSemaphoreById(const char_t identifier, sema_t **handle);
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
 * \defgroup semaphores Semaphores
 *
 * \brief Semaphores
 *
 * Semaphore management
 *
 * @{
 */

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	void	semaphores_init(void);

/*!
 * \brief Create a generic semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          int32_t    iniCounter = 5;
 *          int32_t    maxCounter = 1;
 *          sema_t     *semaphore;
 * const    char_t     identifier[] = ”Semaphore 0”;
 *
 *    status = kern_createSemaphore(identifier, iniCounter, maxCounter, &semaphore);
 * \endcode
 *
 * \param[in]	*identifier		Ptr on the semaphore identifier (nullptr = anonymous)
 * \param[in]	iniCounter		Initial counter value
 * \param[in]	maxCounter		Max counter value
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_SEFUL	No more semaphore
 * \return		KERR_KERN_IDSEM	The semaphore identifier is already used
 *
 */
extern	int32_t	kern_createSemaphore(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, sema_t **handle);

/*!
 * \brief Signal a semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_signalSemaphore(semaphore);
 * \endcode
 *
 * - counter++
 * - If (counter <= 0)
 *   - Then disconnect the first process from the semaphore list (accordingly to the number of events)
 *   - Connect the process to the execution list
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 * \return		KERR_KERN_SETME	The semaphore counts too many events
 *
 */
extern	int32_t	kern_signalSemaphore(sema_t *handle);

/*!
 * \brief Wait for a semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_waitSemaphore(semaphore, timeout);
 * \endcode
 *
 * - counter -= 1
 * - If (counter < 0)
 *   - Then suspend the process
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 * \return		KERR_KERN_SETME	The semaphore counts too many events
 * \return		KERR_KERN_SEKIL	The semaphore has been killed (with processes in its list)
 * \return		KERR_KERN_TIMEO	Timeout
 *
 */
extern	int32_t	kern_waitSemaphore(sema_t *handle, uint32_t timeout);

/*!
 * \brief Kill the semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_killSemaphore(semaphore);
 * \endcode
 *
 * - If (process still connected to the semaphore list)
 *   - Then return error
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 *
 */
extern	int32_t	kern_killSemaphore(sema_t *handle);

/*!
 * \brief Restart the semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_restartSemaphore(semaphore);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 *
 */
extern	int32_t	kern_restartSemaphore(sema_t *handle);

/*!
 * \brief Get the handle of a semaphore by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          sema_t     *semaphore;
 * const    char_t     identifier[] = ”Semaphore 0”;
 *
 *    status = kern_getSemaphoreById(identifier, &semaphore);
 * \endcode
 *
 * - This function returns the handle of the semaphore
 *
 * \param[in]	*identifier		Ptr on the semaphore identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 *
 */
extern	int32_t	kern_getSemaphoreById(const char_t *identifier, sema_t **handle);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
