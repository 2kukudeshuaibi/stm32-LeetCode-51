#include "LCD1602.h"

sbit LCD_EN=P2^7;
sbit LCD_RS=P2^6;
sbit LCD_WR=P2^5;

void LCD_zhiling(uchar command)
{
    
    LCD_RS=0;
    LCD_WR=0;
    P0=command;
    LCD_EN=1;
    delayus(10);
    LCD_EN=0;
}

void LCD_shuju(uchar date)
{
    LCD_EN=0;
    LCD_RS=1;
    LCD_WR=0;
    P0=date;
    LCD_EN=1;
    delayus(10);
    LCD_EN=0;
}

void LCD_Init()
{
    LCD_zhiling(0x38);
    LCD_zhiling(0x0c);
    LCD_zhiling(0x06);
    LCD_zhiling(0x80);
}

void LCD_setshow(uchar h,uchar l)
{
    if(h==1)
    {
        LCD_zhiling(0x80+(l-1));
    }
    if(h==2)
    {
        LCD_zhiling(0x80+0x40+(l-1));
    }
}

void showchar(uchar h,uchar l,char a)
{
    LCD_setshow(h,l);
    LCD_shuju(a);
}

uint LCD_Pow(uint i,uint j)
{
    uint tmp=1;
    uchar k;
    for(k=0;k<j;k++)
    {
        tmp=tmp*i;
    }
    return tmp;
}

void shownumber(uchar h,uchar l,uint num,uchar len)
{
    uchar i;
    uint tmp;
    LCD_setshow(h,l);
    for(i=len;i>0;i--)
    {
        tmp=num/LCD_Pow(10,i-1)%10;
        LCD_shuju(0x30+tmp);
    }
}

void showHEX(uchar h,uchar l,uint num,uchar len)
{
    uchar i;
    uint tmp;
    LCD_setshow(h,l);
    for(i=len;i>0;i--)
    {
        tmp=num/LCD_Pow(16,i-1)%16;
        if(tmp<10)
        {
            LCD_shuju(0x30+tmp);
        }
        else
        {
            LCD_shuju(0x37+tmp);
        }
    }
}

void showstr(uchar h,uchar l,char* p)
{
    LCD_setshow(h,l);
    while(*p!=('\0'))
    {
        LCD_shuju(*p);
        p++;
    }
}