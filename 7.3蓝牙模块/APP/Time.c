#include "Time.h"

void TIM4_Init(u16 per,u16 pres)
{
	TIM_TimeBaseInitTypeDef TIM_TimeInitstruct;
	NVIC_InitTypeDef NVIC_Initstruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	TIM_TimeInitstruct.TIM_Period=per;
	TIM_TimeInitstruct.TIM_Prescaler=pres;
	TIM_TimeInitstruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeInitstruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4,&TIM_TimeInitstruct);
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
	NVIC_Initstruct.NVIC_IRQChannel=TIM4_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=3;
	NVIC_Init(&NVIC_Initstruct);
	TIM_Cmd(TIM4,ENABLE);
}

void TIM4_IRQHandler()
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update))
	{
		LED2=!LED2;
	}
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
}


void TIM7_Init(u16 per,u16 pres)
{
	TIM_TimeBaseInitTypeDef TIM_TimeInitstruct;
	NVIC_InitTypeDef NVIC_Initstruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,ENABLE);
	
	TIM_TimeInitstruct.TIM_Period=per;
	TIM_TimeInitstruct.TIM_Prescaler=pres;
	TIM_TimeInitstruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeInitstruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM7,&TIM_TimeInitstruct);
	
	TIM_ITConfig(TIM7,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM7,ENABLE);
	
	TIM_ClearITPendingBit(TIM7,TIM_IT_Update);
	NVIC_Initstruct.NVIC_IRQChannel=TIM7_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=2;
	NVIC_Init(&NVIC_Initstruct);
	
}

extern vu16 USART3_RX_STA;

void TIM7_IRQHandler()
{
	if(TIM_GetITStatus(TIM7,TIM_IT_Update))
	{
		USART3_RX_STA|=0x8000;
		TIM_ClearITPendingBit(TIM7,TIM_IT_Update);
		TIM_Cmd(TIM7,DISABLE);
	}
}
