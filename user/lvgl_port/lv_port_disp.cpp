#include "lv_port.h"    


void disp_flush_cb(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    HAL::display.fill_area(area->x1, area->y1, area->x2, area->y2, (uint16_t *)color_p);
    lv_disp_flush_ready(disp_drv);
}

void lv_port_disp_init(void)
{
    HAL::display.init();

    static lv_disp_draw_buf_t disp_buf;
    static lv_color_t buf1[DISPLAY_WIDTH * 112];
    static lv_color_t buf2[DISPLAY_WIDTH * 112];

    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, DISPLAY_WIDTH * 112);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &disp_buf;
    disp_drv.flush_cb = disp_flush_cb;
    disp_drv.hor_res = DISPLAY_WIDTH;
    disp_drv.ver_res = DISPLAY_HEIGHT;
    lv_disp_drv_register(&disp_drv);

}