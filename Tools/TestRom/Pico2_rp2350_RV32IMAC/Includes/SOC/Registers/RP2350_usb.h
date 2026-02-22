/*
; RP2350_usb.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_usb equates.
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

// USB address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	ADDR_ENDP;
	volatile	uint32_t	ADDR_ENDP1;
	volatile	uint32_t	ADDR_ENDP2;
	volatile	uint32_t	ADDR_ENDP3;
	volatile	uint32_t	ADDR_ENDP4;
	volatile	uint32_t	ADDR_ENDP5;
	volatile	uint32_t	ADDR_ENDP6;
	volatile	uint32_t	ADDR_ENDP7;
	volatile	uint32_t	ADDR_ENDP8;
	volatile	uint32_t	ADDR_ENDP9;
	volatile	uint32_t	ADDR_ENDP10;
	volatile	uint32_t	ADDR_ENDP11;
	volatile	uint32_t	ADDR_ENDP12;
	volatile	uint32_t	ADDR_ENDP13;
	volatile	uint32_t	ADDR_ENDP14;
	volatile	uint32_t	ADDR_ENDP15;
	volatile	uint32_t	MAIN_CTRL;
	volatile	uint32_t	SOF_WR;
	volatile	uint32_t	SOF_RD;
	volatile	uint32_t	SIE_CTRL;
	volatile	uint32_t	SIE_STATUS;
	volatile	uint32_t	INT_EP_CTRL;
	volatile	uint32_t	BUFF_STATUS;
	volatile	uint32_t	BUFF_CPU_SHOULD_HANDLE;
	volatile	uint32_t	EP_ABORT;
	volatile	uint32_t	EP_ABORT_DONE;
	volatile	uint32_t	EP_STALL_ARM;
	volatile	uint32_t	NAK_POLL;
	volatile	uint32_t	EP_STATUS_STALL_NAK;
	volatile	uint32_t	MUXING;
	volatile	uint32_t	PWR;
	volatile	uint32_t	USBPHY_DIRECT;
	volatile	uint32_t	USBPHY_DIRECT_OVERRIDE;
	volatile	uint32_t	USBPHY_TRIM;
	volatile	uint32_t	LINESTATE_TUNING;
	volatile	uint32_t	INTR;
	volatile	uint32_t	INTE;
	volatile	uint32_t	INTF;
	volatile	uint32_t	INTS;
	volatile	uint32_t	RESERVED0[25];
	volatile	uint32_t	SOF_TIMESTAMP_RAW;
	volatile	uint32_t	SOF_TIMESTAMP_LAST;
	volatile	uint32_t	SM_STATE;
	volatile	uint32_t	EP_TX_ERROR;
	volatile	uint32_t	EP_RX_ERROR;
	volatile	uint32_t	DEV_SM_WATCHDOG;
} USB_TypeDef;

#ifdef __cplusplus
#define	USB_NS	reinterpret_cast<USB_TypeDef *>(0x50110000u)
#define	USB_S	reinterpret_cast<USB_TypeDef *>(0x50110000u)
#else
#define	USB_NS	((USB_TypeDef *)0x50110000u)
#define	USB_S	((USB_TypeDef *)0x50110000u)
#endif

// ADDR_ENDP Configuration

#define	USB_ADDR_ENDP_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP_ADDRESS_0									(0x1u<<0)
#define	USB_ADDR_ENDP_ENDPOINT									(0xFu<<16)
#define	USB_ADDR_ENDP_ENDPOINT_0								(0x1u<<16)

// ADDR_ENDP1 Configuration

#define	USB_ADDR_ENDP1_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP1_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP1_ENDPOINT									(0xFu<<16)
#define	USB_ADDR_ENDP1_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP1_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP1_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP2 Configuration

#define	USB_ADDR_ENDP2_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP2_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP2_ENDPOINT									(0xFu<<16)
#define	USB_ADDR_ENDP2_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP2_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP2_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP3 Configuration

#define	USB_ADDR_ENDP3_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP3_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP3_ENDPOINT									(0xFu<<16)
#define	USB_ADDR_ENDP3_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP3_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP3_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP4 Configuration

#define	USB_ADDR_ENDP4_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP4_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP4_ENDPOINT									(0xFu<<16)
#define	USB_ADDR_ENDP4_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP4_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP4_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP5 Configuration

#define	USB_ADDR_ENDP5_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP5_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP5_ENDPOINT									(0xFu<<16)
#define	USB_ADDR_ENDP5_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP5_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP5_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP6 Configuration

#define	USB_ADDR_ENDP6_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP6_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP6_ENDPOINT									(0xFu<<16)
#define	USB_ADDR_ENDP6_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP6_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP6_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP7 Configuration

#define	USB_ADDR_ENDP7_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP7_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP7_ENDPOINT									(0xFu<<16)
#define	USB_ADDR_ENDP7_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP7_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP7_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP8 Configuration

#define	USB_ADDR_ENDP8_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP8_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP8_ENDPOINT									(0xFu<<16)
#define	USB_ADDR_ENDP8_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP8_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP8_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP9 Configuration

#define	USB_ADDR_ENDP9_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP9_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP9_ENDPOINT									(0xFu<<16)
#define	USB_ADDR_ENDP9_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP9_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP9_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP10 Configuration

#define	USB_ADDR_ENDP10_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP10_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP10_ENDPOINT								(0xFu<<16)
#define	USB_ADDR_ENDP10_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP10_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP10_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP11 Configuration

#define	USB_ADDR_ENDP11_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP11_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP11_ENDPOINT								(0xFu<<16)
#define	USB_ADDR_ENDP11_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP11_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP11_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP12 Configuration

#define	USB_ADDR_ENDP12_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP12_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP12_ENDPOINT								(0xFu<<16)
#define	USB_ADDR_ENDP12_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP12_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP12_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP13 Configuration

#define	USB_ADDR_ENDP13_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP13_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP13_ENDPOINT								(0xFu<<16)
#define	USB_ADDR_ENDP13_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP13_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP13_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP14 Configuration

#define	USB_ADDR_ENDP14_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP14_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP14_ENDPOINT								(0xFu<<16)
#define	USB_ADDR_ENDP14_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP14_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP14_INTEP_PREAMBLE							(0x1u<<26)

// ADDR_ENDP15 Configuration

#define	USB_ADDR_ENDP15_ADDRESS									(0x7Fu<<0)
#define	USB_ADDR_ENDP15_ADDRESS_0								(0x1u<<0)
#define	USB_ADDR_ENDP15_ENDPOINT								(0xFu<<16)
#define	USB_ADDR_ENDP15_ENDPOINT_0								(0x1u<<16)
#define	USB_ADDR_ENDP15_INTEP_DIR								(0x1u<<25)
#define	USB_ADDR_ENDP15_INTEP_PREAMBLE							(0x1u<<26)

// MAIN_CTRL Configuration

#define	USB_MAIN_CTRL_CONTROLLER_EN								(0x1u<<0)
#define	USB_MAIN_CTRL_HOST_NDEVICE								(0x1u<<1)
#define	USB_MAIN_CTRL_PHY_ISO									(0x1u<<2)
#define	USB_MAIN_CTRL_SIM_TIMING								(0x1u<<31)

// SOF_WR Configuration

#define	USB_SOF_WR_COUNT										(0x7FFu<<0)
#define	USB_SOF_WR_COUNT_0										(0x1u<<0)

// SOF_RD Configuration

#define	USB_SOF_RD_COUNT										(0x7FFu<<0)
#define	USB_SOF_RD_COUNT_0										(0x1u<<0)

// SIE_CTRL Configuration

#define	USB_SIE_CTRL_START_TRANS								(0x1u<<0)
#define	USB_SIE_CTRL_SEND_SETUP									(0x1u<<1)
#define	USB_SIE_CTRL_SEND_DATA									(0x1u<<2)
#define	USB_SIE_CTRL_RECEIVE_DATA								(0x1u<<3)
#define	USB_SIE_CTRL_STOP_TRANS									(0x1u<<4)
#define	USB_SIE_CTRL_PREAMBLE_EN								(0x1u<<6)
#define	USB_SIE_CTRL_SOF_SYNC									(0x1u<<8)
#define	USB_SIE_CTRL_SOF_EN										(0x1u<<9)
#define	USB_SIE_CTRL_KEEP_ALIVE_EN								(0x1u<<10)
#define	USB_SIE_CTRL_VBUS_EN									(0x1u<<11)
#define	USB_SIE_CTRL_RESUME										(0x1u<<12)
#define	USB_SIE_CTRL_RESET_BUS									(0x1u<<13)
#define	USB_SIE_CTRL_PULLDOWN_EN								(0x1u<<15)
#define	USB_SIE_CTRL_PULLUP_EN									(0x1u<<16)
#define	USB_SIE_CTRL_RPU_OPT									(0x1u<<17)
#define	USB_SIE_CTRL_TRANSCEIVER_PD								(0x1u<<18)
#define	USB_SIE_CTRL_EP0_STOP_ON_SHORT_PACKET					(0x1u<<19)
#define	USB_SIE_CTRL_DIRECT_DM									(0x1u<<24)
#define	USB_SIE_CTRL_DIRECT_DP									(0x1u<<25)
#define	USB_SIE_CTRL_DIRECT_EN									(0x1u<<26)
#define	USB_SIE_CTRL_EP0_INT_NAK								(0x1u<<27)
#define	USB_SIE_CTRL_EP0_INT_2BUF								(0x1u<<28)
#define	USB_SIE_CTRL_EP0_INT_1BUF								(0x1u<<29)
#define	USB_SIE_CTRL_EP0_DOUBLE_BUF								(0x1u<<30)
#define	USB_SIE_CTRL_EP0_INT_STALL								(0x1u<<31)

// SIE_STATUS Configuration

#define	USB_SIE_STATUS_VBUS_DETECTED							(0x1u<<0)
#define	USB_SIE_STATUS_LINE_STATE								(0x3u<<2)
#define	USB_SIE_STATUS_LINE_STATE_0								(0x1u<<2)
#define	USB_SIE_STATUS_SUSPENDED								(0x1u<<4)
#define	USB_SIE_STATUS_SPEED									(0x3u<<8)
#define	USB_SIE_STATUS_SPEED_0									(0x1u<<8)
#define	USB_SIE_STATUS_VBUS_OVER_CURR							(0x1u<<10)
#define	USB_SIE_STATUS_RESUME									(0x1u<<11)
#define	USB_SIE_STATUS_RX_SHORT_PACKET							(0x1u<<12)
#define	USB_SIE_STATUS_CONNECTED								(0x1u<<16)
#define	USB_SIE_STATUS_SETUP_REC								(0x1u<<17)
#define	USB_SIE_STATUS_TRANS_COMPLETE							(0x1u<<18)
#define	USB_SIE_STATUS_BUS_RESET								(0x1u<<19)
#define	USB_SIE_STATUS_ENDPOINT_ERROR							(0x1u<<23)
#define	USB_SIE_STATUS_CRC_ERROR								(0x1u<<24)
#define	USB_SIE_STATUS_BIT_STUFF_ERROR							(0x1u<<25)
#define	USB_SIE_STATUS_RX_OVERFLOW								(0x1u<<26)
#define	USB_SIE_STATUS_RX_TIMEOUT								(0x1u<<27)
#define	USB_SIE_STATUS_NAK_REC									(0x1u<<28)
#define	USB_SIE_STATUS_STALL_REC								(0x1u<<29)
#define	USB_SIE_STATUS_ACK_REC									(0x1u<<30)
#define	USB_SIE_STATUS_DATA_SEQ_ERROR							(0x1u<<31)

// INT_EP_CTRL Configuration

#define	USB_INT_EP_CTRL_INT_EP_ACTIVE							(0x7FFFu<<1)
#define	USB_INT_EP_CTRL_INT_EP_ACTIVE_0							(0x1u<<1)

// BUFF_STATUS Configuration

#define	USB_BUFF_STATUS_EP0_IN									(0x1u<<0)
#define	USB_BUFF_STATUS_EP0_OUT									(0x1u<<1)
#define	USB_BUFF_STATUS_EP1_IN									(0x1u<<2)
#define	USB_BUFF_STATUS_EP1_OUT									(0x1u<<3)
#define	USB_BUFF_STATUS_EP2_IN									(0x1u<<4)
#define	USB_BUFF_STATUS_EP2_OUT									(0x1u<<5)
#define	USB_BUFF_STATUS_EP3_IN									(0x1u<<6)
#define	USB_BUFF_STATUS_EP3_OUT									(0x1u<<7)
#define	USB_BUFF_STATUS_EP4_IN									(0x1u<<8)
#define	USB_BUFF_STATUS_EP4_OUT									(0x1u<<9)
#define	USB_BUFF_STATUS_EP5_IN									(0x1u<<10)
#define	USB_BUFF_STATUS_EP5_OUT									(0x1u<<11)
#define	USB_BUFF_STATUS_EP6_IN									(0x1u<<12)
#define	USB_BUFF_STATUS_EP6_OUT									(0x1u<<13)
#define	USB_BUFF_STATUS_EP7_IN									(0x1u<<14)
#define	USB_BUFF_STATUS_EP7_OUT									(0x1u<<15)
#define	USB_BUFF_STATUS_EP8_IN									(0x1u<<16)
#define	USB_BUFF_STATUS_EP8_OUT									(0x1u<<17)
#define	USB_BUFF_STATUS_EP9_IN									(0x1u<<18)
#define	USB_BUFF_STATUS_EP9_OUT									(0x1u<<19)
#define	USB_BUFF_STATUS_EP10_IN									(0x1u<<20)
#define	USB_BUFF_STATUS_EP10_OUT								(0x1u<<21)
#define	USB_BUFF_STATUS_EP11_IN									(0x1u<<22)
#define	USB_BUFF_STATUS_EP11_OUT								(0x1u<<23)
#define	USB_BUFF_STATUS_EP12_IN									(0x1u<<24)
#define	USB_BUFF_STATUS_EP12_OUT								(0x1u<<25)
#define	USB_BUFF_STATUS_EP13_IN									(0x1u<<26)
#define	USB_BUFF_STATUS_EP13_OUT								(0x1u<<27)
#define	USB_BUFF_STATUS_EP14_IN									(0x1u<<28)
#define	USB_BUFF_STATUS_EP14_OUT								(0x1u<<29)
#define	USB_BUFF_STATUS_EP15_IN									(0x1u<<30)
#define	USB_BUFF_STATUS_EP15_OUT								(0x1u<<31)

// BUFF_CPU_SHOULD_HANDLE Configuration

#define	USB_BUFF_CPU_SHOULD_HANDLE_EP0_IN						(0x1u<<0)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP0_OUT						(0x1u<<1)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP1_IN						(0x1u<<2)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP1_OUT						(0x1u<<3)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP2_IN						(0x1u<<4)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP2_OUT						(0x1u<<5)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP3_IN						(0x1u<<6)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP3_OUT						(0x1u<<7)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP4_IN						(0x1u<<8)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP4_OUT						(0x1u<<9)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP5_IN						(0x1u<<10)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP5_OUT						(0x1u<<11)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP6_IN						(0x1u<<12)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP6_OUT						(0x1u<<13)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP7_IN						(0x1u<<14)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP7_OUT						(0x1u<<15)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP8_IN						(0x1u<<16)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP8_OUT						(0x1u<<17)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP9_IN						(0x1u<<18)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP9_OUT						(0x1u<<19)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP10_IN						(0x1u<<20)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP10_OUT						(0x1u<<21)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP11_IN						(0x1u<<22)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP11_OUT						(0x1u<<23)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP12_IN						(0x1u<<24)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP12_OUT						(0x1u<<25)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP13_IN						(0x1u<<26)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP13_OUT						(0x1u<<27)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP14_IN						(0x1u<<28)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP14_OUT						(0x1u<<29)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP15_IN						(0x1u<<30)
#define	USB_BUFF_CPU_SHOULD_HANDLE_EP15_OUT						(0x1u<<31)

// EP_ABORT Configuration

#define	USB_EP_ABORT_EP0_IN										(0x1u<<0)
#define	USB_EP_ABORT_EP0_OUT									(0x1u<<1)
#define	USB_EP_ABORT_EP1_IN										(0x1u<<2)
#define	USB_EP_ABORT_EP1_OUT									(0x1u<<3)
#define	USB_EP_ABORT_EP2_IN										(0x1u<<4)
#define	USB_EP_ABORT_EP2_OUT									(0x1u<<5)
#define	USB_EP_ABORT_EP3_IN										(0x1u<<6)
#define	USB_EP_ABORT_EP3_OUT									(0x1u<<7)
#define	USB_EP_ABORT_EP4_IN										(0x1u<<8)
#define	USB_EP_ABORT_EP4_OUT									(0x1u<<9)
#define	USB_EP_ABORT_EP5_IN										(0x1u<<10)
#define	USB_EP_ABORT_EP5_OUT									(0x1u<<11)
#define	USB_EP_ABORT_EP6_IN										(0x1u<<12)
#define	USB_EP_ABORT_EP6_OUT									(0x1u<<13)
#define	USB_EP_ABORT_EP7_IN										(0x1u<<14)
#define	USB_EP_ABORT_EP7_OUT									(0x1u<<15)
#define	USB_EP_ABORT_EP8_IN										(0x1u<<16)
#define	USB_EP_ABORT_EP8_OUT									(0x1u<<17)
#define	USB_EP_ABORT_EP9_IN										(0x1u<<18)
#define	USB_EP_ABORT_EP9_OUT									(0x1u<<19)
#define	USB_EP_ABORT_EP10_IN									(0x1u<<20)
#define	USB_EP_ABORT_EP10_OUT									(0x1u<<21)
#define	USB_EP_ABORT_EP11_IN									(0x1u<<22)
#define	USB_EP_ABORT_EP11_OUT									(0x1u<<23)
#define	USB_EP_ABORT_EP12_IN									(0x1u<<24)
#define	USB_EP_ABORT_EP12_OUT									(0x1u<<25)
#define	USB_EP_ABORT_EP13_IN									(0x1u<<26)
#define	USB_EP_ABORT_EP13_OUT									(0x1u<<27)
#define	USB_EP_ABORT_EP14_IN									(0x1u<<28)
#define	USB_EP_ABORT_EP14_OUT									(0x1u<<29)
#define	USB_EP_ABORT_EP15_IN									(0x1u<<30)
#define	USB_EP_ABORT_EP15_OUT									(0x1u<<31)

// EP_ABORT_DONE Configuration

#define	USB_EP_ABORT_DONE_EP0_IN								(0x1u<<0)
#define	USB_EP_ABORT_DONE_EP0_OUT								(0x1u<<1)
#define	USB_EP_ABORT_DONE_EP1_IN								(0x1u<<2)
#define	USB_EP_ABORT_DONE_EP1_OUT								(0x1u<<3)
#define	USB_EP_ABORT_DONE_EP2_IN								(0x1u<<4)
#define	USB_EP_ABORT_DONE_EP2_OUT								(0x1u<<5)
#define	USB_EP_ABORT_DONE_EP3_IN								(0x1u<<6)
#define	USB_EP_ABORT_DONE_EP3_OUT								(0x1u<<7)
#define	USB_EP_ABORT_DONE_EP4_IN								(0x1u<<8)
#define	USB_EP_ABORT_DONE_EP4_OUT								(0x1u<<9)
#define	USB_EP_ABORT_DONE_EP5_IN								(0x1u<<10)
#define	USB_EP_ABORT_DONE_EP5_OUT								(0x1u<<11)
#define	USB_EP_ABORT_DONE_EP6_IN								(0x1u<<12)
#define	USB_EP_ABORT_DONE_EP6_OUT								(0x1u<<13)
#define	USB_EP_ABORT_DONE_EP7_IN								(0x1u<<14)
#define	USB_EP_ABORT_DONE_EP7_OUT								(0x1u<<15)
#define	USB_EP_ABORT_DONE_EP8_IN								(0x1u<<16)
#define	USB_EP_ABORT_DONE_EP8_OUT								(0x1u<<17)
#define	USB_EP_ABORT_DONE_EP9_IN								(0x1u<<18)
#define	USB_EP_ABORT_DONE_EP9_OUT								(0x1u<<19)
#define	USB_EP_ABORT_DONE_EP10_IN								(0x1u<<20)
#define	USB_EP_ABORT_DONE_EP10_OUT								(0x1u<<21)
#define	USB_EP_ABORT_DONE_EP11_IN								(0x1u<<22)
#define	USB_EP_ABORT_DONE_EP11_OUT								(0x1u<<23)
#define	USB_EP_ABORT_DONE_EP12_IN								(0x1u<<24)
#define	USB_EP_ABORT_DONE_EP12_OUT								(0x1u<<25)
#define	USB_EP_ABORT_DONE_EP13_IN								(0x1u<<26)
#define	USB_EP_ABORT_DONE_EP13_OUT								(0x1u<<27)
#define	USB_EP_ABORT_DONE_EP14_IN								(0x1u<<28)
#define	USB_EP_ABORT_DONE_EP14_OUT								(0x1u<<29)
#define	USB_EP_ABORT_DONE_EP15_IN								(0x1u<<30)
#define	USB_EP_ABORT_DONE_EP15_OUT								(0x1u<<31)

// EP_STALL_ARM Configuration

#define	USB_EP_STALL_ARM_EP0_IN									(0x1u<<0)
#define	USB_EP_STALL_ARM_EP0_OUT								(0x1u<<1)

// NAK_POLL Configuration

#define	USB_NAK_POLL_DELAY_LS									(0x3FFu<<0)
#define	USB_NAK_POLL_DELAY_LS_0									(0x1u<<0)
#define	USB_NAK_POLL_RETRY_COUNT_LO								(0x3Fu<<10)
#define	USB_NAK_POLL_RETRY_COUNT_LO_0							(0x1u<<10)
#define	USB_NAK_POLL_DELAY_FS									(0x3FFu<<16)
#define	USB_NAK_POLL_DELAY_FS_0									(0x1u<<16)
#define	USB_NAK_POLL_STOP_EPX_ON_NAK							(0x1u<<26)
#define	USB_NAK_POLL_EPX_STOPPED_ON_NAK							(0x1u<<27)
#define	USB_NAK_POLL_RETRY_COUNT_HI								(0xFu<<28)
#define	USB_NAK_POLL_RETRY_COUNT_HI_0							(0x1u<<28)

// EP_STATUS_STALL_NAK Configuration

#define	USB_EP_STATUS_STALL_NAK_EP0_IN							(0x1u<<0)
#define	USB_EP_STATUS_STALL_NAK_EP0_OUT							(0x1u<<1)
#define	USB_EP_STATUS_STALL_NAK_EP1_IN							(0x1u<<2)
#define	USB_EP_STATUS_STALL_NAK_EP1_OUT							(0x1u<<3)
#define	USB_EP_STATUS_STALL_NAK_EP2_IN							(0x1u<<4)
#define	USB_EP_STATUS_STALL_NAK_EP2_OUT							(0x1u<<5)
#define	USB_EP_STATUS_STALL_NAK_EP3_IN							(0x1u<<6)
#define	USB_EP_STATUS_STALL_NAK_EP3_OUT							(0x1u<<7)
#define	USB_EP_STATUS_STALL_NAK_EP4_IN							(0x1u<<8)
#define	USB_EP_STATUS_STALL_NAK_EP4_OUT							(0x1u<<9)
#define	USB_EP_STATUS_STALL_NAK_EP5_IN							(0x1u<<10)
#define	USB_EP_STATUS_STALL_NAK_EP5_OUT							(0x1u<<11)
#define	USB_EP_STATUS_STALL_NAK_EP6_IN							(0x1u<<12)
#define	USB_EP_STATUS_STALL_NAK_EP6_OUT							(0x1u<<13)
#define	USB_EP_STATUS_STALL_NAK_EP7_IN							(0x1u<<14)
#define	USB_EP_STATUS_STALL_NAK_EP7_OUT							(0x1u<<15)
#define	USB_EP_STATUS_STALL_NAK_EP8_IN							(0x1u<<16)
#define	USB_EP_STATUS_STALL_NAK_EP8_OUT							(0x1u<<17)
#define	USB_EP_STATUS_STALL_NAK_EP9_IN							(0x1u<<18)
#define	USB_EP_STATUS_STALL_NAK_EP9_OUT							(0x1u<<19)
#define	USB_EP_STATUS_STALL_NAK_EP10_IN							(0x1u<<20)
#define	USB_EP_STATUS_STALL_NAK_EP10_OUT						(0x1u<<21)
#define	USB_EP_STATUS_STALL_NAK_EP11_IN							(0x1u<<22)
#define	USB_EP_STATUS_STALL_NAK_EP11_OUT						(0x1u<<23)
#define	USB_EP_STATUS_STALL_NAK_EP12_IN							(0x1u<<24)
#define	USB_EP_STATUS_STALL_NAK_EP12_OUT						(0x1u<<25)
#define	USB_EP_STATUS_STALL_NAK_EP13_IN							(0x1u<<26)
#define	USB_EP_STATUS_STALL_NAK_EP13_OUT						(0x1u<<27)
#define	USB_EP_STATUS_STALL_NAK_EP14_IN							(0x1u<<28)
#define	USB_EP_STATUS_STALL_NAK_EP14_OUT						(0x1u<<29)
#define	USB_EP_STATUS_STALL_NAK_EP15_IN							(0x1u<<30)
#define	USB_EP_STATUS_STALL_NAK_EP15_OUT						(0x1u<<31)

// MUXING Configuration

#define	USB_MUXING_TO_PHY										(0x1u<<0)
#define	USB_MUXING_TO_EXTPHY									(0x1u<<1)
#define	USB_MUXING_TO_DIGITAL_PAD								(0x1u<<2)
#define	USB_MUXING_SOFTCON										(0x1u<<3)
#define	USB_MUXING_USBPHY_AS_GPIO								(0x1u<<4)
#define	USB_MUXING_SWAP_DPDM									(0x1u<<31)

// PWR Configuration

#define	USB_PWR_VBUS_EN											(0x1u<<0)
#define	USB_PWR_VBUS_EN_OVERRIDE_EN								(0x1u<<1)
#define	USB_PWR_VBUS_DETECT										(0x1u<<2)
#define	USB_PWR_VBUS_DETECT_OVERRIDE_EN							(0x1u<<3)
#define	USB_PWR_OVERCURR_DETECT									(0x1u<<4)
#define	USB_PWR_OVERCURR_DETECT_EN								(0x1u<<5)

// USBPHY_DIRECT Configuration

#define	USB_USBPHY_DIRECT_DP_PULLUP_HISEL						(0x1u<<0)
#define	USB_USBPHY_DIRECT_DP_PULLUP_EN							(0x1u<<1)
#define	USB_USBPHY_DIRECT_DP_PULLDN_EN							(0x1u<<2)
#define	USB_USBPHY_DIRECT_DM_PULLUP_HISEL						(0x1u<<4)
#define	USB_USBPHY_DIRECT_DM_PULLUP_EN							(0x1u<<5)
#define	USB_USBPHY_DIRECT_DM_PULLDN_EN							(0x1u<<6)
#define	USB_USBPHY_DIRECT_TX_DP_OE								(0x1u<<8)
#define	USB_USBPHY_DIRECT_TX_DM_OE								(0x1u<<9)
#define	USB_USBPHY_DIRECT_TX_DP									(0x1u<<10)
#define	USB_USBPHY_DIRECT_TX_DM									(0x1u<<11)
#define	USB_USBPHY_DIRECT_RX_PD									(0x1u<<12)
#define	USB_USBPHY_DIRECT_TX_PD									(0x1u<<13)
#define	USB_USBPHY_DIRECT_TX_FSSLEW								(0x1u<<14)
#define	USB_USBPHY_DIRECT_TX_DIFFMODE							(0x1u<<15)
#define	USB_USBPHY_DIRECT_RX_DD									(0x1u<<16)
#define	USB_USBPHY_DIRECT_RX_DP									(0x1u<<17)
#define	USB_USBPHY_DIRECT_RX_DM									(0x1u<<18)
#define	USB_USBPHY_DIRECT_DP_OVCN								(0x1u<<19)
#define	USB_USBPHY_DIRECT_DM_OVCN								(0x1u<<20)
#define	USB_USBPHY_DIRECT_DP_OVV								(0x1u<<21)
#define	USB_USBPHY_DIRECT_DM_OVV								(0x1u<<22)
#define	USB_USBPHY_DIRECT_RX_DD_OVERRIDE						(0x1u<<23)
#define	USB_USBPHY_DIRECT_RX_DP_OVERRIDE						(0x1u<<24)
#define	USB_USBPHY_DIRECT_RX_DM_OVERRIDE						(0x1u<<25)

// USBPHY_DIRECT_OVERRIDE Configuration

#define	USB_USBPHY_DIRECT_OVERRIDE_DP_PULLUP_HISEL_OVERRIDE_EN	(0x1u<<0)
#define	USB_USBPHY_DIRECT_OVERRIDE_DM_PULLUP_HISEL_OVERRIDE_EN	(0x1u<<1)
#define	USB_USBPHY_DIRECT_OVERRIDE_DP_PULLUP_EN_OVERRIDE_EN		(0x1u<<2)
#define	USB_USBPHY_DIRECT_OVERRIDE_DP_PULLDN_EN_OVERRIDE_EN		(0x1u<<3)
#define	USB_USBPHY_DIRECT_OVERRIDE_DM_PULLDN_EN_OVERRIDE_EN		(0x1u<<4)
#define	USB_USBPHY_DIRECT_OVERRIDE_TX_DP_OE_OVERRIDE_EN			(0x1u<<5)
#define	USB_USBPHY_DIRECT_OVERRIDE_TX_DM_OE_OVERRIDE_EN			(0x1u<<6)
#define	USB_USBPHY_DIRECT_OVERRIDE_TX_DP_OVERRIDE_EN			(0x1u<<7)
#define	USB_USBPHY_DIRECT_OVERRIDE_TX_DM_OVERRIDE_EN			(0x1u<<8)
#define	USB_USBPHY_DIRECT_OVERRIDE_RX_PD_OVERRIDE_EN			(0x1u<<9)
#define	USB_USBPHY_DIRECT_OVERRIDE_TX_PD_OVERRIDE_EN			(0x1u<<10)
#define	USB_USBPHY_DIRECT_OVERRIDE_TX_FSSLEW_OVERRIDE_EN		(0x1u<<11)
#define	USB_USBPHY_DIRECT_OVERRIDE_DM_PULLUP_OVERRIDE_EN		(0x1u<<12)
#define	USB_USBPHY_DIRECT_OVERRIDE_TX_DIFFMODE_OVERRIDE_EN		(0x1u<<15)
#define	USB_USBPHY_DIRECT_OVERRIDE_RX_DD_OVERRIDE_EN			(0x1u<<16)
#define	USB_USBPHY_DIRECT_OVERRIDE_RX_DP_OVERRIDE_EN			(0x1u<<17)
#define	USB_USBPHY_DIRECT_OVERRIDE_RX_DM_OVERRIDE_EN			(0x1u<<18)

// USBPHY_TRIM Configuration

#define	USB_USBPHY_TRIM_DP_PULLDN_TRIM							(0x1Fu<<0)
#define	USB_USBPHY_TRIM_DP_PULLDN_TRIM_0						(0x1u<<0)
#define	USB_USBPHY_TRIM_DM_PULLDN_TRIM							(0x1Fu<<8)
#define	USB_USBPHY_TRIM_DM_PULLDN_TRIM_0						(0x1u<<8)

// LINESTATE_TUNING Configuration

#define	USB_LINESTATE_TUNING_RCV_DELAY							(0x1u<<0)
#define	USB_LINESTATE_TUNING_LINESTATE_DELAY					(0x1u<<1)
#define	USB_LINESTATE_TUNING_MULTI_HUB_FIX						(0x1u<<2)
#define	USB_LINESTATE_TUNING_DEV_BUFF_CONTROL_DOUBLE_READ_FIX	(0x1u<<3)
#define	USB_LINESTATE_TUNING_SIE_RX_BITSTUFF_FIX				(0x1u<<4)
#define	USB_LINESTATE_TUNING_SIE_RX_CHATTER_SE0_FIX				(0x1u<<5)
#define	USB_LINESTATE_TUNING_DEV_RX_ERR_QUIESCE					(0x1u<<6)
#define	USB_LINESTATE_TUNING_DEV_LS_WAKE_FIX					(0x1u<<7)
#define	USB_LINESTATE_TUNING_SPARE_FIX							(0xFu<<8)
#define	USB_LINESTATE_TUNING_SPARE_FIX_0						(0x1u<<8)

// INTR Configuration

#define	USB_INTR_HOST_CONN_DIS									(0x1u<<0)
#define	USB_INTR_HOST_RESUME									(0x1u<<1)
#define	USB_INTR_HOST_SOF										(0x1u<<2)
#define	USB_INTR_TRANS_COMPLETE									(0x1u<<3)
#define	USB_INTR_BUFF_STATUS									(0x1u<<4)
#define	USB_INTR_ERROR_DATA_SEQ									(0x1u<<5)
#define	USB_INTR_ERROR_RX_TIMEOUT								(0x1u<<6)
#define	USB_INTR_ERROR_RX_OVERFLOW								(0x1u<<7)
#define	USB_INTR_ERROR_BIT_STUFF								(0x1u<<8)
#define	USB_INTR_ERROR_CRC										(0x1u<<9)
#define	USB_INTR_STALL											(0x1u<<10)
#define	USB_INTR_VBUS_DETECT									(0x1u<<11)
#define	USB_INTR_BUS_RESET										(0x1u<<12)
#define	USB_INTR_DEV_CONN_DIS									(0x1u<<13)
#define	USB_INTR_DEV_SUSPEND									(0x1u<<14)
#define	USB_INTR_DEV_RESUME_FROM_HOST							(0x1u<<15)
#define	USB_INTR_SETUP_REQ										(0x1u<<16)
#define	USB_INTR_DEV_SOF										(0x1u<<17)
#define	USB_INTR_ABORT_DONE										(0x1u<<18)
#define	USB_INTR_EP_STALL_NAK									(0x1u<<19)
#define	USB_INTR_RX_SHORT_PACKET								(0x1u<<20)
#define	USB_INTR_ENDPOINT_ERROR									(0x1u<<21)
#define	USB_INTR_DEV_SM_WATCHDOG_FIRED							(0x1u<<22)
#define	USB_INTR_EPX_STOPPED_ON_NAK								(0x1u<<23)

// INTE Configuration

#define	USB_INTE_HOST_CONN_DIS									(0x1u<<0)
#define	USB_INTE_HOST_RESUME									(0x1u<<1)
#define	USB_INTE_HOST_SOF										(0x1u<<2)
#define	USB_INTE_TRANS_COMPLETE									(0x1u<<3)
#define	USB_INTE_BUFF_STATUS									(0x1u<<4)
#define	USB_INTE_ERROR_DATA_SEQ									(0x1u<<5)
#define	USB_INTE_ERROR_RX_TIMEOUT								(0x1u<<6)
#define	USB_INTE_ERROR_RX_OVERFLOW								(0x1u<<7)
#define	USB_INTE_ERROR_BIT_STUFF								(0x1u<<8)
#define	USB_INTE_ERROR_CRC										(0x1u<<9)
#define	USB_INTE_STALL											(0x1u<<10)
#define	USB_INTE_VBUS_DETECT									(0x1u<<11)
#define	USB_INTE_BUS_RESET										(0x1u<<12)
#define	USB_INTE_DEV_CONN_DIS									(0x1u<<13)
#define	USB_INTE_DEV_SUSPEND									(0x1u<<14)
#define	USB_INTE_DEV_RESUME_FROM_HOST							(0x1u<<15)
#define	USB_INTE_SETUP_REQ										(0x1u<<16)
#define	USB_INTE_DEV_SOF										(0x1u<<17)
#define	USB_INTE_ABORT_DONE										(0x1u<<18)
#define	USB_INTE_EP_STALL_NAK									(0x1u<<19)
#define	USB_INTE_RX_SHORT_PACKET								(0x1u<<20)
#define	USB_INTE_ENDPOINT_ERROR									(0x1u<<21)
#define	USB_INTE_DEV_SM_WATCHDOG_FIRED							(0x1u<<22)
#define	USB_INTE_EPX_STOPPED_ON_NAK								(0x1u<<23)

// INTF Configuration

#define	USB_INTF_HOST_CONN_DIS									(0x1u<<0)
#define	USB_INTF_HOST_RESUME									(0x1u<<1)
#define	USB_INTF_HOST_SOF										(0x1u<<2)
#define	USB_INTF_TRANS_COMPLETE									(0x1u<<3)
#define	USB_INTF_BUFF_STATUS									(0x1u<<4)
#define	USB_INTF_ERROR_DATA_SEQ									(0x1u<<5)
#define	USB_INTF_ERROR_RX_TIMEOUT								(0x1u<<6)
#define	USB_INTF_ERROR_RX_OVERFLOW								(0x1u<<7)
#define	USB_INTF_ERROR_BIT_STUFF								(0x1u<<8)
#define	USB_INTF_ERROR_CRC										(0x1u<<9)
#define	USB_INTF_STALL											(0x1u<<10)
#define	USB_INTF_VBUS_DETECT									(0x1u<<11)
#define	USB_INTF_BUS_RESET										(0x1u<<12)
#define	USB_INTF_DEV_CONN_DIS									(0x1u<<13)
#define	USB_INTF_DEV_SUSPEND									(0x1u<<14)
#define	USB_INTF_DEV_RESUME_FROM_HOST							(0x1u<<15)
#define	USB_INTF_SETUP_REQ										(0x1u<<16)
#define	USB_INTF_DEV_SOF										(0x1u<<17)
#define	USB_INTF_ABORT_DONE										(0x1u<<18)
#define	USB_INTF_EP_STALL_NAK									(0x1u<<19)
#define	USB_INTF_RX_SHORT_PACKET								(0x1u<<20)
#define	USB_INTF_ENDPOINT_ERROR									(0x1u<<21)
#define	USB_INTF_DEV_SM_WATCHDOG_FIRED							(0x1u<<22)
#define	USB_INTF_EPX_STOPPED_ON_NAK								(0x1u<<23)

// INTS Configuration

#define	USB_INTS_HOST_CONN_DIS									(0x1u<<0)
#define	USB_INTS_HOST_RESUME									(0x1u<<1)
#define	USB_INTS_HOST_SOF										(0x1u<<2)
#define	USB_INTS_TRANS_COMPLETE									(0x1u<<3)
#define	USB_INTS_BUFF_STATUS									(0x1u<<4)
#define	USB_INTS_ERROR_DATA_SEQ									(0x1u<<5)
#define	USB_INTS_ERROR_RX_TIMEOUT								(0x1u<<6)
#define	USB_INTS_ERROR_RX_OVERFLOW								(0x1u<<7)
#define	USB_INTS_ERROR_BIT_STUFF								(0x1u<<8)
#define	USB_INTS_ERROR_CRC										(0x1u<<9)
#define	USB_INTS_STALL											(0x1u<<10)
#define	USB_INTS_VBUS_DETECT									(0x1u<<11)
#define	USB_INTS_BUS_RESET										(0x1u<<12)
#define	USB_INTS_DEV_CONN_DIS									(0x1u<<13)
#define	USB_INTS_DEV_SUSPEND									(0x1u<<14)
#define	USB_INTS_DEV_RESUME_FROM_HOST							(0x1u<<15)
#define	USB_INTS_SETUP_REQ										(0x1u<<16)
#define	USB_INTS_DEV_SOF										(0x1u<<17)
#define	USB_INTS_ABORT_DONE										(0x1u<<18)
#define	USB_INTS_EP_STALL_NAK									(0x1u<<19)
#define	USB_INTS_RX_SHORT_PACKET								(0x1u<<20)
#define	USB_INTS_ENDPOINT_ERROR									(0x1u<<21)
#define	USB_INTS_DEV_SM_WATCHDOG_FIRED							(0x1u<<22)
#define	USB_INTS_EPX_STOPPED_ON_NAK								(0x1u<<23)

// SOF_TIMESTAMP_RAW Configuration

#define	USB_SOF_TIMESTAMP_RAW_SOF_TIMESTAMP_RAW					(0x1FFFFFu<<0)
#define	USB_SOF_TIMESTAMP_RAW_SOF_TIMESTAMP_RAW_0				(0x1u<<0)

// SOF_TIMESTAMP_LAST Configuration

#define	USB_SOF_TIMESTAMP_LAST_SOF_TIMESTAMP_LAST				(0x1FFFFFu<<0)
#define	USB_SOF_TIMESTAMP_LAST_SOF_TIMESTAMP_LAST_0				(0x1u<<0)

// SM_STATE Configuration

#define	USB_SM_STATE_STATE										(0x1Fu<<0)
#define	USB_SM_STATE_STATE_0									(0x1u<<0)
#define	USB_SM_STATE_BC_STATE									(0x7u<<5)
#define	USB_SM_STATE_BC_STATE_0									(0x1u<<5)
#define	USB_SM_STATE_RX_DASM									(0xFu<<8)
#define	USB_SM_STATE_RX_DASM_0									(0x1u<<8)

// EP_TX_ERROR Configuration

#define	USB_EP_TX_ERROR_EP0										(0x3u<<0)
#define	USB_EP_TX_ERROR_EP0_0									(0x1u<<0)
#define	USB_EP_TX_ERROR_EP1										(0x3u<<2)
#define	USB_EP_TX_ERROR_EP1_0									(0x1u<<2)
#define	USB_EP_TX_ERROR_EP2										(0x3u<<4)
#define	USB_EP_TX_ERROR_EP2_0									(0x1u<<4)
#define	USB_EP_TX_ERROR_EP3										(0x3u<<6)
#define	USB_EP_TX_ERROR_EP3_0									(0x1u<<6)
#define	USB_EP_TX_ERROR_EP4										(0x3u<<8)
#define	USB_EP_TX_ERROR_EP4_0									(0x1u<<8)
#define	USB_EP_TX_ERROR_EP5										(0x3u<<10)
#define	USB_EP_TX_ERROR_EP5_0									(0x1u<<10)
#define	USB_EP_TX_ERROR_EP6										(0x3u<<12)
#define	USB_EP_TX_ERROR_EP6_0									(0x1u<<12)
#define	USB_EP_TX_ERROR_EP7										(0x3u<<14)
#define	USB_EP_TX_ERROR_EP7_0									(0x1u<<14)
#define	USB_EP_TX_ERROR_EP8										(0x3u<<16)
#define	USB_EP_TX_ERROR_EP8_0									(0x1u<<16)
#define	USB_EP_TX_ERROR_EP9										(0x3u<<18)
#define	USB_EP_TX_ERROR_EP9_0									(0x1u<<18)
#define	USB_EP_TX_ERROR_EP10									(0x3u<<20)
#define	USB_EP_TX_ERROR_EP10_0									(0x1u<<20)
#define	USB_EP_TX_ERROR_EP11									(0x3u<<22)
#define	USB_EP_TX_ERROR_EP11_0									(0x1u<<22)
#define	USB_EP_TX_ERROR_EP12									(0x3u<<24)
#define	USB_EP_TX_ERROR_EP12_0									(0x1u<<24)
#define	USB_EP_TX_ERROR_EP13									(0x3u<<26)
#define	USB_EP_TX_ERROR_EP13_0									(0x1u<<26)
#define	USB_EP_TX_ERROR_EP14									(0x3u<<28)
#define	USB_EP_TX_ERROR_EP14_0									(0x1u<<28)
#define	USB_EP_TX_ERROR_EP15									(0x3u<<30)
#define	USB_EP_TX_ERROR_EP15_0									(0x1u<<30)

// EP_RX_ERROR Configuration

#define	USB_EP_RX_ERROR_EP0_TRANSACTION							(0x1u<<0)
#define	USB_EP_RX_ERROR_EP0_SEQ									(0x1u<<1)
#define	USB_EP_RX_ERROR_EP1_TRANSACTION							(0x1u<<2)
#define	USB_EP_RX_ERROR_EP1_SEQ									(0x1u<<3)
#define	USB_EP_RX_ERROR_EP2_TRANSACTION							(0x1u<<4)
#define	USB_EP_RX_ERROR_EP2_SEQ									(0x1u<<5)
#define	USB_EP_RX_ERROR_EP3_TRANSACTION							(0x1u<<6)
#define	USB_EP_RX_ERROR_EP3_SEQ									(0x1u<<7)
#define	USB_EP_RX_ERROR_EP4_TRANSACTION							(0x1u<<8)
#define	USB_EP_RX_ERROR_EP4_SEQ									(0x1u<<9)
#define	USB_EP_RX_ERROR_EP5_TRANSACTION							(0x1u<<10)
#define	USB_EP_RX_ERROR_EP5_SEQ									(0x1u<<11)
#define	USB_EP_RX_ERROR_EP6_TRANSACTION							(0x1u<<12)
#define	USB_EP_RX_ERROR_EP6_SEQ									(0x1u<<13)
#define	USB_EP_RX_ERROR_EP7_TRANSACTION							(0x1u<<14)
#define	USB_EP_RX_ERROR_EP7_SEQ									(0x1u<<15)
#define	USB_EP_RX_ERROR_EP8_TRANSACTION							(0x1u<<16)
#define	USB_EP_RX_ERROR_EP8_SEQ									(0x1u<<17)
#define	USB_EP_RX_ERROR_EP9_TRANSACTION							(0x1u<<18)
#define	USB_EP_RX_ERROR_EP9_SEQ									(0x1u<<19)
#define	USB_EP_RX_ERROR_EP10_TRANSACTION						(0x1u<<20)
#define	USB_EP_RX_ERROR_EP10_SEQ								(0x1u<<21)
#define	USB_EP_RX_ERROR_EP11_TRANSACTION						(0x1u<<22)
#define	USB_EP_RX_ERROR_EP11_SEQ								(0x1u<<23)
#define	USB_EP_RX_ERROR_EP12_TRANSACTION						(0x1u<<24)
#define	USB_EP_RX_ERROR_EP12_SEQ								(0x1u<<25)
#define	USB_EP_RX_ERROR_EP13_TRANSACTION						(0x1u<<26)
#define	USB_EP_RX_ERROR_EP13_SEQ								(0x1u<<27)
#define	USB_EP_RX_ERROR_EP14_TRANSACTION						(0x1u<<28)
#define	USB_EP_RX_ERROR_EP14_SEQ								(0x1u<<29)
#define	USB_EP_RX_ERROR_EP15_TRANSACTION						(0x1u<<30)
#define	USB_EP_RX_ERROR_EP15_SEQ								(0x1u<<31)

// DEV_SM_WATCHDOG Configuration

#define	USB_DEV_SM_WATCHDOG_LIMIT								(0x3FFFFu<<0)
#define	USB_DEV_SM_WATCHDOG_LIMIT_0								(0x1u<<0)
#define	USB_DEV_SM_WATCHDOG_ENABLE								(0x1u<<18)
#define	USB_DEV_SM_WATCHDOG_RESET								(0x1u<<19)
#define	USB_DEV_SM_WATCHDOG_FIRED								(0x1u<<20)
