#include <reg52.h>

//实验6.1
/*
配置计数器1的TMOD
GATE=0  C/T=1  M1=0  M0=1
TMOD=0x50
计算初值：x=(2^16-10)
x=65526
*/
sbit t1=P3^5;
unsigned char a=0;
//中断法
void main()
{
   TMOD=0x50;
   TH1=65526/256;
   TL1=65526%256;
   EA=1;
   ET1=1;
   TR1=1;
   while(1)
   {
       t1=~t1;
   }
}

void Zduan() interrupt 3
{
    a++;
   TH1=65526/256;
   TL1=65526%256;
}
//查询法
//void main()
//{
//   TMOD=0x50;
//   TH1=65526/256;
//   TL1=65526%256;
//   TR1=1;
//   while(1)
//   {
//       while(TF1==0)
//       {
//           t1=~t1;
//       }
//       TF1=0;
//       a++;
//       TH1=65526/256;
//       TL1=65526%256;
//   }
//}