/*
; K210_dmac.
; ==========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		K210_dmac equates.
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

#define	DMAC_CHANNEL_COUNT	DMAC_CHANNEL_MAX						//

// DMA device number
// -----------------

typedef	enum	_dmac_channel_number {
	DMAC_CHANNEL0 = 0u,												//
	DMAC_CHANNEL1 = 1u,												//
	DMAC_CHANNEL2 = 2u,												//
	DMAC_CHANNEL3 = 3u,												//
	DMAC_CHANNEL4 = 4u,												//
	DMAC_CHANNEL5 = 5u,												//
	DMAC_CHANNEL_MAX												//
} dmac_channel_number_t;

typedef	enum	_dmac_master_number {
	DMAC_MASTER1 = 0x0u,											//
	DMAC_MASTER2 = 0x1u												//
} dmac_master_number_t;

typedef	enum	_dmac_address_increment {
	DMAC_ADDR_INCREMENT = 0x0u,										//
	DMAC_ADDR_NOCHANGE  = 0x1u										//
} dmac_address_increment_t;

typedef	enum	_dmac_transfer_width {
	DMAC_TRANS_WIDTH_8   = 0x0u,									//
	DMAC_TRANS_WIDTH_16  = 0x1u,									//
	DMAC_TRANS_WIDTH_32  = 0x2u,									//
	DMAC_TRANS_WIDTH_64  = 0x3u,									//
	DMAC_TRANS_WIDTH_128 = 0x4u,									//
	DMAC_TRANS_WIDTH_256 = 0x5u										//
} dmac_transfer_width_t;

typedef	enum	_dmac_transfer_flow {
	DMAC_MEM2MEM_DMA    = 0x0u,										//
	DMAC_MEM2PRF_DMA    = 0x1u,										//
	DMAC_PRF2MEM_DMA    = 0x2u,										//
	DMAC_PRF2PRF_DMA    = 0x3u,										//
	DMAC_PRF2MEM_PRF    = 0x4u,										//
	DMAC_PRF2PRF_SRCPRF = 0x5u,										//
	DMAC_MEM2PRF_PRF    = 0x6u,										//
	DMAC_PRF2PRF_DSTPRF = 0x7u										//
} dmac_transfer_flow_t;

typedef	enum	_dmac_sw_hw_hs_select {
	DMAC_HS_HARDWARE = 0x0u,										//
	DMAC_HS_SOFTWARE = 0x1u											//
} dmac_sw_hw_hs_select_t;

typedef	enum	_dmac_burst_trans_length {
	DMAC_MSIZE_1   = 0x0u,											//
	DMAC_MSIZE_4   = 0x1u,											//
	DMAC_MSIZE_8   = 0x2u,											//
	DMAC_MSIZE_16  = 0x3u,											//
	DMAC_MSIZE_32  = 0x4u,											//
	DMAC_MSIZE_64  = 0x5u,											//
	DMAC_MSIZE_128 = 0x6u,											//
	DMAC_MSIZE_256 = 0x7u											//
} dmac_burst_trans_length_t;

// Structure for accessing DMAC channel registers
// ----------------------------------------------

typedef	struct	[[gnu::packed, gnu::aligned(8)]] _dmac_channel {
	uint64_t	sar;												// (0x100) SAR Address Register
	uint64_t	dar;												// (0x108) DAR Address Register
	uint64_t	block_ts;											// (0x110) Block Transfer Size Register
	uint64_t	ctl;												// (0x118) Control Register
	uint64_t	cfg;												// (0x120) Configure Register
	uint64_t	llp;												// (0x128) Linked List Pointer register
	uint64_t	status;												// (0x130) Channelx Status Register
	uint64_t	swhssrc;											// (0x138) Channelx Software handshake Source Register
	uint64_t	swhsdst;											// (0x140) Channelx Software handshake Destination Register
	uint64_t	blk_tfr;											// (0x148) Channelx Block Transfer Resume Request Register
	uint64_t	axi_id;												// (0x150) Channelx AXI ID Register
	uint64_t	axi_qos;											// (0x158) Channelx AXI QOS Register
	uint64_t	reserved1[4];										// Reserved address
	uint64_t	intstatus_en;										// (0x180) Interrupt Status Enable Register
	uint64_t	intstatus;											// (0x188) Channelx Interrupt Status Register
	uint64_t	intsignal_en;										// (0x190) Interrupt  Siganl Enable Register
	uint64_t	intclear;											// (0x198) Interrupt Clear Register
	uint64_t	reserved2[12];										// Reserved address
} dmac_channel_t;

// Structure for accessing DMAC registers
// --------------------------------------

typedef	struct	[[gnu::packed, gnu::aligned(8)]] _dmac {
	uint64_t	id;													// (0x00) DMAC ID Rgister
	uint64_t	compver;											// (0x08) DMAC COMPVER Register
	uint64_t	cfg;												// (0x10) DMAC Configure Register
	uint64_t	chen;												// (0x18) Channel Enable Register
	uint64_t	reserved1[2];										// Reserved address
	uint64_t	intstatus;											// (0x30) DMAC Interrupt Status Register
	uint64_t	com_intclear;										// (0x38) DMAC Common register Interrupt Status Register
	uint64_t	com_intstatus_en;									// (0x40) DMAC Common Interrupt Enable Register
	uint64_t	com_intsignal_en;									// (0x48) DMAC Common Interrupt Signal Enable Register
	uint64_t	com_intstatus;										// (0x50) DMAC Common Interrupt Status
	uint64_t	reset;												// (0x58) DMAC Reset register
	uint64_t	reserved2[20];										// Reserved address
	dmac_channel_t channel[DMAC_CHANNEL_COUNT];						//
} dmac_t;

// Structure for accessing DMAC chen registers
// -------------------------------------------

typedef	struct	[[gnu::packed, gnu::aligned(8)]] _damc_chen {
	uint64_t	ch1_en       : 1;									//
	uint64_t	ch2_en       : 1;									//
	uint64_t	ch3_en       : 1;									//
	uint64_t	ch4_en       : 1;									//
	uint64_t	ch5_en       : 1;									//
	uint64_t	ch6_en       : 1;									//
	uint64_t	rsvd1        : 2;									//
	uint64_t	ch1_en_we    : 1;									//
	uint64_t	ch2_en_we    : 1;									//
	uint64_t	ch3_en_we    : 1;									//
	uint64_t	ch4_en_we    : 1;									//
	uint64_t	ch5_en_we    : 1;									//
	uint64_t	ch6_en_we    : 1;									//
	uint64_t	rsvd2        : 2;									//
	uint64_t	ch1_susp     : 1;									//
	uint64_t	ch2_susp     : 1;									//
	uint64_t	ch3_susp     : 1;									//
	uint64_t	ch4_susp     : 1;									//
	uint64_t	ch5_susp     : 1;									//
	uint64_t	ch6_susp     : 1;									//
	uint64_t	rsvd3        : 2;									//
	uint64_t	ch1_susp_we  : 1;									//
	uint64_t	ch2_susp_we  : 1;									//
	uint64_t	ch3_susp_we  : 1;									//
	uint64_t	ch4_susp_we  : 1;									//
	uint64_t	ch5_susp_we  : 1;									//
	uint64_t	ch6_susp_we  : 1;									//
	uint64_t	rsvd4        : 2;									//
	uint64_t	ch1_abort    : 1;									//
	uint64_t	ch2_abort    : 1;									//
	uint64_t	ch3_abort    : 1;									//
	uint64_t	ch4_abort    : 1;									//
	uint64_t	ch5_abort    : 1;									//
	uint64_t	ch6_abort    : 1;									//
	uint64_t	rsvd5        : 2;									//
	uint64_t	ch1_abort_we : 1;									//
	uint64_t	ch2_abort_we : 1;									//
	uint64_t	ch3_abort_we : 1;									//
	uint64_t	ch4_abort_we : 1;									//
	uint64_t	ch5_abort_we : 1;									//
	uint64_t	ch6_abort_we : 1;									//
	uint64_t	rsvd6        : 2;									//
	uint64_t	rsvd7        : 16;									//
} damc_chen_t;

typedef	union	_dmac_chen_u {
	damc_chen_t		dmac_chen;										//
	uint64_t		data;											//
} dmac_chen_u_t;

// Structure for accessing DMAC cfg registers
// ------------------------------------------

typedef	struct	[[gnu::packed, gnu::aligned(8)]] _dmac_cfg {
	uint64_t	dmac_en : 1;										//
	uint64_t	int_en  : 1;										//
	uint64_t	rsvd    : 62;										//
} dmac_cfg_t;

typedef	union	_dmac_cfg_u {
	dmac_cfg_t	cfg;												//
	uint64_t	data;												//
} dmac_cfg_u_t;

// Structure for accessing DMAC ctl registers
// ------------------------------------------

typedef	struct	[[gnu::packed, gnu::aligned(8)]] _dmac_ch_ctl {
	uint64_t	sms                    : 1;							//
	uint64_t	rsvd1                  : 1;							//
	uint64_t	dms                    : 1;							//
	uint64_t	rsvd2                  : 1;							//
	uint64_t	sinc                   : 1;							//
	uint64_t	rsvd3                  : 1;							//
	uint64_t	dinc                   : 1;							//
	uint64_t	rsvd4                  : 1;							//
	uint64_t	src_tr_width           : 3;							//
	uint64_t	dst_tr_width           : 3;							//
	uint64_t	src_msize              : 4;							//
	uint64_t	dst_msize              : 4;							//
	uint64_t	rsvd5                  : 4;							//
	uint64_t	rsvd6                  : 4;							//
	uint64_t	nonposted_lastwrite_en : 1;							//
	uint64_t	rsvd7                  : 1;							//
	uint64_t	rsvd8                  : 3;							//
	uint64_t	rsvd9                  : 3;							//
	uint64_t	arlen_en               : 1;							//
	uint64_t	arlen                  : 8;							//
	uint64_t	awlen_en               : 1;							//
	uint64_t	awlen                  : 8;							//
	uint64_t	src_stat_en            : 1;							//
	uint64_t	dst_stat_en            : 1;							//
	uint64_t	ioc_blktfr             : 1;							//
	uint64_t	rsvd10                 : 3;							//
	uint64_t	shadowreg_or_lli_last  : 1;							//
	uint64_t	shadowreg_or_lli_valid : 1;							//
} dmac_ch_ctl_t;

typedef	union	_dmac_ch_ctl_u {
	dmac_ch_ctl_t	ch_ctl;											//
	uint64_t		data;											//
} dmac_ch_ctl_u_t;

// Structure for accessing DMAC cfg registers
// ------------------------------------------

typedef	struct	[[gnu::packed, gnu::aligned(8)]] _dmac_ch_cfg {
	uint64_t	src_multblk_type : 2;								//
	uint64_t	dst_multblk_type : 2;								//
	uint64_t	rsvd1            : 28;								//
	uint64_t	tt_fc            : 3;								//
	uint64_t	hs_sel_src       : 1;								//
	uint64_t	hs_sel_dst       : 1;								//
	uint64_t	src_hwhs_pol     : 1;								//
	uint64_t	dst_hwhs_pol     : 1;								//
	uint64_t	src_per          : 4;								//
	uint64_t	rsvd3            : 1;								//
	uint64_t	dst_per          : 4;								//
	uint64_t	rsvd5            : 1;								//
	uint64_t	ch_prior         : 3;								//
	uint64_t	lock_ch          : 1;								//
	uint64_t	lock_ch_l        : 2;								//
	uint64_t	src_osr_lmt      : 4;								//
	uint64_t	dst_osr_lmt      : 4;								//
} dmac_ch_cfg_t;

typedef	union	_dmac_ch_cfg_u {
	dmac_ch_cfg_t	ch_cfg;											//
	uint64_t		data;											//
} dmac_ch_cfg_u_t;

#define	dmac	((volatile	dmac_t *)0x50000000u)
