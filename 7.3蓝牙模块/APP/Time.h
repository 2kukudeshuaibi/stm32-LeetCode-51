#ifndef _Time_H
#define _Time_H


#include "system.h"
#include "LED.h"
#include "beep.h"
#include "usart3.h"

void TIM4_Init(u16 per,u16 pres);
void TIM7_Init(u16 per,u16 pres);

#endif
