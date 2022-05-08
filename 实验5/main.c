#include <reg52.h>

//实验5
//6MHZ晶振条件下
/*
配置定时器T1的TMOD
GATE=0  C/T=0  M1=0 M0=1
TMOD=0x10
初值计算：（2^16-x）*2=100ms
x=15536
*/


sbit LED=P1^0;
//中断法
//void main()
//{
//   TMOD=0x10;
//   TH1=(15536)/256;
//   TL1=(15536)%256;
//   EA=1;
//   ET1=1;
//   TR1=1;
//   while(1);
//}

//void Time1() interrupt 3
//{
//    LED=~LED;
//    TH1=(15536)/256;
//    TL1=(15536)%256;
//}

//查询法
void main()
{
   TMOD=0x10;
   TH1=(15536)/256;
   TL1=(15536)%256;
   TR1=1;
   while(1)
   {
       while(TF1==0);
       TF1=0;
       LED=~LED;
       TH1=(15536)/256;
       TL1=(15536)%256;
   }
}

