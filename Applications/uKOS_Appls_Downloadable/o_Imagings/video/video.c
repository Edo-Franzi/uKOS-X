/*
; video.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

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
 * \ingroup app_imaging
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 1 processes:
 *
 *			- P0: Repeat every xyz ms
 *					- Prepare an image
 *					- Send it over usb
 *
 *			1. Download the program video.s3
 *			2. Run the Mac Photo Booth
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"video        Example of how to send an image over usb. (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  video\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Video,								// Module name (the first letter has to be upper case)
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

		void	TinyUSB_video_init(void);
		void	TinyUSB_video_getImageSize(uint32_t *w, uint32_t *h);
		void	TinyUSB_video_sendImage(uint8_t *image, uint32_t w, uint32_t h);
static	void	local_prepareImage(uint8_t *image, uint32_t w, uint32_t h, uint32_t startPosition);

/*
 * \brief aProcess
 *
 * - Px: Repeat every xyz ms
 *			- Prepare an image
 *			- Send it over usb
 *
 */
[[noreturn]]
static	void	aProcess(const void *argument) {
			uint32_t	w, h, frame = 0;
			uint8_t		*image_0, *image_1;
			float64_t	frameRate = 0.0;
	static	uint64_t	vTime[2];

	UNUSED(argument);

	PRIVILEGE_ELEVATE;

	TinyUSB_video_init();

	TinyUSB_video_getImageSize(&w, &h);
	image_0 = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (w * h * 2u), "video");
	image_1 = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (w * h * 2u), "video");
	if ((image_0 == nullptr) || (image_1 == nullptr)) {
		LOG(KFATAL_USER, "Out of memory");
		exit(EXIT_OS_FAILURE);
	}

	while (true) {
		vTime[0] = vTime[1];
		kern_readTickCount(&vTime[1]);

		frameRate = (1000000.0 / (float64_t)(vTime[1] - vTime[0])) * 2.0;

// Send it over usb
// Prepare the next image

		local_prepareImage(image_0, w, h, frame);
		TinyUSB_video_sendImage(image_0, w, h);
		frame++;

		local_prepareImage(image_1, w, h, frame);
		TinyUSB_video_sendImage(image_1, w, h);
		frame++;

		(void)dprintf(KSYST, "Image size: %"PRIu32" x %"PRIu32", Frame rate = %5.2f-fps\n", w, h, frameRate);
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
	proc_t	*process;

// -------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden[]) = "Process_User";
	STRG_LOC_CONST(aStrText[]) = "Process user.                             (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess,							// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_05				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_prepareImage
 *
 * - Prepare an image (vertical bars)
 *
 */
static	void	local_prepareImage(uint8_t *image, uint32_t w, uint32_t h, uint32_t startPosition) {
			uint8_t		*p, *end;
			uint32_t	i, j, idx;

// EBU color bars: https://stackoverflow.com/questions/6939422

	static	const	uint8_t		colorBars[8][4] = {

//			 Y,	   U,	 Y,	   V
		{ 235u, 128u, 235u, 128u },		// 100% White
		{ 219u,  16u, 219u, 138u },		// Yellow
		{ 188u, 154u, 188u,  16u },		// Cyan
		{ 173u,  42u, 173u,  26u },		// Green
		{  78u, 214u,  78u, 230u },		// Magenta
		{  63u, 102u,  63u, 240u },		// Red
		{  32u, 240u,  32u, 118u },		// Blue
		{  16u, 128u,  16u, 128u },		// Black
	};

// Generate the 1st line

	end = &image[w * 2u];
	idx = ((w / 2u) - 1u) - (startPosition % (w / 2u));
	p = &image[idx * 4u];

	for (i = 0u; i < 8u; i++) {
		for (j = 0u; j < (w / (2u * 8u)); j++) {

			memcpy(p, &colorBars[i], 4u);
			p += 4u;
			if (end <= p) {
				p = image;
			}
		}
	}

// Duplicate the 1st line to the others

	p = &image[w * 2u];
	for (i = 1u; i < h; i++) {

		memcpy(p, image, (w * 2u));
		p += w * 2u;
	}
}
