#include "LCD1602.h"
#include <reg52.h>
#include "XPT2046.h"
#include <stdio.h>

uint ADValue,AD;
uchar flag_on,flag=0;
uchar a,num=0;
uchar flag_time=0;
float AD_VO;
void delay(uint i)
{
   while(i--);
}

void main()
{
   LCD_Init();
   showstr(1,1,"ADJ  NTC  RG");
   TMOD=0x21;
   TH0=(65536-50000)/256;
   TL0=(65536-50000)%256;
   TH1=0xfd;
   TL1=0xfd;
   TR1=1;
   EA=1;
   ES=1;
   ET0=1;
   REN=1;
   SM0=0;
   SM1=1;
   
   while(1)
   {
       ADValue=XPT2046_ReadAD(XPT2046_XP_8);
       shownum(2,1,ADValue,3);
       delay(10);

       ADValue=XPT2046_ReadAD(XPT2046_YP_8);
       shownum(2,6,ADValue,3);
       delay(10);

       ADValue=XPT2046_ReadAD(XPT2046_VBAT_8);
       shownum(2,11,ADValue,2);
       delay(10);
       if(flag==1)
       {
           flag=0;
           ES=0;
           TI=1;
           switch(flag_on)
           {
              case 1:puts("Turn on ad\n");TR0=1;break;
              case 2:puts("Turn off ad\n");TR0=0;break;
              case 3:puts("error\n");break;
           }
           while(!TI);
           TI=0;
           ES=1;
       }
       if(flag_time==1)
       {
           flag_time=0;
           TI=1;
           ES=0;
           AD=XPT2046_ReadAD(XPT2046_XP_8);
           delay(10);
           AD_VO=(float)AD*(5.0/255.0);
           printf("µÁ—π «: %.2f\n",AD_VO);
           while(!TI);
           TI=0;
           ES=1;
       }
   }
}

void dszduan() interrupt 1
{
   TH0=(65536-50000)/256;
   TL0=(65536-50000)%256;
   num++;
   if(num==20)
   {
      num=0;
      flag_time=1;
   }
}

void ckzduan() interrupt 4
{
    RI=0;
    a=SBUF;
    flag=1;
    if(a==1)
    {
       flag_on=1;
    }
    else if(a==2)
    {
       flag_on=2;
    }
    else
    {
       flag_on=3;
    }   
}