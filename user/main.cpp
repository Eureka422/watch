#include <string>
#include "hal.h"
#include "app.h"
#include "FreeRTOS.h"
#include "task.h"
#include "lvgl.h"
#include "lv_port.h"

int main(void)
{
    HAL_Init();
    lv_port_init();
    app_init();

    while (1) {}
}
