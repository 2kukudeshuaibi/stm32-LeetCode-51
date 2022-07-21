#ifndef _systick_H
#define _systick_H

#include "system.h"
void systick_Init(u8 SYS);
void delay_us(unsigned int us);
void delay_ms(unsigned int ms);



#endif