/**
  * @file    mx25um51245g_conf.h
  * @brief   MX25UM51245G OctoSPI memory configuration for NUCLEO-N657X0-Q FSBL.
  */

#ifndef MX25UM51245G_CONF_H
#define MX25UM51245G_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32n6xx_hal.h"

#define CONF_OSPI_ODS                MX25UM51245G_CR_ODS_24

#define DUMMY_CYCLES_READ            8U
#define DUMMY_CYCLES_READ_OCTAL      6U
#define DUMMY_CYCLES_READ_OCTAL_DTR  6U
#define DUMMY_CYCLES_REG_OCTAL       4U
#define DUMMY_CYCLES_REG_OCTAL_DTR   5U

#ifdef __cplusplus
}
#endif

#endif /* MX25UM51245G_CONF_H */
