#ifndef __APP_H__
#define __APP_H__

#include "hal.h"
#include "FreeRTOS.h"
#include "task.h"


void app_init(void);
void led_task(void *pvParameters);
void disp_task(void *pvParameters);
void touch_task(void *pvParameters);

#endif // __APP_H__