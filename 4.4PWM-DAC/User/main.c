#include "system.h"
#include "systick.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "dac.h"
#include "pwm-dac.h"
#include "adc.h"

int main()
{
	u8 key=0;
	u8 i=0;
	u8 pwm=0;
	u16 adc=0;
	int pwmval=0;
	float pwm_vol=0;
	float adc_vol=0;
	systick_Init(72);
	usart1_Init(115200);
	LED_Init();
	key_Init();
	TIM1_CH1_PWM_Init(255,0);
	ADCx_Init();
	while(1)
	{
		key=key_scan(0);
		i++;
		if(key==1)
		{
			pwmval+=10;
			if(pwmval>=250)
			{
				pwmval=255;
			}
			TIM_SetCompare1(TIM1,pwmval);
		}
		if(key==2)
		{
			pwmval-=10;
			if(pwmval<10)
			{
				pwmval=0;
			}
			TIM_SetCompare1(TIM1,pwmval);
		}
		if(i%20==0)
		{
			LED1=!LED1;
		}
		delay_ms(10);
		if(i%100==0)
		{
			pwm=TIM_GetCapture1(TIM1);
			pwm_vol=(float)pwm*(3.3/256);
			printf("PWMµçÑ¹:%.3f\r\n",pwm_vol);
			
			adc=Get_ADC1_CH1_VAL();
			adc_vol=(float)adc*(3.3/4095);
			printf("ADCµçÑ¹:%.3f\r\n",adc_vol);
		}
	}
	return 0;
}
