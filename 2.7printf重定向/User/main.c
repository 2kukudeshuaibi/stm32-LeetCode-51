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
	u16 data=1234;
	float fdata=12.34;
	char str[]="hello world";
	
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	USART1_Init(115200);
	
	while(1)
	{
		
		if(i%50==0)
		{
			LED2=!LED2;
			printf("%d\r\n",data);
			printf("%x\r\n",data);
			printf("%.2f\r\n",fdata);
			printf("%s\r\n",str);
		}
		delay_ms(100);
		i++;
		
		
	}
	return 0;
}