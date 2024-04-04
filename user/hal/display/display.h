#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include "hal_conf.h"

#define buf_height 224
/**
 * @brief Structure representing an initialization command for the display.
 */
typedef struct
{
    uint8_t cmd;          /**< The command byte. */
    uint8_t *data;        /**< Pointer to the data buffer. */
    uint32_t data_bytes;  /**< The number of data bytes. */
    uint32_t delay_ms;    /**< The delay in milliseconds after sending the command. */
} init_cmd_t;

static const init_cmd_t init_cmds[] = {
    /*  {cmd, data, data_bytes, delay_ms}  */
    {0x11, (uint8_t[]){0x00}, 1, 100},     // sleep out
    // {0x44, (uint8_t[]){0x01, 0x66}, 2, 1}, // Write Tearing Effect Scan Line
    // {0x35, (uint8_t[]){0x00}, 0, 1},       // tearing effect on
    // {0x13, (uint8_t[]){0x00}, 0, 10},
    {0x3A, (uint8_t[]){0x55}, 1, 1},       // set pixel format:qspi 16bit
    {0x53, (uint8_t[]){0x20}, 1, 1},      // Write CTRL Display1:Brightness Control on , Display Dimming on
    {0x51, (uint8_t[]){0x00}, 1, 1},      // Write Display Brightness Value in Normal Mode
    {0x29, (uint8_t[]){0x00}, 0, 1},      // display on
    {0x51, (uint8_t[]){0xff}, 1, 1},       // Write Display Brightness, max: 0x3ff    
};

static const init_cmd_t partial_cmds[] = {
    {0x10, (uint8_t[]){0x00}, 0, 10},       // sleep in
    {0x12, (uint8_t[]){0x00}, 0, 10},       // partial mode
    {0x11, (uint8_t[]){0x00}, 0, 150},     // sleep out
    {0x22, (uint8_t[]){0x00}, 0, 10},      // pixel off
};

class Display
{
    typedef struct {
        GPIO_TypeDef *gpio = GPIOB;
        uint16_t pwr_en = GPIO_PIN_0;
        uint16_t res = GPIO_PIN_2;
    } pin_t;
    typedef struct {
        QSPI_HandleTypeDef hqspi;
        QSPI_CommandTypeDef cmd;
    } per_t;
public:
    uint16_t _width;
    uint16_t _height;
    pin_t pin;
    per_t per;
    
public:
    Display(uint16_t width, uint16_t height);
    ~Display(){}


    void qspi_write_cmd(uint8_t addr, uint8_t *data, uint32_t size);    // 使用QSPI发送命令, 111线模式
    void qspi_write_data(uint8_t addr, uint8_t *data, uint32_t size);   // 使用QSPI发送数据, 114线模式

    void init(void);    // 初始化显示屏
    void set_window(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);    // 设置显示窗口
    void fill_area(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t* color); // 填充矩形区域
};



#endif