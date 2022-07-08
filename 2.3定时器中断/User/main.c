#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "beep.h"
#include "exit.h"
#include "Time.h"
int main()
{
	
	LED_Init();
	TIM4_Init(1000,35999);
	while(1)
	{
		 ;
	}
	return 0;
}