//
// Created by WuGaoyuan on 2022/9/16.
//


#include <cstdarg>
#include <cstdio>
#include <cstring>
#include "Serial.h"
/**
 *
 * @param fmt
 * @param ...
 * @return
 * @description 格式化转化字符串,方便到吹水
 */
const char *Serial::Print(const char *fmt, ...) {
    static char printf_buf[1024];
    va_list args;
    int printed;
    va_start(args, fmt);
    printed = vsprintf(printf_buf, fmt, args);
    va_end(args);
    // puts(printf_buf);
    return (const char*)printf_buf;
}
