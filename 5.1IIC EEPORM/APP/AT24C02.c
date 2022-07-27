#include "AT24C02.h"

void AT24C02_Init()
{
	IIC_Init();
}

void AT24C02_WriteOneByte(u8 add,u8 data)
{
	IIC_STAR();
	IIC_Write_byte(0xa0);
	IIC_Wait_ACK();
	IIC_Write_byte(add);
	IIC_Wait_ACK();
	IIC_Write_byte(data);
	IIC_Wait_ACK();
	IIC_STOP();
	delay_ms(10);
}

u8 AT24C02_ReadOneByte(u8 add)
{
	u8 tmp=0;
	IIC_STAR();
	IIC_Write_byte(0xa0);
	IIC_Wait_ACK();
	IIC_Write_byte(add);
	IIC_Wait_ACK();
	IIC_STAR();
	IIC_Write_byte(0xa1);
	IIC_Wait_ACK();
	tmp=IIC_Read_byte(0);
	IIC_STOP();
	return tmp;
}

u8 AT24C02_Check()
{
	u8 tmp=0;
	tmp=AT24C02_ReadOneByte(255);
	if(tmp==0x36)
	{
		return 0;
	}
	else
	{
		AT24C02_WriteOneByte(255,0x36);
		tmp=AT24C02_ReadOneByte(255);
		if(tmp==0x36)
		{
			return 0;
		}
	}
	return 1;
}