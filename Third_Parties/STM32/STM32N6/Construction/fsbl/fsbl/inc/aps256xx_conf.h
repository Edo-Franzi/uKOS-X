/**
  * @file    aps256xx_conf.h
  * @brief   APS256XX PSRAM configuration for Discovery_N657 FSBL.
  *          PSRAM is not used by the FSBL boot path; this file exists
  *          only to satisfy the Discovery BSP XSPI header dependency.
  */

#ifndef APS256XX_CONF_H
#define APS256XX_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32n6xx_hal.h"

#define CONF_HSPI_DS   APS256XX_MR0_DS_HALF
#define CONF_HSPI_PASR APS256XX_MR4_PASR_FULL
#define CONF_HSPI_RF   APS256XX_MR4_RF_4X

#define DEFAULT_READ_LATENCY_CODE  APS256XX_READ_LATENCY_5
#define DEFAULT_WRITE_LATENCY_CODE APS256XX_WRITE_LATENCY_5

#ifdef __cplusplus
}
#endif

#endif /* APS256XX_CONF_H */
