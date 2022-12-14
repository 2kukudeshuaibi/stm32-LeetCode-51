#include "usart.h"

void usart1_Init(u32 bud)
{
	GPIO_InitTypeDef GPIO_Initstruct;
	USART_InitTypeDef USART_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_9;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	
	USART_Initstruct.USART_BaudRate=bud;
	USART_Initstruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Initstruct.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_Initstruct.USART_Parity=USART_Parity_No;
	USART_Initstruct.USART_StopBits=USART_StopBits_1;
	USART_Initstruct.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_Initstruct);
	
	USART_Cmd(USART1,ENABLE);
}

int fputc(int ch,FILE* P)
{
	USART_SendData(USART1,ch);
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
	return ch;
}