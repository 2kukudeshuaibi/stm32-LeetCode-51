#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "exit.h"
#include "Time.h"
#include "usart.h"
#include "iwdg.h"

int main()
{
	u8 i=0;
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	Key_Init();
	USART1_Init(115200);
	IWDG_Init(4,800);
	
	LED1=1;
	printf("¸´Î»ÏµÍ³\r\n");
	while(1)
	{
		if(key_scan()==1)
		{
		    IWDG_ReloadCounter();
			LED1=0;
			printf("Î¹¹·\r\n");
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