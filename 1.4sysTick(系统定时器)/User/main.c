#include "system.h"


#define LED1  PBout(5)
#define LED2  PEout(5)

void delay(unsigned int i)
{
	unsigned int x,y;
	for(x=i;x>0;x--)
	{
		for(y=110;y>0;y--);
	}
}

void LED_Init()
{
	
	GPIO_InitTypeDef GPIO_InitStructE;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitStructE.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructE.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructE.GPIO_Mode=GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOE,&GPIO_InitStructE);
	
}



int main()
{
	
	LED_Init();
	systick_Init(72);
	while(1)
	{
		LED2=0;
		delay_ms(1000);
		LED2=1;
		delay_ms(1000);
	}
	
	
	return 0;
}
