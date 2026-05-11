/*
; GD32VF103.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103 equates.
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

// Some includes are not necessary because
// addendum contains the skipped definitions.

#define		KDEFINED_IN_ADDENDUM_S

// IWYU pragma: begin_exports

#include	"Registers/soc_vectors.h"
#include	"Registers/GD32VF103_adc0.h"
#include	"Registers/GD32VF103_adc1.h"
#include	"Registers/GD32VF103_afio.h"
#include	"Registers/GD32VF103_bkp.h"
#include	"Registers/GD32VF103_can.h"
#include	"Registers/GD32VF103_crc.h"
#include	"Registers/GD32VF103_dac.h"
#include	"Registers/GD32VF103_dbg.h"
#include	"Registers/GD32VF103_dma0.h"
#include	"Registers/GD32VF103_dma1.h"

#if (!defined(KDEFINED_IN_ADDENDUM_S))
#include	"Registers/GD32VF103_eclic.h"
#endif

#include	"Registers/GD32VF103_exmc.h"
#include	"Registers/GD32VF103_exti.h"
#include	"Registers/GD32VF103_fmc.h"
#include	"Registers/GD32VF103_fwdgt.h"
#include	"Registers/GD32VF103_gpio.h"
#include	"Registers/GD32VF103_i2c.h"
#include	"Registers/GD32VF103_pmu.h"
#include	"Registers/GD32VF103_rcu.h"
#include	"Registers/GD32VF103_rtc.h"
#include	"Registers/GD32VF103_spi.h"
#include	"Registers/GD32VF103_timer0.h"
#include	"Registers/GD32VF103_timer1.h"
#include	"Registers/GD32VF103_timer2.h"
#include	"Registers/GD32VF103_timer3.h"
#include	"Registers/GD32VF103_timer4.h"
#include	"Registers/GD32VF103_timer5.h"
#include	"Registers/GD32VF103_timer6.h"
#include	"Registers/GD32VF103_uart.h"
#include	"Registers/GD32VF103_usart.h"
#include	"Registers/GD32VF103_usbfs_device.h"
#include	"Registers/GD32VF103_usbfs_global.h"
#include	"Registers/GD32VF103_usbfs_host.h"
#include	"Registers/GD32VF103_usbfs_pwrclk.h"
#include	"Registers/GD32VF103_wwdgt.h"
#include	"Registers/soc_addendum.h"

// IWYU pragma: end_exports
