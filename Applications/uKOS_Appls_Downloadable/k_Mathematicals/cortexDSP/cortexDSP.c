/*
; cortexDSP.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
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

/*!
 * \file
 * \ingroup app_mathematic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 3 processes:
 *
 *			- P0: Every 1000-ms
 *					- Toggle LED 0
 *
 *			- P1: Every 1000-ms
 *					- Compute the vertical-horizontal sums of a matrix
 *
 *			- P2: Every 1000-ms
 *					- Compute the sum of the 2 vector product
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"cortexDSP    Example of how to use the DSP.            (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  cortexDSP\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

MODULE(
	UserAppl,							// Module name (the first letter has to be upper case)
	KID_FAM_APPLICATIONS,				// Family (defined in the module.h)
	KNUM_APPLICATION,					// Module identifier (defined in the module.h)
	NULL,								// Address of the initialisation code (early pre-init)
	aStart,								// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,								// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);

// Application specific
// ====================

// Prototypes

__attribute__ ((always_inline)) static __inline void local_cumulate32(int32_t *value, int16_t a, int16_t b);
__attribute__ ((always_inline)) static __inline void local_cumulate64(int64_t *value, int32_t a, int32_t b);

/*
 * \brief aProcess 0
 *
 * - P0: Every 1000-ms
 *  		- Toggle LED 0
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(1000u);
		led_toggle(KLED_0);
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Every 1000-ms
 *			- Compute the vertical-horizontal sums of a matrix
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
					uint8_t		i, j;
	static	const	int16_t		image[10][10] = {
									{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9 },
									{  1,  2,  3,  4,  5,  6,  7,  8,  9, 10 },
									{  2,  3,  4,  5,  6,  7,  8,  9, 10, 11 },
									{  3,  4,  5,  6,  7,  8,  9, 10, 11, 12 },
									{  4,  5,  6,  7,  8,  9, 10, 11, 12, 13 },
									{  5,  6,  7,  8,  9, 10, 11, 12, 13, 14 },
									{  6,  7,  8,  9, 10, 11, 12, 13, 14, 15 },
									{  7,  8,  9, 10, 11, 12, 13, 14, 15, 16 },
									{  8,  9, 10, 11, 12, 13, 14, 15, 16, 17 },
									{ 10, 10, 11, 12, 13, 14, 15, 16, 17, 18 }
								};

	static	int32_t		projections_x[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	static	int32_t		projections_y[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(1000u);

// Compute the vector rows & cols

		for (i = 0u; i < 10u; i++) {
			for (j = 0u; j < 10u; j++) {
				local_cumulate32(&projections_x[i], image[i][j], 1);
				local_cumulate32(&projections_y[i], image[j][i], 1);
			}
		}

		(void)dprintf(KSYST, "\nRows\n\n");
		for (i = 0u; i < 10u; i++) {
			(void)dprintf(KSYST, "%"PRId32"\n", projections_x[i]);
		}

		(void)dprintf(KSYST, "\nCols\n\n");
		for (i = 0u; i < 10u; i++) {
			(void)dprintf(KSYST, "%"PRId32"\n", projections_y[i]);
		}

	}
}

/*
 * \brief aProcess 2
 *
 * - P2: Every 1000-ms
 *			- Compute the sum of the 2 vector product
 *
 */
static void __attribute__ ((noreturn)) aProcess_2(const void *argument) {
			uint8_t		i;
			int64_t		result;
	static	int32_t		vector_1[10] = { 1, -2, 3, 4,  5, 6, 7, 8, 9,  10 };
	static	int32_t		vector_2[10] = { 1,  2, 3, 4, -5, 6, 7, 8, 9, -10 };

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(1000u);

// Compute the vector product

		result = 0;
		for (i = 0u; i < 10u; i++) {
			local_cumulate64(&result, vector_1[i], vector_2[i]);
		}

		(void)dprintf(KSYST, "Result = %"PRId64"\n", result);
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
int		main(int argc, const char *argv[]) {
	proc_t	*process_0, *process_1, *process_2;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrIden_2[]) = "Process_User_2";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2025";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2025";
	STRG_LOC_CONST(aStrText_2[]) = "Process user 2.                           (c) EFr-2025";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_1,							// Code of the process
		aStrIden_1,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		2,									// Index
		specification_2,					// Specifications (just use specification_x)
		aStrText_2,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_2,							// Code of the process
		aStrIden_2,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, NULL, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, NULL, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_2, NULL, &process_2) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_cumulate32
 *
 * - Compute the sum of the elements of a vector
 *   - value.32 = value.32 + (a.16 * b.16)
 *
 */
// NOLINTBEGIN(readability-non-const-parameter)
//
__attribute__ ((always_inline)) static __inline void local_cumulate32(int32_t *value, int16_t a, int16_t b) {

	__asm volatile ("smlabb %0, %1, %2, %3" : "=r" (*value) : "r" (a), "r" (b), "r" (*value));
}

/*
 * \brief local_cumulate64
 *
 * - Compute the sum of the elements of a vector.
 *   - value.64 = value.64 + (a.32 * b.32).
 *
 */
__attribute__ ((always_inline)) static __inline void local_cumulate64(int64_t *value, int32_t a, int32_t b) {
	uint32_t	h, l;

	h = (uint32_t)(*value>>32); l = (uint32_t)(*value & 0xFFFFFFFFul);

	__asm volatile ("smlal %0, %1, %2, %3" : "=r" (l), "=r" (h) : "r" (a), "r" (b), "0" (l), "1" (h));
	*value = (int64_t)(((uint64_t)h<<32u) | l);
}

// NOLINTEND(readability-non-const-parameter)
//
