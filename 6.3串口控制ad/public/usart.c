#include "usart.h"

u8 FLAG_ON_OFF=0;



void USART1_Init()
{
	GPIO_InitTypeDef GPIO_InitTystruct;
	USART_InitTypeDef USART_Initstruct;
	NVIC_InitTypeDef NVIC_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitTystruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitTystruct.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitTystruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitTystruct);
	
	GPIO_InitTystruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitTystruct.GPIO_Pin=GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_InitTystruct);
	
	USART_Initstruct.USART_BaudRate=115200;
	USART_Initstruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Initstruct.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_Initstruct.USART_Parity=USART_Parity_No;
	USART_Initstruct.USART_StopBits=USART_StopBits_1;
	USART_Initstruct.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_Initstruct);
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	USART_Cmd(USART1,ENABLE);
	
	NVIC_Initstruct.NVIC_IRQChannel=USART1_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_Initstruct);
}

int fputc(int ch,FILE* P)
{
	USART_SendData(USART1,ch);
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
	return ch;
}

void USART1_IRQHandler()
{
	u8 tmp=0;
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		tmp=USART_ReceiveData(USART1);
		if(tmp==1)
			FLAG_ON_OFF=1;
		else if(tmp==2)
			FLAG_ON_OFF=2;
		else
			FLAG_ON_OFF=3;
	}
	USART_ClearITPendingBit(USART1,USART_IT_RXNE);
}

