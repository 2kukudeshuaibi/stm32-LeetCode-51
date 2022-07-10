#include "system.h"
#include "systick.h"


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
	TIM_TimeBasestruct.TIM_Period=per;
	TIM_TimeBasestruct.TIM_Prescaler=psc;
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
		TIM_SetCompare2(TIM3,i);//�޸�ռ�ձ�
		delay_ms(10);
	}
	return 0;
}
