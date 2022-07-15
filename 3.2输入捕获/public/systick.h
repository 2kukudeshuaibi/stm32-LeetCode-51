#ifndef _systick_H
#define _systick_H

#include "system.h"

void systick_Init(unsigned char SYSCLK);

void delay_us(unsigned int nus);
void delay_ms(unsigned int nms);
void delay_s(unsigned int ns);


#endif
