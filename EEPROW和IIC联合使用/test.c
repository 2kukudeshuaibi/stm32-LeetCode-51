#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char

sbit sda=P2^0;
sbit scl=P2^1;
uchar a;
//��ʱ����
void delay()
{ ; ; }

//��ʼ����
void start()
{
   sda=1;
   delay();
   scl=1;
   delay();
   sda=0;
   delay();
}

//��ֹ����
void stop()
{
   sda=0;
   delay();
   scl=1;
   delay();
   sda=1;
   delay();
}

//Ӧ���ź�
void reponse()
{
   uchar i;
   scl=1;
   delay();
   while((sda==1)&&(i<250))//�ȴ�Ӧ��
   {
      i++;
   }
   scl=0;
   delay();
   
}

//��ʼ��
void init()
{
   sda=1;
   delay();
   scl=1;
   delay();
}

//д
void xieru(uchar date)
{
   uchar i,temp;
   temp=date;
   scl=0;
   delay();
   for(i=0;i<8;i++)
   {
       temp=temp<<1;
       sda=CY;
       delay();
       scl=1;
       delay();
       scl=0;
       delay();
   }
   sda=1;//�ͷ��������ź� 
         //Ϊ�˶�ȡӦ���ź� 
         //Ӧ���ź�Ϊ�͵�ƽ ���ø� ��Ӧ������
  delay();      
}

//��
uchar read()
{
   uchar i,j,k;
   scl=0;
   delay();
   sda=1;
   delay();
   for(i=0;i<8;i++)
   {
      scl=1;
      delay();
      j=sda;
      k=(k<<1)|j;
      scl=0;
      delay();
   }
   
   return k;
}

void delay1(uchar i)
{
   uchar a,b;
   for(a=i;a>0;a--)
   {
      for(b=100;b>0;b--);
   }
}
//ָ��λ��д���ݺ���
void write_add(uchar dizhi,uchar date)
{
   start();//��ʼ
   //д�����
   xieru(0xa0);// 101000Ϊ������ַ  ���һ��0����д
   reponse();//�ȴ�Ӧ��
   xieru(dizhi);//�����洢���ĵ�ַ  ���������оƬ�ĵ�������ַ��д������
   reponse();//�ȴ�Ӧ��
   xieru(date);//д����
   reponse();//�ȴ�Ӧ��
   stop();//��ֹ 
}
//ָ��λ�ö�ȡ���� 
uchar read_add(uchar dizhi1)
{
   uchar aa;
   start();//��ʼ
   xieru(0xa0);//д��������ַ
   reponse();//�ȴ�Ӧ��
   xieru(dizhi1);//д�������ڲ��Ĵ洢����ַ
   reponse();//�ȴ�Ӧ��
   start();//��ʼ
   xieru(0xa1);//д��������ַ �Ͷ�
   reponse();//�ȴ�Ӧ��
   aa=read();//������
   stop();//��ֹ
   return aa;
}

void main()
{
   init();//��ʼ��
   write_add(3,0x7f);
   delay1(100);
   a=read_add(3);
   P2=a;
   while(1);
}