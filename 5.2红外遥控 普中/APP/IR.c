#include "IR.h"



u32 shuju=0;
u8 jsbz=0;
void IR_Init()
{
	NVIC_InitTypeDef NVIC_Initstruct;
	EXTI_InitTypeDef EXTI_Initstruct;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource9);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	EXTI_Initstruct.EXTI_Line=EXTI_Line9;
	EXTI_Initstruct.EXTI_LineCmd=ENABLE;
	EXTI_Initstruct.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_Initstruct.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_Initstruct);
	
	NVIC_Initstruct.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_Initstruct);

	EXTI_ClearITPendingBit(EXTI_Line9);
}

u8 Get_Time()
{
	u8 t=0;
	while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==1)
	{
		t++;
		delay_us(20);
		if(t>=250)
		{
			return t;
		}
	}
	return t;
}

void EXTI9_5_IRQHandler()
{
	u8 num=0;
	u8 t=0;
	u8 ok=0;
	u8 data=0;
	while(1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==1)
		{
			t=Get_Time();
			if(t>=250)
			{
				break;
			}
			if(t>=200&&t<250)
			{
				ok=1;
			}
			else if(t>60&&t<90)
			{
				data=1;
			}
			else if(t>10&&t<50)
			{
				data=0;
			}
			if(ok==1)
			{
				shuju<<=1;
				shuju+=data;
				if(num>=32)
				{
					jsbz=1;
					break;
				}
			}
			num++;
		}
	}
	
	EXTI_ClearITPendingBit(EXTI_Line9);
}
