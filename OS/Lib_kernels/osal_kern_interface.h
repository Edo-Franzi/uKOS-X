/*
; osal_kern_interface.
; ====================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Osal kernel interface for standalone libraries.
;
;			This file export the major kernel components necessary to
;			build standalone libraries that use the kernel.
;
;			Tipically, the following components are needed:
;			mbox
;			sema
;			mutx
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

#if (!defined(__clang__))
#include	"types.h"

#if (!defined(UKOS_S))

// The comm
// --------

typedef	enum {
			KNOTR = (((uint32_t)'n'<<24u) | ((uint32_t)'o'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'R'),	// notr manager
			KSYST = (((uint32_t)'s'<<24u) | ((uint32_t)'y'<<16u) | ((uint32_t)'s'<<8u) | (uint32_t)'t'),	// syst manager
			KDEF0 = (((uint32_t)'d'<<24u) | ((uint32_t)'e'<<16u) | ((uint32_t)'f'<<8u) | (uint32_t)'0'),	// def0 manager
			KURT0 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'0'),	// urt0 manager
			KURT1 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'1'),	// urt1 manager
			KURT2 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'2'),	// urt2 manager
			KURT3 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'3'),	// urt3 manager
			KURT4 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'4'),	// urt4 manager
			KCDC0 = (((uint32_t)'c'<<24u) | ((uint32_t)'d'<<16u) | ((uint32_t)'c'<<8u) | (uint32_t)'0'),	// cdc0 manager
			KCDC1 = (((uint32_t)'c'<<24u) | ((uint32_t)'d'<<16u) | ((uint32_t)'c'<<8u) | (uint32_t)'1'),	// cdc1 manager
			KWFI0 = (((uint32_t)'w'<<24u) | ((uint32_t)'f'<<16u) | ((uint32_t)'i'<<8u) | (uint32_t)'0'),	// wfi0 manager
			KBLE0 = (((uint32_t)'b'<<24u) | ((uint32_t)'l'<<16u) | ((uint32_t)'e'<<8u) | (uint32_t)'0')		// ble0 manager
} serialManager_t;

// Some necessary equates
// ----------------------

typedef	struct	list			list_t;
typedef	struct	obje			obje_t;
typedef	struct	proc			proc_t;
typedef	struct	spec			spec_t;
typedef	struct	work			work_t;
typedef	struct	stts			stts_t;
typedef	struct	mbox			mbox_t;
typedef	struct	sema			sema_t;
typedef	struct	mutx			mutx_t;
typedef	struct	mboxPack		mboxPack_t;
typedef	struct	mcnf			mcnf_t;

#define	KERR_KERN_NOERR			0								// No error
#define	KWAIT_INFINITY			((uint32_t)(-1))				// Waiting forever
#define	KWAIT_REMAINING_TIMEOUT	((uint32_t)(-2))				// Waiting for the remaining timeout
#define	UNUSED(x)				(void)(x)						// Unused variable

// List equates
// ------------

struct	list {
			proc_t				*oFirst;						// Ptr on the first process
			proc_t				*oLast;							// Ptr on the last process
			uint16_t			oNbElements;					// Number of elements of the list
};

struct	obje {
			list_t				*oList;							// Ptr on the list where the process is linked
			proc_t				*oBack;							// Ptr on the back process
			proc_t				*oForward;						// Ptr on the forward process
};

// Proc equates
// ------------

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
		KKERN_MSK_PRIORITIES = (KKERN_NB_PRIORITIES - 1)		// 2'0011 1111
} priority_t;

struct spec {
	const	char_t				*oIdentifier;												// Ptr on the process identifier
	const	char_t				*oText;														// Ptr on the process identifier text
			uintptr_t			*oStackStart;												// Ptr on the begin of the process stack
			uintptr_t			*oStack;													// Ptr on the process stack (has to be aligned to boundary of 8-bytes)
			uint32_t			oStackSize;													// Size (number of uint32_t) of the process stack

			void				(*oCode)(const void *argument);								// Ptr on the process code

			uint8_t				oStackMode;													// Stack mode
			uint8_t				oKind;														// Process kind
			uint8_t				oMode;														// Process running mode
			priority_t			oPriority;													// Process priority
			serialManager_t		oSerialManager;												// Default I/O channel
			void				(*oScheduleHook)(proc_t *handle, bool scheduled);			// Optional call-back, called each time the process is de / scheduled
};

// Stacks (oStackMode)

enum {
			KPROC_STACK_STATIC  = 0u,														// KPROC_STACK_STATIC = static stack allocation
			KPROC_STACK_DYNAMIC																// KPROC_STACK_DYNAMIC = dynamic stack allocation
};

// Kind of process (oKind)

enum {
			KPROC_NORMAL = 0u,																// KPROC_NORMAL = normal process
			KPROC_DAEMON																	// KPROC_DAEMON = daemon process
};

// Privilege mode (oMode)

enum {
			KPROC_USER = 0u,																// KPROC_USER = process running in a user space
			KPROC_PRIVILEGED																// KPROC_PRIVILEGED = process running in a privileged space
};

struct work {
			list_t				*oListDebg;													// Ptr on the list where the process was connected (before the kern_stopProcess)
			proc_t				*oProcFather;												// Ptr on the father process (nullptr = orphan)
			uint16_t			oStateDebg;													// Process state (before the kern_stopProcess)
			uint16_t			oState;														// Process state
			#define				BPROC_FIRST					0u								// Process first
			#define				BPROC_INSTALLED				1u								// Process installed
			#define				BPROC_RUNNING				2u								// Process running
			#define				BPROC_SUSP_TIME				3u								// Process suspended for a time
			#define				BPROC_SUSP_SIGN				4u								// Process suspended for an signal
			#define				BPROC_SUSP_SEMA				5u								// Process suspended for a semaphore
			#define				BPROC_SUSP_MUTX				6u								// Process suspended for a mutex
			#define				BPROC_SUSP_MBOX_E			7u								// Process suspended for a mailbox (empty)
			#define				BPROC_SUSP_MBOX_F			8u								// Process suspended for a mailbox (full)
			#define				BPROC_SUSP_DEBG				9u								// Process suspended for a debug
			#define				BPROC_LIKE_ISR				10u								// Process should be considered similar to an ISR for blocking APIs
			#define				BPROC_PRIV_ELEVATED			11u								// Process elevated (privileged mode)

			uint32_t			oNestedPrivilege;											// Nested privilege elevation counter
			int32_t				oStatus;													// Status
			uint32_t			oTimeout;													// Process timeout
			uint16_t			oSkip;														// Number of time that the process was skipped
			priority_t			oDynamicPriority;											// Process priority	dynamic
			void				*oLocal;													// Ptr on a general local structure
};

struct stts {
			uint64_t			oNbExecutions;												// Number of time that the process has been scheduled
			uint64_t			oNbKernCalls;												// Number of uKernel system calls

			#if (KKERN_WITH_STATISTICS_S == true)
			uint64_t			oTimePCum;													// Cum CPU time used by the Process
			uint64_t			oTimeKCum;													// Cum CPU time used by the uKernel
			uint64_t			oTimeECum;													// Cum CPU time used by the Exceptions

			#if (KDAEMONS_WITH_STACK_INT_S == true)
			uint32_t			oAvStack;													// Available size in the stack
			#endif

			uint16_t			oTimePMin;													// Min CPU time used by the Process
			uint16_t			oTimePMax;													// Max CPU time used by the Process
			uint16_t			oTimePAvg;													// Avg CPU time used by the Process
			uint16_t			oTimeKMin;													// Min CPU time used by the uKernel
			uint16_t			oTimeKMax;													// Max CPU time used by the uKernel
			uint16_t			oTimeKAvg;													// Avg CPU time used by the uKernel
			uint16_t			oTimeEMin;													// Min CPU time used by the Exceptions
			uint16_t			oTimeEMax;													// Max CPU time used by the Exceptions
			uint16_t			oTimeEAvg;													// Avg CPU time used by the Exceptions
			#endif
};

struct proc {
			obje_t				oObject;													// Process object
			spec_t				oSpecification;												// Process specification
			work_t				oInternal;													// Process internal stuff
			stts_t				oStatistic;													// uKernel statistic
};

// Mbox equates
// ------------

struct	mcnf {
			uint32_t			oNbMaxPacks;												// Mailbox (maximum number of packs)
			uint32_t			oDataEntrySize;												// If > 0, will define the maximum size of each entry to be copied
};

struct	mboxPack {
			uint8_t				*oBuff;														// Ptr on the memory message
			uint32_t			oSize;														// Size of the message
};

struct	mbox {
	const	char_t				*oIdentifier;												// Mailbox identifier
			uint16_t			oState;														// Mailbox state
			#define				BMBOX_INSTALLED		0u										// Mailbox installed
			#define				BMBOX_CONFIGURED	1u										// Mailbox configured
			#define				BMBOX_EMPTY			2u										// Mailbox empty
			#define				BMBOX_FULL			3u										// Mailbox full
			#define				BMBOX_BY_COPY		4u										// Mailbox is copying data

			uint32_t			oNbMaxPacks;												// Maximum number of packs
			uint32_t			oNbUsedPacks;												// Used number of packs
			uint32_t			oNbMaxUsedPacks;											// Maximum number of used packs
			uint32_t			oDataEntrySize;												// Data entry size in copy mode
			mboxPack_t			*oFIFO;														// Fifo of packs
			uint8_t				*oDataBuffer;												// Data copy array
			mboxPack_t			*oWrite;													// Fifo write pointer
			mboxPack_t			*oRead;														// Fifo read pointer
			uint8_t				*oDataWrite;												// Data buffer write pointer
			list_t				oListEmpty;													// Mailbox empty list
			list_t				oListFull;													// Mailbox full list
};

// Mutx equates
// ------------

struct	mutx {
	const	char_t				*oIdentifier;												// Mutex identifier
			uint16_t			oState;														// Mutex state
			#define				BMUTX_INSTALLED		0u										// Mutex installed

			int32_t				oCounter;													// Mutex counter
			int32_t				oMaxCounter;												// Mutex counter max value
			#define				KMUTX_MAX_CPT		INT32_MAX								//
			#define				KMUTX_MIN_CPT		INT32_MIN								//

			proc_t				*oOwner;													// Ptr on the process owner of the mutex
			list_t				oList;														// Mutex list
};

// Sema equates
// ------------

struct	sema {
	const	char_t				*oIdentifier;												// Semaphore identifier
			uint16_t			oState;														// Semaphore state
			#define				BSEMA_INSTALLED		0u										// Semaphore installed

			int32_t				oCounter;													// Semaphore counter
			int32_t				oMaxCounter;												// Semaphore counter max value
			#define				KSEMA_MAX_CPT		INT32_MAX								//
			#define				KSEMA_MIN_CPT		INT32_MIN								//

			proc_t				*oOwner;													// Ptr on the process owner of the semaphore
			list_t				oList;														// Semaphore list
};

// The exported API
// ----------------

extern	int32_t	kern_readTickCount(uint64_t *tickCount);
extern	int32_t	kern_suspendProcess(uint32_t time);
extern	int32_t	kern_createSemaphore(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, sema_t **handle);
extern	int32_t	kern_signalSemaphore(sema_t *handle);
extern	int32_t	kern_waitSemaphore(sema_t *handle, uint32_t timeout);
extern	int32_t	kern_restartSemaphore(sema_t *handle);
extern	int32_t	kern_createMutex(const char_t *identifier, mutx_t **handle);
extern	int32_t	kern_killMutex(mutx_t *handle);
extern	int32_t	kern_lockMutex(mutx_t *handle, uint32_t timeout);
extern	int32_t	kern_unlockMutex(mutx_t *handle);
extern	int32_t	kern_createMailbox(const char_t *identifier, mbox_t **handle);
extern	int32_t	kern_setMailbox(mbox_t *handle, const mcnf_t *configure);
extern	int32_t	kern_killMailbox(mbox_t *handle);
extern	int32_t	kern_readMailbox(mbox_t *handle, void **message, uint32_t *size, uint32_t timeout);
extern	int32_t	kern_writeMailbox(mbox_t *handle, void *message, uint32_t size, uint32_t timeout);
extern	int32_t	kern_killMailbox(mbox_t *handle);
#endif

#endif
