/*
; stm32N657_cryp.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_cryp equates.
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

// CRYP address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	DINR;
	volatile	uint32_t	DOUTR;
	volatile	uint32_t	DMACR;
	volatile	uint32_t	IMSCR;
	volatile	uint32_t	RISR;
	volatile	uint32_t	MISR;
	volatile	uint32_t	K0LR;
	volatile	uint32_t	K0RR;
	volatile	uint32_t	K1LR;
	volatile	uint32_t	K1RR;
	volatile	uint32_t	K2LR;
	volatile	uint32_t	K2RR;
	volatile	uint32_t	K3LR;
	volatile	uint32_t	K3RR;
	volatile	uint32_t	IV0LR;
	volatile	uint32_t	IV0RR;
	volatile	uint32_t	IV1LR;
	volatile	uint32_t	IV1RR;
	volatile	uint32_t	CSGCMCCM0R;
	volatile	uint32_t	CSGCMCCM1R;
	volatile	uint32_t	CSGCMCCM2R;
	volatile	uint32_t	CSGCMCCM3R;
	volatile	uint32_t	CSGCMCCM4R;
	volatile	uint32_t	CSGCMCCM5R;
	volatile	uint32_t	CSGCMCCM6R;
	volatile	uint32_t	CSGCMCCM7R;
	volatile	uint32_t	CSGCM0R;
	volatile	uint32_t	CSGCM1R;
	volatile	uint32_t	CSGCM2R;
	volatile	uint32_t	CSGCM3R;
	volatile	uint32_t	CSGCM4R;
	volatile	uint32_t	CSGCM5R;
	volatile	uint32_t	CSGCM6R;
	volatile	uint32_t	CSGCM7R;
} CRYP_TypeDef;

#if (defined(__cplusplus))
#define	CRYP_NS	reinterpret_cast<CRYP_TypeDef *>(0x44020800u)
#define	CRYP_S	reinterpret_cast<CRYP_TypeDef *>(0x54020800u)

#else
#define	CRYP_NS	((CRYP_TypeDef *)0x44020800u)
#define	CRYP_S	((CRYP_TypeDef *)0x54020800u)
#endif

// CR Configuration

#define	CRYP_CR_IPRST				(0x1u<<31)
#define	CRYP_CR_KMOD				(0x3u<<24)
#define	CRYP_CR_KMOD_0				(0x1u<<24)
#define	CRYP_CR_NPBLB				(0xFu<<20)
#define	CRYP_CR_NPBLB_0				(0x1u<<20)
#define	CRYP_CR_ALGOMODE_1			(0x1u<<19)
#define	CRYP_CR_GCM_CCMPH			(0x3u<<16)
#define	CRYP_CR_GCM_CCMPH_0			(0x1u<<16)
#define	CRYP_CR_CRYPEN				(0x1u<<15)
#define	CRYP_CR_FFLUSH				(0x1u<<14)
#define	CRYP_CR_KEYSIZE				(0x3u<<8)
#define	CRYP_CR_KEYSIZE_0			(0x1u<<8)
#define	CRYP_CR_DATATYPE			(0x3u<<6)
#define	CRYP_CR_DATATYPE_0			(0x1u<<6)
#define	CRYP_CR_ALGOMODE			(0x7u<<3)
#define	CRYP_CR_ALGOMODE_0			(0x1u<<3)
#define	CRYP_CR_ALGODIR				(0x1u<<2)

#define	CRYP_CR_KMOD_B_0X0			(0x0u<<24)
#define	CRYP_CR_KMOD_B_0X2			(0x2u<<24)
#define	CRYP_CR_NPBLB_B_0X0			(0x0u<<20)
#define	CRYP_CR_NPBLB_B_0X1			(0x1u<<20)
#define	CRYP_CR_NPBLB_B_0XF			(0xFu<<20)
#define	CRYP_CR_GCM_CCMPH_B_0X0		(0x0u<<16)
#define	CRYP_CR_GCM_CCMPH_B_0X1		(0x1u<<16)
#define	CRYP_CR_GCM_CCMPH_B_0X2		(0x2u<<16)
#define	CRYP_CR_GCM_CCMPH_B_0X3		(0x3u<<16)
#define	CRYP_CR_CRYPEN_B_0X0		(0x0u<<15)
#define	CRYP_CR_CRYPEN_B_0X1		(0x1u<<15)
#define	CRYP_CR_FFLUSH_B_0X0		(0x0u<<14)
#define	CRYP_CR_FFLUSH_B_0X1		(0x1u<<14)
#define	CRYP_CR_KEYSIZE_B_0X0		(0x0u<<8)
#define	CRYP_CR_KEYSIZE_B_0X1		(0x1u<<8)
#define	CRYP_CR_KEYSIZE_B_0X2		(0x2u<<8)
#define	CRYP_CR_DATATYPE_B_0X0		(0x0u<<6)
#define	CRYP_CR_DATATYPE_B_0X1		(0x1u<<6)
#define	CRYP_CR_DATATYPE_B_0X2		(0x2u<<6)
#define	CRYP_CR_DATATYPE_B_0X3		(0x3u<<6)
#define	CRYP_CR_ALGOMODE_B_0X4		(0x4u<<3)
#define	CRYP_CR_ALGOMODE_B_0X5		(0x5u<<3)
#define	CRYP_CR_ALGOMODE_B_0X6		(0x6u<<3)
#define	CRYP_CR_ALGOMODE_B_0X7		(0x7u<<3)
#define	CRYP_CR_ALGODIR_B_0X0		(0x0u<<2)
#define	CRYP_CR_ALGODIR_B_0X1		(0x1u<<2)

// SR Configuration

#define	CRYP_SR_KEYVALID			(0x1u<<7)
#define	CRYP_SR_KERF				(0x1u<<6)
#define	CRYP_SR_BUSY				(0x1u<<4)
#define	CRYP_SR_OFFU				(0x1u<<3)
#define	CRYP_SR_OFNE				(0x1u<<2)
#define	CRYP_SR_IFNF				(0x1u<<1)
#define	CRYP_SR_IFEM				(0x1u<<0)

#define	CRYP_SR_KEYVALID_B_0X0		(0x0u<<7)
#define	CRYP_SR_KEYVALID_B_0X1		(0x1u<<7)
#define	CRYP_SR_KERF_B_0X0			(0x0u<<6)
#define	CRYP_SR_KERF_B_0X1			(0x1u<<6)
#define	CRYP_SR_BUSY_B_0X0			(0x0u<<4)
#define	CRYP_SR_BUSY_B_0X1			(0x1u<<4)
#define	CRYP_SR_OFFU_B_0X0			(0x0u<<3)
#define	CRYP_SR_OFFU_B_0X1			(0x1u<<3)
#define	CRYP_SR_OFNE_B_0X0			(0x0u<<2)
#define	CRYP_SR_OFNE_B_0X1			(0x1u<<2)
#define	CRYP_SR_IFNF_B_0X0			(0x0u<<1)
#define	CRYP_SR_IFNF_B_0X1			(0x1u<<1)
#define	CRYP_SR_IFEM_B_0X0			(0x0u<<0)
#define	CRYP_SR_IFEM_B_0X1			(0x1u<<0)

// DINR Configuration

#define	CRYP_DINR_DIN				(0xFFFFFFFFu<<0)
#define	CRYP_DINR_DIN_0				(0x1u<<0)

// DOUTR Configuration

#define	CRYP_DOUTR_DOUT				(0xFFFFFFFFu<<0)
#define	CRYP_DOUTR_DOUT_0			(0x1u<<0)

// DMACR Configuration

#define	CRYP_DMACR_DOEN				(0x1u<<1)
#define	CRYP_DMACR_DIEN				(0x1u<<0)

#define	CRYP_DMACR_DOEN_B_0X0		(0x0u<<1)
#define	CRYP_DMACR_DOEN_B_0X1		(0x1u<<1)
#define	CRYP_DMACR_DIEN_B_0X0		(0x0u<<0)
#define	CRYP_DMACR_DIEN_B_0X1		(0x1u<<0)

// IMSCR Configuration

#define	CRYP_IMSCR_OUTIM			(0x1u<<1)
#define	CRYP_IMSCR_INIM				(0x1u<<0)

#define	CRYP_IMSCR_OUTIM_B_0X0		(0x0u<<1)
#define	CRYP_IMSCR_OUTIM_B_0X1		(0x1u<<1)
#define	CRYP_IMSCR_INIM_B_0X0		(0x0u<<0)
#define	CRYP_IMSCR_INIM_B_0X1		(0x1u<<0)

// RISR Configuration

#define	CRYP_RISR_OUTRIS			(0x1u<<1)
#define	CRYP_RISR_INRIS				(0x1u<<0)

#define	CRYP_RISR_OUTRIS_B_0X0		(0x0u<<1)
#define	CRYP_RISR_OUTRIS_B_0X1		(0x1u<<1)
#define	CRYP_RISR_INRIS_B_0X0		(0x0u<<0)
#define	CRYP_RISR_INRIS_B_0X1		(0x1u<<0)

// MISR Configuration

#define	CRYP_MISR_OUTMIS			(0x1u<<1)
#define	CRYP_MISR_INMIS				(0x1u<<0)

#define	CRYP_MISR_OUTMIS_B_0X0		(0x0u<<1)
#define	CRYP_MISR_OUTMIS_B_0X1		(0x1u<<1)
#define	CRYP_MISR_INMIS_B_0X0		(0x0u<<0)
#define	CRYP_MISR_INMIS_B_0X1		(0x1u<<0)

// K0LR Configuration

#define	CRYP_K0LR_K					(0xFFFFFFFFu<<0)
#define	CRYP_K0LR_K_0				(0x1u<<0)

// K0RR Configuration

#define	CRYP_K0RR_K					(0xFFFFFFFFu<<0)
#define	CRYP_K0RR_K_0				(0x1u<<0)

// K1LR Configuration

#define	CRYP_K1LR_K					(0xFFFFFFFFu<<0)
#define	CRYP_K1LR_K_0				(0x1u<<0)

// K1RR Configuration

#define	CRYP_K1RR_K					(0xFFFFFFFFu<<0)
#define	CRYP_K1RR_K_0				(0x1u<<0)

// K2LR Configuration

#define	CRYP_K2LR_K					(0xFFFFFFFFu<<0)
#define	CRYP_K2LR_K_0				(0x1u<<0)

// K2RR Configuration

#define	CRYP_K2RR_K					(0xFFFFFFFFu<<0)
#define	CRYP_K2RR_K_0				(0x1u<<0)

// K3LR Configuration

#define	CRYP_K3LR_K					(0xFFFFFFFFu<<0)
#define	CRYP_K3LR_K_0				(0x1u<<0)

// K3RR Configuration

#define	CRYP_K3RR_K					(0xFFFFFFFFu<<0)
#define	CRYP_K3RR_K_0				(0x1u<<0)

// IV0LR Configuration

#define	CRYP_IV0LR_IVI				(0xFFFFFFFFu<<0)
#define	CRYP_IV0LR_IVI_0			(0x1u<<0)

// IV0RR Configuration

#define	CRYP_IV0RR_IVI				(0xFFFFFFFFu<<0)
#define	CRYP_IV0RR_IVI_0			(0x1u<<0)

// IV1LR Configuration

#define	CRYP_IV1LR_IVI				(0xFFFFFFFFu<<0)
#define	CRYP_IV1LR_IVI_0			(0x1u<<0)

// IV1RR Configuration

#define	CRYP_IV1RR_IVI				(0xFFFFFFFFu<<0)
#define	CRYP_IV1RR_IVI_0			(0x1u<<0)

// CSGCMCCM0R Configuration

#define	CRYP_CSGCMCCM0R_CSGCMCCM	(0xFFFFFFFFu<<0)
#define	CRYP_CSGCMCCM0R_CSGCMCCM_0	(0x1u<<0)

// CSGCMCCM1R Configuration

#define	CRYP_CSGCMCCM1R_CSGCMCCM	(0xFFFFFFFFu<<0)
#define	CRYP_CSGCMCCM1R_CSGCMCCM_0	(0x1u<<0)

// CSGCMCCM2R Configuration

#define	CRYP_CSGCMCCM2R_CSGCMCCM	(0xFFFFFFFFu<<0)
#define	CRYP_CSGCMCCM2R_CSGCMCCM_0	(0x1u<<0)

// CSGCMCCM3R Configuration

#define	CRYP_CSGCMCCM3R_CSGCMCCM	(0xFFFFFFFFu<<0)
#define	CRYP_CSGCMCCM3R_CSGCMCCM_0	(0x1u<<0)

// CSGCMCCM4R Configuration

#define	CRYP_CSGCMCCM4R_CSGCMCCM	(0xFFFFFFFFu<<0)
#define	CRYP_CSGCMCCM4R_CSGCMCCM_0	(0x1u<<0)

// CSGCMCCM5R Configuration

#define	CRYP_CSGCMCCM5R_CSGCMCCM	(0xFFFFFFFFu<<0)
#define	CRYP_CSGCMCCM5R_CSGCMCCM_0	(0x1u<<0)

// CSGCMCCM6R Configuration

#define	CRYP_CSGCMCCM6R_CSGCMCCM	(0xFFFFFFFFu<<0)
#define	CRYP_CSGCMCCM6R_CSGCMCCM_0	(0x1u<<0)

// CSGCMCCM7R Configuration

#define	CRYP_CSGCMCCM7R_CSGCMCCM	(0xFFFFFFFFu<<0)
#define	CRYP_CSGCMCCM7R_CSGCMCCM_0	(0x1u<<0)

// CSGCM0R Configuration

#define	CRYP_CSGCM0R_CSGCM			(0xFFFFFFFFu<<0)
#define	CRYP_CSGCM0R_CSGCM_0		(0x1u<<0)

// CSGCM1R Configuration

#define	CRYP_CSGCM1R_CSGCM			(0xFFFFFFFFu<<0)
#define	CRYP_CSGCM1R_CSGCM_0		(0x1u<<0)

// CSGCM2R Configuration

#define	CRYP_CSGCM2R_CSGCM			(0xFFFFFFFFu<<0)
#define	CRYP_CSGCM2R_CSGCM_0		(0x1u<<0)

// CSGCM3R Configuration

#define	CRYP_CSGCM3R_CSGCM			(0xFFFFFFFFu<<0)
#define	CRYP_CSGCM3R_CSGCM_0		(0x1u<<0)

// CSGCM4R Configuration

#define	CRYP_CSGCM4R_CSGCM			(0xFFFFFFFFu<<0)
#define	CRYP_CSGCM4R_CSGCM_0		(0x1u<<0)

// CSGCM5R Configuration

#define	CRYP_CSGCM5R_CSGCM			(0xFFFFFFFFu<<0)
#define	CRYP_CSGCM5R_CSGCM_0		(0x1u<<0)

// CSGCM6R Configuration

#define	CRYP_CSGCM6R_CSGCM			(0xFFFFFFFFu<<0)
#define	CRYP_CSGCM6R_CSGCM_0		(0x1u<<0)

// CSGCM7R Configuration

#define	CRYP_CSGCM7R_CSGCM			(0xFFFFFFFFu<<0)
#define	CRYP_CSGCM7R_CSGCM_0		(0x1u<<0)
