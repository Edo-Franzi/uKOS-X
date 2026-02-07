/*
; asmp.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		asmp manager.
;
;			Interprocessor communication
;
;			core0, 1, 2 ---> core3
;			core1, 2, 3 ---> core0
;			core2, 3, 0 ---> core1
;			core3, 0, 1 ---> core2
;
;			The buffer is associated to the input of a core.
;			Transfer example (core2 send data to core0)
;
;			core2
;			if (Buffer core0 empty)
;				Fill the core0 buffer
;				Buffer core0 Full
;				Send a message to the core0 (strobe)
;
;			core0
;			Read the data
;			Send a message to the core2 (Ack)
;			Buffer core0 Empty
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

#pragma	once

#include	"./kern/kern.h"

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \defgroup asmp Asmp
 *
 * \brief Asmp
 *
 * Asmp management
 *
 * @{
 */

// Modifiable in the makefile: default amp parameters

#if (!defined(KASMP_NB_CORES))
#define	KASMP_NB_CORES			2u								// Number of cores
#endif

#if (!defined(KASMP_SZ_BUFFER))
#define	KASMP_SZ_BUFFER			1024u							// Size of the inter core buffer
#endif

#if (!defined(KASMP_MBOX_MAX_PACK))
#define	KASMP_MBOX_MAX_PACK		10u								// Size of the mbox
#endif

#if (!defined(KASMP_MBOX_ENTRY_SIZE))
#define	KASMP_MBOX_ENTRY_SIZE	0u								// Entry size (0 = mbox with copy)
#endif

typedef	struct asmpShared	asmpShared_t;

struct	asmpShared {
			uint8_t		oASMPReady;
			bool		oStatusRX[KASMP_NB_CORES];
			bool		oStatusTX[KASMP_NB_CORES];
			#define		KASMP_FREE	false
			#define		KASMP_LOCK	true

			uint32_t	oSender[KASMP_NB_CORES];
			uint32_t	oOrder[KASMP_NB_CORES];
			uint32_t	oSize[KASMP_NB_CORES];
			uint8_t		oBuffer[KASMP_NB_CORES][KASMP_SZ_BUFFER];
};

// cores

enum {
		KASMP_CORE_0 = 0u,
		KASMP_CORE_1,
		KASMP_CORE_2,
		KASMP_CORE_3
};

// Semaphores

#define	KASMP_SEMA_RX_CORE_0_FULL		"RX asmp core 0 full"
#define	KASMP_SEMA_RX_CORE_1_FULL		"RX asmp core 1 full"
#define	KASMP_SEMA_RX_CORE_2_FULL		"RX asmp core 2 full"
#define	KASMP_SEMA_RX_CORE_3_FULL		"RX asmp core 3 full"
#define	KASMP_SEMA_TX_CORE_0_EMPTY		"TX asmp core 0 empty"
#define	KASMP_SEMA_TX_CORE_1_EMPTY		"TX asmp core 1 empty"
#define	KASMP_SEMA_TX_CORE_2_EMPTY		"TX asmp core 2 empty"
#define	KASMP_SEMA_TX_CORE_3_EMPTY		"TX asmp core 3 empty"

// Mailboxes

#define	KASMP_MBOX_SEND_TO_CORE_0		"Send to core 0"
#define	KASMP_MBOX_SEND_TO_CORE_1		"Send to core 1"
#define	KASMP_MBOX_SEND_TO_CORE_2		"Send to core 2"
#define	KASMP_MBOX_SEND_TO_CORE_3		"Send to core 3"
#define	KASMP_MBOX_RECEIVE_FROM_CORE_0	"Receive from core 0"
#define	KASMP_MBOX_RECEIVE_FROM_CORE_1	"Receive from core 1"
#define	KASMP_MBOX_RECEIVE_FROM_CORE_2	"Receive from core 2"
#define	KASMP_MBOX_RECEIVE_FROM_CORE_3	"Receive from core 3"

// Internal messages

enum {
		KASMP_MESSAGE_VALID_FOR_CORE_0 = 1u,
		KASMP_MESSAGE_VALID_FOR_CORE_1,
		KASMP_MESSAGE_VALID_FOR_CORE_2,
		KASMP_MESSAGE_VALID_FOR_CORE_3,
		KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0,
		KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1,
		KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_2,
		KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_3
};

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
 * \brief Send data to core 0..3
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    toCore = KASMP_CORE_1;
 * uint32_t    order = 3;
 * uint32_t    size = 5;
 * uint8_t     send[5] = { 0, 1, 2, 3, 4 };
 *
 *    status = asmp_send(toCore, order, length, send);
 * \endcode
 *
 * \param[in]	toCore			Core number that will receive the message
 * \param[in]	order			Order (optional)
 * \param[in]	size			Size of the message
 * \param[in]	*send			Ptr on the sending buffer
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_GEERR	General error
 * \return		KERR_ASMP_SBFUL	The sender buffer is full
 * \return		KERR_ASMP_CORNA	The core number is not not allowed
 * \return		KERR_ASMP_LNBUB	The buffer size is too big
 *
 */
extern	int32_t	asmp_send(uint32_t toCore, uint32_t order, uint32_t size, const uint8_t *send);

/*!
 * \brief Receive data from core 0..3
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    fromCore;
 * uint32_t    order;
 * uint32_t    size;
 * uint8_t     receive[1024];
 *
 *    status = asmp_receive(&fromCore, &order, &size, &receive[0]);
 * \endcode
 *
 * \param[in]	*fromCore		Ptr on the core number that sent the message
 * \param[in]	*order			Ptr on the order
 * \param[in]	*size			Ptr on the size of the receive buffer
 * \param[in]	*receive		Ptr on the receiving buffer (the buffer size should be al lest KASMP_SZ_BUFFER)
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_GEERR	General error
 * \return		KERR_ASMP_CORNA	The core number is not not allowed
 * \return		KERR_ASMP_RBUEM	The receiver buffer is empty
 *
 */
extern	int32_t	asmp_receive(uint32_t *fromCore, uint32_t *order, uint32_t *size, uint8_t *receive);

/*!
 * \brief Get the running core
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    core;
 *
 *    status = asmp_getRunningCore(&core);
 * \endcode
 *
 * \param[in]	*core			Ptr on the running core number
 * \return		KERR_ASMP_NOERR	OK
 *
 */
extern	int32_t	asmp_getRunningCore(uint32_t *core);

/*!
 * \brief Get the reference of the running core
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    core;
 * char_t      *coreReference;
 *
 *    status = asmp_getReferenceCore(core, &coreReference);
 * \endcode
 *
 * \param[in]	core			Core number
 * \param[in]	**coreReference	Ptr on the core number reference
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_CORNA	The core number is not not allowed
 *
 */
extern	int32_t	asmp_getReferenceCore(uint32_t core, const char_t **coreReference);

/*!
 * \brief Get the handle of the RX full semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    core;
 * sema_t      *semaphore;
 *
 *    status = asmp_getRunningCore(&core);
 *    status = asmp_getSemaphoreRXFull(core, &semaphore);
 * \endcode
 *
 * \param[in]	core			Running core number
 * \param[in]	**semaphore		Ptr on the semaphore handle
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_CORNA	The core number is not not allowed
 *
 */
extern	int32_t	asmp_getSemaphoreRXFull(uint32_t core, sema_t **semaphore);

/*!
 * \brief Get the handle of the TX empty semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    core;
 * sema_t      *semaphore;
 *
 *    status = asmp_getRunningCore(&core);
 *    status = asmp_getSemaphoreTXEmpty(core, &semaphore);
 * \endcode
 *
 * \param[in]	core			Running core number
 * \param[in]	**semaphore		Ptr on the semaphore handle
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_CORNA	The core number is not not allowed
 *
 */
extern	int32_t	asmp_getSemaphoreTXEmpty(uint32_t core, sema_t **semaphore);

/*!
 * \brief Waiting for asmp ready
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = asmp_waitingForReady();
 * \endcode
 *
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_NORDY	The asmp is not ready
 *
 */
extern	int32_t	asmp_waitingForReady(void);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
