/*
; bench_03.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Bench 03: 	Searching for the min / max of a big square array
;						(50000 uint32_t) elements.
;						The data is located in the internal memory.
;						100 iteractions.
;
;			Target used: Nucleo_H743 @ 480-MHz
;			Target used: Nucleo_N657 @ 600-MHz
;			Target used: MAiXDUiNO_K210 @ 400-MHz
;			Target used: Discovery_U5G9 @ 160-MHz
;
;			Bench results in [us]:
;
;										_minMax
;			Nucleo_H743 @ 480-MHz		117
;			Nucleo_N657 @ 600-MHz		85
;			MAiXDUiNO_K210 @ 400-MHz	62
;			Discovery_U5G9 @ 160-MHz	203
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

#define	KNB_TESTS		100u
#define	KNB_ELEMENTS	50000u

// CLI tool specific
// =================

static	void	local_minMax(const uint32_t *array, uint64_t *time, uint32_t *min, uint32_t *max);

/*
 * \brief bench_03
 *
 * - min / max of an small array
 *
 */
bool	bench_03(void) {
	uint64_t	time, sumTime = 0u;
	uint32_t	i, j, *array, value, min, max;

	array = (uint32_t *)memo_malloc(KMEMO_ALIGN_8, (KNB_ELEMENTS * sizeof(uint32_t)), "bench"); if (array == nullptr) { return (false); }

// Initialise the array with a random value

	for (j = 0u; j < KNB_TESTS; j++) {
		for (i = 0u; i < KNB_ELEMENTS; i++) {
			random_read(KRANDOM_SOFT, &value, 1u);
			*(array + i) = value;
		}

		local_minMax(array, &time, &min, &max);
		sumTime += time;
	}
	memo_free(array);

// Results
//                        Bench xy: Descriptions, comments, ....                 Execution time
// -----------------------|---------|--------------------------------------------|-----------------|
//
	(void)dprintf(KSYST, "Bench 03: Fill a big 1D array (50000) elements in\n"
						 "          the internal memory with a random pattern.\n"
						 "          Then, compute the min / max values.\n"
						 "          Number of tests                              n = %6d [-]\n"
						 "          Min / Max                                    t = %6lld [us]\n\n", KNB_TESTS, sumTime);
	return (true);
}

// Local routines
// ==============

/*
 * \brief local_minMax
 *
 * - Compute the min / max of an array
 *
 */
static	void	local_minMax(const uint32_t *array, uint64_t *time, uint32_t *min, uint32_t *max) {
	uint64_t	tStamp[2];
	uint32_t	i;

	kern_readTickCount(&tStamp[0]);

	INTERRUPTION_OFF_HARD;
	*min = UINT32_MAX; *max = 0u;
	for (i = 0u; i < KNB_ELEMENTS; i++) {
		if (*(array + i) < *min) { *min = *(array + i); }
		if (*(array + i) > *max) { *max = *(array + i); }
	}
	INTERRUPTION_ON_HARD;

	kern_readTickCount(&tStamp[1]);
	*time = tStamp[1] - tStamp[0];
}
