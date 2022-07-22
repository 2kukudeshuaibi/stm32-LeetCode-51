#ifndef _key_H
#define _key_H

#include "system.h"
#include "systick.h"

#define KEY_0 GPIO_Pin_4
#define KEY_1 GPIO_Pin_3
#define KEY_2 GPIO_Pin_2


#define KEY0 PEin(4)
#define KEY1 PEin(3)
#define KEY2 PEin(2)


void key_Init();
u8 key_scan(u8 mode);

#endif