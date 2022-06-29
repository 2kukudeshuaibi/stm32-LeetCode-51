

#include "led.h"
#include "Delay.h"


int main()
{
	LED_Init();
	
	while(1)
	{
		GPIO_ResetBits(LED1_PORT,LED1_PIN);
		Delay_ms(200);
		GPIO_SetBits(LED1_PORT,LED1_PIN);
		Delay_ms(200);
		
		
		
		GPIO_ResetBits(LED2_PORT,LED2_PIN);
		Delay_ms(200);
		GPIO_SetBits(LED2_PORT,LED2_PIN);
		Delay_ms(200);
	}
	

}
