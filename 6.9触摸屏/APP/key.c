#include "key.h"

void Key_Init()
{
	GPIO_InitTypeDef Initstruct;
	
	RCC_APB2PeriphClockCmd(KEY_UP_PORT_RCC,ENABLE);
	RCC_APB2PeriphClockCmd(KEY012_PORT_RCC,ENABLE);
	
	Initstruct.GPIO_Pin=KEY_UP_Pin;
	Initstruct.GPIO_Mode=GPIO_Mode_IPD;
	Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(KEY_UP_PORT,&Initstruct);
	
	Initstruct.GPIO_Pin=KEY0_Pin|KEY1_Pin|KEY2_Pin;
	Initstruct.GPIO_Mode=GPIO_Mode_IPU;
	Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(KEY012_PORT,&Initstruct);
}

u8 key_scan()
{
	if(GPIO_ReadInputDataBit(KEY012_PORT,KEY0_Pin)==0)
	{
		delay_ms(10);
		if(GPIO_ReadInputDataBit(KEY012_PORT,KEY0_Pin)==0)
		{
			while(!GPIO_ReadInputDataBit(KEY012_PORT,KEY0_Pin));
			return 1;
		}
	}
	if(GPIO_ReadInputDataBit(KEY012_PORT,KEY1_Pin)==0)
	{
		delay_ms(10);
		if(GPIO_ReadInputDataBit(KEY012_PORT,KEY1_Pin)==0)
		{
			while(!GPIO_ReadInputDataBit(KEY012_PORT,KEY1_Pin));
			return 2;
		}
	}
	if(GPIO_ReadInputDataBit(KEY012_PORT,KEY2_Pin)==0)
	{
		delay_ms(10);
		if(GPIO_ReadInputDataBit(KEY012_PORT,KEY2_Pin)==0)
		{
			while(!GPIO_ReadInputDataBit(KEY012_PORT,KEY2_Pin));
			return 3;
		}
	}
	return 0;
}

