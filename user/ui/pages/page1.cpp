#include "page1.h"

void Page1::create(lv_obj_t* parent)
{
    create_top(parent);
    create_clock(parent);
    create_chart(parent);
    create_btn(parent);
}

void Page1::create_top(lv_obj_t* parent)
{
    // 创建一个容器
    lv_obj_t* cont = lv_obj_create(parent);
    lv_obj_remove_style_all(cont);
    lv_obj_set_size(cont, DISPLAY_WIDTH, 60);

    lv_obj_set_style_bg_opa(cont, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x333333), 0);
    lv_obj_set_style_radius(cont, 8, 0);
    lv_obj_align(cont, LV_ALIGN_TOP_MID, 0, 0);
    ui.top.cont = cont;

    // 创建一个电池
    lv_obj_t* bat = lv_bar_create(cont);
    lv_bar_set_value(bat, 25, LV_ANIM_OFF);
    lv_bar_set_start_value(bat, 0, LV_ANIM_OFF);
    lv_obj_set_width(bat, 40);
    lv_obj_set_height(bat, 24);
    lv_obj_align(bat, LV_ALIGN_LEFT_MID, +15, 0);
    lv_obj_set_style_radius(bat, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bat, lv_color_hex(0x636060), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bat, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(bat, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bat, lv_color_hex(0x0CF70D), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(bat, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    ui.top.bat = bat;

    // 创建一个wifi
    lv_obj_t* wifi = lv_label_create(cont);
    lv_label_set_text(wifi, LV_SYMBOL_WIFI);
    lv_obj_set_style_text_font(wifi, &lv_font_montserrat_24, 0);
    lv_obj_align(wifi, LV_ALIGN_RIGHT_MID, -25, 0);
    lv_obj_set_style_text_color(wifi, lv_color_white(), 0);
    ui.top.wifi = wifi;

    // 创建一个名字
    lv_obj_t* name = lv_label_create(cont);
    lv_label_set_text(name, "EUREKA");
    lv_obj_align(name, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_color(name, lv_color_hex(0xffffff), 0);
    ui.top.name = name;
}

void Page1::create_clock(lv_obj_t* parent)
{
    lv_obj_t* cont = lv_obj_create(parent);
    lv_obj_remove_style_all(cont);
    lv_obj_set_size(cont, DISPLAY_WIDTH, 100);
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x333333), 0);
    lv_obj_set_style_radius(cont, 0, 0);
    lv_obj_align(cont, LV_ALIGN_CENTER, 0, -80);
    ui.clock.cont = cont;

    LV_FONT_DECLARE(lv_gaoel_num_font_64)
    lv_obj_t* hour = lv_label_create(cont);
    lv_label_set_text(hour, "00");
    lv_obj_set_style_text_font(hour, &lv_gaoel_num_font_64, 0);
    lv_obj_set_style_text_color(hour, lv_color_hex(0xffffff), 0);
    lv_obj_align(hour, LV_ALIGN_CENTER, -60, 0);
    ui.clock.hour = hour;

    lv_obj_t* symbal = lv_label_create(cont);
    lv_label_set_text(symbal, ":");
    // lv_obj_set_style_text_font(symbal, &lv_font_montserrat_48, 0);
    lv_obj_set_style_text_color(symbal, lv_color_hex(0xffffff), 0);
    lv_obj_align(symbal, LV_ALIGN_CENTER, 0, 0);
    ui.clock.symbal = symbal;

    lv_obj_t* minute = lv_label_create(cont);
    lv_label_set_text(minute, "00");
    lv_obj_set_style_text_font(minute, &lv_gaoel_num_font_64, 0);
    lv_obj_set_style_text_color(minute, lv_color_hex(0xffffff), 0);
    lv_obj_align(minute, LV_ALIGN_CENTER, 60, 0);
    ui.clock.minute = minute;
}

void Page1::create_chart(lv_obj_t* parent)
{
    lv_obj_t* cont = lv_obj_create(parent);
    lv_obj_remove_style_all(cont);
    lv_obj_set_size(cont, DISPLAY_WIDTH, 150);
    lv_obj_set_style_bg_opa(cont, LV_OPA_TRANSP, 0);
    lv_obj_set_style_radius(cont, 0, 0);
    lv_obj_align(cont, LV_ALIGN_CENTER, 0, +50);
    ui.chart.cont = cont;

    lv_obj_t* chart = lv_chart_create(cont);
    lv_obj_set_size(chart, 220, 150);
    lv_obj_align(chart, LV_ALIGN_CENTER, 0, 0);
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
    lv_chart_set_axis_tick(chart, LV_CHART_AXIS_PRIMARY_X, 10, 5, 5, 2, true, 50);
    lv_chart_set_axis_tick(chart, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 5, 2, true, 50);
    lv_chart_set_axis_tick(chart, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 5, 2, false, 25);
    lv_chart_series_t * chart_series_1 = lv_chart_add_series(chart, lv_color_hex(0xE31010),
                                                                 LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t chart_series_1_array[] = { 0, 10, 20, 40, 80, 80, 40, 20, 10, 0 };
    lv_chart_set_ext_y_array(chart, chart_series_1, chart_series_1_array);
    lv_obj_set_style_bg_grad_color(chart, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    ui.chart.chart = chart;
}

void Page1::create_btn(lv_obj_t* parent)
{
    lv_obj_t* cont = lv_obj_create(parent);
    lv_obj_remove_style_all(cont);
    lv_obj_set_size(cont, DISPLAY_WIDTH, 100);
    lv_obj_set_style_bg_opa(cont, LV_OPA_TRANSP, 0);
    lv_obj_set_style_radius(cont, 0, 0);
    lv_obj_align(cont, LV_ALIGN_BOTTOM_MID, 0, 0);
    ui.btn.cont = cont;


    lv_obj_t* btn1 = lv_btn_create(cont);
    lv_obj_set_size(btn1, 75, 50);
    lv_obj_clear_flag(btn1, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_align(btn1, LV_ALIGN_LEFT_MID, +40, 0);
    ui.btn.btn1 = btn1;

    lv_obj_t* label1 = lv_label_create(btn1);
    lv_label_set_text(label1, "btn1");
    lv_obj_align(label1, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t* btn2 = lv_btn_create(cont);
    lv_obj_set_size(btn2, 75, 50);
    lv_obj_clear_flag(btn2, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 0);
    ui.btn.btn2 = btn2;

    lv_obj_t* label2 = lv_label_create(btn2);
    lv_label_set_text(label2, "btn2");
    lv_obj_align(label2, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t* btn3 = lv_btn_create(cont);
    lv_obj_set_size(btn3, 75, 50);
    lv_obj_clear_flag(btn3, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_align(btn3, LV_ALIGN_RIGHT_MID, -40, 0);
    ui.btn.btn3 = btn3;

    lv_obj_t* label3 = lv_label_create(btn3);
    lv_label_set_text(label3, "btn3");
    lv_obj_align(label3, LV_ALIGN_CENTER, 0, 0);
}

void Page1::load()
{

}