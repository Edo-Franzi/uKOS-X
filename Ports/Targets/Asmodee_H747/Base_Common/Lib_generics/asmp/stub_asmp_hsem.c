/*
; stub_asmp_hsem.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the managemen of the "asmp" manager with HSEM,
;
;			The messages coming from the API are routed to the respective
;			HSEM for the IPC management.
;
;			Generic from the API					Target specific
;
;			KASMP_MESSAGE_VALID_FOR_CORE_0			KHSEM_PROCESS_0
;			KASMP_MESSAGE_VALID_FOR_CORE_1			KHSEM_PROCESS_1
;			KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0	KHSEM_PROCESS_4
;			KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1	KHSEM_PROCESS_5
;
;			core 0 receives interruptions on HSEM->C2IER
;			core 1 receives interruptions on HSEM->C1IER
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

#define	KSIGNATURE_CORE_0		0xC24u				// cortex-M4
#define	KSIGNATURE_CORE_1		0xC27u				// cortex-M7

#define	KHSEM_COREID_CM4		1u					// Core ID cortex-M4, core 0 (see table 9.4 RM0399 Rev 3)
#define	KHSEM_COREID_CM7		3u					// Core ID cortex-M7, core 1 (see table 9.4 RM0399 Rev 3)

#define	KHSEM_PROCESS_0			0u					// Process ID for HSEM, message valid for core 0
#define	KHSEM_PROCESS_1			1u					// Process ID for HSEM, message valid for core 1
#define	KHSEM_PROCESS_4			4u					// Process ID for HSEM, acknowledge the core 0
#define	KHSEM_PROCESS_5			5u					// Process ID for HSEM, acknowledge the core 1

const	char_t			*tableCoreReference[2] = {
							"Cortex-M4",
							"Cortex-M7"
						};

extern	asmpShared_t	*vAsmp_InterCore;

// Prototypes

		int32_t	stub_asmp_getRunningCore(uint32_t *core);
static	void	local_initInterCore(uint32_t core);
static	void	local_getRunningCoreId(uint32_t *coreID);
static	void	local_hsem_interruptionChannel(void);

/*
 * \brief stub_asmp_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
void	stub_asmp_init(void) {
			uint32_t	core;
			IRQn_Type	irqNumber;
			sema_t		*semaphoreRX, *semaphoreTX;
	const	char_t		*identifierRX, *identifierTX;

	RCC->AHB4ENR |= RCC_AHB4ENR_HSEMEN;

	stub_asmp_getRunningCore(&core);
	identifierRX = (core == KASMP_CORE_0) ? (KASMP_SEMA_RX_CORE_0_FULL)  : (KASMP_SEMA_RX_CORE_1_FULL);
	identifierTX = (core == KASMP_CORE_0) ? (KASMP_SEMA_TX_CORE_0_EMPTY) : (KASMP_SEMA_TX_CORE_1_EMPTY);
	irqNumber	 = (core == KASMP_CORE_0) ? (HSEM2_C0_IRQn)				 : (HSEM1_C0_IRQn);

// Suppress the cppcheck warning for the following code portion
// ------------------------------------------------------------

	#define EXCLUDE_CPPCHECK
	#ifdef EXCLUDE_CPPCHECK
	INTERRUPT_VECTOR(irqNumber, local_hsem_interruptionChannel);
	NVIC_SetPriority(irqNumber, KINT_LEVEL_PERIPHERALS);
	NVIC_EnableIRQ(irqNumber);
	#endif

	(core == KASMP_CORE_0) ? (HSEM->C2ICR  = (1u<<KHSEM_PROCESS_0)) : (HSEM->C1ICR  = (1u<<KHSEM_PROCESS_1));
	(core == KASMP_CORE_0) ? (HSEM->C2ICR  = (1u<<KHSEM_PROCESS_4)) : (HSEM->C1ICR  = (1u<<KHSEM_PROCESS_5));

	(core == KASMP_CORE_0) ? (HSEM->C2IER |= (1u<<KHSEM_PROCESS_0)) : (HSEM->C1IER |= (1u<<KHSEM_PROCESS_1));
	(core == KASMP_CORE_0) ? (HSEM->C2IER |= (1u<<KHSEM_PROCESS_4)) : (HSEM->C1IER |= (1u<<KHSEM_PROCESS_5));

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
int32_t	stub_asmp_getRunningCore(uint32_t *core) {

	*core = (((SCB->CPUID & 0x0000FFF0u)>>4u) == KSIGNATURE_CORE_0) ? ((uint32_t)KASMP_CORE_0) : ((uint32_t)KASMP_CORE_1);
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
		default:		   { *coreReference = NULL;								break; }
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
	uint32_t	core, coreID, process = 0u;

	switch (message) {
		case KASMP_MESSAGE_VALID_FOR_CORE_0:	   { process = KHSEM_PROCESS_0; break; }
		case KASMP_MESSAGE_VALID_FOR_CORE_1:	   { process = KHSEM_PROCESS_1; break; }
		case KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0: { process = KHSEM_PROCESS_4; break; }
		case KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1: { process = KHSEM_PROCESS_5; break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}

	local_getRunningCoreId(&coreID);
	core = (coreID == KSIGNATURE_CORE_0) ? (KHSEM_COREID_CM4<<8u) : (KHSEM_COREID_CM7<<8u);

	INTERRUPTION_OFF;
	switch (process) {
		case KHSEM_PROCESS_0: { HSEM->R0 = (HSEM_R0_LOCK | core | process); HSEM->R0 = (0u | core | process); break; }
		case KHSEM_PROCESS_1: { HSEM->R1 = (HSEM_R1_LOCK | core | process); HSEM->R1 = (0u | core | process); break; }
		case KHSEM_PROCESS_4: { HSEM->R4 = (HSEM_R4_LOCK | core | process); HSEM->R4 = (0u | core | process); break; }
		case KHSEM_PROCESS_5: { HSEM->R5 = (HSEM_R5_LOCK | core | process); HSEM->R5 = (0u | core | process); break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	RETURN_INT_RESTORE(KERR_ASMP_NOERR);
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
 * \brief local_getRunningCoreId
 *
 * - Get the running core Id
 *
 */
static	void	local_getRunningCoreId(uint32_t *coreID) {

	*coreID = (((SCB->CPUID & 0x0000FFF0u)>>4u) == KSIGNATURE_CORE_0) ? (KSIGNATURE_CORE_0) : (KSIGNATURE_CORE_1);
}

/*
 * \brief local_hsem_interruptionChannel
 *
 * - Channel management
 *
 */
static	void	local_hsem_interruptionChannel(void) {
			uint32_t	core;
			sema_t		*semaphoreRX, *semaphoreTX;
	const	char_t		*identifierRX, *identifierTX;

	stub_asmp_getRunningCore(&core);
	identifierRX = (core == KASMP_CORE_0) ? (KASMP_SEMA_RX_CORE_0_FULL)  : (KASMP_SEMA_RX_CORE_1_FULL);
	identifierTX = (core == KASMP_CORE_0) ? (KASMP_SEMA_TX_CORE_0_EMPTY) : (KASMP_SEMA_TX_CORE_1_EMPTY);

	kern_getSemaphoreById(identifierRX, &semaphoreRX);
	kern_getSemaphoreById(identifierTX, &semaphoreTX);

// Interruption message sent
// Interruption message read

	if (core == KASMP_CORE_0) {

// core1 indicates to the core0 that there is a valid message in the buffer
// core1 acknowledge the core0, get free the statusTX of the core1

		if ((HSEM->C2ISR & (1u<<KHSEM_PROCESS_0)) != 0u) { HSEM->C2ICR = (1u<<KHSEM_PROCESS_0); vAsmp_InterCore->oStatusRX[KASMP_CORE_0] = KASMP_LOCK; kern_signalSemaphore(semaphoreRX); }
		if ((HSEM->C2ISR & (1u<<KHSEM_PROCESS_4)) != 0u) { HSEM->C2ICR = (1u<<KHSEM_PROCESS_4); vAsmp_InterCore->oStatusTX[KASMP_CORE_1] = KASMP_FREE; kern_signalSemaphore(semaphoreTX); }
	}
	else {

// core0 indicates to the core1 that there is a valid message in the buffer
// core0 acknowledge the core1, get free the statusTX of the core0

		if ((HSEM->C1ISR & (1u<<KHSEM_PROCESS_1)) != 0u) { HSEM->C1ICR = (1u<<KHSEM_PROCESS_1); vAsmp_InterCore->oStatusRX[KASMP_CORE_1] = KASMP_LOCK; kern_signalSemaphore(semaphoreRX); }
		if ((HSEM->C1ISR & (1u<<KHSEM_PROCESS_5)) != 0u) { HSEM->C1ICR = (1u<<KHSEM_PROCESS_5); vAsmp_InterCore->oStatusTX[KASMP_CORE_0] = KASMP_FREE; kern_signalSemaphore(semaphoreTX); }
	}

	PREEMPTION_THRESHOLD(KCORE_0);
}
