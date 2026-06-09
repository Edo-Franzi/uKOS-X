/*
; tracing.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
; Expected results:
;			Serial terminal output
;			uKOS-X > run
;			Execute the downloaded application.
;			Run the downloaded application...
;
;	uKOS-X >
;	The machine will crash in 20 seconds!!
;	The machine will crash in 19 seconds!!
;	The machine will crash in 18 seconds!!
;	The machine will crash in 17 seconds!!
;	The machine will crash in 16 seconds!!
;	The machine will crash in 15 seconds!!
;	The machine will crash in 14 seconds!!
;	The machine will crash in 13 seconds!!
;	The machine will crash in 12 seconds!!
;	The machine will crash in 11 seconds!!
;	The machine will crash in 10 seconds!!
;	The machine will crash in 9 seconds!!
;	The machine will crash in 8 seconds!!
;	The machine will crash in 7 seconds!!
;	The machine will crash in 6 seconds!!
;	The machine will crash in 5 seconds!!
;	The machine will crash in 4 seconds!!
;	The machine will crash in 3 seconds!!
;	The machine will crash in 2 seconds!!
;	The machine will crash in 1 seconds!!
;	The machine will crash in 0 seconds!!
;
;
;
;
;	System dead! Core DUMP!!
;	========================
;
;	Exception:    HardFault
;	Routine:      aProcess
;	Process:      Process_User_0
;
;	CFSR     = 0x00000082 DACCVIOL MMARVALID
;	HFSR     = 0x40000000
;	MMFAR    = 0x001FFFFF
;	BFAR     = 0x001FFFFF
;
;	      Time [us]  Parameter            Information
;
;	    12254051-us  0x0000000004040404    --> Main: Enter
;	    12254053-us  0x0000000005050505    --> Main: Process specifications
;	    12254076-us  0x0000000006060606    --> Main: Process launched
;	    12256043-us  0x0000000002020202    --> Process 0: trace2 example
;	    12256045-us  0x0000000000000000    --> Process 0: value
;	    13257044-us  0x0000000000000001    --> Process 0: value
;	    14258045-us  0x0000000000000002    --> Process 0: value
;	    15259046-us  0x0000000000000003    --> Process 0: value
;	    16260048-us  0x0000000000000004    --> Process 0: value
;	    17261050-us  0x0000000000000005    --> Process 0: value
;	    18262051-us  0x0000000000000006    --> Process 0: value
;	    19263053-us  0x0000000000000007    --> Process 0: value
;	    20264054-us  0x0000000000000008    --> Process 0: value
;	    21265055-us  0x0000000000000009    --> Process 0: value
;	    22266057-us  0x000000000000000A    --> Process 0: value
;	    23267058-us  0x000000000000000B    --> Process 0: value
;	    24268060-us  0x000000000000000C    --> Process 0: value
;	    25269062-us  0x000000000000000D    --> Process 0: value
;	    26270063-us  0x000000000000000E    --> Process 0: value
;	    27271064-us  0x000000000000000F    --> Process 0: value
;	    28272066-us  0x0000000000000010    --> Process 0: value
;	    29273068-us  0x0000000000000011    --> Process 0: value
;	    30274070-us  0x0000000000000012    --> Process 0: value
;	    31275071-us  0x0000000000000013    --> Process 0: value
;	    32276072-us  0x0000000001010101    --> Process 0: Out loop
;	    33276068-us  0x0000000002020202    --> Process 0: save the context
;
;	Logs core 0
;	      Time [us]  Category          Process or ISR identifier            Function                              Line   Information
;
;	          97-us  Info system       Process_First                        prgm                                   125   idle: daemon idle launched
;	         100-us  Info system       Process_First                        boot                                   120   boot: daemon idle launched
;	         119-us  Info system       Process_First                        prgm                                   126   launcher: process launcher launched
;	         121-us  Info system       Process_First                        boot                                   133   boot: Process launcher launched
;	         129-us  Info system       Process_launcher                     local_process                          157   launcher: launching all the processes
;	         198-us  Info system       Process_launcher                     local_process                          168   launcher: early initialisations
;	         217-us  Info system       Process_launcher                     prgm                                   138   getTemp: process getTemp launched
;	         238-us  Info system       Process_launcher                     prgm                                   117   startup: process start-up launched
;	         297-us  Info system       Process_launcher                     prgm                                   140   TinyUSB: process TinyUSB launched
;	         317-us  Info system       Process_launcher                     prgm                                   141   alive: process alive launched
;	         319-us  Info system       Process_launcher                     local_process                          186   launcher: all process launched
;	         330-us  Info system       Process_launcher                     prgm                                   127   stack: daemon stack launched
;	         354-us  Info system       Process_launcher                     prgm                                   129   stimer: daemon stim launched
;	         358-us  Info system       Process_launcher                     local_process                          200   launcher: all daemon launched
;	      252371-us  Info system       Process_tinyusb                      tud_mount_cb                           192   TinyUSB: mounted
;	     1388209-us  Info system       Process_tinyusb                      tud_cdc_line_state_cb                  163   model_TinyUSB_cdc: connected
;	     1389715-us  Info system       Process_tinyusb                      tud_cdc_line_state_cb                  170   model_TinyUSB_cdc: disconnected
;	     1389958-us  Info system       Process_tinyusb                      tud_cdc_line_state_cb                  163   model_TinyUSB_cdc: connected
;	     1391957-us  Info system       Process_tinyusb                      tud_cdc_line_state_cb                  170   model_TinyUSB_cdc: disconnected
;	     1392215-us  Info system       Process_tinyusb                      tud_cdc_line_state_cb                  163   model_TinyUSB_cdc: connected
;	    12254048-us  Info user         Console_urt0                         main                                   178   launched
;	    12254078-us  Info user         Console_urt0                         main                                   200   Application launched
;	    12254118-us  Info user         Process_User_0                       aProcess                               132   launched
;	    33276070-us  Fatal user        Process_User_0                       aProcess                               154   ... and now the crash!
;
;	Stack content before the fault: offset = 0x0000001A
;	stack[+31] = 0x00000000
;	stack[+30] = 0x00000000
;	stack[+29] = 0x00000000
;	stack[+28] = 0x00000000
;	stack[+27] = 0x00000000
;	stack[+26] = 0x00000000
;	stack[+25] = 0x00000000
;	stack[+24] = 0x00000000
;	stack[+23] = 0x00000000
;	stack[+22] = 0x00000000
;	stack[+21] = 0x00000000
;	stack[+20] = 0x00000000
;	stack[+19] = 0x00000000
;	stack[+18] = 0x00000000
;	stack[+17] = 0x00000000
;	stack[+16] = 0x00000000
;	stack[+15] = 0x00000000
;	stack[+14] = 0x00000000
;	stack[+13] = 0x00000000
;	stack[+12] = 0x00000000
;	stack[+11] = 0x00000000
;	stack[+10] = 0x00000000
;	stack[+09] = 0x00000000
;	stack[+08] = 0x00000000
;	stack[+07] = 0x00000000
;	stack[+06] = 0x00000000
;	stack[+05] = 0x00000000
;	stack[+04] = 0x00000000
;	stack[+03] = 0x00000000
;	stack[+02] = 0x00000000
;	stack[+01] = 0x08000A2D
;	stack[+00] = 0x03030303
;
;	CPU registers: (PC after the fault instruction)
;	psp      = 0x70005558    msp      = 0x38000FF4
;	r00      = 0x00000000    r08      = 0x08080808
;	r01      = 0x38007500    r09      = 0x09090909
;	r02      = 0x00000000    r10      = 0x10101010
;	r03      = 0x001FF000    r11      = 0x11111111
;	r04      = 0x00000014    r12      = 0x0000000A
;	r05      = 0x05050505    r13 (SP) = 0x700054E8
;	r06      = 0x06060606    r14 (LR) = 0x08048D19
;	r07      = 0x07070707    lr       = 0xFFFFFFED
;	xPSR     = 0x61010000    r15 (PC) = 0x70800190
;	BASEPRI  = 0x00000080
;
;	FPU registers
;	s00      = 0x00000000    s16      = 0x00000000
;	s01      = 0x00000000    s17      = 0x00000000
;	s02      = 0x00000000    s18      = 0x00000000
;	s03      = 0x00000000    s19      = 0x00000000
;	s04      = 0x00000000    s20      = 0x00000000
;	s05      = 0x00000000    s21      = 0x00000000
;	s06      = 0x00000000    s22      = 0x00000000
;	s07      = 0x00000000    s23      = 0x00000000
;	s08      = 0x00000000    s24      = 0x00000000
;	s09      = 0x00000000    s25      = 0x00000000
;	s10      = 0x00000000    s26      = 0x00000000
;	s11      = 0x00000000    s27      = 0x00000000
;	s12      = 0x00000000    s28      = 0x00000000
;	s13      = 0x00000000    s29      = 0x00000000
;	s14      = 0x00000000    s30      = 0x00000000
;	s15      = 0x00000000    s31      = 0xFFFFFFFF
;	FPSCR    = 0x00000000
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
 *			Launch 1 processes:
 *
 *			- P0: Use the tracing
 *				  Generate an exception (core dump)
 *				  Display the registers
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"tracing      uKernel test of the exceptions.           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  tracing\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Tracing,							// Module name (the first letter has to be upper case)
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

#define LOC_CRASH	(volatile uint32_t *)(0x001FFFFFu)

/*
 * \brief aProcess
 *
 * - P0: Use the tracing
 *		 Generate an exception (cire dump)
 *		 Display the registers
 *
 */
[[noreturn]]
static	void	aProcess(const void *argument) {
	uint32_t	time = 20u;
	uintptr_t	i;

	UNUSED(argument);

	LOG(KINFO_USER, "launched");
	(void)dprintf(KSYST,"The machine will crash in %"PRIu32" seconds!!\n", time--);

	record_trace("--> Process 0: trace2 example", 0x02020202u);

	for (i = 0u; i < 20u; i++) {
		record_trace("--> Process 0: value", i);

		kern_suspendProcess(1000u);
		(void)dprintf(KSYST,"The machine will crash in %"PRIu32" seconds!!\n", time--);
	}

	record_trace("--> Process 0: Out loop", 0x01010101u);

	kern_suspendProcess(1000u);

// Load the registers

	record_trace("--> Process 0: save the context", 0x02020202u);

// Crash the system

	LOG(KFATAL_USER, "... and now the crash!");
	*(LOC_CRASH);
	while (true) { ; }
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
	proc_t	*process;

// -------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden[]) = "Process_User_0";
	STRG_LOC_CONST(aStrText[]) = "Process user 0.                           (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

	LOG(KINFO_USER, "launched");
	record_trace("--> Main: Enter", 0x04040404);

// Specifications for the processes

	record_trace("--> Main: Process specifications", 0x05050505u);

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess,							// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	record_trace("--> Main: Process launched", 0x06060606u);

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
