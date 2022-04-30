#include <reg52.h>
#include "lcd.h"
#include "public.h"
#include "DS18B20.h"


void main()
{	
	u8 i=0;
   	int temp_value;
	ds18b20_init();//��ʼ��DS18B20
    LCD_Init();
	while(1)
	{				
		i++;
		if(i%50==0)//���һ��ʱ���ȡ�¶�ֵ�����ʱ��Ҫ�����¶ȴ�����ת���¶�ʱ��
			temp_value=ds18b20_read_temperture()*10;//�����¶�ֵС����һλ
		if(temp_value<0)//���¶�
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