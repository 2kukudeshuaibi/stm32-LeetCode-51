#include <reg52.h>

//ʵ��5
//6MHZ����������
/*
���ö�ʱ��T1��TMOD
GATE=0  C/T=0  M1=0 M0=1
TMOD=0x10
��ֵ���㣺��2^16-x��*2=100ms
x=15536
*/


sbit LED=P1^0;
//�жϷ�
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

//��ѯ��
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

