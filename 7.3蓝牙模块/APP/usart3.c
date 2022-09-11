#include "usart3.h"
#include "stdio.h"
#include "string.h"
#include "stdarg.h"


u8 USART3_RX_BUFF[USART3_MAX_RECV_LEN];
u8 USART3_TX_BUFF[USART3_MAX_SEND_LEN];

vu16 USART3_RX_STA=0;


void USART3_Init(u32 baud)
{
	GPIO_InitTypeDef GPIO_Initstruct;
	USART_InitTypeDef USART_Initstruct;
	NVIC_InitTypeDef NVIC_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
	
	
	USART_DeInit(USART3);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_10;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_11;
	GPIO_Init(GPIOB,&GPIO_Initstruct);
	
	
	USART_Initstruct.USART_BaudRate=baud;
	USART_Initstruct.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_Initstruct.USART_Parity=USART_Parity_No;
	USART_Initstruct.USART_StopBits=USART_StopBits_1;
	USART_Initstruct.USART_WordLength=USART_WordLength_8b;
	USART_Initstruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Init(USART3,&USART_Initstruct);
	
	USART_Cmd(USART3,ENABLE);
	
	USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);
	
	NVIC_Initstruct.NVIC_IRQChannel=USART3_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=3;
	NVIC_Init(&NVIC_Initstruct);
	TIM7_Init(99,7199);
	USART3_RX_STA=0;
	TIM_Cmd(TIM7,DISABLE);
}

void USART3_IRQHandler()
{
	u8 tmp=0;
	if(USART_GetITStatus(USART3,USART_IT_RXNE))
	{
		tmp=USART_ReceiveData(USART3);
		if((USART3_RX_STA&0x8000)==0)
		{
			if(USART3_RX_STA<USART3_MAX_RECV_LEN)
			{
				TIM_SetCounter(TIM7,0);
				if(USART3_RX_STA==0)
				{
					TIM_Cmd(TIM7,ENABLE);
				}
				USART3_RX_BUFF[USART3_RX_STA++]=tmp;
			}
			else
			{
				USART3_RX_STA|=0x8000;
			}
		}
	}
}

void u3_printf(char* fmt,...)
{
	u16 i,j;
	va_list ap;
	va_start(ap,fmt);
	vsprintf((char*)USART3_TX_BUFF,fmt,ap);
	va_end(ap);
	i=strlen((const char*)USART3_TX_BUFF);
	for(j=0;j<i;j++)
	{
		while(!USART_GetFlagStatus(USART3,USART_FLAG_TC));
		USART_SendData(USART3,USART3_TX_BUFF[j]);
	}
}