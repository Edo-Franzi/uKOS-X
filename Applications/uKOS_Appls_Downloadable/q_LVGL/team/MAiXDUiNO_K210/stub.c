/*
; stub.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			Interface between the lvgl and the hardware.
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
#include	"lcd_display.h"
#include	"../../ulvgl.h"

// Prototypes

static	void		local_LCD_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t  end_y);
extern	int32_t		tft0_init(void);
extern	int32_t		tft0_writeCommand(uint8_t command);
extern	int32_t		tft0_write8(const uint8_t *buffer, uint32_t szBuffer);
extern	int32_t		tft0_write16(const uint16_t *buffer, uint32_t szBuffer);

/*
 * \brief stub_LCD_On
 *
 * - Initialise the LCD & the TFT
 *
 */
void	stub_LCD_On(void) {
	uint8_t		data, direction;

	direction = KDIR_YX_LRUD;

	PRIVILEGE_ELEVATE;

// Soft reset
// Pixel format

	tft0_init();
	tft0_writeCommand(KSOFTWARE_RESET);
	kern_suspendProcess(100u);

	tft0_writeCommand(KSLEEP_OFF);
	kern_suspendProcess(100u);
	tft0_writeCommand(KPIXEL_FORMAT_SET);

// Direction

	data = 0x55u;
	tft0_write8(&data, 1u);
	tft0_writeCommand(KMEMORY_ACCESS_CTL);
	tft0_write8(&direction, 1u);
	kern_suspendProcess(100u);

// Display on

	tft0_writeCommand(KDISPALY_ON);
	PRIVILEGE_RESTORE;
}

/*
 * \brief stub_LCD_flush_cb
 *
 * - Callback for flushing an image in the LCD display
 *
 */
void	stub_LCD_flush_cb(lv_display_t *lv_display, const lv_area_t *area, uint8_t *pixelMapping) {
	int32_t		w = (area->x2 - area->x1 + 1);
	int32_t		h = (area->y2 - area->y1 + 1);
	uint32_t	n, chunk, sent = 0u;

	PRIVILEGE_ELEVATE;
	local_LCD_SetWindow((uint16_t)area->x1, (uint16_t)area->y1, (uint16_t)area->x2, (uint16_t)area->y2);
	tft0_writeCommand(KMEMORY_WRITE);

// Effective transfer area size (n)

	n = (uint32_t)(w * h);

// Split in chunk transfers

	while(sent < n) {
		chunk = n - sent;
		if(chunk > 65535u) { chunk = 65535u; }

		const	void	*p_aligned = __builtin_assume_aligned(pixelMapping, 2);
		tft0_write16((const uint16_t *)p_aligned, (uint16_t)chunk);
		sent += chunk;
	}

	lv_display_flush_ready(lv_display);
	PRIVILEGE_RESTORE;
}

// Local routines
// ==============

/*
 * \brief local_LCD_SetWindow
 *
 * - Select the window region
 *
 */
static	void	local_LCD_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t  end_y) {
	uint8_t		data[4];

// X

	data[0] = (uint8_t)((start_x>>8) & 0xFFu);
	data[1] = (uint8_t)(start_x & 0xFFu);
	data[2] = (uint8_t)((end_x>>8) & 0xFFu);
	data[3] = (uint8_t)(end_x & 0xFFu);

	tft0_writeCommand(KHORIZONTAL_ADDRESS_SET);
	tft0_write8(&data[0], 4u);

// Y

	data[0] = (uint8_t)((start_y>>8) & 0xFFu);
	data[1] = (uint8_t)(start_y & 0xFFu);
	data[2] = (uint8_t)((end_y>>8) & 0xFFu);
	data[3] = (uint8_t)(end_y & 0xFFu);

	tft0_writeCommand(KVERTICAL_ADDRESS_SET);
	tft0_write8(&data[0], 4u);
}
