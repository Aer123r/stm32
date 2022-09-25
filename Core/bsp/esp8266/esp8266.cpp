//
// Created by WuGaoyuan on 2022/9/16.
//

#include <cstdio>
#include "esp8266.h"
#include "Serial.h"
#include "string.h"
#include "stm32f1xx_hal.h"

esp8266::esp8266(UART_HandleTypeDef *huart,MODE mode):mode(mode),huart(huart) {
}
esp8266::~esp8266() {}

void esp8266::init() {
    const char* AT = Serial::Print("AT+CWMODE=%d\r\n",mode);
    uint8_t len = strlen(AT);
    HAL_UART_Transmit(huart,( uint8_t*)AT,len,1000);
    HAL_Delay(20);
    reset();
}
void esp8266::reset() {
    const char* AT = Serial::Print("AT+RST\r\n");
    uint8_t len = strlen(AT);
    HAL_UART_Transmit(huart,( uint8_t*)AT,len,1000);
}
void esp8266::joinWifi(const char *wifi, const char *password) {
    const char* AT = Serial::Print("AT+CWJAP=\"%s\", \"%s\r\n\"",wifi,password);
    uint8_t len = strlen(AT);
    HAL_UART_Transmit(huart,( uint8_t*)AT,len,1000);
}
void esp8266::test() {
//    HAL_UART_Transmit(huart,(const uint8_t *)"AT\r\n",4,1000);
    Serial::Transmit(huart,"AT\\r\\n");
}
void esp8266::TCPClient(const char *ip, uint16_t port) {

}