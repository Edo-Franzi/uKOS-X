/*
; RP2350_otp_data.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_otp_data equates.
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

// OTP_DATA address definitions
// ----------------------------

typedef struct {
	volatile	uint16_t	CHIPID0;
	volatile	uint16_t	CHIPID1;
	volatile	uint16_t	CHIPID2;
	volatile	uint16_t	CHIPID3;
	volatile	uint16_t	RANDID0;
	volatile	uint16_t	RANDID1;
	volatile	uint16_t	RANDID2;
	volatile	uint16_t	RANDID3;
	volatile	uint16_t	RANDID4;
	volatile	uint16_t	RANDID5;
	volatile	uint16_t	RANDID6;
	volatile	uint16_t	RANDID7;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint16_t	ROSC_CALIB;
	volatile	uint16_t	LPOSC_CALIB;
	volatile	uint32_t	RESERVED1[3];
	volatile	uint16_t	NUM_GPIOS;
	volatile	uint16_t	RESERVED2[29];
	volatile	uint16_t	INFO_CRC0;
	volatile	uint16_t	INFO_CRC1;
	volatile	uint32_t	RESERVED3[14];
	volatile	uint16_t	FLASH_DEVINFO;
	volatile	uint16_t	FLASH_PARTITION_SLOT_SIZE;
	volatile	uint16_t	BOOTSEL_LED_CFG;
	volatile	uint16_t	BOOTSEL_PLL_CFG;
	volatile	uint16_t	BOOTSEL_XOSC_CFG;
	volatile	uint16_t	RESERVED4[3];
	volatile	uint16_t	USB_WHITE_LABEL_ADDR;
	volatile	uint16_t	RESERVED5;
	volatile	uint16_t	OTPBOOT_SRC;
	volatile	uint16_t	OTPBOOT_LEN;
	volatile	uint16_t	OTPBOOT_DST0;
	volatile	uint16_t	OTPBOOT_DST1;
	volatile	uint32_t	RESERVED6[15];
	volatile	uint16_t	BOOTKEY0_0;
	volatile	uint16_t	BOOTKEY0_1;
	volatile	uint16_t	BOOTKEY0_2;
	volatile	uint16_t	BOOTKEY0_3;
	volatile	uint16_t	BOOTKEY0_4;
	volatile	uint16_t	BOOTKEY0_5;
	volatile	uint16_t	BOOTKEY0_6;
	volatile	uint16_t	BOOTKEY0_7;
	volatile	uint16_t	BOOTKEY0_8;
	volatile	uint16_t	BOOTKEY0_9;
	volatile	uint16_t	BOOTKEY0_10;
	volatile	uint16_t	BOOTKEY0_11;
	volatile	uint16_t	BOOTKEY0_12;
	volatile	uint16_t	BOOTKEY0_13;
	volatile	uint16_t	BOOTKEY0_14;
	volatile	uint16_t	BOOTKEY0_15;
	volatile	uint16_t	BOOTKEY1_0;
	volatile	uint16_t	BOOTKEY1_1;
	volatile	uint16_t	BOOTKEY1_2;
	volatile	uint16_t	BOOTKEY1_3;
	volatile	uint16_t	BOOTKEY1_4;
	volatile	uint16_t	BOOTKEY1_5;
	volatile	uint16_t	BOOTKEY1_6;
	volatile	uint16_t	BOOTKEY1_7;
	volatile	uint16_t	BOOTKEY1_8;
	volatile	uint16_t	BOOTKEY1_9;
	volatile	uint16_t	BOOTKEY1_10;
	volatile	uint16_t	BOOTKEY1_11;
	volatile	uint16_t	BOOTKEY1_12;
	volatile	uint16_t	BOOTKEY1_13;
	volatile	uint16_t	BOOTKEY1_14;
	volatile	uint16_t	BOOTKEY1_15;
	volatile	uint16_t	BOOTKEY2_0;
	volatile	uint16_t	BOOTKEY2_1;
	volatile	uint16_t	BOOTKEY2_2;
	volatile	uint16_t	BOOTKEY2_3;
	volatile	uint16_t	BOOTKEY2_4;
	volatile	uint16_t	BOOTKEY2_5;
	volatile	uint16_t	BOOTKEY2_6;
	volatile	uint16_t	BOOTKEY2_7;
	volatile	uint16_t	BOOTKEY2_8;
	volatile	uint16_t	BOOTKEY2_9;
	volatile	uint16_t	BOOTKEY2_10;
	volatile	uint16_t	BOOTKEY2_11;
	volatile	uint16_t	BOOTKEY2_12;
	volatile	uint16_t	BOOTKEY2_13;
	volatile	uint16_t	BOOTKEY2_14;
	volatile	uint16_t	BOOTKEY2_15;
	volatile	uint16_t	BOOTKEY3_0;
	volatile	uint16_t	BOOTKEY3_1;
	volatile	uint16_t	BOOTKEY3_2;
	volatile	uint16_t	BOOTKEY3_3;
	volatile	uint16_t	BOOTKEY3_4;
	volatile	uint16_t	BOOTKEY3_5;
	volatile	uint16_t	BOOTKEY3_6;
	volatile	uint16_t	BOOTKEY3_7;
	volatile	uint16_t	BOOTKEY3_8;
	volatile	uint16_t	BOOTKEY3_9;
	volatile	uint16_t	BOOTKEY3_10;
	volatile	uint16_t	BOOTKEY3_11;
	volatile	uint16_t	BOOTKEY3_12;
	volatile	uint16_t	BOOTKEY3_13;
	volatile	uint16_t	BOOTKEY3_14;
	volatile	uint16_t	BOOTKEY3_15;
	volatile	uint32_t	RESERVED7[1860];
	volatile	uint16_t	KEY1_0;
	volatile	uint16_t	KEY1_1;
	volatile	uint16_t	KEY1_2;
	volatile	uint16_t	KEY1_3;
	volatile	uint16_t	KEY1_4;
	volatile	uint16_t	KEY1_5;
	volatile	uint16_t	KEY1_6;
	volatile	uint16_t	KEY1_7;
	volatile	uint16_t	KEY2_0;
	volatile	uint16_t	KEY2_1;
	volatile	uint16_t	KEY2_2;
	volatile	uint16_t	KEY2_3;
	volatile	uint16_t	KEY2_4;
	volatile	uint16_t	KEY2_5;
	volatile	uint16_t	KEY2_6;
	volatile	uint16_t	KEY2_7;
	volatile	uint16_t	KEY3_0;
	volatile	uint16_t	KEY3_1;
	volatile	uint16_t	KEY3_2;
	volatile	uint16_t	KEY3_3;
	volatile	uint16_t	KEY3_4;
	volatile	uint16_t	KEY3_5;
	volatile	uint16_t	KEY3_6;
	volatile	uint16_t	KEY3_7;
	volatile	uint16_t	KEY4_0;
	volatile	uint16_t	KEY4_1;
	volatile	uint16_t	KEY4_2;
	volatile	uint16_t	KEY4_3;
	volatile	uint16_t	KEY4_4;
	volatile	uint16_t	KEY4_5;
	volatile	uint16_t	KEY4_6;
	volatile	uint16_t	KEY4_7;
	volatile	uint16_t	KEY5_0;
	volatile	uint16_t	KEY5_1;
	volatile	uint16_t	KEY5_2;
	volatile	uint16_t	KEY5_3;
	volatile	uint16_t	KEY5_4;
	volatile	uint16_t	KEY5_5;
	volatile	uint16_t	KEY5_6;
	volatile	uint16_t	KEY5_7;
	volatile	uint16_t	KEY6_0;
	volatile	uint16_t	KEY6_1;
	volatile	uint16_t	KEY6_2;
	volatile	uint16_t	KEY6_3;
	volatile	uint16_t	KEY6_4;
	volatile	uint16_t	KEY6_5;
	volatile	uint16_t	KEY6_6;
	volatile	uint16_t	KEY6_7;
} OTP_DATA_TypeDef;

#ifdef __cplusplus
#define	OTP_DATA_NS	reinterpret_cast<OTP_DATA_TypeDef *>(0x40130000u)
#define	OTP_DATA_S	reinterpret_cast<OTP_DATA_TypeDef *>(0x40130000u)
#else
#define	OTP_DATA_NS	((OTP_DATA_TypeDef *)0x40130000u)
#define	OTP_DATA_S	((OTP_DATA_TypeDef *)0x40130000u)
#endif

// CHIPID0 Configuration

#define	OTP_DATA_CHIPID0_CHIPID0																			(0xFFFFu<<0)
#define	OTP_DATA_CHIPID0_CHIPID0_0																			(0x1u<<0)

// CHIPID1 Configuration

#define	OTP_DATA_CHIPID1_CHIPID1																			(0xFFFFu<<0)
#define	OTP_DATA_CHIPID1_CHIPID1_0																			(0x1u<<0)

// CHIPID2 Configuration

#define	OTP_DATA_CHIPID2_CHIPID2																			(0xFFFFu<<0)
#define	OTP_DATA_CHIPID2_CHIPID2_0																			(0x1u<<0)

// CHIPID3 Configuration

#define	OTP_DATA_CHIPID3_CHIPID3																			(0xFFFFu<<0)
#define	OTP_DATA_CHIPID3_CHIPID3_0																			(0x1u<<0)

// RANDID0 Configuration

#define	OTP_DATA_RANDID0_RANDID0																			(0xFFFFu<<0)
#define	OTP_DATA_RANDID0_RANDID0_0																			(0x1u<<0)

// RANDID1 Configuration

#define	OTP_DATA_RANDID1_RANDID1																			(0xFFFFu<<0)
#define	OTP_DATA_RANDID1_RANDID1_0																			(0x1u<<0)

// RANDID2 Configuration

#define	OTP_DATA_RANDID2_RANDID2																			(0xFFFFu<<0)
#define	OTP_DATA_RANDID2_RANDID2_0																			(0x1u<<0)

// RANDID3 Configuration

#define	OTP_DATA_RANDID3_RANDID3																			(0xFFFFu<<0)
#define	OTP_DATA_RANDID3_RANDID3_0																			(0x1u<<0)

// RANDID4 Configuration

#define	OTP_DATA_RANDID4_RANDID4																			(0xFFFFu<<0)
#define	OTP_DATA_RANDID4_RANDID4_0																			(0x1u<<0)

// RANDID5 Configuration

#define	OTP_DATA_RANDID5_RANDID5																			(0xFFFFu<<0)
#define	OTP_DATA_RANDID5_RANDID5_0																			(0x1u<<0)

// RANDID6 Configuration

#define	OTP_DATA_RANDID6_RANDID6																			(0xFFFFu<<0)
#define	OTP_DATA_RANDID6_RANDID6_0																			(0x1u<<0)

// RANDID7 Configuration

#define	OTP_DATA_RANDID7_RANDID7																			(0xFFFFu<<0)
#define	OTP_DATA_RANDID7_RANDID7_0																			(0x1u<<0)

// ROSC_CALIB Configuration

#define	OTP_DATA_ROSC_CALIB_ROSC_CALIB																		(0xFFFFu<<0)
#define	OTP_DATA_ROSC_CALIB_ROSC_CALIB_0																	(0x1u<<0)

// LPOSC_CALIB Configuration

#define	OTP_DATA_LPOSC_CALIB_LPOSC_CALIB																	(0xFFFFu<<0)
#define	OTP_DATA_LPOSC_CALIB_LPOSC_CALIB_0																	(0x1u<<0)

// NUM_GPIOS Configuration

#define	OTP_DATA_NUM_GPIOS_NUM_GPIOS																		(0xFFu<<0)
#define	OTP_DATA_NUM_GPIOS_NUM_GPIOS_0																		(0x1u<<0)

// INFO_CRC0 Configuration

#define	OTP_DATA_INFO_CRC0_INFO_CRC0																		(0xFFFFu<<0)
#define	OTP_DATA_INFO_CRC0_INFO_CRC0_0																		(0x1u<<0)

// INFO_CRC1 Configuration

#define	OTP_DATA_INFO_CRC1_INFO_CRC1																		(0xFFFFu<<0)
#define	OTP_DATA_INFO_CRC1_INFO_CRC1_0																		(0x1u<<0)

// FLASH_DEVINFO Configuration

#define	OTP_DATA_FLASH_DEVINFO_CS1_GPIO																		(0x3Fu<<0)
#define	OTP_DATA_FLASH_DEVINFO_CS1_GPIO_0																	(0x1u<<0)
#define	OTP_DATA_FLASH_DEVINFO_D8H_ERASE_SUPPORTED															(0x1u<<7)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE																		(0xFu<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_0																	(0x1u<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE																		(0xFu<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_0																	(0x1u<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_NONE																(0x0u<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_8K																	(0x1u<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_16K																	(0x2u<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_32K																	(0x3u<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_64K																	(0x4u<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_128K																(0x5u<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_256K																(0x6u<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_512K																(0x7u<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_1M																	(0x8u<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_2M																	(0x9u<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_4M																	(0xAu<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_8M																	(0xBu<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS0_SIZE_16M																	(0xCu<<8)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_NONE																(0x0u<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_8K																	(0x1u<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_16K																	(0x2u<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_32K																	(0x3u<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_64K																	(0x4u<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_128K																(0x5u<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_256K																(0x6u<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_512K																(0x7u<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_1M																	(0x8u<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_2M																	(0x9u<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_4M																	(0xAu<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_8M																	(0xBu<<12)
#define	OTP_DATA_FLASH_DEVINFO_CS1_SIZE_16M																	(0xCu<<12)

// FLASH_PARTITION_SLOT_SIZE Configuration

#define	OTP_DATA_FLASH_PARTITION_SLOT_SIZE_FLASH_PARTITION_SLOT_SIZE										(0xFFFFu<<0)
#define	OTP_DATA_FLASH_PARTITION_SLOT_SIZE_FLASH_PARTITION_SLOT_SIZE_0										(0x1u<<0)

// BOOTSEL_LED_CFG Configuration

#define	OTP_DATA_BOOTSEL_LED_CFG_PIN																		(0x3Fu<<0)
#define	OTP_DATA_BOOTSEL_LED_CFG_PIN_0																		(0x1u<<0)
#define	OTP_DATA_BOOTSEL_LED_CFG_ACTIVELOW																	(0x1u<<8)

// BOOTSEL_PLL_CFG Configuration

#define	OTP_DATA_BOOTSEL_PLL_CFG_FBDIV																		(0x1FFu<<0)
#define	OTP_DATA_BOOTSEL_PLL_CFG_FBDIV_0																	(0x1u<<0)
#define	OTP_DATA_BOOTSEL_PLL_CFG_POSTDIV1																	(0x7u<<9)
#define	OTP_DATA_BOOTSEL_PLL_CFG_POSTDIV1_0																	(0x1u<<9)
#define	OTP_DATA_BOOTSEL_PLL_CFG_POSTDIV2																	(0x7u<<12)
#define	OTP_DATA_BOOTSEL_PLL_CFG_POSTDIV2_0																	(0x1u<<12)
#define	OTP_DATA_BOOTSEL_PLL_CFG_REFDIV																		(0x1u<<15)

// BOOTSEL_XOSC_CFG Configuration

#define	OTP_DATA_BOOTSEL_XOSC_CFG_STARTUP																	(0x3FFFu<<0)
#define	OTP_DATA_BOOTSEL_XOSC_CFG_STARTUP_0																	(0x1u<<0)
#define	OTP_DATA_BOOTSEL_XOSC_CFG_RANGE																		(0x3u<<14)
#define	OTP_DATA_BOOTSEL_XOSC_CFG_RANGE_0																	(0x1u<<14)
#define	OTP_DATA_BOOTSEL_XOSC_CFG_RANGE_1_15MHZ																(0x0u<<14)
#define	OTP_DATA_BOOTSEL_XOSC_CFG_RANGE_10_30MHZ															(0x1u<<14)
#define	OTP_DATA_BOOTSEL_XOSC_CFG_RANGE_25_60MHZ															(0x2u<<14)
#define	OTP_DATA_BOOTSEL_XOSC_CFG_RANGE_40_100MHZ															(0x3u<<14)

// USB_WHITE_LABEL_ADDR Configuration

#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR													(0xFFFFu<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_0												(0x1u<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_VID_VALUE						(0x0u<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_PID_VALUE						(0x1u<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_BCD_DEVICE_VALUE				(0x2u<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_LANG_ID_VALUE					(0x3u<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_MANUFACTURER_STRDEF				(0x4u<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_PRODUCT_STRDEF					(0x5u<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_DEVICE_SERIAL_NUMBER_STRDEF			(0x6u<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_USB_CONFIG_ATTRIBUTES_MAX_POWER_VALUES		(0x7u<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_VOLUME_LABEL_STRDEF						(0x8u<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_SCSI_INQUIRY_VENDOR_STRDEF					(0x9u<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_SCSI_INQUIRY_PRODUCT_STRDEF				(0xAu<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_SCSI_INQUIRY_VERSION_STRDEF				(0xBu<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_INDEX_HTM_REDIRECT_URL_STRDEF				(0xCu<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_INDEX_HTM_REDIRECT_NAME_STRDEF				(0xDu<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_INFO_UF2_TXT_MODEL_STRDEF					(0xEu<<0)
#define	OTP_DATA_USB_WHITE_LABEL_ADDR_USB_WHITE_LABEL_ADDR_INDEX_INFO_UF2_TXT_BOARD_ID_STRDEF				(0xFu<<0)

// OTPBOOT_SRC Configuration

#define	OTP_DATA_OTPBOOT_SRC_OTPBOOT_SRC																	(0xFFFFu<<0)
#define	OTP_DATA_OTPBOOT_SRC_OTPBOOT_SRC_0																	(0x1u<<0)

// OTPBOOT_LEN Configuration

#define	OTP_DATA_OTPBOOT_LEN_OTPBOOT_LEN																	(0xFFFFu<<0)
#define	OTP_DATA_OTPBOOT_LEN_OTPBOOT_LEN_0																	(0x1u<<0)

// OTPBOOT_DST0 Configuration

#define	OTP_DATA_OTPBOOT_DST0_OTPBOOT_DST0																	(0xFFFFu<<0)
#define	OTP_DATA_OTPBOOT_DST0_OTPBOOT_DST0_0																(0x1u<<0)

// OTPBOOT_DST1 Configuration

#define	OTP_DATA_OTPBOOT_DST1_OTPBOOT_DST1																	(0xFFFFu<<0)
#define	OTP_DATA_OTPBOOT_DST1_OTPBOOT_DST1_0																(0x1u<<0)

// BOOTKEY0_0 Configuration

#define	OTP_DATA_BOOTKEY0_0_BOOTKEY0_0																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_0_BOOTKEY0_0_0																	(0x1u<<0)

// BOOTKEY0_1 Configuration

#define	OTP_DATA_BOOTKEY0_1_BOOTKEY0_1																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_1_BOOTKEY0_1_0																	(0x1u<<0)

// BOOTKEY0_2 Configuration

#define	OTP_DATA_BOOTKEY0_2_BOOTKEY0_2																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_2_BOOTKEY0_2_0																	(0x1u<<0)

// BOOTKEY0_3 Configuration

#define	OTP_DATA_BOOTKEY0_3_BOOTKEY0_3																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_3_BOOTKEY0_3_0																	(0x1u<<0)

// BOOTKEY0_4 Configuration

#define	OTP_DATA_BOOTKEY0_4_BOOTKEY0_4																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_4_BOOTKEY0_4_0																	(0x1u<<0)

// BOOTKEY0_5 Configuration

#define	OTP_DATA_BOOTKEY0_5_BOOTKEY0_5																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_5_BOOTKEY0_5_0																	(0x1u<<0)

// BOOTKEY0_6 Configuration

#define	OTP_DATA_BOOTKEY0_6_BOOTKEY0_6																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_6_BOOTKEY0_6_0																	(0x1u<<0)

// BOOTKEY0_7 Configuration

#define	OTP_DATA_BOOTKEY0_7_BOOTKEY0_7																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_7_BOOTKEY0_7_0																	(0x1u<<0)

// BOOTKEY0_8 Configuration

#define	OTP_DATA_BOOTKEY0_8_BOOTKEY0_8																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_8_BOOTKEY0_8_0																	(0x1u<<0)

// BOOTKEY0_9 Configuration

#define	OTP_DATA_BOOTKEY0_9_BOOTKEY0_9																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_9_BOOTKEY0_9_0																	(0x1u<<0)

// BOOTKEY0_10 Configuration

#define	OTP_DATA_BOOTKEY0_10_BOOTKEY0_10																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_10_BOOTKEY0_10_0																	(0x1u<<0)

// BOOTKEY0_11 Configuration

#define	OTP_DATA_BOOTKEY0_11_BOOTKEY0_11																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_11_BOOTKEY0_11_0																	(0x1u<<0)

// BOOTKEY0_12 Configuration

#define	OTP_DATA_BOOTKEY0_12_BOOTKEY0_12																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_12_BOOTKEY0_12_0																	(0x1u<<0)

// BOOTKEY0_13 Configuration

#define	OTP_DATA_BOOTKEY0_13_BOOTKEY0_13																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_13_BOOTKEY0_13_0																	(0x1u<<0)

// BOOTKEY0_14 Configuration

#define	OTP_DATA_BOOTKEY0_14_BOOTKEY0_14																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_14_BOOTKEY0_14_0																	(0x1u<<0)

// BOOTKEY0_15 Configuration

#define	OTP_DATA_BOOTKEY0_15_BOOTKEY0_15																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY0_15_BOOTKEY0_15_0																	(0x1u<<0)

// BOOTKEY1_0 Configuration

#define	OTP_DATA_BOOTKEY1_0_BOOTKEY1_0																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_0_BOOTKEY1_0_0																	(0x1u<<0)

// BOOTKEY1_1 Configuration

#define	OTP_DATA_BOOTKEY1_1_BOOTKEY1_1																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_1_BOOTKEY1_1_0																	(0x1u<<0)

// BOOTKEY1_2 Configuration

#define	OTP_DATA_BOOTKEY1_2_BOOTKEY1_2																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_2_BOOTKEY1_2_0																	(0x1u<<0)

// BOOTKEY1_3 Configuration

#define	OTP_DATA_BOOTKEY1_3_BOOTKEY1_3																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_3_BOOTKEY1_3_0																	(0x1u<<0)

// BOOTKEY1_4 Configuration

#define	OTP_DATA_BOOTKEY1_4_BOOTKEY1_4																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_4_BOOTKEY1_4_0																	(0x1u<<0)

// BOOTKEY1_5 Configuration

#define	OTP_DATA_BOOTKEY1_5_BOOTKEY1_5																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_5_BOOTKEY1_5_0																	(0x1u<<0)

// BOOTKEY1_6 Configuration

#define	OTP_DATA_BOOTKEY1_6_BOOTKEY1_6																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_6_BOOTKEY1_6_0																	(0x1u<<0)

// BOOTKEY1_7 Configuration

#define	OTP_DATA_BOOTKEY1_7_BOOTKEY1_7																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_7_BOOTKEY1_7_0																	(0x1u<<0)

// BOOTKEY1_8 Configuration

#define	OTP_DATA_BOOTKEY1_8_BOOTKEY1_8																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_8_BOOTKEY1_8_0																	(0x1u<<0)

// BOOTKEY1_9 Configuration

#define	OTP_DATA_BOOTKEY1_9_BOOTKEY1_9																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_9_BOOTKEY1_9_0																	(0x1u<<0)

// BOOTKEY1_10 Configuration

#define	OTP_DATA_BOOTKEY1_10_BOOTKEY1_10																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_10_BOOTKEY1_10_0																	(0x1u<<0)

// BOOTKEY1_11 Configuration

#define	OTP_DATA_BOOTKEY1_11_BOOTKEY1_11																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_11_BOOTKEY1_11_0																	(0x1u<<0)

// BOOTKEY1_12 Configuration

#define	OTP_DATA_BOOTKEY1_12_BOOTKEY1_12																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_12_BOOTKEY1_12_0																	(0x1u<<0)

// BOOTKEY1_13 Configuration

#define	OTP_DATA_BOOTKEY1_13_BOOTKEY1_13																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_13_BOOTKEY1_13_0																	(0x1u<<0)

// BOOTKEY1_14 Configuration

#define	OTP_DATA_BOOTKEY1_14_BOOTKEY1_14																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_14_BOOTKEY1_14_0																	(0x1u<<0)

// BOOTKEY1_15 Configuration

#define	OTP_DATA_BOOTKEY1_15_BOOTKEY1_15																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY1_15_BOOTKEY1_15_0																	(0x1u<<0)

// BOOTKEY2_0 Configuration

#define	OTP_DATA_BOOTKEY2_0_BOOTKEY2_0																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_0_BOOTKEY2_0_0																	(0x1u<<0)

// BOOTKEY2_1 Configuration

#define	OTP_DATA_BOOTKEY2_1_BOOTKEY2_1																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_1_BOOTKEY2_1_0																	(0x1u<<0)

// BOOTKEY2_2 Configuration

#define	OTP_DATA_BOOTKEY2_2_BOOTKEY2_2																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_2_BOOTKEY2_2_0																	(0x1u<<0)

// BOOTKEY2_3 Configuration

#define	OTP_DATA_BOOTKEY2_3_BOOTKEY2_3																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_3_BOOTKEY2_3_0																	(0x1u<<0)

// BOOTKEY2_4 Configuration

#define	OTP_DATA_BOOTKEY2_4_BOOTKEY2_4																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_4_BOOTKEY2_4_0																	(0x1u<<0)

// BOOTKEY2_5 Configuration

#define	OTP_DATA_BOOTKEY2_5_BOOTKEY2_5																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_5_BOOTKEY2_5_0																	(0x1u<<0)

// BOOTKEY2_6 Configuration

#define	OTP_DATA_BOOTKEY2_6_BOOTKEY2_6																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_6_BOOTKEY2_6_0																	(0x1u<<0)

// BOOTKEY2_7 Configuration

#define	OTP_DATA_BOOTKEY2_7_BOOTKEY2_7																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_7_BOOTKEY2_7_0																	(0x1u<<0)

// BOOTKEY2_8 Configuration

#define	OTP_DATA_BOOTKEY2_8_BOOTKEY2_8																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_8_BOOTKEY2_8_0																	(0x1u<<0)

// BOOTKEY2_9 Configuration

#define	OTP_DATA_BOOTKEY2_9_BOOTKEY2_9																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_9_BOOTKEY2_9_0																	(0x1u<<0)

// BOOTKEY2_10 Configuration

#define	OTP_DATA_BOOTKEY2_10_BOOTKEY2_10																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_10_BOOTKEY2_10_0																	(0x1u<<0)

// BOOTKEY2_11 Configuration

#define	OTP_DATA_BOOTKEY2_11_BOOTKEY2_11																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_11_BOOTKEY2_11_0																	(0x1u<<0)

// BOOTKEY2_12 Configuration

#define	OTP_DATA_BOOTKEY2_12_BOOTKEY2_12																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_12_BOOTKEY2_12_0																	(0x1u<<0)

// BOOTKEY2_13 Configuration

#define	OTP_DATA_BOOTKEY2_13_BOOTKEY2_13																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_13_BOOTKEY2_13_0																	(0x1u<<0)

// BOOTKEY2_14 Configuration

#define	OTP_DATA_BOOTKEY2_14_BOOTKEY2_14																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_14_BOOTKEY2_14_0																	(0x1u<<0)

// BOOTKEY2_15 Configuration

#define	OTP_DATA_BOOTKEY2_15_BOOTKEY2_15																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY2_15_BOOTKEY2_15_0																	(0x1u<<0)

// BOOTKEY3_0 Configuration

#define	OTP_DATA_BOOTKEY3_0_BOOTKEY3_0																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_0_BOOTKEY3_0_0																	(0x1u<<0)

// BOOTKEY3_1 Configuration

#define	OTP_DATA_BOOTKEY3_1_BOOTKEY3_1																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_1_BOOTKEY3_1_0																	(0x1u<<0)

// BOOTKEY3_2 Configuration

#define	OTP_DATA_BOOTKEY3_2_BOOTKEY3_2																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_2_BOOTKEY3_2_0																	(0x1u<<0)

// BOOTKEY3_3 Configuration

#define	OTP_DATA_BOOTKEY3_3_BOOTKEY3_3																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_3_BOOTKEY3_3_0																	(0x1u<<0)

// BOOTKEY3_4 Configuration

#define	OTP_DATA_BOOTKEY3_4_BOOTKEY3_4																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_4_BOOTKEY3_4_0																	(0x1u<<0)

// BOOTKEY3_5 Configuration

#define	OTP_DATA_BOOTKEY3_5_BOOTKEY3_5																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_5_BOOTKEY3_5_0																	(0x1u<<0)

// BOOTKEY3_6 Configuration

#define	OTP_DATA_BOOTKEY3_6_BOOTKEY3_6																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_6_BOOTKEY3_6_0																	(0x1u<<0)

// BOOTKEY3_7 Configuration

#define	OTP_DATA_BOOTKEY3_7_BOOTKEY3_7																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_7_BOOTKEY3_7_0																	(0x1u<<0)

// BOOTKEY3_8 Configuration

#define	OTP_DATA_BOOTKEY3_8_BOOTKEY3_8																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_8_BOOTKEY3_8_0																	(0x1u<<0)

// BOOTKEY3_9 Configuration

#define	OTP_DATA_BOOTKEY3_9_BOOTKEY3_9																		(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_9_BOOTKEY3_9_0																	(0x1u<<0)

// BOOTKEY3_10 Configuration

#define	OTP_DATA_BOOTKEY3_10_BOOTKEY3_10																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_10_BOOTKEY3_10_0																	(0x1u<<0)

// BOOTKEY3_11 Configuration

#define	OTP_DATA_BOOTKEY3_11_BOOTKEY3_11																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_11_BOOTKEY3_11_0																	(0x1u<<0)

// BOOTKEY3_12 Configuration

#define	OTP_DATA_BOOTKEY3_12_BOOTKEY3_12																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_12_BOOTKEY3_12_0																	(0x1u<<0)

// BOOTKEY3_13 Configuration

#define	OTP_DATA_BOOTKEY3_13_BOOTKEY3_13																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_13_BOOTKEY3_13_0																	(0x1u<<0)

// BOOTKEY3_14 Configuration

#define	OTP_DATA_BOOTKEY3_14_BOOTKEY3_14																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_14_BOOTKEY3_14_0																	(0x1u<<0)

// BOOTKEY3_15 Configuration

#define	OTP_DATA_BOOTKEY3_15_BOOTKEY3_15																	(0xFFFFu<<0)
#define	OTP_DATA_BOOTKEY3_15_BOOTKEY3_15_0																	(0x1u<<0)

// KEY1_0 Configuration

#define	OTP_DATA_KEY1_0_KEY1_0																				(0xFFFFu<<0)
#define	OTP_DATA_KEY1_0_KEY1_0_0																			(0x1u<<0)

// KEY1_1 Configuration

#define	OTP_DATA_KEY1_1_KEY1_1																				(0xFFFFu<<0)
#define	OTP_DATA_KEY1_1_KEY1_1_0																			(0x1u<<0)

// KEY1_2 Configuration

#define	OTP_DATA_KEY1_2_KEY1_2																				(0xFFFFu<<0)
#define	OTP_DATA_KEY1_2_KEY1_2_0																			(0x1u<<0)

// KEY1_3 Configuration

#define	OTP_DATA_KEY1_3_KEY1_3																				(0xFFFFu<<0)
#define	OTP_DATA_KEY1_3_KEY1_3_0																			(0x1u<<0)

// KEY1_4 Configuration

#define	OTP_DATA_KEY1_4_KEY1_4																				(0xFFFFu<<0)
#define	OTP_DATA_KEY1_4_KEY1_4_0																			(0x1u<<0)

// KEY1_5 Configuration

#define	OTP_DATA_KEY1_5_KEY1_5																				(0xFFFFu<<0)
#define	OTP_DATA_KEY1_5_KEY1_5_0																			(0x1u<<0)

// KEY1_6 Configuration

#define	OTP_DATA_KEY1_6_KEY1_6																				(0xFFFFu<<0)
#define	OTP_DATA_KEY1_6_KEY1_6_0																			(0x1u<<0)

// KEY1_7 Configuration

#define	OTP_DATA_KEY1_7_KEY1_7																				(0xFFFFu<<0)
#define	OTP_DATA_KEY1_7_KEY1_7_0																			(0x1u<<0)

// KEY2_0 Configuration

#define	OTP_DATA_KEY2_0_KEY2_0																				(0xFFFFu<<0)
#define	OTP_DATA_KEY2_0_KEY2_0_0																			(0x1u<<0)

// KEY2_1 Configuration

#define	OTP_DATA_KEY2_1_KEY2_1																				(0xFFFFu<<0)
#define	OTP_DATA_KEY2_1_KEY2_1_0																			(0x1u<<0)

// KEY2_2 Configuration

#define	OTP_DATA_KEY2_2_KEY2_2																				(0xFFFFu<<0)
#define	OTP_DATA_KEY2_2_KEY2_2_0																			(0x1u<<0)

// KEY2_3 Configuration

#define	OTP_DATA_KEY2_3_KEY2_3																				(0xFFFFu<<0)
#define	OTP_DATA_KEY2_3_KEY2_3_0																			(0x1u<<0)

// KEY2_4 Configuration

#define	OTP_DATA_KEY2_4_KEY2_4																				(0xFFFFu<<0)
#define	OTP_DATA_KEY2_4_KEY2_4_0																			(0x1u<<0)

// KEY2_5 Configuration

#define	OTP_DATA_KEY2_5_KEY2_5																				(0xFFFFu<<0)
#define	OTP_DATA_KEY2_5_KEY2_5_0																			(0x1u<<0)

// KEY2_6 Configuration

#define	OTP_DATA_KEY2_6_KEY2_6																				(0xFFFFu<<0)
#define	OTP_DATA_KEY2_6_KEY2_6_0																			(0x1u<<0)

// KEY2_7 Configuration

#define	OTP_DATA_KEY2_7_KEY2_7																				(0xFFFFu<<0)
#define	OTP_DATA_KEY2_7_KEY2_7_0																			(0x1u<<0)

// KEY3_0 Configuration

#define	OTP_DATA_KEY3_0_KEY3_0																				(0xFFFFu<<0)
#define	OTP_DATA_KEY3_0_KEY3_0_0																			(0x1u<<0)

// KEY3_1 Configuration

#define	OTP_DATA_KEY3_1_KEY3_1																				(0xFFFFu<<0)
#define	OTP_DATA_KEY3_1_KEY3_1_0																			(0x1u<<0)

// KEY3_2 Configuration

#define	OTP_DATA_KEY3_2_KEY3_2																				(0xFFFFu<<0)
#define	OTP_DATA_KEY3_2_KEY3_2_0																			(0x1u<<0)

// KEY3_3 Configuration

#define	OTP_DATA_KEY3_3_KEY3_3																				(0xFFFFu<<0)
#define	OTP_DATA_KEY3_3_KEY3_3_0																			(0x1u<<0)

// KEY3_4 Configuration

#define	OTP_DATA_KEY3_4_KEY3_4																				(0xFFFFu<<0)
#define	OTP_DATA_KEY3_4_KEY3_4_0																			(0x1u<<0)

// KEY3_5 Configuration

#define	OTP_DATA_KEY3_5_KEY3_5																				(0xFFFFu<<0)
#define	OTP_DATA_KEY3_5_KEY3_5_0																			(0x1u<<0)

// KEY3_6 Configuration

#define	OTP_DATA_KEY3_6_KEY3_6																				(0xFFFFu<<0)
#define	OTP_DATA_KEY3_6_KEY3_6_0																			(0x1u<<0)

// KEY3_7 Configuration

#define	OTP_DATA_KEY3_7_KEY3_7																				(0xFFFFu<<0)
#define	OTP_DATA_KEY3_7_KEY3_7_0																			(0x1u<<0)

// KEY4_0 Configuration

#define	OTP_DATA_KEY4_0_KEY4_0																				(0xFFFFu<<0)
#define	OTP_DATA_KEY4_0_KEY4_0_0																			(0x1u<<0)

// KEY4_1 Configuration

#define	OTP_DATA_KEY4_1_KEY4_1																				(0xFFFFu<<0)
#define	OTP_DATA_KEY4_1_KEY4_1_0																			(0x1u<<0)

// KEY4_2 Configuration

#define	OTP_DATA_KEY4_2_KEY4_2																				(0xFFFFu<<0)
#define	OTP_DATA_KEY4_2_KEY4_2_0																			(0x1u<<0)

// KEY4_3 Configuration

#define	OTP_DATA_KEY4_3_KEY4_3																				(0xFFFFu<<0)
#define	OTP_DATA_KEY4_3_KEY4_3_0																			(0x1u<<0)

// KEY4_4 Configuration

#define	OTP_DATA_KEY4_4_KEY4_4																				(0xFFFFu<<0)
#define	OTP_DATA_KEY4_4_KEY4_4_0																			(0x1u<<0)

// KEY4_5 Configuration

#define	OTP_DATA_KEY4_5_KEY4_5																				(0xFFFFu<<0)
#define	OTP_DATA_KEY4_5_KEY4_5_0																			(0x1u<<0)

// KEY4_6 Configuration

#define	OTP_DATA_KEY4_6_KEY4_6																				(0xFFFFu<<0)
#define	OTP_DATA_KEY4_6_KEY4_6_0																			(0x1u<<0)

// KEY4_7 Configuration

#define	OTP_DATA_KEY4_7_KEY4_7																				(0xFFFFu<<0)
#define	OTP_DATA_KEY4_7_KEY4_7_0																			(0x1u<<0)

// KEY5_0 Configuration

#define	OTP_DATA_KEY5_0_KEY5_0																				(0xFFFFu<<0)
#define	OTP_DATA_KEY5_0_KEY5_0_0																			(0x1u<<0)

// KEY5_1 Configuration

#define	OTP_DATA_KEY5_1_KEY5_1																				(0xFFFFu<<0)
#define	OTP_DATA_KEY5_1_KEY5_1_0																			(0x1u<<0)

// KEY5_2 Configuration

#define	OTP_DATA_KEY5_2_KEY5_2																				(0xFFFFu<<0)
#define	OTP_DATA_KEY5_2_KEY5_2_0																			(0x1u<<0)

// KEY5_3 Configuration

#define	OTP_DATA_KEY5_3_KEY5_3																				(0xFFFFu<<0)
#define	OTP_DATA_KEY5_3_KEY5_3_0																			(0x1u<<0)

// KEY5_4 Configuration

#define	OTP_DATA_KEY5_4_KEY5_4																				(0xFFFFu<<0)
#define	OTP_DATA_KEY5_4_KEY5_4_0																			(0x1u<<0)

// KEY5_5 Configuration

#define	OTP_DATA_KEY5_5_KEY5_5																				(0xFFFFu<<0)
#define	OTP_DATA_KEY5_5_KEY5_5_0																			(0x1u<<0)

// KEY5_6 Configuration

#define	OTP_DATA_KEY5_6_KEY5_6																				(0xFFFFu<<0)
#define	OTP_DATA_KEY5_6_KEY5_6_0																			(0x1u<<0)

// KEY5_7 Configuration

#define	OTP_DATA_KEY5_7_KEY5_7																				(0xFFFFu<<0)
#define	OTP_DATA_KEY5_7_KEY5_7_0																			(0x1u<<0)

// KEY6_0 Configuration

#define	OTP_DATA_KEY6_0_KEY6_0																				(0xFFFFu<<0)
#define	OTP_DATA_KEY6_0_KEY6_0_0																			(0x1u<<0)

// KEY6_1 Configuration

#define	OTP_DATA_KEY6_1_KEY6_1																				(0xFFFFu<<0)
#define	OTP_DATA_KEY6_1_KEY6_1_0																			(0x1u<<0)

// KEY6_2 Configuration

#define	OTP_DATA_KEY6_2_KEY6_2																				(0xFFFFu<<0)
#define	OTP_DATA_KEY6_2_KEY6_2_0																			(0x1u<<0)

// KEY6_3 Configuration

#define	OTP_DATA_KEY6_3_KEY6_3																				(0xFFFFu<<0)
#define	OTP_DATA_KEY6_3_KEY6_3_0																			(0x1u<<0)

// KEY6_4 Configuration

#define	OTP_DATA_KEY6_4_KEY6_4																				(0xFFFFu<<0)
#define	OTP_DATA_KEY6_4_KEY6_4_0																			(0x1u<<0)

// KEY6_5 Configuration

#define	OTP_DATA_KEY6_5_KEY6_5																				(0xFFFFu<<0)
#define	OTP_DATA_KEY6_5_KEY6_5_0																			(0x1u<<0)

// KEY6_6 Configuration

#define	OTP_DATA_KEY6_6_KEY6_6																				(0xFFFFu<<0)
#define	OTP_DATA_KEY6_6_KEY6_6_0																			(0x1u<<0)

// KEY6_7 Configuration

#define	OTP_DATA_KEY6_7_KEY6_7																				(0xFFFFu<<0)
#define	OTP_DATA_KEY6_7_KEY6_7_0																			(0x1u<<0)
