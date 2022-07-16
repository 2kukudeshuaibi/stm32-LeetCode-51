#ifndef _touch_H
#define _touch_H

#include "system.h"
#include "systick.h"
#include "usart.h"

void TIM5_CH2_Input_Init(u16 arr,u16 pes);
void Touch_Reset();
u16 Touch_Get_Val();
u8 Touch_Key_Init(u8 psc);
u8 Touch_key_scan(u8 mode);

#endif