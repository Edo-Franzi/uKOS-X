/*
; cmns.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Some common routines used in many modules.
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

// Supported managers

typedef	enum {
			KNOTR = (((uint32_t)'n'<<24u) | ((uint32_t)'o'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'R'),	// notr manager
			KSYST = (((uint32_t)'s'<<24u) | ((uint32_t)'y'<<16u) | ((uint32_t)'s'<<8u) | (uint32_t)'t'),	// syst manager
			KDEF0 = (((uint32_t)'d'<<24u) | ((uint32_t)'e'<<16u) | ((uint32_t)'f'<<8u) | (uint32_t)'0'),	// def0 manager
			KURT0 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'0'),	// urt0 manager
			KURT1 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'1'),	// urt1 manager
			KURT2 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'2'),	// urt2 manager
			KURT3 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'3'),	// urt3 manager
			KURT4 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'4'),	// urt4 manager
			KCDC0 = (((uint32_t)'c'<<24u) | ((uint32_t)'d'<<16u) | ((uint32_t)'c'<<8u) | (uint32_t)'0'),	// cdc0 manager
			KCDC1 = (((uint32_t)'c'<<24u) | ((uint32_t)'d'<<16u) | ((uint32_t)'c'<<8u) | (uint32_t)'1'),	// cdc1 manager
			KWFI0 = (((uint32_t)'w'<<24u) | ((uint32_t)'f'<<16u) | ((uint32_t)'i'<<8u) | (uint32_t)'0')		// wfi0 manager
} serialManager_t;

/*
 * \brief cmns_init
 *
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	cmns_init(void);

/*
 * \brief cmns_send
 *
 * \param[in]	serialManager	Serial Communication Manager
 * \param[in]	*ascii			Ptr on the ascii buffer
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	cmns_send(serialManager_t serialManager, const char_t *ascii);

/*
 * \brief cmns_receive
 *
 * \param[out]	*data		Data received
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	cmns_receive(serialManager_t serialManager, char_t *data);

/*
 * \brief cmns_wait
 *
 * \param[in]	us		Delay in us
 *
 * \note This function does not return a value (None).
 *
 */
extern	void	cmns_wait(uint32_t us);
