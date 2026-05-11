/*
; record.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		record manager.
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

#include	"macros.h"

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \defgroup record Record
 *
 * \brief Record
 *
 * Record management
 *
 * @{
 */

// Modifiable in the makefile: depth of the fifo for the tracing

#if (!defined(KRECORD_SZ_LOG_BUF))
#define	KRECORD_SZ_LOG_BUF		200u
#endif

#if (!defined(KRECORD_SZ_TRACE_FIFO))
#define	KRECORD_SZ_TRACE_FIFO	200u
#endif

// Trace fifo & log buffer
// -----------------------

typedef	struct	recordTracing	recordTracing_t;
typedef	struct	recordLogging	recordLogging_t;

// Log categories

typedef	enum {
			KFATAL_SYSTEM = 0x10u,								// Fatal
			KFATAL_KERNEL,										//
			KFATAL_MANAGER,										//
			KFATAL_USER,										//

			KERROR_SYSTEM = 0x20u,								// Error
			KERROR_KERNEL,										//
			KERROR_MANAGER,										//
			KERROR_USER,										//

			KWARNING_SYSTEM = 0x30u,							// Warninig
			KWARNING_KERNEL,									//
			KWARNING_MANAGER,									//
			KWARNING_USER,										//

			KINFO_SYSTEM = 0x40u,								// Info
			KINFO_KERNEL,										//
			KINFO_MANAGER,										//
			KINFO_USER											//
} recordLogCategory_t;

// Logs macro

#define	LOG(cat, msg)			(UNUSED(record_log((cat), __LINE__, __func__, (msg))))

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
 * \brief Trace the code with a parameter
 *
 * Call example in C:
 *
 * \code{.c}
 *    record_trace(“Program call the routine _xyz\n”, 0x55);
 *    _xyz();
 *
 *    record_trace(“Program write\n”, 0x24);
 * \endcode
 *
 * \param[in]	*message			Ptr on the message
 * \param[in]	parameter			Parameter
 * \return		KERR_RECORD_NOERR	OK
 * \return		KERR_RECORD_SYCNA	System call not available
 *
 */
extern	int32_t	record_trace(const char_t *message, uintptr_t parameter);

/*!
 * \brief Log trace
 *
 * Call example in C:
 *
 * \code{.c}
 *    record_log(KFATAL_SYSTEM, __LINE__, __fnct__, “Privilege violation”);
 *    _xyz();
 *
 *    The macro LOG allow to write
 *    LOG(“Privilege violation”);
 *
 * \endcode
 *
 * \param[in]	logCategory			Log category
 * \param[in]	lineNumber			Line number (__LINE__)
 * \param[in]	*function			Ptr on the function (__func__)
 * \param[in]	*message			Ptr on the message
 * \return		KERR_RECORD_NOERR	OK
 * \return		KERR_RECORD_SYCNA	System call not available
 *
 */
extern	int32_t	record_log(recordLogCategory_t logCategory, uint32_t lineNumber, const char_t *function, const char_t *message);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
