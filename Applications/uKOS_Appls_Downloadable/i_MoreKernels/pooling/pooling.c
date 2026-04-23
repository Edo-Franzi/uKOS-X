/*
; pooling.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
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

/*!
 * \file
 * \ingroup app_moreKernel
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 2 processes:
 *
 *			- main: Create a memory pool "Memory pool"
 *					Set the memory pool block 0, 100-Bytes
 *					Set the memory pool block 1, 100-Bytes
 *					Set the memory pool block 2, 100-Bytes
 *
 *			- P0: Use the tracing
 *				  Generate an exception (cire dump)
 *				  Display the registers
 *
 */

#include	"uKOS.h"
#include	"kern/private/private_pools.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"pooling      uKernel test of the memory pool.          (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  pooling\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Pooling,							// Module name (the first letter has to be upper case)
	KID_FAM_CLI,						// Family (defined in the module.h)
	KNUM_ROMABLE_0,						// Module identifier (defined in the module.h)
	nullptr,							// Address of the initialisation code (early pre-init)
	prgm,								// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,							// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);

#else
MODULE(
	UserAppl,							// Module name (the first letter has to be upper case)
	KID_FAM_APPLICATIONS,				// Family (defined in the module.h)
	KNUM_APPLICATION,					// Module identifier (defined in the module.h)
	nullptr,							// Address of the initialisation code (early pre-init)
	aStart,								// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,							// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);
#endif

// Application specific
// ====================

static	pcnf_t	vConfigure;
static	pool_t	*vMemoryPool;

/*
 * \brief aProcess_0
 *
 * - P0: Get the memory pool "Memory pool" handle
 *		 Recover the 3 memory pool arrays
 *		 Every 1000-ms
 *			- Fill the allocated blocks with counters
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
	uint16_t	*array_0, *array_1, *array_2;
	uint32_t	i, nbElements;
	int32_t		status;
	pool_t		*memoryPool;

	UNUSED(argument);

	status = kern_getPoolById("Memory pool", &memoryPool);
	if (status != KERR_KERN_NOERR) { (void)dprintf(KSYST, "No pool\n"); LOG(KFATAL_USER, "No pool"); exit(EXIT_OS_FAILURE); }

// Recover the memory arrays

	PRIVILEGE_ELEVATE;
	array_0 = (uint16_t *)memoryPool->oUsedBlocks[0];
	if (array_0 == nullptr) {
		LOG(KFATAL_USER, "No Used bloc 0");
		exit(EXIT_OS_FAILURE);
	}

	array_1 = (uint16_t *)memoryPool->oUsedBlocks[1];
	if (array_1 == nullptr) {
		LOG(KFATAL_USER, "No Used bloc 1");
		exit(EXIT_OS_FAILURE);
	}

	array_2 = (uint16_t *)memoryPool->oUsedBlocks[2];
	if (array_2 == nullptr) {
		LOG(KFATAL_USER, "No Used bloc 2");
		exit(EXIT_OS_FAILURE);
	}

	nbElements = memoryPool->oBlockSize / sizeof(uint16_t);
	PRIVILEGE_RESTORE;

	while (true) {
		kern_suspendProcess(1000u);

// Fill the 3  pools

		for (i = 0u; i < nbElements; i++) { array_0[i] = (uint16_t)i + 0u; }
		for (i = 0u; i < nbElements; i++) { array_1[i] = (uint16_t)i + 1u; }
		for (i = 0u; i < nbElements; i++) { array_2[i] = (uint16_t)i + 2u; }
		led_toggle(KLED_1);
	}
}

/*
 * \brief aProcess_1
 *
 * - P1: Get the memory pool "Memory pool" handle
 *		 Recover the 3 memory pool arrays
 *		 Every 200-ms
 *			- Test the allocated blocks with counters
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
	uint16_t	*array_0, *array_1, *array_2;
	uint32_t	i, nbElements;
	int32_t		status;
	pool_t		*memoryPool;

	UNUSED(argument);

// Waiting until P0 has filled at least once the 3 arrays
// Get the pool information

	kern_suspendProcess(2000u);

	status = kern_getPoolById("Memory pool", &memoryPool);
	if (status != KERR_KERN_NOERR) { (void)dprintf(KSYST, "No pool\n"); LOG(KFATAL_USER, "No pool"); exit(EXIT_OS_FAILURE); }

// Recover the memory arrays

	PRIVILEGE_ELEVATE;
	array_0 = (uint16_t *)memoryPool->oUsedBlocks[0];
	if (array_0 == nullptr) {
		LOG(KFATAL_USER, "No Used bloc 0");
		exit(EXIT_OS_FAILURE);
	}

	array_1 = (uint16_t *)memoryPool->oUsedBlocks[1];
	if (array_1 == nullptr) {
		LOG(KFATAL_USER, "No Used bloc 1");
		exit(EXIT_OS_FAILURE);
	}

	array_2 = (uint16_t *)memoryPool->oUsedBlocks[2];
	if (array_2 == nullptr) {
		LOG(KFATAL_USER, "No Used bloc 2");
		exit(EXIT_OS_FAILURE);
	}

	nbElements = memoryPool->oBlockSize / sizeof(uint16_t);
	PRIVILEGE_RESTORE;

	while (true) {
		kern_suspendProcess(200u);

// Test the 3 pools

		for (i = 0u; i < nbElements; i++) {
			if (array_0[i] != (i + 0u)) {
				LOG(KFATAL_USER, "Coherency problem!!");
				exit(EXIT_OS_FAILURE);
			}

		}
		for (i = 0u; i < nbElements; i++) {
			if (array_1[i] != (i + 1u)) {
				LOG(KFATAL_USER, "Coherency problem!!");
				exit(EXIT_OS_FAILURE);
			}

		}
		for (i = 0u; i < nbElements; i++) {
			if (array_2[i] != (i + 2u)) {
				LOG(KFATAL_USER, "Coherency problem!!");
				exit(EXIT_OS_FAILURE);
			}

			(void)dprintf(KSYST, "Passed ...\n");
		}
		led_toggle(KLED_1);
	}
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
MAIN_ENTRY(argc, argv[]) {
	int32_t		status;
	void		*memory;
	proc_t		*process_0, *process_1;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

	vConfigure.oNbBlocks  = 3u;
	vConfigure.oBlockSize = 1000u * sizeof(uint16_t);

	status = kern_createPool("Memory pool", &vMemoryPool);
	if (status != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create pool");	 exit(EXIT_OS_FAILURE); }

	status = kern_setPool(vMemoryPool, &vConfigure);
	if (status != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Configure pool"); exit(EXIT_OS_FAILURE); }

	status = kern_allocateBlock(vMemoryPool, &memory, 100u);
	if (status != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Allocate bloc");	 exit(EXIT_OS_FAILURE); }

	status = kern_allocateBlock(vMemoryPool, &memory, 100u);
	if (status != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Allocate bloc");  exit(EXIT_OS_FAILURE); }

	status = kern_allocateBlock(vMemoryPool, &memory, 100u);
	if (status != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Allocate bloc");	 exit(EXIT_OS_FAILURE); }

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_1,							// Code of the process
		aStrIden_1,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, nullptr, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
