#include "keyscan.h"
#include "mima.h"

#define uchar unsigned char
#define uint  unsigned int

sbit lsa=P2^2;
sbit lsb=P2^3;
sbit lsc=P2^4;

uchar arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void mima(uchar k)
{
      switch(k)
      {
         case 1:lsc=1;lsb=1;lsa=1;P0=arr[k];break;
         case 2:lsc=1;lsb=1;lsa=1;P0=arr[k];break;  
         case 3:lsc=1;lsb=1;lsa=1;P0=arr[k];break;
         case 4:lsc=1;lsb=1;lsa=1;P0=arr[k];break;
         case 5:lsc=1;lsb=1;lsa=1;P0=arr[k];break;
         case 6:lsc=1;lsb=1;lsa=1;P0=arr[k];break;
         case 7:lsc=1;lsb=1;lsa=1;P0=arr[k];break;
         case 8:lsc=1;lsb=1;lsa=1;P0=arr[k];break;
         case 9:lsc=1;lsb=1;lsa=1;P0=arr[k];break;
      }
      switch(k)
      {
         case 1:lsc=1;lsb=1;lsa=0;P0=arr[k];break;
         case 2:lsc=1;lsb=1;lsa=0;P0=arr[k];break;  
         case 3:lsc=1;lsb=1;lsa=0;P0=arr[k];break;
         case 4:lsc=1;lsb=1;lsa=0;P0=arr[k];break;
         case 5:lsc=1;lsb=1;lsa=0;P0=arr[k];break;
         case 6:lsc=1;lsb=1;lsa=0;P0=arr[k];break;
         case 7:lsc=1;lsb=1;lsa=0;P0=arr[k];break;
         case 8:lsc=1;lsb=1;lsa=0;P0=arr[k];break;
         case 9:lsc=1;lsb=1;lsa=0;P0=arr[k];break;
      }
      switch(k)
      {
         case 1:lsc=1;lsb=0;lsa=1;P0=arr[k];break;
         case 2:lsc=1;lsb=0;lsa=1;P0=arr[k];break;  
         case 3:lsc=1;lsb=0;lsa=1;P0=arr[k];break;
         case 4:lsc=1;lsb=0;lsa=1;P0=arr[k];break;
         case 5:lsc=1;lsb=0;lsa=1;P0=arr[k];break;
         case 6:lsc=1;lsb=0;lsa=1;P0=arr[k];break;
         case 7:lsc=1;lsb=0;lsa=1;P0=arr[k];break;
         case 8:lsc=1;lsb=0;lsa=1;P0=arr[k];break;
         case 9:lsc=1;lsb=0;lsa=1;P0=arr[k];break;
      }
      switch(k)
      {
         case 1:lsc=1;lsb=0;lsa=0;P0=arr[k];break;
         case 2:lsc=1;lsb=0;lsa=0;P0=arr[k];break;  
         case 3:lsc=1;lsb=0;lsa=0;P0=arr[k];break;
         case 4:lsc=1;lsb=0;lsa=0;P0=arr[k];break;
         case 5:lsc=1;lsb=0;lsa=0;P0=arr[k];break;
         case 6:lsc=1;lsb=0;lsa=0;P0=arr[k];break;
         case 7:lsc=1;lsb=0;lsa=0;P0=arr[k];break;
         case 8:lsc=1;lsb=0;lsa=0;P0=arr[k];break;
         case 9:lsc=1;lsb=0;lsa=0;P0=arr[k];break;
      }
      switch(k)
      {
         case 1:lsc=0;lsb=1;lsa=1;P0=arr[k];break;
         case 2:lsc=0;lsb=1;lsa=1;P0=arr[k];break;  
         case 3:lsc=0;lsb=1;lsa=1;P0=arr[k];break;
         case 4:lsc=0;lsb=1;lsa=1;P0=arr[k];break;
         case 5:lsc=0;lsb=1;lsa=1;P0=arr[k];break;
         case 6:lsc=0;lsb=1;lsa=1;P0=arr[k];break;
         case 7:lsc=0;lsb=1;lsa=1;P0=arr[k];break;
         case 8:lsc=0;lsb=1;lsa=1;P0=arr[k];break;
         case 9:lsc=0;lsb=1;lsa=1;P0=arr[k];break;
      }
      switch(k)
      {
         case 1:lsc=0;lsb=1;lsa=0;P0=arr[k];break;
         case 2:lsc=0;lsb=1;lsa=0;P0=arr[k];break;  
         case 3:lsc=0;lsb=1;lsa=0;P0=arr[k];break;
         case 4:lsc=0;lsb=1;lsa=0;P0=arr[k];break;
         case 5:lsc=0;lsb=1;lsa=0;P0=arr[k];break;
         case 6:lsc=0;lsb=1;lsa=0;P0=arr[k];break;
         case 7:lsc=0;lsb=1;lsa=0;P0=arr[k];break;
         case 8:lsc=0;lsb=1;lsa=0;P0=arr[k];break;
         case 9:lsc=0;lsb=1;lsa=0;P0=arr[k];break;
      }
      switch(k)
      {
         case 1:lsc=0;lsb=0;lsa=1;P0=arr[k];break;
         case 2:lsc=0;lsb=0;lsa=1;P0=arr[k];break;  
         case 3:lsc=0;lsb=0;lsa=1;P0=arr[k];break;
         case 4:lsc=0;lsb=0;lsa=1;P0=arr[k];break;
         case 5:lsc=0;lsb=0;lsa=1;P0=arr[k];break;
         case 6:lsc=0;lsb=0;lsa=1;P0=arr[k];break;
         case 7:lsc=0;lsb=0;lsa=1;P0=arr[k];break;
         case 8:lsc=0;lsb=0;lsa=1;P0=arr[k];break;
         case 9:lsc=0;lsb=0;lsa=1;P0=arr[k];break;
      }
      switch(k)
      {
         case 1:lsc=0;lsb=0;lsa=0;P0=arr[k];break;
         case 2:lsc=0;lsb=0;lsa=0;P0=arr[k];break;  
         case 3:lsc=0;lsb=0;lsa=0;P0=arr[k];break;
         case 4:lsc=0;lsb=0;lsa=0;P0=arr[k];break;
         case 5:lsc=0;lsb=0;lsa=0;P0=arr[k];break;
         case 6:lsc=0;lsb=0;lsa=0;P0=arr[k];break;
         case 7:lsc=0;lsb=0;lsa=0;P0=arr[k];break;
         case 8:lsc=0;lsb=0;lsa=0;P0=arr[k];break;
         case 9:lsc=0;lsb=0;lsa=0;P0=arr[k];break;
      }
      
}