/*
; private_preciseSignals.
; =======================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Precise signals.
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
 * \addtogroup preciseSignals
 * @{
 */

/*!
 * \defgroup private_preciseSignals Private Precise Signals
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#if (KKERN_NB_PRECISE_SIGNALS > 0)

#define	KPRCS_ANONYMOUS_ID			"Prcs_anonymous"
#define	KPRCS_DEFAULT_SIGNAL_GROUP	"Def_Signal_Group"

extern	prcs_t		vKern_prcs[KNB_CORES][KKERN_NB_PRECISE_SIGNALS];	// Precise signals
extern	uint16_t	vKern_nbPrcs[KNB_CORES];							// Nb of used precise signals
extern	uint16_t	vKern_nbMaxPrcs[KNB_CORES];							// Max number of used precise signals
#endif

/**@}*/
/**@}*/
/**@}*/
