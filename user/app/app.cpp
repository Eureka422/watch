#include "app.h"
#include "semphr.h"
#include "lvgl.h"

SemaphoreHandle_t MutexSemaphore =NULL;
static int count = 0;

void app_init(void)
{
    taskENTER_CRITICAL();
    // HAL::init();
    MutexSemaphore = xSemaphoreCreateMutex();
    xTaskCreate(led_task, "led_task", 128, NULL, 3, NULL);
    xTaskCreate(disp_task, "disp_task", 1024, NULL, 3, NULL);
    xTaskCreate(clock_task, "clock_task", 128, NULL, 3, NULL);
    taskEXIT_CRITICAL();
    vTaskStartScheduler();
}

void led_task(void *pvParameters)
{
    while (1)
    {
        HAL::led0.toggle();
        HAL_Delay(500);
        // printf("led toggle per s\r\n");
    }
}

void disp_task(void *pvParameters)
{
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, lv_color_black(), LV_PART_MAIN);
    demo_create(screen);

    lv_obj_t *label = lv_label_create(screen);
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_scr_load(screen);
    while (1)
    {
        xSemaphoreTake(MutexSemaphore, portMAX_DELAY);
        lv_label_set_text_fmt(label, "count: %d", count);
        lv_timer_handler();
        printf("lvgl timer handler\r\n");
        xSemaphoreGive(MutexSemaphore);
        vTaskDelay(5);
    }
}

void clock_task(void *pvParameters)
{
    while (1)
    {
        count++;
        HAL::touch.init();
        HAL_Delay(1000);
    }
}
