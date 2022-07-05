#include "system.h"


#define BEEP  PBout(8)


void delay(unsigned int i)
{
	unsigned int x,y;
	for(x=i;x>0;x--)
	{
		for(y=110;y>0;y--);
	}
}

void BEEP_Init()
{
	
	GPIO_InitTypeDef GPIO_InitStructb;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructb.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructb.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructb.GPIO_Mode=GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOB,&GPIO_InitStructb);
	
}

int main()
{
	
	BEEP_Init();
	while(1)
	{
		BEEP=1;
		//delay(5000);
		
		//delay(5000);
	}
	
	
	return 0;
}
