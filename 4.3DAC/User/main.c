#include "system.h"
#include "systick.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "dac.h"
int main()
{
	u8 key=0;
	u16 DAC_VAL=0;
	u8 i=0;
	float DAC_VOL=0;
	systick_Init(72);
	usart1_Init(115200);
	LED_Init();
	key_Init();
	DAC1_Init();
	while(1)
	{
		key=key_scan(0);
		i++;
		if(key==1)
		{
			DAC_VAL+=400;
			if(DAC_VAL>=4000)
			{
				DAC_VAL=4095;
			}
			DAC_SetChannel1Data(DAC_Align_12b_R,DAC_VAL);
		}
		if(key==2)
		{
			DAC_VAL-=400;
			if(DAC_VAL<=0)
			{
				DAC_VAL=0;
			}
			DAC_SetChannel1Data(DAC_Align_12b_R,DAC_VAL);
		}
		if(i%20==0)
		{
			LED1=!LED1;
		}
		delay_ms(10);
		if(i%100==0)
		{
			DAC_VOL=(float)DAC_GetDataOutputValue(DAC_Channel_1)*(3.3/4095);
			printf("µçÑ¹:%.2f\r\n",DAC_VOL);
		}
	}
	return 0;
}
