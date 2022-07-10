#include "system.h"
#include "systick.h"


void TIM3_CH2_PWM_Init(u16 per,u16 psc)
{
	GPIO_InitTypeDef GPIO_Initstruct;//GPIO初始化结构体
	TIM_TimeBaseInitTypeDef TIM_TimeBasestruct;//定时器初始化结构体
	TIM_OCInitTypeDef TIM_OCInitstruct;//PWM通道初始化
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//使能复用功能
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//使能定时器3
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);//使能部分映射
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstruct);//GPIO初始化
	
	
	TIM_TimeBasestruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBasestruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBasestruct.TIM_Period=per;
	TIM_TimeBasestruct.TIM_Prescaler=psc;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBasestruct);//定时器初始化
	
	TIM_OCInitstruct.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitstruct.TIM_OCPolarity=TIM_OCPolarity_Low;//低电平有效
	TIM_OCInitstruct.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC2Init(TIM3,&TIM_OCInitstruct);//PWM1通道2初始化
	
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);//使能TIM3在CCR2上的预装载寄存器
	TIM_ARRPreloadConfig(TIM3,ENABLE);//使能TIM3在ARR 上的预装载寄存器
	TIM_Cmd(TIM3,ENABLE);//开启定时器3
}

int main()
{
	u16 i=0;
	u8 flag=0;
	systick_Init(72);
	TIM3_CH2_PWM_Init(500,72-1);
	while(1)
	{
		if(flag==0)
		{
			i++;
			if(i==300)
			{
				flag=1;
			}
		}
		else
		{
			i--;
			if(i==0)
			{
				flag=0;
			}
		}
		TIM_SetCompare2(TIM3,i);//修改占空比
		delay_ms(10);
	}
	return 0;
}
