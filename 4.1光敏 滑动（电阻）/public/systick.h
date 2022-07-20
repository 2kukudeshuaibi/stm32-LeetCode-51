#ifndef _systick_H
#define _systick_H

#include "system.h"

void SysTick_Init(unsigned char SYS);
void delay_us(unsigned int us);
void delay_ms(unsigned int ms);


#endif