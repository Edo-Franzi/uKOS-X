/*
; stub.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Stub management.
;
;			This module implements the interface with the model_kern_xyz.c_inc.
;
; 			stub system calls
; 			-----------------
;
;			void	stub_kern_init(void);
;			void	stub_kern_runKernel(void);
;			void	stub_kern_setLowPower(uint8_t mode);
;			void	stub_kern_setPreciseSignal(prcs_t *handle);
;			void	stub_kern_readTickCount(uint64_t *tickCount);
;			void	stub_kern_newProcessTimeout(void);
;			void	stub_kern_stopProcessTimeout(void);
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
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup stub Stub
 *
 * \brief Stub
 *
 * Stub management
 *
 * @{
 */

// Modifiable in the makefile: use the PSPLIM & MSPLIM to check the stack overflow (implemented only in armv8.1)

#if (!defined(STUB_KERN_CHECK_XSP_LIMIT_S))
#undef	STUB_KERN_CHECK_XSP_LIMIT_S
#endif

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
 * \brief Initialise the uKernel
 *
 * Call example in C:
 *
 * \code{.c}
 *    stub_kern_init();
 * \endcode
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	stub_kern_init(void);

/*!
 * \brief Run the multitasking
 *
 * Call example in C:
 *
 * \code{.c}
 *    stub_kern_runKernel();
 * \endcode
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	stub_kern_runKernel(void);

/*!
 * \brief Set the low power mode
 *
 * Call example in C:
 *
 * \code{.c}
 * // Possible choice (if supported by the target)
 *
 * // KKERN_CPU_MODE_NORMAL     -> Normal mode
 * // KKERN_CPU_MODE_DEEP_SLEEP -> CPU in a deep sleep mode
 * // KKERN_CPU_MODE_HIBERNATE  -> CPU in a hibernate mode
 * // KKERN_CPU_MODE_STOP       -> CPU in a stop mode
 *
 * uint8_t    mode = KKERN_CPU_MODE_HIBERNATE
 *
 *    stub_kern_setLowPower(mode);
 * \endcode
 *
 * \param[in]	mode		Low power mode
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	stub_kern_setLowPower(uint8_t mode);

/*!
 * \brief Precise signal (minimal jitter)
 *
 * Call example in C:
 *
 * \code{.c}
 * #define     KTOPACQ    (1u<<0) | (1u<<28)
 *
 *    static    void    aProcess(const void *argument) {
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
 * \param[in]	*handle		Ptr on the handle
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	stub_kern_setPreciseSignal(prcs_t *handle);

/*!
 * \brief Read the tickCount
 *
 * Call example in C:
 *
 * \code{.c}
 * uint64_t    tickCount;
 *
 *    stub_kern_readTickCount(&tickCount);
 * \endcode
 *
 * \param[in]	-
 * \param[out]	*tickCount	Ptr on the tickCount (1-us of resolution)
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	stub_kern_readTickCount(uint64_t *tickCount);

/*!
 * \brief Start a new process timeout
 *
 * Call example in C:
 *
 * \code{.c}
 *    stub_kern_newProcessTimeout();
 * \endcode
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	stub_kern_newProcessTimeout(void);

/*!
 * \brief Stop the process timeout
 *
 * Call example in C:
 *
 * \code{.c}
 *    stub_kern_stopProcessTimeout();
 * \endcode
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	stub_kern_stopProcessTimeout(void);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
