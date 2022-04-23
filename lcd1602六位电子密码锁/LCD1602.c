#include <reg52.h>
#include "LCD1602.h"

sbit LCD_EN=P2^7; 
sbit LCD_RS=P2^6;
sbit LCD_WR=P2^5;



void delay(uchar i)
{
   uchar k;
   for(k=0;k<i;k++);
}
void LCD_zhiling(uchar date)
{
   LCD_WR=0;
   LCD_RS=0;
   P0=date;
   delay(1);
   LCD_EN=1;
   delay(1);
   LCD_EN=0;
}

void LCD_shuju(uchar date)
{
   LCD_WR=0;
   LCD_RS=1;
   P0=date;
   delay(1);
   LCD_EN=1;
   delay(1);
   LCD_EN=0;
}

void initLCD()
{
   LCD_zhiling(0x38);
   LCD_zhiling(0x0c);
   LCD_zhiling(0x06);
   LCD_zhiling(0x80);
   showstr(1,1,"PassWord:");
   shownum(2,1,000000,6);
}

void setshow(uchar h,uchar l)
{
   if(h==1)
   {
      LCD_zhiling(0x80+(l-1));
   }
   else
   {
      LCD_zhiling(0x80+(l-1)+0x40);
   }
}
void showstr(uchar h,uchar l,uchar* p)
{
   setshow(h,l);
   while(*p!='\0')
   {
      LCD_shuju(*p);
      p++;
   }
}

uint LCDPOW(uint x,uint y)
{
   uchar i;
   uint tmp=1;
   for(i=0;i<y;i++)
   {
      tmp=tmp*x;
   }
   return tmp;
}
void shownum(uchar h,uchar l,uint number,uchar len)
{
   uchar i;
   uchar tmp;
   setshow(h,l);
   for(i=len;i>0;i--)
   {
      tmp=number/LCDPOW(10,i-1)%10;
      LCD_shuju(0x30+tmp);
   }
}