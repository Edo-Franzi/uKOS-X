/*
; tusb_os_custom.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		uKOS OS interface between uKOS-X & TinyUSB.
;
;			Work based on an preliminary initial version
;			written by Jean-Marc Koller.
;
;   (c) 2019 Ha Thach (tinyusb.org)
;   -------------------------------
;
;   The MIT License (MIT)
;
;   Permission is hereby granted, free of charge, to any person obtaining a copy
;   of this software and associated documentation files (the "Software"), to deal
;   in the Software without restriction, including without limitation the rights
;   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
;   copies of the Software, and to permit persons to whom the Software is
;   furnished to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be included in
;   all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
;   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
;   THE SOFTWARE.
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

#include	"osal_kern_interface.h"

// Save the GCC diagnostic
//
#pragma GCC diagnostic	push

// Ignore the GCC diagnostic
//
#pragma GCC diagnostic	ignored	"-Wpedantic"
#include	"tusb.h"

// Restore the GCC diagnostic
//
#pragma GCC	diagnostic	pop

/*
 * \brief board_millis
 *
 * - Return the number of milli-seconds
 *	 This call is not used but it is in place
 *	 to allow the compilation
 *
 */
uint32_t	board_millis(void) {
	uint64_t	time;

	kern_readTickCount(&time);
	time = time / 1000u;
	return ((uint32_t)time);
}

/*
 * \brief board_get_unique_id
 *
 * - No idea
 *
 */
size_t	board_get_unique_id(uint8_t id[], size_t max_len) {

	UNUSED(id);
	UNUSED(max_len);

	return (0u);
}

/*
 * \brief osal_task_delay
 *
 * - Wait in ms
 *
 */
void	osal_task_delay(uint32_t msec) {

	kern_suspendProcess(msec);
}

/*
 * \brief osal_time_millis
 *
 * - Time elapsed in ms
 *
 */
uint32_t	osal_time_millis(void) {
	uint64_t	time;

	kern_readTickCount(&time);
	return ((uint32_t)(time / 1000u));
}

/*
 * \brief osal_semaphore_create
 *
 * - Create an anonymous synchro semaphore
 *
 */
osal_semaphore_t	osal_semaphore_create(osal_semaphore_def_t *semdef) {
	sema_t	*handle = nullptr;

	UNUSED(semdef);

	if (kern_createSemaphore(nullptr, 0, 1, &handle) == KERR_KERN_NOERR) {
		return ((osal_semaphore_t)(handle));
	}

	return (nullptr);
}

/*
 * \brief osal_semaphore_post
 *
 * - Signal the synchro semaphore
 *
 */
bool	osal_semaphore_post(osal_semaphore_t sem_hdl, bool in_isr) {
	bool	status;

	UNUSED(in_isr);

	status = (kern_signalSemaphore((sema_t *)sem_hdl) == KERR_KERN_NOERR) ? (true) : (false);
	return (status);
}

/*
 * \brief osal_semaphore_wait
 *
 * - Waiting for the synchro semaphore
 *
 */
bool	osal_semaphore_wait(osal_semaphore_t sem_hdl, uint32_t msec) {
	bool	status;

	UNUSED(msec);

	status = (kern_waitSemaphore((sema_t *)sem_hdl, 0u) == KERR_KERN_NOERR) ? (true) : (false);
	return (status);
}

/*
 * \brief osal_semaphore_reset
 *
 * - Restart the synchro semaphore
 *
 */
void	osal_semaphore_reset(osal_semaphore_t sem_hdl) {

	kern_restartSemaphore((sema_t *)sem_hdl);
}

/*
 * \brief osal_mutex_create
 *
 * - Create an anonymous mutex semaphore
 *
 */
osal_mutex_t osal_mutex_create(osal_mutex_def_t *mdef) {
	mutx_t	*handle = nullptr;

	UNUSED(mdef);

	if (kern_createMutex(nullptr, &handle) == KERR_KERN_NOERR) {
	    return ((osal_mutex_t)(handle));
	}

	return (nullptr);
}

/*
 * \brief osal_mutex_delete
 *
 * - Delete an anonymous mutex semaphore
 *
 */
bool osal_mutex_delete(osal_mutex_t mutex_hdl) {

	kern_killMutex((mutx_t *)mutex_hdl);
	return (true);
}

/*
 * \brief osal_mutex_lock
 *
 * - Lock the mutex semaphore
 *
 */
bool osal_mutex_lock(osal_mutex_t mutex_hdl, uint32_t msec) {
	bool	status;

	status = (kern_lockMutex((mutx_t *)mutex_hdl, msec) == KERR_KERN_NOERR) ? (true) : (false);
	return (status);
}

/*
 * \brief osal_mutex_unlock
 *
 * - Unlock the mutex semaphore
 *
 */
bool osal_mutex_unlock(osal_mutex_t mutex_hdl) {
	bool	status;

	status = (kern_unlockMutex((mutx_t *)mutex_hdl) == KERR_KERN_NOERR) ? (true) : (false);
	return (status);
}

/*
 * \brief osal_queue_create
 *
 * - Create an anonymous queue
 *
 */
osal_queue_t osal_queue_create(osal_queue_def_t *qdef) {
	const	mcnf_t	cnf = {
						.oNbMaxPacks    = (uint32_t)qdef->depth,
						.oDataEntrySize = (uint32_t)qdef->item_sz
					};
			mbox_t	*handle = nullptr;

	if (kern_createMailbox(nullptr, &handle) == KERR_KERN_NOERR) {
		if (kern_setMailbox(handle, &cnf) == KERR_KERN_NOERR) {
	       return ((osal_queue_t)(handle));
		}

		kern_killMailbox(handle);
	}
	return (nullptr);
}

/*
 * \brief osal_queue_receive
 *
 * - Receive data from the queue
 *
 */
bool	osal_queue_receive(osal_queue_t qhdl, void *data, uint32_t msec) {
	bool		status;
	uint32_t	size, timeout;
	mbox_t		*handle = (mbox_t *)qhdl;

	timeout = (msec == UINT32_MAX) ? (KWAIT_INFINITY) : (msec);

	size = handle->oDataEntrySize;
	status = (kern_readMailbox(handle, &data, &size, timeout) == KERR_KERN_NOERR) ? (true) : (false);
	return (status);
}

/*
 * \brief osal_queue_send
 *
 * - Send data to the queue
 *
 */
#pragma GCC diagnostic  push
#if (defined(__clang__))
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"

#else
#pragma GCC diagnostic  ignored "-Wdiscarded-qualifiers"
#endif
bool	osal_queue_send(osal_queue_t qhdl, void const *data, bool in_isr) {
	bool	status;
	mbox_t	*handle = (mbox_t *)qhdl;

	UNUSED(in_isr);

	status = (kern_writeMailbox((mbox_t *)qhdl, data, handle->oDataEntrySize, 0u) == KERR_KERN_NOERR) ? (true) : (false);
	return (status);
}
#pragma GCC diagnostic  pop

/*
 * \brief osal_queue_empty
 *
 * - Check if the queue is empty
 *
 */
bool	osal_queue_empty(osal_queue_t qhdl) {
	bool	status;
	mbox_t	*handle = (mbox_t *)qhdl;

	status = ((handle->oState & (1u<<BMBOX_EMPTY)) != 0u) ? (true) : (false);
	return (status);
}

/*
 * \brief osal_queue_delete
 *
 * - Delete the queue
 *
 */
bool	osal_queue_delete(osal_queue_t qhdl) {
	bool	status;

	status = (kern_killMailbox((mbox_t *)qhdl) == KERR_KERN_NOERR) ? (true) : (false);
	return (status);
}
