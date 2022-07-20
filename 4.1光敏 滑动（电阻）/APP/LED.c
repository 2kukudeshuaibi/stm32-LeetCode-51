#include "LED.h"

void LED_Init()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstruct);
	
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_Initstruct);
	
}

