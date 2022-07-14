#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "exit.h"
#include "Time.h"
#include "usart.h"
#include "iwdg.h"
#include "wwdg.h"
int main()
{
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	Key_Init();
	USART1_Init(115200);
	LED1=0;
	delay_s(5);
	LED1=1;
	WWDG_Init();
	while(1)
	{
		
		
	}
	return 0;
}

