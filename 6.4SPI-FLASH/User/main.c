#include "system.h"
#include "systick.h"
#include "oled.h"
#include "usart.h"
#include "LED.h"
#include "spi_flash.h"

uint8_t Read_data[4096]={0};
uint8_t Write_data[4096]={0};

int main()
{
	u8 i=0;
	uint32_t j=0;
	LED_Init();
	USART1_Init();
	systick_Init(72);
	OLED_I2C_Init();
	SPI2_FLASH_Init();
	OLED_Clear();
	printf("id = 0x%x\r\n",SPI_Read_ID());
	
	for(j=0;j<4096;j++)
	{
		Write_data[j]=j;
	}
	
    SPI_FLASH_Write(0,Write_data,4096);
	
	
	SPI_FLASH_Read_data(0,Read_data,4096);
	for(j=0;j<4096;j++)
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
