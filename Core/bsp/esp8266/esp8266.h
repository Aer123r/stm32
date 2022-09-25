//
// Created by WuGaoyuan on 2022/9/16.
//

#ifndef OLED_CPP_ESP8266_H
#define OLED_CPP_ESP8266_H

#include "stm32f1xx_hal.h"



typedef enum {
    STA=1,
    AP=2,
    AP_STA=3,
    HTTP=1,
}MODE;
class esp8266 {
private:

    MODE mode;
    UART_HandleTypeDef *huart;
public:
    esp8266(UART_HandleTypeDef *huart,MODE mode);
    ~esp8266();
    void init();
    void reset();
    void joinWifi(const char* wifi,const char* password);
    void TCPClient(const char* ip,uint16_t port);
    void test();
};


#endif //OLED_CPP_ESP8266_H
