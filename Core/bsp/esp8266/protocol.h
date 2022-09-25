//
// Created by WuGaoyuan on 2022/9/13.
//

#ifndef ROBOT02_PROTOCOL_H
#define ROBOT02_PROTOCOL_H


#include <cstdint>

class protocol {
private:


public:
    void parse();
    uint8_t servo_angle[14];
    uint8_t receive_data[100];
};


#endif //ROBOT02_PROTOCOL_H
