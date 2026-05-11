/*
; stm32U5Gx.
; ==========

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

#include	"Registers/soc_vectors.h"
#include	"Registers/stm32U5Gx_adc1.h"
#include	"Registers/stm32U5Gx_adc12_common.h"
#include	"Registers/stm32U5Gx_adc2.h"
#include	"Registers/stm32U5Gx_adc4.h"
#include	"Registers/stm32U5Gx_adf.h"
#include	"Registers/stm32U5Gx_aes.h"
#include	"Registers/stm32U5Gx_comp.h"
#include	"Registers/stm32U5Gx_cordic.h"
#include	"Registers/stm32U5Gx_crc.h"
#include	"Registers/stm32U5Gx_crs.h"
#include	"Registers/stm32U5Gx_dac.h"
#include	"Registers/stm32U5Gx_dbgmcu.h"
#include	"Registers/stm32U5Gx_dcache.h"
#include	"Registers/stm32U5Gx_dcb.h"
#include	"Registers/stm32U5Gx_dcmi.h"
#include	"Registers/stm32U5Gx_dlyb.h"
#include	"Registers/stm32U5Gx_dma2d.h"
#include	"Registers/stm32U5Gx_exti.h"
#include	"Registers/stm32U5Gx_fdcan.h"
#include	"Registers/stm32U5Gx_flash.h"
#include	"Registers/stm32U5Gx_fmac.h"
#include	"Registers/stm32U5Gx_fmc.h"
#include	"Registers/stm32U5Gx_gfxmmu.h"
#include	"Registers/stm32U5Gx_gfxtim.h"
#include	"Registers/stm32U5Gx_gpdma.h"
#include	"Registers/stm32U5Gx_gpio.h"
#include	"Registers/stm32U5Gx_gtzc1_mpcbb1.h"
#include	"Registers/stm32U5Gx_gtzc1_mpcbb2.h"
#include	"Registers/stm32U5Gx_gtzc1_mpcbb3.h"
#include	"Registers/stm32U5Gx_gtzc1_mpcbb5.h"
#include	"Registers/stm32U5Gx_gtzc1_mpcbb6.h"
#include	"Registers/stm32U5Gx_gtzc1_tzic.h"
#include	"Registers/stm32U5Gx_gtzc1_tzsc.h"
#include	"Registers/stm32U5Gx_gtzc2_mpcbb4.h"
#include	"Registers/stm32U5Gx_gtzc2_tzic.h"
#include	"Registers/stm32U5Gx_gtzc2_tzsc.h"
#include	"Registers/stm32U5Gx_hash.h"
#include	"Registers/stm32U5Gx_hspi.h"
#include	"Registers/stm32U5Gx_i2c.h"
#include	"Registers/stm32U5Gx_icache.h"
#include	"Registers/stm32U5Gx_iwdg.h"
#include	"Registers/stm32U5Gx_jpeg.h"
#include	"Registers/stm32U5Gx_lpdma.h"
#include	"Registers/stm32U5Gx_lpgpio.h"
#include	"Registers/stm32U5Gx_lptim.h"
#include	"Registers/stm32U5Gx_lpuart.h"
#include	"Registers/stm32U5Gx_mdf.h"
#include	"Registers/stm32U5Gx_octospi1.h"
#include	"Registers/stm32U5Gx_octospi2.h"
#include	"Registers/stm32U5Gx_octospim.h"
#include	"Registers/stm32U5Gx_opamp.h"
#include	"Registers/stm32U5Gx_otfdec.h"
#include	"Registers/stm32U5Gx_otg_hs.h"
#include	"Registers/stm32U5Gx_pka.h"
#include	"Registers/stm32U5Gx_pssi.h"
#include	"Registers/stm32U5Gx_pwr.h"
#include	"Registers/stm32U5Gx_ramcfg.h"
#include	"Registers/stm32U5Gx_rcc.h"
#include	"Registers/stm32U5Gx_rng.h"
#include	"Registers/stm32U5Gx_rtc.h"
#include	"Registers/stm32U5Gx_saes.h"
#include	"Registers/stm32U5Gx_sai.h"
#include	"Registers/stm32U5Gx_sdmmc.h"
#include	"Registers/stm32U5Gx_spi.h"
#include	"Registers/stm32U5Gx_syscfg.h"
#include	"Registers/stm32U5Gx_tamp.h"
#include	"Registers/stm32U5Gx_tim1.h"
#include	"Registers/stm32U5Gx_tim15.h"
#include	"Registers/stm32U5Gx_tim16.h"
#include	"Registers/stm32U5Gx_tim17.h"
#include	"Registers/stm32U5Gx_tim2.h"
#include	"Registers/stm32U5Gx_tim3.h"
#include	"Registers/stm32U5Gx_tim4.h"
#include	"Registers/stm32U5Gx_tim5.h"
#include	"Registers/stm32U5Gx_tim6.h"
#include	"Registers/stm32U5Gx_tim7.h"
#include	"Registers/stm32U5Gx_tim8.h"
#include	"Registers/stm32U5Gx_tsc.h"
#include	"Registers/stm32U5Gx_ucpd.h"
#include	"Registers/stm32U5Gx_usart.h"
#include	"Registers/stm32U5Gx_vref.h"
#include	"Registers/stm32U5Gx_wwdg.h"
#include	"Registers/soc_addendum.h"
#include	"Registers/stm32U5Gx_dsi.h"
#include	"Registers/stm32U5Gx_ltdc.h"

// IWYU pragma: end_exports
