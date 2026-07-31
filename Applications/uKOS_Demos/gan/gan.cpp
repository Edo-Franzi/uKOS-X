/*
; gan.
; ====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application classify the space objects and display them
;			on the LCD.
;
;			Launch 4 processes in C++:
;
;			- P0: Configure the the TensorFlow
;				  Every 1000-ms
;					- Complex CNN 4 layer NN
;
;			- P1: Every 1-ms
;					- Tick for LVGL
;
;			- P2: Widget management
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
 * \ingroup app_LVGL
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 3 processes:
 *
 *			- P0: Configure the TensorFlow
 *				  Every 1000-ms
 *					- Complex CNN 4 layer NN
 *
 *			- P1: Every 1-ms
 *					- Tick for LVGL
 *
 *			- P2: Widget management
 *
 */

#include	"uKOS.h"
#include	"ulvgl.h"
#include	<stdlib.h>
#include	<math.h>
#include	<cinttypes>
#include	"ui.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"gan          Complex CNN 4 layer for test.             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  gan\n"
									"Output format: [result]\n\n";

#if (defined(ROMABLE_S))

// Prototypes

namespace {
int32_t		prgm(uint32_t argc, const char_t *argv[]);
}

MODULE(
	Gan,								// Module name (the first letter has to be upper case)
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

// Prototypes

namespace tfl {
extern	void	tfl_init(void);
extern	void	tfl_classify(float32_t *entry, uint8_t *face);
}

extern "C" {
extern	void	lvgl_init(void);
extern	void	ui_drawFace(const uint8_t *face);
extern	void	ui_drawRandom(const char_t *s);
}

namespace {
		float32_t	local_randomUniform(void);
		float32_t	local_randomGaussian(void);
}

namespace {
static	uint8_t		vFace[KFACE_SRC_W * KFACE_SRC_H];
}

/*
 * \brief aProcess_0
 *
 * - P0:  Configure the TensorFlow
 *		  Every 1000-ms
 *			- Complex CNN 4 layer NN
 *			- Display the result
 *
 */
namespace {

[[noreturn]]
void	aProcess_0(const void *argument) {
	uint32_t		i;
	float32_t		entry[64];
	char_t			text[40];

	UNUSED(argument);

	PRIVILEGE_ELEVATE;
	tfl::tfl_init();

	while (true) {
		kern_suspendProcess(1000u);
		led_toggle(KLED_1);

// Use only 10 dimensions to avoid to generate
// like "monster" faces

		for (i = 0u; i < 64u; i++) {
			entry[i] = (i < 10) ? (local_randomGaussian()) : (0.0f);
		}

		tfl::tfl_classify(&entry[0], &vFace[0]);

		(void)snprintf(text, sizeof(text), "%.3f", entry[0]);

		ui_drawRandom(text);
		ui_drawFace(&vFace[0]);
	}
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
CPP_INTERNAL_SCOPE_BEGIN
MAIN_ENTRY(argc, argv[]) {
	proc_t	*process_0;

// ------------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) =    "Process_gan";
	STRG_LOC_CONST(aStrText_0[]) =    "Process gan.                              (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

	lvgl_init();

// Initialise the C++ constructors

	CPP_INIT_ARRAYS;

// Specifications for the processes

// NOLINTBEGIN(misc-const-correctness)
//
	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use vSpecification_x)
		aStrText_0,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_XLIB,				// KSZSTACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_02				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

// NOLINTEND(misc-const-correctness)
//
	if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "debris: Create proc"); exit(EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
CPP_INTERNAL_SCOPE_END

// Local routines
// ==============

/*
 * \brief local_randomUniform
 *
 * - Return a float32_t random
 *
 */
namespace {
float32_t	local_randomUniform(void) {
	uint32_t	random;

	random_read(KRANDOM_SOFT, &random, 1u);

	return ((float32_t)((random<<1u) & 0xFFFFu) / 65535.0f);
}
}

/*
 * \brief local_randomGaussian
 *
 * - Return a float32_t gaussian random
 *
 */
namespace {
float32_t	local_randomGaussian(void) {
	uint32_t	i;
	float32_t	z = 0.0f;

	for (i = 0u; i < 10u; i++) {
		z += local_randomUniform();
	}

	return (z - 6.0f);
}
}
