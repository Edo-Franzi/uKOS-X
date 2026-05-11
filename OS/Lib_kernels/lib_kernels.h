/*
; lib_kernels.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		lib_kernels system call interface module.
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
 * \defgroup Lib_kernels Library for micro-kernel
 *
 * \brief uKernel manager system calls
 *
 * The Lib_kernels library introduces the kern manager, dedicated to real
 * time control. It brings the features of a modern RTOS into a single point.
 *
 * The kern manager schedules tasks with precision. Each process receives
 * its share of the processor, and deadlines are respected without delay.
 * It also handles synchronisation. Semaphores, queues, and events ensure that
 * tasks communicate safely, avoiding both conflict and starvation.
 *
 * Time itself is central. The kern manager measures ticks, waits, and
 * periods, so that actions occur exactly when they are required to happen.
 * A modern RTOS must adapt to change. The kern manager allows priorities
 * to be altered, resources to be reallocated, and systems to remain steady.
 *
 * With Lib_kernels, real time is no longer fragile. It becomes a framework
 * where reliability, responsiveness, and control move hand in hand.
 *
 * @{
 */

// IWYU pragma: begin_exports

#include	"modules.h"
#include	"kern/kern.h"

// IWYU pragma: end_exports

/**!@}*/
