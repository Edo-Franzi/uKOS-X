/*
; bench_01.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Bench 01: 	Compute the X-Y projection and the histogram of
;						a small square array (200 x 200 uint8_t) elements.
;						The data is located in the CPU internal memory
;
;			Target used: Nucleo_H743 @ 480-MHz
;			Target used: Nucleo_N657 @ 600-MHz
;			Target used: MAiXDUiNO_K210 @ 400-MHz
;			Target used: Discovery_U5G9 @ 160-MHz
;
;			Bench results in [us]:
;
;										_fill	_projX	_projY	_histo
;			Nucleo_H743 @ 480-MHz		171		671		288		450
;			Nucleo_N657 @ 600-MHz		336		754		478		631
;			MAiXDUiNO_K210 @ 400-MHz	538		585		728		1230
;			Discovery_U5G9 @ 160-MHz	1519	1771	1522	2018
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

// CLI tool specific
// =================

#define	KNB_X		200u
#define	KNB_Y		200u
#define	KMAX_BIT	256u

// Prototypes

static	void	local_fill(uint8_t *array, uint64_t *time);
static	void	local_prjX(const uint8_t *array, uint64_t *time, uint32_t *x);
static	void	local_prjY(const uint8_t *array, uint64_t *time, uint32_t *y);
static	void	local_hist(const uint8_t *array, uint64_t *time, uint32_t *h);

/*
 * \brief bench_01
 *
 * - X-Y projection and histogram of a big array
 *
 */
bool	bench_01(void) {
	uint64_t	time[4];
	uint8_t		*array;
	uint32_t	*x, *y, *h;

	array = (uint8_t  *)memo_malloc(KMEMO_ALIGN_8, ((size_t)KNB_X * (size_t)KNB_Y * sizeof(uint8_t)),  "bench"); if (array == nullptr) {											   return (false); }
	x     = (uint32_t *)memo_malloc(KMEMO_ALIGN_8, ((size_t)KNB_X *					sizeof(uint32_t)), "bench"); if (x == nullptr)     { memo_free(array);							   return (false); }
	y     = (uint32_t *)memo_malloc(KMEMO_ALIGN_8, ((size_t)KNB_Y *					sizeof(uint32_t)), "bench"); if (y == nullptr)     { memo_free(array); memo_free(x);			   return (false); }
	h     = (uint32_t *)memo_malloc(KMEMO_ALIGN_8, ((size_t)KMAX_BIT *				sizeof(uint32_t)), "bench"); if (h == nullptr)     { memo_free(array); memo_free(x); memo_free(y); return (false); }

	local_fill(array, &time[0]);
	local_prjX(array, &time[1], x);
	local_prjY(array, &time[2], y);
	local_hist(array, &time[3], h);

	memo_free(h);
	memo_free(y);
	memo_free(x);
	memo_free(array);

// Results
//                        Bench xy: Descriptions, comments, ....                 Execution time
// -----------------------|---------|--------------------------------------------|-----------------|
//
	(void)dprintf(KSYST, "Bench 01: Fill a small 2D array (200 x 200) elements\n"
						 "          in the internal memory. Then, compute the\n"
						 "          X-Y projections and the histogram.\n"
						 "          Fill the array                               t = %6lld [us]\n"
						 "          X projection                                 t = %6lld [us]\n"
						 "          Y projection                                 t = %6lld [us]\n"
						 "          Histogram                                    t = %6lld [us]\n\n", time[0], time[1], time[2], time[3]);
	return (true);
}

// Local routines
// ==============

/*
 * \brief local_fill
 *
 * - Fill the array with a random number
 *
 */
static	void	local_fill(uint8_t *array, uint64_t *time) {
				uint64_t	tStamp[2];
	register	uint32_t	i, j;

	kern_readTickCount(&tStamp[0]);

	INTERRUPTION_OFF_HARD;
	for (i = 0u; i < KNB_X; i++) {
		for (j = 0u; j < KNB_Y; j++) {
			*(array + ((size_t)i * (size_t)KNB_Y) + (size_t)j) = (uint8_t)(j);
		}
	}
	INTERRUPTION_ON_HARD;

	kern_readTickCount(&tStamp[1]);
	*time = tStamp[1] - tStamp[0];
}

/*
 * \brief local_prjX
 *
 * - Compute the X projections
 *
 */
static	void	local_prjX(const uint8_t *array, uint64_t *time, uint32_t *x) {
				uint64_t	tStamp[2];
	register	uint32_t	i, j, *p;

	kern_readTickCount(&tStamp[0]);

	INTERRUPTION_OFF_HARD;
	for (i = 0u; i < KNB_X; i++) {
		*(x + i) = 0u;
		for (j = 0u; j < KNB_Y; j++) {
			p = (x + i);
			*p += (uint32_t)*(array + ((size_t)j * (size_t)KNB_X) + (size_t)i);
		}
	}
	INTERRUPTION_ON_HARD;

	kern_readTickCount(&tStamp[1u]);
	*time = tStamp[1u] - tStamp[0u];
}

/*
 * \brief local_prjY
 *
 * - Compute the Y projections
 *
 */
static	void	local_prjY(const uint8_t *array, uint64_t *time, uint32_t *y) {
				uint64_t	tStamp[2];
	register	uint32_t	*p, i, j, k;

	kern_readTickCount(&tStamp[0]);

	INTERRUPTION_OFF_HARD;
	for (j = 0u; j < KNB_Y; j++) {
		*(y + j) = 0u;
		k = j * KNB_X;
		for (i = 0u; i < KNB_X; i++) {
			p = (y + j);
			*p += (uint32_t)*(array + k + i);
		}
	}
	INTERRUPTION_ON_HARD;

	kern_readTickCount(&tStamp[1]);
	*time = tStamp[1] - tStamp[0];
}

/*
 * \brief local_hist
 *
 * - Compute the histogram
 *
 */
static	void	local_hist(const uint8_t *array, uint64_t *time, uint32_t *h) {
				uint64_t	tStamp[2];
	register	uint32_t	*p, i;

	kern_readTickCount(&tStamp[0]);

	INTERRUPTION_OFF_HARD;
	p = h;
	for (i = 0u; i < KMAX_BIT; i++) {
		*p = 0u;
		p++;
	}

	for (i = 0u; i < (KNB_X * KNB_Y); i++) {
		p = (uint32_t *)((uintptr_t)h + (*(array + i) * sizeof(uint32_t)));
		*p += 1u;
	}
	INTERRUPTION_ON_HARD;

	kern_readTickCount(&tStamp[1]);
	*time = tStamp[1] - tStamp[0];
}
