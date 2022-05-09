#include <reg52.h>

sbit p10=P1^0;
sbit a=P3^2;

unsigned char count=0;

void main()
{
   IT0=1;
   EA=1;
   EX0=1;
   while(1)
   {
       a=~a;
   }
}

void INT0zduan() interrupt 0
{
    count++;
    if(count==10)
    {
        EA=0;
        p10=0;
    }
}
