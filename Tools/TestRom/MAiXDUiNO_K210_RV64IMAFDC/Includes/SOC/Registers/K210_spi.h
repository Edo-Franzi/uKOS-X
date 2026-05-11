/*
; K210_spi.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		K210_spi equates.
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

// SPI device number
// -----------------

typedef	enum	_spi_device_num {
	SPI_DEVICE_0,									//
	SPI_DEVICE_1,									//
	SPI_DEVICE_2,									//
	SPI_DEVICE_3,									//
	SPI_DEVICE_MAX									//
} spi_device_num_t;

// SPI work mode
// -------------

typedef	enum	_spi_work_mode {
	SPI_WORK_MODE_0,								//
	SPI_WORK_MODE_1,								//
	SPI_WORK_MODE_2,								//
	SPI_WORK_MODE_3									//
} spi_work_mode_t;

// SPI frame format
// ----------------

typedef	enum	_spi_frame_format {
	SPI_FF_STANDARD,								//
	SPI_FF_DUAL,									//
	SPI_FF_QUAD,									//
	SPI_FF_OCTAL									//
} spi_frame_format_t;

// SPI address transfer mode
// -------------------------

typedef	enum	_spi_instruction_address_trans_mode {
	SPI_AITM_STANDARD,								//
	SPI_AITM_ADDR_STANDARD,							//
	SPI_AITM_AS_FRAME_FORMAT						//
} spi_instruction_address_trans_mode_t;

// SPI transfer mode
// -----------------

typedef	enum	_spi_transfer_mode {
	SPI_TMOD_TRANS_RECV,							//
	SPI_TMOD_TRANS,									//
	SPI_TMOD_RECV,									//
	SPI_TMOD_EEROM									//
} spi_transfer_mode_t;

// SPI transfer width
// ------------------

typedef	enum	_spi_transfer_width {
	SPI_TRANS_CHAR  = 0x1u,							//
	SPI_TRANS_SHORT = 0x2u,							//
	SPI_TRANS_INT   = 0x4u							//
} spi_transfer_width_t;

// SPI chip selects
// ----------------

typedef	enum	_spi_chip_select {
	SPI_CHIP_SELECT_0,								//
	SPI_CHIP_SELECT_1,								//
	SPI_CHIP_SELECT_2,								//
	SPI_CHIP_SELECT_3,								//
	SPI_CHIP_SELECT_MAX								//
} spi_chip_select_t;

// SPI SSIENR Register
// -------------------

#define	SPI_SSIENR_SSI_EN			0u				//

// SPI SR Register
// ---------------

#define	SPI_SR_BUSY					0u				//
#define	SPI_SR_TFE					2u				//

// The SPI address map
// -------------------

typedef	struct	[[gnu::packed, gnu::aligned(4)]] _spi {
	volatile	uint32_t	ctrlr0;					// SPI Control Register 0                                    (0x00)
	volatile	uint32_t	ctrlr1;					// SPI Control Register 1                                    (0x04)
	volatile	uint32_t	ssienr;					// SPI Enable Register                                       (0x08)
	volatile	uint32_t	mwcr;					// SPI Microwire Control Register                            (0x0c)
	volatile	uint32_t	ser;					// SPI Slave Enable Register                                 (0x10)
	volatile	uint32_t	baudr;					// SPI Baud Rate Select                                      (0x14)
	volatile	uint32_t	txftlr;					// SPI Transmit FIFO Threshold Level                         (0x18)
	volatile	uint32_t	rxftlr;					// SPI Receive FIFO Threshold Level                          (0x1c)
	volatile	uint32_t	txflr;					// SPI Transmit FIFO Level Register                          (0x20)
	volatile	uint32_t	rxflr;					// SPI Receive FIFO Level Register                           (0x24)
	volatile	uint32_t	sr;						// SPI Status Register                                       (0x28)
	volatile	uint32_t	imr;					// SPI Interrupt Mask Register                               (0x2c)
	volatile	uint32_t	isr;					// SPI Interrupt Status Register                             (0x30)
	volatile	uint32_t	risr;					// SPI Raw Interrupt Status Register                         (0x34)
	volatile	uint32_t	txoicr;					// SPI Transmit FIFO Overflow Interrupt Clear Register       (0x38)
	volatile	uint32_t	rxoicr;					// SPI Receive FIFO Overflow Interrupt Clear Register        (0x3c)
	volatile	uint32_t	rxuicr;					// SPI Receive FIFO Underflow Interrupt Clear Register       (0x40)
	volatile	uint32_t	msticr;					// SPI Multi-Master Interrupt Clear Register                 (0x44)
	volatile	uint32_t	icr;					// SPI Interrupt Clear Register                              (0x48)
	volatile	uint32_t	dmacr;					// SPI DMA Control Register                                  (0x4c)
	volatile	uint32_t	dmatdlr;				// SPI DMA Transmit Data Level                               (0x50)
	volatile	uint32_t	dmardlr;				// SPI DMA Receive Data Level                                (0x54)
	volatile	uint32_t	idr;					// SPI Identification Register                               (0x58)
	volatile	uint32_t	ssic_version_id;		// SPI DWC_ssi component version                             (0x5c)
	volatile	uint32_t	dr[36];					// SPI Data Register 0-36                                    (0x60)
	volatile	uint32_t	rx_sample_delay;		// SPI RX Sample Delay Register                              (0xf0)
	volatile	uint32_t	spi_ctrlr0;				// SPI SPI Control Register                                  (0xf4)
	volatile	uint32_t	resv;					// reserved                                                  (0xf8)
	volatile	uint32_t	xip_mode_bits;			// SPI XIP Mode bits                                         (0xfc)
	volatile	uint32_t	xip_incr_inst;			// SPI XIP INCR transfer opcode                              (0x100)
	volatile	uint32_t	xip_wrap_inst;			// SPI XIP WRAP transfer opcode                              (0x104)
	volatile	uint32_t	xip_ctrl;				// SPI XIP Control Register                                  (0x108)
	volatile	uint32_t	xip_ser;				// SPI XIP Slave Enable Register                             (0x10c)
	volatile	uint32_t	xrxoicr;				// SPI XIP Receive FIFO Overflow Interrupt Clear Register    (0x110)
	volatile	uint32_t	xip_cnt_time_out;		// SPI XIP time out register for continuous transfers        (0x114)
	volatile	uint32_t	endian;					// SPI endianess       										 (0x118)
} spi_t;

#define	spi0	((volatile	spi_t *)0x52000000u)
#define	spi1	((volatile	spi_t *)0x53000000u)
#define	spi3	((volatile	spi_t *)0x54000000u)
