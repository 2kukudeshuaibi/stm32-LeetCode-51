#ifndef _key_H
#define _key_H

#include "system.h"
#include "systick.h"

#define  KEY012_PORT   RCC_APB2Periph_GPIOE
#define  KEY0_PIN	   GPIO_Pin_4
#define  KEY1_PIN	   GPIO_Pin_3
#define  KEY2_PIN      GPIO_Pin_2


#define KEY0		   PEin(4)
#define KEY1           PEin(3)
#define KEY2           PEin(2)

void KEY_Init();
u8 key_scan();

#endif