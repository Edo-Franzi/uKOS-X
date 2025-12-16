/*
; stub_asmp_msip.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the managemen of the "asmp" manager with msip,
;
;			The messages coming from the API are routed to the respective
;			msip for the IPC management.
;
;			Generic from the API
;
;			KASMP_MESSAGE_VALID_FOR_CORE_0
;			KASMP_MESSAGE_VALID_FOR_CORE_1
;			KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0 (filtered)
;			KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1 (altered)
;
;			Ex.
;			Core 0 send a message
;				SenderFull[KASMP_CORE_1] = true
;				Generate the message KASMP_MESSAGE_VALID_FOR_CORE_1 on the core 1
;
;			Core 1 receives the message KASMP_MESSAGE_VALID_FOR_CORE_1
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

#include	"uKOS.h"

const				char_t		*tableCoreReference[KNB_CORES] = {
									"RISC-V_C0",
									"RISC-V_C1"
								};

extern				asmpShared_t	*vAsmp_InterCore;
static	volatile	uint32_t		vMessage[KNB_CORES] = MCSET(0u);

// Prototypes

static	void	local_initInterCore(uint32_t core);
static	void	local_machineSoftware_IRQHandler(uint32_t core, uint64_t number);
		void	stub_asmp_getRunningCore(uint32_t *core);

/*
 * \brief stub_asmp_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
void	stub_asmp_init(void) {
			uint32_t	core;
			sema_t		*semaphoreRX, *semaphoreTX;
	const	char_t		*identifierRX, *identifierTX;

	stub_asmp_getRunningCore(&core);
	identifierRX = (core == KCORE_0) ? (KASMP_SEMA_RX_CORE_0_FULL)  : (KASMP_SEMA_RX_CORE_1_FULL);
	identifierTX = (core == KCORE_0) ? (KASMP_SEMA_TX_CORE_0_EMPTY) : (KASMP_SEMA_TX_CORE_1_EMPTY);

	INT_INTERRUPT_VECTOR(IINT_MACHINE_SOFTWARE, local_machineSoftware_IRQHandler);
	core_setBitCSR(RV_CSR_MIE, ((uint64_t)1u<<(uint64_t)IINT_MACHINE_SOFTWARE));

	local_initInterCore(core);

// Create the message ready semaphore
// Create the message sent semaphore and signal message sent
// Prepare the information indicating ASMP ready

	kern_createSemaphore(identifierRX, 0, 1, &semaphoreRX);
	kern_createSemaphore(identifierTX, 0, 1, &semaphoreTX);

	kern_signalSemaphore(semaphoreTX);

	INTERRUPTION_OFF;
	vAsmp_InterCore->oASMPReady |= (core == KASMP_CORE_0) ? (1u<<(uint8_t)KASMP_CORE_0) : (1u<<(uint8_t)KASMP_CORE_1);
	INTERRUPTION_RESTORE;
}

/*
 * \brief stub_asmp_getRunningCore
 *
 * - Get the running core
 *
 */
void	stub_asmp_getRunningCore(uint32_t *core) {

	*core = (GET_RUNNING_CORE == KCORE_0) ? ((uint32_t)KASMP_CORE_0) : ((uint32_t)KASMP_CORE_1);
}

/*
 * \brief stub_asmp_getNumberOfCore
 *
 * - Get the number of core
 *
 */
void	stub_asmp_getNumberOfCore(uint8_t *nbCore) {

	*nbCore = ((uint8_t)KASMP_CORE_1 + 1u);
}

/*
 * \brief stub_asmp_getReferenceCore
 *
 * - Get the ptr on the core reference table
 *
 */
void	stub_asmp_getReferenceCore(uint32_t core, const char_t **coreReference) {

	switch (core) {
		case KASMP_CORE_0: { *coreReference = tableCoreReference[KASMP_CORE_0]; break; }
		case KASMP_CORE_1: { *coreReference = tableCoreReference[KASMP_CORE_1]; break; }
		default:		   { *coreReference = NULL;								break; }
	}
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
			uint32_t	core;
	static	spinlock_t	vSignal = SPIN_LOCK_INIT;

	if ((message == KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0) || (message == KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1)) { return (KERR_ASMP_NOERR); }

	INTERRUPTION_OFF;
	SPIN_LOCK(vSignal);
	stub_asmp_getRunningCore(&core);

// The core m generate an interruption on the core n.
// So, the message has to be stored for the code n for a correct decoding
//
// !!! kern_suspendProcess(1) is used just to be sure that the core n
// has enough time to read the message sent by the core m.
// The core m is then acknowledged.

	switch (core) {
		case KASMP_CORE_0: {
			while (clint->msip[KCORE_0].msip != 0u) { kern_switchFast(); }
			while (clint->msip[KCORE_1].msip != 0u) { kern_switchFast(); }

			vMessage[KCORE_1] = message;
			vMessage[KCORE_0] = KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0;
			__sync_synchronize();
			clint->msip[KCORE_1].msip = 1u;
			kern_suspendProcess(1u);
			clint->msip[KCORE_0].msip = 1u;
			break;
		}
		case KASMP_CORE_1: {
			while (clint->msip[KCORE_0].msip != 0u) { kern_switchFast(); }
			while (clint->msip[KCORE_1].msip != 0u) { kern_switchFast(); }

			vMessage[KCORE_0] = message;
			vMessage[KCORE_1] = KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1;
			__sync_synchronize();
			clint->msip[KCORE_0].msip = 1u;
			kern_suspendProcess(1u);
			clint->msip[KCORE_1].msip = 1u;
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	SPIN_UNLOCK(vSignal);
	INTERRUPTION_RESTORE;
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

	maskNbCore = (1u<<(uint8_t)KASMP_CORE_1) | (1u<<(uint8_t)KASMP_CORE_0);

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
 * \brief local_machineSoftware_IRQHandler
 *
 * - Channel management
 *
 */
static	void	local_machineSoftware_IRQHandler(uint32_t core, uint64_t number) {
			sema_t		*semaphoreRX, *semaphoreTX;
	const	char_t		*identifierRX, *identifierTX;

	UNUSED(number);

	identifierRX = (core == KCORE_0) ? (KASMP_SEMA_RX_CORE_0_FULL)  : (KASMP_SEMA_RX_CORE_1_FULL);
	identifierTX = (core == KCORE_0) ? (KASMP_SEMA_TX_CORE_0_EMPTY) : (KASMP_SEMA_TX_CORE_1_EMPTY);

	kern_getSemaphoreById(identifierRX, &semaphoreRX);
	kern_getSemaphoreById(identifierTX, &semaphoreTX);

// Interruption message sent
// Interruption message read

	if (core == KCORE_0) {

// core1 indicates to the core0 that there is a valid message in the buffer
// core1 acknowledge the core0, get free the statusTX of the core1

		if (vMessage[core] == KASMP_MESSAGE_VALID_FOR_CORE_0)		{ vAsmp_InterCore->oStatusRX[KASMP_CORE_0] = KASMP_LOCK; kern_signalSemaphore(semaphoreRX); }
		if (vMessage[core] == KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0) { vAsmp_InterCore->oStatusTX[KASMP_CORE_1] = KASMP_FREE; kern_signalSemaphore(semaphoreTX); }
	}
	else {

// core0 indicates to the core1 that there is a valid message in the buffer
// core0 acknowledge the core1, get free the statusTX of the core0

		if (vMessage[core] == KASMP_MESSAGE_VALID_FOR_CORE_1)		{ vAsmp_InterCore->oStatusRX[KASMP_CORE_1] = KASMP_LOCK; kern_signalSemaphore(semaphoreRX); }
		if (vMessage[core] == KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1) { vAsmp_InterCore->oStatusTX[KASMP_CORE_0] = KASMP_FREE; kern_signalSemaphore(semaphoreTX); }
	}

	PREEMPTION_THRESHOLD(core);

	clint->msip[core].msip = 0u;
}
