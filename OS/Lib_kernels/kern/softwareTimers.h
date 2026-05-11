/*
; softwareTimers.
; ===============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Software timers.
;
;			This module implements the software primitives.
;
;			Software timer system calls
;			---------------------------
;
;			void	softwareTimers_init(void);
;			int32_t	kern_createSoftwareTimer(const char_t *identifier, stim_t **handle);
;			int32_t	kern_setSoftwareTimer(stim_t *handle, const tspc_t *configure);
;			int32_t	kern_killSoftwareTimer(stim_t *handle);
;			int32_t	kern_getSoftwareTimerById(const char_t *identifier, stim_t **handle);
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

#if (KKERN_NB_SOFTWARE_TIMERS > 0)

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup softwareTimers SoftwareTimers
 *
 * \brief Software timers
 *
 * Software timer management
 *
 * @{
 */

#define	KMBOX_SOFTWARE_TIMER	"Mbox_software_timer"			// Id of the mbox used by the software timer daemon

// Structure of the software timer specification
// ---------------------------------------------

typedef	struct	tspc		tspc_t;

struct	tspc {
			uint8_t		oMode;									// Mode
			uint32_t	oInitialTime;							// Initial time
			uint32_t	oTime;									// Continuous time
	const	void		*oArgument;								// Ptr on the software timer argument
			void		(*oCode)(const void *argument);			// Ptr on the code
};

// Mode (oMode)

enum {
			KSTIM_STOP = 0u,									// Stop the execution of the timer
			KSTIM_SINGLE_SHOT,									// Single shot software timer (with start)
			KSTIM_CONTINUOUS,									// Continuous software timer (with start)
};

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	void	softwareTimers_init(void);

/*!
 * \brief Create a software timer
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          stim_t     *softwareTimer;
 * const    char_t     identifier[] = ”Timer acquisition”;
 *
 *    status = kern_createSoftwareTimer(identifier, &softwareTimer);
 * \endcode
 *
 * \param[in]	*identifier		Ptr on the software timer identifier (nullptr = anonymous)
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_STFUL	No more software timer
 * \return		KERR_KERN_IDSTI	The software timer identifier is already used
 *
 */
extern	int32_t	kern_createSoftwareTimer(const char_t *identifier, stim_t **handle);

/*!
 * \brief Set a software timer
 *
 * Call example in C:
 *
 * \code{.c}
 * static     void    _changeStateLed(void);
 *
 * int32_t    status;
 * tspc_t     configure;
 * stim_t     *softwareTimer;
 *
 *    configure.oMode        = KSTIM_CONTINUOUS;
 *    configure.oInitialTime = 10000;
 *    configure.oTime        = 1000;
 *    configure.oArgument    = nullptr;
 *    configure.oCode        = _changeStateLed;
 *
 *    status = kern_setSoftwareTimer(softwareTimer, &configure);
 *
 *    // My callback routine
 *
 *    static    void    _changeStateLed(void) {
 *
 *        led_toggle(KLED_0);
 *    }
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSTI	The software timer does not exist
 * \return		KERR_KERN_CFSTI	The software timer cannot be configured
 *
 */
extern	int32_t	kern_setSoftwareTimer(stim_t *handle, const tspc_t *configure);

/*!
 * \brief Kill the software timer
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * stim_t     *softwareTimer;
 *
 *    status = kern_killSoftwareTimer(softwareTimer);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSTI	The software timer does not exist
 *
 */
extern	int32_t	kern_killSoftwareTimer(stim_t *handle);

/*!
 * \brief Get the handle of a software timer by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          stim_t     *softwareTimer;
 * const    char_t     identifier[] = ”Timer acquisition”;
 *
 *    status = kern_getSoftwareTimerById(identifier, &softwareTimer);
 * \endcode
 *
 * - This function returns the handle of the software timer
 *
 * \param[in]	*identifier		Ptr on the software timer identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSTI	The software timer does not exist
 *
 */
extern	int32_t	kern_getSoftwareTimerById(const char_t *identifier, stim_t **handle);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/

#endif
