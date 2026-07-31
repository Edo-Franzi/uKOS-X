/**
  * @file    stm32n6xx_nucleo_conf.h
  * @brief   BSP configuration for NUCLEO-N657X0-Q FSBL.
  */

#ifndef STM32N6XX_NUCLEO_CONF_H
#define STM32N6XX_NUCLEO_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32n6xx_hal.h"

#define USE_NUCLEO_144

/* COM / UART — not used by FSBL */
#define USE_BSP_COM_FEATURE 0U
#define USE_COM_LOG         0U

#define BSP_BUTTON_USER_IT_PRIORITY 15U

#ifdef __cplusplus
}
#endif

#endif /* STM32N6XX_NUCLEO_CONF_H */
