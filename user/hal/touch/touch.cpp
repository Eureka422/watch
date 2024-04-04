#include "touch.h"

Touch::Touch(void)
: _tp(), pin(), per()
{
    /* 初始化GPIO */
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    /* 初始化外部中断 */
    GPIO_InitStruct.Pin = pin.irq;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(pin.gpio, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = pin.res;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(pin.gpio, &GPIO_InitStruct);

    /* 初始化I2C */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    __HAL_RCC_I2C1_CLK_ENABLE();
    per.hi2c.Instance = I2C1;
    per.hi2c.Init.ClockSpeed = 100000;
    per.hi2c.Init.DutyCycle = I2C_DUTYCYCLE_2;
    per.hi2c.Init.OwnAddress1 = 0;
    per.hi2c.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    per.hi2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    per.hi2c.Init.OwnAddress2 = 0;
    per.hi2c.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    per.hi2c.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    HAL_I2C_Init(&per.hi2c);
}

void Touch::init(void)
{
    /* 初始化触摸屏 */
    // uint8_t data[2] = {0};
    HAL_GPIO_WritePin(pin.gpio, pin.res, GPIO_PIN_SET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(pin.gpio, pin.res, GPIO_PIN_RESET);
    HAL_Delay(20);
    HAL_GPIO_WritePin(pin.gpio, pin.res, GPIO_PIN_SET);
    HAL_Delay(50);

}

void Touch::read(void)
{
    /* 读取触摸点 */
    uint8_t data[7] = {0};
    HAL_I2C_Mem_Read(&per.hi2c, 0X71, 0x00, I2C_MEMADD_SIZE_8BIT, data, 7, 1000);
    if (data[2] != 0x00)
    {
        _tp.event = (data[3] >> 6) & 0x03;
        _tp.id = (data[5] >> 4) & 0x0f;
        _tp.x = ((data[3] & 0x0f) << 8) | data[4];
        _tp.y = ((data[5] & 0x0f) << 8) | data[6];
    }
}

void Touch::get_tp(TouchPoint_t *tp)
{
    /* 获取触摸点 */
    tp->x = _tp.x;
    tp->y = _tp.y;
    /* 清空触摸点 */
    _tp.x = -1;
    _tp.y = -1;
}

