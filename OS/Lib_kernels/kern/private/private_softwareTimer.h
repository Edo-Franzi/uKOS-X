/*
; private_softwareTimer.
; ======================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Software timers.
;
;			Private uKernel variables.
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

#pragma	once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \addtogroup softwareTimer
 * @{
 */

/*!
 * \defgroup private_softwareTimer Private SoftwareTimer
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#if (KKERN_NB_SOFTWARE_TIMERS > 0)

#define	KSTIM_ANONYMOUS		"Stim_anonymous"

struct	stim {
	const	char_t		*oIdentifier;									// Software timer identifier
			uint16_t	oState;											// Software timer state
			#define		BSTIM_INSTALLED			0u						// Software timer installed
			#define		BSTIM_CONFIGURED		1u						// Software timer configured
			#define		BSTIM_RE_CONFIGURED		2u						// Software timer reconfigured
			#define		BSTIM_RUNNING			3u						// Software timer is running
			#define		BSTIM_EXECUTED			4u						// Software timer executed (once)

			uint32_t	oInitCounter;									// Initial time (decremented)
			uint32_t	oCounter;										// Continuous time (decremented)
			tspc_t		oTimerSpec;										// Software timer specifications
};

extern	uint16_t	vKern_curStim[KNB_CORES];							// Currently executed software timer
extern	proc_t		*vStimer_handle[KNB_CORES];							// Daemon Software timer handle
extern	stim_t		vKern_stim[KNB_CORES][KKERN_NB_SOFTWARE_TIMERS];	// Software timers
extern	uint16_t	vKern_nbStim[KNB_CORES];							// Nb of used software timers
extern	uint16_t	vKern_nbMaxStim[KNB_CORES];							// Max number of used software timers
#endif

/**@}*/
/**@}*/
/**@}*/
