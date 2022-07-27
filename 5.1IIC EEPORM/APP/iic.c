#include "iic.h"


void IIC_Init()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	
	RCC_APB2PeriphClockCmd(IIC_SCL_PORT_RCC,ENABLE);
	RCC_APB2PeriphClockCmd(IIC_SDA_PORT_RCC,ENABLE);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin=IIC_SCL_Pin;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(IIC_SCL_PORT,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Pin=IIC_SDA_Pin;
	GPIO_Init(IIC_SDA_PORT,&GPIO_Initstruct);
	
	IIC_SCL=1;
	IIC_SDA=1;
}

void SDA_OUT()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin=IIC_SDA_Pin;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(IIC_SDA_PORT,&GPIO_Initstruct);
}

void SDA_IN()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstruct.GPIO_Pin=IIC_SDA_Pin;
	GPIO_Init(IIC_SDA_PORT,&GPIO_Initstruct);
}

void IIC_STAR()
{
	SDA_OUT();
	IIC_SDA=1;
	IIC_SCL=1;
	delay_us(5);
	IIC_SDA=0;
	delay_us(5);
	IIC_SCL=0;
}

void IIC_STOP()
{
	SDA_OUT();
	IIC_SDA=0;
	IIC_SCL=0;
	IIC_SCL=1;
	delay_us(5);
	IIC_SDA=1;
	delay_us(5);
}

void IIC_ACK()
{
	SDA_OUT();
	IIC_SCL=0;
	IIC_SDA=0;
	delay_us(2);
	IIC_SCL=1;
	delay_us(5);
	IIC_SCL=0;
}

void IIC_NACK()
{
	SDA_OUT();
	IIC_SCL=0;
	IIC_SDA=1;
	delay_us(2);
	IIC_SCL=1;
	delay_us(5);
	IIC_SCL=0;
}

void IIC_Write_byte(u8 data)
{
	u8 i=0;
	SDA_OUT();
	IIC_SCL=0;
	for(i=0;i<8;i++)
	{
		if((data&0x80)>0)
			IIC_SDA=1;
		else
			IIC_SDA=0;
		data<<=1;
		delay_us(2);
		IIC_SCL=1;
		delay_us(2);
		IIC_SCL=0;
	}
	
}

u8 IIC_Read_byte(u8 ack)
{
	u8 i=0;
	u8 tmp=0;
	SDA_IN();
	for(i=0;i<8;i++)
	{
		IIC_SCL=0;
		delay_us(2);
		IIC_SCL=1;
		if(READ_SDA)
		{
			tmp=tmp|(0x80>>i);
		}
		delay_us(2);
	}
	if(ack)
	{
		IIC_ACK();
	}
	else
	{
		IIC_NACK();
	}
	
	return tmp;
}

u8 IIC_Wait_ACK()
{
	u8 i=0;
	SDA_IN();
	IIC_SCL=1;
	delay_us(2);
	while(READ_SDA)
	{
		i++;
		if(i>250)
		{
			IIC_STOP();
			return 1;
		}
	}
	IIC_SCL=0;
	return 0;
}