/*
; preciseSignals.
; ===============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Precise signals.
;
;			This module implements the software primitives.
;
; 			Precise signal system calls
; 			---------------------------
;
;			void	preciseSignals_init(void);
;			int32_t	kern_createPreciseSignal(const char_t *identifier, prcs_t **handle);
;			int32_t	kern_setPreciseSignal(prcs_t *handle, sign_t **sigGroup, proc_t *toProcess, uint64_t period, uint8_t mode, uint32_t signal);
;			int32_t	kern_killPreciseSignal(prcs_t *handle);
;			int32_t	kern_getPreciseSignalById(const char_t *identifier, prcs_t **handle);
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

#if (KKERN_NB_PRECISE_SIGNALS > 0)

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup preciseSignals PreciseSignals
 *
 * \brief Precise signals
 *
 * Precise signal management
 *
 * @{
 */

// Structure of the precise signal specification
// ---------------------------------------------

struct prcs {
	const	char_t		*oIdentifier;							// Ptr on the process identifier
			uint16_t	oState;									// Precise signal state
			#define		BPRCS_INSTALLED		0u					// Precise signal installed

			uint8_t		oMode;									// Mode
			sign_t		*oSignalGroup;							// Ptr on the signal group handle
			proc_t		*oToProcess;							// Ptr on the process handle (selective signal)
			uint32_t	oSignal;								// Precise signal signal
			uint64_t	oPeriod;								// Precise signal period
			uint64_t	oNextTime;								// Precise signal next absolute time
};

// Mode

enum {
			KPRCS_STOP = 0u,									// Stop the execution of the precise signal
			KPRCS_SINGLE_SHOT,									// Single shot precise signal (with start)
			KPRCS_CONTINUOUS									// Continuous precise signal (with start)
};

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	void	preciseSignals_init(void);

/*!
 * \brief Create a precise signal
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          prcs_t     *preciseSignal;
 * const    char_t     identifier[] = ”Top acquisition”;
 *
 *    status = kern_createPreciseSignal(identifier, &preciseSignal);
 * \endcode
 *
 * \param[in]	*identifier		Ptr on the precise signal identifier (nullptr = anonymous)
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_PRFUL	No more precise signal
 * \return		KERR_KERN_IDPRC	The precise signal identifier is already used
 *
 */
extern	int32_t	kern_createPreciseSignal(const char_t *identifier, prcs_t **handle);

/*!
 * \brief Set a precise signal
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KTOPACQ    (1u<<0) | (1u<<28)
 *
 *    static  void     aProcess(const void *argument) {
 *        uint32_t     signal;
 *        prcs_t       *preciseSignal;
 *        proc_t       *process23;
 *        sign_t       *oSignalGroup = nullptr;
 *
 *        // In this example the "signal" is hard-coded. The user can also use the
 *        // system call kern_createBitSignal to automatically obtain a signal.
 *        //
 *        // Create and initialise a precise signal "Test_prcs"
 *        //     Continuous run, period = 200-us, generate the signals (1u<<0) | (1u<<28) on the default signal group, selectively to the process 23
 *
 *        if (kern_createPreciseSignal("Test_prcs", &preciseSignal)                                         != KERR_KERN_NOERR) { exit(EXIT_OS_FAILURE); }
 *        if (kern_setPreciseSignal(preciseSignal, &signalGroup, process23, 200, KPRCS_CONTINUOUS, KTOPACQ) != KERR_KERN_NOERR) { exit(EXIT_OS_FAILURE); }
 *
 *        while (true) {
 *
 *        // Waiting for the signal (1u<<0) coming from the ISR (always the case)
 *
 *            signal = (1u<<0);
 *            kern_waitSignal(signalGroup, &signal, KKERN_HANDLE_FROM_ISR, KWAIT_INFINITY);
 *            led_toggle(KLED_0);
 *        }
 *    }
 * \endcode
 *
 * \param[in]		*handle			Ptr on the handle
 * \param[in, out]	**sigGroup		Ptr on the sigGroup handle. Set variable to nullptr for the default group
 * \param[in]		*toProcess		Ptr on the process handle (selective signal)
 * \param[in]		-				KKERN_HANDLE_BROADCAST, broadcast to all the installed processes the signals
 * \param[in]		period			Time period in us
 * \param[in]		mode			KPRCS_STOP			-> stop the ongoing timer
 * \param[in]		-				KPRCS_SINGLE_SHOT	-> single shot timer
 * \param[in]		-				KPRCS_CONTINUOUS	-> continuous timer
 * \param[in]		signal			Signal(s) to generate
 * \return			KERR_KERN_NOERR	OK
 * \return			KERR_KERN_NOPRC	The precise signal does not exist
 *
 */
extern	int32_t	kern_setPreciseSignal(prcs_t *handle, sign_t **sigGroup, proc_t *toProcess, uint64_t period, uint8_t mode, uint32_t signal);

/*!
 * \brief Kill the precise signal
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * prcs_t     *preciseSignal;
 *
 *    status = kern_killPreciseSignal(preciseSignal);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRC	The precise signal does not exist
 *
 */
extern	int32_t	kern_killPreciseSignal(prcs_t *handle);

/*!
 * \brief Get the handle of a precise signal by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          prcs_t     *preciseSignal;
 * const    char_t     identifier[] = ”Top acquisition”;
 *
 *    status = kern_getPreciseSignalById(identifier, &softwareTimer);
 * \endcode
 *
 * - This function returns the handle of the precise signal
 *
 * \param[in]	*identifier		Ptr on the precise signal identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRC	The precise signal does not exist
 *
 */
extern	int32_t	kern_getPreciseSignalById(const char_t *identifier, prcs_t **handle);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/

#endif
