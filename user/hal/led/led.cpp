#include "led.h"

LED::LED(GPIO_TypeDef* gpioPort, uint16_t gpioPin): m_gpioPort(gpioPort), m_gpioPin(gpioPin) {
        // Enable GPIO clock
        if (m_gpioPort == GPIOA) {
            __HAL_RCC_GPIOA_CLK_ENABLE();
        } else if (m_gpioPort == GPIOB) {
            __HAL_RCC_GPIOB_CLK_ENABLE();
        } else if (m_gpioPort == GPIOC) {
            __HAL_RCC_GPIOC_CLK_ENABLE();
        } else if (m_gpioPort == GPIOD) {
            __HAL_RCC_GPIOD_CLK_ENABLE();
        }
        // Configure GPIO pin as output
        GPIO_InitTypeDef GPIO_InitStruct;
        GPIO_InitStruct.Pin = m_gpioPin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        HAL_GPIO_Init(m_gpioPort, &GPIO_InitStruct);
    }

void LED::on() {
    HAL_GPIO_WritePin(m_gpioPort, m_gpioPin, GPIO_PIN_RESET);
}

void LED::off() {
    HAL_GPIO_WritePin(m_gpioPort, m_gpioPin, GPIO_PIN_SET);
}

void LED::toggle() {
    HAL_GPIO_TogglePin(m_gpioPort, m_gpioPin);
}
