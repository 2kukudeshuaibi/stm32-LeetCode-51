#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char

sbit sda=P2^0;
sbit scl=P2^1;
uchar a;
//延时函数
void delay()
{ ; ; }

//起始函数
void start()
{
   sda=1;
   delay();
   scl=1;
   delay();
   sda=0;
   delay();
}

//终止函数
void stop()
{
   sda=0;
   delay();
   scl=1;
   delay();
   sda=1;
   delay();
}

//应答信号
void reponse()
{
   uchar i;
   scl=1;
   delay();
   while((sda==1)&&(i<250))//等待应答
   {
      i++;
   }
   scl=0;
   delay();
   
}

//初始化
void init()
{
   sda=1;
   delay();
   scl=1;
   delay();
}

//写
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
   sda=1;//释放数据线信号 
         //为了读取应答信号 
         //应答信号为低电平 先置高 等应答拉低
  delay();      
}

//读
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
//指定位置写数据函数
void write_add(uchar dizhi,uchar date)
{
   start();//起始
   //写入过程
   xieru(0xa0);// 101000为器件地址  最后一个0代表写
   reponse();//等待应答
   xieru(dizhi);//器件存储区的地址  代表往这个芯片的第三个地址库写入数据
   reponse();//等待应答
   xieru(date);//写数据
   reponse();//等待应答
   stop();//终止 
}
//指定位置读取函数 
uchar read_add(uchar dizhi1)
{
   uchar aa;
   start();//起始
   xieru(0xa0);//写入器件地址
   reponse();//等待应答
   xieru(dizhi1);//写入器件内部的存储区地址
   reponse();//等待应答
   start();//起始
   xieru(0xa1);//写入器件地址 和读
   reponse();//等待应答
   aa=read();//读数据
   stop();//终止
   return aa;
}

void main()
{
   init();//初始化
   write_add(3,0x7f);
   delay1(100);
   a=read_add(3);
   P2=a;
   while(1);
}