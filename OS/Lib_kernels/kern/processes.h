/*
; processes.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Process management.
;
;			This module manages the processes.
;
;			Service system calls
;			--------------------
;
;			void	processes_init(void);
;			int32_t	kern_createProcess(const spec_t *specification, const void *argument, proc_t **handle);
;			int32_t	kern_killProcess(proc_t *handle);
;			int32_t	kern_setPriority(proc_t *handle, priority_t priority);
;			int32_t	kern_getPriority(proc_t *handle, priority_t *priority);
;			int32_t	kern_getProcessById(const char_t *identifier, proc_t **handle);
;			int32_t	kern_getProcessRun(proc_t **handle);
;			int32_t	kern_installCallBack(void (*code)(uint8_t state));
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
 * \defgroup processes Processes
 *
 * \brief Processes
 *
 * Process management
 *
 * @{
 */

#include	"kern/private/private_lists.h"
#include	"serial/serial.h"

// Structures & macros
// -------------------

// Mandatory: Align the stack to boundary of 8-bytes

#define	SPECIFICATIONS(index, specification, infoStr, lenStackNbWords, code, identifier, serialManager, priority, kind, stackMode)									\
			spec_t		specification = {																															\
							.oIdentifier	= identifier,																											\
							.oText 			= infoStr,																												\
							.oStackStart	= &vStack_##index[0],																									\
							.oStack			= &vStack_##index[(((lenStackNbWords) - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK)],									\
							.oStackSize		= (((lenStackNbWords) - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK),														\
							.oCode			= (void (*)(const void *argument))code,																					\
							.oStackMode		= stackMode,																											\
							.oKind			= kind,																													\
							.oMode			= KPROC_USER,																											\
							.oPriority		= priority,																												\
							.oSerialManager	= serialManager,																										\
							.oScheduleHook	= nullptr																													\
						};

#define	SPECIFICATIONS_DAEMON(core, specification, infoStr, stack, lenStackNbWords, code, identifier, serialManager, priority, kind, stackMode)						\
			spec_t		specification = {																															\
							.oIdentifier	= identifier,																											\
							.oText 			= infoStr,																												\
							.oStackStart	= &stack[core][0],																										\
							.oStack			= &stack[core][(((lenStackNbWords) - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK)],										\
							.oStackSize		= (((lenStackNbWords) - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK),														\
							.oCode			= (void (*)(const void *argument))code,																					\
							.oStackMode		= stackMode,																											\
							.oKind			= kind,																													\
							.oMode			= KPROC_PRIVILEGED,																										\
							.oPriority		= priority,																												\
							.oSerialManager	= serialManager,																										\
							.oScheduleHook	= nullptr																													\
						};

// Support of the user/privileged modes
// ------------------------------------

// Define a process
// - Static stacks
// - Mode privileged (if not selected, user the mode user)

#if (defined(PRIVILEGED_USER_S))
#define	PROCESS_PRIVILEGED(index, specification, infoStr, lenStackNbWords, code, identifier, serialManager, priority)												\
	VAR_DECLARED_ALIGN(static uintptr_t vStack_##index[lenStackNbWords], KSTACK_ALIGNMENT) __attribute__ ((section (".privileged")));								\
																																									\
	SPECIFICATIONS(index, specification, infoStr, lenStackNbWords, code, identifier, serialManager, priority, KPROC_NORMAL, KPROC_STACK_STATIC);

#else
#define	PROCESS_PRIVILEGED(index, specification, infoStr, lenStackNbWords, code, identifier, serialManager, priority)												\
	VAR_DECLARED_ALIGN(static uintptr_t vStack_##index[lenStackNbWords], KSTACK_ALIGNMENT) __attribute__ ((section (".user")));										\
																																									\
	SPECIFICATIONS(index, specification, infoStr, lenStackNbWords, code, identifier, serialManager, priority, KPROC_NORMAL, KPROC_STACK_STATIC);
#endif

// Define a process
// - Static stacks
// - Mode user

#define	PROCESS(index, specification, infoStr, lenStackNbWords, code, identifier, serialManager, priority)															\
	VAR_DECLARED_ALIGN(static uintptr_t vStack_##index[lenStackNbWords], KSTACK_ALIGNMENT) __attribute__ ((section (".user")));										\
																																									\
	SPECIFICATIONS(index, specification, infoStr, lenStackNbWords, code, identifier, serialManager, priority, KPROC_NORMAL, KPROC_STACK_STATIC);

// Define a process
// - Dynamic stacks
// - Mode user

#define	PROCESS_STACKMALLOC(index, specification, infoStr, lenStackNbWords, code, identifier, serialManager, priority)												\
	uintptr_t	*vStack_##index = (uintptr_t *)memo_malloc(KSTACK_ALIGNMENT_MEMO, ((lenStackNbWords) * sizeof(uintptr_t)), "stack");								\
																																									\
	SPECIFICATIONS(index, specification, infoStr, lenStackNbWords, code, identifier, serialManager, priority, KPROC_NORMAL, KPROC_STACK_DYNAMIC);

// Define a daemon
// - Static stacks
// - Mode privileged

#define	DAEMON_PRIVILEGED(core, specification, infoStr, stack, lenStackNbWords, code, identifier, serialManager, priority)											\
	SPECIFICATIONS_DAEMON(core, specification, infoStr, stack, lenStackNbWords, code, identifier, serialManager, priority, KPROC_DAEMON, KPROC_STACK_STATIC);

// Structure for the process specification
// ---------------------------------------

struct spec {
	const	char_t				*oIdentifier;										// Ptr on the process identifier
	const	char_t				*oText;												// Ptr on the process identifier text
			uintptr_t			*oStackStart;										// Ptr on the begin of the process stack
			uintptr_t			*oStack;											// Ptr on the process stack (has to be aligned to boundary of 8-bytes)
			uint32_t			oStackSize;											// Size (number of uint32_t) of the process stack

			void				(*oCode)(const void *argument);						// Ptr on the process code

			uint8_t				oStackMode;											// Stack mode
			uint8_t				oKind;												// Process kind
			uint8_t				oMode;												// Process running mode
			priority_t			oPriority;											// Process priority
			serialManager_t		oSerialManager;										// Default I/O channel
			void				(*oScheduleHook)(proc_t *handle, bool scheduled);	// Optional call-back, called each time the process is de / scheduled
};

// Stacks (oStackMode)

enum {
			KPROC_STACK_STATIC = 0u,												// KPROC_STACK_STATIC = static stack allocation
			KPROC_STACK_DYNAMIC														// KPROC_STACK_DYNAMIC = dynamic stack allocation
};

// Kind of process (oKind)

enum {
			KPROC_NORMAL = 0u,														// KPROC_NORMAL = normal process
			KPROC_DAEMON															// KPROC_DAEMON = daemon process
};

// Privilege mode (oMode)

enum {
			KPROC_USER = 0u,														// KPROC_USER = process running in a user space
			KPROC_PRIVILEGED														// KPROC_PRIVILEGED = process running in a privileged space
};

// Structure for the uKernel working states
// ----------------------------------------

struct work {
			list_t			*oListDebg;												// Ptr on the list where the process was connected (before the kern_stopProcess)
			proc_t			*oProcFather;											// Ptr on the father process (nullptr = orphan)
			uint16_t		oStateDebg;												// Process state (before the kern_stopProcess)
			uint16_t		oState;													// Process state
			#define			BPROC_FIRST					0u							// Process first
			#define			BPROC_INSTALLED				1u							// Process installed
			#define			BPROC_RUNNING				2u							// Process running
			#define			BPROC_SUSP_TIME				3u							// Process suspended for a time
			#define			BPROC_SUSP_SIGN				4u							// Process suspended for an signal
			#define			BPROC_SUSP_SEMA				5u							// Process suspended for a semaphore
			#define			BPROC_SUSP_MUTX				6u							// Process suspended for a mutex
			#define			BPROC_SUSP_MBOX_E			7u							// Process suspended for a mailbox (empty)
			#define			BPROC_SUSP_MBOX_F			8u							// Process suspended for a mailbox (full)
			#define			BPROC_SUSP_DEBG				9u							// Process suspended for a debug
			#define			BPROC_LIKE_ISR				10u							// Process should be considered similar to an ISR for blocking APIs
			#define			BPROC_PRIV_ELEVATED			11u							// Process elevated (privileged mode)

			uint32_t		oNestedPrivilege;										// Nested privilege elevation counter
			int32_t			oStatus;												// Status
			uint32_t		oTimeout;												// Process timeout
			uint16_t		oSkip;													// Number of time that the process was skipped
			priority_t		oDynamicPriority;										// Process priority	dynamic
			void			*oLocal;												// Ptr on a general local structure
};

#define	KSTATE_EOT_MASK		((1u<<BPROC_SUSP_TIME) | (1u<<BPROC_SUSP_SIGN) | (1u<<BPROC_SUSP_SEMA) | (1u<<BPROC_SUSP_MBOX_E) | (1u<<BPROC_SUSP_MBOX_F))

// Structure for the statistics
// ----------------------------

struct stts {
			uint64_t		oNbExecutions;										// Number of time that the process has been scheduled
			uint64_t		oNbKernCalls;										// Number of uKernel system calls

			#if (KKERN_WITH_STATISTICS_S == true)
			uint64_t		oTimePCum;											// Cum CPU time used by the Process
			uint64_t		oTimeKCum;											// Cum CPU time used by the uKernel
			uint64_t		oTimeECum;											// Cum CPU time used by the Exceptions

			#if (KDAEMONS_WITH_STACK_INT_S == true)
			uint32_t		oAvStack;											// Available size in the stack
			#endif

			uint16_t		oTimePMin;											// Min CPU time used by the Process
			uint16_t		oTimePMax;											// Max CPU time used by the Process
			uint16_t		oTimePAvg;											// Avg CPU time used by the Process
			uint16_t		oTimeKMin;											// Min CPU time used by the uKernel
			uint16_t		oTimeKMax;											// Max CPU time used by the uKernel
			uint16_t		oTimeKAvg;											// Avg CPU time used by the uKernel
			uint16_t		oTimeEMin;											// Min CPU time used by the Exceptions
			uint16_t		oTimeEMax;											// Max CPU time used by the Exceptions
			uint16_t		oTimeEAvg;											// Avg CPU time used by the Exceptions
			#endif
};

// Structure of the process
// ------------------------

struct proc {
			obje_t			oObject;											// Process object
			spec_t			oSpecification;										// Process specification
			work_t			oInternal;											// Process internal stuff
			stts_t			oStatistic;											// uKernel statistic
};

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	void	processes_init(void);

/*!
 * \brief Create and install a process
 *
 * Call example in C:
 *
 * \code{.c}
 * // Example for 32-bit machines
 *
 * #define    KSIZE         1024          // Size of the stack in bytes
 * #define    KSZSTACK32    (KSIZE>>2)    // Size of the stack in number of 32-bit words
 *
 * int32_t    status;
 * static     uintptr_t    vStack_0[KSZSTACK32];
 * static     proc_t       *vProcess_0, *vProcess_1;
 *
 * const      spec_t       vSpecs_0 = {
 *                             .oIdentifier    = "User Process 0”,
 *                             .oText          = ”Process to do something (static mode)”,
 *                             .oCode          = (const void (*)(const void *argument))process_0,
 *                             .oStackStart    = &vStack_0[0],
 *                             .oStack         = &vStack_0[((KSZSTACK32 - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK)],
 *                             .oStackSize     = ((KSZSTACK32 - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK),
 *                             .oStackMode     = KPROC_STACK_STATIC,
 *                             .oPriority      = 5,
 *                             .oSerialManager = KDEF0,
 *                             .oKind          = KPROC_NORMAL,
 *                             .oMode          = KPROC_USER,
 *                             .oScheduleHook  = nullptr
 *                         };
 *
 *            uintptr_t    *vStack_1 = (uintptr_t *)memo_malloc(KMEMO_ALIGN_16, (KSZSTACK32 * sizeof(uintptr_t)), "stack");
 * const      spec_t       vSpecs_1 = {
 *                             .oIdentifier    = "User Process 1”,
 *                             .oText          = ”Process to do something (dynamic mode)”,
 *                             .oCode          = (const void (*)(const void *argument))process_1,
 *                             .oStackStart    = &vStack_1[0],
 *                             .oStack         = &vStack_1[((KSZSTACK32 - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK)],
 *                             .oStackSize     = ((KSZSTACK32 - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK),
 *                             .oStackMode     = KPROC_STACK_DYNAMIC,
 *                             .oPriority      = 5,
 *                             .oSerialManager = KDEF0,
 *                             .oKind          = KPROC_NORMAL,
 *                             .oMode          = KPROC_USER,
 *                             .oScheduleHook  = nullptr
 *                         };
 *
 * status = kern_createProcess(&vSpecs_0, nullptr, &vProcess_0);
 * status = kern_createProcess(&vSpecs_1, nullptr, &vProcess_1);
 *
 * To simplify the way to write this initialization, a couple of macros are available;
 * so, the previous example can be written in this way:
 *
 * #define    KSIZE         1024          // Size of the stack in bytes
 * #define    KSZSTACK32    (KSIZE>>2)    // Size of the stack in number of 32-bit words
 *
 * int32_t    status;
 * static     char_t      aStrProcess_0[] = "Process to do something 0r\n";
 * static     char_t      aStrProcess_1[] = "Process to do something 1\r\n";
 * static     proc_t      *vProcess_0, *vProcess_1;
 *
 * PROCESS(0, vSpecs_0, aStrProcess_0, KSZSTACK32, process_0, "User Process 0", KDEF0, 5, 0)
 * PROCESS(1, vSpecs_1, aStrProcess_1, KSZSTACK32, process_1, "User Process 1", KCDC0, 5, 0)
 *
 * status = kern_createProcess(&vSpecs_0, nullptr, &vProcess_0);
 * status = kern_createProcess(&vSpecs_1, nullptr, &vProcess_1);
 * \endcode
 *
 * - Disconnect a process from the empty list
 * - Initialise the stack frame
 * - Connect the process to the execution list
 *
 * \par Fields of \c specification (struct ::spec_t):
 * - \c oIdentifier     : Ptr on the process identifier (nullptr = anonymous)
 * - \c oText           : Ptr on the process text (nullptr = anonymous)
 * - \c oCode           : Ptr on the process code
 * - \c oStackMode      : Stack mode
 * - \c oStackStart     : Begin of the process stack
 * - \c oStack          : Process stack (aligned on 8 bytes)
 * - \c oStackSize      : Size (number of uint32_t) of the process stack
 * - \c oSerialManager  : Default Serial Communication Manager
 * - \c oPriority       : Process priority
 * - \c oKind           : Process kind
 * - \c oMode           : Process running mode
 *
 * \param[in]	*specification				Ptr on the process specification
 * \param[in]	*argument					Ptr on the process argument
 * \param[out]	**handle					Ptr on the handle
 * \return		KERR_KERN_NOERR				OK
 * \return		KERR_KERN_LIFUL				No more process
 * \return		KERR_KERN_IDPRO				The process identifier is already used
 * \return		KERR_KERN_NOSTK				No memory for the stack
 * \return		KERR_KERN_FRISR				Execution from ISR
 * \return		KERR_KERN_PRIVI				Privilege violation
 *
 */
extern	int32_t	kern_createProcess(const spec_t *specification, const void *argument, proc_t **handle);

/*!
 * \brief Kill the process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_killProcess();
 * \endcode
 *
 * - Disconnect a process from the list to which it is connected
 * - Connect the process to the empty list
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_REFRS	The first process cannot be removed
 * \return		KERR_KERN_RESDE	The system daemons cannot be removed
 * \return		KERR_KERN_NOPRO	The process does not exist
 * \return		KERR_KERN_FRISR	Execution from ISR
 * \return		KERR_KERN_PRIVI	Privilege violation
 *
 */
extern	int32_t	kern_killProcess(proc_t *handle);

/*!
 * \brief Set a new static priority for a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_setPriority(process, 23);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	priority		Process priority
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
extern	int32_t	kern_setPriority(proc_t *handle, priority_t priority);

/*!
 * \brief Get the static priority of a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    priority
 * proc_t     *process;
 *
 *    status = kern_getPriority(process, &priority);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	*priority		Ptr on the process priority
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
extern	int32_t	kern_getPriority(proc_t *handle, priority_t *priority);

/*!
 * \brief Get the handle of a process by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * const      char_t    identifier[] = ”Process 0 - read a sensors”;
 *            proc_t    *process;
 *
 *    status = kern_getProcessById(identifier, &process);
 * \endcode
 *
 * - This function returns the handle of the process
 *
 * \param[in]	*identifier		Ptr on the process identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
extern	int32_t	kern_getProcessById(const char_t *identifier, proc_t **handle);

/*!
 * \brief Get the handle of the running process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_getProcessRun(&process);
 * \endcode
 *
 * - This function returns the handle of the current process
 *
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 *
 */
extern	int32_t	kern_getProcessRun(proc_t **handle);

/*!
 * \brief Install the idle calls back routine
 *
 * \warning	This callback has to feed simple and non blocking code!!!
 * \warning	It is forbidden to use functions that unschedule the idle process.
 * \warning	e.g. kern_suspendProcess, etc.
 *
 * Call example in C:
 *
 * \code{.c}
 *            int32_t    status;
 * static     void       local_myRoutine(uint8_t state);
 *
 *    status = kern_installCallBack(local_myRoutine);
 *
 *    // My callback routine
 *
 *    static    void    local_myRoutine(uint8_t state) {
 *
 *        if (state == KKERN_IDLE_IN) led_off(KLED_IDLE);
 *        else                        led_on(KLED_IDLE);
 *    }
 * \endcode
 *
 * - I.e, this function implements a mechanism for visually display
 *   the load of the cpu by a LED intensity (the more the light is on,
 *   the more the load is heavy)
 *
 * \param[in]	*code			Ptr on the routine code
 * \return		KERR_KERN_NOERR	OK
 *
 */
extern	int32_t	kern_installCallBack(void (*code)(uint8_t state));

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
