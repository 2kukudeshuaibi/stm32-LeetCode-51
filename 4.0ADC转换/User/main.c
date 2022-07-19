#include "systick.h"
#include "system.h"
#include "led.h"
#include "usart.h"
#include "touch_key.h"
#include "adc.h"


void TIM3_CH2_PWM_Init(u16 per,u16 psc)
{
	GPIO_InitTypeDef GPIO_Initstruct;//GPIO��ʼ���ṹ��
	TIM_TimeBaseInitTypeDef TIM_TimeBasestruct;//��ʱ����ʼ���ṹ��
	TIM_OCInitTypeDef TIM_OCInitstruct;//PWMͨ����ʼ��
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//ʹ�ܸ��ù���
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//ʹ�ܶ�ʱ��3
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);//ʹ�ܲ���ӳ��
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstruct);//GPIO��ʼ��
	
	
	TIM_TimeBasestruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBasestruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBasestruct.TIM_Period=per;//ARR
	TIM_TimeBasestruct.TIM_Prescaler=psc;//PSC
	TIM_TimeBaseInit(TIM3,&TIM_TimeBasestruct);//��ʱ����ʼ��
	
	TIM_OCInitstruct.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitstruct.TIM_OCPolarity=TIM_OCPolarity_Low;//�͵�ƽ��Ч
	TIM_OCInitstruct.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OC2Init(TIM3,&TIM_OCInitstruct);//PWM1ͨ��2��ʼ��
	
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);//ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
	TIM_ARRPreloadConfig(TIM3,ENABLE);//ʹ��TIM3��ARR �ϵ�Ԥװ�ؼĴ���
	TIM_Cmd(TIM3,ENABLE);//������ʱ��3
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
			printf("����ADֵ:%d\r\n",Get_ADC_VAL(ADC_Channel_1,20));
			vol=(float)(3.3/4096)*Get_ADC_VAL(ADC_Channel_1,20);
			printf("��ѹ:%.2fV\r\n",vol);
		}
		TIM_SetCompare2(TIM3,Get_ADC_VAL(ADC_Channel_1,20));
	}
	return 0;
}
