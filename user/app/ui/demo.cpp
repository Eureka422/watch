#include "demo.h"
#include "stdio.h"

lv_obj_t* speed_label = NULL;

void demo_create(lv_obj_t* parent)
{
    create_label(parent);
    create_btn(parent);

}

/*
 *@brief: 创建一个speed label
 */
void create_label(lv_obj_t* parent)
{
    speed_label = lv_label_create(parent);
    lv_label_set_text(speed_label, "speed: 0");
    // 设置标签颜色
    lv_obj_set_style_text_color(speed_label, lv_color_hex(0xff0000), 0);
    lv_obj_align(speed_label, LV_ALIGN_CENTER, 0, -150);
}

/*
 *@brief: 创建加速按钮
*/
void create_btn(lv_obj_t* parent)
{
    lv_obj_t* btn = lv_btn_create(parent);
    lv_obj_set_size(btn, 100, 100);
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t* label = lv_label_create(btn);
    lv_label_set_text(label, "speedup");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_CLICKED, NULL);
}

/* 
 *@brief: Button event callback function
*/
void btn_event_handler(lv_event_t* event)
{
    lv_obj_t* obj = lv_event_get_target(event);
    if (obj == NULL)
    {
        return;
    }

    if (speed_label == NULL)
    {
        return;
    }

    static int speed = 0;
    speed += 10;
    lv_label_set_text_fmt(speed_label, "speed: %d", speed);
}