#include <string>
#include "hal.h"
#include "app.h"
#include "FreeRTOS.h"
#include "task.h"
#include "display/display.h"

int main(void)
{
    HAL_Init();
    app_init();
    while (1)
    {
        // printf("Hello World! yeah\r\n");
        // HAL_Delay(1000);
        // HAL::led0.toggle();
    }
}
