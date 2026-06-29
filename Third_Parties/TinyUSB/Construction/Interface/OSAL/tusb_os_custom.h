/*
; tusb_os_custom.
; ===============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2019 Ha Thach (tinyusb.org)
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

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

#pragma	once

#include	"osal_kern_interface.h"

extern	uint32_t	SystemCoreClock;

typedef struct {
	uint16_t	depth;
	uint16_t	item_sz;
} osal_queue_def_t;

typedef	uint8_t					osal_semaphore_def_t;
typedef	uint8_t					osal_mutex_def_t;
typedef	osal_semaphore_def_t	*osal_semaphore_t;
typedef	osal_semaphore_def_t	osal_mutex_def_t;
typedef	osal_semaphore_t		osal_mutex_t;
typedef	osal_queue_def_t		*osal_queue_t;
typedef	uint32_t				osal_spinlock_t;

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	OSAL_QUEUE_DEF(_int_set, _name, _depth, _type) \
						osal_queue_def_t _name = { .depth = _depth, .item_sz = sizeof(_type) };

#define	OSAL_SPINLOCK_DEF(_name, _int_set) \
						osal_spinlock_t _name

// Misc
// ====

/*
 * \brief board_millis
 *
 * - Return the number of milli-seconds
 *	 This call is not used but it is in place
 *	 to allow the compilation
 *
 */
extern	uint32_t	board_millis(void);

/*
 * \brief osal_task_delay
 *
 * - Wait in ms
 *
 */
extern	void	osal_task_delay(uint32_t msec);

/*
 * \brief osal_time_millis
 *
 * - Time elapsed in ms
 *
 */
extern	uint32_t	osal_time_millis(void);

// Semaphore
// =========

/*
 * \brief osal_semaphore_create
 *
 * - Create an anonymous synchro semaphore
 *
 */
extern	osal_semaphore_t	osal_semaphore_create(osal_semaphore_def_t *semdef);

/*
 * \brief osal_semaphore_post
 *
 * - Signal the synchro semaphore
 *
 */
extern	bool	osal_semaphore_post(osal_semaphore_t sem_hdl, bool in_isr);

/*
 * \brief osal_semaphore_wait
 *
 * - Waiting for the synchro semaphore
 *
 */
extern	bool	osal_semaphore_wait(osal_semaphore_t sem_hdl, uint32_t msec);

/*
 * \brief osal_semaphore_reset
 *
 * - Restart the synchro semaphore
 *
 */
extern	void	osal_semaphore_reset(osal_semaphore_t sem_hdl);

// Mutex
// =====

/*
 * \brief osal_mutex_create
 *
 * - Create an anonymous mutex semaphore
 *
 */
extern	osal_mutex_t osal_mutex_create(osal_mutex_def_t *mdef);

/*
 * \brief osal_mutex_delete
 *
 * - Delete an anonymous synchro semaphore
 *
 */
extern	bool	osal_mutex_delete(osal_mutex_t mutex_hdl);

/*
 * \brief osal_mutex_lock
 *
 * - Lock the mutex semaphore
 *
 */
extern	bool osal_mutex_lock(osal_mutex_t mutex_hdl, uint32_t msec);

/*
 * \brief osal_mutex_unlock
 *
 * - Unlock the mutex semaphore
 *
 */
extern	bool osal_mutex_unlock(osal_mutex_t mutex_hdl);

// Queue
// =====

/*
 * \brief osal_queue_create
 *
 * - Create an anonymous queue
 *
 */
extern	osal_queue_t osal_queue_create(osal_queue_def_t *qdef);

/*
 * \brief osal_queue_receive
 *
 * - Receive data from the queue
 *
 */
extern	bool	osal_queue_receive(osal_queue_t qhdl, void *data, uint32_t msec);

/*
 * \brief osal_queue_send
 *
 * - Send data to the queue
 *
 */
extern	bool	osal_queue_send(osal_queue_t qhdl, void const *data, bool in_isr);

/*
 * \brief osal_queue_empty
 *
 * - Check if the queue is empty
 *
 */
extern	bool	osal_queue_empty(osal_queue_t qhdl);

/*
 * \brief osal_queue_delete
 *
 * - Delete the queue
 *
 */
extern	bool	osal_queue_delete(osal_queue_t qhdl);

// Spinlock
// ========

/*
 * \brief osal_spin_init
 *
 * - Init the spinlock
 *
 */
TU_ATTR_ALWAYS_INLINE	static	inline	void	osal_spin_init(osal_spinlock_t *ctx) {

	UNUSED(ctx);
}

/*
 * \brief osal_spin_deinit
 *
 * - De-init the spinlock
 *
 */
TU_ATTR_ALWAYS_INLINE	static	inline	void	osal_spin_deinit(osal_spinlock_t *ctx) {

	UNUSED(ctx);
}

/*
 * \brief osal_spin_lock
 *
 * - Lock the spinlock
 *
 */
TU_ATTR_ALWAYS_INLINE	static	inline	void	osal_spin_lock(osal_spinlock_t *ctx, bool in_isr) {

	if (in_isr == true) {
		if (TUP_MCU_MULTIPLE_CORE == false) {

// Single core MCU does not need to lock in ISR

			UNUSED(ctx);
			return;
		}
    }
}

/*
 * \brief osal_spin_unlock
 *
 * - Unlock the spinlock
 *
 */
TU_ATTR_ALWAYS_INLINE	static	inline	void	osal_spin_unlock(osal_spinlock_t *ctx, bool in_isr) {

	if (in_isr == true) {
		if (TUP_MCU_MULTIPLE_CORE == false) {

// Single core MCU does not need to lock in ISR

			UNUSED(ctx);
			return;
		}
    }
}

#if (defined(__cplusplus))
}
#endif
