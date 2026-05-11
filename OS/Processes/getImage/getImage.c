/*
; getImage.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		imager process; continuous acquisition of an image.
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
#include	"MT9V03x/MT9V03x.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"getImage    get image process: image acquisition.     (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "getImage process\n"
									"=================\n\n"

									"Acquisition of an image\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// This process has to run on the following cores:

#define	KEXECUTION_CORE		(1u<<BCORE_0)

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	int32_t		imager_clean(uint32_t argc, const char_t *argv[]);

MODULE(
	GetImage,						// Module name (the first letter has to be upper case)
	KID_FAM_PROCESSES,				// Family (defined in the module.h)
	KNUM_IMAGER,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	prgm,							// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	imager_clean,					// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	KEXECUTION_CORE					// Execution cores
);

// Process specific
// ================

#define	KTIME_ACQ	100u
#define	KLED_XFER	KLED_3

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_getImage";
STRG_LOC_CONST(aStrText[]) = "Process getImage: image acquisition.     (c) EFr-2026";

// Image 328 x 248
// Fixed exposure
//
static	const	mt9v03x_t	aTab328248F[] = {
								{ 1u,	0x00D9u }, { 2u,	0x007Du }, { 3u,	0x00F8u }, { 4u,	0x0149u }, { 5u,	0x016Bu }, { 6u,	0x0032u }, { 7u,	0x0388u }, { 8u,	0x01E0u },
								{ 9u,	0x01E0u }, { 10u,	0x0164u }, { 11u,	0x0007u }, { 16u,	0x002Du }, { 21u,	0x8032u }, { 32u,	0x03D5u }, { 33u,	0x0012u }, { 34u,	0x0028u },
								{ 40u,	0x0016u }, { 41u,	0x0018u }, { 43u,	0x0003u }, { 44u,	0x0006u }, { 46u,	0x0004u }, { 47u,	0x0003u }, { 70u,	0x1606u }, { 71u,	0x8081u },
								{ 72u,	0x007Fu }, { 104u,	0xE5F9u }, { 105u,	0x65D7u }, { 106u,	0x2950u }, { 107u,	0xA040u }, { 112u,	0x0032u }, { 114u,	0x0001u }, { 115u,	0x0307u },
								{ 116u,	0x0000u }, { 128u,	0x00F4u }, { 129u,	0x0004u }, { 130u,	0x0004u }, { 131u,	0x0004u }, { 132u,	0x0004u }, { 133u,	0x0004u }, { 134u,	0x0004u },
								{ 135u,	0x0004u }, { 136u,	0x0004u }, { 137u,	0x0004u }, { 138u,	0x0004u }, { 139u,	0x0004u }, { 140u,	0x0004u }, { 141u,	0x0004u }, { 142u,	0x0004u },
								{ 143u,	0x0004u }, { 144u,	0x0004u }, { 145u,	0x0004u }, { 146u,	0x0004u }, { 147u,	0x0004u }, { 148u,	0x0004u }, { 149u,	0x0004u }, { 150u,	0x0004u },
								{ 151u,	0x0004u }, { 152u,	0x0004u }, { 154u,	0x013Fu }, { 155u,	0x02F0u }, { 156u,	0x02F0u }, { 157u,	0x02F0u }, { 160u,	0x00EFu }, { 161u,	0x01E0u },
								{ 162u,	0x01E0u }, { 163u,	0x01E0u }, { 165u,	0x0020u }, { 166u,	0x0008u }, { 168u,	0x0001u }, { 169u,	0x0008u }, { 171u,	0x0001u }, { 175u,	0x0001u },
								{ 176u,	0x2400u }, { 189u,	0x0120u }, { 194u,	0x0850u }, { 0u,	0x0000u }
							};

static	bool	vKillRequest[KNB_CORES] = MCSET(false);

// Prototypes

static	void	local_process(const void *argument);
static	void	local_transfer(void);

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
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, &vKillRequest[core], &process) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "imager: create proc"); exit(EXIT_OS_PANIC); }

	LOG(KINFO_SYSTEM, "getImage: process imager launched");
	return (EXIT_OS_SUCCESS_CLI);
}

/*
 * \brief imager_clean
 *
 * - Try to clean the ressources
 *		- Free all the ressources
 *
 */
static	int32_t	imager_clean(uint32_t argc, const char_t *argv[]) {
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
 * - Image acquisition
 *
 */
[[noreturn]]
static	void	local_process(const void *argument) {
	volatile		void			*image;
			const	bool			*killRequest;
	static	const	imagerCnf_t	configureIMG0 = {
										.oAcqMode  = KIMAGER_SNAP,
										.oPixMode  = KIMAGER_PIX_8_BITS,
										.oStRows   = 0u,
										.oStCols   = 0u,
										.oNbRows   = KIMAGER_NB_ROWS_QVGA,
										.oNbCols   = KIMAGER_NB_COLS_QVGA,
										.oKernSync = 0u,
										.oImgCnf   = aTab328248F,
										.oHSync    = nullptr,
										.oFrame    = nullptr,
										.oVSync	   = local_transfer,
										.oDMAEc    = nullptr,
									};

	RESERVE(IMG0, KMODE_READ_WRITE);

// Waiting for 20s before starting

	killRequest	= (const bool *)argument;
	kern_suspendProcess(20000u);

	if (imager_configure(&configureIMG0) != KERR_IMAGER_NOERR) {
		LOG(KFATAL_SYSTEM, "getImage: imager configure");
		exit(EXIT_OS_PANIC);
	}

// Turn on the LED and start with the acquisitions

	imager_read(&image);
	imager_ctrlLeds(0b00000001u);
	imager_acquisition();

	while (*killRequest == false) {
		kern_suspendProcess(KTIME_ACQ);
		serial_write(KCDC0, (uint8_t *)(image), KIMAGER_NB_ROWS_QVGA * KIMAGER_NB_COLS_QVGA);
		imager_acquisition();
	}

// Kill the process & the ressources

	INTERRUPTION_OFF;
	RELEASE(IMG0, KMODE_READ_WRITE);

	led_off(KLED_XFER);

	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief local_transfer
 *
 * - Indicate that an image is ready
 *
 * - !!! This is an interrupt call-back function.
 *       Not all the system calls are allowed inside this portion of code.
 *
 */
static	void	local_transfer(void) {

	led_toggle(KLED_XFER);
}
