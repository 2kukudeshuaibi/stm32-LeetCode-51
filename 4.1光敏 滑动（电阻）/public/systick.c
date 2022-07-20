#include "systick.h"

static unsigned int fac_us=0;
static unsigned int fac_ms=0;

void SysTick_Init(unsigned char SYS)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us=SYS/8;
	fac_ms=fac_us*1000;
}


void delay_us(unsigned int us)
{
	unsigned int tmp=0;
	SysTick->LOAD=us*fac_us;
	SysTick->VAL=0;
	SysTick->CTRL|=0x00000001;
	do
	{
		tmp=SysTick->CTRL;
	}while((tmp&0x01)&&!(tmp&(1<<16)));
	SysTick->CTRL&=0xfffffffe;
	SysTick->VAL=0;
}

void delay_ms(unsigned int ms)
{
	unsigned int tmp=0;
	SysTick->LOAD=ms*fac_ms;
	SysTick->VAL=0;
	SysTick->CTRL|=0x00000001;
	do
	{
		tmp=SysTick->CTRL;
	}while((tmp&0x01)&&!(tmp&(1<<16)));
	SysTick->CTRL&=0xfffffffe;
	SysTick->VAL=0;
}