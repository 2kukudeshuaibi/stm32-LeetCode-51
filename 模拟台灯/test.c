#include <reg51.h>
#include <intrins.h>

sbit light_up=P3^1;
sbit light_down=P3^0;
sbit light=P2^0;

void delay(unsigned int k);//ÑÓÊ±º¯Êý


void main()
{
   int i = 0;
   int j = 500;
   while(1)
   {
      light=0;
      delay(i);
      light=1;
      delay(j);
      if(light_up==0)
      {
         j--;i++;
         if(j==0)
         {
            j=500;i=0;
         }
      }
      if(light_down==0)
      {
         j++;i--;
         if(i==0)
         {
            i=500;j=0;
         }
      }
   }
}

void delay(unsigned int k)
{
   unsigned int n = 0;
   for(n=0;n<k;n++);
}