#ifndef _AT24C02_H
#define _AT24C02_H

#include "system.h"
#include "systick.h"
#include "iic.h"

void AT24C02_Init();
void AT24C02_WriteOneByte(u8 add,u8 data);
u8 AT24C02_ReadOneByte(u8 add);
u8 AT24C02_Check();

#endif
