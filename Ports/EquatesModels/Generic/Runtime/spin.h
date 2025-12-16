/*
; spin.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Collection of multi-core routines
;
;   (c) 2025-20xx, Edo. Franzi
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

#include	<stdbool.h>
#include	<stdint.h>
#include	<stdatomic.h>

// Structures for locks
// --------------------

typedef	struct	spinlock	spinlock_t;
typedef	struct	corelock	corelock_t;

struct	spinlock {
	atomic_flag		oFlag;
};

struct	corelock {
	spinlock_t		oLock;
	int64_t			oCount;
	uint32_t		oCore;
};

// Prototypes

__attribute__ ((always_inline))	static	inline	void	spin_lockCore(corelock_t *lock);
__attribute__ ((always_inline))	static	inline	void	spin_unLockCore(corelock_t *lock);
__attribute__ ((always_inline))	static	inline	bool	spin_tryLockCore(corelock_t *lock);
__attribute__ ((always_inline))	static	inline	void	spin_lock(spinlock_t *lock);
__attribute__ ((always_inline))	static	inline	void	spin_unLock(spinlock_t *lock);
__attribute__ ((always_inline))	static	inline	bool	spin_tryLock(spinlock_t *lock);

#define	SPIN_LOCK_INIT		{ ATOMIC_FLAG_INIT }

#if (KNB_CORES > 1)
#define SPIN_LOCK(lock)		do { spin_lock(&(lock)); } while (0)

#else
#define SPIN_LOCK(lock)
#endif

#if (KNB_CORES > 1)
#define SPIN_UNLOCK(lock)	do { spin_unLock(&(lock)); } while (0)

#else
#define SPIN_UNLOCK(lock)
#endif

/*
 * \brief spin_lockCore
 *
 * - Lock for a specific core
 *
 * \param[in]	*lock		Prt on the lock structure
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	spin_lockCore(corelock_t *lock) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	while (true) {
		spin_lock(&lock->oLock);

		if (lock->oCount == 0) {
			lock->oCore   = core;
			lock->oCount  = 1;
			spin_unLock(&lock->oLock);
			return;
		}

		else if (lock->oCore == core) {
			lock->oCount++;
			spin_unLock(&lock->oLock);
			return;
        }

		else {

// Lock held by another core : try again

		 }

		spin_unLock(&lock->oLock);

		while (spin_tryLockCore(lock) == true) {

// Busy, wait

		}
		return;
	}
}

/*
 * \brief spin_unLockCore
 *
 * - Unlock for a specific core
 *
 * \param[in]	*lock		Prt on the lock structure
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	spin_unLockCore(corelock_t *lock) {
	uint32_t	core;

	core = GET_RUNNING_CORE;
	spin_lock(&lock->oLock);

	if (lock->oCore == core) {
		lock->oCount--;
		if (lock->oCount <= 0) {
			lock->oCount = 0;
			lock->oCore  = 0xFFFFFFFFu;
		}
	}
	else {

// We should never reach this point
// Probably, exit(FATAL)

	}

	spin_unLock(&lock->oLock);
}

/*
 * \brief spin_tryLockCore
 *
 * - Try to lock for a specific core
 *
 * \param[in]	*lock		Prt on the lock structure
 * \return		true		Spin already locked
 * \return		false		Spin was unlocked, now is locked by me
 *
 */
__attribute__ ((always_inline))	static	inline	bool	spin_tryLockCore(corelock_t *lock) {
	bool		busy = false;
	uint32_t	core;

	core = GET_RUNNING_CORE;

	if (spin_tryLock(&lock->oLock) == true) {
		return (true);
	}

	if (lock->oCount == 0) {
		lock->oCore	  = core;
		lock->oCount  = 1;
		busy = false;
	}
	else if (lock->oCore == core) {
		lock->oCount++;
		busy = false;
	}
	else {
		busy = true;
	}
	spin_unLock(&lock->oLock);
	return (busy);
}

/*
 * \brief spin_lock
 *
 * - Try to spin lock
 *
 * \param[in]	*lock		Prt on the lock structure
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	spin_lock(spinlock_t *lock) {

// MISRA: memory order has to be consistent (defaut)

	while (atomic_flag_test_and_set(&lock->oFlag) == true) {
		__asm volatile("nop");
	}
}

/*
 * \brief spin_unLock
 *
 * - Try to spin lock
 *
 * \param[in]	*lock		Prt on the lock structure
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	spin_unLock(spinlock_t *lock) {

// MISRA: no specific order

	atomic_flag_clear(&lock->oFlag);
}

/*
 * \brief spin_tryLock
 *
 * - Try to lock for a spin
 *
 * \param[in]	*lock		Prt on the lock structure
 * \return		true		Spin already locked
 * \return		false		Spin was unlocked, now is locked by me
 *
 */
__attribute__ ((always_inline))	static	inline	bool	spin_tryLock(spinlock_t *lock) {
	bool	state;

// MISRA: no specific order

	state = atomic_flag_test_and_set(&lock->oFlag);
	return (state);
}
