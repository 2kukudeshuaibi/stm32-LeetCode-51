#include "system.h"
#include "systick.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "iic.h"
#include "AT24C02.h"

int main()
{
	u8 key=0;
	u8 i=0;
	u8 data=0;
	systick_Init(72);
	usart1_Init(115200);
	LED_Init();
	key_Init();
	AT24C02_Init();
	while(AT24C02_Check())
	{
		printf("AT24C02检测不正常!\r\n");
		delay_ms(1000);
	}
	printf("AT24C02检测正常\r\n");
	while(1)
	{
		key=key_scan(0);
		i++;
		if(key==1)
		{
			data++;
			if(data>255)
			{
				data=0;
			}
			AT24C02_WriteOneByte(0,data);
			printf("写入数据:%d\r\n",data);
		}
		if(key==2)
		{
			printf("读取的数据:%d\r\n",AT24C02_ReadOneByte(0));
		}
		if(i%20==0)
		{
			LED1=!LED1;
		}
		delay_ms(10);
	}
	return 0;
}
