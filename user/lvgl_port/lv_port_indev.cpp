#include "lv_port.h"

lv_indev_t* indev_touchpad;

static void touchpad_read(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static lv_coord_t last_x = 0;
    static lv_coord_t last_y = 0;
    HAL::touch.read();
    if (HAL::touch.is_pressed())
    {
        HAL::touch.get_tp(&last_x, &last_y);
        data->state = LV_INDEV_STATE_PR;
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }
    data->point.x = last_x;
    data->point.y = last_y;
}

void lv_port_indev_init(void)
{
    HAL::touch.init();

    static lv_indev_drv_t indev_drv;
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    indev_touchpad = lv_indev_drv_register(&indev_drv);
}