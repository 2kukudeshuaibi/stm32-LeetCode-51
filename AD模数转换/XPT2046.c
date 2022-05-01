#include "XPT2046.h"
#include <reg52.h>

sbit XPT2046_CS=P3^5;
sbit XPT2046_DCLK=P3^6;
sbit XPT2046_DIN=P3^4;
sbit XPT2046_DOUT=P3^7;

uint XPT2046_ReadAD(uchar command)
{
    uchar i;
    uint ADVALue=0x0000;
    XPT2046_DCLK=0;
    XPT2046_CS=0;
  
    for(i=0;i<8;i++)
    {
      XPT2046_DIN=command&(0x80>>i);
      XPT2046_DCLK=1;
      XPT2046_DCLK=0;
    }
    for(i=0;i<16;i++)
    {
       XPT2046_DCLK=1;
       XPT2046_DCLK=0;
       if(XPT2046_DOUT){ADVALue|=(0x8000>>i);}
    }
    XPT2046_CS=1;
    if(command&0x08)
    {
        return ADVALue>>8;
    }
    else
    {
        return ADVALue>>4;
    }
}
