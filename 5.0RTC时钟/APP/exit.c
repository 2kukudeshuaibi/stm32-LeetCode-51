#include "exit.h"


void My_Exit_Init()
{
	NVIC_InitTypeDef NVIC_Initstruct;
	EXTI_InitTypeDef EXTI_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource2);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
	
	NVIC_Initstruct.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=3;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_Initstruct);
	
	
	NVIC_Initstruct.NVIC_IRQChannel=EXTI2_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=2;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_Initstruct);
	
	
	NVIC_Initstruct.NVIC_IRQChannel=EXTI3_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_Initstruct);
	
	
	NVIC_Initstruct.NVIC_IRQChannel=EXTI4_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=0;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_Initstruct);
	
	
	EXTI_Initstruct.EXTI_Line=EXTI_Line0;
	EXTI_Initstruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_Initstruct.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_Initstruct.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_Initstruct);
	
	
	EXTI_Initstruct.EXTI_Line=EXTI_Line2;
	EXTI_Initstruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_Initstruct.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Initstruct.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_Initstruct);
	
	
	EXTI_Initstruct.EXTI_Line=EXTI_Line3;
	EXTI_Initstruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_Initstruct.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Initstruct.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_Initstruct);
	
	EXTI_Initstruct.EXTI_Line=EXTI_Line4;
	EXTI_Initstruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_Initstruct.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Initstruct.EXTI_LineCmd=ENABLE;
	EXTI_Init(&EXTI_Initstruct);
}



void EXTI0_IRQHandler()
{
	if(EXTI_GetFlagStatus(EXTI_Line0)==SET)
	{
		delay_ms(10);
		if(KEYUP==1)
		{
			LED1=0;
			LED2=0;
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line0);
}

void EXTI2_IRQHandler()
{
	if(EXTI_GetFlagStatus(EXTI_Line2)==SET)
	{
		delay_ms(10);
		if(KEY2==0)
		{
			LED1=1;
			LED2=1;
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line2);
}


void EXTI3_IRQHandler()
{
	if(EXTI_GetFlagStatus(EXTI_Line3)==SET)
	{
		delay_ms(10);
		if(KEY1==0)
		{
			BEEP=1;
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line3);
}

void EXTI4_IRQHandler()
{
	if(EXTI_GetFlagStatus(EXTI_Line4)==SET)
	{
		delay_ms(10);
		if(KEY0==0)
		{
			BEEP=0;
		}
	}
	EXTI_ClearITPendingBit(EXTI_Line4);
}