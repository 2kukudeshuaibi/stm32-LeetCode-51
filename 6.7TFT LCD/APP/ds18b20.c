#include "ds18b20.h"


void DS18B20_IO_IN()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_11;
	GPIO_Init(GPIOG,&GPIO_Initstruct);
}

void DS18B20_IO_OUT()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_11;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOG,&GPIO_Initstruct);
}

void DS18B20_Reset()
{
	DS18B20_IO_OUT();
	DS18B20_OUT=0;
	delay_us(750);
	DS18B20_OUT=1;
	delay_us(15);
}

u8 DS18B20_Check()
{
	u8 i=0;
	DS18B20_IO_IN();
	while(DS18B20_IN&&i<200)
	{
		i++;
		delay_us(1);
	}
	if(i>=200)
		return 1;
	else
		i=0;
	while(!DS18B20_IN&&i<240)
	{
		i++;
		delay_us(1);
	}
	if(i>=240)
		return 1;
	else
		return 0;
}

u8 DS18B20_Init()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_11;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOG,&GPIO_Initstruct);
	
	DS18B20_Reset();
	return DS18B20_Check();
}


void DS18B20_Write_byte(u8 data)
{
	u8 i=0;
	DS18B20_IO_OUT();
	for(i=0;i<8;i++)
	{
		if(data&(0x01<<i))
		{
			DS18B20_OUT=0;
			delay_us(2);
			DS18B20_OUT=1;
			delay_us(60);
		}
		else
		{
			DS18B20_OUT=0;
			delay_us(60);
			DS18B20_OUT=1;
			delay_us(2);
		}
	}
}

u8 DS18B20_Read_BIT()
{
	u8 temp=0;
	DS18B20_IO_OUT();
	DS18B20_OUT=0;
	delay_us(2);
	DS18B20_OUT=1;
	DS18B20_IO_IN();
	delay_us(12);
	if(DS18B20_IN)
	{
		temp=1;
	}
	else
	{
		temp=0;
	}
	delay_us(50);
	return temp;
}

u8 DS18B20_Read_Byte()
{
	u8 data=0;
	u8 i=0;
	u8 temp=0;
	for(i=0;i<8;i++)
	{
		data=DS18B20_Read_BIT();
		if(data)
		{
			temp=temp|(0x01<<i);
		}
	}
	return temp;
}

float DS18B20_GetTemperture()
{
	u8 datal=0;
	u8 datah=0;
	u16 data=0;
	float val=0;
	DS18B20_Reset();
	DS18B20_Check();
	DS18B20_Write_byte(0xcc);
	DS18B20_Write_byte(0x44);
	DS18B20_Reset();
	DS18B20_Check();
	DS18B20_Write_byte(0xcc);
	DS18B20_Write_byte(0xbe);
	datal=DS18B20_Read_Byte();
	datah=DS18B20_Read_Byte();
	data=(datah<<8)+datal;
	if((data&0xf800)==0xf800)
	{
		data=(~data)+1;
		val=data*(-0.0625);
	}
	else
	{
		val=data*(0.0625);
	}
	
	return val;
}
