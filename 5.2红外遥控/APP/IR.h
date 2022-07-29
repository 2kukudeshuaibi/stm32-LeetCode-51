#ifndef _IR_H
#define _IR_H

#include "system.h"
#include "systick.h"
#include "LED.h"
#include "usart.h"

void IR_Init();
u8 Get_data_flag();
u8 Get_repeater_flag();
u8 Get_command();
u8 Get_add();

#endif