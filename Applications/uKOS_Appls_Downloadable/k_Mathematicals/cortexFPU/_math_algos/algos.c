/*
; pi.
; ===

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
;
;			Compute Pi with the Lambert & Spigot series:
;
;			- Lambert algorithm:
;			- Pi = sqrt(6 * (1/1^2 + 1/2^2 + 1/3^2 +...)
;
;			- Spigot algorithm:
;			- Pi = Sum 1/16^^n * (4/(8n + 1) - 2/(8n + 4) - 1/(8n + 5) - 1/(8n + 6))
;
;   (c) 2025-20xx, Edo. Franzi
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
#include	<math.h>

/*
 * \brief pi_lambert
 *
 * - Lambert algorithm:
 *	- Pi = sqrt(6 * (1/1^2 + 1/2^2 + 1/3^2 +...)
 *
 */
float64_t	pi_lambert(float64_t index, float32_t oldPi) {
			float64_t	pi;
	static	float64_t	v = 0.0;

	UNUSED(oldPi);

	v = v + (1.0 / pow(index, 2));
	pi = sqrt(v * 6);
	return (pi);
}

/*
 * \brief pi_spigot
 *
 * - Spigot algorithm:
 *	- Pi = Sum 1/16^^n * (4/(8n + 1) - 2/(8n + 4) - 1/(8n + 5) - 1/(8n + 6))
 *
 */
float64_t	pi_spigot(float64_t index, float64_t oldPi) {
	float64_t	pi;

	pi = oldPi + ((1.0 / pow(16, index)) * ((4.0 / ((8.0 * index) + 1.0)))
			   - (2.0 / ((8.0 * index) + 4.0))
			   - (1.0 / ((8.0 * index) + 5.0))
			   - (1.0 / ((8.0 * index) + 6.0)));

	return (pi);
}
