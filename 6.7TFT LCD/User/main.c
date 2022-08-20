#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "usart.h"
#include "tftlcd.h"
#include "spi_flash.h"





int main()
{
	u8 i=0;
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	SPI2_FLASH_Init();
	USART1_Init(115200);
	TFTLCD_Init();
	TFTLCD_Show_String(10,20,(u8*)"ABCDEFGHIGKLMN",16);
	TFTLCD_Show_HZ(50,70,(u8*)"³ðÖ¾Åô");
	TFTLCD_Show_NUM(0,120,123,3);
	TFTLCD_Show_HEX(0,140,254,2);
	
	
	
	SPI_FLASH_show_data(0,1520);
	while(1)
	{
		if(i%20==0)
		{
			LED2=!LED2;
		}
		delay_ms(10);
		i++;
	}
	return 0;
}