#ifndef __PAGE1_H__
#define __PAGE1_H__

#include "page_base.h"

class Page1 : public PageBase
{
public:
    struct {
        struct {
            lv_obj_t* cont;
            lv_obj_t* bat;
            lv_obj_t* wifi;
        } top;
        struct {
            lv_obj_t* cont;
            lv_obj_t* hour;
            lv_obj_t* minute;
            lv_obj_t* symbal;
        } clock;
        struct {
            lv_obj_t* cont;
            lv_obj_t* chart;
        } chart;
        struct {
            lv_obj_t* cont;
            lv_obj_t* btn1;
            lv_obj_t* btn2;
            lv_obj_t* btn3;
        } btn;
    } ui;
public:
    Page1(void) {}
    ~Page1() {}

    virtual void create(lv_obj_t* parent);
    virtual void load(); 
private:
    void create_top(lv_obj_t* parent);
    void create_clock(lv_obj_t* parent);
    void create_chart(lv_obj_t* parent);
    void create_btn(lv_obj_t* parent);
    
};


#endif // __PAGE1_H__