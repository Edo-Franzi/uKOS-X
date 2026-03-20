/*
; stub_TinyUSB.
; =============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the "TinyUSB" library.
;			Multiple profiles
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

// Save the GCC diagnostic
//
#pragma GCC diagnostic	push

// Ignore the GCC diagnostic
//
#pragma GCC diagnostic	ignored	"-Wpedantic"

// cppcheck-suppress missingInclude
//
#include	"tusb.h"

// Restore the GCC diagnostic
//
#pragma GCC	diagnostic	pop

#if (CFG_TUD_CDC > 0)
#include	"TinyUSB/uKOS_Interface/Models/model_TinyUSB_cdc.c_inc"
#endif

#if (CFG_TUD_MSC > 0)
#include	"TinyUSB/uKOS_Interface/Models/model_TinyUSB_msc.c_inc"
#endif

#if (CFG_TUD_VIDEO > 0)
#include	"TinyUSB/uKOS_Interface/Models/model_TinyUSB_video.c_inc"
#endif

uint32_t	SystemCoreClock = KFREQUENCY_CORE;

// Prototypes

static	void	local_OTG_FS_IRQHandler(void);

// Init device stack on configured roothub port

tusb_rhport_init_t deviceInit = {
	.role  = TUSB_ROLE_DEVICE,
	.speed = TUSB_SPEED_AUTO
};

/*
 * \brief stub_TinyUSB_init
 *
 * - USB initialisation
 *
 */
void	stub_TinyUSB_init(void) {

	INTERRUPT_VECTOR(OTG_FS_C0_IRQn, local_OTG_FS_IRQHandler);
	NVIC_SetPriority(OTG_FS_C0_IRQn, KINT_LEVEL_COMMUNICATIONS);

	tusb_init(BOARD_TUD_RHPORT, &deviceInit);
}

/*
 * \brief stub_TinyUSB_cyclic
 *
 * - USB management
 *
 */
void	stub_TinyUSB_cyclic(void) {

	tud_task();
}

// Local routines
// ==============

/*
 * \brief local_OTG_FS_IRQHandler
 *
 */
static	void	local_OTG_FS_IRQHandler(void) {

	tud_int_handler(BOARD_TUD_RHPORT);
}
