/*
; getTemp.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		getTemp process; continuous acquisition of the temperature.
;			The result is pushed in a mailbox.
;
;			Process								Tool
;			temperature							X
;			while
;				- malloc of a buffer k
;				- send the buffer k				- receive the buffer k
;				- k++							- copy it
;												- free the buffer k
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
#include	<stdlib.h>

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"getTemp      temperature acquisition process           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "temperature process\n"
									"===================\n\n"

									"Acquisition of the temperature\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	int32_t		temperature_clean(uint32_t argc, const char_t *argv[]);
static	void		local_process(const void *argument);

// This process has to run on the following cores:

#define	KEXECUTION_CORE		(1u<<BCORE_0)

MODULE(
	GetTemp,						// Module name (the first letter has to be upper case)
	KID_FAM_PROCESSES,				// Family (defined in the module.h)
	KNUM_GET_TEMP,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	prgm,							// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	temperature_clean,				// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	KEXECUTION_CORE					// Execution cores
);

// Process specific
// ================

static	bool	vKillRequest[KNB_CORES] = MCSET(false);

#define	KTIME_ACQ			200u	// 200-ms
#define	KNB_SAMPLES			128u	// Nb. of samples

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_getTemp";
STRG_LOC_CONST(aStrText[]) = "Process get temp: temp acquisition.       (c) EFr-2026";

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;
	proc_t		*process;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	vKillRequest[core] = false;

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process,						// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, &vKillRequest[core], &process) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "temperature: create proc"); exit(EXIT_OS_PANIC); }

	LOG(KINFO_SYSTEM, "getTemp: process getTemp launched");
	return (EXIT_OS_SUCCESS_CLI);
}

/*
 * \brief temperature_clean
 *
 * - Try to clean the ressources
 *		- Free all the ressources
 *
 */
static	int32_t	temperature_clean(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	vKillRequest[core] = true;

	return (EXIT_OS_SUCCESS);
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Temperature acquisitions (5-Hz)
 *   In the simulated table a period is represented by 16 samples
 *   200-ms per sample -> 3.2-s -> 1/3.2 = 0.3125-Hz
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {
					mbox_t		*mailBox;
					int16_t		*temperature = nullptr;
					uint16_t	i;
					int32_t		value;
					uint32_t	sizeSnd;
					float64_t	raw;
					mcnf_t		configure = {
									.oNbMaxPacks	= 10u,
									.oDataEntrySize	= 0u
								};
			const	bool		*killRequest;

	#if (!defined(CONFIG_REAL_TMPERATURE_S))
					uint32_t	random;
	static	const	float64_t	aSimule[KNB_SAMPLES] = {
									20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
									23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
									20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
									23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
									20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
									23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
									20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
									23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
									20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
									23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
									20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
									23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
									20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
									23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03,
									20.23, 20.52, 21.23, 21.87, 22.21, 22.67, 23.12, 23.67,
									23.78, 23.34, 22.76, 22.09, 21.56, 21.14, 20.55, 20.03
								};

	#else
					float64_t	instTemperature;
	#endif

	killRequest	= (const bool *)argument;

// Create the mailbox "Temperature"

	if (kern_createMailbox("Temperature", &mailBox) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "temperature: create Mbox"); exit(EXIT_OS_PANIC);   }
	if (kern_setMailbox(mailBox, &configure)	    != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "temperature: set mbox\n");  exit(EXIT_OS_FAILURE); }

	while (*killRequest == false) {
		kern_suspendProcess(KTIME_ACQ);

// Request a temperature buffer
// It will be free by the tool X

		temperature = (int16_t *)memo_malloc(KMEMO_ALIGN_8, (KNB_SAMPLES * sizeof(int16_t)), "temperature");
		if (temperature == nullptr) {
			LOG(KFATAL_SYSTEM, "temperature: out of memory");
			exit(EXIT_OS_FAILURE);
		}

// Rearrange the vector & store the new value inside the mailbox
// The temperature acquisition is emulated (see table),
// then, a random noise (-1.28 .. +1.27 degree) is added
// The (random & 0xFF) -> +127/-128 numbers

		#if (defined(CONFIG_REAL_TMPERATURE_S))
		for (i = 0u; i < (KNB_SAMPLES - 1u); i++) {
			temperature[KNB_SAMPLES - 1u - i] = temperature[KNB_SAMPLES - 2u - i];
		}

		temperature_read(&instTemperature);
		temperature[0] = (int16_t)((instTemperature + 273.16) * 100.0);

		#else
		for (i = 0u; i < KNB_SAMPLES; i++) {
			random_read(KRANDOM_SOFT, &random, 1u);
			raw = (aSimule[i] + 273.16) * 100.0;
			value = (int32_t)raw + (int32_t)(random & 0xFFu);
			temperature[i] = (int16_t)value;
		}
		#endif

// As long as the mailbox is not full, send a the temperature

		sizeSnd = (KNB_SAMPLES * sizeof(uint16_t));
		if (kern_writeMailbox(mailBox, &temperature[0], sizeSnd, KWAIT_INFINITY) != KERR_KERN_NOERR) {
			(void)dprintf(KSYST, "mbox problem\n");
			LOG(KFATAL_USER, "temperature: mbox problem");
			exit(EXIT_OS_FAILURE);
		}

	}

// Kill the process & the ressources

	INTERRUPTION_OFF;
	kern_killMailbox(mailBox);
	memo_free(temperature);

	exit(EXIT_OS_SUCCESS);
}
