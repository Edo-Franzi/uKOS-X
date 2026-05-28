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
#include	"../../ulvgl.h"

extern	uint32_t			linker_stLCD_F_BUFFER[];	//
#define	FB_ADDR				linker_stLCD_F_BUFFER		// Frame buffer

#define LCD_W				800u						// Active width
#define LCD_H				480u						// Active hight

#define LCD_HSYNC			48u							// HSYNC width
#define LCD_HBP				88u							// HSYNC HBP
#define LCD_HFP				40u							// HSYNC HFP

#define LCD_VSYNC			3u							// VSYNC width
#define LCD_VBP				32u							// VSYNC VBP
#define LCD_VFP				13u							// VSYNC VFP

#define	L1_W				800u						// Active layer 1 width
#define	L1_H				480u						// Active layer 1 hight
#define	L1_NB_BYTES_LINE	4u							// Active layer 1 nb bytes per liine

// Prototypes

static	void	local_setBackGroundColor(uint32_t rgb8888);
static	void	local_setLayer(void);
static	void	local_setPixelClock(void);
static	void	local_fillFBX8888(uint32_t *addr, uint32_t rgb8888);

/*
 * \brief stub_LCD_On
 *
 * - Initialise the LTDC
 *
 */
void	stub_LCD_On(void) {

	RCC->APB3ENR   |= RCC_APB3ENR_LTDCEN;
	RCC->APB3LPENR |= RCC_APB3LPENR_LTDCLPEN;
	STRONG_BARRIER;

	kern_suspendProcess(10u);

	local_setPixelClock();
	local_fillFBX8888(FB_ADDR, 0x00000000u);

//                             RRGGBB
	local_setBackGroundColor(0xFF0000u);
	local_setLayer();
}

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

// Local routines
// ==============

/*
 * \brief local_setBackGroundColor
 *
 * - Set the background color
 *
 */
static	void	local_setBackGroundColor(uint32_t rgb8888) {

// LTDC off during the configuration phase

	LTDC->GCR &= ~LTDC_GCR_LTDCEN;

// Full screen Timings

	LTDC->SSCR = ((LCD_HSYNC - 1u) * LTDC_SSCR_HSW_0)
			   | ((LCD_VSYNC - 1u) * LTDC_SSCR_VSH_0);
	LTDC->BPCR = ((LCD_HSYNC + LCD_HBP - 1u) * LTDC_BPCR_AHBP_0)
			   | ((LCD_VSYNC + LCD_VBP - 1u) * LTDC_BPCR_AVBP_0);
	LTDC->AWCR = ((LCD_HSYNC + LCD_HBP + LCD_W - 1u) * LTDC_AWCR_AAV_0)
			   | ((LCD_VSYNC + LCD_VBP + LCD_H - 1u) * LTDC_AWCR_AAH_0);
	LTDC->TWCR = ((LCD_HSYNC + LCD_HBP + LCD_W + LCD_HFP - 1u) * LTDC_TWCR_TOTALW_0)
			   | ((LCD_VSYNC + LCD_VBP + LCD_H + LCD_VFP - 1u) * LTDC_TWCR_TOTALH_0);

// Polarities

	LTDC->GCR &= ~(LTDC_GCR_HSPOL | LTDC_GCR_VSPOL | LTDC_GCR_DEPOL | LTDC_GCR_PCPOL);

// Layers OFF

	LTDC->L1CR = 0u;
	LTDC->L2CR = 0u;
	STRONG_BARRIER;

// Set the background

	LTDC->BCCR = rgb8888 & 0x00FFFFFFu;
    LTDC->SRCR = LTDC_SRCR_IMR;
	LTDC->GCR |= LTDC_GCR_LTDCEN;
    LTDC->SRCR = LTDC_SRCR_IMR;

// Display powered
// Backlight on

	GPIOC->ODR |= (1u<<BLCD_POWER);
	kern_suspendProcess(100);

	GPIOB->ODR |= (1u<<BBL_CTRL);
	kern_suspendProcess(100);

// LTDC on

	LTDC->GCR |= LTDC_GCR_LTDCEN;
    LTDC->SRCR = LTDC_SRCR_IMR;
}

/*
 * \brief local_setLayer
 *
 * - Set the layer
 *
 */
static	void	local_setLayer(void) {

// Centered window in ACTIVE area coordinates

	uint32_t	ahbp = (LTDC->BPCR>>16u) & 0x0FFFu;
	uint32_t	avbp = (LTDC->BPCR>>0u)  & 0x0FFFu;
	uint32_t	x0 = (ahbp + 1u) + ((LCD_W - L1_W) / 2u);
	uint32_t	y0 = (avbp + 1u) + ((LCD_H - L1_H) / 2u);
	uint32_t	x1 = x0 + L1_W - 1u;
	uint32_t	y1 = y0 + L1_H - 1u;

// Layer off during the configuration phase

	LTDC->L1CR = 0u;

// Window position

	LTDC->L1WHPCR = ((x1 & 0x0FFFu)<<16u) | (x0 & 0x0FFFu);
	LTDC->L1WVPCR = ((y1 & 0x0FFFu)<<16u) | (y0 & 0x0FFFu);

// Fully opaque constant alpha
// Pixel format ARGB8888
// Blending factors (opaque layer): BF1=CA, BF2=1-CA

	LTDC->L1CACR = 255u;
	LTDC->L1PFCR = (0u * LTDC_L1PFCR_PF_0);
	LTDC->L1BFCR = (4u * LTDC_L1BFCR_BF1_0) | (5u * LTDC_L1BFCR_BF2_0);

// Frame buffer
// Color Framebuffer lenght

	LTDC->L1CFBAR  = (uint32_t)FB_ADDR;
	LTDC->L1CFBLR  = (( L1_W * L1_NB_BYTES_LINE)	   * LTDC_L1CFBLR_CFBP_0)
				   | (((L1_W * L1_NB_BYTES_LINE) + 7u) * LTDC_L1CFBLR_CFBLL_0);
	LTDC->L1CFBLNR = L1_H;

// Layer default background color
//                        AARRGGBB
	LTDC->L1DCCR = 0x00000000u;

// Layer on

	LTDC->L1CR = LTDC_L1CR_LEN;
	LTDC->SRCR = LTDC_SRCR_IMR;

	STRONG_BARRIER;
}

/*
 * \brief local_setPixelClock
 *
 * - Set the pixel clock
 *
 */
static	void	local_setPixelClock(void) {

// STM32H743 LTDC kernel clock selection.
// PLL3_R as LTDC pixel clock source.
// For the timings below, 800x480@60 Hz needs about:
// (800+48+88+40) * (480+3+32+13) * pfs = 25-MHz:
// So, fps = 48.5
//
// See init.c pll3 initialisation

}

/*
 * \brief local_fillFBX8888
 *
 * - Fill the layer 1 frame buffer
 *
 */
static	void	local_fillFBX8888(uint32_t *addr, uint32_t rgb8888) {
				uint32_t	i, pixel;
	volatile	uint32_t	*p = (volatile uint32_t *)addr;

	pixel = rgb8888 & 0x00FFFFFFu;

	for (i = 0u; i < (L1_W * L1_H); i++) {
		p[i] = pixel;
	}
}
