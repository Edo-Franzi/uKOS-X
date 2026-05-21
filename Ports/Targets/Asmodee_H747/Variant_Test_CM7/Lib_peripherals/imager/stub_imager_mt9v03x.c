/*
; stub_imager_mt9v03x.
; ====================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the connection of the "imager" manager to the imager,
;			MT9V03x device.
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
#include	"MT9V03x/MT9V03x.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define	model_imager_init			stub_imager_init
#define	model_imager_configure		stub_imager_configure
#define	model_imager_acquisition	stub_imager_acquisition
#define	model_imager_read			stub_imager_read
#define	model_imager_readRegister	stub_imager_readRegister
#define	model_imager_writeRegister	stub_imager_writeRegister
#define	model_imager_standby		stub_imager_standby
#define	model_imager_exposure		stub_imager_exposure

#define	KIMAGER_DCMI_SEMA_IM_S
#undef	KIMAGER_DCMI_SEMA_VS_S
#define	KIMAGER_DCMI_SEMAPHORE_IM	KIMAGER_SEMAPHORE_IM
#define	KIMAGER_DCMI_SEMAPHORE_VS	KIMAGER_SEMAPHORE_VS

#define KIMAGER_PIXEL_CLOCK_MHZ		27u
#define KIMAGER_TOTAL_HORIZONTALE	(752u + 94u)

enum {
		KIMG_INIT = 0u,
		KIMG_TRIGGER,
		KIMG_STANDBY,
		KIMG_NORMAL,
		KIMG_PIXEL_MODE,
		KIMG_EXPOSITION
};

extern	volatile	uint8_t		vAcqPage;

// Prototypes

static	int32_t	local_setAptina(mt9v03x_t *cnfTable);

// Model callbacks
// ---------------

/*
 * \brief cb_control
 *
 * - Control of the imager
 *   - Initialise
 *   - Trigger
 *   - Imager in standby mode
 *   - Imager in normal mode
 *   - Pixel mode
 *   - Exposure time
 *
 */
static	int32_t	cb_control(uint8_t mode, uint32_t value) {
					uint16_t	agc, grossExpTime, fineExpTime, lineLength;
					int32_t		status = KERR_IMAGER_NOERR;
	static	const	i2cCnf_t	configureI2C0 = {
									.oTimeout  = 1000u,
									.oSpeed    = KI2C_100KBPS,
								};

	switch (mode) {
		case KIMG_INIT: {
			GPIOJ->ODR |= (1u<<BRZ_CAMERA);
			kern_suspendProcess(10u);
			GPIOJ->ODR &= (uint32_t)~(1u<<BRZ_CAMERA);
			kern_suspendProcess(10u);
			GPIOJ->ODR |= (1u<<BRZ_CAMERA);

			GPIOJ->ODR |= (1u<<BEN_CLK);
			kern_suspendProcess(10u);
			GPIOD->ODR &= (uint32_t)~(1u<<BSTANDBY);
			GPIOD->ODR &= (uint32_t)~(1u<<BEXPOSURE);

// Initialise the i2c0

			RESERVE(I2C0, KMODE_READ_WRITE);
			status = i2c_configure(KI2C0, &configureI2C0);
			status = (status == KERR_I2C_NOERR) ? (KERR_IMAGER_NOERR) : (KERR_IMAGER_TIMEO);
			RELEASE(I2C0, KMODE_READ_WRITE);
			break;
		}
		case KIMG_TRIGGER: {
			GPIOD->ODR |= (1u<<BEXPOSURE);
			kern_waitAtLeast(20u);
			GPIOD->ODR &= (uint32_t)~(1u<<BEXPOSURE);
			break;
		}
		case KIMG_STANDBY: {
			GPIOD->ODR |= (1u<<BSTANDBY);
			kern_suspendProcess(10u);
			GPIOJ->ODR &= (uint32_t)~(1u<<BEN_CLK);
			break;
		}
		case KIMG_NORMAL: {
			GPIOJ->ODR |= (1u<<BEN_CLK);
			kern_suspendProcess(10u);
			GPIOD->ODR &= (uint32_t)~(1u<<BSTANDBY);
			break;
		}
		case KIMG_PIXEL_MODE: {
			break;
		}
		case KIMG_EXPOSITION: {
			agc = 1;
			if (value != UINT32_MAX) {
				agc = 0u;
				lineLength = KIMAGER_TOTAL_HORIZONTALE;

				grossExpTime = (uint16_t)((value * KIMAGER_PIXEL_CLOCK_MHZ) / lineLength);
				fineExpTime  = (uint16_t)((value - (uint32_t)((grossExpTime * lineLength) / KIMAGER_PIXEL_CLOCK_MHZ)) * KIMAGER_PIXEL_CLOCK_MHZ);

				imager_writeRegister(KMT9V03x_EXPOSURE, grossExpTime);
				imager_writeRegister(KMT9V03x_FINE_EXPOSURE, fineExpTime);
			}
			imager_writeRegister(KMT9V03x_AUTOMATIC_EXPOSURE, agc);
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	return (status);
}

/*
 * \brief cb_getRegister
 *
 * - Read an imager register
 *
 */
static	int32_t	cb_getRegister(uint8_t registerNb, uint16_t *value) {
	uint8_t		buffer[2];
	int32_t		status;

	buffer[0] = registerNb;

	RESERVE(I2C0, KMODE_READ_WRITE);
	status = i2c_read(KI2C0, KI2C_ADD_MT9V03x, &buffer[0], 2u);
	status = (status == KERR_I2C_NOERR) ? (KERR_IMAGER_NOERR) : (KERR_IMAGER_TIMEO);
	RELEASE(I2C0, KMODE_READ_WRITE);

	*value = (uint16_t)((buffer[0]<<8u) | buffer[1]);
	return (status);
}

/*
 * \brief cb_putRegister
 *
 * - Write an imager register
 *
 */
static	int32_t	cb_putRegister(uint8_t registerNb, uint16_t value) {
	uint8_t		buffer[3];
	int32_t		status;

	buffer[0] = registerNb;
	buffer[1] = (uint8_t)(value>>8u);
	buffer[2] = (uint8_t)value;

	RESERVE(I2C0, KMODE_READ_WRITE);
	status = i2c_write(KI2C0, KI2C_ADD_MT9V03x, &buffer[0], 3u);
	status = (status == KERR_I2C_NOERR) ? (KERR_IMAGER_NOERR) : (KERR_IMAGER_TIMEO);
	RELEASE(I2C0, KMODE_READ_WRITE);

	return (status);
}

/*
 * \brief cb_configure
 *
 * - Configure the imager
 *
 */
static	int32_t	cb_configure(const imagerCnf_t *configure) {
	int32_t		status = KERR_IMAGER_NOERR;

// Configure the sensitivity to the synchro polarity
// Pixel clock -> active H
// Horizontal  -> active L
// Vertical    -> active L

	DCMI->CR &= (uint32_t)~(DCMI_CR_VSPOL | DCMI_CR_HSPOL | DCMI_CR_PCKPOL);
	DCMI->CR |= DCMI_CR_PCKPOL;

// The full Aptina registers configuration including ROI, exposure,
// gain, shutters, interface and control
// Set the vertical blanking to 4 lines
// Set the horizontal blanking to 1000 pixels (to allow to deserve the DCMI line DMA)
// Set SNAPSHOT + SEQUENTIAL + SLAVE mode

	status = cb_putRegister(KMT9V03x_V_BLANK, 0x0004u);				if (status != KERR_IMAGER_NOERR) { return (status); }
	status = cb_putRegister(KMT9V03x_REG20,   0x03C7u);				if (status != KERR_IMAGER_NOERR) { return (status); }
	status = cb_putRegister(KMT9V03x_REG24,   0x001Bu);				if (status != KERR_IMAGER_NOERR) { return (status); }
	status = cb_putRegister(KMT9V03x_REG2B,   0x0003u);				if (status != KERR_IMAGER_NOERR) { return (status); }
	status = cb_putRegister(KMT9V03x_REG2F,   0x0003u);				if (status != KERR_IMAGER_NOERR) { return (status); }
	status = cb_putRegister(KMT9V03x_H_BLANK,   1000u);				if (status != KERR_IMAGER_NOERR) { return (status); }

	if (configure->oAcqMode == KIMAGER_SNAP) {
		status = cb_putRegister(KMT9V03x_CTRL_REG, 0x0398u);		if (status != KERR_IMAGER_NOERR) { return (status); }
	}
	if (configure->oImgCnf != nullptr) {
		status = local_setAptina((mt9v03x_t *)configure->oImgCnf);	if (status != KERR_IMAGER_NOERR) { return (status); }
	}
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_setAptina
 *
 */
static	int32_t	local_setAptina(mt9v03x_t *cnfTable) {
	uint8_t		buffer[3];
	uint16_t	i = 0u;
	int32_t		status;

	RESERVE(I2C0, KMODE_READ_WRITE);
	while (true) {
		buffer[0] = cnfTable[i].oRegNumber;
		buffer[1] = (uint8_t)(cnfTable[i].oValue>>8);
		buffer[2] = (uint8_t)cnfTable[i].oValue;

		if ((buffer[0] == 0u) && (i > 0u)) { RELEASE(I2C0, KMODE_READ_WRITE); return (KERR_IMAGER_NOERR); }
		i++;

		status = i2c_write(KI2C0, KI2C_ADD_MT9V03x, &buffer[0], 3u);
		status = (status == KERR_I2C_NOERR) ? (KERR_IMAGER_NOERR) : (KERR_IMAGER_TIMEO);
		if (status != KERR_IMAGER_NOERR) { RELEASE(I2C0, KMODE_READ_WRITE); return (status); }
	}
}

#include	"model_imager_dcmi_dma2.c_inc"
