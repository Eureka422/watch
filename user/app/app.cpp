#include "app.h"

void app_init(void)
{
    taskENTER_CRITICAL();
    HAL::init();
    xTaskCreate(led_task, "led_task", 128, NULL, 1, NULL);
    xTaskCreate(disp_task, "disp_task", 128, NULL, 1, NULL);
    taskEXIT_CRITICAL();
    vTaskStartScheduler();
}

void led_task(void *pvParameters)
{
    while (1)
    {
        HAL::led0.toggle();
        HAL_Delay(500);
        printf("led toggle per s\r\n");
    }
}

void disp_task(void *pvParameters)
{
    while (1)
    {
        HAL::display.fill_area(0, 0, DISPLAY_WIDTH - 1, buf_height - 100, 0xf800);
        vTaskDelay(1000);
        HAL::display.fill_area(0, 0, DISPLAY_WIDTH - 1, buf_height - 100, 0x07e0);
        vTaskDelay(1000);
        HAL::display.fill_area(0, 0, DISPLAY_WIDTH - 1, buf_height - 100, 0x001F);
        vTaskDelay(1000);
    }
}
