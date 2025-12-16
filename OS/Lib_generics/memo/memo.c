/*
; memo.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-02-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		memo manager.
;
;			!!! The memo manager is designed to share the same heap
;			between all the cores. For a multi-core system KNB_CORES > 1
;			it is mandatory to use the spin lock/unlock technique for
;			the core arbitration.
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
#include	"linker.h"
#include	"kern/private/private_processes.h"
#include	"memo/private/private_memo.h"

#if (defined(CONFIG_MAN_MEMO_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"memo         memo manager.                             (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "memo manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

MODULE(
	Memo,							// Module name (the first letter has to be upper case)
	KID_FAM_GENERICS,				// Family (defined in the module.h)
	KNUM_MEMO,						// Module identifier (defined in the module.h)
	NULL,							// Address of the initialisation code (early pre-init)
	NULL,							// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,							// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

STRG_LOC_CONST(aStrIdSe[]) = "Critical_malloc";

static	mutx_t				*vMutex[KNB_CORES];									// Ptr on the memo_malloc mutex
static	void				*vAddressFreeDelayed[KNB_CORES] = MCSET(NULL);		//
static	bool				vFreeDelayed[KNB_CORES] = MCSET(false);				//

// vMemo_heapInfo has not to be indexed with core information!!!

		mallocHeapInfo_t	vMemo_heapInfo = {
								.oUsdMemory = 0u,								// Used memory
								.oNbBlocks = 0u,								// Number of blocks
								.oNbMaxBlocks = 0u,								// Max number of blocks
								.oUsdMaxMemory = 0u,							// Max used memory
								.oFailedAllocations = 0u						// Number of failed allocations
							};

		#if (KNB_CORES > 1)
		spinlock_t			vMemo = SPIN_LOCK_INIT;
		#endif

// Prototypes

static	void	local_init(void);

/*
 * \brief Memory allocation
 *
 * Call example in C:
 *
 * \code{.c}
 * uint8_t    *memory;
 *
 *    memory = (uint8_t *)memo_malloc(KMEMO_ALIGN_32, 1234, "xyz");
 * \endcode
 *
 * \param[in]	memoAlignement	KMEMO_ALIGN_4
 * \param[in]	-				KMEMO_ALIGN_8
 * \param[in]	-				KMEMO_ALIGN_16
 * \param[in]	-				KMEMO_ALIGN_32
 * \param[in]	size			Size of the memory to allocate
 * \param[in]	*identifier		Ptr on the identifier
 * \return		NULL			Memory block not allocated
 * \return		address			Memory address of the allocated block
 *
 */
void	*memo_malloc(memoAlignement_t memoAlignement, uint32_t size, const char_t *identifier) {
	memoMab_t			*curBlock, *newBlock, *nexBlock;
	uint32_t			core, wkSize = size, nb, nbBlocks, available, pad;
	uintptr_t			startNewBlock, paddedStartNewBlock, deltaNewBlock;
	mallocHeapInfo_t	*heapInfo;

	core = GET_RUNNING_CORE;

// memo_malloc not allowed inside exceptions

	PRIVILEGE_ELEVATE;
	if (IS_EXCEPTION) { PRIVILEGE_RESTORE; return (NULL); }

	local_init();

	SPIN_LOCK(vMemo);
	kern_lockMutex(vMutex[core], KWAIT_INFINITY);

	switch (memoAlignement) {
		case KMEMO_ALIGN_4:  { wkSize = (wkSize + 3u)  & 0xFFFFFFFCu; pad = 3u;  break; }
		case KMEMO_ALIGN_8:  { wkSize = (wkSize + 7u)  & 0xFFFFFFF8u; pad = 7u;  break; }
		case KMEMO_ALIGN_16: { wkSize = (wkSize + 15u) & 0xFFFFFFF0u; pad = 15u; break; }
		case KMEMO_ALIGN_32: { wkSize = (wkSize + 31u) & 0xFFFFFFE0u; pad = 31u; break; }
		default:			 { wkSize = (wkSize + 7u)  & 0xFFFFFFF8u; pad = 7u;  break; }
	}

// From the start of the heap memory ...
// Verify if there are enough place for a new memory allocation
//
// Prepare some pointers to take in account the heap

	curBlock = ALIGNED_PTR(memoMab_t, linker_stHeap);

	heapInfo = &vMemo_heapInfo;

// Looking for a memory hole that can accommodate
// the new allocation demand. Take in account demanded alignment

	nbBlocks = heapInfo->oNbBlocks;
	for (nb = 0u; nb < nbBlocks; nb++) {
		if (curBlock->oMabSignature != (uint32_t)KMAB_SIGNATURE) {
			LOG(KFATAL_MANAGER, "memo: malloc broken");
			exit(EXIT_OS_PANIC_MALLOC_BROKEN);
		}

		if ((sizeof(memoMab_t) + wkSize + pad) <= curBlock->oSzAvailable) {

// The newBlock has to be aligned with the demanded one

			startNewBlock		   = (uintptr_t)curBlock + (uintptr_t)sizeof(memoMab_t) + (uintptr_t)curBlock->oSzAllocated;
			paddedStartNewBlock	   = (startNewBlock + (uintptr_t)pad) & (~(uintptr_t)pad);
			deltaNewBlock		   = paddedStartNewBlock - startNewBlock;

			newBlock			   = (memoMab_t *)paddedStartNewBlock;
			available			   = (uint32_t)(curBlock->oSzAvailable - (uint32_t)deltaNewBlock - sizeof(memoMab_t) - wkSize);
			curBlock->oSzAvailable = (uint32_t)deltaNewBlock;

			newBlock->oProcess	   = vKern_runProc[core];
			newBlock->oSzAllocated = wkSize;
			newBlock->oSzAvailable = available;
			newBlock->oPadBlock	   = (uint32_t)deltaNewBlock;

// Cross link (current <--> new)
// Adjust the number of blocks and the available memory
// Add the bloc signature
// Add the bloc identifier

			newBlock->oPtrPreBlock  =  curBlock;
			nexBlock				=  curBlock->oPtrNexBlock;
			curBlock->oPtrNexBlock  =  newBlock;

			newBlock->oMabSignature =  (uint32_t)KMAB_SIGNATURE;
			newBlock->oIdentifier   =  identifier;

			if (nexBlock != NULL) { nexBlock->oPtrPreBlock = newBlock; newBlock->oPtrNexBlock = nexBlock; }
			else                  {                                    newBlock->oPtrNexBlock = NULL;     }

			heapInfo->oNbBlocks++;
			heapInfo->oNbMaxBlocks  =  (heapInfo->oNbBlocks > heapInfo->oNbMaxBlocks) ? (heapInfo->oNbBlocks) : (heapInfo->oNbMaxBlocks);
			heapInfo->oUsdMemory	+= (uint32_t)(sizeof(memoMab_t) + (deltaNewBlock + wkSize));
			heapInfo->oUsdMaxMemory =  (heapInfo->oUsdMemory > heapInfo->oUsdMaxMemory) ? (heapInfo->oUsdMemory) : (heapInfo->oUsdMaxMemory);

			kern_unlockMutex(vMutex[core]);
			SPIN_UNLOCK(vMemo);

			PRIVILEGE_RESTORE;
			return ((void *)((uintptr_t)newBlock + (uintptr_t)sizeof(memoMab_t)));
		}

		curBlock = curBlock->oPtrNexBlock;
	}
	heapInfo->oFailedAllocations++;
	kern_unlockMutex(vMutex[core]);
	SPIN_UNLOCK(vMemo);

	PRIVILEGE_RESTORE;
	return (NULL);
}

/*
 * \brief Memory re-allocation
 *
 * Call example in C:
 *
 * \code{.c}
 * uint8_t    *memory;
 * uint8_t    *address;
 *
 *    memory = (uint8_t *)memo_realloc(KMEMO_ALIGN_32, address, 1234, "xyz");
 * \endcode
 *
 * \param[in]	memoAlignement	KMEMO_ALIGN_4
 * \param[in]	-				KMEMO_ALIGN_8
 * \param[in]	-				KMEMO_ALIGN_16
 * \param[in]	-				KMEMO_ALIGN_32
 * \param[in]	*address		Ptr on the address
 * \param[in]	size			Size of the memory to allocate
 * \param[in]	*identifier		Ptr on the identifier
 * \return		NULL			Memory block not allocated
 * \return		address			Memory address of the allocated block
 *
 */
void	*memo_realloc(memoAlignement_t memoAlignement, void *address, uint32_t size, const char_t *identifier) {
			uint32_t	oldSize, copySize;
			void		*newAddress;
	const	memoMab_t	*curBlock;

// First case, address == NULL, same behaviour as for the memo_malloc
// Second case, size == 0, same behaviour as for the memo_free

	if (address == NULL) {
		newAddress = memo_malloc(memoAlignement, size, identifier);
		return (newAddress);
	}

	if (size == 0u) {
		memo_free(address);
		return (NULL);
	}

// Third case, try to allocate a new block
// Copy the old block in the new one
// Free the old block

	newAddress = memo_malloc(memoAlignement, size, identifier);
	if (newAddress == NULL) {
		return (NULL);
	}

	curBlock = (const memoMab_t *)((uintptr_t)address - (uintptr_t)sizeof(memoMab_t));
	oldSize = curBlock->oSzAllocated;

	copySize = (oldSize < size) ? (oldSize) : (size);
	memcpy(newAddress, address, copySize);

	memo_free(address);
	return (newAddress);
}

/*
 * \brief Read the information about the allocated block
 *
 * Call example in C:
 *
 * \code{.c}
 *    memoMallocInf_t    allocInfo;
 *
 *    memo_readBlocInfo(memory, &allocInfo);
 * \endcode
 *
 * \param[in]	*address		Ptr on the start address of the block to get the information about
 * \param[out]	*allocInfo		Ptr to structure to fill with the allocation information
 * \return		KERR_MEMO_NOERR	OK
 * \return		KERR_MEMO_GEERR	The address is not valid
 * \return		KERR_MEMO_NOBKI	The block does not exist
 *
 */
int32_t memo_readBlocInfo(void *address, memoMallocInf_t *allocInfo) {
	const	memoMab_t	*curBlock;

	PRIVILEGE_ELEVATE;
	local_init();

	SPIN_LOCK(vMemo);
	if (address == NULL) {
		SPIN_UNLOCK(vMemo);

		PRIVILEGE_RESTORE;
		return (KERR_MEMO_GEERR);
	}

	curBlock = (const memoMab_t *)((uintptr_t)address - (uintptr_t)sizeof(memoMab_t));

	if (curBlock->oMabSignature != (uint32_t)KMAB_SIGNATURE) {
		SPIN_UNLOCK(vMemo);

		PRIVILEGE_RESTORE;
		return (KERR_MEMO_NOBKI);
	}

	allocInfo->oSize	   = curBlock->oSzAllocated;
	allocInfo->oIdentifier = curBlock->oIdentifier;
	SPIN_UNLOCK(vMemo);

	PRIVILEGE_RESTORE;
	return (KERR_MEMO_NOERR);
}

/*
 * \brief Free the memory allocation
 *
 * Call example in C:
 *
 * \code{.c}
 * uint8_t    *memory;
 *
 *    memo_free(memory);
 * \endcode
 *
 * \param[in]	*address	Ptr on the address bloc to release
 *
 */
void	memo_free(void *address) {
	memoMab_t			*preBlock, *curBlock, *nexBlock;
	uintptr_t			*stHeap;
	uint32_t			core, released;
	mallocHeapInfo_t	*heapInfo;

	core = GET_RUNNING_CORE;

// memo_free not allowed inside exceptions

	PRIVILEGE_ELEVATE;
	if ((IS_EXCEPTION) || (address == NULL)) { PRIVILEGE_RESTORE; return; }

	SPIN_LOCK(vMemo);

	local_init();

	curBlock = (memoMab_t *)((uintptr_t)address - (uintptr_t)sizeof(memoMab_t));
	stHeap	 = ALIGNED_PTR(uintptr_t, linker_stHeap);
	heapInfo = &vMemo_heapInfo;

// Verify the bloc signature

	kern_lockMutex(vMutex[core], KWAIT_INFINITY);

	if (curBlock->oMabSignature != (uint32_t)KMAB_SIGNATURE) {
		kern_unlockMutex(vMutex[core]);
		SPIN_UNLOCK(vMemo);

		PRIVILEGE_RESTORE;
		return;
	}

// Release the memory block

	curBlock->oMabSignature = 0u;
	curBlock->oIdentifier   = NULL;

	released = (curBlock->oSzAllocated + curBlock->oPadBlock + sizeof(memoMab_t));
	if (curBlock != (memoMab_t *)stHeap) {
		nexBlock			   =  curBlock->oPtrNexBlock;
		preBlock			   =  curBlock->oPtrPreBlock;
		preBlock->oSzAvailable += (uint32_t)(curBlock->oSzAllocated + curBlock->oSzAvailable + sizeof(memoMab_t));
		preBlock->oPtrNexBlock =  nexBlock;
		if (nexBlock != NULL) {
			nexBlock->oPtrPreBlock = preBlock;
		}

// Adjust the number of blocks and the available memory

		heapInfo->oNbBlocks--;
		heapInfo->oUsdMemory -= released;
	}

	kern_unlockMutex(vMutex[core]);
	SPIN_UNLOCK(vMemo);

	PRIVILEGE_RESTORE;
}

/*
 * \brief Delayed free the memory allocation
 *
 * \note	The effective memo_free is effective at the next memo_xyz call
 * \note	This call is reserved for internal OS applications
 *
 * Call example in C:
 *
 * \code{.c}
 * uint8_t    *memory;
 *
 *    memo_delayedFree(memory);
 * \endcode
 *
 * \param[in]	*address	Ptr on the address bloc to release
 *
 */
void	memo_delayedFree(void *address) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	local_init();

	INTERRUPTION_OFF;
	if (vFreeDelayed[core] == false) {
		vAddressFreeDelayed[core] = address;
		vFreeDelayed[core] = true;
	}
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static	void	local_init(void) {
			memoMab_t	*curBlock;
			uint32_t	core;
			uintptr_t	lnHeap;
			void		*address;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

		if (kern_createMutex(aStrIdSe, &vMutex[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "memo: create mutx"); exit(EXIT_OS_PANIC); }

// Initialise the first empty bloc for each memory heap

		if (core == KCORE_0) {
			lnHeap   = (uintptr_t)linker_lnHeap;
			curBlock = ALIGNED_PTR(memoMab_t, linker_stHeap);

			curBlock->oIdentifier	=  NULL;
			curBlock->oProcess		=  NULL;
			curBlock->oMabSignature	=  (uint32_t)KMAB_SIGNATURE;
			curBlock->oSzAllocated	=  0u;
			curBlock->oSzAvailable	=  (uint32_t)(lnHeap - sizeof(memoMab_t));
			curBlock->oPtrPreBlock	=  NULL;
			curBlock->oPtrNexBlock	=  NULL;
			curBlock->oPadBlock		=  0u;

			vMemo_heapInfo.oNbBlocks	 = 1u;
			vMemo_heapInfo.oNbMaxBlocks	 = 1u;
			vMemo_heapInfo.oUsdMemory	 = sizeof(memoMab_t);
			vMemo_heapInfo.oUsdMaxMemory = sizeof(memoMab_t);
		}
		INTERRUPTION_RESTORE;
	}

// Delayed memo_free

	if (vFreeDelayed[core] == true) {
		address = vAddressFreeDelayed[core];
		vAddressFreeDelayed[core] = NULL;
		vFreeDelayed[core] = false;
		INTERRUPTION_RESTORE;

		memo_free(address);
		return;
	}

	INTERRUPTION_RESTORE;
}

#endif
