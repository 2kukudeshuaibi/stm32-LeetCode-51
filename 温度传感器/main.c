#include <reg52.h>
#include "lcd.h"
#include "public.h"
#include "DS18B20.h"


void main()
{	
	u8 i=0;
   	int temp_value;
	ds18b20_init();//初始化DS18B20
    LCD_Init();
	while(1)
	{				
		i++;
		if(i%50==0)//间隔一段时间读取温度值，间隔时间要大于温度传感器转换温度时间
			temp_value=ds18b20_read_temperture()*10;//保留温度值小数后一位
		if(temp_value<0)//负温度
		{
			temp_value=-temp_value;
			LCD_showchar(2,1,'-');
		}
		if(temp_value>=0)
		{
            LCD_showchar(2,1,'+');
        }
        LCD_shownum(2,2,temp_value/10,2);
        LCD_showchar(2,4,'.');
        LCD_shownum(2,5,temp_value%10,1);
        
	}		
}