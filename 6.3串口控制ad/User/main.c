#include "system.h"
#include "systick.h"
#include "oled.h"
#include "usart.h"
#include "adc.h"


int main()
{
	float val=0;
	u16 tmp=0;
	USART1_Init();
	systick_Init(72);
	OLED_I2C_Init();
	OLED_Clear();
	ADC1_Init();
	while(1)
	{
		if(FLAG_ON_OFF==1)
		{
			OLED_ShowString(1,2,"ADC OPEN ");
			OLED_ShowString(2,2,"ADC1:");
			
			val=Get_Val()*(3.3/4095);
			printf("%.2f\r\n",val);
			tmp=val*10;
			OLED_ShowNum(2,7,tmp/10,1);
			OLED_ShowChar(2,8,'.');
			OLED_ShowNum(2,9,tmp%10,1);
		}
		else if(FLAG_ON_OFF==2)
		{
			OLED_ShowString(1,2,"ADC CLOSE");
			delay_ms(1000);
			OLED_Clear();
			FLAG_ON_OFF=0;
		}
	}
	return 0;
}
