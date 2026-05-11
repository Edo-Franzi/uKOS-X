/*
; tusb_config.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2019 Ha Thach (tinyusb.org)
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		TinyUSB configuration file.
;
;   (c) 2019 Ha Thach (tinyusb.org)
;   -------------------------------
;
;   The MIT License (MIT)
;
;   Permission is hereby granted, free of charge, to any person obtaining a copy
;   of this software and associated documentation files (the "Software"), to deal
;   in the Software without restriction, including without limitation the rights
;   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
;   copies of the Software, and to permit persons to whom the Software is
;   furnished to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be included in
;   all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
;   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
;   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
;   THE SOFTWARE.
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

#if (defined(__cplusplus))
extern	"C" {
#endif

// Board Specific Configuration
// ============================

#define	CFG_TUSB_MCU			OPT_MCU_STM32H7
#define	STM32H747xx				1
#define	CFG_TUSB_OS				OPT_OS_CUSTOM

#if (defined(SYSTEM_TINYUSB_HS_S))
#undef	BOARD_TUD_RHPORT
#undef	CFG_TUD_MAX_SPEED
#define	BOARD_TUD_RHPORT		1
#define	CFG_TUD_MAX_SPEED		OPT_MODE_HIGH_SPEED

#undef	CFG_TUD_CDC_RX_BUFSIZE
#undef	CFG_TUD_CDC_TX_BUFSIZE
#undef	CFG_TUD_CDC_EP_BUFSIZE
#define	CFG_TUD_CDC_RX_BUFSIZE	4096
#define	CFG_TUD_CDC_TX_BUFSIZE	4096
#define	CFG_TUD_CDC_EP_BUFSIZE	512
#endif

#if (defined(SYSTEM_TINYUSB_FS_S))
#undef	BOARD_TUD_RHPORT
#undef	CFG_TUD_MAX_SPEED
#define	BOARD_TUD_RHPORT		0
#define	CFG_TUD_MAX_SPEED		OPT_MODE_FULL_SPEED

#undef	CFG_TUD_CDC_RX_BUFSIZE
#undef	CFG_TUD_CDC_TX_BUFSIZE
#undef	CFG_TUD_CDC_EP_BUFSIZE
#define	CFG_TUD_CDC_RX_BUFSIZE	64
#define	CFG_TUD_CDC_TX_BUFSIZE	64
#define	CFG_TUD_CDC_EP_BUFSIZE	64
#endif

// Common Configuration
// ====================

#define	CFG_TUSB_DEBUG			0
#define	CFG_TUD_ENABLED			1

// USB DMA on some MCUs can only access a specific SRAM region with restriction on alignment.
// TinyUSB use follows macros to declare transferring memory so that they can be put
// into those specific section.
// e.g
// - CFG_TUSB_MEM SECTION : [[gnu::section(".usb_ram")]]
// - CFG_TUSB_MEM_ALIGN   : [[gnu::aligned(4)]]

#if (!defined(CFG_TUSB_MEM_SECTION))
#define	CFG_TUSB_MEM_SECTION
#endif

#if (!defined(CFG_TUSB_MEM_ALIGN))
#define	CFG_TUSB_MEM_ALIGN		[[gnu::aligned(32)]]
#endif

// Device Configuration
// ====================

#if (!defined(CFG_TUD_ENDPOINT0_SIZE))
#define	CFG_TUD_ENDPOINT0_SIZE	64
#endif

// Class

#define	CFG_TUD_CDC				2
#define	CFG_TUD_MSC				0
#define	CFG_TUD_HID				0
#define	CFG_TUD_MIDI			0
#define	CFG_TUD_VENDOR			0
#define	CFG_TUD_VIDEO			0

#if (defined(__cplusplus))
}
#endif
