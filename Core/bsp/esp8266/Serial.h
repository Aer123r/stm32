//
// Created by WuGaoyuan on 2022/9/16.
//

#ifndef OLED_CPP_SERIAL_H
#define OLED_CPP_SERIAL_H

#include "stm32f1xx_hal.h"

class Serial {
public:
    static const char* Print(const char *fmt, ...);
    static inline void Transmit(UART_HandleTypeDef *huart,const char* str){
        uint8_t len = sizeof (str)/sizeof (str[0]);
        HAL_UART_Transmit(huart,(uint8_t *)str,len,1000);
    }
};


#endif //OLED_CPP_SERIAL_H
