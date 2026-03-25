/*
; test_malloc.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Randomly test the memo_maloc.
;
;			Launch 10 processes:
;
;			- P0..P9
;			      Randomly test the memo_malloc
;		    	  Ask for random quantity of memory
;				  Each bloc is filled with a pattern
;				  When the heap is full, check of the coherence of the blocs & release them
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

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"test_malloc  memo_malloc tests.                        (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "memo_malloc tests\n"
									"=================\n\n"

									"Random test of the memo_malloc\n\n"

									"Input format:  test_malloc {nbSamples}\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Test_malloc,								// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_TEST_MALLOC,							// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KNB_PROC	10u							// Number of processes
#define	KSZ_STACK	KKERN_SZ_STACK_XL			// Size of the stack

typedef	struct testMallocPack		testMallocPack_t;

struct	testMallocPack {
			const char_t	*oProcessName;		// Ptr on the process name
			uint8_t			**oTabPtr;			// Ptr on the memo_malloc ptr table
			uint32_t		oNbSamples;			// Number of samples
		};

static	proc_t				*vProcess[KNB_PROC];
static	spec_t				vSpecification[KNB_PROC];
static	testMallocPack_t	vParameter[KNB_PROC];

// Prototypes

static	void	local_process(const void *argument);
static	bool	local_reserve(uint32_t number, uint32_t nbSamples);
static	bool	local_install(uint32_t number);
static	void	local_getRND(uint32_t *number);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	char_t		*dummy;
	int32_t		status = EXIT_OS_SUCCESS_CLI;
	uint32_t	i, nbSamples = 100u;
	enum		{ KERR_NOT, KERR_INA, KERR_NME } error = KERR_NOT;

	(void)dprintf(KSYST, "Random test of the memo_malloc.\n");

	vParameter[0].oProcessName = (const char_t *)"Process: 0 "; vParameter[0].oTabPtr = nullptr; vParameter[0].oNbSamples = 0u;
	vParameter[1].oProcessName = (const char_t *)"Process: 1 "; vParameter[1].oTabPtr = nullptr; vParameter[1].oNbSamples = 0u;
	vParameter[2].oProcessName = (const char_t *)"Process: 2 "; vParameter[2].oTabPtr = nullptr; vParameter[2].oNbSamples = 0u;
	vParameter[3].oProcessName = (const char_t *)"Process: 3 "; vParameter[3].oTabPtr = nullptr; vParameter[3].oNbSamples = 0u;
	vParameter[4].oProcessName = (const char_t *)"Process: 4 "; vParameter[4].oTabPtr = nullptr; vParameter[4].oNbSamples = 0u;
	vParameter[5].oProcessName = (const char_t *)"Process: 5 "; vParameter[5].oTabPtr = nullptr; vParameter[5].oNbSamples = 0u;
	vParameter[6].oProcessName = (const char_t *)"Process: 6 "; vParameter[6].oTabPtr = nullptr; vParameter[6].oNbSamples = 0u;
	vParameter[7].oProcessName = (const char_t *)"Process: 7 "; vParameter[7].oTabPtr = nullptr; vParameter[7].oNbSamples = 0u;
	vParameter[8].oProcessName = (const char_t *)"Process: 8 "; vParameter[8].oTabPtr = nullptr; vParameter[8].oNbSamples = 0u;
	vParameter[9].oProcessName = (const char_t *)"Process: 9 "; vParameter[9].oTabPtr = nullptr; vParameter[9].oNbSamples = 0u;

// Analyse the command line
// ------------------------
//
// Example:
//
// testMalloc 1000	use 1000 blocs for the tests
// testMalloc 345		use 345 blocs for the tests

	switch (argc) {
		case 2u: {
			nbSamples = (uint32_t)strtoul(argv[1], &dummy, 10u);

// Reserve the necessary buffers

			for (i = 0u; i < KNB_PROC; i++) {
				if (local_reserve(i, nbSamples) == false) {
					error = KERR_NME;
					break;
				}
			}

// Install the processes

			if (error == KERR_NOT) {
				for (i = 0u; i < KNB_PROC; i++) {
					if (local_install(i) == false) {
						error = KERR_NME;
						break;
					}
				}
			}
			break;
		}
		default: {
			error = KERR_INA;
			break;
		}
	}

	switch (error) {
		case KERR_NOT: { (void)dprintf(KSYST, "Test in progress ...\n\n");		  status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_INA: { (void)dprintf(KSYST, "Incorrect arguments.\n\n");		  status = EXIT_OS_FAILURE;     break; }
		case KERR_NME: { (void)dprintf(KSYST, "Not enough memory. Restart!\n\n"); status = EXIT_OS_FAILURE;     break; }
		default:	   {														  status = EXIT_OS_FAILURE;     break; }
	}
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_reserve
 *
 * - Reserve the memory
 *   - if not enough memory, kill the previously installed processes and get back the reserved memory
 *
 */
static	bool	local_reserve(uint32_t number, uint32_t nbSamples) {
	uint32_t	i;

	vParameter[number].oNbSamples = nbSamples;
	vParameter[number].oTabPtr    = (uint8_t **)memo_malloc(KMEMO_ALIGN_16, (nbSamples * sizeof(uint8_t *)), "test_malloc");
	if (vParameter[number].oTabPtr == nullptr) {
		if (number > 0u) {
			for (i = 0u; i < number; i++) {
				memo_free((void *)vParameter[i].oTabPtr);
			}
		}
		return (false);
	}

	return (true);
}

/*
 * \brief local_install
 *
 * - Install the process
 *
 */
static	bool	local_install(uint32_t number) {
	bool		status;
	uintptr_t	*stack;

	stack = (uintptr_t *)memo_malloc(KMEMO_ALIGN_16, (KSZ_STACK * sizeof(uintptr_t *)), "test_malloc");
	if (stack == nullptr) { return (false); }

	vSpecification[number].oIdentifier	  = nullptr;
	vSpecification[number].oText		  = nullptr;
	vSpecification[number].oCode		  = (void (*)(const void *argument))local_process;
	vSpecification[number].oStackStart	  = &stack[0];
	vSpecification[number].oStack		  = &stack[((KSZ_STACK - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK)];
	vSpecification[number].oStackSize	  = ((KSZ_STACK - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK);
	vSpecification[number].oStackMode	  = KPROC_STACK_STATIC;
	vSpecification[number].oPriority	  = KKERN_PRIORITY_MEDIUM_03;
	vSpecification[number].oSerialManager = KDEF0;
	vSpecification[number].oKind		  = KPROC_NORMAL;
	vSpecification[number].oMode		  = KPROC_USER;
	vSpecification[number].oScheduleHook  = nullptr;

	status = (kern_createProcess(&vSpecification[number], &vParameter[number], &vProcess[number]) == KERR_KERN_NOERR) ? (true) : (false);
	return (status);
}

/*
 * \brief local_process 0..9
 *
 * - Px: Randomly test the memo_malloc
 *       Ask for random quantity of memory
 *		 Each bloc is filled with a pattern
 *       When the heap is full, check of the coherence of the blocs & release them
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {
			uint32_t			nbSamples, i, j, amount;
			uint8_t				**aTabPtr, *array, *length, *counter, cpt;
	const	char_t				*processName;
	const	testMallocPack_t	*pack;

	pack = (const testMallocPack_t *)argument;

	processName = pack->oProcessName;
	aTabPtr     = pack->oTabPtr;
	nbSamples   = pack->oNbSamples;

	while (true) {

// Initialise the ptr table

		for (i = 0u; i < nbSamples; i++) {
			aTabPtr[i] = nullptr;
		}

// Try to reserve as many blocs as possible
// Consider only 5 < blocks < 256

		for (i = 0u; i < nbSamples; i++) {
			do {
				local_getRND(&amount);
				amount &= 0x000000FFu;
			} while (amount < 5u);

			aTabPtr[i] = (uint8_t *)memo_malloc(KMEMO_ALIGN_16, (amount * sizeof(uint8_t)), "test_malloc");
			if (aTabPtr[i] == nullptr) {
				break;
			}

// Fill the block with a counter
// First bytes the length, then, the counter ...
//		   counter			        (amount - 1)
// 0       1       2       3        xx
// length  00      01      02 ..... nn

			array   = aTabPtr[i];
			length  = &array[0];
			*length = (uint8_t)(amount - 1u);
			counter = &array[1];
			cpt     = 0u;

			for (j = 0u; j < *length; j++) {
				counter[j] = cpt;
				cpt++;
			}
		}

// Verify the counter
// 0       1    2   3      xx
// length  00   01  02 ... nn
//
// Release the reserved blocs

		for (i = 0u; i < nbSamples; i++) {
			if (aTabPtr[i] == nullptr) {
				break;
			}

			array   = aTabPtr[i];
			length  = &array[0];
			counter = &array[1];
			cpt     = 0u;

			for (j = 0u; j < *length; j++) {
				if (counter[j] != cpt++) {
					LOG(KFATAL_SYSTEM, "test_malloc: ioherency problem");
					exit(EXIT_OS_FAILURE);
				}

			}
			memo_free(aTabPtr[i]);
		}
		(void)dprintf(KSYST, "%s: Number of blocs = %"PRIu32"\n", processName, i);
	}
}

/*
 * \brief local_getRND
 *
 * - Return a pseudo random number
 *
 */
#define	Ka	1103515245u
#define	Kc	12345u
#define	Km	((1u<<31u) - 1u)

static	void	local_getRND(uint32_t *number) {
			uint32_t	core;
	static	bool		vInitialSeed[KNB_CORES] = MCSET(false);
	static	uint32_t	vSeed[KNB_CORES];

	core = GET_RUNNING_CORE;

// Use the LSB tickcount to make unpredictable the initial seed

	if (vInitialSeed[core] == false) {
		vInitialSeed[core] = true;

		vSeed[core] = 0x74796907u;
	}

// X[n + 1] = (Ka * X[n] + Kc) * mod(Km)
// With X[n] = vSeed

	kern_criticalSection(KENTER_CRITICAL);
	vSeed[core] = ((Ka * vSeed[core]) + Kc) % Km;
	*number = vSeed[core];
	kern_criticalSection(KEXIT_CRITICAL);
}
