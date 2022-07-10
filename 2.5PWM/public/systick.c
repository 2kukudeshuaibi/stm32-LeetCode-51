#include "systick.h"

static unsigned char fac_us=0;
static unsigned int  fac_ms=0;

void systick_Init(unsigned char SYSCLK)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us=SYSCLK/8;
	fac_ms=(unsigned int)fac_us*1000;
}

void delay_us(unsigned int nus)
{
	unsigned int tmp;
	SysTick->LOAD=nus*fac_us;
	SysTick->VAL=0x00;
	SysTick->CTRL|=0x00000001;
	do
	{
		tmp=SysTick->CTRL;
		
	}while((tmp&0x01)&&!(tmp&(1<<16)));
	SysTick->CTRL&=0xfffffffe;
	SysTick->VAL=0x00;
}

void delay_ms(unsigned int nms)
{
	unsigned int tmp;
	SysTick->LOAD=nms*fac_ms;
	SysTick->VAL=0x00;
	SysTick->CTRL|=0x00000001;
	do
	{
		tmp=SysTick->CTRL;
		
	}while((tmp&0x01)&&!(tmp&(1<<16)));
	SysTick->CTRL&=0xfffffffe;
	SysTick->VAL=0x00;
}