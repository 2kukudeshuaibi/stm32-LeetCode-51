#include <reg52.h>

sbit rw=P2^5;
sbit rs=P2^6;
sbit en=P2^7;


#define uchar unsigned char
#define uint  unsigned int
	
void delay(uint i);//延时函数
void zhiling(uchar num);//指令函数
void shuju(uchar date);//数据函数
void init();//初始化
void show1(char* str1);//1行显示
void show2(char* str2);//2行显示

void main()
{
	 int k = 0;
	 init();
	 show1("I Like YOU");
	 show2("Qi Jin Bo");
	 
	 for(k=0;k<16;k++)
	{
		 zhiling(0x18);
		 delay(400);
	}
	while(1);
}



//延时函数
void delay(uint i)
{
	 uint x,y;
	 for(x=i;x>0;x--)
	{
		for(y=110;y>0;y--);
	}
}

//指令函数
void zhiling(uchar num)
{
   rw=0;
	 rs=0;
	 en=0;
	 P0=num;
	 delay(5);
	 en=1;
	 delay(5);
	 en=0;
}

//数据函数
void shuju(uchar date)
{
	 rs=1;
	 rw=0;
	 en=0;
	 P0=date;
	 delay(5);
	 en=1;
	 delay(5);
	 en=0;
}

//初始化函数
void init()
{
	 zhiling(0x38);
	 zhiling(0x0f);
	 zhiling(0x06);
	 zhiling(0x01);
}

//显示
void show1(char* str1)
{
	 zhiling(0x80+0x10);
	 while(*str1!='\0')
	 {
		  
		  shuju(*str1);
		  delay(5);
		  str1++;
	 }
	 
}
//2行显示
void show2(char* str2)
{
	 zhiling(0x80+0x50);
	 while(*str2!='\0')
	 {
		  shuju(*str2);
		  delay(5);
		  str2++;
	 }
}