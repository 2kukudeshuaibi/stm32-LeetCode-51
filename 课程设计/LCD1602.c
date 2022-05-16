#include "LCD1602.h"


void LCD_Write_zhiling(uchar date)
{
    LCD_RS=0;
    LCD_RW=0;
    P0=date;
    LCD_EN=1;
    delay(1);
    LCD_EN=0;
}

void LCD_Write_shuju(uchar date)
{
    LCD_RS=1;
    LCD_RW=0;
    P0=date;
    LCD_EN=1;
    delay(1);
    LCD_EN=0;
}


void LCD_Init()
{
    LCD_Write_zhiling(0x38);
    LCD_Write_zhiling(0x0c);
    LCD_Write_zhiling(0x06);
    LCD_Write_zhiling(0x80);
}

void LCD_set_show(uchar h,uchar l)
{
    if(h==1)
    {
       LCD_Write_zhiling(0x80+(l-1));
    }
    else
    {
       LCD_Write_zhiling(0x80+0x40+(l-1));
    }
}

void LCD_Show_str(uchar h,uchar l,char* p)
{
    LCD_set_show(h,l);
    while(*p!='\0')
    {
        LCD_Write_shuju(*p);
        p++;
    }
}

uint LCD_Pow(uint x,uint y)
{
    uint i;
    uint tmp=1;
    for(i=0;i<y;i++)
    {
        tmp=tmp*x;
    }
    return tmp;
}

void LCD_show_num(uchar h,uchar l,uint number,uchar len)
{
    uchar i;
    uint tmp;
    LCD_set_show(h,l);
    for(i=len;i>0;i--)
    {
        tmp=number/LCD_Pow(10,i-1)%10;
        LCD_Write_shuju(0x30+tmp);
    }
}