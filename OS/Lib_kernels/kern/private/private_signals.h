/*
; private_signals.
; ================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Signal management.
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
 * \addtogroup signals
 * @{
 */

/*!
 * \defgroup private_signals Private Signals
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#define	KSIGN_ANONYMOUS_ID	"Sign_anonymous"

typedef	struct	dsin		dsin_t;

struct dsin {
			uint32_t	oSignalBitPending;						// The pending signals
			uint32_t	oSignalBitGenerate;						// The generated signals
			proc_t		*oSignalFromProcess;					// Ptr on the process that generate the signals
};

struct	sign {
	const	char_t		*oIdentifier;							// Group identifier
			uint16_t	oState;									// Group state
			#define		BSIGN_INSTALLED		0u					// Group installed

			uint32_t	oGroupNumber;							// Group number
			uint32_t	oUsedBit;								// Used bit
			dsin_t		oSynchro[KKERN_NB_PROCESSES];			// Process synchro
			void		(*oCbOnWaiting)(sign_t *handle,
										uint32_t signals,
										proc_t *fromProcess);
};

extern	list_t		vKern_listSign[KNB_CORES];					// Signal list (processes waiting for a signal)
extern	sign_t		vKern_sign[KNB_CORES][KKERN_NB_SIGNALS];	// Group of signals
extern	uint16_t	vKern_nbSign[KNB_CORES];					// Nb of used signals
extern	uint16_t	vKern_nbMaxSign[KNB_CORES];					// Max number of used signals

/**@}*/
/**@}*/
/**@}*/
