/*
; pools.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Memory pools.
;
;			This module implements the software primitives.
;
;			Memory pool system calls
;			------------------------
;
;			void	pools_init(void);
;			int32_t	kern_createPool(const char_t *identifier, pool_t **handle);
;			int32_t	kern_setPool(pool_t *handle, const pcnf_t *configure);
;			int32_t	kern_allocateBlock(pool_t *handle, void **address, uint32_t timeout);
;			int32_t	kern_deAllocateBlock(pool_t *handle, const void *address);
;			int32_t	kern_killPool(pool_t *handle);
;			int32_t	kern_getPoolById(const char_t *identifier, pool_t **handle);
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
#include	"kern/private/private_pools.h"
#include	"kern/private/private_processes.h"
#include	"kern/private/private_identifiers.h"
#include	"kern/private/private_lists.h"

#if (KKERN_NB_POOLS > 0)
pool_t		vKern_pool[KNB_CORES][KKERN_NB_POOLS];
uint16_t	vKern_nbPool[KNB_CORES];
uint16_t	vKern_nbMaxPool[KNB_CORES];

/*
 * \brief Initialise the manager
 *
 * - This function initialises the "pools" manager
 *   Before using the manager functions, it is necessary to
 *   call this function
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	pools_init(void) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	for (i = 0u; i < KKERN_NB_POOLS; i++) {
		vKern_pool[core][i].oIdentifier  = nullptr;
		vKern_pool[core][i].oState		 = 0u;
		vKern_pool[core][i].oNbBlocks    = 0u;
		vKern_pool[core][i].oBlockSize   = 0u;
		vKern_pool[core][i].oBlockArray  = nullptr;
		vKern_pool[core][i].oUsedBlocks  = nullptr;
		vKern_pool[core][i].oReleaseSema = nullptr;
	}

	vKern_nbPool[core]	  = 0u;
	vKern_nbMaxPool[core] = 0u;
	DEBUG_KERN_TRACE("exit: OK");
}

/*
 * \brief Create a memory pool
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          pool_t     *memoryPool;
 * const    char_t     identifier[] = ”Xfer buffer”;
 *
 *    status = kern_createPool(identifier, &memoryPool);
 * \endcode
 *
 * \param[in]	*identifier		Ptr on the memory pool identifier (nullptr = anonymous)
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_POFUL	No more memory pool
 * \return		KERR_KERN_IDPOI	The memory pool identifier is already used
 *
 */
int32_t	kern_createPool(const char_t *identifier, pool_t **handle) {
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
		for (i = 0u; i < KKERN_NB_POOLS; i++) {
			if (identifiers_cmpStrings(vKern_pool[core][i].oIdentifier, identifier) == true) {
				*handle = &vKern_pool[core][i];
				DEBUG_KERN_TRACE("exit: KO 1");
				INTERRUPTION_RESTORE;
				PRIVILEGE_RESTORE;
				return (KERR_KERN_IDPOI);
			}

		}
	}

	for (i = 0u; i < KKERN_NB_POOLS; i++) {
		if (vKern_pool[core][i].oIdentifier == nullptr) {
			vKern_pool[core][i].oIdentifier  = (identifier == nullptr) ? (KPOOL_ANONYMOUS_ID) : (identifier);
			vKern_pool[core][i].oState       = (1u<<BPOOL_INSTALLED);
			*handle = &vKern_pool[core][i];

			vKern_nbPool[core]    = (uint16_t)(vKern_nbPool[core] + 1);
			vKern_nbMaxPool[core] = (vKern_nbPool[core] > vKern_nbMaxPool[core]) ? (vKern_nbPool[core]) : (vKern_nbMaxPool[core]);
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 2");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_POFUL);
}

/*
 * \brief Set a memory pool
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * pcnf_t     configure;
 * pool_t     *memoryPool;
 *
 *    configure.oNbBlocks  = 16;
 *    configure.oBlockSize = 256;
 *
 *    status = kern_setPool(memoryPool, &configure);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPOI	The memory pool does not exist
 * \return		KERR_KERN_POCNF	The memory pool configuration is not possible
 *
 */
int32_t	kern_setPool(pool_t *handle, const pcnf_t *configure) {
	uint32_t	core, i, nbBlocks, blockSize;
	uint8_t		*blockArray;
	void		**usedBlocks;
	sema_t		*semaphore;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)						        			  { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPOI); }
	if ((handle->oState & (1u<<BPOOL_INSTALLED)) == 0u)				  { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPOI); }
	if ((handle->oState & (1u<<BPOOL_CONFIGURED)) != 0u)			  { DEBUG_KERN_TRACE("exit: KO 3"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_POCNF); }
	if ((configure->oNbBlocks == 0)	|| (configure->oBlockSize == 0u)) { DEBUG_KERN_TRACE("exit: KO 4"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_POCNF); }

// Consider always multiple of 4 bytes

	nbBlocks  = configure->oNbBlocks;
	blockSize = (configure->oBlockSize + 3u) & 0xFFFFFFFCu;

// Reserve the "array" and the "used block" vector
// Initialise the vector

	blockArray = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (uint32_t)((size_t)nbBlocks * (size_t)blockSize * sizeof(uint8_t)), "pool");
	if (blockArray == nullptr) {
		DEBUG_KERN_TRACE("exit: KO 5");
		INTERRUPTION_RESTORE;
		PRIVILEGE_RESTORE;
		return (KERR_KERN_POCNF);
	}

	usedBlocks = (void **)memo_malloc(KMEMO_ALIGN_8, (nbBlocks * sizeof(uint8_t *)), "pool");
	if (usedBlocks == nullptr)	{
		memo_free(blockArray);
		DEBUG_KERN_TRACE("exit: KO 6");
		INTERRUPTION_RESTORE;
		PRIVILEGE_RESTORE;
		return (KERR_KERN_POCNF);
	}

	if (kern_createSemaphore(nullptr, 0, 0, &semaphore) != KERR_KERN_NOERR) {
		memo_free((void *)blockArray);
		memo_free((void *)usedBlocks);
		DEBUG_KERN_TRACE("exit: KO 7");
		INTERRUPTION_RESTORE;
		PRIVILEGE_RESTORE;
		return (KERR_KERN_POCNF);
	}

	handle->oNbBlocks    = nbBlocks;
	handle->oBlockSize   = blockSize;
	handle->oBlockArray  = blockArray;
	handle->oUsedBlocks  = usedBlocks;
	handle->oReleaseSema = semaphore;

	for (i = 0u; i < handle->oNbBlocks; i++) {
		handle->oUsedBlocks[i] = nullptr;
	}

	handle->oState |= (1u<<BPOOL_CONFIGURED);
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Allocate a block in a memory pool
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * pool_t     *memoryPool;
 * void       *address;
 *
 *    status = kern_allocateBlock(memoryPool, &address, 1234);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	**address		Ptr on the pool address
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPOI	The memory pool does not exist
 * \return		KERR_KERN_PONCF	The memory pool is not configured
 * \return		KERR_KERN_BKFUL	No more block
 *
 */
int32_t	kern_allocateBlock(pool_t *handle, void **address, uint32_t timeout) {
	uint32_t	core, i;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*address = nullptr;

	if (handle == nullptr)								 { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPOI); }
	if ((handle->oState & (1u<<BPOOL_INSTALLED)) == 0u)  { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPOI); }
	if ((handle->oState & (1u<<BPOOL_CONFIGURED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 3"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_PONCF); }

	for (i = 0u; i < handle->oNbBlocks; i++) {
		if (handle->oUsedBlocks[i] == nullptr) {
			handle->oUsedBlocks[i]  = (void *)((uintptr_t)handle->oBlockArray + (uintptr_t)(i * handle->oBlockSize));
			*address = handle->oUsedBlocks[i];
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 4");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;

	if (timeout > 0u) {
		if (kern_waitSemaphore(handle->oReleaseSema, timeout) == KERR_KERN_NOERR) {
			return (kern_allocateBlock(handle, address, 0u));
		}

	}
	return (KERR_KERN_BKFUL);
}

/*
 * \brief deallocate a block in a memory pool
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * pool_t     *memoryPool;
 * void       *address;
 *
 *    status = kern_deAllocateBlock(memoryPool, address);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	*address		Ptr on the pool address
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPOI	The memory pool does not exist
 * \return		KERR_KERN_PONCF	The memory pool is not configured
 * \return		KERR_KERN_NOBKI	The block does not exist
 *
 */
int32_t	kern_deAllocateBlock(pool_t *handle, const void *address) {
	uint32_t	core, i;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								 { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPOI); }
	if ((handle->oState & (1u<<BPOOL_INSTALLED)) == 0u)  { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPOI); }
	if ((handle->oState & (1u<<BPOOL_CONFIGURED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 3"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_PONCF); }

	for (i = 0u; i < handle->oNbBlocks; i++) {
		if (handle->oUsedBlocks[i] == address) {
			handle->oUsedBlocks[i]  = nullptr;
			DEBUG_KERN_TRACE("exit: OK");
			kern_signalSemaphore(handle->oReleaseSema);
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 4");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOBKI);
}

/*
 * \brief Kill the memory pool
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * pool_t     *memoryPool;
 *
 *    status = kern_killPool(memoryPool);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPOI	The memory pool does not exist
 * \return		KERR_KERN_PONCF	The memory pool is not configured
 *
 */
int32_t	kern_killPool(pool_t *handle) {
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								 { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPOI); }
	if ((handle->oState & (1u<<BPOOL_INSTALLED)) == 0u)  { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPOI); }
	if ((handle->oState & (1u<<BPOOL_CONFIGURED)) != 0u) {
		memo_free(handle->oBlockArray);
		memo_free((void *)handle->oUsedBlocks);
		kern_killSemaphore(handle->oReleaseSema);
	}
	handle->oIdentifier  = nullptr;
	handle->oState	     = 0u;
	handle->oNbBlocks    = 0u;
	handle->oBlockSize	 = 0u;
	handle->oBlockArray  = nullptr;
	handle->oUsedBlocks  = nullptr;
	handle->oReleaseSema = nullptr;

	if (vKern_nbPool[core] != 0u) { vKern_nbPool[core] = (uint16_t)(vKern_nbPool[core] - 1u); }
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Get the handle of a memory pool by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          pool_t     *memoryPool;
 * const    char_t     identifier[] = ”Xfer buffer”;
 *
 *    status = kern_getPoolById(identifier, &memoryPool);
 * \endcode
 *
 * - This function returns the handle of the memory pool
 *
 * \param[in]	*identifier		Ptr on the memory pool identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPOI	The memory pool does not exist
 *
 */
int32_t	kern_getPoolById(const char_t *identifier, pool_t **handle) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	for (i = 0u; i < KKERN_NB_POOLS; i++) {
		if (identifiers_cmpStrings(vKern_pool[core][i].oIdentifier, identifier) == true) {
			*handle = &vKern_pool[core][i];
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	*handle = nullptr;
	DEBUG_KERN_TRACE("exit: KO");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOPOI);
}
#endif
