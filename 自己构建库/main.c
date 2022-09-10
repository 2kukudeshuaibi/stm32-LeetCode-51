#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void SystemInit()
{
	
}

void main()
{
	GPIO_InitTypedef GPIO_Initstruct;
	RCC->APB2ENR|=(1<<6);
//	GPIOB->CRL&=~(0x0f<<(4*5));
//	GPIOB->CRL|=(0x01<<(4*5));
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHZ;
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Init(GPIOE,&GPIO_Initstruct);
	
	GPIO_RSetBits(GPIOE,GPIO_Pin_5);
	//GPIOB->ODR&=~(0x01<<5);
   // GPIOB->ODR|=(0x01<<5);
	//GPIO_SetBits(GPIOB,GPIO_Pin_5);
	while(1);
}