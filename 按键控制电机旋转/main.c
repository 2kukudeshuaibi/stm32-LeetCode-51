#include <reg52.h>

sbit led=P2^0;

sbit k=P3^1;

sbit lsa=P2^2;
sbit lsb=P2^3;
sbit lsc=P2^4;

unsigned char tt=0;
unsigned char camp=0;
unsigned char num=0;
unsigned char speed=0;

unsigned char arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void Timer0Init(void);
void smg(unsigned char ge);

void main()
{
   Timer0Init();
   while(1)
   {
      if(k==0)
      {
          speed++;
          if(speed==4)
          {
             speed=0;
          }
          while(!k);
      }
      if(speed==0)
      {
          camp=0;
      }
      if(speed==1)
      {
          camp=5;
      }
      if(speed==2)
      {
          camp=50;
      }
      if(speed==3)
      {
          camp=100;
      }
      smg(speed);
   }
   
}

void Timer0Init(void)		//1000微秒@11.0592MHz
{		
	TMOD = 0x01;		//设置定时器模式
	TL0 = 0x9C;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	EA=1;
    ET0=1;
	TR0 = 1;		//定时器0开始计时
}

void smg(unsigned char ge)
{
    lsc=1;lsb=1;lsa=1;
    P0=arr[ge];
}

void zduan() interrupt 1
{
   	TL0 = 0x9C;		//设置定时初始值
	TH0 = 0xFF;
    tt++;
    if(tt==100)
    {
        tt=0;
    }
    if(camp>tt)
    {
       led=0;  
    }
    else
    {
       led=1;
    }
}