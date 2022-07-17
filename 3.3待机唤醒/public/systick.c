#include "systick.h"


static unsigned int fac_ms=0;
static unsigned int fac_us=0;


void systick_init(unsigned char SYS)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us=SYS/8;
	fac_ms=fac_us*1000;
}

void delay_us(unsigned int nus)
{
	unsigned int tmp=0;
	SysTick->LOAD=nus*fac_us;
	SysTick->VAL=0;
	SysTick->CTRL|=0x00000001;
	do
	{
		tmp=SysTick->CTRL;
	}while((tmp&0x01)&&!(tmp&(1<<16)));
	SysTick->CTRL&=0xfffffffe;
	SysTick->VAL=0;
}

void delay_ms(unsigned int nms)
{
	unsigned int tmp=0;
	SysTick->LOAD=nms*fac_ms;
	SysTick->VAL=0;
	SysTick->CTRL|=0x00000001;
	do
	{
		tmp=SysTick->CTRL;
	}while((tmp&0x01)&&!(tmp&(1<<16)));
	SysTick->CTRL&=0xfffffffe;
	SysTick->VAL=0;
}

void delay_s(unsigned int s)
{
	unsigned int i=0;
	for(i=0;i<s;i++)
	{
		delay_ms(1000);
	}
}