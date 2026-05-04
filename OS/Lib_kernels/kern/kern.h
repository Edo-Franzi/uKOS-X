/*
; kernel.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		kernel manager (uKernel core).
;
;			The KERN manager operates on a series of linked lists
;			where the processes are located.
;
;			Service system calls
;			--------------------
;
;			int32_t	kern_init(void);
;			int32_t	kern_runKernel(void);
;			int32_t	kern_criticalSection(uint8_t critical);
;			int32_t	kern_setSerialForProcess(proc_t *handle, serialManager_t serialManager);
;			int32_t	kern_getSerialForProcess(proc_t *handle, serialManager_t *serialManager);
;			int32_t	kern_getState(uint8_t *state);
;			int32_t	kern_createProcess(const spec_t *specification, const void *argument, proc_t **handle);
;			int32_t	kern_killProcess(proc_t *handle);
;			int32_t	kern_setPriority(proc_t *handle, priority_t priority);
;			int32_t	kern_getPriority(proc_t *handle, priority_t *priority);
;			int32_t	kern_getProcessById(const char_t *identifier, proc_t **handle);
;			int32_t	kern_getProcessRun(proc_t **handle);
;			int32_t	kern_installCallBack(void (*code)(uint8_t state));
;
;			Temporal system calls
;			---------------------
;
;			int32_t	kern_suspendProcess(uint32_t time);
;			int32_t	kern_setNewTimeout(proc_t *handle, uint32_t timeout);
;			int32_t	kern_resumeProcessWithTimeout(proc_t *handle);
;			int32_t	kern_readRemainingProcessTimeout(uint32_t *timeout);
;			int32_t	kern_switchFast(void);
;			int32_t	kern_readTickCount(uint64_t *tickCount);
;			int32_t	kern_waitAtLeast(uint16_t time);
;			int32_t	kern_hasPendingTimeoutProcesses(bool *nonInfTOActive);
;
; 			Semaphore system calls
; 			----------------------
;
;			int32_t	kern_createSemaphore(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, sema_t **handle);
;			int32_t	kern_signalSemaphore(sema_t *handle);
;			int32_t	kern_waitSemaphore(sema_t *handle, uint32_t timeout);
;			int32_t	kern_killSemaphore(sema_t *handle);
;			int32_t	kern_restartSemaphore(sema_t *handle);
;			int32_t	kern_getSemaphoreById(const char_t identifier, sema_t **handle);
;
; 			Mutex system calls
; 			------------------
;
;			int32_t	kern_createMutex(const char_t *identifier, mutx_t **handle);
;			int32_t	kern_unlockMutex(mutx_t *handle);
;			int32_t	kern_lockMutex(mutx_t *handle, uint32_t timeout);
;			int32_t	kern_killMutex(mutx_t *handle);
;			int32_t	kern_restartMutex(mutx_t *handle);
;			int32_t	kern_getMutexById(const char_t identifier, mutx_t **handle);
;
;			Mailbox system calls
;			--------------------
;
;			int32_t	kern_createMailbox(const char_t *identifier, mbox_t **handle);
;			int32_t	kern_setMailbox(mbox_t *handle, const mcnf_t *configure);
;			int32_t	kern_writeMailbox(mbox_t *handle, void *message, uint32_t size, uint32_t timeout);
;			int32_t	kern_writeQueue(mbox_t *handle, uintptr_t message, uint32_t timeout);
;			int32_t	kern_readMailbox(mbox_t *handle, void **message, uint32_t *size, uint32_t timeout);
;			int32_t	kern_readQueue(mbox_t *handle, uintptr_t *message, uint32_t timeout);
;			int32_t	kern_killMailbox(mbox_t *handle);
;			int32_t	kern_getMailboxById(const char_t *identifier, mbox_t **handle);
;
;			Signal system calls
;			-------------------
;
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
;			Software timer system calls
;			---------------------------
;
;			int32_t	kern_createSoftwareTimer(const char_t *identifier, stim_t **handle);
;			int32_t	kern_setSoftwareTimer(stim_t *handle, const tspc_t *configure);
;			int32_t	kern_killSoftwareTimer(stim_t *handle);
;			int32_t	kern_getSoftwareTimerById(const char_t *identifier, stim_t **handle);
;
;			Precise signals system calls
;			----------------------------
;
;			int32_t	kern_createPreciseSignal(const char_t *identifier, prcs_t **handle);
;			int32_t	kern_setPreciseSignal(prcs_t *handle, sign_t **sigGroup, proc_t *toProcess, uint64_t period, uint8_t mode, uint32_t signal);
;			int32_t	kern_killPreciseSignal(prcs_t *handle);
;			int32_t	kern_getPreciseSignalById(const char_t *identifier, prcs_t **handle);
;
;			Memory pool system calls
;			------------------------
;
;			int32_t	kern_createPool(const char_t *identifier, pool_t **handle);
;			int32_t	kern_setPool(pool_t *handle, pcnf_t *configure);
;			int32_t	kern_allocateBlock(pool_t *handle, void **address, uint32_t timeout);
;			int32_t	kern_deAllocateBlock(pool_t *handle, const void *address);
;			int32_t	kern_killPool(pool_t *handle);
;			int32_t	kern_getPoolById(const char_t *identifier, pool_t **handle);
;
;			Software debug system calls
;			---------------------------
;
;			int32_t	kern_stopProcess(proc_t *handle);
;			int32_t	kern_reactivateProcess(proc_t *handle);
;
;			Privilege system calls
;			----------------------
;
;			int32_t	kern_setPrivilegeMode(uint8_t mode);
;			void	kern_privilegeElevate(void); !!! Not for user applications
;
;			Name equivalence used by the kernel
;			-----------------------------------
;
;			External module names	Internal suffixes	Exported types
;
;			debug					DEBG				-
;			identifier				-					-
;			kern					KERN				-
;			lists					-					list_t
;			mailboxes				MBOX				mbox_t, mcnf_t
;			mutexes					MUTX				mutx_t
;			pools					POOL				pool_t
;			preciseSignals			PRCS				prcs_t
;			privileges				-					-
;			processes				PROC				proc_t, spec_t, work_t, stts
;			scheduler				-					-
;			semaphores				SEMA				sema_t
;			signals					SIGN				sign_t
;			softwareTimers			STIM				stim_t, tspc_t
;			statistics				-					-
;			stub					-					-
;			temporal				-					-
;			xLibrary				-					-
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
 * \defgroup kern Kern
 *
 * \brief Kern
 *
 * Kern management
 *
 * @{
 */

// Exported standard kernel configuration
// --------------------------------------

// Kernel functionalities

#if (!defined(KKERN_WITH_STATISTICS_S))
#define	KKERN_WITH_STATISTICS_S		true
#endif
#if (!defined(KKERN_WITH_DEBUG_S))
#define	KKERN_WITH_DEBUG_S			true
#endif
#if (!defined(KKERN_WITH_TRTC_S))
#define	KKERN_WITH_TRTC_S			true
#endif

// The number of objects

#if (!defined(KKERN_NB_PROCESSES))
#define	KKERN_NB_PROCESSES			48u
#endif
#if	(defined(KKERN_NB_MAILBOXES))
static_assert((KKERN_NB_MAILBOXES >= 8u), "KKERN_NB_MAILBOXES shall be >= 8");
#else
#define	KKERN_NB_MAILBOXES			48u
#endif
#if	(defined(KKERN_NB_SEMAPHORES))
static_assert((KKERN_NB_SEMAPHORES >= 8u), "KKERN_NB_SEMAPHORES shall be >= 8");
#else
#define	KKERN_NB_SEMAPHORES			48u
#endif
#if	(defined(KKERN_NB_MUTEXES))
static_assert((KKERN_NB_MUTEXES >= 8u), "KKERN_NB_MUTEXES shall be >= 8");
#else
#define	KKERN_NB_MUTEXES			48u
#endif
#if	(defined(KKERN_NB_SIGNALS))
static_assert((KKERN_NB_SIGNALS >= 1u), "KKERN_NB_SIGNALS shall be >= 1");
#else
#define	KKERN_NB_SIGNALS			8u
#endif
#if (!defined(KKERN_NB_SOFTWARE_TIMERS))
#define	KKERN_NB_SOFTWARE_TIMERS	8u
#endif
#if (!defined(KKERN_NB_POOLS))
#define	KKERN_NB_POOLS				8u
#endif
#if (!defined(KKERN_NB_PRECISE_SIGNALS))
#define	KKERN_NB_PRECISE_SIGNALS	8u
#endif

#define	KKERN_NB_PRCS_CHECK(x)		((x * KKERN_NB_SIGNALS) >= x)
static_assert(KKERN_NB_PRCS_CHECK(KKERN_NB_PRECISE_SIGNALS), "KKERN_NB_SIGNALS cannot be 0 when KKERN_NB_PRECISE_SIGNALS > 0");

// The kernel temporal (in ms)

#if (!defined(KKERN_TIC_TIME))
#define	KKERN_TIC_TIME				1u
#endif
#if (!defined(KKERN_TIC_FREQUENCY))
#define	KKERN_TIC_FREQUENCY			1000u
#endif
#if (!defined(KKERN_TICKCOUNT_PER_SECOND))
#define	KKERN_TICKCOUNT_PER_SECOND	(1000u * 1000u)
#endif
#if (!defined(KKERN_PROC_TIMEOUT))
#define	KKERN_PROC_TIMEOUT			20u
#endif

// Misc equates
// ------------

// Size of the object names identifiers + \0 !!! Always aligned !!!

#define	KKERN_OBJECT_SZ_ID			31u							//

// Special process handle (used by semaphores and signals)

#define	KKERN_HANDLE_WRONG			((proc_t *)0x00000000u)		// Wrong handle
#define	KKERN_HANDLE_FROM_ISR		((proc_t *)0x00000001u)		// From ISR (semaphore or other objects)
#define	KKERN_HANDLE_BROADCAST		((proc_t *)0x00000002u)		// Broadcast (signal broadcast)

// uKernel states

enum {
		KKERN_NOT_READY	= 0u,									// Kernel not ready
		KKERN_INITIALISED,										// Kernel Initialised
		KKERN_RUNNING											// KernelRunning
};

// Critical sections

enum {
		KENTER_CRITICAL = 0u,									// Entry into a critical section
		KEXIT_CRITICAL											// Exit from a critical section
};

// Idle states

enum {
		KKERN_IDLE_IN = 0u,										// Enter in the idle process
		KKERN_IDLE_OUT											// Output from the idle process
};

// uKernel Low power modes (used by the idle process)

enum {
		KKERN_CPU_MODE_NORMAL = 0u,								// CPU in a normal running mode
		KKERN_CPU_MODE_DEEP_SLEEP,								// CPU in a deep low power mode
		KKERN_CPU_MODE_HIBERNATE,								// CPU in a hibernate low power mode
		KKERN_CPU_MODE_STOP										// CPU in a stop mode
};

// Priorities

typedef	enum {
		KKERN_PRIORITY_HIGH_Reserved = 0u,						// 00 - High priority (highest priority)
		KKERN_PRIORITY_HIGH_01,									//
		KKERN_PRIORITY_HIGH_02,									//
		KKERN_PRIORITY_HIGH_03,									//
		KKERN_PRIORITY_HIGH_04,									//
		KKERN_PRIORITY_HIGH_05,									//
		KKERN_PRIORITY_HIGH_06,									//
		KKERN_PRIORITY_HIGH_07,									//
		KKERN_PRIORITY_HIGH_08,									//
		KKERN_PRIORITY_HIGH_09,									//
		KKERN_PRIORITY_HIGH_10,									//
		KKERN_PRIORITY_HIGH_11,									//
		KKERN_PRIORITY_HIGH_12,									//
		KKERN_PRIORITY_HIGH_13,									//
		KKERN_PRIORITY_HIGH_14,									//
		KKERN_PRIORITY_HIGH_15,									// 15

		KKERN_PRIORITY_MEDIUM_00,								// 16 - Medium priority
		KKERN_PRIORITY_MEDIUM_01,								//
		KKERN_PRIORITY_MEDIUM_02,								//
		KKERN_PRIORITY_MEDIUM_03,								//
		KKERN_PRIORITY_MEDIUM_04,								//
		KKERN_PRIORITY_MEDIUM_05,								//
		KKERN_PRIORITY_MEDIUM_06,								//
		KKERN_PRIORITY_MEDIUM_07,								//
		KKERN_PRIORITY_MEDIUM_08,								//
		KKERN_PRIORITY_MEDIUM_09,								//
		KKERN_PRIORITY_MEDIUM_10,								//
		KKERN_PRIORITY_MEDIUM_11,								//
		KKERN_PRIORITY_MEDIUM_12,								//
		KKERN_PRIORITY_MEDIUM_13,								//
		KKERN_PRIORITY_MEDIUM_14,								//
		KKERN_PRIORITY_MEDIUM_15,								// 31

		KKERN_PRIORITY_NORMAL_00,								// 32 - Normal priority
		KKERN_PRIORITY_NORMAL_01,								//
		KKERN_PRIORITY_NORMAL_02,								//
		KKERN_PRIORITY_NORMAL_03,								//
		KKERN_PRIORITY_NORMAL_04,								//
		KKERN_PRIORITY_NORMAL_05,								//
		KKERN_PRIORITY_NORMAL_06,								//
		KKERN_PRIORITY_NORMAL_07,								//
		KKERN_PRIORITY_NORMAL_08,								//
		KKERN_PRIORITY_NORMAL_09,								//
		KKERN_PRIORITY_NORMAL_10,								//
		KKERN_PRIORITY_NORMAL_11,								//
		KKERN_PRIORITY_NORMAL_12,								//
		KKERN_PRIORITY_NORMAL_13,								//
		KKERN_PRIORITY_NORMAL_14,								//
		KKERN_PRIORITY_NORMAL_15,								// 47

		KKERN_PRIORITY_LOW_00,									// 48 - Low priority
		KKERN_PRIORITY_LOW_01,									//
		KKERN_PRIORITY_LOW_02,									//
		KKERN_PRIORITY_LOW_03,									//
		KKERN_PRIORITY_LOW_04,									//
		KKERN_PRIORITY_LOW_05,									//
		KKERN_PRIORITY_LOW_06,									//
		KKERN_PRIORITY_LOW_07,									//
		KKERN_PRIORITY_LOW_08,									//
		KKERN_PRIORITY_LOW_09,									//
		KKERN_PRIORITY_LOW_10,									//
		KKERN_PRIORITY_LOW_11,									//
		KKERN_PRIORITY_LOW_12,									//
		KKERN_PRIORITY_LOW_13,									//
		KKERN_PRIORITY_LOW_14,									//
		KKERN_PRIORITY_LOW_IDLE,								// 63 - Lowest priority reserved for the process idle

		KKERN_NB_PRIORITIES,									// 64 - Number of priorities (2^x)
} priority_t;

#define	KKERN_MSK_PRIORITIES	(KKERN_NB_PRIORITIES - 1)		// 2'0011 1111


// uKernel types
// -------------

typedef	struct	proc		proc_t;
typedef	struct	spec		spec_t;
typedef	struct	work		work_t;
typedef	struct	stts		stts_t;
typedef	struct	mbox		mbox_t;
typedef	struct	sema		sema_t;
typedef	struct	mutx		mutx_t;
typedef	struct	atim		atim_t;
typedef	struct	sync		sync_t;
typedef	struct	stim		stim_t;
typedef	struct	pool		pool_t;
typedef	struct	prcs		prcs_t;
typedef	struct	sign		sign_t;

#include	"privileges.h"
#include	"processes.h"
#include	"mailboxes.h"
#include	"statistics.h"
#include	"semaphores.h"
#include	"mutexes.h"
#include	"signals.h"
#include	"temporal.h"
#include	"debug.h"
#include	"softwareTimers.h"
#include	"pools.h"
#include	"preciseSignals.h"
#include	"stub.h"

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	bool	is_exception(void);

/*!
 * \brief Initialise the manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = kern_init();
 *    installMyProcesses();
 *    status = kern_runKernel();
 *
 *    while (true) { ; }
 * \endcode
 *
 * - This function initialises the "kern" manager.
 *   Before using the manager functions, it is necessary to
 *   call this function.
 *
 * \return		KERR_KERN_NOERR	OK
 *
 */
extern	int32_t	kern_init(void);

/*!
 * \brief Start the multi-process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = kern_init();
 *    installMyProcesses();
 *    status = kern_runKernel();
 *
 *    while (true) { ; }
 * \endcode
 *
 * - Initialise all the timers (1-ms & 20-ms)
 * - Enable the time sharing and all the interruptions
 *
 * \return		KERR_KERN_NOERR	OK
 *
 */
extern	int32_t	kern_runKernel(void);

/*!
 * \brief Management of a critical section
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = kern_criticalSection(KENTER_CRITICAL);
 *    ...
 *    Atomic code
 *    ...
 *    status = kern_criticalSection(KEXIT_CRITICAL);
 * \endcode
 *
 * - This function manages the atomic access to a critical section
 *
 * \param[in]	critical		KENTER_CRITICAL, enter in a critical section
 *								KEXIT_CRITICAL, exit from a critical section
 * \return		KERR_KERN_NOERR	OK
 *
 */
extern	int32_t	kern_criticalSection(uint8_t critical);

/*!
 * \brief Set the default communication device for a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_setSerialForProcess(process, KURT1);
 * \endcode
 *
 * - This function sets the default communication device for a process
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	serialManager	Serial Communication Manager
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
extern	int32_t	kern_setSerialForProcess(proc_t *handle, serialManager_t serialManager);

/*!
 * \brief Get the default communication device of a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *            uint32_t    serialManager;
 *
 *    status = kern_getSerialForProcess(process, &serialManager);
 * \endcode
 *
 * - This function gets the default communication device of a process
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	*serialManager	Ptr on the Serial Communication Manager
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
extern	int32_t	kern_getSerialForProcess(proc_t *handle, serialManager_t *serialManager);

/*!
 * \brief Get the uKernel state
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    state;
 *
 *    status = kern_getState(&state);
 *    switch (state) {
 *        case: KKERN_NOT_READY    { … break; }
 *        case: KKERN_INITIALISED  { … break; }
 *        case: KKERN_RUNNING      { … break; }
 * \endcode
 *
 * - This function returns the state of the uKernel
 *
 * \param[out]	*state			Ptr on the uKernel state
 * \return		KERR_KERN_NOERR	OK
 *
 */
extern	int32_t	kern_getState(uint8_t *state);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
