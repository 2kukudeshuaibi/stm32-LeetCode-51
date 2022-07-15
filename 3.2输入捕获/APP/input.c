#include "input.h"

u8 TIM5_CH1_CAPTURE_STA=0;//输入捕获状态
u16 TIM5_CH1_CAPTURE_VAL=0;//输入捕获值


void TIM5_Iniput_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef GPIO_Initstruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
	TIM_ICInitTypeDef TIM_ICInitstruct;
	NVIC_InitTypeDef NVIC_Initstruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitstruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitstruct.TIM_Period=arr;
	TIM_TimeBaseInitstruct.TIM_Prescaler=psc;
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseInitstruct);
	
	TIM_ICInitstruct.TIM_Channel=TIM_Channel_1;
	TIM_ICInitstruct.TIM_ICFilter=0;
	TIM_ICInitstruct.TIM_ICPolarity=TIM_ICPolarity_Rising;
	TIM_ICInitstruct.TIM_ICPrescaler=TIM_ICPSC_DIV1;
	TIM_ICInitstruct.TIM_ICSelection=TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM5,&TIM_ICInitstruct);
	
	TIM_ITConfig(TIM5,TIM_IT_Update|TIM_IT_CC1,ENABLE);
	
	NVIC_Initstruct.NVIC_IRQChannel=TIM5_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_Initstruct);
	
	TIM_Cmd(TIM5,ENABLE);
}



void TIM5_IRQHandler()
{
	//定时溢出中断
	if(TIM_GetITStatus(TIM5,TIM_IT_Update))
	{
		if(TIM5_CH1_CAPTURE_STA&0x40)
		{
			if((TIM5_CH1_CAPTURE_STA&0x3f)==0x3f)
			{
				TIM5_CH1_CAPTURE_STA|=0x80;
				TIM5_CH1_CAPTURE_VAL=0xffff;
			}
			else
			{
				TIM5_CH1_CAPTURE_STA++;
			}
		}
	}
	//捕获中断
	if(TIM_GetITStatus(TIM5,TIM_IT_CC1))
	{
		if(TIM5_CH1_CAPTURE_STA&0x40)
		{
			TIM5_CH1_CAPTURE_VAL=TIM_GetCapture1(TIM5);
			TIM5_CH1_CAPTURE_STA|=0x80;//标记捕获完成
			TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Rising);//设置上升沿捕获
			
		}
		else
		{
			TIM5_CH1_CAPTURE_STA=0;
			TIM5_CH1_CAPTURE_VAL=0;
			TIM5_CH1_CAPTURE_STA|=0x40;//捕获到上升沿
			TIM_Cmd(TIM5,DISABLE);//关闭定时器
			TIM_SetCounter(TIM5,0);//给计数器赋值0
			TIM_OC1PolarityConfig(TIM5,TIM_ICPolarity_Falling);//设置下降沿捕获
			TIM_Cmd(TIM5,ENABLE);
		}
	}
	
	TIM_ClearITPendingBit(TIM5,TIM_IT_Update|TIM_IT_CC1);
}
