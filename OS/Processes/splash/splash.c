/*
; splash.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-10-08
; Modifs:
;
; Project:	uKOS-X
; Goal:		Splash process; draw the boot banner on the LCD display,
;			then terminate.
;
;   (c) 2026, Laurent von Allmen
;   ----------------------------
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
#include	"splash.h"
#include	"ulvgl.h"
#include	"splash_ui.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "splash       Splash process: banner on the display.    (c) LvA-2026";
STRG_LOC_CONST(aStrHelp[])		  = "splash process\n"
									"==============\n\n"

									"Draw the boot banner on the LCD display.\n"
									"The system is then ready for a terminal.\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) LvA-2026\n\n";

// This process has to run on the following cores:

#define KEXECUTION_CORE		(1u<<BCORE_0)

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Splash,								// Module name (the first letter has to be upper case)
	KID_FAM_PROCESSES,					// Family (defined in the module.h)
	KNUM_SPLASH,						// Module identifier (defined in the module.h)
	nullptr,							// Address of the initialisation code (early pre-init)
	prgm,								// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,							// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	(1u<<BSHOW),						// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	KEXECUTION_CORE						// Execution cores
);

// Process specific
// ================

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_splash";
STRG_LOC_CONST(aStrText[]) = "Process splash: banner on the display.    (c) LvA-2026";

// Prototypes

static	void	local_process(const void *argument);

/*
 * \brief Main entry point
 *
 */
static	int32_t prgm([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]) {
	proc_t	*process;

	PROCESS_STACKMALLOC(
		0,								// Index
		specification,					// Specifications (just use specification_x)
		aStrText,						// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_XL,				// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process,					// Code of the process
		aStrIden,						// Identifier (nullptr if anonymous)
		KSYST,							// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

// The banner is only a comfort: without it, the system still has to start

	if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KERROR_SYSTEM, "splash: create proc"); return (EXIT_OS_SUCCESS_CLI); }

	LOG(KINFO_SYSTEM, "splash: process splash launched");
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Turn on the display
 * - Draw the banner once, in the frame buffer of the display
 * - Give back LVGL and the memory: the display keeps showing its frame
 *	 buffer, and an application is then free to initialise LVGL for its
 *	 own usage
 *
 */
[[noreturn]]
static void local_process([[maybe_unused]] const void *argument) {
	uint32_t		LCDBufferSize;
	uint8_t			*LCDBuffer;
	lv_display_t	*display;

	PRIVILEGE_ELEVATE;
	stub_splash_on(KBACKGROUND);
	PRIVILEGE_RESTORE;

	LCDBufferSize = KLCD_WIDTH * KLCD_BUF_LINES * KLCD_NB_BYTES_PIXEL;
	LCDBuffer	  = (uint8_t *)memo_malloc(KMEMO_ALIGN_16, LCDBufferSize, "splash");
	if (LCDBuffer == nullptr) {
		LOG(KERROR_SYSTEM, "splash: no memory");
		exit(EXIT_OS_SUCCESS);
	}

	lv_init();

	display = lv_display_create((int32_t)KLCD_WIDTH, (int32_t)KLCD_HEIGHT);
	lv_display_set_default(display);
	lv_display_set_buffers(display, LCDBuffer, nullptr, LCDBufferSize, LV_DISPLAY_RENDER_MODE_PARTIAL);
	lv_display_set_flush_cb(display, stub_splash_flush_cb);

	splash_ui_draw();
	lv_refr_now(display);

	lv_deinit();
	memo_free(LCDBuffer);

	LOG(KINFO_SYSTEM, "splash: banner displayed");
	exit(EXIT_OS_SUCCESS);
}
