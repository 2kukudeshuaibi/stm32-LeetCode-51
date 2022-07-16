#include "systick.h"
#include "system.h"
#include "led.h"
#include "usart.h"
#include "touch_key.h"

int main()
{
	u8 i=0;
	systick_init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	USART1_Init(115200);
	Touch_Key_Init(6);
	while(1)
	{
		if(Touch_key_scan(0))
		{
			LED1=!LED1;
		}
		if(i%20==0)
		{
			LED0=!LED0;
		}
		i++;
		delay_ms(10);
	}
	return 0;
}
