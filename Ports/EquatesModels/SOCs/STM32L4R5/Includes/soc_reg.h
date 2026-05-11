/*
; stm32L4R5.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5 equates.
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
#include	"Registers/stm32L4R5_adc.h"
#include	"Registers/stm32L4R5_adc_common.h"
#include	"Registers/stm32L4R5_aes.h"
#include	"Registers/stm32L4R5_can.h"
#include	"Registers/stm32L4R5_comp.h"
#include	"Registers/stm32L4R5_crc.h"
#include	"Registers/stm32L4R5_crs.h"
#include	"Registers/stm32L4R5_dac.h"
#include	"Registers/stm32L4R5_dbgmcu.h"
#include	"Registers/stm32L4R5_dcmi.h"
#include	"Registers/stm32L4R5_dfsdm.h"
#include	"Registers/stm32L4R5_dma.h"
#include	"Registers/stm32L4R5_dma2d.h"
#include	"Registers/stm32L4R5_dmamux.h"
#include	"Registers/stm32L4R5_exti.h"
#include	"Registers/stm32L4R5_firewall.h"
#include	"Registers/stm32L4R5_flash.h"
#include	"Registers/stm32L4R5_fmc.h"
#include	"Registers/stm32L4R5_gfxmmu.h"
#include	"Registers/stm32L4R5_gpioa.h"
#include	"Registers/stm32L4R5_gpiob.h"
#include	"Registers/stm32L4R5_gpioc.h"
#include	"Registers/stm32L4R5_gpiod.h"
#include	"Registers/stm32L4R5_gpioe.h"
#include	"Registers/stm32L4R5_gpiof.h"
#include	"Registers/stm32L4R5_gpiog.h"
#include	"Registers/stm32L4R5_gpioh.h"
#include	"Registers/stm32L4R5_gpioi.h"
#include	"Registers/stm32L4R5_hash.h"
#include	"Registers/stm32L4R5_i2c.h"
#include	"Registers/stm32L4R5_iwdg.h"
#include	"Registers/stm32L4R5_lcd.h"
#include	"Registers/stm32L4R5_lptim.h"
#include	"Registers/stm32L4R5_lpuart1.h"
#include	"Registers/stm32L4R5_octospi.h"
#include	"Registers/stm32L4R5_octospim.h"
#include	"Registers/stm32L4R5_opamp.h"
#include	"Registers/stm32L4R5_otg_fs_device.h"
#include	"Registers/stm32L4R5_otg_fs_global.h"
#include	"Registers/stm32L4R5_otg_fs_host.h"
#include	"Registers/stm32L4R5_otg_fs_pwrclk.h"
#include	"Registers/stm32L4R5_pwr.h"
#include	"Registers/stm32L4R5_rcc.h"
#include	"Registers/stm32L4R5_rng.h"
#include	"Registers/stm32L4R5_rtc.h"
#include	"Registers/stm32L4R5_sai.h"
#include	"Registers/stm32L4R5_sdio.h"
#include	"Registers/stm32L4R5_spi.h"
#include	"Registers/stm32L4R5_stk.h"
#include	"Registers/stm32L4R5_swpmi.h"
#include	"Registers/stm32L4R5_syscfg.h"
#include	"Registers/stm32L4R5_tim1.h"
#include	"Registers/stm32L4R5_tim15.h"
#include	"Registers/stm32L4R5_tim16.h"
#include	"Registers/stm32L4R5_tim17.h"
#include	"Registers/stm32L4R5_tim2.h"
#include	"Registers/stm32L4R5_tim3.h"
#include	"Registers/stm32L4R5_tim4.h"
#include	"Registers/stm32L4R5_tim5.h"
#include	"Registers/stm32L4R5_tim6.h"
#include	"Registers/stm32L4R5_tim7.h"
#include	"Registers/stm32L4R5_tim8.h"
#include	"Registers/stm32L4R5_tsc.h"
#include	"Registers/stm32L4R5_uart4.h"
#include	"Registers/stm32L4R5_uart5.h"
#include	"Registers/stm32L4R5_usart1.h"
#include	"Registers/stm32L4R5_usart2.h"
#include	"Registers/stm32L4R5_usart3.h"
#include	"Registers/stm32L4R5_vref.h"
#include	"Registers/stm32L4R5_wwdg.h"
#include	"Registers/soc_addendum.h"

// IWYU pragma: end_exports
