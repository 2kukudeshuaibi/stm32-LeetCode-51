#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "ADC.h"

int main(void)
{
	float ad1=0.0;
	float ad3=0.0;
	int a1=0;
	int a3=0;
	OLED_Init();
	myADC_Init();
	while (1)
	{
		OLED_ShowString(1,2,"ADC1:");
		OLED_ShowString(2,2,"ADC3:");
		
		ad1=(float)(3.3/4096)*GET_ADC1_VAL();
		ad3=(float)(3.3/4096)*GET_ADC3_VAL();
		
		a1=ad1*100;
		a3=ad3*100;
		
		OLED_ShowNum(1,7,ad1,1);
		OLED_ShowNum(2,7,ad3,1);
		OLED_ShowChar(1,8,'.');
		OLED_ShowChar(2,8,'.');
		OLED_ShowNum(1,9,a1%100,2);
		OLED_ShowNum(2,9,a3%100,2);
		
		Delay_ms(100);
		
	}
}
