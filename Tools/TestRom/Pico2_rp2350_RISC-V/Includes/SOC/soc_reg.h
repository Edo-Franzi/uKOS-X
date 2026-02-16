/*
; RP2350.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx equates.
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

// IWYU pragma: begin_exports

#include	<stdint.h>

#include	"Registers/soc_vectors.h"
#include	"Registers/RP2350_accessctrl.h"
#include	"Registers/RP2350_adc.h"
#include	"Registers/RP2350_bootram.h"
#include	"Registers/RP2350_busctrl.h"
#include	"Registers/RP2350_clocks.h"
#include	"Registers/RP2350_coresight_trace.h"
#include	"Registers/RP2350_dma.h"
#include	"Registers/RP2350_eppb.h"
#include	"Registers/RP2350_glitch_detector.h"
#include	"Registers/RP2350_hstx_ctrl.h"
#include	"Registers/RP2350_hstx_fifo.h"
#include	"Registers/RP2350_i2c.h"
#include	"Registers/RP2350_io_bank0.h"
#include	"Registers/RP2350_io_qspi.h"
#include	"Registers/RP2350_otp.h"
#include	"Registers/RP2350_otp_data.h"
#include	"Registers/RP2350_otp_data_raw.h"
#include	"Registers/RP2350_pads_bank0.h"
#include	"Registers/RP2350_pads_qspi.h"
#include	"Registers/RP2350_pio.h"
#include	"Registers/RP2350_pll_sys.h"
#include	"Registers/RP2350_powman.h"
#include	"Registers/RP2350_ppb.h"
#include	"Registers/RP2350_psm.h"
#include	"Registers/RP2350_pwm.h"
#include	"Registers/RP2350_qmi.h"
#include	"Registers/RP2350_resets.h"
#include	"Registers/RP2350_rosc.h"
#include	"Registers/RP2350_sha256.h"
#include	"Registers/RP2350_sio.h"
#include	"Registers/RP2350_spi.h"
#include	"Registers/RP2350_syscfg.h"
#include	"Registers/RP2350_sysinfo.h"
#include	"Registers/RP2350_tbman.h"
#include	"Registers/RP2350_ticks.h"
#include	"Registers/RP2350_timer.h"
#include	"Registers/RP2350_trng.h"
#include	"Registers/RP2350_uart.h"
#include	"Registers/RP2350_usb.h"
#include	"Registers/RP2350_usb_dpram.h"
#include	"Registers/RP2350_watchdog.h"
#include	"Registers/RP2350_xip_aux.h"
#include	"Registers/RP2350_xip_ctrl.h"
#include	"Registers/RP2350_xosc.h"
#include	"Registers/soc_addendum.h"

// IWYU pragma: end_exports
