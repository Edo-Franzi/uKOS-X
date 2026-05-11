/*
; stm32H743.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743 equates.
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
#include	"Registers/stm32H743_adc1.h"
#include	"Registers/stm32H743_adc12_common.h"
#include	"Registers/stm32H743_adc2.h"
#include	"Registers/stm32H743_adc3.h"
#include	"Registers/stm32H743_adc3_common.h"
#include	"Registers/stm32H743_axi.h"
#include	"Registers/stm32H743_bdma.h"
#include	"Registers/stm32H743_can_ccu.h"
#include	"Registers/stm32H743_cec.h"
#include	"Registers/stm32H743_comp1.h"
#include	"Registers/stm32H743_crc.h"
#include	"Registers/stm32H743_crs.h"
#include	"Registers/stm32H743_dac.h"
#include	"Registers/stm32H743_dbgmcu.h"
#include	"Registers/stm32H743_dcmi.h"
#include	"Registers/stm32H743_dfsdm.h"
#include	"Registers/stm32H743_dlyb.h"
#include	"Registers/stm32H743_dma.h"
#include	"Registers/stm32H743_dma2d.h"
#include	"Registers/stm32H743_dmamux1.h"
#include	"Registers/stm32H743_dmamux2.h"
#include	"Registers/stm32H743_ethernet_dma.h"
#include	"Registers/stm32H743_ethernet_mac.h"
#include	"Registers/stm32H743_ethernet_mtl.h"
#include	"Registers/stm32H743_exti.h"
#include	"Registers/stm32H743_fdcan1.h"
#include	"Registers/stm32H743_fdcan2.h"
#include	"Registers/stm32H743_flash.h"
#include	"Registers/stm32H743_fmc.h"
#include	"Registers/stm32H743_gpio.h"
#include	"Registers/stm32H743_hrtim_common.h"
#include	"Registers/stm32H743_hrtim_master.h"
#include	"Registers/stm32H743_hrtim_tima.h"
#include	"Registers/stm32H743_hrtim_timb.h"
#include	"Registers/stm32H743_hrtim_timc.h"
#include	"Registers/stm32H743_hrtim_timd.h"
#include	"Registers/stm32H743_hrtim_time.h"
#include	"Registers/stm32H743_hsem.h"
#include	"Registers/stm32H743_i2c.h"
#include	"Registers/stm32H743_iwdg.h"
#include	"Registers/stm32H743_jpeg.h"
#include	"Registers/stm32H743_lptim.h"
#include	"Registers/stm32H743_lpuart.h"
#include	"Registers/stm32H743_ltdc.h"
#include	"Registers/stm32H743_mdios.h"
#include	"Registers/stm32H743_mdma.h"
#include	"Registers/stm32H743_opamp.h"
#include	"Registers/stm32H743_otg1_hs_device.h"
#include	"Registers/stm32H743_otg1_hs_global.h"
#include	"Registers/stm32H743_otg1_hs_host.h"
#include	"Registers/stm32H743_otg1_hs_pwrclk.h"
#include	"Registers/stm32H743_otg2_hs_device.h"
#include	"Registers/stm32H743_otg2_hs_global.h"
#include	"Registers/stm32H743_otg2_hs_host.h"
#include	"Registers/stm32H743_otg2_hs_pwrclk.h"
#include	"Registers/stm32H743_pwr.h"
#include	"Registers/stm32H743_quadspi.h"
#include	"Registers/stm32H743_ramecc1.h"
#include	"Registers/stm32H743_ramecc2.h"
#include	"Registers/stm32H743_ramecc3.h"
#include	"Registers/stm32H743_rcc.h"
#include	"Registers/stm32H743_rng.h"
#include	"Registers/stm32H743_rtc.h"
#include	"Registers/stm32H743_sai.h"
#include	"Registers/stm32H743_sdmmc.h"
#include	"Registers/stm32H743_spdifrx.h"
#include	"Registers/stm32H743_spi.h"
#include	"Registers/stm32H743_swpmi.h"
#include	"Registers/stm32H743_syscfg.h"
#include	"Registers/stm32H743_tim1.h"
#include	"Registers/stm32H743_tim12.h"
#include	"Registers/stm32H743_tim13.h"
#include	"Registers/stm32H743_tim14.h"
#include	"Registers/stm32H743_tim15.h"
#include	"Registers/stm32H743_tim16.h"
#include	"Registers/stm32H743_tim17.h"
#include	"Registers/stm32H743_tim2.h"
#include	"Registers/stm32H743_tim3.h"
#include	"Registers/stm32H743_tim4.h"
#include	"Registers/stm32H743_tim5.h"
#include	"Registers/stm32H743_tim6.h"
#include	"Registers/stm32H743_tim7.h"
#include	"Registers/stm32H743_tim8.h"
#include	"Registers/stm32H743_usart.h"
#include	"Registers/stm32H743_vrefbuf.h"
#include	"Registers/stm32H743_wwdg.h"
#include	"Registers/soc_addendum.h"

// IWYU pragma: end_exports
