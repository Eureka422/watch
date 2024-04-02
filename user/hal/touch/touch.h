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
    per_t per;
public:
    Touch(void);
    ~Touch() {};

    void init(void);
};




#endif // __TOUCH_H