/*
; RP2350_clocks.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_clocks equates.
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

#include	<stdint.h>

// CLOCKS address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	CLK_GPOUT0_CTRL;
	volatile	uint32_t	CLK_GPOUT0_DIV;
	volatile	uint32_t	CLK_GPOUT0_SELECTED;
	volatile	uint32_t	CLK_GPOUT1_CTRL;
	volatile	uint32_t	CLK_GPOUT1_DIV;
	volatile	uint32_t	CLK_GPOUT1_SELECTED;
	volatile	uint32_t	CLK_GPOUT2_CTRL;
	volatile	uint32_t	CLK_GPOUT2_DIV;
	volatile	uint32_t	CLK_GPOUT2_SELECTED;
	volatile	uint32_t	CLK_GPOUT3_CTRL;
	volatile	uint32_t	CLK_GPOUT3_DIV;
	volatile	uint32_t	CLK_GPOUT3_SELECTED;
	volatile	uint32_t	CLK_REF_CTRL;
	volatile	uint32_t	CLK_REF_DIV;
	volatile	uint32_t	CLK_REF_SELECTED;
	volatile	uint32_t	CLK_SYS_CTRL;
	volatile	uint32_t	CLK_SYS_DIV;
	volatile	uint32_t	CLK_SYS_SELECTED;
	volatile	uint32_t	CLK_PERI_CTRL;
	volatile	uint32_t	CLK_PERI_DIV;
	volatile	uint32_t	CLK_PERI_SELECTED;
	volatile	uint32_t	CLK_HSTX_CTRL;
	volatile	uint32_t	CLK_HSTX_DIV;
	volatile	uint32_t	CLK_HSTX_SELECTED;
	volatile	uint32_t	CLK_USB_CTRL;
	volatile	uint32_t	CLK_USB_DIV;
	volatile	uint32_t	CLK_USB_SELECTED;
	volatile	uint32_t	CLK_ADC_CTRL;
	volatile	uint32_t	CLK_ADC_DIV;
	volatile	uint32_t	CLK_ADC_SELECTED;
	volatile	uint32_t	DFTCLK_XOSC_CTRL;
	volatile	uint32_t	DFTCLK_ROSC_CTRL;
	volatile	uint32_t	DFTCLK_LPOSC_CTRL;
	volatile	uint32_t	CLK_SYS_RESUS_CTRL;
	volatile	uint32_t	CLK_SYS_RESUS_STATUS;
	volatile	uint32_t	FC0_REF_KHZ;
	volatile	uint32_t	FC0_MIN_KHZ;
	volatile	uint32_t	FC0_MAX_KHZ;
	volatile	uint32_t	FC0_DELAY;
	volatile	uint32_t	FC0_INTERVAL;
	volatile	uint32_t	FC0_SRC;
	volatile	uint32_t	FC0_STATUS;
	volatile	uint32_t	FC0_RESULT;
	volatile	uint32_t	WAKE_EN0;
	volatile	uint32_t	WAKE_EN1;
	volatile	uint32_t	SLEEP_EN0;
	volatile	uint32_t	SLEEP_EN1;
	volatile	uint32_t	ENABLED0;
	volatile	uint32_t	ENABLED1;
	volatile	uint32_t	INTR;
	volatile	uint32_t	INTE;
	volatile	uint32_t	INTF;
	volatile	uint32_t	INTS;
} CLOCKS_TypeDef;

#ifdef __cplusplus
#define	CLOCKS_NS	reinterpret_cast<CLOCKS_TypeDef *>(0x40010000u)
#define	CLOCKS_S	reinterpret_cast<CLOCKS_TypeDef *>(0x40010000u)
#else
#define	CLOCKS_NS	((CLOCKS_TypeDef *)0x40010000u)
#define	CLOCKS_S	((CLOCKS_TypeDef *)0x40010000u)
#endif

// CLK_GPOUT0_CTRL Configuration

#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC									(0xFu<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_0									(0x1u<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_KILL										(0x1u<<10)
#define	CLOCKS_CLK_GPOUT0_CTRL_ENABLE									(0x1u<<11)
#define	CLOCKS_CLK_GPOUT0_CTRL_DC50										(0x1u<<12)
#define	CLOCKS_CLK_GPOUT0_CTRL_PHASE									(0x3u<<16)
#define	CLOCKS_CLK_GPOUT0_CTRL_PHASE_0									(0x1u<<16)
#define	CLOCKS_CLK_GPOUT0_CTRL_NUDGE									(0x1u<<20)
#define	CLOCKS_CLK_GPOUT0_CTRL_ENABLED									(0x1u<<28)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_PLL_SYS					(0x0u<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_GPIN0						(0x1u<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_GPIN1						(0x2u<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_PLL_USB					(0x3u<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLKSRC_PLL_USB_PRIMARY_REF_OPCG	(0x4u<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_ROSC_CLKSRC						(0x5u<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_XOSC_CLKSRC						(0x6u<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_LPOSC_CLKSRC						(0x7u<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_SYS							(0x8u<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_USB							(0x9u<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_ADC							(0xAu<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_REF							(0xBu<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_PERI							(0xCu<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_CLK_HSTX							(0xDu<<5)
#define	CLOCKS_CLK_GPOUT0_CTRL_AUXSRC_OTP_CLK2FC						(0xEu<<5)

// CLK_GPOUT0_DIV Configuration

#define	CLOCKS_CLK_GPOUT0_DIV_FRAC										(0xFFFFu<<0)
#define	CLOCKS_CLK_GPOUT0_DIV_FRAC_0									(0x1u<<0)
#define	CLOCKS_CLK_GPOUT0_DIV_INT										(0xFFFFu<<16)
#define	CLOCKS_CLK_GPOUT0_DIV_INT_0										(0x1u<<16)

// CLK_GPOUT0_SELECTED Configuration

#define	CLOCKS_CLK_GPOUT0_SELECTED_CLK_GPOUT0_SELECTED					(0x1u<<0)

// CLK_GPOUT1_CTRL Configuration

#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC									(0xFu<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_0									(0x1u<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_KILL										(0x1u<<10)
#define	CLOCKS_CLK_GPOUT1_CTRL_ENABLE									(0x1u<<11)
#define	CLOCKS_CLK_GPOUT1_CTRL_DC50										(0x1u<<12)
#define	CLOCKS_CLK_GPOUT1_CTRL_PHASE									(0x3u<<16)
#define	CLOCKS_CLK_GPOUT1_CTRL_PHASE_0									(0x1u<<16)
#define	CLOCKS_CLK_GPOUT1_CTRL_NUDGE									(0x1u<<20)
#define	CLOCKS_CLK_GPOUT1_CTRL_ENABLED									(0x1u<<28)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_PLL_SYS					(0x0u<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_GPIN0						(0x1u<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_GPIN1						(0x2u<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_PLL_USB					(0x3u<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLKSRC_PLL_USB_PRIMARY_REF_OPCG	(0x4u<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_ROSC_CLKSRC						(0x5u<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_XOSC_CLKSRC						(0x6u<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_LPOSC_CLKSRC						(0x7u<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_SYS							(0x8u<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_USB							(0x9u<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_ADC							(0xAu<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_REF							(0xBu<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_PERI							(0xCu<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_CLK_HSTX							(0xDu<<5)
#define	CLOCKS_CLK_GPOUT1_CTRL_AUXSRC_OTP_CLK2FC						(0xEu<<5)

// CLK_GPOUT1_DIV Configuration

#define	CLOCKS_CLK_GPOUT1_DIV_FRAC										(0xFFFFu<<0)
#define	CLOCKS_CLK_GPOUT1_DIV_FRAC_0									(0x1u<<0)
#define	CLOCKS_CLK_GPOUT1_DIV_INT										(0xFFFFu<<16)
#define	CLOCKS_CLK_GPOUT1_DIV_INT_0										(0x1u<<16)

// CLK_GPOUT1_SELECTED Configuration

#define	CLOCKS_CLK_GPOUT1_SELECTED_CLK_GPOUT1_SELECTED					(0x1u<<0)

// CLK_GPOUT2_CTRL Configuration

#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC									(0xFu<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_0									(0x1u<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_KILL										(0x1u<<10)
#define	CLOCKS_CLK_GPOUT2_CTRL_ENABLE									(0x1u<<11)
#define	CLOCKS_CLK_GPOUT2_CTRL_DC50										(0x1u<<12)
#define	CLOCKS_CLK_GPOUT2_CTRL_PHASE									(0x3u<<16)
#define	CLOCKS_CLK_GPOUT2_CTRL_PHASE_0									(0x1u<<16)
#define	CLOCKS_CLK_GPOUT2_CTRL_NUDGE									(0x1u<<20)
#define	CLOCKS_CLK_GPOUT2_CTRL_ENABLED									(0x1u<<28)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_PLL_SYS					(0x0u<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_GPIN0						(0x1u<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_GPIN1						(0x2u<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_PLL_USB					(0x3u<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLKSRC_PLL_USB_PRIMARY_REF_OPCG	(0x4u<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_ROSC_CLKSRC_PH					(0x5u<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_XOSC_CLKSRC						(0x6u<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_LPOSC_CLKSRC						(0x7u<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_SYS							(0x8u<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_USB							(0x9u<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_ADC							(0xAu<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_REF							(0xBu<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_PERI							(0xCu<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_CLK_HSTX							(0xDu<<5)
#define	CLOCKS_CLK_GPOUT2_CTRL_AUXSRC_OTP_CLK2FC						(0xEu<<5)

// CLK_GPOUT2_DIV Configuration

#define	CLOCKS_CLK_GPOUT2_DIV_FRAC										(0xFFFFu<<0)
#define	CLOCKS_CLK_GPOUT2_DIV_FRAC_0									(0x1u<<0)
#define	CLOCKS_CLK_GPOUT2_DIV_INT										(0xFFFFu<<16)
#define	CLOCKS_CLK_GPOUT2_DIV_INT_0										(0x1u<<16)

// CLK_GPOUT2_SELECTED Configuration

#define	CLOCKS_CLK_GPOUT2_SELECTED_CLK_GPOUT2_SELECTED					(0x1u<<0)

// CLK_GPOUT3_CTRL Configuration

#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC									(0xFu<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_0									(0x1u<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_KILL										(0x1u<<10)
#define	CLOCKS_CLK_GPOUT3_CTRL_ENABLE									(0x1u<<11)
#define	CLOCKS_CLK_GPOUT3_CTRL_DC50										(0x1u<<12)
#define	CLOCKS_CLK_GPOUT3_CTRL_PHASE									(0x3u<<16)
#define	CLOCKS_CLK_GPOUT3_CTRL_PHASE_0									(0x1u<<16)
#define	CLOCKS_CLK_GPOUT3_CTRL_NUDGE									(0x1u<<20)
#define	CLOCKS_CLK_GPOUT3_CTRL_ENABLED									(0x1u<<28)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_PLL_SYS					(0x0u<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_GPIN0						(0x1u<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_GPIN1						(0x2u<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_PLL_USB					(0x3u<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLKSRC_PLL_USB_PRIMARY_REF_OPCG	(0x4u<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_ROSC_CLKSRC_PH					(0x5u<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_XOSC_CLKSRC						(0x6u<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_LPOSC_CLKSRC						(0x7u<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_SYS							(0x8u<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_USB							(0x9u<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_ADC							(0xAu<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_REF							(0xBu<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_PERI							(0xCu<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_CLK_HSTX							(0xDu<<5)
#define	CLOCKS_CLK_GPOUT3_CTRL_AUXSRC_OTP_CLK2FC						(0xEu<<5)

// CLK_GPOUT3_DIV Configuration

#define	CLOCKS_CLK_GPOUT3_DIV_FRAC										(0xFFFFu<<0)
#define	CLOCKS_CLK_GPOUT3_DIV_FRAC_0									(0x1u<<0)
#define	CLOCKS_CLK_GPOUT3_DIV_INT										(0xFFFFu<<16)
#define	CLOCKS_CLK_GPOUT3_DIV_INT_0										(0x1u<<16)

// CLK_GPOUT3_SELECTED Configuration

#define	CLOCKS_CLK_GPOUT3_SELECTED_CLK_GPOUT3_SELECTED					(0x1u<<0)

// CLK_REF_CTRL Configuration

#define	CLOCKS_CLK_REF_CTRL_SRC											(0x3u<<0)
#define	CLOCKS_CLK_REF_CTRL_SRC_0										(0x1u<<0)
#define	CLOCKS_CLK_REF_CTRL_AUXSRC										(0x3u<<5)
#define	CLOCKS_CLK_REF_CTRL_AUXSRC_0									(0x1u<<5)
#define	CLOCKS_CLK_REF_CTRL_SRC_ROSC_CLKSRC_PH							(0x0u<<0)
#define	CLOCKS_CLK_REF_CTRL_SRC_CLKSRC_CLK_REF_AUX						(0x1u<<0)
#define	CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC								(0x2u<<0)
#define	CLOCKS_CLK_REF_CTRL_SRC_LPOSC_CLKSRC							(0x3u<<0)
#define	CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_PLL_USB						(0x0u<<5)
#define	CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_GPIN0							(0x1u<<5)
#define	CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_GPIN1							(0x2u<<5)
#define	CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_PLL_USB_PRIMARY_REF_OPCG		(0x3u<<5)

// CLK_REF_DIV Configuration

#define	CLOCKS_CLK_REF_DIV_INT											(0xFFu<<16)
#define	CLOCKS_CLK_REF_DIV_INT_0										(0x1u<<16)

// CLK_REF_SELECTED Configuration

#define	CLOCKS_CLK_REF_SELECTED_CLK_REF_SELECTED						(0xFu<<0)
#define	CLOCKS_CLK_REF_SELECTED_CLK_REF_SELECTED_0						(0x1u<<0)

// CLK_SYS_CTRL Configuration

#define	CLOCKS_CLK_SYS_CTRL_SRC											(0x1u<<0)
#define	CLOCKS_CLK_SYS_CTRL_AUXSRC										(0x7u<<5)
#define	CLOCKS_CLK_SYS_CTRL_AUXSRC_0									(0x1u<<5)
#define	CLOCKS_CLK_SYS_CTRL_SRC_CLK_REF									(0x0u<<0)
#define	CLOCKS_CLK_SYS_CTRL_SRC_CLKSRC_CLK_SYS_AUX						(0x1u<<0)
#define	CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_PLL_SYS						(0x0u<<5)
#define	CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_PLL_USB						(0x1u<<5)
#define	CLOCKS_CLK_SYS_CTRL_AUXSRC_ROSC_CLKSRC							(0x2u<<5)
#define	CLOCKS_CLK_SYS_CTRL_AUXSRC_XOSC_CLKSRC							(0x3u<<5)
#define	CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_GPIN0							(0x4u<<5)
#define	CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_GPIN1							(0x5u<<5)

// CLK_SYS_DIV Configuration

#define	CLOCKS_CLK_SYS_DIV_FRAC											(0xFFFFu<<0)
#define	CLOCKS_CLK_SYS_DIV_FRAC_0										(0x1u<<0)
#define	CLOCKS_CLK_SYS_DIV_INT											(0xFFFFu<<16)
#define	CLOCKS_CLK_SYS_DIV_INT_0										(0x1u<<16)

// CLK_SYS_SELECTED Configuration

#define	CLOCKS_CLK_SYS_SELECTED_CLK_SYS_SELECTED						(0x3u<<0)
#define	CLOCKS_CLK_SYS_SELECTED_CLK_SYS_SELECTED_0						(0x1u<<0)

// CLK_PERI_CTRL Configuration

#define	CLOCKS_CLK_PERI_CTRL_AUXSRC										(0x7u<<5)
#define	CLOCKS_CLK_PERI_CTRL_AUXSRC_0									(0x1u<<5)
#define	CLOCKS_CLK_PERI_CTRL_KILL										(0x1u<<10)
#define	CLOCKS_CLK_PERI_CTRL_ENABLE										(0x1u<<11)
#define	CLOCKS_CLK_PERI_CTRL_ENABLED									(0x1u<<28)
#define	CLOCKS_CLK_PERI_CTRL_AUXSRC_CLK_SYS								(0x0u<<5)
#define	CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_PLL_SYS						(0x1u<<5)
#define	CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_PLL_USB						(0x2u<<5)
#define	CLOCKS_CLK_PERI_CTRL_AUXSRC_ROSC_CLKSRC_PH						(0x3u<<5)
#define	CLOCKS_CLK_PERI_CTRL_AUXSRC_XOSC_CLKSRC							(0x4u<<5)
#define	CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_GPIN0						(0x5u<<5)
#define	CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_GPIN1						(0x6u<<5)

// CLK_PERI_DIV Configuration

#define	CLOCKS_CLK_PERI_DIV_INT											(0x3u<<16)
#define	CLOCKS_CLK_PERI_DIV_INT_0										(0x1u<<16)

// CLK_PERI_SELECTED Configuration

#define	CLOCKS_CLK_PERI_SELECTED_CLK_PERI_SELECTED						(0x1u<<0)

// CLK_HSTX_CTRL Configuration

#define	CLOCKS_CLK_HSTX_CTRL_AUXSRC										(0x7u<<5)
#define	CLOCKS_CLK_HSTX_CTRL_AUXSRC_0									(0x1u<<5)
#define	CLOCKS_CLK_HSTX_CTRL_KILL										(0x1u<<10)
#define	CLOCKS_CLK_HSTX_CTRL_ENABLE										(0x1u<<11)
#define	CLOCKS_CLK_HSTX_CTRL_PHASE										(0x3u<<16)
#define	CLOCKS_CLK_HSTX_CTRL_PHASE_0									(0x1u<<16)
#define	CLOCKS_CLK_HSTX_CTRL_NUDGE										(0x1u<<20)
#define	CLOCKS_CLK_HSTX_CTRL_ENABLED									(0x1u<<28)
#define	CLOCKS_CLK_HSTX_CTRL_AUXSRC_CLK_SYS								(0x0u<<5)
#define	CLOCKS_CLK_HSTX_CTRL_AUXSRC_CLKSRC_PLL_SYS						(0x1u<<5)
#define	CLOCKS_CLK_HSTX_CTRL_AUXSRC_CLKSRC_PLL_USB						(0x2u<<5)
#define	CLOCKS_CLK_HSTX_CTRL_AUXSRC_CLKSRC_GPIN0						(0x3u<<5)
#define	CLOCKS_CLK_HSTX_CTRL_AUXSRC_CLKSRC_GPIN1						(0x4u<<5)

// CLK_HSTX_DIV Configuration

#define	CLOCKS_CLK_HSTX_DIV_INT											(0x3u<<16)
#define	CLOCKS_CLK_HSTX_DIV_INT_0										(0x1u<<16)

// CLK_HSTX_SELECTED Configuration

#define	CLOCKS_CLK_HSTX_SELECTED_CLK_HSTX_SELECTED						(0x1u<<0)

// CLK_USB_CTRL Configuration

#define	CLOCKS_CLK_USB_CTRL_AUXSRC										(0x7u<<5)
#define	CLOCKS_CLK_USB_CTRL_AUXSRC_0									(0x1u<<5)
#define	CLOCKS_CLK_USB_CTRL_KILL										(0x1u<<10)
#define	CLOCKS_CLK_USB_CTRL_ENABLE										(0x1u<<11)
#define	CLOCKS_CLK_USB_CTRL_PHASE										(0x3u<<16)
#define	CLOCKS_CLK_USB_CTRL_PHASE_0										(0x1u<<16)
#define	CLOCKS_CLK_USB_CTRL_NUDGE										(0x1u<<20)
#define	CLOCKS_CLK_USB_CTRL_ENABLED										(0x1u<<28)
#define	CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_PLL_USB						(0x0u<<5)
#define	CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_PLL_SYS						(0x1u<<5)
#define	CLOCKS_CLK_USB_CTRL_AUXSRC_ROSC_CLKSRC_PH						(0x2u<<5)
#define	CLOCKS_CLK_USB_CTRL_AUXSRC_XOSC_CLKSRC							(0x3u<<5)
#define	CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_GPIN0							(0x4u<<5)
#define	CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_GPIN1							(0x5u<<5)

// CLK_USB_DIV Configuration

#define	CLOCKS_CLK_USB_DIV_INT											(0xFu<<16)
#define	CLOCKS_CLK_USB_DIV_INT_0										(0x1u<<16)

// CLK_USB_SELECTED Configuration

#define	CLOCKS_CLK_USB_SELECTED_CLK_USB_SELECTED						(0x1u<<0)

// CLK_ADC_CTRL Configuration

#define	CLOCKS_CLK_ADC_CTRL_AUXSRC										(0x7u<<5)
#define	CLOCKS_CLK_ADC_CTRL_AUXSRC_0									(0x1u<<5)
#define	CLOCKS_CLK_ADC_CTRL_KILL										(0x1u<<10)
#define	CLOCKS_CLK_ADC_CTRL_ENABLE										(0x1u<<11)
#define	CLOCKS_CLK_ADC_CTRL_PHASE										(0x3u<<16)
#define	CLOCKS_CLK_ADC_CTRL_PHASE_0										(0x1u<<16)
#define	CLOCKS_CLK_ADC_CTRL_NUDGE										(0x1u<<20)
#define	CLOCKS_CLK_ADC_CTRL_ENABLED										(0x1u<<28)
#define	CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_PLL_USB						(0x0u<<5)
#define	CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_PLL_SYS						(0x1u<<5)
#define	CLOCKS_CLK_ADC_CTRL_AUXSRC_ROSC_CLKSRC_PH						(0x2u<<5)
#define	CLOCKS_CLK_ADC_CTRL_AUXSRC_XOSC_CLKSRC							(0x3u<<5)
#define	CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_GPIN0							(0x4u<<5)
#define	CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_GPIN1							(0x5u<<5)

// CLK_ADC_DIV Configuration

#define	CLOCKS_CLK_ADC_DIV_INT											(0xFu<<16)
#define	CLOCKS_CLK_ADC_DIV_INT_0										(0x1u<<16)

// CLK_ADC_SELECTED Configuration

#define	CLOCKS_CLK_ADC_SELECTED_CLK_ADC_SELECTED						(0x1u<<0)

// DFTCLK_XOSC_CTRL Configuration

#define	CLOCKS_DFTCLK_XOSC_CTRL_SRC										(0x3u<<0)
#define	CLOCKS_DFTCLK_XOSC_CTRL_SRC_0									(0x1u<<0)
#define	CLOCKS_DFTCLK_XOSC_CTRL_SRC_NULL								(0x0u<<0)
#define	CLOCKS_DFTCLK_XOSC_CTRL_SRC_CLKSRC_PLL_USB_PRIMARY				(0x1u<<0)
#define	CLOCKS_DFTCLK_XOSC_CTRL_SRC_CLKSRC_GPIN0						(0x2u<<0)

// DFTCLK_ROSC_CTRL Configuration

#define	CLOCKS_DFTCLK_ROSC_CTRL_SRC										(0x3u<<0)
#define	CLOCKS_DFTCLK_ROSC_CTRL_SRC_0									(0x1u<<0)
#define	CLOCKS_DFTCLK_ROSC_CTRL_SRC_NULL								(0x0u<<0)
#define	CLOCKS_DFTCLK_ROSC_CTRL_SRC_CLKSRC_PLL_SYS_PRIMARY_ROSC			(0x1u<<0)
#define	CLOCKS_DFTCLK_ROSC_CTRL_SRC_CLKSRC_GPIN1						(0x2u<<0)

// DFTCLK_LPOSC_CTRL Configuration

#define	CLOCKS_DFTCLK_LPOSC_CTRL_SRC									(0x3u<<0)
#define	CLOCKS_DFTCLK_LPOSC_CTRL_SRC_0									(0x1u<<0)
#define	CLOCKS_DFTCLK_LPOSC_CTRL_SRC_NULL								(0x0u<<0)
#define	CLOCKS_DFTCLK_LPOSC_CTRL_SRC_CLKSRC_PLL_USB_PRIMARY_LPOSC		(0x1u<<0)
#define	CLOCKS_DFTCLK_LPOSC_CTRL_SRC_CLKSRC_GPIN1						(0x2u<<0)

// CLK_SYS_RESUS_CTRL Configuration

#define	CLOCKS_CLK_SYS_RESUS_CTRL_TIMEOUT								(0xFFu<<0)
#define	CLOCKS_CLK_SYS_RESUS_CTRL_TIMEOUT_0								(0x1u<<0)
#define	CLOCKS_CLK_SYS_RESUS_CTRL_ENABLE								(0x1u<<8)
#define	CLOCKS_CLK_SYS_RESUS_CTRL_FRCE									(0x1u<<12)
#define	CLOCKS_CLK_SYS_RESUS_CTRL_CLEAR									(0x1u<<16)

// CLK_SYS_RESUS_STATUS Configuration

#define	CLOCKS_CLK_SYS_RESUS_STATUS_RESUSSED							(0x1u<<0)

// FC0_REF_KHZ Configuration

#define	CLOCKS_FC0_REF_KHZ_FC0_REF_KHZ									(0xFFFFFu<<0)
#define	CLOCKS_FC0_REF_KHZ_FC0_REF_KHZ_0								(0x1u<<0)

// FC0_MIN_KHZ Configuration

#define	CLOCKS_FC0_MIN_KHZ_FC0_MIN_KHZ									(0x1FFFFFFu<<0)
#define	CLOCKS_FC0_MIN_KHZ_FC0_MIN_KHZ_0								(0x1u<<0)

// FC0_MAX_KHZ Configuration

#define	CLOCKS_FC0_MAX_KHZ_FC0_MAX_KHZ									(0x1FFFFFFu<<0)
#define	CLOCKS_FC0_MAX_KHZ_FC0_MAX_KHZ_0								(0x1u<<0)

// FC0_DELAY Configuration

#define	CLOCKS_FC0_DELAY_FC0_DELAY										(0x7u<<0)
#define	CLOCKS_FC0_DELAY_FC0_DELAY_0									(0x1u<<0)

// FC0_INTERVAL Configuration

#define	CLOCKS_FC0_INTERVAL_FC0_INTERVAL								(0xFu<<0)
#define	CLOCKS_FC0_INTERVAL_FC0_INTERVAL_0								(0x1u<<0)

// FC0_SRC Configuration

#define	CLOCKS_FC0_SRC_FC0_SRC											(0xFFu<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_0										(0x1u<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_NULL										(0x0u<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_PLL_SYS_CLKSRC_PRIMARY					(0x1u<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_PLL_USB_CLKSRC_PRIMARY					(0x2u<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_ROSC_CLKSRC								(0x3u<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_ROSC_CLKSRC_PH							(0x4u<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_XOSC_CLKSRC								(0x5u<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_CLKSRC_GPIN0								(0x6u<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_CLKSRC_GPIN1								(0x7u<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_CLK_REF									(0x8u<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_CLK_SYS									(0x9u<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_CLK_PERI									(0xAu<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_CLK_USB									(0xBu<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_CLK_ADC									(0xCu<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_CLK_HSTX									(0xDu<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_LPOSC_CLKSRC								(0xEu<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_OTP_CLK2FC								(0xFu<<0)
#define	CLOCKS_FC0_SRC_FC0_SRC_PLL_USB_CLKSRC_PRIMARY_DFT				(0x10u<<0)

// FC0_STATUS Configuration

#define	CLOCKS_FC0_STATUS_PASS											(0x1u<<0)
#define	CLOCKS_FC0_STATUS_DONE											(0x1u<<4)
#define	CLOCKS_FC0_STATUS_RUNNING										(0x1u<<8)
#define	CLOCKS_FC0_STATUS_WAITING										(0x1u<<12)
#define	CLOCKS_FC0_STATUS_FAIL											(0x1u<<16)
#define	CLOCKS_FC0_STATUS_SLOW											(0x1u<<20)
#define	CLOCKS_FC0_STATUS_FAST											(0x1u<<24)
#define	CLOCKS_FC0_STATUS_DIED											(0x1u<<28)

// FC0_RESULT Configuration

#define	CLOCKS_FC0_RESULT_FRAC											(0x1Fu<<0)
#define	CLOCKS_FC0_RESULT_FRAC_0										(0x1u<<0)
#define	CLOCKS_FC0_RESULT_KHZ											(0x1FFFFFFu<<5)
#define	CLOCKS_FC0_RESULT_KHZ_0											(0x1u<<5)

// WAKE_EN0 Configuration

#define	CLOCKS_WAKE_EN0_CLK_SYS_CLOCKS									(0x1u<<0)
#define	CLOCKS_WAKE_EN0_CLK_SYS_ACCESSCTRL								(0x1u<<1)
#define	CLOCKS_WAKE_EN0_CLK_ADC											(0x1u<<2)
#define	CLOCKS_WAKE_EN0_CLK_SYS_ADC										(0x1u<<3)
#define	CLOCKS_WAKE_EN0_CLK_SYS_BOOTRAM									(0x1u<<4)
#define	CLOCKS_WAKE_EN0_CLK_SYS_BUSCTRL									(0x1u<<5)
#define	CLOCKS_WAKE_EN0_CLK_SYS_BUSFABRIC								(0x1u<<6)
#define	CLOCKS_WAKE_EN0_CLK_SYS_DMA										(0x1u<<7)
#define	CLOCKS_WAKE_EN0_CLK_SYS_GLITCH_DETECTOR							(0x1u<<8)
#define	CLOCKS_WAKE_EN0_CLK_HSTX										(0x1u<<9)
#define	CLOCKS_WAKE_EN0_CLK_SYS_HSTX									(0x1u<<10)
#define	CLOCKS_WAKE_EN0_CLK_SYS_I2C0									(0x1u<<11)
#define	CLOCKS_WAKE_EN0_CLK_SYS_I2C1									(0x1u<<12)
#define	CLOCKS_WAKE_EN0_CLK_SYS_IO										(0x1u<<13)
#define	CLOCKS_WAKE_EN0_CLK_SYS_JTAG									(0x1u<<14)
#define	CLOCKS_WAKE_EN0_CLK_REF_OTP										(0x1u<<15)
#define	CLOCKS_WAKE_EN0_CLK_SYS_OTP										(0x1u<<16)
#define	CLOCKS_WAKE_EN0_CLK_SYS_PADS									(0x1u<<17)
#define	CLOCKS_WAKE_EN0_CLK_SYS_PIO0									(0x1u<<18)
#define	CLOCKS_WAKE_EN0_CLK_SYS_PIO1									(0x1u<<19)
#define	CLOCKS_WAKE_EN0_CLK_SYS_PIO2									(0x1u<<20)
#define	CLOCKS_WAKE_EN0_CLK_SYS_PLL_SYS									(0x1u<<21)
#define	CLOCKS_WAKE_EN0_CLK_SYS_PLL_USB									(0x1u<<22)
#define	CLOCKS_WAKE_EN0_CLK_REF_POWMAN									(0x1u<<23)
#define	CLOCKS_WAKE_EN0_CLK_SYS_POWMAN									(0x1u<<24)
#define	CLOCKS_WAKE_EN0_CLK_SYS_PWM										(0x1u<<25)
#define	CLOCKS_WAKE_EN0_CLK_SYS_RESETS									(0x1u<<26)
#define	CLOCKS_WAKE_EN0_CLK_SYS_ROM										(0x1u<<27)
#define	CLOCKS_WAKE_EN0_CLK_SYS_ROSC									(0x1u<<28)
#define	CLOCKS_WAKE_EN0_CLK_SYS_PSM										(0x1u<<29)
#define	CLOCKS_WAKE_EN0_CLK_SYS_SHA256									(0x1u<<30)
#define	CLOCKS_WAKE_EN0_CLK_SYS_SIO										(0x1u<<31)

// WAKE_EN1 Configuration

#define	CLOCKS_WAKE_EN1_CLK_PERI_SPI0									(0x1u<<0)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SPI0									(0x1u<<1)
#define	CLOCKS_WAKE_EN1_CLK_PERI_SPI1									(0x1u<<2)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SPI1									(0x1u<<3)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SRAM0									(0x1u<<4)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SRAM1									(0x1u<<5)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SRAM2									(0x1u<<6)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SRAM3									(0x1u<<7)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SRAM4									(0x1u<<8)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SRAM5									(0x1u<<9)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SRAM6									(0x1u<<10)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SRAM7									(0x1u<<11)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SRAM8									(0x1u<<12)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SRAM9									(0x1u<<13)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SYSCFG									(0x1u<<14)
#define	CLOCKS_WAKE_EN1_CLK_SYS_SYSINFO									(0x1u<<15)
#define	CLOCKS_WAKE_EN1_CLK_SYS_TBMAN									(0x1u<<16)
#define	CLOCKS_WAKE_EN1_CLK_REF_TICKS									(0x1u<<17)
#define	CLOCKS_WAKE_EN1_CLK_SYS_TICKS									(0x1u<<18)
#define	CLOCKS_WAKE_EN1_CLK_SYS_TIMER0									(0x1u<<19)
#define	CLOCKS_WAKE_EN1_CLK_SYS_TIMER1									(0x1u<<20)
#define	CLOCKS_WAKE_EN1_CLK_SYS_TRNG									(0x1u<<21)
#define	CLOCKS_WAKE_EN1_CLK_PERI_UART0									(0x1u<<22)
#define	CLOCKS_WAKE_EN1_CLK_SYS_UART0									(0x1u<<23)
#define	CLOCKS_WAKE_EN1_CLK_PERI_UART1									(0x1u<<24)
#define	CLOCKS_WAKE_EN1_CLK_SYS_UART1									(0x1u<<25)
#define	CLOCKS_WAKE_EN1_CLK_SYS_USBCTRL									(0x1u<<26)
#define	CLOCKS_WAKE_EN1_CLK_USB											(0x1u<<27)
#define	CLOCKS_WAKE_EN1_CLK_SYS_WATCHDOG								(0x1u<<28)
#define	CLOCKS_WAKE_EN1_CLK_SYS_XIP										(0x1u<<29)
#define	CLOCKS_WAKE_EN1_CLK_SYS_XOSC									(0x1u<<30)

// SLEEP_EN0 Configuration

#define	CLOCKS_SLEEP_EN0_CLK_SYS_CLOCKS									(0x1u<<0)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_ACCESSCTRL								(0x1u<<1)
#define	CLOCKS_SLEEP_EN0_CLK_ADC										(0x1u<<2)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_ADC									(0x1u<<3)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_BOOTRAM								(0x1u<<4)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_BUSCTRL								(0x1u<<5)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_BUSFABRIC								(0x1u<<6)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_DMA									(0x1u<<7)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_GLITCH_DETECTOR						(0x1u<<8)
#define	CLOCKS_SLEEP_EN0_CLK_HSTX										(0x1u<<9)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_HSTX									(0x1u<<10)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_I2C0									(0x1u<<11)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_I2C1									(0x1u<<12)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_IO										(0x1u<<13)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_JTAG									(0x1u<<14)
#define	CLOCKS_SLEEP_EN0_CLK_REF_OTP									(0x1u<<15)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_OTP									(0x1u<<16)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_PADS									(0x1u<<17)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_PIO0									(0x1u<<18)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_PIO1									(0x1u<<19)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_PIO2									(0x1u<<20)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_PLL_SYS								(0x1u<<21)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_PLL_USB								(0x1u<<22)
#define	CLOCKS_SLEEP_EN0_CLK_REF_POWMAN									(0x1u<<23)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_POWMAN									(0x1u<<24)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_PWM									(0x1u<<25)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_RESETS									(0x1u<<26)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_ROM									(0x1u<<27)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_ROSC									(0x1u<<28)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_PSM									(0x1u<<29)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_SHA256									(0x1u<<30)
#define	CLOCKS_SLEEP_EN0_CLK_SYS_SIO									(0x1u<<31)

// SLEEP_EN1 Configuration

#define	CLOCKS_SLEEP_EN1_CLK_PERI_SPI0									(0x1u<<0)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SPI0									(0x1u<<1)
#define	CLOCKS_SLEEP_EN1_CLK_PERI_SPI1									(0x1u<<2)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SPI1									(0x1u<<3)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SRAM0									(0x1u<<4)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SRAM1									(0x1u<<5)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SRAM2									(0x1u<<6)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SRAM3									(0x1u<<7)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SRAM4									(0x1u<<8)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SRAM5									(0x1u<<9)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SRAM6									(0x1u<<10)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SRAM7									(0x1u<<11)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SRAM8									(0x1u<<12)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SRAM9									(0x1u<<13)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SYSCFG									(0x1u<<14)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_SYSINFO								(0x1u<<15)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_TBMAN									(0x1u<<16)
#define	CLOCKS_SLEEP_EN1_CLK_REF_TICKS									(0x1u<<17)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_TICKS									(0x1u<<18)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_TIMER0									(0x1u<<19)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_TIMER1									(0x1u<<20)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_TRNG									(0x1u<<21)
#define	CLOCKS_SLEEP_EN1_CLK_PERI_UART0									(0x1u<<22)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_UART0									(0x1u<<23)
#define	CLOCKS_SLEEP_EN1_CLK_PERI_UART1									(0x1u<<24)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_UART1									(0x1u<<25)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_USBCTRL								(0x1u<<26)
#define	CLOCKS_SLEEP_EN1_CLK_USB										(0x1u<<27)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_WATCHDOG								(0x1u<<28)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_XIP									(0x1u<<29)
#define	CLOCKS_SLEEP_EN1_CLK_SYS_XOSC									(0x1u<<30)

// ENABLED0 Configuration

#define	CLOCKS_ENABLED0_CLK_SYS_CLOCKS									(0x1u<<0)
#define	CLOCKS_ENABLED0_CLK_SYS_ACCESSCTRL								(0x1u<<1)
#define	CLOCKS_ENABLED0_CLK_ADC											(0x1u<<2)
#define	CLOCKS_ENABLED0_CLK_SYS_ADC										(0x1u<<3)
#define	CLOCKS_ENABLED0_CLK_SYS_BOOTRAM									(0x1u<<4)
#define	CLOCKS_ENABLED0_CLK_SYS_BUSCTRL									(0x1u<<5)
#define	CLOCKS_ENABLED0_CLK_SYS_BUSFABRIC								(0x1u<<6)
#define	CLOCKS_ENABLED0_CLK_SYS_DMA										(0x1u<<7)
#define	CLOCKS_ENABLED0_CLK_SYS_GLITCH_DETECTOR							(0x1u<<8)
#define	CLOCKS_ENABLED0_CLK_HSTX										(0x1u<<9)
#define	CLOCKS_ENABLED0_CLK_SYS_HSTX									(0x1u<<10)
#define	CLOCKS_ENABLED0_CLK_SYS_I2C0									(0x1u<<11)
#define	CLOCKS_ENABLED0_CLK_SYS_I2C1									(0x1u<<12)
#define	CLOCKS_ENABLED0_CLK_SYS_IO										(0x1u<<13)
#define	CLOCKS_ENABLED0_CLK_SYS_JTAG									(0x1u<<14)
#define	CLOCKS_ENABLED0_CLK_REF_OTP										(0x1u<<15)
#define	CLOCKS_ENABLED0_CLK_SYS_OTP										(0x1u<<16)
#define	CLOCKS_ENABLED0_CLK_SYS_PADS									(0x1u<<17)
#define	CLOCKS_ENABLED0_CLK_SYS_PIO0									(0x1u<<18)
#define	CLOCKS_ENABLED0_CLK_SYS_PIO1									(0x1u<<19)
#define	CLOCKS_ENABLED0_CLK_SYS_PIO2									(0x1u<<20)
#define	CLOCKS_ENABLED0_CLK_SYS_PLL_SYS									(0x1u<<21)
#define	CLOCKS_ENABLED0_CLK_SYS_PLL_USB									(0x1u<<22)
#define	CLOCKS_ENABLED0_CLK_REF_POWMAN									(0x1u<<23)
#define	CLOCKS_ENABLED0_CLK_SYS_POWMAN									(0x1u<<24)
#define	CLOCKS_ENABLED0_CLK_SYS_PWM										(0x1u<<25)
#define	CLOCKS_ENABLED0_CLK_SYS_RESETS									(0x1u<<26)
#define	CLOCKS_ENABLED0_CLK_SYS_ROM										(0x1u<<27)
#define	CLOCKS_ENABLED0_CLK_SYS_ROSC									(0x1u<<28)
#define	CLOCKS_ENABLED0_CLK_SYS_PSM										(0x1u<<29)
#define	CLOCKS_ENABLED0_CLK_SYS_SHA256									(0x1u<<30)
#define	CLOCKS_ENABLED0_CLK_SYS_SIO										(0x1u<<31)

// ENABLED1 Configuration

#define	CLOCKS_ENABLED1_CLK_PERI_SPI0									(0x1u<<0)
#define	CLOCKS_ENABLED1_CLK_SYS_SPI0									(0x1u<<1)
#define	CLOCKS_ENABLED1_CLK_PERI_SPI1									(0x1u<<2)
#define	CLOCKS_ENABLED1_CLK_SYS_SPI1									(0x1u<<3)
#define	CLOCKS_ENABLED1_CLK_SYS_SRAM0									(0x1u<<4)
#define	CLOCKS_ENABLED1_CLK_SYS_SRAM1									(0x1u<<5)
#define	CLOCKS_ENABLED1_CLK_SYS_SRAM2									(0x1u<<6)
#define	CLOCKS_ENABLED1_CLK_SYS_SRAM3									(0x1u<<7)
#define	CLOCKS_ENABLED1_CLK_SYS_SRAM4									(0x1u<<8)
#define	CLOCKS_ENABLED1_CLK_SYS_SRAM5									(0x1u<<9)
#define	CLOCKS_ENABLED1_CLK_SYS_SRAM6									(0x1u<<10)
#define	CLOCKS_ENABLED1_CLK_SYS_SRAM7									(0x1u<<11)
#define	CLOCKS_ENABLED1_CLK_SYS_SRAM8									(0x1u<<12)
#define	CLOCKS_ENABLED1_CLK_SYS_SRAM9									(0x1u<<13)
#define	CLOCKS_ENABLED1_CLK_SYS_SYSCFG									(0x1u<<14)
#define	CLOCKS_ENABLED1_CLK_SYS_SYSINFO									(0x1u<<15)
#define	CLOCKS_ENABLED1_CLK_SYS_TBMAN									(0x1u<<16)
#define	CLOCKS_ENABLED1_CLK_REF_TICKS									(0x1u<<17)
#define	CLOCKS_ENABLED1_CLK_SYS_TICKS									(0x1u<<18)
#define	CLOCKS_ENABLED1_CLK_SYS_TIMER0									(0x1u<<19)
#define	CLOCKS_ENABLED1_CLK_SYS_TIMER1									(0x1u<<20)
#define	CLOCKS_ENABLED1_CLK_SYS_TRNG									(0x1u<<21)
#define	CLOCKS_ENABLED1_CLK_PERI_UART0									(0x1u<<22)
#define	CLOCKS_ENABLED1_CLK_SYS_UART0									(0x1u<<23)
#define	CLOCKS_ENABLED1_CLK_PERI_UART1									(0x1u<<24)
#define	CLOCKS_ENABLED1_CLK_SYS_UART1									(0x1u<<25)
#define	CLOCKS_ENABLED1_CLK_SYS_USBCTRL									(0x1u<<26)
#define	CLOCKS_ENABLED1_CLK_USB											(0x1u<<27)
#define	CLOCKS_ENABLED1_CLK_SYS_WATCHDOG								(0x1u<<28)
#define	CLOCKS_ENABLED1_CLK_SYS_XIP										(0x1u<<29)
#define	CLOCKS_ENABLED1_CLK_SYS_XOSC									(0x1u<<30)

// INTR Configuration

#define	CLOCKS_INTR_CLK_SYS_RESUS										(0x1u<<0)

// INTE Configuration

#define	CLOCKS_INTE_CLK_SYS_RESUS										(0x1u<<0)

// INTF Configuration

#define	CLOCKS_INTF_CLK_SYS_RESUS										(0x1u<<0)

// INTS Configuration

#define	CLOCKS_INTS_CLK_SYS_RESUS										(0x1u<<0)
