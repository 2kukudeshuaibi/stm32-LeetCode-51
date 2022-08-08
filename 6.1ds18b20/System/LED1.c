#include "LED1.h"

void LED1_Init()
{
	GPIO_InitTypeDef InitstructB;
	GPIO_InitTypeDef InitstructE;
	RCC_APB2PeriphClockCmd(LED1_PORT_RCC,ENABLE);
	RCC_APB2PeriphClockCmd(LED2_PORT_RCC,ENABLE);
	
	InitstructB.GPIO_Pin=LED1_Pin;
	InitstructB.GPIO_Speed=GPIO_Speed_50MHz;
	InitstructB.GPIO_Mode=GPIO_Mode_Out_PP;
	
	InitstructE.GPIO_Pin=LED2_Pin;
	InitstructE.GPIO_Speed=GPIO_Speed_50MHz;
	InitstructE.GPIO_Mode=GPIO_Mode_Out_PP;
	
	GPIO_Init(LED1_PORT,&InitstructB);
	GPIO_Init(LED2_PORT,&InitstructB);
	
	GPIO_SetBits(LED1_PORT,LED1_Pin);
	GPIO_SetBits(LED2_PORT,LED2_Pin);
}