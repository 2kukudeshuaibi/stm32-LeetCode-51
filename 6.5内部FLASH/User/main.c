#include "system.h"
#include "systick.h"
#include "oled.h"
#include "usart.h"
#include "LED.h"
#include "tftlcd.h"
#include "stm32_flash.h"

u16 Read_data[1024]={0};
u16 Write_data[10]={0};

int main()
{
	u8 i=0;
	uint32_t j=0;
	LED_Init();
	USART1_Init();
	systick_Init(72);
	//OLED_I2C_Init();
	//TFTLCD_Init();
	//OLED_Clear();
	
	printf("≤‚ ‘0\r\n");
	
	for(j=0;j<10;j++)
	{
		Write_data[j]=j;
		
	}
	printf("≤‚ ‘0.0\r\n");
	//STM32_FLASH_Write(0X08000000,Write_data,10);
	
	STM32_FLASH_Read(0X08000000,Read_data,10);
	
	
	
	for(j=0;j<1024;j++)
	{
		printf("0x%x ",Read_data[j]);
		if(j%10==0)
		{
			printf("\r\n");
		}
	}
	
	while(1)
	{
		i++;
		if(i%20==0)
			LED1=!LED1;
		delay_ms(20);
		
	}
	return 0;
}
