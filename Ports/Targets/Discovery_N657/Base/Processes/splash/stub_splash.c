/*
; stub_splash.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
; SPDX-FileCopyrightText: 2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-10-08
; Modifs:
;
; Project:	uKOS-X
; Goal:		Connect the splash process to the RK050HR18 LTDC display.
;
;   (c) 2026, Laurent von Allmen
;   ----------------------------
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
#include	"splash/splash.h"
#include	"ulvgl.h"
#include	<stddef.h>
#include	<stdint.h>

// Connect the physical device to the logical manager
// --------------------------------------------------

extern	uint32_t					linker_stLCD_F_BUFFER[];
#define FB_ADDR						((uint32_t)linker_stLCD_F_BUFFER)
#define LCD_TFT						REG(LTDC)

#define model_lcd_tft_rgb8888_init	stub_splash_on

// Set the layer 1 and the number of bytes per pixel
// The banner is drawn on the whole panel

#define L1_W						LCD_W
#define L1_H						LCD_H
#define L1_NB_BYTES_LINE			KLCD_NB_BYTES_PIXEL

static_assert((KLCD_WIDTH == LCD_W) && (KLCD_HEIGHT == LCD_H), "The banner does not match the panel");

/*
 * \brief stub_splash_flush_cb
 *
 * - Callback for flushing an image in the LCD display
 *
 */
void	stub_splash_flush_cb(lv_display_t *lv_display, const lv_area_t *area, uint8_t *pixelMapping) {
			uint8_t		*frameBuffer = (uint8_t *)FB_ADDR;
			int32_t		w = area->x2 - area->x1 + 1;
			int32_t		h = area->y2 - area->y1 + 1;
			int32_t		line, x, y;
			uint8_t		*dst;
	const	uint8_t		*src;

	for (line = 0; line < h; line++) {
		y = area->y1 + line;
		x = area->x1;

		src = &pixelMapping[(size_t)line * (size_t)w * L1_NB_BYTES_LINE];
		dst = &frameBuffer[(((size_t)y * (size_t)L1_W) + (size_t)x) * L1_NB_BYTES_LINE];

		memcpy(dst, src, (size_t)w * L1_NB_BYTES_LINE);
	}

	lv_display_flush_ready(lv_display);
}

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 * - Set the LTDC pixel clock: PLL4 / 16 = 25-MHz, i.e. 60.9 frames per second
 *	 with the timings of the panel ((800+4+8+8) * (480+4+8+8) pixels)
 *
 */
static	void	cb_enable(uint32_t rgb8888) {
				uint32_t	i, pixel;
	volatile	uint32_t	*p = (volatile uint32_t *)FB_ADDR;

	REG(RCC)->APB5ENR	|= RCC_APB5ENR_LTDCEN;
	REG(RCC)->APB5LPENR |= RCC_APB5LPENR_LTDCLPEN;

	REG(RCC)->IC16CFGR = (3u * RCC_IC16CFGR_IC16SEL_0)
					   | ((16u - 1u) * RCC_IC16CFGR_IC16INT_0);
	STRONG_BARRIER;

	REG(RCC)->DIVENR |= RCC_DIVENR_IC16EN;
	(void)(REG(RCC)->DIVENR);

	REG(RCC)->CCIPR4 &= ~RCC_CCIPR4_LTDCSEL;
	REG(RCC)->CCIPR4 |= (0x2u * RCC_CCIPR4_LTDCSEL_0);
	STRONG_BARRIER;

// Initialise the frame buffer

	pixel = rgb8888 & 0x00FFFFFFu;

	for (i = 0u; i < (L1_W * L1_H); i++) {
		p[i] = pixel;
	}
}

/*
 * \brief cb_powerLCD
 *
 * - Turn-on the LCD
 *
 */
static	void	cb_powerLCD(void) {

// Display powered
// Backlight on

	REG(GPIOQ)->ODR |= (1u<<BLCD_POWER);
	kern_suspendProcess(100u);

	REG(GPIOQ)->ODR |= (1u<<BBL_CTRL);
	kern_suspendProcess(100u);
}

#include	"model_lcd_tft_rgb8888.c_inc"
