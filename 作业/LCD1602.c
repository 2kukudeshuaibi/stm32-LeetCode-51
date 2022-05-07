#include "LCD1602.h"
#include <reg52.h>

sbit LCD_EN=P2^7;
sbit LCD_RS=P2^6;
sbit LCD_WR=P2^5;

void LCD_zhiling(uchar command)
{
   LCD_RS=0;
   LCD_WR=0;
   LCD_EN=0;
   P0=command;
   LCD_EN=1;
   delay(10);
   LCD_EN=0;
}


void LCD_shuju(uchar date)
{
   LCD_RS=1;
   LCD_WR=0;
   LCD_EN=0;
   P0=date;
   LCD_EN=1;
   delay(10);
   LCD_EN=0;
}

void LCD_Init()
{
    LCD_zhiling(0x38);
    LCD_zhiling(0x0c);
    LCD_zhiling(0x06);
    LCD_zhiling(0x80);
} 

void setshow(uchar h,uchar l)
{
    if(h==1)
    {
        LCD_zhiling(0x80+(l-1));
    }
    else
    {
        LCD_zhiling(0x80+0x40+(l-1));
    }
}

void showstr(uchar h,uchar l,char* p)
{
    setshow(h,l);
    while(*p!='\0')
    {
        LCD_shuju(*p);
        p++;
    }
}

uint LCD_Pow(uint num,uchar len)
{
    uint tmp=1;
    uchar i;
    for(i=0;i<len;i++)
    {
        tmp=tmp*num;
    }
    return tmp;
}


void shownumber(uchar h,uchar l,uint number,uchar len)
{
    uchar i;
    uint tmp;
    setshow(h,l);
    for(i=len;i>0;i--)
    {
        tmp=number/LCD_Pow(10,i-1)%10;
        LCD_shuju(0x30+tmp);
    }
}

void showHex(uchar h,uchar l,uint number,uchar len)
{
    uchar i;
    uint tmp;
    setshow(h,l);
    for(i=len;i>0;i--)
    {
        tmp=number/LCD_Pow(16,i-1)%16;
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