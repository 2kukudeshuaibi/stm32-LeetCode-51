#include "hc05.h"

u8 HC05_Init()
{
	u8 retry=10;
	u8 t=0;
	u8 temp=1;
	GPIO_InitTypeDef GPIO_Initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_4;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	
	GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Initstruct.GPIO_Pin=GPIO_Pin_15;
	GPIO_Initstruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initstruct);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	HC05_KEY=1;
	HC05_LED=1;
	
	USART3_Init(9600);
	while(retry--)
	{
		HC05_KEY=1;
		delay_ms(10);
		u3_printf("AT\r\n");
		for(t=0;t<10;t++)
		{
			if(USART3_RX_STA&0x8000)
			{
				break;
			}
			delay_ms(5);
		}
		if(USART3_RX_STA&0x8000)
		{
			temp=USART3_RX_STA&0x7fff;
			USART3_RX_STA=0;
			if(temp==4&&USART3_RX_BUFF[0]=='O'&&USART3_RX_BUFF[1]=='K')
			{
				temp=0;
				break;
			}
		}
	}
	if(retry==0)
	{
		temp=1;
	}
	return temp;
}

u8 HC05_Get_Role()
{
	u8 retry=0x0f;
	u8 t=0;
	u8 temp=1;
	while(retry--)
	{
		HC05_KEY=1;
		delay_ms(10);
		u3_printf("AT+ROLE?\r\n");
		for(t=0;t<20;t++)
		{
			delay_ms(10);
			if(USART3_RX_STA&0x8000)
			{
				break;
			}
		}
		HC05_KEY=0;
		if(USART3_RX_STA&0x8000)
		{
			temp=USART3_RX_STA&0x7fff;
			USART3_RX_STA=0;
			if(temp==13&&USART3_RX_BUFF[0]=='+')
			{
				temp=USART3_RX_BUFF[6]-'0';
				break;
			}
		}
	}
	if(retry==0)
	{
		temp=0xff;
	}
	return temp;
}

u8 HC05_Set_Cmd(u8* str)
{
	u8 retry=0x0f;
	u8 t=0;
	u8 temp=1;
	while(retry--)
	{
		HC05_KEY=1;
		delay_ms(10);
		u3_printf("%s\r\n",str);
		for(t=0;t<20;t++)
		{
			delay_ms(5);
			if(USART3_RX_STA&0x8000)
			{
				break;
			}
		}
		if(USART3_RX_STA&0x8000)
		{
			temp=USART3_RX_STA&0x7fff;
			USART3_RX_STA=0;
			if(temp==4&&USART3_RX_BUFF[0]=='O')
			{
				temp=0;
				break;
			}
		}
	}
	if(retry==0)
	{
		temp=0xff;
	}
	return temp;
}

void HC05_CFG_CMD(u8* str)
{
	u8 tmp=0;
	u8 t;
	HC05_KEY=1;
	delay_ms(10);
	u3_printf("%s\r\n",(char*)str);
	for(t=0;t<50;t++)
	{
		if(USART3_RX_STA&0x8000)
			break;
		delay_ms(10);
	}
	HC05_KEY=0;
	if(USART3_RX_STA&0x8000)
	{
		tmp=USART3_RX_STA&0x7fff;
		USART3_RX_STA=0;
		USART3_RX_BUFF[tmp]=0;
		printf("\r\n%s",USART3_RX_BUFF);
	}
}