#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "beep.h"
#include "exit.h"
#include "Time.h"
#include "usart.h"

int main()
{
	u8 i=0;
	u16 t=0;
	u16 len=0;
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	USART1_Init(115200);
	
	while(1)
	{
		
		if(USART1_RX_STA&0x8000)
		{
			len=USART1_RX_STA&0x3fff;
		    for(t=0;t<len;t++)
			{
				USART_SendData(USART1,USART1_RX_BUF[t]);
				while(!USART_GetFlagStatus(USART1,USART_FLAG_TC));
			}
			USART1_RX_STA=0;
			
		}
		
		
		if(i%50==0)
		{
			LED2=!LED2;
		}
		delay_ms(10);
		i++;
		
		
	}
	return 0;
}