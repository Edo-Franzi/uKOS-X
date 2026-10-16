/*
; nrf5340_network_ficr.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_ficr equates.
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

// FICR address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[128];
	volatile	uint32_t	INFO_CONFIGID;
	volatile	uint32_t	INFO_DEVICEID[2];
	volatile	uint32_t	INFO_PART;
	volatile	uint32_t	INFO_VARIANT;
	volatile	uint32_t	INFO_PACKAGE;
	volatile	uint32_t	INFO_RAM;
	volatile	uint32_t	INFO_FLASH;
	volatile	uint32_t	INFO_CODEPAGESIZE;
	volatile	uint32_t	INFO_CODESIZE;
	volatile	uint32_t	INFO_DEVICETYPE;
	volatile	uint32_t	RESERVED1[21];
	volatile	uint32_t	ER[4];
	volatile	uint32_t	IR[4];
	volatile	uint32_t	DEVICEADDRTYPE;
	volatile	uint32_t	DEVICEADDR[2];
	volatile	uint32_t	RESERVED2[21];
	volatile	uint32_t	TRIMCNF0_ADDR;
	volatile	uint32_t	TRIMCNF0_DATA;
	volatile	uint32_t	TRIMCNF1_ADDR;
	volatile	uint32_t	TRIMCNF1_DATA;
	volatile	uint32_t	TRIMCNF2_ADDR;
	volatile	uint32_t	TRIMCNF2_DATA;
	volatile	uint32_t	TRIMCNF3_ADDR;
	volatile	uint32_t	TRIMCNF3_DATA;
	volatile	uint32_t	TRIMCNF4_ADDR;
	volatile	uint32_t	TRIMCNF4_DATA;
	volatile	uint32_t	TRIMCNF5_ADDR;
	volatile	uint32_t	TRIMCNF5_DATA;
	volatile	uint32_t	TRIMCNF6_ADDR;
	volatile	uint32_t	TRIMCNF6_DATA;
	volatile	uint32_t	TRIMCNF7_ADDR;
	volatile	uint32_t	TRIMCNF7_DATA;
	volatile	uint32_t	TRIMCNF8_ADDR;
	volatile	uint32_t	TRIMCNF8_DATA;
	volatile	uint32_t	TRIMCNF9_ADDR;
	volatile	uint32_t	TRIMCNF9_DATA;
	volatile	uint32_t	TRIMCNF10_ADDR;
	volatile	uint32_t	TRIMCNF10_DATA;
	volatile	uint32_t	TRIMCNF11_ADDR;
	volatile	uint32_t	TRIMCNF11_DATA;
	volatile	uint32_t	TRIMCNF12_ADDR;
	volatile	uint32_t	TRIMCNF12_DATA;
	volatile	uint32_t	TRIMCNF13_ADDR;
	volatile	uint32_t	TRIMCNF13_DATA;
	volatile	uint32_t	TRIMCNF14_ADDR;
	volatile	uint32_t	TRIMCNF14_DATA;
	volatile	uint32_t	TRIMCNF15_ADDR;
	volatile	uint32_t	TRIMCNF15_DATA;
	volatile	uint32_t	TRIMCNF16_ADDR;
	volatile	uint32_t	TRIMCNF16_DATA;
	volatile	uint32_t	TRIMCNF17_ADDR;
	volatile	uint32_t	TRIMCNF17_DATA;
	volatile	uint32_t	TRIMCNF18_ADDR;
	volatile	uint32_t	TRIMCNF18_DATA;
	volatile	uint32_t	TRIMCNF19_ADDR;
	volatile	uint32_t	TRIMCNF19_DATA;
	volatile	uint32_t	TRIMCNF20_ADDR;
	volatile	uint32_t	TRIMCNF20_DATA;
	volatile	uint32_t	TRIMCNF21_ADDR;
	volatile	uint32_t	TRIMCNF21_DATA;
	volatile	uint32_t	TRIMCNF22_ADDR;
	volatile	uint32_t	TRIMCNF22_DATA;
	volatile	uint32_t	TRIMCNF23_ADDR;
	volatile	uint32_t	TRIMCNF23_DATA;
	volatile	uint32_t	TRIMCNF24_ADDR;
	volatile	uint32_t	TRIMCNF24_DATA;
	volatile	uint32_t	TRIMCNF25_ADDR;
	volatile	uint32_t	TRIMCNF25_DATA;
	volatile	uint32_t	TRIMCNF26_ADDR;
	volatile	uint32_t	TRIMCNF26_DATA;
	volatile	uint32_t	TRIMCNF27_ADDR;
	volatile	uint32_t	TRIMCNF27_DATA;
	volatile	uint32_t	TRIMCNF28_ADDR;
	volatile	uint32_t	TRIMCNF28_DATA;
	volatile	uint32_t	TRIMCNF29_ADDR;
	volatile	uint32_t	TRIMCNF29_DATA;
	volatile	uint32_t	TRIMCNF30_ADDR;
	volatile	uint32_t	TRIMCNF30_DATA;
	volatile	uint32_t	TRIMCNF31_ADDR;
	volatile	uint32_t	TRIMCNF31_DATA;
} FICR_TypeDef;

#if (defined(__cplusplus))
#define	FICR_NS	reinterpret_cast<FICR_TypeDef *>(0x01FF0000u)

#else
#define	FICR_NS	((FICR_TypeDef *)0x01FF0000u)
#endif

// CONFIGID Configuration

#define	FICR_INFO_CONFIGID_HWID							(0xFFFFu<<0)
#define	FICR_INFO_CONFIGID_HWID_0						(0x1u<<0)

// DEVICEID Configuration

#define	FICR_INFO_DEVICEID_DEVICEID						(0xFFFFFFFFu<<0)
#define	FICR_INFO_DEVICEID_DEVICEID_0					(0x1u<<0)

// PART Configuration

#define	FICR_INFO_PART_PART								(0xFFFFFFFFu<<0)
#define	FICR_INFO_PART_PART_0							(0x1u<<0)
#define	FICR_INFO_PART_PART_N5340						(0x5340u<<0)
#define	FICR_INFO_PART_PART_UNSPECIFIED					(0xFFFFFFFFu<<0)

// VARIANT Configuration

#define	FICR_INFO_VARIANT_VARIANT						(0xFFFFFFFFu<<0)
#define	FICR_INFO_VARIANT_VARIANT_0						(0x1u<<0)
#define	FICR_INFO_VARIANT_VARIANT_QKAA					(0x514B4141u<<0)
#define	FICR_INFO_VARIANT_VARIANT_CLAA					(0x434C4141u<<0)
#define	FICR_INFO_VARIANT_VARIANT_UNSPECIFIED			(0xFFFFFFFFu<<0)

// PACKAGE Configuration

#define	FICR_INFO_PACKAGE_PACKAGE						(0xFFFFFFFFu<<0)
#define	FICR_INFO_PACKAGE_PACKAGE_0						(0x1u<<0)
#define	FICR_INFO_PACKAGE_PACKAGE_QK					(0x2000u<<0)
#define	FICR_INFO_PACKAGE_PACKAGE_CL					(0x2005u<<0)
#define	FICR_INFO_PACKAGE_PACKAGE_UNSPECIFIED			(0xFFFFFFFFu<<0)

// RAM Configuration

#define	FICR_INFO_RAM_RAM								(0xFFFFFFFFu<<0)
#define	FICR_INFO_RAM_RAM_0								(0x1u<<0)
#define	FICR_INFO_RAM_RAM_K16							(0x10u<<0)
#define	FICR_INFO_RAM_RAM_K32							(0x20u<<0)
#define	FICR_INFO_RAM_RAM_K64							(0x40u<<0)
#define	FICR_INFO_RAM_RAM_K128							(0x80u<<0)
#define	FICR_INFO_RAM_RAM_K256							(0x100u<<0)
#define	FICR_INFO_RAM_RAM_K512							(0x200u<<0)
#define	FICR_INFO_RAM_RAM_UNSPECIFIED					(0xFFFFFFFFu<<0)

// FLASH Configuration

#define	FICR_INFO_FLASH_FLASH							(0xFFFFFFFFu<<0)
#define	FICR_INFO_FLASH_FLASH_0							(0x1u<<0)
#define	FICR_INFO_FLASH_FLASH_K128						(0x80u<<0)
#define	FICR_INFO_FLASH_FLASH_K256						(0x100u<<0)
#define	FICR_INFO_FLASH_FLASH_K512						(0x200u<<0)
#define	FICR_INFO_FLASH_FLASH_K1024						(0x400u<<0)
#define	FICR_INFO_FLASH_FLASH_K2048						(0x800u<<0)
#define	FICR_INFO_FLASH_FLASH_UNSPECIFIED				(0xFFFFFFFFu<<0)

// CODEPAGESIZE Configuration

#define	FICR_INFO_CODEPAGESIZE_CODEPAGESIZE				(0xFFFFFFFFu<<0)
#define	FICR_INFO_CODEPAGESIZE_CODEPAGESIZE_0			(0x1u<<0)
#define	FICR_INFO_CODEPAGESIZE_CODEPAGESIZE_K2048		(0x800u<<0)

// CODESIZE Configuration

#define	FICR_INFO_CODESIZE_CODESIZE						(0xFFFFFFFFu<<0)
#define	FICR_INFO_CODESIZE_CODESIZE_0					(0x1u<<0)
#define	FICR_INFO_CODESIZE_CODESIZE_P128				(0x80u<<0)

// DEVICETYPE Configuration

#define	FICR_INFO_DEVICETYPE_DEVICETYPE					(0xFFFFFFFFu<<0)
#define	FICR_INFO_DEVICETYPE_DEVICETYPE_0				(0x1u<<0)
#define	FICR_INFO_DEVICETYPE_DEVICETYPE_DIE				(0x0u<<0)
#define	FICR_INFO_DEVICETYPE_DEVICETYPE_FPGA			(0xFFFFFFFFu<<0)

// ER Configuration

#define	FICR_ER_ER										(0xFFFFFFFFu<<0)
#define	FICR_ER_ER_0									(0x1u<<0)

// IR Configuration

#define	FICR_IR_IR										(0xFFFFFFFFu<<0)
#define	FICR_IR_IR_0									(0x1u<<0)

// DEVICEADDRTYPE Configuration

#define	FICR_DEVICEADDRTYPE_DEVICEADDRTYPE				(0x1u<<0)
#define	FICR_DEVICEADDRTYPE_DEVICEADDRTYPE_PUBLIC		(0x0u<<0)
#define	FICR_DEVICEADDRTYPE_DEVICEADDRTYPE_RANDOM		(0x1u<<0)

// DEVICEADDR Configuration

#define	FICR_DEVICEADDR_DEVICEADDR						(0xFFFFFFFFu<<0)
#define	FICR_DEVICEADDR_DEVICEADDR_0					(0x1u<<0)

// ADDR Configuration

#define	FICR_TRIMCNF_ADDR_ADDRESS						(0xFFFFFFFFu<<0)
#define	FICR_TRIMCNF_ADDR_ADDRESS_0						(0x1u<<0)

// DATA Configuration

#define	FICR_TRIMCNF_DATA_DATA							(0xFFFFFFFFu<<0)
#define	FICR_TRIMCNF_DATA_DATA_0						(0x1u<<0)
