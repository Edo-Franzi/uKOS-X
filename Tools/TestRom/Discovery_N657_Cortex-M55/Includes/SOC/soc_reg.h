/*
; stm32N657.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657 equates.
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
#include	"Registers/stm32N657_adc.h"
#include	"Registers/stm32N657_adc12.h"
#include	"Registers/stm32N657_adf.h"
#include	"Registers/stm32N657_bsec.h"
#include	"Registers/stm32N657_cacheaxi.h"
#include	"Registers/stm32N657_crc.h"
#include	"Registers/stm32N657_cryp.h"
#include	"Registers/stm32N657_csi.h"
#include	"Registers/stm32N657_dbgmcu.h"
#include	"Registers/stm32N657_dcmi.h"
#include	"Registers/stm32N657_dcmipp.h"
#include	"Registers/stm32N657_dlybsd.h"
#include	"Registers/stm32N657_dma2d.h"
#include	"Registers/stm32N657_dts.h"
#include	"Registers/stm32N657_eth.h"
#include	"Registers/stm32N657_exti.h"
#include	"Registers/stm32N657_fdcan.h"
#include	"Registers/stm32N657_fmc.h"
#include	"Registers/stm32N657_gfxmmu.h"
#include	"Registers/stm32N657_gfxtim.h"
#include	"Registers/stm32N657_gpdma.h"
#include	"Registers/stm32N657_gpio.h"
#include	"Registers/stm32N657_gpiob.h"
#include	"Registers/stm32N657_gpioc.h"
#include	"Registers/stm32N657_gpiod.h"
#include	"Registers/stm32N657_gpioe.h"
#include	"Registers/stm32N657_gpiof.h"
#include	"Registers/stm32N657_gpiog.h"
#include	"Registers/stm32N657_gpioh.h"
#include	"Registers/stm32N657_gpion.h"
#include	"Registers/stm32N657_gpioo.h"
#include	"Registers/stm32N657_gpiop.h"
#include	"Registers/stm32N657_gpioq.h"
#include	"Registers/stm32N657_hash.h"
#include	"Registers/stm32N657_hdp.h"
#include	"Registers/stm32N657_hpdma.h"
#include	"Registers/stm32N657_i2c.h"
#include	"Registers/stm32N657_i3c.h"
#include	"Registers/stm32N657_icache.h"
#include	"Registers/stm32N657_iwdg.h"
#include	"Registers/stm32N657_jpeg.h"
#include	"Registers/stm32N657_lptim.h"
#include	"Registers/stm32N657_lpuart.h"
#include	"Registers/stm32N657_ltdc.h"
#include	"Registers/stm32N657_mce.h"
#include	"Registers/stm32N657_mdf.h"
#include	"Registers/stm32N657_mdios.h"
#include	"Registers/stm32N657_otg.h"
#include	"Registers/stm32N657_pka.h"
#include	"Registers/stm32N657_pssi.h"
#include	"Registers/stm32N657_pwr.h"
#include	"Registers/stm32N657_ramcfg.h"
#include	"Registers/stm32N657_rcc.h"
#include	"Registers/stm32N657_rif.h"
#include	"Registers/stm32N657_rifsc.h"
#include	"Registers/stm32N657_risaf.h"
#include	"Registers/stm32N657_rng.h"
#include	"Registers/stm32N657_rtc.h"
#include	"Registers/stm32N657_saes.h"
#include	"Registers/stm32N657_sai.h"
#include	"Registers/stm32N657_sdmmc.h"
#include	"Registers/stm32N657_spdifrx.h"
#include	"Registers/stm32N657_spi.h"
#include	"Registers/stm32N657_syscfg.h"
#include	"Registers/stm32N657_tamp.h"
#include	"Registers/stm32N657_tim1.h"
#include	"Registers/stm32N657_tim1.h"
#include	"Registers/stm32N657_tim10.h"
#include	"Registers/stm32N657_tim11.h"
#include	"Registers/stm32N657_tim12.h"
#include	"Registers/stm32N657_tim13.h"
#include	"Registers/stm32N657_tim14.h"
#include	"Registers/stm32N657_tim15.h"
#include	"Registers/stm32N657_tim15.h"
#include	"Registers/stm32N657_tim16.h"
#include	"Registers/stm32N657_tim16.h"
#include	"Registers/stm32N657_tim17.h"
#include	"Registers/stm32N657_tim17.h"
#include	"Registers/stm32N657_tim18.h"
#include	"Registers/stm32N657_tim18.h"
#include	"Registers/stm32N657_tim2.h"
#include	"Registers/stm32N657_tim2.h"
#include	"Registers/stm32N657_tim3.h"
#include	"Registers/stm32N657_tim3.h"
#include	"Registers/stm32N657_tim4.h"
#include	"Registers/stm32N657_tim4.h"
#include	"Registers/stm32N657_tim5.h"
#include	"Registers/stm32N657_tim5.h"
#include	"Registers/stm32N657_tim6.h"
#include	"Registers/stm32N657_tim6.h"
#include	"Registers/stm32N657_tim7.h"
#include	"Registers/stm32N657_tim7.h"
#include	"Registers/stm32N657_tim8.h"
#include	"Registers/stm32N657_tim8.h"
#include	"Registers/stm32N657_tim9.h"
#include	"Registers/stm32N657_ucpd.h"
#include	"Registers/stm32N657_usart.h"
#include	"Registers/stm32N657_venc.h"
#include	"Registers/stm32N657_vrefbuf.h"
#include	"Registers/stm32N657_wwdg.h"
#include	"Registers/stm32N657_xspi.h"
#include	"Registers/stm32N657_xspim.h"
#include	"Registers/soc_addendum.h"

// IWYU pragma: end_exports
