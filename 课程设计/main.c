#include "Public.h"
#include "LCD1602.h"
#include "keyscan.h"

sbit lsa=P2^2;
sbit lsb=P2^3;
sbit lsc=P2^4;

sbit start=P3^1;
sbit stop=P3^0;

sbit beep=P2^5;

uchar key;
uchar startflag=0;
uchar stopflag=0;

uchar tt=0;
int num=60;

//uchar code arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x40};


void Referee_key();

void main()
{
   LCD_Init();
   TMOD=0x01;
   TH0=(65536-50000)/256;
   TL0=(65536-50000)%256;
   EA=1;
   ET0=1;
   TR0=0;
   LCD_Show_str(1,1,"Player:");
   LCD_Show_str(2,1,"Time:00");
   while(1)
   {
       Referee_key();
       LCD_show_num(2,6,num,2);
       if(startflag==1)
       { 
           if(key==0)
           {
               key=keyscan();
           }
           else
           {
               TR0=0;
           }
           LCD_show_num(1,8,key,1);
       }
       else
       {
           LCD_show_num(1,8,key,1);
       }
       if(num<=5 && stopflag==0)
       {
           beep=1;
           delay(1000);
           beep=0;
       }
   }
}


void Referee_key()
{
    if(start==0)
    {
        delay(10);
        if(start==0)
        {
            startflag=1;
            TR0=1;
            stopflag=0;
        }
    }
    if(stop==0)
    {
        delay(10);
        if(stop==0)
        {
            stopflag=1;
            TR0=0;
            startflag=0;
            //key=0;
            
        }
    }
}
void Time0() interrupt 1
{
   TH0=(65536-50000)/256;
   TL0=(65536-50000)%256;
   tt++;
   if(tt==20)
   {
      tt=0;
      num--;
      if(num==-1)
      {
          num=0;
      }
   }
}