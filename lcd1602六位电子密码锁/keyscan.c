#include <reg52.h>
#include "keyscan.h"



void delay(uint i)
{
   uint k;
   for(k=0;k<i;k++);
}

uchar keyscan()
{
   uchar tmp;
   uchar key=0;
   P1=0x7f;//检测第一行
   tmp=P1;
   tmp=tmp&0x0f;
   if(tmp!=0x0f)
   {
      delay(500);
      if(tmp!=0x0f)
      {
         switch(tmp)
         {
           case 0x07:key=1;break;
           case 0x0b:key=2;break;
           case 0x0d:key=3;break;
           case 0x0e:key=4;break;
         }
      }
   }
   while(P1!=0x7f);
   P1=0xbf;//检测第二行
   tmp=P1;
   tmp=tmp&0x0f;
   if(tmp!=0x0f)
   {
      delay(500);
      if(tmp!=0x0f)
      {
         switch(tmp)
         {
           case 0x07:key=5;break;
           case 0x0b:key=6;break;
           case 0x0d:key=7;break;
           case 0x0e:key=8;break;
         }
      }
   }
   while(P1!=0xbf);
   P1=0xdf;//检测三行
   tmp=P1;
   tmp=tmp&0x0f;
   if(tmp!=0x0f)
   {
      delay(500);
      if(tmp!=0x0f)
      {
         switch(tmp)
         {
           case 0x07:key=9;break;
         }
      }
   }
   while(P1!=0xdf);
   return key;
}
