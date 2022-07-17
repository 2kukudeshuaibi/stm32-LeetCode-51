#ifndef _systick_H
#define _systick_H

#include "system.h"
void systick_init(unsigned char SYS);
void delay_us(unsigned int nus);
void delay_ms(unsigned int nms);

void delay_s(unsigned int s);
#endif