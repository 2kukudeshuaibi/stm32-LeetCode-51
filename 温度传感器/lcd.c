#include "lcd.h"


sbit LCD_EN=P2^7;
sbit LCD_RS=P2^6;
sbit LCD_WR=P2^5;


void delay1(u16 i)
{
   while(i--);
}

void delay2(u16 k)
{
   u16 i,j;
   for(i=k;i>0;i--)
   {
      for(j=110;j>0;j--);
   }
}

void LCD_Writecommand(u8 command)
{
   
   LCD_RS=0;
   LCD_WR=0;
   P0=command;
   LCD_EN=1;
   delay1(10);
   LCD_EN=0;
   delay1(10);
}

void LCD_Writedate(u8 date)
{
   
   LCD_RS=1;
   LCD_WR=0;
   P0=date;
   LCD_EN=1;
   delay1(10);
   LCD_EN=0;
   delay1(10);
}

void LCD_Init()
{
   LCD_Writecommand(0x38);
   LCD_Writecommand(0x0c);
   LCD_Writecommand(0x06);
   LCD_Writecommand(0x80);
}

void setshow(u8 h,u8 l)
{
   if(h==1)
   {
      LCD_Writecommand(0x80+(l-1));
   }
   if(h==2)
   {
      LCD_Writecommand(0x80+0x40+(l-1));
   }
}
void xiestring(u8 h,u8 l,u8* str)
{
    setshow(h,l);
    while(*str!='\0')
    {
        LCD_Writedate(*str);
        str++;
    }
}

int pow(int i,int j)
{
   int tmp = 1;
   int k = 0;
   for(k=0;k<j;k++)
   {
       tmp=tmp*i;
   }
   return tmp;
}

void LCD_shownum(u8 h,u8 l,int num,u8 len)
{
   u8 i;
   int tmp = 0;
   setshow(h,l);
   for(i=len;i>0;i--)
   {
      tmp=num/pow(10,i-1)%10;
      LCD_Writedate(tmp+0x30);
   }
}

void LCD_showchar(u8 h,u8 l,char a)
{
    setshow(h,l);
    LCD_Writedate(a);
}

void LCD_showbinnum(u8 h,u8 l,u16 num,u8 len)
{
   u16 i,tmp;
   setshow(h,l);
   for(i=len;i>0;i--)
   {
      tmp=num/pow(2,i-1)%2;
      LCD_Writedate(tmp+0x30);
   }
}