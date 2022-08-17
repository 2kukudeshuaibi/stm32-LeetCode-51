#include "key.h"


void KEY_Init()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	
	RCC_APB2PeriphClockCmd(KEY012_PORT,ENABLE);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstruct.GPIO_Pin=KEY0_PIN;
	GPIO_Init(GPIOE,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstruct.GPIO_Pin=KEY1_PIN;
	GPIO_Init(GPIOE,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstruct.GPIO_Pin=KEY2_PIN;
	GPIO_Init(GPIOE,&GPIO_Initstruct);
}

u8 key_scan()
{
	u8 res = 9;
	if(GPIO_ReadInputDataBit(GPIOE,KEY0_PIN)==0)
	{
		res=0;
		while(!GPIO_ReadInputDataBit(GPIOE,KEY0_PIN));
	}
	if(GPIO_ReadInputDataBit(GPIOE,KEY1_PIN)==0)
	{
		res=1;
		while(!GPIO_ReadInputDataBit(GPIOE,KEY1_PIN));
	}
	if(GPIO_ReadInputDataBit(GPIOE,KEY2_PIN)==0)
	{
		res=2;
		while(!GPIO_ReadInputDataBit(GPIOE,KEY2_PIN));
	}
	return res;
}