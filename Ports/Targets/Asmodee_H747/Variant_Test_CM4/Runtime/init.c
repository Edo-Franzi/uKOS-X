/*
; init.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X Asmodee_H747 module.
;
;			!!! This code HAS not to contain static data.
;			!!! It is called before to copy and to initialise
;			!!! the variable into the RAM.
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

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"init         First hardware initialisations.           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Init\n"
									"====\n\n"

									"This code places in a quite state the hardware resources.\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Init,							// Module name (the first letter has to be upper case)
	KID_FAM_STARTUPS,				// Family (defined in the module.h)
	KNUM_INIT,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Runtime specific
// ================

// Prototypes

static	void	local_FPE_Configuration(void);
static	void	local_MPU_Configuration(void);
static	void	local_wait(uint32_t us);

/*
 * \brief init_init
 *
 * - Initialise some basic periphs
 * - GPIO, watchdog, SDRAM
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	init_init(void) {

	local_FPE_Configuration();
	local_MPU_Configuration();

	local_wait(1000000u);
}

/*
 * \brief local_FPE_Configuration
 *
 * - Enable the FPE
 *
 */
static	void	local_FPE_Configuration(void) {

// Set CP10 and CP11 Full Access
// Lazy stacking enable

	SCB->CPACR |= (SCB_CPACR_CP10  | SCB_CPACR_CP11);
	FPE->FPCCR |= (FPE_FPCCR_ASPEN | FPE_FPCCR_LSPEN);
}

/*
 * \brief local_MPU_Configuration
 *
 * - Initialise the MPU for the different
 *   memory regions of the system
 *
 */
static	void	local_MPU_Configuration(void) {

	#if (defined(PRIVILEGED_USER_S))
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,			SZ_FLASH_INT_0,			KMPU_EXECUTABLE,	KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,			SZ_RAM_INT_0,			KMPU_EXECUTABLE,	KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_0_OS,		SZ_RAM_INT_0_OS,		KMPU_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_RAM_INT_1,			SZ_RAM_INT_1,			KMPU_EXECUTABLE,	KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(4u, 0u,	ST_RAM_INT_2_SHARED,	SZ_RAM_INT_2_SHARED,	KMPU_EXECUTABLE,	KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_SHAREABLE,		KMPU_NOT_CASHABLE,	KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(5u, 0u,	ST_PERIPH_SOC,			SZ_PERIPH_SOC,			KMPU_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);
	SET_MPU7_REGION(6u, 0u,	ST_PERIPH_CORE,			SZ_PERIPH_CORE,			KMPU_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);

	#else
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,			SZ_FLASH_INT_0,			KMPU_EXECUTABLE,	KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,			SZ_RAM_INT_0,			KMPU_EXECUTABLE,	KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_1,			SZ_RAM_INT_1,			KMPU_EXECUTABLE,	KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_RAM_INT_2_SHARED,	SZ_RAM_INT_2_SHARED,	KMPU_EXECUTABLE,	KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_SHAREABLE,		KMPU_NOT_CASHABLE,	KMPU_NOT_BUFFERABLE);
	#endif

// Enable branch prediction
// Normally not necessary (always on)

	SCB->CCR |= (1u<<18u);
	DATA_SYNC_BARRIER;
}

/*
 * \brief cmns_wait
 *
 * \param[in]	us		Delay in us
 *
 * \note This function does not return a value (None).
 *
 */
static	void	local_wait(uint32_t us) {
	uint32_t	wkUs = us, time;

	wkUs = (wkUs / 12u) * (KFREQUENCY_CORE / 1000000u);

	for (time = 0u; time < wkUs; time++) { NOP; }
}
