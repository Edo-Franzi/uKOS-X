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

#pragma	once

/*!
 * \addtogroup Lib_neurals
 */
/**@{*/

/*!
 * \defgroup mlpn Mlpn
 *
 * \brief Mlpn
 *
 * Mlpn management
 *
 * @{
 */

// Configuration structure
// -----------------------

typedef	struct	mlpnNetwork		mlpnNetwork_t;
typedef	struct	mlpnLayer		mlpnLayer_t;

struct mlpnNetwork {
			uint32_t		oNBLayer;							// Number of layers
			mlpnLayer_t		*oLayer_L1;							// Ptr on the layer 1
			mlpnLayer_t		*oLayer_L2;							// Ptr on the layer 2
			mlpnLayer_t		*oLayer_L3;							// Ptr on the layer 3
			mlpnLayer_t		*oLayer_L4;							// Ptr on the layer 4
			mlpnLayer_t		*oLayer_L5;							// Ptr on the layer 5
};

struct mlpnLayer {
			uint32_t		oNonLinear;							// Non linear function
			uint32_t		oNBInput;							// Number of inputs
			uint32_t		oNBOutput;							// Number of outputs
			float32_t		*oInput;							// Ptr on the input vector
			float32_t		*oActivation;						// Ptr on the activation vector
			float32_t		*oOutput;							// Ptr on the output vector
	const	float32_t		*oWeight;							// Ptr on the weight matrix
};

// Non linear (oNonLinear)

enum {
			KMLPN_TAN0 = 0u,									// libm tanh
			KMLPN_TAN1,											// Lambert's tanh approximation
			KMLPN_TAN2,											// Ultrafast tanh approximation (~2% precision)
			KMLPN_TAN3,											// Fastest tanh approximation (less precise)
			KMLPN_RELU,											// Ultrafast relu
			KMLPN_LINE,											// Ultrafast linear
			KMLPN_SMAX,											// Ultrafast softmax
};

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
 * \brief Configure the mlpn manager
 *
 * Call example in C:
 *
 * \code{.c}
 * // Layer 1
 *
 * #define    KL1_NB_IN    (3 + 1)            // 3 inputs + the bias
 * #define    KL1_NB_OUT   5                  // 5 outputs
 *
 * static                  float32_t          vInput_L1[KL1_NB_IN];
 * static                  float32_t          vActivation_L1[KL1_NB_OUT];
 * static                  float32_t          vOutput_L1[KL1_NB_OUT + 1];
 * static     const        float32_t          vWeight_L1[KL1_NB_OUT][KL1_NB_IN] = {
 *                                                { -0.7654f, 1.3442f, 4,6543f,  3,1234f },
 *                                                { 0.2654f, -5.3442f, 1,6543f,  8,1234f },
 *                                                { 0.3654f,  6.3442f, -2,6543f, 7,1234f },
 *                                                { 0.4654f, -7.3442f, 6,6543f,  3,1234f },
 *                                                { 05654f,  -6.3442f, 4,6543f,  1,1234f }
 *                                            };
 *
 * static     const        mlpnLayer_t       aLayer_L1 = {
 *                                                KL1_NB_IN,
 *                                                KL1_NB_OUT,
 *                                                &vInput_L1[0],
 *                                                &vActivation_L1[0],
 *                                                &vOutput_L1[0],
 *                                                &vWeight_L1[0][0]
 *                                            };
 *
 * // Layer 2
 *
 * #define    KL2_NB_IN    (KL1_NB_OUT + 1)   // 5 inputs + the bias
 * #define    KL1_NB_OUT   2                  // 2 outputs
 *
 * static                  float32_t          vActivation_L2[KL1_NB_OUT];
 * static                  float32_t          vOutput_L2[KL1_NB_OUT + 1];
 * static     const        float32_t          vWeight_L2[KL1_NB_OUT][KL2_NB_IN] = {
 *                                                { -0.3654f, 6.3442f },
 *                                                { 0.4654f,  7.3432f },
 *                                                { 0.3654f,  9.3482f },
 *                                                { 0.4654f,  8.3442f },
 *                                                { 0.5684f,  3.3472f },
 *                                                { 0.0654f,  2.3442f },
 *                                            };
 *
 * static     const        mlpnLayer_t       aLayer_L2 = {
 *                                                KL2_NB_IN,
 *                                                KL1_NB_OUT,
 *                                                &vOutput_L1[0],
 *                                                &vActivation_L2[0],
 *                                                &vOutput_L2[0],
 *                                                &vWeight_L2[0][0]
 *                                            };
 *
 * // The full network
 *
 * #define    KNB_LAYERS   2                  // 2 layers
 *
 * static     const        mlpnNetwork_t    aNetwork = {
 *                                               KNB_LAYERS,
 *                                               &aLayer_L1,
 *                                               &aLayer_L2,
 *                                               nullptr,
 *                                               nullptr,
 *                                               nullptr
 *                                           };
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
extern	int32_t	mlpn_configure(const mlpnNetwork_t *network);

/*!
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
extern	int32_t	mlpn_compute(const mlpnNetwork_t *network);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
