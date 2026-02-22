/*
; RP2350_i2c.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_i2c equates.
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

// I2C0 address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CON;
	volatile	uint32_t	TAR;
	volatile	uint32_t	SAR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	DATA_CMD;
	volatile	uint32_t	SS_SCL_HCNT;
	volatile	uint32_t	SS_SCL_LCNT;
	volatile	uint32_t	FS_SCL_HCNT;
	volatile	uint32_t	FS_SCL_LCNT;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	INTR_STAT;
	volatile	uint32_t	INTR_MASK;
	volatile	uint32_t	RAW_INTR_STAT;
	volatile	uint32_t	RX_TL;
	volatile	uint32_t	TX_TL;
	volatile	uint32_t	CLR_INTR;
	volatile	uint32_t	CLR_RX_UNDER;
	volatile	uint32_t	CLR_RX_OVER;
	volatile	uint32_t	CLR_TX_OVER;
	volatile	uint32_t	CLR_RD_REQ;
	volatile	uint32_t	CLR_TX_ABRT;
	volatile	uint32_t	CLR_RX_DONE;
	volatile	uint32_t	CLR_ACTIVITY;
	volatile	uint32_t	CLR_STOP_DET;
	volatile	uint32_t	CLR_START_DET;
	volatile	uint32_t	CLR_GEN_CALL;
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	STATUS;
	volatile	uint32_t	TXFLR;
	volatile	uint32_t	RXFLR;
	volatile	uint32_t	SDA_HOLD;
	volatile	uint32_t	TX_ABRT_SOURCE;
	volatile	uint32_t	SLV_DATA_NACK_ONLY;
	volatile	uint32_t	DMA_CR;
	volatile	uint32_t	DMA_TDLR;
	volatile	uint32_t	DMA_RDLR;
	volatile	uint32_t	SDA_SETUP;
	volatile	uint32_t	ACK_GENERAL_CALL;
	volatile	uint32_t	ENABLE_STATUS;
	volatile	uint32_t	FS_SPKLEN;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	CLR_RESTART_DET;
	volatile	uint32_t	RESERVED3[18];
	volatile	uint32_t	COMP_PARAM_1;
	volatile	uint32_t	COMP_VERSION;
	volatile	uint32_t	COMP_TYPE;
} I2C_TypeDef;

#ifdef __cplusplus
#define	I2C0_NS	reinterpret_cast<I2C_TypeDef *>(0x40090000u)
#define	I2C0_S	reinterpret_cast<I2C_TypeDef *>(0x40090000u)
#define	I2C1_NS	reinterpret_cast<I2C_TypeDef *>(0x40098000u)
#define	I2C1_S	reinterpret_cast<I2C_TypeDef *>(0x40098000u)
#else
#define	I2C0_NS	((I2C_TypeDef *)0x40090000u)
#define	I2C0_S	((I2C_TypeDef *)0x40090000u)
#define	I2C1_NS	((I2C_TypeDef *)0x40098000u)
#define	I2C1_S	((I2C_TypeDef *)0x40098000u)
#endif

// CON Configuration

#define	I2C_CON_MASTER_MODE														(0x1u<<0)
#define	I2C_CON_SPEED															(0x3u<<1)
#define	I2C_CON_SPEED_0															(0x1u<<1)
#define	I2C_CON_IC_10BITADDR_SLAVE												(0x1u<<3)
#define	I2C_CON_IC_10BITADDR_MASTER												(0x1u<<4)
#define	I2C_CON_IC_RESTART_EN													(0x1u<<5)
#define	I2C_CON_IC_SLAVE_DISABLE												(0x1u<<6)
#define	I2C_CON_STOP_DET_IFADDRESSED											(0x1u<<7)
#define	I2C_CON_TX_EMPTY_CTRL													(0x1u<<8)
#define	I2C_CON_RX_FIFO_FULL_HLD_CTRL											(0x1u<<9)
#define	I2C_CON_STOP_DET_IF_MASTER_ACTIVE										(0x1u<<10)
#define	I2C_CON_MASTER_MODE_DISABLED											(0x0u<<0)
#define	I2C_CON_MASTER_MODE_ENABLED												(0x1u<<0)
#define	I2C_CON_SPEED_STANDARD													(0x1u<<1)
#define	I2C_CON_SPEED_FAST														(0x2u<<1)
#define	I2C_CON_SPEED_HIGH														(0x3u<<1)
#define	I2C_CON_IC_10BITADDR_SLAVE_ADDR_7BITS									(0x0u<<3)
#define	I2C_CON_IC_10BITADDR_SLAVE_ADDR_10BITS									(0x1u<<3)
#define	I2C_CON_IC_10BITADDR_MASTER_ADDR_7BITS									(0x0u<<4)
#define	I2C_CON_IC_10BITADDR_MASTER_ADDR_10BITS									(0x1u<<4)
#define	I2C_CON_IC_RESTART_EN_DISABLED											(0x0u<<5)
#define	I2C_CON_IC_RESTART_EN_ENABLED											(0x1u<<5)
#define	I2C_CON_IC_SLAVE_DISABLE_SLAVE_ENABLED									(0x0u<<6)
#define	I2C_CON_IC_SLAVE_DISABLE_SLAVE_DISABLED									(0x1u<<6)
#define	I2C_CON_STOP_DET_IFADDRESSED_DISABLED									(0x0u<<7)
#define	I2C_CON_STOP_DET_IFADDRESSED_ENABLED									(0x1u<<7)
#define	I2C_CON_TX_EMPTY_CTRL_DISABLED											(0x0u<<8)
#define	I2C_CON_TX_EMPTY_CTRL_ENABLED											(0x1u<<8)
#define	I2C_CON_RX_FIFO_FULL_HLD_CTRL_DISABLED									(0x0u<<9)
#define	I2C_CON_RX_FIFO_FULL_HLD_CTRL_ENABLED									(0x1u<<9)

// TAR Configuration

#define	I2C_TAR_IC_TAR															(0x3FFu<<0)
#define	I2C_TAR_IC_TAR_0														(0x1u<<0)
#define	I2C_TAR_GC_OR_START														(0x1u<<10)
#define	I2C_TAR_SPECIAL															(0x1u<<11)
#define	I2C_TAR_GC_OR_START_GENERAL_CALL										(0x0u<<10)
#define	I2C_TAR_GC_OR_START_START_BYTE											(0x1u<<10)
#define	I2C_TAR_SPECIAL_DISABLED												(0x0u<<11)
#define	I2C_TAR_SPECIAL_ENABLED													(0x1u<<11)

// SAR Configuration

#define	I2C_SAR_IC_SAR															(0x3FFu<<0)
#define	I2C_SAR_IC_SAR_0														(0x1u<<0)

// DATA_CMD Configuration

#define	I2C_DATA_CMD_DAT														(0xFFu<<0)
#define	I2C_DATA_CMD_DAT_0														(0x1u<<0)
#define	I2C_DATA_CMD_CMD														(0x1u<<8)
#define	I2C_DATA_CMD_STOP														(0x1u<<9)
#define	I2C_DATA_CMD_RESTART													(0x1u<<10)
#define	I2C_DATA_CMD_FIRST_DATA_BYTE											(0x1u<<11)
#define	I2C_DATA_CMD_CMD_WRITE													(0x0u<<8)
#define	I2C_DATA_CMD_CMD_READ													(0x1u<<8)
#define	I2C_DATA_CMD_STOP_DISABLE												(0x0u<<9)
#define	I2C_DATA_CMD_STOP_ENABLE												(0x1u<<9)
#define	I2C_DATA_CMD_RESTART_DISABLE											(0x0u<<10)
#define	I2C_DATA_CMD_RESTART_ENABLE												(0x1u<<10)
#define	I2C_DATA_CMD_FIRST_DATA_BYTE_INACTIVE									(0x0u<<11)
#define	I2C_DATA_CMD_FIRST_DATA_BYTE_ACTIVE										(0x1u<<11)

// SS_SCL_HCNT Configuration

#define	I2C_SS_SCL_HCNT_IC_SS_SCL_HCNT											(0xFFFFu<<0)
#define	I2C_SS_SCL_HCNT_IC_SS_SCL_HCNT_0										(0x1u<<0)

// SS_SCL_LCNT Configuration

#define	I2C_SS_SCL_LCNT_IC_SS_SCL_LCNT											(0xFFFFu<<0)
#define	I2C_SS_SCL_LCNT_IC_SS_SCL_LCNT_0										(0x1u<<0)

// FS_SCL_HCNT Configuration

#define	I2C_FS_SCL_HCNT_IC_FS_SCL_HCNT											(0xFFFFu<<0)
#define	I2C_FS_SCL_HCNT_IC_FS_SCL_HCNT_0										(0x1u<<0)

// FS_SCL_LCNT Configuration

#define	I2C_FS_SCL_LCNT_IC_FS_SCL_LCNT											(0xFFFFu<<0)
#define	I2C_FS_SCL_LCNT_IC_FS_SCL_LCNT_0										(0x1u<<0)

// INTR_STAT Configuration

#define	I2C_INTR_STAT_R_RX_UNDER												(0x1u<<0)
#define	I2C_INTR_STAT_R_RX_OVER													(0x1u<<1)
#define	I2C_INTR_STAT_R_RX_FULL													(0x1u<<2)
#define	I2C_INTR_STAT_R_TX_OVER													(0x1u<<3)
#define	I2C_INTR_STAT_R_TX_EMPTY												(0x1u<<4)
#define	I2C_INTR_STAT_R_RD_REQ													(0x1u<<5)
#define	I2C_INTR_STAT_R_TX_ABRT													(0x1u<<6)
#define	I2C_INTR_STAT_R_RX_DONE													(0x1u<<7)
#define	I2C_INTR_STAT_R_ACTIVITY												(0x1u<<8)
#define	I2C_INTR_STAT_R_STOP_DET												(0x1u<<9)
#define	I2C_INTR_STAT_R_START_DET												(0x1u<<10)
#define	I2C_INTR_STAT_R_GEN_CALL												(0x1u<<11)
#define	I2C_INTR_STAT_R_RESTART_DET												(0x1u<<12)
#define	I2C_INTR_STAT_R_RX_UNDER_INACTIVE										(0x0u<<0)
#define	I2C_INTR_STAT_R_RX_UNDER_ACTIVE											(0x1u<<0)
#define	I2C_INTR_STAT_R_RX_OVER_INACTIVE										(0x0u<<1)
#define	I2C_INTR_STAT_R_RX_OVER_ACTIVE											(0x1u<<1)
#define	I2C_INTR_STAT_R_RX_FULL_INACTIVE										(0x0u<<2)
#define	I2C_INTR_STAT_R_RX_FULL_ACTIVE											(0x1u<<2)
#define	I2C_INTR_STAT_R_TX_OVER_INACTIVE										(0x0u<<3)
#define	I2C_INTR_STAT_R_TX_OVER_ACTIVE											(0x1u<<3)
#define	I2C_INTR_STAT_R_TX_EMPTY_INACTIVE										(0x0u<<4)
#define	I2C_INTR_STAT_R_TX_EMPTY_ACTIVE											(0x1u<<4)
#define	I2C_INTR_STAT_R_RD_REQ_INACTIVE											(0x0u<<5)
#define	I2C_INTR_STAT_R_RD_REQ_ACTIVE											(0x1u<<5)
#define	I2C_INTR_STAT_R_TX_ABRT_INACTIVE										(0x0u<<6)
#define	I2C_INTR_STAT_R_TX_ABRT_ACTIVE											(0x1u<<6)
#define	I2C_INTR_STAT_R_RX_DONE_INACTIVE										(0x0u<<7)
#define	I2C_INTR_STAT_R_RX_DONE_ACTIVE											(0x1u<<7)
#define	I2C_INTR_STAT_R_ACTIVITY_INACTIVE										(0x0u<<8)
#define	I2C_INTR_STAT_R_ACTIVITY_ACTIVE											(0x1u<<8)
#define	I2C_INTR_STAT_R_STOP_DET_INACTIVE										(0x0u<<9)
#define	I2C_INTR_STAT_R_STOP_DET_ACTIVE											(0x1u<<9)
#define	I2C_INTR_STAT_R_START_DET_INACTIVE										(0x0u<<10)
#define	I2C_INTR_STAT_R_START_DET_ACTIVE										(0x1u<<10)
#define	I2C_INTR_STAT_R_GEN_CALL_INACTIVE										(0x0u<<11)
#define	I2C_INTR_STAT_R_GEN_CALL_ACTIVE											(0x1u<<11)
#define	I2C_INTR_STAT_R_RESTART_DET_INACTIVE									(0x0u<<12)
#define	I2C_INTR_STAT_R_RESTART_DET_ACTIVE										(0x1u<<12)

// INTR_MASK Configuration

#define	I2C_INTR_MASK_M_RX_UNDER												(0x1u<<0)
#define	I2C_INTR_MASK_M_RX_OVER													(0x1u<<1)
#define	I2C_INTR_MASK_M_RX_FULL													(0x1u<<2)
#define	I2C_INTR_MASK_M_TX_OVER													(0x1u<<3)
#define	I2C_INTR_MASK_M_TX_EMPTY												(0x1u<<4)
#define	I2C_INTR_MASK_M_RD_REQ													(0x1u<<5)
#define	I2C_INTR_MASK_M_TX_ABRT													(0x1u<<6)
#define	I2C_INTR_MASK_M_RX_DONE													(0x1u<<7)
#define	I2C_INTR_MASK_M_ACTIVITY												(0x1u<<8)
#define	I2C_INTR_MASK_M_STOP_DET												(0x1u<<9)
#define	I2C_INTR_MASK_M_START_DET												(0x1u<<10)
#define	I2C_INTR_MASK_M_GEN_CALL												(0x1u<<11)
#define	I2C_INTR_MASK_M_RESTART_DET												(0x1u<<12)
#define	I2C_INTR_MASK_M_RX_UNDER_ENABLED										(0x0u<<0)
#define	I2C_INTR_MASK_M_RX_UNDER_DISABLED										(0x1u<<0)
#define	I2C_INTR_MASK_M_RX_OVER_ENABLED											(0x0u<<1)
#define	I2C_INTR_MASK_M_RX_OVER_DISABLED										(0x1u<<1)
#define	I2C_INTR_MASK_M_RX_FULL_ENABLED											(0x0u<<2)
#define	I2C_INTR_MASK_M_RX_FULL_DISABLED										(0x1u<<2)
#define	I2C_INTR_MASK_M_TX_OVER_ENABLED											(0x0u<<3)
#define	I2C_INTR_MASK_M_TX_OVER_DISABLED										(0x1u<<3)
#define	I2C_INTR_MASK_M_TX_EMPTY_ENABLED										(0x0u<<4)
#define	I2C_INTR_MASK_M_TX_EMPTY_DISABLED										(0x1u<<4)
#define	I2C_INTR_MASK_M_RD_REQ_ENABLED											(0x0u<<5)
#define	I2C_INTR_MASK_M_RD_REQ_DISABLED											(0x1u<<5)
#define	I2C_INTR_MASK_M_TX_ABRT_ENABLED											(0x0u<<6)
#define	I2C_INTR_MASK_M_TX_ABRT_DISABLED										(0x1u<<6)
#define	I2C_INTR_MASK_M_RX_DONE_ENABLED											(0x0u<<7)
#define	I2C_INTR_MASK_M_RX_DONE_DISABLED										(0x1u<<7)
#define	I2C_INTR_MASK_M_ACTIVITY_ENABLED										(0x0u<<8)
#define	I2C_INTR_MASK_M_ACTIVITY_DISABLED										(0x1u<<8)
#define	I2C_INTR_MASK_M_STOP_DET_ENABLED										(0x0u<<9)
#define	I2C_INTR_MASK_M_STOP_DET_DISABLED										(0x1u<<9)
#define	I2C_INTR_MASK_M_START_DET_ENABLED										(0x0u<<10)
#define	I2C_INTR_MASK_M_START_DET_DISABLED										(0x1u<<10)
#define	I2C_INTR_MASK_M_GEN_CALL_ENABLED										(0x0u<<11)
#define	I2C_INTR_MASK_M_GEN_CALL_DISABLED										(0x1u<<11)
#define	I2C_INTR_MASK_M_RESTART_DET_ENABLED										(0x0u<<12)
#define	I2C_INTR_MASK_M_RESTART_DET_DISABLED									(0x1u<<12)

// RAW_INTR_STAT Configuration

#define	I2C_RAW_INTR_STAT_RX_UNDER												(0x1u<<0)
#define	I2C_RAW_INTR_STAT_RX_OVER												(0x1u<<1)
#define	I2C_RAW_INTR_STAT_RX_FULL												(0x1u<<2)
#define	I2C_RAW_INTR_STAT_TX_OVER												(0x1u<<3)
#define	I2C_RAW_INTR_STAT_TX_EMPTY												(0x1u<<4)
#define	I2C_RAW_INTR_STAT_RD_REQ												(0x1u<<5)
#define	I2C_RAW_INTR_STAT_TX_ABRT												(0x1u<<6)
#define	I2C_RAW_INTR_STAT_RX_DONE												(0x1u<<7)
#define	I2C_RAW_INTR_STAT_ACTIVITY												(0x1u<<8)
#define	I2C_RAW_INTR_STAT_STOP_DET												(0x1u<<9)
#define	I2C_RAW_INTR_STAT_START_DET												(0x1u<<10)
#define	I2C_RAW_INTR_STAT_GEN_CALL												(0x1u<<11)
#define	I2C_RAW_INTR_STAT_RESTART_DET											(0x1u<<12)
#define	I2C_RAW_INTR_STAT_RX_UNDER_INACTIVE										(0x0u<<0)
#define	I2C_RAW_INTR_STAT_RX_UNDER_ACTIVE										(0x1u<<0)
#define	I2C_RAW_INTR_STAT_RX_OVER_INACTIVE										(0x0u<<1)
#define	I2C_RAW_INTR_STAT_RX_OVER_ACTIVE										(0x1u<<1)
#define	I2C_RAW_INTR_STAT_RX_FULL_INACTIVE										(0x0u<<2)
#define	I2C_RAW_INTR_STAT_RX_FULL_ACTIVE										(0x1u<<2)
#define	I2C_RAW_INTR_STAT_TX_OVER_INACTIVE										(0x0u<<3)
#define	I2C_RAW_INTR_STAT_TX_OVER_ACTIVE										(0x1u<<3)
#define	I2C_RAW_INTR_STAT_TX_EMPTY_INACTIVE										(0x0u<<4)
#define	I2C_RAW_INTR_STAT_TX_EMPTY_ACTIVE										(0x1u<<4)
#define	I2C_RAW_INTR_STAT_RD_REQ_INACTIVE										(0x0u<<5)
#define	I2C_RAW_INTR_STAT_RD_REQ_ACTIVE											(0x1u<<5)
#define	I2C_RAW_INTR_STAT_TX_ABRT_INACTIVE										(0x0u<<6)
#define	I2C_RAW_INTR_STAT_TX_ABRT_ACTIVE										(0x1u<<6)
#define	I2C_RAW_INTR_STAT_RX_DONE_INACTIVE										(0x0u<<7)
#define	I2C_RAW_INTR_STAT_RX_DONE_ACTIVE										(0x1u<<7)
#define	I2C_RAW_INTR_STAT_ACTIVITY_INACTIVE										(0x0u<<8)
#define	I2C_RAW_INTR_STAT_ACTIVITY_ACTIVE										(0x1u<<8)
#define	I2C_RAW_INTR_STAT_STOP_DET_INACTIVE										(0x0u<<9)
#define	I2C_RAW_INTR_STAT_STOP_DET_ACTIVE										(0x1u<<9)
#define	I2C_RAW_INTR_STAT_START_DET_INACTIVE									(0x0u<<10)
#define	I2C_RAW_INTR_STAT_START_DET_ACTIVE										(0x1u<<10)
#define	I2C_RAW_INTR_STAT_GEN_CALL_INACTIVE										(0x0u<<11)
#define	I2C_RAW_INTR_STAT_GEN_CALL_ACTIVE										(0x1u<<11)
#define	I2C_RAW_INTR_STAT_RESTART_DET_INACTIVE									(0x0u<<12)
#define	I2C_RAW_INTR_STAT_RESTART_DET_ACTIVE									(0x1u<<12)

// RX_TL Configuration

#define	I2C_RX_TL_RX_TL															(0xFFu<<0)
#define	I2C_RX_TL_RX_TL_0														(0x1u<<0)

// TX_TL Configuration

#define	I2C_TX_TL_TX_TL															(0xFFu<<0)
#define	I2C_TX_TL_TX_TL_0														(0x1u<<0)

// CLR_INTR Configuration

#define	I2C_CLR_INTR_CLR_INTR													(0x1u<<0)

// CLR_RX_UNDER Configuration

#define	I2C_CLR_RX_UNDER_CLR_RX_UNDER											(0x1u<<0)

// CLR_RX_OVER Configuration

#define	I2C_CLR_RX_OVER_CLR_RX_OVER												(0x1u<<0)

// CLR_TX_OVER Configuration

#define	I2C_CLR_TX_OVER_CLR_TX_OVER												(0x1u<<0)

// CLR_RD_REQ Configuration

#define	I2C_CLR_RD_REQ_CLR_RD_REQ												(0x1u<<0)

// CLR_TX_ABRT Configuration

#define	I2C_CLR_TX_ABRT_CLR_TX_ABRT												(0x1u<<0)

// CLR_RX_DONE Configuration

#define	I2C_CLR_RX_DONE_CLR_RX_DONE												(0x1u<<0)

// CLR_ACTIVITY Configuration

#define	I2C_CLR_ACTIVITY_CLR_ACTIVITY											(0x1u<<0)

// CLR_STOP_DET Configuration

#define	I2C_CLR_STOP_DET_CLR_STOP_DET											(0x1u<<0)

// CLR_START_DET Configuration

#define	I2C_CLR_START_DET_CLR_START_DET											(0x1u<<0)

// CLR_GEN_CALL Configuration

#define	I2C_CLR_GEN_CALL_CLR_GEN_CALL											(0x1u<<0)

// ENABLE Configuration

#define	I2C_ENABLE_ENABLE														(0x1u<<0)
#define	I2C_ENABLE_ABORT														(0x1u<<1)
#define	I2C_ENABLE_TX_CMD_BLOCK													(0x1u<<2)
#define	I2C_ENABLE_ENABLE_DISABLED												(0x0u<<0)
#define	I2C_ENABLE_ENABLE_ENABLED												(0x1u<<0)
#define	I2C_ENABLE_ABORT_DISABLE												(0x0u<<1)
#define	I2C_ENABLE_ABORT_ENABLED												(0x1u<<1)
#define	I2C_ENABLE_TX_CMD_BLOCK_NOT_BLOCKED										(0x0u<<2)
#define	I2C_ENABLE_TX_CMD_BLOCK_BLOCKED											(0x1u<<2)

// STATUS Configuration

#define	I2C_STATUS_ACTIVITY														(0x1u<<0)
#define	I2C_STATUS_TFNF															(0x1u<<1)
#define	I2C_STATUS_TFE															(0x1u<<2)
#define	I2C_STATUS_RFNE															(0x1u<<3)
#define	I2C_STATUS_RFF															(0x1u<<4)
#define	I2C_STATUS_MST_ACTIVITY													(0x1u<<5)
#define	I2C_STATUS_SLV_ACTIVITY													(0x1u<<6)
#define	I2C_STATUS_ACTIVITY_INACTIVE											(0x0u<<0)
#define	I2C_STATUS_ACTIVITY_ACTIVE												(0x1u<<0)
#define	I2C_STATUS_TFNF_FULL													(0x0u<<1)
#define	I2C_STATUS_TFNF_NOT_FULL												(0x1u<<1)
#define	I2C_STATUS_TFE_NON_EMPTY												(0x0u<<2)
#define	I2C_STATUS_TFE_EMPTY													(0x1u<<2)
#define	I2C_STATUS_RFNE_EMPTY													(0x0u<<3)
#define	I2C_STATUS_RFNE_NOT_EMPTY												(0x1u<<3)
#define	I2C_STATUS_RFF_NOT_FULL													(0x0u<<4)
#define	I2C_STATUS_RFF_FULL														(0x1u<<4)
#define	I2C_STATUS_MST_ACTIVITY_IDLE											(0x0u<<5)
#define	I2C_STATUS_MST_ACTIVITY_ACTIVE											(0x1u<<5)
#define	I2C_STATUS_SLV_ACTIVITY_IDLE											(0x0u<<6)
#define	I2C_STATUS_SLV_ACTIVITY_ACTIVE											(0x1u<<6)

// TXFLR Configuration

#define	I2C_TXFLR_TXFLR															(0x1Fu<<0)
#define	I2C_TXFLR_TXFLR_0														(0x1u<<0)

// RXFLR Configuration

#define	I2C_RXFLR_RXFLR															(0x1Fu<<0)
#define	I2C_RXFLR_RXFLR_0														(0x1u<<0)

// SDA_HOLD Configuration

#define	I2C_SDA_HOLD_IC_SDA_TX_HOLD												(0xFFFFu<<0)
#define	I2C_SDA_HOLD_IC_SDA_TX_HOLD_0											(0x1u<<0)
#define	I2C_SDA_HOLD_IC_SDA_RX_HOLD												(0xFFu<<16)
#define	I2C_SDA_HOLD_IC_SDA_RX_HOLD_0											(0x1u<<16)

// TX_ABRT_SOURCE Configuration

#define	I2C_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK									(0x1u<<0)
#define	I2C_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK									(0x1u<<1)
#define	I2C_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK									(0x1u<<2)
#define	I2C_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK									(0x1u<<3)
#define	I2C_TX_ABRT_SOURCE_ABRT_GCALL_NOACK										(0x1u<<4)
#define	I2C_TX_ABRT_SOURCE_ABRT_GCALL_READ										(0x1u<<5)
#define	I2C_TX_ABRT_SOURCE_ABRT_HS_ACKDET										(0x1u<<6)
#define	I2C_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET									(0x1u<<7)
#define	I2C_TX_ABRT_SOURCE_ABRT_HS_NORSTRT										(0x1u<<8)
#define	I2C_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT									(0x1u<<9)
#define	I2C_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT									(0x1u<<10)
#define	I2C_TX_ABRT_SOURCE_ABRT_MASTER_DIS										(0x1u<<11)
#define	I2C_TX_ABRT_SOURCE_ARB_LOST												(0x1u<<12)
#define	I2C_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO									(0x1u<<13)
#define	I2C_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST										(0x1u<<14)
#define	I2C_TX_ABRT_SOURCE_ABRT_SLVRD_INTX										(0x1u<<15)
#define	I2C_TX_ABRT_SOURCE_ABRT_USER_ABRT										(0x1u<<16)
#define	I2C_TX_ABRT_SOURCE_TX_FLUSH_CNT											(0x1FFu<<23)
#define	I2C_TX_ABRT_SOURCE_TX_FLUSH_CNT_0										(0x1u<<23)
#define	I2C_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_INACTIVE							(0x0u<<0)
#define	I2C_TX_ABRT_SOURCE_ABRT_7B_ADDR_NOACK_ACTIVE							(0x1u<<0)
#define	I2C_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_INACTIVE							(0x0u<<1)
#define	I2C_TX_ABRT_SOURCE_ABRT_10ADDR1_NOACK_ACTIVE							(0x1u<<1)
#define	I2C_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_INACTIVE							(0x0u<<2)
#define	I2C_TX_ABRT_SOURCE_ABRT_10ADDR2_NOACK_ACTIVE							(0x1u<<2)
#define	I2C_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_ABRT_TXDATA_NOACK_VOID				(0x0u<<3)
#define	I2C_TX_ABRT_SOURCE_ABRT_TXDATA_NOACK_ABRT_TXDATA_NOACK_GENERATED		(0x1u<<3)
#define	I2C_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_ABRT_GCALL_NOACK_VOID				(0x0u<<4)
#define	I2C_TX_ABRT_SOURCE_ABRT_GCALL_NOACK_ABRT_GCALL_NOACK_GENERATED			(0x1u<<4)
#define	I2C_TX_ABRT_SOURCE_ABRT_GCALL_READ_ABRT_GCALL_READ_VOID					(0x0u<<5)
#define	I2C_TX_ABRT_SOURCE_ABRT_GCALL_READ_ABRT_GCALL_READ_GENERATED			(0x1u<<5)
#define	I2C_TX_ABRT_SOURCE_ABRT_HS_ACKDET_ABRT_HS_ACK_VOID						(0x0u<<6)
#define	I2C_TX_ABRT_SOURCE_ABRT_HS_ACKDET_ABRT_HS_ACK_GENERATED					(0x1u<<6)
#define	I2C_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_ABRT_SBYTE_ACKDET_VOID				(0x0u<<7)
#define	I2C_TX_ABRT_SOURCE_ABRT_SBYTE_ACKDET_ABRT_SBYTE_ACKDET_GENERATED		(0x1u<<7)
#define	I2C_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_ABRT_HS_NORSTRT_VOID					(0x0u<<8)
#define	I2C_TX_ABRT_SOURCE_ABRT_HS_NORSTRT_ABRT_HS_NORSTRT_GENERATED			(0x1u<<8)
#define	I2C_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_ABRT_SBYTE_NORSTRT_VOID			(0x0u<<9)
#define	I2C_TX_ABRT_SOURCE_ABRT_SBYTE_NORSTRT_ABRT_SBYTE_NORSTRT_GENERATED		(0x1u<<9)
#define	I2C_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_ABRT_10B_RD_VOID					(0x0u<<10)
#define	I2C_TX_ABRT_SOURCE_ABRT_10B_RD_NORSTRT_ABRT_10B_RD_GENERATED			(0x1u<<10)
#define	I2C_TX_ABRT_SOURCE_ABRT_MASTER_DIS_ABRT_MASTER_DIS_VOID					(0x0u<<11)
#define	I2C_TX_ABRT_SOURCE_ABRT_MASTER_DIS_ABRT_MASTER_DIS_GENERATED			(0x1u<<11)
#define	I2C_TX_ABRT_SOURCE_ARB_LOST_ABRT_LOST_VOID								(0x0u<<12)
#define	I2C_TX_ABRT_SOURCE_ARB_LOST_ABRT_LOST_GENERATED							(0x1u<<12)
#define	I2C_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_ABRT_SLVFLUSH_TXFIFO_VOID		(0x0u<<13)
#define	I2C_TX_ABRT_SOURCE_ABRT_SLVFLUSH_TXFIFO_ABRT_SLVFLUSH_TXFIFO_GENERATED	(0x1u<<13)
#define	I2C_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_ABRT_SLV_ARBLOST_VOID				(0x0u<<14)
#define	I2C_TX_ABRT_SOURCE_ABRT_SLV_ARBLOST_ABRT_SLV_ARBLOST_GENERATED			(0x1u<<14)
#define	I2C_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_ABRT_SLVRD_INTX_VOID					(0x0u<<15)
#define	I2C_TX_ABRT_SOURCE_ABRT_SLVRD_INTX_ABRT_SLVRD_INTX_GENERATED			(0x1u<<15)
#define	I2C_TX_ABRT_SOURCE_ABRT_USER_ABRT_ABRT_USER_ABRT_VOID					(0x0u<<16)
#define	I2C_TX_ABRT_SOURCE_ABRT_USER_ABRT_ABRT_USER_ABRT_GENERATED				(0x1u<<16)

// SLV_DATA_NACK_ONLY Configuration

#define	I2C_SLV_DATA_NACK_ONLY_NACK												(0x1u<<0)
#define	I2C_SLV_DATA_NACK_ONLY_NACK_DISABLED									(0x0u<<0)
#define	I2C_SLV_DATA_NACK_ONLY_NACK_ENABLED										(0x1u<<0)

// DMA_CR Configuration

#define	I2C_DMA_CR_RDMAE														(0x1u<<0)
#define	I2C_DMA_CR_TDMAE														(0x1u<<1)
#define	I2C_DMA_CR_RDMAE_DISABLED												(0x0u<<0)
#define	I2C_DMA_CR_RDMAE_ENABLED												(0x1u<<0)
#define	I2C_DMA_CR_TDMAE_DISABLED												(0x0u<<1)
#define	I2C_DMA_CR_TDMAE_ENABLED												(0x1u<<1)

// DMA_TDLR Configuration

#define	I2C_DMA_TDLR_DMATDL														(0xFu<<0)
#define	I2C_DMA_TDLR_DMATDL_0													(0x1u<<0)

// DMA_RDLR Configuration

#define	I2C_DMA_RDLR_DMARDL														(0xFu<<0)
#define	I2C_DMA_RDLR_DMARDL_0													(0x1u<<0)

// SDA_SETUP Configuration

#define	I2C_SDA_SETUP_SDA_SETUP													(0xFFu<<0)
#define	I2C_SDA_SETUP_SDA_SETUP_0												(0x1u<<0)

// ACK_GENERAL_CALL Configuration

#define	I2C_ACK_GENERAL_CALL_ACK_GEN_CALL										(0x1u<<0)
#define	I2C_ACK_GENERAL_CALL_ACK_GEN_CALL_DISABLED								(0x0u<<0)
#define	I2C_ACK_GENERAL_CALL_ACK_GEN_CALL_ENABLED								(0x1u<<0)

// ENABLE_STATUS Configuration

#define	I2C_ENABLE_STATUS_IC_EN													(0x1u<<0)
#define	I2C_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY								(0x1u<<1)
#define	I2C_ENABLE_STATUS_SLV_RX_DATA_LOST										(0x1u<<2)
#define	I2C_ENABLE_STATUS_IC_EN_DISABLED										(0x0u<<0)
#define	I2C_ENABLE_STATUS_IC_EN_ENABLED											(0x1u<<0)
#define	I2C_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_INACTIVE						(0x0u<<1)
#define	I2C_ENABLE_STATUS_SLV_DISABLED_WHILE_BUSY_ACTIVE						(0x1u<<1)
#define	I2C_ENABLE_STATUS_SLV_RX_DATA_LOST_INACTIVE								(0x0u<<2)
#define	I2C_ENABLE_STATUS_SLV_RX_DATA_LOST_ACTIVE								(0x1u<<2)

// FS_SPKLEN Configuration

#define	I2C_FS_SPKLEN_IC_FS_SPKLEN												(0xFFu<<0)
#define	I2C_FS_SPKLEN_IC_FS_SPKLEN_0											(0x1u<<0)

// CLR_RESTART_DET Configuration

#define	I2C_CLR_RESTART_DET_CLR_RESTART_DET										(0x1u<<0)

// COMP_PARAM_1 Configuration

#define	I2C_COMP_PARAM_1_APB_DATA_WIDTH											(0x3u<<0)
#define	I2C_COMP_PARAM_1_APB_DATA_WIDTH_0										(0x1u<<0)
#define	I2C_COMP_PARAM_1_MAX_SPEED_MODE											(0x3u<<2)
#define	I2C_COMP_PARAM_1_MAX_SPEED_MODE_0										(0x1u<<2)
#define	I2C_COMP_PARAM_1_HC_COUNT_VALUES										(0x1u<<4)
#define	I2C_COMP_PARAM_1_INTR_IO												(0x1u<<5)
#define	I2C_COMP_PARAM_1_HAS_DMA												(0x1u<<6)
#define	I2C_COMP_PARAM_1_ADD_ENCODED_PARAMS										(0x1u<<7)
#define	I2C_COMP_PARAM_1_RX_BUFFER_DEPTH										(0xFFu<<8)
#define	I2C_COMP_PARAM_1_RX_BUFFER_DEPTH_0										(0x1u<<8)
#define	I2C_COMP_PARAM_1_TX_BUFFER_DEPTH										(0xFFu<<16)
#define	I2C_COMP_PARAM_1_TX_BUFFER_DEPTH_0										(0x1u<<16)

// COMP_VERSION Configuration

#define	I2C_COMP_VERSION_IC_COMP_VERSION										(0xFFFFFFFFu<<0)
#define	I2C_COMP_VERSION_IC_COMP_VERSION_0										(0x1u<<0)

// COMP_TYPE Configuration

#define	I2C_COMP_TYPE_IC_COMP_TYPE												(0xFFFFFFFFu<<0)
#define	I2C_COMP_TYPE_IC_COMP_TYPE_0											(0x1u<<0)
