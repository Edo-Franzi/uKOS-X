/*
; stm32N657_dcmi.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_dcmi equates.
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

// DCMI address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	RIS;
	volatile	uint32_t	IER;
	volatile	uint32_t	MIS;
	volatile	uint32_t	ICR;
	volatile	uint32_t	ESCR;
	volatile	uint32_t	ESUR;
	volatile	uint32_t	CWSTRT;
	volatile	uint32_t	CWSIZE;
	volatile	uint32_t	DR;
} DCMI_TypeDef;

#if (defined(__cplusplus))
#define	DCMI_NS	reinterpret_cast<DCMI_TypeDef *>(0x48028400u)
#define	DCMI_S	reinterpret_cast<DCMI_TypeDef *>(0x58028400u)

#else
#define	DCMI_NS	((DCMI_TypeDef *)0x48028400u)
#define	DCMI_S	((DCMI_TypeDef *)0x58028400u)
#endif

// CR Configuration

#define	DCMI_CR_OELS					(0x1u<<20)
#define	DCMI_CR_LSM						(0x1u<<19)
#define	DCMI_CR_OEBS					(0x1u<<18)
#define	DCMI_CR_BSM						(0x3u<<16)
#define	DCMI_CR_BSM_0					(0x1u<<16)
#define	DCMI_CR_ENABLE					(0x1u<<14)
#define	DCMI_CR_EDM						(0x3u<<10)
#define	DCMI_CR_EDM_0					(0x1u<<10)
#define	DCMI_CR_FCRC					(0x3u<<8)
#define	DCMI_CR_FCRC_0					(0x1u<<8)
#define	DCMI_CR_VSPOL					(0x1u<<7)
#define	DCMI_CR_HSPOL					(0x1u<<6)
#define	DCMI_CR_PCKPOL					(0x1u<<5)
#define	DCMI_CR_ESS						(0x1u<<4)
#define	DCMI_CR_JPEG					(0x1u<<3)
#define	DCMI_CR_CROP					(0x1u<<2)
#define	DCMI_CR_CM						(0x1u<<1)
#define	DCMI_CR_CAPTURE					(0x1u<<0)

#define	DCMI_CR_OELS_B_0X0				(0x0u<<20)
#define	DCMI_CR_OELS_B_0X1				(0x1u<<20)
#define	DCMI_CR_LSM_B_0X0				(0x0u<<19)
#define	DCMI_CR_LSM_B_0X1				(0x1u<<19)
#define	DCMI_CR_OEBS_B_0X0				(0x0u<<18)
#define	DCMI_CR_OEBS_B_0X1				(0x1u<<18)
#define	DCMI_CR_BSM_B_0X0				(0x0u<<16)
#define	DCMI_CR_BSM_B_0X1				(0x1u<<16)
#define	DCMI_CR_BSM_B_0X2				(0x2u<<16)
#define	DCMI_CR_BSM_B_0X3				(0x3u<<16)
#define	DCMI_CR_ENABLE_B_0X0			(0x0u<<14)
#define	DCMI_CR_ENABLE_B_0X1			(0x1u<<14)
#define	DCMI_CR_EDM_B_0X0				(0x0u<<10)
#define	DCMI_CR_EDM_B_0X1				(0x1u<<10)
#define	DCMI_CR_EDM_B_0X2				(0x2u<<10)
#define	DCMI_CR_EDM_B_0X3				(0x3u<<10)
#define	DCMI_CR_FCRC_B_0X0				(0x0u<<8)
#define	DCMI_CR_FCRC_B_0X1				(0x1u<<8)
#define	DCMI_CR_FCRC_B_0X2				(0x2u<<8)
#define	DCMI_CR_VSPOL_B_0X0				(0x0u<<7)
#define	DCMI_CR_VSPOL_B_0X1				(0x1u<<7)
#define	DCMI_CR_HSPOL_B_0X0				(0x0u<<6)
#define	DCMI_CR_HSPOL_B_0X1				(0x1u<<6)
#define	DCMI_CR_PCKPOL_B_0X0			(0x0u<<5)
#define	DCMI_CR_PCKPOL_B_0X1			(0x1u<<5)
#define	DCMI_CR_ESS_B_0X0				(0x0u<<4)
#define	DCMI_CR_ESS_B_0X1				(0x1u<<4)
#define	DCMI_CR_JPEG_B_0X0				(0x0u<<3)
#define	DCMI_CR_JPEG_B_0X1				(0x1u<<3)
#define	DCMI_CR_CROP_B_0X0				(0x0u<<2)
#define	DCMI_CR_CROP_B_0X1				(0x1u<<2)
#define	DCMI_CR_CM_B_0X0				(0x0u<<1)
#define	DCMI_CR_CM_B_0X1				(0x1u<<1)
#define	DCMI_CR_CAPTURE_B_0X0			(0x0u<<0)
#define	DCMI_CR_CAPTURE_B_0X1			(0x1u<<0)

// SR Configuration

#define	DCMI_SR_FNE						(0x1u<<2)
#define	DCMI_SR_VSYNC					(0x1u<<1)
#define	DCMI_SR_HSYNC					(0x1u<<0)

#define	DCMI_SR_FNE_B_0X1				(0x1u<<2)
#define	DCMI_SR_FNE_B_0X0				(0x0u<<2)
#define	DCMI_SR_VSYNC_B_0X0				(0x0u<<1)
#define	DCMI_SR_VSYNC_B_0X1				(0x1u<<1)
#define	DCMI_SR_HSYNC_B_0X0				(0x0u<<0)
#define	DCMI_SR_HSYNC_B_0X1				(0x1u<<0)

// RIS Configuration

#define	DCMI_RIS_LINE_RIS				(0x1u<<4)
#define	DCMI_RIS_VSYNC_RIS				(0x1u<<3)
#define	DCMI_RIS_ERR_RIS				(0x1u<<2)
#define	DCMI_RIS_OVR_RIS				(0x1u<<1)
#define	DCMI_RIS_FRAME_RIS				(0x1u<<0)

#define	DCMI_RIS_ERR_RIS_B_0X0			(0x0u<<2)
#define	DCMI_RIS_ERR_RIS_B_0X1			(0x1u<<2)
#define	DCMI_RIS_OVR_RIS_B_0X0			(0x0u<<1)
#define	DCMI_RIS_OVR_RIS_B_0X1			(0x1u<<1)
#define	DCMI_RIS_FRAME_RIS_B_0X0		(0x0u<<0)
#define	DCMI_RIS_FRAME_RIS_B_0X1		(0x1u<<0)

// IER Configuration

#define	DCMI_IER_LINE_IE				(0x1u<<4)
#define	DCMI_IER_VSYNC_IE				(0x1u<<3)
#define	DCMI_IER_ERR_IE					(0x1u<<2)
#define	DCMI_IER_OVR_IE					(0x1u<<1)
#define	DCMI_IER_FRAME_IE				(0x1u<<0)

#define	DCMI_IER_LINE_IE_B_0X0			(0x0u<<4)
#define	DCMI_IER_LINE_IE_B_0X1			(0x1u<<4)
#define	DCMI_IER_VSYNC_IE_B_0X0			(0x0u<<3)
#define	DCMI_IER_VSYNC_IE_B_0X1			(0x1u<<3)
#define	DCMI_IER_ERR_IE_B_0X0			(0x0u<<2)
#define	DCMI_IER_ERR_IE_B_0X1			(0x1u<<2)
#define	DCMI_IER_OVR_IE_B_0X0			(0x0u<<1)
#define	DCMI_IER_OVR_IE_B_0X1			(0x1u<<1)
#define	DCMI_IER_FRAME_IE_B_0X0			(0x0u<<0)
#define	DCMI_IER_FRAME_IE_B_0X1			(0x1u<<0)

// MIS Configuration

#define	DCMI_MIS_LINE_MIS				(0x1u<<4)
#define	DCMI_MIS_VSYNC_MIS				(0x1u<<3)
#define	DCMI_MIS_ERR_MIS				(0x1u<<2)
#define	DCMI_MIS_OVR_MIS				(0x1u<<1)
#define	DCMI_MIS_FRAME_MIS				(0x1u<<0)

#define	DCMI_MIS_LINE_MIS_B_0X0			(0x0u<<4)
#define	DCMI_MIS_LINE_MIS_B_0X1			(0x1u<<4)
#define	DCMI_MIS_VSYNC_MIS_B_0X0		(0x0u<<3)
#define	DCMI_MIS_VSYNC_MIS_B_0X1		(0x1u<<3)
#define	DCMI_MIS_ERR_MIS_B_0X0			(0x0u<<2)
#define	DCMI_MIS_ERR_MIS_B_0X1			(0x1u<<2)
#define	DCMI_MIS_OVR_MIS_B_0X0			(0x0u<<1)
#define	DCMI_MIS_OVR_MIS_B_0X1			(0x1u<<1)
#define	DCMI_MIS_FRAME_MIS_B_0X0		(0x0u<<0)
#define	DCMI_MIS_FRAME_MIS_B_0X1		(0x1u<<0)

// ICR Configuration

#define	DCMI_ICR_LINE_ISC				(0x1u<<4)
#define	DCMI_ICR_VSYNC_ISC				(0x1u<<3)
#define	DCMI_ICR_ERR_ISC				(0x1u<<2)
#define	DCMI_ICR_OVR_ISC				(0x1u<<1)
#define	DCMI_ICR_FRAME_ISC				(0x1u<<0)

// ESCR Configuration

#define	DCMI_ESCR_FEC					(0xFFu<<24)
#define	DCMI_ESCR_FEC_0					(0x1u<<24)
#define	DCMI_ESCR_LEC					(0xFFu<<16)
#define	DCMI_ESCR_LEC_0					(0x1u<<16)
#define	DCMI_ESCR_LSC					(0xFFu<<8)
#define	DCMI_ESCR_LSC_0					(0x1u<<8)
#define	DCMI_ESCR_FSC					(0xFFu<<0)
#define	DCMI_ESCR_FSC_0					(0x1u<<0)

// ESUR Configuration

#define	DCMI_ESUR_FEU					(0xFFu<<24)
#define	DCMI_ESUR_FEU_0					(0x1u<<24)
#define	DCMI_ESUR_LEU					(0xFFu<<16)
#define	DCMI_ESUR_LEU_0					(0x1u<<16)
#define	DCMI_ESUR_LSU					(0xFFu<<8)
#define	DCMI_ESUR_LSU_0					(0x1u<<8)
#define	DCMI_ESUR_FSU					(0xFFu<<0)
#define	DCMI_ESUR_FSU_0					(0x1u<<0)

#define	DCMI_ESUR_FEU_B_0X0				(0x0u<<24)
#define	DCMI_ESUR_FEU_B_0X1				(0x1u<<24)
#define	DCMI_ESUR_LEU_B_0X0				(0x0u<<16)
#define	DCMI_ESUR_LEU_B_0X1				(0x1u<<16)
#define	DCMI_ESUR_LSU_B_0X0				(0x0u<<8)
#define	DCMI_ESUR_LSU_B_0X1				(0x1u<<8)
#define	DCMI_ESUR_FSU_B_0X0				(0x0u<<0)
#define	DCMI_ESUR_FSU_B_0X1				(0x1u<<0)

// CWSTRT Configuration

#define	DCMI_CWSTRT_VST					(0x1FFFu<<16)
#define	DCMI_CWSTRT_VST_0				(0x1u<<16)
#define	DCMI_CWSTRT_HOFFCNT				(0x3FFFu<<0)
#define	DCMI_CWSTRT_HOFFCNT_0			(0x1u<<0)

#define	DCMI_CWSTRT_VST_B_0X0000		(0x0u<<16)
#define	DCMI_CWSTRT_VST_B_0X0001		(0x1u<<16)
#define	DCMI_CWSTRT_VST_B_0X0002		(0x2u<<16)

// CWSIZE Configuration

#define	DCMI_CWSIZE_VLINE				(0x3FFFu<<16)
#define	DCMI_CWSIZE_VLINE_0				(0x1u<<16)
#define	DCMI_CWSIZE_CAPCNT				(0x3FFFu<<0)
#define	DCMI_CWSIZE_CAPCNT_0			(0x1u<<0)

#define	DCMI_CWSIZE_VLINE_B_0X0000		(0x0u<<16)
#define	DCMI_CWSIZE_VLINE_B_0X0001		(0x1u<<16)
#define	DCMI_CWSIZE_VLINE_B_0X0002		(0x2u<<16)
#define	DCMI_CWSIZE_CAPCNT_B_0X0000		(0x0u<<0)
#define	DCMI_CWSIZE_CAPCNT_B_0X0001		(0x1u<<0)
#define	DCMI_CWSIZE_CAPCNT_B_0X0002		(0x2u<<0)

// DR Configuration

#define	DCMI_DR_BYTE3					(0xFFu<<24)
#define	DCMI_DR_BYTE3_0					(0x1u<<24)
#define	DCMI_DR_BYTE2					(0xFFu<<16)
#define	DCMI_DR_BYTE2_0					(0x1u<<16)
#define	DCMI_DR_BYTE1					(0xFFu<<8)
#define	DCMI_DR_BYTE1_0					(0x1u<<8)
#define	DCMI_DR_BYTE0					(0xFFu<<0)
#define	DCMI_DR_BYTE0_0					(0x1u<<0)
