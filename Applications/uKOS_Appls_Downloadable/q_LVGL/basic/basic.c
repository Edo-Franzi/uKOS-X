/*
; basic.
; ======

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
 * \ingroup app_LVGL
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 2 processes:
 *
 *			- P0: Every 1-ms
 *					- Tick for LVGL
 *
 *			- P1: Draw some objects
 *					- Draw the text 1 "uKOS-X"; every 200-ms change its color
 *					- Draw the text 2 "LVGL under uKOS-X control"
 *					- Draw the text 3 "(c) 2025-2026, Edo. Franzi"
 *					- Draw the arc circle (continuously)
 *					- Draw up to 20 squares (continuously)
 *
 */

#include	"uKOS.h"
#include	"ui.h"
#include	"lvgl.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"basic        Example of how to use the LVGL.           (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  basic\n"
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

static	lv_display_t	*display;
static	bool			vLVGLReady = false;

// Prototypes

extern	void	stub_LCD_On(void);
extern	void	stub_LCD_flush_cb(lv_display_t *lv_display, const lv_area_t *area, uint8_t *pixelMapping);
extern	void	ui_draw(void);

/*
 * \brief aProcess 0
 *
 * - P0: Every 1-ms
 *			- Increment the VLGL tick
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {

	UNUSED(argument);

	while (true) {
		if (vLVGLReady == true) {
			lv_tick_inc(1u);
			lv_timer_handler();
		}
		kern_suspendProcess(1u);
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Draw the text 1 "uKOS-X"; every 200-ms change its color
 *		 Draw the text 2 "LVGL under uKOS-X control"
 *		 Draw the text 3 "(c) 2025-2026, Edo. Franzi"
 *		 Draw the arc circle (continuously)
 *		 Draw up to 20 squares (continuously)
 *		 The process remains active with the LVGL context
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
	uint32_t	LCDBufferSize;
	lv_color_t	*LCDBuffer;

	UNUSED(argument);

// Initialise the LCD and the LVGL
// Ask for a small image buffer (for partial rendering)

	stub_LCD_On();
	lv_init();

	LCDBufferSize = (uint32_t)KLCD_WIDTH * (uint32_t)KBUF_LINES * sizeof(lv_color_t);
	LCDBuffer	  = (lv_color_t *)memo_malloc(KMEMO_ALIGN_16, LCDBufferSize, "lcd_buffer");

// Create a display
// Activate it

	display = lv_display_create(KLCD_WIDTH, KLCD_HEIGHT);
	lv_display_set_default(display);

	lv_display_set_buffers(display, LCDBuffer, NULL, LCDBufferSize, LV_DISPLAY_RENDER_MODE_PARTIAL);
	lv_display_set_flush_cb(display, stub_LCD_flush_cb);

// Draw the different objects
// Activate the lvgl tick

	ui_draw();

	vLVGLReady = true;

// Remain in the lvgl process space

	while (true) { kern_suspendProcess(100u); }
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
	proc_t	*process_0, *process_1;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2025";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2025";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_XLIB,				// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_1,							// Code of the process
		aStrIden_1,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, NULL, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, NULL, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
