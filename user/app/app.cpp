#include "app.h"
#include "semphr.h"
#include "lvgl.h"

SemaphoreHandle_t MutexSemaphore =NULL;

void app_init(void)
{
    taskENTER_CRITICAL();
    // HAL::init();
    MutexSemaphore = xSemaphoreCreateMutex();
    xTaskCreate(led_task, "led_task", 128, NULL, 1, NULL);
    xTaskCreate(disp_task, "disp_task", 1024, NULL, 1, NULL);
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

    lv_style_t style_label;
    lv_style_init(&style_label);

    lv_style_set_text_color(&style_label, lv_color_white());
    lv_style_set_text_font(&style_label, &lv_font_montserrat_24);
    lv_obj_t *label = lv_label_create(screen);
    lv_label_set_text(label, "Hello World!");
    lv_obj_add_style(label, &style_label, LV_PART_MAIN);
    lv_obj_center(label);
    lv_scr_load(screen);
    while (1)
    {
        xSemaphoreTake(MutexSemaphore, portMAX_DELAY);
        lv_timer_handler();
        xSemaphoreGive(MutexSemaphore);
        vTaskDelay(5);
    }
}
