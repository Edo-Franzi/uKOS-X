/*
; test_img.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Some img tests.
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
#include	"../../Lib_peripherals/lcd0/lcd0.h"
#include	"../../Lib_peripherals/imgk/imgk.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"test_img     Some img tests.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Test of the lcd\n"
									"===============\n\n"

									"This tool performs some lcd tests.\n\n"

									"Input format:  test_lcd\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Test_img,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	(((uint32_t)'_'<<8u)+(uint32_t)'I'),		// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_IMGK";
STRG_LOC_CONST(aStrText[]) = "Process IMGK.                             (c) EFr-2026";

// Prototypes

static	void	local_process(const void *argument);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	proc_t	*process;

	UNUSED(argc);
	UNUSED(argv);

	(void)dprintf(KSYST, "IMG tests.\n");

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process,						// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_NORMAL_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "test_img: create proc"); exit(EXIT_OS_FAILURE); }
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Display the images
 *
 */
[[noreturn]]
static	void	local_process(const void *argument) {
	uint16_t	*image;
	cnfImgk_t	configure;
	sema_t		*semaphore;

	UNUSED(argument);

// Window position

	#define	KW2_X0			0u
	#define	KW2_Y0			0u
	#define	KW2_DX			320u
	#define	KW2_DY			240u
	#define	KBACKGROUNG		KBLACK

	lcd0_clear(KBACKGROUNG);
	lcd0_setDirection(KDIR_YX_RLDU);

// Image settings

	configure.oPixMode		= KPIX_8_BITS;
	configure.oStRows		= 0u;
	configure.oImagerNbRows	= KIMAGER_NB_ROWS_QVGA;
	configure.oStCols		= 0u;
	configure.oImagerNbCols	= KIMAGER_NB_COLS_QVGA;

	imgk_configure(&configure);
	if (kern_getSemaphoreById(KIMGK_SEMAPHORE_IM, &semaphore) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "test_img: get semaphore"); exit(EXIT_OS_FAILURE); }

	while (true) {
		imgk_acquisition();
		kern_suspendProcess(10u);

		kern_waitSemaphore(semaphore, KWAIT_INFINITY);

// Save the GCC diagnostic
//
		#pragma GCC diagnostic push

// Ignore the GCC diagnostic
//
		#pragma GCC diagnostic ignored "-Wcast-qual"
		imgk_getImage((volatile void **)&image);

// Restore the GCC diagnostic
//
		#pragma GCC diagnostic pop

		lcd0_drawPicture(KW2_X0, KW2_Y0, KW2_DX, KW2_DY, image);
	}
}
