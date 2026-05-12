/*
; lcd0.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		lcd0 manager.
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
#include	"../lcd0/lcd0.h"
#include	"../lcd0/font.h"
#include	"../tft0/tft0.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"lcd0         lcd0 manager.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "lcd0 manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Lcd0,							// Module name (the first letter has to be upper case)
	KID_FAM_PERIPHERALS,			// Family (defined in the module.h)
	KLCD0_NUM,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

static	mutx_t		*vMutex;

static	lcdCtl_t	vLcdCtl;
static	uint16_t	vImage[640 * 2] = { 0u };

// Prototypes

static	int32_t	local_init(void);
static	void	local_setArea(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
static	void	local_drawChar(uint16_t x, uint16_t y, char c, uint16_t color);
static	void	local_drawPoint(uint16_t x, uint16_t y, uint16_t color);

/*
 * \brief Reserve the lcd0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = lcd0_reserve(KMODE_READ_WRITE, 1234u);
 *    ....
 *    lcd0_xyz();
 *    ....
 *    status = lcd0_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \param[in]	timeout			Timeout (1-ms of resolution)
 * \return		KERR_LCD0_NOERR	The manager is reserved
 * \return		KERR_LCD0_GEERR	General error
 * \return	  	KERR_LCD0_CHBSY	The manager is busy
 *
 */
int32_t	lcd0_reserve(reserveMode_t reserveMode, uint32_t timeout) {
	int32_t		status;

	UNUSED(reserveMode);

	status = local_init();
	if (status != KERR_LCD0_NOERR) { return (status); }

	status = kern_lockMutex(vMutex, timeout);
	if (status != KERR_KERN_NOERR) {
		return (KERR_LCD0_CHBSY);
	}

	return (KERR_LCD0_NOERR);
}

/*
 * \brief Release the lcd0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = lcd0_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \return		KERR_LCD0_NOERR	OK
 * \return		KERR_LCD0_GEERR	General error
 * \return		KERR_LCD0_CAREL	Cannot release the manager
 *
 */
int32_t	lcd0_release(reserveMode_t reserveMode) {
	int32_t		status;

	UNUSED(reserveMode);

	status = local_init();
	if (status != KERR_LCD0_NOERR) { return (status); }

	status = kern_unlockMutex(vMutex);
	if (status != KERR_KERN_NOERR) {
		return (KERR_LCD0_CAREL);
	}

	return (KERR_LCD0_NOERR);
}

/*
 * \brief Set the writing direction
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_setDirection(DIR_XY_RLUD);
 * \endcode
 *
 * \param[in]	direction		Writing direction
 * \return		KERR_LCD0_NOERR	OK
 * \return		KERR_LCD0_GEERR	General error
 *
 */
int32_t	lcd0_setDirection(uint8_t direction) {
	int32_t		status;

	status = local_init();
	if (status != KERR_LCD0_NOERR) { return (status); }

	vLcdCtl.direction = direction;
	if ((direction & KDIR_XY_MASK) != 0u) {
		vLcdCtl.width  = KLCD_Y_MAX - 1u;
		vLcdCtl.height = KLCD_X_MAX - 1u;
	}
	else {
		vLcdCtl.width  = KLCD_X_MAX - 1u;
		vLcdCtl.height = KLCD_Y_MAX - 1u;
	}

	tft0_writeCommand(KMEMORY_ACCESS_CTL);
	tft0_write8(&direction, 1u);
	return (KERR_LCD0_NOERR);
}

/*
 * \brief Set the draw point
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_drawPoint(0, 0, 10, 10, MAGENTA);
 * \endcode
 *
 * \param[in]	x				X0 coordinate
 * \param[in]	y				y0 coordinate
 * \param[in]	color			Pixel color
 * \return		KERR_LCD0_NOERR	OK
 * \return		KERR_LCD0_GEERR	General error
 *
 */
int32_t	lcd0_drawPoint(uint16_t x, uint16_t y, uint16_t color) {
	int32_t		status;

	status = local_init();
	if (status != KERR_LCD0_NOERR) { return (status); }

	local_drawPoint(x, y, color);
	return (KERR_LCD0_NOERR);
}

/*
 * \brief Draw a string
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_drawString(0, 0, 'a', MAGENTA);
 * \endcode
 *
 * \param[in]	x				X coordinate
 * \param[in]	y				Y coordinate
 * \param[in]	*s				Ptr on the string
 * \param[in]	color			Pixel color
 * \return		KERR_LCD0_NOERR	OK
 * \return		KERR_LCD0_GEERR	General error
 *
 */
int32_t	lcd0_drawString(uint16_t x, uint16_t y, const char *s, uint16_t color) {
	int32_t		status;

	status = local_init();
	if (status != KERR_LCD0_NOERR) { return (status); }

	while (*s != '\0') {
		local_drawChar(x, y, *s, color);
		s++;
		x += 8u;
	}
	return (KERR_LCD0_NOERR);
}

/*
 * \brief Draw a RAM string
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_drawRamString(0, 0, 'a', MAGENTA);
 * \endcode
 *
 * \param[in]	*s				Ptr on the string
 * \param[in]	*area			Ptr on the RAM area
 * \param[in]	fntColor		Font color
 * \param[in]	bgdColor		Background color
 * \return		KERR_LCD0_NOERR	OK
 * \return		KERR_LCD0_GEERR	General error
 *
 */
int32_t	lcd0_drawRamString(const char *s, uint32_t *area, uint16_t fntColor, uint16_t bgdColor) {
			size_t		width = 0;
			uint32_t	*pixel = nullptr;
			uint8_t		i, j, data;
			int32_t		status;
	const	uint8_t		*font;

	status = local_init();
	if (status != KERR_LCD0_NOERR) { return (status); }

	width = (4u * strlen(s));
	while (*s != '\0') {
		font = &font0816[(size_t)(*s) * (size_t)16u];
		for (i = 0u; i < 16u; i++) {
			data = *font++;
			pixel = area + (i * width);
			for (j = 0u; j < 4u; j++) {
				switch (data>>6u) {
					case 0u: { *pixel = ((uint32_t)bgdColor<<16u) | bgdColor; break; }
					case 1u: { *pixel = ((uint32_t)bgdColor<<16u) | fntColor; break; }
					case 2u: { *pixel = ((uint32_t)fntColor<<16u) | bgdColor; break; }
					case 3u: { *pixel = ((uint32_t)fntColor<<16u) | fntColor; break; }
					default: { *pixel = 0; break; }
				}
				data <<= 2u;
				pixel++;
			}
		}
		s++;
		area += 4u;
	}
	return (KERR_LCD0_NOERR);
}

/*
 * \brief Clear the lcd (fill with a color)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_clear(0, 0, 'a', MAGENTA);
 * \endcode
 *
 * \param[in]	color			Color
 * \return		KERR_LCD0_NOERR	OK
 * \return		KERR_LCD0_GEERR	General error
 *
 */
int32_t	lcd0_clear(uint16_t color) {
	int32_t		status;

	status = local_init();
	if (status != KERR_LCD0_NOERR) { return (status); }

	local_setArea(0u, 0u, vLcdCtl.width, vLcdCtl.height);
	tft0_fill16(&color, KLCD_X_MAX * KLCD_Y_MAX);
	return (KERR_LCD0_NOERR);
}

/*
 * \brief Draw a rectangle
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_drawRectangle(0, 0, 10, 10, MAGENTA);
 * \endcode
 *
 * \param[in]	x0				X0 coordinate
 * \param[in]	y0				y0 coordinate
 * \param[in]	x1				X1 coordinate
 * \param[in]	y1				y1 coordinate
 * \param[in]	width			Rectangle with
 * \param[in]	color			Pixel color
 * \return		KERR_LCD0_NOERR	OK
 * \return		KERR_LCD0_GEERR	General error
 *
 */
int32_t	lcd0_drawRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t width, uint16_t color) {
	uint16_t	*p, data = color;
	uint32_t	i = 0u;
	int32_t		status;

	status = local_init();
	if (status != KERR_LCD0_NOERR) { return (status); }

	p = &vImage[0];
	for (i = 0u; i < (KLCD_Y_MAX * width); i++) {
		*p++ = data;
	}

	local_setArea(x0,						   y0,						    x1,						     (uint16_t)(y0 + width - 1u)); tft0_write16(&vImage[0], (uint32_t)(((x1 - x0 + 1) * width) + 1));
	local_setArea(x0,						   (uint16_t)(y1 - width + 1u), x1,						     y1);						   tft0_write16(&vImage[0], (uint32_t)(((x1 - x0 + 1) * width) + 1));
	local_setArea(x0,						   y0,						    (uint16_t)(x0 + width - 1u), y1);						   tft0_write16(&vImage[0], (uint32_t)(((y1 - y0 + 1) * width) + 1));
	local_setArea((uint16_t)(x1 - width + 1u), y0,						    x1,						     y1);						   tft0_write16(&vImage[0], (uint32_t)(((y1 - y0 + 1) * width) + 1));
	return (KERR_LCD0_NOERR);
}

/*
 * \brief Draw a picture
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = lcd0_drawPicture(0, 0, 10, 10, MAGENTA);
 * \endcode
 *
 * \param[in]	x				X coordinate
 * \param[in]	y				y coordinate
 * \param[in]	width			Width
 * \param[in]	height			Height
 * \param[in]	*area			Ptr on the area
 * \return		KERR_LCD0_NOERR	OK
 * \return		KERR_LCD0_GEERR	General error
 *
 */
int32_t	lcd0_drawPicture(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint16_t *area) {
	int32_t		status;

	status = local_init();
	if (status != KERR_LCD0_NOERR) { return (status); }

	local_setArea(x, y, (uint16_t)(x + width - 1u), (uint16_t)(y + height - 1u));
	tft0_write16(area, (uint16_t)(width * height));
	return (KERR_LCD0_NOERR);
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static	int32_t	local_init(void) {
			uint8_t		data;
	static	bool		vInit = false;

	INTERRUPTION_OFF;
	if (vInit == false) {
		vInit = true;

		if (kern_createMutex(KLCD0_MUTEX_RESERVE, &vMutex) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "lcd0: create mutx"); exit(EXIT_OS_PANIC); }

// Soft reset
// Pixel format

		tft0_init();
		tft0_writeCommand(KSOFTWARE_RESET);
		kern_suspendProcess(100u);

		tft0_writeCommand(KSLEEP_OFF);
		kern_suspendProcess(100u);

		tft0_writeCommand(KPIXEL_FORMAT_SET);

		data = 0x55u;
		tft0_write8(&data, 1u);
		lcd0_setDirection(KDIR_XY_LRDU);

// Display on

		tft0_writeCommand(KDISPALY_ON);
	}
	RETURN_INT_RESTORE(KERR_LCD0_NOERR);
}

/*
 * \brief local_setArea
 *
 * - Set the painting area
 *
 */
static	void	local_setArea(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
	uint8_t		data[4];

	data[0] = (uint8_t)(x0>>8u);
	data[1] = (uint8_t)(x0);
	data[2] = (uint8_t)(x1>>8u);
	data[3] = (uint8_t)(x1);
	tft0_writeCommand(KHORIZONTAL_ADDRESS_SET);
	tft0_write8(&data[0], 4u);

	data[0] = (uint8_t)(y0>>8u);
	data[1] = (uint8_t)(y0);
	data[2] = (uint8_t)(y1>>8u);
	data[3] = (uint8_t)(y1);
	tft0_writeCommand(KVERTICAL_ADDRESS_SET);
	tft0_write8(&data[0], 4u);

	tft0_writeCommand(KMEMORY_WRITE);
}

/*
 * \brief local_drawChar
 *
 * - Write a char
 *
 */
static	void	local_drawChar(uint16_t x, uint16_t y, char c, uint16_t color) {
	uint8_t		i, j, data;

	for (i = 0u; i < 16u; i++) {
		data = font0816[((uint8_t)c * 16u) + i];
		for (j = 0; j < 8u; j++) {
			if ((data & 0x80u) != 0u) {
				local_drawPoint(x + j, y, color);
			}
			data <<= 1u;
		}
		y++;
	}
}

/*
 * \brief local_drawPoint
 *
 * - Draw a point
 *
 */
static	void	local_drawPoint(uint16_t x, uint16_t y, uint16_t color) {

	local_setArea(x, y, x, y);
	tft0_write16(&color, 1u);
}
