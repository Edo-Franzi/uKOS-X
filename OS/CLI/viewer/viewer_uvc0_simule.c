/*
; viewer_uvc0_simule.
; ===================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Image viewer.
;			This tool allows to send a simulated image via the uvc0 manager.
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
#include	<string.h>

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_GLB_CONST(aStrApplication[]) = "viewer       Send an image, via the uvc0 manager.      (c) EFr-2026";
STRG_GLB_CONST(aStrHelp[])		  = "Send a simulated image to the computer\n"
									"======================================\n\n"

								    "Input format:  viewer\n"
								    "Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// CLI tool specific
// =================

typedef	struct	graphic		graphic_t;

struct	graphic {
			uint32_t	oW;					// Image width
			uint32_t	oH;					// Image heigh
			uint8_t		*oImage;			// Ptr on the image
		};

[[gnu::weak]]
extern	uint8_t		linker_stUSB_V_BUFFER_0[];

[[gnu::weak]]
extern	uint8_t		linker_stUSB_V_BUFFER_1[];
static	bool		vKillRequest[KNB_CORES] = MCSET(false);

// Prototypes

		void	TinyUSB_video_init(void);
		void	TinyUSB_video_getImageSize(uint32_t *w, uint32_t *h);
		void	TinyUSB_video_sendImage(uint8_t *image, uint32_t w, uint32_t h, void (*callBack)(const void *argument), const void *argument);
static	void	aProcess(const void *argument);
static	void	local_callBack(const void *argument);
static	void	local_prepareImage(uint8_t *image, uint32_t w, uint32_t h, uint32_t position);

/*
 * \brief viewer_uvc0
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int32_t	viewer_uvc0(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;
	proc_t		*process;

// -------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden[]) = "Process_User";
	STRG_LOC_CONST(aStrText[]) = "Process user.                             (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	vKillRequest[core] = false;

// Specifications for the processes

	PROCESS(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess,							// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_05				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, &vKillRequest[core], &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "viewer: create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "viewer: application launched");
	return (EXIT_OS_SUCCESS_CLI);
}

/*
 * \brief viewer_uvc0_clean
 *
 * - Try to clean the ressources
 *		- Free all the ressources
 *
 */
int32_t	viewer_uvc0_clean(uint32_t argc, const char_t *argv[]) {
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
 * \brief aProcess
 *
 * - Px: Repeat every xyz ms
 *			- Prepare an image
 *			- Send it over usb
 *
 */
[[noreturn]]
static	void	aProcess(const void *argument) {
			uint32_t	w, h;
			float64_t	frameRate;
			uint8_t		*image_0, *image_1;
			uint64_t	time[2];
			graphic_t	pack_0, pack_1;
	const	bool		*killRequest;

	killRequest	= (const bool *)argument;

	PRIVILEGE_ELEVATE;

	TinyUSB_video_init();
	TinyUSB_video_getImageSize(&w, &h);

	image_0 = (uint8_t *)memo_malloc(KMEMO_ALIGN_32, (w * h * 2u), "video");
	image_1 = (uint8_t *)memo_malloc(KMEMO_ALIGN_32, (w * h * 2u), "video");
	if ((image_0 == nullptr) || (image_1 == nullptr)) {

		memo_free(image_0);
		memo_free(image_1);

		if ((linker_stUSB_V_BUFFER_0 != nullptr) && (linker_stUSB_V_BUFFER_1 != nullptr)) {
			image_0 = (uint8_t *)linker_stUSB_V_BUFFER_0;
			image_1 = (uint8_t *)linker_stUSB_V_BUFFER_1;

			LOG(KINFO_USER, "viewer: video buffers in PSRAm");
		}
		else {
			LOG(KFATAL_USER, "viewer: out of memory");
			exit(EXIT_OS_FAILURE);
		}
	}

	pack_0.oW = w; pack_0.oH = h; pack_0.oImage = image_0;
	pack_1.oW = w; pack_1.oH = h; pack_1.oImage = image_1;

	local_prepareImage(image_0, w, h, 0u);

	while (*killRequest == false) {

// Send it over usb
// Prepare the next image
// During the waiting for the transfer acknowledge, the callback prepares the next image

		kern_readTickCount(&time[0]);
		TinyUSB_video_sendImage(image_0, w, h, local_callBack, (const void *)&pack_1);
		TinyUSB_video_sendImage(image_1, w, h, local_callBack, (const void *)&pack_0);
		kern_readTickCount(&time[1]);

		frameRate = (1000000.0 / (float64_t)(time[1] - time[0])) * 2.0;

		(void)dprintf(KSYST, "Image size: %"PRIu32" x %"PRIu32", Frame rate = %5.2f-fps\n", w, h, frameRate);
	}

// Kill the process & the ressources

	PRIVILEGE_RESTORE;

	INTERRUPTION_OFF;
	memo_free(image_0);
	memo_free(image_1);

	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief local_callBack
 *
 * - Prepare an image (called by TinyUSB_video_sendImage)
 *
 */
static	void	local_callBack(const void *argument) {
	const	graphic_t	*pack;
	static	uint32_t	position = 0u;

	pack = (const graphic_t *)argument;

	local_prepareImage(pack->oImage, pack->oW, pack->oH, position++);
}

/*
 * \brief local_prepareImage
 *
 * - Prepare an image (vertical bars)
 *
 */
static	void	local_prepareImage(uint8_t *image, uint32_t w, uint32_t h, uint32_t position) {
			size_t		i, j, idx;
			uint8_t		*p;
	const	size_t		half = (size_t)w / 2u;
	const	size_t		rowBytes = (size_t)w * 2u;
	const	size_t		span = ((size_t)w) / (2u * 8u);
	const	uint8_t		*end;


// EBU color bars: https://stackoverflow.com/questions/6939422

	static	const	uint8_t		aColorBars[8][4] = {

//		     Y,    U,    Y,    V
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

	end = &image[rowBytes];
	idx = (half - 1u) - ((size_t)position % half);
	p = &image[idx * 4u];

	for (i = 0u; i < 8u; i++) {
		for (j = 0u; j < span; j++) {
			memcpy(p, &aColorBars[i][0], 4u);
			p += 4u;
			if (p == end) {
				p = image;
			}
		}
	}

// Duplicate the 1st line to the others

	p = &image[rowBytes];
	for (i = 1u; i < (size_t)h; i++) {

		memcpy(p, image, rowBytes);
		p = &p[rowBytes];
	}
}
