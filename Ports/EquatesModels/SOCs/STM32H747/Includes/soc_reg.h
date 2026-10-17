/*
; cpu_reg.
; ========
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747 equates.
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

#if (defined(CORTEX_M4_S))

// IWYU pragma: begin_exports

#include	"Registers/soc_vectors.h"
#include	"Registers/stm32H747_CM4_adc1.h"
#include	"Registers/stm32H747_CM4_adc12_common.h"
#include	"Registers/stm32H747_CM4_adc2.h"
#include	"Registers/stm32H747_CM4_adc3.h"
#include	"Registers/stm32H747_CM4_adc3_common.h"
#include	"Registers/stm32H747_CM4_art.h"
#include	"Registers/stm32H747_CM4_axi.h"
#include	"Registers/stm32H747_CM4_bdma.h"
#include	"Registers/stm32H747_CM4_can_ccu.h"
#include	"Registers/stm32H747_CM4_cec.h"
#include	"Registers/stm32H747_CM4_comp1.h"
#include	"Registers/stm32H747_CM4_crc.h"
#include	"Registers/stm32H747_CM4_crs.h"
#include	"Registers/stm32H747_CM4_dac.h"
#include	"Registers/stm32H747_CM4_dbgmcu.h"
#include	"Registers/stm32H747_CM4_dcmi.h"
#include	"Registers/stm32H747_CM4_dfsdm.h"
#include	"Registers/stm32H747_CM4_dlyb.h"
#include	"Registers/stm32H747_CM4_dma.h"
#include	"Registers/stm32H747_CM4_dma2d.h"
#include	"Registers/stm32H747_CM4_dmamux1.h"
#include	"Registers/stm32H747_CM4_dmamux2.h"
#include	"Registers/stm32H747_CM4_dsihost.h"
#include	"Registers/stm32H747_CM4_ethernet.h"
#include	"Registers/stm32H747_CM4_exti.h"
#include	"Registers/stm32H747_CM4_fdcan1.h"
#include	"Registers/stm32H747_CM4_fdcan2.h"
#include	"Registers/stm32H747_CM4_flash.h"
#include	"Registers/stm32H747_CM4_fmc.h"
#include	"Registers/stm32H747_CM4_gpio.h"
#include	"Registers/stm32H747_CM4_hrtim_common.h"
#include	"Registers/stm32H747_CM4_hrtim_master.h"
#include	"Registers/stm32H747_CM4_hrtim_tima.h"
#include	"Registers/stm32H747_CM4_hrtim_timb.h"
#include	"Registers/stm32H747_CM4_hrtim_timc.h"
#include	"Registers/stm32H747_CM4_hrtim_timd.h"
#include	"Registers/stm32H747_CM4_hrtim_time.h"
#include	"Registers/stm32H747_CM4_hsem.h"
#include	"Registers/stm32H747_CM4_i2c.h"
#include	"Registers/stm32H747_CM4_iwdg.h"
#include	"Registers/stm32H747_CM4_jpeg.h"
#include	"Registers/stm32H747_CM4_lptim.h"
#include	"Registers/stm32H747_CM4_lpuart.h"
#include	"Registers/stm32H747_CM4_ltdc.h"
#include	"Registers/stm32H747_CM4_mdios.h"
#include	"Registers/stm32H747_CM4_mdma.h"
#include	"Registers/stm32H747_CM4_opamp.h"
#include	"Registers/stm32H747_CM4_otg1_hs_device.h"
#include	"Registers/stm32H747_CM4_otg1_hs_global.h"
#include	"Registers/stm32H747_CM4_otg1_hs_host.h"
#include	"Registers/stm32H747_CM4_otg1_hs_pwrclk.h"
#include	"Registers/stm32H747_CM4_otg2_hs_device.h"
#include	"Registers/stm32H747_CM4_otg2_hs_global.h"
#include	"Registers/stm32H747_CM4_otg2_hs_host.h"
#include	"Registers/stm32H747_CM4_otg2_hs_pwrclk.h"
#include	"Registers/stm32H747_CM4_pwr.h"
#include	"Registers/stm32H747_CM4_quadspi.h"
#include	"Registers/stm32H747_CM4_ramecc1.h"
#include	"Registers/stm32H747_CM4_ramecc2.h"
#include	"Registers/stm32H747_CM4_ramecc3.h"
#include	"Registers/stm32H747_CM4_rcc.h"
#include	"Registers/stm32H747_CM4_rng.h"
#include	"Registers/stm32H747_CM4_rtc.h"
#include	"Registers/stm32H747_CM4_sai.h"
#include	"Registers/stm32H747_CM4_sdmmc.h"
#include	"Registers/stm32H747_CM4_spdifrx.h"
#include	"Registers/stm32H747_CM4_spi.h"
#include	"Registers/stm32H747_CM4_swpmi.h"
#include	"Registers/stm32H747_CM4_syscfg.h"
#include	"Registers/stm32H747_CM4_tim1.h"
#include	"Registers/stm32H747_CM4_tim12.h"
#include	"Registers/stm32H747_CM4_tim13.h"
#include	"Registers/stm32H747_CM4_tim14.h"
#include	"Registers/stm32H747_CM4_tim15.h"
#include	"Registers/stm32H747_CM4_tim16.h"
#include	"Registers/stm32H747_CM4_tim17.h"
#include	"Registers/stm32H747_CM4_tim2.h"
#include	"Registers/stm32H747_CM4_tim3.h"
#include	"Registers/stm32H747_CM4_tim4.h"
#include	"Registers/stm32H747_CM4_tim5.h"
#include	"Registers/stm32H747_CM4_tim6.h"
#include	"Registers/stm32H747_CM4_tim7.h"
#include	"Registers/stm32H747_CM4_tim8.h"
#include	"Registers/stm32H747_CM4_usart.h"
#include	"Registers/stm32H747_CM4_vrefbuf.h"
#include	"Registers/stm32H747_CM4_wwdg.h"
#include	"Registers/soc_addendum_CM4.h"

// IWYU pragma: end_exports

#endif

#if (defined(CORTEX_M7_S))

// IWYU pragma: begin_exports

#include	"Registers/soc_vectors.h"
#include	"Registers/stm32H747_CM7_adc1.h"
#include	"Registers/stm32H747_CM7_adc12_common.h"
#include	"Registers/stm32H747_CM7_adc2.h"
#include	"Registers/stm32H747_CM7_adc3.h"
#include	"Registers/stm32H747_CM7_adc3_common.h"
#include	"Registers/stm32H747_CM7_art.h"
#include	"Registers/stm32H747_CM7_axi.h"
#include	"Registers/stm32H747_CM7_bdma.h"
#include	"Registers/stm32H747_CM7_can_ccu.h"
#include	"Registers/stm32H747_CM7_cec.h"
#include	"Registers/stm32H747_CM7_comp1.h"
#include	"Registers/stm32H747_CM7_crc.h"
#include	"Registers/stm32H747_CM7_crs.h"
#include	"Registers/stm32H747_CM7_dac.h"
#include	"Registers/stm32H747_CM7_dbgmcu.h"
#include	"Registers/stm32H747_CM7_dcmi.h"
#include	"Registers/stm32H747_CM7_dfsdm.h"
#include	"Registers/stm32H747_CM7_dlyb.h"
#include	"Registers/stm32H747_CM7_dma.h"
#include	"Registers/stm32H747_CM7_dma2d.h"
#include	"Registers/stm32H747_CM7_dmamux1.h"
#include	"Registers/stm32H747_CM7_dmamux2.h"
#include	"Registers/stm32H747_CM7_dsihost.h"
#include	"Registers/stm32H747_CM7_ethernet.h"
#include	"Registers/stm32H747_CM7_exti.h"
#include	"Registers/stm32H747_CM7_fdcan1.h"
#include	"Registers/stm32H747_CM7_fdcan2.h"
#include	"Registers/stm32H747_CM7_flash.h"
#include	"Registers/stm32H747_CM7_fmc.h"
#include	"Registers/stm32H747_CM7_gpio.h"
#include	"Registers/stm32H747_CM7_hrtim_common.h"
#include	"Registers/stm32H747_CM7_hrtim_master.h"
#include	"Registers/stm32H747_CM7_hrtim_tima.h"
#include	"Registers/stm32H747_CM7_hrtim_timb.h"
#include	"Registers/stm32H747_CM7_hrtim_timc.h"
#include	"Registers/stm32H747_CM7_hrtim_timd.h"
#include	"Registers/stm32H747_CM7_hrtim_time.h"
#include	"Registers/stm32H747_CM7_hsem.h"
#include	"Registers/stm32H747_CM7_i2c.h"
#include	"Registers/stm32H747_CM7_iwdg.h"
#include	"Registers/stm32H747_CM7_jpeg.h"
#include	"Registers/stm32H747_CM7_lptim.h"
#include	"Registers/stm32H747_CM7_lpuart.h"
#include	"Registers/stm32H747_CM7_ltdc.h"
#include	"Registers/stm32H747_CM7_mdios.h"
#include	"Registers/stm32H747_CM7_mdma.h"
#include	"Registers/stm32H747_CM7_opamp.h"
#include	"Registers/stm32H747_CM7_otg1_hs_device.h"
#include	"Registers/stm32H747_CM7_otg1_hs_global.h"
#include	"Registers/stm32H747_CM7_otg1_hs_host.h"
#include	"Registers/stm32H747_CM7_otg1_hs_pwrclk.h"
#include	"Registers/stm32H747_CM7_otg2_hs_device.h"
#include	"Registers/stm32H747_CM7_otg2_hs_global.h"
#include	"Registers/stm32H747_CM7_otg2_hs_host.h"
#include	"Registers/stm32H747_CM7_otg2_hs_pwrclk.h"
#include	"Registers/stm32H747_CM7_pwr.h"
#include	"Registers/stm32H747_CM7_quadspi.h"
#include	"Registers/stm32H747_CM7_ramecc1.h"
#include	"Registers/stm32H747_CM7_ramecc2.h"
#include	"Registers/stm32H747_CM7_ramecc3.h"
#include	"Registers/stm32H747_CM7_rcc.h"
#include	"Registers/stm32H747_CM7_rng.h"
#include	"Registers/stm32H747_CM7_rtc.h"
#include	"Registers/stm32H747_CM7_sai.h"
#include	"Registers/stm32H747_CM7_sdmmc.h"
#include	"Registers/stm32H747_CM7_spdifrx.h"
#include	"Registers/stm32H747_CM7_spi.h"
#include	"Registers/stm32H747_CM7_swpmi.h"
#include	"Registers/stm32H747_CM7_syscfg.h"
#include	"Registers/stm32H747_CM7_tim1.h"
#include	"Registers/stm32H747_CM7_tim12.h"
#include	"Registers/stm32H747_CM7_tim13.h"
#include	"Registers/stm32H747_CM7_tim14.h"
#include	"Registers/stm32H747_CM7_tim15.h"
#include	"Registers/stm32H747_CM7_tim16.h"
#include	"Registers/stm32H747_CM7_tim17.h"
#include	"Registers/stm32H747_CM7_tim2.h"
#include	"Registers/stm32H747_CM7_tim3.h"
#include	"Registers/stm32H747_CM7_tim4.h"
#include	"Registers/stm32H747_CM7_tim5.h"
#include	"Registers/stm32H747_CM7_tim6.h"
#include	"Registers/stm32H747_CM7_tim7.h"
#include	"Registers/stm32H747_CM7_tim8.h"
#include	"Registers/stm32H747_CM7_usart.h"
#include	"Registers/stm32H747_CM7_vrefbuf.h"
#include	"Registers/stm32H747_CM7_wwdg.h"
#include	"Registers/soc_addendum_CM7.h"

// IWYU pragma: end_exports

#endif
