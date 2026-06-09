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
#include	"ulvgl.h"
#include	"lcd_display.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

extern	uint32_t					linker_stLCD_F_BUFFER[];
#define	FB_ADDR						linker_stLCD_F_BUFFER
#define	LCD_TFT						LTDC

#define	model_lcd_tft_rgb8888_init	stub_LCD_On

// Set the layer 1 and the number of bytes per lane

#define	L1_W						LCD_W
#define	L1_H						LCD_H
#define	L1_NB_BYTES_LINE			4u

/*
 * \brief stub_LCD_flush_cb
 *
 * - Callback for flushing an image in the LCD display
 *
 */
void	stub_LCD_flush_cb(lv_display_t *lv_display, const lv_area_t *area, uint8_t *pixelMapping) {
	uint8_t		*frameBuffer = (uint8_t *)FB_ADDR;
	int32_t		w = area->x2 - area->x1 + 1;
	int32_t		h = area->y2 - area->y1 + 1;
	int32_t		line, x, y;
	uint8_t		*src, *dst;

	UNUSED(lv_display);

	for (line = 0; line < h; line++) {
		y = area->y1 + line;
		x = area->x1;

		src = &pixelMapping[(size_t)line * (size_t)w * 4u];
		dst = &frameBuffer[((size_t)y * (size_t)L1_W + (size_t)x) * 4u];

		memcpy(dst, src, (size_t)w * 4u);
	}

	lv_display_flush_ready(lv_display);
}

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static	void	cb_enable(uint32_t rgb8888) {
				uint32_t	i, pixel;
	volatile	uint32_t	*p = (volatile uint32_t *)FB_ADDR;

	RCC->APB3ENR   |= RCC_APB3ENR_LTDCEN;
	RCC->APB3LPENR |= RCC_APB3LPENR_LTDCLPEN;
	STRONG_BARRIER;

// STM32H743 LTDC kernel clock selection.
// PLL3_R as LTDC pixel clock source.
// For the timings below, 800x480@60 Hz needs about:
// (800+48+88+40) * (480+3+32+13) * pfs = 25-MHz:
// So, fps = 48.5
//
// See init.c pll3 initialisation

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
void	cb_powerLCD(void) {

// Display powered
// Backlight on

	GPIOC->ODR |= (1u<<BLCD_POWER);
	kern_suspendProcess(100);

	GPIOB->ODR |= (1u<<BBL_CTRL);
	kern_suspendProcess(100);
}

#include	"model_lcd_tft_rgb8888.c_inc"
