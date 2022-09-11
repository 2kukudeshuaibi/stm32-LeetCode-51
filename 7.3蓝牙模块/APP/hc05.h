#ifndef _HC05_H
#define _HC05_H

#include "system.h"
#include "systick.h"
#include "LED.h"
#include "usart3.h"
#include "usart.h"

#define HC05_KEY PAout(4)
#define HC05_LED PAin(15)

u8 HC05_Init();
u8 HC05_Get_Role();
u8 HC05_Set_Cmd(u8* str);

#endif
