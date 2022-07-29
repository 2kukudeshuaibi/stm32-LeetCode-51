#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "beep.h"
#include "exit.h"
#include "Time.h"
#include "usart.h"
#include "IR.h"


int main()
{
	u8 i=0;
	u8 addr=0;
	u8 command=0;
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	USART1_Init(115200);
	IR_Init();
	while(1)
	{
		if(i%20==0)
		{
			LED2=!LED2;
		}
		delay_ms(10);
		i++;
		if(jsbz==1)
		{
			printf("Êý¾Ý:%x\r\n",shuju);
			jsbz=0;
			if(shuju==0xff629d)
			{
				LED1=0;
			}
			if(shuju==0xff02fd)
			{
				LED1=1;
			}
		}
		
	}
	return 0;
}