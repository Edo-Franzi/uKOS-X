/**
  * @file    stm32n6570_discovery_conf.h
  * @brief   BSP configuration for STM32N6570-DK (Discovery_N657).
  *          Minimal set for FSBL — peripherals unused by the boot loader
  *          are disabled to avoid pulling in unneeded BSP drivers.
  */

#ifndef STM32N6570_DISCOVERY_CONF_H
#define STM32N6570_DISCOVERY_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32n6xx_hal.h"

/* COM / UART — not used by FSBL */
#define USE_COM_LOG                         0U
#define USE_BSP_COM_FEATURE                 0U

/* Touch screen — not used by FSBL */
#define USE_FT5336_TS_CTRL                  0U
#define USE_TS_GESTURE                      0U
#define USE_TS_MULTI_TOUCH                  0U
#define TS_TOUCH_NBR                        1U

/* LCD frame buffer addresses (required by BSP headers even when LCD unused) */
#define LCD_LAYER_0_ADDRESS                 0x34000000U
#define LCD_LAYER_1_ADDRESS                 0x340C0000U

/* Audio codec — not used by FSBL */
#define USE_AUDIO_CODEC_WM8904
#define DEFAULT_AUDIO_IN_BUFFER_SIZE        2048U

/* IRQ priorities */
#define BSP_SDRAM_IT_PRIORITY               15U
#define BSP_BUTTON_USER1_IT_PRIORITY        15U
#define BSP_BUTTON_USER2_IT_PRIORITY        15U
#define BSP_BUTTON_TAMP_IT_PRIORITY         15U
#define BSP_AUDIO_OUT_IT_PRIORITY           14U
#define BSP_AUDIO_IN_IT_PRIORITY            15U
#define BSP_SD_IT_PRIORITY                  14U
#define BSP_SD_RX_IT_PRIORITY               14U
#define BSP_SD_TX_IT_PRIORITY               15U
#define BSP_TS_IT_PRIORITY                  15U

/* Camera ISP defaults */
#define BSP_CAMERA_ISP_DEFAULT_WHITE_BALANCE    255U
#define BSP_CAMERA_ISP_DEFAULT_EXPOSURE         128U
#define BSP_CAMERA_ISP_DEFAULT_CONTRAST         130U
#define BSP_CAMERA_ISP_STATISTICS_AREA_HEIGHT   1940
#define BSP_CAMERA_ISP_STATISTICS_AREA_WIDTH    2592

#ifdef __cplusplus
}
#endif

#endif /* STM32N6570_DISCOVERY_CONF_H */
