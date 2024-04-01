#ifndef LED_H
#define LED_H

#include "hal_conf.h"

class LED {
public:
    LED(GPIO_TypeDef* gpioPort, uint16_t gpioPin);
    
    void on();
    void off();
    void toggle();
    
private:
    GPIO_TypeDef* m_gpioPort;
    uint16_t m_gpioPin;
};

#endif // LED_H
