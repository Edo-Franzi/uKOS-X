/*
; stub.
; =====

; SPDX-License-Identifier: MIT

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

#define	BLCD_CS			9u				// LCD CS
#define	BLCD_DC			10u				// LCD Data/Command
#define	BLCD_RST		11u				// LCD Reset

// Macros for controlling the LCD controller ST7789VW

#define	CMD_PARAMETER_00(commmande)																	\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
	} while (0)

#define	CMD_PARAMETER_01(commmande, d1)																\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
		local_LCD_WriteData(d1);																	\
	} while (0)

#define	CMD_PARAMETER_02(commmande, d1, d2)															\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
		local_LCD_WriteData(d1);																	\
		local_LCD_WriteData(d2);																	\
	} while (0)

#define	CMD_PARAMETER_04(commmande, d1, d2, d3, d4)													\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
		local_LCD_WriteData(d1);																	\
		local_LCD_WriteData(d2);																	\
		local_LCD_WriteData(d3);																	\
		local_LCD_WriteData(d4);																	\
	} while (0)

#define	CMD_PARAMETER_05(commmande, d1, d2, d3, d4, d5)												\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
		local_LCD_WriteData(d1);																	\
		local_LCD_WriteData(d2);																	\
		local_LCD_WriteData(d3);																	\
		local_LCD_WriteData(d4);																	\
		local_LCD_WriteData(d5);																	\
	} while (0)

#define	CMD_PARAMETER_14(commmande, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14)	\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
		local_LCD_WriteData(d1);																	\
		local_LCD_WriteData(d2);																	\
		local_LCD_WriteData(d3);																	\
		local_LCD_WriteData(d4);																	\
		local_LCD_WriteData(d5);																	\
		local_LCD_WriteData(d6);																	\
		local_LCD_WriteData(d7);																	\
		local_LCD_WriteData(d8);																	\
		local_LCD_WriteData(d9);																	\
		local_LCD_WriteData(d10);																	\
		local_LCD_WriteData(d11);																	\
		local_LCD_WriteData(d12);																	\
		local_LCD_WriteData(d13);																	\
		local_LCD_WriteData(d14);																	\
	} while (0)

// Prototypes

static	void	local_LCD_Init(void);
static	void	local_LCD_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t  end_y);
static	void	local_LCD_WriteCommand(uint8_t command);
static	void	local_LCD_WriteData(uint8_t data);

/*
 * \brief stub_LCD_On
 *
 * - Initialise the LCD & the SPI
 *
 */
void	stub_LCD_On(void) {

// The ST7789VW accept a Tscycw (in write) of 16-ns

	const	spiCnf_t	configure = {
								.oSpeed    = 62500000u,
								.oMode     = (uint8_t)KSPI_MASTER,
								.oClock    = 0u
							};

	PRIVILEGE_ELEVATE;

// Reset the LCD

	REG(GPIOE)->ODR |= ((1u<<BLCD_CS) | (1u<<BLCD_DC) | (1u<<BLCD_RST));
	kern_suspendProcess(200u);
	REG(GPIOE)->ODR &= (uint32_t)~(1u<<BLCD_RST);
	kern_suspendProcess(200u);
	REG(GPIOE)->ODR |= (1u<<BLCD_RST);
	kern_suspendProcess(200u);

// Initialise the SPI & the LCD

	spi_configure(KSPI0, &configure);
	kern_suspendProcess(200u);

	local_LCD_Init();

	PRIVILEGE_RESTORE;
}

/*
 * \brief stub_LCD_flush_cb
 *
 * - Callback for flushing an image in the LCD displa
 *
 */
void	stub_LCD_flush_cb(lv_display_t *lv_display, const lv_area_t *area, uint8_t *pixelMapping) {
	int32_t		w = (area->x2 - area->x1 + 1);
	int32_t		h = (area->y2 - area->y1 + 1);
	uint32_t	n, chunk, sent = 0u;

	PRIVILEGE_ELEVATE;
	local_LCD_SetWindow((uint16_t)area->x1, (uint16_t)area->y1, (uint16_t)area->x2, (uint16_t)area->y2);
	local_LCD_WriteCommand(0x2Cu);

// Effective transfer area size (n)

	n = (uint32_t)(w * h * 2);

	REG(GPIOE)->ODR &= (uint32_t)~(1u<<BLCD_CS);

// Split in chunk transfers

	while(sent < n) {
		chunk = n - sent;
		if(chunk > 65535u) { chunk = 65535u; }

		spi_multipleWriteRead(KSPI0, &pixelMapping[sent], (uint16_t)chunk, nullptr, 0u, KWAIT_INFINITY);
		sent += chunk;
	}

	REG(GPIOE)->ODR |= (1u<<BLCD_CS);

	lv_display_flush_ready(lv_display);
	PRIVILEGE_RESTORE;
}

// Local routines
// ==============

/*
 * \brief local_LCD_Init
 *
 * - Initialise the LCD
 * - This table is provided by the Waveshare
 *
 */
static	void	local_LCD_Init(void) {

// MADCTL (36h): Memory Data Access Control
// Bottom to Top, Left to Right, Reverse Mode, LCD Refresh Top to Bottom
// RGB, LCD Refresh Left to Right

	CMD_PARAMETER_01(0x36u, 0xA0u);

// COLMOD (3Ah): Interface Pixel Format
// ‘101’ = 16bit/pixel

	CMD_PARAMETER_01(0x3Au, 0x05u);

// INVON (21h): Display Inversion On

	CMD_PARAMETER_00(0x21u);

// CASET (2Ah): Column Address Set
// start: 0001, end: 0063

	CMD_PARAMETER_04(0x2Au, 0x00u, 0x01, 0x00u, 0x3Fu);

// RASET (2Bh): Row Address Set
// start: 0000, end: 0239

	CMD_PARAMETER_04(0x2Bu, 0x00u, 0x00u, 0x00u, 0xEFu);

// PORCTRL (B2h): Porch Setting
// 0Ch/0Ch/00h/33h/33h (default)

	CMD_PARAMETER_05(0xB2u, 0x0Cu, 0x0C, 0x00u, 0x33u, 0x33u);

// GCTRL (B7h): Gate Control
// VGHS = 13.26-V, VGLS = -10.43-V

	CMD_PARAMETER_01(0xB7u, 0x35u);

// VCOMS (BBh): VCOM Setting
// Vcom = 0.875-V

	CMD_PARAMETER_01(0xBBu, 0x1Fu);

// LCMCTRL (C0h): LCM Control
// ----

	CMD_PARAMETER_01(0xC0u, 0x2Cu);

// VDVVRHEN (C2h): VDV and VRH Command Enable
// 01h/FFh (default)

	CMD_PARAMETER_02(0xC2u, 0x01u, 0xFFu);

// VRHS (C3h): VRH Set
// VAP = 4.45-V +( vcom+vcom offset+vdv)

	CMD_PARAMETER_01(0xC3u, 0x12u);

// RAMCTRL (B0h): RAM Control
// MCU, Little Endian

	CMD_PARAMETER_02(0xB0u, 0x00u, 0xF8);

// VDVS (C4h): VDV Set
// 20h (default)

	CMD_PARAMETER_01(0xC4u, 0x20u);

// FRCTRL2 (C6h): Frame Rate Control in Normal Mode
// FR = 60-Hz

	CMD_PARAMETER_01(0xC6u, 0x0Fu);

// PWCTRL1 (D0h): Power Control 1
// A4h/A1h (default)

	CMD_PARAMETER_02(0xD0u, 0xA4u, 0xA1u);

// PVGAMCTRL (E0h): Positive Voltage Gamma Control
// ----

	CMD_PARAMETER_14(0xE0u, 0xD0u, 0x08u, 0x11u, 0x08u, 0x0Cu, 0x15u, 0x39u, 0x33u, 0x50u, 0x36u, 0x13u, 0x14u, 0x29u, 0x2Du);

// NVGAMCTRL (E1h): Negative Voltage Gamma Control
// ----

	CMD_PARAMETER_14(0xE1u, 0xD0u, 0x08u, 0x10u, 0x08u, 0x06u, 0x06u, 0x39u, 0x44u, 0x51u, 0x0Bu, 0x16u, 0x14u, 0x2Fu, 0x31u);

// INVON (21h): Display Inversion On

	CMD_PARAMETER_00(0x21u);

// SLPOUT (11h): Sleep Out

	CMD_PARAMETER_00(0x11u);

// DISPON (29h): Display On

	CMD_PARAMETER_00(0x29u);
}

/*
 * \brief local_LCD_SetWindow
 *
 * - Select the window region
 *
 */
static	void	local_LCD_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t  end_y) {
	uint8_t		startMSB, startLSB;
	uint8_t		endMSB, endLSB;

// X

	startMSB = (uint8_t)((start_x>>8) & 0xFFu);
	startLSB = (uint8_t)(start_x & 0xFFu);
	endMSB	 = (uint8_t)((end_x>>8) & 0xFFu);
	endLSB	 = (uint8_t)(end_x & 0xFFu);

	local_LCD_WriteCommand(0x2Au);
	local_LCD_WriteData(startMSB);
	local_LCD_WriteData(startLSB);
	local_LCD_WriteData(endMSB);
	local_LCD_WriteData(endLSB);

// Y

	startMSB = (uint8_t)((start_y>>8) & 0xFFu);
	startLSB = (uint8_t)(start_y & 0xFFu);
	endMSB	 = (uint8_t)((end_y>>8) & 0xFFu);
	endLSB	 = (uint8_t)(end_y & 0xFFu);

	local_LCD_WriteCommand(0x2Bu);
	local_LCD_WriteData(startMSB);
	local_LCD_WriteData(startLSB);
	local_LCD_WriteData(endMSB);
	local_LCD_WriteData(endLSB);
}

/*
 * \brief local_LCD_WriteCommand
 *
 * - Write a command
 *
 */
static	void	local_LCD_WriteCommand(uint8_t command) {
	uint8_t		rwData = command;

	REG(GPIOE)->ODR &= (uint32_t)~(1u<<BLCD_DC);
	REG(GPIOE)->ODR &= (uint32_t)~(1u<<BLCD_CS);

	spi_writeRead(KSPI0, &rwData);
	REG(GPIOE)->ODR |= (1u<<BLCD_CS);
	REG(GPIOE)->ODR |= (1u<<BLCD_DC);
}

/*
 * \brief local_LCD_WriteData
 *
 * - Write a data
 *
 */
static	void	local_LCD_WriteData(uint8_t data) {
	uint8_t		rwData = data;

	REG(GPIOE)->ODR |=			  (1u<<BLCD_DC);
	REG(GPIOE)->ODR &= (uint32_t)~(1u<<BLCD_CS);

	spi_writeRead(KSPI0, &rwData);
	REG(GPIOE)->ODR |= (1u<<BLCD_CS);
}
