#include "display.h"

static uint16_t disp_buf[DISPLAY_WIDTH * buf_height];

Display::Display(uint16_t width, uint16_t height)
    : _width(width), _height(height), pin(), per()
{
    /* 初始化GPIO */
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = pin.pwr_en | pin.res;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(pin.gpio, &GPIO_InitStruct);
    HAL_GPIO_WritePin(pin.gpio, pin.pwr_en | pin.res, GPIO_PIN_SET);

    /* 初始化QSPI IO */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /**QUADSPI GPIO Configuration
    PA6     ------> QUADSPI_BK2_IO0
    PA7     ------> QUADSPI_BK2_IO1
    PC4     ------> QUADSPI_BK2_IO2
    PC5     ------> QUADSPI_BK2_IO3
    PB1     ------> QUADSPI_CLK
    PC11     ------> QUADSPI_BK2_NCS
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_QSPI;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_QSPI;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* 初始化QSPI */
    __HAL_RCC_QSPI_CLK_ENABLE();
    per.hqspi.Instance = QUADSPI;
    per.hqspi.Init.ClockPrescaler = 9;
    per.hqspi.Init.FifoThreshold = 32;
    per.hqspi.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_NONE;
    per.hqspi.Init.FlashSize = 22;
    per.hqspi.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_1_CYCLE;
    per.hqspi.Init.ClockMode = QSPI_CLOCK_MODE_0;
    per.hqspi.Init.FlashID = QSPI_FLASH_ID_2;
    per.hqspi.Init.DualFlash = QSPI_DUALFLASH_DISABLE;
    HAL_QSPI_Init(&per.hqspi);

    /* 初始化QSPI命令 */
    per.cmd.Instruction = 0x32;
    per.cmd.Address = 0x000000;
    per.cmd.AddressSize = QSPI_ADDRESS_24_BITS;
    per.cmd.DummyCycles = 0;
    per.cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    per.cmd.AddressMode = QSPI_ADDRESS_1_LINE;
    per.cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    per.cmd.DataMode = QSPI_DATA_1_LINE;
    per.cmd.NbData = 0;
    per.cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
    per.cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    per.cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

}

void Display::qspi_write_cmd(uint8_t addr, uint8_t *data, uint32_t size)
{
    per.cmd.Instruction = 0x02;
    per.cmd.Address = addr << 8;
    per.cmd.DataMode = size > 0 ? QSPI_DATA_1_LINE : QSPI_DATA_NONE;
    per.cmd.NbData = size;
    HAL_QSPI_Command(&per.hqspi, &per.cmd, 100);
    if (size > 0)
    {
        HAL_QSPI_Transmit(&per.hqspi, data, 100);
    }
}

void Display::qspi_write_data(uint8_t addr, uint8_t *data, uint32_t size)
{
    per.cmd.Instruction = 0x32;
    per.cmd.Address = addr << 8;
    per.cmd.DataMode = QSPI_DATA_4_LINES;
    per.cmd.NbData = size;
    HAL_QSPI_Command(&per.hqspi, &per.cmd, 100);
    HAL_QSPI_Transmit(&per.hqspi, data, HAL_QPSI_TIMEOUT_DEFAULT_VALUE);
}


/**
 * @brief Initializes the display.
 * 
 * This function initializes the display by performing the following steps:
 * 1. Sets the RESET pin to LOW for 10 milliseconds.
 * 2. Sets the RESET pin to HIGH.
 * 3. Executes a series of initialization commands stored in the `init_cmds` array.
 * 
 * @note This function assumes that the GPIO pins and QSPI interface have been properly configured.
 */
void Display::init(void)
{

    HAL_GPIO_WritePin(pin.gpio, GPIO_PIN_2, GPIO_PIN_RESET); // RESET---LOW
    HAL_Delay(10);
    HAL_GPIO_WritePin(pin.gpio, GPIO_PIN_2, GPIO_PIN_SET); // RESET---HIGH
    HAL_Delay(50);
    for (uint32_t i = 0; i < sizeof(init_cmds) / sizeof(init_cmd_t); i++)
    {
        qspi_write_cmd(init_cmds[i].cmd, init_cmds[i].data, init_cmds[i].data_bytes);
        HAL_Delay(init_cmds[i].delay_ms);
    }
}

void Display::set_window(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    uint8_t data[4];
    data[0] = x1 >> 8;
    data[1] = x1 & 0xFF;
    data[2] = x2 >> 8;
    data[3] = x2 & 0xFF;
    qspi_write_cmd(0x2a, data, 4);
    data[0] = y1 >> 8;
    data[1] = y1 & 0xFF;
    data[2] = y2 >> 8;
    data[3] = y2 & 0xFF;
    qspi_write_cmd(0x2b, data, 4);
}

/**
 * Fills a rectangular area on the display with a specified color.
 *
 * @param x1 The starting x-coordinate of the area.
 * @param y1 The starting y-coordinate of the area.
 * @param x2 The ending x-coordinate of the area.
 * @param y2 The ending y-coordinate of the area.
 * @param color The color to fill the area with.
 */
void Display::fill_area(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
    uint32_t size = (x2 - x1 + 1) * (y2 - y1 + 1);
    size = (size >> 1) << 1;
    set_window(x1, y1, x2, y2);
    for (uint32_t i = 0; i < size; i++)
    {
        disp_buf[i] = color;
    }
    qspi_write_data(0x2C, (uint8_t *)disp_buf - 1, size*2);
}