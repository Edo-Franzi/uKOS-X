/*
; mlpn.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		mlpn manager.
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
#include	<math.h>
#include	<stdint.h>

// __ARM_FEATURE_MVE Bit 0 indicates whether Helium integer instructions are available
// __ARM_FEATURE_MVE Bit 1 indicates whether Helium floating-point instructions are available
//
// 0 indicates that Helium is not available
// 1 indicates that only the Helium integer intrinsics are available
// 3 indicates that both the Helium integer and floating-point intrinsics are available

#if	((defined(__ARM_FEATURE_MVE)) && (__ARM_FEATURE_MVE == 2))
#include	<arm_mve.h>
#endif

#if (defined(CONFIG_MAN_MLPN_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"mlpn         mlpn manager.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "mlpn manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Mlpn,							// Module name (the first letter has to be upper case)
	KID_FAM_NEURALS,				// Family (defined in the module.h)
	KNUM_MLPN,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

#define	KMLPN_BIAS	1.0f			// bias

// Prototypes

static	float32_t	local_nonLinear_tan0(float32_t p);
static	float32_t	local_nonLinear_tan1(float32_t p);
static	float32_t	local_nonLinear_tan2(float32_t p);
static	int32_t		local_init(void);
static	int32_t		local_computeLayer(mlpnLayer_t *layer);
static	int32_t		local_initialiseLayer(mlpnLayer_t *layer);

/*
 * \brief Configure the mlpn manager
 *
 * Call example in C:
 *
 * \code{.c}
 * // Layer 1
 *
 * #define    KMLPN_L1_NB_IN     (3 + 1)                  // 3 inputs + the bias
 * #define    KMLPN_L1_NB_OUT    5                        // 5 outputs
 *
 * static                  float32_t          vInput_L1[KMLPN_L1_NB_IN];
 * static                  float32_t          vActivation_L1[KMLPN_L1_NB_OUT];
 * static                  float32_t          vOutput_L1[KMLPN_L1_NB_OUT + 1];
 * static     const        float32_t          vWeight_L1[KMLPN_L1_NB_OUT][KMLPN_L1_NB_IN] = {
 *                                                { -0.7654f, 1.3442f, 4,6543f,  3,1234f },
 *                                                { 0.2654f, -5.3442f, 1,6543f,  8,1234f },
 *                                                { 0.3654f,  6.3442f, -2,6543f, 7,1234f },
 *                                                { 0.4654f, -7.3442f, 6,6543f,  3,1234f },
 *                                                { 05654f,  -6.3442f, 4,6543f,  1,1234f }
 *                                            };
 *
 * static     const        mlpnLayer_t       aLayer_L1 = {
 *                                                KMLPN_TAN0,
 *                                                KMLPN_L1_NB_IN,
 *                                                KMLPN_L1_NB_OUT,
 *                                                &vInput_L1[0],
 *                                                &vActivation_L1[0],
 *                                                &vOutput_L1[0],
 *                                                &vWeight_L1[0][0]
 *                                            };
 *
 * // Layer 2
 *
 * #define    KMLPN_L2_NB_IN     (KMLPN_L1_NB_OUT + 1)    // 5 inputs + the bias
 * #define    KMLPN_L1_NB_OUT    2                        // 2 outputs
 *
 * static                  float32_t          vActivation_L2[KMLPN_L1_NB_OUT];
 * static                  float32_t          vOutput_L2[KMLPN_L1_NB_OUT + 1];
 * static     const        float32_t          vWeight_L2[KMLPN_L1_NB_OUT][KMLPN_L2_NB_IN] = {
 *                                                { -0.3654f, 6.3442f },
 *                                                { 0.4654f,  7.3432f },
 *                                                { 0.3654f,  9.3482f },
 *                                                { 0.4654f,  8.3442f },
 *                                                { 0.5684f,  3.3472f },
 *                                                { 0.0654f,  2.3442f },
 *                                            };
 *
 * static     const        mlpnLayer_t       aLayer_L2 = {
 *                                                KMLPN_TAN0,
 *                                                KMLPN_L2_NB_IN,
 *                                                KMLPN_L1_NB_OUT,
 *                                                &vOutput_L1[0],
 *                                                &vActivation_L2[0],
 *                                                &vOutput_L2[0],
 *                                                &vWeight_L2[0][0]
 *                                            };
 *
 * // The full network
 *
 * #define    KMLPN_NB_LAYERS    2                        // 2 layers
 *
 * static     const        mlpnNetwork_t     aNetwork = {
 *                                               KMLPN_NB_LAYERS,
 *                                               &aLayer_L1,
 *                                               &aLayer_L2,
 *                                               nullptr,
 *                                               nullptr,
 *                                               nullptr
 *                                            };
 *
 *    status = mlpn_configure(&aNetwork);
 *
 * }
 * \endcode
 *
 * \param[in]	*network		Ptr on the network description
 * \return		KERR_MLPN_NOERR	OK
 * \return		KERR_MLPN_GEERR	General error
 * \return		KERR_MLPN_NOMEM	Not enough memory
 *
 */
int32_t	mlpn_configure(const mlpnNetwork_t *network) {
	int32_t		status;

	status = local_init();
	if (status != KERR_MLPN_NOERR) { return (status); }

// Initialise all the layers

	switch (network->oNBLayer) {
		case 1u: {
			if (network->oLayer_L1 == nullptr) { return (KERR_MLPN_GEERR); }
			local_initialiseLayer(network->oLayer_L1);
			break;
		}
		case 2u: {
			if (network->oLayer_L1 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L2 == nullptr) { return (KERR_MLPN_GEERR); }
			local_initialiseLayer(network->oLayer_L1);
			local_initialiseLayer(network->oLayer_L2);
			break;
		}
		case 3u: {
			if (network->oLayer_L1 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L2 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L3 == nullptr) { return (KERR_MLPN_GEERR); }
			local_initialiseLayer(network->oLayer_L1);
			local_initialiseLayer(network->oLayer_L2);
			local_initialiseLayer(network->oLayer_L3);
			break;
		}
		case 4u: {
			if (network->oLayer_L1 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L2 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L3 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L4 == nullptr) { return (KERR_MLPN_GEERR); }
			local_initialiseLayer(network->oLayer_L1);
			local_initialiseLayer(network->oLayer_L2);
			local_initialiseLayer(network->oLayer_L3);
			local_initialiseLayer(network->oLayer_L4);
			break;
		}
		case 5u: {
			if (network->oLayer_L1 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L2 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L3 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L4 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L5 == nullptr) { return (KERR_MLPN_GEERR); }
			local_initialiseLayer(network->oLayer_L1);
			local_initialiseLayer(network->oLayer_L2);
			local_initialiseLayer(network->oLayer_L3);
			local_initialiseLayer(network->oLayer_L4);
			local_initialiseLayer(network->oLayer_L5);
			break;
		}
		default: { return (KERR_MLPN_GEERR); }
	}

	return (status);
}

/*
 * \brief Compute the network
 *
 * Call example in C:
 *
 * \code{.c}
 * // Compute the network
 *
 * vInput_L1[0] = accelerationX;
 * vInput_L1[1] = accelerationY;
 * vInput_L1[2] = accelerationZ;
 *
 *    status = mlpn_compute(&aNetwork);
 *
 *    (void)dprintf(KSYST, "Activation %3ld.%03ld %3ld.%03ld, Output %3ld.%03ld %3ld.%03ld\n", FLOAT_3(vActivation_L2[0]),
 *                                                                                             FLOAT_3(Activation_L2[1]),
 *                                                                                             FLOAT_3(vOutput_L2[0]),
 *                                                                                             FLOAT_3(vOutput_L2[1]));
 *
 * }
 * \endcode
 *
 * \param[in]	*network		Ptr on the network description
 * \return		KERR_MLPN_NOERR	OK
 * \return		KERR_MLPN_GEERR	General error
 *
 */
int32_t	mlpn_compute(const mlpnNetwork_t *network) {
	int32_t		status;

	status = local_init();
	if (status != KERR_MLPN_NOERR) { return (status); }

// Compute all the layers

	switch (network->oNBLayer) {
		case 1u: {
			if (network->oLayer_L1 == nullptr) { return (KERR_MLPN_GEERR); }
			local_computeLayer(network->oLayer_L1);
			break;
		}
		case 2u: {
			if (network->oLayer_L1 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L2 == nullptr) { return (KERR_MLPN_GEERR); }
			local_computeLayer(network->oLayer_L1);
			local_computeLayer(network->oLayer_L2);
			break;
		}
		case 3u: {
			if (network->oLayer_L1 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L2 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L3 == nullptr) { return (KERR_MLPN_GEERR); }
			local_computeLayer(network->oLayer_L1);
			local_computeLayer(network->oLayer_L2);
			local_computeLayer(network->oLayer_L3);
			break;
		}
		case 4u: {
			if (network->oLayer_L1 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L2 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L3 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L4 == nullptr) { return (KERR_MLPN_GEERR); }
			local_computeLayer(network->oLayer_L1);
			local_computeLayer(network->oLayer_L2);
			local_computeLayer(network->oLayer_L3);
			local_computeLayer(network->oLayer_L4);
			break;
		}
		case 5u: {
			if (network->oLayer_L1 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L2 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L3 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L4 == nullptr) { return (KERR_MLPN_GEERR); }
			if (network->oLayer_L5 == nullptr) { return (KERR_MLPN_GEERR); }
			local_computeLayer(network->oLayer_L1);
			local_computeLayer(network->oLayer_L2);
			local_computeLayer(network->oLayer_L3);
			local_computeLayer(network->oLayer_L4);
			local_computeLayer(network->oLayer_L5);
			break;
		}
		default: { return (KERR_MLPN_GEERR); }
	}
	return (KERR_MLPN_NOERR);
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static	int32_t	local_init(void) {
			int32_t		status = KERR_MLPN_NOERR;
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

	}
	RETURN_INT_RESTORE(status);
}

/*
 * \brief local_initialiseLayer
 *
 * - This function initialise a full NN layer
 *
 */
static	int32_t	local_initialiseLayer(mlpnLayer_t *layer) {

	layer->oInput[layer->oNBInput - 1u] = KMLPN_BIAS;
	return (KERR_MLPN_NOERR);
}

/*
 * \brief local_computeLayer
 *
 * - This function compute a full NN layer
 *   !!! The layer computing is limited to :
 *   	 16536 number of inputs
 *   	 16536 number of outputs
 *
 *   y = f(W . x)
 *
 */

// Dot product: Helium FP (MVE) if available (with unroll x2 (8 floats per iteration))

#if	((defined(__ARM_FEATURE_MVE)) && (__ARM_FEATURE_MVE == 2))
static	inline	float32_t	local_hadd_f32x4(float32x4_t v) {
	float32_t	tmp[4];

	vstrwq_f32(tmp, v);
	return (tmp[0] + tmp[1] + tmp[2] + tmp[3]);
}
#endif

static	inline	float32_t	local_dot_f32(const float32_t * __restrict w, const float32_t * __restrict x, uint16_t n) {

	#if	((defined(__ARM_FEATURE_MVE)) && (__ARM_FEATURE_MVE == 2))
    float32x4_t		acc0 = vdupq_n_f32(0.0f);
    float32x4_t		acc1 = vdupq_n_f32(0.0f);
    uint16_t		i = 0u, rem;

	w = (const float32_t *)__builtin_assume_aligned(w, 16);
	x = (const float32_t *)__builtin_assume_aligned(x, 16);

// 8 floats per iteration

	for (i = 0u; (uint16_t)(i + 8u) <= n; i = (uint16_t)(i + 8u)) {
		float32x4_t		w0 = vldrwq_f32(&w[i + 0u]);
		float32x4_t		x0 = vldrwq_f32(&x[i + 0u]);
		acc0 = vfmaq_f32(acc0, w0, x0);

		float32x4_t		w1 = vldrwq_f32(&w[i + 4u]);
		float32x4_t		x1 = vldrwq_f32(&x[i + 4u]);
		acc1 = vfmaq_f32(acc1, w1, x1);
    }

// Remaining: 0..7 floats, managed in 2 predictive blocs of 4

	rem = (uint16_t)(n - i);
    if (rem != 0u) {

// bloc 0..3

		mve_pred16_t	p0 = vctp32q((uint32_t)rem);
		float32x4_t		wR0 = vldrwq_z_f32(&w[i], p0);
		float32x4_t		xR0 = vldrwq_z_f32(&x[i], p0);

		acc0 = vfmaq_m_f32(acc0, wR0, xR0, p0);

// bloc 4..7 (if rem > 4)

		if (rem > 4u) {
			mve_pred16_t	p1 = vctp32q((uint32_t)(rem - 4u));
			float32x4_t		wR1 = vldrwq_z_f32(&w[i + 4u], p1);
			float32x4_t		xR1 = vldrwq_z_f32(&x[i + 4u], p1);

			acc1 = vfmaq_m_f32(acc1, wR1, xR1, p1);
		}
	}

// Reduction

	return (local_hadd_f32x4(vaddq_f32(acc0, acc1)));

	#else
	float32_t	p = 0.0f;
	uint16_t	i;

	for (i = 0u; i < n; i++) {
		p += w[i] * x[i];
	}
    return (p);
	#endif

}

#if (defined(__clang__))
static int32_t local_computeLayer(mlpnLayer_t *layer) {

#else
static __attribute__ ((optimize("O3,inline,aggressive-loop-optimizations,unroll-loops"))) int32_t local_computeLayer(mlpnLayer_t *layer) {
#endif
			uint16_t	j, nbInput, nbOutput;
			float32_t	p, *y;
			float32_t	(*nonLinear)(float32_t p);
	const	float32_t	*x, *w;


	x		  = &layer->oInput[0];
	w		  = &layer->oWeight[0];
	y		  = &layer->oOutput[0];
	nbInput	  = (uint16_t)layer->oNBInput;
	nbOutput  = (uint16_t)layer->oNBOutput;

	switch (layer->oNonLinear) {
		default:
		case KMLPN_TAN0: {
			nonLinear = local_nonLinear_tan0;
			break;
		}
		case KMLPN_TAN1: {
			nonLinear = local_nonLinear_tan1;
			break;
		}
		case KMLPN_TAN2: {
			nonLinear = local_nonLinear_tan2;
			break;
		}
	}

// For all the neurons

	for (j = 0u; j < nbOutput; j++) {

// For one neuron compute the activation
// Activation = Matrix - vector multiplication (Wi . xi)
// Output = non-linear f(Activation)

		p = local_dot_f32(w, x, nbInput);
		y[j] = nonLinear(p);

// Next neuron, next weight set

		w = &w[nbInput];
	}
	return (KERR_MLPN_NOERR);
}

/*
 * \brief local_nonLinear_tan0
 *
 * - This is the libm tanh function
 *
 */
static	float32_t	local_nonLinear_tan0(float32_t p) {

	return (tanhf(p));
}

/*
 * \brief local_nonLinear_tan1
 *
 * - This is a fast approximation of the tanh function
 *
 *   The approximation is based on the Lambert's continued factions
 *
 *                        x
 *   tanh(x) ~= ------------------------
 *                          x^2
 *              1 + --------------------
 *                            x^2
 *                  3 + ----------------
 *                              x^2
 *                      5 + ------------
 *                                x^2
 *                          7 + --------
 *                          ............
 *
 *   If we consider only 7 division, we can rewrite in this way
 *
 *           x^7 + 378 x^5 + 17325 x^3 + 135135 x        a
 *   tanh ~= --------------------------------------   = ---
 *           28 x^6 + 3150 x 4 + 62370 x^2 + 135135      b
 *
 *      a  = (((x^2 + 378) x^2 + 17325) x^2 + 135135) x
 *      b  = ((28 x^2 + 3150) x^2 + 62370) x^2 + 135135
 *
 */
static	float32_t	local_nonLinear_tan1(float32_t p) {
	float32_t	s, a, b;

	if (p < -3.0f) { return (-1.0f); }
	if (p > +3.0f) { return (+1.0f); }
	s = p * p;
	a = (((((s + 378.0f) * s) + 17325.0f) * s) + 135135.0f) * p;
	b = (((((28.0f * s) + 3150.0f) * s) + 62370.0f) * s) + 135135.0f;
	return (a / b);
}

/*
 * \brief local_nonLinear_tan2
 *
 * - This is a very fast linear approximation of the tanh function
 *
 *   tanh(p) = -1, if p <= -1
 *   tanh(p) = +1, if p >= +1
 *   tanh(p) =  p, if (p > -1) && (p < +1)
 *
 */
static	float32_t	local_nonLinear_tan2(float32_t p) {

	if (p <= -1.0f) { return (-1.0f); }
	if (p >= +1.0f) { return (+1.0f); }
	return (p);
}

#endif
