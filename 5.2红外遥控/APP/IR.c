#include "IR.h"


u8 IR_Start=0;
u16 Time=0;

u8 data[4];
u8 pdata=0;

u8 dateflag=0;
u8 repeatflag=0;

u8 add=0;
u8 command=0;


void IR_Init()
{
	NVIC_InitTypeDef NVIC_Initstruct;
	EXTI_InitTypeDef EXTI_Initstruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstruct;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource9);
	
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
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	TIM_TimeBaseInitstruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitstruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitstruct.TIM_Period=0xffff;
	TIM_TimeBaseInitstruct.TIM_Prescaler=72;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitstruct);
	
	EXTI_ClearITPendingBit(EXTI_Line9);
}


u8 Get_data_flag()
{
	
	if(dateflag==1)
	{
		dateflag=0;
		return 1;
	}
	return 0;
}

u8 Get_repeater_flag()
{
	if(repeatflag==1)
	{
		repeatflag=0;
		return 1;
	}
	return 0;
}

u8 Get_command()
{
	return command;
}

u8 Get_add()
{
	return add;
}

void EXTI9_5_IRQHandler()
{
	if(EXTI_GetITStatus(EXTI_Line9)==SET)
	{
		if(IR_Start==0)
		{
			TIM_SetCounter(TIM4,0);
			TIM_Cmd(TIM4,ENABLE);
			IR_Start=1;
		}
		else if(IR_Start==1)
		{
			Time=TIM_GetCounter(TIM4);
			TIM_SetCounter(TIM4,0);
			if((Time>13500-500)&&(Time<13500+500))
			{
				printf("Time1:%d\r\n",Time);
				IR_Start=2;
			}
			else if((Time>11250-500)&&(Time<11250+500))
			{
				repeatflag=1;
				IR_Start=0;
				printf("Time2:%d\r\n",Time);
				TIM_Cmd(TIM4,DISABLE);
			}
			else
			{
				IR_Start=1;
			}
		}
		else if(IR_Start==2)
		{
			Time=TIM_GetCounter(TIM4);
			TIM_SetCounter(TIM4,0);
			printf("Timeshuj:%d\r\n",Time);
			if((Time>1120-500)&&(Time<1120+500))
			{
				data[pdata/8]&=~(0x01<<(pdata%8));
				pdata++;
			}
			else if((Time>2250-500)&&(Time<2250+500))
			{
				data[pdata/8]|=(0x01<<(pdata%8));
				pdata++;
			}
			else
			{
				pdata=0;
				IR_Start=0;
				TIM_Cmd(TIM4,DISABLE);
			}
			if(pdata>=32)
			{
				pdata=0;
				if((data[0]==~(data[1]))&&(data[2]==~(data[3])))
				{
					dateflag=1;
					add=data[0];
					command=data[2];
				}
				TIM_Cmd(TIM4,DISABLE);
				IR_Start=0;
			}
		}
	}
	
	EXTI_ClearITPendingBit(EXTI_Line9);
}