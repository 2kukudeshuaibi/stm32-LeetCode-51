#include <reg52.h>

#define uchar unsigned char
#define uint  unsigned int

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;


uchar arr[]={0x3C,0x42,0xA9,0x85,0x85,0xA9,0x42,0x3C,
             0x3C,0x42,0xA5,0x89,0x89,0xA5,0x42,0x3C,};



void delay(uint i)
{
    uint k;
    for(k=0;k<i;k++);
}

void _74HC595Write(uchar date)
{
    uchar i;
    for(i=0;i<8;i++)
    {
       SER=date&(0x80>>i);
       SCK=1;
       SCK=0;
    }
    RCK=1;
    RCK=0;
}

void LED_Show(uchar l,uchar date1)
{
    _74HC595Write(date1);
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
    uchar i,count=0,offset=0;
    RCK=0;
    SCK=0;
    while(1)
    {
        for(i=0;i<8;i++)
        {
           LED_Show(i,arr[i+offset]);
           
        }
        
        count++;
        if(count>30)
        {
            count=0;
            offset+=8;
            if(offset>9)
            {
                offset=0;
            }
        }
    }
}