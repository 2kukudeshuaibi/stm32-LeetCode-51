#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "ADC.h"
#include "myDMA.h"
#include "ds18b20.h"
#include "usart.h"
#include "LED1.h"

int main(void)
{
	float tem=0;
	int data=0;
	OLED_Init();
	DS18B20_Init();
	LED1_Init();
	//USART1_Init(115200);
	while (1)
	{
		tem=DS18B20_GetTemperture();
		//printf("%.2f\r\n",tem);
		data=(int)tem*100;
		OLED_ShowNum(1,2,data/100,2);
		OLED_ShowChar(1,4,'.');
		OLED_ShowNum(1,5,data%100,2);
		Delay_ms(100);
		LED11=!LED11;
	}
}
