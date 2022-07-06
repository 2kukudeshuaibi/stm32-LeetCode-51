#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"

int main()
{
	
	systick_Init(72);
	LED_Init();
	Key_Init();
	while(1)
	{
		 switch(key_scan())
		 {
			 case 1:LED1=0;break;
			 case 2:LED2=0;break;
			 case 3:LED1=1;LED2=1;break;
		 }
	}
	return 0;
}