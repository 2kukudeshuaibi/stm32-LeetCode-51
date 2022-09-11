#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "usart.h"
#include "tftlcd.h"
#include "spi_flash.h"
#include "hc05.h"
#include "string.h"

void HC05_Role_Show()
{
	if(HC05_Get_Role()==1)
	{
		TFTLCD_Show_String(10,140,(u8*)"ROLE:Master",16);
	}
	else
	{
		TFTLCD_Show_String(10,140,(u8*)"ROLE:Slave ",16);
	}
}


void HC05_Sta_Show()
{
	if(HC05_LED)
	{
		TFTLCD_Show_String(110,140,(u8*)"STA:Connected ",16);
	}
	else
	{
		TFTLCD_Show_String(110,140,(u8*)"STA:disConnect",16);
	}
}


int main()
{
	u8 i=0;
	u16 len=0;
	u8 key=0;
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	SPI2_FLASH_Init();
	USART1_Init(115200);
	Key_Init();
	Beep_Init();
	TFTLCD_Init();

	delay_ms(1000);
	while(HC05_Init())
	{
		TFTLCD_Show_String(10,90,(u8*)"HC05 Error     ",16);
		delay_ms(500);
		TFTLCD_Show_String(10,90,(u8*)"Please Check!!!",16);
		delay_ms(500);
	}
	
	TFTLCD_Show_String(10,90,(u8*)"HC05 success",16);
	
	HC05_Role_Show();
	delay_ms(100);
	USART3_RX_STA=0;
	
	while(1)
	{
		key=key_scan();
		if(key==1)
		{
			key=HC05_Get_Role();
			if(key!=0xff)
			{
				key=!key;
				if(key==0)
				{
					HC05_Set_Cmd((u8*)"AT+ROLE=0");
				}
				else
				{
					HC05_Set_Cmd((u8*)"AT+ROLE=1");
				}
				HC05_Role_Show();
				HC05_Set_Cmd((u8*)"AT+RESET");
				delay_ms(200);
			}
		}
		if(i==50)
		{
			i=0;
			LED2=!LED2;
			HC05_Sta_Show();
		}
		if(USART3_RX_STA&0x8000)
		{
			len=USART3_RX_STA&0x7fff;
			
			USART3_RX_BUFF[len]='\0';
			
			if(len==11||len==10)
			{
				if((strcmp((const char*)USART3_RX_BUFF,"+LED1 ON\r\n"))==0)
				{
					LED1=0;
					TFTLCD_Show_String(10,160,(u8*)"LED1: ON",16);
				}
				if((strcmp((const char*)USART3_RX_BUFF,"+LED1 OFF\r\n"))==0)
				{
					LED1=1;
					TFTLCD_Show_String(10,160,(u8*)"LED1:OFF",16);
				}
				if((strcmp((const char*)USART3_RX_BUFF,"+BEEP ON\r\n"))==0)
				{
					BEEP=1;
					TFTLCD_Show_String(110,160,(u8*)"BEEP: ON",16);
				}
				if((strcmp((const char*)USART3_RX_BUFF,"+BEEP OFF\r\n"))==0)
				{
					TFTLCD_Show_String(110,160,(u8*)"BEEP:OFF",16);
					BEEP=0;
				}
			}
			TFTLCD_Show_String(20,190,USART3_RX_BUFF,16);
			USART3_RX_STA=0;
		}
		i++;
	}
	return 0;
}