#include <reg52.h>

sbit LED1=P1^0;//����1������
sbit LED2=P1^1;//����2������
sbit LED3=P1^2;//ú��1������
sbit LED4=P1^3;//ú��2������

sbit y1=P2^0;//����1
sbit y2=P2^1;//����2
sbit m1=P2^2;//ú��1
sbit m2=P2^3;//ú��2

void main()
{
   IT0=1;
   IT1=1;
   EA=1;
   EX0=1;
   EX1=1;
   while(1);
} 

void zduan0() interrupt 0
{
    if(y1==0)
    {
        LED1=0;
    }
    else
    {
        LED2=0;
    }
}

void zduan1() interrupt 2
{
   if(m1==0)
   {
       LED3=0;
   }
   else
   {
       LED4=0;
   }
}