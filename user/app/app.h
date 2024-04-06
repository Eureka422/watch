#ifndef __APP_H__
#define __APP_H__

#include "hal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "ui/demo.h"
#include "pages/page1.h"


void app_init(void);
void led_task(void *pvParameters);
void disp_task(void *pvParameters);
void clock_task(void *pvParameters);

#endif // __APP_H__