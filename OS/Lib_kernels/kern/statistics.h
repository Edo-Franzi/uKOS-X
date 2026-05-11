/*
; statistics.
; ===========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Statistic management.
;
;			This module is responsible for computing the statistic of
;			the uKernel.
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

#if (KKERN_WITH_STATISTICS_S == true)

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup statistics Statistics
 *
 * \brief Statistics
 *
 * Statistic management
 *
 * @{
 */

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
 * \brief statistics_statistic
 *
 *   time
 *
 *          uKernel   process                  uKernel
 *    ----+         +------------------------+         +-------------------------
 *        |         |                        |         |
 *        +---------+                        +---------+
 *                ^                            ^     ^
 *                LastStart                    Stop  Start
 *    ............--------------------------------->----------------------.......
 *                      backward                       forward
 *
 *    ..............---xx---xxxx----x-x----xx-..........---xx---xxx-------.......
 *                      exceptions
 *
 * Durations:
 *  - uKernel   time = Start - Stop
 *  - Process   time = Stop - LastStart
 *  - Exception time = Sum ( x )
 *
 * For each process:
 * - PMin PAvg PMax in [us] (P stand for Process)
 * - KMin KAvg KMax in [us] (K stand for uKernel)
 * - EMin EAvg EMax in [us] (E stand for Exception)
 *
 * - The average time is computed in this way:
 *   - KNMEAN = 3, 2^3 = 8
 *
 *                            x ------- 7 ------- +   1       / ---- 8 -----
 *   - PAvg[k+1] = ( (PAvg[k] x ((1u<<KNMEAN)-1)) + PIns[k] ) / (1u<<KNMEAN)
 *   - KAvg[k+1] = ( (KAvg[k] x ((1u<<KNMEAN)-1)) + KIns[k] ) / (1u<<KNMEAN)
 *   - EAvg[k+1] = ( (EAvg[k] x ((1u<<KNMEAN)-1)) + EIns[k] ) / (1u<<KNMEAN)
 *
 * \param[in]	*backwardProcess	Ptr on the backward process
 * \param[in]	timeStart			Time when the process was scheduled
 * \param[in]	timeStop			Time when the process was stopped
 * \param[in]	timeLastStart		Time when the process was started (previous cycle)
 * \param[in]	timeE				Time spent in the exceptions (int managers)
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	statistics_statistic(proc_t *backwardProcess, uint32_t timeStart, uint32_t timeStop, uint32_t timeLastStart, uint32_t timeE);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/

#endif
