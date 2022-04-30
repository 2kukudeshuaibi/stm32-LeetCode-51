#include <reg52.h>
#include <intrins.h>
#include "Onewire.h"

sbit One_DQ=P3^7;





unsigned char onewire_Init()
{
   unsigned char i;
   unsigned char num;
   One_DQ=1;
   One_DQ=0;
   i = 247;while(--i);
   One_DQ=1;
   i= 32;while(--i);
   num=One_DQ;
   i = 247;while(--i);
   return num;
}

void onewire_sendbit(unsigned char b)
{
   unsigned char i;
   One_DQ=0;
   i = 4;while(--i);
   One_DQ=b;
   i = 24;while(--i);
   One_DQ=1;
}

unsigned char onewire_rb()
{
   unsigned char i;
   unsigned char b;
   One_DQ=0;
   i = 2;while(--i);
   One_DQ=1;
   i = 2;while(--i);
   b=One_DQ;
   i = 24;while(--i);
   return b;
}

void onewire_sendbyte(unsigned char byte)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
       onewire_sendbit(byte&(0x01<<i));
    }
}

unsigned char onewire_rbyte()
{
   unsigned char i;
   unsigned char byte=0x00;
   for(i=0;i<8;i++)
   {
      if(One_DQ==1)
      {
         byte|=(0x01<<i);
      }
   }
   return byte;
}

