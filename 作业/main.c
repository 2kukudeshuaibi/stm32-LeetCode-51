#include <reg52.h>
#include <intrins.h>
//#include "IR.h"
#include "INT0.h"
#include "Time0.h"
#include "LCD1602.h"
#include "public.h"

//#define uchar unsigned char
//#define uint  unsigned int

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;
sbit beep=P2^5;

uchar arr[]={0x30,0x78,0x7C,0x3E,0x3E,0x7C,0x78,0x30};//显示心
uchar arr1[]={0x3C,0x42,0x95,0x83,0x83,0x95,0x42,0x3C};//显示笑脸
uchar arr2[]={0x38,0x28,0x28,0xFF,0x28,0x28,0x38,0x00};//显示中
uchar arr3[]={0xFF,0x81,0xAB,0xBF,0xAB,0x85,0x81,0xFF};//显示国
uchar code arr4[]={0x00,0x00,0x00,0x00,0x00,0xFF,0x08,0x08,0x08,0xFF,0x00,0x1C,0x2A,0x2A,0x2A,0x1A,0x00,0x00,0xFF,0x01,0x02,
                   0x00,0xFF,0x01,0x02,0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00,0x00,0x00,0x00,
                   0xFF,0x08,0x08,0x08,0xFF,0x00,0x1C,0x2A,0x2A,0x2A,0x1A,0x00,0x00,0xFF,0x01,0x02,
                   0x00,0xFF,0x01,0x02,0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00,0x00,0x00,0x00,0x00};


uchar address;
uchar command1;

uchar xinflag=0;
uchar xiaolian=0;
uchar zi=0;
uchar zi1=0;
uchar hello=0;
//
uchar start=0;
uchar date[4];
uchar pdate;

uint time;

uchar add;
uchar command;
uchar dateflag;
uchar repeatflag;
//



void IRInit();
uchar getdateflag();
uchar getrepeatflag();
uchar getadd();
uchar getcommand();


void _74HC595(uchar date)
{
    uchar i;
    SCK=0;
    RCK=0;
    for(i=0;i<8;i++)
    {
         SER=date&(0x80>>i);
         SCK=1;
         SCK=0;
    }
    RCK=1;
    RCK=0;
}

void show(uchar l,uchar date)
{
    _74HC595(date);
    switch(l)
    {
        case 0:P0=0x7f;break;
        case 1:P0=0xbf;break;
        case 2:P0=0xdf;break;
        case 3:P0=0xef;break;
        case 4:P0=0xf7;break;
        case 5:P0=0xfb;break;
        case 6:P0=0xfd;break;
        case 7:P0=0xfe;break;
    }
}

void main()
{
   uchar i;
   uchar offest=0,count=0;
   uchar k;
   LCD_Init();
   IRInit();
   while(1)
   {
      if(getdateflag() || getrepeatflag())
      {
           address=getadd();
           command1=getcommand();
           //showHex(1,1,address,3);
           //showHex(1,5,command1,3);
           if(command1==0x46)
           {
               while(xinflag)
               {
                    for(i=0;i<8;i++)
                    {
                        show(i,arr[i]);
                    }
               }
           }
           if(command1==0x16)
           {
                while(xiaolian)
                {
                    for(i=0;i<8;i++)
                    {
                         show(i,arr1[i]);
                    }
                }
           }
           if(command1==0x0c)
           {
                while(zi)
                {
                    for(i=0;i<8;i++)
                    {
                         show(i,arr2[i]);
                    }
                }
           }
           if(command1==0x08)
           {
                 while(zi1)
                 {
                     for(i=0;i<8;i++)
                     {
                         show(i,arr3[i]);
                     }
                 }
           }
           if(command1==0x42)
           {
                 while(hello)
                 {
                    for(i=0;i<8;i++)
                    {
                        show(i,arr4[i+offest]);
                    }
                    count++;
                    if(count==20)
                    {
                        count=0;
                        offest++;
                        if(offest==59)
                        {
                           offest=0;
                        }
                    }
                 }
           }
      }
      
   }
}




void IRInit()
{
    Time0Init();
    INT0init();
}

uchar getdateflag()
{
    if(dateflag)
    {
         dateflag=0;
         return 1;
    }
    return 0;
}

uchar getrepeatflag()
{
     if(repeatflag)
     {
         repeatflag=0;
         return 1;
     }
     return 0;
}

uchar getadd()
{
     return add;
}

uchar getcommand()
{
     return command;
}

void INT0zduan() interrupt 0
{
    if(start==0)
    {
        Time0set(0);
        Time0run(1);
        start=1;
    }
    else if(start==1)
    {
        time=Gettime();
        Time0set(0);
        if(time>=13500-900 && time<=13500+900)
        {
            start=2;
        }
        else if(time>=11250-900 && time<=11250+900)
        {
            repeatflag=1;
            Time0run(0);
            start=0;
        }
        else
        {
            start=1;
        }
    }
    else if(start==2)
    {
        time=Gettime();
        Time0set(0);
        if(time>=1120-500 && time<=1120+500)
        {
             date[pdate/8]&=~(0x01<<(pdate%8));
             pdate++;
        }
        else if(time>=2250-500 && time<=2250+500)
        {
             date[pdate/8]|=(0x01<<(pdate%8));
             pdate++;
        }
        else
        {
             pdate=0;
             start=1;
        }
        if(pdate>=32)
        {
             pdate=0;
             if(date[0]==~date[1] && date[2]==~date[3])
             {
                   add=date[0];
                   command=date[2];
                   dateflag=1;
                   xinflag=!xinflag;
                   xiaolian=!xiaolian;
                   zi=!zi;
                   zi1=!zi1;
                   hello=!hello;
             }
             start=0;
             Time0run(0);
        }
    }
}