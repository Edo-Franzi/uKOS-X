/*
; nnh_classifier.
; ===============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			Hardware classifier.
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
#include	"ui.h"
#include	"nn.h"
#include	<stdlib.h>
#include	<math.h>

#if (defined(USE_NN_HARDWARE))
#include	"libNN_Hardware.h"

static	int8_t	vInput[KNN_INPUT_SIZE];
static	int8_t	vOutput[KNN_OUTPUT_SIZE];

// Prototypes

void	ui_drawNPUExecutionTime(const char_t *s);

/*
 * \brief nnh_init
 *
 * - Initialise the used resources
 *
 */
void	nnh_init(void) {

	nn_hardware_init();
}

/*
 * \brief nnh_classify
 *
 * - Classify a data vector
 *
 */
void	nnh_classify(float32_t *entry, uint8_t *face) {
	uint64_t	time[2];
	int32_t		q;
	uint32_t	i, delta = 0u;
	char_t		text[40];

// Prepare the inputs

	for (i = 0u; i < KNN_INPUT_SIZE; i++) {

// !!! Value extracted from the .tflite file

	#define	KSCALE	0.03315797075629234f
	#define	KZERO	-13
	
		q = (int32_t)roundf(entry[i] / KSCALE) + KZERO;

		if (q < -128) { q = -128; }
		if (q >  127) { q =  127; }

		vInput[i] = (int8_t)q;
	}

	nn_hardware_putInput(vInput);

	kern_readTickCount(&time[0]);
	nn_hardware_inference();
	kern_readTickCount(&time[1]);
	delta = (uint32_t)(time[1] - time[0]);

// Return the face

	nn_hardware_getOutput(vOutput);

	for (i = 0u; i < KNN_OUTPUT_SIZE; i++) {
		face[i] = (uint8_t)(vOutput[i] + 128);
	}

	(void)snprintf(text, sizeof(text), "NPU Ex. time: %" PRIu32 " [ms]", (delta / 1000));
	ui_drawNPUExecutionTime(text);
}
#endif
