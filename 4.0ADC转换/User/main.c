#include "systick.h"
#include "system.h"
#include "led.h"
#include "usart.h"
#include "touch_key.h"
#include "adc.h"


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
	TIM_TimeBasestruct.TIM_Period=per;//ARR
	TIM_TimeBasestruct.TIM_Prescaler=psc;//PSC
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
	u8 i=0;
	u16 j=0;
	float vol=0;
	systick_init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	USART1_Init(115200);
	adc_Init();
	TIM3_CH2_PWM_Init(4000,72-1);
	while(1)
	{
		i++;
		if(i%20==0)
		{
			LED1=!LED1;
		}
		delay_ms(10);
		if(i%100==0)
		{
			printf("检测的AD值:%d\r\n",Get_ADC_VAL(ADC_Channel_1,20));
			vol=(float)(3.3/4096)*Get_ADC_VAL(ADC_Channel_1,20);
			printf("电压:%.2fV\r\n",vol);
		}
		TIM_SetCompare2(TIM3,Get_ADC_VAL(ADC_Channel_1,20));
	}
	return 0;
}
