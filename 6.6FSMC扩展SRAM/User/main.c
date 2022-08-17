#include "system.h"
#include "systick.h"
#include "oled.h"
#include "usart.h"
#include "LED.h"
#include "tftlcd.h"
#include "key.h"
#include "sram.h"

u8 tt __attribute__ ((at (Bank1_SRAM_ADDR)));


int main()
{
	u8 i=0;
	u32 j=0;
	u8* tmp;
	LED_Init();
	USART1_Init();
	systick_Init(72);
	TFTLCD_Init();
	KEY_Init();
	//FRONT_COLOR=BLACK;
	printf("这是一个SRAM实验\r\n");
	SRAM_Init();
	tmp=(u8*)Bank1_SRAM_ADDR;
	*tmp=0xaa;
	printf("tt地址:%p\r\n",&tt);
	printf("tt的值:0x%x\r\n",tt);
//	for(j=0;j<200;j++)
//	{
//		printf("0x%x\r\n",*((u8*)(Bank1_SRAM_ADDR+j)));
//		printf("地址:%p\r\n",((u8*)(Bank1_SRAM_ADDR+j)));
//	}
	
	while(1)
	{
		i++;
		if(i%20==0)
			LED1=!LED1;
		delay_ms(20);
	}
	return 0;
}
