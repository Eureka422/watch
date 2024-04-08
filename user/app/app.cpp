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
    lv_obj_set_size(screen, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    lv_obj_clear_flag(screen, LV_OBJ_FLAG_SCROLLABLE);
    Page1 page1;    
    page1.create(screen);
    lv_scr_load(screen);
    while (1)
    {
        xSemaphoreTake(MutexSemaphore, portMAX_DELAY);
        // lv_label_set_text_fmt(page1.ui.clock.minute, "%d", count);
        lv_timer_handler();
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
