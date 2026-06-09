/*
; suicide.
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
;	uKOS-X module list.
;	uKOS-X >
;	FLASH   0  S0O_  v 1.0   boot         Bootstrap of uKOS-X.                      (c) EFr-2026
;	FLASH   1  S02_  v 1.0   crt0         Runtime crt0.                             (c) EFr-2026
;	FLASH   2  S01_  v 1.0   cmns         Minimal I/O (not under uKOS-X).           (c) EFr-2026
;	FLASH   3  S03_  v 1.0   exce         Exception management.                     (c) EFr-2026
;	FLASH   4  S04_  v 1.0   init         First hardware initialisations.           (c) EFr-2026
;
;	FLASH  28  D00_  v 1.0   idle         Idle: run when the others are off.        (c) EFr-2026
;	FLASH  29  D03_  v 1.0   stack        stack: verify the stack integrity.        (c) EFr-2026
;	FLASH  30  D02_  v 1.0   stimer       stimer: software timer management.        (c) EFr-2026
;
;	FLASH  31  T00_  v 1.0   alive        Alive process: everything is OK.          (c) EFr-2026
;	FLASH  32  T03_  v 1.0   getTemp      temperature acquisition process           (c) EFr-2026
;	FLASH  33  T04_  v 1.0   launcher     Launcher: launch the daemons & processes. (c) EFr-2026
;	FLASH  34  T07_  v 1.0   startUp      StartUp process of the system.            (c) EFr-2026
;	FLASH  35  T08_  v 1.0   TinyUSB      TinyUSB process: management of the USB.   (c) EFr-2026
;
;	FLASH  37  X01_  v 1.0   bench        CPU core performance benches.             (c) EFr-2026
;	FLASH  38  X02_  v 1.0   console      Console prompt.                           (c) EFr-2026
;	FLASH  39  X03_  v 1.0   cycle        Cycle function.                           (c) EFr-2026
;	FLASH  40  X08_  v 1.0   date         Set / display date and time.              (c) EFr-2026
;	FLASH  41  X04_  v 1.0   dump         Dump a memory area.                       (c) EFr-2026
;	FLASH  42  X05_  v 1.0   dumplog      Dump the log buffer.                      (c) EFr-2026
;	FLASH  43  X07_  v 1.0   dumptrace    Dump the trace buffer.                    (c) EFr-2026
;	FLASH  44  X09_  v 1.0   echo         echo function.                            (c) EFr-2026
;	FLASH  45  X11_  v 1.0   fill         Fill a memory area with a pattern.        (c) EFr-2026
;	FLASH  46  X14_  v 1.0   hexloader    Intel hex+ (32-bit) loader.               (c) EFr-2026
;	FLASH  47  X15_  v 1.0   kill         Kill a module.                            (c) EFr-2026
;	FLASH  48  X16_  v 1.0   list         List the system modules.                  (c) EFr-2026
;	FLASH  49  X18_  v 1.0   man          Show the help of the module.              (c) EFr-2026
;	FLASH  50  X17_  v 1.0   memory       Give the memory section information.      (c) EFr-2026
;	FLASH  51  X42_  v 1.0   microPython  MicroPython for uKOS-X.                   (c) EFr-2026
;	FLASH  52  X32_  v 1.0   mutex        Show all created mutexes.                 (c) EFr-2026
;	FLASH  53  X21_  v 1.0   object       Display the structure of an object.       (c) EFr-2026
;	FLASH  54  X23_  v 1.0   process      List the installed processes.             (c) EFr-2026
;	FLASH  55  X30_  v 1.0   restart      Make a restart.                           (c) EFr-2026
;	FLASH  56  X24_  v 1.0   rnd          Give a random number.                     (c) EFr-2026
;	FLASH  57  X29_  v 1.0   run          Run a downloaded code.                    (c) EFr-2026
;	FLASH  58  X32_  v 1.0   semaphore    Show all created semaphores.              (c) EFr-2026
;	FLASH  59  X31_  v 1.0   sloader      Motorola S1-9, S2-8, S3-7 loader.         (c) EFr-2026
;	FLASH  60  X33_  v 1.0   szkern       Give the uKernel memory footprint.        (c) EFr-2026
;	FLASH  61  X35_  v 1.0   test_malloc  memo_malloc tests.                        (c) EFr-2026
;	FLASH  62  X37_  v 1.0   test_ram     Minimal test of the RAM (hardware).       (c) EFr-2026
;	FLASH  63  X38_  v 1.0   test_sdcard  sdcard R/W tests.                         (c) EFr-2026
;	FLASH  64  X40_  v 1.0   uKOS         The uKOS-X information.                   (c) EFr-2026
;	FLASH  65  X44_  v 1.0   wki2c        Communicate with the i2c x device.        (c) EFr-2026
;	FLASH  66  X43_  v 1.0   wkserial     Work with a communication device.         (c) EFr-2026
;	FLASH  67  X46_  v 1.0   X            Control the temperature.                  (c) EFr-2026
;
;	FLASH   5  K00_  v 1.1   kern         kern manager.                             (c) EFr-2026
;
;	FLASH   6  Q00_  v 1.0   random       random manager.                           (c) EFr-2026
;
;	FLASH  27  N00_  v 1.0   mlpn         mlpn manager.                             (c) EFr-2026
;
;	FLASH   7  L01_  v 1.0   calendar     calendar manager.                         (c) EFr-2026
;	FLASH   8  L02_  v 1.0   machine      machine manager.                          (c) EFr-2026
;	FLASH   9  L03_  v 1.0   memo         memo manager.                             (c) EFr-2026
;	FLASH  10  L05_  v 1.0   record       record manager.                           (c) EFr-2026
;	FLASH  11  L06_  v 1.0   system       system manager.                           (c) EFr-2026
;	FLASH  25  L04_  v 1.0   newlib       newlib manager.                           (c) EFr-2026
;	FLASH  26  L07_  v 1.0   text         text manager.                             (c) EFr-2026
;
;	FLASH  23  M00_  v 1.0   sdcard       sdcard manager.                           (c) EFr-2026
;	FLASH  24  M02_  v 1.0   storage      storage manager.                          (c) EFr-2026
;
;	FLASH  12  P02_  v 1.0   i2c          i2c manager.                              (c) EFr-2026
;	FLASH  13  P03_  v 1.0   i2c0         i2c0 manager.                             (c) EFr-2026
;	FLASH  14  P09_  v 1.0   led          led manager.                              (c) EFr-2026
;	FLASH  15  P10_  v 1.0   spi          spi manager.                              (c) EFr-2026
;	FLASH  16  P11_  v 1.0   spi0         spi0 manager.                             (c) EFr-2026
;	FLASH  17  P15_  v 1.0   switch       switch manager.                           (c) EFr-2026
;	FLASH  18  P17_  v 1.0   watchdog     watchdog manager.                         (c) EFr-2026
;
;	FLASH  19  C00_  v 1.0   cdc0         cdc0 manager.                             (c) EFr-2026
;	FLASH  20  C01_  v 1.0   cdc1         cdc1 manager.                             (c) EFr-2026
;	FLASH  21  C02_  v 1.0   serial       serial manager.                           (c) EFr-2026
;	FLASH  22  C03_  v 1.0   urt0         urt0 manager.                             (c) EFr-2026
;
;	FLASH  68  Z03_  v 1.0   TinyUSB      Third party TinyUSB library.              (c) EFr-2026
;	FLASH  69  Z01_  v 1.0   MicroPython  Third party MicroPython library.          (c) EFr-2026
;	FLASH  70  Z00_  v 1.0   FatFs        Third party FatFs library.                (c) EFr-2026
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
 * \ingroup app_basic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 2 processes:
 *
 *			- P0: Every 1000-ms
 *					- Toggle LED 1
 *
 *			- P1: Look for the tool "list"
 *				  Execute it
 *				  P1 will commit a suicide
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"suicide      Example of how to commit a suicide.       (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  suicide\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Suicide,							// Module name (the first letter has to be upper case)
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

/*
 * \brief aProcess 0
 *
 * - P0: Every 1000-ms
 *			- Toggle LED 1
 *
 */
[[noreturn]]
static	void	aProcess_0(const void *argument) {

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(1000u);
		led_toggle(KLED_1);
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Look for the tool "list"
 *		 Execute it
 *		 P1 will commit a suicide
 *
 */
#define	KIDMODULE	((KID_FAM_CLI<<24u) | (KNUM_LIST<<8u) | '_')

[[noreturn]]
static	void	aProcess_1(const void *argument) {
			uint16_t		index;
	const	uKOS_module_t	*module;

	UNUSED(argument);

// looking for the cmdLine module ...

	if (system_getModuleId(KIDMODULE, &index, &module) == KERR_SYSTEM_NOERR) {
		module->oExecution(0u, nullptr);
	}
	exit(EXIT_OS_SUCCESS);
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
	proc_t	*process_0, *process_1;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
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
