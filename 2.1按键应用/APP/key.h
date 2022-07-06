#ifndef _KEY_H
#define _KEY_H

#include "system.h"
#include "systick.h"

#define KEY_UP_PORT_RCC        RCC_APB2Periph_GPIOA
#define KEY012_PORT_RCC        RCC_APB2Periph_GPIOE


#define KEY_UP_PORT            GPIOA
#define KEY012_PORT            GPIOE

#define KEY_UP_Pin             GPIO_Pin_0
#define KEY0_Pin               GPIO_Pin_4
#define KEY1_Pin               GPIO_Pin_3
#define KEY2_Pin               GPIO_Pin_2

#define KEYUP                  PAin(0)
#define KEY0                   PEin(4)
#define KEY1                   PEin(3)
#define KEY2                   PEin(2)



void Key_Init();
u8 key_scan();

#endif