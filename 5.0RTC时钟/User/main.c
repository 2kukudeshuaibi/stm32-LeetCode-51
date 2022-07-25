#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "beep.h"
#include "exit.h"
#include "Time.h"
#include "usart.h"
#include "RTC.h"

int main()
{
	u8 i=0;
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	USART1_Init(115200);
	RTC_Init();
	while(1)
	{
		
		if(i%50==0)
		{
			LED2=!LED2;
		}
		delay_ms(10);
		i++;
	}
	return 0;
}