/*
; K210_dvp.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		K210_dvp equates.
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

// DVP config register
// -------------------

#define	DVP_CFG_START_INT_ENABLE				0x00000001u		//
#define	DVP_CFG_FINISH_INT_ENABLE				0x00000002u		//
#define	DVP_CFG_AI_OUTPUT_ENABLE				0x00000004u		//
#define	DVP_CFG_DISPLAY_OUTPUT_ENABLE			0x00000008u		//
#define	DVP_CFG_AUTO_ENABLE						0x00000010u		//
#define	DVP_CFG_BURST_SIZE_4BEATS				0x00000100u		//
#define	DVP_CFG_FORMAT_MASK						0x00000600u		//
#define	DVP_CFG_RGB_FORMAT						0x00000000u		//
#define	DVP_CFG_YUV_FORMAT						0x00000200u		//
#define	DVP_CFG_Y_FORMAT						0x00000600u		//
#define	DVP_CFG_HREF_BURST_NUM_MASK				0x000FF000u		//
#define	DVP_CFG_LINE_NUM_MASK					0x3FF00000u		//
#define	DVP_CFG_HREF_BURST_NUM(x)				((x)<<12)		//
#define	DVP_CFG_LINE_NUM(x)						((x)<<20)		//

// DVP CMOS Config register
// ------------------------

#define	DVP_CMOS_CLK_DIV_MASK					0x000000FFu		//
#define	DVP_CMOS_CLK_ENABLE						0x00000100u		//
#define	DVP_CMOS_RESET							0x00010000u		//
#define	DVP_CMOS_POWER_DOWN						0x01000000u		//
#define	DVP_CMOS_CLK_DIV(x)						((x)<<0)		//

// DVP SCCB Config register
// ------------------------

#define	DVP_SCCB_BYTE_NUM_MASK					0x00000003u		//
#define	DVP_SCCB_BYTE_NUM_2						0x00000001u		//
#define	DVP_SCCB_BYTE_NUM_3						0x00000002u		//
#define	DVP_SCCB_BYTE_NUM_4						0x00000003u		//
#define	DVP_SCCB_SCL_LCNT_MASK					0x0000FF00u		//
#define	DVP_SCCB_SCL_HCNT_MASK					0x00FF0000u		//
#define	DVP_SCCB_SCL_LCNT(x)					((x)<<8)		//
#define	DVP_SCCB_SCL_HCNT(x)					((x)<<16)		//
#define	DVP_SCCB_RDATA_BYTE(x)					((x)>>24)		//

// DVP SCCB Control register
// -------------------------

#define	DVP_SCCB_WRITE_DATA_ENABLE				0x00000001u		//
#define	DVP_SCCB_DEVICE_ADDRESS(x)				((x)<<0)		//
#define	DVP_SCCB_REG_ADDRESS(x)					((x)<<8)		//
#define	DVP_SCCB_WDATA_BYTE0(x)					((x)<<16)		//
#define	DVP_SCCB_WDATA_BYTE1(x)					((x)<<24)		//

// DVP AXI register
// ----------------

#define	DVP_AXI_GM_MLEN_MASK					0x000000FFu		//
#define	DVP_AXI_GM_MLEN_1BYTE					0x00000000u		//
#define	DVP_AXI_GM_MLEN_4BYTE					0x00000003u		//

// DVP STS register
// ----------------

#define	DVP_STS_FRAME_START						0x00000001u		//
#define	DVP_STS_FRAME_START_WE					0x00000002u		//
#define	DVP_STS_FRAME_FINISH					0x00000100u		//
#define	DVP_STS_FRAME_FINISH_WE					0x00000200u		//
#define	DVP_STS_DVP_EN							0x00010000u		//
#define	DVP_STS_DVP_EN_WE						0x00020000u		//
#define	DVP_STS_SCCB_EN							0x01000000u		//
#define	DVP_STS_SCCB_EN_WE						0x02000000u		//

// Clang-format on
// ---------------

typedef	enum	_dvp_output_mode {
	DVP_OUTPUT_AI,												//
	DVP_OUTPUT_DISPLAY											//
} dvp_output_mode_t;

// The DVP address map
// -------------------

typedef	struct	[[gnu::packed, gnu::aligned(4)]] _dvp {
	uint32_t	dvp_cfg;										// DVP config Register
	uint32_t	r_addr;											// DVP start address R component (output to AI)
	uint32_t	g_addr;											// DVP start address G component (output to AI)
	uint32_t	b_addr;											// DVP start address B component (output to AI)
	uint32_t	cmos_cfg;										// DVP CMOS config Register
	uint32_t	sccb_cfg;										// DVP SCCB config Register
	uint32_t	sccb_ctl;										// DVP SCCB control Register
	uint32_t	axi;											// DVP AXI interface Register
	uint32_t	sts;											// DVP STS status Register
	uint32_t	reverse;										// reserved
	uint32_t	rgb_addr;										// DVP output address Register
} dvp_t;

#define	dvp		((volatile	dvp_t *)0x50430000u)
