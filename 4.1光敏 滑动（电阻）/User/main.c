#include "system.h"
#include "systick.h"
#include "LED.h"
#include "usart.h"
#include "pwm.h"
#include "adc.h"
int main()
{
	u8 i=0;
	float val=0.0;
	SysTick_Init(72);
	LED_Init();
	USART1_Init(115200);
	TIM3_CH2_PWM1_Init(4000,72-1);
	AD1_Init();
	LED1=1;
	while(1)
	{
		i++;
		if((i%100)==0)
		{
			printf("AD滑动电阻值:%d\r\n",GAT_ADC_VAL_R(20));
			printf("AD光敏电阻值:%d\r\n",GAT_ADC_VAL_LIGHT(20));
			val=(float)(3.3/4096)*GAT_ADC_VAL_R(20);
			printf("滑动电压:%.2fV\r\n",val);
			
			val=(float)(3.3/4096)*GAT_ADC_VAL_LIGHT(20);
			printf("光敏电压:%.2fV\r\n",val);
		}
		TIM_SetCompare2(TIM3,GAT_ADC_VAL_LIGHT(20));
		
	}
	return 0;
}
