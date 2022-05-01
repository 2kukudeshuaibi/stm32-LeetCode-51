#include <reg52.h>

sbit LED=P2^0;

void delay(unsigned int i)
{
    while(i--);
}

void main()
{
   unsigned int i = 0;
   unsigned int k = 0;
   while(1)
   {
       for(i=0;i<100;i++)
       {
            for(k=0;k<20;k++)
            {
                LED=0;
                delay(i);
                LED=1;
                delay(100-i);
            }
       }
       for(i=100;i>0;i--)
       {
            for(k=0;k<20;k++)
            {
                LED=0;
                delay(i);
                LED=1;
                delay(100-i);
            }
       }
   }
}