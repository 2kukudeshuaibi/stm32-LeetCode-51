#include "system.h"
#include "systick.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "dma.h"

#define SEND_BUF_LEN 500
u8 send_buf[SEND_BUF_LEN];


void Send_buf_init(u8* p)
{
	u16 i=0;
	for(i=0;i<SEND_BUF_LEN/2;i++)
	{
		*p='q';
		p++;
		*p='z';
		p++;
	}
}

int main()
{
	u8 key=0;
	u8 i=0;
	systick_Init(72);
	usart1_Init(115200);
	LED_Init();
	key_Init();
	DMAX_Init(DMA1_Channel4,(u32)&USART1->DR,(u32)send_buf,SEND_BUF_LEN);
	Send_buf_init(send_buf);
	while(1)
	{
		i++;
		key=key_scan(0);
		if(key==1)
		{
			USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);
			DMAX_ENABLE(DMA1_Channel4,SEND_BUF_LEN);
			while(!DMA_GetFlagStatus(DMA1_FLAG_TC4))
			{
				LED0=!LED0;
				delay_ms(300);
			}
			DMA_ClearFlag(DMA1_FLAG_TC4);
		}
		if(i%20==0)
		{
			LED1=!LED1;
		}
		delay_ms(10);
	}
	return 0;
}
