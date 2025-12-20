/*
; image.
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
;   (c) 2025-20xx, Edo. Franzi
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
 *			Launch 2 processes:
 *
 *			- P0: Waiting for the semaphore "imgx - Acquisition"
 *					- Acquire an image and send it
 *
 *			- P1: Sending the image
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"image        Example of how to use an imager.          (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  image\n"
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

// Application specific
// ====================

STRG_LOC_CONST(aStrAcquisition[]) = "imager - Acquisition";
STRG_LOC_CONST(aStrShareBuffer[]) = "Share_Buffer";

static	sema_t		*vSemaImgAcqu;
static	uint8_t		*vImage = NULL;
static	uint32_t	vW, vH;

// Prototypes

		void	TinyUSB_video_init(void);
		void	TinyUSB_video_getImageSize(uint32_t *w, uint32_t *h);
		void	TinyUSB_video_sendImage(uint8_t *image, uint32_t w, uint32_t h);
static	void	local_initialiseYUY2(uint8_t *output, uint32_t w, uint32_t h);
static	void	local_convertToYUY2(const uint8_t *input, uint8_t *output, uint32_t w, uint32_t h);
static	void	local_transfer(void);

/*
 * \brief aProcess_acquisition
 *
 * - P0: Waiting for the semaphore "imgx - Acquisition"
 *			- Acquire an image
 *
 */
static void __attribute__ ((noreturn)) aProcess_acquisition(const void *argument) {
	imagerCnf_t	configureIMG0;
	mutx_t			*mutex;

	UNUSED(argument);

	if (kern_createSemaphore(aStrAcquisition, 0, 1, &vSemaImgAcqu) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create sema G"); exit(EXIT_OS_FAILURE); }

// Configurations for an imager APTINA

	configureIMG0.oAcqMode  = KIMAGER_SNAP;
	configureIMG0.oImgCnf   = NULL;
	configureIMG0.oPixMode  = KIMAGER_PIX_8_BITS;
	configureIMG0.oStRows   = 0u;
	configureIMG0.oStCols   = 0u;
	configureIMG0.oNbRows	= (uint16_t)vH;
	configureIMG0.oNbCols	= (uint16_t)vW;
	configureIMG0.oKernSync = 0u;
	configureIMG0.oHSync    = NULL;
	configureIMG0.oFrame    = NULL;
	configureIMG0.oVSync    = local_transfer;
	configureIMG0.oDMAEc    = NULL;

	if (imager_configure(&configureIMG0) != KERR_IMAGER_NOERR) {
		(void)dprintf(KSYST, "img0 manager problem\n");
	}

// At the power-on the imager starts to send images.
// Just after the SNAP initialization it is necessary waiting for the end of the
// current transfer (~ 40-ms) before starting.

	kern_suspendProcess(40u);
	imager_acquisition();

// Get the mutex "Share_Buffer" ID

	kern_getMutexById(aStrShareBuffer, &mutex);

	while (true) {

// Waiting for the semaphore "vSemaImgAcqu"

		kern_waitSemaphore(vSemaImgAcqu, KWAIT_INFINITY);

		kern_lockMutex(mutex, KWAIT_INFINITY);
		imager_read((volatile void **)&vImage);
		kern_unlockMutex(mutex);

		imager_acquisition();
	}
}

/*
 * \brief aProcess_send
 *
 * - P1: Send an image
 *
 */
static void __attribute__ ((noreturn)) aProcess_send(const void *argument) {
	uint8_t		*imageGray, *imageYUY2;
	mutx_t		*mutex;

	UNUSED(argument);

	PRIVILEGE_ELEVATE;

	imageYUY2 = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (vW * vH * 2), "image");
	if (imageYUY2 == NULL) {
		LOG(KFATAL_USER, "Out of memory");
		exit(EXIT_OS_FAILURE);
	}

// Initialise the imageYUY2 buffer with the U=V=128 constants

	local_initialiseYUY2(imageYUY2, vW, vH);

// Get the mutex "Share_Buffer" ID

	kern_getMutexById(aStrShareBuffer, &mutex);

	while (true) {
		imageGray = vImage;
		if (imageGray != NULL) {
			kern_lockMutex(mutex, KWAIT_INFINITY);
			local_convertToYUY2(imageGray, imageYUY2, vW, vH);
			kern_unlockMutex(mutex);

			TinyUSB_video_sendImage(imageYUY2, vW, vH);
			led_toggle(KLED_0);
		}
		else {
			kern_suspendProcess(1u);
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
int		main(int argc, const char *argv[]) {
	mutx_t	*mutex;
	proc_t	*process_acquisition, *process_send;

// -------------------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_acquisition[]) = "Process_Acquisition";
	STRG_LOC_CONST(aStrText_acquisition[]) = "Process Acquisition.                      (c) EFr-2025";
	STRG_LOC_CONST(aStrIden_send[])		   = "Process_Send_Image";
	STRG_LOC_CONST(aStrText_send[])		   = "Process Send Image.                       (c) EFr-2025";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_acquisition,			// Specifications (just use specification_x)
		aStrText_acquisition,				// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_acquisition,				// Code of the process
		aStrIden_acquisition,				// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_send,					// Specifications (just use specification_x)
		aStrText_send,						// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_send,						// Code of the process
		aStrIden_send,						// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	TinyUSB_video_init();
	TinyUSB_video_getImageSize(&vW, &vH);

	if (kern_createMutex(aStrShareBuffer, &mutex)								   != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create mutx"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_acquisition, NULL, &process_acquisition) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_send,		   NULL, &process_send)		   != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_transfer
 *
 * - waiting for the semaphore "vSemaImgAcqu"
 *		- Signal end of the acquisition
 *
 * - !!! This is an interrupt call-back function
 *       Not all the system calls are allowed inside this portion of code
 *
 */
static	void	local_transfer(void) {

	led_toggle(3);
	kern_signalSemaphore(vSemaImgAcqu);
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
 * \brief local_convertToYUY2
 *
 * - Conversion 8-bit Gray scale to YUY2
 *		- i		Pix i
 *		- i + 1	128
 *		- i + 2	Pix i + 1
 *		- i + 3	128
 *
 */
static	void	local_convertToYUY2(const uint8_t *input, uint8_t *output, uint32_t w, uint32_t h) {
	uint32_t	i;

	for (i = 0u; i < (w * h); i += 2u) {

// Conversion Gray scale to YUY2

		output[i * 2u]		  = input[i];
		output[(i * 2u) + 2u] = input[i + 1];
	}
}
