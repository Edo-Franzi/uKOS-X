/*
; process_actuator.
; =================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Process: actuator.
;			- Every 1000-ms
;				Send a new value to the dispatcher
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

#define	KTIME_SAMPLING_ACTUATOR		1000u

extern	mbox_t	*vQueue_dispatcher;

// Prototypes

static	void	aProcess(const void *argument);

/*
 * \brief Install & launch the process
 *
 */
bool	installaProcess_actuator(void) {
	bool	status;
	proc_t	*process;

// -------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden[]) = "User_Process_actuator";
	STRG_LOC_CONST(aStrText[]) = "Process actuator.                         (c) EFr-2026";

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0u,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess,							// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_15			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	status = (kern_createProcess(&specification, nullptr, &process) == KERR_KERN_NOERR) ? (true) : (false);
	return (status);
}

/*
 * \brief aProcess
 *
 * Px: - Every 1000-ms
 *		 - Send a new value to the dispatcher
 *
 */
static void __attribute__ ((noreturn)) aProcess(const void *argument) {
	uint8_t		motorPosition = 0x00u;
	uintptr_t	message_actuator;

	UNUSED(argument);

	while (vQueue_dispatcher == nullptr) { kern_suspendProcess(1u); }

	while (true) {
		kern_suspendProcess(KTIME_SAMPLING_ACTUATOR);

		message_actuator = KID_ACTUATOR | (uintptr_t)motorPosition;
		if (kern_writeQueue(vQueue_dispatcher, message_actuator, KWAIT_INFINITY) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Write queue"); exit(EXIT_OS_FAILURE); }

// Gray code motor position

		switch (motorPosition & 0x3u) {
			default:
			case 0x0u: { motorPosition = 0x1u; break; }
			case 0x1u: { motorPosition = 0x3u; break; }
			case 0x2u: { motorPosition = 0x0u; break; }
			case 0x3u: { motorPosition = 0x2u; break; }
		}
	}
}
