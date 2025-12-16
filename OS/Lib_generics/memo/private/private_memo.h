/*
; private_memo.
; =============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		memo manager.
;
;			Private uKernel variables.
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
 * \addtogroup memo
 * @{
 */

/*!
 * \defgroup private_memo Private Memo
 *
 * \brief Private memo variables and structures
 *
 * Internal memo structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#define	KMAB_SIGNATURE		(((uint32_t)'m'<<24u) | ((uint32_t)'a'<<16u) | ((uint32_t)'b'<<8u) | (uint32_t)'_')

#if (defined(__LP64__))
// Mandatory:
// Some CPUs (like cortex m) need to have the stack 16-byte aligned.
// CPUs with caches need 64-byte alignments

struct	memoMab {
		const	char_t		*oIdentifier;									// Mab user identifier
				proc_t		*oProcess;										// Ptr on the process who has reserved the memory bloc
				uint32_t	oMabSignature;									// Mab signature
				uint32_t	oSzAllocated;									// Block size (allocated)
				uint32_t	oSzAvailable;									// Block size (available)
				uint32_t	oPadBlock;										// Paddering for the block alignement
				memoMab_t  	*oPtrPreBlock;									// Ptr on the previous block
				memoMab_t	*oPtrNexBlock;									// Ptr on the next block
				uintptr_t	oAlign[2];										// To ensure the 64-byte alignment
};
typedef char p__LINE__[ ((sizeof(struct memoMab) % 64) == 0) ? 1 : -1];		// Just to generate a compiler error if not % 64

#else
// Mandatory:
// Some CPUs (like cortex m) need to have the stack 8-byte aligned.
// CPUs with caches need 32-byte alignments

struct	memoMab {
		const	char_t		*oIdentifier;									// Mab user identifier
				proc_t		*oProcess;										// Ptr on the process who has reserved the memory bloc
				uint32_t	oMabSignature;									// Mab signature
				uint32_t	oSzAllocated;									// Block size (allocated)
				uint32_t	oSzAvailable;									// Block size (available)
				uint32_t	oPadBlock;										// Paddering for the block alignement
				memoMab_t  	*oPtrPreBlock;									// Ptr on the previous block
				memoMab_t  	*oPtrNexBlock;									// Ptr on the next block
};
typedef char p__LINE__[ ((sizeof(struct memoMab) % 32) == 0) ? 1 : -1];		// Just to generate a compiler error if not % 32
#endif

typedef struct {
				uint32_t	oUsdMemory;										// Used memory
				uint32_t	oNbBlocks;										// Number of blocks
				uint32_t	oNbMaxBlocks;									// Max number of blocks
				uint32_t	oUsdMaxMemory;									// Max used memory
				uint32_t	oFailedAllocations;								// Number of failed allocations
} mallocHeapInfo_t;

extern	mallocHeapInfo_t	vMemo_heapInfo;

/**@}*/
/**@}*/
/**@}*/
