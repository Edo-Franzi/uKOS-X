/*
; nrf5340.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340 equates.
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

#if (defined(CPU_APPLICATION_S))
#include	"Registers/soc_vectors_application.h"
#include	"Registers/nrf5340_application_cache.h"
#include	"Registers/nrf5340_application_cachedata.h"
#include	"Registers/nrf5340_application_cacheinfo.h"
#include	"Registers/nrf5340_application_clock.h"
#include	"Registers/nrf5340_application_comp.h"
#include	"Registers/nrf5340_application_cryptocell.h"
#include	"Registers/nrf5340_application_cti.h"
#include	"Registers/nrf5340_application_ctrlapperi.h"
#include	"Registers/nrf5340_application_dcnf.h"
#include	"Registers/nrf5340_application_dppic.h"
#include	"Registers/nrf5340_application_egu.h"
#include	"Registers/nrf5340_application_ficr.h"
#include	"Registers/nrf5340_application_gpio.h"
#include	"Registers/nrf5340_application_gpiote.h"
#include	"Registers/nrf5340_application_i2s.h"
#include	"Registers/nrf5340_application_ipc.h"
#include	"Registers/nrf5340_application_kmu.h"
#include	"Registers/nrf5340_application_lpcomp.h"
#include	"Registers/nrf5340_application_mutex.h"
#include	"Registers/nrf5340_application_nfct.h"
#include	"Registers/nrf5340_application_nvmc.h"
#include	"Registers/nrf5340_application_oscillators.h"
#include	"Registers/nrf5340_application_pdm.h"
#include	"Registers/nrf5340_application_power.h"
#include	"Registers/nrf5340_application_pwm.h"
#include	"Registers/nrf5340_application_qdec.h"
#include	"Registers/nrf5340_application_qspi.h"
#include	"Registers/nrf5340_application_regulators.h"
#include	"Registers/nrf5340_application_reset.h"
#include	"Registers/nrf5340_application_rtc.h"
#include	"Registers/nrf5340_application_saadc.h"
#include	"Registers/nrf5340_application_spim.h"
#include	"Registers/nrf5340_application_spis.h"
#include	"Registers/nrf5340_application_spu.h"
#include	"Registers/nrf5340_application_tad.h"
#include	"Registers/nrf5340_application_timer.h"
#include	"Registers/nrf5340_application_twim.h"
#include	"Registers/nrf5340_application_twis.h"
#include	"Registers/nrf5340_application_uarte.h"
#include	"Registers/nrf5340_application_uicr.h"
#include	"Registers/nrf5340_application_usbd.h"
#include	"Registers/nrf5340_application_usbreg.h"
#include	"Registers/nrf5340_application_vmc.h"
#include	"Registers/nrf5340_application_wdt.h"
#include	"Registers/soc_addendum_application.h"

#else
#include	"Registers/soc_vectors_network.h"
#include	"Registers/nrf5340_network_aar.h"
#include	"Registers/nrf5340_network_acl.h"
#include	"Registers/nrf5340_network_ccm.h"
#include	"Registers/nrf5340_network_clock.h"
#include	"Registers/nrf5340_network_cti.h"
#include	"Registers/nrf5340_network_ctrlapperi.h"
#include	"Registers/nrf5340_network_dcnf.h"
#include	"Registers/nrf5340_network_dppic.h"
#include	"Registers/nrf5340_network_ecb.h"
#include	"Registers/nrf5340_network_egu.h"
#include	"Registers/nrf5340_network_ficr.h"
#include	"Registers/nrf5340_network_gpio.h"
#include	"Registers/nrf5340_network_gpiote.h"
#include	"Registers/nrf5340_network_ipc.h"
#include	"Registers/nrf5340_network_mutex.h"
#include	"Registers/nrf5340_network_nvmc.h"
#include	"Registers/nrf5340_network_power.h"
#include	"Registers/nrf5340_network_radio.h"
#include	"Registers/nrf5340_network_reset.h"
#include	"Registers/nrf5340_network_rng.h"
#include	"Registers/nrf5340_network_rtc.h"
#include	"Registers/nrf5340_network_spim.h"
#include	"Registers/nrf5340_network_spis.h"
#include	"Registers/nrf5340_network_swi.h"
#include	"Registers/nrf5340_network_temp.h"
#include	"Registers/nrf5340_network_timer.h"
#include	"Registers/nrf5340_network_twim.h"
#include	"Registers/nrf5340_network_twis.h"
#include	"Registers/nrf5340_network_uarte.h"
#include	"Registers/nrf5340_network_uicr.h"
#include	"Registers/nrf5340_network_vmc.h"
#include	"Registers/nrf5340_network_vreqctrl.h"
#include	"Registers/nrf5340_network_wdt.h"
#include	"Registers/soc_addendum_network.h"
#endif

// IWYU pragma: end_exports
