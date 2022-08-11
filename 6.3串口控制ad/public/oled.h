#ifndef _oled_H
#define _oled_H

#include "system.h"
#include "systick.h"

#define IIC_SCL 	PDout(6)
#define IIC_SDA 	PDout(7)
#define IIC_SDA_IN  PDin(7)


void OLED_I2C_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(u8 l,u8 c,uint32_t num,u8 len);

#endif