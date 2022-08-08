#ifndef _ds18b20_H
#define _ds18b20_H

#include "stm32f10x.h" 
#include "system.h"
#include "Delay.h"


#define DS18B20_OUT PGout(11)
#define DS18B20_IN  PGin(11)

u8 DS18B20_Init();
void DS18B20_Write_byte(u8 data);
u8 DS18B20_Read_Byte();
float DS18B20_GetTemperture();


#endif