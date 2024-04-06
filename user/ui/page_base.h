#ifndef __PAGEBASE_H__
#define __PAGEBASE_H__

#include "hal.h"
#include "lvgl.h"

class PageBase
{
    typedef struct{


    } page_state_t;
public:
    PageBase(void) {}
    ~PageBase() {}

    virtual void create(lv_obj_t* parent) {};
    virtual void load() {};

};

#endif 