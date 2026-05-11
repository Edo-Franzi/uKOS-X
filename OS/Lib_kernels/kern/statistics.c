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

#include	"uKOS.h"
#include	"kern/private/private_processes.h"

#if (KKERN_WITH_STATISTICS_S == true)

/*
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
void	statistics_statistic(proc_t *backwardProcess, uint32_t timeStart, uint32_t timeStop, uint32_t timeLastStart, uint32_t timeE) {
	#define		KNMEAN	3u

	uint16_t	timeP16, timeK16, timeE16;
	uint32_t	core, timeP32, timeK32, timeE32;

	core = GET_RUNNING_CORE;
	vKern_runProc[core]->oStatistic.oNbExecutions++;

// Instantaneous CPU time used by the process and the uKernel

	timeE32 = timeE;
	timeP32 = (timeStop  - timeLastStart);
	timeK32 = (timeStart - timeStop);
	timeP32 = (timeP32 < timeE32) ? (0) : (timeP32 - timeE32);

// Time > than 65535 can only appears @ the first process switch;
// To avoid wrong max, for this case we fix it to 0.
// The idle could potentially be bigger in extremely low powe situation
// (everything is sleeping)

	timeP16 = (timeP32 > 65535u) ? (0u) : ((uint16_t)timeP32);
	timeK16 = (timeK32 > 65535u) ? (0u) : ((uint16_t)timeK32);
	timeE16 = (timeE32 > 65535u) ? (0u) : ((uint16_t)timeE32);

	backwardProcess->oStatistic.oTimePMin = ((backwardProcess->oStatistic.oTimePMin > timeP16) || (backwardProcess->oStatistic.oTimePMin == 0u)) ? (timeP16) : (backwardProcess->oStatistic.oTimePMin);
	backwardProcess->oStatistic.oTimeKMin = ((backwardProcess->oStatistic.oTimeKMin > timeK16) || (backwardProcess->oStatistic.oTimeKMin == 0u)) ? (timeK16) : (backwardProcess->oStatistic.oTimeKMin);
	backwardProcess->oStatistic.oTimeEMin = ((backwardProcess->oStatistic.oTimeEMin > timeE16) || (backwardProcess->oStatistic.oTimeEMin == 0u)) ? (timeE16) : (backwardProcess->oStatistic.oTimeEMin);
	backwardProcess->oStatistic.oTimePMax = ( backwardProcess->oStatistic.oTimePMax < timeP16)													 ? (timeP16) : (backwardProcess->oStatistic.oTimePMax);
	backwardProcess->oStatistic.oTimeKMax = ( backwardProcess->oStatistic.oTimeKMax < timeK16)													 ? (timeK16) : (backwardProcess->oStatistic.oTimeKMax);
	backwardProcess->oStatistic.oTimeEMax = ( backwardProcess->oStatistic.oTimeEMax < timeE16)													 ? (timeE16) : (backwardProcess->oStatistic.oTimeEMax);
	backwardProcess->oStatistic.oTimePAvg = ( backwardProcess->oStatistic.oTimePAvg == 0u)														 ? (timeP16) : (backwardProcess->oStatistic.oTimePAvg);
	backwardProcess->oStatistic.oTimeKAvg = ( backwardProcess->oStatistic.oTimeKAvg == 0u)														 ? (timeK16) : (backwardProcess->oStatistic.oTimeKAvg);
	backwardProcess->oStatistic.oTimeEAvg = ( backwardProcess->oStatistic.oTimeEAvg == 0u)														 ? (timeE16) : (backwardProcess->oStatistic.oTimeEAvg);

	backwardProcess->oStatistic.oTimePCum += (uint64_t)(timeP32);
	backwardProcess->oStatistic.oTimeKCum += (uint64_t)(timeK32);
	backwardProcess->oStatistic.oTimeECum += (uint64_t)(timeE32);

	backwardProcess->oStatistic.oTimePAvg  = (uint16_t)((((uint32_t)backwardProcess->oStatistic.oTimePAvg * ((1u<<KNMEAN) - 1)) + (timeP32))>>KNMEAN);
	backwardProcess->oStatistic.oTimeKAvg  = (uint16_t)((((uint32_t)backwardProcess->oStatistic.oTimeKAvg * ((1u<<KNMEAN) - 1)) + (timeK32))>>KNMEAN);
	backwardProcess->oStatistic.oTimeEAvg  = (uint16_t)((((uint32_t)backwardProcess->oStatistic.oTimeEAvg * ((1u<<KNMEAN) - 1)) + (timeE32))>>KNMEAN);
}
#endif
