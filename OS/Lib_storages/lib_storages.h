/*
; lib_storages.
; =============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		lib_storages system call interface module.
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
 * \defgroup Lib_storages Library for storage manager
 *
 * \brief Storage manager system calls
 *
 * The Lib_storages library unifies access to memory devices and data stores.
 * It ensures that storage is reliable, efficient, and simple to command.
 *
 * The storage manager offers a common interface. Whether card or flash,
 * it allows programmes to read and write data without caring for details.
 *
 * The sdcard manager controls removable cards. It brings familiar media to
 * embedded systems, where files can be logged, shared, or updated easily.
 *
 * The serialFlash manager governs serial flash memory. It provides fast
 * and persistent space for firmware, assets, and critical information.
 *
 * Together these managers make Lib_storages a safe foundation for data.
 * From portable media to embedded chips, all is handled with equal care.
 *
 * @{
 */

// IWYU pragma: begin_exports

#if (defined(CONFIG_MAN_STORAGE_S))
#include	"storage/storage.h"
#endif
#if (defined(CONFIG_MAN_SDCARD_S))
#include	"sdcard/sdcard.h"
#endif
#if (defined(CONFIG_MAN_SERIAL_FLASH_S))
#include	"serialFlash/serialFlash.h"
#endif

// IWYU pragma: end_exports

/**!@}*/
