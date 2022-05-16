#include "keyscan.h"

uchar keyscan()
{
   
   uchar tmp;
   uchar k=0;
   P1=0x7f;
   tmp=P1;
   tmp=tmp&0x0f;
   if(tmp!=0x0f)
   {
       delay(10);
       if(tmp!=0x0f)
       {
           switch(tmp)
           {
              case 0x07:k=1;break;
              case 0x0b:k=2;break;
              case 0x0d:k=3;break;
              case 0x0e:k=4;break;
           }
       }
   }
   while(P1!=0x7f);

   P1=0xbf;
   tmp=P1;
   tmp=tmp&0x0f;
   if(tmp!=0x0f)
   {
       delay(10);
       if(tmp!=0x0f)
       {
           switch(tmp)
           {
              case 0x07:k=5;break;
              case 0x0b:k=6;break;
              case 0x0d:k=7;break;
              case 0x0e:k=8;break;
           }
       }
   }
   while(P1!=0xbf);

   return k;
}