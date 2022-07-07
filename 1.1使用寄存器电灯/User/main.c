#include "stm32f10x.h"


void SystemInit(void)
{
	
}



	

int main()
{
	RCC_APB2ENR|=1<<6;
	GPIOE_CRL&=~(0x0f<<(4*5));
	GPIOE_CRL|=(3<<(4*5));
	GPIOE_BSRR=(1<<(16+5));
	while(1);
}

