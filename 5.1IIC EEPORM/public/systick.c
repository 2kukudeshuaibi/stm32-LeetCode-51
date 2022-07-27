#include "systick.h"


static unsigned int fac_us=0;
static unsigned int fac_ms=0;

void systick_Init(u8 SYS)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us=SYS/8;
	fac_ms=fac_us*1000;
}

void delay_us(unsigned int us)
{
	u32 tmp=0;
	SysTick->LOAD=fac_us*us;
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
	u32 tmp=0;
	SysTick->LOAD=fac_ms*ms;
	SysTick->VAL=0;
	SysTick->CTRL|=0x00000001;
	do
	{
		tmp=SysTick->CTRL;
	}while((tmp&0x01)&&!(tmp&(1<<16)));
	SysTick->CTRL&=0xfffffffe;
	SysTick->VAL=0;
}