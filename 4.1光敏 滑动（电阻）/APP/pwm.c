#include "pwm.h"

void TIM3_CH2_PWM1_Init(u16 per,u16 psc)
{
	GPIO_InitTypeDef GPIO_Initstruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
	TIM_OCInitTypeDef TIM_OCInitstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstruct);
	
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitstruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitstruct.TIM_Period=per;
	TIM_TimeBaseInitstruct.TIM_Prescaler=psc;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitstruct);
	
	TIM_OCInitstruct.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitstruct.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitstruct.TIM_OutputState=TIM_OutputState_Enable;                                                                   
	TIM_OC2Init(TIM3,&TIM_OCInitstruct);
	
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM3,ENABLE);
	TIM_Cmd(TIM3,ENABLE);
}