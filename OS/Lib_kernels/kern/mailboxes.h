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

#pragma	once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup mailboxes Mailboxes
 *
 * \brief Mailboxes
 *
 * Mailbox & queue management
 *
 * @{
 */

// Structure of the pack for the mailbox
// -------------------------------------

typedef	struct	mcnf		mcnf_t;
typedef	struct	mboxPack	mboxPack_t;

struct	mcnf {
				uint32_t	oNbMaxPacks;						// Mailbox (maximum number of packs)
				uint32_t	oDataEntrySize;						// If > 0, will define the maximum size of each entry to be copied
};

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	void	mailboxes_init(void);

/*!
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
extern	int32_t	kern_createMailbox(const char_t *identifier, mbox_t **handle);

/*!
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
extern	int32_t	kern_setMailbox(mbox_t *handle, const mcnf_t *configure);

/*!
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
extern	int32_t	kern_writeMailbox(mbox_t *handle, void *message, uint32_t size, uint32_t timeout);

/*!
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
extern	int32_t	kern_writeQueue(mbox_t *handle, uintptr_t message, uint32_t timeout);

/*!
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
extern	int32_t	kern_readMailbox(mbox_t *handle, void **message, uint32_t *size, uint32_t timeout);

/*!
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
extern	int32_t	kern_readQueue(mbox_t *handle, uintptr_t *message, uint32_t timeout);

/*!
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
extern	int32_t	kern_killMailbox(mbox_t *handle);

/*!
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
extern	int32_t	kern_getMailboxById(const char_t *identifier, mbox_t **handle);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
