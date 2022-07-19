#include "touch_key.h"


#define Touch_ARR_MAX_VAL 0xffff

u16 touch_default_val=0;



void TIM5_CH2_Input_Init(u16 arr,u16 pes)
{
	GPIO_InitTypeDef GPIO_Initstruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
	TIM_ICInitTypeDef TIM_ICInitstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_1;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitstruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitstruct.TIM_Period=arr;
	TIM_TimeBaseInitstruct.TIM_Prescaler=pes;
	TIM_TimeBaseInit(TIM5,&TIM_TimeBaseInitstruct);
	
	TIM_ICInitstruct.TIM_Channel=TIM_Channel_2;
	TIM_ICInitstruct.TIM_ICFilter=0;
	TIM_ICInitstruct.TIM_ICPolarity=TIM_ICPolarity_Rising;
	TIM_ICInitstruct.TIM_ICPrescaler=TIM_ICPSC_DIV1;
	TIM_ICInitstruct.TIM_ICSelection=TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM5,&TIM_ICInitstruct);
	
	TIM_Cmd(TIM5,ENABLE);
}

void Touch_Reset()
{
	GPIO_InitTypeDef GPIO_Initstruct;
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_1;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	delay_ms(5);
	TIM_ClearFlag(TIM5,TIM_FLAG_Update|TIM_FLAG_CC2);
	TIM_SetCounter(TIM5,0);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_1;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
}

u16 Touch_Get_Val()
{
	Touch_Reset();
	while(TIM_GetFlagStatus(TIM5,TIM_FLAG_CC2)==0)
	{
		if(TIM_GetCounter(TIM5)>Touch_ARR_MAX_VAL-500)
		{
			return TIM_GetCounter(TIM5);
		}
	}
	return TIM_GetCapture2(TIM5);
}





u8 Touch_Key_Init(u8 psc)
{
	u8 i=0;
	u8 j=0;
	u16 swap=0;
	u16 buf[10];
	TIM5_CH2_Input_Init(Touch_ARR_MAX_VAL,psc);
	for(i=0;i<10;i++)
	{
		buf[i]=Touch_Get_Val();
		delay_ms(10);
	}
	for(i=0;i<10-1;i++)
	{
		for(j=0;j<10-1-i;j++)
		{
			if(buf[j]>buf[j+1])
			{
				swap=buf[j];
				buf[j]=buf[j+1];
				buf[j+1]=swap;
			}
		}
	}
	swap=0;
	for(i=2;i<8;i++)
	{
		swap+=buf[i];
	}
	touch_default_val=swap/6;
	printf("touch_default_val=%d\r\n",touch_default_val);
	
	if(touch_default_val>Touch_ARR_MAX_VAL/2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


u16 Touch_Get_MAXVAL(u8 n)
{
	u16 tmp=0;
	u16 res=0;
	while(n--)
	{
		tmp=Touch_Get_Val();
		if(tmp>res)
		{
			res=tmp;
		}
	}
	
	return res;
}


u8 Touch_key_scan(u8 mode)
{
	u16 rval=0;
	static u8 keyen=0;
	u8 res=0;
	rval=Touch_Get_MAXVAL(3);
	
	if(mode)
	{
		keyen=0;
	}
	
	if(rval>(touch_default_val+100)&&rval<(10*touch_default_val))
	{
		if((keyen==0)&&(rval>(touch_default_val+100)))
		{
			res=1;
		}
		printf("´¥Ãþ²¶»ñ:%d\r\n",rval);
		keyen=1;
	}
	else
	{
		keyen=0;
	}
	return res;
}