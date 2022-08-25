#include "iic.h"


void IIC_Init(void)                //��ʼ��IIC��IO��
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(IIC_SCL_PORT_RCC|IIC_SDA_PORT_RCC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=IIC_SCL_PIN;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(IIC_SCL_PORT,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=IIC_SDA_PIN;
	GPIO_Init(IIC_SDA_PORT,&GPIO_InitStructure);
	
	IIC_SCL=1;
	IIC_SDA=1;	
}	

void SDA_OUT(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin=IIC_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(IIC_SDA_PORT,&GPIO_InitStructure);
}


void SDA_IN(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin=IIC_SDA_PIN;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(IIC_SDA_PORT,&GPIO_InitStructure);
}



void IIC_Start(void)				//����IIC��ʼ�ź�
{
	SDA_OUT();
	IIC_SDA=1;
	IIC_SCL=1;
	delay_us(5);
	IIC_SDA=0;
	delay_us(5);
	IIC_SCL=0;
}

void IIC_Stop(void)	  			//����IICֹͣ�ź�
{
	SDA_OUT();
	IIC_SDA=0;
	IIC_SCL=1;
	delay_us(5);
	IIC_SDA=1;
	delay_us(5);
	IIC_SCL=0;
}

void IIC_Send_Byte(u8 txd)		//IIC����һ���ֽ�
{
	u8 i=0;
	SDA_OUT();
	IIC_SCL=0;
	for(i=0;i<8;i++)
	{
		if((txd&0x80)>0)
			IIC_SDA=1;
		else
			IIC_SDA=0;
		txd<<=1;
		delay_us(2);
		IIC_SCL=1;
		delay_us(2);
		IIC_SCL=0;
		delay_us(2);
	}
}

u8 IIC_Read_Byte(u8 ack)			//IIC��ȡһ���ֽ�
{
	u8 i=0;
	u8 tmp=0;
	SDA_IN();
	for(i=0;i<8;i++)
	{
		IIC_SCL=0;
		delay_us(2);
		IIC_SCL=1;
		tmp<<=1;
		if(READ_SDA)
			tmp++;
		delay_us(1);
	}
	if(!ack)
		IIC_NAck();
	else
		IIC_Ack();
	return tmp;
}

u8 IIC_Wait_Ack(void)				//IIC�ȴ�ACK�ź�
{
	u8 i=0;
	IIC_SDA=1;
	delay_us(1);
	SDA_IN();
	IIC_SCL=1;

	delay_us(1);
	while(READ_SDA)
	{
		i++;
		if(i>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL=0;
	return 0;
}

void IIC_Ack(void)				//IIC����ACK�ź�
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=0;
	delay_us(2);
	IIC_SCL=1;
	delay_us(5);
	IIC_SCL=0;
}

void IIC_NAck(void)				//IIC������ACK�ź�
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=1;
	delay_us(2);
	IIC_SCL=1;
	delay_us(5);
	IIC_SCL=0;
}