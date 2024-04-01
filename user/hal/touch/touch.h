#ifndef __TOUCH_H
#define __TOUCH_H

#include "hal_conf.h"

class Touch
{
    typedef struct
    {
        GPIO_TypeDef *gpio = nullptr;
        uint16_t res = 0;
        uint16_t irq = 0;
    } pin_t;
    typedef struct
    {
        I2C_HandleTypeDef hi2c;
    } per_t;
    typedef struct
    {
        uint16_t x = 0;
        uint16_t y = 0;
    } TouchPoint_t;
public:
    TouchPoint_t tp;
    pin_t pin;
public:
    Touch(void);
    ~Touch() {};
};




#endif // __TOUCH_H