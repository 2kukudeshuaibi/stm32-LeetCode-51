#include <reg52.h>

//ʵ��6.2
/*
����T0��TMOD
GATE=0   C/T=1  M1=1 M0=0
TMOD=0x06
�����ֵ��x=256-50
x=206
*/

unsigned char count=0;

sbit LED=P1^0;
sbit t0=P3^4;

//�жϷ�
void main()
{
   TMOD=0x06;
   TH0=206;
   TL0=206;
   EA=1;
   ET0=1;
   TR0=1;
   while(1)
   {
       t0=~t0;
   }
}

void zduan() interrupt 1
{
    count++;
    if(count==100)
    {
       count=0;
       LED=0;
       TR0=0;
    }
}

//��ѯ��
//void main()
//{
//   TMOD=0x06;
//   TH0=206;
//   TL0=206;
//   TR0=1;
//   while(1)
//   {
//       while(TF0==0)
//       {
//          t0=~t0;
//       }
//       TF0=0;
//       count++;
//       if(count==100)
//       {
//           count=0;
//           LED=0;
//           TR0=0;
//       }
//   }
//}