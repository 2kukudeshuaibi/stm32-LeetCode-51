#include "led.h"




void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructB;
	
	RCC_APB2PeriphClockCmd(LED1_PORT_RCC,ENABLE);
	
	GPIO_InitStructB.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructB.GPIO_Pin=LED1_PIN;
	GPIO_InitStructB.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(LED1_PORT,&GPIO_InitStructB);
	
	GPIO_SetBits(LED1_PORT,LED1_PIN);
	
	
	
	
	
	GPIO_InitTypeDef GPIO_InitStructE;
	
	RCC_APB2PeriphClockCmd(LED2_PORT_RCC,ENABLE);
	
	GPIO_InitStructE.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructE.GPIO_Pin=LED2_PIN;
	GPIO_InitStructE.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(LED2_PORT,&GPIO_InitStructE);
	
	GPIO_SetBits(LED2_PORT,LED2_PIN);
	
}