#include "pwm-dac.h"


void TIM1_CH1_PWM_Init(u16 per,u16 psc)
{
	GPIO_InitTypeDef GPIO_Initstruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBasestruct;
	TIM_OCInitTypeDef TIM_OCInitstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_8;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstruct);
	
	
	TIM_TimeBasestruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBasestruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBasestruct.TIM_Period=per;//ARR
	TIM_TimeBasestruct.TIM_Prescaler=psc;//PSC
	TIM_TimeBaseInit(TIM1,&TIM_TimeBasestruct);
	
	TIM_OCInitstruct.TIM_OCMode=TIM_OCMode_PWM2;
	TIM_OCInitstruct.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitstruct.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC1Init(TIM1,&TIM_OCInitstruct);
	
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM1,ENABLE);
	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);
	TIM_SetCompare1(TIM1,0);
	TIM_Cmd(TIM1,ENABLE);
}

