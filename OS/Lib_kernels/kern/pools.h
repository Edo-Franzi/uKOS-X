/*
; pools.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

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

#pragma	once

#if (KKERN_NB_POOLS > 0)

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup pools Pools
 *
 * \brief Pools
 *
 * Pool management
 *
 * @{
 */

// Structure of the memory pool configuration
// ------------------------------------------

typedef	struct	pcnf		pcnf_t;

struct	pcnf {
				uint32_t	oNbBlocks;							// Number of blocks
				uint32_t	oBlockSize;							// Block size
};

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	void	pools_init(void);

/*!
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
extern	int32_t	kern_createPool(const char_t *identifier, pool_t **handle);

/*!
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
extern	int32_t	kern_setPool(pool_t *handle, const pcnf_t *configure);

/*!
 * \brief Allocate a block in a memory pool
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * pool_t     *memoryPool;
 * void       *address;
 *
 *    status = kern_allocateBlock(memoryPool, &address, 1234u);
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
extern	int32_t	kern_allocateBlock(pool_t *handle, void **address, uint32_t timeout);

/*!
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
extern	int32_t	kern_deAllocateBlock(pool_t *handle, const void *address);

/*!
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
extern	int32_t	kern_killPool(pool_t *handle);

/*!
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
extern	int32_t	kern_getPoolById(const char_t *identifier, pool_t **handle);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/

#endif
