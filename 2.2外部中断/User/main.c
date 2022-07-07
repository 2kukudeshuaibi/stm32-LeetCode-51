#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "beep.h"
#include "exit.h"

int main()
{
	
	systick_Init(72);
	LED_Init();
	Key_Init();
	Beep_Init();
	My_Exit_Init();
	while(1)
	{
		 ;
	}
	return 0;
}