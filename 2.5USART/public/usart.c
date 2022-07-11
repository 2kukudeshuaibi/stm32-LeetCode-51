#include "usart.h"

u8 USART1_RX_BUF[USART1_REC_LEN];
u16 USART1_RX_STA=0;

void USART1_Init(u32 baud)
{
	GPIO_InitTypeDef GPIO_Initstruct;
	USART_InitTypeDef USART_Initstruct;
	NVIC_InitTypeDef NVIC_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_9;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	
	
	USART_Initstruct.USART_BaudRate=baud;
	USART_Initstruct.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_Initstruct.USART_Parity=USART_Parity_No;
	USART_Initstruct.USART_StopBits=USART_StopBits_1;
	USART_Initstruct.USART_WordLength=USART_WordLength_8b;
	USART_Initstruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Init(USART1,&USART_Initstruct);
	
	USART_Cmd(USART1,ENABLE);
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	NVIC_Initstruct.NVIC_IRQChannel=USART1_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=3;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=3;
	NVIC_Init(&NVIC_Initstruct);
	
}


void USART1_IRQHandler()
{
	u8 tmp=0;
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		tmp=USART_ReceiveData(USART1);
		
		if((USART1_RX_STA&0x8000)==0)
		{
			if(USART1_RX_STA&0x4000)
			{
				if(tmp!=0x0a)
				{
					USART1_RX_STA=0;
				}
				else
				{
					USART1_RX_STA|=0x8000;
				}
			}
			else
			{
				if(tmp==0x0d)
				{
					USART1_RX_STA|=0x4000;	
				}
				else
				{
					USART1_RX_BUF[USART1_RX_STA&0x3fff]=tmp;
					USART1_RX_STA++;
					if(USART1_RX_STA>USART1_REC_LEN-1)
					{
						USART1_RX_STA=0;
					}
				}
			}
		}
	}
	
}
