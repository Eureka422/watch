#include "lv_port.h"

void lv_port_indev_init(void)
{
    HAL::touch.init();
}