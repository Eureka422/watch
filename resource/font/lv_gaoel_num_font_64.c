/*******************************************************************************
 * Size: 64 px
 * Bpp: 1
 * Opts: --bpp 1 --size 64 --no-compress --font gaoel.ttf --symbols 0123456789: --format lvgl -o lv_gaoel_num_font_64.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef LV_GAOEL_NUM_FONT_64
#define LV_GAOEL_NUM_FONT_64 1
#endif

#if LV_GAOEL_NUM_FONT_64

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x0, 0xf, 0xfc, 0x0, 0x0, 0xf, 0xff, 0xc0,
    0x0, 0xf, 0xff, 0xfc, 0x0, 0x7, 0xff, 0xff,
    0x80, 0x3, 0xff, 0xff, 0xf0, 0x1, 0xff, 0xff,
    0xfe, 0x0, 0xff, 0xff, 0xff, 0xc0, 0x7f, 0xff,
    0xff, 0xf8, 0x1f, 0xff, 0xff, 0xfe, 0xf, 0xff,
    0x3, 0xff, 0xc3, 0xff, 0x0, 0x3f, 0xf0, 0xff,
    0x80, 0x7, 0xfc, 0x7f, 0xe0, 0x1, 0xff, 0x9f,
    0xf0, 0x0, 0x3f, 0xe7, 0xfc, 0x0, 0xf, 0xf9,
    0xff, 0x0, 0x3, 0xfe, 0xff, 0xc0, 0x0, 0xff,
    0xff, 0xe0, 0x0, 0x1f, 0xff, 0xf8, 0x0, 0x7,
    0xff, 0xfe, 0x0, 0x1, 0xff, 0xff, 0x80, 0x0,
    0x7f, 0xff, 0xe0, 0x0, 0x1f, 0xff, 0xf8, 0x0,
    0x7, 0xff, 0xfe, 0x0, 0x1, 0xff, 0xff, 0x80,
    0x0, 0x7f, 0xff, 0xe0, 0x0, 0x1f, 0xff, 0xf8,
    0x0, 0x7, 0xff, 0xfe, 0x0, 0x1, 0xff, 0xff,
    0x80, 0x0, 0x7f, 0xff, 0xe0, 0x0, 0x1f, 0xff,
    0xf8, 0x0, 0xf, 0xfd, 0xff, 0x0, 0x3, 0xfe,
    0x7f, 0xc0, 0x0, 0xff, 0x9f, 0xf0, 0x0, 0x3f,
    0xe7, 0xfe, 0x0, 0x1f, 0xf9, 0xff, 0x80, 0x7,
    0xfe, 0x3f, 0xf0, 0x3, 0xff, 0xf, 0xfe, 0x1,
    0xff, 0xc1, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff,
    0xff, 0xf8, 0xf, 0xff, 0xff, 0xfc, 0x3, 0xff,
    0xff, 0xff, 0x0, 0x7f, 0xff, 0xff, 0x80, 0xf,
    0xff, 0xff, 0xc0, 0x1, 0xff, 0xff, 0xe0, 0x0,
    0x1f, 0xff, 0xe0, 0x0, 0x1, 0xff, 0xe0, 0x0,
    0x0, 0x3, 0x0, 0x0,

    /* U+0031 "1" */
    0x7f, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff,
    0x7f, 0xff, 0x1, 0xff, 0x1, 0xff, 0x1, 0xff,
    0x1, 0xff, 0x1, 0xff, 0x1, 0xff, 0x1, 0xff,
    0x1, 0xff, 0x1, 0xff, 0x1, 0xff, 0x1, 0xff,
    0x1, 0xff, 0x1, 0xff, 0x1, 0xff, 0x1, 0xff,
    0x1, 0xff, 0x1, 0xff, 0x1, 0xff, 0x1, 0xff,
    0x1, 0xff, 0x1, 0xff, 0x1, 0xff, 0x1, 0xff,
    0x1, 0xff, 0x1, 0xff, 0x1, 0xff, 0x1, 0xff,
    0x1, 0xff, 0x1, 0xff, 0x1, 0xff, 0x1, 0xff,
    0x1, 0xff, 0x1, 0xff, 0x1, 0xff, 0x1, 0xff,
    0x1, 0xff, 0x1, 0xff, 0x0, 0xfe,

    /* U+0032 "2" */
    0x0, 0x7, 0xfc, 0x0, 0x0, 0xf, 0xff, 0xf0,
    0x0, 0xf, 0xff, 0xff, 0x0, 0xf, 0xff, 0xff,
    0xe0, 0x7, 0xff, 0xff, 0xfc, 0x3, 0xff, 0xff,
    0xff, 0x81, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xff,
    0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0x8f, 0xff,
    0x1, 0xff, 0xe7, 0xff, 0x0, 0x1f, 0xf9, 0xff,
    0x80, 0x3, 0xff, 0x7f, 0xc0, 0x0, 0x7f, 0xdf,
    0xf0, 0x0, 0x1f, 0xf7, 0xfc, 0x0, 0x7, 0xfd,
    0xfe, 0x0, 0x1, 0xff, 0x0, 0x0, 0x0, 0x7f,
    0xc0, 0x0, 0x0, 0x3f, 0xf0, 0x0, 0x0, 0x1f,
    0xf8, 0x0, 0x0, 0xf, 0xfe, 0x0, 0x0, 0x7,
    0xff, 0x80, 0x0, 0x3, 0xff, 0xc0, 0x0, 0x3,
    0xff, 0xe0, 0x0, 0x1, 0xff, 0xf0, 0x0, 0x0,
    0xff, 0xfc, 0x0, 0x0, 0xff, 0xfe, 0x0, 0x0,
    0x7f, 0xff, 0x0, 0x0, 0x7f, 0xff, 0x0, 0x0,
    0x3f, 0xff, 0x80, 0x0, 0x1f, 0xff, 0xc0, 0x0,
    0x1f, 0xff, 0xc0, 0x0, 0xf, 0xff, 0xe0, 0x0,
    0x7, 0xff, 0xf0, 0x0, 0x3, 0xff, 0xf0, 0x0,
    0x0, 0xff, 0xf8, 0x0, 0x0, 0x7f, 0xf8, 0x0,
    0x0, 0x3f, 0xfc, 0x0, 0x0, 0xf, 0xfe, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xdf, 0xff,
    0xff, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xfd, 0xff,
    0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xdf,
    0xff, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xf8,

    /* U+0033 "3" */
    0x0, 0xf, 0xf8, 0x0, 0x0, 0x1f, 0xff, 0xc0,
    0x0, 0x1f, 0xff, 0xfc, 0x0, 0xf, 0xff, 0xff,
    0xc0, 0x7, 0xff, 0xff, 0xf8, 0x3, 0xff, 0xff,
    0xfe, 0x1, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff,
    0xff, 0xf8, 0x3f, 0xff, 0xff, 0xfe, 0x1f, 0xfe,
    0x3, 0xff, 0xc7, 0xff, 0x0, 0x3f, 0xf1, 0xff,
    0x80, 0x7, 0xfc, 0x7f, 0xc0, 0x1, 0xff, 0x1f,
    0xf0, 0x0, 0x7f, 0xc3, 0xf8, 0x0, 0x1f, 0xf0,
    0x0, 0x0, 0xf, 0xfc, 0x0, 0x0, 0x7, 0xff,
    0x0, 0x0, 0x3, 0xff, 0x80, 0x1, 0xff, 0xff,
    0xe0, 0x0, 0x7f, 0xff, 0xf0, 0x0, 0x3f, 0xff,
    0xfc, 0x0, 0xf, 0xff, 0xfe, 0x0, 0x3, 0xff,
    0xff, 0x80, 0x0, 0xff, 0xff, 0xf0, 0x0, 0x3f,
    0xff, 0xfe, 0x0, 0x7, 0xff, 0xff, 0xc0, 0x1,
    0xff, 0xff, 0xf0, 0x0, 0x0, 0x1f, 0xfe, 0x0,
    0x0, 0x1, 0xff, 0x80, 0x0, 0x0, 0x3f, 0xf0,
    0x0, 0x0, 0xf, 0xfc, 0xfc, 0x0, 0x1, 0xff,
    0x7f, 0x80, 0x0, 0x7f, 0xff, 0xf0, 0x0, 0x1f,
    0xff, 0xfc, 0x0, 0x7, 0xff, 0xff, 0x80, 0x3,
    0xff, 0x7f, 0xf0, 0x1, 0xff, 0xdf, 0xfe, 0x0,
    0xff, 0xe3, 0xff, 0xff, 0xff, 0xf8, 0xff, 0xff,
    0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0x3, 0xff,
    0xff, 0xff, 0x80, 0x7f, 0xff, 0xff, 0xc0, 0xf,
    0xff, 0xff, 0xe0, 0x1, 0xff, 0xff, 0xf0, 0x0,
    0x1f, 0xff, 0xf0, 0x0, 0x1, 0xff, 0xf0, 0x0,
    0x0, 0x3, 0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x3f, 0xf0, 0x0, 0x0, 0xf, 0xfe,
    0x0, 0x0, 0x7, 0xff, 0x80, 0x0, 0x3, 0xff,
    0xe0, 0x0, 0x0, 0xff, 0xf8, 0x0, 0x0, 0x7f,
    0xfe, 0x0, 0x0, 0x3f, 0xff, 0x80, 0x0, 0xf,
    0xff, 0xe0, 0x0, 0x7, 0xff, 0xf8, 0x0, 0x3,
    0xff, 0xfe, 0x0, 0x0, 0xff, 0xff, 0x80, 0x0,
    0x7f, 0xff, 0xe0, 0x0, 0x3f, 0xff, 0xf8, 0x0,
    0xf, 0xff, 0xfe, 0x0, 0x7, 0xfe, 0xff, 0x80,
    0x3, 0xff, 0xbf, 0xe0, 0x0, 0xff, 0xcf, 0xf8,
    0x0, 0x7f, 0xe3, 0xfe, 0x0, 0x3f, 0xf8, 0xff,
    0x80, 0xf, 0xfc, 0x3f, 0xe0, 0x7, 0xfe, 0xf,
    0xf8, 0x1, 0xff, 0x83, 0xfe, 0x0, 0xff, 0xc0,
    0xff, 0x80, 0x7f, 0xe0, 0x3f, 0xe0, 0x1f, 0xf0,
    0xf, 0xf8, 0xf, 0xfc, 0x3, 0xfe, 0x7, 0xfe,
    0x0, 0xff, 0x81, 0xff, 0xff, 0xff, 0xfe, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff,
    0xfe, 0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0x3,
    0xfe, 0x0, 0x0, 0x0, 0xff, 0x80, 0x0, 0x0,
    0x3f, 0xe0, 0x0, 0x0, 0xf, 0xf8, 0x0, 0x0,
    0x3, 0xfe, 0x0, 0x0, 0x0, 0xff, 0x80, 0x0,
    0x0, 0x3f, 0xe0, 0x0, 0x0, 0xf, 0xf8, 0x0,
    0x0, 0x3, 0xfe, 0x0, 0x0, 0x0, 0x7f, 0x0,

    /* U+0035 "5" */
    0x3, 0xff, 0xff, 0xfe, 0x0, 0xff, 0xff, 0xff,
    0xc0, 0x7f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff,
    0xfc, 0x7, 0xff, 0xff, 0xff, 0x1, 0xff, 0xff,
    0xff, 0xc0, 0x7f, 0xff, 0xff, 0xf0, 0x1f, 0xff,
    0xff, 0xfc, 0x7, 0xff, 0xff, 0xfe, 0x3, 0xff,
    0x0, 0x0, 0x0, 0xff, 0xc0, 0x0, 0x0, 0x3f,
    0xf0, 0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0x3,
    0xfe, 0x0, 0x0, 0x0, 0xff, 0xff, 0xc0, 0x0,
    0x3f, 0xff, 0xfe, 0x0, 0x1f, 0xff, 0xff, 0xe0,
    0x7, 0xff, 0xff, 0xfc, 0x1, 0xff, 0xff, 0xff,
    0x80, 0x7f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff,
    0xfe, 0x7, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff,
    0xff, 0xf0, 0x3f, 0xf0, 0x1f, 0xfe, 0x3, 0xf0,
    0x3, 0xff, 0x80, 0x78, 0x0, 0x7f, 0xe0, 0x0,
    0x0, 0xf, 0xfc, 0x0, 0x0, 0x1, 0xff, 0x0,
    0x0, 0x0, 0x7f, 0xc0, 0x0, 0x0, 0x1f, 0xf0,
    0x0, 0x0, 0x7, 0xfd, 0xfe, 0x0, 0x1, 0xff,
    0xff, 0x80, 0x0, 0x7f, 0xff, 0xf0, 0x0, 0x3f,
    0xff, 0xfc, 0x0, 0xf, 0xfd, 0xff, 0x80, 0x7,
    0xfe, 0x7f, 0xf0, 0x3, 0xff, 0x9f, 0xff, 0x3,
    0xff, 0xe3, 0xff, 0xff, 0xff, 0xf0, 0xff, 0xff,
    0xff, 0xf8, 0x1f, 0xff, 0xff, 0xfe, 0x3, 0xff,
    0xff, 0xff, 0x0, 0x7f, 0xff, 0xff, 0x80, 0xf,
    0xff, 0xff, 0xc0, 0x0, 0xff, 0xff, 0xe0, 0x0,
    0x1f, 0xff, 0xe0, 0x0, 0x0, 0x7f, 0xc0, 0x0,

    /* U+0036 "6" */
    0x0, 0x3, 0xfe, 0x0, 0x0, 0x3, 0xff, 0xf8,
    0x0, 0x1, 0xff, 0xff, 0xc0, 0x0, 0x7f, 0xff,
    0xfc, 0x0, 0x3f, 0xff, 0xff, 0xc0, 0xf, 0xff,
    0xff, 0xfc, 0x1, 0xff, 0xff, 0xff, 0xc0, 0x7f,
    0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0x83,
    0xff, 0xc0, 0xff, 0xf0, 0xff, 0xe0, 0xf, 0xfe,
    0x1f, 0xf8, 0x0, 0xff, 0xe3, 0xfe, 0x0, 0xf,
    0xfc, 0xff, 0xc0, 0x1, 0xff, 0x1f, 0xf0, 0x0,
    0x0, 0x3, 0xfe, 0x1f, 0xe0, 0x0, 0x7f, 0xdf,
    0xff, 0x80, 0x1f, 0xff, 0xff, 0xfc, 0x3, 0xff,
    0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xfe, 0xf,
    0xff, 0xff, 0xff, 0xe1, 0xff, 0xff, 0xff, 0xfe,
    0x3f, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xff,
    0xfc, 0xff, 0xfe, 0x7, 0xff, 0xdf, 0xff, 0x0,
    0x3f, 0xfb, 0xff, 0xc0, 0x3, 0xff, 0x7f, 0xf0,
    0x0, 0x3f, 0xff, 0xfc, 0x0, 0x7, 0xff, 0xff,
    0x80, 0x0, 0x7f, 0xff, 0xf0, 0x0, 0xf, 0xfb,
    0xfe, 0x0, 0x1, 0xff, 0x7f, 0xc0, 0x0, 0x3f,
    0xef, 0xf8, 0x0, 0x7, 0xfd, 0xff, 0x80, 0x1,
    0xff, 0x9f, 0xf0, 0x0, 0x3f, 0xe3, 0xff, 0x0,
    0xf, 0xfc, 0x7f, 0xf8, 0x7, 0xff, 0x87, 0xff,
    0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xfc, 0xf,
    0xff, 0xff, 0xff, 0x0, 0xff, 0xff, 0xff, 0xc0,
    0xf, 0xff, 0xff, 0xf0, 0x0, 0xff, 0xff, 0xfc,
    0x0, 0xf, 0xff, 0xff, 0x0, 0x0, 0xff, 0xff,
    0x80, 0x0, 0x3, 0xff, 0xc0, 0x0, 0x0, 0x3,
    0x0, 0x0,

    /* U+0037 "7" */
    0x7f, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x7f, 0xe0, 0x0, 0x0, 0x1f, 0xf8, 0x0,
    0x0, 0xf, 0xfe, 0x0, 0x0, 0x3, 0xff, 0x0,
    0x0, 0x1, 0xff, 0xc0, 0x0, 0x0, 0x7f, 0xe0,
    0x0, 0x0, 0x1f, 0xf8, 0x0, 0x0, 0xf, 0xfc,
    0x0, 0x0, 0x3, 0xff, 0x0, 0x0, 0x1, 0xff,
    0xc0, 0x0, 0x0, 0x7f, 0xe0, 0x0, 0x0, 0x3f,
    0xf8, 0x0, 0x0, 0xf, 0xfc, 0x0, 0x0, 0x3,
    0xff, 0x0, 0x0, 0x1, 0xff, 0x80, 0x0, 0x0,
    0x7f, 0xe0, 0x0, 0x0, 0x3f, 0xf8, 0x0, 0x0,
    0xf, 0xfc, 0x0, 0x0, 0x7, 0xff, 0x0, 0x0,
    0x1, 0xff, 0x80, 0x0, 0x0, 0xff, 0xe0, 0x0,
    0x0, 0x3f, 0xf0, 0x0, 0x0, 0xf, 0xfc, 0x0,
    0x0, 0x7, 0xff, 0x0, 0x0, 0x1, 0xff, 0x80,
    0x0, 0x0, 0xff, 0xe0, 0x0, 0x0, 0x3f, 0xf0,
    0x0, 0x0, 0x1f, 0xfc, 0x0, 0x0, 0x7, 0xfe,
    0x0, 0x0, 0x1, 0xff, 0x80, 0x0, 0x0, 0xff,
    0xe0, 0x0, 0x0, 0x3f, 0xf0, 0x0, 0x0, 0x1f,
    0xfc, 0x0, 0x0, 0x7, 0xfe, 0x0, 0x0, 0x3,
    0xff, 0x80, 0x0, 0x0, 0xff, 0xc0, 0x0, 0x0,
    0x3f, 0xf0, 0x0, 0x0, 0x7, 0xf8, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0xf, 0xfe, 0x0, 0x0, 0xf, 0xff, 0xf8,
    0x0, 0x7, 0xff, 0xff, 0xc0, 0x1, 0xff, 0xff,
    0xfc, 0x0, 0x7f, 0xff, 0xff, 0xc0, 0x1f, 0xff,
    0xff, 0xfc, 0x3, 0xff, 0xff, 0xff, 0x80, 0xff,
    0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0x7,
    0xff, 0x80, 0xff, 0xf0, 0xff, 0xc0, 0x7, 0xfe,
    0x1f, 0xf0, 0x0, 0x7f, 0xc3, 0xfe, 0x0, 0xf,
    0xf8, 0x7f, 0xc0, 0x1, 0xff, 0xf, 0xf8, 0x0,
    0x3f, 0xe1, 0xff, 0x80, 0xf, 0xfc, 0x1f, 0xfc,
    0x7, 0xff, 0x3, 0xff, 0xff, 0xff, 0xe0, 0x3f,
    0xff, 0xff, 0xfc, 0x7, 0xff, 0xff, 0xff, 0x0,
    0x7f, 0xff, 0xff, 0xc0, 0x7, 0xff, 0xff, 0xf0,
    0x3, 0xff, 0xff, 0xff, 0x0, 0xff, 0xff, 0xff,
    0xf0, 0x1f, 0xff, 0xff, 0xff, 0x7, 0xff, 0xff,
    0xff, 0xf1, 0xff, 0xf0, 0x1f, 0xfe, 0x3f, 0xf8,
    0x0, 0xff, 0xe7, 0xfe, 0x0, 0xf, 0xfd, 0xff,
    0x80, 0x0, 0xff, 0xff, 0xe0, 0x0, 0xf, 0xff,
    0xfc, 0x0, 0x1, 0xff, 0xff, 0x80, 0x0, 0x3f,
    0xff, 0xf0, 0x0, 0x7, 0xff, 0xfe, 0x0, 0x0,
    0xff, 0xff, 0xe0, 0x0, 0x3f, 0xff, 0xfe, 0x0,
    0xf, 0xfe, 0xff, 0xe0, 0x3, 0xff, 0x9f, 0xff,
    0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xfc, 0x3f,
    0xff, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 0xe0,
    0x3f, 0xff, 0xff, 0xf8, 0x3, 0xff, 0xff, 0xfe,
    0x0, 0x3f, 0xff, 0xff, 0x80, 0x1, 0xff, 0xff,
    0xc0, 0x0, 0xf, 0xff, 0xe0, 0x0, 0x0, 0x2,
    0x0, 0x0,

    /* U+0039 "9" */
    0x0, 0x7, 0xfc, 0x0, 0x0, 0x7, 0xff, 0xf0,
    0x0, 0x3, 0xff, 0xff, 0x0, 0x1, 0xff, 0xff,
    0xf8, 0x0, 0x7f, 0xff, 0xff, 0x80, 0x1f, 0xff,
    0xff, 0xf8, 0x7, 0xff, 0xff, 0xff, 0x81, 0xff,
    0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xf,
    0xff, 0x81, 0xff, 0xe1, 0xff, 0xc0, 0xf, 0xfe,
    0x3f, 0xf0, 0x0, 0xff, 0xcf, 0xfc, 0x0, 0xf,
    0xf9, 0xff, 0x0, 0x1, 0xff, 0xbf, 0xe0, 0x0,
    0x1f, 0xf7, 0xfc, 0x0, 0x3, 0xfe, 0xff, 0x80,
    0x0, 0x7f, 0xdf, 0xf0, 0x0, 0xf, 0xff, 0xfe,
    0x0, 0x1, 0xff, 0xff, 0xe0, 0x0, 0x7f, 0xf7,
    0xfe, 0x0, 0x1f, 0xfe, 0xff, 0xe0, 0x7, 0xff,
    0xdf, 0xff, 0x3, 0xff, 0xf9, 0xff, 0xff, 0xff,
    0xff, 0x3f, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff,
    0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0x83, 0xff,
    0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xfe, 0x1,
    0xff, 0xff, 0xff, 0xc0, 0xf, 0xff, 0xdf, 0xf8,
    0x0, 0x3f, 0xc3, 0xfe, 0x0, 0x0, 0x0, 0x7f,
    0xc3, 0xfc, 0x0, 0x1f, 0xf8, 0xff, 0x80, 0x3,
    0xff, 0x1f, 0xf8, 0x0, 0xff, 0xc3, 0xff, 0x0,
    0x3f, 0xf8, 0x7f, 0xf8, 0xf, 0xff, 0x7, 0xff,
    0xff, 0xff, 0xc0, 0xff, 0xff, 0xff, 0xf8, 0xf,
    0xff, 0xff, 0xfe, 0x1, 0xff, 0xff, 0xff, 0x80,
    0x1f, 0xff, 0xff, 0xe0, 0x1, 0xff, 0xff, 0xf8,
    0x0, 0x1f, 0xff, 0xfe, 0x0, 0x0, 0xff, 0xff,
    0x0, 0x0, 0x7, 0xff, 0x80, 0x0, 0x0, 0x2,
    0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 636, .box_w = 34, .box_h = 48, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 444, .box_w = 16, .box_h = 47, .ofs_x = 5, .ofs_y = 1},
    {.bitmap_index = 298, .adv_w = 637, .box_w = 34, .box_h = 47, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 498, .adv_w = 637, .box_w = 34, .box_h = 48, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 702, .adv_w = 622, .box_w = 34, .box_h = 47, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 902, .adv_w = 636, .box_w = 34, .box_h = 47, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 1102, .adv_w = 636, .box_w = 35, .box_h = 48, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1312, .adv_w = 636, .box_w = 34, .box_h = 47, .ofs_x = 3, .ofs_y = 1},
    {.bitmap_index = 1512, .adv_w = 636, .box_w = 35, .box_h = 48, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1722, .adv_w = 636, .box_w = 35, .box_h = 48, .ofs_x = 2, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t lv_gaoel_num_font_64 = {
#else
lv_font_t lv_gaoel_num_font_64 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 48,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -5,
    .underline_thickness = 3,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if LV_GAOEL_NUM_FONT_64*/

