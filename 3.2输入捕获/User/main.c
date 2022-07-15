#include "system.h"
#include "systick.h"
#include "LED.h"
#include "input.h"
#include "Time.h"
#include "usart.h"


int main()
{
	u8 i=0;
	double time=0;
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	USART1_Init(115200);
	TIM5_Iniput_Init(1000,35999);
	while(1)
	{
		if(i%50==0)
		{
			LED2=!LED2;
		}
		i++;
		delay_ms(10);
		if(TIM5_CH1_CAPTURE_STA&0x80)
		{
			time=(TIM5_CH1_CAPTURE_VAL+(TIM5_CH1_CAPTURE_STA&0x3f)*500)/1000.0;
			TIM5_CH1_CAPTURE_VAL=0;
			TIM5_CH1_CAPTURE_STA=0;
			printf("高电平时间为:%.2lf秒\r\n",time);
		}
	}
	return 0;
}

