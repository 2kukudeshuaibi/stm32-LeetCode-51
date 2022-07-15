#ifndef _input_H
#define _input_H


#include "system.h"

void TIM5_Iniput_Init(u16 arr,u16 psc);

extern u8 TIM5_CH1_CAPTURE_STA;//输入捕获状态
extern u16 TIM5_CH1_CAPTURE_VAL;//输入捕获值


#endif
