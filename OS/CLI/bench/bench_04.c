/*
; bench_04.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Bench 04: 	Compute the atan2(x, y) by a cordic in a fixed point.
;						The data is located in the external memory.
;						1000 iteractions.
;
;			Target used: Nucleo_H743 @ 480-MHz
;			Target used: Nucleo_N657 @ 600-MHz
;			Target used: MAiXDUiNO_K210 @ 400-MHz
;			Target used: Discovery_U5G9 @ 160-MHz
;
;			Bench results in [us]:
;
;										_atan2
;			Nucleo_H743 @ 480-MHz		1129
;			Nucleo_N657 @ 600-MHz		870
;			MAiXDUiNO_K210 @ 400-MHz	566
;			Discovery_U5G9 @ 160-MHz	2049
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

#define	KNB_TESTS			1000u
#define	KMAX_ITERATIONS		32u

#define KPI					(float64_t)(3.14159265358979f)
#define K180				(float64_t)(180.0f)
#define KRAD_TO_DEG			(K180 / KPI)

// Prototypes

static	void	 local_atan2(uint64_t *time, float64_t *angle, int32_t y, int32_t x);

/*
 * \brief bench_04
 *
 * - aten2(y, x)
 *
 */
bool	bench_04(void) {
	uint64_t	time, sumTime = 0u;
	uint32_t	j;
	int32_t		x, y;
	float64_t	angle;

// atan2(234, 10345) = 178.7042-deg

	x = 10345; y = 234;

	for (j = 0u; j < KNB_TESTS; j++) {
		local_atan2(&time, &angle, y, x);
		sumTime += time;
	}

// Results
//                        Bench xy: Descriptions, comments, ....                 Execution time
// -----------------------|---------|--------------------------------------------|-----------------|
//
	(void)dprintf(KSYST, "Bench 04: Compute the integer atan2 using the CORDIC\n"
						 "          algorithm\n"
						 "          Angle                                        a = %3.6f [Rad]\n"
						 "          Number of tests                              n = %8d [-]\n"
						 "          1000 x atan2(y, x)                           t = %8lld [us]\n\n", angle, KNB_TESTS, sumTime);
	return (true);
}

// Local routines
// ==============

/*
 * \brief local_atan2
 *
 * - Compute the atan2
 *
 */
static	void local_atan2(uint64_t *time, float64_t *angle, int32_t y, int32_t x) {
						uint64_t	tStamp[2];
			register	uint32_t	i, j, sh;
			register	int32_t		yi, lx, ly;
	static	const		float64_t	aTabAtan[] = {
										0.785398163397448000000000000000, 0.463647609000806000000000000000,
										0.244978663126864000000000000000, 0.124354994546761000000000000000,
										0.062418809995957400000000000000, 0.031239833430268300000000000000,
										0.015623728620476800000000000000, 0.007812341060101110000000000000,
										0.003906230131966970000000000000, 0.001953122516478820000000000000,
										0.000976562189559319000000000000, 0.000488281211194898000000000000,
										0.000244140620149362000000000000, 0.000122070311893670000000000000,
										0.000061035156174208800000000000, 0.000030517578115526100000000000,
										0.000015258789061315800000000000, 0.000007629394531101970000000000,
										0.000003814697265606500000000000, 0.000001907348632810190000000000,
										0.000000953674316405961000000000, 0.000000476837158203089000000000,
										0.000000238418579101558000000000, 0.000000119209289550781000000000,
										0.000000059604644775390600000000, 0.000000029802322387695300000000,
										0.000000014901161193847700000000, 0.000000007450580596923830000000,
										0.000000003725290298461910000000, 0.000000001862645149230960000000,
										0.000000000931322574615479000000, 0.000000000465661287307739000000
									};

	kern_readTickCount(&tStamp[0]);

	INTERRUPTION_OFF_HARD;
	for (i = 0u; i < KNB_TESTS; i++) {
		*angle = 0.0;

// Special case: vectors = 0

		if ((x == 0) && (y == 0)) {
			*angle = 0.0;
			INTERRUPTION_ON_HARD;

			kern_readTickCount(&tStamp[1]);
			*time = ((uint32_t)(tStamp[1] - tStamp[0]));
			return;
		}

		lx = x; ly = y;

// Verify the right plane

		if (lx < 0) { lx = -lx; ly = -ly; *angle = KPI;	   }
		if (ly > 0) {                     *angle = -(*angle); }

// Rotate the vector and compute the angle

		for (j = 0u; j < KMAX_ITERATIONS; j++) {
			if (ly < 0) {
				sh = ((uint32_t)lx)>>j;
				yi = ly + (int32_t)sh;

				sh = ((uint32_t)ly)>>j;
				lx = lx - (int32_t)sh;

				ly = yi;
				*angle -= aTabAtan[j];
			}
			else {
				sh = ((uint32_t)lx)>>j;
				yi = ly - (int32_t)sh;

				sh = ((uint32_t)ly)>>j;
				lx = lx + (int32_t)sh;

				ly = yi;
				*angle += aTabAtan[j];
			}
		}
	}
	INTERRUPTION_ON_HARD;

	kern_readTickCount(&tStamp[1]);
	*time = tStamp[1] - tStamp[0];
}
