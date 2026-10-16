/*
; nrf5340_application_qspi.
; =========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_qspi equates.
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

// QSPI address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	TASKS_ACTIVATE;
	volatile	uint32_t	TASKS_READSTART;
	volatile	uint32_t	TASKS_WRITESTART;
	volatile	uint32_t	TASKS_ERASESTART;
	volatile	uint32_t	TASKS_DEACTIVATE;
	volatile	uint32_t	RESERVED0[27];
	volatile	uint32_t	SUBSCRIBE_ACTIVATE;
	volatile	uint32_t	SUBSCRIBE_READSTART;
	volatile	uint32_t	SUBSCRIBE_WRITESTART;
	volatile	uint32_t	SUBSCRIBE_ERASESTART;
	volatile	uint32_t	SUBSCRIBE_DEACTIVATE;
	volatile	uint32_t	RESERVED1[27];
	volatile	uint32_t	EVENTS_READY;
	volatile	uint32_t	RESERVED2[31];
	volatile	uint32_t	PUBLISH_READY;
	volatile	uint32_t	RESERVED3[95];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED4[125];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	READ_SRC;
	volatile	uint32_t	READ_DST;
	volatile	uint32_t	READ_CNT;
	volatile	uint32_t	WRITE_DST;
	volatile	uint32_t	WRITE_SRC;
	volatile	uint32_t	WRITE_CNT;
	volatile	uint32_t	ERASE_PTR;
	volatile	uint32_t	ERASE_LEN;
	volatile	uint32_t	PSEL_SCK;
	volatile	uint32_t	PSEL_CSN;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	PSEL_IO0;
	volatile	uint32_t	PSEL_IO1;
	volatile	uint32_t	PSEL_IO2;
	volatile	uint32_t	PSEL_IO3;
	volatile	uint32_t	XIPOFFSET;
	volatile	uint32_t	IFCONFIG0;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	XIPEN;
	volatile	uint32_t	RESERVED7[4];
	volatile	uint32_t	XIP_ENC_KEY0;
	volatile	uint32_t	XIP_ENC_KEY1;
	volatile	uint32_t	XIP_ENC_KEY2;
	volatile	uint32_t	XIP_ENC_KEY3;
	volatile	uint32_t	XIP_ENC_NONCE0;
	volatile	uint32_t	XIP_ENC_NONCE1;
	volatile	uint32_t	XIP_ENC_NONCE2;
	volatile	uint32_t	XIP_ENC_ENABLE;
	volatile	uint32_t	DMA_ENC_KEY0;
	volatile	uint32_t	DMA_ENC_KEY1;
	volatile	uint32_t	DMA_ENC_KEY2;
	volatile	uint32_t	DMA_ENC_KEY3;
	volatile	uint32_t	DMA_ENC_NONCE0;
	volatile	uint32_t	DMA_ENC_NONCE1;
	volatile	uint32_t	DMA_ENC_NONCE2;
	volatile	uint32_t	DMA_ENC_ENABLE;
	volatile	uint32_t	RESERVED8[24];
	volatile	uint32_t	IFCONFIG1;
	volatile	uint32_t	STATUS;
	volatile	uint32_t	RESERVED9[3];
	volatile	uint32_t	DPMDUR;
	volatile	uint32_t	RESERVED10[3];
	volatile	uint32_t	ADDRCONF;
	volatile	uint32_t	RESERVED11[3];
	volatile	uint32_t	CINSTRCONF;
	volatile	uint32_t	CINSTRDAT0;
	volatile	uint32_t	CINSTRDAT1;
	volatile	uint32_t	IFTIMING;
} QSPI_TypeDef;

#if (defined(__cplusplus))
#define	QSPI_NS	reinterpret_cast<QSPI_TypeDef *>(0x4002B000u)
#define	QSPI_S	reinterpret_cast<QSPI_TypeDef *>(0x5002B000u)

#else
#define	QSPI_NS	((QSPI_TypeDef *)0x4002B000u)
#define	QSPI_S	((QSPI_TypeDef *)0x5002B000u)
#endif

// TASKS_ACTIVATE Configuration

#define	QSPI_TASKS_ACTIVATE_TASKS_ACTIVATE						(0x1u<<0)
#define	QSPI_TASKS_ACTIVATE_TASKS_ACTIVATE_TRIGGER				(0x1u<<0)

// TASKS_READSTART Configuration

#define	QSPI_TASKS_READSTART_TASKS_READSTART					(0x1u<<0)
#define	QSPI_TASKS_READSTART_TASKS_READSTART_TRIGGER			(0x1u<<0)

// TASKS_WRITESTART Configuration

#define	QSPI_TASKS_WRITESTART_TASKS_WRITESTART					(0x1u<<0)
#define	QSPI_TASKS_WRITESTART_TASKS_WRITESTART_TRIGGER			(0x1u<<0)

// TASKS_ERASESTART Configuration

#define	QSPI_TASKS_ERASESTART_TASKS_ERASESTART					(0x1u<<0)
#define	QSPI_TASKS_ERASESTART_TASKS_ERASESTART_TRIGGER			(0x1u<<0)

// TASKS_DEACTIVATE Configuration

#define	QSPI_TASKS_DEACTIVATE_TASKS_DEACTIVATE					(0x1u<<0)
#define	QSPI_TASKS_DEACTIVATE_TASKS_DEACTIVATE_TRIGGER			(0x1u<<0)

// SUBSCRIBE_ACTIVATE Configuration

#define	QSPI_SUBSCRIBE_ACTIVATE_EN								(0x1u<<31)
#define	QSPI_SUBSCRIBE_ACTIVATE_CHIDX							(0xFFu<<0)
#define	QSPI_SUBSCRIBE_ACTIVATE_CHIDX_0							(0x1u<<0)
#define	QSPI_SUBSCRIBE_ACTIVATE_EN_DISABLED						(0x0u<<31)
#define	QSPI_SUBSCRIBE_ACTIVATE_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_READSTART Configuration

#define	QSPI_SUBSCRIBE_READSTART_EN								(0x1u<<31)
#define	QSPI_SUBSCRIBE_READSTART_CHIDX							(0xFFu<<0)
#define	QSPI_SUBSCRIBE_READSTART_CHIDX_0						(0x1u<<0)
#define	QSPI_SUBSCRIBE_READSTART_EN_DISABLED					(0x0u<<31)
#define	QSPI_SUBSCRIBE_READSTART_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_WRITESTART Configuration

#define	QSPI_SUBSCRIBE_WRITESTART_EN							(0x1u<<31)
#define	QSPI_SUBSCRIBE_WRITESTART_CHIDX							(0xFFu<<0)
#define	QSPI_SUBSCRIBE_WRITESTART_CHIDX_0						(0x1u<<0)
#define	QSPI_SUBSCRIBE_WRITESTART_EN_DISABLED					(0x0u<<31)
#define	QSPI_SUBSCRIBE_WRITESTART_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_ERASESTART Configuration

#define	QSPI_SUBSCRIBE_ERASESTART_EN							(0x1u<<31)
#define	QSPI_SUBSCRIBE_ERASESTART_CHIDX							(0xFFu<<0)
#define	QSPI_SUBSCRIBE_ERASESTART_CHIDX_0						(0x1u<<0)
#define	QSPI_SUBSCRIBE_ERASESTART_EN_DISABLED					(0x0u<<31)
#define	QSPI_SUBSCRIBE_ERASESTART_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_DEACTIVATE Configuration

#define	QSPI_SUBSCRIBE_DEACTIVATE_EN							(0x1u<<31)
#define	QSPI_SUBSCRIBE_DEACTIVATE_CHIDX							(0xFFu<<0)
#define	QSPI_SUBSCRIBE_DEACTIVATE_CHIDX_0						(0x1u<<0)
#define	QSPI_SUBSCRIBE_DEACTIVATE_EN_DISABLED					(0x0u<<31)
#define	QSPI_SUBSCRIBE_DEACTIVATE_EN_ENABLED					(0x1u<<31)

// EVENTS_READY Configuration

#define	QSPI_EVENTS_READY_EVENTS_READY							(0x1u<<0)
#define	QSPI_EVENTS_READY_EVENTS_READY_NOTGENERATED				(0x0u<<0)
#define	QSPI_EVENTS_READY_EVENTS_READY_GENERATED				(0x1u<<0)

// PUBLISH_READY Configuration

#define	QSPI_PUBLISH_READY_EN									(0x1u<<31)
#define	QSPI_PUBLISH_READY_CHIDX								(0xFFu<<0)
#define	QSPI_PUBLISH_READY_CHIDX_0								(0x1u<<0)
#define	QSPI_PUBLISH_READY_EN_DISABLED							(0x0u<<31)
#define	QSPI_PUBLISH_READY_EN_ENABLED							(0x1u<<31)

// INTEN Configuration

#define	QSPI_INTEN_READY										(0x1u<<0)
#define	QSPI_INTEN_READY_DISABLED								(0x0u<<0)
#define	QSPI_INTEN_READY_ENABLED								(0x1u<<0)

// INTENSET Configuration

#define	QSPI_INTENSET_READY										(0x1u<<0)
#define	QSPI_INTENSET_READY_DISABLED							(0x0u<<0)
#define	QSPI_INTENSET_READY_ENABLED								(0x1u<<0)
#define	QSPI_INTENSET_READY_SET									(0x1u<<0)

// INTENCLR Configuration

#define	QSPI_INTENCLR_READY										(0x1u<<0)
#define	QSPI_INTENCLR_READY_DISABLED							(0x0u<<0)
#define	QSPI_INTENCLR_READY_ENABLED								(0x1u<<0)
#define	QSPI_INTENCLR_READY_CLEAR								(0x1u<<0)

// ENABLE Configuration

#define	QSPI_ENABLE_ENABLE										(0x1u<<0)
#define	QSPI_ENABLE_ENABLE_DISABLED								(0x0u<<0)
#define	QSPI_ENABLE_ENABLE_ENABLED								(0x1u<<0)

// SRC Configuration

#define	QSPI_READ_SRC_SRC										(0xFFFFFFFFu<<0)
#define	QSPI_READ_SRC_SRC_0										(0x1u<<0)

// DST Configuration

#define	QSPI_READ_DST_DST										(0xFFFFFFFFu<<0)
#define	QSPI_READ_DST_DST_0										(0x1u<<0)

// CNT Configuration

#define	QSPI_READ_CNT_CNT										(0x1FFFFFu<<0)
#define	QSPI_READ_CNT_CNT_0										(0x1u<<0)

// DST Configuration

#define	QSPI_WRITE_DST_DST										(0xFFFFFFFFu<<0)
#define	QSPI_WRITE_DST_DST_0									(0x1u<<0)

// SRC Configuration

#define	QSPI_WRITE_SRC_SRC										(0xFFFFFFFFu<<0)
#define	QSPI_WRITE_SRC_SRC_0									(0x1u<<0)

// CNT Configuration

#define	QSPI_WRITE_CNT_CNT										(0x1FFFFFu<<0)
#define	QSPI_WRITE_CNT_CNT_0									(0x1u<<0)

// PTR Configuration

#define	QSPI_ERASE_PTR_PTR										(0xFFFFFFFFu<<0)
#define	QSPI_ERASE_PTR_PTR_0									(0x1u<<0)

// LEN Configuration

#define	QSPI_ERASE_LEN_LEN										(0x3u<<0)
#define	QSPI_ERASE_LEN_LEN_0									(0x1u<<0)
#define	QSPI_ERASE_LEN_LEN_4KB									(0x0u<<0)
#define	QSPI_ERASE_LEN_LEN_64KB									(0x1u<<0)
#define	QSPI_ERASE_LEN_LEN_ALL									(0x2u<<0)

// SCK Configuration

#define	QSPI_PSEL_SCK_CONNECT									(0x1u<<31)
#define	QSPI_PSEL_SCK_PORT										(0x1u<<5)
#define	QSPI_PSEL_SCK_PIN										(0x1Fu<<0)
#define	QSPI_PSEL_SCK_PIN_0										(0x1u<<0)
#define	QSPI_PSEL_SCK_CONNECT_DISCONNECTED						(0x1u<<31)
#define	QSPI_PSEL_SCK_CONNECT_CONNECTED							(0x0u<<31)

// CSN Configuration

#define	QSPI_PSEL_CSN_CONNECT									(0x1u<<31)
#define	QSPI_PSEL_CSN_PORT										(0x1u<<5)
#define	QSPI_PSEL_CSN_PIN										(0x1Fu<<0)
#define	QSPI_PSEL_CSN_PIN_0										(0x1u<<0)
#define	QSPI_PSEL_CSN_CONNECT_DISCONNECTED						(0x1u<<31)
#define	QSPI_PSEL_CSN_CONNECT_CONNECTED							(0x0u<<31)

// IO0 Configuration

#define	QSPI_PSEL_IO0_CONNECT									(0x1u<<31)
#define	QSPI_PSEL_IO0_PORT										(0x1u<<5)
#define	QSPI_PSEL_IO0_PIN										(0x1Fu<<0)
#define	QSPI_PSEL_IO0_PIN_0										(0x1u<<0)
#define	QSPI_PSEL_IO0_CONNECT_DISCONNECTED						(0x1u<<31)
#define	QSPI_PSEL_IO0_CONNECT_CONNECTED							(0x0u<<31)

// IO1 Configuration

#define	QSPI_PSEL_IO1_CONNECT									(0x1u<<31)
#define	QSPI_PSEL_IO1_PORT										(0x1u<<5)
#define	QSPI_PSEL_IO1_PIN										(0x1Fu<<0)
#define	QSPI_PSEL_IO1_PIN_0										(0x1u<<0)
#define	QSPI_PSEL_IO1_CONNECT_DISCONNECTED						(0x1u<<31)
#define	QSPI_PSEL_IO1_CONNECT_CONNECTED							(0x0u<<31)

// IO2 Configuration

#define	QSPI_PSEL_IO2_CONNECT									(0x1u<<31)
#define	QSPI_PSEL_IO2_PORT										(0x1u<<5)
#define	QSPI_PSEL_IO2_PIN										(0x1Fu<<0)
#define	QSPI_PSEL_IO2_PIN_0										(0x1u<<0)
#define	QSPI_PSEL_IO2_CONNECT_DISCONNECTED						(0x1u<<31)
#define	QSPI_PSEL_IO2_CONNECT_CONNECTED							(0x0u<<31)

// IO3 Configuration

#define	QSPI_PSEL_IO3_CONNECT									(0x1u<<31)
#define	QSPI_PSEL_IO3_PORT										(0x1u<<5)
#define	QSPI_PSEL_IO3_PIN										(0x1Fu<<0)
#define	QSPI_PSEL_IO3_PIN_0										(0x1u<<0)
#define	QSPI_PSEL_IO3_CONNECT_DISCONNECTED						(0x1u<<31)
#define	QSPI_PSEL_IO3_CONNECT_CONNECTED							(0x0u<<31)

// XIPOFFSET Configuration

#define	QSPI_XIPOFFSET_XIPOFFSET								(0xFFFFFFFFu<<0)
#define	QSPI_XIPOFFSET_XIPOFFSET_0								(0x1u<<0)

// IFCONFIG0 Configuration

#define	QSPI_IFCONFIG0_PPSIZE									(0x1u<<12)
#define	QSPI_IFCONFIG0_DPMENABLE								(0x1u<<7)
#define	QSPI_IFCONFIG0_ADDRMODE									(0x1u<<6)
#define	QSPI_IFCONFIG0_WRITEOC									(0x7u<<3)
#define	QSPI_IFCONFIG0_WRITEOC_0								(0x1u<<3)
#define	QSPI_IFCONFIG0_READOC									(0x7u<<0)
#define	QSPI_IFCONFIG0_READOC_0									(0x1u<<0)
#define	QSPI_IFCONFIG0_PPSIZE_256BYTES							(0x0u<<12)
#define	QSPI_IFCONFIG0_PPSIZE_512BYTES							(0x1u<<12)
#define	QSPI_IFCONFIG0_DPMENABLE_DISABLE						(0x0u<<7)
#define	QSPI_IFCONFIG0_DPMENABLE_ENABLE							(0x1u<<7)
#define	QSPI_IFCONFIG0_ADDRMODE_24BIT							(0x0u<<6)
#define	QSPI_IFCONFIG0_ADDRMODE_32BIT							(0x1u<<6)
#define	QSPI_IFCONFIG0_WRITEOC_PP								(0x0u<<3)
#define	QSPI_IFCONFIG0_WRITEOC_PP2O								(0x1u<<3)
#define	QSPI_IFCONFIG0_WRITEOC_PP4O								(0x2u<<3)
#define	QSPI_IFCONFIG0_WRITEOC_PP4IO							(0x3u<<3)
#define	QSPI_IFCONFIG0_READOC_FASTREAD							(0x0u<<0)
#define	QSPI_IFCONFIG0_READOC_READ2O							(0x1u<<0)
#define	QSPI_IFCONFIG0_READOC_READ2IO							(0x2u<<0)
#define	QSPI_IFCONFIG0_READOC_READ4O							(0x3u<<0)
#define	QSPI_IFCONFIG0_READOC_READ4IO							(0x4u<<0)

// XIPEN Configuration

#define	QSPI_XIPEN_XIPEN										(0x1u<<0)
#define	QSPI_XIPEN_XIPEN_DISABLE								(0x0u<<0)
#define	QSPI_XIPEN_XIPEN_ENABLE									(0x1u<<0)

// KEY0 Configuration

#define	QSPI_XIP_ENC_KEY0_KEY0									(0xFFFFFFFFu<<0)
#define	QSPI_XIP_ENC_KEY0_KEY0_0								(0x1u<<0)

// KEY1 Configuration

#define	QSPI_XIP_ENC_KEY1_KEY1									(0xFFFFFFFFu<<0)
#define	QSPI_XIP_ENC_KEY1_KEY1_0								(0x1u<<0)

// KEY2 Configuration

#define	QSPI_XIP_ENC_KEY2_KEY2									(0xFFFFFFFFu<<0)
#define	QSPI_XIP_ENC_KEY2_KEY2_0								(0x1u<<0)

// KEY3 Configuration

#define	QSPI_XIP_ENC_KEY3_KEY3									(0xFFFFFFFFu<<0)
#define	QSPI_XIP_ENC_KEY3_KEY3_0								(0x1u<<0)

// NONCE0 Configuration

#define	QSPI_XIP_ENC_NONCE0_NONCE0								(0xFFFFFFFFu<<0)
#define	QSPI_XIP_ENC_NONCE0_NONCE0_0							(0x1u<<0)

// NONCE1 Configuration

#define	QSPI_XIP_ENC_NONCE1_NONCE1								(0xFFFFFFFFu<<0)
#define	QSPI_XIP_ENC_NONCE1_NONCE1_0							(0x1u<<0)

// NONCE2 Configuration

#define	QSPI_XIP_ENC_NONCE2_NONCE2								(0xFFFFFFFFu<<0)
#define	QSPI_XIP_ENC_NONCE2_NONCE2_0							(0x1u<<0)

// ENABLE Configuration

#define	QSPI_XIP_ENC_ENABLE_ENABLE								(0x1u<<0)
#define	QSPI_XIP_ENC_ENABLE_ENABLE_DISABLED						(0x0u<<0)
#define	QSPI_XIP_ENC_ENABLE_ENABLE_ENABLED						(0x1u<<0)

// KEY0 Configuration

#define	QSPI_DMA_ENC_KEY0_KEY0									(0xFFFFFFFFu<<0)
#define	QSPI_DMA_ENC_KEY0_KEY0_0								(0x1u<<0)

// KEY1 Configuration

#define	QSPI_DMA_ENC_KEY1_KEY1									(0xFFFFFFFFu<<0)
#define	QSPI_DMA_ENC_KEY1_KEY1_0								(0x1u<<0)

// KEY2 Configuration

#define	QSPI_DMA_ENC_KEY2_KEY2									(0xFFFFFFFFu<<0)
#define	QSPI_DMA_ENC_KEY2_KEY2_0								(0x1u<<0)

// KEY3 Configuration

#define	QSPI_DMA_ENC_KEY3_KEY3									(0xFFFFFFFFu<<0)
#define	QSPI_DMA_ENC_KEY3_KEY3_0								(0x1u<<0)

// NONCE0 Configuration

#define	QSPI_DMA_ENC_NONCE0_NONCE0								(0xFFFFFFFFu<<0)
#define	QSPI_DMA_ENC_NONCE0_NONCE0_0							(0x1u<<0)

// NONCE1 Configuration

#define	QSPI_DMA_ENC_NONCE1_NONCE1								(0xFFFFFFFFu<<0)
#define	QSPI_DMA_ENC_NONCE1_NONCE1_0							(0x1u<<0)

// NONCE2 Configuration

#define	QSPI_DMA_ENC_NONCE2_NONCE2								(0xFFFFFFFFu<<0)
#define	QSPI_DMA_ENC_NONCE2_NONCE2_0							(0x1u<<0)

// ENABLE Configuration

#define	QSPI_DMA_ENC_ENABLE_ENABLE								(0x1u<<0)
#define	QSPI_DMA_ENC_ENABLE_ENABLE_DISABLED						(0x0u<<0)
#define	QSPI_DMA_ENC_ENABLE_ENABLE_ENABLED						(0x1u<<0)

// IFCONFIG1 Configuration

#define	QSPI_IFCONFIG1_SCKFREQ									(0xFu<<28)
#define	QSPI_IFCONFIG1_SCKFREQ_0								(0x1u<<28)
#define	QSPI_IFCONFIG1_SPIMODE									(0x1u<<25)
#define	QSPI_IFCONFIG1_DPMEN									(0x1u<<24)
#define	QSPI_IFCONFIG1_SCKDELAY									(0xFFu<<0)
#define	QSPI_IFCONFIG1_SCKDELAY_0								(0x1u<<0)
#define	QSPI_IFCONFIG1_SPIMODE_MODE0							(0x0u<<25)
#define	QSPI_IFCONFIG1_SPIMODE_MODE3							(0x1u<<25)
#define	QSPI_IFCONFIG1_DPMEN_EXIT								(0x0u<<24)
#define	QSPI_IFCONFIG1_DPMEN_ENTER								(0x1u<<24)

// STATUS Configuration

#define	QSPI_STATUS_SREG										(0xFFu<<24)
#define	QSPI_STATUS_SREG_0										(0x1u<<24)
#define	QSPI_STATUS_READY										(0x1u<<3)
#define	QSPI_STATUS_DPM											(0x1u<<2)
#define	QSPI_STATUS_READY_READY									(0x1u<<3)
#define	QSPI_STATUS_READY_BUSY									(0x0u<<3)
#define	QSPI_STATUS_DPM_DISABLED								(0x0u<<2)
#define	QSPI_STATUS_DPM_ENABLED									(0x1u<<2)

// DPMDUR Configuration

#define	QSPI_DPMDUR_EXIT										(0xFFFFu<<16)
#define	QSPI_DPMDUR_EXIT_0										(0x1u<<16)
#define	QSPI_DPMDUR_ENTER										(0xFFFFu<<0)
#define	QSPI_DPMDUR_ENTER_0										(0x1u<<0)

// ADDRCONF Configuration

#define	QSPI_ADDRCONF_WREN										(0x1u<<27)
#define	QSPI_ADDRCONF_WIPWAIT									(0x1u<<26)
#define	QSPI_ADDRCONF_MODE										(0x3u<<24)
#define	QSPI_ADDRCONF_MODE_0									(0x1u<<24)
#define	QSPI_ADDRCONF_BYTE1										(0xFFu<<16)
#define	QSPI_ADDRCONF_BYTE1_0									(0x1u<<16)
#define	QSPI_ADDRCONF_BYTE0										(0xFFu<<8)
#define	QSPI_ADDRCONF_BYTE0_0									(0x1u<<8)
#define	QSPI_ADDRCONF_OPCODE									(0xFFu<<0)
#define	QSPI_ADDRCONF_OPCODE_0									(0x1u<<0)
#define	QSPI_ADDRCONF_WREN_DISABLE								(0x0u<<27)
#define	QSPI_ADDRCONF_WREN_ENABLE								(0x1u<<27)
#define	QSPI_ADDRCONF_WIPWAIT_DISABLE							(0x0u<<26)
#define	QSPI_ADDRCONF_WIPWAIT_ENABLE							(0x1u<<26)
#define	QSPI_ADDRCONF_MODE_NOINSTR								(0x0u<<24)
#define	QSPI_ADDRCONF_MODE_OPCODE								(0x1u<<24)
#define	QSPI_ADDRCONF_MODE_OPBYTE0								(0x2u<<24)
#define	QSPI_ADDRCONF_MODE_ALL									(0x3u<<24)

// CINSTRCONF Configuration

#define	QSPI_CINSTRCONF_LFSTOP									(0x1u<<17)
#define	QSPI_CINSTRCONF_LFEN									(0x1u<<16)
#define	QSPI_CINSTRCONF_WREN									(0x1u<<15)
#define	QSPI_CINSTRCONF_WIPWAIT									(0x1u<<14)
#define	QSPI_CINSTRCONF_LIO3									(0x1u<<13)
#define	QSPI_CINSTRCONF_LIO2									(0x1u<<12)
#define	QSPI_CINSTRCONF_LENGTH									(0xFu<<8)
#define	QSPI_CINSTRCONF_LENGTH_0								(0x1u<<8)
#define	QSPI_CINSTRCONF_OPCODE									(0xFFu<<0)
#define	QSPI_CINSTRCONF_OPCODE_0								(0x1u<<0)
#define	QSPI_CINSTRCONF_LFSTOP_STOP								(0x1u<<17)
#define	QSPI_CINSTRCONF_LFEN_DISABLE							(0x0u<<16)
#define	QSPI_CINSTRCONF_LFEN_ENABLE								(0x1u<<16)
#define	QSPI_CINSTRCONF_WREN_DISABLE							(0x0u<<15)
#define	QSPI_CINSTRCONF_WREN_ENABLE								(0x1u<<15)
#define	QSPI_CINSTRCONF_WIPWAIT_DISABLE							(0x0u<<14)
#define	QSPI_CINSTRCONF_WIPWAIT_ENABLE							(0x1u<<14)
#define	QSPI_CINSTRCONF_LENGTH_1B								(0x1u<<8)
#define	QSPI_CINSTRCONF_LENGTH_2B								(0x2u<<8)
#define	QSPI_CINSTRCONF_LENGTH_3B								(0x3u<<8)
#define	QSPI_CINSTRCONF_LENGTH_4B								(0x4u<<8)
#define	QSPI_CINSTRCONF_LENGTH_5B								(0x5u<<8)
#define	QSPI_CINSTRCONF_LENGTH_6B								(0x6u<<8)
#define	QSPI_CINSTRCONF_LENGTH_7B								(0x7u<<8)
#define	QSPI_CINSTRCONF_LENGTH_8B								(0x8u<<8)
#define	QSPI_CINSTRCONF_LENGTH_9B								(0x9u<<8)

// CINSTRDAT0 Configuration

#define	QSPI_CINSTRDAT0_BYTE3									(0xFFu<<24)
#define	QSPI_CINSTRDAT0_BYTE3_0									(0x1u<<24)
#define	QSPI_CINSTRDAT0_BYTE2									(0xFFu<<16)
#define	QSPI_CINSTRDAT0_BYTE2_0									(0x1u<<16)
#define	QSPI_CINSTRDAT0_BYTE1									(0xFFu<<8)
#define	QSPI_CINSTRDAT0_BYTE1_0									(0x1u<<8)
#define	QSPI_CINSTRDAT0_BYTE0									(0xFFu<<0)
#define	QSPI_CINSTRDAT0_BYTE0_0									(0x1u<<0)

// CINSTRDAT1 Configuration

#define	QSPI_CINSTRDAT1_BYTE7									(0xFFu<<24)
#define	QSPI_CINSTRDAT1_BYTE7_0									(0x1u<<24)
#define	QSPI_CINSTRDAT1_BYTE6									(0xFFu<<16)
#define	QSPI_CINSTRDAT1_BYTE6_0									(0x1u<<16)
#define	QSPI_CINSTRDAT1_BYTE5									(0xFFu<<8)
#define	QSPI_CINSTRDAT1_BYTE5_0									(0x1u<<8)
#define	QSPI_CINSTRDAT1_BYTE4									(0xFFu<<0)
#define	QSPI_CINSTRDAT1_BYTE4_0									(0x1u<<0)

// IFTIMING Configuration

#define	QSPI_IFTIMING_RXDELAY									(0x7u<<8)
#define	QSPI_IFTIMING_RXDELAY_0									(0x1u<<8)
