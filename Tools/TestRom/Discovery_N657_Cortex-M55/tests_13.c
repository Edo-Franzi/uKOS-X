/*
; tests_13.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-03-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the MVE/Helium dot product benchmark.
;
;   (c) 2025-2026, Laurent von Allmen
;   ---------------------------------
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

#include	"tests.h"

#if (defined(TEST_13_S))

#if (defined(__ARM_FEATURE_MVE) && (__ARM_FEATURE_MVE >= 3))
#include	<arm_mve.h>
#define	HAVE_MVE	1

#else
#define	HAVE_MVE	0
#endif

#define	VECTOR_SIZE		1024u
#define	BENCH_PAUSE		2000000u

// SysTick helpers
// ---------------

#define	SYSTICK_MAX		0x00FFFFFFu

static	void	local_sysTick_init(void) {

	SysTick_S->CTRL = 0u;
	SysTick_S->LOAD = SYSTICK_MAX;
	SysTick_S->VAL  = 0u;
	SysTick_S->CTRL = SysTick_CTRL_CLKSOURCE | SysTick_CTRL_ENABLE;
}

// DSB + ISB flush the pipeline so that the SysTick read
// reflects the actual cycle count at this point in time.

[[gnu::noinline]]
static	uint32_t	local_sysTick_read(void) {

	__asm volatile ("dsb sy" ::: "memory");
	__asm volatile ("isb"    ::: "memory");
	return SysTick_S->VAL;
}

// Elapsed cycles accounting for the 24-bit down-counter wrap-around

#define	SYSTICK_ELAPSED(start, end)	(((start) - (end)) & SYSTICK_MAX)

// Scalar dot product (plain C)
// ----------------------------

[[gnu::noinline, gnu::optimize("no-tree-vectorize")]]
static	float	scalar_dot_f32(const float *a, const float *b, uint32_t n) {
	float	sum = 0.0f;

	for (uint32_t i = 0u; i < n; i++) {
		sum += a[i] * b[i];
	}
	return sum;
}

// MVE dot product (Helium intrinsics)
// ------------------------------------

#if (HAVE_MVE)
[[gnu::noinline, gnu::optimize("O2")]]
static	float	mve_dot_f32(const float *a, const float *b, uint32_t n) {
	float32x4_t	vAcc = vdupq_n_f32(0.0f);
	uint32_t	remaining = n;
	uint32_t	idx = 0u;

	while (remaining > 0u) {
		mve_pred16_t	pred = vctp32q(remaining);
		float32x4_t		vA = vldrwq_z_f32(&a[idx], pred);
		float32x4_t		vB = vldrwq_z_f32(&b[idx], pred);

		vAcc = vfmaq_m_f32(vAcc, vA, vB, pred);
		idx += 4u;
		remaining -= (remaining >= 4u) ? (4u) : (remaining);
	}

	// Horizontal sum of the four lanes
	return vAcc[0] + vAcc[1] + vAcc[2] + vAcc[3];
}
#endif

/*
 * \brief test_13
 *
 * - Test of the MVE/Helium dot product benchmark
 *   Measures cycle counts for scalar vs MVE dot product
 *   and prints results via UART
 *
 */
void	test_13(void) {
	static	float		vecA[VECTOR_SIZE];
	static	float		vecB[VECTOR_SIZE];
			char_t		ascii[16];
			uint32_t	start, end, scalarCycles;
	volatile	float	result;

	cmns_init();
	local_sysTick_init();

// Initialise test vectors with known values

	for (uint32_t i = 0u; i < VECTOR_SIZE; i++) {
		vecA[i] = (float)(i + 1u);
		vecB[i] = (float)(i + 1u);
	}

	while (true) {
		cmns_send(KURT0, "\n--- MVE dot product benchmark (N=1024) ---\n");

// Measure scalar dot product

		start  = local_sysTick_read();
		result = scalar_dot_f32(vecA, vecB, VECTOR_SIZE);
		end    = local_sysTick_read();

		scalarCycles = SYSTICK_ELAPSED(start, end);

		cmns_send(KURT0, "Scalar: ");
		debug_cnvtValInt32ToDecAscii(ascii, (const int32_t *)&scalarCycles);
		cmns_send(KURT0, ascii);
		cmns_send(KURT0, " cycles, result: ");
		{
			int32_t	intResult = (int32_t)result;
			debug_cnvtValInt32ToDecAscii(ascii, &intResult);
		}
		cmns_send(KURT0, ascii);
		cmns_send(KURT0, "\n");

// Measure MVE dot product (when available)

		#if (HAVE_MVE)
		{
			uint32_t	mveCycles;

			start  = local_sysTick_read();
			result = mve_dot_f32(vecA, vecB, VECTOR_SIZE);
			end    = local_sysTick_read();

			mveCycles = SYSTICK_ELAPSED(start, end);

			cmns_send(KURT0, "MVE:    ");
			debug_cnvtValInt32ToDecAscii(ascii, (const int32_t *)&mveCycles);
			cmns_send(KURT0, ascii);
			cmns_send(KURT0, " cycles, result: ");
			{
				int32_t	intResult = (int32_t)result;
				debug_cnvtValInt32ToDecAscii(ascii, &intResult);
			}
			cmns_send(KURT0, ascii);
			cmns_send(KURT0, "\n");

			cmns_send(KURT0, "Speedup: ");
			if (mveCycles > 0u) {
				uint32_t	ratio10 = (scalarCycles * 10u) / mveCycles;
				uint32_t	whole   = ratio10 / 10u;
				uint32_t	frac    = ratio10 % 10u;
				debug_cnvtValInt32ToDecAscii(ascii, (const int32_t *)&whole);
				cmns_send(KURT0, ascii);
				cmns_send(KURT0, ".");
				debug_cnvtValInt32ToDecAscii(ascii, (const int32_t *)&frac);
				cmns_send(KURT0, ascii);
			}
			else {
				cmns_send(KURT0, "?");
			}
			cmns_send(KURT0, "x\n");
		}

		#else
		cmns_send(KURT0, "MVE:    not available (compiled without Helium)\n");
		#endif

		LED_GREEN_TOGGLE;
		cmns_wait(BENCH_PAUSE);
	}
}
#endif
