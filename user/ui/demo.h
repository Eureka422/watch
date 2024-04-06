#ifndef __DEMO_H__
#define __DEMO_H__

#include "lvgl.h"   

void demo_create(lv_obj_t* parent);
void create_label(lv_obj_t* parent);
void create_btn(lv_obj_t* parent);
void btn_event_handler(lv_event_t* event);

#endif // __DEMO_H__