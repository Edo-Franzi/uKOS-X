/*
; viewer_uvc0_imager.
; ===================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Image viewer.
;			This tool allows to send an image via the uvc0 manager.
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

#if (defined(CONFIG_MAN_IMAGER_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_GLB_CONST(aStrApplication[]) = "viewer       Send img0 images, via the uvc0 manager.   (c) EFr-2026";
STRG_GLB_CONST(aStrHelp[])		  = "Acquire & send an image to the computer\n"
									"=======================================\n\n"

									"Input format:  viewer\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// CLI tool specific
// =================

// ---------------------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden_acquisition[]) = "Process_Acquisition";
STRG_LOC_CONST(aStrText_acquisition[]) = "Process Acquisition.                      (c) EFr-2026";
STRG_LOC_CONST(aStrImageReady[])	   = "image - Ready";

static	sema_t	*vSemaphore_IM[KNB_CORES];
static	bool	vKillRequest[KNB_CORES] = MCSET(false);

// Prototypes

		void	TinyUSB_video_init(void);
		void	TinyUSB_video_clean(void);
		void	TinyUSB_video_getImageSize(uint32_t *w, uint32_t *h);
		void	TinyUSB_video_sendImage(uint8_t *image, uint32_t w, uint32_t h, void (*callBack)(const void *argument), const void *argument);
static	void	local_initialiseYUY2(uint8_t *output, uint32_t w, uint32_t h);
static	void	local_initialiseReal(uint8_t *output, uint32_t w, uint32_t h);
static	void	local_scaleImage(volatile const uint8_t *input, uint8_t *output, uint32_t w, uint32_t h);
static	void	local_convertToYUY2(volatile const uint8_t *input, uint8_t *output, uint32_t w, uint32_t h);
static	void	local_transfer(void);
static	void	aProcess_acquisition(const void *argument);

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

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	vKillRequest[core] = false;

	RESERVE(IMAGER, KMODE_ALL);

// Specifications for the processes

	PROCESS(
		0,									// Index
		specification_acquisition,			// Specifications (just use specification_x)
		aStrText_acquisition,				// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_acquisition,				// Code of the process
		aStrIden_acquisition,				// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_acquisition, &vKillRequest[core], &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "viewer: create proc"); return (EXIT_OS_FAILURE); }

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
 * \brief aProcess_acquisition
 *
 * - P0: Waiting for the semaphore "imgx - Acquisition"
 *			- Acquire an image
 *			- Send an image
 *
 */
[[noreturn]]
static	void	aProcess_acquisition(const void *argument) {
				uint32_t		core;
				uint32_t		w, h;
				uint8_t			*imageYUY2, *imageReal;
				imagerCnf_t		configureIMAGER;
	const		bool			*killRequest;
	volatile	void			*imageOld, *imageXX = nullptr;

	core = GET_RUNNING_CORE;
	killRequest	= (const bool *)argument;

	PRIVILEGE_ELEVATE;

	TinyUSB_video_init();
	TinyUSB_video_getImageSize(&w, &h);

	imageYUY2 = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (w * h * 2u), "viewer_uvc0_YUY2");
	imageReal = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (w * h),		"viewer_uvc0_Real");
	if ((imageYUY2 == nullptr) || (imageReal == nullptr)) {
		LOG(KFATAL_USER, "viewer: out of memory");
		exit(EXIT_OS_FAILURE);
	}

	if (kern_createSemaphore(aStrImageReady, 0, 1, &vSemaphore_IM[core]) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "viewer: create sema"); exit(EXIT_OS_FAILURE); }

// Configurations for an imager APTINA

	configureIMAGER.oAcqMode  = KIMAGER_SNAP;
	configureIMAGER.oImgCnf   = nullptr;
	configureIMAGER.oPixMode  = KIMAGER_PIX_8_BITS;
	configureIMAGER.oStRows   = 0u;
	configureIMAGER.oStCols   = 0u;
	configureIMAGER.oNbRows	  = (uint16_t)KNB_ROWS;
	configureIMAGER.oNbCols   = (uint16_t)KNB_COLS;
	configureIMAGER.oKernSync = 0u;
	configureIMAGER.oHSync    = nullptr;
	configureIMAGER.oFrame    = nullptr;
	configureIMAGER.oVSync    = local_transfer;
	configureIMAGER.oDMAEc    = nullptr;

	if (imager_configure(&configureIMAGER) != KERR_IMAGER_NOERR) {
		(void)dprintf(KSYST, "img0 manager problem\n");
	}

	local_initialiseYUY2(imageYUY2, w, h);
	local_initialiseReal(imageReal, w, h);

// At the power-on the imager starts to send images.
// Just after the SNAP initialisation it is necessary waiting for the end of the
// current transfer (~ 40-ms) before starting.

	kern_suspendProcess(40u);
	imager_read(&imageOld);
	imager_acquisition();

	while (*killRequest == false) {

// Waiting for the semaphore "vSemaphore_IM"

		kern_waitSemaphore(vSemaphore_IM[core], KWAIT_INFINITY);
		imager_read(&imageXX);

		if (imageXX != imageOld) {
			imageOld = imageXX;

			local_scaleImage((volatile const uint8_t *)imageXX, imageReal, w, h);
			local_convertToYUY2((volatile const uint8_t *)imageReal, imageYUY2, w, h);
			TinyUSB_video_sendImage(imageYUY2, w, h, nullptr, nullptr);
		}
		imager_acquisition();
	}

// Kill the process & the ressources

	PRIVILEGE_RESTORE;

	INTERRUPTION_OFF;
	RELEASE(IMAGER, KMODE_READ_WRITE);

	TinyUSB_video_clean();
	kern_killSemaphore(vSemaphore_IM[core]);
	memo_free(imageYUY2);

	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief local_transfer
 *
 * - Signal end of the acquisition
 *
 * - !!! This is an interrupt call-back function
 *       Not all the system calls are allowed inside this portion of code
 *
 */
static	void	local_transfer(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;
	kern_signalSemaphore(vSemaphore_IM[core]);
}

/*
 * \brief local_initialiseYUY2
 *
 * - Prepare the YUY2 image with U & V
 *		- i + 1	U = 128
 *		- i + 3	V = 128
 *
 */
static	void	local_initialiseYUY2(uint8_t *output, uint32_t w, uint32_t h) {
	uint32_t	i;

	for (i = 0u; i < (w * h); i += 2u) {
		output[(i * 2u) + 1u] = 128u;
		output[(i * 2u) + 3u] = 128u;
	}
}

/*
 * \brief local_initialiseReal
 *
 * - Prepare the Real image with an initial value
 *
 */
static	void	local_initialiseReal(uint8_t *output, uint32_t w, uint32_t h) {

	memset(output, 0u, (size_t)(w * h));
}

/*
 * \brief local_scaleImage
 *
 * - Scale an image of KNB_ROWS x KNB_COLS to an image of h x w
 *	 w has to be > KNB_COLS
 *	 h has to be > KNB_ROWS
 */
static	void	local_scaleImage(volatile const uint8_t *input, uint8_t *output, uint32_t w, uint32_t h) {
	uint32_t	i, j;

	(void)h;

	for (i = 0u; i < KNB_ROWS; i++) {
		for (j = 0u; j < KNB_COLS; j++) {
			output[j] = input[j];
		}

		output = (uint8_t *)((uintptr_t)output + (uintptr_t)w);
		input  = (uint8_t *)((uintptr_t)input  + (uintptr_t)KNB_COLS);
	}
}

/*
 * \brief local_convertToYUY2
 *
 * - Conversion 8-bit Gray scale to YUY2
 *		- i		Pix i
 *		- i + 1	128
 *		- i + 2	Pix i + 1
 *		- i + 3	128
 *
 */
static	void	local_convertToYUY2(volatile const uint8_t *input, uint8_t *output, uint32_t w, uint32_t h) {
	uint32_t	i;

	for (i = 0u; i < (w * h); i += 2) {

// Conversion Gray scale to YUY2

		output[i * 2u]		  = input[i];
		output[(i * 2u) + 2u] = input[i + 1u];
	}
}
#endif
