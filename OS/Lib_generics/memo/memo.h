/*
; memo.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		memo manager.
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

#pragma	once

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \defgroup memo Memo
 *
 * \brief Memo
 *
 * Memo management
 *
 * @{
 */

// memo_malloc memory alignments
// -----------------------------

typedef	enum {
			KMEMO_ALIGN_4 = 0u,									// Alignment 4-bytes
			KMEMO_ALIGN_8,										// Alignment 8-bytes (default)
			KMEMO_ALIGN_16,										// Alignment 16-bytes
			KMEMO_ALIGN_32										// Alignment 32-bytes
} memoAlignement_t;

// memo_malloc & memo_malloc statistics
// ------------------------------------

typedef	struct	memoMab			memoMab_t;
typedef	struct	memoMallocInf	memoMallocInf_t;

struct	memoMallocInf {
			uint32_t	oSize;									// Block size
	const	char_t		*oIdentifier;							// Mab user identifier
};

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
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
extern	void	memo_free(void *address);

/*!
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
#if	((uKOS_COMPILER_VERSION > 110200) && (!defined(__clang__)))
extern	void	*memo_malloc(memoAlignement_t memoAlignement, uint32_t size, const char_t *identifier) __attribute__ ((malloc, malloc(memo_free, 1), alloc_size(2)));

#else
extern	void	*memo_malloc(memoAlignement_t memoAlignement, uint32_t size, const char_t *identifier);
#endif

/*!
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
#if	((uKOS_COMPILER_VERSION > 110200) && (!defined(__clang__)))
extern	void	*memo_realloc(memoAlignement_t memoAlignement, void *address, uint32_t size, const char_t *identifier) __attribute__ ((malloc, malloc(memo_free, 1), alloc_size(3)));

#else
extern	void	*memo_realloc(memoAlignement_t memoAlignement, void *address, uint32_t size, const char_t *identifier);
#endif

/*!
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
 * \return		KERR_MEMO_NOERR	On success
 * \return		KERR_MEMO_GEERR	The address is not valid
 * \return		KERR_MEMO_NOBKI	The block does not exist
 *
 */
extern	int32_t memo_readBlocInfo(const void *address, memoMallocInf_t *allocInfo);

/*!
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
extern	void	memo_delayedFree(void *address);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
