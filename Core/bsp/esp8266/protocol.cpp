//
// Created by WuGaoyuan on 2022/9/13.
//

#include <cstdlib>
#include "protocol.h"
#include "string"
using namespace std;
void protocol::parse() {
    if(receive_data[70]!='$'){
        return;
    }
    printf("接收到的数据是%s\n",receive_data);
    string str =(const char*) receive_data;

    string Matcher = "0123456789ABCD";
    for(int i=0;i< str.length();i=i+5){
        servo_angle[i] =(Matcher.find(str[i+2])) *16+Matcher.find(str[i+3]);
        printf("%d\n",servo_angle[i]);
    }

}