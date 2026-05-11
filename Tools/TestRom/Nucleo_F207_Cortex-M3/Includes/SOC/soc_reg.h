/*
; stm32F217.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217 equates.
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

#include	"Registers/soc_vectors.h"
#include	"Registers/stm32F217_adc1.h"
#include	"Registers/stm32F217_adc2.h"
#include	"Registers/stm32F217_adc3.h"
#include	"Registers/stm32F217_adc_common.h"
#include	"Registers/stm32F217_can.h"
#include	"Registers/stm32F217_crc.h"
#include	"Registers/stm32F217_cryp.h"
#include	"Registers/stm32F217_dac.h"
#include	"Registers/stm32F217_dbg.h"
#include	"Registers/stm32F217_dcmi.h"
#include	"Registers/stm32F217_dma.h"
#include	"Registers/stm32F217_ethernet_dma.h"
#include	"Registers/stm32F217_ethernet_mac.h"
#include	"Registers/stm32F217_ethernet_mmc.h"
#include	"Registers/stm32F217_ethernet_ptp.h"
#include	"Registers/stm32F217_exti.h"
#include	"Registers/stm32F217_flash.h"
#include	"Registers/stm32F217_fsmc.h"
#include	"Registers/stm32F217_gpio.h"
#include	"Registers/stm32F217_hash.h"
#include	"Registers/stm32F217_i2c.h"
#include	"Registers/stm32F217_iwdg.h"
#include	"Registers/stm32F217_otg_fs_device.h"
#include	"Registers/stm32F217_otg_fs_global.h"
#include	"Registers/stm32F217_otg_fs_host.h"
#include	"Registers/stm32F217_otg_fs_pwrclk.h"
#include	"Registers/stm32F217_otg_hs_device.h"
#include	"Registers/stm32F217_otg_hs_global.h"
#include	"Registers/stm32F217_otg_hs_host.h"
#include	"Registers/stm32F217_otg_hs_pwrclk.h"
#include	"Registers/stm32F217_pwr.h"
#include	"Registers/stm32F217_rcc.h"
#include	"Registers/stm32F217_rng.h"
#include	"Registers/stm32F217_rtc.h"
#include	"Registers/stm32F217_sdio.h"
#include	"Registers/stm32F217_spi.h"
#include	"Registers/stm32F217_stk.h"
#include	"Registers/stm32F217_syscfg.h"
#include	"Registers/stm32F217_tim1.h"
#include	"Registers/stm32F217_tim10.h"
#include	"Registers/stm32F217_tim11.h"
#include	"Registers/stm32F217_tim12.h"
#include	"Registers/stm32F217_tim13.h"
#include	"Registers/stm32F217_tim14.h"
#include	"Registers/stm32F217_tim2.h"
#include	"Registers/stm32F217_tim3.h"
#include	"Registers/stm32F217_tim4.h"
#include	"Registers/stm32F217_tim5.h"
#include	"Registers/stm32F217_tim6.h"
#include	"Registers/stm32F217_tim7.h"
#include	"Registers/stm32F217_tim8.h"
#include	"Registers/stm32F217_tim9.h"
#include	"Registers/stm32F217_uart4.h"
#include	"Registers/stm32F217_uart5.h"
#include	"Registers/stm32F217_usart1.h"
#include	"Registers/stm32F217_usart2.h"
#include	"Registers/stm32F217_usart3.h"
#include	"Registers/stm32F217_usart6.h"
#include	"Registers/stm32F217_wwdg.h"
#include	"Registers/soc_addendum.h"

// IWYU pragma: end_exports
