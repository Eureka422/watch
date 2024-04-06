#ifndef __TOUCH_H
#define __TOUCH_H

#include "hal_conf.h"

class Touch
{
    typedef struct
    {
        GPIO_TypeDef *gpio = GPIOB;
        uint16_t res = GPIO_PIN_5;
        uint16_t irq = GPIO_PIN_4;
    } pin_t;
    typedef struct
    {
        uint8_t addr = 0x38;
        I2C_HandleTypeDef hi2c;
    } per_t;
    typedef struct
    {
        uint8_t event = 0;
        uint8_t id = 0;
        int16_t x = -1;
        int16_t y = -1;
    } TouchPoint_t;
    
public:
    TouchPoint_t _tp;
    pin_t pin;
    per_t per;
public:
    Touch(void);
    ~Touch() {};

    void init(void);
    void read(void);
    bool is_pressed(void);
    void get_tp(int16_t *x, int16_t *y);
};




#endif // __TOUCH_H