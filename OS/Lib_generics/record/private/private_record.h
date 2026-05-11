/*
; private_record.
; ===============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		record manager.
;
;			Private record variables.
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

#include	"./kern/kern.h"

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \addtogroup record
 * @{
 */

/*!
 * \defgroup private_record Private Record
 *
 * \brief Private record variables and structures
 *
 * Internal reco structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

struct recordTracing {
				uint64_t			oTimeStamp;												// Time stamp of the trace
		const	char_t				*oMessage;												// Ptr on the message
				uintptr_t			oParameter;												// Parameter
				proc_t				*oProcess;												// Process from which trace has been written
};

extern			recordTracing_t		vRecord_traceFifo[KNB_CORES][KRECORD_SZ_TRACE_FIFO];	// Fifo for the trace
extern			recordTracing_t		*vRecord_RTraceFifo[KNB_CORES];							// Ptr (R) for the trace
extern			recordTracing_t		*vRecord_WTraceFifo[KNB_CORES];							// Ptr (W) for the trace
extern			uint32_t			vRecord_NbTraceWrites[KNB_CORES];						// Number of writes in the fifo trace

struct recordLogging {
				recordLogCategory_t	oLogCategory;											// Log category
				bool				oMark;													// Marking (for reading)
				uint64_t			oTimeStamp;												// Time stamp of the log
		const	char_t				*oFunction;												// Ptr on the function name
		const	char_t				*oMessage;												// Ptr on the message
				uint32_t			oLineNumber;											// Line number
		const	char_t				*oIdentifier;											// Process identifier from which log has been written
};

extern			recordLogging_t		vRecord_logBuffer[KNB_CORES][KRECORD_SZ_LOG_BUF];		// Buffer for the logs
extern			uint32_t			vRecord_NbLogWrites[KNB_CORES];							// Number of writes in the buffer log

/**@}*/
/**@}*/
/**@}*/
