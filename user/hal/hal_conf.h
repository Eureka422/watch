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


/* hardware ------------------------------------------------------------------*/
/* LED */
#define LED0_GPIO_PORT GPIOA
#define LED0_PIN GPIO_PIN_15

/* Display AMOLED 达沃科技1.78寸 - 368*448*/
#define DISPLAY_WIDTH 368
#define DISPLAY_HEIGHT 448


void SystemClock_Config(void);
void Error_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
