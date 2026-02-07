/*
; mailboxes.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - mailbox management.
;
;			This module implements the mailbox primitives.
;
;			Mailbox system calls
;			--------------------
;
;			void	mailboxes_init(void);
;			int32_t	kern_createMailbox(const char_t *identifier, mbox_t **handle);
;			int32_t	kern_setMailbox(mbox_t *handle, const mcnf_t *configure);
;			int32_t	kern_writeMailbox(mbox_t *handle, void *message, uint32_t size, uint32_t timeout);
;			int32_t	kern_writeQueue(mbox_t *handle, uintptr_t message, uint32_t timeout);
;			int32_t	kern_readMailbox(mbox_t *handle, void **message, uint32_t *size, uint32_t timeout);
;			int32_t	kern_readQueue(mbox_t *handle, uintptr_t *message, uint32_t timeout);
;			int32_t	kern_killMailbox(mbox_t *handle);
;			int32_t	kern_getMailboxById(const char_t *identifier, mbox_t **handle);
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
#include	"kern/private/private_kern.h"
#include	"kern/private/private_mailboxes.h"
#include	"kern/private/private_processes.h"
#include	"kern/private/private_identifiers.h"
#include	"kern/private/private_lists.h"

mbox_t		vKern_mbox[KNB_CORES][KKERN_NB_MAILBOXES];
uint16_t	vKern_nbMbox[KNB_CORES];
uint16_t	vKern_nbMaxMbox[KNB_CORES];

// Prototypes

static	int32_t	local_writeMailbox(uint32_t core, mbox_t *handle, void *message, uint32_t size, uint32_t timeout, bool *preemption);
static	int32_t	local_readMailbox(uint32_t core, mbox_t *handle, void **message, uint32_t *size, uint32_t timeout, bool *preemption);
static	void	local_write(uint32_t core, mbox_t *handle, void *message, uint32_t size, bool *preemption);
static	void	local_read(uint32_t core, mbox_t *handle, void **message, uint32_t *size, bool *preemption);

/*
 * \brief Initialise the manager
 *
 * - This function initialises the "mailboxes" manager
 *   Before using the manager functions, it is necessary to
 *   call this function
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	mailboxes_init(void) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	for (i = 0u; i < KKERN_NB_MAILBOXES; i++) {
		vKern_mbox[core][i].oIdentifier		= nullptr;
		vKern_mbox[core][i].oState			= 0u;
		vKern_mbox[core][i].oNbMaxPacks		= 0u;
		vKern_mbox[core][i].oNbUsedPacks	= 0u;
		vKern_mbox[core][i].oNbMaxUsedPacks	= 0u;
		vKern_mbox[core][i].oDataEntrySize	= 0u;
		vKern_mbox[core][i].oFIFO			= nullptr;
		vKern_mbox[core][i].oDataBuffer		= nullptr;
		vKern_mbox[core][i].oWrite			= nullptr;
		vKern_mbox[core][i].oRead			= nullptr;
		vKern_mbox[core][i].oDataWrite		= nullptr;
		lists_initialise(&vKern_mbox[core][i].oListEmpty);
		lists_initialise(&vKern_mbox[core][i].oListFull);
	}

	vKern_nbMbox[core]	  = 0u;
	vKern_nbMaxMbox[core] = 0u;
	DEBUG_KERN_TRACE("exit: OK");
}

/*
 * \brief Create a mailbox
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          mbox_t     *mailBox;
 * const    char_t     identifier[] = ”Mailbox 0”;
 *
 *    status = kern_createMailbox(identifier, &mailBox);
 * \endcode
 *
 * \param[in]	*identifier		Ptr on the mailbox identifier (nullptr = anonymous)
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_MBFUL	No more mailbox
 * \return		KERR_KERN_IDMBO	The mailbox identifier is already used
 *
 */
int32_t	kern_createMailbox(const char_t *identifier, mbox_t **handle) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

// Check if the identifier is already used (nullptr = anonymous)
// If the identifier is already used, then, return an error but
// with the handle of the previously created object

	if (identifier != nullptr) {
		for (i = 0; i < KKERN_NB_MAILBOXES; i++) {
			if (identifiers_cmpStrings(vKern_mbox[core][i].oIdentifier, identifier) == true) {
				*handle = &vKern_mbox[core][i];
				DEBUG_KERN_TRACE("exit: KO 1");
				INTERRUPTION_RESTORE;
				PRIVILEGE_RESTORE;
				return (KERR_KERN_IDMBO);
			}

		}
	}

	for (i = 0u; i < KKERN_NB_MAILBOXES; i++) {
		if (vKern_mbox[core][i].oIdentifier == nullptr) {
			vKern_mbox[core][i].oIdentifier  = (identifier == nullptr) ? (KMBOX_ANONYMOUS_ID) : (identifier);
			vKern_mbox[core][i].oState       = (1u<<BMBOX_INSTALLED) | (1u<<BMBOX_EMPTY);
			*handle = &vKern_mbox[core][i];

			vKern_nbMbox[core]    = (uint16_t)(vKern_nbMbox[core] + 1u);
			vKern_nbMaxMbox[core] = (vKern_nbMbox[core] > vKern_nbMaxMbox[core]) ? (vKern_nbMbox[core]) : (vKern_nbMaxMbox[core]);
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 2");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_MBFUL);
}

/*
 * \brief Set a mailbox
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * mcnf_t     configure;
 * mbox_t     *mailbox;
 *
 * // mbox referenced by pointer
 *
 *    configure.oNbMaxPacks    = 16;
 *    configure.oDataEntrySize = 0;
 *
 * // mbox with physical copy
 *
 *    configure.oNbMaxPacks    = 16;
 *    configure.oDataEntrySize = 123;
 *
 *    status = kern_setMailbox(mailbox, &configure);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMBO	The mailbox does not exist
 * \return		KERR_KERN_MBCNF	The mailbox configuration is not possible
 *
 */
int32_t	kern_setMailbox(mbox_t *handle, const mcnf_t *configure) {
	uint32_t	core, i;
	mboxPack_t	*fifoArray;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								 { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOMBO); }
	if ((handle->oState & (1u<<BMBOX_INSTALLED)) == 0u)  { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOMBO); }
	if ((handle->oState & (1u<<BMBOX_CONFIGURED)) != 0u) { DEBUG_KERN_TRACE("exit: KO 3"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_MBCNF); }
	if (configure->oNbMaxPacks == 0u)				     { DEBUG_KERN_TRACE("exit: KO 4"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_MBCNF); }

// Reserve the mailbox memory

	fifoArray = (mboxPack_t *)memo_malloc(KMEMO_ALIGN_8, (configure->oNbMaxPacks * sizeof(mboxPack_t)), "mbox");
	if (fifoArray == nullptr) {
		DEBUG_KERN_TRACE("exit: KO 5");
		INTERRUPTION_RESTORE;
		PRIVILEGE_RESTORE;
		return (KERR_KERN_MBCNF);
	}

	if (configure->oDataEntrySize > 0u) {
		handle->oDataBuffer = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (configure->oNbMaxPacks * configure->oDataEntrySize), "mbox data");
		if (handle->oDataBuffer == nullptr) {
			memo_free(fifoArray);
			DEBUG_KERN_TRACE("exit: KO 6");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_MBCNF);
		}

		handle->oDataWrite	= handle->oDataBuffer;
		handle->oState	   |= (1u<<BMBOX_BY_COPY);
	}

	handle->oNbMaxPacks		= configure->oNbMaxPacks;
	handle->oNbUsedPacks	= 0u;
	handle->oDataEntrySize	= configure->oDataEntrySize;
	handle->oFIFO			= fifoArray;
	handle->oWrite			= fifoArray;
	handle->oRead			= fifoArray;

	for (i = 0u; i < configure->oNbMaxPacks; i++) {
		handle->oFIFO[i].oBuff = 0u;
		handle->oFIFO[i].oSize = 0u;

		#if (KKERN_WITH_STATISTICS_S == true)
		handle->oFIFO[i].oReadTimeStmp  = 0u;
		handle->oFIFO[i].oWriteTimeStmp = 0u;
		#endif
	}

	handle->oState |= (1u<<BMBOX_CONFIGURED);
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Write a message in the mailbox
 *
 * Call example in C:
 *
 * \code{.c}
 * #define     KSIZE    5
 * int32_t     status;
 * uint32_t    timeout = 1234;
 * uint8_t     message[KSIZE] = {1,2,3,4,5};
 * mbox_t      *mailBox;
 *
 *    status = kern_writeMessage(mailBox, message, KSIZE, timeout);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	*message		Ptr on the message
 * \param[in]	size			Size of the message
 * \param[in]	timeout			Timeout (1-ms of resolution)
 * \param[in]	-				KWAIT_INFINITY, waiting forever
 * \param[in]	-				KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMBO	The mailbox does not exist
 * \return		KERR_KERN_MBNCF	The mailbox is not configured
 * \return		KERR_KERN_MBKIL	The mailbox has been killed (with process in its list)
 * \return		KERR_KERN_MBSIZ	The size of the message is bigger than the size of the configured mailbox
 * \return		KERR_KERN_TIMEO	Timeout
 *
 */
int32_t	kern_writeMailbox(mbox_t *handle, void *message, uint32_t size, uint32_t timeout) {
	bool		preemption = false;
	uint32_t	core;
	int32_t		status;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	status = local_writeMailbox(core, handle, message, size, timeout, &preemption);
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Write a message in the queue
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint32_t     timeout = 1234;
 * uintptr_t    message = 0x2345;
 * mbox_t       *mailBox;
 *
 *    status = kern_writeQueue(mailBox, message, timeout);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	message			Message
 * \param[in]	timeout			Timeout (1-ms of resolution)
 * \param[in]	-				KWAIT_INFINITY, waiting forever
 * \param[in]	-				KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMBO	The mailbox does not exist
 * \return		KERR_KERN_MBNCF	The mailbox is not configured
 * \return		KERR_KERN_MBKIL	The mailbox has been killed (with process in its list)
 * \return		KERR_KERN_TIMEO	Timeout
 *
 */
int32_t	kern_writeQueue(mbox_t *handle, uintptr_t message, uint32_t timeout) {
	bool		preemption = false;
	uint32_t	core;
	int32_t		status;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	status = local_writeMailbox(core, handle, (void *)message, 1, timeout, &preemption);
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Read a message from the mailbox
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    timeout = 1234;
 * uint8_t     size, *message:
 * mbox_t      *mailBox;
 *
 *    status = kern_readMessage(mailBox, &message, &size, timeout);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	**message		Ptr on the message (return nullptr in case of error)
 * \param[out]	*size			Ptr on the	size of the message
 * \param[in]	timeout			Timeout (1-ms of resolution)
 * \param[in]	-				KWAIT_INFINITY, waiting forever
 * \param[in]	-				KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMBO	The mailbox does not exist
 * \return		KERR_KERN_MBNCF	The mailbox is not configured
 * \return		KERR_KERN_MBKIL	The mailbox has been killed (with process in its list)
 * \return		KERR_KERN_TIMEO	Timeout
 *
 */
int32_t	kern_readMailbox(mbox_t *handle, void **message, uint32_t *size, uint32_t timeout) {
	bool		preemption = false;
	uint32_t	core;
	int32_t		status;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	status = local_readMailbox(core, handle, message, size, timeout, &preemption);
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Read a message from the queue
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint32_t     timeout = 1234;
 * uintptr_t    message:
 * mbox_t       *mailBox;
 *
 *    status = kern_readQueue(mailBox, &message, timeout);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	*message		Ptr on the message (return 0 in case of error)
 * \param[in]	timeout			Timeout (1-ms of resolution)
 * \param[in]	-				KWAIT_INFINITY, waiting forever
 * \param[in]	-				KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMBO	The mailbox does not exist
 * \return		KERR_KERN_MBNCF	The mailbox is not configured
 * \return		KERR_KERN_MBKIL	The mailbox has been killed (with process in its list)
 * \return		KERR_KERN_TIMEO	Timeout
 *
 */
int32_t	kern_readQueue(mbox_t *handle, uintptr_t *message, uint32_t timeout) {
	bool		preemption = false;
	int32_t		status;
	uint32_t	core, size;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	size = 1;
	status = local_readMailbox(core, handle, (void **)message, &size, timeout, &preemption);
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Kill the mailbox
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * mbox_t     *mailBox;
 *
 *    status = kern_killMailbox(mailBox);
 * \endcode
 *
 * - If (mailbox still contain messages)
 *   Then return error
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMBO	The mailbox does not exist
 *
 */
int32_t	kern_killMailbox(mbox_t *handle) {
	bool		preemption = false;
	uint32_t	core;
	proc_t		*process;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)             				     { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOMBO); }
	if ((handle->oState & (1u<<BMBOX_INSTALLED)) == 0u)  { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOMBO); }
	if ((handle->oState & (1u<<BMBOX_CONFIGURED)) != 0u) {

// Disconnect the waiting processes from the mailbox empty list

		while (handle->oListEmpty.oNbElements > 0u) {
			process = handle->oListEmpty.oFirst;
			process->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_MBOX_E);
			lists_disconnectConnect(process->oObject.oList, &vKern_listExec[core], process);
			process->oInternal.oStatus = KERR_KERN_MBKIL;

// If the ready process has a higher priority, then preemption occurs

			preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);
		}

// Disconnect the waiting processes from the mailbox full list

		while (handle->oListFull.oNbElements > 0u) {
			process = handle->oListFull.oFirst;
			process->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_MBOX_F);
			lists_disconnectConnect(process->oObject.oList, &vKern_listExec[core], process);
			process->oInternal.oStatus = KERR_KERN_MBKIL;

// If the ready process has a higher priority, then preemption occurs

			preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);
		}

		memo_free(handle->oFIFO);

		if (handle->oDataBuffer != nullptr) {
			memo_free(handle->oDataBuffer);
		}
	}
	handle->oIdentifier	   = nullptr;
	handle->oState		   = 0u;
	handle->oNbMaxPacks	   = 0u;
	handle->oNbUsedPacks   = 0u;
	handle->oDataEntrySize = 0u;
	handle->oFIFO		   = nullptr;
	handle->oDataBuffer	   = nullptr;
	handle->oWrite		   = nullptr;
	handle->oRead		   = nullptr;
	handle->oDataWrite	   = nullptr;

	if (vKern_nbMbox[core] != 0u) { vKern_nbMbox[core] = (uint16_t)(vKern_nbMbox[core] - 1u); }
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Get the handle of a mailbox by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          mbox_t     *mailBox;
 * const    char_t     identifier[] = ”Mailbox 0”;
 *
 *    status = kern_getMailboxById(identifier, &mailBox);
 * \endcode
 *
 * - This function returns the handle of the mailbox
 *
 * \param[in]	*identifier		Ptr on the mailbox identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMBO	The mailbox does not exist
 *
 */
int32_t	kern_getMailboxById(const char_t *identifier, mbox_t **handle) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

	for (i = 0u; i < KKERN_NB_MAILBOXES; i++) {
		if (identifiers_cmpStrings(vKern_mbox[core][i].oIdentifier, identifier) == true) {
			*handle = &vKern_mbox[core][i];
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOMBO);
}

// Local routines
// ==============

/*
 * \brief local_writeMailbox
 *
 * - Generic write to a mailbox or queue
 *
 * \param[in]	core			Core number
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	*message		Ptr on the message
 * \param[in]	size			Size of the message
 * \param[in]	timeout			Timeout (1-ms of resolution)
 * \param[in]	-				KWAIT_INFINITY, waiting forever
 * \param[in]	-				KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \param[out]	*preemption		Ptr on the preemption
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMBO	The mailbox does not exist
 * \return		KERR_KERN_MBNCF	The mailbox is not configured
 * \return		KERR_KERN_MBKIL	The mailbox has been killed (with process in its list)
 * \return		KERR_KERN_MBSIZ	The size of the message is bigger than the size of the configured mailbox
 * \return		KERR_KERN_TIMEO	Timeout
 *
 */
static	int32_t	local_writeMailbox(uint32_t core, mbox_t *handle, void *message, uint32_t size, uint32_t timeout,  bool *preemption) {
	uint32_t	i, synchro, wkTimeout;

	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if ((IS_EXCEPTION) && (timeout != 0u))												   { DEBUG_KERN_TRACE("exit: KO 1"); return (KERR_KERN_FRISR); }
	if (handle == nullptr)																   { DEBUG_KERN_TRACE("exit: KO 2"); return (KERR_KERN_NOMBO); }
	if ((handle->oState  & (1u<<BMBOX_INSTALLED)) == 0u)								   { DEBUG_KERN_TRACE("exit: KO 3"); return (KERR_KERN_NOMBO); }
	if ((handle->oState  & (1u<<BMBOX_CONFIGURED)) == 0u)								   { DEBUG_KERN_TRACE("exit: KO 4"); return (KERR_KERN_MBNCF); }
	if (((handle->oState & (1u<<BMBOX_BY_COPY)) != 0u) && (size > handle->oDataEntrySize)) { DEBUG_KERN_TRACE("exit: KO 5"); return (KERR_KERN_MBSIZ); }

// -------------------------- inputs --------------------------		-------------------------------------- output ---------------------------------------
//
// IF (timeout value == ...)										THEN (vKern_runProc[core]->oInternal.oTimeout = ...)	AND (wkTimeout = ...)
//
// == KWAIT_INFINITY			  									= KWAIT_INFINITY										= KWAIT_INFINITY
//					 == KWAIT_REMAINING_TIMEOUT					    = vKern_runProc[core]->oInternal.oTimeout				= vKern_runProc[core]->oInternal.oTimeout
//							  				    == timeout value	= (timeout value / unit)								= (timeout value / unit)

	wkTimeout = (timeout == KWAIT_INFINITY)			 ? (KWAIT_INFINITY)							 : (timeout / KKERN_TIC_TIME);
	wkTimeout = (timeout == KWAIT_REMAINING_TIMEOUT) ? (vKern_runProc[core]->oInternal.oTimeout) : (wkTimeout);
	if (!(IS_EXCEPTION)) {
		vKern_runProc[core]->oInternal.oTimeout = wkTimeout;
	}

	if ((handle->oState  & (1u<<BMBOX_FULL)) == 0u) {
		local_write(core, handle, message, size, preemption);
		DEBUG_KERN_TRACE("exit: OK");
		return (KERR_KERN_NOERR);
	}

	if (wkTimeout > 0u) {
		i = (uint32_t)(((uintptr_t)handle - (uintptr_t)&vKern_mbox[core][0]) / sizeof(mbox_t));
		synchro = KKERN_MSG_WAIT_MBOX_F + (i & 0x0000FFFFu);
		(void)synchro;

		GOTO_KERN_M(synchro);
		if (vKern_runProc[core]->oInternal.oStatus == KERR_KERN_NOERR) {
			local_write(core, handle, message, size, preemption);
			DEBUG_KERN_TRACE("exit: OK");
			return (KERR_KERN_NOERR);
		}

		DEBUG_KERN_TRACE("exit: ->");
		return (vKern_runProc[core]->oInternal.oStatus);
	}

	DEBUG_KERN_TRACE("exit: KO 4");
	return (KERR_KERN_TIMEO);
}

static	void	local_write(uint32_t core, mbox_t *handle, void *message, uint32_t size, bool *preemption) {
	uint32_t	nbMaxPacks;
	proc_t		*process;

// Write the message

	nbMaxPacks = handle->oNbMaxPacks;
	handle->oWrite->oSize = size;

	if (handle->oDataBuffer != nullptr) {
		memcpy((void *)(unsigned char *)handle->oDataWrite, (const void *)(const unsigned char *)message, (size_t)size);
		handle->oWrite->oBuff = handle->oDataWrite;
		handle->oDataWrite = (&handle->oDataWrite[handle->oDataEntrySize] >= &handle->oDataBuffer[(size_t)handle->oDataEntrySize * (size_t)handle->oNbMaxPacks]) ? handle->oDataBuffer : &handle->oDataWrite[handle->oDataEntrySize];
	}
	else {
		handle->oWrite->oBuff = (uint8_t *)message;
	}

	#if (KKERN_WITH_STATISTICS_S == true)
	uint64_t	timeStmp;

	kern_readTickCount(&timeStmp);
	handle->oWrite->oReadTimeStmp  = 0u;
	handle->oWrite->oWriteTimeStmp = timeStmp;
	handle->oWrite->oProcess	   = (IS_EXCEPTION) ? (nullptr) : (vKern_runProc[core]);
	#endif

	handle->oWrite++;
	handle->oNbUsedPacks++;
	handle->oNbMaxUsedPacks = (handle->oNbUsedPacks > handle->oNbMaxUsedPacks) ? (handle->oNbUsedPacks) : (handle->oNbMaxUsedPacks);
	handle->oState &= (uint16_t)~(1u<<BMBOX_EMPTY);

	handle->oWrite = (handle->oWrite == &handle->oFIFO[nbMaxPacks]) ? (&handle->oFIFO[0])				   : (handle->oWrite);
					 (handle->oWrite == handle->oRead)              ? (handle->oState |= (1u<<BMBOX_FULL)) : (handle->oState |= 0u);

	if (handle->oListEmpty.oNbElements > 0u) {

// If a reading process was suspended, then, reactivate it

		process = handle->oListEmpty.oFirst;
		process->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_MBOX_E);
		lists_disconnectConnect(&handle->oListEmpty, &vKern_listExec[core], process);
		process->oInternal.oStatus = KERR_KERN_NOERR;

// If the ready process has a higher priority, then preemption occurs

		*preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);
	}
}

/*
 * \brief local_readMailbox
 *
 * - Generic read from a mailbox or queue
 *
 * \param[in]	core			Core number
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	**message		Ptr on the message (return nullptr in case of error)
 * \param[out]	*size			Ptr on the size of the message
 * \param[in]	timeout			Timeout (1-ms of resolution)
 * \param[in]	-				KWAIT_INFINITY, waiting forever
 * \param[in]	-				KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \param[out]	*preemption		Ptr on the preemption
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMBO	The mailbox does not exist
 * \return		KERR_KERN_MBNCF	The mailbox is not configured
 * \return		KERR_KERN_MBKIL	The mailbox has been killed (with process in its list)
 * \return		KERR_KERN_TIMEO	Timeout
 *
 */
static	int32_t	local_readMailbox(uint32_t core, mbox_t *handle, void **message, uint32_t *size, uint32_t timeout,  bool *preemption) {
	uint32_t	i, synchro, wkTimeout;

	vKern_runProc[core]->oStatistic.oNbKernCalls++;

	if ((IS_EXCEPTION) && (timeout != 0u))	    		 { DEBUG_KERN_TRACE("exit: KO 1"); return (KERR_KERN_FRISR); }
	if (handle == nullptr)								 { DEBUG_KERN_TRACE("exit: KO 2"); return (KERR_KERN_NOMBO); }
	if ((handle->oState & (1u<<BMBOX_INSTALLED)) == 0u)  { DEBUG_KERN_TRACE("exit: KO 3"); return (KERR_KERN_NOMBO); }
	if ((handle->oState & (1u<<BMBOX_CONFIGURED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 4"); return (KERR_KERN_MBNCF); }

	if ((handle->oState & (1u<<BMBOX_BY_COPY)) == 0u) {
		*message = nullptr;
	}

// -------------------------- inputs --------------------------		-------------------------------------- output ---------------------------------------
//
// IF (timeout value == ...)										THEN (vKern_runProc[core]->oInternal.oTimeout = ...)	AND (wkTimeout = ...)
//
// == KWAIT_INFINITY			  									= KWAIT_INFINITY										= KWAIT_INFINITY
//					 == KWAIT_REMAINING_TIMEOUT					    = vKern_runProc[core]->oInternal.oTimeout				= vKern_runProc[core]->oInternal.oTimeout
//							  				    == timeout value	= (timeout value / unit)								= (timeout value / unit)

	wkTimeout = (timeout == KWAIT_INFINITY)			 ? (KWAIT_INFINITY)							 : (timeout / KKERN_TIC_TIME);
	wkTimeout = (timeout == KWAIT_REMAINING_TIMEOUT) ? (vKern_runProc[core]->oInternal.oTimeout) : (wkTimeout);
	if (!(IS_EXCEPTION)) {
		vKern_runProc[core]->oInternal.oTimeout = wkTimeout;
	}

	if ((handle->oState & (1u<<BMBOX_EMPTY)) == 0u) {
		local_read(core, handle, message, size, preemption);
		DEBUG_KERN_TRACE("exit: OK");
		return (KERR_KERN_NOERR);
	}

	if (wkTimeout > 0u) {
		i = (uint32_t)(((uintptr_t)handle - (uintptr_t)&vKern_mbox[core][0]) / sizeof(mbox_t));
		synchro = KKERN_MSG_WAIT_MBOX_E + (i & 0x0000FFFFu);
		(void)synchro;

		GOTO_KERN_M(synchro);
		if (vKern_runProc[core]->oInternal.oStatus == KERR_KERN_NOERR) {
			local_read(core, handle, message, size, preemption);
			DEBUG_KERN_TRACE("exit: OK");
			return (KERR_KERN_NOERR);
		}

		DEBUG_KERN_TRACE("exit: ->");
		return (vKern_runProc[core]->oInternal.oStatus);
	}

	DEBUG_KERN_TRACE("exit: KO 4");
	return (KERR_KERN_TIMEO);
}

static	void	local_read(uint32_t core, mbox_t *handle, void **message, uint32_t *size, bool *preemption) {
	uint32_t	nbMaxPacks, copySize;
	proc_t		*process;

	UNUSED(core);

// Read the message

	nbMaxPacks = handle->oNbMaxPacks;

	if (handle->oDataBuffer != nullptr) {
		copySize = (((*size) > handle->oRead->oSize) || (*size == 0u)) ? handle->oRead->oSize : (*size);
		if ((copySize > 0u) && (*message != nullptr)) {
			memcpy((void *)(unsigned char *)(*message), (const void *)(const unsigned char *)handle->oRead->oBuff, (size_t)copySize);
		}
		*size = copySize;
	}
	else {
		*message = handle->oRead->oBuff;
		*size	 = handle->oRead->oSize;
	}

	#if (KKERN_WITH_STATISTICS_S == true)
	uint64_t	timeStmp;

	kern_readTickCount(&timeStmp);
	handle->oRead->oReadTimeStmp = timeStmp;
	#endif

	handle->oRead++;
	handle->oNbUsedPacks--;
	handle->oState &= (uint16_t)~(1u<<BMBOX_FULL);

	handle->oRead = (handle->oRead == &handle->oFIFO[nbMaxPacks]) ? (&handle->oFIFO[0])					  : (handle->oRead);
					(handle->oRead == handle->oWrite)             ? (handle->oState |= (1u<<BMBOX_EMPTY)) : (handle->oState |= 0u);

	if (handle->oListFull.oNbElements > 0u) {

// If a writing process was suspended, then, reactivate it

		process = handle->oListFull.oFirst;
		process->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_MBOX_F);
		lists_disconnectConnect(&handle->oListFull, &vKern_listExec[core], process);
		process->oInternal.oStatus = KERR_KERN_NOERR;

// If the ready process has a higher priority, then preemption occurs

		*preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);
	}
}
