#include <reg52.h>
#include <intrins.h>
sbit key=P3^2;

unsigned char i=0;
//脉冲触发
//void main()
//{
//    IT0=1;
//    EA=1;
//    EX0=1;
//    P1=0x00;
//    while(1);
//}

//void INT0zduan() interrupt 0
//{
//    if(i==9)
//    {
//        i=0;
//    }
//    P1|=(0x80>>i);
//    i++;
//}

//电平触发
void delay(unsigned int k)
{
    unsigned int a,j;
    for(a=k;a>0;a--)
    {
         for(j=500;j>0;j--);
    }
}

void main()
{
   IT0=0;
   EA=1;
   EX0=1;
   P1=0x00;
   while(1);
}

void INT0zduan() interrupt 0
{
    for(i=0;i<8;i++)
    {
        delay(5000);
        P1|=(0x80>>i);
    }
}
