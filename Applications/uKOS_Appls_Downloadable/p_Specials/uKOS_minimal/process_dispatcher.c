/*
; process_dispatcher.
; ===================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Process: dispatcher.
;			- As soon as a new data is available on the queue
;				process it
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
#include	"queue.h"

extern	mbox_t	*vQueue_dispatcher;

// Prototypes

static	void	aProcess(const void *argument);

/*
 * \brief Install & launch the process
 *
 */
bool	installaProcess_dispatcher(void) {
	bool	status;
	proc_t	*process;

// -------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden[]) = "User_Process_dispatcher";
	STRG_LOC_CONST(aStrText[]) = "Process dispatcher.                       (c) EFr-2026";

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0u,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess,							// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_15				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	status = (kern_createProcess(&specification, nullptr, &process) == KERR_KERN_NOERR) ? (true) : (false);
	return (status);
}

/*
 * \brief aProcess
 *
 * Px: - As soon as a new data is available on the queue
 *		 - Process it
 *
 */
static void __attribute__ ((noreturn)) aProcess(const void *argument) {
	uintptr_t	message;

	UNUSED(argument);

	while (vQueue_dispatcher == nullptr) { kern_suspendProcess(1u); }

	while (true) {
		if (kern_readQueue(vQueue_dispatcher, &message, KWAIT_INFINITY) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Read queue"); exit(EXIT_OS_FAILURE); }

// Process the information coming from the queue

		switch (message & 0xFF000000u) {
			case KID_SENSOR: {
				((message & 1u) == 1u) ? (led_on(KLED_1)) : (led_off(KLED_1));
				break;
			}
			case KID_ACTUATOR: {
				switch (message & 0x3u) {
					case 0x0u: { (void)dprintf(KURT0, "Motor position 00\n"); break; }
					case 0x1u: { (void)dprintf(KURT0, "Motor position 01\n"); break; }
					case 0x2u: { (void)dprintf(KURT0, "Motor position 02\n"); break; }
					case 0x3u: { (void)dprintf(KURT0, "Motor position 03\n"); break; }
					default: {

// Make MISRA happy :-)

						break;
					}
				}
				break;
			}
			default: { (void)dprintf(KURT0, "ID queue problem\n"); break; }
		}
	}
}
