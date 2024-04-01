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
    // uint8_t data[1] = {0x00};
    while (1)
    {
        HAL::display.fill_area(100, 100, 155, 155, 0xF800);
        vTaskDelay(1000);
        // HAL::display.fill_area(100, 100, 155, 155, 0x07E0);
        // vTaskDelay(1000);
        HAL::display.fill_area(100, 100, 155, 155, 0xFFFF);
        vTaskDelay(1000);
        // HAL::display.fill_area(100, 100, 155, 155, 0x3000);
        // vTaskDelay(1000);
        // printf("display task\r\n");
        // HAL_Delay(1000);
    }
}
