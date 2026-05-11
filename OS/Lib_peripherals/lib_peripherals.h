/*
; lib_peripherals.
; ================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		lib_peripherals system call interface module.
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
 * \defgroup Lib_peripherals Library for handling the peripherals
 *
 * \brief Peripheral manager system calls
 *
 * The Lib_peripherals library provides managers for the many devices that
 * link a system to the real world. Each manager ensures control and clarity.
 *
 * The adc manager reads analogue inputs, turning voltage into digital data
 * that can be measured, stored, and acted upon with precision.
 *
 * The battery manager observes charge and discharge, protecting energy and
 * extending the life of the system with careful supervision.
 *
 * The i2c manager opens a channel for two-wire communication. It enables
 * sensors and modules to share information in a simple, ordered way.
 *
 * The imager manager captures pictures and streams, bringing vision into
 * embedded design and allowing machines to perceive their environment.
 *
 * The imu manager delivers motion and orientation through an inertial unit.
 * It makes navigation possible and supports balance and control.
 *
 * The spi manager manages fast serial links. Devices exchange data at high
 * speed with low overhead, keeping systems both agile and efficient.
 *
 * The led manager provides clear signals of state. A flash of light tells
 * the user what the system feels, whether alert, calm, or in fault.
 *
 * The switch manager handles digital inputs. A press or release becomes a
 * firm command, giving the user direct influence over the machine.
 *
 * The temperature manager measures heat and ensures stability. It allows
 * the system to adjust, protect itself, and maintain safe operation.
 *
 * The watchdog manager safeguards the system. If a fault prevents progress,
 * the watchdog restores order by resetting and recovering control.
 *
 * Together these managers give Lib_peripherals the means to sense, signal,
 * and survive. They turn a circuit into a responsive and reliable partner.
 *
 * @{
 */

// IWYU pragma: begin_exports

#if (defined(CONFIG_MAN_SPI_S))
#include	"spi/spi.h"
#endif
#if (defined(CONFIG_MAN_SPI0_S))
#include	"spi0/spi0.h"
#endif
#if (defined(CONFIG_MAN_SPI1_S))
#include	"spi1/spi1.h"
#endif
#if (defined(CONFIG_MAN_SPI2_S))
#include	"spi2/spi2.h"
#endif
#if (defined(CONFIG_MAN_SPI3_S))
#include	"spi3/spi3.h"
#endif
#if (defined(CONFIG_MAN_I2C_S))
#include	"i2c/i2c.h"
#endif
#if (defined(CONFIG_MAN_I2C0_S))
#include	"i2c0/i2c0.h"
#endif
#if (defined(CONFIG_MAN_I2C1_S))
#include	"i2c1/i2c1.h"
#endif
#if (defined(CONFIG_MAN_I2C2_S))
#include	"i2c2/i2c2.h"
#endif
#if (defined(CONFIG_MAN_I2C3_S))
#include	"i2c3/i2c3.h"
#endif
#if (defined(CONFIG_MAN_ADC_S))
#include	"adc/adc.h"
#endif
#if (defined(CONFIG_MAN_BATTERY_S))
#include	"battery/battery.h"
#endif
#if (defined(CONFIG_MAN_IMAGER_S))
#include	"imager/imager.h"
#endif
#if (defined(CONFIG_MAN_IMU_S))
#include	"imu/imu.h"
#endif
#if (defined(CONFIG_MAN_TEMPERATURE_S))
#include	"temperature/temperature.h"
#endif
#if (defined(CONFIG_MAN_WATCHDOG_S))
#include	"watchdog/watchdog.h"
#endif
#if (defined(CONFIG_MAN_LED_S))
#include	"led/led.h"
#endif
#if (defined(CONFIG_MAN_SWITCH_S))
#include	"switch/switch.h"
#endif

// IWYU pragma: end_exports

/**!@}*/
