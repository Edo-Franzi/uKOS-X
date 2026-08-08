/*
; libNN_Hardware.
; ===============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			Minimal libNN_Hardware interface with the ST library
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

#include	"libNN_Hardware.h"
#include	"stai_network.h"
#include	"npu_cache.h"
#include	<stdbool.h>
#include	<stddef.h>
#include	<stdint.h>
#include	<string.h>

#if (STAI_NETWORK_IN_NUM != 1)
#error "libNN_NPU supports exactly one network input"
#endif

#if (STAI_NETWORK_OUT_NUM != 1)
#error "libNN_NPU supports exactly one network output"
#endif

// The ST.AI context is opaque. ST provides its required size and alignment

_Alignas(STAI_NETWORK_CONTEXT_ALIGNMENT)

static	uint8_t			vNetwork_storage[STAI_NETWORK_CONTEXT_SIZE];
static	stai_network	*const	vNetwork = (stai_network *)(void *)vNetwork_storage;
static	stai_ptr		vInputs[STAI_NETWORK_IN_NUM];
static	stai_ptr		vOutputs[STAI_NETWORK_OUT_NUM];

static	bool			vInit;
static	bool			vInputReady;
static	bool			vOutputReady;

/*
 * \brief Initialise the library
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = nn_hardware_init();
 * \endcode
 *
 * \param[in]	-
 * \return		NN_HARDWARE_OK			OK
 * \return		NN_HARDWARE_ERUNTIME	Runtime error
 *
 */
int32_t	nn_hardware_init(void) {
	stai_return_code	status;
	stai_size			nbInputs  = 0u;
	stai_size			nbOutputs = 0u;

	if (vInit == true) {
		return (NN_HARDWARE_OK);
	}

	memset(vNetwork_storage, 0, sizeof(vNetwork_storage));
	npu_cache_enable();

	status = stai_runtime_init();
	if (status != STAI_SUCCESS) {
		return (NN_HARDWARE_ERUNTIME);
	}

	status = stai_network_init(vNetwork);
	if (status != STAI_SUCCESS) {
		return (NN_HARDWARE_ERUNTIME);
	}

	status = stai_network_get_inputs(vNetwork, vInputs, &nbInputs);
	if ((status != STAI_SUCCESS) || (nbInputs != STAI_NETWORK_IN_NUM) || (vInputs[0] == nullptr)) {
		return (NN_HARDWARE_ERUNTIME);
	}

	status = stai_network_get_outputs(vNetwork, vOutputs, &nbOutputs);
	if ((status != STAI_SUCCESS) || (nbOutputs != STAI_NETWORK_OUT_NUM) || (vOutputs[0] == nullptr)) {
		return (NN_HARDWARE_ERUNTIME);
	}

	vInputReady  = false;
	vOutputReady = false;
	vInit  = true;
	return (NN_HARDWARE_OK);
}

/*
 * \brief De-initialise the library
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = nn_hardware_deinit();
 * \endcode
 *
 * \param[in]	-
 * \return		NN_HARDWARE_OK			OK
 * \return		NN_HARDWARE_ESTATE		Not initialised
 * \return		NN_HARDWARE_ERUNTIME	Runtime error
 *
 */
int32_t	nn_hardware_deinit(void) {
	stai_return_code	status;

	if (vInit == false) {
		return (NN_HARDWARE_ESTATE);
	}

	status = stai_network_deinit(vNetwork);
	if (status != STAI_SUCCESS) {
		return (NN_HARDWARE_ERUNTIME);
	}

	memset(vNetwork_storage, 0, sizeof(vNetwork_storage));
	memset(vInputs, 0, sizeof(vInputs));
	memset(vOutputs, 0, sizeof(vOutputs));

	vInit  = false;
	vInputReady  = false;
	vOutputReady = false;
	return (NN_HARDWARE_OK);
}

/*
 * \brief Set the input vector
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 * const    int8_t     input[64] = { ... };
 *
 *    status = nn_hardware_putInput(input);
 * \endcode
 *
 * \param[in]	-
 * \return		NN_HARDWARE_OK		OK
 * \return		NN_HARDWARE_EINVAL	No valid input vector
 * \return		NN_HARDWARE_ESTATE	Not initialised
 *
 */
int32_t	nn_hardware_putInput(const int8_t *input) {

	if (input == nullptr) {
		return (NN_HARDWARE_EINVAL);
	}

	if ((vInit == false) || (vInputs[0] == nullptr)) {
		return (NN_HARDWARE_ESTATE);
	}

	memcpy(vInputs[0], input, STAI_NETWORK_IN_1_SIZE_BYTES);

	vInputReady  = true;
	vOutputReady = false;
	return (NN_HARDWARE_OK);
}

/*
 * \brief Compute an inference
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = nn_hardware_inference();
 * \endcode
 *
 * \param[in]	-
 * \return		NN_HARDWARE_OK			OK
 * \return		NN_HARDWARE_ESTATE		Not initialised
 * \return		NN_HARDWARE_ERUNTIME	Runtime error
 *
 */
int32_t	nn_hardware_inference(void) {
	stai_return_code	status;

	vOutputReady = false;

	if ((vInit == false) || (vInputReady == false)) {
		return (NN_HARDWARE_ESTATE);
	}

	status = stai_network_run(vNetwork, STAI_MODE_SYNC);
	if (status != STAI_SUCCESS) {
		return (NN_HARDWARE_ERUNTIME);
	}

	vInputReady  = false;
	vOutputReady = true;
	return (NN_HARDWARE_OK);
}

/*
 * \brief Set the output vector
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * int8_t     output[4096];
 *
 *    status = nn_hardware_getOutput(output);
 * \endcode
 *
 * \param[in]	-
 * \return		NN_HARDWARE_OK		OK
 * \return		NN_HARDWARE_EINVAL	No valid input vector
 * \return		NN_HARDWARE_ESTATE	Not initialised
 *
 */
int32_t	nn_hardware_getOutput(int8_t *output) {

	if (output == nullptr) {
		return (NN_HARDWARE_EINVAL);
	}

	if ((vInit == false) || (vOutputs[0] == nullptr) || (vOutputReady == false)) {
		return (NN_HARDWARE_ESTATE);
	}

	memcpy(output, vOutputs[0], STAI_NETWORK_OUT_1_SIZE_BYTES);
	vOutputReady = false;
	return (NN_HARDWARE_OK);
}
