//
// Created by WuGaoyuan on 2022/9/11.
//
#include <cstdio>
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "tim.h"
#include "protocol.h"
#include "esp8266.h"
protocol protocol;
esp8266 wifi(&huart1,HTTP);
int mainApp()
{
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    wifi.test();
    HAL_Delay(20);
            __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,(0/90.0+0.5)*50);
    while(1)
    {
//        HAL_UART_Receive_IT(&huart1,protocol.receive_data,71);
        HAL_Delay(20);

    }
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance==USART1)
    {
        protocol.parse();
                __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_1,(protocol.servo_angle[0]/90.0+0.5)*50);
    }
}
