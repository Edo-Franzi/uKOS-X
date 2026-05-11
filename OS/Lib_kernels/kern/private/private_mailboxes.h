/*
; private_mailboxes.
; ==================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - mailbox box management.
;
;			Private uKernel variables.
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
 * \addtogroup mailboxes
 * @{
 */

/*!
 * \defgroup private_mailboxes Private mailboxes
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#define	KMBOX_ANONYMOUS_ID	"Mbox_anonymous"

struct	mboxPack {
			uint8_t		*oBuff;									// Ptr on the memory message
			uint32_t	oSize;									// Size of the message

			#if (KKERN_WITH_STATISTICS_S == true)
			uint64_t	oReadTimeStmp;							// Read time stamp
			uint64_t	oWriteTimeStmp;							// Write time stamp
			proc_t		*oProcess;								// Source process of the message
			#endif
};

struct	mbox {
	const	char_t		*oIdentifier;							// Mailbox identifier
			uint16_t	oState;									// Mailbox state
			#define		BMBOX_INSTALLED		0u					// Mailbox installed
			#define		BMBOX_CONFIGURED	1u					// Mailbox configured
			#define		BMBOX_EMPTY			2u					// Mailbox empty
			#define		BMBOX_FULL			3u					// Mailbox full
			#define		BMBOX_BY_COPY		4u					// Mailbox is copying data

			uint32_t	oNbMaxPacks;							// Maximum number of packs
			uint32_t	oNbUsedPacks;							// Used number of packs
			uint32_t	oNbMaxUsedPacks;						// Maximum number of used packs
			uint32_t	oDataEntrySize;							// Data entry size in copy mode
			mboxPack_t	*oFIFO;									// Fifo of packs
			uint8_t		*oDataBuffer;							// Data copy array
			mboxPack_t	*oWrite;								// Fifo write pointer
			mboxPack_t	*oRead;									// Fifo read pointer
			uint8_t		*oDataWrite;							// Data buffer write pointer
			list_t		oListEmpty;								// Mailbox empty list
			list_t		oListFull;								// Mailbox full list
};

extern	mbox_t		vKern_mbox[KNB_CORES][KKERN_NB_MAILBOXES];	// Mailboxes
extern	uint16_t	vKern_nbMbox[KNB_CORES];					// Nb of used mailboxes
extern	uint16_t	vKern_nbMaxMbox[KNB_CORES];					// Max number of used mailboxes

/**@}*/
/**@}*/
/**@}*/
