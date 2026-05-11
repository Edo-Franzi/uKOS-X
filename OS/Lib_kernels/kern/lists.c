/*
; lists.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - List management.
;
;			This module manages the list primitives.
;
; 			List system calls
; 			-----------------
;
;			void	chls_init(void);
;			void	lists_initialise(list_t *list);
;			void	lists_connect(list_t *list, proc_t *handle);
;			void	lists_disconnectConnect(list_t *list_d, list_t *list_c, proc_t *handle);
;
;			A process descriptor
;			--------------------
;
;			31					 			0
;			+-------------------------------+
;			| Ptr on proper list			+
;			+-------------------------------+
;			| Ptr on the back process		+
;			+-------------------------------+
;			| Ptr on the forward process	+
;			+-------------------------------+
;			| Specifications				+
;			+-------------------------------+
;			| Internal						+
;			+-------------------------------+
;			| Statistic 					+
;			+-------------------------------+
;			| Synchro						+
;			+-------------------------------+
;
;			A list ...
;			----------
;
;			31								0
;			+-------------------------------+
;			| Ptr on the first process		+
;			+-------------------------------+
;			| Ptr on the last process		+
;			+-------------------------------+
;			| Ptr on the current process	+
;			+-------------------------------+
;			| Number of processes linked	+
;			+-------------------------------+
;
;			Example of linked list ...
;			--------------------------
;
;			31								    0
;			+-----------------------------------+ X
;			| Ptr on the first process	 = A	+ ------+
;			+-----------------------------------+		|
;			| Ptr on the last process	 = B	+ ------|-------+
;			+-----------------------------------+		|		|
;			| Number of processes linked = 3	+		|		|
;			+-----------------------------------+		|		|
;													<---+		|
; Desc 1 	+-----------------------------------+ A <-------+	|
;			| Ptr on proper list		 = X 	+			|	|
;			+-----------------------------------+			|	|
;			| Ptr on the back process	 = 0	+			|	|
;			+-----------------------------------+			|	|
;			| Ptr on the forward process = C	+ ------+	|	|
;			+-----------------------------------+		|	|	|
;													<---|---|---+
; Desc 3	+-----------------------------------+ B	<---|---|---+
;			| Ptr on proper list		 = X 	+		|	|	|
;			+-----------------------------------+		|	|	|
;			| Ptr on the back process	 = C	+ ------|---|---|---+
;			+-----------------------------------+		|	|	|	|
;			| Ptr on the forward process = 0	+		|	|	|	|
;			+-----------------------------------+		|	|	|	|
;													<---|	|	|	|
; Desc 2 	+-----------------------------------+ C <-------|---|---+
;			| Ptr on proper list		 = X 	+			|	|
;			+-----------------------------------+			|	|
;			| Ptr on the back process    = A	+ ----------+	|
;			+-----------------------------------+				|
;			| Ptr on the forward process = B	+ --------------+
;			+-----------------------------------+
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

enum {
		KLIST_EMPTY = 0u,										// The list is empty
		KLIST_NORMAL,											// The list is not empty (normal)
		KLIST_ALONE,											// Only one process connected
		KLIST_FIRST,											// The process is the first of the list
		KLIST_MIDDLE,											// The process is in the middle of the list
		KLIST_LAST												// The process is the last of the list
};

// Prototypes

static	void	local_nextAction(uint8_t action, list_t *list, proc_t *handle);

/*
 * \brief Initialise a list
 *
 * \param[in]	*list	Ptr on the list
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
void	lists_initialise(list_t *list) {

	list->oFirst	  = nullptr;
	list->oLast		  = nullptr;
	list->oNbElements = 0u;
}

/*
 * \brief Connect a process to a list
 *
 * 2 possible cases:
 * - Case 1: IF (The list is empty)
 *           - THEN connect the "process" at the begin of the "list"
 *
 * - Case 2: IF (The list is not empty)
 *           - THEN connect the "process" to the last "process" of the "list"
 *
 * \param[in]	*list		Ptr on the list
 * \param[in]	*handle		Ptr on the handle
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
void	lists_connect(list_t *list, proc_t *handle) {

	if ((list == nullptr) || (handle == nullptr)) {
		LOG(KFATAL_SYSTEM, "list: nullptr pointers");
		exit(EXIT_OS_PANIC);
	}

	INTERRUPTION_OFF;

// Connect the process to the list_c

	(list->oFirst == nullptr) ? (local_nextAction(KLIST_EMPTY, list, handle)) : (local_nextAction(KLIST_NORMAL, list, handle));

	handle->oObject.oList    = list;
	handle->oObject.oForward = nullptr;
	list->oNbElements++;
	INTERRUPTION_RESTORE;
}

/*
 * \brief Disconnect a process from the list_d and connect it to the list_c
 *
 * Disconnect
 * ----------
 *
 * 4 possible cases:
 * - Case 1: IF (The process is alone)
 *           - THEN disconnect the "process" from the "list"
 *
 * - Case 2: IF (The process is the first)
 *           - THEN disconnect the "process" from the "list"
 *		       the next "process" becomes the "first"
 *
 * - Case 3: IF (The process is in the middle)
 *           - THEN disconnect the "process" from the "list"
 *		       connect the next "process" to the previous one
 *
 * - Case 4: IF (The process is at the end)
 *           - THEN disconnect the "process" from the "list"
 *		       the previous "process" becomes the "last" one
 *
 * Connect
 * -------
 *
 * 2 possible cases:
 * - Case 1: IF (The list is empty)
 *           - THEN connect the "process" at the begin of the "list"
 *
 * - Case 2: IF (The list is not empty)
 *           - THEN connect the "process" to the last "process" of the "list"
 *
 * \param[in]	*list_d		Ptr on the list (disconnect)
 * \param[in]	*list_c		Ptr on the list (connect)
 * \param[in]	*handle		Ptr on the handle
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
void	lists_disconnectConnect(list_t *list_d, list_t *list_c, proc_t *handle) {

	if ((list_c == nullptr) || (list_d == nullptr) || (handle == nullptr)) {
		LOG(KFATAL_SYSTEM, "list: nullptr pointers");
		exit(EXIT_OS_PANIC);
	}

	INTERRUPTION_OFF;

// Disconnect the process from the list_d

	if (handle->oObject.oBack == nullptr) {
		(handle->oObject.oForward == nullptr) ? (local_nextAction(KLIST_ALONE, list_d, handle)) : (local_nextAction(KLIST_FIRST,  list_d, handle));
	}
	else {
		(handle->oObject.oForward == nullptr) ? (local_nextAction(KLIST_LAST,  list_d, handle)) : (local_nextAction(KLIST_MIDDLE, list_d, handle));
	}

	handle->oObject.oBack    = nullptr;
	handle->oObject.oForward = nullptr;
	handle->oObject.oList    = nullptr;
	list_d->oNbElements--;

// Connect the process to the list_c

	(list_c->oFirst == nullptr) ? (local_nextAction(KLIST_EMPTY, list_c, handle)) : (local_nextAction(KLIST_NORMAL, list_c, handle));

	handle->oObject.oList    = list_c;
	handle->oObject.oForward = nullptr;
	list_c->oNbElements++;
	INTERRUPTION_RESTORE;
}

/*
 * \brief local_nextAction
 *
 * - The next action could be:
 *   - For the connection:
 *     - KLIST_EMPTY:	The list is empty
 *     - KLIST_NORMAL:	The list is not empty (normal)
 *   - For the disconnection:
 *     - KLIST_ALONE:	Only one process connected
 *     - KLIST_FIRST:	The process is the first of the list
 *     - KLIST_MIDDLE:	The process is in the middle of the list
 *     - KLIST_LAST:		The process is the last of the list
 *
 */
static	void	local_nextAction(uint8_t action, list_t *list, proc_t *handle) {

	switch (action) {

// Connect
// - The list is empty

		case KLIST_EMPTY: {
			list->oFirst = handle;
			list->oLast	 = handle;
			handle->oObject.oBack = nullptr;
			break;
		}

// Connect
// - The list is not empty (normal case)

		case KLIST_NORMAL: {
			list->oLast->oObject.oForward = handle;
			handle->oObject.oBack = list->oLast;
			list->oLast = handle;
			break;
		}

// Disconnect
// - Only one process connected

		case KLIST_ALONE: {
			list->oFirst = nullptr;
			list->oLast  = nullptr;
			break;
		}

// Disconnect
// - The process is the first of the list

		case KLIST_FIRST: {
			list->oFirst = handle->oObject.oForward;
			handle->oObject.oForward->oObject.oBack = nullptr;
			break;
		}

// Disconnect
// - The process is in the middle of the list

		case KLIST_MIDDLE: {
			handle->oObject.oForward->oObject.oBack = handle->oObject.oBack;
			handle->oObject.oBack->oObject.oForward = handle->oObject.oForward;
			break;
		}

// Disconnect
// - The process is the last of the list

		case KLIST_LAST: {
			list->oLast = handle->oObject.oBack;
			handle->oObject.oBack->oObject.oForward = nullptr;
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
}
