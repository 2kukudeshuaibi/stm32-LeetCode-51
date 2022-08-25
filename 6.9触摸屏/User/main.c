#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "usart.h"
#include "tftlcd.h"
#include "spi_flash.h"
#include "touch.h"




int main()
{
	u8 i=0;
	u8 key=0;
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	USART1_Init(115200);
	LED_Init();
	SPI2_FLASH_Init();
	TFTLCD_Init();
	TP_Init();
	
	while(1)
	{
		key=key_scan();
		
		if(key==1)
		{
			TP_ADjust();
		}
		if(TP_Scan(0))
		{
			TFTLCD_Dot(arrx[0],arry[0],RED);
			//TFTLCD_Fill_dot(arrx[0]-1,arry[0]-1,arrx[0]+2,arry[0]+2,RED);
			//printf("x:%d  ",arrx[0]);
			//printf("y:%d\r\n",arry[0]);
		}
		if(i%20==0)
		{
			LED2=!LED2;
		}
		//delay_ms(10);
		i++;
	}
	return 0;
}