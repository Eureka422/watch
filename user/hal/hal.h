/**
  ******************************************************************************
  * @file    hal.h
  * @brief   This file contains the headers of hardwares
 ******************************************************************************
  */
#ifndef __HAL_H__
#define __HAL_H__

#include "hal_conf.h"
#include "led/led.h"
#include "display/display.h"
#include "touch/touch.h"

namespace HAL
{
    extern LED led0;
    extern Display display;
    extern Touch touch;

    void init(void);
} // namespace HAL


#endif