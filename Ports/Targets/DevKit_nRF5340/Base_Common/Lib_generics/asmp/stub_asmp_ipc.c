/*
; stub_asmp_ipc.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the managemen of the "asmp" manager with IPC,
;
;			The messages coming from the API are routed to the respective
;			peripherals for the IPC management.
;
;			Generic from the API					Target specific
;
;			KASMP_MESSAGE_VALID_FOR_CORE_0			IPC_0_PROCESS_0
;			KASMP_MESSAGE_VALID_FOR_CORE_1			IPC_1_PROCESS_1
;			KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0	IPC_2_PROCESS_2
;			KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1	IPC_2_PROCESS_3
;
;			Ex.
;			core 0 send a message
;				SenderFull[KASMP_CORE_1] = true
;				Generate the message KASMP_MESSAGE_VALID_FOR_CORE_1 on the core 1
;
;			core 1 receives the message KASMP_MESSAGE_VALID_FOR_CORE_1
;				ReceiverEmpty = false
;				...
;				Read the message
;				Generate the message KASMPMESSAGE_ACKNOWLEDGE_FROM_CORE_1
;				SenderFull[KASMP_CORE_1] = false
;
;			Important:
;			In this multicore communication layer, we must take into account both heterogeneous (e.g., M4 + M7)
;			and homogeneous (e.g., 2 × M33) core configurations.
;
;			For uKOS:
;			In a heterogeneous configuration, KNB_CORES is always equal to 1.
;			In a homogeneous configuration, KNB_CORES is always greater than 1.
;			Be careful with the PREEMPTION_THRESHOLD macro to ensure it returns the correct core:
;			In a heterogeneous configuration: PREEMPTION_THRESHOLD(KCORE_0)
;			In a homogeneous configuration: PREEMPTION_THRESHOLD(core)
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

#include	"uKOS.h"

#define	IPC_0_PROCESS_0		0u				// Process ID for IPC, message valid for core 0
#define	IPC_1_PROCESS_1		1u				// Process ID for IPC, message valid for core 1
#define	IPC_2_PROCESS_2		2u				// Process ID for IPC, acknowledge the core 0
#define	IPC_3_PROCESS_3		3u				// Process ID for IPC, acknowledge the core 1

const	char_t	*tableCoreReference[2] = {
					"Cortex-M33 App (fpu + dsp) ",
					"Cortex-M33 Net"
				};

extern	asmpShared_t	*vAsmp_InterCore;

// Prototypes

		int32_t	stub_asmp_getRunningCore(uint32_t *core);
static	void	local_initInterCore(uint32_t core);
static	void	local_IPC_interruptionChannel(void);

/*
 * \brief stub_asmp_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
int32_t	stub_asmp_init(void) {
			uint32_t	core;
			sema_t		*semaphore_RX, *semaphore_TX;
	const	char_t		*identifier_RX, *identifier_TX;

	stub_asmp_getRunningCore(&core);
	identifier_RX = (core == KASMP_CORE_0) ? (KASMP_SEMA_RX_CORE_0_FULL)  : (KASMP_SEMA_RX_CORE_1_FULL);
	identifier_TX = (core == KASMP_CORE_0) ? (KASMP_SEMA_TX_CORE_0_EMPTY) : (KASMP_SEMA_TX_CORE_1_EMPTY);

	INTERRUPT_VECTOR(IPC_C0_IRQn, local_IPC_interruptionChannel);
	NVIC_SetPriority(IPC_C0_IRQn, KINT_LEVEL_PERIPHERALS);
	NVIC_EnableIRQ(IPC_C0_IRQn);

	switch (core) {
		case KASMP_CORE_0: {
			REG(IPC)->SEND_CNF[1]	 = (1u<<IPC_1_PROCESS_1);
			REG(IPC)->SEND_CNF[3]	 = (1u<<IPC_3_PROCESS_3);
			REG(IPC)->RECEIVE_CNF[0] = (1u<<IPC_0_PROCESS_0);
			REG(IPC)->RECEIVE_CNF[2] = (1u<<IPC_2_PROCESS_2);
			REG(IPC)->INTENSET		 = (1u<<IPC_2_PROCESS_2) | (1u<<IPC_0_PROCESS_0);
			break;
		}

		case KASMP_CORE_1: {
			REG(IPC)->SEND_CNF[0]	 = (1u<<IPC_0_PROCESS_0);
			REG(IPC)->SEND_CNF[2]	 = (1u<<IPC_2_PROCESS_2);
			REG(IPC)->RECEIVE_CNF[1] = (1u<<IPC_1_PROCESS_1);
			REG(IPC)->RECEIVE_CNF[3] = (1u<<IPC_3_PROCESS_3);
			REG(IPC)->INTENSET		 = (1u<<IPC_3_PROCESS_3) | (1u<<IPC_1_PROCESS_1);
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}

	local_initInterCore(core);

// Create the message ready semaphore
// Create the message sent semaphore and signal message sent
// Prepare the information indicating ASMP ready

	kern_createSemaphore(identifier_RX, 0, 1, &semaphore_RX);
	kern_createSemaphore(identifier_TX, 0, 1, &semaphore_TX);

	kern_signalSemaphore(semaphore_TX);

	INTERRUPTION_OFF;
	vAsmp_InterCore->oASMPReady |= (core == KASMP_CORE_0) ? (1u<<(uint8_t)KASMP_CORE_0) : (1u<<(uint8_t)KASMP_CORE_1);
	RETURN_INT_RESTORE(KERR_ASMP_NOERR);
}

/*
 * \brief stub_asmp_getRunningCore
 *
 * - Get the running core
 *
 */
int32_t	stub_asmp_getRunningCore(uint32_t *core) {

	#if (defined(CPU_APPLICATION_S))
	*core = (uint32_t)KASMP_CORE_0;
	#endif

	#if (defined(CPU_NETWORK_S))
	*core = (uint32_t)KASMP_CORE_1;
	#endif

	return (KERR_ASMP_NOERR);
}

/*
 * \brief stub_asmp_getNumberOfCore
 *
 * - Get the number of core
 *
 */
int32_t	stub_asmp_getNumberOfCore(uint8_t *nbCore) {

	*nbCore = ((uint8_t)KASMP_CORE_1 + 1u);
	return (KERR_ASMP_NOERR);
}

/*
 * \brief stub_asmp_getReferenceCore
 *
 * - Get the ptr on the core reference table
 *
 */
int32_t	stub_asmp_getReferenceCore(uint32_t core, const char_t **coreReference) {

	switch (core) {
		case KASMP_CORE_0: { *coreReference = tableCoreReference[KASMP_CORE_0]; break; }
		case KASMP_CORE_1: { *coreReference = tableCoreReference[KASMP_CORE_1]; break; }
		default:		   { *coreReference = nullptr;							break; }
	}
	return (KERR_ASMP_NOERR);
}

/*
 * \brief stub_asmp_signal
 *
 * - Signal by an hardware semaphore
 *
 *		Possible values
 *		- KASMP_MESSAGE_VALID_FOR_CORE_0
 *		- KASMP_MESSAGE_VALID_FOR_CORE_1
 *		- KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0
 *		- KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1
 *
 */
int32_t	stub_asmp_signal(uint32_t message) {

	switch (message) {
		case KASMP_MESSAGE_VALID_FOR_CORE_0:	   { REG(IPC)->TASKS_SEND[0] = 1u; break; }
		case KASMP_MESSAGE_VALID_FOR_CORE_1:	   { REG(IPC)->TASKS_SEND[1] = 1u; break; }
		case KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0: { REG(IPC)->TASKS_SEND[2] = 1u; break; }
		case KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1: { REG(IPC)->TASKS_SEND[3] = 1u; break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	return (KERR_ASMP_NOERR);
}

/*
 * \brief stub_asmp_waitingForReady
 *
 * - Waiting for the ASMP ready
 *
 */
int32_t	stub_asmp_waitingForReady(void) {
	uint8_t		maskNbCore;
	int32_t		status;

	maskNbCore = (1u<<(uint32_t)KASMP_CORE_1) | (1u<<(uint32_t)KASMP_CORE_0);

	status = ((vAsmp_InterCore->oASMPReady & maskNbCore) == maskNbCore) ? (KERR_ASMP_NOERR) : (KERR_ASMP_NORDY);
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_initInterCore
 *
 * - Initialise the InterCore structure
 *
 */
static	void	local_initInterCore(uint32_t core) {
	uint32_t	i;

	INTERRUPTION_OFF;
	vAsmp_InterCore->oStatusRX[core] = KASMP_FREE;
	vAsmp_InterCore->oStatusTX[core] = KASMP_FREE;
	vAsmp_InterCore->oSender[core]	 = 0u;
	vAsmp_InterCore->oOrder[core]	 = 0u;
	vAsmp_InterCore->oSize[core]	 = 0u;
	for (i = 0u; i < KASMP_SZ_BUFFER; i++) { vAsmp_InterCore->oBuffer[core][i] = 0u; }
	INTERRUPTION_RESTORE;
}

/*
 * \brief local_IPC_interruptionChannel
 *
 * - Channel management
 *
 */
static	void	local_IPC_interruptionChannel(void) {
			uint32_t	core;
			sema_t		*semaphore_RX, *semaphore_TX;
	const	char_t		*identifier_RX, *identifier_TX;

	stub_asmp_getRunningCore(&core);
	identifier_RX = (core == KASMP_CORE_0) ? (KASMP_SEMA_RX_CORE_0_FULL)  : (KASMP_SEMA_RX_CORE_1_FULL);
	identifier_TX = (core == KASMP_CORE_0) ? (KASMP_SEMA_TX_CORE_0_EMPTY) : (KASMP_SEMA_TX_CORE_1_EMPTY);

	kern_getSemaphoreById(identifier_RX, &semaphore_RX);
	kern_getSemaphoreById(identifier_TX, &semaphore_TX);

// Interruption message sent
// Interruption message read

	if (core == KASMP_CORE_0) {

// core1 indicates to the core0 that there is a valid message in the buffer
// core1 acknowledge the core0, get free the statusTX of the core1

		if (REG(IPC)->EVENTS_RECEIVE[0] != 0u) { REG(IPC)->EVENTS_RECEIVE[0] = 0u; vAsmp_InterCore->oStatusRX[KASMP_CORE_0] = KASMP_LOCK; kern_signalSemaphore(semaphore_RX); }
		if (REG(IPC)->EVENTS_RECEIVE[2] != 0u) { REG(IPC)->EVENTS_RECEIVE[2] = 0u; vAsmp_InterCore->oStatusTX[KASMP_CORE_1] = KASMP_FREE; kern_signalSemaphore(semaphore_TX); }
	}
	else {

// core0 indicates to the core1 that there is a valid message in the buffer
// core0 acknowledge the core1, get free the statusTX of the core0

		if (REG(IPC)->EVENTS_RECEIVE[1] != 0u) { REG(IPC)->EVENTS_RECEIVE[1] = 0u; vAsmp_InterCore->oStatusRX[KASMP_CORE_1] = KASMP_LOCK; kern_signalSemaphore(semaphore_RX); }
		if (REG(IPC)->EVENTS_RECEIVE[3] != 0u) { REG(IPC)->EVENTS_RECEIVE[3] = 0u; vAsmp_InterCore->oStatusTX[KASMP_CORE_0] = KASMP_FREE; kern_signalSemaphore(semaphore_TX); }
	}

	PREEMPTION_THRESHOLD(KCORE_0);
}
