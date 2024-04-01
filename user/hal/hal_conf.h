/**
  * @file    haL_conf.h
  * @brief   This file contains pin set
  */
#ifndef __HAL_CONF_H
#define __HAL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"




void SystemClock_Config(void);
void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
